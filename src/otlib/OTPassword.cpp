/**************************************************************
 *    
 *  OTPassword.cpp
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



// size_t
#include <cstddef>

#include <iostream>

#ifdef _WIN32
#include <WinsockWrapper.h>
#endif

// ------------------------------
// For SecureZeroMemory
#ifdef _WIN32

//#include "Windows.h"
// ------------------------------
#else // not _WIN32

// for mlock and munlock
#include <sys/types.h>
#include <sys/mman.h>
#include <limits.h>

#ifndef PAGESIZE
    #include <unistd.h>
    #define PAGESIZE sysconf(_SC_PAGESIZE)
#endif

// FT: Credit to the Bitcoin team for the mlock / munlock defines.

#define mlock(a,b) \
  mlock(((void *)(((size_t)(a)) & (~((PAGESIZE)-1)))),\
  (((((size_t)(a)) + (b) - 1) | ((PAGESIZE) - 1)) + 1) - (((size_t)(a)) & (~((PAGESIZE) - 1))))
#define munlock(a,b) \
  munlock(((void *)(((size_t)(a)) & (~((PAGESIZE)-1)))),\
  (((((size_t)(a)) + (b) - 1) | ((PAGESIZE) - 1)) + 1) - (((size_t)(a)) & (~((PAGESIZE) - 1))))
#endif
// ------------------------------

extern "C"
{	
#include <openssl/err.h>
#include <openssl/rand.h>
}

// ---------------------------------------------------------

#include "OTPassword.h"

#include "OTString.h"

#include "OTLog.h"

// ---------------------------------------------------------
// For everything but Windows:
//
#ifndef _WIN32
extern "C" void *ot_secure_memset(void *v, uint8_t c, uint32_t n);

// This function securely overwrites the contents of a memory buffer
// (which can otherwise be optimized out by an overzealous compiler...)
//
void *ot_secure_memset(void *v, uint8_t c, uint32_t n) 
{
    OT_ASSERT((NULL != v) && (n > 0));
    
	volatile uint8_t * p = static_cast<volatile uint8_t *>(v);
	while (n--)
		*p++ = c;
	
	return v;
}
#endif // _WIN32
// ---------------------------------------------------------


// TODO, security: Generate a session key, and encrypt the password string to that key whenever setting it,
// and decrypt it using that key whenever getting it. Also make sure to use the lock / unlock functions
// at that time (below). Also change so that the contents are dynamically allocated.
// NOTE: Given that OTSymmetricKey works with OTPassword, this is a bit circular in logic. Therefore might
// need to add a function to OTEnvelope so that it takes a const char * instead of an OTPassword, in order
// to handle this specific case! Might also need to duplicate some code between OTSymmetricKey and OTPassword
// in order to make sure both have the same protections. I'll see if there's a way to do this without duplication,
// as I get deeper into it.


// ---------------------------------------------------------
/*
#ifdef _WIN64
   //define something for Windows (64-bit)
#elif _WIN32
   //define something for Windows (32-bit)
#elif __APPLE__
    #include "TargetConditionals.h"
    #ifdef TARGET_OS_IPHONE
         // iOS
    #elif TARGET_IPHONE_SIMULATOR
        // iOS Simulator
    #elif TARGET_OS_MAC
        // Other kinds of Mac OS
    #else
        // Unsupported platform
    #endif
#elif __linux
    // linux
#elif __unix // all unices not caught above
    // Unix
#elif __posix
    // POSIX
#endif 
 */




// THE PURPOSE OF LOCKING A PAGE:
//
// "So that it won't get swapped to disk, where the secret
// could be recovered maliciously from the swap file."
//
bool ot_lockPage(void* addr, size_t len)
{
    static bool bWarned = false;
    
#ifdef _WIN32
	//return VirtualLock(addr, len);
#elif defined(PREDEF_PLATFORM_UNIX)
	if (mlock(addr, len) && !bWarned)
    {
        bWarned = true;
        OTLog::Error("ot_lockPage: WARNING: unable to lock memory. \n"
                     "   (Passwords / secret keys may be swapped to disk!)\n");
    }
    return true;
#else
	OT_ASSERT_MSG(false, "ASSERT: ot_lockPage unable to lock memory.");
#endif
    return false;
}

// TODO:  Note: may need to add directives here so that mlock and munlock are not
// used except where the user is running as a privileged process. (Because that
// may be the only way we CAN use those functions...)

bool ot_unlockPage(void* addr, size_t len)
{
    static bool bWarned = false;

#ifdef _WIN32
//	return VirtualUnlock(addr, len);
#elif defined(PREDEF_PLATFORM_UNIX)
	if (munlock(addr, len) && !bWarned)
    {
        bWarned = true;
        OTLog::Error("ot_unlockPage: WARNING: unable to unlock memory used for storing secrets.\n");
    }
    return true;        
#else
	OT_ASSERT_MSG(false, "ASSERT: ot_unlockPage unable to unlock secret memory.");
#endif
    return false;
}



// ---------------------------------------------------------

