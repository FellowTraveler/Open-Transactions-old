/*************************************************************
 *    
 *  OTAssetContract.cpp
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


#include <cstring>
#include <cmath>


#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include <locale>
#include <iterator>


#include "irrxml/irrXML.h"

using namespace irr;
using namespace io;

#include "OTStorage.h"

#include "OTPayload.h"
#include "OTAssetContract.h"
#include "OTStringXML.h"
#include "OTIdentifier.h"
#include "OTPseudonym.h"
#include "OTAccount.h"
#include "OTBasket.h"
#include "OTLog.h"



// ----------------------------------------------------------------------------


OTAmount::OTAmount(int64_t lAmount/*=0*/) :
    m_lAmount(lAmount)
{
    
}


OTAmount::OTAmount(const OTAmount & other) : m_lAmount(other.GetAmount())
{
    
}


OTAmount& OTAmount::operator=(OTAmount other)
{
    swap(*this, other);
    return *this;
}



// C++11  (move constructor)
//OTAmount::OTAmount(OTAmount&& other)
//: OTAmount() // initialize via default constructor, C++11 only
//{
//    swap(*this, other);
//}


// ----------------------------------------------------------------------------

//static
std::string OTAssetContract::formatLongAmount(long & lOriginalValue, int nFactor/*=100*/, int nPower/*=2*/, const char * szSymbol/*=""*/,
                                              const char * szSeparator/*=","*/, const char * szDecimalPoint/*="."*/)
{
    std::stringstream sss;
    OTString strRemainder;

    if (0 == lOriginalValue)
    {
        sss << szSymbol << " "; // Currency symbol

        if (!(nFactor < 2))
        {
            sss << szDecimalPoint;

            strRemainder.Format("%0*ld", nPower, 0);
        }
        else
            strRemainder.Format("%ld", 0);

        sss << strRemainder.Get();
        return sss.str();
    }
    // --------------------------------------------------
    long lAbsoluteValue = (lOriginalValue > 0) ? lOriginalValue : (lOriginalValue * (-1));
    // --------------------------------------------------
    int power = 0;
    
    long lValue     = lAbsoluteValue / nFactor;
    long lRemainder = lAbsoluteValue % nFactor;
 
    strRemainder.Format((nFactor < 2) ? "" : "%0*ld", nPower, lRemainder);
    // ------------------------------------------------------
    while (lValue / static_cast<long>(pow(static_cast<long double>(1000), power)))
    {
        power += 1;
    }
    power -= 1;
    // ------------------------------------------------------
    if (lOriginalValue < 0)
        sss << "-";
        
    sss << szSymbol << " "; // Currency symbol
    // ------------------------------------------------------
    while (power >= 0)
    {        
        long lPow = static_cast<long>(pow(static_cast<long double>(1000), power));
        long lVal = lValue / lPow;
        long lMultiplier = lVal*lPow;
        // -----------------------------
        sss <<  lValue / static_cast<long>(pow(static_cast<long double>(1000), power));
        // -----------------------------
        power -= 1;
        // -----------------------------
        if (power >= 0)
            sss << szSeparator;
        // -----------------------------
        lValue -= lMultiplier;
    }
    // -----------------------------
    if (!(nFactor < 2))
    {
        sss << szDecimalPoint;
        // -----------------------------
        sss << strRemainder.Get();
    }
    // -----------------------------
    return sss.str();
}

// ----------------------------------------------------------------------------

// Convert 912545 to "$9,125.45"
//
// (Assuming a Factor of 100, Decimal Power of 2, Currency Symbol of "$",
//  separator of "," and decimal point of ".")
//
bool OTAssetContract::FormatAmount(const OTAmount & theInput, std::string & str_output) const // Convert 545 to $5.45.
{
    long lValue = static_cast<long>(theInput.GetAmount());
    // --------------------------------------------------------
    int nFactor = atoi(m_strCurrencyFactor.Get()); // default is 100  (100 cents in a dollar)
    if (nFactor < 1)
        nFactor = 1;
//  OT_ASSERT(nFactor > 0); // should be 1, 10, 100, etc.
    // --------------------------------------------------------
    int nPower = atoi(m_strCurrencyDecimalPower.Get()); // default is 2. ($5.05 is moved 2 decimal places.)
    if (nPower < 0)
        nPower = 0;
//  OT_ASSERT(nPower >= 0); // should be 0, 1, 2, etc.
    // --------------------------------------------------------
    // Lookup separator and decimal point symbols based on locale.
    // --------------------------------------------------------
    // Get a moneypunct facet from the global ("C") locale
    //
    static OTString strSeparator    (",");
    static OTString strDecimalPoint (".");
    // --------------------------------------------------------
    static bool bFirstTime = true;
    // --------------------------------------------------------
    if (bFirstTime)
    {
        bFirstTime = false;
        // TODO: Add ability to customize locale here, if necessary.
        const std::moneypunct<char, false> &mp = std::use_facet< std::moneypunct<char, false> >(std::locale ()); // <=====
        strSeparator.   Format("%c", ('\0' == mp.thousands_sep ()) ? ',' : mp.thousands_sep ());
        strDecimalPoint.Format("%c", ('\0' == mp.decimal_point ()) ? '.' : mp.decimal_point ());
    }
    // --------------------------------------------------------
    str_output = OTAssetContract::formatLongAmount(lValue, nFactor, nPower, m_strCurrencySymbol.Get(),
                                                   strSeparator.Get(), strDecimalPoint.Get());
    return true;
}

