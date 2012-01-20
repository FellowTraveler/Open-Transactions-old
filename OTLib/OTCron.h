/************************************************************************************
 *    
 *  OTCron.h
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


// OTCron has a list of OTCronItems. (Really subclasses of that such as OTTrade and OTAgreement.)

#ifndef __OTCRON_H__
#define __OTCRON_H__

#include <map>
#include <list>

#include "OTIdentifier.h"
#include "OTContract.h"
#include "OTCronItem.h"
#include "OTLog.h"

class OTCronItem;
class OTPseudonym;
class OTMarket;



// Mapped (uniquely) to transaction number.
typedef std::map  <long, OTCronItem *>	mapOfCronItems;

// Mapped (uniquely) to market ID.
typedef std::map  <std::string, OTMarket *>	mapOfMarkets;


// Cron stores a bunch of these on this list, 
// which the server refreshes from time to time.
typedef std::list<long> listOfTransactionNumbers;



class OTCron : public OTContract
{
private:
	mapOfMarkets	m_mapMarkets;	// A list of all valid markets.
	mapOfCronItems	m_mapCronItems;
	OTIdentifier	m_SERVER_ID;	// Always store this in any object that's associated with a specific server.

	OTPseudonym *	m_pServerNym;	// I'll need this for later.
	
	listOfTransactionNumbers	m_listTransactionNumbers; // I can't put receipts in people's inboxes without a supply of these.
   
	bool			m_bIsActivated; // I don't want to start Cron processing until everything else is all loaded up and ready to go.
	
	
	// ---------------------------------------
	static int			__trans_refill_amount;		// The number of transaction numbers Cron will grab for itself, when it gets low, before each round.
	static int			__cron_ms_between_process;	// The number of milliseconds (ideally) between each "Cron Process" event.
	
public:
	static int		GetCronMsBetweenProcess() { return __cron_ms_between_process; }
	static void		SetCronMsBetweenProcess(long lMS) { __cron_ms_between_process = lMS; }
	
	static int		GetCronRefillAmount() { return __trans_refill_amount; }
	static void		SetCronRefillAmount(int nAmount) { __trans_refill_amount = nAmount; }
	
	// ---------------------------------------
	inline bool		IsActivated() const { return m_bIsActivated; }
	inline bool		ActivateCron() { if (!m_bIsActivated) return m_bIsActivated = true; else return false; }
	bool			AddCronItem(OTCronItem & theItem, OTPseudonym * pActivator=NULL, bool bSaveReceipt=true);
	bool			RemoveCronItem(long lTransactionNum, OTPseudonym & theRemover); // if returns false, CronItem wasn't found.
	OTCronItem *	GetCronItem(long lTransactionNum);

	bool AddMarket(OTMarket & theMarket, bool bSaveMarketFile=true);
	bool RemoveMarket(const OTIdentifier & MARKET_ID); // if returns false, market wasn't found.
	OTMarket * GetMarket(const OTIdentifier & MARKET_ID);
	OTMarket * GetOrCreateMarket(const OTIdentifier & ASSET_ID, 
								 const OTIdentifier & CURRENCY_ID, const long & lScale);
	
	
	// This is informational only. It returns OTStorage-type data objects, packed in a string.
	//
	bool GetMarketList(OTASCIIArmor & ascOutput, int & nMarketCount);
	bool GetNym_OfferList(OTASCIIArmor & ascOutput, const OTIdentifier & NYM_ID, int & nOfferCount);
	
	// The server starts out putting a bunch of numbers in here so Cron can use them.
	// Then the internal trades and payment plans get numbers from here as needed.
	// Server MUST replenish from time-to-time, or Cron will stop working.
	// Part of using Cron properly is to call ProcessCron() regularly, as well
	// as to call AddTransactionNumber() regularly, in order to keep GetTransactionCount()
	// at some minimum threshold.
	void	AddTransactionNumber(const long & lTransactionNum);
	long	GetNextTransactionNumber();
	int		GetTransactionCount() const; // How many numbers do I currently have on the list?

	// Make sure every time you call this, you check the GetTransactionCount() first and replenish it
	// to whatever your minimum supply is. (The transaction numbers in there must be enough to last for
	// the entire ProcessCronItems() call, and all the trades and payment plans within, since it will not
	// be replenished again at least until the call has finished.) 
	void	ProcessCronItems();
	
	inline void SetServerID(const OTIdentifier & SERVER_ID)	{ m_SERVER_ID = SERVER_ID; }
	inline const OTIdentifier & GetServerID()	const		{ return m_SERVER_ID; }	

	inline void SetServerNym(OTPseudonym * pServerNym) { OT_ASSERT(NULL != pServerNym); m_pServerNym = pServerNym; }
	inline OTPseudonym * GetServerNym() const { return m_pServerNym; }
	
	// -----------------------------------------------------
	
	bool LoadCron();
	bool SaveCron();
	
	// -----------------------------------------------------
	
	OTCron();
	OTCron(const OTIdentifier & SERVER_ID);
	OTCron(const char * szFilename);
	virtual ~OTCron();
	
	
	void InitCron();
	
	virtual void Release();
	
	// return -1 if error, 0 if nothing, and 1 if the node was processed.
	virtual int ProcessXMLNode(irr::io::IrrXMLReader*& xml);
	
	virtual void UpdateContents(); // Before transmission or serialization, this is where the ledger saves its contents 
	
	virtual bool SaveContractWallet(std::ofstream & ofs);
	
};





#endif // __OTCRON_H__