// Instantiate one of these whenever you do an action that may
// require a passphrase. When you call the OpenSSL private key
// using function, just pass in the address to this instance along
// as one of the parameters. That way when the actual password
// callback is activated, you'll get that pointer as the userdata
// parameter to the callback.
// This enables you to easily pass data to the callback about
// which Nym is doing the action, or what string should be displayed
// on the screen, etc. You'll also be able to use the same mechanism
// for determining whether it's a wallet-Nym doing the action, or
// a real Nym. (Thus making it possible to skip any "password caching"
// code that normally happens for real nyms, when it's the wallet nym.)
//
/*
 
class OTPasswordData
{
private:
    OTPassword *       m_pMasterPW; // Used only when isForMasterKey is true.
    const std::string  m_strDisplay;
    
public:
    // --------------------------------
    bool            isForMasterKey()   const;
    const char *    GetDisplayString() const;
    // --------------------------------
    OTPasswordData(const char        *   szDisplay, OTPassword * pMasterPW=NULL);  
    OTPasswordData(const std::string & str_Display, OTPassword * pMasterPW=NULL);  
    OTPasswordData(const OTString    &  strDisplay, OTPassword * pMasterPW=NULL);  
    ~OTPasswordData();
};
 */


bool OTPasswordData::isUsingOldSystem() const
{
    return m_bUsingOldSystem;
}

void OTPasswordData::setUsingOldSystem(bool bUsing/*=true*/)
{
    m_bUsingOldSystem = bUsing;
}


bool OTPasswordData::isForNormalNym() const
{
    return (NULL == m_pMasterPW);
}

bool OTPasswordData::isForMasterKey() const
{
    return (NULL != m_pMasterPW);
}

const char * OTPasswordData::GetDisplayString() const
{
    return m_strDisplay.c_str();
}

OTPasswordData::OTPasswordData(const char * szDisplay, OTPassword * pMasterPW/*=NULL*/)
: m_pMasterPW(pMasterPW), m_strDisplay(NULL == szDisplay ? "(Sorry, no user data provided.)" : szDisplay),
  m_bUsingOldSystem(false)
{
    
}

OTPasswordData::OTPasswordData(const std::string & str_Display, OTPassword * pMasterPW/*=NULL*/)
: m_pMasterPW(pMasterPW), m_strDisplay(str_Display), m_bUsingOldSystem(false)
{
    
}

OTPasswordData::OTPasswordData(const OTString & strDisplay, OTPassword * pMasterPW/*=NULL*/)
: m_pMasterPW(pMasterPW), m_strDisplay(strDisplay.Get()),   m_bUsingOldSystem(false)
{
    
}

OTPasswordData::~OTPasswordData()
{
	m_pMasterPW = NULL; // not owned
}

// ---------------------------------------------------------

// PURPOSE OF ZERO'ING MEMORY:
//
// So the secret is not stored in memory any longer than absolutely necessary.
// Once it has been used, we want to wipe it from memory ASAP. (The least amount
// of time spent in memory, the better.)

void OTPassword::zeroMemory()
{
	m_nPasswordSize = 0;
    // -------------------
    OTPassword::zeroMemory(static_cast<void *>(&(m_szPassword[0])), static_cast<uint32_t>(getBlockSize()));
    // -------------------
    //
#ifndef _WIN32
    // UNLOCK the page, now that we're AFTER the point where
    // the memory was safely ZERO'd out.
    //
    if (m_bIsPageLocked)
    {
        if (ot_unlockPage(static_cast<void *>(&(m_szPassword[0])), static_cast<uint32_t>(getBlockSize())))
        {
            m_bIsPageLocked = false;
        }
        else
            OTLog::Error("OTPassword::zeroMemory: Error: Memory page was locked, but then failed to unlock it.\n");
    }    
#endif
    // -------------------
}

// ----------------------------------------------------------
//static
void OTPassword::zeroMemory(void * vMemory, uint32_t theSize)
{
//  OT_ASSERT_MSG((NULL != vMemory) && (theSize > 0),"OTPassword::zeroMemory: ASSERT: vMemory is NULL or theSize is 0.");
  
    if ((NULL != vMemory) && (theSize > 0))
    {
        uint8_t * szMemory = static_cast<uint8_t *>(vMemory);
        OTPassword::zeroMemory(szMemory, theSize);
    }
}
// ----------------------------------------------------------
//static
void OTPassword::zeroMemory(uint8_t * szMemory, uint32_t theSize)
{
#ifdef _WIN32
	// ------
	//
	SecureZeroMemory(szMemory, theSize);
	
	// NOTE: Both SecureZeroMemory, and the pragma solution commented-out below,
	// are acceptable for Windows. I put both here for my notes.
	//
//#pragma optimize("", off)
//	memset(szMemory, 0, theSize);
//#pragma optimize("", on)	
	// -------------------------
	// Dr. UNIX, I presume? So, we meet again...
#else	
	ot_secure_memset(szMemory, static_cast<uint8_t>(0), theSize);
#endif
}
// ---------------------------------------------------------



/* WINDOWS:
 errno_t memcpy_s(
 void   * dest,
 size_t   numberOfElements,
 const
 void   * src,
 size_t   count 
 );
 
 FT: Apparently numberOfElements is similar to strcpy_s (where it's the maximum size of destination buffer.)
 "numberOfElements is the Maximum number of characters destination string can accomodate including the NULL character"
 (Then count is the actual size being copied.)
 */
