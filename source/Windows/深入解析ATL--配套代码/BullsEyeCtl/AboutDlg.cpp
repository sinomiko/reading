// AboutDlg.cpp : Implementation of CAboutDlg
#include "stdafx.h"
#include "AboutDlg.h"
#include <windowsx.h>
/////////////////////////////////////////////////////////////////////////////
// CAboutDlg

// Function prototypes for message handlers

static BOOL AboutDlg_OnInitDialog (HWND hwnd, HWND hwndFocus, LPARAM lParam) ;
static void AboutDlg_OnCommand (HWND hwnd, int id, HWND hwndCtl, UINT codeNotify) ;

typedef enum { typeDefault        = 0,
               typeAdvancedServer = 1,
               typeWorkstation    = 2,
               typeServer         = 3 } NTTYPE ;

static NTTYPE GetNTVersion () ;

// Function prototypes for static functions

static void  DisplayExecutableVersionInfo (HWND hwnd) ;
static void  DisplayOperatingSystemVersionInfo (HWND hwnd) ;
static void  DisplayProcessorVersionInfo (HWND hwnd) ;

static DWORD FormatMessageFromString (LPCTSTR szFormat, LPTSTR  szBuffer, DWORD nSize, ...) ;

LRESULT CAboutDlg::OnInitDialog(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
    // Center the dialog window
    CenterWindow () ;

    // Update controls with application version info
    DisplayExecutableVersionInfo (m_hWnd) ;

    // Update controls with operating system version info
    DisplayOperatingSystemVersionInfo (m_hWnd) ;

    // Update controls with processor version info
    DisplayProcessorVersionInfo (m_hWnd) ;

    return TRUE ;   // Let the system set the focus
}

//
// 040904B0 means US English, Unicode code page
// 040904E4 means US English, Windows MultiLingual code page
static const TCHAR szValueNameBase [] = TEXT("\\StringFileInfo\\040904B0\\") ;
static const TCHAR szProductName []   = TEXT("ProductName") ;

// Number of characters in the base portion of the value name string
#define BASECHARS    (DIM(szValueNameBase) - 1)

//
//  void DisplayExecutableVersionInfo (HWND hwnd)
//
//  hwnd            Window handle for the dialog box window
//
//  PURPOSE:        Retrieves the application's version resource
//                  infomation and displays the info in the
//                  appropriate dialog box controls.
//
//  COMMENTS:       This implementation uses the initial control
//                  window text as a version info value key. This
//                  function displays the value retrieved for a
//                  key in the respective control.
//

#define DIM(a) (sizeof(a)/sizeof(a[0]))

