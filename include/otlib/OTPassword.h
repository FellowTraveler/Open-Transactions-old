/**************************************************************
 *    
 *  OTPassword.h
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

#ifndef __OT_PASSWORD_H__
#define __OT_PASSWORD_H__

#ifndef EXPORT
#define EXPORT
#endif
#include <ExportWrapper.h>

#include <string>

extern "C" {
#include <stdint.h>	
}


/*
 To use:
 
 OTPassword thePass;
 (Or...)
 OTPassword thePass(strPassword, strPassword.length());
 
 const char * szPassword	= thePass.getPassword();
 const int    nPassLength	= thePass.getPasswordSize();
 
 If the instance of OTPassword is not going to be destroyed immediately
 after the password is used, then make sure to call zeroMemory() after
 using the password. (Otherwise the destructor will handle this anyway.)
 
 (The primary purpose of this class is that it zeros its memory out when
 it is destructed.)
 
 This class gives me a safe way to hand-off a password, and off-load the
 handling risk to the user.  This class will be included as part of the
 OT-API SWIG interface so that it's available inside other languages.
 
 */


#define OTPASSWORD_BLOCKSIZE    128		// (128 bytes max length for a password.)
#define OTPASSWORD_MEMSIZE		129		// +1 for null terminator.

// UPDATE: Increasing the size here, so we can accommodate private keys (in addition to passphrases.)
//
#define OT_LARGE_BLOCKSIZE	32767		// (32767 bytes max length for a password.)
#define OT_LARGE_MEMSIZE	32768		// +1 for null terminator.
// -------------------------------------------------------

// Default is the smaller size.

#define OT_DEFAULT_BLOCKSIZE  128
#define OT_DEFAULT_MEMSIZE    129

// -------------------------------------------


// https://github.com/lorf/keepassx/blob/master/src/lib/SecString.cpp

