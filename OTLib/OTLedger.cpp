/************************************************************************
 *    
 *  OTLedger.cpp
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



#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include <cstring>

//#include <set> // in header now.


#include "irrxml/irrXML.h"

using namespace irr;
using namespace io;


#include "OTStorage.h"

#include "OTData.h"
#include "OTIdentifier.h"
#include "OTAccount.h"
#include "OTPayload.h"
#include "OTMessage.h"
#include "OTStringXML.h"

#include "OTItem.h"
#include "OTTransaction.h"
#include "OTLedger.h"

#include "OTPseudonym.h"
#include "OTLog.h"


#ifndef _WIN32
#include "stacktrace.h"
#endif




const char * OTLedger::_TypeStrings[] = 
{
	"nymbox",		// the nymbox is per user account (versus per asset account) and is used to receive new transaction numbers (and messages.)
	"inbox",		// each asset account has an inbox, with pending transfers as well as receipts inside.
	"outbox",		// if you SEND a pending transfer, it sits in your outbox until it's accepted, rejected, or canceled.
	"message",		// used in OTMessages, to send various lists of transactions back and forth.
	"error_state"
};




// ------------------------------------
// This calls OTTransactionType::VerifyAccount(), which calls 
// VerifyContractID() as well as VerifySignature().
//
// But first, this OTLedger version also loads the box receipts,
// if doing so is appropriate. (message ledger == not appropriate.)
//
// Use this method instead of OTContract::VerifyContract, which
// expects/uses a pubkey from inside the contract in order to verify
// it.
//
bool OTLedger::VerifyAccount(OTPseudonym & theNym)
{
	switch (this->GetType())
	{
		case OTLedger::message: // message ledgers do not load Box Receipts. (They store full version internally already.)
			break;
		case OTLedger::nymbox:
		case OTLedger::inbox:
		case OTLedger::outbox:
		{
			std::set<long> setUnloaded;
			// if psetUnloaded passed in, then use it to return the #s that weren't there as box receipts.
//			bool bLoadedBoxReceipts = 
			this->LoadBoxReceipts(&setUnloaded); // Note: Also useful for suppressing errors here.
		}
				break;
		default:
		{
			const int nLedgerType = static_cast<int>(this->GetType());
			const OTIdentifier	theNymID(theNym);
			const OTString		strNymID(theNymID);
			OTString strAccountID;
			this->GetIdentifier(strAccountID);
			OTLog::vError("OTLedger::VerifyAccount: Failure: Bad ledger type: %d, UserID: %s, AcctID: %s\n",
						  nLedgerType, strNymID.Get(), strAccountID.Get());
		}
			return false;
	}
	
	return OTTransactionType::VerifyAccount(theNym);
}
/*
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
*/



// This makes sure that ALL transactions inside the ledger are saved as box receipts
// in their full (not abbreviated) form (as separate files.)
//
bool OTLedger::SaveBoxReceipts()	// For ALL full transactions, save the actual box receipt for each to its own place.
{
    bool bRetVal = true;
    FOR_EACH(mapOfTransactions, m_mapTransactions)
    {
        OTTransaction * pTransaction = (*it).second;
        OT_ASSERT(NULL != pTransaction);
        // -------------------------------
        
        // We only save full versions of transactions as box receipts, not abbreviated versions.
        // (If it's not abbreviated, therefore it's the full version.)
        //
        if (false == pTransaction->IsAbbreviated()) // This way we won't see an error if it's not abbreviated.
            bRetVal = pTransaction->SaveBoxReceipt(*this);
        
        if (!bRetVal)
        {
            OTLog::vError("OTLedger::SaveBoxReceipts: Failed calling SaveBoxReceipt on transaction: %ld.\n",
                          pTransaction->GetTransactionNum());
            break;
        }
    }
    return bRetVal;
}

// --------------------------------------------------------


bool OTLedger::SaveBoxReceipt(const long & lTransactionNum)
{
    // --------------------------------------------------------
    // First, see if the transaction itself exists on this ledger.
    // Get a pointer to it. 
    OTTransaction * pTransaction  = this->GetTransaction(lTransactionNum);
    
    if (NULL == pTransaction)
    {
        OTLog::vOutput(0, "OTLedger::SaveBoxReceipt: Unable to save box receipt %ld: "
                       "couldn't find the transaction on this ledger.\n", lTransactionNum);
        return false;
    }
    
    return  pTransaction->SaveBoxReceipt(*this);
}
// --------------------------------------------------------


bool OTLedger::DeleteBoxReceipt(const long & lTransactionNum)
{
    // --------------------------------------------------------
    // First, see if the transaction itself exists on this ledger.
    // Get a pointer to it. 
    OTTransaction * pTransaction  = this->GetTransaction(lTransactionNum);
    
    if (NULL == pTransaction)
    {
        OTLog::vOutput(0, "OTLedger::DeleteBoxReceipt: Unable to delete (overwrite) box receipt %ld: "
                       "couldn't find the transaction on this ledger.\n", lTransactionNum);
        return false;
    }
    
    return  pTransaction->DeleteBoxReceipt(*this);
}
// --------------------------------------------------------



// This makes sure that ALL transactions inside the ledger are loaded in their
// full (not abbreviated) form.
//
// For ALL abbreviated transactions, load the actual box receipt for each.
//
// For all failures to load the box receipt, if a set pointer was passed in,
// then add that transaction# to the set. (psetUnloaded)
//
bool OTLedger::LoadBoxReceipts(std::set<long> * psetUnloaded/*=NULL*/) // if psetUnloaded passed in, then use it to return the #s that weren't there.
{
    // Grab a copy of all the transaction #s stored inside this ledger.
    //
    std::set<long> the_set;
    
    FOR_EACH(mapOfTransactions, m_mapTransactions)
    {
        OTTransaction * pTransaction = (*it).second;
        OT_ASSERT(NULL != pTransaction);
        the_set.insert(pTransaction->GetTransactionNum());
    }
    // -------------------------------
    // Now iterate through those numbers and for each, load the box receipt.
    //
    bool bRetVal = true;
    
    FOR_EACH(std::set<long>, the_set)
	{
		long lSetNum = *it;
        // ------------------------
        OTTransaction * pTransaction = this->GetTransaction(lSetNum);
        OT_ASSERT(NULL != pTransaction);
        // ------------------------
		// Failed loading the boxReceipt
		//
        if ((true	==	pTransaction->IsAbbreviated()) &&
			(false	==	this->LoadBoxReceipt(lSetNum))) 
        {
			// WARNING: pTransaction must be re-Get'd below this point if needed, since pointer
			// is bad if success on LoadBoxReceipt() call.
			pTransaction	= NULL;	
			bRetVal			= false;
			int nLogLevel	= 0;
			// --------------
			if (NULL != psetUnloaded)
			{
				psetUnloaded->insert(lSetNum);
				nLogLevel = 3;
			}
            OTLog::vOutput(nLogLevel, "OTLedger::LoadBoxReceipts: Failed calling LoadBoxReceipt on "
						   "abbreviated transaction number: %ld.\n", lSetNum);
			// If psetUnloaded is passed in, then we don't want to break, because we want to
			// populate it with the conmplete list of IDs that wouldn't load as a Box Receipt.
			// Thus, we only break if psetUnloaded is NULL, which is better optimization in that case.
			// (If not building a list of all failures, then we can return at first sign of failure.)
			//
			if (NULL == psetUnloaded)
				break;
        }
		// else (success), no need for a block in that case.
	}
    
    // You might ask, why didn't I just iterate through the transactions directly and just call
    // LoadBoxReceipt on each one? Answer: Because that function actually deletes the transaction
    // and replaces it with a different object, if successful. 
    
    return bRetVal;
}



/*
 While the box itself is stored at (for example) "nymbox/SERVER_ID/USER_ID"
 the box receipts for that box may be stored at: "nymbox/SERVER_ID/USER_ID.r"
 With a specific receipt denoted by transaction: "nymbox/SERVER_ID/USER_ID.r/TRANSACTION_ID.rct"
 */

