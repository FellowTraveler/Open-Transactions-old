/**************************************************************
 *    
 *  OTAsymmetricKey.cpp
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


extern "C" 
{
#include <memory.h>

#include <openssl/bio.h>
#include <openssl/evp.h>
#include <openssl/pem.h>
#include <openssl/dsa.h>
#include <openssl/err.h>
}

#include <cstdio>
#include <cstring>
#include <cmath>


#include <string>
#include <iostream>


extern "C" 
{
#ifdef _WIN32
#include "Windows.h"
#include <conio.h>
#else
#include <pwd.h>
#include <unistd.h>
#endif
}

#include "OTStorage.h"

#include "OTData.h"
#include "OTString.h"
#include "OTIdentifier.h"
#include "OTAsymmetricKey.h"
#include "OTEnvelope.h"
#include "OTPayload.h"
#include "OTASCIIArmor.h"
#include "OTLog.h"




typedef struct
{
	BIGNUM* p;
	BIGNUM* g;
	BIGNUM* pub_key;
	BIGNUM* priv_key;
}  ELGAMAL;

typedef struct
{
	RSA* pRsa;
	DSA* pDsa;
	ELGAMAL* pElgamal;
}  PgpKeys;




// static
OT_OPENSSL_CALLBACK * OTAsymmetricKey::s_pwCallback = NULL;

//static void SetPasswordCallback(p_OT_OPENSSL_CALLBACK pCallback);
//static p_OT_OPENSSL_CALLBACK GetPasswordCallback();
//static bool IsPasswordCallbackSet() { (NULL == s_pwCallback) ? false : true; }


void OTAsymmetricKey::SetPasswordCallback(OT_OPENSSL_CALLBACK * pCallback)
{
    const char * szFunc = "OTAsymmetricKey::SetPasswordCallback";
    
	if (NULL != s_pwCallback)
		OTLog::vOutput(0, "%s: WARNING: re-setting the password callback (one was already there)...\n", szFunc);
	else
		OTLog::vOutput(1, "%s: FYI, setting the password callback to a non-NULL pointer (which is what we want.)\n",
                       szFunc);
	// -----------------------------------
	if (NULL == pCallback)
		OTLog::vError("%s: WARNING, setting the password callback to NULL! (OpenSSL will thus "
                      "be forced to ask for the passphase on the console, until this is called "
                      "again and set properly.)\n", szFunc);
	// -----------------------------------
	s_pwCallback = pCallback; // no need to delete function pointer that came before this function pointer.
}




OT_OPENSSL_CALLBACK * OTAsymmetricKey::GetPasswordCallback()
{
    const char * szFunc = "OTAsymmetricKey::GetPasswordCallback";
    
#if defined (OT_TEST_PASSWORD)
	OTLog::vOutput(2, "%s: WARNING, OT_TEST_PASSWORD *is* defined. The internal 'C'-based password callback was just "
				  "requested by OT (to pass to OpenSSL). So, returning the default_pass_cb password callback, which will automatically return "
				  "the 'test' password to OpenSSL, if/when it calls that callback function.\n", szFunc);
	return &default_pass_cb;
#else
	if (IsPasswordCallbackSet())
	{
		OTLog::vOutput(2, "%s: FYI, the internal 'C'-based password callback is now being returning to OT, "
					  "which is passing it to OpenSSL "
					  "during a crypto operation. (If OpenSSL invokes it, then we should see other logs after this from when it triggers "
					  "whatever password-collection dialog is provided at startup by the (probably Java) OTAPI client.)\n", szFunc);
		return s_pwCallback;
	}
	else
	{
//		OTLog::Output(2, "OTAsymmetricKey::GetPasswordCallback: FYI, the internal 'C'-based password callback was requested by OT (to pass to OpenSSL), "
//					  "but the callback hasn't been set yet. (Returning NULL CALLBACK to OpenSSL!! Thus causing it to instead ask for the passphrase on the CONSOLE, "
//					  "since no Java password dialog was apparently available.)\n");
        
        
//		return static_cast<OT_OPENSSL_CALLBACK *>(NULL);
        
        // We have our own "console" password-gathering function, which allows us to use our master key.
        // Since the souped-up cb uses it, I'm just returning that here as a default, for now.
        OTAsymmetricKey::SetPasswordCallback(&souped_up_pass_cb);
        return s_pwCallback;
	}
#endif	
}



// --------------------------------------------------------
//static
OTCaller * OTAsymmetricKey::s_pCaller = NULL;


// Takes ownership. UPDATE: doesn't, since he assumes the Java side
// created it and will therefore delete it when the time comes.
// I keep a pointer, but I don't delete the thing. Let Java do it.
//
bool OTAsymmetricKey::SetPasswordCaller(OTCaller & theCaller)
{
    const char * szFunc = "OTAsymmetricKey::SetPasswordCaller";
    
	OTLog::vOutput(1, "%s: Attempting to set the password caller... "
				  "(the Java code has passed us its custom password dialog object for later use if/when the "
				  "OT 'C'-based password callback is triggered by openssl.)\n", szFunc);
	
	if (!theCaller.isCallbackSet())
	{
		OTLog::vError("%s: ERROR: OTCaller::setCallback() "
					 "MUST be called first, with an OTCallback-extended object passed to it,\n"
					 "BEFORE calling this function with that OTCaller. (Returning false.)\n", szFunc);
		return false;
	}
	
	if (NULL != s_pCaller)
	{
		OTLog::vError("%s: WARNING: Setting the password caller again, even though "
					 "it was apparently ALREADY set... (Meaning Java has probably erroneously called this twice, "
					 "possibly passing the same OTCaller both times.)\n", szFunc);
//		delete s_pCaller; // Let Java delete it.
	}
	
	s_pCaller = &theCaller;
	// ---------------------------
	
	OTAsymmetricKey::SetPasswordCallback(&souped_up_pass_cb);
	
	OTLog::vOutput(1, "%s: FYI, Successfully set the password caller object from "
				  "Java, and set the souped_up_pass_cb in C for OpenSSL (which triggers "
                   "that Java object when the time is right.) Returning true.\n", szFunc);

	return true;
}
// --------------------------------------------------------

OTCaller * OTAsymmetricKey::GetPasswordCaller()
{
    const char * szFunc = "OTAsymmetricKey::GetPasswordCaller";
    
	OTLog::vOutput(2, "%s: FYI, this was just called by souped_up_pass_cb "
				   "(which must have just been called by OpenSSL.) "
				   "Returning s_pCaller == %s (Hopefully NOT NULL, so the "
                   "custom password dialog can be triggered.)\n", szFunc,
				   (NULL == s_pCaller) ? "NULL" : "VALID POINTER");
	
	return s_pCaller;
}




bool OT_API_Set_PasswordCallback(OTCaller & theCaller) // Caller must have Callback attached already.
{
    const char * szFunc = "OT_API_Set_PasswordCallback";

	if (!theCaller.isCallbackSet())
	{
		OTLog::vError("%s: ERROR:\nOTCaller::setCallback() "
					 "MUST be called first, with an OTCallback-extended class passed to it,\n"
					 "before then invoking this function (and passing that OTCaller as a parameter "
                      "into this function.)\n", szFunc);
		return false;
	}
	
	OTLog::vOutput(1, "%s: FYI, calling OTAsymmetricKey::SetPasswordCaller(theCaller) now... (which is where "
				   "OT internally sets its pointer to the Java caller object, which must have been passed in as a "
                   "parameter to this function. "
				   "This is also where OT either sets its internal 'C'-based password callback to the souped_up "
                   "version which uses that Java caller object, "
				   "OR where OT sets its internal callback to NULL--which causes OpenSSL to ask for the passphrase "
                   "on the CONSOLE instead.)\n", 
                   szFunc);

	const bool bSuccess = OTAsymmetricKey::SetPasswordCaller(theCaller);
	
	OTLog::vOutput(1, "%s: RESULT of call to OTAsymmetricKey::SetPasswordCaller: %s", szFunc,
				   bSuccess ? "SUCCESS" : "FAILURE");
	
	return bSuccess;
}

// ***************************************************




/*
 extern "C"
 {
 typedef int OT_OPENSSL_CALLBACK(char *buf, int size, int rwflag, void *u); // <== Callback type, used for declaring.
 }
 
 // Used for the actual function definition (in the .cpp file).
 #define OPENSSL_CALLBACK_FUNC(name) extern \"C\" int (name)(char *buf, int size, int rwflag, void *u)
 */




// If the password callback isn't set, then it uses the default ("test") password.
// #define OPENSSL_CALLBACK_FUNC(name) extern "C" int (name)(char *buf, int size, int rwflag, void *userdata)
//
OPENSSL_CALLBACK_FUNC(default_pass_cb)
{
    const char * szFunc = "OPENSSL_CALLBACK_FUNC(default_pass_cb)";
    
	int len = 0;
    const size_t theSize = static_cast<const size_t>(size);
	// ------------------------------------
	// We'd probably do something else if 'rwflag' is 1

    OTPasswordData * pPWData = NULL;
    std::string    str_userdata;
    
    if (NULL != userdata)
    {
        pPWData  = static_cast<OTPasswordData *>(userdata);
        
        if (NULL != pPWData)
        {
            str_userdata = pPWData->GetDisplayString();
            
        }        
    }
    else
        str_userdata = "";
    // -------------------------------------

//	OTLog::vOutput(1, "OPENSSL_CALLBACK_FUNC: (Password callback hasn't been set yet...) Using 'test' pass phrase for \"%s\"\n", (char *)u);
    
	OTLog::vOutput(1, "%s: Using DEFAULT TEST PASSWORD: "
                   "'test' (for \"%s\")\n", szFunc, str_userdata.c_str());
	
	// get pass phrase, length 'len' into 'tmp'
	//
//	std::string str_Password;
//	std::getline (std::cin, str_Password);

//	const char *tmp_passwd = ""; // For now removing any possibility that "test" password can slip through.
	const char *tmp_passwd = "test";
//	const char *tmp_passwd = str_Password.c_str();

	len = strlen(tmp_passwd);
//	len = str_Password.size();
	
	if (len <= 0)
	{
		OTLog::vOutput(0, "%s: Problem? Returning 0...\n", szFunc);
		return 0;
	}
	
	// if too long, truncate
	if (len > size) 
		len = size;
	
    const size_t theLength = static_cast<const size_t>(len);
    // ------------------------------------------------------
    
    //void * pv = 
    OTPassword::safe_memcpy(buf,        // destination
                            theSize,    // size of destination buffer.
                            tmp_passwd, // source
                            theLength); // length of source.
                            //bool bZeroSource=false); // if true, sets the source buffer to zero after copying is done.
	return len;
}
//#ifdef _WIN32
//    memcpy_s(buf,        
//             theSize,    
//             tmp_passwd, // source
//             theLength); // length of source.
//#else
//    memcpy(buf, tmp_passwd, len);
//#endif    



// --------------------------------------------------------
/*
extern "C"
{
void SetStdinEcho(int enable)
{
#ifdef WIN32
    HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE); 
    DWORD mode;
    GetConsoleMode(hStdin, &mode);
    
    if( !enable )
        mode &= ~ENABLE_ECHO_INPUT;
    else
        mode |= ENABLE_ECHO_INPUT;
    
    SetConsoleMode(hStdin, mode );
    
#else
    struct termios tty;
    tcgetattr(STDIN_FILENO, &tty);
    if( !enable )
        tty.c_lflag &= ~ECHO;
    else
        tty.c_lflag |= ECHO;
    
    tcsetattr(STDIN_FILENO, TCSANOW, &tty);
#endif
}
}
*/

