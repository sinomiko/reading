// Utility.h : Declaration of the utility classes

#ifndef __UTILITY_H_
#define __UTILITY_H_

/////////////////////////////////////////////////////////////////////////////
// CDummyStream - Provides an implementation of IStream.

class CDummyStream : public IStream
{
public:
        CDummyStream() { m_libSeek.QuadPart = 0; m_libMaxOffset.QuadPart = 0; }

        STDMETHODIMP QueryInterface (REFIID riid, void**ppv)
        {
            if (riid == IID_IStream ||
                riid == IID_ISequentialStream || riid == IID_IUnknown)
                *ppv = static_cast <IStream*> (this);
            return *ppv = NULL, E_NOINTERFACE;
        }
        STDMETHODIMP_(ULONG) AddRef() { return 2; }
        STDMETHODIMP_(ULONG) Release () { return 1; }

        STDMETHODIMP Read(void* pv, ULONG cb, ULONG* pcbRead) { return E_NOTIMPL; }
        STDMETHODIMP Write(const void* pv, ULONG cb, ULONG* pcbWritten)
        {
            m_libMaxOffset.QuadPart = max (m_libMaxOffset.QuadPart, m_libSeek.QuadPart + cb);
            *pcbWritten = cb;
            return S_OK;
        }
        STDMETHODIMP Seek(LARGE_INTEGER dlibMove, DWORD dwOrigin, ULARGE_INTEGER*plibNewPosition)
        {
            switch (dwOrigin) {
            case STREAM_SEEK_SET:
                m_libSeek.QuadPart = dlibMove.QuadPart;
                break;
            case STREAM_SEEK_CUR:
                m_libSeek.QuadPart += dlibMove.QuadPart;
                break;
            case STREAM_SEEK_END:
                m_libSeek.QuadPart = m_libMaxOffset.QuadPart - dlibMove.QuadPart;
                if (m_libSeek.QuadPart < 0) m_libSeek.QuadPart = 0;
                break;
            default:
                return E_UNEXPECTED;
            }
            *plibNewPosition = m_libSeek;
            return S_OK;
        }
        STDMETHODIMP SetSize(ULARGE_INTEGER libNewSize)
        {
            m_libMaxOffset.QuadPart = libNewSize.QuadPart;
            return S_OK;
        }
        STDMETHODIMP CopyTo(IStream* pstm, ULARGE_INTEGER cb, ULARGE_INTEGER* pcbRead, ULARGE_INTEGER* pcbWritten) { return E_NOTIMPL; }
        STDMETHODIMP Commit(DWORD grfCommitFlags) { return E_NOTIMPL; }
        STDMETHODIMP Revert() { return E_NOTIMPL; }
        STDMETHODIMP LockRegion(ULARGE_INTEGER libOffset, ULARGE_INTEGER cb, DWORD dwLockType) { return E_NOTIMPL; }
        STDMETHODIMP UnlockRegion(ULARGE_INTEGER libOffset, ULARGE_INTEGER cb, DWORD dwLockType) { return E_NOTIMPL; }
        STDMETHODIMP Stat(STATSTG* pstatstg, DWORD grfStatFlag) { return E_NOTIMPL; }
        STDMETHODIMP Clone(IStream**ppstm) { return E_NOTIMPL; }

        ULARGE_INTEGER Size () { return m_libMaxOffset; }
        void Clear() { m_libMaxOffset.QuadPart = 0; }

        ULARGE_INTEGER m_libSeek;
        ULARGE_INTEGER m_libMaxOffset;
};
        

/////////////////////////////////////////////////////////////////////////////
// IPersistMemoryImpl - Provides an implementation of IPersistMemory.

template <class T, class S = IPersistStreamInit>
class ATL_NO_VTABLE IPersistMemoryImpl : public IPersistMemory
{
public:
	// IPersist
	STDMETHODIMP GetClassID(CLSID *pClassID)
	{
		ATLTRACE2(atlTraceCOM, 0, _T("IPersistMemoryImpl::GetClassID\n"));
		T* pT = static_cast<T*>(this);
        S* psi = static_cast <S*> (pT);
        return psi->GetClassID(pClassID);
	}

