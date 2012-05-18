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
#include <iostream>


#include <string> // The C++ one 



// Use Win or Posix
// IF I need this while porting, then uncomment it.
#ifdef _WIN32
#include <windows.h>
//#else
//#ifndef POSIX
//#warning POSIX will be used (but you did not define it)
//#endif
//#include <unistd.h>
#endif


extern "C" 
{
	
#ifdef _WIN32
#include <direct.h>
#include <sys/timeb.h>
#else
#include <wordexp.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>
#endif

#include <sys/stat.h>

// -----------------------
#include <openssl/ssl.h>
#include <openssl/err.h>
#include <openssl/evp.h>
#include <openssl/conf.h>
#include <openssl/rand.h>
// -----------------------
}



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


OTString OTLog::__Version = "0.80g";





// ---------------------------------------------------------------------------------
// This is the "global" path to the subdirectories. The wallet file is probably also there.
OTString OTLog::__OTPath("."); // it defaults to '.' but then it is set by the client and server.

// All my paths now use the global path above, and are constructed using
// the path separator below. So the filesystem aspect of Open Transactions
// should be a LOT more portable to Windows, though I haven't actually tried
// it on Windows.
#ifdef _WIN32
OTString OTLog::__OTPathSeparator = "\\";
#else
OTString OTLog::__OTPathSeparator = "/";
#endif

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
OTString OTLog::__OTPaymentInboxFolder		= "paymentInbox";		
OTString OTLog::__OTRecordBoxFolder			= "recordBox";
OTString OTLog::__OTCertFolder				= "certs";		
OTString OTLog::__OTPubkeyFolder			= "pubkeys";
OTString OTLog::__OTContractFolder			= "contracts";
OTString OTLog::__OTMintFolder				= "mints";
OTString OTLog::__OTSpentFolder				= "spent";
OTString OTLog::__OTPurseFolder				= "purse";
OTString OTLog::__OTMarketFolder			= "markets";
OTString OTLog::__OTScriptFolder			= "scripts";
OTString OTLog::__OTSmartContractsFolder	= "smartcontracts";


OTString OTLog::__OTLogfile;

// If Logfile uninitialized, we assume NO logfile, and we log to output.
// Otherwise, we append to the logfile, and leave output clear.

// --------------------------------------------------

dequeOfStrings OTLog::__logDeque; // Stores the last 1024 logs in memory.


// static
// Changes ~/blah to /Users/au/blah
//
void OTLog::TransformFilePath(const char * szInput, OTString & strOutput)
{
    if (NULL == szInput)
        return;
 	
#ifndef _WIN32 // if UNIX (NOT windows)
	wordexp_t exp_result;
	
	if (wordexp(szInput, &exp_result, 0))
	{
		OTLog::Error("OTLog::TransformFilePath: Error calling wordexp() to expand path.\n");
		wordfree(&exp_result); 
		strOutput.Set(szInput);
		return;
	}
	// ----------------------------
	
	std::string str_Output("");
	
	// wordexp tokenizes by space (as well as expands, which is why I'm using it.)
	// Therefore we need to iterate through the tokens, and create a single string
	// with spaces between the tokens.
	//
	for (int i = 0; exp_result.we_wordv[i] != NULL; i++)
	{
		str_Output += exp_result.we_wordv[i];
		
		if (exp_result.we_wordv[i+1] != NULL)
			str_Output += " ";
	}
	
	wordfree(&exp_result); 

	strOutput.Set(str_Output.c_str());    
#else
	strOutput.Set(szInput);
#endif  
}





/*
 #include <openssl/ssl.h>
 void SSL_load_error_strings(void);
 
 #include <openssl/err.h>
 void ERR_free_strings(void);
 //void ERR_load_crypto_strings(void);
 
 
 #include <openssl/ssl.h>
 int SSL_library_init(void);
 //#define OpenSSL_add_ssl_algorithms()    SSL_library_init()
 //#define SSLeay_add_ssl_algorithms()     SSL_library_init()
 
 
 #include <openssl/evp.h>
 void OpenSSL_add_all_algorithms(void);
 //void OpenSSL_add_all_ciphers(void);
 //void OpenSSL_add_all_digests(void);
 void EVP_cleanup(void);
 
 
 #include <openssl/conf.h>
 void OPENSSL_config(const char *config_name);
 //void OPENSSL_no_config(void);
 //Applications should free up configuration at application closedown by calling CONF_modules_free().
 
 #include <openssl/conf.h>
 void CONF_modules_free(void);
 //void CONF_modules_finish(void);
 //void CONF_modules_unload(int all);
 */



