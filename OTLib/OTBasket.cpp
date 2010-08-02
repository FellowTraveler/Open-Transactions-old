/************************************************************************************
 *    
 *  OTBasket.cpp
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

extern "C"
{
#include <string.h>
}


#include "OTBasket.h"


// For generating a user request to exchange in/out of a basket.
// Assumes that SetTransferMultiple has already been called.
void OTBasket::AddRequestSubContract(const OTIdentifier & SUB_CONTRACT_ID, const OTIdentifier & SUB_ACCOUNT_ID)
{
	BasketItem * pItem = new BasketItem;
	
	if (pItem)
	{
		pItem->SUB_CONTRACT_ID		= SUB_CONTRACT_ID;
		pItem->SUB_ACCOUNT_ID		= SUB_ACCOUNT_ID;
		
		// Minimum transfer amount is not set on a request. The server already knows its value.
		// Also there is no multiple on the item, only on the basket as a whole.
		// ALL items are multiplied by the same multiple. Even the basket amount itself is also.
		
		m_dequeItems.push_back(pItem);
	}
	else {
		fprintf(stderr, "Error allocating memory in OTBasket::AddRequestSubContract\n");
	}
}


// For generating a real basket
void OTBasket::AddSubContract(const OTIdentifier & SUB_CONTRACT_ID, long lMinimumTransferAmount)
{
	BasketItem * pItem = new BasketItem;
	
	if (pItem)
	{
		pItem->SUB_CONTRACT_ID			= SUB_CONTRACT_ID;
		
		// server adds this later. Client can't know it in advance.
//		pItem->SUB_ACCOUNT_ID			= SUB_ACCOUNT_ID; 

		pItem->lMinimumTransferAmount	= lMinimumTransferAmount;

		m_dequeItems.push_back(pItem);
	}
	else {
		fprintf(stderr, "Error allocating memory in OTBasket::AddSubContract\n");
	}
}

BasketItem * OTBasket::At(int nIndex)
{
	if (nIndex < Count() && nIndex >= 0)
		return m_dequeItems.at(nIndex);
	
	return NULL;
}

int OTBasket::Count() const
{
	return m_dequeItems.size();
}


/* 
 struct BasketItem 
 {
 OTIdentifier SUB_CONTRACT_ID;
 OTIdentifier SUB_ACCOUNT_ID;
 long		lMinimumTransferAmount;
 
 BasketItem() { lMinimumTransferAmount = 0; }
 ~BasketItem();
 };

 */


// return -1 if error, 0 if nothing, and 1 if the node was processed.
int OTBasket::ProcessXMLNode(irr::io::IrrXMLReader*& xml)
{	
	if (!strcmp("currencyBasket", xml->getNodeName()))
	{		
		OTString strSubCount, strMinTrans;
		strSubCount			= xml->getAttributeValue("contractCount");
		strMinTrans			= xml->getAttributeValue("minimumTransfer"); 
		
		m_nSubCount			= atoi(strSubCount.Get());
		m_lMinimumTransfer	= atol(strMinTrans.Get()); 
		
		fprintf(stderr, "Loading currency basket...\n");
		
		return 1;
	}
	else if (!strcmp("transferMultiple", xml->getNodeName()))
	{		
		OTString strTransferMultiple, strRequestAccountID;
		
		strTransferMultiple	= xml->getAttributeValue("value");
		strRequestAccountID	= xml->getAttributeValue("transferAccountID");
		
		m_nTransferMultiple	= atoi(strTransferMultiple.Get());
		m_RequestAccountID.SetString(strRequestAccountID);
		
		fprintf(stderr, "Transfer multiple is %d. Target account is:\n%s\n", 
				m_nTransferMultiple, strRequestAccountID.Get());
		
		return 1;
	}
	else if (!strcmp("basketItem", xml->getNodeName()))
	{
		BasketItem * pItem = new BasketItem;
		
		if (pItem)
		{
			OTString strMinTrans = xml->getAttributeValue("minimumTransfer");
			pItem->lMinimumTransferAmount	= atol(	strMinTrans.Get()	);
			
			OTString	strSubAccountID(xml->getAttributeValue("accountID")),
						strContractID(xml->getAttributeValue("assetID"));
			pItem->SUB_ACCOUNT_ID.SetString(strSubAccountID); 
			pItem->SUB_CONTRACT_ID.SetString(strContractID);
			
			m_dequeItems.push_back(pItem);
			
			return 1;
		}
		else {
			fprintf(stderr, "Error allocating memory in OTBasket::ProcessXMLNode\n");
		}

		fprintf(stderr, "Loaded basket item.\n");
		
		return 1;
	}
	
	return 0;	
}

