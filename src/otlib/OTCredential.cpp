/*************************************************************
 *
 *  OTCredential.cpp
 *
 */
// A nym contains a list of credentials

// Each credential contains a "master" subkey, and a list of subkeys
// signed by that master.

// The same class (subkey) is used because there are master credentials
// and subkey credentials, so we're using a single "subkey" class to
// encapsulate each credential, both for the master credential and
// for each subkey credential.

// Each subkey has 3 key pairs: encryption, signing, and authentication.

// Each key pair has 2 OTAsymmetricKeys (public and private.)

/************************************************************
 -----BEGIN PGP SIGNED MESSAGE-----
 Hash: SHA1
 
 *                 OPEN TRANSACTIONS
 *
 *       Financial Cryptography and Digital Cash
 *       Library, Protocol, API, Server, CLI, GUI
 *
 *       -- Anonymous Numbered Accounts.
 *       -- Untraceable Digital Cash.
 *       -- Triple-Signed Receipts.
 *       -- Cheques, Vouchers, Transfers, Inboxes.
 *       -- Basket Currencies, Markets, Payment Plans.
 *       -- Signed, XML, Ricardian-style Contracts.
 *       -- Scripted smart contracts.
 *
 *  Copyright (C) 2010-2013 by "Fellow Traveler" (A pseudonym)
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
 *   -- otlib.........A class library.......LICENSE:...LAGPLv3
 *   -- otapi.........A client API..........LICENSE:...LAGPLv3
 *   -- opentxs/ot....Command-line client...LICENSE:...LAGPLv3
 *   -- otserver......Server Application....LICENSE:....AGPLv3
 *  Github.com/FellowTraveler/Open-Transactions/wiki/Components
 *
 *  All of the above OT components were designed and written by
 *  Fellow Traveler, with the exception of Moneychanger, which
 *  was contracted out to Vicky C (bitcointrader4@gmail.com).
 *  The open-source community has since actively contributed.
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
 *   (==> This means if you are only using the OT API, then you
 *   don't have to open-source your code--only your changes to
 *   Open-Transactions itself must be open source. Similar to
 *   LGPLv3, except it applies to software-as-a-service, not
 *   just to distributing binaries.)
 *
 *   Extra WAIVER for OpenSSL, Lucre, and all other libraries
 *   used by Open Transactions: This program is released under
 *   the AGPL with the additional exemption that compiling,
 *   linking, and/or using OpenSSL is allowed. The same is true
 *   for any other open source libraries included in this
 *   project: complete waiver from the AGPL is hereby granted to
 *   compile, link, and/or use them with Open-Transactions,
 *   according to their own terms, as long as the rest of the
 *   Open-Transactions terms remain respected, with regard to
 *   the Open-Transactions code itself.
 *
 *   Lucre License:
 *   This code is also "dual-license", meaning that Ben Lau-
 *   rie's license must also be included and respected, since
 *   the code for Lucre is also included with Open Transactions.
 *   See Open-Transactions/src/otlib/lucre/LUCRE_LICENSE.txt
 *   The Laurie requirements are light, but if there is any
 *   problem with his license, simply remove the Lucre code.
 *   Although there are no other blind token algorithms in Open
 *   Transactions (yet. credlib is coming), the other functions
 *   will continue to operate.
 *   See Lucre on Github:  https://github.com/benlaurie/lucre
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
 Version: GnuPG v1.4.9 (Darwin)
 
 iQIcBAEBAgAGBQJRSsfJAAoJEAMIAO35UbuOQT8P/RJbka8etf7wbxdHQNAY+2cC
 vDf8J3X8VI+pwMqv6wgTVy17venMZJa4I4ikXD/MRyWV1XbTG0mBXk/7AZk7Rexk
 KTvL/U1kWiez6+8XXLye+k2JNM6v7eej8xMrqEcO0ZArh/DsLoIn1y8p8qjBI7+m
 aE7lhstDiD0z8mwRRLKFLN2IH5rAFaZZUvj5ERJaoYUKdn4c+RcQVei2YOl4T0FU
 LWND3YLoH8naqJXkaOKEN4UfJINCwxhe5Ke9wyfLWLUO7NamRkWD2T7CJ0xocnD1
 sjAzlVGNgaFDRflfIF4QhBx1Ddl6wwhJfw+d08bjqblSq8aXDkmFA7HeunSFKkdn
 oIEOEgyj+veuOMRJC5pnBJ9vV+7qRdDKQWaCKotynt4sWJDGQ9kWGWm74SsNaduN
 TPMyr9kNmGsfR69Q2Zq/FLcLX/j8ESxU+HYUB4vaARw2xEOu2xwDDv6jt0j3Vqsg
 x7rWv4S/Eh18FDNDkVRChiNoOIilLYLL6c38uMf1pnItBuxP3uhgY6COm59kVaRh
 nyGTYCDYD2TK+fI9o89F1297uDCwEJ62U0Q7iTDp5QuXCoxkPfv8/kX6lS6T3y9G
 M9mqIoLbIQ1EDntFv7/t6fUTS2+46uCrdZWbQ5RjYXdrzjij02nDmJAm2BngnZvd
 kamH0Y/n11lCvo1oQxM+
 =uSzz
 -----END PGP SIGNATURE-----
 **************************************************************/

#include <stdafx.h>

#include <algorithm>

// ------------------------------------------------
#include "OTStorage.h"

#include "OTContract.h"
#include "OTAsymmetricKey.h"
#include "OTCredential.h"
#include "OTSignature.h"

#include "OTLog.h"

// ------------------------------------------------



// DONE: Add OTKeypair member for m_pMetadata.
// Add method to set the Metadata. Or instead of a member,
// just have the method set the public and private keys.
//
// Then a Subkey can have a similar function which sets the metadata
// for its three keypairs (they are identical except for the A|E|S.)
//
// When a Nym is loaded, load up its master credentials and all their
// subcredentials. Since their metadata was supposedly set properly at
// creation, verify it at load time.

// TODO: on OTNym, change GetPublicKey to GetPublicKeyForVerify or
// GetPublicKeyForEncrypt or GetPublicKeyForTransmission. Then
// rebuild so that all places using GetPublicKey are forced to choose
// one of those. Same with GetPrivateKeyForSigning, GetPrivateKeyForDecrypt,
// and GetPrivateKeyForAuthentication.


// DONE: add the methods to OTPseudonym for generating a master credential contract
// and a sub contract. Add ability to save / load with this data. Then go from there.


OTKeypair::OTKeypair() :
    m_pkeyPublic (OTAsymmetricKey::KeyFactory()),
    m_pkeyPrivate(OTAsymmetricKey::KeyFactory())
{
    
}

OTKeypair::~OTKeypair()
{
    // -----------------------------
    if (NULL != m_pkeyPublic)
        delete m_pkeyPublic; // todo: else error
	m_pkeyPublic	= NULL;
    // -----------------------------
    if (NULL != m_pkeyPrivate)
        delete m_pkeyPrivate; // todo: else error
	m_pkeyPrivate	= NULL;
    // -----------------------------
}
// ---------------------------------------------------------------

void OTKeypair::SetMetadata(const OTSignatureMetadata & theMetadata)
{
    OT_ASSERT(NULL != m_pkeyPublic);
    OT_ASSERT(NULL != m_pkeyPrivate);
    OT_ASSERT(NULL != m_pkeyPublic-> m_pMetadata);
    OT_ASSERT(NULL != m_pkeyPrivate->m_pMetadata);
    // ------------------------------
    // Set it for both keys.
    //
    *(m_pkeyPublic-> m_pMetadata) = theMetadata;
    *(m_pkeyPrivate->m_pMetadata) = theMetadata;
}

// ---------------------------------------------------------------

bool OTKeypair::HasPublicKey()
{
    OT_ASSERT(NULL != m_pkeyPublic);
    // ---------------------------------------------------------------
	return m_pkeyPublic->IsPublic(); // This means it actually has a public key in it, or tried to.
}

bool OTKeypair::HasPrivateKey()
{
    OT_ASSERT(NULL != m_pkeyPrivate);
    // ---------------------------------------------------------------
	return m_pkeyPrivate->IsPrivate(); // This means it actually has a private key in it, or tried to.
}

// ---------------------------------------------------------------

const OTAsymmetricKey & OTKeypair::GetPublicKey() const
{
    OT_ASSERT(NULL != m_pkeyPublic);
    // ---------------------------------------------------------------
	return (*m_pkeyPublic);
}
// ---------------------------------------------------------------

const OTAsymmetricKey & OTKeypair::GetPrivateKey() const
{
    OT_ASSERT(NULL != m_pkeyPrivate);
    // ---------------------------------------------------------------
	return (*m_pkeyPrivate);
}

// ---------------------------------------------------------------

bool OTKeypair::SaveCertToString(OTString & strOutput, const OTString * pstrReason/*=NULL*/, OTPassword * pImportPassword/*=NULL*/)
{
    OT_ASSERT(NULL != m_pkeyPublic);
    // ---------------------------------------------------------------
    OTString strCert, strReason(NULL == pstrReason ? "OTKeypair::SaveCertToString" : pstrReason->Get());
    
    const bool bSaved = m_pkeyPublic->SaveCertToString(strCert, &strReason, pImportPassword);
    // ---------------------------------------------------------------
	if (bSaved)
        strOutput = strCert;
	
	return bSaved;    
}
// ---------------------------------------------------------------

bool OTKeypair::SavePrivateKeyToString(OTString & strOutput, const OTString * pstrReason/*=NULL*/, OTPassword * pImportPassword/*=NULL*/)
{
    OT_ASSERT(NULL != m_pkeyPrivate);
    // ---------------------------------------------------------------
    OTString strPrivateKey;
    
    const bool bSaved = m_pkeyPrivate->SavePrivateKeyToString(strPrivateKey, pstrReason, pImportPassword);
    // ---------------------------------------------------------------
	if (bSaved)
        strOutput = strPrivateKey;
	
	return bSaved;
}
// ------------------------------------------------

bool OTKeypair::SaveCertAndPrivateKeyToString(OTString & strOutput, const OTString * pstrReason/*=NULL*/, OTPassword * pImportPassword/*=NULL*/)
{
    OTString strCert, strPrivateKey;
    
    const bool bSaved1 = this->SaveCertToString      (strCert,       pstrReason, pImportPassword);
    const bool bSaved2 = this->SavePrivateKeyToString(strPrivateKey, pstrReason, pImportPassword);
    // ---------------------------------------------------------------
	if (bSaved1 && bSaved2)
		strOutput.Format(const_cast<char*>("%s%s"), strPrivateKey.Get(), strCert.Get());
	
	return (bSaved1 && bSaved2);
}
// ------------------------------------------------

bool OTKeypair::LoadCertAndPrivateKeyFromString(const OTString & strInput, const OTString * pstrReason/*=NULL*/, OTPassword * pImportPassword/*=NULL*/)
{
	// ---------------------------------------------------------------
    OT_ASSERT(strInput.Exists());
	// ---------------------------------------------------------------
    // "escaped" means pre-pended with "- " as in:   - -----BEGIN CER....
    //
    const bool bPublic  = this->LoadPublicKeyFromCertString (strInput,   false,  //bool bEscaped=true by default
                                                             pstrReason, pImportPassword);
    const bool bPrivate = this->LoadPrivateKeyFromCertString(strInput,   false,  //bool bEscaped=true by default,
                                                             pstrReason, pImportPassword);
    if (!bPublic)
    {
        OTLog::vError("%s: Although the input string apparently exists, "
                      "LoadPublicKeyFromCertString returned false.\n", __FUNCTION__);
        return false;
    }
    else
    {
        OTLog::vOutput(2, "%s: Successfully loaded public key from string.\n",
                       __FUNCTION__);
    }
    // ----------------
    if (!bPrivate)
    {
        OTLog::vError("%s: Although the input string apparently exists, "
                      "LoadPrivateKeyFromCertString returned false.\n", __FUNCTION__);
        return false;
    }
    else
    {
        OTLog::vOutput(2, "%s: Successfully loaded private key from string.\n", __FUNCTION__);
    }
    // ----------------
    return true;
}

// ------------------------------------------------

bool OTKeypair::SaveAndReloadBothKeysFromTempFile(      OTString   * pstrOutputCert/*=NULL*/,
                                                  const OTString   * pstrReason/*=NULL*/,
                                                        OTPassword * pImportPassword/*=NULL*/)
{
    OT_ASSERT(NULL != m_pkeyPrivate);
    OT_ASSERT(NULL != m_pkeyPublic);
    // ---------------------------------------------------------------
    OTString    strOutput;
    const bool  bSuccess   = this->SaveCertAndPrivateKeyToString(strOutput, pstrReason, pImportPassword);
	// ---------------------------------------
	if (bSuccess)
	{
        // todo security. Revisit this part during security audit.
        //
		const OTString strFilename("temp.nym"); // todo stop hardcoding. Plus this maybe should select a random number too.
        
		if (false == OTDB::StorePlainString(strOutput.Get(), OTFolders::Cert().Get(), strFilename.Get())) // temp.nym
		{
			OTLog::vError("%s: Failure storing new cert in temp file: %s\n", __FUNCTION__, strFilename.Get());
			return false;
		}
		// ------------------------------------------
        if (false == this->LoadBothKeysFromCertFile(OTFolders::Cert().Get(), strFilename, pstrReason, pImportPassword))
            return false; // LoadBothKeysFromCertFile already has error logs, no need to log twice at this point.
		// ------------------------------------------
        if (NULL != pstrOutputCert)
            pstrOutputCert->Set(strOutput); // Success!
	}
	
	return bSuccess;   
}


// ---------------------------------------------------------------
// Load from local storage.
bool OTKeypair::LoadPrivateKey(const OTString & strFoldername,
                               const OTString & strFilename, const OTString * pstrReason/*=NULL*/, OTPassword * pImportPassword/*=NULL*/)
{
    OT_ASSERT(NULL != m_pkeyPrivate);
    // ---------------------------------------------------------------
    return m_pkeyPrivate->LoadPrivateKey(strFoldername, strFilename, pstrReason, pImportPassword);
}

bool OTKeypair::LoadPublicKey (const OTString & strFoldername,
                               const OTString & strFilename)
{
    OT_ASSERT(NULL != m_pkeyPublic);
    // ---------------------------------------------------------------
    return m_pkeyPublic->LoadPublicKey(strFoldername, strFilename);
}

// ***************************************************************
// LoadPrivateKeyFromCertString
//
// "escaped" means pre-pended with "- " as in:   - -----BEGIN CERTIFICATE....
//
bool OTKeypair::LoadPrivateKeyFromCertString(const OTString & strCert,
                                             bool bEscaped/*=true*/,
                                             const OTString * pstrReason/*=NULL*/,
                                             OTPassword * pImportPassword/*=NULL*/)
{
    OT_ASSERT(NULL != m_pkeyPrivate);
    // ---------------------------------------------------------------
    return m_pkeyPrivate->LoadPrivateKeyFromCertString(strCert, bEscaped, pstrReason, pImportPassword);
}

// ***************************************************************
// Load Public Key from Cert (file or string)
//
bool OTKeypair::LoadPublicKeyFromCertString(const OTString   & strCert, bool bEscaped/*=true*/,
                                            const OTString   * pstrReason/*=NULL*/,
                                                  OTPassword * pImportPassword/*=NULL*/) // DOES handle bookends, AND escapes.
{
    OT_ASSERT(NULL != m_pkeyPublic);
    // ---------------------------------------------------------------
    return m_pkeyPublic->LoadPublicKeyFromCertString(strCert, bEscaped, pstrReason, pImportPassword);
}

bool OTKeypair::LoadPublicKeyFromCertFile(const OTString   & strFoldername,
                                          const OTString   & strFilename,
                                          const OTString   * pstrReason/*=NULL*/,
                                                OTPassword * pImportPassword/*=NULL*/) // DOES handle bookends.
{
    OT_ASSERT(NULL != m_pkeyPublic);
    // ---------------------------------------------------------------
    return m_pkeyPublic->LoadPublicKeyFromCertFile(strFoldername, strFilename, pstrReason, pImportPassword);
}



bool OTKeypair::MakeNewKeypair(int nBits/*=1024*/)
{
    const char * szFunc = "OTKeypair::MakeNewKeypair";
	// ---------------------------------------------------------------
    OT_ASSERT(NULL != m_pkeyPrivate);
    OT_ASSERT(NULL != m_pkeyPublic);
    // ---------------------------------------------------------------
    OTLowLevelKeyData lowLevelData;
    
    if (!lowLevelData.MakeNewKeypair(nBits))
    {
        OTLog::vError("%s: Failed in a call to OTLowLevelKeyData::MakeNewKeypair(%d).\n",
                      szFunc, nBits);
        return false;
    }
    // ---------------------------------------------------------------
    return lowLevelData.SetOntoKeypair(*this);
    
    // If true is returned:
    // Success! At this point, theKeypair's public and private keys have been set.
    // Keep in mind though, they still won't be "quite right" until saved and loaded
    // again, at least according to existing logic. That saving/reloading is currently
    // performed in OTPseudonym::GenerateNym().
}



bool OTKeypair::LoadBothKeysFromCertFile(const OTString   & strFoldername,
                                         const OTString   & strFilename,
                                         const OTString   * pstrReason/*=NULL*/,
                                               OTPassword * pImportPassword/*=NULL*/)
{
    const char * szFunc = "OTKeypair::LoadBothKeysFromCertFile";
    // -------------------------------------
    OT_ASSERT(NULL != m_pkeyPublic);
    OT_ASSERT(NULL != m_pkeyPrivate);
    // ---------------------------------------------------------------
    bool bPublic  = false;
    bool bPrivate = false;
    
    bPublic  = m_pkeyPublic-> LoadPublicKeyFromCertFile (strFoldername.Get(), strFilename.Get(),
                                                         pstrReason, pImportPassword);
    bPrivate = m_pkeyPrivate->LoadPrivateKey            (strFoldername.Get(), strFilename.Get(),
                                                         pstrReason, pImportPassword);
    if (!bPublic)
    {
        OTLog::vError("%s: Although the ascii-armored file (%s) was read, LoadPublicKeyFromCert "
                      "returned false.\n", szFunc, strFilename.Get());
        return false;
    }
    else
    {
        OTLog::vOutput(2, "%s: Successfully loaded public key from Certfile: %s\n",
                       szFunc, strFilename.Get());
    }
    // -----------------
    if (!bPrivate)
    {
        OTLog::vError("%s: Although the ascii-armored file (%s) was read, LoadPrivateKey returned false.\n",
                      szFunc, strFilename.Get());
        return false;
    }
    else
    {
        OTLog::vOutput(2, "%s: Successfully loaded private key from certfile: %s\n",
                       szFunc, strFilename.Get());
    }
    // -----------------------------------------
    return true;
}


bool OTKeypair::SignContract(OTContract & theContract, OTPasswordData  * pPWData/*=NULL*/)
{
    OT_ASSERT(NULL != m_pkeyPrivate);
    // --------------------------------------------
    return theContract.SignWithKey(*m_pkeyPrivate, pPWData);
}



