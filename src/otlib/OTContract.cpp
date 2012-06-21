/*************************************************************
 *    
 *  OTContract.cpp
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

#ifdef _WIN32
#include <WinsockWrapper.h>
#endif

extern "C"
{
#include <openssl/pem.h>	
#include <openssl/err.h>
#include <openssl/evp.h>
#include <openssl/rsa.h>
#include <openssl/rand.h>
}

#include <cstdio>	
#include <cstring>

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "irrxml/irrXML.h"

using namespace irr;
using namespace io;

#include "OTData.h"
#include "OTString.h"
#include "OTIdentifier.h"

#include "OTStringXML.h"


#include "OTStorage.h"

#include "OTPseudonym.h"
#include "OTContract.h"
#include "OTLog.h"

#include "OTAgreement.h"
#include "OTPaymentPlan.h"
#include "OTSmartContract.h"
#include "OTTrade.h"
#include "OTOffer.h"
#include "OTAccount.h"
#include "OTCheque.h"
#include "OTMessage.h"
#include "OTLedger.h"
#include "OTTransaction.h"
#include "OTItem.h"
#include "OTMint.h"
#include "OTPurse.h"
#include "OTSignedFile.h"
#include "OTToken.h"
#include "OTServerContract.h"
#include "OTAssetContract.h"





// Factory (though rarely used; was just added recently for the API.)
//
// If you want to instantiate a contract that you already have in string form,
// this function will figure out what kind of contract it is, and instantiate the
// right subclass, then load it up and return it.
//
// CALLER IS RESPONSIBLE to cleanup!
//
OTContract * OTContract::InstantiateContract(OTString strInput)
{
	static char	buf[45] = "";
	
	if (!strInput.Exists())
		return NULL;

    // --------------------------------------------------------------------
	//
    // To support legacy data, we check here to see if it's armored or not.
    // If it's not, we support it. But if it IS, we ALSO support it (we de-armor it here.)
    //
    bool bArmoredAndALSOescaped = false;    // "- -----BEGIN OT ARMORED"
    bool bArmoredButNOTescaped  = false;    // "-----BEGIN OT ARMORED"
    
    if (strInput.Contains(OT_BEGIN_ARMORED_escaped)) // check this one first...
    {
        bArmoredAndALSOescaped = true;
        
        OTLog::Error("OTContract::InstantiateContract: Armored and escaped value passed in, but escaped are forbidden here. (Returning NULL.)\n");
		return NULL;
    }
    else if (strInput.Contains(OT_BEGIN_ARMORED))
    {
        bArmoredButNOTescaped = true;
    }
    // ----------------------------------------
    const bool bArmored = (bArmoredAndALSOescaped || bArmoredButNOTescaped);
    // ----------------------------------------
    
    // Whether the string is armored or not, (-----BEGIN OT ARMORED)
    // either way, we'll end up with the decoded version in this variable:
    //
    std::string str_Trim;
    
    // ------------------------------------------------
    if (bArmored) // it's armored, we have to decode it first.
    {
        OTASCIIArmor ascTemp;
        
        if (false == (ascTemp.LoadFromString(strInput, 
                                             bArmoredAndALSOescaped, // if it IS escaped or not, this variable will be true or false to show it.
                                             // The below szOverride sub-string determines where the content starts, when loading.
                                             OT_BEGIN_ARMORED)))     // Default is:       "-----BEGIN" 
                                                                     // We're doing this: "-----BEGIN OT ARMORED" (Should worked for escaped as well, here.)
        {
            OTLog::vError("OTContract::InstantiateContract: Error loading string contents from ascii-armored encoding. Contents: \n%s\n", 
                          strInput.Get());
            return NULL;
        }
        else // success loading the actual contents out of the ascii-armored version.
        {
            OTString strTemp(ascTemp); // <=== ascii-decoded here.
            
            std::string str_temp(strTemp.Get(), strTemp.GetLength());
            str_Trim = OTString::trim(str_temp); // This is the std::string for the trim process.
        } 
    }
    else
    {
        std::string str_temp(strInput.Get(), strInput.GetLength());

        str_Trim = OTString::trim(str_temp); // This is the std::string for the trim process. (Wasn't armored, so here we use it as passed in.)
    }
    // ------------------------------------------------
    
    // At this point, str_Trim contains the actual contents, whether they
    // were originally ascii-armored OR NOT. (And they are also now trimmed, either way.)
    // ------------------------------------------
    
    OTString strContract(str_Trim);
    
	buf[0] = 0; // probably unnecessary.
	strContract.reset(); // for sgets
	bool bGotLine = strContract.sgets(buf, 40);
	
	if (!bGotLine)
		return NULL;
	
	OTString strFirstLine(buf);
	strContract.reset(); // set the "file" pointer within this string back to index 0.
	
	// Now I feel pretty safe -- the string I'm examining is within
	// the first 45 characters of the beginning of the contract, and
	// it will NOT contain the escape "- " sequence. From there, if
	// it contains the proper sequence, I will instantiate that type.
	if (!strFirstLine.Exists() || strFirstLine.Contains("- -"))
		return NULL;
	
	// -----------------------------------------------------------
	
	OTContract * pContract = NULL;
	
//	if (strFirstLine.Contains("-----BEGIN SIGNED AGREEMENT-----"))  // this string is 32 chars long.
//	{	pContract = new OTAgreement();		OT_ASSERT(NULL != pContract); }
	
	if (strFirstLine.Contains("-----BEGIN SIGNED SMART CONTRACT-----"))  // this string is 37 chars long.
	{	pContract = new OTSmartContract();	OT_ASSERT(NULL != pContract); }
	
	if (strFirstLine.Contains("-----BEGIN SIGNED PAYMENT PLAN-----"))  // this string is 35 chars long.
	{	pContract = new OTPaymentPlan();	OT_ASSERT(NULL != pContract); }
	
	else if (strFirstLine.Contains("-----BEGIN SIGNED TRADE-----"))  // this string is 28 chars long.
	{	pContract = new OTTrade();			OT_ASSERT(NULL != pContract); }
	
	else if (strFirstLine.Contains("-----BEGIN SIGNED OFFER-----")) 
	{	pContract = new OTOffer();			OT_ASSERT(NULL != pContract); }
	
	else if (strFirstLine.Contains("-----BEGIN SIGNED INVOICE-----")) 
	{	pContract = new OTCheque();			OT_ASSERT(NULL != pContract); }
	
	else if (strFirstLine.Contains("-----BEGIN SIGNED VOUCHER-----")) 
	{	pContract = new OTCheque();			OT_ASSERT(NULL != pContract); }
	
	else if (strFirstLine.Contains("-----BEGIN SIGNED CHEQUE-----")) 
	{	pContract = new OTCheque();			OT_ASSERT(NULL != pContract); }
	
	else if (strFirstLine.Contains("-----BEGIN SIGNED MESSAGE-----")) 
	{	pContract = new OTMessage();		OT_ASSERT(NULL != pContract); }
	
	else if (strFirstLine.Contains("-----BEGIN SIGNED MINT-----")) 
	{	pContract = new OTMint();			OT_ASSERT(NULL != pContract); }
	
	else if (strFirstLine.Contains("-----BEGIN SIGNED FILE-----")) 
	{	pContract = new OTSignedFile();		OT_ASSERT(NULL != pContract); }
	
	else if (strFirstLine.Contains("-----BEGIN SIGNED CASH-----")) 
	{	pContract = new OTToken();			OT_ASSERT(NULL != pContract); }

	
	// The Purse object requires the asset type ID in order to be instantiated.
	// I may remove this requirement (if possible) or not.
//	
//	else if (strFirstLine.Contains("-----BEGIN SIGNED PURSE-----")) 
//	{	pContract = new OTPurse();			OT_ASSERT(NULL != pContract); }
	
	
	// THESE OBJECTS REQUIRE YOU TO KNOW THE SERVER ID, USER ID, AND ACCT ID,
	// IN ORDER TO GENERATE A NEW INSTANCE, OR TO LOAD AN EXISTING ONE.
	// THUS, I AM REMOVING THEM FROM HERE FOR NOW.
	// DONE: ADD A OTTransactionType class factory (like I did for CronItem)
	// and then create these in there instead.
	//
//	else if (strFirstLine.Contains("-----BEGIN SIGNED ACCOUNT-----")) 
//	{	pContract = new OTAccount();		OT_ASSERT(NULL != pContract); }	
//	else if (strFirstLine.Contains("-----BEGIN SIGNED LEDGER-----")) 
//	{	pContract = new OTLedger();			OT_ASSERT(NULL != pContract); }
//	
//	else if (strFirstLine.Contains("-----BEGIN SIGNED TRANSACTION-----")) 
//	{	pContract = new OTTransaction();	OT_ASSERT(NULL != pContract); }
//	
//	else if (strFirstLine.Contains("-----BEGIN SIGNED TRANSACTION ITEM-----")) 
//	{	pContract = new OTItem();			OT_ASSERT(NULL != pContract); }
//	

	
	// TODO: Might want to clarify in Asset and Server Contracts,
	// so I don't have to do this crap... The ones above are cleaner.
	//
	else if (strFirstLine.Contains("-----BEGIN SIGNED CONTRACT-----"))
	{
		if (strContract.Contains("<notaryProviderContract version=\"1.0\">")) 
		{	pContract = new OTServerContract();		OT_ASSERT(NULL != pContract); }
		else if (strContract.Contains("<digitalAssetContract version=\"1.0\">")) 
		{	pContract = new OTAssetContract();		OT_ASSERT(NULL != pContract); }
	}
	
	// ----------------------------------------------
	
	// The string didn't match any of the options in the factory.
	if (NULL == pContract)
		OTLog::vOutput(0, "OTContract::InstantiateContract: Object type not yet supported by class factory: %s\n",
                       strFirstLine.Get());
	// Does the contract successfully load from the string passed in?
	else if (false == pContract->LoadContractFromString(strContract))
	{
		OTLog::vOutput(0, "OTContract::InstantiateContract: Failed loading contract from string (first line): %s\n", 
                       strFirstLine.Get());
		delete pContract;
		pContract = NULL;
	}
	else
		return pContract;
	
	return NULL;	
}







// ----------------------------------------------------------------------------------------
//
// OTNumList (helper class.)
//

//    std::set<long>  m_setData;

OTNumList::OTNumList(const std::set<long> & theNumbers)
{
    Add(theNumbers);
}
// -------------------

// removed, security reasons.
//OTNumList::OTNumList(const char * szNumbers)
//{
//    Add(szNumbers);
//}
// -------------------


OTNumList::OTNumList(const OTString & strNumbers)
{
    Add(strNumbers);
}

// -------------------

OTNumList::OTNumList()
{
    
}

// -------------------
OTNumList::~OTNumList()
{
    
}

// -------------------

bool OTNumList::Add(const OTString & strNumbers)  // if false, means the numbers were already there. (At least one of them.)
{
    return Add(strNumbers.Get());
}

// -------------------
// This function is private, so you can't use it without passing an OTString.
// (For security reasons.) It takes a comma-separated list of numbers, and adds
// them to *this.
//
bool OTNumList::Add(const char * szNumbers)       // if false, means the numbers were already there. (At least one of them.)
{
    OT_ASSERT(NULL != szNumbers); // Should never happen.
    
    bool    bSuccess    = true;
    long    lNum        = 0;
    const 
    char *  pChar       = szNumbers;
    
    // Skip any whitespace.
    while(std::isspace(*pChar))
        pChar++;
    
    // -------------------------------------
    
    while (1) // We already know it's not null, due to the assert. (So at least one iteration will happen.)
    {
        if (std::isdigit(*pChar))
        {
            int nDigit = (*pChar - '0');
            
            lNum *= 10;  // Move it up a decimal place.
            lNum += nDigit;
        }
        // if separator, or end of string, either way, add lNum to *this. 
        else if ((',' == *pChar) || ('\0' == *pChar) || std::isspace(*pChar)) // first sign of a space, and we are done with current number. (On to the next.)
        {
            if ((lNum > 0) && (false == this->Add(lNum))) // <=========
                bSuccess = false; // We still go ahead and try to add them all, and then return this sort of status when it's all done.
            // ------------------
            lNum = 0;   // reset for the next transaction number (in the comma-separated list.)
        }
        else
            OTLog::vError("OTNumList::Add: Error: Unexpected character found in erstwhile comma-separated list of longs: %c\n",
                          *pChar);
        // ---------------------------------
        // End of the road.
        if ('\0' == *pChar)
            break;
        // -----------
        pChar++;
        // -----------
        // Skip any whitespace.
        while(std::isspace(*pChar))
            pChar++;
        // -------------------------------------
    } // while
    
    return bSuccess;
}
// -------------------

bool OTNumList::Add(const long & theValue)    // if false, means the value was already there.
{
    std::set<long>::iterator it = m_setData.find(theValue);
    
    if (m_setData.end() == it) // it's not already there, so add it.
    {
        m_setData.insert(theValue);
        return true;
    }
    return false; // it was already there.
}
// -------------------


bool OTNumList::Remove(const long & theValue) // if false, means the value was NOT already there.
{
    std::set<long>::iterator it = m_setData.find(theValue);
    
    if (m_setData.end() != it) // it's there.
    {
        m_setData.erase(it);
        return true;
    }
    return false; // it wasn't there (so how could you remove it then?)
}
// -------------------

bool OTNumList::Verify(const long & theValue) const // returns true/false (whether value is already there.)
{
    std::set<long>::iterator it = m_setData.find(theValue);
    
    return (m_setData.end() == it) ? false : true;
}

// -------------------

bool OTNumList::Add(const OTNumList & theNumList)    // if false, means the numbers were already there. (At least one of them.)
{
    std::set<long> theOutput;
    theNumList.Output(theOutput); // returns false if the numlist was empty.
    
    return this->Add(theOutput);
}
// -------------------

bool OTNumList::Add(const std::set<long> & theNumbers)    // if false, means the numbers were already there. (At least one of them.)
{
    bool bSuccess = true;
    
    FOR_EACH_CONST(std::set<long>, theNumbers)
    {
        const long lValue = *it;
        
        if (!this->Add(lValue)) // It must have already been there.
            bSuccess = false;
    }
    
    return bSuccess;
}
// -------------------

bool OTNumList::Remove(const std::set<long> & theNumbers) // if false, means the numbers were NOT already there. (At least one of them.)
{
    bool bSuccess = true;
    
    FOR_EACH_CONST(std::set<long>, theNumbers)
    {
        const long lValue = *it;
        
        if (!this->Remove(lValue)) // It must have NOT already been there.
            bSuccess = false;
    }
    
    return bSuccess;
}
// -------------------

bool OTNumList::Verify(const std::set<long> & theNumbers) const // True/False, based on whether values are already there. (ALL must be present.)
{
    bool bSuccess = true;
    
    FOR_EACH_CONST(std::set<long>, theNumbers)
    {
        const long lValue = *it;
        
        if (!this->Verify(lValue)) // It must have NOT already been there.
            bSuccess = false;
    }
    
    return bSuccess;
}
// -------------------

// Outputs the numlist as a set of numbers.
// (To iterate OTNumList, call this, then iterate the output.)
//
bool OTNumList::Output(std::set<long> & theOutput) const // returns false if the numlist was empty.
{
    theOutput = m_setData;
    
    return (m_setData.size() > 0) ? true : false;
}
// -------------------

// Outputs the numlist as a comma-separated string (for serialization, usually.)
//
bool OTNumList::Output(OTString & strOutput) const // returns false if the numlist was empty.
{
    int nIterationCount = 0;
    
    FOR_EACH(std::set<long>, m_setData)
    {
        const long lValue = *it;
        nIterationCount ++;
        // ----------
        
        strOutput.Concatenate("%s%ld",
                              // If first iteration, prepend a blank string (instead of a comma.)
                              // Like this:  "%ld"
                              // But for all subsequent iterations, concatenate: ",%ld"
                              (1 == nIterationCount) ? "" : ",", lValue);
    }
    
    return (m_setData.size() > 0) ? true : false;
}

// -------------------


// True/False, based on whether OTNumLists MATCH in COUNT and CONTENT (NOT ORDER.)
//
bool OTNumList::Verify(const OTNumList & rhs) const
{
    // Verify they have the same number of elements.
    //
    if (this->Count() != rhs.Count())
        return false;
    // -------------------
    
    // Verify each value on *this is also found on rhs.
    //
    FOR_EACH(std::set<long>, m_setData)
    {
        const long lValue = *it;
        // ----------
        if (false == rhs.Verify(lValue))
            return false;
    }
    
    return true;
}


int OTNumList::Count() const 
{ 
    return m_setData.size(); 
}

// -------------------

void OTNumList::Release() 
{ 
    m_setData.clear(); 
}

// -----------------------------------------------------------------------------



OTContract::OTContract()
{
	Initialize();
}

OTContract::OTContract(const OTString & name, const OTString & foldername, const OTString & filename, const OTString & strID)
{
	Initialize();
	
	m_strName			= name;
	m_strFoldername		= foldername;
	m_strFilename		= filename;
	
	m_ID.SetString(strID);
}



OTContract::OTContract(const OTString & strID)
{
	Initialize();
	
	m_ID.SetString(strID);
}

OTContract::OTContract(const OTIdentifier & theID)
{
	Initialize();
	
	m_ID = theID;
}

void OTContract::Initialize()
{
	m_strContractType	= "CONTRACT";	// CONTRACT, MESSAGE, TRANSACTION, LEDGER, TRANSACTION ITEM 
	// make sure subclasses set this in their own initialization routine.
	
	m_strSigHashType	= OTIdentifier::DefaultHashAlgorithm;
	m_strVersion		= "1.0";
}


// The name, filename, version, and ID loaded by the wallet
// are NOT released here, since they are used immediately after
// the Release() call in LoadContract(). Really I just want to
// "Release" the stuff that is about to be loaded, not the stuff
// that I need to load it!
void OTContract::Release_Contract()
{
	// !! Notice I don't release the m_strFilename here!!
	// Because in LoadContract, we want to release all the members, and then load up from the file.
	// So if I release the filename, now I can't load up from the file cause I just blanked it. DUh.
	//
	// m_strFilename.Release();
	
	m_strSigHashType = OTIdentifier::DefaultHashAlgorithm;
	m_xmlUnsigned.Release();
	m_strRawFile.Release();
	
	ReleaseSignatures();
	
	// Go through the existing list of nyms at this point, and delete them all.
	while (!m_mapNyms.empty())
	{		
		OTPseudonym * pNym = m_mapNyms.begin()->second;
		
		OT_ASSERT(NULL != pNym);
		
		delete pNym;
		pNym = NULL;

		m_mapNyms.erase(m_mapNyms.begin());
	}	
}

void OTContract::Release()
{	
	Release_Contract();
    
    // No call to ot_super::Release() here, since OTContract
    // is the base class.
}

OTContract::~OTContract()
{	
	
	Release_Contract();
}



	
bool OTContract::SaveToContractFolder()
{
	OTString strFoldername(OTLog::ContractFolder()), strFilename;
	
	GetIdentifier(strFilename);

	// -------------------------------------
	// These are already set in SaveContract(), called below.
//	m_strFoldername	= strFoldername;
//	m_strFilename	= strFilename;
	
	OTLog::Output(2, "OTContract::SaveToContractFolder: Saving asset contract to disk...\n");
	
	return SaveContract(strFoldername.Get(), strFilename.Get());
}





void OTContract::GetFilename(OTString & strFilename)
{
	strFilename = m_strFilename;
}

void OTContract::GetIdentifier(OTIdentifier & theIdentifier)
{
	theIdentifier = m_ID;
}

void OTContract::GetIdentifier(OTString & theIdentifier)
{
	m_ID.GetString(theIdentifier);
}

// Make sure this contract checks out. Very high level. 
// Verifies ID, existence of public key, and signature.
bool OTContract::VerifyContract()
{
	// Make sure that the supposed Contract ID that was set is actually
	// a hash of the contract file, signatures and all.
	if (false == VerifyContractID())
	{
		OTLog::Output(1, "Failed verifying contract ID in OTContract::VerifyContract\n");
		return false;
	}
	
	// Make sure we are able to read the official "contract" public key out of this contract.
	const OTPseudonym * pNym = GetContractPublicNym();

	if (NULL == pNym)
	{
		OTLog::Output(1, "Failed retrieving contract public nym from within contract, in OTContract::VerifyContract\n");
		return false;
	}
	
	if (false == VerifySignature(*pNym))
	{
		OTLog::Output(1, "Failed verifying public key from contract with signature on contract.\n");
		return false;
	}

	
	OTLog::Output(1, "\nVerified -- The Contract ID from the wallet matches the newly-calculated hash of the contract file.\n"
			"Verified -- A standard \"contract\" Public Key or x509 Cert WAS found inside the contract.\n"
			"Verified -- And the **SIGNATURE VERIFIED** with THAT key.\n\n");
	return true;
}


void OTContract::CalculateContractID(OTIdentifier & newID) const
{
//	OTLog::vError("DEBUG CalculateContractID:\n--->%s<---\n", m_strRawFile.Get());
	
//	// may be redundant...	
	std::string str_Trim(m_strRawFile.Get());
	std::string str_Trim2 = OTString::trim(str_Trim);

	OTString strTemp(str_Trim2.c_str());
	
	newID.CalculateDigest(strTemp);
}

bool OTContract::VerifyContractID()
{
	OTIdentifier newID;
	
	std::string str_Trim(m_strRawFile.Get());
	std::string str_Trim2 = OTString::trim(str_Trim);
	
	OTString strTemp(str_Trim2.c_str());
	
	if (!newID.CalculateDigest(strTemp))
	{
		OTLog::Output(1, "Error calculating Contract digest.\n");
		return false;	
	}
	
	// newID now contains the Hash aka Message Digest aka Fingerprint 
	// aka thumbprint aka "IDENTIFIER" of the Contract. 
	// 
	// Now let's compare that identifier to the one already loaded by the wallet
	// for this contract and make sure they MATCH.
	
	// I use the == operator here because there is no != operator at this time.
	// That's why you see the ! outside the parenthesis.
	if (!(m_ID == newID))
	{
		OTString str1(m_ID), str2(newID);

		OTLog::vOutput(0, "\nHashes do NOT match in OTContract::VerifyContractID.\n%s\n%s\n"
//				"\nRAW FILE:\n--->%s<---"
				"\n",
				str1.Get(), str2.Get()
//				m_strRawFile.Get()
				);
		return false;
	}
	else {
		OTString str1;
		newID.GetString(str1);
		OTLog::vOutput(1, "\nContract ID *SUCCESSFUL* match to %s hash of contract file:\n%s\n\n",
				OTIdentifier::DefaultHashAlgorithm.Get(), str1.Get());
		return true;
	}
}

		
const OTPseudonym * OTContract::GetContractPublicNym()
{
	FOR_EACH(mapOfNyms, m_mapNyms)
	{		
		OTPseudonym * pNym = (*it).second;
		OT_ASSERT_MSG(NULL != pNym, "NULL pseudonym pointer in OTContract::GetContractPublicNym.\n");
		
		if ((*it).first == "contract") // TODO have a place for hardcoded values like this.
		{							   // We're saying here that every contract has to have a key tag called "contract"
									   // where the official public key can be found for it and for any contract.
			return pNym;
		}
	}
	
	return NULL;	
}


// If there is a public key I can find for this contract, then
// I will return it here -- or NULL.
const OTAsymmetricKey * OTContract::GetContractPublicKey()
{
	FOR_EACH(mapOfNyms, m_mapNyms)
	{		
		OTPseudonym	* pNym = (*it).second;
		OT_ASSERT_MSG(NULL != pNym, "NULL pseudonym pointer in OTContract::GetContractPublicKey.\n");
		
		if ((*it).first == "contract") // TODO have a place for hardcoded values like this.
		{							   // We're saying here that every contract has a key tag called "contract"
									   // where the official public key can be found for it and for any contract.
			OTAsymmetricKey * pKey = (OTAsymmetricKey *) &(pNym->GetPublicKey()); //todo fix this cast.
			return const_cast<OTAsymmetricKey *>(pKey);
		}
	}
	
	return NULL;
}




/*
int main() 
{ 
	verify("gserver.cer", "gserver.pem"); 
} 
int verify (char *certfile, char * keyfile) 
{ 
	struct stat tStat; 
	int err; 
	int sig_len; 
	unsigned char sig_buf [4096]; 
	static char data[] = "I owe you..."; 
	
	EVP_MD_CTX md_ctx; 
	EVP_PKEY * pkey = NULL; 
	FILE * fp; 
	X509 *	x509 = NULL; 
	
	printf ("verifyCert_N_Key: Certificate File %s\n", certfile); 
	printf ("verifyCert_N_Key: Key File %s\n", keyfile); 
	
	// Just load the crypto library error strings, 
	//SSL_load_error_strings() loads the crypto AND the SSL ones
	// SSL_load_error_strings();
	ERR_load_crypto_strings(); 
	
	// Read private key 
	fp = fopen (keyfile, "r"); if (fp == NULL) exit (1); 
    pkey = PEM_read_PrivateKey(fp, NULL, OTAsymmetricKey::GetPasswordCallback(), NULL); 
	
	fclose (fp); 
	
	if (pkey == NULL) 
	{ 
		return (-1); 
	} 
	
	// Do the signature
	EVP_SignInit (&md_ctx, EVP_md5()); 
	EVP_SignUpdate (&md_ctx, data, strlen(data));
	
	sig_len = sizeof(sig_buf); 
	err = EVP_SignFinal (&md_ctx, sig_buf, (unsigned int *)&sig_len, 
						 pkey); 
	
	if (err != 1) { 
		return (-1); 
	} 
	
	EVP_PKEY_free (pkey); 
	
	// Read public key
	printf ("Reading public key\n"); 
	fp = fopen (certfile, "r"); 
	
	if (fp == NULL) 
	{ 
		exit (1); 
	} 
	
	x509 = PEM_read_X509(fp, NULL, OTAsymmetricKey::GetPasswordCallback(), NULL); 
	fclose (fp); 
	
	if (x509 == NULL) 
	{ 
		return (-1); 
	} 
	
	fclose (fp); 
	
	// Get public key - eay
	printf ("Get public key\n"); 
	pkey=X509_get_pubkey(x509); 
	
	if (pkey == NULL) 
	{ 
		return (-1); 
	} 
	
	printf ("After public key\n"); 
	
	// Verify the signature
	
	EVP_VerifyInit (&md_ctx, EVP_md5()); 
	
	EVP_VerifyUpdate (&md_ctx, data, strlen((char*)data)); 
	
	err = EVP_VerifyFinal (&md_ctx, sig_buf, sig_len, pkey); 
	EVP_PKEY_free (pkey); 
	
	if (err != 1) 
	{ 
		return (-1); 
	} 
	return 1; 
} 
*/