/*
int _getch( void ); // windows only  #include <conio.h>

int main()
{
    std::string password;
    char ch;
    const char ENTER = 13;
    
    std::cout << "enter the password: ";
    
    while((ch = _getch()) != ENTER)
    {
        bool    addChar(char theChar);
        password += ch;
        std::cout << '*';
    }
}
*/

#ifndef _PASSWORD_LEN
#define _PASSWORD_LEN   128
#endif

//static
bool OTAsymmetricKey::GetPasswordFromConsoleLowLevel(OTPassword & theOutput, const char * szPrompt)
{
    OT_ASSERT(NULL != szPrompt);
#ifdef WIN32
    const char ENTER = 13;
    char ch = ENTER;
    
    std::cout << szPrompt;

    while((ch = _getch()) != ENTER)
    {
        if (false == theOutput.addChar(ch))
            return false;
    }
    return true;
#else
    char * szPass = getpass(szPrompt);
    
    if (NULL != szPass)
    {
        size_t nPassLength = OTString::safe_strlen(szPass, _PASSWORD_LEN);
        theOutput.setPassword(szPass, nPassLength);
        OTPassword::zeroMemory(szPass, _PASSWORD_LEN);
        return true;
    }
#endif
    return false;
}

//static
bool OTAsymmetricKey::GetPasswordFromConsole(OTPassword & theOutput, bool bRepeat/*=false*/)
{    
    int nAttempts = 0;
    
    while (1)
    {
        theOutput.zeroMemory();
        
        if (GetPasswordFromConsoleLowLevel(theOutput, "(OT) passphrase: "))
        {
            if (!bRepeat)
            {
                return true;
            }
        }
        else
        {
            std::cout << "Sorry." << std::endl;
            return false;
        }
        // -----------------------------------------------
        OTPassword tempPassword;
        
        if (!GetPasswordFromConsoleLowLevel(tempPassword, "(Verifying) passphrase again: "))
        {    
            std::cout << "Sorry." << std::endl;
            return false;
        }

        if (!tempPassword.Compare(theOutput))
        {
            if (++nAttempts >= 3)
                break;
            
            std::cout << "(Mismatch, try again.)" << std::endl;
        }
        else
            return true;
    }
    
    std::cout << "Sorry." << std::endl;

    return false;
}



		// get pass phrase, length 'len' into 'tmp'
		/*
		int len=0;
		char *tmp=NULL;
//		tmp = "test";
		len = strlen(tmp);
		
		if (len <= 0) 
			return 0;
		
		// if too long, truncate
		if (len > size) 
			len = size;
		
		memcpy(buf, tmp, len);
		return len;		
		 */

// This is the function that OpenSSL calls when it wants to ask the user for his password.
// If we return 0, that's bad, that means the password caller and callback failed somehow.
//
//typedef
//int OT_OPENSSL_CALLBACK (char *buf, int size, int rwflag, void *userdata); // <== Callback type, used for declaring.
//
OPENSSL_CALLBACK_FUNC(souped_up_pass_cb)
{
    const char * szFunc = "OPENSSL_CALLBACK_FUNC(souped_up_pass_cb)";
    // -----------------------------------------------------
    OTPasswordData * pPWData = NULL;    
    OT_ASSERT(NULL != userdata);
    pPWData  = static_cast<OTPasswordData *>(userdata);
    const std::string str_userdata = pPWData->GetDisplayString();    
    // -----------------------------------------------------
    OTPassword thePassword;
    
    bool bGotPassword = false;
    // -------------------------------------
    
    const bool b1 = pPWData->isForNormalNym();
//  const bool b2 = !pPWData->isUsingOldSystem();
    const bool b3 = !(OTMasterKey::It()->isPaused());
    
    
//    OTLog::vOutput(5, "--------------------------------------------------------------------------------\n"
//                  "TOP OF SOUPED-UP PASS CB:\n pPWData->isForNormalNym(): %s \n "
////                "!pPWData->isUsingOldSystem(): %s \n "
//                  "!(OTMasterKey::It()->isPaused()): %s \n",
//                  b1 ? "NORMAL" : "NOT normal",
////                b2 ? "NOT using old system" : "USING old system",
//                  b3 ? "NOT paused" : "PAUSED"
//                  );
    
    //	
    // It's for one of the normal Nyms.
    // (NOT the master key.)
    // If it was for the master key, we'd just pop up the dialog and get the master passphrase.
    // But since it's for a NORMAL Nym, we have to call OTMasterKey::GetMasterPassword. IT will pop
    // up the dialog if it needs to, by recursively calling this in master mode, and then it'll use
    // the user passphrase from that dialog to derive a key, and use THAT key to unlock the actual
    // "passphrase" (a random value) which is then passed back to OpenSSL to use for the Nyms.
    //
    if ( b1 &&  // Normal Nyms, unlike Master passwords, have to look up the master password first.
//       b2 &&  
         b3)    // ...Unless they are still using the old system, in which case they do NOT look up the master password...
    {
        // Therefore we need to provide the password from an OTSymmetricKey stored here.
        // (the "actual key" in the OTSymmetricKey IS the password that we are passing back!)
        
        // So either the "actual key" is cached on a timer, from some previous request like
        // this, OR we have to pop up the passphrase dialog, ask for the passphrase for the
        // OTSymmetricKey, and then use it to GET the actual key from that OTSymmetricKey.
        // The OTSymmetricKey should be stored in the OTWallet or OTServer, which sets a pointer
        // to itself inside the OTPasswordData class statically, on initialization.
        // That way, OTPasswordData can use that pointer to get a pointer to the relevant
        // OTSymmetricKey being used as the MASTER key.
        //
      OTLog::vOutput(3, "%s: Using GetMasterPassword() call. \n", szFunc);
        
        bGotPassword = OTMasterKey::It()->GetMasterPassword(thePassword, str_userdata.c_str());

//      OTLog::vOutput(0, "OPENSSL_CALLBACK_FUNC (souped_up_pass_cb): Finished calling GetMasterPassword(). Result: %s\n",
//                     bGotPassword ? "SUCCESS" : "FAILURE");
    }
    // -----------------------------------------------------
    else
    {
        OTLog::vOutput(3, "%s: Using OT Password Callback. \n", szFunc);
                
        OTCaller * pCaller = OTAsymmetricKey::GetPasswordCaller(); // See if the developer registered one via the OT API.
        
//      if (NULL == pCaller)
//      {
//          OTLog::Error("OPENSSL_CALLBACK_FUNC (souped_up_pass_cb): OTCaller is NULL. Try calling OT_API_Set_PasswordCallback() first.\n");
//          OT_ASSERT(0); // This will never actually happen, since SetPasswordCaller() and souped_up_pass_cb are activated in same place.
//      }
        // ---------------------------------------
        if (NULL == pCaller) // We'll just grab it from the console then.
        {
            OTLog::vOutput(0, "PLEASE SIGN YOUR PASSPHRASE, for: \"%s\"\n", str_userdata.c_str());

            bGotPassword = OTAsymmetricKey::GetPasswordFromConsole(thePassword, (1 == rwflag) ? true : false);
        }
        else // Okay, we have a callback, so let's pop up the dialog!
        {
            // ---------------------------------------
            // The dialog should display this string (so the user knows what he is authorizing.)
            //
            pCaller->SetDisplay(str_userdata.c_str(), str_userdata.size());
            
            // ---------------------------------------
            if (1 == rwflag)
            {
                OTLog::vOutput(4, "%s: Using OT Password Callback (asks twice) for \"%s\"...\n", szFunc,
                               str_userdata.c_str());
                pCaller->callTwo(); // This is where Java pops up a modal dialog and asks for password twice...
            }
            else
            {
                OTLog::vOutput(4, "%s: Using OT Password Callback (asks once) for \"%s\"...\n", szFunc,
                               str_userdata.c_str());
                pCaller->callOne(); // This is where Java pops up a modal dialog and asks for password once...
            }
            // ---------------------------------------

            /*
             NOTICE: (For security...)
             
             We are using an OTPassword object to collect the password from the caller. 
             (We're not passing strings back and forth.) The OTPassword object is where we
             can centralize our efforts to scrub the memory clean as soon as we're done with
             the password. It's also designed to be light (no baggage) and to be passed around
             easily, with a set-size array for the data.

             Notice I am copying the password directly from the OTPassword object into the buffer
             provided to me by OpenSSL. When the OTPassword object goes out of scope, then it cleans
             up automatically.
             */
            
            bGotPassword = pCaller->GetPassword(thePassword);
        }
    }
    // --------------------------------------
	if (false == bGotPassword)
	{
		OTLog::vOutput(0, "%s: Failure: (false == bGotPassword.) (Returning 0.)\n", szFunc);
		return 0;
	}
    // --------------------------------------	
    
    OTLog::vOutput(2, "%s: Success!\n", szFunc);

	/* 
	 http://openssl.org/docs/crypto/pem.html#
	 "The callback must return the number of characters in the passphrase or 0 if an error occurred."
	 */
	int len	= thePassword.isPassword() ? thePassword.getPasswordSize() : thePassword.getMemorySize();
	
	if (len <= 0) 
	{
		OTLog::vOutput(0, "%s: 0 length (or less) password was "
                       "returned from the API password callback :-( Returning 0.\n", szFunc);
		return 0;
	}
	
    // -------------------------------------------------------
    OTPassword * pMasterPW = pPWData->GetMasterPW();

    if (pPWData->isForMasterKey() && (NULL != pMasterPW))
    {
        *pMasterPW = thePassword;
    }
    else
    {
        // if too long, truncate
        if (len > size) 
            len = size;
        
        const size_t theSize   = static_cast<size_t>(size);
        const size_t theLength = static_cast<size_t>(len);
        
        //void * pv = 
        OTPassword::safe_memcpy(buf,                   // destination
                                theSize,               // size of destination buffer.
                                thePassword.isPassword() ? thePassword.getPassword() : thePassword.getMemory(), // source
                                theLength); // length of source.
                               //bool bZeroSource=false); // No need to set this true, since OTPassword (source) already zeros its memory automatically.
        
    }
	return len;
}



//typedef
//int OT_OPENSSL_CALLBACK (char *buf, int size, int rwflag, void *userdata);


// ***************************************************

/*
EVP_PKEY *  CopyPublicKey (EVP_PKEY & theKey);
EVP_PKEY *  CopyPrivateKey(EVP_PKEY & theKey);
*/

void OTAsymmetricKey::SetKeyAsCopyOf(EVP_PKEY & theKey, bool bIsPrivateKey/*=false*/)
{ 
	Release(); 
    // ---------------------------    
    m_pKey			= bIsPrivateKey ? OTAsymmetricKey::CopyPrivateKey(theKey) 
                                    : OTAsymmetricKey::CopyPublicKey (theKey);
	OT_ASSERT_MSG(NULL != m_pKey, "OTAsymmetricKey::SetKeyAsCopyOf: ASSERT: NULL != m_pKey \n");
    // ---------------------------
	m_bIsPublicKey	= !bIsPrivateKey;
	m_bIsPrivateKey	= bIsPrivateKey;
    // ---------------------------
    if (NULL == m_p_ascKey)
    {
        m_p_ascKey = new OTASCIIArmor;
        OT_ASSERT(NULL != m_p_ascKey);
    }
    else
    {
        m_p_ascKey->Release();
    }
    // By this point, m_p_ascKey definitely exists, and it's empty.
    // ----------------------
    if (m_bIsPrivateKey)
//        const bool bArmored = 
            OTAsymmetricKey::ArmorPrivateKey(*m_pKey, *m_p_ascKey, m_timer);
    // NOTE: Timer is already set INSIDE ArmorPrivateKey. No need to set twice.
//      m_timer.start(); // Note: this isn't the ultimate timer solution. See notes in ReleaseKeyLowLevel.
    else if (m_bIsPublicKey)
//        const bool bArmored = 
            OTAsymmetricKey::ArmorPublicKey(*m_pKey, *m_p_ascKey);
    else
        OTLog::Error("OTAsymmetricKey::SetKeyAsCopyOf: Error: This key is NEITHER public NOR private!\n");
}
// ------------------------------------------------------


