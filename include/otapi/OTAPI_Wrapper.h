/************************************************************************************

OTAPI_Wrapper.h   --	A C++ wrapper class (named OTAPI_Wrap)

Ironically, the C functions in OTAPI.h are wrappers around a C++ class.

But I had to add this class for compatibility reasons with OTScript, since
the current "chai" interpreter seems to prefer C++, and I think I'm having
problems right now due to direct use of "extern C" functions with chai. So
I'm adding this wrapper, at least to see if that will fix it :P
*/

/************************************************************
-----BEGIN PGP SIGNED MESSAGE-----
Hash: SHA256

*                 OPEN TRANSACTIONS
*
*       Financial Cryptography and Digital Cash
*       Library, Protocol, API, Server, and GUI 
*    
*    	 -- Anonymous Numbered Accounts.
*    	 -- Untraceable Digital Cash.
*    	 -- Triple-Signed Receipts.
*    	 -- Cheques, Vouchers, Transfers, Inboxes.
*    	 -- Basket Currencies, Markets, Payment Plans.
*    	 -- Signed, XML, Ricardian-style Contracts.
*    
*  Copyright (C) 2010-2012 by "Fellow Traveler" (A pseudonym)
*
*  EMAIL:
*  FellowTraveler@rayservers.net
*  
*  BITCOIN:  1NtTPVVjDsUfDWybS4BwvHpG2pdS9RnYyQ
*
*  KEY FINGERPRINT (PGP Key in license file):
*  9DD5 90EB 9292 4B48 0484  7910 0308 00ED F951 BB8E
*
*  OFFICIAL PROJECT WIKI(s):
*  https://github.com/FellowTraveler/Moneychanger
*  https://github.com/FellowTraveler/Open-Transactions/wiki 
*
*  WEBSITE:
*  http://www.OpenTransactions.org/
*    
*  Components and licensing:
*   -- Moneychanger..A Java client GUI.....LICENSE:.....GPLv3
*   -- OTLib.........A class library.......LICENSE:...LAGPLv3 
*   -- OT-API........A client API..........LICENSE:...LAGPLv3
*   -- testwallet....Command-line client...LICENSE:...LAGPLv3
*   -- OT-Server.....Server Application....LICENSE:....AGPLv3
*  Github.com/FellowTraveler/Open-Transactions/wiki/Components
*
*  All of the above OT components were designed and written by
*  Fellow Traveler, with the exception of Moneychanger, which
*  was contracted out to Vicky C (livewire_3001@yahoo.com).
*
*  -----------------------------------------------------
*
*   LICENSE:
*   This program is free software: you can redistribute it
*   and/or modify it under the terms of the GNU Affero
*   General Public License as published by the Free Software
*   Foundation, either version 3 of the License, or (at your
*   option) any later version.
*    
*   ADDITIONAL PERMISSION under the GNU Affero GPL version 3
*   section 7: (This paragraph applies only to the LAGPLv3
*   components listed above.) If you modify this Program, or
*   any covered work, by linking or combining it with other
*   code, such other code is not for that reason alone subject
*   to any of the requirements of the GNU Affero GPL version 3.
*   (==> This means if you are only using the OT-API, then you
*   don't have to open-source your code--only your changes to
*   Open Transactions itself must be open source. Similar to
*   LGPLv3, except it applies to software-as-a-service, not
*   just to distributing binaries.)
*
*   Extra WAIVER for OpenSSL, Lucre, and all other libraries
*   used by Open Transactions: This program is released under
*   the AGPL with the additional exemption that compiling,
*   linking, and/or using OpenSSL is allowed. The same is true
*   for any other open source libraries included in this
*   project: complete waiver from the AGPL is hereby granted to
*   compile, link, and/or use them with Open Transactions,
*   according to their own terms, as long as the rest of the
*   Open Transactions terms remain respected, with regard to
*   the Open Transactions code itself.
*    
*   Lucre License:
*   This code is also "dual-license", meaning that Ben Lau-
*   rie's license must also be included and respected, since
*   the code for Lucre is also included with Open Transactions.
*   See Open-Transactions/OTLib/Lucre/LUCRE_LICENSE.txt
*   The Laurie requirements are light, but if there is any
*   problem with his license, simply remove the Lucre code.
*   Although there are no other blind token algorithms in Open
*   Transactions (yet. credlib is coming), the other functions
*   will continue to operate.
*   -----------------------------------------------------
*   You should have received a copy of the GNU Affero General
*   Public License along with this program.  If not, see:
*   http://www.gnu.org/licenses/
*
*   If you would like to use this software outside of the free
*   software license, please contact FellowTraveler.
*   (Unfortunately many will run anonymously and untraceably,
*   so who could really stop them?)
*   
*   DISCLAIMER:
*   This program is distributed in the hope that it will be
*   useful, but WITHOUT ANY WARRANTY; without even the implied
*   warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
*   PURPOSE.  See the GNU Affero General Public License for
*   more details.
-----BEGIN PGP SIGNATURE-----
Version: GnuPG v1.4.11 (Darwin)

iQIcBAEBCAAGBQJOjvvUAAoJEAMIAO35UbuOBlMP/1LX0xJ9CrTOe1G/mgc+VygT
JPVZDAbQDL/lJXOZMbaPJ/GaLXyEnTViHp97ERrlVuBQz+9uonIKCmPqAGYGVBG1
MGV2QcscXU2aOUT1VPf2OYEOIul0h8FX2lixfqouH9/OkVsGRLr79Zu8z3zdsO4R
ktQtjZEU6lnL2t6cmp/cuXlQnbz1xvxd56xNDR11YP07Z4x+CuDB4EAK+P9TfCwn
tqq5yJmxJM9HtMoi3cUU7kXodKm1n1YZt7O46DOxHqbXqErHChN1ekSK0fXad614
Gmh+5JfvHjx5XoFWMxb46aAAcUiG8+QpFBcKtSYP2X96k1ylgxMCzrK60ec/MxKV
BzvP00OJ6PzzrTlcUaCgJ8ZX+0scOMvW0XKioEorozKSWNFvT4Drc4Thhy8u9ET3
ru1enNFrjdxKjw2+ZTQcKSZjSRx2kMQ2od/dkqUlhe/M1cHGhseH6ls7pItrkykE
ufZ9GlZoxYE+FRatIBPneT9WwsvFFvH+i6cQ/MM9pbTr19g6VPzVZ4U9E65BbTDB
czITynH+uMtJLbprtCdQlsI+vqTgYNoY8AUsmnr1qUkp020qGlvwfCJVrooisTmm
yIh+Yp/KBzySU3inzclaAfv102/t5xi1l+GTyWHiwZxlyt5PBVglKWx/Ust9CIvN
6h9BYZFTZrh/OwBXCdAv
=MUfS
-----END PGP SIGNATURE-----
**************************************************************/


#ifndef __OT_API_WRAP_H__
#define __OT_API_WRAP_H__

#include <string>
#include <stdint.h>
#include <set>
#include <list>
#include <vector>
#include <memory>

#include <OTPassword.h>

#ifndef EXPORT
#define EXPORT
#endif
#ifndef NOEXPORT
#include <ExportWrapper.h>
#endif

using namespace std;

class OT_API;
class OTServerContract;
class OTEnvelope;


class OTAPI_Wrap
{

private :

	static unique_ptr<OTAPI_Wrap> p_Wrap;

	const unique_ptr<OT_API> p_OTAPI;

	OTAPI_Wrap();

	static bool TheTransportCallback(const std::shared_ptr<OTServerContract> & pServerContract, const OTEnvelope & theEnvelope);

public :


	EXPORT	static const unique_ptr<OTAPI_Wrap> & It();

	EXPORT	static const unique_ptr<OT_API> & OTAPI();


	EXPORT static int64_t StringToLong(const string & strNumber);
	EXPORT static string LongToString(const int64_t & lNumber);

	// --------------------------------------------------------------------
	/**
	INITIALIZE the OTAPI  (Called by the constructor automaticaly)

	Call this first, to initialize the library.

	*/

	EXPORT static bool Init();


	// --------------------------------------------------------------------
	/**
	SET WALLET(optional)

	This command will set the wallet filename in the configuration.
	Use this command to change what wallet will be loaded with the
	"LOAD WALLET" command.

	e.g. SetWallet("wallet2.xml");

	*/
	EXPORT static bool SetWallet(const string & strWalletFilename); 


	// --------------------------------------------------------------------
	/**
	WALLET EXISTS

	Just Checks if the m_pWallet pointer is not null.

	WalletExists();

	*/
	EXPORT static bool WalletExists();


	// --------------------------------------------------------------------
	/**
	LOAD WALLET

	Next you'll want to load your wallet up. It needs to be in the data_folder.
	The filename is set in the configuration. Use "SET WALLET FILENAME" to change it.

	The Default Filename is "wallet.xml"

	LoadWallet();

	*/
	EXPORT static bool LoadWallet(); 



	// --------------------------------------------------------------------
	/**
	SWITCH WALLET(experimental)

	Experimental.
	Set the new wallet with the "SET WALLET FILENAME" function.
	Then call this function to switch to the new wallet.

	*/
	EXPORT static bool SwitchWallet();



