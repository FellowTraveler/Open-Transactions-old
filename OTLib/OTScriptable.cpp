/****************************************************************
 *    
 *  OTScriptable.cpp
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
#include <ctime>

#include <string>
#include <algorithm>


#include "irrxml/irrXML.h"

using namespace irr;
using namespace io;


#include "OTStorage.h"

#include "OTPseudonym.h"
#include "OTTransaction.h"
#include "OTLedger.h"

#include "OTScriptable.h"
#include "OTSmartContract.h"

#include "OTLog.h"



// -----------------------------------------------------------------

// CALLBACKS
//
// The server will call these callbacks, from time to time, and give you the
// opportunity to resolve its questions.


// This script is called by the server, whenever it wants to know whether a
// given party is allowed to execute a specific clause.
//
#ifndef SCRIPTABLE_CALLBACK_PARTY_MAY_EXECUTE
#define SCRIPTABLE_CALLBACK_PARTY_MAY_EXECUTE		"callback_party_may_execute_clause"
#endif

// -----------------------------------------------------------------





OTScriptable * OTScriptable::InstantiateScriptable(const OTString & strInput)
{
	static char		buf[45] = "";
	OTCronItem *	pItem = NULL;
	
	if (!strInput.Exists())
		return NULL;
	
	OTString strContract(strInput);
	
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
		
	// There are actually two factories that load smart contracts. See OTCronItem.
	//
	else if (strFirstLine.Contains("-----BEGIN SIGNED SMARTCONTRACT-----"))  // this string is 36 chars long.
	{	pItem = new OTSmartContract();	OT_ASSERT(NULL != pItem); }
	
	// Coming soon.
//	else if (strFirstLine.Contains("-----BEGIN SIGNED ENTITY-----"))  // this string is 29 chars long.
//	{	pItem = new OTEntity();			OT_ASSERT(NULL != pItem); }

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
// *************************************************************************



//
// VALIDATING IDENTIFIERS IN OTSCRIPTABLE.
//
// Only alphanumerics are valid, or '_' (underscore)
//

bool is_ot_namechar_invalid(char c)
{
	return !(isalnum(c) || (c == '_'));
}

// static
bool OTScriptable::ValidateName(const std::string str_name)
{
	if (str_name.size() <= 0)
	{
		OTLog::Error("OTScriptable::ValidateName: Name has zero size.\n");
		return false;
	}
	else if (find_if(str_name.begin(), str_name.end(), is_ot_namechar_invalid) != str_name.end())
	{
		OTLog::vError("OTScriptable::ValidateName: Name fails validation testing: %s\n",
					 str_name.c_str());
		return false;
	}
	
	return true;
}



// OTSmartContract::RegisterOTNativeCallsWithScript OVERRIDES this, but
// also calls it.
//
void OTScriptable::RegisterOTNativeCallsWithScript(OTScript & theScript)
{
	using namespace chaiscript;
	
	// In the future, this will be polymorphic.
	// But for now, I'm forcing things...
	
	OTScriptChai * pScript = dynamic_cast<OTScriptChai *> (&theScript);
	
	if (NULL != pScript)
	{
		pScript->chai.add(fun(&OTScriptable::GetTime), "get_time");
		// ---------------------------------------------------------------------------------
		pScript->chai.add(fun(&OTScriptable::CanExecuteClause, this), "party_may_execute_clause");		
//		pScript->chai.add(fun(&OTScriptable::CanExecuteClause, (*this)), "party_may_execute_clause");		
	}
//	else if (NULL != (pScript = dynamic_cast<OTScriptSomeOtherScriptingLanguageSubClass_GOES_HERE *> (&theScript)) )
//	{ }
	else 
	{
		OTLog::Error("OTScriptable::RegisterOTNativeCallsWithScript: Failed dynamic casting OTScript to OTScriptChai \n");
	}	
}


//static
std::string OTScriptable::GetTime() // Returns a string, containing seconds as int. (Time in seconds.)
{
	const	time_t	CURRENT_TIME	=	time(NULL);
	const	long	lTime			=	CURRENT_TIME;
	// ----------------------------------
	OTString strTime;
	strTime.Format("%ld", lTime);
	return	strTime.Get();
}


// The server calls this when it wants to know if a certain party is allowed to execute a specific clause.
// This function tries to answer that question by checking for a callback script called callback_party_may_execute_clause
// If the callback exists, then it calls that for the answer. Otherwise the default return value is: true
// Script coders may also call "party_may_execute_clause()" from within a script, which will call this function, 
// which will trigger the script callback_party_may_execute_clause(), etc.
//
bool OTScriptable::CanExecuteClause(const std::string str_party_name, const std::string str_clause_name)
{
//  OTCron * pCron  = GetCron();
//  OT_ASSERT(NULL != pCron);
//  // ----------------------------------
//  OTPseudonym * pServerNym = pCron->GetServerNym();
//  OT_ASSERT(NULL != pServerNym);	
    // -------------------------------------------------

	OTParty		* pParty	= this->GetParty(str_party_name);
	OTClause	* pClause	= this->GetClause(str_clause_name);
	
	if (NULL == pParty)
	{
		OTLog::vOutput(0, "OTScriptable::CanExecuteClause: Unable to find this party: %s\n",
					   str_party_name.size() > 0 ? str_party_name.c_str() : "");
		return false;
	}
	
	if (NULL == pClause)
	{
		OTLog::vOutput(0, "OTScriptable::CanExecuteClause: Unable to find this clause: %s\n",
					   str_clause_name.size() > 0 ? str_clause_name.c_str() : "");
		return false;
	}
	// Below this point, pParty and pClause are both good.
	// -------------------------------------------------
	//
	
	// ...This WILL check to see if pParty has its Opening number verified as issued.
	// (If the opening number is > 0 then VerifyPartyAuthorization() is smart enough to verify it.)
	//
	// To KNOW that a party has the right to even ASK the script to cancel a contract, MEANS that
	// (1) The party is listed as a party on the contract. (2) The party's copy of that contract
	// is signed by the authorizing agent for that party. and (3) The opening transaction number for
	// that party is verified as issued for authorizing agent. (2 and 3 are both performed at the same
	// time, in VerifyPartyAuthorization(), since the agent may need to be loaded in order to verify 
	// them.) 1 is already done by this point, as it's performed above.
	//
	// Todo: notice this code appears in CanCancelContract() (this function) as well as 
	// OTScriptable::CanExecuteClause.
	// Therefore I can see that THIS VERIFICATION CODE WILL GET CALLED EVERY SINGLE TIME THE SCRIPT
	// CALLS ANY CLAUSE OR OT NATIVE FUNCTION.  Since technically this only needs to be verified before the
	// first call, and not for EVERY call during any of a script's runs, I should probably move this verification
	// higher, such as each time the OTCronItem triggers, plus each time a party triggers a clause directly
	// through the API (server message). As long as those are covered, I will be able to remove it from here
	// which should be a significant improvement for performance.
	// It will be at the bottom of those same functions that "ClearTemporaryPointers()" should finally be called.
	//
	// Also todo:  Need to implement MOVE CONSTRUCTORS and MOVE COPY CONSTRUCTORS all over the place,
	// once I'm sure C++0x build environments are available for all of the various OT platforms. That should
	// be another great performance boost!
	//
//	const OTString strServerID(GetServerID());
//	
//	mapOfNyms	map_Nyms_Already_Loaded;
//	this->RetrieveNymPointers(map_Nyms_Already_Loaded);
//	
//	bool bVerifiedAuthorization = 
//		this->VerifyPartyAuthorization(*pParty, *pServerNym, strServerID, &map_Nyms_Already_Loaded);
//	
//	if (!bVerifiedAuthorization)
//	{
//		OTLog::vOutput(0, "OTScriptable::CanExecuteClause: Unable to verify authorization for party: %s\n",
//					   str_party_name.c_str());
//		return false;
//	}
	
	// NOTE (Above):  When it came time to compile, I realized that OTScriptable has no pointer to Cron,
	// nor access to any ServerNym (unless you pass it in).  But I want this function to work by merely
	// passing in 2 strings.
	//
	// SINCE THE PARTY IS VERIFIED ALREADY (WHEN THE SMART CONTRACT IS FIRST ACTIVATED) THEN THIS IS
	// REDUNDANT ANYWAY.
	//
	// IF you ever need to use CanExecuteClause() in some circumstance where the party has NOT been verified
	// anyway (it won't be from within some script...) then just call VerifyPartyAuthorization() yourself in
	// that code, wherever you need to.
	
	// *****************************************************************************
	//
	// DISALLOW parties to directly execute any clauses named similarly to callbacks, hooks, or cron hooks!
	// Only allow this for normal clauses.
	//
	if (str_clause_name.compare(0,5,"cron_") == 0) // todo stop hardcoding
	{
		OTLog::Output(0, "OTScriptable::CanExecuteClause: Parties may not directly trigger clauses beginning in cron_\n");
		return false;
	}
	
	if (str_clause_name.compare(0,5,"hook_") == 0) // todo stop hardcoding
	{
		OTLog::Output(0, "OTScriptable::CanExecuteClause: Parties may not directly trigger clauses beginning in hook_\n");
		return false;
	}
	
	if (str_clause_name.compare(0,9,"callback_") == 0) // todo stop hardcoding
	{
		OTLog::Output(0, "OTScriptable::CanExecuteClause: Parties may not directly trigger clauses beginning in callback_\n");
		return false;
	}
	// *****************************************************************************
	
	// IF NO CALLBACK IS PROVIDED, The default answer to this function is:
	//     YES, this party MAY run this clause!
	//
	// But... first we check to see if this OTScriptable has a clause named:
	//          "callback_party_may_execute_clause"
	// ...and if so, we ask the CALLBACK to make the decision instead. This way, people can define
	// in their own scripts any rules they want about which parties may execute which clauses.
	
	//
	const std::string str_CallbackName(SCRIPTABLE_CALLBACK_PARTY_MAY_EXECUTE);
	
	OTClause * pCallbackClause = this->GetCallback(str_CallbackName); // See if there is a script clause registered for this callback.
	
	if (NULL != pCallbackClause) // Found it!
	{	
		OTLog::vOutput(0, "OTScriptable::CanExecuteClause: Found script for: %s. Asking...\n", 
					   SCRIPTABLE_CALLBACK_PARTY_MAY_EXECUTE);
		
		// The function we're IN defaults to TRUE, if there's no script available.
		// However, if the script is available, then our default return value starts as FALSE.
		// The script itself will then have to set it to true, if that's what it wants.
		//
		OTVariable param1		("param_party_name",  str_party_name,	OTVariable::Var_Constant);
		OTVariable param2		("param_clause_name", str_clause_name,	OTVariable::Var_Constant);
		// -------------------------------------------------------------
		OTVariable theReturnVal	("return_val",		  false);
		// -------------------------------------------------------------		
		mapOfVariables theParameters;
		theParameters.insert(std::pair<std::string, OTVariable *>("param_party_name",  &param1));
		theParameters.insert(std::pair<std::string, OTVariable *>("param_clause_name", &param2));
		
		// ****************************************
		
		if (false == this->ExecuteCallback(*pCallbackClause, theParameters, theReturnVal)) // <============================================
		{
			OTLog::vError("OTScriptable::CanExecuteClause: Error while running callback script %s, clause %s \n",
						  SCRIPTABLE_CALLBACK_PARTY_MAY_EXECUTE, str_clause_name.c_str());
			return false;
		}
		else
		{
			OTLog::vOutput(0, "OTScriptable::CanExecuteClause: Success executing callback script %s, clause: %s.\n\n", 
						   SCRIPTABLE_CALLBACK_PARTY_MAY_EXECUTE, str_clause_name.c_str());
			
			return theReturnVal.CopyValueBool();
		}
		// ****************************************
	}
	else 
	{
		OTLog::vOutput(0, "OTScriptable::CanExecuteClause: Unable to find script for: %s. Therefore, default return value is: TRUE.\n",
					   SCRIPTABLE_CALLBACK_PARTY_MAY_EXECUTE);
	}
	// *****************************************************************************
	
	return true;
}



// Client-side.
// (The server could actually load all the other nyms and accounts,
// and verify their transaction numbers, yadda yadda yadda. But the
// client can only check to see that at least a signed copy is supposedly
// available for every single party.)
//
bool OTScriptable::AllPartiesHaveSupposedlyConfirmed()
{
	FOR_EACH(mapOfParties, m_mapParties)
	{
		OTParty * pParty = (*it).second;
		OT_ASSERT(NULL != pParty);
		// -----------------------
		
		if (!(pParty->GetMySignedCopy().Exists()))
			return false;
	}
	
	return true;
}



bool OTScriptable::ExecuteCallback (OTClause & theCallbackClause, mapOfVariables & theParameters, OTVariable & varReturnVal)
{
	const std::string str_clause_name	= theCallbackClause.GetName().Exists() ? 
											theCallbackClause.GetName().Get() : "";
	OT_ASSERT(OTScriptable::ValidateName(str_clause_name));
	
	OTBylaw * pBylaw = theCallbackClause.GetBylaw();
	OT_ASSERT(NULL != pBylaw);
	// -------------------------------------------------
	// By this point, we have the clause we are executing as theCallbackClause, 
	// and we have the Bylaw it belongs to, as pBylaw.
	// ----------------------------------------
	
	const std::string str_code		=	theCallbackClause.GetCode();	// source code for the script.
	const std::string str_language	=	pBylaw->GetLanguage();			// language it's in. (Default is "chai")
	
	OTScript_SharedPtr pScript = OTScriptFactory(str_code, &str_language);
	
	// ---------------------------------------------------------------
	//
	// SET UP THE NATIVE CALLS, REGISTER THE PARTIES, REGISTER THE VARIABLES, AND EXECUTE THE SCRIPT.
	//
	if (pScript)
	{
		// Register the special server-side native OT calls we make available to all scripts.
		//
		this->RegisterOTNativeCallsWithScript(*pScript); 
		
		// ---------------------------------------
		// Register all the parties with the script.
		//
		FOR_EACH(mapOfParties, m_mapParties)
		{
			const std::string str_party_name	= (*it).first;
			OTParty * pParty					= (*it).second;
			OT_ASSERT((NULL != pParty) && (str_party_name.size() > 0));
			// -----------------------
			
			pScript->AddParty(str_party_name, *pParty);
		}
		// ---------------------------------------
		// Add the parameters...
		//
		FOR_EACH(mapOfVariables, theParameters)
		{
			const std::string str_var_name	= (*it).first;
			OTVariable * pVar				= (*it).second;
			OT_ASSERT((NULL != pVar)&&(str_var_name.size() > 0));
			// ---------------------------------------------------
			pVar->RegisterForExecution(*pScript);
		}
		
		// ---------------------------------------
		// Also need to loop through the Variables on pBylaw and register those as well.
		//
		pBylaw->RegisterVariablesForExecution(*pScript); // This sets all the variables as CLEAN so we can check for dirtiness after execution.
		
		// ****************************************
		
		if (false == pScript->ExecuteScript(&varReturnVal))
		{
			OTLog::vError("OTScriptable::ExecuteCallback: Error while running callback script: clause %s \n",
						 str_clause_name.c_str());
		}
		else
		{
			OTLog::vOutput(0, "OTScriptable::ExecuteCallback: Successfully executed callback script: clause %s.\n\n",
						   str_clause_name.c_str());
			return true;
		}
	}
	// ---------------------------------------------------------------
	else 
	{
		OTLog::Error("OTScriptable::ExecuteCallback: Error instantiating script!!\n");
	}
	
	// ***************************************************************
	
	// NOTE: Normally after calling a script, you want to check to see if any of the persistent variables
	// are dirty, and if important, send a notice to the parties, save an updated copy of the contract, etc.
	// WE DON'T DO THAT FOR CALLBACKS!  Why not?
	//
	// 1) It only matters if the variables change, if you are actually saving an updated version of the contract.
	//    (Which is more OTCronItem / OTSmartContract, which saves an updated copy of itself.) Whereas if you are
	//    NOT saving the contract with those variables in it, then why the hell would you care to notify people?
	// 2) Since only OTCronItem / OTSmartContract actually save updated copies of themselves, they are the only ones
	//    who will ever need to notify anyone. Not EVERY OTScriptable-derived class will send notifications, but if they
	//    need to, SendNoticeToAllParties() is already available on OTScriptable.
	//
	// 3) MOST IMPORTANTLY: the only time a callback is currently triggered is when the script has already been activated
	//    somehow, and the only places that do that ALREADY SEND NOTICES WHEN DIRTY. In fact, if a callback actually makes
	//    the scriptable dirty, IT WILL SEND NOTICES ANYWAY, since the "ExecuteClauses()" function that CALLED the callback
	//    is also smart enough to send the notices already.
	//
	
	return false;
}







bool OTScriptable::SendNoticeToAllParties(OTPseudonym & theServerNym,
										  const OTIdentifier & theServerID,
										  const long & lNewTransactionNumber,
//										  const long & lInReferenceTo,	// Each party has its own opening trans #.
										  const OTString & strReference,
										  OTString * pstrNote/*=NULL*/,
										  OTString * pstrAttachment/*=NULL*/)
{
	bool bSuccess = true;  // Success is defined as ALL parties receiving a notice
	
	FOR_EACH(mapOfParties, m_mapParties)
	{
		OTParty * pParty = (*it).second;
		OT_ASSERT(NULL != pParty);
		// ------------------
		
		if (false == pParty->SendNoticeToParty(theServerNym, theServerID, lNewTransactionNumber, 
//											   lInReferenceTo, // each party has its own opening trans #.
											   strReference, pstrNote, pstrAttachment))
			bSuccess = false; // Notice I don't break here -- I still allow it to notice ALL parties, even if one fails.
	}

	return bSuccess;
}