// Done:  Although we have good memory ZEROING code (for destruction)
// we don't have code yet that will keep the contents SECURE while they
// are in memory. For example, that will prevent them from being paged 
// to the hard drive during swapping. Such code would make OTPassword much
// more appropriate for use cases such as storing passphrases and private
// keys, and would even allow timeout procedures...
//
// NOTE: For Windows, use VirtualLock instead of mlock.
//
/*
 #include <sys/mman.h>
 
 void *locking_alloc(size_t numbytes) 
 {
    static short have_warned = 0;
 
    void *mem = malloc(numbytes);
 
    if (mlock(mem, numbytes) && !have_warned)
    {
 
        // We probably do not have permission.
        // Sometimes, it might not be possible to lock enough memory.
 
        fprintf(stderr, "Warning: Using insecure memory!\n");

        have_warned = 1;

    }     

    return mem;
 }

The mlock() call generally locks more memory than you want. Locking is done on a per-page basis. All of the pages the memory spans will be locked in RAM, and will not be swapped out under any circumstances, until the process unlocks something in the same page by using mlock().

There are some potentially negative consequences here. First, If your process locks two buffers that happen to live on the same page, then unlocking either one will unlock the entire page, causing both buffers to unlock. Second, when locking lots of data, it is easy to lock more pages than necessary (the operating system doesn't move data around once it has been allocated), which can slow down machine performance significantly.

Unlocking a chunk of memory looks exactly the same as locking it, except that you call munlock():
        munlock(mem, numbytes);

 
 // TODO: Work in some usage of CryptProtectMemory and CryptUnprotectMemory (Windows only)
 // with sample code below.  Also should make some kind of UNIX version.
 
 
#ifndef _WINDOWS_
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <windows.h>
#endif
#include <cstdio>
#include <Wincrypt.h>

#define SSN_STR_LEN 12  // includes null

void main()
{
    HRESULT hr = S_OK;
    LPWSTR pSensitiveText = NULL;
    DWORD cbSensitiveText = 0;
    DWORD cbPlainText = SSN_STR_LEN*sizeof(WCHAR);
    DWORD dwMod = 0;

    //  Memory to encrypt must be a multiple of CRYPTPROTECTMEMORY_BLOCK_SIZE.
    if (dwMod = cbPlainText % CRYPTPROTECTMEMORY_BLOCK_SIZE)
        cbSensitiveText = cbPlainText +
		(CRYPTPROTECTMEMORY_BLOCK_SIZE - dwMod);
    else
        cbSensitiveText = cbPlainText;

    pSensitiveText = (LPWSTR)LocalAlloc(LPTR, cbSensitiveText);
    if (NULL == pSensitiveText)
    {
        wprintf(L"Memory allocation failed.\n");
        return E_OUTOFMEMORY;
    }

    //  Place sensitive string to encrypt in pSensitiveText.

    if (!CryptProtectMemory(pSensitiveText, cbSensitiveText,
		CRYPTPROTECTMEMORY_SAME_PROCESS))
    {
        wprintf(L"CryptProtectMemory failed: %d\n", GetLastError());
        SecureZeroMemory(pSensitiveText, cbSensitiveText);
        LocalFree(pSensitiveText);
        pSensitiveText = NULL;
        return E_FAIL;
    }

    //  Call CryptUnprotectMemory to decrypt and use the memory.

    SecureZeroMemory(pSensitiveText, cbSensitiveText);
    LocalFree(pSensitiveText);
    pSensitiveText = NULL;

    return hr;
}
 
 
 
 
#ifndef _WINDOWS_
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <windows.h>
#endif
#include <cstdio>
#include <Wincrypt.h>
#include <strsafe.h>
#pragma comment(lib, "crypt32.lib")

void main()
{
    LPWSTR pEncryptedText;  // contains the encrypted text
    DWORD cbEncryptedText;  // number of bytes to which 
	                        // pEncryptedText points

    if (CryptUnprotectMemory(pEncryptedText, cbEncryptedText, 
		CRYPTPROTECTMEMORY_SAME_PROCESS))
    {
        // Use the decrypted string.
    }
    else
    {
        wprintf(L"CryptUnprotectMemory failed: %d\n", 
			GetLastError());
    }

    // Clear and free memory after using
    // the decrypted string or if an error occurs. 
    SecureZeroMemory(pEncryptedText, cbEncryptedText);
    LocalFree(pEncryptedText);
    pEncryptedText = NULL;
}
 
 
 */

class OTString;


/* 
 OTPasswordData
 This class is used for passing user data to the password callback.
 Whenever actually doing some OpenSSL call that involves a private key,
 just instantiate one of these and pass its address as the userdata for
 the OpenSSL call.  Then when the OT password callback is activated by
 OpenSSL, that pointer will be passed into the callback, so the user string
 can be displayed on the password dialog. (And also so the callback knows
 whether it was activated for a normal key or for a master key.) If it was
 activated for a normal key, then it will use the cached master key, or
 if that's timed out then it will try to decrypt a copy of it using the
 master Nym. Whereas if it WAS activated for the Master Nym, then it will
 just pop up the passphrase dialog and get his passphrase, and use that to
 decrypt the master key.
 
 NOTE: For internationalization later, we can add an OTPasswordData constructor
 that takes a STRING CODE instead of an actual string. We can use an enum for
 this. Then we just pass the code there, instead of the string itself, and 
 the class will do the work of looking up the actual string based on that code.
 */

class OTPassword;

class OTMasterKey;


class OTPasswordData
{
private:
    OTPassword *       m_pMasterPW; // Used only when isForMasterKey is true, for output. Points to output value from original caller (not owned.)
    const std::string  m_strDisplay;
    bool               m_bUsingOldSystem; // "Do NOT use MasterKey if this is true."
    
