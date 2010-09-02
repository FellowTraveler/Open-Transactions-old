/************************************************************************************
 *    
 *  OTCheque.cpp
 *  
 *              Open Transactions:  Library, Protocol, Server, and Test Client
 *    
 *                      -- Anonymous Numbered Accounts
 *                      -- Untraceable Digital Cash
 *                      -- Triple-Signed Receipts
 *                      -- Basket Currencies
 *                      -- Signed XML Contracts
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
 *        If you would like to use this software outside of the free software
 *        license, please contact FellowTraveler. (Unfortunately many will run
 *        anonymously and untraceably, so who could really stop them?)
 *   
 *        This library is also "dual-license", meaning that Ben Laurie's license
 *        must also be included and respected, since the code for Lucre is also
 *        included with Open Transactions.
 *        The Laurie requirements are light, but if there is any problem with his
 *        license, simply remove the deposit/withdraw commands. Although there are 
 *        no other blind token algorithms in Open Transactions (yet), the other 
 *        functionality will continue to operate.
 *    
 *    OpenSSL WAIVER:
 *        This program is released under the AGPL with the additional exemption 
 *        that compiling, linking, and/or using OpenSSL is allowed.
 *    
 *    DISCLAIMER:
 *        This program is distributed in the hope that it will be useful,
 *        but WITHOUT ANY WARRANTY; without even the implied warranty of
 *        MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *        GNU Affero General Public License for more details.
 *      
 ************************************************************************************/


#include <cstring>


#include "irlxml/irrXML.h"

using namespace irr;
using namespace io;


#include "OTCheque.h"


void OTCheque::UpdateContents()
{
	OTString ASSET_TYPE_ID(m_AssetTypeID), SERVER_ID(m_ServerID), 
			SENDER_ACCT_ID(m_SENDER_ACCT_ID), SENDER_USER_ID(m_SENDER_USER_ID), 
			RECIPIENT_USER_ID(m_RECIPIENT_USER_ID);
		
	long lFrom = m_VALID_FROM, lTo = m_VALID_TO;
	
	// I release this because I'm about to repopulate it.
	m_xmlUnsigned.Release();
	
	m_xmlUnsigned.Concatenate("<?xml version=\"%s\"?>\n\n", "1.0");		
	
	m_xmlUnsigned.Concatenate("<cheque\n version=\"%s\"\n"
							  " amount=\"%ld\"\n"
							  " assetTypeID=\"%s\"\n"
							  " transactionNum=\"%ld\"\n"
							  " serverID=\"%s\"\n"
							  " senderAcctID=\"%s\"\n"
							  " senderUserID=\"%s\"\n"
							  " hasRecipient=\"%s\"\n"
							  " recipientUserID=\"%s\"\n"
							  " validFrom=\"%ld\"\n"
							  " validTo=\"%ld\""							  
							  " >\n\n", 
							  m_strVersion.Get(),
							  m_lAmount,
							  ASSET_TYPE_ID.Get(), 
							  m_lTransactionNum,
							  SERVER_ID.Get(),
							  SENDER_ACCT_ID.Get(),
							  SENDER_USER_ID.Get(),
							  (m_bHasRecipient ? "true" : "false"),
							  RECIPIENT_USER_ID.Get(),
							  lFrom, lTo );		
	
	if (m_strMemo.Exists())
	{
		OTASCIIArmor ascMemo(m_strMemo);		
		m_xmlUnsigned.Concatenate("<memo>\n%s</memo>\n\n", ascMemo.Get());
	}
	
	m_xmlUnsigned.Concatenate("</cheque>\n");			
}





/*
 
 m_strMemo;
 
 */