// UNIX:
//    void * memcpy(void *restrict s1, const void *restrict s2, size_t n);
//
//static
void * OTPassword::safe_memcpy(void   * dest,
                               uint32_t dest_size,
                               const
                               void   * src,
                               uint32_t src_length,
                               bool     bZeroSource/*=false*/) // if true, sets the source buffer to zero after copying is done.
{
    bool bSuccess = false;
    
    // Make sure they aren't null.
    OT_ASSERT(NULL != dest);
    OT_ASSERT(NULL != src);

    // Make sure they aren't the same pointer.
    OT_ASSERT(src != dest);

    // Make sure it will fit.
    OT_ASSERT_MSG(src_length <= dest_size, "ASSERT: safe_memcpy: destination buffer too small.\n");

    // Make sure they don't overlap.
    // First assert does the beginning of the string, makes sure it's not within the bounds of the destination
    // string. Second assert does the same thing for the end of the string. Finally a third is needed to make sure
    // we're not in a situation where the beginning is less than the dest beginning, yet the end is also more than
    // the dest ending!
    //
    OT_ASSERT_MSG(false == ((static_cast<const uint8_t *>(src) >   static_cast<uint8_t *>(dest)) &&
                            (static_cast<const uint8_t *>(src) <  (static_cast<uint8_t *>(dest) + dest_size))),
                  "ASSERT: safe_memcpy: Unexpected memory overlap, start of src.\n");
    OT_ASSERT_MSG(false == (((static_cast<const uint8_t *>(src) + src_length) >   static_cast<uint8_t *>(dest)) &&
                            ((static_cast<const uint8_t *>(src) + src_length) <  (static_cast<uint8_t *>(dest) + dest_size))),
                  "ASSERT: safe_memcpy: Unexpected memory overlap, end of src.\n");
    OT_ASSERT(false ==  ((static_cast<const uint8_t *>(src) <= static_cast<uint8_t *>(dest)) &&
                        ((static_cast<const uint8_t *>(src) + src_length) >= (static_cast<uint8_t *>(dest) + dest_size))));
        
#ifdef _WIN32
    bSuccess = (0 == memcpy_s(dest,         // destination
                              static_cast<size_t>(dest_size),    // size of destination buffer.
                              src,          // source
                              static_cast<size_t>(src_length))); // length of source.
#else
    bSuccess = (memcpy(dest, src, static_cast<size_t>(src_length)) == dest);
#endif
    
    if (bSuccess)
    {
        if (bZeroSource)
        {
            OTPassword::zeroMemory(const_cast<void *>(src), src_length);
        }
        // ------------------------
        return dest;
    }
    
    return NULL;
}
// ---------------------------------------------------------

OTPassword::OTPassword(OTPassword::BlockSize theBlockSize/*=DEFAULT_SIZE*/)
:	m_nPasswordSize(0),
    m_bIsText(true),
    m_bIsBinary(false),
    m_bIsPageLocked(false),
	m_theBlockSize(theBlockSize) // The buffer has this size+1 as its static size.
{
	m_szPassword[0] = '\0';
    
    setPassword_uint8(reinterpret_cast<const uint8_t*>(""), 0);
}

// ---------------------------------------------------------


OTPassword & OTPassword::operator=(const OTPassword & rhs)
{
    if (rhs.isPassword())
    {
        setPassword_uint8(rhs.getPassword_uint8(), rhs.getPasswordSize());
    }
    else if (rhs.isMemory())
    {
        setMemory(rhs.getMemory_uint8(), rhs.getMemorySize());
    }
    
    return *this;
}


OTPassword::OTPassword(const OTPassword & rhs)
:	m_nPasswordSize(0),
    m_bIsText(rhs.isPassword()),
    m_bIsBinary(rhs.isMemory()),
    m_bIsPageLocked(false),
    m_theBlockSize(rhs.m_theBlockSize) // The buffer has this size+1 as its static size.
{
    if (m_bIsText)
    {
        m_szPassword[0] = '\0';
        setPassword_uint8(rhs.getPassword_uint8(), rhs.getPasswordSize());
    }
    else if (m_bIsBinary)
    {
        setMemory(rhs.getMemory_uint8(), rhs.getMemorySize());
    }
}

// ---------------------------------------------------------

OTPassword::OTPassword(const char * szInput, uint32_t nInputSize, OTPassword::BlockSize theBlockSize/*=DEFAULT_SIZE*/)
:	m_nPasswordSize(0),
    m_bIsText(true),
    m_bIsBinary(false),
    m_bIsPageLocked(false),
    m_theBlockSize(theBlockSize) // The buffer has this size+1 as its static size.
{
	m_szPassword[0] = '\0';
	
	setPassword_uint8(reinterpret_cast<const uint8_t*>(szInput), nInputSize);
}
// ---------------------------------------------------------
OTPassword::OTPassword(const uint8_t * szInput, uint32_t nInputSize, OTPassword::BlockSize theBlockSize/*=DEFAULT_SIZE*/)
:	m_nPasswordSize(0),
    m_bIsText(true),
    m_bIsBinary(false),
    m_bIsPageLocked(false),
    m_theBlockSize(theBlockSize) // The buffer has this size+1 as its static size.
{
	m_szPassword[0] = '\0';
	
	setPassword_uint8(szInput, nInputSize);
}
// ---------------------------------------------------------
OTPassword::OTPassword(const void * vInput, uint32_t nInputSize, OTPassword::BlockSize theBlockSize/*=DEFAULT_SIZE*/)
:	m_nPasswordSize(0),
    m_bIsText(false),
    m_bIsBinary(true),
    m_bIsPageLocked(false),
    m_theBlockSize(theBlockSize) // The buffer has this size+1 as its static size.
{
	setMemory(vInput, nInputSize);
}
// ---------------------------------------------------------


