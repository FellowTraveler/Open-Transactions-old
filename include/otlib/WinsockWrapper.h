#ifndef _WINSOCK_WRAPPER_H_
#define _WINSOCK_WRAPPER_H_

#ifdef _WIN32

#if _MSC_VER > 1000
#pragma once
#endif
 
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#endif
 
#ifndef _WINSOCK_
#define _WINSOCK_
#include <winsock2.h>
#endif
 
#pragma comment(lib, "ws2_32.lib")
 
#endif
#endif