/************************************************************************************
 *    
 *  OTServer.h
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

#ifndef __OTSERVER_H__
#define __OTSERVER_H__

#include "OTString.h"
#include "OTPseudonym.h"
#include "OTMint.h"
#include "OTAssetContract.h"

class OTMessage;
class OTClientConnection;
class OTAccount;
class OTTransaction;

// these correspond--same IDs.
typedef std::map<std::string, OTMint *>		mapOfMints;
typedef std::map<std::string, std::string>	mapOfBaskets;

class OTServer
{
	OTString	m_strVersion;
	OTString	m_strServerID;
	long		m_lTransactionNumber;	// This stores the last VALID AND ISSUED transaction number.

	
	OTPseudonym m_nymServer; // the Nym for the server, so he can decrypt messages sent to him
							 // by paranoid users :-P  UPDATE: By ALL users. Everything encrypted now by default.
	
	mapOfContracts	m_mapContracts;	// The asset types supported by this server.
	mapOfMints		m_mapMints;		// The mints for each asset type.
	
	mapOfBaskets	m_mapBaskets;	// this map connects BASKET_ID with BASKET_ACCOUNT_ID (so you can look up the server's
									// basket issuer account ID, which is *different* on each server, using the Basket Currency's
									// ID, which is the *same* on every server.)
	mapOfBaskets	m_mapBasketContracts; // Need a way to look up a Basket Account ID using its Contract ID 
	
public:
	OTServer();
	~OTServer();
	
	OTMint * GetMint(const OTIdentifier & ASSET_TYPE_ID); // Each asset contract has its own Mint.
	
	// When a user uploads an asset contract, the server adds it to the list (and verifies the user's key against the
	// contract.) This way the server has a directory with all the asset contracts that it supports, saved by their ID.
	// As long as the IDs are in the server file, it can look them up.
	// When a new asset type is added, a new Mint is added as well. It goes into the mints folder.
	bool	AddAssetContract(OTAssetContract & theContract);
	OTAssetContract * GetAssetContract(const OTIdentifier & ASSET_TYPE_ID);
	
	bool AddBasketAccountID(const OTIdentifier & BASKET_ID, const OTIdentifier & BASKET_ACCOUNT_ID,
							const OTIdentifier & BASKET_CONTRACT_ID);
	bool LookupBasketAccountID(const OTIdentifier & BASKET_ID, OTIdentifier & BASKET_ACCOUNT_ID);
	bool VerifyBasketAccountID(const OTIdentifier & BASKET_ACCOUNT_ID);

	bool LookupBasketAccountIDByContractID(const OTIdentifier & BASKET_CONTRACT_ID, OTIdentifier & BASKET_ACCOUNT_ID);
	bool LookupBasketContractIDByAccountID(const OTIdentifier & BASKET_ACCOUNT_ID, OTIdentifier & BASKET_CONTRACT_ID);

	const OTPseudonym & GetServerNym() const;
	
	void Init(); // Loads the main file...
	
	bool LoadMainFile(); // Called in Init. Loads transaction number.
	bool SaveMainFile(); // Called in GetNextTransactionNumber.
	
	bool ProcessUserCommand(OTClientConnection & theConnection, OTMessage & theMessage, OTMessage & MsgOut);
	bool ValidateServerIDfromUser(OTString & strServerID);
	
	void UserCmdCheckServerID(OTPseudonym & theNym, OTMessage & MsgIn, OTMessage & msgOut);
	void UserCmdCheckUser(OTPseudonym & theNym, OTMessage & MsgIn, OTMessage & msgOut);
	void UserCmdGetRequest(OTPseudonym & theNym, OTMessage & msgIn, OTMessage & msgOut);
	void UserCmdGetTransactionNum(OTPseudonym & theNym, OTMessage & msgIn, OTMessage & msgOut);
	void UserCmdIssueAssetType(OTPseudonym & theNym, OTMessage & MsgIn, OTMessage & msgOut);
	void UserCmdIssueBasket(OTPseudonym & theNym, OTMessage & MsgIn, OTMessage & msgOut);
	void UserCmdExchangeBasket(OTPseudonym & theNym, OTMessage & MsgIn, OTMessage & msgOut);
	void UserCmdCreateAccount(OTPseudonym & theNym, OTMessage & MsgIn, OTMessage & msgOut);
	void UserCmdNotarizeTransactions(OTPseudonym & theNym, OTMessage & MsgIn, OTMessage & msgOut);
	void UserCmdGetInbox(OTPseudonym & theNym, OTMessage & MsgIn, OTMessage & msgOut);
	void UserCmdGetAccount(OTPseudonym & theNym, OTMessage & MsgIn, OTMessage & msgOut);
	void UserCmdGetContract(OTPseudonym & theNym, OTMessage & MsgIn, OTMessage & msgOut);
	void UserCmdGetMint(OTPseudonym & theNym, OTMessage & MsgIn, OTMessage & msgOut);
	void UserCmdProcessInbox(OTPseudonym & theNym, OTMessage & MsgIn, OTMessage & msgOut);

	bool VerifyTransactionNumber(long &lTransactionNumber); // verify a transaction number. passed by reference for speed :P
	bool GetNextTransactionNumber(long &lTransactionNumber); // issue the next transaction number	
	
	// If the server receives a notarizeTransactions command, it will be accompanied by a payload
	// containing a ledger to be notarized.  UserCmdNotarizeTransactions will loop through that ledger,
	// and for each transaction within, it calls THIS method.
	void NotarizeTransaction(OTPseudonym & theNym, OTTransaction & tranIn, OTTransaction & tranOut);
	
	void NotarizeTransfer(OTPseudonym & theNym, OTAccount & theFromAccount, OTTransaction & tranIn, OTTransaction & tranOut);
	void NotarizeDeposit(OTPseudonym & theNym, OTAccount & theAccount, OTTransaction & tranIn, OTTransaction & tranOut);
	void NotarizeWithdrawal(OTPseudonym & theNym, OTAccount & theAccount, OTTransaction & tranIn, OTTransaction & tranOut);
	void NotarizeProcessInbox(OTPseudonym & theNym, OTAccount & theAccount, OTTransaction & tranIn, OTTransaction & tranOut);	
};


#endif // __OTSERVER_H__
