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


class OpenTransactions
{
public:
	OpenTransactions();
	~OpenTransactions();
	
	bool loadWallet(OTString & strPath);
	
	bool connectServer(OTIdentifier & SERVER_ID);
	
	bool processSockets();
	
	void checkServerID(OTIdentifier & SERVER_ID,
		   OTIdentifier & USER_ID);
	
	void createUserAccount(OTIdentifier & SERVER_ID,
		   OTIdentifier & USER_ID);
	
	void checkUser(OTIdentifier SERVER_ID,
	   OTIdentifier USER_ID,
	   OTIdentifier USER_ID_CHECK);
	
	void getRequest(OTIdentifier & SERVER_ID,
		OTIdentifier & USER_ID);
	
	
	void issueAssetType(OTIdentifier	&	SERVER_ID,
			OTIdentifier	&	USER_ID,
			OTString		&	THE_CONTRACT);
	
	void getContract(OTIdentifier & SERVER_ID,
		 OTIdentifier & USER_ID,
		 OTIdentifier & ASSET_ID);
	
	void getMint(OTIdentifier & SERVER_ID,
		 OTIdentifier & USER_ID,
		 OTIdentifier & ASSET_ID);
	
	void createAssetAccount(OTIdentifier & SERVER_ID,
		OTIdentifier & USER_ID,
		OTIdentifier & ASSET_ID);
	
	void getAccount(OTIdentifier & SERVER_ID,
		OTIdentifier & USER_ID,
		OTIdentifier & ACCT_ID);
	
	void issueBasket(OTIdentifier	& SERVER_ID,
		 OTIdentifier	& USER_ID,
		 OTString		& BASKET_INFO);
	
	void exchangeBasket(OTIdentifier	& SERVER_ID,
		OTIdentifier	& USER_ID,
		OTIdentifier	& BASKET_ASSET_ID,
		OTString		& BASKET_INFO);
		
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
	
	void getInbox(OTIdentifier & SERVER_ID,
		  OTIdentifier & USER_ID,
		  OTIdentifier & ACCT_ID);
	
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
		 OTIdentifier	& ACCT_FROM_ID,
		 OTString		& THE_CHEQUE);
	
	
};



#endif // __OPEN_TRANSACTIONS_INTERFACE_H__