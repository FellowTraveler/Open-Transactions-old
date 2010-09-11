/************************************************************************************
 *    
 *  OTLedger.cpp
 *  
 *		Open Transactions:  Library, Protocol, Server, and Test Client
 *    
 *    			-- Anonymous Numbered Accounts
 *    			-- Untraceable Digital Cash
 *    			-- Triple-Signed Receipts
 *    			-- Basket Currencies
 *    			-- Signed XML Contracts
 *    
 *    Copyright (C) 2010 by "Fellow Traveler" (A pseudonym)
 *    
 *    EMAIL:
 *    F3llowTraveler@gmail.com --- SEE PGP PUBLIC KEY IN CREDITS FILE.
 *    
 *    KEY FINGERPRINT:
 *    9DD5 90EB 9292 4B48 0484  7910 0308 00ED F951 BB8E
 *    
 *    WEBSITE:
 *    http://www.OpenTransactions.org
 *    
 *    OFFICIAL PROJECT WIKI:
 *    http://wiki.github.com/FellowTraveler/Open-Transactions/
 *    
 *     ----------------------------------------------------------------
 *    
 *    Open Transactions was written including these libraries:
 *    
 *       Lucre          --- Copyright (C) 1999-2009 Ben Laurie.
 *                          http://anoncvs.aldigital.co.uk/lucre/
 *       irrXML         --- Copyright (C) 2002-2005 Nikolaus Gebhardt
 *                          http://irrlicht.sourceforge.net/author.html	
 *       easyzlib       --- Copyright (C) 2008 First Objective Software, Inc.
 *                          Used with permission. http://www.firstobject.com/
 *       PGP to OpenSSL --- Copyright (c) 2010 Mounir IDRASSI 
 *                          Used with permission. http://www.idrix.fr
 *       SFSocket       --- Copyright (C) 2009 Matteo Bertozzi
 *                          Used with permission. http://th30z.netsons.org/
 *    
 *     ----------------------------------------------------------------
 *
 *    Open Transactions links to these libraries:
 *    
 *       OpenSSL        --- (Version 1.0.0a at time of writing.) 
 *                          http://openssl.org/about/
 *       zlib           --- Copyright (C) 1995-2004 Jean-loup Gailly and Mark Adler
 *    
 *     ----------------------------------------------------------------
 *
 *    LICENSE:
 *        This program is free software: you can redistribute it and/or modify
 *        it under the terms of the GNU Affero General Public License as
 *        published by the Free Software Foundation, either version 3 of the
 *        License, or (at your option) any later version.
 *    
 *        You should have received a copy of the GNU Affero General Public License
 *        along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *    	
 *    	  If you would like to use this software outside of the free software
 *    	  license, please contact FellowTraveler.
 *   
 *        This library is also "dual-license", meaning that Ben Laurie's license
 *        must also be included and respected, since the code for Lucre is also
 *        included with Open Transactions.
 *        The Laurie requirements are light, but if there is any problem with his
 *        license, simply remove the Lucre code. Although there are no other blind
 *        token algorithms in Open Transactions (yet), the other functionality will
 *        continue to operate .
 *    
 *    OpenSSL WAIVER:
 *        This program is released under the AGPL with the additional exemption 
 *    	  that compiling, linking, and/or using OpenSSL is allowed.
 *    
 *    DISCLAIMER:
 *        This program is distributed in the hope that it will be useful,
 *        but WITHOUT ANY WARRANTY; without even the implied warranty of
 *        MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *        GNU Affero General Public License for more details.
 *    	
 ************************************************************************************/



#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include <cstring>

#include "irlxml/irrXML.h"

using namespace irr;
using namespace io;


#include "OTIdentifier.h"
#include "OTAccount.h"
#include "OTPayload.h"
#include "OTMessage.h"
#include "OTStringXML.h"

#include "OTItem.h"
#include "OTTransaction.h"
#include "OTLedger.h"

#include "OTPseudonym.h"


// the below four functions (load/save in/outbox) assume that the ID is already set
// properly.
// Then it uses the ID to form the path for the file that is opened. Easy, right?

