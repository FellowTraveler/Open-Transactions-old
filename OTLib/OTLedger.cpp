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
	"message",	// used in OTMessages, to send various lists of transactions back and forth.
	"inbox",		// each asset account has an inbox, with pending transfers as well as receipts inside.
	"outbox",		// if you SEND a pending transfer, it sits in your outbox until it's accepted, rejected, or canceled.
	"nymbox",		// the nymbox is per user account (versus per asset account) and is used to receive new transaction numbers (and messages.)
	"error_state"
};



bool OTLedger::LoadGeneric(OTLedger::ledgerType theType)
{
	OTString strID;
	GetIdentifier(strID);
	
	m_Type = theType;
	
	const char * pszFolder = NULL;
	const char * pszType = GetTypeString();
	
	switch (theType) 
	{
		case OTLedger::inbox:
			pszFolder = OTLog::InboxFolder();
			break;
		case OTLedger::outbox:
			pszFolder = OTLog::OutboxFolder();
			break;
		case OTLedger::nymbox:
			pszFolder = OTLog::NymboxFolder();
			break;
		default:
			return false;
	}
	// --------------------------------------------------------
	
	m_strFoldername = pszFolder;
	m_strFilename = strID.Get();
	
	const char * szFoldername = m_strFoldername.Get();
	const char * szFilename = m_strFilename.Get();
	
	// --------------------------------------------------------------------
	
	if (false == OTDB::Exists(szFoldername, szFilename))
	{
		OTLog::vOutput(3, "%s does not exist in OTLedger::Load%s:\n%s%s%s\n", pszType,
					   pszType, m_strFoldername.Get(), OTLog::PathSeparator(), m_strFilename.Get());
		return false;
	}
	
	// --------------------------------------------------------------------
	
	// Try to load the ledger from disk.
	else if (false == LoadContract())
	{
		OTLog::vError("Failed loading %s in OTLedger::Load%s:\n%s%s%s\n", 
					  pszType, pszType, m_strFoldername.Get(), OTLog::PathSeparator(), m_strFilename.Get());
		return false;
	}
	else 
	{
		OTLog::vOutput(2, "Successfully loaded %s in OTLedger::Load%s:\n%s%s%s\n", 
					   pszType, pszType, m_strFoldername.Get(), OTLog::PathSeparator(), m_strFilename.Get());
	}
	
	return true;	
}



// the below four functions (load/save in/outbox) assume that the ID is already set
// properly.
// Then it uses the ID to form the path for the file that is opened. Easy, right?

