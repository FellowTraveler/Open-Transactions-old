/*************************************************************
 *    
 *  OTAssetContract.cpp
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


#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "irrxml/irrXML.h"

using namespace irr;
using namespace io;

#include "OTStorage.h"

#include "OTAssetContract.h"
#include "OTStringXML.h"
#include "OTIdentifier.h"
#include "OTPseudonym.h"
#include "OTAccount.h"
#include "OTBasket.h"
#include "OTLog.h"



OTAssetContract::OTAssetContract() : OTContract(), m_bIsCurrency(true), m_bIsShares(false)
{
	
}

OTAssetContract::OTAssetContract(OTString & name, OTString & foldername, OTString & filename, OTString & strID) 
: OTContract(name, foldername, filename, strID), m_bIsCurrency(true), m_bIsShares(false)
{

}


OTAssetContract::~OTAssetContract()
{
	// OTContract::~OTContract is called here automatically, and it calls Release.
	// So I don't need to call it here again when it's already called by the parent.
}



// Normally, Asset Contracts do NOT update / rewrite their contents, since their
// primary goal is for the signature to continue to verify.  But when first creating
// a basket contract, we have to rewrite the contents, which is done here.
bool OTAssetContract::CreateBasket(OTBasket & theBasket, OTPseudonym & theSigner)
{
	Release();

	// Grab a string copy of the basket information.
	theBasket.SaveContractRaw(m_strBasketInfo);
	
	// -------------------------------
	
	// Insert the server's public key as the "contract" key for this basket currency.
	OTString strPubKey, strKeyName("contract"); // todo stop hardcoding
	theSigner.GetPublicKey().GetPublicKey(strPubKey);
	
	InsertNym(strKeyName, strPubKey);

	// todo check the above two return values.
	
	OTASCIIArmor theBasketArmor(m_strBasketInfo);
	
	// -------------------------------
	
	m_xmlUnsigned.Concatenate("<?xml version=\"%s\"?>\n\n", "1.0");		
	
	m_xmlUnsigned.Concatenate("<basketContract version=\"%s\">\n\n", m_strVersion.Get());
	m_xmlUnsigned.Concatenate("<basketInfo>\n%s</basketInfo>\n\n", theBasketArmor.Get());
	m_xmlUnsigned.Concatenate("<key name=\"%s\">\n%s</key>\n\n", strKeyName.Get(), strPubKey.Get());

	m_xmlUnsigned.Concatenate("</basketContract>\n");		
	

	// This function assumes that m_xmlUnsigned is ready to be processed.
	// This function only processes that portion of the contract.
	bool bLoaded = LoadContractXML();
	
	if (bLoaded)
	{
		OTString strTemp;

		SignContract(theSigner);
		RewriteContract(strTemp); // this trims

		// This is probably redundant...
//		std::string str_Trim(strTemp.Get());
//		std::string str_Trim2 = OTString::trim(str_Trim);
//		strTemp.Set(str_Trim2.c_str());
		// -----------------------------------
		Release();
		
		LoadContractFromString(strTemp);
		SaveContract();
		
		OTIdentifier NEW_ID;
		CalculateContractID(NEW_ID);
		m_ID = NEW_ID;	
		
		return true;
	}	
	
	return false;
	
}

	
bool OTAssetContract::DisplayStatistics(OTString & strContents) const
{
	const OTString strID(m_ID);
	
	strContents.Concatenate(
							" Asset Type:  %s\n"
							" AssetTypeID: %s\n"
							"\n",
							m_strName.Get(),
							strID.Get());
	return true;
}


bool OTAssetContract::SaveContractWallet(OTString & strContents) const
{
	const OTString strID(m_ID);
	
	OTASCIIArmor ascName;
	
	if (m_strName.Exists()) // name is in the clear in memory, and base64 in storage.
	{
		ascName.SetString(m_strName, false); // linebreaks == false
	}
	
	strContents.Concatenate("<assetType name=\"%s\"\n"
							" assetTypeID=\"%s\" />\n\n",
							m_strName.Exists() ? ascName.Get() : "",
							strID.Get());
	
	return true;
}


bool OTAssetContract::SaveContractWallet(std::ofstream & ofs)
{
	OTString strOutput;
	
	if (SaveContractWallet(strOutput))
	{
		ofs << strOutput.Get();
		return true;
	}
	
	return false;
}



/*
bool OTAssetContract::SaveContractWallet(FILE * fl)
{
	OTString strID(m_ID);
	
	fprintf(fl, "<assetType name=\"%s\"\n assetTypeID=\"%s\"\n contract=\"%s\" /> "
			"\n\n", m_strName.Get(), strID.Get(), m_strFilename.Get());	
	
	return true;
}
*/

