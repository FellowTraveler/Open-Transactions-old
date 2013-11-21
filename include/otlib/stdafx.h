// OTLIB
// Open Transactions Pre-Compiled Headers File

#pragma once

#ifdef _MSC_VER
//#include <ot_msvc.h>
#else
#include <ot_config.h>
#endif

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
#include <locale>

#include <memory>

#ifdef _WIN32
#ifndef NO_OT_PCH
#include <OTStorage.h>
#include <OTSmartContract.h>
#else
#undef NO_OT_PCH
#endif
#endif
