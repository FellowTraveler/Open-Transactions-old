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



//static
bool OTContract::DearmorAndTrim(const OTString & strInput, OTString & strOutput, OTString & strFirstLine)
{
    const char * szFunc = "OTContract::DearmorAndTrim";
    // --------------------------
	if (!strInput.Exists())
		return false;
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
        
        OTLog::vError("%s: Armored and escaped value passed in, "
                      "but escaped are forbidden here. (Returning false.)\n", szFunc);
		return false;
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
        OTString strInputTemp(strInput);
        
        if (false == (ascTemp.LoadFromString(strInputTemp,
                                             bArmoredAndALSOescaped, // if it IS escaped or not, this variable will be true or false to show it.
                                             // The below szOverride sub-string determines where the content starts, when loading.
                                             OT_BEGIN_ARMORED)))     // Default is:       "-----BEGIN"
            // We're doing this: "-----BEGIN OT ARMORED" (Should worked for escaped as well, here.)
        {
            OTLog::vError("%s: Error "
                          "loading string contents from ascii-armored encoding. Contents: \n%s\n",
                          szFunc, strInput.Get());
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
        std::string str_temp(strInput.Get(), strInput.GetLength());
        str_Trim = OTString::trim(str_temp); // This is the std::string for the trim process. (Wasn't armored, so here we use it as passed in.)
    }
    // ------------------------------------------------
    // At this point, str_Trim contains the actual contents, whether they
    // were originally ascii-armored OR NOT. (And they are also now trimmed, either way.)
    // ------------------------------------------
    strOutput.Set(str_Trim.c_str());
	
    strOutput.reset(); // for sgets
    
    static char		buf[75] = "";
	buf[0] = 0; // probably unnecessary.
	bool bGotLine = strOutput.sgets(buf, 70);
    
	if (!bGotLine)
		return false;
	
	strFirstLine.Set(buf);
	strOutput.reset(); // set the "file" pointer within this string back to index 0.
	
	// Now I feel pretty safe -- the string I'm examining is within
	// the first 70 characters of the beginning of the contract, and
	// it will NOT contain the escape "- " sequence. From there, if
	// it contains the proper sequence, I will instantiate that type.
	if (!strFirstLine.Exists() || strFirstLine.Contains("- -"))
		return false;
    
    return true;
}


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
    const char * szFunc = "OTContract::InstantiateContract";
    // --------------------------------------------------------------------
    OTString   strContract, strFirstLine; // output for the below function.
    const bool bProcessed = OTContract::DearmorAndTrim(strInput, strContract, strFirstLine);
    // --------------------------------------------------------------------
    if (bProcessed)
    {
        // -----------------------------------------------------------
        OTContract * pContract = NULL;
        
//      if (strFirstLine.Contains("-----BEGIN SIGNED AGREEMENT-----"))  // this string is 32 chars long.
//      {	pContract = new OTAgreement();		OT_ASSERT(NULL != pContract); }
	
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
        {	pContract = OTToken::LowLevelInstantiate(strFirstLine); OT_ASSERT(NULL != pContract); }
        
        else if (strFirstLine.Contains("-----BEGIN SIGNED CASH TOKEN-----"))
        {	pContract = OTToken::LowLevelInstantiate(strFirstLine); OT_ASSERT(NULL != pContract); }
        
        else if (strFirstLine.Contains("-----BEGIN SIGNED LUCRE CASH TOKEN-----"))
        {	pContract = OTToken::LowLevelInstantiate(strFirstLine); OT_ASSERT(NULL != pContract); }
    
	
        // The Purse object requires the asset type ID in order to be instantiated.
        // I may remove this requirement (if possible) or not.
//	
//      else if (strFirstLine.Contains("-----BEGIN SIGNED PURSE-----")) 
//      {	pContract = new OTPurse();			OT_ASSERT(NULL != pContract); }
	
	
        // THESE OBJECTS REQUIRE YOU TO KNOW THE SERVER ID, USER ID, AND ACCT ID,
        // IN ORDER TO GENERATE A NEW INSTANCE, OR TO LOAD AN EXISTING ONE.
        // THUS, I AM REMOVING THEM FROM HERE FOR NOW.
        // DONE: ADD A OTTransactionType class factory (like I did for CronItem)
        // and then create these in there instead.
        //
//      else if (strFirstLine.Contains("-----BEGIN SIGNED ACCOUNT-----"))
//      {	pContract = new OTAccount();		OT_ASSERT(NULL != pContract); }	
//      else if (strFirstLine.Contains("-----BEGIN SIGNED LEDGER-----")) 
//      {	pContract = new OTLedger();			OT_ASSERT(NULL != pContract); }
//	
//      else if (strFirstLine.Contains("-----BEGIN SIGNED TRANSACTION-----")) 
//      {	pContract = new OTTransaction();	OT_ASSERT(NULL != pContract); }
//	
//      else if (strFirstLine.Contains("-----BEGIN SIGNED TRANSACTION ITEM-----")) 
//      {	pContract = new OTItem();			OT_ASSERT(NULL != pContract); }
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
        //
        if (NULL == pContract)
            OTLog::vOutput(0, "%s: Object type not yet supported by class factory: %s\n",
                           szFunc, strFirstLine.Get());
        // Does the contract successfully load from the string passed in?
        else if (false == pContract->LoadContractFromString(strContract))
        {
            OTLog::vOutput(0, "%s: Failed loading contract from string (first line): %s\n",
                           szFunc, strFirstLine.Get());
            delete pContract;
            pContract = NULL;
        }
        else
            return pContract;
	}
	return NULL;
}







// ----------------------------------------------------------------------------------------
//
// OTNumList (helper class.)
//

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

OTNumList::OTNumList(const std::string & strNumbers)
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