    OTMasterKey *      m_pMasterKey;  // If m_pMasterPW is set, this must be set as well.
public:
    // --------------------------------
EXPORT    bool            isForNormalNym()   const;
EXPORT    bool            isForMasterKey()   const;
EXPORT    const char *    GetDisplayString() const;
    // --------------------------------    
EXPORT    bool            isUsingOldSystem() const;
EXPORT    void            setUsingOldSystem(bool bUsing=true);
    // --------------------------------
    OTPassword  *    GetMasterPW () { return m_pMasterPW;  }
    OTMasterKey *    GetMasterKey() { return m_pMasterKey; }
    // --------------------------------
EXPORT    OTPasswordData(const char        *   szDisplay, OTPassword * pMasterPW=NULL, OTMasterKey * pMasterKey=NULL);
EXPORT    OTPasswordData(const std::string & str_Display, OTPassword * pMasterPW=NULL, OTMasterKey * pMasterKey=NULL);  
EXPORT    OTPasswordData(const OTString    &  strDisplay, OTPassword * pMasterPW=NULL, OTMasterKey * pMasterKey=NULL);  
EXPORT    ~OTPasswordData();
};



// Originally written for the safe storage of passwords.
// Now used for symmetric keys as well.
// Specifically: when the clear version of a password or key must be stored
// usually for temporary reasons, it must be stored in memory locked from swapping
// to disk, and in an object like OTPassword that zeros the memory as soon as we're done.
// 

class OTPassword
{
public:
	enum BlockSize
		{
            DEFAULT_SIZE = OT_DEFAULT_BLOCKSIZE,  // (128 bytes max length for a password.)
            LARGER_SIZE  = OT_LARGE_BLOCKSIZE     // Update: now 32767 bytes if you use this size.
        }; 	

private:
	uint32_t m_nPasswordSize; // [ 0..128 ]  Update: [ 0..9000 ]
	uint8_t	 m_szPassword[OT_DEFAULT_MEMSIZE]; // a 129-byte block of char. (128 + 1 for null terminator)
//	uint8_t  m_szPassword[OT_LARGE_MEMSIZE];   // 32767 bytes. (32768 + 1 for null terminator) todo: in optimization phase, revisit this array size.