// static bool ArmorPrivateKey(EVP_PKEY & theKey, OTASCIIArmor & ascKey);
// static bool ArmorPublicKey (EVP_PKEY & theKey, OTASCIIArmor & ascKey);


EVP_PKEY * OTAsymmetricKey::GetKeyLowLevel()
{
    return m_pKey;
}


const EVP_PKEY * OTAsymmetricKey::GetKey()
{
    OT_ASSERT_MSG(NULL != m_p_ascKey, "OTAsymmetricKey::GetKey: NULL != m_p_ascKey\n");
    // ----------------------------------------
    
    if (m_timer.getElapsedTimeInSec() > OT_KEY_TIMER)
        ReleaseKeyLowLevel();   // This releases the actual loaded key, but not the ascii-armored, encrypted version of it.
                                // (Thus forcing a reload, and thus forcing the passphrase to be entered again.)
    // ----------------------------------------
    if (NULL == m_pKey)
        return InstantiateKey();  // this is the ONLY place, currently, that this private method is called.
    
	return m_pKey;
}



// Low-level / private
EVP_PKEY * OTAsymmetricKey::InstantiateKey()
{
    if (IsPublic())
        return InstantiatePublicKey();  // this is the ONLY place, currently, that this private method is called.
    
    else if (IsPrivate())
        return InstantiatePrivateKey(); // this is the ONLY place, currently, that this private method is called.
    
    else
        OTLog::Error("OTAsymmetricKey::InstantiateKey: Error: Key is neither public nor private!\n");
    
    return NULL;
}



/*
void OTbase64Decode(unsigned char* pIn, int inLen, unsigned char* pOut, int& outLen)
{
	// create a memory buffer containing base64 encoded data (or binary data if I remove the filter below)
	BIO* bmem = BIO_new_mem_buf((void*)pIn, inLen);
	
	// create a Base64 filter so that reading from buffer decodes it
	BIO *bio64Filter = BIO_new(BIO_f_base64()); 
	BIO_set_flags(bio64Filter, BIO_FLAGS_BASE64_NO_NL); // with no newlines, please.
	
	// push the base64 filter onto the memory buffer
	bmem = BIO_push(bio64Filter, bmem);
	
	// Get the length of the output while also reading it from the BIO
	int finalLen = BIO_read(bmem, (void*)pOut, outLen);
	
	// Free the BIO and related buffers, filters, etc.
	BIO_free_all(bmem);
	
	outLen = finalLen;
}
*/
/*
EVP_PKEY * pKey	OTGetPublicKey(unsigned char* pIn, int inLen, unsigned char* pOut, int& outLen)
{
	// create a memory buffer containing base64 encoded data (or binary data if I remove the filter below)
	BIO* bmem = BIO_new_mem_buf((void*)pIn, inLen);
	
	// create a Base64 filter so that reading from buffer decodes it
	BIO *bio64Filter = BIO_new(BIO_f_base64()); 
	BIO_set_flags(bio64Filter, BIO_FLAGS_BASE64_NO_NL); // with no newlines, please.
	
	// push the base64 filter onto the memory buffer
	bmem = BIO_push(bio64Filter, bmem);
	
	// Get the length of the output while also reading it from the BIO
	int finalLen = BIO_read(bmem, (void*)pOut, outLen);
	
	// Free the BIO and related buffers, filters, etc.
	BIO_free_all(bmem);
	
	outLen = finalLen;
}
 */

/*
 BIO* keyBio = BIO_new_mem_buf(TESTING_PUBLIC_KEY, 
 sizeof(TESTING_PUBLIC_KEY)); 
 public_key = d2i_PUBKEY_bio(keyBio, NULL); 
*/



bool OTAsymmetricKey::CalculateID(OTIdentifier & theOutput) const // Only works for public keys.
{
    const char * szFunc = "OTAsymmetricKey::CalculateID";
    
    theOutput.Release();
    
    if (!IsPublic())
    {
		OTLog::vError("%s: Error: !IsPublic() (This function should only be called on a public key.)\n", szFunc);
		return false;	
    }
    // ------------------------------
	OTString strPublicKey;
	bool bGotPublicKey = this->GetPublicKey(strPublicKey);
	
	if (!bGotPublicKey)
	{
		OTLog::vError("%s: Error getting public key.\n", szFunc);
		return false;	
	}
    // ------------------------------
	bool bSuccessCalculateDigest = theOutput.CalculateDigest(strPublicKey);
	
	if (!bSuccessCalculateDigest)
	{
        theOutput.Release();
		OTLog::vError("%s: Error calculating digest of public key.\n", szFunc);
		return false;	
	}
	
	return true;
}


// -----------------------------------------------------------

// Get the public key in ASCII-armored format with bookends  - ------- BEGIN PUBLIC KEY --------
// This version, so far, is escaped-only. Notice the "- " before the rest of the bookend starts.
bool OTAsymmetricKey::GetPublicKey(OTString & strKey, bool bEscaped/*=true*/) const
{
	OTASCIIArmor theArmor;
	
    // TODO: optimization: When optimizing for CPU cycles, and willing to sacrifice a little RAM, we
    // can save this value the first time it's computed, and then as long as the armored version (without
    // bookends) doesn't change, we can save the computed version and pass it back here, instead of re-generating
    // it here each time this is called. This implies a need for the armored version to be able to be flagged
    // as "dirty" when it is changed.
    
	if (GetPublicKey(theArmor))
	{
		if (bEscaped)
		{
			strKey.Concatenate("- -----BEGIN PUBLIC KEY-----\n"    // ESCAPED VERSION
							   "%s"
							   "- -----END PUBLIC KEY-----\n",
							   theArmor.Get()
							   );
		}
		else
        {
			strKey.Concatenate("-----BEGIN PUBLIC KEY-----\n"      // UN-ESCAPED VERSION
							   "%s"
							   "-----END PUBLIC KEY-----\n",
							   theArmor.Get()
							   );
		}
		return true;
	}
    else
        OTLog::Error("OTAsymmetricKey::GetPublicKey: Error: GetPublicKey(armored) returned false. (Returning false.)\n");
    // ------------
    
    return false;
}


// Get the public key in ASCII-armored format.
//
bool OTAsymmetricKey::GetPublicKey(OTASCIIArmor & ascKey) const
{
    OT_ASSERT_MSG(IsPublic(), "OTAsymmetricKey::GetPublicKey: ASSERT: IsPublic()\n");
    // -----------------------
    ascKey.Release();
    
	if (NULL == m_p_ascKey)
		return false;
	
    ascKey.Set(*m_p_ascKey);
    
    return true;
}



// High-level.
// This is the version that will handle the bookends ( --------- BEGIN PUBLIC KEY -------)
// You can pass it an OTString, and it will then call the lower-level version of SetPublicKey
// (the one that takes an OTASCIIArmor object.)
//
bool OTAsymmetricKey::SetPublicKey(const OTString & strKey, bool bEscaped/*=false*/)
{
	m_bIsPublicKey	= true;
	m_bIsPrivateKey	= false;

	// This reads the string into the Armor and removes the bookends. (----- BEGIN ...)
	OTASCIIArmor theArmor;
	
	if (theArmor.LoadFromString(const_cast<OTString &>(strKey), bEscaped))
	{
		return SetPublicKey(theArmor);
	}
	else
        OTLog::vError("OTAsymmetricKey::SetPublicKey: Error: failed loading ascii-armored contents from bookended string:\n\n%s\n\n",
                      strKey.Get());
    // --------------------
    return false;
}




// Copies to internal ascii-armored string, and wipes any key if
// one is already loaded.
//
bool OTAsymmetricKey::SetPublicKey(const OTASCIIArmor & ascKey)
{	
    ReleaseKeyLowLevel(); // In case the key is already loaded, we release it here. (Since it's being replaced, it's now the wrong key anyway.)
    // ----------------------
    m_bIsPublicKey	= true;
    m_bIsPrivateKey	= false;
    // ----------------------    
    if (NULL == m_p_ascKey)
    {
        m_p_ascKey = new OTASCIIArmor;
        OT_ASSERT(NULL != m_p_ascKey);
    }
    // ----------------------
    m_p_ascKey->Set(ascKey);
    // ----------------------
    return true;
}








//static      // CALLER must EVP_pkey_free!
EVP_PKEY * OTAsymmetricKey::CopyPublicKey(EVP_PKEY & theKey)
{
    const char * szFunc = "OTAsymmetricKey::CopyPublicKey";
    // ----------------------------------------
	// Create a new memory buffer on the OpenSSL side
	BIO *bmem = BIO_new(BIO_s_mem());    
	OT_ASSERT_MSG(NULL != bmem, "OTAsymmetricKey::CopyPublicKey: ASSERT: NULL != bmem");
    
    EVP_PKEY * pReturnKey = NULL;
	// ----------------------------------------
	// write a public key to that buffer, from theKey (parameter.)
    //
	int nWriteBio = PEM_write_bio_PUBKEY(bmem, &theKey);
	
	if (0 == nWriteBio)
	{
		OTLog::vError("%s: Error: Failed writing EVP_PKEY to memory buffer.\n", szFunc);
	}
	else 
	{
		OTLog::vOutput(5, "%s: Success writing EVP_PKEY to memory buffer.\n", szFunc);
		
		char * pChar = NULL;
		
		// After the below call, pChar will point to the memory buffer where the public key
        // supposedly is, and lSize will contain the size of that memory.
        //
		const long lSize = BIO_get_mem_data(bmem, &pChar);
        const int  nSize = static_cast<int>(lSize);
        
        if (nSize > 0)
        {
            // -----------------------------------------------
            // Next, copy theData's contents into a new BIO_mem_buf,
            // so OpenSSL can load the key out of it.
            //
            BIO * keyBio = BIO_new_mem_buf(pChar, nSize); 
            OT_ASSERT_MSG(NULL != keyBio, "OTAsymmetricKey::CopyPublicKey: Assert: NULL != keyBio \n");
            // -------------------------------------------
            // Next we load up the key from the BIO string into an instantiated key object.
            //
            OTPasswordData thePWData("OTAsymmetricKey::CopyPublicKey is calling PEM_read_bio_PUBKEY...");
            
            pReturnKey = PEM_read_bio_PUBKEY(keyBio, NULL, OTAsymmetricKey::GetPasswordCallback(), &thePWData);
            // -------------------------------------------
            // We don't need the BIO anymore.
            // Free the BIO and related buffers, filters, etc.
            //
//          if (theData.GetSize() > 0)
//              OPENSSL_cleanse(keyBio, theData.GetSize());
            BIO_free_all(keyBio);
            keyBio = NULL;
            // -------------------------------------------            
        }
    }
    
	// Free the BIO and related buffers, filters, etc.
    //
//  if (lSize > 0)
//      OPENSSL_cleanse(bmem, lSize);
	BIO_free_all(bmem);
	bmem = NULL;

    return pReturnKey;
}

// NOTE: OpenSSL will store the EVP_PKEY inside the X509, and when I get it, 
// I'm not supposed to destroy the x509 until I destroy the EVP_PKEY FIRST!
// (AND it reference-counts.)
// Since I want ability to destroy the two, independent of each other, I made
// static functions here for copying public and private keys, so I am ALWAYS 
// working with MY OWN copy of any given key, and not OpenSSL's reference-counted
// one.


