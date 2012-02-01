/************************************************************************************
 
 OTAPI_Wrapper.cpp   --	A C++ wrapper class (called OTAPI_Wrap) for the C functions 
 in OTAPI.h
 
 Ironically, the C functions in OTAPI.h are wrappers around a C++ class.
 
 But I had to add this class for compatibility reasons with OTScript, since
 the current "chai" interpreter seems to prefer C++, and I think I'm having
 problems right now due to direct use of "extern C" functions with chai. So
 I'm adding this wrapper, at least to see if that will fix it :P
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


#include <iostream>
#include <string>




#include "OTAPI_Wrapper.h"

#include "OTLog.h"

// --------------------------------

#ifndef OT_BOOL
#define OT_BOOL int
#endif

#ifndef OT_FALSE
const int OT_FALSE = 0;
#endif

#ifndef OT_TRUE
const int OT_TRUE = 1;
#endif



// All methods in this class are STATIC.



/*
 // CRASHES with Chaiscript.  Adding a std::string wrapper.
 
const char * OTAPI_Wrap::Create_SmartContract(const char * SERVER_ID,
											  const char * SIGNER_NYM_ID,	// Use any Nym you wish here. (The signing at this point is only to cause a save.)
											  // ----------------------------------------
											  const char * VALID_FROM,	// Default (0 or NULL) == NOW
											  const char * VALID_TO)
{
	std::cout << "ABOUT TO CALL IT..." << std::endl;
	
	const char * pChar = OT_API_Create_SmartContract(SERVER_ID, SIGNER_NYM_ID, VALID_FROM, VALID_TO);

	std::cout << "FINISHED CALLING IT..." << std::endl;

	return pChar;
}
*/


// --------------------------------------------------------------
void OTAPI_Wrap::Output(const int nLogLevel, const std::string STR_OUTPUT)
{
	OT_API_Output(nLogLevel, STR_OUTPUT.c_str());
}

std::string OTAPI_Wrap::GetTime()
{
	return OT_API_GetTime();
}
// --------------------------------------------------------------



std::string OTAPI_Wrap::Encode(std::string str_Plaintext, bool bLineBreaks) // bLineBreaks is OT_BOOL
{
	return OT_API_Encode(str_Plaintext.c_str(), bLineBreaks ? OT_TRUE : OT_FALSE);
}

std::string OTAPI_Wrap::Decode(std::string str_Encoded, bool bLineBreaks) // bLineBreaks is OT_BOOL
{
	return OT_API_Decode(str_Encoded.c_str(), bLineBreaks ? OT_TRUE : OT_FALSE);
}

std::string OTAPI_Wrap::Encrypt(std::string RECIPIENT_NYM_ID, std::string str_Plaintext)
{
	return OT_API_Encrypt(RECIPIENT_NYM_ID.c_str(), str_Plaintext.c_str());
}

std::string OTAPI_Wrap::Decrypt(std::string RECIPIENT_NYM_ID, std::string str_Ciphertext)
{
	return OT_API_Decrypt(RECIPIENT_NYM_ID.c_str(), str_Ciphertext.c_str());
}

std::string OTAPI_Wrap::SignContract(std::string SIGNER_NYM_ID, std::string THE_CONTRACT)
{
	return OT_API_SignContract(SIGNER_NYM_ID.c_str(), THE_CONTRACT.c_str());
}

std::string OTAPI_Wrap::AddSignature(std::string SIGNER_NYM_ID, std::string THE_CONTRACT)
{
	return OT_API_AddSignature(SIGNER_NYM_ID.c_str(), THE_CONTRACT.c_str());
}

bool OTAPI_Wrap::VerifySignature(std::string SIGNER_NYM_ID, std::string THE_CONTRACT)
{
	return (OT_TRUE == OT_API_VerifySignature(SIGNER_NYM_ID.c_str(), THE_CONTRACT.c_str())) ? true : false;
}




// --------------------------------------------------------------

const std::string OTAPI_Wrap::Create_SmartContract(const std::string SERVER_ID,
												   const std::string SIGNER_NYM_ID,	// Use any Nym you wish here. (The signing at this point is only to cause a save.)
												   // ----------------------------------------
												   const std::string VALID_FROM,	// Default (0 or NULL) == NOW
												   const std::string VALID_TO)
{
	return OT_API_Create_SmartContract(SERVER_ID.c_str(), SIGNER_NYM_ID.c_str(), VALID_FROM.c_str(), VALID_TO.c_str());
}




const std::string OTAPI_Wrap::SmartContract_AddBylaw(const std::string THE_CONTRACT,	// The contract, about to have the bylaw added to it.
													 const std::string SIGNER_NYM_ID,	// Use any Nym you wish here. (The signing at this point is only to cause a save.)
													 // ----------------------------------------
													 const std::string BYLAW_NAME)	// The Bylaw's NAME as referenced in the smart contract. (And the scripts...)
{
	return OT_API_SmartContract_AddBylaw(THE_CONTRACT.c_str(), SIGNER_NYM_ID.c_str(), BYLAW_NAME.c_str());		
}

// returns: the updated smart contract (or NULL)
const std::string OTAPI_Wrap::SmartContract_AddClause(const std::string THE_CONTRACT,	// The contract, about to have the clause added to it.
													  const std::string SIGNER_NYM_ID,	// Use any Nym you wish here. (The signing at this point is only to cause a save.)
													  // ----------------------------------------
													  const std::string BYLAW_NAME,	// Should already be on the contract. (This way we can find it.)
													  // ----------------------------------------
													  const std::string CLAUSE_NAME,	// The Clause's name as referenced in the smart contract. (And the scripts...)
													  const std::string SOURCE_CODE)	// The actual source code for the clause.
{
	return OT_API_SmartContract_AddClause(THE_CONTRACT.c_str(), SIGNER_NYM_ID.c_str(), BYLAW_NAME.c_str(), CLAUSE_NAME.c_str(), SOURCE_CODE.c_str());	
}

// returns: the updated smart contract (or NULL)
const std::string OTAPI_Wrap::SmartContract_AddVariable(const std::string THE_CONTRACT,	// The contract, about to have the variabnle added to it.
														const std::string SIGNER_NYM_ID,	// Use any Nym you wish here. (The signing at this point is only to cause a save.)
														// ----------------------------------------
														const std::string BYLAW_NAME,	// Should already be on the contract. (This way we can find it.)
														// ----------------------------------------
														const std::string VAR_NAME,	// The Variable's name as referenced in the smart contract. (And the scripts...)
														const std::string VAR_ACCESS,	// "constant", "persistent", or "important".
														const std::string VAR_TYPE,	// "string", "long", or "bool"
														const std::string VAR_VALUE)	// Contains a string. If type is long, atol() will be used to convert value to a long. If type is bool, the strings "true" or "false" are expected here in order to convert to a bool.
{
	return OT_API_SmartContract_AddVariable(THE_CONTRACT.c_str(), SIGNER_NYM_ID.c_str(), BYLAW_NAME.c_str(), 
											VAR_NAME.c_str(), VAR_ACCESS.c_str(), 
											VAR_TYPE.c_str(), VAR_VALUE.c_str());	
}

// returns: the updated smart contract (or NULL)
const std::string OTAPI_Wrap::SmartContract_AddCallback(const std::string THE_CONTRACT,	// The contract, about to have the callback added to it.
														const std::string SIGNER_NYM_ID,	// Use any Nym you wish here. (The signing at this point is only to cause a save.)
														// ----------------------------------------
														const std::string BYLAW_NAME,	// Should already be on the contract. (This way we can find it.)
														// ----------------------------------------
														const std::string CALLBACK_NAME,	// The Callback's name as referenced in the smart contract. (And the scripts...)
														const std::string CLAUSE_NAME)	// The actual clause that will be triggered by the callback. (Must exist.)
{
	return OT_API_SmartContract_AddCallback(THE_CONTRACT.c_str(), SIGNER_NYM_ID.c_str(), BYLAW_NAME.c_str(), CALLBACK_NAME.c_str(), CLAUSE_NAME.c_str());	
}

// returns: the updated smart contract (or NULL)
const std::string OTAPI_Wrap::SmartContract_AddHook(const std::string THE_CONTRACT,	// The contract, about to have the hook added to it.
													const std::string SIGNER_NYM_ID,	// Use any Nym you wish here. (The signing at this point is only to cause a save.)
													// ----------------------------------------
													const std::string BYLAW_NAME,		// Should already be on the contract. (This way we can find it.)
													// ----------------------------------------
													const std::string HOOK_NAME,		// The Hook's name as referenced in the smart contract. (And the scripts...)
													const std::string CLAUSE_NAME)	// The actual clause that will be triggered by the hook. (You can call this multiple times, and have multiple clauses trigger on the same hook.)
{
	return OT_API_SmartContract_AddHook(THE_CONTRACT.c_str(), SIGNER_NYM_ID.c_str(), BYLAW_NAME.c_str(), HOOK_NAME.c_str(), CLAUSE_NAME.c_str());	
}

// --------------------------------------------------------------




// RETURNS: Updated version of THE_CONTRACT. (Or NULL.)
const std::string OTAPI_Wrap::SmartContract_AddParty(const std::string THE_CONTRACT,	// The contract, about to have the party added to it.
													 const std::string SIGNER_NYM_ID,	// Use any Nym you wish here. (The signing at this point is only to cause a save.)
													 // ----------------------------------------
													 const std::string PARTY_NAME,		// The Party's NAME as referenced in the smart contract. (And the scripts...)
													 // ----------------------------------------
													 const std::string AGENT_NAME)	// An AGENT will be added by default for this party. Need Agent NAME.