// ***************************************************************************************
// PUBLIC KEY

// * Get the public key in ASCII-armored format                 -- OTASCIIArmor
// * Get the public key in ASCII-armored format WITH bookends   -- OTString
//       - ------- BEGIN PUBLIC KEY --------
//       Notice the "- " before the rest of the bookend starts.
//
bool OTKeypair::GetPublicKey(OTASCIIArmor & strKey) const
{
    OT_ASSERT(NULL != m_pkeyPublic);
    // ---------------------------------------------------------------
    return m_pkeyPublic->GetPublicKey(strKey);
}

bool OTKeypair::GetPublicKey(OTString & strKey, bool bEscaped/*=true*/) const
{
    OT_ASSERT(NULL != m_pkeyPublic);
    // ---------------------------------------------------------------
    return m_pkeyPublic->GetPublicKey(strKey, bEscaped);
}

// -----------------------------------------------------------------------
// (Below) Decodes a public key from ASCII armor into an actual key pointer
// and sets that as the m_pKey on this object.
//
bool OTKeypair::SetPublicKey(const OTASCIIArmor & strKey)
{
    OT_ASSERT(NULL != m_pkeyPublic);
    // ---------------------------------------------------------------
    return m_pkeyPublic->SetPublicKey(strKey);
}


// Decodes a public key from bookended key string into an actual key
// pointer, and sets that as the m_pkeyPublic on this object.
// This is the version that will handle the bookends ( -----BEGIN PUBLIC KEY-----)
//
bool OTKeypair::SetPublicKey(const OTString & strKey, bool bEscaped/*=false*/)
{
    OT_ASSERT(NULL != m_pkeyPublic);
    
    // ---------------------------------------------------------------
    if (strKey.Contains("PGP PUBLIC KEY"))
	{
		OTASCIIArmor theArmor;
		
		if (theArmor.LoadFromString(const_cast<OTString &>(strKey), bEscaped))
		{
			// This function expects that the bookends are already removed.
			// The ascii-armor loading code removes them and handles the escapes also.
			return m_pkeyPublic->LoadPublicKeyFromPGPKey(theArmor);
		}
		else
        {
			OTLog::Output(2, "OTKeypair::SetPublicKey: Failed extracting PGP public key from ascii-armored text.\n");
			return false;
		}
	}
	else // the below function SetPublicKey (in the return call) expects the
        // bookends to still be there, and it will handle removing them. (Unlike PGP code above.)
		return m_pkeyPublic->SetPublicKey(strKey, bEscaped);
}

// ***************************************************************************************
// PRIVATE KEY
// Get the private key in ASCII-armored format with bookends
// - ------- BEGIN ENCRYPTED PRIVATE KEY --------
// Notice the "- " before the rest of the bookend starts.
//
bool OTKeypair::GetPrivateKey(OTString & strKey, bool bEscaped/*=true*/) const
{
    OT_ASSERT(NULL != m_pkeyPrivate);
    // ---------------------------------------------------------------
    return m_pkeyPrivate->GetPrivateKey(strKey, bEscaped);
}

bool OTKeypair::GetPrivateKey(OTASCIIArmor & strKey) const  // Get the private key in ASCII-armored format
{
    OT_ASSERT(NULL != m_pkeyPrivate);
    // ---------------------------------------------------------------
    return m_pkeyPrivate->GetPrivateKey(strKey);
}

// Decodes a private key from ASCII armor into an actual key pointer
// and sets that as the m_pPrivateKey on this object.
// This is the version that will handle the bookends ( -----BEGIN ENCRYPTED PRIVATE KEY-----)
bool OTKeypair::SetPrivateKey(const OTString & strKey, bool bEscaped/*=false*/)
{
    OT_ASSERT(NULL != m_pkeyPrivate);
    // ---------------------------------------------------------------
    const char * szOverride = "PGP PRIVATE KEY";

	if (strKey.Contains(szOverride))
	{
		OTASCIIArmor theArmor;
        
		if (theArmor.LoadFromString(const_cast<OTString &>(strKey), bEscaped,
                                    szOverride)) // szOverride == "PGP PRIVATE KEY"
		{
			// This function expects that the bookends are already removed.
			// The ascii-armor loading code removes them and handles the escapes also.
//			return m_pkeyPrivate->LoadPrivateKeyFromPGPKey(theArmor);
            //
			OTLog::vOutput(0, "OTKeypair::SetPrivateKey 1: Failure: PGP private keys are NOT YET SUPPORTED.\n\n");
//			OTLog::vOutput(0, "OTKeypair::SetPrivateKey 1: Failure: PGP private keys are NOT YET SUPPORTED:\n\n%s\n\n",
//                           strKey.Get());
			return false;
		}
		else 
        {
			OTLog::vOutput(0, "OTKeypair::SetPrivateKey 2: Failure: PGP private keys are NOT YET SUPPORTED.\n\n");
//			OTLog::vOutput(0, "OTKeypair::SetPrivateKey 2: Failure: PGP private keys are NOT YET SUPPORTED:\n\n%s\n\n",
//                           strKey.Get());
			return false;
		}
	}
	else // the below function SetPrivateKey (in the return call) expects the
         // bookends to still be there, and it will handle removing them. (Unlike PGP code above.)
        //
		return m_pkeyPrivate->SetPrivateKey(strKey, bEscaped);
}

bool OTKeypair::SetPrivateKey(const OTASCIIArmor & strKey) // Decodes a private key from ASCII armor into an actual key pointer and sets that as the m_pKey on this object.
{
    OT_ASSERT(NULL != m_pkeyPrivate);
    // ---------------------------------------------------------------
    return m_pkeyPrivate->SetPrivateKey(strKey);
}

bool OTKeypair::CalculateID(OTIdentifier & theOutput) const
{
    OT_ASSERT(NULL != m_pkeyPublic);
    // ---------------------------------------------------------------
    return m_pkeyPublic->CalculateID(theOutput); // Only works for public keys.
}

// ***************************************************************************************







// Contains 3 key pairs: signing, authentication, and encryption.
// This is stored as an OTContract, and it must be signed by the
// master key. (which is also an OTSubcredential.)
//

void OTSubcredential::SetOwner(OTCredential & theOwner)
{
    m_pOwner = &theOwner;
}
// ----------------------------------------------------------------
OTSubcredential::OTSubcredential()
: ot_super(), m_StoreAs(OTSubcredential::credPrivateInfo), m_pOwner(NULL)       { m_strContractType = "CREDENTIAL"; }
// ----------------------------------------------------------------
OTSubcredential::OTSubcredential(OTCredential & theOwner)
: ot_super(), m_StoreAs(OTSubcredential::credPrivateInfo), m_pOwner(&theOwner)  { m_strContractType = "CREDENTIAL"; }
// ----------------------------------------------------------------
OTSubcredential::~OTSubcredential()
{
    Release_Subcredential();
    
}

// ----------------------------------------------------------------

//virtual
void OTSubcredential::Release()
{
    Release_Subcredential();  // My own cleanup is done here.
    
    // Next give the base class a chance to do the same...
	ot_super::Release(); // since I've overridden the base class, I call it now...
}

// ----------------------------------------------------------------

    
void OTSubcredential::Release_Subcredential()
{
    // Release any dynamically allocated members here. (Normally.) 
}

// ----------------------------------------------------------------

//virtual
bool OTSubcredential::SetPublicContents(const mapOfStrings & mapPublic)
{
    m_mapPublicInfo   = mapPublic;
    return true;
}


//virtual
bool OTSubcredential::SetPrivateContents(const mapOfStrings & mapPrivate,
                                               OTPassword   * pImportPassword/*=NULL*/) // if not NULL, it means to use this password by default.)
{
    m_mapPrivateInfo  = mapPrivate;
    return true;
}

void OTSubcredential::SetMasterCredID(const OTString & strMasterCredID)
{
    m_strMasterCredID = strMasterCredID;
}

void OTSubcredential::SetNymIDandSource(const OTString & strNymID, const OTString & strSourceForNymID)
{
    m_strNymID          = strNymID;
    m_strSourceForNymID = strSourceForNymID;
}


// -------------------------------------------------------------------

void OTSubcredential::UpdateMasterPublicToString(OTString & strAppendTo) // Used in UpdateContents.
{
    OT_ASSERT(NULL != m_pOwner);
    OTASCIIArmor ascMaster(m_pOwner->GetPubCredential());
    strAppendTo.Concatenate("<masterPublic>\n%s</masterPublic>\n\n",
                            ascMaster.Get());
}

void OTSubcredential::UpdatePublicContentsToString(OTString & strAppendTo) // Used in UpdateContents.
{
    if (m_mapPublicInfo.size() > 0)
    {
        strAppendTo.Concatenate("<publicContents count=\"%d\">\n\n", m_mapPublicInfo.size());
        
        FOR_EACH(mapOfStrings, m_mapPublicInfo)
        {
            OTString     strInfo((*it).second);
            OTASCIIArmor ascInfo(strInfo);
            strAppendTo.Concatenate("<publicInfo key=\"%s\">\n%s</publicInfo>\n\n",
                                      (*it).first.c_str(), ascInfo.Get());
        }
        // ------------------------------
        strAppendTo.Concatenate("</publicContents>\n\n");
    }
}

void OTSubcredential::UpdatePublicCredentialToString(OTString & strAppendTo) // Used in UpdateContents.
{
    if (this->GetContents().Exists())
    {
        OTASCIIArmor ascContents(this->GetContents());
        if (ascContents.Exists())
            strAppendTo.Concatenate("<publicCredential>\n%s</publicCredential>\n\n",
                                    ascContents.Get());
    }    
}

void OTSubcredential::UpdatePrivateContentsToString(OTString & strAppendTo) // Used in UpdateContents.
{
    if (m_mapPrivateInfo.size() > 0)
    {
        strAppendTo.Concatenate("<privateContents count=\"%d\">\n\n", m_mapPrivateInfo.size());
        
        FOR_EACH(mapOfStrings, m_mapPrivateInfo)
        {
            OTString     strInfo((*it).second);
            OTASCIIArmor ascInfo(strInfo);
            strAppendTo.Concatenate("<privateInfo key=\"%s\">\n%s</privateInfo>\n\n",
                                    (*it).first.c_str(), ascInfo.Get());
        }
        strAppendTo.Concatenate("</privateContents>\n\n");
    }
}

void OTSubcredential::UpdateContents()
{
	m_xmlUnsigned.Release();
    
	m_xmlUnsigned.Concatenate("<subCredential nymID=\"%s\"\n" // a hash of the nymIDSource
							  " masterCredentialID=\"%s\" >\n\n", // Hash of the master credential that signed this subcredential.
							  this->GetNymID().Get(), this->GetMasterCredID().Get());
    
    if (this->GetNymIDSource().Exists())
    {
        OTASCIIArmor ascSource;
        ascSource.SetString(this->GetNymIDSource()); // A nym should always verify through its own source. (Whatever that may be.)
        m_xmlUnsigned.Concatenate("<nymIDSource>\n%s</nymIDSource>\n\n", ascSource.Get());
    }
    // --------------------------------------------
//  if (OTSubcredential::credPublicInfo == m_StoreAs)  // (Always saving public info.)
    {
        // *****************************************************
        // PUBLIC INFO
        this->UpdateMasterPublicToString(m_xmlUnsigned);
        // --------------------------------------------
        this->UpdatePublicContentsToString(m_xmlUnsigned);
        // *****************************************************
    }
	// -------------------------------------------------
    // If we're saving the private credential info...
    // 
    if (OTSubcredential::credPrivateInfo == m_StoreAs)
    {
        this->UpdatePublicCredentialToString(m_xmlUnsigned);
        // -------------------------------------
        this->UpdatePrivateContentsToString(m_xmlUnsigned);
    }
	// -------------------------------------------------	
	m_xmlUnsigned.Concatenate("</subCredential>\n");
    // --------------------------------------------
    m_StoreAs = OTSubcredential::credPrivateInfo;  // <=== SET IT BACK TO DEFAULT BEHAVIOR. Any other state processes ONCE, and then goes back to this again.
}


// ------------------------------


// return -1 if error, 0 if nothing, and 1 if the node was processed.
//
int OTSubcredential::ProcessXMLNode(irr::io::IrrXMLReader*& xml)
{
	int nReturnVal = 0;
	
    const OTString strNodeName(xml->getNodeName());

	// Here we call the parent class first.
	// If the node is found there, or there is some error,
	// then we just return either way.  But if it comes back
	// as '0', then nothing happened, and we'll continue executing.
	//
	// -- Note you can choose not to call the parent if
	// you don't want to use any of those xml tags.
	// As I do in the case of OTAccount.
    //
	// if (nReturnVal = OTContract::ProcessXMLNode(xml))
    //	  return nReturnVal;
	
    // --------------------------------------------------
	if (strNodeName.Compare("subCredential"))
	{
		m_strNymID			= xml->getAttributeValue("nymID");
		m_strMasterCredID	= xml->getAttributeValue("masterCredentialID");
		
		OTLog::Output(1, "Loading subcredential...\n");
		
		nReturnVal = 1;
	}
	// ----------------------------------
	else if (strNodeName.Compare("nymIDSource"))
	{		
		OTLog::Output(1, "Loading nymIDSource...\n");
		
        OTASCIIArmor ascTemp;
        if (false == OTContract::LoadEncodedTextField(xml, ascTemp))
		{
			OTLog::vError("Error in %s line %d: failed loading expected nymIDSource field.\n",
                          __FILE__, __LINE__);
			return (-1); // error condition
		}
        if (ascTemp.Exists())
            ascTemp.GetString(m_strSourceForNymID);

		nReturnVal = 1;
	}
	// ----------------------------------
	else if (strNodeName.Compare("masterPublic"))
	{
        OTString strMasterPublicCredential;
        
		if (false == OTContract::LoadEncodedTextField(xml, strMasterPublicCredential))
		{
			OTLog::vError("Error in %s line %d: failed loading expected master public credential while loading subcredential.\n",
                          __FILE__, __LINE__);
			return (-1); // error condition
		}
        // Verify the master public credential we loaded against the one we expected to get, according
        // to the OTCredential that is m_pOwner.
        //
        else if ((NULL != m_pOwner) && false == (m_pOwner->GetPubCredential().Compare(strMasterPublicCredential)))
        {
            OTLog::vError("Failure in %s line %d: while loading subcredential: master public "
                          "credential loaded just now, doesn't match the actual master public credential, "
                          "according to the current owner object.\n",
                          __FILE__, __LINE__);
			return (-1); // error condition
        }
		
		nReturnVal = 1;
	}
	// ------------------------------------------------------------------------------------
	else if (strNodeName.Compare("publicContents"))
	{
        OTString strCount;
        strCount = xml->getAttributeValue("count");
        const int nCount = strCount.Exists() ? atoi(strCount.Get()) : 0;
        if (nCount > 0)
        {
            int nTempCount = nCount;
            mapOfStrings mapPublic;
            
            while (nTempCount-- > 0)
            {
                // -----------------------------------------------                
                const char	*	pElementExpected	= "publicInfo";
                OTString		strPublicInfo;
                
                // This map contains values we will also want, when we read the info...
                // (The OTContract::LoadEncodedTextField call below will read all the values
                // as specified in this map.)
                //
                mapOfStrings	temp_MapAttributes;
                temp_MapAttributes.insert(std::pair<std::string, std::string>("key", "")); // Value should be "A" or "E" or "S" after reading.
                
                if (false == OTContract::LoadEncodedTextFieldByName(xml, strPublicInfo, pElementExpected, &temp_MapAttributes)) // </publicInfo>
                {
                    OTLog::vError("%s: Error: "
                                  "Expected %s element with text field.\n", __FUNCTION__,
                                  pElementExpected);
                    return (-1); // error condition
                }
                // ------------------------------------------
                mapOfStrings::iterator it = temp_MapAttributes.find("key");                
                if ((it != temp_MapAttributes.end())) // We expected this much.
                {
                    std::string & str_key = (*it).second;
                    
                    if (str_key.size() > 0) // Success finding key type ('A' 'E' or 'S')
                    {
                        // ---------------------------------------
                        mapPublic.insert(std::pair<std::string, std::string>(str_key, strPublicInfo.Get()));
                        // ---------------------------------------
                    }
                    // else it's empty, which is expected if nothing was there, since that's the default value
                    // that we set above for "name" in temp_MapAttributes.
                    else
                    {
                        OTLog::vError("%s: Expected key type of 'A' or 'E' or 'S'.\n", __FUNCTION__);
                        return (-1); // error condition
                    }
                }
                else
                {
                    OTLog::vError("%s: Strange error: couldn't find key type AT ALL.\n", __FUNCTION__); // should never happen.
                    return (-1); // error condition
                }
            } // while
            // --------------------------------
            if (mapPublic.size() != nCount)
            {
                OTLog::vError("%s, %s, %d: Subcredential expected to load %d publicInfo objects, "
                              "but actually loaded %d. (Mismatch, failure loading.)\n",
                              __FUNCTION__, __FILE__, __LINE__, nCount, mapPublic.size());
                return (-1); // error condition
            }
            // --------------------------------
            if (false == this->SetPublicContents(mapPublic))  // <==============  Success.
            {
                OTLog::vError("%s, %s, %d: Subcredential failed setting public contents while loading.\n",
                              __FUNCTION__, __FILE__, __LINE__);
                return (-1); // error condition    
            }
            // --------------------------------            
        } // if strCount.Exists() && nCount > 0
        // -------------------------------------------------------------------------------
		OTLog::Output(2, "Loaded publicContents for subcredential.\n");
		
		nReturnVal = 1;
	}
	// ----------------------------------
	else if (strNodeName.Compare("publicCredential"))
	{
		if (false == OTContract::LoadEncodedTextField(xml, m_strContents)) // <========= m_strContents.
		{
			OTLog::vError("Error in %s line %d: failed loading expected public credential while loading private subcredential.\n",
                          __FILE__, __LINE__);
			return (-1); // error condition
		}
		
		nReturnVal = 1;
	}
	// ----------------------------------
	else if (strNodeName.Compare("privateContents"))
	{
        OTString strCount;
        strCount = xml->getAttributeValue("count");
        const int nCount = strCount.Exists() ? atoi(strCount.Get()) : 0;
        if (nCount > 0)
        {
            int nTempCount = nCount;
            mapOfStrings mapPrivate;
            
            while (nTempCount-- > 0)
            {
                // -----------------------------------------------                
                const char	*	pElementExpected	= "privateInfo";
                OTString		strPrivateInfo;
                
                // This map contains values we will also want, when we read the info...
                // (The OTContract::LoadEncodedTextField call below will read all the values
                // as specified in this map.)
                //
                mapOfStrings	temp_MapAttributes;
                temp_MapAttributes.insert(std::pair<std::string, std::string>("key", "")); // Value should be "A" or "E" or "S" after reading.
                
                if (false == OTContract::LoadEncodedTextFieldByName(xml, strPrivateInfo, pElementExpected, &temp_MapAttributes)) // </privateInfo>
                {
                    OTLog::vError("%s: Error: "
                                  "Expected %s element with text field.\n", __FUNCTION__,
                                  pElementExpected);
                    return (-1); // error condition
                }
                // ------------------------------------------
                mapOfStrings::iterator it = temp_MapAttributes.find("key");                
                if ((it != temp_MapAttributes.end())) // We expected this much.
                {
                    std::string & str_key = (*it).second;
                    
                    if (str_key.size() > 0) // Success finding key type ('A' 'E' or 'S')
                    {
                        // ---------------------------------------
                        mapPrivate.insert(std::pair<std::string, std::string>(str_key, strPrivateInfo.Get()));
                        // ---------------------------------------
                    }
                    // else it's empty, which is expected if nothing was there, since that's the default value
                    // that we set above for "name" in temp_MapAttributes.
                    else
                    {
                        OTLog::vError("%s: Expected key type of 'A' or 'E' or 'S'.\n", __FUNCTION__);
                        return (-1); // error condition
                    }
                }
                else
                {
                    OTLog::vError("%s: Strange error: couldn't find key type AT ALL.\n", __FUNCTION__); // should never happen.
                    return (-1); // error condition
                }
            } // while
            // --------------------------------
            if (mapPrivate.size() != nCount)
            {
                OTLog::vError("%s, %s, %d: Subcredential expected to load %d privateInfo objects, "
                              "but actually loaded %d. (Mismatch, failure loading.)\n",
                              __FUNCTION__, __FILE__, __LINE__, nCount, mapPrivate.size());
                return (-1); // error condition
            }
            // --------------------------------
            OT_ASSERT(NULL != m_pOwner);
            
            // Sometimes we are supposed to use a specific, pre-specified password (versus just
            // blindly asking the user to type a password when it's not cached alrady.) For example,
            // when importing a Nym, the exported version of the Nym is not encrypted to the cached
            // wallet key. It's got its own exported passphrase. So it won't be cached, and we will have
            // the wallet's cached key disabled while loading it. This means we have to enter the same
            // passphrase many times in a row, while OT loads up all the credentials and keys for that
            // Nym. Therefore, instead, we ask the user up front to enter the special passphrase for that
            // exported Nym. Then we just pass it in to all the functions that need it, so none of them have
            // to ask the user to type it.
            //
            // That's what brings us here now... when that happens, m_pOwner->GetImportPassword() will be set
            // with the appropriate pointer to the passphrase. Otherwise it will be NULL. Meanwhile SetPrivateContents
            // below accepts an import passphrase, which it defaults to NULL.
            //
            // So we just pass it in either way (sometimes it's NULL and the wallet cached master key is used, and
            // sometimes an actual passphrase is passed in, so we use it.)
            
            if (false == this->SetPrivateContents(mapPrivate, m_pOwner->GetImportPassword()))
            {
                OTLog::vError("%s, %s, %d: Subcredential failed setting private contents while loading.\n",
                              __FUNCTION__, __FILE__, __LINE__);
                return (-1); // error condition    
            }
            // --------------------------------            
        } // if strCount.Exists() && nCount > 0
        // -------------------------------------------------------------------------------
		OTLog::Output(2, "Loaded privateContents for subcredential.\n");
		
		nReturnVal = 1;
	}
	// ----------------------------------
	return nReturnVal;
}


