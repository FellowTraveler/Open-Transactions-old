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

#ifndef EXPORT
#define EXPORT
#endif
#include <ExportWrapper.h>

#include <deque>
#include <map>
#include <string>
#include <fstream>

#include "OTContract.h"
#include "OTToken.h"
#include "OTASCIIArmor.h"

class OTPurse;
class OTPseudonym;
class OTNym_or_SymmetricKey;

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


typedef std::deque  <OTASCIIArmor *>            dequeOfTokens;
typedef std::map    <std::string, OTToken *>    mapOfTokenPointers;


class OTPurse : public OTContract 
{
private:  // Private prevents erroneous use by other classes.
	typedef OTContract ot_super;

protected:
	virtual void UpdateContents(); // Before transmission or serialization, this is where the Purse saves its contents 

	dequeOfTokens	m_dequeTokens;

	// Todo: Add a boolean value, so that the UserID is either for a real user, or is for a temp Nym
	// which must be ATTACHED to the purse, if that boolean is set to true.

	OTIdentifier	m_UserID;     // Optional
	OTIdentifier	m_ServerID;   // Mandatory
	OTIdentifier	m_AssetID;    // Mandatory
	// ----------------------------------------------
	long            m_lTotalValue;   // Push increments this by denomination, and Pop decrements it by denomination.
	// ----------------------------------------------
	bool            m_bPasswordProtected;  // this purse might be encrypted to a passphrase, instead of a Nym.
	// If that's the case, BTW, then there will be a Symmetric Key and a Master Key.
	// The symmetric key is used to store the actual key for encrypting/decrypting the tokens in this purse.
	// Whereas the master key is used for retrieving the passphrase to use for unlocking the symmetric key.
	// The passphrase in question is actually a random number stored inside the master key, inside its own
	// internal symmetric key. In order to unlock it, OTCachedKey may occasionally ask the user to enter a
	// passphrase, which is used to derived a key to unlock it. This key may then be cached in memory by
	// OTCachedKey until a timeout, and later be zapped by a thread for that purpose.
	// ----------------------------------------------
	bool            m_bIsNymIDIncluded; // It's possible to use a purse WITHOUT attaching the relevant NymID. (The holder of the purse just has to "know" what the correct NymID is, or it won't work.) This bool tells us whether the ID is attached, or not.
	// ----------------------------------------------
	OTSymmetricKey *   m_pSymmetricKey;    // If this purse contains its own symmetric key (instead of using an owner Nym)...
	OTCachedKey    *   m_pCachedKey;       // ...then it will have a master key as well, for unlocking that symmetric key, and managing timeouts, etc.

	OTPurse(); // private

public:
	// OTPayment needs to be able to instantiate OTPurse without knowing the server ID
	// in advance. I decided to add a factory for OTPurse to facilitate that.
	EXPORT	static OTPurse * PurseFactory( OTString strInput);
	EXPORT	static OTPurse * PurseFactory( OTString strInput, const OTIdentifier & SERVER_ID);
	EXPORT	static OTPurse * PurseFactory( OTString strInput, const OTIdentifier & SERVER_ID, const OTIdentifier & ASSET_ID);
	EXPORT	static OTPurse * LowLevelInstantiate(const OTString & strFirstLine);
	EXPORT	static OTPurse * LowLevelInstantiate(const OTString & strFirstLine, const OTIdentifier & SERVER_ID);
	EXPORT	static OTPurse * LowLevelInstantiate(const OTString & strFirstLine, const OTIdentifier & SERVER_ID, const OTIdentifier & ASSET_ID);
	// ----------------------------------------------
	virtual int ProcessXMLNode(irr::io::IrrXMLReader*& xml);
	// ----------------------------------------------
	// What if you DON'T want to encrypt the purse to your Nym??
	// What if you just want to use a passphrase instead?
	// That's what these functions are for. OT just generates
	// an internal symmetric key and stores it INSIDE THE PURSE.
	// You set the passphrase for the internal key, and thereafter
	// your experience is one of a password-protected purse.
	//
	EXPORT    bool             GenerateInternalKey(); // Create internal symmetric key for password-protected purse.
	EXPORT    OTSymmetricKey * GetInternalKey() { return m_pSymmetricKey; } // symmetric key for this purse.
	EXPORT    OTCachedKey    * GetInternalMaster();  // stores the passphrase for the symmetric key.
	EXPORT    bool             GetPassphrase(OTPassword & theOutput, const char * szDisplay=NULL); // Retrieves the passphrase for this purse (which is cached by the master key.) Prompts the user to enter his actual passphrase, if necessary to unlock it. (May not need unlocking yet -- there is a timeout.)
	// ----------------------------------------------
	EXPORT    bool             IsNymIDIncluded() const { return m_bIsNymIDIncluded; } // NymID may be left blank, with user left guessing.
	// ----------------------------------------------    
	EXPORT    bool             IsPasswordProtected() const { return m_bPasswordProtected; }
	// ----------------------------------------------
	// This will return false every time, if IsNymIDIncluded() is false.
	EXPORT  bool         GetNymID(OTIdentifier & theOutput) const;
	// ----------------------------------------------
	// FYI: OTPurse::Push makes its own copy of theToken and does NOT take ownership of the one passed in.
	EXPORT	bool		 Push(OTNym_or_SymmetricKey theOwner, const OTToken & theToken);
	EXPORT	OTToken *    Pop (OTNym_or_SymmetricKey theOwner); // Caller IS responsible to delete. (Peek 
	EXPORT	OTToken *    Peek(OTNym_or_SymmetricKey theOwner) const; // Caller IS responsible to delete. (Peek returns a copy of the token.)
	// ----------------------------------------------
	EXPORT	int			 Count() const;
	EXPORT	bool		 IsEmpty() const;
	// ----------------------------------------------
	inline long	GetTotalValue() const { return m_lTotalValue; }
	// ----------------------------------------------
	EXPORT	bool Merge(const OTPseudonym     & theSigner,
		OTNym_or_SymmetricKey   theOldNym,
		OTNym_or_SymmetricKey   theNewNym, OTPurse & theNewPurse);

	// ----------------------------------------------
	EXPORT	OTPurse(const OTPurse & thePurse); // just for copy another purse's Server and Asset ID
	EXPORT	OTPurse(const OTIdentifier & SERVER_ID, const OTIdentifier & ASSET_ID); // similar thing
	EXPORT	OTPurse(const OTIdentifier & SERVER_ID); // Don't use this unless you really don't know the asset type
	// (Like if you're about to read it out of a string.)
	// Normally you really really want to set the asset type.
	EXPORT	OTPurse(const OTIdentifier & SERVER_ID, const OTIdentifier & ASSET_ID, const OTIdentifier & USER_ID); // UserID optional
	EXPORT	virtual ~OTPurse();
	// ----------------------------------------------

	EXPORT	bool LoadPurse(const char * szServerID=NULL, const char * szUserID=NULL, const char * szAssetTypeID=NULL);
	EXPORT	bool SavePurse(const char * szServerID=NULL, const char * szUserID=NULL, const char * szAssetTypeID=NULL);

	virtual bool LoadContract();

	inline const OTIdentifier & GetServerID() const { return m_ServerID; }
	inline const OTIdentifier & GetAssetID () const { return m_AssetID;  }

	// ----------------------------------------------
	EXPORT	void InitPurse();
	virtual void Release();
	EXPORT	void Release_Purse();
	EXPORT	void ReleaseTokens();

	virtual bool SaveContractWallet(std::ofstream & ofs);
	//	virtual bool SaveContractWallet(FILE * fl);	
};


#endif // __OTPURSE_H__

