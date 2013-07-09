/************************************************************
 *    
 *  OTBasket.h
 *  
 */

/************************************************************
 -----BEGIN PGP SIGNED MESSAGE-----
 Hash: SHA1
 
 *                 OPEN TRANSACTIONS
 *
 *       Financial Cryptography and Digital Cash
 *       Library, Protocol, API, Server, CLI, GUI
 *
 *       -- Anonymous Numbered Accounts.
 *       -- Untraceable Digital Cash.
 *       -- Triple-Signed Receipts.
 *       -- Cheques, Vouchers, Transfers, Inboxes.
 *       -- Basket Currencies, Markets, Payment Plans.
 *       -- Signed, XML, Ricardian-style Contracts.
 *       -- Scripted smart contracts.
 *
 *  Copyright (C) 2010-2013 by "Fellow Traveler" (A pseudonym)
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
 *   -- otlib.........A class library.......LICENSE:...LAGPLv3
 *   -- otapi.........A client API..........LICENSE:...LAGPLv3
 *   -- opentxs/ot....Command-line client...LICENSE:...LAGPLv3
 *   -- otserver......Server Application....LICENSE:....AGPLv3
 *  Github.com/FellowTraveler/Open-Transactions/wiki/Components
 *
 *  All of the above OT components were designed and written by
 *  Fellow Traveler, with the exception of Moneychanger, which
 *  was contracted out to Vicky C (bitcointrader4@gmail.com).
 *  The open-source community has since actively contributed.
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
 *   (==> This means if you are only using the OT API, then you
 *   don't have to open-source your code--only your changes to
 *   Open-Transactions itself must be open source. Similar to
 *   LGPLv3, except it applies to software-as-a-service, not
 *   just to distributing binaries.)
 *
 *   Extra WAIVER for OpenSSL, Lucre, and all other libraries
 *   used by Open Transactions: This program is released under
 *   the AGPL with the additional exemption that compiling,
 *   linking, and/or using OpenSSL is allowed. The same is true
 *   for any other open source libraries included in this
 *   project: complete waiver from the AGPL is hereby granted to
 *   compile, link, and/or use them with Open-Transactions,
 *   according to their own terms, as long as the rest of the
 *   Open-Transactions terms remain respected, with regard to
 *   the Open-Transactions code itself.
 *
 *   Lucre License:
 *   This code is also "dual-license", meaning that Ben Lau-
 *   rie's license must also be included and respected, since
 *   the code for Lucre is also included with Open Transactions.
 *   See Open-Transactions/src/otlib/lucre/LUCRE_LICENSE.txt
 *   The Laurie requirements are light, but if there is any
 *   problem with his license, simply remove the Lucre code.
 *   Although there are no other blind token algorithms in Open
 *   Transactions (yet. credlib is coming), the other functions
 *   will continue to operate.
 *   See Lucre on Github:  https://github.com/benlaurie/lucre
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
 Version: GnuPG v1.4.9 (Darwin)
 
 iQIcBAEBAgAGBQJRSsfJAAoJEAMIAO35UbuOQT8P/RJbka8etf7wbxdHQNAY+2cC
 vDf8J3X8VI+pwMqv6wgTVy17venMZJa4I4ikXD/MRyWV1XbTG0mBXk/7AZk7Rexk
 KTvL/U1kWiez6+8XXLye+k2JNM6v7eej8xMrqEcO0ZArh/DsLoIn1y8p8qjBI7+m
 aE7lhstDiD0z8mwRRLKFLN2IH5rAFaZZUvj5ERJaoYUKdn4c+RcQVei2YOl4T0FU
 LWND3YLoH8naqJXkaOKEN4UfJINCwxhe5Ke9wyfLWLUO7NamRkWD2T7CJ0xocnD1
 sjAzlVGNgaFDRflfIF4QhBx1Ddl6wwhJfw+d08bjqblSq8aXDkmFA7HeunSFKkdn
 oIEOEgyj+veuOMRJC5pnBJ9vV+7qRdDKQWaCKotynt4sWJDGQ9kWGWm74SsNaduN
 TPMyr9kNmGsfR69Q2Zq/FLcLX/j8ESxU+HYUB4vaARw2xEOu2xwDDv6jt0j3Vqsg
 x7rWv4S/Eh18FDNDkVRChiNoOIilLYLL6c38uMf1pnItBuxP3uhgY6COm59kVaRh
 nyGTYCDYD2TK+fI9o89F1297uDCwEJ62U0Q7iTDp5QuXCoxkPfv8/kX6lS6T3y9G
 M9mqIoLbIQ1EDntFv7/t6fUTS2+46uCrdZWbQ5RjYXdrzjij02nDmJAm2BngnZvd
 kamH0Y/n11lCvo1oQxM+
 =uSzz
 -----END PGP SIGNATURE-----
 **************************************************************/


