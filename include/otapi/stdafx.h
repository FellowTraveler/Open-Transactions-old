// OTAPI
// Open Transactions Pre-Compiled Headers File

#pragma once


#ifndef EXPORT
#define EXPORT
#endif
#include <ExportWrapper.h>

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
#else
#include <tr1/memory>
#endif

#ifndef NO_OT_PCH
#include <OTStorage.h>
#include <OTSmartContract.h>
#else
#undef NO_OT_PCH
#endif