bool OTNumList::Add(const std::string & strNumbers)  // if false, means the numbers were already there. (At least one of them.)
{
    return Add(strNumbers.c_str());
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
    bool bStartedANumber = false; // During the loop, set this to true when processing a digit, and set to false when anything else. That way when we go to add the number to the list, and it's "0", we'll know it's a real number we're supposed to add, and not just a default value.
    
    while (1) // We already know it's not null, due to the assert. (So at least one iteration will happen.)
    {
        if (std::isdigit(*pChar))
        {
            bStartedANumber = true;
            
            int nDigit = (*pChar - '0');
            
            lNum *= 10;  // Move it up a decimal place.
            lNum += nDigit;
        }
        // if separator, or end of string, either way, add lNum to *this. 
        else if ((',' == *pChar) || ('\0' == *pChar) || std::isspace(*pChar)) // first sign of a space, and we are done with current number. (On to the next.)
        {
            if ((lNum > 0) || (bStartedANumber && (0 == lNum)))
            {
                if (false == this->Add(lNum)) // <=========
                {
                    bSuccess = false; // We still go ahead and try to add them all, and then return this sort of status when it's all done.
                }
            }
            // ------------------
            lNum = 0;   // reset for the next transaction number (in the comma-separated list.)
            bStartedANumber = false; // reset
        }
        else
        {
            OTLog::vError("OTNumList::Add: Error: Unexpected character found in erstwhile comma-separated list of longs: %c\n",
                          *pChar);
            bSuccess = false;
            break;
        }
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

bool OTNumList::Peek(long & lPeek) const
{
    std::set<long>::iterator it = m_setData.begin();
    
    if (m_setData.end() != it) // it's there.
    {
        lPeek = *it;
        return true;
    }
    return false;
}
// -------------------

bool OTNumList::Pop()
{
    std::set<long>::iterator it = m_setData.begin();
    
    if (m_setData.end() != it) // it's there.
    {
        m_setData.erase(it);
        return true;
    }
    return false;
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


// -------------------------------------------------------------------------------


int OTNumList::Count() const 
{ 
    return static_cast<int> (m_setData.size()); 
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


// -------------------------------------------------------------------------------


OTContract::OTContract(const OTString & name, const OTString & foldername, const OTString & filename, const OTString & strID)
{
	Initialize();
	
	m_strName			= name;
	m_strFoldername		= foldername;
	m_strFilename		= filename;
	
	m_ID.SetString(strID);
}


// -------------------------------------------------------------------------------


OTContract::OTContract(const OTString & strID)
{
	Initialize();
	
	m_ID.SetString(strID);
}


// -------------------------------------------------------------------------------


OTContract::OTContract(const OTIdentifier & theID)
{
	Initialize();
	
	m_ID = theID;
}


// -------------------------------------------------------------------------------


void OTContract::Initialize()
{
	m_strContractType	= "CONTRACT";	// CONTRACT, MESSAGE, TRANSACTION, LEDGER, TRANSACTION ITEM 
	// make sure subclasses set this in their own initialization routine.
	
	m_strSigHashType	= OTIdentifier::DefaultHashAlgorithm;
	m_strVersion		= "1.0";
}


// -------------------------------------------------------------------------------


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


// -------------------------------------------------------------------------------


void OTContract::Release()
{	
	Release_Contract();
    
    // No call to ot_super::Release() here, since OTContract
    // is the base class.
}


// -------------------------------------------------------------------------------


OTContract::~OTContract()
{	
	
	Release_Contract();
}



// -------------------------------------------------------------------------------


	
bool OTContract::SaveToContractFolder()
{
	OTString strFoldername(OTFolders::Contract().Get()), strFilename;
	
	GetIdentifier(strFilename);

	// -------------------------------------
	// These are already set in SaveContract(), called below.
//	m_strFoldername	= strFoldername;
//	m_strFilename	= strFilename;
	
	OTLog::Output(2, "OTContract::SaveToContractFolder: Saving asset contract to disk...\n");
	
	return SaveContract(strFoldername.Get(), strFilename.Get());
}



// -------------------------------------------------------------------------------



void OTContract::GetFilename(OTString & strFilename)
{
	strFilename = m_strFilename;
}


// -------------------------------------------------------------------------------


void OTContract::GetIdentifier(OTIdentifier & theIdentifier)
{
	theIdentifier = m_ID;
}


// -------------------------------------------------------------------------------


void OTContract::GetIdentifier(OTString & theIdentifier)
{
	m_ID.GetString(theIdentifier);
}


// -------------------------------------------------------------------------------



// Make sure this contract checks out. Very high level. 
// Verifies ID, existence of public key, and signature.
//
bool OTContract::VerifyContract()
{
    const char *szFunc = "OTContract::VerifyContract";
    
	// Make sure that the supposed Contract ID that was set is actually
	// a hash of the contract file, signatures and all.
	if (false == VerifyContractID())
	{
		OTLog::vOutput(1, "%s: Failed verifying contract ID.\n", szFunc);
		return false;
	}
	
	// Make sure we are able to read the official "contract" public key out of this contract.
	const OTPseudonym * pNym = this->GetContractPublicNym();

	if (NULL == pNym)
	{
		OTLog::vOutput(0, "%s: Failed retrieving public nym from contract.\n", szFunc);
		return false;
	}
	
	if (false == this->VerifySignature(*pNym))
	{
        const OTIdentifier theNymID(*pNym);
        const OTString     strNymID(theNymID);
		OTLog::vOutput(0, "%s: Failed verifying the contract's signature "
                      "against the public key that was retrieved from the contract, with key ID: %s\n",
                      szFunc, strNymID.Get());
		return false;
	}

	
	OTLog::Output(1, "\nVerified -- The Contract ID from the wallet matches the newly-calculated hash of the contract file.\n"
			"Verified -- A standard \"contract\" Public Key or x509 Cert WAS found inside the contract.\n"
			"Verified -- And the **SIGNATURE VERIFIED** with THAT key.\n\n");
	return true;
}

// -------------------------------------------------------------------------------



void OTContract::CalculateContractID(OTIdentifier & newID) const
{
//	OTLog::vError("DEBUG CalculateContractID:\n--->%s<---\n", m_strRawFile.Get());
	
//	// may be redundant...	
	std::string str_Trim(m_strRawFile.Get());
	std::string str_Trim2 = OTString::trim(str_Trim);

	OTString strTemp(str_Trim2.c_str());
	
	newID.CalculateDigest(strTemp);
}


// -------------------------------------------------------------------------------


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
    //
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
	else
    {
		OTString str1;
		newID.GetString(str1);
		OTLog::vOutput(1, "\nContract ID *SUCCESSFUL* match to %s hash of contract file:\n%s\n\n",
				OTIdentifier::DefaultHashAlgorithm.Get(), str1.Get());
		return true;
	}
}

// -------------------------------------------------------------------------------


		
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

// -------------------------------------------------------------------------------



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


// -------------------------------------------------------------------------------


void OTContract::UpdateContents()
{
	// Deliberately left blank.
	//
	// Some child classes may need to perform work here
	// (OTAccount and OTMessage, for example.)
	//
	// This function is called just prior to the signing of a contract.
}

// -------------------------------------------------------------------------------

// This is the one that you will most likely want to call.
// It actually attaches the resulting signature to this contract.
// If you want the signature to remain on the contract and be handled
// internally, then this is what you should call.
//
bool OTContract::SignContract(const OTPseudonym & theNym,
                              OTPasswordData    * pPWData/*=NULL*/)
{
    const char * szFunc = "OTContract::SignContract";
    // --------------------------------
	OTSignature * pSig = new OTSignature();
	OT_ASSERT_MSG(NULL != pSig, "OTContract::SignContract: Error allocating memory for Signature.\n");
    // --------------------------------
	bool bSigned = this->SignContract(theNym, *pSig, pPWData);

	if (bSigned)
		m_listSignatures.push_back(pSig);
	else 
	{
        OTLog::vError("%s: Failure while calling this->SignContract(theNym, *pSig).\n", szFunc);
		delete pSig; pSig = NULL;
	}
    // --------------------------------
	return bSigned;
}

// -------------------------------------------------------------------------------

// The output signature will be in theSignature.
// It is NOT attached to the contract.  This is just a utility function.
bool OTContract::SignContract(const OTPseudonym & theNym,
                              OTSignature       & theSignature,
                              OTPasswordData    * pPWData/*=NULL*/)
{
	return this->SignContract(theNym.GetPrivateKey(), theSignature, m_strSigHashType, pPWData);
}

// -------------------------------------------------------------------------------

// Normally you'd use OTContract::SignContract(const OTPseudonym & theNym)...
// Normally you WOULDN'T use this function SignWithKey.
// But this is here anyway for those peculiar places where you need it. For example,
// when first creating a Nym, you generate the master credential as part of creating
// the Nym, and the master credential has to sign itself, and it therefore needs to be
// able to "sign a contract" at a high level using purely the key, without having the Nym
// ready yet to signing anything with.
//
bool OTContract::SignWithKey(const OTAsymmetricKey & theKey,
                                   OTPasswordData  * pPWData/*=NULL*/)
{
    const char * szFunc = "OTContract::SignWithKey";
    // --------------------------------
	OTSignature * pSig = new OTSignature();
	OT_ASSERT_MSG(NULL != pSig, "OTContract::SignWithKey: Error allocating memory for Signature.\n");
    // --------------------------------
	bool bSigned = this->SignContract(theKey, *pSig, m_strSigHashType, pPWData);
    
	if (bSigned)
		m_listSignatures.push_back(pSig);
	else
	{
        OTLog::vError("%s: Failure while calling this->SignContract(theNym, *pSig).\n", szFunc);
		delete pSig; pSig = NULL;
	}
    // --------------------------------
	return bSigned;
}


// Done: When signing a contract, need to record the metadata into the signature object here.

// We will know if the key is signing, authentication, or encryption key because?
// Because we used the Nym to choose it! In which case we should have a default option,
// and also some other function with a new name that calls SignContract and CHANGES that default
// option.
// For example, SignContract(bool bUseAuthenticationKey=false)
// Then: SignContractAuthentication() { return SignContract(true); }
//
// In most cases we actually WILL want the signing key, since we are actually signing contracts
// such as cash withdrawals, etc. But when the Nym stores something for himself locally, or when
// sending messages, those will use the authentication key.
//
// We'll also have the ability to SWITCH the key which is important because it raises the
// question, how do we CHOOSE the key? On my phone I might use a different key than on my iPad.
// theNym should either know already (GetPrivateKey being intelligent) or it must be passed in
// (Into the below versions of SignContract.)
//
// If theKey knows its type (A|E|S) the next question is, does it know its other metadata?
// It certainly CAN know, can't it? Especially if it's being loaded from credentials in the
// first place. And if not, well then the data's not there and it's not added to the signature.
// (Simple.) So I will put the Signature Metadata into its own class, so not only a signature
// can use it, but also the OTAsymmetricKey class can use it and also OTSubcredential can use it.
// Then OTContract just uses it if it's there. Also we don't have to pass it in here as separate
// parameters. At most we have to figure out which private key to get above, in theNym.GetPrivateKey()
// Worst case maybe put a loop, and see which of the private keys inside that Nym, in its credentials,
// is actually loaded and available. Then just have GetPrivateKey return THAT one. Similarly, later
// on, in VerifySignature, we'll pass the signature itself into the Nym so that the Nym can use it
// to help search for the proper public key to use for verifying, based on that metadata.
//
// This is all great because it means the only real change I need to do here now is to see if
// theKey.HasMetadata and if so, just copy it directly over to theSignature's Metadata.
//





// The output signature will be in theSignature.
// It is NOT attached to the contract.  This is just a utility function.
//
bool OTContract::SignContract(const OTAsymmetricKey & theKey,
                                    OTSignature     & theSignature,
                              const OTString        & strHashType,
                                    OTPasswordData  * pPWData/*=NULL*/)
{
    const char * szFunc = "OTContract::SignContract";
    // -------------------------------------------------
    // We assume if there's any important metadata, it will already
    // be on the key, so we just copy it over to the signature.
    //
    if (NULL != theKey.m_pMetadata)
    {
        theSignature.m_metadata = *(theKey.m_pMetadata);
    }
    // -------------------------------------------------
    // Update the contents, (not always necessary, many contracts are read-only)
	// This is where we provide an overridable function for the child classes that
	// need to update their contents at this point. 
	// But the OTContract version of this function is actually empty, since the 
	// default behavior is that contract contents don't change.
	// (Accounts and Messages being two big exceptions.)
    //
	UpdateContents();
    // --------------------------------------------------------------------
    if (false == OTCrypto::It()->SignContract(m_xmlUnsigned,
                                              theKey,
                                              theSignature,
                                              strHashType,
                                              pPWData))
    {
		OTLog::vError("%s: OTCrypto::It()->SignContract returned false.\n",
                      szFunc);
		return false; 
    }
	// --------------------------------------------------------------------
    return true;
}

// -------------------------------------------------------------------------------

// Todo: make this private so we can see if anyone is calling it.
// Might want to ditch it if possible, since the metadata isn't
// stored in that cert file...

// Sign the Contract using a private key from a file.
// theSignature will contain the output.
bool OTContract::SignContract(const char     * szFoldername,
                              const char     * szFilename,    // for Certfile, for private key.
                              OTSignature    & theSignature,  // output
                              OTPasswordData * pPWData/*=NULL*/)
{	
	OT_ASSERT(NULL != szFoldername);
	OT_ASSERT(NULL != szFilename);
	// --------------------------------------------------------------------	    
    const char * szFunc = "OTContract::SignContract";
	// --------------------------------------------------------------------
	if (false == OTDB::Exists(szFoldername, szFilename))
	{
		OTLog::vError("%s: File does not exist: %s%s%s\n", szFunc,
					  szFoldername, OTLog::PathSeparator(), szFilename);
		return false;
	}
	// --------------------------------------------------------------------
    const std::string strCertFileContents(OTDB::QueryPlainString(szFoldername, szFilename)); // <=== LOADING FROM DATA STORE.
	
	if (strCertFileContents.length() < 2)
	{
		OTLog::vError("%s: Error reading file: %s%s%s\n", szFunc,
					  szFoldername, OTLog::PathSeparator(), szFilename);
		return false;
	}
	// --------------------------------------------------------------------
    OTPasswordData thePWData("(OTContract::SignContract is trying to read the private key...)");
    
    if (NULL == pPWData)
        pPWData = &thePWData;
    // --------------------------------------------------------------------
    // Update the contents, (not always necessary, many contracts are read-only)
	// This is where we provide an overridable function for the child classes that
	// need to update their contents at this point. 
	// But the OTContract version of this function is actually empty, since the 
	// default behavior is that contract contents don't change.
	// (Accounts and Messages being two big exceptions.)
    //
	UpdateContents();
    // --------------------------------------------------------------------
    if (false == OTCrypto::It()->SignContract(m_xmlUnsigned,
                                              m_strSigHashType,
                                              strCertFileContents,
                                              theSignature,
                                              pPWData))
    {
		OTLog::vError("%s: OTCrypto::It()->SignContract returned false, using Cert file: %s%s%s\n",
                      szFunc, szFoldername, OTLog::PathSeparator(), szFilename);
		return false; 
    }
	// --------------------------------------------------------------------
    return true;
}



// -------------------------------------------------------------------------------



// Presumably the Signature passed in here was just loaded as part of this contract and is
// somewhere in m_listSignatures. Now it is being verified.
//
bool OTContract::VerifySignature(const char        * szFoldername,
                                 const char        * szFilename, // for Cert.
                                 const OTSignature & theSignature,
                                 OTPasswordData    * pPWData/*=NULL*/) const // optional in/out
{
	OT_ASSERT_MSG(NULL != szFoldername, "Null foldername pointer passed to OTContract::VerifySignature");
	OT_ASSERT_MSG(NULL != szFilename,   "Null filename pointer passed to OTContract::VerifySignature");
	// --------------------------------------------------------------------	    	
    const char * szFunc = "OTContract::VerifySignature";
	// --------------------------------------------------------------------	    
	// Read public key
	OTLog::vOutput(2, "%s: Reading public key from certfile in order to verify signature...\n", szFunc); 
	// --------------------------------------------------------------------	
	if (false == OTDB::Exists(szFoldername, szFilename))
	{
		OTLog::vError("%s: File does not exist: %s%s%s\n", szFunc,
					  szFoldername, OTLog::PathSeparator(), szFilename);
		return false;
	}
	// --------------------------------------------------------------------
	const std::string strCertFileContents(OTDB::QueryPlainString(szFoldername, szFilename)); // <=== LOADING FROM DATA STORE.
	
	if (strCertFileContents.length() < 2)
	{
		OTLog::vError("%s: Error reading file: %s%s%s\n", szFunc,
					  szFoldername, OTLog::PathSeparator(), szFilename);
		return false;
	}
	// --------------------------------------------------------------------
    OTPasswordData thePWData("Reading the public key...");
    
    if (NULL == pPWData)
        pPWData = &thePWData;
    // --------------------------------------------------------------------
    if (false == OTCrypto::It()->VerifySignature(m_xmlUnsigned,
                                                 m_strSigHashType,
                                                 strCertFileContents,
                                                 theSignature,
                                                 pPWData))
    {
		OTLog::vOutput(4, "%s: OTCrypto::It()->VerifySignature returned false, using Cert file: %s%s%s\n",
                      szFunc, szFoldername, OTLog::PathSeparator(), szFilename);
		return false; 
    }
	// --------------------------------------------------------------------
    return true;
}
    


// -------------------------------------------------------------------------------


bool OTContract::VerifySignature(const OTPseudonym & theNym,
                                 OTPasswordData    * pPWData/*=NULL*/)
{
	FOR_EACH(listOfSignatures, m_listSignatures)
	{
		OTSignature * pSig = *it;
		OT_ASSERT(NULL != pSig);
		
		if (this->VerifySignature(theNym, *pSig, pPWData))
			return true;
	}
	
	return false;
}


// -------------------------------------------------------------------------------


// The only different between calling this with a Nym and calling it with an Asymmetric Key is that
// the key gives you the choice of hash algorithm, whereas the nym version uses m_strHashType to decide
// for you.  Choose the function you prefer, you can do it either way.
//
bool OTContract::VerifySignature(const OTPseudonym & theNym,
                                 const OTSignature & theSignature,
                                 OTPasswordData    * pPWData/*=NULL*/) const
{
    
    
    // TODO: see: const OTAsymmetricKey & OTPseudonym::GetPublicKey(const OTSignature * pSignature/*=NULL*/) const
    // It must return a list of keys, and we must check them all here. (All are potentially THE key.)
    // ...We might be able to skip some of that, if false == theSignature.m_metadata.HasMetadata()
    
    
    
    
	return this->VerifySignature(theNym.GetPublicKey(&theSignature), theSignature, m_strSigHashType, pPWData);
}


// -------------------------------------------------------------------------------


bool OTContract::VerifySignature(const OTAsymmetricKey & theKey,
                                 const OTSignature     & theSignature,
                                 const OTString        & strHashType,
                                 OTPasswordData        * pPWData/*=NULL*/) const
{
    const char * szFunc = "OTContract::VerifySignature";
    // -------------------------------------------------
    if (false == OTCrypto::It()->VerifySignature(m_xmlUnsigned,
                                                 theKey,
                                                 theSignature,
                                                 strHashType,
                                                 pPWData))
    {
		OTLog::vOutput(4, "%s: OTCrypto::It()->VerifySignature returned false.\n",
                      szFunc);
//		OTLog::vError("%s: Contract:\n\n%s\n\n",
//                      szFunc, m_strRawFile.Get());
		return false;
    }
	// --------------------------------------------------------------------
    return true;
}


// -------------------------------------------------------------------------------


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



// -------------------------------------------------------------------------------




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




// -------------------------------------------------------------------------------


bool OTContract::DisplayStatistics(OTString & strContents) const
{
	// Subclasses may override this.
	strContents.Concatenate(const_cast<char*>("ERROR:  OTContract::DisplayStatistics was called instead of a subclass...\n"));
	
	return false;	
}


// -------------------------------------------------------------------------------


bool OTContract::SaveContractWallet(OTString & strContents) const
{
	// Subclasses may use this.
	
	return false;
}


// -------------------------------------------------------------------------------


bool OTContract::SaveContents(std::ofstream & ofs) const
{	
	ofs << m_xmlUnsigned.Get();
	
	return true;
}

// -------------------------------------------------------------------------------


// Saves the unsigned XML contents to a string
bool OTContract::SaveContents(OTString & strContents) const
{
	strContents.Concatenate(m_xmlUnsigned.Get());

	return true;
}


// -------------------------------------------------------------------------------


/*
 bool OTContract::SaveContents(FILE * fl) const
 {
 if (fl)
 fprintf(fl, "%s", m_xmlUnsigned.Get());
 
 return true;
 }
 */


// -------------------------------------------------------------------------------



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

// -------------------------------------------------------------------------------



// Make sure you escape any lines that begin with dashes using "- "
// So "---BEGIN " at the beginning of a line would change to: "- ---BEGIN"
// This function expects that's already been done.
// This function assumes there is only unsigned contents, and not a signed contract.
// This function is intended to PRODUCE said signed contract.
// NOTE: This function also assumes you already instantiated a contract
// of the proper type. For example, if it's an OTServerContract, then you
// INSTANTIATED an OTServerContract. Because if you tried to do this using
// an OTContract but then the strContract was for an OTServerContract, then
// this function will fail when it tries to "LoadContractFromString()" since it
// is not actually the proper type to handle those data members.
//
// Therefore I need to make an entirely different (but similar) function which
// can be used for signing a piece of unsigned XML where the actual contract type
// is unknown.
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
        OTPasswordData thePWData("(OTContract::CreateContract needs the private key to sign the contract...)");
		// -----------------------------------
		OTString strTemp;
		
		if (false == this->SignContract(theSigner, &thePWData))
        {
            OTLog::vError("%s: this->SignContract failed.  strTemp contents:\n\n%s\n\n\n", 
                          szFunc, strTemp.Get());
            return false;
        }
        // -----------------------------------
		this->SaveContract();
		// -----------------------------------		
//      OTLog::vError("%s: m_xmlUnsigned AFTER SAVING:\n\n%s\n\n", szFunc, m_xmlUnsigned.Get());
//      OTLog::vError("%s: m_strRawFile AFTER SAVING:\n\n%s\n\n", szFunc, m_strRawFile.Get());
        
        this->SaveContractRaw(strTemp);
                
//      OTLog::vError("%s: STRING AFTER SIGNING:\n\n%s\n\n", szFunc, strTemp.Get());
		// -----------------------------------
        Release();
        LoadContractFromString(strTemp); // The ultimate test is, once we've created the serialized string for this contract, is to then load it up from that string.
        // -----------------------------------
		OTIdentifier NEW_ID;
		this->CalculateContractID(NEW_ID);
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


// -------------------------------------------------------------------------------


// CreateContract is great if you already know what kind of contract to instantiate
// and have already done so. Otherwise this function will take ANY flat text and use
// a generic OTContract instance to sign it and then write it to strOutput. This is
// due to the fact that OT was never really designed for signing flat text, only contracts.
//
//static
bool OTContract::SignFlatText(OTString & strFlatText, const OTString & strContractType, OTPseudonym & theSigner, OTString & strOutput)
{
	const char * szFunc = "OTContract::SignFlatText";
    // ----------------------    
    // Trim the input to remove any extraneous whitespace
    //
    std::string str_Trim(strFlatText.Get());
	std::string str_Trim2 = OTString::trim(str_Trim);
	
	strFlatText.Set(str_Trim2.c_str());
    // ---------------------------------------------------------
    char cNewline = 0;
    const uint32_t lLength = strFlatText.GetLength();
    
    if ((3 > lLength) || !strFlatText.At(lLength - 1, cNewline))
    {
        OTLog::vError("%s: Invalid input: text is less than 3 bytes "
                      "long, or unable to read a byte from the end where "
                      "a newline is meant to be.\n", szFunc);
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
    
    OTString strInput;
    if ('\n' == cNewline) // It already has a newline
        strInput = strFlatText;
    else
        strInput.Format("%s\n", strFlatText.Get());
    // ----------------------
    OTSignature      theSignature;
    OTPasswordData   thePWData("Signing flat text (need private key)");
    
    if (false == OTCrypto::It()->SignContract(strInput,
                                              theSigner.GetPrivateKey(),
                                              theSignature, // the output
                                              OTIdentifier::DefaultHashAlgorithm,
                                              &thePWData))
    {
        OTLog::vError("%s: SignContract failed. Contents:\n\n%s\n\n\n", 
                      szFunc, strInput.Get());
        return false;        
    }
    // -----------------------------------
    listOfSignatures listSignatures;
    listSignatures.push_back(&theSignature);
    // ---------------------------------------------------------
    const bool bBookends = OTContract::AddBookendsAroundContent(strOutput, // the output (other params are input.)
                                                                strInput, strContractType,
                                                                OTIdentifier::DefaultHashAlgorithm,
                                                                listSignatures);
    // ---------------------------------------------------------
    return bBookends;
}



// -------------------------------------------------------------------------------



// Saves the raw (pre-existing) contract text to any string you want to pass in.
bool OTContract::SaveContractRaw(OTString & strOutput) const
{
	strOutput.Concatenate("%s", m_strRawFile.Get());

	return true;
}



// -------------------------------------------------------------------------------


//static
bool OTContract::AddBookendsAroundContent(      OTString         & strOutput,
                                          const OTString         & strContents,
                                          const OTString         & strContractType,
                                          const OTString         & strHashType,
                                          const listOfSignatures & listSignatures)
{
	OTString strTemp;
	// ---------------------------------------------------------------
	strTemp.Concatenate("-----BEGIN SIGNED %s-----\nHash: %s\n\n", 
						strContractType.Get(), strHashType.Get());
	// ---------------------------------------------------------------
    strTemp.Concatenate("%s", strContents.Get());
	// ---------------------------------------------------------------
	FOR_EACH_CONST(listOfSignatures, listSignatures)
	{
		OTSignature * pSig = *it;
		OT_ASSERT(NULL != pSig);
        // ---------------------------------------------
		strTemp.Concatenate("-----BEGIN %s SIGNATURE-----\n"
							"Version: Open Transactions %s\n"
							"Comment: http://github.com/FellowTraveler/Open-Transactions/wiki\n",
							strContractType.Get(), OTLog::Version());
        // ---------------------------------------------
		if (pSig->m_metadata.HasMetadata())
            strTemp.Concatenate("Meta:    %c%c%c%c\n",
                                pSig->m_metadata.GetKeyType(),
                                pSig->m_metadata.FirstCharNymID(),
                                pSig->m_metadata.FirstCharMasterCredID(),
                                pSig->m_metadata.FirstCharSubCredID());
        // ---------------------------------------------
		strTemp.Concatenate("\n%s", pSig->Get()); // <=== *** THE SIGNATURE ITSELF ***
		strTemp.Concatenate("-----END %s SIGNATURE-----\n\n", strContractType.Get());
	}
	// ---------------------------------------------------------------
	std::string str_Trim(strTemp.Get());
	std::string str_Trim2 = OTString::trim(str_Trim);
	strOutput.Set(str_Trim2.c_str());
	// ---------------------------------------------------------------	
	return true;		
}


// -------------------------------------------------------------------------------


// Takes the pre-existing XML contents (WITHOUT signatures) and re-writes
// into strOutput the appearance of m_strRawData, adding the pre-existing
// signatures along with new signature bookends.. (The caller actually passes
// m_strRawData into this function...)
//
bool OTContract::RewriteContract(OTString & strOutput) const
{
	OTString strContents;
	this->SaveContents(strContents);
	// ---------------------------------------------------------------    
    return OTContract::AddBookendsAroundContent(strOutput, strContents,
                                                m_strContractType,
                                                m_strSigHashType,
                                                m_listSignatures);
}

// -------------------------------------------------------------------------------


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


// -------------------------------------------------------------------------------


	
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
    
//    OTSignedFile * pX = dynamic_cast<OTSignedFile*>(this);
//    
//    if (NULL != pX)
//        printf("DEBUGGING, OTContract::SaveContract. m_strRawFile contents:\n\n%s\n\n--------------------------------\n",
//                      m_strRawFile.Get());
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




// -------------------------------------------------------------------------------




// assumes m_strFilename is already set.
// Then it reads that file into a string.
// Then it parses that string into the object.
bool OTContract::LoadContract()
{		
	Release();
	LoadContractRawFile(); // opens m_strFilename and reads into m_strRawFile
	
	return ParseRawFile(); // Parses m_strRawFile into the various member variables.
}

// -------------------------------------------------------------------------------


	
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


// -------------------------------------------------------------------------------


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






// -------------------------------------------------------------------------------


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
//          OTLog::vError("DEBUGGING OTCONTRACT: ascTemp: \n%s\n",
//                        ascTemp.Get());
            
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



// -------------------------------------------------------------------------------



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
		memset(buffer1, 0, 2100); // todo remove this in optimization. (might be removed already...)
		
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
					if (line.length() < 2)
					{
						OTLog::Output(3, "Skipping short line...\n");
						
						if (bIsEOF || !m_strRawFile.sgets(buffer1, 2048))
						{
							OTLog::vOutput(0, "Error in signature for contract %s: Unexpected EOF after short line.\n",
                                           m_strFilename.Get());
							return false;
						}
						
						continue;
					}
					else if (line.compare(0,8,"Version:") == 0)
					{
						OTLog::Output(3, "Skipping version section...\n");
						
						if (bIsEOF || !m_strRawFile.sgets(buffer1, 2048))
						{
							OTLog::vOutput(0, "Error in signature for contract %s: Unexpected EOF after \"Version:\"\n",
                                           m_strFilename.Get());
							return false;
						}
						
						continue;
					}
					else if (line.compare(0,8,"Comment:") == 0)
					{
						OTLog::Output(3, "Skipping comment section...\n");
						
						if (bIsEOF || !m_strRawFile.sgets(buffer1, 2048))
						{
							OTLog::vOutput(0, "Error in signature for contract %s: Unexpected EOF after \"Comment:\"\n",
                                           m_strFilename.Get());
							return false;
						}
						
						continue;
					}
					if (line.compare(0,5,"Meta:") == 0)
					{
						OTLog::Output(3, "Collecting signature metadata...\n");
                        
                        if (line.length() != 13) // "Meta:    knms" (It will always be exactly 13 characters long.) knms represents the first characters of the Key type, NymID, Master Cred ID, and Subcred ID. Key type is (A|E|S) and the others are base62.
                        {
                            OTLog::vOutput(0, "Error in signature for contract %s: Unexpected length for \"Meta:\" comment.\n",
                                           m_strFilename.Get());
							return false;
                        }
                        // -----------------------------------------------------------
                        OT_ASSERT(NULL != pSig);
                        if (false == pSig->m_metadata.SetMetadata(line.at(9), line.at(10), line.at(11), line.at(12))) // "knms" from "Meta:    knms"
                        {
                            OTLog::vOutput(0, "Error in signature for contract %s: Unexpected metadata in the \"Meta:\" comment.\nLine: %s\n",
                                           m_strFilename.Get(), line.c_str());
							return false;                            
                        }
                        // -----------------------------------------------------------
						if (bIsEOF || !m_strRawFile.sgets(buffer1, 2048))
						{
							OTLog::vOutput(0, "Error in signature for contract %s: Unexpected EOF after \"Meta:\"\n",
                                           m_strFilename.Get());
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
						
						if (bIsEOF || !m_strRawFile.sgets(buffer1, 2048))
						{
							OTLog::vOutput(0, "Error in contract %s: Unexpected EOF after \"Hash:\"\n", 
                                           m_strFilename.Get());
							return false;
						}
						continue;
					}
				}
			}
		}
        // ---------------------------
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


// -------------------------------------------------------------------------------



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
        OTString strNodeType;
        
		switch(xml->getNodeType())
		{
			case EXN_NONE:         strNodeType.Set("EXN_NONE");        goto switch_log;
			case EXN_COMMENT:      strNodeType.Set("EXN_COMMENT");     goto switch_log;
			case EXN_ELEMENT_END:  strNodeType.Set("EXN_ELEMENT_END"); goto switch_log;
			case EXN_CDATA:        strNodeType.Set("EXN_CDATA");       goto switch_log;
                
            switch_log:
//                OTLog::vError("SKIPPING %s element in OTContract::LoadContractXML: "
//                              "type: %d, name: %s, value: %s\n", 
//                              strNodeType.Get(), xml->getNodeType(), xml->getNodeName(), xml->getNodeData());
				
                break;
				
			case EXN_TEXT:
			{
				// unknown element type
//				OTLog::vError( "SKIPPING unknown text element type in OTContract::LoadContractXML: %s, value: %s\n", 
//							  xml->getNodeName(), xml->getNodeData());
			}
				break;
			case EXN_ELEMENT:
				{
					retProcess = ProcessXMLNode(xml);
					
					// an error was returned. file format or whatever.
					if ((-1) == retProcess)
					{
                        OTLog::Error("OTContract::LoadContractXML: (Cancelling this contract load; an error occurred.)\n");
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
//                OTLog::vError("SKIPPING (default case) element in OTContract::LoadContractXML: %d, value: %s\n", 
//                              xml->getNodeType(), xml->getNodeData());                
			}
				continue;
				
		}
	}
		
	return true;	
}



// -------------------------------------------------------------------------------

//static
bool OTContract::SkipToElement(IrrXMLReader*& xml)
{
	OT_ASSERT_MSG(NULL != xml, "OTContract::SkipToElement -- assert: NULL != xml");
	
    const char * szFunc = "OTContract::SkipToElement";
	// ------------------
	while(xml->read() && (xml->getNodeType() != EXN_ELEMENT))
	{
//      OTLog::vOutput(0, "%s: Looping to skip non-elements: currently on: %s \n", szFunc, xml->getNodeName());
        
		if (xml->getNodeType() == EXN_NONE)
		{ OTLog::vOutput(0, "*** %s: EXN_NONE  (skipping)\n", szFunc); continue; }			// SKIP
		else if (xml->getNodeType() == EXN_COMMENT)
		{ OTLog::vOutput(0, "*** %s: EXN_COMMENT  (skipping)\n", szFunc); continue; }			// SKIP
		else if (xml->getNodeType() == EXN_ELEMENT_END)
//		{ OTLog::Output(0, "*** OTContract::SkipToElement: EXN_ELEMENT_END  (ERROR)\n");  return false; }
		{ OTLog::vOutput(1, "*** %s: EXN_ELEMENT_END  (skipping %s)\n", szFunc, xml->getNodeName());  continue; }
		else if (xml->getNodeType() == EXN_CDATA)
		{ OTLog::vOutput(0, "*** %s: EXN_CDATA (ERROR -- unexpected CData)\n", szFunc); return false; }
		else if (xml->getNodeType() == EXN_TEXT)
		{ OTLog::vError("*** %s: EXN_TEXT\n", szFunc); return false; }
		else if (xml->getNodeType() == EXN_ELEMENT)
		{ OTLog::vOutput(0, "*** %s: EXN_ELEMENT\n", szFunc); break; }  // (Should never happen due to while() second condition.) Still returns true.
		else
		{ OTLog::vError("*** %s: SHOULD NEVER HAPPEN  (Unknown element type!)\n", szFunc); return false; }	// Failure / Error
	}	
	// ------------------
	
	return true;
}


// -------------------------------------------------------------------------------

//static
bool OTContract::SkipToTextField(IrrXMLReader*& xml)
{
	OT_ASSERT_MSG(NULL != xml, "OTContract::SkipToTextField -- assert: NULL != xml");
	// ------------------
	const char * szFunc = "OTContract::SkipToTextField";
	// ------------------
	while(xml->read() && (xml->getNodeType() != EXN_TEXT))
	{
		if (xml->getNodeType() == EXN_NONE)
		{ OTLog::vOutput(0, "*** %s: EXN_NONE  (skipping)\n", szFunc); continue; }			// SKIP
		else if (xml->getNodeType() == EXN_COMMENT)
		{ OTLog::vOutput(0, "*** %s: EXN_COMMENT  (skipping)\n", szFunc); continue; }		// SKIP
		else if (xml->getNodeType() == EXN_ELEMENT_END)
//		{ OTLog::Output(0, "*** OTContract::SkipToTextField: EXN_ELEMENT_END  (skipping)\n");  continue; }     // SKIP (debugging...)
		{ OTLog::vOutput(0, "*** %s: EXN_ELEMENT_END  (ERROR)\n", szFunc);  return false; }
		else if (xml->getNodeType() == EXN_CDATA)
		{ OTLog::vOutput(0, "*** %s: EXN_CDATA (ERROR -- unexpected CData)\n", szFunc); return false; }
		else if (xml->getNodeType() == EXN_ELEMENT)
		{ OTLog::vOutput(0, "*** %s: EXN_ELEMENT\n", szFunc); return false; }
		else if (xml->getNodeType() == EXN_TEXT)
		{ OTLog::vError("*** %s: EXN_TEXT\n", szFunc); break; } // (Should never happen due to while() second condition.) Still returns true.
		else
		{ OTLog::vError("*** %s: SHOULD NEVER HAPPEN  (Unknown element type!)\n", szFunc); return false; }	// Failure / Error
	}	
	// ------------------
	
	return true;
}


// -------------------------------------------------------------------------------

// AFTER you read an element or text field, there is some whitespace, and you 
// just want to bring your cursor back to wherever it should be for the next guy.
// So you call this function..
//
//static
bool OTContract::SkipAfterLoadingField(IrrXMLReader*& xml)
{
	OT_ASSERT_MSG(NULL != xml, "OTContract::SkipAfterLoadingField -- assert: NULL != xml");
	
    const char * szFunc = "OTContract::SkipAfterLoadingField";
    
	if (EXN_ELEMENT_END != xml->getNodeType())  // If we're not ALREADY on the ending element, then go there.
	{
		// move to the next node which SHOULD be the expected element_end.
		//
		while(xml->read())
		{
			if (xml->getNodeType() == EXN_NONE)
			{ OTLog::vOutput(0, "*** %s: EXN_NONE  (skipping)\n", szFunc); continue; }		// SKIP
			else if (xml->getNodeType() == EXN_COMMENT)
			{ OTLog::vOutput(0, "*** %s: EXN_COMMENT  (skipping)\n", szFunc); continue; }   // SKIP
			else if (xml->getNodeType() == EXN_ELEMENT_END)
			{ OTLog::vOutput(5, "*** %s: EXN_ELEMENT_END  (success)\n", szFunc);  break; }	// Success...
			else if (xml->getNodeType() == EXN_CDATA)
			{ OTLog::vOutput(0, "*** %s: EXN_CDATA  (Unexpected!)\n", szFunc); return false; } // Failure / Error
			else if (xml->getNodeType() == EXN_ELEMENT)
			{ OTLog::vOutput(0, "*** %s: EXN_ELEMENT  (Unexpected!)\n", szFunc); return false; }		// Failure / Error
			else if (xml->getNodeType() == EXN_TEXT)
			{ OTLog::vError("*** %s: EXN_TEXT  (Unexpected!)\n", szFunc); return false; }		// Failure / Error
			else
			{ OTLog::vError("*** %s: SHOULD NEVER HAPPEN  (Unknown element type!)\n", szFunc); return false; }	// Failure / Error
		}	
	}
	// ------------------
	// else ... (already on the ending element.)
	//
	// ------------------
	
	return true;
}


// -------------------------------------------------------------------------------


// Loads it up and also decodes it to a string.
//
//static
bool OTContract::LoadEncodedTextField(IrrXMLReader*& xml, OTString & strOutput)
{
	OTASCIIArmor ascOutput;
	
	if (OTContract::LoadEncodedTextField(xml, ascOutput) && ascOutput.GetLength() > 2)
	{
		return ascOutput.GetString(strOutput, true); // linebreaks = true
	}
	
	return false;
}


// -------------------------------------------------------------------------------


//static
bool OTContract::LoadEncodedTextField(IrrXMLReader*& xml, OTASCIIArmor & ascOutput)
{
	OT_ASSERT_MSG(NULL != xml, "OTContract::LoadEncodedTextField -- assert: NULL != xml");	
	// ------------------
    const char * szFunc = "OTContract::LoadEncodedTextField";
	// ------------------
	// If we're not ALREADY on a text field, maybe there is some whitespace, so let's skip ahead...
	//
	if (EXN_TEXT != xml->getNodeType())  
	{
        OTLog::vOutput(4, "%s: Skipping non-text field... \n", szFunc);

		// move to the next node which SHOULD be the expected text field.
		//
		if (false == SkipToTextField(xml))
		{
			OTLog::vOutput(0, "%s: Failure: Unable to find expected text field.\n", szFunc);
			return false;
		}
        OTLog::vOutput(4, "%s: Finished skipping non-text field. (Successfully.)\n", szFunc);
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
			{ OTLog::vOutput(0, "*** %s: Bad data? Expected EXN_ELEMENT_END here, but "
							"didn't get it. Returning false.\n", szFunc); return false; }
            
			return true;
		}
	}
	else 
		OTLog::vOutput(0, "%s: Failure: Unable to find expected text field. 2\n", szFunc);
	
	return false;
}


