// Forum.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <atlbase.h>
#import "../Debug/ATLInternals.dll" no_namespace

HRESULT RunSimulation ()
{
    CComQIPtr<ISpeaker> pDemosthenes, pApollodorus;

    // Demosthenes waits about the Forum for his chance to defend Phormio
    HRESULT hr = pDemosthenes.CoCreateInstance (__uuidof(Demagogue));
    if (FAILED (hr)) return hr;

    // Apollodorus waits nervously for Demosthenes to begin
    hr = pApollodorus.CoCreateInstance (__uuidof(Demagogue));
    if (FAILED (hr)) return hr;

    // All demagogues start as Demosthenes so initialize Apollodorus
    CComQIPtr<INamedObject> pno (pApollodorus);
    CComBSTR name = OLESTR ("Apollodorus");
    hr = pno->put_Name (name);   // Ignoring failure

    CComBSTR speach = OLESTR("I am not a crook!");
    hr = pApollodorus->put_Speech (speach);

    // Now let's have Phormio and a council member listening to the demagogues
    CComQIPtr<IListener> pPhormio, pCouncilMember;

    // Phormio of Athens enters the Forum
    hr = pPhormio.CoCreateInstance (__uuidof(EarPolitic));
    if (FAILED (hr)) return hr;

    pno = pPhormio;
    name = OLESTR ("Phormio");
    hr = pno->put_Name (name);

    // A council member enters the Forum
    hr = pCouncilMember.CoCreateInstance (__uuidof(EarPolitic));
    if (FAILED (hr)) return hr;

    pno = pCouncilMember;
    name = OLESTR ("Council member");
    hr = pno->put_Name (name);

    // Phormio waits for Demosthenes and Apollodorus to speak
    hr = pPhormio->ListenTo (Defendant, pDemosthenes) ;
    if (FAILED (hr)) return hr ;

    hr = pPhormio->ListenTo (Plaintiff, pApollodorus) ;
    if (FAILED (hr)) return hr ;

    // The council member waits for Demosthenes and Apollodorus to speak
    hr = pCouncilMember->ListenTo (Defendant, pDemosthenes) ;
    if (FAILED (hr)) return hr ;

    hr = pCouncilMember->ListenTo (Plaintiff, pApollodorus) ;
    if (FAILED (hr)) return hr ;

    // Demothenes begins speaking...
    hr = pDemosthenes->Speak () ;

    // Apollodorus never gets the chance to speak but if he did...
    hr = pApollodorus->Speak () ;

    // Phormio stops listening
    hr = pPhormio->StopListening (Defendant) ;
    hr = pPhormio->StopListening (Plaintiff) ;

    // The council member stops listening
    hr = pCouncilMember->StopListening (Defendant) ;
    hr = pCouncilMember->StopListening (Plaintiff) ;

    return S_OK ;
}

HRESULT RunSimulation2 ()
{
    // Demosthenes waits about the Forum for his chance to defend Phormio
    ISpeakerPtr pDemosthenes (__uuidof (Demagogue));

    // Apollodorus waits nervously for Demosthenes to begin
	ISpeakerPtr pApollodorus (__uuidof (Demagogue));

    // All demagogues start as Demosthenes so initialize Apollodorus
    INamedObjectPtr pno (pApollodorus);
    pno->Name = "Apollodorus";
    pApollodorus->Speech = "I am not a crook!";

    // Now let's have Phormio and a council member listening to the demagogues

    // Phormio of Athens enters the Forum
	IListenerPtr pPhormio (__uuidof (EarPolitic)); 

    pno = pPhormio;
    pno->Name = "Phormio";

    // A council member enters the Forum
	IListenerPtr pCouncilMember (__uuidof (EarPolitic)); 
    pno = pCouncilMember;
    pno->Name = "Council member";

    // Phormio waits for Demosthenes and Apollodorus to speak
    pPhormio->ListenTo (Defendant, pDemosthenes) ;
    pPhormio->ListenTo (Plaintiff, pApollodorus) ;

    // The council member waits for Demosthenes and Apollodorus to speak
    pCouncilMember->ListenTo (Defendant, pDemosthenes) ;
    pCouncilMember->ListenTo (Plaintiff, pApollodorus) ;

    // Demothenes begins speaking...
    pDemosthenes->Speak () ;

    // Apollodorus never gets the chance to speak but if he did...
    pApollodorus->Speak () ;

    // Phormio stops listening
    pPhormio->StopListening (Defendant) ;
    pPhormio->StopListening (Plaintiff) ;

    // The council member stops listening
    pCouncilMember->StopListening (Defendant) ;
    pCouncilMember->StopListening (Plaintiff) ;

    return S_OK ;
}

int main(int argc, char* argv[])
{
    HRESULT hr = CoInitialize (NULL);
    if (FAILED (hr))
        return -1;

    RunSimulation () ;

#if 0
	try {
		RunSimulation2 ();
	}
	catch (_com_error& e) {
		MessageBox (NULL, e.ErrorMessage (), "Exception thrown", MB_OK) ;
	}
#endif

    CoUninitialize ();
	return 0;
}