static void
DisplayExecutableVersionInfo (HWND hwnd)
{
	BOOL                bResult ;               // Result of Boolean functions
    DWORD               dwVerInfoSize ;         // Size of version information
    DWORD               dwHandle ;              // Extraneous but required parameter
    HMODULE             hmod ;                  // Application's module handle
    HWND                hwndControl ;           // Control window handle
    LPVOID              pVerInfo ;              // File version info pointer
    LPVOID              pValue ;                // Value from version info
	TCHAR               szFullPath [_MAX_PATH] ;// Application executable path
	TCHAR               szValueName [256] ;     // Name of value to retrieve
    UINT                uLength ;               // Length of retrieved value

    // Get the full path to this server
    hmod = _Module.GetModuleInstance() ;
    ::GetModuleFileName (hmod, szFullPath, DIM(szFullPath)) ;

    // Determine the size buffer needed to store the version information:
    dwVerInfoSize = GetFileVersionInfoSize (szFullPath, &dwHandle) ;
    if (0 == dwVerInfoSize)
        return ;

    // Allocate a buffer for the version info block
    pVerInfo = new char [dwVerInfoSize] ;
    ATLASSERT (NULL != pVerInfo) ;
    if (NULL == pVerInfo)
        return ;

    // Read the version info block into the buffer
    GetFileVersionInfo (szFullPath, dwHandle, dwVerInfoSize, pVerInfo) ;

    // Build value name base string...
	lstrcpy (szValueName, szValueNameBase) ;
	
	// Build the \StringFileInfo\040904E4\ProductName value name
	lstrcpy (szValueName + BASECHARS, szProductName) ;

	// Retrieve the value
    bResult = ::VerQueryValue (pVerInfo, szValueName, &pValue, &uLength) ;

    // Format the output for the dialog caption
    // Get the current caption then append to it the ProductName value
    GetWindowText (hwnd, szValueName, DIM (szValueName)) ;
	lstrcat (szValueName, reinterpret_cast <LPCTSTR>(pValue)) ;

    // Change the dialog caption - normally "About <ProductName>"
	SetWindowText (hwnd, szValueName) ;

	// For each control in the dialog...
    //  fetch the version info name from the control's initial window text.
    //  retrieve the value with that name,
    //  change the control's window text to the retrieved value.
    // Technique derived from GENERIC.C.

    hwndControl = GetFirstChild (hwnd) ;
    while (NULL != hwndControl) {
        // Build value name base string...
	    lstrcpy (szValueName, szValueNameBase) ;
	
    	// Build the \StringFileInfo\040904E4\<ControlText> value name
        // The Win32 API contains the following predefined version information strings:
        //     CompanyName              LegalCopyright     
        //     FileDescription          OriginalFilename   
        //     FileVersion              ProductName        
        //     InternalName             ProductVersion     
        
        // Get the control's text...
        GetWindowText (hwndControl,
                       szValueName + BASECHARS,
                       DIM(szValueName) - BASECHARS) ;

	    // Retrieve the value
	    bResult = VerQueryValue (pVerInfo, szValueName, &pValue, &uLength) ;

        // If version information is available and the version information name exists...
        if (bResult)
            // If a value exists for the version information name...
            if (0 != uLength && NULL != pValue)
                // Change the control's text to the version information value
                SetWindowText (hwndControl, reinterpret_cast<LPCTSTR>(pValue)) ;

        hwndControl = GetNextSibling (hwndControl) ;
    }

    // Free the memory for the version information block
    delete [] pVerInfo ;
}


//
//  DWORD DisplayOperatingSystemVersionInfo (HWND hwnd)
//
//  hwnd            Window handle for the dialog box window
//
//  PURPOSE:        Displays the operating system's version
//
//  COMMENTS:
//

static void
DisplayOperatingSystemVersionInfo (HWND hwnd)
{
    BOOL                bResult ;
    HINSTANCE           hinst ;
    NTTYPE              NtOsType ;
    TCHAR               szOSVer [256] ;
    TCHAR               szFormatString [256] ;

    // Get OS version information
    OSVERSIONINFO       osver ;
    osver.dwOSVersionInfoSize = sizeof (osver) ;    // Must initialize size member!

    bResult = GetVersionEx (&osver) ;       // Retrieve version info
    ATLASSERT (FALSE != bResult) ;
    if (FALSE == bResult)
        return ;

    hinst = GetWindowInstance (hwnd) ;      // Get instance for LoadString

    switch (osver.dwPlatformId) {
        case VER_PLATFORM_WIN32_NT:         // Windows NT
            NtOsType = GetNTVersion () ;
            LoadString (hinst, IDS_PLATFORM_WIN32_NT + NtOsType,
                        szFormatString, DIM (szFormatString)) ;
            break ;

        case VER_PLATFORM_WIN32s:           // Win32s on Windows 3.1
            LoadString (hinst, IDS_PLATFORM_WIN32s,
                        szFormatString, DIM (szFormatString)) ;
            break ;

        case VER_PLATFORM_WIN32_WINDOWS:     // Windows 95/98
            if ((osver.dwMajorVersion > 4) ||
                (osver.dwMajorVersion == 4) && (osver.dwMinorVersion > 0)) {
                // Windows 98
                LoadString (hinst, IDS_PLATFORM_WIN32_WINDOWS98,
                            szFormatString, DIM (szFormatString)) ;
                // Windows 95 encodes extra info in HIWORD(dwBuildNumber)
                // Remove unwanted junk
                osver.dwBuildNumber = LOWORD (osver.dwBuildNumber) ;
            }
            else {
                // Windows 95
                LoadString (hinst, IDS_PLATFORM_WIN32_WINDOWS95,
                            szFormatString, DIM (szFormatString)) ;
                // Windows 95 encodes extra info in HIWORD(dwBuildNumber)
                // Remove unwanted junk
                osver.dwBuildNumber = LOWORD (osver.dwBuildNumber) ;
            }
            break ;

        default:                            // Unknown operating system
            LoadString (hinst, IDS_PLATFORM_UNKNOWN,
                        szFormatString, DIM (szFormatString)) ;
            break ;
    }

    wsprintf (szOSVer, szFormatString,
              osver.dwMajorVersion,
              osver.dwMinorVersion,
              osver.dwBuildNumber) ;
    SetDlgItemText (hwnd, IDC_ABOUT_OSVERSION, szOSVer) ;
}