bool OTLedger::LoadBoxReceipt(const long & lTransactionNum)
{
    // First, see if the transaction itself exists on this ledger.
    // Get a pointer to it. 
    // Next, see if the appropriate file exists, and load it up from
    // local storage, into a string.
    // Finally, try to load the transaction from that string and see if successful.
    // If it verifies, then replace the abbreviated receipt with the actual one.
    // --------------------------------------------------------

    // First, see if the transaction itself exists on this ledger.
    // Get a pointer to it. 
    OTTransaction * pTransaction  = this->GetTransaction(lTransactionNum);

    if (NULL == pTransaction)
    {
        OTLog::vOutput(0, "OTLedger::LoadBoxReceipt: Unable to load box receipt %ld: "
                       "couldn't find abbreviated version already on this ledger.\n", lTransactionNum);
        return false;
    }
    // ****************************************************************
    // Todo: security analysis. By this point we've verified the hash of the transaction against the stored
    // hash inside the abbreviated version. (VerifyBoxReceipt) We've also verified a few other values like transaction
    // number, and the "in ref to" display number. We're then assuming based on those, that the adjustment and display
    // amount are correct. (The hash is actually a zero knowledge proof of this already.) This is good for speedier
    // optimization but may be worth revisiting in case any security holes.
    // UPDATE: We'll save this for optimization needs in the future.
//  pBoxReceipt->SetAbbrevAdjustment(       pTransaction->GetAbbrevAdjustment() );    
//  pBoxReceipt->SetAbbrevDisplayAmount(    pTransaction->GetAbbrevDisplayAmount() );
 	// -------------------------------------------------
	
	// OTTransaction::LoadBoxReceipt already checks pTransaction to see if it's abbreviated
	// (which it must be.) So I don't bother checking twice.
	//
	OTTransaction * pBoxReceipt = OTTransaction::LoadBoxReceipt(*pTransaction, *this);

	// success
	if (NULL != pBoxReceipt)
	{
		//  Remove the existing, abbreviated receipt, and replace it with the actual receipt.
		//  (If this inbox/outbox/whatever is saved, it will later save in abbreviated form
		//	again.)
		//
		this->RemoveTransaction(lTransactionNum); // this deletes pTransaction
		this->AddTransaction(*pBoxReceipt); // takes ownership.
		// -------------------------------------------------
		return true;
	}
	
	return false;
}




// the below four functions (load/save in/outbox) assume that the ID is already set
// properly.
// Then it uses the ID to form the path for the file that is opened. Easy, right?

bool OTLedger::LoadInbox()
{
	//	print_stacktrace();
	
	bool bRetVal = LoadGeneric(OTLedger::inbox);
	
	return bRetVal;
}

//TODO really should verify the ServerID after loading the ledger.
// Perhaps just call "VerifyContract" and we'll make sure, for ledgers
// VerifyContract is overriden and explicitly checks the serverID.
// Should also check the Type at the same time.

bool OTLedger::LoadOutbox()
{
	return LoadGeneric(OTLedger::outbox);	
}

bool OTLedger::LoadNymbox()
{
	return LoadGeneric(OTLedger::nymbox);		
}



bool OTLedger::LoadInboxFromString(const OTString & strBox)
{	
	return LoadGeneric(OTLedger::inbox, &strBox);
}

bool OTLedger::LoadOutboxFromString(const OTString & strBox)
{
	return LoadGeneric(OTLedger::outbox, &strBox);	
}

bool OTLedger::LoadNymboxFromString(const OTString & strBox)
{
	return LoadGeneric(OTLedger::nymbox, &strBox);		
}


/**
  OTLedger::LoadGeneric is called by LoadInbox, LoadOutbox, and LoadNymbox.
  Does NOT VerifyAccount after loading -- caller is responsible to do that.
 
  pString -- optional argument, for when  you prefer to load from a string
  instead of from a file.
 */
bool OTLedger::LoadGeneric(OTLedger::ledgerType theType, const OTString * pString/*=NULL*/)
{
	m_Type = theType;
    // --------------------------------------------------------
	const char * pszType	= GetTypeString();
	const char * pszFolder	= NULL;
    // --------------------------------------------------------
	switch (theType) 
	{
		case OTLedger::inbox:   pszFolder = OTLog::InboxFolder();   break;
		case OTLedger::outbox:  pszFolder = OTLog::OutboxFolder();  break;
		case OTLedger::nymbox:  pszFolder = OTLog::NymboxFolder();  break;
		default:
			OTLog::Error("OTLedger::LoadGeneric: Error: unknown box type. (This should never happen.)\n");
			return false;
	}
	m_strFoldername = pszFolder;
	// --------------------------------------------------------
	OTString strID;
	GetIdentifier(strID);	
    // --------------------------------------------------------
	const OTString strServerID(GetRealServerID());

	if (false == m_strFilename.Exists())
		m_strFilename.Format("%s%s%s", strServerID.Get(), OTLog::PathSeparator(), strID.Get());
	// --------------------------------------------------------------------
	OTString strFilename;
	strFilename = strID.Get();
	
	const char * szFolder1name	= m_strFoldername.Get(); // "nymbox" (or "inbox" or "outbox")
	const char * szFolder2name	= strServerID.Get();     // "nymbox/SERVER_ID"
	const char * szFilename		= strFilename.Get();     // "nymbox/SERVER_ID/USER_ID"  (or "inbox/SERVER_ID/ACCT_ID" or "outbox/SERVER_ID/ACCT_ID")
	// --------------------------------------------------------------------	
	OTString strRawFile;

	if (NULL != pString)	// Loading FROM A STRING.
		strRawFile.Set(*pString);
	else					// Loading FROM A FILE.
	{
		if (false == OTDB::Exists(szFolder1name, szFolder2name, szFilename))
		{
			OTLog::vOutput(3, "%s does not exist in OTLedger::Load%s: %s%s%s%s%s\n",
						   pszType,			pszType, 
						   szFolder1name,	OTLog::PathSeparator(), 
						   szFolder2name,	OTLog::PathSeparator(), szFilename);
			return false;
		}
		// --------------------------------------------------------------------
		// Try to load the ledger from local storage.
		//
		std::string strFileContents(OTDB::QueryPlainString(szFolder1name, szFolder2name, szFilename)); // <=== LOADING FROM DATA STORE.
		
		if (strFileContents.length() < 2)
		{
			OTLog::vError("OTLedger::LoadGeneric: Error reading file: %s%s%s%s%s\n", 
						  szFolder1name, OTLog::PathSeparator(), szFolder2name, OTLog::PathSeparator(), szFilename);
			return false;
		}
		// --------------------------------------------------------------------
		strRawFile.Set(strFileContents.c_str());
	}
	// --------------------------------------------------------------------	
	if (false == strRawFile.Exists())
	{
		OTLog::vError("OTLedger::LoadGeneric: Unable to load box (%s%s%s%s%s) from empty string.\n", 
					  szFolder1name, OTLog::PathSeparator(), 
					  szFolder2name, OTLog::PathSeparator(), szFilename);
		return false;
	}	
	// --------------------------------------------------------------------	
	bool bSuccess = this->LoadContractFromString(strRawFile);
		
	if (false == bSuccess)
	{
		OTLog::vError("Failed loading %s %s in OTLedger::Load%s: %s%s%s%s%s\n", 
					  pszType, (NULL != pString) ? "from string" : "from file", pszType, 
					  szFolder1name, OTLog::PathSeparator(), 
					  szFolder2name, OTLog::PathSeparator(), szFilename);
		return false;
	}
	else 
	{
		OTLog::vOutput(2, "Successfully loaded %s %s in OTLedger::Load%s: %s%s%s%s%s\n", 
					   pszType, (NULL != pString) ? "from string" : "from file", pszType, 
					   szFolder1name, OTLog::PathSeparator(), 
					   szFolder2name, OTLog::PathSeparator(), szFilename);
	}
	
	return bSuccess;
}




