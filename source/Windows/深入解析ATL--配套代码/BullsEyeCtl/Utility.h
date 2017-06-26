// Utility.h : Declaration of the utility classes

#ifndef __UTILITY_H_
#define __UTILITY_H_

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
