/* Implementation for class OpenTransactionsJNI */


#include "OpenTransactionsJNI.h"

#include "OTIdentifier.h"

#include "OpenTransactions.h"

// I want people to be able to have a high-level C++ interface as well.
// So I coded the high-level interface in C++, and then I call it 1-for-1
// in Java. That way, the high-level interface is available in both languages.




/*
 * Method:    InitOTAPI
 * Class:     OpenTransactionsJNI
 * Signature: (Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_OpenTransactionsJNI_InitOTAPI
(JNIEnv * env, jclass, jstring jstrClientDirectory)
{
	// THE "WORKING DIRECTORY" WHERE ALL THE FILES CAN BE FOUND
	const char * pBuf = env->GetStringUTFChars(jstrClientDirectory, 0);
	OTString strDirectory(pBuf);		// <==== strDirectory is an OTString	
	env->ReleaseStringUTFChars(jstrClientDirectory, pBuf);
	
	OT_API_Init(strDirectory);
}




/*
 * Method:    getAccount
 * Class:     OpenTransactionsJNI
 * Signature: (ILjava/lang/StringBuffer;Ljava/lang/StringBuffer;)Z
 */
JNIEXPORT jboolean JNICALL Java_OpenTransactionsJNI_getAccount__ILjava_lang_StringBuffer_2Ljava_lang_StringBuffer_2
(JNIEnv *env, jobject, jint jintIndex, jobject jstrbufID, jobject jstrbufName)
{
	jboolean retVal= JNI_FALSE;
	
	OTIdentifier	THE_ID;
	OTString		THE_NAME;
	
	bool bSuccess = OT_API_getAccount((int)jintIndex, THE_ID, THE_NAME);
	
	if (bSuccess)
	{
		OTString THE_ID_STR(THE_ID);
		
		// We now have the ID and name, in OT form. Let's convert them to Java...
		
		// Grab the ID and Name into jstring format.
		jstring jstrID		= (jstring)env->NewStringUTF((const char *)THE_ID_STR.Get());
		jstring jstrName	= (jstring)env->NewStringUTF((const char *)THE_NAME.Get());
		
		// Grab the class for each stringbuffer.
		jclass jbufIDclass		= env->GetObjectClass(jstrbufID);
		jclass jbufNameclass	= env->GetObjectClass(jstrbufName);
		
		// Zero the original StringBuffers, so we can replace them with the result
		jmethodID setLengthID_ID, setLengthID_NAME;
		setLengthID_ID		= env->GetMethodID(jbufIDclass, "setLength", "(I)V");
		setLengthID_NAME	= env->GetMethodID(jbufNameclass, "setLength", "(I)V");
		
		// Actually zero them out here...
		env->CallVoidMethod(jstrbufID, setLengthID_ID, (jint) 0);
		env->CallVoidMethod(jstrbufName, setLengthID_NAME, (jint) 0);
		
		// ------------------------------------------------------------
		
		jmethodID mid;   
		
		// Lookup the append method on the StringBuffer output object, so we can call it.
		mid = env->GetMethodID(jbufIDclass, "append","(Ljava/lang/String;)Ljava/lang/StringBuffer;");
		if (0 == mid)
		{
			fprintf(stderr, "Java_OpenTransactionsJNI_getAccount: GetMethodID for jstrbufID returned 0\n");
			return JNI_FALSE;
		}
		
		// Actually call the object's method
		env->CallObjectMethod(jstrbufID, mid, jstrID);
		
		
		// ------------------------------------------------------------
		
		// Lookup the append method on the StringBuffer output object, so we can call it.
		mid = env->GetMethodID(jbufNameclass, "append","(Ljava/lang/String;)Ljava/lang/StringBuffer;");
		if (0 == mid)
		{
			fprintf(stderr, "Java_OpenTransactionsJNI_getAccount: GetMethodID for jstrbufName returned 0\n");
			return JNI_FALSE;
		}
		
		// Actually call the object's method
		env->CallObjectMethod(jstrbufName, mid, jstrName);
		
		// ------------------------------------------------------------
		
		retVal = JNI_TRUE;
	}
	
	return retVal;
}



/*
 * Method:    getAccountCount
 * Class:     OpenTransactionsJNI
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_OpenTransactionsJNI_getAccountCount
(JNIEnv *, jobject)
{
	int nCount = OT_API_getAccountCount();
	
	return (jint)nCount;	
}



/*
 * Method:    getServer
 * Class:     OpenTransactionsJNI
 * Signature: (ILjava/lang/StringBuffer;Ljava/lang/StringBuffer;)Z
 */