// (FYI, that is basically the only option, until I code Entities and Roles. Until then, a party can ONLY be
// a Nym, with himself as the agent representing that same party. Nym ID is supplied on ConfirmParty() below.)
{
	return OT_API_SmartContract_AddParty(THE_CONTRACT.c_str(), SIGNER_NYM_ID.c_str(), PARTY_NAME.c_str(), AGENT_NAME.c_str());	
}

// ----------------------------------------

// Used when creating a theoretical smart contract (that could be used over and over again with different parties.)
//
// returns: the updated smart contract (or NULL)
const std::string OTAPI_Wrap::SmartContract_AddAccount(const std::string THE_CONTRACT,	// The contract, about to have the account added to it.
													   const std::string SIGNER_NYM_ID,	// Use any Nym you wish here. (The signing at this point is only to cause a save.)
													   // ----------------------------------------
													   const std::string PARTY_NAME,	// The Party's NAME as referenced in the smart contract. (And the scripts...)
													   // ----------------------------------------
													   const std::string ACCT_NAME,		// The Account's name as referenced in the smart contract
													   const std::string ASSET_TYPE_ID)	// Asset Type ID for the Account.
{
	return OT_API_SmartContract_AddAccount(THE_CONTRACT.c_str(), SIGNER_NYM_ID.c_str(), PARTY_NAME.c_str(), ACCT_NAME.c_str(), ASSET_TYPE_ID.c_str());	
}

// ----------------------------------------

int OTAPI_Wrap::SmartContract_CountNumsNeeded(const std::string THE_CONTRACT,	// The smart contract, about to be queried by this function.
											  const std::string AGENT_NAME)
{
	return OT_API_SmartContract_CountNumsNeeded(THE_CONTRACT.c_str(), AGENT_NAME.c_str());
}



// Used when taking a theoretical smart contract, and setting it up to use specific Nyms and accounts. This function sets the ACCT ID for the acct specified by party name and acct name.
// Returns the updated smart contract (or NULL.)
const std::string OTAPI_Wrap::SmartContract_ConfirmAccount(const std::string THE_CONTRACT,	// The smart contract, about to be changed by this function.
														   const std::string SIGNER_NYM_ID,	// Use any Nym you wish here. (The signing at this point is only to cause a save.)
														   // ----------------------------------------
														   const std::string PARTY_NAME,	// Should already be on the contract. (This way we can find it.)
														   // ----------------------------------------
														   const std::string ACCT_NAME,	// Should already be on the contract. (This way we can find it.)
														   const std::string AGENT_NAME,	// The agent name for this asset account.
														   const std::string ACCT_ID)		// AcctID for the asset account. (For acct_name).
{
	return OT_API_SmartContract_ConfirmAccount(THE_CONTRACT.c_str(), SIGNER_NYM_ID.c_str(), PARTY_NAME.c_str(), 
											   ACCT_NAME.c_str(), AGENT_NAME.c_str(), ACCT_ID.c_str());	
}

// Called by each Party. Pass in the smart contract obtained in the above call.
// Call OTAPI_Wrap::SmartContract_ConfirmAccount() first, as much as you need to.
// Returns the updated smart contract (or NULL.)
const std::string OTAPI_Wrap::SmartContract_ConfirmParty(const std::string THE_CONTRACT,	// The smart contract, about to be changed by this function.
														 const std::string PARTY_NAME,		// Should already be on the contract. This way we can find it.
														 // ----------------------------------------
														 const std::string NYM_ID)		// Nym ID for the party, the actual owner, 
// ===> AS WELL AS for the default AGENT of that party.
{
	return OT_API_SmartContract_ConfirmParty(THE_CONTRACT.c_str(), PARTY_NAME.c_str(), NYM_ID.c_str());
}

// ---------------------------------------------------

bool OTAPI_Wrap::HarvestClosingNumbers(const std::string SERVER_ID,
									   const std::string NYM_ID,
									   const std::string THE_CRON_ITEM)
{
	return (OT_TRUE == OT_API_HarvestClosingNumbers(SERVER_ID.c_str(), NYM_ID.c_str(), THE_CRON_ITEM.c_str())) ? true : false;
}

bool OTAPI_Wrap::HarvestAllNumbers(const std::string SERVER_ID,
								   const std::string NYM_ID,
								   const std::string THE_CRON_ITEM)
{
	return (OT_TRUE == OT_API_HarvestAllNumbers(SERVER_ID.c_str(), NYM_ID.c_str(), THE_CRON_ITEM.c_str())) ? true : false;
}

// --------------------------------------------------
/// ACTIVATE SMART CONTRACT
/// Take an existing smart contract, which has already been set up, confirmed, etc,
/// and then activate it on the server so it can start processing.
///
/// See OTAPI_Wrap::Create_SmartContract (etc.)
///
void OTAPI_Wrap::activateSmartContract(const std::string SERVER_ID,
									   const std::string USER_ID,
									   const std::string THE_SMART_CONTRACT)
{
	OT_API_activateSmartContract(SERVER_ID.c_str(), USER_ID.c_str(), THE_SMART_CONTRACT.c_str());
}

// --------------------------------------------------

// If a smart contract is already running on the server, this allows a party
// to trigger clauses on that smart contract, by name. This is NOT a transaction,
// but it DOES message the server.
//
void OTAPI_Wrap::triggerClause(const std::string SERVER_ID,
							   const std::string USER_ID,
							   const std::string TRANSACTION_NUMBER,
							   const std::string CLAUSE_NAME,
							   const std::string STR_PARAM)
{
	OT_API_triggerClause(SERVER_ID.c_str(), USER_ID.c_str(), 
						 TRANSACTION_NUMBER.c_str(), CLAUSE_NAME.c_str(), STR_PARAM.c_str());
}
// --------------------------------------------------


int OTAPI_Wrap::GetMemlogSize()
{
	return OT_API_GetMemlogSize();
}

const std::string OTAPI_Wrap::GetMemlogAtIndex(int nIndex)
{
	return OT_API_GetMemlogAtIndex(nIndex);
}

const std::string OTAPI_Wrap::PeekMemlogFront()
{
	return OT_API_PeekMemlogFront();
}

const std::string OTAPI_Wrap::PeekMemlogBack()
{
	return OT_API_PeekMemlogBack();
}

bool OTAPI_Wrap::PopMemlogFront()
{
	return (OT_API_PopMemlogFront() == OT_TRUE) ? true : false;
}

bool OTAPI_Wrap::PopMemlogBack()
{
	return (OT_API_PopMemlogBack() == OT_TRUE) ? true : false;
}


const std::string OTAPI_Wrap::CreateNym()
{
	return OT_API_CreateNym();
}


bool OTAPI_Wrap::AddServerContract(const std::string szContract)
{
	return (OT_API_AddServerContract(szContract.c_str()) == OT_TRUE) ? true : false;
}

bool OTAPI_Wrap::AddAssetContract(const std::string szContract)
{
	return (OT_API_AddAssetContract(szContract.c_str()) == OT_TRUE) ? true : false;
}

int OTAPI_Wrap::GetServerCount()
{
	return OT_API_GetServerCount();
}

int OTAPI_Wrap::GetAssetTypeCount()
{
	return OT_API_GetAssetTypeCount();
}

int OTAPI_Wrap::GetAccountCount()
{
	return OT_API_GetAccountCount();
}

int OTAPI_Wrap::GetNymCount()
{
	return OT_API_GetNymCount();
}

const std::string OTAPI_Wrap::GetServer_ID(int nIndex)
{
	return OT_API_GetServer_ID(nIndex);
}

const std::string OTAPI_Wrap::GetServer_Name(const std::string SERVER_ID)
{
	return OT_API_GetServer_Name(SERVER_ID.c_str());	
}

const std::string OTAPI_Wrap::GetAssetType_ID(int nIndex)
{
	return OT_API_GetAssetType_ID(nIndex);
}

const std::string OTAPI_Wrap::GetAssetType_Name(const std::string ASSET_TYPE_ID)
{
	return OT_API_GetAssetType_Name(ASSET_TYPE_ID.c_str());	
}

const std::string OTAPI_Wrap::GetAccountWallet_ID(int nIndex)
{
	return OT_API_GetAccountWallet_ID(nIndex);
}

const std::string OTAPI_Wrap::GetAccountWallet_Name(const std::string ACCOUNT_ID)
{
	return OT_API_GetAccountWallet_Name(ACCOUNT_ID.c_str());
}

const std::string OTAPI_Wrap::GetAccountWallet_Balance(const std::string ACCOUNT_ID)
{
	return OT_API_GetAccountWallet_Balance(ACCOUNT_ID.c_str());
}

const std::string OTAPI_Wrap::GetAccountWallet_Type(const std::string ACCOUNT_ID)
{
	return OT_API_GetAccountWallet_Type(ACCOUNT_ID.c_str());
}

const std::string OTAPI_Wrap::GetAccountWallet_AssetTypeID(const std::string ACCOUNT_ID)
{
	return OT_API_GetAccountWallet_AssetTypeID(ACCOUNT_ID.c_str());
}

