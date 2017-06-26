// DartBoard.cpp : Implementation of CDartBoard

#include "stdafx.h"
#include "Controls.h"
#include "DartBoard.h"

/////////////////////////////////////////////////////////////////////////////
// CDartBoard


STDMETHODIMP CDartBoard::get_Score(long *pVal)
{
	*pVal = m_nScore;
	return S_OK;
}

STDMETHODIMP CDartBoard::put_Score(long newVal)
{
  // Cache the new score
  m_nScore = newVal;

  // Update the static control showing the score
  if( m_hWnd ) SetDlgItemInt(IDC_SCORE, m_nScore);

  // Let the container know of the new score
  Fire_OnScoreChanged(m_nScore);

  // Let the container know a property has changed
  FireOnChanged(1);

	return S_OK;
}

STDMETHODIMP CDartBoard::ResetScore()
{
	put_Score(0);
	return S_OK;
}