bool OTLedger::SaveGeneric(OTLedger::ledgerType theType)
{
	m_Type = theType;
	
	const char * pszFolder = NULL;
	const char * pszType = GetTypeString();
	
	switch (theType) 
	{
		case OTLedger::inbox:	pszFolder = OTLog::InboxFolder();	break;
		case OTLedger::outbox:	pszFolder = OTLog::OutboxFolder();	break;
		case OTLedger::nymbox:	pszFolder = OTLog::NymboxFolder();	break;
		default:
			OTLog::Error("OTLedger::SaveGeneric: Error: unknown box type. (This should never happen.)\n");
			return false;
	}
	
	m_strFoldername = pszFolder;  // <=======
	// --------------------------------------------------------
	OTString strID;
	GetIdentifier(strID);
	const OTString strServerID(GetRealServerID());
	
	if (false == m_strFilename.Exists())
		m_strFilename.Format("%s%s%s", strServerID.Get(), OTLog::PathSeparator(), strID.Get()); 
	
	// --------------------------------------------------------------------
	OTString strFilename;
	strFilename = strID.Get();
	
	const char * szFolder1name	= m_strFoldername.Get(); // "nymbox" (or "inbox" or "outbox")
	const char * szFolder2name	= strServerID.Get();     // "nymbox/SERVER_ID"
	const char * szFilename		= strFilename.Get();     // "nymbox/SERVER_ID/USER_ID"  (or "inbox/SERVER_ID/ACCT_ID" or "outbox/SERVER_ID/ACCT_ID")
	
	OT_ASSERT(m_strFoldername.GetLength() > 2);
	OT_ASSERT(m_strFilename.GetLength() > 2);
	// --------------------------------------------------------------------
	OTString strRawFile;
	
	if (!SaveContractRaw(strRawFile))
	{
		OTLog::vError("OTLedger::SaveGeneric: Error saving %s (to string):\n%s%s%s%s%s\n", pszType,
					  szFolder1name, OTLog::PathSeparator(), szFolder2name, OTLog::PathSeparator(), szFilename);
		return false;
	}
	// --------------------------------------------------------------------
	//
	bool bSaved = OTDB::StorePlainString(strRawFile.Get(), szFolder1name, 
										 szFolder2name, szFilename); // <=== SAVING TO DATA STORE.
	if (!bSaved)
	{
		OTLog::vError("OTLedger::SaveGeneric: Error writing %s to file: %s%s%s%s%s\n", pszType,
					  szFolder1name, OTLog::PathSeparator(), szFolder2name, OTLog::PathSeparator(), szFilename);	
		return false;
	}
	else 
		OTLog::vOutput(2, "Successfully saved %s: %s%s%s%s%s\n", pszType, 
					   szFolder1name, OTLog::PathSeparator(), szFolder2name, OTLog::PathSeparator(), szFilename);
	// --------------------------------------------------------------------
	
	return bSaved;
}


// If you're going to save this, make sure you sign it first.
bool OTLedger::SaveInbox()
{
	
//	OTString strTempBlah, strTempBlah2(*this);
//	GetIdentifier(strTempBlah);
//	OTLog::vError("OTLedger::SaveInbox: DEBUGGING: SAVING INBOX for account: %s, number of transactions currently in the inbox: %d \n\n STACK TRACE:\n\n",
//				  strTempBlah.Get(), GetTransactionCount());
//
//	print_stacktrace();
	
//	OTLog::vError("OTLedger::SaveInbox: (CONTINUED DEBUGGING):  INBOX CONTENTS: \n\n%s\n\n",
//				  strTempBlah2.Get());

	
	if (m_Type != OTLedger::inbox)
	{
		OTLog::Error("Wrong ledger type passed to OTLedger::SaveInbox.\n");
		return false;
	}
	
	return SaveGeneric(m_Type);
}


// If you're going to save this, make sure you sign it first.
bool OTLedger::SaveOutbox()
{
	if (m_Type != OTLedger::outbox)
	{
		OTLog::Error("Wrong ledger type passed to OTLedger::SaveOutbox.\n");
		return false;
	}
	
	return SaveGeneric(m_Type);
}

// If you're going to save this, make sure you sign it first.
bool OTLedger::SaveNymbox()
{
	if (m_Type != OTLedger::nymbox)
	{
		OTLog::Error("Wrong ledger type passed to OTLedger::SaveNymbox.\n");
		return false;
	}
	
	return SaveGeneric(m_Type);
}


OTLedger * OTLedger::GenerateLedger(const OTIdentifier & theUserID,
									const OTIdentifier & theAcctID, // AcctID should be "OwnerID" since could be acct OR Nym (with nymbox)
									const OTIdentifier & theServerID, 
									const ledgerType theType,
									bool  bCreateFile/*=false*/)
{
	OTLedger * pLedger = new OTLedger(theUserID, theAcctID, theServerID);
	
	OT_ASSERT(NULL != pLedger);
	
	pLedger->GenerateLedger(theAcctID, theServerID, theType, bCreateFile);
	pLedger->SetUserID(theUserID);

	return pLedger;
}



bool OTLedger::GenerateLedger(const OTIdentifier & theAcctID, 
							  const OTIdentifier & theServerID, const ledgerType theType,
							  bool bCreateFile/*=false*/)
{	
	// First we set the "Safe" ID and try to load the file, to make sure it doesn't already exist.
	OTString strID(theAcctID), strServerID(theServerID);
	
	switch (theType) {
		case OTLedger::nymbox:
			m_strFoldername = OTLog::NymboxFolder();
			m_strFilename.Format("%s%s%s", strServerID.Get(), OTLog::PathSeparator(), strID.Get());
			break;
		case OTLedger::inbox:
			m_strFoldername = OTLog::InboxFolder();
			m_strFilename.Format("%s%s%s", strServerID.Get(), OTLog::PathSeparator(), strID.Get());
			break;
		case OTLedger::outbox:
			m_strFoldername = OTLog::OutboxFolder();
			m_strFilename.Format("%s%s%s", strServerID.Get(), OTLog::PathSeparator(), strID.Get());
			break;
		case OTLedger::message:
			OTLog::Output(4, "Generating message ledger...\n");
			SetRealAccountID(theAcctID);
			SetPurportedAccountID(theAcctID);	// It's safe to set these the same here, since we're creating the ledger now.
			SetRealServerID(theServerID);
			SetPurportedServerID(theServerID);	// Always want the server ID on anything that the server signs.
			m_Type	= theType;
			return true;
		default:
			OT_ASSERT_MSG(false, "OTLedger::GenerateLedger: GenerateLedger is only for message, inbox, outbox, and nymbox ledgers.\n");
			return false; // this return is unecessary because of the assert. But I like having it anyway.
	}
	
	m_Type	= theType; // Todo make this Get/Set methods

	SetRealAccountID(theAcctID); // set this before calling LoadContract... (In this case, will just be the Nym ID as well...)
	SetRealServerID(theServerID); // (Ledgers/transactions/items were originally meant just for account-related functions.)

	if (bCreateFile)
	{
		// --------------------------------------------------------------------
		OTString strFilename;
		strFilename = strID.Get();
		
		const char * szFolder1name	= m_strFoldername.Get(); // "nymbox" (or "inbox" or "outbox")
		const char * szFolder2name	= strServerID.Get();     // "nymbox/SERVER_ID"
		const char * szFilename		= strFilename.Get();     // "nymbox/SERVER_ID/USER_ID"  (or "inbox/SERVER_ID/ACCT_ID" or "outbox/SERVER_ID/ACCT_ID")
		// --------------------------------------------------------------------	
		
		if (OTDB::Exists(szFolder1name, szFolder2name, szFilename))
		{
			OTLog::vOutput(0, "ERROR: trying to generate ledger that already exists: %s%s%s%s%s\n", 
						   szFolder1name, OTLog::PathSeparator(), szFolder2name, OTLog::PathSeparator(), szFilename);
			return false;
		}
		// --------------------------------------------------------------------
	
		// Okay, it doesn't already exist. Let's generate it.
		OTLog::vOutput(0, "Generating %s%s%s%s%s\n", 
					   szFolder1name, OTLog::PathSeparator(), szFolder2name, OTLog::PathSeparator(), szFilename);
	}
	// --------------------------------------------------
	if (OTLedger::nymbox != theType)
	{
		// Have to look up the UserID here. No way around it.
		// Plus it helps verify things.
		OTAccount * pAccount = OTAccount::LoadExistingAccount(theAcctID, theServerID);
		OTCleanup<OTAccount> theAccountGuardian(pAccount); // No worries about having to clean it up.
		
		if (NULL != pAccount)
			SetUserID(pAccount->GetUserID());
	}
	else 
	{
		SetUserID(theAcctID); // In the case of nymbox, the acct ID IS the user ID. (Should change it to "owner ID" to make it sound right either way.)
	}

	// Notice I still don't actually create the file here.  The programmer still has to call 
	// "SaveNymbox", "SaveInbox" or "SaveOutbox" to actually save the file. But he cannot do that unless he
	// generates it first here, and the "bCreateFile" parameter insures that he isn't overwriting
	// one that is already there (even if we don't actually save the file in this function.)
	//
	SetPurportedAccountID(theAcctID);
	SetPurportedServerID(theServerID);
	
	return true;	
}





void OTLedger::InitLedger()
{
	m_strContractType	= "LEDGER"; // CONTRACT, MESSAGE, TRANSACTION, LEDGER, TRANSACTION ITEM 
	
	// This is the default type for a ledger.
	// Inboxes and Outboxes are generated with the right type, with files.
	// Until the GenerateLedger function is called, message is the default type.
	m_Type = OTLedger::message;
	
	m_bLoadedLegacyData = false;
}