	// IPersistMemory
    STDMETHODIMP IsDirty()
	{
		ATLTRACE2(atlTraceCOM, 0, _T("IPersistMemoryImpl::IsDirty\n"));
		T* pT = static_cast<T*>(this);
        S* psi = static_cast <S*> (pT);
		return psi->IsDirty();
	}
	STDMETHODIMP Load(void* pvMem, ULONG cbSize)
	{
		ATLTRACE2(atlTraceCOM, 0, _T("IPersistMemoryImpl::Load\n"));
		T* pT = static_cast<T*>(this);

        // Get memory handle
        HGLOBAL h = GlobalAlloc (GMEM_MOVEABLE, cbSize);
        if (NULL == h) return E_OUTOFMEMORY;
        LPVOID pv = GlobalLock (h);
        if (!pv) return E_OUTOFMEMORY;

        // Copy to memory block
        CopyMemory (pv, pvMem, cbSize);
        CComPtr<IStream> spStrm;
        // Create stream on memory
        HRESULT hr = CreateStreamOnHGlobal (h, TRUE, &spStrm);
        if (FAILED (hr)) {
            GlobalUnlock (h);
            GlobalFree (h);
            return hr;
        }
        // Stream now owns the memory

        // Load from stream
        S* psi = static_cast <S*> (pT);
        hr = psi->Load (spStrm);

        GlobalUnlock (h);
		return hr;
	}
	STDMETHODIMP Save(void* pvMem, BOOL fClearDirty, ULONG cbSize)
    {
		ATLTRACE2(atlTraceCOM, 0, _T("IPersistMemoryImpl::Save\n"));
		T* pT = static_cast<T*>(this);

        // Get memory handle
        HGLOBAL h = GlobalAlloc (GMEM_MOVEABLE, cbSize);
        if (NULL == h) return E_OUTOFMEMORY;

        // Create stream on memory
        CComPtr<IStream> spStrm;
        HRESULT hr = CreateStreamOnHGlobal (h, TRUE, &spStrm);
        if (FAILED (hr)) {
            GlobalFree (h);
            return hr;
        }
        // Stream now owns the memory

        // Set logical size of stream to physical size of memory
        // (Global memory block allocation rounding causes differences)
        ULARGE_INTEGER uli;
        uli.QuadPart = cbSize ;
        spStrm->SetSize (uli);

        S* psi = static_cast <S*> (pT);
        hr = psi->Save (spStrm, fClearDirty);
        if (FAILED (hr)) return hr;

        LPVOID pv = GlobalLock (h);
        if (!pv) return E_OUTOFMEMORY;

        // Copy to memory block
        CopyMemory (pvMem, pv, cbSize);
        
		return hr;
	}
	STDMETHODIMP GetSizeMax(ULONG* pCbSize)
	{
        if (NULL == pCbSize) return E_POINTER;
        *pCbSize = 0 ;

		T* pT = static_cast<T*>(this);
        S* psi = static_cast <S*> (pT);
        ULARGE_INTEGER uli ;
        uli.QuadPart = 0;
        HRESULT hr = psi->GetSizeMax (&uli);
        if (SUCCEEDED (hr)) *pCbSize = uli.LowPart;

        return hr;
	}

	STDMETHODIMP InitNew()
    {
        ATLTRACE2(atlTraceCOM, 0, _T("IPersistMemoryImpl::InitNew\n"));
        T* pT = static_cast<T*>(this);
        S* psi = static_cast <S*> (pT);
        return psi->InitNew();
    }
};


#if 0   
template <class T, class S>
STDMETHODIMP IPersistMemoryImpl<T, IPersistStream>::InitNew()
{
    ATLTRACE2(atlTraceCOM, 0, _T("IPersistMemoryImpl::InitNew\n"));
    return S_OK;
}
#endif

/////////////////////////////////////////////////////////////////////////////
// IMarshalByValueImpl - Provides an implementation of IMarshal that marshals
// by value any object that fully implements IPersistStream. This means the
// object must implement GetSizeMax. Derived from code originally presented
// by Don Box in MSJ and subsequently modified by Jonathan Bordan, Chris Sells
// and Brent Rector.

