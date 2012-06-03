/*************************************************************
 *    
 *  OTPseudonym.h
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


#ifndef __OTPSEUDONYM_H__
#define __OTPSEUDONYM_H__

// DLL Export for Win32

#undef EXPORT
#ifdef _WINDLL
  #define EXPORT __declspec(dllexport)
#else
  #define EXPORT
#endif

#include <cstdio>


#include <map>
#include <deque>
#include <string>
#include <fstream>
#include <set>


extern "C"
{
#include <openssl/pem.h>
#include <openssl/evp.h>
#include <openssl/x509v3.h>
}


#include "OTString.h"
#include "OTData.h"
#include "OTIdentifier.h"

#include "OTASCIIArmor.h"
#include "OTAsymmetricKey.h"

/*
 
 I need to map transaction server ID, each for a pointer to deque of long.
 

 */

class OTItem;
class OTTransaction;
class OTLedger;
class OTMessage;

class OTPasswordData;


typedef std::deque<OTMessage *>                     dequeOfMail;

typedef std::map<std::string, long>                 mapOfRequestNums;
typedef std::map<std::string, long>                 mapOfHighestNums;

typedef std::deque<long>							dequeOfTransNums;

typedef std::map<std::string, dequeOfTransNums *>	mapOfTransNums;

typedef std::map<std::string, OTIdentifier>         mapOfIdentifiers;

typedef std::set<OTIdentifier>                      setOfIdentifiers;



class OTPseudonym
{
private:
    bool        m_bMarkForDeletion; // Default FALSE. When set to true, saves a "DELETED" flag with this Nym, 
                                    // for easy cleanup later when the server is doing some maintenance.
	OTString		m_strName;      // Used by the wallet so the nym is easily identified by the user
									// The internals, and server, prefer nymID to name.	
	OTString		m_strNymfile;   // This contains the request numbers and other user acct info. XML.
									// Client-side only, since the server uses nymID for filenames
	OTString		m_strCertfile;  // Filename for pem file that contains the x509 Certificate. ----BEGIN etc...
									// Client-side only for now.

	OTString		m_strVersion;   // This goes with the Nymfile
	
	OTASCIIArmor	m_ascCert;		// Just the ascii-armor portion without BEGIN and END
	
    // ----------------------------------------------------
	OTIdentifier        m_nymID;            // Hashed-ID formed by hashing the Nym's public key.
	OTIdentifier        m_NymboxHash;       // (Server-side) Hash of the Nymbox
    
    mapOfIdentifiers    m_mapNymboxHash;    // (Client-side) Hash of latest DOWNLOADED Nymbox (OTIdentifier) mapped by ServerID (std::string)
    mapOfIdentifiers    m_mapRecentHash;    // (Client-side) Hash of Nymbox according to Server, based on some recent reply. (May be newer...)
    // ----------------------------------------------------
    mapOfIdentifiers    m_mapInboxHash;    // Whenever client downloads Inbox, its hash is stored here. (When downloading account, can compare ITS inbox hash to this one, to see if I already have latest one.)
    mapOfIdentifiers    m_mapOutboxHash;  // Whenever client downloads Outbox, its hash is stored here. (When downloading account, can compare ITS outbox hash to this one, to see if I already have latest one.)
    // ----------------------------------------------------
    
	OTAsymmetricKey *m_pkeyPublic;	// This nym's public key
	OTAsymmetricKey *m_pkeyPrivate;	// This nym's private key

    // NOTE: these dequeOfMail objects are only currently stored in the Nym for convenience.
    // They don't have to be stored in here.
    //
	dequeOfMail		m_dequeMail;	// Any mail messages received by this Nym. (And not yet deleted.)
	dequeOfMail		m_dequeOutmail;	// Any mail messages sent by this Nym. (And not yet deleted.)
	dequeOfMail		m_dequeOutpayments;	// Any outoing payments sent by this Nym. (And not yet deleted.) (payments screen.)
    
    // -----------------------------------------------
    
	mapOfRequestNums m_mapRequestNum;	// Whenever this user makes a request to a transaction server
										// he must use the latest request number. Each user has a request
										// number for EACH transaction server he accesses.
	
	mapOfTransNums	m_mapTransNum;	// Each Transaction Request must be accompanied by a fresh transaction #,
									// one that has previously been issued to the Nym by the Server. This list
									// is used so that I know WHICH transaction numbers I still have to USE.
	