// ID refers to account ID.
// Since a ledger is normally used as an inbox for a specific account, in a specific file,
// then I've decided to restrict ledgers to a single account.
OTLedger::OTLedger(const OTIdentifier & theUserID, const OTIdentifier & theAccountID, const OTIdentifier & theServerID)
: OTTransactionType(theUserID, theAccountID, theServerID), m_Type(OTLedger::message), m_bLoadedLegacyData(false)
{
	InitLedger();
}

// ONLY call this if you need to load a ledger where you don't already know the person's UserID
// For example, if you need to load someone ELSE's inbox in order to send them a transfer, then
// you only know their account number, not their user ID. So you call this function to get it
// loaded up, and the UserID will hopefully be loaded up with the rest of it.
OTLedger::OTLedger(const OTIdentifier & theAccountID, const OTIdentifier & theServerID)
: OTTransactionType(), m_Type(OTLedger::message), m_bLoadedLegacyData(false)
{
	InitLedger();
	
	SetRealAccountID(theAccountID);
	SetRealServerID(theServerID);
}

// This is private now and hopefully will stay that way.
OTLedger::OTLedger() : OTTransactionType(), m_Type(OTLedger::message), m_bLoadedLegacyData(false)
{
	InitLedger();
}
// -------------------------------------------------------



mapOfTransactions & OTLedger::GetTransactionMap()
{
	return m_mapTransactions;
}

/// If transaction #87, in reference to #74, is in the inbox, you can remove it
/// by calling this function and passing in 87.
///
bool OTLedger::RemoveTransaction(long lTransactionNum) // if false, transaction wasn't found.
{
	// See if there's something there with that transaction number.
	mapOfTransactions::iterator it = m_mapTransactions.find(lTransactionNum);
	
	// If it's not already on the list, then there's nothing to remove.
	if ( it == m_mapTransactions.end() )
	{
		OTLog::vError("Attempt to remove Transaction from ledger, when not already there: %ld\n",
					  lTransactionNum);
		return false;
	}
	// Otherwise, if it WAS already there, remove it properly.
	else 
	{
		OTTransaction * pTransaction = (*it).second;
		OT_ASSERT(NULL != pTransaction);
		
		m_mapTransactions.erase(it);
		delete pTransaction;
		return true;
	}
	
	return false;
}

/// If transaction #87, in reference to #74, is in the inbox, you can remove it
/// by calling this function and passing in 74.
///
bool OTLedger::RemovePendingTransaction(long lTransactionNum) // if false, transaction wasn't found.
{	
	// loop through the items that make up this transaction.
	OTTransaction * pTransaction = NULL;
	
	mapOfTransactions::iterator temp_it;
	
	FOR_EACH(mapOfTransactions, m_mapTransactions)
	{
		temp_it = it;
		
		pTransaction = (*it).second;
		OT_ASSERT(NULL != pTransaction);
		
		bool bCorrectType = false;
		
		switch (pTransaction->GetType()) 
		{
			case OTTransaction::pending:
			case OTTransaction::transferReceipt:
			case OTTransaction::chequeReceipt:
				bCorrectType = true;
				break;
			default:
				break;
		}
		
		if (bCorrectType && pTransaction->GetReferenceToNum() == lTransactionNum)
			break;
		else
			pTransaction = NULL;
		
	}
	
	// If it's not already on the list, then there's nothing to remove.
	if ( NULL == pTransaction )
	{
		OTLog::vError("OTLedger::RemovePendingTransaction: Attempt to remove Transaction from ledger,\n"
					  "when not already there: (the number in reference to) %ld\n",
					  lTransactionNum);
		return false;
	}
	// Otherwise, if it WAS already there, remove it properly.
	else 
	{		
		m_mapTransactions.erase(temp_it);
		delete pTransaction;
		return true;		
	}
	
	return false;
}





bool OTLedger::AddTransaction(OTTransaction & theTransaction)
{
	// See if there's something else already there with the same transaction number.
	mapOfTransactions::iterator it = m_mapTransactions.find(theTransaction.GetTransactionNum());
	
	// If it's not already on the list, then add it...
	if ( it == m_mapTransactions.end() )
	{
		m_mapTransactions[theTransaction.GetTransactionNum()] = &theTransaction;
		theTransaction.SetParent(*this); // for convenience
		return true;
	}
	// Otherwise, if it was already there, log an error.
	else 
	{
		OTLog::vError("Attempt to add Transaction to ledger when already there for that number: %ld\n",
					  theTransaction.GetTransactionNum());
	}
	
	return false;
}





// While processing a transaction, you may wish to query it for items of a certain type.
OTTransaction * OTLedger::GetTransaction(const OTTransaction::transactionType theType) 
{
	// loop through the items that make up this transaction
	
	FOR_EACH(mapOfTransactions, m_mapTransactions)
	{
		OTTransaction * pTransaction = (*it).second;
		OT_ASSERT(NULL != pTransaction);
		
		if (theType == pTransaction->GetType())
			return pTransaction;
	}
	
	return NULL;
}



// Look up a transaction by transaction number and see if it is in the ledger.
// If it is, return a pointer to it, otherwise return NULL.
OTTransaction * OTLedger::GetTransaction(long lTransactionNum)
{
	// loop through the items that make up this transaction
	
//  OTLog::vError("OTLedger::GetTransaction: Checking ledger for trans %ld. COUNT: %d \n", lTransactionNum, GetTransactionCount());
    
	FOR_EACH(mapOfTransactions, m_mapTransactions)
	{
		OTTransaction * pTransaction = (*it).second;
		OT_ASSERT(NULL != pTransaction);
		
//      OTLog::vError("OTLedger::GetTransaction: Looping. Currently on trans %ld \n", pTransaction->GetTransactionNum());
        
		if (pTransaction->GetTransactionNum() == lTransactionNum)
        {
//          OTLog::vOutput(5, "OTLedger::GetTransaction: Returning transaction# %ld \n", lTransactionNum);
            
			return pTransaction;
        }
//		else // this was for debugging only. It's actually normal for non-matching numbers to be on this list.
//			OTLog::vOutput(5"Expected transaction number %ld, but found %ld on the list instead. Bad data?\n",
//						  lTransactionNum, pTransaction->GetTransactionNum());
	}
	
//        OTLog::Error("OTLedger::GetTransaction: Returning NULL \n");

	return NULL;
}



// Return a count of all the transactions in this ledger that are IN REFERENCE TO a specific trans#.
//
// Might want to change this so that it only counts ACCEPTED receipts.
//
int OTLedger::GetTransactionCountInRefTo(const long lReferenceNum)
{
    int nCount = 0;
    
	FOR_EACH(mapOfTransactions, m_mapTransactions)
	{
		OTTransaction * pTransaction = (*it).second;
		OT_ASSERT(NULL != pTransaction);
		
        if (pTransaction->GetReferenceToNum() == lReferenceNum)
            nCount++;
	}
	
	return nCount;
}




// Look up a transaction by transaction number and see if it is in the ledger.
// If it is, return a pointer to it, otherwise return NULL.
OTTransaction * OTLedger::GetTransactionByIndex(int nIndex)
{
	// Out of bounds.
	if ((nIndex < 0) || (nIndex >= GetTransactionCount()))
		return NULL;
	
	int nIndexCount = -1;
	
	FOR_EACH(mapOfTransactions, m_mapTransactions)
	{
		nIndexCount++; // On first iteration, this is now 0, same as nIndex.
		OTTransaction * pTransaction = (*it).second; 
		OT_ASSERT((NULL != pTransaction)); // Should always be good.
		
		// If this transaction is the one at the requested index
		if (nIndexCount == nIndex)
			return pTransaction;
	}
	
	return NULL; // Should never reach this point, since bounds are checked at the top.
}


		
		
// If you TRANSFER REQUEST to me (transaction #1), then the server will create a 
// PENDING transaction in my inbox (transaction #41) and a PENDING transaction in 
// your outbox (also transaction #41) which both contain a copy of transaction#1 in their
// "In Reference To" ascii-armored field.
//
// The above function would look up #41 in my inbox, or #41 in your outbox, but
// you could NOT pass #1 to that function and get a pointer back. You'd get NULL.
// But the below function specifically returns the pointer of a transaction ONLY
// IF THE "IN REFERENCE TO" Transaction ID matches the one passed in (such as #1
// in the example above.
// If it can't find anything, it will return NULL.
OTTransaction * OTLedger::GetPendingTransaction(long lTransactionNum)
{
	// loop through the transactions that make up this ledger.
	//
	FOR_EACH(mapOfTransactions, m_mapTransactions)
	{
		OTTransaction * pTransaction = (*it).second;
		OT_ASSERT(NULL != pTransaction);
		
		if (pTransaction->GetReferenceToNum() == lTransactionNum)
			return pTransaction;
	}
	
	return NULL;
}