void OTBasket::UpdateContents() // Before transmission or serialization, this is where the basket updates its contents 
{		
	// I release this because I'm about to repopulate it.
	m_xmlUnsigned.Release();
	
	m_xmlUnsigned.Concatenate("<currencyBasket contractCount=\"%d\"\n" 
							  " minimumTransfer=\"%ld\" >\n\n", 
							  m_nSubCount, m_lMinimumTransfer);
	
	if (m_nTransferMultiple)
	{
		OTString strRequestAcctID(m_RequestAccountID);
		m_xmlUnsigned.Concatenate("<transferMultiple value=\"%d\"\n transferAccountID=\"%s\" />\n\n", 
								  m_nTransferMultiple, strRequestAcctID.Get());
	}
	
	for (int i = 0; i < Count(); i++)
	{
		BasketItem * pItem = m_dequeItems[i];
		
		if (pItem)
		{
			OTString strAcctID(pItem->SUB_ACCOUNT_ID), strContractID(pItem->SUB_CONTRACT_ID);
			
			m_xmlUnsigned.Concatenate("<basketItem minimumTransfer=\"%ld\"\n"
									" accountID=\"%s\"\n"
									" assetID=\"%s\" />\n\n", 
									pItem->lMinimumTransferAmount,
									m_bHideAccountID ? "" : strAcctID.Get(),
									strContractID.Get());
		}
		else {
			fprintf(stderr, "Error allocating memory in OTBasket::UpdateContents\n");
		}
	}
	
	m_xmlUnsigned.Concatenate("</currencyBasket>\n");					
}

// Most contracts calculate their ID by hashing the Raw File (signatures and all).
// The Basket only hashes the unsigned contents, and only with the account IDs removed.
// This way, the basket will produce a consistent ID across multiple different servers.
void OTBasket::CalculateContractID(OTIdentifier & newID)
{	
	m_bHideAccountID	= true;

	// Produce a version of the file without account IDs (which are different from server to server.)
	UpdateContents();
	
	newID.CalculateDigest(m_xmlUnsigned);

	// Put it back the way it was.
	m_bHideAccountID	= false;
	UpdateContents();
}


OTBasket::OTBasket(int nCount, long lMinimumTransferAmount) :  OTContract()
{
	InitBasket();
	
	m_nSubCount			= nCount;
	m_lMinimumTransfer	= lMinimumTransferAmount;
}

OTBasket::OTBasket() :  OTContract()
{
	InitBasket();
}

OTBasket::~OTBasket()
{
	ReleaseBasket();
}
	
void OTBasket::InitBasket()
{
	m_nSubCount			= 0;
	m_lMinimumTransfer	= 0;
	m_nTransferMultiple	= 0;
	m_bHideAccountID	= false;
}

void OTBasket::ReleaseBasket()
{
	BasketItem * pItem = NULL;
	
	m_RequestAccountID.Release();
	
	while (!m_dequeItems.empty()) 
	{
		pItem = m_dequeItems.front();
		m_dequeItems.pop_front();
		delete pItem;
	}

	m_nSubCount			= 0;
	m_lMinimumTransfer	= 0;
	m_nTransferMultiple	= 0;
	m_bHideAccountID	= false;
}

	
bool OTBasket::SaveContractWallet(FILE * fl)
{
	
}


