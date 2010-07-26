/************************************************************************************
 *    
 *  OTTransaction.cpp
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
#include <strstream>
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
#include "OTLedger.h"
#include "OTTransactionType.h"
#include "OTTransaction.h"


// all common OTTransaction stuff goes here.
// (I don't like constructor loops, prefer to use a separate function they all call.)
void OTTransaction::InitTransaction()
{
	m_Type				= OTTransaction::error_state;
	m_strContractType	= "TRANSACTION"; // CONTRACT, MESSAGE, TRANSACTION, LEDGER, TRANSACTION ITEM 
}


// private and hopefully not needed
OTTransaction::OTTransaction() : OTTransactionType()
{
	InitTransaction();
}


// Let's say you never knew their UserID, you just loaded the inbox based on AccountID.
// Now you want to add a transaction to that inbox. Just pass the inbox into the
// transaction constructor (below) and it will get the rest of the info it needs off of
// the inbox itself (which you presumably just read from a file or socket.)
OTTransaction::OTTransaction(const OTLedger & theOwner)
: OTTransactionType(theOwner.GetUserID(), theOwner.GetPurportedAccountID(), theOwner.GetPurportedServerID())
{
	InitTransaction();

}

// By calling this function, I'm saying "I know the real account ID and Server ID, and here
// they are, and feel free to compare them with whatever YOU load up, which we'll leave
// blank for now unless you generate a transaction, or load one up, 

// ==> or maybe I might need to add a constructor where another transaction or a ledger is passed in.
//      Then it can grab whatever it needs from those. I'm doing something similar in OTItem
OTTransaction::OTTransaction(const OTIdentifier & theUserID, const OTIdentifier & theAccountID, const OTIdentifier & theServerID)
: OTTransactionType(theUserID, theAccountID, theServerID)
{
	InitTransaction();
	
//	m_AcctID	= theID;		// these must be loaded or generated. NOT set in constructor, for security reasons.
//	m_ServerID	= theServerID;	
}

OTTransaction::OTTransaction(const OTIdentifier & theUserID, const OTIdentifier & theAccountID, const OTIdentifier & theServerID, long lTransactionNum)
: OTTransactionType(theUserID, theAccountID, theServerID, lTransactionNum)
{
	InitTransaction();
	
//	m_lTransactionNum = lTransactionNum;	// This is set in OTTransactionType's constructor, as are m_ID and m_ServerID
//	m_AcctID	= theID;					// these must be loaded or generated. NOT set in constructor, for security reasons.
//	m_ServerID	= theServerID;	
}



OTTransaction * OTTransaction::GenerateTransaction(const OTLedger & theOwner, transactionType theType, long lTransactionNum/*=0*/)
{
	return GenerateTransaction(theOwner.GetUserID(), theOwner.GetPurportedAccountID(), 
							   theOwner.GetPurportedServerID(), theType, lTransactionNum);
}

OTTransaction * OTTransaction::GenerateTransaction(const OTIdentifier & theUserID, 
												   const OTIdentifier & theAccountID, 
												   const OTIdentifier & theServerID, transactionType theType,
												   long lTransactionNum/*=0*/)
{
	OTTransaction * pTransaction = new OTTransaction(theUserID, theAccountID, theServerID, lTransactionNum);

	if (pTransaction)
	{
		pTransaction->m_Type = theType;
		
		// Since we're actually generating this transaction, then we can go ahead
		// and set the purported account and server IDs (we have already set the
		// real ones in the constructor). Now both sets are fill with matching data.
		// No need to security check the IDs since we are creating this transaction
		// versus loading and inspecting it.
		pTransaction->SetPurportedAccountID(theAccountID);
		pTransaction->SetPurportedServerID(theServerID);
	}
	
	return pTransaction;
}



// the constructors set the real IDs (account and server) but they do not set the
// IDs that are internal to this object, m_AcctID and m_AcctServerID. These, it is assumed,
// will match the real IDs,but they must be checked when they are loaded.
// If you wish to create a transaction object, but SET the internal members (you KNOW they are correct
// or you want to generate them here) then use this function or make one like it.
bool OTTransaction::GenerateTransaction(const OTIdentifier & theAccountID, const OTIdentifier & theServerID, long lTransactionNum)
{
	// Presumably the constructor was just called, so m_ID and m_ServerID are already set properly.
	// I might make a class factory in order to enforce this. Sounds like an appropriate situation.
	//m_ID
	//m_ServerID
	
	SetPurportedAccountID(theAccountID);
	SetPurportedServerID(theServerID);
	
	SetTransactionNum(lTransactionNum);
	
	// Make sure these match with the ones that were passed into the constructor.
	return VerifyContractID();
}






