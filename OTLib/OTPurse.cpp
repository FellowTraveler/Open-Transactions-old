/************************************************************************************
 *    
 *  OTPurse.cpp
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


#include <cstring>

#include <string>

#include "irrxml/irrXML.h"

using namespace irr;
using namespace io;



#include "OTStorage.h"

#include "OTToken.h"
#include "OTPurse.h"
#include "OTPseudonym.h"
#include "OTEnvelope.h"
#include "OTASCIIArmor.h"
#include "OTLog.h"



bool OTPurse::GetNymID(OTIdentifier & theOutput) const
{
    bool bSuccess = false;
    theOutput.Release();
    // --------------------------------------
    if (this->IsNymIDIncluded() && !m_UserID.IsEmpty())
    {
        bSuccess = true;
        theOutput = m_UserID;
    }
    // --------------------------------------
    else if (this->IsUsingATempNym() && (NULL != m_pTempNym))
    {
        bSuccess  = true;
        m_pTempNym->GetIdentifier(theOutput);
    }
    // --------------------------------------
    else if (!m_UserID.IsEmpty())
    {
        bSuccess  = true;
        theOutput = m_UserID;
    }
    // --------------------------------------
    return bSuccess;
}


// ----------------------------------------------------
// INTERNAL NYM: For adding a PASSPHRASE to a PURSE.
//
// What if you DON'T want to encrypt the purse to your Nym??
// What if you just want to use a passphrase instead?
// That's what these functions are for. OT just generates
// a dummy Nym and stores it INSIDE THE PURSE. You set the
// passphrase for the dummy nym, and thereafter your 
// experience is one of a password-protected purse. (But
// in reality, there is a dummy nym inside that purse.)
//
bool OTPurse::GenerateInternalNym(int nBits/*=1024*/)
{
    // -------------------------------------------    
    if (this->IsUsingATempNym() || (NULL != this->GetInternalNym()))
    {
        OTLog::Output(0, "OTPurse::GenerateInternalNym: Failed: internal Nym already exists.\n");
        return false;
    }
    // -------------------------------------------    
    if (!this->IsEmpty())
    {
        OTLog::Output(0, "OTPurse::GenerateInternalNym: Failed: The purse must be EMPTY before you create a new dummy Nym, internal to that purse. (For the purposes of adding a passphrase to the purse, normally.)\n");
        return false;
    }
    // -------------------------------------------
    
    switch (nBits) 
    {
        case 1024: // todo hardcoding.
        case 2048:
        case 4096:
        case 8192:
            break;            
        default:
            OTLog::vError("OTPurse::GenerateInternalNym: Failure: nBits must be one of: "
                          "1024, 2048, 4096, 8192. (%d was passed...)\n", nBits);
            return false;
    }

    // -------------------------------------------
    OTPseudonym * pNym = new OTPseudonym;
	OT_ASSERT_MSG(NULL != pNym, "OTPurse::GenerateInternalNym: Assert: NULL != new OTPseudonym \n");
    // BELOW THIS point, pNym must either be deleted, or saved. (Or it will leak.)
	// --------------------------------------------
    
	if (false == pNym->GenerateNym(nBits, false)) // bCreateFile=true by default, but it's FALSE here.
	{
        OTLog::vOutput(0, "OTPurse::GenerateInternalNym: Failed while calling pNym->GenerateNym(%d, false).\n",
                       nBits);
		delete pNym;
		pNym = NULL;
        
        return false;
	}
    // ---------------------------------------------------
    
    const bool bSetIdentifier = pNym->SetIdentifierByPubkey();
    OT_ASSERT_MSG(bSetIdentifier, "OTPurse::GenerateInternalNym: Assert: pNym->SetIdentifierByPubkey() \n");

    // By this point, the Nym has been successfully generated, and he even has an ID!
    // Let's attach him to the purse so we don't have to keep worrying about a leak.
    //
    m_pTempNym = pNym;
    // ----------------------------
    // Let's make sure the new Nym's ID is also this purse's UserID...
    //
    pNym->GetIdentifier(m_UserID);
    
    m_bUsingTempNym    = true;
    m_bIsNymIDIncluded = true;
    
	return true;
}




