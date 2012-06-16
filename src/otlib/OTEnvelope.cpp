/*****************************************************************
 *    
 *  OTEnvelope.cpp
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

#include <string>

#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <algorithm>

#ifdef _WIN32
#include <WinsockWrapper.h>
#endif

extern "C"
{
// -----------------------
#include <openssl/crypto.h>
#include <openssl/evp.h>
#include <openssl/pem.h>
#include <openssl/rsa.h>
#include <openssl/err.h>
#include <openssl/rand.h>
#include <openssl/ssl.h>
#include <openssl/conf.h>
 
#ifndef OPENSSL_THREAD_DEFINES
#define OPENSSL_THREAD_DEFINES
#include <openssl/opensslconf.h>
#endif
    
#include <openssl/opensslv.h>
// -----------------------

#ifdef _WIN32
//#include <WinSock.h>
#include <sys/timeb.h>

#else
#include <arpa/inet.h>          // For htonl()
#include <unistd.h>
#include <sys/types.h>
#include <sys/time.h>           // 
#include <sys/resource.h>
#endif
}

#include "stacktrace.h"

// ----------------------------

// TinyThread++
//
#include "tinythread.h"   // These are in the header already.
//#include "fast_mutex.h"

using namespace tthread;

// ----------------------------


#include "OTStorage.h"

#include "OTEnvelope.h"

#include "OTAsymmetricKey.h"
#include "OTASCIIArmor.h"
#include "OTPseudonym.h"
#include "OTLog.h"

// ------------------------------------------------------------------------














// ------------------------------------------------------------------------

// class OTCrypto
//
// To someday get us to the point where we can easily swap crypto libs.
// For now, just for static init / cleanup functions we can call from 
// OTLog Init/Cleanup, and move the more "crypto" related stuff to this file.
//

//static
int OTCrypto::s_nCount = 0;   // Instance count, should never exceed 1. (At this point, anyway.)


// -----------------------------


OTCrypto::OTCrypto()
{
    
}

OTCrypto::~OTCrypto()
{
    
}
    
// -----------------------------

//static
OTCrypto * OTCrypto::It()
{
    // Todo: someday, swapping the crypto lib should be as easy as changing this
    // compile flag to OT_CRYPTO_USING_GPG. We'll get there.
    //
static
#ifdef OT_CRYPTO_USING_OPENSSL
    OTCrypto_OpenSSL
#endif
    s_theSingleton;    // For now we're only allowing a single instance.
    
    return &s_theSingleton;
}

// -----------------------------

// Currently called by OTLog::OT_Init();

void OTCrypto::Init()
{
    // This is only supposed to happen once per run.
    //
    if (0 == OTCrypto::s_nCount)
    {
        ++(OTCrypto::s_nCount);        
        // -----------------------------
        
        OTLog::Output(1, "OT_Init: Setting up rlimits, and crypto library...\n");

        // Here is a security measure intended to make it more difficult to capture a core
        // dump. (Not used in debug mode, obviously.)
        //
#if !defined(PREDEF_MODE_DEBUG) && defined(PREDEF_PLATFORM_UNIX)
        struct rlimit rlim;
        getrlimit(RLIMIT_CORE, &rlim);
        rlim.rlim_max = rlim.rlim_cur = 0;
        if (setrlimit(RLIMIT_CORE, &rlim))
        {
            OT_ASSERT_MSG(false, "OTCrypto::Init: ASSERT: setrlimit failed. (Used for preventing core dumps.)\n");
        }
#endif
        
        // -----------------------------
        this->Init_Override();
    }
    else
        OTLog::Error("OTCrypto::Init: ERROR: Somehow this erroneously got called more than once! (Doing nothing.)\n");
}
// -----------------------------

// Currently called by OTLog::OT_Cleanup();

void OTCrypto::Cleanup()
{
    // This is only supposed to happen once per run.
    //
    if (1 == OTCrypto::s_nCount)
    {
        --(OTCrypto::s_nCount);
        // -----------------------------
        
        // Any crypto-related cleanup code NOT specific to OpenSSL (which is
        // handled in OTCrypto_OpenSSL, a subclass) would go here. 
        //
        
        // -----------------------------
        this->Cleanup_Override();
    }
    else
        OTLog::Error("OTCrypto::Cleanup: ERROR: Somehow this erroneously got called more than once! (Doing nothing.)\n");
}

// -----------------------------

//virtual (Should never get called.)
void OTCrypto::Init_Override()
{
    OTLog::Error("OTCrypto::Init_Override: ERROR: This function should NEVER be called (you should be overriding it...)\n");
}

// -----------------------------

//virtual (Should never get called.)
void OTCrypto::Cleanup_Override()
{
    OTLog::Error("OTCrypto::Cleanup_Override: ERROR: This function should NEVER be called (you should be overriding it...)\n");
}


// ********************************************************************************


// Someday: OTCryptoGPG    }:-)
//
OTCrypto_OpenSSL::OTCrypto_OpenSSL() : OTCrypto()
{
    
}

OTCrypto_OpenSSL::~OTCrypto_OpenSSL()
{
    
}

// -----------------------------

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

// *********************************************************************************


/*
#include <openssl/crypto.h>

/ Don't use this structure directly.
typedef struct crypto_threadid_st
        {
        void *ptr;
        unsigned long val;
        } CRYPTO_THREADID;
 
// Only use CRYPTO_THREADID_set_[numeric|pointer]() within callbacks
void CRYPTO_THREADID_set_numeric(CRYPTO_THREADID *id, unsigned long val);
void CRYPTO_THREADID_set_pointer(CRYPTO_THREADID *id, void *ptr);
 
int CRYPTO_THREADID_set_callback(void (*threadid_func)(CRYPTO_THREADID *));

void (*CRYPTO_THREADID_get_callback(void))(CRYPTO_THREADID *);
 
void CRYPTO_THREADID_current(CRYPTO_THREADID *id);
 
int CRYPTO_THREADID_cmp(const CRYPTO_THREADID *a,
                        const CRYPTO_THREADID *b);
void CRYPTO_THREADID_cpy(CRYPTO_THREADID *dest,
                         const CRYPTO_THREADID *src);

 unsigned long CRYPTO_THREADID_hash(const CRYPTO_THREADID *id);

int CRYPTO_num_locks(void);

 Description
 
 
 OpenSSL can safely be used in multi-threaded applications provided that at least two callback functions are set, 
 locking_function and threadid_func.
 
 locking_function(int mode, int n, const char *file, int line) is needed to perform locking on shared data structures. 
 (Note that OpenSSL uses a number of global data structures that will be implicitly shared whenever multiple threads 
 use OpenSSL.) Multi-threaded applications will crash at random if it is not set.
 
 locking_function() must be able to handle up to CRYPTO_num_locks() different mutex locks. It sets the n-th lock if 
 mode & CRYPTO_LOCK , and releases it otherwise.
 
 file and line are the file number of the function setting the lock. They can be useful for debugging.
 
 threadid_func( CRYPTO_THREADID *id) is needed to record the currently-executing thread's identifier into id. The
 implementation of this callback should not fill in id directly, but should use CRYPTO_THREADID_set_numeric() if 
 thread IDs are numeric, or CRYPTO_THREADID_set_pointer() if they are pointer-based. If the application does not 
 register such a callback using CRYPTO_THREADID_set_callback(), then a default implementation is used - on Windows 
 and BeOS this uses the system's default thread identifying APIs, and on all other platforms it uses the address 
 of errno. The latter is satisfactory for thread-safety if and only if the platform has a thread-local error number
 facility.
 */


/*
 
// struct CRYPTO_dynlock_value needs to be defined by the user
struct CRYPTO_dynlock_value;

void CRYPTO_set_dynlock_create_callback(struct CRYPTO_dynlock_value *
       (*dyn_create_function)(char *file, int line));
void CRYPTO_set_dynlock_lock_callback(void (*dyn_lock_function)
       (int mode, struct CRYPTO_dynlock_value *l,
       const char *file, int line));
void CRYPTO_set_dynlock_destroy_callback(void (*dyn_destroy_function)
       (struct CRYPTO_dynlock_value *l, const char *file, int line));

int CRYPTO_get_new_dynlockid(void);

void CRYPTO_destroy_dynlockid(int i);

void CRYPTO_lock(int mode, int n, const char *file, int line);

#define CRYPTO_w_lock(type)    \
       CRYPTO_lock(CRYPTO_LOCK|CRYPTO_WRITE,type,__FILE__,__LINE__)
#define CRYPTO_w_unlock(type)  \
       CRYPTO_lock(CRYPTO_UNLOCK|CRYPTO_WRITE,type,__FILE__,__LINE__)
#define CRYPTO_r_lock(type)    \
       CRYPTO_lock(CRYPTO_LOCK|CRYPTO_READ,type,__FILE__,__LINE__)
#define CRYPTO_r_unlock(type)  \
       CRYPTO_lock(CRYPTO_UNLOCK|CRYPTO_READ,type,__FILE__,__LINE__)
#define CRYPTO_add(addr,amount,type)   \
       CRYPTO_add_lock(addr,amount,type,__FILE__,__LINE__)
 
 */


tthread::mutex * OTCrypto_OpenSSL::s_arrayMutex = NULL;


// *********************************************************************************

extern "C"
{    
#if OPENSSL_VERSION_NUMBER-0 < 0x10000000L
    unsigned
    long  ot_openssl_thread_id(void);
#else
    void  ot_openssl_thread_id(CRYPTO_THREADID *);
#endif
    // ---------------------------------
    void  ot_openssl_locking_callback( int mode, int type, char *file, int line);
}


// done
/*
 threadid_func( CRYPTO_THREADID *id) is needed to record the currently-executing thread's identifier into id. 
 The implementation of this callback should not fill in id directly, but should use CRYPTO_THREADID_set_numeric() 
 if thread IDs are numeric, or CRYPTO_THREADID_set_pointer() if they are pointer-based. If the application does 
 not register such a callback using CRYPTO_THREADID_set_callback(), then a default implementation is used - on 
 Windows and BeOS this uses the system's default thread identifying APIs, and on all other platforms it uses the 
 address of errno. The latter is satisfactory for thread-safety if and only if the platform has a thread-local
 error number facility.
 
 */

// *********************************************************************************

#if OPENSSL_VERSION_NUMBER-0 < 0x10000000L
unsigned long ot_openssl_thread_id()
{
	unsigned long ret = this_thread::get_raw_id();
    
	return (ret);
}

#else
void ot_openssl_thread_id(CRYPTO_THREADID * id)
{
    OT_ASSERT(NULL != id);
    
    // TODO: Possibly do this by pointer instead of by unsigned long,
    // for certain platforms. (OpenSSL provides functions for both.)
    //
    
    unsigned long val = this_thread::get_raw_id();

//    void CRYPTO_THREADID_set_numeric(CRYPTO_THREADID *id, unsigned long val);
//    void CRYPTO_THREADID_set_pointer(CRYPTO_THREADID *id, void *ptr);
    
           CRYPTO_THREADID_set_numeric(id, val);
}
#endif

// *********************************************************************************


/*
 locking_function(int mode, int n, const char *file, int line) is needed to perform locking on
 shared data structures. (Note that OpenSSL uses a number of global data structures that will
 be implicitly shared whenever multiple threads use OpenSSL.) Multi-threaded applications will
 crash at random if it is not set.
 
 locking_function() must be able to handle up to CRYPTO_num_locks() different mutex locks. It
 sets the n-th lock if mode & CRYPTO_LOCK , and releases it otherwise.
 
 file and line are the file number of the function setting the lock. They can be useful for
 debugging.
 */

void ot_openssl_locking_callback(int mode, int type, const char *file, int line)
{
	if (mode & CRYPTO_LOCK)
    {
		OTCrypto_OpenSSL::s_arrayMutex[type].lock();
    }
	else
    {
		OTCrypto_OpenSSL::s_arrayMutex[type].unlock();
    }
}

// *********************************************************************************


// done

void OTCrypto_OpenSSL::thread_setup()
{
    OTCrypto_OpenSSL::s_arrayMutex = new tthread::mutex[CRYPTO_num_locks()];
    
    // ---------------------------------------
    
    // NOTE: OpenSSL supposedly has some default implementation for the thread_id, 
    // so we're going to NOT set that callback here, and see what happens.
    //
    // UPDATE: Looks like this works "if and only if the local system provides errno"
    // and since I already have a supposedly-reliable ID from tinythread++, I'm going
    // to just use that one for now and see how it works.
    //
#if OPENSSL_VERSION_NUMBER-0 < 0x10000000L    
    CRYPTO_set_id_callback       (ot_openssl_thread_id);
#else
    int nResult = 
    CRYPTO_THREADID_set_callback (ot_openssl_thread_id);
    ++nResult; --nResult;
#endif
    // ---------------------------------------
    
    // Here we set the locking callback function, which is the same for all versions
    // of OpenSSL. (Unlike thread_id function above.)
    //
	CRYPTO_set_locking_callback (ot_openssl_locking_callback);

}
// *********************************************************************************

// done

void OTCrypto_OpenSSL::thread_cleanup()
{
	CRYPTO_set_locking_callback(NULL);
    
    if (NULL != OTCrypto_OpenSSL::s_arrayMutex)
    {
        delete [] OTCrypto_OpenSSL::s_arrayMutex;
    }

    OTCrypto_OpenSSL::s_arrayMutex = NULL;
}


// *********************************************************************************


void OTCrypto_OpenSSL::Init_Override()
{
    const char * szFunc = "OTCrypto_OpenSSL::Init_Override";
    
    OTLog::vOutput(1, "%s: Setting up OpenSSL:  SSL_library_init, error strings and algorithms, and OpenSSL config...\n", 
                   szFunc);

    /*
     OPENSSL_VERSION_NUMBER is a numeric release version identifier:
     
     MMNNFFPPS: major minor fix patch status
     The status nibble has one of the values 0 for development, 1 to e for betas 1 to 14, and f for release.
     
     for example
     
     0x000906000 == 0.9.6 dev
     0x000906023 == 0.9.6b beta 3
     0x00090605f == 0.9.6e release
     Versions prior to 0.9.3 have identifiers < 0x0930. Versions between 0.9.3 and 0.9.5 had a version identifier with this interpretation:
     
     MMNNFFRBB major minor fix final beta/patch
     for example
     
     0x000904100 == 0.9.4 release
     0x000905000 == 0.9.5 dev
     Version 0.9.5a had an interim interpretation that is like the current one, except the patch level got the highest bit set, to keep continuity. The number was therefore 0x0090581f.
     
     For backward compatibility, SSLEAY_VERSION_NUMBER is also defined.
     
     */
#if !defined(OPENSSL_VERSION_NUMBER) || OPENSSL_VERSION_NUMBER-0 < 0x10000000L    
    OT_ASSERT_MSG(false, "ASSERT: Must use OpenSSL version 1.0.0 or higher.\n");
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
    
//  ERR_load_crypto_strings();   // Redundant -- SSL_load_error_strings does this already.
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
    
    /*
    Try to activate OpenSSL debug memory procedure:
        BIO *pbio - BIO_new(BIO_s_file());
        BIO_set_fp(out,stdout,BIO_NOCLOSE);
        CRYPTO_malloc_debug_init();
        MemCheck_start();
        MemCheck_on();
    
        .
        .
        .
        MemCheck_off()
        MemCheck_stop()
        CRYPTO_mem_leaks(pbio);
    
     This will print out to stdout all memory that has been not deallocated.
     
     Put starting part before everything ( even before OpenSSL_add_all_algorithms() call) 
     this way you will see everything.
     
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
    
    RAND_poll();                                //                                   #3
    
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
    //
    // *********************************************************************************
    //
    //
    // THREADS
    //
    //
// -------------------------------------------------
#if defined(OPENSSL_THREADS)
    // thread support enabled
    
    OTLog::vOutput(1, "%s: OpenSSL WAS compiled with thread support, FYI. Setting up mutexes...\n",
                   szFunc);
    
    this->thread_setup();
    
#else
    // no thread support
    
    OTLog::vError("%s: WARNING: OpenSSL was NOT compiled with thread support. "
                 "(Also: Master Key will not expire.)\n", szFunc);
    
#endif
// -------------------------------------------------
    

    
}




//
// *********************************************************************************




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

//
// *********************************************************************************




void OTCrypto_OpenSSL::Cleanup_Override()
{
    const char * szFunc = "OTCrypto_OpenSSL::Cleanup_Override";
    
    OTLog::vOutput(4, "%s: Cleaning up OpenSSL...\n", szFunc);

// In the future if we start using ENGINEs, then do the cleanup here:
//#ifndef OPENSSL_NO_ENGINE
//  void ENGINE_cleanup(void);
//#endif
//
    
// -------------------------------------------------
#if defined(OPENSSL_THREADS)
    // thread support enabled
    
    this->thread_cleanup();
    
#else
    // no thread support
    
    
#endif
// -------------------------------------------------
    

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
//  ERR_remove_state(0);
    ERR_remove_thread_state(NULL);
    
    /*
    +     Note that ERR_remove_state() is now deprecated, because it is tied
    +     to the assumption that thread IDs are numeric.  ERR_remove_state(0)
    +     to free the current thread's error state should be replaced by
    +     ERR_remove_thread_state(NULL).
    */

    
    // NOTE: You must call SSL_shutdown() before you call SSL_free().
    // Update: these are for SSL sockets, they must be called per socket.
    // (IOW: Not needed here for app cleanup.)
}




// *********************************************************************************








// ------------------------------------------------------------------------








// ------------------------------------------------------------------------