//
//  void DisplayProcessorVersionInfo (HWND hwnd, DWORD dwPlatformId)
//
//  hwnd            Window handle for the dialog box window
//  dwPlatformId    Hardware platform ID returned by GetVersionEx
//
//  PURPOSE:        Displays the processor's version
//
//  COMMENTS:
//

static void
DisplayProcessorVersionInfo (HWND hwnd)
{
    BOOL                bRecognized ;
    HINSTANCE           hinst ;
    SYSTEM_INFO         si ;
    TCHAR               szBuffer [256] ;
    TCHAR               szFormat [256] ;

    // Get current system information
    // Zero the structure as Windows 95 and older versions of Windows NT
    // do not initialize *all* fields of the structure (specifically,
    // wProcessorLevel and wProcessorRevision. Unfortunately, the
    // documentation does not say *which* versions of Windows NT do not
    // support setting these fields. Therefore use the new fields if
    // they seem to have been set. otherwise use the "obsolete" fields.

    ZeroMemory (&si, sizeof (si)) ;
    GetSystemInfo (&si) ;
    
    hinst = GetWindowInstance (hwnd) ;      // Get instance for LoadString

    // Determine processor architecture
    bRecognized = TRUE ;
    switch (si.wProcessorArchitecture) {
        default:
            bRecognized = FALSE ;
            LoadString (hinst, IDS_PROCESSOR_ARCHITECTURE_UNKNOWN,
                        szBuffer, DIM (szBuffer)) ;
            break ;

        case PROCESSOR_ARCHITECTURE_INTEL:  // Intel
            switch (si.wProcessorLevel) {
                default:
                    bRecognized = FALSE ;
                    LoadString (hinst,
                                IDS_PROCESSOR_LEVEL_INTEL_UNKNOWN,
                                szBuffer, DIM (szBuffer)) ;
                    break ;

                case 3:                     // Intel 80386
                    LoadString (hinst,
                                IDS_PROCESSOR_ARCHITECTURE_INTEL_386_486,
                                szFormat, DIM (szFormat)) ;
                    FormatMessageFromString (
                        szFormat,
                        szBuffer, DIM (szBuffer),
                        TEXT ("80386"),
                        LOBYTE (si.wProcessorRevision)) ;
                    break ;

                case 4:                     // Intel 80486
                    LoadString (hinst,
                                IDS_PROCESSOR_ARCHITECTURE_INTEL_386_486,
                                szFormat, DIM (szFormat)) ;
                    FormatMessageFromString (
                        szFormat,
                        szBuffer, DIM (szBuffer),
                        TEXT ("80486"),
                        LOBYTE (si.wProcessorRevision)) ;
                    break ;

                case 5:                     // Intel Pentium
                    LoadString (hinst,
                                IDS_PROCESSOR_ARCHITECTURE_INTEL_PENTIUM,
                                szFormat, DIM (szFormat)) ;
                    switch (HIBYTE(si.wProcessorRevision)) {
                    default:
                    FormatMessageFromString (
                        szFormat,
                        szBuffer, DIM (szBuffer),
                        TEXT ("Pentium"),
                        HIBYTE (si.wProcessorRevision),
                        LOBYTE (si.wProcessorRevision)) ;
                    break ;
                    case 4:
                    FormatMessageFromString (
                        szFormat,
                        szBuffer, DIM (szBuffer),
                        TEXT ("Pentium with MMX"),
                        HIBYTE (si.wProcessorRevision),
                        LOBYTE (si.wProcessorRevision)) ;
                    break;
                    }

                case 6:                     // Intel Pentium Pro/II
                    LoadString (hinst,
                                IDS_PROCESSOR_ARCHITECTURE_INTEL_PENTIUM,
                                szFormat, DIM (szFormat)) ;
                    switch (HIBYTE(si.wProcessorRevision)) {
                    default:
                        FormatMessageFromString (
                            szFormat,
                            szBuffer, DIM (szBuffer),
                            TEXT ("Pentium Pro"),
                            HIBYTE (si.wProcessorRevision),
                            LOBYTE (si.wProcessorRevision)) ;
                    break ;
                    case 1:
                        FormatMessageFromString (
                            szFormat,
                            szBuffer, DIM (szBuffer),
                            TEXT ("Pentium Pro"),
                            HIBYTE (si.wProcessorRevision),
                            LOBYTE (si.wProcessorRevision)) ;
                    break ;
                    case 3:
                    case 5:
                        FormatMessageFromString (
                            szFormat,
                            szBuffer, DIM (szBuffer),
                            TEXT ("Pentium II"),
                            HIBYTE (si.wProcessorRevision),
                            LOBYTE (si.wProcessorRevision)) ;
                    break ;
                    }
            }
            break ;

        case PROCESSOR_ARCHITECTURE_MIPS:   // MIPS
            switch (si.wProcessorLevel) {   // 00xx - xx is 8-bit implementation #
                LoadString (hinst, IDS_PROCESSOR_ARCHITECTURE_MIPS,
                            szFormat, DIM (szFormat)) ;
                default:
                    bRecognized = FALSE ;
                    LoadString (hinst, IDS_PROCESSOR_LEVEL_MIPS_UNKNOWN,
                                szBuffer, DIM (szBuffer)) ;
                    break ;

                case 0x0004:                // MIPS R4000
                    FormatMessageFromString (
                        szFormat,
                        szBuffer, DIM (szBuffer),
                        TEXT ("R4000"),
                        LOBYTE (si.wProcessorRevision)) ;
                    break ;
            }
            break ;

        case PROCESSOR_ARCHITECTURE_ALPHA:  // Alpha
            LoadString (hinst, IDS_PROCESSOR_ARCHITECTURE_ALPHA,
                        szFormat, DIM (szFormat)) ;
            switch (si.wProcessorLevel) {   // xxxx - 16-bit processor version #
                default:
                    bRecognized = FALSE ;
                    LoadString (hinst, IDS_PROCESSOR_LEVEL_ALPHA_UNKNOWN,
                                szBuffer, DIM (szBuffer)) ;
                    break ;

                case 21064:                 // Alpha 21064
                    FormatMessageFromString (
                        szFormat,
                        szBuffer, DIM (szBuffer),
                        TEXT ("21064"),
                        (TCHAR)(HIBYTE (si.wProcessorRevision) + (TCHAR) 'A'),
                        LOBYTE (si.wProcessorRevision)) ;
                    break ;

                case 21066:                 // Alpha 21066
                    FormatMessageFromString (
                        szFormat,
                        szBuffer, DIM (szBuffer),
                        TEXT ("21066"),
                        (TCHAR)(HIBYTE (si.wProcessorRevision) + (TCHAR) 'A'),
                        LOBYTE (si.wProcessorRevision)) ;
                    break ;

                case 21164:                 // Alpha 21164
                    FormatMessageFromString (
                        szFormat,
                        szBuffer, DIM (szBuffer),
                        TEXT ("21164"),
                        (TCHAR)(HIBYTE (si.wProcessorRevision) + (TCHAR) 'A'),
                        LOBYTE (si.wProcessorRevision)) ;
                    break ;
            }
            break ;

        case PROCESSOR_ARCHITECTURE_PPC:    // Power PC
            LoadString (hinst, IDS_PROCESSOR_ARCHITECTURE_PPC,
                        szFormat, DIM (szFormat)) ;
            switch (si.wProcessorLevel) {   // xxxx - 16-bit processor version #
                default:
                    bRecognized = FALSE ;
                    LoadString (hinst, IDS_PROCESSOR_LEVEL_PPC_UNKNOWN,
                                szBuffer, DIM (szBuffer)) ;
                    break ;

                case 1:                     // Power PC 601
                    FormatMessageFromString (
                        szFormat,
                        szBuffer, DIM (szBuffer),
                        TEXT ("601"),
                        HIBYTE (si.wProcessorRevision),
                        LOBYTE (si.wProcessorRevision)) ;
                    break ;

                case 3:                     // Power PC 603
                    FormatMessageFromString (
                        szFormat,
                        szBuffer, DIM (szBuffer),
                        TEXT ("603"),
                        HIBYTE (si.wProcessorRevision),
                        LOBYTE (si.wProcessorRevision)) ;
                    break ;

                case 4:                     // Power PC 604
                    FormatMessageFromString (
                        szFormat,
                        szBuffer, DIM (szBuffer),
                        TEXT ("604"),
                        HIBYTE (si.wProcessorRevision),
                        LOBYTE (si.wProcessorRevision)) ;
                    break ;

                case 6:                     // Power PC 603+
                    FormatMessageFromString (
                        szFormat,
                        szBuffer, DIM (szBuffer),
                        TEXT ("603+"),
                        HIBYTE (si.wProcessorRevision),
                        LOBYTE (si.wProcessorRevision)) ;
                    break ;

                case 9:                     // Power PC 604+
                    FormatMessageFromString (
                        szFormat,
                        szBuffer, DIM (szBuffer),
                        TEXT ("604+"),
                        HIBYTE (si.wProcessorRevision),
                        LOBYTE (si.wProcessorRevision)) ;
                    break ;

                case 20:                    // Power PC 620
                    FormatMessageFromString (
                        szFormat,
                        szBuffer, DIM (szBuffer),
                        TEXT ("620"),
                        HIBYTE (si.wProcessorRevision),
                        LOBYTE (si.wProcessorRevision)) ;
                    break ;
            }
            break;

        case PROCESSOR_ARCHITECTURE_SHX:    // Hitachi SHx
            LoadString (hinst, IDS_PROCESSOR_ARCHITECTURE_SHX,
                        szFormat, DIM (szFormat)) ;
            break;
        case PROCESSOR_ARCHITECTURE_ARM:    // StrongArm
            LoadString (hinst, IDS_PROCESSOR_ARCHITECTURE_ARM,
                        szFormat, DIM (szFormat)) ;
            break;
        case PROCESSOR_ARCHITECTURE_IA64:   // IA64
            LoadString (hinst, IDS_PROCESSOR_ARCHITECTURE_IA64,
                        szFormat, DIM (szFormat)) ;
            break;
        case PROCESSOR_ARCHITECTURE_ALPHA64: // Alpha 64
            LoadString (hinst, IDS_PROCESSOR_ARCHITECTURE_ALPHA64,
                        szFormat, DIM (szFormat)) ;
            break ;
    }

    // If the processor type isn't yet recognized, check the, supposedly,
    // "obsolete" dwProcessorType field of the SYSTEM_INFO structure for
    // a reasonable value and use it.
    if (!bRecognized) {
        switch (si.dwProcessorType) {
            case PROCESSOR_INTEL_386:
                LoadString (hinst, IDS_PROCESSOR_NOREV_INTEL_386,
                            szBuffer, DIM (szBuffer)) ;
                break ;

            case PROCESSOR_INTEL_486:
                LoadString (hinst, IDS_PROCESSOR_NOREV_INTEL_486,
                            szBuffer, DIM (szBuffer)) ;
                break ;

            case PROCESSOR_INTEL_PENTIUM:
                LoadString (hinst, IDS_PROCESSOR_NOREV_INTEL_PENTIUM,
                            szBuffer, DIM (szBuffer)) ;
                break ;

            case PROCESSOR_MIPS_R4000:
                LoadString (hinst, IDS_PROCESSOR_NOREV_MIPS_R4000,
                            szBuffer, DIM (szBuffer)) ;
                break ;

            case PROCESSOR_ALPHA_21064:
                LoadString (hinst, IDS_PROCESSOR_NOREV_ALPHA_21064,
                            szBuffer, DIM (szBuffer)) ;
                break ;
        }
    }

    SetDlgItemText (hwnd, IDC_ABOUT_PROCESSORVERSION, szBuffer) ;
}