// Take all the tokens from a purse and add them to this purse.
// Don't allow duplicates.
//
bool OTPurse::Merge(OTPseudonym & theOldNym, OTPseudonym & theNewNym, OTPurse & theNewPurse)
{
	mapOfTokenPointers theMap;
	
	while (this->Count() > 0) 
	{
		OTToken * pToken = this->Pop(theOldNym);
		OT_ASSERT_MSG(NULL != pToken, "OTPurse::Merge: Assert: NULL != this->Pop(theOldNym) \n");
				
		const OTASCIIArmor & ascTokenID = pToken->GetSpendable();
		
		// I just popped a Token off of *this. Let's see if it's in my temporary map...
		// If it's already there, then just delete it (duplicate).
		//
		FOR_EACH(mapOfTokenPointers, theMap)
		{
			OTToken * pTempToken = (*it).second;
			OT_ASSERT(NULL != pTempToken);
			
			const OTASCIIArmor & ascTempTokenID = pTempToken->GetSpendable();
			
			// --------------------------------
			// It's already there. Delete the one that's already there.
			// (That way we can add it after, whether it was there originally or not.)
			if (ascTempTokenID == ascTokenID)
			{
				theMap.erase(it);
				delete pTempToken;
                pTempToken = NULL;
				//break; // In case there are multiple duplicates, not just one.
			}
		}
		
		// Now we know there aren't any duplicates on the temporary map, let's add the token to it.
		std::string theKey = ascTokenID.Get();		
		theMap.insert(std::pair<std::string, OTToken*>(theKey, pToken));
	}
	// At this point, all of the tokens on *this have been popped, and added
	// to the temporary map as token pointers, with any duplicates removed.
	// -----------------------------------------------------------
	// Basically now I just want to do the exact same thing with the other purse...
	//
	while (theNewPurse.Count() > 0) 
	{
		OTToken * pToken = theNewPurse.Pop(theNewNym); 
		OT_ASSERT_MSG(NULL != pToken, "OTPurse::Merge: Assert: NULL != theNewPurse.Pop(theNewNym) \n");
		
		const OTASCIIArmor & ascTokenID = pToken->GetSpendable();
		
		// I just popped a Token off of theNewPurse. Let's see if it's in my temporary map...
		// If it's already there, then just delete it (duplicate).
		FOR_EACH(mapOfTokenPointers, theMap)
		{
			OTToken * pTempToken = (*it).second;
			OT_ASSERT(NULL != pTempToken);
			
			const OTASCIIArmor & ascTempTokenID = pTempToken->GetSpendable();
			
			// --------------------------------
			// It's already there. Delete the one that's already there.
			// (That way we can add it after, whether it was there originally or not.)
			if (ascTempTokenID == ascTokenID)
			{
				theMap.erase(it);
				delete pTempToken;
                pTempToken = NULL;
				//break; // In case there are multiple duplicates, not just one.
			}
		}
		
		// Now we KNOW there aren't any duplicates on the temporary map, so let's
        // add the token to it...
        //
		std::string theKey = ascTokenID.Get();		
		theMap.insert(std::pair<std::string, OTToken*>(theKey, pToken));
        // --------------------------------------------------------------
        //
        // SINCE THE new purse is being MERGED into the old purse, we don't have to re-assign ownership
        // of any of the old tokens. But we DO need to re-assign ownership of the NEW tokens that are being
        // merged in. We reassign them from New ==> TO OLD. (And we only bother if they aren't the same Nym.)
        //
        if (false == theNewNym.CompareID(theOldNym)) // Not the same Nym!!
        {
            if (false == pToken->ReassignOwnership(theNewNym, theOldNym))
            {
                OTLog::Error("OTPurse::Merge: Error: Failed while attempting to re-assign ownership of token during purse merge.\n");
            }
            else 
            {
                OTLog::Output(1, "OTPurse::Merge: FYI: Success re-assigning ownership of token during purse merge.\n");
                
                pToken->ReleaseSignatures();
                pToken->SignContract(theOldNym);
                pToken->SaveContract();
            }
        }
	}
	// -----------------------------------------------------------
	
	// At this point, all of the tokens on *this (old purse) AND theNewPurse have been popped, and added
	// to the temporary map as token pointers, with any duplicates removed.
    // Also, the tokens on the New Purse have been reassigned (from theNewNym as owner, to theOldNym as
    // owner) and each has been signed and saved properly, using the old Nym.

	// -----------------------------------------------------------
	// Next, we loop through theMap, and Push ALL of those tokens back onto *this. (The old purse.)
	
    bool bSuccess = true;
    
	FOR_EACH(mapOfTokenPointers, theMap)
	{
		OTToken * pToken = (*it).second;
		OT_ASSERT(NULL != pToken);
        // ----------------------------------
		bool bPush = this->Push(theOldNym, *pToken); // The purse makes it's own copy of the token, into string form.
		
		if (!bPush)
        {
			OTLog::Error("OTPurse::Merge: Error: Failure pushing token into purse.\n");
            bSuccess = false;
        }
        // Notice we don't break here if 1 token fails -- we loop through them all.
        // Maybe shouldn't? Seems right somehow.
	}
	// -----------------------------------------------------
	// Next I clean up all the tokens out of the temporary map, since they will leak otherwise.
	//
	while (!theMap.empty())
	{		
		OTToken * pToken = theMap.begin()->second;
		OT_ASSERT(NULL != pToken);
		// ---------------------------
		delete pToken; pToken = NULL;
		// ---------------------------
		theMap.erase(theMap.begin());
	}
	// -----------------------------------------------------
	
    // Note: Caller needs to re-sign and re-save this purse, since we aren't doing it
    // internally here.
    
	return bSuccess;
}