// TODO: Add a "Notice Number" to OTScriptable and OTVotingGroup. This increments each
// time a notice is sent to the parties, and will be passed in here as a parameter. The nyms
// will all store a map by ServerID, similar to request #, and for each, a list of notice #s
// mapped by the transaction # for each Cron Item the Nym has open. This way the Nym can
// expect to see notice #1, notice #2, etc, to make sure he didn't miss one. They can even
// have a protocol where each notice contains a hash of the previous one, and the users
// (presumably using some future p2p client) can compare hashes with little network cost.
// (This prevents the server from sending a false notice to one party, without having to
// also falsify all subsequent hashes / notices, since all future hashes will now fail to 
// match.) The hashes can also be made public if people prefer, as a way of "publicly
// posting" the hash of the notice ...without in any way revealing the notice contents.
// 
//
bool OTScriptable::DropServerNoticeToNymbox(OTPseudonym & theServerNym,
											const OTIdentifier & SERVER_ID,
											const OTIdentifier & USER_ID,
											const long & lNewTransactionNumber,
											const long & lInReferenceTo,
											const OTString & strReference,
											OTString * pstrNote/*=NULL*/,
											OTString * pstrAttachment/*=NULL*/)
{
    OTLedger theLedger(USER_ID, USER_ID, SERVER_ID);
    
    // Inbox will receive notification of something ALREADY DONE.
	//
    bool bSuccessLoading = theLedger.LoadNymbox();
    
    // -------------------------------------------------------------------
    // ...or generate it otherwise...
    
    if (true == bSuccessLoading)
        bSuccessLoading		= theLedger.VerifyAccount(theServerNym);
    else
		bSuccessLoading		= theLedger.GenerateLedger(USER_ID, SERVER_ID, OTLedger::nymbox, true); // bGenerateFile=true
    
    // --------------------------------------------------------------------
    
    if (false == bSuccessLoading)
    {
        OTLog::Error("ERROR loading or generating a nymbox in OTScriptable::DropServerNoticeToNymbox. (FAILED WRITING RECEIPT!!) \n");
        return false;
    }
	
    // --------------------------------------------------------------------
    
    OTTransaction * pTransaction = OTTransaction::GenerateTransaction(theLedger,
                                                                      OTTransaction::notice,
                                                                      lNewTransactionNumber);
    
    if (NULL != pTransaction) // The above has an OT_ASSERT within, but I just like to check my pointers.
    {			
        // The nymbox will get a receipt with the new transaction ID.
        // That receipt has an "in reference to" field containing the original OTScriptable
		
        
        // set up the transaction items (each transaction may have multiple items... but not in this case.)
		//
        OTItem * pItem1	= OTItem::CreateItemFromTransaction(*pTransaction, OTItem::notice);
        
        // This may be unnecessary, I'll have to check CreateItemFromTransaction. I'll leave it for now.
        OT_ASSERT(NULL != pItem1);
        
        pItem1->SetStatus(OTItem::acknowledgement);
        
        // -------------------------------------------------------------
        //
        // Here I make sure that the receipt (the nymbox notice) references the
        // transaction number that the trader originally used to issue the cron item...
        // This number is used to match up offers to trades, and used to track all cron items.
        // (All Cron items require a transaction from the user to add them to Cron in the
        // first place.)
        // 
        pTransaction->SetReferenceToNum(lInReferenceTo);
        // -------------------------------------------------
        // The reference on the transaction probably contains a the original cron item or entity contract.
        // Versus the updated item (which, if it exists, is stored on the pItem1 just below.)
        //
        pTransaction->SetReferenceString(strReference);
        // --------------------------------------------
		//
        // The notice ITEM's NOTE probably contains the UPDATED SCRIPTABLE (usually a CRON ITEM. But maybe soon: Entity)
        //
        if (NULL != pstrNote)
        {
            pItem1->SetNote(*pstrNote);    // in markets, this is updated trade.        
        }
        
        // Nothing is special stored here so far for OTTransaction::notice, but the option is always there.
        //
        if (NULL != pstrAttachment)
        {
            pItem1->SetAttachment(*pstrAttachment); 
        }
        
        // -----------------------------------------------------------------
        // sign the item
        
        pItem1->SignContract(theServerNym);
        pItem1->SaveContract();
        
        // the Transaction "owns" the item now and will handle cleaning it up.
        pTransaction->AddItem(*pItem1);
        
        pTransaction->SignContract(theServerNym);
        pTransaction->SaveContract();
        
        // Here the transaction we just created is actually added to the ledger.
        theLedger.AddTransaction(*pTransaction);
        
        // Release any signatures that were there before (They won't
        // verify anymore anyway, since the content has changed.)
        theLedger.ReleaseSignatures();
        
        // Sign and save.
        theLedger.SignContract(theServerNym);
        theLedger.SaveContract();
        
        // TODO: Better rollback capabilities in case of failures here:
        
        // Save both inboxes to storage. (File, DB, wherever it goes.)
        theLedger.	SaveNymbox();
        
		// Corresponds to the AddTransaction() call just above. These
		// are stored in a separate file now.
		//
		pTransaction->SaveBoxReceipt(theLedger);
		
        return true;    // Really this true should be predicated on ALL the above functions returning true. Right?
    }
    else
        OTLog::Error("Failed trying to create Nymbox in OTScriptable::DropServerNoticeToNymbox()\n");
	
    return false; // unreachable.
}









// So you can tell if any persistent or important variables have CHANGED since it was last set clean.
//
bool OTScriptable::IsDirty() const
{
	bool bIsDirty = false;
	
	FOR_EACH_CONST(mapOfBylaws, m_mapBylaws)
	{
		OTBylaw * pBylaw = (*it).second;
		OT_ASSERT(NULL != pBylaw);
		// ---------------------------------------------------		
		//
		if (pBylaw->IsDirty())
		{
			bIsDirty = true;
			break;
		}		
	}
	
	return bIsDirty;
}

// So you can tell if ONLY the IMPORTANT variables have CHANGED since it was last set clean.
//
bool OTScriptable::IsDirtyImportant() const
{	
	bool bIsDirty = false;
	
	FOR_EACH_CONST(mapOfBylaws, m_mapBylaws)
	{
		OTBylaw * pBylaw = (*it).second;
		OT_ASSERT(NULL != pBylaw);
		// ---------------------------------------------------		
		//
		if (pBylaw->IsDirtyImportant())
		{
			bIsDirty = true;
			break;
		}		
	}
	
	return bIsDirty;	
}

// Sets the variables as clean, so you can check later and see if any have been changed (if it's DIRTY again.)
//
void OTScriptable::SetAsClean()
{
	FOR_EACH(mapOfBylaws, m_mapBylaws)
	{
		OTBylaw * pBylaw = (*it).second;
		OT_ASSERT(NULL != pBylaw);
		// ---------------------------------------------------		
		//
		pBylaw->SetAsClean(); // so we can check for dirtiness later, if it's changed.
	}
}


// Note: this maybe would have been more appropriate on OTSmartContract, since that is
// where the opening/closing numbers are actually USED. But still, they ARE stored HERE,
// so I might as well put the function here also. That way later on, if some new subclass
// uses those numbers, it will have access to count them as well.
//
// Returns 0 if this agent is not the authorizing agent for a party, and is also not the
// authorized agent for any party's accounts.
//
int	OTScriptable::GetCountTransNumsNeededForAgent(const std::string str_agent_name)
{
	int nReturnVal = 0;

	OTAgent * pAgent = this->GetAgent(str_agent_name);
	if (NULL == pAgent)
		return nReturnVal;	// (Looks like there is no agent with that name.)
		
	// Below this point, pAgent is good, meaning str_agent_name really IS 
	// a legit agent for this party. But that doesn't necessarily mean the
	// agent has to supply any opening or closing transaction #s for this
	// smart contract. That's only true if he's the AUTHORIZING agent for
	// the party (for the opening num) or the authorized agent for any of
	// party's accounts (for the closing number).  So let's add it up...
	//
	if (pAgent->IsAuthorizingAgentForParty())	// true/false whether THIS agent is the authorizing agent for his party.
		nReturnVal++;
	
	// Add the number of accounts, owned by this agent's party, that this agent is the authorized agent FOR.
	//
	nReturnVal += pAgent->GetCountAuthorizedAccts();		
	
	return nReturnVal;
}



// ---------------------------------------------------------------------------------	


OTPartyAccount * OTScriptable::GetPartyAccount(const std::string str_acct_name)
{
	if (false == OTScriptable::ValidateName(str_acct_name)) // this logs, FYI.
	{
		OTLog::Error("OTScriptable::GetPartyAccount:  Error: invalid name.\n");
		return NULL;
	}
	// ----------------------------------------
	
//	OTLog::vError("DEBUGGING OTScriptable::GetPartyAccount: above loop. str_acct_name: %s \n", str_acct_name.c_str());
	
	FOR_EACH(mapOfParties, m_mapParties)
	{
		OTParty * pParty = (*it).second;
		OT_ASSERT(NULL != pParty);
		// -------------------------
		
//		OTLog::vError("DEBUGGING OTScriptable::GetPartyAccount: loop iteration. party name: %s \n", pParty->GetPartyName().c_str());
		
		OTPartyAccount * pAcct = pParty->GetAccount(str_acct_name);
		
		if (NULL != pAcct) // found it.
			return pAcct;
	}
	
//	OTLog::Error("DEBUGGING OTScriptable::GetPartyAccount: below loop \n");
	
	return NULL;		
}


OTPartyAccount * OTScriptable::GetPartyAccountByID(const OTIdentifier & theAcctID) const
{
	FOR_EACH_CONST(mapOfParties, m_mapParties)
	{
		OTParty * pParty = (*it).second;
		OT_ASSERT(NULL != pParty);
		// -------------------------
		
		OTPartyAccount * pAcct = pParty->GetAccountByID(theAcctID);
		
		if (NULL != pAcct) // found it.
			return pAcct;
	}
	
	return NULL;			
}


/*
 bool HasAgent(OTPseudonym & theNym, OTAgent ** ppAgent=NULL) const; // If Nym is agent for Party, set agent's pointer to Nym and return true.
 bool HasAgentByNymID(OTIdentifier & theNymID, OTAgent ** ppAgent=NULL) const;
 // ------------------------------------
 bool HasAuthorizingAgent(OTPseudonym & theNym, OTAgent ** ppAgent=NULL) const; 
 bool HasAuthorizingAgentByNymID(OTIdentifier & theNymID, OTAgent ** ppAgent=NULL) const; // ppAgent lets you get the agent ptr if it was there.
 // ------------------------------------ 
 */

/*
OTParty * FindPartyBasedOnNymIDAsAgent(const OTIdentifier & theNymID, OTAgent ** ppAgent=NULL);
OTParty * FindPartyBasedOnNymIDAsAuthAgent(const OTIdentifier & theNymID, OTAgent ** ppAgent=NULL);
OTParty * FindPartyBasedOnAccountID(const OTIdentifier & theAcctID, OTPartyAccount ** ppPartyAccount=NULL);
*/

OTParty * OTScriptable::FindPartyBasedOnNymIDAsAgent(const OTIdentifier & theNymID, OTAgent ** ppAgent/*=NULL*/) const
{
	FOR_EACH_CONST(mapOfParties, m_mapParties)
	{
		OTParty * pParty = (*it).second;
		OT_ASSERT(NULL != pParty);
		// -----------------------
		
		if (pParty->HasAgentByNymID(theNymID, ppAgent))
			return pParty;
	}
	return NULL;
}