const std::string OTAPI_Wrap::GetAccountWallet_ServerID(const std::string ACCOUNT_ID)
{
	return OT_API_GetAccountWallet_ServerID(ACCOUNT_ID.c_str());
}

const std::string OTAPI_Wrap::GetAccountWallet_NymID(const std::string ACCOUNT_ID)
{
	return OT_API_GetAccountWallet_NymID(ACCOUNT_ID.c_str());
}

bool OTAPI_Wrap::VerifyAccountReceipt(const std::string SERVER_ID, const std::string NYM_ID, const std::string ACCT_ID)
{
	return (OT_API_VerifyAccountReceipt(SERVER_ID.c_str(), NYM_ID.c_str(), ACCT_ID.c_str()) == OT_TRUE) ? true : false;
}

int OTAPI_Wrap::GetNym_TransactionNumCount(const std::string SERVER_ID, const std::string NYM_ID)
{
	return OT_API_GetNym_TransactionNumCount(SERVER_ID.c_str(), NYM_ID.c_str());
}

const std::string OTAPI_Wrap::GetNym_ID(int nIndex)
{
	return OT_API_GetNym_ID(nIndex);
}

const std::string OTAPI_Wrap::GetNym_Name(const std::string NYM_ID)
{
	return OT_API_GetNym_Name(NYM_ID.c_str());
}

const std::string OTAPI_Wrap::GetNym_Stats(const std::string NYM_ID)
{
	return OT_API_GetNym_Stats(NYM_ID.c_str());
}

bool OTAPI_Wrap::IsNym_RegisteredAtServer(const std::string NYM_ID, const std::string SERVER_ID)
{
	return (OT_API_IsNym_RegisteredAtServer(NYM_ID.c_str(), SERVER_ID.c_str()) == OT_TRUE) ? true : false;
}

// ---------------------------------------------------------
int	OTAPI_Wrap::GetNym_MailCount(const std::string NYM_ID)
{
	return OT_API_GetNym_MailCount(NYM_ID.c_str());
}

const std::string OTAPI_Wrap::GetNym_MailContentsByIndex(const std::string NYM_ID, int nIndex)
{
	return OT_API_GetNym_MailContentsByIndex(NYM_ID.c_str(), nIndex);
}

const std::string OTAPI_Wrap::GetNym_MailSenderIDByIndex(const std::string NYM_ID, int nIndex)
{
	return OT_API_GetNym_MailSenderIDByIndex(NYM_ID.c_str(), nIndex);
}

const std::string OTAPI_Wrap::GetNym_MailServerIDByIndex(const std::string NYM_ID, int nIndex)
{
	return OT_API_GetNym_MailServerIDByIndex(NYM_ID.c_str(), nIndex);
}

bool OTAPI_Wrap::Nym_RemoveMailByIndex(const std::string NYM_ID, int nIndex)
{
	return (OT_API_Nym_RemoveMailByIndex(NYM_ID.c_str(), nIndex) == OT_TRUE) ? true : false;
}

bool OTAPI_Wrap::Nym_VerifyMailByIndex(const std::string NYM_ID, int nIndex)
{
	return (OT_API_Nym_VerifyMailByIndex(NYM_ID.c_str(), nIndex) == OT_TRUE) ? true : false;
}

// ---------------------------------------------------------
int OTAPI_Wrap::GetNym_OutmailCount(const std::string NYM_ID)
{
	return OT_API_GetNym_OutmailCount(NYM_ID.c_str());
}

const std::string OTAPI_Wrap::GetNym_OutmailContentsByIndex(const std::string NYM_ID, int nIndex)
{
	return OT_API_GetNym_OutmailContentsByIndex(NYM_ID.c_str(), nIndex);
}

const std::string OTAPI_Wrap::GetNym_OutmailRecipientIDByIndex(const std::string NYM_ID, int nIndex)
{
	return OT_API_GetNym_OutmailRecipientIDByIndex(NYM_ID.c_str(), nIndex);
}

const std::string OTAPI_Wrap::GetNym_OutmailServerIDByIndex(const std::string NYM_ID, int nIndex)
{
	return OT_API_GetNym_OutmailServerIDByIndex(NYM_ID.c_str(), nIndex);
}

bool OTAPI_Wrap::Nym_RemoveOutmailByIndex(const std::string NYM_ID, int nIndex)
{
	return (OT_API_Nym_RemoveOutmailByIndex(NYM_ID.c_str(), nIndex) == OT_TRUE) ? true : false;
}

bool OTAPI_Wrap::Nym_VerifyOutmailByIndex(const std::string NYM_ID, int nIndex)
{
	return (OT_API_Nym_VerifyOutmailByIndex(NYM_ID.c_str(), nIndex) == OT_TRUE) ? true : false;
}
// ---------------------------------------------------------

bool OTAPI_Wrap::Wallet_CanRemoveServer(const std::string SERVER_ID)
{
	return (OT_API_Wallet_CanRemoveServer(SERVER_ID.c_str()) == OT_TRUE) ? true : false;
}
			
bool OTAPI_Wrap::Wallet_RemoveServer(const std::string SERVER_ID)
{
	return (OT_API_Wallet_RemoveServer(SERVER_ID.c_str()) == OT_TRUE) ? true : false;
}
			
bool OTAPI_Wrap::Wallet_CanRemoveAssetType(const std::string ASSET_ID)
{
	return (OT_API_Wallet_CanRemoveAssetType(ASSET_ID.c_str()) == OT_TRUE) ? true : false;
}
			
bool OTAPI_Wrap::Wallet_RemoveAssetType(const std::string ASSET_ID)
{
	return (OT_API_Wallet_RemoveAssetType(ASSET_ID.c_str()) == OT_TRUE) ? true : false;
}
			
bool OTAPI_Wrap::Wallet_CanRemoveNym(const std::string NYM_ID)
{
	return (OT_API_Wallet_CanRemoveNym(NYM_ID.c_str()) == OT_TRUE) ? true : false;
}
			
bool OTAPI_Wrap::Wallet_RemoveNym(const std::string NYM_ID)
{
	return (OT_API_Wallet_RemoveNym(NYM_ID.c_str()) == OT_TRUE) ? true : false;
}
			
bool OTAPI_Wrap::Wallet_CanRemoveAccount(const std::string ACCOUNT_ID)
{
	return (OT_API_Wallet_CanRemoveAccount(ACCOUNT_ID.c_str()) == OT_TRUE) ? true : false;
}

const std::string OTAPI_Wrap::Wallet_ImportNym(const std::string DISPLAY_NAME, const std::string KEY_FILE_CONTENTS)
{
	return OT_API_Wallet_ImportNym(DISPLAY_NAME.c_str(), KEY_FILE_CONTENTS.c_str());
}

// -----------------------------------

bool OTAPI_Wrap::SetNym_Name(const std::string NYM_ID, 
							 const std::string SIGNER_NYM_ID, 
							 const std::string NYM_NEW_NAME)
{
	return (OT_API_SetNym_Name(NYM_ID.c_str(), SIGNER_NYM_ID.c_str(), NYM_NEW_NAME.c_str()) == OT_TRUE) ? true : false;
}

bool OTAPI_Wrap::SetAccountWallet_Name(const std::string ACCT_ID, 
									   const std::string SIGNER_NYM_ID, 
									   const std::string ACCT_NEW_NAME)
{
	return (OT_API_SetAccountWallet_Name(ACCT_ID.c_str(), SIGNER_NYM_ID.c_str(), ACCT_NEW_NAME.c_str()) == OT_TRUE) ? true : false;
}

bool OTAPI_Wrap::SetAssetType_Name(const std::string ASSET_ID, 
								   const std::string STR_NEW_NAME)
{
	return (OT_API_SetAssetType_Name(ASSET_ID.c_str(), STR_NEW_NAME.c_str()) == OT_TRUE) ? true : false;
}

bool OTAPI_Wrap::SetServer_Name(const std::string SERVER_ID, 
								const std::string STR_NEW_NAME)
{
	return (OT_API_SetServer_Name(SERVER_ID.c_str(), STR_NEW_NAME.c_str()) == OT_TRUE) ? true : false;
}


const std::string OTAPI_Wrap::VerifyAndRetrieveXMLContents(const std::string THE_CONTRACT,
														   const std::string USER_ID)
{
	return OT_API_VerifyAndRetrieveXMLContents(THE_CONTRACT.c_str(), USER_ID.c_str());	
}

// ----------------------------------------------------------------------
const std::string OTAPI_Wrap::WriteCheque(const std::string SERVER_ID,
										  const std::string CHEQUE_AMOUNT, 
										  const std::string VALID_FROM, 
										  const std::string VALID_TO,
										  const std::string SENDER_ACCT_ID,
										  const std::string SENDER_USER_ID,
										  const std::string CHEQUE_MEMO, 
										  const std::string RECIPIENT_USER_ID)
{
	return OT_API_WriteCheque(SERVER_ID.c_str(),
							  CHEQUE_AMOUNT.c_str(), 
							  VALID_FROM.c_str(), 
							  VALID_TO.c_str(),
							  SENDER_ACCT_ID.c_str(),
							  SENDER_USER_ID.c_str(),
							  CHEQUE_MEMO.c_str(), 
							  RECIPIENT_USER_ID.c_str());	
}


