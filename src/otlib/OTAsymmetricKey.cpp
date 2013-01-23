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


// -------------------------------------------------------------------------------------------


extern "C"
{
#include <memory.h>
}

// -------------------------------------------------------------------------------------------

#include <cstdio>
#include <cstring>
#include <cmath>

// -------------------------------------------------------------------------------------------

#include <string>
#include <iostream>

// -------------------------------------------------------------------------------------------

extern "C" 
{
#ifdef _WIN32
//#include "Windows.h"
#include <conio.h>
#else
#include <pwd.h>
#include <unistd.h>
#endif

#include "stacktrace.h"
#include <stdint.h>	

}

// -------------------------------------------------------------------------------------------

#include "OTStorage.h"

#include "OTData.h"
#include "OTPayload.h"
#include "OTString.h"
#include "OTIdentifier.h"
#include "OTSignature.h"
#include "OTAsymmetricKey.h"
#include "OTCredential.h"
#include "OTCachedKey.h"
#include "OTEnvelope.h"
#include "OTPayload.h"
#include "OTASCIIArmor.h"

#include "OTLog.h"

// -------------------------------------------------------------------------------------------

//static
OTAsymmetricKey * OTAsymmetricKey::KeyFactory() // Caller IS responsible to delete!
{
    OTAsymmetricKey * pKey = NULL;
#if defined (OT_CRYPTO_USING_OPENSSL)
    pKey = new OTAsymmetricKey_OpenSSL;    
#elif defined (OT_CRYPTO_USING_GPG)
//  pKey = new OTAsymmetricKey_GPG;
    OTLog::vError("%s: Open-Transactions doesn't support GPG (yet), "
                  "so it's impossible to instantiate a key.\n", __FUNCTION__);
#else
    OTLog::vError("%s: Open-Transactions isn't built with any crypto engine, "
                  "so it's impossible to instantiate a key.\n", __FUNCTION__);
#endif
    return pKey;
}


// -------------------------------------------------------------------------------------------

//virtual
OTAsymmetricKey * OTAsymmetricKey::ClonePubKey() const // Caller IS responsible to delete!
{
    OTAsymmetricKey * pKey = OTAsymmetricKey::KeyFactory();
    OT_ASSERT(NULL != pKey);
    OT_ASSERT(NULL != this->m_pMetadata);
    OT_ASSERT(NULL != pKey->m_pMetadata);
    
    OTASCIIArmor ascTransfer;
    this->GetPublicKey(ascTransfer);     // Get this's public key in ASCII-armored format
    pKey->SetPublicKey(ascTransfer);     // Decodes that public key from ASCII armor into pKey
    
    *(pKey->m_pMetadata) = *(this->m_pMetadata); // Metadata will be attached to signatures, if set.
    
    return pKey;
}


OTLowLevelKeyData::~OTLowLevelKeyData()
{
    if (m_bCleanup)
        Cleanup();
}


// -------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------
// OTAsymmetricKey_OpenSSL

#if defined (OT_CRYPTO_USING_OPENSSL)


OTLowLevelKeyData::OTLowLevelKeyData() : m_bCleanup(true), m_pX509(NULL), m_pKey(NULL)
{

}

// Don't force things by explicitly calling this function, unless you are SURE
// there's no one else cleaning up the same objects. Notice the if (m_bCleanup)
// just above in the destructor, for that very reason.
//
void OTLowLevelKeyData::Cleanup()
{
    if (NULL != m_pKey)
        EVP_PKEY_free(m_pKey);
    if (NULL != m_pX509)
        X509_free(m_pX509);
    
    m_pKey  = NULL;
    m_pX509 = NULL;
}


bool OTLowLevelKeyData::MakeNewKeypair(int nBits/*=1024*/)
{
    const char * szFunc = "OTLowLevelKeyData::MakeNewKeypair";
    // ---------------------------------------
//	BIO			*	bio_err	=	NULL;
	X509		*	x509	=	NULL;
	EVP_PKEY	*	pNewKey	=	NULL;
	
//	CRYPTO_mem_ctrl(CRYPTO_MEM_CHECK_ON); // memory leak detection. Leaving this for now.
//	bio_err	=	BIO_new_fp(stderr, BIO_NOCLOSE);
	
	// actually generate the things. // TODO THESE PARAMETERS...(mkcert)
	mkcert(&x509, &pNewKey, nBits, 0, 3650); // 3650=10 years. Todo hardcoded.
	// Note: 512 bit key CRASHES
	// 1024 is apparently a minimum requirement, if not an only requirement.
	// Will need to go over just what sorts of keys are involved here... todo.
	// ------------------------------------------------------------
	if (NULL == x509)
	{
		OTLog::vError("%s: Failed attempting to generate new x509 cert.\n", szFunc);
        
		if (NULL != pNewKey)
			EVP_PKEY_free(pNewKey);
        
		return false;
	}
	// ---------------------------------------------------------------
	if (NULL == pNewKey)
	{
		OTLog::vError("%s: Failed attempting to generate new private key.\n", szFunc);
		
		if (NULL != x509)
			X509_free(x509);

		return false;
	}
	// ---------------------------------------------------------------
	// Below this point, x509 and pNewKey will need to be cleaned up properly.
    
    if (m_bCleanup)
        Cleanup();

    m_bCleanup = true;
    m_pKey     = pNewKey;
    m_pX509    = x509;
    
	// --------COMMENT THIS OUT FOR PRODUCTION --------  TODO security
	//                  (Debug only.)
//	RSA_print_fp(stdout, pNewKey->pkey.rsa, 0); // human readable
//	X509_print_fp(stdout, x509); // human readable
	
	// --------COMMENT THIS OUT FOR PRODUCTION --------  TODO security
	//                  (Debug only.)
	// write the private key, then the x509, to stdout.

//    OTPasswordData thePWData2("OTPseudonym::GenerateNym is calling PEM_write_PrivateKey...");
//
//	PEM_write_PrivateKey(stdout, pNewKey, EVP_des_ede3_cbc(), NULL, 0, OTAsymmetricKey::GetPasswordCallback(), &thePWData2);
//	PEM_write_X509(stdout, x509);
    // ---------------------------------------------------------------    
	return true;
}
// ----------------------------------------------