JNIEXPORT jboolean JNICALL Java_OpenTransactionsJNI_getServer
(JNIEnv *env, jobject, jint jintIndex, jobject jstrbufID, jobject jstrbufName)
{
	jboolean retVal= JNI_FALSE;
	
	OTIdentifier	THE_ID;
	OTString		THE_NAME;
	
	bool bSuccess = OT_API_getServer((int)jintIndex, THE_ID, THE_NAME);
	
	if (bSuccess)
	{
		OTString THE_ID_STR(THE_ID);
		
		// We now have the ID and name, in OT form. Let's convert them to Java...
		
		// Grab the ID and Name into jstring format.
		jstring jstrID		= (jstring)env->NewStringUTF((const char *)THE_ID_STR.Get());
		jstring jstrName	= (jstring)env->NewStringUTF((const char *)THE_NAME.Get());
		
		// Grab the class for each stringbuffer.
		jclass jbufIDclass		= env->GetObjectClass(jstrbufID);
		jclass jbufNameclass	= env->GetObjectClass(jstrbufName);
		
		// Zero the original StringBuffers, so we can replace them with the result
		jmethodID setLengthID_ID, setLengthID_NAME;
		setLengthID_ID		= env->GetMethodID(jbufIDclass, "setLength", "(I)V");
		setLengthID_NAME	= env->GetMethodID(jbufNameclass, "setLength", "(I)V");
		
		// Actually zero them out here...
		env->CallVoidMethod(jstrbufID, setLengthID_ID, (jint) 0);
		env->CallVoidMethod(jstrbufName, setLengthID_NAME, (jint) 0);
		
		// ------------------------------------------------------------
		
		jmethodID mid;   
		
		// Lookup the append method on the StringBuffer output object, so we can call it.
		mid = env->GetMethodID(jbufIDclass, "append","(Ljava/lang/String;)Ljava/lang/StringBuffer;");
		if (0 == mid)
		{
			fprintf(stderr, "Java_OpenTransactionsJNI_getServer: GetMethodID for jstrbufID returned 0\n");
			return JNI_FALSE;
		}
		
		// Actually call the object's method
		env->CallObjectMethod(jstrbufID, mid, jstrID);
		
		
		// ------------------------------------------------------------
		
		// Lookup the append method on the StringBuffer output object, so we can call it.
		mid = env->GetMethodID(jbufNameclass, "append","(Ljava/lang/String;)Ljava/lang/StringBuffer;");
		if (0 == mid)
		{
			fprintf(stderr, "Java_OpenTransactionsJNI_getServer: GetMethodID for jstrbufName returned 0\n");
			return JNI_FALSE;
		}
		
		// Actually call the object's method
		env->CallObjectMethod(jstrbufName, mid, jstrName);
		
		// ------------------------------------------------------------
		
		retVal = JNI_TRUE;
	}
	
	return retVal;
}

/*
 * Method:    getServerCount
 * Class:     OpenTransactionsJNI
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_OpenTransactionsJNI_getServerCount
(JNIEnv *, jobject)
{
	int nCount = OT_API_getServerCount();
	
	return (jint)nCount;	
}

/*
 * Method:    getAssetType
 * Class:     OpenTransactionsJNI
 * Signature: (ILjava/lang/StringBuffer;Ljava/lang/StringBuffer;)Z
 */
JNIEXPORT jboolean JNICALL Java_OpenTransactionsJNI_getAssetType
(JNIEnv *env, jobject, jint jintIndex, jobject jstrbufID, jobject jstrbufName)
{
	jboolean retVal= JNI_FALSE;
	
	OTIdentifier	THE_ID;
	OTString		THE_NAME;
	
	bool bSuccess = OT_API_getAssetType((int)jintIndex, THE_ID, THE_NAME);
	
	if (bSuccess)
	{
		OTString THE_ID_STR(THE_ID);
		
		// We now have the ID and name, in OT form. Let's convert them to Java...
		
		// Grab the ID and Name into jstring format.
		jstring jstrID		= (jstring)env->NewStringUTF((const char *)THE_ID_STR.Get());
		jstring jstrName	= (jstring)env->NewStringUTF((const char *)THE_NAME.Get());
		
		// Grab the class for each stringbuffer.
		jclass jbufIDclass		= env->GetObjectClass(jstrbufID);
		jclass jbufNameclass	= env->GetObjectClass(jstrbufName);
		
		// Zero the original StringBuffers, so we can replace them with the result
		jmethodID setLengthID_ID, setLengthID_NAME;
		setLengthID_ID		= env->GetMethodID(jbufIDclass, "setLength", "(I)V");
		setLengthID_NAME	= env->GetMethodID(jbufNameclass, "setLength", "(I)V");
		
		// Actually zero them out here...
		env->CallVoidMethod(jstrbufID, setLengthID_ID, (jint) 0);
		env->CallVoidMethod(jstrbufName, setLengthID_NAME, (jint) 0);
		
		// ------------------------------------------------------------
		
		jmethodID mid;   
		
		// Lookup the append method on the StringBuffer output object, so we can call it.
		mid = env->GetMethodID(jbufIDclass, "append","(Ljava/lang/String;)Ljava/lang/StringBuffer;");
		if (0 == mid)
		{
			fprintf(stderr, "Java_OpenTransactionsJNI_getAssetType: GetMethodID for jstrbufID returned 0\n");
			return JNI_FALSE;
		}
		
		// Actually call the object's method
		env->CallObjectMethod(jstrbufID, mid, jstrID);
		
		
		// ------------------------------------------------------------
		
		// Lookup the append method on the StringBuffer output object, so we can call it.
		mid = env->GetMethodID(jbufNameclass, "append","(Ljava/lang/String;)Ljava/lang/StringBuffer;");
		if (0 == mid)
		{
			fprintf(stderr, "Java_OpenTransactionsJNI_getAssetType: GetMethodID for jstrbufName returned 0\n");
			return JNI_FALSE;
		}
		
		// Actually call the object's method
		env->CallObjectMethod(jstrbufName, mid, jstrName);
		
		// ------------------------------------------------------------
		
		retVal = JNI_TRUE;
	}
	
	return retVal;
}