bool OTLedger::LoadInbox()
{
//	OTString strTempBlah;
//	GetIdentifier(strTempBlah);
//	OTLog::vError("OTLedger::LoadInbox: DEBUGGING: LOADING INBOX for account: %s \n STACKTRACE:\n\n",
//				  strTempBlah.Get());
//	
//	print_stacktrace();
	
	bool bRetVal = LoadGeneric(OTLedger::inbox);
	
//	OTLog::vError("OTLedger::LoadInbox: CONTINUED DEBUGGING: Number of transactions in the Inbox: %d\n\n",
//				  GetTransactionCount());

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


bool OTLedger::SaveGeneric(OTLedger::ledgerType theType)
{
	OTString strID;
	GetIdentifier(strID);
	
	const char * pszFolder = NULL;
	const char * pszType = GetTypeString();
	
	switch (theType) 
	{
		case OTLedger::inbox:
			pszFolder = OTLog::InboxFolder();
			break;
		case OTLedger::outbox:
			pszFolder = OTLog::OutboxFolder();
			break;
		case OTLedger::nymbox:
			pszFolder = OTLog::NymboxFolder();
			break;
		default:
			return false;
	}
	// -------------------------------------
	
	m_strFoldername = pszFolder;
	m_strFilename = strID.Get();
	
	OT_ASSERT(m_strFoldername.GetLength() > 2);
	OT_ASSERT(m_strFilename.GetLength() > 2);
	
	if (false == SaveContract(pszFolder, strID.Get()))
	{
		OTLog::vError("Error saving %s in OTLedger::Save%s: %s%s%s\n", 
					  pszType, pszType, m_strFoldername.Get(), OTLog::PathSeparator(), m_strFilename.Get());
		return false;
	}
	else 
	{
		OTLog::vOutput(2, "Successfully saved %s: %s%s%s\n", pszType, 
					   m_strFoldername.Get(), OTLog::PathSeparator(), m_strFilename.Get());
	}
	
	return true;
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


OTLedger * OTLedger::GenerateLedger(const OTIdentifier & theUserID, const OTIdentifier & theAcctID, // AcctID should be "OwnerID" since could be acct OR Nym (with nymbox)
									const OTIdentifier & theServerID, 
									const ledgerType theType, bool bCreateFile/*=false*/)
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
	OTString strID(theAcctID);
	
	switch (theType) {
		case OTLedger::nymbox:
			m_strFoldername = OTLog::NymboxFolder();
			m_strFilename = strID.Get();
			break;
		case OTLedger::inbox:
			m_strFoldername = OTLog::InboxFolder();
			m_strFilename = strID.Get();
			
//			
//		{ // TEMP REMOVE TODO
//			OTString strTempBlah(theAcctID);
//			OTLog::vError("OTLedger::GenerateLedger: DEBUGGING: GENERATING Inbox ledger for account: %s \n ",
//						  strTempBlah.Get());			
//		}
//			
//			
			
			break;
		case OTLedger::outbox:
			m_strFoldername = OTLog::OutboxFolder();
			m_strFilename = strID.Get();
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
		const char * szFoldername = m_strFoldername.Get();
		const char * szFilename = m_strFilename.Get();
		
		if (OTDB::Exists(szFoldername, szFilename))
		{
			OTLog::vOutput(0, "ERROR: trying to generate ledger that already exists: %s%s%s\n", 
						   szFoldername, OTLog::PathSeparator(), szFilename);
			return false;
		}
		
		// --------------------------------------------------------------------
	
		// Okay, it doesn't already exist. Let's generate it.
		OTLog::vOutput(0, "Generating %s%s%s\n", 
					   szFoldername, OTLog::PathSeparator(), szFilename);
	}
	
	if (OTLedger::nymbox != theType)
	{
		// Have to look up the UserID here. No way around it.
		// Plus it helps verify things.
		OTAccount * pAccount = OTAccount::LoadExistingAccount(theAcctID, theServerID);
		OTCleanup<OTAccount> theAccountGuardian(pAccount); // No worries about having to clean it up.
		
		if (pAccount)
			SetUserID(pAccount->GetUserID());
	}
	else 
	{
		SetUserID(theAcctID); // In the case of nymbox, the acct ID IS the user ID. (Should change it to "owner ID" to make it sound right either way.)
	}


	// Notice I still don't actually create the file here.  The programmer still has to call 
	// "SaveInbox" or "SaveOutbox" to actually save the file. But he cannot do that unless he
	// generates it first here, and the "bCreateFile" parameter insures that he isn't overwriting
	// one that is already there (even if we don't actually save the file in this function.)
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
}


// ID refers to account ID.
// Since a ledger is normally used as an inbox for a specific account, in a specific file,
// then I've decided to restrict ledgers to a single account.
OTLedger::OTLedger(const OTIdentifier & theUserID, const OTIdentifier & theAccountID, const OTIdentifier & theServerID)
: OTTransactionType(theUserID, theAccountID, theServerID), m_Type(OTLedger::message)
{
	InitLedger();
}

// ONLY call this if you need to load a ledger where you don't already know the person's UserID
// For example, if you need to load someone ELSE's inbox in order to send them a transfer, then
// you only know their account number, not their user ID. So you call this function to get it
// loaded up, and the UserID will hopefully be loaded up with the rest of it.
OTLedger::OTLedger(const OTIdentifier & theAccountID, const OTIdentifier & theServerID)
: OTTransactionType(), m_Type(OTLedger::message)
{
	InitLedger();
	
	SetRealAccountID(theAccountID);
	SetRealServerID(theServerID);
}

// This is private now and hopefully will stay that way.
OTLedger::OTLedger() : OTTransactionType(), m_Type(OTLedger::message)
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
        // self note: I added the const_cast because the function needs to loop through it, even though it doesn't really change it
        // (doesn't violate the const, just needs to perform a loop and the const screws with the loop.)
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



// SignContract will call this function at the right time.
void OTLedger::UpdateContents() // Before transmission or serialization, this is where the ledger saves its contents 
{
	// Notice I use the PURPORTED Account ID and Server ID to create the output. That's because
	// I don't want to inadvertantly substitute the real ID for a bad one and then sign it.
	// So if there's a bad one in there when I read it, THAT's the one that I write as well!
	OTString	strType(GetTypeString()), 
				strLedgerAcctID(GetPurportedAccountID()), 
				strLedgerAcctServerID(GetPurportedServerID()),
				strUserID(GetUserID());
	
	
	// I release this because I'm about to repopulate it.
	m_xmlUnsigned.Release();
	
	//	m_xmlUnsigned.Concatenate("<?xml version=\"%s\"?>\n\n", "1.0");		
	
	m_xmlUnsigned.Concatenate("<accountLedger version=\"%s\"\n type=\"%s\"\n accountID=\"%s\"\n userID=\"%s\"\n"
							  "serverID=\"%s\" >\n\n", m_strVersion.Get(), strType.Get(), 
							  strLedgerAcctID.Get(), strUserID.Get(), strLedgerAcctServerID.Get());		
	
	// loop through the transactions and print them out here.
	FOR_EACH(mapOfTransactions, m_mapTransactions)
	{
		OTTransaction * pTransaction = (*it).second;
		OT_ASSERT(NULL != pTransaction);
		
		OTString strTransaction;
		pTransaction->SaveContract(strTransaction);
		
		OTASCIIArmor ascTransaction;
		ascTransaction.SetString(strTransaction, true); // linebreaks = true
		
		m_xmlUnsigned.Concatenate("<transaction>\n%s</transaction>\n\n", ascTransaction.Get());
	}
	
	m_xmlUnsigned.Concatenate("</accountLedger>\n");				
}


// LoadContract will call this function at the right time.
// return -1 if error, 0 if nothing, and 1 if the node was processed.
int OTLedger::ProcessXMLNode(irr::io::IrrXMLReader*& xml)
{	
	OTString strKeyName;
	OTString strKeyValue;
	
	OTString strTransaction;
	OTASCIIArmor ascTransaction;
	
	if (!strcmp("accountLedger", xml->getNodeName()))
	{	
		OTString strType, strLedgerAcctID, strLedgerAcctServerID, strUserID;
		
		strType = xml->getAttributeValue("type");
		
		if (strType.Compare("message"))
			m_Type = OTLedger::message;
		else if (strType.Compare("inbox"))
			m_Type = OTLedger::inbox;
		else if (strType.Compare("outbox"))
			m_Type = OTLedger::outbox;
		else if (strType.Compare("nymbox"))
			m_Type = OTLedger::nymbox;
		else
			m_Type = OTLedger::error_state;
	
		m_strVersion			= xml->getAttributeValue("version");	
		strLedgerAcctID			= xml->getAttributeValue("accountID"); 
		strLedgerAcctServerID	= xml->getAttributeValue("serverID");
		strUserID				= xml->getAttributeValue("userID");
		
		OTIdentifier ACCOUNT_ID(strLedgerAcctID), SERVER_ID(strLedgerAcctServerID), USER_ID(strUserID);
		
		SetPurportedAccountID(ACCOUNT_ID);
		SetPurportedServerID(SERVER_ID);
		SetUserID(USER_ID);
		
		OTLog::vOutput(2, "Loaded account ledger of type \"%s\", version: %s\n",
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
		else {
			return -1;
		}

	}
	else if (!strcmp("transaction", xml->getNodeName()))
	{
		// go to the next node and read the text.
		xml->read();
		
		if (EXN_TEXT == xml->getNodeType())
		{
			// the ledger contains a series of transactions.
			// Each transaction is initially stored as an OTASCIIArmor string.
			ascTransaction.Set(xml->getNodeData());		// Put the ascii-armored node data into the ascii-armor object
			ascTransaction.GetString(strTransaction);	// Decode that into strTransaction, so we can load the transaction object from that string.
			OTTransaction * pTransaction = new OTTransaction(GetUserID(), GetPurportedAccountID(), GetPurportedServerID());
			
			// If we're able to successfully base64-decode the string and load it up as
			// a transaction, then let's add it to the ledger's list of transactions
			if (pTransaction && pTransaction->LoadContractFromString(strTransaction)
				&& pTransaction->VerifyContractID())
				// I responsible here to call pTransaction->VerifyContract() since
				// I am loading it here and adding it to the ledger. (So I do.)
			{
				m_mapTransactions[pTransaction->GetTransactionNum()] = pTransaction;
//				OTLog::Output(5, "Loaded transaction and adding to m_mapTransactions in OTLedger\n");
			}
			else {
				OTLog::Error("ERROR: loading transaction in OTLedger::ProcessXMLNode\n");
				if (pTransaction)
				{
					delete pTransaction;
					pTransaction = NULL;
				}
				return (-1);
			}

		}
		else {
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


































