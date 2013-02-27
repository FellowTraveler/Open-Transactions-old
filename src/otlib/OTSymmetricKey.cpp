/*************************************************************
 *
 *  OTSymmetricKey.cpp
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


#include "OTStorage.h"

#include "OTIdentifier.h"
#include "OTPassword.h"
#include "OTASCIIArmor.h"
#include "OTEnvelope.h"
#include "OTCrypto.h"
#include "OTSymmetricKey.h"
#include "OTAsymmetricKey.h"
#include "OTLog.h"



// ------------------------------------------------------------------------

// This class stores the iteration count, the salt, and the encrypted key.
// These are all generated or set when you call GenerateKey.


// ------------------------------------------------------------------------

// Note: this calculates its ID based only on m_dataEncryptedKey,
// and does NOT include salt, IV, iteration count, etc when 
// generating the hash for the ID.
//
void OTSymmetricKey::GetIdentifier(OTIdentifier & theIdentifier) const
{
//  const bool bCalc = 
        theIdentifier.CalculateDigest(m_dataEncryptedKey);
}

void OTSymmetricKey::GetIdentifier(OTString & strIdentifier) const
{
    OTIdentifier theIdentifier;
    const bool bCalc = 
        theIdentifier.CalculateDigest(m_dataEncryptedKey);
    if (bCalc)
        theIdentifier.GetString(strIdentifier);
}





// ------------------------------------------------------------------------

// Generates this OTSymmetricKey based on an OTPassword. The generated key is 
// stored in encrypted form, based on a derived key from that password.
//


// Done:  Change pDerivedKey to ppDerivedKey, since you CANNOT derive a key BEFORE calling
// GenerateKey, since the salt and iteration count are both part of the derivation process!!


// ppDerivedKey: CALLER RESPONSIBLE TO DELETE.  (optional arg.)
//
bool OTSymmetricKey::GenerateKey(const 
                 OTPassword & thePassphrase,
                 OTPassword ** ppDerivedKey/*=NULL*/)  // Output. If you want, I can pass this back to you.
{    
    OT_ASSERT(m_uIterationCount > 1000);
    OT_ASSERT(!m_bIsGenerated);
//  OT_ASSERT(thePassphrase.isPassword());
    // -------------------------------------------------------------------------------------------------
    const char * szFunc = "OTSymmetricKey::GenerateKey";
    
    OTLog::vOutput(2, "  Begin: %s: GENERATING keys and passwords...\n", szFunc);
    // -------------------------------------------------------------------------------------------------
	if (false == m_dataIV.Randomize( OT_DEFAULT_SYMMETRIC_IV_SIZE )) 
	{
		OTLog::vError("%s: Failed generating iv for encrypting a symmetric key. (Returning false.)\n", szFunc);
		return false;
	}
    // -------------------------------------------------------------------------------------------------
	if (false == m_dataSalt.Randomize( OT_DEFAULT_SYMMETRIC_SALT_SIZE )) 
	{
		OTLog::vError("%s: Failed generating random salt. (Returning false.)\n", 
                      szFunc);
		return false;
	}    
    // -------------------------------------------------------------------------------------------------
    //
    // Generate actual key (a randomized memory space.)
    // We will use the derived key for encrypting the actual key.
    //
    OTPassword  theActualKey;
    
    if (OT_DEFAULT_SYMMETRIC_KEY_SIZE != theActualKey.randomizeMemory(OT_DEFAULT_SYMMETRIC_KEY_SIZE))
	{
		OTLog::vError("%s: Failed generating symmetric key. (Returning false.)\n", szFunc);
		return false;
	}
    // We didn't bother generating the derived key if the above three randomizations failed.
    // 
    // -------------------------------------------------------------------------------------------------
    // Generate derived key from passphrase.
    //
    OTCleanup<OTPassword> theDerivedAngel;
    // ------------------------
    
    OTPassword * pDerivedKey = this->CalculateNewDerivedKeyFromPassphrase(thePassphrase); // asserts already.
    
    if (NULL != ppDerivedKey) // A pointerpointer was passed in... (caller will be responsible then, to delete.)
    {
        *ppDerivedKey = pDerivedKey;
    }
    else // We only clean it up in this case, where the caller didn't want the pointer passed back.
    {
        theDerivedAngel.SetCleanupTarget(*pDerivedKey);
    }
    // Below this point, pDerivedKey is NOT null. (And we only clean it up later if we created it.)
    // -------------------------------------------------------------------------------------------------
    //
    // Below this point, pDerivedKey contains a symmetric key derived from the salt, the iteration
    // count, and the password that was passed in. We will store the salt and iteration count inside this
    // OTSymmetricKey object, and we'll store an encrypted copy of the ActualKey, encrypted to pDerivedKey.
    // We'll also store the IV, which is generated while encrypting the actual key, and which must be used
    // while decrypting it later.
    //
    // Encrypt theActualKey using pDerivedKey, which is clear/raw already. (Both are OTPasswords.)
    // Put the result into the OTPayload m_dataEncryptedKey.
    //
    const bool bEncryptedKey = OTCrypto::It()->Encrypt(*pDerivedKey,  // pDerivedKey is a symmetric key, in clear form. Used for encrypting theActualKey.
                                                       // -------------------------------
                                                       reinterpret_cast<const char *>(theActualKey.getMemory_uint8()), // This is the Plaintext that's being encrypted.
                                                       static_cast<uint32_t>(theActualKey.getMemorySize()),
                                                       // -------------------------------
                                                       m_dataIV, // generated above.
                                                       // -------------------------------
                                                       m_dataEncryptedKey); // OUTPUT. (Ciphertext.)
    m_bIsGenerated = bEncryptedKey;
    
    OTLog::vOutput(2, "  End: %s: (GENERATING keys and passwords...) %s\n", 
                   szFunc, m_bIsGenerated ? "SUCCESS" : "FAILED");

    return m_bIsGenerated;
}


