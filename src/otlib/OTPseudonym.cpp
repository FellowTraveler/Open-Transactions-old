/************************************************************************************
 *    
 *  OTPseudonym.cpp
 *  
 */

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

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>
#include <algorithm>

#ifdef _WIN32
#include <WinsockWrapper.h>
#endif

#ifdef _WIN32 // Including this so it'll be above the openssl/ssl.h
//#include <winsock.h> // So there won't be a conflict with WinCrypt.h due to Windows sucking
#endif


#include "irrxml/irrXML.h"

// -------------------------------------

#include "OTStorage.h"

#include "OTString.h"
#include "OTStringXML.h"
#include "OTIdentifier.h"

#include "OTPassword.h"

#include "OTAsymmetricKey.h"

#include "OTASCIIArmor.h"
#include "OTCredential.h"

#include "OTPseudonym.h"
#include "OTSymmetricKey.h"
#include "OTEnvelope.h"
#include "OTSignedFile.h"
#include "OTItem.h"
#include "OTTransaction.h"
#include "OTLedger.h"
#include "OTMessage.h"
#include "OTPayment.h"

#include "OTLog.h"

// -------------------------------------

using namespace irr;
using namespace io;


//static
OTPseudonym * OTPseudonym::LoadPublicNym(const OTIdentifier & NYM_ID,
										 OTString * pstrName/*=NULL*/, 
										 const char * szFuncName/*=NULL*/)
{
	const char * szFunc = (NULL != szFuncName) ? szFuncName : "OTPseudonym::LoadPublicNym";
	// ------------------------------------------
	const OTString	strNymID(NYM_ID);
	// ------------------------------------------
	// If name is empty, construct one way, 
	// else construct a different way.
	//
	OTPseudonym * pNym = ((NULL == pstrName) || !pstrName->Exists()) ? 
		(new OTPseudonym(NYM_ID)): 
		(new OTPseudonym(*pstrName, strNymID, strNymID));
	OT_ASSERT_MSG(NULL != pNym, "OTPseudonym::LoadPublicNym: Error allocating memory.\n");
	// ---------------------------
    bool bLoadedKey = pNym->LoadPublicKey(); // Deprecated. Only used for old-style Nyms. Eventually, remove this. Currently LoadPublicKey calls LoadCredentials, which is what we should be calling, once the nym's own keypair is eliminated.
	// ---------------------------
	// First load the public key
	if (false == bLoadedKey)
		OTLog::vOutput(1, "%s: %s: Unable to find nym: %s\n", __FUNCTION__, szFunc, strNymID.Get());
	else if (false == pNym->VerifyPseudonym())
		OTLog::vError("%s: %s: Security: Failure verifying Nym: %s\n", __FUNCTION__, szFunc, strNymID.Get());
	else if (false == pNym->LoadSignedNymfile(*pNym))
	{
		OTLog::vOutput(4, "OTPseudonym::LoadPublicNym %s: Usually normal: There's no Nymfile (%s), though there IS a public "
					   "key, which checks out. It's probably just someone else's Nym. (So I'm still returning this Nym to "
					   "the caller so he can still use the public key.)\n", szFunc, strNymID.Get());
		return pNym;
	}
	else // success 
		return pNym;
	// -------------------
	delete pNym; pNym = NULL;
	// -------------------
	return NULL;	
}


/*
 
 Normally when I read someone ELSE'S public key, I DON'T have their Nymfile.
 Therefore I don't HAVE any of their credentials, I only have the NymID and the
 public key itself. Which was fine before, since you hashed the public key to 
 verify the NymID -- and if it matched, then all was good.
 
 But let's say I'm reading a public key from a key credential... the hash of that key
 (or credential) is NOT necessarily the hash of the Nym's ID. So how can I verify it?
 
 Normally I read from:  ~/.ot/client_data/pubkeys/NYM_ID   (for the public key for that Nym.)
 
 Instead I want to read up all available credentials for that Nym.
 Let's say their IDs are stored in: ~/.ot/client_data/pubkeys/NYM_ID.cred
 And the credentials themselves:    ~/.ot/client_data/pubkeys/credentials/NYM_ID/CREDENTIAL_ID
 
 So let's say I have a NymID and I need to load his credentials and use his keys to verify
 the Nym and also to send him messages, verify his signatures on instruments, etc.
 
 pNym->LoadPublicKey() should load the UNSIGNED Nymfile from: ~/.ot/client_data/pubkeys/NYM_ID.cred
 Which, in the course of loading, should automatically load all its credentials from
 ~/.ot/client_data/pubkeys/credentials/NYM_ID/CREDENTIAL_ID
 
 From there, we call VerifyPseudonym, which verifies all the credentials internally, including
 their signatures, and which verifies them against their source, which can also be hashed to
 reproduce the NymID.
 
 ...SINCE all the credentials verify AGAINST THEIR SOURCE, and the source hashes to form the NymID,
 then the Nym is therefore self-verifying, without having to sign the nymfile itself (for public nyms.)
 If I want to sign it anyway, well I will need a private Nym to sign it with, I cannot sign it with
 only a public Nym. So I will have to pass the signer in if I want to do that. But it's unnecessary,
 and in fact it's also unnecessary for private Nyms, (or is it?) because all the credentials ARE signed
 contracts already, and since they all ultimately verify to their source.
 
 Therefore this eliminates LoadSignedNymfile? And SaveSignedNymFile? Or augments -- since we will be backwards compatible...
 
 I'll load the local Nym's credential list and the public nym's credential list from the same
 place: ~/.ot/client_data/credentials/NYM_ID.cred
 EITHER WAY I'll load the actual credentials, each from  ~/.ot/client_data/credentials/NYM_ID/CRED_ID
 Then for the local Nym, I'll load his Nymfile like normal from ~/.ot/client_data/nyms/NYM_ID
 (For public Nyms, I don't need to load a Nymfile or anything else -- the credentials are all there is.)
  
 But I still want my Nymfile itself signed, so people can't mess with my transaction numbers.
 What it comes down to is, I must put the credential list in a separate file, load it, verify it,
 and then use it to verify the signature on the Nymfile which contains everything else. So the
 "LoadSignedNymfile" process isn't going to change for the Nymfile itself, and I will have the credential
 list in a separate file, just like the certs were in a separate file in the original system (for the
 same reasons.)
 
 */



//static
OTPseudonym * OTPseudonym::LoadPrivateNym(const OTIdentifier & NYM_ID,
										  const bool		   bChecking/*=false*/,
										        OTString     * pstrName/*=NULL*/,
										  const char         * szFuncName/*=NULL*/,
                                              OTPasswordData * pPWData/*=NULL*/,
                                                OTPassword   * pImportPassword/*=NULL*/)
{	
	const char * szFunc = (NULL != szFuncName) ? szFuncName : "OTPseudonym::LoadPrivateNym";

	if (NYM_ID.IsEmpty()) return NULL;
	// ------------------------------------------
	const OTString	strNymID(NYM_ID);
	// ------------------------------------------
	// If name is empty, construct one way, 
	// else construct a different way.
	//
	OTPseudonym * pNym = ((NULL == pstrName) || !pstrName->Exists()) ? 
		(new OTPseudonym(NYM_ID)): 
		(new OTPseudonym(*pstrName, strNymID, strNymID));
	OT_ASSERT_MSG(NULL != pNym, "OTPseudonym::LoadPrivateNym: Error allocating memory.\n");
	// ---------------------------------
    OTPasswordData thePWData(OT_PW_DISPLAY);
    if (NULL == pPWData)
        pPWData = &thePWData;
    // ----------------------------------
    bool bLoadedKey = pNym->Loadx509CertAndPrivateKey(bChecking, pPWData, pImportPassword); // old style. (Deprecated.) Eventually remove this.
    //***  Right now Loadx509CertAndPrivateKey calls LoadCredentials at its top, which is what we should be calling here. But that function handles old-style Nyms too, so we keep it around until we lose those.  // <====================
    // ---------------------------------
	// Error loading x509CertAndPrivateKey.
	if (false == bLoadedKey)
		OTLog::vOutput(bChecking ? 1 : 0,"%s: %s: (%s: is %s).  Unable to load credentials, "
                       "cert and private key for: %s (maybe this nym doesn't exist?)",
                       __FUNCTION__, szFunc, "bChecking", bChecking ? "true" : "false", strNymID.Get());
	// success loading x509CertAndPrivateKey,
	// failure verifying pseudonym public key.
	else if (false == pNym->VerifyPseudonym())                              // <====================
		OTLog::vError("%s %s: Failure verifying Nym public key: %s\n",
                      __FUNCTION__, szFunc, strNymID.Get());
	// success verifying pseudonym public key.
	// failure loading signed nymfile.
	else if (false == pNym->LoadSignedNymfile(*pNym)) // Unlike with public key, with private key we DO expect nymfile to be here.
		OTLog::vError("%s %s: Failure calling LoadSignedNymfile: %s\n",
                      __FUNCTION__, szFunc, strNymID.Get());
	else // ultimate success.
		return pNym;
	// ---------------------------------
	delete pNym; 
	pNym = NULL;
	// ----------
	return NULL;	
}


// pstrSourceForNymID if left NULL, will use the Nym's public key (OT's original method.)
// Since that is already the Nym's ID (hash of public key) then providing the Nym's public
// key here will naturally hash to the correct ID and thus is the logical default action.
//
// But pstrSourceForNymID might contain a Bitcoin or Namecoin address, or the DN info from
// a traditional Certificate Authority, or a Freenet or Tor or I2P URL, or indeed any URL
// at all... We will also continue to support a simple public key, and by default, if none
// is provided, we will use the Nym's own public key as the source, and if the credential
// contents are not provided, the public cert or public key in full raw text shall be placed
// in this field.
//
// In the case of a traditional CA-issued cert, you would pass the unique issuer and subject DN
// info into the pstrSourceForNymID parameter (where the hash of that data results in the NymID,
// so you should only do it with a brand-new Nym in that case, since it will change the NymID.
// So for the API for creating new Nyms, we will force it that way in the interface to keep things
// safe, but at this low of a level, the power exists.) Continuing that same example, you would
// pass your actual public cert as pstrCredentialContents.
//
// If pstrSourceForNymID was a URL, then perhaps pstrCredentialContents would contain the contents
// located at that URL. As long as the contents of the string pstrCredentialContents can also
// be found at pstrSourceForNymID (or a list of hashes of similar strings...) then the master
// credential will verify. So for example, at the URL you might just post the same public cert,
// or you might have some OTCredential serialized string that contains the Nym ID, the Master
// credential IDs and subcredential IDs that are valid and invalid.
//
// Thought: Seems that there are three ways of exporting the OTCredential: as IDs only, as IDs
// with public keys, and as IDs with public keys and private keys.
//
// hash of pstrSourceForNymID is the NymID, and hash of pstrCredentialContents
// is the credential ID for this new master credential.
bool OTPseudonym::AddNewMasterCredential(      OTString & strOutputMasterCredID,
                                         const OTString * pstrSourceForNymID/*=NULL*/, // If NULL, it uses the Nym's (presumed) existing pubkey as the source.
                                         const int            nBits/*=1024*/,       // Ignored unless pmapPrivate is NULL.
                                         const mapOfStrings * pmapPrivate/*=NULL*/, // If NULL, then the keys are generated in here.
                                         const mapOfStrings * pmapPublic /*=NULL*/, // In the case of key credentials, public is optional since it can already be derived from private. For now we pass it through... May eliminate this parameter later if not needed.
                                         OTPasswordData * pPWData/*=NULL*/, // Pass in the string to show users here, if/when asking for the passphrase.
                                         bool bChangeNymID/*=false*/) // Must be explicitly set to true, to change the Nym's ID. Other restrictions also apply... must be your first master credential. Must have no accounts. Basically can only be used for brand-new Nyms in circumstances where it's assumed the Nym's ID is in the process of being generated anyway. Should never be used on some existing Nym who is already in the wallet and who may even have accounts somewhere already.
{
    const
    OTString * pstrSourceToUse  = NULL;
    OTString   strTempPublicKey; // Used sometimes.
    
    const mapOfStrings * pmapActualPrivate = NULL;
    const mapOfStrings * pmapActualPublic  = NULL;
    
    mapOfStrings   mapPrivate, mapPublic; // Used sometimes.
    
    // A source was passed in. We know it's not a public key, since its hash will not match the existing
    // Nym ID. (Only the existing public key will match that when hashed, and you can use that by passing NULL
    // already, which is the following block.) Therefore it must be one of the other choices: a Freenet/I2P/Tor URL,
    // or indeed any URL at all, a Bitcoin address, a Namecoin address (which is actually a form of URL also.)
    // Or of course, the Issuer/Subject DN info from a traditionally-issued cert. In which case we are low-level
    // enough that we will potentially change the NymID here based on that option. But we won't do that for a public
    // key, unless you pass NULL.
    //
    if ((NULL != pstrSourceForNymID) && pstrSourceForNymID->Exists())
    {
        pstrSourceToUse   = pstrSourceForNymID;
        
        pmapActualPrivate = pmapPrivate;
        pmapActualPublic  = pmapPublic;
        
        // Public are optional, since they can be derived from private.
        // But private are NOT optional -- must be passed in this case.
        OT_ASSERT(NULL != pmapPrivate);
    }
    // ----------------------------
    else
    {   // pstrSourceForNymID was NULL, which means by default,
        // use the Nym's existing public key as the source.
        // (Does one exist?)
        //
        if ((false == this->HasPublicKey()) && (false == this->LoadPublicKey()))
        {
            OTLog::vError("In %s, line %d: in OTPseudonym::AddNewMasterCredential, we tried to generate a new master credential based on the Nym's existing public key. Unfortunately, the Nym apparently has no public key, or it wasn't properly loaded before this function was called. So I tried to load it, but the attempt failed.\n", __FILE__, __LINE__);
            return false;
        }
        // ----------------------------------------------        
        m_pkeypair->GetPublicKey(strTempPublicKey); // bEscaped=true by default.
        pstrSourceToUse = &strTempPublicKey;
        // ----------------------------------------------
        // Hash the Nym's public key and see if it's the NymID.
        // Return false if failure here.
        //
        OTIdentifier theTempID;
        theTempID.CalculateDigest(*pstrSourceToUse);
//      m_pkeypair->CalculateID(theTempID);

        if (false == this->CompareID(theTempID))
        {
            OTString strNymID;
            this->GetIdentifier(strNymID);
            
            OTIdentifier theKeypairNymID;
            m_pkeypair->CalculateID(theKeypairNymID);
            
            const OTString strKeypairNymID(theKeypairNymID), strCalculatedNymID(theTempID);
            
            OTLog::vOutput(0, "%s: No NymID Source was passed in, so I tried to use the existing public key for "
                           "Nym, but hashing that failed to produce the Nym's ID. Meaning the Nym must have "
                           "some other source already, which needs to be passed into this function, for it to work "
                           "on this Nym.\n NYM ID: %s \n KEY PAIR CALCULATED ID: %s \n CONTENTS CALCULATED ID: %s \n NYM ID SOURCE: \n%s\n",
                           __FUNCTION__, strNymID.Get(), strKeypairNymID.Get(), strCalculatedNymID.Get(), pstrSourceToUse->Get());
            return false;
        }
        // ----------------------------------------------
        // Create 2 keypairs here (for authentication and for encryption) and
        // use the Nym's existing keypair as the 3rd (the signing key.)
        // Use the public/private data for all 3 keypairs onto mapPublic and
        // mapPrivate
        //
        OT_ASSERT(NULL == pmapPrivate); // Since we are expected to use the existing keypair and generate 2 others,
        OT_ASSERT(NULL == pmapPublic);  // then there is no reason for anyone to be passing keypair data in here.
        pmapActualPrivate = &mapPrivate;
        pmapActualPublic  = &mapPublic;
        // ----------------------------------------------
        OTKeypair keyAuth, keyEncr;  // (The signing keypair already exists. These are the other two we need.)
        const bool bCreateKeyAuth = keyAuth.MakeNewKeypair();
        const bool bCreateKeyEncr = keyEncr.MakeNewKeypair();
        OT_ASSERT(bCreateKeyAuth && bCreateKeyEncr);
        // ----------------------------------------------        
        keyAuth.SaveAndReloadBothKeysFromTempFile();  // Keys won't be right until this happens.
        keyEncr.SaveAndReloadBothKeysFromTempFile();  // (Necessary evil until better fix.)
        // ----------------------------------------------
        OTString strPublicKey, strPrivateCert;
        // ------------------------------------------
        const OTString strReason("Generating keys for new master credential (preserving existing Nym keypair for signing...)");
        // ------------------------------------------
        const bool b1 = m_pkeypair->GetPublicKey(strPublicKey, false); // bEscaped=true by default.
        const bool b2 = m_pkeypair->SaveCertAndPrivateKeyToString(strPrivateCert, &strReason);
        
        if (b1)
            mapPublic. insert(std::pair<std::string, std::string>("S", strPublicKey.Get()));
        if (b2)
            mapPrivate.insert(std::pair<std::string, std::string>("S", strPrivateCert.Get()));
        // ------------------------------------------------------------------------------------------
        strPublicKey.  Release();
        strPrivateCert.Release();
        const bool b3 = keyAuth.GetPublicKey(strPublicKey, false); // bEscaped=true by default.
        const bool b4 = keyAuth.SaveCertAndPrivateKeyToString(strPrivateCert, &strReason);
        
        if (b3)
            mapPublic. insert(std::pair<std::string, std::string>("A", strPublicKey.Get()));
        if (b4)
            mapPrivate.insert(std::pair<std::string, std::string>("A", strPrivateCert.Get()));
        // ------------------------------------------------------------------------------------------
        strPublicKey.  Release();
        strPrivateCert.Release();
        const bool b5 = keyEncr.GetPublicKey(strPublicKey, false); // bEscaped=true by default.
        const bool b6 = keyEncr.SaveCertAndPrivateKeyToString(strPrivateCert, &strReason);
        
        if (b5)
            mapPublic. insert(std::pair<std::string, std::string>("E", strPublicKey.Get()));
        if (b6)
            mapPrivate.insert(std::pair<std::string, std::string>("E", strPrivateCert.Get()));
        // ------------------------------------------
        if (3 != mapPublic.size())
        {
            OTLog::vError("In %s, line %d: Failed getting public keys in OTPseudonym::AddNewMasterCredential.\n",
                          __FILE__, __LINE__);
            return false;
        }
        // --------------------------------
        if (3 != mapPrivate.size())
        {
            OTLog::vError("In %s, line %d: Failed getting private keys in OTPseudonym::AddNewMasterCredential.\n",
                          __FILE__, __LINE__);
            return false;
        }
    }
    // --------------------------------------------------
    // See if there are any other master credentials already. If there are, make
    // sure they have the same source string calculated above. 
    //
    if (m_mapCredentials.size() > 0)
    {
        FOR_EACH(mapOfCredentials, m_mapCredentials)
        {
            OTCredential * pCredential = (*it).second;
            OT_ASSERT(NULL != pCredential);
            // -----------------------------
            if (false == pstrSourceToUse->Compare(pCredential->GetSourceForNymID()))
            {
                OTLog::vOutput(0, "%s: Attempt to add new master credential failed to "
                               "match the NymID Source on an existing master credential.\n", __FUNCTION__);
                return false;
            }
        } // FOR_EACH
        // --------------------------------------------------
        // bChangeNymID only works if we are adding the FIRST credential. You can't be changing
        // a Nym's ID if he already has credentials, since we only made that possible in the first
        // place to make it possible to add the first credential.
        //
        if (bChangeNymID)
        {
            OTLog::vError("%s: Failure: cannot change NymID for Nym who "
                          "already has credentials.\n", __FUNCTION__);
            return false;
        }
        // --------------------------------------------------

    }
    // --------------------------------------------------
    // Can't change the NymID if it's already registered at a server somewhere.
    //
    if (bChangeNymID && (m_mapRequestNum.size() > 0))
    {
        OTLog::vError("%s: Failure: cannot change NymID for Nym who already is registered at "
                      "transaction servers.\n", __FUNCTION__);
        return false;
    }
    // --------------------------------------------------
    // Create a new master credential, and set its source string (which also sets
    // the NymID).
    //
    OTCredential * pMaster = OTCredential::CreateMaster(*pstrSourceToUse, nBits, pmapActualPrivate, pmapActualPublic, pPWData);
    
    if (NULL == pMaster) // Below this block, pMaster must be cleaned up.
    {
        OTLog::vError("%s: Failed trying to create a new master credential, while calling "
                      "OTCredential::CreateMaster.\n", __FUNCTION__);
        return false;
    }
    // --------------------------------------------------
    // NOTE: The only way to verify a Master Credential is to go to its source (for its NymID)
    // and see if the Master Credential ID is posted at that source. And since the Master Credential
    // ID cannot possibly be known before the Master Credential is created and hashed, there is no
    // way that Credential's ID could have already been posted at that source. Therefore it's
    // impossible for the Credential to verify against the source at this time. (Although it must
    // verify by the time the credential is registered at any OT server.)
    // ----------------------------------------------------
    // We can still verify the credential internally, however. (Everything but the source.)
    //
    OTString strNymID;
    this->GetIdentifier(strNymID);
    
    if (false == pMaster->VerifyInternally())
    {
        OTIdentifier theTempID;
        theTempID.CalculateDigest(*pstrSourceToUse);
        const OTString strTempID(theTempID);
        OTLog::vError("%s: Failed trying to verify the new master credential.\n"
                      "Nym ID: %s\n Source:\n%s\n Hash of Source: %s\n", __FUNCTION__,
                      strNymID.Get(), pstrSourceToUse->Get(), strTempID.Get());
        delete pMaster;
        pMaster = NULL;
        return false;
    }    
    // ----------------------------------------------------
    // OTFolders::Credential() is for private credentials (I've created.)
    // OTFolders::Pubcred() is for public credentials (I've downloaded.)
    // FYI.
    //
    if (OTDB::Exists(OTFolders::Credential().Get(), strNymID.Get(), pMaster->GetMasterCredID().Get()))
    {
        OTLog::vError("%s: Failure: Apparently there is already a credential stored "
                      "for this ID (even though this is a new master credential, just generated.)\n",
                      __FUNCTION__);
        delete pMaster;
        pMaster = NULL;
        return false;
    }
    // ----------------------------------------------------
    // It's already signed (inside CreateMaster) but it's still not added to the Nym,
    // or saved to local storage. So let's do that next...
    //
    OTString strFoldername, strFilename;
    strFoldername.Format("%s%s%s", OTFolders::Credential().Get(), OTLog::PathSeparator(), strNymID.Get());
    strFilename.  Format("%s",     pMaster->GetMasterCredID().Get());
    const bool bSaved = const_cast<OTMasterkey&>(pMaster->GetMasterkey()).SaveContract(strFoldername.Get(), strFilename.Get());
    if (!bSaved)
    {
        OTLog::vError("%s: Failed trying to save new master credential to local storage.\n", __FUNCTION__);
        delete pMaster;
        pMaster = NULL;
        return false;
    }
    // --------------------------------------------------
    m_mapCredentials.insert(std::pair<std::string, OTCredential *>(pMaster->GetMasterCredID().Get(), pMaster));
    strOutputMasterCredID = pMaster->GetMasterCredID();
    // --------------------------------------------------
    this->m_strSourceForNymID = *pstrSourceToUse;
    //
    // Todo: someday we'll add "source" and "altLocation" to CreateNym
    // (currently the public key is just assumed to be the source.)
    // When that time comes, we'll need to set the altLocation here as
    // well, since it will be optional whenever there is a source involved.
    // --------------------------------------------------
    this->SaveCredentialList();
    // --------------------------------------------------
    return true;
}

// --------------------------------------------------

bool OTPseudonym::AddNewSubkey(const OTIdentifier & idMasterCredential,
                               const int nBits/*=1024*/,                   // Ignored unless pmapPrivate is NULL.
                               const mapOfStrings * pmapPrivate/*=NULL*/,  // If NULL, then the keys are generated in here.
                               OTPasswordData * pPWData/*=NULL*/)
{
    const OTString strMasterCredID(idMasterCredential);
    // --------------------------------------------------
    mapOfCredentials::iterator it = m_mapCredentials.find(strMasterCredID.Get());
    
    if (it == m_mapCredentials.end()) // Didn't find it.
    {
        OTLog::vOutput(0, "%s: Failed trying to add key credential to nonexistent master credential.\n", __FUNCTION__);
        return false;
    }
    // --------------------------------------------------
    OTCredential * pMaster = (*it).second;
    OT_ASSERT(NULL != pMaster);
    // --------------------------------------------------
    OTSubkey * pSubkey = NULL;
    const bool bAdded = pMaster->AddNewSubkey(nBits, pmapPrivate, pPWData, &pSubkey);
    // ------------------------------
    if (false == bAdded)
    {
        OTLog::vOutput(0, "%s: Failed trying to add key credential to master credential.\n", __FUNCTION__);
        return false;
    }
    OT_ASSERT(NULL != pSubkey);
    // ----------------------------------------------------
    if (false == pSubkey->VerifyInternally())
    {
        
        OTLog::Error("NYM::ADD_NEW_SUBKEY:   2.5 \n");

        OTLog::vError("%s: Failed trying to verify the new key credential.\n", __FUNCTION__);
        // todo: remove it again, since it failed to verify.
        return false;
    }
    // ----------------------------------------------------
    // It's already signed (inside AddNewSubkey) but it's still not added to the Nym,
    // or saved to local storage. So let's do that next...
    //
    OTString strNymID, strSubkeyID;
    this->GetIdentifier(strNymID);
    pSubkey->GetIdentifier(strSubkeyID);

    // OTFolders::Credential() is for private credentials (I've created.)
    // OTFolders::Pubcred() is for public credentials (I've downloaded.)
    //
    if (OTDB::Exists(OTFolders::Credential().Get(), strNymID.Get(), strSubkeyID.Get()))
    {
        OTLog::vError("%s: Failure: Apparently there is already a credential stored "
                      "for this ID (even though this is a new credential, just generated.)\n",
                      __FUNCTION__);
        return false;
    }
    // ----------------------------------------------------
    OTString strFoldername, strFilename;
    strFoldername.Format("%s%s%s", OTFolders::Credential().Get(), OTLog::PathSeparator(), strNymID.Get());
    strFilename.  Format("%s",     strSubkeyID.Get());
    const bool bSaved = pSubkey->SaveContract(strFoldername.Get(), strFilename.Get());
    if (!bSaved)
    {
        OTLog::vError("%s: Failed trying to save new key credential to local storage.\n", __FUNCTION__);
        return false;
    }
    // --------------------------------------------------
    this->SaveCredentialList();
    // --------------------------------------------------
    return true;
}

// --------------------------------------------------

