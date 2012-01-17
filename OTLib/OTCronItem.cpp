/************************************************************
 *    
 *  OTCronItem.cpp
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



#include <cstring>


#include "irrxml/irrXML.h"

using namespace irr;
using namespace io;

#include "OTStorage.h"


#include "OTPseudonym.h"
#include "OTLedger.h"
#include "OTCronItem.h"
#include "OTAgreement.h"
#include "OTPaymentPlan.h"
#include "OTTrade.h"
#include "OTAccount.h"
#include "OTSmartContract.h"
#include "OTCron.h"
#include "OTLog.h"


// Base class for OTTrade and OTAgreement and OTPaymentPlan.
// OTCron contains lists of these for regular processing.


// static -- class factory.
//
// I just realized, I don't have to use this only for CronItems.
// If I wanted to, I could put ANY Open-Transactions class in here,
// if there was some need for it, and it would work just fine right here.
// Like if I wanted to have different Token types for different cash
// algorithms. All I have to do is change the return type.
//
OTCronItem * OTCronItem::NewCronItem(const OTString & strCronItem)
{
	static char		buf[45] = "";
	OTCronItem *	pItem = NULL;
	
	if (!strCronItem.Exists())
		return NULL;
	
	OTString strContract(strCronItem);
	
	strContract.reset(); // for sgets
	buf[0] = 0; // probably unnecessary.
	bool bGotLine = strContract.sgets(buf, 40);

	if (!bGotLine)
		return NULL;
	
	OTString strFirstLine(buf);
	strContract.reset(); // set the "file" pointer within this string back to index 0.
	
	// Now I feel pretty safe -- the string I'm examining is within
	// the first 45 characters of the beginning of the contract, and
	// it will NOT contain the escape "- " sequence. From there, if
	// it contains the proper sequence, I will instantiate that type.
	if (!strFirstLine.Exists() || strFirstLine.Contains("- -"))
		return NULL;
		
//	if (strFirstLine.Contains("-----BEGIN SIGNED AGREEMENT-----"))  // this string is 32 chars long.
//	{	pItem = new OTAgreement();		OT_ASSERT(NULL != pItem); }
	
	else if (strFirstLine.Contains("-----BEGIN SIGNED PAYMENT PLAN-----"))  // this string is 35 chars long.
	{	pItem = new OTPaymentPlan();	OT_ASSERT(NULL != pItem); }
	
	else if (strFirstLine.Contains("-----BEGIN SIGNED TRADE-----"))  // this string is 28 chars long.
	{	pItem = new OTTrade();			OT_ASSERT(NULL != pItem); }
	
	else if (strFirstLine.Contains("-----BEGIN SIGNED SMARTCONTRACT-----"))  // this string is 36 chars long.
	{	pItem = new OTSmartContract();	OT_ASSERT(NULL != pItem); }
	
	
	// The string didn't match any of the options in the factory.
	if (NULL == pItem)
		return NULL;
	
	// Does the contract successfully load from the string passed in?
	if (pItem->LoadContractFromString(strContract))
		return pItem;
	else
		delete pItem;
	
	
	return NULL;
}




OTCronItem * OTCronItem::LoadCronReceipt(const long & lTransactionNum)
{
	OTString strFilename;
	strFilename.Format("%ld.crn", lTransactionNum);
	
	const char * szFoldername	= OTLog::CronFolder();
	const char * szFilename		= strFilename.Get();
	
	// --------------------------------------------------------------------
	
	if (false == OTDB::Exists(szFoldername, szFilename))
	{
		OTLog::vError("OTCronItem::LoadCronReceipt: File does not exist: %s%s%s\n", 
					  szFoldername, OTLog::PathSeparator(), szFilename);
		return NULL;
	}
	
	// --------------------------------------------------------------------
	//
	OTString strFileContents(OTDB::QueryPlainString(szFoldername, szFilename)); // <=== LOADING FROM DATA STORE.
	
	if (strFileContents.GetLength() < 2)
	{
		OTLog::vError("OTCronItem::LoadCronReceipt: Error reading file: %s%s%s\n", 
					  szFoldername, OTLog::PathSeparator(), szFilename);
		return NULL;
	}
	else
		return OTCronItem::NewCronItem(strFileContents);
}




// When first adding anything to Cron, a copy needs to be saved in a folder somewhere.
// (Just for our records.) For example, before I start updating the status on any Trade,
// I have already saved the user's original Trade object (from his request) to a folder.
// Now I have the freedom to ReleaseSignatures on the Trade and re-sign it with the
// server's Nym as it updates over time.  The user cannot challenge the Trade because
// the server has the original copy on file and sends it with all receipts.

bool OTCronItem::SaveCronReceipt()
{
	OTString strFilename;
	strFilename.Format("%ld.crn", GetTransactionNum());
	
	const char * szFoldername	= OTLog::CronFolder();  // cron
	const char * szFilename		= strFilename.Get();    // cron/TRANSACTION_NUM.crn
	
	// --------------------------------------------------------------------
	
	if (OTDB::Exists(szFoldername, szFilename))
	{
		OTLog::vError("Cron Record exists for transaction %ld %s%s%s,\nyet attempted to record it again.\n",
					  GetTransactionNum(), szFoldername, OTLog::PathSeparator(), szFilename);
		return false;
	}
	
	// --------------------------------------------------------------------
	
	OTString strFinal;
	SaveContractRaw(strFinal);
	
	bool bSaved = OTDB::StorePlainString(strFinal.Get(), szFoldername, szFilename);
	
	if (!bSaved)
	{
		OTLog::vError("OTCronItem::SaveCronReceipt: Error saving file: %s%s%s\n", 
					  szFoldername, OTLog::PathSeparator(), szFilename);
		return false;
	}
	// --------------------------------------------------------------------
	
	return bSaved;
}











// DONE: Make a GENERIC VERSION of the BELOW function, that script coders can call
// whenever they need to move money between two parties!!!! The more I look at it,
// the more I realize I can probably use it NEARLY "as is" !
//
// true == success, false == failure.
//
bool OTCronItem::MoveFunds(const mapOfNyms	  & map_NymsAlreadyLoaded,
						   const long		  &	lAmount, 
						   const OTIdentifier &	SOURCE_ACCT_ID,		// GetSenderAcctID();
						   const OTIdentifier &	SENDER_USER_ID,		// GetSenderUserID();
						   const OTIdentifier &	RECIPIENT_ACCT_ID,	// GetRecipientAcctID();
						   const OTIdentifier &	RECIPIENT_USER_ID)	// GetRecipientUserID();
{	
	const OTCron * pCron = GetCron();
	OT_ASSERT(NULL != pCron);
	
	OTPseudonym * pServerNym = pCron->GetServerNym();
	OT_ASSERT(NULL != pServerNym);
	// --------------------------------------------------------	
	
	if (lAmount <= 0)
	{
		OTLog::vOutput(0, " OTCronItem::MoveFunds: Error: lAmount cannot be 0 or <0. (Value passed in was %ld.)\n",
					   lAmount);
		return false;
	}
	// -----------------------------
	
	bool					bSuccess = false;	// The return value.
	// --------------------------------------------------------
	
	const OTIdentifier		SERVER_ID(pCron->GetServerID());
	const OTIdentifier		SERVER_USER_ID(*pServerNym);
	// --------------------------------------------------------
	
	OTString	strSenderUserID(SENDER_USER_ID), strRecipientUserID(RECIPIENT_USER_ID),
				strSourceAcctID(SOURCE_ACCT_ID), strRecipientAcctID(RECIPIENT_ACCT_ID),
				strServerNymID(SERVER_USER_ID);
	
	// Make sure they're not the same Account IDs ...
	// Otherwise we would have to take care not to load them twice, like with the Nyms below.
	// (Instead I just disallow it entirely. After all, even if I DID allow the account to transfer
	// to itself, there would be no difference in balance than disallowing it.)
	//
	if (SOURCE_ACCT_ID == RECIPIENT_ACCT_ID)
	{
		OTLog::Output(0, "OTCronItem::MoveFunds: Aborted move: both account IDs were identical.\n");
		FlagForRemoval(); // Remove from Cron
		return false; // TODO: should have a "Validate Scripts" function that weeds this crap out before we even get here. (There are other examples...)
	}
	// When the accounts are actually loaded up, then we should also compare
	// the asset types to make sure they were what we expected them to be.
	
	// -----------------------------------------------------------------
	
	// Need to load up the ORIGINAL VERSION OF THIS SMART CONTRACT
	// Will need to verify the parties' signatures, as well as attach a copy of it to the receipt.
	
	OTCronItem * pOrigCronItem	= NULL;
	
	// OTCronItem::LoadCronReceipt loads the original version with the user's signature.
	// (Updated versions, as processing occurs, are signed by the server.)
	pOrigCronItem		= OTCronItem::LoadCronReceipt(GetTransactionNum());
	
	OT_ASSERT(NULL != pOrigCronItem);	// How am I processing it now if the receipt wasn't saved in the first place??
	// TODO: Decide global policy for handling situations where the hard drive stops working, etc.
	
	// When theOrigPlanGuardian goes out of scope, pOrigCronItem gets deleted automatically.
	OTCleanup<OTCronItem>	theOrigPlanGuardian(*pOrigCronItem);
	
	// strOrigPlan is a String copy (a PGP-signed XML file, in string form) of the original Payment Plan request...
	OTString strOrigPlan(*pOrigCronItem); // <====== Farther down in the code, I attach this string to the receipts.
	
	
	// Make sure to clean these up.
	//	delete pOrigCronItem;		// theOrigPlanGuardian will handle this now, whenever it goes out of scope.
	//	pOrigCronItem = NULL;		// So I don't need to worry about deleting this anymore. I can keep it around and
	// use it all I want, and return anytime, and it won't leak.
	
	
	
	// -------------- Make sure have both nyms loaded and checked out. --------------------------------------------------
	// WARNING: 1 or both of the Nyms could be also the Server Nym. They could also be the same Nym, but NOT the Server.
	// In all of those different cases, I don't want to load the same file twice and overwrite it with itself, losing
	// half of all my changes. I have to check all three IDs carefully and set the pointers accordingly, and then operate
	// using the pointers from there.
	
	
	OTPseudonym theSenderNym, theRecipientNym; // We MIGHT use ONE, OR BOTH, of these, or none. (But probably both.)
	
	// Find out if either Nym is actually also the server.
	bool bSenderNymIsServerNym		= ((SENDER_USER_ID		== SERVER_USER_ID) ? true : false);
	bool bRecipientNymIsServerNym	= ((RECIPIENT_USER_ID	== SERVER_USER_ID) ? true : false);
	
	// We also see, after all that is done, whether both pointers go to the same entity. 
	// (We'll want to know that later.)
	bool bUsersAreSameNym			= ((SENDER_USER_ID == RECIPIENT_USER_ID) ? true : false);
	
	// -----------------------------------------------------
	
	OTPseudonym * pSenderNym			= NULL;
	OTPseudonym * pRecipientNym			= NULL;
	// --------------------------
	mapOfNyms::const_iterator it_sender		= map_NymsAlreadyLoaded.find(strSenderUserID.Get());
	mapOfNyms::const_iterator it_recipient	= map_NymsAlreadyLoaded.find(strRecipientUserID.Get());
	
	if (map_NymsAlreadyLoaded.end() != it_sender) // found the sender in list of Nyms that are already loaded.
	{
		pSenderNym = (*it_sender).second;
		OT_ASSERT((NULL != pSenderNym) && (pSenderNym->CompareID(SENDER_USER_ID)));
	}
	if (map_NymsAlreadyLoaded.end() != it_recipient) // found the recipient in list of Nyms that are already loaded.
	{
		pRecipientNym = (*it_recipient).second;
		OT_ASSERT((NULL != pRecipientNym) && (pRecipientNym->CompareID(RECIPIENT_USER_ID)));
	}
	// ------------------
	
	// Figure out if Sender Nym is also Server Nym.
	if (bSenderNymIsServerNym)		
	{
		// If the First Nym is the server, then just point to that.
		pSenderNym = pServerNym;
	}
	else if (NULL == pSenderNym)	// Else load the First Nym from storage, if still not found.
	{
		theSenderNym.SetIdentifier(SENDER_USER_ID);  // theSenderNym is pSenderNym
		
		if (false == theSenderNym.LoadPublicKey())
		{
			OTString strNymID(SENDER_USER_ID);
			OTLog::vError("OTCronItem::MoveFunds: Failure loading Sender Nym public key: %s\n", 
						  strNymID.Get());
			FlagForRemoval(); // Remove it from future Cron processing, please.
			return false;
		}
		
		if (theSenderNym.VerifyPseudonym()	&&
			theSenderNym.LoadSignedNymfile(*pServerNym)) // ServerNym here is not theSenderNym's identity, but merely the signer on this file.
		{
			OTLog::Output(0, "OTCronItem::MoveFunds: Loading sender Nym, since he **** APPARENTLY **** wasn't already loaded.\n"
						  "(On a cron item processing, this is normal. But if you triggered a clause directly, then your Nym SHOULD be already loaded...)\n");
			pSenderNym = &theSenderNym; //  <=====
		}
		else
		{
			OTString strNymID(SENDER_USER_ID);
			OTLog::vError("OTCronItem::MoveFunds: Failure loading or verifying Sender Nym public key: %s\n", 
						  strNymID.Get());
			FlagForRemoval(); // Remove it from future Cron processing, please.
			return false;			
		}
	}
	
	// ------------------
	
	// Next, we also find out if Recipient Nym is Server Nym...
	if (bRecipientNymIsServerNym)		
	{
		// If the Recipient Nym is the server, then just point to that.
		pRecipientNym = pServerNym;
	}
	else if (bUsersAreSameNym)	// Else if the participants are the same Nym, point to the one we already loaded. 
	{
		pRecipientNym = pSenderNym; // theSenderNym is pSenderNym
	}
	else if (NULL == pRecipientNym)	// Otherwise load the Other Nym from Disk and point to that, if still not found.
	{
		theRecipientNym.SetIdentifier(RECIPIENT_USER_ID);
		
		if (false == theRecipientNym.LoadPublicKey())
		{
			OTString strNymID(RECIPIENT_USER_ID);
			OTLog::vError("OTCronItem::MoveFunds: Failure loading Recipient Nym public key: %s\n", 
						  strNymID.Get());
			FlagForRemoval(); // Remove it from future Cron processing, please.
			return false;
		}
		
		if (theRecipientNym.VerifyPseudonym()	&& 
			theRecipientNym.LoadSignedNymfile(*pServerNym))
		{
			OTLog::Output(0, "OTCronItem::MoveFunds: Loading recipient Nym, since he **** APPARENTLY **** wasn't already loaded.\n"
						  "(On a cron item processing, this is normal. But if you triggered a clause directly, then your Nym SHOULD be already loaded...)\n");
			
			pRecipientNym = &theRecipientNym; //  <=====
		}
		else 
		{
			OTString strNymID(RECIPIENT_USER_ID);
			OTLog::vError("OTCronItem::MoveFunds: Failure loading or verifying Recipient Nym public key: %s\n", 
						  strNymID.Get());
			FlagForRemoval(); // Remove it from future Cron processing, please.
			return false;			
		}
	}
	
	// Below this point, both Nyms are loaded and good-to-go.
	// -----------------------------------------------------------------
	
	mapOfNyms map_ALREADY_LOADED; // I know I passed in one of these, but now I have processed the Nym pointers (above) and have better data here now.
	mapOfNyms::iterator it_temp;
	
	it_temp = map_ALREADY_LOADED.find(strServerNymID.Get());
	if (map_ALREADY_LOADED.end() == it_temp)
		map_ALREADY_LOADED.insert(std::pair<std::string,OTPseudonym*>(strServerNymID.Get(),		pServerNym));  // Add Server Nym to list of Nyms already loaded.
	it_temp = map_ALREADY_LOADED.find(strSenderUserID.Get());
	if (map_ALREADY_LOADED.end() == it_temp)
		map_ALREADY_LOADED.insert(std::pair<std::string,OTPseudonym*>(strSenderUserID.Get(),	pSenderNym));  // Add Sender Nym to list of Nyms already loaded.
	it_temp = map_ALREADY_LOADED.find(strRecipientUserID.Get());
	if (map_ALREADY_LOADED.end() == it_temp)
		map_ALREADY_LOADED.insert(std::pair<std::string,OTPseudonym*>(strRecipientUserID.Get(),	pRecipientNym));  // Add Recipient Nym to list of Nyms already loaded.
	//
	//	I set up map_ALREADY_LOADED here so that when I call VerifyAgentAsNym(), I can pass it along. VerifyAgentAsNym often
	//  just verifies ownership (for individual nym owners who act as their own agents.) BUT... If we're in a smart contract,
	//  or other OTScriptable, there might be a party owned by an entity, and a signature needs to be checked that ISN'T the
	//  same Nym! (Perhaps the entity signed the smartcontract via another signer Nym.) This means I might potentially have to
	//  LOAD the other signer Nym, in order to verify his signature...BUT WHAT IF HE'S ALREADY LOADED?  
	//
	//  THAT... is exactly why I am passing in a list now of all the Nyms that are already loaded... So if the authorizing Nym for
	//  any given party happens to already be loaded on that list, it can use it, instead of loading it twice (and potentially 
	//  overwriting data... Bad thing!)
	//
	// Now that I have the original cron item loaded, and all the Nyms ready to go,
	// let's make sure that BOTH the nyms in question have SIGNED the original request.
	// (Their signatures wouldn't be on the updated version in Cron--the server signs
	// that one. Except smart contracts, which keep a signed copy automatically for each party.)
	//
	// NOTE: originally I used to just verify here that both Nyms have signed the original
	// cron item. But now I provide a virtual method to do that (which it still does, by default.)
	// But in the case of smart contracts, it's more complicated. The Nym might merely be an agent
	// for a party, (legitimately) but where a DIFFERENT agent is the one who originally signed.
	// Thus, I have to allow SmartContract to override the method so it can add that extra intelligence.
	//
	// NOTE: This function does NOT verify that the Nyms are authorized for the ASSET ACCOUNTS--either the
	// party providing authorization OR the acct itself. Instead, this ONLY verifies that they are actually
	// agents for legitimate parties to this agreement ACCORDING TO THOSE PARTIES, (regardless of the asset
	// accounts) and that said agreement has also been signed by authorized agents of those parties. 
	// (Usually the agent who originally signed, and the agent signing now, and the
	// party that agent represents, are all in reality the SAME NYM. But in the case of
	// smart contracts, they can be different Nyms, which is why we now have an overridable virtual method
	// for this, instead of simply verifying both signatures on the cron item itself, as the default 
	// OTTrade and OTAgreement versions of that virtual method will continue to do.
	//
	// Repeat: this is not about verifying account ownershp or permissions. It's ONLY about verifying
	// that these nyms are actually authorized to act as parties to the agreement. Verifying their ownership
	// rights over the asset accounts is done separately below.
	//	
	// Another thing: The original "VerifySignature()" proved that the NYM HIMSELF had signed/authorized,
	// whereas now it's more like, prove which party owns the account, then prove that party has authorized
	// Nym as his agent.
	//
	
	// -----------------------------------------------------------------
	// VerifyNymAsAgent() replaces VerifySignature() here. It's polymorphic, so VerifySignature() is still called
	// directly on theNym in certain versions (agreement, trade...) but otherwise there is now more to it than that.
	// See OTScriptable for the complicated version. Either way, it makes sure that the right person signed and that
	// theNym is authorized to act by that person. (As far as pOrigCronItem cares -- the Account may still disagree.)
	// This verifies:
	// - that the Nym is found as an agent on one of the parties.
	// - that there is an "original party signed copy" of the contract attached to the party.
	// - that there is an authorizing agent for that party whose SIGNATURE VERIFIES on the party's signed copy.
	//
	if (!pOrigCronItem->VerifyNymAsAgent(*pSenderNym, *pServerNym,
										 // In case it needs to load the AUTHORIZING agent, and that agent is already loaded, it will have access here.
										 &map_ALREADY_LOADED)) 
	{
		OTLog::vError("OTCronItem::MoveFunds: Failed authorization for sender Nym: %s\n", strSenderUserID.Get());
		FlagForRemoval(); // Remove it from Cron.
		return false;			
	}
	
	if (!pOrigCronItem->VerifyNymAsAgent(*pRecipientNym, *pServerNym,
		 								 // In case it needs to load the AUTHORIZING agent, and that agent is already loaded, it will have access here.
										 &map_ALREADY_LOADED)) 
	{
		OTLog::vError("OTCronItem::MoveFunds: Failed authorization for recipient Nym: %s\n", strRecipientUserID.Get());
		FlagForRemoval(); // Remove it from Cron.
		return false;			
	}
	
	// (verifications)
	//
	// -- DONE Verify that both Nyms are actually authorized to act as agents for the parties. (in the cron item.) This is like pOrig->VerifySignature(theNym);
	// -- DONE Verify that both parties have properly signed/executed the contract. This may mean loading a DIFFERENT Nym (the authorizing agent who signed for the party originally)
	//    This is also like pOrig->VerifySignature(theNym); the extra functionality is added via polymorphism.
	// -- DONE Verify that both Nyms are authorized agents FOR THE ASSET ACCOUNTS IN QUESTION, according to their PARTIES. This is like pParty->HasAgent(theNym);
	// -- DONE Verify that both ACCOUNTS are owned by the parties that the Nyms represent.  According to the ACCOUNTS. This is like pAcct->VerifyOwner(theNym)
	//    The above two items should ALSO be done polymorphically, just like the first two.
	// -- If the Nyms are not the parties they represent, then verify that they have the proper Role at their entities in order to claim such authority.
	//    Does this last one go into OTAccount itself? Or OTScriptable. And the actual verification part will be probably in OTAgent, just like VerifySignature was.
	//
	//	if (!pOrigCronItem->VerifySignature(*pSenderNym) || !pOrigCronItem->VerifySignature(*pRecipientNym))
	//
	//	{
	//		OTLog::Error("OTCronItem::MoveFunds: Failed authorization.\n");
	//		FlagForRemoval(); // Remove it from Cron.
	//		return false;			
	//	}
	
	
	// AT THIS POINT, I have pServerNym, pSenderNym, and pRecipientNym. 
	// ALL are loaded from disk (where necessary.) AND...
	// ALL are valid pointers, (even if they sometimes point to the same object,)
	// AND none are capable of overwriting the storage of the other (by accidentally
	// loading the same storage twice.)
	// We also have boolean variables at this point to tell us exactly which are which,
	// (in case some of those pointers do go to the same object.) 
	// They are:
	// bSenderNymIsServerNym, bRecipientNymIsServerNym, and bUsersAreSameNym.
	//
	// I also have pOrigCronItem, which is a dynamically-allocated copy of the original
	// Cron Receipt for this Cron Item. (And I don't need to worry about deleting it, either.)
	// I know for a fact they are both authorized on pOrigCronItem...
	// -----------------------------------------------------------------
	
	// LOAD THE ACCOUNTS
	//
	OTAccount * pSourceAcct		= OTAccount::LoadExistingAccount(SOURCE_ACCT_ID, SERVER_ID);
	
	if (NULL == pSourceAcct)
	{
		OTLog::Output(0, "OTCronItem::MoveFunds: ERROR verifying existence of source account.\n");
		FlagForRemoval(); // Remove it from future Cron processing, please.
		return false;
	}
	// Past this point we know pSourceAcct is good and will clean itself up.
	OTCleanup<OTAccount>	theSourceAcctSmrtPtr(*pSourceAcct);
	// -----------------------------------------------------------------
	
	OTAccount * pRecipientAcct	= OTAccount::LoadExistingAccount(RECIPIENT_ACCT_ID,	SERVER_ID);
	
	if (NULL == pRecipientAcct)
	{
		OTLog::Output(0, "OTCronItem::MoveFunds: ERROR verifying existence of recipient account.\n");
		FlagForRemoval(); // Remove it from future Cron processing, please.
		return false;
	}
	// Past this point we know pRecipientAcct is good and will clean itself up.
	OTCleanup<OTAccount>	theRecipAcctSmrtPtr(*pRecipientAcct);
	// -----------------------------------------------------------------
	
	
	// BY THIS POINT, both accounts are successfully loaded, and I don't have to worry about
	// cleaning either one of them up, either. But I can now use pSourceAcct and pRecipientAcct...
	//
	//
	// -----------------------------------------------------------------------------------
	
	// A few verification if/elses...
	
	// Are both accounts of the same Asset Type?
	if (pSourceAcct->GetAssetTypeID() != pRecipientAcct->GetAssetTypeID())
	{	// We already know the SUPPOSED Asset IDs of these accounts... But only once
		// the accounts THEMSELVES have been loaded can we VERIFY this to be true.
		OTLog::Output(0, "OTCronItem::MoveFunds: ERROR - attempted payment between accounts of different "
					  "asset types.\n");
		FlagForRemoval(); // Remove it from future Cron processing, please.
		return false;
	}
	
	// -------------------------------------------------------------------------
	// I call VerifySignature (WITH SERVER NYM) here since VerifyContractID was 
	// already called in LoadExistingAccount().
	//
	else if (!pSourceAcct->VerifySignature(*pServerNym) || !this->VerifyNymAsAgentForAccount(*pSenderNym, *pSourceAcct) )
	{
		OTLog::Output(0, "OTCronItem::MoveFunds: ERROR verifying signature or ownership on source account.\n");
		FlagForRemoval(); // Remove it from future Cron processing, please.
		return false;
	}
	
	else if (!pRecipientAcct->VerifySignature(*pServerNym) || !this->VerifyNymAsAgentForAccount(*pRecipientNym, *pRecipientAcct) )
	{
		OTLog::Output(0, "OTCronItem::MoveFunds: ERROR verifying signature or ownership on recipient account.\n");
		FlagForRemoval(); // Remove it from future Cron processing, please.
		return false;
	}
	// -------------------------------------------------------------------------
	
	
	// By this point, I know I have both accounts loaded, and I know that they have the right asset types,
	// and I know they have the right owners and they were all signed by the server.
	// I also know that their account IDs in their internal records matched the account filename for each acct.
	// I also have pointers to the Nyms who own these accounts.
	
	else
	{			
		// Okay then, everything checks out. Let's add a receipt to the sender's inbox and the recipient's inbox. 
		// IF they can be loaded up from file, or generated, that is. 
		
		// Load the inboxes in case they already exist
		OTLedger	theSenderInbox		(SENDER_USER_ID,	SOURCE_ACCT_ID,		SERVER_ID),
					theRecipientInbox	(RECIPIENT_USER_ID, RECIPIENT_ACCT_ID,	SERVER_ID);
		
		// ALL inboxes -- no outboxes. All will receive notification of something ALREADY DONE.
		bool bSuccessLoadingSenderInbox		= theSenderInbox.LoadInbox();
		bool bSuccessLoadingRecipientInbox	= theRecipientInbox.LoadInbox();
		
		// --------------------------------------------------------------------
		
		// ...or generate them otherwise...
		
		if (true == bSuccessLoadingSenderInbox)
			bSuccessLoadingSenderInbox		= theSenderInbox.VerifyAccount(*pServerNym);
		else
			OTLog::Error("OTCronItem::MoveFunds: ERROR loading sender inbox ledger.\n");
//		else
//			bSuccessLoadingSenderInbox		= theSenderInbox.GenerateLedger(SOURCE_ACCT_ID, SERVER_ID, OTLedger::inbox, true); // bGenerateFile=true
		
		if (true == bSuccessLoadingRecipientInbox)
			bSuccessLoadingRecipientInbox	= theRecipientInbox.VerifyAccount(*pServerNym);
		else
			OTLog::Error("OTCronItem::MoveFunds: ERROR loading recipient inbox ledger.\n");
//		else
//			bSuccessLoadingRecipientInbox	= theRecipientInbox.GenerateLedger(RECIPIENT_ACCT_ID, SERVER_ID, OTLedger::inbox, true); // bGenerateFile=true
		
		// --------------------------------------------------------------------
		
		if ((false == bSuccessLoadingSenderInbox)	|| 
			(false == bSuccessLoadingRecipientInbox))
		{
			OTLog::Error("OTCronItem::MoveFunds: ERROR loading or generating one (or both) of the inbox ledgers.\n");
		}
		else 
		{
			// Generate new transaction numbers for these new transactions
			long lNewTransactionNumber = GetCron()->GetNextTransactionNumber();
			
			//			OT_ASSERT(lNewTransactionNumber > 0); // this can be my reminder.			
			if (0 == lNewTransactionNumber)
			{
				OTLog::Output(0, "OTCronItem::MoveFunds: Aborted move: There are no more transaction numbers available.\n");
				// (Here I do NOT flag for removal.)
				return false; 			
			}
			
			OTTransaction * pTransSend		= OTTransaction::GenerateTransaction(theSenderInbox, 
																				 OTTransaction::paymentReceipt, lNewTransactionNumber);
			
			OTTransaction * pTransRecip		= OTTransaction::GenerateTransaction(theRecipientInbox, 
																				 OTTransaction::paymentReceipt, lNewTransactionNumber);
			
			// (No need to OT_ASSERT on the above transactions since it occurs in GenerateTransaction().)
			
			
			// Both inboxes will get receipts with the same (new) transaction ID on them.
			// They will have a "In reference to" field containing the original payment plan
			// (with user's signature).
			
			// set up the transaction items (each transaction may have multiple items... but not in this case.)
			OTItem * pItemSend		= OTItem::CreateItemFromTransaction(*pTransSend, OTItem::paymentReceipt);
			OTItem * pItemRecip		= OTItem::CreateItemFromTransaction(*pTransRecip, OTItem::paymentReceipt);
			
			// these may be unnecessary, I'll have to check CreateItemFromTransaction. I'll leave em.
			OT_ASSERT(NULL != pItemSend);	
			OT_ASSERT(NULL != pItemRecip);
			
			pItemSend->SetStatus(OTItem::rejection); // the default.
			pItemRecip->SetStatus(OTItem::rejection); // the default.
			
			
			
			/* (from above)
			OTString	strSenderUserID(SENDER_USER_ID), strRecipientUserID(RECIPIENT_USER_ID),
						strSourceAcctID(SOURCE_ACCT_ID), strRecipientAcctID(RECIPIENT_ACCT_ID),
						strServerNymID(SERVER_USER_ID);
			
			 // ------------------------------------------------------
			 // (from OTCronItem.h)
			 virtual long GetOpeningNumber(OTIdentifier	& theNymID) const;
			 virtual long GetClosingNumber(OTIdentifier	& theAcctID) const;
			 // ------------------------------------------------------ */
			 //