// -------------------------------------------------------------------


// return -1 if error, 0 if nothing, and 1 if the node was processed.
//
int OTSubkey::ProcessXMLNode(irr::io::IrrXMLReader*& xml)
{
	int nReturnVal = ot_super::ProcessXMLNode(xml);
	
	// Here we call the parent class first.
	// If the node is found there, or there is some error,
	// then we just return either way.  But if it comes back
	// as '0', then nothing happened, and we'll continue executing.
	//
	// -- Note you can choose not to call the parent if
	// you don't want to use any of those xml tags.
	// As I do in the case of OTAccount.
    //
	if (0 != nReturnVal)
       return nReturnVal;
	// else it was 0 (continue...)
    // --------------------------------------------------
    const OTString strNodeName(xml->getNodeName());
    // --------------------------------------------------
	if (strNodeName.Compare("keyCredential"))
	{
		m_strNymID			= xml->getAttributeValue("nymID");
		m_strMasterCredID	= xml->getAttributeValue("masterCredentialID");
		
		OTLog::Output(1, "Loading keyCredential...\n");
		
		nReturnVal = 1;
	}
	// ----------------------------------
	else if (strNodeName.Compare("masterSigned"))
	{
		if (false == OTContract::LoadEncodedTextField(xml, m_strMasterSigned))
		{
			OTLog::vError("Error in %s line %d: failed loading expected master-signed version while loading keyCredential.\n",
                          __FILE__, __LINE__);
			return (-1); // error condition
		}
		
		nReturnVal = 1;
	}
	// ------------------
	return nReturnVal;
}


// -------------------------------------------------------------------

void OTSubkey::UpdateContents()
{
	m_xmlUnsigned.Release();
    
	m_xmlUnsigned.Concatenate("<keyCredential nymID=\"%s\"\n" // a hash of the nymIDSource
							  " masterCredentialID=\"%s\" >\n\n", // Hash of the master credential that signed this subcredential.
							  this->GetNymID().Get(), this->GetMasterCredID().Get());
    
    if (this->GetNymIDSource().Exists())
    {
        OTASCIIArmor ascSource;
        ascSource.SetString(this->GetNymIDSource()); // A nym should always verify through its own source. (Whatever that may be.)
        m_xmlUnsigned.Concatenate("<nymIDSource>\n%s</nymIDSource>\n\n", ascSource.Get());
    }
    // --------------------------------------------
    // MASTER-SIGNED INFO
    //
    if ((OTSubcredential::credMasterSigned == m_StoreAs) || // MASTER-SIGNED INFO
        (OTSubcredential::credPrivateInfo  == m_StoreAs))
    {
        // --------------------------------------------
        this->UpdateMasterPublicToString(m_xmlUnsigned);
        // --------------------------------------------
        this->UpdatePublicContentsToString(m_xmlUnsigned);
    }
    // --------------------------------------------
    // PUBLIC INFO
    //
    if ((OTSubcredential::credPublicInfo  == m_StoreAs)  || // PUBLIC INFO (signed by subkey, contains master signed info.)
        (OTSubcredential::credPrivateInfo == m_StoreAs))
    {
        OTASCIIArmor ascMasterSigned(this->GetMasterSigned()); // GetMasterSigned() returns the contract containing the master-signed contents from the above block.
        m_xmlUnsigned.Concatenate("<masterSigned>\n%s</masterSigned>\n\n", // Contains all the public info, signed by the master key.
                                  ascMasterSigned.Get());                  // Packaged up here inside a final, subkey-signed credential.
    }
	// -------------------------------------------------
    // PRIVATE INFO
    //
    // If we're saving the private credential info...
    // 
    if (OTSubcredential::credPrivateInfo == m_StoreAs)  // PRIVATE INFO
    {
        this->UpdatePublicCredentialToString(m_xmlUnsigned);
        // -------------------------------------
        this->UpdatePrivateContentsToString(m_xmlUnsigned);
    }
	// -------------------------------------------------	
	m_xmlUnsigned.Concatenate("</keyCredential>\n");
    // --------------------------------------------
    m_StoreAs = OTSubcredential::credPrivateInfo;  // <=== SET IT BACK TO DEFAULT BEHAVIOR. Any other state processes ONCE, and then goes back to this again.
}

// -------------------------------------------------------------------


// return -1 if error, 0 if nothing, and 1 if the node was processed.
//
int OTMasterkey::ProcessXMLNode(irr::io::IrrXMLReader*& xml)
{
	int nReturnVal = ot_super::ProcessXMLNode(xml);
	
	// Here we call the parent class first.
	// If the node is found there, or there is some error,
	// then we just return either way.  But if it comes back
	// as '0', then nothing happened, and we'll continue executing.
	//
	// -- Note you can choose not to call the parent if
	// you don't want to use any of those xml tags.
	// As I do in the case of OTAccount.
    //
	if (0 != nReturnVal)
       return nReturnVal;
	// else it was 0 (continue...)
    // --------------------------------------------------
    const OTString strNodeName(xml->getNodeName());
    // --------------------------------------------------
	if (strNodeName.Compare("masterCredential"))
	{
		m_strNymID = xml->getAttributeValue("nymID");

		m_strMasterCredID.Release();
		
		OTLog::Output(1, "Loading masterCredential...\n");
		
		nReturnVal = 1;
	}
	// ----------------------------------
	return nReturnVal;
}


// -------------------------------------------------------------------

void OTMasterkey::UpdateContents() 
{
	m_xmlUnsigned.Release();
    
	m_xmlUnsigned.Concatenate("<masterCredential nymID=\"%s\" >\n\n", // a hash of the nymIDSource
							  this->GetNymID().Get());
    
    if (this->GetNymIDSource().Exists())
    {
        OTASCIIArmor ascSource;
        ascSource.SetString(this->GetNymIDSource()); // A nym should always verify through its own source. (Whatever that may be.)
        m_xmlUnsigned.Concatenate("<nymIDSource>\n%s</nymIDSource>\n\n", ascSource.Get());
    }
    // --------------------------------------------
    // PUBLIC INFO
    //
//  if (OTSubcredential::credPublicInfo == m_StoreAs)   // PUBLIC INFO  (Always save this in every state.)
    {        
        this->UpdatePublicContentsToString(m_xmlUnsigned);
    }
	// -------------------------------------------------
    // PRIVATE INFO
    //
    // If we're saving the private credential info...
    // 
    if (OTSubcredential::credPrivateInfo == m_StoreAs)   // PRIVATE INFO
    {
        this->UpdatePublicCredentialToString(m_xmlUnsigned);
        // -------------------------------------
        this->UpdatePrivateContentsToString(m_xmlUnsigned);
    }
	// -------------------------------------------------	
	m_xmlUnsigned.Concatenate("</masterCredential>\n");
    // --------------------------------------------
    m_StoreAs = OTSubcredential::credPrivateInfo;  // <=== SET IT BACK TO DEFAULT BEHAVIOR. Any other state processes ONCE, and then goes back to this again.
}



// ***************************************************************************************

// VERIFICATION


// ---------------------------------------
// Verify that m_strNymID is the same as the hash of m_strSourceForNymID.
//
bool OTSubcredential::VerifyNymID()
{
    // ---------------------------------------
    // Verify that m_strNymID is the same as the hash of m_strSourceForNymID.
    //
    OTIdentifier theTempID;
    const bool bCalculate = theTempID.CalculateDigest(m_strSourceForNymID);
    OT_ASSERT(bCalculate);
    // ---------------------------------------
    const OTString strNymID(theTempID);
    if (false == m_strNymID.Compare(strNymID))
    {
        OTLog::vOutput(0, "%s: Failure: When the NymID's source is hashed, the result doesn't match the expected NymID.\n"
                       "Expected: %s\n   Found: %s\n  Source: %s\n", __FUNCTION__, m_strNymID.Get(), strNymID.Get(),
                       m_strSourceForNymID.Get());
        return false;
    }
    // ---------------------------------------
    return true;
}

// ---------------------------------------
// Call VerifyNymID. Then verify m_strMasterCredID against the hash of
// m_pOwner->GetMasterkey().GetPubCredential() (the master credential.) Verify that
// m_pOwner->GetMasterkey() and *this have the same NymID. Then verify the
// signature of m_pOwner->GetMasterkey().
//
bool OTSubcredential::VerifyInternally()
{
    OT_ASSERT(NULL != m_pOwner);
    // ---------------------------------------
    // Verify that m_strNymID is the same as the hash of m_strSourceForNymID.
    //
    if (false == this->VerifyNymID())
        return false;
    // ---------------------------------------
    // Verify that m_pOwner->GetMasterkey() and *this have the same NymID.
    //
    if (false == m_strNymID.Compare(m_pOwner->GetMasterkey().GetNymID()))
    {
        OTLog::vOutput(0, "%s: Failure: The actual master credential's NymID doesn't match the NymID on this subcredential.\n"
                       "    This NymID: %s\nMaster's NymID: %s\n My Master Cred ID: %s\n", __FUNCTION__,
                       m_strNymID.Get(), m_pOwner->GetMasterkey().GetNymID().Get(),
                       m_strMasterCredID.Get());
        return false;
    }
    // ---------------------------------------
    // Verify m_strMasterCredID against the hash of m_pOwner->GetMasterkey().GetPubCredential()
    // (the master credentialID is a hash of the master credential.)
    //
    OTIdentifier theActualMasterID;
    const bool bCalcMasterCredID = theActualMasterID.CalculateDigest(m_pOwner->GetPubCredential());
    OT_ASSERT(bCalcMasterCredID);
    const OTString strActualMasterID(theActualMasterID);
 
    if (false == m_strMasterCredID.Compare(strActualMasterID))
    {
        OTLog::vOutput(0, "%s: Failure: When the actual Master Credential is hashed, the "
                       "result doesn't match the expected Master Credential ID.\n"
                       "Expected: %s\n   Found: %s\nMaster Cred:\n%s\n", __FUNCTION__,
                       m_strMasterCredID.Get(), strActualMasterID.Get(),
                       m_pOwner->GetPubCredential().Get());
        return false;
    }
    // ---------------------------------------
    // Then verify the signature of m_pOwner->GetMasterkey()...
    // Let's get a few things straight:
    // * OTMasterkey is a key (derived from OTKeyCredential, derived from OTSubcredential) and it can only sign itself.
    // * The only further verification a Masterkey can get is if its hash is posted at the source. Or, if the source
    //   is a public key, then the master key must be signed by the corresponding private key. (Again: itself.)
    // * Conversely to a master key which can ONLY sign itself, all subkeys must ALSO sign themselves.
    //
    // * Thus: Any OTKeyCredential (both master and subkeys, but no other credentials) must ** sign itself.**
    // * Whereas m_strMasterSigned is only used by OTSubkey, and thus only must be verified there.
    // * Any OTSubcredential must also be signed by its master. (Except masters, which already sign themselves.)
    // * Any OTMasterkey must (at some point, and/or regularly) verify against its own source.
    //
    // -----------------
    // * Any OTSubcredential must also be signed by its master. (Except masters, which already sign themselves.)
    //
    if (false == this->VerifySignedByMaster())
    {
        OTLog::vOutput(0, "%s: Failure: This subcredential hasn't been signed by its master credential.\n",
                       __FUNCTION__);
        return false;
    }
    // ---------------------------------------
    return true;
}
// ---------------------------------------

bool OTKeyCredential::VerifySignedBySelf()
{
    return this->VerifyWithKey(m_SigningKey.GetPublicKey());
}

// ---------------------------------------

bool OTSubcredential::VerifySignedByMaster()
{
    OT_ASSERT(NULL != m_pOwner);
    return this->VerifyWithKey(m_pOwner->GetMasterkey().m_SigningKey.GetPublicKey());
}

// ---------------------------------------

bool OTSubkey::VerifySignedByMaster()
{
    // See if m_strMasterSigned was signed by my master credential.
    //
    OTSubkey theMasterSigned(*(this->m_pOwner));
    
    if (m_strMasterSigned.Exists() && theMasterSigned.LoadContractFromString(m_strMasterSigned))
    {
        // Here we need to MAKE SURE that the "master signed" version contains the same
        // CONTENTS as the actual version.
        
        if (false == this->GetNymID().Compare(theMasterSigned.GetNymID()))
        {
            OTLog::vOutput(0, "%s: Failure, NymID of this key credential doesn't match NymID of master-signed version of this key credential.\n", __FUNCTION__);
            return false;
        }
        
        if (false == this->GetNymIDSource().Compare(theMasterSigned.GetNymIDSource()))
        {
            OTLog::vOutput(0, "%s: Failure, NymIDSource of this key credential doesn't match NymIDSource of master-signed version of this key credential.\n", __FUNCTION__);
            return false;
        }
        
        if (false == this->GetMasterCredID().Compare(theMasterSigned.GetMasterCredID()))
        {
            OTLog::vOutput(0, "%s: Failure, MasterCredID of this key credential doesn't match MasterCredID of master-signed version of this key credential.\n", __FUNCTION__);
            return false;
        }
        
        if ((this->GetPublicMap().size() > 0) && (this->GetPublicMap() != theMasterSigned.GetPublicMap()))
        {
            OTLog::vOutput(0, "%s: Failure, public info of this key credential doesn't match public info of master-signed version of this key credential.\n", __FUNCTION__);
            return false;
        }

        // Master-signed version of subkey does not contain the private keys, since normally the master is signing
        // the public version of the sub credential (to validate it) and you don't want the public seeing your private keys.
        // So we would never expect these to match, since the master signed version should have no private keys in it.
        //
//        if (this->GetPrivateMap() != theMasterSigned.GetPrivateMap())
//        {
//            OTLog::vOutput(0, "%s: Failure, private info of this key credential doesn't match private info of master-signed version of this key credential.\n", __FUNCTION__);
//            return false;
//        }
        
        const bool bVerifiedWithKey = theMasterSigned.VerifyWithKey(m_pOwner->GetMasterkey().m_SigningKey.GetPublicKey());
        
        // ON SERVER SIDE, THE ACTUAL SUBKEY doesn't have any public key, only the master-signed version of it.
        // (The master-signed version being basically the only contents of the public version.)
        // So we need to be able to, after verifying, load up those contents so they are available on the
        // subkey itself, and not just on some master-signed version of itself hidden inside itself.
        // Otherwise I would have to load up the master-signed version anytime the server-side wanted to
        // mess with any of the keys.
        // Thus: copy the public info from master signed, to *this, if the above call was successful
        //
        if (bVerifiedWithKey && (0 == this->GetPublicMap().size()))
            return this->SetPublicContents(theMasterSigned.GetPublicMap());    // For master credential.

        return bVerifiedWithKey;
    } // if (m_strMasterSigned.Exists() && theMasterSigned.LoadContractFromString(m_strMasterSigned))
    
    return false;
}

// ---------------------------------------

int OTKeypair::GetPublicKeyBySignature(listOfAsymmetricKeys & listOutput, // Inclusive means, return the key even when theSignature has no metadata.
                                       const OTSignature & theSignature, bool bInclusive/*=false*/) const
{
    OT_ASSERT(NULL != m_pkeyPublic);
    OT_ASSERT(NULL != m_pkeyPublic->m_pMetadata);
    
    // We know that EITHER exact metadata matches must occur, and the signature MUST have metadata, (bInclusive=false)
    // OR if bInclusive=true, we know that metadata is still used to eliminate keys where possible, but that otherwise,
    // if the signature has no metadata, then the key is still returned, "just in case."
    //
    if ((false == bInclusive) && (false == theSignature.m_metadata.HasMetadata()))
        return 0;
    // -------------------------
    // Below this point, metadata is used if it's available.
    // It's assumed to be "okay" if it's not available, since any non-inclusive
    // calls would have already returned by now, if that were the case.
    // (But if it IS available, then it must match, or the key won't be returned.)
    //
    if ((false == theSignature.m_metadata.HasMetadata())    || // If the signature has no metadata,
        (false == m_pkeyPublic->m_pMetadata->HasMetadata()) || // Or if m_pkeyPublic has no metadata,
        (m_pkeyPublic->m_pMetadata->HasMetadata() &&           // OR if they BOTH have metadata, and
         theSignature.m_metadata.   HasMetadata() &&           // their metadata is a MATCH...
         (theSignature.m_metadata == *(m_pkeyPublic->m_pMetadata)) ) )
    {
        // ...Then add m_pkeyPublic as a possible match, to listOutput.
        //
        listOutput.push_back(m_pkeyPublic);
        return 1;
    }
    return 0;
}

