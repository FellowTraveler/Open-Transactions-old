#ifndef _WINSOCK_WRAPPER_H_
#define _WINSOCK_WRAPPER_H_

#ifdef _WIN32

#if _MSC_VER > 1000
#pragma once
#endif
 
#ifndef _WINDOWS_
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
//#undef WIN32_LEAN_AND_MEAN
#endif
 
#include <winsock2.h>
 
#pragma comment(lib, "ws2_32.lib")
 
#endif
#endif