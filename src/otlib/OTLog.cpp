/*******************************************************************
 *    
 *  OTLog.cpp
 *  
 */

/************************************************************
 -----BEGIN PGP SIGNED MESSAGE-----
 Hash: SHA256
 
 *                 OPEN TRANSACTIONS
 *
 *       Financial Cryptography and Digital Cash
 *       Library, Protocol, API, Server, and GUI 
 *    
 *    	 -- Anonymous Numbered Accounts.
 *    	 -- Untraceable Digital Cash.
 *    	 -- Triple-Signed Receipts.
 *    	 -- Cheques, Vouchers, Transfers, Inboxes.
 *    	 -- Basket Currencies, Markets, Payment Plans.
 *    	 -- Signed, XML, Ricardian-style Contracts.
 *    
 *  Copyright (C) 2010-2012 by "Fellow Traveler" (A pseudonym)
 *
 *  EMAIL:
 *  FellowTraveler@rayservers.net
 *  
 *  BITCOIN:  1NtTPVVjDsUfDWybS4BwvHpG2pdS9RnYyQ
 *
 *  KEY FINGERPRINT (PGP Key in license file):
 *  9DD5 90EB 9292 4B48 0484  7910 0308 00ED F951 BB8E
 *
 *  OFFICIAL PROJECT WIKI(s):
 *  https://github.com/FellowTraveler/Moneychanger
 *  https://github.com/FellowTraveler/Open-Transactions/wiki 
 *
 *  WEBSITE:
 *  http://www.OpenTransactions.org/
 *    
 *  Components and licensing:
 *   -- Moneychanger..A Java client GUI.....LICENSE:.....GPLv3
 *   -- OTLib.........A class library.......LICENSE:...LAGPLv3 
 *   -- OT-API........A client API..........LICENSE:...LAGPLv3
 *   -- testwallet....Command-line client...LICENSE:...LAGPLv3
 *   -- OT-Server.....Server Application....LICENSE:....AGPLv3
 *  Github.com/FellowTraveler/Open-Transactions/wiki/Components
 *
 *  All of the above OT components were designed and written by
 *  Fellow Traveler, with the exception of Moneychanger, which
 *  was contracted out to Vicky C (livewire_3001@yahoo.com).
 *
 *  -----------------------------------------------------
 *
 *   LICENSE:
 *   This program is free software: you can redistribute it
 *   and/or modify it under the terms of the GNU Affero
 *   General Public License as published by the Free Software
 *   Foundation, either version 3 of the License, or (at your
 *   option) any later version.
 *    
 *   ADDITIONAL PERMISSION under the GNU Affero GPL version 3
 *   section 7: (This paragraph applies only to the LAGPLv3
 *   components listed above.) If you modify this Program, or
 *   any covered work, by linking or combining it with other
 *   code, such other code is not for that reason alone subject
 *   to any of the requirements of the GNU Affero GPL version 3.
 *   (==> This means if you are only using the OT-API, then you
 *   don't have to open-source your code--only your changes to
 *   Open Transactions itself must be open source. Similar to
 *   LGPLv3, except it applies to software-as-a-service, not
 *   just to distributing binaries.)
 *
 *   Extra WAIVER for OpenSSL, Lucre, and all other libraries
 *   used by Open Transactions: This program is released under
 *   the AGPL with the additional exemption that compiling,
 *   linking, and/or using OpenSSL is allowed. The same is true
 *   for any other open source libraries included in this
 *   project: complete waiver from the AGPL is hereby granted to
 *   compile, link, and/or use them with Open Transactions,
 *   according to their own terms, as long as the rest of the
 *   Open Transactions terms remain respected, with regard to
 *   the Open Transactions code itself.
 *    
 *   Lucre License:
 *   This code is also "dual-license", meaning that Ben Lau-
 *   rie's license must also be included and respected, since
 *   the code for Lucre is also included with Open Transactions.
 *   See Open-Transactions/OTLib/Lucre/LUCRE_LICENSE.txt
 *   The Laurie requirements are light, but if there is any
 *   problem with his license, simply remove the Lucre code.
 *   Although there are no other blind token algorithms in Open
 *   Transactions (yet. credlib is coming), the other functions
 *   will continue to operate.
 *   -----------------------------------------------------
 *   You should have received a copy of the GNU Affero General
 *   Public License along with this program.  If not, see:
 *   http://www.gnu.org/licenses/
 *
 *   If you would like to use this software outside of the free
 *   software license, please contact FellowTraveler.
 *   (Unfortunately many will run anonymously and untraceably,
 *   so who could really stop them?)
 *   
 *   DISCLAIMER:
 *   This program is distributed in the hope that it will be
 *   useful, but WITHOUT ANY WARRANTY; without even the implied
 *   warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 *   PURPOSE.  See the GNU Affero General Public License for
 *   more details.
 -----BEGIN PGP SIGNATURE-----
 Version: GnuPG v1.4.11 (Darwin)
 
 iQIcBAEBCAAGBQJOjvvUAAoJEAMIAO35UbuOBlMP/1LX0xJ9CrTOe1G/mgc+VygT
 JPVZDAbQDL/lJXOZMbaPJ/GaLXyEnTViHp97ERrlVuBQz+9uonIKCmPqAGYGVBG1
 MGV2QcscXU2aOUT1VPf2OYEOIul0h8FX2lixfqouH9/OkVsGRLr79Zu8z3zdsO4R
 ktQtjZEU6lnL2t6cmp/cuXlQnbz1xvxd56xNDR11YP07Z4x+CuDB4EAK+P9TfCwn
 tqq5yJmxJM9HtMoi3cUU7kXodKm1n1YZt7O46DOxHqbXqErHChN1ekSK0fXad614
 Gmh+5JfvHjx5XoFWMxb46aAAcUiG8+QpFBcKtSYP2X96k1ylgxMCzrK60ec/MxKV
 BzvP00OJ6PzzrTlcUaCgJ8ZX+0scOMvW0XKioEorozKSWNFvT4Drc4Thhy8u9ET3
 ru1enNFrjdxKjw2+ZTQcKSZjSRx2kMQ2od/dkqUlhe/M1cHGhseH6ls7pItrkykE
 ufZ9GlZoxYE+FRatIBPneT9WwsvFFvH+i6cQ/MM9pbTr19g6VPzVZ4U9E65BbTDB
 czITynH+uMtJLbprtCdQlsI+vqTgYNoY8AUsmnr1qUkp020qGlvwfCJVrooisTmm
 yIh+Yp/KBzySU3inzclaAfv102/t5xi1l+GTyWHiwZxlyt5PBVglKWx/Ust9CIvN
 6h9BYZFTZrh/OwBXCdAv
 =MUfS
 -----END PGP SIGNATURE-----
 **************************************************************/

// The long-awaited logging class.


#include <cstdarg>
#include <cstdio>
#include <cstring> // The C one 
#include <cstdlib>
#include <cctype>
#include <cassert>
#include <cerrno>

#include <iostream>
#include <exception>
#include <stdexcept>

#include <string> // The C++ one 

#ifdef _WIN32
#include <WinsockWrapper.h>
#endif


// ----------------------------------------
// Use Win or Posix
//
#ifdef _WIN32