template <class T>
class ATL_NO_VTABLE IMarshalByValueImpl : public IMarshal
{
    STDMETHODIMP GetUnmarshalClass(REFIID /* riid */, void* /* pv */, DWORD /* dwDestContext */, void* /* pvDestContext */, DWORD /* mshlflags */, CLSID *pCid)
    {
        T* pT = static_cast<T*>(this);
        IPersistStreamInit* psi = static_cast <IPersistStreamInit*> (pT);
        return psi->GetClassID (pCid);
    }
    STDMETHODIMP GetMarshalSizeMax(REFIID /* riid */, void* /* pv */, DWORD /* dwDestContext */, void* /* pvDestContext */, DWORD /* mshlflags */, DWORD* pSize)
    {
        T* pT = static_cast<T*>(this);
        IPersistStreamInit* psi = static_cast <IPersistStreamInit*> (pT);

        ULARGE_INTEGER uli = { 0 };

        HRESULT hr = psi->GetSizeMax(&uli);
        if (SUCCEEDED (hr)) *pSize = uli.LowPart;
        return hr;
    }
    STDMETHODIMP MarshalInterface(IStream *pStm, REFIID /* riid */, void* /* pv */, DWORD /* dwDestContext */, void* /* pvDestCtx */, DWORD /* mshlflags */)
    {
        T* pT = static_cast<T*>(this);
        IPersistStreamInit* psi = static_cast <IPersistStreamInit*> (pT);
        return psi->Save(pStm, FALSE);
    }
    STDMETHODIMP UnmarshalInterface(IStream *pStm, REFIID riid, void **ppv)
    {
        T* pT = static_cast<T*>(this);
        IPersistStreamInit* psi = static_cast <IPersistStreamInit*> (pT);
        HRESULT hr = psi->Load(pStm);
        if (SUCCEEDED (hr)) hr = pT->QueryInterface (riid, ppv);
        return hr;
    }
    STDMETHODIMP ReleaseMarshalData(IStream* /* pStm */) { return S_OK; }
    STDMETHODIMP DisconnectObject(DWORD /* dwReserved */) { return S_OK; }
};

/////////////////////////////////////////////////////////////////////////////
// IPersistStreamInitImpl2 - Provides an implementation of IPersistStreamInit
// that actually implements GetSizeMax.