OTParty * OTScriptable::FindPartyBasedOnNymIDAsAuthAgent(const OTIdentifier & theNymID, OTAgent ** ppAgent/*=NULL*/)
{
	FOR_EACH(mapOfParties, m_mapParties)
	{
		OTParty * pParty = (*it).second;
		OT_ASSERT(NULL != pParty);
		// -----------------------
		
		if (pParty->HasAuthorizingAgentByNymID(theNymID, ppAgent))
			return pParty;
	}
	return NULL;
}


OTParty * OTScriptable::FindPartyBasedOnAccountID(const OTIdentifier & theAcctID, OTPartyAccount ** ppPartyAccount/*=NULL*/)
{
	FOR_EACH(mapOfParties, m_mapParties)
	{
		OTParty * pParty = (*it).second;
		OT_ASSERT(NULL != pParty);
		// -----------------------
		
		if (pParty->HasAccountByID(theAcctID, ppPartyAccount))
		{
			return pParty;
		}
	}
	return NULL;
}

// ---------------------------------------------------

OTParty * OTScriptable::FindPartyBasedOnNymAsAgent(OTPseudonym & theNym, OTAgent ** ppAgent/*=NULL*/)
{
	FOR_EACH(mapOfParties, m_mapParties)
	{
		OTParty * pParty = (*it).second;
		OT_ASSERT(NULL != pParty);
		// -----------------------
		
		if (pParty->HasAgent(theNym, ppAgent))
			return pParty;
	}
	return NULL;
}



OTParty * OTScriptable::FindPartyBasedOnNymAsAuthAgent(OTPseudonym & theNym, OTAgent ** ppAgent/*=NULL*/)
{
	FOR_EACH(mapOfParties, m_mapParties)
	{
		OTParty * pParty = (*it).second;
		OT_ASSERT(NULL != pParty);
		// -----------------------
		
		if (pParty->HasAuthorizingAgent(theNym, ppAgent))
			return pParty;
	}
	return NULL;
}


OTParty * OTScriptable::FindPartyBasedOnAccount(OTAccount & theAccount, OTPartyAccount ** ppPartyAccount/*=NULL*/)
{
	FOR_EACH(mapOfParties, m_mapParties)
	{
		OTParty * pParty = (*it).second;
		OT_ASSERT(NULL != pParty);
		// -----------------------
		
		if (pParty->HasAccount(theAccount, ppPartyAccount))
		{
			return pParty;
		}
	}
	return NULL;
}
// ---------------------------------------------------


void OTScriptable::RetrieveNymPointers(mapOfNyms & map_Nyms_Already_Loaded)
{
	FOR_EACH(mapOfParties, m_mapParties)
	{
		OTParty * pParty = (*it).second;
		OT_ASSERT(NULL != pParty);
		// -----------------------
		
		pParty->RetrieveNymPointers(map_Nyms_Already_Loaded);
	}	
}




/*
 -- Load up the authorizing agent's Nym, if not already loaded. (Why? To verifySignature. Also, just to have
 it loaded so I don't have to load it twice in case it's needed for verifying one/some of the accts.) So really:
 -- Verify each party, that the authorizing agent and signature are all good. (I think I have this already...)
 -- Definitely during this, need to make sure that the contents of the signed version match the contents of the main version, for each signer.
 -- Verify that the authorizing agent actually has the opening transaction # for the party issued to him. (Do I have this?....) 
 */

// OTScriptable::VerifyPartyAuthorization
// Similar to VerifyNymAsAgent, except it doesn't ClearTemporaryPointers.
// (If it has to Load the authorizing agent, then it will clear that one.)
// It also doesn't START with a Nym, per se, but rather starts from the Party.
// Though it still allows the possibility that the Nym is already loaded.
// I basically wrote RetrieveNymPointers() (above) so I could call it in here.
// This function is for cases where the Nym very well may NOT be loaded yet,
// BUT THAT WHETHER IT IS, OR NOT, IT *DEFINITELY* DOESN'T CLEAR OUT THE ONES
// THAT *ARE* THERE OTHER THAN WHICHEVER ONES IT IS FORCED TO LOAD ITSELF.
// (This is in contrast to VerifyNymAsAgent(), which calls ClearTemporaryPointers()
// religiously.)
//
// This function also verifies the opening transactions # for the party, whereas
// VerifyNymAsAgent doesn't. ACTUALLY WAIT -- There IS no opening transaction #
// except for OTCronItem-derived objects (OTSmartContract for example...)
// So perhaps that will have to go OUTSIDE of this function after all!
// Therefore I'll make a separate function for that that I can call along with 
// this one. (Like how I do in OTSmartContract::CanCancelContract)
//
// No again -- Because it's in HERE that I actually have the authorizing agent
// loaded. I certainly don't want to just have to load him up again. Therefore I
// have to use a new rule:  IN THIS FUNCTION, if the party HAS an Opening Number,
// THEN IT MUST VERIFY. Since the default value is 0, then that should work, since
// I'm always verifying the number as long as one is there.
//
bool OTScriptable::VerifyPartyAuthorization(OTParty			& theParty,		// The party that supposedly is authorized for this supposedly executed agreement.
											OTPseudonym		& theSignerNym,	// For verifying signature on the authorizing Nym, when loading it
											const OTString	& strServerID, // For verifying issued num, need the serverID the # goes with.
											mapOfNyms		* pmap_ALREADY_LOADED/*=NULL*/, // If some nyms are already loaded, pass them here so we don't load them twice on accident.
											const bool		  bBurnTransNo/*=false*/) // In OTServer::VerifySmartContract(), it not only wants to verify the # is properly issued, but it additionally wants to see that it hasn't been USED yet -- AND it wants to burn it, so it can't be used again!  This bool allows you to tell the function whether or not to do that.
{
	// This function DOES assume that theParty was initially FOUND on OTScriptable.
	// Meaning I don't have to verify that much if I got this far.
	// --------------------------------------------------
	
	// This party hasn't signed the contract??
	//
	if (false == theParty.GetMySignedCopy().Exists())
	{
		OTLog::Output(0, "OTScriptable::VerifyPartyAuthorization: Unable to find party's "
					  "signed copy of this contract. Has it been executed?\n");
		return false;
	}
	
	// By this point, we know that theParty has a signed copy of the agreement (or of SOMETHING anyway) and we know that
	// we were able to find the party based on theNym as one of its agents. But the signature still needs to be verified...
	
	// (2)
	// This step verifies that the party has been signed by its authorizing agent. (Who may not be the Nym, yet might be.)
	//
	OTAgent		* pAuthorizingAgent = NULL;
	OTPseudonym * pAuthAgentsNym	= NULL;
	OTCleanup<OTPseudonym> theAgentNymAngel; // In case I have to load it myself, I want it cleaned up properly.
	
	// Some nyms are *already* loaded. If any were passed in, let's see if any of them are 
	// the authorizing agent for the contract (for this party)...
	//
	if (NULL  != pmap_ALREADY_LOADED) 
	{
		// (So we don't load it twice, if it's there.)
		//
		mapOfNyms & map_Nyms_Already_Loaded = (*pmap_ALREADY_LOADED);
		
		FOR_EACH(mapOfNyms, map_Nyms_Already_Loaded)
		{
			OTPseudonym * pNym = (*it).second;
			OT_ASSERT(NULL != pNym);
			// -----------------------------
			
			if (theParty.HasAuthorizingAgent(*pNym, &pAuthorizingAgent))
			{
				pAuthAgentsNym = pNym; // Just in case
				break;
			}
		}
		// if pAuthorizingAgent != NULL, that means the authorizing agent was found among the map of nyms that were already loaded.
	}
	// -------------------------------------------------------------------------------------
	// Only if I had to load the authorizing agent myself, do I clear its temporary pointer.
	// (Because it's going out of scope at the bottom of this function.)
	// Any other temporary pointers, I do NOT clear, but I leave them because a script is
	// probably executing and may still need them.
	// (This function that we're in was expressly called by someone who didn't want the 
	// temporary nym pointers cleared just yet, for whatever reason.)
	//
	bool bHadToLoadItMyself = (NULL == pAuthorizingAgent) ? true : false;
	
	// Still not found? Okay, let's load it up then...
	//
	if (bHadToLoadItMyself)
	{
		// Of all of a party's Agents, the "authorizing agent" is the one who originally activated
		// the agreement for this party (and fronted the opening trans#.) Since we need to verify his
		// signature, we have to load him up.
		// 
		pAuthAgentsNym = theParty.LoadAuthorizingAgentNym(theSignerNym, &pAuthorizingAgent);
		
		if (NULL != pAuthAgentsNym) // success
		{
			OT_ASSERT(NULL != pAuthorizingAgent); // This HAS to be set now. I assume it henceforth.
			OTLog::vOutput(0, "OTScriptable::VerifyPartyAuthorization: I just had to load "
						   "the authorizing agent's Nym for a party (%s), "
						   "so I guess it wasn't already available on the list of "
						   "Nyms that were already loaded.\n", theParty.GetPartyName().c_str());
			theAgentNymAngel.SetCleanupTarget(*pAuthAgentsNym);  // CLEANUP!!
		}
		else 
		{
			OTLog::Error("OTScriptable::VerifyPartyAuthorization: Error: Strange, unable to load authorizing "
						 "agent's Nym (to verify his signature.)\n");
			return false;
		}
	}
	
	// Below this point, we KNOW that pAuthorizingAgent is a good pointer and will be cleaned up properly/automatically.
	// I'm not using pAuthAgentsNym directly, but pAuthorizingAgent WILL use it before this function is done.
	// -----------------------------------------
	
	// (3) Verify the issued number, if he has one. If this instance is OTScriptable-derived, but NOT OTCronItem-derived,
	//     then that means there IS NO opening number (or closing number) since we're not even on Cron. The parties just
	//     happen to store their opening number for the cases where we ARE on Cron, which will probably be most cases.
	//     Therefore we CHECK TO SEE if the opening number is NONZERO -- and if so, we VERIFY ISSUED on that #. That way,
	//     for cases where this IS a cron item, it will still verify the number (as it should) and in other cases, it will
	//     just skip this step.
	//
	
	const long lOpeningNo = theParty.GetOpeningTransNo();

	if (lOpeningNo > 0) // If one exists, then verify it.
	{
		if (false == pAuthorizingAgent->VerifyIssuedNumber(lOpeningNo, strServerID))
		{
			OTLog::vError("OTScriptable::VerifyPartyAuthorization: Opening trans number %ld doesn't "
						  "verify for the nym listed as the authorizing agent for party %s.\n", lOpeningNo, 
						  theParty.GetPartyName().c_str());
			if (bHadToLoadItMyself)
				pAuthorizingAgent->ClearTemporaryPointers(); // We loaded the Nym ourselves, which goes out of scope after this function. 				
			return false;			
		}
		// --------------------------------------
		// The caller wants the additional verification that the number hasn't been USED 
		// yet -- AND the caller wants you to BURN IT HERE.
		else if (bBurnTransNo)  
		{
			if (false == pAuthorizingAgent->VerifyTransactionNumber(lOpeningNo, strServerID))
			{
				OTLog::vError("OTScriptable::VerifyPartyAuthorization: Opening trans number %ld doesn't "
							  "verify as available for use, for the nym listed as the authorizing agent for party: %s.\n", lOpeningNo, 
							  theParty.GetPartyName().c_str());
				if (bHadToLoadItMyself)
					pAuthorizingAgent->ClearTemporaryPointers(); // We loaded the Nym ourselves, which goes out of scope after this function. 				
				return false;			
			}
			else // SUCCESS -- It verified as available, so let's burn it here. (So he can't use it twice. It remains issued and open until the cron item is eventually closed out for good.)
			{				
				pAuthorizingAgent->RemoveTransactionNumber(lOpeningNo, strServerID, theSignerNym, true); // bSave=true
//				pAuthAgentsNym->RemoveTransactionNum(theSignerNym, strServerID, lOpeningNo); // server removes spent number from nym file. Saves.
			}
		}
		// ---------------------
	} // if lOpeningNo>0
	else if (bBurnTransNo)  // In this case, bBurnTransNo=true, then the caller EXPECTED to burn a transaction
	{						// num. But the number was 0! Therefore, FAILURE!
		OTLog::vOutput(0, "OTScriptable::VerifyPartyAuthorization: FAILURE. On Party %s, expected to burn a legitimate opening transaction "
					   "number, but got this instead: %ld\n", theParty.GetPartyName().c_str(), lOpeningNo);
		if (bHadToLoadItMyself)
			pAuthorizingAgent->ClearTemporaryPointers(); // We loaded the Nym ourselves, which goes out of scope after this function. 				
		return false;
	}
	
	// ----------------------------------------------
	//
	// (4) 
	// Here, we use the Authorizing Agent to verify the signature on his party's version of the contract.
	// Notice: Even if the authorizing agent gets fired, we can still load his Nym to verify the original signature on the
	// original contract! We should ALWAYS be able to verify our signatures!  Therefore, TODO: When a Nym is DELETED, it's necessary
	// to KEEP the public key on file. We may not have a Nymfile with any request #s or trans# signed out, and there are may be no
	// accounts for him, but we still need that public key, for later verification of the signature.
	// UNLESS... the public key ITSELF is stashed into the contract... Notice that normal asset contracts already keep the keys inside,
	// so why shouldn't these? In fact I can pop the "key" value onto the contract as part of the "Party-Signing" API call. Just grab the
	// public key from each one. Meanwhile the server can verify that it's actually there, and refuse to process without it!!  Nice.
	// This also shows why we need to store the NymID, even if it can be overridden by a Role: because you want to be able to verify
	// the original signature, no matter WHO is authorized now. Otherwise your entire contract falls apart.
	
	OTScriptable * pPartySignedCopy = OTScriptable::InstantiateScriptable(theParty.GetMySignedCopy());
	OTCleanup<OTScriptable> theCopyAngel;
	
	if (NULL == pPartySignedCopy)
	{
		OTLog::Error("OTScriptable::VerifyPartyAuthorization: Error loading party's signed copy of agreement. Has it been executed?\n");
		if (bHadToLoadItMyself)
			pAuthorizingAgent->ClearTemporaryPointers(); 
		return false;
	}
	else
	{
		theCopyAngel.SetCleanupTarget(*pPartySignedCopy);
	}	
	// ----------------------------------------------
	
	const bool bSigVerified = pAuthorizingAgent->VerifySignature(*pPartySignedCopy);
//	const bool bSigVerified = pPartySignedCopy->VerifySignature(*pAuthAgentsNym);
	bool bContentsVerified = false;
	
	if (bSigVerified)
	{
		// Todo OPTIMIZE: Might move this call to a higher layer, so it gets called MUCH less often but retains the same security.
		// There are several places currently in smart contracts like this.
		// Need to analyze security aspects before doing it.
		//
		bContentsVerified = this->Compare(*pPartySignedCopy); // This also compares the opening / closing numbers, if they are non-zero.
		
		if (!bContentsVerified)
			OTLog::vOutput(0, "OTScriptable::VerifyPartyAuthorization: Though the signature verifies, the contract "
						   "signed by the party (%s) doesn't match this contract. (Failed comparison.)\n",
						   theParty.GetPartyName().c_str());
	}
	else
		OTLog::vOutput(0, "OTScriptable::VerifyPartyAuthorization: Signature failed to verify for party: %s \n",
					   theParty.GetPartyName().c_str());
	
	// ----------------------------------------------
	
	if (bHadToLoadItMyself)
		pAuthorizingAgent->ClearTemporaryPointers(); // We loaded the Nym ourselves, which goes out of scope after this function. 
	//The party is done with it now, and we don't want it to keep pointing to something that is now going out of scope.
	
	return bContentsVerified;
}