/*
 * Method:    getAssetTypeCount
 * Class:     OpenTransactionsJNI
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_OpenTransactionsJNI_getAssetTypeCount
(JNIEnv *, jobject)
{
	int nCount = OT_API_getAssetTypeCount();
	
	return (jint)nCount;	
}






/*
 * Method:    getNym
 * Class:     OpenTransactionsJNI
 * Signature: (ILjava/lang/StringBuffer;Ljava/lang/StringBuffer;)Z
 */
JNIEXPORT jboolean JNICALL Java_OpenTransactionsJNI_getNym
(JNIEnv *env, jobject, jint jintIndex, jobject jstrbufID, jobject jstrbufName)
{
	jboolean retVal= JNI_FALSE;
	
	OTIdentifier	THE_ID;
	OTString		THE_NAME;
	
	bool bSuccess = OT_API_getNym((int)jintIndex, THE_ID, THE_NAME);
	
	if (bSuccess)
	{
		OTString THE_ID_STR(THE_ID);
		
		// We now have the ID and name, in OT form. Let's convert them to Java...

		// Grab the ID and Name into jstring format.
		jstring jstrID		= (jstring)env->NewStringUTF((const char *)THE_ID_STR.Get());
		jstring jstrName	= (jstring)env->NewStringUTF((const char *)THE_NAME.Get());

		// Grab the class for each stringbuffer.
		jclass jbufIDclass		= env->GetObjectClass(jstrbufID);
		jclass jbufNameclass	= env->GetObjectClass(jstrbufName);

		// Zero the original StringBuffers, so we can replace them with the result
		jmethodID setLengthID_ID, setLengthID_NAME;
		setLengthID_ID		= env->GetMethodID(jbufIDclass, "setLength", "(I)V");
		setLengthID_NAME	= env->GetMethodID(jbufNameclass, "setLength", "(I)V");
		
		// Actually zero them out here...
		env->CallVoidMethod(jstrbufID, setLengthID_ID, (jint) 0);
		env->CallVoidMethod(jstrbufName, setLengthID_NAME, (jint) 0);
		
		// ------------------------------------------------------------
	
		jmethodID mid;   

		// Lookup the append method on the StringBuffer output object, so we can call it.
		mid = env->GetMethodID(jbufIDclass, "append","(Ljava/lang/String;)Ljava/lang/StringBuffer;");
		if (0 == mid)
		{
			fprintf(stderr, "Java_OpenTransactionsJNI_getNym: GetMethodID for jstrbufID returned 0\n");
			return JNI_FALSE;
		}
		
		// Actually call the object's method
		env->CallObjectMethod(jstrbufID, mid, jstrID);
		
		
		// ------------------------------------------------------------
		
		// Lookup the append method on the StringBuffer output object, so we can call it.
		mid = env->GetMethodID(jbufNameclass, "append","(Ljava/lang/String;)Ljava/lang/StringBuffer;");
		if (0 == mid)
		{
			fprintf(stderr, "Java_OpenTransactionsJNI_getNym: GetMethodID for jstrbufName returned 0\n");
			return JNI_FALSE;
		}
		
		// Actually call the object's method
		env->CallObjectMethod(jstrbufName, mid, jstrName);
		
		// ------------------------------------------------------------
		
		retVal = JNI_TRUE;
	}
	
	return retVal;
}

/*
 * Method:    getNymCount
 * Class:     OpenTransactionsJNI
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_OpenTransactionsJNI_getNymCount
(JNIEnv *, jobject)
{
	int nCount = OT_API_getNymCount();

	return (jint)nCount;
}




/*
 // Get the class associated with this object
 jclass cls = env->GetObjectClass(obj);
 
 // The the ID for its 'String toString()' method
 jmethodID mid = env->GetMethodID(cls, "toString", "()Ljava/lang/String;");
 
 // Call the method, which returns a String
 jstring s = (jstring)env->CallObjectMethod(obj, mid);
 
 // Get C-style NULL-terminated string
 const char *buf = (char *)env->GetStringUTFChars(WALLET_PATH, 0); 
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
	const char *buf = (char *)env->GetStringUTFChars(WALLET_PATH, 0);
	
    // Copy the C-string here to an OTString...
	OTString strPath(buf);
	//	printf("%s\n", buf);
	
	// Release the buffer, don't need it anymore...
	env->ReleaseStringUTFChars(WALLET_PATH, buf);

	// Load the wallet...
	bool bLoaded = OT_API_loadWallet(strPath);
	
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
 * Signature: (Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)Z
 */