OTPassword::~OTPassword() 
{
	if (m_nPasswordSize > 0)
		zeroMemory();
}

// ---------------------------------------------------------


bool OTPassword::isPassword() const
{
    return m_bIsText;
}

bool OTPassword::isMemory() const
{
    return m_bIsBinary;
}


// ---------------------------------------------------------


// ---------------------------------------------------------
//
const char * OTPassword::getPassword() const // asserts if m_bIsText is false.
{
    return reinterpret_cast<const char *>(this->getPassword_uint8());

}
// ---------------------------------------------------------
// getPassword returns "" if empty, otherwise returns the password.
//
const uint8_t * OTPassword::getPassword_uint8() const
{
    OT_ASSERT(m_bIsText);
	return (m_nPasswordSize <= 0) ? reinterpret_cast<const uint8_t *>("") : &(m_szPassword[0]); 
}

uint8_t * OTPassword::getPasswordWritable()
{
    OT_ASSERT(m_bIsText);
	return (m_nPasswordSize <= 0) ? NULL : static_cast<uint8_t *>(static_cast<void *>(&(m_szPassword[0]))); 
}

char * OTPassword::getPasswordWritable_char()
{
    OT_ASSERT(m_bIsText);
	return (m_nPasswordSize <= 0) ? NULL : static_cast<char *>(static_cast<void *>(&(m_szPassword[0]))); 
}


// ---------------------------------------------------------
// getMemory returns NULL if empty, otherwise returns the password.
//
const void * OTPassword::getMemory() const
{
    return reinterpret_cast<const void *>(this->getMemory_uint8());
}

const uint8_t * OTPassword::getMemory_uint8() const
{
    OT_ASSERT(m_bIsBinary);
	return (m_nPasswordSize <= 0) ? NULL : static_cast<const uint8_t *>(&(m_szPassword[0])); 
}

// ---------------------------------------------------------
// getMemoryWritable returns NULL if empty, otherwise returns the password.
//
void * OTPassword::getMemoryWritable()
{
    OT_ASSERT(m_bIsBinary);
	return (m_nPasswordSize <= 0) ? NULL : static_cast<void *>(&(m_szPassword[0])); 
}

// ---------------------------------------------------------
uint32_t OTPassword::getBlockSize() const	
{
    uint32_t nReturn = 0;
    
    switch(m_theBlockSize)
    {
        case OTPassword::DEFAULT_SIZE:
            nReturn =  static_cast<uint32_t>(OT_DEFAULT_BLOCKSIZE);
            break;
        case OTPassword::LARGER_SIZE:
            nReturn =  static_cast<uint32_t>(OT_LARGE_BLOCKSIZE);
            break;
        default:
            break;
    }

	return nReturn;
}

// ---------------------------------------------------------
uint32_t OTPassword::getPasswordSize() const
{ 
    OT_ASSERT(m_bIsText);
	return m_nPasswordSize; 
}

// ---------------------------------------------------------
uint32_t OTPassword::getMemorySize() const
{ 
    OT_ASSERT(m_bIsBinary);
	return m_nPasswordSize; 
}


// ------------------

bool OTPassword::addChar(uint8_t theChar)
{
    OT_ASSERT(isPassword());
    if (getPasswordSize() < getBlockSize())
    {
        m_szPassword[m_nPasswordSize] = theChar;
        ++m_nPasswordSize;
        m_szPassword[m_nPasswordSize] = '\0';
        return true;
    }
    return false;
}

// -------------------

bool OTPassword::Compare(OTPassword & rhs) const
{
    OT_ASSERT(this->isPassword() || this->isMemory());
    OT_ASSERT(rhs.isPassword()   || rhs.isMemory());
    
    if (this->isPassword() && !rhs.isPassword())
        return false;
    if (this->isMemory() && !rhs.isMemory())
        return false;
    
    const uint32_t nThisSize = this->isPassword() ? this->getPasswordSize() : this->getMemorySize();
    const uint32_t nRhsSize  = rhs.isPassword()   ? rhs.getPasswordSize()   : rhs.getMemorySize();
    
    if (nThisSize != nRhsSize)
        return false;
    
    if (0 == memcmp(this->isPassword() ? this->getPassword_uint8() : this->getMemory_uint8(), 
                    rhs.  isPassword() ? rhs.  getPassword_uint8() : rhs.  getMemory_uint8(), 
                    rhs.  isPassword() ? rhs.  getPasswordSize()   : rhs.  getMemorySize()) )
        return true;
    
    return false;
}




// ---------------------------------------------------------
// Returns size of password (in case truncation is necessary.)
// Returns -1 in case of error.
//
int OTPassword::setPassword(const char * szInput, int nInputSize)
{
    return static_cast<int>(this->setPassword_uint8(
                reinterpret_cast<const uint8_t *>(szInput),
                static_cast<uint32_t>(nInputSize)));
}