// return -1 if error, 0 if nothing, and 1 if the node was processed.
int OTCheque::ProcessXMLNode(IrrXMLReader*& xml)
{	
	int nReturnVal = 0;
	
	// Here we call the parent class first.
	// If the node is found there, or there is some error,
	// then we just return either way.  But if it comes back
	// as '0', then nothing happened, and we'll continue executing.
	//
	// -- Note you can choose not to call the parent if
	// you don't want to use any of those xml tags.
	// As I do below, in the case of OTAccount.
	//if (nReturnVal = OTContract::ProcessXMLNode(xml))
	//	return nReturnVal;
	
	if (!strcmp("cheque", xml->getNodeName())) 
	{
		OTString strHasRecipient;
		strHasRecipient		= xml->getAttributeValue("hasRecipient");
		if (strHasRecipient.Compare("true"))
			m_bHasRecipient = true;
		else
			m_bHasRecipient = false;

		m_strVersion		= xml->getAttributeValue("version");					
		m_lAmount			= atol(xml->getAttributeValue("amount"));
		m_lTransactionNum	= atol(xml->getAttributeValue("transactionNum"));

		m_VALID_FROM	= atol(xml->getAttributeValue("validFrom"));
		m_VALID_TO		= atol(xml->getAttributeValue("validTo"));
		
		OTString	strAssetTypeID(xml->getAttributeValue("assetTypeID")),
					strServerID(xml->getAttributeValue("serverID")),
					strSenderAcctID(xml->getAttributeValue("senderAcctID")),
					strSenderUserID(xml->getAttributeValue("senderUserID")),
					strRecipientUserID(xml->getAttributeValue("recipientUserID"));
							
		m_AssetTypeID.SetString(strAssetTypeID);
		m_ServerID.SetString(strServerID);
		m_SENDER_ACCT_ID.SetString(strSenderAcctID);	
		m_SENDER_USER_ID.SetString(strSenderUserID);	

		// Recipient ID --------
		if (m_bHasRecipient)
		{
			m_RECIPIENT_USER_ID.SetString(strRecipientUserID);	
		}
		else {
			m_RECIPIENT_USER_ID.Release();
		}

		// ---------------------
		
		fprintf(stderr, 
				//	"\n===> Loading XML for token into memory structures..."
				"\n\nCheque Amount: %ld.  Transaction Number: %ld\n Valid From: %ld\n Valid To: %ld\n"
				" AssetTypeID: %s\n ServerID: %s\n"
				" senderAcctID: %s\n senderUserID: %s\n "
				" Has Recipient? %s. If yes, UserID of Recipient:\n%s\n", 
				m_lAmount, m_lTransactionNum, m_VALID_FROM, m_VALID_TO,
				strAssetTypeID.Get(), strServerID.Get(),
				strSenderAcctID.Get(), strSenderUserID.Get(), 
				(m_bHasRecipient ? "Yes" : "No"),
				strRecipientUserID.Get());
		
		nReturnVal = 1;
	}
	
	else if (!strcmp("memo", xml->getNodeName())) 
	{
		// go to the next node and read the text.
		xml->read();
		
		if (EXN_TEXT == xml->getNodeType())
		{
			OTString strNodeData = xml->getNodeData();
						
			// Sometimes the XML reads up the data with a prepended newline.
			// This screws up my own objects which expect a consistent in/out
			// So I'm checking here for that prepended newline, and removing it.
			char cNewline;
			if (strNodeData.At(0, cNewline))
			{
				OTASCIIArmor ascNodeData;
				
				if ('\n' == cNewline)
				{
					ascNodeData.Set(strNodeData.Get() + 1);
					ascNodeData.GetString(m_strMemo, true); // linebreaks = true
				}
				else
				{
					ascNodeData.Set(strNodeData.Get());
					ascNodeData.GetString(m_strMemo, true); // linebreaks = true
				}
			}
		}
		else {
			fprintf(stderr, "Error in OTCheque::ProcessXMLNode: memo field without value.\n");
			return (-1); // error condition
		}
		
		return 1;
	}

	return nReturnVal;
}



// Imagine that you are actually writing a cheque.
// That's basically what this function does.
// Make sure to sign it afterwards.
bool OTCheque::IssueCheque(const long & lAmount, const long & lTransactionNum,
				const time_t & VALID_FROM, const time_t & VALID_TO,	// The expiration date (valid from/to dates) of the cheque
				const OTIdentifier & SENDER_ACCT_ID,			// The asset account the cheque is drawn on.
				const OTIdentifier & SENDER_USER_ID,			// This ID must match the user ID on the asset account, 
														// AND must verify the cheque signature with that user's key.
				const OTString & strMemo,				// Optional memo field.
				const OTIdentifier * pRECIPIENT_USER_ID/*=NULL*/)	// Recipient optional. (Might be a blank cheque.)
{
	m_VALID_FROM			= VALID_FROM;
	m_VALID_TO				= VALID_TO;
	
	m_lAmount				= lAmount;
	m_lTransactionNum		= lTransactionNum;
	m_strMemo				= strMemo;
	
	m_SENDER_ACCT_ID		= SENDER_ACCT_ID;	
	m_SENDER_USER_ID		= SENDER_USER_ID;
	
	if (pRECIPIENT_USER_ID)
	{
		m_bHasRecipient		= true;
		m_RECIPIENT_USER_ID	= *pRECIPIENT_USER_ID;
	}

	if (m_lAmount < 0)
		m_strContractType.Set("INVOICE");
	
	return true;
}


void OTCheque::InitCheque()
{	
	m_strContractType.Set("CHEQUE");
		
	m_lAmount			= 0;
	m_lTransactionNum	= 0; 

	m_bHasRecipient		= false;
	
	m_strMemo.Release();
	m_SENDER_ACCT_ID.Release();	
	m_SENDER_USER_ID.Release();
	m_RECIPIENT_USER_ID.Release();
}

OTCheque::OTCheque() : OTInstrument()
{
	InitCheque();
}

OTCheque::OTCheque(const OTIdentifier & SERVER_ID, const OTIdentifier & ASSET_ID) : OTInstrument(SERVER_ID, ASSET_ID)
{
	InitCheque();
	
	// m_ServerID and m_AssetTypeID are now in the parent class (OTInstrument)
	// So they are initialized there now.
}


void OTCheque::Release()
{
	// If there were any dynamically allocated objects, clean them up here.

	OTInstrument::Release(); // since I've overridden the base class, I call it now...
	
	// Then I call this to re-initialize everything
	InitCheque(); 
}

OTCheque::~OTCheque()
{
	// OTContract::~OTContract is called here automatically, and it calls Release() already.
	// So I don't need to call Release() here again, since it's already called by the parent.
}


bool OTCheque::SaveContractWallet(FILE * fl)
{
	
	return true;
}