bool OTPseudonym::AddNewSubcredential(const OTIdentifier & idMasterCredential,
                                      const mapOfStrings * pmapPrivate/*=NULL*/,  // If NULL, then the keys are generated in here.
                                      const mapOfStrings * pmapPublic/*=NULL*/,   // In the case of key credentials, public is optional since it can already be derived from private. For now we pass it through... May eliminate this parameter later if not needed.
                                      OTPasswordData * pPWData/*=NULL*/)
{
    const OTString strMasterCredID(idMasterCredential);
    // --------------------------------------------------
    mapOfCredentials::iterator it = m_mapCredentials.find(strMasterCredID.Get());
    
    if (it == m_mapCredentials.end()) // Didn't find it.
    {
        OTLog::vOutput(0, "%s: Failed trying to add subcredential to nonexistent master credential.\n", __FUNCTION__);
        return false;
    }
    // --------------------------------------------------
    OTCredential * pMaster = (*it).second;
    OT_ASSERT(NULL != pMaster);
    // --------------------------------------------------
    OTSubcredential * pSubcredential = NULL;
    const bool bAdded = pMaster->AddNewSubcredential(*pmapPrivate, *pmapPublic, pPWData, &pSubcredential);
    // ------------------------------
    if (false == bAdded)
    {
        OTLog::vOutput(0, "%s: Failed trying to add subcredential to master credential.\n", __FUNCTION__);
        return false;
    }
    OT_ASSERT(NULL != pSubcredential);
    // ----------------------------------------------------
    if (false == pSubcredential->VerifyInternally())
    {
        OTLog::vError("%s: Failed trying to verify the new subcredential.\n", __FUNCTION__);
        // todo: remove it again, since it failed to verify.
        return false;
    }
    // ----------------------------------------------------
    // It's already signed (inside AddNewSubcredential) but it's still not added to the Nym,
    // or saved to local storage. So let's do that next...
    //
    OTString strNymID, strSubcredentialID;
    this->GetIdentifier(strNymID);
    pSubcredential->GetIdentifier(strSubcredentialID);
    
    if (OTDB::Exists(OTFolders::Credential().Get(), strNymID.Get(), strSubcredentialID.Get()))
    {
        OTLog::vError("%s: Failure: Apparently there is already a credential stored "
                      "for this ID (even though this is a new credential, just generated.)\n",
                      __FUNCTION__);
        return false;
    }
    // ----------------------------------------------------
    OTString strFoldername, strFilename;
    strFoldername.Format("%s%s%s", OTFolders::Credential().Get(), OTLog::PathSeparator(), strNymID.Get());
    strFilename.  Format("%s",     strSubcredentialID.Get());
    const bool bSaved = pSubcredential->SaveContract(strFoldername.Get(), strFilename.Get());
    if (!bSaved)
    {
        OTLog::vError("%s: Failed trying to save new subcredential to local storage.\n", __FUNCTION__);
        return false;
    }
    // --------------------------------------------------
    this->SaveCredentialList();
    // --------------------------------------------------
    return true;
}

// -------------------------------------------------



/// Though the parameter is a reference (forcing you to pass a real object),
/// the Nym DOES take ownership of the object. Therefore it MUST be allocated
/// on the heap, NOT the stack, or you will corrupt memory with this call.
///
void OTPseudonym::AddMail(OTMessage & theMessage) // a mail message is a form of transaction, transported via Nymbox
{
	m_dequeMail.push_front(&theMessage);
}

/// return the number of mail items available for this Nym.
//
int OTPseudonym::GetMailCount()
{
	return static_cast<int> (m_dequeMail.size());
}

// Look up a piece of mail by index.
// If it is, return a pointer to it, otherwise return NULL.
OTMessage * OTPseudonym::GetMailByIndex(const int nIndex)
{
	const unsigned int uIndex = nIndex;
	
	// Out of bounds.
	if (m_dequeMail.empty()	||
		(nIndex < 0)		|| (uIndex >= m_dequeMail.size()))
		return NULL;
	
	return m_dequeMail.at(nIndex);	
}


bool OTPseudonym::RemoveMailByIndex(const int nIndex) // if false, mail index was bad.
{
	const unsigned int uIndex = nIndex;
	
	// Out of bounds.
	if (m_dequeMail.empty()	||
		(nIndex < 0)		|| (uIndex >= m_dequeMail.size()))
		return false;
	
	// -----------------------
	
	OTMessage * pMessage = m_dequeMail.at(nIndex);
	
	OT_ASSERT(NULL != pMessage);
	
	m_dequeMail.erase(m_dequeMail.begin() + nIndex);
	
	delete pMessage;
	
	return true;		
}


void OTPseudonym::ClearMail()
{
	while (GetMailCount() > 0)
		RemoveMailByIndex(0);
}



// --------------------



/// Though the parameter is a reference (forcing you to pass a real object),
/// the Nym DOES take ownership of the object. Therefore it MUST be allocated
/// on the heap, NOT the stack, or you will corrupt memory with this call.
///
void OTPseudonym::AddOutmail(OTMessage & theMessage) // a mail message is a form of transaction, transported via Nymbox
{
	m_dequeOutmail.push_front(&theMessage);
}

/// return the number of mail items available for this Nym.
//
int OTPseudonym::GetOutmailCount()
{
	return static_cast<int> (m_dequeOutmail.size());
}

// Look up a transaction by transaction number and see if it is in the ledger.
// If it is, return a pointer to it, otherwise return NULL.
OTMessage * OTPseudonym::GetOutmailByIndex(const int nIndex)
{
	const unsigned int uIndex = nIndex;
	
	// Out of bounds.
	if (m_dequeOutmail.empty()	||
		(nIndex < 0)		|| (uIndex >= m_dequeOutmail.size()))
		return NULL;
	
	return m_dequeOutmail.at(nIndex);	
}


bool OTPseudonym::RemoveOutmailByIndex(const int nIndex) // if false, outmail index was bad.
{
	const unsigned int uIndex = nIndex;
	
	// Out of bounds.
	if (m_dequeOutmail.empty()	||
		(nIndex < 0)		|| (uIndex >= m_dequeOutmail.size()))
		return false;
	
	// -----------------------
	
	OTMessage * pMessage = m_dequeOutmail.at(nIndex);
	
	OT_ASSERT(NULL != pMessage);
	
	m_dequeOutmail.erase(m_dequeOutmail.begin() + nIndex);
	
	delete pMessage;
	
	return true;		
}


void OTPseudonym::ClearOutmail()
{
	while (GetOutmailCount() > 0)
		RemoveOutmailByIndex(0);
}



// --------------------



/// Though the parameter is a reference (forcing you to pass a real object),
/// the Nym DOES take ownership of the object. Therefore it MUST be allocated
/// on the heap, NOT the stack, or you will corrupt memory with this call.
///
void OTPseudonym::AddOutpayments(OTMessage & theMessage) // a payments message is a form of transaction, transported via Nymbox
{
	m_dequeOutpayments.push_front(&theMessage);
}

/// return the number of payments items available for this Nym.
//
int OTPseudonym::GetOutpaymentsCount()
{
	return static_cast<int> (m_dequeOutpayments.size());
}

// Look up a transaction by transaction number and see if it is in the ledger.
// If it is, return a pointer to it, otherwise return NULL.
OTMessage * OTPseudonym::GetOutpaymentsByIndex(const int nIndex)
{
	const unsigned int uIndex = nIndex;
	
	// Out of bounds.
	if (m_dequeOutpayments.empty()	||
		(nIndex < 0)		|| (uIndex >= m_dequeOutpayments.size()))
		return NULL;
	
	return m_dequeOutpayments.at(nIndex);	
}



int OTPseudonym::GetOutpaymentsIndexByTransNum(const long lTransNum)
{
    int32_t lOutpaymentsCount = this->GetOutpaymentsCount();
    
    for (int32_t lOutpaymentsIndex = 0; lOutpaymentsIndex < lOutpaymentsCount; ++lOutpaymentsIndex)
    {
        OTMessage * pOutpaymentMsg = this->GetOutpaymentsByIndex(lOutpaymentsIndex);
        if (NULL != pOutpaymentMsg)
        {
            OTString	strPayment;
            
            // There isn't any encrypted envelope this time, since it's my outPayments box.
            //
            if (pOutpaymentMsg->m_ascPayload.Exists() &&
                pOutpaymentMsg->m_ascPayload.GetString(strPayment) &&
                strPayment.Exists())
            {
                OTPayment thePayment(strPayment);
                // ---------------------------------------------
                // Let's see if it's the cheque we're looking for...
                //
                if (thePayment.IsValid() && thePayment.SetTempValues() &&
                    thePayment.HasTransactionNum(lTransNum))
                {
                    return static_cast<int>(lOutpaymentsIndex);
                }
            }
        }
    } // for
    // --------------------------------------------------------
    return (-1);
}



// if this function returns false, outpayments index was bad.
bool OTPseudonym::RemoveOutpaymentsByIndex(const int nIndex, bool bDeleteIt/*=true*/)
{
	const unsigned int uIndex = nIndex;
	
	// Out of bounds.
	if (m_dequeOutpayments.empty()	||
		(nIndex < 0)		|| (uIndex >= m_dequeOutpayments.size()))
		return false;
	// -----------------------
	OTMessage * pMessage = m_dequeOutpayments.at(nIndex);
	OT_ASSERT(NULL != pMessage);
	
	m_dequeOutpayments.erase(m_dequeOutpayments.begin() + nIndex);
	
    if (bDeleteIt)
        delete pMessage;
	
	return true;
}


void OTPseudonym::ClearOutpayments()
{
	while (GetOutpaymentsCount() > 0)
		RemoveOutpaymentsByIndex(0);
}



// --------------------

// Instead of a "balance statement", some messages require a "transaction statement".
// Whenever the number of transactions changes, you must sign the new list so you
// aren't responsible for cleared transactions, for example. Or so you server will
// allow you to take responsibility for a new transaction number (only if you've
// signed off on it!)
//
// There will have to be another version of this function for when you don't have
// a transaction (like a processNymbox!) Otherwise you would need a transaction number
// in order to do a processNymbox. This function therefore is available in that incarnation
// even when you don't have a transaction number. It'll just attach the balance item to
// the message directly.
//
OTItem * OTPseudonym::GenerateTransactionStatement(const OTTransaction & theOwner)
{
	if ( (theOwner.GetUserID() != m_nymID) )
	{
		OTLog::Error("Transaction has wrong owner in OTPseudonym::GenerateTransactionStatement (expected to match nym).\n");
		return NULL;
	}
	// ---------------------------------------------------------
	// theOwner is the depositPaymentPlan, activateSmartContract, or marketOffer that triggered the need for this transaction statement.
	// since it uses up a transaction number, I will be sure to remove that one from my list before signing the list.
	OTItem * pBalanceItem = OTItem::CreateItemFromTransaction(theOwner, OTItem::transactionStatement); // <=== transactionStatement type, with user ID, server ID, transaction ID.
	
	// The above has an ASSERT, so this this will never actually happen.
	if (NULL == pBalanceItem)
		return NULL;
	
	// --------------------------------------------------------
	// COPY THE ISSUED TRANSACTION NUMBERS FROM THE NYM
	
	OTPseudonym theMessageNym;
	
	theMessageNym.HarvestIssuedNumbers(theOwner.GetPurportedServerID(),
                                       *this /*unused in this case, not saving to disk*/, *this, false); // bSave = false;
	// ---------------------------------------------------------
    switch (theOwner.GetType()) 
    {
        case OTTransaction::cancelCronItem:
            if (theOwner.GetTransactionNum() > 0)
            {
                theMessageNym.RemoveIssuedNum(theOwner.GetRealServerID(), theOwner.GetTransactionNum());  // a transaction number is being used, and REMOVED from my list of responsibility,
                theMessageNym.RemoveTransactionNum(theOwner.GetRealServerID(), theOwner.GetTransactionNum()); // so I want the new signed list to reflect that number has been REMOVED.
            }
            break;
            
            // Transaction Statements usually only have a transaction number in the case of market offers and
            // payment plans, in which case the number should NOT be removed, and remains in play until
            // final closure from Cron.
        case OTTransaction::marketOffer:
        case OTTransaction::paymentPlan:
        case OTTransaction::smartContract:
        default:
            break;
    }
	// ---------------------------------------------------------
	// What about cases where no number is being used? (Such as processNymbox)
	// Perhaps then if this function is even called, it's with a 0-number transaction, in which 
	// case the above Removes probably won't hurt anything.  Todo.
	
	OTString	strMessageNym(theMessageNym); // Okay now we have the transaction numbers in this MessageNym string.
	
	pBalanceItem->SetAttachment(strMessageNym);	// <======== This is where the server will read the transaction numbers from (A nym in item.m_ascAttachment)
	// ---------------------------------------------------------
	pBalanceItem->SignContract(*this); // <=== Sign, save, and return. OTTransactionType needs to weasel in a "date signed" variable.
	pBalanceItem->SaveContract();
	
	return pBalanceItem;	
}

// ---------------------------------

bool OTPseudonym::Savex509CertAndPrivateKeyToString(OTString & strOutput, const OTString * pstrReason/*=NULL*/)
{
    return m_pkeypair->SaveCertAndPrivateKeyToString(strOutput, pstrReason);
}

// ---------------------------------

bool OTPseudonym::Savex509CertAndPrivateKey(bool bCreateFile/*=true*/,
                                            const OTString * pstrReason/*=NULL*/)
{
    const char * szFunc = "OTPseudonym::Savex509CertAndPrivateKey";
    // ---------------------------------------
    OTString    strOutput;
    const bool  bSuccess = m_pkeypair->SaveAndReloadBothKeysFromTempFile(&strOutput, pstrReason);
	// ---------------------------------------
    //	
	// At this point, the Nym's private key is set, and its public key is also set.
	// So the object in memory is good to go.
	// Now we just need to create some files, especially where the keys are stored,
	// since the Nym normally never writes to those files (just reads.)
	//
	if (bSuccess)
	{
		// ------------------------------------------
        if (false == this->SetIdentifierByPubkey())
        {
			OTLog::vError("%s: Error calculating Nym ID (as a digest of Nym's public key.)\n", szFunc);
			return false;	
        }
        // ---------------------------------------
		const OTString strFilenameByID(m_nymID);
		// ---------------------------------------
        if (bCreateFile &&
            (false == OTDB::StorePlainString(strOutput.Get(),
                                             OTFolders::Cert().Get(),
                                             strFilenameByID.Get()))) // Store as actual Nym ID this time instead of temp.nym
		{
			OTLog::vError("%s: Failure storing cert for new nym: %s\n", szFunc, strFilenameByID.Get());
			return false;
		}
	}
	
	return bSuccess;
}



// use this to actually generate a new key pair and assorted nym files.
//
bool OTPseudonym::GenerateNym(int  nBits/*=1024*/,
                              bool bCreateFile/*=true*/, // By default, it creates the various nym files and certs in local storage. (Pass false when creating a temp Nym, like for OTPurse.)
                              const std::string str_id_source   /*=""*/,
                              const std::string str_alt_location/*=""*/)
{
	// ---------------------------------------------------------------
    OT_ASSERT(NULL != m_pkeypair);
    // ---------------------------------------------------------------
    if (m_pkeypair->MakeNewKeypair(nBits))
    {
        OTString strSource     (str_id_source),
                 strAltLocation(str_alt_location);
        // ---------------------------------------------------------------
        this->SetNymIDSource(strSource);
        this->SetAltLocation(strAltLocation);
        // ---------------------------------------------------------------
        OTString strReason("Creating new Nym.");
        bool bSaved = this->Savex509CertAndPrivateKey(bCreateFile, &strReason);  // Todo: remove this. Credentials code will supercede.        
        // ---------------------------------------------------------------
        if (bSaved && bCreateFile)
        {		
            bSaved = this->SaveSignedNymfile(*this); // Now we'll generate the NymFile as well! (bCreateFile will be false for temp Nyms..)
        }
        
        if (bCreateFile && !bSaved)
            OTLog::vError("%s: Failed trying to save new Nym's cert or nymfile.\n", __FUNCTION__);
        else
        {
            // NEW CREDENTIALS CODE!
            // We've added a parameter to this function so you can pass in the SOURCE for
            // the Nym (which is what is hashed to produce the NymID.) The source could be a Bitcoin
            // address, a URL, the Subject/Issuer DN info from a traditionally-issued certificate authority,
            // or a public key. (OT originally was written to hash a public key to form the NymID -- so we
            // will just continue to support that as an option.)
            //
            // If the SOURCE parameter is not passed, we will assume by default that the Nym uses its own
            // public key as its source. This will become the first master credential, which can then be used
            // to issue keyCredentials and other types of subCredentials.
            //
            OTString strMasterCredID;
            
            const bool bAddedMaster = this->AddNewMasterCredential(strMasterCredID,
                                                                   (str_id_source.size() > 0) ? &strSource : NULL,
                                                                   nBits);

            if (bAddedMaster && strMasterCredID.Exists() && (this->GetMasterCredentialCount() > 0))
            {
                const OTIdentifier theMasterCredID(strMasterCredID);
                const bool bAddedSubkey = this->AddNewSubkey(theMasterCredID);

                if (bAddedSubkey)
                {
                    bSaved = this->SaveCredentialList();
                }
                else
                {
                    bSaved = false;
                    OTLog::vError("%s: Failed trying to add new keyCredential to new Master credential.\n",
                                  __FUNCTION__);
                }
            }
            else
            {
                bSaved = false;
                OTLog::vError("%s: Failed trying to add new master credential to new Nym.\n",
                              __FUNCTION__);
            }
        }
        
        return bSaved;
    }
    // ---------------------------------------------------------------
    return false;
}


bool OTPseudonym::SetIdentifierByPubkey()
{
    OT_ASSERT(NULL != m_pkeypair);
    // ---------------------------------------------------------------
    const bool bCalculated = m_pkeypair->CalculateID(m_nymID); // OTAsymmetricKey::CalculateID only works with public keys.
    
	if (!bCalculated)
	{
		OTLog::vError("%s: Error calculating Nym ID in OTAsymmetricKey::CalculateID().\n", __FUNCTION__);
		return false;	
	}
	
	return true;
}



// If an ID is passed in, that means remove all numbers FOR THAT SERVER ID.
// If passed in, and current map doesn't match, then skip it (continue).

#ifndef CLEAR_MAP_AND_DEQUE
#define CLEAR_MAP_AND_DEQUE(the_map) \
    \
FOR_EACH(mapOfTransNums, the_map) \
{ \
if ((NULL != pstrServerID) && (str_ServerID != it->first)) \
        continue; \
    dequeOfTransNums * pDeque = (it->second); \
    OT_ASSERT(NULL != pDeque); \
    if (!(pDeque->empty())) \
        pDeque->clear(); \
}
#endif // CLEAR_MAP_AND_DEQUE





// Sometimes for testing I need to clear out all the transaction numbers from a nym.
// So I added this method to make such a thing easy to do.
//
void OTPseudonym::RemoveAllNumbers(const OTString * pstrServerID/*=NULL*/, const bool bRemoveHighestNum/*=true*/) // Some callers don't want to wipe the highest num. Some do.
{
	const std::string str_ServerID((NULL != pstrServerID) ? pstrServerID->Get() : "");		

    // --------------------------
    // These use str_ServerID (above)
    //
    CLEAR_MAP_AND_DEQUE(m_mapIssuedNum)
    CLEAR_MAP_AND_DEQUE(m_mapTransNum)
    CLEAR_MAP_AND_DEQUE(m_mapTentativeNum)
    CLEAR_MAP_AND_DEQUE(m_mapAcknowledgedNum)
    
    // ----------------------------
	
    std::list<mapOfHighestNums::iterator> listOfHighestNums;
    std::list<mapOfIdentifiers::iterator> listOfNymboxHash;
    std::list<mapOfIdentifiers::iterator> listOfInboxHash;
    std::list<mapOfIdentifiers::iterator> listOfOutboxHash;
    std::list<mapOfIdentifiers::iterator> listOfRecentHash;
    
	if (bRemoveHighestNum)
	{
		FOR_EACH(mapOfHighestNums, m_mapHighTransNo)
		{
			if ((NULL != pstrServerID) && (str_ServerID != it->first)) // If passed in, and current it doesn't match, then skip it (continue).
				continue;
			
            listOfHighestNums.push_back(it);
//			m_mapHighTransNo.erase(it);		
		}	
	}	
    // ----------------------------
    
    FOR_EACH(mapOfIdentifiers, m_mapNymboxHash)
    {
        if ((NULL != pstrServerID) && (str_ServerID != it->first)) // If passed in, and current it doesn't match, then skip it (continue).
            continue;
        
        listOfNymboxHash.push_back(it);
//      m_mapNymboxHash.erase(it);
    }	
    // ----------------------------
    // This is mapped to acct_id, not server_id.
    // (So we just wipe them all.)
    //
    FOR_EACH(mapOfIdentifiers, m_mapInboxHash)
    {
        listOfInboxHash.push_back(it);
//      m_mapInboxHash.erase(it);
    }	
    // ----------------------------
    // This is mapped to acct_id, not server_id.
    // (So we just wipe them all.)
    //    
    FOR_EACH(mapOfIdentifiers, m_mapOutboxHash)
    {
        listOfOutboxHash.push_back(it);
//      m_mapOutboxHash.erase(it);
    }	
    // ----------------------------
    
    FOR_EACH(mapOfIdentifiers, m_mapRecentHash)
    {
        if ((NULL != pstrServerID) && (str_ServerID != it->first)) // If passed in, and current it doesn't match, then skip it (continue).
            continue;
        
        listOfRecentHash.push_back(it);
//      m_mapRecentHash.erase(it);		
    }
    
    // ----------------------------------------------------------------

    while (listOfHighestNums.size() > 0)
    {
        m_mapHighTransNo.erase(listOfHighestNums.back());
        listOfHighestNums.pop_back();
    }
    while (listOfNymboxHash.size() > 0)
    {
        m_mapNymboxHash.erase(listOfNymboxHash.back());
        listOfNymboxHash.pop_back();
    }
    while (listOfInboxHash.size() > 0)
    {
        m_mapInboxHash.erase(listOfInboxHash.back());
        listOfInboxHash.pop_back();
    }
    while (listOfOutboxHash.size() > 0)
    {
        m_mapOutboxHash.erase(listOfOutboxHash.back());
        listOfOutboxHash.pop_back();
    }
    while (listOfRecentHash.size() > 0)
    {
        m_mapRecentHash.erase(listOfRecentHash.back());
        listOfRecentHash.pop_back();
    }
}




//	OTIdentifier        m_NymboxHash;       // (Server-side) Hash of the Nymbox
//  mapOfIdentifiers    m_mapNymboxHash;    // (Client-side) Hash of Nymbox (OTIdentifier) mapped by ServerID (std::string)


bool OTPseudonym::GetNymboxHashServerSide(const OTIdentifier & theServerID, OTIdentifier & theOutput)    // server-side
{
    if (m_NymboxHash.IsEmpty())
    {
        OTLedger theNymbox(m_nymID, m_nymID, theServerID);
        
        if (theNymbox.LoadNymbox() && theNymbox.CalculateNymboxHash(theOutput))
            return true;
    }
    
    return false;
}


void OTPseudonym::SetNymboxHashServerSide(const OTIdentifier & theInput)    // server-side
{
    m_NymboxHash = theInput;
}



// ---------------------------------------------------------

bool OTPseudonym::GetNymboxHash(const std::string & server_id, OTIdentifier & theOutput) const // client-side
{
    return this->GetHash(m_mapNymboxHash, server_id, theOutput);
}


bool OTPseudonym::SetNymboxHash(const std::string & server_id, const OTIdentifier & theInput) // client-side
{
    return this->SetHash(m_mapNymboxHash, server_id, theInput);
}

// ---------------------------------------------------------

bool OTPseudonym::GetRecentHash(const std::string & server_id, OTIdentifier & theOutput) const // client-side
{
    return this->GetHash(m_mapRecentHash, server_id, theOutput);
}


bool OTPseudonym::SetRecentHash(const std::string & server_id, const OTIdentifier & theInput) // client-side
{
    return this->SetHash(m_mapRecentHash, server_id, theInput);
}


// ---------------------------------------------------------

bool OTPseudonym::GetInboxHash(const std::string & acct_id, OTIdentifier & theOutput) const // client-side
{
    return this->GetHash(m_mapInboxHash, acct_id, theOutput);
}


bool OTPseudonym::SetInboxHash(const std::string & acct_id, const OTIdentifier & theInput) // client-side
{
    return this->SetHash(m_mapInboxHash, acct_id, theInput);
}


// ---------------------------------------------------------

bool OTPseudonym::GetOutboxHash(const std::string & acct_id, OTIdentifier & theOutput) const // client-side
{
    return this->GetHash(m_mapOutboxHash, acct_id, theOutput);
}


bool OTPseudonym::SetOutboxHash(const std::string & acct_id, const OTIdentifier & theInput) // client-side
{
    return this->SetHash(m_mapOutboxHash, acct_id, theInput);
}

// ---------------------------------------------------------

bool OTPseudonym::GetHash(const mapOfIdentifiers & the_map, const std::string & str_id, OTIdentifier & theOutput) const // client-side
{
	bool bRetVal = false; // default is false: "No, I didn't find a hash for that id."
	theOutput.Release();
    
	// The Pseudonym has a map of its recent hashes, one for each server (nymbox) or account (inbox/outbox).
	// For Server Bob, with this Pseudonym, I might have hash lkjsd987345lkj.
	// For but Server Alice, I might have hash 98345jkherkjghdf98gy.
    // (Same Nym, but different hash for each server, as well as inbox/outbox hashes for each asset acct.)
	// 
	// So let's loop through all the hashes I have, and if the ID on the map passed in
	// matches the [server|acct] ID that was passed in, then return TRUE.
    //
	FOR_EACH_CONST(mapOfIdentifiers, the_map)
	{
		if ( str_id == it->first )
		{			
			// The call has succeeded
			bRetVal     = true;
            theOutput   = it->second;
			break;
		}
	}
	
	return bRetVal;    
}

bool OTPseudonym::SetHash(mapOfIdentifiers & the_map, const std::string & str_id, const OTIdentifier & theInput) // client-side
{
    bool bSuccess = false;
    
    mapOfIdentifiers::iterator find_it = the_map.find(str_id);
    
    if (the_map.end() != find_it) // found something for that str_id
	{
        // The call has succeeded
        the_map.erase(find_it);
        the_map[str_id] = theInput;
        bSuccess = true;
	}
	
	// If I didn't find it in the list above (whether the list is empty or not....)
	// that means it does not exist. (So create it.)
    //
	if (!bSuccess)
	{
		the_map[str_id] = theInput;
		bSuccess = true;
	}
//	if (bSuccess)
//	{
//		SaveSignedNymfile(SIGNER_NYM);
//	}
    
    return bSuccess;
}



// ---------------------------------------------------------



void OTPseudonym::RemoveReqNumbers(const OTString * pstrServerID/*=NULL*/)
{
	const std::string str_ServerID((NULL != pstrServerID) ? pstrServerID->Get() : "");		
	
	FOR_EACH(mapOfRequestNums, m_mapRequestNum)
	{
		if ((NULL != pstrServerID) && (str_ServerID != it->first)) // If passed in, and current it doesn't match, then skip it (continue).
			continue;

		m_mapRequestNum.erase(it);		
	}	
}



// You can't go using a Nym at a certain server, if it's not registered there...
// BTW -- if you have never called GetRequest(), then this will wrongly return false!
// But as long as you call getRequest() upon successsful registration (or whenever) this
// function will return an accurate answer after that point, and forever.
//
bool OTPseudonym::IsRegisteredAtServer(const OTString & strServerID)
{
	bool bRetVal		= false; // default is return false: "No, I'm NOT registered at that Server."
	std::string strID	= strServerID.Get();
	
	// The Pseudonym has a map of the request numbers for different servers.
	// For Server Bob, with this Pseudonym, I might be on number 34.
	// For but Server Alice, I might be on number 59.
	// 
	// So let's loop through all the numbers I have, and if the server ID on the map
	// matches the Server ID that was passed in, then return TRUE.
	FOR_EACH(mapOfRequestNums, m_mapRequestNum)
	{
		if ( strID == it->first )
		{			
			// The call has succeeded
			bRetVal = true;
			
			break;
		}
	}
	
	return bRetVal;	
}


// Removes Request Num for specific server
// (Like if Nym has deleted his account on that server...)
// Caller is responsible to save Nym after this.
//
bool OTPseudonym::UnRegisterAtServer(const OTString & strServerID)
{
	bool bRetVal		= false; // default is return false: "No, I'm NOT registered at that Server."
	std::string strID	= strServerID.Get();
	
	// The Pseudonym has a map of the request numbers for different servers.
	// For Server Bob, with this Pseudonym, I might be on number 34.
	// For but Server Alice, I might be on number 59.
	// 
	// So let's loop through all the numbers I have, and if the server ID on the map
	// matches the Server ID that was passed in, then delete that one.
    //
	FOR_EACH(mapOfRequestNums, m_mapRequestNum)
	{
		if ( strID == it->first )
		{			
			// The call has succeeded
			bRetVal = true;
            m_mapRequestNum.erase(it);
			break;
		}
	}
	
	return bRetVal;	
}


// -----------------------------------------------------

#ifndef WIPE_MAP_AND_DEQUE
#define WIPE_MAP_AND_DEQUE(the_map) \
while (!the_map.empty()) \
{ \
    dequeOfTransNums * pDeque = the_map.begin()->second; \
    OT_ASSERT(NULL != pDeque); \
    the_map.erase(the_map.begin()); \
    delete pDeque; pDeque = NULL; \
}
#endif // WIPE_MAP_AND_DEQUE


