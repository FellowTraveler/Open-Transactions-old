// otapicli.h

#pragma once

using namespace System;

namespace otapicli {

	public ref class otapi_wrap
	{
	public :

		otapi_wrap();
		~otapi_wrap();


		Int64	 __clrcall StringToLong(String ^% strNumber);
		String ^ __clrcall LongToString(Int64 % lNumber);

		Boolean	 __clrcall Init();
		Boolean	 __clrcall SetWallet(String ^% strWalletFilename);
		Boolean	 __clrcall WalletExists();
		Boolean	 __clrcall LoadWallet();
		Boolean	 __clrcall SwitchWallet();
		void	 __clrcall Output(Int32 % nLogLevel, String ^% strOutput);
		Int64	 __clrcall GetTime();
		String ^ __clrcall NumList_Add (String ^% strNumList, String ^% strNumbers);
		String ^ __clrcall NumList_Remove (String ^% strNumList, String ^% strNumbers);
		Boolean	 __clrcall NumList_VerifyQuery(String ^% strNumList, String ^% strNumbers);
		Boolean	 __clrcall NumList_VerifyAll (String ^% strNumList, String ^% strNumbers);
		Int32	 __clrcall NumList_Count (String ^% strNumList);
		String ^ __clrcall Encode(String ^% strPlaintext, Boolean % bLineBreaks);
		String ^ __clrcall Decode(String ^% strEncoded, Boolean % bLineBreaks);
		String ^ __clrcall Encrypt(String ^% RECIPIENT_NYM_ID, String ^% strPlaintext);
		String ^ __clrcall Decrypt(String ^% RECIPIENT_NYM_ID, String ^% strCiphertext);
		String ^ __clrcall CreateSymmetricKey();
		String ^ __clrcall SymmetricEncrypt(String ^% SYMMETRIC_KEY, String ^% PLAintEXT);
		String ^ __clrcall SymmetricDecrypt(String ^% SYMMETRIC_KEY, String ^% CIPHERTEXT_ENVELOPE);
		String ^ __clrcall SignContract(String ^% SIGNER_NYM_ID, String ^% THE_CONTRACT);
		String ^ __clrcall FlatSign(String ^% SIGNER_NYM_ID, String ^% THE_INPUT, String ^% CONTRACT_TYPE);
		String ^ __clrcall AddSignature(String ^% SIGNER_NYM_ID, String ^% THE_CONTRACT);
		Boolean	 __clrcall VerifySignature(String ^% SIGNER_NYM_ID, String ^% THE_CONTRACT);
		String ^ __clrcall VerifyAndRetrieveXMLContents(String ^% THE_CONTRACT, String ^% SIGNER_ID);
		Int32	 __clrcall GetMemlogSize();
		String ^ __clrcall GetMemlogAtIndex(Int32 % nIndex);
		String ^ __clrcall PeekMemlogFront();
		String ^ __clrcall PeekMemlogBack();
		Boolean	 __clrcall PopMemlogFront();
		Boolean	 __clrcall PopMemlogBack();
		String ^ __clrcall CreateNym(Int32 % nKeySize, String ^% NYM_ID_SOURCE, String ^% ALT_LOCATION);
		String ^ __clrcall CreateServerContract(String ^% NYM_ID, String ^% strXMLcontents );
		String ^ __clrcall CreateAssetContract (String ^% NYM_ID, String ^% strXMLcontents );
		Int32	 __clrcall AddServerContract(String ^% strContract);
		Int32	 __clrcall AddAssetContract(String ^% strContract);
		Int32	 __clrcall GetServerCount();
		Int32	 __clrcall GetAssetTypeCount();
		Int32	 __clrcall GetAccountCount();
		Int32	 __clrcall GetNymCount();
		String ^ __clrcall GetServer_ID(Int32 % nIndex);
		String ^ __clrcall GetServer_Name(String ^% SERVER_ID);
		String ^ __clrcall GetServer_Contract(String ^% SERVER_ID);
		String ^ __clrcall GetAssetType_ID(Int32 % nIndex);
		String ^ __clrcall GetAssetType_Name(String ^% ASSET_TYPE_ID);
		String ^ __clrcall GetAssetType_Contract(String ^% ASSET_TYPE_ID);
		String ^ __clrcall GetAccountWallet_ID(Int32 % nIndex);
		String ^ __clrcall GetAccountWallet_Name(String ^% ACCOUNT_ID);
		Int64 __clrcall GetAccountWallet_Balance(String ^% ACCOUNT_ID);
		String ^ __clrcall GetAccountWallet_Type(String ^% ACCOUNT_ID);
		String ^ __clrcall GetAccountWallet_AssetTypeID(String ^% ACCOUNT_ID);
		String ^ __clrcall GetAccountWallet_ServerID(String ^% ACCOUNT_ID);
		String ^ __clrcall GetAccountWallet_NymID(String ^% ACCOUNT_ID);
		String ^ __clrcall GetAccountWallet_InboxHash (String ^% ACCOUNT_ID);
		String ^ __clrcall GetAccountWallet_OutboxHash(String ^% ACCOUNT_ID);
		Boolean	 __clrcall VerifyAccountReceipt(String ^% SERVER_ID, String ^% NYM_ID, String ^% ACCT_ID);
		Int32	 __clrcall GetNym_TransactionNumCount(String ^% SERVER_ID, String ^% NYM_ID);
		String ^ __clrcall GetNym_ID(Int32 % nIndex);
		String ^ __clrcall GetNym_Name(String ^% NYM_ID);
		String ^ __clrcall GetNym_Stats(String ^% NYM_ID);
		String ^ __clrcall GetNym_NymboxHash(String ^% SERVER_ID, String ^% NYM_ID);
		String ^ __clrcall GetNym_RecentHash(String ^% SERVER_ID, String ^% NYM_ID);
		String ^ __clrcall GetNym_InboxHash(String ^% ACCOUNT_ID, String ^% NYM_ID);
		String ^ __clrcall GetNym_OutboxHash(String ^% ACCOUNT_ID, String ^% NYM_ID);
		Boolean	 __clrcall IsNym_RegisteredAtServer(String ^% NYM_ID, String ^% SERVER_ID);
		Int32	 __clrcall GetNym_MailCount(String ^% NYM_ID);
		String ^ __clrcall GetNym_MailContentsByIndex(String ^% NYM_ID, Int32 % nIndex);
		String ^ __clrcall GetNym_MailSenderIDByIndex(String ^% NYM_ID, Int32 % nIndex);
		String ^ __clrcall GetNym_MailServerIDByIndex(String ^% NYM_ID, Int32 % nIndex);
		Boolean	 __clrcall Nym_RemoveMailByIndex(String ^% NYM_ID, Int32 % nIndex);
		Boolean	 __clrcall Nym_VerifyMailByIndex(String ^% NYM_ID, Int32 % nIndex);
		Int32	 __clrcall GetNym_OutmailCount(String ^% NYM_ID);
		String ^ __clrcall GetNym_OutmailContentsByIndex(String ^% NYM_ID, Int32 % nIndex);
		String ^ __clrcall GetNym_OutmailRecipientIDByIndex(String ^% NYM_ID, Int32 % nIndex);
		String ^ __clrcall GetNym_OutmailServerIDByIndex(String ^% NYM_ID, Int32 % nIndex);
		Boolean	 __clrcall Nym_RemoveOutmailByIndex(String ^% NYM_ID, Int32 % nIndex);
		Boolean	 __clrcall Nym_VerifyOutmailByIndex(String ^% NYM_ID, Int32 % nIndex);
		Int32	 __clrcall GetNym_OutpaymentsCount(String ^% NYM_ID);
		String ^ __clrcall GetNym_OutpaymentsContentsByIndex(String ^% NYM_ID, Int32 % nIndex);
		String ^ __clrcall GetNym_OutpaymentsRecipientIDByIndex(String ^% NYM_ID, Int32 % nIndex);
		String ^ __clrcall GetNym_OutpaymentsServerIDByIndex(String ^% NYM_ID, Int32 % nIndex);
		Boolean	 __clrcall Nym_RemoveOutpaymentsByIndex(String ^% NYM_ID, Int32 % nIndex);
		Boolean	 __clrcall Nym_VerifyOutpaymentsByIndex(String ^% NYM_ID, Int32 % nIndex);
		Boolean	 __clrcall Wallet_CanRemoveServer(String ^% SERVER_ID);
		Boolean	 __clrcall Wallet_RemoveServer(String ^% SERVER_ID);
		Boolean	 __clrcall Wallet_CanRemoveAssetType(String ^% ASSET_ID);
		Boolean	 __clrcall Wallet_RemoveAssetType(String ^% ASSET_ID);
		Boolean	 __clrcall Wallet_CanRemoveNym(String ^% NYM_ID);
		Boolean	 __clrcall Wallet_RemoveNym(String ^% NYM_ID);
		Boolean	 __clrcall Wallet_CanRemoveAccount(String ^% ACCOUNT_ID);
		Boolean	 __clrcall Wallet_ChangePassphrase();
		String ^ __clrcall Wallet_ExportNym(String ^% NYM_ID);
		String ^ __clrcall Wallet_ImportNym(String ^% FILE_CONTENTS);
		String ^ __clrcall Wallet_ImportCert(String ^% DISPLAY_NAME, String ^% FILE_CONTENTS);
		String ^ __clrcall Wallet_ExportCert(String ^% NYM_ID);
		String ^ __clrcall Wallet_GetNymIDFromPartial (String ^% PARTIAL_ID);
		String ^ __clrcall Wallet_GetServerIDFromPartial (String ^% PARTIAL_ID);
		String ^ __clrcall Wallet_GetAssetIDFromPartial (String ^% PARTIAL_ID);
		String ^ __clrcall Wallet_GetAccountIDFromPartial(String ^% PARTIAL_ID);

		Boolean	 __clrcall SetNym_Name(
			String ^% NYM_ID, 
			String ^% SIGNER_NYM_ID, 
			String ^% NYM_NEW_NAME
			);

		Boolean	 __clrcall SetAccountWallet_Name(
			String ^% ACCT_ID, 
			String ^% SIGNER_NYM_ID, 
			String ^% ACCT_NEW_NAME
			);

		Boolean	 __clrcall SetAssetType_Name(
			String ^% ASSET_ID, 
			String ^% STR_NEW_NAME
			);

		Boolean	 __clrcall SetServer_Name(
			String ^% SERVER_ID, 
			String ^% STR_NEW_NAME
			); 

		String ^ __clrcall WriteCheque(
			String ^% SERVER_ID,
			Int64 % CHEQUE_AMOUNT, 
			DateTime % VALID_FROM, 
			DateTime % VALID_TO,
			String ^% SENDER_ACCT_ID,
			String ^% SENDER_USER_ID,
			String ^% CHEQUE_MEMO, 
			String ^% RECIPIENT_USER_ID
			);

		Boolean	 __clrcall DiscardCheque(
			String ^% SERVER_ID,
			String ^% USER_ID,
			String ^% ACCT_ID,
			String ^% THE_CHEQUE
			);

		String ^ __clrcall ProposePaymentPlan(
			String ^% SERVER_ID,
			DateTime % VALID_FROM,
			DateTime % VALID_TO,
			String ^% SENDER_ACCT_ID,
			String ^% SENDER_USER_ID,
			String ^% PLAN_CONSIDERATION,
			String ^% RECIPIENT_ACCT_ID,
			String ^% RECIPIENT_USER_ID,
			Int64 % INITIAL_PAYMENT_AMOUNT,
			TimeSpan % INITIAL_PAYMENT_DELAY,
			Int64 % PAYMENT_PLAN_AMOUNT,
			TimeSpan % PAYMENT_PLAN_DELAY,
			TimeSpan % PAYMENT_PLAN_PERIOD,
			Int64 % PAYMENT_PLAN_LENGTH,
			Int32 % PAYMENT_PLAN_MAX_PAYMENTS
			);	

		String ^ __clrcall ConfirmPaymentPlan(
			String ^% SERVER_ID,
			String ^% SENDER_USER_ID,
			String ^% SENDER_ACCT_ID,
			String ^% RECIPIENT_USER_ID,
			String ^% PAYMENT_PLAN
			);

		String ^ __clrcall Create_SmartContract(
			String ^% SERVER_ID,
			String ^% SIGNER_NYM_ID,
			DateTime % VALID_FROM,
			DateTime % VALID_TO
			);

		String ^ __clrcall SmartContract_AddBylaw(
			String ^% THE_CONTRACT,
			String ^% SIGNER_NYM_ID,
			String ^% BYLAW_NAME
			);


		String ^ __clrcall SmartContract_AddClause(
			String ^% THE_CONTRACT,
			String ^% SIGNER_NYM_ID,
			String ^% BYLAW_NAME,
			String ^% CLAUSE_NAME,
			String ^% SOURCE_CODE
			);

		String ^ __clrcall SmartContract_AddVariable(
			String ^% THE_CONTRACT,
			String ^% SIGNER_NYM_ID,
			String ^% BYLAW_NAME,
			String ^% VAR_NAME,
			String ^% VAR_ACCESS,
			String ^% VAR_TYPE,
			String ^% VAR_VALUE
			);

		String ^ __clrcall SmartContract_AddCallback(
			String ^% THE_CONTRACT,
			String ^% SIGNER_NYM_ID,
			String ^% BYLAW_NAME,
			String ^% CALLBACK_NAME,
			String ^% CLAUSE_NAME
			);

		String ^ __clrcall SmartContract_AddHook(
			String ^% THE_CONTRACT,
			String ^% SIGNER_NYM_ID,
			String ^% BYLAW_NAME,
			String ^% HOOK_NAME,
			String ^% CLAUSE_NAME
			);

		String ^ __clrcall SmartContract_AddParty(
			String ^% THE_CONTRACT,
			String ^% SIGNER_NYM_ID,
			String ^% PARTY_NAME,
			String ^% AGENT_NAME
			);

		String ^ __clrcall SmartContract_AddAccount(
			String ^% THE_CONTRACT,
			String ^% SIGNER_NYM_ID,
			String ^% PARTY_NAME,
			String ^% ACCT_NAME,
			String ^% ASSET_TYPE_ID
			);

		Int32	 __clrcall SmartContract_CountNumsNeeded(
			String ^% THE_CONTRACT,
			String ^% AGENT_NAME
			);

		String ^ __clrcall SmartContract_ConfirmAccount(
			String ^% THE_CONTRACT,
			String ^% SIGNER_NYM_ID,
			String ^% PARTY_NAME,
			String ^% ACCT_NAME,
			String ^% AGENT_NAME,
			String ^% ACCT_ID
			);

		String ^ __clrcall SmartContract_ConfirmParty(
			String ^% THE_CONTRACT,
			String ^% PARTY_NAME,
			String ^% NYM_ID
			);

		Int32	 __clrcall activateSmartContract(
			String ^% SERVER_ID,
			String ^% USER_ID,
			String ^% THE_SMART_CONTRACT
			);

		Int32	 __clrcall triggerClause(
			String ^% SERVER_ID,
			String ^% USER_ID,
			Int64 % TRANSACTION_NUMBER,
			String ^% CLAUSE_NAME,
			String ^% STR_PARAM
			);

		Boolean	 __clrcall Msg_HarvestTransactionNumbers(
			String ^% THE_MESSAGE,
			String ^% USER_ID,
			Boolean % bHarvestingForRetry,
			Boolean % bReplyWasSuccess,
			Boolean % bReplyWasFailure,
			Boolean % bTransactionWasSuccess,
			Boolean % bTransactionWasFailure
			);

		String ^ __clrcall LoadUserPubkey_Encryption(String ^% USER_ID);
		String ^ __clrcall LoadUserPubkey_Signing(String ^% USER_ID);
		String ^ __clrcall LoadPubkey_Encryption(String ^% USER_ID);
		String ^ __clrcall LoadPubkey_Signing(String ^% USER_ID);
		Boolean	 __clrcall VerifyUserPrivateKey(String ^% USER_ID);


		String ^ __clrcall LoadPurse(
			String ^% SERVER_ID,
			String ^% ASSET_TYPE_ID,
			String ^% USER_ID
			);

		String ^ __clrcall LoadMint(
			String ^% SERVER_ID,
			String ^% ASSET_TYPE_ID
			);

		String ^ __clrcall LoadAssetContract(String ^% ASSET_TYPE_ID);
		String ^ __clrcall LoadServerContract(String ^% SERVER_ID);

		Boolean	 __clrcall Mint_IsStillGood(
			String ^% SERVER_ID,
			String ^% ASSET_TYPE_ID
			);

		Boolean	 __clrcall IsBasketCurrency(String ^% ASSET_TYPE_ID);
		Int32	 __clrcall Basket_GetMemberCount(String ^% BASKET_ASSET_TYPE_ID);

		String ^ __clrcall Basket_GetMemberType(
			String ^% BASKET_ASSET_TYPE_ID,
			Int32 % nIndex
			);

		Int64 __clrcall Basket_GetMinimumTransferAmount(String ^% BASKET_ASSET_TYPE_ID);

		Int64 __clrcall Basket_GetMemberMinimumTransferAmount(
			String ^% BASKET_ASSET_TYPE_ID,
			Int32 % nIndex
			);

		String ^ __clrcall LoadAssetAccount(
			String ^% SERVER_ID,
			String ^% USER_ID,
			String ^% ACCOUNT_ID
			);


		String ^ __clrcall LoadInbox(
			String ^% SERVER_ID,
			String ^% USER_ID,
			String ^% ACCOUNT_ID
			);

		String ^ __clrcall LoadOutbox(
			String ^% SERVER_ID,
			String ^% USER_ID,
			String ^% ACCOUNT_ID
			);

		String ^ __clrcall LoadInboxNoVerify(
			String ^% SERVER_ID,
			String ^% USER_ID,
			String ^% ACCOUNT_ID
			);

		String ^ __clrcall LoadOutboxNoVerify(
			String ^% SERVER_ID,
			String ^% USER_ID,
			String ^% ACCOUNT_ID
			);

		String ^ __clrcall LoadPaymentInbox(
			String ^% SERVER_ID,
			String ^% USER_ID
			);

		String ^ __clrcall LoadPaymentInboxNoVerify(
			String ^% SERVER_ID,
			String ^% USER_ID
			);

		String ^ __clrcall LoadRecordBox(
			String ^% SERVER_ID,
			String ^% USER_ID,
			String ^% ACCOUNT_ID
			);

		String ^ __clrcall LoadRecordBoxNoVerify(
			String ^% SERVER_ID,
			String ^% USER_ID,
			String ^% ACCOUNT_ID
			);

		Boolean __clrcall ClearRecord(
            String ^% SERVER_ID,
            String ^% USER_ID,
            String ^% ACCOUNT_ID,
            Int32 % nIndex,
            Boolean % bClearAll
            );

		Boolean __clrcall RecordPayment(
            String ^% SERVER_ID,
            String ^% USER_ID,
            Boolean % bIsInbox,
            Int32 % nIndex            
            );

		Int32	 __clrcall Ledger_GetCount(
			String ^% SERVER_ID,
			String ^% USER_ID,
			String ^% ACCOUNT_ID,
			String ^% THE_LEDGER
			);

		String ^ __clrcall Ledger_CreateResponse(
			String ^% SERVER_ID,
			String ^% USER_ID,
			String ^% ACCOUNT_ID,
			String ^% ORIGINAL_LEDGER
			);

		String ^ __clrcall Ledger_GetTransactionByIndex(
			String ^% SERVER_ID,
			String ^% USER_ID,
			String ^% ACCOUNT_ID,
			String ^% THE_LEDGER,
			Int32 % nIndex
			);

		String ^ __clrcall Ledger_GetTransactionByID(
			String ^% SERVER_ID,
			String ^% USER_ID,
			String ^% ACCOUNT_ID,
			String ^% THE_LEDGER,
			Int64 % TRANSACTION_NUMBER
			);

		Int64 __clrcall Ledger_GetTransactionIDByIndex(
			String ^% SERVER_ID,
			String ^% USER_ID,
			String ^% ACCOUNT_ID,
			String ^% THE_LEDGER,
			Int32 % nIndex
			);

		String ^ __clrcall Ledger_AddTransaction(
			String ^% SERVER_ID,
			String ^% USER_ID,
			String ^% ACCOUNT_ID,
			String ^% THE_LEDGER,
			String ^% THE_TRANSACTION
			);

		String ^ __clrcall Transaction_CreateResponse(
			String ^% SERVER_ID,
			String ^% USER_ID,
			String ^% ACCOUNT_ID,
			String ^% RESPONSE_LEDGER,
			String ^% ORIGINAL_TRANSACTION,
			Boolean % BOOL_DO_I_ACCEPT
			);

		String ^ __clrcall Ledger_FinalizeResponse(
			String ^% SERVER_ID,
			String ^% USER_ID,
			String ^% ACCOUNT_ID,
			String ^% THE_LEDGER
			);

		String ^ __clrcall Ledger_GetInstrument(
			String ^% SERVER_ID,
			String ^% USER_ID,
			String ^% ACCOUNT_ID,
			String ^% THE_LEDGER,
			Int32 % nIndex
			);

		String ^ __clrcall Transaction_GetType(
			String ^% SERVER_ID,
			String ^% USER_ID,
			String ^% ACCOUNT_ID,
			String ^% THE_TRANSACTION
			);

		Int64 __clrcall ReplyNotice_GetRequestNum(
			String ^% SERVER_ID,
			String ^% USER_ID,
			String ^% THE_TRANSACTION
			);

		String ^ __clrcall Transaction_GetVoucher(
			String ^% SERVER_ID,
			String ^% USER_ID,
			String ^% ACCOUNT_ID,
			String ^% THE_TRANSACTION
			);

		Boolean	 __clrcall Transaction_GetSuccess(
			String ^% SERVER_ID,
			String ^% USER_ID,
			String ^% ACCOUNT_ID,
			String ^% THE_TRANSACTION
			);

		Boolean	 __clrcall Transaction_GetBalanceAgreementSuccess(
			String ^% SERVER_ID,
			String ^% USER_ID,
			String ^% ACCOUNT_ID,
			String ^% THE_TRANSACTION
			);

		DateTime __clrcall Transaction_GetDateSigned(
			String ^% SERVER_ID,
			String ^% USER_ID,
			String ^% ACCOUNT_ID,
			String ^% THE_TRANSACTION
			); 

		Int64 __clrcall Transaction_GetAmount(
			String ^% SERVER_ID,
			String ^% USER_ID,
			String ^% ACCOUNT_ID,
			String ^% THE_TRANSACTION
			);

		String ^ __clrcall Pending_GetNote(
			String ^% SERVER_ID,
			String ^% USER_ID,
			String ^% ACCOUNT_ID,
			String ^% THE_TRANSACTION
			);

		String ^ __clrcall Transaction_GetSenderUserID(
			String ^% SERVER_ID,
			String ^% USER_ID,
			String ^% ACCOUNT_ID,
			String ^% THE_TRANSACTION
			);

		String ^ __clrcall Transaction_GetSenderAcctID(
			String ^% SERVER_ID,
			String ^% USER_ID,
			String ^% ACCOUNT_ID,
			String ^% THE_TRANSACTION
			);

		String ^ __clrcall Transaction_GetRecipientUserID(
			String ^% SERVER_ID,
			String ^% USER_ID,
			String ^% ACCOUNT_ID,
			String ^% THE_TRANSACTION
			);

		String ^ __clrcall Transaction_GetRecipientAcctID(
			String ^% SERVER_ID,
			String ^% USER_ID,
			String ^% ACCOUNT_ID,
			String ^% THE_TRANSACTION
			);

		Int64 __clrcall Transaction_GetDisplayReferenceToNum(
			String ^% SERVER_ID,
			String ^% USER_ID,
			String ^% ACCOUNT_ID,
			String ^% THE_TRANSACTION
			);

		Boolean	 __clrcall SavePurse(
			String ^% SERVER_ID,
			String ^% ASSET_TYPE_ID,
			String ^% USER_ID,
			String ^% THE_PURSE
			);

		String ^ __clrcall CreatePurse(
			String ^% SERVER_ID,
			String ^% ASSET_TYPE_ID,
			String ^% OWNER_ID,
			String ^% SIGNER_ID
			);

		String ^ __clrcall CreatePurse_Passphrase(
			String ^% SERVER_ID,
			String ^% ASSET_TYPE_ID,
			String ^% SIGNER_ID
			);

		Int64 __clrcall Purse_GetTotalValue(
			String ^% SERVER_ID,
			String ^% ASSET_TYPE_ID,
			String ^% THE_PURSE
			);

		Int32	 __clrcall Purse_Count(
			String ^% SERVER_ID,
			String ^% ASSET_TYPE_ID,
			String ^% THE_PURSE
			);

		Boolean	 __clrcall Purse_HasPassword(
			String ^% SERVER_ID,
			String ^% THE_PURSE
			);

		String ^ __clrcall Purse_Peek(
			String ^% SERVER_ID,
			String ^% ASSET_TYPE_ID,
			String ^% OWNER_ID,
			String ^% THE_PURSE
			);

		String ^ __clrcall Purse_Pop(
			String ^% SERVER_ID,
			String ^% ASSET_TYPE_ID,
			String ^% OWNER_OR_SIGNER_ID,
			String ^% THE_PURSE
			);

		String ^ __clrcall Purse_Push(
			String ^% SERVER_ID,
			String ^% ASSET_TYPE_ID,
			String ^% SIGNER_ID,
			String ^% OWNER_ID,
			String ^% THE_PURSE,
			String ^% THE_TOKEN
			);

		String ^ __clrcall Purse_Empty(
			String ^% SERVER_ID,
			String ^% ASSET_TYPE_ID,
			String ^% SIGNER_ID,
			String ^% THE_PURSE
			);

		Boolean	 __clrcall Wallet_ImportPurse(
			String ^% SERVER_ID,
			String ^% ASSET_TYPE_ID,
			String ^% USER_ID,
			String ^% THE_PURSE
			);

		Int32	 __clrcall exchangePurse(
			String ^% SERVER_ID,
			String ^% ASSET_TYPE_ID,
			String ^% USER_ID,
			String ^% THE_PURSE
			);

		String ^ __clrcall Token_ChangeOwner(
			String ^% SERVER_ID,
			String ^% ASSET_TYPE_ID,
			String ^% THE_TOKEN,
			String ^% SIGNER_NYM_ID,
			String ^% OLD_OWNER,
			String ^% NEW_OWNER
			);

		String ^ __clrcall Token_GetID(
			String ^% SERVER_ID,
			String ^% ASSET_TYPE_ID,
			String ^% THE_TOKEN
			);

		Int64 __clrcall Token_GetDenomination(
			String ^% SERVER_ID,
			String ^% ASSET_TYPE_ID,
			String ^% THE_TOKEN
			);

		Int32	 __clrcall Token_GetSeries(
			String ^% SERVER_ID,
			String ^% ASSET_TYPE_ID,
			String ^% THE_TOKEN
			);

		DateTime __clrcall Token_GetValidFrom(
			String ^% SERVER_ID,
			String ^% ASSET_TYPE_ID,
			String ^% THE_TOKEN
			);

		DateTime __clrcall Token_GetValidTo(
			String ^% SERVER_ID,
			String ^% ASSET_TYPE_ID,
			String ^% THE_TOKEN
			);

		String ^ __clrcall Token_GetAssetID(String ^% THE_TOKEN);
		String ^ __clrcall Token_GetServerID(String ^% THE_TOKEN);
		Int64  __clrcall Instrmnt_GetAmount (String ^% THE_INSTRUMENT);
		Int64  __clrcall Instrmnt_GetTransNum (String ^% THE_INSTRUMENT);
		DateTime __clrcall Instrmnt_GetValidFrom (String ^% THE_INSTRUMENT);
		DateTime __clrcall Instrmnt_GetValidTo (String ^% THE_INSTRUMENT);
		String ^ __clrcall Instrmnt_GetMemo (String ^% THE_INSTRUMENT);
		String ^ __clrcall Instrmnt_GetType (String ^% THE_INSTRUMENT);
		String ^ __clrcall Instrmnt_GetServerID (String ^% THE_INSTRUMENT);
		String ^ __clrcall Instrmnt_GetAssetID (String ^% THE_INSTRUMENT);
		String ^ __clrcall Instrmnt_GetSenderUserID (String ^% THE_INSTRUMENT);
		String ^ __clrcall Instrmnt_GetSenderAcctID (String ^% THE_INSTRUMENT);
		String ^ __clrcall Instrmnt_GetRecipientUserID(String ^% THE_INSTRUMENT);
		String ^ __clrcall Instrmnt_GetRecipientAcctID(String ^% THE_INSTRUMENT);
		Int32	 __clrcall checkServerID(String ^% SERVER_ID, String ^% USER_ID);

		Int32	 __clrcall createUserAccount(
			String ^% SERVER_ID,
			String ^% USER_ID
			);

		Int32	 __clrcall deleteUserAccount(
			String ^% SERVER_ID,
			String ^% USER_ID
			);

		Int32	 __clrcall deleteAssetAccount(
			String ^% SERVER_ID,
			String ^% USER_ID,
			String ^% ACCOUNT_ID
			);

		Int32	 __clrcall usageCredits(
			String ^% SERVER_ID,
			String ^% USER_ID,
			String ^% USER_ID_CHECK,
			Int64 % ADJUSTMENT
			);

		Int64 __clrcall Message_GetUsageCredits(String ^% THE_MESSAGE);

		Int32	 __clrcall checkUser(
			String ^% SERVER_ID,
			String ^% USER_ID,
			String ^% USER_ID_CHECK
			);

		Int32	 __clrcall sendUserMessage(
			String ^% SERVER_ID,
			String ^% USER_ID,
			String ^% USER_ID_RECIPIENT,
			String ^% RECIPIENT_PUBKEY,
			String ^% THE_MESSAGE
			);

		Int32	 __clrcall sendUserInstrument(
			String ^% SERVER_ID,
			String ^% USER_ID,
			String ^% USER_ID_RECIPIENT,
			String ^% RECIPIENT_PUBKEY,
			String ^% THE_INSTRUMENT,
            String ^% INSTRUMENT_FOR_SENDER
			);

		Int32	 __clrcall getRequest(
			String ^% SERVER_ID,
			String ^% USER_ID
			);

		Int32	 __clrcall getTransactionNumber(
			String ^% SERVER_ID,
			String ^% USER_ID
			);

		Int32	 __clrcall issueAssetType(
			String ^% SERVER_ID,
			String ^% USER_ID,
			String ^% THE_CONTRACT
			);

		Int32	 __clrcall getContract(
			String ^% SERVER_ID,
			String ^% USER_ID,
			String ^% ASSET_ID
			);

		Int32	 __clrcall getMint(
			String ^% SERVER_ID,
			String ^% USER_ID,
			String ^% ASSET_ID
			);

		Int32	 __clrcall createAssetAccount(
			String ^% SERVER_ID,
			String ^% USER_ID,
			String ^% ASSET_ID
			);

		Int32	 __clrcall getAccount(
			String ^% SERVER_ID,
			String ^% USER_ID,
			String ^% ACCT_ID
			);

		String ^ __clrcall GenerateBasketCreation(
			String ^% USER_ID,
			Int64 % MINIMUM_TRANSFER
			);

		String ^ __clrcall AddBasketCreationItem(
			String ^% USER_ID,
			String ^% THE_BASKET,
			String ^% ASSET_TYPE_ID,
			Int64 % MINIMUM_TRANSFER
			);

		Int32	 __clrcall issueBasket(
			String ^% SERVER_ID,
			String ^% USER_ID,
			String ^% THE_BASKET
			);

		String ^ __clrcall GenerateBasketExchange(
			String ^% SERVER_ID,
			String ^% USER_ID,
			String ^% BASKET_ASSET_TYPE_ID,
			String ^% BASKET_ASSET_ACCT_ID,
			Int32 % TRANSFER_MULTIPLE
			);

		String ^ __clrcall AddBasketExchangeItem(
			String ^% SERVER_ID,
			String ^% USER_ID,
			String ^% THE_BASKET, 
			String ^% ASSET_TYPE_ID,
			String ^% ASSET_ACCT_ID
			);

		Int32	 __clrcall exchangeBasket(
			String ^% SERVER_ID,
			String ^% USER_ID,
			String ^% BASKET_ASSET_ID,
			String ^% THE_BASKET,
			Boolean % BOOL_EXCHANGE_IN_OR_OUT
			);

		Int32	 __clrcall notarizeWithdrawal(
			String ^% SERVER_ID,
			String ^% USER_ID,
			String ^% ACCT_ID,
			Int64 % AMOUNT
			);

		Int32	 __clrcall notarizeDeposit(
			String ^% SERVER_ID,
			String ^% USER_ID,
			String ^% ACCT_ID,
			String ^% THE_PURSE
			);

		Int32	 __clrcall notarizeTransfer(
			String ^% SERVER_ID,
			String ^% USER_ID,
			String ^% ACCT_FROM,
			String ^% ACCT_TO,
			Int64 % AMOUNT,
			String ^% NOTE
			);

		Int32	 __clrcall getInbox(
			String ^% SERVER_ID,
			String ^% USER_ID,
			String ^% ACCT_ID
			);

		Int32	 __clrcall getOutbox(
			String ^% SERVER_ID,
			String ^% USER_ID,
			String ^% ACCT_ID
			);

		Int32	 __clrcall getNymbox(
			String ^% SERVER_ID,
			String ^% USER_ID
			);

		String ^ __clrcall LoadNymbox(
			String ^% SERVER_ID,
			String ^% USER_ID
			);

		String ^ __clrcall LoadNymboxNoVerify(
			String ^% SERVER_ID,
			String ^% USER_ID
			);

		String ^ __clrcall Nymbox_GetReplyNotice(
			String ^% SERVER_ID,
			String ^% USER_ID,
			Int64 % REQUEST_NUMBER
			);

		Boolean	 __clrcall HaveAlreadySeenReply(
			String ^% SERVER_ID,
			String ^% USER_ID,
			Int64 % REQUEST_NUMBER
			);

		Int32	 __clrcall getBoxReceipt(
			String ^% SERVER_ID,
			String ^% USER_ID,
			String ^% ACCOUNT_ID,
			Int32 % nBoxType,
			Int64 % TRANSACTION_NUMBER
			);

		Boolean	 __clrcall DoesBoxReceiptExist(
			String ^% SERVER_ID,
			String ^% USER_ID,
			String ^% ACCOUNT_ID,
			Int32 % nBoxType,
			Int64 % TRANSACTION_NUMBER
			);

		Int32	 __clrcall processInbox(
			String ^% SERVER_ID,
			String ^% USER_ID,
			String ^% ACCT_ID,
			String ^% ACCT_LEDGER
			);

		Int32	 __clrcall processNymbox(
			String ^% SERVER_ID,
			String ^% USER_ID
			);

		Int32	 __clrcall withdrawVoucher(
			String ^% SERVER_ID,
			String ^% USER_ID,
			String ^% ACCT_ID,
			String ^% RECIPIENT_USER_ID,
			String ^% CHEQUE_MEMO,
			Int64 % AMOUNT
			);

		Int32	 __clrcall payDividend(
			String ^% SERVER_ID,
			String ^% ISSUER_USER_ID,
			String ^% DIVIDEND_FROM_ACCT_ID,
			String ^% SHARES_ASSET_TYPE_ID,
			String ^% DIVIDEND_MEMO,
			Int64 % AMOUNT_PER_SHARE
			);

		Int32	 __clrcall depositCheque(
			String ^% SERVER_ID,
			String ^% USER_ID,
			String ^% ACCT_ID,
			String ^% THE_CHEQUE
			);

		Int32	 __clrcall depositPaymentPlan(
			String ^% SERVER_ID,
			String ^% USER_ID,
			String ^% THE_PAYMENT_PLAN
			);

		Int32	 __clrcall issueMarketOffer(
			String ^% SERVER_ID,
			String ^% USER_ID,
			String ^% ASSET_ACCT_ID,
			String ^% CURRENCY_ACCT_ID,
			Int64 % MARKET_SCALE,
			Int64 % MINIMUM_INCREMENT,
			Int64 % TOTAL_ASSETS_ON_OFFER,
			Int64 % PRICE_LIMIT,
			Boolean % bBuyingOrSelling,
			TimeSpan % LIFESPAN_IN_SECONDS
			);

		Int32	 __clrcall getMarketList(String ^% SERVER_ID, String ^% USER_ID);

		Int32	 __clrcall getMarketOffers(
			String ^% SERVER_ID,
			String ^% USER_ID, 
			String ^% MARKET_ID,
			Int64 % MAX_DEPTH
			);

		Int32	 __clrcall getMarketRecentTrades(
			String ^% SERVER_ID,
			String ^% USER_ID, 
			String ^% MARKET_ID
			);

		Int32	 __clrcall getNym_MarketOffers(String ^% SERVER_ID, String ^% USER_ID); // Offers this Nym has out on market.

		Int32	 __clrcall cancelMarketOffer(
			String ^% SERVER_ID, 
			String ^% USER_ID, 
			String ^% ASSET_ACCT_ID, 
			Int64 % TRANSACTION_NUMBER
			);

		Int32	 __clrcall cancelPaymentPlan(
			String ^% SERVER_ID, 
			String ^% USER_ID, 
			String ^% FROM_ACCT_ID, 
			Int64 % TRANSACTION_NUMBER
			);

		String ^ __clrcall PopMessageBuffer(
			Int64 % REQUEST_NUMBER,
			String ^% SERVER_ID, 
			String ^% USER_ID
			);

		void	 __clrcall FlushMessageBuffer();

		String ^ __clrcall GetSentMessage(
			Int64 % REQUEST_NUMBER,
			String ^% SERVER_ID, 
			String ^% USER_ID
			);

		Boolean	 __clrcall RemoveSentMessage(
			Int64 % REQUEST_NUMBER,
			String ^% SERVER_ID, 
			String ^% USER_ID
			);

		void	 __clrcall FlushSentMessages(
			Boolean % bHarvestingForRetry,
			String ^% SERVER_ID, 
			String ^% USER_ID,
			String ^% THE_NYMBOX
			); 

		void	 __clrcall Sleep(Int64 % MILLISECONDS);
		Boolean	 __clrcall ResyncNymWithServer(String ^% SERVER_ID, String ^% USER_ID, String ^% THE_MESSAGE);
		String ^ __clrcall Message_GetCommand(String ^% THE_MESSAGE);
		Int32	 __clrcall Message_GetSuccess(String ^% THE_MESSAGE);
		Int32	 __clrcall queryAssetTypes(String ^% SERVER_ID, String ^% USER_ID, String ^% ENCODED_MAP);
		String ^ __clrcall Message_GetPayload(String ^% THE_MESSAGE);
		Int32	 __clrcall Message_GetDepth(String ^% THE_MESSAGE);

		Int32	 __clrcall Message_GetTransactionSuccess(
			String ^% SERVER_ID,
			String ^% USER_ID,
			String ^% ACCOUNT_ID,
			String ^% THE_MESSAGE
			);

		Int32	 __clrcall Message_GetBalanceAgreementSuccess(
			String ^% SERVER_ID,
			String ^% USER_ID,
			String ^% ACCOUNT_ID,
			String ^% THE_MESSAGE
			);

		String ^ __clrcall Message_GetLedger(String ^% THE_MESSAGE);
		String ^ __clrcall Message_GetNewAssetTypeID(String ^% THE_MESSAGE);
		String ^ __clrcall Message_GetNewIssuerAcctID(String ^% THE_MESSAGE);
		String ^ __clrcall Message_GetNewAcctID(String ^% THE_MESSAGE);
		String ^ __clrcall Message_GetNymboxHash(String ^% THE_MESSAGE);

		Boolean	 __clrcall ConnectServer(
			String ^% SERVER_ID,
			String ^% USER_ID, 
			String ^% strCA_FILE,
			String ^% strKEY_FILE, 
			String ^% strKEY_PASSWORD
			);

		Boolean	 __clrcall ProcessSockets();

	};
}
