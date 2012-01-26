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

#include <cstdio>


#include <map>
#include <deque>
#include <string>
#include <fstream>
#include <set>

#include "OTString.h"
#include "OTData.h"
#include "OTIdentifier.h"

#include "OTASCIIArmor.h"
#include "OTAsymmetricKey.h"

/*
 
 I need to map transaction server ID, each for a pointer to deque of long.
 

 */

;

class OTItem;
class OTTransaction;
class OTLedger;
class OTMessage;

typedef std::deque<OTMessage *>		dequeOfMail;

typedef std::map<std::string, long>	mapOfRequestNums;
typedef std::map<std::string, long>	mapOfHighestNums;

typedef std::deque<long>							dequeOfTransNums;
typedef std::map<std::string, dequeOfTransNums *>	mapOfTransNums;

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
	
	OTIdentifier	m_nymID;		// hashed public key

	OTAsymmetricKey *m_pkeyPublic;	// This nym's public key
	OTAsymmetricKey *m_pkeyPrivate;	// This nym's private key

	dequeOfMail		m_dequeMail;	// Any mail messages received by this Nym. (And not yet deleted.)
	dequeOfMail		m_dequeOutmail;	// Any mail messages sent by this Nym. (And not yet deleted.)
		
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
	
    std::set<long> m_setOpenCronItems; // Until these Cron Items are closed out, the server-side Nym keeps a list of them handy.
    
    // Using strings here to avoid juggling memory crap.
    std::set<std::string> m_setAccounts; // A list of asset account IDs. Server side only (client side uses wallet; has multiple servers.)
    // ------------------------------------------
	long		m_lUsageCredits;	// Server-side. The usage credits available for this Nym. Infinite if negative.
	
public:
	
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
	
	OTPseudonym();
	OTPseudonym(const OTIdentifier & nymID);
	OTPseudonym(const OTString & strNymID);
	OTPseudonym(const OTString & name, const OTString & filename, const OTString & nymID);
	virtual ~OTPseudonym();
	
	void Initialize();
	void ReleaseTransactionNumbers();
	
	bool VerifyPseudonym() const;

	
	// use this to actually generate a new key pair and assorted nym files.
	//
	bool GenerateNym();

	// ---------------------------------------------
	
	// Some messages require "transaction agreement" as opposed to "balance agreement."
	// That is, cases where only transactions change and not balances.
	//
	
	OTItem * GenerateTransactionStatement(const OTTransaction & theOwner); // like balance agreement

	// ---------------------------------------------
		
	// This version WILL handle the bookends -----BEGIN PUBLIC KEY------ 
	bool SetPublicKey(const OTString & strKey, bool bEscaped=true);
	
	// This version WILL handle the bookends: -----BEGIN CERTIFICATE------ 
	// It also handles the escaped version:   - -----BEGIN CERTIFICATE-----
	bool SetCertificate(const OTString & strCert, bool bEscaped=true);
	
	// This will set the public key on this Nym 
	// based on the public key as it appears in an
	// ascii-armored string.
	bool SetPublicKey(const OTASCIIArmor & strKey);	
	
	// ------------------------------------------
	
	// CALLER is responsible to delete the Nym ptr being returned
	// in these functions!
	//
	static OTPseudonym * LoadPublicNym(const OTIdentifier & NYM_ID, OTString * pstrName=NULL, const char * szFuncName=NULL);
	static OTPseudonym * LoadPrivateNym(const OTIdentifier & NYM_ID, OTString * pstrName=NULL, const char * szFuncName=NULL);

	// ------------------------------------------

	bool HasPublicKey();
	bool HasPrivateKey();
	
	// The signer is whoever wanted to make sure these nym files haven't changed.
	// Usually that means the server nym.  Most of the time, m_nymServer will be used as signer.
	bool LoadSignedNymfile(OTPseudonym & SIGNER_NYM);
	bool SaveSignedNymfile(OTPseudonym & SIGNER_NYM);
	
	bool LoadNymfile(const char * szFilename=NULL);
	bool LoadFromString(const OTString & strNym);

	bool LoadPublicKey();
	bool Loadx509CertAndPrivateKey();
	