//
//  DWORD FormatMessageFromString (LPCTSTR szFormat, LPTSTR  szBuffer, DWORD nSize, ...)
//
//  szFormat        Format string containing message insertion markers
//  szBuffer        Output string buffer
//  nSize           Size of output string buffer
//  ...             Variable number of optional parameter
//                  
//
//  PURPOSE:        
//                  Convenient helper function for calling FormatMessage
//
//  COMMENTS:
//

static DWORD
FormatMessageFromString (LPCTSTR szFormat, LPTSTR  szBuffer, DWORD nSize, ...)
{
    DWORD               dwRet ;
    va_list             marker ;

    va_start (marker, nSize) ;              // Initialize variable arguments

    dwRet = FormatMessage (FORMAT_MESSAGE_FROM_STRING,
                           szFormat, 0, 0,
                           szBuffer, nSize,
                           &marker) ;

    va_end (marker) ;                       // Reset variable arguments

    return dwRet ;
}


//
//  void AboutDlg_OnCommand (HWND hwnd, int id, hwnd hwndCtl, UINT codeNotify)
//
//  hwnd            Window handle for the dialog box window
//  id              Specifies the identifier of the menu item, control, or accelerator.
//  hwndCtl         Handle of the control sending the message if the message
//                  is from a control, otherwise, this parameter is NULL. 
//  codeNotify      Specifies the notification code if the message is from a control.
//                  This parameter is 1 when the message is from an accelerator.
//                  This parameter is 0 when the message is from a menu.
//                  
//
//  PURPOSE:        
//                  Handle the keyboard and control notifications.
//                  An OK button press, or Enter/Esc keypress
//                  all dismiss the About dialog box.
//                  
//
//  COMMENTS:
//