// ---------------------------------------
// NOTE: You might ask, if we are using theSignature's metadata to narrow down the key type,
// then why are we still passing the key type as a separate parameter? Good question. Because
// often, theSignature will have no metadata at all! In that case, normally we would just NOT
// return any keys, period. Because we assume, if a key credential signed it, then it WILL have
// metadata, and if it doesn't have metadata, then a key credential did NOT sign it, and therefore
// we know from the get-go that none of the keys from the key credentials will work to verify it,
// either. That's why, normally, we don't return any keys if theSignature has no metadata.
// BUT...Let's say you know this, that the signature has no metadata, yet you also still believe
// it may be signed with one of these keys. Further, while you don't know exactly which key it
// actually is, let's say you DO know by context that it's a signing key, or an authentication key,
// or an encryption key. So you specify that. In which case, OT should return all possible matching
// pubkeys based on that 1-letter criteria, instead of its normal behavior, which is to return all
// possible matching pubkeys based on a full match of the metadata.
//
int OTKeyCredential::GetPublicKeysBySignature(listOfAsymmetricKeys & listOutput,
                                              const OTSignature & theSignature,
                                              char cKeyType/*='0'*/) const // 'S' (signing key) or 'E' (encryption key) or 'A' (authentication key)
{
    // Key type was not specified, because we only want keys that match the metadata on theSignature.
    // And if theSignature has no metadata, then we want to return 0 keys.
    if ((  '0' == cKeyType) &&
        (false == theSignature.m_metadata.HasMetadata()))
        return 0;
    // -----------------
    // By this point, we know that EITHER exact metadata matches must occur, and the signature DOES have metadata, ('0')
    // OR the search is only for 'A', 'E', or 'S' candidates, based on cKeyType, and that the signature's metadata
    // can additionally narrow the search down, if it's present, which in this case it's not guaranteed to be.
    int nCount = 0;
    switch (cKeyType)
    {
            // Specific search only for signatures with metadata.
        case '0':
        {   // FYI, theSignature.m_metadata.HasMetadata() is true, in this case.
            // That's why I can just assume theSignature has a key type here:
            switch (theSignature.m_metadata.GetKeyType())
            {
                case 'A': nCount = m_AuthentKey.GetPublicKeyBySignature(listOutput, theSignature); break; // bInclusive=false by default
                case 'E': nCount = m_EncryptKey.GetPublicKeyBySignature(listOutput, theSignature); break; // bInclusive=false by default
                case 'S': nCount = m_SigningKey.GetPublicKeyBySignature(listOutput, theSignature); break; // bInclusive=false by default
                default: OTLog::vError("%s: Unexpected value for theSignature.m_metadata.GetKeyType: %c (failure)\n",
                                       __FUNCTION__, theSignature.m_metadata.GetKeyType()); return 0;
            }
            break;
        }
            // Generalized search which specifies key type and returns keys
            // even for signatures with no metadata. (When metadata is present,
            // it's still used to eliminate keys.)
        case 'A': nCount = m_AuthentKey.GetPublicKeyBySignature(listOutput, theSignature, true); break; // bInclusive=true
        case 'E': nCount = m_EncryptKey.GetPublicKeyBySignature(listOutput, theSignature, true); break; // bInclusive=true
        case 'S': nCount = m_SigningKey.GetPublicKeyBySignature(listOutput, theSignature, true); break; // bInclusive=true
        default:  OTLog::vError("%s: Unexpected value for cKeyType (should be 0, A, E, or S): %c\n",
                                __FUNCTION__, cKeyType); return 0;
    }
    return nCount;
}

// ---------------------------------------
// '0' for cKeyType means, theSignature MUST have metadata in order for ANY keys to be returned, and it MUST match.
// Whereas if you pass 'A', 'E', or 'S' for cKeyType, that means it can ONLY return authentication, encryption, or signing
// keys. It also means that metadata must match IF it's present, but that otherwise, if theSignature has no metadata at
// all, then it will still be a "presumed match" and returned as a possibility. (With the 'A', 'E', or 'S' enforced.)
//
int OTCredential::GetPublicKeysBySignature(listOfAsymmetricKeys & listOutput,
                                           const OTSignature & theSignature,
                                           char cKeyType/*='0'*/) const // 'S' (signing key) or 'E' (encryption key) or 'A' (authentication key)
{
    int nCount = 0;
    FOR_EACH_CONST(mapOfSubcredentials, m_mapSubcredentials)
    {
        const OTSubcredential * pSub = (*it).second;
        OT_ASSERT(NULL != pSub);
        // -------------------------
        const OTSubkey * pKey = dynamic_cast<const OTSubkey *>(pSub);
        if (NULL == pKey) continue; // Skip all non-key credentials. We're looking for keys.
        // -------------------------
        const int nTempCount = pKey->GetPublicKeysBySignature(listOutput, theSignature, cKeyType);
        nCount += nTempCount;
    }
    return nCount;
}

// ---------------------------------------


// ---------------------------------------
// Verify that m_strNymID is the same as the hash of m_strSourceForNymID.
// Subkey verifies (master does not): NymID against Masterkey NymID, and master credential ID against hash of master credential.
// (How? Because OTMasterkey overrides this function and does NOT call the parent, whereas OTSubkey does.)
// Then verify the (self-signed) signature on *this.
//
bool OTKeyCredential::VerifyInternally()
{
    // Verify that m_strNymID is the same as the hash of m_strSourceForNymID. 
    if (false == ot_super::VerifyInternally())
        return false;
    // ---------------------------------------
    // Any OTKeyCredential (both master and subkeys, but no other credentials) must ** sign itself.**
    //
    if (false == this->VerifySignedBySelf())
    {
        OTLog::vOutput(0, "%s: Failed verifying key credential: it's not signed by itself (its own signing key.)\n",
                       __FUNCTION__);
        return false;
    }
    // ---------------------------------------
    return true;
}

// ---------------------------------------
// Verify that m_strNymID is the same as the hash of m_strSourceForNymID. Also verify that
// *this == m_pOwner->GetMasterkey() (the master credential.) Verify the (self-signed)
// signature on *this.
//
bool OTMasterkey::VerifyInternally()
{
    // Verify that m_strNymID is the same as the hash of m_strSourceForNymID.
    //
    // We can't use super here, since OTSubcredential::VerifyInternally will verify
    // m_strMasterCredID against the actual Master, which is not relevant to us in
    // OTMasterkey. But this means if we need anything else that OTKeyCredential::VerifyInternally
    // was doing, we will have to duplicate that here as well...
//  if (false == ot_super::VerifyInternally())
//      return false;
    if (false == this->VerifyNymID())
        return false;
    // ---------------------------------------
    OT_ASSERT(NULL != m_pOwner);
    // Verify that *this == m_pOwner->GetMasterkey() (the master credential.)
    //
    if (this != &(m_pOwner->GetMasterkey()))
    {
        OTLog::vOutput(0, "%s: Failure: Expected *this object to be the same as m_pOwner->GetMasterkey(), "
                       "but it wasn't.\n", __FUNCTION__);
        return false;
    }
    // ---------------------------------------
    // Remember this note above: ...if we need anything else that OTKeyCredential::VerifyInternally
    // was doing, we will have to duplicate that here as well...
    // Since we aren't calling OTKeyCredential::VerifyInternally (the super) and since that function
    // verifies that the credential is self-signed, we must do the same verification here:
    //
    // Any OTKeyCredential (both master and subkeys, but no other credentials) must ** sign itself.**
    //
    if (false == this->VerifySignedBySelf())
    {
        OTLog::vOutput(0, "%s: Failed verifying master credential: it's not signed by itself (its own signing key.)\n",
                       __FUNCTION__);
        return false;
    }
    // ---------------------------------------
    return true;
}


// ---------------------------------------

bool OTSubcredential::VerifyContract()
{
	if (false == this->VerifyContractID())
	{
		OTLog::vOutput(1, "%s: Failed verifying credential ID against whatever it was expected to be.\n",
                       __FUNCTION__);
		return false;
	}
    // -------------------------------------
	if (false == this->VerifyInternally()) // Logs copiously.
        return false;
    // -------------------------------------
    return true;
}


// ------------------------------------------------

bool OTCredential::VerifyInternally() const
{
    // --------------------------------------
    OTIdentifier theActualMasterCredID;
    theActualMasterCredID.CalculateDigest(m_Masterkey.GetPubCredential());
    const OTString strActualMasterCredID(theActualMasterCredID);
    // --------------------------------------
    if (false == m_strNymID.Compare(m_Masterkey.GetNymID()))
    {
        OTLog::vOutput(0, "%s: NymID did not match its "
                       "counterpart in m_Masterkey (failed to verify): %s\n",
                       __FUNCTION__, this->GetNymID().Get());
        return false;
    }
    // --------------------------------------
    if (false == m_strMasterCredID.Compare(strActualMasterCredID))
    {
        OTLog::vOutput(0, "%s: Master Credential ID did not match its "
                       "counterpart in m_Masterkey:\nExpected Master Credential ID: %s\n "
                       "Hash of m_Masterkey contents: %s\nContents:\n%s\n",
                       __FUNCTION__, this->GetMasterCredID().Get(), strActualMasterCredID.Get(),
                       m_Masterkey.GetPubCredential().Get());
        return false;
    }
    // --------------------------------------
    if (false == const_cast<OTMasterkey&>(m_Masterkey).VerifyContract())
    {
        OTLog::vOutput(0, "%s: Master Credential failed to verify: %s\nNymID: %s\n",
                       __FUNCTION__, this->GetMasterCredID().Get(), this->GetNymID().Get());
        return false;
    }
    // -------------------------------------
    FOR_EACH_CONST(mapOfSubcredentials, m_mapSubcredentials)
    {
        std::string str_sub_id = (*it).first;
        OTSubcredential * pSub = (*it).second;
        OT_ASSERT(NULL != pSub);
        // ----------------------
        if (false == pSub->VerifyContract())
        {
            OTLog::vOutput(0, "%s: Subcredential failed to verify: %s\nNymID: %s\n", __FUNCTION__,
                           str_sub_id.c_str(), this->GetNymID().Get());
            return false;
        }
    }
    // -------------------------------------
    return true;
}

// ------------------------------

bool OTCredential::VerifyAgainstSource() const
{
    // * Any OTMasterkey must (at some point, and/or regularly) verify against its own source.
    //
    if (false == m_Masterkey.VerifyAgainstSource())
	{
		OTLog::vOutput(1, "%s: Failed verifying master credential against its own source.\n", __FUNCTION__);
		return false;
	}
    // NOTE: This spot will have a significant delay, TODO OPTIMIZE. Performing a Freenet lookup, or DNS, etc,
    // will introduce delay inside the call VerifyAgainstSource. Therefore in the long term, we must have a
    // separate server process which will verify identities for some specified period of time (specified in
    // their credentials I suppose...) That way, when we call VerifyAgainstSource, we are verifying against
    // some server-signed authorization, based on a lookup that some separate process did within the past
    // X allowed time, such that the lookup is still considered valid (without having to lookup every single
    // time, which is untenable.)
    // -------------------------------------
    return true;
}


// ---------------------------------------
// Should actually curl the URL, or lookup the blockchain value, or verify Cert against
// Cert Authority, etc. Due to the network slowdown of this step, we will eventually make
// a separate identity verification server.
//
bool OTMasterkey::VerifyAgainstSource() const
{
    // RULE: *Any* source except for a public key, will begin with a
    // protocol specifier. Such as:
    //
    // http:        (a normal URL)
    // https:       (a normal URL on https)
    // bitcoin:     (a bitcoin address)
    // namecoin:    (a namecoin address)
    // i2p:         (an i2p address)
    // tor:         (a tor address)
    // freenet:     (a freenet address)
    // cert:        (Subject and Issuer DN from the cert)
    //
    // If NO protocol specifier is found, the source is assumed
    // to be a public key.
    // Public key is the default because that's the original behavior
    // of OT anyway: the public key was hashed to form the NymID. We will
    // continue to support this as a default, but now we are additionally
    // also allowing other sources such as Namecoin, Freenet, etc. As long
    // as a Nym's source hashes to its correct ID, and as long as its master
    // credentials can be verified from that same source, then all master
    // credentials can be verified (as well as subcredentials) from any source
    // the user prefers.
    //
    // ---------------------------------
    bool bVerified = false;
    // ---------------------------------
    const std::string str_raw_source(m_strSourceForNymID.Get());
    std::string str_source;
    
    // It's a URL.
    if (str_raw_source.compare(0,5,"http:")  == 0)
    {
        str_source.insert(str_source.begin(), str_raw_source.begin()+5, str_raw_source.end());
        bVerified = this->VerifySource_HTTP(str_source.c_str());
    }
    else if (str_raw_source.compare(0,6,"https:")  == 0)
    {
        str_source.insert(str_source.begin(), str_raw_source.begin()+6, str_raw_source.end());
        bVerified = this->VerifySource_HTTPS(str_source.c_str());
    }
    // It's a Bitcoin address.
    else if (str_raw_source.compare(0,8,"bitcoin:") == 0)
    {
        str_source.insert(str_source.begin(), str_raw_source.begin()+8, str_raw_source.end());
        bVerified = this->VerifySource_Bitcoin(str_source.c_str());
    }
    // It's a Namecoin address.
    else if (str_raw_source.compare(0,9,"namecoin:") == 0)
    {
        str_source.insert(str_source.begin(), str_raw_source.begin()+9, str_raw_source.end());
        bVerified = this->VerifySource_Namecoin(str_source.c_str());
    }
    // It's a Freenet URL.
    else if (str_raw_source.compare(0,8,"freenet:") == 0)
    {
        str_source.insert(str_source.begin(), str_raw_source.begin()+8, str_raw_source.end());
        bVerified = this->VerifySource_Freenet(str_source.c_str());
    }
    // It's a Tor URL.
    else if (str_raw_source.compare(0,4,"tor:") == 0)
    {
        str_source.insert(str_source.begin(), str_raw_source.begin()+4, str_raw_source.end());
        bVerified = this->VerifySource_TOR(str_source.c_str());
    }
    // It's an I2P URL.
    else if (str_raw_source.compare(0,4,"i2p:") == 0)
    {
        str_source.insert(str_source.begin(), str_raw_source.begin()+4, str_raw_source.end());
        bVerified = this->VerifySource_I2P(str_source.c_str());
    }
    // It's the Issuer/Subject DN info from a cert issued by a traditional certificate authority.
    else if (str_raw_source.compare(0,5,"cert:") == 0)
    {
        str_source.insert(str_source.begin(), str_raw_source.begin()+5, str_raw_source.end());
        bVerified = this->VerifySource_CA(str_source.c_str());
    }
    else // It's presumably a public key.
    {
        str_source = str_raw_source;
        bVerified = this->VerifySource_Pubkey(str_source.c_str());
    }
    // -----------------------------------------------------------------
    return bVerified;
}

bool OTMasterkey::VerifySource_HTTP(const OTString strSource) const
{
    /*
     The source is a URL, http://blah.com/folder
     If I download files from there, will I find my own masterkey inside?
     If so, then I verify.
     */
    
    OTLog::vError("%s: Failure: this function has not yet been written, so this HTTP source cannot be verified.\n",
                  __FUNCTION__);
//    return false;
    
    // Todo security
    OTLog::vError("\nNOTE: Returning TRUE for TESTING PURPOSES, as if HTTP source had verified."
                  "\n\n\n ----------------------- \n\n");

    return true;
}

bool OTMasterkey::VerifySource_HTTPS(const OTString strSource) const
{
    /*
     The source is a URL, https://blah.com/folder
     If I download files from there, will I find my own masterkey inside?
     If so, then I verify.
     */

    OTLog::vError("%s: Failure: this function has not yet been written, so this HTTPS source cannot be verified.\n",
                  __FUNCTION__);
//    return false;

    // Todo security
    OTLog::vError("\nNOTE: Returning TRUE for TESTING PURPOSES, as if HTTPS source had verified."
                  "\n\n\n ----------------------- \n\n");
    
    return true;
}

bool OTMasterkey::VerifySource_Bitcoin(const OTString strSource) const
{
    /*
     The source is a Bitcoin address
     The last transfer from that address should have memo data with the hash of the master credential.
     I compare that to my own ID and they should match.
     Alternately, to support multiple master credentials, have the last transfer go to multiple addresses,
     and each should have a memo with the master cred ID for each credential, one of which should match my own.
     If so, then I verify.
     */

    OTLog::vError("%s: Failure: this function has not yet been written, so this Bitcoin source cannot be verified.\n",
                  __FUNCTION__);
//    return false;

    // Todo security
    OTLog::vError("\nNOTE: Returning TRUE for TESTING PURPOSES, as if Bitcoin had verified."
                  "\n\n\n ----------------------- \n\n");
    
    return true;
}

bool OTMasterkey::VerifySource_Namecoin(const OTString strSource) const
{
    /*
     The source is a URL, http://blah.bit/folder
     If I download files from there, will I find my own masterkey inside?
     If so, then I verify.
     */

    OTLog::vError("%s: Failure: this function has not yet been written, so this Namecoin source cannot be verified.\n",
                  __FUNCTION__);
//    return false;

    // Todo security
    OTLog::vError("\nNOTE: Returning TRUE for TESTING PURPOSES, as if Namecoin had verified."
                  "\n\n\n ----------------------- \n\n");
    
    return true;
}

bool OTMasterkey::VerifySource_Freenet(const OTString strSource) const
{
    OTLog::vError("%s: Failure: this function has not yet been written, so this Freenet source cannot be verified.\n",
                  __FUNCTION__);
    return false;
}

bool OTMasterkey::VerifySource_TOR(const OTString strSource) const
{
    OTLog::vError("%s: Failure: this function has not yet been written, so this Tor source cannot be verified.\n",
                  __FUNCTION__);
    return false;
}

bool OTMasterkey::VerifySource_I2P(const OTString strSource) const
{
    OTLog::vError("%s: Failure: this function has not yet been written, so this I2P source cannot be verified.\n",
                  __FUNCTION__);
    return false;
}

bool OTMasterkey::VerifySource_CA(const OTString strSource) const
{
    
    /*
     The Source is the DN info on the Cert.
     Therefore look at the Cert being used in this Masterkey.
     Does it have the same DN info? Does it verify through its CA ?
     Then it verifies.
     */
    
    OTLog::vError("%s: Failure: this function has not yet been written, so this CA source cannot be verified.\n",
                  __FUNCTION__);
    return false;
}