#ifdef _DEBUG
#pragma comment( lib, "libeay32MDd.lib" )
#pragma comment( lib, "ssleay32MDd.lib" )
#else
#pragma comment( lib, "libeay32MD.lib" )
#pragma comment( lib, "ssleay32MD.lib" )
#endif


#endif
// ----------------------------------------




extern "C" 
{
	
#ifdef _WIN32
    
#include <direct.h>
#include <sys/timeb.h>

    // For signal handling in Windows.
    //
    LONG  Win32FaultHandler(struct _EXCEPTION_POINTERS *  ExInfo);
    void  LogStackFrames(void *FaultAdress, char *);

#else // else if NOT _WIN32

// ----------------------------------------
// These added for the signal handling:
//
#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif
#ifndef __USE_GNU
#define __USE_GNU
#endif

    // This shitty apple section is for struct sigcontext for the signal handling.
#if defined(__APPLE__)
#define _XOPEN_SOURCE 600
    // Fucking Apple!
struct sigcontext
{
	  int eip;
};
#endif // defined __APPLE__
//#define __APPLE_API_OBSOLETE
//#include <sys/signal.h>
//#include <sys/ucontext.h>
//#else
#include <signal.h>
#include <ucontext.h>
//#endif
    
#include <wordexp.h>
#include <sys/time.h>
#include <sys/resource.h>

#include <execinfo.h>
//#endif
// ----------------------------------------

#include <unistd.h>

#endif // not _WIN32

    
#include <sys/stat.h>
} // extern C
// ---------------------------

// TinyThread++
//
#include "tinythread.h"   // These are in the header already.
//#include "fast_mutex.h"

using namespace tthread;

// ---------------------------------------------------------------------------

#include "ot_default_paths.h"

// ---------------------------------------------------------------------------

#ifndef _WIN32

void ot_terminate(void);


namespace {
    // invoke set_terminate as part of global constant initialization
    static const bool SET_TERMINATE = std::set_terminate(ot_terminate);
}
#endif




#ifdef ANDROID
#include <android/log.h>
#endif


#include "OTString.h"
#include "OTLog.h"


#ifndef _WIN32
#include "stacktrace.h"
#endif


// If it MUST output, set the verbosity to 0. Less important logs are
// at higher and higher levels.
//
// All are sent to stdout, but the 0 are the most important ones.
// By default, only those are actually logged. If you want to see the other messages,
// then set this log level to a higher value sometime when you start execution.
// (Or right here.)

#if defined (DSP)					   
int OTLog::__CurrentLogLevel = 0;	// If you build with DSP=1, it assumes a special location for OpenSSL,
#else								// and it turns off all the output.
int OTLog::__CurrentLogLevel = 0;
#endif


// These are only default values. There are configurable in the config file.
//
bool	OTLog::__blocking = false;	// Normally false. This means we will wait FOREVER when trying to send or receive.

// Delay after each message is sent (client side only.)
int		OTLog::__latency_send_delay_after = 50;	// It's 50 here after every server request, but also there's a default sleep of 50 in the java GUI after groups of messages.

int     OTLog::__latency_send_no_tries = 2; // Number of times will try to send a message.
int     OTLog::__latency_receive_no_tries = 2; // Number of times will try to receive a reply.

int     OTLog::__latency_send_ms = 5000; // number of ms to wait before retrying send.
int     OTLog::__latency_receive_ms = 5000; // number of ms to wait before retrying receive.


long	OTLog::__minimum_market_scale = 1;	// Server admin can configure this to any higher power-of-ten.


OTString OTLog::__Version = "0.82.k";





// ---------------------------------------------------------------------------------
// This is the "global" path to the subdirectories. The wallet file is probably also there.
//
OTString OTLog::__OTPath("."); // it defaults to '.' but then it is set by the client and server.
OTString OTLog::__OTConfigPath(OT_FOLDER_DEFAULT); // it defaults to "~/.ot" but then it can be refreshed with the wordexp translation.
OTString OTLog::__OTPrefixPath(OT_PREFIX_DEFAULT); // it defaults to "/usr/local" or "~/.local" but then it can be refreshed with the wordexp translation.



// All my paths now use the global path above, and are constructed using
// the path separator below. So the filesystem aspect of Open Transactions
// should be a LOT more portable to Windows, though I haven't actually tried
// it on Windows.
//
OTString OTLog::__OTPathSeparator = OT_DEFAULT_PATH_SEPARATOR;

// ---------------------------------------------------------------------------------


// Just a default value, since this is configurable programmatically.

// these are static

OTString OTLog::__OTCronFolder				= "cron";		
OTString OTLog::__OTNymFolder				= "nyms";		
OTString OTLog::__OTAccountFolder			= "accounts";	
OTString OTLog::__OTUserAcctFolder			= "useraccounts";	
OTString OTLog::__OTReceiptFolder			= "receipts";		
OTString OTLog::__OTNymboxFolder			= "nymbox";		
OTString OTLog::__OTInboxFolder				= "inbox";		
OTString OTLog::__OTOutboxFolder			= "outbox";	
OTString OTLog::__OTPaymentInboxFolder			= "paymentInbox";		
OTString OTLog::__OTRecordBoxFolder			= "recordBox";
OTString OTLog::__OTCertFolder				= "certs";		
OTString OTLog::__OTPubkeyFolder			= "pubkeys";
OTString OTLog::__OTContractFolder			= "contracts";
OTString OTLog::__OTMintFolder				= "mints";
OTString OTLog::__OTSpentFolder				= "spent";
OTString OTLog::__OTPurseFolder				= "purse";
OTString OTLog::__OTMarketFolder			= "markets";
OTString OTLog::__OTScriptFolder			= "scripts";
OTString OTLog::__OTSmartContractsFolder		= "smartcontracts";


OTString OTLog::__OTLogfile;

// If Logfile uninitialized, we assume NO logfile, and we log to output.
// Otherwise, we append to the logfile, and leave output clear.

// --------------------------------------------------

dequeOfStrings OTLog::__logDeque; // Stores the last 1024 logs in memory.


// *********************************************************************************

// SIGNALS
//
// To get the most mileage out of this signal handler, 
// compile it with the options:  -g -rdynamic 
//

// *********************************************************************************



#ifdef _WIN32   // Windows SIGNALS

// The windows version is from Stefan Wörthmüller, who wrote an excellent article
// at Dr. Dobbs Journal here:
// http://www.drdobbs.com/architecture-and-design/185300443
//

//static
void OTLog::SetupSignalHandler()
{
    static int nCount = 0;
    
    if (0 == nCount)
    {
        ++nCount;
        SetUnhandledExceptionFilter((LPTOP_LEVEL_EXCEPTION_FILTER)Win32FaultHandler);
    }
}