// This adds a null terminator.
//
int32_t OTPassword::setPassword_uint8(const uint8_t * szInput, uint32_t nInputSize)
{
    OT_ASSERT(NULL != szInput);
    
    const char * szFunc = "OTPassword::setPassword";
    // ---------------------------------
	// Wipe whatever was in there before.
    //
	if (m_nPasswordSize > 0)
		zeroMemory();
	// ---------------------------------
	if (0 > nInputSize)
		return (-1);
    // ---------------------------------
    m_bIsBinary = false;
    m_bIsText   = true;
	// ---------------------------------
	if (0 == nInputSize)
		return 0;
	// ---------------------------------

	// Make sure no input size is larger than our block size
	//
	if (nInputSize > getBlockSize())
		nInputSize = getBlockSize(); // Truncated password beyond max size.
	// ---------------------------------
	// The szInput string passed into this function should never
	// be a different size than what is passed in. For example it shouldn't
	// be SMALLER than what the user claims either. If it is, we error out.
	//
	if (strnlen(reinterpret_cast<const char *>(szInput), static_cast<size_t>(nInputSize)) < static_cast<size_t>(nInputSize))
	{
        OTLog::vError("%s: ERROR: string length of szInput did not match nInputSize.\n", szFunc);
//		std::cerr << "OTPassword::setPassword: ERROR: string length of szInput did not match nInputSize." << std::endl;
		return (-1);
	}

#ifndef _WIN32
	// ---------------------------------	
    //
    // Lock the memory page, before we copy the data over.
    // (If it's not already locked, which I doubt it will be.)
    //
    if (!m_bIsPageLocked) // it won't be locked already, since we just zero'd it (above.) But I check this anyway...
    {
        if (ot_lockPage(static_cast<void *>(&(m_szPassword[0])), getBlockSize()))
        {
            m_bIsPageLocked = true;
        }
        else
            OTLog::vError("%s: Error: Failed attempting to lock memory page.\n", szFunc);
    }   
#endif
	// ---------------------------------
#ifdef _WIN32
	strncpy_s(reinterpret_cast<char *>(m_szPassword), (1 + nInputSize), reinterpret_cast<const char *>(szInput), nInputSize);
#else
	strncpy(reinterpret_cast<char *>(m_szPassword), reinterpret_cast<const char *>(szInput), nInputSize);
#endif

	// ---------------------------------	
	// force a null terminator in the 129th byte (at index 128.)
	// (Or at the 6th byte (at index 5), if the size is 5 bytes long.)
	//
	m_szPassword[nInputSize] = '\0'; 	
    m_nPasswordSize          = nInputSize;
	// ---------------------------------	

	return m_nPasswordSize;
}




/*
void OTPassword::zeroMemory()
{
	m_nPasswordSize = 0;
    // -------------------
    OTPassword::zeroMemory(m_szPassword, sizeof(m_szPassword));    
    // -------------------
    //
    // UNLOCK the page, now that we're AFTER the point where
    // the memory was safely ZERO'd out.
    //
    if (m_bIsPageLocked)
    {
        if (ot_unlockPage(static_cast<void *>(&(m_szPassword[0])), getBlockSize()))
        {
            m_bIsPageLocked = false;
        }
        else
            OTLog::Error("OTPassword::zeroMemory: Error: Memory page was locked, but then failed to unlock it.\n");
    }    
    // -------------------
}
*/
 

//static
bool OTPassword::randomizePassword(char * szDestination, uint32_t nNewSize)
{
    return OTPassword::randomizePassword_uint8(reinterpret_cast<uint8_t *>(szDestination), nNewSize);
}


//static
bool OTPassword::randomizePassword_uint8(uint8_t * szDestination, uint32_t nNewSize)
{
    OT_ASSERT(NULL != szDestination);
    OT_ASSERT(nNewSize > 0);
	// ---------------------------------
//    const char * szFunc = "OTPassword::randomizePassword(static)";
	// ---------------------------------
    if (OTPassword::randomizeMemory_uint8(szDestination, nNewSize))
    {
        // --------------------------------------------------
        // This loop converts an array of binary bytes into the
        // same array, where each byte is translated to a byte
        // between the values of 33 and 122 (visible ASCII.)
        //
        for (uint32_t i = 0; i < nNewSize; ++i)
        {
            uint8_t temp     =  (( (szDestination[i]) % 89 ) + 33);
            szDestination[i] = temp;
        }
        // --------------------------------------------------
        // Add the NULL terminator...
        //
        szDestination[nNewSize-1] = '\0';
        
        return true;
    }
    return false;
}


// ---------------------------------------------------------
// Returns size of memory (in case truncation is necessary.)
// Returns -1 in case of error.
//
int32_t OTPassword::randomizePassword(uint32_t nNewSize/*=DEFAULT_SIZE*/)
{
    const char * szFunc = "OTPassword::randomizePassword";
    uint32_t nSize = nNewSize;
    // ---------------------------------
	// Wipe whatever was in there before.
    //
	if (m_nPasswordSize > 0)
		zeroMemory();
	// ---------------------------------
	if (0 > nSize)
		return (-1);
    // ---------------------------------
    m_bIsBinary = false;
    m_bIsText   = true;
	// ---------------------------------
	if (0 == nSize)
		return 0;
	// ---------------------------------
	// Make sure no input size is larger than our block size
	//
	if (nSize > getBlockSize())
		nSize = getBlockSize(); // Truncated password beyond max size.
#ifndef _WIN32
    //
    // Lock the memory page, before we randomize 'size bytes' of the data.
    // (If it's not already locked, which I doubt it will be.)
    //
    if (!m_bIsPageLocked) // it won't be locked already, since we just zero'd it (above.) But I check this anyway...
    {
        if (ot_lockPage(static_cast<void *>(&(m_szPassword[0])), getBlockSize()))
        {
            m_bIsPageLocked = true;
        }
        else
            OTLog::vError("%s: Error: Failed attempting to lock memory page.\n", szFunc);
    }    
#endif
	// ---------------------------------
    //
	if (!OTPassword::randomizePassword_uint8(&(m_szPassword[0]), static_cast<int32_t>(nSize+1)))
    {
        // randomizeMemory (above) already logs, so I'm not logging again twice here.
        //
        zeroMemory();
		return -1;
	}
	// --------------------------------------------------
	m_nPasswordSize = nSize;
    
	return m_nPasswordSize;
}