bool OTMasterkey::VerifySource_Pubkey(const OTString strSource) const
{
    // Verify signed by self.
    //
    // Note: Whenever VerifyAgainstSource is called, VerifyInternally is also called.
    // And VerifyInternally, for all OTKeyCredentials, verifies already that the
    // credential has been signed by its own private signing key.
    // Since the credential is already verified as having signed itself, there's no
    // reason to verify that redundantly here, so we just return true.
    //
    return true;
}

// ***************************************************************************************

// OTLog::vError("%s line %d: \n", __FILE__, __LINE__);


OTKeyCredential::OTKeyCredential()                        : ot_super()         { }
OTKeyCredential::OTKeyCredential(OTCredential & theOwner) : ot_super(theOwner) { }

OTKeyCredential::~OTKeyCredential()
{
    Release_Subkey();
}

//virtual
void OTKeyCredential::Release()
{
    Release_Subkey();   // My own cleanup is done here.
    
    // Next give the base class a chance to do the same...
	ot_super::Release(); // since I've overridden the base class, I call it now...
}
    
void OTKeyCredential::Release_Subkey()
{
    // Release any dynamically allocated members here. (Normally.)
}
// --------------------------------------

bool OTKeyCredential::GenerateKeys(int nBits/*=1024*/)       // Gotta start somewhere.
{
    const bool bSign = m_SigningKey.MakeNewKeypair(nBits);
    const bool bAuth = m_AuthentKey.MakeNewKeypair(nBits);
    const bool bEncr = m_EncryptKey.MakeNewKeypair(nBits);
    // ----------------------------------------------
    OT_ASSERT(bSign && bAuth && bEncr);
    // ----------------------------------------------
    m_SigningKey.SaveAndReloadBothKeysFromTempFile();  // Keys won't be right until this happens.
    m_AuthentKey.SaveAndReloadBothKeysFromTempFile();  // (Necessary evil until better fix.)
    m_EncryptKey.SaveAndReloadBothKeysFromTempFile();
    // ----------------------------------------------
    // Since the keys were all generated successfully, we need to copy their
    // certificate data into the m_mapPublicInfo and m_mapPrivateInfo (string maps.)
    //
    OTString     strPublicKey, strPrivateCert;
    mapOfStrings mapPublic,    mapPrivate;
    // ------------------------------------------
    const OTString strReason("Generating keys for new credential...");
    // ------------------------------------------                
    const bool b1 = m_SigningKey.GetPublicKey(strPublicKey, false); // bEscaped=true by default.
    const bool b2 = m_SigningKey.SaveCertAndPrivateKeyToString(strPrivateCert, &strReason);
    
    if (b1)
        mapPublic. insert(std::pair<std::string, std::string>("S", strPublicKey.Get()));
    if (b2)
        mapPrivate.insert(std::pair<std::string, std::string>("S", strPrivateCert.Get()));
    // ------------------------------------------------------------------------------------------
    strPublicKey.  Release();
    strPrivateCert.Release();
    const bool b3 = m_AuthentKey.GetPublicKey(strPublicKey, false); // bEscaped=true by default.
    const bool b4 = m_AuthentKey.SaveCertAndPrivateKeyToString(strPrivateCert, &strReason);                
    
    if (b3)
        mapPublic. insert(std::pair<std::string, std::string>("A", strPublicKey.Get()));
    if (b4)
        mapPrivate.insert(std::pair<std::string, std::string>("A", strPrivateCert.Get()));
    // ------------------------------------------------------------------------------------------
    strPublicKey.  Release();
    strPrivateCert.Release();
    const bool b5 = m_EncryptKey.GetPublicKey(strPublicKey, false); // bEscaped=true by default.
    const bool b6 = m_EncryptKey.SaveCertAndPrivateKeyToString(strPrivateCert, &strReason);
    
    if (b5)
        mapPublic. insert(std::pair<std::string, std::string>("E", strPublicKey.Get()));
    if (b6)
        mapPrivate.insert(std::pair<std::string, std::string>("E", strPrivateCert.Get()));
    // ------------------------------------------
    if (3 != mapPublic.size())
    {
        OTLog::vError("In %s, line %d: Failed getting public keys in OTKeyCredential::GenerateKeys.\n",
                      __FILE__, __LINE__);
        return false;
    }
    else
        this->ot_super::SetPublicContents(mapPublic);
    // --------------------------------
    if (3 != mapPrivate.size())
    {
        OTLog::vError("In %s, line %d: Failed getting private keys in OTKeyCredential::GenerateKeys.\n",
                      __FILE__, __LINE__);
        return false;
    }
    else
        this->ot_super::SetPrivateContents(mapPrivate);
    // --------------------------------
    return true;
}

// --------------------------------------

//virtual
bool OTKeyCredential::SetPublicContents(const mapOfStrings & mapPublic)
{
    // NOTE: We might use this on the server side, we'll see, but so far on the client
    // side, we won't need to use this function, since SetPrivateContents already does
    // the dirty work of extracting the public keys and setting them.
    //
    // -------------------------------------------------
    if (mapPublic.size() != 3)
    {
        OTLog::vError("%s line %d: Failure: Expected 3 in mapPublic.size(), but the actual value was: %d\n",
                      __FILE__, __LINE__, mapPublic.size());
        return false;
    }
    // -------------------------------------------------
    mapOfStrings::const_iterator iiAuth = mapPublic.find("A");  // Authentication key
    mapOfStrings::const_iterator iiEncr = mapPublic.find("E");  // Encryption key
    mapOfStrings::const_iterator iiSign = mapPublic.find("S");  // Signing key
    // -------------------------------------------------
    if (mapPublic.end() == iiAuth)
    {
        OTLog::vError("%s line %d: Failure: Unable to find public authentication key.\n", __FILE__, __LINE__);
        return false;
    }
    // -------------------------------------------------
    if (mapPublic.end() == iiEncr)
    {
        OTLog::vError("%s line %d: Failure: Unable to find public encryption key.\n", __FILE__, __LINE__);
        return false;
    }
    // -------------------------------------------------
    if (mapPublic.end() == iiSign)
    {
        OTLog::vError("%s line %d: Failure: Unable to find public signing key.\n", __FILE__, __LINE__);
        return false;
    }
    // -------------------------------------------------
    if (this->ot_super::SetPublicContents(mapPublic))
    {
        // -------------------------------------------------
        OTString strKey;
        strKey.Set((*iiAuth).second.c_str());
        if (false == m_AuthentKey.SetPublicKey(strKey))
        {
            OTLog::vError("%s line %d: Failure: Unable to set public authentication key based on string:\n%s\n",
                          __FILE__, __LINE__, strKey.Get());
            return false;
        }
        // -------------------------------------------------
        strKey.Release();
        strKey.Set((*iiEncr).second.c_str());
        if (false == m_EncryptKey.SetPublicKey(strKey))
        {
            OTLog::vError("%s line %d: Failure: Unable to set public encryption key based on string:\n%s\n",
                          __FILE__, __LINE__, strKey.Get());
            return false;
        }
        // -------------------------------------------------
        strKey.Release();
        strKey.Set((*iiSign).second.c_str());
        if (false == m_SigningKey.SetPublicKey(strKey))
        {
            OTLog::vError("%s line %d: Failure: Unable to set public signing key based on string:\n%s\n",
                          __FILE__, __LINE__, strKey.Get());
            return false;
        }
        // -------------------------------------------------
        return true; // SUCCESS! This means the input, mapPublic, actually contained an "A" key, an "E"
        // key, and an "S" key (and nothing else) and that all three of those public keys actually loaded
        // from string form into their respective key object members.
    }
    // -------------------------------------------------
    return false;
}



// -------------------------------------------------
// NOTE: With OTKeyCredential, if you call SetPrivateContents, you don't have to call SetPublicContents,
// since SetPrivateContents will automatically set the public contents, since the public certs are available
// from the private certs. Not all credentials do this, but keys do. So you might ask, why did I still
// provide a version of SetPublicContents for OTKeyCredential? Just to fit the convention, also also because
// perhaps on the server side, public contents will be the only ones available, and private ones will never
// be set.

//virtual
bool OTKeyCredential::SetPrivateContents(const mapOfStrings & mapPrivate,
                                               OTPassword   * pImportPassword/*=NULL*/) // if not NULL, it means to use this password by default.
{
    // -------------------------------------------------
    if (mapPrivate.size() != 3)
    {
        OTLog::vError("%s line %d: Failure: Expected 3 in mapPrivate(), but the actual value was: %d\n",
                      __FILE__, __LINE__, mapPrivate.size());
        return false;
    }
    // -------------------------------------------------
    mapOfStrings::const_iterator iiAuth = mapPrivate.find("A");  // Authentication key
    mapOfStrings::const_iterator iiEncr = mapPrivate.find("E");  // Encryption key
    mapOfStrings::const_iterator iiSign = mapPrivate.find("S");  // Signing key
    // -------------------------------------------------
    if (mapPrivate.end() == iiAuth)
    {
        OTLog::vError("%s line %d: Failure: Unable to find private authentication key.\n", __FILE__, __LINE__);
        return false;
    }
    // -------------------------------------------------
    if (mapPrivate.end() == iiEncr)
    {
        OTLog::vError("%s line %d: Failure: Unable to find private encryption key.\n", __FILE__, __LINE__);
        return false;
    }
    // -------------------------------------------------
    if (mapPrivate.end() == iiSign)
    {
        OTLog::vError("%s line %d: Failure: Unable to find private signing key.\n", __FILE__, __LINE__);
        return false;
    }
    // -------------------------------------------------
    if (this->ot_super::SetPrivateContents(mapPrivate, pImportPassword))
    {
        const OTString strReason("Loading private key from credential.");
        mapOfStrings mapPublic;
        // -------------------------------------------------
        OTString strPrivate;
        strPrivate.Set((*iiAuth).second.c_str()); // strPrivate now contains the private Cert string.
        
        if (false == m_AuthentKey.LoadPrivateKeyFromCertString(strPrivate, false /*bEscaped true by default*/,  &strReason, pImportPassword))
        {
            OTLog::vError("%s line %d: Failure: Unable to set private authentication key based on string.\n",
                          __FILE__, __LINE__);
//          OTLog::vError("%s line %d: Failure: Unable to set private authentication key based on string:\n%s\n",
//                        __FILE__, __LINE__, strPrivate.Get());
            return false;
        }
        else // Success loading the private key. Let's grab the public key here.
        {
            OTString strPublic;

            if ((false == m_AuthentKey.LoadPublicKeyFromCertString(strPrivate, false /* bEscaped true by default */, &strReason, pImportPassword)) ||
                (false == m_AuthentKey.GetPublicKey(strPublic, false /* bEscaped true by default */)))
            {
                OTLog::vError("%s line %d: Failure: Unable to set public authentication key based on private string.\n",
                              __FILE__, __LINE__);
//              OTLog::vError("%s line %d: Failure: Unable to set public authentication key based on private string:\n%s\n",
//                            __FILE__, __LINE__, strPrivate.Get());
                return false;
            }
            mapPublic.insert(std::pair<std::string, std::string>("A", strPublic.Get()));
        }
        // -------------------------------------------------
        strPrivate.Release();
        strPrivate.Set((*iiEncr).second.c_str());
        
        if (false == m_EncryptKey.LoadPrivateKeyFromCertString(strPrivate, false /*bEscaped true by default*/,  &strReason, pImportPassword))
        {
            OTLog::vError("%s line %d: Failure: Unable to set private encryption key based on string.\n",
                          __FILE__, __LINE__);
//          OTLog::vError("%s line %d: Failure: Unable to set private encryption key based on string:\n%s\n",
//                        __FILE__, __LINE__, strPrivate.Get());
            return false;
        }
        else // Success loading the private key. Let's grab the public key here.
        {
            OTString strPublic;
            
            if ((false == m_EncryptKey.LoadPublicKeyFromCertString(strPrivate, false /* bEscaped true by default */, &strReason, pImportPassword)) ||
                (false == m_EncryptKey.GetPublicKey(strPublic, false /* bEscaped true by default */)))
            {
                OTLog::vError("%s line %d: Failure: Unable to set public encryption key based on private string.\n",
                              __FILE__, __LINE__);
//              OTLog::vError("%s line %d: Failure: Unable to set public encryption key based on private string:\n%s\n",
//                            __FILE__, __LINE__, strPrivate.Get());
                return false;
            }
            mapPublic.insert(std::pair<std::string, std::string>("E", strPublic.Get()));
        }
        // -------------------------------------------------
        strPrivate.Release();
        strPrivate.Set((*iiSign).second.c_str());
        
        if (false == m_SigningKey.LoadPrivateKeyFromCertString(strPrivate, false /*bEscaped true by default*/,  &strReason, pImportPassword))
        {
            OTLog::vError("%s line %d: Failure: Unable to set private signing key based on string.\n",
                          __FILE__, __LINE__);
//          OTLog::vError("%s line %d: Failure: Unable to set private signing key based on string:\n%s\n",
//                        __FILE__, __LINE__, strPrivate.Get());
            return false;
        }
        else // Success loading the private key. Let's grab the public key here.
        {
            OTString strPublic;
            
            if ((false == m_SigningKey.LoadPublicKeyFromCertString(strPrivate, false /* bEscaped true by default */, &strReason, pImportPassword)) ||
                (false == m_SigningKey.GetPublicKey(strPublic, false /* bEscaped true by default */)))
            {
                OTLog::vError("%s line %d: Failure: Unable to set public signing key based on private string.\n",
                              __FILE__, __LINE__);
//              OTLog::vError("%s line %d: Failure: Unable to set public signing key based on private string:\n%s\n",
//                            __FILE__, __LINE__, strPrivate.Get());
                return false;
            }
            mapPublic.insert(std::pair<std::string, std::string>("S", strPublic.Get()));
        }
        // -------------------------------------------------
        if (false == this->ot_super::SetPublicContents(mapPublic))
        {
            OTLog::vError("%s line %d: Failure: While trying to call: ot_super::SetPublicContents(mapPublic)\n",
                          __FILE__, __LINE__); // Should never happen (it always just returns true.)
            return false;
        }
        // -------------------------------------------------
        return true; // SUCCESS! This means the input, mapPrivate, actually contained an "A" key, an "E"
        // key, and an "S" key (and nothing else) and that all three of those private keys actually loaded
        // from string form into their respective key object members. We also set the public keys in here, FYI.
    }
    // -------------------------------------------------
    return false;
}


bool OTKeyCredential::SignContract(OTContract & theContract, OTPasswordData * pPWData/*=NULL*/)
{
    return m_SigningKey.SignContract(theContract, pPWData);
}

// ***************************************************************************************

OTSubkey::OTSubkey() : ot_super()
{
    m_strContractType = "KEY CREDENTIAL";
}

OTSubkey::OTSubkey(OTCredential & theOwner) : ot_super(theOwner)
{
    m_strContractType = "KEY CREDENTIAL";    
}

OTSubkey::~OTSubkey() { }

// ------------------------------

OTMasterkey::OTMasterkey() : ot_super()
{
    m_strContractType = "MASTER KEY CREDENTIAL";    
}

OTMasterkey::OTMasterkey(OTCredential & theOwner) : ot_super(theOwner)
{
    m_strContractType = "MASTER KEY CREDENTIAL";    
}

OTMasterkey::~OTMasterkey() { }

// ***************************************************************************************

// Contains a "master" subkey,
// and a list of "sub" subkeys signed by that master.
// Each subkey can generate its own "credential" contract,
// so OTCredential actually may include many "credentials."
// A nym has multiple OTCredentials because there may be
// several master keys.
//

// ------------------------------
const OTString & OTCredential::GetNymID() const
{
    return m_strNymID;
}
// ------------------------------

const OTString & OTCredential::GetSourceForNymID() const
{
    return m_strSourceForNymID;
}
// ------------------------------
/// This sets m_strSourceForNymID.
/// This also sets m_strNymID, which is always a hash of strSourceForNymID.
///
void OTCredential::SetSourceForNymID(const OTString & strSourceForNymID)
{
    // --------------------------------------
    m_strSourceForNymID = strSourceForNymID;
    // --------------------------------------
    //  Now re-calculate the NymID...
    //
    m_strNymID.Release();
    OTIdentifier theTempID;
    const bool bCalculate = theTempID.CalculateDigest(m_strSourceForNymID);
    OT_ASSERT(bCalculate);
    theTempID.GetString(m_strNymID);
    // ------------------------------
    m_Masterkey.SetNymIDandSource(m_strNymID, m_strSourceForNymID); // The key in here must somehow verify against its own source.
    
    // Success! By this point, m_strSourceForNymID and m_strNymID
    // are both set.
}

// ----------------------------------

const OTString & OTCredential::GetPubCredential() const
{
    return m_Masterkey.GetPubCredential();
}

const OTString & OTCredential::GetPriCredential() const
{
    return m_Masterkey.GetPriCredential();
}

bool OTCredential::SetPublicContents(const mapOfStrings & mapPublic)
{
    return m_Masterkey.SetPublicContents(mapPublic);
}

bool OTCredential::SetPrivateContents(const mapOfStrings & mapPrivate)
{
    return m_Masterkey.SetPrivateContents(mapPrivate);
}

// ---------------------------------
//private
OTCredential::OTCredential() :
    m_Masterkey(*this), m_pImportPassword(NULL)
{ }

void OTCredential::SetMasterCredID(const OTString & strID)
{
    m_strMasterCredID = strID;
}

const OTString & OTCredential::GetMasterCredID() const
{
    return m_strMasterCredID;
}
// ---------------------------------------------------------------------------------


//static  (Caller is responsible to delete.)
OTCredential * OTCredential::LoadMaster(const OTString & strNymID, // Caller is responsible to delete, in both CreateMaster and LoadMaster.
                                        const OTString & strMasterCredID,
                                        OTPasswordData * pPWData/*=NULL*/)
{
    OTCredential * pCredential = new OTCredential;
    OTCleanup<OTCredential> theCredentialAngel(pCredential);
    OT_ASSERT(NULL != pCredential);
    // -------------------------------------
    OTPasswordData thePWData("Loading master credential. (static 1.)");
    const bool bLoaded = pCredential->Load_Master(strNymID, strMasterCredID, (NULL == pPWData) ? &thePWData : pPWData);
    if (!bLoaded)
    {
        OTLog::vError("%s: Failed trying to load master credential from local storage. 1\n", __FUNCTION__);
        return NULL;
    }
    // --------------------------------------------------
    theCredentialAngel.SetCleanupTargetPointer(NULL); // so pCredential doesn't get cleaned up.
    return pCredential;
}
// ---------------------------------------------------------------------------------

