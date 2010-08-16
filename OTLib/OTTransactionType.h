/************************************************************************************
 *    
 *  OTTransactionType.h
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


#ifndef __OTTRANSACTION_TYPE_H__
#define __OTTRANSACTION_TYPE_H__

#include "OTASCIIArmor.h"
#include "OTContract.h"

class OTString;
class OTIdentifier;


// the "inbox" and "outbox" functionality is implemented in this class
//
class OTTransactionType : public OTContract 
{	
private:
	
protected:
	// keeping constructor protected in order to force people to use the other constructors and 
	// therefore provide the requisite IDs.
	OTTransactionType();

	
	// Basically what I want here is, SERVER ID and ACCOUNT ID.
	// That way, all the child classes can also have a server ID and account ID,
	// and they can compare to the internal ones to make sure they match.
	// This class centralizes that mechanism so I'm not duplicating it three or four times.
	//
	// So I need the SERVER ID and the ACCOUNT ID stored here.
	//
	// Fortunately, OTContract already handles the ID, which is the Account ID in
	// the context of all transaction objects.
	//
	// So therefore I just need to add the Server ID, and I have both.
	// Then all child classes should ALSO implement their own copy of both, and compare the
	// two whenever loading something, so that we know we're safe, as well as comparing
	// signatures.
	//
	// That's really the whole point of this software -- comparing IDs and verifying
	// signatures.
	
	OTIdentifier m_ServerID; // All child classes will have m_ID from OTContract and m_ServerID from here.
	
	// Update: instead of in the child classes, I put the "purported acct ID" and "purported server ID" here too,
	// to manage it all centrally.
									
	OTIdentifier	m_AcctID;		// THE PRIMARY ACCOUNT. Compare to m_ID.
	OTIdentifier	m_AcctServerID;	// transaction server ID for security reasons. Compare to m_ServerID.

	OTIdentifier	m_AcctUserID;		// NymID of the user who created this item. (In the future, this item
										// might be the only reference someone has. They'll want my NymID.)

	// return -1 if error, 0 if nothing, and 1 if the node was processed.
//	virtual int ProcessXMLNode(irr::io::IrrXMLReader*& xml);
	
//	void UpdateContents(); // I don't think I need this here. My parent and child classes do well enough.
	
	// I put this in protected because there are now Get/Set methods...so use them!
	long	m_lTransactionNum;	// The server issues this and it must be sent with transaction request.
	long	m_lInReferenceToTransaction;  
								// Sometimes an item is in reference to some other transaction, which does NOT need to be
								// included in the item (since the server already has it) but instead can be referenced by
								// transaction ID.

	OTASCIIArmor	m_ascInReferenceTo;	// This item may be in reference to a different item
	
public:
	
	inline const OTIdentifier & GetUserID() const { return m_AcctUserID; }
	inline void					SetUserID(const OTIdentifier & theID) {  m_AcctUserID = theID; }
	
	inline const OTIdentifier & GetRealAccountID() const { return m_ID; }
	inline void					SetRealAccountID(const OTIdentifier & theID) {  m_ID = theID; }
	
	inline const OTIdentifier & GetRealServerID() const { return m_ServerID; }
	inline void					SetRealServerID(const OTIdentifier & theID) { m_ServerID = theID; }
	
	inline const OTIdentifier & GetPurportedAccountID() const { return m_AcctID; }
	inline void					SetPurportedAccountID(const OTIdentifier & theID) {  m_AcctID = theID; }
	
	inline const OTIdentifier & GetPurportedServerID() const { return m_AcctServerID; }
	inline void					SetPurportedServerID(const OTIdentifier & theID) {  m_AcctServerID = theID; }

	
	// Compares the m_AcctID from the xml portion of the contract
	// with m_ID (supposedly the same number.)
	// Also Verifies the ServerID, since this object type is all about the both of those IDs.
	virtual bool VerifyContractID();  
	
	// This calls VerifyContractID() as well as VerifySignature() 
	// Use this instead of OTContract::VerifyContract, which expects/uses a pubkey from inside the contract.
	virtual bool VerifyAccount(OTPseudonym & theNym); 
	
	// The parameters to the constructor are supposed to be the ACTUAL account ID and server ID.
	// Whereas the child classes contain their own copies of those IDs which they load into their
	// own member variables. When that happens, they can then be compared to the ones that were
	// already passed in HERE to see if anything is fishy.
	// Thus, while OTContract instituted a constructor with an ID, OTTransactionType will require
	// both the Account ID and the ServerID.
	OTTransactionType(const OTIdentifier & theUserID, const OTIdentifier & theAccountID, const OTIdentifier & theServerID);
	OTTransactionType(const OTIdentifier & theUserID, const OTIdentifier & theAccountID, const OTIdentifier & theServerID, 
					  long lTransactionNum);

	void InitTransactionType();
	virtual ~OTTransactionType();
	
	// need to know the transaction number of this transaction? Call this.
	long GetTransactionNum() const;
	void SetTransactionNum(const long lTransactionNum);
	
	long GetReferenceToNum() const;
	void SetReferenceToNum(const long lTransactionNum);	
	
	void GetReferenceString(OTString & theStr) const;
	void SetReferenceString(const OTString & theStr);
	
	virtual bool SaveContractWallet(FILE * fl);
};


#endif // __OTTRANSACTION_TYPE_H__