/* 
 
 DERIVING KEYS FROM A PASSWORD
 
 #include <evp.h>
 #include <openssl/rand.h>
 
 char * passwd = "secret password";
 
 unsigned char salt[8];
 
 int iter = 65535;
 
 unsigned char key[16];
 
 RAND_bytes(salt, sizeof(salt));
 
 // From OTPassword.h:
 // size_t strnlen(const char *s, size_t max) 

 PKCS5_PBKDF2_HMAC_SHA1(passwd, strnlen(passwd, BIGGEST_POSSIBLE_PWD), salt, sizeof(salt), iter, sizeof(key), key);
 
 AES_KEY aes_key;
 AES_set_encrypt_key(key, 128, aes_key);
 
 
 // perform aes encryption here...
 
 unsigned char iv[16];
 RAND_bytes(iv,   sizeof(iv));

 
 -----------------------------------------------------------

 DEALING WITH SALT:
 
 // Note: Salt is generated randomly when the symmetric key is created from the passphrase.
 // Then the salt must be STORED with the symmetric key, so that the passphrase / salt / encrypted symmetric key
 // can later be used to produce a decrypted symmetric key (which should not stay in memory for long...)
 //
 
int main()
{
	char *pass = "password";
	char *salt = "12340000";
	int ic = 1;
	unsigned char buf[1024];

	ic = 1;
	PKCS5_PBKDF2_HMAC_SHA1(pass, strlen(pass), (unsigned char*)salt, strlen(salt), ic, 32+16, buf);
	printf("PKCS5_PBKDF2_HMAC_SHA1(\"%s\", \"%s\", %d)=\n", pass, salt, ic);
	print_hex(buf, 32+16);

 // NOTE: The above function is used INSTEAD of the one below!
 
    ic = 1;
	EVP_BytesToKey(EVP_aes_256_cbc(), EVP_sha1(), (unsigned char*)salt, (unsigned char*)pass, strlen(pass), ic, buf, buf+32);
	printf("EVP_BytesToKey(\"%s\", \"%s\", %d)=\n", pass, salt, ic);
	print_hex(buf, 32+16);

	return(0);
}
 
 

 
 
 int EVP_BytesToKey(const EVP_CIPHER *type,const EVP_MD *md,
                    const unsigned char *salt,
                    const unsigned char *data, int datal,
                    int count,
                    unsigned char *key,unsigned char *iv);
 
 EVP_BytesToKey() derives a key and IV from various parameters. 
    type is the cipher to derive the key and IV for.
    md is the message digest to use. 
    The salt paramter is used as a salt in the derivation: it should point to an 8 byte buffer or NULL if no salt is used. 
    data is a buffer containing datal bytes which is used to derive the keying data. 
    count is the iteration count to use. 
 The derived key and IV will be written to key and iv respectively.
 -----------------------------------------------------------
 
 
 
 The initialization vector needs to be known to Alice AND Bob.
   And it needs to be transmitted at the time the session key is negotiated.
 
 So there should probably be a "OTEnvelope" class which stores the IV
 as well as the session key, and which can be encrypted with a public key 
 and decrypted with a private key. The keys can just be passed in or whatever. 
 
 
int PKCS5_PBKDF2_HMAC_SHA1	(
    const void * 	password,
    size_t          password_len,
    const void * 	salt,
    size_t          salt_len,
    unsigned long 	iter,
    size_t          keylen,
    void *          key 
)	
 
 
 OPENSSL's version:
 
 int PKCS5_PBKDF2_HMAC_SHA1(
    const char *pass, int passlen,
    const unsigned char *salt, int saltlen,
    int iter,
    int keylen,  unsigned char *out);

 */


bool OTMasterKey::IsGenerated()
{
    tthread::lock_guard<tthread::mutex> lock(m_Mutex);
    // ----------------------------
    
    bool bReturnVal = false;

    if (NULL != m_pSymmetricKey)
    {
        bReturnVal = m_pSymmetricKey->IsGenerated();
    }
    
    return bReturnVal;
}


//static
OTMasterKey * OTMasterKey::It()
{
    // For now we're only allowing a single instance.
    //
    static OTMasterKey s_theSingleton;  // Default is 0 ("you have to type your PW a million times"), but it's overridden in config file.

    return &s_theSingleton;
}


OTMasterKey::OTMasterKey(int nTimeoutSeconds/*=OT_MASTER_KEY_TIMEOUT*/) :
    m_pThread(NULL),
    m_nTimeoutSeconds(nTimeoutSeconds), 
    m_pMasterPassword(NULL), // This is created in GetMasterPassword, and destroyed by a timer thread sometime soon after.   
    m_pSymmetricKey(NULL),   // OTServer OR OTWallet owns this key, and sets this pointer. It's the encrypted form of s_pMasterPassword.
    m_bPaused(false)
{

}

// We don't lock the mutex here because otherwise we'll freeze ourselves.
//
bool OTMasterKey::isPaused()
{
    return m_bPaused;
}


// When the master key is on pause, it won't work (Nyms will just use their
// own passwords instead of the master password.) This is important, for example,
// if you are loading up a bunch of Old Nyms. You pause before and after each one,
// and THEN convert them to the master key.
//
bool OTMasterKey::Pause()
{
    tthread::lock_guard<tthread::mutex> lock(m_Mutex);
    // ----------------------------

    if (!m_bPaused)
    {
        m_bPaused = true;
        return true;
    }
    return false;
}

bool OTMasterKey::Unpause()
{
    tthread::lock_guard<tthread::mutex> lock(m_Mutex);
    // ----------------------------

    if (m_bPaused)
    {
        m_bPaused = false;
        return true;
    }
    return false;
}


// This should ONLY be called from a function that locks the Mutex first!
//
void OTMasterKey::LowLevelReleaseThread()
{ 
    // NO NEED TO LOCK THIS ONE -- BUT ONLY CALL IT FROM A LOCKED FUNCTION.
    if (NULL != m_pThread)
    {
        if (m_pThread->joinable())
        {
            m_pThread->detach();
        }
        delete m_pThread;
        m_pThread = NULL;
    }
}


OTMasterKey::~OTMasterKey()
{
    tthread::lock_guard<tthread::mutex> lock(m_Mutex);  // I figured this would cause some kind of problem but how else can I mess with the members unless I lock this?
    // --------------------
    LowLevelReleaseThread();
    // -----
    if (NULL != m_pMasterPassword)  // Only stored temporarily, the purpose of this class is to destoy it after a timer.
    {
        delete m_pMasterPassword;
        m_pMasterPassword = NULL;
    }
    // -----
    if (NULL != m_pSymmetricKey)       // Owned / based on a string passed in. Stored somewhere else (OTServer, OTWallet...)
        delete m_pSymmetricKey;
    m_pSymmetricKey = NULL;
    // -----
}


int OTMasterKey::GetTimeoutSeconds()
{
    tthread::lock_guard<tthread::mutex> lock(m_Mutex); // Multiple threads can't get inside here at the same time.

    const int nTimeout = m_nTimeoutSeconds;
    
    return nTimeout;
}

void OTMasterKey::SetTimeoutSeconds(int nTimeoutSeconds) // So we can load from the config file.
{
    tthread::lock_guard<tthread::mutex> lock(m_Mutex); // Multiple threads can't get inside here at the same time.

    OT_ASSERT_MSG(nTimeoutSeconds >= (-1), "OTMasterKey::SetTimeoutSeconds: ASSERT: nTimeoutSeconds must be >= (-1)\n");
    
    m_nTimeoutSeconds = nTimeoutSeconds;
}



// ------------------------------------------------------------------------


bool OTMasterKey::SerializeTo(OTASCIIArmor & ascOutput)
{
    tthread::lock_guard<tthread::mutex> lock(m_Mutex);
    
    if (NULL == m_pSymmetricKey)
        return false;
    
    return m_pSymmetricKey->SerializeTo(ascOutput);
}

bool OTMasterKey::SerializeFrom(const OTASCIIArmor & ascInput)
{
    tthread::lock_guard<tthread::mutex> lock(m_Mutex);
    
    if (NULL == m_pSymmetricKey)
        return false;

    return m_pSymmetricKey->SerializeFrom(ascInput);
}


// ------------------------------------------------------------------------


/*
class OTMasterKey
{
private:
    tthread::thread * m_pThread;         // The thread used for destroying the password after the timeout period.
    int               m_nTimeoutSeconds; // The master password will be stored internally for X seconds, and then destroyed.
    OTPassword     *  m_pMasterPassword; // Created when password is passed in; destroyed by Timer after X seconds.
    OTSymmetricKey *  m_pSymmetricKey;      // Serialized by OTWallet or OTServer. Here for reference only.

public:
    tthread::mutex    m_Mutex;           // Mutex used for serializing access to this instance.

    OTMasterKey(int nTimeoutSeconds=OT_MASTER_KEY_TIMEOUT);
    ~OTMasterKey();

    // These two functions are used by the OTServer or OTWallet that actually keeps
    // the master key. The owner sets the master key pointer on initialization, and then
    // later when the password callback code in OTAsymmetricKey needs to access the master
    // key, it can use OTSymmetricKey::GetMasterKey to access it.
    //
    void SetMasterKey(const OTString & strMasterKey); // OTServer/OTWallet calls this, I instantiate.
    
    int  GetTimeoutSeconds(); 
    void SetTimeoutSeconds(int nTimeoutSeconds); // So we can load from the config file.
    
    bool GetMasterPassword(OTPassword & theOutput);  // The password callback uses this to get the password for any individual Nym.
    void DestroyMasterPassword(); // The thread, when the time comes, calls this method using the instance pointer that was passed into the thread originally. 

    // The cleartext version (m_pMasterPassword) is deleted and set NULL after a Timer of X seconds. (Timer thread calls this.)
    // The INSTANCE that owns the thread also passes a pointer to ITSELF.
    // (So we can access password, mutex, timeout value, etc.) This function calls DestroyMasterPassword.
    //
    static void ThreadTimeout(void * pArg); 
};
*/


// Called by OTServer or OTWallet, or whatever instantiates those.
//
void OTMasterKey::SetMasterKey(const OTASCIIArmor & ascMasterKey)
{
    tthread::lock_guard<tthread::mutex> lock(m_Mutex); // Multiple threads can't get inside here at the same time.    

    OT_ASSERT(ascMasterKey.Exists());    
    // ----------------------------------------
    
    if (NULL != m_pSymmetricKey)
    {
        OTLog::Error("OTMasterKey::SetMasterKey: Warning: This was already set. (Re-setting.)\n");
        delete m_pSymmetricKey;
        m_pSymmetricKey = NULL;
    }
    // -----------------------------------------
    m_pSymmetricKey = new OTSymmetricKey;
    OT_ASSERT(NULL != m_pSymmetricKey);
    // ----------------------------------
    
    //const bool bSerialized = 
        m_pSymmetricKey->SerializeFrom(ascMasterKey);
}


// Called by the password callback function.
// The password callback uses this to get the password for any individual Nym.
// This will also generate the master password, if one does not already exist.
//
bool OTMasterKey::GetMasterPassword(OTPassword & theOutput, const char * szDisplay, bool bVerifyTwice/*=false*/)
{
    tthread::lock_guard<tthread::mutex> lock(m_Mutex); // Multiple threads can't get inside here at the same time.
    
    const char * szFunc = "OTMasterKey::GetMasterPassword";
    
//  OT_ASSERT(NULL != m_pSymmetricKey); // (This had better be set already.) // Took this out because calling Generate inside here now.
    // ----------------------------------------
    //
    if (NULL != m_pMasterPassword)
    {
        OTLog::vOutput(2, "%s: Master password was available. (Returning it now.)\n", szFunc);
        
        theOutput = *m_pMasterPassword;
        return true;
    }
    // --------------------------------------------

    OTLog::vOutput(2, "%s: Master password wasn't loaded. Instantiating...\n", szFunc);

    // If m_pMasterPassword is NULL, (which below this point it is) then...
    //
    // Either it hasn't been created yet, in which case we need to instantiate it,
    // OR it expired, in which case m_pMasterPassword is NULL,
    // but m_pThread isn't, and still needs cleaning up before we instantiate another one!
    //
    LowLevelReleaseThread();
    
    unsigned char temp_memory[OT_DEFAULT_SYMMETRIC_KEY_SIZE]; // (This insures we create it in binary/memory mode instead of text mode.)
    m_pMasterPassword = new OTPassword(static_cast<void *>(&temp_memory[0]), OT_DEFAULT_SYMMETRIC_KEY_SIZE);
    OT_ASSERT(NULL != m_pMasterPassword);    
    
    /*
     How does this work?
     
     When trying to open a normal nym, the password callback realizes we are calling it 
     in "NOT master mode", so instead of just collecting the passphrase and giving it
     back to OpenSSL, it calls this function first, which returns the master password
     (so that IT can be given to OpenSSL instead.)
     
     If the master wasn't already loaded (common) then we call the callback here. Notice
     it's recursive! This time, the callback sees we ARE in master mode, so it doesn't
     call this function (which would be an infinite loop.) Instead, it collects the password
     as normal, only instead of passing it back to the caller via the buffer, it uses the
     passUserInput by attaching it to thePWData before the call. That way the callback function
     can set passUserInput with whatever it retrieved from the user, and then back in this function
     we can get the passUserInput and use it to unlock the MASTER passphrase, which we set
     onto theOutput.
     
     When this function returns true, the callback (0th level of recursion) uses theOutput
     as the "passphrase" for all Nyms, passing it to OpenSSL.
     
     This way, OpenSSL gets a random key instead of a passphrase, and the passphrase is just used
     for encrypting that random key whenever its timer has run out.
     
     */
    
    bool bReturnVal = false;
    
    // CALL the callback directly. (To retrieve a passphrase so I can use it in GenerateKey
    // and GetRawKey.
    //
    //int OT_OPENSSL_CALLBACK (char *buf, int size, int rwflag, void *userdata);
    //
    // For us, it will set passUserInput to the password from the user, and return
    // a simple 1 or 0 (instead of the length.) buf and size can be NULL / 0, and
    // rwflag should be passed in from somewhere.
    //
    
    if (NULL == m_pSymmetricKey)
    {
        m_pSymmetricKey = new OTSymmetricKey;
        OT_ASSERT(NULL != m_pSymmetricKey);        
    }
    
    if (false == m_pSymmetricKey->IsGenerated())
    {
        OTLog::vOutput(2, "%s: Master key didn't exist. Need to collect a password from the user, "
                       "so we can generate a master key...\n ", szFunc);

        bVerifyTwice = true; // we force it, in this case.
    }
    
//  OTLog::vOutput(2, "*********Begin OTMasterKey::GetMasterPassword: Calling souped-up password cb...\n * *  * *  * *  * *  * ");
    
    OTPassword      passUserInput; // text mode.
    OTPasswordData  thePWData(szDisplay, &passUserInput); // this pointer is only passed in the case where it's for the master key.
    
    const int nCallback = souped_up_pass_cb(NULL,  //passUserInput.getPasswordWritable(),
                                            0,     //passUserInput.getBlockSize(),
                                            bVerifyTwice ? 1 : 0, static_cast<void *>(&thePWData));

//  OTLog::vOutput(2, "*********End OTMasterKey::GetMasterPassword: FINISHED CALLING souped-up password cb. Result: %s ------\n",
//                 (nCallback > 0) ? "success" : "failure");

    if (nCallback > 0) // Success retrieving the passphrase from the user. (Now let's see if the key is good, or generate it...)
    {
        // It's possible this is the first time this is happening, and the master key 
        // hasn't evem been generated yet. In which case, we generate it here...
        //
        bool bGenerated = m_pSymmetricKey->IsGenerated();
        
        if (false == bGenerated)
        {
            OTLog::vOutput(3, "%s: Calling m_pSymmetricKey->GenerateKey()...\n", szFunc);
            bGenerated = m_pSymmetricKey->GenerateKey(passUserInput);
//          OTLog::vOutput(0, "%s: Finished calling m_pSymmetricKey->GenerateKey()...\n", szFunc);
        }
        
        if (bGenerated)
        {
            OTLog::vOutput(3, "%s: Calling m_pSymmetricKey->GetRawKey()...\n", szFunc);

            // Once we have the user's password, then we use it to GetKey from the OTSymmetricKey (which
            // is encrypted) and that retrieves the cleartext master password which we set here and also
            // return a copy of.
            //
            const bool bMasterKey = m_pSymmetricKey->GetRawKey(passUserInput, *m_pMasterPassword);
            
            if (bMasterKey)
            {
//              OTLog::vOutput(0, "%s: Finished calling m_pSymmetricKey->GetRawKey (Success.)\n", szFunc);
                theOutput  = *m_pMasterPassword;
                bReturnVal = true;
            }
            else
                OTLog::vOutput(0, "%s: m_pSymmetricKey->GetRawKey() failed.\n", szFunc);
        }
    }
    // -------------------------------------------
    
    if (bReturnVal) // Start the thread!
    {
//      OTLog::vOutput(4, "%s: starting up new thread, so we can expire the master key from RAM.\n", szFunc);

// -------------------------------------------------
#if defined(OPENSSL_THREADS)
        // thread support enabled
        
        OTLog::vOutput(1, "%s: Starting thread for Master Key...\n", szFunc);
        
        m_pThread = new thread(OTMasterKey::ThreadTimeout, static_cast<void *>(this));
        
#else
        // no thread support
        
        OTLog::vError("%s: WARNING: OpenSSL was NOT compiled with thread support. "
                      "(Master Key will not expire.)\n", szFunc);
        
#endif
// -------------------------------------------------

    }
    else if (m_nTimeoutSeconds != (-1))
    {
        if (NULL != m_pMasterPassword)
            delete m_pMasterPassword;
        m_pMasterPassword = NULL;
    }
    // Since we have set the cleartext master password, We also have to fire up the thread
    // so it can timeout and be destroyed. In the meantime, it'll be stored in an OTPassword
    // which has these security precautions:
    /*
       1. Zeros memory in a secure and cross-platform way, in its destructor.
       2. OT_Init() uses setrlimit to prevent core dumps.
       3. Uses VirtualLock and mlock to reduce/prevent swapping RAM to hard drive.
       4. (SOON) will use VirtualProtect on Windows (standard API for protected memory)
       5. (SOON) and similarly have option in config file for ssh-agent, gpg-agent, etc.
       6. Even without those things,the master password is stored in an encrypted form after it times out.
       7. While decrypted (while timer is going) it's still got the above security mechanisms,
          plus options for standard protected-memory APIs are made available wherever possible.
       8. The actual passphrase the user types is not stored in memory, except just long enough to 
          use it to derive another key, used to unlock the actual key (for a temporary period of time.)
       9. Meanwhile the actual key is stored in encrypted form on disk, and the derived key isn't stored anywhere.
      10. Ultimately external hardware, and smart cards, are the way to go. But OT should still do the best possible.
    */
    
    return bReturnVal;
}