//static  (Caller is responsible to delete.)
OTCredential * OTCredential::LoadMasterFromString(const OTString & strInput,
                                                  const OTString & strNymID, // Caller is responsible to delete, in both CreateMaster and LoadMaster.
                                                  const OTString & strMasterCredID,
                                                  OTPasswordData * pPWData/*=NULL*/,
                                                  OTPassword     * pImportPassword/*=NULL*/)
{
    OTCredential * pCredential = new OTCredential;
    OTCleanup<OTCredential> theCredentialAngel(pCredential);
    OT_ASSERT(NULL != pCredential);
    // -------------------------------------
    OTPasswordData thePWData(NULL == pImportPassword ? "Enter wallet master passphrase." : "Enter passphrase for exported Nym.");
    const bool bLoaded = pCredential->Load_MasterFromString(strInput, strNymID,
                                                            strMasterCredID,
                                                            (NULL == pPWData) ? &thePWData : pPWData,
                                                            pImportPassword);
    if (!bLoaded)
    {
        OTLog::vError("%s: Failed trying to load master credential from string. 2\n", __FUNCTION__);
        return NULL;
    }
    // --------------------------------------------------
    theCredentialAngel.SetCleanupTargetPointer(NULL); // so pCredential doesn't get cleaned up.
    return pCredential;
}
// ---------------------------------------------------------------------------------

// called by OTCredential::CreateMaster
bool OTCredential::SignNewMaster(OTPasswordData * pPWData/*=NULL*/)
{
    OTPasswordData thePWData("Signing new master credential... OTCredential::SignNewMaster");
    // ------------------------------------
    m_Masterkey.StoreAsPublic(); // So the version we create here only contains public keys, not private.
    const bool bSignedPublic = m_Masterkey.SignContract(m_Masterkey, NULL == pPWData ? &thePWData : pPWData);
    if (bSignedPublic)
    {
        m_Masterkey.SaveContract();
        // ***********************************************************
        // THE OFFICIAL "PUBLIC CREDENTIAL" FOR THE MASTER KEY
        // (Copied from the raw contents here into a member variable for safe-keeping.)
        // Future verifiers can hash it and the output should match the master credential ID.
        //
        OTString strPublicCredential;
        
        if (m_Masterkey.SaveContractRaw(strPublicCredential))
        {
            m_Masterkey.SetContents(strPublicCredential); // <=== The "master public credential" string.
            // ***********************************************************
            // NEW MASTER CREDENTIAL ID.
            //
            // Only now can we calculate the master key's ID, since the ID is a hash of
            // the contents.
            //
            OTIdentifier theNewID;
            m_Masterkey.CalculateContractID(theNewID);
            m_Masterkey.SetIdentifier(theNewID); // Usually this will be set based on an expected value from above, then loaded from storage, and then verified against what was actually loaded (by hashing it.)
            // -------------------------------
            const OTString strMasterCredID(theNewID);
            this->SetMasterCredID(strMasterCredID);  // <=== Master Credential ID is now set.
        }
        else
        {
            OTLog::vError("In %s, line %d: Failed calling m_Masterkey.SaveContractRaw 1.\n",
                          __FILE__, __LINE__);
            return false;
        }
        // **********************************************************
        // THE PRIVATE KEYS
        //
        // Next, we sign / save it again, this time in its private form, and also
        // m_Masterkey.m_strContents and m_strIDsOnly will be contained within that
        // private form along with the private keys.
        //
        m_Masterkey.ReleaseSignatures(); // This time we'll sign it in private mode.
        const bool bSignedPrivate = m_Masterkey.SignContract(m_Masterkey, NULL == pPWData ? &thePWData : pPWData);
        if (bSignedPrivate)
        {
            m_Masterkey.SaveContract();
            // -------------------------------
            m_Masterkey.SetMetadata();
        }
        else
        {
            OTLog::vError("In %s, line %d: Failed trying to sign the master private credential.\n",
                          __FILE__, __LINE__);
            return false;
        }
    }
    else
    {
        OTLog::vError("In %s, line %d: Failed trying to sign the master public credential.\n",
                      __FILE__, __LINE__);
        return false;
    }
    // ------------------------------------
    return true;
}

// ---------------------------------------------------------------------------------

// Overriding from OTContract.
void OTSubcredential::CalculateContractID(OTIdentifier & newID)
{
	if (!newID.CalculateDigest(this->GetPubCredential()))
		OTLog::vError("%s: Error calculating credential digest.\n", __FUNCTION__);
}


// ---------------------------------------------------------------------------------

// Used when importing/exporting a Nym to/from the wallet.
//
bool OTKeypair::ReEncrypt(OTPassword & theExportPassword, bool bImporting, OTString & strOutput)
{
    // --------------------------------------
    OT_ASSERT(NULL != m_pkeyPublic );
    OT_ASSERT(NULL != m_pkeyPrivate);
    // --------------------------------------
    OT_ASSERT(this->HasPublicKey() );
    OT_ASSERT(this->HasPrivateKey());
    // --------------------------------------
    // If we were importing, we were in the exported format but now we're in the internal format.
    // Therefore we want to use the wallet's internal cached master passphrase to save. Therefore
    // strReason will be used for the import case.
    //
    // But if we were exporting, then we were in the internal format and just re-encrypted to the
    // export format. So we'd want to pass the export passphrase when saving.
    //    
    const OTString strReasonAbove(bImporting ?
                                  "Enter the new export passphrase. (Above ReEncryptPrivateKey in OTKeypair::ReEncrypt)" :
                                  "Enter your wallet's master passphrase. (Above ReEncryptPrivateKey in OTKeypair::ReEncrypt)");

    const OTString strReasonBelow(bImporting ?
                                  "Enter your wallet's master passphrase. (Below ReEncryptPrivateKey in OTKeypair::ReEncrypt)" :
                                  "Enter the new export passphrase. (Below ReEncryptPrivateKey in OTKeypair::ReEncrypt)");
    // --------------------------------------
    // At this point the public key was loaded from a public key, not a cert,
    // but the private key was loaded from the cert. Therefore we'll save the
    // public cert from the private key, and then use that to reload the public
    // key after ReEncrypting. (Otherwise the public key would be there, but it
    // would be missing the x509, which is only available in the cert, not the
    // pubkey alone -- and without the x509 being there, the "SaveAndReload" call
    // below would fail.
    // Why don't I just stick the Cert itself into the public data, instead of
    // sticking the public key in there? Because not all key credentials will use
    // certs. Some will use pubkeys from certs, and some will use pubkeys not from
    // certs. But I might still just stick it in there, and code things to be able to
    // load either indiscriminately. After all, that's what I'm doing already in the
    // asset and server contracts. But even in those cases, there will be times when
    // only a pubkey is available, not a cert, so I'll probably still find myself having
    // to do this. Hmm...
    
    // ---------------------------------------
    
    const bool bReEncrypted = m_pkeyPrivate->ReEncryptPrivateKey(theExportPassword, bImporting); // <==== IMPORT or EXPORT occurs here.
          bool bGotCert = false;
    
    if (bReEncrypted)
    {
        // ------------------------------------------------
        // Keys won't be right until this happens. Todo: eliminate this need.
        bGotCert = this->SaveAndReloadBothKeysFromTempFile(&strOutput, &strReasonBelow,
                                                           bImporting ? NULL : &theExportPassword);
    }
    
    const bool bSuccess = (bReEncrypted && bGotCert);
    // --------------------------------------
    if (!bSuccess)
    {
        strOutput.Release();
        OTLog::vError("%s: Failure, either when re-encrypting, or when subsequently retrieving "
                      "the public/private keys. bImporting == %s\n", __FUNCTION__,
                      bImporting ? "true" : "false");
    }
    // --------------------------------------
    return bSuccess;
}

// ---------------------------------------------------------------------------------

bool OTKeyCredential::ReEncryptKeys(OTPassword & theExportPassword, bool bImporting)
{
    OTString strSign, strAuth, strEncr;
    // ----------------------------------------
    const bool bSign = m_SigningKey.ReEncrypt(theExportPassword, bImporting, strSign);
          bool bAuth = false;
          bool bEncr = false;
    // ----------------------------------------    
    if (bSign)
    {
        bAuth = m_AuthentKey.ReEncrypt(theExportPassword, bImporting, strAuth);

        if (bAuth)
            bEncr = m_EncryptKey.ReEncrypt(theExportPassword, bImporting, strEncr);
    }
    // ----------------------------------------
    const bool bSuccessReEncrypting = (bSign && bAuth && bEncr);
          bool bSuccess = false;
    // ----------------------------------------
    // If success, we now have the updated versions of the private certs.
    // 
    if (bSuccessReEncrypting)
    {
        mapOfStrings mapPrivate;        
        // ----------------------------------------
        FOR_EACH(mapOfStrings, m_mapPrivateInfo)
        {
            std::string  str_key_type     = (*it).first;   // A, E, S.
            std::string  str_key_contents = (*it).second;
            // ----------------------------------------
            if ("A" == str_key_type)
            {
                mapPrivate.insert(std::pair<std::string, std::string>("A", strAuth.Get()));
            }
            else if ("E" == str_key_type)
                mapPrivate.insert(std::pair<std::string, std::string>("E", strEncr.Get()));
            else if ("S" == str_key_type)
                mapPrivate.insert(std::pair<std::string, std::string>("S", strSign.Get()));
            // ----------------------------------------
            else // Should never happen, but if there are other keys here, we'll preserve 'em.
            {
                mapPrivate.insert(std::pair<std::string, std::string>(str_key_type, str_key_contents));
                OT_FAIL; // really this should never happen.
            }
        }
        // ----------------------------------------
        if (3 != mapPrivate.size())
            OTLog::vError("%s: Unexpected, mapPrivate does not have exactly a size of 3. \n", __FUNCTION__);
        // ----------------------------------------
        else
        {
            // Logic: If I'm IMPORTING, bImporting is true, and that means the Nym WAS
            // encrypted to its own external passphrase (whenever it was exported) and
            // in order to IMPORT it, I re-encrypted all the keys from the exported passphrase,
            // to the wallet master key (this was done above in ReEncrypt.)
            // So now that I am loading up the private contents again based on those
            // re-encrypted keys, I will want to use the normal wallet master key to load
            // them. (So I pass NULL.)
            //
            // But if I'm EXPORTING, bImporting is false, and that means the Nym WAS
            // encrypted to the wallet's master passphrase, until just above when I ReEncrypted
            // it to its own external passphrase. So now that I am attempting to reload the
            // keys based on this new external passphrase, I need to pass it in so it can be
            // used for that loading. (So I pass &theExportPassword.)
            //
            bSuccess = this->SetPrivateContents(mapPrivate, bImporting ? NULL : &theExportPassword);
        }
    }
    // ----------------------------------------
    return bSuccess; // Note: Caller must re-sign credential after doing this, to keep these changes.
}


// ---------------------------------------------------------------------------------
// When exporting a Nym, you don't want his private keys encrypted to the cached key
// for the wallet, so you have to load them up, and then pause OTCachedKey, and then
// save them to string again, re-encrypting them to the export passphrase (and not to
// any "master key" from the wallet.) And you have to release all the signatures on
// the private credentials, since the private info is being re-encrypted, and re-sign
// them all. Joy. 
//
bool OTCredential::ReEncryptPrivateCredentials(OTPassword & theExportPassword, bool bImporting)
{
    if (m_Masterkey.GetPrivateMap().size() > 0)
    {
        OTPasswordData thePWData(bImporting ?
                                 "2 Enter passphrase for the Nym being imported." :
                                 "2 Enter new passphrase for exported Nym.");
        // -------------------------------
        // Re-encrypt the private keys in the masterkey. (THEN sign.)
        //
        const bool bReEncryptMaster = m_Masterkey.ReEncryptKeys(theExportPassword, bImporting);
              bool bSignedMaster    = false;
        
        if (bReEncryptMaster)
        {
            m_Masterkey.ReleaseSignatures(); // This time we'll sign it in private mode.
            bSignedMaster = m_Masterkey.SignContract(m_Masterkey, &thePWData);
        }
        else
        {
            OTLog::vError("In %s, line %d: Failed trying to re-encrypt the private masterkey.\n",
                          __FILE__, __LINE__);
            return false;
        }
        // ---------------------------
        if (bSignedMaster)
        {
            m_Masterkey.SaveContract();
            m_Masterkey.SetMetadata (); // todo: can probably remove this, since it was set based on public info when the key was first created.
            // -------------------------------
            FOR_EACH(mapOfSubcredentials, m_mapSubcredentials)
            {
                const std::string str_cred_id = (*it).first;
                      OTSubcredential * pSub  = (*it).second;
                OT_ASSERT(NULL != pSub);
                // ------------------------
                OTSubkey * pKey = dynamic_cast<OTSubkey *>(pSub);
                if (NULL == pKey) continue;
                // ------------------------
                const bool bReEncryptSubkey = pKey->ReEncryptKeys(theExportPassword, bImporting);
                      bool bSignedSubkey    = false;

                if (bReEncryptSubkey)
                {
                    pKey->ReleaseSignatures();
                    bSignedSubkey = pKey->SignContract(*pKey, &thePWData);
                }
                else
                {
                    OTLog::vError("In %s, line %d: Failed trying to re-encrypt the private subkey.\n",
                                  __FILE__, __LINE__);
                    return false;
                }
                // ---------------------
                if (bSignedSubkey)
                {
                    pKey->SaveContract();
                    pKey->SetMetadata (); // todo: can probably remove this, since it was set based on public info when the key was first created.
                }
                else
                {
                    OTLog::vError("In %s, line %d: Failed trying to re-sign the private subkey.\n",
                                  __FILE__, __LINE__);
                    return false;
                }
            } // FOR_EACH
            // -------------------------------
            return true; // <=== Success.
        }
        else
            OTLog::vError("In %s, line %d: Failed trying to re-sign the master private credential.\n",
                          __FILE__, __LINE__);
    }
    else
        OTLog::vError("In %s, line %d: Failed: There is no private info on this master credential.\n",
                      __FILE__, __LINE__);

    return false;
}

// -------------------------------------------------------------------------------

bool OTCredential::SignNewSubcredential(OTSubcredential & theSubCred, OTIdentifier & theSubCredID_out, OTPasswordData * pPWData/*=NULL*/)
{
    OTPasswordData thePWData("Signing new subcredential... OTCredential::SignNewSubcredential");
    // ------------------------------------
    // First, we store the subcredential itself with its basic info.
    // This version is signed with the Masterkey. Then we save a copy of it
    // in a member variable for safe-keeping, m_strMasterSigned. Next, we
    // save a "public" version of the subcredential (the official version)
    // which will include m_strMasterSigned inside it, and be signed by the
    // subkey. This version may not need to duplicate all that data, especially
    // if we end up just having to verify it twice as a result. So I might have
    // the public version be sparse (other than including the master signed version,
    // and being signed by the subkey.)
    // Though with many subcredentials, there will ONLY be the master-signed version,
    // and that WILL be the public version. Only with subkeys will that be different!
    //
    OTSubkey * pSubkey   = dynamic_cast<OTSubkey *>(&theSubCred);
    const bool bIsSubkey = (NULL != pSubkey); // It's not just any subcredential -- it's a subkey!
    // --------------------------------------------------------------
	// If it's not a subkey, but rather, a normal subcredential with no keys, then it doesn't need to contain a "master signed" version,
	// since the entire subcredential will already be master signed, since there's no subkey to sign in that case.
    if (!bIsSubkey) 
        theSubCred.SetMasterSigned(OTString("")); 
    // ------------------------
    // ELSE It's a subkey...
    else // Subkeys must be self-signed, and must contain a master-signed version of themselves where the data is actually stored.
    {
        // ***********************************************************
        pSubkey->StoreAsMasterSigned(); // So the version we create here only contains public keys, not private. (And so it won't include
                                        // the "master signed" version in what it stores, since that's what we're creating now.)

        const bool bMasterSigned = m_Masterkey.SignContract(*pSubkey, NULL == pPWData ? &thePWData : pPWData);
        if (!bMasterSigned)
        {
            OTLog::vError("In %s, line %d: Failed calling m_Masterkey.SignContract(*pSubkey) after StoreAsMasterSigned.\n",
                          __FILE__, __LINE__);
            return false;
        }
        else
        {
            pSubkey->SaveContract();
            // ------------------------------------
            // Make a copy of the "master signed" version of the public subcredential.
            //
            OTString strMasterSigned;
            
            if (pSubkey->SaveContractRaw(strMasterSigned)) // <=== The "master signed" version of the "public credential" string. Captured here
                pSubkey->SetMasterSigned(strMasterSigned); // so that the (subkey-signed) public version of the subcredential will contain it.
            else
            {
                OTLog::vError("In %s, line %d: Failed calling pSubkey->SaveContractRaw 1.\n",
                              __FILE__, __LINE__);
                return false;
            }
        }
        // --------------------------
        pSubkey->ReleaseSignatures();
    }
    // ***********************************************************
    theSubCred.StoreAsPublic(); // So the version we create here only contains public keys, not private.
    
    // Here, dynamic cast theSubCred to a subkey and if successful, use it to sign itself.
    // Otherwise, sign it with the master. (If it's a real subkey, then it will contain the
    // master-signed version, and it will be signed with itself, its own subkey. Whereas if
    // it's a subcredential that is NOT a subkey, such as a Google Authenticator or some other
    // 3rd-party authentication, then it will HAVE no key to sign itself with, since its primary
    // purpose in that case is to provide some OTHER authentication info INSTEAD of a key.
    // So in that case, it must be signed by the master.)
    //
    bool bSignedPublic = false;
    
    if (bIsSubkey) // If it's a subkey, its keys are already generated by the time we got here. So use it to sign its own public version.
        bSignedPublic = pSubkey->   SignContract(theSubCred, NULL == pPWData ? &thePWData : pPWData);
    else // It's not a subkey, but some other conventional subcredential. So we sign with master key, since that's all we've got.
        bSignedPublic = m_Masterkey.SignContract(theSubCred, NULL == pPWData ? &thePWData : pPWData);
    // -----------------
    if (!bSignedPublic)
    {
        OTLog::vError("In %s, line %d: Failed trying to sign the public subcredential or subkey.\n",
                      __FILE__, __LINE__);
        return false;
    }
    else
    {
        theSubCred.SaveContract();
        // ***********************************************************
        // THE OFFICIAL "PUBLIC CREDENTIAL STRING" FOR THIS NEW SUB-CREDENTIAL
        // Set it aside for safe-keeping as the official contents, hashable to form
        // the ID for this sub-credential.
        //
        OTString strPublicCredential;
        if (theSubCred.SaveContractRaw(strPublicCredential))
        {
            theSubCred.SetContents(strPublicCredential); // <=== The "public credential" string aka the contents.
            // ***********************************************************
            // NEW SUB-CREDENTIAL ID.
            //
            // Only now that the contents have been set, can we calculate the ID, which
            // is a hash of those contents. (Credential ID is a hash of GetPubCredential instead
            // of m_strRawXML as most contracts would use, since we only want to use the PUBLIC
            // info for calculating the ID, not the private info.)
            //
            theSubCred.CalculateContractID(theSubCredID_out);
            theSubCred.SetIdentifier(theSubCredID_out);
        }
        else
        {
            OTLog::vError("In %s, line %d: Failed calling theSubCred.SaveContractRaw.\n",
                          __FILE__, __LINE__);
            return false;
        }
        // **********************************************************
        // CREATE THE PRIVATE FORM.
        //
        // Next, we sign / save it again, this time in its private form, and also
        // theSubCred.m_strContents will be contained within that private form,
        // along with the private keys.
        //
        theSubCred.ReleaseSignatures(); // This time we'll sign it in private mode.
        bool bSignedPrivate = false;
        
        if (bIsSubkey) // If it's a subkey, its keys are already generated by the time we got here. So use it to sign its own private version.
            bSignedPrivate = pSubkey->   SignContract(theSubCred, NULL == pPWData ? &thePWData : pPWData);
        else // It's not a subkey, but some other conventional subcredential. So we sign the private info with the master key, since that's all we've got.
            bSignedPrivate = m_Masterkey.SignContract(theSubCred, NULL == pPWData ? &thePWData : pPWData);
        
        if (bSignedPrivate)
            theSubCred.SaveContract();
        else
        {
            OTLog::vError("In %s, line %d: Failed trying to sign the private subcredential.\n",
                          __FILE__, __LINE__);
            return false;
        }
    }
    // ------------------------------------
    return true;
}