LONG Win32FaultHandler(struct _EXCEPTION_POINTERS *  ExInfo)
{   
    char  *FaultTx = "";
    
    switch(ExInfo->ExceptionRecord->ExceptionCode)
    {
        case EXCEPTION_ACCESS_VIOLATION          : FaultTx = "ACCESS VIOLATION"         ; break;
        case EXCEPTION_DATATYPE_MISALIGNMENT     : FaultTx = "DATATYPE MISALIGNMENT"    ; break;
        case EXCEPTION_BREAKPOINT                : FaultTx = "BREAKPOINT"               ; break;
        case EXCEPTION_SINGLE_STEP               : FaultTx = "SINGLE STEP"              ; break;
        case EXCEPTION_ARRAY_BOUNDS_EXCEEDED     : FaultTx = "ARRAY BOUNDS EXCEEDED"    ; break;
        case EXCEPTION_FLT_DENORMAL_OPERAND      : FaultTx = "FLT DENORMAL OPERAND"     ; break;
        case EXCEPTION_FLT_DIVIDE_BY_ZERO        : FaultTx = "FLT DIVIDE BY ZERO"       ; break;
        case EXCEPTION_FLT_INEXACT_RESULT        : FaultTx = "FLT INEXACT RESULT"       ; break;
        case EXCEPTION_FLT_INVALID_OPERATION     : FaultTx = "FLT INVALID OPERATION"    ; break;
        case EXCEPTION_FLT_OVERFLOW              : FaultTx = "FLT OVERFLOW"             ; break;
        case EXCEPTION_FLT_STACK_CHECK           : FaultTx = "FLT STACK CHECK"          ; break;
        case EXCEPTION_FLT_UNDERFLOW             : FaultTx = "FLT UNDERFLOW"            ; break;
        case EXCEPTION_INT_DIVIDE_BY_ZERO        : FaultTx = "INT DIVIDE BY ZERO"       ; break;
        case EXCEPTION_INT_OVERFLOW              : FaultTx = "INT OVERFLOW"             ; break;
        case EXCEPTION_PRIV_INSTRUCTION          : FaultTx = "PRIV INSTRUCTION"         ; break;
        case EXCEPTION_IN_PAGE_ERROR             : FaultTx = "IN PAGE ERROR"            ; break;
        case EXCEPTION_ILLEGAL_INSTRUCTION       : FaultTx = "ILLEGAL INSTRUCTION"      ; break;
        case EXCEPTION_NONCONTINUABLE_EXCEPTION  : FaultTx = "NONCONTINUABLE EXCEPTION" ; break;
        case EXCEPTION_STACK_OVERFLOW            : FaultTx = "STACK OVERFLOW"           ; break;
        case EXCEPTION_INVALID_DISPOSITION       : FaultTx = "INVALID DISPOSITION"      ; break;
        case EXCEPTION_GUARD_PAGE                : FaultTx = "GUARD PAGE"               ; break;
        default: FaultTx = "(unknown)";           break;
    }
    int    wsFault    = ExInfo->ExceptionRecord->ExceptionCode;
    void * CodeAdress = ExInfo->ExceptionRecord->ExceptionAddress;
    
    // (using stderr.)
//  sgLogFile = fopen("Win32Fault.log", "w");
    
    if(stderr != NULL)
    {
        fprintf(stderr, "****************************************************\n");
        fprintf(stderr, "*** A Programm Fault occured:\n");
        fprintf(stderr, "*** Error code %08X: %s\n", wsFault, FaultTx);
        fprintf(stderr, "****************************************************\n");
        fprintf(stderr, "***   Address: %08X\n", (int)CodeAdress);
        fprintf(stderr, "***     Flags: %08X\n", ExInfo->ExceptionRecord->ExceptionFlags);
        
#if defined (_CONSOLE)
        printf("\n");
        printf("*** A Programm Fault occured:\n");
        printf("*** Error code %08X: %s\n", wsFault, FaultTx);
#endif
        /* This infomation ssems to be wrong
         if(ExInfo->ExceptionRecord->ExceptionCode == EXCEPTION_ACCESS_VIOLATION)
         {
         fprintf(stderr, "****************************************************\n");
         fprintf(stderr, "*** Attempted to %s to address %08LX \n", 
         ExInfo->ExceptionRecord->ExceptionInformation[0] ? "write" : "read",
         ExInfo->ExceptionRecord->ExceptionInformation[1]);
         
         }
         */ 
#ifdef _WIN64
//		LogStackFrames(CodeAdress, (char *)ExInfo->ContextRecord->Rbp);
#else
        LogStackFrames(CodeAdress, (char *)ExInfo->ContextRecord->Ebp);
#endif
        
//      fclose(sgLogFile);
    }
    
    
    
    /*if(want to continue)
     {
     ExInfo->ContextRecord->Eip++;
     #if defined (_CONSOLE)
     printf("*** Trying to continue\n");
     printf("\n");
     #endif
     return EXCEPTION_CONTINUE_EXECUTION;
     }
     */ 
    
    printf("*** Terminating\n");
    printf("\n");
    return EXCEPTION_EXECUTE_HANDLER;
}
/////////////////////////////////////////////////////////////////////////////
// Unwind the stack and save its return addresses to the logfile
/////////////////////////////////////////////////////////////////////////////



void   LogStackFrames(void *FaultAdress, char *eNextBP)

{      
#if defined(_WIN64)
    
    typedef USHORT (WINAPI *CaptureStackBackTraceType)(__in ULONG, __in ULONG, __out PVOID*, __out_opt PULONG);
    CaptureStackBackTraceType func = (CaptureStackBackTraceType)
        (GetProcAddress(LoadLibrary(L"kernel32.dll"), "RtlCaptureStackBackTrace"));

    
    if(func == NULL)
        return;
    
    // Quote from Microsoft Documentation:
    // ## Windows Server 2003 and Windows XP:  
    // ## The sum of the FramesToSkip and FramesToCapture parameters must be less than 63.
    const int kMaxCallers = 62; 
    
    void* callers[kMaxCallers];
    int count = (func)(0, kMaxCallers, callers, NULL);
    for(int i = 0; i < count; i++)
        fprintf(stderr, "*** %d called from %016I64LX\n", i, callers[i]);
    
#elif defined (_WIN32) // not _WIN64 ? Must be _WIN32
    
    char *p = NULL, *pBP = NULL;
    unsigned i = 0, x = 0, BpPassed = 0;
    static int  CurrentlyInTheStackDump = 0;
    
    if(CurrentlyInTheStackDump)
    {
        fprintf(stderr, "\n***\n*** Recursive Stack Dump skipped\n***\n");
        return;
    }
    
    fprintf(stderr, "****************************************************\n");
    fprintf(stderr, "*** CallStack:\n");
    fprintf(stderr, "****************************************************\n");
    
    /* ====================================================================== */
    /*                                                                        */
    /*      BP +x ...    -> == SP (current top of stack)                      */
    /*            ...    -> Local data of current function                    */
    /*      BP +4 0xabcd -> 32 address of calling function                    */
    /*  +<==BP    0xabcd -> Stack address of next stack frame (0, if end)     */
    /*  |   BP -1 ...    -> Aruments of function call                         */
    /*  Y                                                                     */
    /*  |   BP -x ...    -> Local data of calling function                    */
    /*  |                                                                     */
    /*  Y  (BP)+4 0xabcd -> 32 address of calling function                    */
    /*  +==>BP)   0xabcd -> Stack address of next stack frame (0, if end)     */
    /*            ...                                                         */
    /* ====================================================================== */
    CurrentlyInTheStackDump = 1;
    
    
    BpPassed = (eNextBP != NULL);
    
    if(! eNextBP)
    {
        _asm mov     eNextBP, eBp   
    }
    else 
        fprintf(stderr, "\n  Fault Occured At $ADDRESS:%08LX\n", (int)FaultAdress);
    
    
    // prevent infinite loops
    for(i = 0; eNextBP && i < 100; i++)
    {      
        pBP = eNextBP;           // keep current BasePointer
        eNextBP = *(char **)pBP; // dereference next BP 
        
        p = pBP + 8; 
        
        // Write 20 Bytes of potential arguments
        fprintf(stderr, "         with ");                                                          
        for(x = 0; p < eNextBP && x < 20; p++, x++)
            fprintf(stderr, "%02X ", *(unsigned char *)p);
        
        fprintf(stderr, "\n\n");                                                          
        
        if(i == 1 && ! BpPassed) 
            fprintf(stderr, "****************************************************\n"
                    "         Fault Occured Here:\n");
        
        // Write the backjump address
        fprintf(stderr, "*** %2d called from $ADDRESS:%08X\n", i, *(char **)(pBP + 4));
        
        if(*(char **)(pBP + 4) == NULL)
            break; 
    }
    
    
    fprintf(stderr, "************************************************************\n");
    fprintf(stderr, "\n\n");
    
    
    CurrentlyInTheStackDump = 0;
    
    fflush(stderr);
#endif // _WIN64 else (_WIN32) endif
}