// ----------------------------------------------------------------------------

bool OTAssetContract::ParseFormatted(OTAmount & theOutput, const std::string str_input) const // Convert $5.45 to amount 545.
{
    // TODO! Rules:
    
    // End at newline

    // Skip any other spaces.
    
    // Skip currency symbol. (Any other symbol == error.)
    
    // ...Except separator and decimal (, and .) which are allowed and interpreted.
    
    // If there is no decimal point, then it's assumed to have been at the end of the number.
    // For example, input "5" would be interpreted the same as "5.00" which would be
    // stored as 500. The decimal point is assumed, if not found.
    
    return false;
}

// ----------------------------------------------------------------------------

// NOTE: the use of "dollars" and "cents" here is only metaphoric.
// For example, if the currency type was Bitcoin, then "dollars" are actually BTC,
// and "cents" are actually satoshis.

// Given input of 545, GetDollarsOnly returns 5
//
int64_t OTAssetContract::GetDollarsOnly(const OTAmount & theInput) const
{
    return 0; // TODO
}

// ----------------------------------------------------------------------------

// Given input of 545, GetCentsOnly returns 45.

int64_t OTAssetContract::CentsOnly(const OTAmount & theInput) const
{
    return 0; // TODO
}


// ----------------------------------------------------------------------------



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
	return false;
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
    OTDB::Storable * pStorable = OTDB::QueryObject(OTDB::STORED_OBJ_STRING_MAP, OTFolders::Contract().Get(), strAcctRecordFile.Get());
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
    if (OTDB::Exists(OTFolders::Contract().Get(), strAcctRecordFile.Get())) // the file already exists; let's try to load it up.
        pStorable = OTDB::QueryObject(OTDB::STORED_OBJ_STRING_MAP, OTFolders::Contract().Get(), strAcctRecordFile.Get());
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
    if (false == OTDB::StoreObject(*pMap, OTFolders::Contract().Get(), strAcctRecordFile.Get()))
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
    if (OTDB::Exists(OTFolders::Contract().Get(), strAcctRecordFile.Get())) // the file already exists; let's try to load it up.
        pStorable = OTDB::QueryObject(OTDB::STORED_OBJ_STRING_MAP, OTFolders::Contract().Get(), strAcctRecordFile.Get());
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
    if (false == OTDB::StoreObject(*pMap, OTFolders::Contract().Get(), strAcctRecordFile.Get()))
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


// Normally, Asset Contracts do NOT update / rewrite their contents, since their
// primary goal is for the signature to continue to verify.  But when first creating
// a basket contract, we have to rewrite the contents, which is done here.
bool OTAssetContract::CreateBasket(OTBasket & theBasket, OTPseudonym & theSigner)
{
	Release();

	// Grab a string copy of the basket information.
	theBasket.SaveContractRaw(m_strBasketInfo);
	// -------------------------------
    OTString     strTemplate;
    OTASCIIArmor theBasketArmor(m_strBasketInfo);
    // -------------------------------
    m_xmlUnsigned.Concatenate("<?xml version=\"%s\"?>\n", "1.0");
    
    strTemplate.Concatenate("<basketContract version=\"%s\">\n\n", m_strVersion.Get());
    strTemplate.Concatenate("<basketInfo>\n%s</basketInfo>\n\n", theBasketArmor.Get());

    strTemplate.Concatenate("</%s>\n", "basketContract");
    // -------------------------------    
	return this->CreateContract(strTemplate, theSigner);
}


