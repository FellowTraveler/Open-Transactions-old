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






#include "OTStorage.h"

#include "OTCrypto.h"
#include "OTEnvelope.h"

#include "OTSignature.h"

#include "OTAsymmetricKey.h"
#include "OTSymmetricKey.h"
#include "OTASCIIArmor.h"
#include "OTPseudonym.h"

#include "OTKeyring.h"

#include "OTLog.h"

// ------------------------------------------------------------------------









// ------------------------------------------------------------------------

// Presumably this Envelope contains encrypted data (in binary form.)
// If you would like an ASCII-armored version of that data, just call this
// function.
// Should be called "Get Binary Envelope Encrypted Contents Into Ascii-Armored Form"
//
bool OTEnvelope::GetAsciiArmoredData(OTASCIIArmor & theArmoredText,
                                     bool           bLineBreaks/*=true*/) const
{
	return theArmoredText.SetData(m_dataContents, bLineBreaks);
}

// Should be called "Set This Envelope's binary ciphertext data, from an ascii-armored input string."
//
// Let's say you just retrieved the ASCII-armored contents of an encrypted envelope.
// Perhaps someone sent it to you, and you just read it out of his message.
// And let's say you want to get those contents back into binary form in an
// Envelope object again, so that they can be decrypted and extracted back as
// plaintext. Fear not, just call this function.
//
bool OTEnvelope::SetAsciiArmoredData(const OTASCIIArmor & theArmoredText,
                                           bool           bLineBreaks/*=true*/)
{
	return theArmoredText.GetData(m_dataContents, bLineBreaks);
}

// ------------------------------------------------------------------------

bool OTEnvelope::GetAsBookendedString(OTString & strArmorWithBookends, // output (if successful.)
                                      bool       bEscaped/*=false*/) const
{
    const char * szFunc = "OTEnvelope::GetAsBookendedString";
    // -----------------------------
    OTASCIIArmor theArmoredText;
    // This function will base64 ENCODE m_dataContents, and then
    // Set() that as the string contents on theArmoredText.
	const bool   bSetData = theArmoredText.SetData(m_dataContents, true);//bLineBreaks=true (by default anyway.)
    
    if (bSetData)
    {
        const bool bWritten = theArmoredText.WriteArmoredString(strArmorWithBookends, "ENVELOPE", // todo hardcoded
                                                                bEscaped);
        if (!bWritten)
            OTLog::vError("%s: Failed while calling: "
                          "theArmoredText.WriteArmoredString\n", szFunc);
        else
            return true;
    }
    else
        OTLog::vError("%s: Failed while calling: "
                      "theArmoredText.SetData(m_dataContents, true)\n", szFunc);
    
    return false;
}

// ------------------------------------------------------------------------

bool OTEnvelope::SetFromBookendedString(const OTString & strArmorWithBookends, // input
                                              bool       bEscaped/*=false*/)
{
    const char * szFunc = "OTEnvelope::SetFromBookendedString";
    // -----------------------------
    OTASCIIArmor theArmoredText;
    const bool   bLoaded = theArmoredText.LoadFromString(const_cast<OTString &>(strArmorWithBookends), bEscaped); //std::string str_override="-----BEGIN");
    
    if (bLoaded)
    {
        // This function will base64 DECODE theArmoredText's string contents
        // and return them as binary in m_dataContents
        const bool bGotData = theArmoredText.GetData(m_dataContents, true); // bLineBreaks = true

        if (!bGotData)
            OTLog::vError("%s: Failed while calling: "
                          "theArmoredText.GetData\n", szFunc);
        else
            return true;
    }
    else
        OTLog::vError("%s: Failed while calling: "
                      "theArmoredText.LoadFromString\n", szFunc);
    // -----------------------------
    return false;
}



// ------------------------------------------------------------------------


// Encrypt theInput as envelope using symmetric crypto, using a random AES key that's 
// kept encrypted in an OTSymmetricKey (encrypted using another key derived from  
// thePassword.)