//static
bool OTPassword::randomizeMemory(void * szDestination, uint32_t nNewSize)
{
    return OTPassword::randomizeMemory_uint8(reinterpret_cast<uint8_t *>(szDestination), nNewSize);
}


//static
bool OTPassword::randomizeMemory_uint8(uint8_t * szDestination, uint32_t nNewSize)
{
    OT_ASSERT(NULL != szDestination);
    OT_ASSERT(nNewSize > 0);
	// ---------------------------------
    const char * szFunc = "OTPassword::randomizeMemory(static)";
	// ---------------------------------
    /*
     RAND_bytes() returns 1 on success, 0 otherwise. The error code can be obtained by ERR_get_error(3). 
     RAND_pseudo_bytes() returns 1 if the bytes generated are cryptographically strong, 0 otherwise. 
     Both functions return -1 if they are not supported by the current RAND method.
     */
    const int nRAND_bytes = RAND_bytes(reinterpret_cast<uint8_t*>(szDestination), 
                                       static_cast<int>(nNewSize));
    
	if ((-1) == nRAND_bytes)
	{
		OTLog::vError("%s: ERROR: RAND_bytes is apparently not supported by the current "
                      "RAND method. OpenSSL: %s\n", szFunc, ERR_error_string(ERR_get_error(), NULL));
		return false;
	}
	else if (0 == nRAND_bytes)
	{
		OTLog::vError("%s: Failed: The PRNG is apparently not seeded. OpenSSL error: %s\n",
                      szFunc, ERR_error_string(ERR_get_error(), NULL));
		return false;
	}
	// --------------------------------------------------
    return true;
}


// ---------------------------------------------------------
// Returns size of memory (in case truncation is necessary.)
// Returns -1 in case of error.
//
int32_t OTPassword::randomizeMemory(uint32_t nNewSize/*=DEFAULT_SIZE*/)
{
    const char * szFunc = "OTPassword::randomizeMemory";
    uint32_t nSize = nNewSize;
    // ---------------------------------
	// Wipe whatever was in there before.
    //
	if (m_nPasswordSize > 0)
		zeroMemory();
	// ---------------------------------
	if (0 > nSize)
		return (-1);
    // ---------------------------------
    m_bIsBinary = true;
    m_bIsText   = false;
	// ---------------------------------
	if (0 == nSize)
		return 0;
	// ---------------------------------
	// Make sure no input size is larger than our block size
	//
	if (nSize > getBlockSize())
		nSize = getBlockSize(); // Truncated password beyond max size.

#ifndef _WIN32
    //
    // Lock the memory page, before we randomize 'size bytes' of the data.
    // (If it's not already locked, which I doubt it will be.)
    //
    if (!m_bIsPageLocked) // it won't be locked already, since we just zero'd it (above.) But I check this anyway...
    {
        if (ot_lockPage(static_cast<void *>(&(m_szPassword[0])), getBlockSize()))
        {
            m_bIsPageLocked = true;
        }
        else
            OTLog::vError("%s: Error: Failed attempting to lock memory page.\n", szFunc);
    }  
#endif
	// ---------------------------------
    //
	if (!OTPassword::randomizeMemory_uint8(&(m_szPassword[0]), nSize))
    {
        // randomizeMemory (above) already logs, so I'm not logging again twice here.
        //
        zeroMemory();
		return -1;
	}
	// --------------------------------------------------
	m_nPasswordSize = nSize;

	return m_nPasswordSize;
}


// (FYI, truncates if nAppendSize + getPasswordSize() is larger than getBlockSize.)
// Returns number of bytes appended, or -1 for error.
//
int32_t OTPassword::addMemory(const void * vAppend, uint32_t nAppendSize) 
{
    OT_ASSERT(NULL != vAppend);

//  const char * szFunc = "OTPassword::addMemory";
    // ---------------------------------
	if (0 > nAppendSize)
		return (-1);
    // ---------------------------------
	if (0 == nAppendSize)
		return 0;
	// ---------------------------------
	// If I'm currently at a 0 size, then call setMemory instead.
    //
	if (m_nPasswordSize == 0)
		return this->setMemory(vAppend, nAppendSize);
    // ***********************************************
    //
    // By this point, I know I already have some memory allocated,
    // and I'm actually appending some other memory onto the end of it.
    //
    OT_ASSERT(m_bIsBinary); // Should already be set from the above setMemory call.
	// ---------------------------------
	// Make sure total new size isn't larger than our block size
	//
	if ((nAppendSize + m_nPasswordSize) > getBlockSize())
		nAppendSize = (getBlockSize() - m_nPasswordSize); // Truncated password beyond max size.
	// ---------------------------------
//  OT_ASSERT(nAppendSize >= 0);
    
    if (0 == nAppendSize)
        return 0;
    // ------------------------------------
    // By this point, I know nAppendSize is larger than 0, AND that appending it onto the
    // existing memory of this object will not exceed the total allowed block size.
    //
    // Because we use setMemory when empty, and only use addMemory when we KNOW something
    // is already there, therefore we know the page is already locked, so no need to go
    // trying to lock it again.
	// ---------------------------------    
    OTPassword::safe_memcpy(static_cast<void *>(&(m_szPassword[m_nPasswordSize])),
                            static_cast<uint32_t>(nAppendSize), // dest size is based on the source size, but guaranteed to be >0 and <=getBlockSize
                            vAppend,
                            static_cast<uint32_t>(nAppendSize)); // Since dest size is known to be src size or less (and >0) we use it as src size. (We may have truncated... and we certainly don't want to copy beyond our own truncation.)    
	// ---------------------------------
    m_nPasswordSize += nAppendSize;
	// ---------------------------------
	return nAppendSize;
}


