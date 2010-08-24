/* Implementation for class OpenTransactionsJNI */


#include "OpenTransactionsJNI.h"

#include "OTIdentifier.h"

#include "OpenTransactions.h"

// I want people to be able to have a high-level C++ interface as well.
// So I coded the high-level interface in C++, and then I call it 1-for-1
// in Java. That way, the high-level interface is available in both languages.
//
// TODO: the Java class should be a singleton, since it uses a class-wide
// g_OpenTransactions.  (Not really an issue since I don't see anyone using this
// interface two different times in the same application.)
OpenTransactions g_OpenTransactions;



/*
 // Get the class associated with this object
 jclass cls = env->GetObjectClass(obj);
 
 // The the ID for its 'String toString()' method
 jmethodID mid = env->GetMethodID(cls, "toString", "()Ljava/lang/String;");
 
 // Call the method, which returns a String
 jstring s = (jstring)env->CallObjectMethod(obj, mid);
 
 // Get C-style NULL-terminated string
 const char *buf = env->GetStringUTFChars(WALLET_PATH, 0); 
 */

// ---------------------------------------------------------


/*
 * Class:     OpenTransactionsJNI
 * Method:    loadWallet
 * Signature: (Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_OpenTransactionsJNI_loadWallet
(JNIEnv * env, jobject, jstring WALLET_PATH)
{
    // Get C-style NULL-terminated string
	const char *buf = env->GetStringUTFChars(WALLET_PATH, 0);
	
    // Copy the C-string here to an OTString...
	OTString strPath(buf);
	//	printf("%s\n", buf);
	
	// Release the buffer, don't need it anymore...
	env->ReleaseStringUTFChars(WALLET_PATH, buf);

	// Load the wallet...
	bool bLoaded = g_OpenTransactions.loadWallet(strPath);
	
	// TODO possibly return the bool here.
}


/*
 * Class:     OpenTransactionsJNI
 * Method:    generatePseudonym
 * Signature: (Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_OpenTransactionsJNI_generatePseudonym
(JNIEnv *env, jobject, jstring)
{
	
}


/*
 * Class:     OpenTransactionsJNI
 * Method:    addPseudonym
 * Signature: (Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_OpenTransactionsJNI_addPseudonym
(JNIEnv *env, jobject, jstring)
{
	
}

/*
 * Class:     OpenTransactionsJNI
 * Method:    addServerContract
 * Signature: (Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_OpenTransactionsJNI_addServerContract
(JNIEnv *env, jobject, jstring)
{
	
}


/*
 * Method:    connectServer
 * Class:     OpenTransactionsJNI
 * Signature: (Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_OpenTransactionsJNI_connectServer
  (JNIEnv *env, jobject, jstring jstrServerID)

{
    // Get C-style NULL-terminated string
	const char *buf = env->GetStringUTFChars(jstrServerID, 0);
	
    // Copy the C-string here to an OTString...
	OTString strServerID(buf);
	//	printf("%s\n", buf);
	
	// Release the buffer, don't need it anymore...
	env->ReleaseStringUTFChars(jstrServerID, buf);
	
	// Load the wallet...
	OTIdentifier SERVER_ID(strServerID);
	bool bConnected = g_OpenTransactions.connectServer(SERVER_ID);
	
	// todo:  return the bool here.
}



/*
 * Method:    processSockets
 * Class:     OpenTransactionsJNI
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_OpenTransactionsJNI_processSockets
(JNIEnv *, jobject)
{
	g_OpenTransactions.processSockets();
}




/*
 * Method:    checkServerID
 * Class:     OpenTransactionsJNI
 * Signature: (Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_OpenTransactionsJNI_checkServerID
  (JNIEnv *env, jobject, jstring jstrServerID, jstring jstrUserID)

{
	char *pBuf = NULL;
	
	// SERVER ID
	pBuf = env->GetStringUTFChars(jstrServerID, 0);
	OTString strServerID(pBuf);
	env->ReleaseStringUTFChars(jstrServerID, pBuf);
	OTIdentifier SERVER_ID(strServerID);	// <==== SERVER_ID is an OTIdentifier
	
	// USER ID
	pBuf = env->GetStringUTFChars(jstrUserID, 0);
	OTString strUserID(pBuf);
	env->ReleaseStringUTFChars(jstrUserID, pBuf);
	OTIdentifier USER_ID(strUserID);		// <==== USER_ID is an OTIdentifier	
	
	// Finally we make the call to the C++ high-level interface...
	g_OpenTransactions.checkServerID(SERVER_ID, USER_ID);
}


/*
 * Method:    createUserAccount
 * Class:     OpenTransactionsJNI
 * Signature: (Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_OpenTransactionsJNI_createUserAccount
(JNIEnv *env, jobject, jstring jstrServerID, jstring jstrUserID)
{
	char *pBuf = NULL;
	
	// SERVER ID
	pBuf = env->GetStringUTFChars(jstrServerID, 0);
	OTString strServerID(pBuf);
	env->ReleaseStringUTFChars(jstrServerID, pBuf);
	OTIdentifier SERVER_ID(strServerID);	// <==== SERVER_ID is an OTIdentifier
	
	// USER ID
	pBuf = env->GetStringUTFChars(jstrUserID, 0);
	OTString strUserID(pBuf);
	env->ReleaseStringUTFChars(jstrUserID, pBuf);
	OTIdentifier USER_ID(strUserID);		// <==== USER_ID is an OTIdentifier	
	
	// Finally we make the call to the C++ high-level interface...
	g_OpenTransactions.createUserAccount(SERVER_ID, USER_ID);	
}

/*
 * Method:    checkUser
 * Class:     OpenTransactionsJNI
 * Signature: (Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_OpenTransactionsJNI_checkUser
  (JNIEnv *env, jobject, jstring jstrServerID, jstring jstrUserID, jstring jstrUserID2)
{
	char *pBuf = NULL;
	
	// SERVER ID
	pBuf = env->GetStringUTFChars(jstrServerID, 0);
	OTString strServerID(pBuf);
	env->ReleaseStringUTFChars(jstrServerID, pBuf);
	OTIdentifier SERVER_ID(strServerID);	// <==== SERVER_ID is an OTIdentifier
	
	// USER ID
	pBuf = env->GetStringUTFChars(jstrUserID, 0);
	OTString strUserID(pBuf);
	env->ReleaseStringUTFChars(jstrUserID, pBuf);
	OTIdentifier USER_ID(strUserID);		// <==== USER_ID is an OTIdentifier	
	
	// USER ID CHECK
	pBuf = env->GetStringUTFChars(jstrUserID2, 0);
	OTString strUserID2(pBuf);
	env->ReleaseStringUTFChars(jstrUserID2, pBuf);
	OTIdentifier USER_ID_CHECK(strUserID2);		// <==== USER_ID_CHECK is an OTIdentifier	
	
	// Finally we make the call to the C++ high-level interface...
	g_OpenTransactions.checkUser(SERVER_ID, USER_ID, USER_ID_CHECK);	
}


/*
 * Method:    getRequest
 * Class:     OpenTransactionsJNI
 * Signature: (Ljava/lang/String;Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_OpenTransactionsJNI_getRequest
  (JNIEnv *env, jobject, jstring jstrServerID, jstring jstrUserID)
{
	char *pBuf = NULL;
	
	// SERVER ID
	pBuf = env->GetStringUTFChars(jstrServerID, 0);
	OTString strServerID(pBuf);
	env->ReleaseStringUTFChars(jstrServerID, pBuf);
	OTIdentifier SERVER_ID(strServerID);	// <==== SERVER_ID is an OTIdentifier
	
	// USER ID
	pBuf = env->GetStringUTFChars(jstrUserID, 0);
	OTString strUserID(pBuf);
	env->ReleaseStringUTFChars(jstrUserID, pBuf);
	OTIdentifier USER_ID(strUserID);		// <==== USER_ID is an OTIdentifier	
	
	// Finally we make the call to the C++ high-level interface...
	g_OpenTransactions.getRequest(SERVER_ID, USER_ID);		
}


/*
 * Method:    issueAssetType
 * Class:     OpenTransactionsJNI
 * Signature: (Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_OpenTransactionsJNI_issueAssetType
(JNIEnv *env, jobject, jstring jstrServerID, jstring jstrUserID, jstring jstrTheContract)
{
	char *pBuf = NULL;
	
	// SERVER ID
	pBuf = env->GetStringUTFChars(jstrServerID, 0);
	OTString strServerID(pBuf);
	env->ReleaseStringUTFChars(jstrServerID, pBuf);
	OTIdentifier SERVER_ID(strServerID);	// <==== SERVER_ID is an OTIdentifier
	
	// USER ID
	pBuf = env->GetStringUTFChars(jstrUserID, 0);
	OTString strUserID(pBuf);
	env->ReleaseStringUTFChars(jstrUserID, pBuf);
	OTIdentifier USER_ID(strUserID);		// <==== USER_ID is an OTIdentifier	
	
	// THE CONTRACT
	pBuf = env->GetStringUTFChars(jstrTheContract, 0);
	OTString strTheContract(pBuf);		// <==== strTheContract is an OTString	
	env->ReleaseStringUTFChars(jstrTheContract, pBuf);
	
	// Finally we make the call to the C++ high-level interface...
	g_OpenTransactions.issueAssetType(SERVER_ID, USER_ID, strTheContract);		
}


/*
 * Method:    getContract
 * Class:     OpenTransactionsJNI
 * Signature: (Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_OpenTransactionsJNI_getContract
(JNIEnv *env, jobject, jstring jstrServerID, jstring jstrUserID, jstring jstrAssetID)
{
	char *pBuf = NULL;
	
	// SERVER ID
	pBuf = env->GetStringUTFChars(jstrServerID, 0);
	OTString strServerID(pBuf);
	env->ReleaseStringUTFChars(jstrServerID, pBuf);
	OTIdentifier SERVER_ID(strServerID);	// <==== SERVER_ID is an OTIdentifier
	
	// USER ID
	pBuf = env->GetStringUTFChars(jstrUserID, 0);
	OTString strUserID(pBuf);
	env->ReleaseStringUTFChars(jstrUserID, pBuf);
	OTIdentifier USER_ID(strUserID);		// <==== USER_ID is an OTIdentifier	
	
	// ASSET ID
	pBuf = env->GetStringUTFChars(jstrAssetID, 0);
	OTString strAssetID(pBuf);
	env->ReleaseStringUTFChars(jstrAssetID, pBuf);
	OTIdentifier ASSET_ID(strAssetID);		// <==== ASSET_ID is an OTIdentifier	
	
	// Finally we make the call to the C++ high-level interface...
	g_OpenTransactions.getContract(SERVER_ID, USER_ID, ASSET_ID);		
}


/*
 * Method:    getMint
 * Class:     OpenTransactionsJNI
 * Signature: (Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_OpenTransactionsJNI_getMint
(JNIEnv *env, jobject, jstring jstrServerID, jstring jstrUserID, jstring jstrAssetID)
{
	char *pBuf = NULL;
	
	// SERVER ID
	pBuf = env->GetStringUTFChars(jstrServerID, 0);
	OTString strServerID(pBuf);
	env->ReleaseStringUTFChars(jstrServerID, pBuf);
	OTIdentifier SERVER_ID(strServerID);	// <==== SERVER_ID is an OTIdentifier
	
	// USER ID
	pBuf = env->GetStringUTFChars(jstrUserID, 0);
	OTString strUserID(pBuf);
	env->ReleaseStringUTFChars(jstrUserID, pBuf);
	OTIdentifier USER_ID(strUserID);		// <==== USER_ID is an OTIdentifier	
	
	// ASSET ID
	pBuf = env->GetStringUTFChars(jstrAssetID, 0);
	OTString strAssetID(pBuf);
	env->ReleaseStringUTFChars(jstrAssetID, pBuf);
	OTIdentifier ASSET_ID(strAssetID);		// <==== ASSET_ID is an OTIdentifier	
	
	// Finally we make the call to the C++ high-level interface...
	g_OpenTransactions.getMint(SERVER_ID, USER_ID, ASSET_ID);			
}


/*
 * Method:    createAssetAccount
 * Class:     OpenTransactionsJNI
 * Signature: (Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_OpenTransactionsJNI_createAssetAccount
(JNIEnv *env, jobject, jstring jstrServerID, jstring jstrUserID, jstring jstrAssetID)
{
	char *pBuf = NULL;
	
	// SERVER ID
	pBuf = env->GetStringUTFChars(jstrServerID, 0);
	OTString strServerID(pBuf);
	env->ReleaseStringUTFChars(jstrServerID, pBuf);
	OTIdentifier SERVER_ID(strServerID);	// <==== SERVER_ID is an OTIdentifier
	
	// USER ID
	pBuf = env->GetStringUTFChars(jstrUserID, 0);
	OTString strUserID(pBuf);
	env->ReleaseStringUTFChars(jstrUserID, pBuf);
	OTIdentifier USER_ID(strUserID);		// <==== USER_ID is an OTIdentifier	
	
	// ASSET ID
	pBuf = env->GetStringUTFChars(jstrAssetID, 0);
	OTString strAssetID(pBuf);
	env->ReleaseStringUTFChars(jstrAssetID, pBuf);
	OTIdentifier ASSET_ID(strAssetID);		// <==== ASSET_ID is an OTIdentifier	
	
	// Finally we make the call to the C++ high-level interface...
	g_OpenTransactions.createAssetAccount(SERVER_ID, USER_ID, ASSET_ID);			
}


/*
 * Method:    getAccount
 * Class:     OpenTransactionsJNI
 * Signature: (Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_OpenTransactionsJNI_getAccount
(JNIEnv *env, jobject, jstring jstrServerID, jstring jstrUserID, jstring jstrAcctID)
{
	char *pBuf = NULL;
	
	// SERVER ID
	pBuf = env->GetStringUTFChars(jstrServerID, 0);
	OTString strServerID(pBuf);
	env->ReleaseStringUTFChars(jstrServerID, pBuf);
	OTIdentifier SERVER_ID(strServerID);	// <==== SERVER_ID is an OTIdentifier
	
	// USER ID
	pBuf = env->GetStringUTFChars(jstrUserID, 0);
	OTString strUserID(pBuf);
	env->ReleaseStringUTFChars(jstrUserID, pBuf);
	OTIdentifier USER_ID(strUserID);		// <==== USER_ID is an OTIdentifier	
	
	// ACCOUNT ID
	pBuf = env->GetStringUTFChars(jstrAcctID, 0);
	OTString strAcctID(pBuf);
	env->ReleaseStringUTFChars(jstrAcctID, pBuf);
	OTIdentifier ACCT_ID(strAcctID);		// <==== ACCT_ID is an OTIdentifier	
	
	// Finally we make the call to the C++ high-level interface...
	g_OpenTransactions.getAccount(SERVER_ID, USER_ID, ACCT_ID);				
}


/*
 * Method:    issueBasket
 * Class:     OpenTransactionsJNI
 * Signature: (Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_OpenTransactionsJNI_issueBasket
(JNIEnv *env, jobject, jstring jstrServerID, jstring jstrUserID, jstring jstrBasketInfo)
{
	char *pBuf = NULL;
	
	// SERVER ID
	pBuf = env->GetStringUTFChars(jstrServerID, 0);
	OTString strServerID(pBuf);
	env->ReleaseStringUTFChars(jstrServerID, pBuf);
	OTIdentifier SERVER_ID(strServerID);	// <==== SERVER_ID is an OTIdentifier
	
	// USER ID
	pBuf = env->GetStringUTFChars(jstrUserID, 0);
	OTString strUserID(pBuf);
	env->ReleaseStringUTFChars(jstrUserID, pBuf);
	OTIdentifier USER_ID(strUserID);		// <==== USER_ID is an OTIdentifier	
	
	// BASKET INFO
	pBuf = env->GetStringUTFChars(jstrBasketInfo, 0);
	OTString strBasketInfo(pBuf);		// <==== strBasketInfo is an OTString
	env->ReleaseStringUTFChars(jstrBasketInfo, pBuf);
	
	// Finally we make the call to the C++ high-level interface...
	g_OpenTransactions.issueBasket(SERVER_ID, USER_ID, strBasketInfo);					
}


/*
 * Method:    exchangeBasket
 * Class:     OpenTransactionsJNI
 * Signature: (Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_OpenTransactionsJNI_exchangeBasket
(JNIEnv *env, jobject, jstring jstrServerID, jstring jstrUserID, jstring jstrAssetID, jstring jstrBasketInfo)
{
	char *pBuf = NULL;
	
	// SERVER ID
	pBuf = env->GetStringUTFChars(jstrServerID, 0);
	OTString strServerID(pBuf);
	env->ReleaseStringUTFChars(jstrServerID, pBuf);
	OTIdentifier SERVER_ID(strServerID);	// <==== SERVER_ID is an OTIdentifier
	
	// USER ID
	pBuf = env->GetStringUTFChars(jstrUserID, 0);
	OTString strUserID(pBuf);
	env->ReleaseStringUTFChars(jstrUserID, pBuf);
	OTIdentifier USER_ID(strUserID);		// <==== USER_ID is an OTIdentifier	
	
	// ASSET ID
	pBuf = env->GetStringUTFChars(jstrAssetID, 0);
	OTString strAssetID(pBuf);
	env->ReleaseStringUTFChars(jstrAssetID, pBuf);
	OTIdentifier ASSET_ID(strAssetID);		// <==== ASSET_ID is an OTIdentifier	
	
	// BASKET INFO
	pBuf = env->GetStringUTFChars(jstrBasketInfo, 0);
	OTString strBasketInfo(pBuf);		// <==== strBasketInfo is an OTString
	env->ReleaseStringUTFChars(jstrBasketInfo, pBuf);
		
	// Finally we make the call to the C++ high-level interface...
	g_OpenTransactions.exchangeBasket(SERVER_ID, USER_ID, ASSET_ID, strBasketInfo);			
	
}


/*
 * Method:    getTransactionNumber
 * Class:     OpenTransactionsJNI
 * Signature: (Ljava/lang/String;Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_OpenTransactionsJNI_getTransactionNumber
(JNIEnv *env, jobject, jstring jstrServerID, jstring jstrUserID)
{
	char *pBuf = NULL;
	
	// SERVER ID
	pBuf = env->GetStringUTFChars(jstrServerID, 0);
	OTString strServerID(pBuf);
	env->ReleaseStringUTFChars(jstrServerID, pBuf);
	OTIdentifier SERVER_ID(strServerID);	// <==== SERVER_ID is an OTIdentifier
	
	// USER ID
	pBuf = env->GetStringUTFChars(jstrUserID, 0);
	OTString strUserID(pBuf);
	env->ReleaseStringUTFChars(jstrUserID, pBuf);
	OTIdentifier USER_ID(strUserID);		// <==== USER_ID is an OTIdentifier	
	
	// Finally we make the call to the C++ high-level interface...
	g_OpenTransactions.getTransactionNumber(SERVER_ID, USER_ID);		
}

/*
 * Method:    notarizeWithdrawal
 * Class:     OpenTransactionsJNI
 * Signature: (Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_OpenTransactionsJNI_notarizeWithdrawal
(JNIEnv *env, jobject, jstring jstrServerID, jstring jstrUserID, jstring jstrAcctID, jstring jstrAmount)
{
	char *pBuf = NULL;
	
	// SERVER ID
	pBuf = env->GetStringUTFChars(jstrServerID, 0);
	OTString strServerID(pBuf);
	env->ReleaseStringUTFChars(jstrServerID, pBuf);
	OTIdentifier SERVER_ID(strServerID);	// <==== SERVER_ID is an OTIdentifier
	
	// USER ID
	pBuf = env->GetStringUTFChars(jstrUserID, 0);
	OTString strUserID(pBuf);
	env->ReleaseStringUTFChars(jstrUserID, pBuf);
	OTIdentifier USER_ID(strUserID);		// <==== USER_ID is an OTIdentifier	
	
	// ACCOUNT ID
	pBuf = env->GetStringUTFChars(jstrAcctID, 0);
	OTString strAcctID(pBuf);
	env->ReleaseStringUTFChars(jstrAcctID, pBuf);
	OTIdentifier ACCT_ID(strAcctID);		// <==== ACCT_ID is an OTIdentifier	
	
	// AMOUNT
	pBuf = env->GetStringUTFChars(jstrAmount, 0);
	OTString strAmount(pBuf);				// <==== strAmount is an OTString	
	env->ReleaseStringUTFChars(jstrAmount, pBuf);
	
	// Finally we make the call to the C++ high-level interface...
	g_OpenTransactions.notarizeWithdrawal(SERVER_ID, USER_ID, ACCT_ID, strAmount);				
}


/*
 * Method:    notarizeDeposit
 * Class:     OpenTransactionsJNI
 * Signature: (Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_OpenTransactionsJNI_notarizeDeposit
(JNIEnv *env, jobject, jstring jstrServerID, jstring jstrUserID, jstring jstrAcctID, jstring jstrPurse)
{
	char *pBuf = NULL;
	
	// SERVER ID
	pBuf = env->GetStringUTFChars(jstrServerID, 0);
	OTString strServerID(pBuf);
	env->ReleaseStringUTFChars(jstrServerID, pBuf);
	OTIdentifier SERVER_ID(strServerID);	// <==== SERVER_ID is an OTIdentifier
	
	// USER ID
	pBuf = env->GetStringUTFChars(jstrUserID, 0);
	OTString strUserID(pBuf);
	env->ReleaseStringUTFChars(jstrUserID, pBuf);
	OTIdentifier USER_ID(strUserID);		// <==== USER_ID is an OTIdentifier	
	
	// ACCOUNT ID
	pBuf = env->GetStringUTFChars(jstrAcctID, 0);
	OTString strAcctID(pBuf);
	env->ReleaseStringUTFChars(jstrAcctID, pBuf);
	OTIdentifier ACCT_ID(strAcctID);		// <==== ACCT_ID is an OTIdentifier	
	
	// PURSE
	pBuf = env->GetStringUTFChars(jstrPurse, 0);
	OTString strPurse(pBuf);				// <==== strPurse is an OTString	
	env->ReleaseStringUTFChars(jstrPurse, pBuf);
	
	// Finally we make the call to the C++ high-level interface...
	g_OpenTransactions.notarizeDeposit(SERVER_ID, USER_ID, ACCT_ID, strPurse);				
}


/*
 * Method:    notarizeTransfer
 * Class:     OpenTransactionsJNI
 * Signature: (Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_OpenTransactionsJNI_notarizeTransfer
(JNIEnv *env, jobject,	jstring jstrServerID, jstring jstrUserID, 
						jstring jstrAcctFromID, jstring jstrAcctToID, 
						jstring jstrAmount, jstring jstrNote)
{
	char *pBuf = NULL;
	
	// SERVER ID
	pBuf = env->GetStringUTFChars(jstrServerID, 0);
	OTString strServerID(pBuf);
	env->ReleaseStringUTFChars(jstrServerID, pBuf);
	OTIdentifier SERVER_ID(strServerID);	// <==== SERVER_ID is an OTIdentifier
	
	// USER ID
	pBuf = env->GetStringUTFChars(jstrUserID, 0);
	OTString strUserID(pBuf);
	env->ReleaseStringUTFChars(jstrUserID, pBuf);
	OTIdentifier USER_ID(strUserID);		// <==== USER_ID is an OTIdentifier	
	
	// ACCOUNT FROM ID
	pBuf = env->GetStringUTFChars(jstrAcctFromID, 0);
	OTString strAcctFromID(pBuf);
	env->ReleaseStringUTFChars(jstrAcctFromID, pBuf);
	OTIdentifier ACCT_FROM_ID(strAcctFromID);	// <==== ACCT_FROM_ID is an OTIdentifier	
	
	// ACCOUNT TO ID
	pBuf = env->GetStringUTFChars(jstrAcctToID, 0);
	OTString strAcctToID(pBuf);
	env->ReleaseStringUTFChars(jstrAcctToID, pBuf);
	OTIdentifier ACCT_TO_ID(strAcctToID);		// <==== ACCT_TO_ID is an OTIdentifier	
	
	// AMOUNT
	pBuf = env->GetStringUTFChars(jstrAmount, 0);
	OTString strAmount(pBuf);				// <==== strAmount is an OTString	
	env->ReleaseStringUTFChars(jstrAmount, pBuf);
	
	// NOTE
	pBuf = env->GetStringUTFChars(jstrNote, 0);
	OTString strNote(pBuf);					// <==== strNote is an OTString	
	env->ReleaseStringUTFChars(jstrNote, pBuf);
	
	// Finally we make the call to the C++ high-level interface...
	g_OpenTransactions.notarizeWithdrawal(SERVER_ID, USER_ID, 
										  ACCT_FROM_ID, ACCT_TO_ID, 
										  strAmount, strNote);				
}


/*
 * Method:    getInbox
 * Class:     OpenTransactionsJNI
 * Signature: (Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_OpenTransactionsJNI_getInbox
(JNIEnv *env, jobject, jstring jstrServerID, jstring jstrUserID, jstring jstrAcctID)
{
	char *pBuf = NULL;
	
	// SERVER ID
	pBuf = env->GetStringUTFChars(jstrServerID, 0);
	OTString strServerID(pBuf);
	env->ReleaseStringUTFChars(jstrServerID, pBuf);
	OTIdentifier SERVER_ID(strServerID);	// <==== SERVER_ID is an OTIdentifier
	
	// USER ID
	pBuf = env->GetStringUTFChars(jstrUserID, 0);
	OTString strUserID(pBuf);
	env->ReleaseStringUTFChars(jstrUserID, pBuf);
	OTIdentifier USER_ID(strUserID);		// <==== USER_ID is an OTIdentifier	
	
	// ACCOUNT ID
	pBuf = env->GetStringUTFChars(jstrAcctID, 0);
	OTString strAcctID(pBuf);
	env->ReleaseStringUTFChars(jstrAcctID, pBuf);
	OTIdentifier ACCT_ID(strAcctID);		// <==== ACCT_ID is an OTIdentifier	
	
	// Finally we make the call to the C++ high-level interface...
	g_OpenTransactions.getInbox(SERVER_ID, USER_ID, ACCT_ID);				
}


/*
 * Method:    processInbox
 * Class:     OpenTransactionsJNI
 * Signature: (Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_OpenTransactionsJNI_processInbox
(JNIEnv *env, jobject, jstring jstrServerID, jstring jstrUserID, jstring jstrAcctID, jstring jstrLedger)
{
	char *pBuf = NULL;
	
	// SERVER ID
	pBuf = env->GetStringUTFChars(jstrServerID, 0);
	OTString strServerID(pBuf);
	env->ReleaseStringUTFChars(jstrServerID, pBuf);
	OTIdentifier SERVER_ID(strServerID);	// <==== SERVER_ID is an OTIdentifier
	
	// USER ID
	pBuf = env->GetStringUTFChars(jstrUserID, 0);
	OTString strUserID(pBuf);
	env->ReleaseStringUTFChars(jstrUserID, pBuf);
	OTIdentifier USER_ID(strUserID);		// <==== USER_ID is an OTIdentifier	
	
	// ACCOUNT ID
	pBuf = env->GetStringUTFChars(jstrAcctID, 0);
	OTString strAcctID(pBuf);
	env->ReleaseStringUTFChars(jstrAcctID, pBuf);
	OTIdentifier ACCT_ID(strAcctID);		// <==== ACCT_ID is an OTIdentifier	
	
	// LEDGER
	pBuf = env->GetStringUTFChars(jstrLedger, 0);
	OTString strLedger(pBuf);				// <==== strLedger is an OTString	
	env->ReleaseStringUTFChars(jstrLedger, pBuf);
	
	// Finally we make the call to the C++ high-level interface...
	g_OpenTransactions.processInbox(SERVER_ID, USER_ID, ACCT_ID, strLedger);				
}



//----------------------------------------------------------------------


/*
 * Method:    withdrawVoucher
 * Class:     OpenTransactionsJNI
 * Signature: (Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_OpenTransactionsJNI_withdrawVoucher
(JNIEnv *env, jobject,	jstring jstrServerID,			jstring jstrUserID,	jstring jstrAcctID, 
						jstring jstrRecipientUserID,	jstring jstrMemo,	jstring jstrAmount)
{
	char *pBuf = NULL;
	
	// SERVER ID
	pBuf = env->GetStringUTFChars(jstrServerID, 0);
	OTString strServerID(pBuf);
	env->ReleaseStringUTFChars(jstrServerID, pBuf);
	OTIdentifier SERVER_ID(strServerID);	// <==== SERVER_ID is an OTIdentifier
	
	// USER ID
	pBuf = env->GetStringUTFChars(jstrUserID, 0);
	OTString strUserID(pBuf);
	env->ReleaseStringUTFChars(jstrUserID, pBuf);
	OTIdentifier USER_ID(strUserID);		// <==== USER_ID is an OTIdentifier	
	
	// ACCOUNT ID
	pBuf = env->GetStringUTFChars(jstrAcctID, 0);
	OTString strAcctID(pBuf);
	env->ReleaseStringUTFChars(jstrAcctID, pBuf);
	OTIdentifier ACCT_ID(strAcctID);		// <==== ACCT_ID is an OTIdentifier	
	
	// RECIPIENT USER ID
	pBuf = env->GetStringUTFChars(jstrRecipientUserID, 0);
	OTString strRecipientUserID(pBuf);
	env->ReleaseStringUTFChars(jstrRecipientUserID, pBuf);
	OTIdentifier RECIPIENT_USER_ID(strRecipientUserID);// <==== RECIPIENT_USER_ID is an OTIdentifier	
	
	// MEMO
	pBuf = env->GetStringUTFChars(jstrMemo, 0);
	OTString strMemo(pBuf);				// <==== strMemo is an OTString	
	env->ReleaseStringUTFChars(jstrMemo, pBuf);
	
	// AMOUNT
	pBuf = env->GetStringUTFChars(jstrAmount, 0);
	OTString strAmount(pBuf);				// <==== strAmount is an OTString	
	env->ReleaseStringUTFChars(jstrAmount, pBuf);
	
	// Finally we make the call to the C++ high-level interface...
	g_OpenTransactions.withdrawVoucher(SERVER_ID, USER_ID, ACCT_ID, RECIPIENT_USER_ID, strMemo, strAmount);				
}


/*
 * Method:    depositCheque
 * Class:     OpenTransactionsJNI
 * Signature: (Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_OpenTransactionsJNI_depositCheque
(JNIEnv *env, jobject, jstring jstrServerID, jstring jstrUserID, jstring jstrAcctID, jstring jstrCheque)
{
	char *pBuf = NULL;
	
	// SERVER ID
	pBuf = env->GetStringUTFChars(jstrServerID, 0);
	OTString strServerID(pBuf);
	env->ReleaseStringUTFChars(jstrServerID, pBuf);
	OTIdentifier SERVER_ID(strServerID);	// <==== SERVER_ID is an OTIdentifier
	
	// USER ID
	pBuf = env->GetStringUTFChars(jstrUserID, 0);
	OTString strUserID(pBuf);
	env->ReleaseStringUTFChars(jstrUserID, pBuf);
	OTIdentifier USER_ID(strUserID);		// <==== USER_ID is an OTIdentifier	
	
	// ACCOUNT ID
	pBuf = env->GetStringUTFChars(jstrAcctID, 0);
	OTString strAcctID(pBuf);
	env->ReleaseStringUTFChars(jstrAcctID, pBuf);
	OTIdentifier ACCT_ID(strAcctID);		// <==== ACCT_ID is an OTIdentifier	
	
	// CHEQUE
	pBuf = env->GetStringUTFChars(jstrCheque, 0);
	OTString strCheque(pBuf);				// <==== strCheque is an OTString	
	env->ReleaseStringUTFChars(jstrCheque, pBuf);
	
	// Finally we make the call to the C++ high-level interface...
	g_OpenTransactions.depositCheque(SERVER_ID, USER_ID, ACCT_ID, strCheque);				
}