// *********************************************************************************

#else  // if _WIN32, else:      UNIX -- SIGNALS

// UNIX

// This is our custom std::terminate handler for SIGABRT
//
void ot_terminate() 
{
    static tthread::mutex the_Mutex;
    
    tthread::lock_guard<tthread::mutex> lock(the_Mutex);
    
    static bool tried_throw = false;
    
    try {
        // try once to re-throw currently active exception
        if (!tried_throw) {
            tried_throw = true;
            throw;
        }
    }
    catch (const std::exception &e) {
        std::cerr << "ot_terminate: " << __FUNCTION__ << " caught unhandled exception. type: " << typeid(e).name() << " what(): "
        << e.what() << std::endl;
    }
    catch (...) {
        std::cerr << "ot_terminate: " << __FUNCTION__ << " caught unknown/unhandled exception." 
        << std::endl;
    }
    
    /*
     void * array[50];
     int size = backtrace(array, 50);    
     
     std::cerr << "ot_terminate: " << __FUNCTION__ << " backtrace returned " << size << " frames\n\n";
     
     char ** messages = backtrace_symbols(array, size);
     
     for (int i = 0; i < size && messages != NULL; ++i) {
     std::cerr << "[bt]: (" << i << ") " << messages[i] << std::endl;
     }
     std::cerr << std::endl;
     
     free(messages);
     
     abort();
     */
    
    void * array[50];
    int size = backtrace(array, 50);
    
    char ** messages = backtrace_symbols(array, size);    
    
    // skip first stack frame (points here)
    for (int i = 1; i < size && messages != NULL; ++i)
    {
        char *mangled_name = 0, *offset_begin = 0, *offset_end = 0;
        
        // find parantheses and +address offset surrounding mangled name
        for (char *p = messages[i]; *p; ++p)
        {
            if (*p == '(') 
            {
                mangled_name = p; 
            }
            else if (*p == '+') 
            {
                offset_begin = p;
            }
            else if (*p == ')')
            {
                offset_end = p;
                break;
            }
        }
        
        // if the line could be processed, attempt to demangle the symbol
        if (mangled_name && offset_begin && offset_end && 
            mangled_name < offset_begin)
        {
            *mangled_name++ = '\0';
            *offset_begin++ = '\0';
            *offset_end++ = '\0';
            
            int status;
            char * real_name = abi::__cxa_demangle(mangled_name, 0, 0, &status);
            
            // if demangling is successful, output the demangled function name
            if (status == 0)
            {    
                std::cerr << "[bt]: (" << i << ") " << messages[i] << " : " 
                << real_name << "+" << offset_begin << offset_end 
                << std::endl;
                
            }
            // otherwise, output the mangled function name
            else
            {
                std::cerr << "[bt]: (" << i << ") " << messages[i] << " : " 
                << mangled_name << "+" << offset_begin << offset_end 
                << std::endl;
            }
            free(real_name);
        }
        // otherwise, print the whole line
        else
        {
            std::cerr << "[bt]: (" << i << ") " << messages[i] << std::endl;
        }
    }
    std::cerr << std::endl;
    
    free(messages);
    
    abort(); 
}




// CREDIT: the Linux / GNU portion of the signal handler comes from StackOverflow,
// where several answers are combined here.
// http://stackoverflow.com/questions/77005/how-to-generate-a-stacktrace-when-my-gcc-c-app-crashes
//

struct sig_ucontext_t {
//  typedef struct _sig_ucontext {
    unsigned long     uc_flags;
    struct ucontext   *uc_link;
    stack_t           uc_stack;
    struct sigcontext uc_mcontext;
    sigset_t          uc_sigmask;
};

extern "C" {
    // This structure mirrors the one found in /usr/include/asm/ucontext.h 
    //

    void crit_err_hdlr(int sig_num, siginfo_t * info, void * ucontext);
}

#if defined(OT_NO_DEMANGLING_STACK_TRACE)

// this version doesn't do demangling.
void crit_err_hdlr(int sig_num, siginfo_t * info, void * ucontext)
{
    void *             array[50];
    void *             caller_address;
    char **            messages;
    int                size, i;
    sig_ucontext_t *   uc;
 
    static tthread::mutex the_Mutex;
    
    tthread::lock_guard<tthread::mutex> lock(the_Mutex);

    uc = (sig_ucontext_t *)ucontext;
    
    // Get the address at the time the signal was raised from the EIP (x86)
    caller_address = (void *) uc->uc_mcontext.eip;   
    
    fprintf(stderr, "signal %d (%s), address is %p from %p\n", 
            sig_num, strsignal(sig_num), info->si_addr, 
            (void *)caller_address);
    
    size = backtrace(array, 50);
    
    // overwrite sigaction with caller's address
    //
    array[1] = caller_address;
    
    messages = backtrace_symbols(array, size);
    
    // skip first stack frame (points here)
    //
    for (i = 1; i < size && messages != NULL; ++i)
    {
        fprintf(stderr, "[bt]: (%d) %s\n", i, messages[i]);
    }
    
    free(messages);
    
    _exit(0);
}