// ---------------------------------------------------------------------------------

bool OTCredential::GenerateMasterkey(int nBits/*=1024*/) // CreateMaster is able to create keys from scratch (by calling this function.)
{
    return m_Masterkey.GenerateKeys(nBits);
}
// ---------------------------------------------------------------------------------

bool OTCredential::Load_MasterFromString(const OTString & strInput,
                                         const OTString & strNymID,
                                         const OTString & strMasterCredID,
                                         OTPasswordData * pPWData/*=NULL*/,
                                         OTPassword     * pImportPassword/*=NULL*/)
{
    m_strNymID          = strNymID;
    m_strMasterCredID   = strMasterCredID;
    // --------------------------------------
    m_Masterkey.SetIdentifier(strMasterCredID);
    // --------------------------------------
    // m_Masterkey and the subkeys all have a pointer to "owner" (who is *this)
    // and so I can set pImportPassword onto a member variable, perform the load,
    // and then set that member NULL again. During the call to LoadContractFromString,
    // m_Masterkey can reference m_pOwner->GetImportPassword() and if it's not NULL,
    // use it instead of using the wallet's cached master key. After all, if it's not
    // NULL here, that's why it was passed in.
    //
    // --------------------------------------
    
    this->SetImportPassword(pImportPassword); // might be NULL.
    
    // --------------------------------------
    const bool bLoaded = m_Masterkey.LoadContractFromString(strInput);
    if (!bLoaded)
    {
        OTLog::vError("%s: Failed trying to load master credential from string.\n", __FUNCTION__);
        return false;
    }
    // --------------------------------------

    this->SetImportPassword(NULL); // It was only set during the m_Masterkey.LoadContractFromString (which references it.)
    
    // --------------------------------------
    m_strNymID          = m_Masterkey.GetNymID();
    m_strSourceForNymID = m_Masterkey.GetNymIDSource();
    // --------------------------------------
    this->ClearSubcredentials();  // The master is loaded first, and then any subcredentials. So this is probably already empty. Just looking ahead.
    // --------------------------------------
    m_Masterkey.SetMetadata();
    // --------------------------------------------------
    return true;
}
// ---------------------------------------------------------------------------------



bool OTCredential::Load_Master(const OTString & strNymID,
                               const OTString & strMasterCredID,
                               OTPasswordData * pPWData/*=NULL*/)
{
    // --------------------------------------
    std::string str_Folder = OTFolders::Credential().Get(); // Try private credential first. If that fails, then public.
    // --------------------------------------
    if (false == OTDB::Exists(str_Folder, strNymID.Get(), strMasterCredID.Get()))
    {
        str_Folder = OTFolders::Pubcred().Get();
        
        if (false == OTDB::Exists(str_Folder, strNymID.Get(), strMasterCredID.Get()))
        {
            OTLog::vError("%s: Failure: Master Credential %s doesn't exist for Nym %s\n",
                          __FUNCTION__, strMasterCredID.Get(), strNymID.Get());
            return false;
        }
    }
    // ----------------------------------------------------
    OTString strFileContents(OTDB::QueryPlainString(str_Folder,
                                                    strNymID.Get(),
                                                    strMasterCredID.Get()));
    if (!strFileContents.Exists())
    {
        OTLog::vError("%s: Failed trying to load master credential from local storage.\n", __FUNCTION__);
        return false;
    }
    // ---------------------------------------    
    if (false == strFileContents.DecodeIfArmored()) // bEscapedIsAllowed=true by default.
    {
        OTLog::vError("%s: File contents apparently were encoded and then failed decoding. Contents: \n%s\n",
                      __FUNCTION__, strFileContents.Get());
        return false;
    }
    // --------------------------------------------------
    return this->Load_MasterFromString(strFileContents, strNymID, strMasterCredID, pPWData);
}
// ---------------------------------------------------------------------------------

void OTKeyCredential::SetMetadata()
{
    bool bMetadata         = false;
	char cMetaKeyType;            // Can be A, E, or S (authentication, encryption, or signing. Also, E would be unusual.)
	char cMetaNymID        = '0'; // Can be any letter from base62 alphabet. Represents first letter of a Nym's ID.
	char cMetaMasterCredID = '0'; // Can be any letter from base62 alphabet. Represents first letter of a Master Credential ID (for that Nym.)
	char cMetaSubCredID    = '0'; // Can be any letter from base62 alphabet. Represents first letter of a SubCredential ID (signed by that Master.)
    // ----------------------------------------------------
    OTString strSubcredID;
    this->GetIdentifier(strSubcredID);
    // ----------------------------------------------------
    const bool bNymID  = this->GetNymID()           .At(0, cMetaNymID);
    const bool bCredID = m_pOwner->GetMasterCredID().At(0, cMetaMasterCredID);
    const bool bSubID  = strSubcredID               .At(0, cMetaSubCredID); // In the case of the master credential, this will repeat the previous one.

	if (!bNymID || !bCredID || !bSubID)
	{
		OTLog::vOutput(1,"%s: No metadata available:\n %s is %s, %s is %s, %s is %s", __FUNCTION__,
			"bNymID", bNymID ? "True": "False",
			"bCredID",bNymID ? "True": "False",
			"bSubID", bNymID ? "True": "False");
	}

    // ----------------------------------------------------
    OTSignatureMetadata theMetadata;
    // ----------------------------------------------------
    cMetaKeyType   = 'A';
    bMetadata = theMetadata.SetMetadata(cMetaKeyType, cMetaNymID, cMetaMasterCredID, cMetaSubCredID);
    m_AuthentKey.SetMetadata(theMetadata);
    // ----------------------------------------------------
    cMetaKeyType   = 'E';
    bMetadata = theMetadata.SetMetadata(cMetaKeyType, cMetaNymID, cMetaMasterCredID, cMetaSubCredID);
    m_EncryptKey.SetMetadata(theMetadata);
    // ----------------------------------------------------
    cMetaKeyType   = 'S';
    bMetadata = theMetadata.SetMetadata(cMetaKeyType, cMetaNymID, cMetaMasterCredID, cMetaSubCredID);
    m_SigningKey.SetMetadata(theMetadata);
    // ----------------------------------------------------
}

// ---------------------------------------------------------------------------------

bool OTCredential::LoadSubkeyFromString(const OTString & strInput, const OTString & strSubID, OTPassword * pImportPassword/*=NULL*/)
{
    // Make sure it's not already there.
    //
    mapOfSubcredentials::iterator it = m_mapSubcredentials.find(strSubID.Get());
    if (it != m_mapSubcredentials.end()) // It was already there. (Reload it.)
    {
        OTLog::vError("%s: Warning: Deleting and re-loading keyCredential that was already loaded.\n",
                      __FUNCTION__);
        OTSubcredential * pSub = (*it).second;
        OT_ASSERT(NULL != pSub);
        delete pSub;
        m_mapSubcredentials.erase(it);
    }
    // -------------------------------------
    OTSubkey * pSub = new OTSubkey(*this);
    OTCleanup<OTSubkey> theSubAngel(pSub);
    OT_ASSERT(NULL != pSub);
    // ----------------------
    pSub->SetIdentifier(strSubID);
    pSub->SetNymIDandSource(this->GetNymID(), this->GetSourceForNymID()); // Set NymID and source string that hashes to it.
    pSub->SetMasterCredID  (this->GetMasterCredID());         // Set master credential ID (onto this new subcredential...)
    // --------------------------------------
    
    this->SetImportPassword(pImportPassword); // might be NULL.

    // --------------------------------------
    if (false == pSub->LoadContractFromString(strInput))
    {
        OTLog::vError("%s: Failed trying to load keyCredential from string.\n", __FUNCTION__);
        return false;
    }
    // --------------------------------------
    
    this->SetImportPassword(NULL); // Only set long enough for LoadContractFromString above to use it.
    
    // --------------------------------------
    pSub->SetMetadata();
    // -------------------------------------
    m_mapSubcredentials.insert(std::pair<std::string, OTSubcredential *>(strSubID.Get(), pSub));
    theSubAngel.SetCleanupTargetPointer(NULL);
    return true;
}
// ---------------------------------------------------------------------------------

bool OTCredential::LoadSubkey(const OTString & strSubID)
{
    // --------------------------------------
    std::string str_Folder = OTFolders::Credential().Get(); // Try private credential first. If that fails, then public.
    // --------------------------------------
    if (false == OTDB::Exists(str_Folder, this->GetNymID().Get(), strSubID.Get()))
    {
        str_Folder = OTFolders::Pubcred().Get();
        
        if (false == OTDB::Exists(str_Folder, this->GetNymID().Get(), strSubID.Get()))
        {
            OTLog::vError("%s: Failure: Key Credential %s doesn't exist for Nym %s\n",
                          __FUNCTION__, strSubID.Get(), this->GetNymID().Get());
            return false;
        }
    }
    // ----------------------------------------------------    
    OTString strFileContents(OTDB::QueryPlainString(str_Folder,
                                                    this->GetNymID().Get(),
                                                    strSubID.Get()));
    
    if (false == strFileContents.Exists())
    {
        OTLog::vError("%s: Failed trying to load keyCredential from local storage.\n", __FUNCTION__);
        return false;
    }
    // ---------------------------------------
    if (false == strFileContents.DecodeIfArmored()) // bEscapedIsAllowed=true by default.
    {
        OTLog::vError("%s: File contents apparently were encoded and then failed decoding. Contents: \n%s\n",
                      __FUNCTION__, strFileContents.Get());
        return false;
    }
    // --------------------------------------------------
    return this->LoadSubkeyFromString(strFileContents, strSubID);
}
// ---------------------------------------------------------------------------------

bool OTCredential::LoadSubcredentialFromString(const OTString & strInput, const OTString & strSubID, OTPassword * pImportPassword/*=NULL*/)
{
    // Make sure it's not already there.
    //
    mapOfSubcredentials::iterator it = m_mapSubcredentials.find(strSubID.Get());
    if (it != m_mapSubcredentials.end()) // It was already there. (Reload it.)
    {
        OTLog::vError("%s: Warning: Deleting and re-loading subCredential that was already loaded.\n", __FUNCTION__);
        OTSubcredential * pSub = (*it).second;
        OT_ASSERT(NULL != pSub);
        delete pSub;
        m_mapSubcredentials.erase(it);
    }
    // -------------------------------------
    OTSubcredential * pSub = new OTSubcredential(*this);
    OTCleanup<OTSubcredential> theSubAngel(pSub);
    OT_ASSERT(NULL != pSub);
    // ----------------------
    pSub->SetIdentifier(strSubID);
    pSub->SetNymIDandSource(this->GetNymID(), this->GetSourceForNymID()); // Set NymID and source string that hashes to it.
    pSub->SetMasterCredID  (this->GetMasterCredID());         // Set master credential ID (onto this new subcredential...)
    // --------------------------------------
    
    this->SetImportPassword(pImportPassword); // might be NULL.
    
    // --------------------------------------
    if (false == pSub->LoadContractFromString(strInput))
    {
        OTLog::vError("%s: Failed trying to load subCredential from string.\n", __FUNCTION__);
        return false;
    }
    // --------------------------------------
    
    this->SetImportPassword(NULL); // This is only set long enough for LoadContractFromString to use it. (Then back to NULL.)
    
    // --------------------------------------
    m_mapSubcredentials.insert(std::pair<std::string, OTSubcredential *>(strSubID.Get(), pSub));
    theSubAngel.SetCleanupTargetPointer(NULL);
    return true;
}

bool OTCredential::LoadSubcredential(const OTString & strSubID)
{
    // --------------------------------------
    std::string str_Folder = OTFolders::Credential().Get(); // Try private credential first. If that fails, then public.
    // --------------------------------------
    if (false == OTDB::Exists(str_Folder, this->GetNymID().Get(), strSubID.Get()))
    {
        str_Folder = OTFolders::Pubcred().Get();
        
        if (false == OTDB::Exists(str_Folder, this->GetNymID().Get(), strSubID.Get()))
        {
            OTLog::vError("%s: Failure: Credential %s doesn't exist for Nym %s\n",
                          __FUNCTION__, strSubID.Get(), this->GetNymID().Get());
            return false;
        }
    }
    // ----------------------------------------------------
    OTString strFileContents(OTDB::QueryPlainString(str_Folder,
                                                    this->GetNymID().Get(),
                                                    strSubID.Get()));
    if (!strFileContents.Exists())
    {
        OTLog::vError("%s: Failed trying to load subCredential from local storage.\n", __FUNCTION__);
        return false;
    }
    // ---------------------------------------
    if (false == strFileContents.DecodeIfArmored()) // bEscapedIsAllowed=true by default.
    {
        OTLog::vError("%s: File contents apparently were encoded and then failed decoding. Contents: \n%s\n",
                      __FUNCTION__, strFileContents.Get());
        return false;
    }
    // --------------------------------------------------
    return this->LoadSubcredentialFromString(strFileContents, strSubID);
}

// ---------------------------------------------------------------------------------
// For adding subcredentials that are specifically *subkeys*. Meaning it will
// contain 3 keypairs: signing, authentication, and encryption.
//
bool OTCredential::AddNewSubkey(const int            nBits       /*=1024*/, // Ignored unless pmapPrivate is NULL
                                const mapOfStrings * pmapPrivate /*=NULL*/, // Public keys are derived from the private.
                                    OTPasswordData * pPWData     /*=NULL*/, // The master key will sign the subkey.
                                    OTSubkey      ** ppSubkey    /*=NULL*/) // output
{
    OTSubkey * pSub = new OTSubkey(*this);
    OT_ASSERT(NULL != pSub);
    // ----------------------
    pSub->SetNymIDandSource(this->GetNymID(), this->GetSourceForNymID()); // Set NymID and source string that hashes to it.
    pSub->SetMasterCredID  (this->GetMasterCredID());         // Set master credential ID (onto this new subcredential...)
    // -------------------------------------
    // If a map of private certs was not passed in, we're expected to
    // generate the keys ourselves.
    //
    bool bContentsReady = false;

    if (NULL != pmapPrivate) // Pre-generated keys were passed in for us to use,
        bContentsReady = pSub->SetPrivateContents(*pmapPrivate); // so let's set them onto the sub key.
    else
        // No keys were provided, so let's generate them ourselves...
        bContentsReady = pSub->GenerateKeys(nBits);
    // -------------------------------------
    if (!bContentsReady)
    {
        OTLog::vError("In %s, line %d: Failed trying to SetPrivateContents or GenerateKeys\n",
                      __FILE__, __LINE__);
        delete pSub; pSub = NULL;
        return false;
    }
    // -------------------------------------
    else // By this point we've set up the subkey with its NymID, the source string for that NymID,
    {    // my master credential ID, and the public and private certs for the subkey. Now let's
         // sign it...
        OTPasswordData thePWData("Signing new subkey... OTCredential::AddNewSubkey");
        OTIdentifier   theSubCredID;
        
        // SignNewSubcredential uses m_Masterkey's actual signing key to sign "pSub the contract."
        //
        if (false == this->SignNewSubcredential(*pSub, theSubCredID, NULL == pPWData ? &thePWData : pPWData))
        {
            OTLog::vError("In %s, line %d: Failed trying to call this->SignNewSubcredential\n",
                          __FILE__, __LINE__);
            delete pSub; pSub = NULL;
            return false;
        }
        // ---------------------------------------------
        const OTString strSubCredID(theSubCredID); // SignNewSubcredential also generates the ID.
        // --------------------------------------
        pSub->SetMetadata();
        // -------------------------------------
        // ADD IT TO THE MAP
        // Only after pSub is signed and saved can we then calculate its ID and use that ID
        // as the key in m_mapSubcredentials (with pSub being the value.)
        //
        m_mapSubcredentials.insert(std::pair<std::string, OTSubcredential *>(strSubCredID.Get(), pSub));

        if (NULL != ppSubkey) // output
        {
            *ppSubkey = pSub;
        }
        
        return true;
    }
}

// --------------------------------------------------------------------------
// For adding non-key credentials, such as for 3rd-party authentication.
//
bool OTCredential::AddNewSubcredential(const mapOfStrings & mapPrivate,
                                       const mapOfStrings & mapPublic,
                                       OTPasswordData  *  pPWData/*=NULL*/, // The master key will sign the subcredential.
                                       OTSubcredential ** ppSubcred/*=NULL*/) // output
{
    OTSubcredential * pSub = new OTSubcredential(*this);
    OT_ASSERT(NULL != pSub);
    // ----------------------
    pSub->SetNymIDandSource(m_strNymID, m_strSourceForNymID); // Set NymID and source string that hashes to it.
    pSub->SetMasterCredID  (this->GetMasterCredID());         // Set master credential ID (onto this new subcredential...)
    // -------------------------------------
    if (false == pSub->SetPublicContents(mapPublic))
    {
        OTLog::vError("In %s, line %d: Failed while calling pSub->SetPublicContents.\n",
                      __FILE__, __LINE__);
        delete pSub; pSub = NULL;
        return false;
    }
    // -------------------------------------
    else if (false == pSub->SetPrivateContents(mapPrivate))
    {
        OTLog::vError("In %s, line %d: Failed while trying to pSub->SetPrivateContents.\n",
                      __FILE__, __LINE__);
        delete pSub; pSub = NULL;
        return false;
    }
    // -------------------------------------
    else // By this point we've set up the subcredential with its NymID, the source string for that NymID,
    {    // my master credential ID, and the public and private contents for the subcredential. Let's sign
         // it...
        OTPasswordData thePWData("Signing new subcredential... OTCredential::AddNewSubcredential");
        OTIdentifier   theSubCredID;
        
        // SignNewSubcredential uses m_Masterkey's actual signing key to sign "pSub the contract."
        //
        if (false == this->SignNewSubcredential(*pSub, theSubCredID, NULL == pPWData ? &thePWData : pPWData))
        {
            OTLog::vError("In %s, line %d: Failed trying to call this->SignNewSubcredential\n",
                          __FILE__, __LINE__);
            delete pSub; pSub = NULL;
            return false;
        }
        // ---------------------------------------------
        const OTString strSubCredID(theSubCredID);
        // -------------------------------
        // ADD IT TO THE MAP
        // Only after pSub is signed and saved can we then calculate its ID and use that ID
        // as the key in m_mapSubcredentials (with pSub being the value.)
        //
        m_mapSubcredentials.insert(std::pair<std::string, OTSubcredential *>(strSubCredID.Get(), pSub));
        if (NULL != ppSubcred) // output
            *ppSubcred = pSub;
        return true;
    }
}