// ----------------------------------------------------------------

OTAcctFunctor::OTAcctFunctor(const OTIdentifier & theServerID, mapOfAccounts * pLoadedAccounts/*=NULL*/)
 : m_pServerID(new OTIdentifier(theServerID)), // owned
   m_pLoadedAccounts(pLoadedAccounts) // not owned
{
        
}

OTAcctFunctor::~OTAcctFunctor()
{
    if (NULL != m_pServerID)
        delete m_pServerID;
    m_pServerID = NULL;
    
    m_pLoadedAccounts = NULL; // not owned
}

bool OTAcctFunctor::Trigger(OTAccount & theAccount)
{
    OT_ASSERT_MSG(false, "OTAcctFunctor::Trigger: You need to override the Trigger method in your subclass. (It's missing.)");
}

// ----------------------------------------------------------------

// ----------------------------------------------------------------
// currently only "simple" accounts (normal user asset accounts) are added to this list
// Any "special" accounts, such as basket reserve accounts, or voucher reserve accounts,
// or cash reserve accounts, are not included on this list.
//
bool OTAssetContract::ForEachAccountRecord(OTAcctFunctor & theAction)  // Loops through all the accounts for a given asset type, and calls Functor on each.
{
    // Load up account list stringmap
    // if success, iterate through map and trigger theAction.
    // loop
    //    theAction.Trigger(theAcct);
    
    OTString strAssetTypeID, strAcctRecordFile;
    this->GetIdentifier(strAssetTypeID);
    strAcctRecordFile.Format("%s.a", strAssetTypeID.Get());
    // --------------------------------------------------------------
    OTDB::Storable * pStorable = OTDB::QueryObject(OTDB::STORED_OBJ_STRING_MAP, OTLog::ContractFolder(), strAcctRecordFile.Get());
    OTCleanup<OTDB::Storable> theAngel(pStorable); // It will definitely be cleaned up.
    OTDB::StringMap * pMap = (NULL == pStorable) ? NULL : dynamic_cast<OTDB::StringMap *>(pStorable);
    // --------------------------------------------------------------    
    // There was definitely a StringMap loaded from local storage. 
    // (Even an empty one, possibly.) This is the only block that matters in this function.
    //
    if (NULL != pMap) 
    {
        OTIdentifier * pServerID = theAction.GetServerID();        
        OT_ASSERT_MSG(NULL != pServerID, "Assert: NULL Server ID on functor. (How did you even construct the thing?)");
        // -------------------------------------
        mapOfStrings & theMap = pMap->the_map;
        
        // todo: optimize: will probably have to use a database for this, long term. 
        // (What if there are a million acct IDs in this flat file? Not scaleable.)
        //
        FOR_EACH(mapOfStrings, theMap) 
        {
            const std::string & str_acct_id  = (*it).first;	 // Containing the account ID.
            const std::string & str_asset_id = (*it).second; // Containing the asset type ID. (Just in case someone copied the wrong file here...)
            // --------------------------------
            
            if (false == strAssetTypeID.Compare(str_asset_id.c_str()))
            {
                OTLog::vError("OTAssetContract::ForEachAccountRecord: Error: wrong asset type ID (%s) when expecting: %s\n",
                              str_asset_id.c_str(), strAssetTypeID.Get());
            }
            else
            {
                OTAccount * pAccount = NULL;
                OTCleanup<OTAccount> theAcctAngel;
                
                bool  bAlreadyLoaded = false;
                const OTIdentifier theAccountID(str_acct_id.c_str());
                
                // Before loading it from local storage, let's first make sure it's not already loaded.
                // (theAction functor has a list of 'already loaded' accounts, just in case.)
                //
                mapOfAccounts * pLoadedAccounts = theAction.GetLoadedAccts();
                
                if (NULL != pLoadedAccounts) // there are some accounts already loaded, 
                {                            // let's see if the one we're looking for is there...
                    mapOfAccounts::iterator found_it = pLoadedAccounts->find(str_acct_id);
                    
                    if (pLoadedAccounts->end() != found_it) // FOUND IT.
                    {
                        bAlreadyLoaded = true;
                        pAccount = (*found_it).second;
                        OT_ASSERT(NULL != pAccount);
                        
                        if (theAccountID != pAccount->GetPurportedAccountID())
                        {
                            OTLog::Error("Error: the actual account didn't have the ID that the std::map SAID it had! (Should never happen.)\n");
                            bAlreadyLoaded = false;
                            pAccount       = NULL;
                        }
                    }
                }
                // ------------------------------------------------
                // I guess it wasn't already loaded...
                // Let's try to load it.
                //
                if (NULL == pAccount)
                {
                    pAccount = OTAccount::LoadExistingAccount(theAccountID, *pServerID);
                    theAcctAngel.SetCleanupTargetPointer(pAccount);
                }
                // --------------------------------            
                const bool bSuccessLoadingAccount = ((pAccount != NULL) ? true:false );
                if (bSuccessLoadingAccount)
                {
                    const bool bTriggerSuccess = theAction.Trigger(*pAccount);   // <=========
                    // todo, log?
                }   
                else
                {
                    // todo, log?
                }
                // --------------------------------            
            }
        } // FOR_EACH
        
        return true;
    } // if pMap != NULL
    // ----------------------------------------------------------------
    else // nothing was loaded up from local storage. No String Map. It was NULL.
    {
        // Therefore I couldn't possibly loop through "EachAccountRecord", 
        // if there ARE NO account records... right?
        //
        return true; // 
    }
    
    return false; // should never happen.
}