	mapOfTransNums	m_mapIssuedNum;	// If the server has issued me (1,2,3,4,5) and I have already used 1-3,
									// then (4,5) are the only remaining numbers on the ABOVE list, but the
									// entire (1,2,3,4,5) are still on THIS list--each only to be removed 
									// when I have ACCEPTED THE RECEIPT IN MY NYMBOX FOR EACH ONE. This list
									// is so I can do agreements with the server concerning which RECEIPTS I'VE ACCEPTED.
	
	// When I accept a transaction number, I put it on this list. Then when I receive the server reply, I add the # to the
	// actual lists (m_maps TransNum and IssuedNum) and remove it from this list. If it's NOT on this list when I receive
	// the server reply, then the server is trying to trick me! into accepting a number I never asked to sign for. The real
	// reason I added this member was so the server could drop notices into my Nymbox about these new transaction numbers
	// (for cases where the actual network message was lost, the server reply, I realized a good backup plan is to have the
	// server always drop notices into your nymbox as well, so you won't get out of sync, since the notice is there even if
	// the network fails before you get the server's reply. I think this is also a GREAT backup plan for withdrawing CASH
	mapOfTransNums	m_mapTentativeNum; 
	
	// We store the highest transaction number accepted for any given server, and we refuse, in the future, to accept anything lower.
	// This prevents a sneaky server from sending you an old number, getting you to sign it out again, then then using that to run 
	// through an old instrument (such as a cheque) that still has your old (valid) signature on it.
    mapOfHighestNums m_mapHighTransNo;  // Mapped, a single long to each server (just like request numbers are.)
	// -----------------------------
    
    // Although it says "mapOfTransNums", in this case, request numbers are stored. I used mapOfTransNums and its associated
    // generic manipulation functions, since they already existed. The AcknowledgedNums are for optimization only, as they enable
    // us to avoid downloading many Box Receipts we'd other have to download. (Specifically, replyNotices, which are referenced
    // by their request number.)
    //
    mapOfTransNums	m_mapAcknowledgedNum; 

	// -----------------------------

    // (SERVER side)
    std::set<long> m_setOpenCronItems; // Until these Cron Items are closed out, the server-side Nym keeps a list of them handy.
    
    // (SERVER side)
    // Using strings here to avoid juggling memory crap.
    std::set<std::string> m_setAccounts; // A list of asset account IDs. Server side only (client side uses wallet; has multiple servers.)
    // ------------------------------------------
    // (SERVER side.)
	long	m_lUsageCredits;	// Server-side. The usage credits available for this Nym. Infinite if negative.
	
public:
	// ------------------------------------------------
EXPORT    bool            GetNymboxHashServerSide(const OTIdentifier & theServerID, OTIdentifier & theOutput);    // server-side
EXPORT    void            SetNymboxHashServerSide(const OTIdentifier & theInput); // server-side    
private:
	// ------------------------------------------------
    // Generic function used by the below functions.
    bool            GetHash(const mapOfIdentifiers & the_map, const std::string & str_id, OTIdentifier & theOutput) const;   // client-side	
    bool            SetHash(mapOfIdentifiers & the_map, const std::string & str_id, const OTIdentifier & theInput);    // client-side
	// ------------------------------------------------
//	OTIdentifier        m_NymboxHash;       // (Server-side) Hash of the Nymbox
//  mapOfIdentifiers    m_mapNymboxHash;    // (Client-side) Hash of Nymbox (OTIdentifier) mapped by ServerID (std::string)
public:
	// ------------------------------------------------
    // This value is only updated on client side, when the actual latest
    // nymbox has been downloaded.
EXPORT    bool            GetNymboxHash(const std::string & server_id,       OTIdentifier & theOutput) const;   // client-side
EXPORT    bool            SetNymboxHash(const std::string & server_id, const OTIdentifier & theInput);    // client-side
	// ------------------------------------------------
    // Whereas THIS value is updated when various server replies are received.
    // (So we can see the most recent version of the same hash on server side.)
    // If this doesn't match the hash above, then it's time to download your nymbox
    // because it's old.
EXPORT    bool            GetRecentHash(const std::string & server_id, OTIdentifier & theOutput) const;   // client-side	
EXPORT    bool            SetRecentHash(const std::string & server_id, const OTIdentifier & theInput);    // client-side
	// ------------------------------------------------
    // This functions are for the latest downloaded inbox's hash.
    // (If the hash that appears in the account is different, then
    // your inbox is old -- download it again.)
    //
    // This saves you having to download it many times when it has not even changed.
    //
EXPORT    bool            GetInboxHash(const std::string & acct_id, OTIdentifier & theOutput) const;   // client-side	
EXPORT    bool            SetInboxHash(const std::string & acct_id, const OTIdentifier & theInput);    // client-side
	// ------------------------------------------------
    // This functions are for the latest downloaded outbox's hash.
    // (If the hash that appears in the account is different, then
    // your outbox is old -- download it again.)
    //
    // This saves you having to download it many times when it has not even changed.
    //
EXPORT    bool            GetOutboxHash(const std::string & acct_id, OTIdentifier & theOutput) const;   // client-side	
EXPORT    bool            SetOutboxHash(const std::string & acct_id, const OTIdentifier & theInput);    // client-side
	// ------------------------------------------------
    
