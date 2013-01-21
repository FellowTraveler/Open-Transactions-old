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



// ------------------------------------------------
#include "OTStorage.h"

#include "OTContract.h"
#include "OTAsymmetricKey.h"
#include "OTCredential.h"

#include "OTLog.h"

// ------------------------------------------------



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
    if (NULL != m_pkeyPrivate)
        delete m_pkeyPrivate; // todo: else error
    // -----------------------------
	m_pkeyPublic	= NULL;
	m_pkeyPrivate	= NULL;
    // -----------------------------
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

bool OTKeypair::SaveCertToString(OTString & strOutput)
{
    OT_ASSERT(NULL != m_pkeyPublic);
    // ---------------------------------------------------------------
    OTString strCert;
    
    const bool bSaved = m_pkeyPublic->SaveCertToString(strCert);
    // ---------------------------------------------------------------
	if (bSaved)
        strOutput = strCert;
	
	return bSaved;    
}
// ---------------------------------------------------------------

bool OTKeypair::SavePrivateKeyToString(OTString & strOutput, const OTString * pstrReason/*=NULL*/)
{
    OT_ASSERT(NULL != m_pkeyPrivate);
    // ---------------------------------------------------------------
    OTString strPrivateKey;
    
    const bool bSaved = m_pkeyPrivate->SavePrivateKeyToString(strPrivateKey, pstrReason);
    // ---------------------------------------------------------------
	if (bSaved)
        strOutput = strPrivateKey;
	
	return bSaved;
}
// ------------------------------------------------

bool OTKeypair::SaveCertAndPrivateKeyToString(OTString & strOutput, const OTString * pstrReason/*=NULL*/)
{
    OTString strCert, strPrivateKey;
    
    const bool bSaved1 = this->SaveCertToString      (strCert);
    const bool bSaved2 = this->SavePrivateKeyToString(strPrivateKey, pstrReason);
    // ---------------------------------------------------------------
	if (bSaved1 && bSaved2)
		strOutput.Format(const_cast<char*>("%s%s"), strPrivateKey.Get(), strCert.Get());
	
	return (bSaved1 && bSaved2);
}
// ------------------------------------------------

bool OTKeypair::LoadCertAndPrivateKeyFromString(const OTString & strInput, const OTString * pstrReason/*=NULL*/)
{
    const char *szFunc = "OTKeypair::LoadCertAndPrivateKeyFromString";
	// ---------------------------------------------------------------
    OT_ASSERT(strInput.Exists());
	// ---------------------------------------------------------------
    // "escaped" means pre-pended with "- " as in:   - -----BEGIN CER....
    //
    const bool bPublic  = this->LoadPublicKeyFromCertString (strInput, false); //bool bEscaped=true by default
    const bool bPrivate = this->LoadPrivateKeyFromCertString(strInput, false,  //bool bEscaped=true by default,
                                                             pstrReason);
    if (!bPublic)
    {
        OTLog::vError("%s: Although the input string apparently exists, "
                      "LoadPublicKeyFromCertString returned false.\n", szFunc);
        return false;
    }
    else
    {
        OTLog::vOutput(2, "%s: Successfully loaded public key from string.\n",
                       szFunc);
    }
    // ----------------
    if (!bPrivate)
    {
        OTLog::vError("%s: Although the input string apparently exists, "
                      "LoadPrivateKeyFromCertString returned false.\n", szFunc);
        return false;
    }
    else
    {
        OTLog::vOutput(2, "%s: Successfully loaded private key from string.\n", szFunc);
    }
    // ----------------
    return true;
}

// ------------------------------------------------