	// --------------------------------------------------------------------
	/** Output to the screen(stderr.)
	(This is so stdout can be left clean for the ACTUAL output.)
	Log level is 0(least verbose) to 5(most verbose.)
	*/
	EXPORT	static void Output(
		const int32_t & nLogLevel = 0,
		const string & strOutput = ""
		);


	// --------------------------------------------------------------------
	/** TIME(in seconds, as string)

	This will return the current time in seconds, as a string.
	Returns NULL if failure.

	Todo: consider making this available on the server side as well,
	so the smart contracts can see what time it is.

	*/
	EXPORT	static	int64_t GetTime();




	/**
	These 2 functions aren't in the OT_API proper, but are only available inside
	the OTScripts on the client side.(They're not available in server-side
	scripts, and they're not available in, for example, the OTAPI Java programmable
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

	EXPORT	static	string NumList_str(
		const set<long> & setNumList
		);

	EXPORT	static	set<long> NumList(
		const string & strNumList
		);

	EXPORT	static	set<long> NumList_Add(
		const set<long> & setNumList,
		const set<long> & setNumbers
		);

	EXPORT	static	set<long> NumList_Remove(
		const set<long> & setNumList,
		const set<long> & setNumbers
		);

	EXPORT	static	bool NumList_VerifyQuery(
		const set<long> & setNumList,
		const set<long> & setNumbers
		);

	EXPORT	static	bool NumList_VerifyAll(
		const set<long> & setNumList,
		const set<long> & setNumbers
		);

	EXPORT	static	int32_t NumList_Count(
		const set<long> & setNumList
		);




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
	EXPORT	static	string Encode(
		const string & strPlaint32_text,
		bool bLineBreaks
		); 



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

	EXPORT	static	string Decode(
		const string & strEncoded,
		bool bLineBreaks
		);


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
	EXPORT	static	string Encrypt(
		const string & RECIPIENT_NYM_ID,
		const string & strPlaint32_text
		);


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
	EXPORT	static	string Decrypt(
		const string & RECIPIENT_NYM_ID,
		const string & strCiphertext
		);


	// --------------------------------------------------------------------

	// Generates a new symmetric key, based on a passphrase,
	// and returns it(or NULL.)
	//
	EXPORT	static	string CreateSymmetricKey();

	// Returns the CIPHERTEXT_ENVELOPE (the Envelope encrypted with the Symmetric Key.)
	//
	EXPORT	static	string SymmetricEncrypt(
		const string & SYMMETRIC_KEY,
		const string & PLAINTEXT
		);

	EXPORT	static	string SymmetricDecrypt(
		const string & SYMMETRIC_KEY,
		const string & CIPHERTEXT_ENVELOPE
		);


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
	EXPORT	static	string SignContract(
		const string & SIGNER_NYM_ID,
		const string & THE_CONTRACT
		);




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
	EXPORT	static	string AddSignature(
		const string & SIGNER_NYM_ID,
		const string & THE_CONTRACT
		);



	// --------------------------------------------------------------------
	/** OT-Verify the signature on a CONTRACT.

	*/
	EXPORT	static	bool VerifySignature(
		const string & SIGNER_NYM_ID,
		const string & THE_CONTRACT
		);


	EXPORT	static string FlatSign(
		const string SIGNER_NYM_ID,
		const string THE_INPUT,
		const string CONTRACT_TYPE
		);


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
	EXPORT	static	string VerifyAndRetrieveXMLContents(
		const string & THE_CONTRACT,
		const string & SIGNER_ID
		);





	// ----------------------------------------------------
	/** The below functions are for retrieving log data programatically.
	*/
	EXPORT	static	int32_t GetMemlogSize();

	EXPORT	static	string GetMemlogAtIndex(const int32_t nIndex);

	EXPORT	static	string PeekMemlogFront();
	EXPORT	static	string PeekMemlogBack();

	EXPORT	static	bool PopMemlogFront();
	EXPORT	static	bool PopMemlogBack();



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
	EXPORT	static	string CreateNym(const int32_t nKeySize); // must be 1024, 2048, 4096, or 8192 


	// Creates a contract based on the contents passed in, 
	// then sets the contract key based on the NymID,
	// and signs it with that Nym.
	// This function will also ADD the contract to the wallet.
	// Returns: the new contract ID, or NULL if failure.
	//
	EXPORT	static	string CreateServerContract(
		const string & NYM_ID,
		const string & strXMLcontents
		);

	EXPORT	static	string CreateAssetContract(
		const string & NYM_ID,
		const string & strXMLcontents
		);

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
	EXPORT	static	bool AddServerContract(const string & strContract);




	// --------------------------------------------------
	// ADD ASSET CONTRACT(to wallet)
	//
	// If you have an asset contract that you'd like to add 
	// to your wallet, call this function.
	//
	EXPORT	static	bool AddAssetContract(const string & strContract);




	// --------------------------------------------------

	// NOTE: THE BELOW FUNCTIONS *DO NOT* SEND ANY MESSAGE TO THE SERVER,
	// BUT RATHER, THEY ONLY QUERY FOR DATA FROM LOCAL STORAGE.
	//
	// Often a server response will cause a change to the data in local storage.
	// These functions allow you to re-load that data so your GUI can reflect
	// the updates to those files.
	//
	EXPORT	static	int32_t GetServerCount(void);
	EXPORT	static	int32_t GetAssetTypeCount(void);
	EXPORT	static	int32_t GetAccountCount(void);
	EXPORT	static	int32_t GetNymCount(void);



	EXPORT	static	string GetServer_ID(const int32_t nIndex); // based on Index(above 4 functions) this returns the Server's ID
	EXPORT	static	string GetServer_Name(const string & SERVER_ID); // Return's Server's name(based on server ID)
	EXPORT	static	string GetServer_Contract(const string & SERVER_ID); // Return's Server's contract(based on server ID)




	EXPORT	static	string GetAssetType_ID(const int32_t nIndex); // returns Asset Type ID(based on index from GetAssetTypeCount)
	EXPORT	static	string GetAssetType_Name(const string & ASSET_TYPE_ID); // Returns asset type name based on Asset Type ID
	EXPORT	static	string GetAssetType_Contract(const string & ASSET_TYPE_ID); // Returns currency contract based on Asset Type ID



	// You already have accounts in your wallet(without any server communications)
	// and these functions allow you to query the data members of those accounts.
	// Thus, "AccountWallet" denotes that you are examining copies of your accounts that
	// are sitting in your wallet. Originally the purpose was to eliminate confusion with
	// a different set of similarly-named functions.
	EXPORT	static	string GetAccountWallet_ID(const int32_t nIndex);  // returns a string containing the account ID, based on index.
	EXPORT	static	string GetAccountWallet_Name(const string & ACCOUNT_ID);  // returns the account name, based on account ID.
	EXPORT	static	int64_t GetAccountWallet_Balance(const string & ACCOUNT_ID);  // returns the account balance, based on account ID.
	EXPORT	static	string GetAccountWallet_Type(const string & ACCOUNT_ID);  // returns the account type(simple, issuer, etc)
	EXPORT	static	string GetAccountWallet_AssetTypeID(const string & ACCOUNT_ID);  // returns asset type ID of the account
	EXPORT	static	string GetAccountWallet_ServerID(const string & ACCOUNT_ID);  // returns Server ID of the account
	EXPORT	static	string GetAccountWallet_NymID(const string & ACCOUNT_ID);  // returns Nym ID of the account

	EXPORT	static	string GetAccountWallet_InboxHash(const string & ACCOUNT_ID);  // returns latest InboxHash according to the account file.(Usually more recent than: GetNym_InboxHash)
	EXPORT	static	string GetAccountWallet_OutboxHash(const string & ACCOUNT_ID);  // returns latest OutboxHash according to the account file.(Usually more recent than: GetNym_OutboxHash)

	// Verifies any asset account(const int32_termediary files) against its own last signed receipt.
	// Obviously this will fail for any new account that hasn't done any transactions yet, and thus has no receipts.
	EXPORT	static	bool VerifyAccountReceipt(
		const string & SERVER_ID,
		const string & NYM_ID,
		const string & ACCT_ID
		);


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
	EXPORT	static	int32_t GetNym_TransactionNumCount(
		const string & SERVER_ID,
		const string & NYM_ID
		);

	EXPORT	static	string GetNym_ID(const int32_t nIndex); // based on Index(above 4 functions) this returns the Nym's ID
	EXPORT	static	string GetNym_Name(const string & NYM_ID); // Returns Nym Name(based on NymID)
	EXPORT	static	string GetNym_Stats(const string & NYM_ID); // Returns Nym Statistics(based on NymID)

	// NymboxHash for "most recently DOWNLOADED" Nymbox(by ServerID)
	EXPORT	static	string GetNym_NymboxHash(
		const string & SERVER_ID,
		const string & NYM_ID 
		);

	// "Most recent NymboxHash according to the SERVER's records"(Which is often sent as an 'FYI' with various server replies to my messages.)
	EXPORT	static	string GetNym_RecentHash(
		const string & SERVER_ID,
		const string & NYM_ID
		);

	// InboxHash for "most recently DOWNLOADED" Inbox(by AccountID). Often contains older value than GetAccountWallet_InboxHash.
	EXPORT	static	string GetNym_InboxHash(
		const string & ACCOUNT_ID,
		const string & NYM_ID
		);