// Kind of replaces VerifySignature() in certain places. It still verifies signatures inside, but
// OTTrade and OTAgreement have a much simpler way of doing that than OTScriptable/OTSmartContract.
//
// This function also loads its own versions of certain nyms, when necessary, and cleans the pointers
// when it's done.
//
bool OTScriptable::VerifyNymAsAgent(OTPseudonym & theNym,  
									OTPseudonym & theSignerNym, 
									mapOfNyms	* pmap_ALREADY_LOADED/*=NULL*/)
{
	// (COmmented out) existing trades / payment plans on OT basically just have this one line:
	//
	// this->VerifySignature(theNym)
	
	// ----------------------------------------------------
	// NEW VERSION:
	/*
	 Proves the original party DOES approve of Nym:
	 
	 1) Lookup the party for this Nym, (loop to see if Nym is listed as an agent by any party.)
	 2) If party found, lookup authorizing agent for party, loading him if necessary.
	 3) Use authorizing agent to verify signature on original copy of this contract. Each party stores their
	    own copy of the agreement, therefore use that copy to verify signature, instead of the current version.
	 
	 This proves that the original authorizing agent for the party that lists Nym as an agent HAS signed the smart contract.
	 (As long as that same party OWNS the account, that should be fine.)
	 Obviously the best proof is to verify the ORIGINAL version of the contract against the PARTY'S ORIGINAL SIGNED COPY,
	 and also to verify them AGAINST EACH OTHER.  The calling function should do this. Otherwise what if the "authorized signer"
	 has been changed, and some new guy and signature are substituted? Well, I guess as long as he really is authorized... but
	 you simply don't know what the original agreement really says unless you look at it.  So load it and use it to call THIS METHOD.
	 */
	
	// (1)
	// This step verifies that theNym is at least REGISTERED as a valid agent for the party. (According to the party.)
	//
	OTParty * pParty = this->FindPartyBasedOnNymAsAgent(theNym);
	
	if (NULL == pParty)
	{
		OTLog::Output(0, "OTScriptable::VerifyNymAsAgent: Unable to find party based on Nym as agent.\n");
		return false;
	}
	// Below this point, pParty is good.
	// --------------------------------------------------
	
	// This party hasn't signed the contract??
	//
	if (false == pParty->GetMySignedCopy().Exists())
	{
		OTLog::vOutput(0, "OTScriptable::VerifyNymAsAgent: Unable to find party's (%s) signed copy of "
					   "this contract. Has it been executed?\n", pParty->GetPartyName().c_str());
		return false;
	}
	
	// By this point, we know that pParty has a signed copy of the agreement (or of SOMETHING anyway) and we know that
	// we were able to find the party based on theNym as one of its agents. But the signature still needs to be verified...
	
	// (2)
	// This step verifies that the party has been signed by its authorizing agent. (Who may not be the Nym, yet might be.)
	//
	OTAgent		* pAuthorizingAgent = NULL;
	OTPseudonym * pAuthAgentsNym	= NULL;
	OTCleanup<OTPseudonym> theAgentNymAngel;
	
	// See if theNym is the authorizing agent.
	//
	if ((false == pParty->HasAuthorizingAgent(theNym, &pAuthorizingAgent)) && 
		(NULL  != pmap_ALREADY_LOADED))
	{
		// No? Okay then, let's see if the authorizing agent is one of these already loaded.
		// (So we don't load it twice.)
		//
		mapOfNyms & map_Nyms_Already_Loaded = (*pmap_ALREADY_LOADED);
		FOR_EACH(mapOfNyms, map_Nyms_Already_Loaded)
		{
			OTPseudonym * pNym = (*it).second;
			OT_ASSERT(NULL != pNym);
			// -----------------------------
			
			if (pParty->HasAuthorizingAgent(*pNym, &pAuthorizingAgent))
			{
				pAuthAgentsNym = pNym; // Just in case.
				break;
			}		
		}
		// if pAuthorizingAgent != NULL, that means the authorizing agent was found among the map of nyms that were already loaded.
	}
	
	// Still not found?
	if (NULL == pAuthorizingAgent)
	{
		// Of all of a party's Agents, the "authorizing agent" is the one who originally activated
		// the agreement for this party (and fronted the opening trans#.) Since we need to verify his
		// signature, we have to load him up.
		// 
		pAuthAgentsNym = pParty->LoadAuthorizingAgentNym(theSignerNym, &pAuthorizingAgent);
		
		if (NULL != pAuthAgentsNym) // success
		{
			OT_ASSERT(NULL != pAuthorizingAgent); // This HAS to be set now. I assume it henceforth.
			OTLog::vOutput(3, "OTScriptable::VerifyNymAsAgent: I just had to load the authorizing agent's Nym for a party (%s), "
						  "so I guess it wasn't already available on the list of Nyms that were already loaded.\n",
						   pParty->GetPartyName().c_str());
			theAgentNymAngel.SetCleanupTarget(*pAuthAgentsNym);  // CLEANUP!!
		}
		else 
		{
			OTLog::vError("OTScriptable::VerifyNymAsAgent: Error: Strange, unable to load authorizing "
						 "agent's Nym for party %s (to verify his signature.)\n", pParty->GetPartyName().c_str());
			pParty->ClearTemporaryPointers();
			return false;
		}
	}

	// Below this point, we KNOW that pAuthorizingAgent is a good pointer and will be cleaned up properly/automatically.
	// I'm not using pAuthAgentsNym directly, but pAuthorizingAgent WILL use it before this function is done.
	// -----------------------------------------
	
	// TODO: Verify the opening transaction # here, like I do in VerifyPartyAuthorization() ??  Research first.
	
	// (3) 
	// Here, we use the Authorizing Agent to verify the signature on his party's version of the contract.
	// Notice: Even if the authorizing agent gets fired, we can still load his Nym to verify the original signature on the
	// original contract! We should ALWAYS be able to verify our signatures!  Therefore, TODO: When a Nym is DELETED, it's necessary
	// to KEEP the public key on file. We may not have a Nymfile with any request #s or trans# signed out, and there are may be no
	// accounts for him, but we still need that public key, for later verification of the signature.
	// UNLESS... the public key ITSELF is stashed into the contract... Notice that normal asset contracts already keep the keys inside,
	// so why shouldn't these? In fact I can pop the "key" value onto the contract as part of the "Party-Signing" API call. Just grab the
	// public key from each one. Meanwhile the server can verify that it's actually there, and refuse to process without it!!  Nice.
	// This also shows why we need to store the NymID, even if it can be overridden by a Role: because you want to be able to verify
	// the original signature, no matter WHO is authorized now. Otherwise your entire contract falls apart.

	OTScriptable * pPartySignedCopy = OTScriptable::InstantiateScriptable(pParty->GetMySignedCopy());
	OTCleanup<OTScriptable> theCopyAngel;
	
	if (NULL == pPartySignedCopy)
	{
		OTLog::vError("OTScriptable::VerifyNymAsAgent: Error loading party's (%s) signed copy of agreement. Has it been executed?\n",
					  pParty->GetPartyName().c_str());
		pParty->ClearTemporaryPointers();
		return false;
	}
	else
		theCopyAngel.SetCleanupTarget(*pPartySignedCopy);
	// ----------------------------------------------
	
	const bool bSigVerified = pAuthorizingAgent->VerifySignature(*pPartySignedCopy);
	bool bContentsVerified = false;

	if (bSigVerified)
	{
		// Todo OPTIMIZE: Might move this call to a higher layer, so it gets called MUCH less often but retains the same security.
		// There are several places currently in smart contracts like this.
		// Need to analyze security aspects before doing it.
		//
		bContentsVerified = this->Compare(*pPartySignedCopy);
		
		if (!bContentsVerified)
			OTLog::vOutput(0, "OTScriptable::VerifyNymAsAgent: Though the signature verifies, the contract "
						   "signed by the party (%s) doesn't match this contract. (Failed comparison.)\n",
						   pParty->GetPartyName().c_str());
	}
	else
		OTLog::vOutput(0, "OTScriptable::VerifyNymAsAgent: Signature failed to verify for party: %s \n",
					   pParty->GetPartyName().c_str());
	
	
	// Todo: possibly call this->Compare(*pPartySignedCopy); to make sure there's no funny business.
	// Well actually that HAS to happen anyway, it's just a question of whether it goes here too, or only somewhere else.
	// ----------------------------------------------
	
	pParty->ClearTemporaryPointers(); // We loaded a Nym ourselves, which goes out of scope after this function. The party is done
									// with it now, and we don't want it to keep pointing to something that is now going out of scope.
		
	return bContentsVerified;
}



//
// Call VerifyPartyAuthorization() first.
// Also, this function, unlike VerifyPartyAuthorization(), is able to ASSUME that ALL
// of the Nyms AND accounts have ALREADY been loaded into memory, AND that *this has 
// pointers to them. That is all prepared before this function is called. That is why
// you don't see me passing in maps to Nyms that are already loaded -- because *this
// already has them all loaded.
//
// This function verifies ownership AND agency of the account, and it
// also handles closing transaction numbers when appropriate.
//
bool OTScriptable::VerifyPartyAcctAuthorization(OTPartyAccount	& thePartyAcct,	// The party is assumed to have been verified already via VerifyPartyAuthorization()
												OTPseudonym		& theSignerNym,	// For verifying signature on the authorizing Nym.
												const OTString	& strServerID, // For verifying issued num, need the serverID the # goes with.
												const bool		  bBurnTransNo/*=false*/) // In OTServer::VerifySmartContract(), it not only wants to verify the closing # is properly issued, but it additionally wants to see that it hasn't been USED yet -- AND it wants to burn it, so it can't be used again!  This bool allows you to tell the function whether or not to do that.		
{
	OTParty * pParty = thePartyAcct.GetParty();
	
	if (NULL == pParty)
	{
		OTLog::vError("OTScriptable::VerifyPartyAcctAuthorization: Unable to find party for acct: %s \n",
					  thePartyAcct.GetName().Get());
		return false;
	}
	// -----------------------

	OTAgent * pAuthorizedAgent = thePartyAcct.GetAuthorizedAgent();
	
	if (NULL == pAuthorizedAgent)
	{
		OTLog::vOutput(0, "OTScriptable::VerifyPartyAcctAuthorization: Unable to find authorized agent (%s) for acct: %s \n",
					   thePartyAcct.GetAgentName().Get(), thePartyAcct.GetName().Get());
		return false;
	}
	
	// BELOW THIS POINT, pParty and pAuthorizedAgent are both good pointers.
	//
	// Next, we need to verify that pParty is the proper OWNER of thePartyAcct..
	// 
	// AND that pAuthorizedAgent really IS authorized to manipulate the actual 
	// account itself. (Either he is listed as its actual owner, or he is an
	// agent for an entity, authorized based on a specific role, and the account
	// is owned by that entity / controlled by that role.)
	//
	// -----------------------
	
	// VERIFY ACCOUNT's OWNERSHIP BY PARTY
	//
	if (!thePartyAcct.VerifyOwnership())  // This will use pParty internally.
	{
		OTLog::vOutput(0, "OTScriptable::VerifyPartyAcctAuthorization: Unable to verify party's (%s) ownership of acct: %s \n",
					  pParty->GetPartyName().c_str(), thePartyAcct.GetName().Get());
		return false;
	}
	
	// VERIFY ACCOUNT's AUTHORIZED AGENT (that he has rights to manipulate the account itself)
	//
	if (!thePartyAcct.VerifyAgency()) // This will use pAuthorizedAgent internally.
	{
		OTLog::vOutput(0, "OTScriptable::VerifyPartyAcctAuthorization: Unable to verify agent's (%s) rights re: acct: %s \n",
					   pAuthorizedAgent->GetName().Get(), thePartyAcct.GetName().Get());
		return false;
	}
	// **************************************************
	
	//     Verify the closing number, if he has one. (If this instance is OTScriptable-derived, but NOT OTCronItem-derived,
	//     then that means there IS NO closing number, since we're not even on Cron.) The PartyAccts just happen
	//     to store their closing number for the cases where we ARE on Cron, which will probably be most cases.
	//     Therefore we CHECK TO SEE if the closing number is NONZERO -- and if so, we VERIFY ISSUED on that #. That way,
	//     for cases where this IS a cron item, it will still verify the number (as it should) and in other cases, it will
	//     just skip this step.
	//
	//     Also: If bBurnTransNo is set to true, then it will force this issue, since the code then DEMANDS a number 
	//     be available for use.
	
	const long lClosingNo = thePartyAcct.GetClosingTransNo();
	
	if (lClosingNo > 0) // If one exists, then verify it.
	{
		if (false == pAuthorizedAgent->VerifyIssuedNumber(lClosingNo, strServerID))
//		if (false == pAuthAgentsNym->VerifyIssuedNum(strServerID, lClosingNo))
		{
			OTLog::vOutput(0, "OTScriptable::VerifyPartyAcctAuthorization: Closing trans number %ld doesn't "
						   "verify for the nym listed as the authorized agent for account %s.\n", lClosingNo, 
						   thePartyAcct.GetName().Get());
			return false;			
		}
		// --------------------------------------
		// The caller wants the additional verification that the number hasn't been USED 
		// yet -- AND the caller wants you to BURN IT HERE.
		else if (bBurnTransNo)  
		{
			if (false == pAuthorizedAgent->VerifyTransactionNumber(lClosingNo, strServerID))
//			if (false == pAuthAgentsNym->VerifyTransactionNum(strServerID, lClosingNo))
			{
				OTLog::vOutput(0, "OTScriptable::VerifyPartyAcctAuthorization: Closing trans number %ld doesn't "
							   "verify as available for use, for the nym listed as the authorized agent for acct: %s.\n", 
							   lClosingNo, thePartyAcct.GetName().Get());
				return false;			
			}
			else // SUCCESS -- It verified as available, so let's burn it here. (So he can't use it twice. It remains issued and open until the cron item is eventually closed out for good.)
			{				
				pAuthorizedAgent->RemoveTransactionNumber(lClosingNo, strServerID, theSignerNym, true); // bSave=true
//				pAuthAgentsNym->RemoveTransactionNum(theSignerNym, strServerID, lClosingNo); // server removes spent number from nym file. Saves.
			}
		}
		// ---------------------
	} // if lClosingNo>0
	else if (bBurnTransNo)  // In this case, bBurnTransNo=true, then the caller EXPECTED to burn a transaction
	{						// num. But the number was 0! Therefore, FAILURE!
		OTLog::vOutput(0, "OTScriptable::VerifyPartyAcctAuthorization: FAILURE. On Acct %s, expected to burn a legitimate closing transaction "
					   "number, but got this instead: %ld\n", thePartyAcct.GetName().Get(), lClosingNo);
		return false;
	}
	
	// ----------------------------------------------
	
	return true;	
}