// ----------------------------------------------------------------


bool OTAssetContract::AddAccountRecord(const OTAccount & theAccount) // adds the account to the list. (When account is created.)
{
    //  Load up account list StringMap. Create it if doesn't already exist.
    //  See if account is already there in the map. Add it otherwise.
    //  Save the StringMap back again. (The account records list for a given asset type.)
    
    const char * szFunc = "OTAssetContract::AddAccountRecord";
    
    if (theAccount.GetAssetTypeID() != m_ID)
    {
        OTLog::vError("%s: Error: theAccount doesn't have the same asset type ID as *this does.\n",
                      szFunc);
        return false;
    }
    // --------------------------------------------------------------
    const OTIdentifier theAcctID(theAccount);
    const OTString     strAcctID(theAcctID);
    // --------------------------------------------------------------
    OTString strAssetTypeID, strAcctRecordFile;
    this->GetIdentifier(strAssetTypeID);
    strAcctRecordFile.Format("%s.a", strAssetTypeID.Get());
    // --------------------------------------------------------------
    OTDB::Storable * pStorable = NULL;
    OTCleanup<OTDB::Storable> theAngel;
    OTDB::StringMap * pMap = NULL;
    // --------------------------------------------------------------
    if (OTDB::Exists(OTLog::ContractFolder(), strAcctRecordFile.Get())) // the file already exists; let's try to load it up.
        pStorable = OTDB::QueryObject(OTDB::STORED_OBJ_STRING_MAP, OTLog::ContractFolder(), strAcctRecordFile.Get());
    else // the account records file (for this asset type) doesn't exist.
        pStorable = OTDB::CreateObject(OTDB::STORED_OBJ_STRING_MAP); // this asserts already, on failure.
    
    theAngel.SetCleanupTargetPointer(pStorable); // It will definitely be cleaned up.
    pMap = (NULL == pStorable) ? NULL : dynamic_cast<OTDB::StringMap *>(pStorable);
    // --------------------------------------------------------------
    // It exists.
    //
    if (NULL == pMap) 
    {
        OTLog::vError("%s: Error: failed trying to load or create the account records file for asset type: %s\n", 
                      szFunc, strAssetTypeID.Get());
        return false;
    }
    // -----------------------------------------------
    mapOfStrings &         theMap = pMap->the_map;
    mapOfStrings::iterator map_it = theMap.find(strAcctID.Get());
    
    if (theMap.end() != map_it) // we found it.
    {   // We were ADDING IT, but it was ALREADY THERE. 
        // (Thus, we're ALREADY DONE.)
        // Let's just make sure the right asset type ID is associated with this account 
        // (it better be, since we loaded the account records file based on the asset type ID as its filename...)
        //
        const std::string & str2 = (*map_it).second; // Containing the asset type ID. (Just in case someone copied the wrong file here, 
        // --------------------------------          // every account should map to the SAME asset ID.)

        if (false == strAssetTypeID.Compare(str2.c_str())) // should never happen.
        {
            OTLog::vError("%s: Error: wrong asset type found in account records file...\n For asset type: %s\n "
                          "For account: %s\n Found wrong asset type: %s\n", szFunc, strAssetTypeID.Get(),
                          strAcctID.Get(), str2.c_str());
            return false;
        }

        return true; // already there (no need to add.) + the asset type ID matches.
    }
    // ---------------------------------------------------
    // it wasn't already on the list...

    // ...so add it.
    //
    theMap[strAcctID.Get()] = strAssetTypeID.Get();
    
    // ---------------------------------------------------
    // Then save it back to local storage:
    //
    if (false == OTDB::StoreObject(*pMap, OTLog::ContractFolder(), strAcctRecordFile.Get()))
    {
        OTLog::vError("%s: Failed trying to StoreObject, while saving updated "
                      "account records file for asset type: %s\n to contain account ID: %s\n", 
                      szFunc, strAssetTypeID.Get(), strAcctID.Get());
        return false;
    }
    // ----------------------------------------------------------------
    // Okay, we saved the updated file, with the account added. (done, success.)
    //
    return true;
}

