/************************************************************************************
 *    
 *  OTClient.h
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

#ifndef __OTCLIENT_H__
#define __OTCLIENT_H__

class OTPseudonym;
class OTAssetContract;
class OTServerContract;
class OTAccount;
class OTPayload;
class OTMessage;
class OTServerConnection;
class OTLedger;
class OTTransaction;

// This class represents the "test client"
//
// I have it separate from the wallet because I would like to be
// able to use the wallet in a "nice client" too, so I'm forcing
// the separation to keep it designed that way.
//

class OTClient
{
public:
	enum OT_CLIENT_CMD_TYPE 
	{
		checkServerID,		// Your public key is sent along with this message so the server can reply to 
							// you even without your being a registered user. Other than these top two commands, 
							// all other commands can only be executed by registered users.
							//
							// The server ID is a hash of the server contract. The signature on the contract
							// can be verified by a public key that appears in a standard section of any server
							// contract.  The URL/port information is also derived from the contract.
							//
							// Simply by importing the server contract into your wallet, you are able to connect
							// to it and encrypt all of your communications to it.
							//
							// Thus, the check server ID command really just confirms what you should already know...
							// Your wallet still wants to see that the server agrees with the server ID, and that
							// the server is able to read messages that were encrypted to the public key in the
							// contract, and that the server is able to sign all of its future correspondence with
							// the same public key.
							//
							// It is the server operator's responsibility to secure the domain name and web host
							// that users will connect to when they import the contract, as well as the private
							// key that matches the public key from the contract.
		
		createUserAccount,  // Create user account with public key. User ID will be hash of said public key.
		
		checkUser,			// Request a user's public key based on User ID included with the request.
							// (If you want to send him cash or a check, your wallet will encrypt portions
							// of the tokens, etc, to the Nym of the recipient.)
		
		getRequest,			// Get the next request number from the server (for this user). Most requests must be
							// accompanied by a request number, which increments for each Nym with each request.
		
		issueAssetType,		// Upload a currency contract to the server and create an asset ID from a hash of that. 
							// contract. Also creates an issuer account for that asset ID. This ONLY works if public
							// key of the user matches the contract key found in the currency contract, AND if the
							// contract is signed by the same key.
		
		createAccount,		// Create an asset account for a certain serverID, UserID, and Asset Type ID.
							// These accounts are where users actually store their digital assets of various
							// types. Account files are stored on user's computer, signed by notary server.
							// Server also maintains its own copy. Users can create an unlimited number of accounts
							// for any asset type that they choose.
		
		issueBasket,		// Create a basket account, which is like an issuer account, but based on a basket of 
							// other asset types. This way, users can trade with what is apparently a single currency, 
							// when in fact the issuence is delegated and distributed across multiple issuers.
		
		exchangeBasket,		// Use this to exchange assets in and out of a basket currency.
		
		getTransactionNum,	// Every transaction requires a transaction number. If your wallet doesn't have one, 
							// then here it can request the server to send one over. (Or several.)
		
		getInbox,			// Grab a copy of my inbox from the server so I can decide what to do with it.
		
		processInbox,		// Instruct the server what to do with the various items sitting in my inbox.
		
		getAccount,			// Grab the server's copy of my asset account file, in case mine is lost.
		
		getContract,		// Grab the server's copy of any asset contract. Input is the asset type ID.
		
		getMint,			// Grab the server's copy of any mint based on Asset ID. (For blinded tokens.)
		
		notarizeTransfer,	// Request the server to transfer from one account to another.
		
		notarizeWithdrawal,	// Request the server to withdraw from an asset account and return digital cash tokens to the wallet.
		
		withdrawVoucher,	// Request the server to withdraw from an asset account and issue a voucher (cashier's cheque)

		notarizeDeposit,	// Request the server to accept some digital cash and deposit it to an asset account.
		
		notarizePurse,		// Same as the above, but sends an entire purse of tokens at once instead of sending individual tokens.
		
		notarizeCheque,		// Deposit like the above, but deposits a cheque instead of cash tokens.
		
		badID
	};
	
	OTClient();
	~OTClient();
	
	bool ProcessUserCommand(OT_CLIENT_CMD_TYPE requestedCommand,
							OTMessage & theMessage,
							OTPseudonym & theNym,
//							OTAssetContract & theContract,
							OTServerContract & theServer,
							OTAccount * pAccount=0);

	bool ProcessServerReply(OTServerConnection & theConnection, OTMessage & theReply);

	void ProcessIncomingTransactions(OTServerConnection & theConnection, OTMessage & theReply);
	void ProcessWithdrawalResponse(OTTransaction & theTransaction, OTServerConnection & theConnection, OTMessage & theReply);
	void ProcessDepositResponse(OTTransaction & theTransaction, OTServerConnection & theConnection, OTMessage & theReply);

	
	void AcceptEntireInbox(OTLedger & theInbox, OTServerConnection & theConnection);
	
	void HarvestTransactionNumbers(OTTransaction & theTransaction, OTPseudonym & theNym);	

};

#endif // __OTCLIENT_H__