bool OTAPI_Wrap::DiscardCheque(const std::string SERVER_ID,
							   const std::string USER_ID, 
							   const std::string ACCT_ID, 
							   const std::string THE_CHEQUE)
{
	return (OT_API_DiscardCheque(SERVER_ID.c_str(), USER_ID.c_str(), ACCT_ID.c_str(), THE_CHEQUE.c_str()) == OT_TRUE) ? true : false;
}


// ----------------------------------------------------------------------
//	const std::string OTAPI_Wrap::ProposePaymentPlan(const std::string SERVER_ID,
//										   // ----------------------------------------
//										   const std::string VALID_FROM,	// Default (0 or NULL) == NOW
//										   const std::string VALID_TO,		// Default (0 or NULL) == no expiry / cancel anytime
//										   // ----------------------------------------
//										   const std::string SENDER_ACCT_ID,	// Mandatory parameters.
//										   const std::string SENDER_USER_ID,	// Both sender and recipient must sign before submitting.
//										   // ----------------------------------------
//										   const std::string PLAN_CONSIDERATION,	// Like a memo.
//										   // ----------------------------------------
//										   const std::string RECIPIENT_ACCT_ID,	// NOT optional.
//										   const std::string RECIPIENT_USER_ID,	// Both sender and recipient must sign before submitting.
//										   // -------------------------------	
//										   const std::string INITIAL_PAYMENT_AMOUNT,	// zero or NULL == no initial payment.
//										   const std::string INITIAL_PAYMENT_DELAY,	// seconds from creation date. Default is zero or NULL.
//										   // ---------------------------------------- .
//										   const std::string PAYMENT_PLAN_AMOUNT,		// zero or NULL == no regular payments.
//										   const std::string PAYMENT_PLAN_DELAY,		// No. of seconds from creation date. Default is zero or NULL.
//										   const std::string PAYMENT_PLAN_PERIOD,		// No. of seconds between payments. Default is zero or NULL.
//										   // --------------------------------------- 
//										   const std::string PAYMENT_PLAN_LENGTH,		// In seconds. Defaults to 0 or NULL (no maximum length.)
//										   const std::string PAYMENT_PLAN_MAX_PAYMENTS	// Integer. Defaults to 0 or NULL (no maximum payments.)
//										   )
//{
//	
//}


const std::string OTAPI_Wrap::ConfirmPaymentPlan(const std::string SERVER_ID,
												 const std::string SENDER_USER_ID,
												 const std::string SENDER_ACCT_ID,
												 const std::string RECIPIENT_USER_ID,
												 const std::string PAYMENT_PLAN)
{
	return OT_API_ConfirmPaymentPlan(SERVER_ID.c_str(),
									 SENDER_USER_ID.c_str(),
									 SENDER_ACCT_ID.c_str(),
									 RECIPIENT_USER_ID.c_str(),
									 PAYMENT_PLAN.c_str());
}

// -----------------------------------------------------------------

const std::string OTAPI_Wrap::LoadUserPubkey(const std::string USER_ID)
{
	return OT_API_LoadUserPubkey(USER_ID.c_str());
}

const std::string OTAPI_Wrap::LoadPubkey(const std::string USER_ID)
{
	return OT_API_LoadPubkey(USER_ID.c_str());
}

bool OTAPI_Wrap::VerifyUserPrivateKey(const std::string USER_ID)
{
	return (OT_TRUE == OT_API_VerifyUserPrivateKey(USER_ID.c_str())) ? true : false;
}

const std::string OTAPI_Wrap::LoadPurse(const std::string SERVER_ID,
										const std::string ASSET_TYPE_ID,
										const std::string USER_ID)
{
	return OT_API_LoadPurse(SERVER_ID.c_str(), ASSET_TYPE_ID.c_str(), USER_ID.c_str());
}

const std::string OTAPI_Wrap::LoadMint(const std::string SERVER_ID,
									   const std::string ASSET_TYPE_ID)
{
	return OT_API_LoadMint(SERVER_ID.c_str(), ASSET_TYPE_ID.c_str());
}

const std::string OTAPI_Wrap::LoadAssetContract(const std::string ASSET_TYPE_ID)
{
	return OT_API_LoadAssetContract(ASSET_TYPE_ID.c_str());
}

const std::string OTAPI_Wrap::LoadServerContract(const std::string SERVER_ID)
{
	return OT_API_LoadServerContract(SERVER_ID.c_str());
}

bool OTAPI_Wrap::Mint_IsStillGood(const std::string SERVER_ID,
								  const std::string USER_ID,
								  const std::string ASSET_TYPE_ID)
{
//	return ( == OT_TRUE) ? true : false;
	
	return (OT_API_Mint_IsStillGood(SERVER_ID.c_str(), USER_ID.c_str(), ASSET_TYPE_ID.c_str()) == OT_TRUE) ? true : false;
}

bool OTAPI_Wrap::IsBasketCurrency(const std::string ASSET_TYPE_ID)
{
	return (OT_API_IsBasketCurrency(ASSET_TYPE_ID.c_str()) == OT_TRUE) ? true : false;
}

int OTAPI_Wrap::Basket_GetMemberCount(const std::string BASKET_ASSET_TYPE_ID)
{
	return OT_API_Basket_GetMemberCount(BASKET_ASSET_TYPE_ID.c_str());
}
									   
const std::string OTAPI_Wrap::Basket_GetMemberType(const std::string BASKET_ASSET_TYPE_ID,
												   const int nIndex)
{
	return OT_API_Basket_GetMemberType(BASKET_ASSET_TYPE_ID.c_str(), nIndex);
}

const std::string OTAPI_Wrap::Basket_GetMinimumTransferAmount(const std::string BASKET_ASSET_TYPE_ID)
{
	return OT_API_Basket_GetMinimumTransferAmount(BASKET_ASSET_TYPE_ID.c_str());
}

const std::string OTAPI_Wrap::Basket_GetMemberMinimumTransferAmount(const std::string BASKET_ASSET_TYPE_ID,
																	const int nIndex)
{
	return OT_API_Basket_GetMemberMinimumTransferAmount(BASKET_ASSET_TYPE_ID.c_str(), nIndex);
}

// --------------------------------------------------------------
const std::string OTAPI_Wrap::LoadAssetAccount(const std::string SERVER_ID,
											   const std::string USER_ID,
											   const std::string ACCOUNT_ID)
{
	return OT_API_LoadAssetAccount(SERVER_ID.c_str(), USER_ID.c_str(), ACCOUNT_ID.c_str());
}

const std::string OTAPI_Wrap::LoadInbox(const std::string SERVER_ID,
										const std::string USER_ID,
										const std::string ACCOUNT_ID)
{
	return OT_API_LoadInbox(SERVER_ID.c_str(), USER_ID.c_str(), ACCOUNT_ID.c_str());
}

const std::string OTAPI_Wrap::LoadOutbox(const std::string SERVER_ID,
										 const std::string USER_ID,
										 const std::string ACCOUNT_ID)
{
	return OT_API_LoadOutbox(SERVER_ID.c_str(), USER_ID.c_str(), ACCOUNT_ID.c_str());
}
// --------------------------------------------------------------
const std::string OTAPI_Wrap::LoadInboxNoVerify(const std::string SERVER_ID,
												const std::string USER_ID,
												const std::string ACCOUNT_ID)
{
	return OT_API_LoadInboxNoVerify(SERVER_ID.c_str(), USER_ID.c_str(), ACCOUNT_ID.c_str());
}

const std::string OTAPI_Wrap::LoadOutboxNoVerify(const std::string SERVER_ID,
												 const std::string USER_ID,
												 const std::string ACCOUNT_ID)
{
	return OT_API_LoadOutboxNoVerify(SERVER_ID.c_str(), USER_ID.c_str(), ACCOUNT_ID.c_str());
}
// --------------------------------------------------------------

int OTAPI_Wrap::Ledger_GetCount(const std::string SERVER_ID,
								const std::string USER_ID,
								const std::string ACCOUNT_ID,
								const std::string THE_LEDGER)
{
	return OT_API_Ledger_GetCount(SERVER_ID.c_str(), USER_ID.c_str(), ACCOUNT_ID.c_str(), THE_LEDGER.c_str());
}
// -----------------------------------------------------------------------
const std::string OTAPI_Wrap::Ledger_CreateResponse(const std::string SERVER_ID,
													const std::string USER_ID,
													const std::string ACCOUNT_ID,
													const std::string ORIGINAL_LEDGER)
{
	return OT_API_Ledger_CreateResponse(SERVER_ID.c_str(), USER_ID.c_str(), ACCOUNT_ID.c_str(), ORIGINAL_LEDGER.c_str());
}
// -------------------------------------------------------------------------
const std::string OTAPI_Wrap::Ledger_GetTransactionByIndex(const std::string SERVER_ID,
														   const std::string USER_ID,
														   const std::string ACCOUNT_ID,
														   const std::string THE_LEDGER,
														   int nIndex)
{
	return OT_API_Ledger_GetTransactionByIndex(SERVER_ID.c_str(), USER_ID.c_str(), ACCOUNT_ID.c_str(), THE_LEDGER.c_str(), nIndex);
}
// -------------------------------------------------------------------------

const std::string OTAPI_Wrap::Ledger_GetTransactionByID(const std::string SERVER_ID,
														const std::string USER_ID,
														const std::string ACCOUNT_ID,
														const std::string THE_LEDGER,
														const std::string TRANSACTION_NUMBER)
{
	return OT_API_Ledger_GetTransactionByID(SERVER_ID.c_str(), USER_ID.c_str(), ACCOUNT_ID.c_str(), THE_LEDGER.c_str(), TRANSACTION_NUMBER.c_str());
}
// -------------------------------------------------------------------------