	// OutboxHash for "most recently DOWNLOADED" Outbox(by AccountID) Often contains older value than GetAccountWallet_OutboxHash
	EXPORT	static	string GetNym_OutboxHash(
		const string & ACCOUNT_ID,
		const string & NYM_ID
		);



	EXPORT	static	bool IsNym_RegisteredAtServer(const string & NYM_ID, string SERVER_ID);


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

	EXPORT	static	int32_t GetNym_MailCount(const string & NYM_ID);

	// returns the message itself(Subject: optionally as first line)
	EXPORT	static	string GetNym_MailContentsByIndex(
		const string & NYM_ID,
		const int32_t & nIndex
		);

	// returns the NymID of the sender.
	EXPORT	static	string GetNym_MailSenderIDByIndex(
		const string & NYM_ID,
		const int32_t & nIndex
		);

	// returns the ServerID where the message came from.
	EXPORT	static	string GetNym_MailServerIDByIndex(
		const string & NYM_ID,
		const int32_t & nIndex
		);

	EXPORT	static	bool Nym_RemoveMailByIndex(
		const string & NYM_ID,
		const int32_t & nIndex
		);

	// True if signature verifies.(Sender Nym MUST be in my wallet for this to work.)
	EXPORT	static	bool Nym_VerifyMailByIndex(
		const string & NYM_ID,
		const int32_t & nIndex
		);

	// ---------------------------------------------------------

	EXPORT	static	int32_t GetNym_OutmailCount(const string & NYM_ID);

	// returns the message itself(Subject: optionally as first line)
	EXPORT	static	string GetNym_OutmailContentsByIndex(
		const string & NYM_ID,
		const int32_t & nIndex
		);

	// returns the NymID of the recipient.
	EXPORT	static	string GetNym_OutmailRecipientIDByIndex(
		const string & NYM_ID,
		const int32_t & nIndex
		);

	// returns the ServerID where the message came from.
	EXPORT	static	string GetNym_OutmailServerIDByIndex(
		const string & NYM_ID,
		const int32_t & nIndex
		);

	EXPORT	static	bool Nym_RemoveOutmailByIndex(
		const string & NYM_ID,
		const int32_t & nIndex
		);

	// TRUE if signature verifies.(Sender Nym MUST be in my wallet for this to work.)
	EXPORT	static	bool Nym_VerifyOutmailByIndex(
		const string & NYM_ID,
		const int32_t & nIndex
		);

	// ---------------------------------------------------------

	EXPORT	static	int32_t GetNym_OutpaymentsCount(const string & NYM_ID);

	// returns the message itself
	EXPORT	static	string GetNym_OutpaymentsContentsByIndex(
		const string & NYM_ID,
		const int32_t & nIndex
		);

	// returns the NymID of the recipient.
	EXPORT	static	string GetNym_OutpaymentsRecipientIDByIndex(
		const string & NYM_ID,
		const int32_t & nIndex
		);

	// returns the ServerID where the message came from.
	EXPORT	static	string GetNym_OutpaymentsServerIDByIndex(
		const string & NYM_ID,
		const int32_t & nIndex
		);

	// returns the ServerID where the message came from.
	EXPORT	static	bool Nym_RemoveOutpaymentsByIndex(
		const string & NYM_ID,
		const int32_t & nIndex
		);

	// TRUE if signature verifies.(Sender Nym MUST be in my wallet for this to work.)
	EXPORT	static	bool Nym_VerifyOutpaymentsByIndex(
		const string & NYM_ID,
		const int32_t & nIndex
		);

	// ---------------------------------------------------------


	EXPORT static bool  Wallet_ChangePassphrase();

	// *** FUNCTIONS FOR REMOVING VARIOUS CONTRACTS AND NYMS FROM THE WALLET ***

	// Can I remove this server contract from my wallet?
	//
	// You cannot remove the server contract from your wallet if there are accounts in there using it.
	// This function tells you whether you can remove the server contract or not.(Whether there are accounts...)
	//
	EXPORT	static	bool Wallet_CanRemoveServer(const string & SERVER_ID);

	// Remove this server contract from my wallet!
	//
	// Try to remove the server contract from the wallet.
	// This will not work if there are any accounts in the wallet for the same server ID.
	//
	EXPORT	static	bool Wallet_RemoveServer(const string & SERVER_ID);



	// Can I remove this asset contract from my wallet?
	//
	// You cannot remove the asset contract from your wallet if there are accounts in there using it.
	// This function tells you whether you can remove the asset contract or not.(Whether there are accounts...)
	//
	EXPORT	static	bool Wallet_CanRemoveAssetType(const string & ASSET_ID);


	// Remove this asset contract from my wallet!
	//
	// Try to remove the asset contract from the wallet.
	// This will not work if there are any accounts in the wallet for the same asset type ID.
	//
	EXPORT	static	bool Wallet_RemoveAssetType(const string & ASSET_ID);



	// Can I remove this Nym from my wallet?
	//
	// You cannot remove the Nym from your wallet if there are accounts in there using it.
	// This function tells you whether you can remove the Nym or not.(Whether there are accounts...)
	//
	EXPORT	static	bool Wallet_CanRemoveNym(const string & NYM_ID);


	// Remove this Nym from my wallet!
	//
	// Try to remove the Nym from the wallet.
	// This will not work if there are any nyms in the wallet for the same server ID.
	//
	EXPORT	static	bool Wallet_RemoveNym(const string & NYM_ID);


	// Can I remove this Account from my wallet?
	//
	// You cannot remove the Account from your wallet if there are transactions still open.
	// This function tells you whether you can remove the Account or not.(Whether there are transactions...)
	//
	EXPORT	static	bool Wallet_CanRemoveAccount(const string & ACCOUNT_ID);


	// See deleteAssetAccount(), a server message, for deleting asset accounts.
	//(You can't just delete them out of the wallet without first deleting them off of the server.)
	//



	EXPORT static const std::string Wallet_ExportNym (const std::string NYM_ID);
	EXPORT static const std::string Wallet_ImportNym (const std::string FILE_CONTENTS);
	EXPORT static const std::string Wallet_ImportCert(const std::string DISPLAY_NAME, const std::string FILE_CONTENTS);
	EXPORT static const std::string Wallet_ExportCert(const std::string NYM_ID);


	// Attempts to find a full ID in the wallet, based on a partial of the same ID.
	// Returns NULL on failure, otherwise returns the full ID.
	// 
	EXPORT	static	string Wallet_GetNymIDFromPartial(const string & PARTIAL_ID);
	EXPORT	static	string Wallet_GetServerIDFromPartial(const string & PARTIAL_ID);
	EXPORT	static	string Wallet_GetAssetIDFromPartial(const string & PARTIAL_ID);
	EXPORT	static	string Wallet_GetAccountIDFromPartial(const string & PARTIAL_ID);




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
	EXPORT	static	bool SetNym_Name(
		const string & NYM_ID, 
		const string & SIGNER_NYM_ID, 
		const string & NYM_NEW_NAME
		); 

	// The asset account's name is merely a client-side label.
	EXPORT	static	bool SetAccountWallet_Name(
		const string & ACCT_ID, 
		const string & SIGNER_NYM_ID, 
		const string & ACCT_NEW_NAME
		);

	EXPORT	static	bool SetAssetType_Name(
		const string & ASSET_ID, 
		const string & STR_NEW_NAME
		);

	EXPORT	static	bool SetServer_Name(
		const string & SERVER_ID, 
		const string & STR_NEW_NAME
		); 


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

