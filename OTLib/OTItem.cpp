/************************************************************************************
 *    
 *  OTItem.cpp
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
 *    
 *     ----------------------------------------------------------------
 *
 *    Open Transactions links to these libraries:
 *    
 *       OpenSSL        --- (Version 0.9.8l at time of writing.) 
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

#include "OTTransactionType.h"
#include "OTTransaction.h"
#include "OTItem.h"




void OTItem::GetAttachment(OTString & theStr) const
{
	m_ascAttachment.GetString(theStr);
}

void OTItem::SetAttachment(const OTString & theStr)
{
	m_ascAttachment.SetString(theStr);
}



#define MINIMUM_CLEARTEXT_SIZE_OTASCIIARMOR	100

#define OTASSCIIARMOR_PADDING_TEXT  " IGNORE -- NOTE PADDING -- IGNORE -- NOTE PADDING \nIGNORE -- NOTE PADDING -- IGNORE -- NOTE PADDING \n"

void OTItem::SetNote(const OTString & theStr)
{
	OTString theString(theStr);
	if (theStr.GetLength() < MINIMUM_CLEARTEXT_SIZE_OTASCIIARMOR)
	{
		OTString strPadding(OTASSCIIARMOR_PADDING_TEXT);
		
		theString.Concatenate(strPadding);
	}
	
	m_ascNote.SetString(theString);
}

void OTItem::GetNote(OTString & theStr) const
{
	m_ascNote.GetString(theStr);
	
	if (theStr.Contains(OTASSCIIARMOR_PADDING_TEXT))
		theStr.Truncate(theStr.GetLength() - MINIMUM_CLEARTEXT_SIZE_OTASCIIARMOR);
}
		



// this one is private (I hope to keep it that way.)
// probvably not actually. If I end up back here, it's because
// sometimes I dont' WANT to assign the stuff, but leave it blank
// because I'm about to load it.
OTItem::OTItem() : OTTransactionType()
{
	InitItem();
}


// Let's say you have created a transaction, and you are creating an item to put into it.
// Well in that case, you don't care to verify that the real IDs match the purported IDs, since
// you are creating this item yourself, not verifying it from someone else.
// Use this function to create the new Item before you add it to your new Transaction.
OTItem * OTItem::CreateItemFromTransaction(const OTTransaction & theOwner, OTItem::itemType theType, OTIdentifier * pDestinationAcctID/*=NULL*/)
{
	OTItem * pItem = new OTItem(theOwner.GetUserID(), theOwner, theType, pDestinationAcctID);
	
	if (pItem)
	{
		pItem->SetPurportedAccountID(theOwner.GetPurportedAccountID());
		pItem->SetPurportedServerID(theOwner.GetPurportedServerID());
		return pItem;
	}
	return NULL;
}


// Sometimes I don't know user ID of the originator, or the account ID of the originator,
// until after I have loaded the item. It's simply impossible to set those values ahead
// of time, sometimes. In those cases, we set the values appropriately but then we need
// to verify that the user ID is actually the owner of the AccountID. TOdo that.
OTItem * OTItem::CreateItemFromString(const OTString & strItem, const OTIdentifier & theServerID, long lTransactionNumber)
{
	OTItem * pItem = new OTItem();

	// So when it loads its own server ID, we can compare to this one.
	pItem->SetRealServerID(theServerID);
	
	// This loads up the purported account ID and the user ID.
	if (pItem->LoadContractFromString(strItem))
	{
		const OTIdentifier & ACCOUNT_ID = pItem->GetPurportedAccountID();
		pItem->SetRealAccountID(ACCOUNT_ID);// I do this because it's all we've got in this case. It's what's in the
											// xml, so it must be right. If it's a lie, the signature will fail or the
											// user will not show as the owner of that account. But remember, the server
											// sent the message in the first place.
	
		pItem->SetTransactionNum(lTransactionNumber);
		
		if (pItem->VerifyContractID()) // this compares purported and real account IDs, as well as server IDs.
		{
			return pItem;
		}
		else {
			delete pItem;
			pItem = NULL;
		}
	}

	return NULL;
}