void OTPseudonym::ReleaseTransactionNumbers()
{
    WIPE_MAP_AND_DEQUE(m_mapTransNum)
    WIPE_MAP_AND_DEQUE(m_mapIssuedNum)
    WIPE_MAP_AND_DEQUE(m_mapTentativeNum)
    WIPE_MAP_AND_DEQUE(m_mapAcknowledgedNum)
}
// -----------------------------------------------------





/*
 ResyncWithServer:
    // ----------------------------------------------------
--	OTIdentifier        m_NymboxHash;       // (Server-side) Hash of the Nymbox
    // ----------------------------------------------------    
--    mapOfIdentifiers    m_mapNymboxHash;    // (Client-side) Hash of latest DOWNLOADED Nymbox (OTIdentifier) mapped by ServerID (std::string)
--    mapOfIdentifiers    m_mapRecentHash;    // (Client-side) Hash of Nymbox according to Server, based on some recent reply. (May be newer...)
    // ----------------------------------------------------
--    mapOfIdentifiers    m_mapInboxHash;  
--    mapOfIdentifiers    m_mapOutboxHash; 
    // ----------------------------------------------------    
--	dequeOfMail		m_dequeMail;	// Any mail messages received by this Nym. (And not yet deleted.)
--	dequeOfMail		m_dequeOutmail;	// Any mail messages sent by this Nym. (And not yet deleted.)
--	dequeOfMail		m_dequeOutpayments;	// Any outoing payments sent by this Nym. (And not yet deleted.) (payments screen.)
    // -----------------------------------------------
--	mapOfRequestNums m_mapRequestNum;	// Whenever this user makes a request to a transaction server
 
**	mapOfTransNums	 m_mapTransNum;	// Each Transaction Request must be accompanied by a fresh transaction #,
**	mapOfTransNums	 m_mapIssuedNum;	// If the server has issued me (1,2,3,4,5) and I have already used 1-3,
**	mapOfTransNums	 m_mapTentativeNum; 
 
**  mapOfHighestNums m_mapHighTransNo;  // Mapped, a single long to each server (just like request numbers are.)
	// -----------------------------
--    mapOfTransNums	m_mapAcknowledgedNum; // request numbers are stored here.
	// -----------------------------
    // (SERVER side)
--    std::set<long> m_setOpenCronItems; // Until these Cron Items are closed out, the server-side Nym keeps a list of them handy.
    // -----------------------------
    // (SERVER side)
    // Using strings here to avoid juggling memory crap.
--    std::set<std::string> m_setAccounts; // A list of asset account IDs. Server side only (client side uses wallet; has multiple servers.)
    // ------------------------------------------
    // (SERVER side.)
--	long	m_lUsageCredits;	// Server-side. The usage credits available for this Nym. Infinite if negative.
 // -----------------------------
 */


/*
 OTPseudonym::RemoveAllNumbers affects (**):  (-- means doesn't affect)
 // ----------------------------------------------------
--	OTIdentifier        m_NymboxHash;       // (Server-side) Hash of the Nymbox
 // ----------------------------------------------------
**    mapOfIdentifiers    m_mapNymboxHash;    // (Client-side) Hash of latest DOWNLOADED Nymbox (OTIdentifier) mapped by ServerID (std::string)
**    mapOfIdentifiers    m_mapRecentHash;    // (Client-side) Hash of Nymbox according to Server, based on some recent reply. (May be newer...)
 // ----------------------------------------------------
**    mapOfIdentifiers    m_mapInboxHash; 
**    mapOfIdentifiers    m_mapOutboxHash;   
 // ----------------------------------------------------
--	dequeOfMail		m_dequeMail;	// Any mail messages received by this Nym. (And not yet deleted.)
--	dequeOfMail		m_dequeOutmail;	// Any mail messages sent by this Nym. (And not yet deleted.)
--	dequeOfMail		m_dequeOutpayments;	// Any outoing payments sent by this Nym. (And not yet deleted.) (payments screen.)
    // -----------------------------------------------
--    mapOfRequestNums m_mapRequestNum;
 
**	mapOfTransNums   m_mapTransNum;
**	mapOfTransNums   m_mapIssuedNum;
**	mapOfTransNums	 m_mapTentativeNum; 

**    mapOfHighestNums m_mapHighTransNo;  // Mapped, a single long to each server (just like request numbers are.)
 // ----------------------------- 
**  mapOfTransNums	 m_mapAcknowledgedNum;  // request nums are stored.
	// -----------------------------
    // (SERVER side)
--    std::set<long> m_setOpenCronItems; // Until these Cron Items are closed out, the server-side Nym keeps a list of them handy.
 // ----------------------------------------------------
    // (SERVER side)
--    std::set<std::string> m_setAccounts; // A list of asset account IDs. Server side only (client side uses wallet; has multiple servers.)
    // ------------------------------------------
    // (SERVER side.)
--	long	m_lUsageCredits;	// Server-side. The usage credits available for this Nym. Infinite if negative.
 // ----------------------------------------------------
 
 
 CLEAR_MAP_AND_DEQUE(m_mapIssuedNum)
 CLEAR_MAP_AND_DEQUE(m_mapTransNum)
 CLEAR_MAP_AND_DEQUE(m_mapTentativeNum)
 CLEAR_MAP_AND_DEQUE(m_mapAcknowledgedNum)
 
 m_mapHighTransNo.erase(listOfHighestNums.back());
 m_mapNymboxHash.erase(listOfNymboxHash.back());
 m_mapRecentHash.erase(listOfRecentHash.back());

*/

// -----------------------------------------------------
//
// ** ResyncWithServer **
//
// Not for normal use! (Since you should never get out of sync with the server in the first place.)
// However, in testing, or if some bug messes up some data, or whatever, and you absolutely need to
// re-sync with a server, and you trust that server not to lie to you, then this function will do the trick.
// NOTE: Before calling this, you need to do a getNymbox() to download the latest Nymbox, and you need to do
// a createUserAccount() to download the server's copy of your Nym. You then need to load that Nymbox from
// local storage, and you need to load the server's message Nym out of the @createUserAccount reply, so that
// you can pass both of those objects into this function, which must assume that those pieces were already done
// just prior to this call.
//
bool OTPseudonym::ResyncWithServer(OTLedger & theNymbox, OTPseudonym & theMessageNym)
{
	bool bSuccess = true;
	
	// --------------------------------------
	const OTIdentifier &	theServerID = theNymbox.GetRealServerID();
	const OTString			strServerID(theServerID);
	const OTString			strNymID(m_nymID);

	const int nIssuedNumCount	= theMessageNym.GetIssuedNumCount(theServerID);
	const int nTransNumCount	= theMessageNym.GetTransactionNumCount(theServerID);

	// --------------------------------------
	// Remove all issued, transaction, and tentative numbers for a specific server ID,
    // as well as all acknowledgedNums, and the highest transaction number for that serverID,
	// from *this nym. Leave our record of the highest trans num received from that server,
	// since we will want to just keep it when re-syncing. (Server doesn't store that anyway.)
	//
	this->RemoveAllNumbers(&strServerID, false); // bRemoveHighestNum=true by default. But in this case, I keep it.
	
	// --------------------------------------
	// Any issued or trans numbers we add to *this from theMessageNym, are also added here so 
	// they can be used to update the "highest number" record (at the bottom of this function.)
	//
	std::set<long> setTransNumbers;  

	// ***************************************************************************
	// Now that *this has no issued or transaction numbers for theServerID, we add
	// them back again from theMessageNym. (So they will match, and be 'N SYNC!!!)
	//
	// Copy the issued and transaction numbers from theMessageNym onto *this.
	// 
	for(int n1 = 0; n1 < nIssuedNumCount; ++n1)
	{
		const long lNum = theMessageNym.GetIssuedNum(theServerID, n1);

		if (false == this->AddIssuedNum(strServerID, lNum))		// Add to list of numbers that haven't been closed yet.
		{
			OTLog::vError("OTPseudonym::ResyncWithServer: Failed trying to add IssuedNum (%ld) onto *this nym: %s, for server: %s\n",
						  lNum, strNymID.Get(), strServerID.Get());
			bSuccess = false;
		}
		else
		{
			setTransNumbers.insert(lNum);
			// ---------------------------
			OTLog::vOutput(1, "OTPseudonym::ResyncWithServer: Added IssuedNum (%ld) onto *this nym: %s, for server: %s \n",
						   lNum, strNymID.Get(), strServerID.Get());
		}		
	}
	// --------------------------------------
	for(int n2 = 0; n2 < nTransNumCount; ++n2)
	{
		const long lNum = theMessageNym.GetTransactionNum(theServerID, n2);
		
		if (false == this->AddTransactionNum(strServerID, lNum))		// Add to list of available-to-use numbers.
		{
			OTLog::vError("OTPseudonym::ResyncWithServer: Failed trying to add TransactionNum (%ld) onto *this nym: %s, for server: %s\n",
						  lNum, strNymID.Get(), strServerID.Get());
			bSuccess = false;
		}
		else
		{
			setTransNumbers.insert(lNum);
			// ---------------------------
			OTLog::vOutput(1, "OTPseudonym::ResyncWithServer: Added TransactionNum (%ld) onto *this nym: %s, for server: %s \n",
						   lNum, strNymID.Get(), strServerID.Get());
		}
	}
	// ***************************************************************************
	// We already cleared all tentative numbers from *this (above in 
	// RemoveAllNumbers). Next, loop through theNymbox and add Tentative numbers 
	// to *this based on each successNotice in the Nymbox. This way, when the notices
    // are processed, they will succeed because the Nym will believe he was expecting them.
	//
	FOR_EACH(mapOfTransactions, theNymbox.GetTransactionMap())
	{
		OTTransaction * pTransaction = (*it).second;
		OT_ASSERT(NULL != pTransaction);		
//		OTString strTransaction(*pTransaction);
//		OTLog::vError("TRANSACTION CONTENTS:\n%s\n", strTransaction.Get());
		
		// (a new; ALREADY just added transaction number.)
		if ((OTTransaction::successNotice != pTransaction->GetType())) // if !successNotice 
			continue;
		// -------------
		const long lNum = pTransaction->GetReferenceToNum(); // successNotice is inRefTo the new transaction # that should be on my tentative list.
		
		if (false == this->AddTentativeNum(strServerID, lNum)) // Add to list of tentatively-being-added numbers.
		{
			OTLog::vError("OTPseudonym::ResyncWithServer: Failed trying to add TentativeNum (%ld) onto *this nym: %s, for server: %s\n",
						  lNum, strNymID.Get(), strServerID.Get());
			bSuccess = false;
		}
		else
			OTLog::vOutput(1, "OTPseudonym::ResyncWithServer: Added TentativeNum (%ld) onto *this nym: %s, for server: %s \n",
						   lNum, strNymID.Get(), strServerID.Get());
		// There's no "else insert to setTransNumbers" here, like the other two blocks above.
		// Why not? Because setTransNumbers is for updating the Highest Trans Num record on this Nym,
		// and the Tentative Numbers aren't figured into that record until AFTER they are accepted
		// from the Nymbox. So I leave them out, since this function is basically setting us up to
		// successfully process the Nymbox, which will then naturally update the highest num record
		// based on the tentatives, as it's removing them from the tentative list and adding them to
		// the "available" transaction list (and issued.)
		
	} // FOR_EACH (Nymbox)
	// ***************************************************************************
	
	const std::string strID	= strServerID.Get();
	
	FOR_EACH_IT(mapOfHighestNums, this->m_mapHighTransNo, it_high_num)
	{
		if ( strID == it_high_num->first )	// We found it!
		{
            // -------------------------
			// See if any numbers on the set are higher, and if so, update the record to match.
			//
			FOR_EACH(std::set<long>, setTransNumbers)
			{
				const long lTransNum = (*it);
				// --------------------------------
				// Grab a copy of the old highest trans number
				const long lOldHighestNumber = it_high_num->second;
				// --------------------------------
				if (lTransNum > lOldHighestNumber) // Did we find a bigger one?
				{
					// Then update the Nym's record!
					this->m_mapHighTransNo[it_high_num->first] = lTransNum; 
					OTLog::vOutput(1, "OTPseudonym::ResyncWithServer: Updated HighestNum (%ld) record on *this nym: %s, for server: %s \n",
								   lTransNum, strNymID.Get(), strServerID.Get());	
				}
			}
            // -------------------------
			// We only needed to do this for the one server, so we can break now.
			break;
		}
	}
	// ***************************************************************************
	
	return (this->SaveSignedNymfile(*this) && bSuccess);
}




/*
typedef std::deque<long>							dequeOfTransNums;
typedef std::map<std::string, dequeOfTransNums *>	mapOfTransNums;	
*/


// Verify whether a certain transaction number appears on a certain list.
//
bool OTPseudonym::VerifyGenericNum(mapOfTransNums & THE_MAP, const OTString & strServerID, const long & lTransNum)
{
	std::string strID	= strServerID.Get();
	
	// The Pseudonym has a deque of transaction numbers for each servers.
	// These deques are mapped by Server ID.
	// 
	// So let's loop through all the deques I have, and if the server ID on the map
	// matches the Server ID that was passed in, then find the transaction number on
	// that list, and then return true. Else return false.
	//
	FOR_EACH(mapOfTransNums, THE_MAP)
	{
		// if the ServerID passed in matches the serverID for the current deque
		if ( strID == it->first )
		{
			dequeOfTransNums * pDeque = (it->second);
			OT_ASSERT(NULL != pDeque);
			
			if (!(pDeque->empty())) // there are some numbers for that server ID
			{
				// Let's loop through them and see if the culprit is there
				for (unsigned i = 0; i < pDeque->size(); i++)
				{
					// Found it!
					if (lTransNum == pDeque->at(i))
					{
						return true;
					}
				}
			}
			break;			
		}
	}
	
	return false;	
}

// On the server side: A user has submitted a specific transaction number. 
// Remove it from his file so he can't use it again.
bool OTPseudonym::RemoveGenericNum(mapOfTransNums & THE_MAP, OTPseudonym & SIGNER_NYM, const OTString & strServerID, const long & lTransNum)
{
	bool bRetVal = RemoveGenericNum(THE_MAP, strServerID, lTransNum);
	
	if (bRetVal)
	{
		SaveSignedNymfile(SIGNER_NYM);
	}
	
	return bRetVal;
}

// This function is a little lower level, and doesn't worry about saving. Used internally.
// Returns true IF it successfully finds and removes the number. Otherwise returns false.
//
bool OTPseudonym::RemoveGenericNum(mapOfTransNums & THE_MAP, const OTString & strServerID, const long & lTransNum)
{
	bool bRetVal = false;
	std::string strID	= strServerID.Get();
	
	// The Pseudonym has a deque of transaction numbers for each servers.
	// These deques are mapped by Server ID.
	// 
	// So let's loop through all the deques I have, and if the server ID on the map
	// matches the Server ID that was passed in, then find the transaction number on
	// that list, and then remove it, and return true. Else return false.
	//
	FOR_EACH(mapOfTransNums, THE_MAP)
	{
		// if the ServerID passed in matches the serverID for the current deque
		if ( strID == it->first )
		{
			dequeOfTransNums * pDeque = (it->second);
			
			OT_ASSERT(NULL != pDeque);
			
			if (!(pDeque->empty())) // there are some numbers for that server ID
			{
				// Let's loop through them and see if the culprit is there
				for (unsigned i = 0; i < pDeque->size(); i++)
				{
					// Found it!
					if (lTransNum == pDeque->at(i))
					{
						pDeque->erase(pDeque->begin() + i);
						bRetVal = true;
						break;
					}
				}
			}
			break;			
		}
	}
		
	return bRetVal;
}


// No signer needed for this one, and save is false.
// This version is ONLY for cases where we're not saving inside this function.
bool OTPseudonym::AddGenericNum(mapOfTransNums & THE_MAP, const OTString & strServerID, const long lTransNum) 
{
	bool bSuccessFindingServerID = false, bSuccess = false;
	std::string strID	= strServerID.Get();
	
	// The Pseudonym has a deque of transaction numbers for each server.
	// These deques are mapped by Server ID.
	// 
	// So let's loop through all the deques I have, and if the server ID on the map
	// matches the Server ID that was passed in, then add the transaction number.
	//
	FOR_EACH(mapOfTransNums, THE_MAP)
	{
		// if the ServerID passed in matches the serverID for the current deque
		if ( strID == it->first )
		{
			dequeOfTransNums * pDeque = (it->second);
			OT_ASSERT(NULL != pDeque);
			
			dequeOfTransNums::iterator iiii = std::find(pDeque->begin(), pDeque->end(), lTransNum);
			
			if (iiii == pDeque->end()) // Only add it if it's not already there. No duplicates!
				pDeque->push_front(lTransNum);
			
			bSuccess				= true;
			bSuccessFindingServerID	= true;
			
			break;			
		}
	}
	
	// Apparently there is not yet a deque stored for this specific serverID.
	// Fine. Let's create it then, and then add the transaction num to that new deque.
	if (!bSuccessFindingServerID)
	{
		dequeOfTransNums * pDeque = new dequeOfTransNums;
		
		OT_ASSERT(NULL != pDeque);
		
		THE_MAP[strID] = pDeque;
		pDeque->push_front(lTransNum);
		bSuccess = true;
	}
	
	return bSuccess;	
}


// Returns count of transaction numbers available for a given server.
//
int OTPseudonym::GetGenericNumCount(mapOfTransNums & THE_MAP, const OTIdentifier & theServerID) 
{
	int nReturnValue = 0;
	
	const OTString strServerID(theServerID);
	std::string strID	= strServerID.Get();
	
	dequeOfTransNums * pDeque = NULL;
	
	// The Pseudonym has a deque of transaction numbers for each server.
	// These deques are mapped by Server ID.
	// 
	// So let's loop through all the deques I have, and if the server ID on the map
	// matches the Server ID that was passed in, then we found the right server.
	FOR_EACH(mapOfTransNums, THE_MAP)
	{
		// if the ServerID passed in matches the serverID for the current deque
		if ( strID == it->first )
		{
			pDeque = (it->second);
			OT_ASSERT(NULL != pDeque);

			break;			
		}
	}
	
	// We found the right server, so let's count the transaction numbers
	// that this nym has already stored for it.
	if (NULL != pDeque)
	{		
		nReturnValue = static_cast<int> (pDeque->size());
	}
	
	return nReturnValue;	
}


// by index.
long OTPseudonym::GetGenericNum(mapOfTransNums & THE_MAP, const OTIdentifier & theServerID, int nIndex)
{
	long lRetVal = 0;
	
	const OTString strServerID(theServerID);
	std::string strID	= strServerID.Get();
	
	// The Pseudonym has a deque of numbers for each server.
	// These deques are mapped by Server ID.
	// 
	// So let's loop through all the deques I have, and if the server ID on the
	// maps matches the Server ID that was passed in, then find the number on
	// that list, and then return it.
	//
	FOR_EACH(mapOfTransNums, THE_MAP)
	{
		// if the ServerID passed in matches the serverID for the current deque
		if ( strID == it->first )
		{
			dequeOfTransNums * pDeque = (it->second);
			OT_ASSERT(NULL != pDeque);
			
			if (!(pDeque->empty())) // there are some numbers for that server ID
			{
				// Let's loop through them and see if the culprit is there
				for (unsigned i = 0; i < pDeque->size(); i++)
				{					
					// Found it!
					if ((unsigned)nIndex == i)
					{
						lRetVal = pDeque->at(i); // <==== Got the number here.
						break;
					}
				}
			}
			break;			
		}
	}
	
	return lRetVal;
}

// *************************************************************************************



// by index.
long OTPseudonym::GetTentativeNum(const OTIdentifier & theServerID, int nIndex)
{
	return GetGenericNum(m_mapTentativeNum, theServerID, nIndex);
}

// by index.
long OTPseudonym::GetIssuedNum(const OTIdentifier & theServerID, int nIndex)
{
	return GetGenericNum(m_mapIssuedNum, theServerID, nIndex);
}

// by index.
long OTPseudonym::GetTransactionNum(const OTIdentifier & theServerID, int nIndex)
{
	return GetGenericNum(m_mapTransNum, theServerID, nIndex);
}

// by index.
long OTPseudonym::GetAcknowledgedNum(const OTIdentifier & theServerID, int nIndex)
{
	return GetGenericNum(m_mapAcknowledgedNum, theServerID, nIndex);
}


// ------------------------------------

// TRANSACTION NUM

// On the server side: A user has submitted a specific transaction number. 
// Verify whether he actually has a right to use it.
bool OTPseudonym::VerifyTransactionNum(const OTString & strServerID, const long & lTransNum) // doesn't save
{
	return VerifyGenericNum(m_mapTransNum, strServerID, lTransNum);
}

// On the server side: A user has submitted a specific transaction number. 
// Remove it from his file so he can't use it again.
bool OTPseudonym::RemoveTransactionNum(OTPseudonym & SIGNER_NYM, const OTString & strServerID, const long & lTransNum)  // saves
{
	return RemoveGenericNum(m_mapTransNum, SIGNER_NYM, strServerID, lTransNum);
}

bool OTPseudonym::RemoveTransactionNum(const OTString & strServerID, const long & lTransNum) // doesn't save.
{
	return RemoveGenericNum(m_mapTransNum, strServerID, lTransNum);
}

// Returns count of transaction numbers available for a given server.
//
int OTPseudonym::GetTransactionNumCount(const OTIdentifier & theServerID)  
{
	return GetGenericNumCount(m_mapTransNum, theServerID);
}


// No signer needed for this one, and save is false.
// This version is ONLY for cases where we're not saving inside this function.
bool OTPseudonym::AddTransactionNum(const OTString & strServerID, const long lTransNum)  // doesn't save
{
	return AddGenericNum(m_mapTransNum, strServerID, lTransNum);
}


// ----------------------------------------------------------------------

// ISSUED NUM

// On the server side: A user has submitted a specific transaction number. 
// Verify whether it was issued to him and still awaiting final closing.
bool OTPseudonym::VerifyIssuedNum(const OTString & strServerID, const long & lTransNum)
{
	return VerifyGenericNum(m_mapIssuedNum, strServerID, lTransNum);
}

// On the server side: A user has accepted a specific receipt. 
// Remove it from his file so he's not liable for it anymore.
bool OTPseudonym::RemoveIssuedNum(OTPseudonym & SIGNER_NYM, const OTString & strServerID, const long & lTransNum) // saves
{
	return RemoveGenericNum(m_mapIssuedNum, SIGNER_NYM, strServerID, lTransNum);
}

bool OTPseudonym::RemoveIssuedNum(const OTString & strServerID, const long & lTransNum) // doesn't save
{
	return RemoveGenericNum(m_mapIssuedNum, strServerID, lTransNum);
}


// Returns count of transaction numbers not yet cleared for a given server.
//
int OTPseudonym::GetIssuedNumCount(const OTIdentifier & theServerID) 
{
	return GetGenericNumCount(m_mapIssuedNum, theServerID);
}


// No signer needed for this one, and save is false.
// This version is ONLY for cases where we're not saving inside this function.
bool OTPseudonym::AddIssuedNum(const OTString & strServerID, const long & lTransNum)  // doesn't save.
{
	return AddGenericNum(m_mapIssuedNum, strServerID, lTransNum);
}



// ----------------------------------------------------------------------

// TENTATIVE NUM

// On the server side: A user has submitted a specific transaction number. 
// Verify whether it was issued to him and still awaiting final closing.
bool OTPseudonym::VerifyTentativeNum(const OTString & strServerID, const long & lTransNum)
{
	return VerifyGenericNum(m_mapTentativeNum, strServerID, lTransNum);
}

// On the server side: A user has accepted a specific receipt. 
// Remove it from his file so he's not liable for it anymore.
bool OTPseudonym::RemoveTentativeNum(OTPseudonym & SIGNER_NYM, const OTString & strServerID, const long & lTransNum) // saves
{
	return RemoveGenericNum(m_mapTentativeNum, SIGNER_NYM, strServerID, lTransNum);
}

bool OTPseudonym::RemoveTentativeNum(const OTString & strServerID, const long & lTransNum) // doesn't save
{
	return RemoveGenericNum(m_mapTentativeNum, strServerID, lTransNum);
}


// Returns count of transaction numbers not yet cleared for a given server.
//
int OTPseudonym::GetTentativeNumCount(const OTIdentifier & theServerID) 
{
	return GetGenericNumCount(m_mapTentativeNum, theServerID);
}


// No signer needed for this one, and save is false.
// This version is ONLY for cases where we're not saving inside this function.
bool OTPseudonym::AddTentativeNum(const OTString & strServerID, const long & lTransNum)  // doesn't save.
{
	return AddGenericNum(m_mapTentativeNum, strServerID, lTransNum);
}


// ----------------------------------------------------------------------

// ACKNOWLEDGED NUM

// These are actually used for request numbers, so both sides can determine which
// replies are already acknowledged. Used purely for optimization, to avoid downloading
// a large number of box receipts (specifically the replyNotices.)


// Client side: See if I've already seen the server's reply to a certain request num.
// Server side: See if I've already seen the client's acknowledgment of a reply I sent.
//
bool OTPseudonym::VerifyAcknowledgedNum(const OTString & strServerID, const long & lRequestNum)
{
	return VerifyGenericNum(m_mapAcknowledgedNum, strServerID, lRequestNum);
}

// On client side: server acknowledgment has been spotted in a reply message, so I can remove it from my ack list.
// On server side: client has removed acknowledgment from his list (as evident since its sent with client messages), so server can remove it as well.
//
bool OTPseudonym::RemoveAcknowledgedNum(OTPseudonym & SIGNER_NYM, const OTString & strServerID, const long & lRequestNum) // saves
{
	return RemoveGenericNum(m_mapAcknowledgedNum, SIGNER_NYM, strServerID, lRequestNum);
}

bool OTPseudonym::RemoveAcknowledgedNum(const OTString & strServerID, const long & lRequestNum) // doesn't save
{
	return RemoveGenericNum(m_mapAcknowledgedNum, strServerID, lRequestNum);
}


// Returns count of request numbers that the client has already seen the reply to
// (Or in the case of server-side, the list of request numbers that the client has
// told me he has already seen the reply to.)
//
int OTPseudonym::GetAcknowledgedNumCount(const OTIdentifier & theServerID) 
{
	return GetGenericNumCount(m_mapAcknowledgedNum, theServerID);
}




#ifndef OT_MAX_ACK_NUMS
#define OT_MAX_ACK_NUMS   100
#endif


// No signer needed for this one, and save is false.
// This version is ONLY for cases where we're not saving inside this function.
bool OTPseudonym::AddAcknowledgedNum(const OTString & strServerID, const long & lRequestNum)  // doesn't save.
{
    // We're going to call AddGenericNum, but first, let's enforce a cap on the total
    // number of ackNums allowed...
    //
    std::string strID = strServerID.Get();
	
	// The Pseudonym has a deque of transaction numbers for each server.
	// These deques are mapped by Server ID.
	//
	// So let's loop through all the deques I have, and if the server ID on the map
	// matches the Server ID that was passed in, then we'll pop the size of the deque
    // down to our max size (off the back) before then calling AddGenericNum which will
    // push the new request number onto the front.
	//
	FOR_EACH(mapOfTransNums, m_mapAcknowledgedNum)
	{
		// if the ServerID passed in matches the serverID for the current deque
		if ( strID == it->first )
		{
			dequeOfTransNums * pDeque = (it->second);
			OT_ASSERT(NULL != pDeque);
			
            while (pDeque->size() > OT_MAX_ACK_NUMS)
            {
                pDeque->pop_back(); // This fixes knotwork's issue where he had thousands of ack nums somehow never getting cleared out. Now we have a MAX and always keep it clean otherwise.
            }			
			break;
		}
	}
    // ---------------------------------
	return AddGenericNum(m_mapAcknowledgedNum, strServerID, lRequestNum); // <=== Here we finally add the new request number, the actual purpose of this function.
}



// ----------------------------------------------------------------------


// HIGHER LEVEL...