//			const long lTransSendRefNo	= GetTransactionNum();
//			const long lTransRecipRefNo	= GetTransactionNum();
			const long lTransSendRefNo	= this->GetOpeningNumber(SENDER_USER_ID);
			const long lTransRecipRefNo	= this->GetOpeningNumber(RECIPIENT_USER_ID);
			
			// Here I make sure that each receipt (each inbox notice) references the original
			// transaction number that was used to set the cron item into place...
			// This number is used to track all cron items. (All Cron items require a transaction 
			// number from the user in order to add them to Cron in the first place.)
			// 
			// The number is also used to uniquely identify all other transactions, as you
			// might guess from its name.
			//
			// UPDATE: Notice I'm now looking up different numbers based on the UserIDs.
			// This is to support smart contracts, which have many parties, agents, and accounts.
			//
//			pItemSend->SetReferenceToNum(lTransSendRefNo);
			pTransSend->SetReferenceToNum(lTransSendRefNo);
			// ----------------------------------------------
//			pItemRecip->SetReferenceToNum(lTransRecipRefNo);
			pTransRecip->SetReferenceToNum(lTransRecipRefNo);
			// --------------------------------------------------------
			
			// The TRANSACTION (a receipt in my inbox) will be sent with "In Reference To" information
            // containing the ORIGINAL SIGNED CRON ITEM. (With both parties' original signatures on it.)
			//
			// Whereas the TRANSACTION ITEM will include an "attachment" containing the UPDATED
			// CRON ITEM (this time with the SERVER's signature on it.)
			//
			// Here's the original one going onto the transaction:
			//
			pTransSend->SetReferenceString(strOrigPlan);
			pTransRecip->SetReferenceString(strOrigPlan);			
			
			// --------------------------------------------------------------------------
			
			// MOVE THE DIGITAL ASSETS FROM ONE ACCOUNT TO ANOTHER...
			
			// Calculate the amount and debit/ credit the accounts
			// Make sure each Account can afford it, and roll back in case of failure.
			
			bool bMoveSender	= false;
			bool bMoveRecipient = false;
			
			// Make sure he can actually afford it...
			if (pSourceAcct->GetBalance() >= lAmount)
			{
				// Debit the source account. 
				bMoveSender	= pSourceAcct->Debit(lAmount); // <====== DEBIT FUNDS
				
				// IF success, credit the recipient.
				if (bMoveSender)
				{
					bMoveRecipient	= pRecipientAcct->Credit(lAmount); // <=== CREDIT FUNDS
					
					// Okay, we already took it from the source account.
					// But if we FAIL to credit the recipient, then we need to PUT IT BACK in the source acct.
					// (EVEN THOUGH we'll just "NOT SAVE" after any failure, so it's really superfluous.)
					//
					if (!bMoveRecipient)
						pSourceAcct->Credit(lAmount); // put the money back
					else
						bSuccess = true;
				}
				
				// If ANY of these failed, then roll them all back and break.
				if (!bMoveSender || !bMoveRecipient)
				{
					OTLog::Error("OTCronItem::MoveFunds: Very strange! Funds were available but "
								 "debit or credit failed while performing move.\n");
					// We won't save the files anyway, if this failed. 					
					bSuccess = false;
				}				
			}
			
			
			
			// --------------------------------------------------------------------------
			
			
			
			
			
			// DO NOT SAVE ACCOUNTS if bSuccess is false.
			// We only save these accounts if bSuccess == true.
			// (But we do save the inboxes either way, since payment failures always merit an inbox notice.)
			
			if (true == bSuccess) // The payment succeeded.
			{
				// Both accounts involved need to get a receipt of this trade in their inboxes...
				pItemSend->SetStatus(OTItem::acknowledgement); // pSourceAcct		
				pItemRecip->SetStatus(OTItem::acknowledgement); // pRecipientAcct
				
				pItemSend->SetAmount(lAmount*(-1));	// "paymentReceipt" is otherwise ambigious about whether you are paying or being paid.
				pItemRecip->SetAmount(lAmount);		// So, I decided for payment and market receipts, to use negative and positive amounts.
				// I will probably do the same for cheques, since they can be negative as well (invoices).
				
				OTLog::Output(3, "OTCronItem::MoveFunds: Move performed.\n");
				
				// (I do NOT save m_pCron here, since that already occurs after this function is called.)
			}
			else // bSuccess = false.  The payment failed.
			{
				pItemSend->SetStatus(OTItem::rejection);// pSourceAcct		// These are already initialized to false.
				pItemRecip->SetStatus(OTItem::rejection);// pRecipientAcct	// (But just making sure...)
				
				pItemSend->SetAmount(0);		// No money changed hands. Just being explicit.
				pItemRecip->SetAmount(0);		// No money changed hands. Just being explicit.		
				
				OTLog::Output(3, "OTCronItem::MoveFunds: Move failed.\n");
			}
			
			// Everytime a payment processes, a receipt is put in the user's inbox, containing a
			// CURRENT copy of the cron item (which took just money from the user's acct, or not,
			// and either way thus updated its status -- so its internal data has changed.)
			//
			// It will also contain a copy of the user's ORIGINAL signed cron item, where the data
			// has NOT changed, (so the user's original signature is still good.)
			//
			// In order for it to export the RIGHT VERSION of the CURRENT plan, which has just changed
			// (above), then I need to re-sign it and save it first. (The original version I'll load from
			// a separate file using OTCronItem::LoadCronReceipt(lTransactionNum).
			//
			// I should be able to call a method on the original cronitem, where I ask it to verify a certain
			// nym as being acceptable to that cron item as an agent, based on the signature of the original
			// authorizing agent for that party.
			//
			
			this->ReleaseSignatures();
			this->SignContract(*pServerNym);
			this->SaveContract();
			
			
			// This is now at the bottom of this function.
			//
			//m_pCron->SaveCron(); // Cron is where I am serialized, so if Cron's not saved, I'm not saved.
			
			// -----------------------------------------------------------------
			//
			// EVERYTHING BELOW is just about notifying the users, by dropping the receipt in their
			// inboxes. The rest is done.  The accounts and inboxes will all be saved at the same time.
			//
			// The Payment Plan is entirely updated and saved by this point, and Cron will
			// also be saved in the calling function once we return (no matter what.)
			//
			// -----------------------------------------------------------------
			
			
			// Basically I load up both INBOXES, which are actually LEDGERS, and then I create
			// a new transaction, with a new transaction item, for each of the ledgers.
			// (That's where the receipt information goes.)
			// 
			
			
			
			// -----------------------------------------------------------------
			
			// The TRANSACTION will be sent with "In Reference To" information containing the
			// ORIGINAL SIGNED PLAN. (With both of the users' original signatures on it.)
			//
			// Whereas the TRANSACTION ITEM will include an "attachment" containing the UPDATED
			// PLAN (this time with the SERVER's signature on it.)
			
			// (Lucky I just signed and saved the updated plan (above), or it would still have 
			// have the old data in it.)
			
			// I also already loaded the original plan. Remember this from above,
			// near the top of the function:
			//  OTCronItem * pOrigCronItem	= NULL;
			// 	OTString strOrigPlan(*pOrigCronItem); // <====== Farther down in the code, I attach this string to the receipts.
			//  ... then lower down...
			// pTransSend->SetReferenceString(strOrigPlan);
			// pTransRecip->SetReferenceString(strOrigPlan);
			//
			// So the original plan is already loaded and copied to the Transaction as the "In Reference To" 
			// Field. Now let's add the UPDATED plan as an ATTACHMENT on the Transaction ITEM:
			//
			OTString	strUpdatedCronItem(*this);
			
			// Set the updated cron item as the attachment on the transaction item.
			// (With the SERVER's signature on it!)
			// (As a receipt for each party, so they can see their smartcontract updating.)
			//
			pItemSend->SetAttachment(strUpdatedCronItem);
			pItemRecip->SetAttachment(strUpdatedCronItem);
			
			// -----------------------------------------------------------------
			
			// Success OR failure, either way I want a receipt in both inboxes.
			// But if FAILURE, I do NOT want to save the Accounts, JUST the inboxes.
			// So the inboxes happen either way, but the accounts are saved only on success.
			
			// sign the item
			pItemSend->SignContract(*pServerNym);
			pItemRecip->SignContract(*pServerNym);
			
			pItemSend->SaveContract();
			pItemRecip->SaveContract();
			
			// the Transaction "owns" the item now and will handle cleaning it up.
			pTransSend->AddItem(*pItemSend);
			pTransRecip->AddItem(*pItemRecip);
			
			pTransSend->SignContract(*pServerNym);
			pTransRecip->SignContract(*pServerNym);
			
			pTransSend->SaveContract();
			pTransRecip->SaveContract();
			
			// -------------------------------------------
			// Here, the transactions we just created are actually added to the ledgers.
			// This happens either way, success or fail.
			
			theSenderInbox.		AddTransaction(*pTransSend);
			theRecipientInbox.	AddTransaction(*pTransRecip);
			
			// -------------------------------------------
			
			// Release any signatures that were there before (They won't
			// verify anymore anyway, since the content has changed.)
			theSenderInbox.		ReleaseSignatures();
			theRecipientInbox.	ReleaseSignatures();
			
			// Sign both of them.				
			theSenderInbox.		SignContract(*pServerNym);
			theRecipientInbox.	SignContract(*pServerNym);
			
			// Save both of them internally
			theSenderInbox.		SaveContract();
			theRecipientInbox.	SaveContract();
			
			// Save both inboxes to storage. (File, DB, wherever it goes.)
			theSenderInbox.		SaveInbox();
			theRecipientInbox.	SaveInbox();
			
			// These correspond to the AddTransaction() calls, just above
			//
			pTransSend->SaveBoxReceipt(theSenderInbox);
			pTransRecip->SaveBoxReceipt(theRecipientInbox);
			
			// If success, save the accounts with new balance. (Save inboxes with receipts either way,
			// and the receipts will contain a rejection or acknowledgment stamped by the Server Nym.)
			if (true == bSuccess)
			{					
				// -------------------------------------------
				// Release any signatures that were there before (They won't
				// verify anymore anyway, since the content has changed.)
				pSourceAcct->	ReleaseSignatures();	
				pRecipientAcct->ReleaseSignatures();	
				
				// Sign both of them.				
				pSourceAcct->	SignContract(*pServerNym);	
				pRecipientAcct->SignContract(*pServerNym);	
				
				// Save both of them internally
				pSourceAcct->	SaveContract();	
				pRecipientAcct->SaveContract();	
				
				// TODO: Better rollback capabilities in case of failures here:
				
				// Save both accounts to storage.
				pSourceAcct->	SaveAccount();	
				pRecipientAcct->SaveAccount();	
				
				// NO NEED TO LOG HERE, since success / failure is already logged above.
			}
		} // both inboxes were successfully loaded or generated.
	} // By the time we enter this block, accounts and nyms are already loaded. As we begin, inboxes are instantiated.
	
	// Todo: possibly notify ALL parties here (in Nymbox.)
	
	// Either way, Cron should save, since it just updated.
	// The above function WILL change this smart contract.
	// and re-sign it and save it, no matter what. So I just 
	// call this here to keep it simple:
	
	GetCron()->SaveCron();
	
	
	return bSuccess;
}