void OTItem::InitItem()
{
	
	m_lAmount			= 0; // Accounts default to ZERO.  They can only change that amount by receiving from another account.
	m_Status			= OTItem::request;					// (Unless an issuer account, which can create currency of that type.)
	m_Type				= OTItem::error_state;
	m_strContractType	= "TRANSACTION ITEM"; // CONTRACT, MESSAGE, TRANSACTION, LEDGER, TRANSACTION ITEM 
}


// From owner we can get acct ID, server ID, and transaction Num
OTItem::OTItem(const OTIdentifier & theUserID, const OTTransaction & theOwner) 
		: OTTransactionType(theUserID, theOwner.GetRealAccountID(), theOwner.GetRealServerID(), theOwner.GetTransactionNum())
{
	InitItem();

}

OTItem::OTItem(const OTIdentifier & theUserID, const OTTransaction & theOwner, OTItem::itemType theType, OTIdentifier * pDestinationAcctID/*=NULL*/)
		: OTTransactionType(theUserID, theOwner.GetRealAccountID(), theOwner.GetRealServerID(), theOwner.GetTransactionNum())
{
	InitItem();
	
	m_Type	= theType;  // This has to be below the InitItem() call that appears just above
	
	// Most transactions items don't HAVE a "to" account, just a primary account.
	// (If you deposit, or withdraw, you don't need a "to" account.)
	// But for the ones that do, you can pass the "to" account's ID in 
	// as a pointer, and we'll set that too....
	if (NULL != pDestinationAcctID)
	{
		m_AcctToID = *pDestinationAcctID;
	}	
}


/*
OTItem& OTItem::operator=(const OTItem& rhs)
{
	m_Type				= rhs.m_Type;	
	m_Status			= rhs.m_Status;
	m_lAmount			= rhs.m_lAmount;
	m_lTransactionNum	= rhs.m_lTransactionNum;
	m_strNote			= rhs.m_strNote;
	m_AcctFromID		= rhs.m_AcctFromID;		
	m_AcctToID			= rhs.m_AcctToID;
	m_AcctServerID		= rhs.m_AcctServerID;		
	m_OutboxHash		= rhs.m_OutboxHash;		
	m_ascInReferenceTo	= rhs.m_ascInReferenceTo;
	m_lInReferenceToTrans = rhs.m_lInReferenceToTrans;
	
	// Until there is a contract::op=, we'll just do it by hand here.
	// (these are the members of OTContract)
	m_strName			= rhs.m_strName;    
	m_strFilename		= rhs.m_strFilename;
	m_ID				= rhs.m_ID;	 
	m_xmlUnsigned		= rhs.m_xmlUnsigned; 
	m_strRawFile		= rhs.m_strRawFile; 
	m_strSigHashType	= rhs.m_strSigHashType;
	m_strContractType	= rhs.m_strContractType;
	m_strVersion		= rhs.m_strVersion;

	return *this;
}
*/
OTItem::~OTItem()
{
	
}