// -------------------------------------------------------------------------------



// Loads it up and also decodes it to a string.
//static
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


// -------------------------------------------------------------------------------


// Loads it up and keeps it encoded in an ascii-armored object.
//static
bool OTContract::LoadEncodedTextFieldByName(IrrXMLReader*& xml, OTASCIIArmor & ascOutput,
											const char *& szName, mapOfStrings * pmapExtraVars/*=NULL*/)
{
	OT_ASSERT(NULL != szName);
    const char * szFunc = "OTContract::LoadEncodedTextFieldByName";
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
			OTLog::vOutput(0, "%s: Failure: Unable to find expected element: %s. \n",
                           szFunc, szName);
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
				OTLog::vError("%s: Error loading %s field.\n", szFunc,
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
//				{ OTLog::Output(0, "*** %s: Bad data? Expected EXN_ELEMENT_END here, but "
//								"didn't get it. Returning false.\n", szFunc); return false; }
				
				return true;  // <============ SUCCESS!!!!
			}
		}
		else 
		{
			OTLog::vError("%s: Error: missing %s element.\n",
                          szFunc, pElementExpected);
			return false; // error condition
		}
	}
	else
	{
		OTLog::vError("%s: Error: Expected %s element with text field.\n",
                      szFunc, pElementExpected);
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


// -------------------------------------------------------------------------------


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



// -------------------------------------------------------------------------------


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
// inside a comment here #include <cstdio>
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






























