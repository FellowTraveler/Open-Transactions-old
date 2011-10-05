/************************************************************************************
 *    
 *  OTTransactionType.h
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
 *  Copyright (C) 2010-2011 by "Fellow Traveler" (A pseudonym)
 *
 *  EMAIL:
 *  FellowTraveler@rayservers.net --- SEE PGP KEY BELOW.
 *  F3llowTraveler@gmail.com --- (not preferred.)
 *  
 *  BITCOIN:  1NtTPVVjDsUfDWybS4BwvHpG2pdS9RnYyQ
 *
 *  KEY FINGERPRINT:
 *  9DD5 90EB 9292 4B48 0484  7910 0308 00ED F951 BB8E
 *
 *  OFFICIAL PROJECT WIKI(s):
 *  http://wiki.github.com/FellowTraveler/Open-Transactions/wiki 
 *  http://wiki.github.com/FellowTraveler/Moneychanger/wiki 
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
 Version: GnuPG v1.4.10 (Darwin)
 
 iQIcBAEBCAAGBQJNsV9NAAoJEAMIAO35UbuOB3IP/12THBedTYrR2F2hkhYKK+0H
 YlVwRJyFnX3uKjDkYx2fpB2yNaMPPyiQRFpQBpiUxB2wSMHelM+m4YxVegx7h15s
 nD+jMLeVnlhgfKYsVZZiCKT58HXVsuGDc/iycXBBIQYBjCzbeCCG0vyEapR+sCwF
 eGR5l7yGbcMWaVqjPawqSMe/5Ie0wstWMrNAkLlWHRn/ISXb8vMusaxCe9kSeUX8
 7ZSZ0ojy3gLTZnUHFFZ2RaMepVB9jVoMSdVG89mEHX383foTuaxedjI2Wsw6J8YR
 D7PFp6PLGhm1eqArmotCj5NeV9lleULdnvR7T4QwzOZjI65kMwi/e1W6GyvzT3RZ
 RrLaZwiagcyKTXyEX5qSBQfSVNwC761rgNTG0fCBrBmDbQxet4A6Y+ZMxZmE0QXb
 Xch/g4g9Lki0TrSOx0zSAAcpLCIrqdvGX2jcmmJ/Ex4ZhzVhMvtkGfui9bUaY2bU
 bdu1GY0CfmElZ7+wXh2AutkMscRtnu62VSdGjrqry3KJMBWbtxNA9Q+U+NipWnYN
 yisBlQBADkXNtkL3EXEqX6OnjGfHNZ3G1bwuELcZjoOL+K0aQKCojRf8Ii5DW0A3
 niqzq/dwpt45VaQ+uYSG7Sg19FNvADg+WILdFcyszfS8Wks6BsKYzHUc5zbf3SFc
 JaOXLV9Ss58mj57JpNp8
 =VjLJ
 -----END PGP SIGNATURE-----
 **************************************************************/


#ifndef __OTTRANSACTION_TYPE_H__
#define __OTTRANSACTION_TYPE_H__

#include <fstream>

#include "OTASCIIArmor.h"
#include "OTContract.h"

class OTString;
class OTIdentifier;


// use as a base class for OTLedger, OTTransaction, and OTItem
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
	
    bool            m_bLoadSecurely; // defaults to true.
    
public:
	
    static OTTransactionType * TransactionFactory(const OTString & strInput);

    // ------------------------------------------------------------------
    
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
	virtual void Release();

	// need to know the transaction number of this transaction? Call this.
	long GetTransactionNum() const;
	void SetTransactionNum(const long lTransactionNum);
	
	long GetReferenceToNum() const;
	void SetReferenceToNum(const long lTransactionNum);	
	
	void GetReferenceString(OTString & theStr) const;
	void SetReferenceString(const OTString & theStr);
	
//	virtual bool SaveContractWallet(FILE * fl);
	virtual bool SaveContractWallet(std::ofstream & ofs);
};


#endif // __OTTRANSACTION_TYPE_H__