template <class T>
class ATL_NO_VTABLE IPersistStreamInitImpl2 : public IPersistStreamInitImpl<T>
{
public:
#if 0
    STDMETHOD(GetSizeMax)(ULARGE_INTEGER* pcbSize)
    {
        if (NULL == pcbSize) return E_POINTER;

        pcbSize->QuadPart = 0;

        T*      pT = static_cast<T*>(this);

        CComPtr<IUnknown>   pUnk = pT->GetUnknown();
        ATL_PROPMAP_ENTRY*  pMap = T::GetPropertyMap();
        ATLASSERT(pMap != NULL);

        CComPtr<IDispatch>  pDispatch;
        const IID*          piidOld = NULL;

        // For each persistent property entry in the property map
        for (int i = 0; pMap[i].pclsidPropPage != NULL; i++) {
            if (pMap[i].szDesc == NULL)
                continue;

            // Just use the actual size of a raw data entry
            if (pMap[i].dwSizeData != 0) {
                pcbSize->QuadPart += pMap[i].dwSizeData;
                continue;
            }

            // Fetch the new IDispatch interface when we don't already have it
            CComVariant var;
            if (pMap[i].piidDispatch != piidOld) {
                pDispatch.Release();
                if (FAILED(pUnk->QueryInterface(*pMap[i].piidDispatch, (void**)&pDispatch))) {
                    ATLTRACE2(atlTraceCOM, 0, _T("Failed to get a dispatch pointer for property #%i\n"), i);
                    return E_FAIL;
                }
                piidOld = pMap[i].piidDispatch;
            }

            // Fetch the property described in the property map
            if (FAILED(CComDispatchDriver::GetProperty(pDispatch, pMap[i].dispid, &var))) {
                ATLTRACE2(atlTraceCOM, 0, _T("Invoked failed on DISPID %x\n"), pMap[i].dispid);
                return E_FAIL;
            }

            // Interface pointers persist as a CLSID followed by the object's persistent stream
            switch (var.vt) {
            case VT_UNKNOWN:    case VT_DISPATCH:
            {
                CComQIPtr<IPersistStream> spStream(var.punkVal);
                if (!spStream) QueryInterface(IID_IPersistStreamInit, (void**)&spStream);
                if (!spStream) {
                    ATLTRACE2(atlTraceCOM, 0, _T("Object doesn't implement IPersistStream[Init]\n"));
                    return E_FAIL;
                }
                ULARGE_INTEGER cbWrite = { 0 };
                HRESULT hr = spStream->GetSizeMax(&cbWrite);
                if (FAILED(hr)) return hr;
                pcbSize->QuadPart += cbWrite.QuadPart + sizeof(CLSID);
                continue;
            }

            // Scalar types persist as their size
            case VT_UI1:    case VT_I1:
                pcbSize->QuadPart += sizeof(BYTE);
                continue;
            case VT_I2:     case VT_UI2:    case VT_BOOL:
                pcbSize->QuadPart += sizeof(short);
                continue;
            case VT_I4:     case VT_UI4:    case VT_R4:
            case VT_INT:    case VT_UINT:   case VT_ERROR:
                pcbSize->QuadPart += sizeof(long);
                continue;
            case VT_R8:     case VT_CY:     case VT_DATE:
                pcbSize->QuadPart += sizeof(double);
                continue;
            default:
                break;
            }

            // The VARTYPE was not recognized
            // Try to convert the VARIANT into a BSTR
            CComBSTR    bstrWrite;
            CComVariant varBSTR;
            if (var.vt != VT_BSTR) {
                HRESULT hr = VariantChangeType(&varBSTR, &var, VARIANT_NOVALUEPROP, VT_BSTR);
                if (FAILED(hr)) return hr;
                bstrWrite = varBSTR.bstrVal;
            }
            else
                bstrWrite = var.bstrVal;

            // And include the size of the BSTR
            pcbSize->QuadPart += sizeof (ULONG) + 
                bstrWrite.m_str ? SysStringByteLen(bstrWrite) + sizeof(OLECHAR) : 0 ;
        }
        return S_OK;
    }
#endif
    STDMETHODIMP GetSizeMax(ULARGE_INTEGER* pcbSize)
    {
        if (NULL == pcbSize) return E_POINTER;

        pcbSize->QuadPart = 0;

        CDummyStream ds;
        HRESULT hr = Save (&ds, FALSE);
        if (SUCCEEDED (hr))
            *pcbSize = ds.Size();
        return hr;
    }
};

/////////////////////////////////////////////////////////////////////////////
// CSupportDirtyBit - Provides an implementation of the m_bRequiresSave variable
// and helper functions so non-controls can uses the ATL persistence support.

class ATL_NO_VTABLE CSupportDirtyBit
{
public:
  CSupportDirtyBit() { m_bRequiresSave = FALSE; } 
  void SetDirty(BOOL bDirty) { m_bRequiresSave = bDirty ? TRUE : FALSE; }
  BOOL GetDirty() { return m_bRequiresSave ? TRUE : FALSE; }
  BOOL m_bRequiresSave;
};

/////////////////////////////////////////////////////////////////////////////
// CSize - An extent, similar to Windows SIZE structure.

class CPoint;
class CRect;