void OTAssetContract::CreateContents()
{
    // ----------------------------------
    m_strVersion = "2.0";  // 2.0 since adding credentials.
    // ----------------------------------
 	m_xmlUnsigned.Release();
    m_xmlUnsigned.Concatenate("<?xml version=\"%s\"?>\n", "1.0");
    // ----------------------------------
    if (m_strBasketInfo.Exists()) // Basket contract
    {
        OTASCIIArmor theBasketArmor(m_strBasketInfo);
        // -------------------------------
        m_xmlUnsigned.Concatenate("<basketContract version=\"%s\">\n\n", m_strVersion.Get());
        m_xmlUnsigned.Concatenate("<basketInfo>\n%s</basketInfo>\n\n", theBasketArmor.Get());
    }
    // ----------------------------------
    else // All other asset contracts.
    {
        // ----------------------------------
        m_xmlUnsigned.Concatenate("<%s version=\"%s\">\n\n", "digitalAssetContract", m_strVersion.Get());
        // --------------------------------------------
        // Entity
        m_xmlUnsigned.Concatenate("<entity shortname=\"%s\"\n"
                                  " longname=\"%s\"\n"
                                  " email=\"%s\"/>\n\n",
                                  m_strEntityShortName.Get(),
                                  m_strEntityLongName .Get(),
                                  m_strEntityEmail    .Get());    
        // --------------------------------------------
        // Issue
        m_xmlUnsigned.Concatenate("<issue company=\"%s\"\n"
                                  " email=\"%s\"\n"
                                  " contractUrl=\"%s\"\n"
                                  " type=\"%s\"/>\n\n",
                                  m_strIssueCompany    .Get(),
                                  m_strIssueEmail      .Get(),
                                  m_strIssueContractURL.Get(),
                                  m_strIssueType       .Get());
        // --------------------------------------------
        // [currency|shares]
        if (m_bIsCurrency)
            m_xmlUnsigned.Concatenate("<currency name=\"%s\" tla=\"%s\" symbol=\"%s\" type=\"%s\" "
                                      "factor=\"%s\" decimal_power=\"%s\" fraction=\"%s\" />\n\n",
                                      m_strCurrencyName        .Get(),
                                      m_strCurrencyTLA         .Get(),
                                      m_strCurrencySymbol      .Get(),
                                      m_strCurrencyType        .Get(),
                                      m_strCurrencyFactor      .Get(),
                                      m_strCurrencyDecimalPower.Get(),
                                      m_strCurrencyFraction    .Get());
        else if (m_bIsShares)
            m_xmlUnsigned.Concatenate("<shares name=\"%s\" symbol=\"%s\" type=\"%s\" issuedate=\"%s\" />\n\n",
                                      m_strCurrencyName  .Get(),
                                      m_strCurrencySymbol.Get(),
                                      m_strCurrencyType  .Get(),
                                      m_strIssueDate     .Get());
    }
    // --------------------------------------------
    // This is where OTContract scribes m_xmlUnsigned with its keys, conditions, etc.
    this->CreateInnerContents();    
    // --------------------------------------------
	m_xmlUnsigned.Concatenate("</%s>\n", m_strBasketInfo.Exists() ? "basketContract" : "digitalAssetContract");
    // --------------------------------------------   
}

// ----------------------------------------------------------------

// return -1 if error, 0 if nothing, and 1 if the node was processed.
//
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
		nReturnVal = 1;
	}	
	else if (strNodeName.Compare("issue"))
	{
		m_strIssueCompany     = xml->getAttributeValue("company");
		m_strIssueEmail       = xml->getAttributeValue("email");
		m_strIssueContractURL = xml->getAttributeValue("contractUrl");
		m_strIssueType        = xml->getAttributeValue("type");
		
		OTLog::vOutput(2, "Loaded Issue company: %s\nEmail: %s\nContractURL: %s\nType: %s\n----------\n",
				m_strIssueCompany.Get(), m_strIssueEmail.Get(), m_strIssueContractURL.Get(),
				m_strIssueType.Get());
		nReturnVal = 1;
	}
    // TODO security validation: validate all the above and below values.
	else if (strNodeName.Compare("currency") )    
	{
        m_bIsCurrency             = true;  // silver grams
        m_bIsShares               = false;        

		m_strName                 = xml->getAttributeValue("name");
		m_strCurrencyName         = xml->getAttributeValue("name");
		m_strCurrencySymbol       = xml->getAttributeValue("symbol");
		m_strCurrencyType         = xml->getAttributeValue("type");

		m_strCurrencyTLA          = xml->getAttributeValue("tla");
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
	
//  share_type some type, for example, A or B, or NV (non voting)
//        
//  share_name this is the long legal name of the company
//        
//  share_symbol this is the trading name (8 chars max), as it might be 
//      displayed in a market contect, and should be unique within some given market
//        
//  share_issue_date date of start of this share item (not necessarily IPO)

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














