// ---------------------------------------------------------
// Returns size of memory (in case truncation is necessary.)
// Returns -1 in case of error.
//
int32_t OTPassword::setMemory(const void * vInput, uint32_t nInputSize)
{		
    OT_ASSERT(NULL != vInput);
    
    const char * szFunc = "OTPassword::setMemory";
    // ---------------------------------
	// Wipe whatever was in there before.
    //
	if (m_nPasswordSize > 0)
		zeroMemory();
	// ---------------------------------
	if (0 > nInputSize)
		return (-1);
    // ---------------------------------
    m_bIsBinary = true;
    m_bIsText   = false;
	// ---------------------------------
	if (0 == nInputSize)
		return 0;
	// ---------------------------------
	// Make sure no input size is larger than our block size
	//
	if (nInputSize > getBlockSize())
		nInputSize = getBlockSize(); // Truncated password beyond max size.
	// ---------------------------------

#ifndef _WIN32
    //
    // Lock the memory page, before we copy the data over.
    // (If it's not already locked, which I doubt it will be.)
    //
    if (!m_bIsPageLocked) // it won't be locked already, since we just zero'd it (above.) But I check this anyway...
    {
        if (ot_lockPage(static_cast<void *>(&(m_szPassword[0])), getBlockSize()))
        {
            m_bIsPageLocked = true;
        }
        else
            OTLog::vError("%s: Error: Failed attempting to lock memory page.\n", szFunc);
    }    
#endif

	// ---------------------------------    
    OTPassword::safe_memcpy(static_cast<void *>(&(m_szPassword[0])),
                            static_cast<uint32_t>(nInputSize), // dest size is based on the source size, but guaranteed to be >0 and <=getBlockSize
                            vInput,
                            static_cast<uint32_t>(nInputSize)); // Since dest size is known to be src size or less (and >0) we use it as src size. (We may have truncated... and we certainly don't want to copy beyond our own truncation.)    
	// ---------------------------------
    m_nPasswordSize = nInputSize;
	// ---------------------------------
	return m_nPasswordSize;
}

// ---------------------------------------------------------




// ***************************************************

// OTCallback CLASS

OTCallback::~OTCallback() 
{
	OTLog::vError("OTCallback::~OTCallback:  (This should only happen ONCE ONLY -- as the application is closing.)\n");
//	std::cout << "OTCallback::~OTCallback()" << std:: endl; 
}


// Asks for password once. (For authentication when using nym.)
//
void OTCallback::runOne(const char * szDisplay, OTPassword & theOutput) // child class will override.
{ 
	OT_ASSERT_MSG(false, "OTCallback::runOne: ASSERT (The child class was supposed to override this method.)\n");
}

// Asks for password twice. (For confirmation when changing password or creating nym.)
//
void OTCallback::runTwo(const char * szDisplay, OTPassword & theOutput) // child class will override.
{ 
	OT_ASSERT_MSG(false, "OTCallback::runTwo: ASSERT (The child class was supposed to override this method.)\n");
}


// ***************************************************

// OTCaller CLASS

OTCaller::~OTCaller() 
{
	OTLog::vOutput(0, "OTCaller::~OTCaller: (This should only happen as the application is closing.)\n");
	
	delCallback(); 
}


// A display string is set here before the Java dialog is shown, so that the string can be displayed on that dialog.
//
const char * OTCaller::GetDisplay() const
{
	// I'm using the OTPassword class to store the display string, in addition to
	// storing the password itself. (For convenience.)
	//
	return reinterpret_cast<const char *>(m_Display.getPassword_uint8()); 
}

// A display string is set here before the Java dialog is shown, so that the string can be displayed on that dialog.
//
void OTCaller::SetDisplay(const char * szDisplay, int nLength)
{
	// I'm using the OTPassword class to store the display string, in addition to
	// storing the password itself. (For convenience.)
	//
	m_Display.setPassword_uint8(reinterpret_cast<const uint8_t *>(szDisplay), nLength);
}


// ------------------------------------------------


// The password will be stored here by the Java dialog, so that the C callback can retrieve it and pass it to OpenSSL
//
bool OTCaller::GetPassword(OTPassword & theOutput) const // Get the password....
{ 
	OTLog::Output(0, "OTCaller::GetPassword: FYI, returning password after invoking a (probably Java) password dialog.\n");
	
	theOutput.setPassword_uint8(m_Password.getPassword_uint8(), m_Password.getPasswordSize());
	
	return true; 
}

void OTCaller::ZeroOutPassword()	// Then ZERO IT OUT so copies aren't floating around.
{
	if (m_Password.getPasswordSize() > 0)
		m_Password.zeroMemory();
}


//--------------------------------