const std::string OTAPI_Wrap::Ledger_GetTransactionIDByIndex(const std::string SERVER_ID,
															 const std::string USER_ID,
															 const std::string ACCOUNT_ID,
															 const std::string THE_LEDGER,
															 int nIndex)
{
	return OT_API_Ledger_GetTransactionIDByIndex(SERVER_ID.c_str(), USER_ID.c_str(), ACCOUNT_ID.c_str(), THE_LEDGER.c_str(), nIndex);
}
// --------------------------------------------------------------
const std::string OTAPI_Wrap::Ledger_AddTransaction(const std::string SERVER_ID,
													const std::string USER_ID,
													const std::string ACCOUNT_ID,
													const std::string THE_LEDGER,
													const std::string THE_TRANSACTION)
{
	return OT_API_Ledger_AddTransaction(SERVER_ID.c_str(), USER_ID.c_str(), ACCOUNT_ID.c_str(), THE_LEDGER.c_str(), THE_TRANSACTION.c_str());
}
// --------------------------------------------------------------
const std::string OTAPI_Wrap::Transaction_CreateResponse(const std::string SERVER_ID,
														 const std::string USER_ID,
														 const std::string ACCOUNT_ID,
														 const std::string RESPONSE_LEDGER, // To be sent to the server...
														 const std::string ORIGINAL_TRANSACTION, // Responding to...?
														 bool BOOL_DO_I_ACCEPT)
{
	return OT_API_Transaction_CreateResponse(SERVER_ID.c_str(), USER_ID.c_str(), ACCOUNT_ID.c_str(), 
											 RESPONSE_LEDGER.c_str(), ORIGINAL_TRANSACTION.c_str(),
											 BOOL_DO_I_ACCEPT ? OT_TRUE : OT_FALSE);
}
// -------------------------------------------------------------------------
const std::string OTAPI_Wrap::Ledger_FinalizeResponse(const std::string SERVER_ID,
													  const std::string USER_ID,
													  const std::string ACCOUNT_ID,
													  const std::string THE_LEDGER)
{
	return OT_API_Ledger_FinalizeResponse(SERVER_ID.c_str(), USER_ID.c_str(), ACCOUNT_ID.c_str(), THE_LEDGER.c_str());
}
// -------------------------------------------------------------------------

const std::string OTAPI_Wrap::Transaction_GetType(const std::string SERVER_ID,
												  const std::string USER_ID,
												  const std::string ACCOUNT_ID,
												  const std::string THE_TRANSACTION)
{
	return OT_API_Transaction_GetType(SERVER_ID.c_str(), USER_ID.c_str(), ACCOUNT_ID.c_str(), THE_TRANSACTION.c_str());
}
// --------------------------------------------------------------------
const std::string OTAPI_Wrap::Transaction_GetVoucher(const std::string SERVER_ID,
													 const std::string USER_ID,
													 const std::string ACCOUNT_ID,
													 const std::string THE_TRANSACTION)
{
	return OT_API_Transaction_GetVoucher(SERVER_ID.c_str(), USER_ID.c_str(), ACCOUNT_ID.c_str(), THE_TRANSACTION.c_str());
}
// --------------------------------------------------
bool OTAPI_Wrap::Transaction_GetSuccess(const std::string SERVER_ID,
										const std::string USER_ID,
										const std::string ACCOUNT_ID,
										const std::string THE_TRANSACTION)
{
	return (OT_API_Transaction_GetSuccess(SERVER_ID.c_str(), USER_ID.c_str(), ACCOUNT_ID.c_str(), THE_TRANSACTION.c_str()) == OT_TRUE) ? true : false;
}

// --------------------------------------------------
bool OTAPI_Wrap::Transaction_GetBlnceAgrmntSuccess(const std::string SERVER_ID,
												   const std::string USER_ID,
												   const std::string ACCOUNT_ID,
												   const std::string THE_TRANSACTION)
{
	return (OT_API_Transaction_GetBalanceAgreementSuccess(SERVER_ID.c_str(), USER_ID.c_str(), ACCOUNT_ID.c_str(), THE_TRANSACTION.c_str()) == OT_TRUE) ? true : false;
}

// --------------------------------------------------
const std::string OTAPI_Wrap::Transaction_GetDateSigned(const std::string SERVER_ID,
														const std::string USER_ID,
														const std::string ACCOUNT_ID,
														const std::string THE_TRANSACTION)
{
	return OT_API_Transaction_GetDateSigned(SERVER_ID.c_str(), USER_ID.c_str(), ACCOUNT_ID.c_str(), THE_TRANSACTION.c_str());
}

// --------------------------------------------------

const std::string OTAPI_Wrap::Transaction_GetAmount(const std::string SERVER_ID,
													const std::string USER_ID,
													const std::string ACCOUNT_ID,
													const std::string THE_TRANSACTION)
{
	return OT_API_Transaction_GetAmount(SERVER_ID.c_str(), USER_ID.c_str(), ACCOUNT_ID.c_str(), THE_TRANSACTION.c_str());
}
// --------------------------------------------------
const std::string OTAPI_Wrap::Pending_GetNote(const std::string SERVER_ID,
											  const std::string USER_ID,
											  const std::string ACCOUNT_ID,
											  const std::string THE_TRANSACTION)
{
	return OT_API_Pending_GetNote(SERVER_ID.c_str(), USER_ID.c_str(), ACCOUNT_ID.c_str(), THE_TRANSACTION.c_str());
}
// --------------------------------------------------
const std::string OTAPI_Wrap::Transaction_GetSenderUserID(const std::string SERVER_ID,
														  const std::string USER_ID,
														  const std::string ACCOUNT_ID,
														  const std::string THE_TRANSACTION)
{
	return OT_API_Transaction_GetSenderUserID(SERVER_ID.c_str(), USER_ID.c_str(), ACCOUNT_ID.c_str(), THE_TRANSACTION.c_str());
}
// --------------------------------------------------

const std::string OTAPI_Wrap::Transaction_GetSenderAcctID(const std::string SERVER_ID,
														  const std::string USER_ID,
														  const std::string ACCOUNT_ID,
														  const std::string THE_TRANSACTION)
{
	return OT_API_Transaction_GetSenderAcctID(SERVER_ID.c_str(), USER_ID.c_str(), ACCOUNT_ID.c_str(), THE_TRANSACTION.c_str());
}
// --------------------------------------------------

const std::string OTAPI_Wrap::Transaction_GetRecipientUserID(const std::string SERVER_ID,
															 const std::string USER_ID,
															 const std::string ACCOUNT_ID,
															 const std::string THE_TRANSACTION)
{
	return OT_API_Transaction_GetRecipientUserID(SERVER_ID.c_str(), USER_ID.c_str(), ACCOUNT_ID.c_str(), THE_TRANSACTION.c_str());
}
// --------------------------------------------------

const std::string OTAPI_Wrap::Transaction_GetRecipientAcctID(const std::string SERVER_ID,
															 const std::string USER_ID,
															 const std::string ACCOUNT_ID,
															 const std::string THE_TRANSACTION)
{
	return OT_API_Transaction_GetRecipientAcctID(SERVER_ID.c_str(), USER_ID.c_str(), ACCOUNT_ID.c_str(), THE_TRANSACTION.c_str());
}
// --------------------------------------------------

const std::string OTAPI_Wrap::Transaction_GetDisplayReferenceToNum(const std::string SERVER_ID,
																   const std::string USER_ID,
																   const std::string ACCOUNT_ID,
																   const std::string THE_TRANSACTION)
{
	return OT_API_Transaction_GetDisplayReferenceToNum(SERVER_ID.c_str(), USER_ID.c_str(), ACCOUNT_ID.c_str(), THE_TRANSACTION.c_str());
}
// ---------------------------------------------------------

const std::string OTAPI_Wrap::CreatePurse(const std::string SERVER_ID,
										  const std::string ASSET_TYPE_ID,
										  const std::string USER_ID)
{
	return OT_API_CreatePurse(SERVER_ID.c_str(), ASSET_TYPE_ID.c_str(), USER_ID.c_str());
}

// --------------------------------------------------------------------
bool OTAPI_Wrap::SavePurse(const std::string SERVER_ID,
						   const std::string ASSET_TYPE_ID,
						   const std::string USER_ID,
						   const std::string THE_PURSE)
{
	return (OT_API_SavePurse(SERVER_ID.c_str(), ASSET_TYPE_ID.c_str(), USER_ID.c_str(), THE_PURSE.c_str()) == OT_TRUE) ? true : false;
}

// --------------------------------------------------------------------
const std::string OTAPI_Wrap::Purse_GetTotalValue(const std::string SERVER_ID,
												  const std::string ASSET_TYPE_ID,
												  const std::string THE_PURSE)
{
	return OT_API_Purse_GetTotalValue(SERVER_ID.c_str(), ASSET_TYPE_ID.c_str(), THE_PURSE.c_str());
}


// --------------------------------------------------------------------
int OTAPI_Wrap::Purse_Count(const std::string SERVER_ID,
							const std::string ASSET_TYPE_ID,
							const std::string THE_PURSE)
{
	return OT_API_Purse_Count(SERVER_ID.c_str(), ASSET_TYPE_ID.c_str(), THE_PURSE.c_str());
}