bool OTLowLevelKeyData::SetOntoKeypair(OTKeypair & theKeypair)
{
    OT_ASSERT(NULL != m_pKey);
    OT_ASSERT(NULL != m_pX509);
    // ----------------------------------------------
    OT_ASSERT(NULL != theKeypair.m_pkeyPublic);
    OT_ASSERT(NULL != theKeypair.m_pkeyPrivate);
    // ----------------------------------------------
    // Since we are in OpenSSL-specific code, we have to make sure these are
    // OpenSSL-specific keys.
    //
    OTAsymmetricKey_OpenSSL * pPublicKey  = dynamic_cast<OTAsymmetricKey_OpenSSL *> (theKeypair.m_pkeyPublic);
    OTAsymmetricKey_OpenSSL * pPrivateKey = dynamic_cast<OTAsymmetricKey_OpenSSL *> (theKeypair.m_pkeyPrivate);
    
    if (NULL == pPublicKey)
    {
        OTLog::vError("%s: dynamic_cast to OTAsymmetricKey_OpenSSL failed. (theKeypair.m_pkeyPublic)\n", __FUNCTION__);
        return false;
    }
    if (NULL == pPrivateKey)
    {
        OTLog::vError("%s: dynamic_cast to OTAsymmetricKey_OpenSSL failed. (theKeypair.m_pkeyPrivate)\n", __FUNCTION__);
        return false;
    }
    // ----------------------------------------------
    // Now we can call OpenSSL-specific methods on these keys...
    //
    pPublicKey-> SetX509(m_pX509); // m_pX509 is now owned by pPublicKey. (No need to free it in our own destructor anymore.)
    m_pX509 = NULL; // pPublicKey took ownership, so we don't want to ALSO clean it up, since pPublicKey already will do so.

    pPrivateKey->SetKeyAsCopyOf(*m_pKey, true); // bool bIsPrivateKey=true; (Default is false)
    // Since pPrivateKey only takes a COPY of m_pKey, we are still responsible to clean up m_pKey in our own destructor.
    // (Assuming m_bCleanup is set to true, which is the default.) That's why I'm NOT setting it to NULL, as I did above
    // with m_pX509.

    // Success! At this point, theKeypair's public and private keys have been set.
    // Keep in mind though, they still won't be "quite right" until saved and loaded
    // again, at least according to existing logic. That saving/reloading is currently
    // performed in OTPseudonym::GenerateNym().
    //
    return true;
}


// ----------------------------------------------

OTAsymmetricKey_OpenSSL::OTAsymmetricKey_OpenSSL() : OTAsymmetricKey(), m_pX509(NULL), m_pKey(NULL)
{

}


OTAsymmetricKey_OpenSSL::~OTAsymmetricKey_OpenSSL()
{
    Release_AsymmetricKey_OpenSSL();
    // -------------------------
    if (NULL != m_pX509)  // Todo: figure out if I should put a copy of this into ReleaseKeyLowLevel_Hook as we are with m_pKey.
        X509_free(m_pX509); // FYI: the reason it's not there already is because the original need was for wiping m_pKey when a private key timed out.
    m_pX509 = NULL;         // ReleaseKeyLowLevel is used all over OTAsymmetricKey.cpp for the purpose of wiping that private key. The same need didn't exist with the x509 so it was never coded that way. As long as it's cleaned up here in the destructor, seems good enough?
    // -------------------------
    // Release the instantiated OpenSSL key (unsafe to store in this form.)
    //
    if (NULL != m_pKey)
        EVP_PKEY_free (m_pKey);
    m_pKey = NULL;
    //-------------------------
    // YOU MIGHT ASK... Why is m_pKey cleaned up here in the destructor, and ALSO in ReleaseKeyLowLevel_Hook ?
    // The answer is because if we call ReleaseKeyLowLevel_Hook from OTAsymmetricKey's destructor (down that chain)
    // then it will fail at runtime, since it is a pure virtual method. Since we still want the ABILITY to use ReleaseKeyLowLevel_Hook
    // (For cases where the destructor is not being used) and since we still want it to ALSO work when destructing, the
    // easiest/quickest/simplest way is to put the code into OTAsymmetricKey_OpenSSL's destructor directly, as well
    // as OTAsymmetricKey_OpenSSL's override of ReleaseKeyLowLevel_Hook. Then go into OTAsymmetricKey's destructor and
    // make sure the full call path through there doesn't involve any virtual functions.
}

//virtual
void OTAsymmetricKey_OpenSSL::Release()
{
    Release_AsymmetricKey_OpenSSL(); // My own cleanup is performed here.
    
    // Next give the base class a chance to do the same...
	ot_super::Release(); // since I've overridden the base class, I call it now...
}


void OTAsymmetricKey_OpenSSL::Release_AsymmetricKey_OpenSSL()
{
    // Release any dynamically allocated members here. (Normally.)
}


void OTAsymmetricKey_OpenSSL::ReleaseKeyLowLevel_Hook()
{
    // Release the instantiated OpenSSL key (unsafe to store in this form.)
    //
    if (NULL != m_pKey)
        EVP_PKEY_free (m_pKey);
    m_pKey = NULL;
}


// -------------------------------------------------------------------------------------------



// low level
void OTAsymmetricKey_OpenSSL::SetX509(X509 * x509)
{
    if (m_pX509 == x509)
        return;
    
    if (NULL != m_pX509)
        X509_free(m_pX509);
    
    m_pX509 = x509;
}


// -------------------------------------------------------------------------------------------


void OTAsymmetricKey_OpenSSL::SetKeyAsCopyOf(EVP_PKEY & theKey, bool bIsPrivateKey/*=false*/)
{ 
	Release(); 
    // ---------------------------
    //typedef
    //int OT_OPENSSL_CALLBACK (char *buf, int size, int rwflag, void *userdata);
    /*
    EVP_PKEY *  CopyPublicKey (EVP_PKEY & theKey);
    EVP_PKEY *  CopyPrivateKey(EVP_PKEY & theKey);
    */
    m_pKey			= bIsPrivateKey ? OTAsymmetricKey_OpenSSL::CopyPrivateKey(theKey) 
                                    : OTAsymmetricKey_OpenSSL::CopyPublicKey (theKey);
	OT_ASSERT_MSG(NULL != m_pKey, "OTAsymmetricKey_OpenSSL::SetKeyAsCopyOf: ASSERT: NULL != m_pKey \n");
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
            OTAsymmetricKey_OpenSSL::ArmorPrivateKey(*m_pKey, *m_p_ascKey, m_timer);
    // NOTE: Timer is already set INSIDE ArmorPrivateKey. No need to set twice.
//      m_timer.start(); // Note: this isn't the ultimate timer solution. See notes in ReleaseKeyLowLevel.
    else if (m_bIsPublicKey)
//        const bool bArmored = 
            OTAsymmetricKey_OpenSSL::ArmorPublicKey(*m_pKey, *m_p_ascKey);
    else
        OTLog::Error("OTAsymmetricKey_OpenSSL::SetKeyAsCopyOf: Error: This key is NEITHER public NOR private!\n");
}
// ------------------------------------------------------


// static bool ArmorPrivateKey(EVP_PKEY & theKey, OTASCIIArmor & ascKey);
// static bool ArmorPublicKey (EVP_PKEY & theKey, OTASCIIArmor & ascKey);


EVP_PKEY * OTAsymmetricKey_OpenSSL::GetKeyLowLevel()
{
    return m_pKey;
}

// -------------------------------------------------------------------------------------------


const EVP_PKEY * OTAsymmetricKey_OpenSSL::GetKey(OTPasswordData * pPWData/*=NULL*/)
{
    OT_ASSERT_MSG(NULL != m_p_ascKey, "OTAsymmetricKey_OpenSSL::GetKey: NULL != m_p_ascKey\n");
    
    if (NULL == m_p_ascKey)
    {
        OTLog::vError("%s: Unexpected NULL m_p_ascKey. Printing stack trace (and returning NULL):\n", __FUNCTION__);
        print_stacktrace();
        return NULL;
    }
    // ----------------------------------------
    
    if (m_timer.getElapsedTimeInSec() > OT_KEY_TIMER)
        ReleaseKeyLowLevel();   // This releases the actual loaded key, but not the ascii-armored, encrypted version of it.
                                // (Thus forcing a reload, and thus forcing the passphrase to be entered again.)
    // ----------------------------------------
    if (NULL == m_pKey)
        return InstantiateKey(pPWData);  // this is the ONLY place, currently, that this private method is called.
    
	return m_pKey;
}