class CSize : public tagSIZE
{
public:

// Constructors
	// construct an uninitialized size
	CSize() { /* random filled */ }
	// create from two integers
	CSize(int initCX, int initCY) { cx = initCX; cy = initCY; }
	// create from another size
	CSize(SIZE initSize) { *(SIZE*)this = initSize; }
	// create from a point
	CSize(POINT initPt) { *(POINT*)this = initPt; }
	// create from a DWORD: cx = LOWORD(dw) cy = HIWORD(dw)
    CSize(DWORD dwSize) { cx = (short)LOWORD(dwSize); cy = (short)HIWORD(dwSize); }

// CSize

// Operations
    BOOL operator==(SIZE size) const          { return (cx == size.cx && cy == size.cy); }
    BOOL operator!=(SIZE size) const          { return (cx != size.cx || cy != size.cy); }
    void operator+=(SIZE size)                { cx += size.cx; cy += size.cy; }
    void operator-=(SIZE size)                { cx -= size.cx; cy -= size.cy; }

// Operators returning CSize values
    CSize operator+(SIZE size) const          { return CSize(cx + size.cx, cy + size.cy); }
    CSize operator-(SIZE size) const          { return CSize(cx - size.cx, cy - size.cy); }
    CSize operator-() const                   { return CSize(-cx, -cy); }

// Operators returning CPoint values
    CPoint operator+(POINT point) const ;
    CPoint operator-(POINT point) const ;

// Operators returning CRect values
    CRect operator+(const RECT* lpRect) const ;
    CRect operator-(const RECT* lpRect) const ;
};

/////////////////////////////////////////////////////////////////////////////
// CPoint - A 2-D point, similar to Windows POINT structure.


class CPoint : public tagPOINT
{
public:
// Constructors

	// create an uninitialized point
	CPoint() { /* random filled */ }
	// create from two integers
	CPoint(int initX, int initY) { x = initX; y = initY; }
	// create from another point
	CPoint(POINT initPt) { *(POINT*)this = initPt; }
	// create from a size
	CPoint(SIZE initSize) { *(SIZE*)this = initSize; }
	// create from a dword: x = LOWORD(dw) y = HIWORD(dw)
	CPoint(DWORD dwPoint) {	x = (short)LOWORD(dwPoint);	y = (short)HIWORD(dwPoint);	}

// Operations

// translate the point
	void Offset(int xOffset, int yOffset) { x += xOffset; y += yOffset; }
	void Offset(POINT point) { x += point.x; y += point.y; }
	void Offset(SIZE size) { x += size.cx; y += size.cy; }

    BOOL operator==(POINT point) const  { return (x == point.x && y == point.y); }
    BOOL operator!=(POINT point) const  { return (x != point.x || y != point.y); }
    void operator+=(SIZE size)          { x += size.cx; y += size.cy; }
    void operator-=(SIZE size)          { x -= size.cx; y -= size.cy; }
    void operator+=(POINT point)        { x += point.x; y += point.y; }
    void operator-=(POINT point)        { x -= point.x; y -= point.y; }

// Operators returning CPoint values
    CPoint operator+(SIZE size) const   { return CPoint(x + size.cx, y + size.cy); }
    CPoint operator-(SIZE size) const   { return CPoint(x - size.cx, y - size.cy); }
    CPoint operator-() const            { return CPoint(-x, -y); }
    CPoint operator+(POINT point) const { return CPoint(x + point.x, y + point.y); }

// Operators returning CSize values
    CSize operator-(POINT point) const  { return CSize(x - point.x, y - point.y); }

// Operators returning CRect values
    CRect operator+(const RECT* lpRect) const ;
    CRect operator-(const RECT* lpRect) const ;
};

/////////////////////////////////////////////////////////////////////////////
// CRect - A 2-D rectangle, similar to Windows RECT structure.

typedef const RECT* LPCRECT;    // pointer to read/only RECT

class CRect : public tagRECT
{
public:

// Constructors

	// uninitialized rectangle
	CRect() { /* random filled */ }
	// from left, top, right, and bottom
	CRect(int l, int t, int r, int b) { left = l; top = t; right = r; bottom = b; }
	// copy constructor
	CRect(const RECT& srcRect) { ::CopyRect(this, &srcRect); }
	// from a pointer to another rect
	CRect(LPCRECT lpSrcRect) { ::CopyRect(this, lpSrcRect); }
	// from a point and size
	CRect(POINT point, SIZE size) { right = (left = point.x) + size.cx; bottom = (top = point.y) + size.cy; }
	// from two points
	CRect(POINT topLeft, POINT bottomRight) { left = topLeft.x; top = topLeft.y; right = bottomRight.x; bottom = bottomRight.y; }

// Attributes (in addition to RECT members)