//static      // CALLER must EVP_pkey_free!
EVP_PKEY * OTAsymmetricKey::CopyPrivateKey(EVP_PKEY & theKey)
{
    const char * szFunc = "OTAsymmetricKey::CopyPrivateKey";    
    // ----------------------------------------
	// Create a new memory buffer on the OpenSSL side
	BIO *bmem = BIO_new(BIO_s_mem());    
	OT_ASSERT(NULL != bmem);
    
    EVP_PKEY * pReturnKey = NULL;
	// ----------------------------------------
	// write a private key to that buffer, from theKey
    //
    OTPasswordData thePWData("OTAsymmetricKey::CopyPrivateKey is calling PEM_write_bio_PrivateKey...");
    
    // todo optimization: might just remove the password callback here, and just write the private key in the clear,
    // and then load it up again, saving the encrypt/decrypt step that otherwise occurs, and then as long as we OpenSSL_cleanse
    // the BIO, then it SHOULD stil be safe, right?
    //
    int nWriteBio = PEM_write_bio_PrivateKey(bmem, &theKey, EVP_des_ede3_cbc(), // todo should this algorithm be hardcoded?
                                             NULL, 0, OTAsymmetricKey::GetPasswordCallback(), &thePWData);
	
	if (0 == nWriteBio)
	{
		OTLog::vError("%s: Failed writing EVP_PKEY to memory buffer.\n", szFunc);
	}
	else 
	{
		OTLog::vOutput(5, "%s: Success writing EVP_PKEY to memory buffer.\n", szFunc);
		
		char * pChar = NULL;
		
		// After the below call, pChar will point to the memory buffer where the private key supposedly is,
		// and lSize will contain the size of that memory.
        //
        const long lSize = BIO_get_mem_data(bmem, &pChar);
        const int  nSize = static_cast<int>(lSize);

		if (nSize > 0)
		{
            // --------------------------------------
            // Copy the encrypted binary private key data into an OpenSSL memory BIO...
            //
            BIO * keyBio = BIO_new_mem_buf(pChar, nSize); 
            OT_ASSERT_MSG(NULL != keyBio, "OTAsymmetricKey::CopyPrivateKey: Assert: NULL != keyBio \n");
            // --------------------------------------
            OTPasswordData thePWData("OTAsymmetricKey::CopyPrivateKey is calling PEM_read_bio_PrivateKey...");
            
            pReturnKey = PEM_read_bio_PrivateKey( keyBio, NULL, OTAsymmetricKey::GetPasswordCallback(), &thePWData );
            
            // Free the BIO and related buffers, filters, etc.
            //
//          if (theData.GetSize() > 0)
//              OPENSSL_cleanse(keyBio, theData.GetSize());
            BIO_free_all(keyBio);
            keyBio = NULL;
            // --------------------------------------
		}
		else 
		{
			OTLog::vError("%s: Failed copying private key into memory.\n", szFunc);
		}
	}
    
	// Free the BIO and related buffers, filters, etc.
    //
//  if (lSize > 0)
//      OPENSSL_cleanse(bmem, lSize);
	BIO_free_all(bmem);
	bmem = NULL;
	
	return pReturnKey;	
}






// -----------------------------------------------------------
// Take a public key, theKey (input), and create an armored version of
// it into ascKey (output.)
//
// OpenSSL loaded key ===> ASCII-Armored export of same key.
//
//static
//
bool OTAsymmetricKey::ArmorPublicKey(EVP_PKEY & theKey, OTASCIIArmor & ascKey)
{
	bool bReturnVal = false;
    
    const char * szFunc = "OTAsymmetricKey::ArmorPublicKey";
    
    ascKey.Release();
    // ----------------------------------------
	// Create a new memory buffer on the OpenSSL side
	BIO *bmem = BIO_new(BIO_s_mem());    
	OT_ASSERT_MSG(NULL != bmem, "OTAsymmetricKey::ArmorPublicKey: ASSERT: NULL != bmem");
    
    long lSize = 0;
	// ----------------------------------------
	// write a public key to that buffer, from theKey (parameter.)
    //
	int nWriteBio = PEM_write_bio_PUBKEY(bmem, &theKey);
	
	if (0 == nWriteBio)
	{
		OTLog::vError("%s: Error: Failed writing EVP_PKEY to memory buffer.\n", szFunc);
	}
	else 
	{
		OTLog::vOutput(5, "%s: Success writing EVP_PKEY to memory buffer.\n", szFunc);
		
		OTPayload theData;
		char * pChar = NULL;
		
		// After the below call, pChar will point to the memory buffer where the public key
        // supposedly is, and lSize will contain the size of that memory.
        //
		lSize = BIO_get_mem_data(bmem, &pChar);
		int  nSize = lSize; // todo security, etc. Fix this assumed type conversion.
		
		if (nSize > 0)
		{
			// Set the buffer size in our own memory.
			theData.SetPayloadSize(nSize);
            
//            void * pv = 
                OTPassword::safe_memcpy((static_cast<char*>(const_cast<void*>(theData.GetPayloadPointer()))), // destination
                                    theData.GetSize(),    // size of destination buffer.
                                    pChar,                // source
                                    nSize);               // length of source.
                                    // bool bZeroSource=false); // if true, sets the source buffer to zero after copying is done.
            
            // ------------------------------------------------
			// This base64 encodes the public key data
            //
			ascKey.SetData(theData);
			
            OTLog::vOutput(5, "%s: Success copying public key into memory.\n", szFunc);
			bReturnVal = true;
		}
		else 
		{
			OTLog::vError("%s: Failed copying public key into memory.\n", szFunc);
		}
	}
    
	// Free the BIO and related buffers, filters, etc.
    //
//  if (lSize > 0)
//      OPENSSL_cleanse(bmem, lSize);
	BIO_free_all(bmem);
	bmem = NULL;
	
	return bReturnVal;	
}



//
//
// Low-level
//
// (Internal) ASCII-Armored key ====> (Internal) Actual loaded OpenSSL key.
//
//
EVP_PKEY * OTAsymmetricKey::InstantiatePublicKey()
{
    OT_ASSERT(m_pKey     == NULL);
    OT_ASSERT(m_p_ascKey != NULL);
    OT_ASSERT(IsPublic());
    
    const char * szFunc = "OTAsymmetricKey::InstantiatePublicKey";
    // ------------------------------
    EVP_PKEY * pReturnKey = NULL;
    OTPayload  theData;
    // -----------------------------------------------
    // This base64 decodes the string m_p_ascKey into the
    // binary payload object "theData"
    //
    m_p_ascKey->GetData(theData);
    // -------------------------------------------
    // Next, copy theData's contents into a new BIO_mem_buf,
    // so OpenSSL can load the key out of it.
    //
    BIO* keyBio	= BIO_new_mem_buf(static_cast<char*>(const_cast<void*>(theData.GetPayloadPointer())), 
                                  theData.GetSize());
	OT_ASSERT_MSG(NULL != keyBio, "OTAsymmetricKey::InstantiatePublicKey: Assert: NULL != keyBio \n");
    // -------------------------------------------
    // Next we load up the key from the BIO string into an instantiated key object.
    //
    OTPasswordData thePWData("OTAsymmetricKey::InstantiatePublicKey is calling PEM_read_bio_PUBKEY...");
    
    pReturnKey = PEM_read_bio_PUBKEY(keyBio, NULL, OTAsymmetricKey::GetPasswordCallback(), &thePWData);
    // -------------------------------------------
    // We don't need the BIO anymore.
    // Free the BIO and related buffers, filters, etc.
    //
//  if (theData.GetSize() > 0)
//      OPENSSL_cleanse(keyBio, theData.GetSize());
    BIO_free_all(keyBio);
    keyBio = NULL;
    // -------------------------------------------
    
    ReleaseKeyLowLevel(); // Release whatever loaded key I might have already had.
    
    if (NULL != pReturnKey)
    {
        m_pKey = pReturnKey;
        OTLog::vOutput(4, "%s: Success reading public key from ASCII-armored data:\n\n%s\n\n",
                       szFunc, m_p_ascKey->Get());
        return m_pKey;
    }
    
    OTLog::vError("%s: Failed reading public key from ASCII-armored data:\n\n%s\n\n", 
                  szFunc, m_p_ascKey->Get());
    return NULL;
}










// -----------------------------------------------------------












// -----------------------------------------------------------

// Get the private key in ASCII-armored format with bookends  - ------- BEGIN ENCRYPTED PRIVATE KEY --------
// This version, so far, is escaped-only. Notice the "- " before the rest of the bookend starts.
//
bool OTAsymmetricKey::GetPrivateKey(OTString & strKey, bool bEscaped/*=true*/) const
{
	OTASCIIArmor theArmor;
	
	if (GetPrivateKey(theArmor))
	{
		if (bEscaped)
		{
			strKey.Concatenate("- -----BEGIN ENCRYPTED PRIVATE KEY-----\n"
							   "%s"
							   "- -----END ENCRYPTED PRIVATE KEY-----\n",
							   theArmor.Get()
							   );
		}
		else 
        {
			strKey.Concatenate("-----BEGIN ENCRYPTED PRIVATE KEY-----\n"
							   "%s"
							   "-----END ENCRYPTED PRIVATE KEY-----\n",
							   theArmor.Get()
							   );
		}
		return true;
	}
    else
        OTLog::Error("OTAsymmetricKey::GetPrivateKey: Error: GetPrivateKey(armored) returned false. (Returning false.)\n");
    // ------------
    
    return false;
}

// Get the private key in ASCII-armored format
//
bool OTAsymmetricKey::GetPrivateKey(OTASCIIArmor & ascKey) const // (ascKey is the output.)
{
    OT_ASSERT(IsPrivate());
    // -------------------------
    ascKey.Release();
    
	if (NULL == m_p_ascKey)
		return false;
	
    ascKey.Set(*m_p_ascKey);
    
    return true;
}


// Decodes a private key from ASCII armor into an actual key pointer
// and sets that as the keypointer on this object.
// This is the version that will handle the bookends ( --------- BEGIN ENCRYPTED PRIVATE KEY -------)
//
bool OTAsymmetricKey::SetPrivateKey(const OTString & strKey, bool bEscaped/*=false*/)
{
	m_bIsPublicKey	= false;
	m_bIsPrivateKey	= true;
        
	// This reads the string into the Armor and removes the bookends. (----- BEGIN ...)
    //
	OTASCIIArmor theArmor;
    const char * szPrivateKeyStarts = "-----BEGIN ENCRYPTED PRIVATE KEY-----";	
	if (theArmor.LoadFromString(const_cast<OTString &>(strKey), bEscaped,
                                szPrivateKeyStarts)) // This last param causes OTASCIIArmor to only "start loading" when it reaches the private key.
    {
		return SetPrivateKey(theArmor);
    }

    return false;
}


// Copies to the internal ascii-armored storage. Wipes the internal
// private key, if one is loaded.
//
bool OTAsymmetricKey::SetPrivateKey(const OTASCIIArmor & ascKey)
{	
    ReleaseKeyLowLevel();
    // ----------------------
	m_bIsPublicKey	= false;
	m_bIsPrivateKey	= true;     // PRIVATE KEY
    // ----------------------    
    if (NULL == m_p_ascKey)
    {
        m_p_ascKey = new OTASCIIArmor;
        OT_ASSERT(NULL != m_p_ascKey);
    }
    // ----------------------
    m_p_ascKey->Set(ascKey);
    // ----------------------
    return true;
}

// -----------------------------------------------------------