// Find the finalReceipt in this Inbox, that has lTransactionNum as its "in reference to".
// This is useful for cases where a marketReceipt or paymentReceipt has been found,
// yet the transaction # for that receipt isn't on my issued list... it's been closed.
// Normally this would be a problem: why is it in my inbox then? Because those receipts
// are still valid as long as there is a "FINAL RECEIPT" in the same inbox, that references
// the same original transaction that they do.  The below function makes it easy to find that
// final receipt, if it exists.
//
OTTransaction * OTLedger::GetFinalReceipt(long lReferenceNum)
{
	// loop through the items that make up this transaction.
	FOR_EACH(mapOfTransactions, m_mapTransactions)
	{
		OTTransaction * pTransaction = (*it).second;
		OT_ASSERT(NULL != pTransaction);
		
        if (OTTransaction::finalReceipt != pTransaction->GetType()) // <=======
            continue;
        // ---------------------------------
		if (pTransaction->GetReferenceToNum() == lReferenceNum)
			return pTransaction;
	}
	
	return NULL;
}

// If my outbox has a pending transfer, #1901, referencing 1884, and then the 
// recipient accepts it with his #781, referencing 1884, then it will pop into my inbox
// as a transfer receipt, #1902 (say) and referencing 781. Attached to that
// transfer receipt is a copy of the actual #781, which is in reference to 1884.
//
// Why does this matter? Because when I am verifying a balance agreement, and an
// outbox item 1901/1884 is missing, that means there is probably a corresponding 
// transferReceipt in the Inbox. In that case, I START with #1901 referencing 1884 (from
// the outbox) and I need to FIND #1902, in reference to 781, referencing 1884 in the inbox.
//
// Therefore, loop through all items and filter by transfer receipt. For each, load its
// Reference string (containing the acceptPending) and get ITS ReferenceNum() to compare
// to the one passed in.
//
// Therefore 1884 would be passed in, and the appropriate transferReceipt will be returned.
//
OTTransaction * OTLedger::GetTransferReceipt(long lTransactionNum)
{
	// loop through the items that make up this transaction.
	FOR_EACH(mapOfTransactions, m_mapTransactions)
	{
		OTTransaction * pTransaction = (*it).second;
		OT_ASSERT(NULL != pTransaction);
		
		if (OTTransaction::transferReceipt == pTransaction->GetType())
		{
			OTString strReference;
			pTransaction->GetReferenceString(strReference);
			
			OTItem * pOriginalItem = OTItem::CreateItemFromString(strReference, 
																  pTransaction->GetPurportedServerID(), 
																  pTransaction->GetReferenceToNum()); 
			OT_ASSERT(NULL != pOriginalItem);
			OTCleanup<OTItem> theItemAngel(*pOriginalItem);
			
			if (pOriginalItem->GetType() != OTItem::acceptPending) 
			{
				OTLog::Error("OTLedger::GetTransferReceipt: Wrong item type attached to transferReceipt!\n");
				return NULL;
			}
			else 
			{
				if (pOriginalItem->GetReferenceToNum() == lTransactionNum)
					return pTransaction; // FOUND IT!
			}
		}
	}
	
	return NULL;
}


/// Only if it is an inbox, a ledger will loop through the transactions
/// and produce the XML output for the report that's necessary during
/// a balance agreement. (Any balance agreement for an account must
/// include the list of transactions the nym has issued for use, as
/// well as a listing of the transactions in the inbox for that account.
/// This function does that last part :)
///
/// returns a new balance statement item containing the inbox report
/// CALLER IS RESPONSIBLE TO DELETE.
OTItem * OTLedger::GenerateBalanceStatement(const long lAdjustment, const OTTransaction & theOwner, 
											OTPseudonym & theNym, const OTAccount & theAccount, OTLedger & theOutbox) 
{
	if (OTLedger::inbox != GetType())
	{
		OTLog::Error("OTLedger::GenerateBalanceStatement: Wrong ledger type.\n");
		return NULL;
	}
	
	// ------------------------------------------------------
	
	const OTIdentifier theNymID(theNym);
	
	if (
		(theAccount.GetPurportedAccountID()	!= GetPurportedAccountID()) ||
		(theAccount.GetPurportedServerID()	!= GetPurportedServerID()) ||
		(theAccount.GetUserID()				!= GetUserID()) )
	{
		OTLog::Error("Wrong Account passed in to OTLedger::GenerateBalanceStatement.\n");
		return NULL;
	}
	if (
		(theOutbox.GetPurportedAccountID()	!= GetPurportedAccountID()) ||
		(theOutbox.GetPurportedServerID()	!= GetPurportedServerID()) ||
		(theOutbox.GetUserID()				!= GetUserID()) )
	{
		OTLog::Error("Wrong Outbox passed in to OTLedger::GenerateBalanceStatement.\n");
		return NULL;
	}
	if (
		(theNymID	!= GetUserID()))
	{
		OTLog::Error("Wrong Nym passed in to OTLedger::GenerateBalanceStatement.\n");
		return NULL;
	}
	// ---------------------------------------------------------

	// theOwner is the withdrawal, or deposit, or whatever, that wants to change
	// the account balance, and thus that needs a new balance agreement signed.
	//
	OTItem * pBalanceItem = OTItem::CreateItemFromTransaction(theOwner, OTItem::balanceStatement); // <=== balanceStatement type, with user ID, server ID, account ID, transaction ID.

	// The above has an ASSERT, so this this will never actually happen.
	if (NULL == pBalanceItem)
		return NULL;
	
	// ---------------------------------------------------------
	
	// COPY THE ISSUED TRANSACTION NUMBERS FROM THE NYM to the MESSAGE NYM.
	
	OTPseudonym theMessageNym;
	    
	theMessageNym.HarvestIssuedNumbers(this->GetPurportedServerID(), 
                                       theNym /*unused in this case, not saving to disk*/, theNym, false); // bSave = false;
	
	// -------------------------------------
	
    
    
	switch (theOwner.GetType()) 
	{
			// These five options will remove the transaction number from the issued list, SUCCESS OR FAIL.
			// Server will expect the number to be missing from the list, in the case of these.
			// Therefore I remove it here in order to generate a proper balance agreement, acceptable to the server.
		case OTTransaction::processInbox:
		case OTTransaction::deposit:
		case OTTransaction::withdrawal:
        case OTTransaction::cancelCronItem:
		case OTTransaction::exchangeBasket:

			theMessageNym.RemoveIssuedNum(theOwner.GetRealServerID(), theOwner.GetTransactionNum());  // a transaction number is being used, and REMOVED from my list of responsibility,
			theMessageNym.RemoveTransactionNum(theOwner.GetRealServerID(), theOwner.GetTransactionNum());  // a transaction number is being used, and REMOVED from my list of  available numbers.
			break;
		case OTTransaction::transfer:
		case OTTransaction::marketOffer:
		case OTTransaction::paymentPlan:
		case OTTransaction::smartContract:
			// Nothing removed here since the transaction is still in play. (Assuming success.)
			// If the server replies with rejection for any of these three, then I can remove
			// the transaction number from my list of issued/signed for. But if success, then I
			// am responsible for the transaction number until I sign off on closing it.
			// Since the Balance Statement ANTICIPATES SUCCESS, NOT FAILURE, it assumes the number
			// to be "in play" here, and thus DOES NOT remove it (vs the cases above, which do.)
			break;
		default: 
			// Error
			OTLog::vError("OTLedger::GenerateBalanceStatement: wrong owner transaction type: %s\n",
						  theOwner.GetTypeString());
			break;
	}
	
	OTString	strMessageNym(theMessageNym); // Okay now we have the transaction numbers in this MessageNym string.

	pBalanceItem->SetAttachment(strMessageNym);				// <======== This is where the server will read the transaction numbers from (A nym in item.m_ascAttachment)
	
	// ---------------------------------------------------------

	long lCurrentBalance = theAccount.GetBalance();
	
	pBalanceItem->SetAmount(lCurrentBalance + lAdjustment);  // <==== Here's the new (predicted) balance for after the withdrawal is complete. (item.GetAmount)
	
	// ---------------------------------------------------------
	// loop through the INBOX transactions, and produce a sub-item onto pBalanceItem for each, which will
	// be a report on each transaction in this inbox, therefore added to the balance item.
	// (So the balance item contains a complete report on the receipts in this inbox.)
	
	OTLog::Output(2, "About to loop through the inbox items and produce a report for each one...\n");
	
	FOR_EACH(mapOfTransactions, m_mapTransactions)
	{
		OTTransaction * pTransaction = (*it).second;
		OT_ASSERT(NULL != pTransaction);
		
		OTLog::Output(2, "Producing a report...\n");

		// it only reports receipts where we don't yet have balance agreement.
//      pTransaction->ProduceInboxReportItem(*pBalanceItem, const_cast<OTTransaction &>(theOwner));
		pTransaction->ProduceInboxReportItem(*pBalanceItem);	// <======= This function adds a receipt sub-item to pBalanceItem, where appropriate for INBOX items.
	}
	
	// ---------------------------------------------------------
	
	theOutbox.ProduceOutboxReport(*pBalanceItem);	// <======= This function adds receipt sub-items to pBalanceItem, where appropriate for the OUTBOX items.
	
	// ---------------------------------------------------------
	
	pBalanceItem->SignContract(theNym); // <=== Sign, save, and return. OTTransactionType needs to weasel in a "date signed" variable.
	pBalanceItem->SaveContract();
	
	return pBalanceItem;
}