OTPurse::OTPurse(const OTPurse & thePurse) : OTContract(),
	m_ServerID(thePurse.GetServerID()),
	m_AssetID(thePurse.GetAssetID()),
	m_lTotalValue(0),
    m_bUsingTempNym(false),
    m_bIsNymIDIncluded(false),
    m_pTempNym(NULL)
{
	InitPurse();
}


// Don't use this unless you really don't have the asset type handy.
// Perhaps you know you're about to read this purse from a string and you
// know the asset type is in there anyway. So you use this constructor.
OTPurse::OTPurse(const OTIdentifier & SERVER_ID) : OTContract(),
	m_ServerID(SERVER_ID),
    m_lTotalValue(0),
    m_bUsingTempNym(false),
    m_bIsNymIDIncluded(false),
    m_pTempNym(NULL)
{
	InitPurse();
}

OTPurse::OTPurse(const OTIdentifier & SERVER_ID, const OTIdentifier & ASSET_ID) : OTContract(),
	m_ServerID(SERVER_ID),
	m_AssetID(ASSET_ID),
    m_lTotalValue(0),
    m_bUsingTempNym(false),
    m_bIsNymIDIncluded(false),
    m_pTempNym(NULL)
{
	InitPurse();
}



OTPurse::OTPurse(const OTIdentifier & SERVER_ID, 
				 const OTIdentifier & ASSET_ID, 
				 const OTIdentifier & USER_ID) : OTContract(),
	m_UserID(USER_ID),
	m_ServerID(SERVER_ID),
	m_AssetID(ASSET_ID),
    m_lTotalValue(0),
    m_bUsingTempNym(false),
    m_bIsNymIDIncluded(false),
    m_pTempNym(NULL)
{
	InitPurse();
}

OTPurse::~OTPurse()
{
//	Release();
	// OTContract::~OTContract is called here automatically, and it calls Release() already.
	// So I don't need to call Release() here again, since it's already called by the parent.

}

void OTPurse::InitPurse()
{
	m_strContractType.Set("PURSE");
	
	m_lTotalValue = 0;
    
    m_bUsingTempNym     = false;
    m_bIsNymIDIncluded  = false;
}


void OTPurse::Release()
{
	// This sets m_lTotalValue to 0 already.
	ReleaseTokens();
//	m_lTotalValue = 0;
    // -----------------------
	
    m_bUsingTempNym     = false;
    m_bIsNymIDIncluded  = false;
    // -----------------------
    // the Temp Nym is when a purse contains its own Nym, created just
    // for that purse, so that it can be password protected instead of using
    // one of the real Nyms in your wallet.
    //
    if (NULL != m_pTempNym)
    {
        delete m_pTempNym;
        m_pTempNym = NULL;
    }    
    // -----------------------
	OTContract::Release();
}

/*	
 OTIdentifier	m_UserID;	// Optional
 OTIdentifier	m_ServerID;	// Mandatory
 OTIdentifier	m_AssetID;	// Mandatory
 */

bool OTPurse::LoadContract()
{
	return LoadPurse();
}


bool OTPurse::LoadPurse(const char * szServerID/*=NULL*/, const char * szUserID/*=NULL*/, const char * szAssetTypeID/*=NULL*/)
{
	if (!m_strFoldername.Exists())
		m_strFoldername.Set(OTLog::PurseFolder());
	// -----------------------------------------
	OTString strServerID(m_ServerID), strUserID(m_UserID), strAssetTypeID(m_AssetID);
	
	if (NULL != szServerID)
		strServerID = szServerID;
	if (NULL != szUserID)
		strUserID = szUserID;
	if (NULL != szAssetTypeID)
		strAssetTypeID = szAssetTypeID;
	// -------------------------------
	if (!m_strFilename.Exists())
	{
		m_strFilename.Format("%s%s%s%s%s", strServerID.Get(), OTLog::PathSeparator(), 
							 strUserID.Get(), OTLog::PathSeparator(), strAssetTypeID.Get());
	}
	
	const char * szFolder1name	= OTLog::PurseFolder();     // purse 
	const char * szFolder2name	= strServerID.Get();        // purse/SERVER_ID
	const char * szFolder3name	= strUserID.Get();          // purse/SERVER_ID/USER_ID
	const char * szFilename		= strAssetTypeID.Get();     // purse/SERVER_ID/USER_ID/ASSET_TYPE_ID
	
	// --------------------------------------------------------------------
	
	if (false == OTDB::Exists(szFolder1name, szFolder2name, szFolder3name, szFilename))
	{
		OTLog::vError("OTPurse::LoadPurse: File does not exist: %s%s%s%s%s%s%s\n", 
					  szFolder1name, OTLog::PathSeparator(), szFolder2name, OTLog::PathSeparator(), 
					  szFolder3name, OTLog::PathSeparator(), szFilename);
		return false;
	}
	
	// --------------------------------------------------------------------
	//
	std::string strFileContents(OTDB::QueryPlainString(szFolder1name, szFolder2name, szFolder3name, szFilename)); // <=== LOADING FROM DATA STORE.
	
	if (strFileContents.length() < 2)
	{
		OTLog::vError("OTPurse::LoadPurse: Error reading file: %s%s%s%s%s%s%s\n", 
					  szFolder1name, OTLog::PathSeparator(), szFolder2name, OTLog::PathSeparator(), 
					  szFolder3name, OTLog::PathSeparator(), szFilename);
		return false;
	}
	// --------------------------------------------------------------------
	
    // NOTE: No need here to deal with OT ARMORED file format, since LoadContractFromString
    // already handles it internally.
    
	OTString strRawFile(strFileContents.c_str());
	
	return LoadContractFromString(strRawFile);
}