// Low-level
//
// Note: Be sure to ReleaseKey() when you're done with it.
// Note: the way that should work is, the programmatic user should Get the Key and
// then Release the key immediately before and after using it. But they should be
// HIGH-LEVEL functions, which handle the timer stuff internally.
//
EVP_PKEY * OTAsymmetricKey::InstantiatePrivateKey()
{
    OT_ASSERT(m_pKey     == NULL);
    OT_ASSERT(m_p_ascKey != NULL);
    OT_ASSERT(IsPrivate());    
    // ------------------------------    
	EVP_PKEY * pReturnKey = NULL;
	OTPayload theData;  // after base64-decoding the ascii-armored string, the (encrypted) binary will be stored here.
	// --------------------------------------	
	// This line base64 decodes the ascii-armored string into binary object theData...
    //
	m_p_ascKey->GetData(theData); // theData now contains binary data, the encrypted private key itself, no longer in text-armoring.
    //
    // Note, for future optimization: the ASCII-ARMORING could be used for serialization, but the BIO (still encrypted)
    // could be used in RAM for this object. Otherwise you just have to do the extra step of ascii-decoding it first to get
    // the BIO, before being able to instantiate the key itself from that. That final step can't change, but I can remove
    // the step before it, in most cases, by just storing the BIO itself, instead of the ascii-armored string. Or perhaps
    // make them both available...hm.
	// --------------------------------------
    // Copy the encrypted binary private key data into an OpenSSL memory BIO...
    //
	BIO * keyBio = BIO_new_mem_buf(static_cast<char*>(const_cast<void*>(theData.GetPayloadPointer())), 
                                   theData.GetSize()); // theData will zeroMemory upon destruction.
	OT_ASSERT_MSG(NULL != keyBio, "OTAsymmetricKey::InstantiatePrivateKey: Assert: NULL != keyBio \n");
	// --------------------------------------
    
    OTPasswordData thePWData("OTAsymmetricKey::InstantiatePrivateKey is calling PEM_read_bio_PrivateKey...");

	pReturnKey = PEM_read_bio_PrivateKey( keyBio, NULL, OTAsymmetricKey::GetPasswordCallback(), &thePWData );
    
	// Free the BIO and related buffers, filters, etc.
    //
//    if (theData.GetSize() > 0)
//        OPENSSL_cleanse(keyBio, theData.GetSize());
	BIO_free_all(keyBio);
	keyBio = NULL;
	// --------------------------------------
    
	ReleaseKeyLowLevel();
	
	if (NULL != pReturnKey)
	{
		m_pKey = pReturnKey;
        // TODO (remove theTimer entirely. OTMasterKey replaces already.)
        // I set this timer because the above required a password. But now that master key is working,
        // the above would flow through even WITHOUT the user typing his passphrase (since master key still
        // not timed out.) Resulting in THIS timer being reset!  Todo: I already shortened this timer to 30
        // seconds, but need to phase it down to 0 and then remove it entirely! Master key takes over now!
        //

        m_timer.start();  // Note: this isn't the ultimate timer solution. See notes in ReleaseKeyLowLevel.
		OTLog::vOutput(4, "OTAsymmetricKey::InstantiatePrivateKey: Success reading private key from ASCII-armored data:\n\n%s\n\n",
                       m_p_ascKey->Get());
		return m_pKey;
	}
    OTLog::vError("OTAsymmetricKey::InstantiatePrivateKey: Failed reading private key from ASCII-armored data:\n\n%s\n\n",
                  m_p_ascKey->Get());
    return NULL;
}
                                            
// -----------------------------------------------------------

//static
bool OTAsymmetricKey::ArmorPrivateKey(EVP_PKEY & theKey, OTASCIIArmor & ascKey, Timer & theTimer)
{
	bool bReturnVal = false;
    
    const char * szFunc = "OTAsymmetricKey::ArmorPrivateKey";
    
    ascKey.Release();
    // ----------------------------------------
	// Create a new memory buffer on the OpenSSL side
	BIO *bmem = BIO_new(BIO_s_mem());    
	OT_ASSERT(NULL != bmem);
    
    long lSize = 0;
	// ----------------------------------------
	// write a private key to that buffer, from theKey
    //
    OTPasswordData thePWData("OTAsymmetricKey::ArmorPrivateKey is calling PEM_write_bio_PrivateKey...");

    int nWriteBio = PEM_write_bio_PrivateKey(bmem, &theKey, EVP_des_ede3_cbc(), // todo should this algorithm be hardcoded?
                                             NULL, 0, OTAsymmetricKey::GetPasswordCallback(), &thePWData);
	
	if (0 == nWriteBio)
	{
		OTLog::vError("%s: Failed writing EVP_PKEY to memory buffer.\n", szFunc);
	}
	else 
	{
        // TODO (remove theTimer entirely. OTMasterKey replaces already.)
        // I set this timer because the above required a password. But now that master key is working,
        // the above would flow through even WITHOUT the user typing his passphrase (since master key still
        // not timed out.) Resulting in THIS timer being reset!  Todo: I already shortened this timer to 30
        // seconds, but need to phase it down to 0 and then remove it entirely! Master key takes over now!
        //

        theTimer.start(); // Note: this isn't the ultimate timer solution. See notes in ReleaseKeyLowLevel.
        // --------------------
		OTLog::vOutput(5, "%s: Success writing EVP_PKEY to memory buffer.\n", szFunc);
		
		OTPayload theData;
		char * pChar = NULL;
		
		// After the below call, pChar will point to the memory buffer where the private key supposedly is,
		// and lSize will contain the size of that memory.
        //
		lSize = BIO_get_mem_data(bmem, &pChar);
		int  nSize = lSize;
		
		if (nSize > 0)
		{
			// Set the buffer size in our own memory.
			theData.SetPayloadSize(nSize);
            
//            void * pv = 
                OTPassword::safe_memcpy((static_cast<char*>(const_cast<void*>(theData.GetPayloadPointer()))), // destination
                                    theData.GetSize(),    // size of destination buffer.
                                    pChar,                // source
                                    nSize);               // length of source.
            // bool bZeroSource=false); // if true, sets the source buffer to zero after copying is done.
            
            // ------------------------------------------------
			// This base64 encodes the private key data, which
            // is already encrypted to its passphase as well.
            //
			ascKey.SetData(theData);
			
            OTLog::vOutput(5, "%s: Success copying private key into memory.\n", szFunc);
			bReturnVal = true;
		}
		else 
		{
			OTLog::vError("%s: Failed copying private key into memory.\n", szFunc);
		}
	}
    
	// Free the BIO and related buffers, filters, etc.
    //
//    if (lSize > 0)
//        OPENSSL_cleanse(bmem, lSize);
	BIO_free_all(bmem);
	bmem = NULL;
	
	return bReturnVal;	
}







// -----------------------------------------------------------


/*
 * An implementation of convertion from PGP public key format to OpenSSL equivalent
 * Support of RSA, DSA and Elgamal public keys
 *
 * Copyright (c) 2010 Mounir IDRASSI <mounir.idrassi@idrix.fr>. All rights reserved.
 *
 * This program is distributed in the hope that it will be useful, 
 * but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY 
 * or FITNESS FOR A PARTICULAR PURPOSE.
 * 
 */

PgpKeys ExportRsaKey(unsigned char *pbData, int dataLength)
{
	PgpKeys pgpKeys;
	int i;
	
	memset(&pgpKeys, 0, sizeof(pgpKeys));
	for (i = 0; i < dataLength; )
	{
		int packetLength;
		unsigned char packetTag = pbData[i++];
		if ((packetTag & 0x80) == 0) 
			break;
		if ((packetTag & 0x40))
		{
			packetTag &= 0x3F;
			packetLength = pbData[i++];
			if( (packetLength >191) && (packetLength <224)) 
				packetLength = ((packetLength-192) << 8) + pbData[i++];
			else if( (packetLength > 223) && (packetLength < 255))
				packetLength = (1 << (packetLength & 0x1f)); 
			else if(packetLength == 255) 
			{
				packetLength = (pbData[i]<<24) + (pbData[i+1]<<16) + (pbData[i+2]<<8) + pbData[i+3];
				i+=4;
			}
		}
		else
		{
			packetLength = packetTag & 3;
			packetTag = (packetTag >> 2) & 15;
			if(packetLength == 0) 
				packetLength = pbData[i++];
			else if(packetLength == 1) 
			{
				packetLength = (pbData[i]<<8) + pbData[i+1];
				i+=2;
			}
			else if(packetLength == 2) 
			{
				packetLength = (pbData[i]<<24) + (pbData[i+1]<<16) + (pbData[i+2]<<8) + pbData[i+3];
				i+=4;
			}
			else 
				packetLength = dataLength - 1;
		}
		
		if( (packetTag==6) || (packetTag==14) )  //  a public key
		{
			int algorithm;
			int version = pbData[i++];
			
			// skip time over 4 bytes
			i += 4;
			
			if( (version==2) || (version==3) )
			{
				// skip validity over 2 bytes
				i += 2;
			}
			
			algorithm = pbData[i++];
			
			if( (algorithm == 1) || (algorithm == 2) || (algorithm == 3) ) // an RSA key
			{
				int modulusLength, exponentLength;
				RSA* pKey = RSA_new();
				
				// Get the modulus
				modulusLength = ((pbData[i]*256 + pbData[i+1]+7)/8);
				pKey->n = BN_bin2bn (pbData + i + 2, modulusLength, NULL);
				i += modulusLength + 2;
				
				// Get the exponent
				exponentLength = (pbData[i]*256 + pbData[i+1]+7)/8;
				pKey->e = BN_bin2bn(pbData + i + 2, exponentLength, NULL);
				i += exponentLength + 2;
				
				pgpKeys.pRsa = pKey;
				
				continue;
			}
			else if (algorithm == 17) // a DSA key
			{
				int pLen, qLen, gLen, yLen;
				DSA* pKey = DSA_new();
				
				// Get Prime P
				pLen = ((pbData[i]*256 + pbData[i+1]+7)/8);
				pKey->p = BN_bin2bn(pbData + i + 2, pLen, NULL);
				i += pLen + 2;
				
				// Get Prime Q
				qLen = ((pbData[i]*256 + pbData[i+1]+7)/8);
				pKey->q = BN_bin2bn(pbData + i + 2, qLen, NULL);
				i += qLen + 2;
				
				// Get Prime G
				gLen = ((pbData[i]*256 + pbData[i+1]+7)/8);
				pKey->g = BN_bin2bn(pbData + i + 2, gLen, NULL);
				i += gLen + 2;
				
				// Get Prime Y
				yLen = ((pbData[i]*256 + pbData[i+1]+7)/8);
				pKey->pub_key = BN_bin2bn(pbData + i + 2, yLen, NULL);
				i += yLen + 2;
				
				pgpKeys.pDsa = pKey;
				
				continue;
			}
			else if ((algorithm == 16) || (algorithm == 20)) // Elgamal key (not supported by OpenSSL
			{
				int pLen, gLen, yLen;
				ELGAMAL* pKey = (ELGAMAL*) malloc(sizeof(ELGAMAL));
				
				// Get Prime P
				pLen = ((pbData[i]*256 + pbData[i+1]+7)/8);
				pKey->p = BN_bin2bn(pbData + i + 2, pLen, NULL);
				i += pLen + 2;
				
				// Get Prime G
				gLen = ((pbData[i]*256 + pbData[i+1]+7)/8);
				pKey->g = BN_bin2bn(pbData + i + 2, gLen, NULL);
				i += gLen + 2;
				
				// Get Prime Y
				yLen = ((pbData[i]*256 + pbData[i+1]+7)/8);       
				pKey->pub_key = BN_bin2bn(pbData + i + 2, yLen, NULL);
				i += yLen + 2;
				
				pgpKeys.pElgamal = pKey;
				
				continue;
			}
			else
			{
				i -= 6;
				if (version == 2 || version == 3)
					i -= 2;
			}
		}
		
		i += packetLength;	
	}
	
	return pgpKeys;
}