	const long & GetUsageCredits() const { return m_lUsageCredits; } 
	void SetUsageCredits(const long & lUsage) { m_lUsageCredits = lUsage; }
	
	// ------------------------------------------------
	
    inline void MarkForDeletion() { m_bMarkForDeletion = true; }
    inline bool IsMarkedForDeletion() const { return m_bMarkForDeletion; }
    inline void MarkAsUndeleted() { m_bMarkForDeletion = false; }
    
    // Server-side. Helps the server keep track of the accounts for a certain Nym, and the cron items.
    inline std::set<long> &         GetSetOpenCronItems() { return m_setOpenCronItems; }
    inline std::set<std::string> &  GetSetAssetAccounts() { return m_setAccounts; } // stores acct IDs as std::string
    
	// ------------------------------------------------
	
	inline OTString &	GetNymName() { return m_strName; }
	inline void			SetNymName(const OTString & strName) { m_strName = strName; }
	// ------------------------------------------------
	
    // Old style: the user enters a passphrase for using the Nym.
    // New style: the user enters a passphrase which is used to derive a key,
    // which is used to decrypt the master key, which is used for using the Nym.
    // To convert an "old style" Nym to a "new style" Nym, just call this function
    // after loading "old style" and it will save in the "new style."
    // THIS WILL OVERWRITE THE CERT (with the new master key passphrase.) meaning
    // that you will no longer be able to use the Nym OUTSIDE of OT, since OpenSSL
    // will be expecting the master key, not the user's actual passphrase.
    //
    // THEREFORE: Nyms will be "imported" into the master key mode, and then if you want
    // to use them outside of your wallet, you will have to "export" the Nym, which will 
    // have to call a function that reverses the one below. (ConvertBackOutOfMasterKey or
    // some such thing.)
    //

//EXPORT    bool ConvertToMasterKey();  // Replaced by Savex509CertAndPrivateKey().
    
	// ------------------------------------------------
EXPORT	OTPseudonym();
EXPORT	OTPseudonym(const OTIdentifier & nymID);
EXPORT	OTPseudonym(const OTString & strNymID);
	OTPseudonym(const OTString & name, const OTString & filename, const OTString & nymID);
EXPORT	virtual ~OTPseudonym();
	
	void Initialize();
	void ReleaseTransactionNumbers();
	// ------------------------------------------------
	
EXPORT	bool VerifyPseudonym() const;

	
	// use this to actually generate a new key pair and assorted nym files.
	//
EXPORT	bool GenerateNym(int nBits=1024, bool bCreateFile=true);

	// ---------------------------------------------
	
	// Some messages require "transaction agreement" as opposed to "balance agreement."
	// That is, cases where only transactions change and not balances.
	//
	
EXPORT	OTItem * GenerateTransactionStatement(const OTTransaction & theOwner); // like balance agreement

	// ---------------------------------------------
		
	// This version WILL handle the bookends -----BEGIN PUBLIC KEY------ 
EXPORT	bool SetPublicKey(const OTString & strKey, bool bEscaped=true);
	
	// This version WILL handle the bookends: -----BEGIN CERTIFICATE------ 
	// It also handles the escaped version:   - -----BEGIN CERTIFICATE-----
	bool SetCertificate(const OTString & strCert, bool bEscaped=true);
	