bool OTLedger::LoadInbox()
{
	OTString strID;
	GetIdentifier(strID);
	
	m_Type = OTLedger::inbox;

	m_strFilename.Format("%s%sinbox%s%s", OTPseudonym::OTPath.Get(), OTPseudonym::OTPathSeparator.Get(),
						 OTPseudonym::OTPathSeparator.Get(), strID.Get());
	
	// Try to load the ledger from disk.
	if (false == LoadContract())
	{
		fprintf(stderr, "Failure loading inbox in OTLedger::LoadInbox\n");
		return false;
	}
	
	return true;	
}

//TODO really should verify the ServerID after loading the ledger.
// Perhaps just call "VerifyContract" and we'll make sure, for ledgers
// VerifyContract is overriden and explicitly checks the serverID.
// Should also check the Type at the same time.

bool OTLedger::LoadOutbox()
{
	OTString strID;
	GetIdentifier(strID);
	
	m_Type = OTLedger::outbox;
	
	m_strFilename.Format("%s%soutbox%s%s", OTPseudonym::OTPath.Get(), OTPseudonym::OTPathSeparator.Get(),
						 OTPseudonym::OTPathSeparator.Get(), strID.Get());
	
	if (false == LoadContract())
	{
		fprintf(stderr, "Error loading outbox in OTLedger::LoadOutbox\n");
		return false;
	}
	
	return true;	
}


// If you're going to save this, make sure you sign it first.
bool OTLedger::SaveInbox()
{
	OTString strID;
	GetIdentifier(strID);
	
	m_strFilename.Format("%s%sinbox%s%s", OTPseudonym::OTPath.Get(), OTPseudonym::OTPathSeparator.Get(),
						 OTPseudonym::OTPathSeparator.Get(), strID.Get());
	
	if (false == SaveContract((const char*)m_strFilename.Get()))
	{
		fprintf(stderr, "Error saving inbox in OTLedger::SaveInbox\n");
		return false;
	}
	
	return true;
}


// If you're going to save this, make sure you sign it first.
bool OTLedger::SaveOutbox()
{
	OTString strID;
	GetIdentifier(strID);
	
	m_strFilename.Format("%s%soutbox%s%s", OTPseudonym::OTPath.Get(), OTPseudonym::OTPathSeparator.Get(),
						 OTPseudonym::OTPathSeparator.Get(), strID.Get());
	
	if (false == SaveContract((const char*)m_strFilename.Get()))
	{
		fprintf(stderr, "Error saving outbox in OTLedger::SaveOutbox\n");
		return false;
	}
	
	return true;
}


OTLedger * OTLedger::GenerateLedger(const OTIdentifier & theUserID, const OTIdentifier & theAcctID, 
									const OTIdentifier & theServerID, 
									const ledgerType theType, bool bCreateFile/*=false*/)
{
	OTLedger * pLedger = new OTLedger(theUserID, theAcctID, theServerID);
	
	if (pLedger)
	{
		pLedger->GenerateLedger(theAcctID, theServerID, theType, bCreateFile);
		pLedger->SetUserID(theUserID);

		return pLedger;
	}
	
	return NULL;
}