bool OTKeypair::SaveAndReloadBothKeysFromTempFile(      OTString * pstrOutputCert/*=NULL*/,
                                                  const OTString * pstrReason/*=NULL*/)
{
    const char * szFunc = " OTKeypair::SaveAndReloadBothKeysFromTempFile";
	// ---------------------------------------------------------------
    OT_ASSERT(NULL != m_pkeyPrivate);
    OT_ASSERT(NULL != m_pkeyPublic);
    // ---------------------------------------------------------------
    OTString    strOutput;
    const bool  bSuccess   = this->SaveCertAndPrivateKeyToString(strOutput, pstrReason);
	// ---------------------------------------
	if (bSuccess)
	{
        // todo security. Revisit this part during security audit.
        //
		const OTString strFilename("temp.nym"); // todo stop hardcoding. Plus this maybe should select a random number too.
        
		if (false == OTDB::StorePlainString(strOutput.Get(), OTFolders::Cert().Get(), strFilename.Get())) // temp.nym
		{
			OTLog::vError("%s: Failure storing new cert in temp file: %s\n", szFunc, strFilename.Get());
			return false;
		}
		// ------------------------------------------
        if (false == this->LoadBothKeysFromCertFile(OTFolders::Cert().Get(), strFilename, pstrReason))
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
                               const OTString & strFilename, const OTString * pstrReason/*=NULL*/)
{
    OT_ASSERT(NULL != m_pkeyPrivate);
    // ---------------------------------------------------------------
    return m_pkeyPrivate->LoadPrivateKey(strFoldername, strFilename, pstrReason);
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
bool OTKeypair::LoadPrivateKeyFromCertString(const OTString & strCert, bool bEscaped/*=true*/, const OTString * pstrReason/*=NULL*/)
{
    OT_ASSERT(NULL != m_pkeyPrivate);
    // ---------------------------------------------------------------
    return m_pkeyPrivate->LoadPrivateKeyFromCertString(strCert, bEscaped, pstrReason);
}

// ***************************************************************
// Load Public Key from Cert (file or string)
//
bool OTKeypair::LoadPublicKeyFromCertString(const OTString & strCert, bool bEscaped/*=true*/) // DOES handle bookends, AND escapes.
{
    OT_ASSERT(NULL != m_pkeyPublic);
    // ---------------------------------------------------------------
    return m_pkeyPublic->LoadPublicKeyFromCertString(strCert, bEscaped);
}

bool OTKeypair::LoadPublicKeyFromCertFile(const OTString & strFoldername, const OTString & strFilename) // DOES handle bookends.
{
    OT_ASSERT(NULL != m_pkeyPublic);
    // ---------------------------------------------------------------
    return m_pkeyPublic->LoadPublicKeyFromCertFile(strFoldername, strFilename);
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



bool OTKeypair::LoadBothKeysFromCertFile(const OTString & strFoldername,
                                         const OTString & strFilename,
                                         const OTString * pstrReason/*=NULL*/)
{
    const char * szFunc = "OTKeypair::LoadBothKeysFromCertFile";
    // -------------------------------------
    OT_ASSERT(NULL != m_pkeyPublic);
    OT_ASSERT(NULL != m_pkeyPrivate);
    // ---------------------------------------------------------------
    bool bPublic  = false;
    bool bPrivate = false;
    
    bPublic  = m_pkeyPublic-> LoadPublicKeyFromCertFile (strFoldername.Get(), strFilename.Get());
    bPrivate = m_pkeyPrivate->LoadPrivateKey            (strFoldername.Get(), strFilename.Get(),
                                                         pstrReason);
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
// pointer, and sets that as the m_pPublicKey on this object.
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

    return false;
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
			OTLog::vOutput(0, "OTKeypair::SetPrivateKey 1: Failure: PGP private keys are NOT YET SUPPORTED:\n\n%s\n\n",
                           strKey.Get());
			return false;
		}
		else 
        {
			OTLog::vOutput(0, "OTKeypair::SetPrivateKey 2: Failure: PGP private keys are NOT YET SUPPORTED:\n\n%s\n\n",
                           strKey.Get());
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

OTSubcredential::OTSubcredential() : ot_super()
{
    
}

OTSubcredential::~OTSubcredential()
{
    Release_Subcredential();
}

//virtual
void OTSubcredential::Release()
{
    Release_Subcredential();  // My own cleanup is done here.
    
    // Next give the base class a chance to do the same...
	ot_super::Release(); // since I've overridden the base class, I call it now...
}
    
void OTSubcredential::Release_Subcredential()
{
    // Release any dynamically allocated members here. (Normally.) 
}

// ***************************************************************************************

OTSubkey::OTSubkey() : ot_super()
{
    
}

OTSubkey::~OTSubkey()
{
    Release_Subkey();
}

//virtual
void OTSubkey::Release()
{
    Release_Subkey();   // My own cleanup is done here.
    
    // Next give the base class a chance to do the same...
	ot_super::Release(); // since I've overridden the base class, I call it now...
}
    
void OTSubkey::Release_Subkey()
{
    // Release any dynamically allocated members here. (Normally.)
}

// ***************************************************************************************

// Contains a "master" subkey,
// and a list of "sub" subkeys signed by that master.
// Each subkey can generate its own "credential" contract,
// so OTCredential actually may include many "credentials."
// A nym has multiple OTCredentials because there may be
// several master keys.
//


OTCredential::OTCredential() : m_pMasterkey(NULL)
{
    
}

OTCredential::~OTCredential()
{
    if (NULL != m_pMasterkey)
        delete m_pMasterkey;
    m_pMasterkey = NULL;
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

// ------------------------------------------------





















// ------------------------------------------------
// ------------------------------------------------
// ------------------------------------------------
// ------------------------------------------------





