//static 
// This is the thread itself.
// This function never locks the Mutex because it never needs to.
// Instead, it just calls functions that lock the mutex.
//
void OTMasterKey::ThreadTimeout(void * pArg)
{
    OTMasterKey * pMyself = static_cast<OTMasterKey *>(pArg);
    OT_ASSERT_MSG(NULL != pMyself, "OTMasterKey::ThreadTimeout: Need ptr to master key here, that activated this thread.\n");
    // --------------------------------------
    int nTimeoutSeconds = pMyself->GetTimeoutSeconds(); // locks mutex internally.
    
    if (nTimeoutSeconds > 0)
        this_thread::sleep_for(chrono::seconds( nTimeoutSeconds )); // <===== ASLEEP!
    // --------------------------------------

    if (nTimeoutSeconds != (-1))
        pMyself->DestroyMasterPassword(); // locks mutex internally.
}


// Called by the thread.
// The cleartext version (m_pMasterPassword) is deleted and set NULL after a Timer of X seconds. 
// (Timer thread calls this.) The instance that owns each thread will pass its instance pointer
// as pArg so we can access the timeout seconds and the mutex, and the password we're destroying.
//
void OTMasterKey::DestroyMasterPassword()
{
    tthread::lock_guard<tthread::mutex> lock(m_Mutex); // Multiple threads can't get inside here at the same time.
    //
    if (m_nTimeoutSeconds != (-1))
    {
        // (m_pSymmetricKey stays. 
        //  m_pMasterPassword only is destroyed.)
        //
        if (NULL != m_pMasterPassword)
            delete m_pMasterPassword;
        m_pMasterPassword = NULL;
    }
    // (We do NOT call LowLevelReleaseThread(); here, since the thread is
    // what CALLED this function. Instead, we destroy / NULL the master password,
    // so that next time around we will see it is NULL and THEN we will know to 
    // call LowLevelReleaseThread(); before instantiating a new one.)
}


// ------------------------------------------------------------------------

/*
 // TOdo: make this so you can pass in a password, or you can pass NULL
 // and then it will use the GetPasswordCallback() method to collect one
 // from the user.
 
 OT_OPENSSL_CALLBACK * OTAsymmetricKey::GetPasswordCallback()

 #define OPENSSL_CALLBACK_FUNC(name) extern "C" int (name)(char *buf, int size, int rwflag, void *userdata)

 */

bool OTSymmetricKey::GenerateKey(const OTPassword & thePassword)
{
    const char * szFunc = "OTSymmetricKey::GenerateKey";
    
    OT_ASSERT(m_nIterationCount > 1000);
    OT_ASSERT(!m_bIsGenerated);
    OT_ASSERT(thePassword.isPassword());

    OTLog::vOutput(2, "  Begin: %s: GENERATING keys and passwords...\n", szFunc);
    
    // This derived_key memory is unused, except to help us allocate a 16-byte derived key OTPassword
    // object. (OTPassword stores its own memory internally, and merely copies the derived key, which
    // we then overwrite in the call to PKCS5_PBKDF2_HMAC_SHA1.)
    //
    unsigned char   derived_key[OT_DEFAULT_SYMMETRIC_KEY_SIZE];
    // theDerivedKey will be populated with its actual data in the call to PKCS5_PBKDF2_HMAC_SHA1.
    OTPassword      theDerivedKey(static_cast<void *>(&derived_key[0]), OT_DEFAULT_SYMMETRIC_KEY_SIZE);
	// --------------------------------------------------
    OTPassword      theActualKey;
    
    if (OT_DEFAULT_SYMMETRIC_KEY_SIZE != theActualKey.randomizeMemory(OT_DEFAULT_SYMMETRIC_KEY_SIZE))
	{
		OTLog::vError("%s: Failed generating symmetric key. (Returning false.)\n", szFunc);
		return false;
	}
	// --------------------------------------------------
	if (false == m_dataSalt.Randomize( OT_DEFAULT_SYMMETRIC_SALT_SIZE )) 
	{
		OTLog::vError("%s: Failed generating random salt. (Returning false.)\n", szFunc);
		return false;
	}    
	// --------------------------------------------------
	if (false == m_dataIV.Randomize( OT_DEFAULT_SYMMETRIC_IV_SIZE )) 
	{
		OTLog::vError("%s: Failed generating iv for encrypting a symmetric key. (Returning false.)\n", szFunc);
		return false;
	}
	// --------------------------------------------------
    const char * char_p_password_contents = reinterpret_cast<const char *>(thePassword.getPassword_uint8());
    const size_t size_t_password_length   = static_cast<const size_t>(thePassword.getPasswordSize());
    
    unsigned char * char_p_derived_contents  = static_cast<unsigned char *>(theDerivedKey.getMemoryWritable());
    const size_t size_t_derived_length    = static_cast<const size_t>(theDerivedKey.getMemorySize());
    
    const unsigned char * uchar_p_salt_contents = static_cast<const unsigned char *>(m_dataSalt.GetPayloadPointer());
    const size_t size_t_salt_length       = static_cast<const size_t>(m_dataSalt.GetSize());
    // -----------------
    // Key derivation.
    //
    // int PKCS5_PBKDF2_HMAC_SHA1(const char*, int, const unsigned char*, int, int, int, unsigned char*)’
    //
    PKCS5_PBKDF2_HMAC_SHA1(char_p_password_contents,  size_t_password_length,
                           uchar_p_salt_contents,     size_t_salt_length,
                           static_cast<int>(m_nIterationCount),
                           size_t_derived_length,    char_p_derived_contents);
    // -------------------------------------------------------------------------------------------------
    //
    // Below this point, theDerivedKey contains a new symmetric key derived from the salt, the iteration
    // count, and the password that was passed in. We will store the salt and iteration count inside this
    // OTSymmetricKey object, and we'll store an encrypted copy of the ActualKey, encrypted to the Derived Key.
    // We'll also store the IV for that encryption bit.
    //
    // Encrypt theActualKey using theDerivedKey, which is clear/raw already. (Both are OTPasswords.)
    // Put the result into the OTPayload m_dataEncryptedKey.
    //
    const bool bEncryptedKey = OTEnvelope::Encrypt(theDerivedKey,  // theDerivedKey is a symmetric key, in clear form. Used for encrypting theActualKey.
                                                   // -------------------------------
                                                   reinterpret_cast<const char *>(theActualKey.getMemory_uint8()), // This is the Plaintext that's being encrypted.
                                                   static_cast<uint32_t>(theActualKey.getMemorySize()),
                                                   // -------------------------------
                                                   m_dataIV,
                                                   // -------------------------------
                                                   m_dataEncryptedKey); // OUTPUT. (Ciphertext.)    
    m_bIsGenerated = bEncryptedKey;
    
    OTLog::vOutput(2, "  End: %s: (GENERATING keys and passwords...)\n", szFunc);

    return m_bIsGenerated;
}


// ------------------------------------------------------------------------
/*
 To generate a symmetric key:
 
    1. First we generate the plain symmetric key itself using RAND_bytes().
    2. Then we generate the salt using RAND_bytes()
    3. Then we use thePassword and the salt to derive a key using PBKDF2.
    4. Then we encrypt the plain symmetric key using the derived key from PBKDF2.
    5. Then we store the salt and the encrypted symmetric key. (We discard the derived key.)
    6. (Use the plain symmetric key to encrypt the plaintext.)
 
 To use the symmetric key:
    
    1. We use thePassword from user input, and the stored salt, with PBKDF2 to derive a key.
    2. Use the derived key to decrypt the encrypted symmetric key.
    3. (Use the decrypted symmetric key to decrypt the ciphertext.)
 */

// Done:  add a "get Key" function which takes the OTPassword, generates the derived key using salt already on
// OTSymmetricKey objet, then decrypts the encrypted symmetric key (using derived key) and returns clear symmetric
// key back as another OTPassword object.

// Assumes key is already generated. Tries to get the raw clear key from its encrypted form, via its password.

// If returns true, theRawKeyOutput will contain the decrypted symmetric key, in an OTPassword object.
// Otherwise returns false if failure.
//
bool OTSymmetricKey::GetRawKey(const OTPassword & thePassword, OTPassword & theRawKeyOutput) const
{
    const char * szFunc = "OTSymmetricKey::GetRawKey";    
    
    OT_ASSERT(m_bIsGenerated);
    OT_ASSERT(thePassword.isPassword());
    
    OTLog::vOutput(2, "%s: Attempting to recover actual key using derived key...\n", szFunc);

    // ------------------------------------
    // This derived_key memory is unused, except to help us allocate a 16-byte derived key OTPassword
    // object. (OTPassword stores its own memory internally, and merely copies derived_key, which
    // we then overwrite with the real derived key in the call to PKCS5_PBKDF2_HMAC_SHA1.)
    //
    unsigned char   derived_key[OT_DEFAULT_SYMMETRIC_KEY_SIZE];
    // theDerivedKey will be populated with its actual data in the call to PKCS5_PBKDF2_HMAC_SHA1.
    OTPassword      theDerivedKey(static_cast<void *>(&derived_key[0]), OT_DEFAULT_SYMMETRIC_KEY_SIZE);
	// --------------------------------------------------
    const char * char_p_password_contents = const_cast<char *>(reinterpret_cast<const char *>(thePassword.getPassword_uint8()));
    const size_t size_t_password_length   = static_cast<const size_t>(thePassword.getPasswordSize());
    
    unsigned char * uchar_p_derived_contents  = static_cast<unsigned char *>(theDerivedKey.getMemoryWritable());
    const size_t size_t_derived_length    = static_cast<const size_t>(theDerivedKey.getMemorySize());
    
    const unsigned char * uchar_p_salt_contents  = static_cast<const unsigned char *>(m_dataSalt.GetPayloadPointer());
    const size_t size_t_salt_length       = static_cast<const size_t>(m_dataSalt.GetSize());
    // -----------------
    // Key derivation.
    //
    // int PKCS5_PBKDF2_HMAC_SHA1(const char*, int, const unsigned char*, int, int, int, unsigned char*)
    //
    PKCS5_PBKDF2_HMAC_SHA1(char_p_password_contents, size_t_password_length,
                           uchar_p_salt_contents,     size_t_salt_length,
                           static_cast<int>(m_nIterationCount),
                           size_t_derived_length,    uchar_p_derived_contents);
    // -------------------------------------------------------------------------------------------------
    //
    // Below this point, theDerivedKey contains a derived symmetric key, from the salt, the iteration
    // count, and the password that was passed in. The salt and iteration count were both stored inside this
    // OTSymmetricKey object when this key was originally generated, and we store an encrypted copy of the
    // ActualKey already, as well--encrypted to the Derived Key. (We also store the IV from that encryption bit.)
    //
    // Decrypt theActualKey using theDerivedKey, which is clear/raw already. (Both are OTPasswords.)
    // Put the result into theRawKeyOutput.
    //
    // -----------------

    const bool bDecryptedKey = OTEnvelope::Decrypt(theDerivedKey, // theDerivedKey is a symmetric key, in clear form. Used for decrypting m_dataEncryptedKey into theRawKeyOutput.
                                                   // -------------------------------
                                                   static_cast<const char *>(m_dataEncryptedKey.GetPayloadPointer()), // This is the Ciphertext.  
                                                   m_dataEncryptedKey.GetSize(),
                                                   // -------------------------------
                                                   m_dataIV,
                                                   // -------------------------------
                                                   theRawKeyOutput); // OUTPUT. (Recovered plaintext of symmetric key.) You can pass OTPassword& OR OTPayload& here (either will work.)
    OTLog::vOutput(2, "%s: (End) attempt to recover actual key using derived key...\n", szFunc);
    return bDecryptedKey;
}



// ------------------------------------------------------------------------


bool OTSymmetricKey::SerializeTo(OTString & strOutput, bool bEscaped/*=false*/) const
{
    OTASCIIArmor ascOutput;
    
    if (this->SerializeTo(ascOutput))
        return ascOutput.WriteArmoredString(strOutput, "SYMMETRIC KEY", bEscaped);

    return false;
}


bool OTSymmetricKey::SerializeFrom(const OTString & strInput, bool bEscaped/*=false*/)
{
    OTASCIIArmor ascInput;

    if (strInput.Exists() && ascInput.LoadFromString(const_cast<OTString &>(strInput), 
                                                     bEscaped, 
                                                     "-----BEGIN OT ARMORED SYMMETRIC KEY"))
        return true;

    return false;
}


// ------------------------------------------------------------------------


bool OTSymmetricKey::SerializeTo(OTASCIIArmor & ascOutput) const
{
    OTPayload theOutput;
    
    if (this->SerializeTo(theOutput))
    {
        ascOutput.SetData(theOutput);
        return true;
    }
    
    return false;
}


bool OTSymmetricKey::SerializeFrom(const OTASCIIArmor & ascInput)
{
    OTPayload theInput;
    
    if (ascInput.Exists() && ascInput.GetData(theInput))
    {
        return this->SerializeFrom(theInput);
    }
    return false;
}


// ------------------------------------------------------------------------


bool OTSymmetricKey::SerializeTo(OTPayload & theOutput) const
{
    // -----------------------------------------------
    uint16_t   n_is_generated    = static_cast<uint16_t>(htons(static_cast<uint16_t>(m_bIsGenerated ? 1 : 0))); 
    uint16_t   n_key_size_bits   = static_cast<uint16_t>(htons(static_cast<uint16_t>(m_nKeySize))); 
    // ----------------------------------------------------------------------------------------
    uint32_t   n_iteration_count = static_cast<uint32_t>(htonl(static_cast<uint32_t>(m_nIterationCount))); 
    
    uint32_t   n_salt_size       = static_cast<uint32_t>(htonl(static_cast<uint32_t>(m_dataSalt.GetSize()))); 
    uint32_t   n_iv_size         = static_cast<uint32_t>(htonl(static_cast<uint32_t>(m_dataIV.GetSize()))); 
    uint32_t   n_enc_key_size    = static_cast<uint32_t>(htonl(static_cast<uint32_t>(m_dataEncryptedKey.GetSize()))); 
    
    
    OTLog::vOutput(5, "%s: is_generated: %d   key_size_bits: %d   iteration_count: %ld   \n  "
                   "salt_size: %ld   iv_size: %ld   enc_key_size: %ld   \n", 
                   __FUNCTION__, 
                   static_cast<int>(ntohs(n_is_generated)),
                   static_cast<int>(ntohs(n_key_size_bits)),
                   
                   static_cast<long>(ntohl(n_iteration_count)),
                   static_cast<long>(ntohl(n_salt_size)),
                   static_cast<long>(ntohl(n_iv_size)),
                   static_cast<long>(ntohl(n_enc_key_size))
                   );
    
    // -----------------------------------------------
    theOutput.Concatenate(reinterpret_cast<void *>(&n_is_generated),   
                          static_cast<uint32_t>(sizeof(n_is_generated)));
    
    theOutput.Concatenate(reinterpret_cast<void *>(&n_key_size_bits),   
                          static_cast<uint32_t>(sizeof(n_key_size_bits)));
    
    theOutput.Concatenate(reinterpret_cast<void *>(&n_iteration_count),   
                          static_cast<uint32_t>(sizeof(n_iteration_count)));
    // -------------------------
    theOutput.Concatenate(reinterpret_cast<void *>(&n_salt_size),   
                          static_cast<uint32_t>(sizeof(n_salt_size)));
    
    theOutput.Concatenate(m_dataSalt.GetPayloadPointer(),
                          m_dataSalt.GetSize());
    // -------------------------
    theOutput.Concatenate(reinterpret_cast<void *>(&n_iv_size),   
                          static_cast<uint32_t>(sizeof(n_iv_size)));
    
    theOutput.Concatenate(m_dataIV.GetPayloadPointer(),
                          m_dataIV.GetSize());
    // -------------------------
    theOutput.Concatenate(reinterpret_cast<void *>(&n_enc_key_size),   
                          static_cast<uint32_t>(sizeof(n_enc_key_size)));
    
    theOutput.Concatenate(m_dataEncryptedKey.GetPayloadPointer(),
                          m_dataEncryptedKey.GetSize());
    
    return true;
}

// ------------------------------------------------------------------------