#else   // #if no demangling, #else...
/*
// This version DOES do demangling.
//
void crit_err_hdlr(int sig_num, siginfo_t * info, void * ucontext)
{
    sig_ucontext_t * uc = (sig_ucontext_t *)ucontext;
    
    void * caller_address = (void *) uc->uc_mcontext.eip; // x86 specific
    
    std::cerr << "signal " << sig_num 
    << " (" << strsignal(sig_num) << "), address is " 
    << info->si_addr << " from " << caller_address 
    << std::endl << std::endl;
    
    void * array[50];
    int size = backtrace(array, 50);
    
    array[1] = caller_address;
    
    char ** messages = backtrace_symbols(array, size);    
    
    // skip first stack frame (points here)
    for (int i = 1; i < size && messages != NULL; ++i)
    {
        char *mangled_name = 0, *offset_begin = 0, *offset_end = 0;
        
        // find parantheses and +address offset surrounding mangled name
        for (char *p = messages[i]; *p; ++p)
        {
            if (*p == '(') 
            {
                mangled_name = p; 
            }
            else if (*p == '+') 
            {
                offset_begin = p;
            }
            else if (*p == ')')
            {
                offset_end = p;
                break;
            }
        }
        
        // if the line could be processed, attempt to demangle the symbol
        if (mangled_name && offset_begin && offset_end && 
            mangled_name < offset_begin)
        {
            *mangled_name++ = '\0';
            *offset_begin++ = '\0';
            *offset_end++ = '\0';
            
            int status;
            char * real_name = abi::__cxa_demangle(mangled_name, 0, 0, &status);
            
            // if demangling is successful, output the demangled function name
            if (status == 0)
            {    
                std::cerr << "[bt]: (" << i << ") " << messages[i] << " : " 
                << real_name << "+" << offset_begin << offset_end 
                << std::endl;
                
            }
            // otherwise, output the mangled function name
            else
            {
                std::cerr << "[bt]: (" << i << ") " << messages[i] << " : " 
                << mangled_name << "+" << offset_begin << offset_end 
                << std::endl;
            }
            free(real_name);
        }
        // otherwise, print the whole line
        else
        {
            std::cerr << "[bt]: (" << i << ") " << messages[i] << std::endl;
        }
    }
    std::cerr << std::endl;
    
    free(messages);
    
    _exit(0); 
}
*/

void
crit_err_hdlr(int sig_num, siginfo_t *info, void *v)
{
    static tthread::mutex the_Mutex;
    
    tthread::lock_guard<tthread::mutex> lock(the_Mutex);

    
    assert(NULL != v);
    
    int read = 0;
    
#ifdef _LP64
    typedef uint64_t ot_ulong;
#else
    typedef uint32_t ot_ulong;
#endif // lp64
    
    ot_ulong addr=0,
             eip=0,
             esp=0;
    ucontext_t *uc = (ucontext_t *)v;
    
#if defined(__APPLE__)
    mcontext_t mc;
    mc = uc->uc_mcontext;
    addr = (ot_ulong)info->si_addr;
    read = !(mc->__es.__err&2);
#ifdef _LP64
    eip = mc->__ss.__rip;
    esp = mc->__ss.__rsp;
#else
    eip = mc->__ss.__eip;
    esp = mc->__ss.__esp;
#endif
#elif defined(__linux__)
    mcontext_t *mc;
    struct sigcontext *ctx;
    mc = &uc->uc_mcontext;
    ctx = (struct sigcontext*)mc;
    addr = (ot_ulong)info->si_addr;
    read = !(ctx->err&2);
#ifdef i386
    eip = ctx->eip;
    esp = ctx->esp;
#else
    eip = ctx->rip;
    esp = ctx->rsp;
#endif
#elif defined(__FreeBSD__)
    mcontext_t *mc;
    mc = &uc->uc_mcontext;
#ifdef __i386__
    eip = mc->mc_eip;
    esp = mc->mc_esp;
#elif defined(__amd64__)
    eip = mc->mc_rip;
    esp = mc->mc_rsp;
#endif
    addr = (ot_ulong)info->si_addr;
    if(__FreeBSD__ < 7){
        /*
         * FreeBSD /usr/src/sys/i386/i386/trap.c kludgily reuses
         * frame->tf_err as somewhere to put the faulting address
         * (cr2) when calling into the generic signal dispatcher.
         * Unfortunately, that means that the bit in tf_err that says
         * whether this is a read or write fault is irretrievably gone.
         * So we have to figure it out.  Let's assume that if the page
         * is already mapped in core, it is a write fault.  If not, it is a
         * read fault.  
         *
         * This is apparently fixed in FreeBSD 7, but I don't have any
         * FreeBSD 7 machines on which to verify this.
         */
        char vec;
        int r;
        
        vec = 0;
        r = mincore((void*)addr, 1, &vec);
        //iprint("FreeBSD fault [%d]: addr=%p[%p] mincore=%d vec=%#x errno=%d\n", signo, addr, (uchar*)addr-uzero, r, vec, errno);
        if(r < 0 || vec == 0)
            mc->mc_err = 0; /* read fault */
        else
            mc->mc_err = 2; /* write fault */
    }
    read = !(mc->mc_err&2);
#else
#       error   "Unknown OS in sigsegv"
#endif

    
    void * caller_address = (void *) eip; 
    
    std::cerr << "signal " << sig_num 
    << " (" << strsignal(sig_num) << "), address is " 
    << info->si_addr << " from " << caller_address 
    << std::endl << std::endl;
    
    void * array[50];
    int size = backtrace(array, 50);
    
    array[1] = caller_address;
    
    char ** messages = backtrace_symbols(array, size);    
    
    // skip first stack frame (points here)
    for (int i = 1; i < size && messages != NULL; ++i)
    {
        char *mangled_name = 0, *offset_begin = 0, *offset_end = 0;
        
        // find parantheses and +address offset surrounding mangled name
        for (char *p = messages[i]; *p; ++p)
        {
            if (*p == '(') 
            {
                mangled_name = p; 
            }
            else if (*p == '+') 
            {
                offset_begin = p;
            }
            else if (*p == ')')
            {
                offset_end = p;
                break;
            }
        }
        
        // if the line could be processed, attempt to demangle the symbol
        if (mangled_name && offset_begin && offset_end && 
            mangled_name < offset_begin)
        {
            *mangled_name++ = '\0';
            *offset_begin++ = '\0';
            *offset_end++ = '\0';
            
            int status;
            char * real_name = abi::__cxa_demangle(mangled_name, 0, 0, &status);
            
            // if demangling is successful, output the demangled function name
            if (status == 0)
            {    
                std::cerr << "[bt]: (" << i << ") " << messages[i] << " : " 
                << real_name << "+" << offset_begin << offset_end 
                << std::endl;
                
            }
            // otherwise, output the mangled function name
            else
            {
                std::cerr << "[bt]: (" << i << ") " << messages[i] << " : " 
                << mangled_name << "+" << offset_begin << offset_end 
                << std::endl;
            }
            free(real_name);
        }
        // otherwise, print the whole line
        else
        {
            std::cerr << "[bt]: (" << i << ") " << messages[i] << std::endl;
        }
    }
    std::cerr << std::endl;
    
    free(messages);
    
    _exit(0); 
}


#endif // defined(OT_NO_DEMANGLING_STACK_TRACE)

// --------------------------------------
#ifndef OT_HANDLE_SIGNAL
#define OT_HANDLE_SIGNAL(OT_SIGNAL_TYPE) \
{ \
\
    struct sigaction new_action, old_action; \
    new_action.sa_sigaction = crit_err_hdlr; \
    sigemptyset (&new_action.sa_mask); \
    new_action.sa_flags = SA_RESTART | SA_SIGINFO;  \
\
    sigaction(OT_SIGNAL_TYPE, NULL, &old_action); \
\
    if (old_action.sa_handler != SIG_IGN) \
    { \
        if (sigaction(OT_SIGNAL_TYPE, &new_action, NULL) != 0) \
        { \
            OTLog::vError("OTLog::SetupSignalHandler: Failed setting signal handler for error %d (%s)\n", \
                          OT_SIGNAL_TYPE, strsignal(OT_SIGNAL_TYPE)); \
            abort(); \
        } \
    } \
}
#endif
// --------------------------------------

