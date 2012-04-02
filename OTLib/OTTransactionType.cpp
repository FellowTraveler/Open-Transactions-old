/************************************************************************************
 *    
 *  OTTransactionType.cpp
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

#include <cctype>
#include <cstdlib>

#include "OTStorage.h"

#include "OTLog.h"

#include "OTTransactionType.h"
#include "OTItem.h"
#include "OTTransaction.h"
#include "OTAccount.h"
#include "OTLedger.h"



// static -- class factory.
//
OTTransactionType * OTTransactionType::TransactionFactory(const OTString & strInput)
{
	static char		buf[45] = "";
    
	OTTransactionType *	pItem = NULL;
	
	if (!strInput.Exists())
		return NULL;
	
	OTString strContract(strInput);
	
	strContract.reset(); // for sgets
	buf[0] = 0; // probably unnecessary.
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
    
	if (strFirstLine.Contains("-----BEGIN SIGNED TRANSACTION-----"))  // this string is 34 chars long.
	{	pItem = new OTTransaction();		OT_ASSERT(NULL != pItem); }
	
	else if (strFirstLine.Contains("-----BEGIN SIGNED TRANSACTION ITEM-----"))  // this string is 39 chars long.
	{	pItem = new OTItem();	OT_ASSERT(NULL != pItem); }
	
	else if (strFirstLine.Contains("-----BEGIN SIGNED LEDGER-----"))  // this string is 29 chars long.
	{	pItem = new OTLedger();			OT_ASSERT(NULL != pItem); }
	
	else if (strFirstLine.Contains("-----BEGIN SIGNED ACCOUNT-----"))  // this string is 30 chars long.
	{	pItem = new OTAccount();			OT_ASSERT(NULL != pItem); }
	
	
	// The string didn't match any of the options in the factory.
	if (NULL == pItem)
		return NULL;
	
    // This causes pItem to load ASSUMING that the PurportedAcctID and PurportedServerID are correct.
    // The object is still expected to be internally consistent with its sub-items, regarding those IDs,
    // but the big difference is that it will SET the Real Acct and Real Server IDs based on the purported
    // values. This way you can load a transaction without knowing the account in advance.
    //
    pItem->m_bLoadSecurely = false;
    
//	OTLog::Error("\n\nTESTING DEBUGGING LOL LOL LOL LOL \n\n\n");

	// Does the contract successfully load from the string passed in?
	if (pItem->LoadContractFromString(strContract))
	{
		// NOTE: this already happens in OTTransaction::ProcessXMLNode and OTLedger::ProcessXMLNode.
		// Specifically, it happens when m_bLoadSecurely is set to false.
		//
//		pItem->SetRealServerID(pItem->GetPurportedServerID());
//		pItem->SetRealAccountID(pItem->GetPurportedAccountID());
//		
		return pItem;
	}
    else
		delete pItem;
	
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





// ----------------------------------------------------------------------------------------

void OTTransactionType::GetNumList(OTNumList & theOutput)
{    
    theOutput.Release();
    theOutput.Add(m_Numlist);
}


// Allows you to string-search the raw contract.
bool OTTransactionType::Contains(const OTString & strContains)
{
	return m_strRawFile.Contains(strContains);
}

// Allows you to string-search the raw contract.
bool OTTransactionType::Contains(const char * szContains)
{
	return m_strRawFile.Contains(szContains);
}



// keeping constructor private in order to force people to use the other constructors and 
// therefore provide the requisite IDs.
OTTransactionType::OTTransactionType() : OTContract(), 
    m_lTransactionNum(0), m_lInReferenceToTransaction(0), m_bLoadSecurely(true)
{
 // this function is private to prevent people from using it.	
	// Should never actually get called.
	
	InitTransactionType(); // Just in case.
}


OTTransactionType::OTTransactionType(const OTIdentifier & theUserID, const OTIdentifier & theAccountID, 
									 const OTIdentifier & theServerID) : OTContract(theAccountID), 
    m_lTransactionNum(0), m_lInReferenceToTransaction(0), m_bLoadSecurely(true)
{
	InitTransactionType();
	
	// m_ID			= theAccountID  -- This happens in OTContract, no need to do it twice.
	m_ServerID		= theServerID;
	m_AcctUserID	= theUserID;
	
	// do NOT set m_AcctID and m_AcctServerID here.  Let the child classes LOAD them or GENERATE them.
}

OTTransactionType::OTTransactionType(const OTIdentifier & theUserID, const OTIdentifier & theAccountID, 
									 const OTIdentifier & theServerID, long lTransactionNum) : OTContract(theAccountID), 
    m_lTransactionNum(0), m_lInReferenceToTransaction(0), m_bLoadSecurely(true)
{
	// This initializes m_lTransactionNum, so it must come FIRST. 
	// In fact, that's the general rule with this function.
	InitTransactionType();
	
	// m_ID				= theAccountID  -- This happens in OTContract, no need to do it twice.
	m_ServerID			= theServerID;
	m_AcctUserID		= theUserID;
	m_lTransactionNum	= lTransactionNum;

	// do NOT set m_AcctID and m_AcctServerID here.  Let the child classes LOAD them or GENERATE them.
}


void OTTransactionType::InitTransactionType()
{
	m_lTransactionNum			= 0;
	m_lInReferenceToTransaction	= 0;
}

OTTransactionType::~OTTransactionType()
{
	// No need to call Release() here, it's called already by the framework.
	
}

void OTTransactionType::Release()
{
	// If there were any dynamically allocated objects, clean them up here.
		
	OTContract::Release(); // since I've overridden the base class, I call it now...
}




// -------------------------------------------
// OTAccount, OTTransaction, OTItem, and OTLedger are all derived from
// this class (OTTransactionType). Therefore they can all quickly identify
// whether one of the other components belongs to the same account, using 
// this method.
//
bool OTTransactionType::IsSameAccount(const OTTransactionType & rhs) const
{
    if (
        (GetUserID()        != rhs.GetUserID())        ||
        (GetRealAccountID() != rhs.GetRealAccountID()) ||
        (GetRealServerID()  != rhs.GetRealServerID())
        )
        return false;
    return true;
}



void OTTransactionType::GetReferenceString(OTString & theStr) const
{
	m_ascInReferenceTo.GetString(theStr);
}

void OTTransactionType::SetReferenceString(const OTString & theStr)
{
	m_ascInReferenceTo.SetString(theStr);
}



bool OTTransactionType::SaveContractWallet(std::ofstream & ofs)
{
	return true;
}


// Make sure this contract checks out. Very high level. 
// Verifies ID and signature.
// I do NOT call VerifyOwner() here, because the server may
// wish to verify its signature on this account, even though
// the server may not be the actual owner.
// So if you wish to VerifyOwner(), then call it.
bool OTTransactionType::VerifyAccount(OTPseudonym & theNym)
{
	// Make sure that the supposed AcctID matches the one read from the file.
	//
	if (false == VerifyContractID())
	{
		OTLog::Error("Error verifying account ID in OTTransactionType::VerifyAccount\n");
		return false;
	}
	else if (false == VerifySignature(theNym))
	{
		OTLog::Error("Error verifying signature in OTTransactionType::VerifyAccount.\n");
		return false;
	}
	
	OTLog::Output(4, "\nWe now know that...\n"
			"1) The expected Account ID matches the ID that was found on the object.\n"
			"2) The SIGNATURE VERIFIED on the object.\n\n");
	return true;
}



bool OTTransactionType::VerifyContractID()
{	
	//m_AcctID contains the number we read from the xml file
	//we can compare it to the existing and actual identifier.
	
	// m_AcctID  contains the "IDENTIFIER" of the object, according to the xml file. 
	// 
	// Meanwhile m_ID contains the same identifier, except it was generated.
	//
	// Now let's compare the two and make sure they match...
	
	// Also, for this class, we compare ServerID as well.  They go hand in hand.
	
	if ((m_ID		!= m_AcctID)		|| 
		(m_ServerID	!= m_AcctServerID))
	{
//		OT_ASSERT(false);  // I was debugging.
		
		OTString str1(m_ID), str2(m_AcctID), str3(m_ServerID), str4(m_AcctServerID);
		OTLog::vError("Identifiers do NOT match in OTTransactionType::VerifyContractID.\n"
				"m_ID: %s\n m_AcctID: %s\n m_ServerID: %s\n m_AcctServerID: %s\n",
				str1.Get(), str2.Get(), str3.Get(), str4.Get());
		return false;
	}
	else 
	{
//		OTString str1(m_AcctID), str2(m_AcctServerID);
//		OTLog::vError("Expected Account ID and Server ID both *SUCCESSFUL* match to "
//				"IDs in the xml:\n Account ID:\n%s\n ServerID:\n%s\n"
//				"-----------------------------------------------------------------------------\n",
//				str1.Get(), str2.Get());
		return true;
	}
}




// need to know the transaction number of this transaction? Call this.
long OTTransactionType::GetTransactionNum() const
{
	return m_lTransactionNum; 
}	


void OTTransactionType::SetTransactionNum(const long lTransactionNum)
{
	m_lTransactionNum = lTransactionNum;
}


// need to know the transaction number of this transaction? Call this.
long OTTransactionType::GetReferenceToNum() const
{
	return m_lInReferenceToTransaction; 
}	


void OTTransactionType::SetReferenceToNum(const long lTransactionNum)
{
	m_lInReferenceToTransaction = lTransactionNum;
}

