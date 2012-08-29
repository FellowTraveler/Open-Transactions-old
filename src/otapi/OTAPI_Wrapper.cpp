
#include <vector>
#include <memory>

// credit:stlplus library.
#include "containers/simple_ptr.hpp"

#include <OTAPI_Wrapper.h>


#include <OTStorage.h>
#include <OTString.h>
#include <OTMint.h>
#include <OTContract.h>
#include <OTBasket.h>
#include <OTWallet.h>
#include <OTMessage.h>
#include <OTPayment.h>
#include <OTCheque.h>
#include <OTPurse.h>
#include <OTPaymentPlan.h>
#include <OTLedger.h>
#include <OTAsymmetricKey.h>

#include <OTClient.h>


#include <OpenTransactions.h>


using namespace std;


OTAPI_Wrap * OTAPI_Wrap::p_Wrap = NULL;


OTAPI_Wrap::OTAPI_Wrap() : p_OTAPI(OT_CTX::It() -> New(&OTAPI_Wrap::TheTransportCallback)), m_bInitialized(false), m_bLoadedWallet(false)
{

}

//static
bool OTAPI_Wrap::TheTransportCallback(const OTServerContract & sc, const OTEnvelope & env)
{
	return OTAPI_Wrap::OTAPI()->TransportCallback(sc,env);
}

//static
shared_ptr<OTAPI_Wrap> OTAPI_Wrap::It()
{
	static shared_ptr<OTAPI_Wrap> p_Wrap(nullptr);

	if (nullptr == p_Wrap)
	{
		p_Wrap = shared_ptr<OTAPI_Wrap>(new OTAPI_Wrap());

	}
	return p_Wrap;
}

OTAPI_Wrap::~OTAPI_Wrap()
{

}

//static
const std::unique_ptr<OT_API> & OTAPI_Wrap::OTAPI()
{
	return OTAPI_Wrap::It()->p_OTAPI;
}


int64_t OTAPI_Wrap::StringToLong(const string & strNumber)
{
	char* end;
	int64_t lNumber = strtol(strNumber.c_str(), &end, 10);

	if (!*end) return lNumber;
	else 
	{
		OTLog::sError("Conversion error (str to long), non-convertible part: %s",end);
		OT_ASSERT(false);
		return -1;
	}
}

string OTAPI_Wrap::LongToString(const int64_t & lNumber)
{
	string strNumber;
	stringstream strstream;

	strstream << lNumber;
	strstream >> strNumber;

	return strNumber;
}


// --------------------------------------------------------------------
/**
INITIALIZE the OTAPI  (Called by the constructor automaticaly)

Call this first, to initialize the library.

*/

bool OTAPI_Wrap::Init()
{
	if (NULL != OTAPI_Wrap::It()) return true;
	else return false;
}


// --------------------------------------------------------------------
/**
SET WALLET(optional)

This command will set the wallet filename in the configuration.
Use this command to change what wallet will be loaded with the
"LOAD WALLET" command.

e.g. SetWallet("wallet2.xml");

*/
bool OTAPI_Wrap::SetWallet(const string & strWalletFilename)
{
	bool bIsInitialized = OTAPI_Wrap::OTAPI()->IsInitialized();
	if (!bIsInitialized)
	{
		OTLog::sError("%s: Error: OT_API not Initialized!!\n", __FUNCTION__);
		OT_ASSERT(false);
	}
	else
	{
		OTString sWalletFilename(strWalletFilename);

		if (sWalletFilename.Exists())
		{
			return OTAPI_Wrap::OTAPI()->SetWalletFilename(strWalletFilename);
		}
		else
		{
			OTLog::sError("%s: Error:: Wallet Filename is Null!\n", __FUNCTION__);
		}
		OT_ASSERT(false);
	}
	return false;
}


// --------------------------------------------------------------------
/**
WALLET EXISTS

Just Checks if the m_pWallet pointer is not null.

WalletExists();

*/
bool OTAPI_Wrap::WalletExists()
{
	return OTAPI_Wrap::OTAPI()->WalletExists();
}

// --------------------------------------------------------------------
/**
LOAD WALLET

Next you'll want to load your wallet up. It needs to be in the data_folder.
The filename is set in the configuration. Use "SET WALLET FILENAME" to change it.

The Default Filename is "wallet.xml"

LoadWallet();

*/
bool OTAPI_Wrap::LoadWallet()
{
return OTAPI_Wrap::OTAPI()->LoadWallet();
}


// --------------------------------------------------------------------
/**
SWITCH WALLET(experimental)

Experimental.
Set the new wallet with the "SET WALLET FILENAME" function.
Then call this function to switch to the new wallet.

*/
bool OTAPI_Wrap::SwitchWallet()
{
return OTAPI_Wrap::OTAPI()->LoadWallet();
}


// --------------------------------------------------------------------
/** Output to the screen(stderr.)
(This is so stdout can be left clean for the ACTUAL output.)
Log level is 0(least verbose) to 5(most verbose.)
*/
void OTAPI_Wrap::Output(
	const int32_t & nLogLevel,
	const string & strOutput
	)
{
	const OTString sOutput(strOutput.empty() ? "\n" : strOutput);
	OTLog::Output(nLogLevel, sOutput.Get());
}


// --------------------------------------------------------------------
/** TIME(in seconds, as string)

This will return the current time in seconds, as a string.
Returns NULL if failure.

Todo: consider making this available on the server side as well,
so the smart contracts can see what time it is.

*/
int64_t OTAPI_Wrap::GetTime()
{
	return OTAPI_Wrap::OTAPI()->GetTime();
}


/**
These 2 functions aren't in the OT_API proper, but are only available inside
the OTScripts on the client side.(They're not available in server-side
scripts, and they're not available in, for example, the OTAPI_Wrap Java programmable
int32_terface. You would use Java functions at that point32_t.)
Shown here only for reference.
*/
// String OT_CLI_ReadLine(void); // Reads from cin until Newline.
// String OT_CLI_ReadUntilEOF(void); // Reads from cin until EOF.




// ********************************************************************


//OTNumList is a class that encapsulates working with a comma-separated list
// of long int32_tegers, stored in a set and easily serializable in/out of a string.
//(It's useful.)
//
string OTAPI_Wrap::NumList_str(
	const set<long> & setNumList
	)
{
	if (setNumList.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "setNumList"			); OT_ASSERT(false); }

	OTNumList theList(setNumList);

	OTString strNumList;
	theList.Output(strNumList);

	return strNumList.Get();
}

set<long> OTAPI_Wrap::NumList(
	const string & strNumList
	)
{
	if (strNumList.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "strNumList"			); OT_ASSERT(false); }

	OTNumList theList(strNumList);

	set<long> setNumList;
	theList.Output(setNumList);
	return setNumList;
}

set<long> OTAPI_Wrap::NumList_Add(
	const set<long> & setNumList,
	const set<long> & setNumbers
	)
{
	if (setNumbers.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "setNumbers"			); OT_ASSERT(false); }

	OTNumList theList(setNumbers);  // make a list of the numbers

	if (!setNumList.empty()) theList.Add(setNumList); // if we had a pre-existing numbers, add them also.

	set<long> ret_setNumList;
	theList.Output(ret_setNumList);
	return ret_setNumList;
}

set<long> OTAPI_Wrap::NumList_Remove(
	const set<long> & setNumList,
	const set<long> & setNumbers
	)
{
	if (setNumList.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "setNumList"			); OT_ASSERT(false); }
	if (setNumbers.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "setNumbers"			); OT_ASSERT(false); }

	OTNumList theList(setNumList);  // make a list of the numbers

	if (theList.Remove(setNumbers))  // remove the numbers in setNumbers
	{
		set<long> ret_setNumList;
		theList.Output(ret_setNumList);
		return ret_setNumList;
	}
	else return set<long>();
}

bool OTAPI_Wrap::NumList_VerifyQuery(
	const set<long> & setNumList,
	const set<long> & setNumbers
	)
{
	if (setNumList.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "setNumList"			); OT_ASSERT(false); }
	if (setNumbers.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "setNumbers"			); OT_ASSERT(false); }

	OTNumList theList(setNumList);  // make a list of the numbers

	return theList.Verify(setNumbers);  // verify that the set contains these entries.
}

bool OTAPI_Wrap::NumList_VerifyAll(
	const set<long> & setNumList,
	const set<long> & setNumbers
	)
{
	if (setNumList.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "setNumList"			); OT_ASSERT(false); }
	if (setNumbers.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "setNumbers"			); OT_ASSERT(false); }

	if (setNumList.size() != setNumbers.size()) return false;

	OTNumList theList(setNumList);  // make a list of the numbers
	return theList.Verify(setNumbers);  // verify that the set contains these entries.
}

int32_t OTAPI_Wrap::NumList_Count(
		const set<long> & setNumList
		)
{
	return static_cast<int32_t> (setNumList.size());
}

// --------------------------------------------------------------------
/** OT-encode a plaint32_text string.

string Encode(const string & strPlaint32_text);

This will pack, compress, and base64-encode a plain string.
Returns the base64-encoded string, or NULL.

int32_ternally: 
OTString strPlain(strPlaint32_text);
OTASCIIArmor ascEncoded(thePlaint32_text); // ascEncoded now contains the OT-encoded string.
return ascEncoded.Get(); // We return it.
*/
string OTAPI_Wrap::Encode(
	const string & strPlaint32_text,
	bool bLineBreaks
	)
{
	if (strPlaint32_text.empty())		{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "strPlaint32_text"		); OT_ASSERT(false); }

	const	OTString strPlaintext(strPlaint32_text);
	OTString strOutput;

	bool bEncoded = OTAPI_Wrap::OTAPI()->Encode(strPlaintext, strOutput, bLineBreaks);

	if (!bEncoded)
		return"";

	return strOutput.Get();
}


// --------------------------------------------------------------------
/** Decode an OT-encoded string(back to plaint32_text.)

string Decode(const string & strEncoded);

This will base64-decode, uncompress, and unpack an OT-encoded string.
Returns the plaint32_text string, or NULL.

int32_ternally: 
OTASCIIArmor ascEncoded(strEncoded);
OTString strPlain(ascEncoded); // strPlain now contains the decoded plaint32_text string.
return strPlain.Get(); // We return it.
*/

string OTAPI_Wrap::Decode(
	const string & strEncoded,
	bool bLineBreaks
	)
{
	if (strEncoded.empty())		{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "strEncoded"		); OT_ASSERT(false); }

	const	OTString sEncoded(strEncoded);
	OTString strOutput;

	bool bDecoded = OTAPI_Wrap::OTAPI()->Decode(sEncoded, strOutput, bLineBreaks);

	if (!bDecoded)
		return"";

	return strOutput.Get();
}


// --------------------------------------------------------------------
/** OT-ENCRYPT a plaint32_text string.(ASYMMETRIC)

string Encrypt(const string & RECIPIENT_NYM_ID, string strPlaint32_text);

This will encode, ENCRYPT, and encode a plain string.
Returns the base64-encoded ciphertext, or NULL.

int32_ternally the C++ code is: 
OTString strPlain(strPlaint32_text);
OTEnvelope theEnvelope; 
if(theEnvelope.Seal(RECIPIENT_NYM, strPlain)) { // Now it's encrypted(in binary form, inside the envelope), to the recipient's nym.
OTASCIIArmor ascCiphertext(theEnvelope); // ascCiphertext now contains the base64-encoded ciphertext(as a string.)
return ascCiphertext.Get();
}
*/
string OTAPI_Wrap::Encrypt(
	const string & RECIPIENT_NYM_ID,
	const string & strPlaint32_text
	)
{
	if (RECIPIENT_NYM_ID.empty())		{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "RECIPIENT_NYM_ID"		); OT_ASSERT(false); }
	if (strPlaint32_text.empty())		{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "strPlaint32_text"		); OT_ASSERT(false); }

	const	OTString strRECIPIENT_NYM_ID(RECIPIENT_NYM_ID);
	const	OTString strPlaintext(strPlaint32_text);
	OTString strOutput;

	bool bEncrypted = OTAPI_Wrap::OTAPI()->Encrypt(strRECIPIENT_NYM_ID,strPlaintext, strOutput);

	if (!bEncrypted)
		return"";

	return strOutput.Get();
}


// --------------------------------------------------------------------
/** OT-DECRYPT an OT-encrypted string back to plaint32_text.(ASYMMETRIC)

string Decrypt(const string & RECIPIENT_NYM_ID, string strCiphertext);

Decrypts the base64-encoded ciphertext back int32_to a normal string plaint32_text.
Returns the plaint32_text string, or NULL.

int32_ternally the C++ code is: 
OTEnvelope theEnvelope;  // Here is the envelope object.(The ciphertext IS the data for an OTEnvelope.)
OTASCIIArmor ascCiphertext(strCiphertext); // The base64-encoded ciphertext passed in. Next we'll try to attach it to envelope object...
if(theEnvelope.SetAsciiArmoredData(ascCiphertext)) { // ...so that we can open it using the appropriate Nym, int32_to a plain string object:
OTString strServerReply;  // This will contain the output when we're done.
const bool bOpened =  // Now we try to decrypt:
theEnvelope.Open(RECIPIENT_NYM, strServerReply);
if(bOpened) {
return strServerReply.Get();
}
}
*/
string OTAPI_Wrap::Decrypt(
	const string & RECIPIENT_NYM_ID,
	const string & strCiphertext
	)
{
	if (RECIPIENT_NYM_ID.empty())		{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "RECIPIENT_NYM_ID"		); OT_ASSERT(false); }
	if (strCiphertext.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "strCiphertext"			); OT_ASSERT(false); }

	const	OTString strRECIPIENT_NYM_ID(RECIPIENT_NYM_ID);
	const	OTString strCipher_text(strCiphertext);
	OTString strOutput;

	bool bDecrypted = OTAPI_Wrap::OTAPI()->Decrypt(strRECIPIENT_NYM_ID,strCipher_text, strOutput);

	if (!bDecrypted)
		return"";

	return strOutput.Get();
}


// --------------------------------------------------------------------

// Generates a new symmetric key, based on a passphrase,
// and returns it(or NULL.)
//
string OTAPI_Wrap::CreateSymmetricKey()
{
	char  throwaway_text[OT_DEFAULT_BLOCKSIZE];
	for (int tt = 0; tt < OT_DEFAULT_BLOCKSIZE; ++tt)
	{
		throwaway_text[tt] = 'A'; // todo optimization...
	}
	throwaway_text[OT_DEFAULT_BLOCKSIZE-1] = '\0';
	// We don't use the above memory, except to force OTPassword to create itself
	// at a certain password size, so we can pass that buffer and size on to souped_up_pass_cb
	//
	OTPassword  passUserInput(&(throwaway_text[0]), OT_DEFAULT_BLOCKSIZE-1); // text mode.
	// -----------------------------------------------    
	const char *    szDisplay = "Creating new symmetric Key.";
	OTPasswordData  thePWData(szDisplay);
	thePWData.setUsingOldSystem(); // So the master key doesn't interfere, since this is for a plain symmetric key.
	OTString strOutput;
	bool bSuccess = false;

	const int nCallback = OTAsymmetricKey::GetPasswordCallback()(passUserInput.getPasswordWritable_char(),
		passUserInput.getBlockSize(),
		1, // bVerifyTwice ? 1 : 0, 
		static_cast<void *>(&thePWData));

	if (nCallback > 0) // Success retrieving the passphrase from the user. (Now let's generate the key...)
	{        
		OTLog::sOutput(3, "%s: Calling OTSymmetricKey theKey.GenerateKey()...\n", __FUNCTION__);
		OTSymmetricKey theKey(passUserInput);
		bool bGenerated = theKey.IsGenerated();
		//      OTLog::sOutput(0, "%s: Finished calling OTSymmetricKey theKey.GenerateKey()...\n", __FUNCTION__);

		if (bGenerated && theKey.SerializeTo(strOutput))
			bSuccess = true;
		else
			OTLog::sOutput(1,"%s: Sorry, unable to generate key. (Failure.)\n", __FUNCTION__);
	}
	else
		OTLog::sOutput(1,"%s: Sorry, unable to retrieve password from user. (Failure.)\n", __FUNCTION__);

	if (!bSuccess)
		return "";

	return strOutput.Get();
}

string OTAPI_Wrap::SymmetricEncrypt(
	const string & SYMMETRIC_KEY,
	const string & PLAINTEXT
	)
{
	if (SYMMETRIC_KEY.empty())		{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "SYMMETRIC_KEY"			); OT_ASSERT(false); }
	if (PLAINTEXT.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "PLAINTEXT"			); OT_ASSERT(false); }

	// ---------------------------
	OTASCIIArmor ascOutput;
	bool bSuccess = false;
	// ---------------------------
	const OTString strPlaintext(PLAINTEXT);
	const OTString strKey(SYMMETRIC_KEY);

	if (!strKey.Exists() || !strPlaintext.Exists())
	{
		OTLog::sOutput(1,"%s: Nonexistent: either the key or the plaintext. Please supply. (Failure.)\n",
			__FUNCTION__);
		return "";
	}
	// -----------------------------------
	OTSymmetricKey theKey;

	if (false == theKey.SerializeFrom(strKey))
	{    
		OTLog::sOutput(1,"%s: Failed trying to load symmetric key from string. (Returning NULL.)\n",
			__FUNCTION__);
		return "";
	}
	// -----------------------------------
	// By this point, we know we have a plaintext and a symmetric Key.
	//
	char  throwaway_text[OT_DEFAULT_BLOCKSIZE];
	for (int tt = 0; tt < OT_DEFAULT_BLOCKSIZE; ++tt)
	{
		throwaway_text[tt] = 'A';
	}
	throwaway_text[OT_DEFAULT_BLOCKSIZE-1] = '\0';
	// We don't use the above memory, except to force OTPassword to create itself
	// at a certain password size, so we can pass that buffer and size on to souped_up_pass_cb
	//
	OTPassword  passUserInput(&(throwaway_text[0]), OT_DEFAULT_BLOCKSIZE-1); // text mode.
	// -----------------------------------------------    
	const char *    szDisplay = "OT_API_SymmetricEncrypt";
	OTPasswordData  thePWData(szDisplay);
	thePWData.setUsingOldSystem(); // So the master key doesn't interfere, since this is for a plain symmetric key.        
	const int nCallback = OTAsymmetricKey::GetPasswordCallback()(passUserInput.getPasswordWritable_char(),
		passUserInput.getBlockSize(),
		0, // bVerifyTwice ? 1 : 0, 
		static_cast<void *>(&thePWData));

	if (nCallback > 0) // Success retrieving the passphrase from the user. (Now let's encrypt...)
	{
		OTEnvelope theEnvelope;

		if (theEnvelope.Encrypt(strPlaintext, theKey, passUserInput) &&
			theEnvelope.GetAsciiArmoredData(ascOutput))
		{
			bSuccess = true;
		}
		else
		{
			OTLog::sOutput(1,"%s: Failed trying to encrypt. (Sorry.)\n",
				__FUNCTION__);
			return "";
		}
	}
	else
		OTLog::sOutput(1,"%s: Sorry, unable to retrieve passphrase from user. (Failure.)\n", 
		__FUNCTION__);

	if (!bSuccess)
		return "";

	return ascOutput.Get();
}

string OTAPI_Wrap::SymmetricDecrypt(
	const string & SYMMETRIC_KEY,
	const string & CIPHERTEXT_ENVELOPE
	)
{
	if (SYMMETRIC_KEY.empty())		{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "SYMMETRIC_KEY"		); OT_ASSERT(false); }
	if (CIPHERTEXT_ENVELOPE.empty()){ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "CIPHERTEXT_ENVELOPE"); OT_ASSERT(false); }
	// ---------------------------
	OTString strOutput;
	bool bSuccess = false;
	// ---------------------------
	OTString strInput(CIPHERTEXT_ENVELOPE);
	OTASCIIArmor ascArmor;

	const bool bBookends = strInput.Contains("-----BEGIN"); 

	if (bBookends)
	{
		const bool bEscaped = strInput.Contains("- -----BEGIN");

		if (!ascArmor.LoadFromString(strInput, bEscaped))
		{
			OTLog::sError("%s: Failure loading string into OTASCIIArmor object:\n\n%s\n\n",
				__FUNCTION__, strInput.Get());
			return "";
		}
	}
	else
		ascArmor.Set(strInput.Get());
	// -------------------------------    
	if (!ascArmor.Exists())
	{
		OTLog::sOutput(1,"%s: Nonexistent: the ciphertext envelope. Please supply. (Failure.)\n",
			__FUNCTION__);
		return "";
	}
	// -----------------------------------
	const OTString strKey(SYMMETRIC_KEY);

	if (!strKey.Exists())
	{
		OTLog::sOutput(1,"%s: Nonexistent: The symmetric key. Please supply. (Failure.)\n",
			__FUNCTION__);
		return "";
	}
	// -----------------------------------
	OTSymmetricKey theKey;

	if (false == theKey.SerializeFrom(strKey))
	{    
		OTLog::sOutput(1,"%s: Failed trying to load symmetric key from string. (Returning NULL.)\n",
			__FUNCTION__);
		return "";
	}
	// -----------------------------------
	// By this point, we know we have a ciphertext envelope and a symmetric Key.
	//
	char  throwaway_text[OT_DEFAULT_BLOCKSIZE];
	for (int tt = 0; tt < OT_DEFAULT_BLOCKSIZE; ++tt)
	{
		throwaway_text[tt] = 'A';
	}
	throwaway_text[OT_DEFAULT_BLOCKSIZE-1] = '\0';
	// We don't use the above memory, except to force OTPassword to create itself
	// at a certain password size, so we can pass that buffer and size on to souped_up_pass_cb
	//
	OTPassword  passUserInput(&(throwaway_text[0]), OT_DEFAULT_BLOCKSIZE-1); // text mode.
	// -----------------------------------------------    
	const char *    szDisplay = "OT_API_SymmetricDecrypt";
	OTPasswordData  thePWData(szDisplay);
	thePWData.setUsingOldSystem(); // So the master key doesn't interfere, since this is for a plain symmetric key.
	const int nCallback = OTAsymmetricKey::GetPasswordCallback()(passUserInput.getPasswordWritable_char(),
		passUserInput.getBlockSize(),
		0, // bVerifyTwice ? 1 : 0, 
		static_cast<void *>(&thePWData));

	if (nCallback > 0) // Success retrieving the passphrase from the user. (Now let's encrypt...)
	{
		OTEnvelope theEnvelope(ascArmor);

		if (theEnvelope.Decrypt(strOutput, theKey, passUserInput))
		{
			bSuccess = true;
		}
		else
		{
			OTLog::sOutput(1,"%s: Failed trying to decrypt. (Sorry.)\n",
				__FUNCTION__);
			return "";
		}
	}
	else
		OTLog::sOutput(1,"%s: Sorry, unable to retrieve passphrase from user. (Failure.)\n", 
		__FUNCTION__);

	if (!bSuccess)
		return "";

	return strOutput.Get();
}


// --------------------------------------------------------------------
/** OT-Sign a CONTRACT.(First signature)

string SignContract(const string & SIGNER_NYM_ID, string THE_CONTRACT);

Tries to instantiate the contract object, based on the string passed in.
Releases all signatures, and then signs the contract.
Returns the signed contract, or NULL if failure.

NOTE: The actual OT functionality(Use Cases) NEVER requires you to sign via
this function. Why not? because, anytime a signature is needed on something,
the relevant OT API call will require you to pass in the Nym, and the API already
signs int32_ternally wherever it deems appropriate. Thus, this function is only for
advanced uses, for OT-Scripts, server operators, etc.

*/
string OTAPI_Wrap::SignContract(
	const string & SIGNER_NYM_ID,
	const string & THE_CONTRACT
	)
{	
	if (SIGNER_NYM_ID.empty())		{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "SIGNER_NYM_ID"		); OT_ASSERT(false); }
	if (THE_CONTRACT.empty())		{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_CONTRACT"		); OT_ASSERT(false); }
	// --------------------------------------------------------------------
	const OTString		strContract(THE_CONTRACT);
	const OTIdentifier	theSignerNymID(SIGNER_NYM_ID);
	// --------------------------------------------------------------------
	OTString strOutput;

	bool bSigned  = OTAPI_Wrap::OTAPI()->SignContract(theSignerNymID, strContract, strOutput);

	if (!bSigned || !strOutput.Exists())
		return "";

	return strOutput.Get();
}


// --------------------------------------------------------------------
/** OT-Sign a CONTRACT.(Add a signature)

string AddSignature(const string & SIGNER_NYM_ID, string THE_CONTRACT);

Tries to instantiate the contract object, based on the string passed in.
Signs the contract, without releasing any signatures that are already there.
Returns the signed contract, or NULL if failure.

NOTE: The actual OT functionality(Use Cases) NEVER requires you to sign via
this function. Why not? because, anytime a signature is needed on something,
the relevant OT API call will require you to pass in the Nym, and the API already
signs int32_ternally wherever it deems appropriate. Thus, this function is only for
advanced uses, for OT-Scripts, server operators, etc.

*/
string OTAPI_Wrap::AddSignature(
	const string & SIGNER_NYM_ID,
	const string & THE_CONTRACT
	)
{
	if (SIGNER_NYM_ID.empty())		{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "SIGNER_NYM_ID"		); OT_ASSERT(false); }
	if (THE_CONTRACT.empty())		{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_CONTRACT"		); OT_ASSERT(false); }
	// --------------------------------------------------------------------
	const OTString		strContract(THE_CONTRACT);
	const OTIdentifier	theSignerNymID(SIGNER_NYM_ID);
	// --------------------------------------------------------------------
	OTString strOutput;

	bool bSigned  = OTAPI_Wrap::OTAPI()->AddSignature(theSignerNymID, strContract, strOutput);

	if (!bSigned || !strOutput.Exists())
		return "";

	return strOutput.Get();
}


// --------------------------------------------------------------------
/** OT-Verify the signature on a CONTRACT.

*/
bool OTAPI_Wrap::VerifySignature(
	const string & SIGNER_NYM_ID,
	const string & THE_CONTRACT
	)
{
	if (SIGNER_NYM_ID.empty())		{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "SIGNER_NYM_ID"		); OT_ASSERT(false); }
	if (THE_CONTRACT.empty())		{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_CONTRACT"		); OT_ASSERT(false); }
	// -----------------------------------------------------	
	const OTString		strContract(THE_CONTRACT);
	const OTIdentifier	theNymID(SIGNER_NYM_ID);
	// -----------------------------------------------------
	const bool bVerified = OTAPI_Wrap::OTAPI()->VerifySignature(strContract, theNymID); /*ppContract=NULL (optional third parameter for retrieving loaded contract.)*/
	// -----------------------------------------------------	
	return bVerified;
}


std::string OTAPI_Wrap::FlatSign(std::string SIGNER_NYM_ID, std::string THE_INPUT, std::string CONTRACT_TYPE)
{
	OTIdentifier ID(SIGNER_NYM_ID);
	OTString strOutput = "";
	const bool bSuccess = OTAPI_Wrap::It()-> p_OTAPI -> FlatSign(ID, THE_INPUT, CONTRACT_TYPE, strOutput);

	if (bSuccess) return strOutput.Get();
	else return "";
}


// --------------------------------------------------
// Verify and Retrieve XML Contents.
//
// Pass in a contract and a user ID, and this function will:
// -- Load the contract up and verify it.(Most classes in OT
// are derived in some way from OTContract.)
// -- Verify the user's signature on it.
// -- Remove the PGP-style bookends(the signatures, etc)
// and return the XML contents of the contract in string form. <==
//
string OTAPI_Wrap::VerifyAndRetrieveXMLContents(
	const string & THE_CONTRACT,
	const string & SIGNER_ID
	)

{
	if (THE_CONTRACT.empty())		{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_CONTRACT"		); OT_ASSERT(false); }
	if (SIGNER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "SIGNER_ID"			); OT_ASSERT(false); }

	// -----------------------------------------------------
	const OTString		strContract(THE_CONTRACT);
	const OTIdentifier	theSignerID(SIGNER_ID);
	// -----------------------------------------------------
	OTString strOutput;

	if (false == OTAPI_Wrap::OTAPI()->VerifyAndRetrieveXMLContents(strContract, theSignerID, strOutput))
	{
		OTLog::sOutput(0, "%s: Failure: OTAPI_Wrap::OTAPI()->VerifyAndRetrieveXMLContents() returned false.\n",__FUNCTION__);
		return "";
	}
	// -----------------------------------------------------		
	return strOutput.Get();	
}


// ----------------------------------------------------
/** The below functions are for retrieving log data programatically.
*/
int32_t OTAPI_Wrap::GetMemlogSize() { return OTLog::GetMemlogSize(); }

string OTAPI_Wrap::GetMemlogAtIndex(const int32_t nIndex) { OTString s = OTLog::GetMemlogAtIndex(nIndex); return s.Get(); }

string OTAPI_Wrap::PeekMemlogFront() {  OTString s = OTLog::PeekMemlogFront(); return s.Get(); }
string OTAPI_Wrap::PeekMemlogBack() { OTString s = OTLog::PeekMemlogBack(); return s.Get(); }

bool OTAPI_Wrap::PopMemlogFront() { return OTLog::PopMemlogFront(); }
bool OTAPI_Wrap::PopMemlogBack() {return OTLog::PopMemlogBack(); }


// --------------------------------------------------
// CREATE NYM -- Create new User
//
// Creates a new Nym and adds it to the wallet.
//(Including PUBLIC and PRIVATE KEYS.)
//
// Returns a new User ID(with files already created)
// or NULL upon failure.
//
// Once it exists, use createUserAccount() to
// register your new Nym at any given Server.(Nearly all
// server requests require this...)
//
string OTAPI_Wrap::CreateNym(const int32_t nKeySize) // must be 1024, 2048, 4096, or 8192 
{
	if (0 == nKeySize)	{ OTLog::sError("%s: Keysize is 0, will fail!!\n"	,__FUNCTION__); OT_ASSERT(false);}

	// -----------------------------------------------------
	OTPseudonym *  pNym(OTAPI_Wrap::OTAPI()->CreateNym(nKeySize));
	if (NULL == pNym) // Creation failed.
	{
		OTLog::sOutput(0, "%s: Failed trying to create Nym.\n", __FUNCTION__);
		return "";		
	}
	// -----------------------------------------------------}
	OTString strOutput;	
	pNym->GetIdentifier(strOutput); // We're returning the new Nym ID.
	// --------------------------------
	return strOutput.Get();
}


// Creates a contract based on the contents passed in, 
// then sets the contract key based on the NymID,
// and signs it with that Nym.
// This function will also ADD the contract to the wallet.
// Returns: the new contract ID, or NULL if failure.
//
string OTAPI_Wrap::CreateServerContract(
	const string & NYM_ID,
	const string & strXMLcontents
	)
{
	// -----------------------------------------------------
	bool bInitialized = OTAPI_Wrap::OTAPI()->IsInitialized();
	if (!bInitialized) { OTLog::sError("%s: Not initialized; call OT_API::Init first.\n",__FUNCTION__);	OT_ASSERT(false); }

	if (NYM_ID.empty())				{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "NYM_ID"				); OT_ASSERT(false); }
	if (strXMLcontents.empty())		{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "szXMLcontents"		); OT_ASSERT(false); }
	// -----------------------------------------------------

	// -----------------------------------------------------
	const OTIdentifier theNymID(NYM_ID);
	OTPseudonym *  pNym(OTAPI_Wrap::OTAPI()->GetNym(theNymID, __FUNCTION__));
	if (NULL == pNym) return "";
	// -------------------------------------------    
	string str_Trim(strXMLcontents);
	string str_Trim2 = OTString::trim(str_Trim);
	OTString strContract(str_Trim2.c_str());

	if (strContract.GetLength() < 2)
	{
		OTLog::sOutput(0, "%s: Empty XML contents passed in! (Failure.)\n", __FUNCTION__);
		return "";
	}
	// -------------------------------------------    
	std::tr1::shared_ptr<OTServerContract> pContract(new OTServerContract());

	OT_ASSERT(NULL != pContract);

	pContract->CreateContract(strContract, *pNym); // <==========  **** CREATE CONTRACT!! ****
	// -------------------------------------------
	// But does it meet our requirements?
	//
	const OTPseudonym * pContractKeyNym = pContract->GetContractPublicNym();
	//  const OTAsymmetricKey * pKey = pContract->GetContractPublicKey();

	if (NULL == pContractKeyNym)
	{
		OTLog::sOutput(0, "%s: Missing 'key' tag with name=\"contract\" and text value containing "
			"the public cert or public key of the signer Nym. (Please add it first. Failure.)\n",
			__FUNCTION__);
		return "";
	}
	else if (false == pNym->CompareID(*pContractKeyNym))
	{
		OTLog::sOutput(0, "%s: Found 'key' tag with name=\"contract\" and text value, but it apparently does NOT contain "
			"the public cert or public key of the signer Nym. Please fix that first; see the sample data. (Failure.)\n",
			__FUNCTION__);
		return "";
	}
	/*
	<key name="contract">
	- -----BEGIN CERTIFICATE-----
	MIICZjCCAc+gAwIBAgIJAO14L19TJgzcMA0GCSqGSIb3DQEBBQUAMFcxCzAJBgNV
	BAYTAlVTMREwDwYDVQQIEwhWaXJnaW5pYTEQMA4GA1UEBxMHRmFpcmZheDERMA8G
	A1UEChMIWm9yay5vcmcxEDAOBgNVBAMTB1Jvb3QgQ0EwHhcNMTAwOTI5MDUyMzAx
	WhcNMjAwOTI2MDUyMzAxWjBeMQswCQYDVQQGEwJVUzERMA8GA1UECBMIVmlyZ2lu
	aWExEDAOBgNVBAcTB0ZhaXJmYXgxETAPBgNVBAoTCFpvcmsub3JnMRcwFQYDVQQD
	Ew5zaGVsbC56b3JrLm9yZzCBnzANBgkqhkiG9w0BAQEFAAOBjQAwgYkCgYEA3vD9
	fO4ov4854L8wXrgfv2tltDz0ieVrTNSLuy1xuQyb//+MwZ0EYwu8jMMQrqbUaYG6
	y8zJu32yBKrBNPPwJ+fJE+tfgVg860dGVbwMd4KhpkKtppJXmZaGqLqvELaXa4Uw
	9N3qg/faj0NMEDIBhv/tD/B5U65vH+U0JlRJ07kCAwEAAaMzMDEwCQYDVR0TBAIw
	ADAkBgNVHREEHTAbgg5zaGVsbC56b3JrLm9yZ4IJbG9jYWxob3N0MA0GCSqGSIb3
	DQEBBQUAA4GBALLXPa/naWsiXsw0JwlSiG7aOmvMF2romUkcr6uObhN7sghd38M0
	l2kKTiptnA8txrri8RhqmQgOgiyKFCKBkxY7/XGot62cE8Y1+lqGXlhu2UHm6NjA
	pRKvng75J2HTjmmsbCHy+nexn4t44wssfPYlGPD8sGwmO24u9tRfdzJE
	- -----END CERTIFICATE-----
	</key>
	*/
	// -------------------------------------------
	OTString strHostname; int nPort=0;

	if (false == pContract->GetConnectInfo(strHostname, nPort))
	{
		OTLog::sOutput(0, "%s: Unable to retrieve connection info from this contract. Please "
			"fix that first; see the sample data. (Failure.)\n", __FUNCTION__);
		return "";
	}
	// -------------------------------------------
	// By this point, we know that the "contract" key is properly attached
	// to the raw XML contents, AND that the NymID for that key matches
	// the NymID passed into this function.
	// We also know that the connect info was properly attached to this
	// server contract.
	// So we can proceed to add it to the wallet...
	//
	// -----------------------------------------------------
	OTString strOutput;
	pContract->GetIdentifier(strOutput);

	OTAPI_Wrap::OTAPI()->AddServerContract(*pContract);

	// -------------------------------------------
	return strOutput.Get();
}


string OTAPI_Wrap::CreateAssetContract(
	const string & NYM_ID,
	const string & strXMLcontents
	)
{
	// -----------------------------------------------------
	bool bInitialized = OTAPI_Wrap::OTAPI()->IsInitialized();
	if (!bInitialized) { OTLog::sError("%s: Not initialized; call OT_API::Init first.\n",__FUNCTION__);	OT_ASSERT(false); }

	if (NYM_ID.empty())				{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "NYM_ID"				); OT_ASSERT(false); }
	if (strXMLcontents.empty())		{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "szXMLcontents"		); OT_ASSERT(false); }
	// -----------------------------------------------------

	const OTIdentifier theNymID(NYM_ID);
	OTPseudonym *  pNym(OTAPI_Wrap::OTAPI()->GetNym(theNymID, __FUNCTION__));
	if (NULL == pNym) return "";
	// -------------------------------------------    
	string str_Trim(strXMLcontents);
	string str_Trim2 = OTString::trim(str_Trim);
	OTString strContract(str_Trim2.c_str());

	if (strContract.GetLength() < 2)
	{
		OTLog::sOutput(0, "%s: Empty XML contents passed in! (Failure.)\n", __FUNCTION__);
		return "";
	}
	// -------------------------------------------    
	OTAssetContract * pContract = new OTAssetContract;
	OT_ASSERT(NULL != pContract);
	OTCleanup<OTAssetContract> theAngel(*pContract);
	pContract->CreateContract(strContract, *pNym); // <==========  **** CREATE CONTRACT!! ****
	// -------------------------------------------
	// But does it meet our requirements?
	//
	const OTPseudonym * pContractKeyNym = pContract->GetContractPublicNym();
	//  const OTAsymmetricKey * pKey = pContract->GetContractPublicKey();

	if (NULL == pContractKeyNym)
	{
		OTLog::sOutput(0, "%s: Missing 'key' tag with name=\"contract\" and text value containing "
			"the public cert or public key of the signer Nym. (Please add it first. Failure.)\n", 
			__FUNCTION__);
		return "";
	}
	else if (false == pNym->CompareID(*pContractKeyNym))
	{
		OTLog::sOutput(0, "%s: Found 'key' tag with name=\"contract\" and text value, but it apparently does NOT contain "
			"the public cert or public key of the signer Nym. Please fix that first; see the sample data. (Failure.)\n",
			__FUNCTION__);
		return "";
	}
	/*
	<key name="contract">
	- -----BEGIN CERTIFICATE-----
	MIICZjCCAc+gAwIBAgIJAO14L19TJgzcMA0GCSqGSIb3DQEBBQUAMFcxCzAJBgNV
	BAYTAlVTMREwDwYDVQQIEwhWaXJnaW5pYTEQMA4GA1UEBxMHRmFpcmZheDERMA8G
	A1UEChMIWm9yay5vcmcxEDAOBgNVBAMTB1Jvb3QgQ0EwHhcNMTAwOTI5MDUyMzAx
	WhcNMjAwOTI2MDUyMzAxWjBeMQswCQYDVQQGEwJVUzERMA8GA1UECBMIVmlyZ2lu
	aWExEDAOBgNVBAcTB0ZhaXJmYXgxETAPBgNVBAoTCFpvcmsub3JnMRcwFQYDVQQD
	Ew5zaGVsbC56b3JrLm9yZzCBnzANBgkqhkiG9w0BAQEFAAOBjQAwgYkCgYEA3vD9
	fO4ov4854L8wXrgfv2tltDz0ieVrTNSLuy1xuQyb//+MwZ0EYwu8jMMQrqbUaYG6
	y8zJu32yBKrBNPPwJ+fJE+tfgVg860dGVbwMd4KhpkKtppJXmZaGqLqvELaXa4Uw
	9N3qg/faj0NMEDIBhv/tD/B5U65vH+U0JlRJ07kCAwEAAaMzMDEwCQYDVR0TBAIw
	ADAkBgNVHREEHTAbgg5zaGVsbC56b3JrLm9yZ4IJbG9jYWxob3N0MA0GCSqGSIb3
	DQEBBQUAA4GBALLXPa/naWsiXsw0JwlSiG7aOmvMF2romUkcr6uObhN7sghd38M0
	l2kKTiptnA8txrri8RhqmQgOgiyKFCKBkxY7/XGot62cE8Y1+lqGXlhu2UHm6NjA
	pRKvng75J2HTjmmsbCHy+nexn4t44wssfPYlGPD8sGwmO24u9tRfdzJE
	- -----END CERTIFICATE-----
	</key>
	*/
	// -------------------------------------------
	// By this point, we know that the "contract" key is properly attached
	// to the raw XML contents, AND that the NymID for that key matches
	// the NymID passed into this function.
	// So we can proceed to add it to the wallet...
	//
	// -----------------------------------------------------
	OTString strOutput;
	pContract->GetIdentifier(strOutput);

	OTAPI_Wrap::OTAPI()->AddAssetContract(*pContract);
	theAngel.SetCleanupTargetPointer(NULL); // (No need to cleanup anymore.)
	pContract = NULL; // Success. The wallet "owns" it now, no need to clean it up.
	// -------------------------------------------
	return strOutput.Get();
}


bool  OTAPI_Wrap::Wallet_ChangePassphrase()
{
    return OTAPI_Wrap::OTAPI()->Wallet_ChangePassphrase();

}


const std::string OTAPI_Wrap::Wallet_ImportNym(const std::string FILE_CONTENTS)
{
	bool bInitialized = OTAPI_Wrap::OTAPI()->IsInitialized();
	if (!bInitialized) { OTLog::vError("%s: Not initialized; call OT_API::Init first.\n",__FUNCTION__);	OT_ASSERT(false); }

	if (FILE_CONTENTS.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "FILE_CONTENTS"		); OT_ASSERT(false); }

	OTIdentifier ID;
    const bool bSuccess = OTAPI_Wrap::OTAPI()->Wallet_ImportNym(FILE_CONTENTS, &ID);

	if (bSuccess) {
	const OTString rID(ID);
	return rID.Get();
	}
	else return "";
}

const std::string OTAPI_Wrap::Wallet_ImportCert(const std::string DISPLAY_NAME, 
                                                const std::string FILE_CONTENTS)
{
	bool bInitialized = OTAPI_Wrap::OTAPI()->IsInitialized();
	if (!bInitialized) { OTLog::vError("%s: Not initialized; call OT_API::Init first.\n",__FUNCTION__);	OT_ASSERT(false); }

	if (DISPLAY_NAME.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "DISPLAY_NAME"		); OT_ASSERT(false); }
	if (FILE_CONTENTS.empty())		{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "FILE_CONTENTS"		); OT_ASSERT(false); }

	OTIdentifier ID;
    const bool bSuccess = OTAPI_Wrap::OTAPI()->Wallet_ImportCert(DISPLAY_NAME, FILE_CONTENTS, &ID);

	if (bSuccess) return OTString(ID).Get();
	else return "";
}


const std::string OTAPI_Wrap::Wallet_ExportNym(const std::string NYM_ID)
{
	bool bInitialized = OTAPI_Wrap::OTAPI()->IsInitialized();
	if (!bInitialized) { OTLog::vError("%s: Not initialized; call OT_API::Init first.\n",__FUNCTION__);	OT_ASSERT(false); }

	if (NYM_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "NYM_ID"			); OT_ASSERT(false); }

	OTIdentifier ID(NYM_ID);
	OTString strOutput = "";
	const bool bSuccess = OTAPI_Wrap::OTAPI()->Wallet_ExportNym(ID, strOutput);

	if (bSuccess) return strOutput.Get();
	else return "";
}

const std::string OTAPI_Wrap::Wallet_ExportCert(const std::string NYM_ID)
{
	bool bInitialized = OTAPI_Wrap::OTAPI()->IsInitialized();
	if (!bInitialized) { OTLog::vError("%s: Not initialized; call OT_API::Init first.\n",__FUNCTION__);	OT_ASSERT(false); }

	if (NYM_ID.empty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "NYM_ID"			); OT_ASSERT(false); }

	OTIdentifier ID(NYM_ID);
	OTString strOutput = "";
    const bool bSuccess = OTAPI_Wrap::OTAPI()->Wallet_ExportCert(ID,strOutput);
    
	if (bSuccess) return strOutput.Get();
	else return "";
}

// Use these below functions to get the new contract ITSELF, using its ID
// that was returned by the above two functions:
//
//string GetServer_Contract(const string & SERVER_ID); // Return's Server's contract(based on server ID)
//string GetAssetType_Contract(const string & ASSET_TYPE_ID); // Returns currency contract based on Asset Type ID

/*
---------------------------------

ASSET CONTRACTS will want to make sure they put something like this at the top:

<?xml version="1.0"?>
<digitalAssetContract version="1.0">

<entity shortname="Just testing" 
longname="I need user feedback to help design the contract tags the server must support..." 
email="F3llowTraveler(at) gmail.com"/>


// -----------------------------------

<issue company="Chuck-E-Cheese, Inc" 
email="games@chuckecheese.com"
contractUrl="https://chuckecheese.com/games/contract/"
type="currency"/>

<currency name="game tokens" tla="TOKEN" symbol="tks" type="decimal" factor="1" decimal_power="0" fraction="mg"/>


---------------------------------

SERVER CONTRACTS will want to make sure they put something like this at the top:

<?xml version="1.0"?>
<notaryProviderContract version="1.0">

<entity shortname="Transactions.com" 
longname="Transactions.com, LLC" 
email="serverfarm@cloudcomputing.com"
serverURL="https://transactions.com/vers/1/"/>

<notaryServer hostname="localhost" 
port="7085"
URL="https://transactions.com/vers/1/" />

---------------------------------


NEITHER has to worry about THIS, which is added automatically:


<key name="contract">
- -----BEGIN CERTIFICATE-----
MIICZjCCAc+gAwIBAgIJAO14L19TJgzcMA0GCSqGSIb3DQEBBQUAMFcxCzAJBgNV
BAYTAlVTMREwDwYDVQQIEwhWaXJnaW5pYTEQMA4GA1UEBxMHRmFpcmZheDERMA8G
A1UEChMIWm9yay5vcmcxEDAOBgNVBAMTB1Jvb3QgQ0EwHhcNMTAwOTI5MDUyMzAx
WhcNMjAwOTI2MDUyMzAxWjBeMQswCQYDVQQGEwJVUzERMA8GA1UECBMIVmlyZ2lu
aWExEDAOBgNVBAcTB0ZhaXJmYXgxETAPBgNVBAoTCFpvcmsub3JnMRcwFQYDVQQD
Ew5zaGVsbC56b3JrLm9yZzCBnzANBgkqhkiG9w0BAQEFAAOBjQAwgYkCgYEA3vD9
fO4ov4854L8wXrgfv2tltDz0ieVrTNSLuy1xuQyb//+MwZ0EYwu8jMMQrqbUaYG6
y8zJu32yBKrBNPPwJ+fJE+tfgVg860dGVbwMd4KhpkKtppJXmZaGqLqvELaXa4Uw
9N3qg/faj0NMEDIBhv/tD/B5U65vH+U0JlRJ07kCAwEAAaMzMDEwCQYDVR0TBAIw
ADAkBgNVHREEHTAbgg5zaGVsbC56b3JrLm9yZ4IJbG9jYWxob3N0MA0GCSqGSIb3
DQEBBQUAA4GBALLXPa/naWsiXsw0JwlSiG7aOmvMF2romUkcr6uObhN7sghd38M0
l2kKTiptnA8txrri8RhqmQgOgiyKFCKBkxY7/XGot62cE8Y1+lqGXlhu2UHm6NjA
pRKvng75J2HTjmmsbCHy+nexn4t44wssfPYlGPD8sGwmO24u9tRfdzJE
- -----END CERTIFICATE-----
</key>

*/



/*
string Contract_AddTag(const string & NYM_ID, string THE_CONTRACT,
string TAG_NAME, string SUBTAG_NAME, 
string SUBTAG_VALUE, string TAG_VALUE); 
key == TAG_NAME
name == SUBTAG_NAME
"contract" == SUBTAG_VALUE
<the cert> == TAG_VALUE

*/




// --------------------------------------------------
// ADD SERVER CONTRACT(to wallet)
//
// If you have a server contract that you'd like to add 
// to your wallet, call this function.
//
bool OTAPI_Wrap::AddServerContract(const string & strContract)
{
	if (strContract.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "szContract"			); OT_ASSERT(false); }


	// -----------------------------------------------------
	string str_Trim(strContract);
	string str_Trim2 = OTString::trim(str_Trim);
	OTString sContract(str_Trim2.c_str());
	// -----------------------------------------------------
	std::tr1::shared_ptr<OTServerContract> pContract(new OTServerContract());
	OT_ASSERT(NULL != pContract);

	// Check the server signature on the contract here. (Perhaps the message is good enough?
	// After all, the message IS signed by the server and contains the Account.
	//	if (pContract->LoadContract() && pContract->VerifyContract())
	if (sContract.Exists() && pContract->LoadContractFromString(strContract))
	{
		OTIdentifier theContractID;

		pContract->CalculateContractID(theContractID);
		pContract->SetIdentifier(theContractID);

		OTAPI_Wrap::OTAPI()->AddServerContract(*pContract);
	}


	return true;
}


// --------------------------------------------------
// ADD ASSET CONTRACT(to wallet)
//
// If you have an asset contract that you'd like to add 
// to your wallet, call this function.
//
bool OTAPI_Wrap::AddAssetContract(const string & strContract)
{
	if (strContract.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "strContract"			); OT_ASSERT(false); }

	// -----------------------------------------------------
	string str_Trim(strContract);
	string str_Trim2 = OTString::trim(str_Trim);
	OTString sContract(str_Trim2.c_str());

	OTAssetContract * pContract = new OTAssetContract;
	OT_ASSERT(NULL != pContract);

	// Check the server signature on the contract here. (Perhaps the message is good enough?
	// After all, the message IS signed by the server and contains the Account.
	//	if (pContract->LoadContract() && pContract->VerifyContract())
	if (sContract.Exists() && pContract->LoadContractFromString(strContract))
	{
		OTIdentifier theContractID;

		pContract->CalculateContractID(theContractID);
		pContract->SetIdentifier(theContractID);

		// Next make sure the wallet has this contract on its list...
		OTAPI_Wrap::OTAPI()->AddAssetContract(*pContract);
		pContract = NULL; // Success. The wallet "owns" it now, no need to clean it up.
	}
	// cleanup
	if (pContract)
	{
		delete pContract;
		pContract = NULL;

		return false;	
	}
	return true;	
}


// --------------------------------------------------

// NOTE: THE BELOW FUNCTIONS *DO NOT* SEND ANY MESSAGE TO THE SERVER,
// BUT RATHER, THEY ONLY QUERY FOR DATA FROM LOCAL STORAGE.
//
// Often a server response will cause a change to the data in local storage.
// These functions allow you to re-load that data so your GUI can reflect
// the updates to those files.
//
int32_t OTAPI_Wrap::GetServerCount() { return OTAPI_Wrap::OTAPI()->GetServerCount(); }
int32_t OTAPI_Wrap::GetAssetTypeCount() { return OTAPI_Wrap::OTAPI()->GetAssetTypeCount(); }
int32_t OTAPI_Wrap::GetAccountCount() { return OTAPI_Wrap::OTAPI()->GetAccountCount(); }
int32_t OTAPI_Wrap::GetNymCount() { return OTAPI_Wrap::OTAPI()->GetNymCount(); };


// based on Index(above 4 functions) this returns the Server's ID
string OTAPI_Wrap::GetServer_ID(const int32_t nIndex)
{
	if (0 > nIndex) { OTLog::sError("%s: nIndex is out of bounds (it's in the negative!)\n", __FUNCTION__); OT_ASSERT(false); }

	OTIdentifier	theID;
	OTString		strName;
	bool bGetServer = OTAPI_Wrap::OTAPI()->GetServer(nIndex, theID, strName);

	if (bGetServer)
	{
		OTString strID(theID);

		return strID.Get();	
	}
	return "";
}

// Return's Server's name(based on server ID)
string OTAPI_Wrap::GetServer_Name(const string & SERVER_ID)
{
	if (SERVER_ID.empty())				{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"				); OT_ASSERT(false); }
	OTIdentifier	theID(SERVER_ID);

	// -------------------------
	OTServerContract * pServer = OTAPI_Wrap::OTAPI()->GetServer(theID, __FUNCTION__);
	if (NULL == pServer) return "";
	// -------------------------
	OTString strName;
	pServer->GetName(strName);

	return strName.Get();
}

// Return's Server's contract(based on server ID)
string OTAPI_Wrap::GetServer_Contract(const string & SERVER_ID)
{
	// -----------------------------------------------------
	bool bInitialized = OTAPI_Wrap::OTAPI()->IsInitialized();
	if (!bInitialized) { OTLog::sError("%s: Not initialized; call OT_API::Init first.\n",__FUNCTION__);	OT_ASSERT(false); }

	if (SERVER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	// -----------------------------------------------------

	// --------------------------------------------------------------------
	const OTIdentifier theServerID(SERVER_ID);
	OTServerContract * pServer = OTAPI_Wrap::OTAPI()->GetServer(theServerID, __FUNCTION__);
	if (NULL == pServer) return "";
	// By this point, pServer is a good pointer.  (No need to cleanup.)
	// --------------------------------------------------------------------
	const OTString strOutput(*pServer);

	return strOutput.Get();
}

// returns Asset Type ID(based on index from GetAssetTypeCount)
string OTAPI_Wrap::GetAssetType_ID(const int32_t nIndex)
{
	if (0 > nIndex) { OTLog::sError("%s: nIndex is out of bounds (it's in the negative!)\n", __FUNCTION__); OT_ASSERT(false); }

	OTIdentifier	theID;
	OTString		strName;

	bool bGetServer = OTAPI_Wrap::OTAPI()->GetAssetType(nIndex, theID, strName);

	if (bGetServer)
	{
		OTString strID(theID);
		return strID.Get();		
	}
	return "";
}

// Returns asset type name based on Asset Type ID
string OTAPI_Wrap::GetAssetType_Name(const string & ASSET_TYPE_ID)
{
	if (ASSET_TYPE_ID.empty())				{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "ASSET_TYPE_ID"				); OT_ASSERT(false); }

	OTIdentifier	theID(ASSET_TYPE_ID);

	// -------------------------
	OTAssetContract * pContract = OTAPI_Wrap::OTAPI()->GetAssetType(theID, __FUNCTION__);
	if (NULL == pContract) return "";
	// -------------------------
	OTString strName;
	pContract->GetName(strName);

	return strName.Get();
}

// Returns currency contract based on Asset Type ID
string OTAPI_Wrap::GetAssetType_Contract(const string & ASSET_TYPE_ID)
{
	// -----------------------------------------------------
	bool bInitialized = OTAPI_Wrap::OTAPI()->IsInitialized();
	if (!bInitialized) { OTLog::sError("%s: Not initialized; call OT_API::Init first.\n",__FUNCTION__);	OT_ASSERT(false); }

	if (ASSET_TYPE_ID.empty())		{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "ASSET_TYPE_ID"		); OT_ASSERT(false); }
	// -----------------------------------------------------

	const OTIdentifier theAssetID(ASSET_TYPE_ID);
	OTAssetContract * pContract = OTAPI_Wrap::OTAPI()->GetAssetType(theAssetID, __FUNCTION__);
	if (NULL == pContract) return "";
	// By this point, pContract is a good pointer.  (No need to cleanup.)
	// --------------------------------------------------------------------
	const OTString strOutput(*pContract);

	return strOutput.Get();
}


// You already have accounts in your wallet(without any server communications)
// and these functions allow you to query the data members of those accounts.
// Thus, "AccountWallet" denotes that you are examining copies of your accounts that
// are sitting in your wallet. Originally the purpose was to eliminate confusion with
// a different set of similarly-named functions.

// returns a string containing the account ID, based on index.
string OTAPI_Wrap::GetAccountWallet_ID(const int32_t nIndex)
{
	if (0 > nIndex) { OTLog::sError("%s: nIndex is out of bounds (it's in the negative!)\n", __FUNCTION__); OT_ASSERT(false); }

	OTIdentifier	theID;
	OTString		strName;

	bool bGetServer = OTAPI_Wrap::OTAPI()->GetAccount(nIndex, theID, strName);

	if (bGetServer)
	{
		OTString strID(theID);

		return strID.Get();
	}
	return "";
}

// returns the account name, based on account ID.
string OTAPI_Wrap::GetAccountWallet_Name(const string & ACCOUNT_ID)
{
	if (ACCOUNT_ID.empty())				{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCOUNT_ID"				); OT_ASSERT(false); }

	OTIdentifier	theID(ACCOUNT_ID);

	const char * szFunc = "OT_API_GetAccountWallet_Name";
	// -------------------------
	OTAccount * pAccount = OTAPI_Wrap::OTAPI()->GetAccount(theID, szFunc);
	if (NULL == pAccount) return "";
	// -------------------------
	OTString strName;
	pAccount->GetName(strName);

	return strName.Get();
}

// returns the account balance, based on account ID.
int64_t OTAPI_Wrap::GetAccountWallet_Balance(const string & ACCOUNT_ID)
{
	if (ACCOUNT_ID.empty())				{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCOUNT_ID"				); OT_ASSERT(false); }

	OTIdentifier	theID(ACCOUNT_ID);

	// -------------------------
	OTAccount * pAccount = OTAPI_Wrap::OTAPI()->GetAccount(theID, __FUNCTION__);
	if (NULL == pAccount) return -1;
	// -------------------------	
	return pAccount->GetBalance();
}

// returns the account type(simple, issuer, etc)
string OTAPI_Wrap::GetAccountWallet_Type(const string & ACCOUNT_ID)
{
	if (ACCOUNT_ID.empty())				{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_ID"				); OT_ASSERT(false); }

	OTIdentifier	theID(ACCOUNT_ID);

	// -------------------------
	OTAccount * pAccount = OTAPI_Wrap::OTAPI()->GetAccount(theID, __FUNCTION__);
	if (NULL == pAccount) return "";
	// -------------------------

	return pAccount->GetTypeString();
}

// returns asset type ID of the account
string OTAPI_Wrap::GetAccountWallet_AssetTypeID(const string & ACCOUNT_ID)
{
	if (ACCOUNT_ID.empty())				{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_ID"				); OT_ASSERT(false); }

	OTIdentifier	theID(ACCOUNT_ID);

	// -------------------------
	OTAccount * pAccount = OTAPI_Wrap::OTAPI()->GetAccount(theID, __FUNCTION__);
	if (NULL == pAccount) return "";
	// -------------------------	
	OTIdentifier theAssetID(pAccount->GetAssetTypeID());

	OTString strAssetTypeID(theAssetID);

	OTLog::sOutput(1, "%s: Returning asset type %s for account %s\n", __FUNCTION__, strAssetTypeID.Get(), ACCOUNT_ID.c_str());

	return strAssetTypeID.Get(); 
}


// returns Server ID of the account
string OTAPI_Wrap::GetAccountWallet_ServerID(const string & ACCOUNT_ID)
{
	if (ACCOUNT_ID.empty())				{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_ID"				); OT_ASSERT(false); }

	OTIdentifier	theID(ACCOUNT_ID);

	// -------------------------
	OTAccount * pAccount = OTAPI_Wrap::OTAPI()->GetAccount(theID, __FUNCTION__);
	if (NULL == pAccount) return "";
	// -------------------------	
	OTIdentifier theServerID(pAccount->GetPurportedServerID());
	OTString strServerID(theServerID);

	return strServerID.Get(); 
}

// returns Nym ID of the account
string OTAPI_Wrap::GetAccountWallet_NymID(const string & ACCOUNT_ID)
{
	if (ACCOUNT_ID.empty())				{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_ID"				); OT_ASSERT(false); }

	const OTIdentifier	theID(ACCOUNT_ID);

	// -------------------------
	OTAccount * pAccount = OTAPI_Wrap::OTAPI()->GetAccount(theID, __FUNCTION__);
	if (NULL == pAccount) return "";
	// -------------------------	
	OTIdentifier theUserID(pAccount->GetUserID());
	OTString strUserID(theUserID);

	return strUserID.Get(); 
}

// returns latest InboxHash according to the account file.(Usually more recent than: GetNym_InboxHash)
string OTAPI_Wrap::GetAccountWallet_InboxHash(const string & ACCOUNT_ID)
{
	if (ACCOUNT_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCOUNT_ID"			); OT_ASSERT(false); }

	OTIdentifier	theID(ACCOUNT_ID);

	// -------------------------
	OTAccount * pAccount = OTAPI_Wrap::OTAPI()->GetAccount(theID, __FUNCTION__);
	if (NULL == pAccount) return "";
	// -------------------------

	OTIdentifier theOutput;
	const bool bGotHash = pAccount->GetInboxHash(theOutput);

	OTString strOutput;

	if (bGotHash)
		theOutput.GetString(strOutput);

	return strOutput.Get();
}

// returns latest OutboxHash according to the account file.(Usually more recent than: GetNym_OutboxHash)
string OTAPI_Wrap::GetAccountWallet_OutboxHash(const string & ACCOUNT_ID)
{
	if (ACCOUNT_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCOUNT_ID"			); OT_ASSERT(false); }

	OTIdentifier	theID(ACCOUNT_ID);

	// -------------------------
	OTAccount * pAccount = OTAPI_Wrap::OTAPI()->GetAccount(theID, __FUNCTION__);
	if (NULL == pAccount) return "";
	// -------------------------

	OTIdentifier theOutput;
	const bool bGotHash = pAccount->GetOutboxHash(theOutput);

	OTString strOutput;

	if (bGotHash)
		theOutput.GetString(strOutput);

	return strOutput.Get();
}


// Verifies any asset account(const int32_termediary files) against its own last signed receipt.
// Obviously this will fail for any new account that hasn't done any transactions yet, and thus has no receipts.
bool OTAPI_Wrap::VerifyAccountReceipt(
	const string & SERVER_ID,
	const string & NYM_ID,
	const string & ACCT_ID
	)
{
	if (SERVER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (NYM_ID.empty())				{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "NYM_ID"				); OT_ASSERT(false); }
	if (ACCT_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCT_ID"			); OT_ASSERT(false); }

	const OTIdentifier theServerID(SERVER_ID), theNymID(NYM_ID), theAcctID(ACCT_ID);
	// -----------------------------------------------------	
	const bool bVerified = OTAPI_Wrap::OTAPI()->VerifyAccountReceipt(theServerID, theNymID, theAcctID);
	// -----------------------------------------------------	
	return bVerified;
}


//----------------------------------------------------------
// GET NYM TRANSACTION NUM COUNT
// How many transaction numbers does the Nym have(for a given server?)
//
// This function returns the count of numbers available. If 0, then no
// transactions will work until you call getTransactionNumber()
// to replenish your Nym's supply for that ServerID...
//
// Returns a count(0 through N numbers available), 
// or -1 for error(no nym found.)
//
int32_t OTAPI_Wrap::GetNym_TransactionNumCount(
	const string & SERVER_ID,
	const string & NYM_ID
	)
{
	if (SERVER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (NYM_ID.empty())				{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "NYM_ID"				); OT_ASSERT(false); }

	OTIdentifier	theServerID(SERVER_ID);
	OTIdentifier	theNymID(NYM_ID);

	int nReturnValue = 0;

	// -------------------------
	OTPseudonym * pNym(OTAPI_Wrap::OTAPI()->GetNym(theNymID, __FUNCTION__));

	if (NULL != pNym)
		nReturnValue = pNym->GetTransactionNumCount(theServerID);
	else 
		nReturnValue = -1;

	return nReturnValue;
}

// based on Index(above 4 functions) this returns the Nym's ID
string OTAPI_Wrap::GetNym_ID(const int32_t nIndex)
{
	if (0 > nIndex) { OTLog::sError("%s: nIndex is out of bounds (it's in the negative!)\n", __FUNCTION__); OT_ASSERT(false); }

	OTIdentifier	theNymID;
	OTString		strName;

	bool bGetNym = OTAPI_Wrap::OTAPI()->GetNym(nIndex, theNymID, strName);

	if (bGetNym)
	{
		OTString strNymID(theNymID);

		return strNymID.Get();
	}

	return "";
}

// Returns Nym Name(based on NymID)
string OTAPI_Wrap::GetNym_Name(const string & NYM_ID)
{
	if (NYM_ID.empty())			{ OTLog::sError("%s: Null NYM_ID passed in!\n"			,__FUNCTION__); OT_ASSERT(false); }

	OTIdentifier	theNymID(NYM_ID);

	OTPseudonym * pNym = OTAPI_Wrap::OTAPI()->GetNym(theNymID);

	if (NULL != pNym)
	{
		OTString & strName = pNym->GetNymName();

		return strName.Get();
	}

	return "";
}

// Returns Nym Statistics(based on NymID)
string OTAPI_Wrap::GetNym_Stats(const string & NYM_ID)
{
	if (NYM_ID.empty())				{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "NYM_ID"				); OT_ASSERT(false); }

	// -------------------------
	OTIdentifier	theNymID(NYM_ID);
	OTPseudonym *  pNym(OTAPI_Wrap::OTAPI()->GetNym(theNymID, __FUNCTION__));

	if (NULL != pNym)
	{
		OTString strOutput;

		pNym->DisplayStatistics(strOutput);

		return strOutput.Get();
	}

	return "";	
}

// NymboxHash for "most recently DOWNLOADED" Nymbox(by ServerID)
string OTAPI_Wrap::GetNym_NymboxHash(
	const string & SERVER_ID,
	const string & NYM_ID 
	)
{
	if (NYM_ID.empty())				{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "NYM_ID"				); OT_ASSERT(false); }
	if (SERVER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }

	// -------------------------
	OTIdentifier	theNymID(NYM_ID);
	OTPseudonym *  pNym(OTAPI_Wrap::OTAPI()->GetNym(theNymID, __FUNCTION__));

	if (NULL != pNym)
	{
		OTIdentifier    theNymboxHash;
		const			string     str_server_id(SERVER_ID);
		const bool      bGothash = pNym->GetNymboxHash(str_server_id, theNymboxHash); // (theNymboxHash is output.)

		if (!bGothash)
		{
			const OTString strNymID(theNymID); // You might ask, why create this string and not just use NYM_ID?
			// The answer is because I'm looking forward to a day soon when we don't pass const char * in the first
			// place, and thus I can't always expect that variable will be there.
			//
			OTLog::sOutput(1, "%s: NymboxHash not found, on client side, "
				"for server %s and nym %s. (Returning NULL.)\n",
				__FUNCTION__, str_server_id.c_str(), strNymID.Get());
		}
		else // Success: the hash was there, for that Nym, for that server ID.
		{
			OTString strOutput(theNymboxHash);

			return strOutput.Get();       
		}
	}

	return "";
}

// "Most recent NymboxHash according to the SERVER's records"(Which is often sent as an 'FYI' with various server replies to my messages.)
string OTAPI_Wrap::GetNym_RecentHash(
	const string & SERVER_ID,
	const string & NYM_ID
	)
{
	if (NYM_ID.empty())				{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "NYM_ID"				); OT_ASSERT(false); }
	if (SERVER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }

	// -------------------------
	OTIdentifier	theNymID(NYM_ID);
	OTPseudonym *  pNym(OTAPI_Wrap::OTAPI()->GetNym(theNymID, __FUNCTION__));

	if (NULL != pNym)
	{
		OTIdentifier    theHash;
		const			string     str_server_id(SERVER_ID);
		const bool      bGothash = pNym->GetRecentHash(str_server_id, theHash); // (theHash is output.)

		if (!bGothash)
		{
			const OTString strNymID(theNymID); // You might ask, why create this string and not just use NYM_ID?
			// The answer is because I'm looking forward to a day soon when we don't pass const char * in the first
			// place, and thus I can't always expect that variable will be there.
			//
			OTLog::sOutput(1, "%s: RecentHash not found, on client side, "
				"for server %s and nym %s. (Returning NULL.)\n",
				__FUNCTION__, str_server_id.c_str(), strNymID.Get());
		}
		else // Success: the hash was there, for that Nym, for that server ID.
		{
			OTString strOutput(theHash);

			return strOutput.Get();
		}
	}

	return "";	
}

// InboxHash for "most recently DOWNLOADED" Inbox(by AccountID). Often contains older value than GetAccountWallet_InboxHash.
string OTAPI_Wrap::GetNym_InboxHash(
	const string & ACCOUNT_ID,
	const string & NYM_ID
	)
{
	if (ACCOUNT_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCOUNT_ID"			); OT_ASSERT(false); }
	if (NYM_ID.empty())				{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "NYM_ID"				); OT_ASSERT(false); }

	// -------------------------
	OTIdentifier	theNymID(NYM_ID);
	OTPseudonym *  pNym(OTAPI_Wrap::OTAPI()->GetNym(theNymID, __FUNCTION__));

	if (NULL != pNym)
	{
		OTIdentifier    theHash;
		const			string     str_acct_id(ACCOUNT_ID);
		const bool      bGothash = pNym->GetInboxHash(str_acct_id, theHash); // (theHash is output.)

		if (!bGothash)
		{
			const OTString strNymID(theNymID); // You might ask, why create this string and not just use NYM_ID?
			// The answer is because I'm looking forward to a day soon when we don't pass const char * in the first
			// place, and thus I can't always expect that variable will be there.
			//
			OTLog::sOutput(1, "%s: InboxHash not found, on client side, "
				"for account %s and nym %s. (Returning NULL.)\n",
				__FUNCTION__, str_acct_id.c_str(), strNymID.Get());
		}
		else // Success: the hash was there, for that Nym, for that server ID.
		{
			OTString strOutput(theHash);

			return strOutput.Get();
		}
	}

	return "";	
}

// OutboxHash for "most recently DOWNLOADED" Outbox(by AccountID) Often contains older value than GetAccountWallet_OutboxHash
string OTAPI_Wrap::GetNym_OutboxHash(
	const string & ACCOUNT_ID,
	const string & NYM_ID
	)
{
	if (ACCOUNT_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCOUNT_ID"			); OT_ASSERT(false); }
	if (NYM_ID.empty())				{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "NYM_ID"				); OT_ASSERT(false); }

	// -------------------------
	OTIdentifier	theNymID(NYM_ID);
	OTPseudonym *  pNym(OTAPI_Wrap::OTAPI()->GetNym(theNymID, __FUNCTION__));

	if (NULL != pNym)
	{
		OTIdentifier    theHash;
		const			string     str_acct_id(ACCOUNT_ID);
		const bool      bGothash = pNym->GetOutboxHash(str_acct_id, theHash); // (theHash is output.)

		if (!bGothash)
		{
			const OTString strNymID(theNymID); // You might ask, why create this string and not just use NYM_ID?
			// The answer is because I'm looking forward to a day soon when we don't pass const char * in the first
			// place, and thus I can't always expect that variable will be there.
			//
			OTLog::sOutput(1, "%s: OutboxHash not found, on client side, "
				"for account %s and nym %s. (Returning NULL.)\n",
				__FUNCTION__, str_acct_id.c_str(), strNymID.Get());
		}
		else // Success: the hash was there, for that Nym, for that server ID.
		{
			OTString strOutput(theHash);

			return strOutput.Get();       
		}
	}

	return "";	
}

bool OTAPI_Wrap::IsNym_RegisteredAtServer(const string & NYM_ID, string SERVER_ID)
{
	if (NYM_ID.empty())				{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "NYM_ID"				); OT_ASSERT(false); }
	if (SERVER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }

	const OTIdentifier	theNymID(NYM_ID), 
		theServerID(SERVER_ID);

	bool bSuccess = OTAPI_Wrap::OTAPI()->IsNym_RegisteredAtServer(theNymID, theServerID);

	return bSuccess;
}


// Each Nym has mail messages, they can come from different servers.
// This allows you to peruse the mail for a given Nym, and erase messages.
//
/***

So how would you actually USE this to browse a Nym's mail?

-- Call GetNym_MailCount() to find out how many mail items there are.

-- Then LOOP through them, and use GetNym_MailSenderIDByIndex and
GetNym_MailServerIDByIndex to populate the list.

-- If you want to add a subject display, you'll have to call GetNym_MailContentsByIndex()
and check for a first line beginning in Subject:(there may not be one.)

-- GetNym_MailContentsByIndex returns the body of the mail regardless.

-- Use Nym_VerifyMailByIndex() to verify the signature on the mail,

-- and use Nym_RemoveMailByIndex() to erase mail(when you want to.)

*/

int32_t OTAPI_Wrap::GetNym_MailCount(const string & NYM_ID)
{
	if (NYM_ID.empty())				{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "NYM_ID"				); OT_ASSERT(false); }

	// -------------------------
	OTIdentifier	theNymID(NYM_ID);
	OTPseudonym *  pNym(OTAPI_Wrap::OTAPI()->GetNym(theNymID, __FUNCTION__));
	if (NULL == pNym) return 0;
	// -------------------------
	return pNym->GetMailCount();
}

// returns the message itself(Subject: optionally as first line)
string OTAPI_Wrap::GetNym_MailContentsByIndex(
	const string & NYM_ID,
	const int32_t & nIndex
	)
{
	if (NYM_ID.empty())				{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "NYM_ID"				); OT_ASSERT(false); }

	if (0 > nIndex) { OTLog::sError("%s: nIndex is out of bounds (it's in the negative!)\n", __FUNCTION__); OT_ASSERT(false); }

	// -------------------------
	OTIdentifier	theNymID(NYM_ID);
	OTPseudonym *  pNym(OTAPI_Wrap::OTAPI()->GetNym(theNymID, __FUNCTION__));
	if (NULL == pNym) return "";
	// -------------------------
	std::shared_ptr<OTMessage> pMessage(pNym->GetMailByIndex(nIndex));

	if (NULL != pMessage)
	{
		// SENDER:    pMessage->m_strNymID
		// RECIPIENT: pMessage->m_strNymID2
		// MESSAGE:   pMessage->m_ascPayload (in an OTEnvelope)
		//	
		OTEnvelope	theEnvelope;
		OTString	strEnvelopeContents;

		// Decrypt the Envelope.
		if (theEnvelope.SetAsciiArmoredData(pMessage->m_ascPayload) &&
			theEnvelope.Open(*pNym, strEnvelopeContents))
		{
			return strEnvelopeContents.Get();
		}
	}
	return "";	
}

// returns the NymID of the sender.
string OTAPI_Wrap::GetNym_MailSenderIDByIndex(
	const string & NYM_ID,
	const int32_t & nIndex
	)
{
	if (NYM_ID.empty())				{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "NYM_ID"				); OT_ASSERT(false); }

	if (0 > nIndex) { OTLog::sError("%s: nIndex is out of bounds (it's in the negative!)\n", __FUNCTION__); OT_ASSERT(false); }

	// -------------------------
	OTIdentifier	theNymID(NYM_ID);
	OTPseudonym *  pNym(OTAPI_Wrap::OTAPI()->GetNym(theNymID, __FUNCTION__));
	if (NULL == pNym) return "";
	// -------------------------
	std::shared_ptr<OTMessage>  pMessage(pNym->GetMailByIndex(nIndex));

	if (NULL != pMessage)
	{
		// SENDER:    pMessage->m_strNymID
		// SERVER:    pMessage->m_strServerID
		// RECIPIENT: pMessage->m_strNymID2
		// MESSAGE:   pMessage->m_ascPayload (in an OTEnvelope)

		return pMessage->m_strNymID.Get(); 
	}
	return "";	
}

// returns the ServerID where the message came from.
string OTAPI_Wrap::GetNym_MailServerIDByIndex(
	const string & NYM_ID,
	const int32_t & nIndex
	)
{
	if (NYM_ID.empty())				{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "NYM_ID"				); OT_ASSERT(false); }

	if (0 > nIndex) { OTLog::sError("%s: nIndex is out of bounds (it's in the negative!)\n", __FUNCTION__); OT_ASSERT(false); }

	// -------------------------
	OTIdentifier	theNymID(NYM_ID);
	OTPseudonym *  pNym(OTAPI_Wrap::OTAPI()->GetNym(theNymID, __FUNCTION__));
	if (NULL == pNym) return "";
	// -------------------------	
	std::shared_ptr<OTMessage>  pMessage(pNym->GetMailByIndex(nIndex));

	if (NULL != pMessage)
	{
		// SENDER:    pMessage->m_strNymID
		// SERVER:    pMessage->m_strServerID
		// RECIPIENT: pMessage->m_strNymID2
		// MESSAGE:   pMessage->m_ascPayload (in an OTEnvelope)

		return pMessage->m_strServerID.Get();
	}
	return "";	
}

bool OTAPI_Wrap::Nym_RemoveMailByIndex(
	const string & NYM_ID,
	const int32_t & nIndex
	)
{
	if (NYM_ID.empty())				{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "NYM_ID"				); OT_ASSERT(false); }

	if (0 > nIndex) { OTLog::sError("%s: nIndex is out of bounds (it's in the negative!)\n", __FUNCTION__); OT_ASSERT(false); }

	// -------------------------
	OTIdentifier	theNymID(NYM_ID);
	OTPseudonym *  pNym(OTAPI_Wrap::OTAPI()->GetNym(theNymID, __FUNCTION__));
	if (NULL == pNym) return false;
	// -------------------------	
	OTPseudonym *  pSignerNym = pNym;

	if (pNym->RemoveMailByIndex(nIndex))
	{
		if (pNym->SaveSignedNymfile(*pSignerNym)) // <== save Nym to local storage, since a mail was erased.
			return true; 
		else 
			OTLog::sError("%s: Error saving Nym: %s\n", __FUNCTION__, NYM_ID);
	}
	return false;
}

// True if signature verifies.(Sender Nym MUST be in my wallet for this to work.)
bool OTAPI_Wrap::Nym_VerifyMailByIndex(
	const string & NYM_ID,
	const int32_t & nIndex
	)
{
	if (NYM_ID.empty())				{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "NYM_ID"				); OT_ASSERT(false); }

	if (0 > nIndex) { OTLog::sError("%s: nIndex is out of bounds (it's in the negative!)\n", __FUNCTION__); OT_ASSERT(false); }

	// -------------------------
	OTIdentifier	theNymID(NYM_ID);
	OTPseudonym *  pNym(OTAPI_Wrap::OTAPI()->GetNym(theNymID, __FUNCTION__));
	if (NULL == pNym) return false;
	// -------------------------	
	std::shared_ptr<OTMessage>  pMessage(pNym->GetMailByIndex(nIndex));

	if (NULL != pMessage)
	{
		// Grab the NymID of the sender.
		const OTIdentifier theSenderNymID(pMessage->m_strNymID);

		// Grab a pointer to that Nym (if its public key is in my wallet.)
		OTPseudonym *  pSenderNym(OTAPI_Wrap::OTAPI()->GetNym(theSenderNymID, __FUNCTION__));

		// If it's there, use it to verify the signature on the message.
		// return OT_TRUE if successful signature verification.
		//
		if (NULL != pSenderNym)
		{
			if (pMessage->VerifySignature(*pSenderNym))
				return true;
		}
	}
	return false;	
}


// ---------------------------------------------------------

int32_t OTAPI_Wrap::GetNym_OutmailCount(const string & NYM_ID)
{
	if (NYM_ID.empty())				{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "NYM_ID"				); OT_ASSERT(false); }

	// -------------------------
	OTIdentifier	theNymID(NYM_ID);
	OTPseudonym *  pNym(OTAPI_Wrap::OTAPI()->GetNym(theNymID, __FUNCTION__));
	if (NULL == pNym) return 0;
	// -------------------------	
	return pNym->GetOutmailCount();
}

// returns the message itself(Subject: optionally as first line)
string OTAPI_Wrap::GetNym_OutmailContentsByIndex(
	const string & NYM_ID,
	const int32_t & nIndex
	)
{
	if (NYM_ID.empty())				{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "NYM_ID"				); OT_ASSERT(false); }

	if (0 > nIndex) { OTLog::sError("%s: nIndex is out of bounds (it's in the negative!)\n", __FUNCTION__); OT_ASSERT(false); }

	// -------------------------
	OTIdentifier	theNymID(NYM_ID);
	OTPseudonym *  pNym(OTAPI_Wrap::OTAPI()->GetNym(theNymID, __FUNCTION__));
	if (NULL == pNym) return "";
	// -------------------------	
	std::shared_ptr<OTMessage>  pMessage(pNym->GetOutmailByIndex(nIndex));
	if (NULL != pMessage)
	{
		// SENDER:    pMessage->m_strNymID
		// RECIPIENT: pMessage->m_strNymID2
		// MESSAGE:   pMessage->m_ascPayload (in an OTEnvelope)
		OTString	strMailContents;

		if (pMessage->m_ascPayload.Exists() &&
			pMessage->m_ascPayload.GetString(strMailContents))
		{

			return strMailContents.Get();
		}
	}
	return "";	
}

// returns the NymID of the recipient.
string OTAPI_Wrap::GetNym_OutmailRecipientIDByIndex(
	const string & NYM_ID,
	const int32_t & nIndex
	)
{
	if (NYM_ID.empty())				{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "NYM_ID"				); OT_ASSERT(false); }

	if (0 > nIndex) { OTLog::sError("%s: nIndex is out of bounds (it's in the negative!)\n", __FUNCTION__); OT_ASSERT(false); }

	// -------------------------
	OTIdentifier	theNymID(NYM_ID);
	OTPseudonym *  pNym(OTAPI_Wrap::OTAPI()->GetNym(theNymID, __FUNCTION__));
	if (NULL == pNym) return "";
	// -------------------------	
	std::shared_ptr<OTMessage>  pMessage(pNym->GetOutmailByIndex(nIndex));
	if (NULL != pMessage)
	{
		// SENDER:    pMessage->m_strNymID
		// SERVER:    pMessage->m_strServerID
		// RECIPIENT: pMessage->m_strNymID2
		// MESSAGE:   pMessage->m_ascPayload

		return pMessage->m_strNymID2.Get();
	}
	return "";	
}

// returns the ServerID where the message came from.
string OTAPI_Wrap::GetNym_OutmailServerIDByIndex(
	const string & NYM_ID,
	const int32_t & nIndex
	)
{
	if (NYM_ID.empty())				{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "NYM_ID"				); OT_ASSERT(false); }

	if (0 > nIndex) { OTLog::sError("%s: nIndex is out of bounds (it's in the negative!)\n", __FUNCTION__); OT_ASSERT(false); }

	// -------------------------
	OTIdentifier	theNymID(NYM_ID);
	OTPseudonym *  pNym(OTAPI_Wrap::OTAPI()->GetNym(theNymID, __FUNCTION__));
	if (NULL == pNym) return "";
	// -------------------------	
	std::shared_ptr<OTMessage>  pMessage(pNym->GetOutmailByIndex(nIndex));

	if (NULL != pMessage)
	{
		// SENDER:    pMessage->m_strNymID
		// SERVER:    pMessage->m_strServerID
		// RECIPIENT: pMessage->m_strNymID2
		// MESSAGE:   pMessage->m_ascPayload 

		return pMessage->m_strServerID.Get();
	}
	return "";	
}

bool OTAPI_Wrap::Nym_RemoveOutmailByIndex(
	const string & NYM_ID,
	const int32_t & nIndex
	)
{
	if (NYM_ID.empty())				{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "NYM_ID"				); OT_ASSERT(false); }

	if (0 > nIndex) { OTLog::sError("%s: nIndex is out of bounds (it's in the negative!)\n", __FUNCTION__); OT_ASSERT(false); }

	// -------------------------
	OTIdentifier	theNymID(NYM_ID);
	OTPseudonym *  pNym(OTAPI_Wrap::OTAPI()->GetNym(theNymID, __FUNCTION__));
	if (NULL == pNym) return false;
	// -------------------------	
	OTPseudonym *  pSignerNym = pNym;

	if (pNym->RemoveOutmailByIndex(nIndex))
	{
		if (pNym->SaveSignedNymfile(*pSignerNym)) // <== save Nym to local storage, since a mail was erased.
			return true;
		else 
			OTLog::sError("%s: Error saving Nym: %s\n", __FUNCTION__, NYM_ID);
	}
	return false;	
}

// TRUE if signature verifies.(Sender Nym MUST be in my wallet for this to work.)
bool OTAPI_Wrap::Nym_VerifyOutmailByIndex(
	const string & NYM_ID,
	const int32_t & nIndex
	)
{
	if (NYM_ID.empty())				{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "NYM_ID"				); OT_ASSERT(false); }

	if (0 > nIndex) { OTLog::sError("%s: nIndex is out of bounds (it's in the negative!)\n", __FUNCTION__); OT_ASSERT(false); }

	// -------------------------
	OTIdentifier	theNymID(NYM_ID);
	OTPseudonym *  pNym(OTAPI_Wrap::OTAPI()->GetNym(theNymID, __FUNCTION__));
	if (NULL == pNym) return false;
	// -------------------------	
	std::shared_ptr<OTMessage>  pMessage(pNym->GetOutmailByIndex(nIndex));
	if (NULL != pMessage)
	{
		// Grab the NymID of the sender.
		const OTIdentifier theSenderNymID(pMessage->m_strNymID);

		// Grab a pointer to that Nym (if its public key is in my wallet.)
		OTPseudonym *  pSenderNym(OTAPI_Wrap::OTAPI()->GetNym(theSenderNymID, __FUNCTION__));

		// If it's there, use it to verify the signature on the message.
		// return OT_TRUE if successful signature verification.
		//
		if (NULL != pSenderNym)
		{
			if (pMessage->VerifySignature(*pSenderNym))
				return true;
		}
	}
	return false;	
}


// ---------------------------------------------------------

int32_t OTAPI_Wrap::GetNym_OutpaymentsCount(const string & NYM_ID)
{
	if (NYM_ID.empty())				{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "NYM_ID"				); OT_ASSERT(false); }

	// -------------------------
	OTIdentifier	theNymID(NYM_ID);
	OTPseudonym *  pNym(OTAPI_Wrap::OTAPI()->GetNym(theNymID, __FUNCTION__));
	if (NULL == pNym) return 0;
	// -------------------------	
	return pNym->GetOutpaymentsCount();
}

// returns the message itself
string OTAPI_Wrap::GetNym_OutpaymentsContentsByIndex(
	const string & NYM_ID,
	const int32_t & nIndex
	)
{
	if (NYM_ID.empty())				{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "NYM_ID"				); OT_ASSERT(false); }

	if (0 > nIndex) { OTLog::sError("%s: nIndex is out of bounds (it's in the negative!)\n", __FUNCTION__); OT_ASSERT(false); }

	// -------------------------
	OTIdentifier	theNymID(NYM_ID);
	OTPseudonym *  pNym(OTAPI_Wrap::OTAPI()->GetNym(theNymID, __FUNCTION__));
	if (NULL == pNym) return "";
	// -------------------------	
	std::shared_ptr<OTMessage>  pMessage(pNym->GetOutpaymentsByIndex(nIndex));
	if (NULL != pMessage)
	{
		// SENDER:     pMessage->m_strNymID
		// RECIPIENT:  pMessage->m_strNymID2
		// INSTRUMENT: pMessage->m_ascPayload (in an OTEnvelope)
		OTString	strPayment;
		OTString	strPaymentContents;

		// There isn't any encrypted envelope this time, since it's my outPayments box.
		//
		if (pMessage->m_ascPayload.Exists() &&
			pMessage->m_ascPayload.GetString(strPayment) &&
			strPayment.Exists())
		{
			OTPayment thePayment;
			// ---------------------------------------------
			if (thePayment.LoadContractFromString(strPayment)       &&
				thePayment.GetPaymentContents(strPaymentContents)   &&
				strPaymentContents.Exists())
			{

				return strPaymentContents.Get();
			}
		}
	}
	return "";	
}

// returns the NymID of the recipient.
string OTAPI_Wrap::GetNym_OutpaymentsRecipientIDByIndex(
	const string & NYM_ID,
	const int32_t & nIndex
	)
{
	if (NYM_ID.empty())				{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "NYM_ID"				); OT_ASSERT(false); }

	if (0 > nIndex) { OTLog::sError("%s: nIndex is out of bounds (it's in the negative!)\n", __FUNCTION__); OT_ASSERT(false); }

	// -------------------------
	OTIdentifier	theNymID(NYM_ID);
	OTPseudonym *  pNym(OTAPI_Wrap::OTAPI()->GetNym(theNymID, __FUNCTION__));
	if (NULL == pNym) return "";
	// -------------------------	
	std::shared_ptr<OTMessage>  pMessage(pNym->GetOutpaymentsByIndex(nIndex));
	if (NULL != pMessage)
	{
		// SENDER:    pMessage->m_strNymID
		// SERVER:    pMessage->m_strServerID
		// RECIPIENT: pMessage->m_strNymID2
		// MESSAGE:   pMessage->m_ascPayload

		return pMessage->m_strNymID2.Get();
	}
	return "";	
}

// returns the ServerID where the message came from.
string OTAPI_Wrap::GetNym_OutpaymentsServerIDByIndex(
	const string & NYM_ID,
	const int32_t & nIndex
	)
{
	if (NYM_ID.empty())				{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "NYM_ID"				); OT_ASSERT(false); }

	if (0 > nIndex) { OTLog::sError("%s: nIndex is out of bounds (it's in the negative!)\n", __FUNCTION__); OT_ASSERT(false); }

	// -------------------------
	OTIdentifier	theNymID(NYM_ID);
	OTPseudonym *  pNym(OTAPI_Wrap::OTAPI()->GetNym(theNymID, __FUNCTION__));
	if (NULL == pNym) return "";
	// -------------------------	
	std::shared_ptr<OTMessage>  pMessage(pNym->GetOutpaymentsByIndex(nIndex));

	if (NULL != pMessage)
	{
		// SENDER:    pMessage->m_strNymID
		// SERVER:    pMessage->m_strServerID
		// RECIPIENT: pMessage->m_strNymID2
		// MESSAGE:   pMessage->m_ascPayload 

		int bServerIdLength = pMessage->m_strServerID.GetLength();
		if (1 >= bServerIdLength) {
			OTLog::sError("%s: m_strServerID Length is 1 or less!\n", __FUNCTION__);
			OT_ASSERT(false);
		}

		return pMessage->m_strServerID.Get();
	}
	return "";	
}

// returns the ServerID where the message came from.
bool OTAPI_Wrap::Nym_RemoveOutpaymentsByIndex(
	const string & NYM_ID,
	const int32_t & nIndex
	)
{
	if (NYM_ID.empty())				{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "NYM_ID"				); OT_ASSERT(false); }

	if (0 > nIndex) { OTLog::sError("%s: nIndex is out of bounds (it's in the negative!)\n", __FUNCTION__); OT_ASSERT(false); }

	// -------------------------
	OTIdentifier	theNymID(NYM_ID);
	OTPseudonym *  pNym(OTAPI_Wrap::OTAPI()->GetNym(theNymID, __FUNCTION__));
	if (NULL == pNym) return false;
	// -------------------------	
	OTPseudonym *  pSignerNym = pNym;

	if (pNym->RemoveOutpaymentsByIndex(nIndex))
	{
		if (pNym->SaveSignedNymfile(*pSignerNym)) // <== save Nym to local storage, since a payment outmail was erased.
			return true;
		else 
			OTLog::sError("%s: Error saving Nym: %s\n", __FUNCTION__, NYM_ID);
	}
	return false;
}

// TRUE if signature verifies.(Sender Nym MUST be in my wallet for this to work.)
bool OTAPI_Wrap::Nym_VerifyOutpaymentsByIndex(
	const string & NYM_ID,
	const int32_t & nIndex
	)
{
	if (NYM_ID.empty())				{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "NYM_ID"				); OT_ASSERT(false); }

	if (0 > nIndex) { OTLog::sError("%s: nIndex is out of bounds (it's in the negative!)\n", __FUNCTION__); OT_ASSERT(false); }

	// -------------------------
	OTIdentifier	theNymID(NYM_ID);
	OTPseudonym *  pNym(OTAPI_Wrap::OTAPI()->GetNym(theNymID, __FUNCTION__));
	if (NULL == pNym) return false;
	// -------------------------	
	std::shared_ptr<OTMessage>  pMessage(pNym->GetOutpaymentsByIndex(nIndex));
	if (NULL != pMessage)
	{
		// Grab the NymID of the sender.
		const OTIdentifier theSenderNymID(pMessage->m_strNymID);

		// Grab a pointer to that Nym (if its public key is in my wallet.)
		OTPseudonym *  pSenderNym(OTAPI_Wrap::OTAPI()->GetNym(theSenderNymID, __FUNCTION__));

		// If it's there, use it to verify the signature on the message.
		// return OT_TRUE if successful signature verification.
		//
		if (NULL != pSenderNym)
		{
			if (pMessage->VerifySignature(*pSenderNym))
				return true;
		}
	}
	return false;	
}


// ---------------------------------------------------------

// *** FUNCTIONS FOR REMOVING VARIOUS CONTRACTS AND NYMS FROM THE WALLET ***

// Can I remove this server contract from my wallet?
//
// You cannot remove the server contract from your wallet if there are accounts in there using it.
// This function tells you whether you can remove the server contract or not.(Whether there are accounts...)
//
bool OTAPI_Wrap::Wallet_CanRemoveServer(const string & SERVER_ID)
{
	// -----------------------------------------------------
	bool bInitialized = OTAPI_Wrap::OTAPI()->IsInitialized();
	if (!bInitialized) { OTLog::sError("%s: Not initialized; call OT_API::Init first.\n",__FUNCTION__);	OT_ASSERT(false); }

	if (SERVER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	// -----------------------------------------------------
	OTString strName;
	// ------------------------------------------	
	OTIdentifier theServerID(SERVER_ID);
	// ------------------------------------------

	return OTAPI_Wrap::OTAPI()->Wallet_CanRemoveServer(theServerID);

}


// Remove this server contract from my wallet!
//
// Try to remove the server contract from the wallet.
// This will not work if there are any accounts in the wallet for the same server ID.
//
bool OTAPI_Wrap::Wallet_RemoveServer(const string & SERVER_ID)
{
	// -----------------------------------------------------
	bool bInitialized = OTAPI_Wrap::OTAPI()->IsInitialized();
	if (!bInitialized) { OTLog::sError("%s: Not initialized; call OT_API::Init first.\n",__FUNCTION__);	OT_ASSERT(false); }

	if (SERVER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }

	// ------------------------------------------	
	OTIdentifier theServerID(SERVER_ID);
	// ------------------------------------------

	return OTAPI_Wrap::OTAPI()->Wallet_RemoveServer(theServerID);
}


// Can I remove this asset contract from my wallet?
//
// You cannot remove the asset contract from your wallet if there are accounts in there using it.
// This function tells you whether you can remove the asset contract or not.(Whether there are accounts...)
//
bool OTAPI_Wrap::Wallet_CanRemoveAssetType(const string & ASSET_ID)
{
	// -----------------------------------------------------
	bool bInitialized = OTAPI_Wrap::OTAPI()->IsInitialized();
	if (!bInitialized) { OTLog::sError("%s: Not initialized; call OT_API::Init first.\n",__FUNCTION__);	OT_ASSERT(false); }

	if (ASSET_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "ASSET_ID"			); OT_ASSERT(false); }
	// -----------------------------------------------------

	OTIdentifier theID(ASSET_ID);
	// ------------------------------------------
	return OTAPI_Wrap::OTAPI()->Wallet_CanRemoveAssetType(theID);
}


// Remove this asset contract from my wallet!
//
// Try to remove the asset contract from the wallet.
// This will not work if there are any accounts in the wallet for the same asset type ID.
//
bool OTAPI_Wrap::Wallet_RemoveAssetType(const string & ASSET_ID)
{
	// -----------------------------------------------------
	bool bInitialized = OTAPI_Wrap::OTAPI()->IsInitialized();
	if (!bInitialized) { OTLog::sError("%s: Not initialized; call OT_API::Init first.\n",__FUNCTION__);	OT_ASSERT(false); }

	if (ASSET_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "ASSET_ID"			); OT_ASSERT(false); }
	// -----------------------------------------------------
	OTIdentifier theID(ASSET_ID);

	return OTAPI_Wrap::OTAPI()->Wallet_RemoveAssetType(theID);
}



// Can I remove this Nym from my wallet?
//
// You cannot remove the Nym from your wallet if there are accounts in there using it.
// This function tells you whether you can remove the Nym or not.(Whether there are accounts...)
//
bool OTAPI_Wrap::Wallet_CanRemoveNym(const string & NYM_ID)
{
	// -----------------------------------------------------
	bool bInitialized = OTAPI_Wrap::OTAPI()->IsInitialized();
	if (!bInitialized) { OTLog::sError("%s: Not initialized; call OT_API::Init first.\n",__FUNCTION__);	OT_ASSERT(false); }

	if (NYM_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "NYM_ID"			); OT_ASSERT(false); }
	// -----------------------------------------------------

	OTIdentifier theID(NYM_ID);
	// ------------------------------------------
	return OTAPI_Wrap::OTAPI()->Wallet_CanRemoveNym(theID);
}


// Remove this Nym from my wallet!
//
// Try to remove the Nym from the wallet.
// This will not work if there are any nyms in the wallet for the same server ID.
//
bool OTAPI_Wrap::Wallet_RemoveNym(const string & NYM_ID)
{
	// -----------------------------------------------------
	bool bInitialized = OTAPI_Wrap::OTAPI()->IsInitialized();
	if (!bInitialized) { OTLog::sError("%s: Not initialized; call OT_API::Init first.\n",__FUNCTION__);	OT_ASSERT(false); }

	if (NYM_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "NYM_ID"			); OT_ASSERT(false); }
	// -----------------------------------------------------

	OTIdentifier theID(NYM_ID);
	// ------------------------------------------
	return OTAPI_Wrap::OTAPI()->Wallet_RemoveNym(theID);
}


// Can I remove this Account from my wallet?
//
// You cannot remove the Account from your wallet if there are transactions still open.
// This function tells you whether you can remove the Account or not.(Whether there are transactions...)
//
bool OTAPI_Wrap::Wallet_CanRemoveAccount(const string & ACCOUNT_ID)
{
	// -----------------------------------------------------
	bool bInitialized = OTAPI_Wrap::OTAPI()->IsInitialized();
	if (!bInitialized) { OTLog::sError("%s: Not initialized; call OT_API::Init first.\n",__FUNCTION__);	OT_ASSERT(false); }

	if (ACCOUNT_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "NYM_ID"			); OT_ASSERT(false); }
	// -----------------------------------------------------

	OTIdentifier theID(ACCOUNT_ID);
	// ------------------------------------------
	return OTAPI_Wrap::OTAPI()->Wallet_CanRemoveAccount(theID);
}




// Attempts to find a full ID in the wallet, based on a partial of the same ID.
// Returns NULL on failure, otherwise returns the full ID.
// 
string OTAPI_Wrap::Wallet_GetNymIDFromPartial(const string & PARTIAL_ID)
{
	//  OTPseudonym * 	GetNym(const OTIdentifier & NYM_ID, const char * szFuncName=NULL);
	//  OTPseudonym * 	GetNymByIDPartialMatch(const string PARTIAL_ID, const char * szFuncName=NULL);

	// -----------------------------------------------------
	bool bInitialized = OTAPI_Wrap::OTAPI()->IsInitialized();
	if (!bInitialized) { OTLog::sError("%s: Not initialized; call OT_API::Init first.\n"		,__FUNCTION__);	OT_ASSERT(false); }

	if (PARTIAL_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "PARTIAL_ID"			); OT_ASSERT(false); }
	// -----------------------------------------------------

	OTIdentifier  thePartialID(PARTIAL_ID);

	// In this case, the user passed in the FULL ID. 
	// (We STILL confirm whether he's found in the wallet...)
	//
	OTPseudonym *  pObject(OTAPI_Wrap::OTAPI()->GetNym(thePartialID, "OT_API_Wallet_GetNymIDFromPartial"));

	if (NULL != pObject) // Found it (as full ID.)
	{
		OTString strID_Output(thePartialID);
		return strID_Output.Get();
	}
	// ------------------------------------------
	// Below this point, it definitely wasn't a FULL ID, so now we can
	// go ahead and search for it as a PARTIAL ID...
	//
	pObject = (OTAPI_Wrap::OTAPI()->GetNymByIDPartialMatch(PARTIAL_ID, "OT_API_Wallet_GetNymIDFromPartial"));

	if (NULL != pObject) // Found it (as partial ID.)
	{
		OTString strID_Output;
		pObject->GetIdentifier(strID_Output);
		return strID_Output.Get();
	}

	return "";
}

string OTAPI_Wrap::Wallet_GetServerIDFromPartial(const string & PARTIAL_ID)
{
	//    OTServerContract *	GetServer(const OTIdentifier & THE_ID, const char * szFuncName=NULL);
	//    OTServerContract *	GetServerContractPartialMatch(const string PARTIAL_ID, const char * szFuncName=NULL);

	// -----------------------------------------------------
	bool bInitialized = OTAPI_Wrap::OTAPI()->IsInitialized();
	if (!bInitialized) { OTLog::sError("%s: Not initialized; call OT_API::Init first.\n"		,__FUNCTION__);	OT_ASSERT(false); }

	if (PARTIAL_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "PARTIAL_ID"			); OT_ASSERT(false); }
	// -----------------------------------------------------

	OTIdentifier  thePartialID(PARTIAL_ID);

	// In this case, the user passed in the FULL ID. 
	// (We STILL confirm whether he's found in the wallet...)
	//
	OTServerContract * pObject(OTAPI_Wrap::OTAPI()->GetServer(thePartialID, "OT_API_Wallet_GetServerIDFromPartial")); 

	if (NULL != pObject) // Found it (as full ID.)
	{
		OTString strID_Output(thePartialID);

		return strID_Output.Get();
	}
	// ------------------------------------------
	// Below this point, it definitely wasn't a FULL ID, so now we can
	// go ahead and search for it as a PARTIAL ID...
	//
	pObject = (OTAPI_Wrap::OTAPI()->GetServerContractPartialMatch(PARTIAL_ID, "OT_API_Wallet_GetServerIDFromPartial"));

	if (NULL != pObject) // Found it (as partial ID.)
	{
		OTString strID_Output;
		pObject->GetIdentifier(strID_Output);

		return strID_Output.Get();
	}

	return "";
}

string OTAPI_Wrap::Wallet_GetAssetIDFromPartial(const string & PARTIAL_ID)
{
	//    OTAssetContract *	GetAssetType(const OTIdentifier & THE_ID, const char * szFuncName=NULL);
	//    OTAssetContract *	GetAssetContractPartialMatch(const string PARTIAL_ID, const char * szFuncName=NULL);

	// -----------------------------------------------------
	bool bInitialized = OTAPI_Wrap::OTAPI()->IsInitialized();
	if (!bInitialized) { OTLog::sError("%s: Not initialized; call OT_API::Init first.\n"		,__FUNCTION__);	OT_ASSERT(false); }

	if (PARTIAL_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "PARTIAL_ID"			); OT_ASSERT(false); }
	// -----------------------------------------------------

	OTIdentifier  thePartialID(PARTIAL_ID);

	// In this case, the user passed in the FULL ID. 
	// (We STILL confirm whether he's found in the wallet...)
	//
	OTAssetContract * pObject = OTAPI_Wrap::OTAPI()->GetAssetType(thePartialID, "OT_API_Wallet_GetAssetIDFromPartial"); 

	if (NULL != pObject) // Found it (as full ID.)
	{
		OTString strID_Output(thePartialID);

		return strID_Output.Get();
	}
	// ------------------------------------------
	// Below this point, it definitely wasn't a FULL ID, so now we can
	// go ahead and search for it as a PARTIAL ID...
	//
	pObject = OTAPI_Wrap::OTAPI()->GetAssetContractPartialMatch(PARTIAL_ID, "OT_API_Wallet_GetAssetIDFromPartial"); 

	if (NULL != pObject) // Found it (as partial ID.)
	{
		OTString strID_Output;
		pObject->GetIdentifier(strID_Output);

		return strID_Output.Get();
	}

	return "";
}


string OTAPI_Wrap::Wallet_GetAccountIDFromPartial(const string & PARTIAL_ID)
{
	//    OTAccount *   GetAccount(const OTIdentifier & THE_ID, const char * szFuncName=NULL);	
	//    OTAccount *   GetAccountPartialMatch(const string PARTIAL_ID, const char * szFuncName=NULL);

	// -----------------------------------------------------
	bool bInitialized = OTAPI_Wrap::OTAPI()->IsInitialized();
	if (!bInitialized) { OTLog::sError("%s: Not initialized; call OT_API::Init first.\n"		,__FUNCTION__);	OT_ASSERT(false); }

	if (PARTIAL_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "PARTIAL_ID"			); OT_ASSERT(false); }
	// -----------------------------------------------------

	OTIdentifier  thePartialID(PARTIAL_ID);

	// In this case, the user passed in the FULL ID. 
	// (We STILL confirm whether he's found in the wallet...)
	//
	OTAccount * pObject = OTAPI_Wrap::OTAPI()->GetAccount(thePartialID, "OT_API_Wallet_GetNymIDFromPartial"); 

	if (NULL != pObject) // Found it (as full ID.)
	{
		OTString strID_Output(thePartialID);

		return strID_Output.Get();
	}
	// ------------------------------------------
	// Below this point, it definitely wasn't a FULL ID, so now we can
	// go ahead and search for it as a PARTIAL ID...
	//
	pObject = OTAPI_Wrap::OTAPI()->GetAccountPartialMatch(PARTIAL_ID, "OT_API_Wallet_GetNymIDFromPartial"); 

	if (NULL != pObject) // Found it (as partial ID.)
	{
		OTString strID_Output;
		pObject->GetIdentifier(strID_Output);

		return strID_Output.Get();
	}

	return "";
}



// -----------------------------------
// SET NYM NAME
//
// You might have 40 of your friends' public nyms in
// your wallet. You might have labels on each of them.
// But whenever you change a label(and thus re-sign the
// file for that Nym when you save it), you only SIGN
// using one of your OWN nyms, for which you have a private
// key available for signing.
//
// Signer Nym?
// When testing, there is only one nym, so you just pass it
// twice. But in real production, a user will have a default
// signing nym, the same way that he might have a default 
// signing key in PGP, and that must be passed in whenever
// he changes the name on any of the other nyms in his wallet.
//(In order to properly sign and save the change.)
//
// Returns OT_TRUE(1) or OT_FALSE(0)
//
bool OTAPI_Wrap::SetNym_Name(
	const string & NYM_ID, 
	const string & SIGNER_NYM_ID, 
	const string & NYM_NEW_NAME
	)
{
	if (NYM_ID.empty())				{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "NYM_ID"				); OT_ASSERT(false); }
	if (SIGNER_NYM_ID.empty())		{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "SIGNER_NYM_ID"		); OT_ASSERT(false); }
	if (NYM_NEW_NAME.empty())		{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "NYM_NEW_NAME"		); OT_ASSERT(false); }

	const OTIdentifier	theNymID(NYM_ID), 
		theSignerNymID(SIGNER_NYM_ID);
	const OTString		strNymName(NYM_NEW_NAME);

	return OTAPI_Wrap::OTAPI()->SetNym_Name(theNymID, theSignerNymID, strNymName);
}

// The asset account's name is merely a client-side label.
bool OTAPI_Wrap::SetAccountWallet_Name(
	const string & ACCT_ID, 
	const string & SIGNER_NYM_ID, 
	const string & ACCT_NEW_NAME
	)
{
	if (ACCT_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCT_ID"			); OT_ASSERT(false); }
	if (SIGNER_NYM_ID.empty())		{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "SIGNER_NYM_ID"		); OT_ASSERT(false); }
	if (ACCT_NEW_NAME.empty())		{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCT_NEW_NAME"		); OT_ASSERT(false); }

	OTIdentifier	theAcctID(ACCT_ID),
		theSignerNymID(SIGNER_NYM_ID);
	OTString		strAcctNewName(ACCT_NEW_NAME);

	return OTAPI_Wrap::OTAPI()->SetAccount_Name(theAcctID, theSignerNymID, strAcctNewName);
}

bool OTAPI_Wrap::SetAssetType_Name(
	const string & ASSET_ID, 
	const string & STR_NEW_NAME
	)
{
	if (ASSET_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "ASSET_ID"			); OT_ASSERT(false); }
	if (STR_NEW_NAME.empty())		{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "STR_NEW_NAME"		); OT_ASSERT(false); }

	const OTIdentifier	theContractID(ASSET_ID);
	const OTString		strNewName(STR_NEW_NAME);

	return OTAPI_Wrap::OTAPI()->SetAssetType_Name(theContractID, strNewName);
}

bool OTAPI_Wrap::SetServer_Name(
	const string & SERVER_ID, 
	const string & STR_NEW_NAME
	)
{
	if (SERVER_ID.empty())		{ OTLog::sError("%s: Null SERVER_ID passed in!\n"		,__FUNCTION__); OT_ASSERT(false); }
	if (STR_NEW_NAME.empty())	{ OTLog::sError("%s: Null STR_NEW_NAME passed in!\n"	,__FUNCTION__); OT_ASSERT(false); }

	const OTIdentifier	theContractID(SERVER_ID);
	const OTString		strNewName(STR_NEW_NAME);

	return OTAPI_Wrap::OTAPI()->SetServer_Name(theContractID, strNewName);
}


//(Above) IMPORTANT: USE the above functions for setting the CLIENT-SIDE
// display labels that you use in your UI for the Nyms/Servers/AssetTypes/Accounts.
// These labels are stored SEPARATELY from their own files, in the wallet file.
//
// If you just added the contract, it will SET the label for you based on the contract type.
// like if it's an asset contract, it uses the currency name field from the asset contract.
// If it's a server contract it uses the entity short name. After that, it's 
// configurable for the user, and stays on client side, and persists via wallet.
//
// EVEN WHEN OT has to re-download one of those files, it will make sure to save
// the display label properly in the wallet.
//
// THIS MEANS *you*, as a client developer:
// 1) CAN DEPEND on these labels to have the right value.
// 2) Can expect them to start out with good default values.
// 3) Can configure them from there.
// 4) SHOULD DISPLAY THEM as appropriate in your application.
// 5) Of course, use the ID behind the scenes for making all your
// OT calls... just use the name for display purposes.
//




// ----------------------------------------------------------------------
/**

WRITE A CHEQUE ---(Returns the cheque in string form.)

==> WriteCheque() int32_ternally constructs an OTCheque 
and issues it, like so:

OTCheque theCheque( SERVER_ID, ASSET_TYPE_ID );

theCheque.IssueCheque( AMOUNT // The amount of the cheque, in string form, which OTAPI_Wrap
// will convert to a long int32_teger. Negative amounts 
// allowed, since that is how OT implements invoices.
//(An invoice is just a cheque with a negative amount.)

lTransactionNumber, // The API will supply this automatically, as long as
// there are some transaction numbers in the wallet.(Call
// getTransactionNumber() if your wallet needs more.)

VALID_FROM, VALID_TO, // Valid date range(in seconds since Jan 1970...)

ACCOUNT_ID, USER_ID, // User ID and Acct ID for SENDER.

CHEQUE_MEMO, // The memo for the cheque.(Can be empty or be NULL.)

RECIPIENT_USER_ID); // Recipient User ID is optional.(You can use an
// empty string here, to write a blank cheque, or pass NULL.)
*/
string OTAPI_Wrap::WriteCheque(
	const string & SERVER_ID,
	const string & CHEQUE_AMOUNT, 
	const time_t & VALID_FROM, 
	const time_t & VALID_TO,
	const string & SENDER_ACCT_ID,
	const string & SENDER_USER_ID,
	const string & CHEQUE_MEMO, 
	const string & RECIPIENT_USER_ID
	)
{
	if (SERVER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (CHEQUE_AMOUNT.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "CHEQUE_AMOUNT"		); OT_ASSERT(false); }
	if (0 >= VALID_FROM)			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "VALID_FROM"			); OT_ASSERT(false); }
	if (0 >= VALID_TO)				{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "VALID_TO"			); OT_ASSERT(false); }
	if (SENDER_ACCT_ID.empty())		{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "SENDER_ACCT_ID"		); OT_ASSERT(false); }
	if (SENDER_USER_ID.empty())		{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "SENDER_USER_ID"		); OT_ASSERT(false); }
	//if (CHEQUE_MEMO.empty())		{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "CHEQUE_MEMO"		); OT_ASSERT(false); }
	if (RECIPIENT_USER_ID.empty())	{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "RECIPIENT_USER_ID"	); OT_ASSERT(false); }

	const int64_t lAmount = StringToLong(CHEQUE_AMOUNT);

	const time_t time_From = VALID_FROM;
	const time_t time_To = VALID_TO;

	const OTIdentifier theServerID(SERVER_ID);
	const OTIdentifier theSenderAcctID(SENDER_ACCT_ID);
	const OTIdentifier theSenderUserID(SENDER_USER_ID);

	OTIdentifier theRecipientUserID;

	bool bHasRecipient = (RECIPIENT_USER_ID.length() > 2);

	if (bHasRecipient) theRecipientUserID.SetString(RECIPIENT_USER_ID);


	// ----------------------------------------------------
	OTString strMemo(CHEQUE_MEMO);

	OTCheque * pCheque = OTAPI_Wrap::OTAPI()->WriteCheque(theServerID,
		static_cast<long>(lAmount), 
		time_From, time_To,
		theSenderAcctID,
		theSenderUserID,
		strMemo, 
		bHasRecipient ? &(theRecipientUserID) : NULL);

	OTCleanup<OTCheque> theChequeAngel(pCheque); // Handles cleanup. (If necessary.)

	if (NULL == pCheque)
	{
		OTLog::sError("%s: OT_API::WriteCheque failed.\n",__FUNCTION__);
		return "";
	}

	// At this point, I know pCheque is good (and will be cleaned up automatically.)

	const OTString strCheque(*pCheque); // Extract the cheque to string form.

	return strCheque.Get();
}

// ----------------------------------------------------------------------
/**
DISCARD A CHEQUE -- returns OT_TRUE or OT_FALSE

When you write a cheque, your wallet software must use one of your transaction
numbers on the cheque. Even when you give the cheque to someone, a good wallet
should still store a copy of the cheque, until it is cashed.
This way, if you decide to "tear it up"(perhaps the recipient left the country!)
then you will still have a copy of the cheque, and you can get your transaction
number back before discarding it.

Why does it matter to get the transaction number back? Because once you sign
that number out, you will have to CONTINUE signing it out on EVERY RECEIPT until
that transaction is finally closed out. You are still responsible for that 
transaction number, until then.

So most likely, if the cheque is going nowhere, then you will want to RETRIEVE
the transaction number back from the cheque so you can use it on another transaction
instead. *THIS* IS THE FUNCTION YOU SHOULD USE TO DO THAT!!!!
*/

bool OTAPI_Wrap::DiscardCheque(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & ACCT_ID,
	const string & THE_CHEQUE
	)
{
	if (SERVER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }
	if (ACCT_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCT_ID"			); OT_ASSERT(false); }
	if (THE_CHEQUE.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_CHEQUE"			); OT_ASSERT(false); }

	OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theAcctID(ACCT_ID);
	OTString strCheque(THE_CHEQUE);

	return OTAPI_Wrap::OTAPI()->DiscardCheque(theServerID, theUserID, theAcctID, strCheque);
}



// ----------------------------------------------------------------------

/*


PROPOSE PAYMENT PLAN --- Returns the payment plan in string form.

(Called by Merchant.)

PARAMETER NOTES:
-- Payment Plan Delay, and Payment Plan Period, both default to 30 days(if you pass 0.)

-- Payment Plan Length, and Payment Plan Max Payments, both default to 0, which means
no maximum length and no maximum number of payments.

-----------------------------------------------------------------
FYI, the payment plan creation process(finally) is:

1) Payment plan is written, and signed, by the recipient.(This function: ProposePaymentPlan)
2) He sends it to the sender, who signs it and submits it.(ConfirmPaymentPlan and depositPaymentPlan)
3) The server loads the recipient nym to verify the transaction
number. The sender also had to burn a transaction number(to
submit it) so now, both have verified trns#s in this way.

----------------------------------------------------------------------------------------

FYI, here are all the OT library calls that are performed by this single API call:

OTPaymentPlan * pPlan = new OTPaymentPlan(pAccount->GetRealServerID(), 
pAccount->GetAssetTypeID(),
pAccount->GetRealAccountID(), pAccount->GetUserID(),
RECIPIENT_ACCT_ID, RECIPIENT_USER_ID);

----------------------------------------------------------------------------------------
From OTAgreement:(This must be called first, before the other two methods below can be called.) 

bool OTAgreement::SetProposal( const OTPseudonym & MERCHANT_NYM, const OTString & strConsideration,
const time_t & VALID_FROM=0, const time_t & VALID_TO=0);

----------------------------------------------------------------------------------------
(Optional initial payment):
bool OTPaymentPlan::SetInitialPayment(const long & lAmount, time_t tTimeUntilInitialPayment=0); // default: now.
----------------------------------------------------------------------------------------

These two(above and below) can be called independent of each other. You can 
have an initial payment, AND/OR a payment plan.

----------------------------------------------------------------------------------------
(Optional regular payments):
bool OTPaymentPlan::SetPaymentPlan(const long & lPaymentAmount, 
time_t tTimeUntilPlanStart=LENGTH_OF_MONTH_IN_SECONDS, // Default: 1st payment in 30 days
time_t tBetweenPayments=LENGTH_OF_MONTH_IN_SECONDS, // Default: 30 days.
time_t tPlanLength=0, int32_t nMaxPayments=0);
----------------------------------------------------------------------------------------
*/
string OTAPI_Wrap::ProposePaymentPlan(
	const string & SERVER_ID,
	// ----------------------------------------
	const time_t & VALID_FROM, // Default(0 or NULL) == NOW
	const time_t & VALID_TO, // Default(0 or NULL) == no expiry / cancel anytime
	// ----------------------------------------
	const string & SENDER_ACCT_ID, // Mandatory parameters.
	const string & SENDER_USER_ID, // Both sender and recipient must sign before submitting.
	// ----------------------------------------
	const string & PLAN_CONSIDERATION, // Like a memo.
	// ----------------------------------------
	const string & RECIPIENT_ACCT_ID, // NOT optional.
	const string & RECIPIENT_USER_ID, // Both sender and recipient must sign before submitting.
	// ------------------------------- 
	const string & INITIAL_PAYMENT_AMOUNT, // zero or NULL == no initial payment.
	const string & INITIAL_PAYMENT_DELAY, // seconds from creation date. Default is zero or NULL.
	// ---------------------------------------- .
	const string & PAYMENT_PLAN_AMOUNT, // zero or NULL == no regular payments.
	const string & PAYMENT_PLAN_DELAY, // No. of seconds from creation date. Default is zero or NULL.
	const string & PAYMENT_PLAN_PERIOD, // No. of seconds between payments. Default is zero or NULL.
	// --------------------------------------- 
	const string & PAYMENT_PLAN_LENGTH, // In seconds. Defaults to 0 or NULL(no maximum length.)
	const int32_t & PAYMENT_PLAN_MAX_PAYMENTS // int32_teger. Defaults to 0 or NULL(no maximum payments.)
	)
{
	if (SERVER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (SENDER_ACCT_ID.empty())		{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "SENDER_ACCT_ID"		); OT_ASSERT(false); }
	if (SENDER_USER_ID.empty())		{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "SENDER_USER_ID"		); OT_ASSERT(false); }
	if (RECIPIENT_ACCT_ID.empty())	{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "RECIPIENT_ACCT_ID"	); OT_ASSERT(false); }
	if (RECIPIENT_USER_ID.empty())	{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "RECIPIENT_USER_ID"	); OT_ASSERT(false); }

	const OTIdentifier theServerID(SERVER_ID);
	const OTIdentifier theSenderAcctID(SENDER_ACCT_ID);
	const OTIdentifier theSenderUserID(SENDER_USER_ID);
	const OTIdentifier theRecipientAcctID(RECIPIENT_ACCT_ID);
	const OTIdentifier theRecipientUserID(RECIPIENT_USER_ID);
	// --------------------------------------
	time_t tValidFrom = VALID_FROM;
	// --------------------------------------
	time_t tValidTo = VALID_TO;
	// --------------------------------------
	OTString strConsideration("(Consideration for the agreement between the parties is meant to be recorded here.)");
	if (!PLAN_CONSIDERATION.empty())
		strConsideration.Set(PLAN_CONSIDERATION);
	// --------------------------------------
	int64_t lInitialPaymentAmount = StringToLong(INITIAL_PAYMENT_AMOUNT);

	// --------------------------------------
	time_t tInitialPaymentDelay = StringToLong(INITIAL_PAYMENT_DELAY);
	// --------------------------------------
	int64_t lPaymentPlanAmount = StringToLong(PAYMENT_PLAN_AMOUNT);

	// --------------------------------------
	time_t tPaymentPlanDelay = StringToLong(PAYMENT_PLAN_DELAY);
	// --------------------------------------
	time_t tPaymentPlanPeriod = StringToLong(PAYMENT_PLAN_PERIOD);
	// --------------------------------------
	time_t tPaymentPlanLength = StringToLong(PAYMENT_PLAN_LENGTH);
	// --------------------------------------
	int32_t nPaymentPlanMaxPayments = PAYMENT_PLAN_MAX_PAYMENTS;
	// --------------------------------------	
	OTPaymentPlan * pPlan = OTAPI_Wrap::OTAPI()->ProposePaymentPlan(theServerID,
		// ----------------------------------------
		tValidFrom,	// Default (0) == NOW
		tValidTo,		// Default (0) == no expiry / cancel anytime
		// ----------------------------------------
		theSenderAcctID,
		theSenderUserID,
		// ----------------------------------------
		strConsideration, // Like a memo.
		// ----------------------------------------
		theRecipientAcctID,
		theRecipientUserID,
		// ----------------------------------------  
		static_cast<long>(lInitialPaymentAmount), 
		tInitialPaymentDelay,  
		// ---------------------------------------- 
		static_cast<long>(lPaymentPlanAmount),
		tPaymentPlanDelay,
		tPaymentPlanPeriod,	
		// ----------------------------------------
		tPaymentPlanLength,	
		nPaymentPlanMaxPayments);
	OTCleanup<OTPaymentPlan> theAngel(pPlan); // Handles cleanup. (If necessary.)
	if (NULL == pPlan)
	{
		OTLog::sError("%s: failed in OT_API_ProposePaymentPlan.\n",__FUNCTION__);
		return "";
	}
	// At this point, I know pPlan is good (and will be cleaned up automatically.)

	OTString strOutput(*pPlan); // Extract the payment plan to string form.

	return strOutput.Get();
}


// Called by Customer. Pass in the plan obtained in the above call.
//
string OTAPI_Wrap::ConfirmPaymentPlan(
	const string & SERVER_ID,
	const string & SENDER_USER_ID,
	const string & SENDER_ACCT_ID,
	const string & RECIPIENT_USER_ID,
	const string & PAYMENT_PLAN
	)
{
	if (SERVER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (SENDER_ACCT_ID.empty())		{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "SENDER_ACCT_ID"		); OT_ASSERT(false); }
	if (SENDER_USER_ID.empty())		{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "SENDER_USER_ID"		); OT_ASSERT(false); }
	if (RECIPIENT_USER_ID.empty())	{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "RECIPIENT_USER_ID"	); OT_ASSERT(false); }
	if (PAYMENT_PLAN.empty())		{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "PAYMENT_PLAN"		); OT_ASSERT(false); }

	const OTIdentifier theServerID(SERVER_ID);
	const OTIdentifier theSenderUserID(SENDER_USER_ID);
	const OTIdentifier theSenderAcctID(SENDER_ACCT_ID);
	const OTIdentifier theRecipientUserID(RECIPIENT_USER_ID);

	OTPaymentPlan thePlan;
	const OTString strPlan(PAYMENT_PLAN);

	if (!strPlan.Exists() || (false == thePlan.LoadContractFromString(strPlan)))
	{
		OTLog::sOutput(0, "%s: Failure loading payment plan from string.\n",__FUNCTION__);
		return "";
	}
	// --------------------------------------	
	bool bConfirmed = OTAPI_Wrap::OTAPI()->ConfirmPaymentPlan(theServerID,
		theSenderUserID,
		theSenderAcctID,
		theRecipientUserID,
		thePlan);
	if (false == bConfirmed)
	{
		OTLog::sOutput(0, "%s: failed in OT_API_ConfirmPaymentPlan().\n",__FUNCTION__);
		return "";
	}

	OTString strOutput(thePlan); // Extract the payment plan to string form.

	return strOutput.Get();
}



// -----------------------------------------------------------------


// SMART CONTRACTS


// RETURNS: the Smart Contract itself.(Or NULL.)
//
string OTAPI_Wrap::Create_SmartContract(
	const string & SERVER_ID,
	const string & SIGNER_NYM_ID,// Use any Nym you wish here.(The signing at this point32_t is only to cause a save.)
	// ----------------------------------------
	const time_t & VALID_FROM, // Default(0 or NULL) == NOW
	const time_t & VALID_TO // Default(0 or NULL) == no expiry / cancel anytime
	)
{
	if (SERVER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (SIGNER_NYM_ID.empty())		{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "SIGNER_NYM_ID"		); OT_ASSERT(false); }

	// -----------------------------------------------------
	const OTIdentifier theServerID(SERVER_ID), theSignerNymID(SIGNER_NYM_ID);
	// -----------------------------------------------------
	time_t tValidFrom = VALID_FROM;
	// --------------------------------------
	time_t tValidTo = VALID_TO;	
	// --------------------------------------
	OTString strOutput;

	const bool bCreated = OTAPI_Wrap::OTAPI()->Create_SmartContract(theServerID, 
		theSignerNymID, 
		tValidFrom,	// Default (0 or NULL) == NOW
		tValidTo,	// Default (0 or NULL) == no expiry / cancel anytime
		strOutput);
	if (!bCreated || !strOutput.Exists())
		return "";
	// -----------------------------------------------------
	// Success!
	//
	return strOutput.Get(); 	
}
// ----------------------------------------

// ------------------

//
// todo: Someday add a parameter here BYLAW_LANGUAGE so that people can use
// custom languages in their scripts. For now I have a default language, so 
// I'll just make that the default.(There's only one language right now anyway.)
//
// returns: the updated smart contract(or NULL)
string OTAPI_Wrap::SmartContract_AddBylaw(
	const string & THE_CONTRACT, // The contract, about to have the bylaw added to it.
	const string & SIGNER_NYM_ID, // Use any Nym you wish here.(The signing at this point32_t is only to cause a save.)
	// ----------------------------------------
	const string & BYLAW_NAME // The Bylaw's NAME as referenced in the smart contract.(And the scripts...)
	)
{
	if (THE_CONTRACT.empty())		{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_CONTRACT"		); OT_ASSERT(false); }
	if (SIGNER_NYM_ID.empty())		{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "SIGNER_NYM_ID"		); OT_ASSERT(false); }
	if (BYLAW_NAME.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "BYLAW_NAME"			); OT_ASSERT(false); }

	// -----------------------------------------------------
	const OTString		strContract(THE_CONTRACT), strBylawName(BYLAW_NAME);
	const OTIdentifier	theSignerNymID(SIGNER_NYM_ID);
	// -----------------------------------------------------
	OTString strOutput;

	const bool bAdded = OTAPI_Wrap::OTAPI()->SmartContract_AddBylaw(strContract,		// The contract, about to have the bylaw added to it.
		theSignerNymID,	// Use any Nym you wish here. (The signing at this point is only to cause a save.)
		strBylawName,		// The Bylaw's NAME as referenced in the smart contract. (And the scripts...)
		strOutput);
	if (!bAdded || !strOutput.Exists())
		return "";
	// -----------------------------------------------------
	// Success!
	//
	return strOutput.Get();
}

// returns: the updated smart contract(or NULL)
string OTAPI_Wrap::SmartContract_AddClause(
	const string & THE_CONTRACT, // The contract, about to have the clause added to it.
	const string & SIGNER_NYM_ID, // Use any Nym you wish here.(The signing at this point32_t is only to cause a save.)
	// ----------------------------------------
	const string & BYLAW_NAME, // Should already be on the contract.(This way we can find it.)
	// ----------------------------------------
	const string & CLAUSE_NAME, // The Clause's name as referenced in the smart contract.(And the scripts...)
	const string & SOURCE_CODE // The actual source code for the clause.
	)
{
	if (THE_CONTRACT.empty())		{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_CONTRACT"		); OT_ASSERT(false); }
	if (SIGNER_NYM_ID.empty())		{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "SIGNER_NYM_ID"		); OT_ASSERT(false); }
	if (BYLAW_NAME.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "BYLAW_NAME"			); OT_ASSERT(false); }
	if (CLAUSE_NAME.empty())		{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "CLAUSE_NAME"		); OT_ASSERT(false); }
	if (SOURCE_CODE.empty())		{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "SOURCE_CODE"		); OT_ASSERT(false); }

	// -----------------------------------------------------
	const OTString		strContract(THE_CONTRACT),	strBylawName(BYLAW_NAME), 
		strClauseName(CLAUSE_NAME),	strSourceCode(SOURCE_CODE);
	const OTIdentifier	theSignerNymID(SIGNER_NYM_ID);
	// -----------------------------------------------------
	OTString strOutput;

	const bool bAdded = OTAPI_Wrap::OTAPI()->SmartContract_AddClause(strContract,	// The contract, about to have the clause added to it.
		theSignerNymID,	// Use any Nym you wish here. (The signing at this point is only to cause a save.)
		// ----------------------------------------
		strBylawName,	// Should already be on the contract. (This way we can find it.)
		// ----------------------------------------
		strClauseName,	// The Clause's name as referenced in the smart contract. (And the scripts...)
		strSourceCode,	// The actual source code for the clause.
		strOutput);
	if (!bAdded || !strOutput.Exists())
		return "";
	// -----------------------------------------------------
	// Success!
	//
	return strOutput.Get();
}

// returns: the updated smart contract(or NULL)
string OTAPI_Wrap::SmartContract_AddVariable(
	const string & THE_CONTRACT, // The contract, about to have the variabnle added to it.
	const string & SIGNER_NYM_ID, // Use any Nym you wish here.(The signing at this point32_t is only to cause a save.)
	// ----------------------------------------
	const string & BYLAW_NAME, // Should already be on the contract.(This way we can find it.)
	// ----------------------------------------
	const string & VAR_NAME, // The Variable's name as referenced in the smart contract.(And the scripts...)
	const string & VAR_ACCESS, // "constant", "persistent", or "important".
	const string & VAR_TYPE, // "string", "long", or "bool"
	const string & VAR_VALUE // Contains a string. If type is long, atol() will be used to convert value to a long. If type is bool, the strings "true" or "false" are expected here in order to convert to a bool.
	)
{
	if (THE_CONTRACT.empty())		{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_CONTRACT"		); OT_ASSERT(false); }
	if (SIGNER_NYM_ID.empty())		{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "SIGNER_NYM_ID"		); OT_ASSERT(false); }
	if (BYLAW_NAME.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "BYLAW_NAME"			); OT_ASSERT(false); }
	if (VAR_NAME.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "VAR_NAME"			); OT_ASSERT(false); }
	if (VAR_ACCESS.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "VAR_ACCESS"			); OT_ASSERT(false); }
	if (VAR_TYPE.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "VAR_TYPE"			); OT_ASSERT(false); }
	if (VAR_VALUE.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "VAR_VALUE"			); OT_ASSERT(false); }

	// -----------------------------------------------------
	const OTString		strContract(THE_CONTRACT),	strBylawName(BYLAW_NAME), 
		strVarName(VAR_NAME),		strVarAccess(VAR_ACCESS),
		strVarType(VAR_TYPE),		strVarValue(VAR_VALUE);
	const OTIdentifier theSignerNymID(SIGNER_NYM_ID);
	// -----------------------------------------------------
	OTString strOutput;

	const bool bAdded = OTAPI_Wrap::OTAPI()->SmartContract_AddVariable(strContract,		// The contract, about to have the clause added to it.
		theSignerNymID,	// Use any Nym you wish here. (The signing at this point is only to cause a save.)
		// ----------------------------------------
		strBylawName,	// Should already be on the contract. (This way we can find it.)
		// ----------------------------------------
		strVarName,		// The Variable's name as referenced in the smart contract. (And the scripts...)
		strVarAccess,	// "constant", "persistent", or "important".
		strVarType,		// "string", "long", or "bool"
		strVarValue,		// Contains a string. If type is long, atol() will be used to convert value to a long. If type is bool, the strings "true" or "false" are expected here in order to convert to a bool.
		// ----------------------------------------
		strOutput);
	if (!bAdded || !strOutput.Exists())
		return "";
	// -----------------------------------------------------
	// Success!
	//
	return strOutput.Get();
}

// returns: the updated smart contract(or NULL)
string OTAPI_Wrap::SmartContract_AddCallback(
	const string & THE_CONTRACT, // The contract, about to have the callback added to it.
	const string & SIGNER_NYM_ID, // Use any Nym you wish here.(The signing at this point32_t is only to cause a save.)
	// ----------------------------------------
	const string & BYLAW_NAME, // Should already be on the contract.(This way we can find it.)
	// ----------------------------------------
	const string & CALLBACK_NAME, // The Callback's name as referenced in the smart contract.(And the scripts...)
	const string & CLAUSE_NAME // The actual clause that will be triggered by the callback.(Must exist.)
	)
{
	if (THE_CONTRACT.empty())		{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_CONTRACT"		); OT_ASSERT(false); }
	if (SIGNER_NYM_ID.empty())		{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "SIGNER_NYM_ID"		); OT_ASSERT(false); }
	if (BYLAW_NAME.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "BYLAW_NAME"			); OT_ASSERT(false); }
	if (CALLBACK_NAME.empty())		{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "CALLBACK_NAME"		); OT_ASSERT(false); }
	if (CLAUSE_NAME.empty())		{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "CLAUSE_NAME"		); OT_ASSERT(false); }

	// -----------------------------------------------------
	const OTString		strContract(THE_CONTRACT),	strBylawName(BYLAW_NAME), 
		strCallbackName(CALLBACK_NAME),	strClauseName(CLAUSE_NAME);
	const OTIdentifier theSignerNymID(SIGNER_NYM_ID);
	// -----------------------------------------------------
	OTString strOutput;

	const bool bAdded = OTAPI_Wrap::OTAPI()->SmartContract_AddCallback(strContract,		// The contract, about to have the clause added to it.
		theSignerNymID,	// Use any Nym you wish here. (The signing at this point is only to cause a save.)
		// ----------------------------------------
		strBylawName,	// Should already be on the contract. (This way we can find it.)
		// ----------------------------------------
		strCallbackName,	// The Callback's name as referenced in the smart contract. (And the scripts...)
		strClauseName,	// The actual clause that will be triggered by the callback. (Must exist.)
		strOutput);
	if (!bAdded || !strOutput.Exists())
		return "";
	// -----------------------------------------------------
	// Success!
	//	
	return strOutput.Get();
}

// returns: the updated smart contract(or NULL)
string OTAPI_Wrap::SmartContract_AddHook(
	const string & THE_CONTRACT, // The contract, about to have the hook added to it.
	const string & SIGNER_NYM_ID, // Use any Nym you wish here.(The signing at this point32_t is only to cause a save.)
	// ----------------------------------------
	const string & BYLAW_NAME, // Should already be on the contract.(This way we can find it.)
	// ----------------------------------------
	const string & HOOK_NAME, // The Hook's name as referenced in the smart contract.(And the scripts...)
	const string & CLAUSE_NAME // The actual clause that will be triggered by the hook.(You can call this multiple times, and have multiple clauses trigger on the same hook.)
	)
{
	if (THE_CONTRACT.empty())		{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_CONTRACT"		); OT_ASSERT(false); }
	if (SIGNER_NYM_ID.empty())		{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "SIGNER_NYM_ID"		); OT_ASSERT(false); }
	if (BYLAW_NAME.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "BYLAW_NAME"			); OT_ASSERT(false); }
	if (HOOK_NAME.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "HOOK_NAME"			); OT_ASSERT(false); }
	if (CLAUSE_NAME.empty())		{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "CLAUSE_NAME"		); OT_ASSERT(false); }

	// -----------------------------------------------------
	const OTString		strContract(THE_CONTRACT),	strBylawName(BYLAW_NAME), 
		strHookName(HOOK_NAME),		strClauseName(CLAUSE_NAME);
	const OTIdentifier theSignerNymID(SIGNER_NYM_ID);
	// -----------------------------------------------------
	OTString strOutput;

	const bool bAdded = OTAPI_Wrap::OTAPI()->SmartContract_AddHook(strContract,		// The contract, about to have the clause added to it.
		theSignerNymID,	// Use any Nym you wish here. (The signing at this point is only to cause a save.)
		// ----------------------------------------
		strBylawName,	// Should already be on the contract. (This way we can find it.)
		// ----------------------------------------
		strHookName,		// The Hook's name as referenced in the smart contract. (And the scripts...)
		strClauseName,	// The actual clause that will be triggered by the hook. (You can call this multiple times, and have multiple clauses trigger on the same hook.)
		strOutput);
	if (!bAdded || !strOutput.Exists())
		return "";
	// -----------------------------------------------------
	// Success!
	//	
	return strOutput.Get();
}

// --------------------------------------------------------------

// RETURNS: Updated version of THE_CONTRACT.(Or NULL.)
string OTAPI_Wrap::SmartContract_AddParty(
	const string & THE_CONTRACT, // The contract, about to have the party added to it.
	const string & SIGNER_NYM_ID, // Use any Nym you wish here.(The signing at this point32_t is only to cause a save.)
	// ----------------------------------------
	const string & PARTY_NAME, // The Party's NAME as referenced in the smart contract.(And the scripts...)
	// ----------------------------------------
	const string & AGENT_NAME // An AGENT will be added by default for this party. Need Agent NAME.
	)
{
	if (THE_CONTRACT.empty())		{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_CONTRACT"		); OT_ASSERT(false); }
	if (SIGNER_NYM_ID.empty())		{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "SIGNER_NYM_ID"		); OT_ASSERT(false); }
	if (PARTY_NAME.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "PARTY_NAME"			); OT_ASSERT(false); }
	if (AGENT_NAME.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "AGENT_NAME"			); OT_ASSERT(false); }

	// -----------------------------------------------------
	const OTString		strContract(THE_CONTRACT),	strPartyName(PARTY_NAME), 
		strAgentName(AGENT_NAME);
	const OTIdentifier theSignerNymID(SIGNER_NYM_ID);
	// -----------------------------------------------------
	OTString strOutput;

	const bool bAdded = OTAPI_Wrap::OTAPI()->SmartContract_AddParty(strContract,		// The contract, about to have the bylaw added to it.
		theSignerNymID,	// Use any Nym you wish here. (The signing at this point is only to cause a save.)
		// ----------------------------------------
		strPartyName,		// The Party's NAME as referenced in the smart contract. (And the scripts...)
		strAgentName,		// An AGENT will be added by default for this party. Need Agent NAME.
		strOutput);
	if (!bAdded || !strOutput.Exists())
		return "";
	// -----------------------------------------------------
	// Success!
	//	
	return strOutput.Get();
}

//(FYI, that is basically the only option, until I code Entities and Roles. Until then, a party can ONLY be
// a Nym, with himself as the agent representing that same party. Nym ID is supplied on ConfirmParty() below.)

// ----------------------------------------

// Used when creating a theoretical smart contract(that could be used over and over again with different parties.)
//
// returns: the updated smart contract(or NULL)
string OTAPI_Wrap::SmartContract_AddAccount(
	const string & THE_CONTRACT, // The contract, about to have the account added to it.
	const string & SIGNER_NYM_ID, // Use any Nym you wish here.(The signing at this point32_t is only to cause a save.)
	// ----------------------------------------
	const string & PARTY_NAME, // The Party's NAME as referenced in the smart contract.(And the scripts...)
	// ----------------------------------------
	const string & ACCT_NAME, // The Account's name as referenced in the smart contract
	const string & ASSET_TYPE_ID // Asset Type ID for the Account.
	)
{
	if (THE_CONTRACT.empty())		{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_CONTRACT"		); OT_ASSERT(false); }
	if (SIGNER_NYM_ID.empty())		{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "SIGNER_NYM_ID"		); OT_ASSERT(false); }
	if (PARTY_NAME.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "PARTY_NAME"			); OT_ASSERT(false); }
	if (ACCT_NAME.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCT_NAME"			); OT_ASSERT(false); }
	if (ASSET_TYPE_ID.empty())		{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "ASSET_TYPE_ID"		); OT_ASSERT(false); }

	// -----------------------------------------------------
	const OTString		strContract(THE_CONTRACT),	strPartyName(PARTY_NAME), 
		strAcctName(ACCT_NAME),		strAssetTypeID(ASSET_TYPE_ID);
	const OTIdentifier theSignerNymID(SIGNER_NYM_ID);
	// -----------------------------------------------------
	OTString strOutput;

	const bool bAdded = OTAPI_Wrap::OTAPI()->SmartContract_AddAccount(strContract,		// The contract, about to have the clause added to it.
		theSignerNymID,	// Use any Nym you wish here. (The signing at this point is only to cause a save.)
		// ----------------------------------------
		strPartyName,		// The Party's NAME as referenced in the smart contract. (And the scripts...)
		// ----------------------------------------
		strAcctName,		// The Account's name as referenced in the smart contract
		strAssetTypeID,	// Asset Type ID for the Account.
		strOutput);
	if (!bAdded || !strOutput.Exists())
		return "";
	// -----------------------------------------------------
	// Success!
	//	
	return strOutput.Get();
}	

// ----------------------------------------

// This function returns the count of how many trans#s a Nym needs in order to confirm as 
// a specific agent for a contract.(An opening number is needed for every party of which
// agent is the authorizing agent, plus a closing number for every acct of which agent is the
// authorized agent.)
//
int32_t OTAPI_Wrap::SmartContract_CountNumsNeeded(
	const string & THE_CONTRACT, // The smart contract, about to be queried by this function.
	const string & AGENT_NAME
	)
{
	if (THE_CONTRACT.empty())		{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_CONTRACT"		); OT_ASSERT(false); }
	if (AGENT_NAME.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "AGENT_NAME"			); OT_ASSERT(false); }
	// -------------------------------------------------------------
	const OTString		strContract(THE_CONTRACT), strAgentName(AGENT_NAME);
	// -------------------------------------------------------------
	//
	const int nCount = OTAPI_Wrap::OTAPI()->SmartContract_CountNumsNeeded(strContract, strAgentName);

	return nCount;
}

// ----------------------------------------
// Used when taking a theoretical smart contract, and setting it up to use specific Nyms and accounts. This function sets the ACCT ID for the acct specified by party name and acct name.
// Returns the updated smart contract(or NULL.)
string OTAPI_Wrap::SmartContract_ConfirmAccount(
	const string & THE_CONTRACT, // The smart contract, about to be changed by this function.
	const string & SIGNER_NYM_ID, // Use any Nym you wish here.(The signing at this point32_t is only to cause a save.)
	// ----------------------------------------
	const string & PARTY_NAME, // Should already be on the contract.(This way we can find it.)
	// ----------------------------------------
	const string & ACCT_NAME, // Should already be on the contract.(This way we can find it.)
	const string & AGENT_NAME, // The agent name for this asset account.
	const string & ACCT_ID // AcctID for the asset account.(For acct_name).
	)
{
	if (THE_CONTRACT.empty())		{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_CONTRACT"		); OT_ASSERT(false); }
	if (SIGNER_NYM_ID.empty())		{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "SIGNER_NYM_ID"		); OT_ASSERT(false); }
	if (PARTY_NAME.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "PARTY_NAME"			); OT_ASSERT(false); }
	if (ACCT_NAME.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCT_NAME"			); OT_ASSERT(false); }
	if (AGENT_NAME.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "AGENT_NAME"			); OT_ASSERT(false); }
	if (ACCT_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCT_ID"			); OT_ASSERT(false); }

	// -----------------------------------------------------
	const OTString		strContract(THE_CONTRACT), strPartyName(PARTY_NAME);
	const OTString		strAccountID(ACCT_ID), strAcctName(ACCT_NAME), strAgentName(AGENT_NAME);
	const OTIdentifier	theSignerNymID(SIGNER_NYM_ID), theAcctID(strAccountID);
	// -----------------------------------------------------
	OTString strOutput;

	const bool bConfirmed = OTAPI_Wrap::OTAPI()->SmartContract_ConfirmAccount(strContract, 
		theSignerNymID, 
		strPartyName, 
		strAcctName, 
		strAgentName,
		strAccountID, 
		strOutput);
	if (!bConfirmed || !strOutput.Exists())
		return "";
	// -----------------------------------------------------
	// Success!
	//	
	return strOutput.Get(); 	
}



// Called by each Party. Pass in the smart contract obtained in the above call.
// Call SmartContract_ConfirmAccount() first, as much as you need to.
// Returns the updated smart contract(or NULL.)
string OTAPI_Wrap::SmartContract_ConfirmParty(
	const string & THE_CONTRACT, // The smart contract, about to be changed by this function.
	const string & PARTY_NAME, // Should already be on the contract. This way we can find it.
	// ----------------------------------------
	const string & NYM_ID // Nym ID for the party, the actual owner, 
	)
{
	if (THE_CONTRACT.empty())		{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_CONTRACT"		); OT_ASSERT(false); }
	if (PARTY_NAME.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "PARTY_NAME"			); OT_ASSERT(false); }
	if (NYM_ID.empty())				{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "NYM_ID"				); OT_ASSERT(false); }

	// -----------------------------------------------------
	const OTIdentifier	theNymID(NYM_ID);
	const OTString		strContract(THE_CONTRACT), strPartyName(PARTY_NAME);
	// -----------------------------------------------------
	OTString strOutput;

	const bool bConfirmed = OTAPI_Wrap::OTAPI()->SmartContract_ConfirmParty(strContract,	// The smart contract, about to be changed by this function.
		strPartyName,	// Should already be on the contract. This way we can find it.
		// ----------------------------------------
		theNymID,		// Nym ID for the party, the actual owner, 
		strOutput);
	if (!bConfirmed || !strOutput.Exists())
		return "";
	// -----------------------------------------------------
	// Success!
	//		
	return strOutput.Get(); 	
}

// ===> AS WELL AS for the default AGENT of that party.

// --------------------------------------------------
// ACTIVATE SMART CONTRACT
// Take an existing smart contract, which has already been set up, confirmed, etc,
// and then activate it on the server so it can start processing.
//
// See Create_SmartContract(etc.)
//
int32_t OTAPI_Wrap::activateSmartContract(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & THE_SMART_CONTRACT
	)
{
	if (SERVER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }
	if (THE_SMART_CONTRACT.empty())	{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_SMART_CONTRACT"	); OT_ASSERT(false); }

	const OTIdentifier	theServerID(SERVER_ID), theUserID(USER_ID);
	const OTString		strContract(THE_SMART_CONTRACT);

	return OTAPI_Wrap::OTAPI()->activateSmartContract(theServerID, theUserID, strContract);	
}
// --------------------------------------------------

// If a smart contract is already running on the server, this allows a party
// to trigger clauses on that smart contract, by name. This is NOT a transaction,
// but it DOES message the server.
//
// Returns int32_t:
// -1 means error; no message was sent.
// -2 means the message was sent, but the request number must be passed as a string, so call GetLargeRequestNum.
// 0 means NO error, but also: no message was sent.
// >0 means NO error, and the message was sent, and the request number fits int32_to an int32_teger...
// ...and in fact the requestNum IS the return value!
// ===> In 99% of cases, this LAST option is what actually happens!!
//
int32_t OTAPI_Wrap::triggerClause(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & TRANSACTION_NUMBER,
	const string & CLAUSE_NAME,
	const string & STR_PARAM
	)
{
	if (SERVER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }
	if (TRANSACTION_NUMBER.empty())	{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "TRANSACTION_NUMBER"	); OT_ASSERT(false); }
	if (CLAUSE_NAME.empty())		{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "CLAUSE_NAME"		); OT_ASSERT(false); }

	const OTIdentifier	theServerID(SERVER_ID), theUserID(USER_ID);
	const OTString		strClauseName(CLAUSE_NAME);
	const int64_t			lTransactionNum = StringToLong(TRANSACTION_NUMBER);

	const OTString strParam((STR_PARAM.empty()) ? "" : STR_PARAM);

	return OTAPI_Wrap::OTAPI()->triggerClause(theServerID, theUserID, static_cast<long>(lTransactionNum), strClauseName, (STR_PARAM.empty()) ? NULL : &strParam);
}




/*
Msg_HarvestTransactionNumbers

This function will load up the cron item(which is either a market offer, a payment plan,
or a SMART CONTRACT.) UPDATE: this function operates on messages, not cron items.

Then it will try to harvest all of the closing transaction numbers for NYM_ID that are
available to be harvested from THE_CRON_ITEM.(There might be zero #s available for that
Nym, which is still a success and will return true. False means error.)

YOU MIGHT ASK:

WHY WOULD I WANT to harvest ONLY the closing numbers for the Nym, and not the OPENING
numbers as well? The answer is because for this Nym, the opening number might already
be burned. For example, if Nym just tried to activate a smart contract, and the activation
FAILED, then maybe the opening number is already gone, even though his closing numbers, on the
other hand, are still valid for retrieval.(I have to double check this.)

HOWEVER, what if the MESSAGE failed, before it even TRIED the transaction? In which case,
the opening number is still good also, and should be retrieved. 

Remember, I have to keep signing for my transaction numbers until they are finally closed out.
They will appear on EVERY balance agreement and transaction statement from here until the end
of time, whenever I finally close out those numbers. If some of them are still good on a failed
transaction, then I want to retrieve them so I can use them, and eventually close them out.

==> Whereas, what if I am the PARTY to a smart contract, but I am not the actual ACTIVATOR / ORIGINATOR
(who activated the smart contract on the server). Therefore I never sent any transaction to the
server, and I never burned my opening number. It's probably still a good #. If my wallet is not a piece
of shit, then I should have a stored copy of any contract that I signed. If it turns out in the future
that that contract wasn't activated, then I can retrieve not only my closing numbers, but my OPENING
number as well! IN THAT CASE, I would call HarvestAllNumbers() instead of HarvestClosingNumbers().

// -----------------

UPDATE: The above logic is now handled automatically in HarvestTransactionNumbers.
Therefore HarvestClosingNumbers and HarvestAllNumbers have been removed.

*/

bool OTAPI_Wrap::Msg_HarvestTransactionNumbers(
	const string & THE_MESSAGE,
	const string & USER_ID,
	const bool & bHarvestingForRetry, // OT_BOOL
	const bool & bReplyWasSuccess, // OT_BOOL
	const bool & bReplyWasFailure, // OT_BOOL 
	const bool & bTransactionWasSuccess, // OT_BOOL
	const bool & bTransactionWasFailure // OT_BOOL
	)
{
	// -----------------------------------------------------
	bool bInitialized = OTAPI_Wrap::OTAPI()->IsInitialized();
	if (!bInitialized) { OTLog::sError("%s: Not initialized; call OT_API::Init first.\n",__FUNCTION__);	OT_ASSERT(false); }

	if (THE_MESSAGE.empty())		{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_MESSAGE"		); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }

	// -----------------------------------------------------

	const OTIdentifier theUserID(USER_ID);

	// -----------------------------------------------------
	OTMessage   theMessage;
	const
		OTString    strMsg(THE_MESSAGE);

	if (!strMsg.Exists())
	{
		OTLog::sError("%s: Failed trying to load message from empty string.\n", __FUNCTION__);
		return false;
	}
	// -----------------------------------

	if (!theMessage.LoadContractFromString(strMsg))
	{
		// -----------------------------------------------------
		// Unfortunately the ONLY reason we are loading up this cron item here,
		// is so we can get the server ID off of it.
		//
		OTCronItem * pCronItem = OTCronItem::NewCronItem(strMsg);
		OTCleanup<OTCronItem> theContractAngel;
		if (NULL == pCronItem)
		{
			OTLog::sError("%s: Failed trying to load message from string.",__FUNCTION__);

			OTLog::sOutput(0, "%s: Error trying to load the cron item from string (a cron item is a smart contract, or "
				"some other recurring transaction such as a market offer, or a payment plan.) Contents:\n\n%s\n\n",
				__FUNCTION__, strMsg.Get());
			return false;
		}
		else
			theContractAngel.SetCleanupTarget(*pCronItem);  // Auto-cleanup.
		// -----------------------------------------------------

		// If a CronItem is passed in here instead of a Message, that means the client
		// didn't even TRY to send the message. He failed before reaching that point.
		// Therefore in this one, strange case, we don't really care about all the bools
		// that were passed in here. We're just going to harvest ALL the numbers, and
		// ASSUME all the bools were false.
		// Here goes...
		//
		const bool bSuccessCronItem = OTAPI_Wrap::OTAPI()->HarvestAllNumbers(pCronItem->GetServerID(), theUserID, strMsg);

		return bSuccessCronItem;
	}
	// ---------------------------------------------------
	// By this point, we have the actual message loaded up.
	//
	return OTAPI_Wrap::OTAPI()->Msg_HarvestTransactionNumbers(
		theMessage,
		theUserID,
		bHarvestingForRetry,
		bReplyWasSuccess,
		bReplyWasFailure,
		bTransactionWasSuccess,
		bTransactionWasFailure
		);
}

///Returns OT_BOOL
//int32_t HarvestClosingNumbers(const string & SERVER_ID,
//   string NYM_ID,
//   string THE_CRON_ITEM);
//
//
//
///Returns OT_BOOL
//int32_t HarvestAllNumbers(const string & SERVER_ID,
//   string NYM_ID,
//   string THE_CRON_ITEM);


// -----------------------------------------------------------------



// -----------------------------------------------------------------
// LOAD USER PUBLIC KEY -- from local storage
//
//(returns as string)
//
// MEANT TO BE USED in cases where a private key is also available.
//
// returns NULL, or a public key.
string OTAPI_Wrap::LoadUserPubkey(const string & USER_ID)
{
	if (USER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }

	OTString strPubkey; // For the output

	OTIdentifier	NYM_ID(USER_ID);

	// There is an OT_ASSERT in here for memory failure,
	// but it still might return NULL if various verification fails.
	OTPseudonym *  pNym = (OTAPI_Wrap::It()->p_OTAPI->LoadPrivateNym(NYM_ID)); 


	if (NULL == pNym)
	{
		OTString strNymID(NYM_ID);
		OTLog::sOutput(0, "%s: Failure calling OT_API::LoadPrivateNym: %s\n", __FUNCTION__, strNymID.Get());
	}
	else if (false == pNym->GetPublicKey().GetPublicKey(strPubkey))
	{
		OTString strNymID(NYM_ID);
		OTLog::sOutput(0, "%s: Failure retrieving pubkey from Nym: %s\n", __FUNCTION__, strNymID.Get());
	}
	else // success 
	{
		return strPubkey.Get(); 
	}

	return "";
}


// -----------------------------------------------------------------
// LOAD PUBLIC KEY -- from local storage
//
//(returns as string)
//
// MEANT TO BE USED in cases where a private key is NOT available.
//
// returns NULL, or a public key.
string OTAPI_Wrap::LoadPubkey(const string & USER_ID)
{
	if (USER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }

	OTString strPubkey; // For the output

	// ---------------------------------------------------------

	OTIdentifier	NYM_ID(USER_ID);

	// There is an OT_ASSERT in here for memory failure,
	// but it still might return NULL if various verification fails.
	OTPseudonym *  pNym = (OTAPI_Wrap::OTAPI()->LoadPublicNym(NYM_ID));

	if (NULL == pNym) // If he's not in the "address book" then let's see if this is a private Nym.
	{
		pNym = (OTAPI_Wrap::OTAPI()->LoadPrivateNym(NYM_ID));
	}

	// ---------------------------------------------------------

	if (NULL == pNym)
	{
		std::tr1::shared_ptr<OTPseudonym> pNym(new OTPseudonym(NYM_ID));

		if (NULL == pNym)		{ OTLog::sError("%s: Error allocating memory in the OT API.\n"			,__FUNCTION__); OT_ASSERT(false); }

		// First load the public key
		if (false == pNym->LoadPublicKey())
		{
			OTString strNymID(NYM_ID);
			OTLog::sError("%s: Failure loading Nym public key: %s\n", __FUNCTION__, strNymID.Get());

		}
		else if (false == pNym->VerifyPseudonym())
		{
			OTString strNymID(NYM_ID);
			OTLog::sError("%s: Failure verifying Nym public key: %s\n", __FUNCTION__, strNymID.Get());
		}
	}

	// ---------------------------------------------------------


	if (NULL == pNym)
	{
		OTString strNymID(NYM_ID);
		OTLog::sOutput(0, "%s: Failure: %s\n", __FUNCTION__, strNymID.Get());
	}
	else if (false == pNym->GetPublicKey().GetPublicKey(strPubkey, false)) // bEscaped defaults to true. 6/13/12
	{	
		OTString strNymID(NYM_ID);
		OTLog::sOutput(0, "%s: Failure retrieving pubkey from Nym: %s\n", __FUNCTION__, strNymID.Get());
	}
	else // success
	{
		return strPubkey.Get();
	}

	return "";
}





// ------------------------------------------------------------------------
//
// Verify that USER_ID(including its Private Key) is an 
// available and verified user in local storage.
//
// Loads the user's private key, verifies, then returns OT_TRUE or OT_FALSE.
//
// returns OT_BOOL
bool OTAPI_Wrap::VerifyUserPrivateKey(const string & USER_ID)
{
	if (USER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }

	// Get the string into usable form.
	OTIdentifier	NYM_ID(USER_ID);

	// There is an OT_ASSERT in here for memory failure,
	// but it still might return NULL if various verification fails.
	OTPseudonym *  pNym = (OTAPI_Wrap::OTAPI()->LoadPrivateNym(NYM_ID)); 



	if (NULL == pNym)
	{
		OTString strNymID(NYM_ID);
		OTLog::sOutput(0, "%s: Failure calling OT_API::LoadPrivateNym:\n%s\n", __FUNCTION__, strNymID.Get());
	}
	else
	{
		return true;
	}

	return false;
}






// --------------------------------------------------------------
// LOAD PURSE or Mint32_t or ASSET CONTRACT or SERVER CONTRACT --(from local storage)
//
// Based on Asset Type ID: load a purse, a public mint32_t, or an asset/server contract
// and return it as a string -- or return NULL if it wasn't found.
//
// returns NULL, or a purse.
string OTAPI_Wrap::LoadPurse(
	const string & SERVER_ID,
	const string & ASSET_TYPE_ID,
	const string & USER_ID
	)
{
	if (SERVER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (ASSET_TYPE_ID.empty())		{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "ASSET_TYPE_ID"		); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }

	const OTIdentifier theServerID(SERVER_ID);
	const OTIdentifier theAssetID(ASSET_TYPE_ID);
	const OTIdentifier theUserID(USER_ID);

	// There is an OT_ASSERT in here for memory failure,
	// but it still might return NULL if various verification fails.
	OTPurse * pPurse = OTAPI_Wrap::OTAPI()->LoadPurse(theServerID, theAssetID, theUserID); 

	// Make sure it gets cleaned up when this goes out of scope.
	OTCleanup<OTPurse>	thePurseAngel(pPurse); // I pass the pointer, in case it's NULL.

	if (NULL == pPurse)
	{
		OTLog::sOutput(0, "%s: received null when called OT_API::LoadPurse().\nServer: %s Asset Type: %s\n", __FUNCTION__, SERVER_ID, ASSET_TYPE_ID);
	}
	else // success 
	{
		OTString strOutput(*pPurse); // For the output

		return strOutput.Get();
	}

	return "";	
}

// returns NULL, or a mint32_t
string OTAPI_Wrap::LoadMint(
	const string & SERVER_ID,
	const string & ASSET_TYPE_ID)
{
	if (SERVER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (ASSET_TYPE_ID.empty())		{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "ASSET_TYPE_ID"		); OT_ASSERT(false); }

	const OTIdentifier theServerID(SERVER_ID);
	const OTIdentifier theAssetID(ASSET_TYPE_ID);

	// There is an OT_ASSERT in here for memory failure,
	// but it still might return NULL if various verification fails.
	OTMint * pMint = OTAPI_Wrap::OTAPI()->LoadMint(theServerID, theAssetID); 

	// Make sure it gets cleaned up when this goes out of scope.
	OTCleanup<OTMint>	theMintAngel(pMint); // I pass the pointer, in case it's NULL.

	if (NULL == pMint)
		OTLog::sOutput(0, "OT_API_LoadMint: Failure calling OT_API::LoadMint.\nServer: %s\n Asset Type: %s\n", __FUNCTION__, SERVER_ID, ASSET_TYPE_ID);
	else // success 
	{
		OTString strOutput(*pMint); // For the output

		return strOutput.Get(); 
	}
	return "";
}
// returns NULL, or an asset contract.
string OTAPI_Wrap::LoadAssetContract(const string & ASSET_TYPE_ID)
{
	if (ASSET_TYPE_ID.empty())		{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "ASSET_TYPE_ID"		); OT_ASSERT(false); }

	const OTIdentifier theAssetID(ASSET_TYPE_ID);

	// There is an OT_ASSERT in here for memory failure,
	// but it still might return NULL if various verification fails.
	OTAssetContract * pContract = OTAPI_Wrap::OTAPI()->LoadAssetContract(theAssetID); 

	// Make sure it gets cleaned up when this goes out of scope.
	OTCleanup<OTAssetContract>	theAngel(pContract); // I pass the pointer, in case it's NULL.

	if (NULL == pContract)
	{
		OTLog::sOutput(0, "%s: Failure calling OT_API::LoadAssetContract.\n Asset Type: %s\n", __FUNCTION__, ASSET_TYPE_ID);
	}
	else // success 
	{
		OTString strOutput(*pContract); // For the output

		return strOutput.Get(); 
	}

	return "";			
}

// returns NULL, or a server contract.
string OTAPI_Wrap::LoadServerContract(const string & SERVER_ID)
{
	if (SERVER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }

	const OTIdentifier theServerID(SERVER_ID);

	// There is an OT_ASSERT in here for memory failure,
	// but it still might return NULL if various verification fails.
	OTServerContract * pContract = (OTAPI_Wrap::OTAPI()->LoadServerContract(theServerID));


	if (NULL == pContract)
	{
		OTLog::sOutput(0, "%s: Failure calling OT_API::LoadServerContract.\nServer ID: %s\n", __FUNCTION__, SERVER_ID);
	}
	else // success 
	{
		OTString strOutput(*pContract); // For the output

		return strOutput.Get(); 
	}

	return "";			
}




// TRUE if the mint32_t is still usable.
// FALSE if expired or other error.
//
bool OTAPI_Wrap::Mint_IsStillGood(
	const string & SERVER_ID,
	const string & ASSET_TYPE_ID
	)
{
	if (SERVER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (ASSET_TYPE_ID.empty())		{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "ASSET_TYPE_ID"		); OT_ASSERT(false); }

	const OTIdentifier theServerID(SERVER_ID), theAssetID(ASSET_TYPE_ID);
	// -----------------------------------------------------
	// There is an OT_ASSERT in here for memory failure,
	// but it still might return NULL if various verification fails.
	OTMint * pMint = OTAPI_Wrap::OTAPI()->LoadMint(theServerID, theAssetID); 

	// Make sure it gets cleaned up when this goes out of scope.
	OTCleanup<OTMint>	theMintAngel(pMint); // I pass the pointer, in case it's NULL.

	if (NULL == pMint)
		OTLog::sOutput(0, "%s: Failure calling OT_API::LoadMint.\nServer: %s\n Asset Type: %s\n", __FUNCTION__, SERVER_ID, ASSET_TYPE_ID);
	else // success 
	{
		bool bExpired = pMint->Expired();

		if (!bExpired)
			return true;
	}
	// -----------------------------------------------------
	return false;
}




// --------------------------------------------------------------
// IS BASKET CURRENCY ?
//
// Tells you whether or not a given asset type is actually a basket currency.
//
bool OTAPI_Wrap::IsBasketCurrency(const string & ASSET_TYPE_ID)
{
	if (ASSET_TYPE_ID.empty())		{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "ASSET_TYPE_ID"		); OT_ASSERT(false); }

	const OTIdentifier theAssetTypeID(ASSET_TYPE_ID);

	return OTAPI_Wrap::OTAPI()->IsBasketCurrency(theAssetTypeID);
}


// --------------------------------------------------------------------
// Get Basket Count(of backing asset types.)
//
// Returns the number of asset types that make up this basket.
//(Or zero.)
//
int32_t OTAPI_Wrap::Basket_GetMemberCount(const string & BASKET_ASSET_TYPE_ID)
{
	if (BASKET_ASSET_TYPE_ID.empty())	{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "BASKET_ASSET_TYPE_ID"	); OT_ASSERT(false); }

	const OTIdentifier theAssetTypeID(BASKET_ASSET_TYPE_ID);

	return OTAPI_Wrap::OTAPI()->GetBasketMemberCount(theAssetTypeID);
}

// --------------------------------------------------------------------
// Get Asset Type of a basket's member currency, by index.
//
//(Returns a string containing Asset Type ID, or NULL).
//
string OTAPI_Wrap::Basket_GetMemberType(
	const string & BASKET_ASSET_TYPE_ID,
	const int32_t & nIndex
	)
{
	if (BASKET_ASSET_TYPE_ID.empty()) { OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "BASKET_ASSET_TYPE_ID" ); OT_ASSERT(false); }

	if (0 > nIndex) { OTLog::sError("%s: nIndex is out of bounds (it's in the negative!)\n", __FUNCTION__); OT_ASSERT(false); }

	const OTIdentifier theAssetTypeID(BASKET_ASSET_TYPE_ID);

	OTIdentifier theOutputMemberType;

	bool bGotType = OTAPI_Wrap::OTAPI()->GetBasketMemberType(theAssetTypeID,
		nIndex,
		theOutputMemberType);
	if (false == bGotType)
		return "";


	OTString strOutput(theOutputMemberType);

	return strOutput.Get(); 
}

// ----------------------------------------------------
// GET BASKET MINIMUM TRANSFER AMOUNT
//
// Returns a long(as string) containing the minimum transfer
// amount for the entire basket.
//
// FOR EXAMPLE: 
// If the basket is defined as 10 Rands == 2 Silver, 5 Gold, 8 Euro,
// then the minimum transfer amount for the basket is 10. This function
// would return a string containing "10", in that example.
//
int64_t OTAPI_Wrap::Basket_GetMinimumTransferAmount(const string & BASKET_ASSET_TYPE_ID)
{
	if (BASKET_ASSET_TYPE_ID.empty()) { OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "BASKET_ASSET_TYPE_ID" ); OT_ASSERT(false); }

	const OTIdentifier theAssetTypeID(BASKET_ASSET_TYPE_ID);

	long lMinTransAmount = OTAPI_Wrap::OTAPI()->GetBasketMinimumTransferAmount(theAssetTypeID);

	if (0 == lMinTransAmount)
		return -1;
	else return lMinTransAmount;
}



// ----------------------------------------------------
// GET BASKET MEMBER's MINIMUM TRANSFER AMOUNT
//
// Returns a long(as string) containing the minimum transfer
// amount for one of the member currencies in the basket.
//
// FOR EXAMPLE: 
// If the basket is defined as 10 Rands == 2 Silver, 5 Gold, 8 Euro,
// then the minimum transfer amount for the member currency at index
// 0 is 2, the minimum transfer amount for the member currency at
// index 1 is 5, and the minimum transfer amount for the member 
// currency at index 2 is 8.
//
int64_t OTAPI_Wrap::Basket_GetMemberMinimumTransferAmount(
	const string & BASKET_ASSET_TYPE_ID,
	const int32_t & nIndex
	)
{
	if (BASKET_ASSET_TYPE_ID.empty()) { OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "BASKET_ASSET_TYPE_ID" ); OT_ASSERT(false); }

	if (0 > nIndex) { OTLog::sError("%s: nIndex is out of bounds (it's in the negative!)\n", __FUNCTION__); OT_ASSERT(false); }

	const OTIdentifier theAssetTypeID(BASKET_ASSET_TYPE_ID);

	long lMinTransAmount = OTAPI_Wrap::OTAPI()->GetBasketMemberMinimumTransferAmount(theAssetTypeID, nIndex);

	if (0 == lMinTransAmount)
	{
		OTLog::sError("%s: returned 0. Strange... what basket is this?\n", __FUNCTION__);
		return -1;
	}
	else return lMinTransAmount;
}













// --------------------------------------------------------------
// LOAD ACCOUNT / INBOX / OUTBOX --(from local storage)
//
// Loads an acct, or inbox or outbox, based on account ID,(from local storage)
// and returns it as string(or returns NULL if it couldn't load it.)
//
// Returns NULL, or an account.
string OTAPI_Wrap::LoadAssetAccount(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & ACCOUNT_ID
	)
{
	if (SERVER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }
	if (ACCOUNT_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCOUNT_ID"			); OT_ASSERT(false); }

	const OTIdentifier theServerID(SERVER_ID);
	const OTIdentifier theUserID(USER_ID);
	const OTIdentifier theAccountID(ACCOUNT_ID);

	// There is an OT_ASSERT in here for memory failure,
	// but it still might return NULL if various verification fails.
	OTAccount * pAccount = OTAPI_Wrap::OTAPI()->LoadAssetAccount(theServerID, theUserID, theAccountID); 

	// Make sure it gets cleaned up when this goes out of scope.
	OTCleanup<OTAccount>	theAngel(pAccount); // I pass the pointer, in case it's NULL.

	if (NULL == pAccount)
	{
		OTLog::sOutput(0, "%s: Failure calling OT_API::LoadAssetAccount.\nAccount ID: %s\n", __FUNCTION__, ACCOUNT_ID);
	}
	else // success 
	{
		OTString strOutput(*pAccount); // For the output

		return strOutput.Get(); 
	}

	return "";				
}

// Returns NULL, or an inbox.
string OTAPI_Wrap::LoadInbox(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & ACCOUNT_ID
	)
{
	if (SERVER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }
	if (ACCOUNT_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCOUNT_ID"			); OT_ASSERT(false); }


	const OTIdentifier theServerID(SERVER_ID);
	const OTIdentifier theUserID(USER_ID);
	const OTIdentifier theAccountID(ACCOUNT_ID);

	// There is an OT_ASSERT in here for memory failure,
	// but it still might return NULL if various verification fails.
	OTLedger * pLedger = OTAPI_Wrap::OTAPI()->LoadInbox(theServerID, theUserID, theAccountID); 

	// Make sure it gets cleaned up when this goes out of scope.
	OTCleanup<OTLedger>	theAngel(pLedger); // I pass the pointer, in case it's NULL.

	if (NULL == pLedger)
	{
		OTLog::sOutput(0, "%s: Failure calling OT_API::LoadInbox.\nAccount ID: %s\n", __FUNCTION__, ACCOUNT_ID);
	}
	else // success 
	{
		OTString strOutput(*pLedger); // For the output

		return strOutput.Get(); 
	}

	return "";
}

// returns NULL, or an outbox.
string OTAPI_Wrap::LoadOutbox(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & ACCOUNT_ID
	)
{
	if (SERVER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }
	if (ACCOUNT_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCOUNT_ID"			); OT_ASSERT(false); }

	const OTIdentifier theServerID(SERVER_ID);
	const OTIdentifier theUserID(USER_ID);
	const OTIdentifier theAccountID(ACCOUNT_ID);

	// There is an OT_ASSERT in here for memory failure,
	// but it still might return NULL if various verification fails.
	OTLedger * pLedger = OTAPI_Wrap::OTAPI()->LoadOutbox(theServerID, theUserID, theAccountID); 

	// Make sure it gets cleaned up when this goes out of scope.
	OTCleanup<OTLedger>	theAngel(pLedger); // I pass the pointer, in case it's NULL.

	if (NULL == pLedger)
	{
		OTLog::sOutput(0, "%s: Failure calling OT_API::LoadOutbox().\nAccount ID: %s\n", __FUNCTION__, ACCOUNT_ID);
	}
	else // success 
	{
		OTString strOutput(*pLedger); // For the output

		return strOutput.Get(); 
	}

	return "";				
}

// These versions don't verify the ledger, they just load it up.
//
// Returns NULL, or an inbox.
string OTAPI_Wrap::LoadInboxNoVerify(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & ACCOUNT_ID
	)
{
	if (SERVER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }
	if (ACCOUNT_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCOUNT_ID"			); OT_ASSERT(false); }

	const OTIdentifier theServerID(SERVER_ID);
	const OTIdentifier theUserID(USER_ID);
	const OTIdentifier theAccountID(ACCOUNT_ID);

	// There is an OT_ASSERT in here for memory failure,
	// but it still might return NULL if various verification fails.
	OTLedger * pLedger = OTAPI_Wrap::OTAPI()->LoadInboxNoVerify(theServerID, theUserID, theAccountID); 

	// Make sure it gets cleaned up when this goes out of scope.
	OTCleanup<OTLedger>	theAngel(pLedger); // I pass the pointer, in case it's NULL.

	if (NULL == pLedger)
	{
		OTLog::sOutput(0, "%s: Failure calling OT_API::LoadInboxNoVerify.\nAccount ID: %s\n", __FUNCTION__, ACCOUNT_ID);
	}
	else // success 
	{
		OTString strOutput(*pLedger); // For the output

		return strOutput.Get(); 
	}

	return "";				
}

// returns NULL, or an outbox.
string OTAPI_Wrap::LoadOutboxNoVerify(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & ACCOUNT_ID
	)
{
	if (SERVER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }
	if (ACCOUNT_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCOUNT_ID"			); OT_ASSERT(false); }

	const OTIdentifier theServerID(SERVER_ID);
	const OTIdentifier theUserID(USER_ID);
	const OTIdentifier theAccountID(ACCOUNT_ID);

	// There is an OT_ASSERT in here for memory failure,
	// but it still might return NULL if various verification fails.
	OTLedger * pLedger = OTAPI_Wrap::OTAPI()->LoadOutboxNoVerify(theServerID, theUserID, theAccountID); 

	// Make sure it gets cleaned up when this goes out of scope.
	OTCleanup<OTLedger>	theAngel(pLedger); // I pass the pointer, in case it's NULL.

	if (NULL == pLedger)
	{
		OTLog::sOutput(0, "%s: Failure calling OT_API::LoadOutboxNoVerify.\nAccount ID: %s\n", __FUNCTION__, ACCOUNT_ID);
	}
	else // success 
	{
		OTString strOutput(*pLedger); // For the output

		return strOutput.Get(); 
	}

	return "";				
}
// --------------------------------------------------------------


// from local storage.
// Returns NULL, or a payment inbox.
string OTAPI_Wrap::LoadPaymentInbox(
	const string & SERVER_ID,
	const string & USER_ID
	)
{
	if (SERVER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }

	const OTIdentifier theServerID(SERVER_ID);
	const OTIdentifier theUserID(USER_ID);

	// There is an OT_ASSERT in here for memory failure,
	// but it still might return NULL if various verification fails.
	OTLedger * pLedger = OTAPI_Wrap::OTAPI()->LoadPaymentInbox(theServerID, theUserID); 

	// Make sure it gets cleaned up when this goes out of scope.
	OTCleanup<OTLedger>	theAngel(pLedger); // I pass the pointer, in case it's NULL.

	if (NULL == pLedger)
	{
		OTLog::sOutput(0, "%s: Failure calling OT_API::LoadPaymentInbox.\n User ID: %s\n", __FUNCTION__, USER_ID);
	}
	else // success 
	{
		OTString strOutput(*pLedger); // For the output

		return strOutput.Get(); 
	}

	return "";				
}

// Returns NULL, or a payment inbox.
string OTAPI_Wrap::LoadPaymentInboxNoVerify(
	const string & SERVER_ID,
	const string & USER_ID
	)
{
	if (SERVER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }

	const OTIdentifier theServerID(SERVER_ID);
	const OTIdentifier theUserID(USER_ID);

	// There is an OT_ASSERT in here for memory failure,
	// but it still might return NULL if various verification fails.
	OTLedger * pLedger = OTAPI_Wrap::OTAPI()->LoadPaymentInboxNoVerify(theServerID, theUserID); 

	// Make sure it gets cleaned up when this goes out of scope.
	OTCleanup<OTLedger>	theAngel(pLedger); // I pass the pointer, in case it's NULL.

	if (NULL == pLedger)
	{
		OTLog::sOutput(0, "%s: Failure calling OT_API::LoadPaymentInboxNoVerify.\nUser ID: %s\n", __FUNCTION__, USER_ID);
	}
	else // success 
	{
		OTString strOutput(*pLedger); // For the output

		return strOutput.Get(); 
	}

	return "";				
}


// NOTE: Sometimes the user ID is also passed in the "account ID" field, depending
// on what kind of record box it is.
// from local storage.
// Returns NULL, or a RecordBox.
string OTAPI_Wrap::LoadRecordBox(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & ACCOUNT_ID
	)
{
	if (SERVER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }
	if (ACCOUNT_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCOUNT_ID"			); OT_ASSERT(false); }

	const OTIdentifier theServerID(SERVER_ID);
	const OTIdentifier theUserID(USER_ID);
	const OTIdentifier theAccountID(ACCOUNT_ID);

	// There is an OT_ASSERT in here for memory failure,
	// but it still might return NULL if various verification fails.
	OTLedger * pLedger = OTAPI_Wrap::OTAPI()->LoadRecordBox(theServerID, theUserID, theAccountID); 

	// Make sure it gets cleaned up when this goes out of scope.
	OTCleanup<OTLedger>	theAngel(pLedger); // I pass the pointer, in case it's NULL.

	if (NULL == pLedger)
	{
		OTLog::sOutput(0, "%s: Failure calling OT_API::LoadRecordBox.\n",__FUNCTION__);
	}
	else // success 
	{
		OTString strOutput(*pLedger); // For the output

		return strOutput.Get(); 
	}
	return "";				
}

// Returns NULL, or a RecordBox.
string OTAPI_Wrap::LoadRecordBoxNoVerify(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & ACCOUNT_ID
	)
{
	if (SERVER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }
	if (ACCOUNT_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCOUNT_ID"			); OT_ASSERT(false); }

	const OTIdentifier theServerID(SERVER_ID);
	const OTIdentifier theUserID(USER_ID);
	const OTIdentifier theAccountID(ACCOUNT_ID);

	// There is an OT_ASSERT in here for memory failure,
	// but it still might return NULL if various verification fails.
	OTLedger * pLedger = OTAPI_Wrap::OTAPI()->LoadRecordBoxNoVerify(theServerID, theUserID, theAccountID); 

	// Make sure it gets cleaned up when this goes out of scope.
	OTCleanup<OTLedger>	theAngel(pLedger); // I pass the pointer, in case it's NULL.

	if (NULL == pLedger)
	{
		OTLog::sOutput(0, "%s: Failure calling OT_API::LoadRecordBoxNoVerify.\n", __FUNCTION__);
	}
	else // success 
	{
		OTString strOutput(*pLedger); // For the output

		return strOutput.Get(); 
	}
	return "";				
}



// --------------------------------------------------------------
// Find out how many pending transactions(and receipts) are in this inbox.
// Returns number of transactions within.
int32_t OTAPI_Wrap::Ledger_GetCount(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & ACCOUNT_ID,
	const string & THE_LEDGER
	)
{
	if (SERVER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }
	if (ACCOUNT_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCOUNT_ID"			); OT_ASSERT(false); }
	if (THE_LEDGER.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_LEDGER"			); OT_ASSERT(false); }

	const OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theAccountID(ACCOUNT_ID);

	OTString strLedger(THE_LEDGER);
	// -----------------------------------------------------
	OTLedger theLedger(theUserID, theAccountID, theServerID);

	if (false == theLedger.LoadLedgerFromString(strLedger))
	{
		OTString strAcctID(theAccountID);
		OTLog::sError("%s: Error loading ledger from string. Acct ID: %s\n", __FUNCTION__, strAcctID.Get());
		return -1;
	}

	return theLedger.GetTransactionCount();
}


// -----------------------------------------------------------------------
// Creates a new 'response' ledger, set up with the right Server ID, etc, so you can
// add the 'response' transactions to it, one by one.(Pass in the original ledger 
// that you are responding to, as it uses the data from it to set up the response.)
//
string OTAPI_Wrap::Ledger_CreateResponse(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & ACCOUNT_ID,
	const string & ORIGINAL_LEDGER
	)
{
	if (SERVER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }
	if (ACCOUNT_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCOUNT_ID"			); OT_ASSERT(false); }
	if (ORIGINAL_LEDGER.empty())	{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "ORIGINAL_LEDGER"	); OT_ASSERT(false); }

	const OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theAccountID(ACCOUNT_ID);

	// -----------------------------------------------------
	OTPseudonym *  pNym(OTAPI_Wrap::OTAPI()->GetOrLoadPrivateNym(theUserID, __FUNCTION__)); // These copiously log, and ASSERT.
	if (NULL == pNym) return "";
	// -----------------------------------------------------
	// Let's load up the ledger (an inbox) that was passed in...
	OTString strOriginalLedger(ORIGINAL_LEDGER);
	OTLedger theOriginalLedger(theUserID, theAccountID, theServerID);

	if (false == theOriginalLedger.LoadLedgerFromString(strOriginalLedger))
	{
		OTString strAcctID(theAccountID);
		OTLog::sError("%s: Error loading ledger from string. Acct ID: %s\n", __FUNCTION__, strAcctID.Get());
		return "";
	}

	if (false == theOriginalLedger.VerifyAccount(*pNym))
	{
		OTString strAcctID(theAccountID);
		OTLog::sError("%s: Error verifying original ledger. Acct ID: %s\n", __FUNCTION__, strAcctID.Get());
		return "";
	}
	// -----------------------------------------------------
	// By this point, the ledger is loaded properly from the string,
	// Let's create the response to it.
	OTLedger * pResponseLedger = OTLedger::GenerateLedger(theUserID, theAccountID,
		theServerID, OTLedger::message);// bCreateFile=false
	OTCleanup<OTLedger> theResponseAngel(pResponseLedger); // Angel will handle cleanup.

	if (NULL == pResponseLedger)
	{
		OTString strAcctID(theAccountID);
		OTLog::sError("%s: Error generating response ledger. Acct ID: %s\n", __FUNCTION__, strAcctID.Get());
		return "";
	}
	// -----------------------------------------------------
	pResponseLedger->SignContract(*pNym);
	pResponseLedger->SaveContract();

	OTString strOutput(*pResponseLedger); // For the output

	return strOutput.Get(); 
}


// -------------------------------------------------------------------------
// Lookup a transaction or its ID(from within a ledger) based on index or
// transaction number.
//
// returns transaction by index.
string OTAPI_Wrap::Ledger_GetTransactionByIndex(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & ACCOUNT_ID,
	const string & THE_LEDGER,
	const int32_t & nIndex
	)
{
	if (SERVER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }
	if (ACCOUNT_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCOUNT_ID"			); OT_ASSERT(false); }
	if (THE_LEDGER.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_LEDGER"			); OT_ASSERT(false); }

	if (0 > nIndex) { OTLog::sError("%s: nIndex is out of bounds (it's in the negative!)\n", __FUNCTION__); OT_ASSERT(false); }

	const OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theAccountID(ACCOUNT_ID);

	OTString strLedger(THE_LEDGER);
	// -----------------------------------------------------
	OTLedger theLedger(theUserID, theAccountID, theServerID);
	//	set<long> setUnloaded;

	if (	!theLedger.LoadLedgerFromString(strLedger)
		//		||	!theLedger.LoadBoxReceipts(&setUnloaded)	// This is done below, for the individual transaction, for better optimization.
		)
	{
		OTString strAcctID(theAccountID);
		OTLog::sError("%s: Error loading ledger from string, or loading box receipts subsequently. Acct ID: %s\n", __FUNCTION__, strAcctID.Get());
		return "";
	}

	// At this point, I know theLedger loaded successfully.

	if (nIndex >= theLedger.GetTransactionCount())
	{
		OTLog::vError("%s: out of bounds: %d\n", __FUNCTION__, nIndex);
		return ""; // out of bounds. I'm saving from an OT_ASSERT_MSG() happening here. (Maybe I shouldn't.)
	}

	OTTransaction * pTransaction = theLedger.GetTransactionByIndex(nIndex);
	//	OTCleanup<OTTransaction> theAngel(pTransaction); // THE LEDGER CLEANS THIS ALREADY.

	if (NULL == pTransaction)
	{
		OTLog::vError("%s: Failure: good index but uncovered NULL pointer: %d\n", __FUNCTION__, nIndex);
		return ""; // Weird.
	}

	const long lTransactionNum = pTransaction->GetTransactionNum();
	// At this point, I actually have the transaction pointer, so let's return it in string form...

	// Update: for transactions in ABBREVIATED form, the string is empty, since it has never actually
	// been signed (in fact the whole point with abbreviated transactions in a ledger is that they 
	// take up very little room, and have no signature of their own, but exist merely as XML tags on
	// their parent ledger.)
	//
	// THEREFORE I must check to see if this transaction is abbreviated and if so, sign it in order to
	// force the UpdateContents() call, so the programmatic user of this API will be able to load it up.
	//
	if (pTransaction->IsAbbreviated())
	{
		theLedger.LoadBoxReceipt(lTransactionNum); // I don't check return val here because I still want it to send the abbreviated form, if this fails.
		pTransaction = theLedger.GetTransaction(lTransactionNum);
		// -------------------------
		if (NULL == pTransaction)
		{
			OTLog::vError("%s: good index but uncovered NULL pointer after trying to load full version of receipt (from abbreviated): %d\n", __FUNCTION__, nIndex);
			return ""; // Weird.
		}		
		// I was doing this when it was abbreviated. But now (above) I just 
		// load the box receipt itself. (This code is a hack that creates a
		// serialized abbreviated version.)
		//		OTPseudonym *  pNym = OTAPI_Wrap::OTAPI()->GetNym(theUserID, "OT_API_Ledger_GetTransactionByIndex");
		//		if (NULL == pNym) return "";
		//		// -------------------------	
		//		pTransaction->ReleaseSignatures();
		//		pTransaction->SignContract(*pNym);
		//		pTransaction->SaveContract();
	}
	// ------------------------------------------------

	const OTString strOutput(*pTransaction); // For the output
	return strOutput.Get();
}

// returns transaction by ID.
string OTAPI_Wrap::Ledger_GetTransactionByID(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & ACCOUNT_ID,
	const string & THE_LEDGER,
	const string & TRANSACTION_NUMBER
	)
{
	if (SERVER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }
	if (ACCOUNT_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCOUNT_ID"			); OT_ASSERT(false); }
	if (THE_LEDGER.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_LEDGER"			); OT_ASSERT(false); }
	if (TRANSACTION_NUMBER.empty())	{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "TRANSACTION_NUMBER"	); OT_ASSERT(false); }

	const int64_t lTransactionNumber = StringToLong(TRANSACTION_NUMBER);

	if (0 > lTransactionNumber) { OTLog::sError("%s: Bad transaction number passed in (negative value)\n", __FUNCTION__); OT_ASSERT(false); }

	const OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theAccountID(ACCOUNT_ID);

	OTString strLedger(THE_LEDGER);

	// -----------------------------------------------------

	OTLedger theLedger(theUserID, theAccountID, theServerID);

	if (false == theLedger.LoadLedgerFromString(strLedger))
	{
		OTString strAcctID(theAccountID);
		OTLog::sError("%s: Error loading ledger from string. Acct ID: %s\n", __FUNCTION__, strAcctID.Get());
		return "";
	}
	// At this point, I know theLedger loaded successfully.
	// -----------------------------------------------------

	OTTransaction * pTransaction = theLedger.GetTransaction(static_cast<long>(lTransactionNumber));
	// No need to cleanup this transaction, the ledger owns it already.

	if (NULL == pTransaction)
	{
		OTLog::vOutput(0, "%s: No transaction found in ledger with that number: %ld.\n", __FUNCTION__, lTransactionNumber);
		return ""; // Maybe he was just looking; this isn't necessarily an error.
	}
	// -----------------------------------------------------

	// At this point, I actually have the transaction pointer, so let's return it in string form...
	//
	const long lTransactionNum = pTransaction->GetTransactionNum();
	OT_ASSERT(lTransactionNum == lTransactionNumber);

	// Update: for transactions in ABBREVIATED form, the string is empty, since it has never actually
	// been signed (in fact the whole point with abbreviated transactions in a ledger is that they 
	// take up very little room, and have no signature of their own, but exist merely as XML tags on
	// their parent ledger.)
	//
	// THEREFORE I must check to see if this transaction is abbreviated and if so, sign it in order to
	// force the UpdateContents() call, so the programmatic user of this API will be able to load it up.
	//
	if (pTransaction->IsAbbreviated())
	{
		// First we see if we are able to load the full version of this box receipt.
		// (Perhaps it has already been downloaded sometime in the past, and simply
		// needs to be loaded up. Worth a shot.)
		//
		const bool bLoadedBoxReceipt = theLedger.LoadBoxReceipt(lTransactionNum); // I still want it to send the abbreviated form, if this fails.

		// Grab this pointer again, since the object was re-instantiated
		// in the case of a successful LoadBoxReceipt.
		//
		if (bLoadedBoxReceipt)
			pTransaction = theLedger.GetTransaction(lTransactionNum);

		// (else if false == bLoadedBoxReceipt, then pTransaction ALREADY points
		// to the abbreviated version.)
		// -------------------------
		if (NULL == pTransaction)
		{
			OTLog::sError("%s: good ID, but uncovered NULL pointer after trying to load full version "
				"of receipt (from abbreviated.) Probably just need to download this one...\n",
				__FUNCTION__);
			return ""; // Weird.
		}
		// If it's STILL abbreviated after the above efforts, then there's nothing else I can do
		// except return the abbreviated version. The caller may still need the info available on
		// the abbreviated version. (And the caller may yet download the full version...)
		//
		else if (pTransaction->IsAbbreviated())
		{
			OTPseudonym *  pNym(OTAPI_Wrap::OTAPI()->GetNym(theUserID, __FUNCTION__));
			if (NULL == pNym) return ""; // Weird.
			// -------------------------
			pTransaction->ReleaseSignatures();
			pTransaction->SignContract(*pNym);
			pTransaction->SaveContract();
		}
	}
	// ------------------------------------------------
	const OTString strOutput(*pTransaction); // For the output
	return strOutput.Get(); 	
}

// returns transaction number by index.
int64_t OTAPI_Wrap::Ledger_GetTransactionNumberByIndex(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & ACCOUNT_ID,
	const string & THE_LEDGER,
	const int32_t & nIndex
	)
{
	if (SERVER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }
	if (ACCOUNT_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCOUNT_ID"			); OT_ASSERT(false); }
	if (THE_LEDGER.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_LEDGER"			); OT_ASSERT(false); }

	if (0 > nIndex) { OTLog::sError("%s: nIndex is out of bounds (it's in the negative!)\n", __FUNCTION__); OT_ASSERT(false); }

	const OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theAccountID(ACCOUNT_ID);

	OTString strLedger(THE_LEDGER);
	// -----------------------------------------------------
	int64_t lOutput = -1; // For the output

	long lTransactionNumber = 0;
	OTTransaction * pTransaction = NULL;

	OTLedger theLedger(theUserID, theAccountID, theServerID);

	if (false == theLedger.LoadLedgerFromString(strLedger))
	{
		OTString strAcctID(theAccountID);
		OTLog::sError("%s: Error loading ledger from string. Acct ID: %s\n", __FUNCTION__, strAcctID.Get());
	}

	// At this point, I know theLedger loaded successfully.

	else if (nIndex >= theLedger.GetTransactionCount())
	{
		OTLog::vError("%s: out of bounds: %d\n", __FUNCTION__, nIndex);
		// out of bounds. I'm saving from an OT_ASSERT_MSG() happening here. (Maybe I shouldn't.)
	}

	else if (NULL == (pTransaction = theLedger.GetTransactionByIndex(nIndex)))
	{
		OTLog::vError("%s: good index but uncovered NULL pointer: %d\n", __FUNCTION__, nIndex);
	} // NO NEED TO CLEANUP the transaction, since it is already "owned" by theLedger.

	// At this point, I actually have the transaction pointer, so let's get the ID...

	else if (0 >= (lTransactionNumber = pTransaction->GetTransactionNum()))
	{
		OTLog::vError("%s: negative or zero transaction num: %ld\n", __FUNCTION__, lTransactionNumber);
		// Bad value.
	}
	else // success
	{
		lOutput = lTransactionNumber;
	}

	return lTransactionNumber;
}

// --------------------------------------------------------------
// Add a transaction to a ledger.
//
string OTAPI_Wrap::Ledger_AddTransaction(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & ACCOUNT_ID,
	const string & THE_LEDGER,
	const string & THE_TRANSACTION
	)
{
	if (SERVER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }
	if (ACCOUNT_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCOUNT_ID"			); OT_ASSERT(false); }
	if (THE_LEDGER.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_LEDGER"			); OT_ASSERT(false); }
	if (THE_TRANSACTION.empty())	{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_TRANSACTION"	); OT_ASSERT(false); }

	const OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theAccountID(ACCOUNT_ID);

	OTString strLedger(THE_LEDGER);
	OTString strTransaction(THE_TRANSACTION);

	// -----------------------------------------------------
	OTPseudonym *  pNym(OTAPI_Wrap::OTAPI()->GetOrLoadPrivateNym(theUserID, __FUNCTION__)); // These copiously log, and ASSERT.
	if (NULL == pNym) return "";
	// -----------------------------------------------------

	OTLedger theLedger(theUserID, theAccountID, theServerID);

	if (false == theLedger.LoadLedgerFromString(strLedger))
	{
		OTString strAcctID(theAccountID);
		OTLog::sError("%s: Error loading ledger from string. Acct ID: %s\n", __FUNCTION__, strAcctID.Get());
		return "";
	}
	else if (false == theLedger.VerifyAccount(*pNym))
	{
		OTString strAcctID(theAccountID);
		OTLog::sError("%s: Error verifying ledger in OT_API_Ledger_AddTransaction. Acct ID: %s\n", __FUNCTION__, strAcctID.Get());
		return "";
	}

	// At this point, I know theLedger loaded and verified successfully.
	// -----------------------------------------------------

	OTTransaction * pTransaction = new OTTransaction(theUserID, theAccountID, theServerID);
	if (NULL == pTransaction)	{ OTLog::sError("%s: Error allocating memory in the OTAPI_Wrap: %s !\n", __FUNCTION__, "pTransaction"	); OT_ASSERT(false); }

	if (false == pTransaction->LoadContractFromString(strTransaction))
	{
		OTString strAcctID(theAccountID);
		OTLog::sError("%s: Error loading transaction from string. Acct ID: %s\n", __FUNCTION__, strAcctID.Get());
		delete pTransaction; pTransaction = NULL;
		return "";
	}
	else if (false == pTransaction->VerifyAccount(*pNym))
	{
		OTString strAcctID(theAccountID);
		OTLog::sError("%s: Error verifying transaction. Acct ID: %s\n", __FUNCTION__, strAcctID.Get());
		delete pTransaction; pTransaction = NULL;
		return "";
	}
	// -----------------------------------------------------
	// At this point, I know pTransaction loaded and verified successfully.
	// So let's add it to the ledger, save, and return updated ledger in string form.

	theLedger.AddTransaction(*pTransaction); // Ledger now "owns" it and will handle cleanup.

	theLedger.ReleaseSignatures();
	theLedger.SignContract(*pNym);
	theLedger.SaveContract();

	OTString strOutput(theLedger); // For the output

	return strOutput.Get();
}


// --------------------------------------------------------------
// Create a 'response' transaction, that will be used to indicate my
// acceptance or rejection of another transaction. Usually an entire
// ledger full of these is sent to the server as I process the various
// transactions in my inbox.
//
// 1 or 0(OT_TRUE or OT_FALSE.)
string OTAPI_Wrap::Transaction_CreateResponse(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & ACCOUNT_ID,
	const string & RESPONSE_LEDGER, // To be sent to the server...
	const string & ORIGINAL_TRANSACTION, // Responding to...?
	bool BOOL_DO_I_ACCEPT
	)
{
	if (SERVER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }
	if (ACCOUNT_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCOUNT_ID"			); OT_ASSERT(false); }
	if (RESPONSE_LEDGER.empty())		{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "RESPONSE_LEDGER"		); OT_ASSERT(false); }
	if (ORIGINAL_TRANSACTION.empty())	{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "ORIGINAL_TRANSACTION"	); OT_ASSERT(false); }


	const OTIdentifier	theServerID(SERVER_ID), 
		theUserID(USER_ID), theAcctID(ACCOUNT_ID);

	OTString strLedger(RESPONSE_LEDGER);
	OTString strTransaction(ORIGINAL_TRANSACTION);

	// -----------------------------------------------------
	OTServerContract * pServer(OTAPI_Wrap::OTAPI()->GetServer(theServerID, __FUNCTION__));
	if (NULL == pServer) return "";
	// By this point, pServer is a good pointer.  (No need to cleanup.)
	// --------------------------------------------------------------------
	const OTPseudonym * pServerNym = pServer->GetContractPublicNym();

	if (NULL == pServerNym)
	{
		OTLog::sOutput(0, "%s: No Contract Nym found in that Server Contract.\n", __FUNCTION__);
		return "";
	}
	// By this point, pServerNym is a good pointer.  (No need to cleanup.)
	// -----------------------------------------------------
	OTPseudonym *  pNym(OTAPI_Wrap::OTAPI()->GetOrLoadPrivateNym(theUserID, __FUNCTION__)); // This logs, ASSERTs, etc.
	if (NULL == pNym) return "";
	// By this point, pNym is a good pointer, and is on the wallet. (No need to cleanup.)
	// -----------------------------------------------------	
	OTLedger theLedger(theUserID, theAcctID, theServerID);

	if (false == theLedger.LoadLedgerFromString(strLedger))
	{
		OTString strAcctID(theAcctID);
		OTLog::sError("%s: Error loading ledger from string. Acct ID: %s\n", __FUNCTION__, strAcctID.Get());
		return "";
	}
	else if (false == theLedger.VerifyAccount(*pNym))
	{
		OTString strAcctID(theAcctID);
		OTLog::sError("%s: Error verifying ledger. Acct ID: %s\n", __FUNCTION__, strAcctID.Get());
		return "";
	}

	// At this point, I know theLedger loaded and verified successfully.
	// (This is the 'response' ledger that the user previously generated,
	// and now he is loading it up with responses that this function will 
	// generate on his behalf.)
	// -----------------------------------------------------

	OTTransaction theTransaction(theUserID, theAcctID, theServerID);

	if (false == theTransaction.LoadContractFromString(strTransaction))
	{
		OTString strAcctID(theAcctID);
		OTLog::sError("%s: Error loading transaction from string. Acct ID: %s\n", __FUNCTION__, strAcctID.Get());
		return "";
	}
	// --------------------------------------
	OTTransaction * pTransaction = NULL;
	OTCleanup<OTTransaction> theTransAngel;

	if (theTransaction.IsAbbreviated())
	{
		pTransaction = OTTransaction::LoadBoxReceipt(theTransaction, static_cast<long>(OTLedger::inbox));

		if (NULL == pTransaction)
		{
			OTString strAcctID(theAcctID);
			OTLog::sError("%s: Error loading full transaction from abbreviated version of inbox receipt. Acct ID: %s\n", __FUNCTION__, strAcctID.Get());
			return "";
		}
		theTransAngel.SetCleanupTargetPointer(pTransaction);
	}
	else
		pTransaction = &theTransaction;
	// --------------------------------------
	// BELOW THIS POINT, only use pTransaction, not theTransaction.

	// This transaction is presumably from the server, since we are in this
	// function in order to generate a response back to the server. So therefore
	// I want to verify that the server has actually signed the thing, before
	// I go off responding to it like a damned fool.
	//
	if (false == pTransaction->VerifyAccount(*pServerNym))
	{
		OTString strAcctID(theAcctID);
		OTLog::sError("%s:Error verifying transaction. Acct ID: %s\n", __FUNCTION__, strAcctID.Get());
		return "";
	}

	// -----------------------------------------------------

	if (
		(OTTransaction::pending			!= pTransaction->GetType()) 
		&&	(OTTransaction::chequeReceipt	!= pTransaction->GetType())
		&&	(OTTransaction::transferReceipt	!= pTransaction->GetType())
		&&	(OTTransaction::marketReceipt	!= pTransaction->GetType())
		&&	(OTTransaction::paymentReceipt	!= pTransaction->GetType())
		&&	(OTTransaction::finalReceipt	!= pTransaction->GetType())
		&&	(OTTransaction::basketReceipt	!= pTransaction->GetType())
		)
	{
		OTLog::sError("%s: wrong transaction type: %s.\n", __FUNCTION__, pTransaction->GetTypeString());
		return "";		
	}

	// -----------------------------------------------------

	// At this point, I know pTransaction loaded and verified successfully.
	// So let's generate a response item based on it, and add it to a processInbox
	// transaction to be added to that ledger (if one's not already there...)

	// First, check to see if there is a processInbox transaction already on
	// the ledger...
	OTTransaction * pResponse = theLedger.GetTransaction(OTTransaction::processInbox);

	// If it's not already there, create it and add it.
	if (NULL == pResponse)
	{
		OTString strServerID(theServerID);
		long lTransactionNumber=0;
		bool bGotTransNum = pNym->GetNextTransactionNum(*pNym, strServerID, lTransactionNumber);

		if (false == bGotTransNum)
		{
			OTString strNymID(theUserID);
			OTLog::sOutput(0, "%s: User is all out of transaction numbers:\n%s\n", __FUNCTION__, strNymID.Get());
			return "";
		}

		pResponse = OTTransaction::GenerateTransaction(theUserID, theAcctID, theServerID, 
			OTTransaction::processInbox, 
			lTransactionNumber);
		if (NULL == pResponse)
		{
			OTString strAcctID(theAcctID);
			OTLog::sError("%s: Error generating processInbox transaction for AcctID: %s\n", __FUNCTION__, strAcctID.Get());

			pNym->AddTransactionNum(*pNym, strServerID, lTransactionNumber, true); // bSave=true.  Have to add this back since we failed to use it.

			return "";
		}

		theLedger.AddTransaction(*pResponse); // Ledger now "owns" it and will handle cleanup.
	}

	// At this point I know pResponse is a processInbox transaction, ready to go,
	// and that theLedger will handle any cleanup issues related to it.

	// -----------------------------------------------------

	// Next let's create a new item that responds to pTransaction, and add that 
	// item to pResponse. Then we'll return the updated ledger.

	OTItem::itemType theAcceptItemType = OTItem::error_state;
	OTItem::itemType theRejectItemType = OTItem::error_state;

	switch (pTransaction->GetType()) 
	{
	case OTTransaction::pending:
		theAcceptItemType = OTItem::acceptPending;
		theRejectItemType = OTItem::rejectPending;
		break;


	case OTTransaction::marketReceipt:
	case OTTransaction::paymentReceipt:
		theAcceptItemType = OTItem::acceptCronReceipt;
		theRejectItemType = OTItem::disputeCronReceipt;
		break;

	case OTTransaction::chequeReceipt:
	case OTTransaction::transferReceipt:
		theAcceptItemType = OTItem::acceptItemReceipt;
		theRejectItemType = OTItem::disputeItemReceipt;
		break;

	case OTTransaction::finalReceipt:
		theAcceptItemType = OTItem::acceptFinalReceipt;
		theRejectItemType = OTItem::disputeFinalReceipt;
		break;

	case OTTransaction::basketReceipt:
		theAcceptItemType = OTItem::acceptBasketReceipt;
		theRejectItemType = OTItem::disputeBasketReceipt;
		break;

	default:
		theAcceptItemType = OTItem::error_state;
		theRejectItemType = OTItem::error_state;
		OTLog::sError("%s: Unexpected transaction type in: %s\n", __FUNCTION__, pTransaction->GetTypeString());
		return "";
	}

	long lReferenceTransactionNum = 0;

	switch (pTransaction->GetType()) 
	{
	case OTTransaction::marketReceipt:
	case OTTransaction::paymentReceipt:
	case OTTransaction::finalReceipt:
	case OTTransaction::basketReceipt:
		lReferenceTransactionNum = pTransaction->GetTransactionNum();			
		break;

	case OTTransaction::pending:
	case OTTransaction::chequeReceipt:
	case OTTransaction::transferReceipt:
		{
			// -----------------------------------------------------
			// Here's some code in case you need to load up the item.
			OTString strReference;
			pTransaction->GetReferenceString(strReference);

			if (!strReference.Exists())
			{
				OTLog::sError("%s: No reference string found on transaction.\n", __FUNCTION__);
				return "";				
			}
			// -----------------------------------------------------
			OTItem * pOriginalItem = OTItem::CreateItemFromString(strReference, theServerID, pTransaction->GetReferenceToNum());
			OTCleanup<OTItem> theAngel(pOriginalItem);

			if (NULL == pOriginalItem)
			{
				OTLog::sError("%s: Failed loading transaction item from string.\n", __FUNCTION__);
				return "";				
			}
			// pItem will be automatically cleaned up when it goes out of scope.
			// -----------------------------------------------------

			if (
				(OTItem::request != pOriginalItem->GetStatus()) 
				||
				(
				(OTItem::acceptPending	!= pOriginalItem->GetType())  && // I'm accepting a transfer receipt.
				(OTItem::transfer		!= pOriginalItem->GetType())  && // I'm accepting a transfer that was sent to me.
				(OTItem::depositCheque	!= pOriginalItem->GetType())	 // I'm accepting a notice that someone cashed a cheque I wrote.
				)	
				)
			{ 
				OTLog::sError("%s: Wrong item type or status attached as reference on transaction.\n", __FUNCTION__);
				return "";				
			}

			lReferenceTransactionNum = pOriginalItem->GetTransactionNum();	// <============	
		}
		// -----------------------------------------------------
		break;

	default:			
		OTLog::sError("%s: Unexpected transaction type in: %s\n", __FUNCTION__, pTransaction->GetTypeString());
		return "";
	}


	OTItem * pAcceptItem = OTItem::CreateItemFromTransaction(*pResponse, 
		(BOOL_DO_I_ACCEPT) ?
theAcceptItemType : theRejectItemType); // set above.


	// Set up the "accept" transaction item to be sent to the server 
	// (this item references and accepts another item by its transaction number--
	//  one that is already there in my inbox)
	pAcceptItem->SetReferenceToNum(lReferenceTransactionNum); // This is critical. Server needs this to look up the original.
	// Don't need to set transaction num on item since the constructor already got it off the owner transaction.

	pAcceptItem->SetAmount(pTransaction->GetReceiptAmount()); // Server validates this, so make sure it's right.

	// the transaction will handle cleaning up the transaction item.
	pResponse->AddItem(*pAcceptItem);

	// I don't attach the original item here because I already reference it by transaction num,
	// and because the server already has it and sent it to me. SO I just need to give the server
	// enough info to look it up again.

	// sign the item
	pAcceptItem->SignContract(*pNym);
	pAcceptItem->SaveContract();

	pResponse->ReleaseSignatures();
	pResponse->SignContract(*pNym);
	pResponse->SaveContract();

	theLedger.ReleaseSignatures();
	theLedger.SignContract(*pNym);
	theLedger.SaveContract();

	OTString strOutput(theLedger); // For the output

	return strOutput.Get(); 
}



// -------------------------------------------------------------------------
//(Response Ledger) LEDGER FINALIZE RESPONSE
//
// AFTER you have set up all the transaction responses, call THIS function
// to finalize them by adding a BALANCE AGREEMENT.
//
// MAKE SURE you have the latest copy of the account file, inbox file, and
// outbox file, since we will need those in here to create the balance statement
// properly.
//
//(Client software may wish to check those things, when downloaded, against
// the local copies and the local signed receipts. In this way, clients can
// protect themselves against malicious servers.)
//
// 'Response' ledger be sent to the server...
string OTAPI_Wrap::Ledger_FinalizeResponse(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & ACCOUNT_ID,
	const string & THE_LEDGER
	)
{
	if (SERVER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }
	if (ACCOUNT_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCOUNT_ID"			); OT_ASSERT(false); }
	if (THE_LEDGER.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_LEDGER"			); OT_ASSERT(false); }

	const OTIdentifier	theServerID(SERVER_ID), 
		theUserID(USER_ID), 
		theAcctID(ACCOUNT_ID);

	OTString strLedger(THE_LEDGER), strServerID(theServerID);


	// --------------------------------------------------------------------
	OTServerContract * pServer(OTAPI_Wrap::OTAPI()->GetServer(theServerID, __FUNCTION__));
	if (NULL == pServer) return "";
	// By this point, pServer is a good pointer.  (No need to cleanup.)
	// --------------------------------------------------------------------
	const OTPseudonym * pServerNym = pServer->GetContractPublicNym();

	if (NULL == pServerNym)
	{
		OTLog::sOutput(0, "%s: No Contract Nym found in that Server Contract.\n", __FUNCTION__);
		return "";
	}
	// By this point, pServerNym is a good pointer.  (No need to cleanup.)
	// -----------------------------------------------------
	OTPseudonym *  pNym(OTAPI_Wrap::OTAPI()->GetOrLoadPrivateNym(theUserID, __FUNCTION__)); // This logs, ASSERTs, etc.
	if (NULL == pNym) return "";
	// By this point, pNym is a good pointer, and is on the wallet. (No need to cleanup.)
	// -----------------------------------------------------	
	OTLedger theLedger(theUserID, theAcctID, theServerID);

	if (false == theLedger.LoadLedgerFromString(strLedger))
	{
		OTString strAcctID(theAcctID);
		OTLog::sError("%s: Error loading ledger from string. Acct ID: %s\n", __FUNCTION__, strAcctID.Get());
		return "";
	}
	else if (false == theLedger.VerifyAccount(*pNym))
	{
		OTString strAcctID(theAcctID);
		OTLog::sError("%s: Error verifying ledger. Acct ID: %s\n", __FUNCTION__, strAcctID.Get());
		return "";
	}

	// At this point, I know theLedger loaded and verified successfully.
	// (This is the 'response' ledger that the user previously generated
	// in response to the various inbox receipts, and now he is loading
	// it up with responses that this function will finalize for sending.)
	// -----------------------------------------------------

	// First, check to see if there is a processInbox transaction already on
	// the ledger...
	OTTransaction * pTransaction = theLedger.GetTransaction(OTTransaction::processInbox);

	// If it's not already there, create it and add it.
	if (NULL == pTransaction)
	{
		OTString strAcctID(theAcctID);
		OTLog::sError("%s: Error finding processInbox transaction for AcctID: %s\n", __FUNCTION__, strAcctID.Get());
		return "";
	}
	// At this point I know pTransaction is a processInbox transaction, ready to go,
	// and that theLedger will handle any cleanup issues related to it.
	// -----------------------------------------------------
	// If balance statement is already there, return.
	if (NULL != pTransaction->GetItem(OTItem::balanceStatement))
	{
		OTLog::sError("%s: this response has already been finalized.\n", __FUNCTION__);
		return "";		
	}
	// -------------------------------------------------------------
	// Get the account. 
	OTAccount *	pAccount = OTAPI_Wrap::OTAPI()->GetAccount(theAcctID, __FUNCTION__);		
	if (NULL == pAccount) return "";
	// -------------------------------------------------------------
	// Load the inbox and outbox.		

	OTLedger theInbox(theUserID, theAcctID, theServerID);
	OTLedger theOutbox(theUserID, theAcctID, theServerID);

	if (!theInbox.LoadInbox() || !theInbox.VerifyAccount(*pNym))
	{
		OTLog::sOutput(0, "%s: Unable to load or verify Inbox for acct %s\n", __FUNCTION__, ACCOUNT_ID);
		return "";		
	}

	if (!theOutbox.LoadOutbox() || !theOutbox.VerifyAccount(*pNym))
	{
		OTLog::sOutput(0, "%s: Unable to load or verify Outbox for acct %s\n", __FUNCTION__, ACCOUNT_ID);
		return "";		
	}

	// -------------------------------------------------------------

	// Setup balance agreement item here!	
	// Adapting code from OTServer... with comments:
	//
	// This transaction accepts various incoming pending transfers.
	// So when it's all done, my balance will be higher.
	// AND pending inbox items will be removed from my inbox.
	// 
	// I would like to not even process the whole giant loop below, 
	// if I can verify here now that the balance agreement is wrong.
	//
	// Thus I will actually loop through the acceptPending items in pTransaction, and then for each one, I'll
	// lookup the ACTUAL transaction in the inbox, and get its ACTUAL value. (And total them all up.)
	//
	// The total of those, (WITHOUT the user having to tell me what it will be, since I'm looking them all up),
	// should equal the difference in the account balance! Meaning the current balance plus that total will be
	// the expected NEW balance, according to this balance agreement -- if it wants to be approved, that is.
	//
	//

	bool bSuccessFindingAllTransactions = true;
	long lTotalBeingAccepted = 0;

	list<long> theListOfInboxReceiptsBeingRemoved;

	OTPseudonym theTempNym;

	FOR_EACH_IT(listOfItems, pTransaction->GetItemList(), it_bigloop)
	{
		OTItem * pItem = *it_bigloop;
		if (NULL == pItem)	{ OTLog::sError("%s: Pointer: %s should not have been NULL.\n", __FUNCTION__, "pItem" ); OT_ASSERT(false); }

		if ((pItem->GetType() == OTItem::acceptPending) ||
			(pItem->GetType() == OTItem::acceptItemReceipt))
		{
			OTTransaction * pServerTransaction = theInbox.GetPendingTransaction(pItem->GetReferenceToNum());

			OTLog::vOutput(0, "%s: Checking client-side inbox for expected pending or receipt transaction: %ld...\n", __FUNCTION__, pItem->GetReferenceToNum()); // temp remove

			if (NULL == pServerTransaction)
			{
				bSuccessFindingAllTransactions = false;
				OTLog::sOutput(0, "%s: NOT found! (Do you have the latest inbox?)\n", __FUNCTION__); // temp remove
				break;
			}
			else 
			{
				bSuccessFindingAllTransactions = true;

				// IF I'm accepting a pending transfer, then add the amount to my counter of total amount being accepted.
				//
				// ELSE if I'm accepting an item receipt (which will remove my responsibility for that item) then add it
				// to the temp Nym (which is a list of transaction numbers that will be removed from my responsibility if
				// all is successful.)  Also remove all the Temp Nym numbers from pNym, so we can verify the Balance
				// Statement AS IF they were already removed. Add them 
				//
				if (pItem->GetType() == OTItem::acceptPending) // acceptPending
					lTotalBeingAccepted += pServerTransaction->GetReceiptAmount();   // <============================

				else if (pItem->GetType() == OTItem::acceptItemReceipt) // acceptItemReceipt
				{
					// What number do I remove here? the user is accepting a transfer receipt, which
					// is in reference to the recipient's acceptPending. THAT item is in reference to
					// my original transfer (or contains a cheque with my original number.) (THAT's the # I need.)
					//
					OTString strOriginalItem;
					pServerTransaction->GetReferenceString(strOriginalItem);

					OTItem * pOriginalItem = OTItem::CreateItemFromString(strOriginalItem, theServerID, 
						pServerTransaction->GetReferenceToNum());
					OTCleanup<OTItem> theOrigItemGuardian(pOriginalItem); // So I don't have to clean it up later. No memory leaks.

					if (NULL != pOriginalItem)
					{
						// If pOriginalItem is acceptPending, that means the client is accepting the transfer receipt from the server, (from his inbox),
						// which has the recipient's acceptance inside of the client's transfer as the original item. This means the transfer that
						// the client originally sent is now finally closed!
						// 
						// If it's a depositCheque, that means the client is accepting the cheque receipt from the server, 
						// (from his inbox)
						// which has the recipient's deposit inside of it as the original item. This means that the cheque that
						// the client originally wrote is now finally closed!
						//
						// In both cases, the "original item" itself is not from the client, but from the recipient! Therefore,
						// the number on that item is useless for removing numbers from the client's list of issued numbers.
						// Rather, I need to load that original cheque, or pending transfer, from WITHIN the original item,
						// in order to get THAT number, to remove it from the client's issued list. (Whether for real, or for
						// setting up dummy data in order to verify the balance agreement.) *sigh*
						//						
						// ----------------------------
						if (OTItem::depositCheque == pOriginalItem->GetType()) // client is accepting a cheque receipt, which has a depositCheque (from the recipient) as the original item within.
						{
							// Get the cheque from the Item and load it up into a Cheque object.
							OTString strCheque;
							pOriginalItem->GetAttachment(strCheque);

							OTCheque theCheque; // allocated on the stack :-)

							if (false == ((strCheque.GetLength() > 2) && 
								theCheque.LoadContractFromString(strCheque)))
							{
								OTLog::sError("%s: ERROR loading cheque from string:\n%s\n", __FUNCTION__, strCheque.Get());
							}
							else	// Since the client wrote the cheque, and he is now accepting the cheque receipt, he can be cleared for that transaction number...
							{
								if (pNym->VerifyIssuedNum(strServerID, theCheque.GetTransactionNum()))
									theTempNym.AddIssuedNum(strServerID, theCheque.GetTransactionNum());
								else
									OTLog::vError("%s: cheque receipt, trying to 'remove' an issued "
									"number (%ld) that already wasn't on my issued list. (So what is this in my inbox, "
									"then? Maybe need to download a fresh copy of it.)\n", __FUNCTION__, 
									theCheque.GetTransactionNum());
							}
						}
						// ----------------------------
						// client is accepting a transfer receipt, which has an acceptPending from the recipient 
						// as the original item within.
						//
						else if (OTItem::acceptPending == pOriginalItem->GetType()) // (which is in reference to the client's outoing original transfer.)
						{
							if (pNym->VerifyIssuedNum(strServerID, pOriginalItem->GetReferenceToNum()))
								theTempNym.AddIssuedNum(strServerID, pOriginalItem->GetReferenceToNum());
							else
								OTLog::vError("%s: transferReceipt, trying to 'remove' an issued "
								"number (%ld) that already wasn't on my issued list. (So what is this in my inbox, "
								"then? Maybe need to download a fresh copy of it.)\n", __FUNCTION__,
								pOriginalItem->GetReferenceToNum());
						}
						// ----------------------------
						else // wrong type.
						{
							OTString strOriginalItemType;
							pOriginalItem->GetTypeString(strOriginalItemType);
							OTLog::sError("%s: Original item has wrong type, while accepting item receipt:\n%s\n", __FUNCTION__, strOriginalItemType.Get());
						}
					}
					else 
					{
						OTLog::sError("%s: Unable to load original item from string while accepting item receipt:\n%s\n", __FUNCTION__, strOriginalItem.Get());
					}
				} // acceptItemReceipt


				// I'll also go ahead and remove each transaction from theInbox, and pass said inbox into the VerifyBalanceAgreement call...
				// (So it can simulate as if the inbox was already changed, and the total is already calculated, and if it succeeds,
				// then we can allow the giant loop below to do it all for real.)
				// (I'm not saving this copy of the inbox anyway--there's another one below.)
				//
				//theInbox.RemovePendingTransaction(pItem->GetReferenceToNum());
				// Let's remove it this way instead:
				//
				//theInbox.RemoveTransaction(pServerTransaction->GetTransactionNum());	// <================
				// Now this is done AFTER this loop...
				//
				theListOfInboxReceiptsBeingRemoved.push_back(pServerTransaction->GetTransactionNum());

			} // pServerTransaction != NULL
		} // if pItem type is accept pending or item receipt.

		// ---------------------------------------------------------------

		else if ((pItem->GetType() == OTItem::acceptCronReceipt) ||
			(pItem->GetType() == OTItem::acceptFinalReceipt) ||
			(pItem->GetType() == OTItem::acceptBasketReceipt)
			)
		{
			OTTransaction * pServerTransaction = theInbox.GetTransaction(pItem->GetReferenceToNum());

			OTLog::vOutput(2, "%s: Checking client-side inbox for expected cron or final or basket receipt: %ld... ", __FUNCTION__, pItem->GetReferenceToNum()); // temp remove

			if (NULL == pServerTransaction)
			{
				bSuccessFindingAllTransactions = false;
				OTLog::sOutput(2, "%s: NOT found! (Do you have the latest inbox?)\n", __FUNCTION__); // temp remove
				break;
			}
			else 
			{
				bSuccessFindingAllTransactions = true;

				switch (pItem->GetType()) 
				{
					// ************************************************************

				case OTItem::acceptCronReceipt:
					// pServerTransaction is a marketReceipt or paymentReceipt
					//

					// When accepting a cron receipt from the inbox, you don't have to clear the issued transaction number.
					// In this case, the original trans# is cleared when the finalReceipt is generated, 
					// and the closing trans# is cleared when the finalReceipt is cleared.

					// So NO issued numbers being removed or added in this case.
					// (But we still remove the receipt from our copy of the inbox, below,
					// so that the balance agreement will reflect as if it had already been
					// successfully removed. (Because balance agreement is meant to show the new
					// state of things, in the event of success--a signed record of those things.)
					break;

					// ************************************************************

				case OTItem::acceptFinalReceipt:                        
					// pServerTransaction is a finalReceipt


					// IN THIS CASE: If we're accepting a finalReceipt, that means all the OTHER receipts related to it
					// (sharing the same "in reference to") must ALSO be cleared from the inbox along with it! That's the
					// whole point of the finalReceipt -- to make sure all related receipts are cleared, when IT is.
					//
					// The server WILL verify this also (I tested it)... That's why we check here, to save the trouble
					// of being rejected by the server.
					//
					// So let's see if the number of related receipts on this process inbox (pTransaction) matches
					// the number of related receipts in the actual inbox (theInbox), as found by the finalReceipt's
					// (pServerTransaction) "in reference to" value, which should be the same as on the related receipts.

					// (Below) pTransaction is the processInbox transaction. Each item on it is in ref to a DIFFERENT receipt,
					// even though, if they are marketReceipts, all of THOSE receipts are in ref to the original transaction#.
					{
						//                      int nRefCount = 0;
						set<long> setOfRefNumbers; // we'll store them here, to disallow duplicates, to make sure they are all unique IDs

						//
						// I need to loop through all items on pTransaction (my processInbox request)
						// For each, look it up on the inbox. (Each item may be "in reference to" 
						// one original transaction or another.) FIND THE ONES that are in reference to
						// the same # as pServerTransaction is.
						//
						FOR_EACH(listOfItems, pTransaction->GetItemList())
						{
							OTItem * pItemPointer = *it;
							if (NULL == pItemPointer)	{ OTLog::sError("%s: Pointer: %s should not have been NULL.\n", __FUNCTION__, "pItemPointer" ); OT_ASSERT(false); }

							// pItemPointer->GetReferenceToNum() is the server's transaction number for the receipt
							// that it dropped into my inbox. pTransPointer is the receipt itself (hopefully.)
							OTTransaction * pTransPointer = theInbox.GetTransaction(pItemPointer->GetReferenceToNum());

							// Careful on the logic here...
							// ONCE EACH INBOX RECEIPT IS DEFINITELY NOT-NULL, and
							// if *IT* is "in reference to" pServerTransaction->GetReferenceToNum(),
							// Then increment the count for the transaction.  COMPARE *THAT* to theInbox.GetCount and we're golden!!
							// Perhaps the finalReceipt is in reference to #10, and there are 6 others that are ALSO in reference to #10.
							// That's a total of 7 receipts in the inbox that are in reference to #10, so my request had better have the
							// same count :-)
							//
							if ((NULL != pTransPointer) && 
								(pTransPointer->GetReferenceToNum() == pServerTransaction->GetReferenceToNum()))
							{
								//                              nRefCount++;
								// set doesn't allow duplicates.
								setOfRefNumbers.insert(pItemPointer->GetReferenceToNum());
							}
						}

						// ---------------------------------------------
						//
						if (static_cast<int>(setOfRefNumbers.size()) 
							!=   // IS NOT EQUAL TO...

							theInbox.GetTransactionCountInRefTo(pServerTransaction->GetReferenceToNum()))
							/* todo: Notice I'm not making sure the count is entirely composed of ACCEPTED receipts. (vs DISPUTED...)
							I probably should add code to GetItemCountInRefTo() so it only counts ACCEPTED receipts.*/
						{
							OTLog::vOutput(0, 
								"%s: When accepting a finalReceipt, you MUST accept all "
								"related receipts (ones that share the same IN REFERENCE TO transaction number as the finalReceipt %ld)\n"
								"Transaction item count (in ref to): %d    Inbox transaction count (in ref to): %ld.\n", __FUNCTION__,
								pServerTransaction->GetReferenceToNum(),
								setOfRefNumbers.size(), 
								theInbox.GetTransactionCountInRefTo(pServerTransaction->GetReferenceToNum()));

							bSuccessFindingAllTransactions = false;
							break;
						}
						// Else NO BREAK;
						//break;  FALLING THROUGH TO BELOW, to do the pNym/theTempNym stuff in the BASKET section...

						// pServerTransaction->GetReferenceToNum() is the OPENING number and should already be closed.
						//
						// IN fact, since the "in reference to" is supposedly already closed, then let's just
						// MAKE SURE of that, since otherwise it'll screw up my future balance agreements. (The
						// instant a finalReceipt appears, the "in ref to" is already gone on the server's side.)
						//
						if (OTTransaction::finalReceipt	== pServerTransaction->GetType())
						{
							if (pNym->RemoveIssuedNum(*pNym, strServerID, pServerTransaction->GetReferenceToNum(), true)) // bool bSave=true
								OTLog::vOutput(1, "%s: **** Due to finding a finalReceipt, REMOVING OPENING NUMBER FROM NYM:  %ld \n", __FUNCTION__, pServerTransaction->GetReferenceToNum());
							else
								OTLog::vOutput(1, "%s: **** Noticed a finalReceipt, but Opening Number %ld had ALREADY been removed from nym. \n", __FUNCTION__, pServerTransaction->GetReferenceToNum());
						}
						else
							OTLog::sError("%s: Expected pServerTransaction to be a final receipt (while finalizing for process inbox.)\n", __FUNCTION__);
						//
						// pNym won't actually save unless it actually removes that #. If the #'s already NOT THERE,
						// then the removal will fail, and thus it won't bother saving here.
					}

					// ... (FALL THROUGH) ...

				case OTItem::acceptBasketReceipt:
					// pServerTransaction is a basketReceipt (or finalReceipt, since falling through from above.)
					//
					// Remove the proper issued number, based on the CLOSING TRANSACTION NUMBER 
					// of the finalReceipt/basketReceipt I'm accepting...
					//

					if (pNym->VerifyIssuedNum(strServerID, pServerTransaction->GetClosingNum()))
						theTempNym.AddIssuedNum(strServerID, pServerTransaction->GetClosingNum());
					else
						OTLog::vError("%s: final or basket Receipt, trying to 'remove' an issued "
						"number (%ld) that already wasn't on my issued list. (So what is this in my inbox, "
						"then? Maybe need to download a fresh copy of it.)\n", __FUNCTION__,
						pServerTransaction->GetClosingNum());
					break;

					// ************************************************************

				default:
					{
						OTString strTempType;
						pItem->GetTypeString(strTempType);
						OTLog::sError("%s: Unexpected item type: %s\n", __FUNCTION__, strTempType.Get());
						break;
					}
				}

				// I'll also go ahead and remove each transaction from theInbox, and pass said inbox into the VerifyBalanceAgreement call...
				// (So it can simulate as if the inbox was already changed, and the total is already calculated, and if it succeeds,
				// then we can allow the giant loop below to do it all for real.)
				// (I'm not saving this copy of the inbox anyway--there's another one below.)
				//
				//theInbox.RemoveTransaction(pItem->GetReferenceToNum());
				// Let's remove it this way instead:
				//
				//				theInbox.RemoveTransaction(pServerTransaction->GetTransactionNum());	// <================
				//
				// Actually, let's remove it this way:
				theListOfInboxReceiptsBeingRemoved.push_back(pServerTransaction->GetTransactionNum());

			} // else if pServerTransaction NOT NULL.
		} // If acceptCronReceipt/acceptFinalReceipt/acceptBasketReceipt
	}

	// ------------------------------------------

	if (false == bSuccessFindingAllTransactions) // failure.
	{
		OTLog::sOutput(0, "%s: transactions in processInbox message do not match actual inbox.\n", __FUNCTION__);

		return "";		// RETURN.
	}
	// ---------------------------------------------------------------------

	// SUCCESS finding all transactions

	while (!theListOfInboxReceiptsBeingRemoved.empty())
	{
		long lTemp = theListOfInboxReceiptsBeingRemoved.front();
		theListOfInboxReceiptsBeingRemoved.pop_front();

		if (false == theInbox.RemoveTransaction(lTemp))    // <================
			OTLog::vError("%s: Failed removing receipt from temporary Inbox: %ld \n", __FUNCTION__, lTemp); 
	}

	// *****************************************************************

	// SET UP NYM FOR BALANCE AGREEMENT.

	// By this point, theTempNym contains a list of all the transaction numbers that are issued to me,
	// but that will NOT be issued to me anymore once this processInbox is processed.
	// Therefore I need to REMOVE those items from my issued list (at least temporarily) in order to
	// calculate the balance agreement properly. So I used theTempNym as a temp variable to store those
	// numbers, so I can remove them from my Nym and them add them again after generating the statement.
	//
	for (int i = 0; i < theTempNym.GetIssuedNumCount(theServerID); i++)
	{
		long lTemp = theTempNym.GetIssuedNum(theServerID, i);
		pNym->RemoveIssuedNum(strServerID, lTemp);
	}

	// -----------------------------------------

	// BALANCE AGREEMENT 
	//
	// The item is signed and saved within this call as well. No need to do that again.
	//
	OTItem * pBalanceItem = theInbox.GenerateBalanceStatement(lTotalBeingAccepted, *pTransaction, *pNym, *pAccount, theOutbox);

	// -----------------------------------------

	// Here I am adding these numbers back again, since I removed them to generate the balance agreement.
	// (They won't be removed for real until I receive the server's acknowledgment that those numbers
	// really were removed. theTempNym then I have to keep them and use them for my balance agreements.)
	//
	for (int i = 0; i < theTempNym.GetIssuedNumCount(theServerID); i++)
	{
		long lTemp = theTempNym.GetIssuedNum(theServerID, i);
		pNym->AddIssuedNum(strServerID, lTemp);
	}						

	// *****************************************************************

	if (NULL == pBalanceItem)
	{
		OTLog::sOutput(0, "%s: ERROR generating balance statement.\n", __FUNCTION__);

		return "";
	}

	// the transaction will handle cleaning up the transaction item.
	pTransaction->AddItem(*pBalanceItem);

	// -----------------------------------------

	// sign the item
	// This already happens in the GenerateBalanceStatement() call above.
	// I would actually have to RELEASE the signatures if I wanted to sign again!
	// (Unless I WANT two signatures...)
	//
	//	pBalanceItem->SignContract(*pNym);
	//	pBalanceItem->SaveContract();

	pTransaction->ReleaseSignatures();
	pTransaction->SignContract(*pNym);
	pTransaction->SaveContract();

	theLedger.ReleaseSignatures();
	theLedger.SignContract(*pNym);
	theLedger.SaveContract();

	OTString strOutput(theLedger); // For the output

	return strOutput.Get(); 
}



// -------------------------------------------------------------------------
// Ledger_GetInstrument(by index)
//
// Lookup a financial instrument(from within a transaction that is inside
// a ledger) based on index or transaction number.
/*
sendUserInstrument does this:
-- Puts an OTPayment(a form of contract) as an encrypted Payload on an OTMessage(1).
-- Also puts instrument(same contract) as CLEAR payload on an OTMessage(2).
--(1) is sent to server, and(2) is added to Outpayments messages.
--(1) gets added to recipient's Nymbox as "in ref to" string on a "instrumentNotice" transaction.
-- When recipient processes Nymbox, the "instrumentNotice" transaction(containing(1) in its "in ref to"
field) is copied and added to the recipient's paymentInbox.
-- When recipient iterates through paymentInbox transactions, they are ALL "instrumentNotice"s. Each 
transaction contains an OTMessage in its "in ref to" field, and that OTMessage object contains an 
encrypted payload of the instrument itself(an OTPayment object containing a cheque or payment plan
or invoice etc.)
-- When sender gets Outpayments contents, the original instrument(inside an OTPayment) is stored IN THE 
CLEAR as payload on an OTMessage.

THEREFORE:
TO EXTRACT INSTRUMENT FROM PAYMENTS INBOX:
-- Iterate through the transactions in the payments inbox.
--(They should all be "instrumentNotice" transactions.)
-- Each transaction contains(1) OTMessage in "in ref to" field, which in turn contains an encrypted
OTPayment in the payload field, which then contains the instrument itself.
-- *** Therefore, this function, based purely on ledger index(as we iterate) extracts the
OTMessage from the Transaction "in ref to" field(for the transaction at that index), then decrypts
the payload on that message and returns the decrypted cleartext. 
*/
// returns financial instrument by index of the transaction it's in.
string OTAPI_Wrap::Ledger_GetInstrument(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & ACCOUNT_ID,
	const string & THE_LEDGER,
	const int32_t & nIndex
	)
{
	if (SERVER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }
	if (ACCOUNT_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCOUNT_ID"			); OT_ASSERT(false); }
	if (THE_LEDGER.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_LEDGER"			); OT_ASSERT(false); }

	if (0 > nIndex) { OTLog::sError("%s: nIndex is out of bounds (it's in the negative!)\n", __FUNCTION__); OT_ASSERT(false); }

	const OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theAccountID(ACCOUNT_ID);

	// -----------------------------------------------------
	OTPseudonym *  pNym(OTAPI_Wrap::OTAPI()->GetNym(theUserID, __FUNCTION__));
	if (NULL == pNym) return "";
	// -------------------------
	OTString strLedger(THE_LEDGER);	
	OTLedger theLedger(theUserID, theAccountID, theServerID);
	//	set<long> setUnloaded;

	if (	!theLedger.LoadLedgerFromString(strLedger)
		//		||	!theLedger.LoadBoxReceipts(&setUnloaded)	// This is done below, for the individual transaction, for better optimization.
		)
	{
		OTString strAcctID(theAccountID);
		OTLog::sError("%s: Error loading ledger from string. Acct ID: %s\n", __FUNCTION__, strAcctID.Get());
		return "";
	}
	// -----------------------------------------------------
	// At this point, I know theLedger loaded successfully.

	if (nIndex >= theLedger.GetTransactionCount())
	{
		OTLog::vError("%s: out of bounds: %d\n", __FUNCTION__, nIndex);
		return ""; // out of bounds. I'm saving from an OT_ASSERT_MSG() happening here. (Maybe I shouldn't.)
	}
	// -----------------------------------------------------

	OTTransaction * pTransaction = theLedger.GetTransactionByIndex(nIndex);
	//	OTCleanup<OTTransaction> theAngel(pTransaction); // THE LEDGER CLEANS THIS ALREADY.

	if (NULL == pTransaction)
	{
		OTLog::vError("%s: good index but uncovered NULL pointer: %d\n", __FUNCTION__, nIndex);
		return ""; // Weird.
	}
	// -----------------------------------------------------

	const long lTransactionNum = pTransaction->GetTransactionNum();

	// Update: for transactions in ABBREVIATED form, the string is empty, since it has never actually
	// been signed (in fact the whole point with abbreviated transactions in a ledger is that they 
	// take up very little room, and have no signature of their own, but exist merely as XML tags on
	// their parent ledger.)
	//
	// THEREFORE I must check to see if this transaction is abbreviated and if so, sign it in order to
	// force the UpdateContents() call, so the programmatic user of this API will be able to load it up.
	//
	if (pTransaction->IsAbbreviated())
	{
		theLedger.LoadBoxReceipt(lTransactionNum); // I don't check return val here because I still want it to send the abbreviated form, if this fails.
		pTransaction = theLedger.GetTransaction(lTransactionNum);
		// -------------------------
		if (NULL == pTransaction)
		{
			OTLog::vError("%s: good index but uncovered NULL pointer after trying to load full version of receipt (from abbreviated) at index: %d\n", __FUNCTION__, nIndex);
			return ""; // Weird.
		}
	}
	// ------------------------------------------------
	/*
	TO EXTRACT INSTRUMENT FROM PAYMENTS INBOX:
	-- Iterate through the transactions in the payments inbox.
	-- (They should all be "instrumentNotice" transactions.)
	-- Each transaction contains (1) OTMessage in "in ref to" field, which in turn contains an encrypted
	OTPayment in the payload field, which contains the actual financial instrument.
	-- *** Therefore, this function, based purely on ledger index (as we iterate):
	1. extracts the OTMessage from the Transaction "in ref to" field (for the transaction at that index), 
	2. then decrypts the payload on that message, producing an OTPayment object, 
	3. ...which contains the actual instrument.
	*/
	// ------------------------------------------------
	if ((OTTransaction::instrumentNotice	!= pTransaction->GetType()) &&
		(OTTransaction::notice				!= pTransaction->GetType()))
	{
		OTLog::sOutput(0, "%s: Failure: Expected OTTransaction::instrumentNotice or notice, but found: OTTransaction::%s\n", __FUNCTION__, pTransaction->GetTypeString());
		return "";
	}
	// ------------------------------------------------

	if (OTTransaction::instrumentNotice	== pTransaction->GetType()) // It's encrypted.
	{
		OTString strMsg;
		pTransaction->GetReferenceString(strMsg);

		if (!strMsg.Exists())
		{
			OTLog::sOutput(0, "%s: Failure: Expected OTTransaction::instrumentNotice to contain an 'in reference to' string, but it was empty. (Returning NULL.)\n", __FUNCTION__);
			return "";
		}
		// ------------------------------------------------

		std::tr1::shared_ptr<OTMessage> pMsg(new OTMessage());
		if (NULL == pMsg) { OTLog::sError("%s: Null:  Assert while allocating memory for an OTMessage!\n", __FUNCTION__); OT_ASSERT(false); }

		if (false == pMsg->LoadContractFromString(strMsg))
		{
			OTLog::sOutput(0, "%s: Failed trying to load OTMessage from string:\n\n%s\n\n", __FUNCTION__, strMsg.Get());
			return "";		
		}
		// ------------------------------------------------
		// By this point, the original OTMessage has been loaded from string successfully.
		// Now we need to decrypt the payment on that message (which contains the instrument
		// itself that we need to return.) We decrypt it the same way as we do in 
		// OT_API_GetNym_MailContentsByIndex():
		//

		// SENDER:     pMsg->m_strNymID
		// RECIPIENT:  pMsg->m_strNymID2
		// INSTRUMENT: pMsg->m_ascPayload (in an OTEnvelope)
		//	
		OTEnvelope	theEnvelope;
		OTString	strEnvelopeContents;

		// Decrypt the Envelope.
		if (theEnvelope.SetAsciiArmoredData(pMsg->m_ascPayload) &&
			theEnvelope.Open(*pNym, strEnvelopeContents))
		{
			OTPayment   thePayment;
			OTString    strPaymentContents;

			if ((!thePayment.IsValid())  ||
				(false == thePayment.LoadContractFromString(strEnvelopeContents)) ||
				(false == thePayment.GetPaymentContents(strPaymentContents))
				)
			{
				OTLog::sOutput(0, "%s: ERROR_STATE while trying to resurrect payment from string:\n\n%s\n\n", __FUNCTION__, strEnvelopeContents.Get());
				return "";		
			}
			// ------------------------------------------------------
			return strPaymentContents.Get();
		}
		else
			OTLog::sOutput(0, "%s: Failed trying to decrypt the financial instrument that was supposedly attached as a payload to this payment message:\n\n%s\n\n", __FUNCTION__, strMsg.Get());
	}
	else
		OTLog::sError("%s: This must be a notice (vs an instrumentNotice). !!! Not yet supported !!!\n", __FUNCTION__);

	return "";
}

// --------------------------------------------------------------------
// Get Transaction Type(const int32_ternally uses GetTransactionTypestring().)
//
string OTAPI_Wrap::Transaction_GetType(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & ACCOUNT_ID,
	const string & THE_TRANSACTION
	)
{
	if (SERVER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }
	if (ACCOUNT_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCOUNT_ID"			); OT_ASSERT(false); }
	if (THE_TRANSACTION.empty())	{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_TRANSACTION"	); OT_ASSERT(false); }

	const OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theAccountID(ACCOUNT_ID);

	OTString strTransaction(THE_TRANSACTION);

	// -----------------------------------------------------
	OTPseudonym *  pNym(OTAPI_Wrap::OTAPI()->GetOrLoadPrivateNym(theUserID, __FUNCTION__)); // These copiously log, and ASSERT.
	if (NULL == pNym) return "";
	// -----------------------------------------------------

	OTTransaction theTransaction(theUserID, theAccountID, theServerID);

	if (false == theTransaction.LoadContractFromString(strTransaction))
	{
		OTString strAcctID(theAccountID);
		OTLog::sError("%s: Error loading transaction from string. Acct ID: %s\n", __FUNCTION__, strAcctID.Get());
		return "";
	}

	// -----------------------------------------------------
	// NO need to load abbreviated version, since it already stores this number.

	return theTransaction.GetTypeString(); 	
}


// Transactions do not have request numbers. However, if you have a replyNotice
// in your Nymbox, which is an OTTransaction object, it will CONTAIN a server
// reply to some previous message. This function will only work on a replyNotice,
// and it returns the actual request number of the server reply inside that notice.
// Used for calling HaveAlreadySeenReply() in order to see if we've already
// processed the reply for that message.
//
int64_t OTAPI_Wrap::ReplyNotice_GetRequestNum(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & THE_TRANSACTION
	)
{
	if (SERVER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }
	if (THE_TRANSACTION.empty())	{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_TRANSACTION"	); OT_ASSERT(false); }

	const OTIdentifier  theServerID(SERVER_ID),
		theUserID(USER_ID), 
		theAccountID(USER_ID); // account IS user, for Nymbox (the only box that carries replyNotices...)

	OTString strTransaction(THE_TRANSACTION);

	// -----------------------------------------------------
	OTPseudonym *  pNym(OTAPI_Wrap::OTAPI()->GetOrLoadPrivateNym(theUserID, __FUNCTION__)); // These copiously log, and ASSERT.
	if (NULL == pNym) return -1;
	// -----------------------------------------------------

	OTTransaction theTransaction(theUserID, theAccountID, theServerID);

	if (false == theTransaction.LoadContractFromString(strTransaction))
	{
		OTString strUserID(theUserID);
		OTLog::sError("%s: Error loading transaction from string. User ID: %s\n",__FUNCTION__, strUserID.Get());
		return -1;
	}

	// -----------------------------------------------------
	if (OTTransaction::replyNotice != theTransaction.GetType())
	{
		OTString strUserID(theUserID);
		OTLog::sError("%s: Unexpected transaction type: %s. (Expected: %s) User: %s\n",__FUNCTION__, theTransaction.GetTypeString(), "replyNotice", strUserID.Get());
		return -1;
	}
	// -----------------------------------------------------
	// NO need to load abbreviated version, since it already stores this number.

	const long lRequestNumber = theTransaction.GetRequestNum();

	return lRequestNumber;
}



// --------------------------------------------------------------------
// Retrieve Voucher from Transaction
//
// If you withdrew int32_to a voucher instead of cash, this function allows
// you to retrieve the actual voucher cheque from the reply transaction.
//(A voucher is a cheque drawn on an int32_ternal server account instead
// of a user's asset account, so the voucher cannot ever bounce due to 
// insufficient funds. We are accustomed to this functionality already
// in our daily lives, via "money orders" and "cashier's cheques".)
//
// How would you use this in full?
//
// First, call withdrawVoucher() in order to send the request
// to the server.(You may optionally call FlushMessageBuffer()
// before doing this.)
//
// Then, call PopMessageBuffer() to retrieve any server reply.
//
// If there is a message from the server in reply, then call 
// Message_GetCommand to verify that it's a reply to the message
// that you sent, and call Message_GetSuccess to verify whether
// the message was a success.
//
// If it was a success, next call Message_GetLedger to retrieve
// the actual "reply ledger" from the server.
//
// Penultimately, call Ledger_GetTransactionByID() and then,
// finally, call Transaction_GetVoucher()(below) in order to
// retrieve the voucher cheque itself from the transaction.
//
string OTAPI_Wrap::Transaction_GetVoucher(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & ACCOUNT_ID,
	const string & THE_TRANSACTION
	)
{
	if (SERVER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }
	if (ACCOUNT_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCOUNT_ID"			); OT_ASSERT(false); }
	if (THE_TRANSACTION.empty())	{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_TRANSACTION"	); OT_ASSERT(false); }

	const OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theAccountID(ACCOUNT_ID);

	OTString strTransaction(THE_TRANSACTION);

	OTString strOutput;

	// -----------------------------------------------------
	OTPseudonym *  pNym(OTAPI_Wrap::OTAPI()->GetOrLoadPrivateNym(theUserID, __FUNCTION__)); // These copiously log, and ASSERT.
	if (NULL == pNym) return "";
	// -----------------------------------------------------

	OTTransaction theTransaction(theUserID, theAccountID, theServerID);

	if (false == theTransaction.LoadContractFromString(strTransaction))
	{
		OTString strAcctID(theAccountID);
		OTLog::sError("%s: Error loading transaction from string. Acct ID: %s\n", __FUNCTION__, strAcctID.Get());
		return "";
	}
	// No need to check if transaction is abbreviated, since it's coming from a message ledger.
	// (Those always contain the full version of the transactions, automatically.)
	// -----------------------------------------------------

	if (OTTransaction::atWithdrawal != theTransaction.GetType())
	{
		OTLog::sError("%s: Error: tried to retrieve voucher from wrong transaction (not atWithdrawal).\n", __FUNCTION__);
		return "";
	}

	// -----------------------------------------------------

	// loop through the ALL items that make up this transaction and check to see if a response to withdrawal.

	// if pointer not null, and it's a withdrawal, and it's an acknowledgement (not a rejection or error)
	FOR_EACH(listOfItems, theTransaction.GetItemList())
	{
		OTItem * pItem = *it;
		if (NULL == pItem)	{ OTLog::sError("%s: Pointer: %s should not have been NULL.\n", __FUNCTION__, "pItem" ); OT_ASSERT(false); }

		if ((OTItem::atWithdrawVoucher	== pItem->GetType()) &&
			(OTItem::acknowledgement	== pItem->GetStatus()))
		{ 
			OTString	strVoucher;
			pItem->GetAttachment(strVoucher);

			OTCheque	theVoucher;
			if (theVoucher.LoadContractFromString(strVoucher)) // Todo additional verification here on the cheque.
			{
				theVoucher.SaveContractRaw(strOutput);
				break;			
			}
		}
	}

	// -----------------------------------------------------

	// Didn't find one.
	if (!strOutput.Exists())
		return "";

	// We found a voucher -- let's return it!
	//
	return strOutput.Get(); 
}


// --------------------------------------------------
//
// Get Transaction Success:
//-1 == error
// 1 == acknowledgment
// 0 == rejection 
//
int32_t OTAPI_Wrap::Transaction_GetSuccess(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & ACCOUNT_ID,
	const string & THE_TRANSACTION
	)
{
	if (SERVER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }
	if (ACCOUNT_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCOUNT_ID"			); OT_ASSERT(false); }
	if (THE_TRANSACTION.empty())	{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_TRANSACTION"	); OT_ASSERT(false); }

	const OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theAccountID(ACCOUNT_ID);

	OTString strTransaction(THE_TRANSACTION);

	// -----------------------------------------------------
	OTPseudonym *  pNym(OTAPI_Wrap::OTAPI()->GetOrLoadPrivateNym(theUserID, __FUNCTION__)); // These copiously log, and ASSERT.
	if (NULL == pNym) return 0;
	// By this point, pNym is a good pointer, and is on the wallet. (No need to cleanup.)
	// -----------------------------------------------------				
	OTTransaction theTransaction(theUserID, theAccountID, theServerID);

	if (false == theTransaction.LoadContractFromString(strTransaction))
	{
		OTString strAcctID(theAccountID);
		OTLog::sError("%s: Error loading transaction from string. Acct ID: %s\n", __FUNCTION__, strAcctID.Get());
		return -1;
	}
	// -----------------------------------------------------
	OTTransaction * pTransaction = NULL;
	OTCleanup<OTTransaction> theTransAngel;

	if (theTransaction.IsAbbreviated()) // Abbreviated.
	{
		long lBoxType = 0;

		// --------------
		if (theTransaction.Contains("nymboxRecord"))           lBoxType = static_cast<long>(OTLedger::nymbox);
		else if (theTransaction.Contains("inboxRecord"))            lBoxType = static_cast<long>(OTLedger::inbox);
		else if (theTransaction.Contains("outboxRecord"))           lBoxType = static_cast<long>(OTLedger::outbox);
		else if (theTransaction.Contains("paymentInboxRecord"))		lBoxType = static_cast<long>(OTLedger::paymentInbox);
		else if (theTransaction.Contains("recordBoxRecord"))		lBoxType = static_cast<long>(OTLedger::recordBox);
		else
		{
			OTLog::sError("%s: Error loading from abbreviated transaction: unknown ledger type. \n", __FUNCTION__);
			return -1;
		}
		// --------------
		pTransaction = OTTransaction::LoadBoxReceipt(theTransaction, lBoxType);
		if (NULL == pTransaction)
		{
			OTLog::sError("%s: Error loading from abbreviated transaction: failed loading box receipt. \n", __FUNCTION__);
			return -1;			
		}
		// ----------------
		theTransAngel.SetCleanupTargetPointer(pTransaction);
	}
	else        // NOT abbreviated.
		pTransaction = &theTransaction;
	// -----------------------------------------------------	

	if (pTransaction->GetSuccess())
	{
		return 1;
	}
	else
	{
		const long lTransactionNum = pTransaction->GetTransactionNum();

		OTLog::vError("%s: ** FYI, this transaction has a 'failure' status from the server. TransNum: %ld\n", __FUNCTION__, lTransactionNum);
	}

	return 0;
}

// Gets the balance agreement success(from a transaction.)
//
int32_t OTAPI_Wrap::Transaction_GetBalanceAgreementSuccess(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & ACCOUNT_ID,
	const string & THE_TRANSACTION
	)
{
	if (SERVER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }
	if (ACCOUNT_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCOUNT_ID"			); OT_ASSERT(false); }
	if (THE_TRANSACTION.empty())	{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_TRANSACTION"	); OT_ASSERT(false); }

	const OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theAccountID(ACCOUNT_ID);

	OTString strTransaction(THE_TRANSACTION);
	// -----------------------------------------------------

	// -----------------------------------------------------
	OTPseudonym *  pNym(OTAPI_Wrap::OTAPI()->GetOrLoadPrivateNym(theUserID, __FUNCTION__)); // These copiously log, and ASSERT.
	if (NULL == pNym) return 0;
	// By this point, pNym is a good pointer, and is on the wallet. (No need to cleanup.)
	// -----------------------------------------------------					
	OTTransaction theTransaction(theUserID, theAccountID, theServerID);

	if (false == theTransaction.LoadContractFromString(strTransaction))
	{
		OTString strAcctID(theAccountID);
		OTLog::sError("%s: Error loading transaction from string. Acct ID: %s\n", __FUNCTION__, strAcctID.Get());
		return -1;
	}
	// -----------------------------------------------------
	OTTransaction * pTransaction = NULL;
	OTCleanup<OTTransaction> theTransAngel;

	if (theTransaction.IsAbbreviated())  // IF TRANSACTION IS ABBREVIATED (Ledger may only contain stubs, not full records...)
	{
		long lBoxType = 0;

		// ----------------
		if (theTransaction.Contains("nymboxRecord"))		lBoxType = static_cast<long>(OTLedger::nymbox);
		else if (theTransaction.Contains("inboxRecord"))        lBoxType = static_cast<long>(OTLedger::inbox);
		else if (theTransaction.Contains("outboxRecord"))       lBoxType = static_cast<long>(OTLedger::outbox);
		else if (theTransaction.Contains("paymentInboxRecord"))	lBoxType = static_cast<long>(OTLedger::paymentInbox);
		else if (theTransaction.Contains("recordBoxRecord"))	lBoxType = static_cast<long>(OTLedger::recordBox);
		else
		{
			OTLog::sError("%s: Error loading from abbreviated transaction: unknown ledger type. \n", __FUNCTION__);
			return -1;			
		}
		// --------------
		pTransaction = OTTransaction::LoadBoxReceipt(theTransaction, lBoxType);
		if (NULL == pTransaction)
		{
			OTLog::sError("%s: Error loading from abbreviated transaction: failed loading box receipt.\n", __FUNCTION__);
			return -1;			
		}
		// ----------------
		theTransAngel.SetCleanupTargetPointer(pTransaction);
	}
	else
		pTransaction = &theTransaction;
	// -----------------------------------------------------	
	// At this point, I actually have the transaction pointer, so let's return its success status
	OTItem * pReplyItem = pTransaction->GetItem(OTItem::atBalanceStatement);

	if (NULL == pReplyItem)
		pReplyItem = pTransaction->GetItem(OTItem::atTransactionStatement);

	if (NULL == pReplyItem)
	{
		OTLog::sError("%s: good transaction (could have been abbreviated though) but uncovered NULL item pointer.\n", __FUNCTION__);
		return -1; // Weird.
	}

	return pReplyItem->GetStatus() == OTItem::acknowledgement;
}


// --------------------------------------------------
//
// Get Transaction Date Signed(const int32_ternally uses OTTransaction::GetDateSigned().)
//
time_t OTAPI_Wrap::Transaction_GetDateSigned(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & ACCOUNT_ID,
	const string & THE_TRANSACTION
	)
{
	if (SERVER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }
	if (ACCOUNT_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCOUNT_ID"			); OT_ASSERT(false); }
	if (THE_TRANSACTION.empty())	{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_TRANSACTION"	); OT_ASSERT(false); }

	const OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theAccountID(ACCOUNT_ID);

	OTString strTransaction(THE_TRANSACTION);

	// -----------------------------------------------------
	OTPseudonym *  pNym(OTAPI_Wrap::OTAPI()->GetOrLoadPrivateNym(theUserID, __FUNCTION__)); // These copiously log, and ASSERT.
	if (NULL == pNym) return -1;
	// -----------------------------------------------------

	OTTransaction theTransaction(theUserID, theAccountID, theServerID);

	if (false == theTransaction.LoadContractFromString(strTransaction))
	{
		OTString strAcctID(theAccountID);
		OTLog::sError("%s: Error loading transaction from string. Acct ID: %s\n", __FUNCTION__, strAcctID.Get());
		return -1;
	}
	// NO need to load abbreviated version here, since it already stores the date.
	// -----------------------------------------------------

	OTString strOutput;
	const long lDateSigned = static_cast<long> (theTransaction.GetDateSigned());

	return lDateSigned;
}

int64_t OTAPI_Wrap::Transaction_GetAmount(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & ACCOUNT_ID,
	const string & THE_TRANSACTION
	)
{
	if (SERVER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }
	if (ACCOUNT_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCOUNT_ID"			); OT_ASSERT(false); }
	if (THE_TRANSACTION.empty())	{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_TRANSACTION"	); OT_ASSERT(false); }

	const OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theAccountID(ACCOUNT_ID);

	OTString strTransaction(THE_TRANSACTION);

	// -----------------------------------------------------
	OTPseudonym *  pNym(OTAPI_Wrap::OTAPI()->GetOrLoadPrivateNym(theUserID, __FUNCTION__)); // These copiously log, and ASSERT.
	if (NULL == pNym) return -1;
	// -----------------------------------------------------

	OTTransaction theTransaction(theUserID, theAccountID, theServerID);

	if (false == theTransaction.LoadContractFromString(strTransaction))
	{
		OTString strAcctID(theAccountID);
		OTLog::sError("%s: Error loading transaction from string. Acct ID: %s\n", __FUNCTION__, strAcctID.Get());
		return -1;
	}

	// -----------------------------------------------------
	OTTransaction * pTransaction = NULL;
	OTCleanup<OTTransaction> theTransAngel;

	if (theTransaction.IsAbbreviated())
	{
		long lBoxType = 0;

		if (theTransaction.Contains("nymboxRecord"))		lBoxType = static_cast<long>(OTLedger::nymbox);
		else if (theTransaction.Contains("inboxRecord"))        lBoxType = static_cast<long>(OTLedger::inbox);
		else if (theTransaction.Contains("outboxRecord"))       lBoxType = static_cast<long>(OTLedger::outbox);
		else if (theTransaction.Contains("paymentInboxRecord"))	lBoxType = static_cast<long>(OTLedger::paymentInbox);
		else if (theTransaction.Contains("recordBoxRecord"))	lBoxType = static_cast<long>(OTLedger::recordBox);
		else
		{
			OTLog::sError("%s: Error loading from abbreviated transaction: unknown ledger type. \n", __FUNCTION__);
			return -1;			
		}
		// --------------
		pTransaction = OTTransaction::LoadBoxReceipt(theTransaction, lBoxType);
		if (NULL == pTransaction)
		{
			OTLog::sError("%s: Error loading from abbreviated transaction: failed loading box receipt. \n", __FUNCTION__);
			return -1;			
		}
		// ----------------
		theTransAngel.SetCleanupTargetPointer(pTransaction);
	}
	else
		pTransaction = &theTransaction;
	// -----------------------------------------------------	

	OTString strOutput;
	const long lAmount = pTransaction->GetReceiptAmount();

	return lAmount;
}


// --------------------------------------------------
//
// PENDING TRANSFER(various functions)
//
// When someone has sent you a PENDING TRANSFER(a form of transaction
// that will be sitting in your inbox waiting for you to accept/reject it)
// then, as you are reading the inbox, you can use these functions in
// order to get data from each pending transfer. That way your user can
// then decide whether to accept or reject it(see the ledger functions.)
//

string OTAPI_Wrap::Pending_GetNote(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & ACCOUNT_ID,
	const string & THE_TRANSACTION
	)
{
	if (SERVER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }
	if (ACCOUNT_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCOUNT_ID"			); OT_ASSERT(false); }
	if (THE_TRANSACTION.empty())	{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_TRANSACTION"	); OT_ASSERT(false); }

	const OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theAccountID(ACCOUNT_ID);

	OTString strTransaction(THE_TRANSACTION);

	// -----------------------------------------------------
	OTPseudonym *  pNym(OTAPI_Wrap::OTAPI()->GetOrLoadPrivateNym(theUserID, __FUNCTION__)); // These copiously log, and ASSERT.
	if (NULL == pNym) return "";
	// -----------------------------------------------------

	OTTransaction theTransaction(theUserID, theAccountID, theServerID);

	if (false == theTransaction.LoadContractFromString(strTransaction))
	{
		OTString strAcctID(theAccountID);
		OTLog::sError("%s: Error loading transaction from string. Acct ID: %s\n", __FUNCTION__, strAcctID.Get());
		return "";
	}

	// -----------------------------------------------------
	OTTransaction * pTransaction = NULL;
	OTCleanup<OTTransaction> theTransAngel;

	if (theTransaction.IsAbbreviated())
	{
		long lBoxType = 0;

		if (theTransaction.Contains("nymboxRecord"))		lBoxType = static_cast<long>(OTLedger::nymbox);
		else if (theTransaction.Contains("inboxRecord"))        lBoxType = static_cast<long>(OTLedger::inbox);
		else if (theTransaction.Contains("outboxRecord"))       lBoxType = static_cast<long>(OTLedger::outbox);
		else if (theTransaction.Contains("paymentInboxRecord"))	lBoxType = static_cast<long>(OTLedger::paymentInbox);
		else if (theTransaction.Contains("recordBoxRecord"))	lBoxType = static_cast<long>(OTLedger::recordBox);
		else
		{
			OTLog::sError("%s Error loading from abbreviated transaction: unknown ledger type. \n", __FUNCTION__);
			return "";			
		}
		// --------------
		pTransaction = OTTransaction::LoadBoxReceipt(theTransaction, lBoxType);
		if (NULL == pTransaction)
		{
			OTLog::sError("%s: Error loading from abbreviated transaction: failed loading box receipt. \n", __FUNCTION__);
			return "";			
		}
		// ----------------
		theTransAngel.SetCleanupTargetPointer(pTransaction);
	}
	else
		pTransaction = &theTransaction;
	// -----------------------------------------------------	

	if (OTTransaction::pending != pTransaction->GetType())
	{
		OTLog::sError("%s: wrong transaction type: %s. (Expected \"pending\".)\n", __FUNCTION__, pTransaction->GetTypeString());
		return "";		
	}

	// -----------------------------------------------------

	OTString strReference;
	pTransaction->GetReferenceString(strReference);

	if (!strReference.Exists())
	{
		OTLog::sError("%s: No reference string found on transaction.\n", __FUNCTION__);
		return "";				
	}

	// -----------------------------------------------------

	OTItem * pItem = OTItem::CreateItemFromString(strReference, theServerID, pTransaction->GetReferenceToNum());
	OTCleanup<OTItem> theAngel(pItem);

	if (NULL == pItem)
	{
		OTLog::sError("%s: Failed loading transaction item from string.\n", __FUNCTION__);
		return "";				
	}

	// pItem will be automatically cleaned up when it goes out of scope.
	// -----------------------------------------------------


	if ((OTItem::transfer	!= pItem->GetType()) ||
		(OTItem::request	!= pItem->GetStatus()))
	{ 
		OTLog::sError("%s: Wrong item type or status attached as reference on transaction.\n", __FUNCTION__);
		return "";				
	}


	// -----------------------------------------------------

	OTString strOutput;

	pItem->GetNote(strOutput);

	// -----------------------------------------------------

	// Didn't find one.
	if (!strOutput.Exists())
		return "";

	// We found a note -- let's return it!
	//
	return strOutput.Get(); 
}



// ----------

string OTAPI_Wrap::Transaction_GetSenderUserID(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & ACCOUNT_ID,
	const string & THE_TRANSACTION
	)
{
	if (SERVER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }
	if (ACCOUNT_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCOUNT_ID"			); OT_ASSERT(false); }
	if (THE_TRANSACTION.empty())	{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_TRANSACTION"	); OT_ASSERT(false); }

	const OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theAccountID(ACCOUNT_ID);

	OTString strTransaction(THE_TRANSACTION);

	// -----------------------------------------------------
	OTPseudonym *  pNym(OTAPI_Wrap::OTAPI()->GetOrLoadPrivateNym(theUserID, __FUNCTION__)); // These copiously log, and ASSERT.
	if (NULL == pNym) return "";
	// -----------------------------------------------------

	OTTransaction theTransaction(theUserID, theAccountID, theServerID);

	if (false == theTransaction.LoadContractFromString(strTransaction))
	{
		OTString strAcctID(theAccountID);
		OTLog::sError("%s: Error loading transaction from string. Acct ID: %s\n", __FUNCTION__, strAcctID.Get());
		return "";
	}
	// -----------------------------------------------------
	OTTransaction * pTransaction = NULL;
	OTCleanup<OTTransaction> theTransAngel;

	if (theTransaction.IsAbbreviated())
	{
		long lBoxType = 0;

		if (theTransaction.Contains("nymboxRecord"))       lBoxType = static_cast<long>(OTLedger::nymbox);
		else if (theTransaction.Contains("inboxRecord"))        lBoxType = static_cast<long>(OTLedger::inbox);
		else if (theTransaction.Contains("outboxRecord"))       lBoxType = static_cast<long>(OTLedger::outbox);
		else if (theTransaction.Contains("paymentInboxRecord"))	lBoxType = static_cast<long>(OTLedger::paymentInbox);
		else if (theTransaction.Contains("recordBoxRecord"))	lBoxType = static_cast<long>(OTLedger::recordBox);
		else
		{
			OTLog::sError("%s: Error loading from abbreviated transaction: unknown ledger type.\n", __FUNCTION__);
			return "";			
		}
		// --------------
		pTransaction = OTTransaction::LoadBoxReceipt(theTransaction, lBoxType);
		if (NULL == pTransaction)
		{
			OTLog::sError("%s: Error loading from abbreviated transaction: failed loading box receipt.\n", __FUNCTION__);
			return "";
		}
		// ----------------
		theTransAngel.SetCleanupTargetPointer(pTransaction);
	}
	else
		pTransaction = &theTransaction;
	// -----------------------------------------------------	
	OTIdentifier theOutput;

	bool bSuccess = pTransaction->GetSenderUserIDForDisplay(theOutput);
	// -----------------------------------------------------

	if (bSuccess)
	{
		OTString strOutput(theOutput);

		// Didn't find one.
		if (!strOutput.Exists())
			return "";

		// We found it -- let's return the user ID
		//
		return strOutput.Get(); 
	}
	else
		return "";
}

string OTAPI_Wrap::Transaction_GetSenderAcctID(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & ACCOUNT_ID,
	const string & THE_TRANSACTION
	)
{
	if (SERVER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }
	if (ACCOUNT_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCOUNT_ID"			); OT_ASSERT(false); }
	if (THE_TRANSACTION.empty())	{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_TRANSACTION"	); OT_ASSERT(false); }

	const OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theAccountID(ACCOUNT_ID);

	OTString strTransaction(THE_TRANSACTION);

	// -----------------------------------------------------
	OTPseudonym *  pNym(OTAPI_Wrap::OTAPI()->GetOrLoadPrivateNym(theUserID, __FUNCTION__)); // These copiously log, and ASSERT.
	if (NULL == pNym) return "";
	// -----------------------------------------------------

	OTTransaction theTransaction(theUserID, theAccountID, theServerID);

	if (false == theTransaction.LoadContractFromString(strTransaction))
	{
		OTString strAcctID(theAccountID);
		OTLog::sError("%s: Error loading transaction from string. Acct ID: %s\n", __FUNCTION__, strAcctID.Get());
		return "";
	}
	// -----------------------------------------------------
	OTTransaction * pTransaction = NULL;
	OTCleanup<OTTransaction> theTransAngel;

	if (theTransaction.IsAbbreviated())
	{
		long lBoxType = 0;

		if (theTransaction.Contains("nymboxRecord"))		lBoxType = static_cast<long>(OTLedger::nymbox);
		else if (theTransaction.Contains("inboxRecord"))        lBoxType = static_cast<long>(OTLedger::inbox);
		else if (theTransaction.Contains("outboxRecord"))       lBoxType = static_cast<long>(OTLedger::outbox);
		else if (theTransaction.Contains("paymentInboxRecord"))	lBoxType = static_cast<long>(OTLedger::paymentInbox);
		else if (theTransaction.Contains("recordBoxRecord"))	lBoxType = static_cast<long>(OTLedger::recordBox);		
		else
		{
			OTLog::sError("%s: Error loading from abbreviated transaction: unknown ledger type.\n", __FUNCTION__);
			return "";			
		}
		// --------------
		pTransaction = OTTransaction::LoadBoxReceipt(theTransaction, lBoxType);
		if (NULL == pTransaction)
		{
			OTLog::sError("%s: Error loading from abbreviated transaction: failed loading box receipt. \n", __FUNCTION__);
			return "";			
		}
		// ----------------
		theTransAngel.SetCleanupTargetPointer(pTransaction);
	}
	else
		pTransaction = &theTransaction;
	// -----------------------------------------------------	

	OTIdentifier theOutput;

	bool bSuccess = pTransaction->GetSenderAcctIDForDisplay(theOutput);

	// -----------------------------------------------------

	if (bSuccess)
	{
		OTString strOutput(theOutput);

		// Didn't find one.
		if (!strOutput.Exists())
			return "";

		// We found it -- let's return the user ID
		//
		return strOutput.Get(); 
	}
	else
		return "";
}

string OTAPI_Wrap::Transaction_GetRecipientUserID(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & ACCOUNT_ID,
	const string & THE_TRANSACTION
	)
{
	if (SERVER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }
	if (ACCOUNT_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCOUNT_ID"			); OT_ASSERT(false); }
	if (THE_TRANSACTION.empty())	{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_TRANSACTION"	); OT_ASSERT(false); }

	const OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theAccountID(ACCOUNT_ID);

	OTString strTransaction(THE_TRANSACTION);
	// -----------------------------------------------------

	OTPseudonym *  pNym(OTAPI_Wrap::OTAPI()->GetOrLoadPrivateNym(theUserID, __FUNCTION__)); // These copiously log, and ASSERT.
	if (NULL == pNym) return "";
	// By this point, pNym is a good pointer, and is on the wallet. (No need to cleanup.)
	// -----------------------------------------------------			
	OTTransaction theTransaction(theUserID, theAccountID, theServerID);

	if (false == theTransaction.LoadContractFromString(strTransaction))
	{
		OTString strAcctID(theAccountID);
		OTLog::sError("%s: Error loading transaction from string. Acct ID: %s\n", __FUNCTION__, strAcctID.Get());
		return "";
	}
	// -----------------------------------------------------
	OTTransaction * pTransaction = NULL;
	OTCleanup<OTTransaction> theTransAngel;

	if (theTransaction.IsAbbreviated())
	{
		long lBoxType = 0;

		if (theTransaction.Contains("nymboxRecord"))		lBoxType = static_cast<long>(OTLedger::nymbox);
		else if (theTransaction.Contains("inboxRecord"))        lBoxType = static_cast<long>(OTLedger::inbox);
		else if (theTransaction.Contains("outboxRecord"))       lBoxType = static_cast<long>(OTLedger::outbox);
		else if (theTransaction.Contains("paymentInboxRecord"))	lBoxType = static_cast<long>(OTLedger::paymentInbox);
		else if (theTransaction.Contains("recordBoxRecord"))	lBoxType = static_cast<long>(OTLedger::recordBox);		
		else
		{
			OTLog::sError("%s: Error loading from abbreviated transaction: unknown ledger type. \n", __FUNCTION__);
			return "";			
		}
		// --------------
		pTransaction = OTTransaction::LoadBoxReceipt(theTransaction, lBoxType);
		if (NULL == pTransaction)
		{
			OTLog::sError("%s: Error loading from abbreviated transaction: failed loading box receipt.", __FUNCTION__);
			return "";			
		}
		// ----------------
		theTransAngel.SetCleanupTargetPointer(pTransaction);
	}
	else
		pTransaction = &theTransaction;
	// -----------------------------------------------------	

	OTIdentifier theOutput;

	bool bSuccess = pTransaction->GetRecipientUserIDForDisplay(theOutput);

	// -----------------------------------------------------

	// Normally, there IS NO recipient user ID for a transfer (only a recipient acct ID.)
	// But here, as a special trick, I'll see if the account is in my address book.
	// THIS MEANS THE ADDRESS BOOK needs to store nyms (for other people, their public nym)
	// as well as a list of acct IDs that I have associated with each Nym. That way, I can
	// later look up the Nym ID based on the acct ID, and then look up my display label for
	// that Nym.
	//
	//	if (!bSuccess && (theTransaction.GetType() == OTTransaction::pending))
	//	{
	//		// AS SOON AS ADDRESS BOOK FEATURE IS ADDED, THEN THIS CAN BE COMPLETED HERE.
	//	}

	// -----------------------------------------------------

	if (bSuccess)
	{
		OTString strOutput(theOutput);

		// Didn't find one.
		if (!strOutput.Exists())
			return "";

		// We found it -- let's return the user ID
		//
		return strOutput.Get(); 
	}
	else
		return "";
}

string OTAPI_Wrap::Transaction_GetRecipientAcctID(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & ACCOUNT_ID,
	const string & THE_TRANSACTION
	)
{
	if (SERVER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }
	if (ACCOUNT_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCOUNT_ID"			); OT_ASSERT(false); }
	if (THE_TRANSACTION.empty())	{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_TRANSACTION"	); OT_ASSERT(false); }

	const OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theAccountID(ACCOUNT_ID);

	OTString strTransaction(THE_TRANSACTION);

	// -----------------------------------------------------
	OTPseudonym *  pNym(OTAPI_Wrap::OTAPI()->GetOrLoadPrivateNym(theUserID, __FUNCTION__)); // These copiously log, and ASSERT.
	if (NULL == pNym) return "";
	// -----------------------------------------------------

	OTTransaction theTransaction(theUserID, theAccountID, theServerID);

	if (false == theTransaction.LoadContractFromString(strTransaction))
	{
		OTString strAcctID(theAccountID);
		OTLog::sError("%s: Error loading transaction from string in OT_API_Transaction_GetRecipientAcctID. Acct ID: %s\n", __FUNCTION__, strAcctID.Get());
		return "";
	}

	// -----------------------------------------------------
	OTTransaction * pTransaction = NULL;
	OTCleanup<OTTransaction> theTransAngel;

	if (theTransaction.IsAbbreviated())
	{
		long lBoxType = 0;

		if (theTransaction.Contains("nymboxRecord"))		lBoxType = static_cast<long>(OTLedger::nymbox);
		else if (theTransaction.Contains("inboxRecord"))        lBoxType = static_cast<long>(OTLedger::inbox);
		else if (theTransaction.Contains("outboxRecord"))       lBoxType = static_cast<long>(OTLedger::outbox);
		else if (theTransaction.Contains("paymentInboxRecord"))	lBoxType = static_cast<long>(OTLedger::paymentInbox);
		else if (theTransaction.Contains("recordBoxRecord"))	lBoxType = static_cast<long>(OTLedger::recordBox);
		else
		{
			OTLog::sError("%s: Error loading from abbreviated transaction: unknown ledger type. \n", __FUNCTION__);
			return "";			
		}
		// --------------
		pTransaction = OTTransaction::LoadBoxReceipt(theTransaction, lBoxType);
		if (NULL == pTransaction)
		{
			OTLog::sError("%s: Error loading from abbreviated transaction: failed loading box receipt.\n", __FUNCTION__);
			return "";			
		}
		// ----------------
		theTransAngel.SetCleanupTargetPointer(pTransaction);
	}
	else
		pTransaction = &theTransaction;
	// -----------------------------------------------------	
	OTIdentifier theOutput;

	bool bSuccess = pTransaction->GetRecipientAcctIDForDisplay(theOutput);

	// -----------------------------------------------------

	if (bSuccess)
	{
		OTString strOutput(theOutput);

		// Didn't find one.
		if (!strOutput.Exists())
			return "";

		// We found it -- let's return the user ID
		//
		return strOutput.Get(); 

	}
	else
		return "";
}


// The pending notice in the inbox has a transaction number that
// was issued to the server(so it could put the notice in your inbox.)
// But it's IN REFERENCE TO a transfer that was initiated by another
// user. THIS function will retrieve THAT transaction number, because
// this function queries a pending transaction to see what transaction
// it is "in reference to."
//
int64_t OTAPI_Wrap::Transaction_GetDisplayReferenceToNum(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & ACCOUNT_ID,
	const string & THE_TRANSACTION
	)
{
	if (SERVER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }
	if (ACCOUNT_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCOUNT_ID"			); OT_ASSERT(false); }
	if (THE_TRANSACTION.empty())	{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_TRANSACTION"	); OT_ASSERT(false); }

	const OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theAccountID(ACCOUNT_ID);

	OTString strTransaction(THE_TRANSACTION);

	// -----------------------------------------------------
	OTPseudonym *  pNym(OTAPI_Wrap::OTAPI()->GetOrLoadPrivateNym(theUserID, __FUNCTION__)); // These copiously log, and ASSERT.
	if (NULL == pNym) return -1;
	// -----------------------------------------------------

	OTTransaction theTransaction(theUserID, theAccountID, theServerID);

	if (false == theTransaction.LoadContractFromString(strTransaction))
	{
		OTString strAcctID(theAccountID);
		OTLog::sError("%s: Error loading transaction from string. Acct ID: %s\n", __FUNCTION__, strAcctID.Get());
		return -1;
	}

	// -----------------------------------------------------
	// NO need to load abbreviated version here, since it already stores this number.
	//
	long lDisplayNumber = theTransaction.GetReferenceNumForDisplay();
	if (0 < lDisplayNumber) return lDisplayNumber;
	else return -1; //error
}





// ---------------------------------------------------------



/*
string LoadPurse( string SERVER_ID,
string ASSET_TYPE_ID,
string USER_ID); // returns NULL, or a purse. 
*/

// This should, if USER_ID is NULL, create a Nym to encrypt the tokens to, and just attach 
// it(the dummy nym) as a parameter on the purse, along with its ID.
// Otherwise use the User ID that's there.
//
// returns NULL, or a purse.
string OTAPI_Wrap::CreatePurse(
	const string & SERVER_ID,
	const string & ASSET_TYPE_ID,
	const string & USER_ID // UserID optional.
	)
{
	if (SERVER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (ASSET_TYPE_ID.empty())		{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "ASSET_TYPE_ID"		); OT_ASSERT(false); }

	//	if (NULL != USER_ID)
	//        OTLog::sError("DEBUG OT_API_CreatePurse: SERVER_ID: %s\n ASSET_TYPE_ID: %s\n USER_ID: %s\n ", SERVER_ID, ASSET_TYPE_ID, USER_ID);
	//	else
	//        OTLog::sError("DEBUG OT_API_CreatePurse with NULL USER_ID: SERVER_ID: %s\n ASSET_TYPE_ID: %s\n ", SERVER_ID, ASSET_TYPE_ID);

	const OTIdentifier theServerID(SERVER_ID), theAssetTypeID(ASSET_TYPE_ID);
	OTIdentifier theUserID;

	if (!USER_ID.empty())
		theUserID.SetString(USER_ID);
	else 
	{
		OTLog::sError("%s: ERROR: This is where we need to create a dummy Nym for the purse. Todo.", __FUNCTION__);
		// This is where we need to create a dummy Nym for the purse. Todo.
	}

	// -----------------------------------------------------
	OTPseudonym *  pNym(OTAPI_Wrap::OTAPI()->GetOrLoadPrivateNym(theUserID, __FUNCTION__)); // These copiously log, and ASSERT.
	if (NULL == pNym) return "";
	// By this point, pNym is a good pointer, and is on the wallet. (No need to cleanup.)
	// -----------------------------------------------------					

	OTPurse thePurse(theServerID, theAssetTypeID, theUserID);

	thePurse.SignContract(*pNym);  // todo when the dummy nym is done, HE will sign this. Pointer will have one or the other.
	thePurse.SaveContract();
	// -------------

	OTString strOutput(thePurse);

	return strOutput.Get();			
}

// Warning! This will overwrite whatever purse is there.
// The proper way to use this function is, LOAD the purse,
// then IMPORT whatever other purse you want int32_to it, then
// SAVE it again.
// returns OT_BOOL
bool OTAPI_Wrap::SavePurse(
	const string & SERVER_ID,
	const string & ASSET_TYPE_ID,
	const string & USER_ID,
	const string & THE_PURSE
	)
{
	if (SERVER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (ASSET_TYPE_ID.empty())		{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "ASSET_TYPE_ID"		); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }
	if (THE_PURSE.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_PURSE"			); OT_ASSERT(false); }

	//    OTLog::sError("DEBUG OT_API_SavePurse: SERVER_ID: %s\n ASSET_TYPE_ID: %s\n USER_ID: %s\n ", SERVER_ID, ASSET_TYPE_ID, USER_ID);

	const OTIdentifier theServerID(SERVER_ID), theAssetTypeID(ASSET_TYPE_ID), theUserID(USER_ID);

	const OTString strPurse(THE_PURSE);

	// -------------------------------------------------------------

	bool bSuccess = false;

	OTPurse thePurse(theServerID, theAssetTypeID, theUserID);

	if (strPurse.Exists() && thePurse.LoadContractFromString(strPurse))
	{
		if (OTAPI_Wrap::OTAPI()->SavePurse(theServerID, theAssetTypeID, theUserID, thePurse))
		{
			bSuccess = true;
		}
		else 
		{
			OTLog::sOutput(0, "%s: Failure saving purse:\n%s\n", __FUNCTION__, strPurse.Get());
		}
	}
	else 
	{
		OTLog::sOutput(0, "%s: Failure loading purse from string:\n%s\n", __FUNCTION__, strPurse.Get());
	}

	return bSuccess;
}

// --------------------------------------------------------------------
// Get Purse Total Value(const int32_ternally uses GetTotalValue().)
//
// Returns the purported sum of all the tokens within.
//
int64_t OTAPI_Wrap::Purse_GetTotalValue(
	const string & SERVER_ID,
	const string & ASSET_TYPE_ID,
	const string & THE_PURSE
	)
{
	if (SERVER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (ASSET_TYPE_ID.empty())		{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "ASSET_TYPE_ID"		); OT_ASSERT(false); }
	if (THE_PURSE.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_PURSE"			); OT_ASSERT(false); }

	const OTIdentifier theServerID(SERVER_ID), theAssetTypeID(ASSET_TYPE_ID);

	OTString strPurse(THE_PURSE);

	// -----------------------------------------------------

	OTPurse thePurse(theServerID, theAssetTypeID);

	if (false == thePurse.LoadContractFromString(strPurse))
	{
		OTString strAssetTypeID(theAssetTypeID);
		OTLog::sError("%s: Error loading purse from string. Asset Type ID: %s\n", __FUNCTION__, strAssetTypeID.Get());
		return -1;
	}

	// -----------------------------------------------------

	long lTotalValue = thePurse.GetTotalValue();

	if (0 < lTotalValue) return lTotalValue;
	else return -1; //error;

}

// ---

int32_t OTAPI_Wrap::Purse_Count(
	const string & SERVER_ID,
	const string & ASSET_TYPE_ID,
	const string & THE_PURSE
	)
{
	if (SERVER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (ASSET_TYPE_ID.empty())		{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "ASSET_TYPE_ID"		); OT_ASSERT(false); }
	if (THE_PURSE.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_PURSE"			); OT_ASSERT(false); }

	const OTIdentifier theServerID(SERVER_ID), theAssetTypeID(ASSET_TYPE_ID);

	const OTString strPurse(THE_PURSE);

	// -------------------------------------------------------------

	OTPurse thePurse(theServerID, theAssetTypeID);

	if (strPurse.Exists() && thePurse.LoadContractFromString(strPurse)) 
	{
		return thePurse.Count();
	}

	return -1;
}

// Returns the TOKEN on top of the stock(LEAVING it on top of the stack,
// but giving you a string copy of it.)
// returns NULL if failure.
//
string OTAPI_Wrap::Purse_Peek(
	const string & SERVER_ID,
	const string & ASSET_TYPE_ID,
	const string & USER_ID,
	const string & THE_PURSE
	)
{
	OTString strOutput; // for later.

	if (SERVER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (ASSET_TYPE_ID.empty())		{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "ASSET_TYPE_ID"		); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }
	if (THE_PURSE.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_PURSE"			); OT_ASSERT(false); }

	const OTIdentifier theServerID(SERVER_ID), theAssetTypeID(ASSET_TYPE_ID), theUserID(USER_ID);

	const OTString strPurse(THE_PURSE);

	// -----------------------------------------------------
	OTPseudonym *  pNym(OTAPI_Wrap::OTAPI()->GetOrLoadPrivateNym(theUserID, __FUNCTION__)); // These copiously log, and ASSERT.
	if (NULL == pNym) return "";
	// By this point, pNym is a good pointer, and is on the wallet. (No need to cleanup.)
	// -----------------------------------------------------						
	OTPurse thePurse(theServerID, theAssetTypeID, theUserID);

	if (strPurse.Exists() && thePurse.LoadContractFromString(strPurse))
	{
		if (!thePurse.IsEmpty())
		{
			OTToken * pToken = thePurse.Pop(*pNym);
			OTCleanup<OTToken> theTokenAngel(pToken);

			if (NULL != pToken)
			{
				pToken->SaveContractRaw(strOutput);				
			}
			else 
			{
				OTLog::sOutput(0, "%s: Failed popping a token from a stack that wasn't supposed to be empty...\n", __FUNCTION__);
				return "";
			}
		}
		else
		{
			OTLog::sOutput(0, "%s: Failed attempt to peek; purse is empty.\n", __FUNCTION__);
			return "";
		}
	}
	else 
	{
		OTLog::sOutput(0, "%s: Failure loading purse from string:\n%s\n", __FUNCTION__, strPurse.Get());
		return "";
	}

	return strOutput.Get(); 
}

// Removes the token from the top of the stock and DESTROYS IT,
// and RETURNS THE UPDATED PURSE(with the token now missing from it.)
// WARNING: Do not call this function unless you have PEEK()d FIRST!!
// Otherwise you will lose the token and get left "holding the bag".
// returns NULL if failure.
string OTAPI_Wrap::Purse_Pop(
	const string & SERVER_ID,
	const string & ASSET_TYPE_ID,
	const string & USER_ID,
	const string & THE_PURSE
	)
{
	OTString strOutput; // for later.

	if (SERVER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (ASSET_TYPE_ID.empty())		{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "ASSET_TYPE_ID"		); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }
	if (THE_PURSE.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_PURSE"			); OT_ASSERT(false); }

	//    OTLog::sError("DEBUG OT_API_Purse_Pop: SERVER_ID: %s\n ASSET_TYPE_ID: %s\n USER_ID: %s\n ", SERVER_ID, ASSET_TYPE_ID, USER_ID);

	const OTIdentifier theServerID(SERVER_ID), theAssetTypeID(ASSET_TYPE_ID), theUserID(USER_ID);

	const OTString strPurse(THE_PURSE);

	// -----------------------------------------------------
	OTPseudonym *  pNym(OTAPI_Wrap::OTAPI()->GetOrLoadPrivateNym(theUserID, __FUNCTION__)); // These copiously log, and ASSERT.
	if (NULL == pNym) return "";
	// By this point, pNym is a good pointer, and is on the wallet. (No need to cleanup.)
	// -----------------------------------------------------						
	OTPurse thePurse(theServerID, theAssetTypeID, theUserID);

	if (strPurse.Exists() && thePurse.LoadContractFromString(strPurse))
	{
		if (!thePurse.IsEmpty())
		{
			OTToken * pToken = thePurse.Pop(*pNym);
			OTCleanup<OTToken> theTokenAngel(pToken);

			if (NULL != pToken)
			{
				thePurse.ReleaseSignatures();
				thePurse.SignContract(*pNym);
				thePurse.SaveContract();
				thePurse.SaveContractRaw(strOutput);
			}
			else 
			{
				OTLog::sOutput(0, "%s: Failed popping a token from a stack that wasn't supposed to be empty...\n", __FUNCTION__);
				return "";
			}
		}
		else
		{
			OTLog::sOutput(0, "%s: Failed attempt to peek; purse is empty.\n", __FUNCTION__);
			return "";
		}
	}
	else 
	{
		OTLog::sOutput(0, "%s: Failure loading purse from string:\n%s\n", __FUNCTION__, strPurse.Get());
		return "";
	}

	return strOutput.Get(); 	
}

// Pushes a token onto the stack(of the purse.)
// Returns the updated purse(now including the token.)
// Returns NULL if failure.
string OTAPI_Wrap::Purse_Push(
	const string & SERVER_ID,
	const string & ASSET_TYPE_ID,
	const string & USER_ID,
	const string & THE_PURSE,
	const string & THE_TOKEN
	)
{
	OTString strOutput; // for later.

	if (SERVER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (ASSET_TYPE_ID.empty())		{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "ASSET_TYPE_ID"		); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }
	if (THE_PURSE.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_PURSE"			); OT_ASSERT(false); }
	if (THE_TOKEN.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_TOKEN"			); OT_ASSERT(false); }

	//    OTLog::sError("DEBUG OT_API_Purse_Push: SERVER_ID: %s\n ASSET_TYPE_ID: %s\n USER_ID: %s\n ", SERVER_ID, ASSET_TYPE_ID, USER_ID);

	//	OTLog::sError("Purse Push SERVER_ID: %s \n", SERVER_ID);
	//	OTLog::sError("Purse Push ASSET_TYPE_ID: %s \n", ASSET_TYPE_ID);
	//	OTLog::sError("Purse Push USER_ID: %s \n", USER_ID); 
	//	OTLog::sError("Purse Push THE_PURSE: %s \n", THE_PURSE); 
	//	OTLog::sError("Purse Push THE_TOKEN: %s \n", THE_TOKEN); 	

	const OTIdentifier theServerID(SERVER_ID), theAssetTypeID(ASSET_TYPE_ID), theUserID(USER_ID);

	const OTString strPurse(THE_PURSE), strToken(THE_TOKEN);

	// -----------------------------------------------------
	OTPseudonym *  pNym(OTAPI_Wrap::OTAPI()->GetOrLoadPrivateNym(theUserID, __FUNCTION__)); // These copiously log, and ASSERT.
	if (NULL == pNym) return "";
	// -----------------------------------------------------

	if (!strPurse.Exists())
	{
		OTLog::sOutput(0, "%s: Purse does not exist.\n", __FUNCTION__);
		return "";
	}
	else if (!strToken.Exists())
	{
		OTLog::sOutput(0, "%s: Token does not exist.\n", __FUNCTION__);
		return "";
	}

	// ---------------------------

	OTPurse thePurse(theServerID, theAssetTypeID, theUserID);
	OTToken theToken(theServerID, theAssetTypeID);

	if (thePurse.LoadContractFromString(strPurse) && 
		theToken.LoadContractFromString(strToken))
	{		
		if (thePurse.Push(*pNym, theToken)) // purse makes its own copy of token. 
		{
			thePurse.ReleaseSignatures();
			thePurse.SignContract(*pNym);
			thePurse.SaveContract();
			thePurse.SaveContractRaw(strOutput);
		}
		else 
		{
			OTLog::sOutput(0, "%s: Failed pushing a token to a purse...\n", __FUNCTION__);
			return "";
		}
	}
	else 
	{
		OTLog::sOutput(0, "%s: Failure loading purse or token from string:\n%s\n%s\n", __FUNCTION__, strPurse.Get(), strToken.Get());
		return "";
	}

	return strOutput.Get(); 
}


// ------------------


// Should handle duplicates. Should load, merge, and save.
// It should either have your User ID on it, or the key should be inside so you can import.
bool OTAPI_Wrap::Wallet_ImportPurse(
	const string & SERVER_ID,
	const string & ASSET_TYPE_ID,
	const string & USER_ID, // you pass in the purse you're trying to import
	const string & THE_PURSE
	)
{
	if (SERVER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (ASSET_TYPE_ID.empty())		{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "ASSET_TYPE_ID"		); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }
	if (THE_PURSE.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_PURSE"			); OT_ASSERT(false); }

	//    OTLog::sError("DEBUG OT_API_Wallet_ImportPurse: SERVER_ID: %s\n ASSET_TYPE_ID: %s\n USER_ID: %s\n ", SERVER_ID, ASSET_TYPE_ID, USER_ID);

	//	OTLog::sError("Debug start\nServerID: %s\nAsset ID: %s\n User ID: %s\nNew Purse:\n%s\n",
	//				  SERVER_ID, ASSET_TYPE_ID, USER_ID, THE_PURSE);

	const OTIdentifier theServerID(SERVER_ID), theAssetTypeID(ASSET_TYPE_ID), theUserID(USER_ID);

	const OTString strNewPurse(THE_PURSE);

	// -----------------------------------------------------
	OTPseudonym *  pNym(OTAPI_Wrap::OTAPI()->GetOrLoadPrivateNym(theUserID, __FUNCTION__)); // These copiously log, and ASSERT.
	if (NULL == pNym) return false;
	// By this point, pNym is a good pointer, and is on the wallet. (No need to cleanup.)
	// -----------------------------------------------------						
	OTPurse * pOldPurse = OTAPI_Wrap::OTAPI()->LoadPurse(theServerID, theAssetTypeID, theUserID);
	OTCleanup<OTPurse> thePurseAngel(pOldPurse);

	if (NULL == pOldPurse) // apparently there's not already a purse of this type, let's create it.
	{
		pOldPurse = new OTPurse(theServerID, theAssetTypeID, theUserID);
		OT_ASSERT(NULL != pOldPurse);
		// ---------------------------------------
		thePurseAngel.SetCleanupTarget(*pOldPurse);
	}
	// By this point, the old purse has either been loaded, or created.
	// --------------------------------------------------------------

	OTPurse theNewPurse(theServerID);
	//	OTPurse theNewPurse(theServerID, theAssetTypeID, theUserID); // This purse might have a dummy nym inside it, so I can't assume it's for my User ID.

	OTPseudonym *  pNewNym = NULL;

	if (strNewPurse.Exists() && theNewPurse.LoadContractFromString(strNewPurse))
	{
		if (pOldPurse->GetServerID() != theNewPurse.GetServerID())
		{
			OTLog::sOutput(0, "%s: Failure: ServerIDs don't match between these two purses.\n", __FUNCTION__);
		}
		// -----------------------------------------------------------
		else if (pOldPurse->GetAssetID() != theNewPurse.GetAssetID())
		{
			OTLog::sOutput(0, "%s: Failure: AssetIDs don't match between these two purses.\n", __FUNCTION__);
		}
		// -----------------------------------------------------------
		else    // Let's make sure we have the right Nym for theNewPurse...
		{
			if (theNewPurse.IsUsingATempNym())
			{
				pNewNym = (theNewPurse.GetInternalNym());
				if (NULL == pNewNym)
					OTLog::sError("%s: theNewPurse is supposedly using a Temp Nym, but GetInternalNym returns NULL!\n", __FUNCTION__);
			}
			// ---------------------------------------------
			// There's no temp nym inside the new purse.
			// Okay, let's see if we can find the Nym based on its ID. (If there even IS an ID...)
			//
			if (NULL == pNewNym)
			{
				OTIdentifier theOtherNymID;

				const bool bGotOtherNymID = theNewPurse.GetNymID(theOtherNymID);

				if (!bGotOtherNymID)
				{
					OTLog::sError("%s: WARNING: Unable to discern the NymID for theNewPurse. "
						"Therefore, I'm going with the same NymID as the Old Purse. (If that's not right, then probably "
						"something you are trying to do will fail soon.)\n", __FUNCTION__);
					pNewNym = pNym; // <==============
				}
				else // bGotOtherNymID is true (it returned an ID...)
				{
					if (pNym->CompareID(theOtherNymID)) // It's the same Nym!
					{
						pNewNym = pNym; // <==============
					}
					else // We definitely have 2 different NymIDs. So let's lookup the second one...
					{
						pNewNym = (OTAPI_Wrap::OTAPI()->GetOrLoadPrivateNym(theOtherNymID, __FUNCTION__)); // These copiously log, and ASSERT.

						// We DEFINITELY had a NymID, but when we tried to LOAD the Nym from the wallet
						// based on that ID, it returned NULL!
						//
						if (NULL == pNewNym)
						{
							OTLog::sError("%s: ERROR: theNewPurse has a different NymID, and I can't find that nym in my wallet!\n", __FUNCTION__);
							return false; // Failure.
						}
						// else pNewNym is set and loaded by this point!
					}
				}
			}
			// ---------------------------------------------
			if (NULL == pNewNym) // STILL?? I don't even know if we can make it down this far and have it still be NULL, honestly.
			{
				OTLog::sError("%s: ERROR: Unable to find owner Nym for theNewPurse. (Need both Nyms to do the merge.)\n", __FUNCTION__);
				return false; // Failure.
			}
			// ****************************************************************
			//
			// By this point, I have TWO NYMS!!!!!! (Finally.)
			//
			if (pOldPurse->Merge(*pNym, *pNewNym, theNewPurse)) 
			{
				pOldPurse->ReleaseSignatures();
				pOldPurse->SignContract(*pNym);
				pOldPurse->SaveContract();
				// -------------------------------------------------
				bool bSaved = OTAPI_Wrap::OTAPI()->SavePurse(theServerID, theAssetTypeID, theUserID, *pOldPurse);
				return bSaved;
			}
			else // Failed merge.
			{
				OTString strNymID1, strNymID2;
				pNym->   GetIdentifier(strNymID1);
				pNewNym->GetIdentifier(strNymID2);
				OTLog::sOutput(0, "%s: (OldNymID: %s.) (NewNymID: %s.) Failure merging purse:\n\n%s\n\n", __FUNCTION__, strNymID1.Get(), strNymID2.Get(), strNewPurse.Get());
			}
		}
		// -----------------------------------------------------------
	}
	else 
	{
		OTLog::sOutput(0, "%s: Failure loading the other purse from string:\n\n%s\n\n", __FUNCTION__, strNewPurse.Get());
	}

	return false;
}

// Messages the server. If failure, make sure you didn't lose that purse!!
// If success, the new tokens will be returned shortly and saved int32_to the appropriate purse.
// Note that an asset account isn't necessary to do this... just a nym operating cash-only.
// The same as exchanging a 20-dollar bill at the teller window for a replacement bill.
//
// Returns int32_t:
// -1 means error; no message was sent.
// -2 means the message was sent, but the request number must be passed as a string, so call GetLargeRequestNum.
// 0 means NO error, but also: no message was sent.
// >0 means NO error, and the message was sent, and the request number fits int32_to an int32_teger...
// ...and in fact the requestNum IS the return value!
// ===> In 99% of cases, this LAST option is what actually happens!!
//
int32_t OTAPI_Wrap::exchangePurse(
	const string & SERVER_ID,
	const string & ASSET_TYPE_ID,
	const string & USER_ID,
	const string & THE_PURSE
	)
{
	if (SERVER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (ASSET_TYPE_ID.empty())		{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "ASSET_TYPE_ID"		); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }
	if (THE_PURSE.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_PURSE"			); OT_ASSERT(false); }

	// todo:  exchange message.
	OTLog::sError("%s: TODO (NOT CODED) OT_API_exchangePurse: SERVER_ID: %s\n ASSET_TYPE_ID: %s\n USER_ID: %s\n ", __FUNCTION__, SERVER_ID, ASSET_TYPE_ID, USER_ID);

	return -1;
}

// --------------

// Tokens are stored in an encrypted state for security reasons.
// This function is used for exporting those tokens to another Nym,
// such as a Dummy nym, or another user's Nym.
//
string OTAPI_Wrap::Token_ChangeOwner(
	const string & SERVER_ID,
	const string & ASSET_TYPE_ID,
	const string & THE_TOKEN,
	const string & OLD_OWNER_NYM_ID,
	const string & NEW_OWNER_NYM_ID
	)
{
	if (SERVER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (ASSET_TYPE_ID.empty())		{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "ASSET_TYPE_ID"		); OT_ASSERT(false); }
	if (THE_TOKEN.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_TOKEN"			); OT_ASSERT(false); }
	if (OLD_OWNER_NYM_ID.empty())	{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "OLD_OWNER_NYM_ID"	); OT_ASSERT(false); }
	if (NEW_OWNER_NYM_ID.empty())	{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "NEW_OWNER_NYM_ID"	); OT_ASSERT(false); }

	//    OTLog::sError("Debugging OT_API_Token_ChangeOwner: SERVER_ID: %s\n ASSET_TYPE_ID: %s\n OLD_OWNER_NYM_ID: %s\n NEW_OWNER_NYM_ID: %s\n ", 
	//                  SERVER_ID, ASSET_TYPE_ID, OLD_OWNER_NYM_ID, NEW_OWNER_NYM_ID);

	const OTIdentifier	theServerID(SERVER_ID), theAssetTypeID(ASSET_TYPE_ID),
		oldOwnerID(OLD_OWNER_NYM_ID), newOwnerID(NEW_OWNER_NYM_ID);
	// -----------------------------------------------------

	// -----------------------------------------------------
	OTPseudonym * 			pOldNym(OTAPI_Wrap::OTAPI()->GetOrLoadPrivateNym(oldOwnerID, __FUNCTION__)); // These copiously log, and ASSERT.
	if (NULL == pOldNym)	return "";
	// -----------------------------------------------------						
	// I try to load the private Nym first in case that's what it really is --
	// might as well have it that way correctly in the wallet.
	// Failing that, I try to load the public nym. If I'm exporting some
	// cash to someone, I at LEAST need his public key. (And after that, can't re-import...)
	// Failing that, we have to return NULL. Sorry, we tried.
	// -----------------------------------------------------
	OTPseudonym * 			pNewNym(OTAPI_Wrap::OTAPI()->GetOrLoadPrivateNym(newOwnerID, __FUNCTION__)); // These copiously log, and ASSERT.
	if (NULL == pNewNym)	pNewNym = (OTAPI_Wrap::OTAPI()->GetOrLoadPublicNym(newOwnerID, __FUNCTION__));
	if (NULL == pNewNym)	return "";
	// -----------------------------------------------------						

	OTToken theToken(theServerID, theAssetTypeID);

	OTString strOutput, strToken(THE_TOKEN);	

	if (strToken.Exists() && theToken.LoadContractFromString(strToken))
	{
		if (false == theToken.ReassignOwnership(*pOldNym, *pNewNym))
		{
			OTLog::sError("%s: Error re-assigning ownership of token.\n", __FUNCTION__);
		}
		else 
		{
			OTLog::sOutput(3, "%s: Success re-assigning ownership of token.\n", __FUNCTION__);

			theToken.ReleaseSignatures();
			theToken.SignContract(*pNewNym);
			theToken.SaveContract();

			theToken.SaveContractRaw(strOutput);
		}
	}

	return strOutput.Get(); 	
}

// Returns an encrypted form of the actual blinded token ID.
//(There's no need to decrypt the ID until redeeming the token, when
// you re-encrypt it to the server's public key, or until spending it,
// when you re-encrypt it to the recipient's public key, or exporting
// it, when you create a dummy recipient and attach it to the purse.)
//
string OTAPI_Wrap::Token_GetID(
	const string & SERVER_ID,
	const string & ASSET_TYPE_ID,
	const string & THE_TOKEN
	)
{
	if (SERVER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (ASSET_TYPE_ID.empty())		{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "ASSET_TYPE_ID"		); OT_ASSERT(false); }
	if (THE_TOKEN.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_TOKEN"			); OT_ASSERT(false); }

	const OTIdentifier theServerID(SERVER_ID), theAssetTypeID(ASSET_TYPE_ID);

	OTToken theToken(theServerID, theAssetTypeID);

	OTString strOutput("0"), strToken(THE_TOKEN);	

	if (strToken.Exists() && theToken.LoadContractFromString(strToken))
	{
		const OTASCIIArmor & ascSpendable = theToken.GetSpendable(); // encrypted version of Token ID, used as an "ID" on client side.

		strOutput.Format("%s", ascSpendable.Get());
	}

	return strOutput.Get(); 	
}

// The actual cash value of the token. Returns a long int32_t as a string.
//
int64_t OTAPI_Wrap::Token_GetDenomination(
	const string & SERVER_ID,
	const string & ASSET_TYPE_ID,
	const string & THE_TOKEN
	)
{
	if (SERVER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (ASSET_TYPE_ID.empty())		{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "ASSET_TYPE_ID"		); OT_ASSERT(false); }
	if (THE_TOKEN.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_TOKEN"			); OT_ASSERT(false); }

	const OTIdentifier theServerID(SERVER_ID), theAssetTypeID(ASSET_TYPE_ID);

	OTToken theToken(theServerID, theAssetTypeID);

	OTString strOutput("0"), strToken(THE_TOKEN);	

	if (strToken.Exists() && theToken.LoadContractFromString(strToken))
	{
		return theToken.GetDenomination();

	}

	return -1; //error
}

int32_t OTAPI_Wrap::Token_GetSeries(
	const string & SERVER_ID,
	const string & ASSET_TYPE_ID,
	const string & THE_TOKEN
	)
{
	if (SERVER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (ASSET_TYPE_ID.empty())		{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "ASSET_TYPE_ID"		); OT_ASSERT(false); }
	if (THE_TOKEN.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_TOKEN"			); OT_ASSERT(false); }

	const OTIdentifier theServerID(SERVER_ID), theAssetTypeID(ASSET_TYPE_ID);

	OTToken theToken(theServerID, theAssetTypeID);

	OTString strOutput, strToken(THE_TOKEN);	

	if (strToken.Exists() && theToken.LoadContractFromString(strToken))
		return theToken.GetSeries();

	return -1;		
}

// the date is seconds since Jan 1970, but returned as a string.
//
time_t OTAPI_Wrap::Token_GetValidFrom(
	const string & SERVER_ID,
	const string & ASSET_TYPE_ID,
	const string & THE_TOKEN
	)
{
	if (SERVER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (ASSET_TYPE_ID.empty())		{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "ASSET_TYPE_ID"		); OT_ASSERT(false); }
	if (THE_TOKEN.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_TOKEN"			); OT_ASSERT(false); }

	const OTIdentifier theServerID(SERVER_ID), theAssetTypeID(ASSET_TYPE_ID);

	OTToken theToken(theServerID, theAssetTypeID);

	OTString strToken(THE_TOKEN);	

	if (strToken.Exists() && theToken.LoadContractFromString(strToken))
	{
		return theToken.GetValidFrom();
	}

	return -1; //error	
}

// the date is seconds since Jan 1970, but returned as a string.
//
time_t OTAPI_Wrap::Token_GetValidTo(
	const string & SERVER_ID,
	const string & ASSET_TYPE_ID,
	const string & THE_TOKEN
	)
{
	if (SERVER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (ASSET_TYPE_ID.empty())		{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "ASSET_TYPE_ID"		); OT_ASSERT(false); }
	if (THE_TOKEN.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_TOKEN"			); OT_ASSERT(false); }

	const OTIdentifier theServerID(SERVER_ID), theAssetTypeID(ASSET_TYPE_ID);

	OTToken theToken(theServerID, theAssetTypeID);

	OTString strOutput, strToken(THE_TOKEN);	

	if (strToken.Exists() && theToken.LoadContractFromString(strToken))
	{
		return theToken.GetValidTo();
	}

	return -1; //error	
}


// ---------

string OTAPI_Wrap::Token_GetAssetID(const string & THE_TOKEN)
{
	if (THE_TOKEN.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_TOKEN"			); OT_ASSERT(false); }

	OTToken theToken;
	OTString strToken(THE_TOKEN), strOutput;	

	if (strToken.Exists() && theToken.LoadContractFromString(strToken))
	{
		const OTIdentifier & theID = theToken.GetAssetID();
		theID.GetString(strOutput);
	}

	return strOutput.Get(); 

}

string OTAPI_Wrap::Token_GetServerID(const string & THE_TOKEN)
{
	if (THE_TOKEN.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_TOKEN"			); OT_ASSERT(false); }

	OTToken theToken;
	OTString strToken(THE_TOKEN), strOutput;	

	if (strToken.Exists() && theToken.LoadContractFromString(strToken))
	{
		const OTIdentifier & theID = theToken.GetServerID();
		theID.GetString(strOutput);
	}

	return strOutput.Get();
}



// --------------------------------------------------------------------



//
//
// THESE FUNCTIONS were added for the PAYMENTS screen.(They are fairly new.)
//
// Basically there was a need to have DIFFERENT instruments, but to be able to
// treat them as though they are a single type.
//
// In keeping with that, the below functions will work with disparate types.
// You can pass [ CHEQUES / VOUCHERS / INVOICES ] and PAYMENT PLANS, and
// SMART CONTRACTS, and PURSEs int32_to these functions, and they should be able
// to handle any of those types.
//
//

int64_t OTAPI_Wrap::Instrument_GetAmount(
	const string & SERVER_ID,
	const string & THE_INSTRUMENT
	)
{
	if (SERVER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (THE_INSTRUMENT.empty())		{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_INSTRUMENT"		); OT_ASSERT(false); }

	// ------------------------------------
	const OTIdentifier  theServerID(SERVER_ID);
	const OTString      strInstrument(THE_INSTRUMENT);
	// ------------------------------------
	OTPayment thePayment(strInstrument);

	if (!thePayment.IsValid())
	{
		OTLog::sOutput(0, "%s: Unable to parse instrument:\n\n%s\n\n",
			__FUNCTION__, strInstrument.Get());
		return 0;
	}
	// ---------------------------------------
	bool bSetValues = false;

	if (thePayment.IsPurse())
		bSetValues = thePayment.SetTempValuesPurse(theServerID);
	else
		bSetValues = thePayment.SetTempValues();
	// ---------------------------------------
	if (!bSetValues)
	{
		OTLog::sOutput(0, "%s: Unable to load instrument:\n\n%s\n\n",
			__FUNCTION__, strInstrument.Get());
		return -1;
	}
	// ---------------------------------------

	// BY THIS POINT, we have definitely loaded up all the values of the instrument
	// into the OTPayment object. (Meaning we can now return the requested data...)

	OTString    strOutput;
	long        lOutput = 0;
	const bool  bGotData = thePayment.GetAmount(lOutput); // <========

	if (bGotData)
	{
		return lOutput;
	}

	return -1;
}

int64_t OTAPI_Wrap::Instrument_GetTransNum(
	const string & SERVER_ID,
	const string & THE_INSTRUMENT
	)
{
	if (SERVER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (THE_INSTRUMENT.empty())		{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_INSTRUMENT"		); OT_ASSERT(false); }

	// ------------------------------------
	const OTIdentifier  theServerID(SERVER_ID);
	const OTString      strInstrument(THE_INSTRUMENT);
	// ------------------------------------
	OTPayment thePayment(strInstrument);

	if (!thePayment.IsValid())
	{
		OTLog::sOutput(0, "%s: Unable to parse instrument:\n\n%s\n\n",
			__FUNCTION__, strInstrument.Get());
		return -1;
	}
	// ---------------------------------------
	bool bSetValues = false;

	if (thePayment.IsPurse())
		bSetValues = thePayment.SetTempValuesPurse(theServerID);
	else
		bSetValues = thePayment.SetTempValues();
	// ---------------------------------------
	if (!bSetValues)
	{
		OTLog::sOutput(0, "%s: Unable to load instrument:\n\n%s\n\n",
			__FUNCTION__, strInstrument.Get());
		return -1;
	}
	// ---------------------------------------

	// BY THIS POINT, we have definitely loaded up all the values of the instrument
	// into the OTPayment object. (Meaning we can now return the requested data...)

	OTString    strOutput;
	long        lOutput = 0;
	const bool  bGotData = thePayment.GetTransactionNum(lOutput); // <========

	if (bGotData)
	{
		return lOutput;
	}

	return -1;
}

time_t OTAPI_Wrap::Instrument_GetValidFrom(
	const string & SERVER_ID,
	const string & THE_INSTRUMENT
	)
{
	if (SERVER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (THE_INSTRUMENT.empty())		{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_INSTRUMENT"		); OT_ASSERT(false); }

	// ------------------------------------
	const OTIdentifier  theServerID(SERVER_ID);
	const OTString      strInstrument(THE_INSTRUMENT);
	// ------------------------------------
	OTPayment thePayment(strInstrument);

	if (!thePayment.IsValid())
	{
		OTLog::sOutput(0, "%s: Unable to parse instrument:\n\n%s\n\n",
			__FUNCTION__, strInstrument.Get());
		return -1;
	}
	// ---------------------------------------
	bool bSetValues = false;

	if (thePayment.IsPurse())
		bSetValues = thePayment.SetTempValuesPurse(theServerID);
	else
		bSetValues = thePayment.SetTempValues();
	// ---------------------------------------
	if (!bSetValues)
	{
		OTLog::sOutput(0, "%s: Unable to load instrument:\n\n%s\n\n",
			__FUNCTION__, strInstrument.Get());
		return -1;
	}
	// ---------------------------------------

	// BY THIS POINT, we have definitely loaded up all the values of the instrument
	// into the OTPayment object. (Meaning we can now return the requested data...)

	OTString    strOutput;
	//long        lOutput = 0;
	time_t      tOutput = 0;
	const bool  bGotData = thePayment.GetValidFrom(tOutput); // <========

	if (bGotData)
	{
		return tOutput;
	}

	return -1;
}

time_t OTAPI_Wrap::Instrument_GetValidTo(
	const string & SERVER_ID,
	const string & THE_INSTRUMENT
	)
{
	if (SERVER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (THE_INSTRUMENT.empty())		{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_INSTRUMENT"		); OT_ASSERT(false); }

	// ------------------------------------
	const OTIdentifier  theServerID(SERVER_ID);
	const OTString      strInstrument(THE_INSTRUMENT);
	// ------------------------------------
	OTPayment thePayment(strInstrument);

	if (!thePayment.IsValid())
	{
		OTLog::sOutput(0, "%s: Unable to parse instrument:\n\n%s\n\n",
			__FUNCTION__, strInstrument.Get());
		return -1;
	}
	// ---------------------------------------
	bool bSetValues = false;

	if (thePayment.IsPurse())
		bSetValues = thePayment.SetTempValuesPurse(theServerID);
	else
		bSetValues = thePayment.SetTempValues();
	// ---------------------------------------
	if (!bSetValues)
	{
		OTLog::sOutput(0, "%s: Unable to load instrument:\n\n%s\n\n",
			__FUNCTION__, strInstrument.Get());
		return -1;
	}
	// ---------------------------------------

	// BY THIS POINT, we have definitely loaded up all the values of the instrument
	// into the OTPayment object. (Meaning we can now return the requested data...)

	OTString    strOutput;
	//long        lOutput = 0;
	time_t      tOutput = 0;
	const bool  bGotData = thePayment.GetValidTo(tOutput); // <========

	if (bGotData)
	{
		return tOutput;
	}

	return -1;
}

string OTAPI_Wrap::Instrument_GetMemo(
	const string & SERVER_ID,
	const string & THE_INSTRUMENT
	)
{
	if (SERVER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (THE_INSTRUMENT.empty())		{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_INSTRUMENT"		); OT_ASSERT(false); }

	// ------------------------------------
	const OTIdentifier  theServerID(SERVER_ID);
	const OTString      strInstrument(THE_INSTRUMENT);
	// ------------------------------------
	OTPayment thePayment(strInstrument);

	if (!thePayment.IsValid())
	{
		OTLog::sOutput(0, "%s: Unable to parse instrument:\n\n%s\n\n",
			__FUNCTION__, strInstrument.Get());
		return "";
	}
	// ---------------------------------------
	bool bSetValues = false;

	if (thePayment.IsPurse())
		bSetValues = thePayment.SetTempValuesPurse(theServerID);
	else
		bSetValues = thePayment.SetTempValues();
	// ---------------------------------------
	if (!bSetValues)
	{
		OTLog::sOutput(0, "%s: Unable to load instrument:\n\n%s\n\n",
			__FUNCTION__, strInstrument.Get());
		return "";
	}
	// ---------------------------------------

	// BY THIS POINT, we have definitely loaded up all the values of the instrument
	// into the OTPayment object. (Meaning we can now return the requested data...)

	OTString    strOutput;
	const bool  bGotData = thePayment.GetMemo(strOutput); // <========

	if (bGotData)
	{
		return strOutput.Get();
	}

	return "";
}

string OTAPI_Wrap::Instrument_GetType(
	const string & SERVER_ID,
	const string & THE_INSTRUMENT
	)
{
	if (SERVER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (THE_INSTRUMENT.empty())		{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_INSTRUMENT"		); OT_ASSERT(false); }

	// ------------------------------------
	const OTIdentifier  theServerID(SERVER_ID);
	const OTString      strInstrument(THE_INSTRUMENT);
	// ------------------------------------
	OTPayment thePayment(strInstrument);

	if (!thePayment.IsValid())
	{
		OTLog::sOutput(0, "%s: Unable to parse instrument:\n\n%s\n\n",
			__FUNCTION__, strInstrument.Get());
		return "";
	}
	// ---------------------------------------
	bool bSetValues = false;

	if (thePayment.IsPurse())
		bSetValues = thePayment.SetTempValuesPurse(theServerID);
	else
		bSetValues = thePayment.SetTempValues();
	// ---------------------------------------
	if (!bSetValues)
	{
		OTLog::sOutput(0, "%s: Unable to load instrument:\n\n%s\n\n",
			__FUNCTION__, strInstrument.Get());
		return "";
	}
	// ---------------------------------------

	// BY THIS POINT, we have definitely loaded up all the values of the instrument
	// into the OTPayment object. (Meaning we can now return the requested data...)

	const OTString strOutput(thePayment.GetTypeString());

	if (strOutput.Exists())
	{
		return strOutput.Get();
	}

	return "";
}


string OTAPI_Wrap::Instrument_GetAssetID(
	const string & SERVER_ID,
	const string & THE_INSTRUMENT
	)
{
	if (SERVER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (THE_INSTRUMENT.empty())		{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_INSTRUMENT"		); OT_ASSERT(false); }

	// ------------------------------------
	const OTIdentifier  theServerID(SERVER_ID);
	const OTString      strInstrument(THE_INSTRUMENT);
	// ------------------------------------
	OTPayment thePayment(strInstrument);

	if (!thePayment.IsValid())
	{
		OTLog::sOutput(0, "%s: Unable to parse instrument:\n\n%s\n\n",
			__FUNCTION__, strInstrument.Get());
		return "";
	}
	// ---------------------------------------
	bool bSetValues = false;

	if (thePayment.IsPurse())
		bSetValues = thePayment.SetTempValuesPurse(theServerID);
	else
		bSetValues = thePayment.SetTempValues();
	// ---------------------------------------
	if (!bSetValues)
	{
		OTLog::sOutput(0, "%s: Unable to load instrument:\n\n%s\n\n",
			__FUNCTION__, strInstrument.Get());
		return "";
	}
	// ---------------------------------------

	// BY THIS POINT, we have definitely loaded up all the values of the instrument
	// into the OTPayment object. (Meaning we can now return the requested data...)

	OTIdentifier  theOutput;
	const bool    bGotData = thePayment.GetAssetTypeID(theOutput); // <========

	if (bGotData)
	{
		const OTString strOutput(theOutput);

		return strOutput.Get();
	}

	return "";
}

string OTAPI_Wrap::Instrmnt_GetSenderUserID(
	const string & SERVER_ID,
	const string & THE_INSTRUMENT
	)
{
	if (SERVER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (THE_INSTRUMENT.empty())		{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_INSTRUMENT"		); OT_ASSERT(false); }

	// ------------------------------------
	const OTIdentifier  theServerID(SERVER_ID);
	const OTString      strInstrument(THE_INSTRUMENT);
	// ------------------------------------
	OTPayment thePayment(strInstrument);

	if (!thePayment.IsValid())
	{
		OTLog::sOutput(0, "%s: Unable to parse instrument:\n\n%s\n\n",
			__FUNCTION__, strInstrument.Get());
		return "";
	}
	// ---------------------------------------
	bool bSetValues = false;

	if (thePayment.IsPurse())
		bSetValues = thePayment.SetTempValuesPurse(theServerID);
	else
		bSetValues = thePayment.SetTempValues();
	// ---------------------------------------
	if (!bSetValues)
	{
		OTLog::sOutput(0, "%s: Unable to load instrument:\n\n%s\n\n",
			__FUNCTION__, strInstrument.Get());
		return "";
	}
	// ---------------------------------------

	// BY THIS POINT, we have definitely loaded up all the values of the instrument
	// into the OTPayment object. (Meaning we can now return the requested data...)

	OTIdentifier  theOutput;
	const bool    bGotData = thePayment.GetSenderUserID(theOutput); // <========

	if (bGotData)
	{
		const OTString strOutput(theOutput);

		return strOutput.Get();
	}

	return "";
}

string OTAPI_Wrap::Instrmnt_GetSenderAcctID(
	const string & SERVER_ID,
	const string & THE_INSTRUMENT
	)
{
	if (SERVER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (THE_INSTRUMENT.empty())		{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_INSTRUMENT"		); OT_ASSERT(false); }

	// ------------------------------------
	const OTIdentifier  theServerID(SERVER_ID);
	const OTString      strInstrument(THE_INSTRUMENT);
	// ------------------------------------
	OTPayment thePayment(strInstrument);

	if (!thePayment.IsValid())
	{
		OTLog::sOutput(0, "%s: Unable to parse instrument:\n\n%s\n\n",
			__FUNCTION__, strInstrument.Get());
		return "";
	}
	// ---------------------------------------
	bool bSetValues = false;

	if (thePayment.IsPurse())
		bSetValues = thePayment.SetTempValuesPurse(theServerID);
	else
		bSetValues = thePayment.SetTempValues();
	// ---------------------------------------
	if (!bSetValues)
	{
		OTLog::sOutput(0, "%s: Unable to load instrument:\n\n%s\n\n",
			__FUNCTION__, strInstrument.Get());
		return "";
	}
	// ---------------------------------------

	// BY THIS POINT, we have definitely loaded up all the values of the instrument
	// into the OTPayment object. (Meaning we can now return the requested data...)

	OTIdentifier  theOutput;
	const bool    bGotData = thePayment.GetSenderAcctID(theOutput); // <========

	if (bGotData)
	{
		const OTString strOutput(theOutput);

		return strOutput.Get();
	}

	return "";
}

string OTAPI_Wrap::Instrmnt_GetRecipientUserID(
	const string & SERVER_ID,
	const string & THE_INSTRUMENT
	)
{
	if (SERVER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (THE_INSTRUMENT.empty())		{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_INSTRUMENT"		); OT_ASSERT(false); }

	// ------------------------------------
	const OTIdentifier  theServerID(SERVER_ID);
	const OTString      strInstrument(THE_INSTRUMENT);
	// ------------------------------------
	OTPayment thePayment(strInstrument);

	if (!thePayment.IsValid())
	{
		OTLog::sOutput(0, "%s: Unable to parse instrument:\n\n%s\n\n",
			__FUNCTION__, strInstrument.Get());
		return "";
	}
	// ---------------------------------------
	bool bSetValues = false;

	if (thePayment.IsPurse())
		bSetValues = thePayment.SetTempValuesPurse(theServerID);
	else
		bSetValues = thePayment.SetTempValues();
	// ---------------------------------------
	if (!bSetValues)
	{
		OTLog::sOutput(0, "%s: Unable to load instrument:\n\n%s\n\n",
			__FUNCTION__, strInstrument.Get());
		return "";
	}
	// ---------------------------------------

	// BY THIS POINT, we have definitely loaded up all the values of the instrument
	// into the OTPayment object. (Meaning we can now return the requested data...)

	OTIdentifier  theOutput;
	const bool    bGotData = thePayment.GetRecipientUserID(theOutput); // <========

	if (bGotData)
	{
		const OTString strOutput(theOutput);

		return strOutput.Get();
	}

	return "";
}

string OTAPI_Wrap::Instrmnt_GetRecipientAcctID(
	const string & SERVER_ID,
	const string & THE_INSTRUMENT
	)
{
	if (SERVER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (THE_INSTRUMENT.empty())		{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_INSTRUMENT"		); OT_ASSERT(false); }

	// ------------------------------------
	const OTIdentifier  theServerID(SERVER_ID);
	const OTString      strInstrument(THE_INSTRUMENT);
	// ------------------------------------
	OTPayment thePayment(strInstrument);

	if (!thePayment.IsValid())
	{
		OTLog::sOutput(0, "%s: Unable to parse instrument:\n\n%s\n\n",
			__FUNCTION__, strInstrument.Get());
		return "";
	}
	// ---------------------------------------
	bool bSetValues = false;

	if (thePayment.IsPurse())
		bSetValues = thePayment.SetTempValuesPurse(theServerID);
	else
		bSetValues = thePayment.SetTempValues();
	// ---------------------------------------
	if (!bSetValues)
	{
		OTLog::sOutput(0, "%s: Unable to load instrument:\n\n%s\n\n",
			__FUNCTION__, strInstrument.Get());
		return "";
	}
	// ---------------------------------------

	// BY THIS POINT, we have definitely loaded up all the values of the instrument
	// into the OTPayment object. (Meaning we can now return the requested data...)

	OTIdentifier  theOutput;
	const bool    bGotData = thePayment.GetRecipientAcctID(theOutput); // <========

	if (bGotData)
	{
		const OTString strOutput(theOutput);

		return strOutput.Get();
	}

	return "";
}



// --------------------------------------------------------------------




// *** MESSAGES BEING SENT TO THE SERVER -- BELOW!!! ***




/**
CHECK SERVER ID --(This is used for "pinging" the server...)

Notice, if you ever want to send a message, you have to include the
Server ID and the User ID.

The OTAPI_Wrap will use the Server ID to look-up the server contract.(FYI,
the Server ID is a hash of the server contract itself, so it is impos-
sible to change the contract, without also changing the ID.)

Then it will connect to the server based on the connection information
in that contract, send the message, get the reply, and disconnect. 
(That's in HTTP mode -- in TCP mode it maint32_tains the connection.)

It will also encrypt the message to the public key found inside that
contract, so only the person who signed the contract will be able to
read the message.

Open Transactions will also use the User ID to lookup the public key
for that user.(The UserID, aka NymID, is a hash of the public key
itself.)

This message is basically just a ping -- it verifies that the server
is really there, and that it can really open the messages that are
encrypted to the key in the server contract. It's the first thing
your wallet software should do. Think of it like a way to PING the
server.

*/
// Returns int32_t:
// -1 means error; no message was sent.
// -2 means the message was sent, but the request number must be passed as a string, so call GetLargeRequestNum.
// 0 means NO error, but also: no message was sent.
// >0 means NO error, and the message was sent, and the request number fits int32_to an int32_teger...
// ...and in fact the requestNum IS the return value!
// ===> In 99% of cases, this LAST option is what actually happens!!
//
int32_t OTAPI_Wrap::checkServerID(
	const string & SERVER_ID,
	const string & USER_ID
	)
{
	if (SERVER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }

	OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID);

	return OTAPI_Wrap::OTAPI()->checkServerID(theServerID, theUserID);
}


// --------------------------------------------------------------------
/**
CREATE USER's ACCOUNT(On a specific server.)

Note: There are USER accounts and ASSET accounts...

A User account is simply a public key. Whenever you send a message
to the server, you would normally have to send a public key with the
message, so that the server can encrypt the reply back to you.

Due to this, the server will cache the public key so you only have
to send the ID(which is a hash of the key.) The server uses this ID
to look up the public key and encrypt the response back to you.

-- Any user can create as many public keys as they wish. So User
accounts are pseudonymous.

-- Cash token exchanges are possible without a User account(using
an HTTPS proxy operated by the server operator) so users are NOT
forced to create accounts, if they prefer to deal only in cash.
However, it's worth noting that even if they do, the cash itself
IS STILL UNTRACEABLE, due to the Chaumian blinding.

-- A user may use the same public key at multiple servers, and he
creates his own keys inside the wallet. So this function is less
about "creating" the user account, and more about simply register-
ing a public key on a specific server. 

--(Wallet software is capable, in OT, of distributing assets across
multiple servers seamlessly, which means it's a requirement that
the user generate his own keys and register them on whichever 
servers that he sees fit to trust.

Since the server contract and public key are both presumed to have
been created by this point32_t, you simply pass in their IDs and the
library will do the rest of the work.
*/
// Returns int32_t:
// -1 means error; no message was sent.
// -2 means the message was sent, but the request number must be passed as a string, so call GetLargeRequestNum.
// 0 means NO error, but also: no message was sent.
// >0 means NO error, and the message was sent, and the request number fits int32_to an int32_teger...
// ...and in fact the requestNum IS the return value!
// ===> In 99% of cases, this LAST option is what actually happens!!
//
int32_t OTAPI_Wrap::createUserAccount(
	const string & SERVER_ID,
	const string & USER_ID
	)
{
	if (SERVER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }

	OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID);

	return OTAPI_Wrap::OTAPI()->createUserAccount(theServerID, theUserID);
}


// This allows you to delete a Nym from any server it is
// registered at. NOTE: This will FAIL if the Nym has any
// transactions open at the server("used but not closed"),
// as well as if there are any accounts or cron items still
// open at that server, or any receipts in the Nymbox.
//
// Returns int32_t:
// -1 means error; no message was sent.
// -2 means the message was sent, but the request number must be passed as a string, so call GetLargeRequestNum.
// 0 means NO error, but also: no message was sent.
// >0 means NO error, and the message was sent, and the request number fits int32_to an int32_teger...
// ...and in fact the requestNum IS the return value!
// ===> In 99% of cases, this LAST option is what actually happens!!
//
int32_t OTAPI_Wrap::deleteUserAccount(
	const string & SERVER_ID,
	const string & USER_ID
	)
{
	if (SERVER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }

	OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID);

	return OTAPI_Wrap::OTAPI()->deleteUserAccount(theServerID, theUserID);
}

// This allows you to delete an asset account from a server,
// provided that the balance is 0 and the inbox and outbox are
// both empty.
//
// Returns int32_t:
// -1 means error; no message was sent.
// -2 means the message was sent, but the request number must be passed as a string, so call GetLargeRequestNum.
// 0 means NO error, but also: no message was sent.
// >0 means NO error, and the message was sent, and the request number fits int32_to an int32_teger...
// ...and in fact the requestNum IS the return value!
// ===> In 99% of cases, this LAST option is what actually happens!!
//
int32_t OTAPI_Wrap::deleteAssetAccount(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & ACCOUNT_ID
	)
{
	if (SERVER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }
	if (ACCOUNT_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCOUNT_ID"			); OT_ASSERT(false); }

	OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theAccountID(ACCOUNT_ID);

	if (! OTAPI_Wrap::OTAPI()->Wallet_CanRemoveAccount(theAccountID)) return 0;

	return OTAPI_Wrap::OTAPI()->deleteAssetAccount(theServerID, theUserID, theAccountID);
}

// --------------------------------------------------------------------
/**
USAGE CREDITS ---(Based on a UserID, retrieve or adjust the Usage Credits for that Nym.)

ServerID -- Must be included with every message.
USER_ID -- You must include your own userID so the server can reply.
USER_CHECK_ID -- This is a SECOND user's ID.(Whose usage credits we are checking)
ADJUSTMENT -- This can be NULL(resolves as "0"). Otherwise, positive or negative, and passed
as a string. This gives the option to adjust the usage credits balance, up or down.

In this message, you are requesting the server to send you the current balance of
the usage credits for the second user_id. You may also adjust this balance up or
down(+ or - any long int32_t value in string format). If you do, the server reply will
contain the updated usage credits, AFTER the adjustment.

You might ask: Doesn't this mean that ANY user can get/set the usage credits for any other??
// ---------------
ANSWER: Most OT server operators will set cmd_usage_credits=false in the ~/.ot/server.cfg
file.(BECAUSE ONLY AN ADMINISTRATOR SHOULD BE ABLE TO ADJUST ANYONE'S USAGE CREDITS.)
In this case, users will still be able to use this message to VIEW their own personal
usage credits, but they will be unable to see others' balances, and they will be unable
to do any adjustments to any balances, including their own.

If you wish to give full rights to this function to a specific admin Nym, use the
override_nym_id found in ~/.ot/server.cfg
// ---------------------------
After you call usageCredits(), you will receive a server reply. Pass that int32_to
the next function: Message_GetUsageCredits()
*/
// Returns int32_t:
// -1 means error; no message was sent.
// -2 means the message was sent, but the request number must be passed as a string, so call GetLargeRequestNum.
// 0 means NO error, but also: no message was sent.
// >0 means NO error, and the message was sent, and the request number fits int32_to an int32_teger...
// ...and in fact the requestNum IS the return value!
// ===> In 99% of cases, this LAST option is what actually happens!!
//
int32_t OTAPI_Wrap::usageCredits(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & USER_ID_CHECK,
	const string & ADJUSTMENT
	)
{
	if (SERVER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }
	if (USER_ID_CHECK.empty())		{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID_CHECK"		); OT_ASSERT(false); }

	//	OT_ASSERT_MSG(NULL != ADJUSTMENT, "OT_API_usageCredits: Null ADJUSTMENT passed in."); // NULL is allowed here.

	const OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theOtherUserID(USER_ID_CHECK);

	int64_t lAdjustment;

	if (0 < StringToLong(ADJUSTMENT)) lAdjustment = StringToLong(ADJUSTMENT);
	else lAdjustment = 0;

	return OTAPI_Wrap::OTAPI()->usageCredits(theServerID, theUserID, theOtherUserID, static_cast<long>(lAdjustment));
}



// IF THE_MESSAGE is of command type @usageCredits, and IF it was a SUCCESS,
// then this function returns the usage credits BALANCE(it's a long int32_t, but
// passed as a string). If you adjusted the balance using the usageCredits
// command(THE_MESSAGE being the server's reply to that) then you will see
// the balance AFTER the adjustment.(The current "Usage Credits" balance.)
// 
int64_t OTAPI_Wrap::Message_GetUsageCredits(const string & THE_MESSAGE)
{
	if (THE_MESSAGE.empty())		{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_MESSAGE"		); OT_ASSERT(false); }

	OTString strMessage(THE_MESSAGE);
	OTMessage theMessage;
	if (!strMessage.Exists())
	{
		OTLog::sError("%s: Error: THE_MESSAGE doesn't exist.\n", __FUNCTION__);
		return -1;
	}

	if (!theMessage.LoadContractFromString(strMessage))
	{
		OTLog::sError("%s: Failed loading message from string.\n", __FUNCTION__);
		return -1;
	}

	if (false == theMessage.m_bSuccess)
	{
		OTLog::sError("%s: Message success == false, thus unable to report Usage Credits balance.\n", __FUNCTION__);
		return -1;
	}

	if (false == theMessage.m_strCommand.Compare("@usageCredits"))
	{
		OTLog::sError("%s: THE_MESSAGE is supposed to be of command type \"@usageCredits\", but instead it's a: %s\n (Failure. Returning NULL.)", __FUNCTION__, theMessage.m_strCommand.Get());
		return -1;
	}

	// ----------------------------------------------
	// By this point, we know the message was a successful @usageCredits, loaded
	// properly from the string that was passed in. Let's return the usage credits
	// balance (a long int, returned in string format.)

	return theMessage.m_lDepth;
}




// --------------------------------------------------------------------
/**
CHECK USER ---(Grab his public key based on his User ID.)

ServerID -- Must be included with every message.
USER_ID -- You must include your own userID so the server can reply.
USER_CHECK_ID -- This is a SECOND user's ID. 

In this message, you are requesting the server to send you the
public key for another user, denoted by his ID in USER_ID_CHECK.

The server's response will contain the public key of the other
user, so you can encrypt messages or cash to him. Your wallet can
verify that the key is the right one, by hashing it and comparing
the result to the other user's ID. Since the User ID is a hash of
the key, they should always match.

*/
// Returns int32_t:
// -1 means error; no message was sent.
// -2 means the message was sent, but the request number must be passed as a string, so call GetLargeRequestNum.
// 0 means NO error, but also: no message was sent.
// >0 means NO error, and the message was sent, and the request number fits int32_to an int32_teger...
// ...and in fact the requestNum IS the return value!
// ===> In 99% of cases, this LAST option is what actually happens!!
//
int32_t OTAPI_Wrap::checkUser(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & USER_ID_CHECK
	)
{
	if (SERVER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }
	if (USER_ID_CHECK.empty())		{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID_CHECK"		); OT_ASSERT(false); }

	OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theOtherUserID(USER_ID_CHECK);

	return OTAPI_Wrap::OTAPI()->checkUser(theServerID, theUserID, theOtherUserID);
}

// --------------------------------------------------------------------
/**
SEND USER MESSAGE ---(Send a message to another user, encrypted to his pubkey.)

ServerID -- Must be included with every message.
USER_ID -- You must include your own userID so the server can reply.
USER_ID_RECIPIENT -- This is a recipient user ID.
RECIPIENT_PUBKEY -- Recipient's public key in base64-encoded form.
THE_MESSAGE -- plaint32_text message you want to send. A cheque? Some cash? A note? Etc.

In this message, you are requesting the server to send a message to
another user, encrypted to his public key and dropped in his nymbox.

*/
// Returns int32_t:
// -1 means error; no message was sent.
// -2 means the message was sent, but the request number must be passed as a string, so call GetLargeRequestNum.
// 0 means NO error, but also: no message was sent.
// >0 means NO error, and the message was sent, and the request number fits int32_to an int32_teger...
// ...and in fact the requestNum IS the return value!
// ===> In 99% of cases, this LAST option is what actually happens!!
//
int32_t OTAPI_Wrap::sendUserMessage(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & USER_ID_RECIPIENT,
	const string & RECIPIENT_PUBKEY,
	const string & THE_MESSAGE
	)
{
	if (SERVER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }
	if (USER_ID_RECIPIENT.empty())	{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID_RECIPIENT"	); OT_ASSERT(false); }
	if (RECIPIENT_PUBKEY.empty())	{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "RECIPIENT_PUBKEY"	); OT_ASSERT(false); }
	if (THE_MESSAGE.empty())		{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_MESSAGE"		); OT_ASSERT(false); }

	OTIdentifier	theServerID(SERVER_ID), theUserID(USER_ID), theOtherUserID(USER_ID_RECIPIENT);
	OTString        strRecipPubkey(RECIPIENT_PUBKEY);
	OTString		strMessage(THE_MESSAGE);

	return OTAPI_Wrap::OTAPI()->sendUserMessage(theServerID, theUserID, theOtherUserID, strRecipPubkey, strMessage);	
}
/*
sendUserMessage does this:
-- Puts user message as encrypted Payload on an OTMessage(1)...
-- Also puts user message as a CLEAR payload on an OTMessage(2)...
--(1) is sent to server, and(2) is added to Outmail messages.
--(1) gets added to recipient's Nymbox as "in ref to" string on a
"message" transaction.
-- When recipient processes Nymbox, OTMessage(1) is extracted and
added to recipient's nym Mail.
-- When recipient gets mail contents, decryption occurs from(1) payload,
before returning contents as original user message string.
-- When sender gets outmail contents, original user message string is
returned from(2) payload, with no decryption necessary.
*/



// --------------------------------------------------------------------
/**
SEND USER INSTRUMENT ---(Send a financial instrument to another user, encrypted to his pubkey.)

ServerID -- Must be included with every message.
USER_ID -- You must include your own userID so the server can reply.
USER_ID_RECIPIENT -- This is a recipient user ID.
RECIPIENT_PUBKEY -- Recipient's public key in base64-encoded form.
THE_INSTRUMENT -- plaint32_text string of instrument(cheque, payment plan, purse, invoice, voucher...)

In this message, you are requesting the server to send a financial instrument to
another user, encrypted to his public key and dropped in his paymentInbox(by way
of his nymbox.)

*/
// Returns int32_t:
// -1 means error; no message was sent.
// -2 means the message was sent, but the request number must be passed as a string, so call GetLargeRequestNum.
// 0 means NO error, but also: no message was sent.
// >0 means NO error, and the message was sent, and the request number fits int32_to an int32_teger...
// ...and in fact the requestNum IS the return value!
// ===> In 99% of cases, this LAST option is what actually happens!!
//
int32_t OTAPI_Wrap::sendUserInstrument(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & USER_ID_RECIPIENT,
	const string & RECIPIENT_PUBKEY,
	const string & THE_INSTRUMENT
	)
{
	if (SERVER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }
	if (USER_ID_RECIPIENT.empty())	{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID_RECIPIENT"	); OT_ASSERT(false); }
	if (RECIPIENT_PUBKEY.empty())	{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "RECIPIENT_PUBKEY"	); OT_ASSERT(false); }
	if (THE_INSTRUMENT.empty())		{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_INSTRUMENT"		); OT_ASSERT(false); }

	OTIdentifier	theServerID(SERVER_ID), theUserID(USER_ID), theOtherUserID(USER_ID_RECIPIENT);
	OTASCIIArmor	ascRecipPubkey(RECIPIENT_PUBKEY);
	OTString		strInstrument(THE_INSTRUMENT);
	// ---------------------------------------------------


	OTPayment thePayment(strInstrument);

	if (!thePayment.IsValid())
	{
		OTLog::sOutput(0, "%s: Failure loading payment instrument from string:\n\n%s\n\n", __FUNCTION__, strInstrument.Get());
		return -1;
	}
	// ------------------------------------------------------------
	return OTAPI_Wrap::OTAPI()->sendUserInstrument(theServerID, theUserID, theOtherUserID, ascRecipPubkey, thePayment);	
}

// --------------------------------------------------------------------
/**
GET REQUEST NUMBER

Nearly every message to the server needs to have the current "Request
Number" attached to it. This is a number that, for each user, starts at
0, and increments with each command. Usually, the number simply
increments on both sides, and there is no need to communicate it.

BUT SOMETIMES the request number GOES OUT OF SYNC... When this happen,
none of your commands will work anymore!

To fix it, just call this function.

After you call it, it will automatically synchronize your wallet with
the request number on the server side, and your commands will start
working again.

Without understanding this simple concept, NONE of your messages will
go through! This mechanism prevents an attack from int32_tercepting a message
and sending it multiple times.
*/
// Returns int32_t:
// -1 means error; no message was sent.
// -2 means the message was sent, but the request number must be passed as a string, so call GetLargeRequestNum.
// 0 means NO error, but also: no message was sent.
// >0 means NO error, and the message was sent, and the request number fits int32_to an int32_teger...
// ...and in fact the requestNum IS the return value!
// ===> In 99% of cases, this LAST option is what actually happens!!
//
int32_t OTAPI_Wrap::getRequest(
	const string & SERVER_ID,
	const string & USER_ID
	)
{
	if (SERVER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }

	OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID);

	return OTAPI_Wrap::OTAPI()->getRequest(theServerID, theUserID);
}

/**
GET TRANSACTION NUMBER

Every TRANSACTION must be accompanied by a TRANSACTION NUMBER
and you can only use a transaction number that was given to you
previously by the server. If you run out of transaction numbers, then
just call the below API function to get a new one(call it a few times
so your wallet has a few in reserve.)

The server usually sends you new transaction numbers whenever you
successfully do commands, but if you run out, you just call that function.

Without understanding this, none of your transactions would ever go
through! This mechanism is what makes it possible to prove balances
and transactions, without having to store any account history!
*/
// Returns int32_t:
// -1 means error; no message was sent.
// -2 means the message was sent, but the request number must be passed as a string, so call GetLargeRequestNum.
// 0 means NO error, but also: no message was sent.
// >0 means NO error, and the message was sent, and the request number fits int32_to an int32_teger...
// ...and in fact the requestNum IS the return value!
// ===> In 99% of cases, this LAST option is what actually happens!!
//
int32_t OTAPI_Wrap::getTransactionNumber(
	const string & SERVER_ID,
	const string & USER_ID
	)
{
	if (SERVER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }

	OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID);


	return OTAPI_Wrap::OTAPI()->getTransactionNumber(theServerID, theUserID);
}



// --------------------------------------------------------------------
// ISSUE ASSET TYPE -- Ask the server to issue a new asset type.
//
// THE_CONTRACT is actually a string containing the asset contract itself.
//(And the server will not issue the new asset type unless the key in the
// contract matches YOUR UserID. Only the contract signer may issue it.)
//
// Returns int32_t:
// -1 means error; no message was sent.
// -2 means the message was sent, but the request number must be passed as a string, so call GetLargeRequestNum.
// 0 means NO error, but also: no message was sent.
// >0 means NO error, and the message was sent, and the request number fits int32_to an int32_teger...
// ...and in fact the requestNum IS the return value!
// ===> In 99% of cases, this LAST option is what actually happens!!
//
int32_t OTAPI_Wrap::issueAssetType(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & THE_CONTRACT
	)
{
	if (SERVER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }
	if (THE_CONTRACT.empty())		{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_CONTRACT"		); OT_ASSERT(false); }

	OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID);

	OTString strContract(THE_CONTRACT);

	return OTAPI_Wrap::OTAPI()->issueAssetType(theServerID, theUserID, strContract);
}



// --------------------------------------------------------------------
// GET CONTRACT -- Get server's copy of any asset contract, by asset type ID.
//
// Returns int32_t:
// -1 means error; no message was sent.
// -2 means the message was sent, but the request number must be passed as a string, so call GetLargeRequestNum.
// 0 means NO error, but also: no message was sent.
// >0 means NO error, and the message was sent, and the request number fits int32_to an int32_teger...
// ...and in fact the requestNum IS the return value!
// ===> In 99% of cases, this LAST option is what actually happens!!
//
int32_t OTAPI_Wrap::getContract(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & ASSET_ID
	)
{
	if (SERVER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }
	if (ASSET_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "ASSET_ID"			); OT_ASSERT(false); }

	OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theAssetID(ASSET_ID);

	return OTAPI_Wrap::OTAPI()->getContract(theServerID, theUserID, theAssetID);
}




// --------------------------------------------------------------------------
// Get server's copy of public Mint32_t file(which contains the public mint32_ting
// keys for each asset type. Withdrawal requests will not work for any given
// asset type until you have downloaded the mint32_t for that asset type.)
//
// Returns int32_t:
// -1 means error; no message was sent.
// -2 means the message was sent, but the request number must be passed as a string, so call GetLargeRequestNum.
// 0 means NO error, but also: no message was sent.
// >0 means NO error, and the message was sent, and the request number fits int32_to an int32_teger...
// ...and in fact the requestNum IS the return value!
// ===> In 99% of cases, this LAST option is what actually happens!!
//
int32_t OTAPI_Wrap::getMint(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & ASSET_ID
	)
{
	if (SERVER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }
	if (ASSET_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "ASSET_ID"			); OT_ASSERT(false); }

	OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theAssetID(ASSET_ID);

	return OTAPI_Wrap::OTAPI()->getMint(theServerID, theUserID, theAssetID);
}





// ---------------------------------------------------------------------------
// CREATE ASSET ACCOUNT -- of any asset type,(just pass in the Asset Type ID.) 
//
// Returns int32_t:
// -1 means error; no message was sent.
// -2 means the message was sent, but the request number must be passed as a string, so call GetLargeRequestNum.
// 0 means NO error, but also: no message was sent.
// >0 means NO error, and the message was sent, and the request number fits int32_to an int32_teger...
// ...and in fact the requestNum IS the return value!
// ===> In 99% of cases, this LAST option is what actually happens!!
//
int32_t OTAPI_Wrap::createAssetAccount(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & ASSET_ID
	)
{
	if (SERVER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }
	if (ASSET_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "ASSET_ID"			); OT_ASSERT(false); }

	OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theAssetID(ASSET_ID);

	return OTAPI_Wrap::OTAPI()->createAssetAccount(theServerID, theUserID, theAssetID);
}




// --------------------------------------------------------------------------
// GET ACCOUNT -- Send a message to the server asking it to send you the latest
// copy of any of your asset accounts(incl. the current balance.)
//
// Returns int32_t:
// -1 means error; no message was sent.
// -2 means the message was sent, but the request number must be passed as a string, so call GetLargeRequestNum.
// 0 means NO error, but also: no message was sent.
// >0 means NO error, and the message was sent, and the request number fits int32_to an int32_teger...
// ...and in fact the requestNum IS the return value!
// ===> In 99% of cases, this LAST option is what actually happens!!
//
int32_t OTAPI_Wrap::getAccount(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & ACCT_ID
	)
{
	if (SERVER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }
	if (ACCT_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCT_ID"			); OT_ASSERT(false); }

	OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theAcctID(ACCT_ID);

	return OTAPI_Wrap::OTAPI()->getAccount(theServerID, theUserID, theAcctID);
}



// --------------------------------------------------









// ----------------------------------------------------
// GENERATE BASKET CREATION REQUEST
//
//(returns the basket in string form.)
//
// Call AddBasketCreationItem multiple times to add
// the various currencies to the basket, and then call 
// issueBasket to send the request to the server.
//
string OTAPI_Wrap::GenerateBasketCreation(
	const string & USER_ID,
	const string & MINIMUM_TRANSFER // If basket is X=2,3,4, then this is X.
	)
{
	if (USER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }

	const OTIdentifier theUserID(USER_ID);

	// ----------------------------------------------
	int64_t lMinimumTransfer;

	if (0 > StringToLong(MINIMUM_TRANSFER)) lMinimumTransfer = 10;
	else lMinimumTransfer = StringToLong(MINIMUM_TRANSFER);
	// ----------------------------------------------

	OTBasket * pBasket = OTAPI_Wrap::OTAPI()->GenerateBasketCreation(theUserID, static_cast<long>(lMinimumTransfer)); // Must be above zero. If <= 0, defaults to 10.

	OTCleanup<OTBasket> theAngel(pBasket);

	if (NULL == pBasket)
		return "";

	// At this point, I know pBasket is good (and will be cleaned up automatically.)
	// ----------------------------------------------


	OTString strOutput(*pBasket);
	//	pBasket->SaveContract(strOutput); // Extract the basket to string form.

	return strOutput.Get(); 	
}


// ----------------------------------------------------
// ADD BASKET CREATION ITEM
//
//(returns the updated basket in string form.)
//
// Call GenerateBasketCreation first(above), then
// call this function multiple times to add the various
// currencies to the basket, and then call issueBasket 
// to send the request to the server.
//
string OTAPI_Wrap::AddBasketCreationItem(
	const string & USER_ID, // for signature.
	const string & THE_BASKET, // created in above call.
	const string & ASSET_TYPE_ID, // Adding an asset type to the new basket.
	const string & MINIMUM_TRANSFER // If basket is 5=X,X,X then this is an X.
	)
{

	if (USER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }
	if (THE_BASKET.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_BASKET"			); OT_ASSERT(false); }
	if (ASSET_TYPE_ID.empty())		{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "ASSET_TYPE_ID"		); OT_ASSERT(false); }

	OTString strBasket(THE_BASKET);

	// ----------------------------------------------------

	const OTIdentifier theUserID(USER_ID), theAssetTypeID(ASSET_TYPE_ID);

	// ----------------------------------------------
	int64_t lMinimumTransfer;

	if (0 > StringToLong(MINIMUM_TRANSFER)) lMinimumTransfer = 10;
	else lMinimumTransfer = StringToLong(MINIMUM_TRANSFER);
	// ----------------------------------------------

	OTBasket theBasket;

	bool bAdded = false;

	// todo perhaps verify the basket here, even though I already verified the asset contract itself...
	// Can't never be too sure.
	if (theBasket.LoadContractFromString(strBasket))
	{
		bAdded = OTAPI_Wrap::OTAPI()->AddBasketCreationItem(theUserID, // for signature.
			theBasket, // created in above call.
			theAssetTypeID, // Adding an asset type to the new basket.
			static_cast<long>(lMinimumTransfer)); // The amount of the asset type that is in the basket (per).
	}

	if (false == bAdded)
		return "";
	// ----------------------------------------

	OTString strOutput(theBasket); // Extract the updated basket to string form.

	return strOutput.Get(); 	
}


// --------------------------------------------------------------------------
// ISSUE BASKET CURRENCY
//
// Issue a new asset type based on a BASKET of other asset types!
// You cannot call this function until you first set up the BASKET_INFO object.
// I will provide functions for setting up that object, so that you can then
// call this function to actually message the server with your request.
//
// ANYONE can issue a new basket type, but they will have no control over the
// issuer account. Normally when issuing a currency, you therefore control the
// issuer account. But with baskets, that is managed int32_ternally by the server.
// This means anyone can define a basket, and all may use it -- but no one
// controls it except the server.
//
// Returns int32_t:
// -1 means error; no message was sent.
// -2 means the message was sent, but the request number must be passed as a string, so call GetLargeRequestNum.
// 0 means NO error, but also: no message was sent.
// >0 means NO error, and the message was sent, and the request number fits int32_to an int32_teger...
// ...and in fact the requestNum IS the return value!
// ===> In 99% of cases, this LAST option is what actually happens!!
//
int32_t OTAPI_Wrap::issueBasket(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & THE_BASKET
	)
{
	if (SERVER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }
	if (THE_BASKET.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_BASKET"			); OT_ASSERT(false); }

	OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID);

	OTString strBasketInfo(THE_BASKET);

	return OTAPI_Wrap::OTAPI()->issueBasket(theServerID, theUserID, strBasketInfo);
}










// ----------------------------------------------------
// GENERATE BASKET EXCHANGE REQUEST
//
//(Returns the new basket exchange request in string form.)
//
// Call this function first. Then call AddBasketExchangeItem
// multiple times, and then finally call exchangeBasket to
// send the request to the server.
//
string OTAPI_Wrap::GenerateBasketExchange(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & BASKET_ASSET_TYPE_ID,
	const string & BASKET_ASSET_ACCT_ID,
	// -------------------------------------
	const int32_t & TRANSFER_MULTIPLE
	)
{
	if (SERVER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }
	if (BASKET_ASSET_TYPE_ID.empty()) { OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "BASKET_ASSET_TYPE_ID"); OT_ASSERT(false); }
	if (BASKET_ASSET_ACCT_ID.empty()) { OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "BASKET_ASSET_ACCT_ID"); OT_ASSERT(false); }

	const OTIdentifier	theUserID(USER_ID), theServerID(SERVER_ID),
		theBasketAssetTypeID(BASKET_ASSET_TYPE_ID), 
		theBasketAssetAcctID(BASKET_ASSET_ACCT_ID);

	// ----------------------------------------------

	int nTransferMultiple = 1; // Just a default value.

	if (TRANSFER_MULTIPLE > 0)
		nTransferMultiple = TRANSFER_MULTIPLE;

	// ----------------------------------------------

	OTBasket * pBasket = OTAPI_Wrap::OTAPI()->GenerateBasketExchange(theServerID,
		theUserID,
		theBasketAssetTypeID,
		theBasketAssetAcctID,
		nTransferMultiple);	// 1			2			 3
	// 5=2,3,4  OR  10=4,6,8  OR 15=6,9,12
	OTCleanup<OTBasket> theAngel(pBasket);

	if (NULL == pBasket)
		return "";

	// At this point, I know pBasket is good (and will be cleaned up automatically.)
	// ----------------------------------------------


	OTString strOutput(*pBasket); // Extract the basket to string form.

	return strOutput.Get(); 	
}
// 1 2  3
// 5=2,3,4 OR 10=4,6,8 OR 15=6,9,12 Etc.(The MULTIPLE.)


// ----------------------------------------------------
// ADD BASKET EXCHANGE ITEM
//
// Returns the updated basket exchange request in string form.
//(Or NULL.)
//
// Call the above function first. Then call this one multiple
// times, and then finally call exchangeBasket to send
// the request to the server.
//
string OTAPI_Wrap::AddBasketExchangeItem(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & THE_BASKET, 
	const string & ASSET_TYPE_ID,
	const string & ASSET_ACCT_ID
	)
{
	if (SERVER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }
	if (THE_BASKET.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_BASKET"			); OT_ASSERT(false); }
	if (ASSET_TYPE_ID.empty())		{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "ASSET_TYPE_ID"		); OT_ASSERT(false); }
	if (ASSET_ACCT_ID.empty())		{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "ASSET_ACCT_ID"		); OT_ASSERT(false); }

	OTString strBasket(THE_BASKET);

	// ----------------------------------------------------

	const OTIdentifier	theServerID(SERVER_ID), theUserID(USER_ID), 
		theAssetTypeID(ASSET_TYPE_ID),
		theAssetAcctID(ASSET_ACCT_ID);

	// ----------------------------------------------

	OTBasket theBasket;

	bool bAdded = false;

	// todo perhaps verify the basket here, even though I already verified the asset contract itself...
	// Can't never be too sure.
	if (theBasket.LoadContractFromString(strBasket))
	{
		bAdded = OTAPI_Wrap::OTAPI()->AddBasketExchangeItem(theServerID,
			theUserID,
			theBasket, 
			theAssetTypeID,
			theAssetAcctID);
	}

	if (false == bAdded)
		return "";

	OTString strOutput(theBasket); // Extract the updated basket to string form.

	return strOutput.Get(); 
}

// --------------------------------------------------------------------------
// EXCHANGE BASKET
//
// Send a request to the server asking to exchange in or out of a basket
// currency.
// 
// For example, maybe you have 3 gold, 2 silver, and 5 dollars, and those are
// the ingredients of the "Rand" basket currency. This message allows you to
// ask the server to convert from your gold, silver, and dollar accounts int32_to
// your Rand account.(Or convert from your Rand account back int32_to your gold,
// silver, and dollar accounts.)
//
// Other than this conversion process,(with the reserves stored int32_ternally by
// the server) basket accounts are identical to normal asset accounts -- they
// are merely another asset type ID, and you can use them the same as you would
// use any other asset type(open accounts, write cheques, withdraw cash, trade
// on markets, etc.)
//
// Returns int32_t:
// -1 means error; no message was sent.
// -2 means the message was sent, but the request number must be passed as a string, so call GetLargeRequestNum.
// 0 means NO error, but also: no message was sent.
// >0 means NO error, and the message was sent, and the request number fits int32_to an int32_teger...
// ...and in fact the requestNum IS the return value!
// ===> In 99% of cases, this LAST option is what actually happens!!
//
int32_t OTAPI_Wrap::exchangeBasket(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & BASKET_ASSET_ID,
	const string & THE_BASKET,
	const bool & BOOL_EXCHANGE_IN_OR_OUT // exchanging in == OT_TRUE, out == OT_FALSE.
	)
{
	if (SERVER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }
	if (BASKET_ASSET_ID.empty())	{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "BASKET_ASSET_ID"	); OT_ASSERT(false); }
	if (THE_BASKET.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_BASKET"			); OT_ASSERT(false); }

	OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theBasketAssetID(BASKET_ASSET_ID);

	OTString strBasketInfo(THE_BASKET);

	// exchanging in == true, out == false.
	const bool bExchangeInOrOut = BOOL_EXCHANGE_IN_OR_OUT;

	return OTAPI_Wrap::OTAPI()->exchangeBasket(theServerID, theUserID, theBasketAssetID, strBasketInfo, bExchangeInOrOut);
}



// --------------------------------------------------------------------------
// WITHDRAW CASH
//
// User is requesting the server to withdraw AMOUNT from ACCT_ID and return
// a purse containing cash tokens.
//
// Cash tokens come in specific denominations, such as 10, 25, 100, etc.
// Thus, if you want to withdraw a specific amount, such as 1291, then
// you are not withdrawing a single token, but a purse full of them.
//(An "OTPurse" is the object that contains a list of tokens.)
//
// Therefore, any transactions involving cash withdrawals or deposits,
// you are actually using an OTPurse, rather than manipulating the individual
// tokens.
// 
// If Open Transactions receives a purse in reply from the server, it
// will automatically save the tokens in that purse int32_to your purse
// file for that asset type. You can then reload the purse using 
// LoadPurse, if you want to see the updated contents.
//
// Returns int32_t:
// -1 means error; no message was sent.
// -2 means the message was sent, but the request number must be passed as a string, so call GetLargeRequestNum.
// 0 means NO error, but also: no message was sent.
// >0 means NO error, and the message was sent, and the request number fits int32_to an int32_teger...
// ...and in fact the requestNum IS the return value!
// ===> In 99% of cases, this LAST option is what actually happens!!
//
int32_t OTAPI_Wrap::notarizeWithdrawal(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & ACCT_ID,
	const string & AMOUNT
	)
{
	if (SERVER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }
	if (ACCT_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCT_ID"			); OT_ASSERT(false); }
	if (AMOUNT.empty())				{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "AMOUNT"				); OT_ASSERT(false); }

	OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theAcctID(ACCT_ID);

	OTString strAmount(AMOUNT);

	return OTAPI_Wrap::OTAPI()->notarizeWithdrawal(theServerID, theUserID, theAcctID, strAmount);
}

// --------------------------------------------------------------------------
// DEPOSIT CASH
//
// Use LoadPurse to load a purse from storage, and then use this
// function to actually deposit that cash int32_to a server account.(The cash
// must, of course, be the same asset type as the account.)
//
// Returns int32_t:
// -1 means error; no message was sent.
// -2 means the message was sent, but the request number must be passed as a string, so call GetLargeRequestNum.
// 0 means NO error, but also: no message was sent.
// >0 means NO error, and the message was sent, and the request number fits int32_to an int32_teger...
// ...and in fact the requestNum IS the return value!
// ===> In 99% of cases, this LAST option is what actually happens!!
//
int32_t OTAPI_Wrap::notarizeDeposit(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & ACCT_ID,
	const string & THE_PURSE
	)
{
	if (SERVER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }
	if (ACCT_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCT_ID"			); OT_ASSERT(false); }
	if (THE_PURSE.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_PURSE"			); OT_ASSERT(false); }

	// REMOVE TEMP DEBUG
	//	OTLog::sError("DEBUG: SERVER_ID: %s \n USER_ID: %s \n ACCT_ID: %s \n THE_PURSE: %s\n", 
	//				  SERVER_ID, USER_ID, ACCT_ID, THE_PURSE);

	OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theAcctID(ACCT_ID);
	OTString strPurse(THE_PURSE);

	return OTAPI_Wrap::OTAPI()->notarizeDeposit(theServerID, theUserID, theAcctID, strPurse);
}

// --------------------------------------------------------------------------
// TRANSFER FROM ONE ASSET ACCOUNT TO ANOTHER
//
// Send a request to the server to initiate a transfer from my account to
// another account's inbox.(With "transfer pending" notice in my outbox).
// Until the recipient accepts the transfer, I have the option to cancel
// it while it is still sitting in my outbox. But once he accepts it, it 
// cannot be reversed.
// The server has signatures from BOTH parties requesting the transfer, and
// each party has the signature on the other party's request. Receipts are
// dropped int32_to their respective inboxes.
//
// Returns int32_t:
// -1 means error; no message was sent.
// -2 means the message was sent, but the request number must be passed as a string, so call GetLargeRequestNum.
// 0 means NO error, but also: no message was sent.
// >0 means NO error, and the message was sent, and the request number fits int32_to an int32_teger...
// ...and in fact the requestNum IS the return value!
// ===> In 99% of cases, this LAST option is what actually happens!!
//
int32_t OTAPI_Wrap::notarizeTransfer(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & ACCT_FROM,
	const string & ACCT_TO,
	const string & AMOUNT,
	const string & NOTE
	)
{
	if (SERVER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }
	if (ACCT_FROM.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCT_FROM"			); OT_ASSERT(false); }
	if (ACCT_TO.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCT_TO"			); OT_ASSERT(false); }
	if (0 > StringToLong(AMOUNT))	{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "AMOUNT"				); OT_ASSERT(false); }

	OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID);
	OTIdentifier theFromAcct(ACCT_FROM), theToAcct(ACCT_TO);

	OTString strNote;

	const int64_t lAmount = StringToLong(AMOUNT);

	if (! NOTE.empty()) strNote.Set(NOTE);

	return OTAPI_Wrap::OTAPI()->notarizeTransfer(theServerID, theUserID, theFromAcct, theToAcct, static_cast<long>(lAmount), strNote);
}

// --------------------------------------------------------------------------
// GET A COPY OF MY INBOX
//
// Each asset account has its own inbox/outbox.
// If a pending transfer is in my inbox, or a new receipt, I might want to see
// that. This message asks the server to send me the latest copy of the inbox
// for any given account(and will save it to my local storage, so I can then
// load it using LoadInbox, which I haven't written yet.
/* 
NOTE: the test client, upon receiving a @getInbox response from the server, 
will automatically process that int32_to a processInbox command back to the server, 
automatically accepting all of the transactions, resulting in a final 
@processInbox reply from the server. Obviously a real GUI client would merely 
display the inbox to the user, where the user could choose to accept the items 
individually.
*/
/**
SO HOW WOULD YOU **USE** THIS? To process your inbox...

-- First you call getInbox to grab the latest inbox from the server.
(You will also want to call getOutbox as well as
getAccount, since you need to have the latest versions of
those files, or your balance agreement will be calculated wrong,
causing your transaction to fail.)

-- Then you call LoadInbox to load it from local storage.

During this time, your user has the opportunity to peruse the
inbox, and to decide which transactions therein he wishes to 
accept or reject. If you want to display the inbox items on
the screen, use these functions to loop through them:
Ledger_GetCount
Ledger_GetTransactionByIndex
Ledger_GetTransactionNumberByIndex

You will probably ask me for more int32_trospection on the transactions themselves. 
(Just ask -- No problem.) Here's what you have right now:
Transaction_GetType

-- Then call Ledger_CreateResponse in order to create a
'response' ledger for that inbox, which will be sent to the server.

-- Then call Ledger_GetCount(pass it the inbox) to find out how many 
transactions are inside of it. Use that count to LOOP through them...

-- Use Ledger_GetTransactionByIndex to grab each transaction as
you iterate through the inbox.

-- Call Transaction_CreateResponse to create a response for each
transaction, accepting or rejecting it, and adding it to the response
ledger.

-- Penultimately, call Ledger_FinalizeResponse() which will create
a Balance Agreement for the ledger.

-- Finally, call processInbox to send that response ledger to the
server and process the various items.
*/

// Returns int32_t:
// -1 means error; no message was sent.
// -2 means the message was sent, but the request number must be passed as a string, so call GetLargeRequestNum.
// 0 means NO error, but also: no message was sent.
// >0 means NO error, and the message was sent, and the request number fits int32_to an int32_teger...
// ...and in fact the requestNum IS the return value!
// ===> In 99% of cases, this LAST option is what actually happens!!
//
int32_t OTAPI_Wrap::getInbox(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & ACCT_ID
	)
{
	if (SERVER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }
	if (ACCT_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCT_ID"			); OT_ASSERT(false); }

	OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theAcctID(ACCT_ID);

	return OTAPI_Wrap::OTAPI()->getInbox(theServerID, theUserID, theAcctID);
}

// Returns int32_t:
// -1 means error; no message was sent.
// -2 means the message was sent, but the request number must be passed as a string, so call GetLargeRequestNum.
// 0 means NO error, but also: no message was sent.
// >0 means NO error, and the message was sent, and the request number fits int32_to an int32_teger...
// ...and in fact the requestNum IS the return value!
// ===> In 99% of cases, this LAST option is what actually happens!!
//
int32_t OTAPI_Wrap::getOutbox(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & ACCT_ID
	)
{
	if (SERVER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }
	if (ACCT_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCT_ID"			); OT_ASSERT(false); }

	OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theAcctID(ACCT_ID);

	return OTAPI_Wrap::OTAPI()->getOutbox(theServerID, theUserID, theAcctID);
}



// from server(pop message buf for the response)
// Returns int32_t:
// -1 means error; no message was sent.
// -2 means the message was sent, but the request number must be passed as a string, so call GetLargeRequestNum.
// 0 means NO error, but also: no message was sent.
// >0 means NO error, and the message was sent, and the request number fits int32_to an int32_teger...
// ...and in fact the requestNum IS the return value!
// ===> In 99% of cases, this LAST option is what actually happens!!
//
int32_t OTAPI_Wrap::getNymbox(
	const string & SERVER_ID,
	const string & USER_ID
	)
{
	if (SERVER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }

	OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID);

	return OTAPI_Wrap::OTAPI()->getNymbox(theServerID, theUserID);
}

// from local storage.
// Returns NULL, or a Nymbox.
string OTAPI_Wrap::LoadNymbox(
	const string & SERVER_ID,
	const string & USER_ID
	)
{
	if (SERVER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }

	const OTIdentifier theServerID(SERVER_ID);
	const OTIdentifier theUserID(USER_ID);

	// There is an OT_ASSERT in here for memory failure,
	// but it still might return NULL if various verification fails.
	OTLedger * pLedger = OTAPI_Wrap::OTAPI()->LoadNymbox(theServerID, theUserID); 

	// Make sure it gets cleaned up when this goes out of scope.
	OTCleanup<OTLedger>	theAngel(pLedger); // I pass the pointer, in case it's NULL.

	if (NULL == pLedger)
	{
		OTLog::sOutput(0, "%s: Failure calling OT_API::LoadNymbox.\n", __FUNCTION__);
	}
	else // success 
	{
		OTString strOutput(*pLedger); // For the output

		return strOutput.Get(); 
	}

	return "";				
}

// Returns NULL, or a Nymbox.
string OTAPI_Wrap::LoadNymboxNoVerify(
	const string & SERVER_ID,
	const string & USER_ID
	)
{
	if (SERVER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }

	const OTIdentifier theServerID(SERVER_ID);
	const OTIdentifier theUserID(USER_ID);

	// There is an OT_ASSERT in here for memory failure,
	// but it still might return NULL if various verification fails.
	OTLedger * pLedger = OTAPI_Wrap::OTAPI()->LoadNymboxNoVerify(theServerID, theUserID); 

	// Make sure it gets cleaned up when this goes out of scope.
	OTCleanup<OTLedger>	theAngel(pLedger); // I pass the pointer, in case it's NULL.

	if (NULL == pLedger)
	{
		OTLog::sOutput(0, "%s: Failure calling OT_API::LoadNymboxNoVerify.\n", __FUNCTION__);
	}
	else // success 
	{
		OTString strOutput(*pLedger); // For the output

		return strOutput.Get(); 
	}

	return "";
}



// Some server replies(to your messages) are so important that a notice is dropped
// int32_to your Nymbox with a copy of the server's reply. It's called a replyNotice.
// Since the server is usually replying to a message, I've added this function for
// quickly looking up the message reply, if it's there, based on the requestNumber.
// This is the only example in the entire OT API where a Transaction is looked-up from
// a ledger, based on a REQUEST NUMBER.(Normally transactions use transaction numbers,
// and messages use request numbers. But in this case, it's a transaction that carries
// a copy of a message.)
//
// returns replyNotice transaction by requestNumber.
string OTAPI_Wrap::Nymbox_GetReplyNotice(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & REQUEST_NUMBER
	)
{
	if (SERVER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }
	if (0 > StringToLong(REQUEST_NUMBER))			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }

	const OTIdentifier theServerID(SERVER_ID);
	const OTIdentifier theUserID(USER_ID);

	const long lRequestNumber = static_cast<long>(StringToLong(REQUEST_NUMBER));

	// -----------------------------------------

	// There is an OT_ASSERT in here for memory failure,
	// but it still might return NULL if various verification fails.

	OTLedger * pLedger = OTAPI_Wrap::OTAPI()->LoadNymboxNoVerify(theServerID, theUserID); 
	// Make sure it gets cleaned up when this goes out of scope.
	OTCleanup<OTLedger>	theAngel(pLedger); // I pass the pointer, in case it's NULL.

	if (NULL == pLedger)
	{
		OTLog::sOutput(0, "%s: Failure calling OT_API::LoadNymboxNoVerify.\n", __FUNCTION__);
		return "";
	}
	// -----------------------------------

	OTTransaction * pTransaction = pLedger->GetReplyNotice(lRequestNumber);
	// No need to cleanup this transaction, the ledger owns it already.

	if (NULL == pTransaction)
	{
		OTLog::vOutput(4, "%s: No replyNotice transactions found in ledger with request number: %ld\n", __FUNCTION__, lRequestNumber);
		return ""; // Maybe he was just looking; this isn't necessarily an error.
	}
	// -----------------------------------

	// At this point, I actually have the transaction pointer to the replyNotice,
	// so let's return it in string form...
	//
	const long lTransactionNum = pTransaction->GetTransactionNum();

	// Update: for transactions in ABBREVIATED form, the string is empty, since it has never actually
	// been signed (in fact the whole point with abbreviated transactions in a ledger is that they 
	// take up very little room, and have no signature of their own, but exist merely as XML tags on
	// their parent ledger.)
	//
	// THEREFORE I must check to see if this transaction is abbreviated and if so, sign it in order to
	// force the UpdateContents() call, so the programmatic user of this API will be able to load it up.
	//

	OTString strOutput(*pTransaction); // First we grab the transaction as it is (the abbreviated version, possibly.)

	if (pTransaction->IsAbbreviated())
	{
		pLedger->LoadBoxReceipt(lTransactionNum); 
		pTransaction = pLedger->GetTransaction(lTransactionNum);
		// -------------------------
		if (NULL == pTransaction)
		{
			OTLog::sError("%s: good index but uncovered NULL pointer after trying to load full "
				"version of receipt (from abbreviated.) Thus, saving abbreviated version instead, "
				"so I can still return SOMETHING.\n", __FUNCTION__);
			// ----------------------------------
			OTPseudonym *  pNym(OTAPI_Wrap::OTAPI()->GetNym(theUserID, __FUNCTION__));
			if (NULL == pNym) return "";
			// -------------------------	
			pTransaction->ReleaseSignatures();
			pTransaction->SignContract(*pNym);
			pTransaction->SaveContract();
			// -------------------------
		}		
		strOutput.Release();
		pTransaction->SaveContractRaw(strOutput); // if it was abbreviated before, now it either IS the box receipt, or it's the abbreviated version.            
	}
	// ------------------------------------------------

	// We return the abbreviated version because the developer using the OT API
	// needs to know if that receipt is there, whether it's abbreviated or not.
	// So rather than passing NULL when it's abbreviated, and thus leading him
	// astray, we give him the next-best thing: the abbreviated version. That
	// way at least he knows for sure that the receipt is there, the one he is
	// asking about.

	return strOutput.Get(); 
}


// If the client-side has ALREADY seen the server's reply to a specific
// request number, he stores that number in a list which can be queried
// using this function. A copy of that list is sent with nearly every request
// message sent to the server. This way the server can see which replies you
// have already received. The server will mirror every number it sees(it sends
// its own list in all its replies.) Whenever you see a number mirrored in the
// server's reply, that means the server now knows you got its original reply
//(the one referenced by the number) and the server removed any replyNotice
// of that from your Nymbox(so you don't have to download it.) Basically that
// means you can go ahead and remove it from your list, and once you do, the server
// will remove its matching copy as well.
// When you are downloading your box receipts, you can skip any receipts where
// you have ALREADY seen the reply. So you can use this function to see if you already
// saw it, and if you did, then you can skip downloading that box receipt.
// Warning: this function isn't "perfect", in the sense that it cannot tell you definitively
// whether you have actually seen a server reply, but it CAN tell you if you have seen
// one until it finishes the above-described protocol(it will work in that way, which is
// how it was int32_tended.) But after that, it will no longer know if you got the reply since
// it has removed it from its list.
//
bool OTAPI_Wrap::HaveAlreadySeenReply(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & REQUEST_NUMBER
	)
{
	if (SERVER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }
	if (0 > StringToLong(REQUEST_NUMBER))		{ OTLog::sError("%s: Bad: %s passed in!\n", __FUNCTION__, "REQUEST_NUMBER"		); OT_ASSERT(false); }

	OTIdentifier theServerID(SERVER_ID);
	OTIdentifier theUserID(USER_ID);

	const long lRequestNumber = static_cast<long>(StringToLong(REQUEST_NUMBER));

	//  const char * szFunc = "OT_API_HaveAlreadySeenReply";
	// -----------------------------------------

	// There is an OT_ASSERT in here for memory failure,
	// but it still might return NULL if various verification fails.

	const bool bTemp = OTAPI_Wrap::OTAPI()->HaveAlreadySeenReply(theServerID, theUserID, lRequestNumber);

	return bTemp;
}

// The Nymbox/Inbox/Outbox only contain abbreviated receipts, with a hash for zero-knowledge
// proof of the entire receipt.(Messages were getting too big, it couldn't be helped. Sorry.)
// Once you download your nym/in/out/*box and load it int32_to memory from storage, you iterate through
// it and download all the box receipts(preferably only once.) Once you load those up, it's as if
// the various pieces were never sundered int32_to multiple files to begin with. Then you can verify
// the box and do all the normal operations.
//
/** How to use?
Call getInbox(say), and if successful, loadInbox().
*/
// Returns int32_t:
// -1 means error; no message was sent.
// -2 means the message was sent, but the request number must be passed as a string, so call GetLargeRequestNum.
// 0 means NO error, but also: no message was sent.
// >0 means NO error, and the message was sent, and the request number fits int32_to an int32_teger...
// ...and in fact the requestNum IS the return value!
// ===> In 99% of cases, this LAST option is what actually happens!!
//
int32_t OTAPI_Wrap::getBoxReceipt(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & ACCOUNT_ID, // If for Nymbox(vs inbox/outbox) then pass USER_ID in this field also.
	const int32_t & nBoxType, // 0/nymbox, 1/inbox, 2/outbox
	const string & TRANSACTION_NUMBER
	)
{
	if (SERVER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }
	if (ACCOUNT_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCOUNT_ID"			); OT_ASSERT(false); }

	if ( ! ( (0 == nBoxType)	|| (1 == nBoxType) || (2 == nBoxType) ) ){
		OTLog::vError("%s: nBoxType is of wrong type: value: %d\n", __FUNCTION__, nBoxType);
		OT_ASSERT(false);
	}

	if (0 > StringToLong(TRANSACTION_NUMBER))	{ OTLog::sError("%s: Bad: %s passed in!\n", __FUNCTION__, "TRANSACTION_NUMBER"	); OT_ASSERT(false); }

	const OTIdentifier	theServerID(SERVER_ID), theUserID(USER_ID), theAccountID(ACCOUNT_ID);
	const long			lTransactionNum = static_cast<long>(StringToLong(TRANSACTION_NUMBER));
	// --------------------------------------
	switch (nBoxType)
	{
	case 0:		// nymbox
	case 1:		// inbox
	case 2:		// outbox
		break;
	default:
		OTLog::vError("OT_API_getBoxReceipt: Error: bad nBoxType: %d for UserID: %s AcctID: %s"
			"(expected one of: 0/nymbox, 1/inbox, 2/outbox)\n", nBoxType, USER_ID.c_str(), ACCOUNT_ID.c_str());
		return -1;
	}

	return OTAPI_Wrap::OTAPI()->getBoxReceipt(theServerID,
		theUserID,
		theAccountID, // If for Nymbox (vs inbox/outbox) then pass USER_ID in this field also.						   
		nBoxType,	// 0/nymbox, 1/inbox, 2/outbox
		lTransactionNum);
}

//
bool OTAPI_Wrap::DoesBoxReceiptExist(
	const string & SERVER_ID,
	const string & USER_ID, // Unused here for now, but still convention.
	const string & ACCOUNT_ID, // If for Nymbox(vs inbox/outbox) then pass USER_ID in this field also.
	const int32_t & nBoxType, // 0/nymbox, 1/inbox, 2/outbox
	const string & TRANSACTION_NUMBER
	)
{

	if (SERVER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }
	if (ACCOUNT_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCOUNT_ID"			); OT_ASSERT(false); }

	if ( ! ( (0 == nBoxType)	|| (1 == nBoxType) || (2 == nBoxType) ) ){
		OTLog::vError("%s: nBoxType is of wrong type: value: %d\n", __FUNCTION__, nBoxType);
		OT_ASSERT(false);
	}

	if (0 > StringToLong(TRANSACTION_NUMBER))	{ OTLog::sError("%s: Bad: %s passed in!\n", __FUNCTION__, "TRANSACTION_NUMBER"	); OT_ASSERT(false); }


	const OTIdentifier	theServerID(SERVER_ID), theUserID(USER_ID), theAccountID(ACCOUNT_ID);
	const long			lTransactionNum = static_cast<long>(StringToLong(TRANSACTION_NUMBER));
	// --------------------------------------
	switch (nBoxType)
	{
	case 0:		// nymbox
	case 1:		// inbox
	case 2:		// outbox
		break;
	default:
		OTLog::vError("%s: Error: bad nBoxType: %d for UserID: %s AcctID: %s (expected one of: 0/nymbox, 1/inbox, 2/outbox)\n",
			__FUNCTION__, nBoxType, USER_ID.c_str(), ACCOUNT_ID.c_str());
		return false;
	}

	return OTAPI_Wrap::OTAPI()->DoesBoxReceiptExist(theServerID,
		theUserID,
		theAccountID, // If for Nymbox (vs inbox/outbox) then pass USER_ID in this field also.						   
		nBoxType,	// 0/nymbox, 1/inbox, 2/outbox
		lTransactionNum);
}

// --------------------------------------------------------------------------
/**
PROCESS INBOX

Assuming I have gone through the various transactions in my inbox,
and chosen some that I wish to accept or reject, this message asks
the server to accept or reject those transactions.

You must include a copy of the ledger, which contains your accept or
reject requests for the various inbox items. In other words, you will
need to use some other function call first to set up that ledger with
the various requests(accept transfer, accept receipt, etc) before you 
can then use THIS function call to actually send those requests to
the server.(See all the Ledger functions.)

(Try the 'i' command in the test client, if you want to empty out the
inbox and automatically accept all of the transactions within.)

*/
// Returns int32_t:
// -1 means error; no message was sent.
// -2 means the message was sent, but the request number must be passed as a string, so call GetLargeRequestNum.
// 0 means NO error, but also: no message was sent.
// >0 means NO error, and the message was sent, and the request number fits int32_to an int32_teger...
// ...and in fact the requestNum IS the return value!
// ===> In 99% of cases, this LAST option is what actually happens!!
//
int32_t OTAPI_Wrap::processInbox(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & ACCT_ID,
	const string & ACCT_LEDGER
	)
{
	if (SERVER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }
	if (ACCT_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCT_ID"			); OT_ASSERT(false); }
	if (ACCT_LEDGER.empty())		{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCT_LEDGER"		); OT_ASSERT(false); }

	OTLog::vOutput(0, "%s: \n"
		"SERVER_ID: %s \n"
		"USER_ID: %s \n"
		"ACCT_ID: %s \n"
		"ACCT_LEDGER:\n%s\n\n",
		__FUNCTION__, SERVER_ID.c_str(), USER_ID.c_str(), ACCT_ID.c_str(), ACCT_LEDGER.c_str());

	OTIdentifier    theServerID(SERVER_ID), theUserID(USER_ID), theAcctID(ACCT_ID);
	OTString        strLedger(ACCT_LEDGER);

	OTString temp1(SERVER_ID), temp2(USER_ID), temp3(ACCT_ID), temp4(ACCT_LEDGER);
	OTLog::vOutput(0,  "%s: \n"
		"\n\nSERVER_ID: %s \n"
		"USER_ID: %s \n"
		"ACCT_ID: %s \n"
		"ACCT_LEDGER:\n%s\n\n",
		__FUNCTION__, temp1.Get(), temp2.Get(), temp3.Get(), temp4.Get());

	return OTAPI_Wrap::OTAPI()->processInbox(theServerID, theUserID, theAcctID, strLedger);
}

// I use this automatically to save the API developers the hassle(for now)
// added here for completeness.
// UPDATE: It was a mistake for me to automatically call this, which can 
// mess up the client's expectation of which messages are being sent/received.
// It was causing network problems. Now clients NEED to call this themselves,
// after getting the Nymbox. I can't call it for them anymore.
//
// Returns:
// -1 if error.
// 0 if Nymbox is empty.
// 1 or more: Count of items in Nymbox before processing.
//

int32_t OTAPI_Wrap::processNymbox(
	const string & SERVER_ID,
	const string & USER_ID
	)
{
	if (SERVER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }

	OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID);

	return OTAPI_Wrap::OTAPI()->processNymbox(theServerID, theUserID);
}


// --------------------------------------------------------------------------
// WITHDRAW VOUCHER -- aka CASHIER'S CHEQUE.
//
// This is VERY similar to withdrawing cash, except the server gives you
// a voucher instead of cash. It's the same thing as a CASHIER'S CHEQUE...
//
// Basically the funds are moved int32_to an int32_ternal server account, and then
// the server gives you a cheque drawn on its own account. This way you can
// use it like a cheque, but it will never bounce.
//
// Returns int32_t:
// -1 means error; no message was sent.
// -2 means the message was sent, but the request number must be passed as a string, so call GetLargeRequestNum.
// 0 means NO error, but also: no message was sent.
// >0 means NO error, and the message was sent, and the request number fits int32_to an int32_teger...
// ...and in fact the requestNum IS the return value!
// ===> In 99% of cases, this LAST option is what actually happens!!
//
int32_t OTAPI_Wrap::withdrawVoucher(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & ACCT_ID,
	const string & RECIPIENT_USER_ID,
	const string & CHEQUE_MEMO,
	const string & AMOUNT
	)
{
	if (SERVER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }
	if (ACCT_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCT_ID"			); OT_ASSERT(false); }
	if (RECIPIENT_USER_ID.empty())	{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "RECIPIENT_USER_ID"	); OT_ASSERT(false); }
	if (CHEQUE_MEMO.empty())		{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "CHEQUE_MEMO"		); OT_ASSERT(false); }
	if (0 > StringToLong(AMOUNT))	{ OTLog::sError("%s: Bad: %s passed in!\n", __FUNCTION__, "AMOUNT"				); OT_ASSERT(false); }


	OTIdentifier	theServerID(SERVER_ID),	theUserID(USER_ID), 
		theAcctID(ACCT_ID),		theRecipientUserID(RECIPIENT_USER_ID);

	OTString strMemo(CHEQUE_MEMO);

	return OTAPI_Wrap::OTAPI()->withdrawVoucher(theServerID, theUserID, theAcctID, theRecipientUserID, strMemo, static_cast<long>(StringToLong(AMOUNT)));
}
// --------------------------------------------------

// PAY DIVIDEND -- to shareholders
//
int32_t OTAPI_Wrap::payDividend(
	const string & SERVER_ID,
	const string & ISSUER_USER_ID, // must be issuer of SHARES_ASSET_TYPE_ID
	const string & DIVIDEND_FROM_ACCT_ID, // if dollars paid for pepsi shares, then this is the issuer's dollars account.
	const string & SHARES_ASSET_TYPE_ID, // if dollars paid for pepsi shares, then this is the pepsi shares asset type id.
	const string & DIVIDEND_MEMO, // user-configurable note that's added to the payout request message.
	const string & AMOUNT_PER_SHARE // number of dollars to be paid out PER SHARE(multiplied by total number of shares issued.)
	)
{
	if (SERVER_ID.empty())				{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"				); OT_ASSERT(false); }
	if (ISSUER_USER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "ISSUER_USER_ID"			); OT_ASSERT(false); }
	if (DIVIDEND_FROM_ACCT_ID.empty())	{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "DIVIDEND_FROM_ACCT_ID"	); OT_ASSERT(false); }
	if (SHARES_ASSET_TYPE_ID.empty())	{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "SHARES_ASSET_TYPE_ID"	); OT_ASSERT(false); }
	if (DIVIDEND_MEMO.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "DIVIDEND_MEMO"			); OT_ASSERT(false); }
	if (0 > StringToLong(AMOUNT_PER_SHARE))			{ OTLog::sError("%s: Bad: %s passed in!\n", __FUNCTION__, "AMOUNT_PER_SHARE"		); OT_ASSERT(false); }

	OTIdentifier	theServerID           (SERVER_ID),                         
		theIssuerUserID       (ISSUER_USER_ID), 
		theDividendFromAcctID (DIVIDEND_FROM_ACCT_ID),	
		theSharesAssetTypeID  (SHARES_ASSET_TYPE_ID);

	OTString  strMemo  (DIVIDEND_MEMO);

	return OTAPI_Wrap::OTAPI()->payDividend(theServerID, 
		theIssuerUserID, 
		theDividendFromAcctID, 
		theSharesAssetTypeID, 
		strMemo, 
		static_cast<long>(StringToLong(AMOUNT_PER_SHARE)));
}

// --------------------------------------------------



// --------------------------------------------------------------------------
// DEPOSIT A CHEQUE(or VOUCHER) int32_tO AN ASSET ACCOUNT.
//
// If someone gives you a cheque, you can use this function to message the
// server asking it to deposit the cheque int32_to one of your asset accounts.
//(Of course the account and the cheque must be the same asset type.)
//
// Since a voucher is simply a cheque drawn on an int32_ternal server account,
// you can deposit a voucher the same as any other cheque.
//
// Returns int32_t:
// -1 means error; no message was sent.
// -2 means the message was sent, but the request number must be passed as a string, so call GetLargeRequestNum.
// 0 means NO error, but also: no message was sent.
// >0 means NO error, and the message was sent, and the request number fits int32_to an int32_teger...
// ...and in fact the requestNum IS the return value!
// ===> In 99% of cases, this LAST option is what actually happens!!
//
int32_t OTAPI_Wrap::depositCheque(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & ACCT_ID,
	const string & THE_CHEQUE
	)
{
	if (SERVER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }
	if (ACCT_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCT_ID"			); OT_ASSERT(false); }
	if (THE_CHEQUE.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_CHEQUE"			); OT_ASSERT(false); }

	OTIdentifier theServerID(SERVER_ID), 
		theUserID(USER_ID), 
		theAcctID(ACCT_ID);

	OTString     strCheque(THE_CHEQUE);

	return OTAPI_Wrap::OTAPI()->depositCheque(theServerID, theUserID, theAcctID, strCheque);
}
// --------------------------------------------------





// --------------------------------------------------
// DEPOSIT(ACTIVATE) PAYMENT PLAN
//
// See ProposePaymentPlan / ConfirmPaymentPlan as well.
//
// Returns int32_t:
// -1 means error; no message was sent.
// -2 means the message was sent, but the request number must be passed as a string, so call GetLargeRequestNum.
// 0 means NO error, but also: no message was sent.
// >0 means NO error, and the message was sent, and the request number fits int32_to an int32_teger...
// ...and in fact the requestNum IS the return value!
// ===> In 99% of cases, this LAST option is what actually happens!!
//
int32_t OTAPI_Wrap::depositPaymentPlan(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & THE_PAYMENT_PLAN
	)
{
	if (SERVER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }
	if (THE_PAYMENT_PLAN.empty())	{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_PAYMENT_PLAN"	); OT_ASSERT(false); }

	const OTIdentifier	theServerID(SERVER_ID), theUserID(USER_ID);
	const OTString		strPlan(THE_PAYMENT_PLAN);

	return OTAPI_Wrap::OTAPI()->depositPaymentPlan(theServerID, theUserID, strPlan);	
}
// --------------------------------------------------





// --------------------------------------------------
// ISSUE MARKET OFFER
//
// Returns int32_t:
// -1 means error; no message was sent.
// -2 means the message was sent, but the request number must be passed as a string, so call GetLargeRequestNum.
// 0 means NO error, but also: no message was sent.
// >0 means NO error, and the message was sent, and the request number fits int32_to an int32_teger...
// ...and in fact the requestNum IS the return value!
// ===> In 99% of cases, this LAST option is what actually happens!!
//

int32_t OTAPI_Wrap::issueMarketOffer(
		const string & SERVER_ID,
		const string & USER_ID,
		// -------------------------------------------
		const string & ASSET_TYPE_ID, // Perhaps this is the
		const string & ASSET_ACCT_ID, // wheat market.
		// -------------------------------------------
		const string & CURRENCY_TYPE_ID, // Perhaps I'm buying the
		const string & CURRENCY_ACCT_ID, // wheat with rubles.
		// -------------------------------------------
		const string & MARKET_SCALE, // Defaults to minimum of 1. Market granularity.
		const string & MINIMUM_INCREMENT, // This will be multiplied by the Scale. Min 1.
		const string & TOTAL_ASSETS_ON_OFFER, // Total assets available for sale or purchase. Will be multiplied by minimum increment.
		const string & PRICE_LIMIT, // Per Minimum Increment...

		const bool & bBuyingOrSelling // Actually OT_BOOL. SELLING == OT_TRUE, BUYING == OT_FALSE.
		)
{
	if (SERVER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }
	if (ASSET_TYPE_ID.empty())		{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "ASSET_TYPE_ID"		); OT_ASSERT(false); }
	if (ASSET_ACCT_ID.empty())		{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "ASSET_ACCT_ID"		); OT_ASSERT(false); }
	if (CURRENCY_TYPE_ID.empty())	{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "CURRENCY_TYPE_ID"	); OT_ASSERT(false); }
	if (CURRENCY_ACCT_ID.empty())	{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "CURRENCY_ACCT_ID"	); OT_ASSERT(false); }
	if (MARKET_SCALE.empty())		{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "MARKET_SCALE"		); OT_ASSERT(false); }
	if (MINIMUM_INCREMENT.empty())	{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "MINIMUM_INCREMENT"	); OT_ASSERT(false); }
	if (TOTAL_ASSETS_ON_OFFER.empty()){ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "TOTAL_ASSETS_ON_OFFER"); OT_ASSERT(false); }
	if (PRICE_LIMIT.empty())		{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "PRICE_LIMIT"	); OT_ASSERT(false); }

	const OTIdentifier	theServerID(SERVER_ID), theUserID(USER_ID),
		theAssetTypeID(ASSET_TYPE_ID), theAssetAcctID(ASSET_ACCT_ID),
		theCurrencyTypeID(CURRENCY_TYPE_ID), theCurrencyAcctID(CURRENCY_ACCT_ID);

	long lMarketScale = 1, lMinIncrement = 1, lTotalAssetsOnOffer = 1, lPriceLimit = 1;

	if (0 < StringToLong(MARKET_SCALE)) lMarketScale					= static_cast<long>(StringToLong(MARKET_SCALE));
	if (0 < StringToLong(MINIMUM_INCREMENT)) lMinIncrement			= static_cast<long>(StringToLong(MINIMUM_INCREMENT));
	if (0 < StringToLong(TOTAL_ASSETS_ON_OFFER)) lTotalAssetsOnOffer	= static_cast<long>(StringToLong(TOTAL_ASSETS_ON_OFFER));
	if (0 < StringToLong(PRICE_LIMIT)) lPriceLimit					= static_cast<long>(StringToLong(PRICE_LIMIT));

	return OTAPI_Wrap::OTAPI()->issueMarketOffer(theServerID, theUserID,
		// -------------------------------------------
		theAssetTypeID, theAssetAcctID,
		theCurrencyTypeID, theCurrencyAcctID,
		// -------------------------------------------
		lMarketScale, lMinIncrement, lTotalAssetsOnOffer, lPriceLimit,
		bBuyingOrSelling);	

}

int32_t OTAPI_Wrap::issueMarketOffer_chai(
	const string & SERVER_ID,
	const string & USER_ID,
	// -------------------------------------------
	const string & ASSET_TYPE_ID, // Perhaps this is the
	const string & ASSET_ACCT_ID, // wheat market.
	// -------------------------------------------
	const string & CURRENCY_TYPE_ID, // Perhaps I'm buying the
	const string & CURRENCY_ACCT_ID, // wheat with rubles.
	// -------------------------------------------
	const vector<string> & nValues,
	//const string & MARKET_SCALE, // Defaults to minimum of 1. Market granularity.
	//const string & MINIMUM_INCREMENT, // This will be multiplied by the Scale. Min 1.
	//const string & TOTAL_ASSETS_ON_OFFER, // Total assets available for sale or purchase. Will be multiplied by minimum increment.
	//const string & PRICE_LIMIT, // Per Minimum Increment...
	const bool & bBuyingOrSelling // Actually OT_BOOL. SELLING == OT_TRUE, BUYING == OT_FALSE.
	)
{
	if (nValues.empty())			{ OTLog::sError("%s: Bad: %s passed in!\n", __FUNCTION__, "nValues"		); OT_ASSERT(false); }
	if (3 != nValues.size())		{ OTLog::sError("%s: Bad: %s passed in!\n", __FUNCTION__, "nValues"		); OT_ASSERT(false); }

	return issueMarketOffer(SERVER_ID,USER_ID,ASSET_TYPE_ID,ASSET_ACCT_ID,CURRENCY_TYPE_ID,CURRENCY_ACCT_ID,nValues[0],nValues[1],nValues[2],nValues[3],bBuyingOrSelling);
}


// --------------------------------------------------




/*

What objects are actually stored in local storage after a successful server call?

A "MarketList", which contains a list of Market Datas. Load this up and you can get 
point32_ters to the elements as needed. THERE IS ONLY ONE OF THESE.

An "OfferList" which contains "all" offers for a specific Market ID. There may be
many markets, so this should be saved by Server / Asset / User the same as Purses.
If you load this object, you can loop through its offers. I don't think a sub-object
is necessary here since the data is so simple.

A "TradeList" which contains "all" trades for a specific Market ID. There many be
many markets, so this should be saved Server/Asset/User the same as purses.
If you load this object you can loop through the trades, which again, no sub-object
needed since the data here is so simple. But we shall see!

A "NymOfferList" which contains all offers for a specific nym. Unlike the above offers,
these offers are full-featured and should contain a LOT more details.

*/


// Retrieves details for each market.
//
// Returns int32_t:
// -1 means error; no message was sent.
// -2 means the message was sent, but the request number must be passed as a string, so call GetLargeRequestNum.
// 0 means NO error, but also: no message was sent.
// >0 means NO error, and the message was sent, and the request number fits int32_to an int32_teger...
// ...and in fact the requestNum IS the return value!
// ===> In 99% of cases, this LAST option is what actually happens!!
//
int32_t OTAPI_Wrap::getMarketList(
	const string & SERVER_ID,
	const string & USER_ID
	)
{
	if (SERVER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }

	const OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID);

	return OTAPI_Wrap::OTAPI()->getMarketList(theServerID, theUserID);
}

// Gets all offers for a specific market and their details(up until maximum depth)
// Returns int32_t:
// -1 means error; no message was sent.
// -2 means the message was sent, but the request number must be passed as a string, so call GetLargeRequestNum.
// 0 means NO error, but also: no message was sent.
// >0 means NO error, and the message was sent, and the request number fits int32_to an int32_teger...
// ...and in fact the requestNum IS the return value!
// ===> In 99% of cases, this LAST option is what actually happens!!
//
int32_t OTAPI_Wrap::getMarketOffers(
	const string & SERVER_ID,
	const string & USER_ID, 
	const string & MARKET_ID,
	const string & MAX_DEPTH // Market Depth
	)
{
	if (SERVER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }
	if (0 > StringToLong(MAX_DEPTH))				{ OTLog::sError("%s: Bad: %s passed in!\n", __FUNCTION__, "MAX_DEPTH"			); OT_ASSERT(false); }

	const OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theMarketID(MARKET_ID);

	const long lDepth = static_cast<long>(StringToLong(MAX_DEPTH));

	return OTAPI_Wrap::OTAPI()->getMarketOffers(theServerID, theUserID, theMarketID, lDepth);
}

// Gets all recent trades(up until maximum depth)
// Returns int32_t:
// -1 means error; no message was sent.
// -2 means the message was sent, but the request number must be passed as a string, so call GetLargeRequestNum.
// 0 means NO error, but also: no message was sent.
// >0 means NO error, and the message was sent, and the request number fits int32_to an int32_teger...
// ...and in fact the requestNum IS the return value!
// ===> In 99% of cases, this LAST option is what actually happens!!
//
int32_t OTAPI_Wrap::getMarketRecentTrades(
	const string & SERVER_ID,
	const string & USER_ID, 
	const string & MARKET_ID
	)
{
	if (SERVER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }
	if (MARKET_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "MARKET_ID"			); OT_ASSERT(false); }

	const OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theMarketID(MARKET_ID);

	return OTAPI_Wrap::OTAPI()->getMarketRecentTrades(theServerID, theUserID, theMarketID);
}

// This "Market Offer" data is a lot more detailed than the Market_GetOffers() call, which seems similar otherwise.
// Returns int32_t:
// -1 means error; no message was sent.
// -2 means the message was sent, but the request number must be passed as a string, so call GetLargeRequestNum.
// 0 means NO error, but also: no message was sent.
// >0 means NO error, and the message was sent, and the request number fits int32_to an int32_teger...
// ...and in fact the requestNum IS the return value!
// ===> In 99% of cases, this LAST option is what actually happens!!
//
int32_t OTAPI_Wrap::getNym_MarketOffers(
	const string & SERVER_ID,
	const string & USER_ID // Offers this Nym has out on market.
	)
{
	if (SERVER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }

	const OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID);

	return OTAPI_Wrap::OTAPI()->getNym_MarketOffers(theServerID, theUserID);
}
// These may just be the Cron Receipts...





// Returns int32_t:
// -1 means error; no message was sent.
// -2 means the message was sent, but the request number must be passed as a string, so call GetLargeRequestNum.
// 0 means NO error, but also: no message was sent.
// >0 means NO error, and the message was sent, and the request number fits int32_to an int32_teger...
// ...and in fact the requestNum IS the return value!
// ===> In 99% of cases, this LAST option is what actually happens!!
//
int32_t OTAPI_Wrap::cancelMarketOffer(
	const string & SERVER_ID, 
	const string & USER_ID, 
	const string & ASSET_ACCT_ID, 
	const string & TRANSACTION_NUMBER
	)
{
	if (SERVER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }
	if (ASSET_ACCT_ID.empty())		{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "ASSET_ACCT_ID"		); OT_ASSERT(false); }
	if (0 > StringToLong(TRANSACTION_NUMBER))		{ OTLog::sError("%s: Bad: %s passed in!\n", __FUNCTION__, "TRANSACTION_NUMBER"	); OT_ASSERT(false); }

	const long lTransactionNumber = static_cast<long>(StringToLong(TRANSACTION_NUMBER));

	const OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theAssetAcctID(ASSET_ACCT_ID);

	return OTAPI_Wrap::OTAPI()->cancelCronItem(theServerID, theUserID, theAssetAcctID, lTransactionNumber);	
}

// Returns int32_t:
// -1 means error; no message was sent.
// -2 means the message was sent, but the request number must be passed as a string, so call GetLargeRequestNum.
// 0 means NO error, but also: no message was sent.
// >0 means NO error, and the message was sent, and the request number fits int32_to an int32_teger...
// ...and in fact the requestNum IS the return value!
// ===> In 99% of cases, this LAST option is what actually happens!!
//
int32_t OTAPI_Wrap::cancelPaymentPlan(
	const string & SERVER_ID, 
	const string & USER_ID, 
	const string & FROM_ACCT_ID, 
	const string & TRANSACTION_NUMBER
	)
{
	if (SERVER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }
	if (FROM_ACCT_ID.empty())		{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "FROM_ACCT_ID"		); OT_ASSERT(false); }
	if (0 > StringToLong(TRANSACTION_NUMBER))		{ OTLog::sError("%s: Bad: %s passed in!\n", __FUNCTION__, "TRANSACTION_NUMBER"	); OT_ASSERT(false); }

	const long lTransactionNumber = static_cast<long>(StringToLong(TRANSACTION_NUMBER));

	const OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theFromAcctID(FROM_ACCT_ID);

	return OTAPI_Wrap::OTAPI()->cancelCronItem(theServerID, theUserID, theFromAcctID, lTransactionNumber);	
}





// -----------------------------------------------------------
// POP MESSAGE BUFFER
// 
// If there are any replies from the server, they are stored in
// the message buffer. This function will return those messages
//(and remove them from the list) one-by-one, newest first.
//
// Returns the message as a string.
//

// Update: added arguments for: ServerID AND NymID AND request number
// NOTE: Any messages, when popping, which have the CORRECT serverID
// and the CORRECT NymID, but the wrong Request number, will be discarded.
//
//(Why? Because the client using the OT API will have already treated
// that message as "dropped" by now, if it's already on to the next one,
// and the protocol is designed to move forward properly based specifically
// on this function returning the one EXPECTED... outgoing messages flush
// the incoming buffer anyway, so the client will have assumed the wrong
// reply was flushed by now anyway.)
// 
// However, if the Server ID and the User ID are wrong, this just means that
// some other code is still expecting that reply, and hasn't even popped yet!
// Therefore, we do NOT want to discard THOSE replies, but put them back if
// necessary -- only discarding the ones where the IDs match.
//
string OTAPI_Wrap::PopMessageBuffer(
	const string & REQUEST_NUMBER,
	const string & SERVER_ID, 
	const string & USER_ID
	)
{
	if (0 > StringToLong(REQUEST_NUMBER))			{ OTLog::sError("%s: Bad: %s passed in!\n", __FUNCTION__, "REQUEST_NUMBER"		); OT_ASSERT(false); }
	if (SERVER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }

	// ------------------------------------------------    
	const long          lRequestNum = static_cast<long>(StringToLong(REQUEST_NUMBER));
	const OTIdentifier  theServerID(SERVER_ID),
		theUserID(USER_ID);
	// ------------------------------------------------
	std::tr1::shared_ptr<OTMessage> pMsg(OTAPI_Wrap::OTAPI()->PopMessageBuffer(lRequestNum, theServerID, theUserID)); // caller responsible to delete.

	if (NULL == pMsg) // The buffer was empty.
	{
		OTLog::sError("%s:  Reply not found, sorry.\n", __FUNCTION__);
		return "";
	}

	const OTString strOutput(*pMsg);

	return strOutput.Get(); 	
}

void OTAPI_Wrap::FlushMessageBuffer(void)
{
	OTAPI_Wrap::OTAPI()->FlushMessageBuffer();
}


// Outgoing:

string OTAPI_Wrap::GetSentMessage(
	const string & REQUEST_NUMBER,
	const string & SERVER_ID, 
	const string & USER_ID
	)
{	
	if (0 > StringToLong(REQUEST_NUMBER))			{ OTLog::sError("%s: Bad: %s passed in!\n", __FUNCTION__, "REQUEST_NUMBER"		); OT_ASSERT(false); }
	if (SERVER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }
	// ------------------------------------------------    
	const long          lRequestNum = static_cast<long>(StringToLong(REQUEST_NUMBER));
	const OTIdentifier  theServerID(SERVER_ID),
		theUserID(USER_ID);
	// ------------------------------------------------
	std::shared_ptr<OTMessage>  pMsg(OTAPI_Wrap::OTAPI()->GetSentMessage(lRequestNum, theServerID, theUserID)); 

	if (NULL == pMsg) // The message wasn't found with that request number.
	{
		OTLog::vOutput(0, "%s: Message not found with request number %ld, sorry.\n", __FUNCTION__, lRequestNum);
		return "";
	}
	// ------------------------------------------------
	const OTString strOutput(*pMsg); // No need to cleanup the message since it's still in the buffer until explicitly removed.

	return strOutput.Get(); 	
}

bool OTAPI_Wrap::RemoveSentMessage(
	const string & REQUEST_NUMBER,
	const string & SERVER_ID, 
	const string & USER_ID
	)
{	
	if (0 > StringToLong(REQUEST_NUMBER))		{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "REQUEST_NUMBER"		); OT_ASSERT(false); }
	if (SERVER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }
	// ------------------------------------------------    
	const long          lRequestNum = static_cast<long>(StringToLong(REQUEST_NUMBER));
	const OTIdentifier  theServerID(SERVER_ID),
		theUserID(USER_ID);
	// ------------------------------------------------
	return OTAPI_Wrap::OTAPI()->RemoveSentMessage(lRequestNum, theServerID, theUserID);
}

// Note: Might remove this from API. Basically, the sent messages queue must store
// messages(by request number) until we know for SURE whether we have a success, a failure,
// or a lost/rejected message. That is, until we DOWNLOAD the Nymbox, and thus know for SURE
// that a response to a given message is there...or not. Why do we care? For making this 
// choice:
//
// Messages that DO have a reply are therefore already "in the system" and will be handled
// normally--they can be ignored and flushed from the "sent messages" queue. Whereas messages
// that do NOT have a reply in the Nymbox(yet are still in the "sent messages" queue) can be
// assumed safely to have been rejected at "message level"(before any transaction could
// have processed) and the reply must have been dropped on the network, OR the server never
// even received the message in the first place. EITHER WAY the trans #s can be harvested
// accordingly and then removed from the sent buffer. In a perfect world(read: iteration 2)
// these sent messages will be serialized somehow along with the Nym, and not just stored in 
// RAM like this version does.
//
// -----------------------------------------------------------
// FlushSentMessages
//
// Make sure to call this directly after a successful @getNymbox.
//(And ONLY at that time.)
//
// This empties the buffer of sent messages.
//(Harvesting any transaction numbers that are still there.)
//
// NOTE: You normally ONLY call this immediately after receiving
// a successful @getNymbox. It's only then that you can see which
// messages a server actually received or not -- which transactions
// it processed(success or fail) vs which transactions did NOT
// process(and thus did NOT leave any success/fail receipt in the
// nymbox.)
//
// I COULD have just flushed myself IN the @getNymbox code(where
// the reply is processed.) But then the developer using the OT API
// would never have the opportunity to see whether a message was
// replied to, and harvest it for himself(say, just before attempting
// a re-try, which I plan to do in the high-level Java API, which is
// why I'm coding it this way.)
//
// This way, he can do that if he wishes, THEN call this function,
// and harvesting will still occur properly, and he will also thus have
// his chance to check for his own replies to harvest before then.
// This all depends on the developer using the API being smart enough
// to call this function after a successful @getNymbox!
//
void OTAPI_Wrap::FlushSentMessages(
	const bool & bHarvestingForRetry, // bHarvestingForRetry is actually OT_BOOL
	const string & SERVER_ID, 
	const string & USER_ID,
	const string & THE_NYMBOX
	)
{
	if (SERVER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }
	if (THE_NYMBOX.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_NYMBOX"			); OT_ASSERT(false); }

	// ------------------------------------------------    
	const OTIdentifier  theServerID(SERVER_ID),
		theUserID(USER_ID);
	const OTString      strLedger(THE_NYMBOX);
	OTLedger      theLedger(theUserID, theUserID, theServerID);
	// ------------------------------------------------
	if (strLedger.Exists() && theLedger.LoadContractFromString(strLedger)) {
		OTAPI_Wrap::OTAPI()->FlushSentMessages(
			bHarvestingForRetry,
			theServerID,
			theUserID,
			theLedger
			);
	}
	else
		OTLog::sError("%s: Failure: Unable to load Nymbox from string:\n\n%s\n\n", __FUNCTION__, strLedger.Get());
}




// --------------------------------------------------------------------
/** SLEEP

If you want to go to sleep for one second, then pass "1000" to this function.

*/
void OTAPI_Wrap::Sleep(const string & MILLISECONDS)
{
	// -----------------------------------------------------
	bool bInitialized = OTAPI_Wrap::OTAPI()->IsInitialized();
	if (!bInitialized) { OTLog::sError("%s: Not initialized; call OT_API::Init first.\n",__FUNCTION__);	OT_ASSERT(false); }

	if (0 >= StringToLong(MILLISECONDS))		{ OTLog::sError("%s: Bad: %s passed in!\n", __FUNCTION__, "MILLISECONDS"		); OT_ASSERT(false); }
	// -----------------------------------------------

	const long lMilliseconds = static_cast<long>(StringToLong(MILLISECONDS));

	OTLog::SleepMilliseconds(lMilliseconds);
}

//void OTAPI_Wrap::Sleep(const string & MILLISECONDS)
//{
//	// -----------------------------------------------------
//	bool bInitialized = OTAPI_Wrap::OTAPI()->IsInitialized();
//	if (!bInitialized) { OTLog::sError("%s: Not initialized; call OT_API::Init first.\n",__FUNCTION__);	OT_ASSERT(false); }
//
//	//if (MILLISECONDS.empty())		{ OTLog::sError("%s: Bad: %s passed in!\n", __FUNCTION__, "MILLISECONDS"		); OT_ASSERT(false); }
//	// -----------------------------------------------
//
//	//const long lMilliseconds = static_cast<long>(MILLISECONDS);
//
//	OTLog::SleepMilliseconds(50);
//}





/* For emergency/testing use only. This call forces you to trust the server.
You should never need to call this for any normal use, and hopefully
you should never need to actually call it at all, ever. But if your Nym
ever gets out of sync with the server, this will resync it based on 
the server's version of the data.

*/

// Make sure you download your Nymbox(getNymbox) before calling this,
// so when it loads the Nymbox it will have the latest version of it.
//
// Also, call createUserAccount() and pass the server reply message in
// here, so that it can read theMessageNym(to sync the transaction
// numbers.)
//
bool OTAPI_Wrap::ResyncNymWithServer(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & THE_MESSAGE
	)
{
	// -----------------------------------------------------
	bool bInitialized = OTAPI_Wrap::OTAPI()->IsInitialized();
	if (!bInitialized) { OTLog::sError("%s: Not initialized; call OT_API::Init first.\n",__FUNCTION__);	OT_ASSERT(false); }

	if (SERVER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }
	if (THE_MESSAGE.empty())		{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_MESSAGE"		); OT_ASSERT(false); }
	// -----------------------------------------------


	OTIdentifier	theServerID(SERVER_ID), theNymID(USER_ID);
	const OTString	strMessage(THE_MESSAGE), strNymID(theNymID);

	// -----------------------------------------------------
	OTPseudonym *  pNym(OTAPI_Wrap::OTAPI()->GetOrLoadPrivateNym(theNymID));
	if (NULL == pNym) return false;
	// -----------------------------------------------------------------
	OTMessage theMessage;

	if (false == theMessage.LoadContractFromString(strMessage))
	{
		OTLog::sError("%s: Failed trying to load @createUserAccount() message from string (it's a server reply.) Contents:\n\n%s\n\n", __FUNCTION__, strMessage.Get());
		return false;
	}
	// -----------------------------------------------------------------
	if (false == strNymID.Compare(theMessage.m_strNymID))
	{
		OTLog::sError("%s: Failed. Though success loading message from string, it had the wrong NymID. "
			"(Expected %s, but found %s.) Message contents:\n\n%s\n\n", __FUNCTION__,
			strNymID.Get(), theMessage.m_strNymID.Get(), strMessage.Get());
		return false;
	}
	// -----------------------------------------------------------------
	if (false == theMessage.m_strCommand.Compare("@createUserAccount"))
	{
		OTLog::sError("%s: Failed. Though success loading message from string, it had the wrong command type. "
			"(Expected @createUserAccount, but found %s.) Message contents:\n\n%s\n\n", __FUNCTION__,
			theMessage.m_strCommand.Get(), strMessage.Get());
		return false;
	}
	// -----------------------------------------------------------------
	if (false == theMessage.m_ascPayload.Exists())
	{
		OTLog::sError("%s: Failed. Though success loading @createUserAccount() message, the payload was empty. "
			"(Expected theMessageNym to be there, so I could re-sync client side to server.) Message contents:\n\n%s\n\n", __FUNCTION__, strMessage.Get());
		return false;
	}
	// -----------------------------------------------------------------
	OTString strMessageNym;

	if (false == theMessage.m_ascPayload.GetString(strMessageNym))
	{
		OTLog::sError("%s: Failed decoding message payload in server reply: @createUserAccount(). "
			"(Expected theMessageNym to be there, so I could re-sync client side to server.) Message contents:\n\n%s\n\n", __FUNCTION__, strMessage.Get());
		return false;
	}
	// -----------------------------------------------------------------
	OTPseudonym theMessageNym; // <====================

	if (false == theMessageNym.LoadFromString(strMessageNym))
	{
		OTLog::sError("%s: Failed loading theMessageNym from a string. String contents:\n\n%s\n\n", __FUNCTION__, strMessageNym.Get());
		return false;
	}
	// -----------------------------------------------------------------
	// Based on serverID and UserID, load the Nymbox.
	//
	OTLedger theNymbox(theNymID, theNymID, theServerID); // <===========

	bool bSynced		= false;
	bool bLoadedNymbox	= (theNymbox.LoadNymbox() && theNymbox.VerifyAccount(*pNym));

	if (bLoadedNymbox)
		bSynced = OTAPI_Wrap::OTAPI()->ResyncNymWithServer(*pNym, theNymbox, theMessageNym);
	else
		OTLog::sError("%s: Failed while loading or verifying Nymbox for User %s, on Server %s \n", __FUNCTION__, strNymID.Get(), SERVER_ID);
	// -----------------------------------------------------------------

	return bSynced;
}



// -----------------------------------------------------------
// GET MESSAGE COMMAND TYPE
//
// This way you can discover what kind of command it was.
// All server replies are pre-pended with the @ sign. For example, if
// you send a "getAccount" message, the server reply is "@getAccount",
// and if you send "getMint32_t" the reply is "@getMint32_t", and so on.
//
string OTAPI_Wrap::Message_GetCommand(const string & THE_MESSAGE)
{
	if (THE_MESSAGE.empty())		{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_MESSAGE"		); OT_ASSERT(false); }

	OTString strMessage(THE_MESSAGE);

	OTMessage theMessage;

	if (!strMessage.Exists() || !theMessage.LoadContractFromString(strMessage))
		return "";

	OTString strOutput(theMessage.m_strCommand);

	return strOutput.Get(); 			
}



// -----------------------------------------------------------
// GET MESSAGE SUCCESS(True or False)
//
// Returns TRUE for Success and FALSE for Failure.
// Also returns FALSE for error.
//
int32_t OTAPI_Wrap::Message_GetSuccess(const string & THE_MESSAGE)
{
	if (THE_MESSAGE.empty())		{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_MESSAGE"		); OT_ASSERT(false); }

	OTMessage   theMessage;
	OTString    strMessage(THE_MESSAGE);

	if (!strMessage.Exists())
	{
		OTLog::sError("%s: Error: THE_MESSAGE doesn't exist.\n", __FUNCTION__);
		return -1;
	}

	if (!theMessage.LoadContractFromString(strMessage))
	{
		OTLog::sError("%s: Error: Failed loading message from string:\n\n%s\n\n", __FUNCTION__, THE_MESSAGE);
		return -1;
	}
	// ---------------------------------------------
	if (true == theMessage.m_bSuccess)
	{
		OTLog::sOutput(0, "%s: ** FYI, server reply was received, and "
			"it said 'Yes.' (Status = success). RequestNum: %s\n",// Contents: \n\n%s\n\n",  
			__FUNCTION__, theMessage.m_strRequestNum.Get());//, THE_MESSAGE);
		return 1;
	}
	else
	{
		OTLog::sError("%s: ** FYI, server reply was received, and "
			"it said 'No.' (Status = failed). RequestNum: %s\n",// Contents: \n\n%s\n\n", 
			__FUNCTION__, theMessage.m_strRequestNum.Get());//, THE_MESSAGE);
	}
	return 0;
}




// -----------------------------------------------------------
// QUERY ASSET TYPES(server message)
//
// This way you can ask the server to confirm whether various
// asset types are issued there.
//
// Returns int32_t:
// -1 means error; no message was sent.
// -2 means the message was sent, but the request number must be passed as a string, so call GetLargeRequestNum.
// 0 means NO error, but also: no message was sent.
// >0 means NO error, and the message was sent, and the request number fits int32_to an int32_teger...
// ...and in fact the requestNum IS the return value!
// ===> In 99% of cases, this LAST option is what actually happens!!
//
int32_t OTAPI_Wrap::queryAssetTypes(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & ENCODED_MAP
	)
{
	if (SERVER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }
	if (ENCODED_MAP.empty())		{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "ENCODED_MAP"		); OT_ASSERT(false); }

	OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID);
	OTASCIIArmor theArmor(ENCODED_MAP);

	return OTAPI_Wrap::OTAPI()->queryAssetTypes(theServerID, theUserID, theArmor);
}


// -----------------------------------------------------------
// GET MESSAGE PAYLOAD
//
// This way you can retrieve the payload from any message.
// Useful, for example, for getting the encoded stringMap object
// from the queryAssetTypes and @queryAssetTypes messages, which both
// use the m_ascPayload field to transport it.
//
string OTAPI_Wrap::Message_GetPayload(const string & THE_MESSAGE)
{
	if (THE_MESSAGE.empty())		{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_MESSAGE"		); OT_ASSERT(false); }

	OTString	strMessage(THE_MESSAGE);
	OTMessage	theMessage;

	if (!strMessage.Exists() || !theMessage.LoadContractFromString(strMessage))
		return "";

	return theMessage.m_ascPayload.Get(); 	
}



// -----------------------------------------------------------
// GET MESSAGE "DEPTH"(USED FOR MARKET-SPECIFIC MESSAGES.)
//
// Returns the count of relevant items, so you know whether to bother reading the payload.
// Returns -1 if error.
//
// The "depth" variable stores the count of items being returned.
// For example, if I call getMarketList, and 10 markets are returned,
// then depth will be set to 10. OR, if I call getNym_MarketOffers, and
// the Nym has 16 offers on the various markets, then the depth will be 16. 
// 
// This value is important when processing server replies to market inquiries.
// If the depth is 0, then you are done. End. BUT! if it contains a number, such as 10,
// then that means you will want to next READ those 10 markets(or offers, or trades, etc)
// out of the server reply's payload.
//
// Whereas if success is TRUE, but depth is 0, that means while the message processed
// successfully, the list was simply empty(and thus it would be a waste of time trying
// to unpack the non-existent, empty list of data items from the payload of your successful 
// reply.)
//
int64_t OTAPI_Wrap::Message_GetDepth(const string & THE_MESSAGE)
{
	if (THE_MESSAGE.empty())		{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_MESSAGE"		); OT_ASSERT(false); }

	OTString strMessage(THE_MESSAGE);

	OTMessage theMessage;

	if (!strMessage.Exists() || !theMessage.LoadContractFromString(strMessage))
		return -1;

	return theMessage.m_lDepth;
}

// -----------------------------------------------------------
// GET MESSAGE TRANSACTION SUCCESS(True or False)
// 
// Returns TRUE for Success and FALSE for Failure.
// Also returns OT_FALSE for error.
//
int32_t OTAPI_Wrap::Message_GetTransactionSuccess(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & ACCOUNT_ID,
	const string & THE_MESSAGE
	)
{
	if (SERVER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }
	if (ACCOUNT_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCOUNT_ID"			); OT_ASSERT(false); }
	if (THE_MESSAGE.empty())		{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_MESSAGE"		); OT_ASSERT(false); }

	const OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theAccountID(ACCOUNT_ID);

	OTString strMessage(THE_MESSAGE);

	OTMessage theMessage;

	if (!strMessage.Exists() || !theMessage.LoadContractFromString(strMessage))
	{
		OTLog::sOutput(0, "%s: Unable to load message.\n",__FUNCTION__);
		return -1;
	}

	// It's not a transaction request or response, so the Payload wouldn't
	// contain a ledger. (Don't want to pass back whatever it DOES contain
	// in that case, now do I?)
	//
	if (
		(false == theMessage.m_strCommand.Compare("@notarizeTransactions")) &&
		(false == theMessage.m_strCommand.Compare("@processInbox")) &&
		(false == theMessage.m_strCommand.Compare("@processNymbox"))
		)
	{
		OTLog::sOutput(0, "%s: Wrong message type: %s\n", __FUNCTION__, theMessage.m_strCommand.Get());
		return -1;
	}

	// The ledger is stored in the Payload, we'll grab it into the String.
	OTString strLedger(theMessage.m_ascPayload);

	if (!strLedger.Exists())
	{
		OTLog::sOutput(0, "%s: No ledger found on message.\n", __FUNCTION__);
		return -1;
	}

	// ------------------------------------

	OTLedger theLedger(theUserID, theAccountID, theServerID);

	if (false == theLedger.LoadContractFromString(strLedger))
	{
		OTString strAcctID(theAccountID);
		OTLog::sError("%s: Error loading ledger from string. Acct ID: %s\n", __FUNCTION__, strAcctID.Get());
		return -1;
	}

	// At this point, I know theLedger loaded successfully.

	if (theLedger.GetTransactionCount() <= 0)
	{
		OTLog::vError("%s: bad count in message ledger: %d\n", __FUNCTION__, theLedger.GetTransactionCount());
		return -1; // out of bounds. I'm saving from an OT_ASSERT_MSG() happening here. (Maybe I shouldn't.)
	}

	OTTransaction * pTransaction = theLedger.GetTransactionByIndex(0); // Right now this is a defacto standard. (only 1 transaction per message ledger, excepting process inbox.)
	//	OTCleanup<OTTransaction> theAngel(pTransaction); // THE LEDGER CLEANS THIS ALREADY.

	if (NULL == pTransaction)
	{
		OTLog::vError("%s: good index but uncovered NULL pointer: %d\n", __FUNCTION__, 0);
		return -1; // Weird.
	}

	// At this point, I actually have the transaction pointer, so let's return its success status
	//    
	if (pTransaction->GetSuccess())
		return 1;
	else
	{
		const long lRequestNum     = atol(theMessage.m_strRequestNum.Get());
		const long lTransactionNum = pTransaction->GetTransactionNum();

		OTLog::vError("%s: ** FYI, server reply was received, and it said 'No.' (Status = failed). RequestNum: %ld, TransNum: %ld\n",// Contents: \n\n%s\n\n", 
			__FUNCTION__, lRequestNum, lTransactionNum);//, THE_MESSAGE);
	}

	return 0;
}

// -----------------------------------------------------------
// GET BALANCE AGREEMENT SUCCESS(From a MESSAGE.)
// 
// Returns TRUE for Success and FALSE for Failure.
// Also returns FALSE for error.(Sorry.)
//
int32_t OTAPI_Wrap::Message_GetBalanceAgreementSuccess(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & ACCOUNT_ID,
	const string & THE_MESSAGE
	)
{
	if (SERVER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }
	if (ACCOUNT_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCOUNT_ID"			); OT_ASSERT(false); }
	if (THE_MESSAGE.empty())		{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_MESSAGE"		); OT_ASSERT(false); }

	const OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID), theAccountID(ACCOUNT_ID);

	OTString strMessage(THE_MESSAGE);

	OTMessage theMessage;

	if (!strMessage.Exists() || !theMessage.LoadContractFromString(strMessage))
	{
		OTLog::sOutput(0, "%s: Unable to load message.\n", __FUNCTION__);
		return -1;
	}

	// It's not a transaction request or response, so the Payload wouldn't
	// contain a ledger. (Don't want to pass back whatever it DOES contain
	// in that case, now do I?)
	//
	if (
		(false == theMessage.m_strCommand.Compare("@notarizeTransactions")) &&
		(false == theMessage.m_strCommand.Compare("@processNymbox")) &&
		(false == theMessage.m_strCommand.Compare("@processInbox"))
		)
	{
		OTLog::sOutput(0, "%s: Wrong message type: %s\n", __FUNCTION__, theMessage.m_strCommand.Get());
		return -1;
	}

	// The ledger is stored in the Payload, we'll grab it into the String.
	OTString strLedger(theMessage.m_ascPayload);

	if (!strLedger.Exists())
	{
		OTLog::sOutput(0, "%s: No ledger found on message.\n", __FUNCTION__);
		return -1;
	}

	// ------------------------------------

	OTLedger theLedger(theUserID, theAccountID, theServerID);

	if (false == theLedger.LoadLedgerFromString(strLedger))
	{
		OTString strAcctID(theAccountID);
		OTLog::sError("%s: Error loading ledger from string. Acct ID: %s\n", __FUNCTION__, strAcctID.Get());
		return -1;
	}

	// At this point, I know theLedger loaded successfully.

	if (theLedger.GetTransactionCount() <= 0)
	{
		OTLog::vError("%s bad count in message ledger: %d\n", __FUNCTION__, theLedger.GetTransactionCount());
		return -1; // out of bounds. I'm saving from an OT_ASSERT_MSG() happening here. (Maybe I shouldn't.)
	}

	OTTransaction * pReplyTransaction = theLedger.GetTransactionByIndex(0); // Right now this is a defacto standard. (only 1 transaction per message ledger, excepting process inbox. <== why? That's one as well I thought. And has multiple items attached.)
	//	OTCleanup<OTTransaction> theAngel(pTransaction); // THE LEDGER CLEANS THIS ALREADY.

	if (NULL == pReplyTransaction)
	{
		OTLog::sError("%s good index but uncovered NULL pointer there: %d\n", __FUNCTION__, 0);
		return -1; // Weird.
	}

	// At this point, I actually have the transaction pointer, so let's return its success status
	OTItem * pReplyItem = pReplyTransaction->GetItem(OTItem::atBalanceStatement);

	if (NULL == pReplyItem)
		pReplyItem = pReplyTransaction->GetItem(OTItem::atTransactionStatement);

	if (NULL == pReplyItem)
	{
		OTLog::sError("%s good index but uncovered NULL item pointer: %d\n", __FUNCTION__, 0);
		return -1; // Weird.
	}

	if (pReplyItem->GetStatus() == OTItem::acknowledgement)
	{
		return 1;
	}

	return 0;
}

// -----------------------------------------------------------
// GET MESSAGE LEDGER 
//
// If you just received a server response to a transaction, and
// you want to actually iterate through the response ledger for
// that transaction, this function will retrieve it for you.
//
string OTAPI_Wrap::Message_GetLedger(const string & THE_MESSAGE)
{
	if (THE_MESSAGE.empty())		{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_MESSAGE"		); OT_ASSERT(false); }

	OTString strMessage(THE_MESSAGE);

	OTMessage theMessage;

	if (!strMessage.Exists() || !theMessage.LoadContractFromString(strMessage))
	{
		OTLog::sOutput(0, "%s: Unable to load message.\n", __FUNCTION__);
		return "";
	}

	// It's not a transaction request or response, so the Payload wouldn't
	// contain a ledger. (Don't want to pass back whatever it DOES contain
	// in that case, now do I?)
	//
	if ((false == theMessage.m_strCommand.Compare("notarizeTransactions")) &&
		(false == theMessage.m_strCommand.Compare("@notarizeTransactions")))
	{
		OTLog::sOutput(0, "%s: Wrong message type: %s\n", __FUNCTION__, theMessage.m_strCommand.Get());
		return "";
	}

	// The ledger is stored in the Payload, we'll grab it into the String.
	OTString strOutput(theMessage.m_ascPayload);

	if (!strOutput.Exists())
	{
		OTLog::sOutput(0, "%s: No ledger found on message.\n", __FUNCTION__);
		return "";
	}

	return strOutput.Get(); 			
}



// -----------------------------------------------------------
// GET NEW ASSET TYPE ID 
//
// If you just issued a new asset type, you'll want to read the
// server reply and get the new asset type ID out of it.
// Otherwise how will you ever open accounts in that new type?
//
string OTAPI_Wrap::Message_GetNewAssetTypeID(const string & THE_MESSAGE)
{
	if (THE_MESSAGE.empty())		{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_MESSAGE"		); OT_ASSERT(false); }

	OTString strMessage(THE_MESSAGE);

	OTMessage theMessage;

	if (!strMessage.Exists() || !theMessage.LoadContractFromString(strMessage))
	{
		OTLog::sOutput(0, "%s: Unable to load message.\n", __FUNCTION__);
		return "";
	}

	// It's not a transaction request or response, so the Payload wouldn't
	// contain a ledger. (Don't want to pass back whatever it DOES contain
	// in that case, now do I?)
	//
	if ((false == theMessage.m_strCommand.Compare("@issueAssetType")) &&
		(false == theMessage.m_strCommand.Compare("@issueBasket")))
	{
		OTLog::sOutput(0, "%s: Wrong message type: %s\n", __FUNCTION__, theMessage.m_strCommand.Get());
		return "";
	}

	OTString strOutput(theMessage.m_strAssetID);

	if (!strOutput.Exists())
	{
		OTLog::sOutput(0, "%s: No new asset type ID found on message.\n", __FUNCTION__);
		return "";
	}

	return strOutput.Get(); 
}


// -----------------------------------------------------------
// GET NEW ISSUER ACCOUNT ID 
//
// If you just issued a new asset type, you'll want to read the
// server reply and get the new issuer acct ID out of it.
// Otherwise how will you ever issue anything with it?
//
string OTAPI_Wrap::Message_GetNewIssuerAcctID(const string & THE_MESSAGE)
{
	if (THE_MESSAGE.empty())		{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_MESSAGE"		); OT_ASSERT(false); }

	OTString strMessage(THE_MESSAGE);

	OTMessage theMessage;

	if (!strMessage.Exists() || !theMessage.LoadContractFromString(strMessage))
	{
		OTLog::sOutput(0, "%s: Unable to load message.\n", __FUNCTION__);
		return "";
	}

	// It's not an issue asset type response, so the m_strAcctID wouldn't
	// contain an issuer account ID. (Don't want to pass back whatever it DOES contain
	// in that case, now do I?)
	//
	if (false == theMessage.m_strCommand.Compare("@issueAssetType"))
	{
		OTLog::sOutput(0, "%s: Wrong message type: %s\n",  __FUNCTION__, theMessage.m_strCommand.Get());
		return "";
	}

	OTString strOutput(theMessage.m_strAcctID);

	if (!strOutput.Exists())
	{
		OTLog::sOutput(0, "%s: No issuer account ID found on message.\n", __FUNCTION__);
		return "";
	}

	return strOutput.Get(); 
}

// -----------------------------------------------------------
// GET NEW ACCOUNT ID 
//
// If you just opened a new asset account, you'll want to read the
// server reply and get the new acct ID out of it.
// Otherwise how will you know which account you just created?
// This function allows you to get the new account ID out of the
// server reply message.
//
string OTAPI_Wrap::Message_GetNewAcctID(const string & THE_MESSAGE)
{
	if (THE_MESSAGE.empty())		{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_MESSAGE"		); OT_ASSERT(false); }

	OTString strMessage(THE_MESSAGE);

	OTMessage theMessage;

	if (!strMessage.Exists() || !theMessage.LoadContractFromString(strMessage))
	{
		OTLog::sOutput(0, "%s: Unable to load message.\n", __FUNCTION__);
		return "";
	}

	// It's not a response to createAccount, so the m_strAcctID wouldn't
	// contain a new account ID anyway, right? (Don't want to pass back whatever 
	// it DOES contain in that case, now do I?)
	//
	if (false == theMessage.m_strCommand.Compare("@createAccount"))
	{
		OTLog::sOutput(0, "%s: Wrong message type: %s\n", __FUNCTION__, theMessage.m_strCommand.Get());
		return "";
	}

	OTString strOutput(theMessage.m_strAcctID);

	if (!strOutput.Exists())
	{
		OTLog::sOutput(0, "%s: No asset account ID found on message.\n", __FUNCTION__);
		return "";
	}

	return strOutput.Get(); 
}

// -----------------------------------------------------------
// GET NYMBOX HASH 
//
// Some messages include a copy of the Nymbox Hash. This helps the
// server to quickly ascertain whether some messages will fail, and
// also allows the client to query the server for this information
// for syncronicity purposes.
//
string OTAPI_Wrap::Message_GetNymboxHash(const string & THE_MESSAGE)
{
	if (THE_MESSAGE.empty())		{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "THE_MESSAGE"		); OT_ASSERT(false); }

	OTString strMessage(THE_MESSAGE);

	OTMessage theMessage;

	if (!strMessage.Exists() || !theMessage.LoadContractFromString(strMessage))
	{
		OTLog::sOutput(0, "%s: Unable to load message.\n", __FUNCTION__);
		return "";
	}

	// So far these are the only messages that use m_strNymboxHash:
	if (
		(false == theMessage.m_strCommand.Compare("processNymbox")) &&
		(false == theMessage.m_strCommand.Compare("notarizeTransactions")) &&
		(false == theMessage.m_strCommand.Compare("getTransactionNum")) &&
		(false == theMessage.m_strCommand.Compare("processInbox")) &&
		(false == theMessage.m_strCommand.Compare("triggerClause")) &&
		(false == theMessage.m_strCommand.Compare("@getNymbox")) &&
		(false == theMessage.m_strCommand.Compare("@getRequest")) &&
		(false == theMessage.m_strCommand.Compare("@getTransactionNum"))
		)
	{
		OTLog::sOutput(0, "%s: Wrong message type: %s \nFYI, with m_strNymboxHash: %s\n", __FUNCTION__, theMessage.m_strCommand.Get(), theMessage.m_strNymboxHash.Get());
		return "";
	}

	if (!theMessage.m_strNymboxHash.Exists())
	{
		OTLog::sOutput(0, "%s: No NymboxHash found on message: %s\n", __FUNCTION__, strMessage.Get());
		return "";
	}

	OTString strOutput(theMessage.m_strNymboxHash);
	return strOutput.Get(); 
}

// ------------------------------------------------------------



// --------------------------------------------------------------------
// CONNECT TO SERVER, and PROCESS SOCKETS
//
// NOTE: These two functions are NOT NECESSARY in ZMQ mode!
// They are only useful in TCP/SSL mode. --Otherwise IGNORE THEM.--
//
// Not necessary in HTTP mode.
bool OTAPI_Wrap::ConnectServer(
	const string & SERVER_ID,
	const string & USER_ID, 
	const string & strCA_FILE,
	const string & strKEY_FILE, 
	const string & strKEY_PASSWORD
	)
{
	if (SERVER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
	if (USER_ID.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "USER_ID"			); OT_ASSERT(false); }
	if (strCA_FILE.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "strCA_FILE"			); OT_ASSERT(false); }
	if (strKEY_FILE.empty())		{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "strKEY_FILE"		); OT_ASSERT(false); }
	if (strKEY_PASSWORD.empty())	{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "strKEY_PASSWORD"	); OT_ASSERT(false); }

	OTIdentifier theServerID(SERVER_ID), theUserID(USER_ID);

	OTString strCA(strCA_FILE), strKeyFile(strKEY_FILE), strKeyPassword(strKEY_PASSWORD);

	return OTAPI_Wrap::OTAPI()->ConnectServer(theServerID, theUserID, strCA, strKeyFile, strKeyPassword);
}

// Not necessary in ZMQ mode.
bool OTAPI_Wrap::ProcessSockets()
{
	return OTAPI_Wrap::OTAPI()->ProcessSockets();

}
// --------------------------------------------------------------------