// Client side: We have received a new trans num from server. Store it.
// Now the server uses this too, for storing these numbers so it can verify them later.
//
bool OTPseudonym::AddTransactionNum(OTPseudonym & SIGNER_NYM, const OTString & strServerID, long lTransNum, bool bSave) // SAVE OR NOT (your choice) High-Level.
{
	bool bSuccess1 = AddTransactionNum(strServerID, lTransNum);	// Add to list of available-to-use, outstanding numbers.
	bool bSuccess2 = AddIssuedNum(strServerID, lTransNum);		// Add to list of numbers that haven't been closed yet.
	// -----------------------------------
	if (bSuccess1 && !bSuccess2)
		RemoveGenericNum(m_mapTransNum, strServerID, lTransNum);
	else if (bSuccess2 && !bSuccess1)
		RemoveGenericNum(m_mapIssuedNum, strServerID, lTransNum);
	// -----------------------------------
	if (bSuccess1 && bSuccess2 && bSave)
		bSave = SaveSignedNymfile(SIGNER_NYM);
	else
		bSave = true; // so the return at the bottom calculates correctly.
	
	return (bSuccess1 && bSuccess2 && bSave);
}

// Client side: We have received a server's successful reply to a processNymbox accepting a specific new transaction number(s).
// Or, if the reply was lost, then we still found out later that the acceptance was successful, since a notice is still dropped
// into the Nymbox. Either way, this function removes the Tentative number, right before calling the above AddTransactionNum()
// in order to make it available for the Nym's use on actual transactions.
//
bool OTPseudonym::RemoveTentativeNum(OTPseudonym & SIGNER_NYM, const OTString & strServerID, const long & lTransNum, bool bSave) // SAVE OR NOT (your choice) High-Level.
{
	bool bSuccess = RemoveTentativeNum(strServerID, lTransNum);		// Remove from list of numbers that haven't been made available for use yet, though they're "tentative"...
	// -----------------------------------
	if (bSuccess && bSave)
		bSave = SaveSignedNymfile(SIGNER_NYM);
	else 
		bSave = true; // so the return at the bottom calculates correctly.
	// -----------------------------------
	return (bSuccess && bSave);
}

// Client side: We have accepted a certain receipt. Remove the transaction number from my list of issued numbers.
// The server uses this too, also for keeping track of issued numbers, and removes them around same time as client.
// (When receipt is accepted.) Also, There is no "RemoveTransactionNum" at this level since GetNextTransactionNum handles that.
//
bool OTPseudonym::RemoveIssuedNum(OTPseudonym & SIGNER_NYM, const OTString & strServerID, const long & lTransNum, bool bSave) // SAVE OR NOT (your choice) High-Level.
{
	bool bSuccess = RemoveIssuedNum(strServerID, lTransNum);		// Remove from list of numbers that haven't been closed yet.
	// -----------------------------------
	if (bSuccess && bSave)
		bSave = SaveSignedNymfile(SIGNER_NYM);
	else 
		bSave = true; // so the return at the bottom calculates correctly.
	// -----------------------------------
	return (bSuccess && bSave);
}


// Client keeps track of server replies it's already seen.
// Server keeps track of these client acknowledgments.
// (Server also removes from Nymbox, any acknowledged message
// that wasn't already on his list based on request num.)
// Server already removes from his list, any number the client
// has removed from his.
// This is all purely for optimization, since it allows us to avoid
// downloading all the box receipts that contain replyNotices.
//
bool OTPseudonym::RemoveAcknowledgedNum(OTPseudonym & SIGNER_NYM, const OTString & strServerID, const long & lRequestNum, bool bSave) // SAVE OR NOT (your choice) High-Level.
{
	bool bSuccess = RemoveAcknowledgedNum(strServerID, lRequestNum);		// Remove from list of acknowledged request numbers.
	// -----------------------------------
	if (bSuccess && bSave)
		bSave = SaveSignedNymfile(SIGNER_NYM);
	else 
		bSave = true; // so the return at the bottom calculates correctly.
	// -----------------------------------
	return (bSuccess && bSave);
}



/// OtherNym is used as container for server to send us new transaction numbers
/// Currently unused. (old) NEW USE:
/// Okay then, new use: This will be the function that does what the below function
/// does (OTPseudonym::HarvestIssuedNumbers), EXCEPT it only adds numbers that
/// aren't on the TENTATIVE list. Also, it will set the new "highest" trans num
/// for the appropriate server, based on the new numbers being harvested.
//
void OTPseudonym::HarvestTransactionNumbers(const OTIdentifier & theServerID, 
                                                  OTPseudonym  & SIGNER_NYM,
                                                  OTPseudonym  & theOtherNym, bool bSave/*=true*/)
{
    const char * szFunc = "OTPseudonym::HarvestTransactionNumbers";
    // --------------------
	long lTransactionNumber = 0;
	
	std::set<long> setInput, setOutputGood, setOutputBad;

	FOR_EACH(mapOfTransNums, theOtherNym.GetMapIssuedNum())
	{	
        std::string	strServerID		= (*it).first;
		dequeOfTransNums * pDeque	= (it->second);
		
        OT_ASSERT(NULL != pDeque);
		
        OTString OTstrServerID = strServerID.c_str();
        const OTIdentifier theTempID(OTstrServerID);
		
		if (!(pDeque->empty()) && (theServerID == theTempID) ) // only for the matching serverID.
		{
			for (unsigned i = 0; i < pDeque->size(); i++)
			{
				lTransactionNumber = pDeque->at(i);
				
				// If number wasn't already on issued list, then add to BOTH lists.
				// Otherwise do nothing (it's already on the issued list, and no longer 
				// valid on the available list--thus shouldn't be re-added there anyway.)
				// 
				if ((true   == VerifyTentativeNum(OTstrServerID, lTransactionNumber)) &&	// If I've actually requested this number and waiting on it...
					(false  == VerifyIssuedNum(OTstrServerID, lTransactionNumber))          // and if it's not already on my issued list...
					)
					setInput.insert(lTransactionNumber);
			}
            break;  // We found it! Might as well break out.
		}
	} // for
    
	// ----------------------------------
    // Looks like we found some numbers to harvest
    // (tentative numbers we had already been waiting for,
    // yet hadn't processed onto our issued list yet...)
    //
	if (setInput.size() > 0)
	{
		const OTString strServerID(theServerID), strNymID(m_nymID);
        
		long lViolator = this->UpdateHighestNum(SIGNER_NYM, strServerID, setInput,
                                                setOutputGood, setOutputBad); // bSave=false (saved below already, if necessary)

		// NOTE: Due to the possibility that a server reply could be processed twice (due to redundancy
        // for the purposes of preventing syncing issues) then we expect we might get numbers in here
        // that are below our "last highest num" (due to processing the same numbers twice.) Therefore
        // we don't need to assume an error in this case. UpdateHighestNum() is already smart enough to
        // only update based on the good numbers, while ignoring the bad (i.e. already-processed) ones.
        // Thus we really only have a problem if we receive a (-1), which would mean an error occurred.
        // Also, the above call will log an FYI that it is skipping any numbers below the line, so no need
        // to log more in the case of lViolater being >0 but less than the 'last highest number.'
        //
		if ((-1) == lViolator)
			OTLog::vError("%s: ERROR: UpdateHighestNum() returned (-1), which is an error condition. "
                          "(Should never happen.)\nNym ID: %s \n", szFunc, strNymID.Get());
		else
		{
            // We only remove-tentative-num/add-transaction-num for the numbers that were above our 'last highest number'.
            // The contents of setOutputBad are thus ignored for these purposes.
            //
			FOR_EACH(std::set<long>, setOutputGood) 
			{
				const long lNoticeNum = (*it);
                // --------------------------------------
                // We already know it's on the TentativeNum list, since we checked that in the above for loop.
                // We also already know that it's not on the issued list, since we checked that as well.
                // That's why the below calls just ASSUME those things already.
                //
				RemoveTentativeNum(strServerID, lNoticeNum); // doesn't save (but saved below)
				AddTransactionNum(SIGNER_NYM, strServerID, lNoticeNum, false); // bSave = false (but saved below...)
			}

            // We save regardless of whether any removals or additions are made, because data was
            // updated in UpdateHighestNum regardless.
            //
			if (bSave) 
				SaveSignedNymfile(SIGNER_NYM);
		}
	}
}




//  OtherNym is used as container for us to send server list of issued transaction numbers.
//  NOTE: in more recent times, a class has been added for managing lists of numbers. But
//  we didn't have that back when this was written.
//
// The above function is good for accepting new numbers onto my list, numbers that I already
// tried to sign for and are thus waiting in my tentative list. When calling that function,
// I am trying to accept those new numbers (the ones I was expecting already), and NO other
// numbers.
//
// Whereas with the below function, I am adding as "available" all the numbers that I didn't
// already have issued to me, REGARDLESS of tentative status. Why would I do this? Well,
// perhaps a temp nym is being used during some calculations, and I want to copy all the numbers
// over to the temp nym, period, regardless of his tentative list, because he has no tentative
// list, because he's not a nym in the first place.
//
void OTPseudonym::HarvestIssuedNumbers(const OTIdentifier & theServerID,
                                       OTPseudonym & SIGNER_NYM,
                                       OTPseudonym & theOtherNym,
                                       bool bSave/*=false*/)
{
	bool bChangedTheNym = false;
	long lTransactionNumber = 0;
	
	FOR_EACH(mapOfTransNums, theOtherNym.GetMapIssuedNum())
	{	
        std::string	strServerID		= (*it).first;
		dequeOfTransNums * pDeque	= (it->second);
		
        OT_ASSERT(NULL != pDeque);

        OTString OTstrServerID = ((strServerID.size()) > 0 ? strServerID.c_str() : "");
        const OTIdentifier theTempID(OTstrServerID);
		
		if (!(pDeque->empty()) && (theServerID == theTempID) )
		{
			for (unsigned i = 0; i < pDeque->size(); i++)
			{
				lTransactionNumber = pDeque->at(i);
				
				// If number wasn't already on issued list, then add to BOTH lists.
				// Otherwise do nothing (it's already on the issued list, and no longer 
				// valid on the available list--thus shouldn't be re-added there anyway.)
				// 
				if (false == VerifyIssuedNum(OTstrServerID, lTransactionNumber))
                {
					AddTransactionNum(SIGNER_NYM, OTstrServerID, lTransactionNumber, false); // bSave = false (but saved below...)
                    bChangedTheNym = true;
                }
			}
            break;  // We found it! Might as well break out.
		}
	} // for
	
	if (bChangedTheNym && bSave)
	{
		SaveSignedNymfile(SIGNER_NYM);
	}
}


// ---------------------------------------------------------------------------------


/// When a number IS already on my issued list, but NOT on my available list
/// (because I already used it on some transaction) then this function will
/// verify that and then add it BACK to my available list. (Like if the
/// transaction failed and I just want to get my numbers back so I can use
/// them on a different transaction.)
///
bool OTPseudonym::ClawbackTransactionNumber(const OTIdentifier & theServerID,
                                            const long & lTransClawback, // the number being clawed back.
                                            bool bSave/*=false*/, // false because you might call this function 10 times in a loop, and not want to save EVERY iteration.
                                            OTPseudonym * pSIGNER_NYM/*=NULL*/)
{
    if (NULL == pSIGNER_NYM)
        pSIGNER_NYM = this;
    // Below this point, pSIGNER_NYM is definitely a good pointer.
    // -------------------------------
    const OTString strServerID(theServerID);

    // Only re-add the transaction number if it's already on my issued list.
    // (Otherwise, why am I "adding it back again" if I never had it in the
    // first place? Doesn't sound like a real clawback situation in that case.)
    // 
    if (true == VerifyIssuedNum(strServerID, lTransClawback))
    {
        AddTransactionNum(*pSIGNER_NYM, strServerID, lTransClawback, bSave);
        return true;
    }
    // -------------------------------
    return false;
}



// ---------------------------------------------------------------------------------


/// Client side.
/// Get the next available transaction number for the serverID
/// The lTransNum parameter is for the return value.
/// SAVES if successful.
bool OTPseudonym::GetNextTransactionNum(OTPseudonym & SIGNER_NYM, const OTString & strServerID, long &lTransNum,
                                        bool bSave/*=true*/)
{
	bool bRetVal		= false;
	std::string strID	= strServerID.Get();
	
	// The Pseudonym has a deque of transaction numbers for each server.
	// These deques are mapped by Server ID.
	// 
	// So let's loop through all the deques I have, and if the server ID on the map
	// matches the Server ID that was passed in, then send out the transaction  number.
	//
	FOR_EACH(mapOfTransNums, m_mapTransNum)
	{
		// if the ServerID passed in matches the serverID for the current deque
		if ( strID == it->first )
		{
			dequeOfTransNums * pDeque = (it->second);
			OT_ASSERT(NULL != pDeque);
			
			if (!(pDeque->empty()))
			{
				lTransNum = pDeque->front();
				
				pDeque->pop_front();
				
				// The call has succeeded
				bRetVal = true;
			}
			break;			
		}
	}
	
	if (bRetVal && bSave)
	{
		if (false == SaveSignedNymfile(SIGNER_NYM))
            OTLog::Error("Error saving signed NymFile in OTPseudonym::GetNextTransactionNum\n");
	}
    
	return bRetVal;
}








// returns true on success, value goes into lReqNum
// Make sure the Nym is LOADED before you call this,
// otherwise it won't be there to get.
//
bool OTPseudonym::GetHighestNum(const OTString & strServerID, long &lHighestNum)
{		
	bool bRetVal		= false;
	std::string strID	= strServerID.Get();
	
	// The Pseudonym has a map of the highest transaction # it's received from different servers.
	// For Server Bob, with this Pseudonym, I might be on number 34.
	// For but Server Alice, I might be on number 59.
	// 
	// So let's loop through all the numbers I have, and if the server ID on the map
	// matches the Server ID that was passed in, then send out the highest number.
	//
	// Since the transaction number only ever gets bigger, this is a way of preventing
	// the server from EVER tricking us by trying to give us a number that we've
	// already seen before.
	//
	FOR_EACH(mapOfHighestNums, m_mapHighTransNo)
	{
		if ( strID == it->first )
		{
			// Setup return value.
			lHighestNum = (it->second);
			
			// The call has succeeded
			bRetVal = true;
			
			break;
		}
	}
	
	return bRetVal;
}



// Go through setNumbers and make sure none of them is lower than the highest number I already have for this
// server. At the same time, keep a record of the largest one in the set. If successful, that becomes the new
// "highest" number I've ever received that server. Otherwise fail.
// If success, returns 0. If failure, returns the number that caused us to fail (by being lower than the last 
// highest number.) I should NEVER receive a new transaction number that is lower than any I've gotten before.
// They should always only get bigger. UPDATE: Unless I happen to be processing an old receipt twice... (which
// can happen, due to redundancy used for preventing syncing issues, such as Nymbox notices.)
//
long OTPseudonym::UpdateHighestNum(OTPseudonym & SIGNER_NYM,
                                   const OTString & strServerID,
                                   std::set<long> & setNumbers,
                                   std::set<long> & setOutputGood,
                                   std::set<long> & setOutputBad, bool bSave/*=false*/)
{
	bool bFoundServerID = false;
	long lReturnVal     = 0; // 0 is success.
    
	// First find the highest and lowest numbers out of the new set.
	//
	long lHighestInSet  = 0;
	long lLowestInSet   = 0;
    
	FOR_EACH(std::set<long>, setNumbers)
	{
		const long lSetNum = *it;

		if (lSetNum > lHighestInSet)		lHighestInSet = lSetNum;    // Set lHighestInSet to contain the highest number out of setNumbers (input)
		// ---------------------
		if (0 == lLowestInSet)				lLowestInSet = lSetNum;     // If lLowestInSet is still 0, then set it to the current number (happens first iteration.)
		else if (lSetNum < lLowestInSet)	lLowestInSet = lSetNum;     // If current number is less than lLowestInSet, then set lLowestInSet to current Number.
	}
    
    // By this point, lLowestInSet contains the lowest number in setNumbers,
    // and lHighestInSet contains the highest number in setNumbers.
    // -------------------------------------------------------------------
    //
	// The Pseudonym has a map of the "highest transaction numbers" for different servers.
	// For Server Bob, with this Pseudonym, I might be on number 34.
	// For but Server Alice, I might be on number 59.
	// 
	// So let's loop through all the numbers I have, and if the server ID on the map
	// matches the Server ID that was passed in, then update it there (then break.)
	//
	// Make sure to save the Pseudonym afterwards, so the new numbers are saved.

	std::string strID	= strServerID.Get();
	
	FOR_EACH(mapOfHighestNums, m_mapHighTransNo)
	{
        // We found the serverID key on the map?
        // We now know the highest trans number for that server?
        //
		if ( strID == it->first ) // Iterates inside this block zero times or one time. (One if it finds it, zero if not.)
		{
			// We found it!
			// Presumably we ONLY found it because this Nym has been properly loaded first.
			// Good job! Otherwise, the list would have been empty even though the highest number
			// was sitting in the file.
			
			// Grab a copy of the old highest trans number for this server.
            //
			const long lOldHighestNumber = it->second; // <=========== The previous "highest number".

			// ----------------------------------------------
            
            // Loop through the numbers passed in, and for each, see if it's less than
            // the previous "highest number for this server."
            //
            // If it's less, then we can't add it (must have added it already...)
            // So we add it to the bad list.
            // But if it's more, 
            
            FOR_EACH_IT(std::set<long>, setNumbers, it_numbers)
            {
                const long lSetNum = *it_numbers;
                // ------------------------
                // If the current number (this iteration) is less than or equal to the
                // "old highest number", then it's not going to be added twice.
                // (It goes on the "bad list.")
                //
                if (lSetNum <= lOldHighestNumber)
                {
                    OTLog::vOutput(1, "OTPseudonym::UpdateHighestNum: New transaction number is less-than-or-equal-to "
                                   "last known 'highest trans number' record. (Must be seeing the same server reply for "
                                   "a second time, due to a receipt in my Nymbox.) "
                                   "FYI, last known 'highest' number received: %ld (Current 'violator': %ld) Skipping...\n",
                                   lOldHighestNumber, lSetNum);
                    setOutputBad.insert(lSetNum);
                }
                // ------------------------------------------------------------------------------
                // The current number this iteration, as it should be, is HIGHER than any transaction
                // number I've ever received before. (Although sometimes old messages will 'echo'.)
                // I want to replace the "highest" record with this one
                else
                {
                    setOutputGood.insert(lSetNum);
                }
            } // FOR_EACH_IT (it_numbers)
			// ----------------------------------------------

			// Here we're making sure that all the numbers in the set are larger than any others
			// that we've had before for the same server (They should only ever get larger.)
			//
//			if (lLowestInSet <= lOldHighestNumber) // ERROR!!! The new numbers should ALWAYS be larger than the previous ones!
			if ((lLowestInSet > 0) && (lLowestInSet <= lOldHighestNumber))  // WARNING! The new numbers should ALWAYS be larger than the previous ones!
                                                                            // UPDATE: Unless we happen to be processing the same receipt for a second time, due to redundancy in the system (for preventing syncing errors.)
				lReturnVal = lLowestInSet;  // We return the violator (otherwise 0 if success).
			// ---------------------------------------------------------------
			// The loop has succeeded in finding the server ID and its associated "highest number" value.
            //
			bFoundServerID = true;
			break;  // This main FOR_EACH only ever has one active iteration: the one with
                    //  the right server ID. Once we find it, we break (no matter what.)
		} // server ID matches.
	} // FOR_EACH
	// ----------------------------------------------------------------
	// If we found the server ID, that means the highest number was previously recorded.
    // We don't want to replace it unless we were successful in this function. And if we
    // were, then we want to replace it with the new "highest number in the set."
    //
    // IF we found the server ID for a previously recorded highestNum, and
    // IF this function was a success in terms of the new numbers all exceeding that old record,
    // THEN ERASE that old record and replace it with the new highest number.
    //
    // Hmm: Should I require ALL new numbers to be valid? Or should I take the valid ones,
    // and ignore the invalid ones?
    //
    // Update: Just found this comment from the calling function:
    // NOTE: Due to the possibility that a server reply could be processed twice (due to redundancy
    // for the purposes of preventing syncing issues) then we expect we might get numbers in here
    // that are below our "last highest num" (due to processing the same numbers twice.) Therefore
    // we don't need to assume an error in this case. UpdateHighestNum() is already smart enough to
    // only update based on the good numbers, while ignoring the bad (i.e. already-processed) ones.
    // Thus we really only have a problem if we receive a (-1), which would mean an error occurred.
    // Also, the above call will log an FYI that it is skipping any numbers below the line, so no need
    // to log more in the case of lViolater being >0 but less than the 'last highest number.'
    //
    // ===> THEREFORE, we don't need an lReturnVal of 0 in order to update the highest record.
    // Instead, we just need bFoundServerID to be true, and we need setOutputGood to not be empty
    // (we already know the numbers in setOutputGood are higher than the last highest recorded trans
    // num... that's why they are in setOutputGood instead of setOutputBad.)
    //
    if (!setOutputGood.empty()) // There's numbers worth savin'!
    {
        if (bFoundServerID)
        {
            OTLog::vOutput(0, "OTPseudonym::UpdateHighestNum: Raising Highest Trans Number from %ld to %ld.\n",
                           m_mapHighTransNo[strID], lHighestInSet);
            
            // We KNOW it's there, so we can straight-away just
            // erase it and insert it afresh..
            //
            m_mapHighTransNo.erase(strID);
            m_mapHighTransNo.insert(std::pair<std::string, long>(strID, lHighestInSet));                
        }
        // ----------------------------------------------
        // If I didn't find the server in the list above (whether the list is empty or not....)
        // that means the record does not yet exist. (So let's create it)--we wouldn't even be
        // here unless we found valid transaction numbers and added them to setOutputGood.
        // (So let's record lHighestInSet mapped to strID, just as above.)
        else
        {
            OTLog::vOutput(0, "OTPseudonym::UpdateHighestNum: Creating "
                           "Highest Transaction Number entry for this server as '%ld'.\n",
                           lHighestInSet);
            m_mapHighTransNo.insert(std::pair<std::string, long>(strID, lHighestInSet));
        }
        // ----------------------------------------------
        // By this point either the record was created, or we were successful above in finding it
        // and updating it. Either way, it's there now and potentially needs to be saved.
        //
        if (bSave)
			SaveSignedNymfile(SIGNER_NYM);
    }
    else // setOutputGood was completely empty in this case...
    {    // (So there's nothing worth saving.) A repeat message.
         //
         // Should I return a -1 here or something? Let's say it's
         // a redundant message...I've already harvested these numbers. So
         // they are ignored this time, my record of 'highest' is unimpacted,
         // and if I just return lReturnVal below, it will contain 0 for success
         // or a transaction number (the min/low violator) but even that is considered
         // a "success" in the sense that some of the numbers would still normally be
         // expected to have passed through.
         // The caller will check for -1 in case of some drastic error, but so far I don't
         // see a place here for that return value.
         // 
    }
    // ----------------------------------------------------------------
    
	return lReturnVal; // Defaults to 0 (success) but above, might have been set to "lLowestInSet" (if one was below the mark.)
}










// returns true on success, value goes into lReqNum
// Make sure the Nym is LOADED before you call this,
// otherwise it won't be there to get.
// and if the request number needs to be incremented,
// then make sure you call IncrementRequestNum (below)
bool OTPseudonym::GetCurrentRequestNum(const OTString & strServerID, long &lReqNum)
{		
	bool bRetVal		= false;
	std::string strID	= strServerID.Get();
	
	// The Pseudonym has a map of the request numbers for different servers.
	// For Server Bob, with this Pseudonym, I might be on number 34.
	// For but Server Alice, I might be on number 59.
	// 
	// So let's loop through all the numbers I have, and if the server ID on the map
	// matches the Server ID that was passed in, then send out the request number.
	FOR_EACH(mapOfRequestNums, m_mapRequestNum)
	{
		if ( strID == it->first )
		{
			// Setup return value.
			lReqNum = (it->second);
			
			// The call has succeeded
			bRetVal = true;
			
			break;
		}
	}
	
	return bRetVal;
}



// Make SURE you call SavePseudonym after you call this.
// Otherwise it will increment in memory but not in the file.
// In fact, I cannot allow that. I will call SavePseudonym myself.
// Therefore, make SURE you fully LOAD this Pseudonym before you save it.
// You don't want to overwrite what's in that file.
// THEREFORE we need a better database than the filesystem.
// I will research a good, free, secure database (or encrypt everything
// before storing it there) and soon these "load/save" commands will use that
// instead of the filesystem.
void OTPseudonym::IncrementRequestNum(OTPseudonym & SIGNER_NYM, const OTString & strServerID)
{
	bool bSuccess = false;

	// The Pseudonym has a map of the request numbers for different servers.
	// For Server Bob, with this Pseudonym, I might be on number 34.
	// For but Server Alice, I might be on number 59.
	// 
	// So let's loop through all the numbers I have, and if the server ID on the map
	// matches the Server ID that was passed in, then send out the request number and
	// increment it so it will be ready for the next request.
	//
	// Make sure to save the Pseudonym so the new request number is saved.
	std::string strID	= strServerID.Get();
	
	FOR_EACH(mapOfRequestNums, m_mapRequestNum)
	{
		if ( strID == it->first )
		{
			// We found it!
			// Presumably we ONLY found it because this Nym has been properly loaded first.
			// Good job! Otherwise, the list would have been empty even though the request number
			// was sitting in the file.
			
			
			// Grab a copy of the old request number
			long lOldRequestNumber = m_mapRequestNum[it->first];
			
			// Set the new request number to the old one plus one.
			m_mapRequestNum[it->first] = lOldRequestNumber + 1;
			
			// Now we can log BOTH, before and after... // debug here
			OTLog::vOutput(4, "Incremented Request Number from %ld to %ld. Saving...\n", 
					lOldRequestNumber, m_mapRequestNum[it->first]);

			// The call has succeeded
			bSuccess = true;
			break;
		}
	}
	
	// If I didn't find it in the list above (whether the list is empty or not....)
	// that means it does not exist. So create it.
	
	if (!bSuccess)
	{
		OTLog::Output(0, "Creating Request Number entry as '100'. Saving...\n");
		m_mapRequestNum[strServerID.Get()] = 100;
		bSuccess = true;
	}
	
	
	if (bSuccess)
	{
		SaveSignedNymfile(SIGNER_NYM);
	}
}






// if the server sends us a @getRequest
void OTPseudonym::OnUpdateRequestNum(OTPseudonym & SIGNER_NYM, const OTString & strServerID, long lNewRequestNumber)
{
	bool bSuccess = false;
	
	// The Pseudonym has a map of the request numbers for different servers.
	// For Server Bob, with this Pseudonym, I might be on number 34.
	// For but Server Alice, I might be on number 59.
	// 
	// So let's loop through all the numbers I have, and if the server ID on the map
	// matches the Server ID that was passed in, then send out the request number and
	// increment it so it will be ready for the next request.
	//
	// Make sure to save the Pseudonym so the new request number is saved.
	std::string strID	= strServerID.Get();
	
	FOR_EACH(mapOfRequestNums, m_mapRequestNum)
	{
		if ( strID == it->first )
		{
			// We found it!
			// Presumably we ONLY found it because this Nym has been properly loaded first.
			// Good job! Otherwise, the list would have been empty even though the request number
			// was sitting in the file.
			
			// The call has succeeded
			bSuccess = true;
			
			// Grab a copy of the old request number
			long lOldRequestNumber = m_mapRequestNum[it->first];
			
			// Set the new request number to the old one plus one.
			m_mapRequestNum[it->first] = lNewRequestNumber;
			
			// Now we can log BOTH, before and after...
			OTLog::vOutput(4, "Updated Request Number from %ld to %ld. Saving...\n", 
					lOldRequestNumber, m_mapRequestNum[it->first]);
			break;
		}
	}
	
	// If I didn't find it in the list above (whether the list is empty or not....)
	// that means it does not exist. So create it.
	
	if (!bSuccess)
	{
		OTLog::vOutput(0, "Creating Request Number entry as '%ld'. Saving...\n", lNewRequestNumber);
		m_mapRequestNum[strServerID.Get()] = lNewRequestNumber;
		bSuccess = true;
	}
	// -----------------
	if (bSuccess)
	{
		SaveSignedNymfile(SIGNER_NYM);
	}
	
}