bool OTCronItem::SetDateRange(const time_t VALID_FROM/*=0*/,  const time_t VALID_TO/*=0*/)
{
	// ***************************************************
	// Set the CREATION DATE
    //
	const time_t CURRENT_TIME = time(NULL);
	
	// Set the Creation Date.
	SetCreationDate(CURRENT_TIME);
	
    // -----------------------------------------
    // VALID_FROM
    //
	// The default "valid from" time is NOW.
	if (0 >= VALID_FROM) // if it's 0 or less, set to current time.
		SetValidFrom(CURRENT_TIME);
	else // Otherwise use whatever was passed in.
		SetValidFrom(VALID_FROM);
    // ------------------------------------------- 
    // VALID_TO
    //
	// The default "valid to" time is 0 (which means no expiration date / cancel anytime.)
	if (0 == VALID_TO) // VALID_TO is 0
	{
		SetValidTo(VALID_TO); // Keep it at zero then, so it won't expire.
	}
	else if (0 < VALID_TO) // VALID_TO is ABOVE zero...
	{
		if (VALID_TO < VALID_FROM) // If Valid-To date is EARLIER than Valid-From date...
		{
			long lValidTo = VALID_TO, lValidFrom = VALID_FROM;
			OTLog::vError("OTCronItem::SetDateRange: VALID_TO (%ld) is earlier than VALID_FROM (%ld)\n", 
                          lValidTo, lValidFrom);
			return false;
		}
		
		SetValidTo(VALID_TO); // Set it to whatever it is, since it is now validated as higher than Valid-From.
	}
	else // VALID_TO is a NEGATIVE number... Error.
	{
		long lValidTo = VALID_TO;
		OTLog::vError("OTCronItem::SetDateRange: Negative value for valid_to: %ld\n", lValidTo);
        
		return false;
	}
	// ***************************************************
	
	return true;
}