bool OTPurse::SavePurse(const char * szServerID/*=NULL*/, const char * szUserID/*=NULL*/, const char * szAssetTypeID/*=NULL*/)
{
	if (!m_strFoldername.Exists())
		m_strFoldername.Set(OTLog::PurseFolder());
	// -----------------------------------------
	OTString strServerID(m_ServerID), strUserID(m_UserID), strAssetTypeID(m_AssetID);
	
	if (NULL != szServerID)
		strServerID = szServerID;
	if (NULL != szUserID)
		strUserID = szUserID;
	if (NULL != szAssetTypeID)
		strAssetTypeID = szAssetTypeID;
	// -------------------------------
	if (!m_strFilename.Exists())
	{
		m_strFilename.Format("%s%s%s%s%s", strServerID.Get(), OTLog::PathSeparator(), 
							 strUserID.Get(), OTLog::PathSeparator(), strAssetTypeID.Get());
	}
	// --------------------------------------------------------------------
	
	const char * szFolder1name	= OTLog::PurseFolder();     // purse 
	const char * szFolder2name	= strServerID.Get();        // purse/SERVER_ID
	const char * szFolder3name	= strUserID.Get();          // purse/SERVER_ID/USER_ID
	const char * szFilename		= strAssetTypeID.Get();     // purse/SERVER_ID/USER_ID/ASSET_TYPE_ID
    	
	// --------------------------------------------------------------------
	
	OTString strRawFile;
	
	if (!SaveContractRaw(strRawFile))
	{
		OTLog::vError("OTPurse::SavePurse: Error saving Pursefile (to string):\n%s%s%s%s%s%s%s\n", 
                      szFolder1name,
					  OTLog::PathSeparator(), szFolder2name, OTLog::PathSeparator(), 
					  szFolder3name, OTLog::PathSeparator(), szFilename);
		return false;
	}
	// --------------------------------------------------------------------
	//
	OTString strFinal;
    OTASCIIArmor ascTemp(strRawFile);
    
    if (false == ascTemp.WriteArmoredString(strFinal, m_strContractType.Get()))
    {
		OTLog::vError("OTPurse::SavePurse: Error saving Pursefile (failed writing armored string):\n%s%s%s%s%s%s%s\n", 
                      szFolder1name,
					  OTLog::PathSeparator(), szFolder2name, OTLog::PathSeparator(), 
					  szFolder3name, OTLog::PathSeparator(), szFilename);
		return false;
    }
    // --------------------------------------------------------------------
	bool bSaved = OTDB::StorePlainString(strFinal.Get(), szFolder1name, szFolder2name,  
										 szFolder3name, szFilename); // <=== SAVING TO DATA STORE.
	if (!bSaved)
	{
		OTLog::vError("OTPurse::SavePurse: Error writing to file: %s%s%s%s%s%s%s\n", szFolder1name,
					  OTLog::PathSeparator(), szFolder2name, OTLog::PathSeparator(), 
					  szFolder3name, OTLog::PathSeparator(), szFilename);
		return false;
	}
	// --------------------------------------------------------------------
	
	return true;
}