// Decodes a PGP public key from ASCII armor into an actual key pointer
// and sets that as the keypointer on this object.
// This function expects the bookends to be GONE already
// It just wants the base64 encoded data which is why we have ascii-armor
// object coming in instead of a string.
bool OTAsymmetricKey::LoadPublicKeyFromPGPKey(const OTASCIIArmor & strKey)
{	
    Release();
    // ---------------------
    
	m_bIsPublicKey	= true;
	m_bIsPrivateKey	= false;

	/*
	EVP_PKEY * pReturnKey = NULL;
	OTPayload theData;
	
	// This base64 decodes the string into binary object theData
	strKey.GetData(theData);
	
	BIO* keyBio	= BIO_new_mem_buf((void*)theData.GetPayloadPointer(), theData.GetSize());
	
	//TODO Figure out which one of these is right, if any
	//	pReturnKey	= d2i_PUBKEY_bio(keyBio, NULL); 
	pReturnKey = PEM_read_bio_PUBKEY(keyBio, NULL, OTAsymmetricKey::GetPasswordCallback(), NULL); // we'll try this one next
	
	// Free the BIO and related buffers, filters, etc.
	BIO_free_all(keyBio);
	
	Release();
	
	if (NULL != pReturnKey)
	{
		m_pKey = pReturnKey;
//		OTLog::vOutput(4, "Success reading public key from ASCII-armored data:\n%s",strKey.Get());
		return true;
	}
	else 
    {
//		OTLog::vOutput(4, "Failed reading public key from ASCII-armored data:\n%s",strKey.Get());
		return false;
	}
	
	*/
	
	
	/*
	 * An implementation of convertion from PGP public key format to OpenSSL equivalent
	 * Support of RSA, DSA and Elgamal public keys
	 *
	 * Copyright (c) 2010 Mounir IDRASSI <mounir.idrassi@idrix.fr>. All rights reserved.
	 *
	 * This program is distributed in the hope that it will be useful, 
	 * but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY 
	 * or FITNESS FOR A PARTICULAR PURPOSE.
	 * 
	 */
	int iRet =-1, len;
	BIO *bio, *b64, *bio_out;
	unsigned char buffer[520]; // Making it a bit bigger than 512 for safety reasons.
	BUF_MEM *bptr;
	PgpKeys pgpKeys;
	
	b64 = BIO_new(BIO_f_base64());
	bio = BIO_new_mem_buf((void*)strKey.Get(), strKey.GetLength());
	bio_out = BIO_new(BIO_s_mem());
	bio = BIO_push(b64, bio);
	
	while((len = BIO_read(bio, buffer, 512)) > 0)
		BIO_write(bio_out, buffer, len);
	BIO_free_all(bio);
	bio = NULL;
	
	BIO_get_mem_ptr(bio_out, &bptr);
	
	pgpKeys = ExportRsaKey((unsigned char*)bptr->data, bptr->length);
	
	if(!pgpKeys.pRsa)
	{  
		OTLog::Output(5,  "\nNo RSA public key found.\n\n"); 
	}
	else
	{
		char* szModulusHex = BN_bn2hex(pgpKeys.pRsa->n);
		char* szExponentHex = BN_bn2hex(pgpKeys.pRsa->e);
		OTLog::vOutput(5, "RSA public key found : \n  Modulus (%d bits)\n", BN_num_bits(pgpKeys.pRsa->n));
		OTLog::vOutput(5, "  Exponent : 0x%s\n\n", szExponentHex);
		OTLog::vOutput(5, "RSA public key found : \nModulus (%d bits) : 0x%s\n", BN_num_bits(pgpKeys.pRsa->n), szModulusHex);
		OTLog::vOutput(5, "Exponent : 0x%s\n\n", szExponentHex);
		
		CRYPTO_free(szModulusHex);
		CRYPTO_free(szExponentHex);
	}
	
	if(!pgpKeys.pDsa)
	{  
		OTLog::Output(5, "No DSA public key found.\n\n"); 
	}
	else
	{
		char* szPHex = BN_bn2hex(pgpKeys.pDsa->p);
		char* szQHex = BN_bn2hex(pgpKeys.pDsa->q);
		char* szGHex = BN_bn2hex(pgpKeys.pDsa->g);
		char* szYHex = BN_bn2hex(pgpKeys.pDsa->pub_key);
		OTLog::vOutput(5, "DSA public key found : \n  p (%d bits)\n", BN_num_bits(pgpKeys.pDsa->p));
		OTLog::vOutput(5, "  q (%d bits)\n", BN_num_bits(pgpKeys.pDsa->q));
		OTLog::vOutput(5, "  g (%d bits)\n", BN_num_bits(pgpKeys.pDsa->g));
		OTLog::vOutput(5, "public key (%d bits)\n\n", BN_num_bits(pgpKeys.pDsa->pub_key));
		OTLog::vOutput(5, "DSA public key found : \np (%d bits) : 0x%s\n", BN_num_bits(pgpKeys.pDsa->p), szPHex);
		OTLog::vOutput(5, "q (%d bits) : 0x%s\n", BN_num_bits(pgpKeys.pDsa->q),szQHex);
		OTLog::vOutput(5, "g (%d bits) : 0x%s\n", BN_num_bits(pgpKeys.pDsa->g),szGHex);
		OTLog::vOutput(5, "public key (%d bits) : 0x%s\n\n", BN_num_bits(pgpKeys.pDsa->pub_key),szYHex);
		
		CRYPTO_free(szPHex);
		CRYPTO_free(szQHex);
		CRYPTO_free(szGHex);
		CRYPTO_free(szYHex);
	}
	
	if(!pgpKeys.pElgamal)
	{  
		OTLog::Output(5, "No Elgamal public key found.\n\n"); 
	}
	else
	{
		char* szPHex = BN_bn2hex(pgpKeys.pElgamal->p);
		char* szGHex = BN_bn2hex(pgpKeys.pElgamal->g);
		char* szYHex = BN_bn2hex(pgpKeys.pElgamal->pub_key);
		OTLog::vOutput(5, "Elgamal public key found : \n  p (%d bits) : 0x%s\n", BN_num_bits(pgpKeys.pElgamal->p), szPHex);
		OTLog::vOutput(5, "  g (%d bits) : 0x%s\n", BN_num_bits(pgpKeys.pElgamal->g),szGHex);
		OTLog::vOutput(5, "  public key (%d bits) : 0x%s\n\n", BN_num_bits(pgpKeys.pElgamal->pub_key),szYHex);
		
		CRYPTO_free(szPHex);
		CRYPTO_free(szGHex);
		CRYPTO_free(szYHex);
	}
	
	iRet = 0;
	
	BIO_free(bio_out);
	bio_out = NULL;
	
	/*
	if (pgpKeys.pRsa)
		RSA_free(pgpKeys.pRsa);
	if (pgpKeys.pDsa)
		DSA_free(pgpKeys.pDsa);
	if (pgpKeys.pElgamal)
		free(pgpKeys.pElgamal);
	*/
	
    // -------------------------------------------------------

	bool		bReturnValue	= false;
	EVP_PKEY *	pkey			= EVP_PKEY_new();
	OT_ASSERT(NULL != pkey);
	
	if (pgpKeys.pRsa)
	{
		if (EVP_PKEY_assign_RSA(pkey, pgpKeys.pRsa))
		{
			bReturnValue	= true;
            // todo: make sure the lack of RSA_free here is not a memory leak.            
			OTLog::Output(4, "Successfully extracted RSA public key from PGP public key block.\n");
		}
		else
		{
			RSA_free(pgpKeys.pRsa);
			OTLog::Output(0, "Extracted RSA public key from PGP public key block, but unable to convert to EVP_PKEY.\n");
		}

		pgpKeys.pRsa = NULL;
	}
	else if (pgpKeys.pDsa)
	{
		if (EVP_PKEY_assign_DSA(pkey, pgpKeys.pDsa))
		{
			bReturnValue	= true;
            // todo: make sure the lack of DSA_free here is not a memory leak.
			OTLog::Output(4, "Successfully extracted DSA public key from PGP public key block.\n");
		}
		else
		{
			DSA_free(pgpKeys.pDsa);
			OTLog::Output(0, "Extracted DSA public key from PGP public key block, but unable to convert to EVP_PKEY.\n");
		}
		
		pgpKeys.pDsa = NULL;
	}
	else if (pgpKeys.pElgamal)
	{
		OTLog::Output(0, "Extracted ElGamal Key from PGP public key block, but currently do not support it (sorry))\n");
        //
		// int EVP_PKEY_assign_EC_KEY(EVP_PKEY *pkey,EC_KEY *key); // Here is the assign function for El Gamal 
		// (assuming that "EC" stands for eliptical curve... kind of hard to tell with the OpenSSL docs...)
        //
		free(pgpKeys.pElgamal); 
		pgpKeys.pElgamal = NULL;
	}
    // -------------------------------------------------------
    // FT: Adding some fixes here...
    //
    if (bReturnValue)
    {
        this->SetKeyAsCopyOf(*pkey, false); // bIsPrivateKey=false. PUBLIC KEY.
        EVP_PKEY_free(pkey); // We have our own copy already. It's set NULL just below...
    }
    else if (NULL != pkey) // we failed, but pkey is NOT null (need to free it.)
    {
            EVP_PKEY_free(pkey); // Set NULL just below...
    }
    // ---------------------------
    
	pkey = NULL; // This is either stored on m_pKey, or deleted. I'm setting pointer to NULL here just for completeness.
		
	return bReturnValue;
    
	//	EVP_cleanup(); // removes digests from the table
	//	ERR_free_strings(); // removes error strings.
}


/*
bool OTAsymmetricKey::SetPublicKey(OTASCIIArmor & strKey)
{	
	EVP_PKEY * pReturnKey = NULL;
	
	// create a memory buffer containing the ascii-armored Key data
	BIO* bmem = BIO_new_mem_buf((void *)strKey.Get(), strKey.GetLength());
	
	// create a Base64 filter so that reading from buffer decodes it
	BIO *bio64Filter = BIO_new(BIO_f_base64()); 
	//BIO_set_flags(bio64Filter, BIO_FLAGS_BASE64_NO_NL); // with no newlines, please.
	
	// push the base64 filter onto the memory buffer
	bmem = BIO_push(bio64Filter, bmem);
	
	// Reads from a BIO into a public key
	pReturnKey = PEM_read_bio_PUBKEY(bmem, NULL, OTAsymmetricKey::GetPasswordCallback(), NULL);
	
	// Free the BIO and related buffers, filters, etc.
	BIO_free_all(bmem);
	
	Release();
	
	if (NULL != pReturnKey)
	{
		m_pKey = pReturnKey;
		OTLog::vOutput(4, "Success reading public key from ASCII-armored data:\n%s", strKey.Get());
		return true;
	}
	else {
		OTLog::vError("Failed reading public key from ASCII-armored data:\n%s", strKey.Get());
		return false;
	}
}
*/
/*
 
 bool OTAsymmetricKey::SetPublicKey(OTASCIIArmor & strKey)
 {
 OTPayload theData;
 
 // This base64 decodes the string into binary object theData
 strKey.GetData(theData);
 
 // Next I ask OpenSSL to allocate a public key handle for me,
 // based on the binary key data that I show in memory.
 //	const unsigned char * pChar	= (const unsigned char*)theData.GetPayloadPointer();
 
 EVP_PKEY * pKey	= NULL;
 EVP_PKEY * pReturnKey = NULL;
 
 // create a memory buffer containing the (already decoded) binary Key data
 BIO* bmem = BIO_new_mem_buf(theData.GetPayloadPointer(), theData.GetSize());
 
 // Reads from a BIO into a public key
 pReturnKey = PEM_read_bio_PUBKEY(bmem, &pKey, OTAsymmetricKey::GetPasswordCallback(), NULL);
 
 // Free the BIO and related buffers, filters, etc.
 BIO_free_all(bmem);
 
 Release();
 
 if (NULL != pReturnKey)
 {
 m_pKey = pReturnKey;
		OTLog::vOutput(4,  "Success reading public key from ASCII-armored data.\n");
 return true;
 }
 else {
		OTLog::Error("Failed reading public key from ASCII-armored data.\n");
 return false;
 }
 }
 
 */