void OTContract::UpdateContents()
{
	// Deliberately left blank.
	//
	// Some child classes may need to perform work here
	// (OTAccount and OTMessage, for example.)
	//
	// This function is called just prior to the signing of a contract.
}


// This is the one that you will most likely want to call.
// It actually attaches the resulting signature to this contract.
// If you want the signature to remain on the contract and be handled
// internally, then this is what you should call.
bool OTContract::SignContract(const OTPseudonym & theNym)
{
	bool bSigned = false;
	OTSignature * pSig = NULL;

    const char * szFunc = "OTContract::SignContract";
    
	OT_ASSERT_MSG(pSig = new OTSignature(), "OTContract::SignContract: Error allocating memory for Signature.\n");
	
	bSigned = this->SignContract(theNym, *pSig);

	if (bSigned)
		m_listSignatures.push_back(pSig);
	else 
	{
        OTLog::vError("%s: Failure in this->SignContract(theNym, *pSig).\n", szFunc);
		delete pSig;
		pSig = NULL;
	}
	
	return bSigned;
}

// The output signature will be in theSignature.
// It is NOT attached to the contract.  This is just a utility function.
bool OTContract::SignContract(const OTPseudonym & theNym, OTSignature & theSignature)
{
	return SignContract(theNym.GetPrivateKey(), theSignature, m_strSigHashType);
}

// The output signature will be in theSignature.
// It is NOT attached to the contract.  This is just a utility function.
bool OTContract::SignContract(const OTAsymmetricKey & theKey, OTSignature & theSignature, const OTString & strHashType)
{
	return SignContract((const_cast<OTAsymmetricKey &>(theKey)).GetKey(), theSignature, strHashType);
}




// The default hashing algorithm in this software should be one that XOR combines two other,
// established and respected algorithms. In this case, we use the "SAMY" hash which is actually
// SHA512 XOR'd with WHIRLPOOL (also 512 in output). Credit to SAMY for the idea.
//
// This way if one is ever cracked, our system is still strong, and we can swap it out.
// Thus, I had to write this special function so that if the Default hash algorithm is the one
// chosen, ("SAMY") then we have to hash it twice using Hash1 (SHA512) and Hash2 (Whirlpool)
// before we encrypt it with the private key.
// 
// Since the envelope (EVP) interface did not allow this, I had to Google everywhere to find
// lower-level code I could model.

/*
 128 bytes * 8 bits == 1024 bits key.  (RSA)
 
 64 bytes * 8 bits == 512 bits key (for WHIRLPOOL and SHA-512 message digests.)
 
 BUT--now I want to allow various key sizes (above 1024...)
 and I also have a smaller message digest now: 256 bits.
 
 */
// TODO: make the default sizes configurable.

// 512 bytes == 4096 bits
#define OT_MAX_PUBLIC_KEYSIZE 512
// 128 bytes == 1024 bits
#define OT_DEFAULT_PUBLIC_KEYSIZE 128

// 64 bytes == 512 bits
#define OT_MAX_SYMMETRIC_KEYSIZE 64
// 64 bytes == 512 bits. 
// 32 bytes == 256 bits
#define OT_DEFAULT_SIZE_DIGEST1 32
#define OT_DEFAULT_SIZE_DIGEST2 64