// Notice I don't theInput.reset(), because what if this
// key was being read from a larger file containing several
// keys?  I should just continue reading from the current
// position, and let the CALLER reset first, if that's his
// intention.
//
bool OTSymmetricKey::SerializeFrom(OTPayload & theInput)
{
    const char * szFunc = "OTSymmetricKey::SerializeFrom";
    
    uint32_t  nRead  = 0;
    
    // ****************************************************************************
    //
    // Read network-order "is generated" flag. (convert to host order) 
    //    
    uint16_t  n_is_generated = 0;
    
    if (0 == (nRead = theInput.OTfread(reinterpret_cast<uint8_t*>(&n_is_generated), 
                                       static_cast<uint32_t>(sizeof(n_is_generated)))))
	{
		OTLog::vError("%s: Error reading n_is_generated.\n", szFunc);
		return false;
	}
    // ----------------------------------------------------------------------------
	// convert from network to HOST endian.
    //
    uint16_t host_is_generated = ntohs(n_is_generated);
    
    if (1 == host_is_generated)
        m_bIsGenerated = true;
    else if (0 == host_is_generated)
        m_bIsGenerated = false;
    else
    {
        OTLog::vError("%s: Error: host_is_generated, Bad value: %d. (Expected 0 or 1.)\n",
                      szFunc, static_cast<int>(host_is_generated));
        return false;
    }
    // ****************************************************************************
    
    OTLog::vOutput(5, "%s: is_generated: %d \n", 
                   __FUNCTION__, 
                   static_cast<int>(host_is_generated)
                   );
    
    // ****************************************************************************
    //
    // Read network-order "key size in bits". (convert to host order) 
    //    
    uint16_t  n_key_size_bits = 0;
    
    if (0 == (nRead = theInput.OTfread(reinterpret_cast<uint8_t*>(&n_key_size_bits), 
                                       static_cast<uint32_t>(sizeof(n_key_size_bits)))))
	{
		OTLog::vError("%s: Error reading n_key_size_bits.\n", szFunc);
		return false;
	}
    // ----------------------------------------------------------------------------
	// convert from network to HOST endian.

    m_nKeySize = static_cast<uint16_t>(ntohs(n_key_size_bits));
    
    OTLog::vOutput(5, "%s: key_size_bits: %d \n", 
                   __FUNCTION__, 
                   static_cast<int>(m_nKeySize)
                   );
    

    // ****************************************************************************
    
    
    
    // ****************************************************************************
    //
    // Read network-order "iteration count". (convert to host order) 
    //    
    uint32_t  n_iteration_count = 0;
    
    if (0 == (nRead = theInput.OTfread(reinterpret_cast<uint8_t*>(&n_iteration_count), 
                                       static_cast<uint32_t>(sizeof(n_iteration_count)))))
	{
		OTLog::vError("%s: Error reading n_iteration_count.\n", szFunc);
		return false;
	}
    OT_ASSERT(nRead == static_cast<uint32_t>(sizeof(n_iteration_count)));
    // ----------------------------------------------------------------------------
	// convert from network to HOST endian.
    
    m_nIterationCount = static_cast<uint32_t>(ntohl(n_iteration_count));
    
    OTLog::vOutput(5, "%s: iteration_count: %ld \n", 
                   __FUNCTION__, 
                   static_cast<long>(m_nIterationCount)
                   );
    
    // ****************************************************************************
    
    
    
    // ****************************************************************************
    //
    // Read network-order "salt size". (convert to host order) 
    //    
    uint32_t  n_salt_size = 0;
    
    if (0 == (nRead = theInput.OTfread(reinterpret_cast<uint8_t*>(&n_salt_size), 
                                       static_cast<uint32_t>(sizeof(n_salt_size)))))
	{
		OTLog::vError("%s: Error reading n_salt_size.\n", szFunc);
		return false;
	}
    OT_ASSERT(nRead == static_cast<uint32_t>(sizeof(n_salt_size)));
    // ----------------------------------------------------------------------------
	// convert from network to HOST endian.
    
    const uint32_t lSaltSize = static_cast<uint32_t>(ntohl(static_cast<uint32_t>(n_salt_size)));
    
    OTLog::vOutput(5, "%s: salt_size value: %ld \n", 
                   __FUNCTION__, 
                   static_cast<long>(lSaltSize)
                   );

	// ----------------------------------------------------------------------------
    //
    // Then read the Salt itself.
    //
    m_dataSalt.SetPayloadSize(lSaltSize);
    
    if (0 == (nRead = theInput.OTfread(static_cast<uint8_t*>(const_cast<void *>(m_dataSalt.GetPayloadPointer())),
                                       static_cast<uint32_t>(lSaltSize))))
    {
        OTLog::vError("%s: Error reading salt for symmetric key.\n", szFunc);
        return false;
    }
    OTLog::vOutput(5, "%s: salt length actually read: %ld \n", 
                   __FUNCTION__, 
                   static_cast<long>(nRead)
                   );
    OT_ASSERT(nRead == static_cast<uint32_t>(lSaltSize));
    // ****************************************************************************
    
    
    // ****************************************************************************
    //
    // Read network-order "IV size". (convert to host order) 
    //    
    uint32_t  n_iv_size = 0;
    
    if (0 == (nRead = theInput.OTfread(reinterpret_cast<uint8_t*>(&n_iv_size), 
                                       static_cast<uint32_t>(sizeof(n_iv_size)))))
	{
		OTLog::vError("%s: Error reading n_iv_size.\n", szFunc);
		return false;
	}
    
    OT_ASSERT(nRead == static_cast<uint32_t>(sizeof(n_iv_size)));
    
    // ----------------------------------------------------------------------------
	// convert from network to HOST endian.
    
    const uint32_t lIVSize = ntohl(n_iv_size);

    OTLog::vOutput(5, "%s: iv_size value: %ld \n", 
                   __FUNCTION__, 
                   static_cast<long>(lIVSize)
                   );
    
	// ----------------------------------------------------------------------------
    //
    // Then read the IV itself.
    //
    m_dataIV.SetPayloadSize(lIVSize);
    
    if (0 == (nRead = theInput.OTfread(static_cast<uint8_t*>(const_cast<void *>(m_dataIV.GetPayloadPointer())),
                                       static_cast<uint32_t>(lIVSize))))
    {
        OTLog::vError("%s: Error reading IV for symmetric key.\n", szFunc);
        return false;
    }
    
    OTLog::vOutput(5, "%s: iv length actually read: %ld \n", 
                   __FUNCTION__, 
                   static_cast<long>(nRead)
                   );

    OT_ASSERT(nRead == static_cast<uint32_t>(lIVSize));
    // ****************************************************************************
    

    
    // ****************************************************************************
    //
    // Read network-order "encrypted key size". (convert to host order) 
    //    
    uint32_t  n_enc_key_size = 0;
    
    if (0 == (nRead = theInput.OTfread(reinterpret_cast<uint8_t*>(&n_enc_key_size), 
                                       static_cast<uint32_t>(sizeof(n_enc_key_size)))))
	{
		OTLog::vError("%s: Error reading n_enc_key_size.\n", szFunc);
		return false;
	}
    OT_ASSERT(nRead == static_cast<uint32_t>(sizeof(n_enc_key_size)));
    // ----------------------------------------------------------------------------
	// convert from network to HOST endian.
    
    const uint32_t lEncKeySize = ntohl(n_enc_key_size);
    
    OTLog::vOutput(5, "%s: enc_key_size value: %ld \n", 
                   __FUNCTION__, 
                   static_cast<long>(lEncKeySize)
                   );

	// ----------------------------------------------------------------------------
    //
    // Then read the Encrypted Key itself.
    //
    m_dataEncryptedKey.SetPayloadSize(lEncKeySize);
    
    if (0 == (nRead = theInput.OTfread(static_cast<uint8_t*>(const_cast<void *>(m_dataEncryptedKey.GetPayloadPointer())),
                                       static_cast<uint32_t>(lEncKeySize))))
    {
        OTLog::vError("%s: Error reading encrypted symmetric key.\n", szFunc);
        return false;
    }
    
    OTLog::vOutput(5, "%s: encrypted key length actually read: %ld \n", 
                   __FUNCTION__, 
                   static_cast<long>(nRead)
                   );

    OT_ASSERT(nRead == static_cast<uint32_t>(lEncKeySize));
    // ****************************************************************************

    return true;
}

// ------------------------------------------------------------------------












// ------------------------------------------------------------------------

OTSymmetricKey::OTSymmetricKey()
:   m_bIsGenerated(false), 
    m_nKeySize(OT_DEFAULT_SYMMETRIC_KEY_SIZE_BITS), // 128
    m_nIterationCount(OT_DEFAULT_ITERATION_COUNT) 
{
    
}

// ------------------------------------------------------------------------

OTSymmetricKey::OTSymmetricKey(const OTPassword & thePassword)
:   m_bIsGenerated(false), 
    m_nKeySize(OT_DEFAULT_SYMMETRIC_KEY_SIZE_BITS), // 128
    m_nIterationCount(OT_DEFAULT_ITERATION_COUNT)
{
//    const bool bGenerated = 
        this->GenerateKey(thePassword);
}

// ------------------------------------------------------------------------

OTSymmetricKey::~OTSymmetricKey()
{
//  Release(); // Unnecessary here, since the two data object members already will destruct.
}
// ------------------------------------------------------------------------

void OTSymmetricKey::Release()
{
    m_bIsGenerated    = false;
    m_nIterationCount = OT_DEFAULT_ITERATION_COUNT;
    m_nKeySize        = OT_DEFAULT_SYMMETRIC_KEY_SIZE_BITS; // 128
    
    m_dataSalt.Release();
    m_dataIV.Release();
    m_dataEncryptedKey.Release();    
}




// ------------------------------------------------------------------------

// Presumably this Envelope contains encrypted data (in binary form.)
// If you would like an ASCII-armored version of that data, just call this
// function.
// Should be called "Get Binary Envelope Encrypted Contents Into Ascii-Armored Form"
//
bool OTEnvelope::GetAsciiArmoredData(OTASCIIArmor & theArmoredText) const
{
	return theArmoredText.SetData(m_dataContents);
}

// Let's say you just retrieved the ASCII-armored contents of an encrypted envelope.
// Perhaps someone sent it to you, and you just read it out of his message.
// And let's say you want to get those contents back into binary form in an
// Envelope object again, so that they can be decrypted and extracted back as
// plaintext. Fear not, just call this function.
// should be called "Set Via Ascii Armored Data"
bool OTEnvelope::SetAsciiArmoredData(const OTASCIIArmor & theArmoredText)
{
	return theArmoredText.GetData(m_dataContents);
}




// ------------------------------------------------------------------------


/*
 void OTData::AESEncrypt(OTData & theKey)
{
	const unsigned char *iv="blahfuckheadfixthis";
	
	EVP_CIPHER_CTX ctx;
	EVP_CIPHER_CTX_init(&ctx);
	
	const EVP_CIPHER * cipher = EVP_aes_128_cbc();
	
	EVP_EncryptInit(&ctx, cipher, theKey.GetPointer(), iv);
	
	EVP_EncryptUpdate(&ctx, out, &outlen, in, inlen);
	
	// unsigned char * out
	EVP_EncryptFinal(&ctx, out, &outlen);
	
	EVP_CIPHER_CTX_cleanup(&ctx);
}
 
 
 int EVP_EncryptInit(EVP_CIPHER_CTX *ctx, const EVP_CIPHER *type,
                     unsigned char  *key, unsigned char *iv);
 */

// #define OT_DEFAULT_SYMMETRIC_BUFFER_SIZE 4096


//static
bool OTEnvelope::Encrypt(const OTPassword & theRawSymmetricKey, // The symmetric key, in clear form.
                         // -------------------------------
                         const char *       szInput,            // This is the Plaintext.
                         const uint32_t     lInputLength,
                         // -------------------------------
                         const OTPayload &  theIV,              // (We assume this IV is already generated and passed in.)
                         // -------------------------------
                               OTPayload &  theEncryptedOutput) // OUTPUT. (Ciphertext.)
{
    const char * szFunc = "OTEnvelope::Encrypt(static)";
    // -----------------------------------------------  
    OT_ASSERT(OT_DEFAULT_SYMMETRIC_IV_SIZE   == theIV.GetSize());
    OT_ASSERT(OT_DEFAULT_SYMMETRIC_KEY_SIZE  == theRawSymmetricKey.getMemorySize());
    OT_ASSERT(NULL != szInput);
    OT_ASSERT(lInputLength > 0);
    // -----------------------------------------------    
	EVP_CIPHER_CTX	ctx;
    
	uint8_t	buffer    [ OT_DEFAULT_SYMMETRIC_BUFFER_SIZE ]; // 4096
    uint8_t	buffer_out[ OT_DEFAULT_SYMMETRIC_BUFFER_SIZE + EVP_MAX_IV_LENGTH];
    
	uint32_t		len     = 0;
    int				len_out = 0;
    // -----------------------------------------------
	memset(buffer,     0, OT_DEFAULT_SYMMETRIC_BUFFER_SIZE );
	memset(buffer_out, 0, OT_DEFAULT_SYMMETRIC_BUFFER_SIZE + EVP_MAX_IV_LENGTH);
    // -----------------------------------------------    
	//
	// This is where the envelope final contents will be placed.
    // including the size of the IV, the IV itself, and the ciphertext.
    //
	theEncryptedOutput.Release();
    
    // -----------------------------------------------
    class _OTEnv_Enc_stat
    {
    private:
        const char      *  m_szFunc;
        EVP_CIPHER_CTX	&  m_ctx;
    public:
        _OTEnv_Enc_stat(const char * param_szFunc,
                        EVP_CIPHER_CTX & param_ctx) :
            m_szFunc(param_szFunc),
            m_ctx(param_ctx)
        {
            OT_ASSERT(NULL != param_szFunc);

            EVP_CIPHER_CTX_init(&m_ctx);
        }
        ~_OTEnv_Enc_stat()
        {
            // EVP_CIPHER_CTX_cleanup returns 1 for success and 0 for failure.
            //
            if (0 == EVP_CIPHER_CTX_cleanup(&m_ctx))
                OTLog::vError("%s: Failure in EVP_CIPHER_CTX_cleanup. (It returned 0.)\n", m_szFunc);
			
			m_szFunc = NULL; // keep the static analyzer happy
        }
    };
    _OTEnv_Enc_stat  theInstance(szFunc, ctx);
    // -----------------------------------------------

    const EVP_CIPHER * cipher_type = EVP_aes_128_cbc();   // todo hardcoding. 	    
    
    // -----------------------------------------------
    if (!EVP_EncryptInit(&ctx, 
                         cipher_type, 
                         const_cast<uint8_t *>(theRawSymmetricKey.getMemory_uint8()),
                         static_cast<uint8_t *>(const_cast<void *>(theIV.GetPayloadPointer()))))
    {
        OTLog::vError("%s: EVP_EncryptInit: failed.\n", szFunc);
		return false;
    }
    // -----------------------------------------------
	//
    // Now we process the input and write the encrypted data to
	// the output.
	//
    uint32_t  lRemainingLength = lInputLength;
    uint32_t  lCurrentIndex    = 0;
    
    while (lRemainingLength > 0)
    {
        // If the remaining length is less than the default buffer size, then set len to remaining length.
        // else if remaining length is larger than or equal to default buffer size, then use the default buffer size.
        // Resulting value stored in len.
        //
        len = static_cast<uint32_t>((lRemainingLength < OT_DEFAULT_SYMMETRIC_BUFFER_SIZE) ? lRemainingLength : OT_DEFAULT_SYMMETRIC_BUFFER_SIZE); // 4096
        
        if (!EVP_EncryptUpdate(&ctx,
                               buffer_out,
                               &len_out,
                               const_cast<uint8_t *>(reinterpret_cast<const uint8_t *>(&(szInput [ lCurrentIndex ]))),
                               len))
        {
            OTLog::vError("%s: EVP_EncryptUpdate: failed.\n", szFunc);
			return false;
        }
        lRemainingLength -= len;
        lCurrentIndex    += len;
        
        if (len_out > 0)
            theEncryptedOutput.Concatenate(reinterpret_cast<void *>(buffer_out), 
                                           static_cast<uint32_t>(len_out));
    }
    // -----------------------------------------------
    //
	if (!EVP_EncryptFinal(&ctx, buffer_out, &len_out))
    {
        OTLog::vError("%s: EVP_EncryptFinal: failed.\n", szFunc);
		return false;
    }
    // -----------------------------------------------    
    // This is the "final" piece that is added from EncryptFinal just above.
    //
    if (len_out > 0)
        theEncryptedOutput.Concatenate(reinterpret_cast<void *>(buffer_out), 
                                       static_cast<uint32_t>(len_out));    
    // -----------------------------------------------
    return true;
}



// Encrypt theInput as envelope using symmetric crypto, using a random AES key that's 
// kept encrypted in an OTSymmetricKey (encrypted using another key derived from  
// thePassword.)