void OTPurse::UpdateContents() // Before transmission or serialization, this is where the Purse saves its contents 
{
	const OTString SERVER_ID(m_ServerID), USER_ID(m_UserID), ASSET_TYPE_ID(m_AssetID);
	
	// I release this because I'm about to repopulate it.
	m_xmlUnsigned.Release();
	
	m_xmlUnsigned.Concatenate("<?xml version=\"%s\"?>\n\n", "1.0");		
	
	m_xmlUnsigned.Concatenate("<purse version=\"%s\"\n"
							  " totalValue=\"%ld\"\n" // Total value of all the tokens within.
                              // --------------
							  " isUsingTempNym=\"%s\"\n"
							  " isNymIDIncluded=\"%s\"\n"
                              // --------------
							  " userID=\"%s\"\n" // UserID is optional.
							  " assetTypeID=\"%s\"\n"
                              " serverID=\"%s\">\n\n",
                              // --------------
							  m_strVersion.Get(), 
							  m_lTotalValue,
                              // --------------
                              m_bUsingTempNym    ? "true" : "false",
                              m_bIsNymIDIncluded ? "true" : "false",
                              // --------------
                              // USER_ID / NYM_ID of purse owner.
                              // IF a real NymID (from the user's wallet) is listed in the purse (which is
                              // optional--user's choice) OR whether using a Temp Nym, either way, we
                              // attach that NymID here...
							  ((m_bIsNymIDIncluded || m_bUsingTempNym) 
                               &&
                               !m_UserID.IsEmpty() // (Provided that the ID even exists, of course.)
                              )  ?  // =====>
                                USER_ID.Get() : "", // Then print the ID (otherwise print an empty string.)
							  (!m_AssetID.IsEmpty())  ? ASSET_TYPE_ID.Get() : "", // (Should never actually be empty.)
							  (!m_ServerID.IsEmpty()) ? SERVER_ID.Get()     : ""  // (Should never actually be empty.)
                              );
	// ----------------------------------------------
    //
    // Save the TEMP NYM here (if there IS one.)
    // (Some Purses own their own temp Nym internally, in order to "password protect" the purse.)
    //
    if (m_bUsingTempNym)
    {
        if (NULL == m_pTempNym)
            OTLog::Error("OTPurse::UpdateContents: Error: m_pTempNym is unexpectedly NULL, even though m_bUsingTempNym is true!\n");
        else // m_pTempNym is a good pointer. (Or at least, not-null.)
        {
            const OTString strTempNym(*m_pTempNym);
            
            if (!strTempNym.Exists())
                OTLog::Error("OTPurse::UpdateContents: Error: m_pTempNym was 'good', yet unexpectedly serialized as an empty string.\n");
            else
            {
                const OTASCIIArmor ascTempNym(strTempNym);
                
                if (!ascTempNym.Exists())
                    OTLog::Error("OTPurse::UpdateContents: Error: strTempNym was 'good', yet unexpectedly packed as an empty OTASCIIArmor.\n");
                else
                {
                    // ascTempNym is good by this point.
                    // Therefore, let's grab the keys, and serialize the lot...
                    //
                    OTString strPublicKey, strPrivateKey;
                    // -------------------------------------------
                    const OTAsymmetricKey & publicKey   = m_pTempNym->GetPublicKey();
                    const OTAsymmetricKey & privateKey  = m_pTempNym->GetPrivateKey();
                    // -------------------------------------------
                    bool bPublicKey  = publicKey. GetPublicKey (strPublicKey);
                    bool bPrivateKey = privateKey.GetPrivateKey(strPrivateKey);
                    // -------------------------------------------
                    if (!bPublicKey       || !strPublicKey.Exists())
                        OTLog::Error("OTPurse::UpdateContents: Error: failed reading public key from temp Nym (Nym owned by purse.)\n");
                    else if (!bPrivateKey || !strPrivateKey.Exists())
                        OTLog::Error("OTPurse::UpdateContents: Error: failed reading private key from temp Nym (Nym owned by purse.)\n");
                    else
                    {
                        // By this point, ascTempNym contains the Nym itself, strPublicKey contains the pubkey
                        // and strPrivateKey contains the private key. (Properly formatted, of course.)
                        //
                        m_xmlUnsigned.Concatenate("%s\n\n", "<internalNym>"); // The temp nym, owned by the purse.

                        m_xmlUnsigned.Concatenate("<nymfile>\n%s</nymfile>\n\n",        ascTempNym.Get());    // The "nymfile" itself.
                        m_xmlUnsigned.Concatenate("<publicKey>\n%s</publicKey>\n\n",    strPublicKey.Get());  // The nym's public key.
                        m_xmlUnsigned.Concatenate("<privateKey>\n%s</privateKey>\n\n",  strPrivateKey.Get()); // The nym's private key.

                        m_xmlUnsigned.Concatenate("%s\n\n", "</internalNym>"); // The temp nym, owned by the purse.
                    }
                }
            }
        }
    }
    // ---------------------------------------
	for (int i = 0; i < Count(); i++)
	{
		m_xmlUnsigned.Concatenate("<token>\n%s</token>\n\n", m_dequeTokens[i]->Get());
	}
	// ----------------------------------------------
	m_xmlUnsigned.Concatenate("</purse>\n");
}

    
    