bool OTContract::SignContractDefaultHash(const EVP_PKEY * pkey, OTSignature & theSignature)
{
    const char * szFunc = "OTContract::SignContractDefaultHash";
    // -------------------------------
	bool bReturnValue = false;
	
	RSA* pRsaKey = NULL;
	
	unsigned char	pOutputHash1[OT_MAX_SYMMETRIC_KEYSIZE];	// These two contain the output of the two message digest
	unsigned char	pOutputHash2[OT_MAX_SYMMETRIC_KEYSIZE];	// functions that we're using (SHA-256 and WHIRLPOOL.)
	unsigned char	pDigest		[OT_MAX_SYMMETRIC_KEYSIZE]; // the two output hashes are then merged together into this one.
	
	unsigned char	EM			[OT_MAX_PUBLIC_KEYSIZE];	// This stores the message digest, pre-encrypted, but with the padding added.
	unsigned char	pSignature	[OT_MAX_PUBLIC_KEYSIZE];	// This stores the final signature, when the EM value has been signed by RSA private key.
	
	unsigned int	uDigest1Len = OT_DEFAULT_SIZE_DIGEST1; // 32 bytes == 256 bits. (These are used for function output below, not input.)
	unsigned int	uDigest2Len = OT_DEFAULT_SIZE_DIGEST2; // 64 bytes == 512 bits. (These are used for function output below, not input.)
	
	EVP_MD_CTX mdHash1_ctx, mdHash2_ctx;
	
	memset(pOutputHash1,	0, OT_MAX_SYMMETRIC_KEYSIZE);
	memset(pOutputHash2,	0, OT_MAX_SYMMETRIC_KEYSIZE);
	memset(pDigest,			0, OT_MAX_SYMMETRIC_KEYSIZE);
	
	memset(EM,				0, OT_MAX_PUBLIC_KEYSIZE);
	memset(pSignature,		0, OT_MAX_PUBLIC_KEYSIZE);
	
	// Here, we convert the EVP_PKEY that was passed in, to an RSA key for signing.
	pRsaKey = EVP_PKEY_get1_RSA(const_cast< EVP_PKEY* > (pkey));
	
	if (!pRsaKey)
	{
		OTLog::vError("%s: EVP_PKEY_get1_RSA failed with error %s\n", szFunc,
					  ERR_error_string(ERR_get_error(), NULL));
		return false;
	}
	
	// Since the idea of this special code is that we're using 2 hash algorithms,
	// let's look them up and see what they are.
	// addendum: unless we're on Android... then there's only 1 hash algorithm.
	
	const EVP_MD * digest1 = OTIdentifier::GetOpenSSLDigestByName(OTIdentifier::HashAlgorithm1); // SHA-256
	
	if (NULL == digest1)
	{
		OTLog::vError("%s: Failure to load message digest algorithm in OTContract::SignContractDefaultHash\n", szFunc);
		RSA_free(pRsaKey);	pRsaKey = NULL;
		return false;
	}

	// hash the contents of the contract with HashAlgorithm1 (SHA-256)
	EVP_MD_CTX_init   (&mdHash1_ctx);
	EVP_DigestInit    (&mdHash1_ctx, digest1); // digest1 is the actual algorithm
	EVP_DigestUpdate  (&mdHash1_ctx, m_xmlUnsigned.Get(), m_xmlUnsigned.GetLength()); // input	
	EVP_DigestFinal   (&mdHash1_ctx, pOutputHash1, &uDigest1Len); // output and length 
	EVP_MD_CTX_cleanup(&mdHash1_ctx); // cleanup
	
	/*
	 TODO:
	 The functions EVP_DigestInit(), EVP_DigestFinal() and EVP_MD_CTX_copy() are obsolete but are retained to maintain compatibility 
	 with existing code. New applications should use EVP_DigestInit_ex(), EVP_DigestFinal_ex() and EVP_MD_CTX_copy_ex() because they 
	 can efficiently reuse a digest context instead of initializing and cleaning it up on each call and allow non default implementations 
	 of digests to be specified.
	 */
#ifndef ANDROID
	const EVP_MD * digest2 = OTIdentifier::GetOpenSSLDigestByName(OTIdentifier::HashAlgorithm2); // WHIRLPOOL (512)
	
	if (NULL == digest2)
	{
		OTLog::vError("%s: Failure to load message digest algorithm in OTContract::SignContractDefaultHash\n", szFunc);
		RSA_free(pRsaKey);	pRsaKey = NULL;
		return false;
	}
	
	// hash the same contents with HashAlgorithm2 (WHIRLPOOL)
	EVP_MD_CTX_init   (&mdHash2_ctx);
	EVP_DigestInit    (&mdHash2_ctx, digest2);	// digest2 is the algorithm
	EVP_DigestUpdate  (&mdHash2_ctx, m_xmlUnsigned.Get(), m_xmlUnsigned.GetLength()); // Input
	EVP_DigestFinal   (&mdHash2_ctx, pOutputHash2, &uDigest2Len); // output and length
	EVP_MD_CTX_cleanup(&mdHash2_ctx); // cleanup
	
	// (Goes with the smaller size.)
	const unsigned int uDigestMergedLength = (uDigest1Len > uDigest2Len ? uDigest2Len : uDigest1Len);

	// XOR the two together
	//
	for (unsigned int i = 0; i < uDigestMergedLength; i++)
	{
		pDigest[i] = ((pOutputHash1[i]) ^ (pOutputHash2[i]));
	}
#else // ANDROID
	const unsigned int uDigestMergedLength = uDigest1Len;

	for (int i = 0; i < uDigestMergedLength; i++)
	{
		pDigest[i] = (pOutputHash1[i]);
	}	
#endif // ANDROID
	
	// pDigest is now set up.
	// uDigestMergedLength contains its length in bytes.
	
	// ---------------------------------------------------------
	/*
	 NOTE:
	 RSA_sign only supports PKCS# 1 v1.5 padding which always gives the same 
	 output for the same input data. 
	 If you want to perfom a digital signature with PSS padding, you have to 
	 pad the data yourself by calling RSA_padding_add_PKCS1_PSS and then call 
	 RSA_private_encrypt on the padded output after setting its last 
	 parameter to RSA_NO_PADDING. 
	 
	 I have written a small sample code that shows how to perform PSS 
	 signature and verification. You can get the code from the following link: 
	 http://www.idrix.fr/Root/Samples/openssl_pss_signature.c
	 
	 I hope this answers your questions. 
	 Cheers, 
	 -- 
	 Mounir IDRASSI 	 
	 */
	// compute the PSS padded data
	// the result goes into EM.
	
	/*
	 int RSA_padding_add_PKCS1_PSS(RSA *rsa, unsigned char *EM,
				const unsigned char *mHash,
				const EVP_MD *Hash, int sLen);	 
	 */
//	int RSA_padding_add_xxx(unsigned char *to, int tlen,
//							unsigned char *f, int fl);
	// RSA_padding_add_xxx() encodes *fl* bytes from *f* so as to fit into *tlen* 
	// bytes and stores the result at *to*. 
	// An error occurs if fl does not meet the size requirements of the encoding method.
	// The RSA_padding_add_xxx() functions return 1 on success, 0 on error. 
	// The RSA_padding_check_xxx() functions return the length of the recovered data, -1 on error.
	
										//   rsa	EM	mHash	  Hash	  sLen
										//	  in	OUT	  IN		in		in
	int status = RSA_padding_add_PKCS1_PSS(pRsaKey, EM, pDigest, digest1, -2); //maximum salt length

	// Above, pDigest is the input, but its length is not needed, since it is determined
	// by the digest algorithm (digest1.) In this case, that size is 32 bytes == 256 bits.
	
	// Also notice that digest1 and digest2 are both processed, and then digest1 is used here
	// again, since RSA_padding_add_PKCS1_PSS requires a digest. Might be optimization opportunities there.
	// 
	// More clearly: pDigest is 256 bits long, aka 32 bytes. The call to RSA_padding_add_PKCS1_PSS above
	// is transforming its contents based on digest1, into EM. Once this is done, the new digest stored in
	// EM will be RSA_size(pRsaKey)-11 bytes in size, with the rest padded.
	// Therefore if this is sucessful, then we can call RSA_private_encrypt without any further padding,
	// since it's already accomplished here. EM itself will be RSA_size(pRsaKey) in size total (exactly.)
	
	if (!status)  // 1 or 0.
	{
		OTLog::vError("%s: RSA_padding_add_PKCS1_PSS failure: %s\n", 
					  ERR_error_string(ERR_get_error(), NULL));
		RSA_free(pRsaKey);	pRsaKey = NULL;
		return false;
	}
	
	// EM is now set up. 
	// But how big is it? Answer: RSA_size(pRsaKey)
	// No size is returned because the whole point of RSA_padding_add_PKCS1_PSS is to safely pad 
	// pDigest into EM within a specific size based on the keysize.
	
	// RSA_padding_check_xxx() verifies that the fl bytes at f contain a valid encoding for a rsa_len byte RSA key in the respective 
	// encoding method and stores the recovered data of at most tlen bytes (for RSA_NO_PADDING: of size tlen) at to.
	
	// RSA_private_encrypt
//	int RSA_private_encrypt(int flen, unsigned char *from,
//							unsigned char *to, RSA *rsa, int padding);
	// RSA_private_encrypt() signs the *flen* bytes at *from* (usually a message digest with 
	// an algorithm identifier) using the private key rsa and stores the signature in *to*.
	// to must point to RSA_size(rsa) bytes of memory.
	// RSA_private_encrypt() returns the size of the signature (i.e., RSA_size(rsa)).
	//
	status = RSA_private_encrypt(RSA_size(pRsaKey),		// input
								 EM,					// padded message digest (input)
								 pSignature,			// encrypted padded message digest (output)
								 pRsaKey,				// private key (input )
								 RSA_NO_PADDING); // why not RSA_PKCS1_PADDING ? (Custom padding above in PSS mode with two hashes.)
		
	if (status == -1)
	{
		OTLog::vError("%s: RSA_private_encrypt failure: %s\n", szFunc,
					  ERR_error_string(ERR_get_error(), NULL));
		RSA_free(pRsaKey);	pRsaKey = NULL;
		return false;
	}
	// status contains size
	
	OTData binSignature(pSignature, status); // RSA_private_encrypt actually returns the right size.
//	OTData binSignature(pSignature, 128); // stop hardcoding this block size.
	
	// theSignature that was passed in, now contains the final signature.
	// The contents were hashed twice, and the resulting hashes were
	// XOR'd together, and then padding was added, and then it was signed
	// with the private key.
	theSignature.SetData(binSignature, true); // true means, "yes, with newlines in the b64-encoded output, please."
	bReturnValue = true;
	
	// ---------------------------------------------------------
	
	if (pRsaKey)
		RSA_free(pRsaKey);
		
	pRsaKey = NULL;

	return bReturnValue;
}



// Verify a contract that has been signed with our own default algorithm (aka SAMY hash)
// Basically we had to customize for that algorithm since, by default, it XORs two different
// algorithms together (SHA256 and WHIRLPOOL) in anticipation of the day that one of them is
// broken.

