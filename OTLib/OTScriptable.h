/************************************************************************************
 *    
 *  OTScriptable.h
 * 
 *  This is just like OTContract, except it also has "Bylaws" and "Parties".
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


#ifndef __OTSCRIPTABLE_H__
#define __OTSCRIPTABLE_H__

#include <string>


#include "OTContract.h"

#include "OTBylaw.h"
#include "OTScript.h"

#include "OTString.h"

class OTAccount;


class OTScriptable : public OTContract
{
protected:
	mapOfParties		m_mapParties;	// The parties to the contract. Could be Nyms, or other entities. May be rep'd by an Agent.
	
	mapOfBylaws			m_mapBylaws;	// The Bylaws for this contract.
	// -------------------------------------------------------------------

	// return -1 if error, 0 if nothing, and 1 if the node was processed.
	virtual int ProcessXMLNode(irr::io::IrrXMLReader*& xml);
public:
	// ----------------------------------------------------
	int GetPartyCount() const { return m_mapParties.size(); }
	int GetBylawCount() const { return m_mapBylaws.size(); }
	
	virtual bool AddParty(OTParty & theParty); // Takes ownership.
	virtual bool AddBylaw(OTBylaw & theBylaw); // takes ownership.

	virtual bool ConfirmParty(OTParty & theParty); // Takes ownership.
	// ----------------------------------------------------
	OTParty		* GetParty	(const std::string str_party_name);
	OTBylaw		* GetBylaw	(const std::string str_bylaw_name);
	OTClause	* GetClause	(const std::string str_clause_name);
	// ----------------------------------------------------
	OTParty * FindPartyBasedOnNymAsAgent(OTPseudonym & theNym, OTAgent ** ppAgent=NULL);
	OTParty * FindPartyBasedOnNymAsAuthAgent(OTPseudonym & theNym, OTAgent ** ppAgent=NULL);
	OTParty * FindPartyBasedOnAccount(OTAccount & theAccount, OTPartyAccount ** ppPartyAccount=NULL);
	// ----------------------------------------------------
	OTParty * FindPartyBasedOnNymIDAsAgent(const OTIdentifier & theNymID, OTAgent ** ppAgent=NULL) const;
	OTParty * FindPartyBasedOnNymIDAsAuthAgent(const OTIdentifier & theNymID, OTAgent ** ppAgent=NULL);
	OTParty * FindPartyBasedOnAccountID(const OTIdentifier & theAcctID, OTPartyAccount ** ppPartyAccount=NULL);
	// ----------------------------------------------------
	OTAgent			* GetAgent(const std::string str_agent_name);
	OTPartyAccount	* GetPartyAccount(const std::string str_acct_name);
	OTPartyAccount	* GetPartyAccountByID(const OTIdentifier & theAcctID) const;
	// -----------------------------------------------------------------

	// -----------------------------------------------------------------
	// This function returns the count of how many trans#s a Nym needs in order to confirm as 
	// a specific agent for a contract. (An opening number is needed for every party of which
	// agent is the authorizing agent, plus a closing number for every acct of which agent is the
	// authorized agent.)
	//
	int  GetCountTransNumsNeededForAgent(const std::string str_agent_name);
	
	// ----------------------------------------------------
	// Verifies that Nym is actually an agent for this agreement.
	// (Verifies that Nym has signed this agreement, if it's a trade or a payment plan, OR
	// that the authorizing agent for Nym's party has done so,
	// and in that case, that theNym is listed as an agent for that party.)
	// Basically this means that the agreement's owner approves of theNym.
	//
	virtual bool VerifyNymAsAgent(OTPseudonym & theNym, 
								  OTPseudonym & theSignerNym, 
								  mapOfNyms	* pmap_ALREADY_LOADED=NULL);
	
	// NEED TO CALL BOTH METHODS. (above / below)
	
	// Verifies that theNym is actually an agent for theAccount, according to the PARTY.
	// Also verifies that theNym is an agent for theAccount, according to the ACCOUNT.
	//
	virtual bool VerifyNymAsAgentForAccount(OTPseudonym & theNym, OTAccount & theAccount);
	
	// -----------------------------------------------------------------
	// 
	bool VerifyPartyAuthorization(OTParty			& theParty,		// The party that supposedly is authorized for this supposedly executed agreement.
								  OTPseudonym		& theSignerNym,	// For verifying signature on the authorizing Nym, when loading it
								  const OTString	& strServerID,	// For verifying issued num, (need the serverID the # goes with.)
								  mapOfNyms			* pmap_ALREADY_LOADED=NULL, // If some nyms are already loaded, pass them here so we don't load them twice on accident.
								  const bool		  bBurnTransNo=false); // In OTServer::VerifySmartContract(), it not only wants to verify the # is properly issued, but it additionally wants to see that it hasn't been USED yet -- AND it wants to burn it, so it can't be used again!  This bool allows you to tell the function whether or not to do that.
	
	bool VerifyPartyAcctAuthorization(OTPartyAccount	& thePartyAcct,	// The party is assumed to have been verified already via VerifyPartyAuthorization()
									  OTPseudonym		& theSignerNym,	// For verifying signature on the authorized Nym
									  const OTString	& strServerID, // For verifying issued num, need the serverID the # goes with.
									  const bool		  bBurnTransNo=false); // In OTServer::VerifySmartContract(), it not only wants to verify the closing # is properly issued, but it additionally wants to see that it hasn't been USED yet -- AND it wants to burn it, so it can't be used again!  This bool allows you to tell the function whether or not to do that.		
	
	bool VerifyThisAgainstAllPartiesSignedCopies();

	bool AllPartiesHaveSupposedlyConfirmed();
	
	// -----------------------------------------------------------------------------------
	// Often we endeavor to avoid loading the same Nym twice, and a higher-level function
	// will ask an OTScriptable for a list of all the Nym pointers that it already has,
	// so they can be checked for various things if they are already loaded (when they are needed)
	// without having to load them again in order to check those things, purely out of blindness
	// to the fact that they had infact already been loaded and were floating around in memory somewhere.
	//
	void RetrieveNymPointers(mapOfNyms & map_Nyms_Already_Loaded);
	
	// ----------------
	// Look up all clauses matching a specific hook.
	// (Across all Bylaws) Automatically removes any duplicates.
	// That is, you can have multiple clauses registered to the same
	// hook name, but you can NOT have the same clause name repeated
	// multiple times in theResults. Each clause can only trigger once.
	//
	bool GetHooks(const std::string str_HookName, mapOfClauses & theResults);

	// See if a scripted clause was provided for any given callback name.
	// 
	OTClause	* GetCallback(const std::string str_CallbackName);
	
	// See if a variable exists for a given variable name.
	// 
	OTVariable	* GetVariable(const std::string str_VarName);
	
	// ---------------------------------
	
	bool IsDirty() const;	// So you can tell if any of the persistent or important variables have CHANGED since it was last set clean.
	bool IsDirtyImportant() const;	// So you can tell if ONLY the IMPORTANT variables have CHANGED since it was last set clean.
	void SetAsClean();		// Sets the variables as clean, so you can check later and see if any have been changed (if it's DIRTY again.)
	// --------------------------------------------------------------------
	
	bool SendNoticeToAllParties(OTPseudonym & theServerNym,
								const OTIdentifier & theServerID,
								const long & lNewTransactionNumber,
//								const long & lInReferenceTo, // each party has its own opening trans #.
								const OTString & strReference,
								OTString * pstrNote=NULL,
								OTString * pstrAttachment=NULL);
	
	bool DropServerNoticeToNymbox(OTPseudonym & theServerNym,
								  const OTIdentifier & SERVER_ID,
								  const OTIdentifier & USER_ID,
                                  const long & lNewTransactionNumber,
								  const long & lInReferenceTo,
                                  const OTString & strReference,
                                  OTString * pstrNote=NULL,
                                  OTString * pstrAttachment=NULL);
	
	// ----------------

	// This is an OT Native call party_may_execute_clause
	// It returns true/false whether party is allowed to execute clause.
	// The default return value, for a legitimate party, is true.
	// If you want to override that behavior, add a script callback named callback_party_may_execute_clause to your OTScriptable.
	// CanExecuteClause will call ExecuteCallback() if that script exists, so the script can reply true/false.
	//
	bool CanExecuteClause(const std::string str_party_name, const std::string str_clause_name); // This calls (if available) the scripted clause: bool party_may_execute_clause(party_name, clause_name)

	//
	// Also: callback_party_may_execute_clause should expect two parameters: param_party_name and param_clause_name, both strings.
	// Also: callback_party_may_execute_clause should return a bool.
	
	
	bool ExecuteCallback (OTClause & theCallbackClause, mapOfVariables & theParameters, OTVariable & varReturnVal);

	virtual void RegisterOTNativeCallsWithScript(OTScript & theScript);

	virtual bool Compare(OTScriptable & rhs);

	// ----------------

	static OTScriptable * InstantiateScriptable(const OTString & strInput);
	
	// Make sure a string contains only alpha, numeric, or '_'
	// And make sure it's not blank. This is for script variable names, clause names, party names, etc.
	//
	static bool ValidateName(const std::string str_name);

	// ------------------------
	// For use from inside server-side scripts.
	//
	static std::string GetTime(); // Returns a string, containing seconds as int. (Time in seconds.)
	
	// ------------------------
	
	OTScriptable();

	virtual ~OTScriptable();

	void UpdateContentsToString(OTString & strAppend);

	virtual void Release();
	virtual void UpdateContents();
//	virtual bool SaveContractWallet(FILE * fl);	
	virtual bool SaveContractWallet(std::ofstream & ofs);

};





#endif // __OTSCRIPTABLE_H__