bool OTEnvelope::Encrypt(const OTString & theInput, OTSymmetricKey & theKey, const OTPassword & thePassword)
{
    const char * szFunc = "OTEnvelope::Encrypt";
    // -----------------------------------------------
    OT_ASSERT(thePassword.isPassword());
    OT_ASSERT(thePassword.getPasswordSize() > 0);
    OT_ASSERT(theInput.Exists());
    // -----------------------------------------------
    // Generate a random initialization vector.
    //
    OTPayload theIV;

    if (false == theIV.Randomize(OT_DEFAULT_SYMMETRIC_IV_SIZE))
    {
		OTLog::vError("%s: Failed trying to randomly generate IV.\n", szFunc);
		return false;	
    }
    // -----------------------------------------------
    // If the symmetric key hasn't already been generated, we'll just do that now...
    // (The passphrase is used to derive another key that is used to encrypt the
    // actual symmetric key, and to access it later.)
    //
    if ((false == theKey.IsGenerated()) && (false == theKey.GenerateKey(thePassword)))
    {
		OTLog::vError("%s: Failed trying to generate symmetric key using password.\n", szFunc);
		return false;	
    }
    // -----------------------------------------------
    OTPassword  theRawSymmetricKey;
    
    if (false == theKey.GetRawKey(thePassword, theRawSymmetricKey))
    {
		OTLog::vError("%s: Failed trying to retrieve raw symmetric key using password.\n", szFunc);
		return false;	
    }
    // -----------------------------------------------
    //
    OTPayload theCipherText;
    
    const bool bEncrypted = OTEnvelope::Encrypt(theRawSymmetricKey, // The symmetric key, in clear form.
                                                // -------------------------------
                                                theInput.Get(),     // This is the Plaintext.
                                                theInput.GetLength() + 1, // for null terminator
                                                // -------------------------------
                                                theIV,              // Initialization vector.
                                                // -------------------------------
                                                theCipherText);     // OUTPUT. (Ciphertext.)
    // -----------------------------------------------
    //
    // Success?
    //
    if (!bEncrypted)
    {
        OTLog::vError("%s: (static) call failed to encrypt. Wrong key? (Returning false.)\n", szFunc);
		return false;
    }
    // -----------------------------------------------
    //
	// This is where the envelope final contents will be placed,
    // including the envelope type, the size of the IV, the IV
    // itself, and the ciphertext.
    //
	m_dataContents.Release();

    // -----------------------------------------------
    // Write the ENVELOPE TYPE (network order version.)
    //
    // 0 == Error
    // 1 == Asymmetric Key  (other functions -- Seal / Open.)
    // 2 == Symmetric Key   (this function -- Encrypt / Decrypt.)
    // Anything else: error.
    
    uint16_t   env_type_n = static_cast<uint16_t>(htons(static_cast<uint16_t>(2))); // Calculate "network-order" version of envelope type 2.
    
    m_dataContents.Concatenate(reinterpret_cast<void *>(&env_type_n),   
                               // (uint32_t here is the 2nd parameter to Concatenate, and has nothing to do with env_type_n being uint16_t)
                               static_cast<uint32_t>(sizeof(env_type_n)));  
    // ------------------------------------------------------------
    //
    // Write IV size (in network-order)
    //
    uint32_t  ivlen   = OT_DEFAULT_SYMMETRIC_IV_SIZE; // Length of IV for this cipher...
    OT_ASSERT(ivlen >= theIV.GetSize());
    uint32_t  ivlen_n = htonl(theIV.GetSize()); // Calculate "network-order" version of iv length.
    
	m_dataContents.Concatenate(reinterpret_cast<void *>(&ivlen_n),   
                               static_cast<uint32_t>(sizeof(ivlen_n)));
	
    // Write the IV itself.
    //
	m_dataContents.Concatenate(theIV.GetPayloadPointer(), 
                               static_cast<uint32_t>(theIV.GetSize()));
    // ------------------------------------------------------------
    
    // Write the Ciphertext.
    //
    m_dataContents.Concatenate(theCipherText.GetPayloadPointer(), 
                               static_cast<uint32_t>(theCipherText.GetSize()));
    
    // We don't write the size of the ciphertext before the ciphertext itself,
    // since the decryption is able to deduce the size based on the total envelope
    // size minus the other pieces. We might still want to add that size here, however.
    // (for security / safety reasons.)
    
    // -----------------------------------------------
    return true;
}


// Note: these two functions will make it pretty easy to add Session Keys for all communications,
// since Envelopes are ALREADY used for all comms. 

// ------------------------------------------------------------------------

/*
class OTEnvelope_Decrypt_Output
{
private:
    OTPassword * m_pPassword;
    OTPayload  * m_pPayload;
    
    OTEnvelope_Decrypt_Output();
public:
    ~OTEnvelope_Decrypt_Output();
    
    OTEnvelope_Decrypt_Output(OTEnvelope_Decrypt_Output & rhs);
    OTEnvelope_Decrypt_Output(OTPassword & thePassword);
    OTEnvelope_Decrypt_Output(OTPayload  & thePayload);
    
    
    void swap(OTEnvelope_Decrypt_Output & other); // the swap member function (should never fail!)
    
    OTEnvelope_Decrypt_Output & operator = (OTEnvelope_Decrypt_Output other); // note: argument passed by value!
};
*/
// ------------------------------------------------------------------------

OTEnvelope_Decrypt_Output::OTEnvelope_Decrypt_Output() : m_pPassword(NULL), m_pPayload(NULL) {}

OTEnvelope_Decrypt_Output::~OTEnvelope_Decrypt_Output() 
{
    m_pPassword = NULL;
    m_pPayload  = NULL;

}


OTEnvelope_Decrypt_Output::OTEnvelope_Decrypt_Output(const OTEnvelope_Decrypt_Output & rhs) // passed 
: m_pPassword(NULL), m_pPayload(NULL)
{
    m_pPassword = rhs.m_pPassword;
    m_pPayload  = rhs.m_pPayload;
}
    
OTEnvelope_Decrypt_Output::OTEnvelope_Decrypt_Output(OTPassword & thePassword)
 : m_pPassword(&thePassword), m_pPayload(NULL)
{
    
}

OTEnvelope_Decrypt_Output::OTEnvelope_Decrypt_Output(OTPayload  & thePayload)
 : m_pPassword(NULL), m_pPayload(&thePayload)
{
    
}

void OTEnvelope_Decrypt_Output::swap(OTEnvelope_Decrypt_Output & other) // the swap member function (should never fail!)
{
    std::swap(m_pPassword, other.m_pPassword);
    std::swap(m_pPayload,  other.m_pPayload);
}
    
OTEnvelope_Decrypt_Output & OTEnvelope_Decrypt_Output::operator=(OTEnvelope_Decrypt_Output other) // note: argument passed by value!
{
    // swap this with other
    this->swap(other);
    
    // by convention, always return *this
    return *this;
}

// This is just a wrapper class.
//
void OTEnvelope_Decrypt_Output::Release()
{
    OT_ASSERT((m_pPassword != NULL) || (m_pPayload != NULL));

    if (NULL != m_pPassword)
        m_pPassword->zeroMemory();

    if (NULL != m_pPayload)
        m_pPayload->Release();
}


bool OTEnvelope_Decrypt_Output::Concatenate(const void * pAppendData, uint32_t lAppendSize)
{
    OT_ASSERT((m_pPassword != NULL) || (m_pPayload != NULL));
    
    if (NULL != m_pPassword)
    {
        if (static_cast<int32_t>(lAppendSize) == 
            static_cast<int32_t>(m_pPassword->addMemory(pAppendData, static_cast<uint32_t>(lAppendSize))))
            return true;
        else
            return false;
    }
    // -------------------------
    if (NULL != m_pPayload)
    {
        m_pPayload->Concatenate(pAppendData, lAppendSize);
        return true;
    }
    return false;
}




// ------------------------------------------------------------------------

//static
bool OTEnvelope::Decrypt(const OTPassword & theRawSymmetricKey, // The symmetric key, in clear form.
                         // -------------------------------
                         const char *       szInput,            // This is the Ciphertext.
                         const uint32_t     lInputLength,
                         // -------------------------------
                         const OTPayload &  theIV,              // (We assume this IV is already generated and passed in.)
                         // -------------------------------
                         OTEnvelope_Decrypt_Output theDecryptedOutput) // OUTPUT. (Recovered plaintext.) You can pass OTPassword& OR OTPayload& here (either will work.)
{
    const char * szFunc = "OTEnvelope::Decrypt(static)";
    // -----------------------------------------------  
    OT_ASSERT(OT_DEFAULT_SYMMETRIC_IV_SIZE   == theIV.GetSize());
    OT_ASSERT(OT_DEFAULT_SYMMETRIC_KEY_SIZE  == theRawSymmetricKey.getMemorySize());
    OT_ASSERT(NULL != szInput);
    OT_ASSERT(lInputLength > 0);
    // -----------------------------------------------    
	EVP_CIPHER_CTX	ctx;
    
	uint8_t	buffer    [ OT_DEFAULT_SYMMETRIC_BUFFER_SIZE ]; // 4096
    uint8_t	buffer_out[ OT_DEFAULT_SYMMETRIC_BUFFER_SIZE + EVP_MAX_IV_LENGTH];
    
	uint32_t		len     = 0;
    int				len_out = 0;
    // -----------------------------------------------
	memset(buffer,     0, OT_DEFAULT_SYMMETRIC_BUFFER_SIZE );
	memset(buffer_out, 0, OT_DEFAULT_SYMMETRIC_BUFFER_SIZE + EVP_MAX_IV_LENGTH);
    // -----------------------------------------------    
	//
	// This is where the plaintext results will be placed.
    //
	theDecryptedOutput.Release();
    
    // -----------------------------------------------
    class _OTEnv_Dec_stat
    {
    private:
        const char      *  m_szFunc;
        EVP_CIPHER_CTX	&  m_ctx;
    public:
        _OTEnv_Dec_stat(const char * param_szFunc,
                        EVP_CIPHER_CTX & param_ctx) :
            m_szFunc(param_szFunc),
            m_ctx(param_ctx)
        {
            OT_ASSERT(NULL != param_szFunc);

            EVP_CIPHER_CTX_init(&m_ctx);
        }
        ~_OTEnv_Dec_stat()
        {
            // EVP_CIPHER_CTX_cleanup returns 1 for success and 0 for failure.
            //
            if (0 == EVP_CIPHER_CTX_cleanup(&m_ctx))
                OTLog::vError("%s: Failure in EVP_CIPHER_CTX_cleanup. (It returned 0.)\n", m_szFunc);
			m_szFunc = NULL; // to keep the static analyzer happy.
        }
    };
    _OTEnv_Dec_stat  theInstance(szFunc, ctx);
    // -----------------------------------------------

    const EVP_CIPHER * cipher_type = EVP_aes_128_cbc();    	    
    
    // -----------------------------------------------
    //
    if (!EVP_DecryptInit(&ctx, 
                         cipher_type, 
                         const_cast<uint8_t *>(theRawSymmetricKey.getMemory_uint8()),
                         static_cast<uint8_t *>(const_cast<void *>(theIV.GetPayloadPointer()))))
    {
        OTLog::vError("%s: EVP_DecryptInit: failed.\n", szFunc);
		return false;
    }
    // -----------------------------------------------
	//
    // Now we process the input and write the decrypted data to
	// the output.
	//
    uint32_t  lRemainingLength = lInputLength;
    uint32_t  lCurrentIndex    = 0;
    
    while (lRemainingLength > 0)
    {
        // If the remaining length is less than the default buffer size, then set len to remaining length.
        // else if remaining length is larger than or equal to default buffer size, then use the default buffer size.
        // Resulting value stored in len.
        //
        len = (lRemainingLength < OT_DEFAULT_SYMMETRIC_BUFFER_SIZE) ? lRemainingLength : OT_DEFAULT_SYMMETRIC_BUFFER_SIZE; // 4096
        lRemainingLength -= len;

        if (!EVP_DecryptUpdate(&ctx,
                               buffer_out,
                               &len_out,
                               const_cast<uint8_t *>(reinterpret_cast<const uint8_t *>(&(szInput [ lCurrentIndex ]))),
                               len))
        {
            OTLog::vError("%s: EVP_DecryptUpdate: failed.\n", szFunc);
			return false;
        }
        lCurrentIndex += len;
        
        if (len_out > 0)
            if (false == theDecryptedOutput.Concatenate(reinterpret_cast<void *>(buffer_out), 
                                                        static_cast<uint32_t>(len_out)))
            {
                OTLog::vError("%s: Failure: theDecryptedOutput isn't large enough for the decrypted output (1).\n", szFunc);
                return false;
            }

    }
    // -----------------------------------------------
    //
	if (!EVP_DecryptFinal(&ctx, buffer_out, &len_out))
    {
        OTLog::vError("%s: EVP_DecryptFinal: failed.\n", szFunc);
		return false;
    }
    // -----------------------------------------------    
    // This is the "final" piece that is added from DecryptFinal just above.
    //
    if (len_out > 0)
        if (false == theDecryptedOutput.Concatenate(reinterpret_cast<void *>(buffer_out), 
                                                    static_cast<uint32_t>(len_out)))
        {
            OTLog::vError("%s: Failure: theDecryptedOutput isn't large enough for the decrypted output (2).\n", szFunc);
            return false;
        }
    // -----------------------------------------------
    return true;
}


/*

void OTData::AESDecrypt(OTData & theKey)
{
	const unsigned char *iv="blahfuckheadfixthis";
	
	EVP_CIPHER_CTX ctx;
	EVP_CIPHER_CTX_init(&ctx);
	
	const EVP_CIPHER * cipher = EVP_aes_128_cbc();
	
	EVP_DecryptInit(&ctx, cipher, theKey.GetPointer(), iv);
	
	EVP_DecryptUpdate(&ctx, out, &outlen, in, inlen);
	
	// unsigned char * out
	EVP_DecryptFinal(&ctx, out, &outlen);
	
	EVP_CIPHER_CTX_cleanup(&ctx);
} 
 */

//
bool OTEnvelope::Decrypt(OTString & theOutput, const OTSymmetricKey & theKey, const OTPassword & thePassword)
{
    const char * szFunc = "OTEnvelope::Decrypt";
    // ------------------------------------------------
    OT_ASSERT(thePassword.isPassword());
    OT_ASSERT(thePassword.getPasswordSize() > 0);
    OT_ASSERT(theKey.IsGenerated());
    // -----------------------------------------------
    OTPassword  theRawSymmetricKey;
    
    if (false == theKey.GetRawKey(thePassword, theRawSymmetricKey))
    {
		OTLog::vError("%s: Failed trying to retrieve raw symmetric key using password. (Wrong password?)\n", 
                      szFunc);
		return false;	
    }
    // -----------------------------------------------
    //
    uint32_t    nRead         = 0;
    uint32_t    nRunningTotal = 0;
    
    m_dataContents.reset(); // Reset the fread position on this object to 0.

    // ****************************************************************************
    //
    // Read the ENVELOPE TYPE (as network order version -- and convert to host version.)
    //
    // 0 == Error
    // 1 == Asymmetric Key  (this function -- Seal / Open)
    // 2 == Symmetric Key   (other functions -- Encrypt / Decrypt use this.)
    // Anything else: error.
    //
    uint16_t  env_type_n = 0;
    
    if (0 == (nRead = m_dataContents.OTfread(reinterpret_cast<uint8_t*>(&env_type_n),
                                             static_cast<uint32_t>(sizeof(env_type_n)))))
	{
		OTLog::vError("%s: Error reading Envelope Type. Expected asymmetric(1) or symmetric (2).\n", szFunc);
		return false;
	}
    nRunningTotal += nRead;
    OT_ASSERT(nRead == static_cast<uint32_t>(sizeof(env_type_n)));
    // ----------------------------------------------------------------------------
	// convert that envelope type from network to HOST endian.
    //
    const uint16_t env_type = static_cast<uint16_t>(ntohs(static_cast<uint16_t>(env_type_n)));
//  nRunningTotal += env_type;    // NOPE! Just because envelope type is 1 or 2, doesn't mean we add 1 or 2 extra bytes to the length here. Nope!
    
    if (2 != env_type)
	{
        const uint32_t l_env_type = static_cast<uint32_t>(env_type);
		OTLog::vError("%s: Error: Expected Envelope for Symmetric key (type 2) but instead found type: %ld.\n", 
                      szFunc, l_env_type);
		return false;
	}
    // ****************************************************************************
    //
    // Read network-order IV size (and convert to host version) 
    //    
    const uint32_t max_iv_length   = OT_DEFAULT_SYMMETRIC_IV_SIZE; // I believe this is a max length, so it may not match the actual length of the IV.
    
    // Read the IV SIZE (network order version -- convert to host version.)
    //
    uint32_t	iv_size_n   = 0;
    
    if (0 == (nRead = m_dataContents.OTfread(reinterpret_cast<uint8_t*>(&iv_size_n),
                                             static_cast<uint32_t>(sizeof(iv_size_n)))))
	{
		OTLog::vError("%s: Error reading IV Size.\n", szFunc);
		return false;
	}
    nRunningTotal += nRead;
    OT_ASSERT(nRead == static_cast<uint32_t>(sizeof(iv_size_n)));
    // ----------------------------------------------------------------------------
	// convert that iv size from network to HOST endian.
    //
    const uint32_t iv_size_host_order = ntohl(iv_size_n);
    
    if (iv_size_host_order > max_iv_length)
    {
        OTLog::vError("%s: Error: iv_size (%ld) is larger than max_iv_length (%ld).\n",
                      szFunc, static_cast<long>(iv_size_host_order), static_cast<long>(max_iv_length));
        return false;
    }
//  nRunningTotal += iv_size_host_order; // Nope!
    // ****************************************************************************
    //
    // Then read the IV (initialization vector) itself.
    //
    OTPayload theIV;
    theIV.SetPayloadSize(iv_size_host_order);
    
    if (0 == (nRead = m_dataContents.OTfread(static_cast<uint8_t*>(const_cast<void *>(theIV.GetPayloadPointer())), 
                                             static_cast<uint32_t>(iv_size_host_order))))
    {
        OTLog::vError("%s: Error reading initialization vector.\n", szFunc);
        return false;
    }
    nRunningTotal += nRead;
    OT_ASSERT(nRead == static_cast<uint32_t>(iv_size_host_order));
    
    OT_ASSERT(nRead <= max_iv_length);
    
	// ----------------------------------------------------------------------------    
    // We create an OTPayload object to store the ciphertext itself, which begins AFTER the end of the IV.
    // So we see pointer + nRunningTotal as the starting point for the ciphertext.
    // the size of the ciphertext, meanwhile, is the size of the entire thing, MINUS nRunningTotal.
    //
	OTPayload theCipherText(static_cast<const void*>( 
                                               static_cast<const uint8_t *>(m_dataContents.GetPointer()) + nRunningTotal
                                               ), 
					  m_dataContents.GetSize() - nRunningTotal);
    // ----------------------------------------------------------------------------
    // Now we've got all the pieces together, let's try to decrypt it...
    //
    OTPayload thePlaintext; // for output.
    
    const bool bDecrypted = OTEnvelope::Decrypt(theRawSymmetricKey, // The symmetric key, in clear form.
                                                // -------------------------------
                                                static_cast<const char *>(theCipherText.GetPayloadPointer()),  // This is the Ciphertext.
                                                theCipherText.GetSize(),
                                                // -------------------------------
                                                theIV,
                                                // -------------------------------
                                                thePlaintext); // OUTPUT. (Recovered plaintext.) You can pass OTPassword& OR OTPayload& here (either will work.)
    // -----------------------------------------------
    // theOutput is where we'll put the decrypted data.
    //
    theOutput.Release();
    
    if (bDecrypted)
    {
        // -----------------------------------------------------
        // Make sure it's null-terminated...
        //
        uint32_t nIndex = thePlaintext.GetSize()-1;
        (static_cast<uint8_t*>(const_cast<void *>(thePlaintext.GetPointer())))[nIndex] = '\0';
        
        // -----------------------------------------------------
        // Set it into theOutput (to return the plaintext to the caller)
        //
        theOutput.Set(static_cast<const char *>(thePlaintext.GetPointer()));
        // ----------------
    }
    
    return bDecrypted;
}