// -------------------------------------------------------------------------------------------

// Low-level / private
EVP_PKEY * OTAsymmetricKey_OpenSSL::InstantiateKey(OTPasswordData * pPWData/*=NULL*/)
{
    if (IsPublic())
        return InstantiatePublicKey(pPWData);  // this is the ONLY place, currently, that this private method is called.
    
    else if (IsPrivate())
        return InstantiatePrivateKey(pPWData); // this is the ONLY place, currently, that this private method is called.
    
    else
        OTLog::Error("OTAsymmetricKey_OpenSSL::InstantiateKey: Error: Key is neither public nor private!\n");
    
    return NULL;
}


// -------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------
// Load the private key from a .pem formatted cert string
//
bool OTAsymmetricKey_OpenSSL::LoadPrivateKeyFromCertString(const OTString & strCert, // Contains certificate and private key.
                                                           bool bEscaped/*=true*/, // "escaped" means pre-pended with "- " as in:   - -----BEGIN CER....
                                                           const OTString * pstrReason/*=NULL*/) // This reason is what displays on the passphrase dialog.
{   
    const char * szFunc = "OTAsymmetricKey_OpenSSL::LoadPrivateKeyFromCertString";
    
	Release();
	
	m_bIsPublicKey	= false;
	m_bIsPrivateKey	= true;
	// --------------------------------------------------------------------
	//
	if (!strCert.Exists())
	{
		OTLog::vError("%s: Error: Cert input is nonexistent!\n", szFunc);
		return false;
	}
	// --------------------------------------------------------------------
	
    // Read private key
    //
	OTString strWithBookends;
	OTLog::vOutput(3,  "%s: FYI, Reading private key from x509 stored in bookended string...\n", szFunc); 

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
			OTLog::vError("%s: Error extracting ASCII-Armored text from Cert String.\n", szFunc);
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
//  BIO * bio = BIO_new_mem_buf(static_cast<void*>(const_cast<char*>(strWithBookends.Get())), strWithBookends.GetLength() /*+1*/); 
    BIO * bio = BIO_new_mem_buf(static_cast<void*>(const_cast<char*>(strWithBookends.Get())), -1); 
	OT_ASSERT_MSG(NULL != bio, "OTAsymmetricKey_OpenSSL::LoadPrivateKeyFromCertString: Assert: NULL != bio \n");	

	// --------------------------------------------------------------------
	{
		// TODO security: Need to replace PEM_read_bio_PrivateKey().
		/* The old PrivateKey write routines are retained for compatibility. 
		 New applications should write private keys using the PEM_write_bio_PKCS8PrivateKey() or PEM_write_PKCS8PrivateKey() 
		 routines because they are more secure (they use an iteration count of 2048 whereas the traditional routines use a
		 count of 1) unless compatibility with older versions of OpenSSL is important.
		 NOTE: The PrivateKey read routines can be used in all applications because they handle all formats transparently.
		 */
        OTPasswordData thePWData((NULL == pstrReason) ? 
                                 "Enter the master passphrase. (LoadPrivateKeyFromCertString)" : 
                                 pstrReason->Get());

        EVP_PKEY * pkey = PEM_read_bio_PrivateKey( bio, NULL, OTAsymmetricKey::GetPasswordCallback(), &thePWData );
                
//        if (strWithBookends.GetLength() > 0)
//            OPENSSL_cleanse(bio, strWithBookends.GetLength());        
		BIO_free_all(bio);
		bio = NULL;
		// ------------------------------------------------------
		
		if (NULL == pkey) 
		{ 
			OTLog::vError("%s: Error reading private key from string:\n\n%s\n\n",
						  szFunc, strWithBookends.Get());
			return false; 
		}
		else 
		{
            // Note: no need to start m_timer here since SetKeyAsCopyOf already calls ArmorPrivateKey, which does that.
            //
            this->SetKeyAsCopyOf(*pkey, true); // bIsPrivateKey=false by default, but true here.
            EVP_PKEY_free(pkey);
            pkey = NULL;
			OTLog::vOutput(3, "%s: Successfully loaded private key, FYI.\n", szFunc);
			return true;
		}
	}
	// -------------------
    
	if (NULL != bio)
    {
//      if (strWithBookends.GetLength() > 0)
//          OPENSSL_cleanse(bio, strWithBookends.GetLength());        
		BIO_free_all(bio);
        bio = NULL;
    }
	
	OTLog::vError("%s: STRANGE error while loading private key: %s\n",
                  szFunc, strWithBookends.Get());
	return false;
}



// -------------------------------------------------------------------------------------------
// Load the public key from a x509 stored in a bookended string
// If the string is escaped (- ----BEGIN is prefixed with dash space: "- ") then make
// sure to pass true.  (Keys that appear inside contracts are escaped after signing.)
// This function will remove the escapes.
//
bool OTAsymmetricKey_OpenSSL::LoadPublicKeyFromCertString(const OTString & strCert, bool bEscaped/*=true*/)
{
    const char * szFunc = "OTAsymmetricKey_OpenSSL::LoadPublicKeyFromCertString";
	Release();
    // ------------------------------
	m_bIsPublicKey	= true;
	m_bIsPrivateKey	= false;
	
	bool bReturnValue = false;
    // ------------------------------
	// Read public key
	OTLog::vOutput(3,  "%s: Reading public key from x509 stored in bookended string...\n", szFunc); 

	OTString   strWithBookends;
	
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
			OTLog::vError("%s: Error extracting ASCII-Armored text from Cert String.\n", szFunc);
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
	BIO  * keyBio = BIO_new_mem_buf(static_cast<void*>(const_cast<char*>(strWithBookends.Get())), -1); 
//	BIO  * keyBio = BIO_new_mem_buf(static_cast<void*>(const_cast<char*>(strWithBookends.Get())), strWithBookends.GetLength() /*+1*/); 
//	BIO  * keyBio = BIO_new_mem_buf((void*)strCert.Get(), strCert.GetLength() /*+1*/);
	OT_ASSERT(NULL != keyBio);
	// --------------------------------------------------
    
    OTPasswordData thePWData("OTAsymmetricKey_OpenSSL::LoadPublicKeyFromCertString is calling PEM_read_bio_X509...");
    
	X509 * x509 = PEM_read_bio_X509(keyBio, NULL, OTAsymmetricKey::GetPasswordCallback(), &thePWData);
		
	// TODO security: At some point need to switch to using X509_AUX functions.
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
			OTLog::vError("%s: Error reading public key from x509.\n", szFunc);
		}
		else
		{
            this->SetKeyAsCopyOf(*pkey, false); // bIsPrivateKey=false. PUBLIC KEY.
            EVP_PKEY_free(pkey);
            pkey = NULL;
			OTLog::vOutput(3, "%s: Successfully extracted a public key from an x509 certificate.\n", szFunc); 
			bReturnValue = true; 
		}
	}
	else
	{ 
		OTLog::vError("%s: Error reading x509 out of certificate.\n", szFunc); 
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
//  if (strWithBookends.GetLength() > 0)
//      OPENSSL_cleanse(keyBio, strWithBookends.GetLength());
	BIO_free_all(keyBio);
	keyBio = NULL;
	// --------------------------------------------------

	return bReturnValue;
}