// ---------------------------------------------------------------------------------
// After calling this, you still need to save it to disk (or not.) This function alone
// doesn't save anything to disk.
//
//static
OTCredential * OTCredential::CreateMaster(const OTString     & strSourceForNymID,
                                          const int            nBits/*=1024*/,       // Ignored unless pmapPrivate is NULL.
                                          const mapOfStrings * pmapPrivate/*=NULL*/, // If NULL, then the keys are generated in here.
                                          const mapOfStrings * pmapPublic /*=NULL*/, // In the case of key credentials, public is optional since it can already be derived from private. But not all credentials are keys...
                                          OTPasswordData * pPWData/*=NULL*/)
{
    OTCredential * pCredential = new OTCredential;
    OT_ASSERT(NULL != pCredential);
    // -------------------------------------
    pCredential->SetSourceForNymID(strSourceForNymID); // This also recalculates and sets  ** m_strNymID **
    // -------------------------------------
    // OTKeyCredential::SetPrivateContents will already set the public keys, which is why this argument is optional. But not all credentials are keys, so we must still retain the ability to explicitly set the public info. Even so, in the case of keys, private is below, so it will overwrite this.
    
    if ((NULL != pmapPublic) &&
        (NULL != pmapPrivate)) // You cannot pass public info in here unless you also pass private info.
    {
        if (false == pCredential->SetPublicContents(*pmapPublic))
        {
            OTLog::vError("In %s, line %d: Failed trying to call pCredential->SetPublicContents\n",
                          __FILE__, __LINE__);
            delete pCredential;
            pCredential = NULL;
            return NULL;
        }
    }
    // -------------------------------------
    // Private info must be passed in to create a credential. This saves a copy of the map, and for keys also loads the map all up into the OTKeypair objects (in the case of OTKeyCredentials anyway -- not all credentials are keys.)
    //
    bool bContentsReady = false;
    
    if (NULL != pmapPrivate) // Pre-generated keys were passed in for us to use.
        bContentsReady = pCredential->SetPrivateContents(*pmapPrivate); // So let's set them onto the master key.
    else
        // No keys were provided, so let's generate them ourselves...
        bContentsReady = pCredential->GenerateMasterkey(nBits);
    // -------------------------------------
    if (!bContentsReady)
    {
        OTLog::vError("In %s, line %d: Failed trying to SetPrivateContents or GenerateMasterkey\n",
                      __FILE__, __LINE__);
        delete pCredential;
        pCredential = NULL;
        return NULL;
    }
    else
    {
        OTPasswordData thePWData("Signing new master credential... OTCredential::CreateMaster");
        
        // Using m_Masterkey's actual signing key to sign "m_Masterkey the contract."
        //
        if (false == pCredential->SignNewMaster(NULL == pPWData ? &thePWData : pPWData))
        {
            OTLog::vError("In %s, line %d: Failed trying to call pCredential->SignNewMaster\n",
                          __FILE__, __LINE__);
            delete pCredential;
            pCredential = NULL;
            return NULL;
        }
    }
    
    // By this point, we have instantiated a new OTCredential, set the source string, hashed that
    // source string to get the NymID for this credential, and set the public and private info for
    // this credential (each a map of strings.) Since pCredential->m_Masterkey is derived from
    // OTKeyCredential, it also loaded up the 3 keypairs (authentication, encryption, and signing.)
    // Then we signed that master key with itself, with its signing key. (It's also an OTContract,
    // so it can be signed.) This also calculated the new master credential ID, and called
    // pCredential->SetMasterCredID. That is, the OTCredential's "master credential ID" is formed
    // as a hash of the signed contract that is its OTMasterkey.
    // BUT!!! We don't want to use a hash of the private key information, since others cannot verify
    // the hash without seeing our private key. We want OTMasterkey to create an 'official' signed
    // public version of itself, minus private keys, which is what can be sent to servers and to
    // other users, and which can be hashed to form the master credential ID (and verified later.)
    // ...Which is exactly what it does. Inside pCredential->SignNewMaster, a public version is created
    // and signed, and set onto that masterkey as m_strContents. It's then re-signed as the private
    // version, which contains m_strContents in encoded form, along with the private keys.
    //
    return pCredential;
}

// ----------------------------------

size_t OTCredential::GetSubcredentialCount() const
{
    return m_mapSubcredentials.size();
}


const OTSubcredential * OTCredential::GetSubcredential(const OTString & strSubID, const listOfStrings * plistRevokedIDs/*=NULL*/) const
{
    FOR_EACH_CONST(mapOfSubcredentials, m_mapSubcredentials)
    {
        const std::string str_cred_id = (*it).first;
        const OTSubcredential * pSub  = (*it).second;
        OT_ASSERT(NULL != pSub);
        // ------------------------
        // See if pSub, with ID str_cred_id, is on plistRevokedIDs...
        //
        if (NULL != plistRevokedIDs)
        {
            listOfStrings::const_iterator iter = std::find(plistRevokedIDs->begin(), plistRevokedIDs->end(), str_cred_id);
            if (iter != plistRevokedIDs->end()) // It was on the revoked list.
                continue; // Skip this revoked credential.
        }
        // At this point we know it's not on the revoked list, if one was passed in.
        // --------------------------------------------------
        if (strSubID.Compare(str_cred_id.c_str()))
            return pSub;
    }
    return NULL;
}



const OTSubcredential * OTCredential::GetSubcredentialByIndex(int nIndex) const
{
    if ((nIndex < 0) || (nIndex >= m_mapSubcredentials.size()))
    {
        OTLog::vError("%s: Index out of bounds: %d\n", __FUNCTION__, nIndex);
    }
    else
    {
        int nLoopIndex = -1;
        
        FOR_EACH_CONST(mapOfSubcredentials, m_mapSubcredentials)
        {
            const std::string str_cred_id = (*it).first;
            const OTSubcredential * pSub  = (*it).second;
            OT_ASSERT(NULL != pSub);
            // ------------------------
            ++nLoopIndex; // 0 on first iteration.
            // ------------------------
            if (nIndex == nLoopIndex)
                return pSub;
        }
    }
    // -------------------------
    return NULL;
}



const std::string OTCredential::GetSubcredentialIDByIndex(size_t nIndex) const
{
    if (nIndex >= m_mapSubcredentials.size())
    {
        OTLog::vError("%s: Index out of bounds: %d\n", __FUNCTION__, nIndex);
    }
    else
    {
        int nLoopIndex = -1;
        
        FOR_EACH_CONST(mapOfSubcredentials, m_mapSubcredentials)
        {
            const std::string str_cred_id = (*it).first;
            const OTSubcredential * pSub  = (*it).second;
            OT_ASSERT(NULL != pSub);
            // ------------------------
            ++nLoopIndex; // 0 on first iteration.
            // ------------------------
            if (nIndex == nLoopIndex)
                return str_cred_id;
        }
    }
    // -------------------------
    return NULL;
}




// ----------------------------------

const OTKeypair & OTCredential::GetAuthKeypair(const listOfStrings * plistRevokedIDs/*=NULL*/) const
{
    FOR_EACH_CONST(mapOfSubcredentials, m_mapSubcredentials)
    {
        const std::string str_cred_id = (*it).first;
        const OTSubcredential * pSub  = (*it).second;
        OT_ASSERT(NULL != pSub);
        // ------------------------
        const OTSubkey * pKey = dynamic_cast<const OTSubkey *>(pSub);
        if (NULL == pKey) continue;
        // ------------------------
        // See if pKey, with ID str_cred_id, is on plistRevokedIDs...
        //
        if (NULL != plistRevokedIDs)
        {
            listOfStrings::const_iterator iter = std::find(plistRevokedIDs->begin(), plistRevokedIDs->end(), str_cred_id);
            if (iter != plistRevokedIDs->end()) // It was on the revoked list.
                continue; // Skip this revoked key.
        }
        // At this point we know it's a key credential, and we know it's not on
        // the revoked list. Therefore, let's return the key! (Any other future
        // smart criteria might go here before taking this final step...)
        //
        return pKey->m_AuthentKey;
    }
    
    // Didn't find any subcredentials we can use? For now, we'll return the master key instead.
    // This is purely for backwards compatibility reasons and eventually should be removed. That is,
    // masters should only be able to verify subkeys, and only subkeys should be able to do actions.
    // Capiche?
    //
    return m_Masterkey.m_AuthentKey;
}

const OTKeypair & OTCredential::GetEncrKeypair(const listOfStrings * plistRevokedIDs/*=NULL*/) const
{
    FOR_EACH_CONST(mapOfSubcredentials, m_mapSubcredentials)
    {
        const std::string str_cred_id = (*it).first;
        const OTSubcredential * pSub  = (*it).second;
        OT_ASSERT(NULL != pSub);
        // ------------------------
        const OTSubkey * pKey = dynamic_cast<const OTSubkey *>(pSub);
        if (NULL == pKey) continue;
        // ------------------------
        // See if pKey, with ID str_cred_id, is on plistRevokedIDs...
        //
        if (NULL != plistRevokedIDs)
        {
            listOfStrings::const_iterator iter = std::find(plistRevokedIDs->begin(), plistRevokedIDs->end(), str_cred_id);
            if (iter != plistRevokedIDs->end()) // It was on the revoked list.
                continue; // Skip this revoked key.
        }
        // At this point we know it's a key credential, and we know it's not on
        // the revoked list. Therefore, let's return the key! (Any other future
        // smart criteria might go here before taking this final step...)
        //
        return pKey->m_EncryptKey;
    }
    
    // Didn't find any subcredentials we can use? For now, we'll return the master key instead.
    // This is purely for backwards compatibility reasons and eventually should be removed. That is,
    // masters should only be able to verify subkeys, and only subkeys should be able to do actions.
    // Capiche?
    //
    return m_Masterkey.m_EncryptKey;
}

const OTKeypair & OTCredential::GetSignKeypair(const listOfStrings * plistRevokedIDs/*=NULL*/) const
{
    FOR_EACH_CONST(mapOfSubcredentials, m_mapSubcredentials)
    {
        const std::string str_cred_id = (*it).first;
        const OTSubcredential * pSub  = (*it).second;
        OT_ASSERT(NULL != pSub);
        // ------------------------
        const OTSubkey * pKey = dynamic_cast<const OTSubkey *>(pSub);
        if (NULL == pKey) continue;
        // ------------------------
        // See if pKey, with ID str_cred_id, is on plistRevokedIDs...
        //
        if (NULL != plistRevokedIDs)
        {
            listOfStrings::const_iterator iter = std::find(plistRevokedIDs->begin(), plistRevokedIDs->end(), str_cred_id);
            if (iter != plistRevokedIDs->end()) // It was on the revoked list.
                continue; // Skip this revoked key.
        }
        // At this point we know it's a key credential, and we know it's not on
        // the revoked list. Therefore, let's return the key! (Any other future
        // smart criteria might go here before taking this final step...)
        //
        return pKey->m_SigningKey;
    }
    
    // Didn't find any subcredentials we can use? For now, we'll return the master key instead.
    // This is purely for backwards compatibility reasons and eventually should be removed. That is,
    // masters should only be able to verify subkeys, and only subkeys should be able to do actions.
    // Capiche?
    //
    return m_Masterkey.m_SigningKey;
}

// ------------------------------


// NOTE: Until we figure out the rule by which we decide WHICH authentication key is the right auth key,
// or WHICH signing key is the right signing key, we'll just go with the first one we find.
// We'll also weed out any that appear on plistRevokedIDs, if it's passed in. (Optional.)

const OTAsymmetricKey & OTCredential::GetPublicAuthKey(const listOfStrings * plistRevokedIDs/*=NULL*/) const
{
    return this->GetAuthKeypair(plistRevokedIDs).GetPublicKey();
}

const OTAsymmetricKey & OTCredential::GetPublicEncrKey(const listOfStrings * plistRevokedIDs/*=NULL*/) const
{
    return this->GetEncrKeypair(plistRevokedIDs).GetPublicKey();
}

const OTAsymmetricKey & OTCredential::GetPublicSignKey(const listOfStrings * plistRevokedIDs/*=NULL*/) const
{
    return this->GetSignKeypair(plistRevokedIDs).GetPublicKey();
}

// ----------------------------------

const OTAsymmetricKey & OTCredential::GetPrivateAuthKey(const listOfStrings * plistRevokedIDs/*=NULL*/) const
{
    return this->GetAuthKeypair(plistRevokedIDs).GetPrivateKey();
}

const OTAsymmetricKey & OTCredential::GetPrivateEncrKey(const listOfStrings * plistRevokedIDs/*=NULL*/) const
{
    return this->GetEncrKeypair(plistRevokedIDs).GetPrivateKey();
}

const OTAsymmetricKey & OTCredential::GetPrivateSignKey(const listOfStrings * plistRevokedIDs/*=NULL*/) const
{
    return this->GetSignKeypair(plistRevokedIDs).GetPrivateKey();
}

// ----------------------------------

OTCredential::~OTCredential()
{
    this->ClearSubcredentials();
}

void OTCredential::ClearSubcredentials()
{
    // ---------------------------
	while (!m_mapSubcredentials.empty())
	{
		OTSubcredential * pSub = m_mapSubcredentials.begin()->second;
		OT_ASSERT(NULL != pSub);
		// -----------
		delete pSub;
		pSub = NULL;
        // -----------
		m_mapSubcredentials.erase(m_mapSubcredentials.begin());
	} // while
    // --------------------------- 
}


// I needed this for exporting a Nym (with credentials) from the wallet.
const OTString & OTSubcredential::GetPriCredential() const
{
    OT_ASSERT_MSG(m_mapPrivateInfo.size() > 0, "ASSERT: GetPriCredential can only be called on private subcredentials.");
    
    return m_strRawFile;
}


// We don't want to have to figure this out each time we need the public credential, so we just
// call this function wherever we need to get the public credential.
//
const OTString & OTSubcredential::GetPubCredential()  const  // More intelligent version of GetContents. Higher level.
{
    // If this is a private (client-side) credential containing private keys,
    // then the public version is stored in GetContents(), and return that.
    if ((m_mapPrivateInfo.size() > 0) && this->GetContents().Exists())
        return this->GetContents();
    
    // Otherwise this is a server-side copy of a Nym's credential, with no private keys inside it.
    // In which case public info that would have been in GetContents (making room so we can have
    // the private keys in m_strRawFile) is now directly found in m_strRawFile, since that's all the
    // server ever loads up. There is only public info and nothing else, so it's found in the main
    // normal location, m_strRawFile.
    //
    return m_strRawFile;
}

// listRevokedIDs should contain a list of std::strings for IDs of already-revoked subcredentials.
// That way, SerializeIDs will know whether to mark them as valid while serializing them.
// bShowRevoked allows us to include/exclude the revoked credentials from the output (filter for valid-only.)
// bValid=true means we are saving OTPseudonym::m_mapCredentials. Whereas bValid=false means we're saving m_mapRevoked.
// pmapPubInfo is optional output, the public info for all the credentials will be placed inside, if a pointer is provided.
//
void OTCredential::SerializeIDs(OTString & strOutput, listOfStrings & listRevokedIDs,
                                mapOfStrings * pmapPubInfo/*=NULL*/,
                                mapOfStrings * pmapPriInfo/*=NULL*/,
                                bool bShowRevoked/*=false*/, bool bValid/*=true*/) const
{
    if (bValid || bShowRevoked)
    {
        strOutput.Concatenate("<masterCredential\n"
                              " ID=\"%s\"\n"
                              " valid=\"%s\""
                              "/>\n\n",
                              this->GetMasterCredID().Get(),
                              bValid ? "true" : "false");
        // ------------------------------------------------
        if (NULL != pmapPubInfo) // optional out-param.
            pmapPubInfo->insert(std::pair<std::string, std::string>(this->GetMasterCredID().Get(), this->GetPubCredential().Get()));
        // ------------------------------------------------
        if (NULL != pmapPriInfo) // optional out-param.
            pmapPriInfo->insert(std::pair<std::string, std::string>(this->GetMasterCredID().Get(), this->GetPriCredential().Get()));
        // ------------------------------------------------
    }
    // -------------------------------------
    FOR_EACH_CONST(mapOfSubcredentials, m_mapSubcredentials)
    {
        const std::string str_cred_id = (*it).first;
        const OTSubcredential * pSub  = (*it).second;
		OT_ASSERT(NULL != pSub);
        // -----------------------------
        // See if the current subcredential is on the Nym's list of "revoked" subcredential IDs.
        // If so, we'll skip serializing it here.
        //
        listOfStrings::iterator iter = std::find(listRevokedIDs.begin(), listRevokedIDs.end(), str_cred_id);
        
        // Was it on the 'revoked' list?
        // If not, then the subcredential isn't revoked, so it's still valid.
        //
        const bool bSubcredValid = bValid ? (iter == listRevokedIDs.end()) : false;
        // -----------------------------
        if (bSubcredValid || bShowRevoked)
        {
            const OTSubkey * pSubkey = dynamic_cast<const OTSubkey *>(pSub);
            
            if (NULL != pSubkey)
                strOutput.Concatenate("<keyCredential\n"
                                      " ID=\"%s\"\n"
                                      " masterID=\"%s\"\n"
                                      " valid=\"%s\""
                                      "/>\n\n",
                                      str_cred_id.c_str(),
                                      pSubkey->GetMasterCredID().Get(),
                                      bSubcredValid ? "true" : "false");
            else
                strOutput.Concatenate("<subCredential\n"
                                      " ID=\"%s\"\n"
                                      " masterID=\"%s\"\n"
                                      " valid=\"%s\""
                                      "/>\n\n",
                                      str_cred_id.c_str(),
                                      pSub->GetMasterCredID().Get(),
                                      bSubcredValid ? "true" : "false");
            // ------------------------------------------------
            if (NULL != pmapPubInfo) // optional out-param.
                pmapPubInfo->insert(std::pair<std::string, std::string>(str_cred_id.c_str(), pSub->GetPubCredential().Get()));
            // ------------------------------------------------
            if (NULL != pmapPriInfo) // optional out-param.
                pmapPriInfo->insert(std::pair<std::string, std::string>(str_cred_id.c_str(), pSub->GetPriCredential().Get()));
            // ------------------------------------------------
        } // if (bSubcredValid)
    } // FOR_EACH_CONST
    // -------------------------------------
}









// ------------------------------------------------
// ------------------------------------------------
// ------------------------------------------------
// ------------------------------------------------





















