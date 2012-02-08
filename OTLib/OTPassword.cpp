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

// For SecureZeroMemory
#ifdef _WIN32
#include "Windows.h"
#endif // _WIN32

// ---------------------------------------------------------

#include "OTPassword.h"

#include "OTLog.h"

// ---------------------------------------------------------
// For everything but Windows:
#ifndef _WIN32
extern "C" void *ot_secure_memset(void *v, int c, size_t n);

void *ot_secure_memset(void *v, int c, size_t n) 
{
	volatile unsigned char * p = static_cast<volatile unsigned char *>(v);
	while (n--)
		*p++ = c;
	
	return v;
}
#endif // _WIN32
// ---------------------------------------------------------

#ifndef linux
extern "C" { 
size_t strnlen(const char *s, size_t max) 
{
    register const char *p;
    for(p = s; *p && max--; ++p);
    return(p - s);
}
}
#endif


// ---------------------------------------------------------

void OTPassword::zeroMemory()
{
	m_nPasswordSize = 0;
	
#ifdef _WIN32
	// ------
	//
	SecureZeroMemory(m_szPassword, sizeof(m_szPassword));
	
	// NOTE: Both SecureZeroMemory, and the pragma solution commented-out below,
	// are acceptable for Windows. I put both here for my notes.
	//
//#pragma optimize("", off)
//	memset(m_szPassword, 0, sizeof(m_szPassword));
//#pragma optimize("", on)	
	// -------------------------
	// Dr. UNIX, I presume? So, we meet again...
#else	
	
	ot_secure_memset(m_szPassword, 0, sizeof(m_szPassword));
	
#endif
}
// ---------------------------------------------------------



OTPassword::OTPassword() 
:	m_nPasswordSize(0),
	blockSize(OTPassword::DEFAULT_SIZE)
{
	m_szPassword[0] = '\0';
}

OTPassword::OTPassword(const char * szInput, int nInputSize)
:	m_nPasswordSize(0),
	blockSize(OTPassword::DEFAULT_SIZE)
{
	m_szPassword[0] = '\0';
	
	setPassword(szInput, nInputSize);
}


OTPassword::~OTPassword() 
{
	if (m_nPasswordSize > 0)
		zeroMemory();
}


// ---------------------------------------------------------
// getPassword returns "" if empty, otherwise returns the password.
const char * OTPassword::getPassword() const
{
	return (m_nPasswordSize <= 0) ? "" : &(m_szPassword[0]); 
}

// ---------------------------------------------------------
int OTPassword::getBlockSize() const	
{ 
	return static_cast<int> (blockSize); 
}

// ---------------------------------------------------------
int OTPassword::getPasswordSize() const
{ 
	return m_nPasswordSize; 
}

// ---------------------------------------------------------
// Returns size of password (in case truncation is necessary.)
// Returns -1 in case of error.
//
int OTPassword::setPassword(const char * szInput, int nInputSize)
{		
	// ---------------------------------
	// Wipe whatever was in there before.
	if (m_nPasswordSize > 0)
		zeroMemory();
	// ---------------------------------
	if (0 > nInputSize)
		return (-1);
	else if (0 == nInputSize)
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
	if (strnlen(szInput, static_cast<size_t>(nInputSize)) < static_cast<size_t>(nInputSize))
	{
		std::cerr << "OTPassword::setPassword: ERROR: string length of szInput did not match nInputSize." << std::endl;
		return (-1);
	}
	// ---------------------------------
	
	m_nPasswordSize = nInputSize;
	
	// ---------------------------------
#ifdef _WIN32
	strncpy_s(m_szPassword, (1 + nInputSize), szInput, nInputSize);
#else
	strncpy(m_szPassword, szInput, nInputSize);
#endif
	
	// ---------------------------------	
	// force a null terminator in the 129th byte (at index 128.)
	// (Or at the 6th byte (at index 5), if the size is 5 bytes long.)
	//
	m_szPassword[nInputSize] = '\0'; 
	
	// ---------------------------------	

	return m_nPasswordSize;
}

// ---------------------------------------------------------




// ***************************************************

// OTCallback CLASS

OTCallback::~OTCallback() 
{
	OTLog::vOutput(0, "OTCallback::~OTCallback:  (This should only happen ONCE -- as the application is closing.)\n");
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
	return m_Display.getPassword(); 
}

// A display string is set here before the Java dialog is shown, so that the string can be displayed on that dialog.
//
void OTCaller::SetDisplay(const char * szDisplay, int nLength)
{
	// I'm using the OTPassword class to store the display string, in addition to
	// storing the password itself. (For convenience.)
	//
	m_Display.setPassword(szDisplay, nLength);
}


// ------------------------------------------------


// The password will be stored here by the Java dialog, so that the C callback can retrieve it and pass it to OpenSSL
//
bool OTCaller::GetPassword(OTPassword & theOutput) const // Get the password....
{ 
	OTLog::Output(0, "OTCaller::GetPassword: FYI, returning password after invoking a (probably Java) password dialog.\n");
	
	theOutput.setPassword(m_Password.getPassword(), m_Password.getPasswordSize());
	
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