	theCheque.IssueCheque( AMOUNT // The amount of the cheque, in string form, which OTAPI
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
	EXPORT	static	string WriteCheque(
		const string & SERVER_ID,
		const string & CHEQUE_AMOUNT, 
		const time_t & VALID_FROM, 
		const time_t & VALID_TO,
		const string & SENDER_ACCT_ID,
		const string & SENDER_USER_ID,
		const string & CHEQUE_MEMO, 
		const string & RECIPIENT_USER_ID
		);

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

	EXPORT	static	bool DiscardCheque(
		const string & SERVER_ID,
		const string & USER_ID,
		const string & ACCT_ID,
		const string & THE_CHEQUE
		);




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
	EXPORT	static	string ProposePaymentPlan(
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
		);

	// Called by Customer. Pass in the plan obtained in the above call.
	//
	EXPORT	static	string ConfirmPaymentPlan(
		const string & SERVER_ID,
		const string & SENDER_USER_ID,
		const string & SENDER_ACCT_ID,
		const string & RECIPIENT_USER_ID,
		const string & PAYMENT_PLAN
		);
	// -----------------------------------------------------------------





	// SMART CONTRACTS


	// RETURNS: the Smart Contract itself.(Or NULL.)
	//
	EXPORT	static	string Create_SmartContract(
		const string & SERVER_ID,
		const string & SIGNER_NYM_ID,// Use any Nym you wish here.(The signing at this point32_t is only to cause a save.)
		// ----------------------------------------
		const time_t & VALID_FROM, // Default(0 or NULL) == NOW
		const time_t & VALID_TO // Default(0 or NULL) == no expiry / cancel anytime
		);
	// ----------------------------------------

	// ------------------

	//
	// todo: Someday add a parameter here BYLAW_LANGUAGE so that people can use
	// custom languages in their scripts. For now I have a default language, so 
	// I'll just make that the default.(There's only one language right now anyway.)
	//
	// returns: the updated smart contract(or NULL)
	EXPORT	static	string SmartContract_AddBylaw(
		const string & THE_CONTRACT, // The contract, about to have the bylaw added to it.
		const string & SIGNER_NYM_ID, // Use any Nym you wish here.(The signing at this point32_t is only to cause a save.)
		// ----------------------------------------
		const string & BYLAW_NAME // The Bylaw's NAME as referenced in the smart contract.(And the scripts...)
		);

	// returns: the updated smart contract(or NULL)
	EXPORT	static	string SmartContract_AddClause(
		const string & THE_CONTRACT, // The contract, about to have the clause added to it.
		const string & SIGNER_NYM_ID, // Use any Nym you wish here.(The signing at this point32_t is only to cause a save.)
		// ----------------------------------------
		const string & BYLAW_NAME, // Should already be on the contract.(This way we can find it.)
		// ----------------------------------------
		const string & CLAUSE_NAME, // The Clause's name as referenced in the smart contract.(And the scripts...)
		const string & SOURCE_CODE // The actual source code for the clause.
		);

	// returns: the updated smart contract(or NULL)
	EXPORT	static	string SmartContract_AddVariable(
		const string & THE_CONTRACT, // The contract, about to have the variabnle added to it.
		const string & SIGNER_NYM_ID, // Use any Nym you wish here.(The signing at this point32_t is only to cause a save.)
		// ----------------------------------------
		const string & BYLAW_NAME, // Should already be on the contract.(This way we can find it.)
		// ----------------------------------------
		const string & VAR_NAME, // The Variable's name as referenced in the smart contract.(And the scripts...)
		const string & VAR_ACCESS, // "constant", "persistent", or "important".
		const string & VAR_TYPE, // "string", "long", or "bool"
		const string & VAR_VALUE // Contains a string. If type is long, atol() will be used to convert value to a long. If type is bool, the strings "true" or "false" are expected here in order to convert to a bool.
		); 

	// returns: the updated smart contract(or NULL)
	EXPORT	static	string SmartContract_AddCallback(
		const string & THE_CONTRACT, // The contract, about to have the callback added to it.
		const string & SIGNER_NYM_ID, // Use any Nym you wish here.(The signing at this point32_t is only to cause a save.)
		// ----------------------------------------
		const string & BYLAW_NAME, // Should already be on the contract.(This way we can find it.)
		// ----------------------------------------
		const string & CALLBACK_NAME, // The Callback's name as referenced in the smart contract.(And the scripts...)
		const string & CLAUSE_NAME // The actual clause that will be triggered by the callback.(Must exist.)
		);

	// returns: the updated smart contract(or NULL)
	EXPORT	static	string SmartContract_AddHook(
		const string & THE_CONTRACT, // The contract, about to have the hook added to it.
		const string & SIGNER_NYM_ID, // Use any Nym you wish here.(The signing at this point32_t is only to cause a save.)
		// ----------------------------------------
		const string & BYLAW_NAME, // Should already be on the contract.(This way we can find it.)
		// ----------------------------------------
		const string & HOOK_NAME, // The Hook's name as referenced in the smart contract.(And the scripts...)
		const string & CLAUSE_NAME // The actual clause that will be triggered by the hook.(You can call this multiple times, and have multiple clauses trigger on the same hook.)
		);

	// --------------------------------------------------------------

	// RETURNS: Updated version of THE_CONTRACT.(Or NULL.)
	EXPORT	static	string SmartContract_AddParty(
		const string & THE_CONTRACT, // The contract, about to have the party added to it.
		const string & SIGNER_NYM_ID, // Use any Nym you wish here.(The signing at this point32_t is only to cause a save.)
		// ----------------------------------------
		const string & PARTY_NAME, // The Party's NAME as referenced in the smart contract.(And the scripts...)
		// ----------------------------------------
		const string & AGENT_NAME // An AGENT will be added by default for this party. Need Agent NAME.
		);

	//(FYI, that is basically the only option, until I code Entities and Roles. Until then, a party can ONLY be
	// a Nym, with himself as the agent representing that same party. Nym ID is supplied on ConfirmParty() below.)

	// ----------------------------------------

	// Used when creating a theoretical smart contract(that could be used over and over again with different parties.)
	//
	// returns: the updated smart contract(or NULL)
	EXPORT	static	string SmartContract_AddAccount(
		const string & THE_CONTRACT, // The contract, about to have the account added to it.
		const string & SIGNER_NYM_ID, // Use any Nym you wish here.(The signing at this point32_t is only to cause a save.)
		// ----------------------------------------
		const string & PARTY_NAME, // The Party's NAME as referenced in the smart contract.(And the scripts...)
		// ----------------------------------------
		const string & ACCT_NAME, // The Account's name as referenced in the smart contract
		const string & ASSET_TYPE_ID // Asset Type ID for the Account.
		);

	// ----------------------------------------

	// This function returns the count of how many trans#s a Nym needs in order to confirm as 
	// a specific agent for a contract.(An opening number is needed for every party of which
	// agent is the authorizing agent, plus a closing number for every acct of which agent is the
	// authorized agent.)
	//
	EXPORT	static	int32_t SmartContract_CountNumsNeeded(
		const string & THE_CONTRACT, // The smart contract, about to be queried by this function.
		const string & AGENT_NAME
		);

	// ----------------------------------------
	// Used when taking a theoretical smart contract, and setting it up to use specific Nyms and accounts. This function sets the ACCT ID for the acct specified by party name and acct name.
	// Returns the updated smart contract(or NULL.)
	EXPORT	static	string SmartContract_ConfirmAccount(
		const string & THE_CONTRACT, // The smart contract, about to be changed by this function.
		const string & SIGNER_NYM_ID, // Use any Nym you wish here.(The signing at this point32_t is only to cause a save.)
		// ----------------------------------------
		const string & PARTY_NAME, // Should already be on the contract.(This way we can find it.)
		// ----------------------------------------
		const string & ACCT_NAME, // Should already be on the contract.(This way we can find it.)
		const string & AGENT_NAME, // The agent name for this asset account.
		const string & ACCT_ID // AcctID for the asset account.(For acct_name).
		);


	// Called by each Party. Pass in the smart contract obtained in the above call.
	// Call SmartContract_ConfirmAccount() first, as much as you need to.
	// Returns the updated smart contract(or NULL.)
	EXPORT	static	string SmartContract_ConfirmParty(
		const string & THE_CONTRACT, // The smart contract, about to be changed by this function.
		const string & PARTY_NAME, // Should already be on the contract. This way we can find it.
		// ----------------------------------------
		const string & NYM_ID // Nym ID for the party, the actual owner, 
		);

	// ===> AS WELL AS for the default AGENT of that party.

	// --------------------------------------------------
	// ACTIVATE SMART CONTRACT
	// Take an existing smart contract, which has already been set up, confirmed, etc,
	// and then activate it on the server so it can start processing.
	//
	// See Create_SmartContract(etc.)
	//
	EXPORT	static	int32_t activateSmartContract(
		const string & SERVER_ID,
		const string & USER_ID,
		const string & THE_SMART_CONTRACT
		);
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
	EXPORT	static	int32_t triggerClause(
		const string & SERVER_ID,
		const string & USER_ID,
		const string & TRANSACTION_NUMBER,
		const string & CLAUSE_NAME,
		const string & STR_PARAM
		);



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

	EXPORT	static	bool Msg_HarvestTransactionNumbers(
		const string & THE_MESSAGE,
		const string & USER_ID,
		const bool & bHarvestingForRetry, // OT_BOOL
		const bool & bReplyWasSuccess, // OT_BOOL
		const bool & bReplyWasFailure, // OT_BOOL 
		const bool & bTransactionWasSuccess, // OT_BOOL
		const bool & bTransactionWasFailure // OT_BOOL
		);


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
	EXPORT	static	string LoadUserPubkey(const string & USER_ID); 



	// -----------------------------------------------------------------
	// LOAD PUBLIC KEY -- from local storage
	//
	//(returns as string)
	//
	// MEANT TO BE USED in cases where a private key is NOT available.
	//
	// returns NULL, or a public key.
	EXPORT	static	string LoadPubkey(const string & USER_ID);






	// ------------------------------------------------------------------------
	//
	// Verify that USER_ID(including its Private Key) is an 
	// available and verified user in local storage.
	//
	// Loads the user's private key, verifies, then returns OT_TRUE or OT_FALSE.
	//
	// returns OT_BOOL
	EXPORT	static	bool VerifyUserPrivateKey(const string & USER_ID);








	// --------------------------------------------------------------
	// LOAD PURSE or Mint32_t or ASSET CONTRACT or SERVER CONTRACT --(from local storage)
	//
	// Based on Asset Type ID: load a purse, a public mint32_t, or an asset/server contract
	// and return it as a string -- or return NULL if it wasn't found.
	//
	// returns NULL, or a purse.
	EXPORT	static	string LoadPurse(
		const string & SERVER_ID,
		const string & ASSET_TYPE_ID,
		const string & USER_ID
		);

	// returns NULL, or a mint32_t
	EXPORT	static	string LoadMint(
		const string & SERVER_ID,
		const string & ASSET_TYPE_ID);

	EXPORT	static	string LoadAssetContract(const string & ASSET_TYPE_ID); // returns NULL, or an asset contract.

	EXPORT	static	string LoadServerContract(const string & SERVER_ID); // returns NULL, or a server contract.





	// TRUE if the mint32_t is still usable.
	// FALSE if expired or other error.
	//
	EXPORT	static	bool Mint_IsStillGood(
		const string & SERVER_ID,
		const string & ASSET_TYPE_ID
		);




	// --------------------------------------------------------------
	// IS BASKET CURRENCY ?
	//
	// Tells you whether or not a given asset type is actually a basket currency.
	//
	EXPORT	static	bool IsBasketCurrency(const string & ASSET_TYPE_ID);


	// --------------------------------------------------------------------
	// Get Basket Count(of backing asset types.)
	//
	// Returns the number of asset types that make up this basket.
	//(Or zero.)
	//
	EXPORT	static	int32_t Basket_GetMemberCount(const string & BASKET_ASSET_TYPE_ID);


	// --------------------------------------------------------------------
	// Get Asset Type of a basket's member currency, by index.
	//
	//(Returns a string containing Asset Type ID, or NULL).
	//
	EXPORT	static	string Basket_GetMemberType(
		const string & BASKET_ASSET_TYPE_ID,
		const int32_t & nIndex
		);

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
	EXPORT	static	int64_t	Basket_GetMinimumTransferAmount(const string & BASKET_ASSET_TYPE_ID);



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
	EXPORT	static	int64_t	Basket_GetMemberMinimumTransferAmount(
		const string & BASKET_ASSET_TYPE_ID,
		const int32_t & nIndex
		);













	// --------------------------------------------------------------
	// LOAD ACCOUNT / INBOX / OUTBOX --(from local storage)
	//
	// Loads an acct, or inbox or outbox, based on account ID,(from local storage)
	// and returns it as string(or returns NULL if it couldn't load it.)
	//
	// Returns NULL, or an account.
	EXPORT	static	string LoadAssetAccount(
		const string & SERVER_ID,
		const string & USER_ID,
		const string & ACCOUNT_ID
		);

	// Returns NULL, or an inbox.
	EXPORT	static	string LoadInbox(
		const string & SERVER_ID,
		const string & USER_ID,
		const string & ACCOUNT_ID
		);

	// returns NULL, or an outbox.
	EXPORT	static	string LoadOutbox(
		const string & SERVER_ID,
		const string & USER_ID,
		const string & ACCOUNT_ID
		);

	// These versions don't verify the ledger, they just load it up.
	//
	// Returns NULL, or an inbox.
	EXPORT	static	string LoadInboxNoVerify(
		const string & SERVER_ID,
		const string & USER_ID,
		const string & ACCOUNT_ID
		);

	// returns NULL, or an outbox.
	EXPORT	static	string LoadOutboxNoVerify(
		const string & SERVER_ID,
		const string & USER_ID,
		const string & ACCOUNT_ID
		); 
	// --------------------------------------------------------------


	// from local storage.
	// Returns NULL, or a payment inbox.
	EXPORT	static	string LoadPaymentInbox(
		const string & SERVER_ID,
		const string & USER_ID
		);

	// Returns NULL, or a payment inbox.
	EXPORT	static	string LoadPaymentInboxNoVerify(
		const string & SERVER_ID,
		const string & USER_ID
		); 


	// NOTE: Sometimes the user ID is also passed in the "account ID" field, depending
	// on what kind of record box it is.
	// from local storage.
	// Returns NULL, or a RecordBox.
	EXPORT	static	string LoadRecordBox(
		const string & SERVER_ID,
		const string & USER_ID,
		const string & ACCOUNT_ID
		);

	// Returns NULL, or a RecordBox.
	EXPORT	static	string LoadRecordBoxNoVerify(
		const string & SERVER_ID,
		const string & USER_ID,
		const string & ACCOUNT_ID
		);



	// --------------------------------------------------------------
	// Find out how many pending transactions(and receipts) are in this inbox.
	// Returns number of transactions within.
	EXPORT	static	int32_t Ledger_GetCount(
		const string & SERVER_ID,
		const string & USER_ID,
		const string & ACCOUNT_ID,
		const string & THE_LEDGER
		);


	// -----------------------------------------------------------------------
	// Creates a new 'response' ledger, set up with the right Server ID, etc, so you can
	// add the 'response' transactions to it, one by one.(Pass in the original ledger 
	// that you are responding to, as it uses the data from it to set up the response.)
	//
	EXPORT	static	string Ledger_CreateResponse(
		const string & SERVER_ID,
		const string & USER_ID,
		const string & ACCOUNT_ID,
		const string & ORIGINAL_LEDGER
		); 


	// -------------------------------------------------------------------------
	// Lookup a transaction or its ID(from within a ledger) based on index or
	// transaction number.
	//
	// returns transaction by index.
	EXPORT	static	string Ledger_GetTransactionByIndex(
		const string & SERVER_ID,
		const string & USER_ID,
		const string & ACCOUNT_ID,
		const string & THE_LEDGER,
		const int32_t & nIndex
		);

	// returns transaction by ID.
	EXPORT	static	string Ledger_GetTransactionByID(
		const string & SERVER_ID,
		const string & USER_ID,
		const string & ACCOUNT_ID,
		const string & THE_LEDGER,
		const string & TRANSACTION_NUMBER
		); 

	// returns transaction number by index.
	EXPORT	static	int64_t Ledger_GetTransactionNumberByIndex(
		const string & SERVER_ID,
		const string & USER_ID,
		const string & ACCOUNT_ID,
		const string & THE_LEDGER,
		const int32_t & nIndex
		);

	// --------------------------------------------------------------
	// Add a transaction to a ledger.
	//
	EXPORT	static	string Ledger_AddTransaction(
		const string & SERVER_ID,
		const string & USER_ID,
		const string & ACCOUNT_ID,
		const string & THE_LEDGER,
		const string & THE_TRANSACTION
		);


	// --------------------------------------------------------------
	// Create a 'response' transaction, that will be used to indicate my
	// acceptance or rejection of another transaction. Usually an entire
	// ledger full of these is sent to the server as I process the various
	// transactions in my inbox.
	//
	// 1 or 0(OT_TRUE or OT_FALSE.)
	EXPORT	static	string Transaction_CreateResponse(
		const string & SERVER_ID,
		const string & USER_ID,
		const string & ACCOUNT_ID,
		const string & RESPONSE_LEDGER, // To be sent to the server...
		const string & ORIGINAL_TRANSACTION, // Responding to...?
		bool BOOL_DO_I_ACCEPT
		);




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
	EXPORT	static	string Ledger_FinalizeResponse(
		const string & SERVER_ID,
		const string & USER_ID,
		const string & ACCOUNT_ID,
		const string & THE_LEDGER);



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
	EXPORT	static	string Ledger_GetInstrument(
		const string & SERVER_ID,
		const string & USER_ID,
		const string & ACCOUNT_ID,
		const string & THE_LEDGER,
		const int32_t & nIndex
		);

	// --------------------------------------------------------------------
	// Get Transaction Type(const int32_ternally uses GetTransactionTypestring().)
	//
	EXPORT	static	string Transaction_GetType(
		const string & SERVER_ID,
		const string & USER_ID,
		const string & ACCOUNT_ID,
		const string & THE_TRANSACTION
		);


	// Transactions do not have request numbers. However, if you have a replyNotice
	// in your Nymbox, which is an OTTransaction object, it will CONTAIN a server
	// reply to some previous message. This function will only work on a replyNotice,
	// and it returns the actual request number of the server reply inside that notice.
	// Used for calling HaveAlreadySeenReply() in order to see if we've already
	// processed the reply for that message.
	//
	EXPORT	static	int64_t ReplyNotice_GetRequestNum(
		const string & SERVER_ID,
		const string & USER_ID,
		const string & THE_TRANSACTION
		);



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
	EXPORT	static	string Transaction_GetVoucher(
		const string & SERVER_ID,
		const string & USER_ID,
		const string & ACCOUNT_ID,
		const string & THE_TRANSACTION
		);



	// --------------------------------------------------
	//
	// Get Transaction Success:
	//-1 == error
	// 1 == acknowledgment
	// 0 == rejection 
	//
	EXPORT	static	int32_t Transaction_GetSuccess(
		const string & SERVER_ID,
		const string & USER_ID,
		const string & ACCOUNT_ID,
		const string & THE_TRANSACTION
		);

	// Gets the balance agreement success(from a transaction.)
	//
	EXPORT	static	int32_t Transaction_GetBalanceAgreementSuccess(
		const string & SERVER_ID,
		const string & USER_ID,
		const string & ACCOUNT_ID,
		const string & THE_TRANSACTION
		);


	// --------------------------------------------------
	//
	// Get Transaction Date Signed(const int32_ternally uses OTTransaction::GetDateSigned().)
	//
	EXPORT	static	time_t Transaction_GetDateSigned(
		const string & SERVER_ID,
		const string & USER_ID,
		const string & ACCOUNT_ID,
		const string & THE_TRANSACTION
		); 

	EXPORT	static	int64_t Transaction_GetAmount(
		const string & SERVER_ID,
		const string & USER_ID,
		const string & ACCOUNT_ID,
		const string & THE_TRANSACTION
		);


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

	EXPORT	static	string Pending_GetNote(
		const string & SERVER_ID,
		const string & USER_ID,
		const string & ACCOUNT_ID,
		const string & THE_TRANSACTION
		);


	// ----------

	EXPORT	static	string Transaction_GetSenderUserID(
		const string & SERVER_ID,
		const string & USER_ID,
		const string & ACCOUNT_ID,
		const string & THE_TRANSACTION
		);

	EXPORT	static	string Transaction_GetSenderAcctID(
		const string & SERVER_ID,
		const string & USER_ID,
		const string & ACCOUNT_ID,
		const string & THE_TRANSACTION
		);

	EXPORT	static	string Transaction_GetRecipientUserID(
		const string & SERVER_ID,
		const string & USER_ID,
		const string & ACCOUNT_ID,
		const string & THE_TRANSACTION
		);

	EXPORT	static	string Transaction_GetRecipientAcctID(
		const string & SERVER_ID,
		const string & USER_ID,
		const string & ACCOUNT_ID,
		const string & THE_TRANSACTION
		);


	// The pending notice in the inbox has a transaction number that
	// was issued to the server(so it could put the notice in your inbox.)
	// But it's IN REFERENCE TO a transfer that was initiated by another
	// user. THIS function will retrieve THAT transaction number, because
	// this function queries a pending transaction to see what transaction
	// it is "in reference to."
	//
	EXPORT	static	int64_t Transaction_GetDisplayReferenceToNum(
		const string & SERVER_ID,
		const string & USER_ID,
		const string & ACCOUNT_ID,
		const string & THE_TRANSACTION
		);



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
	EXPORT	static	string CreatePurse(
		const string & SERVER_ID,
		const string & ASSET_TYPE_ID,
		const string & USER_ID // UserID optional.
		);

	// Warning! This will overwrite whatever purse is there.
	// The proper way to use this function is, LOAD the purse,
	// then IMPORT whatever other purse you want int32_to it, then
	// SAVE it again.
	// returns OT_BOOL
	EXPORT	static	bool SavePurse(
		const string & SERVER_ID,
		const string & ASSET_TYPE_ID,
		const string & USER_ID,
		const string & THE_PURSE
		);

	// --------------------------------------------------------------------
	// Get Purse Total Value(const int32_ternally uses GetTotalValue().)
	//
	// Returns the purported sum of all the tokens within.
	//
	EXPORT	static	int64_t Purse_GetTotalValue(
		const string & SERVER_ID,
		const string & ASSET_TYPE_ID,
		const string & THE_PURSE
		);

	// ---

	EXPORT	static	int32_t Purse_Count(
		const string & SERVER_ID,
		const string & ASSET_TYPE_ID,
		const string & THE_PURSE
		);

	// Returns the TOKEN on top of the stock(LEAVING it on top of the stack,
	// but giving you a string copy of it.)
	// returns NULL if failure.
	//
	EXPORT	static	string Purse_Peek(
		const string & SERVER_ID,
		const string & ASSET_TYPE_ID,
		const string & USER_ID,
		const string & THE_PURSE
		);

	// Removes the token from the top of the stock and DESTROYS IT,
	// and RETURNS THE UPDATED PURSE(with the token now missing from it.)
	// WARNING: Do not call this function unless you have PEEK()d FIRST!!
	// Otherwise you will lose the token and get left "holding the bag".
	// returns NULL if failure.
	EXPORT	static	string Purse_Pop(
		const string & SERVER_ID,
		const string & ASSET_TYPE_ID,
		const string & USER_ID,
		const string & THE_PURSE
		);

	// Pushes a token onto the stack(of the purse.)
	// Returns the updated purse(now including the token.)
	// Returns NULL if failure.
	EXPORT	static	string Purse_Push(
		const string & SERVER_ID,
		const string & ASSET_TYPE_ID,
		const string & USER_ID,
		const string & THE_PURSE,
		const string & THE_TOKEN
		);


	// ------------------


	// Should handle duplicates. Should load, merge, and save.
	// It should either have your User ID on it, or the key should be inside so you can import.
	EXPORT	static	bool Wallet_ImportPurse(
		const string & SERVER_ID,
		const string & ASSET_TYPE_ID,
		const string & USER_ID, // you pass in the purse you're trying to import
		const string & THE_PURSE
		);

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
	EXPORT	static	int32_t exchangePurse(
		const string & SERVER_ID,
		const string & ASSET_TYPE_ID,
		const string & USER_ID,
		const string & THE_PURSE
		);

	// --------------

	// Tokens are stored in an encrypted state for security reasons.
	// This function is used for exporting those tokens to another Nym,
	// such as a Dummy nym, or another user's Nym.
	//
	EXPORT	static	string Token_ChangeOwner(
		const string & SERVER_ID,
		const string & ASSET_TYPE_ID,
		const string & THE_TOKEN,
		const string & OLD_OWNER_NYM_ID,
		const string & NEW_OWNER_NYM_ID
		);

	// Returns an encrypted form of the actual blinded token ID.
	//(There's no need to decrypt the ID until redeeming the token, when
	// you re-encrypt it to the server's public key, or until spending it,
	// when you re-encrypt it to the recipient's public key, or exporting
	// it, when you create a dummy recipient and attach it to the purse.)
	//
	EXPORT	static	string Token_GetID(
		const string & SERVER_ID,
		const string & ASSET_TYPE_ID,
		const string & THE_TOKEN
		);

	// The actual cash value of the token. Returns a long int32_t as a string.
	//
	EXPORT	static	int64_t Token_GetDenomination(
		const string & SERVER_ID,
		const string & ASSET_TYPE_ID,
		const string & THE_TOKEN
		);

	EXPORT	static	int32_t Token_GetSeries(
		const string & SERVER_ID,
		const string & ASSET_TYPE_ID,
		const string & THE_TOKEN
		);


	// the date is seconds since Jan 1970, but returned as a string.
	//
	EXPORT	static	time_t Token_GetValidFrom(
		const string & SERVER_ID,
		const string & ASSET_TYPE_ID,
		const string & THE_TOKEN
		);

	// the date is seconds since Jan 1970, but returned as a string.
	//
	EXPORT	static	time_t Token_GetValidTo(
		const string & SERVER_ID,
		const string & ASSET_TYPE_ID,
		const string & THE_TOKEN
		);


	// ---------

	EXPORT	static	string Token_GetAssetID(const string & THE_TOKEN);

	EXPORT	static	string Token_GetServerID(const string & THE_TOKEN);



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

	EXPORT	static	int64_t Instrument_GetAmount(
		const string & SERVER_ID,
		const string & THE_INSTRUMENT
		);

	EXPORT	static	int64_t Instrument_GetTransNum(
		const string & SERVER_ID,
		const string & THE_INSTRUMENT
		);

	EXPORT	static	time_t Instrument_GetValidFrom(
		const string & SERVER_ID,
		const string & THE_INSTRUMENT
		);

	EXPORT	static	time_t Instrument_GetValidTo(
		const string & SERVER_ID,
		const string & THE_INSTRUMENT
		);

	EXPORT	static	string Instrument_GetMemo(
		const string & SERVER_ID,
		const string & THE_INSTRUMENT
		);

	EXPORT	static	string Instrument_GetType(
		const string & SERVER_ID,
		const string & THE_INSTRUMENT
		);

	EXPORT	static	string Instrument_GetAssetID(
		const string & SERVER_ID,
		const string & THE_INSTRUMENT
		);

	EXPORT	static	string Instrmnt_GetSenderUserID(
		const string & SERVER_ID,
		const string & THE_INSTRUMENT
		);

	EXPORT	static	string Instrmnt_GetSenderAcctID(
		const string & SERVER_ID,
		const string & THE_INSTRUMENT
		);

	EXPORT	static	string Instrmnt_GetRecipientUserID(
		const string & SERVER_ID,
		const string & THE_INSTRUMENT
		);

	EXPORT	static	string Instrmnt_GetRecipientAcctID(
		const string & SERVER_ID,
		const string & THE_INSTRUMENT
		);




	// --------------------------------------------------------------------




	// *** MESSAGES BEING SENT TO THE SERVER -- BELOW!!! ***




	/**
	CHECK SERVER ID --(This is used for "pinging" the server...)

	Notice, if you ever want to send a message, you have to include the
	Server ID and the User ID.

	The OTAPI will use the Server ID to look-up the server contract.(FYI,
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
	EXPORT	static	int32_t checkServerID(
		const string & SERVER_ID,
		const string & USER_ID
		);


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
	EXPORT	static	int32_t createUserAccount(
		const string & SERVER_ID,
		const string & USER_ID
		);

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
	EXPORT	static	int32_t deleteUserAccount(
		const string & SERVER_ID,
		const string & USER_ID
		);

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
	EXPORT	static	int32_t deleteAssetAccount(
		const string & SERVER_ID,
		const string & USER_ID,
		const string & ACCOUNT_ID
		);

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
	EXPORT	static	int32_t usageCredits(
		const string & SERVER_ID,
		const string & USER_ID,
		const string & USER_ID_CHECK,
		const string & ADJUSTMENT
		);



	// IF THE_MESSAGE is of command type @usageCredits, and IF it was a SUCCESS,
	// then this function returns the usage credits BALANCE(it's a long int32_t, but
	// passed as a string). If you adjusted the balance using the usageCredits
	// command(THE_MESSAGE being the server's reply to that) then you will see
	// the balance AFTER the adjustment.(The current "Usage Credits" balance.)
	// 
	EXPORT	static	int64_t Message_GetUsageCredits(const string & THE_MESSAGE);




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
	EXPORT	static	int32_t checkUser(
		const string & SERVER_ID,
		const string & USER_ID,
		const string & USER_ID_CHECK
		);

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
	EXPORT	static	int32_t sendUserMessage(
		const string & SERVER_ID,
		const string & USER_ID,
		const string & USER_ID_RECIPIENT,
		const string & RECIPIENT_PUBKEY,
		const string & THE_MESSAGE
		);
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
	EXPORT	static	int32_t sendUserInstrument(
		const string & SERVER_ID,
		const string & USER_ID,
		const string & USER_ID_RECIPIENT,
		const string & RECIPIENT_PUBKEY,
		const string & THE_INSTRUMENT
		);

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
	EXPORT	static	int32_t getRequest(
		const string & SERVER_ID,
		const string & USER_ID
		);

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
	EXPORT	static	int32_t getTransactionNumber(
		const string & SERVER_ID,
		const string & USER_ID
		);



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
	EXPORT	static	int32_t issueAssetType(
		const string & SERVER_ID,
		const string & USER_ID,
		const string & THE_CONTRACT
		);



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
	EXPORT	static	int32_t getContract(
		const string & SERVER_ID,
		const string & USER_ID,
		const string & ASSET_ID
		);




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
	EXPORT	static	int32_t getMint(
		const string & SERVER_ID,
		const string & USER_ID,
		const string & ASSET_ID
		);





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
	EXPORT	static	int32_t createAssetAccount(
		const string & SERVER_ID,
		const string & USER_ID,
		const string & ASSET_ID
		);




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
	EXPORT	static	int32_t getAccount(
		const string & SERVER_ID,
		const string & USER_ID,
		const string & ACCT_ID
		);


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
	EXPORT	static	string GenerateBasketCreation(
		const string & USER_ID,
		const string & MINIMUM_TRANSFER // If basket is X=2,3,4, then this is X.
		);


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
	EXPORT	static	string AddBasketCreationItem(
		const string & USER_ID, // for signature.
		const string & THE_BASKET, // created in above call.
		const string & ASSET_TYPE_ID, // Adding an asset type to the new basket.
		const string & MINIMUM_TRANSFER // If basket is 5=X,X,X then this is an X.
		);


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
	EXPORT	static	int32_t issueBasket(
		const string & SERVER_ID,
		const string & USER_ID,
		const string & THE_BASKET
		);










	// ----------------------------------------------------
	// GENERATE BASKET EXCHANGE REQUEST
	//
	//(Returns the new basket exchange request in string form.)
	//
	// Call this function first. Then call AddBasketExchangeItem
	// multiple times, and then finally call exchangeBasket to
	// send the request to the server.
	//
	EXPORT	static	string GenerateBasketExchange(
		const string & SERVER_ID,
		const string & USER_ID,
		const string & BASKET_ASSET_TYPE_ID,
		const string & BASKET_ASSET_ACCT_ID,
		// -------------------------------------
		const int32_t & TRANSFER_MULTIPLE
		);
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
	EXPORT	static	string AddBasketExchangeItem(
		const string & SERVER_ID,
		const string & USER_ID,
		const string & THE_BASKET, 
		const string & ASSET_TYPE_ID,
		const string & ASSET_ACCT_ID
		);

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
	EXPORT	static	int32_t exchangeBasket(
		const string & SERVER_ID,
		const string & USER_ID,
		const string & BASKET_ASSET_ID,
		const string & THE_BASKET,
		const bool & BOOL_EXCHANGE_IN_OR_OUT // exchanging in == OT_TRUE, out == OT_FALSE.
		); 










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
	EXPORT	static	int32_t notarizeWithdrawal(
		const string & SERVER_ID,
		const string & USER_ID,
		const string & ACCT_ID,
		const string & AMOUNT
		);

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
	EXPORT	static	int32_t notarizeDeposit(
		const string & SERVER_ID,
		const string & USER_ID,
		const string & ACCT_ID,
		const string & THE_PURSE
		);

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
	EXPORT	static	int32_t notarizeTransfer(
		const string & SERVER_ID,
		const string & USER_ID,
		const string & ACCT_FROM,
		const string & ACCT_TO,
		const string & AMOUNT,
		const string & NOTE
		);

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
	EXPORT	static	int32_t getInbox(
		const string & SERVER_ID,
		const string & USER_ID,
		const string & ACCT_ID
		);

	// Returns int32_t:
	// -1 means error; no message was sent.
	// -2 means the message was sent, but the request number must be passed as a string, so call GetLargeRequestNum.
	// 0 means NO error, but also: no message was sent.
	// >0 means NO error, and the message was sent, and the request number fits int32_to an int32_teger...
	// ...and in fact the requestNum IS the return value!
	// ===> In 99% of cases, this LAST option is what actually happens!!
	//
	EXPORT	static	int32_t getOutbox(
		const string & SERVER_ID,
		const string & USER_ID,
		const string & ACCT_ID
		);



	// from server(pop message buf for the response)
	// Returns int32_t:
	// -1 means error; no message was sent.
	// -2 means the message was sent, but the request number must be passed as a string, so call GetLargeRequestNum.
	// 0 means NO error, but also: no message was sent.
	// >0 means NO error, and the message was sent, and the request number fits int32_to an int32_teger...
	// ...and in fact the requestNum IS the return value!
	// ===> In 99% of cases, this LAST option is what actually happens!!
	//
	EXPORT	static	int32_t getNymbox(
		const string & SERVER_ID,
		const string & USER_ID
		);

	// from local storage.
	// Returns NULL, or a Nymbox.
	EXPORT	static	string LoadNymbox(
		const string & SERVER_ID,
		const string & USER_ID
		);

	// Returns NULL, or a Nymbox.
	EXPORT	static	string LoadNymboxNoVerify(
		const string & SERVER_ID,
		const string & USER_ID
		);



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
	EXPORT	static	string Nymbox_GetReplyNotice(
		const string & SERVER_ID,
		const string & USER_ID,
		const string & REQUEST_NUMBER
		);


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
	EXPORT	static	bool HaveAlreadySeenReply(
		const string & SERVER_ID,
		const string & USER_ID,
		const string & REQUEST_NUMBER
		); 

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
	EXPORT	static	int32_t getBoxReceipt(
		const string & SERVER_ID,
		const string & USER_ID,
		const string & ACCOUNT_ID, // If for Nymbox(vs inbox/outbox) then pass USER_ID in this field also.
		const int32_t & nBoxType, // 0/nymbox, 1/inbox, 2/outbox
		const string & TRANSACTION_NUMBER
		);

	//
	EXPORT	static	bool DoesBoxReceiptExist(
		const string & SERVER_ID,
		const string & USER_ID, // Unused here for now, but still convention.
		const string & ACCOUNT_ID, // If for Nymbox(vs inbox/outbox) then pass USER_ID in this field also.
		const int32_t & nBoxType, // 0/nymbox, 1/inbox, 2/outbox
		const string & TRANSACTION_NUMBER
		);

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
	EXPORT	static	int32_t processInbox(
		const string & SERVER_ID,
		const string & USER_ID,
		const string & ACCT_ID,
		const string & ACCT_LEDGER
		);

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

	EXPORT	static	int32_t processNymbox(
		const string & SERVER_ID,
		const string & USER_ID
		);


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
	EXPORT	static	int32_t withdrawVoucher(
		const string & SERVER_ID,
		const string & USER_ID,
		const string & ACCT_ID,
		const string & RECIPIENT_USER_ID,
		const string & CHEQUE_MEMO,
		const string & AMOUNT
		);
	// --------------------------------------------------

	// PAY DIVIDEND -- to shareholders
	//
	EXPORT	static	int32_t payDividend(
		const string & SERVER_ID,
		const string & ISSUER_USER_ID, // must be issuer of SHARES_ASSET_TYPE_ID
		const string & DIVIDEND_FROM_ACCT_ID, // if dollars paid for pepsi shares, then this is the issuer's dollars account.
		const string & SHARES_ASSET_TYPE_ID, // if dollars paid for pepsi shares, then this is the pepsi shares asset type id.
		const string & DIVIDEND_MEMO, // user-configurable note that's added to the payout request message.
		const string & AMOUNT_PER_SHARE // number of dollars to be paid out PER SHARE(multiplied by total number of shares issued.)
		);

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
	EXPORT	static	int32_t depositCheque(
		const string & SERVER_ID,
		const string & USER_ID,
		const string & ACCT_ID,
		const string & THE_CHEQUE
		);
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
	EXPORT	static	int32_t depositPaymentPlan(
		const string & SERVER_ID,
		const string & USER_ID,
		const string & THE_PAYMENT_PLAN
		);
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
	EXPORT	static	int32_t issueMarketOffer(
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
		);

	// Overide For Chaiscript

	EXPORT	static	int32_t issueMarketOffer_chai(
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
		);


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
	EXPORT	static	int32_t getMarketList(
		const string & SERVER_ID,
		const string & USER_ID
		);

	// Gets all offers for a specific market and their details(up until maximum depth)
	// Returns int32_t:
	// -1 means error; no message was sent.
	// -2 means the message was sent, but the request number must be passed as a string, so call GetLargeRequestNum.
	// 0 means NO error, but also: no message was sent.
	// >0 means NO error, and the message was sent, and the request number fits int32_to an int32_teger...
	// ...and in fact the requestNum IS the return value!
	// ===> In 99% of cases, this LAST option is what actually happens!!
	//
	EXPORT	static	int32_t getMarketOffers(
		const string & SERVER_ID,
		const string & USER_ID, 
		const string & MARKET_ID,
		const string & MAX_DEPTH // Market Depth
		); 

	// Gets all recent trades(up until maximum depth)
	// Returns int32_t:
	// -1 means error; no message was sent.
	// -2 means the message was sent, but the request number must be passed as a string, so call GetLargeRequestNum.
	// 0 means NO error, but also: no message was sent.
	// >0 means NO error, and the message was sent, and the request number fits int32_to an int32_teger...
	// ...and in fact the requestNum IS the return value!
	// ===> In 99% of cases, this LAST option is what actually happens!!
	//
	EXPORT	static	int32_t getMarketRecentTrades(
		const string & SERVER_ID,
		const string & USER_ID, 
		const string & MARKET_ID
		);

	// This "Market Offer" data is a lot more detailed than the Market_GetOffers() call, which seems similar otherwise.
	// Returns int32_t:
	// -1 means error; no message was sent.
	// -2 means the message was sent, but the request number must be passed as a string, so call GetLargeRequestNum.
	// 0 means NO error, but also: no message was sent.
	// >0 means NO error, and the message was sent, and the request number fits int32_to an int32_teger...
	// ...and in fact the requestNum IS the return value!
	// ===> In 99% of cases, this LAST option is what actually happens!!
	//
	EXPORT	static	int32_t getNym_MarketOffers(
		const string & SERVER_ID,
		const string & USER_ID // Offers this Nym has out on market.
		); 
	// These may just be the Cron Receipts...





	// Returns int32_t:
	// -1 means error; no message was sent.
	// -2 means the message was sent, but the request number must be passed as a string, so call GetLargeRequestNum.
	// 0 means NO error, but also: no message was sent.
	// >0 means NO error, and the message was sent, and the request number fits int32_to an int32_teger...
	// ...and in fact the requestNum IS the return value!
	// ===> In 99% of cases, this LAST option is what actually happens!!
	//
	EXPORT	static	int32_t cancelMarketOffer(
		const string & SERVER_ID, 
		const string & USER_ID, 
		const string & ASSET_ACCT_ID, 
		const string & TRANSACTION_NUMBER
		);

	// Returns int32_t:
	// -1 means error; no message was sent.
	// -2 means the message was sent, but the request number must be passed as a string, so call GetLargeRequestNum.
	// 0 means NO error, but also: no message was sent.
	// >0 means NO error, and the message was sent, and the request number fits int32_to an int32_teger...
	// ...and in fact the requestNum IS the return value!
	// ===> In 99% of cases, this LAST option is what actually happens!!
	//
	EXPORT	static	int32_t cancelPaymentPlan(
		const string & SERVER_ID, 
		const string & USER_ID, 
		const string & FROM_ACCT_ID, 
		const string & TRANSACTION_NUMBER
		);





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
	EXPORT	static	string PopMessageBuffer(
		const string & REQUEST_NUMBER,
		const string & SERVER_ID, 
		const string & USER_ID
		);

	EXPORT	static	void FlushMessageBuffer(void);



	// Outgoing:

	EXPORT	static	string GetSentMessage(
		const string & REQUEST_NUMBER,
		const string & SERVER_ID, 
		const string & USER_ID
		);

	EXPORT	static	bool RemoveSentMessage(
		const string & REQUEST_NUMBER,
		const string & SERVER_ID, 
		const string & USER_ID
		);

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
	EXPORT	static	void FlushSentMessages(
		const bool & bHarvestingForRetry, // bHarvestingForRetry is actually OT_BOOL
		const string & SERVER_ID, 
		const string & USER_ID,
		const string & THE_NYMBOX
		); 




	// --------------------------------------------------------------------
	/** SLEEP

	If you want to go to sleep for one second, then pass "1000" to this function.

	*/
	EXPORT	static	void Sleep(const string & MILLISECONDS);




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
	EXPORT	static	bool ResyncNymWithServer(
		const string & SERVER_ID,
		const string & USER_ID,
		const string & THE_MESSAGE
		);




	// -----------------------------------------------------------
	// GET MESSAGE COMMAND TYPE
	//
	// This way you can discover what kind of command it was.
	// All server replies are pre-pended with the @ sign. For example, if
	// you send a "getAccount" message, the server reply is "@getAccount",
	// and if you send "getMint32_t" the reply is "@getMint32_t", and so on.
	//
	EXPORT	static	string Message_GetCommand(const string & THE_MESSAGE);



	// -----------------------------------------------------------
	// GET MESSAGE SUCCESS(True or False)
	//
	// Returns TRUE for Success and FALSE for Failure.
	// Also returns FALSE for error.
	//
	EXPORT	static	int32_t Message_GetSuccess(const string & THE_MESSAGE);





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
	EXPORT	static	int32_t queryAssetTypes(
		const string & SERVER_ID,
		const string & USER_ID,
		const string & ENCODED_MAP
		);




	// -----------------------------------------------------------
	// GET MESSAGE PAYLOAD
	//
	// This way you can retrieve the payload from any message.
	// Useful, for example, for getting the encoded stringMap object
	// from the queryAssetTypes and @queryAssetTypes messages, which both
	// use the m_ascPayload field to transport it.
	//
	EXPORT	static	string Message_GetPayload(const string & THE_MESSAGE);



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
	EXPORT	static	int64_t Message_GetDepth(const string & THE_MESSAGE);


	// -----------------------------------------------------------
	// GET MESSAGE TRANSACTION SUCCESS(True or False)
	// 
	// Returns TRUE for Success and FALSE for Failure.
	// Also returns OT_FALSE for error.
	//
	EXPORT	static	int32_t Message_GetTransactionSuccess(
		const string & SERVER_ID,
		const string & USER_ID,
		const string & ACCOUNT_ID,
		const string & THE_MESSAGE
		);

	// -----------------------------------------------------------
	// GET BALANCE AGREEMENT SUCCESS(From a MESSAGE.)
	// 
	// Returns TRUE for Success and FALSE for Failure.
	// Also returns FALSE for error.(Sorry.)
	//
	EXPORT	static	int32_t Message_GetBalanceAgreementSuccess(
		const string & SERVER_ID,
		const string & USER_ID,
		const string & ACCOUNT_ID,
		const string & THE_MESSAGE
		);

	// -----------------------------------------------------------
	// GET MESSAGE LEDGER 
	//
	// If you just received a server response to a transaction, and
	// you want to actually iterate through the response ledger for
	// that transaction, this function will retrieve it for you.
	//
	EXPORT	static	string Message_GetLedger(const string & THE_MESSAGE);




	// -----------------------------------------------------------
	// GET NEW ASSET TYPE ID 
	//
	// If you just issued a new asset type, you'll want to read the
	// server reply and get the new asset type ID out of it.
	// Otherwise how will you ever open accounts in that new type?
	//
	EXPORT	static	string Message_GetNewAssetTypeID(const string & THE_MESSAGE);



	// -----------------------------------------------------------
	// GET NEW ISSUER ACCOUNT ID 
	//
	// If you just issued a new asset type, you'll want to read the
	// server reply and get the new issuer acct ID out of it.
	// Otherwise how will you ever issue anything with it?
	//
	EXPORT	static	string Message_GetNewIssuerAcctID(const string & THE_MESSAGE);


	// -----------------------------------------------------------
	// GET NEW ACCOUNT ID 
	//
	// If you just opened a new asset account, you'll want to read the
	// server reply and get the new acct ID out of it.
	// Otherwise how will you know which account you just created?
	// This function allows you to get the new account ID out of the
	// server reply message.
	//
	EXPORT	static	string Message_GetNewAcctID(const string & THE_MESSAGE);


	// -----------------------------------------------------------
	// GET NYMBOX HASH 
	//
	// Some messages include a copy of the Nymbox Hash. This helps the
	// server to quickly ascertain whether some messages will fail, and
	// also allows the client to query the server for this information
	// for syncronicity purposes.
	//
	EXPORT	static	string Message_GetNymboxHash(const string & THE_MESSAGE);


	// ------------------------------------------------------------



	// --------------------------------------------------------------------
	// CONNECT TO SERVER, and PROCESS SOCKETS
	//
	// NOTE: These two functions are NOT NECESSARY in ZMQ mode!
	// They are only useful in TCP/SSL mode. --Otherwise IGNORE THEM.--
	//
	// Not necessary in HTTP mode.
	EXPORT	static	bool ConnectServer(
		const string & SERVER_ID,
		const string & USER_ID, 
		const string & strCA_FILE,
		const string & strKEY_FILE, 
		const string & strKEY_PASSWORD
		);

	EXPORT	static	bool ProcessSockets(); // Not necessary in ZMQ mode.
	// --------------------------------------------------------------------



};









#endif   // __OT_API_WRAP_H__

