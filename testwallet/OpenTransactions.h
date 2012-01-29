/************************************************************************************
 *    
 *  OpenTransactions.h   This is the header to include if you link to OTAPI.a
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




#ifndef __OPEN_TRANSACTIONS_INTERFACE_H__
#define __OPEN_TRANSACTIONS_INTERFACE_H__

#include <string>

class OTString;
class OTASCIIArmor;
class OTIdentifier;
class OTServerContract;
class OTEnvelope;
class OTWallet;
class OTClient;
class OTPseudonym;
class OTAccount;
class OTAssetContract;
class OTServerContract;
class OTPurse;
class OTCheque;
class OTPaymentPlan;
class OTMint;
class OTMessage;
class OTLedger;


// This function is what makes Open Transactions go over XmlRpc/HTTP instead of TCP/SSL
// (If you compile it in rpc mode using "make rpc"
//
#if defined(OT_ZMQ_MODE)
#include <zmq.hpp>
#endif


// --------------------------------------------------------------------

class OT_API // The C++ high-level interface to the Open Transactions client-side.
{
	OTWallet *		m_pWallet;
	OTClient *		m_pClient;

	bool			m_bInitialized;
	
	OTString *		m_pstrStoragePath;
	OTString *		m_pstrWalletFilename;
	
	static zmq::context_t	s_ZMQ_Context;

public:

	static void TransportCallback(OTServerContract & theServerContract, OTEnvelope & theEnvelope);

	OTWallet * GetWallet(const char * szFuncName=NULL);

	inline OTClient * GetClient() { return m_pClient; }
	
	inline const char * GetStoragePath() { return ((NULL == m_pstrStoragePath) ? NULL : m_pstrStoragePath->Get()); }
	inline const char * GetWalletFilename() { return ((NULL == m_pstrWalletFilename) ? NULL : m_pstrWalletFilename->Get()); }
	
	inline bool SetStoragePath(const OTString & strPath) 
	{ return ((NULL == m_pstrStoragePath) ? false : (m_pstrStoragePath->Set(strPath), true) ); }
	inline bool SetWalletFilename(const OTString & strFilename) 
	{ return ((NULL == m_pstrWalletFilename) ? false : (m_pstrWalletFilename->Set(strFilename), true) ); }
	
	OT_API();
	~OT_API();
	
	bool LoadConfigFile(const OTString & strMainPath);

			bool Init(OTString & strClientPath);	// Per instance.
	static	bool InitOTAPI();						// Once per run.

	bool IsInitialized() const { return m_bInitialized; }
	
	bool LoadWallet(const OTString & strFilename);
	
	// Note: these two functions are NOT used in XmlRpc Mode
	// ONLY for SSL/TCP mode...
	bool ConnectServer(OTIdentifier & SERVER_ID,
					   OTIdentifier	& USER_ID,
					   OTString & strCA_FILE, 
					   OTString & strKEY_FILE, 
					   OTString & strKEY_PASSWORD);
	bool ProcessSockets();
	// --------------------------------------------------
	
	long GetTime();

	// --------------------------------------------------
	// Reading data about the local wallet.. presumably already loaded.
	
	int GetNymCount();
	int GetServerCount();
	int GetAssetTypeCount();
	int GetAccountCount();
	
	bool GetNym(int iIndex, OTIdentifier & NYM_ID, OTString & NYM_NAME);
	bool GetServer(int iIndex, OTIdentifier & THE_ID, OTString & THE_NAME);
	bool GetAssetType(int iIndex, OTIdentifier & THE_ID, OTString & THE_NAME);
	bool GetAccount(int iIndex, OTIdentifier & THE_ID, OTString & THE_NAME);
	
	// ----------------------------------------------------
	// In this case, the ID is input, the pointer is output.
	// Gets the data from Wallet.
	//
	OTPseudonym *		GetNym(const OTIdentifier & NYM_ID, const char * szFuncName=NULL);
	OTServerContract *	GetServer(const OTIdentifier & THE_ID, const char * szFuncName=NULL);
	OTAssetContract *	GetAssetType(const OTIdentifier & THE_ID, const char * szFuncName=NULL);
	OTAccount *			GetAccount(const OTIdentifier & THE_ID, const char * szFuncName=NULL);	
    
	OTPseudonym *		GetNymByIDPartialMatch(const std::string PARTIAL_ID, const char * szFuncName=NULL);
	OTServerContract *	GetServerContractPartialMatch(const std::string PARTIAL_ID, const char * szFuncName=NULL);
	OTAssetContract *	GetAssetContractPartialMatch(const std::string PARTIAL_ID, const char * szFuncName=NULL);
	OTAccount *         GetAccountPartialMatch(const std::string PARTIAL_ID, const char * szFuncName=NULL);
	
	// ----------------------------------------------------
	
	OTPseudonym * GetOrLoadPublicNym(const OTIdentifier & NYM_ID, const char * szFuncName=NULL);
	OTPseudonym * GetOrLoadPrivateNym(const OTIdentifier & NYM_ID, const char * szFuncName=NULL);
	OTPseudonym * GetOrLoadNym(const OTIdentifier & NYM_ID, const char * szFuncName=NULL);

	OTAccount * GetOrLoadAccount(		OTPseudonym		& theNym,
								 const	OTIdentifier	& ACCT_ID,
								 const	OTIdentifier	& SERVER_ID,
								 const char *	szFuncName	=NULL);
	
	OTAccount * GetOrLoadAccount(const	OTIdentifier	& NYM_ID,
								 const	OTIdentifier	& ACCT_ID,
								 const	OTIdentifier	& SERVER_ID,
								 const char *	szFuncName	=NULL);
	
	// ----------------------------------------------------
	
	// The name is basically just a client-side label.
	// This function lets you change it.
	bool SetNym_Name(const OTIdentifier	&	NYM_ID, 
					 const OTIdentifier	&	SIGNER_NYM_ID,
					 const OTString		&	NYM_NEW_NAME);
	
	// The name is basically just a client-side label.
	// This function lets you change it.
	bool SetAccount_Name(const OTIdentifier &	ACCT_ID, 
						 const OTIdentifier &	SIGNER_NYM_ID,
						 const OTString		&	ACCT_NEW_NAME);
	
	// The name is basically just a client-side label.
	// This function lets you change it.
	bool SetAssetType_Name(const OTIdentifier	&	ASSET_ID, 
						   const OTString		&	STR_NEW_NAME);

	// The name is basically just a client-side label.
	// This function lets you change it.
	bool SetServer_Name(const OTIdentifier	&	SERVER_ID, 
						const OTString		&	STR_NEW_NAME);

	// ----------------------------------------------------
	
	// Accessing local storage...
	// (Caller responsible to delete.)
	//
	OTPseudonym *		LoadPublicNym(const OTIdentifier & NYM_ID, const char * szFuncName=NULL);
	OTPseudonym *		LoadPrivateNym(const OTIdentifier & NYM_ID, const char * szFuncName=NULL);
	
	OTPseudonym *		CreateNym(); // returns a new nym (with key pair) and files created. (Or NULL.)

	bool	IsNym_RegisteredAtServer(const OTIdentifier & NYM_ID, const OTIdentifier & SERVER_ID);
	
	// ----------------------------------------------------
	//
	// ENCODE, DECODE, SIGN, VERIFY, ENCRYPT, DECRYPT
	
	
	// --------------------------------------------------------------------
	/** OT-encode a plaintext string.
	 This will pack, compress, and base64-encode a plain string.
	 Returns the base64-encoded string, or NULL.
	 */
	bool Encode(const OTString	&	strPlaintext,
				// ---------------------
				OTString		&	strOutput,
				bool bLineBreaks=true);

	
	// --------------------------------------------------------------------
	/** Decode an OT-encoded string (back to plaintext.)
	 This will base64-decode, uncompress, and unpack an OT-encoded string.
	 Returns the plaintext string, or NULL.
	 */
	bool Decode(const OTString	&	strEncoded,
				// ---------------------
				OTString		&	strOutput,
				bool bLineBreaks=true);
	
	// --------------------------------------------------------------------
	/** OT-ENCRYPT a plaintext string.
	 This will encode, ENCRYPT, and encode a plain string.
	 Returns the base64-encoded ciphertext, or NULL.
	 */
	bool Encrypt(const OTIdentifier	&	theRecipientNymID, 
				 const OTString		&	strPlaintext,
				 // ---------------------
				 OTString			&	strOutput);	
	
	// --------------------------------------------------------------------
	/** OT-DECRYPT an OT-encrypted string back to plaintext.
	 Decrypts the base64-encoded ciphertext back into a normal string plaintext.
	 Returns the plaintext string, or NULL.
	 */
	bool Decrypt(const OTIdentifier	&	theRecipientNymID, 
				 const OTString		&	strCiphertext,
				 // ---------------------
				 OTString			&	strOutput);
	
	// --------------------------------------------------------------------
	/** OT-Sign a CONTRACT.  (First signature)
	 Tries to instantiate the contract object, based on the string passed in.
	 Then it releases ALL signatures, and then signs the contract.
	 Returns the signed contract, or NULL if failure.
	 */
	bool SignContract(const OTIdentifier	&	theSignerNymID, 
					  const OTString		&	strContract,
					  // ---------------------
					  OTString				&	strOutput);
	
	// --------------------------------------------------------------------
	/** OT-Sign a CONTRACT.  (Add a signature)
	 Tries to instantiate the contract object, based on the string passed in.
	 Signs the contract, WITHOUT releasing any signatures that are already there.
	 Returns the signed contract, or NULL if failure.
	 */
	bool AddSignature(const OTIdentifier	&	theSignerNymID, 
					  const OTString		&	strContract,
					  // ---------------------
					  OTString				&	strOutput);
	
	// --------------------------------------------------------------------
	/** OT-Verify the signature on a CONTRACT.
	 Returns true/false (success/fail)
	 */
	bool VerifySignature(const OTString		& strContract,
						 const OTIdentifier	& theSignerNymID,
						 OTContract			**ppContract=NULL); // If you use this optional parameter, then YOU are responsible to clean it up.
	
	/// Verify and Retrieve XML Contents.
	bool VerifyAndRetrieveXMLContents(const OTString		&	strContract,
									  const OTIdentifier	&	theSignerNymID,
									  // ---------------------
									  OTString				&	strOutput);
	
	// ----------------------------------------------------
	/// === Verify Account Receipt ===
	/// Returns bool. Verifies any asset account (intermediary files) against its own last signed receipt.
	/// Obviously this will fail for any new account that hasn't done any transactions yet, and thus has no receipts.
	///
	bool VerifyAccountReceipt(const OTIdentifier & SERVER_ID,
							  const OTIdentifier & USER_ID,
							  const OTIdentifier & ACCOUNT_ID);
	
	// ----------------------------------------------------
	//
	// Returns an OTCheque pointer, or NULL. 
	// (Caller responsible to delete.)
	OTCheque * WriteCheque(const OTIdentifier & SERVER_ID,
						   const long &			CHEQUE_AMOUNT, 
						   const time_t &		VALID_FROM, 
						   const time_t &		VALID_TO,
						   const OTIdentifier & SENDER_ACCT_ID,
						   const OTIdentifier & SENDER_USER_ID,
						   const OTString &		CHEQUE_MEMO, 
						   const OTIdentifier * pRECIPIENT_USER_ID=NULL);
	
	// ----------------------------------------------------
	// DISCARD CHEQUE (recover the transaction number for re-use, so the 
	// cheque itself can be discarded.)

	bool DiscardCheque(OTIdentifier	& SERVER_ID,
					   OTIdentifier	& USER_ID,
					   OTIdentifier	& ACCT_ID,
					   OTString		& THE_CHEQUE);
	
	// PROPOSE PAYMENT PLAN (called by Merchant)
	//
	// Returns an OTPaymentPlan pointer, or NULL. 
	// (Caller responsible to delete.)
	//
	// Payment Plan Delay, and Payment Plan Period, both default to 30 days (if you pass 0),
	// measured in seconds.
	//
	// Payment Plan Length, and Payment Plan Max Payments, both default to 0, which means
	// no maximum length and no maximum number of payments.
	//
	OTPaymentPlan * ProposePaymentPlan(const OTIdentifier & SERVER_ID,
									// ----------------------------------------
									 const time_t		& VALID_FROM, 
									 const time_t		& VALID_TO,
									 // ----------------------------------------
									 const OTIdentifier & SENDER_ACCT_ID,
									 const OTIdentifier & SENDER_USER_ID,
									 // ----------------------------------------
									 const OTString		& PLAN_CONSIDERATION, // like a memo.
									 // ----------------------------------------
									 const OTIdentifier & RECIPIENT_ACCT_ID,
									 const OTIdentifier & RECIPIENT_USER_ID,
									 // ----------------------------------------  // If it's above zero, the initial
									 const long			& INITIAL_PAYMENT_AMOUNT, // amount will be processed after
									 const time_t		& INITIAL_PAYMENT_DELAY,  // delay (seconds from now.) 
									 // ----------------------------------------  // AND SEPARATELY FROM THIS...
									 const long			& PAYMENT_PLAN_AMOUNT,	// The regular amount charged,
									 const time_t		& PAYMENT_PLAN_DELAY,	// which begins occuring after delay
									 const time_t		& PAYMENT_PLAN_PERIOD,	// (seconds from now) and happens
									 // ----------------------------------------// every period, ad infinitum, until
									 time_t	  PAYMENT_PLAN_LENGTH		= 0,	// after the length (in seconds)
									 int	  PAYMENT_PLAN_MAX_PAYMENTS	= 0		// expires, or after the maximum
									 );											// number of payments. These last 
																				// two arguments are optional.
    // CONFIRM PAYMENT PLAN (called by Customer)
    //
    bool ConfirmPaymentPlan(const OTIdentifier & SERVER_ID,
                            // ----------------------------------------
                            const OTIdentifier & SENDER_USER_ID,
                            const OTIdentifier & SENDER_ACCT_ID,
                            // ----------------------------------------
                            const OTIdentifier & RECIPIENT_USER_ID,
                            // ----------------------------------------
                            OTPaymentPlan & thePlan);

	// ----------------------------------------------------

	OTPurse * LoadPurse(const OTIdentifier & SERVER_ID,
						const OTIdentifier & ASSET_ID,
						const OTIdentifier & USER_ID);
	
	bool SavePurse(const OTIdentifier & SERVER_ID,
				   const OTIdentifier & ASSET_ID,
				   const OTIdentifier & USER_ID,
				   OTPurse & THE_PURSE);
	
	OTMint * LoadMint(const OTIdentifier & SERVER_ID,
					  const OTIdentifier & ASSET_ID);
	
	OTAssetContract * LoadAssetContract(const OTIdentifier & ASSET_ID);
	OTServerContract * LoadServerContract(const OTIdentifier & SERVER_ID);
	
	// ----------------------------------------------------
		
	bool IsBasketCurrency(const OTIdentifier & BASKET_ASSET_TYPE_ID);

	long GetBasketMinimumTransferAmount(const OTIdentifier & BASKET_ASSET_TYPE_ID);

	int GetBasketMemberCount(const OTIdentifier & BASKET_ASSET_TYPE_ID);

	bool GetBasketMemberType(const OTIdentifier & BASKET_ASSET_TYPE_ID,
							 const int nIndex,
							 OTIdentifier & theOutputMemberType);
	
	long GetBasketMemberMinimumTransferAmount(const OTIdentifier & BASKET_ASSET_TYPE_ID,
											  const int nIndex);

	// ----------------------------------------------------

	OTAccount * LoadAssetAccount(const OTIdentifier & SERVER_ID,
								 const OTIdentifier & USER_ID,
								 const OTIdentifier & ACCOUNT_ID);
	
	// ----------------------------------------------------
	OTLedger * LoadNymbox(const OTIdentifier & SERVER_ID,
						  const OTIdentifier & USER_ID);

	OTLedger * LoadNymboxNoVerify(const OTIdentifier & SERVER_ID,
								  const OTIdentifier & USER_ID);
		
	OTLedger * LoadInbox(const OTIdentifier & SERVER_ID,
						 const OTIdentifier & USER_ID,
						 const OTIdentifier & ACCOUNT_ID);
	
	OTLedger * LoadInboxNoVerify(const OTIdentifier & SERVER_ID,
								 const OTIdentifier & USER_ID,
								 const OTIdentifier & ACCOUNT_ID);
	
	OTLedger * LoadOutbox(const OTIdentifier & SERVER_ID,
						  const OTIdentifier & USER_ID,
						  const OTIdentifier & ACCOUNT_ID);

	OTLedger * LoadOutboxNoVerify(const OTIdentifier & SERVER_ID,
								  const OTIdentifier & USER_ID,
								  const OTIdentifier & ACCOUNT_ID);
	// ----------------------------------------------------
	
	// So the client side knows which ones he has in storage, vs which ones he
	// still needs to download.
	//
	bool DoesBoxReceiptExist(const OTIdentifier & SERVER_ID,
							 const OTIdentifier & USER_ID,	// Unused here for now, but still convention.
							 const OTIdentifier & ACCOUNT_ID,	// If for Nymbox (vs inbox/outbox) then pass USER_ID in this field also.
							 const int			nBoxType,	// 0/nymbox, 1/inbox, 2/outbox
							 const long		  &	lTransactionNum);
	
	// ------------------------------------------------------
	
	// YOU are responsible to delete the OTMessage object, once
	// you receive the pointer that comes back from this function.
	// (It also might return NULL, if there are none there.)
	//
	OTMessage *	PopMessageBuffer();
	
	void		FlushMessageBuffer();
	
	// ------------------------------------------------------

	bool ResyncNymWithServer(OTPseudonym & theNym, OTLedger & theNymbox, OTPseudonym & theMessageNym);

	// ****************************************************
	
	// These commands below send messages to the server:
	
	void checkServerID(OTIdentifier & SERVER_ID,
					   OTIdentifier & USER_ID);
	
	void createUserAccount(OTIdentifier & SERVER_ID,
						   OTIdentifier & USER_ID);
	void deleteUserAccount(OTIdentifier & SERVER_ID,
						   OTIdentifier & USER_ID);
	
	void checkUser(OTIdentifier & SERVER_ID,
				   OTIdentifier & USER_ID,
				   OTIdentifier & USER_ID_CHECK);
	
	void usageCredits(const OTIdentifier &	SERVER_ID,
					  const OTIdentifier &	USER_ID,
					  const OTIdentifier &	USER_ID_CHECK,
					  const long			lAdjustment=0);
	
	void getRequest(OTIdentifier & SERVER_ID,
					OTIdentifier & USER_ID);
	
	void sendUserMessage(OTIdentifier	& SERVER_ID,
						 OTIdentifier	& USER_ID,
						 OTIdentifier	& USER_ID_RECIPIENT,
						 OTASCIIArmor	& RECIPIENT_PUBKEY,
						 OTString		& THE_MESSAGE);
	
	void issueAssetType(OTIdentifier	&	SERVER_ID,
						OTIdentifier	&	USER_ID,
						OTString		&	THE_CONTRACT);
	
	void getContract(OTIdentifier & SERVER_ID,
					 OTIdentifier & USER_ID,
					 OTIdentifier & ASSET_ID);
	
	void getMint(OTIdentifier & SERVER_ID,
				 OTIdentifier & USER_ID,
				 OTIdentifier & ASSET_ID);
	
	void getBoxReceipt(const OTIdentifier & SERVER_ID,
					   const OTIdentifier & USER_ID,
					   const OTIdentifier & ACCOUNT_ID,	// If for Nymbox (vs inbox/outbox) then pass USER_ID in this field also.
					   const int	 nBoxType,		// 0/nymbox, 1/inbox, 2/outbox
					   const long	&lTransactionNum);
	
	// ----------------------------------------------------
	
	void queryAssetTypes(OTIdentifier & SERVER_ID,
						 OTIdentifier & USER_ID,
						 OTASCIIArmor & ENCODED_MAP);
	// ----------------------------------------------------
	
	void createAssetAccount(OTIdentifier & SERVER_ID,
							OTIdentifier & USER_ID,
							OTIdentifier & ASSET_ID);
	void deleteAssetAccount(OTIdentifier & SERVER_ID,
							OTIdentifier & USER_ID,
							OTIdentifier & ACCOUNT_ID);
	
	void getAccount(OTIdentifier & SERVER_ID,
					OTIdentifier & USER_ID,
					OTIdentifier & ACCT_ID);
	
	// ----------------------------------------------------
	
	OTBasket * GenerateBasketCreation(const OTIdentifier & USER_ID,
									  const long MINIMUM_TRANSFER); // Must be above zero. If <= 0, defaults to 10.
	
	bool AddBasketCreationItem(const OTIdentifier & USER_ID, // for signature.
							   OTBasket & theBasket, // created in above call.
							   const OTIdentifier & ASSET_TYPE_ID, // Adding an asset type to the new basket.
							   const long MINIMUM_TRANSFER); // The amount of the asset type that is in the basket.
	
	void issueBasket(OTIdentifier	& SERVER_ID,
					 OTIdentifier	& USER_ID,
					 OTString		& BASKET_INFO);
	
	// ----------------------------------------------------

	OTBasket * GenerateBasketExchange(const OTIdentifier & SERVER_ID,
									  const OTIdentifier & USER_ID,
									  const OTIdentifier & BASKET_ASSET_TYPE_ID,
									  const OTIdentifier & BASKET_ASSET_ACCT_ID,
									  const int TRANSFER_MULTIPLE);	// 1			2			 3
																	// 5=2,3,4  OR  10=4,6,8  OR 15=6,9,12
	
	bool AddBasketExchangeItem(const OTIdentifier & SERVER_ID,
							   const OTIdentifier & USER_ID,
							   OTBasket & theBasket, 
							   const OTIdentifier & ASSET_TYPE_ID,
							   const OTIdentifier & ASSET_ACCT_ID);
	
	void exchangeBasket(OTIdentifier	& SERVER_ID,
						OTIdentifier	& USER_ID,
						OTIdentifier	& BASKET_ASSET_ID,
						OTString		& BASKET_INFO,
						const bool bExchangeInOrOut);
	
	// ----------------------------------------------------

	void getTransactionNumber(OTIdentifier & SERVER_ID,
							  OTIdentifier & USER_ID);
	
	void notarizeWithdrawal(OTIdentifier	& SERVER_ID,
							OTIdentifier	& USER_ID,
							OTIdentifier	& ACCT_ID,
							OTString		& AMOUNT);
	
	void notarizeDeposit(OTIdentifier	& SERVER_ID,
						 OTIdentifier	& USER_ID,
						 OTIdentifier	& ACCT_ID,
						 OTString		& THE_PURSE);
	
	void notarizeTransfer(OTIdentifier	& SERVER_ID,
						  OTIdentifier	& USER_ID,
						  OTIdentifier	& ACCT_FROM,
						  OTIdentifier	& ACCT_TO,
						  OTString		& AMOUNT,
						  OTString		& NOTE);
	
	void getNymbox(OTIdentifier & SERVER_ID,
				  OTIdentifier & USER_ID);
	
	void getInbox(OTIdentifier & SERVER_ID,
				  OTIdentifier & USER_ID,
				  OTIdentifier & ACCT_ID);
	
	void getOutbox(OTIdentifier & SERVER_ID,
				   OTIdentifier & USER_ID,
				   OTIdentifier & ACCT_ID);
	
	// Returns:
	// -1 if error.
	//  0 if Nymbox is empty.
	//  1 or more: Count of items in Nymbox before processing.
	//	
	int processNymbox(OTIdentifier	& SERVER_ID,
					  OTIdentifier	& USER_ID);
	
	void processInbox(OTIdentifier	& SERVER_ID,
					  OTIdentifier	& USER_ID,
					  OTIdentifier	& ACCT_ID,
					  OTString		& ACCT_LEDGER);
	
	void withdrawVoucher(OTIdentifier	& SERVER_ID,
						 OTIdentifier	& USER_ID,
						 OTIdentifier	& ACCT_ID,
						 OTIdentifier	& RECIPIENT_USER_ID,
						 OTString		& CHEQUE_MEMO,
						 OTString		& AMOUNT);
	
	void depositCheque(OTIdentifier	& SERVER_ID,
					   OTIdentifier	& USER_ID,
					   OTIdentifier	& ACCT_ID,
					   OTString		& THE_CHEQUE);
	
	void triggerClause(const OTIdentifier	& SERVER_ID,
					   const OTIdentifier	& USER_ID,
					   const long			& lTransactionNum,
					   const OTString		& strClauseName,
					   const OTString		* pStrParam=NULL);
	
	bool Create_SmartContract(const OTIdentifier & SERVER_ID,
							  const OTIdentifier & SIGNER_NYM_ID,// Use any Nym you wish here. (The signing at this point is only to cause a save.)
							  // ----------------------------------------
							  time_t		VALID_FROM,	// Default (0 or NULL) == NOW
							  time_t		VALID_TO,	// Default (0 or NULL) == no expiry / cancel anytime
							  OTString & strOutput);
	
	bool SmartContract_AddBylaw(const	OTString		& THE_CONTRACT,	// The contract, about to have the bylaw added to it.
								const	OTIdentifier	& SIGNER_NYM_ID,// Use any Nym you wish here. (The signing at this point is only to cause a save.)
								// ----------------------------------------
								const	OTString		& BYLAW_NAME,	// The Bylaw's NAME as referenced in the smart contract. (And the scripts...)
										OTString		& strOutput);
	
	bool SmartContract_AddClause(const	OTString		& THE_CONTRACT,	// The contract, about to have the clause added to it.
								 const	OTIdentifier	& SIGNER_NYM_ID,	// Use any Nym you wish here. (The signing at this point is only to cause a save.)
								 // ----------------------------------------
								 const	OTString		& BYLAW_NAME,	// Should already be on the contract. (This way we can find it.)
								 // ----------------------------------------
								 const	OTString		& CLAUSE_NAME,	// The Clause's name as referenced in the smart contract. (And the scripts...)
								 const	OTString		& SOURCE_CODE,	// The actual source code for the clause.
										OTString		& strOutput);
	
	bool SmartContract_AddVariable(const	OTString		& THE_CONTRACT,	 // The contract, about to have the clause added to it.
								   const	OTIdentifier	& SIGNER_NYM_ID, // Use any Nym you wish here. (The signing at this point is only to cause a save.)
								   // ----------------------------------------
								   const	OTString		& BYLAW_NAME,	// Should already be on the contract. (This way we can find it.)
								   // ----------------------------------------
								   const	OTString		& VAR_NAME,		// The Variable's name as referenced in the smart contract. (And the scripts...)
								   const	OTString		& VAR_ACCESS,	// "constant", "persistent", or "important".
								   const	OTString		& VAR_TYPE,		// "string", "long", or "bool"
								   const	OTString		& VAR_VALUE,	// Contains a string. If type is long, atol() will be used to convert value to a long. If type is bool, the strings "true" or "false" are expected here in order to convert to a bool.
								   // ----------------------------------------
											OTString		& strOutput);
	
	bool SmartContract_AddCallback(const	OTString		& THE_CONTRACT,	// The contract, about to have the clause added to it.
								   const	OTIdentifier	& SIGNER_NYM_ID,	// Use any Nym you wish here. (The signing at this point is only to cause a save.)
								   // ----------------------------------------
								   const	OTString		& BYLAW_NAME,	// Should already be on the contract. (This way we can find it.)
								   // ----------------------------------------
								   const	OTString		& CALLBACK_NAME,// The Callback's name as referenced in the smart contract. (And the scripts...)
								   const	OTString		& CLAUSE_NAME,	// The actual clause that will be triggered by the callback. (Must exist.)
											OTString		& strOutput);
	
	bool SmartContract_AddHook(const	OTString		& THE_CONTRACT,		// The contract, about to have the clause added to it.
							   const	OTIdentifier	& SIGNER_NYM_ID,	// Use any Nym you wish here. (The signing at this point is only to cause a save.)
							   // ----------------------------------------
							   const	OTString		& BYLAW_NAME,		// Should already be on the contract. (This way we can find it.)
							   // ----------------------------------------
							   const	OTString		& HOOK_NAME,		// The Hook's name as referenced in the smart contract. (And the scripts...)
							   const	OTString		& CLAUSE_NAME,		// The actual clause that will be triggered by the hook. (You can call this multiple times, and have multiple clauses trigger on the same hook.)
										OTString		& strOutput);
	
	bool SmartContract_AddParty(const	OTString		& THE_CONTRACT,		// The contract, about to have the bylaw added to it.
								const	OTIdentifier	& SIGNER_NYM_ID,	// Use any Nym you wish here. (The signing at this point is only to cause a save.)
								// ----------------------------------------
								const	OTString		& PARTY_NAME,		// The Party's NAME as referenced in the smart contract. (And the scripts...)
								const	OTString		& AGENT_NAME,		// An AGENT will be added by default for this party. Need Agent NAME.
										OTString		& strOutput);

	bool SmartContract_AddAccount(const	OTString		& THE_CONTRACT,		// The contract, about to have the clause added to it.
								  const	OTIdentifier	& SIGNER_NYM_ID,	// Use any Nym you wish here. (The signing at this point is only to cause a save.)
								  // ----------------------------------------
								  const	OTString		& PARTY_NAME,		// The Party's NAME as referenced in the smart contract. (And the scripts...)
								  // ----------------------------------------
								  const	OTString		& ACCT_NAME,		// The Account's name as referenced in the smart contract
								  const	OTString		& ASSET_TYPE_ID,	// Asset Type ID for the Account.
										OTString		& strOutput);
	
	int SmartContract_CountNumsNeeded(const	OTString	& THE_CONTRACT,		// The contract, about to have the bylaw added to it.
									  const	OTString	& AGENT_NAME);		// An AGENT will be added by default for this party. Need Agent NAME.

	bool SmartContract_ConfirmAccount(const	OTString	& THE_CONTRACT,	
									  const	OTIdentifier& SIGNER_NYM_ID,
									  // -----------------------------
									  const	OTString	& PARTY_NAME,	
									  const	OTString	& ACCT_NAME,	
									  // -----------------------------
									  const	OTString	& AGENT_NAME,
									  const	OTString	& ACCT_ID,
											OTString	& strOutput);
	
	bool SmartContract_ConfirmParty(const	OTString		& THE_CONTRACT,	// The smart contract, about to be changed by this function.
									const	OTString		& PARTY_NAME,	// Should already be on the contract. This way we can find it.
									// ----------------------------------------
									const	OTIdentifier	& NYM_ID,		// Nym ID for the party, the actual owner, 
											OTString		& strOutput);	// ===> AS WELL AS for the default AGENT of that party. (For now, until I code entities)
	
	bool HarvestClosingNumbers(const OTIdentifier	& SERVER_ID,
							   const OTIdentifier	& NYM_ID,
							   const OTString		& THE_CRON_ITEM);
	
	bool HarvestAllNumbers(const OTIdentifier	& SERVER_ID,
						   const OTIdentifier	& NYM_ID,
						   const OTString		& THE_CRON_ITEM);
	
	void activateSmartContract(const OTIdentifier	& SERVER_ID,
							   const OTIdentifier	& USER_ID,
							   const OTString		& THE_SMART_CONTRACT);
	
	void depositPaymentPlan(const OTIdentifier	& SERVER_ID,
							const OTIdentifier	& USER_ID,
							const OTString		& THE_PAYMENT_PLAN);
	
	void issueMarketOffer(const OTIdentifier	& SERVER_ID,
						  const OTIdentifier	& USER_ID,
						  // -------------------------------------------
						  const OTIdentifier	& ASSET_TYPE_ID,
						  const OTIdentifier	& ASSET_ACCT_ID,
						  // -------------------------------------------
						  const OTIdentifier	& CURRENCY_TYPE_ID,
						  const OTIdentifier	& CURRENCY_ACCT_ID,
						  // -------------------------------------------
						  const long			& MARKET_SCALE,	// Defaults to minimum of 1. Market granularity.
						  const long			& MINIMUM_INCREMENT,	// This will be multiplied by the Scale. Min 1.
						  const long			& TOTAL_ASSETS_ON_OFFER, // Total assets available for sale or purchase. Will be multiplied by minimum increment.
						  const long			& PRICE_LIMIT,		// Per Minimum Increment...
						  const bool			bBuyingOrSelling);	//  BUYING == false, SELLING == true.
	
	void getMarketList(const OTIdentifier & SERVER_ID, const OTIdentifier & USER_ID);
	void getMarketOffers(const OTIdentifier & SERVER_ID, const OTIdentifier & USER_ID, 
						 const OTIdentifier & MARKET_ID, const long & lDepth);
	void getMarketRecentTrades(const OTIdentifier & SERVER_ID, const OTIdentifier & USER_ID, 
							   const OTIdentifier & MARKET_ID);
	void getNym_MarketOffers(const OTIdentifier & SERVER_ID, const OTIdentifier & USER_ID);
    

    // For cancelling market offers and payment plans.
    //
	void cancelCronItem(const OTIdentifier & SERVER_ID, const OTIdentifier & USER_ID, 
                                const OTIdentifier & ASSET_ACCT_ID, 
                                const long & lTransactionNum);
    
    void getOffer_Trades(const OTIdentifier & SERVER_ID, const OTIdentifier & USER_ID, const long & lTransactionNum);

};
		


#endif // __OPEN_TRANSACTIONS_INTERFACE_H__