// ----------------------------------------------------------------

bool OTAssetContract::EraseAccountRecord(const OTIdentifier & theAcctID)  // removes the account from the list. (When account is deleted.)
{
    //  Load up account list StringMap. Create it if doesn't already exist.
    //  See if account is already there in the map. Erase it, if it is.
    //  Save the StringMap back again. (The account records list for a given asset type.)
    
    const char * szFunc = "OTAssetContract::EraseAccountRecord";    
    // --------------------------------------------------------------
    const OTString     strAcctID(theAcctID);
    // --------------------------------------------------------------
    OTString strAssetTypeID, strAcctRecordFile;
    this->GetIdentifier(strAssetTypeID);
    strAcctRecordFile.Format("%s.a", strAssetTypeID.Get());
    // --------------------------------------------------------------
    OTDB::Storable * pStorable = NULL;
    OTCleanup<OTDB::Storable> theAngel;
    OTDB::StringMap * pMap = NULL;
    // --------------------------------------------------------------
    if (OTDB::Exists(OTLog::ContractFolder(), strAcctRecordFile.Get())) // the file already exists; let's try to load it up.
        pStorable = OTDB::QueryObject(OTDB::STORED_OBJ_STRING_MAP, OTLog::ContractFolder(), strAcctRecordFile.Get());
    else // the account records file (for this asset type) doesn't exist.
        pStorable = OTDB::CreateObject(OTDB::STORED_OBJ_STRING_MAP); // this asserts already, on failure.
    
    theAngel.SetCleanupTargetPointer(pStorable); // It will definitely be cleaned up.
    pMap = (NULL == pStorable) ? NULL : dynamic_cast<OTDB::StringMap *>(pStorable);
    // --------------------------------------------------------------
    // It exists.
    //
    if (NULL == pMap) 
    {
        OTLog::vError("%s: Error: failed trying to load or create the account records file for asset type: %s\n", 
                      szFunc, strAssetTypeID.Get());
        return false;
    }
    // -----------------------------------------------
    // Before we can erase it, let's see if it's even there....
    //
    mapOfStrings &         theMap = pMap->the_map;
    mapOfStrings::iterator map_it = theMap.find(strAcctID.Get());
    
    // we found it!
    if (theMap.end() != map_it) //  Acct ID was already there...
    {           
        theMap.erase(map_it); // remove it
    }
    // ---------------------------------------------------
    // it wasn't already on the list...
    // (So it's like success, since the end result is, acct ID will not appear on this list--whether
    // it was there or not beforehand, it's definitely not there now.)
    
    // Then save it back to local storage:
    //
    if (false == OTDB::StoreObject(*pMap, OTLog::ContractFolder(), strAcctRecordFile.Get()))
    {
        OTLog::vError("%s: Failed trying to StoreObject, while saving updated "
                      "account records file for asset type: %s\n to erase account ID: %s\n", 
                      szFunc, strAssetTypeID.Get(), strAcctID.Get());
        return false;
    }
    // ----------------------------------------------------------------
    // Okay, we saved the updated file, with the account removed. (done, success.)
    //
    return true;
}


// ----------------------------------------------------------------

