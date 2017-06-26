// filedlg.h

#pragma once
#ifndef __FILEDLG_H__
#define __FILEDLG_H__

#include <tchar.h>

/////////////////////////////////////////////////////////////////////////////
// CFileDialog

class CFileDialog : public OPENFILENAME
{
public:
    CFileDialog(LPCTSTR pszFilter,
                LPCTSTR pszInitialFile,
                LPCTSTR pszDefExt,
                DWORD dwFlags)
    {
        ZeroMemory(this, sizeof(OPENFILENAME));
        lStructSize = sizeof(OPENFILENAME);
        hInstance = _Module.GetModuleInstance();
        lpstrFilter = pszFilter;
        
        if( pszInitialFile )
        {
            _tcscpy(m_pszFile, pszInitialFile);
        }
        else
        {
            *m_pszFile = 0;
        }
        lpstrFile = m_pszFile;
        nMaxFile = sizeof(m_pszFile)/sizeof(*m_pszFile);
        Flags = dwFlags;
        lpstrDefExt = pszDefExt;
    }

private:
    TCHAR   m_pszFile[MAX_PATH+1];
};

class CFileOpenDialog : public CFileDialog
{
public:
    CFileOpenDialog(LPCTSTR pszFilter = 0,
                    LPCTSTR pszInitialFile = 0,
                    LPCTSTR pszDefExt = 0,
                    DWORD dwFlags = OFN_PATHMUSTEXIST)
    : CFileDialog(pszFilter, pszInitialFile, pszDefExt, dwFlags)
    {}

    int DoModal(HWND hWndParent = ::GetActiveWindow())
    {
        hwndOwner = hWndParent;
        return (GetOpenFileName(this) ? IDOK : IDCANCEL);
    }
};

class CFileSaveDialog : public CFileDialog
{
public:
    CFileSaveDialog(LPCTSTR pszFilter = 0,
                    LPCTSTR pszInitialFile = 0,
                    LPCTSTR pszDefExt = 0,
                    DWORD dwFlags = OFN_OVERWRITEPROMPT)
    : CFileDialog(pszFilter, pszInitialFile, pszDefExt, dwFlags)
    {}

    int DoModal(HWND hWndParent = ::GetActiveWindow())
    {
        hwndOwner = hWndParent;
        return (GetSaveFileName(this) ? IDOK : IDCANCEL);
    }
};

#endif  // __FILEDLG_H__