bool OTEnvelope::Encrypt(const OTString & theInput, OTSymmetricKey & theKey, const OTPassword & thePassword)
{
    const char * szFunc = "OTEnvelope::Encrypt";
    // -----------------------------------------------
    OT_ASSERT((thePassword.isPassword() && (thePassword.getPasswordSize() > 0)) || (thePassword.isMemory() && (thePassword.getMemorySize() > 0)));
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

	if (!theKey.HasHashCheck())
	{
		if(!theKey.GenerateHashCheck(thePassword))
		{
		OTLog::vError("%s: Failed trying to generate hash check using password.\n", szFunc);
		return false;
		}
	}

	OT_ASSERT(theKey.HasHashCheck());

    OTPassword  theRawSymmetricKey;
    
    if (false == theKey.GetRawKeyFromPassphrase(thePassword, theRawSymmetricKey))
    {
		OTLog::vError("%s: Failed trying to retrieve raw symmetric key using password.\n", szFunc);
		return false;	
    }
    // -----------------------------------------------
    //
    OTPayload theCipherText;
    
    const bool bEncrypted = OTCrypto::It()->Encrypt(theRawSymmetricKey, // The symmetric key, in clear form.
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




//
bool OTEnvelope::Decrypt(OTString & theOutput, const OTSymmetricKey & theKey, const OTPassword & thePassword)
{
    const char * szFunc = "OTEnvelope::Decrypt";
    // ------------------------------------------------
    OT_ASSERT((thePassword.isPassword() && (thePassword.getPasswordSize() > 0)) || (thePassword.isMemory() && (thePassword.getMemorySize() > 0)));
    OT_ASSERT(theKey.IsGenerated());
    // -----------------------------------------------
    OTPassword  theRawSymmetricKey;
    
    if (false == theKey.GetRawKeyFromPassphrase(thePassword, theRawSymmetricKey))
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
    
    const bool bDecrypted = OTCrypto::It()->Decrypt(theRawSymmetricKey, // The symmetric key, in clear form.
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





//
// There are certain cases where we want the option to pass a Nym OR a
// symmetric key, and the function should be able to handle either.
// This class is used to make that possible.
//

/// (This constructor is private.)
// ---------------------------------
OTNym_or_SymmetricKey::OTNym_or_SymmetricKey()
: m_pNym(NULL), m_pKey(NULL), m_pPassword(NULL), m_bCleanupPassword(false), m_pstrDisplay(NULL)  {}
// ---------------------------------


OTNym_or_SymmetricKey::~OTNym_or_SymmetricKey()
{
    // We don't own these objects.
    // Rather, we own a pointer to ONE of them, since we are a wrapper
    // for this one or that.
    //
    m_pNym       = NULL;
    // -------------
    m_pKey       = NULL;
    // -------------
    if (m_bCleanupPassword && (NULL != m_pPassword))
        delete m_pPassword;
    m_pPassword  = NULL; // optional
    // -------------
    
    m_pstrDisplay = NULL;
    
    // Since this is merely a wrapper class, we don't even Release() these things.
    // However, we DO have a release function, since the programmatic USER of this class
    // MAY wish to Release() whatever it is wrapping. That's his choice. But we don't call
    // it here in the destructor, because we aren't the owner.
    //
//  Release_Nym_or_SymmetricKey(); 
}

// ---------------------------------

OTNym_or_SymmetricKey::OTNym_or_SymmetricKey(const OTNym_or_SymmetricKey & rhs) // same type
: m_pNym(NULL), m_pKey(NULL), m_pPassword(NULL), m_bCleanupPassword(false), m_pstrDisplay(rhs.m_pstrDisplay)
{
    // This class doesn't do any cleanup, it's just a temporary wrapper.
    // So we won't have anything get deleted twice, because this class won't
    // even delete it once.
    //
    m_pNym       = rhs.m_pNym;
    // -----------------
    m_pKey       = rhs.m_pKey;
    m_pPassword  = rhs.m_pPassword; // optional

    //m_bCleanupPassword  = rhs.m_bCleanupPassword; // optional
    //
    // This is commented out because this object keeps a POINTER to the password,
    // which is usually owned by the caller. (So we normally wouldn't delete it.)
    // But sometimes, we have to CREATE the password, in which case we store it until
    // we destruct, and then destroy it in our destructor. (Having it available in the
    // meantime to use, without having to load again.)
    // m_bCleanupPassword thus normally tells us whether the password was passed in
    // by its owner for reference purposes only, or whether we created it internally and
    // thus need to clean it up ourselves.
    // THEREFORE, here in the COPY CONSTRUCTOR, we need to keep a pointer to the password
    // from the rhs object, in case we need that password, but we cannot DESTROY that password,
    // if rhs is also destroying it! Therefore we copy the password, but we leave m_bCleanupPassword
    // as false (its default) since THIS INSTANCE definitely does not own m_pPassword.
    //
}

OTNym_or_SymmetricKey::OTNym_or_SymmetricKey(const OTPseudonym & theNym, const OTString * pstrDisplay/*=NULL*/)  // construct with nym
: m_pNym(const_cast<OTPseudonym *>(&theNym)), m_pKey(NULL), m_pPassword(NULL), m_bCleanupPassword(false), m_pstrDisplay(pstrDisplay)
{
    
}

OTNym_or_SymmetricKey::OTNym_or_SymmetricKey(const OTSymmetricKey & theKey, const OTString * pstrDisplay/*=NULL*/) // construct with key
: m_pNym(NULL), m_pKey(const_cast<OTSymmetricKey *>(&theKey)), m_pPassword(NULL), m_bCleanupPassword(false), m_pstrDisplay(pstrDisplay)
{
    
}

OTNym_or_SymmetricKey::OTNym_or_SymmetricKey(const OTSymmetricKey & theKey, const OTPassword & thePassword, // construct with key and password.
                                             const OTString * pstrDisplay/*=NULL*/) 
: m_pNym(NULL), m_pKey(const_cast<OTSymmetricKey *>(&theKey)),
  m_pPassword(const_cast<OTPassword *>(&thePassword)), m_bCleanupPassword(false), m_pstrDisplay(pstrDisplay)
{
    
}

// ---------------------------------

void OTNym_or_SymmetricKey::swap(OTNym_or_SymmetricKey & other)
{
    if (&other != this)
    {
        std::swap(m_pNym,               other.m_pNym);
        std::swap(m_pKey,               other.m_pKey);
        std::swap(m_pPassword,          other.m_pPassword);
        std::swap(m_bCleanupPassword,   other.m_bCleanupPassword);
        std::swap(m_pstrDisplay,        other.m_pstrDisplay);
    }
}

OTNym_or_SymmetricKey & OTNym_or_SymmetricKey::operator = (OTNym_or_SymmetricKey other) // passed by value.
{
    // swap this with other
    this->swap(other);
    
    // by convention, always return *this
    return *this;    
}

// ---------------------------------
// This is just a wrapper class.
//
void OTNym_or_SymmetricKey::Release() // Someday make this virtual, if we ever subclass it.
{
    OT_ASSERT((m_pNym != NULL) || (m_pKey != NULL)); // m_pPassword is optional
    
    Release_Nym_or_SymmetricKey();
    
    // no need to call ot_super::Release here, since this class has no superclass.
}

// This is just a wrapper class. (Destructor doesn't call this because we aren't the owner.)
//
void OTNym_or_SymmetricKey::Release_Nym_or_SymmetricKey()
{
    if (NULL != m_pNym)
    {
//      m_pNym->Release(); // no such call on OTPseudonym. (Otherwise it wouldn't be commented out.)
    }

    if (NULL != m_pKey)
        m_pKey->Release();

    if (NULL != m_pPassword)
    {
        m_pPassword->zeroMemory();
        // -------------
        if (m_bCleanupPassword) // Only in cases where *this is the actual owner of m_pPassword.
        {
            delete m_pPassword;
            m_pPassword = NULL;
        }
    }
}

// ------------------------------------------------------------------------

bool OTNym_or_SymmetricKey::CompareID(const OTNym_or_SymmetricKey & rhs) const
{
    OTIdentifier idTHIS, idRHS;
    // --------------------------
    this->GetIdentifier(idTHIS);
    rhs.  GetIdentifier(idRHS );
    // --------------------------
    return (idTHIS == idRHS);
}

// ------------------------------------------------------------------------

void OTNym_or_SymmetricKey::GetIdentifier(OTIdentifier & theIdentifier) const
{
    if (this->IsNym())
    {
        m_pNym->GetIdentifier(theIdentifier);
    }
    else if (this->IsKey())
    {
        m_pKey->GetIdentifier(theIdentifier);
    }
    else
    {
        OT_ASSERT(false); // should never happen
    }
}

// ------------------------------------------------------------------------

void OTNym_or_SymmetricKey::GetIdentifier(OTString & strIdentifier) const
{
    if (this->IsNym())
    {
        m_pNym->GetIdentifier(strIdentifier);
    }
    else if (this->IsKey())
    {
        m_pKey->GetIdentifier(strIdentifier);
    }
    else
    {
        OT_ASSERT(false); // should never happen
    }   
}

// ------------------------------------------------------------------------
// From OTEnvelope:
//	bool GetAsBookendedString  (      OTString     & strArmorWithBookends, bool bEscaped    = false ) const;
//	bool SetFromBookendedString(const OTString     & strArmorWithBookends, bool bEscaped    = false );

bool OTNym_or_SymmetricKey::Open_or_Decrypt(const OTEnvelope & inputEnvelope,
                                                  OTString   & strOutput,
                                            const OTString   * pstrDisplay/*=NULL*/)
{
    const char * szFunc = "OTNym_or_SymmetricKey::Open_or_Decrypt";
    // --------------------------
    bool bSuccess                  = false;
    bool bHadToInstantiatePassword = false;
    // ---------------
	// Decrypt/Open inputEnvelope into strOutput
    //    
    if (this->IsNym()) // *this is a Nym.
    {
        bSuccess = (const_cast<OTEnvelope &>(inputEnvelope)).Open(*(this->GetNym()), strOutput);
    }
    else if (this->IsKey()) // *this is a symmetric key, possibly with a password already as well.
    {
        OTPassword * pPassword = NULL;
        
        if (this->HasPassword()) // Password is already available. Let's use it.
            pPassword = this->GetPassword();
        else // NO PASSWORD already? let's collect it from the user...
        {
            const OTString strDisplay((NULL == pstrDisplay) ? szFunc : pstrDisplay->Get());
            // NOTE: m_pstrDisplay overrides this below.
            // -------------------------------------------
            // returns a text OTPassword, or NULL.
            //
            pPassword = OTSymmetricKey::GetPassphraseFromUser((NULL == m_pstrDisplay) ? &strDisplay : m_pstrDisplay);//bool bAskTwice=false
            
            if (NULL == pPassword) // Unable to retrieve passphrase from user.
            {
                OTLog::vOutput(0, "%s: Failed trying to retrieve passphrase for key. "
                               "Returning false.\n", szFunc);
                return false;
            }
            else // OTNym_or_SymmetricKey stores this, if it creates it.
                 // (And cleans it up on destruction, IF it created it.)
                 //
                bHadToInstantiatePassword = true;
        }
        // -------------------------------------------
        //
        bSuccess = (const_cast<OTEnvelope &>(inputEnvelope)).Decrypt(strOutput, *(this->GetKey()), *pPassword);
        
        // We only set this, presuming we have to at all, if it was a success.
        if (bHadToInstantiatePassword)
        {
            if (bSuccess)
            {
                m_bCleanupPassword = true;
                m_pPassword        = pPassword; // Not bothering to cleanup whatever was here before, since we only end up here if m_pPassword was set to NULL (according to above logic...)
            }
            else // We instantiated the password, but the decrypt failed. (Need to cleanup the password then.)
            {
                delete pPassword;
                pPassword = NULL;
            }
        }
    }
    // else ? should never happen.
    // -------------------------------------------
    return bSuccess;
}



// ------------------------------------------------------------------------




bool OTNym_or_SymmetricKey::Seal_or_Encrypt(      OTEnvelope & outputEnvelope,
                                            const OTString     strInput,
                                            const OTString   * pstrDisplay/*=NULL*/)
{
    const char * szFunc = "OTNym_or_SymmetricKey::Seal_or_Encrypt";
    // --------------------------
    bool bSuccess                  = false;
    bool bHadToInstantiatePassword = false;
    // ---------------
	// Encrypt/Seal strInput into outputEnvelope
    //
    if (this->IsNym())
    {
        bSuccess = outputEnvelope.Seal(*(this->GetNym()), strInput);
    }
    // -------------------------------------------
    else if (this->IsKey())
    {
        OTPassword * pPassword = NULL;
        
        if (this->HasPassword()) // Password is already available. Let's use it.
            pPassword = this->GetPassword();
        else // no password? let's collect it from the user...
        {
            const OTString strDisplay((NULL == pstrDisplay) ? szFunc : pstrDisplay->Get());
            // NOTE: m_pstrDisplay overrides this below.
            // -------------------------------------------
            // returns a text OTPassword, or NULL.
            //
            pPassword = OTSymmetricKey::GetPassphraseFromUser((NULL == m_pstrDisplay) ? &strDisplay : m_pstrDisplay);//bool bAskTwice=false
            
            if (NULL == pPassword) // Unable to retrieve passphrase from user.
            {
                OTLog::vOutput(0, "%s: Failed trying to retrieve passphrase for key. "
                               "Returning false.\n", szFunc);
                return false;
            }
            else // OTNym_or_SymmetricKey stores this, if it creates it.
                 // (And cleans it up on destruction, IF it created it.)
                 //
                bHadToInstantiatePassword = true;
        }
        // -------------------------------------------
        //
        bSuccess = outputEnvelope.Encrypt(strInput, *(this->GetKey()), *pPassword);
        
        // We only set this, presuming we have to at all, if it was a success.
        if (bHadToInstantiatePassword)
        {
            if (bSuccess)
            {
                m_bCleanupPassword = true;
                m_pPassword        = pPassword; // Not bothering to cleanup whatever was here before, since we only end up here if m_pPassword was set to NULL (according to above logic...)
            }
            else // We instantiated the password, but the encrypt failed. (Need to cleanup the password then.)
            {
                delete pPassword;
                pPassword = NULL;
            }
        }
    }
    // else ? should never happen.
    // -----------------------------------
	return bSuccess;
}





// -----------------------------------------------------------------------------------



// RSA / AES
//

bool OTEnvelope::Seal(const OTPseudonym & theRecipient, const OTString & theInput)
{
    setOfAsymmetricKeys   theKeys;
    theKeys.insert(const_cast<OTAsymmetricKey *>(&(theRecipient.GetPublicKey())));
    // -----------------------------
    return this->Seal(theKeys, theInput);
}
// ------------------------------------------------------------------------


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

// ------------------------------------------------------------------------



// Seal up as envelope (Asymmetric, using public key and then AES key.)

bool OTEnvelope::Seal(setOfAsymmetricKeys & RecipPubKeys, const OTString & theInput)
{
    OT_ASSERT_MSG(RecipPubKeys.size() > 0, "OTEnvelope::Seal: ASSERT: RecipPubKeys.size() > 0");
    // -----------------------------------------------
    
    return OTCrypto::It()->Seal(RecipPubKeys, theInput, m_dataContents);
}
// ------------------------------------------------------------------------

    
// RSA / AES

bool OTEnvelope::Open(const OTPseudonym & theRecipient, OTString & theOutput, OTPasswordData * pPWData/*=NULL*/)
{
    const char * szFunc = "OTEnvelope::Open";
	// ------------------------------------------------
    
    return OTCrypto::It()->Open(m_dataContents, theRecipient, theOutput, pPWData);
}


// ------------------------------------------------------------------------



// DONE: Fix OTEnvelope so we can seal to multiple recipients simultaneously.
// DONE: Fix OTEnvelope so it supports symmetric crypto as well as asymmetric.

// DONE: Remove the Nym stored inside the purse, and replace with a
// session key, just as envelopes will support a session key.


// TODO: Make sure OTEnvelope / OTCrypto_OpenSSL is safe with zeroing memory wherever needed.

// Todo: Once envelopes support multiple recipient Nyms, then make a habit of encrypting
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