int OTPseudonym::GetMasterCredentialCount() const
{
    return m_mapCredentials.size();
}

int OTPseudonym::GetRevokedCredentialCount() const
{
    return m_mapRevoked.size();
}



/*
 How will VerifyPseudonym change now that we are adding credentials?
 
 Before it was easy: hash the public key, and compare the result to the NymID
 as it was already set by the wallet. If they match, then this really is the public
 key that I was expecting. (You could not change out that key without causing the ID
 to also change.)
 
 How are things with credentials?
 
 The public key may not directly hash to the Nym ID, but even if it did, which public key?
 Aren't there THREE public keys for each credential? That is, a signing, authentication, and
 encryption key. Which one is used as that Key ID? Perhaps all three are hashed together?
 And that collective three-key is only valid for a given Nym, if its credential contract is
 signed by a master key for that Nym. And that master key is only valid if its authority
 verifies properly. And the Nym's ID should be a hash somehow, of that authority. All of those
 things must verify in VerifyPseudonym, in the new system.
 
 Is that really true?
 
 Pseudo-code:
 
 Loop through the credentials for this Nym.
 For each, the authority/source string (which resolve to the NymID) should be identical.
 Resolve the NymID and compare it to the one that was expected.
 An extended version will also verify the authority itself, to see if it verifies the key.
 For example if this Nym is issued based on a Namecoin address, then the code would actually
 check Namecoin itself to verify the NymID is the same one posted there.
 
 */

bool OTPseudonym::VerifyPseudonym() const
{
    // If there are credentials, then we verify the Nym via his credentials.
    // Otherwise we do it the old way (using the Nym's "keypair")--which is being deprecated.
    //
    if (m_mapCredentials.size() > 0)
    {
        // Verify Nym by his own credentials.
        //
        FOR_EACH_CONST(mapOfCredentials, m_mapCredentials)
        {
            const OTCredential * pCredential = (*it).second;
            OT_ASSERT(NULL != pCredential);
            // ---------------------------------------
            const OTIdentifier theCredentialNymID(pCredential->GetNymID());
            if (false == this->CompareID(theCredentialNymID))
            {
                OTString strNymID;
                this->GetIdentifier(strNymID);
                OTLog::vOutput(0, "%s: Credential NymID (%s) doesn't match actual NymID: %s\n",
                               __FUNCTION__, pCredential->GetNymID().Get(), strNymID.Get());
                return false;
            }
            // ---------------------------------------
            if (false == pCredential->VerifyInternally())
            {
                OTLog::vOutput(0, "%s: Credential (%s) failed its own internal verification.\n",
                               __FUNCTION__, pCredential->GetMasterCredID().Get());
                return false;
            }
            // ---------------------------------------
            // Warning: time-intensive. Todo optimize: load a contract here which verifies authorization,
            // based on a signature from a separate process which did an identity lookup externally.
            // Once that authorization times out, then the identity verification server can just sign
            // another one.
            //
            if (false == pCredential->VerifyAgainstSource()) // todo optimize, warning: time-intensive.
            {
                OTLog::vOutput(0, "%s: Credential failed against its source. Credential ID: %s\n"
                               "NymID: %s\nSource:\n%s\n", __FUNCTION__,
                               pCredential->GetMasterCredID().Get(), pCredential->GetNymID().Get(),
                               pCredential->GetSourceForNymID().Get());
                return false;
            }
            // ---------------------------------------
        } // FOR_EACH_CONST
        
        return true;
        
    } // If there are credentials
    // --------------------------------------------
    else // Deprecated. OTPseudonym::m_pkeypair was used for encryption, signing, and authentication.
    {    // (Replaced by the above block, which has a map of credentials for each Nym, with each
         // credential having a master key and a set of subcredentials including subkeys.
         //
        OT_ASSERT(NULL != m_pkeypair);
        // -----------------
        OTString strPublicKey;
        bool bGotPublicKey = m_pkeypair->GetPublicKey(strPublicKey);
        
        if (!bGotPublicKey)
        {
            OTLog::Error("Error getting public key in OTPseudonym::VerifyPseudonym.\n");
            return false;	
        }
        // --------------------------------------------
        OTIdentifier newID;
        bool bSuccessCalculateDigest = newID.CalculateDigest(strPublicKey);
        
        if (!bSuccessCalculateDigest)
        {
            OTLog::Error("Error calculating pubkey digest.\n");
            return false;	
        }
        // --------------------------------------------	
        // newID now contains the Hash aka Message Digest aka Fingerprint aka "IDENTIFIER" 
        // of the public key (in its text form, with escaped bookends.)
        // 
        // Now let's compare that identifier to the one already loaded by the wallet
        // and make sure they MATCH.
        
        if (m_nymID != newID)
        {
            OTString str1(m_nymID), str2(newID);
            OTLog::vError("\nHashes do NOT match in OTPseudonym::VerifyPseudonym!\n%s\n%s\n",
                    str1.Get(), str2.Get());
            
            return false;
        }
        else
        {
    //		OTString str2(newID);
    //		OTLog::Output(1, "\nNymID from wallet *SUCCESSFUL* match to hash of Nym\'s public key:\n%s\n"
    //				"---------------------------------------------------------------\n", str2.Get());
            return true;
        }
    }
    // --------------------------------------------
    return false;
}


bool OTPseudonym::CompareID(const OTPseudonym & RHS) const
{ 
	return RHS.CompareID(m_nymID); 
}



// --------------------------------------------------------------


bool OTPseudonym::SavePseudonymWallet(OTString & strOutput) const
{
	OTString nymID;
	GetIdentifier(nymID);
	
	OTASCIIArmor ascName;
	
	if (m_strName.Exists()) // name is in the clear in memory, and base64 in storage.
	{
		ascName.SetString(m_strName, false); // linebreaks == false
	}

	strOutput.Concatenate("<pseudonym name=\"%s\"\n"
			" nymID=\"%s\" />\n\n",
			ascName.Get(),
			nymID.Get());
	
	return true;
}


bool OTPseudonym::SavePseudonymWallet(std::ofstream & ofs) const
{
	OTString strOutput;
	
	if (SavePseudonymWallet(strOutput))
		ofs << strOutput.Get();
	else
		return false;
	
	return true;
}

// -----------------------------------------------------


//
// This function saves the public key to a file.
//
bool OTPseudonym::SavePublicKey(const OTString & strPath) const
{
	const char * szFoldername	= OTFolders::Pubkey().Get();
	const char * szFilename	= strPath.Get();
	
	OT_ASSERT(NULL != szFoldername);
	OT_ASSERT(NULL != szFilename);
	
    OT_ASSERT(NULL != m_pkeypair);
    
	// By passing in an OTString instead of OTASCIIArmor, it knows to add the bookends
	// ----- BEGIN PUBLIC KEY  etc.  These bookends are necessary for OTASCIIArmor to later
	// read the thing back up into memory again.
	OTString strKey;
	
	if (m_pkeypair->GetPublicKey(strKey, false)) // false means "do not ESCAPE the bookends"
		// Ie we'll get ----------- instead of - ---------
	{
		bool bStored = OTDB::StorePlainString(strKey.Get(), szFoldername, szFilename);

		if (!bStored)
		{
			OTLog::vError("Failure in OTPseudonym::SavePublicKey while saving to storage: %s%s%s\n",
						  szFoldername, OTLog::PathSeparator(), szFilename);
			return false;
		}
	}
	else 
	{
		OTLog::Error("Error in OTPseudonym::SavePublicKey: unable to GetPublicKey from Nym\n");
		return false;
	}
	
	return true;
}


bool OTPseudonym::SavePublicKey(std::ofstream & ofs) const
{
    OT_ASSERT(NULL != m_pkeypair);

	// By passing in an OTString instead of OTASCIIArmor, it knows to add the bookends
	// ----- BEGIN PUBLIC KEY  etc.  These bookends are necessary for OTASCIIArmor to later
	// read the thing back up into memory again.
	OTString strKey;
	
	if (m_pkeypair->GetPublicKey(strKey, false)) // false means "do not ESCAPE the bookends"
		// Ie we'll get ----------- instead of - ---------
	{
		strKey.WriteToFile(ofs);
	}
	else 
	{
		OTLog::Error("Error in OTPseudonym::SavePublicKey: unable to GetPublicKey from Nym\n");
		return false;
	}
	
	return true;
}


// pstrID is an output parameter.
bool OTPseudonym::Server_PubKeyExists(OTString * pstrID/*=NULL*/) // Only used on server side.
{
	// ------------------------------------
	OTString strID;
    if (NULL == pstrID)
    {
        pstrID = &strID;
    }
    this->GetIdentifier(*pstrID);
	// ------------------------------------
    // Below this point, pstrID is a GOOD pointer, no matter what. (And no need to delete it.)

	return OTDB::Exists(OTFolders::Pubkey().Get(), pstrID->Get());
}

// ------------------------------------

// This version is run on the server side, and assumes only a Public Key.
// This code reads up the file, discards the bookends, and saves only the gibberish itself.
bool OTPseudonym::LoadPublicKey()
{
    OT_ASSERT(NULL != m_pkeypair);
    // ----------------------------   
    // Here we try to load credentials first (the new system) and if it's successful, we
    // use that to set the public key from the credential, and then return. Otherwise,
    // we run the old code.
    //
    if (this->LoadCredentials() && (this->GetMasterCredentialCount() > 0)) // New style!
    {
//        mapOfCredentials::iterator it = m_mapCredentials.begin();
//        OT_ASSERT(m_mapCredentials.end() != it);
//        OTCredential * pCredential = (*it).second;
//        OT_ASSERT(NULL != pCredential);
//        // -----------------------------
//        OTString strSigningKey;
//
//        if (const_cast<OTKeypair &>(pCredential->GetSignKeypair(&m_listRevokedIDs)).GetPublicKey(strSigningKey, false)) //bEscaped
//            return m_pkeypair->SetPublicKey(strSigningKey, false); // bEscaped
//        else
//            OTLog::vError("%s: Failed in call to pCredential->GetPublicSignKey().GetPublicKey()\n", __FUNCTION__);
        // -----------------------------
        return true;
        
        // NOTE: LoadPublicKey (this function) calls LoadCredentials (above.) On the server side, these are
        // public credentials which do not contain keys, per se. Instead, it contains a single variable which in
        // turn contains the master-signed version of itself which then contains the public keys.
        //
        // That means when the credentials are first loaded, there are no public keys loaded! Each subcredential
        // is signed by itself, and contains a master-signed version of itself that's signed by the master. It's
        // only AFTER loading, in verification (OTSubcredential::VerifyInternally) when we verify the master signature
        // on the master-signed version, and if it all checks out, THEN we copy the public keys from the master-signed
        // version up into the actual subcredential. UNTIL WE DO THAT, the actual subcredential HAS NO PUBLIC KEYS IN IT.
        //
        // That's why the above code was having problems -- we are trying to "GetPublicKey" when there can be no
        // possibility that the public key will be there.
        // For now I'm going to NOT set m_pkeypair, since the public key isn't available to set onto it yet.
        // We want to phase out m_pkeypair anyway, but I just hope this doesn't cause problems where it was expected
        // in the future, where I still need to somehow make sure it's set. (AFTER verification, apparently.)
        //
        // Notice however, that this only happens in cases where the credentials were actually available, so maybe it
        // will just work, since the below block is where we handle cases where the credentials WEREN'T available, so
        // we load the old key the old way. (Meaning we definitely know that those "old cases" will continue to work.)
        // Any potential problems will have to be in cases where credentials ARE available, but the code was nonetheless
        // still expecting things to work the old way -- and these are precisely the sorts of cases I probably want to
        // uncover, so I can convert things over...
    }
    // ----------------------------
    // OLD STYLE (below.) Deprecated!
    
    
	OTString strID;
	
	if (false == this->Server_PubKeyExists(&strID)) // strID will contain *this nymID after this call.
	{
		// Code will call this in order to see if there is a PublicKey to be loaded.
		// Therefore I don't want to log a big error here since we expect that sometimes
		// the key won't be there.
		// Therefore I log at level 4, the same level as I log the successful outcome.
        //
		OTLog::vOutput(4, "%s: Failed load: "
                      "Apparently this Nym doesn't exist. (Returning.)\n", __FUNCTION__);
		return false;
	}
	// --------------------------------------------------------------------
    const char * szFoldername	= OTFolders::Pubkey().Get();
	const char * szFilename		= strID.Get();
	// --------------------------------------------------------------------
	const OTString strFoldername(szFoldername), strFilename(szFilename);
	
	// This loads up the ascii-armored Public Key.
	// On the client side, the entire x509 is stored in the cert folder.
    // (With other Nym's pubkeys stored in pubkey folder.)
	// On the server side, it's just the public key and stored here in pubkey folder.
    //
	const bool bCanLoadKeyFile = OTDB::Exists(szFoldername, szFilename);
	
	if (bCanLoadKeyFile)
	{		
		if (!m_pkeypair->LoadPublicKey(strFoldername, strFilename))
		{
			OTLog::vError("%s: Although the ascii-armored file (%s%s%s) was read, LoadPublicKey "
						  "returned false.\n", __FUNCTION__, szFoldername, OTLog::PathSeparator(), szFilename);
			return false;
		}
		else
		{
			OTLog::vOutput(4, "%s: Successfully loaded public key from file: %s%s%s\n", 
						   __FUNCTION__, szFoldername, OTLog::PathSeparator(), szFilename);
		}		
		return true;	
	}

	OTLog::vOutput(2, "%s: Failure.\n", __FUNCTION__);
	return false;
}





// DISPLAY STATISTICS

void OTPseudonym::DisplayStatistics(OTString & strOutput)
{
    FOR_EACH(mapOfRequestNums, m_mapRequestNum)
    {
        std::string strServerID	= it->first;
        long lRequestNumber		= it->second;
        
        // Now we can log BOTH, before and after...
        strOutput.Concatenate("Req# is %ld for server ID: %s\n", 
                              lRequestNumber, strServerID.c_str());
    }
    // -------------------------------------
    FOR_EACH(mapOfHighestNums, m_mapHighTransNo)
    {	
        std::string	strServerID = (*it).first;
        const long lHighestNum  = (*it).second;
        
        strOutput.Concatenate("Highest trans# was %ld for server: %s\n",
                              lHighestNum, strServerID.c_str());
    }
    
	FOR_EACH(mapOfTransNums, m_mapIssuedNum)
	{	
		std::string strServerID		= (*it).first;
		dequeOfTransNums * pDeque	= (it->second);
		
		OT_ASSERT(NULL != pDeque);
		
		if (!(pDeque->empty()))
		{
            strOutput.Concatenate("---- Transaction numbers still signed out from server: %s\n", strServerID.c_str());

			for (unsigned i = 0; i < pDeque->size(); i++)
			{
				long lTransactionNumber = pDeque->at(i);
				
				strOutput.Concatenate(0 == i ? "%ld" : ", %ld", lTransactionNumber);
			}
            strOutput.Concatenate("\n");
		}
	} // for
	
	FOR_EACH(mapOfTransNums, m_mapTransNum)
	{	
		std::string strServerID		= (*it).first;
		dequeOfTransNums * pDeque	= (it->second);
		
		OT_ASSERT(NULL != pDeque);
		
		if (!(pDeque->empty()))
		{
            strOutput.Concatenate("---- Transaction numbers still usable on server: %s\n", strServerID.c_str());

			for (unsigned i = 0; i < pDeque->size(); i++)
			{
				long lTransactionNumber = pDeque->at(i);
                strOutput.Concatenate(0 == i ? "%ld" : ", %ld", lTransactionNumber);
			}
            strOutput.Concatenate("\n");
		}
	} // for
	
	FOR_EACH(mapOfTransNums, m_mapAcknowledgedNum)
	{	
		std::string strServerID		= (*it).first;
		dequeOfTransNums * pDeque	= (it->second);
		
		OT_ASSERT(NULL != pDeque);
		
		if (!(pDeque->empty()))
		{
            strOutput.Concatenate("---- Request numbers for which Nym has already received a reply from server: %s\n",
                                  strServerID.c_str());

			for (unsigned i = 0; i < pDeque->size(); i++)
			{
				long lRequestNumber = pDeque->at(i);
                strOutput.Concatenate(0 == i ? "%ld" : ", %ld", lRequestNumber);

			}
            strOutput.Concatenate("\n");
		}
	} // for
    
    
    strOutput.Concatenate("Source for ID:\n%s\n", m_strSourceForNymID.Get());
    strOutput.Concatenate("Alt. location: %s\n\n", m_strAltLocation.Get());    

    const int nMasterCredCount = this->GetMasterCredentialCount();
    if (nMasterCredCount > 0)
    {
        for (int iii = 0; iii < nMasterCredCount; ++iii)
        {
            const OTCredential * pCredential = this->GetMasterCredentialByIndex(iii);
            if (NULL != pCredential)
            {                         
                strOutput.Concatenate("Credential ID: %s \n",
                                      pCredential->GetMasterCredID().Get());
                const int nSubcredentialCount = pCredential->GetSubcredentialCount();
                
                if (nSubcredentialCount > 0)
                {
                    for (int vvv = 0; vvv < nSubcredentialCount; ++vvv)
                    {
                        const std::string str_subcred_id(pCredential->GetSubcredentialIDByIndex(vvv));

                        strOutput.Concatenate("   Subcredential: %s  \n",
                                              str_subcred_id.c_str());
                    }
                }
                
            }
        }
        strOutput.Concatenate("%s", "\n");
    }
    // -----------------------------------------------------------------------
    strOutput.Concatenate("==>      Name: %s   %s\n", m_strName.Get(),
                          m_bMarkForDeletion ? "(MARKED FOR DELETION)" : "");
	strOutput.Concatenate("      Version: %s\n", m_strVersion.Get());
    
    // This is used on server-side only. (Client side sees this value
    // by querying the server.)
    // Therefore since m_lUsageCredits is unused on client side, why display
    // it in the client API? Makes no sense.
//	strOutput.Concatenate("Usage Credits: %ld\n", m_lUsageCredits);
    
    strOutput.Concatenate("       Mail count: %d\n", m_dequeMail.size());
	strOutput.Concatenate("    Outmail count: %d\n", m_dequeOutmail.size());
	strOutput.Concatenate("Outpayments count: %d\n", m_dequeOutpayments.size());
    
	OTString theStringID;
	GetIdentifier(theStringID);
	strOutput.Concatenate("Nym ID: %s\n", theStringID.Get());
}





bool OTPseudonym::SavePseudonym() 
{
	if (!m_strNymfile.GetLength())
	{
		OTString nymID;
		GetIdentifier(nymID);
		m_strNymfile.Format("%s", nymID.Get());
	}
	
	OTLog::vOutput(2, "Saving nym to: %s%s%s\n", 
				   OTFolders::Nym().Get(), OTLog::PathSeparator(), m_strNymfile.Get());
	
	return this->SavePseudonym(OTFolders::Nym().Get(), m_strNymfile.Get());
}



bool OTPseudonym::SavePseudonym(const char * szFoldername, const char * szFilename)
{	
	OT_ASSERT(NULL != szFoldername);
	OT_ASSERT(NULL != szFilename);
	
	OTString strNym;
	this->SavePseudonym(strNym);
	// -------------------------------------
	bool bSaved = OTDB::StorePlainString(strNym.Get(), szFoldername, szFilename);
	if (!bSaved)
		OTLog::vError("%s: Error saving file: %s%s%s\n", __FUNCTION__,
					  szFoldername, OTLog::PathSeparator(), szFilename);
    // --------------------------------------------------------------------
	return bSaved;
}



bool OTPseudonym::SavePseudonym(std::ofstream & ofs)
{
	OTString strNym;
	this->SavePseudonym(strNym);
		
	ofs << strNym.Get();
	
	return true;
}



// -----------------------------------------------------------------------------
// Used when importing/exporting Nym into and out-of the sphere of the cached key
// in the wallet.
bool OTPseudonym::ReEncryptPrivateCredentials(bool bImporting, //bImporting=true, or false if exporting.
                                              OTPasswordData * pPWData/*=NULL*/,
                                              OTPassword * pImportPassword/*=NULL*/)
{
    OTPassword * pExportPassphrase = NULL;
    OTCleanup<OTPassword> thePasswordAngel;
    
    if (NULL == pImportPassword)
    {
        // ----------------------------------------------------
        // whether import/export, this display string is for the OUTSIDE OF WALLET
        // portion of that process.
        //
        OTString strDisplay(NULL != pPWData ? pPWData->GetDisplayString() :
                            (bImporting ?
                             "Enter passphrase for the Nym being imported." :
                             "Enter passphrase for exported Nym."));
        // Circumvents the cached key.
        pExportPassphrase = OTSymmetricKey::GetPassphraseFromUser(&strDisplay, !bImporting); //bAskTwice is true when exporting (since the export passphrase is being created at that time.)
        thePasswordAngel.SetCleanupTargetPointer(pExportPassphrase);
        
        if (NULL == pExportPassphrase)
        {
            OTLog::vError("%s: Failed in GetPassphraseFromUser.\n", __FUNCTION__);
            return false;
        }
        // ----------------------------------------        
//      OTLog::vOutput(0, "%s: DEBUGGING pExportPassphrase, size %d, contains: %s \n",
//                     __FUNCTION__, pExportPassphrase->getPasswordSize(), pExportPassphrase->getPassword());
    }
    else
    {
        pExportPassphrase = pImportPassword;
        
//      OTLog::vOutput(0, "%s: DEBUGGING pImportPassword, size %d, contains: %s \n",
//                     __FUNCTION__, pImportPassword->getPasswordSize(), pImportPassword->getPassword());
    }
    // ****************************************************
    
    FOR_EACH(mapOfCredentials, m_mapCredentials)
    {
        OTCredential * pCredential = (*it).second;
        OT_ASSERT(NULL != pCredential);
        // -----------------------------
        if (false == pCredential->ReEncryptPrivateCredentials(*pExportPassphrase, bImporting))
            return false;
    }
    // ----------------------------------------------------
    return true;
}

// -----------------------------------------------------------------------------

// If the Nym's source is a URL, he needs to post his valid master credential IDs
// there, so they can be verified against their source. This method is what creates
// the file which you can post at that URL. (Containing only the valid IDs, not the revoked ones.)
// Optionally it also returns the contents of the public credential files, mapped by their
// credential IDs.
//
void OTPseudonym::GetPublicCredentials(OTString & strCredList, mapOfStrings * pmapCredFiles/*=NULL*/)
{
	OTString strNymID;
	this->GetIdentifier(strNymID);
	
	strCredList.Concatenate("<?xml version=\"%s\"?>\n", "2.0"); // todo hardcoding.
	
    strCredList.Concatenate("<OTuser version=\"%s\"\n"
                            " nymID=\"%s\""
                            ">\n\n",
                            m_strVersion.Get(),
                            strNymID.Get()
                            );
    // ----------------------------------------------------
    this->SerializeNymIDSource(strCredList);
    // ----------------------------------------------------
    FOR_EACH(mapOfCredentials, m_mapCredentials)
    {
        OTCredential * pCredential = (*it).second;
        OT_ASSERT(NULL != pCredential);
        // -----------------------------
        pCredential->SerializeIDs(strCredList, m_listRevokedIDs, pmapCredFiles); // bShowRevoked=false by default, bValid=true by default. (True since we're looping m_mapCredentials only, and not m_mapRevoked.)
    }
    // ----------------------------------------------------
    strCredList.Concatenate("</OTuser>\n");
}

// -----------------------------------------------------------------------------

void OTPseudonym::GetPrivateCredentials(OTString & strCredList, mapOfStrings * pmapCredFiles/*=NULL*/)
{
	OTString strNymID;
	this->GetIdentifier(strNymID);
	
	strCredList.Concatenate("<?xml version=\"%s\"?>\n", "2.0"); // todo hardcoding.
	
    strCredList.Concatenate("<OTuser version=\"%s\"\n"
                            " nymID=\"%s\""
                            ">\n\n",
                            m_strVersion.Get(),
                            strNymID.Get()
                            );
    // ----------------------------------------------------
    this->SerializeNymIDSource(strCredList);
    // ----------------------------------------------------
    this->SaveCredentialsToString(strCredList, NULL, pmapCredFiles);
    // ----------------------------------------------------
    strCredList.Concatenate("</OTuser>\n");
}

// -----------------------------------------------------------------------------

void OTPseudonym::SerializeNymIDSource(OTString & strOutput)
{
    // ----------------------------------
    // We encode these before storing.
    if (m_strSourceForNymID.Exists())
    {
        const OTASCIIArmor ascSourceForNymID(m_strSourceForNymID);
        
        if (m_strAltLocation.Exists())
        {
            OTASCIIArmor ascAltLocation;
            ascAltLocation.SetString(m_strAltLocation, false); //bLineBreaks=true by default.
            
            strOutput.Concatenate("<nymIDSource altLocation=\"%s\">\n%s</nymIDSource>\n\n",
                                  ascAltLocation.Get(), ascSourceForNymID.Get());
        }
        else
            strOutput.Concatenate("<nymIDSource>\n%s</nymIDSource>\n\n",
                                  ascSourceForNymID.Get());
    }
}
// -----------------------------------------------------------------------------

void OTPseudonym::SaveCredentialListToString(OTString & strOutput)
{
	OTString strNymID;
	this->GetIdentifier(strNymID);
	
	strOutput.Concatenate("<?xml version=\"%s\"?>\n", "2.0"); // todo hardcoding.
	
    strOutput.Concatenate("<OTuser version=\"%s\"\n"
                          " nymID=\"%s\""
                          ">\n\n",
                          m_strVersion.Get(),
                          strNymID.Get()
                          );
    // ----------------------------------------------------
    this->SerializeNymIDSource(strOutput);
    // ----------------------------------------------------
    this->SaveCredentialsToString(strOutput);
    // ----------------------------------------------------
    strOutput.Concatenate("</OTuser>\n");
}

// -----------------------------------------------------------------------------

bool OTPseudonym::SaveCredentialList()
{
	OTString strNymID, strOutput;
	this->GetIdentifier(strNymID);
    // ----------------------------------------------------
    this->SaveCredentialListToString(strOutput);
    
    if (strOutput.Exists())
    {
        OTASCIIArmor ascOutput(strOutput);
        strOutput.Release();
        if (ascOutput.WriteArmoredString(strOutput, "CREDENTIAL LIST") && // bEscaped=false by default.
            strOutput.Exists())
        {
            // ----------------------------------------------------
            // Save it to local storage.
            OTString strFilename;
            strFilename.Format("%s.cred", strNymID.Get());    
            
            std::string str_Folder = this->HasPrivateKey() ? OTFolders::Credential().Get() : OTFolders::Pubcred().Get();
            
            if (false == OTDB::StorePlainString(strOutput.Get(), str_Folder, strFilename.Get()))
            {
                OTLog::vError("%s: Failure trying to store %s credential list for Nym: %s\n",
                              __FUNCTION__, this->HasPrivateKey() ? "private" : "public", strNymID.Get());
                return false;
            }
            // ----------------------------------------------------
            return true;
        }
    }
    return false;
}