// return -1 if error, 0 if nothing, and 1 if the node was processed.
int OTItem::ProcessXMLNode(irr::io::IrrXMLReader*& xml)
{
	if (!strcmp("item", xml->getNodeName()))
	{	
		OTString strType, strStatus;
		
		strType		= xml->getAttributeValue("type");
		strStatus	= xml->getAttributeValue("status");
		
		// Type
		if (strType.Compare("transaction"))
			m_Type = OTItem::transaction;
		else if (strType.Compare("atTransaction"))
			m_Type = OTItem::atTransaction;
		else if (strType.Compare("transfer"))
			m_Type = OTItem::transfer;
		else if (strType.Compare("atTransfer"))
			m_Type = OTItem::atTransfer;
		else if (strType.Compare("accept"))
			m_Type = OTItem::accept;
		else if (strType.Compare("atAccept"))
			m_Type = OTItem::atAccept;
		else if (strType.Compare("reject"))
			m_Type = OTItem::reject;
		else if (strType.Compare("atReject"))
			m_Type = OTItem::atReject;
		else if (strType.Compare("serverfee"))
			m_Type = OTItem::serverfee;
		else if (strType.Compare("atServerfee"))
			m_Type = OTItem::atServerfee;
		else if (strType.Compare("issuerfee"))
			m_Type = OTItem::issuerfee;
		else if (strType.Compare("atIssuerfee"))
			m_Type = OTItem::atIssuerfee;
		else if (strType.Compare("balance"))
			m_Type = OTItem::balance;
		else if (strType.Compare("atBalance"))
			m_Type = OTItem::atBalance;
		else if (strType.Compare("outboxhash"))
			m_Type = OTItem::outboxhash;
		else if (strType.Compare("atOutboxhash"))
			m_Type = OTItem::atOutboxhash;
		else if (strType.Compare("withdrawal"))
			m_Type = OTItem::withdrawal;
		else if (strType.Compare("atWithdrawal"))
			m_Type = OTItem::atWithdrawal;
		else if (strType.Compare("deposit"))
			m_Type = OTItem::deposit;
		else if (strType.Compare("atDeposit"))
			m_Type = OTItem::atDeposit;
		else
			m_Type = OTItem::error_state;
		 
		// Status
		if (strStatus.Compare("request"))
			m_Status = OTItem::request;
		else if (strStatus.Compare("acknowledgement"))
			m_Status = OTItem::acknowledgement;
		else if (strStatus.Compare("rejection"))
			m_Status = OTItem::rejection;
		else
			m_Status = OTItem::error_status;
		
		OTString strAcctFromID, strAcctToID, strServerID, strUserID;
		
		strAcctFromID		= xml->getAttributeValue("fromAccountID"); 
		strAcctToID			= xml->getAttributeValue("toAccountID"); 
		strServerID			= xml->getAttributeValue("serverID");
		strUserID			= xml->getAttributeValue("userID");
		
		OTIdentifier ACCOUNT_ID(strAcctFromID), SERVER_ID(strServerID), DESTINATION_ACCOUNT(strAcctToID),
			USER_ID(strUserID);
		
		SetPurportedAccountID(ACCOUNT_ID);		// OTTransactionType::m_AcctID  the PURPORTED Account ID
		SetPurportedServerID(SERVER_ID);		// OTTransactionType::m_AcctServerID the PURPORTED Server ID
		SetDestinationAcctID(DESTINATION_ACCOUNT);
		SetUserID(USER_ID);
		SetTransactionNum(atol(xml->getAttributeValue("transactionNum")));
		SetReferenceToNum(atol(xml->getAttributeValue("inReferenceTo")));
		
		m_lAmount	= atol(xml->getAttributeValue("amount"));
		
		fprintf(stderr, "Loaded transaction Item, transaction num %ld, In Reference To: %ld, type: %s, status: %s\n",
//				"fromAccountID:\n%s\n UserID:\n%s\n toAccountID:\n%s\n serverID:\n%s\n----------\n", 
				GetTransactionNum(),
				GetReferenceToNum(), strType.Get(), strStatus.Get()
//				strAcctFromID.Get(), strUserID.Get(), strAcctToID.Get(), strServerID.Get()
				);
		
		return 1;
	}
	else if (!strcmp("note", xml->getNodeName()))
	{
		// go to the next node and read the text.
		xml->read();
		
		if (EXN_TEXT == xml->getNodeType())
		{
			m_ascNote.Set(xml->getNodeData());
			return 1;
		}
		else {
			fprintf(stderr, "Error in OItem::ProcessXMLNode: missing text for note.\n");
			return (-1); // error condition
		}
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
			fprintf(stderr, "Error in OItem::ProcessXMLNode: missing text for inReferenceTo.\n");
			return (-1); // error condition
		}
	}	
	else if (!strcmp("attachment", xml->getNodeName()))
	{
		// go to the next node and read the text.
		xml->read();
		
		if (EXN_TEXT == xml->getNodeType())
		{
			m_ascAttachment.Set(xml->getNodeData());
			return 1;
		}
		else {
			fprintf(stderr, "Error in OItem::ProcessXMLNode: missing text for attachment.\n");
			return (-1); // error condition
		}
	}	
	return 0;	
}



