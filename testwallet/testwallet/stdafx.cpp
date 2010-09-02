// stdafx.cpp : source file that includes just the standard includes
// testwallet.pch will be the pre-compiled header
// stdafx.obj will contain the pre-compiled type information

#include "stdafx.h"

#include <winsock2.h>
#include <winbase.h>

// TODO: reference any additional headers you need in STDAFX.H
// and not in this file

void OT_Sleep(int nMS)
{
	Sleep(nMS);
}