// -----------------------------------------------------------------------------
// Use this to load the keys for a Nym (whether public or private), and then
// call VerifyPseudonym, and then load the actual Nymfile using LoadSignedNymfile.
//
bool OTPseudonym::LoadCredentials(bool bLoadPrivate/*=false*/, // Loads public credentials by default. For private, pass true.
                                  OTPasswordData * pPWData/*=NULL*/,
                                  OTPassword * pImportPassword/*=NULL*/)
{
    OTString strReason(NULL == pPWData ? OT_PW_DISPLAY : pPWData->GetDisplayString());
	// --------------------------------------------------------------------
    this->ClearCredentials();
	// --------------------------------------------------------------------
	OTString strNymID;
    this->GetIdentifier(strNymID);	
	// --------------------------------------------------------------------
    OTString strFilename;
    strFilename.Format("%s.cred", strNymID.Get());
	// --------------------------------------------------------------------
    const char * szFoldername = bLoadPrivate ? OTFolders::Credential().Get() : OTFolders::Pubcred().Get();
	const char * szFilename   = strFilename.Get();
	// --------------------------------------------------------------------
    if (OTDB::Exists(szFoldername, szFilename))
    {
        OTString strFileContents(OTDB::QueryPlainString(szFoldername, szFilename));
        
        // The credential list file is like the nymfile except with ONLY credential IDs inside.
        // Therefore, we LOAD it like we're loading a Nymfile from string. There's no need for
        // the list itself to be signed, since we verify it fully before using it to verify the
        // signature on the actual nymfile.
        // How is the list safe not to be signed? Because the Nym ID's source string must hash
        // to form the NymID, and any credential IDs on the list must be found on a lookup to
        // that source. An attacker cannot add a credential without putting it inside the source,
        // which the user controls, and the attacker cannot change the source without changing
        // the NymID. Therefore the credential list file itself doesn't need to be signed, for
        // the same reason that the public key didn't need to be signed: because you can prove
        // its validity by hashing (the source string that validates the credentials in that list,
        // or by hashing/ the public key for that Nym, if doing things the old way.)
        //
        if (strFileContents.Exists() && strFileContents.DecodeIfArmored())
        {
            const bool bLoaded = this->LoadFromString(strFileContents,
                                                      NULL, // map of credentials--if NULL, it loads them from local storage.
                                                      &strReason,
                                                      pImportPassword); // optional to provide a passphrase (otherwise one is prompted for.)
            
            // Potentially set m_pkeypair here, though it's currently set in
            // LoadPublicKey and Loadx509CertAndPrivateKey.
            // (And thus set in static calls OTPseudonym::LoadPublicNym and LoadPrivateNym.)
            
            return bLoaded;
        }
        else
        {
            OTLog::vError("%s: Failed trying to load credential list from file: %s%s%s\n",
                           __FUNCTION__, szFoldername, OTLog::PathSeparator(), szFilename);
        }		
    }
    // ---------------------------------------
	return false; // No log on failure, since often this may be used to SEE if credentials exist.
                  // (No need for error message every time they don't exist.)
}

// -----------------------------------------------------------------------------

void OTPseudonym::SaveCredentialsToString(OTString     & strOutput,
                                          mapOfStrings * pmapPubInfo/*=NULL*/,
                                          mapOfStrings * pmapPriInfo/*=NULL*/)
{
	// *************************************************************************
    // IDs for revoked subcredentials are saved here.
    FOR_EACH(listOfStrings, m_listRevokedIDs)
    {
        std::string str_revoked_id = *it;
        strOutput.Concatenate("<revokedCredential\n"
						   " ID=\"%s\""
						   "/>\n\n",
						   str_revoked_id.c_str());
    }
    // -------------------------------------
    // Serialize master and sub-credentials here.
    FOR_EACH(mapOfCredentials, m_mapCredentials)
    {
        OTCredential * pCredential = (*it).second;
        OT_ASSERT(NULL != pCredential);
        // -----------------------------
        pCredential->SerializeIDs(strOutput, m_listRevokedIDs, pmapPubInfo, pmapPriInfo, true); // bShowRevoked=false by default (true here), bValid=true
    }
    // -------------------------------------
    // Serialize Revoked master credentials here, including their subkeys.
    FOR_EACH(mapOfCredentials, m_mapRevoked)
    {
        OTCredential * pCredential = (*it).second;
        OT_ASSERT(NULL != pCredential);
        // -----------------------------
        pCredential->SerializeIDs(strOutput, m_listRevokedIDs, pmapPubInfo, pmapPriInfo, true, false); // bShowRevoked=false by default. (Here it's true.) bValid=true by default. Here is for revoked, so false.
    }
	// *************************************************************************
}


// -----------------------------------------------------------------------------


// Save the Pseudonym to a string...
bool OTPseudonym::SavePseudonym(OTString & strNym)
{
	OTString nymID;
	this->GetIdentifier(nymID);
	
	strNym.Concatenate("<?xml version=\"%s\"?>\n", "2.0");
	
	if (m_lUsageCredits == 0)
		strNym.Concatenate("<OTuser version=\"%s\"\n"
						   " nymID=\"%s\""
						   ">\n\n", 
						   m_strVersion.Get(), 
						   nymID.Get()
						   );
	else
		strNym.Concatenate("<OTuser version=\"%s\"\n"
						   " nymID=\"%s\"\n"
						   " usageCredits=\"%ld\""
						   ">\n\n", 
						   m_strVersion.Get(), 
						   nymID.Get(),
						   m_lUsageCredits
						   );
	// *************************************************************************

    // ----------------------------------------------------
    this->SerializeNymIDSource(strNym);
    // ----------------------------------------------------

    // For now I'm saving the credential list to a separate file. (And then of course,
    // each credential also gets its own file.) We load the credential list file,
    // and any associated credentials, before loading the Nymfile proper.
    // Then we use the keys from those credentials possibly to verify the signature on
    // the Nymfile (or not, in the case of the server which uses its own key.)
    
//  this->SaveCredentialsToString(strNym);
    
	// *************************************************************************
	long lRequestNum;
	
	FOR_EACH(mapOfRequestNums, m_mapRequestNum)
	{	
		std::string	strServerID = (*it).first;
		lRequestNum = (*it).second;
		
		strNym.Concatenate("<requestNum\n"
						   " serverID=\"%s\"\n"
						   " currentRequestNum=\"%ld\""
						   "/>\n\n", 
						   strServerID.c_str(),
						   lRequestNum
						   );
	}
	// -------------------------------------
	long lHighestNum;
	
	FOR_EACH(mapOfHighestNums, m_mapHighTransNo)
	{	
		std::string	strServerID = (*it).first;
		lHighestNum = (*it).second;
		
		strNym.Concatenate("<highestTransNum\n"
						   " serverID=\"%s\"\n"
						   " mostRecent=\"%ld\""
						   "/>\n\n", 
						   strServerID.c_str(),
						   lHighestNum
						   );
	}
	// -------------------------------------
    // When you delete a Nym, it just marks it.
    // Actual deletion occurs during maintenance sweep (targeting marked nyms...)
    //
    if (m_bMarkForDeletion)
        strNym.Concatenate("<MARKED_FOR_DELETION>\n"
                           "%s</MARKED_FOR_DELETION>\n\n", 
                           "THIS NYM HAS BEEN MARKED FOR DELETION AT ITS OWN REQUEST");
	// -------------------------------------
	long lTransactionNumber = 0;
	
	FOR_EACH(mapOfTransNums, m_mapTransNum)
	{	
		std::string	strServerID		= (*it).first;
		dequeOfTransNums * pDeque	= (it->second);
		
		OT_ASSERT(NULL != pDeque);
		
//		if (!(pDeque->empty()) && (strServerID.size() > 0) )
//		{
//			for (unsigned i = 0; i < pDeque->size(); i++)
//			{
//				lTransactionNumber = pDeque->at(i);
//				
//				strNym.Concatenate("<transactionNum\n"
//								   " serverID=\"%s\"\n"
//								   " transactionNum=\"%ld\""
//								   "/>\n\n", 
//								   strServerID.c_str(),
//								   lTransactionNumber
//								   );
//			}
//		}
        
		if (!(pDeque->empty()) && (strServerID.size() > 0) )
		{
            OTNumList theList;
            
			for (unsigned i = 0; i < pDeque->size(); i++)
			{
				lTransactionNumber = pDeque->at(i);
                theList.Add(lTransactionNumber);
			}
            OTString strTemp;
            if ((theList.Count() > 0) && theList.Output(strTemp) && strTemp.Exists())
            {
                const OTASCIIArmor ascTemp(strTemp);
                
                if (ascTemp.Exists())
                    strNym.Concatenate("<transactionNums serverID=\"%s\">\n%s</transactionNums>\n\n",
                                       strServerID.c_str(), ascTemp.Get());
            }
		}
	} // for
	
	// -------------------------------------
	
	lTransactionNumber = 0;
	
	FOR_EACH(mapOfTransNums, m_mapIssuedNum)
	{	
		std::string	strServerID		= (*it).first;
		dequeOfTransNums * pDeque	= (it->second);
		
		OT_ASSERT(NULL != pDeque);
		
//		if (!(pDeque->empty()) && (strServerID.size() > 0) )
//		{
//			for (unsigned i = 0; i < pDeque->size(); i++)
//			{
//				lTransactionNumber = pDeque->at(i);
//				
//				strNym.Concatenate("<issuedNum\n"
//								   " serverID=\"%s\"\n"
//								   " transactionNum=\"%ld\""
//								   "/>\n\n", 
//								   strServerID.c_str(),
//								   lTransactionNumber
//								   );
//			}
//		}
        
        if (!(pDeque->empty()) && (strServerID.size() > 0) )
		{
            OTNumList theList;
            
			for (unsigned i = 0; i < pDeque->size(); i++)
			{
				lTransactionNumber = pDeque->at(i);
                theList.Add(lTransactionNumber);
			}
            OTString strTemp;
            if ((theList.Count() > 0) && theList.Output(strTemp) && strTemp.Exists())
            {
                const OTASCIIArmor ascTemp(strTemp);
                
                if (ascTemp.Exists())
                    strNym.Concatenate("<issuedNums serverID=\"%s\">\n%s</issuedNums>\n\n",
                                       strServerID.c_str(), ascTemp.Get());
            }
		}
	} // for
	
	// -------------------------------------
	
	lTransactionNumber = 0;
	
	FOR_EACH(mapOfTransNums, m_mapTentativeNum)
	{	
		std::string	strServerID		= (*it).first;
		dequeOfTransNums * pDeque	= (it->second);
		
		OT_ASSERT(NULL != pDeque);
		
//		if (!(pDeque->empty()) && (strServerID.size() > 0) )
//		{
//			for (unsigned i = 0; i < pDeque->size(); i++)
//			{
//				lTransactionNumber = pDeque->at(i);
//				
//				strNym.Concatenate("<tentativeNum\n"
//								   " serverID=\"%s\"\n"
//								   " transactionNum=\"%ld\""
//								   "/>\n\n", 
//								   strServerID.c_str(),
//								   lTransactionNumber
//								   );
//			}
//		}
        
        if (!(pDeque->empty()) && (strServerID.size() > 0) )
		{
            OTNumList theList;
            
			for (unsigned i = 0; i < pDeque->size(); i++)
			{
				lTransactionNumber = pDeque->at(i);
                theList.Add(lTransactionNumber);
			}
            OTString strTemp;
            if ((theList.Count() > 0) && theList.Output(strTemp) && strTemp.Exists())
            {
                const OTASCIIArmor ascTemp(strTemp);
                
                if (ascTemp.Exists())
                    strNym.Concatenate("<tentativeNums serverID=\"%s\">\n%s</tentativeNums>\n\n",
                                       strServerID.c_str(), ascTemp.Get());
            }
		}

	} // for
	
	// -------------------------------------
	
    // although mapOfTransNums is used, in this case,
    // request numbers are what is actually being stored.
    // The data structure just happened to be appropriate 
    // in this case, with generic manipulation functions
    // already written, so I used that pre-existing system.
    //
	FOR_EACH(mapOfTransNums, m_mapAcknowledgedNum)
	{	
		std::string	strServerID		= (*it).first;
		dequeOfTransNums * pDeque	= (it->second);
		
		OT_ASSERT(NULL != pDeque);
		
//		if (!(pDeque->empty()) && (strServerID.size() > 0) )
//		{
//			for (unsigned i = 0; i < pDeque->size(); i++)
//			{
//				const long lRequestNumber = pDeque->at(i);
//				
//				strNym.Concatenate("<acknowledgedNum\n"
//								   " serverID=\"%s\"\n"
//								   " requestNum=\"%ld\""
//								   "/>\n\n", 
//								   strServerID.c_str(),
//								   lRequestNumber
//								   );
//			}
//		}
        
        if (!(pDeque->empty()) && (strServerID.size() > 0) )
		{
            OTNumList theList;
            
			for (unsigned i = 0; i < pDeque->size(); i++)
			{
                const long lRequestNumber = pDeque->at(i);
                theList.Add(lRequestNumber);
			}
            OTString strTemp;
            if ((theList.Count() > 0) && theList.Output(strTemp) && strTemp.Exists())
            {
                const OTASCIIArmor ascTemp(strTemp);
                
                if (ascTemp.Exists())
                    strNym.Concatenate("<ackNums serverID=\"%s\">\n%s</ackNums>\n\n",
                                       strServerID.c_str(), ascTemp.Get());
            }
		}

	} // for
	
	// -------------------------------------
	
	if (!(m_dequeMail.empty()))
	{
		for (unsigned i = 0; i < m_dequeMail.size(); i++)
		{
			OTMessage * pMessage = m_dequeMail.at(i);
			OT_ASSERT(NULL != pMessage);
			
			OTString strMail(*pMessage);
			
			OTASCIIArmor ascMail;
			
			if (strMail.Exists())
				ascMail.SetString(strMail);
			
			if (ascMail.Exists())
				strNym.Concatenate("<mailMessage>\n"
								   "%s</mailMessage>\n\n", 
								   ascMail.Get());
		} 
	}
	
	// -------------------------------------
	
	
	if (!(m_dequeOutmail.empty()))
	{
		for (unsigned i = 0; i < m_dequeOutmail.size(); i++)
		{
			OTMessage * pMessage = m_dequeOutmail.at(i);
			OT_ASSERT(NULL != pMessage);
			
			OTString strOutmail(*pMessage);
			
			OTASCIIArmor ascOutmail;
			
			if (strOutmail.Exists())
				ascOutmail.SetString(strOutmail);
			
			if (ascOutmail.Exists())
				strNym.Concatenate("<outmailMessage>\n"
								   "%s</outmailMessage>\n\n", 
								   ascOutmail.Get());
		} 
	}
	
	// -------------------------------------
	
	if (!(m_dequeOutpayments.empty()))
	{
		for (unsigned i = 0; i < m_dequeOutpayments.size(); i++)
		{
			OTMessage * pMessage = m_dequeOutpayments.at(i);
			OT_ASSERT(NULL != pMessage);
			
			OTString strOutpayments(*pMessage);
			
			OTASCIIArmor ascOutpayments;
			
			if (strOutpayments.Exists())
				ascOutpayments.SetString(strOutpayments);
			
			if (ascOutpayments.Exists())
				strNym.Concatenate("<outpaymentsMessage>\n"
								   "%s</outpaymentsMessage>\n\n", 
								   ascOutpayments.Get());
		} 
	}
	
	// -------------------------------------
    // These are used on the server side.
    // (That's why you don't see the server ID saved here.)
    //
	if (!(m_setOpenCronItems.empty()))
	{
		FOR_EACH(std::set<long>, m_setOpenCronItems)
		{
            long lCronItemTransNum = *it;
            
            strNym.Concatenate("<hasOpenCronItem ID=\"%ld\" />\n\n",
                               lCronItemTransNum);
		} 
	}
	
	// -------------------------------------
    // These are used on the server side.
    // (That's why you don't see the server ID saved here.)
    //
	if (!(m_setAccounts.empty()))
	{
		FOR_EACH(std::set<std::string>, m_setAccounts)
		{
            std::string strAcctID = *it;
                        
            strNym.Concatenate("<ownsAssetAcct ID=\"%s\" />\n\n",
                               strAcctID.c_str());
		} 
	}
	
	// -------------------------------------
    // client-side
	FOR_EACH(mapOfIdentifiers, m_mapNymboxHash)
	{	
		std::string	strServerID		= (*it).first;
        OTIdentifier & theID        = (*it).second;
        
		if ( (strServerID.size() > 0) && !theID.IsEmpty())
		{
            const OTString strNymboxHash(theID);
            strNym.Concatenate("<nymboxHashItem\n"
                               " serverID=\"%s\"\n"
                               " nymboxHash=\"%s\""
                               "/>\n\n", 
                               strServerID.c_str(),
                               strNymboxHash.Get());
		}
	} // for
    
	// -------------------------------------
    // client-side
	FOR_EACH(mapOfIdentifiers, m_mapRecentHash)
	{	
		std::string	strServerID		= (*it).first;
        OTIdentifier & theID        = (*it).second;
        
		if ( (strServerID.size() > 0) && !theID.IsEmpty())
		{
            const OTString strRecentHash(theID);
            strNym.Concatenate("<recentHashItem\n"
                               " serverID=\"%s\"\n"
                               " recentHash=\"%s\""
                               "/>\n\n", 
                               strServerID.c_str(),
                               strRecentHash.Get());
		}
	} // for
    
	// -------------------------------------
    // server-side
    if (!m_NymboxHash.IsEmpty())
    {
        const OTString strNymboxHash(m_NymboxHash);
        strNym.Concatenate("<nymboxHash\n"
                           " value=\"%s\""
                           "/>\n\n", 
                           strNymboxHash.Get());
    }
	
	// -------------------------------------
	
    // -------------------------------------
    // client-side
	FOR_EACH(mapOfIdentifiers, m_mapInboxHash)
	{	
		std::string	strAcctID		= (*it).first;
        OTIdentifier & theID        = (*it).second;
        
		if ( (strAcctID.size() > 0) && !theID.IsEmpty())
		{
            const OTString strHash(theID);
            strNym.Concatenate("<inboxHashItem\n"
                               " accountID=\"%s\"\n"
                               " hashValue=\"%s\""
                               "/>\n\n", 
                               strAcctID.c_str(),
                               strHash.Get());
		}
	} // for
    
	// -------------------------------------
    // client-side
	FOR_EACH(mapOfIdentifiers, m_mapOutboxHash)
	{	
		std::string	strAcctID		= (*it).first;
        OTIdentifier & theID        = (*it).second;
        
		if ( (strAcctID.size() > 0) && !theID.IsEmpty())
		{
            const OTString strHash(theID);
            strNym.Concatenate("<outboxHashItem\n"
                               " accountID=\"%s\"\n"
                               " hashValue=\"%s\""
                               "/>\n\n", 
                               strAcctID.c_str(),
                               strHash.Get());
		}
	} // for
    
	// -------------------------------------
	
	strNym.Concatenate("</OTuser>\n");	
	
	return true;
	
}



// --------------------------------------------------------------

OTCredential * OTPseudonym::GetMasterCredential(const OTString & strID)
{
    mapOfCredentials::iterator iter = m_mapCredentials.find(strID.Get());
    OTCredential * pCredential = NULL;
    
    if (iter != m_mapCredentials.end()) // found it
        pCredential = (*iter).second;
    
    return pCredential;
}


// --------------------------------------------------------------

OTCredential * OTPseudonym::GetRevokedCredential(const OTString & strID)
{
    mapOfCredentials::iterator iter = m_mapRevoked.find(strID.Get());
    OTCredential * pCredential = NULL;
    
    if (iter != m_mapRevoked.end()) // found it
        pCredential = (*iter).second;
    
    return pCredential;
}

// --------------------------------------------------------------

const OTCredential * OTPseudonym::GetMasterCredentialByIndex(int nIndex) const
{
    if ((nIndex < 0) || (nIndex >= m_mapCredentials.size()))
    {
        OTLog::vError("%s: Index out of bounds: %d\n", __FUNCTION__, nIndex);
    }
    // --------------------
    else
    {
        int nLoopIndex = -1;
        
        FOR_EACH_CONST(mapOfCredentials, m_mapCredentials)
        {
            const OTCredential * pCredential = (*it).second;
            OT_ASSERT(NULL != pCredential);
            // ---------------------------------
            ++nLoopIndex; // 0 on first iteration.
            // ---------------------------------
            if (nLoopIndex == nIndex)
                return pCredential;
            // ---------------------------------
        }
    }
    return NULL;
}

const OTCredential * OTPseudonym::GetRevokedCredentialByIndex(int nIndex) const
{
    if ((nIndex < 0) || (nIndex >= m_mapRevoked.size()))
    {
        OTLog::vError("%s: Index out of bounds: %d\n", __FUNCTION__, nIndex);
    }
    // --------------------
    else
    {
        int nLoopIndex = -1;
        
        FOR_EACH_CONST(mapOfCredentials, m_mapRevoked)
        {
            const OTCredential * pCredential = (*it).second;
            OT_ASSERT(NULL != pCredential);
            // ---------------------------------
            ++nLoopIndex; // 0 on first iteration.
            // ---------------------------------
            if (nLoopIndex == nIndex)
                return pCredential;
            // ---------------------------------
        }
    }
    return NULL;
}


// ------------------------------------------------

const OTSubcredential * OTPseudonym::GetSubcredential(const OTString & strMasterID, const OTString & strSubCredID) const
{
    mapOfCredentials::const_iterator iter = m_mapCredentials.find(strMasterID.Get());
    const OTCredential * pMaster = NULL;
    
    if (iter != m_mapCredentials.end()) // found it
        pMaster = (*iter).second;
    
    if (NULL != pMaster)
    {
        const OTSubcredential * pSub = pMaster->GetSubcredential(strSubCredID, &m_listRevokedIDs);

        if (NULL != pSub)
            return pSub;
    }

    return NULL;
}


// Todo: if it's possible to have a revoked subcredential on a still-good master,
// this function doesn't account for that at all.
//
const OTSubcredential * OTPseudonym::GetRevokedSubcred(const OTString & strRevokedID, const OTString & strSubCredID) const 
{
    mapOfCredentials::const_iterator iter = m_mapRevoked.find(strRevokedID.Get());
    const OTCredential * pMaster = NULL;
    
    if (iter != m_mapRevoked.end()) // found it
        pMaster = (*iter).second;
    
    if (NULL != pMaster)
    {
        const OTSubcredential * pSub = pMaster->GetSubcredential(strSubCredID);
        
        if (NULL != pSub)
            return pSub;
    }
    
    return NULL;
}

// ------------------------------------------------



// --------------------------------------------------------------

//std::set<long> m_setOpenCronItems; // Until these Cron Items are closed out, the server-side Nym keeps a list of them handy.

//std::set<std::string> m_setAccounts; // A list of asset account IDs. Server side only (client side uses wallet; has multiple servers.)


/*
 
 Enumeration for all xml nodes which are parsed by IrrXMLReader.
 
 Enumeration values:
 
 EXN_NONE			No xml node. This is usually the node if you did not read anything yet.
 EXN_ELEMENT		A xml element, like <foo>.
 EXN_ELEMENT_END	End of an xml element, like </foo>.
 EXN_TEXT			Text within a xml element: <foo> this is the text. </foo>.
 EXN_COMMENT		An xml comment like <!-- I am a comment --> or a DTD definition.
 EXN_CDATA			An xml cdata section like <![CDATA[ this is some CDATA ]]>.
 EXN_UNKNOWN		Unknown element.
 
 Definition at line 180 of file irrXML.h.
 
 */
 // todo optimize