// Wherever you call the below function, you need to call the above function too, and make sure the same
// Party is the one found in both cases.
//
// AGAIN: CALL VerifyNymAsAgent() BEFORE you call this function! Otherwise you aren't proving nearly as much. ALWAYS call it first.
//
bool OTScriptable::VerifyNymAsAgentForAccount(OTPseudonym & theNym,
											  OTAccount & theAccount)
{
	// -------------------------------------------------------------
	// Lookup the party via the NYM.
	// NOTE: I think without this, the agent never gets its pointer set to Nym.  FYI.
	// OTAgent * pAgent = NULL;
//	const	OTParty * pNymParty = this->FindPartyBasedOnNymAsAgent(theNym, &pAgent);
//	
//	if (NULL == pNymParty)
//	{
//		OT_ASSERT(NULL != pAgent);
//		OTLog::Output(0, "OTScriptable::VerifyNymAsAgentForAccount: Unable to find party based on Nym as agent.\n");
//		return false;
//	}
	// Below this point, pAgent is a good pointer.
	//
	// -------------------------------------------------------------
	// Lookup the party via the ACCOUNT.
	//
	OTPartyAccount	* pPartyAcct	= NULL;
	OTParty			* pParty		= this->FindPartyBasedOnAccount(theAccount, &pPartyAcct);

	if (NULL == pParty)
	{
		OT_ASSERT(NULL != pPartyAcct);
		OTLog::Output(0, "OTScriptable::VerifyNymAsAgentForAccount: Unable to find party based on account.\n");
		return false;
	}
	// pPartyAcct is a good pointer below this point.
	
	// -------------------------------------------------------------

	// Verify ownership.
	//
	if (false == pParty->VerifyOwnershipOfAccount(theAccount))
	{
		OTLog::Output(0, "OTScriptable::VerifyNymAsAgentForAccount: pParty is not the owner of theAccount.\n");
		pParty->ClearTemporaryPointers(); // Just in case.
		return false;
	}	
	
	// -------------------------------------------------------------
	
	const	std::string	str_acct_agent_name	= pPartyAcct->	GetAgentName().Get();
			OTAgent *	pAgent				= pParty->		GetAgent(str_acct_agent_name);

	// Make sure they are from the SAME PARTY.
	//
	if (NULL == pAgent)
	{
		OTLog::Output(0, "OTScriptable::VerifyNymAsAgentForAccount: Unable to find the right agent for this account.\n");
		pParty->ClearTemporaryPointers(); // Just in case.
		return false;
	}
	// Below this point, pPartyAcct is a good pointer, and so is pParty, as well as pAgent
	// We also know that the agent's name is the same one that was listed on the account as authorized.
	// (Because we used the account's agent_name to look up pAgent in the first place.)
	// -------------------------------------------------------------
	
	// Make sure theNym is a valid signer for pAgent, whether representing himself as in individual, or in a role for an entity.
	// This means that pAgent (looked up based on partyAcct's agent name) will return true to IsValidSigner when passed theNym,
	// assuming theNym really is the agent that partyAcct was talking about.
	//
	if (false == pAgent->IsValidSigner(theNym))
	{
		OTLog::Output(0, "OTScriptable::VerifyNymAsAgentForAccount: theNym is not a valid signer for pAgent.\n");
		pParty->ClearTemporaryPointers(); // Just in case.
		return false;
	}
	if (false == pAgent->VerifyAgencyOfAccount(theAccount))
	{
		OTLog::Output(0, "OTScriptable::VerifyNymAsAgentForAccount: theNym is not a valid agent for theAccount.\n");
		pParty->ClearTemporaryPointers(); // Just in case.
		return false;
	}

	
//	Now we know:  
	// (1) theNym is agent for pParty,     (according to the party)
	// (2) theAccount is owned by pParty   (according to the party)
	// (3) theNym is agent for theAccount  (according to the party)
	// (4) theNym is valid signer for pAgent
	// (5) pParty is the actual OWNER of the account. (According to theAccount.)
	
	
	pParty->ClearTemporaryPointers(); // Just in case.
	
	return true;
}	
	
	// Normally I'd call this to prove OWNERSHIP and I'd ASSUME AGENCY based on that:
	// pSourceAcct->VerifyOwner(*pSenderNym)
	
	// However, if I'm instead supposed to accept that pSenderNym, while NOT listed as the "Owner" on the
	// account itself, is still somehow AUTHORIZED to change it, "because the actual owner says that it's okay"...
	// Well in that case, it's not good enough unless I prove BOTH ownership AND Agency. I should prove:
	// -- the actual owner for the account, 
	// -- AND is shown to have signed the agreement with his authorizing agent,
	// -- AND is shown to have set theNym as his agent, and listed theNym as authorized agent for that account.
	
	/*
	 Proves the original party DOES approve of Nym managing that account (assuming that VerifyNymAsAgentForAnyParty was called, which
	 saves us from having to look up the authorizing agent for the party and verify his signature on the entire contract. We assume the
	 contract itself is sound, and we go on to verify its term.)
	 Also needs to prove that the ACCOUNT believes itself to be owned by the original party and was signed by the server.
	 (If we have proved that ACCOUNT believes itself to be owned by the party, AND that the PARTY believes it has authorized Nym to
	 manage that account, 
	 plus the previous function already proves that Nym is an agent of the PARTY and that the original agreement
	 is sound, as signed by the party's authorizing agent.)
	 
	 AGENCY
	 1) Lookup the account from among all the parties. This way we find the party. bool FindPartyBasedOnAccount(theAccount);
	 2) Lookup the party based on the Nym as agent, and compare it to make sure they are the SAME PARTY.
	 3) Lookup the authorized agent for that account (from that party.) This is different than the authorizing agent in
	    the function above, which is who signed to open the contract and fronted the opening trans#. But in THIS case, the authorized
	    agent must be available for EACH asset account, and he is the one who supplied the CLOSING number. Each acct has an agent
	    name, so lookup that agent from pParty.
	 4) Make sure theNym IS that authorized agent. Only THEN do we know that theNym is authorized (as far as the party is concerned.)
		Notice also that we didn't verify theNym's signature on anything since he hasn't actually signed anything on the contract itself.
	    Notice that the ONLY REASON THAT WE KNOW FOR SURE is because VerifyNymAsAgent() was called before this function! Because that is
	    what loads the original signer and verifies his signature. Unless that was done, we honestly don't even know this much! So make
	    sure you call that function before this one.

	 Assuming we get this far, this means the Party / Smart Contract actually approves of theNym as an Agent, and of theAccount as an
	 account, and it also approves that Nym is authorized to manipulate that account.
	 But it doesn't prove who OWNS that account! Nor does it prove, even if the Nym DOES own it, whether theNym actually authorizes
	 this action. Therefore we must also prove that the owner of the account (according to the ACCOUNT) is the same party who authorized
	 the Nym to manage that account in the smart contract.  (If the Nym IS the party, then he will show as the owner AND agent.)
	 
	 OWNERSHIP
	 1) pParty->VerifyOwnership(theAccount)
	 2) If Party owner is a Nym, then call verifyOwner on the account directly with that Nym (just like the old way.)
	 3) BUT, if Party owner is an Entity, verify that the entity owns the account.
	 4) ALSO: Outside of the smart contract, the same Nym should be able to manipulate that account in this same way, just
	    by showing that the account is owned by an entity where that Nym has the RoleID in that entity that appears on the
	    account. (Account should have entity AND role).
	 
	 AHH this is the difference between "this Nym may manipulate this account in general, due to his role" vs. "this Nym may
	 manipulate this account DUE TO THE AGENCY OF THE ROLE ID stored in the Account."
	 What's happening is, I'm proving BOTH.  The smart contract, even if you HAVE the role, still restricts you from doing anything
	 FROM INSIDE THE SMART CONTRACT (scripts) where that Nym isn't explicitly set up as the authorized agent for that account. The Nym
	 may STILL *normally* be able to mess with that account, if the role is set up that way -- he just can't do it from inside the script,
	 without the additional setup inside the script itself that THIS Nym is the one setup on THIS account.
	 
	 Really though, inside the script itself, the only time a Nym would be set up as the account manager is really if the script
	 owner wanted to set the ROLE as the account manager.  I don't REALLY want to set Frank in charge in the sales budget money. 
	 Rather, I want to set the SALES DIRECTOR ROLE as being in charge of the sales budget money, and Frank just happens to be in that
	 role.  IF I FIRE HIM TOMORROW, AND PUT ANOTHER NYM IN THAT ROLE, THE CONTRACT SHOULD STILL FUNCTION, right? Following that...
	 
	 The account itself will store the EntityID and RoleID.
	 
	 The partyaccount (on the party) only has the "agent name" who deals with that account. (No nym ID so far.)
	 
	 When I lookup the partyaccount, I lookup the authorized agent. At this point, the agent could still be a Role, not a Nym.
	 
	 Therefore when I verify the Nym against the agent, I do it the same way as I might verify a nym against an account. If the
	 agent is a nym repping himself, I compare the NymIDs. Else if the agent is an individual in a role, then I  take the Entity that 
	 owns that agent (the entity is hidden inside the party) and I compare the Nym's ID to the NymID recorded in the Entity as being 
	 responsible for that role based on the RoleID stored in the agent. CLearer:  The agent has a RoleID and an Entity ID. The entity
	 that owns it has a list of NymIDs, each mapped to a RoleID.  For the account controlled by the agent, if the Nym trying to change
	 that account is actually listed in entity EntityID as being assigned role RoleID, where EntityID and RoleID match those in the agent,
	 then Nym IS authorized to play with the account. This is verifiable for entities, nyms, and accounts even OUTSIDE of a smart contract,
	 and doesn't rely on the smart contract having the partyaccount/authorized_agent set up. Those are just ADDITIONAL restrictions.
	 Thus, Inside a smart contract, OT should enforce those additional restrictions as a layer above the verification of role/owner, etc.
	 
	 OR: Should I make it instead: That you must EITHER have Role-permission, OR smartcontract authorization, and EITHER WAY it allows
	 you to manipulate the account?
	 
	 */


// Find the first (and hopefully the only) clause on this scriptable object,
// with a given name. (Searches ALL Bylaws on *this.)
//
OTClause * OTScriptable::GetClause(const std::string str_clause_name)
{
	if (false == OTScriptable::ValidateName(str_clause_name)) // this logs, FYI.
	{
		OTLog::Error("OTScriptable::GetClause:  Error: invalid name.\n");
		return NULL;
	}
	// --------------------------------
	
	FOR_EACH(mapOfBylaws, m_mapBylaws)
	{
		OTBylaw * pBylaw = (*it).second;
		OT_ASSERT(NULL != pBylaw);
		// -------------------------
		
		OTClause * pClause = pBylaw->GetClause(str_clause_name);
		
		if (NULL != pClause) // found it.
			return pClause;
	}

	return NULL;	
}


OTAgent * OTScriptable::GetAgent(const std::string str_agent_name)
{
	if (false == OTScriptable::ValidateName(str_agent_name)) // this logs, FYI.
	{
		OTLog::Error("OTScriptable::GetAgent:  Error: invalid name.\n");
		return NULL;
	}
	// -----------------------------------
	
	FOR_EACH(mapOfParties, m_mapParties)
	{
		OTParty * pParty = (*it).second;
		OT_ASSERT(NULL != pParty);
		// -------------------------
		
		OTAgent * pAgent = pParty->GetAgent(str_agent_name);
		
		if (NULL != pAgent) // found it.
			return pAgent;
	}
	
	return NULL;		
}



OTBylaw * OTScriptable::GetBylaw(const std::string str_bylaw_name)
{
	if (false == OTScriptable::ValidateName(str_bylaw_name)) // this logs, FYI.
	{
		OTLog::Error("OTScriptable::GetBylaw:  Error: invalid name.\n");
		return NULL;
	}
	// -----------------------------------------------------------
	
	mapOfBylaws::iterator iii = m_mapBylaws.find(str_bylaw_name);
	
	if (m_mapBylaws.end() == iii) // Did NOT find it.
	{
		// People call this function sometimes just to SEE if one is there.
		// So it's not an error if it's not there...
		//
//		OTLog::vOutput(0, "OTScriptable::GetBylaw: Strange: bylaw not found: %s. Bylaw count is: %d \n",
//					   str_bylaw_name.c_str(), m_mapBylaws.size());		
		return NULL;
	}
	// ----------------------------------------
	
	OTBylaw * pBylaw = (*iii).second;
	OT_ASSERT(NULL != pBylaw);
	
	return pBylaw;	
}



OTParty * OTScriptable::GetParty(const std::string str_party_name)
{
	if (false == OTScriptable::ValidateName(str_party_name)) // this logs, FYI.
	{
		OTLog::Error("OTScriptable::GetParty:  Error: invalid name.\n");
		return NULL;
	}
	// -----------------------------------------------------------
	
	mapOfParties::iterator it = m_mapParties.find(str_party_name);
	
	if (m_mapParties.end() == it) // Did NOT find it.
	{
		// GetParty() is often called to SEE if a party is there.
		// (So if the party ain't there, it's not necessarily an error.)
		//
//		OTLog::vOutput(0, "OTScriptable::GetParty: Strange: party not found: %s\n",
//					   str_party_name.c_str());
		return NULL;
	}
	// ----------------------------------------
	
	OTParty * pParty = (*it).second;
	OT_ASSERT(NULL != pParty);
	
	return pParty;	
}