bool OTContract::VerifyContractDefaultHash(const EVP_PKEY * pkey, const OTSignature & theSignature) const
{
    const char * szFunc = "OTContract::VerifyContractDefaultHash";
    // ----------------------------
	bool bReturnValue = false;
	
	RSA* pRsaKey = NULL;
	
	unsigned char	pOutputHash1[OT_MAX_SYMMETRIC_KEYSIZE];	// These two contain the output of the two message digest
	unsigned char	pOutputHash2[OT_MAX_SYMMETRIC_KEYSIZE];	// functions that we're using (SHA-256 and WHIRLPOOL.)
	unsigned char	pDigest		[OT_MAX_SYMMETRIC_KEYSIZE]; // the two output hashes are then merged together into this one.

	unsigned char	pDecrypted[OT_MAX_PUBLIC_KEYSIZE];	// Contains the decrypted signature.
	
	unsigned int	uDigest1Len = OT_DEFAULT_SIZE_DIGEST1; // 32 bytes == 256 bits. (These are used for function output below, not input.)
	unsigned int	uDigest2Len = OT_DEFAULT_SIZE_DIGEST2; // 64 bytes == 512 bits. (These are used for function output below, not input.)

	EVP_MD_CTX mdHash1_ctx, mdHash2_ctx;
	
	memset(pOutputHash1,	0, OT_MAX_SYMMETRIC_KEYSIZE);
	memset(pOutputHash2,	0, OT_MAX_SYMMETRIC_KEYSIZE);
	memset(pDigest,			0, OT_MAX_SYMMETRIC_KEYSIZE);
	
	memset(pDecrypted,		0, OT_MAX_PUBLIC_KEYSIZE);
	
	// Here, we convert the EVP_PKEY that was passed in, to an RSA key for signing.
	pRsaKey = EVP_PKEY_get1_RSA((EVP_PKEY*)pkey);
	
	if (!pRsaKey)
	{
		OTLog::vError("%s: EVP_PKEY_get1_RSA failed with error %s\n", szFunc,
                      ERR_error_string(ERR_get_error(), NULL));
		return false;
	}
	
	// Since the idea of this special code is that we're using 2 hash algorithms,
	// let's look them up and see what they are.
	const EVP_MD * digest1 = OTIdentifier::GetOpenSSLDigestByName(OTIdentifier::HashAlgorithm1); // SHA-256
	if (NULL == digest1)
	{
		OTLog::vError("%s: Failure to load message digest algorithm.\n", szFunc);
		RSA_free(pRsaKey); pRsaKey = NULL;
		return false;
	}

	// hash the contents of the contract with HashAlgorithm1 (SHA-256)
	EVP_MD_CTX_init   (&mdHash1_ctx);
	EVP_DigestInit    (&mdHash1_ctx, digest1); // digest1 is the algorithm itself
	EVP_DigestUpdate  (&mdHash1_ctx, m_xmlUnsigned.Get(), m_xmlUnsigned.GetLength()); // input	
	EVP_DigestFinal   (&mdHash1_ctx, pOutputHash1, &uDigest1Len); // output and size
	EVP_MD_CTX_cleanup(&mdHash1_ctx); // cleanup
	
#ifndef ANDROID
	const EVP_MD * digest2 = OTIdentifier::GetOpenSSLDigestByName(OTIdentifier::HashAlgorithm2); // WHIRLPOOL
	if (NULL == digest2)
	{
		OTLog::vError("%s: Failure to load message digest algorithm.\n", szFunc);
		RSA_free(pRsaKey); pRsaKey = NULL;
		return false;
	}

	// hash the same contents with HashAlgorithm2 (WHIRLPOOL)
	EVP_MD_CTX_init   (&mdHash2_ctx);
	EVP_DigestInit    (&mdHash2_ctx, digest2); // digest2 is the algorithm itself
	EVP_DigestUpdate  (&mdHash2_ctx, m_xmlUnsigned.Get(), m_xmlUnsigned.GetLength()); // Input
	EVP_DigestFinal   (&mdHash2_ctx, pOutputHash2, &uDigest2Len); // output and size
	EVP_MD_CTX_cleanup(&mdHash2_ctx); // cleanup
	
	// (Goes with the smaller size.)
	const unsigned int uDigestMergedLength = (uDigest1Len > uDigest2Len ? uDigest2Len : uDigest1Len);
		
	// XOR the two together
	for (unsigned int i = 0; i < uDigestMergedLength; i++)
	{
		pDigest[i] = ((pOutputHash1[i]) ^ (pOutputHash2[i]));
	}
#else // ANDROID
	
	// (Goes with the smaller size.)
	const unsigned int uDigestMergedLength = uDigest1Len;
		
	for (int i = 0; i < uDigest1Len; i++)
	{
		pDigest[i] = (pOutputHash1[i]);
	}	
#endif // ANDROID
		
	// Now we have the exact content in pDigest that we should also see if we decrypt
	// the signature that was passed in.
	//
	// ---------------------------------------------------------
		
	OTData binSignature;
	
	// This will cause binSignature to contain the base64 decoded binary of the 
	// signature that we're verifying. Unless the call fails of course...
	//
	if ((theSignature.GetLength() < 10) || (false == theSignature.GetData(binSignature)))
	{
		OTLog::vError("%s: Error decoding base64 data for Signature.\n", szFunc);
		RSA_free(pRsaKey); pRsaKey = NULL;
		return false;
	}
	// --------------------------------------------------------
	
	const int nSignatureSize = static_cast<int> (binSignature.GetSize()); // converting from unsigned to signed (since openssl wants it that way.)

	if ((binSignature.GetSize()	< static_cast<unsigned int>(RSA_size(pRsaKey))) || 
		(nSignatureSize			< RSA_size(pRsaKey))) // this one probably unnecessary.
	{		
		OTLog::vError("%s: Decoded base64-encoded data for signature, but resulting size was < RSA_size(pRsaKey): "
					  "Signed: %d. Unsigned: %u.\n", szFunc, nSignatureSize, binSignature.GetSize());
		RSA_free(pRsaKey); pRsaKey = NULL;
		return false;
	}
	
	// now we will verify the signature 
	// Start by a RAW decrypt of the signature
	// output goes to pDecrypted
	// FYI: const void * binSignature.GetPointer()
	
	// RSA_PKCS1_OAEP_PADDING
	// RSA_PKCS1_PADDING
	
	// the 128 in the below call was a BUG. The SIZE of the ciphertext (signature) being decrypted is NOT 128 (modulus / cleartext size).
	// Rather, the size of the signature is RSA_size(pRsaKey).  Will have to revisit this likely, elsewhere in the code.
//	status = RSA_public_decrypt(128, static_cast<const unsigned char*>(binSignature.GetPointer()), pDecrypted, pRsaKey, RSA_NO_PADDING);
	int status = RSA_public_decrypt(nSignatureSize,	// length of signature, aka RSA_size(rsa)
									static_cast<const unsigned char*>(binSignature.GetPointer()), // location of signature
									pDecrypted,		// Output--must be large enough to hold the md (which is smaller than RSA_size(rsa) - 11)
									pRsaKey,		// signer's public key
									RSA_NO_PADDING);
	
	// int RSA_public_decrypt(int flen, unsigned char *from,
	//							unsigned char *to, RSA *rsa, int padding);
	
	// RSA_public_decrypt() recovers the message digest from the *flen* bytes long signature at *from*, 
	// using the signer's public key *rsa*.
	// padding is the padding mode that was used to sign the data.
	// *to* must point to a memory section large enough to hold the message digest 
	// (which is smaller than RSA_size(rsa) - 11).
	// RSA_public_decrypt() returns the size of the recovered message digest.
	/*
	 M         
	 message to be encrypted, an octet string of length at
	 most k-2-2hLen, where k is the length in octets of the
	 modulus n and hLen is the length in octets of the hash
	 function output for EME-OAEP
	 */
	
	if (status == -1) // Error
	{
		OTLog::vError("%s: RSA_public_decrypt failed with error %s\n", szFunc,
					  ERR_error_string(ERR_get_error(), NULL));
		RSA_free(pRsaKey); pRsaKey = NULL;
		return false;
	}
	// status contains size of recovered message digest after signature decryption.
	
	// verify the data
	// Now it compares pDecrypted (the decrypted message digest from the signature) with pDigest
	// (supposedly the same message digest, which we calculated above based on the message itself.) 
	// They SHOULD be the same.
	/*
	 int RSA_verify_PKCS1_PSS(RSA *rsa, const unsigned char *mHash,
						const EVP_MD *Hash, const unsigned char *EM, int sLen)
	 */							// rsa		mHash	Hash alg.	EM		 sLen
	status = RSA_verify_PKCS1_PSS(pRsaKey, pDigest, digest1, pDecrypted, -2); // salt length recovered from signature
	
	if (status == 1)
	{
		OTLog::Output(5, "  *Signature verified*\n");
		bReturnValue = true;
	}
	else
	{
		OTLog::vOutput(5, "%s: RSA_verify_PKCS1_PSS failed with error: %s\n", szFunc,
					   ERR_error_string(ERR_get_error(), NULL));
		RSA_free(pRsaKey); pRsaKey = NULL;
		return false;
	}
		
	/*
	 
	 NOTE:
	 RSA_private_encrypt() signs the flen bytes at from (usually a message digest with an algorithm identifier) 
	 using the private key rsa and stores the signature in to. to must point to RSA_size(rsa) bytes of memory.
	 
	 From: http://linux.die.net/man/3/rsa_public_decrypt
	 
	 RSA_NO_PADDING
	 Raw RSA signature. This mode should only be used to implement cryptographically sound padding modes in the application code. 
	 Signing user data directly with RSA is insecure.
	 
	 RSA_PKCS1_PADDING
	 PKCS #1 v1.5 padding. This function does not handle the algorithmIdentifier specified in PKCS #1. When generating or verifying
	 PKCS #1 signatures, rsa_sign(3) and rsa_verify(3) should be used.
	 
	 Need to research this and make sure it's being done right.
	 
	 Perhaps my use of the lower-level call here is related to my use of two message-digest algorithms.
	 -------------------------------
	 
	 On Sun, Feb 25, 2001 at 08:04:55PM -0500, Greg Stark wrote:
	 
	 > It is not a bug, it is a known fact. As Joseph Ashwood notes, you end up
	 > trying to encrypt values that are larger than the modulus. The documentation
	 > and most literature do tend to refer to moduli as having a certain "length"
	 > in bits or bytes. This is fine for most discussions, but if you are planning
	 > to use RSA to directly encrypt/decrypt AND you are not willing or able to
	 > use one of the padding schemes, then you'll have to understand *all* the
	 > details. One of these details is that it is possible to supply
	 > RSA_public_encrypt() with plaintext values that are greater than the modulus
	 > N. It returns values that are always between 0 and N-1, which is the only
	 > reasonable behavior. Similarly, RSA_public_decrypt() returns values between
	 > 0 and N-1.
	 
	 I have to confess I totally overlooked that and just assumed that if
	 RSA_size(key) would be 1024, then I would be able to encrypt messages of 1024
	 bits.
	 
	 > There are multiple solutions to this problem. A generally useful one
	 > is to use the RSA PKCS#1 ver 1.5 padding
	 > (http://www.rsalabs.com/pkcs/pkcs-1/index.html). If you don't like that
	 > padding scheme, then you might want to read the PKCS#1 document for the
	 > reasons behind that padding scheme and decide for yourself where you can
	 > modify it. It sounds like it be easiest if you just follow Mr. Ashwood's
	 > advice. Is there some problem with that?
	 
	 Yes well, upon reading the PKCS#1 v1.5 document I noticed that Mr. Ashwood
	 solves this problem by not only making the most significant bit zero, but in
	 fact the 6 most significant bits.
	 
	 I don't want to use one of the padding schemes because I already know the
	 message size in advance, and so does a possible attacker. Using a padding
	 scheme would therefore add known plaintext, which does not improve security.
	 
	 But thank you for the link! I think this solves my problem now :).
	 */
	
	/*
	 #include <openssl/rsa.h>
	 
	 int RSA_sign(int type, const unsigned char *m, unsigned int m_len,
					unsigned char *sigret, unsigned int *siglen, RSA *rsa);
	 int RSA_verify(int type, const unsigned char *m, unsigned int m_len,
					unsigned char *sigbuf, unsigned int siglen, RSA *rsa);
	 
	 DESCRIPTION
	 
	 RSA_sign() signs the message digest m of size m_len using the private key rsa as specified in PKCS #1 v2.0. 
	 It stores the signature in sigret and the signature size in siglen. sigret must point to RSA_size(rsa) bytes of memory.
	 
	 type denotes the message digest algorithm that was used to generate m. It usually is one of NID_sha1, NID_ripemd160 
	 and NID_md5; see objects(3) for details. If type is NID_md5_sha1, an SSL signature (MD5 and SHA1 message digests with 
	 PKCS #1 padding and no algorithm identifier) is created.
	 
	 RSA_verify() verifies that the signature sigbuf of size siglen matches a given message digest m of size m_len. type 
	 denotes the message digest algorithm that was used to generate the signature. rsa is the signer's public key.
	 
	 RETURN VALUES
	 
	 RSA_sign() returns 1 on success, 0 otherwise. RSA_verify() returns 1 on successful verification, 0 otherwise.
	 
	 The error codes can be obtained by ERR_get_error(3).
	 */
	
	/*
	 Hello,
	 > I am getting the following error in calling OCSP_basic_verify():
	 > 
	 > error:04067084:rsa routines:RSA_EAY_PUBLIC_DECRYPT:data too large for modulus
	 > 
	 > Could somebody advice what is going wrong?
	 
	 In RSA you can encrypt/decrypt only as much data as RSA key size
	 (size of RSA key is the size of modulus n = p*q).
	 In this situation, RSA routine checks size of data to decrypt
	 (probably signature) and this size of bigger than RSA key size, 
	 this if of course error.
	 I think that in this situation this is possible when OCSP was signed
	 with (for example) 2048 bit key (private key) and you have some
	 certificate with (maybe old) 1024 bit public key.
	 In this case this error may happen.
	 My suggestion is to check signer certificate. 
	 
	 Best regards,
	 -- 
	 Marek Marcola <[EMAIL PROTECTED]>
	 
	 
	 
	 Daniel Stenberg | 16 Jul 19:57
	 
	 Re: SSL cert error with CURLOPT_SSL_VERIFYPEER
	 
	 On Thu, 16 Jul 2009, Stephen Collyer wrote:
	 
	 > error:04067084:rsa routines:RSA_EAY_PUBLIC_DECRYPT:data too large for 
	 > modulus
	 
	 This sounds like an OpenSSL problem to me.
	 
	 
	 
	 http://www.mail-archive.com/openssl-users@openssl.org/msg38183.html
	 On Tue, Dec 07, 2004, Jesse Hammons wrote:
	 
	 > 
	 > > Jesse Hammons wrote:
	 > >
	 > >> So to clarify: If I generate a 65-bit key, will I be able to use that
	 > >> 65-bit key to sign any 64-bit value?
	 > >
	 > > Yes, but
	 > 
	 > Actually, I have found the answer to be "no" :-)
	 > 
	 > > a 65 bit key won't be very secure AT ALL, it will be
	 > > very easy to factor a modulus that small.
	 > 
	 > Security is not my goal.  This is more of a theoretical exercise that
	 > happens to have a practical application for me.
	 > 
	 > >  Bottom line: asymmetrical
	 > > (public-key) encryption has a fairly large "minimum block size" that
	 > > actually increases as key size increases.
	 > 
	 > Indeed.  I have found experimentally that:
	 >  * The minimum signable data quantity in OpenSSL is 1 byte
	 >  * The minimum size RSA key that can be used to sign 1 byte is 89 bits
	 >  * A signature created using a 64-bit RSA key would create a number 64
	 > bits long, BUT:
	 >    - This is not possible to do in OpenSSL because the maximum signable
	 > quantity for a 64
	 >       bit RSA key is only a few bits, and OpenSSL input/output is done on
	 > byte boundaries
	 > 
	 > Do those number sound right?
	 
	 It depends on the padding mode. These insert/delete padding bytes depending on
	 the mode used. If you use the no padding mode you can "sign" data equal to the
	 modulus length but less than its magnitude.
	 
	 Check the manual pages (e.g. RSA_private_encrypt()) for more info.
	 
	 
	 
	 
	 
	 http://www.mail-archive.com/openssl-users@openssl.org/msg29731.html
	 Hmm, the error message "RSA_R_DATA_TOO_LARGE_FOR_MODULUS"
	 is triggered by:
	 
	 ... (from RSA_eay_private_encrypt() in rsa_eay.c)
	 if (BN_ucmp(&f, rsa->n) >= 0)
	 {       
	 // usually the padding functions would catch this
	RSAerr(...,RSA_R_DATA_TOO_LARGE_FOR_MODULUS);
	goto err;
}
...
=> the error message has nothing to do with PKCS#1. It should tell you
that your plaintext (as a BIGNUM) is greater (or equal) than the modulus.
The typical error message in case of PKCS#1 error (in your case) would
be "RSA_R_DATA_TOO_LARGE_FOR_KEY_SIZE".

						> I can arrange for the plaintext to be a little smaller: 14 octets is
						> definitely doable. (The 15 octet length for the ciphertext I can't exceed.)
					  > If I arrange for the plaintext to be a zero followed by 14 octets of data,
					  > can I make this work?
					  
					  it should work (, but what about a longer (== more secure) key ?)
					  
					  Regards,
					  Nils
					  
					  
					  
					  
					  For reasons that would be tedious to rehearse, the size of the encrypted block has to be not more than 15 octets.
					  I was hoping for something a little more definitive than "should work."
					  
					  
					  >
					  > Would a good approach be perhaps to generate keys until I found one for
					  > which n is greater than the bignum representation of the largest plaintext?
					  > (Yeah, I know, this would restrict the key space, which might be a security
					  > concern.)
					  
					  It would be sufficient is the highest bit of the plaintext is zero
					  , because the highest bit of the modulus is certainly set 
					  (at least if the key is generated with OpenSSL).
					  
					  ...
					  > > it should work (, but what about a longer (== more secure) key ?)
					  >
					  > For reasons that would be tedious to rehearse, the size of the encrypted
					  > block has to be not more than 15 octets.
					  >
					  > I was hoping for something a little more definitive than "should work."
					  
					  Ok , unless something really strange happens: it will work :-)
					  
					  Regards,
					  Nils
					  
	 
	 Re: RSA_private_encrypt does not work with RSA_NO_PADDING option  
	 by Dr. Stephen Henson Jul 19, 2010; 10:31am :: Rate this Message:    - Use ratings to moderate (?)
	 Reply | Print | View Threaded | Show Only this Message
	 On Mon, Jul 19, 2010, anhpham wrote: 
	 
	 > 
	 > Hi all :x 
	 > I encountered an error when using function RSA_private_encrypt with 
	 > RSA_NO_PADDING option. 
	 > I had an unsigned char array a with length = 20, RSA* r, 
	 > unsigned char* sig = (unsigned char*) malloc(RSA_size(r)) and then I invoked 
	 > function int i = RSA_private_encrypt(20,a ,sign,r,RSA_NO_PADDING ); The 
	 > returned value  i = -1 means that this function failed. However, when I 
	 > invoked int i = RSA_private_encrypt(20,a,sig,r,RSA_PKCS1_PADDING ), it did 
	 > run smoothly. I'm confused whether it is an error of the library or not but 
	 > I don't know how to solve this problem. 
	 > Please help me :-<
	 ... [show rest of quote]
	 
	 If you use RSA_NO_PADDING you have to supply a buffer of RSA_size(r) bytes and 
	 whose value is less than the modulus. 
	 
	 With RSA_PKCS1_PADDING you can pass up to RSA_size(r) - 11. 
	 
	 Steve. 
	 -- 
	 Dr Stephen N. Henson. OpenSSL project core developer. 
	 Commercial tech support now available see: http://www.openssl.org
	 
	 
	 
	 Hello,
	 
	 I have a problem, I cannot really cover.
	 
	 I'm using public key encryption together with RSA_NO_PADDING. The
	 Key-/Modulus-Size is 128Byte and the message to be encrypted are also
	 128Byte sized.
	 
	 Now my problem:
	 Using the same (!) binary code (running in a debugging environment or not)
	 it sometimes work properly, sometimes it failes with the following
	 message:
	 
	 "error:04068084:rsa routines:RSA_EAY_PUBLIC_ENCRYPT:data too large for
	 modulus"
	 
	 Reply:
	 It is *not* enough that the modulus and message are both 128 bytes. You need
	 a stronger condition.
	 
	 Suppose your RSA modulus, as a BigNum, is n. Suppose the data you are trying
	 to encrypt, as a BigNum, is x. You must ensure that x < n, or you get that
	 error message. That is one of the reasons to use a padding scheme such as
	 RSA_PKCS1 padding.
	 
	 
	 knotwork
	 is this a reason to use larger keys or something? 4096 instead of2048 or 1024?
	 
	 4:41
	 FellowTraveler
	 larger keys is one solution, and that is why I've been looking at mkcert.c
	 which, BTW *you* need to look at mkcert.c since there are default values hardcoded, and I need you to give me a better idea of what you would want in those places, as a server operator.
	 First argument of encrypt should have been key.size() and first argument of decrypt should have been RSA_size(myKey).
	 Padding scheme should have been used
	 furthermore, RSA_Sign and RSA_Verify should have been used instead of RSA_Public_Decrypt and RSA_Private_Encrypt
	 What you are seeing, your error, is a perfectly normal result of the fact that the message data being passed in is too large for the modulus of your key.
	 .
	 All of the above fixes need to be investigated and implemented at some point, and that will almost certainly change the data format inside the key enough to invalidate all existing signatures
	 This is a real bug you found, in the crypto.
	 
	 4:43
	 knotwork
	 zmq got you thinking you could have large messages so you forgot the crypto had its own limits on message size?
	 
	 4:43
	 FellowTraveler
	 it's not message size per se
	 it's message DIGEST size in relation to key modulus
	 which must be smaller based on a bignum comparison of the two
	 RSA_Size is supposed to be used in decrypt
	 
	 4:44
	 knotwork
	 a form of the resync should fix everything, it just needs to run throguh everything resigning it with new type of signature?
	 
	 4:44
	 FellowTraveler
	 not that simple
	 I would have to code some kind of special "convert legacy data" thing into OT itself
	 though there might be a stopgap measure now, good enough to keep data until all the above fixes are made
	 ok see if this fixes it for you......
	 knotwork, go into OTLib/OTContract.cpp
	 Find the first line that begins with status = RSA_public_decrypt
	 
	 4:46
	 knotwork
	 vanalces would be enough maybe. jsut a way to set balances of all accoutns to whatever they actually are at the time
	 
	 4:46
	 FellowTraveler
	 the only other one is commented out, so it's not hard
	 you will see a hardcoded size:    status = RSA_public_decrypt(128,  
	 CHANGE the 128 to this value:
	 RSA_size(pRsaKey)
	 for now you can change the entire line to this:
	 status = RSA_public_decrypt(RSA_size(pRsaKey), static_cast<const unsigned char*>(binSignature.GetPointer()), pDecrypted, pRsaKey, RSA_NO_PADDING);
	 Then see if your bug goes away
	 I will still need to make fixes someday though, even if this works, and will have to lose or convert data.
	 4:48
	 otherwise there could be security issues down the road.
	
	 
	 TODO SECURITY ^  sign/verify needs revamping!
	 
	 UPDATE: Okay I may have it fixed now, though need to test still.
	 
	 http://www.bmt-online.org/geekisms/RSA_verify
	 
	 Also see: ~/Projects/openssl/demos/sign
	 */
	
	
	// ----------------------
	
	if (pRsaKey)
		RSA_free(pRsaKey);
	 pRsaKey = NULL;
		
	return bReturnValue;
}