bool OTSymmetricKey::GenerateHashCheck(const OTPassword & thePassphrase)
{
    OT_ASSERT(m_uIterationCount > 1000);

	if (!m_bIsGenerated)
	{
		OTLog::vError("%s: No Key Generated, run GenerateKey(), and this function will not be needed!",__FUNCTION__);
		OT_ASSERT(false);
		return false;
	}

	if (this->HasHashCheck())
	{
		OTLog::vError("%s: Already have a HashCheck, no need to create one!",__FUNCTION__);
		return false;
	}

	OT_ASSERT(this->m_dataHashCheck.IsEmpty());

	OTPassword * pDerivedKey = this->CalculateNewDerivedKeyFromPassphrase(thePassphrase); // asserts already.
    
    if (NULL == pDerivedKey) // A pointerpointer was passed in... (caller will be responsible then, to delete.)
    {
		OTLog::vError("%s: failed to calculate derived key",__FUNCTION__);
		return false;
    }

	if (!this->HasHashCheck())
	{
		OTLog::vError("%s: Still don't have a hash check (even after generating one)\n!"
			"this is bad. Will assert.",__FUNCTION__);
		OT_ASSERT(false);
		return false;
	}
}

bool OTSymmetricKey::ReGenerateHashCheck(const OTPassword & thePassphrase)
{
	if (!this->HasHashCheck())
	{
		OTLog::vOutput(0,"%s: Warning!! We don't have a hash-check yet... will create one anyway.",__FUNCTION__);
	}

	if (!this->m_dataHashCheck.IsEmpty()) this->m_dataHashCheck.zeroMemory();
	OT_ASSERT(this->m_dataHashCheck.IsEmpty());

	this->m_bHasHashCheck = false;

	return this->GenerateHashCheck(thePassphrase);
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
// OTSymmetricKey object, then decrypts the encrypted symmetric key (using derived key) and returns clear symmetric
// key back as another OTPassword object.



// Assumes key is already generated. Tries to get the raw clear key from its encrypted form, via 
// its passphrase being used to derive a key for that purpose.
//
// If returns true, theRawKeyOutput will contain the decrypted symmetric key, in an OTPassword object.
// Otherwise returns false if failure.
//


// ------------------------------------------------------------------------ 
// The derived key is used for decrypting the actual symmetric key.
// It's called the derived key because it is derived from the passphrase.
//
// CALLER IS RESPONSIBLE TO DELETE.
//
OTPassword * OTSymmetricKey::CalculateDerivedKeyFromPassphrase(const OTPassword & thePassphrase, const bool bCheckForHashCheck /*= true*/) const
{
//  OT_ASSERT(m_bIsGenerated);
//  OT_ASSERT(thePassphrase.isPassword());
	OTPassword * pDerivedKey = NULL;

	OTPayload tmpDataHashCheck = this->m_dataHashCheck;

	if (bCheckForHashCheck)
	{
		if (!this->HasHashCheck())
		{
			OTLog::vError("%s: Unable to Calculate Derived Key, as Hash Check is missing!", __FUNCTION__);
			OT_ASSERT(false);
			return false;
		}
		OT_ASSERT(!tmpDataHashCheck.IsEmpty());
	}
	else
	{
		if (!this->HasHashCheck())
		{
			OTLog::vOutput(0,"%s: Warning!! No hash check, ignoring... (since bCheckForHashCheck was set false)", __FUNCTION__);
			OT_ASSERT(tmpDataHashCheck.IsEmpty());
		}
	}

	pDerivedKey = OTCrypto::It()->DeriveNewKey(thePassphrase, this->m_dataSalt, this->m_uIterationCount, tmpDataHashCheck);

    return pDerivedKey; // can be null
}

OTPassword * OTSymmetricKey::CalculateNewDerivedKeyFromPassphrase(const OTPassword & thePassphrase)
{
//  OT_ASSERT(m_bIsGenerated);
//  OT_ASSERT(thePassphrase.isPassword());
	OTPassword * pDerivedKey = NULL;

	if (!this->HasHashCheck())
	{
		this->m_dataHashCheck.zeroMemory();

		pDerivedKey = OTCrypto::It()->DeriveNewKey(thePassphrase, this->m_dataSalt, this->m_uIterationCount, this->m_dataHashCheck);
	}
	else 
	{
		OTLog::vError("%s: Calling Wrong function!! Hash Check already exists!", __FUNCTION__);
	}
    
    OT_ASSERT(NULL != pDerivedKey);
	OT_ASSERT(!this->m_dataHashCheck.IsEmpty());

	this->m_bHasHashCheck = true;
	
    return pDerivedKey;
}


// ------------------------------------------------------------------------ 

// Assumes key is already generated. Tries to get the raw clear key from its 
// encrypted form, via its passphrase being used to derive a key for that purpose.
//
bool OTSymmetricKey::GetRawKeyFromPassphrase(const
                                             OTPassword & thePassphrase, 
                                             OTPassword & theRawKeyOutput,
                                             OTPassword * pDerivedKey/*=NULL*/) const // Optionally pass this, to save me the step.
{    
    OT_ASSERT(m_bIsGenerated);
//  OT_ASSERT(thePassphrase.isPassword());
    // -------------------------------------------------------------------------------------------------
    const char * szFunc = "OTSymmetricKey::GetRawKeyFromPassphrase";    
    // -------------------------------------------------------------------------------------------------    
    OTCleanup<OTPassword> theDerivedAngel;
    // ------------------------
    if (NULL == pDerivedKey)
    {
        // todo, security: Do we have to create all these OTPassword objects on the stack, just
        // as a general practice? In which case I can't use this factory how I'm using it now...
        //

		pDerivedKey = this->CalculateDerivedKeyFromPassphrase(thePassphrase,false); // asserts already.

        theDerivedAngel.SetCleanupTarget(*pDerivedKey);
    }
    // Below this point, pDerivedKey is NOT null. And we only clean it up if we created it.
    // -------------------------------------------------------------------------------------------------
    //
    // Below this point, pDerivedKey contains a derived symmetric key, from the salt, the iteration
    // count, and the password that was passed in. The salt and iteration count were both stored inside this
    // OTSymmetricKey object since this key was originally generated, and we store an encrypted copy of the
    // ActualKey already, as well-- it's encrypted to the Derived Key. (We also store the IV from that 
    // encryption bit.)
    //
    return this->GetRawKeyFromDerivedKey(*pDerivedKey, theRawKeyOutput);
}    
    

// Assumes key is already generated. Tries to get the raw clear key from its encrypted form, via a derived key.
//
// If returns true, theRawKeyOutput will contain the decrypted symmetric key, in an OTPassword object.
// Otherwise returns false if failure.
//
bool OTSymmetricKey::GetRawKeyFromDerivedKey(const OTPassword & theDerivedKey, OTPassword & theRawKeyOutput) const
{
    OT_ASSERT(m_bIsGenerated);
    OT_ASSERT(theDerivedKey.isMemory());
    // -------------------------------------------------------------------------------------------------
    const char * szFunc = "OTSymmetricKey::GetRawKeyFromDerivedKey";    
    // -------------------------------------------------------------------------------------------------
    //
    // Decrypt theActualKey using theDerivedKey, which is clear/raw already. (Both are OTPasswords.)
    // Put the result into theRawKeyOutput.
    //
    // theDerivedKey is a symmetric key, in clear form. Used here
    // for decrypting m_dataEncryptedKey into theRawKeyOutput.
    //
    OTLog::vOutput(2, "%s: *Begin) Attempting to recover actual key using derived key...\n", szFunc);

    const bool bDecryptedKey = OTCrypto::It()->Decrypt(theDerivedKey, // We're using theDerivedKey to decrypt m_dataEncryptedKey.
                                                       // -------------------------------
                                                       // Here's what we're trying to decrypt: the encrypted
                                                       // form of the symmetric key.
                                                       //
                                                       static_cast<const char *>(m_dataEncryptedKey.GetPayloadPointer()), // The Ciphertext.
                                                       m_dataEncryptedKey.GetSize(),
                                                       // -------------------------------
                                                       m_dataIV, // Created when *this symmetric key was generated. Both are already stored.
                                                       // -------------------------------
                                                       theRawKeyOutput); // OUTPUT. (Recovered plaintext of symmetric key.) You can pass OTPassword& OR OTPayload& here (either will work.)
    
    OTLog::vOutput(2, "%s: (End) attempt to recover actual key using derived key...\n", szFunc);
    return bDecryptedKey;
}


// ------------------------------------------------------------------------



// ------------------------------------------------------------------------

// The highest-level possible interface (used by the API)
//


//static  NOTE: this version circumvents the master key.
OTPassword * OTSymmetricKey::GetPassphraseFromUser(const OTString * pstrDisplay/*=NULL*/,
                                                   const bool       bAskTwice  /*=false*/) // returns a text OTPassword, or NULL.
{
    // Caller MUST delete!
    // ---------------------------------------------------
    OTPassword * pPassUserInput = OTPassword::CreateTextBuffer(); // already asserts.
//  pPassUserInput->zeroMemory(); // This was causing the password to come out blank.
    //
    // Below this point, pPassUserInput must be returned, or deleted. (Or it will leak.)
    // -----------------------------------------------
    const char *    szDisplay = "OTSymmetricKey::GetPassphraseFromUser";
    OTPasswordData  thePWData((NULL == pstrDisplay) ? szDisplay : pstrDisplay->Get());
    thePWData.setUsingOldSystem(); // So the cached key doesn't interfere, since this is for a plain symmetric key.
    // -----------------------------------------------
    const int nCallback = souped_up_pass_cb(pPassUserInput->getPasswordWritable_char(),
                                            pPassUserInput->getBlockSize(),
                                            bAskTwice ? 1 : 0,
                                            static_cast<void *>(&thePWData));
    const uint32_t uCallback = static_cast<uint32_t>(nCallback);
    if ((nCallback > 0) &&// Success retrieving the passphrase from the user.
        pPassUserInput->SetSize(uCallback))
    {
        
        //resume
        

        
        OTLog::vOutput(0, "%s: Retrieved passphrase (blocksize %d, actual size %d) from user: %s\n", __FUNCTION__,
                       pPassUserInput->getBlockSize(), nCallback, pPassUserInput->getPassword());
        return pPassUserInput; // Caller MUST delete!
    }
    else
    {
        delete pPassUserInput; pPassUserInput = NULL;
        OTLog::vOutput(0, "%s: Sorry, unable to retrieve passphrase from user. (Failure.)\n", __FUNCTION__);
    }
    
    return NULL;
}

// ------------------------------------------------------------------------

//static 
bool OTSymmetricKey::CreateNewKey(      OTString   & strOutput,
                                  const OTString   * pstrDisplay   /*=NULL*/,
                                  const OTPassword * pAlreadyHavePW/*=NULL*/)
{
    OTPassword * pPassUserInput = NULL;
    OTCleanup<OTPassword> thePWAngel;
    
    if (NULL == pAlreadyHavePW)
    {
        const char *    szDisplay = "Creating new symmetric key.";
        const OTString  strDisplay((NULL == pstrDisplay) ? szDisplay : pstrDisplay->Get());
        // -----------------------------------------------
        pPassUserInput = OTSymmetricKey::GetPassphraseFromUser(&strDisplay, true);//bAskTwice=false by default.
        thePWAngel.SetCleanupTargetPointer(pPassUserInput); // may be NULL.
    }
    else
        pPassUserInput = const_cast<OTPassword *>(pAlreadyHavePW);
    // -----------------------------------------------
    bool bSuccess = false;
        
    if (NULL != pPassUserInput) // Success retrieving the passphrase from the user. (Now let's generate the key...)
    {        
        OTLog::vOutput(3, "%s: Calling OTSymmetricKey theKey.GenerateKey()...\n", __FUNCTION__);
        OTSymmetricKey theKey(*pPassUserInput);
        const bool bGenerated = theKey.IsGenerated();
//      OTLog::vOutput(0, "%s: Finished calling OTSymmetricKey theKey.GenerateKey()...\n", __FUNCTION__);
        
        if (bGenerated && theKey.SerializeTo(strOutput))
            bSuccess = true;
        else
            OTLog::vOutput(1,"%s: Sorry, unable to generate key. (Failure.)\n", __FUNCTION__);
    }
    else
        OTLog::vOutput(1,"%s: Sorry, unable to retrieve password from user. (Failure.)\n", __FUNCTION__);
    
    return bSuccess;
}



// ------------------------------------------------------------------------



//static 
bool OTSymmetricKey::Encrypt(const OTString   & strKey,
                             const OTString   & strPlaintext,
                                   OTString   & strOutput,
                             const OTString   * pstrDisplay   /*=NULL*/,
                             const bool         bBookends     /*=true*/,
                             const OTPassword * pAlreadyHavePW/*=NULL*/)
{
    if (!strKey.Exists() || !strPlaintext.Exists())
    {
        OTLog::vOutput(1,"%s: Nonexistent: either the key or the plaintext. Please supply. (Failure.)\n",
                       __FUNCTION__);
        return false;
    }
    // -----------------------------------
    OTSymmetricKey theKey;
    
    if (false == theKey.SerializeFrom(strKey))
    {    
        OTLog::vOutput(1,"%s: Failed trying to load symmetric key from string. (Returning false.)\n",
                       __FUNCTION__);
        return false;
    }
    // -----------------------------------
    // By this point, we know we have a plaintext and a symmetric Key.
    //
    return OTSymmetricKey::Encrypt(theKey, strPlaintext,
                                   strOutput,
                                   pstrDisplay, bBookends, pAlreadyHavePW);
}
    

// ------------------------------------------------------------------------



//static 
bool OTSymmetricKey::Encrypt(const OTSymmetricKey & theKey,
                             const OTString       & strPlaintext,
                                   OTString       & strOutput,
                             const OTString       * pstrDisplay    /*=NULL*/,
                             const bool             bBookends      /*=true*/,
                             const OTPassword     * pAlreadyHavePW /*=NULL*/)
{
    if (!theKey.IsGenerated())
    {
        OTLog::vOutput(1,"%s: Failure: theKey.IsGenerated() was false. (The calling "
                       "code probably should have checked that key already...)\n", __FUNCTION__);
        return false;
    }
    // -----------------------------------
    if (!strPlaintext.Exists())
    {
        OTLog::vOutput(1,"%s: Plaintext is empty. Please supply. (Failure.)\n",
                       __FUNCTION__);
        return false;
    }
    // -----------------------------------
    // By this point, we know we have a plaintext and a symmetric Key.
    //
    OTPassword * pPassUserInput = NULL;
    OTCleanup<OTPassword> thePWAngel;
    
    if (NULL == pAlreadyHavePW)
    {
        const char *    szDisplay = "Password-protecting a plaintext.";
        const OTString  strDisplay((NULL == pstrDisplay) ? szDisplay : pstrDisplay->Get());
        // -----------------------------------------------
        pPassUserInput = OTSymmetricKey::GetPassphraseFromUser(&strDisplay);//bAskTwice=false by default.
        thePWAngel.SetCleanupTargetPointer(pPassUserInput); // may be NULL.
    }
    else
        pPassUserInput = const_cast<OTPassword *>(pAlreadyHavePW);
    // -----------------------------------------------
    OTASCIIArmor ascOutput;
    bool bSuccess = false;
    // -----------------------------------------------    
    if (NULL != pPassUserInput) // Success retrieving the passphrase from the user. (Now let's encrypt...)
    {
        OTEnvelope theEnvelope;
        
        if (theEnvelope.Encrypt(strPlaintext, const_cast<OTSymmetricKey &>(theKey), *pPassUserInput) &&
            theEnvelope.GetAsciiArmoredData(ascOutput))
        {
            bSuccess = true;
            
            if (bBookends)
            {
                return ascOutput.WriteArmoredString(strOutput, "SYMMETRIC MSG", // todo hardcoding.
                                                    false);//bEscaped=false
            }
            else
            {
                strOutput.Set(ascOutput.Get());
            }
        }
        else
        {
            OTLog::vOutput(1,"%s: Failed trying to encrypt. (Sorry.)\n",
                           __FUNCTION__);
        }
    }
    else
        OTLog::vOutput(1,"%s: Sorry, unable to retrieve passphrase from user. (Failure.)\n", 
                       __FUNCTION__);

    return bSuccess;
}


// ------------------------------------------------------------------------



//static 
bool OTSymmetricKey::Decrypt(const OTString   & strKey,
                                   OTString   & strCiphertext,
                                   OTString   & strOutput,
                             const OTString   * pstrDisplay   /*=NULL*/,
                             const OTPassword * pAlreadyHavePW/*=NULL*/)
{    
    // -----------------------------------
    if (!strKey.Exists())
    {
        OTLog::vOutput(1,"%s: Nonexistent: The symmetric key. Please supply. (Failure.)\n",
                       __FUNCTION__);
        return false;
    }
    // -----------------------------------
    OTSymmetricKey theKey;
    
    if (false == theKey.SerializeFrom(strKey))
    {    
        OTLog::vOutput(1,"%s: Failed trying to load symmetric key from string. (Returning false.)\n",
                       __FUNCTION__);
        return false;
    }
    // -----------------------------------
    // By this point, we know we have a ciphertext envelope and a symmetric Key.
    //
    return OTSymmetricKey::Decrypt(theKey, strCiphertext,
                                   strOutput,
                                   pstrDisplay, pAlreadyHavePW);
}


// ------------------------------------------------------------------------


//static 
bool OTSymmetricKey::Decrypt(const OTSymmetricKey & theKey,
                                   OTString       & strCiphertext,
                                   OTString       & strOutput,
                             const OTString       * pstrDisplay   /*=NULL*/,
                             const OTPassword     * pAlreadyHavePW/*=NULL*/)
{
    if (!theKey.IsGenerated())
    {
        OTLog::vOutput(1,"%s: Failure: theKey.IsGenerated() was false. (The calling "
                       "code probably should have checked for that...)\n", __FUNCTION__);
        return false;
    }
    // -----------------------------------------------------
    OTASCIIArmor ascArmor;
    const bool bLoadedArmor = OTASCIIArmor::LoadFromString(ascArmor, strCiphertext); // str_bookend="-----BEGIN" by default
	// -----------------------------------------------------
    if (!bLoadedArmor || !ascArmor.Exists())
    {
        OTLog::vError("%s: Failure loading ciphertext envelope:\n\n%s\n\n",
                      __FUNCTION__, strCiphertext.Get());
        return false;
    }
	// -------------------------------------------------
    // By this point, we know we have a ciphertext envelope and a symmetric Key.
    //
    OTPassword * pPassUserInput = NULL;
    OTCleanup<OTPassword> thePWAngel;
    
    if (NULL == pAlreadyHavePW)
    {
        const char *    szDisplay = "Decrypting a password-protected ciphertext.";
        const OTString  strDisplay((NULL == pstrDisplay) ? szDisplay : pstrDisplay->Get());
        // -----------------------------------------------
        pPassUserInput = OTSymmetricKey::GetPassphraseFromUser(&strDisplay);//bAskTwice=false by default.
        thePWAngel.SetCleanupTargetPointer(pPassUserInput); // may be NULL.
    }
    else
        pPassUserInput = const_cast<OTPassword *>(pAlreadyHavePW);
    // -----------------------------------------------
    bool  bSuccess  = false;
    // -----------------------------------------------    
    if (NULL != pPassUserInput) // Success retrieving the passphrase from the user. (Now let's decrypt...)
    {
        OTEnvelope theEnvelope(ascArmor);
        
        if (theEnvelope.Decrypt(strOutput, theKey, *pPassUserInput))
        {
            bSuccess = true;
        }
        else
        {
            OTLog::vOutput(1,"%s: Failed trying to decrypt. (Sorry.)\n",
                           __FUNCTION__);
        }
    }
    else
        OTLog::vOutput(1,"%s: Sorry, unable to retrieve passphrase from user. (Failure.)\n", 
                       __FUNCTION__);
    
    return bSuccess;
}




// ------------------------------------------------------------------------


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
    {
        return this->SerializeFrom(ascInput);
    }

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
    uint16_t   from_bool_is_generated = (m_bIsGenerated ? 1 : 0);
    uint16_t   n_is_generated    = static_cast<uint16_t>(htons(static_cast<uint16_t>(from_bool_is_generated))); 
    uint16_t   n_key_size_bits   = static_cast<uint16_t>(htons(static_cast<uint16_t>(m_nKeySize))); 
    // ----------------------------------------------------------------------------------------
    uint32_t   n_iteration_count = static_cast<uint32_t>(htonl(static_cast<uint32_t>(m_uIterationCount))); 
    
    uint32_t   n_salt_size       = static_cast<uint32_t>(htonl(static_cast<uint32_t>(m_dataSalt.GetSize()))); 
    uint32_t   n_iv_size         = static_cast<uint32_t>(htonl(static_cast<uint32_t>(m_dataIV.GetSize()))); 
    uint32_t   n_enc_key_size    = static_cast<uint32_t>(htonl(static_cast<uint32_t>(m_dataEncryptedKey.GetSize()))); 

	uint32_t   n_hash_check_size  = static_cast<uint32_t>(htonl(static_cast<uint32_t>(m_dataHashCheck.GetSize())));
    // -----------------------------------------------
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

	theOutput.Concatenate(reinterpret_cast<void *>(&n_hash_check_size),   
                          static_cast<uint32_t>(sizeof(n_hash_check_size)));

	theOutput.Concatenate(m_dataHashCheck.GetPayloadPointer(),
                          m_dataHashCheck.GetSize());
    // -----------------------------------------------
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
    uint16_t host_is_generated = static_cast<uint16_t>(ntohs(static_cast<uint16_t>(n_is_generated)));
    
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
    
    m_uIterationCount = static_cast<uint32_t>(ntohl(n_iteration_count));
    
    OTLog::vOutput(5, "%s: iteration_count: %ld \n", 
                   __FUNCTION__, 
                   static_cast<long>(m_uIterationCount)
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
    



    // ****************************************************************************
    //
    // Read network-order "hash check size". (convert to host order) 
    //    
    uint32_t  n_hash_check_size = 0;
    
    if (0 == (nRead = theInput.OTfread(reinterpret_cast<uint8_t*>(&n_hash_check_size), 
                                       static_cast<uint32_t>(sizeof(n_hash_check_size)))))
	{
		OTLog::vError("%s: Error reading n_hash_check_size.\n", szFunc);
		OTLog::vError("%s: Looks like we don't have a hash check yet! (will make one)\n", szFunc);
		m_bHasHashCheck = false;
		return false;
	}
    OT_ASSERT(nRead == static_cast<uint32_t>(sizeof(n_hash_check_size)));
    // ----------------------------------------------------------------------------
	// convert from network to HOST endian.
    
    const uint32_t lHashCheckSize = ntohl(n_hash_check_size);
    
    OTLog::vOutput(5, "%s: hash_check_size value: %ld \n", 
                   __FUNCTION__, 
                   static_cast<long>(lHashCheckSize)
                   );

	// ----------------------------------------------------------------------------
    //
    // Then read the Hashcheck itself.
    //
	m_dataHashCheck.SetPayloadSize(lHashCheckSize);
    
    if (0 == (nRead = theInput.OTfread(static_cast<uint8_t*>(const_cast<void *>(m_dataHashCheck.GetPayloadPointer())),
                                       static_cast<uint32_t>(lHashCheckSize))))
    {
        OTLog::vError("%s: Error reading hash check data.\n", szFunc);
        return false;
    }
    
    OTLog::vOutput(5, "%s: hash check data actually read: %ld \n", 
                   __FUNCTION__, 
                   static_cast<long>(nRead)
                   );

    OT_ASSERT(nRead == static_cast<uint32_t>(lHashCheckSize));

	m_bHasHashCheck = !m_dataHashCheck.IsEmpty();

    // ****************************************************************************





    return true;
}

// ------------------------------------------------------------------------












// ------------------------------------------------------------------------

OTSymmetricKey::OTSymmetricKey()
:   m_bIsGenerated(false), 
    m_bHasHashCheck(false),
    m_nKeySize(OT_DEFAULT_SYMMETRIC_KEY_SIZE_BITS), // 128
    m_uIterationCount(OT_DEFAULT_ITERATION_COUNT) 
{
    
}

// ------------------------------------------------------------------------

OTSymmetricKey::OTSymmetricKey(const OTPassword & thePassword)
:   m_bIsGenerated(false), 
    m_bHasHashCheck(false),
    m_nKeySize(OT_DEFAULT_SYMMETRIC_KEY_SIZE_BITS), // 128
    m_uIterationCount(OT_DEFAULT_ITERATION_COUNT)
{
//    const bool bGenerated = 
        this->GenerateKey(thePassword);
}


// ------------------------------------------------------------------------

OTSymmetricKey::~OTSymmetricKey()
{
    Release_SymmetricKey();
}
// ------------------------------------------------------------------------

void OTSymmetricKey::Release_SymmetricKey()
{
    m_bIsGenerated    = false;
    m_uIterationCount = OT_DEFAULT_ITERATION_COUNT;
    m_nKeySize        = OT_DEFAULT_SYMMETRIC_KEY_SIZE_BITS; // 128
    
    m_dataSalt.Release();
    m_dataIV.Release();
    m_dataEncryptedKey.Release();    
}

void OTSymmetricKey::Release()
{
    Release_SymmetricKey();
    
    // no call to ot_super::Release() here, since this is a base class (currently with no children...)
}






// ------------------------------------------------------------------------





