	// This will set the public key on this Nym based on the public key as it
    // appears in an ascii-armored string.
	bool SetPublicKey(const OTASCIIArmor & strKey);	
	
	// ---------------------------------------------
    
	// This version WILL handle the bookends -----BEGIN ENCRYPTED PRIVATE KEY------ 
	bool SetPrivateKey(const OTString & strKey, bool bEscaped=true);
	
	// This will set the private key on this Nym based on the private key as it
    // appears in an ascii-armored string.
	bool SetPrivateKey(const OTASCIIArmor & strKey);	
	
	// ------------------------------------------
	
	// CALLER is responsible to delete the Nym ptr being returned
	// in these functions!
	//
EXPORT	static OTPseudonym * LoadPublicNym(const OTIdentifier & NYM_ID, OTString * pstrName=NULL, 
                                       const char * szFuncName=NULL);
EXPORT	static OTPseudonym * LoadPrivateNym(const OTIdentifier & NYM_ID, OTString * pstrName=NULL, 
                                        const char * szFuncName=NULL);

	// ------------------------------------------

	bool HasPublicKey();
	bool HasPrivateKey();
	
	// The signer is whoever wanted to make sure these nym files haven't changed.
	// Usually that means the server nym.  Most of the time, m_nymServer will be used as signer.
EXPORT	bool LoadSignedNymfile(OTPseudonym & SIGNER_NYM);
EXPORT	bool SaveSignedNymfile(OTPseudonym & SIGNER_NYM);
	
	bool LoadNymfile(const char * szFilename=NULL);
EXPORT	bool LoadFromString(const OTString & strNym);

EXPORT	bool LoadPublicKey();
EXPORT	bool Loadx509CertAndPrivateKey();
EXPORT	bool Savex509CertAndPrivateKey(bool bCreateFile=true);
    
//	bool SavePseudonymWallet(FILE * fl) const;
	bool SavePseudonymWallet(OTString & strOutput) const;
	bool SavePseudonymWallet(std::ofstream & ofs) const;

EXPORT	bool SavePublicKey(const OTString & strPath) const;
//	bool SavePublicKey(FILE * fl) const;
	bool SavePublicKey(std::ofstream & ofs) const;

	bool SavePseudonym(); // saves to filename m_strNymfile
	bool SavePseudonym(const char * szFoldername, const char * szFilename);
EXPORT	bool SavePseudonym(OTString & strNym);
//	bool SavePseudonym(FILE * fl);
	bool SavePseudonym(std::ofstream & ofs);

	bool SetIdentifierByPubkey();
	
    bool CompareID(const OTIdentifier & theIdentifier) const 
	{ return (theIdentifier == m_nymID); }
	
EXPORT    bool CompareID(const OTPseudonym & RHS) const;
    
	const OTIdentifier & GetConstID() const { return m_nymID; }
	
EXPORT	void GetIdentifier(OTIdentifier & theIdentifier) const;
EXPORT	void SetIdentifier(const OTIdentifier & theIdentifier);
	
EXPORT	void GetIdentifier(OTString & theIdentifier) const;
EXPORT	void SetIdentifier(const OTString & theIdentifier);

    // --------------------------------------------
    
EXPORT	void HarvestTransactionNumbers(const OTIdentifier & theServerID, OTPseudonym & SIGNER_NYM,
                                   OTPseudonym & theOtherNym, // OtherNym is used as a container for the server to send
                                   bool bSave=true);          // us new transaction numbers.
    
EXPORT	void HarvestIssuedNumbers(const OTIdentifier & theServerID, OTPseudonym & SIGNER_NYM,
                              OTPseudonym & theOtherNym, // OtherNym is used as container for us to send a list
                              bool bSave=false);         // of issued numbers to the server (for balance agreement)

    
    bool ClawbackTransactionNumber(const OTIdentifier & theServerID,
                                   const long & lTransClawback, // the number being clawed back.
                                   bool bSave=false,
                                   OTPseudonym * pSIGNER_NYM=NULL);
    
