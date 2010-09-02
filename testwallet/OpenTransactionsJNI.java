
/*
 *  OpenTransactionsJNI.java
 *
 *  A high-level Java interface to the Open Transactions library.
 *
 *  Created by Fellow Traveler on 8/6/10.
 *  Copyright 2010. All rights reserved.
 *
 */


import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;
import java.util.Set;


public class OpenTransactionsJNI 
{     
	
	public static void main(String args[]) {
		
		OpenTransactionsJNI.InitOT("/Users/REDACTED/Projects/Open-Transactions/testwallet");
		
		OpenTransactionsJNI theAPI = new OpenTransactionsJNI();
		
		theAPI.loadWallet("wallet.xml");
		
		theAPI.connectServer("6147e7dead777e4671020f5ae7d8abb1b84d8c2dae630f7557778129beb5b2bb082c813af3412e77cb865cd91eb213df5cc979367528b7634453113d77fd5953",
							 "aa4c73aa4b2658a195fb7ecb1bd242fd1759eaeab0bbd6d0b51f835373b7e5088eb57e804c98e9529a79792d022c3689f1f8d40b5daaf4edb20c64e5b838d0ca",
							 "SSL-Example/ca.crt",
							 "SSL-Example/client.pem",
							 "test");
	}
	
	
	protected static native void InitOTAPI(String CLIENT_FOLDER);

	
	// Step 1... Load the Open Transactions library
	public static void InitOT(String CLIENT_FOLDER)
	{
		System.loadLibrary("OT_JNI_API"); 
		
		InitOTAPI(CLIENT_FOLDER);
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
	public native boolean connectServer(String SERVER_ID, String USER_ID,
										String strCA_FILE, String strKEY_FILE, String strKEY_PASSWORD);
	
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
	
	// WALLET CONTENTS.
	
	
	public native int			getNymCount();
	// iIndex is input, jstrbufID and jstrbufName are output.
	public native boolean		getNym(int iIndex, StringBuffer jstrbufID, StringBuffer jstrbufName);
	public Map<String,String>	getMapOfNyms() 
	{
		Map<String,String> returnValue = new HashMap<String,String>(5); // "typical size" will be 5. (FYI to HashMap.)
		
		for (int i = 0; i < getNymCount(); i++) 
		{
			// I know that IDs are strings 128 bytes long. Name () defaults to 16 bytes long.
			// (StringBuffer will resize itself as necessary.)
			StringBuffer	strbufID	= new StringBuffer(128), 
			strbufName	= new StringBuffer();
			
			if (getNym(i, strbufID, strbufName))
			{
				returnValue.put(strbufID.toString(), strbufName.toString());				
			}
		}
		
		return returnValue;
	}
	
	// -----------------------------------------------------------
	
	public native int			getServerCount();
	// iIndex is input, jstrbufID and jstrbufName are output.
	public native boolean		getServer(int iIndex, StringBuffer jstrbufID, StringBuffer jstrbufName);
	public Map<String,String>	getMapOfServers() 
	{
		Map<String,String> returnValue = new HashMap<String,String>(5); // "typical size" will be 5. (FYI to HashMap.)
		
		for (int i = 0; i < getServerCount(); i++) 
		{
			// I know that IDs are strings 128 bytes long. Name () defaults to 16 bytes long.
			// (StringBuffer will resize itself as necessary.)
			StringBuffer	strbufID	= new StringBuffer(128), 
			strbufName	= new StringBuffer();
			
			if (getServer(i, strbufID, strbufName))
			{
				returnValue.put(strbufID.toString(), strbufName.toString());				
			}
		}
		
		return returnValue;
	}
	
	
	// -----------------------------------------------------------
	
	public native int			getAssetTypeCount();
	// iIndex is input, jstrbufID and jstrbufName are output.
	public native boolean		getAssetType(int iIndex, StringBuffer jstrbufID, StringBuffer jstrbufName);
	public Map<String,String>	getMapOfAssetTypes()
	{
		Map<String,String> returnValue = new HashMap<String,String>(5); // "typical size" will be 5. (FYI to HashMap.)
		
		for (int i = 0; i < getAssetTypeCount(); i++) 
		{
			// I know that IDs are strings 128 bytes long. Name () defaults to 16 bytes long.
			// (StringBuffer will resize itself as necessary.)
			StringBuffer	strbufID	= new StringBuffer(128), 
			strbufName	= new StringBuffer();
			
			if (getAssetType(i, strbufID, strbufName))
			{
				returnValue.put(strbufID.toString(), strbufName.toString());				
			}
		}
		
		return returnValue;
	}
	
	
	// -----------------------------------------------------------
	
	
	public native int			getAccountCount();
	// iIndex is input, jstrbufID and jstrbufName are output.
	public native boolean		getAccount(int iIndex, StringBuffer jstrbufID, StringBuffer jstrbufName);
	public Map<String,String>	getMapOfAccounts()
	{
		Map<String,String> returnValue = new HashMap<String,String>(5); // "typical size" will be 5. (FYI to HashMap.)
		
		for (int i = 0; i < getAccountCount(); i++) 
		{
			// I know that IDs are strings 128 bytes long. Name () defaults to 16 bytes long.
			// (StringBuffer will resize itself as necessary.)
			StringBuffer	strbufID	= new StringBuffer(128), 
			strbufName	= new StringBuffer();
			
			if (getAccount(i, strbufID, strbufName))
			{
				returnValue.put(strbufID.toString(), strbufName.toString());				
			}
		}
		
		return returnValue;
	}
	
	
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



// Return:
//
// Java String object containing environment variable value
// ========================================================================
//JNIEXPORT jstring JNICALL 
//Java_SysInfo_getenv__Ljava_lang_String_2 
//(JNIEnv *env, jclass clazz, jstring EVName)
//{
//	// Check Java String object argument (environment variable name) to see
//	// if null reference passed.
//	if (EVName == 0)
//		return 0;
//
//	// Get ASCII representation of environment variable name.
//	const char *_EVName = env->GetStringUTFChars (EVName, 0);
//
//	// Get environment variable value.
//	const char *EVValue = getenv (_EVName);
//
//	// Release memory used to hold ASCII representation.
//	env->ReleaseStringUTFChars (EVName, _EVName);
//
//	// Return a null reference if there is no environment variable value 
//	// otherwise return this value.
//	return (EVValue == 0) ? 0 : env->NewStringUTF (EVValue);
//}



