// return -1 if error, 0 if nothing, and 1 if the node was processed.
int OTAssetContract::ProcessXMLNode(IrrXMLReader*& xml)
{
	int nReturnVal = OTContract::ProcessXMLNode(xml);

	// Here we call the parent class first.
	// If the node is found there, or there is some error,
	// then we just return either way.  But if it comes back
	// as '0', then nothing happened, and we'll continue executing.
	//
	// -- Note you can choose not to call the parent if
	// you don't want to use any of those xml tags.
	
	if (nReturnVal == 1 || nReturnVal == (-1))
		return nReturnVal;
	
    const OTString strNodeName(xml->getNodeName());
    
	if (strNodeName.Compare("digitalAssetContract"))
	{
		m_strVersion = xml->getAttributeValue("version");					
		
		OTLog::vOutput(1, "\n"
				"===> Loading XML portion of asset contract into memory structures...\n\n"
				"Digital Asset Contract: %s\nContract version: %s\n----------\n", m_strName.Get(), m_strVersion.Get());
		nReturnVal = 1;
	}
    
	else if (strNodeName.Compare("basketContract"))
	{
		m_strVersion = xml->getAttributeValue("version");					
		
		OTLog::vOutput(1, "\n"
				"===> Loading XML portion of basket contract into memory structures...\n\n"
				"Digital Basket Contract: %s\nContract version: %s\n----------\n", m_strName.Get(), m_strVersion.Get());
		nReturnVal = 1;
	}
	
	else if (strNodeName.Compare("basketInfo")) 
	{		
		if (false == OTContract::LoadEncodedTextField(xml, m_strBasketInfo))
		{
			OTLog::Error("Error in OTAssetContract::ProcessXMLNode: basketInfo field without value.\n");
			return (-1); // error condition
		}
		
		return 1;
	}
	
	else if (strNodeName.Compare("issue"))
	{
		m_strIssueCompany = xml->getAttributeValue("company");
		m_strIssueEmail = xml->getAttributeValue("email");
		m_strIssueContractURL = xml->getAttributeValue("contractUrl");
		m_strIssueType = xml->getAttributeValue("type");
		
		OTLog::vOutput(2, "Loaded Issue company: %s\nEmail: %s\nContractURL: %s\nType: %s\n----------\n",
				m_strIssueCompany.Get(), m_strIssueEmail.Get(), m_strIssueContractURL.Get(),
				m_strIssueType.Get());
		nReturnVal = 1;
	}
        
	else if (strNodeName.Compare("currency") )    
	{
        m_bIsCurrency             = true;  // silver grams
        m_bIsShares               = false;        

		m_strName                 = xml->getAttributeValue("name");
		m_strCurrencyName         = xml->getAttributeValue("name");
		
		m_strCurrencyTLA          = xml->getAttributeValue("tla");
		m_strCurrencySymbol       = xml->getAttributeValue("symbol");
		m_strCurrencyType         = xml->getAttributeValue("type");
		m_strCurrencyFactor       = xml->getAttributeValue("factor");
		m_strCurrencyDecimalPower = xml->getAttributeValue("decimal_power");
		m_strCurrencyFraction     = xml->getAttributeValue("fraction");
		
		OTLog::vOutput(2, "Loaded %s, Name: %s, TLA: %s, Symbol: %s\n"
                       "Type: %s, Factor: %s, Decimal Power: %s, Fraction: %s\n----------\n", 
                       strNodeName.Get(),
                       m_strCurrencyName.Get(), m_strCurrencyTLA.Get(), m_strCurrencySymbol.Get(),
                       m_strCurrencyType.Get(), m_strCurrencyFactor.Get(), m_strCurrencyDecimalPower.Get(),
                       m_strCurrencyFraction.Get());
		nReturnVal = 1;
	}
	
    //        share_type some type, for example, A or B, or NV (non voting)
    //        
    //        share_name this is the long legal name of the company
    //        
    //        share_symbol this is the trading name (8 chars max), as it might be 
    //          displayed in a market contect, and should be unique within some given market
    //        
    //        share_issue_date date of start of this share item (not necessarily IPO)

	else if (strNodeName.Compare("shares") )       
	{
        m_bIsShares           = true;        // shares of pepsi
        m_bIsCurrency         = false;
        
		m_strName			  = xml->getAttributeValue("name");
		m_strCurrencyName	  = xml->getAttributeValue("name");	
        
		m_strCurrencySymbol   = xml->getAttributeValue("symbol");
		m_strCurrencyType     = xml->getAttributeValue("type");
        
		m_strIssueDate        = xml->getAttributeValue("issuedate");
		
		OTLog::vOutput(2, "Loaded %s, Name: %s, Symbol: %s\n"
                       "Type: %s, Issue Date: %s\n----------\n", 
                       strNodeName.Get(),
                       m_strCurrencyName.Get(), m_strCurrencySymbol.Get(),
                       m_strCurrencyType.Get(),
                       m_strIssueDate.Get());
		nReturnVal = 1;
	}
	
	return nReturnVal;
}














