// Verify the contents of THIS contract against signed copies of it that are stored in each Party.
//
bool OTScriptable::VerifyThisAgainstAllPartiesSignedCopies()
{
	// MAKE SURE ALL SIGNED COPIES ARE OF THE SAME CONTRACT.
	// Loop through ALL the parties. For whichever ones are already signed,
	// load up the signed copy and make sure it compares to the main one.
	// This is in order to make sure that I am signing the same thing that
	// everyone else signed, before I actually sign it.
	//
	FOR_EACH(mapOfParties, m_mapParties)
	{
		const std::string current_party_name	= (*it).first;
		OTParty * pParty						= (*it).second;
		OT_ASSERT(NULL != pParty);
		// ---------------
		
		if (pParty->GetMySignedCopy().Exists())
		{
			OTScriptable * pPartySignedCopy = OTScriptable::InstantiateScriptable(pParty->GetMySignedCopy());
			OTCleanup<OTScriptable> theCopyAngel;
			
			if (NULL == pPartySignedCopy)
			{
				OTLog::vError("OTScriptable::VerifyThisAgainstAllPartiesSignedCopies: Error loading party's (%s) "
							  "signed copy of agreement. Has it been executed?\n", current_party_name.c_str());				
				return false;
			}
			else
				theCopyAngel.SetCleanupTarget(*pPartySignedCopy);
			// ----------------------
			if ( ! this->Compare(*pPartySignedCopy) )   // <============= For all signed copies, we compare them to *this.
			{
				OTLog::vError("OTScriptable::VerifyThisAgainstAllPartiesSignedCopies: Party's (%s) "
							  "signed copy of agreement doesn't match *this.\n", current_party_name.c_str());				
				return false;				
			}
		}
		// else nothing. (We only verify against the ones that are signed.)
	} // FOR_EACH
	// ---------------
	return true;
}


// Done
// Takes ownership. Client side.
// ONLY works if the party is ALREADY there. Assumes the transaction #s, etc are set up already.
//
// Used once all the actual parties have examined a specific smartcontract and have 
// chosen to sign-on to it. This function looks up the theoretical party (such as "trustee") 
// that they are trying to sign on to, compares the two, then replaces the theoretical one
// with the actual one. Then it signs the contract and saves a copy inside the party.
//
bool OTScriptable::ConfirmParty(OTParty & theParty)
{
	const std::string str_party_name = theParty.GetPartyName();
	
	if (false == OTScriptable::ValidateName(str_party_name)) // this logs, FYI.
	{
		OTLog::Error("OTScriptable::ConfirmParty:  Error: invalid name.\n");
		return false;
	}
	// -----------------------------------------------------------
	// MAKE SURE ALL SIGNED COPIES ARE OF THE SAME CONTRACT.
	// Loop through ALL the parties. For whichever ones are already signed,
	// load up the signed copy and make sure it compares to the main one.
	// This is in order to make sure that I am signing the same thing that
	// everyone else signed, before I actually sign it.
	//
	if (false == VerifyThisAgainstAllPartiesSignedCopies())
		return false; // This already logs on failure.
	
	// BY THIS POINT, we know that, of all the parties who have already signed, 
	// their signed copies DO match this smart contract.
	//
	// -----------------------------------------------------------
	//
	// Next, find the theoretical Party on this scriptable that matches the actual Party that
	// was passed in. (It should already be there.) If found, replace it with the one passed in.
	// Then sign the contract, save the signed version in the new party, and then sign again.
	//
	// If NOT found, then we failed. (For trying to confirm a non-existent party.)
	//
	mapOfParties::iterator it_delete = m_mapParties.find(str_party_name);
	
	if (it_delete != m_mapParties.end()) // It was already there. (Good.)
	{
		OTParty * pParty = (*it_delete).second;
		OT_ASSERT(NULL != pParty);
		// -------------------------------
		
		if (!pParty->Compare(theParty)) // Make sure my party compares to the one it's replacing...
		{
			OTLog::vOutput(0, "OTScriptable::ConfirmParty: Party (%s) doesn't match the one it's confirming.\n",
						   str_party_name.c_str());
			return false;
		}
		// else...
		m_mapParties.erase(it_delete);  // Remove the theoretical party from the map, so we can replace it with the real one.
		delete pParty; pParty=NULL;		// Delete it, since I own it.
		// ------------------------
		// Careful:  This ** DOES ** TAKE OWNERSHIP!  theParty will get deleted when 
		// this OTScriptable instance is.
		//
		m_mapParties.insert( std::pair<std::string, OTParty *>(str_party_name, &theParty)) ; 
		theParty.SetOwnerAgreement(*this); // Now the actual party is in place, instead of a placekeeper version of it. There are actual Acct/Nym IDs now, etc.
		// ------------------------
				
		// Sign it and save it, 
		OTString strNewSignedCopy;
		this->ReleaseSignatures();
		bool bSuccess = theParty.SignContract(*this);
		if (bSuccess)
		{
			this->SaveContract();
			this->SaveContractRaw(strNewSignedCopy);
			// -----------------------
			// then save a copy of it inside theParty, 
			//
			theParty.SetMySignedCopy(strNewSignedCopy);

			// -----------------------	
			// then sign the overall thing again, so that signed copy (now inside theParty) will be properly saved.
			// That way when other people verify my signature, it will be there for them to verify.
			//
			this->ReleaseSignatures();
			theParty.SignContract(*this);		
			this->SaveContract();
			
			return true;
		}
		
		return false;
	}
	else 
		OTLog::vOutput(0, "OTScriptable::ConfirmParty: Failed attempt to confirm non-existent party: %s \n ",
					  str_party_name.c_str());
	// ----------------------------------------
	
	return false;
}


// ONLY adds it if it's not already there.
// Used during the design of the smartcontract. (Adding theoretical parties.)
//
bool OTScriptable::AddParty(OTParty & theParty)
{
	const std::string str_party_name = theParty.GetPartyName();
	
	if (false == OTScriptable::ValidateName(str_party_name)) // this logs, FYI.
	{
		OTLog::Error("OTScriptable::AddParty:  Error: invalid name.\n");
		return false;
	}
	// -----------------------------------------------------------
	
	if (m_mapParties.find(str_party_name) == m_mapParties.end())
	{
		// Careful:  This ** DOES ** TAKE OWNERSHIP!  theParty will get deleted when this OTScriptable is.
		m_mapParties.insert( std::pair<std::string, OTParty *>(str_party_name, &theParty)) ;
		
		theParty.SetOwnerAgreement(*this);
		
		return true;
	}
	else 
		OTLog::Output(0, "OTScriptable::AddParty: Failed attempt: party already exists on contract.\n ");
	
	// ----------------------------------------
	
	return false;
}


bool OTScriptable::AddBylaw(OTBylaw & theBylaw)
{
	const std::string str_name = theBylaw.GetName().Get();
	
	if (false == OTScriptable::ValidateName(str_name)) // this logs, FYI.
	{
		OTLog::Error("OTScriptable::AddBylaw:  Error: invalid name.\n");
		return false;
	}
	// -----------------------------------------------------------
	
	if (m_mapBylaws.find(str_name) == m_mapBylaws.end())
	{
		// Careful:  This ** DOES ** TAKE OWNERSHIP!  theBylaw will get deleted when this OTScriptable is.
		m_mapBylaws.insert( std::pair<std::string, OTBylaw *>(str_name, &theBylaw)) ;

		theBylaw.SetOwnerAgreement(*this);
		
		return true;
	}
	else 
		OTLog::Output(0, "OTScriptable::AddBylaw: Failed attempt: bylaw already exists on contract.\n ");
	
	// ----------------------------------------
	
	return false;
}




/*
 <party name=“shareholders”
 Owner_Type=“entity”  // ONLY can be “nym” or “entity”.
 Owner_ID=“this” >   // Nym ID or Entity ID. Not known at creation.
 
 <agent type=“group”// could be “nym”, or “role”, or “group”. 
	Nym_id=“” // In case of “nym”, this is the Nym’s ID. If “role”, this is NymID of employee in role.
	Role_id=“” // In case of “role”, this is the Role’s ID.
	Entity_id=“this” // same as OwnerID if ever used. Should remove.
	Group_ID=“class_A” // “class A shareholders” are the voting group that controls this agent. 
	/>
 
 </party> 
 */




bool OTScriptable::Compare(OTScriptable & rhs)
{
	//
	// UPDATE: ALL of the parties should be there, in terms of their
	// names and account names --- but the actual IDs can remain blank,
	// and the signed copies can be blank. (Those things are all verified
	// elsewhere. That's about verifying the signature and authorization,
	// versus verifying the content.)
	//
	if (this->GetPartyCount() != rhs.GetPartyCount())
	{
		OTLog::vOutput(0, "OTScriptable::Compare: The number of parties does not match.\n");
		return false;
	}
	if (this->GetBylawCount() != rhs.GetBylawCount())
	{
		OTLog::vOutput(0, "OTScriptable::Compare: The number of bylaws does not match.\n");
		return false;
	}
	// ----------------------------------------
	FOR_EACH_CONST(mapOfBylaws, m_mapBylaws)
	{
		const std::string str_bylaw_name	= (*it).first;
		OTBylaw * pBylaw					= (*it).second;
		OT_ASSERT(NULL != pBylaw);
		// --------------------
		
		OTBylaw * p2 = rhs.GetBylaw(str_bylaw_name);
		
		if (NULL == p2)
		{
			OTLog::vOutput(0, "OTScriptable::Compare: Unable to find bylaw %s on rhs.\n",
						   str_bylaw_name.c_str());
			return false;
		}
		else if ( ! pBylaw->Compare(*p2) )
		{
			OTLog::vOutput(0, "OTScriptable::Compare: Bylaws don't match: %s.\n",
						   str_bylaw_name.c_str());
			return false;
		}
	}
	// ----------------------------------------
	FOR_EACH_CONST(mapOfParties, m_mapParties)
	{
		const std::string str_party_name	= (*it).first;
		OTParty * pParty					= (*it).second;
		OT_ASSERT(NULL != pParty);
		// --------------------
		
		OTParty * p2 = rhs.GetParty(str_party_name);
		
		if (NULL == p2)
		{
			OTLog::vOutput(0, "OTScriptable::Compare: Unable to find party %s on rhs.\n",
						   str_party_name.c_str());
			return false;
		}
		else if ( ! pParty->Compare(*p2) )
		{
			OTLog::vOutput(0, "OTScriptable::Compare: Parties don't match: %s.\n",
						   str_party_name.c_str());
			return false;
		}
	}
	// ----------------------------
	
    return true;
}





void OTScriptable::UpdateContentsToString(OTString & strAppend)
{	
	if ((m_mapParties.size()>0) || (m_mapBylaws.size()>0))
	{
		strAppend.Concatenate("<scriptableContract>\n\n");
		
		FOR_EACH(mapOfParties, m_mapParties)
		{
			OTParty * pParty = (*it).second;
			OT_ASSERT(NULL != pParty);
			
			pParty->Serialize(strAppend);		
		}
		
		FOR_EACH(mapOfBylaws, m_mapBylaws)
		{
			OTBylaw * pBylaw = (*it).second;
			OT_ASSERT(NULL != pBylaw);
			
			pBylaw->Serialize(strAppend);
		}
		
		strAppend.Concatenate("</scriptableContract>\n\n");
	}
}


void OTScriptable::UpdateContents() // Before transmission or serialization, this is where the contract updates its contents 
{		
	// I release this because I'm about to repopulate it.
	m_xmlUnsigned.Release();
	
	UpdateContentsToString(m_xmlUnsigned);
}