// ------------------------------------------------------------------------

// RSA / AES
//

bool OTEnvelope::Seal(const OTPseudonym & theRecipient, const OTString & theInput)
{
    setOfAsymmetricKeys   theKeys;
    theKeys.insert(const_cast<OTAsymmetricKey *>(&(theRecipient.GetPublicKey())));
    // -----------------------------
    return this->Seal(theKeys, theInput);
}
// --------------


bool OTEnvelope::Seal(setOfNyms & theRecipients, const OTString & theInput)
{
    setOfAsymmetricKeys RecipPubKeys;
    
    // Loop through theRecipients, and add the public key of each one to a set of keys.
    //
    FOR_EACH(setOfNyms, theRecipients)
    {
        OTPseudonym * pNym = *it;
		OT_ASSERT_MSG(NULL != pNym, "OTEnvelope::Seal: Assert: NULL pseudonym pointer.");
		// ------------------------------
        
        RecipPubKeys.insert(const_cast<OTAsymmetricKey *>(&(pNym->GetPublicKey())));
    }
    // --------------------------------
    if (0 == RecipPubKeys.size())
        return false;
    // --------------------------------
	return Seal(RecipPubKeys, theInput);
}


// ------------------------------------------------------------------------


bool OTEnvelope::Seal(const OTAsymmetricKey & RecipPubKey, const OTString & theInput)
{
    setOfAsymmetricKeys   theKeys;
    theKeys.insert(const_cast<OTAsymmetricKey *>(&RecipPubKey));
    // -----------------------------
    return this->Seal(theKeys, theInput);
}

//typedef std::set<OTPseudonym *>         setOfNyms;
//typedef std::set<OTAsymmetricKey *>	  setOfAsymmetricKeys;


// Seal up as envelope (Asymmetric, using public key and then AES key.)

bool OTEnvelope::Seal(setOfAsymmetricKeys & RecipPubKeys, const OTString & theInput)
{
    OT_ASSERT_MSG(RecipPubKeys.size() > 0, "OTEnvelope::Seal: ASSERT: RecipPubKeys.size() > 0");
    // -----------------------------------------------
    const char * szFunc = "OTEnvelope::Seal";
    // -----------------------------------------------
	EVP_CIPHER_CTX	 ctx;
    
	uint8_t	 buffer[4096];
    uint8_t	 buffer_out[4096 + EVP_MAX_IV_LENGTH];
    uint8_t	 iv[EVP_MAX_IV_LENGTH];
    
	uint32_t         len     = 0;
    int              len_out = 0;
    // -----------------------------------------------

	memset(buffer, 0, 4096);
	memset(buffer_out, 0, 4096 + EVP_MAX_IV_LENGTH);
	memset(iv, 0, EVP_MAX_IV_LENGTH);
    
    // -----------------------------------------------
    // The below three arrays are ALL allocated and then cleaned-up inside this fuction
    // (Using the below nested class, _OTEnv_Seal.) The first array will contain useful pointers, but we do NOT delete those.
    // The next array contains pointers that we DO need to cleanup.
    // The final array contains integers (sizes.)
    //
    EVP_PKEY      ** array_pubkey = NULL;  // These will be pointers we use, but do NOT need to clean-up.
    uint8_t       ** ek           = NULL;  // These we DO need to cleanup...
    int           *  eklen        = NULL;  // This will just be an array of integers.
    
    bool             bFinalized   = false; // If this is set true, then we don't bother to cleanup the ctx. (See the destructor below.)
    
    // -----------------------------------------------
    // This class is used as a nested function, for easier cleanup. (C++ doesn't directly support nested functions.)
    // Basically it translates the incoming RecipPubKeys into the low-level arrays
    // ek and eklen (that OpenSSL needs.) This also cleans up those same arrays, once 
    // this object destructs (when we leave scope of this function.)
    //
    class _OTEnv_Seal
    {
    private:
        const char                  *   m_szFunc;
        EVP_CIPHER_CTX              &   m_ctx;                  // reference to openssl cipher context.
        EVP_PKEY                    *** m_array_pubkey;         // pointer to array of public key pointers.
        uint8_t                     *** m_ek;                   // pointer to array of encrypted symmetric keys.
        int                         **  m_eklen;                // pointer to array of lengths for each encrypted symmetric key 
        setOfAsymmetricKeys         &   m_RecipPubKeys;         // array of public keys (to initialize the above members with.)
        int                             m_nLastPopulatedIndex;  // We store the highest-populated index (so we can free() up 'til the same index, in destructor.)
        bool                        &   m_bFinalized;
    public:
        _OTEnv_Seal(const char            * param_szFunc,
                    EVP_CIPHER_CTX        & theCTX,
                    EVP_PKEY            *** param_array_pubkey,
                    uint8_t             *** param_ek, 
                    int                  ** param_eklen,
                    setOfAsymmetricKeys   & param_RecipPubKeys,
                    bool                  & param_Finalized) :
            m_szFunc(param_szFunc),
            m_ctx(theCTX), 
            m_array_pubkey(NULL), 
            m_ek(NULL), 
            m_eklen(NULL), 
            m_RecipPubKeys(param_RecipPubKeys),
            m_nLastPopulatedIndex(-1),
            m_bFinalized(param_Finalized)
        {
            OT_ASSERT(NULL != param_szFunc);
            OT_ASSERT(NULL != param_array_pubkey);
            OT_ASSERT(NULL != param_ek);
            OT_ASSERT(NULL != param_eklen);
            OT_ASSERT(m_RecipPubKeys.size() > 0);
            // ----------------------------
            // Notice that each variable is a "pointer to" the actual array that was passed in.
            // (So use them that way, inside this class,
            //  like this:    *m_ek   and   *m_eklen )
            //
            m_array_pubkey = param_array_pubkey;
            m_ek           = param_ek;
            m_eklen        = param_eklen;
            // -----------------------------------------------
            // EVP_CIPHER_CTX_init() corresponds to: EVP_CIPHER_CTX_cleanup()
            // EVP_CIPHER_CTX_cleanup clears all information from a cipher context and free up any allocated 
            // memory associate with it. It should be called after all operations using a cipher are complete
            // so sensitive information does not remain in memory.
            //
            EVP_CIPHER_CTX_init(&m_ctx);
            
            // ----------------------------------------------
            // (*m_array_pubkey)[] array must have m_RecipPubKeys.size() no. of elements (each containing a pointer 
            // to an EVP_PKEY that we must NOT clean up.)
            //
            *m_array_pubkey = (EVP_PKEY **)malloc(m_RecipPubKeys.size() * sizeof(EVP_PKEY *));  
            OT_ASSERT(NULL != *m_array_pubkey);
            memset(*m_array_pubkey, 0, m_RecipPubKeys.size() * sizeof(EVP_PKEY *)); // size of array length * sizeof(pointer)
            // ----------------------------------------------
            // (*m_ek)[] array must have m_RecipPubKeys.size() no. of elements (each will contain a pointer from OpenSSL that we must clean up.)
            //
            *m_ek = (uint8_t**)malloc(m_RecipPubKeys.size() * sizeof(uint8_t*));  
            OT_ASSERT(NULL != *m_ek);
            memset(*m_ek, 0, m_RecipPubKeys.size() * sizeof(uint8_t*)); // size of array length * sizeof(pointer)
            // ----------------------------------------------
            // (*m_eklen)[] array must also have m_RecipPubKeys.size() no. of elements (each containing a size as integer.)
            //
            *m_eklen = static_cast<int *>(malloc(m_RecipPubKeys.size() * sizeof(int)));
            OT_ASSERT(NULL != *m_eklen);
            memset(*m_eklen, 0, m_RecipPubKeys.size() * sizeof(int)); // size of array length * sizeof(int)
            // ----------------------------------------------
            //
            // ABOVE is all just above allocating the memory and setting it to 0 / NULL.
            //
            // Whereas BELOW is about populating that memory, so the actual OTEnvelope::Seal() function can use it.
            //
            // -----------------------------------------------
            int nKeyIndex = -1; // it will be 0 upon first iteration.
            
            FOR_EACH(setOfAsymmetricKeys, m_RecipPubKeys)
            {
                ++nKeyIndex; // 0 on first iteration.
                m_nLastPopulatedIndex = nKeyIndex;
                // -------------------
                OTAsymmetricKey * pPublicKey = *it;
                OT_ASSERT(NULL != pPublicKey);
                // -------------------
                EVP_PKEY * public_key	= const_cast<EVP_PKEY *>(pPublicKey->GetKey());
                OT_ASSERT(NULL != public_key);
                // -------------------
                // Copy the public key pointer to an array of public key pointers...
                //
                (*m_array_pubkey)[nKeyIndex] = public_key; // For OpenSSL, it needs an array of ALL the public keys.
                // -------------------
                // We allocate enough space for the encrypted symmetric key to be placed
                // at this index (the space determined based on size of the public key that
                // the symmetric key will be encrypted to.) The space is left empty, for OpenSSL
                // to populate.
                //
                (*m_ek)[nKeyIndex] = (uint8_t*)malloc(EVP_PKEY_size(public_key));  // (*m_ek)[i] must have room for EVP_PKEY_size(pubk[i]) bytes. 
                OT_ASSERT(NULL != (*m_ek)[nKeyIndex]);
                memset((*m_ek)[nKeyIndex], 0, EVP_PKEY_size(public_key)); 
                // -------------------
            } // FOR_EACH(setOfAsymmetricKeys, m_RecipPubKeys)
            // -----------------------------------------------
        }
        // --------------------------------
        ~_OTEnv_Seal() // (destructor)
        {
            OT_ASSERT(NULL != m_array_pubkey);  // 1. pointer to an array of pointers to EVP_PKEY,
            OT_ASSERT(NULL != m_ek);            // 2. pointer to an array of pointers to encrypted symmetric keys
            OT_ASSERT(NULL != m_eklen);         // 3. pointer to an array storing the lengths of those keys.
            // -------------------------------
            // Iterate the array of encrypted symmetric keys, and free the key at each index...
            // 
            // We know how many there are, because each pointer will otherwise be NULL.
            // Plus we have m_nLastPopulatedIndex, which is obviously as far as we will go.
            //
            // -------------------------------
            int    nKeyIndex = -1; // it will be 0 upon first iteration.
            while (nKeyIndex < m_nLastPopulatedIndex) // if m_nLastPopulatedIndex is 0, then this loop will iterate ONCE, with nKeyIndex incrementing to 0 on the first line.
            {
                ++nKeyIndex; // 0 on first iteration.
                // --------------
                OT_ASSERT(NULL != (*m_ek)[nKeyIndex]);
                // --------------
                free((*m_ek)[nKeyIndex]);
                (*m_ek)[nKeyIndex] = NULL;
            }
            // -------------------------------
            //
            // Now free all of the arrays: 
            // 1. an array of pointers to EVP_PKEY, 
            // 2. an array of pointers to encrypted symmetric keys
            //    (those all being NULL pointers due to the above while-loop),
            //    and
            // 3. an array storing the lengths of those keys.
            //
            // -------------------------------
            if (NULL != *m_array_pubkey) // NOTE: The individual pubkeys are NOT to be cleaned up, but this array, containing pointers to those pubkeys, IS cleaned up.
                free(*m_array_pubkey); *m_array_pubkey = NULL;  m_array_pubkey = NULL;
            if (NULL != *m_ek)
                free(*m_ek);           *m_ek           = NULL;  m_ek           = NULL;
            if (NULL != *m_eklen)
                free(*m_eklen);        *m_eklen        = NULL;  m_eklen        = NULL;           
            // -------------------------------
  
            // EVP_CIPHER_CTX_cleanup returns 1 for success and 0 for failure.
            // EVP_EncryptFinal(), EVP_DecryptFinal() and EVP_CipherFinal() behave in a similar way to EVP_EncryptFinal_ex(), EVP_DecryptFinal_ex() and EVP_CipherFinal_ex() except ctx is automatically cleaned up after the call.
            //
            if (!m_bFinalized)
            {
                // We only clean this up here, if the "Final" Seal function didn't get called. (It normally
                // would have done this for us.)
                
                if (0 == EVP_CIPHER_CTX_cleanup(&m_ctx))
                    OTLog::vError("%s: Failure in EVP_CIPHER_CTX_cleanup. (It returned 0.)\n", m_szFunc);
            }
        }
        // -----------------------------------
    }; // class _OTEnv_Seal
    // ---------------------------------------------------------------------------------------------------------------
    
    // INSTANTIATE IT (This does all our setup on construction here, AND cleanup 
    // on destruction, whenever exiting this function.)
    
    _OTEnv_Seal local_RAII(szFunc, ctx, &array_pubkey, &ek, &eklen, RecipPubKeys, bFinalized);
 
    // --------------------------------
	// This is where the envelope final contents will be placed.
    // including the size of the encrypted symmetric key, the symmetric key
    // itself, the initialization vector, and the ciphertext.
    //
	m_dataContents.Release();
	
    // -----------------------------------------------
    const EVP_CIPHER * cipher_type = EVP_aes_128_cbc(); // todo hardcoding.
    // --------------------------
    /*
    int EVP_SealInit(EVP_CIPHER_CTX *ctx, const EVP_CIPHER *type,
                     unsigned char **ek,  int *ekl,
                     unsigned char *iv,
                     EVP_PKEY **pubk,     int npubk);
     
     -- ek is an array of buffers where the public-key-encrypted secret key will be written (for each recipient.)
     -- Each buffer must contain enough room for the corresponding encrypted key: that is,
            ek[i] must have room for EVP_PKEY_size(pubk[i]) bytes. 
     -- The actual size of each encrypted secret key is written to the array ekl. 
     -- pubk is an array of npubk public keys.
     */
    
//    EVP_PKEY      ** array_pubkey = NULL;  // These will be pointers we use, but do NOT need to clean-up.
//    unsigned char ** ek           = NULL;  // These we DO need to cleanup...
//    int           *  eklen        = NULL;  // This will just be an array of integers.
    // **********************************************************
    
    if (!EVP_SealInit(&ctx, cipher_type, 
                      ek,   eklen, // array of buffers for output of encrypted copies of the symmetric "session key". (Plus array of ints, to receive the size of each key.)
                      iv,          // A buffer where the generated IV is written. Must contain room for the corresponding cipher's IV, as determined by (for example) EVP_CIPHER_iv_length(type).
                      array_pubkey, RecipPubKeys.size())) // array of public keys we are addressing this envelope to.
    {
        OTLog::vError("%s: EVP_SealInit: failed.\n", szFunc);
		return false;
    }
    // -----------------------------------------------
    // Write the ENVELOPE TYPE (network order version.)
    //
    // 0 == Error
    // 1 == Asymmetric Key  (this function -- Seal / Open)
    // 2 == Symmetric Key   (other functions -- Encrypt / Decrypt use this.)
    // Anything else: error.
    
    uint16_t   temp_env_type = 1; // todo hardcoding.
    uint16_t   env_type_n    = static_cast<uint16_t>(htons( static_cast<uint16_t>(temp_env_type) )); // Calculate "network-order" version of envelope type 1.
    
    m_dataContents.Concatenate(reinterpret_cast<void *>(&env_type_n),   
                               static_cast<uint32_t>(sizeof(env_type_n))); 
    // ------------------------------------------------------------
    // Write the ARRAY SIZE (network order version.)
    
    uint32_t   array_size_n = static_cast<uint32_t>(htonl(static_cast<uint32_t>(RecipPubKeys.size()))); // Calculate "network-order" version of array size.
    
    m_dataContents.Concatenate(reinterpret_cast<void *>(&array_size_n),   
                               static_cast<uint32_t>(sizeof(array_size_n))); 
    // ------------------------------------------------------------

    OTLog::vOutput(5, "%s: Envelope type:  %d    Array size: %ld\n", __FUNCTION__,
                   static_cast<int>(ntohs(env_type_n)),
                   static_cast<long>(ntohl(array_size_n))
                   );
    
    // ------------------------------------------------------------
    OT_ASSERT(NULL != ek);
    OT_ASSERT(NULL != eklen);
    // -----------------
    // Loop through the encrypted symmetric keys, and for each, write its 
    // network-order NymID size, and its NymID, and its network-order content size,
    // and its content, to the envelope data contents
    // (that we are currently building...)
    //
    int32_t ii = -1; // it will be 0 upon first iteration.
    
    FOR_EACH(setOfAsymmetricKeys, RecipPubKeys)
    {
        ++ii; // 0 on first iteration.
        // -------------------
        OTAsymmetricKey * pPublicKey = *it;
        OT_ASSERT(NULL != pPublicKey);
        // -------------------
        OTIdentifier theNymID;
        bool bCalculatedID = pPublicKey->CalculateID(theNymID); // Only works for public keys.
        
        if (false == bCalculatedID)
        {
            OTLog::vError("%s: Error trying to calculate ID of recipient.\n", szFunc);
            return false;
        }
        // -------------------------
        const OTString strNymID(theNymID);
        
        uint32_t    nymid_len   = static_cast<uint32_t>(strNymID.GetLength()+1); // +1 for null terminator.
        uint32_t    nymid_len_n = static_cast<uint32_t>(htonl(nymid_len)); // Calculate "network-order" version of length (+1 for null terminator)

        // Write nymid_len_n and strNymID for EACH encrypted symmetric key.
        //
        m_dataContents.Concatenate(reinterpret_cast<void *>(&nymid_len_n),   
                                   static_cast<uint32_t>(sizeof(nymid_len_n))); 
        
        m_dataContents.Concatenate(reinterpret_cast<const void *>(strNymID.Get()),         
                                   static_cast<uint32_t>(nymid_len)); // (+1 for null terminator is included here already, from above.)
        // -----------------------------------------
        OTLog::vOutput(5, "%s: INDEX: %ld  NymID length:  %ld   Nym ID: %s   Strlen (should be a byte shorter): %ld\n", __FUNCTION__,
                       static_cast<long>(ii),
                       static_cast<long>(ntohl(nymid_len_n)),
                       strNymID.Get(), 
                       static_cast<long>(strNymID.GetLength())
                       );
        

        // **********************************
        
//      Write eklen_n and ek for EACH encrypted symmetric key, 
//        
//        EVP_PKEY      ** array_pubkey = NULL;  // These will be pointers we use, but do NOT need to clean-up.
//        unsigned char ** ek           = NULL;  // These we DO need to cleanup...
//        int           *  eklen        = NULL;  // This will just be an array of integers.

        // --------------------------
        OT_ASSERT(NULL != ek[ii]); // assert key pointer not null.
        OT_ASSERT(eklen[ii] > 0);  // assert key length larger than 0.
        // -----------------
        uint32_t    eklen_n = static_cast<uint32_t>(htonl(static_cast<uint32_t>(eklen[ii]))); // Calculate "network-order" version of length.
        // -----------------        
        m_dataContents.Concatenate(reinterpret_cast<void *>(&eklen_n),   
                                   static_cast<uint32_t>(sizeof(eklen_n))); 
        
        m_dataContents.Concatenate(reinterpret_cast<void *>(ek[ii]),         
                                   static_cast<uint32_t>(eklen[ii]));
        
        OTLog::vOutput(5, "%s: EK length:  %ld     First byte: %d      Last byte: %d\n", __FUNCTION__,
                       static_cast<long>(ntohl(eklen_n)),
                       static_cast<int>((ek[ii])[0]),
                       static_cast<int>((ek[ii])[eklen[ii]-1])
                       );
        

        // -------------------
    } // FOR_EACH(setOfAsymmetricKeys, m_RecipPubKeys)
    // -----------------------------------------------
    //
    // Write IV size before then writing IV itself.
    //
    uint32_t       ivlen   = static_cast<uint32_t>(EVP_CIPHER_iv_length(cipher_type)); // Length of IV for this cipher... (TODO: add cipher name to output, and use it for looking up cipher upon Open.)
//  OT_ASSERT(ivlen > 0);
    uint32_t  ivlen_n = static_cast<uint32_t>(htonl(static_cast<uint32_t>(ivlen))); // Calculate "network-order" version of iv length.

	m_dataContents.Concatenate(reinterpret_cast<void *>(&ivlen_n),   
                               static_cast<uint32_t>(sizeof(ivlen_n)));
	
	m_dataContents.Concatenate(reinterpret_cast<void *>(iv), 
                               static_cast<uint32_t>(ivlen));

    
    OTLog::vOutput(5, "%s: iv_size: %ld   IV first byte: %d    IV last byte: %d   \n", 
                   __FUNCTION__, 
                   static_cast<long>(ntohl(ivlen_n)),
                   static_cast<int>(iv[0]),
                   static_cast<int>(iv[ivlen-1])
                   );

    // -----------------------------------------------
	// Next we put the plaintext into a data object so we can process it via EVP_SealUpdate,
    // in blocks, into encrypted form in m_dataContents. Each iteration of the loop processes
    // one block.
    //
	OTData plaintext(static_cast<const void*>(theInput.Get()), theInput.GetLength()+1); // +1 for null terminator
	
    // -----------------------------------------------
    // Now we process the input and write the encrypted data to the
	// output.
	//
    while (0 < (len = plaintext.OTfread(reinterpret_cast<uint8_t*>(buffer), 
                                        static_cast<uint32_t>(sizeof(buffer)))))
    {
        if (!EVP_SealUpdate(&ctx, buffer_out, &len_out, buffer, static_cast<int>(len)))
        {
            OTLog::vError("%s: EVP_SealUpdate failed.\n", szFunc);
			return false;
        }
        // -------------------
        else if (len_out > 0)
            m_dataContents.Concatenate(reinterpret_cast<void *>(buffer_out), 
                                       static_cast<uint32_t>(len_out));
        else break;
	}
    // -----------------------------------------------

    if (!EVP_SealFinal(&ctx, buffer_out, &len_out))
    {
        OTLog::vError("%s: EVP_SealFinal failed.\n", szFunc);
		return false;
    }
    // This is the "final" piece that is added from SealFinal just above.
    //
    else if (len_out > 0)
    {
        bFinalized = true;
        m_dataContents.Concatenate(reinterpret_cast<void *>(buffer_out), 
                                   static_cast<uint32_t>(len_out));
    }
    else
        bFinalized = true;

    // -----------------------------------------------
    
    return true;
}







