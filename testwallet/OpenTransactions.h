/*
 *  OpenTransactions.h
 *
 *  A high-level C++ interface to the Open Transactions library.
 *
 *  Created by Fellow Traveler on 8/6/10.
 *  Copyright 2010. All rights reserved.
 *
 */

#ifndef __OPEN_TRANSACTIONS_INTERFACE_H__
#define __OPEN_TRANSACTIONS_INTERFACE_H__

class OTString;
class OTIdentifier;

	bool OT_API_Init(OTString & strClientPath);

	bool OT_API_loadWallet(OTString & strPath);
	
	bool OT_API_connectServer(OTIdentifier & SERVER_ID,
					   OTIdentifier	& USER_ID,
					   OTString & strCA_FILE, 
					   OTString & strKEY_FILE, 
					   OTString & strKEY_PASSWORD);
	
	bool OT_API_processSockets();
	
	void OT_API_checkServerID(OTIdentifier & SERVER_ID,
		   OTIdentifier & USER_ID);
	
	void OT_API_createUserAccount(OTIdentifier & SERVER_ID,
		   OTIdentifier & USER_ID);
	
	void OT_API_checkUser(OTIdentifier & SERVER_ID,
	   OTIdentifier & USER_ID,
	   OTIdentifier & USER_ID_CHECK);
	
	void OT_API_getRequest(OTIdentifier & SERVER_ID,
		OTIdentifier & USER_ID);
	
	
	void OT_API_issueAssetType(OTIdentifier	&	SERVER_ID,
			OTIdentifier	&	USER_ID,
			OTString		&	THE_CONTRACT);
	
	void OT_API_getContract(OTIdentifier & SERVER_ID,
		 OTIdentifier & USER_ID,
		 OTIdentifier & ASSET_ID);
	
	void OT_API_getMint(OTIdentifier & SERVER_ID,
		 OTIdentifier & USER_ID,
		 OTIdentifier & ASSET_ID);
	
	void OT_API_createAssetAccount(OTIdentifier & SERVER_ID,
		OTIdentifier & USER_ID,
		OTIdentifier & ASSET_ID);
	
	void OT_API_getAccount(OTIdentifier & SERVER_ID,
		OTIdentifier & USER_ID,
		OTIdentifier & ACCT_ID);
	
	void OT_API_issueBasket(OTIdentifier	& SERVER_ID,
		 OTIdentifier	& USER_ID,
		 OTString		& BASKET_INFO);
	
	void OT_API_exchangeBasket(OTIdentifier	& SERVER_ID,
		OTIdentifier	& USER_ID,
		OTIdentifier	& BASKET_ASSET_ID,
		OTString		& BASKET_INFO);
		
	void OT_API_getTransactionNumber(OTIdentifier & SERVER_ID,
		  OTIdentifier & USER_ID);
	
	void OT_API_notarizeWithdrawal(OTIdentifier	& SERVER_ID,
		OTIdentifier	& USER_ID,
		OTIdentifier	& ACCT_ID,
		OTString		& AMOUNT);
	
	void OT_API_notarizeDeposit(OTIdentifier	& SERVER_ID,
		 OTIdentifier	& USER_ID,
		 OTIdentifier	& ACCT_ID,
		 OTString		& THE_PURSE);
	
	void OT_API_notarizeTransfer(OTIdentifier	& SERVER_ID,
		  OTIdentifier	& USER_ID,
		  OTIdentifier	& ACCT_FROM,
		  OTIdentifier	& ACCT_TO,
		  OTString		& AMOUNT,
		  OTString		& NOTE);
	
	void OT_API_getInbox(OTIdentifier & SERVER_ID,
		  OTIdentifier & USER_ID,
		  OTIdentifier & ACCT_ID);
	
	void OT_API_processInbox(OTIdentifier	& SERVER_ID,
		  OTIdentifier	& USER_ID,
		  OTIdentifier	& ACCT_ID,
		  OTString		& ACCT_LEDGER);

	void OT_API_withdrawVoucher(OTIdentifier	& SERVER_ID,
		   OTIdentifier	& USER_ID,
		   OTIdentifier	& ACCT_ID,
		   OTIdentifier	& RECIPIENT_USER_ID,
		   OTString		& CHEQUE_MEMO,
		   OTString		& AMOUNT);
	
	void OT_API_depositCheque(OTIdentifier	& SERVER_ID,
		 OTIdentifier	& USER_ID,
		 OTIdentifier	& ACCT_FROM_ID,
		 OTString		& THE_CHEQUE);
	
	
	// --------------------------------------------------
	
	int OT_API_getNymCount();
	int OT_API_getServerCount();
	int OT_API_getAssetTypeCount();
	int OT_API_getAccountCount();
	
	bool OT_API_getNym(int iIndex, OTIdentifier & NYM_ID, OTString & NYM_NAME);
	bool OT_API_getServer(int iIndex, OTIdentifier & THE_ID, OTString & THE_NAME);
	bool OT_API_getAssetType(int iIndex, OTIdentifier & THE_ID, OTString & THE_NAME);
	bool OT_API_getAccount(int iIndex, OTIdentifier & THE_ID, OTString & THE_NAME);		


		


#endif // __OPEN_TRANSACTIONS_INTERFACE_H__