// return -1 if error, 0 if nothing, and 1 if the node was processed.
int OTScriptable::ProcessXMLNode(irr::io::IrrXMLReader*& xml)
{	
	int nReturnVal = 0; // Unless/until I want to add OTContract::Compare(), then people would be able to surreptitiously insert keys and 
//	int nReturnVal = OTContract::ProcessXMLNode(xml); // conditions, and entities, that passed OTScriptable::Compare() with flying colors 
//  even though they didn't really match. Therefore, here I explicitly disallow loading those things.
	
	// Here we call the parent class first.
	// If the node is found there, or there is some error,
	// then we just return either way.  But if it comes back
	// as '0', then nothing happened, and we'll continue executing.
	//
	// -- Note: you can choose not to call the parent, if
	// you don't want to use any of those xml tags.
	
//	if (nReturnVal == 1 || nReturnVal == (-1))
//		return nReturnVal;
	
	if (!strcmp("scriptableContract", xml->getNodeName()))
	{
		nReturnVal = 1; 
	}
	
	else if (!strcmp("party", xml->getNodeName()))
	{
		OTString strName			= xml->getAttributeValue("name"); // Party name (in script code)
		OTString strOwnerType		= xml->getAttributeValue("ownerType"); // "nym" or "entity"
		OTString strOwnerID			= xml->getAttributeValue("ownerID"); // Nym or Entity ID. todo security probably make these separate variables.
		
		OTString strOpeningTransNo	= xml->getAttributeValue("openingTransNo"); // the closing #s are on the asset accounts.
		
		OTString strAuthAgent		= xml->getAttributeValue("authorizingAgent"); // When an agent activates this contract, it's HIS opening trans# that's used.
		
		OTString strNumAgents		= xml->getAttributeValue("numAgents"); // number of agents on this party.
		OTString strNumAccounts		= xml->getAttributeValue("numAccounts"); // number of accounts for this party.
		
		OTString strIsCopyProvided	= xml->getAttributeValue("signedCopyProvided");
		
		// ----------------------------------
		bool bIsCopyProvided = false; // default
		
		if (strIsCopyProvided.Compare("true"))
			bIsCopyProvided = true;
		
		// ---------------------------------------
		long lOpeningTransNo = 0;
		// -------
		if (strOpeningTransNo.Exists())
			lOpeningTransNo = atol(strOpeningTransNo.Get());
		else
			OTLog::Error("OTScriptable::ProcessXMLNode: Expected openingTransNo in party.\n");
		// ---------------------------------------
		
		OTParty * pParty = new 	OTParty(strName.Exists() ? strName.Get() : "PARTY_ERROR_NAME",
										strOwnerType.Compare("nym") ? true : false, 
										strOwnerID.Get(),
										strAuthAgent.Get());
		OT_ASSERT(NULL != pParty);
		
		pParty->SetOpeningTransNo(lOpeningTransNo);	// WARNING:  NEED TO MAKE SURE pParty IS CLEANED UP BELOW THIS POINT, IF FAILURE!!

		// -----------------------------------------------
		//
		// Load up the agents.
		//
		int nCount	= strNumAgents.Exists() ? atoi(strNumAgents.Get()) : 0;
		if (nCount > 0)
		{
			while (nCount-- > 0)
			{
//				xml->read(); // <==================
				if (false == SkipToElement(xml))
				{
					OTLog::Output(0, "OTScriptable::ProcessXMLNode: Failure: Unable to find expected element for agent. \n");
					delete pParty; pParty=NULL;
					return (-1);
				}
				// -----------------------------------------------

				if ((xml->getNodeType() == EXN_ELEMENT) && (!strcmp("agent", xml->getNodeName())))
				{
					OTString strAgentName		= xml->getAttributeValue("name"); // Agent name (if needed in script code)
					OTString strAgentRepSelf	= xml->getAttributeValue("doesAgentRepresentHimself"); // Agent might also BE the party, and not just party's employee.
					OTString strAgentIndividual	= xml->getAttributeValue("isAgentAnIndividual"); // Is the agent a voting group, or an individual nym? (whether employee or not)
					OTString strNymID			= xml->getAttributeValue("nymID"); // Nym ID if Nym in role for entity, or if representing himself.
					OTString strRoleID			= xml->getAttributeValue("roleID"); // Role ID if Nym in Role.
					OTString strGroupName		= xml->getAttributeValue("groupName"); // Group name if voting group. (Relative to entity.)
										
					// ----------------------------------
					
					if (!strAgentName.Exists() || !strAgentRepSelf.Exists() || !strAgentIndividual.Exists())
					{
						OTLog::Error("OTScriptable::ProcessXMLNode: Error loading agent: Either the name, or one of the bool variables was EMPTY.\n");
						delete pParty; pParty=NULL;
						return (-1);
					}
					// ----------------------------------
					if (!OTScriptable::ValidateName(strAgentName.Get()))
					{
						OTLog::vError("OTScriptable::ProcessXMLNode: Failed loading agent due to Invalid name: %s\n",
									  strAgentName.Get());
						delete pParty; pParty=NULL;
						return (-1);
					}
					// ----------------------------------
					bool bRepsHimself = true; // default
					
					if (strAgentRepSelf.Compare("false"))
						bRepsHimself = false;
					
					// ----------------------------------
					bool bIsIndividual = true; // default
					
					if (strAgentIndividual.Compare("false"))
						bIsIndividual = false;
					
					// ---------------------------------------
					// See if the same-named agent already exists on ANY of the OTHER PARTIES
					// (There can only be one agent on an OTScriptable with a given name.)
					//
					OTAgent * pExistingAgent = this->GetAgent(strAgentName.Get());
					
					if (NULL != pExistingAgent) // Uh-oh, it's already there!
					{
						OTLog::vOutput(0, "OTScriptable::ProcessXMLNode: Error loading agent named %s, since one was "
									   "already there on party %s.\n", strAgentName.Get(), strName.Get());
						delete pParty; pParty=NULL;
						return (-1);
					}
					// The AddAgent call below checks to see if it's already there, but only for the
					// currently-loading party.
					// Whereas the above GetAgent() call checks this OTScriptable for ALL the agents on the already-loaded parties.
					// ----------------------------------
					
					OTAgent * pAgent = 
						new OTAgent(bRepsHimself, bIsIndividual, strAgentName, strNymID, strRoleID, strGroupName);
					OT_ASSERT(NULL != pAgent);
					
					if (false == pParty->AddAgent(*pAgent))
					{
						delete pAgent; pAgent = NULL;
						delete pParty; pParty=NULL;
						OTLog::Error("OTScriptable::ProcessXMLNode: Failed adding agent to party.\n");
						return (-1);
					}
					
//					xml->read(); // <==================
					
					// MIGHT need to add "skip after element" here.
					
					// Update: Nope.
				}				
				else 
				{
					OTLog::Error("Expected agent element in party, OTScriptable::ProcessXMLNode\n");
					delete pParty; pParty=NULL;
					return (-1); // error condition
				}
			} // while
		}
		// --------------------------------
		//
		// LOAD PARTY ACCOUNTS.
		//
		nCount	= strNumAccounts.Exists() ? atoi(strNumAccounts.Get()) : 0;
		if (nCount > 0)
		{
			while (nCount-- > 0)
			{
//				xml->read(); // <==================
				if (false == OTContract::SkipToElement(xml))
				{
					OTLog::Error("OTScriptable::ProcessXMLNode: Error finding expected next element for party account.\n");
					delete pParty; pParty=NULL;
					return (-1);
				}
				// -----------------------------------------------
				
				if ((xml->getNodeType() == EXN_ELEMENT) && (!strcmp("assetAccount", xml->getNodeName())))
				{
					OTString strAcctName		= xml->getAttributeValue("name"); // Acct name (if needed in script code)
					OTString strAcctID			= xml->getAttributeValue("acctID"); // Asset Acct ID
					OTString strAssetTypeID		= xml->getAttributeValue("assetTypeID"); // Asset Type ID
					OTString strAgentName		= xml->getAttributeValue("agentName"); // Name of agent who controls this account.
					OTString strClosingTransNo	= xml->getAttributeValue("closingTransNo"); // the closing #s are on the asset accounts.
					
					long lClosingTransNo = 0;
					// -------
					if (strClosingTransNo.Exists())
						lClosingTransNo = atol(strClosingTransNo.Get());
					else
					{
						OTLog::Error("OTScriptable::ProcessXMLNode: Expected closingTransNo in partyaccount.\n");
						delete pParty; pParty=NULL;
						return (-1);
					}
					// ----------------------------------
					
					// Missing Account ID is allowed, as well as agent name, since those things may not be decided yet.
					//
					if (!strAcctName.Exists() || !strAssetTypeID.Exists())
//					if (!strAcctName.Exists() || !strAcctID.Exists() || !strAgentName.Exists() || !strAssetTypeID.Exists())
					{
						OTLog::Error("OTScriptable::ProcessXMLNode: Expected missing AcctID or AssetTypeID or Name or AgentName in partyaccount.\n");
						delete pParty; pParty=NULL;
						return (-1);
					}
					// ---------------------------------------
					// See if the same-named partyacct already exists on ANY of the OTHER PARTIES
					// (There can only be one partyacct on an OTScriptable with a given name.)
					//
					OTPartyAccount * pAcct = this->GetPartyAccount(strAcctName.Get());

					if (NULL != pAcct) // Uh-oh, it's already there!
					{
						OTLog::vOutput(0, "OTScriptable::ProcessXMLNode: Error loading partyacct named %s, since one was "
									   "already there on party %s.\n", strAcctName.Get(), strName.Get());
						delete pParty; pParty=NULL;
						return (-1);
					}
					// The AddAccount call below checks to see if it's already there, but only for the
					// currently-loading party.
					// Whereas the above call checks this OTScriptable for all the accounts on the already-loaded parties.
					// ----------------------------------
					
					if (false == pParty->AddAccount(strAgentName, strAcctName, strAcctID, strAssetTypeID, lClosingTransNo))
					{
						OTLog::Error("OTScriptable::ProcessXMLNode: Failed adding account to party.\n");
						delete pParty; pParty=NULL;
						return (-1);
					}
					
//					xml->read(); // <==================
					
					
					// MIGHT need to add "skip after field" call here.
					
					// UPdate: Nope. Not here.
					
				}				
				else 
				{
					OTLog::Error("Expected assetAccount element in party, OTScriptable::ProcessXMLNode\n");
					delete pParty; pParty=NULL;
					return (-1); // error condition
				}
			} // while
		}
		
		// **************************************
		
		if (bIsCopyProvided)
		{
			const char	*	pElementExpected	= "mySignedCopy";
			OTString		strTextExpected; // signed copy will go here.
					
			if (false == LoadEncodedTextFieldByName(xml, strTextExpected, pElementExpected))
			{
				OTLog::vError("Error in OTScriptable::ProcessXMLNode: "
							  "Expected %s element with text field.\n", 
							  pElementExpected);
				delete pParty; pParty = NULL;
				return (-1); // error condition
			}
			// else ...
			
			pParty->SetMySignedCopy(strTextExpected);
		}
		
		// --------------------------------
		if (false == SkipAfterLoadingField(xml))  // </party>
		{ 
			OTLog::Output(0, "*** OTScriptable::ProcessXMLNode: Bad data? Expected EXN_ELEMENT_END here, but "
						  "didn't get it. Failure.\n"); 
			delete pParty; pParty=NULL;
			return (-1);
		}
		// --------------------------------
		
		if (AddParty(*pParty))
			OTLog::vOutput(2, "OTScriptable: Loaded Party: %s\n", pParty->GetPartyName().c_str());
		else 
		{
			OTLog::vError("OTScriptable: Failed loading Party: %s\n", pParty->GetPartyName().c_str());
			delete pParty; pParty = NULL;
			return (-1); // error condition
		}
		
		nReturnVal = 1;
	} // "party"
	
	// ----------------------------------------------------------------------------------
	
	else if (!strcmp("bylaw", xml->getNodeName())) 
	{
		OTString strName		= xml->getAttributeValue("name"); // bylaw name
		OTString strLanguage	= xml->getAttributeValue("language"); // The script language used in this bylaw.
		
		OTString strNumVariable		= xml->getAttributeValue("numVariables"); // number of variables on this bylaw.
		OTString strNumClauses		= xml->getAttributeValue("numClauses"); // number of clauses on this bylaw.
		OTString strNumHooks		= xml->getAttributeValue("numHooks"); // hooks to server events.
		OTString strNumCallbacks	= xml->getAttributeValue("numCallbacks"); // Callbacks the server may initiate, when it needs answers.
		
		OTBylaw * pBylaw = new OTBylaw(strName.Get(), strLanguage.Get());
		
		OT_ASSERT(NULL != pBylaw);
		
		// ---------------------------------------------------------------------------
		//
		// LOAD VARIABLES AND CONSTANTS.
		//
		int nCount	= strNumVariable.Exists() ? atoi(strNumVariable.Get()) : 0;
		if (nCount > 0)
		{
			while (nCount-- > 0)
			{
//				xml->read(); // <==================
				if (false == OTContract::SkipToElement(xml))
				{
					OTLog::Error("OTScriptable::ProcessXMLNode: Error finding expected next element for variable.\n");
					delete pBylaw; pBylaw=NULL;
					return (-1);
				}
				// -----------------------------------------------
				
				if ((xml->getNodeType() == EXN_ELEMENT) && (!strcmp("variable", xml->getNodeName())))
				{
					OTString strVarName		= xml->getAttributeValue("name"); // Variable name (if needed in script code)
					OTString strVarValue	= xml->getAttributeValue("value"); // Value stored in variable (If this is "true" then a real value is expected in a text field below. Otherwise, it's assumed to be a BLANK STRING.)
					OTString strVarType		= xml->getAttributeValue("type"); // string or long
					OTString strVarAccess	= xml->getAttributeValue("access"); // constant, persistent, or important.
					
					// ----------------------------------
					
					if (!strVarName.Exists() || !strVarType.Exists() || !strVarAccess.Exists())
					{
						OTLog::Error("OTScriptable::ProcessXMLNode: Expected missing name, type, or access type in variable.\n");
						delete pBylaw; pBylaw=NULL;
						return (-1);
					}
					// ---------------------------------------
					// See if the same-named variable already exists on ANY of the OTHER BYLAWS
					// (There can only be one variable on an OTScriptable with a given name.)
					//
					OTVariable * pVar = this->GetVariable(strVarName.Get());
					
					if (NULL != pVar) // Uh-oh, it's already there!
					{
						OTLog::vOutput(0, "OTScriptable::ProcessXMLNode: Error loading variable named %s, since one was "
									   "already there on one of the bylaws.\n", strVarName.Get());
						delete pBylaw; pBylaw=NULL;
						return (-1);
					}
					// The AddVariable call below checks to see if it's already there, but only for the
					// currently-loading bylaw.
					// Whereas the above call checks this OTScriptable for all the variables on the already-loaded bylaws.
					// ----------------------------------
					//
					// VARIABLE TYPE AND ACCESS TYPE
					//
					OTVariable::OTVariable_Type theVarType = OTVariable::Var_Error_Type;
					
					if (strVarType.Compare("integer"))
						theVarType = OTVariable::Var_Integer;
					else if (strVarType.Compare("string"))
						theVarType = OTVariable::Var_String;
					else if (strVarType.Compare("bool"))
						theVarType = OTVariable::Var_Bool;
					else
						OTLog::vError("OTScriptable::ProcessXMLNode: Bad variable type: %s.\n", strVarType.Get());

					// ---------
					
					OTVariable::OTVariable_Access theVarAccess = OTVariable::Var_Error_Access;
					
					if (strVarAccess.Compare("constant"))
						theVarAccess = OTVariable::Var_Constant;
					else if (strVarAccess.Compare("persistent"))
						theVarAccess = OTVariable::Var_Persistent;
					else if (strVarAccess.Compare("important"))
						theVarAccess = OTVariable::Var_Important;
					else
						OTLog::vError("OTScriptable::ProcessXMLNode: Bad variable access type: %s.\n", strVarAccess.Get());

					// ---------
					
					if ((OTVariable::Var_Error_Access == theVarAccess) || 
						(OTVariable::Var_Error_Type == theVarType))
					{
						OTLog::vError("OTScriptable::ProcessXMLNode: Error loading variable to bylaw: "
									  "bad type (%s) or access type (%s).\n", strVarType.Get(), strVarAccess.Get());
						delete pBylaw; pBylaw=NULL;
						return (-1);
					}
					// ---------------------------------------

					bool bAddedVar = false;
					const std::string str_var_name = strVarName.Get();
					
					switch (theVarType) 
					{
						case OTVariable::Var_Integer:
							if (strVarValue.Exists())
							{
								const int nVarValue = atoi(strVarValue.Get());
								bAddedVar = pBylaw->AddVariable(str_var_name, nVarValue, theVarAccess);
							}
							else
							{
								OTLog::vError("OTScriptable::ProcessXMLNode: No value found for integer variable: %s\n",
											 strVarName.Get());
								delete pBylaw; pBylaw=NULL;
								return (-1);
							}
							break;
							// ---------------------------------
						case OTVariable::Var_Bool:
							if (strVarValue.Exists())
							{
								const bool bVarValue = strVarValue.Compare("true") ? true : false;
								bAddedVar = pBylaw->AddVariable(str_var_name, bVarValue, theVarAccess);
							}
							else
							{
								OTLog::vError("OTScriptable::ProcessXMLNode: No value found for bool variable: %s\n",
											 strVarName.Get());
								delete pBylaw; pBylaw=NULL;
								return (-1);
							}
							break;
							// ---------------------------------
						case OTVariable::Var_String:
						{
							// I realized I should probably allow empty strings.  :-P
							if (strVarValue.Exists() && strVarValue.Compare("exists"))
							{
								strVarValue.Release(); // probably unnecessary.
								if (false == LoadEncodedTextField(xml, strVarValue))
								{
									OTLog::vError("OTScriptable::ProcessXMLNode: No value found for string variable: %s\n",
												  strVarName.Get());
									delete pBylaw; pBylaw=NULL;
									return (-1);
								}
								// (else success)
							}
							else
								strVarValue.Release(); // Necessary. If it's going to be a blank string, then let's make sure.

							const std::string str_var_value = strVarValue.Get();
							bAddedVar = pBylaw->AddVariable(str_var_name, str_var_value, theVarAccess);
						}
							break;
						default:
							OTLog::Error("OTScriptable::ProcessXMLNode: Wrong variable type... "
										 "somehow AFTER I should have already detected it...\n");
							delete pBylaw; pBylaw=NULL;
							return (-1);							
					}
					// -------------------------------------------------

					if (false == bAddedVar)
					{
						OTLog::Error("OTScriptable::ProcessXMLNode: Failed adding variable to bylaw.\n");
						delete pBylaw; pBylaw=NULL;
						return (-1);
					}
					
//					xml->read(); // <==================
					
					// MIGHT NEED TO HAVE "SKIP AFTER" HERE...
					// Update: Nope.
					
					
//					if (false == SkipAfterLoadingField(xml))
//					{ 
//						OTLog::Output(0, "*** OTScriptable::ProcessXMLNode: Bad data? Expected EXN_ELEMENT_END here, but "
//									"didn't get it. Failure.\n"); 
//						delete pBylaw; pBylaw=NULL;
//						return (-1);
//					}
				}				
				else 
				{
					OTLog::Error("Expected variable element in bylaw, OTScriptable::ProcessXMLNode\n");
					delete pBylaw; pBylaw=NULL;
					return (-1); // error condition
				}
			} // while
		}
		
		// ---------------------------------------------------------------------------
		// LOAD CLAUSES
		//
		nCount	= strNumClauses.Exists() ? atoi(strNumClauses.Get()) : 0;
		if (nCount > 0)
		{
			while (nCount-- > 0)
			{
				// LoadEncodedTextFieldByName() (below) does this stuff already. Commented out.
				//
//				xml->read(); // <==================
//				if (false == OTContract::SkipToElement(xml))
//				{
//					OTLog::Error("OTScriptable::ProcessXMLNode: Error finding expected next element for variable.\n");
//					delete pBylaw; pBylaw=NULL;
//					return (-1);
//				}
				// -----------------------------------------------
				
				const char	*	pElementExpected	= "clause";
				OTString		strTextExpected; // clause's script code will go here.
				
				mapOfStrings	temp_MapAttributes;
				//
				// This map contains values we will also want, when we read the clause... 
				// (The LoadEncodedTextField call below will read all the values
				// as specified in this map.)
				// 
				//
				temp_MapAttributes.insert(std::pair<std::string, std::string>("name", ""));
//				temp_MapAttributes.insert(std::pair<std::string, std::string>("name", ""));   // Grab the others this way as well.
//				temp_MapAttributes.insert(std::pair<std::string, std::string>("name", ""));
//				temp_MapAttributes.insert(std::pair<std::string, std::string>("name", ""));
//				temp_MapAttributes.insert(std::pair<std::string, std::string>("name", ""));
//				temp_MapAttributes.insert(std::pair<std::string, std::string>("name", ""));
//				temp_MapAttributes.insert(std::pair<std::string, std::string>("name", ""));
				
				if (false == LoadEncodedTextFieldByName(xml, strTextExpected, pElementExpected, &temp_MapAttributes)) // </clause>
				{
					OTLog::vError("Error in OTScriptable::ProcessXMLNode: "
								  "Expected %s element with text field.\n", 
								  pElementExpected);
					delete pBylaw; pBylaw = NULL;
					return (-1); // error condition
				}
				
				// Okay we now have the script code in strTextExpected. Next, let's read the clause's NAME
				// from the map. If it's there, and presumably some kind of harsh validation for both, then
				// create a clause object and add to my list here.
				// ------------------------------------------
				
				mapOfStrings::iterator it = temp_MapAttributes.find("name");
				
				if ((it != temp_MapAttributes.end())) // We expected this much.
				{					
					std::string & str_name = (*it).second;
					
					if (str_name.size() > 0) // SUCCESS
					{
						// ---------------------------------------
						
//						if (false == SkipAfterLoadingField(xml))  // NOt sure yet about this block....
//						{ 
//							OTLog::Output(0, "*** OTScriptable::ProcessXMLNode: Bad data? Expected EXN_ELEMENT_END here, but "
//										  "didn't get it. Failure.\n"); 
//							delete pBylaw; pBylaw=NULL;
//							return (-1);
//						}
						// *****************************************************					
						
						// See if the same-named clause already exists on ANY of the OTHER BYLAWS
						// (There can only be one clause on an OTScriptable with a given name.)
						//
						OTClause * pClause = this->GetClause(str_name.c_str());
						
						if (NULL != pClause) // Uh-oh, it's already there!
						{
							OTLog::vOutput(0, "OTScriptable::ProcessXMLNode: Error loading clause named %s, since one was already "
										   "there on one of the bylaws.\n", str_name.c_str());
							delete pBylaw; pBylaw=NULL;
							return (-1);
						}
						// ---------------------------------------------------------
						else if (false == pBylaw->AddClause(str_name.c_str(), 
															strTextExpected.Get()))
						{
							OTLog::Error("OTScriptable::ProcessXMLNode: Failed adding clause to bylaw.\n");
							delete pBylaw; pBylaw=NULL;
							return (-1); // error condition
						}
					}
					// else it's empty, which is expected if nothing was there, since that's the default value
					// that we set above for "name" in temp_MapAttributes. 
					else 
					{
						OTLog::Error("Expected clause name in OTScriptable::ProcessXMLNode\n");
						delete pBylaw; pBylaw=NULL;
						return (-1); // error condition
					}
				}
				else 
				{
					OTLog::Error("Strange error in OTScriptable::ProcessXMLNode: couldn't find name AT ALL.\n");
					delete pBylaw; pBylaw=NULL;
					return (-1); // error condition
				}
			} // while
		} // if strNumClauses.Exists() && nCount > 0		
		
		
		// ---------------------------------------------------------------------------
		//
		// LOAD HOOKS.
		//
		nCount	= strNumHooks.Exists() ? atoi(strNumHooks.Get()) : 0;
		if (nCount > 0)
		{
			while (nCount-- > 0)
			{
//				xml->read();
				if (false == SkipToElement(xml))
				{
					OTLog::Output(0, "OTScriptable::ProcessXMLNode: Failure: Unable to find expected element.\n");
					delete pBylaw; pBylaw=NULL;
					return (-1);
				}
				// --------------------------------------
				
				if ((xml->getNodeType() == EXN_ELEMENT) && (!strcmp("hook", xml->getNodeName())))
				{
					OTString strHookName	= xml->getAttributeValue("name"); // Name of standard hook such as hook_activate or cron_process, etc
					OTString strClause		= xml->getAttributeValue("clause"); // Name of clause on this Bylaw that should trigger when that callback occurs.
					
					// ----------------------------------
					
					if (!strHookName.Exists() || !strClause.Exists())
					{
						OTLog::Error("OTScriptable::ProcessXMLNode: Expected missing name or clause while loading hook.\n");
						delete pBylaw; pBylaw=NULL;
						return (-1);
					}
					// ---------------------------------------

					if (false == pBylaw->AddHook(strHookName.Get(), strClause.Get()))
					{
						OTLog::Error("OTScriptable::ProcessXMLNode: Failed adding hook to bylaw.\n");
						delete pBylaw; pBylaw=NULL;
						return (-1);
					}
					// ---------------------------------------
					
//					xml->read(); // <==================  NO NEED FOR THIS HERE.
				}				
				else 
				{
					OTLog::Error("Expected hook element in bylaw, OTScriptable::ProcessXMLNode\n");
					delete pBylaw; pBylaw=NULL;
					return (-1); // error condition
				}
			} // while
		}

		// ---------------------------------------------------------------
		//
		// LOAD CALLBACKS.
		//
		nCount	= 0;
		nCount	= strNumCallbacks.Exists() ? atoi(strNumCallbacks.Get()) : 0;
		if (nCount > 0)
		{
			while (nCount-- > 0)
			{
//				xml->read();
				if (false == SkipToElement(xml))
				{
					OTLog::Output(0, "OTScriptable::ProcessXMLNode: Failure: Unable to find expected element.\n");
					delete pBylaw; pBylaw=NULL;
					return (-1);
				}
				// --------------------------------------
				
				if ((xml->getNodeType() == EXN_ELEMENT) && (!strcmp("callback", xml->getNodeName())))
				{
					OTString strCallbackName	= xml->getAttributeValue("name"); // Name of standard callback such as OnActivate, OnDeactivate, etc
					OTString strClause			= xml->getAttributeValue("clause"); // Name of clause on this Bylaw that should trigger when that hook occurs.
					
					// ----------------------------------
					
					if (!strCallbackName.Exists() || !strClause.Exists())
					{
						OTLog::vError("OTScriptable::ProcessXMLNode: Expected, yet nevertheless missing, name or clause while loading "
									  "callback for bylaw %s.\n", strName.Get());
						delete pBylaw; pBylaw=NULL;
						return (-1);
					}
					// ---------------------------------------
					// See if the same-named callback already exists on ANY of the OTHER BYLAWS
					// (There can only be one clause to handle any given callback.)
					//
					OTClause * pClause = this->GetCallback(strCallbackName.Get());
					
					if (NULL != pClause) // Uh-oh, it's already there!
					{
						OTLog::vOutput(0, "OTScriptable::ProcessXMLNode: Error loading callback %s, since one was already there on one of the other bylaws.\n",
									   strCallbackName.Get());
						delete pBylaw; pBylaw=NULL;
						return (-1);
					}
					// The below call checks to see if it's already there, but only for the currently-loading bylaw.
					// Whereas the above call checks this OTScriptable for all the already-loaded bylaws.
					// ---------------------------------------
					
					if (false == pBylaw->AddCallback(strCallbackName.Get(), strClause.Get()))
					{
						OTLog::vError("OTScriptable::ProcessXMLNode: Failed adding callback (%s) to bylaw (%s).\n",
									  strCallbackName.Get(), strName.Get());
						delete pBylaw; pBylaw=NULL;
						return (-1);
					}
					// ---------------------------------------
					
//					xml->read(); // <==================    NO NEED FOR THIS HERE.
				}				
				else 
				{
					OTLog::Error("Expected callback element in bylaw, OTScriptable::ProcessXMLNode\n");
					delete pBylaw; pBylaw=NULL;
					return (-1); // error condition
				}
			} // while
		}
		
		// --------------------------------
		if (false == SkipAfterLoadingField(xml))  // </bylaw>
		{ 
			OTLog::Output(0, "*** OTScriptable::ProcessXMLNode: Bad data? Expected EXN_ELEMENT_END here, but "
						  "didn't get it. Failure.\n"); 
			delete pBylaw; pBylaw=NULL;
			return (-1);
		}
		// --------------------------------						
		
		if (AddBylaw(*pBylaw))
		{
			OTLog::vOutput(2, "OTScriptable: Loaded Bylaw: %s\n", 
						   pBylaw->GetName().Get());
			
		}
		else 
		{
			OTLog::vError("OTScriptable: Failed loading Bylaw: %s\n", 
						  pBylaw->GetName().Get());
			delete pBylaw; pBylaw = NULL;
			return (-1); // error condition
		}
		
		nReturnVal = 1;
	} // "bylaw"
	
	return nReturnVal;
}