// --------------------------------------------------------------------
const std::string OTAPI_Wrap::Purse_Peek(const std::string SERVER_ID,
										 const std::string ASSET_TYPE_ID,
										 const std::string USER_ID,
										 const std::string THE_PURSE)
{
	return OT_API_Purse_Peek(SERVER_ID.c_str(), ASSET_TYPE_ID.c_str(), USER_ID.c_str(), THE_PURSE.c_str());
}

// --------------------------------------------------------------------
const std::string OTAPI_Wrap::Purse_Pop(const std::string SERVER_ID,
										const std::string ASSET_TYPE_ID,
										const std::string USER_ID,
										const std::string THE_PURSE)
{
	return OT_API_Purse_Pop(SERVER_ID.c_str(), ASSET_TYPE_ID.c_str(), USER_ID.c_str(), THE_PURSE.c_str());
}

// --------------------------------------------------------------------
const std::string OTAPI_Wrap::Purse_Push(const std::string SERVER_ID,
										 const std::string ASSET_TYPE_ID,
										 const std::string USER_ID,
										 const std::string THE_PURSE,
										 const std::string THE_TOKEN)
{
	return OT_API_Purse_Push(SERVER_ID.c_str(), ASSET_TYPE_ID.c_str(), USER_ID.c_str(), THE_PURSE.c_str(), THE_TOKEN.c_str());
}

// --------------------------------------------------------------------
bool OTAPI_Wrap::Wallet_ImportPurse(const std::string SERVER_ID,
									const std::string ASSET_TYPE_ID,
									const std::string USER_ID, // you pass in the purse you're trying to import
									const std::string THE_PURSE)
{
	return (OT_API_Wallet_ImportPurse(SERVER_ID.c_str(), ASSET_TYPE_ID.c_str(), USER_ID.c_str(), THE_PURSE.c_str()) == OT_TRUE) ? true : false;
}

// --------------------------------------------------------------------
void OTAPI_Wrap::exchangePurse(const std::string SERVER_ID,
							   const std::string ASSET_TYPE_ID,
							   const std::string USER_ID,
							   const std::string THE_PURSE)
{
	OT_API_exchangePurse(SERVER_ID.c_str(), ASSET_TYPE_ID.c_str(), USER_ID.c_str(), THE_PURSE.c_str());
}

// --------------------------------------------------------------------
const std::string OTAPI_Wrap::Token_ChangeOwner(const std::string SERVER_ID,
												const std::string ASSET_TYPE_ID,
												const std::string THE_TOKEN,
												const std::string OLD_OWNER_NYM_ID,
												const std::string NEW_OWNER_NYM_ID)
{
	return OT_API_Token_ChangeOwner(SERVER_ID.c_str(), ASSET_TYPE_ID.c_str(), THE_TOKEN.c_str(), OLD_OWNER_NYM_ID.c_str(), NEW_OWNER_NYM_ID.c_str());
}

// --------------------------------------------------------------------
const std::string OTAPI_Wrap::Token_GetID(const std::string SERVER_ID,
										  const std::string ASSET_TYPE_ID,
										  const std::string THE_TOKEN)
{
	return OT_API_Token_GetID(SERVER_ID.c_str(), ASSET_TYPE_ID.c_str(), THE_TOKEN.c_str());
}

// --------------------------------------------------------------------
const std::string OTAPI_Wrap::Token_GetDenomination(const std::string SERVER_ID,
													const std::string ASSET_TYPE_ID,
													const std::string THE_TOKEN)
{
	return OT_API_Token_GetDenomination(SERVER_ID.c_str(), ASSET_TYPE_ID.c_str(), THE_TOKEN.c_str());
}

// --------------------------------------------------------------------
int OTAPI_Wrap::Token_GetSeries(const std::string SERVER_ID,
								const std::string ASSET_TYPE_ID,
								const std::string THE_TOKEN)
{
	return OT_API_Token_GetSeries(SERVER_ID.c_str(), ASSET_TYPE_ID.c_str(), THE_TOKEN.c_str());
}

// --------------------------------------------------------------------
const std::string OTAPI_Wrap::Token_GetValidFrom(const std::string SERVER_ID,
												 const std::string ASSET_TYPE_ID,
												 const std::string THE_TOKEN)
{
	return OT_API_Token_GetValidFrom(SERVER_ID.c_str(), ASSET_TYPE_ID.c_str(), THE_TOKEN.c_str());
}

// --------------------------------------------------------------------
const std::string OTAPI_Wrap::Token_GetValidTo(const std::string SERVER_ID,
											   const std::string ASSET_TYPE_ID,
											   const std::string THE_TOKEN)
{
	return OT_API_Token_GetValidTo(SERVER_ID.c_str(), ASSET_TYPE_ID.c_str(), THE_TOKEN.c_str());
}

// --------------------------------------------------------------------
const std::string OTAPI_Wrap::Token_GetAssetID(const std::string THE_TOKEN)
{
	return OT_API_Token_GetAssetID(THE_TOKEN.c_str());
}

// --------------------------------------------------------------------
const std::string OTAPI_Wrap::Token_GetServerID(const std::string THE_TOKEN)
{
	return OT_API_Token_GetServerID(THE_TOKEN.c_str());
}


// ********************************************************************************



void OTAPI_Wrap::checkServerID(const std::string SERVER_ID, const std::string USER_ID)
{
	OT_API_checkServerID(SERVER_ID.c_str(), USER_ID.c_str());
}

// --------------------------------------------------------------------
void OTAPI_Wrap::createUserAccount(const std::string SERVER_ID,
								   const std::string USER_ID)
{
	OT_API_createUserAccount(SERVER_ID.c_str(), USER_ID.c_str());
}

// --------------------------------------------------------------------
void OTAPI_Wrap::deleteUserAccount(const std::string SERVER_ID,
								   const std::string USER_ID)
{
	OT_API_deleteUserAccount(SERVER_ID.c_str(), USER_ID.c_str());
}

// --------------------------------------------------------------------
void OTAPI_Wrap::deleteAssetAccount(const std::string SERVER_ID,
									const std::string USER_ID,
									const std::string ACCOUNT_ID)
{
	OT_API_deleteAssetAccount(SERVER_ID.c_str(), USER_ID.c_str(), ACCOUNT_ID.c_str());
}

// --------------------------------------------------------------------
void OTAPI_Wrap::checkUser(const std::string SERVER_ID,
						   const std::string USER_ID,
						   const std::string USER_ID_CHECK)
{
	OT_API_checkUser(SERVER_ID.c_str(), USER_ID.c_str(), USER_ID_CHECK.c_str());
}
// --------------------------------------------------------------------
void OTAPI_Wrap::usageCredits(const std::string SERVER_ID,
							  const std::string USER_ID,
							  const std::string USER_ID_CHECK,
							  const std::string ADJUSTMENT)
{
	OT_API_usageCredits(SERVER_ID.c_str(), USER_ID.c_str(), USER_ID_CHECK.c_str(), ADJUSTMENT.c_str());
}
// --------------------------------------------------------------------
void OTAPI_Wrap::sendUserMessage(const std::string SERVER_ID,
								 const std::string USER_ID,
								 const std::string USER_ID_RECIPIENT,
								 const std::string RECIPIENT_PUBKEY,
								 const std::string THE_MESSAGE)
{
	OT_API_sendUserMessage(SERVER_ID.c_str(), USER_ID.c_str(), USER_ID_RECIPIENT.c_str(), RECIPIENT_PUBKEY.c_str(), THE_MESSAGE.c_str());
}
// --------------------------------------------------------------------
void OTAPI_Wrap::getRequest(const std::string SERVER_ID,
							const std::string USER_ID)
{
	OT_API_getRequest(SERVER_ID.c_str(), USER_ID.c_str());
}

void OTAPI_Wrap::getTransactionNumber(const std::string SERVER_ID,
									  const std::string USER_ID)
{
	OT_API_getTransactionNumber(SERVER_ID.c_str(), USER_ID.c_str());
}
// --------------------------------------------------------------------
void OTAPI_Wrap::issueAssetType(const std::string	SERVER_ID,
								const std::string	USER_ID,
								const std::string	THE_CONTRACT)
{
	OT_API_issueAssetType(SERVER_ID.c_str(), USER_ID.c_str(), THE_CONTRACT.c_str());
}
// --------------------------------------------------------------------
void OTAPI_Wrap::getContract(const std::string SERVER_ID,
							 const std::string USER_ID,
							 const std::string ASSET_ID)
{
	OT_API_getContract(SERVER_ID.c_str(), USER_ID.c_str(), ASSET_ID.c_str());
}
// --------------------------------------------------------------------------
void OTAPI_Wrap::getMint(const std::string SERVER_ID,
						 const std::string USER_ID,
						 const std::string ASSET_ID)
{
	OT_API_getMint(SERVER_ID.c_str(), USER_ID.c_str(), ASSET_ID.c_str());
}
// ---------------------------------------------------------------------------
void OTAPI_Wrap::createAssetAccount(const std::string SERVER_ID,
									const std::string USER_ID,
									const std::string ASSET_ID)
{
	OT_API_createAssetAccount(SERVER_ID.c_str(), USER_ID.c_str(), ASSET_ID.c_str());
}
// --------------------------------------------------------------------------
void OTAPI_Wrap::getAccount(const std::string SERVER_ID,
							const std::string USER_ID,
							const std::string ACCT_ID)
{
	OT_API_getAccount(SERVER_ID.c_str(), USER_ID.c_str(), ACCT_ID.c_str());
}
// --------------------------------------------------

