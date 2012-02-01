/************************************************************************************
 
 OTAPI_Wrapper.h   --	A C++ wrapper class (named OTAPI_Wrap) for the
 C functions in OTAPI.h
 
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


#ifndef __OT_API_WRAP_H__
#define __OT_API_WRAP_H__

#include <string>


#include "OTAPI_funcdef.h"
//#include "OTAPI.h"




class OTAPI_Wrap 
{
public:

	static void Output(const int nLogLevel, const std::string STR_OUTPUT);
	
	static std::string GetTime();
	
	// Encode, decode, encrypt, decrypt, signcontract, addsignature, and verify.
	//
	static std::string Encode(std::string str_Plaintext,	bool bLineBreaks);
	static std::string Decode(std::string str_Encoded,		bool bLineBreaks);
	static std::string Encrypt(std::string RECIPIENT_NYM_ID, std::string str_Plaintext);
	static std::string Decrypt(std::string RECIPIENT_NYM_ID, std::string str_Ciphertext);
	static std::string SignContract(std::string SIGNER_NYM_ID, std::string THE_CONTRACT);
	static std::string AddSignature(std::string SIGNER_NYM_ID, std::string THE_CONTRACT);
	static bool VerifySignature(std::string SIGNER_NYM_ID, std::string THE_CONTRACT);
	
	/*
	 static const std::string Create_SmartContract(const std::string SERVER_ID,
		const std::string SIGNER_NYM_ID,	// Use any Nym you wish here. (The signing at this point is only to cause a save.)
		// ----------------------------------------
		const std::string VALID_FROM,	// Default (0 or NULL) == NOW
		const std::string VALID_TO);
	 */
	static const std::string Create_SmartContract(const std::string SERVER_ID,
												  const std::string SIGNER_NYM_ID,	// Use any Nym you wish here. (The signing at this point is only to cause a save.)
												  // ----------------------------------------
												  const std::string VALID_FROM,	// Default (0 or NULL) == NOW
												  const std::string VALID_TO);	// Default (0 or NULL) == never expires.
	// -------------------------
	
	static const std::string SmartContract_AddBylaw(const std::string THE_CONTRACT,	// The contract, about to have the bylaw added to it.
													const std::string SIGNER_NYM_ID,	// Use any Nym you wish here. (The signing at this point is only to cause a save.)
													// ----------------------------------------
													const std::string BYLAW_NAME);	// The Bylaw's NAME as referenced in the smart contract. (And the scripts...)
	
	// returns: the updated smart contract (or NULL)
	static const std::string SmartContract_AddClause(const std::string THE_CONTRACT,	// The contract, about to have the clause added to it.
													 const std::string SIGNER_NYM_ID,	// Use any Nym you wish here. (The signing at this point is only to cause a save.)
													 // ----------------------------------------
													 const std::string BYLAW_NAME,	// Should already be on the contract. (This way we can find it.)
													 // ----------------------------------------
													 const std::string CLAUSE_NAME,	// The Clause's name as referenced in the smart contract. (And the scripts...)
													 const std::string SOURCE_CODE);	// The actual source code for the clause.
	// returns: the updated smart contract (or NULL)
	static const std::string SmartContract_AddVariable(const std::string THE_CONTRACT,	// The contract, about to have the variabnle added to it.
													   const std::string SIGNER_NYM_ID,	// Use any Nym you wish here. (The signing at this point is only to cause a save.)
													   // ----------------------------------------
													   const std::string BYLAW_NAME,	// Should already be on the contract. (This way we can find it.)
													   // ----------------------------------------
													   const std::string VAR_NAME,	// The Variable's name as referenced in the smart contract. (And the scripts...)
													   const std::string VAR_ACCESS,	// "constant", "persistent", or "important".
													   const std::string VAR_TYPE,	// "string", "long", or "bool"
													   const std::string VAR_VALUE);	// Contains a string. If type is long, atol() will be used to convert value to a long. If type is bool, the strings "true" or "false" are expected here in order to convert to a bool.
	
	// returns: the updated smart contract (or NULL)
	static const std::string SmartContract_AddCallback(const std::string THE_CONTRACT,	// The contract, about to have the callback added to it.
													   const std::string SIGNER_NYM_ID,	// Use any Nym you wish here. (The signing at this point is only to cause a save.)
													   // ----------------------------------------
													   const std::string BYLAW_NAME,	// Should already be on the contract. (This way we can find it.)
													   // ----------------------------------------
													   const std::string CALLBACK_NAME,	// The Callback's name as referenced in the smart contract. (And the scripts...)
													   const std::string CLAUSE_NAME);	// The actual clause that will be triggered by the callback. (Must exist.)
	
	// returns: the updated smart contract (or NULL)
	static const std::string SmartContract_AddHook(const std::string THE_CONTRACT,	// The contract, about to have the hook added to it.
												   const std::string SIGNER_NYM_ID,	// Use any Nym you wish here. (The signing at this point is only to cause a save.)
												   // ----------------------------------------
												   const std::string BYLAW_NAME,	// Should already be on the contract. (This way we can find it.)
												   // ----------------------------------------
												   const std::string HOOK_NAME,		// The Hook's name as referenced in the smart contract. (And the scripts...)
												   const std::string CLAUSE_NAME);	// The actual clause that will be triggered by the hook. (You can call this multiple times, and have multiple clauses trigger on the same hook.)
	
	// --------------------------------------------------------------

	// RETURNS: Updated version of THE_CONTRACT. (Or NULL.)
	static const std::string SmartContract_AddParty(const std::string THE_CONTRACT,	// The contract, about to have the party added to it.
													const std::string SIGNER_NYM_ID,// Use any Nym you wish here. (The signing at this point is only to cause a save.)
													// ----------------------------------------
													const std::string PARTY_NAME,	// The Party's NAME as referenced in the smart contract. (And the scripts...)
													// ----------------------------------------
													const std::string AGENT_NAME);	// An AGENT will be added by default for this party. Need Agent NAME.
	// (FYI, that is basically the only option, until I code Entities and Roles. Until then, a party can ONLY be
	// a Nym, with himself as the agent representing that same party. Nym ID is supplied on ConfirmParty() below.)
	
	// ----------------------------------------
	
	// Used when creating a theoretical smart contract (that could be used over and over again with different parties.)
	//
	// returns: the updated smart contract (or NULL)
	static const std::string SmartContract_AddAccount(const std::string THE_CONTRACT,	// The contract, about to have the account added to it.
													  const std::string SIGNER_NYM_ID,	// Use any Nym you wish here. (The signing at this point is only to cause a save.)
													  // ----------------------------------------
													  const std::string PARTY_NAME,		// The Party's NAME as referenced in the smart contract. (And the scripts...)
													  // ----------------------------------------
													  const std::string ACCT_NAME,		// The Account's name as referenced in the smart contract
													  const std::string ASSET_TYPE_ID);	// Asset Type ID for the Account.
	
	// ----------------------------------------
	
	static int SmartContract_CountNumsNeeded(const std::string THE_CONTRACT,	// The smart contract, about to be queried by this function.
											 const std::string AGENT_NAME);
	// ----------------------------------------
	
	// Used when taking a theoretical smart contract, and setting it up to use specific Nyms and accounts. This function sets the ACCT ID for the acct specified by party name and acct name.
	// Returns the updated smart contract (or NULL.)
	//
	static const std::string SmartContract_ConfirmAccount(const std::string THE_CONTRACT,	// The smart contract, about to be changed by this function.
														  const std::string SIGNER_NYM_ID,	// Use any Nym you wish here. (The signing at this point is only to cause a save.)
														  // ----------------------------------------
														  const std::string PARTY_NAME,	// Should already be on the contract. (This way we can find it.)
														  // ----------------------------------------
														  const std::string ACCT_NAME,	// Should already be on the contract. (This way we can find it.)
														  const std::string AGENT_NAME,	// The agent name for this asset account.
														  const std::string ACCT_ID);	// AcctID for the asset account. (For acct_name).
	
	static const std::string SmartContract_ConfirmParty(const std::string THE_CONTRACT,	// The smart contract, about to be changed by this function.
														const std::string PARTY_NAME,	// Should already be on the contract. This way we can find it.
														// ----------------------------------------
														const std::string NYM_ID);		// Nym ID for the party, the actual owner, 
	// ===> AS WELL AS for the default AGENT of that party.
	
	// ---------------------------------------------------
	
	static bool HarvestClosingNumbers(const std::string SERVER_ID,
									  const std::string NYM_ID,
									  const std::string THE_CRON_ITEM);
	
	static bool HarvestAllNumbers(const std::string SERVER_ID,
								  const std::string NYM_ID,
								  const std::string THE_CRON_ITEM);
		
	// --------------------------------------------------
	static void activateSmartContract(const std::string SERVER_ID,
									  const std::string USER_ID,
									  const std::string THE_SMART_CONTRACT);
	// --------------------------------------------------
	static void triggerClause(const std::string SERVER_ID,
							  const std::string USER_ID,
							  const std::string TRANSACTION_NUMBER,
							  const std::string CLAUSE_NAME,
							  const std::string STR_PARAM);
	// ---------------------------------------------------
	
	static int GetMemlogSize();
	
	static const std::string GetMemlogAtIndex(int nIndex);
	
	static const std::string PeekMemlogFront();
	static const std::string PeekMemlogBack();
	
	static bool PopMemlogFront(); 
	static bool PopMemlogBack(); 
	
	
	static const std::string CreateNym();
	
	
	static bool AddServerContract(const std::string szContract); // returns OT_TRUE (1) or OT_FALSE(0)
	
	static bool AddAssetContract(const std::string szContract); // returns OT_TRUE (1) or OT_FALSE(0)
	
	static int GetServerCount();
	static int GetAssetTypeCount();
	static int GetAccountCount();
	static int GetNymCount();
	
	static const std::string GetServer_ID(int nIndex); // based on Index (above 4 functions) this returns the Server's ID
	static const std::string GetServer_Name(const std::string SERVER_ID); // Return's Server's name (based on server ID)
	
	static const std::string GetAssetType_ID(int nIndex); // returns Asset Type ID (based on index from GetAssetTypeCount)
	static const std::string GetAssetType_Name(const std::string ASSET_TYPE_ID); // Returns asset type name based on Asset Type ID
	
	static const std::string GetAccountWallet_ID(int nIndex);	 // returns a string containing the account ID, based on index.
	static const std::string GetAccountWallet_Name(const std::string ACCOUNT_ID);	 // returns the account name, based on account ID.
	static const std::string GetAccountWallet_Balance(const std::string ACCOUNT_ID);	 // returns the account balance, based on account ID.
	static const std::string GetAccountWallet_Type(const std::string ACCOUNT_ID);	 // returns the account type (simple, issuer, etc)
	static const std::string GetAccountWallet_AssetTypeID(const std::string ACCOUNT_ID);	 // returns asset type ID of the account
	static const std::string GetAccountWallet_ServerID(const std::string ACCOUNT_ID);	 // returns Server ID of the account
	static const std::string GetAccountWallet_NymID(const std::string ACCOUNT_ID);	 // returns Nym ID of the account
	
	static bool VerifyAccountReceipt(const std::string SERVER_ID, const std::string NYM_ID, const std::string ACCT_ID);
	
	static int GetNym_TransactionNumCount(const std::string SERVER_ID, const std::string NYM_ID);
	
	static const std::string GetNym_ID(int nIndex); /// based on Index (above 4 functions) this returns the Nym's ID
	static const std::string GetNym_Name(const std::string NYM_ID); /// Returns Nym Name (based on NymID)
	static const std::string GetNym_Stats(const std::string NYM_ID); /// Returns Nym Statistics (based on NymID)
	
	static bool IsNym_RegisteredAtServer(const std::string NYM_ID, const std::string SERVER_ID); // actually returns OT_BOOL
	
	// ---------------------------------------------------------
	static int					GetNym_MailCount(const std::string NYM_ID);
	
	static const std::string	GetNym_MailContentsByIndex(const std::string NYM_ID, int nIndex); /// returns the message itself (Subject: optionally as first line)
	
	static const std::string	GetNym_MailSenderIDByIndex(const std::string NYM_ID, int nIndex); /// returns the NymID of the sender.
	static const std::string	GetNym_MailServerIDByIndex(const std::string NYM_ID, int nIndex); /// returns the ServerID where the message came from.
	
	static bool					Nym_RemoveMailByIndex(const std::string NYM_ID, int nIndex); /// actually returns OT_BOOL, (1 or 0.)
	static bool					Nym_VerifyMailByIndex(const std::string NYM_ID, int nIndex); /// actually returns OT_BOOL. OT_TRUE if signature verifies. (Sender Nym MUST be in my wallet for this to work.)
	
	// ---------------------------------------------------------
	static int					GetNym_OutmailCount(const std::string NYM_ID);
	
	static const std::string	GetNym_OutmailContentsByIndex(const std::string NYM_ID, int nIndex); /// returns the message itself (Subject: optionally as first line)
	
	static const std::string	GetNym_OutmailRecipientIDByIndex(const std::string NYM_ID, int nIndex); /// returns the NymID of the recipient.
	static const std::string	GetNym_OutmailServerIDByIndex(const std::string NYM_ID, int nIndex); /// returns the ServerID where the message came from.
	
	static bool					Nym_RemoveOutmailByIndex(const std::string NYM_ID, int nIndex); /// actually returns OT_BOOL, (1 or 0.)
	static bool					Nym_VerifyOutmailByIndex(const std::string NYM_ID, int nIndex); /// actually returns OT_BOOL. OT_TRUE if signature verifies. (Sender Nym MUST be in my wallet for this to work.)
	
	// ---------------------------------------------------------
	static bool Wallet_CanRemoveServer(const std::string SERVER_ID);
	static bool Wallet_RemoveServer(const std::string SERVER_ID);
	static bool Wallet_CanRemoveAssetType(const std::string ASSET_ID);
	static bool Wallet_RemoveAssetType(const std::string ASSET_ID);
	static bool Wallet_CanRemoveNym(const std::string NYM_ID);
	static bool Wallet_RemoveNym(const std::string NYM_ID);
	static bool Wallet_CanRemoveAccount(const std::string ACCOUNT_ID);

	static const std::string Wallet_ImportNym(const std::string DISPLAY_NAME, const std::string KEY_FILE_CONTENTS);

	// -----------------------------------

	static bool SetNym_Name(const std::string NYM_ID, 
						   const std::string SIGNER_NYM_ID, 
						   const std::string NYM_NEW_NAME); // actually returns OT_BOOL.
	
	static bool SetAccountWallet_Name(const std::string ACCT_ID, 
									  const std::string SIGNER_NYM_ID, 
									  const std::string ACCT_NEW_NAME);
	static bool SetAssetType_Name(const std::string ASSET_ID, 
								  const std::string STR_NEW_NAME);
	static bool SetServer_Name(const std::string SERVER_ID, 
							   const std::string STR_NEW_NAME); 
	
	static const std::string VerifyAndRetrieveXMLContents(const std::string THE_CONTRACT,
														  const std::string USER_ID);
	
	// ----------------------------------------------------------------------
	static const std::string WriteCheque(const std::string SERVER_ID,
										 const std::string CHEQUE_AMOUNT, 
										 const std::string VALID_FROM, 
										 const std::string VALID_TO,
										 const std::string SENDER_ACCT_ID,
										 const std::string SENDER_USER_ID,
										 const std::string CHEQUE_MEMO, 
										 const std::string RECIPIENT_USER_ID);
	
	// ----------------------------------------------------------------------
		
	static bool DiscardCheque(const std::string SERVER_ID,
							  const std::string USER_ID, 
							  const std::string ACCT_ID, 
							  const std::string THE_CHEQUE);
	
	// ----------------------------------------------------------------------