// ------------------------------------------------------------
// These are for finalReceipt
// The Cron Item stores a list of these closing transaction numbers,
// used for closing a transaction.
//
int OTCronItem::GetCountClosingNumbers() const
{
	return m_dequeClosingNumbers.size();
}

long OTCronItem::GetClosingTransactionNoAt(unsigned int nIndex) const 
{
    OT_ASSERT_MSG((nIndex < m_dequeClosingNumbers.size()) && (nIndex >= 0), 
                  "OTCronItem::GetClosingTransactionNoAt: index out of bounds.");
    
    return m_dequeClosingNumbers.at(nIndex);
}

void OTCronItem::AddClosingTransactionNo(const long & lClosingTransactionNo)
{
    m_dequeClosingNumbers.push_back(lClosingTransactionNo);
}
// ------------------------------------------------------------

/// See if theNym has rights to remove this item from Cron.
///
bool OTCronItem::CanRemoveItemFromCron(OTPseudonym & theNym)
{
    // You don't just go willy-nilly and remove a cron item from a market unless you check first
    // and make sure the Nym who requested it actually has said number (or a related closing number)
    // signed out to him on his last receipt...
    //    
    if (false == theNym.CompareID(GetSenderUserID()))
    {
        OTLog::Output(5, "OTCronItem::CanRemoveItem: theNym is not the originator of this CronItem. "
                      "(He could be a recipient though, so this is normal.)\n");
        return false;
    }
    
    // By this point, that means theNym is DEFINITELY the originator (sender)...
    else if (this->GetCountClosingNumbers() < 1)
    {
        OTLog::vOutput(0, "Weird: Sender tried to remove a cron item; expected at least 1 closing number to be available"
                      "--that wasn't. (Found %d).\n", this->GetCountClosingNumbers());
        return false;
    }
    // ------------------------------------------
    //
    const OTString strServerID(GetServerID());
    
    if (false == theNym.VerifyIssuedNum(strServerID, this->GetClosingNum()))
    {
        OTLog::Output(0, "OTCronItem::CanRemoveItemFromCron: Closing number didn't verify (for removal from cron).\n");
        return false;
    }
 
    // By this point, we KNOW theNym is the sender, and we KNOW there are the proper number of transaction
    // numbers available to close. We also know that this cron item really was on the cron object, since
    // that is where it was looked up from, when this function got called! So I'm pretty sure, at this point,
    // to authorize removal, as long as the transaction num is still issued to theNym (this check here.)
    //
    return theNym.VerifyIssuedNum(strServerID, this->GetOpeningNum());

    // Normally this will be all we need to check. The originator will have the transaction
    // number signed-out to him still, if he is trying to close it. BUT--in some cases, someone
    // who is NOT the originator can cancel. Like in a payment plan, the sender is also the depositor,
    // who would normally be the person cancelling the plan. But technically, the RECIPIENT should
    // also have the ability to cancel that payment plan.  BUT: the transaction number isn't signed
    // out to the RECIPIENT... In THAT case, the below VerifyIssuedNum() won't work! In those cases,
    // expect that the special code will be in the subclasses override of this function. (OTPaymentPlan::CanRemoveItem() etc)

    // P.S. If you override this function, maybe call the parent (OTCronItem::CanRemoveItem) first, 
    // for the VerifyIssuedNum call above. Only if that fails, do you need to dig deeper...
}