const std::string OTAPI_Wrap::GenerateBasketCreation(const std::string USER_ID,
													 const std::string MINIMUM_TRANSFER)
{
	return OT_API_GenerateBasketCreation(USER_ID.c_str(), MINIMUM_TRANSFER.c_str());
}

// --------------------------------------------------------------------
const std::string OTAPI_Wrap::AddBasketCreationItem(const std::string USER_ID, // for signature.
													const std::string THE_BASKET, // created in above call.
													const std::string ASSET_TYPE_ID, // Adding an asset type to the new basket.
													const std::string MINIMUM_TRANSFER)
{
	return OT_API_AddBasketCreationItem(USER_ID.c_str(), THE_BASKET.c_str(), ASSET_TYPE_ID.c_str(), MINIMUM_TRANSFER.c_str());
}

// --------------------------------------------------------------------
void OTAPI_Wrap::issueBasket(const std::string SERVER_ID,
							 const std::string USER_ID,
							 const std::string THE_BASKET)
{
	OT_API_issueBasket(SERVER_ID.c_str(), USER_ID.c_str(), THE_BASKET.c_str());
}

// --------------------------------------------------------------------
const std::string OTAPI_Wrap::GenerateBasketExchange(const std::string SERVER_ID,
													 const std::string USER_ID,
													 const std::string BASKET_ASSET_TYPE_ID,
													 const std::string BASKET_ASSET_ACCT_ID,
													 // -------------------------------------
													 const int TRANSFER_MULTIPLE)
{
	return OT_API_GenerateBasketExchange(SERVER_ID.c_str(), USER_ID.c_str(), 
										 BASKET_ASSET_TYPE_ID.c_str(), BASKET_ASSET_ACCT_ID.c_str(), 
										 TRANSFER_MULTIPLE);
}

// --------------------------------------------------------------------
const std::string OTAPI_Wrap::AddBasketExchangeItem(const std::string SERVER_ID,
													const std::string USER_ID,
													const std::string THE_BASKET, 
													const std::string ASSET_TYPE_ID,
													const std::string ASSET_ACCT_ID)
{
	return OT_API_AddBasketExchangeItem(SERVER_ID.c_str(), USER_ID.c_str(), THE_BASKET.c_str(), ASSET_TYPE_ID.c_str(), ASSET_ACCT_ID.c_str());
}
// --------------------------------------------------------------------------
void OTAPI_Wrap::exchangeBasket(const std::string SERVER_ID,
								const std::string USER_ID,
								const std::string BASKET_ASSET_ID,
								const std::string THE_BASKET,
								const bool BOOL_EXCHANGE_IN_OR_OUT)
{
	OT_API_exchangeBasket(SERVER_ID.c_str(), USER_ID.c_str(), BASKET_ASSET_ID.c_str(), THE_BASKET.c_str(),
						  BOOL_EXCHANGE_IN_OR_OUT ? OT_TRUE : OT_FALSE);
}

// --------------------------------------------------------------------
void OTAPI_Wrap::notarizeWithdrawal(const std::string SERVER_ID,
									const std::string USER_ID,
									const std::string ACCT_ID,
									const std::string AMOUNT)
{
	OT_API_notarizeWithdrawal(SERVER_ID.c_str(), USER_ID.c_str(), ACCT_ID.c_str(), AMOUNT.c_str());
}

// --------------------------------------------------------------------
void OTAPI_Wrap::notarizeDeposit(const std::string SERVER_ID,
								 const std::string USER_ID,
								 const std::string ACCT_ID,
								 const std::string THE_PURSE)
{
	OT_API_notarizeDeposit(SERVER_ID.c_str(), USER_ID.c_str(), ACCT_ID.c_str(), THE_PURSE.c_str());
}

// --------------------------------------------------------------------
void OTAPI_Wrap::notarizeTransfer(const std::string SERVER_ID,
								  const std::string USER_ID,
								  const std::string ACCT_FROM,
								  const std::string ACCT_TO,
								  const std::string AMOUNT,
								  const std::string NOTE)
{
	OT_API_notarizeTransfer(SERVER_ID.c_str(), USER_ID.c_str(), ACCT_FROM.c_str(), ACCT_TO.c_str(), AMOUNT.c_str(), NOTE.c_str());
}

// --------------------------------------------------------------------
void OTAPI_Wrap::getInbox(const std::string SERVER_ID,
						  const std::string USER_ID,
						  const std::string ACCT_ID)
{
	OT_API_getInbox(SERVER_ID.c_str(), USER_ID.c_str(), ACCT_ID.c_str());
}

// --------------------------------------------------------------------
void OTAPI_Wrap::getOutbox(const std::string SERVER_ID,
						   const std::string USER_ID,
						   const std::string ACCT_ID)
{
	OT_API_getOutbox(SERVER_ID.c_str(), USER_ID.c_str(), ACCT_ID.c_str());
}


// --------------------------------------------------------------------

void OTAPI_Wrap::getNymbox(const std::string SERVER_ID,
						   const std::string USER_ID)
{
	OT_API_getNymbox(SERVER_ID.c_str(), USER_ID.c_str());
}

// --------------------------------------------------------------------
const std::string OTAPI_Wrap::LoadNymbox(const std::string SERVER_ID,
										 const std::string USER_ID)
{
	return OT_API_LoadNymbox(SERVER_ID.c_str(), USER_ID.c_str());
}

// --------------------------------------------------------------------
const std::string OTAPI_Wrap::LoadNymboxNoVerify(const std::string SERVER_ID,
												 const std::string USER_ID)
{
	return OT_API_LoadNymboxNoVerify(SERVER_ID.c_str(), USER_ID.c_str());
}

// --------------------------------------------------------------------
void OTAPI_Wrap::getBoxReceipt(const std::string	SERVER_ID,
							   const std::string	USER_ID,
							   const std::string	ACCT_ID,	// If for Nymbox (vs inbox/outbox) then pass USER_ID in this field also.
							   const int			nBoxType,	// 0/nymbox, 1/inbox, 2/outbox
							   const std::string	TRANSACTION_NUMBER)
{
	OT_API_getBoxReceipt(SERVER_ID.c_str(), USER_ID.c_str(), ACCT_ID.c_str(), nBoxType, TRANSACTION_NUMBER.c_str());
}

// --------------------------------------------------------------------------
bool OTAPI_Wrap::DoesBoxReceiptExist(const std::string	SERVER_ID,
									 const std::string	USER_ID,
									 const std::string	ACCT_ID,	// If for Nymbox (vs inbox/outbox) then pass USER_ID in this field also.
									 const int			nBoxType,	// 0/nymbox, 1/inbox, 2/outbox
									 const std::string	TRANSACTION_NUMBER)
{
	return (OT_TRUE == 
				OT_API_DoesBoxReceiptExist(SERVER_ID.c_str(), USER_ID.c_str(), ACCT_ID.c_str(), nBoxType, TRANSACTION_NUMBER.c_str())) 
			? 
		true : false;
}

// --------------------------------------------------------------------------
void OTAPI_Wrap::processInbox(const std::string SERVER_ID,
							  const std::string USER_ID,
							  const std::string ACCT_ID,
							  const std::string ACCT_LEDGER)
{
	OT_API_processInbox(SERVER_ID.c_str(), USER_ID.c_str(), ACCT_ID.c_str(), ACCT_LEDGER.c_str());
}
// --------------------------------------------------------------------

int OTAPI_Wrap::processNymbox(const std::string SERVER_ID,
							  const std::string USER_ID)
{
	return OT_API_processNymbox(SERVER_ID.c_str(), USER_ID.c_str());
}
// --------------------------------------------------------------------

void OTAPI_Wrap::withdrawVoucher(const std::string SERVER_ID,
								 const std::string USER_ID,
								 const std::string ACCT_ID,
								 const std::string RECIPIENT_USER_ID,
								 const std::string CHEQUE_MEMO,
								 const std::string AMOUNT)
{
	OT_API_withdrawVoucher(SERVER_ID.c_str(), USER_ID.c_str(), ACCT_ID.c_str(), RECIPIENT_USER_ID.c_str(), CHEQUE_MEMO.c_str(), AMOUNT.c_str());
}
// --------------------------------------------------------------------------