/*
#include <openssl/evp.h>
int EVP_OpenInit(EVP_CIPHER_CTX *ctx,EVP_CIPHER *type,unsigned char *ek,
				 int ekl,unsigned char *iv,EVP_PKEY *priv);
int EVP_OpenUpdate(EVP_CIPHER_CTX *ctx, unsigned char *out,
				   int *outl, unsigned char *in, int inl);
int EVP_OpenFinal(EVP_CIPHER_CTX *ctx, unsigned char *out,
				  int *outl);
DESCRIPTION

The EVP envelope routines are a high level interface to envelope decryption. They decrypt a public key 
 encrypted symmetric key and then decrypt data using it.

 int EVP_OpenInit(EVP_CIPHER_CTX *ctx,EVP_CIPHER *type,unsigned char *ek, int ekl,unsigned char *iv,EVP_PKEY *priv);
EVP_OpenInit() initializes a cipher context ctx for decryption with cipher type. It decrypts the encrypted 
 symmetric key of length ekl bytes passed in the ek parameter using the private key priv. The IV is supplied 
 in the iv parameter.

EVP_OpenUpdate() and EVP_OpenFinal() have exactly the same properties as the EVP_DecryptUpdate() and 
 EVP_DecryptFinal() routines, as documented on the EVP_EncryptInit(3) manual page.

NOTES

It is possible to call EVP_OpenInit() twice in the same way as EVP_DecryptInit(). The first call should have 
 priv set to NULL and (after setting any cipher parameters) it should be called again with type set to NULL.

If the cipher passed in the type parameter is a variable length cipher then the key length will be set to the 
value of the recovered key length. If the cipher is a fixed length cipher then the recovered key length must 
match the fixed cipher length.

RETURN VALUES

EVP_OpenInit() returns 0 on error or a non zero integer (actually the recovered secret key size) if successful.

EVP_OpenUpdate() returns 1 for success or 0 for failure.

EVP_OpenFinal() returns 0 if the decrypt failed or 1 for success.
*/


// DONE: Fix OTEnvelope so we can seal to multiple recipients simultaneously.
// TODO: Fix OTEnvelope so it supports symmetric crypto as well as asymmetric.

// TODO: Make sure OTEnvelope is safe with zeroing memory wherever needed.

// TODO: Might want to remove the Nym stored inside the purse, and replace with a 
// session key, just as envelopes will support a session key.


//Todo: Once envelopes support multiple recipient Nyms, then make a habit of encrypting
// to the user's key AND server's key, when sending.

// Hmm this might be better than a session key, since we don't have to worry about keeping track
// of the session key for LATER, since envelopes generate a session key already.
// BUT: That means we do it already, and that means we wouldn't get any speed benefit.
// Transport protocol should have session key already built-in -- hmm what if going over email or
// some insecure channel?
// Solution: Make it always encrypted to public key (as it already is now) with session key automatically
// (as already) by virtue of using OpenSSL envelope. This will, of course, generate a new session key for
// EACH envelope, so we will STILL add the protocol of initiating sessions, purely to reduce CPU cycles
// during each session. This means we'll have the same protocol as before but just faster (in a way.)
// 


// RSA / AES