#undef OT_MAX_PUBLIC_KEYSIZE
#undef OT_DEFAULT_PUBLIC_KEYSIZE
#undef OT_MAX_SYMMETRIC_KEYSIZE
#undef OT_DEFAULT_SYMMETRIC_KEYSIZE

#undef OT_DEFAULT_SIZE_DIGEST1
#undef OT_DEFAULT_SIZE_DIGEST2

// ---------------------------------------------------------





// All the other various versions eventually call this one, where the actual work is done.
//
bool OTContract::SignContract(const EVP_PKEY * pkey, OTSignature & theSignature, const OTString & strHashType)
{
    OT_ASSERT_MSG(NULL != pkey, "Null private key sent to OTContract::SignContract.\n");
    // ---------------------------------------------------
    const char * szFunc = "OTContract::SignContract";
    // ---------------------------------------------------
    
    class _OTCont_SignCont1
    {
    private:
        const char  *  m_szFunc;
        EVP_MD_CTX  &  m_ctx;
        
    public:
        _OTCont_SignCont1(const char * param_szFunc, EVP_MD_CTX & param_ctx) :
            m_szFunc(param_szFunc),
            m_ctx(param_ctx)
        {
            OT_ASSERT(NULL != m_szFunc);
            
            EVP_MD_CTX_init(&m_ctx);
        }
        ~_OTCont_SignCont1()
        {
            if (0 == EVP_MD_CTX_cleanup(&m_ctx))
                OTLog::vError("%s: Failure in cleanup. (It returned 0.)\n", m_szFunc);
        }
    };
    // ------------------------------------
    // Moving this lower...
    
//  _OTCont_SignCont1 theInstance(szFunc, md_ctx);
    
    // ------------------------------------
    
//	OTString strDoubleHash;

	// Update the contents, (not always necessary, many contracts are read-only)
	// This is where we provide an overridable function for the child classes that
	// need to update their contents at this point. 
	// But the OTContract version of this function is actually empty, since the 
	// default behavior is that contract contents don't change.
	// (Accounts and Messages being two big exceptions.)
	UpdateContents();
	
	// Are we using the special SAMY hash? In which case, we have to actually combine two signatures.
	const bool bUsesDefaultHashAlgorithm = strHashType.Compare(OTIdentifier::DefaultHashAlgorithm);
	EVP_MD * md = NULL;
	
	// SAMY hash. (The "default" hash.)
	if (bUsesDefaultHashAlgorithm)
	{
//		OTIdentifier hash1, hash2;
//		
//		hash1.CalculateDigest(m_xmlUnsigned, OTIdentifier::HashAlgorithm1);
//		hash2.CalculateDigest(m_xmlUnsigned, OTIdentifier::HashAlgorithm2);
//	
//		hash1.XOR(hash2);
//		hash1.GetString(strDoubleHash);
//
//		md = (EVP_MD *)OTIdentifier::GetOpenSSLDigestByName(OTIdentifier::HashAlgorithm1);
		return SignContractDefaultHash(pkey, theSignature);
	}
    // ---------------------------------------------------
//	else 
	{
		md = (EVP_MD *)OTIdentifier::GetOpenSSLDigestByName(strHashType);
	}
    // ---------------------------------------------------
	
	// If it's not the default hash, then it's just a normal hash.
	// Either way then we process it, first by getting the message digest pointer for signing.
	
	if (NULL == md)
	{
		OTLog::vError("%s: Unable to decipher Hash algorithm: %s\n", 
					  szFunc, strHashType.Get()); 
		return false; 
	}
    // ---------------------------------------------------
	int err, sig_len; 
	unsigned char sig_buf [4096]; // Safe since we pass the size when we use it.
    
    // RE: EVP_SignInit() or EVP_MD_CTX_init()...
    //
    // Since only a copy of the digest context is ever finalized the 
    // context MUST be cleaned up after use by calling EVP_MD_CTX_cleanup() 
    // or a memory leak will occur.
    //
	EVP_MD_CTX   md_ctx;     
    // ---------------------------------------------------
    
    _OTCont_SignCont1 theInstance(szFunc, md_ctx);

    // ----------------------
	// Do the signature
    // Note: I just changed this to the _ex version (in case I'm debugging later
    // and find a problem here.)
    //
	EVP_SignInit_ex(&md_ctx, md, NULL);

    // ---------------------------------------------------
//	if (bUsesDefaultHashAlgorithm)
//	{
//		EVP_SignUpdate (&md_ctx, strDoubleHash.Get(), strDoubleHash.GetLength());
//	}
//	else 
	{
		EVP_SignUpdate (&md_ctx, m_xmlUnsigned.Get(), m_xmlUnsigned.GetLength());
	}
    // ----------------------------------------------

	sig_len = sizeof(sig_buf); 
	err = EVP_SignFinal (&md_ctx, sig_buf, (unsigned int *)&sig_len, (EVP_PKEY *)pkey); 
		
	if (err != 1) 
	{ 
		OTLog::vError("%s: Error signing xml contents.\n", szFunc); 
		return false; 
	}
	else
    {
		OTLog::vOutput(3, "%s: Successfully signed xml contents.\n", szFunc);
		
		// We put the signature data into the signature object that
		// was passed in for that purpose.
		OTData tempData;
		tempData.Assign(sig_buf, sig_len);
		theSignature.SetData(tempData);
		
		return true;
	}
}


// All the other various versions eventually call this one, where the actual work is done.
bool OTContract::VerifySignature(const EVP_PKEY * pkey, const OTSignature & theSignature, const OTString & strHashType) const
{	
//	OTString strDoubleHash;
	
	OT_ASSERT_MSG(NULL != pkey, "Null key in OTContract::VerifySignature.\n");
	
	// Are we using the special SAMY hash? In which case, we have to actually combine two hashes.
	const bool bUsesDefaultHashAlgorithm = strHashType.Compare(OTIdentifier::DefaultHashAlgorithm);
	EVP_MD * md = NULL;
	
	if (bUsesDefaultHashAlgorithm)
	{
//		OTIdentifier hash1, hash2;
//		
//		hash1.CalculateDigest(m_xmlUnsigned, OTIdentifier::HashAlgorithm1);
//		hash2.CalculateDigest(m_xmlUnsigned, OTIdentifier::HashAlgorithm2);
//		
//		hash1.XOR(hash2);
//		hash1.GetString(strDoubleHash);
//
//		md = (EVP_MD *)OTIdentifier::GetOpenSSLDigestByName(OTIdentifier::HashAlgorithm1);
		return VerifyContractDefaultHash(pkey, theSignature);
	}
//	else
	{
		md = (EVP_MD *)OTIdentifier::GetOpenSSLDigestByName(strHashType);
	}
	
	if (!md) 
	{
		OTLog::vOutput(1, "Unknown message digest algorithm in OTContract::VerifySignature: %s\n", 
				strHashType.Get());
		return false;
	}
	
	OTData binSignature;
	
	// now binSignature contains the base64 decoded binary of the signature.
	// Unless the call failed of course...
	if (!theSignature.GetData(binSignature))
	{
		OTLog::Error("Error decoding base64 data for Signature in OTContract::VerifySignature.\n");
		return false;
	}
	
	
	EVP_MD_CTX ctx;	
	EVP_MD_CTX_init(&ctx);
	
	EVP_VerifyInit(&ctx, md);	

	// Here I'm adding the actual XML portion of the contract (the portion that gets signed.)
	// Basically we are repeating similarly to the signing process in order to verify.

//	if (bUsesDefaultHashAlgorithm)
//	{
//		EVP_VerifyUpdate(&ctx, strDoubleHash.Get(), strDoubleHash.GetLength());		
//	}
//	else 
	{
		EVP_VerifyUpdate(&ctx, m_xmlUnsigned.Get(), m_xmlUnsigned.GetLength());		
	}

	
	// Now we pass in the Signature
	// EVP_VerifyFinal() returns 1 for a correct signature, 0 for failure and -1 if some other error occurred.
	int nErr = EVP_VerifyFinal(&ctx, (const unsigned char *)binSignature.GetPointer(), 
							   (unsigned int)binSignature.GetSize(), (EVP_PKEY *)pkey); 
	
	EVP_MD_CTX_cleanup(&ctx);
	
	// the moment of true. 1 means the signature verified.
	if (1 == nErr)
		return true;
	else
		return false;
}



// Sign the Contract using a private key from a file.
// theSignature will contain the output.
bool OTContract::SignContract(const char * szFoldername, const char * szFilename, OTSignature & theSignature)
{	
	OT_ASSERT(NULL != szFoldername);
	OT_ASSERT(NULL != szFilename);
	
	EVP_PKEY * pkey = NULL; 
    
    const char * szFunc = "OTContract::SignContract";
	/*
	BIO *bio = BIO_new( BIO_s_file() );
	
	OT_ASSERT(NULL != bio);
	
	BIO_read_filename( bio, szFilename );
	*/
	// --------------------------------------------------------------------
	
	if (false == OTDB::Exists(szFoldername, szFilename))
	{
		OTLog::vError("%s: File does not exist: %s%s%s\n", szFunc,
					  szFoldername, OTLog::PathSeparator(), szFilename);
		return false;
	}
	
	// --------------------------------------------------------------------
	//
    std::string strFileContents(OTDB::QueryPlainString(szFoldername, szFilename)); // <=== LOADING FROM DATA STORE.
	
	if (strFileContents.length() < 2)
	{
		OTLog::vError("%s: Error reading file: %s%s%s\n", szFunc,
					  szFoldername, OTLog::PathSeparator(), szFilename);
		return false;
	}
	// --------------------------------------------------------------------
	// Create a new memory buffer on the OpenSSL side
	BIO * bio = BIO_new_mem_buf((void*)strFileContents.c_str(), -1);  // todo cast.
//	BIO * bio = BIO_new_mem_buf((void*)strFileContents.c_str(), strFileContents.length());  // todo cast.
//	BIO *bio = BIO_new(BIO_s_mem());
	OT_ASSERT(NULL != bio);
//  BIO_puts(bmem, Get());	
//	int nPutsResult = BIO_puts(bio, strFileContents.c_str());

	// --------------------------------------------------------------------
		
//	if (nPutsResult > 0)
	{
		// TODO security:
		/* The old PrivateKey write routines are retained for compatibility. 
		   New applications should write private keys using the PEM_write_bio_PKCS8PrivateKey() or PEM_write_PKCS8PrivateKey() 
		   routines because they are more secure (they use an iteration count of 2048 whereas the traditional routines use a
		   count of 1) unless compatibility with older versions of OpenSSL is important.
 		   NOTE: The PrivateKey read routines can be used in all applications because they handle all formats transparently.
		 */
		
        OTPasswordData thePWData("(OTContract::SignContract is trying to read the private key...)");
        
		pkey = PEM_read_bio_PrivateKey( bio, NULL, OTAsymmetricKey::GetPasswordCallback(), &thePWData);
		
		if (NULL == pkey) 
		{ 
			OTLog::vError("%s: Error reading private key from BIO.\n", szFunc); 
			BIO_free_all(bio);
			return false; 
		} 
		
		bool bSigned = SignContract(pkey, theSignature, m_strSigHashType);
		
		EVP_PKEY_free (pkey);  pkey = NULL;
		BIO_free_all(bio);
		
		return bSigned;
	}
	
	BIO_free_all(bio);
	return false;
}


void OTContract::ReleaseSignatures()
{
	OTSignature * pSig = NULL;
	
	while (!m_listSignatures.empty())
	{
		pSig = m_listSignatures.front();
		m_listSignatures.pop_front();
		delete pSig; pSig=NULL;
	}
}


bool OTContract::VerifySignature(const OTPseudonym & theNym)
{
	FOR_EACH(listOfSignatures, m_listSignatures)
	{
		OTSignature * pSig = *it;
		OT_ASSERT(NULL != pSig);
		
		if (VerifySignature(theNym, *pSig))
			return true;
	}
	
	return false;
}


// The only different between calling this with a Nym and calling it with an Asymmetric Key is that
// the key gives you the choice of hash algorithm, whereas the nym version uses m_strHashType to decide
// for you.  Choose the function you prefer, you can do it either way.
bool OTContract::VerifySignature(const OTPseudonym & theNym, const OTSignature & theSignature) const
{
	return VerifySignature(theNym.GetPublicKey(), theSignature, m_strSigHashType);
}

/*
 openssl dgst -sha1 \
 -sign clientkey.pem \
 -out cheesy2.sig \
 cheesy2.xml

 openssl dgst -sha1 \
 -verify clientcert.pem \
 -signature cheesy2.sig \
 cheesy2.xml
 
 
 
openssl x509 -in clientcert.pem -pubkey -noout > clientpub.pem
 
 Then verification using the public key works as expected:
 
openssl dgst -sha1 -verify clientpub.pem -signature cheesy2.sig  cheesy2.xml
 
 Verified OK
 
 
 openssl enc -base64 -out cheesy2.b64 cheesy2.sig
 
 */

bool OTContract::VerifySignature(const OTAsymmetricKey & theKey, const OTSignature & theSignature, const OTString & strHashType) const
{
	return VerifySignature((const_cast<OTAsymmetricKey &>(theKey)).GetKey(), theSignature, strHashType);
}



// Presumably the Signature passed in here was just loaded as part of this contract and is
// somewhere in m_listSignatures. Now it is being verified.
//
bool OTContract::VerifySignature(const char * szFoldername, const char * szFilename, const OTSignature & theSignature) const
{
	OT_ASSERT_MSG(NULL != szFoldername, "Null foldername pointer passed to OTContract::VerifySignature");
	OT_ASSERT_MSG(NULL != szFilename, "Null filename pointer passed to OTContract::VerifySignature");
	
    const char * szFunc = "OTContract::VerifySignature";
    
//	FILE	 * fp	= NULL; 
	X509	 * x509	= NULL; 
	EVP_PKEY * pkey	= NULL; 
	
	// Read public key
	OTLog::vOutput(2, "%s: Reading public key from certfile in order to verify signature...\n", szFunc); 

	/*
	BIO * bio = BIO_new( BIO_s_file() );
	OT_ASSERT(NULL != bio);
	BIO_read_filename( bio, szFilename );
	*/
	
	// --------------------------------------------------------------------
	
	if (false == OTDB::Exists(szFoldername, szFilename))
	{
		OTLog::vError("%s: File does not exist: %s%s%s\n", szFunc,
					  szFoldername, OTLog::PathSeparator(), szFilename);
		return false;
	}
	
	// --------------------------------------------------------------------
	//
	std::string strFileContents(OTDB::QueryPlainString(szFoldername, szFilename)); // <=== LOADING FROM DATA STORE.
	
	if (strFileContents.length() < 2)
	{
		OTLog::vError("%s: Error reading file: %s%s%s\n", szFunc,
					  szFoldername, OTLog::PathSeparator(), szFilename);
		return false;
	}
	// --------------------------------------------------------------------
	
	// Create a new memory buffer on the OpenSSL side
	BIO * bio = BIO_new_mem_buf((void*)strFileContents.c_str(), -1); // todo cast
//	BIO * bio = BIO_new_mem_buf((void*)strFileContents.c_str(), strFileContents.length()); // todo cast
//	BIO *bio = BIO_new(BIO_s_mem());
	OT_ASSERT(NULL != bio);
	//BIO_puts(bmem, Get());
	
//	int nPutsResult = BIO_puts(bio, strFileContents.c_str());
	
	// --------------------------------------------------------------------
//	if (nPutsResult <= 0)
//	{
//		BIO_free_all(bio);
//		return false;
//	}
	
    OTPasswordData thePWData("(OTContract::VerifySignature is trying to read the private key...)");

	x509 = PEM_read_bio_X509(bio, NULL, OTAsymmetricKey::GetPasswordCallback(), &thePWData); 
	BIO_free_all(bio);
	
	// --------------------------
	
	if (x509 == NULL) 
	{ 
		OTLog::vError("%s: Failed reading x509 out of cert file: %s%s%s\n", szFunc,
					  szFoldername, OTLog::PathSeparator(), szFilename);
		return false; 
	}
	
	bool bVerifySig = false;
	
	pkey = X509_get_pubkey(x509); 
	
	if (pkey == NULL) 
	{ 
		OTLog::vError("%s: Failed reading public key from x509 from certfile: %s\n",
                      szFunc, szFilename); 
	} 
	else 
	{
		bVerifySig = VerifySignature(pkey, theSignature, m_strSigHashType);
		EVP_PKEY_free(pkey); pkey = NULL;
	}

	// At some point have to call this
	X509_free(x509);   x509 = NULL;
	
	return bVerifySig; 
}