//	static const std::string ProposePaymentPlan(const std::string SERVER_ID,
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
//										   );									
	
	static const std::string ConfirmPaymentPlan(const std::string SERVER_ID,
												const std::string SENDER_USER_ID,
												const std::string SENDER_ACCT_ID,
												const std::string RECIPIENT_USER_ID,
												const std::string PAYMENT_PLAN);
	// -----------------------------------------------------------------

	static const std::string LoadUserPubkey(const std::string USER_ID); // returns NULL, or a public key.
	static const std::string LoadPubkey(const std::string USER_ID); // returns NULL, or a public key.

	static bool VerifyUserPrivateKey(const std::string USER_ID); // returns OT_BOOL

	static const std::string LoadPurse(const std::string SERVER_ID,
									   const std::string ASSET_TYPE_ID,
									   const std::string USER_ID); // returns NULL, or a purse.
	
	static const std::string LoadMint(const std::string SERVER_ID,
									  const std::string ASSET_TYPE_ID); // returns NULL, or a mint
	
	static const std::string LoadAssetContract(const std::string ASSET_TYPE_ID); // returns NULL, or an asset contract.
	static const std::string LoadServerContract(const std::string SERVER_ID); // returns NULL, or a server contract.

	static bool Mint_IsStillGood(const std::string SERVER_ID,
								 const std::string USER_ID,
								 const std::string ASSET_TYPE_ID);

	static bool IsBasketCurrency(const std::string ASSET_TYPE_ID); // returns OT_BOOL (OT_TRUE or OT_FALSE aka 1 or 0.)
	static int Basket_GetMemberCount(const std::string BASKET_ASSET_TYPE_ID);
	static const std::string Basket_GetMemberType(const std::string BASKET_ASSET_TYPE_ID,
												  const int nIndex);
	static const std::string Basket_GetMinimumTransferAmount(const std::string BASKET_ASSET_TYPE_ID);
	static const std::string Basket_GetMemberMinimumTransferAmount(const std::string BASKET_ASSET_TYPE_ID,
																   const int nIndex);
	
	// --------------------------------------------------------------
	static const std::string LoadAssetAccount(const std::string SERVER_ID,
											  const std::string USER_ID,
											  const std::string ACCOUNT_ID); // Returns NULL, or an account.
	static const std::string LoadInbox(const std::string SERVER_ID,
									   const std::string USER_ID,
									   const std::string ACCOUNT_ID); // Returns NULL, or an inbox.
	static const std::string LoadOutbox(const std::string SERVER_ID,
										const std::string USER_ID,
										const std::string ACCOUNT_ID); // returns NULL, or an outbox.
	
	static const std::string LoadInboxNoVerify(const std::string SERVER_ID,
											   const std::string USER_ID,
											   const std::string ACCOUNT_ID); // Returns NULL, or an inbox.
	static const std::string LoadOutboxNoVerify(const std::string SERVER_ID,
												const std::string USER_ID,
												const std::string ACCOUNT_ID); // returns NULL, or an outbox.
	
	// --------------------------------------------------------------
	static int Ledger_GetCount(const std::string SERVER_ID,
							   const std::string USER_ID,
							   const std::string ACCOUNT_ID,
							   const std::string THE_LEDGER); // Returns number of transactions within.
	// -----------------------------------------------------------------------
	static const std::string Ledger_CreateResponse(const std::string SERVER_ID,
												   const std::string USER_ID,
												   const std::string ACCOUNT_ID,
												   const std::string ORIGINAL_LEDGER); 
	// -------------------------------------------------------------------------
	static const std::string Ledger_GetTransactionByIndex(const std::string SERVER_ID,
														  const std::string USER_ID,
														  const std::string ACCOUNT_ID,
														  const std::string THE_LEDGER,
														  int nIndex); // returns transaction by index.
	
	static const std::string Ledger_GetTransactionByID(const std::string SERVER_ID,
													   const std::string USER_ID,
													   const std::string ACCOUNT_ID,
													   const std::string THE_LEDGER,
													   const std::string TRANSACTION_NUMBER); // returns transaction by ID.
	
	static const std::string Ledger_GetTransactionIDByIndex(const std::string SERVER_ID,
															const std::string USER_ID,
															const std::string ACCOUNT_ID,
															const std::string THE_LEDGER,
															int nIndex); // returns transaction number by index.
	// --------------------------------------------------------------
	static const std::string Ledger_AddTransaction(const std::string SERVER_ID,
												   const std::string USER_ID,
												   const std::string ACCOUNT_ID,
												   const std::string THE_LEDGER,
												   const std::string THE_TRANSACTION);
	// --------------------------------------------------------------
	static const std::string Transaction_CreateResponse(const std::string SERVER_ID,
														const std::string USER_ID,
														const std::string ACCOUNT_ID,
														const std::string RESPONSE_LEDGER, // To be sent to the server...
														const std::string ORIGINAL_TRANSACTION, // Responding to...?
														bool BOOL_DO_I_ACCEPT);   // 1 or 0  (OT_TRUE or OT_FALSE.)
	/// -------------------------------------------------------------------------
	static const std::string Ledger_FinalizeResponse(const std::string SERVER_ID,
													 const std::string USER_ID,
													 const std::string ACCOUNT_ID,
													 const std::string THE_LEDGER); // 'Response' ledger be sent to the server...
	// --------------------------------------------------------------------
	/// Get Transaction Type  (internally uses GetTransactionTypeString().)
	//
	static const std::string Transaction_GetType(const std::string SERVER_ID,
												 const std::string USER_ID,
												 const std::string ACCOUNT_ID,
												 const std::string THE_TRANSACTION);
	// --------------------------------------------------------------------
	static const std::string Transaction_GetVoucher(const std::string SERVER_ID,
													const std::string USER_ID,
													const std::string ACCOUNT_ID,
													const std::string THE_TRANSACTION);
	// --------------------------------------------------
	static bool Transaction_GetSuccess(const std::string SERVER_ID,
									   const std::string USER_ID,
									   const std::string ACCOUNT_ID,
									   const std::string THE_TRANSACTION); 
	
	static bool Transaction_GetBlnceAgrmntSuccess(const std::string SERVER_ID,
												  const std::string USER_ID,
												  const std::string ACCOUNT_ID,
												  const std::string THE_TRANSACTION); 
	/// --------------------------------------------------
	static const std::string Transaction_GetDateSigned(const std::string SERVER_ID,
													   const std::string USER_ID,
													   const std::string ACCOUNT_ID,
													   const std::string THE_TRANSACTION); 
	
	static const std::string Transaction_GetAmount(const std::string SERVER_ID,
												   const std::string USER_ID,
												   const std::string ACCOUNT_ID,
												   const std::string THE_TRANSACTION);
	// --------------------------------------------------
	static const std::string Pending_GetNote(const std::string SERVER_ID,
											 const std::string USER_ID,
											 const std::string ACCOUNT_ID,
											 const std::string THE_TRANSACTION);
	// ----------	
	static const std::string Transaction_GetSenderUserID(const std::string SERVER_ID,
														 const std::string USER_ID,
														 const std::string ACCOUNT_ID,
														 const std::string THE_TRANSACTION);
	
	static const std::string Transaction_GetSenderAcctID(const std::string SERVER_ID,
														 const std::string USER_ID,
														 const std::string ACCOUNT_ID,
														 const std::string THE_TRANSACTION);
	
	static const std::string Transaction_GetRecipientUserID(const std::string SERVER_ID,
															const std::string USER_ID,
															const std::string ACCOUNT_ID,
															const std::string THE_TRANSACTION);
	
	static const std::string Transaction_GetRecipientAcctID(const std::string SERVER_ID,
															const std::string USER_ID,
															const std::string ACCOUNT_ID,
															const std::string THE_TRANSACTION);
	
	static const std::string Transaction_GetDisplayReferenceToNum(const std::string SERVER_ID,
																  const std::string USER_ID,
																  const std::string ACCOUNT_ID,
																  const std::string THE_TRANSACTION);
	// ---------------------------------------------------------
	static const std::string CreatePurse(const std::string SERVER_ID,
										 const std::string ASSET_TYPE_ID,
										 const std::string USER_ID); // returns NULL, or a purse. UserID optional.
	static bool SavePurse(const std::string SERVER_ID,
						  const std::string ASSET_TYPE_ID,
						  const std::string USER_ID,
						  const std::string THE_PURSE); // returns OT_BOOL
	
	// --------------------------------------------------------------------
	static const std::string Purse_GetTotalValue(const std::string SERVER_ID,
												 const std::string ASSET_TYPE_ID,
												 const std::string THE_PURSE);
	// ---
	static int Purse_Count(const std::string SERVER_ID,
						   const std::string ASSET_TYPE_ID,
						   const std::string THE_PURSE);
	
	static const std::string Purse_Peek(const std::string SERVER_ID,
										const std::string ASSET_TYPE_ID,
										const std::string USER_ID,
										const std::string THE_PURSE);
	
	static const std::string Purse_Pop(const std::string SERVER_ID,
									   const std::string ASSET_TYPE_ID,
									   const std::string USER_ID,
									   const std::string THE_PURSE);
	
	static const std::string Purse_Push(const std::string SERVER_ID,
										const std::string ASSET_TYPE_ID,
										const std::string USER_ID,
										const std::string THE_PURSE,
										const std::string THE_TOKEN);
	// ------------------
	static bool Wallet_ImportPurse(const std::string SERVER_ID,
								   const std::string ASSET_TYPE_ID,
								   const std::string USER_ID, // you pass in the purse you're trying to import
								   const std::string THE_PURSE); // It should either have your User ID on it, or the key should be inside so you can import.
	
	static void exchangePurse(const std::string SERVER_ID,
							  const std::string ASSET_TYPE_ID,
							  const std::string USER_ID,
							  const std::string THE_PURSE);
	// --------------
	static const std::string Token_ChangeOwner(const std::string SERVER_ID,
											   const std::string ASSET_TYPE_ID,
											   const std::string THE_TOKEN,
											   const std::string OLD_OWNER_NYM_ID,
											   const std::string NEW_OWNER_NYM_ID);
	
	static const std::string Token_GetID(const std::string SERVER_ID,
										 const std::string ASSET_TYPE_ID,
										 const std::string THE_TOKEN);
	
	static const std::string Token_GetDenomination(const std::string SERVER_ID,
												   const std::string ASSET_TYPE_ID,
												   const std::string THE_TOKEN);
	
	static int Token_GetSeries(const std::string SERVER_ID,
							   const std::string ASSET_TYPE_ID,
							   const std::string THE_TOKEN);
	
	static const std::string Token_GetValidFrom(const std::string SERVER_ID,
												const std::string ASSET_TYPE_ID,
												const std::string THE_TOKEN);
	
	static const std::string Token_GetValidTo(const std::string SERVER_ID,
											  const std::string ASSET_TYPE_ID,
											  const std::string THE_TOKEN);
	
	static const std::string Token_GetAssetID(const std::string THE_TOKEN);
	static const std::string Token_GetServerID(const std::string THE_TOKEN);
	// --------------------------------------------------------------------
	
	static void checkServerID(const std::string SERVER_ID, const std::string USER_ID);
	
	static void createUserAccount(const std::string SERVER_ID,
								  const std::string USER_ID);
	
	static void deleteUserAccount(const std::string SERVER_ID,
								  const std::string USER_ID);
	
	static void deleteAssetAccount(const std::string SERVER_ID,
								   const std::string USER_ID,
								   const std::string ACCOUNT_ID);
	
	// --------------------------------------------------------------------
	static void checkUser(const std::string SERVER_ID,
						  const std::string USER_ID,
						  const std::string USER_ID_CHECK);
	
	// --------------------------------------------------------------------
	static void usageCredits(const std::string SERVER_ID,
							 const std::string USER_ID,
							 const std::string USER_ID_CHECK,
							 const std::string ADJUSTMENT);
	
	// --------------------------------------------------------------------
	static void sendUserMessage(const std::string SERVER_ID,
								const std::string USER_ID,
								const std::string USER_ID_RECIPIENT,
								const std::string RECIPIENT_PUBKEY,
								const std::string THE_MESSAGE);
	// --------------------------------------------------------------------
	static void getRequest(const std::string SERVER_ID,
						   const std::string USER_ID);
	
	static void getTransactionNumber(const std::string SERVER_ID,
									 const std::string USER_ID);
	// --------------------------------------------------------------------
	static void issueAssetType(const std::string	SERVER_ID,
							   const std::string	USER_ID,
							   const std::string	THE_CONTRACT);
	// --------------------------------------------------------------------
	static void getContract(const std::string SERVER_ID,
							const std::string USER_ID,
							const std::string ASSET_ID);
	// --------------------------------------------------------------------------
	static void getMint(const std::string SERVER_ID,
						const std::string USER_ID,
						const std::string ASSET_ID);
	// ---------------------------------------------------------------------------
	static void createAssetAccount(const std::string SERVER_ID,
								   const std::string USER_ID,
								   const std::string ASSET_ID);
	// --------------------------------------------------------------------------
	static void getAccount(const std::string SERVER_ID,
						   const std::string USER_ID,
						   const std::string ACCT_ID);
	// --------------------------------------------------
	
	static const std::string GenerateBasketCreation(const std::string USER_ID,
													const std::string MINIMUM_TRANSFER); // If basket is X=2,3,4, then this is X.
	
	static const std::string AddBasketCreationItem(const std::string USER_ID, // for signature.
												   const std::string THE_BASKET, // created in above call.
												   const std::string ASSET_TYPE_ID, // Adding an asset type to the new basket.
												   const std::string MINIMUM_TRANSFER); // If basket is 5=X,X,X then this is an X.
	
	static void issueBasket(const std::string SERVER_ID,
							const std::string USER_ID,
							const std::string THE_BASKET);
	
	static const std::string GenerateBasketExchange(const std::string SERVER_ID,
													const std::string USER_ID,
													const std::string BASKET_ASSET_TYPE_ID,
													const std::string BASKET_ASSET_ACCT_ID,
													// -------------------------------------
													const int TRANSFER_MULTIPLE);
	
	static const std::string AddBasketExchangeItem(const std::string SERVER_ID,
												   const std::string USER_ID,
												   const std::string THE_BASKET, 
												   const std::string ASSET_TYPE_ID,
												   const std::string ASSET_ACCT_ID);
	// --------------------------------------------------------------------------
	static void exchangeBasket(const std::string SERVER_ID,
							   const std::string USER_ID,
							   const std::string BASKET_ASSET_ID,
							   const std::string THE_BASKET,
							   const bool BOOL_EXCHANGE_IN_OR_OUT); // exchanging in == true, out == false.
	
	static void notarizeWithdrawal(const std::string SERVER_ID,
								   const std::string USER_ID,
								   const std::string ACCT_ID,
								   const std::string AMOUNT);
	
	static void notarizeDeposit(const std::string SERVER_ID,
								const std::string USER_ID,
								const std::string ACCT_ID,
								const std::string THE_PURSE);
	
	static void notarizeTransfer(const std::string SERVER_ID,
								 const std::string USER_ID,
								 const std::string ACCT_FROM,
								 const std::string ACCT_TO,
								 const std::string AMOUNT,
								 const std::string NOTE);
	
	static void getInbox(const std::string SERVER_ID,
						 const std::string USER_ID,
						 const std::string ACCT_ID);
	
	static void getOutbox(const std::string SERVER_ID,
						  const std::string USER_ID,
						  const std::string ACCT_ID);
	
	
	static void getNymbox(const std::string SERVER_ID,
						  const std::string USER_ID);
	
	static const std::string LoadNymbox(const std::string SERVER_ID,
										const std::string USER_ID); // Returns NULL, or a Nymbox.
	
	static const std::string LoadNymboxNoVerify(const std::string SERVER_ID,
												const std::string USER_ID); // Returns NULL, or a Nymbox. (Without loading the box receipts.)
	
	static void getBoxReceipt(const std::string	SERVER_ID,
							  const std::string	USER_ID,
							  const std::string	ACCT_ID,	// If for Nymbox (vs inbox/outbox) then pass USER_ID in this field also.
							  const int			nBoxType,	// 0/nymbox, 1/inbox, 2/outbox
							  const std::string	TRANSACTION_NUMBER);
	
	static bool DoesBoxReceiptExist(const std::string	SERVER_ID,
									const std::string	USER_ID,
									const std::string	ACCT_ID,	// If for Nymbox (vs inbox/outbox) then pass USER_ID in this field also.
									const int			nBoxType,	// 0/nymbox, 1/inbox, 2/outbox
									const std::string	TRANSACTION_NUMBER);
	// --------------------------------------------------------------------------
	static void processInbox(const std::string SERVER_ID,
							 const std::string USER_ID,
							 const std::string ACCT_ID,
							 const std::string ACCT_LEDGER);
	
	static int processNymbox(const std::string SERVER_ID,
							 const std::string USER_ID);
	
	// --------------------------------------------------------------------------
	static void withdrawVoucher(const std::string SERVER_ID,
								const std::string USER_ID,
								const std::string ACCT_ID,
								const std::string RECIPIENT_USER_ID,
								const std::string CHEQUE_MEMO,
								const std::string AMOUNT);
	// --------------------------------------------------------------------------
	static void depositCheque(const std::string SERVER_ID,
							  const std::string USER_ID,
							  const std::string ACCT_ID,
							  const std::string THE_CHEQUE);
	// --------------------------------------------------
	static void depositPaymentPlan(const std::string SERVER_ID,
								   const std::string USER_ID,
								   const std::string THE_PAYMENT_PLAN);
	// --------------------------------------------------
	static void issueMarketOffer(const std::string SERVER_ID,
								 const std::string USER_ID,
								 // -------------------------------------------
								 const std::string ASSET_ACCT_ID, // Perhaps this is the wheat market.
								 // -------------------------------------------
								 const std::string CURRENCY_ACCT_ID, // Perhaps I'm buying the wheat with rubles.
								 // -------------------------------------------
								 const std::string MARKET_SCALE,				// Defaults to minimum of 1. Market granularity.
								 const std::string MINIMUM_INCREMENT,		// This will be multiplied by the Scale. Min 1.
								 const std::string TOTAL_ASSETS_ON_OFFER,	// Total assets available for sale or purchase. Will be multiplied by minimum increment.
								 const std::string PRICE_LIMIT,				// Per Minimum Increment...
								 bool	bBuyingOrSelling); // Actually OT_BOOL. SELLING == OT_TRUE, BUYING == OT_FALSE.
	// --------------------------------------------------
	
	static void getMarketList(const std::string SERVER_ID, const std::string USER_ID);
	
	static void getMarketOffers(const std::string SERVER_ID, const std::string USER_ID, 
								const std::string MARKET_ID, const std::string MAX_DEPTH); // Market Depth
	
	static void getMarketRecentTrades(const std::string SERVER_ID, const std::string USER_ID, 
									  const std::string MARKET_ID);
	
	static void getNym_MarketOffers(const std::string SERVER_ID, const std::string USER_ID); // Offers this Nym has out on market.
	
	static void cancelMarketOffer(const std::string SERVER_ID, 
								  const std::string USER_ID, 
								  const std::string ASSET_ACCT_ID, 
								  const std::string TRANSACTION_NUMBER);
	
	static void cancelPaymentPlan(const std::string SERVER_ID, 
								  const std::string USER_ID, 
								  const std::string FROM_ACCT_ID, 
								  const std::string TRANSACTION_NUMBER);
	// -----------------------------------------------------------
	static const std::string PopMessageBuffer();
	
	static void FlushMessageBuffer();
	
	static void Sleep(const std::string MILLISECONDS);

	// -----------------------------------------------------------

	static bool ResyncNymWithServer(const std::string SERVER_ID,
									const std::string USER_ID,
									const std::string THE_MESSAGE);

	// -----------------------------------------------------------
	
	static void queryAssetTypes(const std::string SERVER_ID,
								const std::string USER_ID,
								const std::string ENCODED_MAP);
	
	static const std::string Message_GetCommand(const std::string THE_MESSAGE);
	
	static const std::string Message_GetPayload(const std::string THE_MESSAGE);
	
	static bool Message_GetSuccess(const std::string THE_MESSAGE);
	
	static int Message_GetDepth(const std::string THE_MESSAGE);
	
	static const std::string Message_GetUsageCredits(const std::string THE_MESSAGE);
	
	static bool Msg_GetTransactionSuccess(const std::string SERVER_ID,
										  const std::string USER_ID,
										  const std::string ACCOUNT_ID,
										  const std::string THE_MESSAGE);
	
	static bool Msg_GetBlnceAgrmntSuccess(const std::string SERVER_ID,
										  const std::string USER_ID,
										  const std::string ACCOUNT_ID,
										  const std::string THE_MESSAGE);
	
	static const std::string Message_GetLedger(const std::string THE_MESSAGE);
	
	static const std::string Message_GetNewAssetTypeID(const std::string THE_MESSAGE);
	
	static const std::string Message_GetNewIssuerAcctID(const std::string THE_MESSAGE);
	
	static const std::string Message_GetNewAcctID(const std::string THE_MESSAGE);
	
	// -----------------------------------------------------------
	
public:
	// -----------------------------------------------------------
	OTAPI_Wrap();
	~OTAPI_Wrap();
};


















#endif   // __OT_API_WRAP_H__

