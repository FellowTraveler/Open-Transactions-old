/************************************************************************************
 *    
 *  OTAccount.h
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


#ifndef __OTACCOUNT_H__
#define __OTACCOUNT_H__

#include <list>
#include <fstream>

#include "OTTransactionType.h"
#include "OTString.h"

class OTPseudonym;
class OTAccount;
class OTMessage;
class OTLedger;



class OTAccount : public OTTransactionType 
{
    friend OTTransactionType * OTTransactionType::TransactionFactory(const OTString & strInput);

public:
	enum AccountType {
		simple,
		issuer,
		basket,
		err_acct
	};  // If you add any types to this list, update the list of strings at the top of the .CPP file.
	
protected:
	
	AccountType		m_AcctType;
	
	OTIdentifier	m_AcctAssetTypeID; // These are all the variables from the account file itself.

	OTString		m_BalanceDate;
	OTString		m_BalanceAmount;


	// return -1 if error, 0 if nothing, and 1 if the node was processed.
	virtual int ProcessXMLNode(irr::io::IrrXMLReader*& xml);

	virtual void UpdateContents();
	OTAccount(const OTIdentifier & theUserID, const OTIdentifier & theServerID);
	OTAccount();

    bool        m_bMarkForDeletion; // Default FALSE. When set to true, saves a "DELETED" flag with this Account, 
                                    // for easy cleanup later when the server is doing some maintenance.
public:	

    inline void MarkForDeletion() { m_bMarkForDeletion = true; }
    inline bool IsMarkedForDeletion() const { return m_bMarkForDeletion; }

    // ---------------------------------------
	
    OTAccount(const OTIdentifier & theUserID, const OTIdentifier & theAccountID, const OTIdentifier & theServerID, const OTString & name);
	OTAccount(const OTIdentifier & theUserID, const OTIdentifier & theAccountID, const OTIdentifier & theServerID);
	void InitAccount();
	virtual ~OTAccount();
	
	static OTAccount * GenerateNewAccount(const OTIdentifier & theUserID, const OTIdentifier & theServerID, 
										  const OTPseudonym & theServerNym, const OTMessage & theMessage,
										  const AccountType eAcctType=simple);

	bool GenerateNewAccount(const OTPseudonym & theServer, const OTMessage & theMessage, const AccountType eAcctType=simple);

	// Let's say you don't have or know the UserID, and you just want to load the damn thing up.
	// Then call this function. It will set userID for you.
	static OTAccount * LoadExistingAccount(const OTIdentifier & theAccountID, const OTIdentifier & theServerID);

	
	OTLedger * LoadInbox(OTPseudonym & theNym); // Caller responsible to delete.
	OTLedger * LoadOutbox(OTPseudonym & theNym); // Caller responsible to delete.
	
	// gives you the asset type ID of this account. (the asset contract hash.)
	const OTIdentifier & GetAssetTypeID();
	
	long GetBalance() const;
	
	bool Debit(const long & lAmount); // Debit a certain amount from the account (presumably the same amount is being added somewhere)
	bool Credit(const long & lAmount); // Credit a certain amount from the account (presumably the same amount is being subtracted somewhere)
		
	// Compares the NymID loaded from the account file with whatever Nym the programmer wants to verify.
	bool VerifyOwner(OTPseudonym & theCandidate);
	
	virtual bool LoadContract(); // overriding this so I can set the filename automatically inside based on ID.
	bool SaveAccount(); // generates filename based on accounts path and account ID. Saves to the standard location for an acct.
		
//	virtual bool SaveContractWallet(FILE * fl);
	virtual bool SaveContractWallet(std::ofstream & ofs);
	virtual bool SaveContractWallet(OTString & strContents) const;
	
	virtual bool DisplayStatistics(OTString & strContents) const;

	// --------------------------------------------------------------

	static const char * _TypeStrings[]; // for translating transaction type into a string.
	
	static inline const char * _GetTypeString(AccountType theType)
	{ int nType = (int)theType; return OTAccount::_TypeStrings[nType]; }
	
	inline const char * GetTypeString() { return OTAccount::_GetTypeString(m_AcctType); }
};

typedef std::list <OTAccount *>	listOfAccounts;

#endif // __OTACCOUNT_H__