bool OTContract::DisplayStatistics(OTString & strContents) const
{
	// Subclasses may override this.
	strContents.Concatenate((char*)"ERROR:  OTContract::DisplayStatistics was called instead of a subclass...\n");
	
	return false;	
}


bool OTContract::SaveContractWallet(OTString & strContents) const
{
	// Subclasses may use this.
	
	return false;
}


bool OTContract::SaveContents(std::ofstream & ofs) const
{	
	ofs << m_xmlUnsigned.Get();
	
	return true;
}

// Saves the unsigned XML contents to a string
bool OTContract::SaveContents(OTString & strContents) const
{
	strContents.Concatenate(m_xmlUnsigned.Get());

	return true;
}


/*
 bool OTContract::SaveContents(FILE * fl) const
 {
 if (fl)
 fprintf(fl, "%s", m_xmlUnsigned.Get());
 
 return true;
 }
 */



// Save the contract member variables into the m_strRawFile variable

bool OTContract::SaveContract()
{
	OTString strTemp;
	bool bSuccess = RewriteContract(strTemp);
	
	if (bSuccess)
	{
		m_strRawFile.Set(strTemp);
		
		
		// RewriteContract() already does this.
		//
//		std::string str_Trim(strTemp.Get());
//		std::string str_Trim2 = OTString::trim(str_Trim);
//		m_strRawFile.Set(str_Trim2.c_str());
	}
	
	return bSuccess;
}


// Make sure you escape any lines that begin with dashes using "- "
// So "---BEGIN " at the beginning of a line would change to: "- ---BEGIN"
// This function expects that's already been done.
// This function assumes there is only unsigned contents, and not a signed contract.
// This function is intended to PRODUCE said signed contract.
//
bool OTContract::CreateContract(OTString & strContract, OTPseudonym & theSigner)
{	
	const char * szFunc = "OTContract::CreateContract";

	Release();
    
    char cNewline = 0;
    const uint32_t lLength = strContract.GetLength();
    
    if ((3 > lLength) || !strContract.At(lLength - 1, cNewline))
    {
        OTLog::vError("%s: Invalid input: contract is less than 3 bytes "
                      "long, or unable to read a byte from the end where a newline is meant to be.\n", szFunc);
        return false;
    }
    // ----------------------
    // ADD a newline, if necessary.
    // (The -----BEGIN part needs to start on its OWN LINE...)
    //
    // If length is 10, then string goes from 0..9.
    // Null terminator will be at 10.
    // Therefore the final newline should be at 9.
    // Therefore if char_at_index[lLength-1] != '\n'
    // Concatenate one!
    
    if ('\n' == cNewline) // It already has a newline
        m_xmlUnsigned = strContract;
    else
        m_xmlUnsigned.Format("%s\n", strContract.Get());
    
    // ----------------------
	// This function assumes that m_xmlUnsigned is ready to be processed.
	// This function only processes that portion of the contract.
    //
	bool bLoaded = LoadContractXML();
	
	if (bLoaded)
	{
		// -----------------------------------

		OTString strTemp;
		
		if (false == SignContract(theSigner))
        {
            OTLog::vError("%s: this->SignContract failed.  strTemp contents:\n\n%s\n\n\n", 
                          szFunc, strTemp.Get());
            return false;
        }
		SaveContract();

		
        OTLog::vError("%s: m_xmlUnsigned AFTER SAVING:\n\n%s\n\n", szFunc, m_xmlUnsigned.Get());
        
        OTLog::vError("%s: m_strRawFile AFTER SAVING:\n\n%s\n\n", szFunc, m_strRawFile.Get());
        
        
        SaveContractRaw(strTemp);
        
        
        
        OTLog::vError("%s: STRING AFTER SIGNING:\n\n%s\n\n", szFunc, strTemp.Get());
        
		// -----------------------------------
		
        Release();
        LoadContractFromString(strTemp);
        
        // -----------------------------------

		OTIdentifier NEW_ID;
		CalculateContractID(NEW_ID);
		m_ID = NEW_ID;	
        
        // -----------------------------------

		return true;
	}
    else
    {
        OTLog::vError("%s: this->LoadContractXML failed.  strContract contents:\n\n%s\n\n\n", 
                      szFunc, strContract.Get());
        return false;
    }

	return false;
}




// Saves the raw (pre-existing) contract text to any string you want to pass in.
bool OTContract::SaveContractRaw(OTString & strOutput) const
{
	strOutput.Concatenate("%s", m_strRawFile.Get());

	return true;
}

// Takes the pre-existing XML contents (WITHOUT signatures) and re-writes the Raw data, adding the pre-existing signatures along with new signature bookends. 
bool OTContract::RewriteContract(OTString & strOutput) const
{
	OTString strTemp;
	
	// ---------------------------------------------------------------
	
	strTemp.Concatenate("-----BEGIN SIGNED %s-----\nHash: %s\n\n", 
						m_strContractType.Get(), m_strSigHashType.Get());
	
	// ---------------------------------------------------------------
	
	this->SaveContents(strTemp);
	
	// ---------------------------------------------------------------
	
	FOR_EACH_CONST(listOfSignatures, m_listSignatures)
	{
		OTSignature * pSig = *it;
		OT_ASSERT(NULL != pSig);
		
		strTemp.Concatenate("-----BEGIN %s SIGNATURE-----\n"
							"Version: Open Transactions %s\n"
							"Comment: http://github.com/FellowTraveler/Open-Transactions/wiki\n\n", 
							m_strContractType.Get(), OTLog::Version());
		strTemp.Concatenate("%s", pSig->Get());
		strTemp.Concatenate("-----END %s SIGNATURE-----\n\n", m_strContractType.Get());
	}
	// ---------------------------------------------------------------
	
	std::string str_Trim(strTemp.Get());
	std::string str_Trim2 = OTString::trim(str_Trim);
	
	strOutput.Set(str_Trim2.c_str());
	
	return true;		
}

/*
bool OTContract::SaveContract(OTString & strContract)
{	
	OTString strTemp;
	
	// ---------------------------------------------------------------
	
	strTemp.Concatenate("-----BEGIN SIGNED %s-----\nHash: %s\n\n", 
						m_strContractType.Get(), m_strSigHashType.Get());
	
	// ---------------------------------------------------------------
	
	SaveContents(strTemp);
	
	// ---------------------------------------------------------------
	
	FOR_EACH(listOfSignatures, m_listSignatures)
	{
		OTSignature * pSig = *it;
		OT_ASSERT(NULL != pSig);
		
		strTemp.Concatenate("-----BEGIN %s SIGNATURE-----\n"
								"Version: Open Transactions %s\n"
								"Comment: http://github.com/FellowTraveler/Open-Transactions/wiki\n\n", 
								m_strContractType.Get(), OTLog::Version());
		strTemp.Concatenate("%s", pSig->Get());
		strTemp.Concatenate("-----END %s SIGNATURE-----\n\n", m_strContractType.Get());
	}
	// ---------------------------------------------------------------
	
	std::string str_Trim(strTemp.Get());
	std::string str_Trim2 = OTString::trim(str_Trim);
	
	strOutput.Set(str_Trim2.c_str());
		
	return true;		
}
*/


	
bool OTContract::SaveContract(const char * szFoldername, const char * szFilename)
{
	OT_ASSERT_MSG(NULL != szFilename, "Null filename sent to OTContract::SaveContract\n");
	OT_ASSERT_MSG(NULL != szFoldername, "Null foldername sent to OTContract::SaveContract\n");
	
	m_strFoldername.Set(szFoldername);
	m_strFilename.Set(szFilename);
	
	OT_ASSERT(m_strFoldername.GetLength() > 2);
	OT_ASSERT(m_strFilename.GetLength() > 2);
	
	// --------------------------------------------------------------------
    
    if (!m_strRawFile.Exists())
    {
		OTLog::vError("OTContract::SaveContract: Error saving file (contract contents are empty): %s%s%s\n", 
					  szFoldername, OTLog::PathSeparator(), szFilename);
		return false;
    }
    // --------------------------------------------------------------------

	OTString strFinal;
//	OTString strFinal(m_strRawFile);
    OTASCIIArmor ascTemp(m_strRawFile);
    
    if (false == ascTemp.WriteArmoredString(strFinal, m_strContractType.Get()))
    {
		OTLog::vError("OTContract::SaveContract: Error saving file (failed writing armored string): %s%s%s\n", 
					  szFoldername, OTLog::PathSeparator(), szFilename);
		return false;
    }
    // --------------------------------------------------------------------
	bool bSaved = OTDB::StorePlainString(strFinal.Get(), szFoldername, szFilename);
	
	if (!bSaved)
	{
		OTLog::vError("OTContract::SaveContract: Error saving file: %s%s%s\n", 
					  szFoldername, OTLog::PathSeparator(), szFilename);
		return false;
	}
	// --------------------------------------------------------------------
/*
	std::ofstream ofs(szFilename, std::ios::binary);
	
	if (ofs.fail())
	{
		OTLog::vError("Error opening file in OTContract::SaveContract: %s\n", szFilename);
		return false;
	}
	
	ofs.clear();
	
	OTString strFinal;
	SaveContract(strFinal);
	
	ofs << strFinal.Get();
	ofs.close();
 */
	// --------

	/*
	fprintf(fl, "%s", strFinal.Get());
	fclose(fl);
	*/
	
	return true;	
}



	


// assumes m_strFilename is already set.
// Then it reads that file into a string.
// Then it parses that string into the object.
bool OTContract::LoadContract()
{		
	Release();
	LoadContractRawFile(); // opens m_strFilename and reads into m_strRawFile
	
	return ParseRawFile(); // Parses m_strRawFile into the various member variables.
}

	
// The entire Raw File, signatures and all, is used to calculate the hash 
// value that becomes the ID of the contract. If you change even one letter,
// then you get a different ID.
// This applies to all contracts except accounts, since their contents must
// change periodically, their ID is not calculated from a hash of the file, 
// but instead is chosen at random when the account is created.
bool OTContract::LoadContractRawFile()
{	
	const char * szFoldername = m_strFoldername.Get();
	const char * szFilename = m_strFilename.Get();
	
	if (!m_strFoldername.Exists() || !m_strFilename.Exists())
		return false;
	
	// --------------------------------------------------------------------
	
	if (false == OTDB::Exists(szFoldername, szFilename))
	{
		OTLog::vError("OTContract::LoadContractRawFile: File does not exist: %s%s%s\n", 
					  szFoldername, OTLog::PathSeparator(), szFilename);
		return false;
	}
    // --------------------------------------------------------------------
	//
	OTString strFileContents(OTDB::QueryPlainString(szFoldername, szFilename)); // <=== LOADING FROM DATA STORE.

	if (strFileContents.GetLength() < 2)
	{
		OTLog::vError("OTContract::LoadContractRawFile: Error reading file: %s%s%s\n", 
					  szFoldername, OTLog::PathSeparator(), szFilename);
		return false;
	}
	// --------------------------------------------------------------------
    // To support legacy data, we check here to see if it's armored or not.
    // If it's not, we support it. But if it IS, we ALSO support it (we de-armor it here.)
    //
    bool bArmoredAndALSOescaped = false;    // "- -----BEGIN OT ARMORED"
    bool bArmoredButNOTescaped  = false;    // "-----BEGIN OT ARMORED"
    
    if (strFileContents.Contains(OT_BEGIN_ARMORED_escaped)) // check this one first...
    {
        bArmoredAndALSOescaped = true;
    }
    else if (strFileContents.Contains(OT_BEGIN_ARMORED))
    {
        bArmoredButNOTescaped = true;
    }
    // ----------------------------------------
    const bool bArmored = (bArmoredAndALSOescaped || bArmoredButNOTescaped);
    // ----------------------------------------
    
    // Whether the string is armored or not, (-----BEGIN OT ARMORED)
    // either way, we'll end up with the decoded version in this variable:
    //
    std::string str_Trim;
    
    // ------------------------------------------------
    if (bArmored) // it's armored, we have to decode it first.
    {
        OTASCIIArmor ascTemp;
        
        if (false == (ascTemp.LoadFromString(strFileContents, 
                                             bArmoredAndALSOescaped, // if it IS escaped or not, this variable will be true or false to show it.
                                             // The below szOverride sub-string determines where the content starts, when loading.
                                             OT_BEGIN_ARMORED)))     // Default is:       "-----BEGIN" 
                                                                     // We're doing this: "-----BEGIN OT ARMORED" (Should worked for escaped as well, here.)
        {
            OTLog::vError("OTContract::LoadContractRawFile: Error loading file contents from "
                          "ascii-armored encoding: %s%s%s.\n Contents: \n%s\n", 
                          szFoldername, OTLog::PathSeparator(), szFilename, strFileContents.Get());
            return false;
        }
        else // success loading the actual contents out of the ascii-armored version.
        {
            OTString strTemp(ascTemp); // <=== ascii-decoded here.
            
            std::string str_temp(strTemp.Get(), strTemp.GetLength());
            
            str_Trim = OTString::trim(str_temp); // This is the std::string for the trim process.
        } 
    }
    else
    {
        std::string str_temp(strFileContents.Get(), strFileContents.GetLength());
        
        str_Trim = OTString::trim(str_temp); // This is the std::string for the trim process. (Wasn't armored, so here we use it as passed in.)
    }
    // ------------------------------------------------
    
    // At this point, str_Trim contains the actual contents, whether they
    // were originally ascii-armored OR NOT. (And they are also now trimmed, either way.)
    // ------------------------------------------

	m_strRawFile.Set(str_Trim.c_str());
	
	if (m_strRawFile.GetLength())
		return true;
	else
		return false;
}


bool OTContract::LoadContract(const char * szFoldername, const char * szFilename)
{
	Release();
	
	m_strFoldername.Set(szFoldername);
	m_strFilename.Set(szFilename);
	
	// --------------------------------------------
	/*
	if (false == OTLog::ConfirmExactPath(m_strFilename.Get()))
	{
		OTLog::vOutput(3, "LoadContract: File does not exist: %s\n", m_strFilename.Get());
		return false;
	}
	*/
	// --------------------------------------------
	
	// opens m_strFilename and reads into m_strRawFile
	if (LoadContractRawFile())
		return ParseRawFile(); // Parses m_strRawFile into the various member variables.
	else 
	{
		OTLog::vError("Failed loading raw contract file: %s%s%s\n", 
					  m_strFoldername.Get(), OTLog::PathSeparator(), m_strFilename.Get());
	}

	return false;
}






