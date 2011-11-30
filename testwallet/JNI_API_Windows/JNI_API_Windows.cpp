// JNI_API_Windows.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "JNI_API_Windows.h"


// This is an example of an exported variable
JNI_API_WINDOWS_API int nJNI_API_Windows=0;

// This is an example of an exported function.
JNI_API_WINDOWS_API int fnJNI_API_Windows(void)
{
	return 42;
}

// This is the constructor of a class that has been exported.
// see JNI_API_Windows.h for the class definition
CJNI_API_Windows::CJNI_API_Windows()
{
	return;
}


void OT_Sleep(int nMS)
{
	Sleep(nMS);
}