/*
 bool OTAsymmetricKey::GetPublicKey(OTASCIIArmor & strKey)
 {
 if (NULL == m_pKey)
 return false;
 
 // I assume the 0 passed in here is what tells it to give us the length
 OTPayload theData;
 unsigned char *next;
 
 int nLength = i2d_PublicKey(m_pKey, 0);
 
 theData.SetPayloadSize(nLength);
 
 next = (unsigned char *) theData.GetPayloadPointer();
 
 i2d_PublicKey(m_pKey, &next); // If we use buf here, return buf; becomes wrong. So we use next.
 
 // This base64 encodes the public key data
 strKey.SetData(theData);
 
 return true;
 
 }
 */



/*
 BIO *infile;
 infile = BIO_new_file(strFilename.Get(), "r");
 
 if (!infile)
 //Error
 ;
 
 BIO_printf(infile, "Hello World\n");
 BIO_free(infile); 
 */

// Does public key only.
OTAsymmetricKey & OTAsymmetricKey::operator=(const OTAsymmetricKey & rhs)
{
	// Already done in SetPublicKey()
//	m_bIsPublicKey	= true;
//	m_bIsPrivateKey	= false;

	if ((&rhs != this) && (false == rhs.IsPrivate()) && (rhs.IsPublic()))
	{
		OTASCIIArmor ascTransfer;
		
		// Get the Issuer's public key in ASCII-armored format
		rhs.GetPublicKey(ascTransfer);
		
		// Decodes a public key from ASCII armor into m_keyPublic, which stores it as a EVP_PKEY pointer.
		this->SetPublicKey(ascTransfer);		
	}
	
	return *this;
}


// Does public key only.
//
OTAsymmetricKey::OTAsymmetricKey(const OTAsymmetricKey & rhs) : 
    m_pX509(NULL),
    m_p_ascKey(NULL),
    m_pKey(NULL),
    m_bIsPublicKey(true),   // PUBLIC KEY
    m_bIsPrivateKey(false)
{
	if ((&rhs != this) && (false == rhs.IsPrivate()) && (rhs.IsPublic()))
	{
		OTASCIIArmor ascTransfer;
		
		// Get the Issuer's public key in ASCII-armored format
		rhs.GetPublicKey(ascTransfer);
		
		// Decodes a public key from ASCII armor into m_keyPublic, which stores it as a EVP_PKEY pointer.
		this->SetPublicKey(ascTransfer);
	}
    else
        OTLog::Error("OTAsymmetricKey::OTAsymmetricKey: Error: Asymmetric key construction attempt either with itself, "
                     "or with a private key (when expecting public.)\n");
}


OTAsymmetricKey::OTAsymmetricKey() :
    m_pX509(NULL),
    m_p_ascKey(NULL),
    m_pKey(NULL),
    m_bIsPublicKey(false),
    m_bIsPrivateKey(false)
{
    
}


OTAsymmetricKey::~OTAsymmetricKey()
{
	Release();
    // -------------------------
    if (NULL != m_pX509)
        X509_free(m_pX509);
    m_pX509 = NULL;
    // -------------------------
}

void OTAsymmetricKey::ReleaseKeyLowLevel()
{
    // Release the instantiated OpenSSL key (unsafe to store in this form.)
    //
    if (NULL != m_pKey)
        EVP_PKEY_free (m_pKey); 
    m_pKey = NULL;
    // -------------------------
    m_timer.clear();
    // -------------------------
//	m_bIsPrivateKey = false;  // Every time this Releases, I don't want to lose what kind of key it was. (Once we know, we know.)
    // -------------------------
}

// High-level, used only by programmatic user, not by this class internally.
//
void OTAsymmetricKey::ReleaseKey()
{
    // Todo: someday put a timer inside this class, so it doesn't REALLY release the
    // key until the Timer has expired. 
    // NOTE: marking this as "todo" because I won't necessarily want it done this way. This
    // solution would keep the actual private key loaded in OpenSSL, meaning I'd have to take
    // over the OpenSSL memory management to make it into a safe solution (though I probably
    // have to do that anyway.)
    // A better solution might be to have a random session key used for protecting a hashed
    // version of the passphrase, and then ALWAYS destroying the key as fast as possible, 
    // instead using the hashed passphrase within the bounds of a timer, with the hashed passphrase
    // being decrypted JUST before use and then destroyed, just as the private key is destroyed.
    // I might also wish such a thing was stored not just in OT protected memory, but in a standard
    // *API* for protected memory, such as ssh-agent or the Mac Keychain. However, that can easily 
    // be just an option to be added later, meaning I can go ahead and code my hashed password solution
    // in the meantime. But will that be coded here at the OTAsymmetricKey level? Or at the Nym level,
    // or at the static Nym level, or the app level? Hmm...
    //
    // Security:
    // UPDATE: Since the above solution is coming at some point anyway, I'm going ahead and adding a 
    // Timer version that works at this level (OTAsymmetricKey.)  The reason is because it will be quick
    // and easy, and will give me the functionality I need for now, until I code all the stuff above.
    // Just keep in mind: This is good enough for now, but it WILL result in the private key staying
    // loaded in memory until the timer runs out, meaning if an attacker has access to the RAM on the
    // local machine, if I haven't replaced the OpenSSL memory management, then that is a security issue.
    //
    // TODO (remove theTimer entirely. OTMasterKey replaces already.)
    // I set this timer because the above required a password. But now that master key is working,
    // the above would flow through even WITHOUT the user typing his passphrase (since master key still
    // not timed out.) Resulting in THIS timer being reset!  Todo: I already shortened this timer to 30
    // seconds, but need to phase it down to 0 and then remove it entirely! Master key takes over now!
    //

    // -------------------------    
    
    if (m_timer.getElapsedTimeInSec() > OT_KEY_TIMER)
        ReleaseKeyLowLevel();
    
    // Programmatic user (developer) may call ReleaseKey, but then we don't actually release it until it's
    // been at least X minutes.
    
    // -------------------------
}

                                
void OTAsymmetricKey::Release()
{
    // -------------------------
    // Release the ascii-armored version of the key (safe to store in this form.)
    //
    if (NULL != m_p_ascKey)
        delete m_p_ascKey;
    m_p_ascKey = NULL;
    // -------------------------
    // Release the instantiated OpenSSL key (unsafe to store in this form.)
    //
    ReleaseKeyLowLevel();
    // -------------------------
//	m_bIsPrivateKey = false;  // Every time this Releases, I don't want to lose what kind of key it was. (Once we know, we know.)
    // -------------------------
}



// Load the private key from a .pem file
//
// (Using OTPassword to store the Cert String (private key) since it's more secure than OTString.)
//
bool OTAsymmetricKey::LoadPrivateKeyFromCertString(const
                                                   OTString & strCert, // Contains certificate and private key.
                                                   bool bEscaped/*=true*/) // "escaped" means pre-pended with "- " as in:   - -----BEGIN CER....
{    
	Release();
	
	m_bIsPublicKey	= false;
	m_bIsPrivateKey	= true;

	// --------------------------------------------------------------------
	//
	if (!strCert.Exists())
	{
		OTLog::Error("OTAsymmetricKey::LoadPrivateKeyFromCertString: Error: Cert input is nonexistent!\n");
		return false;
	}
	// --------------------------------------------------------------------
	
    // Read private key
    //
	OTString strWithBookends;
	OTLog::Output(3,  "LoadPrivateKeyFromCertString: FYI, Reading private key from x509 stored in bookended string...\n"); 

	if (bEscaped)
	{
		OTASCIIArmor theArmor;
        
		// I only have a CERTIFICATE 'if' here, not a PUBLIC KEY 'if'.
		// That's because this function is called "LoadPublicKeyFrom*CERT*String"
		// If you want to load a public key from a public key string, then call the
		// other function that does that.
		if (theArmor.LoadFromString(const_cast<OTString &>(strCert), true, // passing bEscaped in as true explicitly here.
                                    "-----BEGIN ENCRYPTED PRIVATE")) // It will start loading from THIS substring...
			strWithBookends.Format("-----BEGIN ENCRYPTED PRIVATE KEY-----\n%s-----END ENCRYPTED PRIVATE KEY-----\n", 
								   theArmor.Get());
		else 
		{
			OTLog::Error("OTAsymmetricKey::LoadPrivateKeyFromCertString: Error extracting ASCII-Armored text from Cert String.\n");
			return false;
		}
	}
	else // It's not escaped already, so no need to remove the escaping, in this case.
    {
		strWithBookends = strCert;
	}
    // *****************************************************
    
	// Create a new memory buffer on the OpenSSL side.
    //
//	BIO * bio = BIO_new(BIO_s_mem());
    BIO * bio = BIO_new_mem_buf(static_cast<void*>(const_cast<char*>(strWithBookends.Get())), strWithBookends.GetLength() /*+1*/); 
	OT_ASSERT_MSG(NULL != bio, "OTAsymmetricKey::LoadPrivateKeyFromCertString: Assert: NULL != bio \n");	

	// --------------------------------------------------------------------
	{
		// TODO security: Need to replace PEM_read_bio_PrivateKey().
		/* The old PrivateKey write routines are retained for compatibility. 
		 New applications should write private keys using the PEM_write_bio_PKCS8PrivateKey() or PEM_write_PKCS8PrivateKey() 
		 routines because they are more secure (they use an iteration count of 2048 whereas the traditional routines use a
		 count of 1) unless compatibility with older versions of OpenSSL is important.
		 NOTE: The PrivateKey read routines can be used in all applications because they handle all formats transparently.
		 */
        OTPasswordData thePWData("OTAsymmetricKey::LoadPrivateKeyFromCertString is calling PEM_read_bio_PrivateKey...");

        EVP_PKEY * pkey = PEM_read_bio_PrivateKey( bio, NULL, OTAsymmetricKey::GetPasswordCallback(), &thePWData );
                
//        if (strWithBookends.GetLength() > 0)
//            OPENSSL_cleanse(bio, strWithBookends.GetLength());        
		BIO_free_all(bio);
		bio = NULL;
		// ------------------------------------------------------
		
		if (NULL == pkey) 
		{ 
			OTLog::vError("OTAsymmetricKey::LoadPrivateKeyFromCertString: Error reading private key from string:\n\n%s\n\n",
						  strWithBookends.Get());
			return false; 
		}
		else 
		{
            // Note: no need to start m_timer here since SetKeyAsCopyOf already calls ArmorPrivateKey, which does that.
            //
            this->SetKeyAsCopyOf(*pkey, true); // bIsPrivateKey=false by default, but true here.
            EVP_PKEY_free(pkey);
            pkey = NULL;
			OTLog::Output(3, "OTAsymmetricKey::LoadPrivateKeyFromCertString: Successfully loaded private key, FYI.\n");
			return true;
		}
	}
	// -------------------
    
	if (NULL != bio)
    {
//        if (strWithBookends.GetLength() > 0)
//            OPENSSL_cleanse(bio, strWithBookends.GetLength());        
		BIO_free_all(bio);
        bio = NULL;
    }
	
	OTLog::vError("OTAsymmetricKey::LoadPrivateKeyFromCertString: STRANGE error while loading private key: %s\n",
                  strWithBookends.Get());
	return false;
}