void OTCaller::delCallback() 
{ 
	//	if (NULL != _callback)  // TODO this may be a memory leak.
	//		delete _callback;	// But I know we're currently crashing from deleting same object twice.
	// And since the object comes from Java, who am I to delete it? Let Java clean it up.
	if (isCallbackSet())
		OTLog::Output(0, "OTCaller::delCallback: WARNING: setting existing callback object pointer to NULL. "
					  "(This message doesn't trigger if it was already NULL.)\n");
	//--------------------------------
	_callback = NULL; 
}

void OTCaller::setCallback(OTCallback *cb) 
{ 
	OTLog::Output(0, "OTCaller::setCallback: Attempting to set the password OTCallback pointer...\n");	
	
	if (NULL == cb)
	{
		OTLog::Output(0, "OTCaller::setCallback: ERROR: NULL password OTCallback object passed in. (Returning.)\n");
		return;
	}
	
	delCallback(); // Sets _callback to NULL, but LOGS first, if it was already set.
	// -----------------------------
	
	_callback = cb;
	OTLog::Output(0, "OTCaller::setCallback: FYI, the password OTCallback pointer was set.\n");
}

bool OTCaller::isCallbackSet() const
{ 
	return (NULL == _callback) ? false : true; 
}

//--------------------------------

void OTCaller::callOne() 
{ 
	ZeroOutPassword(); // Make sure there isn't some old password still in here.
	
	if (isCallbackSet()) 
	{ 
		OTLog::Output(0, "OTCaller::callOne: FYI, Executing password callback (one)...\n");		
		_callback->runOne(this->GetDisplay(), m_Password); 
	}
	else
	{
		OTLog::Output(0, "OTCaller::callOne: WARNING: Failed attempt to trigger password callback (one), due to \"it hasn't been set yet.\"\n");
	}
}

void OTCaller::callTwo() 
{ 
	ZeroOutPassword(); // Make sure there isn't some old password still in here.
	
	if (isCallbackSet()) 
	{ 
		OTLog::Output(0, "OTCaller::callTwo: FYI, Executing password callback (two)...\n");		
		_callback->runTwo(this->GetDisplay(), m_Password);
	}
	else
	{
		OTLog::Output(0, "OTCaller::callTwo: WARNING: Failed attempt to trigger password callback (two), due to \"it hasn't been set yet.\"\n");
	}	
}
//--------------------------------






/*
 WCHAR szPassword[MAX_PATH];
 
 // Retrieve the password
 if (GetPasswordFromUser(szPassword, MAX_PATH))    
 
 UsePassword(szPassword); // <===========
 
 // WINDOWS MEMORY ZEROING CODE:
 SecureZeroMemory(szPassword, sizeof(szPassword));
 
 */




/*
 SOURCE: https://www.securecoding.cert.org
 TODO security: research all of these items and implement them in OT properly along with all other code scanning and security measures.
 
 https://www.securecoding.cert.org/confluence/display/cplusplus/MSC06-CPP.+Be+aware+of+compiler+optimization+when+dealing+with+sensitive+data
 
 
 Compliant Code Example (Windows)
 This compliant solution uses a SecureZeroMemory() function provided by many versions of the Microsoft Visual Studio compiler. 
 The documentation for the SecureZeroMemory() function guarantees that the compiler does not optimize out this call when zeroing memory.
 
 void getPassword(void) {
  char pwd[64];
  if (retrievePassword(pwd, sizeof(pwd))) {
    // checking of password, secure operations, etc
  }
  SecureZeroMemory(pwd, sizeof(pwd));
} 
 
Compliant Solution (Windows)
The #pragma directives in this compliant solution instruct the compiler to avoid optimizing the enclosed code. 
 This #pragma directive is supported on some versions of Microsoft Visual Studio and may be supported on other compilers. 
 Check compiler documentation to ensure its availability and its optimization guarantees.

void getPassword(void) {
	char pwd[64];
	if (retrievePassword(pwd, sizeof(pwd))) {
		// checking of password, secure operations, etc
	}
#pragma optimize("", off)
	memset(pwd, 0, sizeof(pwd));
#pragma optimize("", on)
}
 
Compliant Solution
This compliant solution uses the volatile type qualifier to inform the compiler that the memory should be overwritten 
 and that the call to the memset_s() function should not be optimized out. Unfortunately, this compliant solution may 
 not be as efficient as possible due to the nature of the volatile type qualifier preventing the compiler from optimizing 
 the code at all. Typically, some compilers are smart enough to replace calls to memset() with equivalent assembly instructions 
 that are much more efficient than the memset() implementation. Implementing a memset_s() function as shown in the example may 
 prevent the compiler from using the optimal assembly instructions and may result in less efficient code. Check compiler 
 documentation and the assembly output from the compiler.

// memset_s.c
void *memset_s(void *v, int c, size_t n) {
	volatile unsigned char *p = v;
	while (n--)
		*p++ = c;
	
	return v;
}

// getPassword.c
extern void *memset_s(void *v, int c, size_t n);

void getPassword(void) {
	char pwd[64];
	
	if (retrievePassword(pwd, sizeof(pwd))) {
		// checking of password, secure operations, etc
	}
	memset_s(pwd, 0, sizeof(pwd));
}
However, it should be noted that both calling functions and accessing volatile qualified objects can still be optimized out 
 (while maintaining strict conformance to the standard), so the above may still not work.
 */















































































// _____________________________________________________________