// Just like it says. If you have a contract in string form, pass it in
// here to import it.
bool OTContract::LoadContractFromString(const OTString & theStr)
{
	Release();
	
    const char * szFunc = "OTContract::LoadContractFromString";
    
	if (!theStr.Exists())
	{
		OTLog::vError("%s: Empty string passed in... (Error)\n", szFunc);
		
//		OT_ASSERT_MSG(false, "Callstack?");

		return false;
	}
	
    // --------------------------------------------------------------------
    // To support legacy data, we check here to see if it's armored or not.
    // If it's not, we support it. But if it IS, we ALSO support it (we de-armor it here.)
    //
    bool bArmoredAndALSOescaped = false;    // "- -----BEGIN OT ARMORED"
    bool bArmoredButNOTescaped  = false;    // "-----BEGIN OT ARMORED"
    
    if (theStr.Contains(OT_BEGIN_ARMORED_escaped)) // check this one first...
    {
        bArmoredAndALSOescaped = true;
    }
    else if (theStr.Contains(OT_BEGIN_ARMORED))
    {
        bArmoredButNOTescaped = true;
    }
    // ----------------------------------------
    const bool bArmored = (bArmoredAndALSOescaped || bArmoredButNOTescaped);
    // ----------------------------------------

    // Whether the string is armored or not, (-----BEGIN OT ARMORED)
    // either way, we'll end up with the decoded version in this variable:
    //
    std::string str;

    // ------------------------------------------------
    if (bArmored) // it's armored, we have to decode it first.
    {
        OTASCIIArmor ascTemp;
        OTString strNotConst(theStr);
        
        if (false == (ascTemp.LoadFromString(strNotConst, 
                                             bArmoredAndALSOescaped, // if it IS escaped or not, this variable will be true or false to show it.
                                             // The below szOverride sub-string determines where the content starts, when loading.
                                             OT_BEGIN_ARMORED)))     // Default is:       "-----BEGIN" 
                                                                     // We're doing this: "-----BEGIN OT ARMORED" (Should worked for escaped as well, here.)
        {
            OTLog::vError("%s: Error loading file contents from ascii-armored encoding: %s\n", 
                          szFunc, theStr.Get());
            return false;
        }
        else // success loading the actual contents out of the ascii-armored version.
        {
//            OTLog::vError("DEBUGGING OTCONTRACT: ascTemp: \n%s\n",
//                         ascTemp.Get());
            
            if (ascTemp.GetLength() > 2)
            {
                OTString strTemp(ascTemp); // <=== ascii-decoded here.
                
                str = strTemp.Get(); // This is the std::string for the trim process.
            }
            else
            {
                OTLog::vError("%s: Error loading file contents from empty or near-empty "
                              "ascii-armored encoding: %s\n", szFunc, theStr.Get());
                return false;
            }
        } 
    }
    else
        str = theStr.Get(); // This is the std::string for the trim process. (Wasn't armored, so here we use it as passed in.)
    // ------------------------------------------------
    
	// This populates the internal "raw file" member as if we had actually read it from a file.	
//	std::string str(theStr.Get());
	std::string str_trim = OTString::trim(str);
	m_strRawFile.Set(str_trim.c_str());
	
    // todo: would like to avoid so many string copies. Optimize.
    
	// This populates m_xmlUnsigned with the contents of m_strRawFile (minus bookends, signatures, etc. JUST the XML.)
	bool bSuccess = ParseRawFile(); // It also parses into the various member variables.
	
    // (I think this was the bug where the version changed from 75 to 75c, and suddenly contract ID was wrong...)
    //
	// If it was a success, save back to m_strRawFile again so 
	// the format is consistent and hashes will calculate properly.
//	if (bSuccess)
//	{
//		// Basically we take the m_xmlUnsigned that we parsed out of the raw file before,
//		// then we use that to generate the raw file again, re-attaching the signatures.
//		// This function does that.
//		SaveContract();
//	} 
	
	return bSuccess;
}




bool OTContract::ParseRawFile()
{
	char buffer1[2100]; // a bit bigger than 2048, just for safety reasons.
	OTSignature * pSig = NULL;
	
	std::string line;
	
	bool bSignatureMode = false; // "currently in signature mode"
	bool bContentMode = false; // "currently in content mode"
	bool bHaveEnteredContentMode = false; // "have yet to enter content mode"
	
	if (!m_strRawFile.GetLength())
	{
		OTLog::vError("Empty m_strRawFile in OTContract::ParseRawFile. Filename: %s%s%s.\n", 
					  m_strFoldername.Get(), OTLog::PathSeparator(), m_strFilename.Get());
		return false;
	}
	
	// This is redundant (I thought) but the problem hasn't cleared up yet.. so trying to really nail it now.
	std::string str_Trim(m_strRawFile.Get());
	std::string str_Trim2 = OTString::trim(str_Trim);
	m_strRawFile.Set(str_Trim2.c_str());
	// ----------------------------------------
	
	bool bIsEOF = false;
	m_strRawFile.reset();
	
	do
	{
		// Just a fresh start at the top of the loop block... probably unnecessary.
		memset(buffer1, 0, 2100);
		
		// the call returns true if there's more to read, and false if there isn't.
		bIsEOF = !(m_strRawFile.sgets(buffer1, 2048));
//		bIsEOF = fin.getline(buffer1, 2048).eof();
		
		line = buffer1;
		const char * pConstBuf = line.c_str();
		char * pBuf = (char *)pConstBuf;
		
		
		if (line.length() < 2)
		{
			if (bSignatureMode)
				continue;
		}
		
		// if we're on a dashed line...
		else if (line.at(0) == '-')
		{			
			if (bSignatureMode)
			{
				// we just reached the end of a signature
			//	OTLog::vError("%s\n", pSig->Get());
				pSig = NULL;
				bSignatureMode = false;
				continue;
			}
			
			// if I'm NOT in signature mode, and I just hit a dash, that means there
			// are only four options:
			
			// a. I have not yet even entered content mode, and just now entering it for the first time.
			if (!bHaveEnteredContentMode)
			{
				if ((line.length() > 3) && 
					(line.find("BEGIN")!=std::string::npos) && 
					line.at(1) == '-' && 
					line.at(2) == '-' && 
					line.at(3) == '-')
				{
//					OTLog::Error("\nProcessing contract... \n");
					bHaveEnteredContentMode = true;
					bContentMode = true;
					continue;
				}
				else
				{
					continue;
				}				
				
			}
			
			// b. I am now entering signature mode!
			else if (line.length() > 3 && line.find("SIGNATURE")!=std::string::npos && line.at(1) == '-' && line.at(2) == '-' && line.at(3) == '-')
			{
				//if (bContentMode)
				//	OTLog::Output(3, "Finished reading contract.\n\nReading a signature at the bottom of the contract...\n");
				//else
				//	OTLog::Output(3, "Reading another signature...\n");
				
				bSignatureMode = true;
				bContentMode   = false;
				
				pSig = new OTSignature();
				
				OT_ASSERT_MSG(NULL != pSig, "Error allocating memory for Signature in OTContract::ParseRawFile\n");
				
				m_listSignatures.push_back(pSig);
				
				continue;
			}
			// c. There is an error in the file!
			else if (line.length() < 3 || line.at(1) != ' ' || line.at(2) != '-')
			{
				OTLog::vOutput(0, "Error in contract %s: a dash at the beginning of the "
						"line should be followed by a space and another dash:\n%s\n", 
							   m_strFilename.Get(), m_strRawFile.Get());
				return false;
			}
			// d. It is an escaped dash, and therefore kosher, so I merely remove the escape and add it.
			else 
				; // I've decided not to remove the dashes but to keep them as part of the signed content.
			// It's just much easier to deal with that way. The input code will insert the extra dashes.
			//pBuf += 2;  
		}
		
		// Else we're on a normal line, not a dashed line.
		else
		{
			if (bHaveEnteredContentMode)
			{
				if (bSignatureMode)
				{
					if (line.length()<2 ||
						line.compare(0,8,"Version:") == 0 || 
						line.compare(0,8,"Comment:") == 0
						)
					{
						OTLog::Output(3, "Skipping version section...\n");
						
						if (!m_strRawFile.sgets(buffer1, 2048))
						{
							OTLog::vOutput(0, "Error in signature for contract %s: Unexpected EOF after \"Version:\"\n", m_strFilename.Get());
							return false;
						}
						
						continue;
					}
				}
				if (bContentMode)
				{
					if (line.compare(0,6,"Hash: ") == 0)
					{
						OTLog::Output(3, "Collecting message digest algorithm from contract header...\n");
						
						std::string strTemp = line.substr(6);
						m_strSigHashType = strTemp.c_str();
						m_strSigHashType.ConvertToUpperCase();
						
						if (!m_strRawFile.sgets(buffer1, 2048))
						{
							OTLog::vOutput(0, "Error in contract %s: Unexpected EOF after \"Hash:\"\n", m_strFilename.Get());
							return false;
						}
						continue;
					}
				}
			}
		}

		if (bSignatureMode)
		{
			OT_ASSERT_MSG(NULL != pSig, "Error: Null Signature pointer WHILE processing signature, in OTContract::ParseRawFile");
			
			pSig->Concatenate("%s\n", pBuf);
		}
		else if (bContentMode)
			m_xmlUnsigned.Concatenate("%s\n", pBuf);
	}
	while(!bIsEOF);
	//	while(!bIsEOF && (!bHaveEnteredContentMode || bContentMode || bSignatureMode));
	
	
	/*	
	 OTSignature theSignature;	
	 SignContract("clientkey.pem", theSignature);
	 
	 FILE * tf = fopen("output.txt", "w");
	 
	 fprintf(tf, "-----BEGIN CONTRACT SIGNATURE-----\n%s-----END CONTRACT SIGNATURE-----\n",
	 theSignature.Get());
	 fclose(tf);
	 */
	
	if (!bHaveEnteredContentMode)
	{
		OTLog::Error("Error in OTContract::ParseRawFile: Found no BEGIN for signed content.\n");
		return false;
	}
	else if (bContentMode)
	{
		OTLog::Error("Error in OTContract::ParseRawFile: EOF while reading xml content.\n");
		return false;
	}
	else if (bSignatureMode)
	{
		OTLog::Error("Error in OTContract::ParseRawFile: EOF while reading signature.\n");
        OT_ASSERT_MSG(false, "gimme a call stack!");
		return false;
	}
	else if (!LoadContractXML())
	{
		OTLog::Error("Error in OTContract::ParseRawFile: unable to load XML portion of contract into memory.\n");
		return false;
	}
	// Verification code and loading code are now called separately.
//	else if (!VerifyContractID())
//	{
//		OTLog::Error("Error in OTContract::ParseRawFile: Contract ID does not match hashed contract file.\n");
//		return false;
//	}
	else 
	{
		return true;
	}
}



// This function assumes that m_xmlUnsigned is ready to be processed.
// This function only processes that portion of the contract.
bool OTContract::LoadContractXML()
{
	int retProcess = 0;
	
	if (!m_xmlUnsigned.Exists())
	{
		return false;
	}
	
    m_xmlUnsigned.reset();
    
	IrrXMLReader* xml = createIrrXMLReader(&m_xmlUnsigned);
	OT_ASSERT_MSG(NULL != xml, "Memory allocation issue with xml reader in OTContract::LoadContractXML()\n");
    OTCleanup<IrrXMLReader> xmlAngel(*xml);
    
	// parse the file until end reached
	while(xml->read())
	{
		switch(xml->getNodeType())
		{
			case EXN_NONE:
			case EXN_COMMENT:
			case EXN_ELEMENT_END:
			case EXN_CDATA:
				break;
				
			case EXN_TEXT:
			{
				// unknown element type
				OTLog::vError( "unknown text element type in OTContract::LoadContractXML: %s, value: %s\n", 
							  xml->getNodeName(), xml->getNodeData());
			}
				break;
			case EXN_ELEMENT:
				{
					retProcess = ProcessXMLNode(xml);
					
					// an error was returned. file format or whatever.
					if ((-1) == retProcess)
					{
						return false;
					}
					// No error, but also the node wasn't found...
					else if (0 == retProcess)
					{
						// unknown element type
						OTLog::vError("UNKNOWN element type in OTContract::LoadContractXML: %s, value: %s\n", 
								xml->getNodeName(), xml->getNodeData());
					}
					// else if 1 was returned, that means the node was processed.
				}
				break;
			default:
			{
			}
				continue;
				
		}
	}
		
	return true;	
}


// -------------------------------------------------------------

bool OTContract::SkipToElement(IrrXMLReader*& xml)
{
	OT_ASSERT_MSG(NULL != xml, "OTContract::SkipToElement -- assert: NULL != xml");
	
	// ------------------
	while(xml->read() && (xml->getNodeType() != EXN_ELEMENT))
	{
		if (xml->getNodeType() == EXN_NONE)
		{ OTLog::Output(0, "*** OTContract::SkipToElement: EXN_NONE  (skipping)\n"); continue; }			// SKIP
		else if (xml->getNodeType() == EXN_COMMENT)
		{ OTLog::Output(0, "*** OTContract::SkipToElement: EXN_COMMENT  (skipping)\n"); continue; }			// SKIP
		else if (xml->getNodeType() == EXN_ELEMENT_END)
		{ OTLog::Output(0, "*** OTContract::SkipToElement: EXN_ELEMENT_END  (ERROR)\n");  return false; }
		else if (xml->getNodeType() == EXN_CDATA)
		{ OTLog::Output(0, "*** OTContract::SkipToElement: EXN_CDATA (ERROR -- unexpected CData)\n"); return false; }
		else if (xml->getNodeType() == EXN_TEXT)
		{ OTLog::Error("*** OTContract::SkipToElement: EXN_TEXT\n"); return false; }
		else if (xml->getNodeType() == EXN_ELEMENT)
		{ OTLog::Output(0, "*** OTContract::SkipToElement: EXN_ELEMENT\n"); break; }  // (Should never happen due to while() second condition.) Still returns true.
		else
		{ OTLog::Error("*** OTContract::SkipToElement: SHOULD NEVER HAPPEN  (Unknown element type!)\n"); return false; }	// Failure / Error
	}	
	// ------------------
	
	return true;
}

bool OTContract::SkipToTextField(IrrXMLReader*& xml)
{
	OT_ASSERT_MSG(NULL != xml, "OTContract::SkipToTextField -- assert: NULL != xml");
	
	// ------------------
	while(xml->read() && (xml->getNodeType() != EXN_TEXT))
	{
		if (xml->getNodeType() == EXN_NONE)
		{ OTLog::Output(0, "*** OTContract::SkipToTextField: EXN_NONE  (skipping)\n"); continue; }			// SKIP
		else if (xml->getNodeType() == EXN_COMMENT)
		{ OTLog::Output(0, "*** OTContract::SkipToTextField: EXN_COMMENT  (skipping)\n"); continue; }		// SKIP
		else if (xml->getNodeType() == EXN_ELEMENT_END)
		{ OTLog::Output(0, "*** OTContract::SkipToTextField: EXN_ELEMENT_END  (ERROR)\n");  return false; }
		else if (xml->getNodeType() == EXN_CDATA)
		{ OTLog::Output(0, "*** OTContract::SkipToTextField: EXN_CDATA (ERROR -- unexpected CData)\n"); return false; }
		else if (xml->getNodeType() == EXN_ELEMENT)
		{ OTLog::Output(0, "*** OTContract::SkipToTextField: EXN_ELEMENT\n"); return false; }
		else if (xml->getNodeType() == EXN_TEXT)
		{ OTLog::Error("*** OTContract::SkipToTextField: EXN_TEXT\n"); break; } // (Should never happen due to while() second condition.) Still returns true.
		else
		{ OTLog::Error("*** OTContract::SkipToTextField: SHOULD NEVER HAPPEN  (Unknown element type!)\n"); return false; }	// Failure / Error
	}	
	// ------------------
	
	return true;
}

// ---------------
// AFTER you read an element or text field, there is some whitespace, and you 
// just want to bring your cursor back to wherever it should be for the next guy.
// So you call this function..
//
bool OTContract::SkipAfterLoadingField(IrrXMLReader*& xml)
{
	OT_ASSERT_MSG(NULL != xml, "OTContract::SkipAfterLoadingField -- assert: NULL != xml");
	
	if (EXN_ELEMENT_END != xml->getNodeType())  // If we're not ALREADY on the ending element, then go there.
	{
		// move to the next node which SHOULD be the expected element_end.
		//
		while(xml->read())
		{
			if (xml->getNodeType() == EXN_NONE)
			{ OTLog::Output(0, "*** OTContract::SkipAfterLoadingField: EXN_NONE  (skipping)\n"); continue; }		// SKIP
			else if (xml->getNodeType() == EXN_COMMENT)
			{ OTLog::Output(0, "*** OTContract::SkipAfterLoadingField: EXN_COMMENT  (skipping)\n"); continue; }		// SKIP
			else if (xml->getNodeType() == EXN_ELEMENT_END)
			{ OTLog::Output(5, "*** OTContract::SkipAfterLoadingField: EXN_ELEMENT_END  (success)\n");  break; }	// Success...
			else if (xml->getNodeType() == EXN_CDATA)
			{ OTLog::Output(0, "*** OTContract::SkipAfterLoadingField: EXN_CDATA  (Unexpected!)\n"); return false; } // Failure / Error
			else if (xml->getNodeType() == EXN_ELEMENT)
			{ OTLog::Output(0, "*** OTContract::SkipAfterLoadingField: EXN_ELEMENT  (Unexpected!)\n"); return false; }		// Failure / Error
			else if (xml->getNodeType() == EXN_TEXT)
			{ OTLog::Error("*** OTContract::SkipAfterLoadingField: EXN_TEXT  (Unexpected!)\n"); return false; }		// Failure / Error
			else
			{ OTLog::Error("*** OTContract::SkipAfterLoadingField: SHOULD NEVER HAPPEN  (Unknown element type!)\n"); return false; }	// Failure / Error
		}	
	}
	// ------------------
	// else ... (already on the ending element.)
	//
	// ------------------
	
	return true;
}