//	bool SavePseudonymWallet(FILE * fl) const;
	bool SavePseudonymWallet(OTString & strOutput) const;
	bool SavePseudonymWallet(std::ofstream & ofs) const;

	bool SavePublicKey(const OTString & strPath) const;
//	bool SavePublicKey(FILE * fl) const;
	bool SavePublicKey(std::ofstream & ofs) const;

	bool SavePseudonym(); // saves to filename m_strNymfile
	bool SavePseudonym(const char * szFoldername, const char * szFilename);
	bool SavePseudonym(OTString & strNym);
//	bool SavePseudonym(FILE * fl);
	bool SavePseudonym(std::ofstream & ofs);

	bool SetIdentifierByPubkey();
	
    bool CompareID(const OTIdentifier & theIdentifier) const 
	{ return (theIdentifier == m_nymID); }
	
    bool CompareID(const OTPseudonym & RHS) const;
    
	const OTIdentifier & GetConstID() const { return m_nymID; }
	
	void GetIdentifier(OTIdentifier & theIdentifier) const;
	void SetIdentifier(const OTIdentifier & theIdentifier);
	
	void GetIdentifier(OTString & theIdentifier) const;
	void SetIdentifier(const OTString & theIdentifier);

	void HarvestTransactionNumbers(const OTIdentifier & theServerID, OTPseudonym & SIGNER_NYM, OTPseudonym & theOtherNym, bool bSave=true); // OtherNym is used as container for server to send us new transaction numbers
	void HarvestIssuedNumbers(const OTIdentifier & theServerID, OTPseudonym & SIGNER_NYM, OTPseudonym & theOtherNym, bool bSave=false); // OtherNym is used as container for us to send list of issued numbers to the server (for balance agreement)

	void IncrementRequestNum(OTPseudonym & SIGNER_NYM, const OTString & strServerID); // Increment the counter or create a new one for this serverID starting at 1
	void OnUpdateRequestNum(OTPseudonym & SIGNER_NYM, const OTString & strServerID, long lNewRequestNumber); // if the server sends us a @getRequest
	bool GetCurrentRequestNum(const OTString & strServerID, long &lReqNum); // get the current request number for the serverID
	
	bool GetHighestNum(const OTString & strServerID, long &lHighestNum); // get the last/current highest transaction number for the serverID.
	long UpdateHighestNum(OTPseudonym & SIGNER_NYM, const OTString & strServerID, std::set<long> & setNumbers, bool bSave=false); // Returns 0 if success, otherwise # of the violator.

	inline mapOfTransNums & GetMapTransNum() { return m_mapTransNum; }
	inline mapOfTransNums & GetMapIssuedNum() { return m_mapIssuedNum; }
	inline mapOfTransNums & GetMapTentativeNum() { return m_mapTentativeNum; }

	void RemoveAllNumbers(const OTString * pstrServerID=NULL, const bool bRemoveHighestNum=true); // for transaction numbers
	void RemoveReqNumbers(const OTString * pstrServerID=NULL); // for request numbers (entirely different animal)
	// -----------------------------------------------------
	
	bool	UnRegisterAtServer(const OTString & strServerID); // Removes the request num for a specific server, if it was there before.
	bool	IsRegisteredAtServer(const OTString & strServerID); // You can't go using a Nym at a certain server, if it's not registered there...

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
	bool	ResyncWithServer(OTLedger & theNymbox, OTPseudonym & theMessageNym);
	
	// -----------------------------------------------------
	// HIGH LEVEL:
	bool	AddTransactionNum(OTPseudonym & SIGNER_NYM, const OTString & strServerID, long lTransNum, bool bSave); // We have received a new trans num from server. Store it.
	bool	GetNextTransactionNum(OTPseudonym & SIGNER_NYM, const OTString & strServerID, long &lTransNum,
                                  bool bSave=true); // Get the next available transaction number for the serverID passed. Saves by default.
	bool	RemoveIssuedNum(OTPseudonym & SIGNER_NYM, const OTString & strServerID, const long & lTransNum, bool bSave); // SAVE OR NOT (your choice)

	bool	RemoveTentativeNum(OTPseudonym & SIGNER_NYM, const OTString & strServerID, const long & lTransNum, bool bSave);
	
	bool	VerifyIssuedNum(const OTString & strServerID, const long & lTransNum); // verify user is still responsible for (signed for) a certain trans# that was previous issued to him. (i.e. it's been used, but not yet accepted receipt through inbox.)
	bool	VerifyTransactionNum(const OTString & strServerID, const long & lTransNum); // server verifies that nym has this TransNum available for use.
	bool	VerifyTentativeNum(const OTString & strServerID, const long & lTransNum); // Client-side verifies that it actually tried to sign for this number (so it knows if the reply is valid.)

	// These two functions are for when you re-download your nym/account/inbox/outbox, and you
	// need to verify it against the last signed receipt to make sure you aren't getting screwed.
	bool VerifyIssuedNumbersOnNym(OTPseudonym & THE_NYM);
	bool VerifyTransactionStatementNumbersOnNym(OTPseudonym & THE_NYM);

	// -------------------------------------
	// These functions are for transaction numbers that were assigned to me, 
	// until I accept the receipts or put stop payment onto them.
	int		GetIssuedNumCount(const OTIdentifier & theServerID); // count
	long	GetIssuedNum(const OTIdentifier & theServerID, int nIndex); // index
	
	bool	AddIssuedNum(const OTString & strServerID, const long & lTransNum); // doesn't save
	
	bool	RemoveIssuedNum(OTPseudonym & SIGNER_NYM, const OTString & strServerID, const long & lTransNum); // saves
	bool	RemoveIssuedNum(const OTString & strServerID, const long & lTransNum); // doesn't save

	// -------------------------------------
	// These functions are for transaction numbers that I still have available to use.
	//
	int GetTransactionNumCount(const OTIdentifier & theServerID); // count
	long GetTransactionNum(const OTIdentifier & theServerID, int nIndex); // index
	
	bool AddTransactionNum(const OTString & strServerID, const long lTransNum); // doesn't save
	
	bool RemoveTransactionNum(OTPseudonym & SIGNER_NYM, const OTString & strServerID, const long & lTransNum); // server removes spent number from nym file. Saves.
	bool RemoveTransactionNum(const OTString & strServerID, const long & lTransNum); // doesn't save.
	
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
	
	bool AddTentativeNum(const OTString & strServerID, const long &lTransNum); // doesn't save
	
	bool RemoveTentativeNum(OTPseudonym & SIGNER_NYM, const OTString & strServerID, const long & lTransNum);
	bool RemoveTentativeNum(const OTString & strServerID, const long & lTransNum); // doesn't save.
	
	// ---------------------------------------------
	
	// The "issued" numbers and the "transaction" numbers both use these functions
	// to do the actual work (just avoiding code duplication.)
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
	void		AddMail(OTMessage & theMessage); // a mail message is the original OTMessage from the sender, transported via Nymbox of recipient (me).
	int			GetMailCount(); // How many mail messages does this Nym currently store?
	OTMessage *	GetMailByIndex(const int nIndex); // Get a specific piece of mail, at a specific index.
	bool		RemoveMailByIndex(const int nIndex); // if returns false, mail index was bad (or something else must have gone seriously wrong.)
	
	void		ClearMail(); // called by the destructor. (Not intended to erase messages from local storage.)
	
	// -------------------------------------
	
	// Whenever a Nym sends a message, a copy is dropped into his Outmail.
	//
	void		AddOutmail(OTMessage & theMessage); // a mail message is the original OTMessage that this Nym sent.
	int			GetOutmailCount(); // How many outmail messages does this Nym currently store?
	OTMessage *	GetOutmailByIndex(const int nIndex); // Get a specific piece of outmail, at a specific index.
	bool		RemoveOutmailByIndex(const int nIndex); // if returns false, outmail index was bad (or something else must have gone seriously wrong.)
	
	void		ClearOutmail(); // called by the destructor. (Not intended to erase messages from local storage.)
	
	// -------------------------------------
	
	const OTAsymmetricKey & GetPublicKey() const;
	const OTAsymmetricKey & GetPrivateKey() const;
	
	void DisplayStatistics(OTString & strOutput);
};

#endif // __OTPSEUDONYM_H__









