	// ---------------------------------------------
    
EXPORT    void IncrementRequestNum(OTPseudonym & SIGNER_NYM, const OTString & strServerID); // Increment the counter or create a new one for this serverID starting at 1
EXPORT	void OnUpdateRequestNum(OTPseudonym & SIGNER_NYM, const OTString & strServerID, long lNewRequestNumber); // if the server sends us a @getRequest
EXPORT	bool GetCurrentRequestNum(const OTString & strServerID, long &lReqNum); // get the current request number for the serverID
	
EXPORT	bool GetHighestNum(const OTString & strServerID, long &lHighestNum); // get the last/current highest transaction number for the serverID.
	long UpdateHighestNum(OTPseudonym & SIGNER_NYM, 
                          const OTString & strServerID, 
                          std::set<long> & setNumbers, 
                          std::set<long> & setOutputGood,
                          std::set<long> & setOutputBad, bool bSave=false); // Returns 0 if success, otherwise # of the violator.

	inline mapOfTransNums & GetMapTransNum()        { return m_mapTransNum;         }
	inline mapOfTransNums & GetMapIssuedNum()       { return m_mapIssuedNum;        }
	inline mapOfTransNums & GetMapTentativeNum()    { return m_mapTentativeNum;     }
	inline mapOfTransNums & GetMapAcknowledgedNum() { return m_mapAcknowledgedNum;  } // This one actually stores request numbers.

	void RemoveAllNumbers(const OTString * pstrServerID=NULL, const bool bRemoveHighestNum=true); // for transaction numbers
	void RemoveReqNumbers(const OTString * pstrServerID=NULL); // for request numbers (entirely different animal)
	// -----------------------------------------------------
	
EXPORT	bool	UnRegisterAtServer(const OTString & strServerID); // Removes the request num for a specific server, if it was there before.
EXPORT	bool	IsRegisteredAtServer(const OTString & strServerID); // You can't go using a Nym at a certain server, if it's not registered there...

	// -----------------------------------------------------
	//
	// ** ResyncWithServer **
	//
	// Not for normal use! (Since you should never get out of sync with the server in the first place.)
	// However, in testing, or if some bug messes up some data, or whatever, and you absolutely need to
	// re-sync with a server, and you trust that server not to lie to you, then this function will do the trick.
	// NOTE: Before calling this, you need to do a getNymbox() to download the latest Nymbox, and you need to do
	// a createUserAccount() to download the server's copy of your Nym. You then need to load that Nymbox from
	// local storage, and you need to load the server's message Nym out of the @createUserAccount reply, so that
	// you can pass both of those objects into this function, which must assume that those pieces were already done
	// just prior to this call.
EXPORT	bool	ResyncWithServer(OTLedger & theNymbox, OTPseudonym & theMessageNym);
	
	// -----------------------------------------------------
	// HIGH LEVEL:
EXPORT	bool	AddTransactionNum(OTPseudonym & SIGNER_NYM, const OTString & strServerID, long lTransNum, bool bSave); // We have received a new trans num from server. Store it.
EXPORT	bool	GetNextTransactionNum(OTPseudonym & SIGNER_NYM, const OTString & strServerID, long &lTransNum,
                                  bool bSave=true); // Get the next available transaction number for the serverID passed. Saves by default.
    // --------------------
EXPORT	bool	RemoveIssuedNum      (OTPseudonym & SIGNER_NYM, const OTString & strServerID, const long & lTransNum,   bool bSave); // SAVE OR NOT (your choice)
	bool	RemoveTentativeNum   (OTPseudonym & SIGNER_NYM, const OTString & strServerID, const long & lTransNum,   bool bSave);
EXPORT	bool	RemoveAcknowledgedNum(OTPseudonym & SIGNER_NYM, const OTString & strServerID, const long & lRequestNum, bool bSave); // Used on both client and server sides for optimization.
    // --------------------	
EXPORT	bool	VerifyIssuedNum      (const OTString & strServerID, const long & lTransNum);   // verify user is still responsible for (signed for) a certain trans# that was previous issued to him. (i.e. it's been used, but not yet accepted receipt through inbox.)
EXPORT	bool	VerifyTransactionNum (const OTString & strServerID, const long & lTransNum);   // server verifies that nym has this TransNum available for use.
EXPORT	bool	VerifyTentativeNum   (const OTString & strServerID, const long & lTransNum);   // Client-side verifies that it actually tried to sign for this number (so it knows if the reply is valid.)
EXPORT	bool	VerifyAcknowledgedNum(const OTString & strServerID, const long & lRequestNum); // Client verifies it has already seen a server reply. Server acknowledges client has seen reply (so client can remove from list, so server can as well.)
    // --------------------

