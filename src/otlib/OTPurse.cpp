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
    if (this->IsPasswordProtected())
    {
        bSuccess = false; // optimizer will remove automatically anyway, I assume. Might as well have it here for clarity.
    }
    // --------------------------------------
    else if (this->IsNymIDIncluded() && !m_UserID.IsEmpty())
    {
        bSuccess = true;
        theOutput = m_UserID;
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


// Retrieves the passphrase for this purse (which is cached by its master key.)
// Prompts the user to enter his actual passphrase, if necessary to unlock it.
// (May not need unlocking yet -- there is a timeout.)
//
bool OTPurse::GetPassphrase(OTPassword & theOutput, const char * szDisplay/*=NULL*/)
{
    const char * szFunc = "OTPurse::GetPassphrase";
    // -------------------------------------------
    if (!this->IsPasswordProtected())
    {
        OTLog::vOutput(0, "%s: Failed: this purse isn't even password-protected.\n", szFunc);
        return false;
    }
    // -------------------------------------------
    OTMasterKey * pMasterKey = this->GetInternalMaster();
    OT_ASSERT(NULL != pMasterKey);
    // -------------------------------------------
    const OTString strReason((NULL == szDisplay) ? szFunc : szDisplay);
    // -------------------------------------------
    const bool bGotMasterPassword = pMasterKey->GetMasterPassword(theOutput, strReason.Get()); //bVerifyTwice=false
    return bGotMasterPassword;
}


// Don't ever deal with m_pMasterKey directly (except before it's been created / loaded.)
// When you actually USE m_pMasterKey, you want to use this function instead.
// (It will save the user from having the type the password, for example, 50 times in 1 minute,
// by using the cached one.)
//
OTMasterKey * OTPurse::GetInternalMaster()  // stores the passphrase for the symmetric key.
{
    const char * szFunc = "OTPurse::GetInternalMaster";
    // -------------------------------------------
    if (!this->IsPasswordProtected() || (NULL == m_pMasterKey)) // this second half of the logic should never happen.
    {
        OTLog::vOutput(0, "%s: Failed: no internal master key exists, in this purse.\n", szFunc);
        return NULL;
    }
    // -------------------------------------------
    if (!m_pMasterKey->IsGenerated()) // should never happen, since the purse IS password-protected... then where's the master key?
    {
        OTLog::vOutput(0, "%s: Error: internal master key has not yet been generated.\n", szFunc);
        return NULL;
    }
    // -------------------------------------------
    // By this point we know the purse is password protected, the internal master key
    // exists (not NULL) and it's been properly generated, so we won't be inadvertantly sticking
    // a copy of it on the masterkey map indexed to some nonexistent ID for an ungenerated key.
    // The caller will be forced to make sure the master key is real and generated, before passing
    // it in here where it could get copied.
    //
    // Why is that important? BECAUSE THE COPY is all the caller will ever actually use! So if it's
    // not ENTIRELY loaded up properly BEFORE it's copied, the caller will never see the properly
    // loaded version of that master key.
    // 
    return OTMasterKey::It(*m_pMasterKey); // here we return a cached copy of the master key (so it's available between instances of this purse.)
}



// ----------------------------------------------------
// INTERNAL KEY: For adding a PASSPHRASE to a PURSE.
//
// What if you DON'T want to encrypt the purse to your Nym??
// What if you just want to use a passphrase instead?
// That's what these functions are for. OT just generates
// a symmetric key and stores it INSIDE THE PURSE. You set the
// passphrase for the symmetric key, and thereafter your 
// experience is one of a password-protected purse.
//
bool OTPurse::GenerateInternalKey()
{
    const char * szFunc = "OTPurse::GenerateInternalKey";
    // -------------------------------------------    
    if ( this->IsPasswordProtected()     ||
        (NULL != m_pSymmetricKey)        ||    //this->GetInternalKey())
        (NULL != m_pMasterKey)
       )
    {
        OTLog::vOutput(0, "%s: Failed: internal Key  or master key already exists. "
                       "Or IsPasswordProtected was true.\n", szFunc);
        return false;
    }
    // -------------------------------------------    
    if (!this->IsEmpty())
    {
        OTLog::vOutput(0, "%s: Failed: The purse must be EMPTY before you create a "
                       "new symmetric key, internal to that purse. (For the purposes of "
                       "adding a passphrase to the purse, normally.) Otherwise I would have "
                       "to loop through all the tokens and re-assign ownership of each one. "
                       "Instead, I'm just going to return false. That's easier.\n", szFunc);
        return false;
    }
    // ------------------------------------------------------------------------
//  OTSymmetricKey *   m_pSymmetricKey;    // If this purse contains its own symmetric key (instead of using an owner Nym)...
//  OTMasterKey    *   m_pMasterKey;       // ...then it will have a master key as well, for unlocking that symmetric key, and managing timeouts.

    // m_pSymmetricKey and m_pMasterKey are both explicitly checked for NULL (above.)
    // Therefore we have to instantiate them both now.
    //
    // We'll do the Master key first, since we need the passphrase from that, in order to
    // create the symmetric key.
    //
    OTPassword  thePassphrase;
    const OTString strDisplay("Enter the new passphrase for this new password-protected purse."); // todo internationalization / hardcoding.
    // ------------------------------------------------------------------------
    // thePassphrase and m_pMasterKey are BOTH output from the below function.
    //
    m_pMasterKey = OTMasterKey::CreateMasterPassword(thePassphrase, strDisplay.Get()); //int nTimeoutSeconds=OT_MASTER_KEY_TIMEOUT)
    if ((NULL == m_pMasterKey) ||
        !m_pMasterKey->IsGenerated()) // This one is unnecessary because CreateMasterPassword already checks it. todo optimize.
    {
        OTLog::vOutput(0, "%s: Failed: While calling OTMasterKey::CreateMasterPassword.\n", szFunc);
        return false;
    }
    // ------------------------------------------------------------------------
    m_pSymmetricKey = new OTSymmetricKey(thePassphrase); // Creates the symmetric key here based on the passphrase from purse's master key.
    OT_ASSERT(NULL != m_pSymmetricKey);
    // ------------------------------------------------------------------
    if (!m_pSymmetricKey->IsGenerated())
    {
        OTLog::vOutput(0, "%s: Failed: generating m_pSymmetricKey.\n", szFunc);
        delete m_pSymmetricKey; m_pSymmetricKey = NULL;
        delete m_pMasterKey;    m_pMasterKey    = NULL;
        return false;
    }
    // ------------------------------------------------------------------
    m_UserID.Release();
    m_bIsNymIDIncluded = false;
    // ------------------------------------------------------------------------
    OTLog::vOutput(1, "%s: Successfully created a purse's internal key.\n", szFunc);
    // -----------------
    m_bPasswordProtected = true;
    // -----------------
    OTMasterKey * pCachedMaster = OTPurse::GetInternalMaster();
    if (NULL == pCachedMaster)
        OTLog::vError("%s: Failed trying to cache the master key for this purse.\n", szFunc);
    // -----------------
	return true;
}





// Take all the tokens from a purse and add them to this purse.
// Don't allow duplicates.
//
bool OTPurse::Merge(const OTPseudonym     & theSigner,
                    OTNym_or_SymmetricKey   theOldNym, // must be private, if a nym.
                    OTNym_or_SymmetricKey   theNewNym, // must be private, if a nym.
                    OTPurse               & theNewPurse)
{
    const char * szFunc = "OTPurse::Merge";
    
	mapOfTokenPointers theMap;
	
	while (this->Count() > 0) 
	{
		OTToken * pToken = this->Pop(theOldNym); // must be private, if a Nym.
		OT_ASSERT_MSG(NULL != pToken, "OTPurse::Merge: Assert: NULL != this->Pop(theOldNym) \n");
				
		const OTASCIIArmor & ascTokenID = pToken->GetSpendable();
		
        std::list<mapOfTokenPointers::iterator> listOfTokenMapIterators;
        
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
                listOfTokenMapIterators.push_back(it);
//				theMap.erase(it);
//				delete pTempToken;
//              pTempToken = NULL;
				//break; // In case there are multiple duplicates, not just one.
			}
		}
        while (listOfTokenMapIterators.size() > 0)
        {
            OTToken * pTempToken = (listOfTokenMapIterators.back())->second;
            theMap.erase(listOfTokenMapIterators.back());
            delete pTempToken;
            pTempToken = NULL;
            listOfTokenMapIterators.pop_back();
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
		
        std::list<mapOfTokenPointers::iterator> listOfTokenMapIterators;

		// I just popped a Token off of theNewPurse. Let's see if it's in my temporary map...
		// If it's already there, then just delete it (it's a duplicate.)
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
                listOfTokenMapIterators.push_back(it);
//				theMap.erase(it);
//				delete pTempToken;
//              pTempToken = NULL;
				//break; // In case there are multiple duplicates, not just one.
			}
		}
        while (listOfTokenMapIterators.size() > 0)
        {
            OTToken * pTempToken = (listOfTokenMapIterators.back())->second;
            theMap.erase(listOfTokenMapIterators.back());
            delete pTempToken;
            pTempToken = NULL;
            listOfTokenMapIterators.pop_back();
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
//      if (false == theNewNym.CompareID(theOldNym)) // Not the same Nym!!
        //
        // UPDATE: the above line was moved INSIDE OTToken::ReassignOwnership, FYI.
        //
        if (false == pToken->ReassignOwnership(theNewNym,  // must be private, if a Nym.
                                               theOldNym)) // can be public, if a Nym.
        {
            OTLog::vError("%s: Error: Failed while attempting to re-assign "
                          "ownership of token during purse merge.\n", szFunc);
        }
        else 
        {
            OTLog::vOutput(1, "%s: FYI: Success re-assigning ownership of "
                           "token during purse merge.\n", szFunc);
            
            pToken->ReleaseSignatures();
            pToken->SignContract(theSigner);
            pToken->SaveContract();
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
		bool bPush = this->Push(theOldNym, // can be public, if a Nym.
                                *pToken);  // The purse makes it's own copy of the token, into string form.
		
		if (!bPush)
        {
			OTLog::vError("%s: Error: Failure pushing token into purse.\n", szFunc);
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






// static -- class factory.
//
OTPurse * OTPurse::LowLevelInstantiate(const OTString     & strFirstLine,
                                       const OTIdentifier & SERVER_ID,
                                       const OTIdentifier & ASSET_ID)
{
    OTPurse * pPurse = NULL;
    if (strFirstLine.Contains("-----BEGIN SIGNED PURSE-----"))  // this string is 28 chars long. todo hardcoding.
	{	pPurse = new OTPurse(SERVER_ID, ASSET_ID);		OT_ASSERT(NULL != pPurse); }
    return pPurse;
}

OTPurse * OTPurse::LowLevelInstantiate(const OTString     & strFirstLine,
                                       const OTIdentifier & SERVER_ID)
{
    OTPurse * pPurse = NULL;
    if (strFirstLine.Contains("-----BEGIN SIGNED PURSE-----"))  // this string is 28 chars long. todo hardcoding.
	{	pPurse = new OTPurse(SERVER_ID);		OT_ASSERT(NULL != pPurse); }
    return pPurse;
}

OTPurse * OTPurse::LowLevelInstantiate(const OTString & strFirstLine)
{
    OTPurse * pPurse = NULL;
    if (strFirstLine.Contains("-----BEGIN SIGNED PURSE-----"))  // this string is 28 chars long. todo hardcoding.
	{	pPurse = new OTPurse();		OT_ASSERT(NULL != pPurse); }
    return pPurse;
}

// --------------------------------------------------------------------

// static -- class factory.
//
// Checks the serverID / AssetID, so you don't have to.
//
OTPurse * OTPurse::PurseFactory(      OTString       strInput,
                                const OTIdentifier & SERVER_ID,
                                const OTIdentifier & ASSET_ID)
{
    const char * szFunc = "OTPurse::PurseFactory";
    // --------------------------------------------------------------------
    OTString strContract, strFirstLine; // output for the below function.
    const bool bProcessed = OTContract::DearmorAndTrim(strInput, strContract, strFirstLine);
    // --------------------------------------------------------------------
    if (bProcessed)
    {
        OTPurse * pPurse = OTPurse::LowLevelInstantiate(strFirstLine, SERVER_ID, ASSET_ID);
        
        // The string didn't match any of the options in the factory.
        if (NULL == pPurse)
            return NULL;
        
        // Does the contract successfully load from the string passed in?
        if (pPurse->LoadContractFromString(strContract))
        {
            if (SERVER_ID != pPurse->GetServerID())
            {
                const OTString strServerID(SERVER_ID), strPurseServerID(pPurse->GetServerID());
                OTLog::vError("%s: Failure: ServerID on purse (%s) doesn't match expected "
                              "server ID (%s).\n", szFunc, strPurseServerID.Get(), strServerID.Get());
                delete pPurse; pPurse = NULL;
            }
            else if (ASSET_ID != pPurse->GetAssetID())
            {
                const OTString strAssetID(ASSET_ID), strPurseAssetID(pPurse->GetAssetID());
                OTLog::vError("%s: Failure: AssetID on purse (%s) doesn't match expected "
                              "asset ID (%s).\n", szFunc, strPurseAssetID.Get(), strAssetID.Get());
                delete pPurse; pPurse = NULL;
            }
            else
                return pPurse;
        }
        else
        {
            delete pPurse; pPurse = NULL;
        }
    }
	
	return NULL;
}

// --------------------------------------------------------------------

// Checks the serverID, so you don't have to.
//
OTPurse * OTPurse::PurseFactory(      OTString       strInput,
                                const OTIdentifier & SERVER_ID)
{
    const char * szFunc = "OTPurse::PurseFactory";
    // --------------------------------------------------------------------
    OTString strContract, strFirstLine; // output for the below function.
    const bool bProcessed = OTContract::DearmorAndTrim(strInput, strContract, strFirstLine);
    // --------------------------------------------------------------------
    if (bProcessed)
    {
        OTPurse * pPurse = OTPurse::LowLevelInstantiate(strFirstLine, SERVER_ID);
        
        // The string didn't match any of the options in the factory.
        if (NULL == pPurse)
            return NULL;
        
        // Does the contract successfully load from the string passed in?
        if (pPurse->LoadContractFromString(strContract))
        {
            if (SERVER_ID != pPurse->GetServerID())
            {
                const OTString strServerID(SERVER_ID), strPurseServerID(pPurse->GetServerID());
                OTLog::vError("%s: Failure: ServerID on purse (%s) doesn't match expected "
                              "server ID (%s).\n", szFunc, strPurseServerID.Get(), strServerID.Get());
                delete pPurse; pPurse = NULL;
            }
            else
                return pPurse;
        }
        else
        {
            delete pPurse; pPurse = NULL;
        }
    }
	
	return NULL;
}

// --------------------------------------------------------------------

OTPurse * OTPurse::PurseFactory(OTString strInput)
{
//  const char * szFunc = "OTPurse::PurseFactory";
    // --------------------------------------------------------------------
    OTString strContract, strFirstLine; // output for the below function.
    const bool bProcessed = OTContract::DearmorAndTrim(strInput, strContract, strFirstLine);
    // --------------------------------------------------------------------
    if (bProcessed)
    {
        OTPurse * pPurse = OTPurse::LowLevelInstantiate(strFirstLine);
        
        // The string didn't match any of the options in the factory.
        if (NULL == pPurse)
            return NULL;
        
        // Does the contract successfully load from the string passed in?
        if (pPurse->LoadContractFromString(strContract))
            return pPurse;
        else
            delete pPurse;
    }
	
	return NULL;
}

// --------------------------------------------------------------------

//private, used by factory.
OTPurse::OTPurse() : ot_super(),
//	m_ServerID(),
//	m_AssetID(),
	m_lTotalValue(0),
    m_bPasswordProtected(false),
    m_bIsNymIDIncluded(false),
    m_pSymmetricKey(NULL),
    m_pMasterKey(NULL)
{
	InitPurse();
}


OTPurse::OTPurse(const OTPurse & thePurse) : ot_super(),
	m_ServerID(thePurse.GetServerID()),
	m_AssetID(thePurse.GetAssetID()),
	m_lTotalValue(0),
    m_bPasswordProtected(false),
    m_bIsNymIDIncluded(false),
    m_pSymmetricKey(NULL),
    m_pMasterKey(NULL)
{
	InitPurse();
}


// Don't use this unless you really don't have the asset type handy.
// Perhaps you know you're about to read this purse from a string and you
// know the asset type is in there anyway. So you use this constructor.
OTPurse::OTPurse(const OTIdentifier & SERVER_ID) : ot_super(),
	m_ServerID(SERVER_ID),
    m_lTotalValue(0),
    m_bPasswordProtected(false),
    m_bIsNymIDIncluded(false),
    m_pSymmetricKey(NULL),
    m_pMasterKey(NULL)
{
	InitPurse();
}

OTPurse::OTPurse(const OTIdentifier & SERVER_ID, const OTIdentifier & ASSET_ID) : ot_super(),
	m_ServerID(SERVER_ID),
	m_AssetID(ASSET_ID),
    m_lTotalValue(0),
    m_bPasswordProtected(false),
    m_bIsNymIDIncluded(false),
    m_pSymmetricKey(NULL),
    m_pMasterKey(NULL)
{
	InitPurse();
}



OTPurse::OTPurse(const OTIdentifier & SERVER_ID, 
				 const OTIdentifier & ASSET_ID, 
				 const OTIdentifier & USER_ID) : ot_super(),
	m_UserID(USER_ID),
	m_ServerID(SERVER_ID),
	m_AssetID(ASSET_ID),
    m_lTotalValue(0),
    m_bPasswordProtected(false),
    m_bIsNymIDIncluded(false),
    m_pSymmetricKey(NULL),
    m_pMasterKey(NULL)
{
	InitPurse();
}

void OTPurse::InitPurse()
{
	m_strContractType.Set("PURSE");
	
	m_lTotalValue = 0;
    
    m_bPasswordProtected = false;
    m_bIsNymIDIncluded   = false;
}


OTPurse::~OTPurse()
{
    Release_Purse();
}



void OTPurse::Release_Purse()
{
	// This sets m_lTotalValue to 0 already.
	ReleaseTokens();
//	m_lTotalValue = 0;
    // -----------------------
    m_bPasswordProtected = false;
    m_bIsNymIDIncluded   = false;
    // -----------------------
    // the Temp Nym is when a purse contains its own Nym, created just
    // for that purse, so that it can be password protected instead of using
    // one of the real Nyms in your wallet.
    //
    if (NULL != m_pSymmetricKey)
    {
        delete m_pSymmetricKey;
        m_pSymmetricKey = NULL;
    }
    // -----------------------
    if (NULL != m_pMasterKey)
    {
        delete m_pMasterKey;
        m_pMasterKey = NULL;
    }
    // -----------------------
}


void OTPurse::Release()
{
    Release_Purse();
    // -----------------------
	ot_super::Release();
    
    InitPurse();
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
    OT_ASSERT(!this->IsPasswordProtected());
	// -----------------------------------------
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
    OT_ASSERT(!this->IsPasswordProtected());
	// -----------------------------------------
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
	// ------------------------------------
    const char * szFunc = "OTPurse::UpdateContents";
	// ------------------------------------
	// I release this because I'm about to repopulate it.
	m_xmlUnsigned.Release();
	
	m_xmlUnsigned.Concatenate("<?xml version=\"%s\"?>\n\n", "1.0");		
	
	m_xmlUnsigned.Concatenate("<purse version=\"%s\"\n"
							  " totalValue=\"%ld\"\n" // Total value of all the tokens within.
                              // --------------
							  " isPasswordProtected=\"%s\"\n"
							  " isNymIDIncluded=\"%s\"\n"
                              // --------------
							  " userID=\"%s\"\n"       // UserID   is optional.
							  " assetTypeID=\"%s\"\n"  // assetTypeID required.
                              " serverID=\"%s\">\n\n", // serverID is required.
                              // --------------
							  m_strVersion.Get(), 
							  m_lTotalValue,
                              // --------------
                              m_bPasswordProtected  ? "true" : "false",
                              m_bIsNymIDIncluded    ? "true" : "false",
                              // --------------
                              // USER_ID / NYM_ID of purse owner.
                              // IF a real NymID (from the user's wallet) is listed in the purse (which is
                              // optional--user's choice) we attach that NymID here...
                              //
							  (m_bIsNymIDIncluded && !m_UserID.IsEmpty()) // (Provided that the ID even exists, of course.)
                               ?  // =====>
                                USER_ID.Get() : "", // Then print the ID (otherwise print an empty string.)
							  (!m_AssetID.IsEmpty())  ? ASSET_TYPE_ID.Get() : "", // (Should never actually be empty.) todo: Change this to just the Get()
							  (!m_ServerID.IsEmpty()) ? SERVER_ID.Get()     : ""  // (Should never actually be empty.) todo: Change this to just the Get()
                              );
	// ----------------------------------------------
    //
    // Save the Internal Symmetric Key here (if there IS one.)
    // (Some Purses own their own internal Symmetric Key, in order to "password protect" the purse.)
    //
    if (m_bPasswordProtected)
    {
        if (NULL == m_pMasterKey)
            OTLog::vError("%s: Error: m_pMasterKey is unexpectedly NULL, even though "
                          "m_bPasswordProtected is true!\n", szFunc);
        else if (NULL == m_pSymmetricKey)
            OTLog::vError("%s: Error: m_pSymmetricKey is unexpectedly NULL, even though "
                          "m_bPasswordProtected is true!\n", szFunc);
        else // m_pMasterKey and m_pSymmetricKey are good pointers. (Or at least, not-null.)
        {
            if (!m_pMasterKey->IsGenerated())
                OTLog::vError("%s: Error: m_pMasterKey wasn't a generated key! Even though "
                              "m_bPasswordProtected is true.\n", szFunc);
            else if (!m_pSymmetricKey->IsGenerated())
                OTLog::vError("%s: Error: m_pSymmetricKey wasn't a generated key! Even though "
                              "m_bPasswordProtected is true.\n", szFunc);
            else
            {
                OTASCIIArmor ascMasterKey, ascSymmetricKey;
                
                if (!m_pMasterKey   ->SerializeTo(ascMasterKey)    || !ascMasterKey   .Exists()  ||
                    !m_pSymmetricKey->SerializeTo(ascSymmetricKey) || !ascSymmetricKey.Exists())
                    OTLog::vError("%s: Error: m_pMasterKey or m_pSymmetricKey failed "
                                  "trying to serialize to OTASCIIArmor.\n", szFunc);
                else
                {
                    // ascInternalKey is good by this point.
                    // Therefore, let's serialize it...
                    //
                    // -------------------------------------------
                    // By this point, ascInternalKey contains the Key itself.
                    //
                    m_xmlUnsigned.Concatenate("<masterKey>\n%s</masterKey>\n\n",
                                              ascMasterKey.Get()); // The "password" for the internal symmetric key.
                    
                    m_xmlUnsigned.Concatenate("<internalKey>\n%s</internalKey>\n\n",
                                              ascSymmetricKey.Get()); // The internal symmetric key, owned by the purse. ascii-armored.
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
    const char *szFunc = "OTPurse::ProcessXMLNode";
    // -----------------------
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
        const OTString strPasswdProtected  = xml->getAttributeValue("isPasswordProtected");
        if (strPasswdProtected.Compare("true"))
            m_bPasswordProtected = true;
        else
            m_bPasswordProtected = false;
        // ---------------------------------
        const OTString strNymIDIncluded = xml->getAttributeValue("isNymIDIncluded");
        if (strNymIDIncluded.Compare("true"))
            m_bIsNymIDIncluded = true;
        else
            m_bIsNymIDIncluded = false;
        // ---------------------------------
        // TODO security: Might want to verify the server ID here, if it's already set.
        // Just to make sure it's the one we were expecting.
		const OTString strServerID		= xml->getAttributeValue("serverID");
        if (strServerID.Exists())
            m_ServerID.SetString(strServerID);
        else
        {
            m_ServerID.Release();
            OTLog::vError("%s: Failed loading serverID, when one was expected.\n", szFunc);
            return (-1);
        }
        // ---------------------------------
        // TODO security: Might want to verify the asset ID here, if it's already set.
        // Just to make sure it's the one we were expecting.
		const OTString strAssetTypeID   = xml->getAttributeValue("assetTypeID");
        if (strAssetTypeID.Exists())
            m_AssetID.SetString(strAssetTypeID);
        else
        {
            m_AssetID.Release();
            OTLog::vError("%s: Failed loading assetTypeID, when one was expected.\n", szFunc);
            return (-1);
        }
        // ---------------------------------
        const OTString strUserID    = xml->getAttributeValue("userID"); // (May not exist.)
        if (m_bIsNymIDIncluded) // Nym ID **is** included.  (It's optional. Even if you use one, you don't have to list it.)
        {
            if (strUserID.Exists())
                m_UserID.SetString(strUserID);
            else
            {
                OTLog::vError("%s: Failed loading userID, when one was expected. "
                              "(isNymIDIncluded was true.)\n", szFunc);
                m_UserID.Release();
                return (-1);
            }
        }
        else// UserID SUPPOSED to be blank here. (Thus the Release.) Maybe later,
            // we might consider trying to read it, in order to validate this.
            //
            m_UserID.Release(); // For now, just assume it's not there to be read, and Release my own value to match it.
        // ---------------------------------		
			
		OTLog::vOutput(4, "%s: Loaded purse... (%s)\n ServerID: %s\n UserID: %s\n Asset ID: %s\n----------\n",
                       szFunc, (m_bPasswordProtected ? "Password-protected" : "NOT password-protected"),
                       strServerID.Get(), m_bIsNymIDIncluded ? strUserID.Get() : "",
                       strAssetTypeID.Get());

		return 1;
	}
    // ----------------------------------------------

    // Sometimes you want the purse to have a passphrase on it, without being attached to
    // one of your actual Nyms in your wallet. To accommodate this, OT creates a symmetric key
    // and stashes it INSIDE the purse. This symmetric key can have whatever passphrase you want.
    // There is also a master key attached, which allows for passphrase timeouts on the symmetric key.
    // Therefore internalKey and masterKey will both be attached to the purse (or neither will be.)
    //
	else if (strNodeName.Compare("internalKey")) 
	{
        if (!m_bPasswordProtected) // If we're NOT using the internal key, then why am I in the middle of loading one here?
        {
            OTLog::vError("%s: Error: Unexpected 'internalKey' data, "
                          "since m_bPasswordProtected is set to false!\n", szFunc);
            return (-1); // error condition
        }
        // ----------------------------------------------------
        if (!m_UserID.IsEmpty()) // If the UserID isn't empty, then why am I in the middle of loading an internal Key?
        {
            OTLog::vError("%s: Error: Unexpected 'internalKey' data, since m_UserID is not blank! "
                         "(The UserID should have loaded before THIS node ever popped up...)\n", szFunc);
            return (-1); // error condition
        }
        // ----------------------------------------------------
        OTASCIIArmor  ascValue;
        
        if (!OTContract::LoadEncodedTextField(xml, ascValue) ||
            !ascValue.Exists())
        {
            OTLog::vError("%s: Error: Expected %s element to have text field.\n",
                          szFunc, "internalKey");
            return (-1); // error condition
        }
        // ----------------------------------------------------
        //
        // Let's see if the internal key is already loaded somehow... (Shouldn't be...)
        //
        if (NULL != m_pSymmetricKey)
        {
            OTLog::vError("%s: WARNING: While loading internal Key for a purse, "
                         "noticed the pointer was ALREADY set! (I'm deleting old one to make room, "
                          "and then allowing this one to load instead...)\n", szFunc);
//          return (-1); // error condition
            
            delete m_pSymmetricKey;
            m_pSymmetricKey = NULL;
        }
        // ----------------------------------------------------
        //
		// By this point, I've loaded up the string containing the encrypted symmetric key.
        // I also know that m_bPasswordProtected is set to true, and I know that m_pSymmetricKey is NULL.
        //
        // (It's only now that I bother instantiating.)
        //
        OTSymmetricKey * pSymmetricKey = new OTSymmetricKey();
        OT_ASSERT_MSG(NULL != pSymmetricKey, "OTPurse::ProcessXMLNode: Assert: NULL != new OTSymmetricKey \n");
        // -----------------
        // NOTE: In the event of any error, need to delete pSymmetricKey before returning.
        // (Or it will leak.)
        //
        if (!pSymmetricKey->SerializeFrom(ascValue))
        {
            OTLog::vError("%s: Error: While loading internal Key for a purse, failed "
                          "serializing from stored string! (Failed loading purse.)\n", szFunc);
            delete pSymmetricKey; pSymmetricKey = NULL;
            return (-1);
        }
        // -----------------
        // By this point, the symmetric key has loaded successfully from storage.

        OTLog::vOutput(1, "%s: Successfully loaded a purse's internal key.\n", szFunc);
        // -----------------
        // No more worry about pSymmetricKey cleanup, now that this pointer is set.

        m_pSymmetricKey = pSymmetricKey;
        // -----------------
		return 1;
	}
	// ----------------------------------------------
    
    else if (strNodeName.Compare("masterKey"))
	{
        if (!m_bPasswordProtected) // If we're NOT using the internal and master keys, then why am I in the middle of loading one here?
        {
            OTLog::vError("%s: Error: Unexpected 'masterKey' data, "
                          "since m_bPasswordProtected is set to false!\n", szFunc);
            return (-1); // error condition
        }
        // ----------------------------------------------------
        if (!m_UserID.IsEmpty()) // If the UserID isn't empty, then why am I in the middle of loading an internal Key?
        {
            OTLog::vError("%s: Error: Unexpected 'masterKey' data, since m_UserID is not blank!\n", szFunc);
            return (-1); // error condition
        }
        // ----------------------------------------------------
        OTASCIIArmor  ascValue;
        
        if (!OTContract::LoadEncodedTextField(xml, ascValue) ||
            !ascValue.Exists())
        {
            OTLog::vError("%s: Error: Expected %s element to have text field.\n",
                          szFunc, "masterKey");
            return (-1); // error condition
        }
        // ----------------------------------------------------
        //
        // Let's see if the master key is already loaded somehow... (Shouldn't be...)
        //
        if (NULL != m_pMasterKey)
        {
            OTLog::vError("%s: WARNING: While loading master Key for a purse, "
                         "noticed the pointer was ALREADY set! (I'm deleting old one to make room, "
                          "and then allowing this one to load instead...)\n", szFunc);
//          return (-1); // error condition
            
            delete m_pMasterKey;
            m_pMasterKey = NULL;
        }
        // ----------------------------------------------------
        //
		// By this point, I've loaded up the string containing the encrypted symmetric key.
        // I also know that m_bPasswordProtected is set to true, and I know that m_pSymmetricKey is NULL.
        //
        // (It's only now that I bother instantiating.)
        //
        OTMasterKey * pMasterKey = new OTMasterKey(ascValue);
        OT_ASSERT_MSG(NULL != pMasterKey, "OTPurse::ProcessXMLNode: Assert: NULL != new OTMasterKey \n");
        // -----------------
        // NOTE: In the event of any error, need to delete pMasterKey before returning.
        // (Or it will leak.)
        //
        if (!pMasterKey->SerializeFrom(ascValue))
        {
            OTLog::vError("%s: Error: While loading master Key for a purse, failed "
                          "serializing from stored string! (Failed loading purse.)\n", szFunc);
            delete pMasterKey; pMasterKey = NULL;
            return (-1);
        }
        // -----------------
        // By this point, the symmetric key has loaded successfully from storage.

        OTLog::vOutput(1, "%s: Successfully loaded a purse's master key.\n", szFunc);
        // -----------------
        // No more worry about pSymmetricKey cleanup, now that this pointer is set.

        m_pMasterKey = pMasterKey;
        
        // NOTE: Hereafter, do NOT use m_pMasterKey directly.
        // Instead, use OTMasterKey::It(*m_pMasterKey) (So you deal with the cached
        // version, and avoid forcing the user to re-type his passphrase more than
        // necessary according to timeouts designed in OTMasterKey class.)
        //
        // In fact, don't even use that. Instead, I'll add an OTPurse::GetPassphrase
        // method, which handles that for you.
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
			OTLog::vError("%s: Error: token field without value.\n", szFunc);
			
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


// Caller IS responsible to delete. (Peek returns an instance of the
// actual token, which is stored in encrypted form inside the purse.)
//
OTToken * OTPurse::Peek(OTNym_or_SymmetricKey theOwner) const
{
    const char * szFunc = "OTPurse::Peek";
    // ---------------
	if (m_dequeTokens.empty())
		return NULL;
    // ---------------
	// Grab a pointer to the first armored token on the deque.
    //
	const OTASCIIArmor * pArmor =  m_dequeTokens.front();
    // ---------------	
    // Copy the token contents into an Envelope.
	OTEnvelope theEnvelope(*pArmor);
    // ---------------
	// Open the envelope into a string.
	//
    OTString strToken;
    const
    OTString strDisplay(szFunc); // this is the passphrase string that will display if theOwner doesn't have one already.
    // ---------------
    const bool bSuccess = theOwner.Open_or_Decrypt(theEnvelope, strToken, &strDisplay);
    // ---------------
    if (bSuccess)
    {
        // Create a new token with the same server and asset IDs as this purse.
        OTToken * pToken = OTToken::TokenFactory(strToken, *this);
        OT_ASSERT(NULL != pToken);
        
        if (pToken->GetAssetID()  != m_AssetID ||
            pToken->GetServerID() != m_ServerID)
        {
            delete pToken;
            pToken = NULL;
            
            OTLog::vError("%s: ERROR: Cash token with wrong server or asset type.\n", szFunc);
        }
        else 
        {
            // CALLER is responsible to delete this token.
            return pToken;
        }
    }
    else
        OTLog::vError("%s: Failure: theOwner.Open_or_Decrypt.\n", szFunc);

	return NULL;
}


// Hypocritically (compared to Push) in the case of Pop(), we DO
// allocate a OTToken and return the pointer. The caller IS
// responsible to delete it when he's done with it.
// 
// The apparent discrepancy is due to the fact that internally,
// we aren't storing the token object but an encrypted string of it.
// But this is hidden from the user of the purse, who perceives only
// that he is passing tokens in and getting them back out again.
//
OTToken * OTPurse::Pop( OTNym_or_SymmetricKey theOwner)
{
    const char * szFunc = "OTPurse::Pop";
    // ---------------
	if (m_dequeTokens.empty())
		return NULL;
    // ---------------
    OTToken * pToken = this->Peek(theOwner);
    // ---------------
	if (NULL == pToken)
    {
        OTLog::vError("%s: Failure: this->Peek(theOwner) "
                      "(And m_dequeTokens isn't empty, either.)\n", szFunc);
		return NULL;
    }
    // ---------------
	// Grab a pointer to the ascii-armored token, and remove it from the deque.
    // (And delete it.)
    //
	OTASCIIArmor * pArmor =  m_dequeTokens.front();
	m_dequeTokens.pop_front();
	delete pArmor; pArmor = NULL;	
    // ---------------
    // We keep track of the purse's total value.
    m_lTotalValue -= pToken->GetDenomination();
    // ---------------    
    // CALLER is responsible to delete this token.
    return pToken;
}


// Use a local variable for theToken, do NOT allocate it on the heap 
// unless you are going to delete it yourself.
// Repeat: OTPurse is NOT responsible to delete it. We create our OWN internal
// variable here, new that, and add it to the stack. We do not add the one passed in.
bool OTPurse::Push( OTNym_or_SymmetricKey theOwner, const OTToken & theToken)
{
    const char * szFunc = "OTPurse::Push";
    // ---------------
	if (theToken.GetAssetID() == m_AssetID)
	{
        const
        OTString strDisplay(szFunc); // this is the passphrase string that will display if theOwner doesn't have one already.
        // -----------------------------------
		OTString strToken(theToken);
		OTEnvelope theEnvelope;
        const bool bSuccess = theOwner.Seal_or_Encrypt(theEnvelope, strToken, &strDisplay);
		
        if (bSuccess)
        {
            OTASCIIArmor * pArmor = new OTASCIIArmor(theEnvelope);

            m_dequeTokens.push_front(pArmor);
            
            // We keep track of the purse's total value.
            m_lTotalValue += theToken.GetDenomination();
            
            return true;
        }
        else
        {
            OTString strPurseAssetType(m_AssetID), strTokenAssetType(theToken.GetAssetID());
            OTLog::vError("%s: Failed while calling: theOwner.Seal_or_Encrypt(theEnvelope, strToken)\nPurse Asset Type:\n%s\n"
                          "Token Asset Type:\n%s\n", szFunc, strPurseAssetType.Get(), strTokenAssetType.Get());
        }
	}
	else
    {
		OTString strPurseAssetType(m_AssetID), strTokenAssetType(theToken.GetAssetID());
		OTLog::vError("%s: ERROR: Tried to push token with wrong asset type.\nPurse Asset Type:\n%s\n"
				"Token Asset Type:\n%s\n", szFunc, strPurseAssetType.Get(), strTokenAssetType.Get());
	}
    // ----------------------------------------------
    return false;
}



int OTPurse::Count() const
{
	return static_cast<int> (m_dequeTokens.size());
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