// ----------------------------------------------



int OTPurse::ProcessXMLNode(irr::io::IrrXMLReader*& xml)
{
    const OTString strNodeName(xml->getNodeName());
        
	if (strNodeName.Compare("purse"))
	{	
		m_strVersion = xml->getAttributeValue("version");
        // ---------------------------------
		const OTString strTotalValue	= xml->getAttributeValue("totalValue");
		if (strTotalValue.Exists() && (atol(strTotalValue.Get()) > 0))
			m_lTotalValue = atol(strTotalValue.Get());
        else
            m_lTotalValue = 0;
        // ---------------------------------
        const OTString strUsingTempNym  = xml->getAttributeValue("isUsingTempNym");        
        if (strUsingTempNym.Compare("true"))
            m_bUsingTempNym = true;
        else
            m_bUsingTempNym = false;
        // ---------------------------------
        const OTString strNymIDIncluded = xml->getAttributeValue("isNymIDIncluded");
        if (strNymIDIncluded.Compare("true"))
            m_bIsNymIDIncluded = true;
        else
            m_bIsNymIDIncluded = false;
        // ---------------------------------
		const OTString strServerID		= xml->getAttributeValue("serverID");
        if (strServerID.Exists())
            m_ServerID.SetString(strServerID);
        else
        {
            m_ServerID.Release();
            OTLog::Error("OTPurse::ProcessXMLNode: Failed loading serverID, when one was expected.\n");
            return (-1);
        }
        // ---------------------------------
		const OTString strAssetTypeID   = xml->getAttributeValue("assetTypeID");
        if (strAssetTypeID.Exists())
            m_AssetID.SetString(strAssetTypeID);
        else
        {
            m_AssetID.Release();
            OTLog::Error("OTPurse::ProcessXMLNode: Failed loading assetTypeID, when one was expected.\n");
            return (-1);
        }
        // ---------------------------------
        const OTString strUserID    = xml->getAttributeValue("userID"); // (May not exist.)
        if (m_bUsingTempNym || m_bIsNymIDIncluded)
        {
            if (strUserID.Exists())
                m_UserID.SetString(strUserID);
            else
            {
                OTLog::Error("OTPurse::ProcessXMLNode: Failed loading userID, when one was expected.\n");
                m_UserID.Release();
                return (-1);
            }
        }
        else // UserID SUPPOSED to be blank here. (Thus the Release.) Maybe later, we might consider trying to read it,
             // in order to validate this.
            m_UserID.Release(); // For now, just assume it's not there to be read, and Release my own value to match it.
        // ---------------------------------		
			
		OTLog::vOutput(4, "Loaded purse...\n ServerID: %s\n UserID: %s\n Asset ID: %s\n----------\n",
                       strServerID.Get(),
                       (m_bUsingTempNym || m_bIsNymIDIncluded) ? strUserID.Get() : "",
                       strAssetTypeID.Get());

		return 1;
	}
    // ----------------------------------------------

    // Sometimes you want the purse to have a passphrase on it, without being attached to
    // one of your actual Nyms in your wallet. To accommodate this, OT creates a dummy Nym
    // and stashes it INSIDE the purse! This Dummy Nym can have whatever passphrase you want.
    //
	else if (strNodeName.Compare("internalNym")) 
	{
        if (!m_bUsingTempNym) // If we're NOT using the temp nym, then why am I in the middle of loading one here?
        {
            OTLog::Error("OTPurse::ProcessXMLNode: Error: Unexpected 'internalNym' data, since m_bUsingTempNym is set to false!\n");
            return (-1); // error condition
        }
        // ----------------------------------------------------
        if (m_UserID.IsEmpty()) // If the UserID was empty, then why am I in the middle of loading an internal Nym? Wasn't it saved with an ID?
        {
            OTLog::Error("OTPurse::ProcessXMLNode: Error: Unexpected 'internalNym' data, since m_UserID is blank! "
                         "(The UserID should have loaded before THIS node ever popped up...)\n");
            return (-1); // error condition
        }
        // ----------------------------------------------------
        const char	*	pElementExpected1	= "nymfile";
        OTString		strNymfile; // The actual Nymfile is here.
        
        if (false == OTContract::LoadEncodedTextFieldByName(xml, strNymfile, pElementExpected1))
        {
            OTLog::vError("OTPurse::ProcessXMLNode: Error: Expected %s element with text field.\n", 
                          pElementExpected1);
            return (-1); // error condition
        }
        // ----------------------------------------------------
        const char	*	pElementExpected2	= "publicKey";
        OTString		strPublicKey; // The public key is here.
        
        if (false == OTContract::LoadEncodedTextFieldByName(xml, strPublicKey, pElementExpected2))
        {
            OTLog::vError("OTPurse::ProcessXMLNode: Error: Expected %s element with text field.\n", 
                          pElementExpected2);
            return (-1); // error condition
        }
        // ----------------------------------------------------
        const char	*	pElementExpected3	= "privateKey";
        OTString		strPrivateKey; // The private key is here.
        
        if (false == OTContract::LoadEncodedTextFieldByName(xml, strPrivateKey, pElementExpected3))
        {
            OTLog::vError("OTPurse::ProcessXMLNode: Error: Expected %s element with text field.\n", 
                          pElementExpected3);
            return (-1); // error condition
        }
        // ---------------------------------------------------- 
        //
        // Let's see if the internal nym is already loaded somehow...
        //
        if (NULL != m_pTempNym)
        {
            OTLog::Error("OTPurse::ProcessXMLNode: WARNING: While loading internal Nym for a purse, "
                         "noticed the pointer was ALREADY set!\n");
//          return (-1); // error condition
            
            delete m_pTempNym;
            m_pTempNym = NULL;
        }
        // ----------------------------------------------------
        //
		// By this point, I've loaded up the strings for the Nymfile AND the public key AND the private key.
        // I also know that m_bUsingTempNym is set to true, and I know that m_pTempNym is NULL.
        //
        // (It's only now that I bother instantiating.)
        //
        OTPseudonym * pNym = new OTPseudonym(m_UserID); // m_UserID is validated near the top of this function.
        OT_ASSERT_MSG(NULL != pNym, "OTPurse::ProcessXMLNode: Assert: NULL != new OTPseudonym(m_UserID) \n");
        // -----------------
        // NOTE: In the event of any error, need to delete pNym before returning.
        // (Or it will leak.)
        //
        if (false == pNym->SetPublicKey(strPublicKey, true)) //bool bEscaped=false by default.
        {
            OTLog::vError("OTPurse::ProcessXMLNode: Failed trying to set strPublicKey (from string) as "
                          "the actual public key for this purse's internal Nym. Key contents:\n\n%s\n\n",
                          strPublicKey.Get());
            delete pNym; pNym = NULL;
            return (-1);
        }
        // ----------------------------------------------------
        // Make sure the NymID according to the public key's hash is the same
        // as the m_UserID that we already loaded...
        //
        pNym->SetIdentifierByPubkey();
        OTLog::Output(1, "OTPurse::ProcessXMLNode: FYI, successfully Loaded a public key for purse's internal Nym.\n");
        
        if (false == pNym->CompareID(m_UserID))
        {
            OTLog::Error("OTPurse::ProcessXMLNode: Error: Loaded UserID for purse's internal Nym, then loaded public "
                         "key for same Nym -- but strangely, they don't match.\n");
            delete pNym; pNym = NULL;
            return (-1);
        }
        // ----------------------------------------------------
        // By this point, I know the Nym's ID, as based on the Nym's public key, is valid.
        // I also know that the public key has been successfully set.
        // Therefore, let's set the private key, load the Nymfile from string, and verify...
        //
        if (false == pNym->SetPrivateKey(strPrivateKey, true)) //bool bEscaped=false by default.
        {
            OTLog::vError("OTPurse::ProcessXMLNode: FAILED trying to set strPrivateKey (from string) as "
                          "the actual private key for this purse's internal Nym. Key contents:\n\n%s\n\n",
                          strPrivateKey.Get());
            // (So if you don't know the password, the rest of the purse / nym can still load up.)
//          delete pNym; pNym = NULL;
//          return (-1);
        }
        // ----------------------------------------------------
        // Okay, looks like the private key worked as well...
        // And the CompareID() is basically just as good as a VerifyPseudonym(), meaning that's basically
        // done already... So, let's load up the Nymfile!
        // 
        const bool bLoadedNym = pNym->LoadFromString(strNymfile); // "nymfile" element text contents are in strNymfile

        if (!bLoadedNym)
        {
            OTLog::vError("OTPurse::ProcessXMLNode: Failed trying to load a purse's internal Nymfile "
                          "(Used for adding a passphrase to a purse.) Internal nymfile contents:\n\n%s\n\n",
                          strNymfile.Get());
            delete pNym; pNym = NULL;
            return (-1);            
        }
        // -----------------
        // By this point, the nymfile has loaded successfully, and the public/private keys have
        // also been loaded and set onto the Nym, and the ID has also been verified.
        //
        const OTString strUserID(m_UserID);
        OTLog::vOutput(1, "OTPurse::ProcessXMLNode: Successfully loaded a purse's internal Nym and keys, "
                       "with UserID: %s\n", strUserID.Get());
        
        // -----------------
        // No more worry about pNym cleanup, now that this pointer is set.
        //
        m_pTempNym = pNym; // <==========
        
        // -----------------
        
		return 1;
	}
	// ----------------------------------------------
    
	else if (strNodeName.Compare("token")) 
	{		
		OTASCIIArmor * pArmor = new OTASCIIArmor;
		OT_ASSERT(NULL != pArmor);
		
		if (!OTContract::LoadEncodedTextField(xml, *pArmor) || !pArmor->Exists())
		{
			OTLog::Error("Error in OTPurse::ProcessXMLNode: token field without value.\n");
			
			delete pArmor;
			pArmor = NULL;
			
			return (-1); // error condition
		}
		else 
		{			
			m_dequeTokens.push_front(pArmor);
		}
		
		return 1;
	}
	// ----------------------------------------------

	return 0;
}



