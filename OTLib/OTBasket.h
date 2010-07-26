/************************************************************************************
 *    
 *  OTBasket.h
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


#ifndef __OTBASKET_H__
#define __OTBASKET_H__

#include <deque>

#include "OTIdentifier.h"
#include "OTContract.h"



class BasketItem 
{
public:
	OTIdentifier SUB_CONTRACT_ID;
	OTIdentifier SUB_ACCOUNT_ID;
	
	long		lMinimumTransferAmount;
	
	BasketItem() { lMinimumTransferAmount = 0; }
	~BasketItem() {}
};



typedef std::deque <BasketItem *> dequeOfBasketItems;


class OTBasket : public OTContract
{
public:
						 
protected:
	
	int		m_nSubCount;
	long	m_lMinimumTransfer;			// used in the actual basket

	int		m_nTransferMultiple;		// used in a request basket
	
	OTIdentifier m_RequestAccountID;	// used in a request basket so the server knows your acct ID.
	
	dequeOfBasketItems	m_dequeItems;
	
	bool	m_bHideAccountID;	// When saving, we might wish to produce a version without Account IDs
								// So that the resulting hash will be a consistent ID across different servers.
	
	// return -1 if error, 0 if nothing, and 1 if the node was processed.
	virtual int ProcessXMLNode(irr::io::IrrXMLReader*& xml);
public:
	OTBasket();
	OTBasket(int nCount, long lMinimumTransferAmount);
	virtual ~OTBasket();
		
	virtual void UpdateContents();
	virtual bool SaveContractWallet(FILE * fl);	

	virtual void CalculateContractID(OTIdentifier & newID);
	
	inline long GetMinimumTransfer() const { return m_lMinimumTransfer; }
	
	inline int	GetTransferMultiple() const { return m_nTransferMultiple; }
	inline void SetTransferMultiple(int nTransferMultiple) { m_nTransferMultiple = nTransferMultiple; } 
	
	int Count() const;
	BasketItem * At(int nIndex);

	// For generating a real basket.  The user does this part, and the server creates Account ID later
	// (That's why you don't see the account ID being passed in to the method.)
	void AddSubContract(const OTIdentifier & SUB_CONTRACT_ID, long lMinimumTransferAmount);

	// For generating a user request to exchange in/out of a basket.
	// Assumes that SetTransferMultiple has already been called.
	void AddRequestSubContract(const OTIdentifier & SUB_CONTRACT_ID, const OTIdentifier & SUB_ACCOUNT_ID);
	
	inline void SetRequestAccountID(const OTIdentifier & theAccountID) { m_RequestAccountID = theAccountID; }
	inline const OTIdentifier & GetRequestAccountID() { return m_RequestAccountID; }

	void InitBasket();
	void ReleaseBasket();
};





#endif __OTBASKET_H__

/*
 
 I figured this one out, it's easy.
 
 Someone creates a contract that contains 10 sub-contracts. It just delegates the issuence to the sub-issuers.
 
 When he connects to the server he can upload the contract, but he has no control over it at that point, 
 since he is not one of the real issuers.
 
 The contract will only work if the sub-issuers actually have issued currencies on that transaction server.
 
 Then, the transaction server itself becomes the "issuer" of the basket currency.  It simply creates an issuer
 account, and stores a list of sub-accounts to store the delegated cuts of "real" currencies.
 
 For example, if I issue a currency that is 1 part dollar, 1 part gold, and 1 part silver, then the server
 creates an issuer account in "goldbucks" and then ANY other user can create a "goldbucks" asset account and 
 trade it like any other asset.  It doesn't even have to be a special account that the trader uses. It's just
 a normal account, but the asset type ID links to the special basket issuer account maintained by the server.
 
 Meanwhile, behind the scenes, the server's "goldbucks" issuer account is not OTAccount, but derived from it.
 suppose derived from OTAccount, that contains a list of 3 sub-accounts, 1 denominated in the dollar asset
 specified in the contract, 1 denominiated in the gold asset, and so on.
 
 The OTAssetBasket contract (with sub-issuers) and the OTBasketAccount (issuer account) objects handle all the
 details of converting between the sub-accounts and the main account.
 
 If I am trading in goldbucks, and I have 9 goldbucks in my goldbucks account, then the goldbucks issuer account 
 (controlled by the transaction server) must have at least -9 on its balance due to me. And its hidden 3 sub-accounts
 have at least +3 dollars, +3 gold, and +3 silver stored along with the rest that make up their total balances from
 all the users of that basket currency.
 
 */