OTTransaction::~OTTransaction()
{
	ReleaseItems();
}


void OTTransaction::ReleaseItems()
{
	OTItem * pItem = NULL;
	
	while (!m_listItems.empty())
	{
		pItem = m_listItems.front();
		m_listItems.pop_front();
		delete pItem;
		pItem = NULL;
	}
}

bool OTTransaction::SaveContractWallet(FILE * fl)
{
	return true;
}


// You have to allocate the item on the heap and then pass it in as a reference. 
// OTTransaction will take care of it from there and will delete it in destructor.
void OTTransaction::AddItem(OTItem & theItem) 
{ 
	m_listItems.push_back(&theItem);  
} 


// While processing a transaction, you may wish to query it for items of a certain type.
OTItem * OTTransaction::GetItem(const OTItem::itemType theType) 
{
	// loop through the items that make up this transaction and print them out here, base64-encoded, of course.
	OTItem * pItem = NULL;

	for (listOfItems::iterator ii = m_listItems.begin(); ii != m_listItems.end(); ++ii)
	{
		if (pItem = *ii) // if pointer not null
		{
			if (theType == pItem->m_Type)
				return pItem;
		}
	}
	
	return NULL;
}


// return -1 if error, 0 if nothing, and 1 if the node was processed.
int OTTransaction::ProcessXMLNode(irr::io::IrrXMLReader*& xml)
{	
	if (!strcmp("transaction", xml->getNodeName()))
	{	
		OTString strType, strAcctID, strServerID, strUserID;

		strType = xml->getAttributeValue("type");
		
		if (strType.Compare("blank"))
			m_Type = OTTransaction::blank;
		else if (strType.Compare("pending"))
			m_Type = OTTransaction::pending;
		else if (strType.Compare("processInbox"))
			m_Type = OTTransaction::processInbox;
		else if (strType.Compare("atProcessInbox"))
			m_Type = OTTransaction::atProcessInbox;
		else if (strType.Compare("transfer"))
			m_Type = OTTransaction::transfer;
		else if (strType.Compare("atTransfer"))
			m_Type = OTTransaction::atTransfer;
		else if (strType.Compare("deposit"))
			m_Type = OTTransaction::deposit;
		else if (strType.Compare("atDeposit"))
			m_Type = OTTransaction::atDeposit;
		else if (strType.Compare("withdrawal"))
			m_Type = OTTransaction::withdrawal;
		else if (strType.Compare("atWithdrawal"))
			m_Type = OTTransaction::atWithdrawal;
		else
			m_Type = OTTransaction::error_state;
		
		strAcctID	= xml->getAttributeValue("accountID"); 
		strServerID	= xml->getAttributeValue("serverID");
		strUserID	= xml->getAttributeValue("userID");
		
		OTIdentifier ACCOUNT_ID(strAcctID), SERVER_ID(strServerID), USER_ID(strUserID);
		
		SetPurportedAccountID(ACCOUNT_ID);
		SetPurportedServerID(SERVER_ID);
		SetUserID(USER_ID);
		SetTransactionNum(atol(xml->getAttributeValue("transactionNum")));
		SetReferenceToNum(atol(xml->getAttributeValue("inReferenceTo")));
		
		fprintf(stderr, "Loaded transaction %ld, in reference to: %ld type: %s\n",
//				"accountID:\n%s\n serverID:\n%s\n----------\n", 
				GetTransactionNum(),
				GetReferenceToNum(), strType.Get()
//				strAcctID.Get(), strServerID.Get()
				);
		
		return 1;
	}
	else if (!strcmp("inReferenceTo", xml->getNodeName()))
	{
		// go to the next node and read the text.
		xml->read();
		
		if (EXN_TEXT == xml->getNodeType())
		{
			m_ascInReferenceTo.Set(xml->getNodeData());
			return 1;
		}
		else {
			fprintf(stderr, "Error in OTTransaction::ProcessXMLNode: missing text for inReferenceTo.\n");
			return (-1); // error condition
		}
	}
	else if (!strcmp("item", xml->getNodeName()))
	{
		OTString strItem;
		OTASCIIArmor ascItem;

		// go to the next node and read the text.
		xml->read();
		
		if (EXN_TEXT == xml->getNodeType())
		{
			ascItem.Set(xml->getNodeData());
			ascItem.GetString(strItem);
			OTItem * pItem = new OTItem(GetUserID(), *this);
			
			// If we're able to successfully base64-decode the string and load it up as
			// a transaction, then add it to the ledger's list of transactions
			if (pItem && pItem->LoadContractFromString(strItem) && pItem->VerifyContractID())
			{
				m_listItems.push_back(pItem);
//				fprintf(stderr, "Loaded transaction Item and adding to m_listItems in OTTransaction\n");
			}
			else {
				fprintf(stderr, "ERROR: loading transaction Item in OTTransaction::ProcessXMLNode\n");
				if (pItem)
				{
					delete pItem;
					pItem = NULL;
				}
				return (-1);
			}
			
		}
		else {
			fprintf(stderr, "Error in OTTransaction::ProcessXMLNode: transaction item without value.\n");
			return (-1); // error condition
		}
		
		return 1;
	}
	
	return 0;
}