static
void AboutDlg_OnCommand (HWND hwnd, int id, HWND hwndCtl, UINT codeNotify)
{
    switch (id) {
        case IDOK:                          // OK pushbutton/Enter keypress
        case IDCANCEL:                      // Esc keypress
            EndDialog (hwnd, TRUE) ;        // Dismiss the about dialog box
			break ;

		default:
			break ;
	}
}

//
//  NTTYPE GetNTVersion ()
//
//  PURPOSE:        
//                  Determine the specific variant of Windows NT on which
//					we're running.
//
//  COMMENTS:
//					Windows NT 4.0 does not follow the documentation
//					in the knowledgebase. Specifically, both versions set the
//                  appropriate registry key to "LANMANNT" rather than "SERVERNT".
//

static NTTYPE
GetNTVersion ()
{
    TCHAR               szValue [256] ;
    DWORD               dwType = 0, dwSize = sizeof (szValue) ;
    HKEY                hKey       = NULL ;
    LONG                lStatus ;

static const TCHAR szProductOptions []   = TEXT("SYSTEM\\CurrentControlSet\\Control\\ProductOptions") ;
static const TCHAR szProductType []      = TEXT("ProductType") ;
static const TCHAR szWinNT []            = TEXT("WINNT") ;      //  Windows NT Workstation is running
static const TCHAR szServerNT []         = TEXT("SERVERNT") ;   //  Windows NT Server (3.5 or later) is running
static const TCHAR szAdvancedServerNT [] = TEXT("LANMANNT") ;   //  Windows NT Advanced Server (3.1) is running

    lStatus = ::RegOpenKeyEx (HKEY_LOCAL_MACHINE,szProductOptions, 0, KEY_QUERY_VALUE, &hKey) ;
    if (ERROR_SUCCESS != lStatus)
        return typeDefault ;            // Windows NT

    lStatus = ::RegQueryValueEx (hKey, szProductType, NULL, &dwType, (LPBYTE) szValue, &dwSize) ; 
    ::RegCloseKey (hKey) ;
    if (ERROR_SUCCESS != lStatus)
        return typeDefault ;            // Windows NT

    if (0 == lstrcmpi (szWinNT, szValue))
        return typeWorkstation ;        // Windows NT Workstation
    else if (0 == lstrcmpi (szServerNT, szValue))
        return typeServer ;             // Windows NT Server
    else if (0 == lstrcmpi (szAdvancedServerNT, szValue))
        return typeServer ;             // Windows NT Advanced Server (3.1)

    return typeDefault ;                // Windows NT
}
