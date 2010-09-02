
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
import java.util.Map;

public class OpenTransactionsJNI 
{   		
	// UNIX
	/*
	private static final String DLL_NAME		= "OT_JNI_API";
	private static final String WALLET_PATH		= "/Users/REDACTED/Projects/Open-Transactions/testwallet";	
	private static final String WALLET			= "wallet.xml";
	private static final String CA_FILE			= "SSL-Example/ca.crt";
	private static final String KEY_FILE		= "SSL-Example/client.pem";
	*/
	
	// WINDOWS
	// The C++ code uses these paths so I want to make sure it's compatible, so I changed to \\ instead of /
//	private static final String DLL_PATH		= "C:\\~\\Open-Transactions\\testwallet\\JNI_API_Windows\\Debug\\JNI_API_Windows.dll";
	private static final String DLL_NAME		= "JNI_API_Windows";
	private static final String WALLET_PATH		= "C:\\~\\Open-Transactions\\testwallet";	
	private static final String WALLET			= "wallet-Windows.xml";
	private static final String CA_FILE			= "SSL-Example\\ca.crt";
	private static final String KEY_FILE		= "SSL-Example\\client.pem";
	
	

	private static final String KEY_PASSWORD	= "test";
	
	private static final String SERVER_ID 		= "6147e7dead777e4671020f5ae7d8abb1b84d8c2dae630f7557778129beb5b2bb082c813af3412e77cb865cd91eb213df5cc979367528b7634453113d77fd5953";
	private static final String USER_ID 		= "aa4c73aa4b2658a195fb7ecb1bd242fd1759eaeab0bbd6d0b51f835373b7e5088eb57e804c98e9529a79792d022c3689f1f8d40b5daaf4edb20c64e5b838d0ca";
	private static final String ACCT_ID			= "046adc320eada132f102b44ac9a9885bccd586e538bf3e734d34a8f622a6707d2eb7a99452247b85c7e00f3d31b96bc530f33216531125b6298d1d2be703d022";	

	// Remember the path and wallet we used.
	private static 		 String dllPath			= DLL_NAME;
	private static 		 String wallet			= WALLET;	
	
	private static 		 String serverID		= SERVER_ID;	
	private static 		 String userID			= USER_ID;	
	private static 		 String accountID		= ACCT_ID;	
	
	/**
	 * Constructor.
	 */
	public OpenTransactionsJNI() 
	{
		// Call the other constructor to load the library.
		this (DLL_NAME, WALLET_PATH, WALLET);
		
		// NOTE: The other constructor doesn't do this automatically.
		connectServer(SERVER_ID, USER_ID, CA_FILE, KEY_FILE, KEY_PASSWORD);				
	}
	
	/**
	 * 
	 * Constructor allows path and wallet to be specified.
	 * 
	 * NOTE: This constructor doesn't call connect server automatically.
	 *
	 * @param dllPath
	 * @param clientFolder
	 * @param wallet
	 */
	public OpenTransactionsJNI(String dllPath, String clientFolder, String wallet) 
	{		
		super ();
		
		// Load the library.
		loadLibrary (dllPath, clientFolder, wallet);				
	}
	
	/**
	 * 
	 * @param path
	 * @param wallet
	 */
	public void loadLibrary (String dllPath, String clientFolder, String wallet)
	{
		// Remember the path and wallet.
		OpenTransactionsJNI.dllPath = dllPath;
		OpenTransactionsJNI.wallet  = wallet;
		
		// Load the library
		loadLibrary (dllPath, clientFolder);
		
		// Load the wallet.
		loadWallet(wallet);
	}
	
	///////////////////////////////////////////////////////////////////////////////
	// JNI functions.
	///////////////////////////////////////////////////////////////////////////////
	
	// Step 1... Load the Open Transactions library
	public void loadLibrary (String dllPath, String clientFolder)
	{
		try {
			// Load the dll.
			System.loadLibrary (dllPath); 
			//System.load (dllPath); 
			
			// init client folder
			InitOTAPI(clientFolder);
		}
		catch (Throwable th) {
			// There was a problem.
			th.printStackTrace();
		}
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
			StringBuffer strbufID = new StringBuffer(128), 
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
	public native boolean		getAccountByIndex(int iIndex, StringBuffer jstrbufID, StringBuffer jstrbufName);
	public Map<String,String>	getMapOfAccounts()
	{
		Map<String,String> returnValue = new HashMap<String,String>(5); // "typical size" will be 5. (FYI to HashMap.)
		
		for (int i = 0; i < getAccountCount(); i++) 
		{
			// I know that IDs are strings 128 bytes long. Name () defaults to 16 bytes long.
			// (StringBuffer will resize itself as necessary.)
			StringBuffer	strbufID	= new StringBuffer(128), 
			strbufName	= new StringBuffer();
			
			if (getAccountByIndex(i, strbufID, strbufName))
			{
				returnValue.put(strbufID.toString(), strbufName.toString());				
			}
		}
		
		return returnValue;
	}	
	
	///////////////////////////////////////////////////////////////////////////////
	// JNI Static functions.
	///////////////////////////////////////////////////////////////////////////////
	
	/**
	 * Going native.
	 * 
	 * @param CLIENT_FOLDER
	 */
	protected static native void InitOTAPI(String CLIENT_FOLDER);
	
	/**
	 * Main
	 * 
	 * @param args
	 */
	public static void main(String args[]) 
	{
		OpenTransactionsJNI ot = new OpenTransactionsJNI();
		
		// getAccount will fail unless the request numbers are synced.
		// (They usually are already, but I'm just making sure here.)
		ot.getRequest(serverID, userID);

		ot.getAccount(serverID, userID, accountID);
		
		Map<String,String> nyms = ot.getMapOfNyms();
		System.out.println(nyms.toString());	
	}
}

