//static
void OTLog::SetupSignalHandler()
{
    static int nCount = 0;
    
    if (0 == nCount)
    {
        ++nCount;
        // --------------------------------------
        OT_HANDLE_SIGNAL(SIGINT)  // Ctrl-C. (So we can shutdown gracefully, I suppose, on Ctrl-C.)
        OT_HANDLE_SIGNAL(SIGSEGV) // Segmentation fault.
//      OT_HANDLE_SIGNAL(SIGABRT) // Abort.
        OT_HANDLE_SIGNAL(SIGBUS)  // Bus error
    //  OT_HANDLE_SIGNAL(SIGHUP)  // I believe this is for sending a "restart" signal to your process, that sort of thing.
        OT_HANDLE_SIGNAL(SIGTERM) // Used by kill pid (NOT kill -9 pid). Used for "killing softly."
        OT_HANDLE_SIGNAL(SIGILL)  // Illegal instruction.
        OT_HANDLE_SIGNAL(SIGTTIN) // SIGTTIN may be sent to a background process that attempts to read from its controlling terminal.
        OT_HANDLE_SIGNAL(SIGTTOU) // SIGTTOU may be sent to a background process that attempts to write to its controlling terminal.
    //  OT_HANDLE_SIGNAL(SIGPIPE) // Unix supports the principle of piping. When a pipe is broken, the process writing to it is sent the SIGPIPE.
    //  OT_HANDLE_SIGNAL(SIGKILL) // kill -9. "The receiving process cannot perform any clean-up upon receiving this signal."
        OT_HANDLE_SIGNAL(SIGFPE)  // Floating point exception.
        OT_HANDLE_SIGNAL(SIGXFSZ) // SIGXFSZ is the signal sent to a process when it grows a file larger than the maximum allowed size.
    //  OT_HANDLE_SIGNAL(SIGQUIT) // SIGQUIT is the signal sent to a process by its controlling terminal when the user requests that the process perform a core dump.
        OT_HANDLE_SIGNAL(SIGSYS)  // sent when a process supplies an incorrect argument to a system call.
    //  OT_HANDLE_SIGNAL(SIGTRAP) // used by debuggers
        // --------------------------------------
    }
}

#endif  // #if windows, #else (unix) #endif. (SIGNAL handling.)

// *********************************************************************************









// static
// Changes ~/blah to /Users/au/blah
//
void OTLog::TransformFilePath(const char * szInput, OTString & strOutput)
{
    OT_ASSERT(NULL != szInput);
    
#ifndef _WIN32 // if UNIX (NOT windows)
	wordexp_t exp_result;
	
    exp_result.we_wordc = 0;
    exp_result.we_wordv = NULL;
    exp_result.we_offs  = 0;
    
    OTString strError;
    
    const int nWordExp = wordexp(szInput, &exp_result, WRDE_NOCMD|WRDE_SHOWERR|WRDE_UNDEF);
    
	if (0 != nWordExp)  // If non-zero, then failure.
	{
        switch (nWordExp)
        {
//          case 0:			// Successful.
//              break;
            case WRDE_BADCHAR:
                strError = "An unquoted metacharacter appeared in the wrong place.";
                break;
            case WRDE_BADVAL:
                strError = "There was an undefined environment variable reference with the WRDE_UNDEF flag set.";
                break;
            case WRDE_CMDSUB:
                strError = "Command substitution was requested with the WRDE_NOCMD flag set.";
                break;
            case WRDE_SYNTAX:
                strError = "There was a sh syntax error.";
                break;
            case WRDE_NOSPACE:
                /* If the error was WRDE_NOSPACE,
                 then perhaps part of the result was allocated.  */
//              wordfree (&exp_result);
                strError = "The process ran out of memory.";
                break;
            default:                    /* Some other error.  */
                strError = "(UNDEFINED!)";
                break;
        }
        

		OTLog::vError("%s: Error calling wordexp() to expand path: %s\nWORDEXP OUTPUT: %s\n", 
                      __FUNCTION__, szInput, strError.Get());
		wordfree(&exp_result); 
		strOutput.Set(szInput);
		return;
	}
	// ----------------------------
	
	std::string str_Output("");
	
    if ((exp_result.we_wordc > 0) && (NULL != exp_result.we_wordv))
    {
        // wordexp tokenizes by space (as well as expands, which is why I'm using it.)
        // Therefore we need to iterate through the tokens, and create a single string
        // with spaces between the tokens.
        //
        int nCount = -1;
        
        for (unsigned int i = 0; (i < exp_result.we_wordc) && (exp_result.we_wordv[i] != NULL); ++i)
        {
            ++nCount; // 0 on first iteration.
            // ---------------
            str_Output += exp_result.we_wordv[i];
            
            if (static_cast<unsigned int>(nCount) < (exp_result.we_wordc)-1) // we don't add a space after the last one.
                str_Output += " ";
        }
        
        wordfree(&exp_result); 
    }
    
    if (str_Output.size() > 0)
        strOutput.Set(str_Output.c_str());
    else
        strOutput.Set(szInput);
#else
	strOutput.Set(szInput);
#endif  
}


// *********************************************************************************




const char * OTLog::GetMemlogAtIndex(int nIndex)
{
	unsigned int uIndex = static_cast<unsigned int> (nIndex);
	
	if ((nIndex < 0) || (uIndex >= __logDeque.size()))
	{
		OTLog::vError("%s: index out of bounds: %d\n", __FUNCTION__, nIndex);
		return NULL;
	}
	
	OTString * pStr = __logDeque.at(uIndex);
	
	if ((NULL != pStr) && (pStr->Exists()))
		return pStr->Get();
	
	return NULL;
}


// --------------------------------------------------
// We keep 1024 logs in memory, to make them available via the API.

int OTLog::GetMemlogSize() 
{
	return __logDeque.size();
}


const char * OTLog::PeekMemlogFront()
{
	if (__logDeque.size() <= 0)
		return NULL;
	
	OTString * pStr = __logDeque.front();
	
	if ((NULL != pStr) && (pStr->Exists()))
		return pStr->Get();
	
	return NULL;
}


const char * OTLog::PeekMemlogBack()
{
	if (__logDeque.size() <= 0)
		return NULL;
	
	OTString * pStr = __logDeque.back();
	
	if ((NULL != pStr) && (pStr->Exists()))
		return pStr->Get();
	
	return NULL;	
}


bool OTLog::PopMemlogFront()
{
	if (__logDeque.size() <= 0)
		return false;
	
	OTString * pStr = __logDeque.front();
	
	if (NULL != pStr)
	{
		delete pStr;
		pStr = NULL;
	}
	
	__logDeque.pop_front();
	
	return true;		
}


bool OTLog::PopMemlogBack()
{
	if (__logDeque.size() <= 0)
		return false;
	
	OTString * pStr = __logDeque.back();
	
	if (NULL != pStr)
	{
		delete pStr;
		pStr = NULL;
	}
	
	__logDeque.pop_back();
	
	return true;			
}