// OTCron calls this regularly, which is my chance to expire, etc.
// Child classes will override this, AND call it (to verify valid date range.)
//
// Return False:	REMOVE this Cron Item from Cron.
// Return True:		KEEP this Cron Item on Cron (for now.)
//
bool OTCronItem::ProcessCron()
{
	OT_ASSERT(m_pCron);
	
    if (IsFlaggedForRemoval())
    {
		OTLog::vOutput(3, "Cron: Flagged for removal: %s.\n", m_strContractType.Get());        
        return false;
    }
    
	// I call IsExpired() here instead of VerifyCurrentDate(). The Cron Item will stay on
	// Cron even if it is NOT YET valid. But once it actually expires, this will remove it.
	if (IsExpired())
	{
		OTLog::vOutput(3, "Cron: Expired %s.\n", m_strContractType.Get());
		return false;
	}
	
	// As far as this code is concerned, the item can stay on cron for now. Return true.
	return true;
}




// OTCron calls this when a cron item is added.
// bForTheFirstTime=true means that this cron item is being
// activated for the very first time. (Versus being re-added
// to cron after a server reboot.)
//
void OTCronItem::HookActivationOnCron(OTPseudonym * pActivator, // sometimes NULL.
									  bool bForTheFirstTime/*=false*/) 
{
    OTCron * pCron  = GetCron();
    OT_ASSERT(NULL != pCron);
    
    OTPseudonym * pServerNym = pCron->GetServerNym();
    OT_ASSERT(NULL != pServerNym);
    
    // -----------------------------------------------------
    
	// Put anything else in here, that needs to be done in the
	// cron item base class, upon activation. (This executes
	// no matter what, even if onActivate() is overridden.)
    
    // -------------------------------------------------------
    // 
	if (bForTheFirstTime)
		onActivate(); // Subclasses may override this. 
	//
	// MOST NOTABLY,
	// OTSmartContract overrides this, so it can allow the SCRIPT
	// a chance to hook onActivate() as well.
}