    // OTPassword tries to store a piece of data more securely.
    // During the time I have to take a password from the user and pass it to OpenSSL,
    // I want it stored as securely as possible, and that's what this class was written for.
    // Now I'm adding the ability to store binary data in here, not just a text-based password.
    // That way, OTSymmetricKey can store its plain key in an OTPassword. Well, it actually stores
    // its key in an encrypted format, but whenever, for what brief moments that key is decrypted and
    // USED, the decrypted form of it will be stored in an OTPassword (in binary mode.)
    // This is basically just to save me from duplicating work that's already done here in OTPassword.
    // 
    bool    m_bIsText;          // storing a text passphrase?
    bool    m_bIsBinary;        // storing binary memory?
    bool    m_bIsPageLocked;    // is the page locked to prevent us from swapping this secret memory to disk?
    
public:
		const		BlockSize	m_theBlockSize;		
    // -----------------
EXPORT	bool		isPassword() const;
EXPORT	const		uint8_t *	getPassword_uint8() const; // asserts if m_bIsText is false.

EXPORT	const		char *		getPassword()	const; // asserts if m_bIsText is false.
EXPORT				uint8_t *	getPasswordWritable(); // asserts if m_bIsText is false.
EXPORT				char *		getPasswordWritable_char(); // asserts if m_bIsText is false.
    
EXPORT				int			setPassword(const char * szInput, int nInputSize); // (FYI, truncates if nInputSize larger than getBlockSize.)
EXPORT				int32_t		setPassword_uint8(const uint8_t * szInput, uint32_t nInputSize); // (FYI, truncates if nInputSize larger than getBlockSize.)
EXPORT				bool		addChar(uint8_t theChar);
    // ---------------------
EXPORT				int32_t		randomizePassword(uint32_t nNewSize=DEFAULT_SIZE);
    // -----------------
EXPORT	static	    bool		randomizePassword_uint8(uint8_t * szDestination, uint32_t nNewSize);
EXPORT	static		bool		randomizePassword(char * szDestination, uint32_t nNewSize);
    // -----------------
EXPORT				bool		isMemory()	const;
EXPORT	const		void *		getMemory() const; // asserts if m_bIsBinary is false.
EXPORT	const		uint8_t *	getMemory_uint8() const; // asserts if m_bIsBinary is false.
EXPORT				void *		getMemoryWritable(); // asserts if m_bIsBinary is false.
EXPORT				int32_t		setMemory(const void * vInput,  uint32_t nInputSize);  // (FYI, truncates if nInputSize larger than getBlockSize.)
EXPORT				int32_t		addMemory(const void * vAppend, uint32_t nAppendSize); // (FYI, truncates if nInputSize + getPasswordSize() is larger than getBlockSize.)
    // ---------------------
EXPORT				int32_t		randomizeMemory(uint32_t nNewSize=DEFAULT_SIZE);
    // -----------------
EXPORT	static		bool		randomizeMemory_uint8(uint8_t * szDestination, uint32_t nNewSize);
    // -----------------
EXPORT	static		bool		randomizeMemory(void * szDestination, uint32_t nNewSize);
    // -----------------
EXPORT				uint32_t	getBlockSize()    const;
EXPORT				bool		Compare(OTPassword & rhs) const;
    // ----------------------
EXPORT				uint32_t	getPasswordSize() const; // asserts if m_bIsText is false.
EXPORT				uint32_t	getMemorySize()   const; // asserts if m_bIsBinary is false.
    // -----------------
EXPORT				void		zeroMemory();
    // -----------------
EXPORT	static		void		zeroMemory(uint8_t * szMemory, uint32_t theSize);
EXPORT	static		void		zeroMemory(void * vMemory,     uint32_t theSize);
    // -----------------
EXPORT	static		void *		safe_memcpy(void *			dest,
											uint32_t		dest_size,
											const void *	src,
											uint32_t		src_length,
											bool			bZeroSource=false); // if true, sets the source buffer to zero after copying is done.
    // ---------------------------------------
    // OTPassword thePass; will create a text password.
    // But use the below function if you want one that has
    // a text buffer of size (versus a 0 size.) This is for
    // cases where you need the buffer to pre-exist so that
    // some other function can populate that buffer directly.
    // (Such as the OpenSSL password callback...)
    // CALLER IS RESPONSIBLE TO DELETE.
    //
EXPORT  static OTPassword * CreateTextBuffer(); // asserts already.
    
    // ---------------------------------------
EXPORT
    OTPassword & operator=(const OTPassword & rhs);
EXPORT	OTPassword(BlockSize theBlockSize=DEFAULT_SIZE);
EXPORT	OTPassword(const OTPassword & rhs);
EXPORT	OTPassword(const char    * szInput, uint32_t nInputSize, BlockSize theBlockSize=DEFAULT_SIZE);  // text   / password stored.
EXPORT	OTPassword(const uint8_t * szInput, uint32_t nInputSize, BlockSize theBlockSize=DEFAULT_SIZE);  // text   / password stored.
EXPORT	OTPassword(const void    * vInput,  uint32_t nInputSize, BlockSize theBlockSize=DEFAULT_SIZE);  // binary / symmetric key stored.
    // -----------------
EXPORT	~OTPassword();
};

//#undef OTPASSWORD_BLOCKSIZE
//#undef OTPASSWORD_MEMSIZE
//
//#undef OT_LARGE_BLOCKSIZE
//#undef OT_LARGE_MEMSIZE
//
//#undef OT_DEFAULT_BLOCKSIZE
//#undef OT_DEFAULT_MEMSIZE


// ---------------------------------------------------------
// Used for the password callback...

class OTCallback 
{
public:
	OTCallback() {}
EXPORT	virtual ~OTCallback();
EXPORT	virtual void runOne(const char * szDisplay, OTPassword & theOutput); // Asks for password once. (For authentication when using nym.)
EXPORT	virtual void runTwo(const char * szDisplay, OTPassword & theOutput); // Asks for password twice. (For confirmation when changing password or creating nym.)
};

