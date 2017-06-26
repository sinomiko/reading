#ifndef _PISVRCP_H_
#define _PISVRCP_H_





template <class T>
class CProxy_ICalcPiEvents : public IConnectionPointImpl<T, &DIID__ICalcPiEvents, CComDynamicUnkArray>
{
  //Warning this class may be recreated by the wizard.
public:
  VOID Fire_OnDigit(SHORT nIndex, SHORT nDigit)
  {
    T* pT = static_cast<T*>(this);
    int nConnectionIndex;
    CComVariant* pvars = new CComVariant[2];
    int nConnections = m_vec.GetSize();
    
    for (nConnectionIndex = 0; nConnectionIndex < nConnections; nConnectionIndex++)
    {
      pT->Lock();
      CComPtr<IUnknown> sp = m_vec.GetAt(nConnectionIndex);
      pT->Unlock();
      IDispatch* pDispatch = reinterpret_cast<IDispatch*>(sp.p);
      if (pDispatch != NULL)
      {
        pvars[1].vt = VT_I2;
        pvars[1].iVal= nIndex;
        pvars[0].vt = VT_I2;
        pvars[0].iVal= nDigit;
        DISPPARAMS disp = { pvars, NULL, 2, 0 };
        pDispatch->Invoke(0x1, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &disp, NULL, NULL, NULL);
      }
    }
    delete[] pvars;
    
  }
};
#endif