JNIEXPORT jboolean JNICALL Java_OpenTransactionsJNI_connectServer
(JNIEnv *env, jobject, jstring jstrServerID, jstring jstrUserID, 
 jstring jstrCAFile, jstring jstrKeyFile, jstring jstrKeyPassword)
{
	jboolean retVal= JNI_FALSE;

	char *pBuf = NULL;
	
	// SERVER ID
	pBuf = (char *)env->GetStringUTFChars(jstrServerID, 0);
	OTString strServerID(pBuf);
	env->ReleaseStringUTFChars(jstrServerID, pBuf);
	OTIdentifier SERVER_ID(strServerID);	// <==== SERVER_ID is an OTIdentifier
	
	// USER ID
	pBuf = (char *)env->GetStringUTFChars(jstrUserID, 0);
	OTString strUserID(pBuf);
	env->ReleaseStringUTFChars(jstrUserID, pBuf);
	OTIdentifier USER_ID(strUserID);		// <==== USER_ID is an OTIdentifier	
	
	
	// THE CA FILE
	pBuf = (char *)env->GetStringUTFChars(jstrCAFile, 0);
	OTString strCA_FILE(pBuf);		// <==== strCA_FILE is an OTString	
	env->ReleaseStringUTFChars(jstrCAFile, pBuf);
	
	// THE KEY FILE
	pBuf = (char *)env->GetStringUTFChars(jstrKeyFile, 0);
	OTString strKEY_FILE(pBuf);		// <==== strKEY_FILE is an OTString	
	env->ReleaseStringUTFChars(jstrKeyFile, pBuf);
	
	// THE KEY PASSWORD
	pBuf = (char *)env->GetStringUTFChars(jstrKeyPassword, 0);
	OTString strKEY_PASSWORD(pBuf);		// <==== strKEY_PASSWORD is an OTString	
	env->ReleaseStringUTFChars(jstrKeyPassword, pBuf);
	
	
	bool bConnected = OT_API_connectServer(SERVER_ID, USER_ID,
							  strCA_FILE, strKEY_FILE, strKEY_PASSWORD);

	if (bConnected)
		retVal = JNI_TRUE;
	
	return retVal;
}