// ------------------------------------------------

class OTCaller 
{
protected:
	OTPassword	m_Password;	// The password will be stored here by the Java dialog, so that the C callback can retrieve it and pass it to OpenSSL
	OTPassword	m_Display;	// A display string is set here before the Java dialog is shown. (OTPassword used here only for convenience.)
	
	OTCallback * _callback;
	
public:
	OTCaller() : _callback(NULL) { }
EXPORT	~OTCaller();
	
EXPORT	bool	GetPassword(OTPassword & theOutput) const;	// Grab the password when it is needed.
EXPORT	void	ZeroOutPassword();	// Then ZERO IT OUT so copies aren't floating around...
	
EXPORT	const char * GetDisplay() const;
EXPORT	void SetDisplay(const char * szDisplay, int nLength);
	
EXPORT	void delCallback();
EXPORT	void setCallback(OTCallback *cb);
EXPORT	bool isCallbackSet() const;
	
EXPORT	void callOne(); // Asks for password once. (For authentication when using the Nym's private key.)
EXPORT	void callTwo(); // Asks for password twice. (For confirmation during nym creation and password change.)
};



// ------------------------------------------------







/*
 
 
 HOW TO PREVENT MEMORY FROM GOING INTO CORE DUMPS
 
 
#include <sys/time.h>

#include <sys/resource.h>

#include <unistd.h>



int  main(int argc, char **argv)
 
 {

  struct rlimit rlim;



  getrlimit(RLIMIT_CORE, &rlim);

  rlim.rlim_max = rlim.rlim_cur = 0;

  if(setrlimit(RLIMIT_CORE, &rlim)) {

    exit(-1);

  }

  ...

  return 0;

}

 
 
 http://www.drdobbs.com/cpp/184401646
 
 
 
 
 MORE CODE FOR MEMLOCK:
 
 namespace Botan
 {
 
    bool has_mlock();
 
    bool lock_mem(void* addr, size_t length);
 
    void unlock_mem(void* addr, size_t length);
 }
 
 
//
// Memory Locking Functions
// (C) 1999-2007 Jack Lloyd
//
// Distributed under the terms of the Botan license
//

#include <botan/internal/mlock.h>

#if defined(BOTAN_TARGET_OS_HAS_POSIX_MLOCK)
  #include <sys/types.h>
  #include <sys/mman.h>
#elif defined(BOTAN_TARGET_OS_HAS_WIN32_VIRTUAL_LOCK)
#ifndef _WINDOWS_
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <windows.h>
#endif
#endif

namespace Botan {

bool has_mlock()
   {
   byte buf[4096];
   if(!lock_mem(&buf, sizeof(buf)))
      return false;
   unlock_mem(&buf, sizeof(buf));
   return true;
   }

//
// Lock an area of memory into RAM
//
bool lock_mem(void* ptr, size_t bytes)
   {
#if defined(BOTAN_TARGET_OS_HAS_POSIX_MLOCK)
   return (::mlock(static_cast<char*>(ptr), bytes) == 0);
#elif defined(BOTAN_TARGET_OS_HAS_WIN32_VIRTUAL_LOCK)
   return (::VirtualLock(ptr, bytes) != 0);
#else
   return false;
#endif
   }

//
// Unlock a previously locked region of memory
//
void unlock_mem(void* ptr, size_t bytes)
   {
#if defined(BOTAN_TARGET_OS_HAS_POSIX_MLOCK)
   ::munlock(static_cast<char*>(ptr), bytes);
#elif defined(BOTAN_TARGET_OS_HAS_WIN32_VIRTUAL_LOCK)
   ::VirtualUnlock(ptr, bytes);
#endif
   }

}
 
 */





















































// _____________________________________________________________

#endif //__OT_PASSWORD_H__