// for inbox only, allows you to lookup the total value of pending transfers within the inbox.
// (And it really loads the items to check the amount, but does all this ONLY for pending transfers.)
//
long OTLedger::GetTotalPendingValue()
{
	long lTotalPendingValue = 0;
	
	if (OTLedger::inbox != GetType())
	{
		OTLog::Error("OTLedger::GetTotalPendingValue: Wrong ledger type (expected inbox).\n");
		return 0;
	}
	
	FOR_EACH(mapOfTransactions, m_mapTransactions)
	{
		OTTransaction * pTransaction = (*it).second;
		OT_ASSERT(NULL != pTransaction);
		
		if (pTransaction->GetType() == OTTransaction::pending)
			lTotalPendingValue += pTransaction->GetReceiptAmount(); // this actually loads up the original item and reads the amount.
	}	
	
	return lTotalPendingValue;
}



// Called by the above function.
// This ledger is an outbox, and it is creating a report of itself, 
// adding each report item to this balance item.
// DO NOT call this, it's meant to be used only by above function.
void OTLedger::ProduceOutboxReport(OTItem & theBalanceItem)  
{
	if (OTLedger::outbox != GetType())
	{
		OTLog::Error("OTLedger::ProduceOutboxReport: Wrong ledger type.\n");
		return;
	}
	
	// loop through the OUTBOX transactions, and produce a sub-item onto theBalanceItem for each, which will
	// be a report on each pending transfer in this outbox, therefore added to the balance item.
	// (So the balance item contains a complete report on the outoing transfers in this outbox.)
	FOR_EACH(mapOfTransactions, m_mapTransactions)
	{
		OTTransaction * pTransaction = (*it).second;
		OT_ASSERT(NULL != pTransaction);
		
		// it only reports receipts where we don't yet have balance agreement.
		pTransaction->ProduceOutboxReportItem(theBalanceItem);	// <======= This function adds a pending transfer sub-item to theBalanceItem, where appropriate.
	}
	
	// ---------------------------------------------------------	
}




// Auto-detects ledger type. (message/nymbox/inbox/outbox)
// Use this instead of LoadContractFromString (for ledgers,
// for when you don't know their type already.)
// Otherwise if you know the type, then use LoadNymboxFromString() etc.
//
bool OTLedger::LoadLedgerFromString(const OTString & theStr)
{
	bool bLoaded = false;
	
	if (theStr.Contains("\"\n type=\"nymbox\""))
		bLoaded = this->LoadNymboxFromString(theStr);
	else if (theStr.Contains("\"\n type=\"inbox\""))
		bLoaded = this->LoadInboxFromString(theStr);
	else if (theStr.Contains("\"\n type=\"outbox\""))
		bLoaded = this->LoadOutboxFromString(theStr);
	else if (theStr.Contains("\"\n type=\"message\""))
	{
		m_Type	= OTLedger::message;
		bLoaded = this->LoadContractFromString(theStr);
	}
	return bLoaded;
}



// SignContract will call this function at the right time.
void OTLedger::UpdateContents() // Before transmission or serialization, this is where the ledger saves its contents 
{
	bool	bSavingAbbreviated	= true;	// The default. Only OTLedger::message changes this to false.
	int		nPartialRecordCount	= 0;	// We store this, so we know how many abbreviated records to read back later.
	
	// --------------------------------
	switch (this->GetType()) 
	{
			// a message ledger stores the full receipts directly inside itself. (No separate files.)
		case OTLedger::message:
			bSavingAbbreviated	= false; 
			nPartialRecordCount	= 0; // In this case (OTLedger::message), they are all FULL records, not abbreviated.
			break;
			// -----------------------------
			// These store abbreviated versions of themselves, with the actual receipts in separate files.
			// Those separate files are created on server side when first added to the box, and on client
			// side when downloaded from the server. They must match the hash that appears in the box.
		case OTLedger::inbox:
		case OTLedger::outbox:
		case OTLedger::nymbox:
			bSavingAbbreviated	= true;
			nPartialRecordCount	= m_mapTransactions.size(); // We store this, so we know how many abbreviated records to read back later.
			break;
			// -----------------------------
		default:
			OTLog::Error("OTLedger::UpdateContents: Error: unexpected box type (1st block). (This should never happen.)\n");
			return;
	}
	// --------------------------------
	//
	// Notice I use the PURPORTED Account ID and Server ID to create the output. That's because
	// I don't want to inadvertantly substitute the real ID for a bad one and then sign it.
	// So if there's a bad one in there when I read it, THAT's the one that I write as well!
	//
	OTString	strType(GetTypeString()), 
				strLedgerAcctID(GetPurportedAccountID()), 
				strLedgerAcctServerID(GetPurportedServerID()),
				strUserID(GetUserID());
	
	// -----------------------------------------
	
	// I release this because I'm about to repopulate it.
	m_xmlUnsigned.Release();
	
//	m_xmlUnsigned.Concatenate("<?xml version=\"%s\"?>\n\n", "1.0");		
	
	m_xmlUnsigned.Concatenate("<accountLedger version=\"%s\"\n "
							  "type=\"%s\"\n "
							  "numPartialRecords=\"%d\"\n "
							  "accountID=\"%s\"\n "
							  "userID=\"%s\"\n "
							  "serverID=\"%s\" >\n\n", m_strVersion.Get(), 
							  strType.Get(),
							  nPartialRecordCount,
							  strLedgerAcctID.Get(), 
							  strUserID.Get(), 
							  strLedgerAcctServerID.Get());		
	
	// loop through the transactions and print them out here.
	FOR_EACH(mapOfTransactions, m_mapTransactions)
	{
		OTTransaction * pTransaction = (*it).second;
		OT_ASSERT(NULL != pTransaction);
		// ------------------------------
		OTString strTransaction;
		// ------------------------------
		if (false == bSavingAbbreviated) // only OTLedger::message uses this block.
		{	// Save the FULL version of the receipt inside the box, so no separate files are necessary.
			//
			pTransaction->SaveContractRaw(strTransaction);
			OTASCIIArmor ascTransaction;
			ascTransaction.SetString(strTransaction, true); // linebreaks = true
			m_xmlUnsigned.Concatenate("<transaction>\n%s</transaction>\n\n", ascTransaction.Get());
		}
		// ------------------------------
		else // true == bSavingAbbreviated	// ALL OTHER ledger types are saved here in abbreviated form.
		{
			switch (this->GetType()) 
			{
					// -----------------------------
				case OTLedger::inbox:	pTransaction->SaveAbbreviatedInboxRecord(strTransaction);	break;
				case OTLedger::outbox:	pTransaction->SaveAbbreviatedOutboxRecord(strTransaction);	break;
				case OTLedger::nymbox:	pTransaction->SaveAbbreviatedNymboxRecord(strTransaction);	break;
					// -----------------------------
				default: // todo: possibly change this to an OT_ASSERT. security.
					OTLog::Error("OTLedger::UpdateContents: Error: unexpected box type (2nd block). (This should never happen. Skipping.)\n");
					continue;
			}
			m_xmlUnsigned.Concatenate("%s", strTransaction.Get());
		} // ------------------------------
	}// FOR_EACH(transactions)
	
	m_xmlUnsigned.Concatenate("</accountLedger>\n");				
}