// OTCron calls this when a cron item is removed
// This gives each item a chance to drop a final receipt,
// and clean up any memory, before being destroyed.
//
void OTCronItem::HookRemovalFromCron(OTPseudonym * pRemover) // sometimes NULL.
{
    OTCron * pCron  = GetCron();
    OT_ASSERT(NULL != pCron);
    
    OTPseudonym * pServerNym = pCron->GetServerNym();
    OT_ASSERT(NULL != pServerNym);
    
    // -----------------------------------------------------
    
    // Generate new transaction number for these new inbox receipts.
    //
    const long lNewTransactionNumber = pCron->GetNextTransactionNumber();
    
    //	OT_ASSERT(lNewTransactionNumber > 0); // this can be my reminder.			
    if (0 == lNewTransactionNumber)
    {
        OTLog::Error("OTCronItem::HookRemovalFromCron: ** ERROR Final receipt not added to inbox, since no "
                     "transaction numbers were available!\n");
    }
    else
    {
        // Everytime a payment processes, or a trade, then a receipt is put in the user's inbox.
        // This contains a copy of the current payment or trade (which took money from the user's acct.)
        //
        // ==> So I increment the payment count each time before dropping the receipt. (I also use a fresh
        // transaction number when I put it into the inbox.) That way, the user will never get the same
        // receipt for the same plan twice. It cannot take funds from his account, without a new payment
        // count and a new transaction number on a new receipt. Until the user accepts the receipt out
        // of his inbox with a new balance agreement, the existing receipts can be added up and compared
        // to the last balance agreement, to verify the current balance. Every receipt from a processing
        // payment will have the user's authorization, signature, and terms, as well as the update in balances
        // due to the payment, signed by the server.
        
        // In the case of the FINAL RECEIPT, I do NOT increment the count, so you can see it will have the same
        // payment count as the last paymentReceipt. (if there were 5 paymentReceipts, from 1 to 5, then the
        // finalReceipt will also be 5. This is evidence of what the last paymentReceipt WAS.)
        
        // -------------------------------------------------------------
        
        // The TRANSACTION will be dropped into the INBOX with "In Reference To" information,
        // containing the ORIGINAL SIGNED REQUEST.
        //
        OTCronItem * pOrigCronItem	= OTCronItem::LoadCronReceipt(GetTransactionNum());
        // OTCronItem::LoadCronReceipt loads the original version with the user's signature.
        // (Updated versions, as processing occurs, are signed by the server.)
        OT_ASSERT(NULL != pOrigCronItem);
        OTCleanup<OTCronItem> theCronItemAngel(*pOrigCronItem);
        
        // Note: elsewhere, we verify the Nym's signature. But in this place, we verify the SERVER's
        // signature. (The server signed the cron receipt just before it was first saved, so it has two signatures on it.)
        //
        OT_ASSERT_MSG(pOrigCronItem->VerifySignature(*pServerNym), 
                      "Failure verifying signature of server on Cron Item in OTCronItem::HookRemovalFromCron.\n");
        
        // I now have a String copy of the original CronItem...
        const OTString strOrigCronItem(*pOrigCronItem);
        // -------------------------------------------------------
        
        OTPseudonym theOriginatorNym; // Don't use this... use the pointer just below.

        // The Nym who is actively requesting to remove a cron item will be passed in as pRemover.
        // However, sometimes there is no Nym... perhaps it just expired and pRemover is NULL.
        // The originating Nym (if different than remover) is loaded up. Otherwise the originator
        // pointer just pointers to *pRemover.
        //
        OTPseudonym * pOriginator = NULL;
        
        if (pServerNym->CompareID(pOrigCronItem->GetSenderUserID()))
        {
            pOriginator = pServerNym; // Just in case the originator Nym is also the server Nym.
        }                               // This MIGHT be unnecessary, since pRemover is(I think) already transmogrified 
        // ******************************************************* to pServer earlier, if they share the same ID.
        //
        // If pRemover is NOT NULL, and he has the Originator's ID...
        // then set the pointer accordingly.
        //
        else if ((NULL != pRemover) && (true == pRemover->CompareID(pOrigCronItem->GetSenderUserID())))
        {
            pOriginator = pRemover; // <======== now both pointers are set (to same Nym). DONE!
        }
        // --------------------------------------------------------------------------------------------------
        // At this point, pRemover MIGHT be set, or NULL. (And that's that -- pRemover may always be NULL.)
        //
        // if pRemover IS set, then pOriginator MIGHT point to it as well. (If the IDs match. Done above.)
        // pOriginator might also still be NULL. (If pRemover is NULL, then pOriginator DEFINITELY is.)
        // pRemover is loaded (or not). Next let's make SURE pOriginator is loaded, if it wasn't already...
        //
        if (NULL == pOriginator)
        {
            // GetSenderUserID() should be the same on THIS (updated version of the same cron item) 
            // but for whatever reason, I'm checking the userID on the original version. Sue me.
            //
            const OTIdentifier NYM_ID(pOrigCronItem->GetSenderUserID());
            
            theOriginatorNym.SetIdentifier(NYM_ID);  
            
            if (false == theOriginatorNym.LoadPublicKey())
            {
                OTString strNymID(NYM_ID);
                OTLog::vError("OTCronItem::HookRemovalFromCron: Failure loading Sender's public key:\n%s\n", strNymID.Get());
            }		
            else if (theOriginatorNym.VerifyPseudonym() && 
                     theOriginatorNym.LoadSignedNymfile(*pServerNym)) // ServerNym here is merely the signer on this file.
            {
                pOriginator = &theOriginatorNym; //  <=====
            }
            else 
            {
                OTString strNymID(NYM_ID);
                OTLog::vError("OTCronItem::HookRemovalFromCron: Failure verifying Sender's public key or loading signed nymfile: %s\n",
                              strNymID.Get());
            }
        }
        
        // -------------------------------
        
        // pOriginator should NEVER be NULL by this point, unless there was an ERROR in the above block.
        // We even loaded the guy from storage, if we had to.
        //
        if (NULL != pOriginator)
        {
            // Drop the FINAL RECEIPT(s) into the user's inbox(es)!!
            // Pass in strOrigCronItem and lNewTransactionNumber which were obtained above.
            //
            onFinalReceipt(*pOrigCronItem, lNewTransactionNumber, *pOriginator, pRemover);
        }
        else
        {
            OTLog::Error("MAJOR ERROR in OTCronItem::HookRemovalFromCron!! Failed loading Originator Nym for Cron Item.\n");
        }
    }
    
    // -------------------------------------------------------
    // Remove corresponding offer from market, if applicable.
    // 
    onRemovalFromCron();
}


long OTCronItem::GetOpeningNum() const
{
    return GetTransactionNum();
}

long OTCronItem::GetClosingNum() const
{
    return (GetCountClosingNumbers() > 0) ? GetClosingTransactionNoAt(0) : 0; // todo stop hardcoding.
}

// -------------------------------------


/*
 inline const OTIdentifier & GetSenderAcctID()		{ return m_SENDER_ACCT_ID; }
 inline const OTIdentifier & GetSenderUserID()		{ return m_SENDER_USER_ID; }
 */

bool OTCronItem::IsValidOpeningNumber(const long & lOpeningNum) const
{
	if (GetOpeningNum() == lOpeningNum)
		return true;
	
	return false;
}

long OTCronItem::GetOpeningNumber(const OTIdentifier & theNymID) const
{
	const OTIdentifier & theSenderNymID = this->GetSenderUserID();
	
	if (theNymID == theSenderNymID)
		return GetOpeningNum();
	
	return 0;
}


long OTCronItem::GetClosingNumber(const OTIdentifier & theAcctID) const
{
	const OTIdentifier & theSenderAcctID = this->GetSenderAcctID();
	
	if (theAcctID == theSenderAcctID)
		return GetClosingNum();
	
	return 0;
}


// This function is overridden in OTTrade, OTAgreement, and OTSmartContract.
//
// I'm put a default implementation here "Just Because."
//
// This is called by HookRemovalFromCron().
//
void OTCronItem::onFinalReceipt(OTCronItem & theOrigCronItem, 
								const long & lNewTransactionNumber,
                                OTPseudonym & theOriginator,
                                OTPseudonym * pRemover) // may already point to theOriginator... or someone else...
{
    OTCron * pCron  = GetCron();
    OT_ASSERT(NULL != pCron);
    
    OTPseudonym * pServerNym = pCron->GetServerNym();
    OT_ASSERT(NULL != pServerNym);

    // -------------------------------------------------
    
    // The finalReceipt Item's ATTACHMENT contains the UPDATED Cron Item.
    // (With the SERVER's signature on it!)
    //
    OTString strUpdatedCronItem(*this);
    OTString * pstrAttachment=&strUpdatedCronItem;
    
    const OTString strOrigCronItem(theOrigCronItem);
    // -----------------------------------------------------------------

    // First, we are closing the transaction number ITSELF, of this cron item,
    // as an active issued number on the originating nym. (Changing it to CLOSED.)
    //
    // Second, we're verifying the CLOSING number, and using it as the closing number
    // on the FINAL RECEIPT (with that receipt being "InReferenceTo" this->GetTransactionNum())
    //
    const long lOpeningNumber = theOrigCronItem.GetOpeningNum();
    const long lClosingNumber = theOrigCronItem.GetClosingNum();
//  const long lOpeningNumber = theOrigCronItem.GetTransactionNum();
//  const long lClosingNumber = (theOrigCronItem.GetCountClosingNumbers() > 0) ? theOrigCronItem.GetClosingTransactionNoAt(0) : 0;

    const OTString strServerID(GetServerID());

    // -----------------------------------------------------------------
    // I'm ASSUMING here that pRemover is also theOriginator.
    //
    // REMEMBER: Most subclasses will override this method, and THEY
    // are the cases where pRemover is someone other than theOriginator.
    // That's why they have a different version of onFinalReceipt.
    //
    if ((lOpeningNumber > 0) && 
        theOriginator.VerifyIssuedNum(strServerID, lOpeningNumber)) 
    {
        // The Nym (server side) stores a list of all opening and closing cron #s.
        // So when the number is released from the Nym, we also take it off that list.
        //
        std::set<long> & theIDSet = theOriginator.GetSetOpenCronItems();
        theIDSet.erase(lOpeningNumber);
        
        theOriginator.RemoveIssuedNum(*pServerNym, strServerID, lOpeningNumber, false); //bSave=false
        theOriginator.SaveSignedNymfile(*pServerNym);
        
        // the RemoveIssued call means the original transaction# (to find this cron item on cron) is now CLOSED.
        // But the Transaction itself is still OPEN. How? Because the CLOSING number is still signed out.
        // The closing number is also USED, since the NotarizePaymentPlan or NotarizeMarketOffer call, but it
        // remains ISSUED, until the final receipt itself is accepted during a process inbox.
        //
        
        if (false == this->DropFinalReceiptToNymbox(GetSenderUserID(),
                                                    lNewTransactionNumber,
                                                    strOrigCronItem,
                                                    NULL, // note
                                                    pstrAttachment))
        {
            OTLog::Error("OTCronItem::onFinalReceipt:Failure dropping finalReceipt to Nymbox.\n");
        }        
    }
    else
    {
        OTLog::Error("OTCronItem::onFinalReceipt: Failed doing VerifyIssuedNum(theOrigCronItem.GetTransactionNum())\n");
    }
    
    // ------------------------------------------------------------------------
    
    if ((lClosingNumber > 0) && 
        theOriginator.VerifyIssuedNum(strServerID, lClosingNumber)
        ) 
    {        
        // SENDER only. (CronItem has no recipient. That's in the subclass.)
        if (false == this->DropFinalReceiptToInbox(GetSenderUserID(), GetSenderAcctID(),
                                                        lNewTransactionNumber,
                                                        lClosingNumber, // The closing transaction number to put on the receipt.
                                                        strOrigCronItem,
                                                        NULL, // note
                                                        pstrAttachment))
            OTLog::Error("OTCronItem::onFinalReceipt: Failure dropping receipt into inbox.\n");

        // In this case, I'm passing NULL for pstrNote, since there is no note.
        // (Additional information would normally be stored in the note.) 

        // This part below doesn't happen until you ACCEPT the final receipt (when processing your inbox.)
        //
//      theOriginator.RemoveIssuedNum(strServerID, lClosingNumber, true); //bSave=false
    }
    else
    {
        OTLog::Error("OTCronItem::onFinalReceipt: Failed verifying lClosingNumber=theOrigCronItem.GetClosingTransactionNoAt(0)>0 &&  "
                     "theOriginator.VerifyTransactionNum(lClosingNumber)\n");
    }
    // -------------------------------
   
    // QUESTION: Won't there be Cron Items that have no asset account at all?
    // In which case, there'd be no need to drop a final receipt, but I don't think
    // that's the case, since you have to use a transaction number to get onto cron
    // in the first place.
    // -----------------------------------------------------------------
} 



