	// retrieves the width
	int Width() const { return right - left; }
	// returns the height
	int Height() const { return bottom - top; }
	// returns the size
	CSize Size() const { return CSize(right - left, bottom - top); }
	// reference to the top-left point
	CPoint& TopLeft() { return *((CPoint*)this); }
	// reference to the bottom-right point
	CPoint& BottomRight() { return *((CPoint*)this+1); }
	// const reference to the top-left point
	const CPoint& TopLeft() const { return *((CPoint*)this); }
	// const reference to the bottom-right point
	const CPoint& BottomRight() const { return *((CPoint*)this+1); }
	// the geometric center point of the rectangle
	CPoint CenterPoint() const { return CPoint((left+right)/2, (top+bottom)/2); }
	// swap the left and right
	void SwapLeftRight() { SwapLeftRight(LPRECT(this)); }
	static void SwapLeftRight(LPRECT lpRect) { LONG temp = lpRect->left; lpRect->left = lpRect->right; lpRect->right = temp; }

	// convert between CRect and LPRECT/LPCRECT (no need for &)
	operator LPRECT() { return this; }
	operator LPCRECT() const { return this; }

	// returns TRUE if rectangle has no area
	BOOL IsRectEmpty() const { return ::IsRectEmpty(this); }
	// returns TRUE if rectangle is at (0,0) and has no area
	BOOL IsRectNull() const { return (left == 0 && right == 0 && top == 0 && bottom == 0); }
	// returns TRUE if point is within rectangle
	BOOL PtInRect(POINT point) const { return ::PtInRect(this, point); }


// Operations

	// set rectangle from left, top, right, and bottom
	void SetRect(int x1, int y1, int x2, int y2) { ::SetRect(this, x1, y1, x2, y2); }
	void SetRect(POINT topLeft, POINT bottomRight) { ::SetRect(this, topLeft.x, topLeft.y, bottomRight.x, bottomRight.y); }
	// empty the rectangle
	void SetRectEmpty() { ::SetRectEmpty(this); }
	// copy from another rectangle
	void CopyRect(LPCRECT lpSrcRect) { ::CopyRect(this, lpSrcRect); }
	// TRUE if exactly the same as another rectangle
	BOOL EqualRect(LPCRECT lpRect) const { return ::EqualRect(this, lpRect); }

	// inflate rectangle's width and height without
	// moving its top or left
	void InflateRect(int x, int y) { ::InflateRect(this, x, y); }
	void InflateRect(SIZE size) { ::InflateRect(this, size.cx, size.cy); }
    void InflateRect(LPCRECT lpRect)
    {
	    left   -= lpRect->left;
	    top    -= lpRect->top;
	    right  += lpRect->right;
	    bottom += lpRect->bottom;
    }

    void InflateRect(int l, int t, int r, int b)
    {
	    left   -= l;
	    top    -= t;
	    right  += r;
	    bottom += b;
    }

	// deflate the rectangle's width and height without
	// moving its top or left
	void DeflateRect(int x, int y) { ::InflateRect(this, -x, -y); }
	void DeflateRect(SIZE size) { ::InflateRect(this, -size.cx, -size.cy); }
    void DeflateRect(LPCRECT lpRect)
    {
	    left   += lpRect->left;
	    top    += lpRect->top;
	    right  -= lpRect->right;
	    bottom -= lpRect->bottom;
    }

    void DeflateRect(int l, int t, int r, int b)
    {
	    left   += l;
	    top    += t;
	    right  -= r;
	    bottom -= b;
    }


	// translate the rectangle by moving its top and left
	void OffsetRect(int x, int y) { ::OffsetRect(this, x, y); }
	void OffsetRect(SIZE size) { ::OffsetRect(this, size.cx, size.cy); }
	void OffsetRect(POINT point) { ::OffsetRect(this, point.x, point.y); }
    void NormalizeRect()
    {
	    int nTemp;
        if (left > right) { nTemp = left; left = right;   right = nTemp; }
        if (top > bottom) { nTemp = top;   top = bottom; bottom = nTemp; }
    }