// Loads it up and also decodes it to a string.
//
bool OTContract::LoadEncodedTextField(IrrXMLReader*& xml, OTString & strOutput)
{
	OTASCIIArmor ascOutput;
	
	if (OTContract::LoadEncodedTextField(xml, ascOutput) && ascOutput.GetLength() > 2)
	{
		return ascOutput.GetString(strOutput, true); // linebreaks = true
	}
	
	return false;
}

// ---------------

bool OTContract::LoadEncodedTextField(IrrXMLReader*& xml, OTASCIIArmor & ascOutput)
{
	OT_ASSERT_MSG(NULL != xml, "OTContract::LoadEncodedTextField -- assert: NULL != xml");	
	
	// ------------------
	// If we're not ALREADY on a text field, maybe there is some whitespace, so let's skip ahead...
	//
	if (EXN_TEXT != xml->getNodeType())  
	{
		// move to the next node which SHOULD be the expected text field.
		//
		if (false == SkipToTextField(xml))
		{
			OTLog::Output(0, "OTContract::LoadEncodedTextField: Failure: Unable to find expected text field.\n");
			return false;
		}
	}
	// ------------------
	//
	if (EXN_TEXT == xml->getNodeType())  // SHOULD always be true, in fact this could be an assert().
	{
		OTString strNodeData = xml->getNodeData();
		
		// Sometimes the XML reads up the data with a prepended newline.
		// This screws up my own objects which expect a consistent in/out
		// So I'm checking here for that prepended newline, and removing it.
		//
		char cNewline;
		if (strNodeData.Exists() && strNodeData.GetLength() > 2 && strNodeData.At(0, cNewline))
		{
			if ('\n' == cNewline)
			{
				ascOutput.Set(strNodeData.Get() + 1);
			}
			else
			{
				ascOutput.Set(strNodeData.Get());
			}
			
			// ----------------------------------------
			// SkipAfterLoadingField() only skips ahead if it's not ALREADY
			// sitting on an element_end node. 
			//
			xml->read(); // THIS PUTS us on the CLOSING TAG.  <========================
			// The below call won't advance any further if it's ALREADY on the closing tag (e.g. from the above xml->read() call.)
			if (false == SkipAfterLoadingField(xml))
			{ OTLog::Output(0, "*** OTContract::LoadEncodedTextField: Bad data? Expected EXN_ELEMENT_END here, but "
							"didn't get it. Returning false.\n"); return false; }
			return true;
		}
	}
	else 
		OTLog::Output(0, "OTContract::LoadEncodedTextField: Failure: Unable to find expected text field. 2\n");
	
	return false;
}

// ---------------


// Loads it up and also decodes it to a string.
bool OTContract::LoadEncodedTextFieldByName(IrrXMLReader*& xml, OTString & strOutput, 
											const char *& szName, mapOfStrings * pmapExtraVars/*=NULL*/)
{
	OT_ASSERT(NULL != szName);
	
	OTASCIIArmor ascOutput;
	
	if (OTContract::LoadEncodedTextFieldByName(xml, ascOutput, szName, pmapExtraVars) && ascOutput.GetLength() > 2)
	{
		return ascOutput.GetString(strOutput, true); // linebreaks = true
	}
	
	return false;
}

// Loads it up and keeps it encoded in an ascii-armored object.
bool OTContract::LoadEncodedTextFieldByName(IrrXMLReader*& xml, OTASCIIArmor & ascOutput, 
											const char *& szName, mapOfStrings * pmapExtraVars/*=NULL*/)
{
	OT_ASSERT(NULL != szName);

	const char * pElementExpected = szName;
	
	// ------------------
	// If we're not ALREADY on an element, maybe there is some whitespace, so let's skip ahead...
	//
	if ((EXN_ELEMENT != xml->getNodeType()) ||			// If we're not already on a node, OR if the node's
		!(strcmp(pElementExpected, xml->getNodeName()) == 0) )	// name doesn't match the one expected.
	{
		// move to the next node which SHOULD be the expected name.
		//
		if (false == SkipToElement(xml))
		{
			OTLog::vOutput(0, "OTContract::LoadEncodedTextFieldByName: Failure: Unable to find expected element: %s. \n",
						   szName);
			return false;
		}
	}
	// ------------------		
	if (EXN_ELEMENT == xml->getNodeType())  // SHOULD always be true...
	{
		if (!strcmp(pElementExpected, xml->getNodeName()))
		{
			// ----------------------------------------

			if (NULL != pmapExtraVars) // If the caller wants values for certain names expected to be on this node.
			{
				mapOfStrings & mapExtraVars = (*pmapExtraVars);
				
				FOR_EACH(mapOfStrings, mapExtraVars)
				{		

					std::string first	= ((*it).first);
//					std::string second	= ((*it).second);

					OTString strTemp = xml->getAttributeValue(first.c_str());

					if (strTemp.Exists())
					{
						mapExtraVars[first] = strTemp.Get();
						
//						mapExtraVars.erase(first);
//						mapExtraVars.insert(std::pair<std::string, std::string>(first, strTemp.Get()));
					}
				}
			} // Any attribute names passed in, now have their corresponding values set on mapExtraVars (for caller.)
			
			// ----------------------------------------
			
			if (false == OTContract::LoadEncodedTextField(xml, ascOutput)) // <====================================================
			{
				OTLog::vError("OTContract::LoadEncodedTextFieldByName: Error loading %s field.\n",
							  pElementExpected);
				return false; // error condition
			}
			else 
			{
				// ----------------------------------------
				// SkipAfterLoadingField() only skips ahead if it's not ALREADY
				// sitting on an element_end node. 
				//
				// Update: Above, LoadEncodedTextField() already does this (below).
				//
//				if (false == SkipAfterLoadingField(xml))
//				{ OTLog::Output(0, "*** OTContract::LoadEncodedTextFieldByName: Bad data? Expected EXN_ELEMENT_END here, but "
//								"didn't get it. Returning false.\n"); return false; }
				
				return true;  // <============ SUCCESS!!!!
			}
		}
		else 
		{
			OTLog::vError("Error in OTContract::LoadEncodedTextFieldByName:"
						  " missing %s element.\n", pElementExpected);
			return false; // error condition
		}
	}
	else
	{
		OTLog::vError("Error in OTContract::LoadEncodedTextFieldByName:"
					  " Expected %s element with text field.\n", 
					  pElementExpected);
		return false; // error condition
	}
	
	return false;
}



// ---------------------------------------------------------------------


// return -1 if error, 0 if nothing, and 1 if the node was processed.
int OTContract::ProcessXMLNode(IrrXMLReader*& xml)
{
	OTString strEntityShortName;
	OTString strEntityLongName;
	OTString strEntityEmail;
	
	OTString strConditionName;
	OTString strConditionValue;
	
	OTString strKeyName;
	OTString strKeyValue;
	
    const OTString strNodeName(xml->getNodeName());
    
	if (strNodeName.Compare("entity"))
	{					
//		strEntityShortName = xml->getAttributeValue("shortname");
		if (!m_strName.Exists()) // only set it if it's not already set, since the wallet may have already had a user label set.
			m_strName = xml->getAttributeValue("shortname");	// m_strName may later be changed again in OTAssetContract::ProcessXMLNode
		strEntityLongName = xml->getAttributeValue("longname"); 
		strEntityEmail = xml->getAttributeValue("email");
		
		OTLog::vOutput(1, "Loaded Entity, shortname: %s\nLongname: %s, email: %s\n----------\n", 
				strEntityShortName.Get(), strEntityLongName.Get(), strEntityEmail.Get());

		return 1;
	}
	else if (strNodeName.Compare("condition"))
	{
		strConditionName  = xml->getAttributeValue("name");
		
//		xml->read();
		// ------------------		
		if (false == SkipToTextField(xml))
		{
			OTLog::vOutput(0, "OTContract::ProcessXMLNode: Failure: Unable to find expected text field for xml node named: %s\n",
						  xml->getNodeName());
			return (-1); // error condition
		}
		// ------------------
		
		if (EXN_TEXT == xml->getNodeType())
		{
			strConditionValue = xml->getNodeData();
		}
		else {
			OTLog::vError("Error in OTContract::ProcessXMLNode: Condition without value: %s\n",
					strConditionName.Get());
			return (-1); // error condition
		}
		
		//Todo: add the conditions to a list in memory (on this object)
		
		OTLog::vOutput(1, "---- Loaded condition \"%s\"\n", strConditionName.Get());
//		OTLog::vOutput(1, "Loading condition \"%s\": %s----------(END DATA)----------\n", strConditionName.Get(), 
//				strConditionValue.Get());
		
		return 1;
	}
	else if (strNodeName.Compare("key"))
	{
		strKeyName  = xml->getAttributeValue("name");
		
//		xml->read();
		// ------------------		
		if (false == SkipToTextField(xml))
		{
			OTLog::vOutput(0, "OTContract::ProcessXMLNode: Failure: Unable to find expected text "
                           "field for xml node named: %s\n", xml->getNodeName());
			return (-1); // error condition
		}
		// ------------------
		
		if (EXN_TEXT == xml->getNodeType())
		{
			strKeyValue = xml->getNodeData();
		}
		else 
        {
			OTLog::vError("Error in OTContract::ProcessXMLNode: Key without value: %s\n",
					strKeyName.Get());
			return (-1); // error condition
		}
		
		// Create a new nym for this public key (or x509 cert, it works either way)
		// and add it to the contract's internal list of nyms.
		// 
		// Later on, if someone needs to get the Public Key for this contract and
		// use it to verify the signature on the contract, or to verify a message
		// from the server, the contract can iterate the list of Nyms and get
		// the public contract key based on a standard name such as the "contract" key.
		// (Versus the "server" key or the "certification" key, etc.
		
		if (!InsertNym(strKeyName, strKeyValue))
			OTLog::Error("Error performing OTContract::InsertNym.\n");

		return 1;
	}
	
	return 0;
}


// If you have a Public Key or Cert that you would like to add as one of the keys on this contract,
// just call this function. Usually you'd never want to do that because you would never want to actually
// change the text of the contract (or the signatures will stop verifying.)
// But in unique situations, for example when first creating a contract, you might want to insert some
// keys into it.  You might also call this function when LOADING the contract, to populate it.
bool OTContract::InsertNym(const OTString & strKeyName, const OTString & strKeyValue)
{
	bool bResult		= false;
	OTPseudonym * pNym	= new OTPseudonym;
	
	OT_ASSERT_MSG(NULL != pNym, "Error allocating memory for new Nym in OTContract::InsertNym\n");
	
	// This is the version of SetCertificate that handles escaped bookends. ( - -----BEGIN CERTIFICATE-----)
	if (strKeyValue.Contains("CERTIFICATE") && pNym->SetCertificate(strKeyValue, true)) // it also defaults to true, FYI.
	{											
		m_mapNyms[strKeyName.Get()] = pNym;
		pNym->SetIdentifierByPubkey();
		OTLog::vOutput(1, "---- Loaded certificate \"%s\"\n", strKeyName.Get());
		bResult = true;
	}			
	else if (strKeyValue.Contains("PUBLIC KEY") && pNym->SetPublicKey(strKeyValue, true)) // it also defaults to true, FYI.
	{											
		m_mapNyms[strKeyName.Get()] = pNym;	
		pNym->SetIdentifierByPubkey();
		OTLog::vOutput(1, "---- Loaded public key \"%s\"\n", strKeyName.Get());
		bResult = true;
	}	
	else
	{
		delete pNym;
		pNym = NULL;
		OTLog::vOutput(0, "\nLoaded key \"%s\" but FAILED adding the Nym to the Contract:\n--->%s<---\n",
				strKeyName.Get(), strKeyValue.Get());
	}

	return bResult;
}



/*
 * An implementation of RSA PSS digital signature using OpenSSL
 *
 * Copyright (c) 2009 Mounir IDRASSI <mounir.idrassi@idrix.fr>. All rights reserved.
 *
 * This program is distributed in the hope that it will be useful, 
 * but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY 
 * or FITNESS FOR A PARTICULAR PURPOSE.
 * 
 */
/*
// inside a comment here #include <stdio.h>
// inside a comment here #include <string.h>
#include <openssl/err.h>
#include <openssl/evp.h>
#include <openssl/rsa.h>
#include <openssl/rand.h>


int main(int argc, char** argv)
{
	RSA* pRsaKey = NULL;
	unsigned char pDigest[32];
	size_t uDigestLen = 32;
	const char* szMessage = "This is the string to be signed";
	EVP_MD_CTX md_ctx;
	unsigned char EM[128];
	unsigned char pSignature[128];
	unsigned char pDecrypted[128];
	int status = 0;
	
	// openssl initialization
	ERR_load_crypto_strings(); 
	OpenSSL_add_all_algorithms();
	
#ifdef _WIN32
	RAND_screen();      
#else
	RAND_poll();
#endif
	
	// Generate an RSA key pair
	pRsaKey = RSA_generate_key(1024, 0x010001, NULL, NULL);
	if (!pRsaKey)
	{
		printf("RSA_generate_key failed with error %s\n", ERR_error_string(ERR_get_error(), NULL));
		goto prog_end;
	}
	
	// hash the message
	EVP_MD_CTX_init(&md_ctx);
	EVP_DigestInit(&md_ctx, EVP_sha256());
	EVP_DigestUpdate(&md_ctx, (const void*) szMessage, strlen(szMessage));
	EVP_DigestFinal(&md_ctx, pDigest, &uDigestLen);
	EVP_MD_CTX_cleanup(&md_ctx);
	
	// compute the PSS padded data
	status = RSA_padding_add_PKCS1_PSS(pRsaKey, EM, pDigest, EVP_sha256(), -2); //maximum salt length
	if (!status)  
	{
		printf("RSA_padding_add_PKCS1_PSS failed with error %s\n", ERR_error_string(ERR_get_error(), NULL));
		goto prog_end;      
	}
	
	// perform digital signature
	status = RSA_private_encrypt(128, EM, pSignature, pRsaKey, RSA_NO_PADDING);
	if (status == -1)
	{
		printf("RSA_private_encrypt failed with error %s\n", ERR_error_string(ERR_get_error(), NULL));
		goto prog_end;      
	}
	
	// now we will verify the signature 
	// Start by a RAW decrypt of the signature
	status = RSA_public_decrypt(128, pSignature, pDecrypted, pRsaKey, RSA_NO_PADDING);
	if (status == -1)
	{
		printf("RSA_public_decrypt failed with error %s\n", ERR_error_string(ERR_get_error(), NULL));
		goto prog_end;      
	}
	
	// verify the data
	status = RSA_verify_PKCS1_PSS(pRsaKey, pDigest, EVP_sha256(), pDecrypted, -2); // salt length recovered from signature
	if (status == 1)
	{
		printf("Signature verification successfull!\n");
	}
	else
	{
		printf("RSA_verify_PKCS1_PSS failed with error %s\n", ERR_error_string(ERR_get_error(), NULL));
		goto prog_end;            
	}
	
prog_end:
	if (pRsaKey)
		RSA_free(pRsaKey);
	
	// openssl cleanup
	CRYPTO_cleanup_all_ex_data();
	RAND_cleanup();
	EVP_cleanup();
	ERR_free_strings();
	ERR_remove_state(0);
	
	return 0;
}
*/






