// This is the "DROPS FINAL RECEIPT" function.
// "Final Receipts" are used by Cron Items, as the last receipt for a given transaction number.
//
/*
 bool DropFinalReceiptToInbox(const OTIdentifier & USER_ID,
            const OTIdentifier & ACCOUNT_ID,
            const long & lNewTransactionNumber,
            const long & lClosingNumber,
            OTString & strOrigCronItem,
            OTString * pstrNote=NULL, 
            OTString * pstrAttachment=NULL);
 */
bool OTCronItem::DropFinalReceiptToInbox(const OTIdentifier & USER_ID,
                                         const OTIdentifier & ACCOUNT_ID,
                                         const long & lNewTransactionNumber,
                                         const long & lClosingNumber,
                                         const OTString & strOrigCronItem,
                                         OTString * pstrNote/*=NULL*/,
                                         OTString * pstrAttachment/*=NULL*/)
{
    OTCron * pCron  = GetCron();
    OT_ASSERT(NULL != pCron);
    
    OTPseudonym * pServerNym = pCron->GetServerNym();
    OT_ASSERT(NULL != pServerNym);
    
    // -----------------------------------------------------
	// Load the inbox in case it already exists.
    OTLedger theInbox (USER_ID, ACCOUNT_ID, GetServerID());
    
    // Inbox will receive notification of something ALREADY DONE.
    bool bSuccessLoading = theInbox.LoadInbox();
    
    // -------------------------------------------------------------------
    // ...or generate it otherwise...
    
    if (true == bSuccessLoading)
        bSuccessLoading		= theInbox.VerifyAccount(*pServerNym);
	else
		OTLog::Error("OTCronItem::DropFinalReceiptToInbox: ERROR loading inbox ledger.\n");
//		OTLog::Error("OTCronItem::DropFinalReceiptToInbox: ERROR loading inbox ledger.\n");
//  else
//		bSuccessLoading		= theInbox.GenerateLedger(ACCOUNT_ID, GetServerID(), OTLedger::inbox, true); // bGenerateFile=true
    
    // --------------------------------------------------------------------
    
    if (false == bSuccessLoading)
    {
        OTLog::Error("ERROR loading or generating an inbox in OTCronItem::DropFinalReceiptToInbox. (FAILED WRITING RECEIPT!!) \n");
        return false;
    }
    else 
    {        
        // Start generating the receipts
        
        OTTransaction * pTrans1	= OTTransaction::GenerateTransaction(theInbox, OTTransaction::finalReceipt, lNewTransactionNumber);        
        // (No need to OT_ASSERT on the above transaction since it occurs in GenerateTransaction().)
        
        // The inbox will get a receipt with the new transaction ID.
        // That receipt has an "in reference to" field containing the original cron item.
        
        // set up the transaction items (each transaction may have multiple items... but not in this case.)
        OTItem * pItem1	= OTItem::CreateItemFromTransaction(*pTrans1, OTItem::finalReceipt);
        
        // This may be unnecessary, I'll have to check CreateItemFromTransaction. I'll leave it for now.
        OT_ASSERT(NULL != pItem1);
        
        pItem1->SetStatus(OTItem::acknowledgement);
                
        // -------------------------------------------------------------
        //
        // Here I make sure that the receipt (the inbox notice) references the
        // transaction number that the trader originally used to issue the cron item...
        // This number is used to match up offers to trades, and used to track all cron items.
        // (All Cron items require a transaction from the user to add them to Cron in the
        // first place.)
        // 
		const long lOpeningNum = GetOpeningNumber(USER_ID);
		
//        pItem1->SetReferenceToNum(lOpeningNum);
        pTrans1->SetReferenceToNum(lOpeningNum);
//      pTrans1->SetReferenceToNum(GetOpeningNum());
        // -------------------------------------------------
        // The reference on the transaction contains an OTCronItem, in this case.
        // The original cron item, versus the updated cron item (which is stored
        // on the finalReceipt item just below here.)
        //
        pTrans1->SetReferenceString(strOrigCronItem);
        // --------------------------------------------
//        pItem1->SetClosingNum(lClosingNumber); // This transaction is the finalReceipt for GetTransactionNum(), as lClosingNumber.
        pTrans1->SetClosingNum(lClosingNumber); // This transaction is the finalReceipt for GetTransactionNum(), as lClosingNumber.
		//
		// NOTE: I COULD look up the closing number by doing a call to this->GetClosingNumber(ACCOUNT_ID);
		// But that is already taken care of where it matters, and passed in here properly already, so it 
		// would be superfluous.
        // -----------------------------------------------------------------
        // The finalReceipt ITEM's NOTE contains the UPDATED CRON ITEM.
        //
        if (NULL != pstrNote)
        {
            pItem1->SetNote(*pstrNote);    // in markets, this is updated trade.        
        }
        
        // Also set the ** UPDATED OFFER ** as the ATTACHMENT on the ** item.** 
        // (With the SERVER's signature on it!) // in markets, this is updated offer.
        //
        if (NULL != pstrAttachment)
        {
            pItem1->SetAttachment(*pstrAttachment); 
        }
        
        // -----------------------------------------------------------------
        // sign the item
        
        pItem1->SignContract(*pServerNym);
        pItem1->SaveContract();
        
        // the Transaction "owns" the item now and will handle cleaning it up.
        pTrans1->AddItem(*pItem1);
        
        pTrans1->SignContract(*pServerNym);
        pTrans1->SaveContract();
        
        // Here the transaction we just created is actually added to the ledger.
        theInbox.AddTransaction(*pTrans1);
        
        // Release any signatures that were there before (They won't
        // verify anymore anyway, since the content has changed.)
        theInbox.ReleaseSignatures();
        
        // Sign and save.
        theInbox.   SignContract(*pServerNym);
        theInbox.	SaveContract();
        
        // TODO: Better rollback capabilities in case of failures here:
        
        // Save both inboxes to storage. (File, DB, wherever it goes.)
        theInbox.	SaveInbox();
        
		// Corresponds to the AddTransaction() just above.
		// Details are stored in separate file these days.
		//
		pTrans1->SaveBoxReceipt(theInbox);
		
        return true;    // Really this true should be predicated on ALL the above functions returning true. Right?
    }                   // ...Right?
    
    return false; // unreachable.
}




