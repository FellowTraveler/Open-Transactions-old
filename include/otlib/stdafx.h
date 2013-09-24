// OTLIB
// Open Transactions Pre-Compiled Headers File

#pragma once


#ifndef EXPORT
#define EXPORT
#endif
#ifndef NOEXPORT
#include <ExportWrapper.h>
#endif

#ifdef _WIN32
#include <WinsockWrapper.h>
#endif

#include <list>
#include <fstream>
#include <string>
#include <map>
#include <set>
#include <stack>
#include <deque>
#include <vector>

#ifdef _WIN32
#include <memory>
#elif __GXX_EXPERIMENTAL_CXX0X__ || __cplusplus >= 201103L
#include <memory>
#else
#include <tr1/memory>
#endif

#ifdef _WIN32
#ifndef NO_OT_PCH
#include <OTStorage.h>
#include <OTSmartContract.h>
#else
#undef NO_OT_PCH
#endif
#endif