	// These two functions are for when you re-download your nym/account/inbox/outbox, and you
	// need to verify it against the last signed receipt to make sure you aren't getting screwed.
    //
	bool VerifyIssuedNumbersOnNym(OTPseudonym & THE_NYM);
	bool VerifyTransactionStatementNumbersOnNym(OTPseudonym & THE_NYM);

	// -------------------------------------
	// These functions are for transaction numbers that were assigned to me, 
	// until I accept the receipts or put stop payment onto them.
    //
EXPORT	int		GetIssuedNumCount(const OTIdentifier & theServerID); // count
EXPORT	long	GetIssuedNum(const OTIdentifier & theServerID, int nIndex); // index
	
EXPORT	bool	AddIssuedNum(const OTString & strServerID, const long & lTransNum); // doesn't save
	
	bool	RemoveIssuedNum(OTPseudonym & SIGNER_NYM, const OTString & strServerID, const long & lTransNum); // saves
EXPORT	bool	RemoveIssuedNum(const OTString & strServerID, const long & lTransNum); // doesn't save

	// -------------------------------------
	// These functions are for transaction numbers that I still have available to use.
	//
EXPORT	int GetTransactionNumCount(const OTIdentifier & theServerID); // count
EXPORT	long GetTransactionNum(const OTIdentifier & theServerID, int nIndex); // index
	
	bool AddTransactionNum(const OTString & strServerID, const long lTransNum); // doesn't save
	
EXPORT	bool RemoveTransactionNum(OTPseudonym & SIGNER_NYM, const OTString & strServerID, const long & lTransNum); // server removes spent number from nym file. Saves.
EXPORT	bool RemoveTransactionNum(const OTString & strServerID, const long & lTransNum); // doesn't save.
	
	// -------------------------------------
	// These functions are for tentative transaction numbers that I am trying to sign for.
	// They are in my Nymbox. I sign to accept them, and then store them here. The server 
	// replies with success, and then I remove them from this list, and move them onto the
	// two lists above. For good measure, the server also puts a success note into my Nymbox,
	// so if the network transport is lost, I will still have the chance to get my Nymbox,
	// and see the notices. By this time, the numbers are DEFNITELY ALREADY CONFIRMED, and
	// the notices can simply be discarded if the numbers aren't on list "Tentative" list.
	// That means they already went through, and were already removed from this list as
	// described higher in this paragraph. HOWEVER, if I somehow lost the message (the 
	// original server success reply when I signed for the numbers) then they will STILL be
	// stuck on this list! The notice gives me a chance to officially move them to the right
	// place. After all, my transactions won't work until I do, because my balance agreements
	// will be wrong.
	//
	int GetTentativeNumCount(const OTIdentifier & theServerID); // count
	long GetTentativeNum(const OTIdentifier & theServerID, int nIndex); // index
	
EXPORT	bool AddTentativeNum(const OTString & strServerID, const long &lTransNum); // doesn't save
	
	bool RemoveTentativeNum(OTPseudonym & SIGNER_NYM, const OTString & strServerID, const long & lTransNum);
EXPORT	bool RemoveTentativeNum(const OTString & strServerID, const long & lTransNum); // doesn't save.
	
	// ---------------------------------------------
	
    // On the client side, whenever the client is DEFINITELY made aware of the existence of a 
    // server reply, he adds its request number to this list, which is sent along with all client-side
    // requests to the server.
    // The server reads the list on the incoming client message (and it uses these same functions
    // to store its own internal list.) If the # already appears on its internal list, then it does
    // nothing. Otherwise, it loads up the Nymbox and removes the replyNotice, and then adds the #
    // to its internal list.
    // For any numbers on the internal list but NOT on the client's list, the server removes from
    // the internal list. (The client removed them when it saw the server's internal list, which the
    // server sends with its replies.)
    //
    // This entire protocol, densely described, is unnecessary for OT to function, but is great for
    // optimization, as it enables OT to avoid downloading all Box Receipts containing replyNotices,
    // as long as the original reply was properly received when the request was originally sent (which
    // is MOST of the time...)
    // Thus we can eliminate most replyNotice downloads, and likely a large % of box receipt downloads
    // as well.
    //
EXPORT	int GetAcknowledgedNumCount(const OTIdentifier & theServerID); // count
EXPORT	long GetAcknowledgedNum(const OTIdentifier & theServerID, int nIndex); // index
	
EXPORT	bool AddAcknowledgedNum(const OTString & strServerID, const long &lRequestNum); // doesn't save
	