#ifndef __OTBASKET_H__
#define __OTBASKET_H__

#ifndef EXPORT
#define EXPORT
#endif
#include <ExportWrapper.h>

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
private:  // Private prevents erroneous use by other classes.
    typedef OTContract ot_super;
						 
protected:
	int		m_nSubCount;
	long	m_lMinimumTransfer;			// used in the actual basket
	// -------------------------------------------------------------------------
	int		m_nTransferMultiple;		// used in a request basket. If non-zero, that means this is a request basket.
    // -------------------------------------------------------------------------
	OTIdentifier m_RequestAccountID;	// used in a request basket so the server knows your acct ID.
    // -------------------------------------------------------------------------
	dequeOfBasketItems	m_dequeItems;
    // -------------------------------------------------------------------------
	bool	m_bHideAccountID;	// When saving, we might wish to produce a version without Account IDs
								// So that the resulting hash will be a consistent ID across different servers.
	// -------------------------------------------------------------------------
    bool    m_bExchangingIn;    // True if exchanging INTO the basket, False if exchanging OUT of the basket.
	// -------------------------------------------------------------------------
    long	m_lClosingTransactionNo;  // For the main (basket) account, in a request basket (for exchanges.)
	// -------------------------------------------------------------------------
	// return -1 if error, 0 if nothing, and 1 if the node was processed.
	virtual int ProcessXMLNode(irr::io::IrrXMLReader*& xml);
public:
EXPORT	OTBasket();
EXPORT	OTBasket(int nCount, long lMinimumTransferAmount);
EXPORT	virtual ~OTBasket();
		
	virtual void UpdateContents();
//	virtual bool SaveContractWallet(FILE * fl);	
	virtual bool SaveContractWallet(std::ofstream & ofs);

EXPORT	virtual void CalculateContractID(OTIdentifier & newID);
	
	inline long GetMinimumTransfer() const { return m_lMinimumTransfer; }
	
	inline int	GetTransferMultiple() const { return m_nTransferMultiple; }
	inline void SetTransferMultiple(const int nTransferMultiple) { m_nTransferMultiple = nTransferMultiple; } 
	
    inline bool IsExchanging() const { return (m_nTransferMultiple > 0); }
    
    inline bool GetExchangingIn() const { return m_bExchangingIn; }
    inline void SetExchangingIn(const bool bDirection) { m_bExchangingIn = bDirection; } 
    
EXPORT	int Count() const;
EXPORT	BasketItem * At(unsigned int nIndex);

    long GetClosingTransactionNoAt(unsigned int nIndex);

    inline long GetClosingNum() const { return m_lClosingTransactionNo; }
    inline void SetClosingNum(const long & lClosingNum) { m_lClosingTransactionNo = lClosingNum; }
    
	// For generating a real basket.  The user does this part, and the server creates Account ID later
	// (That's why you don't see the account ID being passed in to the method.)
EXPORT	void AddSubContract(const OTIdentifier & SUB_CONTRACT_ID, long lMinimumTransferAmount);
	inline void IncrementSubCount() { m_nSubCount++; } // Used to abstract away this detail in the API.
	
	// For generating a user request to exchange in/out of a basket.
	// Assumes that SetTransferMultiple has already been called.
EXPORT	void AddRequestSubContract(const OTIdentifier & SUB_CONTRACT_ID, 
                                   const OTIdentifier & SUB_ACCOUNT_ID,
                                   const long & lClosingTransactionNo);
	
	inline void SetRequestAccountID(const OTIdentifier & theAccountID) { m_RequestAccountID = theAccountID; }
	inline const OTIdentifier & GetRequestAccountID() { return m_RequestAccountID; }

	virtual void Release();
	void Release_Basket();
    
    // -----------------------------------------------------------------------------
    //
    // NOTE: Experimental / new (here):
    
    // The basket itself only stores the CLOSING numbers.
    // For the opening number, you have to go deal with the exchangeBasket TRANSACTION.
        
    // Normally do this if your transaction failed so you can get most of your numbers back
    //
EXPORT void HarvestClosingNumbers(OTPseudonym & theNym, const OTIdentifier & theServerID, const bool bSave=true);
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