// This is called automatically by SignContract to make sure what's being signed is the most up-to-date
// Before transmission or serialization, this is where the ledger saves its contents 
// So let's make sure this transaction has the right contents.
void OTTransaction::UpdateContents() 
{	
	OTString strType, strAcctID(GetPurportedAccountID()), strServerID(GetPurportedServerID()),
		strUserID(GetUserID());
	
	switch (m_Type) {
		case OTTransaction::blank:
			strType.Set("blank");
			break;
		case OTTransaction::pending:
			strType.Set("pending");
			break;
		case OTTransaction::processInbox:
			strType.Set("processInbox");
			break;
		case OTTransaction::atProcessInbox:
			strType.Set("atProcessInbox");
			break;
		case OTTransaction::transfer:
			strType.Set("transfer");
			break;
		case OTTransaction::atTransfer:
			strType.Set("atTransfer");
			break;
		case OTTransaction::deposit:
			strType.Set("deposit");
			break;
		case OTTransaction::atDeposit:
			strType.Set("atDeposit");
			break;
		case OTTransaction::withdrawal:
			strType.Set("withdrawal");
			break;
		case OTTransaction::atWithdrawal:
			strType.Set("atWithdrawal");
			break;
		default:
			strType.Set("error-unknown");
			break;
	}
	
	// I release this because I'm about to repopulate it.
	m_xmlUnsigned.Release();

	m_xmlUnsigned.Concatenate("<transaction type=\"%s\"\n"
			  " accountID=\"%s\"\n"
			  " userID=\"%s\"\n"
				" serverID=\"%s\"\n"
				" transactionNum=\"%ld\"\n"
				" inReferenceTo=\"%ld\" >\n\n", 
				strType.Get(), strAcctID.Get(), strUserID.Get(), strServerID.Get(), GetTransactionNum(),
							  GetReferenceToNum());
	
//	fprintf(stderr, "IN REFERENCE TO, LENGTH: %d\n", m_ascInReferenceTo.GetLength());
	
	// a transaction contains a list of items, but it is also in reference to some item, from someone else
	// We include that item here.
	if (m_ascInReferenceTo.GetLength())
		m_xmlUnsigned.Concatenate("<inReferenceTo>\n%s</inReferenceTo>\n\n", m_ascInReferenceTo.Get());

	// loop through the items that make up this transaction and print them out here, base64-encoded, of course.
	OTItem * pItem = NULL;
	
	for (listOfItems::iterator ii = m_listItems.begin(); ii != m_listItems.end(); ++ii)
	{
		if (pItem = *ii) // if pointer not null
		{
			OTString strItem;
			pItem->SaveContract(strItem);
			
			OTASCIIArmor ascItem;
			ascItem.SetString(strItem, true); // linebreaks = true
			
			m_xmlUnsigned.Concatenate("<item>\n%s</item>\n\n", ascItem.Get());
		}
	}	

	m_xmlUnsigned.Concatenate("</transaction>\n");					
}

