/*************************************************************
 *    
 *  OTPurse.h
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


#ifndef __OTPURSE_H__
#define __OTPURSE_H__

#include <deque>
#include <map>
#include <string>
#include <fstream>

#include "OTContract.h"
#include "OTToken.h"
#include "OTASCIIArmor.h"

class OTPurse;

// A token has no User ID, or Account ID, or even a traceable TokenID (the tokenID only becomes relevant
// after it is spent.)
// But a purse can be stuffed full of tokens, and can be saved by accountID as filename, and can have its
// contents encrypted to the public key of a specific user.
//
// I will add an optional UserID field, so it's obvious whose public key to use for opening the tokens.
// This may seem odd, but the field is entirely optional because it's not necessary for the actual operation.
// The recipient will already know to use his own private key to open the purse, and then he will immediately
// open it, redeem the coins, and store the replacements again encrypted to his own key, until he spends them
// again to someone else, when he will also know to encrypt the purse to THEIR public key, and so on.

// The interface of this class is that of a simple stack.
// Imagine a stack of poker chips.

typedef std::deque <OTASCIIArmor *> dequeOfTokens;
typedef std::map<std::string, OTToken *>	mapOfTokenPointers;

class OTPurse : public OTContract 
{
protected:
	virtual void UpdateContents(); // Before transmission or serialization, this is where the Purse saves its contents 

	dequeOfTokens	m_dequeTokens;
	
	OTIdentifier	m_UserID;	// Optional
	OTIdentifier	m_ServerID;	// Mandatory
	OTIdentifier	m_AssetID;	// Mandatory
	
	long	m_lTotalValue; // Push increments this by denomination, and Pop decrements it by denomination.
	
public:
	virtual int ProcessXMLNode(irr::io::IrrXMLReader*& xml);
	

	OTToken *	Pop(const OTPseudonym & theOwner);		// Caller is responsible to delete
	// OTPurse::Push makes it's own copy of theToken and does NOT take ownership of the one passed in.
	bool		Push(const OTPseudonym & theOwner, const OTToken & theToken);	
	int			Count() const;
	bool		IsEmpty() const;
	
	inline long	GetTotalValue() const { return m_lTotalValue; }
	
	bool Merge(OTPseudonym & theNym, OTPurse & theNewPurse);
	
	OTPurse(const OTPurse & thePurse); // just for copy another purse's Server and Asset ID
	OTPurse(const OTIdentifier & SERVER_ID, const OTIdentifier & ASSET_ID); // similar thing
	OTPurse(const OTIdentifier & SERVER_ID); // Don't use this unless you really don't know the asset type
											// (Like if you're about to read it out of a string.)
											// Normally you really really want to set the asset type.
	OTPurse(const OTIdentifier & SERVER_ID, const OTIdentifier & ASSET_ID, const OTIdentifier & USER_ID); // UserID optional
	virtual ~OTPurse();

	bool LoadPurse(const char * szServerID=NULL, const char * szUserID=NULL, const char * szAssetTypeID=NULL);
	bool SavePurse(const char * szServerID=NULL, const char * szUserID=NULL, const char * szAssetTypeID=NULL);

	virtual bool LoadContract();

	inline const OTIdentifier & GetServerID() const { return m_ServerID; }
	inline const OTIdentifier & GetAssetID() const { return m_AssetID; }
	
	void InitPurse();
	virtual void Release();
	void ReleaseTokens();
	
	virtual bool SaveContractWallet(std::ofstream & ofs);
//	virtual bool SaveContractWallet(FILE * fl);	
};


#endif // __OTPURSE_H__