bool OTPurse::SaveContractWallet(std::ofstream & ofs)	
{
	return true;
}


// Hypocritically (compared to Push) in the case of Pop(), we DO
// allocate a OTToken and return the pointer. The caller IS
// responsible to delete it when he's done with it.
// 
// The apparent discrepancy is due to the fact that internally,
// we aren't storing the token object but an encrypted string of it.
// But this is hidden from the user of the purse, who perceives only
// that he is passing tokens in and getting them back out again.
OTToken * OTPurse::Pop(const OTPseudonym & theOwner)
{
	if (m_dequeTokens.empty())
		return NULL;
	
	// Grab a copy of the pointer and remove it from the deque
	OTASCIIArmor * pArmor =  m_dequeTokens.front();
	m_dequeTokens.pop_front();
	
//	OTLog::vError("$$$$$$$$$$$$$$ ARMORED TEXT in PURSE POP:\n--------->%s<-----------\n", pArmor->Get());
	
	// Copy the token contents into an Envelope, and delete the pointer.
	OTEnvelope theEnvelope(*pArmor);
	delete pArmor;
	pArmor = NULL;	

	// Open the envelope into a string.
	OTString strToken;
	theEnvelope.Open(theOwner, strToken);
	
//	OTLog::vError("$$$$$$$$$$$$$$$ OPENED ENVELOPE TEXT in PURSE POP:\n--------->%s<-----------\n", strToken.Get());

	// Create a new token with the same server and asset IDs as this purse.
	OTToken * pToken =  new OTToken(*this);
	
	OT_ASSERT(NULL != pToken);
	
	// Load the token from the string we got out of the envelope.
	pToken->LoadContractFromString(strToken);
	
	if (pToken->GetAssetID() != m_AssetID ||
		pToken->GetServerID() != m_ServerID)
	{
		delete pToken;
		pToken = NULL;
		
		OTLog::Error("ERROR: Token with wrong asset type in OTPurse::Pop\n");
	}
	else 
	{
		// We keep track of the purse's total value.
		m_lTotalValue -= pToken->GetDenomination();
	}

	// CALLER is responsible to delete this token.
	return pToken;
}


