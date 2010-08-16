
/*
 *  OpenTransactionsJNI.java
 *
 *  A high-level Java interface to the Open Transactions library.
 *
 *  Created by Fellow Traveler on 8/6/10.
 *  Copyright 2010. All rights reserved.
 *
 */


class OpenTransactionsJNI 
{     
	// Step 1... Load the Open Transactions library
	public static void InitOT()
	{
		System.loadLibrary("OpenTransactionsJNI"); 
	}
	
	// Step 2...  Instantiate an OpenTransactionsJNI object, then call loadWallet...
	public native void loadWallet(String STR_PATH);
	
	// Step 3...  Generate or add users (public/private keypairs)
	// (NOTE: I already generated a test user, so this step is unnecessary for testing.)
	public native void generatePseudonym(String NYM_NAME);
	public native void addPseudonym(String NYM_PATH);
	
	// Step 4...  Add server contracts to the wallet
	// (NOTE: I already generated a test server, so this step is unnecessary for testing.)
	public native void addServerContract(String SERVER_CONTRACT);
	
	// Step 5...  Connect to a server...
	// Todo: I may phase out "connectServer" since all the other commands
	// already require the SERVER_ID already--it should be smart enough to 
	// connect whenever it needs to just based off of that.
	public native void connectServer(String SERVER_ID);
	
	// Step 6 (polling)
	// Make sure you call this regularly, so Open Transactions has the chance
	// to process any server communications.
	public native void processSockets();
	
	
	// Step 7: Run some commands! (everything below)
	
	public native void checkServerID(String SERVER_ID, String USER_ID);
	
	public native void createUserAccount(String SERVER_ID, String USER_ID);
	
	public native void checkUser(String SERVER_ID,
								 String USER_ID,
								 String USER_ID_CHECK);
	
	public native void getRequest(String SERVER_ID,
								  String USER_ID);
	
	public native void issueAssetType(String SERVER_ID,
									  String USER_ID,
									  String THE_CONTRACT);
	
	public native void getContract(String SERVER_ID,
								   String USER_ID,
								   String ASSET_ID);
	
	public native void getMint(String SERVER_ID,
							   String USER_ID,
							   String ASSET_ID);
	
	public native void createAssetAccount(String SERVER_ID,
										  String USER_ID,
										  String ASSET_TYPE);
	
	public native void getAccount(String SERVER_ID,
								  String USER_ID,
								  String ACCT_ID);
	
	public native void issueBasket(String SERVER_ID,
								   String USER_ID,
								   String BASKET_INFO);
	
	public native void exchangeBasket(String SERVER_ID,
									  String USER_ID,
									  String BASKET_ASSET_ID,
									  String BASKET_INFO);
	
	public native void getTransactionNumber(String SERVER_ID,
											String USER_ID);
	
	public native void notarizeWithdrawal(String SERVER_ID,
										  String USER_ID,
										  String ACCT_ID,
										  String AMOUNT);
	
	public native void notarizeDeposit(String SERVER_ID,
									   String USER_ID,
									   String ACCT_ID,
									   String THE_PURSE);
	
	public native void notarizeTransfer(String SERVER_ID,
										String USER_ID,
										String ACCT_FROM,
										String ACCT_TO,
										String AMOUNT,
										String NOTE);
	
	public native void getInbox(String SERVER_ID,
								String USER_ID,
								String ACCT_ID);
	
	public native void processInbox(String SERVER_ID,
									String USER_ID,
									String ACCT_ID,
									String ACCT_LEDGER);
	
	public native void withdrawVoucher(String SERVER_ID,
								String USER_ID,
								String ACCT_ID,
								String RECIPIENT_USER_ID,
								String CHEQUE_MEMO,
								String AMOUNT);
	
	public native void depositCheque(String SERVER_ID,
									   String USER_ID,
									   String ACCT_ID,
									   String THE_CHEQUE);
	
	
	// -----------------------------------------------------------

	// CALLBACK INTERFACE:  COMING SOON!!!
	
	// The above functions all return void because all they do
	// is SEND THE MESSAGE to the server.
	//
	// Later on, as you are calling processSockets(), server replies will
	// come in. When that happens, I will provide CALLBACK FUNCTIONS so that you
	// can have your actions occur at that time.
	//
	// What callback functions you will need, and what informational functions you
	// will need, is something that you will have to work with me on. I will be VERY
	// responsive to developer needs on this high-level interface...

}