// I wanted a global OT_Init function where I could set up OpenSSL,
// load the error strings, etc.  I chose to put it in OTLog for now
// because the header is usually expected in every other file, so it's
// available, and it's in the library, so it's available to BOTH client
// and server from this spot.
//
// -------------------------------------------
//static
void OTLog::OT_Init()
{
    static bool __OT_LowLevel_Initialized = false;
    // -------------------------------------------

    // This way it can only happen once -- the first time.
    //
    if (false == __OT_LowLevel_Initialized)
    {
        __OT_LowLevel_Initialized = true;
        
        OTLog::Output(1, "OT_Init: Setting up rlimits, SSL_library_init, error strings and algorithms, and OpenSSL config...\n");
        
        // *********************************************************************************
        
        // Here is a security measure intended to make it more difficult to capture a core
        // dump. (Not used in debug mode, obviously.)
        //
#if !defined(PREDEF_MODE_DEBUG) && defined(PREDEF_PLATFORM_UNIX)
        struct rlimit rlim;
        getrlimit(RLIMIT_CORE, &rlim);
        rlim.rlim_max = rlim.rlim_cur = 0;
        if (setrlimit(RLIMIT_CORE, &rlim))
        {
            OT_ASSERT_MSG(false, "ASSERT: setrlimit failed. (Used for preventing core dumps.)\n");
        }
#endif
        
        // *********************************************************************************
        /* Todo FYI:
         - One final comment about compiling applications linked to the OpenSSL library.
         - If you don't use the multithreaded DLL runtime library (/MD option) your
         - program will almost certainly crash because malloc gets confused -- the
         - OpenSSL DLLs are statically linked to one version, the application must
         - not use a different one.  You might be able to work around such problems
         - by adding CRYPTO_malloc_init() to your program before any calls to the
         - OpenSSL libraries: This tells the OpenSSL libraries to use the same
         - malloc(), free() and realloc() as the application.  However there are many
         - standard library functions used by OpenSSL that call malloc() internally
         - (e.g. fopen()), and OpenSSL cannot change these; so in general you cannot
         - rely on CRYPTO_malloc_init() solving your problem, and you should
         - consistently use the multithreaded library.
         */
#ifdef _WIN32
		CRYPTO_malloc_init();                           //      # -1
        // FYI: this call appeared in the client version, not the server version.
        // but now it will obviously appear in both, since they both will just call this (OT_Init.)
        // Therefore if any weird errors crop in the server, just be aware. This call might have been
        // specifically for DLLs or something.
#endif
        // *********************************************************************************
        // SSL_library_init() must be called before any other action takes place.
        // SSL_library_init() is not reentrant.
        //
        SSL_library_init();                               //     #0

        // *********************************************************************************
        
        /*
         We all owe a debt of gratitude to the OpenSSL team but fuck is their documentation
         difficult!! In this case I am trying to figure out whether I should call SSL_library_init()
         first, or SSL_load_error_strings() first.
         Docs say:
         
         EXAMPLES   (http://www.openssl.org/docs/ssl/SSL_library_init.html#)
         
         A typical TLS/SSL application will start with the library initialization, 
         and provide readable error messages.
         
            SSL_load_error_strings();               // readable error messages
            SSL_library_init();                      // initialize library
        -----------
         ===> NOTICE it said "START" with library initialization, "AND" provide
              readable error messages... But then what order does it PUT them in?
         
            SSL_load_error_strings();        // readable error messages
            SSL_library_init();              // initialize library
         -------
         
         ON THE SAME PAGE, as if things weren't confusing enough, see THIS:
         
         NOTES
         SSL_library_init() must be called before any other action takes place.
         SSL_library_init() is not reentrant.
         -------------------
         Then, on http://www.openssl.org/docs/crypto/ERR_load_crypto_strings.html#, in
         reference to SSL_load_error_strings and ERR_load_crypto_strings, it says:
         
            One of these functions should be called BEFORE generating textual error messages.
         
         ====>  ?? Huh?? So which should I call first? Ben Laurie, if you are ever googling your
         own name on the Internet, please drop me a line and lemme know:
                fellowtraveler around rayservers cough net
         */
        // ---------------------------------------------
        
        // NOTE: the below sections are numbered #1, #2, #3, etc so that they can be UNROLLED
        // IN THE OPPOSITE ORDER when we get to OT_Cleanup().
        
        // *********************************************************************************
        /*
         - ERR_load_crypto_strings() registers the error strings for all libcrypto functions.
         - SSL_load_error_strings() does the same, but also registers the libssl error strings.
         One of these functions should be called before generating textual error messages.
         - ERR_free_strings() frees all previously loaded error strings.
         */
        SSL_load_error_strings();    // DONE -- corresponds to ERR_free_strings in OT_Cleanup()   #1
//      ERR_load_crypto_strings();   // Redundant -- SSL_load_error_strings does this already.
        // *********************************************************************************
        //
        /*
         OpenSSL keeps an internal table of digest algorithms and ciphers. 
         It uses this table to lookup ciphers via functions such as EVP_get_cipher_byname().
         
         OpenSSL_add_all_algorithms() adds all algorithms to the table (digests and ciphers).
         
         OpenSSL_add_all_digests() adds all digest algorithms to the table.
         OpenSSL_add_all_ciphers() adds all encryption algorithms to the table including password based encryption algorithms.
         // ---------------------
         TODO optimization:
         Calling OpenSSL_add_all_algorithms() links in all algorithms: as a result a statically linked executable
         can be quite large. If this is important it is possible to just add the required ciphers and digests.
         -- Thought: I will probably have different optimization options. Some things will be done no matter what, but
         other things will be compile-flags for optimizing specifically for speed, or size, or use of RAM, or CPU cycles,
         or security options, etc. This is one example of something where I would optimize it out, if possible, when trying
         to conserve RAM.
         Note: However it seems from the docs, that this table needs to be populated anyway due to problems in
         OpenSSL when it's not.
         */
        OpenSSL_add_all_algorithms();   // DONE -- corresponds to EVP_cleanup() in OT_Cleanup().    #2
        //
        // *********************************************************************************
        //
        // RAND
        //
        /*
        RAND_bytes() automatically calls RAND_poll() if it has not already been done at least once.
         So you do not have to call it yourself. RAND_poll() feeds on what the operating system provides: 
         on Linux, Solaris, FreeBSD and similar Unix-like systems, it will use /dev/urandom (or /dev/random 
         if there is no /dev/urandom) to obtain a cryptographically secure initial seed; on Windows, it will
         call CryptGenRandom() for the same effect.
            
            RAND_screen() is provided by OpenSSL only for backward compatibility with (much) older code which
         may call it (that was before OpenSSL used proper OS-based seed initialization).
                
         So the "normal" way of dealing with RAND_poll() and RAND_screen() is to call neither. Just use RAND_bytes() 
         and be happy.
         
         RESPONSE: Thanks for the detailed answer. In regards to your suggestion to call neither, the problem
         under Windows is that RAND_poll can take some time and will block our UI. So we call it upon initialization,
         which works for us. 
        */
        // I guess Windows will seed the PRNG whenever someone tries to get
        // some RAND_bytes() the first time...
        //
//#ifdef _WIN32
        // CORRESPONDS to RAND_cleanup in OT_Cleanup().
//      RAND_screen();
//#else
        // note: optimization: might want to remove this, since supposedly it happens anyway
        // when you use RAND_bytes. So the "lazy evaluation" rule would seem to imply, not bothering
        // to slow things down NOW, since it's not really needed until THEN.
        //
#if defined(USE_RAND_POLL)
            RAND_poll();           //                                   #3
#endif
        // *********************************************************************************

        // OPENSSL_config()                                             #4
        //
        // OPENSSL_config configures OpenSSL using the standard openssl.cnf configuration file name 
        // using config_name. If config_name is NULL then the default name openssl_conf will be used. 
        // Any errors are ignored. Further calls to OPENSSL_config() will have no effect. The configuration
        // file format is documented in the conf(5) manual page.
        //
        OPENSSL_config(NULL); // const char *config_name = NULL: the default name openssl_conf will be used.
        //
        // Corresponds to CONF_modules_free() in OT_Cleanup().
        //
        // *********************************************************************************
        
        
        
        // *********************************************************************************
        //
        // Let's see 'em!
        //
        ERR_print_errors_fp(stderr);
    }

}