	bool RemoveAcknowledgedNum(OTPseudonym & SIGNER_NYM, const OTString & strServerID, const long & lRequestNum);
	bool RemoveAcknowledgedNum(const OTString & strServerID, const long & lRequestNum); // doesn't save.
	
	// ---------------------------------------------
	
	// The "issued" numbers and the "transaction" numbers both use these functions
	// to do the actual work (just avoiding code duplication.) "tentative" as well,
    // and "Acknowledged". (For acknowledged replies.)
    //
	bool VerifyGenericNum(mapOfTransNums & THE_MAP, const OTString & strServerID, const long & lTransNum);
	
	bool RemoveGenericNum(mapOfTransNums & THE_MAP, OTPseudonym & SIGNER_NYM, const OTString & strServerID, const long & lTransNum); // saves
	bool RemoveGenericNum(mapOfTransNums & THE_MAP, const OTString & strServerID, const long & lTransNum); // doesn't save
	
	bool AddGenericNum(mapOfTransNums & THE_MAP, const OTString & strServerID, const long lTransNum); // doesn't save
	
	int  GetGenericNumCount(mapOfTransNums & THE_MAP, const OTIdentifier & theServerID); 
	long GetGenericNum(mapOfTransNums & THE_MAP, const OTIdentifier & theServerID, int nIndex);

	// -------------------------------------
	
	// Whenever a Nym receives a message via his Nymbox, and then the Nymbox is processed, (which happens automatically)
	// that processing will drop all mail messages into this deque for safe-keeping, after Nymbox is cleared.
	//
EXPORT	void		AddMail(OTMessage & theMessage); // a mail message is the original OTMessage from the sender, transported via Nymbox of recipient (me).
EXPORT	int			GetMailCount(); // How many mail messages does this Nym currently store?
EXPORT	OTMessage *	GetMailByIndex(const int nIndex); // Get a specific piece of mail, at a specific index.
EXPORT	bool		RemoveMailByIndex(const int nIndex); // if returns false, mail index was bad (or something else must have gone seriously wrong.)
	
	void		ClearMail(); // called by the destructor. (Not intended to erase messages from local storage.)
	
	// -------------------------------------
	
	// Whenever a Nym sends a message, a copy is dropped into his Outmail.
	//
EXPORT	void		AddOutmail(OTMessage & theMessage); // a mail message is the original OTMessage that this Nym sent.
EXPORT	int			GetOutmailCount(); // How many outmail messages does this Nym currently store?
EXPORT	OTMessage *	GetOutmailByIndex(const int nIndex); // Get a specific piece of outmail, at a specific index.
EXPORT	bool		RemoveOutmailByIndex(const int nIndex); // if returns false, outmail index was bad (or something else must have gone seriously wrong.)
	
	void		ClearOutmail(); // called by the destructor. (Not intended to erase messages from local storage.)
	
	// -------------------------------------
	
	// Whenever a Nym sends a payment, a copy is dropped into his Outpayments. (Payments screen.)
	//
EXPORT	void		AddOutpayments(OTMessage & theMessage); // a payments message is the original OTMessage that this Nym sent.
EXPORT	int			GetOutpaymentsCount(); // How many outpayments messages does this Nym currently store?
EXPORT	OTMessage *	GetOutpaymentsByIndex(const int nIndex); // Get a specific piece of outpayments, at a specific index.
EXPORT	bool		RemoveOutpaymentsByIndex(const int nIndex); // if returns false, outpayments index was bad (or something else must have gone seriously wrong.)
	
	void		ClearOutpayments(); // called by the destructor. (Not intended to erase messages from local storage.)
	
	// -------------------------------------
	
EXPORT	const OTAsymmetricKey & GetPublicKey() const;
	const OTAsymmetricKey & GetPrivateKey() const;
	
	// -------------------------------------
	
EXPORT	void DisplayStatistics(OTString & strOutput);
};

#endif // __OTPSEUDONYM_H__









































