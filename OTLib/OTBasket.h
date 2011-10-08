/************************************************************************************
 *    
 *  OTBasket.h
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
 *  Copyright (C) 2010-2012 by "Fellow Traveler" (A pseudonym)
 *
 *  EMAIL:
 *  FellowTraveler@rayservers.net
 *  
 *  BITCOIN:  1NtTPVVjDsUfDWybS4BwvHpG2pdS9RnYyQ
 *
 *  KEY FINGERPRINT (PGP Key in license file):
 *  9DD5 90EB 9292 4B48 0484  7910 0308 00ED F951 BB8E
 *
 *  OFFICIAL PROJECT WIKI(s):
 *  https://github.com/FellowTraveler/Moneychanger
 *  https://github.com/FellowTraveler/Open-Transactions/wiki 
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
 Version: GnuPG v1.4.11 (Darwin)
 
 iQIcBAEBCAAGBQJOjvvUAAoJEAMIAO35UbuOBlMP/1LX0xJ9CrTOe1G/mgc+VygT
 JPVZDAbQDL/lJXOZMbaPJ/GaLXyEnTViHp97ERrlVuBQz+9uonIKCmPqAGYGVBG1
 MGV2QcscXU2aOUT1VPf2OYEOIul0h8FX2lixfqouH9/OkVsGRLr79Zu8z3zdsO4R
 ktQtjZEU6lnL2t6cmp/cuXlQnbz1xvxd56xNDR11YP07Z4x+CuDB4EAK+P9TfCwn
 tqq5yJmxJM9HtMoi3cUU7kXodKm1n1YZt7O46DOxHqbXqErHChN1ekSK0fXad614
 Gmh+5JfvHjx5XoFWMxb46aAAcUiG8+QpFBcKtSYP2X96k1ylgxMCzrK60ec/MxKV
 BzvP00OJ6PzzrTlcUaCgJ8ZX+0scOMvW0XKioEorozKSWNFvT4Drc4Thhy8u9ET3
 ru1enNFrjdxKjw2+ZTQcKSZjSRx2kMQ2od/dkqUlhe/M1cHGhseH6ls7pItrkykE
 ufZ9GlZoxYE+FRatIBPneT9WwsvFFvH+i6cQ/MM9pbTr19g6VPzVZ4U9E65BbTDB
 czITynH+uMtJLbprtCdQlsI+vqTgYNoY8AUsmnr1qUkp020qGlvwfCJVrooisTmm
 yIh+Yp/KBzySU3inzclaAfv102/t5xi1l+GTyWHiwZxlyt5PBVglKWx/Ust9CIvN
 6h9BYZFTZrh/OwBXCdAv
 =MUfS
 -----END PGP SIGNATURE-----
 **************************************************************/


#ifndef __OTBASKET_H__
#define __OTBASKET_H__

#include <deque>
#include <fstream>

#include "OTIdentifier.h"
#include "OTContract.h"



class BasketItem 
{
public:
	OTIdentifier SUB_CONTRACT_ID;
	OTIdentifier SUB_ACCOUNT_ID;
	
	long	lMinimumTransferAmount;
    
    // lClosingTransactionNo:
    // Used when EXCHANGING a basket (NOT USED when first creating one.)
    // A basketReceipt must be dropped into each asset account during
    // an exchange, to account for the change in balance. Until that
    // receipt is accepted, lClosingTransactionNo will remain open as
    // an issued transaction number (an open transaction) on that Nym.
    // (One must be supplied for EACH asset account during an exchange.)
    //
	long	lClosingTransactionNo;  
	
	BasketItem();
	~BasketItem() {}
};



typedef std::deque <BasketItem *> dequeOfBasketItems;


class OTBasket : public OTContract
{
public:
						 
protected:
	
	int		m_nSubCount;
	long	m_lMinimumTransfer;			// used in the actual basket

	int		m_nTransferMultiple;		// used in a request basket. If non-zero, that means this is a request basket.
	
	OTIdentifier m_RequestAccountID;	// used in a request basket so the server knows your acct ID.
	
	dequeOfBasketItems	m_dequeItems;
	
	bool	m_bHideAccountID;	// When saving, we might wish to produce a version without Account IDs
								// So that the resulting hash will be a consistent ID across different servers.
	
    bool    m_bExchangingIn;    // True if exchanging INTO the basket, False if exchanging OUT of the basket.
    
    long	m_lClosingTransactionNo;  // For the main (basket) account, in a request basket (for exchanges.)

	// return -1 if error, 0 if nothing, and 1 if the node was processed.
	virtual int ProcessXMLNode(irr::io::IrrXMLReader*& xml);
public:
	OTBasket();
	OTBasket(int nCount, long lMinimumTransferAmount);
	virtual ~OTBasket();
		
	virtual void UpdateContents();
//	virtual bool SaveContractWallet(FILE * fl);	
	virtual bool SaveContractWallet(std::ofstream & ofs);

	virtual void CalculateContractID(OTIdentifier & newID);
	
	inline long GetMinimumTransfer() const { return m_lMinimumTransfer; }
	
	inline int	GetTransferMultiple() const { return m_nTransferMultiple; }
	inline void SetTransferMultiple(const int nTransferMultiple) { m_nTransferMultiple = nTransferMultiple; } 
	
    inline bool GetExchangingIn() const { return m_bExchangingIn; }
    inline void SetExchangingIn(const bool bDirection) { m_bExchangingIn = bDirection; } 
    
	int Count() const;
	BasketItem * At(unsigned int nIndex);

    long GetClosingTransactionNoAt(unsigned int nIndex);

    inline long GetClosingNum() const { return m_lClosingTransactionNo; }
    inline void SetClosingNum(const long & lClosingNum) { m_lClosingTransactionNo = lClosingNum; }
    
	// For generating a real basket.  The user does this part, and the server creates Account ID later
	// (That's why you don't see the account ID being passed in to the method.)
	void AddSubContract(const OTIdentifier & SUB_CONTRACT_ID, long lMinimumTransferAmount);
	inline void IncrementSubCount() { m_nSubCount++; } // Used to abstract away this detail in the API.
	
	// For generating a user request to exchange in/out of a basket.
	// Assumes that SetTransferMultiple has already been called.
	void AddRequestSubContract(const OTIdentifier & SUB_CONTRACT_ID, 
                               const OTIdentifier & SUB_ACCOUNT_ID,
                               const long & lClosingTransactionNo);
	
	inline void SetRequestAccountID(const OTIdentifier & theAccountID) { m_RequestAccountID = theAccountID; }
	inline const OTIdentifier & GetRequestAccountID() { return m_RequestAccountID; }

	void ReleaseBasket();
};





#endif // __OTBASKET_H__

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