// RAND_status() and RAND_event() return 1 if the PRNG has been seeded with enough data, 0 otherwise.


/*
 13. I think I've detected a memory leak, is this a bug?
 
 In most cases the cause of an apparent memory leak is an OpenSSL internal
 table that is allocated when an application starts up. Since such tables do
 not grow in size over time they are harmless.
 
 These internal tables can be freed up when an application closes using
 various functions. Currently these include following:
 
    Thread-local cleanup functions:
 
        ERR_remove_state()
 
 Application-global cleanup functions that are aware of usage (and therefore thread-safe):

        ENGINE_cleanup() and CONF_modules_unload()
 
 "Brutal" (thread-unsafe) Application-global cleanup functions:
        
        ERR_free_strings(), EVP_cleanup() and CRYPTO_cleanup_all_ex_data().
 */
//static
void OTLog::OT_Cleanup()
{
// In the future if we start using ENGINEs, then do the cleanup here:
//#ifndef OPENSSL_NO_ENGINE
//  void ENGINE_cleanup(void);
//#endif
    //
    // ------------------------------------------
            
    /*
     CONF_modules_free()
     
     OpenSSL configuration cleanup function. CONF_modules_free() closes down and frees
     up all memory allocated by all configuration modules.
     Normally applications will only call CONF_modules_free() at application [shutdown]
     to tidy up any configuration performed.
     */
    CONF_modules_free(); // CORRESPONDS to: OPENSSL_config() in OT_Init().   #4
    
    RAND_cleanup();      // Corresponds to RAND_screen / RAND_poll in OT_Init()  #3

	EVP_cleanup();       // DONE (brutal) -- corresponds to OpenSSL_add_all_algorithms in OT_Init(). #2
    // -------------------------------------------------
    
    CRYPTO_cleanup_all_ex_data(); // (brutal)
//	CRYPTO_mem_leaks(bio_err);

    // -------------------------------------------------
    
	ERR_free_strings(); // DONE (brutal) -- corresponds to SSL_load_error_strings in OT_Init().  #1
	
    // ----------------------------------
    // ERR_remove_state - free a thread's error queue "prevents memory leaks..."
    //
    // ERR_remove_state() frees the error queue associated with thread pid. If pid == 0, 
    // the current thread will have its error queue removed.
    //
    // Since error queue data structures are allocated automatically for new threads,
    // they must be freed when threads are terminated in order to avoid memory leaks.
    //
    ERR_remove_state(0);
    
    // NOTE: You must call SSL_shutdown() before you call SSL_free().
    // Update: these are for SSL sockets, they must be called per socket.
    // (IOW: Not needed here for app cleanup.)
}