	// set this rectangle to intersection of two others
	BOOL IntersectRect(LPCRECT lpRect1, LPCRECT lpRect2) { return ::IntersectRect(this, lpRect1, lpRect2);}

	// set this rectangle to bounding union of two others
	BOOL UnionRect(LPCRECT lpRect1, LPCRECT lpRect2) { return ::UnionRect(this, lpRect1, lpRect2); }

	// set this rectangle to minimum of two others
	BOOL SubtractRect(LPCRECT lpRectSrc1, LPCRECT lpRectSrc2) { return ::SubtractRect(this, lpRectSrc1, lpRectSrc2); }

// Additional Operations
    void operator=(const RECT& srcRect) { ::CopyRect(this, &srcRect); }
    BOOL operator==(const RECT& rect) const { return ::EqualRect(this, &rect); }
    BOOL operator!=(const RECT& rect) const { return !::EqualRect(this, &rect); }
    void operator+=(POINT point)            { ::OffsetRect(this, point.x, point.y); }
    void operator+=(SIZE size)              { ::OffsetRect(this, size.cx, size.cy); }
    void operator+=(LPCRECT lpRect)         { InflateRect(lpRect); }
    void operator-=(POINT point)            { ::OffsetRect(this, -point.x, -point.y); }
    void operator-=(SIZE size)              { ::OffsetRect(this, -size.cx, -size.cy); }
    void operator-=(LPCRECT lpRect)         { DeflateRect(lpRect); }
    void operator&=(const RECT& rect)       { ::IntersectRect(this, this, &rect); }
    void operator|=(const RECT& rect)       { ::UnionRect(this, this, &rect); }

// Operators returning CRect values
    CRect MulDiv(int nMultiplier, int nDivisor) const
    {
	return CRect(
		::MulDiv(left, nMultiplier, nDivisor),
		::MulDiv(top, nMultiplier, nDivisor),
		::MulDiv(right, nMultiplier, nDivisor),
		::MulDiv(bottom, nMultiplier, nDivisor));
    }

    CRect operator+(POINT pt) const { CRect rect(*this); ::OffsetRect(&rect, pt.x, pt.y); return rect; }
    CRect operator-(POINT pt) const { CRect rect(*this); ::OffsetRect(&rect, -pt.x, -pt.y); return rect; }
    CRect operator+(SIZE size) const { CRect rect(*this); ::OffsetRect(&rect, size.cx, size.cy); return rect; }
    CRect operator-(SIZE size) const { CRect rect(*this); ::OffsetRect(&rect, -size.cx, -size.cy); return rect; }
    CRect operator+(LPCRECT lpRect) const { CRect rect(this); rect.InflateRect(lpRect); return rect; }
    CRect operator-(LPCRECT lpRect) const { CRect rect(this); rect.DeflateRect(lpRect); return rect; }
    CRect operator&(const RECT& rect2) const { CRect rect; ::IntersectRect(&rect, this, &rect2); return rect; }
    CRect operator|(const RECT& rect2) const { CRect rect; ::UnionRect(&rect, this, &rect2); return rect; }
};

// Operators returning CPoint values
inline CPoint CSize::operator+(POINT point) const       { return CPoint(cx + point.x, cy + point.y); }
inline CPoint CSize::operator-(POINT point) const       { return CPoint(cx - point.x, cy - point.y); }

// Operators returning CRect values
inline CRect CSize::operator+(const RECT* lpRect) const { return CRect(lpRect) + *this; }
inline CRect CSize::operator-(const RECT* lpRect) const { return CRect(lpRect) - *this; }

// Operators returning CRect values
inline CRect CPoint::operator+(const RECT* lpRect) const { return CRect(lpRect) + *this; }
inline CRect CPoint::operator-(const RECT* lpRect) const { return CRect(lpRect) - *this; }

#endif