bool OTEnvelope::Open(const OTPseudonym & theRecipient, OTString & theOutput)
{
    const char * szFunc = "OTEnvelope::Open";    
	// ------------------------------------------------
    uint8_t	buffer[4096];
    uint8_t	buffer_out[4096 + EVP_MAX_IV_LENGTH];
    uint8_t	iv[EVP_MAX_IV_LENGTH];

    uint32_t		len     = 0;
    int             len_out = 0;
    
    bool            bFinalized = false;  // We only clean up the ctx if the Open "Final" function hasn't been called, since it does that automatically already.
	// ------------------------------------------------
    
	memset(buffer, 0, 4096);
	memset(buffer_out, 0, 4096 + EVP_MAX_IV_LENGTH);
	memset(iv, 0, EVP_MAX_IV_LENGTH);

    // ------------------------------------------------
    // theOutput is where we'll put the decrypted result.
    //
    theOutput.Release();	
    // ------------------------------------------------
    // Grab the NymID of the recipient, so we can find his session
    // key (there might be symmetric keys for several Nyms, not just this
    // one, and we need to find the right one in order to perform this Open.)
    //
    OTString  strNymID;
    theRecipient.GetIdentifier(strNymID);
    // ------------------------------------------------
	OTAsymmetricKey &	privateKey	= const_cast<OTAsymmetricKey &>(theRecipient.GetPrivateKey());
	EVP_PKEY *			private_key = const_cast<EVP_PKEY *>(privateKey.GetKey());
	
	if (NULL == private_key)
	{
		OTLog::vError("%s: Null private key on recipient. (Returning false.)\n", szFunc);
		return false;
	}
    else
        OTLog::vOutput(5, "%s: Private key is available for NymID: %s \n", __FUNCTION__,
                       strNymID.Get()
                       );
    // ------------------------------------------------
    EVP_CIPHER_CTX	ctx;
    // ----------------------------------------------
    class _OTEnv_Open
    {
    private:
        const char        *   m_szFunc;
        EVP_CIPHER_CTX    &   m_ctx;        // reference to openssl cipher context.
        OTAsymmetricKey   &   m_privateKey; // reference to OTAsymmetricKey object.
        bool              &   m_bFinalized;
    public:
        // ------------------------
        _OTEnv_Open(const char       * param_szFunc,
                    EVP_CIPHER_CTX   & theCTX,
                    OTAsymmetricKey  & param_privateKey,
                    bool             & param_Finalized) :
            m_szFunc(param_szFunc),
            m_ctx(theCTX),
            m_privateKey(param_privateKey),
            m_bFinalized(param_Finalized)
        {
            OT_ASSERT(NULL != param_szFunc);

            EVP_CIPHER_CTX_init(&m_ctx);
        }
        // ------------------------
        ~_OTEnv_Open()  // DESTRUCTOR
        {
            m_privateKey.ReleaseKey();
            //
            // BELOW this point, private_key (which is a member of m_privateKey is either
            // cleaned up, or kept based on a timer value. (It MAY not be cleaned up,
            // depending on its state.)
            
            
            // EVP_CIPHER_CTX_cleanup returns 1 for success and 0 for failure.
            //
            if (!m_bFinalized)
            {
                if (0 == EVP_CIPHER_CTX_cleanup(&m_ctx))
                    OTLog::vError("%s: Failure in EVP_CIPHER_CTX_cleanup. (It returned 0.)\n", m_szFunc);
			}
            
			m_szFunc = NULL;
        }
    };
    // ------------------------------------------------
    // INSTANTIATE the clean-up object.
    //            
    _OTEnv_Open     theNestedInstance(szFunc, ctx, privateKey, bFinalized);
    //
    // ------------------------------------------------
    //
	m_dataContents.reset(); // Reset the fread position on this object to 0.
	
    uint32_t nRunningTotal  = 0; // Everytime we read something, we add the length to this variable.
    
	uint32_t nReadEnvType   = 0;
	uint32_t nReadArraySize = 0;
	uint32_t nReadIV        = 0;
	// ----------------------------------------------------------------------------
    //
    // Read the ARRAY SIZE (network order version -- convert to host version.)
    // -----------------
    // Loop through the array of encrypted symmetric keys, and for each:
    //      read its network-order NymID size (convert to host version), and then read its NymID,
    //      read its network-order key content size (convert to host), and then read its key content,
    // -----------------
    //
    // Read network-order IV size (convert to host version) before then reading IV itself.
    // (Then update encrypted blocks until evp open final...)
    //
    // --------------------------------------------------
    
    // So here we go...
    
    // ****************************************************************************
    //
    // Read the ENVELOPE TYPE (as network order version -- and convert to host version.)
    //
    // 0 == Error
    // 1 == Asymmetric Key  (this function -- Seal / Open)
    // 2 == Symmetric Key   (other functions -- Encrypt / Decrypt use this.)
    // Anything else: error.
    //
    uint16_t  env_type_n = 0;
    
    if (0 == (nReadEnvType = m_dataContents.OTfread(reinterpret_cast<uint8_t*>(&env_type_n), 
                                                    static_cast<uint32_t>(sizeof(env_type_n)))))
	{
		OTLog::vError("%s: Error reading Envelope Type. Expected asymmetric(1) or symmetric (2).\n", szFunc);
		return false;
	}
    nRunningTotal += nReadEnvType;
    OT_ASSERT(nReadEnvType == static_cast<uint32_t>(sizeof(env_type_n)));
    // ----------------------------------------------------------------------------
	// convert that envelope type from network to HOST endian.
    //
    const uint16_t env_type = static_cast<uint16_t>(ntohs(static_cast<uint16_t>(env_type_n)));
//  nRunningTotal += env_type;    // NOPE! Just because envelope type is 1 or 2, doesn't mean we add 1 or 2 extra bytes to the length here. Nope!
    

    if (1 != env_type)
	{
		OTLog::vError("%s: Error: Expected Envelope for Asymmetric key (type 1) but instead found type %d.\n", 
                      szFunc, static_cast<int>(env_type));
        print_stacktrace();
		return false;
	}
    else
        OTLog::vOutput(5, "%s: Envelope type: %d\n", __FUNCTION__,
                       static_cast<int>(env_type)
                       );

    // ****************************************************************************
    //
    // Read the ARRAY SIZE (network order version -- convert to host version.)
    //
    uint32_t	array_size_n = 0;
    
    if (0 == (nReadArraySize = m_dataContents.OTfread(reinterpret_cast<uint8_t*>(&array_size_n), 
                                                      static_cast<uint32_t>(sizeof(array_size_n)))))
	{
		OTLog::vError("%s: Error reading Array Size for encrypted symmetric keys.\n", szFunc);
		return false;
	}
    nRunningTotal += nReadArraySize;
    OT_ASSERT(nReadArraySize == static_cast<uint32_t>(sizeof(array_size_n)));
    // ----------------------------------------------------------------------------
	// convert that array size from network to HOST endian.
    //
    const uint32_t array_size = ntohl(array_size_n);
    
    OTLog::vOutput(5, "%s: Array size: %ld\n", __FUNCTION__,
                   static_cast<long>(array_size)
                   );
    
//  nRunningTotal += array_size;    // NOPE! Just because there are 10 array elements doesn't mean I want to add "10" here to the running total!! Not logical.
    // ****************************************************************************
    //
    // We are going to loop through all the keys and load each up (then delete.)
    // Each one is proceeded by its length. 
    // IF we find the one we are looking for, then we set it onto this variable,
    // theRawEncryptedKey, so we have it available below this loop.
    //
    OTPayload  theRawEncryptedKey;
    bool       bFoundKeyAlready = false; // If we find it during the loop below, we'll set this to true.
    // ----------------------------------------------------------------------------
    // Loop through as we read the encrypted symmetric keys, and for each:
    //      read its network-order NymID size (convert to host version), and then read its NymID,
    //      read its network-order key content size (convert to host), and then read its key content,
    // 
    for (uint32_t ii = 0; ii < array_size; ++ii)
    {
        // ****************************************************************************
        //
        // Loop through the encrypted symmetric keys, and for each:
        //      read its network-order NymID size (convert to host version), and then read its NymID,
        //      read its network-order key content size (convert to host), and then read its key content.
        // -----------------
        //
        uint32_t	nymid_len_n    = 0;
        uint32_t    nReadNymIDSize = 0;
        
        if (0 == (nReadNymIDSize = m_dataContents.OTfread(reinterpret_cast<uint8_t*>(&nymid_len_n), 
                                                          static_cast<uint32_t>(sizeof(nymid_len_n)))))
        {
            OTLog::vError("%s: Error reading NymID length for an encrypted symmetric key.\n", szFunc);
            return false;
        }
        nRunningTotal += nReadNymIDSize;
        OT_ASSERT(nReadNymIDSize == static_cast<uint32_t>(sizeof(nymid_len_n)));
        // ----------------------------------------------------------------------------
        // convert that array size from network to HOST endian.
        //
        uint32_t nymid_len = static_cast<uint32_t>(ntohl(static_cast<uint32_t>(nymid_len_n)));    // FYI: ntohl returns uint32_t !!!!!
        
        
        OTLog::vOutput(5, "%s: NymID length: %ld\n", __FUNCTION__,
                       static_cast<long>(nymid_len)
                       );

        
//      nRunningTotal += nymid_len; // Nope!
        // ----------------------------------------------------------------------------
        uint8_t * nymid = static_cast<uint8_t *>(malloc(sizeof(uint8_t) * nymid_len));
        OT_ASSERT(NULL != nymid);
        nymid[0] = '\0'; // null terminator.
        
        uint32_t  nReadNymID = 0;
        
        if (0 == (nReadNymID = m_dataContents.OTfread(reinterpret_cast<uint8_t *>(nymid), 
                                                      static_cast<uint32_t>(sizeof(uint8_t) * nymid_len)))) // this length includes the null terminator (it was written that way.)
        {
            OTLog::vError("%s: Error reading NymID for an encrypted symmetric key.\n", szFunc);
            free(nymid); nymid = NULL;
            return false;
        }
        nRunningTotal += nReadNymID;
        OT_ASSERT(nReadNymID == static_cast<uint32_t>(sizeof(uint8_t) * nymid_len));
//      OT_ASSERT(nymid_len == nReadNymID);
        // ----------------------------------------------------------------------------
        nymid[nymid_len-1] = '\0'; // for null terminator. If string is 10 bytes long, it's from 0-9, and the null terminator is at index 9.
        const OTString loopStrNymID(reinterpret_cast<char *>(nymid));
        free(nymid); nymid = NULL;
        // ****************************************************************************
        
        
        OTLog::vOutput(5, "%s: (LOOP) Current NymID: %s    Strlen:  %ld\n", __FUNCTION__,
                       loopStrNymID.Get(),
                       static_cast<long>(loopStrNymID.GetLength())
                       );
        //
        // loopStrNymID ... if this matches strNymID then it's the one we're looking for.
        // But we have to load it all either way, just to iterate through them, so might
        // as well load it all first, then check. If it matches, we use it and break.
        // Otherwise we keep iterating until we find it.
        //
        // ----------------------------------------------------------------------------
        
        // Read its network-order key content size (convert to host-order), and then 
        // read its key content.

        uint8_t      *	ek          = NULL;
        uint32_t		eklen       = 0;
        uint32_t		eklen_n     = 0;
        uint32_t        nReadLength = 0;
        uint32_t        nReadKey    = 0;
        // ----------------------------------------------------------------------------
        // First we read the encrypted key size.
        //
        if (0 == (nReadLength = m_dataContents.OTfread(reinterpret_cast<uint8_t *>(&eklen_n), 
                                                       static_cast<uint32_t>(sizeof(eklen_n)))))
        {
            OTLog::vError("%s: Error reading encrypted key size.\n", szFunc);
            return false;
        }
        nRunningTotal += nReadLength;
        OT_ASSERT(nReadLength == static_cast<uint32_t>(sizeof(eklen_n)));
        // ----------------------------------------------------------------------------
        // convert that key size from network to host endian.
        //
        eklen  = static_cast<uint32_t>(ntohl(static_cast<uint32_t>(eklen_n)));
//      eklen  = EVP_PKEY_size(private_key);  // We read this size from file now...
        
        OTLog::vOutput(5, "%s: EK length:  %ld   \n", __FUNCTION__,
                       static_cast<long>(eklen));

        
//      nRunningTotal += eklen;  // Nope!
        // ----------------------------------------------------------------------------
        ek     = static_cast<uint8_t*>(malloc(static_cast<int>(eklen) * sizeof(uint8_t)));  // I assume this is for the AES key
        OT_ASSERT(NULL != ek);
        memset(static_cast<void *>(ek), 0, static_cast<int>(eklen));
        // ----------------------------------------------------------------------------
        // Next we read the encrypted key itself...
        //
        if (0 == (nReadKey = m_dataContents.OTfread(reinterpret_cast<uint8_t*>(ek), 
                                                    static_cast<uint32_t>(eklen))))
        {
            OTLog::vError("%s: Error reading encrypted key.\n", szFunc);
            free(ek); ek = NULL;
            return false;
        }
        nRunningTotal += nReadKey;
        
        OTLog::vOutput(5, "%s:    EK First byte: %d     EK Last byte: %d\n", __FUNCTION__,
                       static_cast<int>(ek[0]),
                       static_cast<int>(ek[eklen-1])
                       );

        
        OT_ASSERT(nReadKey == static_cast<uint32_t>(eklen));
        // ****************************************************************************
        //
        // If we "found the key already" that means we already found the right key on
        // a previous iteration, so therefore we're *definitely* just going to throw
        // THIS one away. We just continue on to the next iteration and keep counting
        // the bytes.
        //
        if (false == bFoundKeyAlready)
        {
            // We have NOT found the right key yet, so let's see if this is the one we're looking for.
            
            if (strNymID.Compare(loopStrNymID)) // FOUND IT! <==========
            {
                bFoundKeyAlready = true;
                
                theRawEncryptedKey.Assign(static_cast<void *>(ek), static_cast<uint32_t>(eklen));
//              theRawEncryptedKey.Assign(const_cast<const void *>(static_cast<void *>(ek)), eklen);
            }
        }        
        
        free(ek); ek = NULL;
        
    } // for
    // ------------------------------------------------------------------
    
    if (false == bFoundKeyAlready)
    {
        OTLog::vOutput(0, "%s: Sorry: Unable to find a session key for the Nym attempting to open this envelope.\n",
                       szFunc);
        return false;
    }
    
    // ****************************************************************************
    //
    // Read network-order IV size (convert to host version) before then reading IV itself.
    // (Then update encrypted blocks until evp open final...)
    //
    // --------------------------------------------------
    //    
    const uint32_t max_iv_length = OT_DEFAULT_SYMMETRIC_IV_SIZE; // I believe this is a max length, so it may not match the actual length.

    // Read the IV SIZE (network order version -- convert to host version.)
    //
    uint32_t	iv_size_n   = 0;
    uint32_t    nReadIVSize = 0;

    if (0 == (nReadIVSize = m_dataContents.OTfread(reinterpret_cast<uint8_t*>(&iv_size_n), 
                                                   static_cast<uint32_t>(sizeof(iv_size_n)))))
	{
		OTLog::vError("%s: Error reading IV Size for encrypted symmetric keys.\n", szFunc);
		return false;
	}
    nRunningTotal += nReadIVSize;    
    OT_ASSERT(nReadIVSize == static_cast<uint32_t>(sizeof(iv_size_n)));
    // ----------------------------------------------------------------------------
	// convert that iv size from network to HOST endian.
    //
    const uint32_t iv_size_host_order = ntohl(static_cast<uint32_t>(iv_size_n));
        
    if (iv_size_host_order > max_iv_length)
    {
        const long l1 = iv_size_host_order, l2 = max_iv_length;
        OTLog::vError("%s: Error: iv_size (%ld) is larger than max_iv_length (%ld).\n",
                      __FUNCTION__, l1, l2);
        return false;
    }
    else
        OTLog::vOutput(5, "%s: IV size: %ld\n", __FUNCTION__,
                       static_cast<long>(iv_size_host_order)
                       );

    // ****************************************************************************
    //
    // Then read the IV (initialization vector) itself.
    //
    if (0 == (nReadIV = m_dataContents.OTfread(reinterpret_cast<uint8_t*>(iv), 
                                               static_cast<uint32_t>(iv_size_host_order))))
    {
        OTLog::vError("%s: Error reading initialization vector.\n", szFunc);
        return false;
    }
    
    nRunningTotal += nReadIV;
    OT_ASSERT(nReadIV == static_cast<uint32_t>(iv_size_host_order));
	// ----------------------------------------------------------------------------
    
    OTLog::vOutput(5, "%s:    IV First byte: %d     IV Last byte: %d\n", __FUNCTION__,
                   static_cast<int>   (iv[0]),
                   static_cast<int>   (iv[iv_size_host_order-1])
                   );

    // We read the encrypted key size, then we read the encrypted key itself, with nReadKey containing
    // the number of bytes actually read. The IF statement says "if 0 ==" but it should probably say
    // "if eklen !=" (right?) Wrong: because I think it's a max length.
    //
    // We create an OTData object to store the ciphertext itself, which begins AFTER the end of the IV.
    // So we see pointer + nRunningTotal as the starting point for the ciphertext.
    // the size of the ciphertext, meanwhile, is the size of the entire thing, MINUS nRunningTotal.
    //
	OTData ciphertext(static_cast<const void*>( 
                                         static_cast<const uint8_t *>(m_dataContents.GetPointer()) + nRunningTotal
                                         ), 
					  m_dataContents.GetSize() - nRunningTotal);
    // ------------------------------------------------
    //
    const EVP_CIPHER * cipher_type = EVP_aes_128_cbc();  // todo hardcoding.
    //
    //  OTPayload
    //  void   SetPayloadSize   (uint32_t lNewSize);
    //	const
    //  void * GetPayloadPointer() const;
    
    //  OTData
    //  inline 
    //  uint32_t	 GetSize    () const { return m_lSize; } 
    //	bool         IsEmpty    () const;
    //  virtual void Release    ();
    //	void         Assign     (const void * pNewData, uint32_t lNewSize);
    //	void         Concatenate(const void * pNewData, uint32_t lNewSize);
    // ----------------------------------------------
    //
	if (!EVP_OpenInit(&ctx, cipher_type,
                      static_cast<const unsigned char *>(theRawEncryptedKey.GetPayloadPointer()),
                      static_cast<int>(theRawEncryptedKey.GetSize()),
                      static_cast<const unsigned char *>(iv),
                      private_key))
//  if (!EVP_OpenInit(&ctx, cipher_type, ek, eklen, iv, private_key))
    {
        // int EVP_OpenInit(
        //          EVP_CIPHER_CTX *ctx,
        //          EVP_CIPHER *type,
        //          unsigned char *ek, 
        //          int ekl,
        //          unsigned char *iv,
        //          EVP_PKEY *priv);
        
        //EVP_OpenInit() initializes a cipher context ctx for decryption with cipher type. It decrypts the encrypted 
        //	symmetric key of length ekl bytes passed in the ek parameter using the private key priv. The IV is supplied 
        //	in the iv parameter.

        OTLog::vError("%s: EVP_OpenInit: failed.\n", szFunc);
		return false;
    }
    
    // ----------------------------------------------------------------------------
	// Now we process ciphertext and write the decrypted data to plaintext.
    //
	OTData plaintext;

    // We loop through the ciphertext and process it in blocks...
    //
    while (0 < (len = ciphertext.OTfread(reinterpret_cast<uint8_t*>(buffer), 
                                     static_cast<uint32_t>(sizeof(buffer)))))
    {
        if (!EVP_OpenUpdate(&ctx, buffer_out, &len_out, buffer, static_cast<int>(len)))
        {
            OTLog::vError("%s: EVP_OpenUpdate: failed.\n", szFunc);
            return false;
        }
        else if (len_out > 0)
            plaintext.Concatenate(reinterpret_cast<void *>(buffer_out), 
                                  static_cast<uint32_t>(len_out));
        else break;
	}
    // -----------------------------------------------------    

    if (!EVP_OpenFinal(&ctx, buffer_out, &len_out))
    {
		OTLog::vError("%s: EVP_OpenFinal: failed.\n", szFunc);
		return false;
    }
    else if (len_out > 0)
    {
        bFinalized = true;
        plaintext.Concatenate(reinterpret_cast<void *>(buffer_out), 
                              static_cast<uint32_t>(len_out));
        
    }
    else
        bFinalized = true;

    // -----------------------------------------------------    

    
	// Make sure it's null-terminated...
    //
	uint32_t nIndex = plaintext.GetSize()-1; // null terminator is already part of length here (it was sealed that way.)
	(static_cast<uint8_t*>(const_cast<void*>(plaintext.GetPointer())))[nIndex] = '\0';
	
    // -----------------------------------------------------
	// Set it into theOutput (to return the plaintext to the caller)
    //
	theOutput.Set(static_cast<const char *>(plaintext.GetPointer()), plaintext.GetSize());
    
    OTLog::vOutput(5, "%s: Output:\n\n%s\n\n", __FUNCTION__, theOutput.Get());

    // ----------------
    return true;
}














// NOTHING INTERESTING BELOW THIS POINT












/*
int do_evp_seal(FILE *rsa_pkey_file, FILE *in_file, FILE *out_file)
{
    int retval = 0;
    RSA *rsa_pkey = NULL;
    EVP_PKEY *pkey = EVP_PKEY_new();
    EVP_CIPHER_CTX ctx;
    unsigned char buffer[4096];
    unsigned char buffer_out[4096 + EVP_MAX_IV_LENGTH];
    size_t len;
    int len_out;
    unsigned char *ek;
    int eklen;
    uint32_t eklen_n;
    unsigned char iv[EVP_MAX_IV_LENGTH];
	
    if (!PEM_read_RSA_PUBKEY(rsa_pkey_file, &rsa_pkey, OTAsymmetricKey::GetPasswordCallback(), NULL))
    {
        OTLog::Error("Error loading RSA Public Key File.\n");
        ERR_print_errors_fp(stderr);
        retval = 2;
        goto out;
    }
	
    if (!EVP_PKEY_assign_RSA(pkey, rsa_pkey))
    {
        OTLog::Error("EVP_PKEY_assign_RSA: failed.\n");
        retval = 3;
        goto out;
    }
	
    EVP_CIPHER_CTX_init(&ctx);
    ek = malloc(EVP_PKEY_size(pkey));
	
    if (!EVP_SealInit(&ctx, EVP_aes_128_cbc(), &ek, &eklen, iv, &pkey, 1))
    {
        OTLog::Error("EVP_SealInit: failed.\n");
        retval = 3;
        goto out_free;
    }
	
    // First we write out the encrypted key length, then the encrypted key,
     / then the iv (the IV length is fixed by the cipher we have chosen).
     
	
    eklen_n = htonl(eklen);
    if (fwrite(&eklen_n, sizeof eklen_n, 1, out_file) != 1)
    {
        perror("output file");
        retval = 5;
        goto out_free;
    }
    if (fwrite(ek, eklen, 1, out_file) != 1)
    {
        perror("output file");
        retval = 5;
        goto out_free;
    }
    if (fwrite(iv, EVP_CIPHER_iv_length(EVP_aes_128_cbc()), 1, out_file) != 1)
    {
        perror("output file");
        retval = 5;
        goto out_free;
    }
	
    // Now we process the input file and write the encrypted data to the
	//output file.
	
    while ((len = fread(buffer, 1, sizeof buffer, in_file)) > 0)
    {
        if (!EVP_SealUpdate(&ctx, buffer_out, &len_out, buffer, len))
        {
            OTLog::Error("EVP_SealUpdate: failed.\n");
            retval = 3;
            goto out_free;
        }
		
        if (fwrite(buffer_out, len_out, 1, out_file) != 1)
        {
            perror("output file");
            retval = 5;
            goto out_free;
        }
    }
	
    if (ferror(in_file))
    {
        perror("input file");
        retval = 4;
        goto out_free;
    }
	
    if (!EVP_SealFinal(&ctx, buffer_out, &len_out))
    {
        OTLog::Error("EVP_SealFinal: failed.\n");
        retval = 3;
        goto out_free;
    }
	
    if (fwrite(buffer_out, len_out, 1, out_file) != 1)
    {
        perror("output file");
        retval = 5;
        goto out_free;
    }
	
out_free:
    EVP_PKEY_free(pkey);
    free(ek);
	
out:
    return retval;
}

int main(int argc, char *argv[])
{
    FILE *rsa_pkey_file;
    int rv;
	
    if (argc < 2)
    {
        OTLog::vOutput(0, "Usage: %s <PEM RSA Public Key File>\n", argv[0]);
        exit(1);
    }
	
    rsa_pkey_file = fopen(argv[1], "rb");
    if (!rsa_pkey_file)
    {
        perror(argv[1]);
        OTLog::Error("Error loading PEM RSA Public Key File.\n");
        exit(2);
    }
	
    rv = do_evp_seal(rsa_pkey_file, stdin, stdout);
	
    fclose(rsa_pkey_file);
    return rv;
}
*/


// We just read some encrypted (and armored) data, and we want to put it in
// an envelope so that it can be opened. So we can just directly set the
// armored string here, and it will be decoded into the original binary,
// inside this envelope. That way we can decrypt it (symmetric), or open it
// (asymmetric) and get the original plaintext that was sent.
//
OTEnvelope::OTEnvelope(const OTASCIIArmor & theArmoredText)
{
	SetAsciiArmoredData(theArmoredText);
}

OTEnvelope::OTEnvelope()
{
	
}

OTEnvelope::~OTEnvelope()
{
	
}