bool OTLedger::GenerateLedger(const OTIdentifier & theAcctID, 
							  const OTIdentifier & theServerID, const ledgerType theType,
							  bool bCreateFile/*=false*/)
{
	// First we set the "Safe" ID and try to load the file, to make sure it doesn't already exist.
	OTString strID(theAcctID);
	
	switch (theType) {
		case OTLedger::inbox:
			m_strFilename.Format("%s%sinbox%s%s", OTPseudonym::OTPath.Get(), OTPseudonym::OTPathSeparator.Get(),
								 OTPseudonym::OTPathSeparator.Get(), strID.Get());
			break;
		case OTLedger::outbox:
			m_strFilename.Format("%s%soutbox%s%s", OTPseudonym::OTPath.Get(), OTPseudonym::OTPathSeparator.Get(),
								 OTPseudonym::OTPathSeparator.Get(), strID.Get());
			break;
		case OTLedger::message:
//			fprintf(stderr, "Generating message ledger...\n");
			SetRealAccountID(theAcctID);
			SetPurportedAccountID(theAcctID);	// It's safe to set these the same here, since we're creating the ledger now.
			SetRealServerID(theServerID);
			SetPurportedServerID(theServerID);	// Always want the server ID on anything that the server signs.
			m_Type	= theType;
			return true;
		default:
			fprintf(stderr, "ERROR: GenerateLedger is only for message, inbox and outbox ledgers.\n");
			return false;
	}
	
	SetRealAccountID(theAcctID); // set this before calling LoadContract...
	SetRealServerID(theServerID);

	if (bCreateFile)
	{
		// Try to load the ledger from disk.
		bool bLoaded	= LoadContract();
		
		if (bLoaded)
		{
			fprintf(stderr, "ERROR: trying to generate inbox that already exists: %s\n", strID.Get());
			return false;
		}
	
		// Okay, it doesn't already exist. Let's generate it.
		fprintf(stderr, "Generating %s\n", m_strFilename.Get());
	}
	
	// Have to look up the UserID here. No way around it.
	// Plus it helps verify things.
	OTAccount * pAccount = OTAccount::LoadExistingAccount(theAcctID, theServerID);
	
	// Notice I still don't actually create the file here.  The programmer still has to call 
	// "SaveInbox" or "SaveOutbox" to actually save the file. But he cannot do that unless he
	// generates it first here, and the "bCreateFile" parameter insures that he isn't overwriting
	// one that is already there (even if we don't actually save the file in this function.)
	SetPurportedAccountID(theAcctID);
	SetPurportedServerID(theServerID);
	
	m_Type	= theType; // Todo make this Get/Set methods
	
	if (pAccount)
	{
		SetUserID(pAccount->GetUserID());
		
		delete pAccount;
		pAccount = NULL;
	}
	
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
: OTTransactionType(theUserID, theAccountID, theServerID)
{
	InitLedger();
}

// ONLY call this if you need to load a ledger where you don't already know the person's UserID
// For example, if you need to load someone ELSE's inbox in order to send them a transfer, then
// you only know their account number, not their user ID. So you call this function to get it
// loaded up, and the UserID will hopefully be loaded up with the rest of it.
OTLedger::OTLedger(const OTIdentifier & theAccountID, const OTIdentifier & theServerID)
: OTTransactionType()
{
	InitLedger();
	
	SetRealAccountID(theAccountID);
	SetRealServerID(theServerID);
}

// This is private now and hopefully will stay that way.
OTLedger::OTLedger() : OTTransactionType()
{
	InitLedger();
}







mapOfTransactions & OTLedger::GetTransactionMap()
{
	return m_mapTransactions;
}

bool OTLedger::RemoveTransaction(long lTransactionNum) // if false, transaction wasn't found.
{
	// loop through the transactions that make up this ledger and remove one of them.
	OTTransaction * pTransaction = NULL;
	
	for (mapOfTransactions::iterator ii = m_mapTransactions.begin(); ii != m_mapTransactions.end(); ++ii)
	{
		if ((pTransaction = (*ii).second)) // if pointer not null
		{			
			if (pTransaction->GetTransactionNum() == lTransactionNum)
			{
				m_mapTransactions.erase(ii);
				delete pTransaction;
				return true;
			}
		}
	}
	return false;
}

void OTLedger::AddTransaction(OTTransaction & theTransaction)
{
	m_mapTransactions[theTransaction.GetTransactionNum()] = &theTransaction;
}


// Look up a transaction by transaction number and see if it is in the ledger.
// If it is, return a pointer to it, otherwise return NULL.
OTTransaction * OTLedger::GetTransaction(long lTransactionNum)
{
	// loop through the items that make up this transaction and print them out here, base64-encoded, of course.
	OTTransaction * pTransaction = NULL;
	
	for (mapOfTransactions::iterator ii = m_mapTransactions.begin(); ii != m_mapTransactions.end(); ++ii)
	{
		if ((pTransaction = (*ii).second)) // if pointer not null
		{			
			if (pTransaction->GetTransactionNum() == lTransactionNum)
				return pTransaction;
		}
	}
	
	return NULL;
}


// If you TRANSFER REQUEST to me (transaction #1), then the server will create a 
// PENDING transaction in my inbox (transaction #41) and a PENDING transaction in 
// your outbox (transaction #58) which both contain a copy of transaction#1 in their
// "In Reference To" ascii-armored field.
//
// The above function would look up #41 in my inbox, or #58 in your outbox, but
// you could NOT pass #1 to that function and get a pointer back. You'd get NULL.
// But the below function specifically returns the pointer of a transaction ONLY
// IF THE "IN REFERENCE TO" Transaction ID matches the one passed in (such as #1
// in the example above.
// If it can't find anything, it will return NULL.
OTTransaction * OTLedger::GetPendingTransaction(long lTransactionNum)
{
	// loop through the items that make up this transaction and print them out here, base64-encoded, of course.
	OTTransaction * pTransaction = NULL;
	
	for (mapOfTransactions::iterator ii = m_mapTransactions.begin(); ii != m_mapTransactions.end(); ++ii)
	{
		if ((pTransaction = (*ii).second)) // if pointer not null
		{	
			if (pTransaction->GetReferenceToNum() == lTransactionNum)
				return pTransaction;
		}
	}
	
	return NULL;
}



// SignContract will call this function at the right time.
void OTLedger::UpdateContents() // Before transmission or serialization, this is where the ledger saves its contents 
{
	// Notice I use the PURPORTED Account ID and Server ID to create the output. That's because
	// I don't want to inadvertantly substitute the real ID for a bad one and then sign it.
	// So if there's a bad one in there when I read it, THAT's the one that I write as well!
	OTString strType, strLedgerAcctID(GetPurportedAccountID()), strLedgerAcctServerID(GetPurportedServerID()),
		strUserID(GetUserID());
	
	switch (m_Type) {
		case OTLedger::message:
			strType.Set("message");
			break;
		case OTLedger::inbox:
			strType.Set("inbox");
			break;
		case OTLedger::outbox:
			strType.Set("outbox");
			break;
		default:
			strType.Set("error-unknown");
			break;
	}
	
	// I release this because I'm about to repopulate it.
	m_xmlUnsigned.Release();
	
	//	m_xmlUnsigned.Concatenate("<?xml version=\"%s\"?>\n\n", "1.0");		
	
	m_xmlUnsigned.Concatenate("<accountLedger version=\"%s\"\n type=\"%s\"\n accountID=\"%s\"\n userID=\"%s\"\n"
							  "serverID=\"%s\" >\n\n", m_strVersion.Get(), strType.Get(), 
							  strLedgerAcctID.Get(), strUserID.Get(), strLedgerAcctServerID.Get());		
	
	// loop through the transactions and print them out here.
	OTTransaction * pTransaction = NULL;
	
	for (mapOfTransactions::iterator ii = m_mapTransactions.begin(); 
		 ii != m_mapTransactions.end(); ++ii)
	{
		if ((pTransaction = (*ii).second)) // if pointer not null
		{
			OTString strTransaction;
			pTransaction->SaveContract(strTransaction);
			
			OTASCIIArmor ascTransaction;
			ascTransaction.SetString(strTransaction, true); // linebreaks = true
			
			m_xmlUnsigned.Concatenate("<transaction>\n%s</transaction>\n\n", ascTransaction.Get());
		}
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
		
		fprintf(stderr, "Loaded account ledger of type \"%s\", version: %s\n",
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
//				fprintf(stderr, "Loaded transaction and adding to m_mapTransactions in OTLedger\n");
			}
			else {
				fprintf(stderr, "ERROR: loading transaction in OTLedger::ProcessXMLNode\n");
				if (pTransaction)
				{
					delete pTransaction;
					pTransaction = NULL;
				}
				return (-1);
			}

		}
		else {
			fprintf(stderr, "Error in OTLedger::ProcessXMLNode: transaction without value.\n");
			return (-1); // error condition
		}
		
		return 1;
	}
	
	return 0;
}


OTLedger::~OTLedger()
{

	while (!m_mapTransactions.empty())
	{		
		OTTransaction * pTransaction = m_mapTransactions.begin()->second;
		m_mapTransactions.erase(m_mapTransactions.begin());
		delete pTransaction;
		pTransaction = NULL;
	}
	
}

bool OTLedger::SaveContractWallet(FILE * fl)
{
	return true;
}


