// -------------------------------------------------------------------------------------------


//static      // CALLER must EVP_pkey_free!
EVP_PKEY * OTAsymmetricKey_OpenSSL::CopyPublicKey(EVP_PKEY & theKey)
{
    const char * szFunc = "OTAsymmetricKey_OpenSSL::CopyPublicKey";
    // ----------------------------------------
	// Create a new memory buffer on the OpenSSL side
	BIO *bmem = BIO_new(BIO_s_mem());    
	OT_ASSERT_MSG(NULL != bmem, "OTAsymmetricKey_OpenSSL::CopyPublicKey: ASSERT: NULL != bmem");
    
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
		const long      lSize = BIO_get_mem_data(bmem, &pChar);
        const uint32_t  nSize = static_cast<uint32_t>(lSize);
        
        if (nSize > 0)
        {
            OTPayload theData;

            // Set the buffer size in our own memory.
            theData.SetPayloadSize(nSize);
            
            void * pv = 
               OTPassword::safe_memcpy((static_cast<char*>(const_cast<void*>(theData.GetPayloadPointer()))), // destination
                                    theData.GetSize(),    // size of destination buffer.
                                    pChar,                // source
                                    nSize);               // length of source.
            // bool bZeroSource=false); // if true, sets the source buffer to zero after copying is done.

            if (NULL != pv)
            {
                // -----------------------------------------------
                // Next, copy theData's contents into a new BIO_mem_buf,
                // so OpenSSL can load the key out of it.
                //
                BIO* keyBio	= BIO_new_mem_buf(static_cast<char*>(const_cast<void*>(theData.GetPayloadPointer())), 
                                              theData.GetSize());
                OT_ASSERT_MSG(NULL != keyBio, "OTAsymmetricKey_OpenSSL::CopyPublicKey: Assert: NULL != keyBio \n");
                // -------------------------------------------
                // Next we load up the key from the BIO string into an instantiated key object.
                //
                OTPasswordData thePWData("OTAsymmetricKey_OpenSSL::CopyPublicKey is calling PEM_read_bio_PUBKEY...");
                
                pReturnKey = PEM_read_bio_PUBKEY(keyBio, NULL, OTAsymmetricKey::GetPasswordCallback(), &thePWData);
                // -------------------------------------------
                // We don't need the BIO anymore.
                // Free the BIO and related buffers, filters, etc.
                //
//              if (theData.GetSize() > 0)
//                  OPENSSL_cleanse(keyBio, theData.GetSize());
                BIO_free_all(keyBio);
                keyBio = NULL;
            }
            else 
                OTLog::vError("%s: Error: Failed copying memory from BIO into OTPayload.\n");
            // -------------------------------------------            
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



// -------------------------------------------------------------------------------------------

// NOTE: OpenSSL will store the EVP_PKEY inside the X509, and when I get it, 
// I'm not supposed to destroy the x509 until I destroy the EVP_PKEY FIRST!
// (AND it reference-counts.)
// Since I want ability to destroy the two, independent of each other, I made
// static functions here for copying public and private keys, so I am ALWAYS 
// working with MY OWN copy of any given key, and not OpenSSL's reference-counted
// one.
//
// Furthermore, BIO_mem_buf doesn't allocate its own memory, but uses the memory
// you pass to it. You CANNOT free that memory until you destroy the BIO.
//
// That's why you see me copying one bio into a payload, before copying it into
// the next bio. Todo security: copy it into an OTPassword here, instead of an
// OTPayload, which is safer, and more appropriate for a private key. Make sure
// OTPassword can accommodate a bit larger size than what it does now.
//
//static      // CALLER must EVP_pkey_free!
EVP_PKEY * OTAsymmetricKey_OpenSSL::CopyPrivateKey(EVP_PKEY & theKey)
{
    const char * szFunc = "OTAsymmetricKey_OpenSSL::CopyPrivateKey";    
    // ----------------------------------------
	// Create a new memory buffer on the OpenSSL side
	BIO *bmem = BIO_new(BIO_s_mem());    
	OT_ASSERT(NULL != bmem);
    
    EVP_PKEY * pReturnKey = NULL;
	// ----------------------------------------
	// write a private key to that buffer, from theKey
    //
    OTPasswordData thePWData("OTAsymmetricKey_OpenSSL::CopyPrivateKey is calling PEM_write_bio_PrivateKey...");
    
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
        const long      lSize = BIO_get_mem_data(bmem, &pChar);
        const uint32_t  nSize = static_cast<uint32_t>(lSize);
        
        if (nSize > 0)
        {
            OTPayload theData;
            
            // Set the buffer size in our own memory.
            theData.SetPayloadSize(nSize);
            
            void * pv = 
               OTPassword::safe_memcpy((static_cast<char*>(const_cast<void*>(theData.GetPayloadPointer()))), // destination
                                       theData.GetSize(),    // size of destination buffer.
                                       pChar,                // source
                                       nSize);               // length of source.
            // bool bZeroSource=false); // if true, sets the source buffer to zero after copying is done.
            
            if (NULL != pv)
            {
                // -----------------------------------------------
                // Next, copy theData's contents into a new BIO_mem_buf,
                // so OpenSSL can load the key out of it.
                //
                BIO* keyBio	= BIO_new_mem_buf(static_cast<char*>(const_cast<void*>(theData.GetPayloadPointer())), 
                                              theData.GetSize());
                OT_ASSERT_MSG(NULL != keyBio, "OTAsymmetricKey_OpenSSL::CopyPrivateKey: Assert: NULL != keyBio \n");
                // -------------------------------------------
                // Next we load up the key from the BIO string into an instantiated key object.
                //
                OTPasswordData thePWData("OTAsymmetricKey_OpenSSL::CopyPrivateKey is calling PEM_read_bio_PUBKEY...");
                
                pReturnKey = PEM_read_bio_PrivateKey( keyBio, NULL, OTAsymmetricKey::GetPasswordCallback(), &thePWData );
                // -------------------------------------------
                // We don't need the BIO anymore.
                // Free the BIO and related buffers, filters, etc.
                //
//              if (theData.GetSize() > 0)
//                  OPENSSL_cleanse(keyBio, theData.GetSize());
                BIO_free_all(keyBio);
                keyBio = NULL;
            }
            else 
                OTLog::vError("%s: Error: Failed copying memory from BIO into OTPayload.\n");
            // -------------------------------------------            
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
bool OTAsymmetricKey_OpenSSL::ArmorPublicKey(EVP_PKEY & theKey, OTASCIIArmor & ascKey)
{
	bool bReturnVal = false;
    
    const char * szFunc = "OTAsymmetricKey_OpenSSL::ArmorPublicKey";
    
    ascKey.Release();
    // ----------------------------------------
	// Create a new memory buffer on the OpenSSL side
	BIO *bmem = BIO_new(BIO_s_mem());    
	OT_ASSERT_MSG(NULL != bmem, "OTAsymmetricKey_OpenSSL::ArmorPublicKey: ASSERT: NULL != bmem");
    
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
		uint32_t  nSize = static_cast<uint32_t>(lSize); // todo security, etc. Fix this assumed type conversion.
		
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



// -------------------------------------------------------------------------------------------

//
//
// Low-level
//
// (Internal) ASCII-Armored key ====> (Internal) Actual loaded OpenSSL key.
//
//
EVP_PKEY * OTAsymmetricKey_OpenSSL::InstantiatePublicKey(OTPasswordData * pPWData/*=NULL*/)
{
    OT_ASSERT(m_pKey     == NULL);
    OT_ASSERT(m_p_ascKey != NULL);
    OT_ASSERT(IsPublic());
    
    const char * szFunc = "OTAsymmetricKey_OpenSSL::InstantiatePublicKey";
    // ------------------------------
    EVP_PKEY * pReturnKey = NULL;
    OTPayload  theData;
    // -----------------------------------------------
    // This base64 decodes the string m_p_ascKey into the
    // binary payload object "theData"
    //
    m_p_ascKey->GetData(theData);
    
    if (theData.GetSize() > 0)
    {
        // -------------------------------------------
        // Next, copy theData's contents into a new BIO_mem_buf,
        // so OpenSSL can load the key out of it.
        //
        BIO* keyBio	= BIO_new_mem_buf(static_cast<char*>(const_cast<void*>(theData.GetPayloadPointer())), 
                                      theData.GetSize());
        OT_ASSERT_MSG(NULL != keyBio, "OTAsymmetricKey_OpenSSL::InstantiatePublicKey: Assert: NULL != keyBio \n");
        // -------------------------------------------
        // Next we load up the key from the BIO string into an instantiated key object.
        //
        OTPasswordData thePWData("OTAsymmetricKey_OpenSSL::InstantiatePublicKey is calling PEM_read_bio_PUBKEY...");
        
        if (NULL == pPWData)
            pPWData = &thePWData;
        
        pReturnKey = PEM_read_bio_PUBKEY(keyBio, NULL, OTAsymmetricKey::GetPasswordCallback(), pPWData);
        // -------------------------------------------
        // We don't need the BIO anymore.
        // Free the BIO and related buffers, filters, etc.
        //
//      if (theData.GetSize() > 0)
//          OPENSSL_cleanse(keyBio, theData.GetSize());
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
    }
    
    OTLog::vError("%s: Failed reading public key from ASCII-armored data:\n\n%s\n\n", 
                  szFunc, m_p_ascKey->Get());
    return NULL;
}






// -------------------------------------------------------------------------------------------


// Low-level
//
// Note: Be sure to ReleaseKey() when you're done with it.
// Note: the way that should work is, the programmatic user should Get the Key and
// then Release the key immediately before and after using it. But they should be
// HIGH-LEVEL functions, which handle the timer stuff internally.
//
EVP_PKEY * OTAsymmetricKey_OpenSSL::InstantiatePrivateKey(OTPasswordData * pPWData/*=NULL*/)
{
    OT_ASSERT(m_pKey     == NULL);
    OT_ASSERT(m_p_ascKey != NULL);
    OT_ASSERT(IsPrivate());    
    // ------------------------------
    const char * szFunc = "OTAsymmetricKey_OpenSSL::InstantiatePrivateKey";
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
    if (theData.GetSize() > 0)
    {
        BIO * keyBio = BIO_new_mem_buf(static_cast<char*>(const_cast<void*>(theData.GetPayloadPointer())), 
                                       theData.GetSize()); // theData will zeroMemory upon destruction.
        OT_ASSERT_MSG(NULL != keyBio, "OTAsymmetricKey_OpenSSL::InstantiatePrivateKey: Assert: NULL != keyBio \n");
        // --------------------------------------
        // Here's thePWData we use if we didn't have anything else:
        //
        OTPasswordData thePWData("OTAsymmetricKey_OpenSSL::InstantiatePrivateKey is calling PEM_read_bio_PrivateKey...");

        if (NULL == pPWData)
            pPWData = &thePWData;
        
        pReturnKey = PEM_read_bio_PrivateKey( keyBio, NULL, OTAsymmetricKey::GetPasswordCallback(), pPWData );
        
        // Free the BIO and related buffers, filters, etc.
        //
//    if (theData.GetSize() > 0)
//        OPENSSL_cleanse(keyBio, theData.GetSize());
        BIO_free_all(keyBio);
        keyBio = NULL;
        // --------------------------------------
        ReleaseKeyLowLevel();
        // --------------------------------------
        if (NULL != pReturnKey)
        {
            m_pKey = pReturnKey;
            // TODO (remove theTimer entirely. OTCachedKey replaces already.)
            // I set this timer because the above required a password. But now that master key is working,
            // the above would flow through even WITHOUT the user typing his passphrase (since master key still
            // not timed out.) Resulting in THIS timer being reset!  Todo: I already shortened this timer to 30
            // seconds, but need to phase it down to 0 and then remove it entirely! Master key takes over now!
            //

            m_timer.start();  // Note: this isn't the ultimate timer solution. See notes in ReleaseKeyLowLevel.
            OTLog::vOutput(4, "%s: Success reading private key from ASCII-armored data:\n\n%s\n\n",
                           szFunc, m_p_ascKey->Get());
            return m_pKey;
        }
    }
    OTLog::vError("%s: Failed reading private key from ASCII-armored data:\n\n%s\n\n",
                  szFunc, m_p_ascKey->Get());
    return NULL;
}
                                            

// -------------------------------------------------------------------------------------------

//static
bool OTAsymmetricKey_OpenSSL::ArmorPrivateKey(EVP_PKEY & theKey, OTASCIIArmor & ascKey, Timer & theTimer, OTPasswordData * pPWData/*=NULL*/)
{
	bool bReturnVal = false;
    
    const char * szFunc = "OTAsymmetricKey_OpenSSL::ArmorPrivateKey";
    
    ascKey.Release();
    // ----------------------------------------
	// Create a new memory buffer on the OpenSSL side
	BIO *bmem = BIO_new(BIO_s_mem());    
	OT_ASSERT(NULL != bmem);
    
    long lSize = 0;
	// ----------------------------------------
	// write a private key to that buffer, from theKey
    //
    OTPasswordData thePWData("OTAsymmetricKey_OpenSSL::ArmorPrivateKey is calling PEM_write_bio_PrivateKey...");

    if (NULL == pPWData)
        pPWData = &thePWData;
    
    int nWriteBio = PEM_write_bio_PrivateKey(bmem, &theKey, EVP_des_ede3_cbc(), // todo should this algorithm be hardcoded?
                                             NULL, 0, OTAsymmetricKey::GetPasswordCallback(), pPWData);
	
	if (0 == nWriteBio)
	{
		OTLog::vError("%s: Failed writing EVP_PKEY to memory buffer.\n", szFunc);
	}
	else 
	{
        // TODO (remove theTimer entirely. OTCachedKey replaces already.)
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
		uint32_t  nSize = static_cast<uint32_t>(lSize);
		
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

// -------------------------------------------------------------------------------------------
// Used below for cleanup.

    class _Nym__saveCert_
    {
        BIO	**	m_bio_out;
    public:
        _Nym__saveCert_(BIO	** param_bio_out)
        : m_bio_out(param_bio_out)
        {
            OT_ASSERT(NULL != m_bio_out);
            
            *m_bio_out  = BIO_new(BIO_s_mem());
        }
        ~_Nym__saveCert_()
        {            
            if (NULL != *m_bio_out)
                BIO_free(*m_bio_out);
            *m_bio_out = NULL;
            m_bio_out  = NULL;
        }
    };

//virtual
bool OTAsymmetricKey_OpenSSL::SaveCertToString(OTString & strOutput)
{
    const char * szFunc = "OTAsymmetricKey_OpenSSL::SaveCertToString";
    // ---------------------------------------
    X509 * x509 = this->GetX509();
    
    if (NULL == x509)
    {
        OTLog::vError("%s: Error: Unexpected NULL x509. (Returning false.)\n", szFunc);
        return false;
    }
    // ---------------------------------------    
	BIO	* bio_out_x509 = NULL;
    // ---------------------------------------
    _Nym__saveCert_ theInstance(&bio_out_x509);
    // ---------------------------------------
	PEM_write_bio_X509(bio_out_x509, x509);
    // ---------------------------------------
    bool bSuccess = false;
    
	unsigned char buffer_x509[8192] = ""; // todo hardcoded
	
	OTString strx509;
    
	int len = 0;
	
    // todo hardcoded 4080 (see array above.)
    //
	if (0 < (len = BIO_read(bio_out_x509, buffer_x509, 8100))) // returns number of bytes successfully read.
	{
		buffer_x509[len] = '\0';
		strx509.Set((const char*)buffer_x509); // todo cast

		EVP_PKEY  * pPublicKey = X509_get_pubkey(x509); 
		if (NULL != pPublicKey)
        {
			this->SetKeyAsCopyOf(*pPublicKey, false); // bool bIsPrivateKey=false;
            EVP_PKEY_free(pPublicKey);
            pPublicKey = NULL;
        }
		// else?
        
        bSuccess = true;
	}
	// ---------------------------------------
	//
	if (bSuccess)
        strOutput = strx509;
	
	return bSuccess;    
}

// -------------------------------------------------------------------------------------------

//virtual
bool OTAsymmetricKey_OpenSSL::SavePrivateKeyToString(OTString & strOutput, const OTString * pstrReason/*=NULL*/)
{
    const char * szFunc = "OTAsymmetricKey_OpenSSL::SavePrivateKeyToString";
    // ---------------------------------------
    if (!IsPrivate())
    {
		OTLog::vError("%s: Error: !IsPrivate() (This function should only be called on a private key.)\n", szFunc);
		return false;
    }
    // ------------------------------
	EVP_PKEY  * pPrivateKey = this->GetKeyLowLevel();
    if (NULL == pPrivateKey)
    {
        OTLog::vError("%s: Error: Unexpected NULL pPrivateKey. (Returning false.)\n", szFunc);
        return false;
    }
    // ---------------------------------------
    BIO	* bio_out_pri  = NULL;
    // ---------------------------------------
    _Nym__saveCert_ theInstance(&bio_out_pri);
    // ---------------------------------------
    OTPasswordData thePWData((NULL != pstrReason) ? pstrReason->Get() : 
                             "OTAsymmetricKey_OpenSSL::SavePrivateKeyToString is calling PEM_write_bio_PrivateKey...");
    
	PEM_write_bio_PrivateKey(bio_out_pri,
                             pPrivateKey,
                             EVP_des_ede3_cbc(), // todo security (revisit this mode...)
                             NULL, 0, OTAsymmetricKey::GetPasswordCallback(), &thePWData);
    // ---------------------------------------
    bool bSuccess = false;
    
	int           len = 0;
	unsigned char buffer_pri [4096] = ""; // todo hardcoded
	
    // todo hardcoded 4080 (see array above.)
    if (0 < (len = BIO_read(bio_out_pri, buffer_pri, 4080))) // returns number of bytes successfully read.
    {
        buffer_pri[len] = '\0';
        strOutput.Set((const char *)buffer_pri); // so I can write this string to file in a sec... todo cast
        bSuccess = true;
    }
	// ---------------------------------------
	return bSuccess;    
}

// -------------------------------------------------------------------------------------------


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


PgpKeys ExportRsaKey(unsigned char *pbData, int dataLength)
{
	PgpKeys pgpKeys;
	int i;
	
	OT_ASSERT(NULL != pbData);
	
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




// -------------------------------------------------------------------------------------------



// Decodes a PGP public key from ASCII armor into an actual key pointer
// and sets that as the keypointer on this object.
// This function expects the bookends to be GONE already
// It just wants the base64 encoded data which is why we have ascii-armor
// object coming in instead of a string.
bool OTAsymmetricKey_OpenSSL::LoadPublicKeyFromPGPKey(const OTASCIIArmor & strKey)
{	
    Release();
    // ---------------------
    
	m_bIsPublicKey	= true;
	m_bIsPrivateKey	= false;
	
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
//	bio = BIO_new_mem_buf((void*)strKey.Get(), strKey.GetLength());
	bio = BIO_new_mem_buf((void*)strKey.Get(), -1);
	bio_out = BIO_new(BIO_s_mem());
	bio = BIO_push(b64, bio);
	
	while((len = BIO_read(bio, buffer, 512)) > 0)
		BIO_write(bio_out, buffer, len);
	BIO_free_all(bio);
	bio = NULL;
	
	BIO_get_mem_ptr(bio_out, &bptr);
	
	pgpKeys = ExportRsaKey((unsigned char*)bptr->data, static_cast<int> (bptr->length));
	
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



// -------------------------------------------------------------------------------------------

#elif defined (OT_CRYPTO_USING_GPG)



// -------------------------------------------------------------------------------------------
#else




#endif
// -------------------------------------------------------------------------------------------


// static
OT_OPENSSL_CALLBACK * OTAsymmetricKey::s_pwCallback = NULL;

//static void SetPasswordCallback(p_OT_OPENSSL_CALLBACK pCallback);
//static p_OT_OPENSSL_CALLBACK GetPasswordCallback();
//static bool IsPasswordCallbackSet() { (NULL == s_pwCallback) ? false : true; }


// -------------------------------------------------------------------------------------------

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



// -------------------------------------------------------------------------------------------


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
		OTLog::vOutput(5, "%s: FYI, the internal 'C'-based password callback is now being returning to OT, "
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



// -------------------------------------------------------------------------------------------
//static
OTCaller * OTAsymmetricKey::s_pCaller = NULL;


// Takes ownership. UPDATE: doesn't, since he assumes the Java side
// created it and will therefore delete it when the time comes.
// I keep a pointer, but I don't delete the thing. Let Java do it.
//
bool OTAsymmetricKey::SetPasswordCaller(OTCaller & theCaller)
{
    const char * szFunc = "OTAsymmetricKey::SetPasswordCaller";
    
	OTLog::vOutput(3, "%s: Attempting to set the password caller... "
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
    
	OTLog::vOutput(4, "%s: FYI, this was just called by souped_up_pass_cb "
				   "(which must have just been called by OpenSSL.) "
				   "Returning s_pCaller == %s (Hopefully NOT NULL, so the "
                   "custom password dialog can be triggered.)\n", szFunc,
				   (NULL == s_pCaller) ? "NULL" : "VALID POINTER");
	
	return s_pCaller;
}



// -------------------------------------------------------------------------------------------


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
    const uint32_t theSize = uint32_t(size);
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

	len = static_cast<int> (strlen(tmp_passwd));
//	len = str_Password.size();
	
	if (len <= 0)
	{
		OTLog::vOutput(0, "%s: Problem? Returning 0...\n", szFunc);
		return 0;
	}
	
	// if too long, truncate
	if (len > size) 
		len = size;
	
    const uint32_t theLength = static_cast<const uint32_t>(len);
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



// -------------------------------------------------------------------------------------------

#ifndef _PASSWORD_LEN
#define _PASSWORD_LEN   128
#endif

// -------------------------------------------------------------------------------------------

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
//  OT_ASSERT(NULL != buf); // apparently it CAN be NULL sometimes.
    OT_ASSERT(NULL != userdata);
    OTPasswordData * pPWData  = static_cast<OTPasswordData *>(userdata);
    const std::string str_userdata = pPWData->GetDisplayString();    
    // -----------------------------------------------------
    OTPassword  thePassword;
    bool        bGotPassword = false;
    // -------------------------------------
    OTCachedKey * pCachedKey = pPWData->GetCachedKey(); // Sometimes it's passed in, otherwise we use the global one.
    if (NULL == pCachedKey)
    {
        pCachedKey = OTCachedKey::It(); // Used to only use this one (global one) but now I allow pPWData to contain a pointer to the exact instance. (To enable multiple instances...) If that's not found then here we set it to the global one.
    }
    OT_ASSERT(NULL != pCachedKey);
    // -------------------------------------
    const bool b1 = pPWData->isForNormalNym();
    const bool b3 = !(pCachedKey->isPaused());
    
    // For example, perhaps we need to collect a password for a symmetric key.
    // In that case, it has nothing to do with any master key, or any public/private
    // keys. It ONLY wants to do a simple password collect.
    //
    const bool bOldSystem = pPWData->isUsingOldSystem();

//    OTLog::vOutput(5, "--------------------------------------------------------------------------------\n"
//                  "TOP OF SOUPED-UP PASS CB:\n pPWData->isForNormalNym(): %s \n "
////                "!pPWData->isUsingOldSystem(): %s \n "
//                  "!(pCachedKey->isPaused()): %s \n",
//                  b1 ? "NORMAL" : "NOT normal",
////                b2 ? "NOT using old system" : "USING old system",
//                  b3 ? "NOT paused" : "PAUSED"
//                  );
    
    //	
    // It's for one of the normal Nyms.
    // (NOT the master key.)
    // If it was for the master key, we'd just pop up the dialog and get the master passphrase.
    // But since it's for a NORMAL Nym, we have to call OTCachedKey::GetMasterPassword. IT will pop
    // up the dialog if it needs to, by recursively calling this in master mode, and then it'll use
    // the user passphrase from that dialog to derive a key, and use THAT key to unlock the actual
    // "passphrase" (a random value) which is then passed back to OpenSSL to use for the Nyms.
    //
    if ( b1 &&  // Normal Nyms, unlike Master passwords, have to look up the master password first.
         !bOldSystem &&  
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
        
        bGotPassword = pCachedKey->GetMasterPassword(thePassword, str_userdata.c_str());//bool bVerifyTwice=false

        // NOTE: shouldn't the above call to GetMasterPassword be passing the rwflag as the final parameter?
        // Just as we see below with the call to GetPasswordFromConsole. Right? Of course, it DOES generate internally,
        // if necessary, and thus it forces an "ask twice" in that situation anyway. (It's that smart.)
        // Actually that's it. The master already asks twice when it's generating.
        
//      bool   GetMasterPassword(      OTPassword & theOutput,
//                               const char       * szDisplay=NULL,
//                                     bool         bVerifyTwice=false);

        
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
            OTLog::vOutput(0, "Passphrase request for: \"%s\"\n", str_userdata.c_str());

            bGotPassword = OTCrypto::It()->GetPasswordFromConsole(thePassword, (1 == rwflag) ? true : false);
        }
        else // Okay, we have a callback, so let's pop up the dialog!
        {
            // ---------------------------------------
            // The dialog should display this string (so the user knows what he is authorizing.)
            //
            pCaller->SetDisplay(str_userdata.c_str(), static_cast<int> (str_userdata.size()));
            
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
	
	if (len < 0) 
	{
		OTLog::vOutput(0, "%s: <0 length password was "
                       "returned from the API password callback. "
                       "Returning 0.\n", szFunc);
		return 0;        
	}
    // --------------------------------------	
	else if (len == 0) 
	{
        const char * szDefault = "test";
        
		OTLog::vOutput(0, "%s: 0 length password was "
                       "returned from the API password callback. "
                       "Substituting default password 'test'.\n", szFunc); // todo: security: is this safe? Here's what's driving this: We can't return 0 length string, but users wanted to be able to "just hit enter" and use an empty passphrase. So for cases where the user has explicitly "hit enter" we will substitute "test" as their passphrase instead. They still have to do this explicitly--it only happens when they use an empty one. 
		
        if (thePassword.isPassword())
            thePassword.setPassword(szDefault, static_cast<int>(OTString::safe_strlen(szDefault, _PASSWORD_LEN)));
        else
            thePassword.setMemory(static_cast<const void *>(szDefault),
                                  static_cast<uint32_t>(OTString::safe_strlen(szDefault, _PASSWORD_LEN)) + 1); // setMemory doesn't assume the null terminator like setPassword does.
        
        len	= thePassword.isPassword() ? thePassword.getPasswordSize() : thePassword.getMemorySize();
	}
    // -------------------------------------------------------
    OTPassword * pMasterPW = pPWData->GetMasterPW();

    if (pPWData->isForCachedKey() && (NULL != pMasterPW))
    {
        *pMasterPW = thePassword;
    }
    // --------------------------------------	
    else if (NULL != buf)
    {
        // if too long, truncate
        if (len > size) 
            len = size;
        
        const uint32_t theSize   = static_cast<uint32_t>(size);
        const uint32_t theLength = static_cast<uint32_t>(len);
        
        //void * pv = 
        OTPassword::safe_memcpy(buf,                   // destination
                                theSize,               // size of destination buffer.
                                thePassword.isPassword() ? thePassword.getPassword_uint8() : thePassword.getMemory_uint8(), // source
                                theLength); // length of source.
                               //bool bZeroSource=false); // No need to set this true, since OTPassword (source) already zeros its memory automatically.
        
    }
    // --------------------------------------	
    else // should never happen
    {
//      OT_ASSERT_MSG(false, "This should never happen. (souped_up_pass_cb");
    }
	return len;
}
// -------------------------------------------------------------------------------------------







// -------------------------------------------------------------------------------------------

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



// -------------------------------------------------------------------------------------------

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

// -------------------------------------------------------------------------------------------


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


// -------------------------------------------------------------------------------------------


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


// -------------------------------------------------------------------------------------------



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


// -------------------------------------------------------------------------------------------

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


// -------------------------------------------------------------------------------------------


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



// -------------------------------------------------------------------------------------------

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




// -------------------------------------------------------------------------------------------

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
        
        // Even if unused, both should always already be instantiated.
        if ((NULL != this->m_pMetadata) && (NULL != rhs.m_pMetadata))
            *(this->m_pMetadata) = *(rhs.m_pMetadata);
	}
	
	return *this;
}


// -------------------------------------------------------------------------------------------

// Does public key only.
//
OTAsymmetricKey::OTAsymmetricKey(const OTAsymmetricKey & rhs) : 
    m_p_ascKey(NULL),
    m_bIsPublicKey(true),   // PUBLIC KEY
    m_bIsPrivateKey(false),
    m_pMetadata(new OTSignatureMetadata)
{
	if ((&rhs != this) && (false == rhs.IsPrivate()) && (rhs.IsPublic()))
	{
		OTASCIIArmor ascTransfer;
		
		// Get the Issuer's public key in ASCII-armored format
		rhs.GetPublicKey(ascTransfer);
		
		// Decodes a public key from ASCII armor into m_keyPublic, which stores it as a EVP_PKEY pointer.
		this->SetPublicKey(ascTransfer);
        
        if ((NULL != this->m_pMetadata) && (NULL != rhs.m_pMetadata))
            *(this->m_pMetadata) = *(rhs.m_pMetadata);
	}
    else
        OTLog::Error("OTAsymmetricKey::OTAsymmetricKey: Error: Asymmetric key construction attempt either with itself, "
                     "or with a private key (when expecting public.)\n");
    
//    if (NULL == m_p_ascKey)
//    {
//        m_p_ascKey = new OTASCIIArmor;
//        OT_ASSERT(NULL != m_p_ascKey);
//    }
}


// -------------------------------------------------------------------------------------------

OTAsymmetricKey::OTAsymmetricKey() :
    m_p_ascKey(NULL),
    m_bIsPublicKey(false),
    m_bIsPrivateKey(false),
    m_pMetadata(new OTSignatureMetadata)
{
//    if (NULL == m_p_ascKey)
//    {
//        m_p_ascKey = new OTASCIIArmor;
//        OT_ASSERT(NULL != m_p_ascKey);
//    }   
}

// -------------------------------------------------------------------------------------------


OTAsymmetricKey::~OTAsymmetricKey()
{
//	Release_AsymmetricKey(); // ******
    
    m_timer.clear(); // Since ReleaseKeyLowLevel is no longer called here (via Release_AsymmetricKey) then
    // m_timer.clear() was no longer getting called, so I added it here to rectify that. See below NOTE for
    // more details.
    //
    // NOTE: It's very unusual that the above is commented out, since my normal convention is to
    // call this function both in the destructor, as well as in the Release() method for any given
    // class.
    // Here's why it's commented out, in this case. Because all it does is call ReleaseKeyLowLevel,
    // which calls ReleaseKeyLowLevel_Hook, which is pure virtual and is what allows the
    // OTAsymmetricKey_OpenSSL class to clean up its OpenSSL-specific private members.
    // We CANNOT call a pure virtual method from a destructor (which is where we currently are)
    // and so we cannot call Release_AsymmetricKey without removing that pure virtual call. The
    // problem is, ReleaseKeyLowLevel USES that pure virtual call all over this file (i.e. in many
    // other places BESIDES the destructor) and so we cannot just remove the pure virtual call it
    // uses which is, in fact, the entire purpose it's being called in the first place. So what I
    // did was, I changed OTAsymmetricKey_OpenSSL to directly clean up its OpenSSL-specific key data,
    // and it just ALSO has the hook override doing the same thing. This way Release_AsymmetricKey
    // can continue to be used by ReleaseKeyLowLevel all over this file, as it was designed, using
    // the hook and the override, yet also this destructor will continue to work perfectly... because
    // Release_AsymmetricKey() is commented out above, we won't have any runtime errors from trying to
    // run a pure virtual method from a destructor. And because OTAsymmetricKey_OpenSSL now cleans itself
    // up in its own destructor automatically, we have no need whatsoever to call a virtual function here
    // to clean it up. So it's commented out.
    // Makes sense? Of course we didn't have any virtuality before OTAsymmetricKey_OpenSSL was added,
    // since OTAsymmetricKey previously had no subclasses at all. But that has changed recently, so that
    // it is now an abstract interface, so that someday a GPG implementation, or NaCl implementation can
    // someday be added.
    // -------------------------
    // Release the ascii-armored version of the key (safe to store in this form.)
    //
    if (NULL != m_p_ascKey)
        delete m_p_ascKey;
    m_p_ascKey = NULL;
    // -------------------------
    if (NULL != m_pMetadata)
        delete m_pMetadata;
    m_pMetadata = NULL;
}

// -------------------------------------------------------------------------------------------

void OTAsymmetricKey::Release_AsymmetricKey()
{
    // -------------------------
    // Release the ascii-armored version of the key (safe to store in this form.)
    //
    // Moving this to the destructor. Shouldn't be going NULL here IMO.
//    if (NULL != m_p_ascKey)
//        delete m_p_ascKey;
//    m_p_ascKey = NULL;
    // -------------------------
    // Release the instantiated OpenSSL key (unsafe to store in this form.)
    //
    ReleaseKeyLowLevel();
    // -------------------------
//	m_bIsPrivateKey = false;  // Every time this Releases, I don't want to lose what kind of key it was. (Once we know, we know.)
    // -------------------------    
}

// -------------------------------------------------------------------------------------------

void OTAsymmetricKey::ReleaseKeyLowLevel()
{
    ReleaseKeyLowLevel_Hook();
    // -------------------------
    m_timer.clear();
    // -------------------------
//	m_bIsPrivateKey = false;  // Every time this Releases, I don't want to lose what kind of key it was. (Once we know, we know.)
    // -------------------------
}

// -------------------------------------------------------------------------------------------

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
    // TODO (remove theTimer entirely. OTCachedKey replaces already.)
    // I set this timer because the above required a password. But now that master key is working,
    // the above would flow through even WITHOUT the user typing his passphrase (since master key still
    // not timed out.) Resulting in THIS timer being reset!  Todo: I already shortened this timer to 30
    // seconds, but need to phase it down to 0 and then remove it entirely! Master key takes over now!
    //
    // -------------------------    
//  if (m_timer.getElapsedTimeInSec() > OT_KEY_TIMER)
        ReleaseKeyLowLevel();
    
    // Programmatic user (developer) may call ReleaseKey, but then we don't actually release it until it's
    // been at least X minutes.
}

// -------------------------------------------------------------------------------------------

void OTAsymmetricKey::Release()
{
    Release_AsymmetricKey();  // My own cleanup is done here.
    
    // Next give the base class a chance to do the same...
//	ot_super::Release(); // THERE IS NO base class in this case. But normally this would be here for most classes.
}

// -------------------------------------------------------------------------------------------

// Load the private key from a .pem file
bool OTAsymmetricKey::LoadPrivateKey(const  OTString & strFoldername, 
                                     const  OTString & strFilename,
                                     const  OTString * pstrReason/*=NULL*/) // This reason is what displays on the passphrase dialog.
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
    
    return this->LoadPrivateKeyFromCertString(strCert, false, pstrReason); // bEscaped=false; "escaped" means pre-pended with "- " as in:   - -----BEGIN CER....
}




// -------------------------------------------------------------------------------------------


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

// -------------------------------------------------------------------------------------------


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



// -------------------------------------------------------------------------------------------

