void OTItem::UpdateContents() // Before transmission or serialization, this is where the ledger saves its contents 
{
	OTString strFromAcctID(GetPurportedAccountID()), strToAcctID(GetDestinationAcctID()), strServerID(GetPurportedServerID()), 
			 strType, strStatus, strUserID(GetUserID());
	
	switch (m_Type) {
		case OTItem::transaction:
			strType.Set("transaction");
			break;
		case OTItem::transfer:
			strType.Set("transfer");
			break;
		case OTItem::accept:
			strType.Set("accept");
			break;
		case OTItem::reject:
			strType.Set("reject");
			break;
		case OTItem::serverfee:
			strType.Set("serverfee");
			break;
		case OTItem::issuerfee:
			strType.Set("issuerfee");
			break;
		case OTItem::balance:
			strType.Set("balance");
			break;
		case OTItem::outboxhash:
			strType.Set("outboxhash");
			break;
		case OTItem::withdrawal:
			strType.Set("withdrawal");
			break;
		case OTItem::deposit:
			strType.Set("deposit");
			break;
		case OTItem::atTransaction:
			strType.Set("atTransaction");
			break;
		case OTItem::atTransfer:
			strType.Set("atTransfer");
			break;
		case OTItem::atAccept:
			strType.Set("atAccept");
			break;
		case OTItem::atReject:
			strType.Set("atReject");
			break;
		case OTItem::atServerfee:
			strType.Set("atServerfee");
			break;
		case OTItem::atIssuerfee:
			strType.Set("atIssuerfee");
			break;
		case OTItem::atBalance:
			strType.Set("atBalance");
			break;
		case OTItem::atOutboxhash:
			strType.Set("atOutboxhash");
			break;
		case OTItem::atWithdrawal:
			strType.Set("atWithdrawal");
			break;
		case OTItem::atDeposit:
			strType.Set("atDeposit");
			break;
		default:
			strType.Set("error-unknown");
			break;
	}
	
	switch (m_Status) {
		case OTItem::request:
			strStatus.Set("request");
			break;
		case OTItem::acknowledgement:
			strStatus.Set("acknowledgement");
			break;
		case OTItem::rejection:
			strStatus.Set("rejection");
			break;
		default:
			strStatus.Set("error-unknown");
			break;
	}
	
	// I release this because I'm about to repopulate it.
	m_xmlUnsigned.Release();
		
	m_xmlUnsigned.Concatenate("<item type=\"%s\"\n status=\"%s\"\n"
							  " transactionNum=\"%ld\"\n"
							  " serverID=\"%s\"\n"
							  " userID=\"%s\"\n"
							  " fromAccountID=\"%s\"\n"
							  " toAccountID=\"%s\"\n"
							  " inReferenceTo=\"%ld\"\n" 
							  " amount=\"%ld\" >\n\n", 
							  strType.Get(), strStatus.Get(), GetTransactionNum(), strServerID.Get(), 
							  strUserID.Get(),
							  strFromAcctID.Get(), strToAcctID.Get(), GetReferenceToNum(), m_lAmount);
		
	if (m_ascNote.GetLength())
	{
		m_xmlUnsigned.Concatenate("<note>\n%s</note>\n\n", m_ascNote.Get());
	}
	
	if (m_ascInReferenceTo.GetLength())
	{
		m_xmlUnsigned.Concatenate("<inReferenceTo>\n%s</inReferenceTo>\n\n", m_ascInReferenceTo.Get());
	}
	
	if (m_ascAttachment.GetLength())
	{
		m_xmlUnsigned.Concatenate("<attachment>\n%s</attachment>\n\n", m_ascAttachment.Get());
	}
	
	m_xmlUnsigned.Concatenate("</item>\n");					
}


bool OTItem::SaveContractWallet(FILE * fl)
{
	return true;
}





