// LoadContract will call this function at the right time.
// return -1 if error, 0 if nothing, and 1 if the node was processed.
int OTLedger::ProcessXMLNode(irr::io::IrrXMLReader*& xml)
{	
	if (!strcmp("accountLedger", xml->getNodeName()))
	{	
		OTString	strType,  // ledger type
					strLedgerAcctID, // purported
					strLedgerAcctServerID, // purported
					strUserID,
					strNumPartialRecords; // Ledger contains either full receipts, or abbreviated receipts with hashes and partial data.
		// ------------------------------------------------------------------
		strType			= xml->getAttributeValue("type");
		m_strVersion	= xml->getAttributeValue("version");
		if (strType.Compare("message"))		// These are used for sending transactions in messages. (Withdrawal request, etc.)
			m_Type = OTLedger::message;
		else if (strType.Compare("inbox"))	// These are used for storing the receipts in your inbox. (That server must store until signed-off.)
			m_Type = OTLedger::inbox;
		else if (strType.Compare("outbox"))	// Outgoing, pending transfers.
			m_Type = OTLedger::outbox;
		else if (strType.Compare("nymbox"))	// Used for receiving new transaction numbers, and for receiving notices.
			m_Type = OTLedger::nymbox;
		else
			m_Type = OTLedger::error_state;	// Danger, Will Robinson.
		// ------------------------------------------------------------------
		strLedgerAcctID			= xml->getAttributeValue("accountID");
		strLedgerAcctServerID	= xml->getAttributeValue("serverID");
		strUserID				= xml->getAttributeValue("userID");
		if (!strLedgerAcctID.Exists() || !strLedgerAcctServerID.Exists() || !strUserID.Exists())
		{
			OTLog::vOutput(0, "OTLedger::ProcessXMLNode: Failure: missing strLedgerAcctID (%s) or "
						   "strLedgerAcctServerID (%s) or strUserID (%s) while loading transaction "
						   "from %s ledger. \n", strLedgerAcctID.Get(), strLedgerAcctServerID.Get(), 
						   strUserID.Get(), strType.Get());
			return (-1);			
		}
		// --------------------------------------------------------------
		OTIdentifier	ACCOUNT_ID(strLedgerAcctID),
						SERVER_ID(strLedgerAcctServerID),
						USER_ID(strUserID);
		// --------------------------------------------------------------
						SetPurportedAccountID(ACCOUNT_ID);
						SetPurportedServerID(SERVER_ID);
						SetUserID(USER_ID);		
		
		if (false ==  m_bLoadSecurely)
		{
			SetRealAccountID(ACCOUNT_ID);
			SetRealServerID(SERVER_ID);
		}		
		// ------------------------------------------------------------------
		// Load up the partial records, based on the expected count...
		//
		strNumPartialRecords	= xml->getAttributeValue("numPartialRecords");
		int	nPartialRecordCount = (strNumPartialRecords.Exists() ? atoi(strNumPartialRecords.Get()) : 0);
		// -------------------------------------
		OTString strExpected;	// The record type has a different name for each box.
		switch (m_Type) 
		{
			case OTLedger::nymbox:	strExpected.Set("nymboxRecord");	break;
			case OTLedger::inbox:	strExpected.Set("inboxRecord");		break;
			case OTLedger::outbox:	strExpected.Set("outboxRecord");	break;
			case OTLedger::message:	
                if (nPartialRecordCount > 0) // -------------------
                {
					OTLog::vError("OTLedger::ProcessXMLNode: Error: There are %d unexpected abbreviated records in an "
                                  "OTLedger::message type ledger. (Failed loading ledger with accountID: %s)\n",
                                  nPartialRecordCount, strLedgerAcctID.Get());
					return (-1);
                }// -----------------------------------------------
				break;
			default:OTLog::vError("OTLedger::ProcessXMLNode: Unexpected ledger type (%s). (Failed loading "
                                  "ledger for account: %s)\n", strType.Get(), strLedgerAcctID.Get());
					return (-1);
		} // switch (to set strExpected to the abbreviated record type.)
		// -------------------------		
		if (nPartialRecordCount > 0) // message ledger will never enter this block due to switch block (above.)
		{
			// -------------------------------
            // We iterate to read the expected number of partial records from the xml.
            // (They had better be there...)
            //
			while (nPartialRecordCount-- > 0)
			{
//				xml->read(); // <==================
				if (false == SkipToElement(xml))
				{
					OTLog::Output(0, "OTLedger::ProcessXMLNode: Failure: Unable to find expected element "
                                  "for abbreviated record of receipt in box. \n");
					return (-1);
				}
				// -----------------------------------------------
				// strExpected can be one of:
				//
//				strExpected.Set("nymboxRecord");
//				strExpected.Set("inboxRecord");
//				strExpected.Set("outboxRecord");
                //
                // We're loading here either a nymboxRecord, inboxRecord, or outboxRecord...
                //
				if ((xml->getNodeType() == EXN_ELEMENT) && (!strcmp(strExpected.Get(), xml->getNodeName())))
				{
					long lTransactionNum	= 0;
					long lInRefTo			= 0;
					long lInRefDisplay		= 0;
					// -------------------------------------
					time_t the_DATE_SIGNED	= 0;
					OTTransaction::transactionType theType = OTTransaction::error_state; // default
					OTString strHash;
					// -------------------------------------
					long lAdjustment		= 0;
					long lDisplayValue		= 0;
					long lClosingNum		= 0;
					// -------------------------------------
					int nAbbrevRetVal =
						OTTransaction::LoadAbbreviatedRecord(xml,
															 lTransactionNum,
															 lInRefTo,
															 lInRefDisplay,
															 the_DATE_SIGNED,
															 theType,
															 strHash,
															 lAdjustment,
															 lDisplayValue,
															 lClosingNum);
					if ((-1) == nAbbrevRetVal)
						return (-1); // The function already logs appropriately.
					// -------------------------------------
					//
					// See if the same-ID transaction already exists in the ledger.
					// (There can only be one.)
					//
					OTTransaction * pExistingTrans = this->GetTransaction(lTransactionNum);
					if (NULL != pExistingTrans) // Uh-oh, it's already there!
					{
						OTLog::vOutput(0, "OTLedger::ProcessXMLNode: Error loading transaction %ld (%s), since one was "
									   "already there, in box for account: %s.\n", lTransactionNum, strExpected.Get(), 
									   strLedgerAcctID.Get());
						return (-1);
					}
					// ----------------------------------
					//
					// CONSTRUCT THE ABBREVIATED RECEIPT HERE...
										
					// Set all the values we just loaded here during actual construction of transaction 
                    // (as abbreviated transaction) i.e. make a special constructor for abbreviated transactions
                    // which is ONLY used here.
                    //
					OTTransaction * pTransaction = new OTTransaction(USER_ID, 
																	 ACCOUNT_ID, 
																	 SERVER_ID,
																	 lTransactionNum,
																	 lInRefTo,			// lInRefTo
																	 lInRefDisplay, 
																	 the_DATE_SIGNED, 
																	 theType,
																	 strHash,
																	 lAdjustment,
																	 lDisplayValue,
																	 lClosingNum);
					OT_ASSERT(NULL != pTransaction); // --------------------------------
					//
					// NOTE: For THIS CONSTRUCTOR ONLY, we DO set the purported AcctID and purported ServerID.
					// WHY? Normally you set the "real" IDs at construction, and then set the "purported" IDs
					// when loading from string. But this constructor (only this one) is actually used when 
					// loading abbreviated receipts as you load their inbox/outbox/nymbox.
					// Abbreviated receipts are not like real transactions, which have serverID, AcctID, userID,
					// and signature attached, and the whole thing is base64-encoded and then added to the ledger
					// as part of a list of contained objects. Rather, with abbreviated receipts, there are a series
					// of XML records loaded up as PART OF the ledger itself. None of these individual XML records
					// has its own signature, or its own record of the main IDs -- those are assumed to be on the parent
					// ledger.
					// That's the whole point: abbreviated records don't store redundant info, and don't each have their
					// own signature, because we want them to be as small as possible inside their parent ledger.
					// Therefore I will pass in the parent ledger's "real" IDs at construction, and immediately thereafter
					// set the parent ledger's "purported" IDs onto the abbreviated transaction. That way, VerifyContractID()
					// will still work and do its job properly with these abbreviated records.
					//
					// This part normally happens in "GenerateTransaction".
					// NOTE: Moved to OTTransaction constructor (for abbreviateds) for now.
					//
//                    pTransaction->SetPurportedAccountID(	this->GetPurportedAccountID());
//                    pTransaction->SetPurportedServerID(		this->GetPurportedServerID());
                    // --------------------------------------------------------------------
 					// Add it to the ledger's list of transactions...
					//
					if (pTransaction->VerifyContractID())
					{
                        // Add it to the ledger...
                        //
						m_mapTransactions[pTransaction->GetTransactionNum()] = pTransaction;
						pTransaction->SetParent(*this);
//                      OTLog::Output(5, "Loaded abbreviated transaction and adding to m_mapTransactions in OTLedger\n");
					}
					else 
					{
						OTLog::vError("ERROR: verifying contract ID on abbreviated transaction %ld in OTLedger::ProcessXMLNode\n",
									  pTransaction->GetTransactionNum());
						delete pTransaction;
						pTransaction = NULL;
						return (-1);
					}					
//					xml->read(); // <==================
					// MIGHT need to add "skip after element" here.
					//
					// Update: Nope.
				}
				else 
				{
					OTLog::Error("Expected abbreviated record element in OTLedger::ProcessXMLNode\n");
					return (-1); // error condition
				}
			} // while
		} //if (number of partial records > 0)
		// --------------------------------
		
		
		// ------------------------------------------------------------------
		OTLog::vOutput(2, "Loading account ledger of type \"%s\", version: %s\n",
//				"accountID:\n%s\n userID:\n%s\n serverID:\n%s\n----------\n",
				strType.Get(),
				m_strVersion.Get()
//				strLedgerAcctID.Get(), strUserID.Get(), strLedgerAcctServerID.Get()
				);
			
		// Since we just loaded this stuff, let's verify it.
		// We may have to remove this verification here and do it outside this call.
		// But for now...
				
		if (VerifyContractID())
			return 1;
		else 
			return (-1);
	}
	
	// Todo: When loading abbreviated list of records, set the m_bAbbreviated to true.
	// Then in THIS block below, if that is set to true, then seek an existing transaction instead of
	// instantiating a new one. Then repopulate the new one and verify the new values against the ones
	// that were already there before overwriting anything.
	
	// Hmm -- technically this code should only execute for OTLedger::message, and thus only if
	// m_bIsAbbreviated is FALSE. When the complete receipt is loaded, "LoadBoxReceipt()" will be
	// called, and it will directly load the transaction starting in OTTransaction::ProcessXMLNode().
	// THAT is where we must check for abbreviated mode and expect it already loaded etc etc. Whereas
	// here in this spot, we basically want to error out if it's not a message ledger.
	// UPDATE: However, I must consider legacy data. For now, I'll allow this to load in any type of box.
    // I also need to check and see if the box receipt already exists (since its normal creation point
    // may not have happened, when taking legacy data into account.) If it doesn't already exist, then I 
    // should save it again at this point.
    //
	else if (!strcmp("transaction", xml->getNodeName()))
	{
		OTString		strTransaction;
		OTASCIIArmor	ascTransaction;
				
		// go to the next node and read the text.
//		xml->read(); // <==================
		if (false == SkipToTextField(xml))
		{
			OTLog::Output(0, "OTLedger::ProcessXMLNode: Failure: Unable to find expected text field "
						  "containing receipt transaction in box. \n");
			return (-1);
		}
		// -----------------------------------------------
		
		if (EXN_TEXT == xml->getNodeType())
		{
			// the ledger contains a series of transactions.
			// Each transaction is initially stored as an OTASCIIArmor string.
			ascTransaction.Set(xml->getNodeData());		// Put the ascii-armored node data into the ascii-armor object
			
			// Decode that into strTransaction, so we can load the transaction object from that string.
			if (!ascTransaction.Exists() || !ascTransaction.GetString(strTransaction))
			{
				OTLog::vError("ERROR: Missing expected transaction contents in OTLedger::ProcessXMLNode for trans num: %ld (In Reference To: %ld)\n",
							  GetTransactionNum(), GetReferenceToNum());
				return (-1);
			}
			// ------------------------------
			// I belive we're only supposed to use purported numbers when loading/saving, and to compare them (as distrusted)
			// against a more-trusted source, in order to verify them. Whereas when actually USING the numbers (such as here,
			// when "GetRealAccountID()" is being used to instantiate the transaction, then you ONLY use numbers that you KNOW
			// are good (the number you were expecting) versus whatever number was actually in the file.
			// But wait, you ask, how do I know they are the same number then? Because you verified that when you first loaded
			// everything into memory. Right after "load" was a "verify" that makes sure the "real" account ID and the "purported"
			// account ID are actually the same.
			//
			// UPDATE: If this ledger is loaded from string, there's no guarantee that the real IDs have even been set.
			// In some cases (Factory...) they definitely have not been. It makes sense here when loading, to set the member
			// transactions to the same account/server IDs that were actually loaded for their parent ledger. Therefore, changing
			// back here to Purported values.
//			OTTransaction * pTransaction = new OTTransaction(GetUserID(), GetRealAccountID(), GetRealServerID());
			OTTransaction * pTransaction = new OTTransaction(GetUserID(), GetPurportedAccountID(), GetPurportedServerID());
			
			// Need this set before the LoadContractFromString().
			//
			if (false ==  m_bLoadSecurely)
				pTransaction->SetLoadInsecure();
			// -------------------------------------------
			
			// If we're able to successfully base64-decode the string and load it up as
			// a transaction, then let's add it to the ledger's list of transactions
			if ((NULL != pTransaction) && pTransaction->LoadContractFromString(strTransaction)
				&& pTransaction->VerifyContractID())
				// I responsible here to call pTransaction->VerifyContractID() since
				// I am loading it here and adding it to the ledger. (So I do.)
			{
				m_mapTransactions[pTransaction->GetTransactionNum()] = pTransaction;
				pTransaction->SetParent(*this);
//				OTLog::Output(5, "Loaded transaction and adding to m_mapTransactions in OTLedger\n");
                
                switch (this->GetType())
				{
					case OTLedger::message:		
						break;
					case OTLedger::nymbox:
					case OTLedger::inbox:
					case OTLedger::outbox:
					{
						// For the sake of legacy data, check for existence of box receipt here,
						// and re-save that box receipt if it doesn't exist.
						//
						OTLog::vOutput(0, "--- Apparently this is old data (the transaction is still stored inside the ledger itself)... \n");
						m_bLoadedLegacyData = true; // Only place this is set true.
						
						const int nBoxType = static_cast<int>(this->GetType());
						
						const bool bBoxReceiptAlreadyExists = 
							OTTransaction::VerifyBoxReceiptExists(pTransaction->GetRealServerID(),
																  pTransaction->GetUserID(),
																  pTransaction->GetRealAccountID(),	// If Nymbox (vs inbox/outbox) the USER_ID will be in this field also.
																  nBoxType,							// 0/nymbox, 1/inbox, 2/outbox
																  pTransaction->GetTransactionNum());
						if (false == bBoxReceiptAlreadyExists) // Doesn't already exist separately.
						{
							// Okay then, let's create it...
							//
							OTLog::vOutput(0, "--- The BoxReceipt doesn't exist separately (yet.) Creating it in local storage...\n");
							
							const long lBoxType = static_cast<long>(nBoxType);
							
							if (false == pTransaction->SaveBoxReceipt(lBoxType)) //  <======== SAVE BOX RECEIPT
								OTLog::Error("--- FAILED trying to save BoxReceipt from legacy data to local storage!\n");
						}
					}
						break;
					default:
						OTLog::Error("OTLedger::ProcessXMLNode: Unknown ledger type while loading transaction! (Should never happen.)\n");
						return (-1);
				} // switch (this->GetType())
			}	// if transaction loads and verifies.
			else 
			{
				OTLog::Error("ERROR: loading or verifying transaction in OTLedger::ProcessXMLNode\n");
				if (NULL != pTransaction)
				{
					delete pTransaction;
					pTransaction = NULL;
				}
				return (-1);
			}
		}
		else 
		{
			OTLog::Error("Error in OTLedger::ProcessXMLNode: transaction without value.\n");
			return (-1); // error condition
		}
		return 1;
	}
	
	return 0;
}


OTLedger::~OTLedger()
{
// No need to call Release() here, it's called already by the framework.
}


void OTLedger::ReleaseTransactions()
{
	// If there were any dynamically allocated objects, clean them up here.
	
	while (!m_mapTransactions.empty())
	{		
		OTTransaction * pTransaction = m_mapTransactions.begin()->second;
		m_mapTransactions.erase(m_mapTransactions.begin());
		delete pTransaction;
		pTransaction = NULL;
	}	
}

void OTLedger::Release()
{
	ReleaseTransactions();
	
	OTTransactionType::Release(); // since I've overridden the base class, I call it now...
}


bool OTLedger::SaveContractWallet(std::ofstream & ofs)
{
	return true;
}


































