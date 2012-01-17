/************************************************************************************
 *    
 *  OTWallet.h
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

#ifndef __OTWALLET_H__
#define __OTWALLET_H__

#include <string>
#include <map>

#include "OTPseudonym.h"
#include "OTContract.h"
#include "OTAssetContract.h"
#include "OTServerContract.h"
#include "OTAccount.h"


class OTMessage;
class OTPurse;
class OTString;

//typedef std::map<std::string, OTPseudonym *>		mapOfNyms; // in OTContract.h now.
typedef std::map<std::string, OTServerContract *>	mapOfServers;

class OTWallet
{
private:
	mapOfNyms		m_mapNyms;
	mapOfContracts	m_mapContracts;
	mapOfServers	m_mapServers;
	mapOfAccounts	m_mapAccounts;

	OTString m_strName;
	OTString m_strVersion;
	
	OTPurse	*	m_pWithdrawalPurse; // While waiting on server response to withdrawal, store private coin data here for unblinding
public:
	OTString m_strFilename;
	
	OTWallet();
	virtual ~OTWallet();
	void Release();
	//------------------------------------------------------------	

	OTPseudonym * GetOrLoadNym(const OTIdentifier & NYM_ID, const char * szFuncName=NULL);
	OTPseudonym * GetOrLoadPublicNym(const OTIdentifier & NYM_ID, const char * szFuncName=NULL);
	OTPseudonym * GetOrLoadPrivateNym(const OTIdentifier & NYM_ID, const char * szFuncName=NULL);
	
	OTAccount	* LoadAccount(OTPseudonym & theNym, 
							  const OTIdentifier & ACCT_ID, 
							  const OTIdentifier & SERVER_ID, const char * szFuncName=NULL);
	OTAccount	* GetOrLoadAccount(OTPseudonym & theNym, 
								   const OTIdentifier & ACCT_ID, 
								   const OTIdentifier & SERVER_ID, const char * szFuncName=NULL);
	//------------------------------------------------------------	
	// Used by high-level wrapper.
	
	int GetNymCount(); 
	int GetServerCount();
	int GetAssetTypeCount(); 
	int GetAccountCount(); 

	bool GetNym			(const int iIndex, OTIdentifier & NYM_ID, OTString & NYM_NAME);
	bool GetServer		(const int iIndex, OTIdentifier & THE_ID, OTString & THE_NAME);
	bool GetAssetType	(const int iIndex, OTIdentifier & THE_ID, OTString & THE_NAME);
	bool GetAccount		(const int iIndex, OTIdentifier & THE_ID, OTString & THE_NAME);
	//------------------------------------------------------------
	
	void DisplayStatistics(OTString & strOutput);
	
	OTPseudonym *		GetNymByID(const OTIdentifier & NYM_ID);
	OTPseudonym *		GetNymByIDPartialMatch(const std::string PARTIAL_ID);
	
	void				AddServerContract(const OTServerContract & theContract);
	OTServerContract *	GetServerContract(const OTIdentifier & SERVER_ID);
	OTServerContract *	GetServerContractPartialMatch(const std::string PARTIAL_ID);
	
	void				AddNym			(const OTPseudonym & theNym);
	void				AddAccount		(const OTAccount & theAcct);
	
	void				AddAssetContract(const OTAssetContract & theContract);
	OTAssetContract *	GetAssetContract(const OTIdentifier & theContractID);
	OTAssetContract *	GetAssetContractPartialMatch(const std::string PARTIAL_ID);	
	// --------------------------------------------------------
	bool VerifyAssetAccount(OTPseudonym & theNym, 
							OTAccount & theAcct, 
							const OTIdentifier & SERVER_ID,
							const OTString & strAcctID,
							const char * szFuncName =NULL);	
	// --------------------------------------------------------
	OTAccount * GetAccount(const OTIdentifier & theAccountID);
	OTAccount * GetAccountPartialMatch(const std::string PARTIAL_ID);

	// While waiting on server response to a withdrawal, we keep the private coin
	// data here so we can unblind the response.
	// This information is so important (as important as the digital cash token
	// itself, until the unblinding is done) that we need to save the file right away.
	void AddPendingWithdrawal(const OTPurse & thePurse);
	void RemovePendingWithdrawal();
	inline OTPurse * GetPendingWithdrawal() const { return m_pWithdrawalPurse; }
	
	bool LoadWallet(const char * szFilename);
	bool SaveWallet(const char * szFilename=NULL);
	bool SaveContract(OTString & strContract); // For saving the wallet to a string.

	bool SignContractWithFirstNymOnList(OTContract & theContract);
	
	// ----------------------------------------------------
	
	
	// These functions are low-level. They don't check for dependent data before deleting,
	// and they don't save the wallet after they do.
	//
	// (You have to handle that at a higher level.)
	
	bool RemoveAssetContract(const OTIdentifier & theTargetID);
	bool RemoveServerContract(const OTIdentifier & theTargetID);
	
	// higher level version of these two will require a server message, 
	// in addition to removing from wallet. (To delete them on server side.)
	//
	bool RemoveAccount(const OTIdentifier & theTargetID);
	bool RemoveNym(const OTIdentifier & theTargetID);
};

#endif // __OTWALLET_H__