// Load the private key from a .pem file
bool OTAsymmetricKey::LoadPrivateKey(const OTString & strFoldername, const OTString & strFilename)
{    
	Release();

	m_bIsPublicKey	= false;
	m_bIsPrivateKey	= true;
	
	const char * szFoldername = strFoldername.Get();
	const char * szFilename = strFilename.Get();
	
	OT_ASSERT(strFoldername.Exists());
	OT_ASSERT(strFilename.Exists());
	// --------------------------------------------------------------------
	
	if (false == OTDB::Exists(szFoldername, szFilename))
	{
		OTLog::vOutput(0, "OTAsymmetricKey::LoadPrivateKey: Unable to find private key file: %s%s%s\n", 
					   szFoldername, OTLog::PathSeparator(), szFilename);
		return false;
	}
	
	// --------------------------------------------------------------------
	//
    // TODO: security. Verify whether this is safe, to load the private key up into a std::string.
    // Find a more secure version of std::string or add an OTDB method for loading into OTPassword instead.
    // Call it "OTDB::SecureQueryPlainString()" or something.
    //
    // Update: the private key is already stored in an encrypted form, which is how it stays until the
    // password callback is passed into some OpenSSL call that attempts to use it.
    //
	std::string strFileContents(OTDB::QueryPlainString(szFoldername, szFilename)); // <=== LOADING "AS-IS" FROM DATA STORE.
	
	if (strFileContents.length() < 2)
	{
		OTLog::vError("OTAsymmetricKey::LoadPrivateKey: Error reading file: %s%s%s\n", 
					  szFoldername, OTLog::PathSeparator(), szFilename);
		return false;
	}
	// --------------------------------------------------------------------
	
    const OTString strCert(strFileContents);
    
    return this->LoadPrivateKeyFromCertString(strCert, false); // bEscaped=false; "escaped" means pre-pended with "- " as in:   - -----BEGIN CER....
}



// Load the public key from a x509 stored in a bookended string
// If the string is escaped (- ----BEGIN is prefixed with dash space: "- ") then make
// sure to pass true.  (Keys that appear inside contracts are escaped after signing.)
// This function will remove the escapes.
//
bool OTAsymmetricKey::LoadPublicKeyFromCertString(const OTString & strCert, bool bEscaped/*=true*/)
{
	Release();
    // ------------------------------
	m_bIsPublicKey	= true;
	m_bIsPrivateKey	= false;
	
	bool bReturnValue = false;
	
    // ------------------------------
	// Read public key
	OTLog::Output(3,  "\nReading public key from x509 stored in bookended string...\n"); 

	OTString	strWithBookends;
	
	if (bEscaped)
	{
		OTASCIIArmor	theArmor;

		// I only have a CERTIFICATE 'if' here, not a PUBLIC KEY 'if'.
		// That's because this function is called "LoadPublicKeyFrom*CERT*String"
		// If you want to load a public key from a public key string, then call the
		// other function that does that.
        //
		if (theArmor.LoadFromString(const_cast<OTString &>(strCert), true, // passing bEscaped in as true explicitly here.
                                    "-----BEGIN CERTIFICATE")) // Overrides "-----BEGIN" 
			strWithBookends.Format("-----BEGIN CERTIFICATE-----\n%s-----END CERTIFICATE-----\n", 
								   theArmor.Get());
		else 
		{
			OTLog::Error("Error extracting ASCII-Armored text from Cert String in "
					"OTAsymmetricKey::LoadPublicKeyFromCertString\n");
			return false;
		}
	}
	else // It's not escaped already, so no need to remove the escaping, in this case.
    {
		strWithBookends = strCert;
	}
    // -------------------------------------------------
	
	// took out the +1 on the length since null terminater only
	// needed in string form, not binary form as OpenSSL treats it.
    //
	BIO  * keyBio = BIO_new_mem_buf(static_cast<void*>(const_cast<char*>(strWithBookends.Get())), strWithBookends.GetLength() /*+1*/); 
//	BIO  * keyBio = BIO_new_mem_buf((void*)strCert.Get(), strCert.GetLength() /*+1*/);
	OT_ASSERT(NULL != keyBio);
	// --------------------------------------------------
    
    OTPasswordData thePWData("OTAsymmetricKey::LoadPublicKeyFromCertString is calling PEM_read_bio_X509...");
    
	X509 * x509 = PEM_read_bio_X509(keyBio, NULL, OTAsymmetricKey::GetPasswordCallback(), &thePWData);
		
	// TODO: At some point need to switch to using X509_AUX functions.
	// The current x509 functions will read a trust certificate but discard the trust structure.
	// The X509_AUX functions will process the trust structure.
    // UPDATE: Possibly the trust structure sucks. Need to consult experts. (CA system is a farce.)
    //
	if (NULL != x509)
	{
        EVP_PKEY * pkey = X509_get_pubkey(x509);
        // ------------------------
		if (pkey == NULL)
		{
			OTLog::Error("Error reading public key from x509 in LoadPublicKeyFromCertArmor.\n");
		}
		else
		{
            this->SetKeyAsCopyOf(*pkey, false); // bIsPrivateKey=false. PUBLIC KEY.
            EVP_PKEY_free(pkey);
            pkey = NULL;
			OTLog::Output(3, "\nSuccessfully extracted a public key from an x509 certificate.\n"); 
			bReturnValue = true; 
		}
	}
	else
	{ 
		OTLog::Error("Error reading x509 out of certificate in LoadPublicKeyFromCertArmor.\n"); 
	}
	
    // ---------------------------------------------------------
    
    // For now we save the x509, and free it in the destructor, since we may
    // need it in the meantime, to convert the Nym to the new master key and
    // re-save. (Don't want to have to load the x509 AGAIN just to re-save it...)
    //
    if (bReturnValue)
    {
        SetX509(x509);
    }
    else
    {
        if (NULL != x509) 
            X509_free(x509);
        x509 = NULL;
        SetX509(NULL);
    }
    
    // Free the BIO and related buffers, filters, etc.
    //
//    if (strWithBookends.GetLength() > 0)
//        OPENSSL_cleanse(keyBio, strWithBookends.GetLength());
	BIO_free_all(keyBio);
	keyBio = NULL;
	// --------------------------------------------------

	return bReturnValue;
}


// low level
void OTAsymmetricKey::SetX509(X509 * x509)
{
    if (m_pX509 == x509)
        return;
    
    if (NULL != m_pX509)
        X509_free(m_pX509);

    m_pX509 = x509;
}






// Load the public key from a .pem file
bool OTAsymmetricKey::LoadPublicKey(const OTString & strFoldername, const OTString & strFilename)
{
	// Already done in SetPublicKey()
//	m_bIsPublicKey	= true;
//	m_bIsPrivateKey	= false;

	Release();
	
	// This doesn't use assert on the arguments, but theArmor.LoadFromFile DOES.
	// -----------------------
	
	OTASCIIArmor theArmor;
	
	if (theArmor.LoadFromFile(strFoldername, strFilename))
	{
		if (SetPublicKey(theArmor))
		{
			OTLog::Output(4, "Success setting public key from OTASCIIArmor in OTAsymmetricKey::LoadPublicKey.\n"); 
			return true; 			
		}
		else
		{
			OTLog::vError("Unable to convert from OTASCIIArmor to public key in "
					 "OTAsymmetricKey::LoadPublicKey: %s\n",
					 strFilename.Get()); 
			return false; 			
		}
	}
	else 
	{
		OTLog::vError("Unable to read pubkey file in OTAsymmetricKey::LoadPublicKey: %s\n", strFilename.Get()); 
		return false; 
	}

	return false;
}

/*
// Load the public key from a .pem file
bool OTAsymmetricKey::LoadPublicKey(OTString & strFilename)
{
	Release();
	
	FILE * fp; 
	
	// Read public key 
	fp = fopen (strFilename.Get(), "r"); 
	
	if (NULL == fp)
	{ 
		fprintf (stderr, "Error opening public key file in OTAsymmetricKey::LoadPublicKey: %s\n", strFilename.Get()); 
		return false; 
	} 
	
    m_pKey = PEM_read_PUBKEY(fp, &m_pKey, OTAsymmetricKey::GetPasswordCallback(), NULL); 
	
	fclose (fp); 
	
	if (NULL == m_pKey) 
	{ 
		fprintf (stderr, "Error reading public key from file in OTAsymmetricKey::LoadPublicKey: %s\n", strFilename.Get()); 
		return false; 
	}
	
	return true;
}
*/




// Load the public key from a x509 stored in a .pem file
//
bool OTAsymmetricKey::LoadPublicKeyFromCertFile(const OTString & strFoldername, const OTString & strFilename)
{
	Release();
	
	m_bIsPublicKey	= true;
	m_bIsPrivateKey	= false;
	// ---------------
	const char * szFoldername = strFoldername.Get();
	const char * szFilename = strFilename.Get();
	
	OT_ASSERT(strFoldername.Exists());
	OT_ASSERT(strFilename.Exists());

	// --------------------------------------------------------------------
	
	if (false == OTDB::Exists(szFoldername, szFilename))
	{
		OTLog::vError("OTAsymmetricKey::LoadPublicKeyFromCertFile: File does not exist: %s%s%s\n", 
					  szFoldername, OTLog::PathSeparator(), szFilename);
		return false;
	}
	
	// --------------------------------------------------------------------
	//
	std::string strFileContents(OTDB::QueryPlainString(szFoldername, szFilename)); // <=== LOADING FROM DATA STORE.
	
	if (strFileContents.length() < 2)
	{
		OTLog::vError("OTAsymmetricKey::LoadPublicKeyFromCertFile: Error reading file: %s%s%s\n", 
					  szFoldername, OTLog::PathSeparator(), szFilename);
		return false;
	}
	// --------------------------------------------------------------------
		
    const OTString strCert(strFileContents);
    
    return this->LoadPublicKeyFromCertString(strCert, false); // bEscaped=false; "escaped" means pre-pended with "- " as in:   - -----BEGIN CER....
}


/*    
	// Create a new memory buffer on the OpenSSL side
	BIO * bio = BIO_new_mem_buf((void*)strFileContents.c_str(), strFileContents.length()); 

//	BIO *bio = BIO_new(BIO_s_mem());
	OT_ASSERT(NULL != bio);
	
//	int nPutsResult = BIO_puts(bio, strFileContents.c_str());
	
	// --------------------------------------------------------------------
	
//	if (nPutsResult > 0)
	{
		x509 = PEM_read_bio_X509(bio, NULL, OTAsymmetricKey::GetPasswordCallback(), NULL); 
		
		BIO_free_all(bio);
		bio = NULL;
		// -------------------------------------------------
		
		if (x509 == NULL) 
		{ 
			OTLog::vError("Error reading x509 out of cert file: %s%s%s\n", 
						  szFoldername, OTLog::PathSeparator(), szFilename);
			return false; 
		}
		
		m_pKey = X509_get_pubkey(x509); 
        
        
        
		X509_free(x509);  
		x509 = NULL;
		
		if (m_pKey == NULL) 
		{ 
			OTLog::vError("Error reading public key from x509 from certfile: %s%s%s\n", 
						  szFoldername, OTLog::PathSeparator(), szFilename); 
			return false; 
		}
		else
		{
			OTLog::vOutput(3, "Successfully loaded public key from x509 from certfile: %s%s%s\n", 
						   szFoldername, OTLog::PathSeparator(), szFilename);
			return true; 
		}
	}
	
	if (NULL != bio)
		BIO_free_all(bio);

	return false;
}
*/