// The final receipt doesn't have a closing number in the Nymbox, only in the Inbox.
// That's because in the Nymbox, it's just a notice, and it's not there to enforce anything.
// If you get one in your Nymbox, it's just so that you know to removed its "in ref to" number
// from your issued list (so your balance agreements will work :P)
//
bool OTCronItem::DropFinalReceiptToNymbox(const OTIdentifier & USER_ID,
                                         const long & lNewTransactionNumber,
                                         const OTString & strOrigCronItem,
                                         OTString * pstrNote/*=NULL*/,
                                         OTString * pstrAttachment/*=NULL*/)
{
    OTCron * pCron  = GetCron();
    OT_ASSERT(NULL != pCron);
    
    OTPseudonym * pServerNym = pCron->GetServerNym();
    OT_ASSERT(NULL != pServerNym);
    
    // -----------------------------------------------------
    
    OTLedger theLedger(USER_ID, USER_ID, GetServerID());
    
    // Inbox will receive notification of something ALREADY DONE.
    bool bSuccessLoading = theLedger.LoadNymbox();
    
    // -------------------------------------------------------------------
    // ...or generate it otherwise...
    
    if (true == bSuccessLoading)
        bSuccessLoading		= theLedger.VerifyAccount(*pServerNym);
	else
		OTLog::Error("OTCronItem::DropFinalReceiptToNymbox: Unable to load Nymbox.\n");
//    else
//		bSuccessLoading		= theLedger.GenerateLedger(USER_ID, GetServerID(), OTLedger::nymbox, true); // bGenerateFile=true
    
    // --------------------------------------------------------------------
    
    if (false == bSuccessLoading)
    {
        OTLog::Error("ERROR loading or generating a nymbox in OTCronItem::DropFinalReceiptToNymbox. (FAILED WRITING RECEIPT!!) \n");
        return false;
    }

    // --------------------------------------------------------------------
    
    OTTransaction * pTransaction = OTTransaction::GenerateTransaction(theLedger,
                                                                      OTTransaction::finalReceipt,
                                                                      lNewTransactionNumber);
    
    if (NULL != pTransaction) // The above has an OT_ASSERT within, but I just like to check my pointers.
    {			
        // The nymbox will get a receipt with the new transaction ID.
        // That receipt has an "in reference to" field containing the original cron item.

        
        // set up the transaction items (each transaction may have multiple items... but not in this case.)
        OTItem * pItem1	= OTItem::CreateItemFromTransaction(*pTransaction, OTItem::finalReceipt);
        
        // This may be unnecessary, I'll have to check CreateItemFromTransaction. I'll leave it for now.
        OT_ASSERT(NULL != pItem1);
        
        pItem1->SetStatus(OTItem::acknowledgement);
        
        // -------------------------------------------------------------
        //
//      const long lOpeningNumber = GetTransactionNum(); // Notice I'm actually putting the opening # here...
//
        const long lOpeningNumber = GetOpeningNumber(USER_ID);

        // Here I make sure that the receipt (the nymbox notice) references the
        // transaction number that the trader originally used to issue the cron item...
        // This number is used to match up offers to trades, and used to track all cron items.
        // (All Cron items require a transaction from the user to add them to Cron in the
        // first place.)
        // 
//        pItem1->SetReferenceToNum(lOpeningNumber);	// Notice this same number is set twice (again just below), so might be an opportunity to store something else in one of them.
        pTransaction->SetReferenceToNum(lOpeningNumber);	// Notice this same number is set twice (again just below), so might be an opportunity to store something else in one of them.

        // -------------------------------------------------
        // The reference on the transaction contains an OTCronItem, in this case.
        // The original cron item, versus the updated cron item (which is stored
        // on the finalReceipt item just below here.)
        //
        pTransaction->SetReferenceString(strOrigCronItem);
		
        // --------------------------------------------
		
		// Normally in the Inbox, the "Closing Num" is set to the closing number, in reference to the opening number. (on a finalReceipt)
		// But in the NYMBOX, we are sending the Opening Number in that spot. The purpose is so the client side will know not to use that
		// opening number as a valid transaction # in its transaction statements and balance statements, since the number is now gone.
		// Otherwise the Nym wouldn't know any better, and he'd keep signing for it, and therefore his balance agreements would start to fail.
		//
//		pItem1->SetClosingNum(lOpeningNumber); // This transaction is the finalReceipt for GetTransactionNum(). (Which is also the original transaction number.)
		pTransaction->SetClosingNum(lOpeningNumber); // This transaction is the finalReceipt for GetTransactionNum(). (Which is also the original transaction number.)
        
        // -----------------------------------------------------------------
        // The finalReceipt ITEM's NOTE contains the UPDATED CRON ITEM.
        //
        if (NULL != pstrNote)
        {
            pItem1->SetNote(*pstrNote);    // in markets, this is updated trade.        
        }
        
        // Also set the ** UPDATED OFFER ** as the ATTACHMENT on the ** item.** 
        // (With the SERVER's signature on it!) // in markets, this is updated offer.
        //
        if (NULL != pstrAttachment)
        {
            pItem1->SetAttachment(*pstrAttachment); 
        }
        
        // -----------------------------------------------------------------
        // sign the item
        
        pItem1->SignContract(*pServerNym);
        pItem1->SaveContract();
        
        // the Transaction "owns" the item now and will handle cleaning it up.
        pTransaction->AddItem(*pItem1);
        
        pTransaction->SignContract(*pServerNym);
        pTransaction->SaveContract();
        
        // Here the transaction we just created is actually added to the ledger.
        theLedger.AddTransaction(*pTransaction);
        
        // Release any signatures that were there before (They won't
        // verify anymore anyway, since the content has changed.)
        theLedger.ReleaseSignatures();
        
        // Sign and save.
        theLedger.SignContract(*pServerNym);
        theLedger.SaveContract();
        
        // TODO: Better rollback capabilities in case of failures here:
        
        // Save nymbox to storage. (File, DB, wherever it goes.)
        theLedger.	SaveNymbox();
        
		// This corresponds to the AddTransaction() call just above.
		// These are stored in a separate file now.
		//
		pTransaction->SaveBoxReceipt(theLedger);
		
        return true;    // Really this true should be predicated on ALL the above functions returning true. Right?
    }
    else
        OTLog::Error("Failed trying to create Nymbox in OTCronItem::DropFinalReceiptToNymbox()\n");

    return false; // unreachable.
}



// ****************************************************************



// You usually wouldn't want to use this, since if the transaction failed, the opening number
// is already burned and gone. But there might be cases where it's not, and you want to retrieve it.
// So I added this function for those cases. In most cases, you will prefer HarvestClosingNumbers().
//
void OTCronItem::HarvestOpeningNumber(OTPseudonym & theNym)
{
    // The Nym is the original sender. (If Compares true).
    // IN CASES where GetTransactionNum() isn't already burned, we can harvest it here.
    // Subclasses will have to override this function for recipients, etc.
    //
    if (theNym.CompareID(GetSenderUserID()))
    {
        const OTString strServerID(GetServerID());
		
		if (theNym.VerifyIssuedNum(strServerID, GetOpeningNum())) // we only "add it back" if it was really there in the first place.
			theNym.AddTransactionNum(theNym, strServerID, GetOpeningNum(), true); // bSave=true
    }
}




// This is a good default implementation.
// Also, some subclasses override this, but they STILL CALL IT.
//
void OTCronItem::HarvestClosingNumbers(OTPseudonym & theNym)
{
    // The Nym is the original sender. (If Compares true).
    // GetTransactionNum() is usually already burned, but we can harvest the closing
    // numbers from the "Closing" list, which is only for the sender's numbers.
    // Subclasses will have to override this function for recipients, etc.
    //
    if (theNym.CompareID(GetSenderUserID()))
    {
        const OTString strServerID(GetServerID());
		
        for (int i = 0; i < GetCountClosingNumbers(); i++)
        {
			if (theNym.VerifyIssuedNum(strServerID, GetClosingTransactionNoAt(i))) // we only "add it back" if it was really there in the first place.
				theNym.AddTransactionNum(theNym, strServerID, GetClosingTransactionNoAt(i), 
										 (i == (GetCountClosingNumbers()-1) ? true : false)); // bSave=true only on the last iteration.
//			else 
//				OTLog::vError("OTCronItem::HarvestClosingNumbers: Number (%ld) failed as issued. (Thus didn't bother 'adding it back'.)\n",
//							  GetClosingTransactionNoAt(i));
        }
    }
}



OTCronItem::OTCronItem() : OTTrackable(), m_pCron(NULL), m_CREATION_DATE(0), m_LAST_PROCESS_DATE(0),
    m_PROCESS_INTERVAL(1),  // Default for any cron item is to execute once per second.
    m_bRemovalFlag(false)
{
	InitCronItem();
}


OTCronItem::OTCronItem(const OTIdentifier & SERVER_ID, const OTIdentifier & ASSET_ID) : 
    OTTrackable(SERVER_ID, ASSET_ID),
        m_pCron(NULL), m_CREATION_DATE(0), 
        m_LAST_PROCESS_DATE(0), m_PROCESS_INTERVAL(1), // Default for any cron item is to execute once per second.
        m_bRemovalFlag(false)
{
	InitCronItem();
}

OTCronItem::OTCronItem(const OTIdentifier & SERVER_ID, const OTIdentifier & ASSET_ID,
					   const OTIdentifier & ACCT_ID, const OTIdentifier & USER_ID) : 
    OTTrackable(SERVER_ID, ASSET_ID, ACCT_ID, USER_ID),
        m_pCron(NULL), m_CREATION_DATE(0), 
        m_LAST_PROCESS_DATE(0), m_PROCESS_INTERVAL(1), // Default for any cron item is to execute once per second.
        m_bRemovalFlag(false)

{
	InitCronItem();
}




OTCronItem::~OTCronItem()
{
    // No need to call Release() here, it's handled by the framework.	
}

void OTCronItem::InitCronItem()
{
	m_strContractType.Set("CRONITEM"); // in practice should never appear. Child classes will overwrite.
}


void OTCronItem::ClearClosingNumbers()
{
	m_dequeClosingNumbers.clear();
}

void OTCronItem::Release()
{
	// If there were any dynamically allocated objects, clean them up here.
	
    m_CREATION_DATE = 0;
    m_LAST_PROCESS_DATE = 0;
	m_PROCESS_INTERVAL = 1;
	
    ClearClosingNumbers();
    
    m_bRemovalFlag = false;

    // ----------------------------------
    
	OTTrackable::Release(); // since I've overridden the base class, I call it now...
}



// return -1 if error, 0 if nothing, and 1 if the node was processed.
int OTCronItem::ProcessXMLNode(irr::io::IrrXMLReader*& xml)
{
	int nReturnVal = 0;
    
	// Here we call the parent class first.
	// If the node is found there, or there is some error,
	// then we just return either way.  But if it comes back
	// as '0', then nothing happened, and we'll continue executing.
	//
	// -- Note you can choose not to call the parent if
	// you don't want to use any of those xml tags.
	//
	
	// In this case, I don't need to call the parent. But I'm going to 
	// call the grand-grand-parent (scriptable.)
	//
	nReturnVal = OTScriptable::ProcessXMLNode(xml);
	
	if (nReturnVal != 0) // -1 is error, and 1 is "found it". Either way, return.
		return nReturnVal;	// 0 means "nothing happened, keep going."
    
	// ---------
	
    if (!strcmp("closingTransactionNumber", xml->getNodeName())) 
	{		
        OTString strClosingNumber = xml->getAttributeValue("value");
        
        if (strClosingNumber.Exists())
        {
            const long lClosingNumber = atol(strClosingNumber.Get());					
            
            this->AddClosingTransactionNo(lClosingNumber);
        }
        else
		{
			OTLog::Error("Error in OTCronItem::ProcessXMLNode: closingTransactionNumber field without value.\n");
			return (-1); // error condition
		}
        
		nReturnVal = 1;
	}
     
	return nReturnVal;
}



/*

void OTCronItem::UpdateContents()
{
	
}


bool OTCronItem::SaveContractWallet(std::ofstream & ofs)
{
	return true;
}
*/