bool OTLog::PushMemlogFront(const char * szLog)
{
	OT_ASSERT(NULL != szLog);
	
	OTString * pStr = new OTString(szLog);
	
	OT_ASSERT(NULL != pStr);

	__logDeque.push_front(pStr);
	
	if (__logDeque.size() > 1024) // todo: stop hardcoding.
	{
		OTLog::PopMemlogBack(); // We start removing from the back when it reaches this size.
	}
	
	return true;
}

bool OTLog::PushMemlogBack(const char * szLog)
{
	OT_ASSERT(NULL != szLog);
	
	OTString * pStr = new OTString(szLog);
	
	OT_ASSERT(NULL != pStr);
	
	__logDeque.push_back(pStr);
	
	return true;	
}


// --------------------------------------------------


/*
 void sleep( unsigned int in_mseconds )
 {
 
 }
 
 
 void ssleep( unsigned int in_seconds )
 {
 }
 */



// ---------------------------------------------------------------------------------

void OTLog::SleepSeconds(long lSeconds)
{
#ifdef _WIN32
	Sleep(1000 * lSeconds);
#else
	sleep(lSeconds);
#endif	
}


void OTLog::SleepMilliseconds(long lMilliseconds)
{
#ifdef _WIN32
	Sleep( lMilliseconds );
#else
	usleep( lMilliseconds * 1000 );
#endif	
}


// ---------------------------------------------------------------------------------


// Private; never actually called.
OTLog::OTLog()
{
	
}

// Never actually called. Never instantiated.
OTLog::~OTLog()
{
	
}

// -------------------------------------------------------

// This function is for things that should NEVER happen.
// In fact you should never even call it -- use the OT_ASSERT() macro instead.

int OTLog::Assert(const char * szFilename, int nLinenumber, const char * szMessage)
{
	if (NULL != szMessage)
	{
#ifndef ANDROID // if NOT android
		std::cerr << szMessage << "\n";		
		// -----------------------------
		LogToFile(szMessage); LogToFile("\n");
		// -----------------------------
				
#else // if Android
		__android_log_write(ANDROID_LOG_FATAL,"OT Assert", szMessage);
#endif
		
#ifndef _WIN32
		print_stacktrace();
#endif
	}
	
	return OTLog::Assert(szFilename, nLinenumber);
}

int OTLog::Assert(const char * szFilename, int nLinenumber)
{
	if ((NULL != szFilename))
	{
#ifndef ANDROID // if NOT android
		std::cerr << "OT_ASSERT in " << szFilename << " at line " << nLinenumber << "\n";
		
		// -----------------------------
		// Grab this if we can, too...
		//
		OTString strTemp;
		strTemp.Format("OT_ASSERT in %s at line %d\n", szFilename, nLinenumber);
		LogToFile(strTemp.Get());
		// -----------------------------
		
#else // if Android
		OTString strAndroidAssertMsg;
		strAndroidAssertMsg.Format("\nOT_ASSERT in %s at line %d\n", szFilename, nLinenumber);
		__android_log_write(ANDROID_LOG_FATAL,"OT Assert", (const char *)strAndroidAssertMsg.Get());
#endif
		
#ifndef _WIN32
		print_stacktrace();
#endif
		
	}
	
	abort();
	return -1;
}


// If there's no logfile, then send it to stderr.
// (So we can still see it on the screen, but it doesn't interfere with any
// command line utilities who might otherwise interpret it as their own input,
// if I was actually writing to stdout.)
//
void OTLog::LogToFile(const char * szOutput)
{
    // Append to logfile
	if ((NULL != szOutput) && OTLog::__OTLogfile.Exists())
	{
		std::ofstream logfile;
		logfile.open (OTLog::Logfile(), std::ios::app);

		if(!logfile.fail())
		{
			logfile << szOutput;
			logfile.close();
		}
	}
//	else // We now do this either way. 
	{
		std::cerr << szOutput;	
		std::cerr.flush();
	}
}



// -------------------------------------------------------

// For normal output. The higher the verbosity, the less important the message.
// (Verbose level 0 ALWAYS logs.) Currently goes to stdout.

void OTLog::Output(int nVerbosity, const char *szOutput)
{
	// If log level is 0, and verbosity of this message is 2, don't bother logging it.
//	if (nVerbosity > OTLog::__CurrentLogLevel || (NULL == szOutput))
	if ((nVerbosity > OTLog::__CurrentLogLevel) || (NULL == szOutput) || (OTLog::__CurrentLogLevel == (-1)))		
		return; 

	// We store the last 1024 logs so programmers can access them via the API.
	OTLog::PushMemlogFront(szOutput);
	
	// ---------------------------------------
	
#ifndef ANDROID // if NOT android
	
	LogToFile(szOutput);

#else // if IS Android
	/*
	 typedef enum android_LogPriority {
	 ANDROID_LOG_UNKNOWN = 0,
	 ANDROID_LOG_DEFAULT,    // only for SetMinPriority()
	 ANDROID_LOG_VERBOSE,
	 ANDROID_LOG_DEBUG,
	 ANDROID_LOG_INFO,
	 ANDROID_LOG_WARN,
	 ANDROID_LOG_ERROR,
	 ANDROID_LOG_FATAL,
	 ANDROID_LOG_SILENT,     // only for SetMinPriority(); must be last
	 } android_LogPriority;
	 */
	switch (nVerbosity) {
		case 0:
		case 1:
			__android_log_write(ANDROID_LOG_INFO,"OT Output", szOutput);
			break;
		case 2:
		case 3:
			__android_log_write(ANDROID_LOG_DEBUG,"OT Debug", szOutput);
			break;
		case 4:
		case 5:
			__android_log_write(ANDROID_LOG_VERBOSE,"OT Verbose", szOutput);
			break;
		default:
			__android_log_write(ANDROID_LOG_UNKNOWN,"OT Unknown", szOutput);
			break;
	}
#endif
}

void OTLog::Output(int nVerbosity, OTString & strOutput)
{
	if (strOutput.Exists())
		OTLog::Output(nVerbosity, strOutput.Get());
}

// the vOutput is to avoid name conflicts.
void OTLog::vOutput(int nVerbosity, const char *szOutput, ...)
{
	// If log level is 0, and verbosity of this message is 2, don't bother logging it.
	if (nVerbosity > OTLog::__CurrentLogLevel || (NULL == szOutput))
		return; 
	
	va_list args;
	
   	// _WIN32
	static char * new_string = NULL;
	
	if (NULL == new_string)
	{
		new_string = new char[MAX_STRING_LENGTH]; // This only happens once -- static var.
		
		OT_ASSERT(NULL != new_string);
		
		memset(new_string, 0, MAX_STRING_LENGTH);
	}
	
	new_string[0] = '\0';
	// _end _WIN32
	
	va_start(args, szOutput);
	
#ifdef _WIN32
	vsprintf_s(new_string, MAX_STRING_LENGTH, szOutput, args);
#else
	vsnprintf(new_string, MAX_STRING_LENGTH, szOutput, args);
#endif
	
	va_end(args);
	
	OTLog::Output(nVerbosity, new_string);
}



// -----------------------------------------------------------------