const char * OTLog::GetMemlogAtIndex(int nIndex)
{
	unsigned int uIndex = static_cast<unsigned int> (nIndex);
	
	if ((uIndex < 0) || (uIndex >= __logDeque.size()))
	{
		OTLog::vError("OTLog::GetMemlogAtIndex: index out of bounds: %d\n", nIndex);
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
	
	// DIRECTORY IS PRESENT?
	struct stat st;
	
	OTString strRawPath;
	strRawPath.Format("%s%s%s", OTLog::Path(), OTLog::PathSeparator(), szFolderName);
	
//	OTLog::vError("**** Path: %s  Foldername: %s    Total: %s \n",
//				  OTLog::Path(), szFolderName, strRawPath.Get());
	/*ACTUAL OUTPUT:
	 ****	Path: /Users/au/Library/Application  
			Foldername: nyms
			Total: "/Users/au/Library/Application/nyms" 

	 */
	
	OTString strPath;
    OTLog::TransformFilePath(strRawPath.Get(), strPath);
	
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
	
	
	// FILE IS PRESENT?
	struct stat st;
	
	OTString strRawPath;
	strRawPath.Format("%s%s%s", OTLog::Path(), OTLog::PathSeparator(), szFileName);
	
	OTString strPath;
    OTLog::TransformFilePath(strRawPath.Get(), strPath);

	return (0 == stat(strPath.Get(), &st));
}


// Returns true or false whether a specific file exists.
bool OTLog::ConfirmExactPath(const char * szFileName)
{
	OT_ASSERT(NULL != szFileName);
	
	// FILE IS PRESENT?
	struct stat st;
	
	OTString strPath;
    OTLog::TransformFilePath(szFileName, strPath);
	
	return (0 == stat(strPath.Get(), &st));
}





















