/*
 * Method:    processSockets
 * Class:     OpenTransactionsJNI
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_OpenTransactionsJNI_processSockets
(JNIEnv *, jobject)
{
	OT_API_processSockets();
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
	pBuf = (char *)env->GetStringUTFChars(jstrServerID, 0);
	OTString strServerID(pBuf);
	env->ReleaseStringUTFChars(jstrServerID, pBuf);
	OTIdentifier SERVER_ID(strServerID);	// <==== SERVER_ID is an OTIdentifier
	
	// USER ID
	pBuf = (char *)env->GetStringUTFChars(jstrUserID, 0);
	OTString strUserID(pBuf);
	env->ReleaseStringUTFChars(jstrUserID, pBuf);
	OTIdentifier USER_ID(strUserID);		// <==== USER_ID is an OTIdentifier	
	
	// Finally we make the call to the C++ high-level interface...
	OT_API_checkServerID(SERVER_ID, USER_ID);
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
	pBuf = (char *)env->GetStringUTFChars(jstrServerID, 0);
	OTString strServerID(pBuf);
	env->ReleaseStringUTFChars(jstrServerID, pBuf);
	OTIdentifier SERVER_ID(strServerID);	// <==== SERVER_ID is an OTIdentifier
	
	// USER ID
	pBuf = (char *)env->GetStringUTFChars(jstrUserID, 0);
	OTString strUserID(pBuf);
	env->ReleaseStringUTFChars(jstrUserID, pBuf);
	OTIdentifier USER_ID(strUserID);		// <==== USER_ID is an OTIdentifier	
	
	// Finally we make the call to the C++ high-level interface...
	OT_API_createUserAccount(SERVER_ID, USER_ID);	
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
	pBuf = (char *)env->GetStringUTFChars(jstrServerID, 0);
	OTString strServerID(pBuf);
	env->ReleaseStringUTFChars(jstrServerID, pBuf);
	OTIdentifier SERVER_ID(strServerID);	// <==== SERVER_ID is an OTIdentifier
	
	// USER ID
	pBuf = (char *)env->GetStringUTFChars(jstrUserID, 0);
	OTString strUserID(pBuf);
	env->ReleaseStringUTFChars(jstrUserID, pBuf);
	OTIdentifier USER_ID(strUserID);		// <==== USER_ID is an OTIdentifier	
	
	// USER ID CHECK
	pBuf = (char *)env->GetStringUTFChars(jstrUserID2, 0);
	OTString strUserID2(pBuf);
	env->ReleaseStringUTFChars(jstrUserID2, pBuf);
	OTIdentifier USER_ID_CHECK(strUserID2);		// <==== USER_ID_CHECK is an OTIdentifier	
	
	// Finally we make the call to the C++ high-level interface...
	OT_API_checkUser(SERVER_ID, USER_ID, USER_ID_CHECK);	
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
	pBuf = (char *)env->GetStringUTFChars(jstrServerID, 0);
	OTString strServerID(pBuf);
	env->ReleaseStringUTFChars(jstrServerID, pBuf);
	OTIdentifier SERVER_ID(strServerID);	// <==== SERVER_ID is an OTIdentifier
	
	// USER ID
	pBuf = (char *)env->GetStringUTFChars(jstrUserID, 0);
	OTString strUserID(pBuf);
	env->ReleaseStringUTFChars(jstrUserID, pBuf);
	OTIdentifier USER_ID(strUserID);		// <==== USER_ID is an OTIdentifier	
	
	// Finally we make the call to the C++ high-level interface...
	OT_API_getRequest(SERVER_ID, USER_ID);		
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
	pBuf = (char *)env->GetStringUTFChars(jstrServerID, 0);
	OTString strServerID(pBuf);
	env->ReleaseStringUTFChars(jstrServerID, pBuf);
	OTIdentifier SERVER_ID(strServerID);	// <==== SERVER_ID is an OTIdentifier
	
	// USER ID
	pBuf = (char *)env->GetStringUTFChars(jstrUserID, 0);
	OTString strUserID(pBuf);
	env->ReleaseStringUTFChars(jstrUserID, pBuf);
	OTIdentifier USER_ID(strUserID);		// <==== USER_ID is an OTIdentifier	
	
	// THE CONTRACT
	pBuf = (char *)env->GetStringUTFChars(jstrTheContract, 0);
	OTString strTheContract(pBuf);		// <==== strTheContract is an OTString	
	env->ReleaseStringUTFChars(jstrTheContract, pBuf);
	
	// Finally we make the call to the C++ high-level interface...
	OT_API_issueAssetType(SERVER_ID, USER_ID, strTheContract);		
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
	pBuf = (char *)env->GetStringUTFChars(jstrServerID, 0);
	OTString strServerID(pBuf);
	env->ReleaseStringUTFChars(jstrServerID, pBuf);
	OTIdentifier SERVER_ID(strServerID);	// <==== SERVER_ID is an OTIdentifier
	
	// USER ID
	pBuf = (char *)env->GetStringUTFChars(jstrUserID, 0);
	OTString strUserID(pBuf);
	env->ReleaseStringUTFChars(jstrUserID, pBuf);
	OTIdentifier USER_ID(strUserID);		// <==== USER_ID is an OTIdentifier	
	
	// ASSET ID
	pBuf = (char *)env->GetStringUTFChars(jstrAssetID, 0);
	OTString strAssetID(pBuf);
	env->ReleaseStringUTFChars(jstrAssetID, pBuf);
	OTIdentifier ASSET_ID(strAssetID);		// <==== ASSET_ID is an OTIdentifier	
	
	// Finally we make the call to the C++ high-level interface...
	OT_API_getContract(SERVER_ID, USER_ID, ASSET_ID);		
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
	pBuf = (char *)env->GetStringUTFChars(jstrServerID, 0);
	OTString strServerID(pBuf);
	env->ReleaseStringUTFChars(jstrServerID, pBuf);
	OTIdentifier SERVER_ID(strServerID);	// <==== SERVER_ID is an OTIdentifier
	
	// USER ID
	pBuf = (char *)env->GetStringUTFChars(jstrUserID, 0);
	OTString strUserID(pBuf);
	env->ReleaseStringUTFChars(jstrUserID, pBuf);
	OTIdentifier USER_ID(strUserID);		// <==== USER_ID is an OTIdentifier	
	
	// ASSET ID
	pBuf = (char *)env->GetStringUTFChars(jstrAssetID, 0);
	OTString strAssetID(pBuf);
	env->ReleaseStringUTFChars(jstrAssetID, pBuf);
	OTIdentifier ASSET_ID(strAssetID);		// <==== ASSET_ID is an OTIdentifier	
	
	// Finally we make the call to the C++ high-level interface...
	OT_API_getMint(SERVER_ID, USER_ID, ASSET_ID);			
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
	pBuf = (char *)env->GetStringUTFChars(jstrServerID, 0);
	OTString strServerID(pBuf);
	env->ReleaseStringUTFChars(jstrServerID, pBuf);
	OTIdentifier SERVER_ID(strServerID);	// <==== SERVER_ID is an OTIdentifier
	
	// USER ID
	pBuf = (char *)env->GetStringUTFChars(jstrUserID, 0);
	OTString strUserID(pBuf);
	env->ReleaseStringUTFChars(jstrUserID, pBuf);
	OTIdentifier USER_ID(strUserID);		// <==== USER_ID is an OTIdentifier	
	
	// ASSET ID
	pBuf = (char *)env->GetStringUTFChars(jstrAssetID, 0);
	OTString strAssetID(pBuf);
	env->ReleaseStringUTFChars(jstrAssetID, pBuf);
	OTIdentifier ASSET_ID(strAssetID);		// <==== ASSET_ID is an OTIdentifier	
	
	// Finally we make the call to the C++ high-level interface...
	OT_API_createAssetAccount(SERVER_ID, USER_ID, ASSET_ID);			
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
	pBuf = (char *)env->GetStringUTFChars(jstrServerID, 0);
	OTString strServerID(pBuf);
	env->ReleaseStringUTFChars(jstrServerID, pBuf);
	OTIdentifier SERVER_ID(strServerID);	// <==== SERVER_ID is an OTIdentifier
	
	// USER ID
	pBuf = (char *)env->GetStringUTFChars(jstrUserID, 0);
	OTString strUserID(pBuf);
	env->ReleaseStringUTFChars(jstrUserID, pBuf);
	OTIdentifier USER_ID(strUserID);		// <==== USER_ID is an OTIdentifier	
	
	// ACCOUNT ID
	pBuf = (char *)env->GetStringUTFChars(jstrAcctID, 0);
	OTString strAcctID(pBuf);
	env->ReleaseStringUTFChars(jstrAcctID, pBuf);
	OTIdentifier ACCT_ID(strAcctID);		// <==== ACCT_ID is an OTIdentifier	
	
	// Finally we make the call to the C++ high-level interface...
	OT_API_getAccount(SERVER_ID, USER_ID, ACCT_ID);				
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
	pBuf = (char *)env->GetStringUTFChars(jstrServerID, 0);
	OTString strServerID(pBuf);
	env->ReleaseStringUTFChars(jstrServerID, pBuf);
	OTIdentifier SERVER_ID(strServerID);	// <==== SERVER_ID is an OTIdentifier
	
	// USER ID
	pBuf = (char *)env->GetStringUTFChars(jstrUserID, 0);
	OTString strUserID(pBuf);
	env->ReleaseStringUTFChars(jstrUserID, pBuf);
	OTIdentifier USER_ID(strUserID);		// <==== USER_ID is an OTIdentifier	
	
	// BASKET INFO
	pBuf = (char *)env->GetStringUTFChars(jstrBasketInfo, 0);
	OTString strBasketInfo(pBuf);		// <==== strBasketInfo is an OTString
	env->ReleaseStringUTFChars(jstrBasketInfo, pBuf);
	
	// Finally we make the call to the C++ high-level interface...
	OT_API_issueBasket(SERVER_ID, USER_ID, strBasketInfo);					
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
	pBuf = (char *)env->GetStringUTFChars(jstrServerID, 0);
	OTString strServerID(pBuf);
	env->ReleaseStringUTFChars(jstrServerID, pBuf);
	OTIdentifier SERVER_ID(strServerID);	// <==== SERVER_ID is an OTIdentifier
	
	// USER ID
	pBuf = (char *)env->GetStringUTFChars(jstrUserID, 0);
	OTString strUserID(pBuf);
	env->ReleaseStringUTFChars(jstrUserID, pBuf);
	OTIdentifier USER_ID(strUserID);		// <==== USER_ID is an OTIdentifier	
	
	// ASSET ID
	pBuf = (char *)env->GetStringUTFChars(jstrAssetID, 0);
	OTString strAssetID(pBuf);
	env->ReleaseStringUTFChars(jstrAssetID, pBuf);
	OTIdentifier ASSET_ID(strAssetID);		// <==== ASSET_ID is an OTIdentifier	
	
	// BASKET INFO
	pBuf = (char *)env->GetStringUTFChars(jstrBasketInfo, 0);
	OTString strBasketInfo(pBuf);		// <==== strBasketInfo is an OTString
	env->ReleaseStringUTFChars(jstrBasketInfo, pBuf);
		
	// Finally we make the call to the C++ high-level interface...
	OT_API_exchangeBasket(SERVER_ID, USER_ID, ASSET_ID, strBasketInfo);			
	
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
	pBuf = (char *)env->GetStringUTFChars(jstrServerID, 0);
	OTString strServerID(pBuf);
	env->ReleaseStringUTFChars(jstrServerID, pBuf);
	OTIdentifier SERVER_ID(strServerID);	// <==== SERVER_ID is an OTIdentifier
	
	// USER ID
	pBuf = (char *)env->GetStringUTFChars(jstrUserID, 0);
	OTString strUserID(pBuf);
	env->ReleaseStringUTFChars(jstrUserID, pBuf);
	OTIdentifier USER_ID(strUserID);		// <==== USER_ID is an OTIdentifier	
	
	// Finally we make the call to the C++ high-level interface...
	OT_API_getTransactionNumber(SERVER_ID, USER_ID);		
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
	pBuf = (char *)env->GetStringUTFChars(jstrServerID, 0);
	OTString strServerID(pBuf);
	env->ReleaseStringUTFChars(jstrServerID, pBuf);
	OTIdentifier SERVER_ID(strServerID);	// <==== SERVER_ID is an OTIdentifier
	
	// USER ID
	pBuf = (char *)env->GetStringUTFChars(jstrUserID, 0);
	OTString strUserID(pBuf);
	env->ReleaseStringUTFChars(jstrUserID, pBuf);
	OTIdentifier USER_ID(strUserID);		// <==== USER_ID is an OTIdentifier	
	
	// ACCOUNT ID
	pBuf = (char *)env->GetStringUTFChars(jstrAcctID, 0);
	OTString strAcctID(pBuf);
	env->ReleaseStringUTFChars(jstrAcctID, pBuf);
	OTIdentifier ACCT_ID(strAcctID);		// <==== ACCT_ID is an OTIdentifier	
	
	// AMOUNT
	pBuf = (char *)env->GetStringUTFChars(jstrAmount, 0);
	OTString strAmount(pBuf);				// <==== strAmount is an OTString	
	env->ReleaseStringUTFChars(jstrAmount, pBuf);
	
	// Finally we make the call to the C++ high-level interface...
	OT_API_notarizeWithdrawal(SERVER_ID, USER_ID, ACCT_ID, strAmount);				
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
	pBuf = (char *)env->GetStringUTFChars(jstrServerID, 0);
	OTString strServerID(pBuf);
	env->ReleaseStringUTFChars(jstrServerID, pBuf);
	OTIdentifier SERVER_ID(strServerID);	// <==== SERVER_ID is an OTIdentifier
	
	// USER ID
	pBuf = (char *)env->GetStringUTFChars(jstrUserID, 0);
	OTString strUserID(pBuf);
	env->ReleaseStringUTFChars(jstrUserID, pBuf);
	OTIdentifier USER_ID(strUserID);		// <==== USER_ID is an OTIdentifier	
	
	// ACCOUNT ID
	pBuf = (char *)env->GetStringUTFChars(jstrAcctID, 0);
	OTString strAcctID(pBuf);
	env->ReleaseStringUTFChars(jstrAcctID, pBuf);
	OTIdentifier ACCT_ID(strAcctID);		// <==== ACCT_ID is an OTIdentifier	
	
	// PURSE
	pBuf = (char *)env->GetStringUTFChars(jstrPurse, 0);
	OTString strPurse(pBuf);				// <==== strPurse is an OTString	
	env->ReleaseStringUTFChars(jstrPurse, pBuf);
	
	// Finally we make the call to the C++ high-level interface...
	OT_API_notarizeDeposit(SERVER_ID, USER_ID, ACCT_ID, strPurse);				
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
	pBuf = (char *)env->GetStringUTFChars(jstrServerID, 0);
	OTString strServerID(pBuf);
	env->ReleaseStringUTFChars(jstrServerID, pBuf);
	OTIdentifier SERVER_ID(strServerID);	// <==== SERVER_ID is an OTIdentifier
	
	// USER ID
	pBuf = (char *)env->GetStringUTFChars(jstrUserID, 0);
	OTString strUserID(pBuf);
	env->ReleaseStringUTFChars(jstrUserID, pBuf);
	OTIdentifier USER_ID(strUserID);		// <==== USER_ID is an OTIdentifier	
	
	// ACCOUNT FROM ID
	pBuf = (char *)env->GetStringUTFChars(jstrAcctFromID, 0);
	OTString strAcctFromID(pBuf);
	env->ReleaseStringUTFChars(jstrAcctFromID, pBuf);
	OTIdentifier ACCT_FROM_ID(strAcctFromID);	// <==== ACCT_FROM_ID is an OTIdentifier	
	
	// ACCOUNT TO ID
	pBuf = (char *)env->GetStringUTFChars(jstrAcctToID, 0);
	OTString strAcctToID(pBuf);
	env->ReleaseStringUTFChars(jstrAcctToID, pBuf);
	OTIdentifier ACCT_TO_ID(strAcctToID);		// <==== ACCT_TO_ID is an OTIdentifier	
	
	// AMOUNT
	pBuf = (char *)env->GetStringUTFChars(jstrAmount, 0);
	OTString strAmount(pBuf);				// <==== strAmount is an OTString	
	env->ReleaseStringUTFChars(jstrAmount, pBuf);
	
	// NOTE
	pBuf = (char *)env->GetStringUTFChars(jstrNote, 0);
	OTString strNote(pBuf);					// <==== strNote is an OTString	
	env->ReleaseStringUTFChars(jstrNote, pBuf);
	
	// Finally we make the call to the C++ high-level interface...
	OT_API_notarizeTransfer(SERVER_ID, USER_ID, ACCT_FROM_ID, ACCT_TO_ID, strAmount, strNote);				
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
	pBuf = (char *)env->GetStringUTFChars(jstrServerID, 0);
	OTString strServerID(pBuf);
	env->ReleaseStringUTFChars(jstrServerID, pBuf);
	OTIdentifier SERVER_ID(strServerID);	// <==== SERVER_ID is an OTIdentifier
	
	// USER ID
	pBuf = (char *)env->GetStringUTFChars(jstrUserID, 0);
	OTString strUserID(pBuf);
	env->ReleaseStringUTFChars(jstrUserID, pBuf);
	OTIdentifier USER_ID(strUserID);		// <==== USER_ID is an OTIdentifier	
	
	// ACCOUNT ID
	pBuf = (char *)env->GetStringUTFChars(jstrAcctID, 0);
	OTString strAcctID(pBuf);
	env->ReleaseStringUTFChars(jstrAcctID, pBuf);
	OTIdentifier ACCT_ID(strAcctID);		// <==== ACCT_ID is an OTIdentifier	
	
	// Finally we make the call to the C++ high-level interface...
	OT_API_getInbox(SERVER_ID, USER_ID, ACCT_ID);				
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
	pBuf = (char *)env->GetStringUTFChars(jstrServerID, 0);
	OTString strServerID(pBuf);
	env->ReleaseStringUTFChars(jstrServerID, pBuf);
	OTIdentifier SERVER_ID(strServerID);	// <==== SERVER_ID is an OTIdentifier
	
	// USER ID
	pBuf = (char *)env->GetStringUTFChars(jstrUserID, 0);
	OTString strUserID(pBuf);
	env->ReleaseStringUTFChars(jstrUserID, pBuf);
	OTIdentifier USER_ID(strUserID);		// <==== USER_ID is an OTIdentifier	
	
	// ACCOUNT ID
	pBuf = (char *)env->GetStringUTFChars(jstrAcctID, 0);
	OTString strAcctID(pBuf);
	env->ReleaseStringUTFChars(jstrAcctID, pBuf);
	OTIdentifier ACCT_ID(strAcctID);		// <==== ACCT_ID is an OTIdentifier	
	
	// LEDGER
	pBuf = (char *)env->GetStringUTFChars(jstrLedger, 0);
	OTString strLedger(pBuf);				// <==== strLedger is an OTString	
	env->ReleaseStringUTFChars(jstrLedger, pBuf);
	
	// Finally we make the call to the C++ high-level interface...
	OT_API_processInbox(SERVER_ID, USER_ID, ACCT_ID, strLedger);				
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
	pBuf = (char *)env->GetStringUTFChars(jstrServerID, 0);
	OTString strServerID(pBuf);
	env->ReleaseStringUTFChars(jstrServerID, pBuf);
	OTIdentifier SERVER_ID(strServerID);	// <==== SERVER_ID is an OTIdentifier
	
	// USER ID
	pBuf = (char *)env->GetStringUTFChars(jstrUserID, 0);
	OTString strUserID(pBuf);
	env->ReleaseStringUTFChars(jstrUserID, pBuf);
	OTIdentifier USER_ID(strUserID);		// <==== USER_ID is an OTIdentifier	
	
	// ACCOUNT ID
	pBuf = (char *)env->GetStringUTFChars(jstrAcctID, 0);
	OTString strAcctID(pBuf);
	env->ReleaseStringUTFChars(jstrAcctID, pBuf);
	OTIdentifier ACCT_ID(strAcctID);		// <==== ACCT_ID is an OTIdentifier	
	
	// RECIPIENT USER ID
	pBuf = (char *)env->GetStringUTFChars(jstrRecipientUserID, 0);
	OTString strRecipientUserID(pBuf);
	env->ReleaseStringUTFChars(jstrRecipientUserID, pBuf);
	OTIdentifier RECIPIENT_USER_ID(strRecipientUserID);// <==== RECIPIENT_USER_ID is an OTIdentifier	
	
	// MEMO
	pBuf = (char *)env->GetStringUTFChars(jstrMemo, 0);
	OTString strMemo(pBuf);				// <==== strMemo is an OTString	
	env->ReleaseStringUTFChars(jstrMemo, pBuf);
	
	// AMOUNT
	pBuf = (char *)env->GetStringUTFChars(jstrAmount, 0);
	OTString strAmount(pBuf);				// <==== strAmount is an OTString	
	env->ReleaseStringUTFChars(jstrAmount, pBuf);
	
	// Finally we make the call to the C++ high-level interface...
	OT_API_withdrawVoucher(SERVER_ID, USER_ID, ACCT_ID, RECIPIENT_USER_ID, strMemo, strAmount);				
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
	pBuf = (char *)env->GetStringUTFChars(jstrServerID, 0);
	OTString strServerID(pBuf);
	env->ReleaseStringUTFChars(jstrServerID, pBuf);
	OTIdentifier SERVER_ID(strServerID);	// <==== SERVER_ID is an OTIdentifier
	
	// USER ID
	pBuf = (char *)env->GetStringUTFChars(jstrUserID, 0);
	OTString strUserID(pBuf);
	env->ReleaseStringUTFChars(jstrUserID, pBuf);
	OTIdentifier USER_ID(strUserID);		// <==== USER_ID is an OTIdentifier	
	
	// ACCOUNT ID
	pBuf = (char *)env->GetStringUTFChars(jstrAcctID, 0);
	OTString strAcctID(pBuf);
	env->ReleaseStringUTFChars(jstrAcctID, pBuf);
	OTIdentifier ACCT_ID(strAcctID);		// <==== ACCT_ID is an OTIdentifier	
	
	// CHEQUE
	pBuf = (char *)env->GetStringUTFChars(jstrCheque, 0);
	OTString strCheque(pBuf);				// <==== strCheque is an OTString	
	env->ReleaseStringUTFChars(jstrCheque, pBuf);
	
	// Finally we make the call to the C++ high-level interface...
	OT_API_depositCheque(SERVER_ID, USER_ID, ACCT_ID, strCheque);				
}