// Look up the first (and hopefully only) variable registered for a given name.
// (Across all of my Bylaws)
//
OTVariable * OTScriptable::GetVariable(const std::string str_VarName)
{
	if (false == OTScriptable::ValidateName(str_VarName)) // this logs, FYI.
	{
		OTLog::Error("OTScriptable::GetVariable:  Error: invalid name.\n");
		return NULL;
	}
	// -------------------------------------
	
	FOR_EACH(mapOfBylaws, m_mapBylaws)
	{
		OTBylaw * pBylaw = (*it).second;
		OT_ASSERT(NULL != pBylaw);
		// -------------------------
		
		OTVariable * pVar = pBylaw->GetVariable(str_VarName);
		
		if (NULL != pVar) // found it.
			return pVar;
	}
	
	return NULL;		
}


// Look up the first (and hopefully only) clause registered for a given callback.
//
OTClause * OTScriptable::GetCallback(const std::string str_CallbackName)
{
	if ((false == OTScriptable::ValidateName(str_CallbackName)) ||
		(str_CallbackName.compare(0,9,"callback_") != 0)) // this logs, FYI.
	{
		OTLog::vError("OTScriptable::GetCallback:  Error: invalid name: %s\n", str_CallbackName.c_str());
		return NULL;
	}
	// -------------------------------------
	FOR_EACH(mapOfBylaws, m_mapBylaws)
	{
		OTBylaw * pBylaw = (*it).second;
		OT_ASSERT(NULL != pBylaw);
		// -------------------------
		
		OTClause * pClause = pBylaw->GetCallback(str_CallbackName);

		if (NULL != pClause) // found it.
			return pClause;
	}
	
	return NULL;	
}


// Look up all clauses matching a specific hook.
//
bool OTScriptable::GetHooks(const std::string str_HookName, mapOfClauses & theResults)
{
	if (
		(false == OTScriptable::ValidateName(str_HookName))
		||
		((str_HookName.compare(0,5,"cron_") != 0) && (str_HookName.compare(0,5,"hook_") != 0))
	   ) // this logs, FYI.
	{
		OTLog::Error("OTScriptable::GetHooks:  Error: invalid name.\n");
		return NULL;
	}
	// -------------------------------------
	bool bReturnVal = false;
	
	FOR_EACH(mapOfBylaws, m_mapBylaws)
	{
		OTBylaw * pBylaw = (*it).second;
		OT_ASSERT(NULL != pBylaw);
		// -------------------------
		
		// Look up all clauses matching a specific hook.
		//
		if (pBylaw->GetHooks(str_HookName, theResults))
			bReturnVal = true;
	}
	
	return bReturnVal;
}



void OTScriptable::Release()
{	
	// Go through the existing list of parties and bylaws at this point, and delete them all.
	// (After all, I own them.)
	//
	while (!m_mapParties.empty())
	{		
		OTParty * pParty = m_mapParties.begin()->second;
		
		OT_ASSERT(NULL != pParty);
		
		delete pParty;
		pParty = NULL;
		
		m_mapParties.erase(m_mapParties.begin());
	}	
	while (!m_mapBylaws.empty())
	{		
		OTBylaw * pBylaw = m_mapBylaws.begin()->second;
		
		OT_ASSERT(NULL != pBylaw);
		
		delete pBylaw;
		pBylaw = NULL;
		
		m_mapBylaws.erase(m_mapBylaws.begin());
	}	
	
	// If there were any dynamically allocated objects, clean them up here.
	
	OTContract::Release(); // since I've overridden the base class, I call it now...	
}


OTScriptable::OTScriptable() :  OTContract()
{

}

OTScriptable::~OTScriptable()
{
	// ~OTContract calls Release already.
//	Release();
}



bool OTScriptable::SaveContractWallet(std::ofstream & ofs)
{
	return true;
}


