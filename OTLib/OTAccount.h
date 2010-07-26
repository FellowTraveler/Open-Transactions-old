/************************************************************************************
 *    
 *  OTAccount.h
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


#ifndef __OTACCOUNT_H__
#define __OTACCOUNT_H__

#include <list>

#include "OTTransactionType.h"
#include "OTString.h"

class OTPseudonym;
class OTAccount;
class OTMessage;

class OTAccount : public OTTransactionType {
private:

public:
	enum AccountType {
		simple,
		issuer,
		basket,
		err_acct
	};
	
protected:
	
	AccountType		m_AcctType;
	
	OTIdentifier	m_AcctAssetTypeID; // These are all the variables from the account file itself.

	OTString		m_BalanceDate;
	OTString		m_BalanceAmount;


	// return -1 if error, 0 if nothing, and 1 if the node was processed.
	virtual int ProcessXMLNode(irr::io::IrrXMLReader*& xml);

	void UpdateContents();
	OTAccount(const OTIdentifier & theUserID, const OTIdentifier & theServerID);
	OTAccount();

public:	
	OTAccount(const OTIdentifier & theUserID, const OTIdentifier & theAccountID, const OTIdentifier & theServerID, const OTString & name);
	OTAccount(const OTIdentifier & theUserID, const OTIdentifier & theAccountID, const OTIdentifier & theServerID);
	void InitAccount();
	virtual ~OTAccount();
	
	static OTAccount * GenerateNewAccount(const OTIdentifier & theUserID, const OTIdentifier & theServerID, 
										  const OTPseudonym & theServerNym, const OTMessage & theMessage,
										  const AccountType eAcctType=simple);

	bool GenerateNewAccount(const OTPseudonym & theServer, const OTMessage & theMessage, const AccountType eAcctType=simple);

	// Let's say you don't have or know the UserID, and you just want to load the damn thing up.
	// Then call this function. It will set userID and server ID for you.
	static OTAccount * LoadExistingAccount(const OTIdentifier & theAccountID, const OTIdentifier & theServerID);
	
	// gives you the asset type ID of this account. (the asset contract hash.)
	const OTIdentifier & GetAssetTypeID();
	
	bool Debit(long lAmount); // Debit a certain amount from the account (presumably the same amount is being added somewhere)
	bool Credit(long lAmount); // Credit a certain amount from the account (presumably the same amount is being subtracted somewhere)
		
	// Compares the NymID loaded from the account file with whatever Nym the programmer wants to verify.
	bool VerifyOwner(OTPseudonym & theCandidate);
	
	virtual bool LoadContract(); // overriding this so I can set the filename automatically inside based on ID.
	bool SaveAccount(); // generates filename based on accounts path and account ID. Saves to the standard location for an acct.
		
	bool SaveContractWallet(FILE * fl);
};

typedef std::list <OTAccount *>	listOfAccounts;

#endif // __OTACCOUNT_H__