// An error has occurred, that somehow doesn't match the Assert or Output functions.
// So use this one instead.  This ALWAYS logs and currently it all goes to stderr.

void OTLog::Error(const char *szError)
{
	if ((NULL == szError))
		return; 
	
	// We store the last 1024 logs so programmers can access them via the API.
	OTLog::PushMemlogFront(szError);

#ifndef ANDROID // if NOT android
	
	LogToFile(szError);
	
#else // if Android
	__android_log_write(ANDROID_LOG_ERROR,"OT Error", szError);
#endif
}

void OTLog::Error(OTString & strError)
{
	if (strError.Exists())
		OTLog::Error(strError.Get());
}

// the vError name is to avoid name conflicts
void OTLog::vError(const char *szError, ...)
{
	if ((NULL == szError))
		return; 
	
	va_list args;
	
   	// _WIN32
	static char * new_string = NULL;
	
	if (NULL == new_string)
	{
		new_string = new char[MAX_STRING_LENGTH]; // This only happens once -- static var.
		
		OT_ASSERT(NULL != new_string);
		
		memset(new_string, 0, MAX_STRING_LENGTH);
	}
	
	new_string[0] = '\0';
	// _end _WIN32
	
	va_start(args, szError);
	
#ifdef _WIN32
	vsprintf_s(new_string, MAX_STRING_LENGTH, szError, args);
#else
	vsnprintf(new_string, MAX_STRING_LENGTH, szError, args);
#endif
	
	va_end(args);
	
	OTLog::Error(new_string);
}


// NOTE: if you have problems compiling on certain platforms, due to the use
// of errno, then just use preprocessor directives to carve those portions out
// of this function, replacing with a message about the unavailability of errno.
//
//static
void  OTLog::Errno(const char * szLocation/*=NULL*/) // stderr
{   
    const int errnum = errno;
    char buf[128]; buf[0] = '\0';
    
    int nstrerr = 0;
    char * szErrString = NULL;
    
//#if((_POSIX_C_SOURCE >= 200112L || _XOPEN_SOURCE >= 600) && !defined(_GNU_SOURCE))

#if defined(_GNU_SOURCE) && defined(__linux__)
    szErrString = strerror_r(errnum, buf, 127);
#elif (_POSIX_C_SOURCE >= 200112L || _XOPEN_SOURCE >= 600)
    nstrerr = strerror_r(errnum, buf, 127); // (strerror_r is threadsafe version of strerror)
#endif
    
    const char * szFunc = "OTLog::Errno";
    const char * sz_location = (NULL == szLocation) ? "" : szLocation;
    
    if (NULL == szErrString)
        szErrString = buf;
    // ------------------------
    if (0 == nstrerr)
        OTLog::vError("%s %s: errno %d: %s.\n", 
                      szFunc, sz_location,
                      errnum, szErrString[0] != '\0' ? szErrString : "");
    else
        OTLog::vError("%s %s: errno: %d. (Unable to retrieve error string for that number.)\n", 
                      szFunc, sz_location,
                      errnum);
}




// Used for making sure that certain necessary folders actually exist. (Creates them otherwise.)
//
// If you pass in "spent", then this function will make sure that "<path>/spent" actually exists, 
// or create it. WARNING: If what you want to pass is "spent/sub-folder-to-spent" then make SURE
// you call it with "spent" FIRST, so you are sure THAT folder has been created, otherwise the
// folder creation will definitely fail on the sub-folder call (if the primary folder wasn't
// already there, that is.)
//
bool OTLog::ConfirmOrCreateFolder(const char * szFolderName)
{
	OT_ASSERT_MSG(NULL != szFolderName, "OTLog::ConfirmOrCreateFolder: Assert failed: NULL != szFolderName");
	
    OTString strFolderName(szFolderName);
    
	// DIRECTORY IS PRESENT?
	struct stat st;
	
	OTString strRawPath;
    
    if (strFolderName.Compare("."))
        strRawPath.Format("%s", OTLog::Path());
    else
        strRawPath.Format("%s%s%s", OTLog::Path(), OTLog::PathSeparator(), strFolderName.Get());
	
//	OTLog::vError("**** Path: %s  Foldername: %s    Total: %s \n",
//				  OTLog::Path(), szFolderName, strRawPath.Get());
	/*ACTUAL OUTPUT:
	 ****	Path: /Users/au/Library/Application  
			Foldername: nyms
			Total: "/Users/au/Library/Application/nyms" 

	 */
	
    
	OTString strPath;
    OTLog::TransformFilePath(strRawPath.Get(), strPath);
	
    OTLog::vOutput(1, "OTLog::ConfirmOrCreateFolder: Transformed %s into %s \n",
                   strRawPath.Get(), strPath.Get());
    
	bool bDirIsPresent = (0 == stat(strPath.Get(), &st));
	
	// ----------------------------------------------------------------------------
	
	// IF NO, CREATE IT
	if (!bDirIsPresent)
	{
#ifdef _WIN32
		if (_mkdir(strPath.Get()) == -1) 
#else
			if (mkdir(strPath.Get(), 0700) == -1) 
#endif
			{
				OTLog::vError("OTLog::ConfirmOrCreateFolder: Unable to create %s.\n",
							  strPath.Get());
				return false;
			}
		
		// Now we have created it, so let's check again...
		bDirIsPresent = (0 == stat(strPath.Get(), &st));
		
		if (bDirIsPresent)
			OTLog::vOutput(0, "Created folder: %s\n", strPath.Get());
	}
	
	// ----------------------------------------------------------------------------
	
	// At this point if the folder still doesn't exist, nothing we can do. We
	// already tried to create the folder, and SUCCEEDED, and then STILL failed 
	// to find it (if this is still false.)
	if (!bDirIsPresent)
	{
		OTLog::vError("OTLog::ConfirmOrCreateFolder: Unable to find newly-created folder: %s\n", 
					  strPath.Get());
		return false;
	}
	
	return true;
}	

// Returns true or false whether a specific file exists.
// Adds the main path prior to checking.
bool OTLog::ConfirmFile(const char * szFileName)
{
	OT_ASSERT(NULL != szFileName);
	
	OTString strFilename(szFileName);
    
	// FILE IS PRESENT?
	struct stat st;
	
	OTString strRawPath;
    
    if (strFilename.Compare("."))
        strRawPath.Format("%s", OTLog::Path());
    else
        strRawPath.Format("%s%s%s", OTLog::Path(), OTLog::PathSeparator(), szFileName);
	
	OTString strPath;
    OTLog::TransformFilePath(strRawPath.Get(), strPath);

	return (0 == stat(strPath.Get(), &st));
}


// Returns true or false whether a specific file exists.
bool OTLog::ConfirmExactPath(const char * szFileName)
{
	OT_ASSERT(NULL != szFileName);
	
    OTString strFilename(szFileName);
    OT_ASSERT_MSG(!strFilename.Compare("."), "OTLog::ConfirmExactPath: ASSERT: !strFilename.Compare(\".\")\n");
    

	// FILE IS PRESENT?
	struct stat st;
	
	OTString strPath;
    OTLog::TransformFilePath(strFilename.Get(), strPath);
	
	return (0 == stat(strPath.Get(), &st));
}





















