bool OTPseudonym::LoadFromString(const OTString & strNym,
                                 mapOfStrings * pMapCredentials/*=NULL*/, //pMapCredentials can be passed, if you prefer to use a specific set, instead of just loading the actual set from storage (such as during registration, when the credentials have been sent inside a message.)
                                 OTString     * pstrReason/*=NULL*/,
                                 OTPassword   * pImportPassword/*=NULL*/)
{
	bool bSuccess = false;
    // ------------------------------------
    ClearAll();  // Since we are loading everything up... (credentials are NOT cleared here. See note in OTPseudonym::ClearAll.)
    // ------------------------------------
	OTStringXML strNymXML(strNym); // todo optimize
	IrrXMLReader* xml = createIrrXMLReader(&strNymXML);
	OT_ASSERT(NULL != xml);
	OTCleanup<IrrXMLReader> theCleanup(*xml);
    
	// parse the file until end reached
	while(xml && xml->read())
	{
        
//        switch(xml->getNodeType())
//        {
//            case(EXN_NONE):
//                OTLog::Error("ACK NUMS: EXN_NONE --  No xml node. This is usually the node if you did not read anything yet.\n");
//                break;
//            case(EXN_ELEMENT):
//                OTLog::Error("ACK NUMS: EXN_ELEMENT -- An xml element such as <foo>.\n");
//                break;
//            case(EXN_ELEMENT_END):
//                OTLog::Error("ACK NUMS: EXN_ELEMENT_END -- End of an xml element such as </foo>.\n");
//                break;
//            case(EXN_TEXT):
//                OTLog::Error("ACK NUMS: EXN_TEXT -- Text within an xml element: <foo> this is the text. <foo>.\n");
//                break;
//            case(EXN_COMMENT):
//                OTLog::Error("ACK NUMS: EXN_COMMENT -- An xml comment like <!-- I am a comment --> or a DTD definition.\n");
//                break;
//            case(EXN_CDATA):
//                OTLog::Error("ACK NUMS: EXN_CDATA -- An xml cdata section like <![CDATA[ this is some CDATA ]]>.\n");
//                break;
//            case(EXN_UNKNOWN):
//                OTLog::Error("ACK NUMS: EXN_UNKNOWN -- Unknown element.\n");
//                break;
//            default:
//                OTLog::Error("ACK NUMS: default!! -- SHOULD NEVER HAPPEN...\n");
//                break;
//        }
//        OTLog::vError("OTPseudonym::LoadFromString: NODE DATA: %s\n", xml->getNodeData());

        
		// strings for storing the data that we want to read out of the file		
        //
		switch(xml->getNodeType())
		{
			case EXN_NONE:
			case EXN_TEXT:
			case EXN_COMMENT:
			case EXN_ELEMENT_END:
			case EXN_CDATA:
				// in this xml file, the only text which occurs is the messageText
				//messageText = xml->getNodeData();
                
//            switch(xml->getNodeType())
//            {
//                case(EXN_NONE):
//                    OTLog::Error("SKIPPING: EXN_NONE --  No xml node. This is usually the node if you did not read anything yet.\n");
//                    break;
//                case(EXN_TEXT):
//                    OTLog::Error("SKIPPING: EXN_TEXT -- Text within an xml element: <foo> this is the text. <foo>.\n");
//                    break;
//                case(EXN_COMMENT):
//                    OTLog::Error("SKIPPING: EXN_COMMENT -- An xml comment like <!-- I am a comment --> or a DTD definition.\n");
//                    break;
//                case(EXN_ELEMENT_END):
//                    OTLog::Error("SKIPPING: EXN_ELEMENT_END -- End of an xml element such as </foo>.\n");
//                    break;
//                case(EXN_CDATA):
//                    OTLog::Error("SKIPPING: EXN_CDATA -- An xml cdata section like <![CDATA[ this is some CDATA ]]>.\n");
//                    break;
//                default:
//                    OTLog::Error("SKIPPING: default!! -- SHOULD NEVER HAPPEN...\n");
//                    break;
//            }
                
				break;
			case EXN_ELEMENT:
			{
                const OTString strNodeName = xml->getNodeName();
//              OTLog::vError("PROCESSING EXN_ELEMENT: NODE NAME: %s\n", strNodeName.Get());

				if (strNodeName.Compare("OTuser"))
				{
                                   m_strVersion     = xml->getAttributeValue("version");
					const OTString UserNymID        = xml->getAttributeValue("nymID");

					// Server-side only...
					OTString strCredits = xml->getAttributeValue("usageCredits");
					
					if (strCredits.GetLength() > 0)
						m_lUsageCredits = atol(strCredits.Get());
					else
						m_lUsageCredits = 0; // This is the default anyway, but just being safe...

					//TODO: no need to set the ID again here. We already know the ID
					// at this point. Better to check and compare they are the same here.
					//m_nymID.SetString(UserNymID);
					
					if (UserNymID.GetLength())
						OTLog::vOutput(3, "\nLoading user, version: %s NymID:\n%s\n", m_strVersion.Get(), UserNymID.Get());
					bSuccess = true;
				}
                // ----------------------------------
                else if (strNodeName.Compare("nymIDSource"))
                {
//                  OTLog::Output(3, "Loading nymIDSource...\n");
                    OTASCIIArmor ascAltLocation = xml->getAttributeValue("altLocation"); // optional.
                    if (ascAltLocation.Exists())
                        ascAltLocation.GetString(m_strAltLocation, false); //bLineBreaks=true by default.
                    
                    if (false == OTContract::LoadEncodedTextField(xml, m_strSourceForNymID))
                    {
                        OTLog::vError("Error in %s line %d: failed loading expected nymIDSource field.\n",
                                      __FILE__, __LINE__);
                        return false; // error condition
                    }
                }
                // ----------------------------------
                else if (strNodeName.Compare("revokedCredential"))
				{
					const OTString strRevokedID = xml->getAttributeValue("ID");
                    OTLog::vOutput(3, "revokedCredential ID: %s\n", strRevokedID.Get());
                    listOfStrings::iterator iter = std::find(m_listRevokedIDs.begin(), m_listRevokedIDs.end(), strRevokedID.Get());
                    if (iter == m_listRevokedIDs.end()) // It's not already there, so it's safe to add it.
                        m_listRevokedIDs.push_back(strRevokedID.Get()); // todo optimize.
				}
                // ----------------------------------
                else if (strNodeName.Compare("masterCredential"))
				{
					const OTString strID    = xml->getAttributeValue("ID");
					const OTString strValid = xml->getAttributeValue("valid");
                    const bool bValid = strValid.Compare("true");
                    OTLog::vOutput(3, "Loading %s masterCredential ID: %s\n",
                                   bValid ? "valid" : "invalid", strID.Get());
                    OTString strNymID;
                    this->GetIdentifier(strNymID);
                    OTCredential * pCredential = NULL;
                    // -------------------------
                    if (NULL == pMapCredentials) // pMapCredentials is an option that allows you to read credentials from the map instead of from local storage. (While loading the Nym...) In this case, the option isn't being employed...
                        pCredential = OTCredential::LoadMaster(strNymID, strID);
                    else // In this case, it potentially is on the map...
                    {
                        mapOfStrings::iterator it_cred = pMapCredentials->find(strID.Get());
                        
                        if (it_cred == pMapCredentials->end()) // Nope, didn't find it on the map. But if a Map was passed, then it SHOULD have contained all the listed credentials (including the one we're trying to load now.)
                            OTLog::vError("%s: Expected master credential (%s) on map of credentials, but couldn't find it. (Failure.)\n",
                                          __FUNCTION__, strID.Get());
                        else // Found it on the map passed in (so no need to load from storage, we'll load from string instead.)
                        {
                            const OTString strMasterCredential((*it_cred).second.c_str());
                            if (strMasterCredential.Exists())
                            {
                                OTPasswordData thePWData(NULL == pstrReason ? "OTPseudonym::LoadFromString" : pstrReason->Get());
                                pCredential = OTCredential::LoadMasterFromString(strMasterCredential, strNymID, strID, &thePWData,
                                                                                 pImportPassword);
                            }
                        }
                    }
                    // -------------------------
                    if (NULL == pCredential)
                    {
                        OTLog::vError("%s: Failed trying to load Master Credential ID: %s\n",
                                      __FUNCTION__, strID.Get());
                        return false;
                    }
                    else // pCredential must be cleaned up or stored somewhere.
                    {
                        mapOfCredentials * pMap = bValid ? &m_mapCredentials : &m_mapRevoked;
                        mapOfCredentials::iterator iter = pMap->find(strID.Get());  // todo optimize.
                        if (iter == pMap->end()) // It's not already there, so it's safe to add it.
                            pMap->insert(std::pair<std::string, OTCredential *>(strID.Get(), pCredential)); // <=====
                        else
                        {
                            OTLog::vError("%s: While loading credential (%s), discovered it was already there "
                                          "on my list, or one with the exact same ID! Therefore, failed "
                                          "adding this newer one.\n", __FUNCTION__, strID.Get());
                            delete pCredential; pCredential = NULL;
                            return false;
                        }
                    }
				}
                // ----------------------------------
                else if (strNodeName.Compare("keyCredential"))
				{
					const OTString strID           = xml->getAttributeValue("ID");
					const OTString strValid        = xml->getAttributeValue("valid"); // If this is false, the ID is already on revokedCredentials list. (FYI.)
					const OTString strMasterCredID = xml->getAttributeValue("masterID");
                    const bool bValid = strValid.Compare("true");
                    OTLog::vOutput(3, "Loading %s keyCredential ID: %s\n ...For master credential: %s\n",
                                   bValid ? "valid" : "invalid", strID.Get(), strMasterCredID.Get());
                    OTCredential * pCredential = this->GetMasterCredential(strMasterCredID); // no need to cleanup.
                    if (NULL == pCredential)
                        pCredential = this->GetRevokedCredential(strMasterCredID);
                    if (NULL == pCredential)
                    {
                        OTLog::vError("%s: While loading keyCredential, failed trying to find expected Master Credential ID: %s\n",
                                      __FUNCTION__, strMasterCredID.Get());
                        return false;
                    }
                    else // We found the master credential that this keyCredential belongs to.
                    {
                        bool bLoaded = false;
                        // -------------------------
                        if (NULL == pMapCredentials) // pMapCredentials is an option that allows you to read credentials from the map instead of from local storage. (While loading the Nym...) In this case, the option isn't being employed...
                            bLoaded = pCredential->LoadSubkey(strID);
                        else // In this case, it potentially is on the map...
                        {
                            mapOfStrings::iterator it_cred = pMapCredentials->find(strID.Get());
                            
                            if (it_cred == pMapCredentials->end()) // Nope, didn't find it on the map. But if a Map was passed, then it SHOULD have contained all the listed credentials (including the one we're trying to load now.)
                                OTLog::vError("%s: Expected keyCredential (%s) on map of credentials, but couldn't find it. (Failure.)\n",
                                              __FUNCTION__, strID.Get());
                            else // Found it on the map passed in (so no need to load from storage, we'll load from string instead.)
                            {
                                const OTString strSubCredential((*it_cred).second.c_str());
                                if (strSubCredential.Exists())
                                    bLoaded = pCredential->LoadSubkeyFromString(strSubCredential, strID, pImportPassword);
                            }
                        }
                        // -------------------------
                        if (!bLoaded)
                        {
                            OTString strNymID;
                            this->GetIdentifier(strNymID);
                            OTLog::vError("%s: Failed loading keyCredential %s for master credential %s for Nym %s.\n",
                                          __FUNCTION__, strID.Get(), strMasterCredID.Get(), strNymID.Get());
                            return false;
                        }
                    }
				}
                // ----------------------------------
                else if (strNodeName.Compare("subCredential"))
				{
					const OTString strID           = xml->getAttributeValue("ID");
					const OTString strValid        = xml->getAttributeValue("valid"); // If this is false, the ID is already on revokedCredentials list. (FYI.)
					const OTString strMasterCredID = xml->getAttributeValue("masterID");
                    const bool bValid = strValid.Compare("true");
                    OTLog::vOutput(3, "Loading %s subCredential ID: %s\n ...For master credential: %s\n",
                                   bValid ? "valid" : "invalid", strID.Get(), strMasterCredID.Get());
                    OTCredential * pCredential = this->GetMasterCredential(strMasterCredID); // no need to cleanup.
                    if (NULL == pCredential)
                        pCredential = this->GetRevokedCredential(strMasterCredID);
                    if (NULL == pCredential)
                    {
                        OTLog::vError("%s: While loading subCredential, failed trying to find expected Master Credential ID: %s\n",
                                      __FUNCTION__, strMasterCredID.Get());
                        return false;
                    }
                    else // We found the master credential that this subCredential belongs to.
                    {
                        bool bLoaded = false;
                        // -------------------------
                        if (NULL == pMapCredentials) // pMapCredentials is an option that allows you to read credentials from the map instead of from local storage. (While loading the Nym...) In this case, the option isn't being employed...
                            bLoaded = pCredential->LoadSubcredential(strID);
                        else // In this case, it potentially is on the map...
                        {
                            mapOfStrings::iterator it_cred = pMapCredentials->find(strID.Get());
                            
                            if (it_cred == pMapCredentials->end())// Nope, didn't find it on the map. But if a Map was passed, then it SHOULD have contained all the listed credentials (including the one we're trying to load now.)
                                OTLog::vError("%s: Expected subCredential (%s) on map of credentials, but couldn't find it. (Failure.)\n",
                                              __FUNCTION__, strID.Get());
                            else // Found it on the map passed in (so no need to load from storage, we'll load from string instead.)
                            {
                                const OTString strSubCredential((*it_cred).second.c_str());
                                if (strSubCredential.Exists())
                                    bLoaded = pCredential->LoadSubcredentialFromString(strSubCredential, strID, pImportPassword);
                            }
                        }
                        // -------------------------
                        if (!bLoaded)
                        {
                            OTString strNymID;
                            this->GetIdentifier(strNymID);
                            OTLog::vError("%s: Failed loading subCredential %s for master credential %s for Nym %s.\n",
                                          __FUNCTION__, strID.Get(), strMasterCredID.Get(), strNymID.Get());
                            return false;
                        }
                    }
                }
                // ----------------------------------
				else if (strNodeName.Compare("requestNum"))
				{
					const OTString ReqNumServerID = xml->getAttributeValue("serverID");
					const OTString ReqNumCurrent  = xml->getAttributeValue("currentRequestNum");
					
					OTLog::vOutput(3, "\nCurrent Request Number is %s for ServerID: %s\n",
								   ReqNumCurrent.Get(), ReqNumServerID.Get());
					
					// Make sure now that I've loaded this request number, to add it to my
					// internal map so that it is available for future lookups.
					m_mapRequestNum[ReqNumServerID.Get()] = atol(ReqNumCurrent.Get());
				}                
				else if (strNodeName.Compare("nymboxHash"))
				{
					const OTString strValue = xml->getAttributeValue("value");				
					
					OTLog::vOutput(3, "\nNymboxHash is: %s\n", strValue.Get());
					
                    if (strValue.Exists())
                        m_NymboxHash.SetString(strValue);
				}
                else if (strNodeName.Compare("nymboxHashItem"))
				{
					const OTString strServerID      = xml->getAttributeValue("serverID");				
					const OTString strNymboxHash    = xml->getAttributeValue("nymboxHash");
					
					OTLog::vOutput(3, "\nNymboxHash is %s for ServerID: %s\n",
								   strNymboxHash.Get(), strServerID.Get());
					
					// Make sure now that I've loaded this nymboxHash, to add it to my
					// internal map so that it is available for future lookups.
                    if (strServerID.Exists() && strNymboxHash.Exists())
                    {
                        const OTIdentifier theID(strNymboxHash);
                        m_mapNymboxHash[strServerID.Get()] = theID;
                    }
				}
                else if (strNodeName.Compare("recentHashItem"))
				{
					const OTString strServerID      = xml->getAttributeValue("serverID");				
					const OTString strRecentHash    = xml->getAttributeValue("recentHash");
					
					OTLog::vOutput(3, "\nRecentHash is %s for ServerID: %s\n",
								   strRecentHash.Get(), strServerID.Get());
					
					// Make sure now that I've loaded this RecentHash, to add it to my
					// internal map so that it is available for future lookups.
                    if (strServerID.Exists() && strRecentHash.Exists())
                    {
                        const OTIdentifier theID(strRecentHash);
                        m_mapRecentHash[strServerID.Get()] = theID;
                    }
				}
                else if (strNodeName.Compare("inboxHashItem"))
				{
					const OTString strAccountID    = xml->getAttributeValue("accountID");				
					const OTString strHashValue    = xml->getAttributeValue("hashValue");
					
					OTLog::vOutput(3, "\nInboxHash is %s for Account ID: %s\n",
								   strHashValue.Get(), strAccountID.Get());
					
					// Make sure now that I've loaded this InboxHash, to add it to my
					// internal map so that it is available for future lookups.
                    //
                    if (strAccountID.Exists() && strHashValue.Exists())
                    {
                        const OTIdentifier theID(strHashValue);
                        m_mapInboxHash[strAccountID.Get()] = theID;
                    }
				}
                else if (strNodeName.Compare("outboxHashItem"))
				{
					const OTString strAccountID    = xml->getAttributeValue("accountID");				
					const OTString strHashValue    = xml->getAttributeValue("hashValue");
					
					OTLog::vOutput(3, "\nOutboxHash is %s for Account ID: %s\n",
								   strHashValue.Get(), strAccountID.Get());
					
					// Make sure now that I've loaded this OutboxHash, to add it to my
					// internal map so that it is available for future lookups.
                    //
                    if (strAccountID.Exists() && strHashValue.Exists())
                    {
                        const OTIdentifier theID(strHashValue);
                        m_mapOutboxHash[strAccountID.Get()] = theID;
                    }
				}
				else if (strNodeName.Compare("highestTransNum"))
				{
					const OTString HighNumServerID = xml->getAttributeValue("serverID");				
					const OTString HighNumRecent = xml->getAttributeValue("mostRecent");
					
					OTLog::vOutput(3, "\nHighest Transaction Number ever received is %s for ServerID: %s\n",
								   HighNumRecent.Get(), HighNumServerID.Get());
					
					// Make sure now that I've loaded this highest number, to add it to my
					// internal map so that it is available for future lookups.
					m_mapHighTransNo[HighNumServerID.Get()] = atol(HighNumRecent.Get());
				}
                // ----------------------------------------------
                
                else if (strNodeName.Compare("transactionNums"))
                {
                    const OTString tempServerID	= xml->getAttributeValue("serverID");				
                    OTString strTemp;
                    if (!tempServerID.Exists() || !OTContract::LoadEncodedTextField(xml, strTemp))
                    {
                        OTLog::vError("%s: Error: transactionNums field without value.\n", __FUNCTION__);
                        return false; // error condition
                    }
                    OTNumList theNumList;
                    
                    if (strTemp.Exists())
                        theNumList.Add(strTemp);
                    
                    long lTemp=0;
                    while(theNumList.Peek(lTemp))
                    {
                        theNumList.Pop();
                        // ------------
                        OTLog::vOutput(3, "Transaction Number %ld ready-to-use for ServerID: %s\n",
                                       lTemp, tempServerID.Get());
                        AddTransactionNum(tempServerID, lTemp); // This version doesn't save to disk. (Why save to disk AS WE'RE LOADING?)
                    }
                }
                
                // ----------------------------------------------
                
                else if (strNodeName.Compare("issuedNums"))
                {	
                    const OTString tempServerID	= xml->getAttributeValue("serverID");				
                    OTString strTemp;
                    if (!tempServerID.Exists() || !OTContract::LoadEncodedTextField(xml, strTemp))
                    {
                        OTLog::vError("%s: Error: issuedNums field without value.\n", __FUNCTION__);
                        return false; // error condition
                    }
                    OTNumList theNumList;
                    
                    if (strTemp.Exists())
                        theNumList.Add(strTemp);
                    
                    long lTemp=0;
                    while(theNumList.Peek(lTemp))
                    {
                        theNumList.Pop();
                        // ------------
                        OTLog::vOutput(3, "Currently liable for issued trans# %ld at ServerID: %s\n",
                                       lTemp, tempServerID.Get());
                        AddIssuedNum(tempServerID, lTemp); // This version doesn't save to disk. (Why save to disk AS WE'RE LOADING?)
                    }
                }
                
                // ----------------------------------------------
                
                else if (strNodeName.Compare("tentativeNums"))
                {	
                    const OTString tempServerID	= xml->getAttributeValue("serverID");				
                    OTString strTemp;
                    if (!tempServerID.Exists() || !OTContract::LoadEncodedTextField(xml, strTemp))
                    {
                        OTLog::Error("OTPseudonym::LoadFromString: Error: tentativeNums field without value.\n");
                        return false; // error condition
                    }
                    OTNumList theNumList;
                    
                    if (strTemp.Exists())
                        theNumList.Add(strTemp);
                    
                    long lTemp=0;
                    while(theNumList.Peek(lTemp))
                    {
                        theNumList.Pop();
                        // ------------
                        OTLog::vOutput(3, "Tentative: Currently awaiting success notice, "
                                       "for accepting trans# %ld for ServerID: %s\n",
                                       lTemp, tempServerID.Get());
                        AddTentativeNum(tempServerID, lTemp); // This version doesn't save to disk. (Why save to disk AS WE'RE LOADING?)
                    }
                }
                
                // ----------------------------------------------
                
                else if (strNodeName.Compare("ackNums"))
                {	
                    const OTString tempServerID	= xml->getAttributeValue("serverID");				
                    OTString strTemp;
                    if (!tempServerID.Exists())
                    {
                        OTLog::vError("%s: Error: While loading ackNums "
                                      "field: Missing serverID. Nym contents:\n\n%s\n\n",
                                      __FUNCTION__, strNym.Get());
                        return false; // error condition
                    }
                    // ----------------------
                    
//                  xml->read(); // there should be a text field next, with the data for the list of acknowledged numbers.
                    // Note: I think I was forced to add this when the numlist was empty, one time, so this may come back
                    // to haunt me, but I want to fix it right, not kludge it.
                    //
                    // ----------------------
                    if (!OTContract::LoadEncodedTextField(xml, strTemp))
                    {
                        OTLog::vError("%s: Error: ackNums field without value "
                                      "(at least, unable to LoadEncodedTextField on that value.)\n", __FUNCTION__);
                        return false; // error condition
                    }
                    OTNumList theNumList;
                    
                    if (strTemp.Exists())
                        theNumList.Add(strTemp);
                    
                    long lTemp=0;
                    while(theNumList.Peek(lTemp))
                    {
                        theNumList.Pop();
                        // ------------
                        OTLog::vOutput(2, "Acknowledgment record exists for server reply, for Request Number %ld for ServerID: %s\n",
                                       lTemp, tempServerID.Get());
                        AddAcknowledgedNum(tempServerID, lTemp); // This version doesn't save to disk. (Why save to disk AS WE'RE LOADING?)
                    }
                }
                
                // ----------------------------------------------
                
                // THE BELOW FOUR ARE DEPRECATED, AND ARE REPLACED BY THE ABOVE FOUR.
                
				else if (strNodeName.Compare("transactionNum"))
				{
					const OTString TransNumServerID  = xml->getAttributeValue("serverID");
					const OTString TransNumAvailable = xml->getAttributeValue("transactionNum");
					
					OTLog::vOutput(3, "Transaction Number %s available for ServerID: %s\n",
								   TransNumAvailable.Get(), TransNumServerID.Get());
					
					AddTransactionNum(TransNumServerID, atol(TransNumAvailable.Get())); // This version doesn't save to disk. (Why save to disk AS WE'RE LOADING?)
				}
				else if (strNodeName.Compare("issuedNum"))
				{
					const OTString TransNumServerID  = xml->getAttributeValue("serverID");
					const OTString TransNumAvailable = xml->getAttributeValue("transactionNum");
					
					OTLog::vOutput(3, "Currently liable for Transaction Number %s, for ServerID: %s\n",
								   TransNumAvailable.Get(), TransNumServerID.Get());
					
					AddIssuedNum(TransNumServerID, atol(TransNumAvailable.Get())); // This version doesn't save to disk. (Why save to disk AS WE'RE LOADING?)
				}
				else if (strNodeName.Compare("tentativeNum"))
				{
					const OTString TransNumServerID  = xml->getAttributeValue("serverID");
					const OTString TransNumAvailable = xml->getAttributeValue("transactionNum");
					
					OTLog::vOutput(3, "Currently waiting on server success notice, accepting Transaction Number %s, for ServerID: %s\n",
								   TransNumAvailable.Get(), TransNumServerID.Get());
					
					AddTentativeNum(TransNumServerID, atol(TransNumAvailable.Get())); // This version doesn't save to disk. (Why save to disk AS WE'RE LOADING?)
				}                
				else if (strNodeName.Compare("acknowledgedNum"))
				{
					const OTString AckNumServerID = xml->getAttributeValue("serverID");
					const OTString AckNumValue    = xml->getAttributeValue("requestNum");
					
					OTLog::vOutput(3, "Acknowledgment record exists for server reply, for Request Number %s, for ServerID: %s\n",
								   AckNumValue.Get(), AckNumServerID.Get());
					
					AddAcknowledgedNum(AckNumServerID, atol(AckNumValue.Get())); // This version doesn't save to disk. (Why save to disk AS WE'RE LOADING?)
				}                
                // -------------------------------------
                else if (strNodeName.Compare("MARKED_FOR_DELETION"))
				{
					m_bMarkForDeletion = true;  
                    OTLog::vOutput(3, "This nym has been MARKED_FOR_DELETION (at some point prior.)\n");
				}
                // -------------------------------------
                
				else if (!!strNodeName.Compare("hasOpenCronItem"))
				{
                    OTString strID = xml->getAttributeValue("ID");
					
                    if (strID.Exists())
                    {
                        const long lNewID = atol(strID.Get()); 
                        m_setOpenCronItems.insert(lNewID);
                        OTLog::vOutput(3, "This nym has an open cron item with ID: %s\n",
                                       strID.Get());
                    }
                    else
                        OTLog::vOutput(3, "This nym MISSING ID when loading open cron item record.\n");
				}
				else if (strNodeName.Compare("ownsAssetAcct"))
				{
                    OTString strID = xml->getAttributeValue("ID");
					
                    if (strID.Exists())
                    {
                        m_setAccounts.insert(strID.Get());
                        OTLog::vOutput(3, "This nym has an asset account with the ID: %s\n",
                                       strID.Get());
                    }
                    else
                        OTLog::vOutput(3, "This nym MISSING asset account ID when loading nym record.\n");
				}
				else if (strNodeName.Compare("mailMessage"))
				{					
					OTASCIIArmor armorMail;
					OTString     strMessage;
					
					xml->read();
					
					if (EXN_TEXT == xml->getNodeType())
					{
						OTString strNodeData = xml->getNodeData();
						
						// Sometimes the XML reads up the data with a prepended newline.
						// This screws up my own objects which expect a consistent in/out
						// So I'm checking here for that prepended newline, and removing it.
						char cNewline;
						if (strNodeData.Exists() && strNodeData.GetLength() > 2 && strNodeData.At(0, cNewline))
						{
							if ('\n' == cNewline)
								armorMail.Set(strNodeData.Get() + 1); // I know all this shit is ugly. I refactored this in OTContract.
							else										// unfortunately OTNym is like a "basic type" and isn't derived from OTContract.
								armorMail.Set(strNodeData.Get());       // TODO: OTContract now has STATIC methods for this. (Start using them here...)
							
							if (armorMail.GetLength() > 2)
							{
								armorMail.GetString(strMessage, true); // linebreaks == true.
								
								if (strMessage.GetLength() > 2)
								{
									OTMessage * pMessage = new OTMessage;
									
									OT_ASSERT(NULL != pMessage);
									
									if (pMessage->LoadContractFromString(strMessage))
										m_dequeMail.push_back(pMessage); // takes ownership
									else
										delete pMessage;
								}
							} // armorMail
						} // strNodeData
					} // EXN_TEXT
				}
				else if (strNodeName.Compare("outmailMessage"))
				{					
					OTASCIIArmor armorMail;
					OTString     strMessage;
					
					xml->read();
					
					if (EXN_TEXT == xml->getNodeType())
					{
						OTString strNodeData = xml->getNodeData();
						
						// Sometimes the XML reads up the data with a prepended newline.
						// This screws up my own objects which expect a consistent in/out
						// So I'm checking here for that prepended newline, and removing it.
						char cNewline;
						if (strNodeData.Exists() && strNodeData.GetLength() > 2 && strNodeData.At(0, cNewline))
						{
							if ('\n' == cNewline)
								armorMail.Set(strNodeData.Get() + 1);
							else
								armorMail.Set(strNodeData.Get());
							
							if (armorMail.GetLength() > 2)
							{
								armorMail.GetString(strMessage, true); // linebreaks == true.
								
								if (strMessage.GetLength() > 2)
								{
									OTMessage * pMessage = new OTMessage;
									OT_ASSERT(NULL != pMessage);
									
									if (pMessage->LoadContractFromString(strMessage))
										m_dequeOutmail.push_back(pMessage); // takes ownership
									else
										delete pMessage;
								}
							} // armorMail
						} // strNodeData
					} // EXN_TEXT
				} // outpayments message
				else if (strNodeName.Compare("outpaymentsMessage"))
				{					
					OTASCIIArmor armorMail;
					OTString     strMessage;
					
					xml->read();
					
					if (EXN_TEXT == xml->getNodeType())
					{
						OTString strNodeData = xml->getNodeData();
						
						// Sometimes the XML reads up the data with a prepended newline.
						// This screws up my own objects which expect a consistent in/out
						// So I'm checking here for that prepended newline, and removing it.
						char cNewline;
						if (strNodeData.Exists() && strNodeData.GetLength() > 2 && strNodeData.At(0, cNewline))
						{
							if ('\n' == cNewline)
								armorMail.Set(strNodeData.Get() + 1);
							else
								armorMail.Set(strNodeData.Get());
							
							if (armorMail.GetLength() > 2)
							{
								armorMail.GetString(strMessage, true); // linebreaks == true.
								
								if (strMessage.GetLength() > 2)
								{
									OTMessage * pMessage = new OTMessage;
									OT_ASSERT(NULL != pMessage);
									
									if (pMessage->LoadContractFromString(strMessage))
										m_dequeOutpayments.push_back(pMessage); // takes ownership
									else
										delete pMessage;
								}
							}
						} // strNodeData
					} // EXN_TEXT
				} // outpayments message
				else
				{
					// unknown element type
					OTLog::vError("Unknown element type in %s: %s\n", __FUNCTION__, xml->getNodeName());
					bSuccess = false;
				}
				break;
			}
			default:
			{
				OTLog::vOutput(5, "Unknown XML type in %s: %s\n", __FUNCTION__, xml->getNodeName());
				break;	
			}
		} // switch
	} // while

	return bSuccess;
}




bool OTPseudonym::LoadSignedNymfile(OTPseudonym & SIGNER_NYM)
{
	// Get the Nym's ID in string form
	OTString nymID;
	this->GetIdentifier(nymID);
	
	// Create an OTSignedFile object, giving it the filename (the ID) and the local directory ("nyms")
	OTSignedFile theNymfile(OTFolders::Nym(), nymID);
	
	if (false == theNymfile.LoadFile())
	{
		OTLog::vOutput(0, "%s: Failed loading a signed nymfile: %s\n\n", __FUNCTION__, nymID.Get());
	}
	// We verify:
	//
	// 1. That the file even exists and loads.
	// 2. That the local subdir and filename match the versions inside the file.
	// 3. That the signature matches for the signer nym who was passed in.
	//
    else if (false == theNymfile.VerifyFile())
    {
        OTLog::vError("%s: Failed verifying nymfile: %s\n\n",
                      __FUNCTION__, nymID.Get());
    }
    else if (false == theNymfile.VerifySignature(SIGNER_NYM))
    {
        OTString strSignerNymID;
        SIGNER_NYM.GetIdentifier(strSignerNymID);
        OTLog::vError("%s: Failed verifying signature on nymfile: %s\n Signer Nym ID: %s\n",
                      __FUNCTION__, nymID.Get(), strSignerNymID.Get());
    }
    // NOTE: Comment out the above two blocks if you want to load a Nym without having
    // to verify his information. (For development reasons. Never do that normally.)
    // -----------------------------------
    else
	{
		OTLog::Output(2, "Loaded and verified signed nymfile. Reading from string...\n");
		
		if (theNymfile.GetFilePayload().GetLength() > 0)
			return this->LoadFromString(theNymfile.GetFilePayload()); // <====== Success...
		else 
		{
			const long lLength = static_cast<long> (theNymfile.GetFilePayload().GetLength());
			
			OTLog::vError("%s: Bad length (%ld) while loading nymfile: %s\n",
                          __FUNCTION__, lLength, nymID.Get());
		}
	}
    // -----------------------------------
	return false;
}