void OTAPI_Wrap::depositCheque(const std::string SERVER_ID,
							   const std::string USER_ID,
							   const std::string ACCT_ID,
							   const std::string THE_CHEQUE)
{
	OT_API_depositCheque(SERVER_ID.c_str(), USER_ID.c_str(), ACCT_ID.c_str(), THE_CHEQUE.c_str());
}
// --------------------------------------------------
void OTAPI_Wrap::depositPaymentPlan(const std::string SERVER_ID,
									const std::string USER_ID,
									const std::string THE_PAYMENT_PLAN)
{
	OT_API_depositPaymentPlan(SERVER_ID.c_str(), USER_ID.c_str(), THE_PAYMENT_PLAN.c_str());
}
// --------------------------------------------------
void OTAPI_Wrap::issueMarketOffer(const std::string SERVER_ID,
								  const std::string USER_ID,
								  // -------------------------------------------
								  const std::string ASSET_ACCT_ID, // Perhaps this is the wheat market.
								  // -------------------------------------------
								  const std::string CURRENCY_ACCT_ID, // Perhaps I'm buying the wheat with rubles.
								  // -------------------------------------------
								  const std::string MARKET_SCALE,			// Defaults to minimum of 1. Market granularity.
								  const std::string MINIMUM_INCREMENT,		// This will be multiplied by the Scale. Min 1.
								  const std::string TOTAL_ASSETS_ON_OFFER,	// Total assets available for sale or purchase. Will be multiplied by minimum increment.
								  const std::string PRICE_LIMIT,			// Per Minimum Increment...
										bool		bBuyingOrSelling)
{
	
	const char * pType1 = OT_API_GetAccountWallet_AssetTypeID(ASSET_ACCT_ID.c_str());		// Returns asset type ID of the asset account.
	const std::string str_Type1((NULL == pType1) ? "" : pType1);
	
	const char * pType2 = OT_API_GetAccountWallet_AssetTypeID(CURRENCY_ACCT_ID.c_str());	// Returns asset type ID of the currency account.
	const std::string str_Type2((NULL == pType2) ? "" : pType2);
	
	if ((str_Type1.size() < 1) || (str_Type2.size() < 1))
	{
		OTLog::Error("OTAPI_Wrap::issueMarketOffer: Unable to find asset type ID or currency type ID, based on account IDs passed in.\n");
		return;
	}
	else
	{
		OTLog::vOutput(1, "OTAPI_Wrap::issueMarketOffer: Using asset type: %s for account: %s.\n",
					   str_Type1.c_str(), ASSET_ACCT_ID.c_str());
		OTLog::vOutput(1, "OTAPI_Wrap::issueMarketOffer: Using asset type: %s for account: %s.\n",
					   str_Type2.c_str(), CURRENCY_ACCT_ID.c_str());
	}

	// Todo: perhaps have these sorts of "server message" functions return a bool, so I know whether it even sent
	// the message. Otherwise all my error-correction crap where I pop the server reply, is a total waste of time,
	// since the message was never even sent.
	
	OT_API_issueMarketOffer(SERVER_ID.c_str(), USER_ID.c_str(),
							str_Type1.c_str(), ASSET_ACCT_ID.c_str(),
							str_Type2.c_str(), CURRENCY_ACCT_ID.c_str(),
							MARKET_SCALE.c_str(), MINIMUM_INCREMENT.c_str(),
							TOTAL_ASSETS_ON_OFFER.c_str(), PRICE_LIMIT.c_str(),
							bBuyingOrSelling ? OT_TRUE : OT_FALSE);	
}
// --------------------------------------------------

void OTAPI_Wrap::getMarketList(const std::string SERVER_ID, const std::string USER_ID)
{
	OT_API_getMarketList(SERVER_ID.c_str(), USER_ID.c_str());
}

// --------------------------------------------------------------------
void OTAPI_Wrap::getMarketOffers(const std::string SERVER_ID, const std::string USER_ID, 
								 const std::string MARKET_ID, const std::string MAX_DEPTH)
{
	OT_API_getMarketOffers(SERVER_ID.c_str(), USER_ID.c_str(), MARKET_ID.c_str(), MAX_DEPTH.c_str());
}

// --------------------------------------------------------------------
void OTAPI_Wrap::getMarketRecentTrades(const std::string SERVER_ID, const std::string USER_ID, 
									   const std::string MARKET_ID)
{
	OT_API_getMarketRecentTrades(SERVER_ID.c_str(), USER_ID.c_str(), MARKET_ID.c_str());
}

// --------------------------------------------------------------------
void OTAPI_Wrap::getNym_MarketOffers(const std::string SERVER_ID, const std::string USER_ID)
{
	OT_API_getNym_MarketOffers(SERVER_ID.c_str(), USER_ID.c_str());
}

// --------------------------------------------------------------------
void OTAPI_Wrap::cancelMarketOffer(const std::string SERVER_ID, 
								   const std::string USER_ID, 
								   const std::string ASSET_ACCT_ID, 
								   const std::string TRANSACTION_NUMBER)
{
	OT_API_cancelMarketOffer(SERVER_ID.c_str(), USER_ID.c_str(), ASSET_ACCT_ID.c_str(), TRANSACTION_NUMBER.c_str());
}

// --------------------------------------------------------------------
void OTAPI_Wrap::cancelPaymentPlan(const std::string SERVER_ID, 
								   const std::string USER_ID, 
								   const std::string FROM_ACCT_ID, 
								   const std::string TRANSACTION_NUMBER)
{
	OT_API_cancelPaymentPlan(SERVER_ID.c_str(), USER_ID.c_str(), FROM_ACCT_ID.c_str(), TRANSACTION_NUMBER.c_str());
}
// -----------------------------------------------------------
const std::string OTAPI_Wrap::PopMessageBuffer()
{
	return OT_API_PopMessageBuffer();
}

// --------------------------------------------------------------------
void OTAPI_Wrap::FlushMessageBuffer()
{
	OT_API_FlushMessageBuffer();
}
// -----------------------------------------------------------

void OTAPI_Wrap::Sleep(const std::string MILLISECONDS)
{
	OT_API_Sleep(MILLISECONDS.c_str());
}

// -----------------------------------------------------------

bool OTAPI_Wrap::ResyncNymWithServer(const std::string SERVER_ID,
									 const std::string USER_ID,
									 const std::string THE_MESSAGE)
{
	return (OT_TRUE == 
				OT_API_ResyncNymWithServer(SERVER_ID.c_str(), USER_ID.c_str(), THE_MESSAGE.c_str())) ?
				true : false;
}

// -----------------------------------------------------------

void OTAPI_Wrap::queryAssetTypes(const std::string SERVER_ID,
								 const std::string USER_ID,
								 const std::string ENCODED_MAP)
{
	OT_API_queryAssetTypes(SERVER_ID.c_str(), USER_ID.c_str(), ENCODED_MAP.c_str());	
}

// -----------------------------------------------------------

const std::string OTAPI_Wrap::Message_GetPayload(const std::string THE_MESSAGE)
{
	return OT_API_Message_GetPayload(THE_MESSAGE.c_str());
}

// --------------------------------------------------------------------
const std::string OTAPI_Wrap::Message_GetCommand(const std::string THE_MESSAGE)
{
	return OT_API_Message_GetCommand(THE_MESSAGE.c_str());
}

// --------------------------------------------------------------------
bool OTAPI_Wrap::Message_GetSuccess(const std::string THE_MESSAGE)
{
	return (OT_TRUE == OT_API_Message_GetSuccess(THE_MESSAGE.c_str())) ? true : false;
}

// --------------------------------------------------------------------
int OTAPI_Wrap::Message_GetDepth(const std::string THE_MESSAGE)
{
	return OT_API_Message_GetDepth(THE_MESSAGE.c_str());
}

// --------------------------------------------------------------------
const std::string OTAPI_Wrap::Message_GetUsageCredits(const std::string THE_MESSAGE)
{
	return OT_API_Message_GetUsageCredits(THE_MESSAGE.c_str());
}

// --------------------------------------------------------------------
bool OTAPI_Wrap::Msg_GetTransactionSuccess(const std::string SERVER_ID,
										   const std::string USER_ID,
										   const std::string ACCOUNT_ID,
										   const std::string THE_MESSAGE)
{
	return (OT_TRUE == OT_API_Message_GetTransactionSuccess(SERVER_ID.c_str(), USER_ID.c_str(), ACCOUNT_ID.c_str(), THE_MESSAGE.c_str())) ? true : false;
}

// --------------------------------------------------------------------
// Name abbreviated due to problems with length in scripting environment.
//
bool OTAPI_Wrap::Msg_GetBlnceAgrmntSuccess(const std::string SERVER_ID,
										   const std::string USER_ID,
										   const std::string ACCOUNT_ID,
										   const std::string THE_MESSAGE)
{
	return (OT_TRUE == OT_API_Message_GetBalanceAgreementSuccess(SERVER_ID.c_str(), USER_ID.c_str(), ACCOUNT_ID.c_str(), THE_MESSAGE.c_str())) ? true : false;
}

// --------------------------------------------------------------------
const std::string OTAPI_Wrap::Message_GetLedger(const std::string THE_MESSAGE)
{
	return OT_API_Message_GetLedger(THE_MESSAGE.c_str());
}

// --------------------------------------------------------------------
const std::string OTAPI_Wrap::Message_GetNewAssetTypeID(const std::string THE_MESSAGE)
{
	return OT_API_Message_GetNewAssetTypeID(THE_MESSAGE.c_str());
}

// --------------------------------------------------------------------
const std::string OTAPI_Wrap::Message_GetNewIssuerAcctID(const std::string THE_MESSAGE)
{
	return OT_API_Message_GetNewIssuerAcctID(THE_MESSAGE.c_str());
}

// --------------------------------------------------------------------
const std::string OTAPI_Wrap::Message_GetNewAcctID(const std::string THE_MESSAGE)
{
	return OT_API_Message_GetNewAcctID(THE_MESSAGE.c_str());
}


// --------------------------------------------------------------------


OTAPI_Wrap::OTAPI_Wrap()
{
	
}

OTAPI_Wrap::~OTAPI_Wrap()
{
	
}






















