/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 2.0.8
 * 
 * This file is not intended to be easily readable and contains a number of 
 * coding conventions designed to improve portability and efficiency. Do not make
 * changes to this file unless you know what you are doing--modify the SWIG 
 * interface file instead. 
 * ----------------------------------------------------------------------------- */

#ifndef PHP_OTAPI_H
#define PHP_OTAPI_H

extern zend_module_entry otapi_module_entry;
#define phpext_otapi_ptr &otapi_module_entry

#ifdef PHP_WIN32
# define PHP_OTAPI_API __declspec(dllexport)
#else
# define PHP_OTAPI_API
#endif

#ifdef ZTS
#include "TSRM.h"
#endif

PHP_MINIT_FUNCTION(otapi);
PHP_MSHUTDOWN_FUNCTION(otapi);
PHP_RINIT_FUNCTION(otapi);
PHP_RSHUTDOWN_FUNCTION(otapi);
PHP_MINFO_FUNCTION(otapi);

ZEND_NAMED_FUNCTION(_wrap_OTPasswordData_isForNormalNym);
ZEND_NAMED_FUNCTION(_wrap_OTPasswordData_isForMasterKey);
ZEND_NAMED_FUNCTION(_wrap_OTPasswordData_GetDisplayString);
ZEND_NAMED_FUNCTION(_wrap_OTPasswordData_isUsingOldSystem);
ZEND_NAMED_FUNCTION(_wrap_OTPasswordData_setUsingOldSystem);
ZEND_NAMED_FUNCTION(_wrap_OTPasswordData_GetMasterPW);
ZEND_NAMED_FUNCTION(_wrap_new_OTPasswordData);
ZEND_NAMED_FUNCTION(_wrap_OTPassword_m_theBlockSize_get);
ZEND_NAMED_FUNCTION(_wrap_OTPassword_isPassword);
ZEND_NAMED_FUNCTION(_wrap_OTPassword_getPassword_uint8);
ZEND_NAMED_FUNCTION(_wrap_OTPassword_getPassword);
ZEND_NAMED_FUNCTION(_wrap_OTPassword_getPasswordWritable);
ZEND_NAMED_FUNCTION(_wrap_OTPassword_getPasswordWritable_char);
ZEND_NAMED_FUNCTION(_wrap_OTPassword_setPassword);
ZEND_NAMED_FUNCTION(_wrap_OTPassword_setPassword_uint8);
ZEND_NAMED_FUNCTION(_wrap_OTPassword_addChar);
ZEND_NAMED_FUNCTION(_wrap_OTPassword_randomizePassword_uint8);
ZEND_NAMED_FUNCTION(_wrap_OTPassword_randomizePassword);
ZEND_NAMED_FUNCTION(_wrap_OTPassword_isMemory);
ZEND_NAMED_FUNCTION(_wrap_OTPassword_getMemory);
ZEND_NAMED_FUNCTION(_wrap_OTPassword_getMemory_uint8);
ZEND_NAMED_FUNCTION(_wrap_OTPassword_getMemoryWritable);
ZEND_NAMED_FUNCTION(_wrap_OTPassword_setMemory);
ZEND_NAMED_FUNCTION(_wrap_OTPassword_addMemory);
ZEND_NAMED_FUNCTION(_wrap_OTPassword_randomizeMemory_uint8);
ZEND_NAMED_FUNCTION(_wrap_OTPassword_randomizeMemory);
ZEND_NAMED_FUNCTION(_wrap_OTPassword_getBlockSize);
ZEND_NAMED_FUNCTION(_wrap_OTPassword_Compare);
ZEND_NAMED_FUNCTION(_wrap_OTPassword_getPasswordSize);
ZEND_NAMED_FUNCTION(_wrap_OTPassword_getMemorySize);
ZEND_NAMED_FUNCTION(_wrap_OTPassword_zeroMemory);
ZEND_NAMED_FUNCTION(_wrap_OTPassword_safe_memcpy);
ZEND_NAMED_FUNCTION(_wrap_new_OTPassword);
ZEND_NAMED_FUNCTION(_wrap_new_OTCallback);
ZEND_NAMED_FUNCTION(_wrap_OTCallback_runOne);
ZEND_NAMED_FUNCTION(_wrap_OTCallback_runTwo);
ZEND_NAMED_FUNCTION(_wrap_new_OTCaller);
ZEND_NAMED_FUNCTION(_wrap_OTCaller_GetPassword);
ZEND_NAMED_FUNCTION(_wrap_OTCaller_ZeroOutPassword);
ZEND_NAMED_FUNCTION(_wrap_OTCaller_GetDisplay);
ZEND_NAMED_FUNCTION(_wrap_OTCaller_SetDisplay);
ZEND_NAMED_FUNCTION(_wrap_OTCaller_delCallback);
ZEND_NAMED_FUNCTION(_wrap_OTCaller_setCallback);
ZEND_NAMED_FUNCTION(_wrap_OTCaller_isCallbackSet);
ZEND_NAMED_FUNCTION(_wrap_OTCaller_callOne);
ZEND_NAMED_FUNCTION(_wrap_OTCaller_callTwo);
ZEND_NAMED_FUNCTION(_wrap_OT_API_Set_PasswordCallback);
ZEND_NAMED_FUNCTION(_wrap_OT_API_Init);
ZEND_NAMED_FUNCTION(_wrap_OT_API_Cleanup);
ZEND_NAMED_FUNCTION(_wrap_OT_API_SetWallet);
ZEND_NAMED_FUNCTION(_wrap_OT_API_LoadWallet);
ZEND_NAMED_FUNCTION(_wrap_OT_API_SwitchWallet);
ZEND_NAMED_FUNCTION(_wrap_OT_API_Output);
ZEND_NAMED_FUNCTION(_wrap_OT_API_GetTime);
ZEND_NAMED_FUNCTION(_wrap_OT_API_NumList_Add);
ZEND_NAMED_FUNCTION(_wrap_OT_API_NumList_Remove);
ZEND_NAMED_FUNCTION(_wrap_OT_API_NumList_VerifyQuery);
ZEND_NAMED_FUNCTION(_wrap_OT_API_NumList_VerifyAll);
ZEND_NAMED_FUNCTION(_wrap_OT_API_NumList_Count);
ZEND_NAMED_FUNCTION(_wrap_OT_API_Encode);
ZEND_NAMED_FUNCTION(_wrap_OT_API_Decode);
ZEND_NAMED_FUNCTION(_wrap_OT_API_Encrypt);
ZEND_NAMED_FUNCTION(_wrap_OT_API_Decrypt);
ZEND_NAMED_FUNCTION(_wrap_OT_API_CreateSymmetricKey);
ZEND_NAMED_FUNCTION(_wrap_OT_API_SymmetricEncrypt);
ZEND_NAMED_FUNCTION(_wrap_OT_API_SymmetricDecrypt);
ZEND_NAMED_FUNCTION(_wrap_OT_API_SignContract);
ZEND_NAMED_FUNCTION(_wrap_OT_API_FlatSign);
ZEND_NAMED_FUNCTION(_wrap_OT_API_AddSignature);
ZEND_NAMED_FUNCTION(_wrap_OT_API_VerifySignature);
ZEND_NAMED_FUNCTION(_wrap_OT_API_VerifyAndRetrieveXMLContents);
ZEND_NAMED_FUNCTION(_wrap_OT_API_GetMemlogSize);
ZEND_NAMED_FUNCTION(_wrap_OT_API_GetMemlogAtIndex);
ZEND_NAMED_FUNCTION(_wrap_OT_API_PeekMemlogFront);
ZEND_NAMED_FUNCTION(_wrap_OT_API_PeekMemlogBack);
ZEND_NAMED_FUNCTION(_wrap_OT_API_PopMemlogFront);
ZEND_NAMED_FUNCTION(_wrap_OT_API_PopMemlogBack);
ZEND_NAMED_FUNCTION(_wrap_OT_API_CreateNym);
ZEND_NAMED_FUNCTION(_wrap_OT_API_CreateServerContract);
ZEND_NAMED_FUNCTION(_wrap_OT_API_CreateAssetContract);
ZEND_NAMED_FUNCTION(_wrap_OT_API_AddServerContract);
ZEND_NAMED_FUNCTION(_wrap_OT_API_AddAssetContract);
ZEND_NAMED_FUNCTION(_wrap_OT_API_GetServerCount);
ZEND_NAMED_FUNCTION(_wrap_OT_API_GetAssetTypeCount);
ZEND_NAMED_FUNCTION(_wrap_OT_API_GetAccountCount);
ZEND_NAMED_FUNCTION(_wrap_OT_API_GetNymCount);
ZEND_NAMED_FUNCTION(_wrap_OT_API_GetServer_ID);
ZEND_NAMED_FUNCTION(_wrap_OT_API_GetServer_Name);
ZEND_NAMED_FUNCTION(_wrap_OT_API_GetServer_Contract);
ZEND_NAMED_FUNCTION(_wrap_OT_API_GetAssetType_ID);
ZEND_NAMED_FUNCTION(_wrap_OT_API_GetAssetType_Name);
ZEND_NAMED_FUNCTION(_wrap_OT_API_GetAssetType_Contract);
ZEND_NAMED_FUNCTION(_wrap_OT_API_GetAccountWallet_ID);
ZEND_NAMED_FUNCTION(_wrap_OT_API_GetAccountWallet_Name);
ZEND_NAMED_FUNCTION(_wrap_OT_API_GetAccountWallet_Balance);
ZEND_NAMED_FUNCTION(_wrap_OT_API_GetAccountWallet_Type);
ZEND_NAMED_FUNCTION(_wrap_OT_API_GetAccountWallet_AssetTypeID);
ZEND_NAMED_FUNCTION(_wrap_OT_API_GetAccountWallet_ServerID);
ZEND_NAMED_FUNCTION(_wrap_OT_API_GetAccountWallet_NymID);
ZEND_NAMED_FUNCTION(_wrap_OT_API_GetAccountWallet_InboxHash);
ZEND_NAMED_FUNCTION(_wrap_OT_API_GetAccountWallet_OutboxHash);
ZEND_NAMED_FUNCTION(_wrap_OT_API_VerifyAccountReceipt);
ZEND_NAMED_FUNCTION(_wrap_OT_API_GetNym_TransactionNumCount);
ZEND_NAMED_FUNCTION(_wrap_OT_API_GetNym_ID);
ZEND_NAMED_FUNCTION(_wrap_OT_API_GetNym_Name);
ZEND_NAMED_FUNCTION(_wrap_OT_API_GetNym_Stats);
ZEND_NAMED_FUNCTION(_wrap_OT_API_GetNym_NymboxHash);
ZEND_NAMED_FUNCTION(_wrap_OT_API_GetNym_RecentHash);
ZEND_NAMED_FUNCTION(_wrap_OT_API_GetNym_InboxHash);
ZEND_NAMED_FUNCTION(_wrap_OT_API_GetNym_OutboxHash);
ZEND_NAMED_FUNCTION(_wrap_OT_API_IsNym_RegisteredAtServer);
ZEND_NAMED_FUNCTION(_wrap_OT_API_GetNym_MailCount);
ZEND_NAMED_FUNCTION(_wrap_OT_API_GetNym_MailContentsByIndex);
ZEND_NAMED_FUNCTION(_wrap_OT_API_GetNym_MailSenderIDByIndex);
ZEND_NAMED_FUNCTION(_wrap_OT_API_GetNym_MailServerIDByIndex);
ZEND_NAMED_FUNCTION(_wrap_OT_API_Nym_RemoveMailByIndex);
ZEND_NAMED_FUNCTION(_wrap_OT_API_Nym_VerifyMailByIndex);
ZEND_NAMED_FUNCTION(_wrap_OT_API_GetNym_OutmailCount);
ZEND_NAMED_FUNCTION(_wrap_OT_API_GetNym_OutmailContentsByIndex);
ZEND_NAMED_FUNCTION(_wrap_OT_API_GetNym_OutmailRecipientIDByIndex);
ZEND_NAMED_FUNCTION(_wrap_OT_API_GetNym_OutmailServerIDByIndex);
ZEND_NAMED_FUNCTION(_wrap_OT_API_Nym_RemoveOutmailByIndex);
ZEND_NAMED_FUNCTION(_wrap_OT_API_Nym_VerifyOutmailByIndex);
ZEND_NAMED_FUNCTION(_wrap_OT_API_GetNym_OutpaymentsCount);
ZEND_NAMED_FUNCTION(_wrap_OT_API_GetNym_OutpaymentsContentsByIndex);
ZEND_NAMED_FUNCTION(_wrap_OT_API_GetNym_OutpaymentsRecipientIDByIndex);
ZEND_NAMED_FUNCTION(_wrap_OT_API_GetNym_OutpaymentsServerIDByIndex);
ZEND_NAMED_FUNCTION(_wrap_OT_API_Nym_RemoveOutpaymentsByIndex);
ZEND_NAMED_FUNCTION(_wrap_OT_API_Nym_VerifyOutpaymentsByIndex);
ZEND_NAMED_FUNCTION(_wrap_OT_API_Wallet_CanRemoveServer);
ZEND_NAMED_FUNCTION(_wrap_OT_API_Wallet_RemoveServer);
ZEND_NAMED_FUNCTION(_wrap_OT_API_Wallet_CanRemoveAssetType);
ZEND_NAMED_FUNCTION(_wrap_OT_API_Wallet_RemoveAssetType);
ZEND_NAMED_FUNCTION(_wrap_OT_API_Wallet_CanRemoveNym);
ZEND_NAMED_FUNCTION(_wrap_OT_API_Wallet_RemoveNym);
ZEND_NAMED_FUNCTION(_wrap_OT_API_Wallet_CanRemoveAccount);
ZEND_NAMED_FUNCTION(_wrap_OT_API_Wallet_ChangePassphrase);
ZEND_NAMED_FUNCTION(_wrap_OT_API_Wallet_ExportNym);
ZEND_NAMED_FUNCTION(_wrap_OT_API_Wallet_ImportNym);
ZEND_NAMED_FUNCTION(_wrap_OT_API_Wallet_ImportCert);
ZEND_NAMED_FUNCTION(_wrap_OT_API_Wallet_ExportCert);
ZEND_NAMED_FUNCTION(_wrap_OT_API_Wallet_GetNymIDFromPartial);
ZEND_NAMED_FUNCTION(_wrap_OT_API_Wallet_GetServerIDFromPartial);
ZEND_NAMED_FUNCTION(_wrap_OT_API_Wallet_GetAssetIDFromPartial);
ZEND_NAMED_FUNCTION(_wrap_OT_API_Wallet_GetAccountIDFromPartial);
ZEND_NAMED_FUNCTION(_wrap_OT_API_SetNym_Name);
ZEND_NAMED_FUNCTION(_wrap_OT_API_SetAccountWallet_Name);
ZEND_NAMED_FUNCTION(_wrap_OT_API_SetAssetType_Name);
ZEND_NAMED_FUNCTION(_wrap_OT_API_SetServer_Name);
ZEND_NAMED_FUNCTION(_wrap_OT_API_WriteCheque);
ZEND_NAMED_FUNCTION(_wrap_OT_API_DiscardCheque);
ZEND_NAMED_FUNCTION(_wrap_OT_API_ProposePaymentPlan);
ZEND_NAMED_FUNCTION(_wrap_OT_API_ConfirmPaymentPlan);
ZEND_NAMED_FUNCTION(_wrap_OT_API_Create_SmartContract);
ZEND_NAMED_FUNCTION(_wrap_OT_API_SmartContract_AddBylaw);
ZEND_NAMED_FUNCTION(_wrap_OT_API_SmartContract_AddClause);
ZEND_NAMED_FUNCTION(_wrap_OT_API_SmartContract_AddVariable);
ZEND_NAMED_FUNCTION(_wrap_OT_API_SmartContract_AddCallback);
ZEND_NAMED_FUNCTION(_wrap_OT_API_SmartContract_AddHook);
ZEND_NAMED_FUNCTION(_wrap_OT_API_SmartContract_AddParty);
ZEND_NAMED_FUNCTION(_wrap_OT_API_SmartContract_AddAccount);
ZEND_NAMED_FUNCTION(_wrap_OT_API_SmartContract_CountNumsNeeded);
ZEND_NAMED_FUNCTION(_wrap_OT_API_SmartContract_ConfirmAccount);
ZEND_NAMED_FUNCTION(_wrap_OT_API_SmartContract_ConfirmParty);
ZEND_NAMED_FUNCTION(_wrap_OT_API_activateSmartContract);
ZEND_NAMED_FUNCTION(_wrap_OT_API_triggerClause);
ZEND_NAMED_FUNCTION(_wrap_OT_API_Msg_HarvestTransactionNumbers);
ZEND_NAMED_FUNCTION(_wrap_OT_API_LoadUserPubkey);
ZEND_NAMED_FUNCTION(_wrap_OT_API_LoadPubkey);
ZEND_NAMED_FUNCTION(_wrap_OT_API_VerifyUserPrivateKey);
ZEND_NAMED_FUNCTION(_wrap_OT_API_LoadPurse);
ZEND_NAMED_FUNCTION(_wrap_OT_API_LoadMint);
ZEND_NAMED_FUNCTION(_wrap_OT_API_LoadAssetContract);
ZEND_NAMED_FUNCTION(_wrap_OT_API_LoadServerContract);
ZEND_NAMED_FUNCTION(_wrap_OT_API_Mint_IsStillGood);
ZEND_NAMED_FUNCTION(_wrap_OT_API_IsBasketCurrency);
ZEND_NAMED_FUNCTION(_wrap_OT_API_Basket_GetMemberCount);
ZEND_NAMED_FUNCTION(_wrap_OT_API_Basket_GetMemberType);
ZEND_NAMED_FUNCTION(_wrap_OT_API_Basket_GetMinimumTransferAmount);
ZEND_NAMED_FUNCTION(_wrap_OT_API_Basket_GetMemberMinimumTransferAmount);
ZEND_NAMED_FUNCTION(_wrap_OT_API_LoadAssetAccount);
ZEND_NAMED_FUNCTION(_wrap_OT_API_LoadInbox);
ZEND_NAMED_FUNCTION(_wrap_OT_API_LoadOutbox);
ZEND_NAMED_FUNCTION(_wrap_OT_API_LoadInboxNoVerify);
ZEND_NAMED_FUNCTION(_wrap_OT_API_LoadOutboxNoVerify);
ZEND_NAMED_FUNCTION(_wrap_OT_API_LoadPaymentInbox);
ZEND_NAMED_FUNCTION(_wrap_OT_API_LoadPaymentInboxNoVerify);
ZEND_NAMED_FUNCTION(_wrap_OT_API_LoadRecordBox);
ZEND_NAMED_FUNCTION(_wrap_OT_API_LoadRecordBoxNoVerify);
ZEND_NAMED_FUNCTION(_wrap_OT_API_Ledger_GetCount);
ZEND_NAMED_FUNCTION(_wrap_OT_API_Ledger_CreateResponse);
ZEND_NAMED_FUNCTION(_wrap_OT_API_Ledger_GetTransactionByIndex);
ZEND_NAMED_FUNCTION(_wrap_OT_API_Ledger_GetTransactionByID);
ZEND_NAMED_FUNCTION(_wrap_OT_API_Ledger_GetTransactionIDByIndex);
ZEND_NAMED_FUNCTION(_wrap_OT_API_Ledger_AddTransaction);
ZEND_NAMED_FUNCTION(_wrap_OT_API_Transaction_CreateResponse);
ZEND_NAMED_FUNCTION(_wrap_OT_API_Ledger_FinalizeResponse);
ZEND_NAMED_FUNCTION(_wrap_OT_API_Ledger_GetInstrument);
ZEND_NAMED_FUNCTION(_wrap_OT_API_Transaction_GetType);
ZEND_NAMED_FUNCTION(_wrap_OT_API_ReplyNotice_GetRequestNum);
ZEND_NAMED_FUNCTION(_wrap_OT_API_Transaction_GetVoucher);
ZEND_NAMED_FUNCTION(_wrap_OT_API_Transaction_GetSuccess);
ZEND_NAMED_FUNCTION(_wrap_OT_API_Transaction_GetBalanceAgreementSuccess);
ZEND_NAMED_FUNCTION(_wrap_OT_API_Transaction_GetDateSigned);
ZEND_NAMED_FUNCTION(_wrap_OT_API_Transaction_GetAmount);
ZEND_NAMED_FUNCTION(_wrap_OT_API_Pending_GetNote);
ZEND_NAMED_FUNCTION(_wrap_OT_API_Transaction_GetSenderUserID);
ZEND_NAMED_FUNCTION(_wrap_OT_API_Transaction_GetSenderAcctID);
ZEND_NAMED_FUNCTION(_wrap_OT_API_Transaction_GetRecipientUserID);
ZEND_NAMED_FUNCTION(_wrap_OT_API_Transaction_GetRecipientAcctID);
ZEND_NAMED_FUNCTION(_wrap_OT_API_Transaction_GetDisplayReferenceToNum);
ZEND_NAMED_FUNCTION(_wrap_OT_API_CreatePurse);
ZEND_NAMED_FUNCTION(_wrap_OT_API_SavePurse);
ZEND_NAMED_FUNCTION(_wrap_OT_API_Purse_GetTotalValue);
ZEND_NAMED_FUNCTION(_wrap_OT_API_Purse_Count);
ZEND_NAMED_FUNCTION(_wrap_OT_API_Purse_Peek);
ZEND_NAMED_FUNCTION(_wrap_OT_API_Purse_Pop);
ZEND_NAMED_FUNCTION(_wrap_OT_API_Purse_Push);
ZEND_NAMED_FUNCTION(_wrap_OT_API_Wallet_ImportPurse);
ZEND_NAMED_FUNCTION(_wrap_OT_API_exchangePurse);
ZEND_NAMED_FUNCTION(_wrap_OT_API_Token_ChangeOwner);
ZEND_NAMED_FUNCTION(_wrap_OT_API_Token_GetID);
ZEND_NAMED_FUNCTION(_wrap_OT_API_Token_GetDenomination);
ZEND_NAMED_FUNCTION(_wrap_OT_API_Token_GetSeries);
ZEND_NAMED_FUNCTION(_wrap_OT_API_Token_GetValidFrom);
ZEND_NAMED_FUNCTION(_wrap_OT_API_Token_GetValidTo);
ZEND_NAMED_FUNCTION(_wrap_OT_API_Token_GetAssetID);
ZEND_NAMED_FUNCTION(_wrap_OT_API_Token_GetServerID);
ZEND_NAMED_FUNCTION(_wrap_OT_API_Instrument_GetAmount);
ZEND_NAMED_FUNCTION(_wrap_OT_API_Instrument_GetTransNum);
ZEND_NAMED_FUNCTION(_wrap_OT_API_Instrument_GetValidFrom);
ZEND_NAMED_FUNCTION(_wrap_OT_API_Instrument_GetValidTo);
ZEND_NAMED_FUNCTION(_wrap_OT_API_Instrument_GetMemo);
ZEND_NAMED_FUNCTION(_wrap_OT_API_Instrument_GetType);
ZEND_NAMED_FUNCTION(_wrap_OT_API_Instrument_GetAssetID);
ZEND_NAMED_FUNCTION(_wrap_OT_API_Instrmnt_GetSenderUserID);
ZEND_NAMED_FUNCTION(_wrap_OT_API_Instrmnt_GetSenderAcctID);
ZEND_NAMED_FUNCTION(_wrap_OT_API_Instrmnt_GetRecipientUserID);
ZEND_NAMED_FUNCTION(_wrap_OT_API_Instrmnt_GetRecipientAcctID);
ZEND_NAMED_FUNCTION(_wrap_OT_API_checkServerID);
ZEND_NAMED_FUNCTION(_wrap_OT_API_createUserAccount);
ZEND_NAMED_FUNCTION(_wrap_OT_API_deleteUserAccount);
ZEND_NAMED_FUNCTION(_wrap_OT_API_deleteAssetAccount);
ZEND_NAMED_FUNCTION(_wrap_OT_API_usageCredits);
ZEND_NAMED_FUNCTION(_wrap_OT_API_Message_GetUsageCredits);
ZEND_NAMED_FUNCTION(_wrap_OT_API_checkUser);
ZEND_NAMED_FUNCTION(_wrap_OT_API_sendUserMessage);
ZEND_NAMED_FUNCTION(_wrap_OT_API_sendUserInstrument);
ZEND_NAMED_FUNCTION(_wrap_OT_API_getRequest);
ZEND_NAMED_FUNCTION(_wrap_OT_API_getTransactionNumber);
ZEND_NAMED_FUNCTION(_wrap_OT_API_issueAssetType);
ZEND_NAMED_FUNCTION(_wrap_OT_API_getContract);
ZEND_NAMED_FUNCTION(_wrap_OT_API_getMint);
ZEND_NAMED_FUNCTION(_wrap_OT_API_createAssetAccount);
ZEND_NAMED_FUNCTION(_wrap_OT_API_getAccount);
ZEND_NAMED_FUNCTION(_wrap_OT_API_GenerateBasketCreation);
ZEND_NAMED_FUNCTION(_wrap_OT_API_AddBasketCreationItem);
ZEND_NAMED_FUNCTION(_wrap_OT_API_issueBasket);
ZEND_NAMED_FUNCTION(_wrap_OT_API_GenerateBasketExchange);
ZEND_NAMED_FUNCTION(_wrap_OT_API_AddBasketExchangeItem);
ZEND_NAMED_FUNCTION(_wrap_OT_API_exchangeBasket);
ZEND_NAMED_FUNCTION(_wrap_OT_API_notarizeWithdrawal);
ZEND_NAMED_FUNCTION(_wrap_OT_API_notarizeDeposit);
ZEND_NAMED_FUNCTION(_wrap_OT_API_notarizeTransfer);
ZEND_NAMED_FUNCTION(_wrap_OT_API_getInbox);
ZEND_NAMED_FUNCTION(_wrap_OT_API_getOutbox);
ZEND_NAMED_FUNCTION(_wrap_OT_API_getNymbox);
ZEND_NAMED_FUNCTION(_wrap_OT_API_LoadNymbox);
ZEND_NAMED_FUNCTION(_wrap_OT_API_LoadNymboxNoVerify);
ZEND_NAMED_FUNCTION(_wrap_OT_API_Nymbox_GetReplyNotice);
ZEND_NAMED_FUNCTION(_wrap_OT_API_HaveAlreadySeenReply);
ZEND_NAMED_FUNCTION(_wrap_OT_API_getBoxReceipt);
ZEND_NAMED_FUNCTION(_wrap_OT_API_DoesBoxReceiptExist);
ZEND_NAMED_FUNCTION(_wrap_OT_API_processInbox);
ZEND_NAMED_FUNCTION(_wrap_OT_API_processNymbox);
ZEND_NAMED_FUNCTION(_wrap_OT_API_withdrawVoucher);
ZEND_NAMED_FUNCTION(_wrap_OT_API_payDividend);
ZEND_NAMED_FUNCTION(_wrap_OT_API_depositCheque);
ZEND_NAMED_FUNCTION(_wrap_OT_API_depositPaymentPlan);
ZEND_NAMED_FUNCTION(_wrap_OT_API_issueMarketOffer);
ZEND_NAMED_FUNCTION(_wrap_OT_API_getMarketList);
ZEND_NAMED_FUNCTION(_wrap_OT_API_getMarketOffers);
ZEND_NAMED_FUNCTION(_wrap_OT_API_getMarketRecentTrades);
ZEND_NAMED_FUNCTION(_wrap_OT_API_getNym_MarketOffers);
ZEND_NAMED_FUNCTION(_wrap_OT_API_cancelMarketOffer);
ZEND_NAMED_FUNCTION(_wrap_OT_API_cancelPaymentPlan);
ZEND_NAMED_FUNCTION(_wrap_OT_API_PopMessageBuffer);
ZEND_NAMED_FUNCTION(_wrap_OT_API_FlushMessageBuffer);
ZEND_NAMED_FUNCTION(_wrap_OT_API_GetSentMessage);
ZEND_NAMED_FUNCTION(_wrap_OT_API_RemoveSentMessage);
ZEND_NAMED_FUNCTION(_wrap_OT_API_FlushSentMessages);
ZEND_NAMED_FUNCTION(_wrap_OT_API_Sleep);
ZEND_NAMED_FUNCTION(_wrap_OT_API_ResyncNymWithServer);
ZEND_NAMED_FUNCTION(_wrap_OT_API_Message_GetCommand);
ZEND_NAMED_FUNCTION(_wrap_OT_API_Message_GetSuccess);
ZEND_NAMED_FUNCTION(_wrap_OT_API_queryAssetTypes);
ZEND_NAMED_FUNCTION(_wrap_OT_API_Message_GetPayload);
ZEND_NAMED_FUNCTION(_wrap_OT_API_Message_GetDepth);
ZEND_NAMED_FUNCTION(_wrap_OT_API_Message_GetTransactionSuccess);
ZEND_NAMED_FUNCTION(_wrap_OT_API_Message_GetBalanceAgreementSuccess);
ZEND_NAMED_FUNCTION(_wrap_OT_API_Message_GetLedger);
ZEND_NAMED_FUNCTION(_wrap_OT_API_Message_GetNewAssetTypeID);
ZEND_NAMED_FUNCTION(_wrap_OT_API_Message_GetNewIssuerAcctID);
ZEND_NAMED_FUNCTION(_wrap_OT_API_Message_GetNewAcctID);
ZEND_NAMED_FUNCTION(_wrap_OT_API_Message_GetNymboxHash);
ZEND_NAMED_FUNCTION(_wrap_OT_API_ConnectServer);
ZEND_NAMED_FUNCTION(_wrap_OT_API_ProcessSockets);
ZEND_NAMED_FUNCTION(_wrap_Storable_Create);
ZEND_NAMED_FUNCTION(_wrap_Storable_ot_dynamic_cast);
ZEND_NAMED_FUNCTION(_wrap_Storage_GetPacker);
ZEND_NAMED_FUNCTION(_wrap_Storage_Exists);
ZEND_NAMED_FUNCTION(_wrap_Storage_StoreString);
ZEND_NAMED_FUNCTION(_wrap_Storage_QueryString);
ZEND_NAMED_FUNCTION(_wrap_Storage_StorePlainString);
ZEND_NAMED_FUNCTION(_wrap_Storage_QueryPlainString);
ZEND_NAMED_FUNCTION(_wrap_Storage_StoreObject);
ZEND_NAMED_FUNCTION(_wrap_Storage_QueryObject);
ZEND_NAMED_FUNCTION(_wrap_Storage_EncodeObject);
ZEND_NAMED_FUNCTION(_wrap_Storage_DecodeObject);
ZEND_NAMED_FUNCTION(_wrap_Storage_EraseValueByKey);
ZEND_NAMED_FUNCTION(_wrap_Storage_CreateObject);
ZEND_NAMED_FUNCTION(_wrap_Storage_Create);
ZEND_NAMED_FUNCTION(_wrap_Storage_GetType);
ZEND_NAMED_FUNCTION(_wrap_InitDefaultStorage);
ZEND_NAMED_FUNCTION(_wrap_GetDefaultStorage);
ZEND_NAMED_FUNCTION(_wrap_CreateStorageContext);
ZEND_NAMED_FUNCTION(_wrap_CreateObject);
ZEND_NAMED_FUNCTION(_wrap_Exists);
ZEND_NAMED_FUNCTION(_wrap_StoreString);
ZEND_NAMED_FUNCTION(_wrap_QueryString);
ZEND_NAMED_FUNCTION(_wrap_StorePlainString);
ZEND_NAMED_FUNCTION(_wrap_QueryPlainString);
ZEND_NAMED_FUNCTION(_wrap_StoreObject);
ZEND_NAMED_FUNCTION(_wrap_QueryObject);
ZEND_NAMED_FUNCTION(_wrap_EncodeObject);
ZEND_NAMED_FUNCTION(_wrap_DecodeObject);
ZEND_NAMED_FUNCTION(_wrap_EraseValueByKey);
ZEND_NAMED_FUNCTION(_wrap_OTDBString_m_string_set);
ZEND_NAMED_FUNCTION(_wrap_OTDBString_m_string_get);
ZEND_NAMED_FUNCTION(_wrap_OTDBString_ot_dynamic_cast);
ZEND_NAMED_FUNCTION(_wrap_Blob_m_memBuffer_set);
ZEND_NAMED_FUNCTION(_wrap_Blob_m_memBuffer_get);
ZEND_NAMED_FUNCTION(_wrap_Blob_ot_dynamic_cast);
ZEND_NAMED_FUNCTION(_wrap_StringMap_the_map_set);
ZEND_NAMED_FUNCTION(_wrap_StringMap_the_map_get);
ZEND_NAMED_FUNCTION(_wrap_StringMap_SetValue);
ZEND_NAMED_FUNCTION(_wrap_StringMap_GetValue);
ZEND_NAMED_FUNCTION(_wrap_StringMap_ot_dynamic_cast);
ZEND_NAMED_FUNCTION(_wrap_Displayable_gui_label_set);
ZEND_NAMED_FUNCTION(_wrap_Displayable_gui_label_get);
ZEND_NAMED_FUNCTION(_wrap_Displayable_ot_dynamic_cast);
ZEND_NAMED_FUNCTION(_wrap_MarketData_gui_label_set);
ZEND_NAMED_FUNCTION(_wrap_MarketData_gui_label_get);
ZEND_NAMED_FUNCTION(_wrap_MarketData_server_id_set);
ZEND_NAMED_FUNCTION(_wrap_MarketData_server_id_get);
ZEND_NAMED_FUNCTION(_wrap_MarketData_market_id_set);
ZEND_NAMED_FUNCTION(_wrap_MarketData_market_id_get);
ZEND_NAMED_FUNCTION(_wrap_MarketData_asset_type_id_set);
ZEND_NAMED_FUNCTION(_wrap_MarketData_asset_type_id_get);
ZEND_NAMED_FUNCTION(_wrap_MarketData_currency_type_id_set);
ZEND_NAMED_FUNCTION(_wrap_MarketData_currency_type_id_get);
ZEND_NAMED_FUNCTION(_wrap_MarketData_scale_set);
ZEND_NAMED_FUNCTION(_wrap_MarketData_scale_get);
ZEND_NAMED_FUNCTION(_wrap_MarketData_total_assets_set);
ZEND_NAMED_FUNCTION(_wrap_MarketData_total_assets_get);
ZEND_NAMED_FUNCTION(_wrap_MarketData_number_bids_set);
ZEND_NAMED_FUNCTION(_wrap_MarketData_number_bids_get);
ZEND_NAMED_FUNCTION(_wrap_MarketData_number_asks_set);
ZEND_NAMED_FUNCTION(_wrap_MarketData_number_asks_get);
ZEND_NAMED_FUNCTION(_wrap_MarketData_last_sale_price_set);
ZEND_NAMED_FUNCTION(_wrap_MarketData_last_sale_price_get);
ZEND_NAMED_FUNCTION(_wrap_MarketData_current_bid_set);
ZEND_NAMED_FUNCTION(_wrap_MarketData_current_bid_get);
ZEND_NAMED_FUNCTION(_wrap_MarketData_current_ask_set);
ZEND_NAMED_FUNCTION(_wrap_MarketData_current_ask_get);
ZEND_NAMED_FUNCTION(_wrap_MarketData_volume_trades_set);
ZEND_NAMED_FUNCTION(_wrap_MarketData_volume_trades_get);
ZEND_NAMED_FUNCTION(_wrap_MarketData_volume_assets_set);
ZEND_NAMED_FUNCTION(_wrap_MarketData_volume_assets_get);
ZEND_NAMED_FUNCTION(_wrap_MarketData_volume_currency_set);
ZEND_NAMED_FUNCTION(_wrap_MarketData_volume_currency_get);
ZEND_NAMED_FUNCTION(_wrap_MarketData_recent_highest_bid_set);
ZEND_NAMED_FUNCTION(_wrap_MarketData_recent_highest_bid_get);
ZEND_NAMED_FUNCTION(_wrap_MarketData_recent_lowest_ask_set);
ZEND_NAMED_FUNCTION(_wrap_MarketData_recent_lowest_ask_get);
ZEND_NAMED_FUNCTION(_wrap_MarketData_ot_dynamic_cast);
ZEND_NAMED_FUNCTION(_wrap_MarketList_GetMarketDataCount);
ZEND_NAMED_FUNCTION(_wrap_MarketList_GetMarketData);
ZEND_NAMED_FUNCTION(_wrap_MarketList_RemoveMarketData);
ZEND_NAMED_FUNCTION(_wrap_MarketList_AddMarketData);
ZEND_NAMED_FUNCTION(_wrap_MarketList_ot_dynamic_cast);
ZEND_NAMED_FUNCTION(_wrap_OfferDataMarket_gui_label_set);
ZEND_NAMED_FUNCTION(_wrap_OfferDataMarket_gui_label_get);
ZEND_NAMED_FUNCTION(_wrap_OfferDataMarket_transaction_id_set);
ZEND_NAMED_FUNCTION(_wrap_OfferDataMarket_transaction_id_get);
ZEND_NAMED_FUNCTION(_wrap_OfferDataMarket_price_per_scale_set);
ZEND_NAMED_FUNCTION(_wrap_OfferDataMarket_price_per_scale_get);
ZEND_NAMED_FUNCTION(_wrap_OfferDataMarket_available_assets_set);
ZEND_NAMED_FUNCTION(_wrap_OfferDataMarket_available_assets_get);
ZEND_NAMED_FUNCTION(_wrap_OfferDataMarket_minimum_increment_set);
ZEND_NAMED_FUNCTION(_wrap_OfferDataMarket_minimum_increment_get);
ZEND_NAMED_FUNCTION(_wrap_OfferDataMarket_ot_dynamic_cast);
ZEND_NAMED_FUNCTION(_wrap_BidData_gui_label_set);
ZEND_NAMED_FUNCTION(_wrap_BidData_gui_label_get);
ZEND_NAMED_FUNCTION(_wrap_BidData_transaction_id_set);
ZEND_NAMED_FUNCTION(_wrap_BidData_transaction_id_get);
ZEND_NAMED_FUNCTION(_wrap_BidData_price_per_scale_set);
ZEND_NAMED_FUNCTION(_wrap_BidData_price_per_scale_get);
ZEND_NAMED_FUNCTION(_wrap_BidData_available_assets_set);
ZEND_NAMED_FUNCTION(_wrap_BidData_available_assets_get);
ZEND_NAMED_FUNCTION(_wrap_BidData_minimum_increment_set);
ZEND_NAMED_FUNCTION(_wrap_BidData_minimum_increment_get);
ZEND_NAMED_FUNCTION(_wrap_BidData_ot_dynamic_cast);
ZEND_NAMED_FUNCTION(_wrap_AskData_gui_label_set);
ZEND_NAMED_FUNCTION(_wrap_AskData_gui_label_get);
ZEND_NAMED_FUNCTION(_wrap_AskData_transaction_id_set);
ZEND_NAMED_FUNCTION(_wrap_AskData_transaction_id_get);
ZEND_NAMED_FUNCTION(_wrap_AskData_price_per_scale_set);
ZEND_NAMED_FUNCTION(_wrap_AskData_price_per_scale_get);
ZEND_NAMED_FUNCTION(_wrap_AskData_available_assets_set);
ZEND_NAMED_FUNCTION(_wrap_AskData_available_assets_get);
ZEND_NAMED_FUNCTION(_wrap_AskData_minimum_increment_set);
ZEND_NAMED_FUNCTION(_wrap_AskData_minimum_increment_get);
ZEND_NAMED_FUNCTION(_wrap_AskData_ot_dynamic_cast);
ZEND_NAMED_FUNCTION(_wrap_OfferListMarket_GetBidDataCount);
ZEND_NAMED_FUNCTION(_wrap_OfferListMarket_GetBidData);
ZEND_NAMED_FUNCTION(_wrap_OfferListMarket_RemoveBidData);
ZEND_NAMED_FUNCTION(_wrap_OfferListMarket_AddBidData);
ZEND_NAMED_FUNCTION(_wrap_OfferListMarket_GetAskDataCount);
ZEND_NAMED_FUNCTION(_wrap_OfferListMarket_GetAskData);
ZEND_NAMED_FUNCTION(_wrap_OfferListMarket_RemoveAskData);
ZEND_NAMED_FUNCTION(_wrap_OfferListMarket_AddAskData);
ZEND_NAMED_FUNCTION(_wrap_OfferListMarket_ot_dynamic_cast);
ZEND_NAMED_FUNCTION(_wrap_TradeDataMarket_gui_label_set);
ZEND_NAMED_FUNCTION(_wrap_TradeDataMarket_gui_label_get);
ZEND_NAMED_FUNCTION(_wrap_TradeDataMarket_transaction_id_set);
ZEND_NAMED_FUNCTION(_wrap_TradeDataMarket_transaction_id_get);
ZEND_NAMED_FUNCTION(_wrap_TradeDataMarket_date_set);
ZEND_NAMED_FUNCTION(_wrap_TradeDataMarket_date_get);
ZEND_NAMED_FUNCTION(_wrap_TradeDataMarket_price_set);
ZEND_NAMED_FUNCTION(_wrap_TradeDataMarket_price_get);
ZEND_NAMED_FUNCTION(_wrap_TradeDataMarket_amount_sold_set);
ZEND_NAMED_FUNCTION(_wrap_TradeDataMarket_amount_sold_get);
ZEND_NAMED_FUNCTION(_wrap_TradeDataMarket_ot_dynamic_cast);
ZEND_NAMED_FUNCTION(_wrap_TradeListMarket_GetTradeDataMarketCount);
ZEND_NAMED_FUNCTION(_wrap_TradeListMarket_GetTradeDataMarket);
ZEND_NAMED_FUNCTION(_wrap_TradeListMarket_RemoveTradeDataMarket);
ZEND_NAMED_FUNCTION(_wrap_TradeListMarket_AddTradeDataMarket);
ZEND_NAMED_FUNCTION(_wrap_TradeListMarket_ot_dynamic_cast);
ZEND_NAMED_FUNCTION(_wrap_OfferDataNym_gui_label_set);
ZEND_NAMED_FUNCTION(_wrap_OfferDataNym_gui_label_get);
ZEND_NAMED_FUNCTION(_wrap_OfferDataNym_valid_from_set);
ZEND_NAMED_FUNCTION(_wrap_OfferDataNym_valid_from_get);
ZEND_NAMED_FUNCTION(_wrap_OfferDataNym_valid_to_set);
ZEND_NAMED_FUNCTION(_wrap_OfferDataNym_valid_to_get);
ZEND_NAMED_FUNCTION(_wrap_OfferDataNym_server_id_set);
ZEND_NAMED_FUNCTION(_wrap_OfferDataNym_server_id_get);
ZEND_NAMED_FUNCTION(_wrap_OfferDataNym_asset_type_id_set);
ZEND_NAMED_FUNCTION(_wrap_OfferDataNym_asset_type_id_get);
ZEND_NAMED_FUNCTION(_wrap_OfferDataNym_asset_acct_id_set);
ZEND_NAMED_FUNCTION(_wrap_OfferDataNym_asset_acct_id_get);
ZEND_NAMED_FUNCTION(_wrap_OfferDataNym_currency_type_id_set);
ZEND_NAMED_FUNCTION(_wrap_OfferDataNym_currency_type_id_get);
ZEND_NAMED_FUNCTION(_wrap_OfferDataNym_currency_acct_id_set);
ZEND_NAMED_FUNCTION(_wrap_OfferDataNym_currency_acct_id_get);
ZEND_NAMED_FUNCTION(_wrap_OfferDataNym_selling_set);
ZEND_NAMED_FUNCTION(_wrap_OfferDataNym_selling_get);
ZEND_NAMED_FUNCTION(_wrap_OfferDataNym_scale_set);
ZEND_NAMED_FUNCTION(_wrap_OfferDataNym_scale_get);
ZEND_NAMED_FUNCTION(_wrap_OfferDataNym_price_per_scale_set);
ZEND_NAMED_FUNCTION(_wrap_OfferDataNym_price_per_scale_get);
ZEND_NAMED_FUNCTION(_wrap_OfferDataNym_transaction_id_set);
ZEND_NAMED_FUNCTION(_wrap_OfferDataNym_transaction_id_get);
ZEND_NAMED_FUNCTION(_wrap_OfferDataNym_total_assets_set);
ZEND_NAMED_FUNCTION(_wrap_OfferDataNym_total_assets_get);
ZEND_NAMED_FUNCTION(_wrap_OfferDataNym_finished_so_far_set);
ZEND_NAMED_FUNCTION(_wrap_OfferDataNym_finished_so_far_get);
ZEND_NAMED_FUNCTION(_wrap_OfferDataNym_minimum_increment_set);
ZEND_NAMED_FUNCTION(_wrap_OfferDataNym_minimum_increment_get);
ZEND_NAMED_FUNCTION(_wrap_OfferDataNym_stop_sign_set);
ZEND_NAMED_FUNCTION(_wrap_OfferDataNym_stop_sign_get);
ZEND_NAMED_FUNCTION(_wrap_OfferDataNym_stop_price_set);
ZEND_NAMED_FUNCTION(_wrap_OfferDataNym_stop_price_get);
ZEND_NAMED_FUNCTION(_wrap_OfferDataNym_ot_dynamic_cast);
ZEND_NAMED_FUNCTION(_wrap_OfferListNym_GetOfferDataNymCount);
ZEND_NAMED_FUNCTION(_wrap_OfferListNym_GetOfferDataNym);
ZEND_NAMED_FUNCTION(_wrap_OfferListNym_RemoveOfferDataNym);
ZEND_NAMED_FUNCTION(_wrap_OfferListNym_AddOfferDataNym);
ZEND_NAMED_FUNCTION(_wrap_OfferListNym_ot_dynamic_cast);
ZEND_NAMED_FUNCTION(_wrap_TradeDataNym_gui_label_set);
ZEND_NAMED_FUNCTION(_wrap_TradeDataNym_gui_label_get);
ZEND_NAMED_FUNCTION(_wrap_TradeDataNym_transaction_id_set);
ZEND_NAMED_FUNCTION(_wrap_TradeDataNym_transaction_id_get);
ZEND_NAMED_FUNCTION(_wrap_TradeDataNym_completed_count_set);
ZEND_NAMED_FUNCTION(_wrap_TradeDataNym_completed_count_get);
ZEND_NAMED_FUNCTION(_wrap_TradeDataNym_date_set);
ZEND_NAMED_FUNCTION(_wrap_TradeDataNym_date_get);
ZEND_NAMED_FUNCTION(_wrap_TradeDataNym_price_set);
ZEND_NAMED_FUNCTION(_wrap_TradeDataNym_price_get);
ZEND_NAMED_FUNCTION(_wrap_TradeDataNym_amount_sold_set);
ZEND_NAMED_FUNCTION(_wrap_TradeDataNym_amount_sold_get);
ZEND_NAMED_FUNCTION(_wrap_TradeDataNym_ot_dynamic_cast);
ZEND_NAMED_FUNCTION(_wrap_TradeListNym_GetTradeDataNymCount);
ZEND_NAMED_FUNCTION(_wrap_TradeListNym_GetTradeDataNym);
ZEND_NAMED_FUNCTION(_wrap_TradeListNym_RemoveTradeDataNym);
ZEND_NAMED_FUNCTION(_wrap_TradeListNym_AddTradeDataNym);
ZEND_NAMED_FUNCTION(_wrap_TradeListNym_ot_dynamic_cast);
ZEND_NAMED_FUNCTION(_wrap_Acct_gui_label_set);
ZEND_NAMED_FUNCTION(_wrap_Acct_gui_label_get);
ZEND_NAMED_FUNCTION(_wrap_Acct_acct_id_set);
ZEND_NAMED_FUNCTION(_wrap_Acct_acct_id_get);
ZEND_NAMED_FUNCTION(_wrap_Acct_server_id_set);
ZEND_NAMED_FUNCTION(_wrap_Acct_server_id_get);
ZEND_NAMED_FUNCTION(_wrap_Acct_ot_dynamic_cast);
ZEND_NAMED_FUNCTION(_wrap_BitcoinAcct_gui_label_set);
ZEND_NAMED_FUNCTION(_wrap_BitcoinAcct_gui_label_get);
ZEND_NAMED_FUNCTION(_wrap_BitcoinAcct_acct_id_set);
ZEND_NAMED_FUNCTION(_wrap_BitcoinAcct_acct_id_get);
ZEND_NAMED_FUNCTION(_wrap_BitcoinAcct_server_id_set);
ZEND_NAMED_FUNCTION(_wrap_BitcoinAcct_server_id_get);
ZEND_NAMED_FUNCTION(_wrap_BitcoinAcct_bitcoin_acct_name_set);
ZEND_NAMED_FUNCTION(_wrap_BitcoinAcct_bitcoin_acct_name_get);
ZEND_NAMED_FUNCTION(_wrap_BitcoinAcct_ot_dynamic_cast);
ZEND_NAMED_FUNCTION(_wrap_ServerInfo_gui_label_set);
ZEND_NAMED_FUNCTION(_wrap_ServerInfo_gui_label_get);
ZEND_NAMED_FUNCTION(_wrap_ServerInfo_server_id_set);
ZEND_NAMED_FUNCTION(_wrap_ServerInfo_server_id_get);
ZEND_NAMED_FUNCTION(_wrap_ServerInfo_server_type_set);
ZEND_NAMED_FUNCTION(_wrap_ServerInfo_server_type_get);
ZEND_NAMED_FUNCTION(_wrap_ServerInfo_ot_dynamic_cast);
ZEND_NAMED_FUNCTION(_wrap_Server_gui_label_set);
ZEND_NAMED_FUNCTION(_wrap_Server_gui_label_get);
ZEND_NAMED_FUNCTION(_wrap_Server_server_id_set);
ZEND_NAMED_FUNCTION(_wrap_Server_server_id_get);
ZEND_NAMED_FUNCTION(_wrap_Server_server_type_set);
ZEND_NAMED_FUNCTION(_wrap_Server_server_type_get);
ZEND_NAMED_FUNCTION(_wrap_Server_server_host_set);
ZEND_NAMED_FUNCTION(_wrap_Server_server_host_get);
ZEND_NAMED_FUNCTION(_wrap_Server_server_port_set);
ZEND_NAMED_FUNCTION(_wrap_Server_server_port_get);
ZEND_NAMED_FUNCTION(_wrap_Server_ot_dynamic_cast);
ZEND_NAMED_FUNCTION(_wrap_BitcoinServer_gui_label_set);
ZEND_NAMED_FUNCTION(_wrap_BitcoinServer_gui_label_get);
ZEND_NAMED_FUNCTION(_wrap_BitcoinServer_server_id_set);
ZEND_NAMED_FUNCTION(_wrap_BitcoinServer_server_id_get);
ZEND_NAMED_FUNCTION(_wrap_BitcoinServer_server_type_set);
ZEND_NAMED_FUNCTION(_wrap_BitcoinServer_server_type_get);
ZEND_NAMED_FUNCTION(_wrap_BitcoinServer_server_host_set);
ZEND_NAMED_FUNCTION(_wrap_BitcoinServer_server_host_get);
ZEND_NAMED_FUNCTION(_wrap_BitcoinServer_server_port_set);
ZEND_NAMED_FUNCTION(_wrap_BitcoinServer_server_port_get);
ZEND_NAMED_FUNCTION(_wrap_BitcoinServer_bitcoin_username_set);
ZEND_NAMED_FUNCTION(_wrap_BitcoinServer_bitcoin_username_get);
ZEND_NAMED_FUNCTION(_wrap_BitcoinServer_bitcoin_password_set);
ZEND_NAMED_FUNCTION(_wrap_BitcoinServer_bitcoin_password_get);
ZEND_NAMED_FUNCTION(_wrap_BitcoinServer_ot_dynamic_cast);
ZEND_NAMED_FUNCTION(_wrap_RippleServer_gui_label_set);
ZEND_NAMED_FUNCTION(_wrap_RippleServer_gui_label_get);
ZEND_NAMED_FUNCTION(_wrap_RippleServer_server_id_set);
ZEND_NAMED_FUNCTION(_wrap_RippleServer_server_id_get);
ZEND_NAMED_FUNCTION(_wrap_RippleServer_server_type_set);
ZEND_NAMED_FUNCTION(_wrap_RippleServer_server_type_get);
ZEND_NAMED_FUNCTION(_wrap_RippleServer_server_host_set);
ZEND_NAMED_FUNCTION(_wrap_RippleServer_server_host_get);
ZEND_NAMED_FUNCTION(_wrap_RippleServer_server_port_set);
ZEND_NAMED_FUNCTION(_wrap_RippleServer_server_port_get);
ZEND_NAMED_FUNCTION(_wrap_RippleServer_ripple_username_set);
ZEND_NAMED_FUNCTION(_wrap_RippleServer_ripple_username_get);
ZEND_NAMED_FUNCTION(_wrap_RippleServer_ripple_password_set);
ZEND_NAMED_FUNCTION(_wrap_RippleServer_ripple_password_get);
ZEND_NAMED_FUNCTION(_wrap_RippleServer_namefield_id_set);
ZEND_NAMED_FUNCTION(_wrap_RippleServer_namefield_id_get);
ZEND_NAMED_FUNCTION(_wrap_RippleServer_passfield_id_set);
ZEND_NAMED_FUNCTION(_wrap_RippleServer_passfield_id_get);
ZEND_NAMED_FUNCTION(_wrap_RippleServer_ot_dynamic_cast);
ZEND_NAMED_FUNCTION(_wrap_LoomServer_gui_label_set);
ZEND_NAMED_FUNCTION(_wrap_LoomServer_gui_label_get);
ZEND_NAMED_FUNCTION(_wrap_LoomServer_server_id_set);
ZEND_NAMED_FUNCTION(_wrap_LoomServer_server_id_get);
ZEND_NAMED_FUNCTION(_wrap_LoomServer_server_type_set);
ZEND_NAMED_FUNCTION(_wrap_LoomServer_server_type_get);
ZEND_NAMED_FUNCTION(_wrap_LoomServer_server_host_set);
ZEND_NAMED_FUNCTION(_wrap_LoomServer_server_host_get);
ZEND_NAMED_FUNCTION(_wrap_LoomServer_server_port_set);
ZEND_NAMED_FUNCTION(_wrap_LoomServer_server_port_get);
ZEND_NAMED_FUNCTION(_wrap_LoomServer_loom_username_set);
ZEND_NAMED_FUNCTION(_wrap_LoomServer_loom_username_get);
ZEND_NAMED_FUNCTION(_wrap_LoomServer_namefield_id_set);
ZEND_NAMED_FUNCTION(_wrap_LoomServer_namefield_id_get);
ZEND_NAMED_FUNCTION(_wrap_LoomServer_ot_dynamic_cast);
ZEND_NAMED_FUNCTION(_wrap_ContactNym_gui_label_set);
ZEND_NAMED_FUNCTION(_wrap_ContactNym_gui_label_get);
ZEND_NAMED_FUNCTION(_wrap_ContactNym_nym_type_set);
ZEND_NAMED_FUNCTION(_wrap_ContactNym_nym_type_get);
ZEND_NAMED_FUNCTION(_wrap_ContactNym_nym_id_set);
ZEND_NAMED_FUNCTION(_wrap_ContactNym_nym_id_get);
ZEND_NAMED_FUNCTION(_wrap_ContactNym_public_key_set);
ZEND_NAMED_FUNCTION(_wrap_ContactNym_public_key_get);
ZEND_NAMED_FUNCTION(_wrap_ContactNym_memo_set);
ZEND_NAMED_FUNCTION(_wrap_ContactNym_memo_get);
ZEND_NAMED_FUNCTION(_wrap_ContactNym_GetServerInfoCount);
ZEND_NAMED_FUNCTION(_wrap_ContactNym_GetServerInfo);
ZEND_NAMED_FUNCTION(_wrap_ContactNym_RemoveServerInfo);
ZEND_NAMED_FUNCTION(_wrap_ContactNym_AddServerInfo);
ZEND_NAMED_FUNCTION(_wrap_ContactNym_ot_dynamic_cast);
ZEND_NAMED_FUNCTION(_wrap_WalletData_GetBitcoinServerCount);
ZEND_NAMED_FUNCTION(_wrap_WalletData_GetBitcoinServer);
ZEND_NAMED_FUNCTION(_wrap_WalletData_RemoveBitcoinServer);
ZEND_NAMED_FUNCTION(_wrap_WalletData_AddBitcoinServer);
ZEND_NAMED_FUNCTION(_wrap_WalletData_GetBitcoinAcctCount);
ZEND_NAMED_FUNCTION(_wrap_WalletData_GetBitcoinAcct);
ZEND_NAMED_FUNCTION(_wrap_WalletData_RemoveBitcoinAcct);
ZEND_NAMED_FUNCTION(_wrap_WalletData_AddBitcoinAcct);
ZEND_NAMED_FUNCTION(_wrap_WalletData_GetRippleServerCount);
ZEND_NAMED_FUNCTION(_wrap_WalletData_GetRippleServer);
ZEND_NAMED_FUNCTION(_wrap_WalletData_RemoveRippleServer);
ZEND_NAMED_FUNCTION(_wrap_WalletData_AddRippleServer);
ZEND_NAMED_FUNCTION(_wrap_WalletData_GetLoomServerCount);
ZEND_NAMED_FUNCTION(_wrap_WalletData_GetLoomServer);
ZEND_NAMED_FUNCTION(_wrap_WalletData_RemoveLoomServer);
ZEND_NAMED_FUNCTION(_wrap_WalletData_AddLoomServer);
ZEND_NAMED_FUNCTION(_wrap_WalletData_ot_dynamic_cast);
ZEND_NAMED_FUNCTION(_wrap_ContactAcct_gui_label_set);
ZEND_NAMED_FUNCTION(_wrap_ContactAcct_gui_label_get);
ZEND_NAMED_FUNCTION(_wrap_ContactAcct_server_type_set);
ZEND_NAMED_FUNCTION(_wrap_ContactAcct_server_type_get);
ZEND_NAMED_FUNCTION(_wrap_ContactAcct_server_id_set);
ZEND_NAMED_FUNCTION(_wrap_ContactAcct_server_id_get);
ZEND_NAMED_FUNCTION(_wrap_ContactAcct_asset_type_id_set);
ZEND_NAMED_FUNCTION(_wrap_ContactAcct_asset_type_id_get);
ZEND_NAMED_FUNCTION(_wrap_ContactAcct_acct_id_set);
ZEND_NAMED_FUNCTION(_wrap_ContactAcct_acct_id_get);
ZEND_NAMED_FUNCTION(_wrap_ContactAcct_nym_id_set);
ZEND_NAMED_FUNCTION(_wrap_ContactAcct_nym_id_get);
ZEND_NAMED_FUNCTION(_wrap_ContactAcct_memo_set);
ZEND_NAMED_FUNCTION(_wrap_ContactAcct_memo_get);
ZEND_NAMED_FUNCTION(_wrap_ContactAcct_public_key_set);
ZEND_NAMED_FUNCTION(_wrap_ContactAcct_public_key_get);
ZEND_NAMED_FUNCTION(_wrap_ContactAcct_ot_dynamic_cast);
ZEND_NAMED_FUNCTION(_wrap_Contact_gui_label_set);
ZEND_NAMED_FUNCTION(_wrap_Contact_gui_label_get);
ZEND_NAMED_FUNCTION(_wrap_Contact_contact_id_set);
ZEND_NAMED_FUNCTION(_wrap_Contact_contact_id_get);
ZEND_NAMED_FUNCTION(_wrap_Contact_email_set);
ZEND_NAMED_FUNCTION(_wrap_Contact_email_get);
ZEND_NAMED_FUNCTION(_wrap_Contact_memo_set);
ZEND_NAMED_FUNCTION(_wrap_Contact_memo_get);
ZEND_NAMED_FUNCTION(_wrap_Contact_public_key_set);
ZEND_NAMED_FUNCTION(_wrap_Contact_public_key_get);
ZEND_NAMED_FUNCTION(_wrap_Contact_GetContactNymCount);
ZEND_NAMED_FUNCTION(_wrap_Contact_GetContactNym);
ZEND_NAMED_FUNCTION(_wrap_Contact_RemoveContactNym);
ZEND_NAMED_FUNCTION(_wrap_Contact_AddContactNym);
ZEND_NAMED_FUNCTION(_wrap_Contact_GetContactAcctCount);
ZEND_NAMED_FUNCTION(_wrap_Contact_GetContactAcct);
ZEND_NAMED_FUNCTION(_wrap_Contact_RemoveContactAcct);
ZEND_NAMED_FUNCTION(_wrap_Contact_AddContactAcct);
ZEND_NAMED_FUNCTION(_wrap_Contact_ot_dynamic_cast);
ZEND_NAMED_FUNCTION(_wrap_AddressBook_GetContactCount);
ZEND_NAMED_FUNCTION(_wrap_AddressBook_GetContact);
ZEND_NAMED_FUNCTION(_wrap_AddressBook_RemoveContact);
ZEND_NAMED_FUNCTION(_wrap_AddressBook_AddContact);
ZEND_NAMED_FUNCTION(_wrap_AddressBook_ot_dynamic_cast);
#endif /* PHP_OTAPI_H */