bool OTPseudonym::SaveSignedNymfile(OTPseudonym & SIGNER_NYM)
{
	// Get the Nym's ID in string form
	OTString strNymID;
	this->GetIdentifier(strNymID);

	// Create an OTSignedFile object, giving it the filename (the ID) and the local directory ("nyms")
	OTSignedFile	theNymfile(OTFolders::Nym().Get(), strNymID);
	theNymfile.GetFilename(m_strNymfile);
	
	OTLog::vOutput(2, "Saving nym to: %s\n", m_strNymfile.Get());
	
	// First we save this nym to a string...
	// Specifically, the file payload string on the OTSignedFile object.
	this->SavePseudonym(theNymfile.GetFilePayload());

	// Now the OTSignedFile contains the path, the filename, AND the
	// contents of the Nym itself, saved to a string inside the OTSignedFile object.
	
	if (theNymfile.SignContract(SIGNER_NYM) && 
		theNymfile.SaveContract())
	{
        const bool bSaved = theNymfile.SaveFile();
        
        if (!bSaved)
        {
            OTString strSignerNymID;
            SIGNER_NYM.GetIdentifier(strSignerNymID);
            OTLog::vError("%s: Failed while calling theNymfile.SaveFile() for Nym %s using Signer Nym %s\n",
                          __FUNCTION__, strNymID.Get(), strSignerNymID.Get());
        }
        
		return bSaved;
	}
    else
    {
        OTString strSignerNymID;
        SIGNER_NYM.GetIdentifier(strSignerNymID);
        OTLog::vError("%s: Failed trying to sign and save Nymfile for Nym %s using Signer Nym %s\n",
                      __FUNCTION__, strNymID.Get(), strSignerNymID.Get());
    }
	
	return false;
}


/// See if two nyms have identical lists of issued transaction numbers (#s currently signed for.)
//
bool OTPseudonym::VerifyIssuedNumbersOnNym(OTPseudonym & THE_NYM)
{
	long lTransactionNumber	= 0; // Used in the loop below.
	
	int nNumberOfTransactionNumbers1 = 0; // *this
	int nNumberOfTransactionNumbers2 = 0; // THE_NYM.
	
	std::string	strServerID;
	
	// First, loop through the Nym on my side (*this), and count how many numbers total he has...
	//
	FOR_EACH(mapOfTransNums, GetMapIssuedNum())
	{	
//		strServerID					= (*it).first;
		dequeOfTransNums * pDeque	= (it->second);		
		OT_ASSERT(NULL != pDeque);
		
		if (!(pDeque->empty()))
		{
			nNumberOfTransactionNumbers1 += static_cast<int> (pDeque->size());
		}
	} // for
	
	// Next, loop through THE_NYM, and count his numbers as well...
	// But ALSO verify that each one exists on *this, so that each individual
	// number is checked.
	//
	FOR_EACH(mapOfTransNums, THE_NYM.GetMapIssuedNum())
	{	
		strServerID					= (*it).first;
		dequeOfTransNums * pDeque	= (it->second);
		OT_ASSERT(NULL != pDeque);
		
		OTString OTstrServerID = strServerID.c_str();
				
		if (!(pDeque->empty()))
		{
			for (unsigned i = 0; i < pDeque->size(); i++)
			{
				lTransactionNumber = pDeque->at(i);
				
//				if ()
				{
					nNumberOfTransactionNumbers2 ++ ; 
					
					if (false == VerifyIssuedNum(OTstrServerID, lTransactionNumber))
					{
						OTLog::vOutput(0, "OTPseudonym::VerifyIssuedNumbersOnNym: Issued transaction # %ld from THE_NYM not found on *this.\n", 
									   lTransactionNumber);
						
						return false;
					}
				}
			}
		}
	} // for
	
	// Finally, verify that the counts match...
	if (nNumberOfTransactionNumbers1 != nNumberOfTransactionNumbers2)
	{
		OTLog::vOutput(0, "OTPseudonym::VerifyIssuedNumbersOnNym: Issued transaction # Count mismatch: %d and %d\n", 
					   nNumberOfTransactionNumbers1, nNumberOfTransactionNumbers2);
		
		return false;
	}	
	
	return true;
}


// This is client-side. It's called by VerifyTransactionReceipt and VerifyBalanceReceipt.
//
// It's okay if some issued transaction #s in THE_NYM (the receipt's Nym) aren't found on *this, (client-side Nym)
// since the last balance agreement may have cleaned them out after they were recorded in THE_NYM 
// (from the transaction statement receipt).
//
// But I should never see transaction #s APPEAR in *this that aren't in THE_NYM on receipt, since a balance agreement
// can ONLY remove numbers, not add them. So any numbers left over should still be accounted for on the
// last signed receipt (which supplied THE_NYM as that list of numbers.)
//
// Conclusion: Loop through *this, which is newer, and make sure ALL numbers appear on THE_NYM.
// No need to check the reverse, and no need to match the count.
//
bool OTPseudonym::VerifyTransactionStatementNumbersOnNym(OTPseudonym & THE_NYM) // THE_NYM is from the receipt.
{
	long lTransactionNumber	= 0; // Used in the loop below.
	
	std::string	strServerID;
	
	// First, loop through the Nym on my side (*this), and verify that all those #s appear on the last receipt (THE_NYM)
	//
	FOR_EACH(mapOfTransNums, GetMapIssuedNum())
	{	
		strServerID					= (*it).first;
		dequeOfTransNums * pDeque	= (it->second);
		
		OTString OTstrServerID = strServerID.c_str();
		
		OT_ASSERT(NULL != pDeque);
		
		if (!(pDeque->empty()))
		{
			for (unsigned i = 0; i < pDeque->size(); i++)
			{
				lTransactionNumber = pDeque->at(i);

				if (false == THE_NYM.VerifyIssuedNum(OTstrServerID, lTransactionNumber))
				{
					OTLog::vOutput(0, "OTPseudonym::VerifyTransactionStatementNumbersOnNym: Issued transaction # %ld from *this not found on THE_NYM.\n", 
								   lTransactionNumber);
					return false;
				}
			}
		}
	} // for
	
	// Getting here means that, though issued numbers may have been removed from my responsibility
	// in a subsequent balance agreement (since the transaction agreement was signed), I know
	// for a fact that no numbers have been ADDED to my list of responsibility.
	// That's the most we can verify here, since we don't know the account number that was
	// used for the last balance agreement.
	
	
	return true;
}





// Each Nym has a public key file, as well as a nym file. Why two separate files?
// Because they are often used for different purposes and are being loaded/saved 
// for their own reasons. The Nymfile contains the user ID, which is a hash of the
// public key, so the it knows how to find the right pubkey file (filename is the
// hash) and it knows how to validate the contents (by hashing them.) The Nymfile
// also contains the transaction numbers that have been issued to that nym, so 
// the server might later load it up in order to verify that a specific transaction
// number is indeed on that list (and then remove it from the list.)
bool OTPseudonym::LoadNymfile(const char * szFilename/*=NULL*/)
{
	OTString strID;
	GetIdentifier(strID);

	const char * szFoldername = OTFolders::Nym().Get();
	const char * szTheFilename = strID.Get();
	
	// If no filename was passed in (user might have designated one) then we create
	// the filename by appending the Nym's ID to the path.
	if (NULL == szFilename)
	{
		m_strNymfile = szTheFilename;
	}
	else 
	{
		m_strNymfile = szFilename;
	}
	// --------------------------------------------------------------------
	if (false == OTDB::Exists(szFoldername, m_strNymfile.Get()))
	{
		OTLog::vError("%s: File does not exist: %s%s%s\n", __FUNCTION__,
					  szFoldername, OTLog::PathSeparator(), m_strNymfile.Get());
		return false;
	}
	// --------------------------------------------------------------------
	//
	std::string strFileContents(OTDB::QueryPlainString(szFoldername, m_strNymfile.Get())); // <=== LOADING FROM DATA STORE.
	
	if (strFileContents.length() < 2)
	{
		OTLog::vError("%s: Error reading file: %s%s%s\n", __FUNCTION__,
					  szFoldername, OTLog::PathSeparator(), m_strNymfile.Get());
		return false;
	}
	// --------------------------------------------------------------------
	OTString strRawFile = strFileContents.c_str();
	
	if (strRawFile.GetLength())
		return LoadFromString(strRawFile);
		
	return false;
}



bool OTPseudonym::Loadx509CertAndPrivateKeyFromString(const OTString   & strInput,
                                                      OTPasswordData   * pPWData/*=NULL*/,
                                                            OTPassword * pImportPassword/*=NULL*/)
{
    OT_ASSERT(NULL != m_pkeypair);
	// --------------------------------------------------------------------
	if (!strInput.Exists())
	{
        const OTString strID(m_nymID);
		OTLog::vError("%s: strInput does not exist. (Returning false.) ID currently set to: %s\n",
                      __FUNCTION__, strID.Get());
		return false;
	}	
	// --------------------------------------------------------------------
    OTString strReason(NULL == pPWData ? OT_PW_DISPLAY : pPWData->GetDisplayString());
    
    return m_pkeypair->LoadCertAndPrivateKeyFromString(strInput, &strReason, pImportPassword);
}

                      
// Todo: if the above function works fine, then call it in the below function (to reduce code bloat.)

bool OTPseudonym::Loadx509CertAndPrivateKey(const bool bChecking/*=false*/,
                                            OTPasswordData * pPWData/*=NULL*/,
                                            OTPassword * pImportPassword/*=NULL*/)
{
    OT_ASSERT(NULL != m_pkeypair);
    // ----------------------------
    OTPasswordData thePWData( OT_PW_DISPLAY );
    if (NULL == pPWData)
        pPWData = &thePWData;
    OTString strReason(pPWData->GetDisplayString());

    // Here we try to load credentials first (the new system) and if it's successful, we
    // use that to set the private/public keypair from the credential, and then return.
    // Otherwise, we run the old code.
    //
    if ( this->LoadCredentials(true, pPWData, pImportPassword) &&
        (this->GetMasterCredentialCount() > 0)) // New style!
    {
//      return true;
        mapOfCredentials::iterator it = m_mapCredentials.begin();
        OT_ASSERT(m_mapCredentials.end() != it);
        OTCredential * pCredential = (*it).second;
        OT_ASSERT(NULL != pCredential);
        // -----------------------------
        OTString strPubAndPrivCert;

        if (const_cast<OTKeypair &>(pCredential->GetSignKeypair(&m_listRevokedIDs)).SaveCertAndPrivateKeyToString(strPubAndPrivCert,
                                                                                                                  &strReason,
                                                                                                                  pImportPassword))
        {            
            const bool bReturnValue = m_pkeypair->LoadCertAndPrivateKeyFromString(strPubAndPrivCert, &strReason, pImportPassword);
            
            if (!bReturnValue)
                OTLog::vError("%s: Failed in call to m_pkeypair->SetPrivateKey.\n", __FUNCTION__);

            return bReturnValue;
        }
        // -----------------------------
    }
    // ---------------------------------
    // OLD STYLE (below) Deprecated.
    
    
	OTString     strID(m_nymID);
	// --------------------------------------------------------------------
	std::string  strFoldername	= OTFolders::Cert().Get();
	std::string  strFilename	= strID.Get();
	// --------------------------------------------------------------------
	if (strFoldername.empty()) { OTLog::vError("%s: Error: strFoldername is empty!",__FUNCTION__); OT_ASSERT(false); return false; }
	if (strFilename.empty())   { OTLog::vError("%s: Error: strFilename is empty!",  __FUNCTION__); OT_ASSERT(false); return false; }
	// --------------------------------------------------------------------
	const bool bExists = OTDB::Exists(strFoldername, strFilename);

	if (!bExists)
	{
		OTLog::vOutput(bChecking ? 1 : 0,"%s: (%s: is %s).  File does not exist: %s in: %s",
			__FUNCTION__, "bChecking", bChecking ? "true" : "false", strFoldername.c_str(), strFilename.c_str());

		return false;
	}
	// --------------------------------------------------------------------
	else if (m_pkeypair->LoadBothKeysFromCertFile(OTFolders::Cert(), // foldername
                                                  strID,             // filename
                                                  &strReason,
                                                  pImportPassword))
		return true; // LoadBothKeysFromCertFile has plenty of logs, no need for more at this time here.
    // ---------------------------------
    OTLog::vError("%s: Failure, filename: %s%s%s\n", __FUNCTION__,
                  strFoldername.c_str(), OTLog::PathSeparator(), strFilename.c_str());
    return false;
}



//static
bool OTPseudonym::DoesCertfileExist(const OTString & strNymID)
{
    OTString strCredListFile;
    strCredListFile.Format("%s.cred", strNymID.Get());
	// --------------------------------------------------------------------
    return OTDB::Exists(OTFolders::Cert()      .Get(), strNymID       .Get()) || // Old-school.
           OTDB::Exists(OTFolders::Credential().Get(), strCredListFile.Get());   // New-school.
	// --------------------------------------------------------------------
}


// on the client side, this means it's a private Nym.
bool OTPseudonym::CertfileExists()
{
	const OTString strID(m_nymID);
    return OTPseudonym::DoesCertfileExist(strID);
}


bool OTPseudonym::HasPublicKey()
{
    OT_ASSERT(NULL != m_pkeypair);
	// --------------------
    return m_pkeypair->HasPublicKey();
}

bool OTPseudonym::HasPrivateKey()
{
    OT_ASSERT(NULL != m_pkeypair);
	// --------------------
    return m_pkeypair->HasPrivateKey();
}

// ----------------------------------------------------------------------------------------

// This version WILL handle the bookends: -----BEGIN CERTIFICATE------ 
// It will also handle the escaped version: - -----BEGIN CERTIFICATE-----
bool OTPseudonym::SetCertificate(const OTString & strCert, bool bEscaped/*=true*/)
{
    OT_ASSERT(NULL != m_pkeypair);
	// --------------------
	return m_pkeypair->LoadPublicKeyFromCertString(strCert, bEscaped);
}

// ----------------------------------------------------------------------------------------

// This version WILL handle the bookends -----BEGIN PUBLIC KEY------ 
// It will also handle the escaped version: - -----BEGIN PUBLIC KEY------
bool OTPseudonym::SetPublicKey(const OTString & strKey, bool bEscaped/*=true*/)
{	
    OT_ASSERT(NULL != m_pkeypair);
	// --------------------
	return m_pkeypair->SetPublicKey(strKey, bEscaped);
}

// ----------------------------------------------------------------------------------------

// This version handles the ascii-armored text WITHOUT the bookends
bool OTPseudonym::SetPublicKey(const OTASCIIArmor & strKey)
{
    OT_ASSERT(NULL != m_pkeypair);
	// --------------------
	return m_pkeypair->SetPublicKey(strKey);
}

// ----------------------------------------------------------------------------------------


// This version WILL handle the bookends -----BEGIN ENCRYPTED PRIVATE KEY------ 
// It will also handle the escaped version: - -----BEGIN ENCRYPTED PRIVATE KEY------
//
bool OTPseudonym::SetPrivateKey(const OTString & strKey, bool bEscaped/*=true*/)
{
    OT_ASSERT(NULL != m_pkeypair);
	// --------------------
	return m_pkeypair->SetPrivateKey(strKey, bEscaped);
}

// ----------------------------------------------------------------------------------------

// This version handles the ascii-armored text WITHOUT the bookends
//
bool OTPseudonym::SetPrivateKey(const OTASCIIArmor & strKey)
{
    OT_ASSERT(NULL != m_pkeypair);
    // --------------------
    return m_pkeypair->SetPrivateKey(strKey);
}

// ----------------------------------------------------------------------------------------

const OTAsymmetricKey & OTPseudonym::GetPrivateAuthKey() const
{
    if (m_mapCredentials.size() > 0)
    {
        FOR_EACH_CONST(mapOfCredentials, m_mapCredentials)
        {
            const OTCredential * pCredential = (*it).second;
            OT_ASSERT(NULL != pCredential);
            // ------------------
            // Todo: If we have some criteria, such as which master or subcredential
            // is currently being employed by the user, we'll use that here to skip
            // through this loop until we find the right one. Until then, I'm just
            // going to return the first one that's valid.
            // ------------------
            return pCredential->GetPrivateAuthKey(&m_listRevokedIDs);
        }
    }
    else
    {
        OTString strNymID;
        this->GetIdentifier(strNymID);
        OTLog::vOutput(1, "%s: This nym (%s) has no credentials from where I can pluck a private AUTHENTICATION key, apparently. Instead, using the private key on the Nym's keypair (a system which is being deprecated in favor of credentials, so it's not good that I'm having to do this here. Why are there no credentials on this Nym?)\n", __FUNCTION__, strNymID.Get());
    }

//  else // Deprecated.
    {
        OT_ASSERT(NULL != m_pkeypair);
        // -------
        return m_pkeypair->GetPrivateKey();
    }
}

// ----------------------------------------------------------------------------------------

const OTAsymmetricKey & OTPseudonym::GetPrivateEncrKey() const
{
    if (m_mapCredentials.size() > 0)
    {
        FOR_EACH_CONST(mapOfCredentials, m_mapCredentials)
        {
            const OTCredential * pCredential = (*it).second;
            OT_ASSERT(NULL != pCredential);
            // ------------------
            // Todo: If we have some criteria, such as which master or subcredential
            // is currently being employed by the user, we'll use that here to skip
            // through this loop until we find the right one. Until then, I'm just
            // going to return the first one that's valid.
            // ------------------
            return pCredential->GetPrivateEncrKey(&m_listRevokedIDs);
        }
    }
    else
    {
        OTString strNymID;
        this->GetIdentifier(strNymID);
        OTLog::vOutput(1, "%s: This nym (%s) has no credentials from where I can pluck a private ENCRYPTION key, apparently. Instead, using the private key on the Nym's keypair (a system which is being deprecated in favor of credentials, so it's not good that I'm having to do this here. Why are there no credentials on this Nym?)\n", __FUNCTION__, strNymID.Get());
    }

//  else // Deprecated.
    {
        OT_ASSERT(NULL != m_pkeypair);
        // -------
        return m_pkeypair->GetPrivateKey();
    }
}

// ----------------------------------------------------------------------------------------

const OTAsymmetricKey & OTPseudonym::GetPrivateSignKey() const
{
    if (m_mapCredentials.size() > 0)
    {
        FOR_EACH_CONST(mapOfCredentials, m_mapCredentials)
        {
            const OTCredential * pCredential = (*it).second;
            OT_ASSERT(NULL != pCredential);
            // ------------------
            // Todo: If we have some criteria, such as which master or subcredential
            // is currently being employed by the user, we'll use that here to skip
            // through this loop until we find the right one. Until then, I'm just
            // going to return the first one that's valid.
            // ------------------
            return pCredential->GetPrivateSignKey(&m_listRevokedIDs);
        }
    }
    else
    {
        OTString strNymID;
        this->GetIdentifier(strNymID);
        OTLog::vOutput(1, "%s: This nym (%s) has no credentials from where I can pluck a private SIGNING key, apparently. Instead, using the private key on the Nym's keypair (a system which is being deprecated in favor of credentials, so it's not good that I'm having to do this here. Why are there no credentials on this Nym?)\n", __FUNCTION__, strNymID.Get());
    }

//  else // Deprecated.
    {
        OT_ASSERT(NULL != m_pkeypair);
        // -------
        return m_pkeypair->GetPrivateKey();
    }
}

// ----------------------------------------------------------------------------------------

const OTAsymmetricKey & OTPseudonym::GetPublicAuthKey() const
{
    if (m_mapCredentials.size() > 0)
    {
        FOR_EACH_CONST(mapOfCredentials, m_mapCredentials)
        {
            const OTCredential * pCredential = (*it).second;
            OT_ASSERT(NULL != pCredential);
            // ------------------
            // Todo: If we have some criteria, such as which master or subcredential
            // is currently being employed by the user, we'll use that here to skip
            // through this loop until we find the right one. Until then, I'm just
            // going to return the first one that's valid.
            // ------------------
            return pCredential->GetPublicAuthKey(&m_listRevokedIDs);
        }
    }
    else
    {
        OTString strNymID;
        this->GetIdentifier(strNymID);
        OTLog::vOutput(1, "%s: This nym (%s) has no credentials from which I can pluck a public AUTHENTICATION key, unfortunately. Instead, using the public key on the Nym's keypair (a system which is being deprecated in favor of credentials, so it's not good that I'm having to do this here. Why are there no credentials on this Nym?)\n", __FUNCTION__, strNymID.Get());
    }
    
//  else // Deprecated.
    {
        OT_ASSERT(NULL != m_pkeypair);
        // -------
        return m_pkeypair->GetPublicKey();
    }
}

// ----------------------------------------------------------------------------------------

const OTAsymmetricKey & OTPseudonym::GetPublicEncrKey() const
{
    if (m_mapCredentials.size() > 0)
    {
        FOR_EACH_CONST(mapOfCredentials, m_mapCredentials)
        {
            const OTCredential * pCredential = (*it).second;
            OT_ASSERT(NULL != pCredential);
            // ------------------
            // Todo: If we have some criteria, such as which master or subcredential
            // is currently being employed by the user, we'll use that here to skip
            // through this loop until we find the right one. Until then, I'm just
            // going to return the first one that's valid.
            // ------------------
            return pCredential->GetPublicEncrKey(&m_listRevokedIDs);
        }
    }
    else
    {
        OTString strNymID;
        this->GetIdentifier(strNymID);
        OTLog::vOutput(1, "%s: This nym (%s) has no credentials from which I can pluck a public ENCRYPTION key, unfortunately. Instead, using the public key on the Nym's keypair (a system which is being deprecated in favor of credentials, so it's not good that I'm having to do this here. Why are there no credentials on this Nym?)\n", __FUNCTION__, strNymID.Get());
    }

//  else // Deprecated.
    {
        OT_ASSERT(NULL != m_pkeypair);
        // -------
        return m_pkeypair->GetPublicKey();
    }
}

// ----------------------------------------------------------------------------------------

const OTAsymmetricKey & OTPseudonym::GetPublicSignKey() const
{
    if (m_mapCredentials.size() > 0)
    {
        FOR_EACH_CONST(mapOfCredentials, m_mapCredentials)
        {
            const OTCredential * pCredential = (*it).second;
            OT_ASSERT(NULL != pCredential);
            // ------------------
            // Todo: If we have some criteria, such as which master or subcredential
            // is currently being employed by the user, we'll use that here to skip
            // through this loop until we find the right one. Until then, I'm just
            // going to return the first one that's valid.
            // ------------------
            return pCredential->GetPublicSignKey(&m_listRevokedIDs);
        }
    }
    else
    {
        OTString strNymID;
        this->GetIdentifier(strNymID);
        OTLog::vOutput(1, "%s: This nym (%s) has no credentials from which I can pluck a public SIGNING key, unfortunately. Instead, using the public key on the Nym's keypair (a system which is being deprecated in favor of credentials, so it's not good that I'm having to do this here. Why are there no credentials on this Nym?)\n", __FUNCTION__, strNymID.Get());
    }
    
//  else // Deprecated.
    {
        OT_ASSERT(NULL != m_pkeypair);
        // -------
        return m_pkeypair->GetPublicKey();
    }
}

// ----------------------------------------------------------------------------------------

// This is being called by:
// OTContract::VerifySignature(const OTPseudonym & theNym, const OTSignature & theSignature, OTPasswordData * pPWData=NULL)
//
// Note: Need to change OTContract::VerifySignature so that it checks all of these keys when verifying.
//
// OT uses the signature's metadata to narrow down its search for the correct public key.
// Return value is the count of public keys found that matched the metadata on the signature.
//
int OTPseudonym::GetPublicKeysBySignature(listOfAsymmetricKeys & listOutput, const OTSignature & theSignature, char cKeyType/*='0'*/) const
{
    OT_ASSERT(NULL != m_pkeypair);
    // -----------------------------------------------
    // Unfortunately, theSignature can only narrow the search down (there may be multiple results.)
    int nCount = 0;
    // -----------------------------------------------
    FOR_EACH_CONST(mapOfCredentials, m_mapCredentials)
    {
        const OTCredential * pCredential = (*it).second;
        OT_ASSERT(NULL != pCredential);
        // -----------------------------
        const int nTempCount = pCredential->GetPublicKeysBySignature(listOutput, theSignature, cKeyType);
        nCount += nTempCount;
    }
    // -----------------------------------------------
    return nCount;
}

// ----------------------------------------------------------------------------------------
// sets internal member based in ID passed in
void OTPseudonym::SetIdentifier(const OTIdentifier & theIdentifier)
{
	m_nymID = theIdentifier;
}
// ----------------------------------------------------------------------------------------

// sets argument based on internal member
void OTPseudonym::GetIdentifier(OTIdentifier & theIdentifier) const
{
	theIdentifier = m_nymID;
}
// ----------------------------------------------------------------------------------------

// sets internal member based in ID passed in
void OTPseudonym::SetIdentifier(const OTString & theIdentifier)
{
	m_nymID.SetString(theIdentifier);
}
// ----------------------------------------------------------------------------------------

// sets argument based on internal member
void OTPseudonym::GetIdentifier(OTString & theIdentifier) const
{	
	m_nymID.GetString(theIdentifier);
}

// ----------------------------------------------------------------------------------------


OTPseudonym::OTPseudonym() : m_bMarkForDeletion(false), m_pkeypair(new OTKeypair), m_lUsageCredits(0)
{
    OT_ASSERT(NULL != m_pkeypair);

	Initialize();
}
// ----------------------------------------------------------------------------------------

void OTPseudonym::Initialize()
{
	m_strVersion = "1.0";
}

OTPseudonym::OTPseudonym(const OTString & name, const OTString & filename, const OTString & nymID)
 : m_bMarkForDeletion(false), m_pkeypair(new OTKeypair), m_lUsageCredits(0)
{
    OT_ASSERT(NULL != m_pkeypair);

	Initialize();
	
	m_strName		= name;
	m_strNymfile	= filename;
	
	m_nymID.SetString(nymID);
}

// -----------------------------------------------


OTPseudonym::OTPseudonym(const OTIdentifier & nymID) : m_bMarkForDeletion(false), m_pkeypair(new OTKeypair), m_lUsageCredits(0)
{
    OT_ASSERT(NULL != m_pkeypair);

	Initialize();
	
	m_nymID = nymID;
}
// -----------------------------------------------

OTPseudonym::OTPseudonym(const OTString & strNymID) : m_bMarkForDeletion(false), m_pkeypair(new OTKeypair), m_lUsageCredits(0)
{
    OT_ASSERT(NULL != m_pkeypair);

	Initialize();
	
	m_nymID.SetString(strNymID);
}
// -----------------------------------------------

void OTPseudonym::ClearCredentials()
{
    m_listRevokedIDs.clear();
    // -----------------------------
    while (!m_mapCredentials.empty())
    {
        OTCredential * pCredential = m_mapCredentials.begin()->second;
		m_mapCredentials.erase(m_mapCredentials.begin());
		delete pCredential;
		pCredential = NULL;
    }
    // -----------------------------
    while (!m_mapRevoked.empty())
    {
        OTCredential * pCredential = m_mapRevoked.begin()->second;
		m_mapRevoked.erase(m_mapRevoked.begin());
		delete pCredential;
		pCredential = NULL;
    }
}

// -----------------------------------------------


void OTPseudonym::ClearAll()
{
    m_mapRequestNum.clear();
    m_mapHighTransNo.clear();
    // ---------------------------
    ReleaseTransactionNumbers();
//  m_mapTransNum.clear();
//  m_mapIssuedNum.clear();
//  m_mapTentativeNum.clear();
//  m_mapAcknowledgedNum.clear();
    // ---------------------------
    m_mapNymboxHash.clear();
    m_mapRecentHash.clear();
    m_mapInboxHash.clear();
    m_mapOutboxHash.clear();
    // ---------------------------
    m_setAccounts.clear();
    m_setOpenCronItems.clear();
    // -----------------------------
	ClearMail();
	ClearOutmail();
	ClearOutpayments();
    // -----------------------------
    // We load the Nym twice... once just to load the credentials up from the .cred file, and a second
    // time to load the rest of the Nym up from the Nymfile. LoadFromString calls ClearAll before loading,
    // so there's no possibility of duplicated data on the Nym. And when that happens, we don't want the
    // credentials to get cleared, since we want them to still be there after the rest of the Nym is
    // loaded. So this is commented out.
//  ClearCredentials();
    // -----------------------------
}


OTPseudonym::~OTPseudonym()
{
    // -----------------------------
	ClearAll();
	ClearCredentials();
    // -----------------------------
    if (NULL != m_pkeypair)
        delete m_pkeypair; // todo: else error
    // -----------------------------
	m_pkeypair	= NULL;
    // -----------------------------
}




