// Use a local variable for theToken, do NOT allocate it on the heap 
// unless you are going to delete it yourself.
// Repeat: OTPurse is NOT responsible to delete it. We create our OWN internal
// variable here, new that, and add it to the stack. We do not add the one passed in.
bool OTPurse::Push(const OTPseudonym & theOwner, const OTToken & theToken)
{
	if (theToken.GetAssetID() == m_AssetID)
	{
		OTString strToken(theToken);
		
//		OTLog::vError("$$$$$$$$$$$$$$$  PUSHING token to Purse:\n---------->%s<-------------\n", strToken.Get());
		
		OTEnvelope theEnvelope;
		theEnvelope.Seal(theOwner, strToken);
		
		OTASCIIArmor * pArmor = new OTASCIIArmor(theEnvelope);
//		OTLog::vError("$$$$$$$$$$$$$$$  PUSHING token to Purse in armored form:\n---------->%s<-------------\n", 
//				pArmor->Get());

		m_dequeTokens.push_front(pArmor);
		
		// We keep track of the purse's total value.
		m_lTotalValue += theToken.GetDenomination();
		
		return true;
	}
	else {
		OTString strPurseAssetType(m_AssetID), strTokenAssetType(theToken.GetAssetID());
		OTLog::vError("ERROR: Tried to push token with wrong asset type in OTPurse::Push\nPurse Asset Type:\n%s\n"
				"Token Asset Type:\n%s\n", strPurseAssetType.Get(), strTokenAssetType.Get());
		
		return false;
	}
}

int OTPurse::Count() const
{
	return m_dequeTokens.size();
}

bool OTPurse::IsEmpty() const
{
	return m_dequeTokens.empty();
}

void OTPurse::ReleaseTokens()
{
	OTASCIIArmor * pArmor = NULL;
	
	while (!m_dequeTokens.empty()) {
		pArmor = m_dequeTokens.front();
		m_dequeTokens.pop_front();
		delete pArmor;
	}
	
	m_lTotalValue = 0;
}

