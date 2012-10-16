/************************************************************************************

OTAPI_Basic.cpp   --	A C++ wrapper class (named OTAPI_Basic)

This is a Direct sub-set of OTAPI_Wrapper

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

#include <vector>

#include <OTAPI_Basic.h>
#include <OTAPI_Wrapper.h>

#include <OTLog.h>


using namespace std;



//static
SwigPasswordCallback * SwigPasswordCallback::s_pSwigPasswordCallback = nullptr;

SwigPasswordCallback::SwigPasswordCallback()
{
}
//virtual
SwigPasswordCallback::~SwigPasswordCallback()
{
}
//virtual
const bool SwigPasswordCallback::SwigGetPassword(OTPassword & passwordObject, const std::string & strMessage)
{
	OT_ASSERT(false);
	return false;
}
//virtual
const bool SwigPasswordCallback::SwigNewPassword(OTPassword & passwordObject, const std::string & strMessage)
{
	OT_ASSERT(false);
	return false;
}


//static
const bool SwigPasswordCallback::GetPassword(OTPassword & passwordObject, const std::string & strMessage)
{
	if (nullptr != s_pSwigPasswordCallback)
	{
		return s_pSwigPasswordCallback->SwigGetPassword(passwordObject,strMessage);
	}
	else
	{
		OT_ASSERT(false);
		return false;
	}
}
//static
const bool SwigPasswordCallback::NewPassword(OTPassword & passwordObject, const std::string & strMessage)
{
if (nullptr != s_pSwigPasswordCallback)
	{
		return s_pSwigPasswordCallback->SwigNewPassword(passwordObject,strMessage);
	}
	else
	{
		OT_ASSERT(false);
		return false;
	}
}
//static
const bool SwigPasswordCallback::SetCallback(SwigPasswordCallback * pSwigPasswordCallback)
{
	if (nullptr != pSwigPasswordCallback)
	{
		s_pSwigPasswordCallback = pSwigPasswordCallback;
		return true;
	}
	else return false;
}



OTAPI_Basic::OTAPI_Basic()
{
	OTAPI_Wrap::Init();

	OTAPI_Wrap::SetupSwigPasswordCallback(&SwigPasswordCallback::GetPassword,&SwigPasswordCallback::NewPassword);
}

bool OTAPI_Basic::SetWallet(const string & strWalletFilename)
{
	return OTAPI_Wrap::SetWallet(strWalletFilename);
}

bool OTAPI_Basic::LoadWallet()
{
	return OTAPI_Wrap::LoadWallet();
}

bool OTAPI_Basic::SwitchWallet()
{
	return OTAPI_Wrap::SwitchWallet();
}

void OTAPI_Basic::Output(
	const long & nLogLevel,
	const string & strOutput
	)
{
	OTAPI_Wrap::Output(nLogLevel,strOutput);
}

string OTAPI_Basic::GetTime()
{
	int64_t lTime = OTAPI_Wrap::GetTime();
	return OTAPI_Wrap::LongToString(lTime);
}

string OTAPI_Basic::NumList_Add(
	const string & strNumList,
	const string & strNumbers
	)
{
	if (strNumList.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "strNumList"			); OT_ASSERT(false); }

	set<long> setNumList, setNumbers, setResult;

	if (!strNumList.empty()) setNumList = OTAPI_Wrap::NumList(strNumList);
	else setNumList.clear();

	setNumbers = OTAPI_Wrap::NumList(strNumbers);

	setResult = OTAPI_Wrap::NumList_Add(setNumList,setNumbers);

	return OTAPI_Wrap::NumList_str(setResult);
}

string OTAPI_Basic::NumList_Remove(
	const string & strNumList,
	const string & strNumbers
	)
{
	if (strNumList.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "strNumList"			); OT_ASSERT(false); }
	if (strNumbers.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "strNumbers"			); OT_ASSERT(false); }

	set<long> setNumList, setNumbers, setResult;

	setNumList = OTAPI_Wrap::NumList(strNumList);
	setNumbers = OTAPI_Wrap::NumList(strNumbers);

	setResult = OTAPI_Wrap::NumList_Remove(setNumList,setNumbers);

	return OTAPI_Wrap::NumList_str(setResult);
}

bool OTAPI_Basic::NumList_VerifyQuery(
	const string & strNumList,
	const string & strNumbers
	)
{
	if (strNumList.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "strNumList"			); OT_ASSERT(false); }
	if (strNumbers.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "strNumbers"			); OT_ASSERT(false); }

	set<long> setNumList, setNumbers, setResult;

	setNumList = OTAPI_Wrap::NumList(strNumList);
	setNumbers = OTAPI_Wrap::NumList(strNumbers);

	return OTAPI_Wrap::NumList_VerifyQuery(setNumList,setNumbers);
}

bool OTAPI_Basic::NumList_VerifyAll(
	const string & strNumList,
	const string & strNumbers
	)
{
	if (strNumList.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "strNumList"			); OT_ASSERT(false); }
	if (strNumbers.empty())			{ OTLog::sError("%s: Null: %s passed in!\n", __FUNCTION__, "strNumbers"			); OT_ASSERT(false); }

	set<long> setNumList, setNumbers, setResult;

	setNumList = OTAPI_Wrap::NumList(strNumList);
	setNumbers = OTAPI_Wrap::NumList(strNumbers);

	return OTAPI_Wrap::NumList_VerifyAll(setNumList,setNumbers);
}

long OTAPI_Basic::NumList_Count(
	const string & strNumList
	)
{
	set<long> setNumList = OTAPI_Wrap::NumList(strNumList);
	return OTAPI_Wrap::NumList_Count(setNumList);
}

string OTAPI_Basic::Encode(
	const string & strPlaintext,
	bool bLineBreaks
	)
{
	return OTAPI_Wrap::Encode(strPlaintext,bLineBreaks);
}

string OTAPI_Basic::Decode(
	const string & strEncoded,
	bool bLineBreaks
	)
{
	return OTAPI_Wrap::Decode(
		strEncoded,
		bLineBreaks
		);
}

string OTAPI_Basic::Encrypt(
	const string & RECIPIENT_NYM_ID,
	const string & strPlainText
	)
{
	return OTAPI_Wrap::Encrypt(
		RECIPIENT_NYM_ID,
		strPlainText
		);
}

string OTAPI_Basic::Decrypt(
	const string & RECIPIENT_NYM_ID,
	const string & strCiphertext
	)
{
	return OTAPI_Wrap::Decrypt(
		RECIPIENT_NYM_ID,
		strCiphertext
		);
}

string OTAPI_Basic::CreateSymmetricKey()
{
	return OTAPI_Wrap::CreateSymmetricKey();
}

string OTAPI_Basic::SymmetricEncrypt(
	const string & SYMMETRIC_KEY,
	const string & PLAINTEXT
	)
{
	return OTAPI_Wrap::SymmetricEncrypt(
		SYMMETRIC_KEY,
		PLAINTEXT
		);
}

string OTAPI_Basic::SymmetricDecrypt(
	const string & SYMMETRIC_KEY,
	const string & CIPHERTEXT_ENVELOPE
	)
{
	return OTAPI_Wrap::SymmetricDecrypt(
		SYMMETRIC_KEY,
		CIPHERTEXT_ENVELOPE
		);
}

string OTAPI_Basic::SignContract(
	const string & SIGNER_NYM_ID,
	const string & THE_CONTRACT
	)
{	
	return OTAPI_Wrap::SymmetricDecrypt(
		SIGNER_NYM_ID,
		THE_CONTRACT
		);
}

string OTAPI_Basic::AddSignature(
	const string & SIGNER_NYM_ID,
	const string & THE_CONTRACT
	)
{
	return OTAPI_Wrap::AddSignature(
		SIGNER_NYM_ID,
		THE_CONTRACT
		);
}

bool OTAPI_Basic::VerifySignature(
	const string & SIGNER_NYM_ID,
	const string & THE_CONTRACT
	)
{
	return OTAPI_Wrap::VerifySignature(
		SIGNER_NYM_ID,
		THE_CONTRACT
		);
}

string OTAPI_Basic::VerifyAndRetrieveXMLContents(
	const string & THE_CONTRACT,
	const string & SIGNER_ID
	)

{
	return OTAPI_Wrap::VerifyAndRetrieveXMLContents(
		THE_CONTRACT,
		SIGNER_ID
		);
}

long OTAPI_Basic::GetMemlogSize() { return OTAPI_Wrap::GetMemlogSize(); }

string OTAPI_Basic::GetMemlogAtIndex(const long nIndex) { return OTAPI_Wrap::GetMemlogAtIndex(nIndex); }

string OTAPI_Basic::PeekMemlogFront() { return OTAPI_Wrap::PeekMemlogFront(); }
string OTAPI_Basic::PeekMemlogBack() { return OTAPI_Wrap::PeekMemlogBack(); }

bool OTAPI_Basic::PopMemlogFront() { return OTAPI_Wrap::PopMemlogFront(); }
bool OTAPI_Basic::PopMemlogBack() {return OTAPI_Wrap::PopMemlogBack(); }

string OTAPI_Basic::CreateNym(const long nKeySize) // must be 1024, 2048, 4096, or 8192 
{
	return OTAPI_Wrap::CreateNym(
		nKeySize
		);
}

string OTAPI_Basic::CreateServerContract(
	const string & NYM_ID,
	const string & strXMLcontents
	)
{
	return OTAPI_Wrap::CreateServerContract(
		NYM_ID,
		strXMLcontents
		);
}


string OTAPI_Basic::CreateAssetContract(
	const string & NYM_ID,
	const string & strXMLcontents
	)
{
	return OTAPI_Wrap::CreateAssetContract(
		NYM_ID,
		strXMLcontents
		);
}

bool OTAPI_Basic::AddServerContract(const string & strContract)
{
	return OTAPI_Wrap::AddServerContract(
		strContract
		);
}

bool OTAPI_Basic::AddAssetContract(const string & strContract)
{
	return OTAPI_Wrap::AddAssetContract(
		strContract
		);
}

long OTAPI_Basic::GetServerCount() { return OTAPI_Wrap::GetServerCount(); }
long OTAPI_Basic::GetAssetTypeCount() { return OTAPI_Wrap::GetAssetTypeCount(); }
long OTAPI_Basic::GetAccountCount() { return OTAPI_Wrap::GetAccountCount(); }
long OTAPI_Basic::GetNymCount() {
	long nNymCount = OTAPI_Wrap::GetNymCount();
	return nNymCount;
};

string OTAPI_Basic::GetServer_ID(const long nIndex)
{
	return OTAPI_Wrap::GetServer_ID(
		nIndex
		);
}

string OTAPI_Basic::GetServer_Name(const string & SERVER_ID)
{
	return OTAPI_Wrap::GetServer_Name(
		SERVER_ID
		);
}

string OTAPI_Basic::GetServer_Contract(const string & SERVER_ID)
{
	return OTAPI_Wrap::GetServer_Contract(
		SERVER_ID
		);
}

string OTAPI_Basic::GetAssetType_ID(const long nIndex)
{
	return OTAPI_Wrap::GetAssetType_ID(
		nIndex
		);
}

string OTAPI_Basic::GetAssetType_Name(const string & ASSET_TYPE_ID)
{
	return OTAPI_Wrap::GetAssetType_Name(
		ASSET_TYPE_ID
		);
}

string OTAPI_Basic::GetAssetType_Contract(const string & ASSET_TYPE_ID)
{
	return OTAPI_Wrap::GetAssetType_Contract(
		ASSET_TYPE_ID
		);
}

string OTAPI_Basic::GetAccountWallet_ID(const long nIndex)
{
	return OTAPI_Wrap::GetAccountWallet_ID(
		nIndex
		);
}

string OTAPI_Basic::GetAccountWallet_Name(const string & ACCOUNT_ID)
{
	return OTAPI_Wrap::GetAccountWallet_Name(
		ACCOUNT_ID
		);
}

string OTAPI_Basic::GetAccountWallet_Balance(const string & ACCOUNT_ID)
{
	return OTAPI_Wrap::LongToString(OTAPI_Wrap::GetAccountWallet_Balance(ACCOUNT_ID));
}

string OTAPI_Basic::GetAccountWallet_Type(const string & ACCOUNT_ID)
{
	return OTAPI_Wrap::GetAccountWallet_Type(
		ACCOUNT_ID
		);
}

string OTAPI_Basic::GetAccountWallet_AssetTypeID(const string & ACCOUNT_ID)
{
	return OTAPI_Wrap::GetAccountWallet_AssetTypeID(
		ACCOUNT_ID
		);
}

string OTAPI_Basic::GetAccountWallet_ServerID(const string & ACCOUNT_ID)
{
	return OTAPI_Wrap::GetAccountWallet_ServerID(
		ACCOUNT_ID
		);
}

string OTAPI_Basic::GetAccountWallet_NymID(const string & ACCOUNT_ID)
{
	return OTAPI_Wrap::GetAccountWallet_NymID(
		ACCOUNT_ID
		);
}

string OTAPI_Basic::GetAccountWallet_InboxHash(const string & ACCOUNT_ID)
{
	return OTAPI_Wrap::GetAccountWallet_InboxHash(
		ACCOUNT_ID
		);
}

string OTAPI_Basic::GetAccountWallet_OutboxHash(const string & ACCOUNT_ID)
{
	return OTAPI_Wrap::GetAccountWallet_OutboxHash(
		ACCOUNT_ID
		);
}

bool OTAPI_Basic::VerifyAccountReceipt(
	const string & SERVER_ID,
	const string & NYM_ID,
	const string & ACCT_ID
	)
{
	return OTAPI_Wrap::VerifyAccountReceipt(
		SERVER_ID,
		NYM_ID,
		ACCT_ID
		);
}

long OTAPI_Basic::GetNym_TransactionNumCount(
	const string & SERVER_ID,
	const string & NYM_ID
	)
{
	return OTAPI_Wrap::GetNym_TransactionNumCount(
		SERVER_ID,
		NYM_ID
		);
}

string OTAPI_Basic::GetNym_ID(const long nIndex)
{
	return OTAPI_Wrap::GetNym_ID(
		nIndex
		);
}

string OTAPI_Basic::GetNym_Name(const string & NYM_ID)
{
	return OTAPI_Wrap::GetNym_Name(
		NYM_ID
		);
}

string OTAPI_Basic::GetNym_Stats(const string & NYM_ID)
{
	return OTAPI_Wrap::GetNym_Stats(
		NYM_ID
		);
}

string OTAPI_Basic::GetNym_NymboxHash(
	const string & SERVER_ID,
	const string & NYM_ID 
	)
{
	return OTAPI_Wrap::GetNym_NymboxHash(
		SERVER_ID,
		NYM_ID
		);
}

string OTAPI_Basic::GetNym_RecentHash(
	const string & SERVER_ID,
	const string & NYM_ID
	)
{
	return OTAPI_Wrap::GetNym_RecentHash(
		SERVER_ID,
		NYM_ID
		);	
}

string OTAPI_Basic::GetNym_InboxHash(
	const string & ACCOUNT_ID,
	const string & NYM_ID
	)
{
	return OTAPI_Wrap::GetNym_InboxHash(
		ACCOUNT_ID,
		NYM_ID
		);		
}

string OTAPI_Basic::GetNym_OutboxHash(
	const string & ACCOUNT_ID,
	const string & NYM_ID
	)
{
	return OTAPI_Wrap::GetNym_OutboxHash(
		ACCOUNT_ID,
		NYM_ID
		);	
}

bool OTAPI_Basic::IsNym_RegisteredAtServer(const string & NYM_ID, string SERVER_ID)
{
	return OTAPI_Wrap::IsNym_RegisteredAtServer(
		NYM_ID,
		SERVER_ID
		);	
}

long OTAPI_Basic::GetNym_MailCount(const string & NYM_ID)
{
	return OTAPI_Wrap::GetNym_MailCount(
		NYM_ID
		);
}

string OTAPI_Basic::GetNym_MailContentsByIndex(
	const string & NYM_ID,
	const long & nIndex
	)
{
	return OTAPI_Wrap::GetNym_MailContentsByIndex(
		NYM_ID,
		nIndex
		);	
}

string OTAPI_Basic::GetNym_MailSenderIDByIndex(
	const string & NYM_ID,
	const long & nIndex
	)
{
	return OTAPI_Wrap::GetNym_MailSenderIDByIndex(
		NYM_ID,
		nIndex
		);		
}

string OTAPI_Basic::GetNym_MailServerIDByIndex(
	const string & NYM_ID,
	const long & nIndex
	)
{
	return OTAPI_Wrap::GetNym_MailServerIDByIndex(
		NYM_ID,
		nIndex
		);
}

bool OTAPI_Basic::Nym_RemoveMailByIndex(
	const string & NYM_ID,
	const long & nIndex
	)
{
	return OTAPI_Wrap::Nym_RemoveMailByIndex(
		NYM_ID,
		nIndex
		);
}

bool OTAPI_Basic::Nym_VerifyMailByIndex(
	const string & NYM_ID,
	const long & nIndex
	)
{
	return OTAPI_Wrap::Nym_VerifyMailByIndex(
		NYM_ID,
		nIndex
		);	
}

long OTAPI_Basic::GetNym_OutmailCount(const string & NYM_ID)
{
	return OTAPI_Wrap::GetNym_OutmailCount(
		NYM_ID
		);
}

string OTAPI_Basic::GetNym_OutmailContentsByIndex(
	const string & NYM_ID,
	const long & nIndex
	)
{
	return OTAPI_Wrap::GetNym_OutmailContentsByIndex(
		NYM_ID,
		nIndex
		);	
}

string OTAPI_Basic::GetNym_OutmailRecipientIDByIndex(
	const string & NYM_ID,
	const long & nIndex
	)
{
	return OTAPI_Wrap::GetNym_OutmailRecipientIDByIndex(
		NYM_ID,
		nIndex
		);
}

string OTAPI_Basic::GetNym_OutmailServerIDByIndex(
	const string & NYM_ID,
	const long & nIndex
	)
{
	return OTAPI_Wrap::GetNym_OutmailServerIDByIndex(
		NYM_ID,
		nIndex
		);
}

bool OTAPI_Basic::Nym_RemoveOutmailByIndex(
	const string & NYM_ID,
	const long & nIndex
	)
{
	return OTAPI_Wrap::Nym_RemoveOutmailByIndex(
		NYM_ID,
		nIndex
		);
}

bool OTAPI_Basic::Nym_VerifyOutmailByIndex(
	const string & NYM_ID,
	const long & nIndex
	)
{
	return OTAPI_Wrap::Nym_VerifyOutmailByIndex(
		NYM_ID,
		nIndex
		);	
}

long OTAPI_Basic::GetNym_OutpaymentsCount(const string & NYM_ID)
{
	return OTAPI_Wrap::GetNym_OutpaymentsCount(
		NYM_ID
		);
}

string OTAPI_Basic::GetNym_OutpaymentsContentsByIndex(
	const string & NYM_ID,
	const long & nIndex
	)
{
	return OTAPI_Wrap::GetNym_OutpaymentsContentsByIndex(
		NYM_ID,
		nIndex
		);	
}

string OTAPI_Basic::GetNym_OutpaymentsRecipientIDByIndex(
	const string & NYM_ID,
	const long & nIndex
	)
{
	return OTAPI_Wrap::GetNym_OutpaymentsRecipientIDByIndex(
		NYM_ID,
		nIndex
		);
}

string OTAPI_Basic::GetNym_OutpaymentsServerIDByIndex(
	const string & NYM_ID,
	const long & nIndex
	)
{
	return OTAPI_Wrap::GetNym_OutpaymentsServerIDByIndex(
		NYM_ID,
		nIndex
		);	
}

bool OTAPI_Basic::Nym_RemoveOutpaymentsByIndex(
	const string & NYM_ID,
	const long & nIndex
	)
{
	return OTAPI_Wrap::Nym_RemoveOutpaymentsByIndex(
		NYM_ID,
		nIndex
		);
}

bool OTAPI_Basic::Nym_VerifyOutpaymentsByIndex(
	const string & NYM_ID,
	const long & nIndex
	)
{
	return OTAPI_Wrap::Nym_VerifyOutpaymentsByIndex(
		NYM_ID,
		nIndex
		);	
}


bool  OTAPI_Basic::Wallet_ChangePassphrase() { return OTAPI_Wrap::Wallet_ChangePassphrase(); }

bool OTAPI_Basic::Wallet_CanRemoveServer(const string & SERVER_ID)
{
	return OTAPI_Wrap::Wallet_CanRemoveServer(
		SERVER_ID
		);
}

bool OTAPI_Basic::Wallet_RemoveServer(const string & SERVER_ID)
{
	return OTAPI_Wrap::Wallet_RemoveServer(
		SERVER_ID
		);
}

bool OTAPI_Basic::Wallet_CanRemoveAssetType(const string & ASSET_ID)
{
	return OTAPI_Wrap::Wallet_CanRemoveAssetType(
		ASSET_ID
		);
}

bool OTAPI_Basic::Wallet_RemoveAssetType(const string & ASSET_ID)
{
	return OTAPI_Wrap::Wallet_RemoveAssetType(
		ASSET_ID
		);
}

bool OTAPI_Basic::Wallet_CanRemoveNym(const string & NYM_ID)
{
	return OTAPI_Wrap::Wallet_RemoveAssetType(
		NYM_ID
		);
}

bool OTAPI_Basic::Wallet_RemoveNym(const string & NYM_ID)
{
	return OTAPI_Wrap::Wallet_RemoveNym(
		NYM_ID
		);
}

bool OTAPI_Basic::Wallet_CanRemoveAccount(const string & ACCOUNT_ID)
{
	return OTAPI_Wrap::Wallet_CanRemoveAccount(
		ACCOUNT_ID
		);
}


const std::string OTAPI_Basic::Wallet_ExportNym (const std::string NYM_ID)
{
	return OTAPI_Wrap::Wallet_ExportNym(NYM_ID);
}
const std::string OTAPI_Basic::Wallet_ImportNym (const std::string FILE_CONTENTS)
{
	return OTAPI_Wrap::Wallet_ImportNym(FILE_CONTENTS);
}
const std::string OTAPI_Basic::Wallet_ImportCert(const std::string DISPLAY_NAME, const std::string FILE_CONTENTS)
{
	return OTAPI_Wrap::Wallet_ImportCert(DISPLAY_NAME, FILE_CONTENTS);
}
const std::string OTAPI_Basic::Wallet_ExportCert(const std::string NYM_ID)
{
	return OTAPI_Wrap::Wallet_ExportCert(NYM_ID);
}



string OTAPI_Basic::Wallet_GetNymIDFromPartial(const string & PARTIAL_ID)
{
	return OTAPI_Wrap::Wallet_GetNymIDFromPartial(
		PARTIAL_ID
		);
}

string OTAPI_Basic::Wallet_GetServerIDFromPartial(const string & PARTIAL_ID)
{
	return OTAPI_Wrap::Wallet_GetServerIDFromPartial(
		PARTIAL_ID
		);
}

string OTAPI_Basic::Wallet_GetAssetIDFromPartial(const string & PARTIAL_ID)
{
	return OTAPI_Wrap::Wallet_GetAssetIDFromPartial(
		PARTIAL_ID
		);
}

string OTAPI_Basic::Wallet_GetAccountIDFromPartial(const string & PARTIAL_ID)
{
	return OTAPI_Wrap::Wallet_GetAccountIDFromPartial(
		PARTIAL_ID
		);
}

bool OTAPI_Basic::SetNym_Name(
	const string & NYM_ID, 
	const string & SIGNER_NYM_ID, 
	const string & NYM_NEW_NAME
	)
{
	return OTAPI_Wrap::SetNym_Name(
		NYM_ID,
		SIGNER_NYM_ID,
		NYM_NEW_NAME
		);
}

bool OTAPI_Basic::SetAccountWallet_Name(
	const string & ACCT_ID, 
	const string & SIGNER_NYM_ID, 
	const string & ACCT_NEW_NAME
	)
{
	return OTAPI_Wrap::SetAccountWallet_Name(
		ACCT_ID,
		SIGNER_NYM_ID,
		ACCT_NEW_NAME
		);
}

bool OTAPI_Basic::SetAssetType_Name(
	const string & ASSET_ID, 
	const string & STR_NEW_NAME
	)
{
	return OTAPI_Wrap::SetAssetType_Name(
		ASSET_ID,
		STR_NEW_NAME
		);
}

bool OTAPI_Basic::SetServer_Name(
	const string & SERVER_ID, 
	const string & STR_NEW_NAME
	)
{
	return OTAPI_Wrap::SetServer_Name(
		SERVER_ID,
		STR_NEW_NAME
		);
}

string OTAPI_Basic::WriteCheque(
	const string & SERVER_ID,
	const string & CHEQUE_AMOUNT, 
	const string & VALID_FROM, 
	const string & VALID_TO,
	const string & SENDER_ACCT_ID,
	const string & SENDER_USER_ID,
	const string & CHEQUE_MEMO, 
	const string & RECIPIENT_USER_ID
	)
{
	//const int64_t lCHEQUE_AMOUNT = OTAPI_Wrap::StringToLong(CHEQUE_AMOUNT);
	const int64_t lVALID_FROM	 = OTAPI_Wrap::StringToLong(VALID_FROM);
	const int64_t lVALID_TO		 = OTAPI_Wrap::StringToLong(VALID_TO);

	return OTAPI_Wrap::WriteCheque(
		SERVER_ID,
		CHEQUE_AMOUNT,
		static_cast<time_t> (lVALID_FROM),
		static_cast<time_t> (lVALID_TO),
		SENDER_ACCT_ID,
		SENDER_USER_ID,
		CHEQUE_MEMO,
		RECIPIENT_USER_ID
		);
}

bool OTAPI_Basic::DiscardCheque(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & ACCT_ID,
	const string & THE_CHEQUE
	)
{
	return OTAPI_Wrap::DiscardCheque(
		SERVER_ID,
		USER_ID,
		ACCT_ID,
		THE_CHEQUE
		);
}

string OTAPI_Basic::ProposePaymentPlan(
	const string & SERVER_ID,
	const string & VALID_FROM,
	const string & VALID_TO,
	const string & SENDER_ACCT_ID,
	const string & SENDER_USER_ID,
	const string & PLAN_CONSIDERATION,
	const string & RECIPIENT_ACCT_ID,
	const string & RECIPIENT_USER_ID,
	const string & INITIAL_PAYMENT_AMOUNT,
	const string & INITIAL_PAYMENT_DELAY,
	const string & PAYMENT_PLAN_AMOUNT,
	const string & PAYMENT_PLAN_DELAY,
	const string & PAYMENT_PLAN_PERIOD,
	const string & PAYMENT_PLAN_LENGTH,
	const long & PAYMENT_PLAN_MAX_PAYMENTS
	)
{
	const int64_t lVALID_FROM				= OTAPI_Wrap::StringToLong(VALID_FROM);
	const int64_t lVALID_TO					= OTAPI_Wrap::StringToLong(VALID_TO);
	//const int64_t lINITIAL_PAYMENT_AMOUNT	= OTAPI_Wrap::StringToLong(INITIAL_PAYMENT_AMOUNT);
	//const int64_t lINITIAL_PAYMENT_DELAY	= OTAPI_Wrap::StringToLong(INITIAL_PAYMENT_DELAY);
	//const int64_t LPAYMENT_PLAN_AMOUNT		= OTAPI_Wrap::StringToLong(PAYMENT_PLAN_AMOUNT);
	//const int64_t lPAYMENT_PLAN_DELAY		= OTAPI_Wrap::StringToLong(PAYMENT_PLAN_DELAY);
	//const int64_t lPAYMENT_PLAN_PERIOD		= OTAPI_Wrap::StringToLong(PAYMENT_PLAN_PERIOD);
	//const int64_t lPAYMENT_PLAN_LENGTH		= OTAPI_Wrap::StringToLong(PAYMENT_PLAN_LENGTH);

	return OTAPI_Wrap::ProposePaymentPlan(
		SERVER_ID,
		static_cast<time_t> (lVALID_FROM),
		static_cast<time_t> (lVALID_TO),
		SENDER_ACCT_ID,
		SENDER_USER_ID,
		PLAN_CONSIDERATION,
		RECIPIENT_ACCT_ID,
		RECIPIENT_USER_ID,
		INITIAL_PAYMENT_AMOUNT,
		INITIAL_PAYMENT_DELAY,
		PAYMENT_PLAN_AMOUNT,
		PAYMENT_PLAN_DELAY,
		PAYMENT_PLAN_PERIOD,
		PAYMENT_PLAN_LENGTH,
		PAYMENT_PLAN_MAX_PAYMENTS
		);
}

string OTAPI_Basic::ConfirmPaymentPlan(
	const string & SERVER_ID,
	const string & SENDER_USER_ID,
	const string & SENDER_ACCT_ID,
	const string & RECIPIENT_USER_ID,
	const string & PAYMENT_PLAN
	)
{
	return OTAPI_Wrap::ConfirmPaymentPlan(
		SERVER_ID,
		SENDER_USER_ID,
		SENDER_ACCT_ID,
		RECIPIENT_USER_ID,
		PAYMENT_PLAN
		);
}

string OTAPI_Basic::Create_SmartContract(
	const string & SERVER_ID,
	const string & SIGNER_NYM_ID,
	const string & VALID_FROM,
	const string & VALID_TO
	)
{
	const int64_t lVALID_FROM				= OTAPI_Wrap::StringToLong(VALID_FROM);
	const int64_t lVALID_TO					= OTAPI_Wrap::StringToLong(VALID_TO);

	return OTAPI_Wrap::Create_SmartContract(
		SERVER_ID,
		SIGNER_NYM_ID,
		static_cast<time_t> (lVALID_FROM),
		static_cast<time_t> (lVALID_TO)
		);	
}

string OTAPI_Basic::SmartContract_AddBylaw(
	const string & THE_CONTRACT,
	const string & SIGNER_NYM_ID,
	const string & BYLAW_NAME
	)
{
	return OTAPI_Wrap::SmartContract_AddBylaw(
		THE_CONTRACT,
		SIGNER_NYM_ID,
		BYLAW_NAME
		);
}

string OTAPI_Basic::SmartContract_AddClause(
	const string & THE_CONTRACT,
	const string & SIGNER_NYM_ID,
	const string & BYLAW_NAME,
	const string & CLAUSE_NAME,
	const string & SOURCE_CODE
	)
{
	return OTAPI_Wrap::SmartContract_AddClause(
		THE_CONTRACT,
		SIGNER_NYM_ID,
		BYLAW_NAME,
		CLAUSE_NAME,
		SOURCE_CODE
		);
}

string OTAPI_Basic::SmartContract_AddVariable(
	const string & THE_CONTRACT,
	const string & SIGNER_NYM_ID,
	const string & BYLAW_NAME,
	const string & VAR_NAME,
	const string & VAR_ACCESS,
	const string & VAR_TYPE,
	const string & VAR_VALUE
	)
{
	return OTAPI_Wrap::SmartContract_AddVariable(
		THE_CONTRACT,
		SIGNER_NYM_ID,
		BYLAW_NAME,
		VAR_NAME,
		VAR_ACCESS,
		VAR_TYPE,
		VAR_VALUE
		);
}

string OTAPI_Basic::SmartContract_AddCallback(
	const string & THE_CONTRACT,
	const string & SIGNER_NYM_ID,
	const string & BYLAW_NAME,
	const string & CALLBACK_NAME,
	const string & CLAUSE_NAME
	)
{
	return OTAPI_Wrap::SmartContract_AddCallback(
		THE_CONTRACT,
		SIGNER_NYM_ID,
		BYLAW_NAME,
		CALLBACK_NAME,
		CLAUSE_NAME
		);
}

string OTAPI_Basic::SmartContract_AddHook(
	const string & THE_CONTRACT,
	const string & SIGNER_NYM_ID,
	const string & BYLAW_NAME,
	const string & HOOK_NAME,
	const string & CLAUSE_NAME
	)
{
	return OTAPI_Wrap::SmartContract_AddHook(
		THE_CONTRACT,
		SIGNER_NYM_ID,
		BYLAW_NAME,
		HOOK_NAME,
		CLAUSE_NAME
		);
}

string OTAPI_Basic::SmartContract_AddParty(
	const string & THE_CONTRACT,
	const string & SIGNER_NYM_ID,
	const string & PARTY_NAME,
	const string & AGENT_NAME
	)
{
	return OTAPI_Wrap::SmartContract_AddParty(
		THE_CONTRACT,
		SIGNER_NYM_ID,
		PARTY_NAME,
		AGENT_NAME
		);
}

string OTAPI_Basic::SmartContract_AddAccount(
	const string & THE_CONTRACT,
	const string & SIGNER_NYM_ID,
	const string & PARTY_NAME,
	const string & ACCT_NAME,
	const string & ASSET_TYPE_ID
	)
{
	return OTAPI_Wrap::SmartContract_AddAccount(
		THE_CONTRACT,
		SIGNER_NYM_ID,
		PARTY_NAME,
		ACCT_NAME,
		ASSET_TYPE_ID
		);
}	

long OTAPI_Basic::SmartContract_CountNumsNeeded(
	const string & THE_CONTRACT,
	const string & AGENT_NAME
	)
{
	return OTAPI_Wrap::SmartContract_CountNumsNeeded(
		THE_CONTRACT,
		AGENT_NAME
		);
}

string OTAPI_Basic::SmartContract_ConfirmAccount(
	const string & THE_CONTRACT,
	const string & SIGNER_NYM_ID,
	const string & PARTY_NAME,
	const string & ACCT_NAME,
	const string & AGENT_NAME,
	const string & ACCT_ID
	)
{
	return OTAPI_Wrap::SmartContract_ConfirmAccount(
		THE_CONTRACT,
		SIGNER_NYM_ID,
		PARTY_NAME,
		ACCT_NAME,
		AGENT_NAME,
		ACCT_ID
		);
}

string OTAPI_Basic::SmartContract_ConfirmParty(
	const string & THE_CONTRACT,
	const string & PARTY_NAME,
	const string & NYM_ID
	)
{
	return OTAPI_Wrap::SmartContract_ConfirmParty(
		THE_CONTRACT,
		PARTY_NAME,
		NYM_ID
		);
}

long OTAPI_Basic::activateSmartContract(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & THE_SMART_CONTRACT
	)
{
	return OTAPI_Wrap::activateSmartContract(
		SERVER_ID,
		USER_ID,
		THE_SMART_CONTRACT
		);
}

long OTAPI_Basic::triggerClause(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & TRANSACTION_NUMBER,
	const string & CLAUSE_NAME,
	const string & STR_PARAM
	)
{
	//const int64_t lTRANSACTION_NUMBER		= OTAPI_Wrap::StringToLong(TRANSACTION_NUMBER);

	return OTAPI_Wrap::triggerClause(
		SERVER_ID,
		USER_ID,
		TRANSACTION_NUMBER,
		CLAUSE_NAME,
		STR_PARAM
		);
}

bool OTAPI_Basic::Msg_HarvestTransactionNumbers(
	const string & THE_MESSAGE,
	const string & USER_ID,
	const bool & bHarvestingForRetry,
	const bool & bReplyWasSuccess,
	const bool & bReplyWasFailure,
	const bool & bTransactionWasSuccess,
	const bool & bTransactionWasFailure
	)
{
	return OTAPI_Wrap::Msg_HarvestTransactionNumbers(
		THE_MESSAGE,
		USER_ID,
		bHarvestingForRetry,
		bReplyWasSuccess,
		bReplyWasFailure,
		bTransactionWasSuccess,
		bTransactionWasFailure
		);
}

string OTAPI_Basic::LoadUserPubkey(const string & USER_ID)
{
	return OTAPI_Wrap::LoadUserPubkey(
		USER_ID
		);
}

string OTAPI_Basic::LoadPubkey(const string & USER_ID)
{
	return OTAPI_Wrap::LoadPubkey(
		USER_ID
		);
}

bool OTAPI_Basic::VerifyUserPrivateKey(const string & USER_ID)
{
	return OTAPI_Wrap::VerifyUserPrivateKey(
		USER_ID
		);
}

string OTAPI_Basic::LoadPurse(
	const string & SERVER_ID,
	const string & ASSET_TYPE_ID,
	const string & USER_ID
	)
{
	return OTAPI_Wrap::LoadPurse(
		SERVER_ID,
		ASSET_TYPE_ID,
		USER_ID
		);
}

string OTAPI_Basic::LoadMint(
	const string & SERVER_ID,
	const string & ASSET_TYPE_ID)
{
	return OTAPI_Wrap::LoadMint(
		SERVER_ID,
		ASSET_TYPE_ID
		);
}

string OTAPI_Basic::LoadAssetContract(const string & ASSET_TYPE_ID)
{
	return OTAPI_Wrap::LoadAssetContract(
		ASSET_TYPE_ID
		);
}

string OTAPI_Basic::LoadServerContract(const string & SERVER_ID)
{
	return OTAPI_Wrap::LoadServerContract(
		SERVER_ID
		);			
}

bool OTAPI_Basic::Mint_IsStillGood(
	const string & SERVER_ID,
	const string & ASSET_TYPE_ID
	)
{
	return OTAPI_Wrap::Mint_IsStillGood(
		SERVER_ID,
		ASSET_TYPE_ID
		);
}

bool OTAPI_Basic::IsBasketCurrency(const string & ASSET_TYPE_ID)
{
	return OTAPI_Wrap::IsBasketCurrency(
		ASSET_TYPE_ID
		);
}

long OTAPI_Basic::Basket_GetMemberCount(const string & BASKET_ASSET_TYPE_ID)
{
	return OTAPI_Wrap::Basket_GetMemberCount(
		BASKET_ASSET_TYPE_ID
		);
}

string OTAPI_Basic::Basket_GetMemberType(
	const string & BASKET_ASSET_TYPE_ID,
	const long & nIndex
	)
{
	return OTAPI_Wrap::Basket_GetMemberType(
		BASKET_ASSET_TYPE_ID,
		nIndex
		);
}

string OTAPI_Basic::Basket_GetMinimumTransferAmount(const string & BASKET_ASSET_TYPE_ID)
{
	int64_t lNumber = OTAPI_Wrap::Basket_GetMinimumTransferAmount(BASKET_ASSET_TYPE_ID);
	return OTAPI_Wrap::LongToString(lNumber);
}

string OTAPI_Basic::Basket_GetMemberMinimumTransferAmount(
	const string & BASKET_ASSET_TYPE_ID,
	const long & nIndex
	)
{
	int64_t lNumber = OTAPI_Wrap::Basket_GetMemberMinimumTransferAmount(
		BASKET_ASSET_TYPE_ID,
		nIndex
		);

	return OTAPI_Wrap::LongToString(lNumber);
}

string OTAPI_Basic::LoadAssetAccount(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & ACCOUNT_ID
	)
{
	return OTAPI_Wrap::LoadAssetAccount(
		SERVER_ID,
		USER_ID,
		ACCOUNT_ID
		);
}

string OTAPI_Basic::LoadInbox(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & ACCOUNT_ID
	)
{
	return OTAPI_Wrap::LoadInbox(
		SERVER_ID,
		USER_ID,
		ACCOUNT_ID
		);
}

string OTAPI_Basic::LoadOutbox(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & ACCOUNT_ID
	)
{
	return OTAPI_Wrap::LoadOutbox(
		SERVER_ID,
		USER_ID,
		ACCOUNT_ID
		);				
}

string OTAPI_Basic::LoadInboxNoVerify(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & ACCOUNT_ID
	)
{
	return OTAPI_Wrap::LoadInboxNoVerify(
		SERVER_ID,
		USER_ID,
		ACCOUNT_ID
		);				
}

string OTAPI_Basic::LoadOutboxNoVerify(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & ACCOUNT_ID
	)
{
	return OTAPI_Wrap::LoadOutboxNoVerify(
		SERVER_ID,
		USER_ID,
		ACCOUNT_ID
		);					
}

string OTAPI_Basic::LoadPaymentInbox(
	const string & SERVER_ID,
	const string & USER_ID
	)
{
	return OTAPI_Wrap::LoadPaymentInbox(
		SERVER_ID,
		USER_ID
		);					
}

string OTAPI_Basic::LoadPaymentInboxNoVerify(
	const string & SERVER_ID,
	const string & USER_ID
	)
{
	return OTAPI_Wrap::LoadPaymentInboxNoVerify(
		SERVER_ID,
		USER_ID
		);				
}

string OTAPI_Basic::LoadRecordBox(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & ACCOUNT_ID
	)
{
	return OTAPI_Wrap::LoadRecordBox(
		SERVER_ID,
		USER_ID,
		ACCOUNT_ID
		);
}

string OTAPI_Basic::LoadRecordBoxNoVerify(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & ACCOUNT_ID
	)
{
	return OTAPI_Wrap::LoadRecordBoxNoVerify(
		SERVER_ID,
		USER_ID,
		ACCOUNT_ID
		);
}

long OTAPI_Basic::Ledger_GetCount(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & ACCOUNT_ID,
	const string & THE_LEDGER
	)
{
	return OTAPI_Wrap::Ledger_GetCount(
		SERVER_ID,
		USER_ID,
		ACCOUNT_ID,
		THE_LEDGER
		);
}

string OTAPI_Basic::Ledger_CreateResponse(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & ACCOUNT_ID,
	const string & ORIGINAL_LEDGER
	)
{
	return OTAPI_Wrap::Ledger_CreateResponse(
		SERVER_ID,
		USER_ID,
		ACCOUNT_ID,
		ORIGINAL_LEDGER
		);
}

string OTAPI_Basic::Ledger_GetTransactionByIndex(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & ACCOUNT_ID,
	const string & THE_LEDGER,
	const long & nIndex
	)
{
	return OTAPI_Wrap::Ledger_GetTransactionByIndex(
		SERVER_ID,
		USER_ID,
		ACCOUNT_ID,
		THE_LEDGER,
		nIndex
		);
}

string OTAPI_Basic::Ledger_GetTransactionByID(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & ACCOUNT_ID,
	const string & THE_LEDGER,
	const string & TRANSACTION_NUMBER
	)
{
	//const int64_t lTRANSACTION_NUMBER		= OTAPI_Wrap::StringToLong(TRANSACTION_NUMBER);

	return OTAPI_Wrap::Ledger_GetTransactionByID(
		SERVER_ID,
		USER_ID,
		ACCOUNT_ID,
		THE_LEDGER,
		TRANSACTION_NUMBER
		);
}

string OTAPI_Basic::Ledger_GetTransactionNumberByIndex(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & ACCOUNT_ID,
	const string & THE_LEDGER,
	const long & nIndex
	)
{
	return OTAPI_Wrap::LongToString(OTAPI_Wrap::Ledger_GetTransactionNumberByIndex(
		SERVER_ID,
		USER_ID,
		ACCOUNT_ID,
		THE_LEDGER,
		nIndex
		));
}

string OTAPI_Basic::Ledger_AddTransaction(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & ACCOUNT_ID,
	const string & THE_LEDGER,
	const string & THE_TRANSACTION
	)
{
	return OTAPI_Wrap::Ledger_AddTransaction(
		SERVER_ID,
		USER_ID,
		ACCOUNT_ID,
		THE_LEDGER,
		THE_TRANSACTION
		);
}

string OTAPI_Basic::Transaction_CreateResponse(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & ACCOUNT_ID,
	const string & RESPONSE_LEDGER,
	const string & ORIGINAL_TRANSACTION,
	bool BOOL_DO_I_ACCEPT
	)
{
	return OTAPI_Wrap::Transaction_CreateResponse(
		SERVER_ID,
		USER_ID,
		ACCOUNT_ID,
		RESPONSE_LEDGER,
		ORIGINAL_TRANSACTION,
		BOOL_DO_I_ACCEPT
		);
}

string OTAPI_Basic::Ledger_FinalizeResponse(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & ACCOUNT_ID,
	const string & THE_LEDGER
	)
{
	return OTAPI_Wrap::Ledger_FinalizeResponse(
		SERVER_ID,
		USER_ID,
		ACCOUNT_ID,
		THE_LEDGER
		);
}

string OTAPI_Basic::Ledger_GetInstrument(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & ACCOUNT_ID,
	const string & THE_LEDGER,
	const long & nIndex
	)
{
	return OTAPI_Wrap::Ledger_GetInstrument(
		SERVER_ID,
		USER_ID,
		ACCOUNT_ID,
		THE_LEDGER,
		nIndex
		);
}

string OTAPI_Basic::Transaction_GetType(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & ACCOUNT_ID,
	const string & THE_TRANSACTION
	)
{
	return OTAPI_Wrap::Transaction_GetType(
		SERVER_ID,
		USER_ID,
		ACCOUNT_ID,
		THE_TRANSACTION
		);
}

string OTAPI_Basic::ReplyNotice_GetRequestNum(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & THE_TRANSACTION
	)
{
	return OTAPI_Wrap::LongToString(OTAPI_Wrap::ReplyNotice_GetRequestNum(
		SERVER_ID,
		USER_ID,
		THE_TRANSACTION
		));
}

string OTAPI_Basic::Transaction_GetVoucher(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & ACCOUNT_ID,
	const string & THE_TRANSACTION
	)
{
	return OTAPI_Wrap::Transaction_GetVoucher(
		SERVER_ID,
		USER_ID,
		ACCOUNT_ID,
		THE_TRANSACTION
		);
}

long OTAPI_Basic::Transaction_GetSuccess(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & ACCOUNT_ID,
	const string & THE_TRANSACTION
	)
{
	return OTAPI_Wrap::Transaction_GetSuccess(
		SERVER_ID,
		USER_ID,
		ACCOUNT_ID,
		THE_TRANSACTION
		);
}

long OTAPI_Basic::Transaction_GetBalanceAgreementSuccess(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & ACCOUNT_ID,
	const string & THE_TRANSACTION
	)
{
	return OTAPI_Wrap::Transaction_GetBalanceAgreementSuccess(
		SERVER_ID,
		USER_ID,
		ACCOUNT_ID,
		THE_TRANSACTION
		);
}

string OTAPI_Basic::Transaction_GetDateSigned(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & ACCOUNT_ID,
	const string & THE_TRANSACTION
	)
{
	return OTAPI_Wrap::LongToString(static_cast<int64_t>(OTAPI_Wrap::Transaction_GetDateSigned(
		SERVER_ID,
		USER_ID,
		ACCOUNT_ID,
		THE_TRANSACTION
		)));
}

string OTAPI_Basic::Transaction_GetAmount(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & ACCOUNT_ID,
	const string & THE_TRANSACTION
	)
{
	return OTAPI_Wrap::LongToString(OTAPI_Wrap::Transaction_GetAmount(
		SERVER_ID,
		USER_ID,
		ACCOUNT_ID,
		THE_TRANSACTION
		));
}

string OTAPI_Basic::Pending_GetNote(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & ACCOUNT_ID,
	const string & THE_TRANSACTION
	)
{
	return OTAPI_Wrap::Pending_GetNote(
		SERVER_ID,
		USER_ID,
		ACCOUNT_ID,
		THE_TRANSACTION
		);
}

string OTAPI_Basic::Transaction_GetSenderUserID(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & ACCOUNT_ID,
	const string & THE_TRANSACTION
	)
{
	return OTAPI_Wrap::Transaction_GetSenderUserID(
		SERVER_ID,
		USER_ID,
		ACCOUNT_ID,
		THE_TRANSACTION
		);
}

string OTAPI_Basic::Transaction_GetSenderAcctID(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & ACCOUNT_ID,
	const string & THE_TRANSACTION
	)
{
	return OTAPI_Wrap::Transaction_GetSenderAcctID(
		SERVER_ID,
		USER_ID,
		ACCOUNT_ID,
		THE_TRANSACTION
		);
}

string OTAPI_Basic::Transaction_GetRecipientUserID(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & ACCOUNT_ID,
	const string & THE_TRANSACTION
	)
{
	return OTAPI_Wrap::Transaction_GetRecipientUserID(
		SERVER_ID,
		USER_ID,
		ACCOUNT_ID,
		THE_TRANSACTION
		);
}

string OTAPI_Basic::Transaction_GetRecipientAcctID(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & ACCOUNT_ID,
	const string & THE_TRANSACTION
	)
{
	return OTAPI_Wrap::Transaction_GetRecipientAcctID(
		SERVER_ID,
		USER_ID,
		ACCOUNT_ID,
		THE_TRANSACTION
		);
}

string OTAPI_Basic::Transaction_GetDisplayReferenceToNum(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & ACCOUNT_ID,
	const string & THE_TRANSACTION
	)
{
	return OTAPI_Wrap::LongToString(OTAPI_Wrap::Transaction_GetDisplayReferenceToNum(
		SERVER_ID,
		USER_ID,
		ACCOUNT_ID,
		THE_TRANSACTION
		));
}

string OTAPI_Basic::CreatePurse(
	const string & SERVER_ID,
	const string & ASSET_TYPE_ID,
	const string & USER_ID // UserID optional.
	)
{
	return OTAPI_Wrap::CreatePurse(
		SERVER_ID,
		ASSET_TYPE_ID,
		USER_ID
		);
}

bool OTAPI_Basic::SavePurse(
	const string & SERVER_ID,
	const string & ASSET_TYPE_ID,
	const string & USER_ID,
	const string & THE_PURSE
	)
{
	return OTAPI_Wrap::SavePurse(
		SERVER_ID,
		ASSET_TYPE_ID,
		USER_ID,
		THE_PURSE
		);
}

string OTAPI_Basic::Purse_GetTotalValue(
	const string & SERVER_ID,
	const string & ASSET_TYPE_ID,
	const string & THE_PURSE
	)
{
	return OTAPI_Wrap::LongToString(OTAPI_Wrap::Purse_GetTotalValue(
		SERVER_ID,
		ASSET_TYPE_ID,
		THE_PURSE
		));
}

long OTAPI_Basic::Purse_Count(
	const string & SERVER_ID,
	const string & ASSET_TYPE_ID,
	const string & THE_PURSE
	)
{
	return OTAPI_Wrap::Purse_Count(
		SERVER_ID,
		ASSET_TYPE_ID,
		THE_PURSE
		);
}

string OTAPI_Basic::Purse_Peek(
	const string & SERVER_ID,
	const string & ASSET_TYPE_ID,
	const string & USER_ID,
	const string & THE_PURSE
	)
{
	return OTAPI_Wrap::Purse_Peek(
		SERVER_ID,
		ASSET_TYPE_ID,
		USER_ID,
		THE_PURSE
		);
}

string OTAPI_Basic::Purse_Pop(
	const string & SERVER_ID,
	const string & ASSET_TYPE_ID,
	const string & USER_ID,
	const string & THE_PURSE
	)
{
	return OTAPI_Wrap::Purse_Pop(
		SERVER_ID,
		ASSET_TYPE_ID,
		USER_ID,
		THE_PURSE
		);
}

string OTAPI_Basic::Purse_Push(
	const string & SERVER_ID,
	const string & ASSET_TYPE_ID,
	const string & USER_ID,
	const string & THE_PURSE,
	const string & THE_TOKEN
	)
{
	return OTAPI_Wrap::Purse_Push(
		SERVER_ID,
		ASSET_TYPE_ID,
		USER_ID,
		THE_PURSE,
		THE_TOKEN
		);
}

bool OTAPI_Basic::Wallet_ImportPurse(
	const string & SERVER_ID,
	const string & ASSET_TYPE_ID,
	const string & USER_ID,
	const string & THE_PURSE
	)
{
	return OTAPI_Wrap::Wallet_ImportPurse(
		SERVER_ID,
		ASSET_TYPE_ID,
		USER_ID,
		THE_PURSE
		);
}

long OTAPI_Basic::exchangePurse(
	const string & SERVER_ID,
	const string & ASSET_TYPE_ID,
	const string & USER_ID,
	const string & THE_PURSE
	)
{
	return OTAPI_Wrap::exchangePurse(
		SERVER_ID,
		ASSET_TYPE_ID,
		USER_ID,
		THE_PURSE
		);
}

string OTAPI_Basic::Token_ChangeOwner(
	const string & SERVER_ID,
	const string & ASSET_TYPE_ID,
	const string & THE_TOKEN,
	const string & OLD_OWNER_NYM_ID,
	const string & NEW_OWNER_NYM_ID
	)
{
	return OTAPI_Wrap::Token_ChangeOwner(
		SERVER_ID,
		ASSET_TYPE_ID,
		THE_TOKEN,
		OLD_OWNER_NYM_ID,
		NEW_OWNER_NYM_ID
		);
}

string OTAPI_Basic::Token_GetID(
	const string & SERVER_ID,
	const string & ASSET_TYPE_ID,
	const string & THE_TOKEN
	)
{
	return OTAPI_Wrap::Token_GetID(
		SERVER_ID,
		ASSET_TYPE_ID,
		THE_TOKEN
		);
}

string OTAPI_Basic::Token_GetDenomination(
	const string & SERVER_ID,
	const string & ASSET_TYPE_ID,
	const string & THE_TOKEN
	)
{
	return OTAPI_Wrap::LongToString(OTAPI_Wrap::Token_GetDenomination(
		SERVER_ID,
		ASSET_TYPE_ID,
		THE_TOKEN
		));
}

long OTAPI_Basic::Token_GetSeries(
	const string & SERVER_ID,
	const string & ASSET_TYPE_ID,
	const string & THE_TOKEN
	)
{
	return OTAPI_Wrap::Token_GetSeries(
		SERVER_ID,
		ASSET_TYPE_ID,
		THE_TOKEN
		);	
}

string OTAPI_Basic::Token_GetValidFrom(
	const string & SERVER_ID,
	const string & ASSET_TYPE_ID,
	const string & THE_TOKEN
	)
{
	return OTAPI_Wrap::LongToString(static_cast<int64_t>(OTAPI_Wrap::Token_GetValidFrom(
		SERVER_ID,
		ASSET_TYPE_ID,
		THE_TOKEN
		)));
}

string OTAPI_Basic::Token_GetValidTo(
	const string & SERVER_ID,
	const string & ASSET_TYPE_ID,
	const string & THE_TOKEN
	)
{
	return OTAPI_Wrap::LongToString(static_cast<int64_t>(OTAPI_Wrap::Token_GetValidTo(
		SERVER_ID,
		ASSET_TYPE_ID,
		THE_TOKEN
		)));	
}

string OTAPI_Basic::Token_GetAssetID(const string & THE_TOKEN)
{
	return OTAPI_Wrap::Token_GetAssetID(
		THE_TOKEN
		);
}

string OTAPI_Basic::Token_GetServerID(const string & THE_TOKEN)
{
	return OTAPI_Wrap::Token_GetServerID(
		THE_TOKEN
		);
}

string OTAPI_Basic::Instrument_GetAmount(
	const string & SERVER_ID,
	const string & THE_INSTRUMENT
	)
{
	int64_t lNumber = OTAPI_Wrap::Instrument_GetAmount(
		SERVER_ID,
		THE_INSTRUMENT
		);

	return OTAPI_Wrap::LongToString(lNumber);
}

string OTAPI_Basic::Instrument_GetTransNum(
	const string & SERVER_ID,
	const string & THE_INSTRUMENT
	)
{
	int64_t lNumber = OTAPI_Wrap::Instrument_GetTransNum(
		SERVER_ID,
		THE_INSTRUMENT
		);

	return OTAPI_Wrap::LongToString(lNumber);
}

string OTAPI_Basic::Instrument_GetValidFrom(
	const string & SERVER_ID,
	const string & THE_INSTRUMENT
	)
{
	int64_t lNumber = static_cast<int64_t>(OTAPI_Wrap::Instrument_GetValidFrom(
		SERVER_ID,
		THE_INSTRUMENT
		));

	return OTAPI_Wrap::LongToString(lNumber);
}

string OTAPI_Basic::Instrument_GetValidTo(
	const string & SERVER_ID,
	const string & THE_INSTRUMENT
	)
{
	int64_t lNumber = static_cast<int64_t>(OTAPI_Wrap::Instrument_GetValidTo(
		SERVER_ID,
		THE_INSTRUMENT
		));

	return OTAPI_Wrap::LongToString(lNumber);
}

string OTAPI_Basic::Instrument_GetMemo(
	const string & SERVER_ID,
	const string & THE_INSTRUMENT
	)
{
	return OTAPI_Wrap::Instrument_GetMemo(
		SERVER_ID,
		THE_INSTRUMENT
		);
}

string OTAPI_Basic::Instrument_GetType(
	const string & SERVER_ID,
	const string & THE_INSTRUMENT
	)
{
	return OTAPI_Wrap::Instrument_GetType(
		SERVER_ID,
		THE_INSTRUMENT
		);
}

string OTAPI_Basic::Instrument_GetAssetID(
	const string & SERVER_ID,
	const string & THE_INSTRUMENT
	)
{
	return OTAPI_Wrap::Instrument_GetAssetID(
		SERVER_ID,
		THE_INSTRUMENT
		);
}

string OTAPI_Basic::Instrmnt_GetSenderUserID(
	const string & SERVER_ID,
	const string & THE_INSTRUMENT
	)
{
	return OTAPI_Wrap::Instrmnt_GetSenderUserID(
		SERVER_ID,
		THE_INSTRUMENT
		);
}

string OTAPI_Basic::Instrmnt_GetSenderAcctID(
	const string & SERVER_ID,
	const string & THE_INSTRUMENT
	)
{
	return OTAPI_Wrap::Instrmnt_GetSenderAcctID(
		SERVER_ID,
		THE_INSTRUMENT
		);
}

string OTAPI_Basic::Instrmnt_GetRecipientUserID(
	const string & SERVER_ID,
	const string & THE_INSTRUMENT
	)
{
	return OTAPI_Wrap::Instrmnt_GetRecipientUserID(
		SERVER_ID,
		THE_INSTRUMENT
		);
}

string OTAPI_Basic::Instrmnt_GetRecipientAcctID(
	const string & SERVER_ID,
	const string & THE_INSTRUMENT
	)
{
	return OTAPI_Wrap::Instrmnt_GetRecipientAcctID(
		SERVER_ID,
		THE_INSTRUMENT
		);
}

long OTAPI_Basic::checkServerID(
	const string & SERVER_ID,
	const string & USER_ID
	)
{
	return OTAPI_Wrap::checkServerID(
		SERVER_ID,
		USER_ID
		);
}


long OTAPI_Basic::createUserAccount(
	const string & SERVER_ID,
	const string & USER_ID
	)
{
	return OTAPI_Wrap::createUserAccount(
		SERVER_ID,
		USER_ID
		);
}

long OTAPI_Basic::deleteUserAccount(
	const string & SERVER_ID,
	const string & USER_ID
	)
{
	return OTAPI_Wrap::deleteUserAccount(
		SERVER_ID,
		USER_ID
		);
}

long OTAPI_Basic::deleteAssetAccount(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & ACCOUNT_ID
	)
{
	return OTAPI_Wrap::deleteAssetAccount(
		SERVER_ID,
		USER_ID,
		ACCOUNT_ID
		);
}

long OTAPI_Basic::usageCredits(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & USER_ID_CHECK,
	const string & ADJUSTMENT
	)
{
	return OTAPI_Wrap::usageCredits(
		SERVER_ID,
		USER_ID,
		USER_ID_CHECK,
		ADJUSTMENT
		);
}

string OTAPI_Basic::Message_GetUsageCredits(const string & THE_MESSAGE)
{
	const int64_t lNumber = OTAPI_Wrap::Message_GetUsageCredits(
		THE_MESSAGE
		);

	return OTAPI_Wrap::LongToString(lNumber);
}

long OTAPI_Basic::checkUser(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & USER_ID_CHECK
	)
{
	return OTAPI_Wrap::checkUser(
		SERVER_ID,
		USER_ID,
		USER_ID_CHECK
		);
}

long OTAPI_Basic::sendUserMessage(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & USER_ID_RECIPIENT,
	const string & RECIPIENT_PUBKEY,
	const string & THE_MESSAGE
	)
{
	return OTAPI_Wrap::sendUserMessage(
		SERVER_ID,
		USER_ID,
		USER_ID_RECIPIENT,
		RECIPIENT_PUBKEY,
		THE_MESSAGE
		);
}

long OTAPI_Basic::sendUserInstrument(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & USER_ID_RECIPIENT,
	const string & RECIPIENT_PUBKEY,
	const string & THE_INSTRUMENT
	)
{
	return OTAPI_Wrap::sendUserInstrument(
		SERVER_ID,
		USER_ID,
		USER_ID_RECIPIENT,
		RECIPIENT_PUBKEY,
		THE_INSTRUMENT
		);
}

long OTAPI_Basic::getRequest(
	const string & SERVER_ID,
	const string & USER_ID
	)
{
	return OTAPI_Wrap::getRequest(
		SERVER_ID,
		USER_ID
		);
}

long OTAPI_Basic::getTransactionNumber(
	const string & SERVER_ID,
	const string & USER_ID
	)
{
	return OTAPI_Wrap::getTransactionNumber(
		SERVER_ID,
		USER_ID
		);
}

long OTAPI_Basic::issueAssetType(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & THE_CONTRACT
	)
{
	return OTAPI_Wrap::issueAssetType(
		SERVER_ID,
		USER_ID,
		THE_CONTRACT
		);
}

long OTAPI_Basic::getContract(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & ASSET_ID
	)
{
	return OTAPI_Wrap::getContract(
		SERVER_ID,
		USER_ID,
		ASSET_ID
		);
}

long OTAPI_Basic::getMint(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & ASSET_ID
	)
{
	return OTAPI_Wrap::getMint(
		SERVER_ID,
		USER_ID,
		ASSET_ID
		);
}

long OTAPI_Basic::createAssetAccount(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & ASSET_ID
	)
{
	return OTAPI_Wrap::createAssetAccount(
		SERVER_ID,
		USER_ID,
		ASSET_ID
		);
}

long OTAPI_Basic::getAccount(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & ACCT_ID
	)
{
	return OTAPI_Wrap::getAccount(
		SERVER_ID,
		USER_ID,
		ACCT_ID
		);
}

string OTAPI_Basic::GenerateBasketCreation(
	const string & USER_ID,
	const string & MINIMUM_TRANSFER
	)
{
	//const int64_t lMINIMUM_TRANSFER = OTAPI_Wrap::StringToLong(MINIMUM_TRANSFER);

	return OTAPI_Wrap::GenerateBasketCreation(
		USER_ID,
		MINIMUM_TRANSFER
		);
}

string OTAPI_Basic::AddBasketCreationItem(
	const string & USER_ID,
	const string & THE_BASKET,
	const string & ASSET_TYPE_ID,
	const string & MINIMUM_TRANSFER
	)
{
	//const int64_t lMINIMUM_TRANSFER = OTAPI_Wrap::StringToLong(MINIMUM_TRANSFER);

	return OTAPI_Wrap::AddBasketCreationItem(
		USER_ID,
		THE_BASKET,
		ASSET_TYPE_ID,
		MINIMUM_TRANSFER
		);	
}

long OTAPI_Basic::issueBasket(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & THE_BASKET
	)
{
	return OTAPI_Wrap::issueBasket(
		SERVER_ID,
		USER_ID,
		THE_BASKET
		);
}

string OTAPI_Basic::GenerateBasketExchange(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & BASKET_ASSET_TYPE_ID,
	const string & BASKET_ASSET_ACCT_ID,
	// -------------------------------------
	const long & TRANSFER_MULTIPLE
	)
{
	return OTAPI_Wrap::GenerateBasketExchange(
		SERVER_ID,
		USER_ID,
		BASKET_ASSET_TYPE_ID,
		BASKET_ASSET_ACCT_ID,
		TRANSFER_MULTIPLE
		);
}

string OTAPI_Basic::AddBasketExchangeItem(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & THE_BASKET, 
	const string & ASSET_TYPE_ID,
	const string & ASSET_ACCT_ID
	)
{
	return OTAPI_Wrap::AddBasketExchangeItem(
		SERVER_ID,
		USER_ID,
		THE_BASKET,
		ASSET_TYPE_ID,
		ASSET_ACCT_ID
		);
}

long OTAPI_Basic::exchangeBasket(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & BASKET_ASSET_ID,
	const string & THE_BASKET,
	const bool & BOOL_EXCHANGE_IN_OR_OUT
	)
{
	return OTAPI_Wrap::exchangeBasket(
		SERVER_ID,
		USER_ID,
		BASKET_ASSET_ID,
		THE_BASKET,
		BOOL_EXCHANGE_IN_OR_OUT
		);
}

long OTAPI_Basic::notarizeWithdrawal(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & ACCT_ID,
	const string & AMOUNT
	)
{
	return OTAPI_Wrap::notarizeWithdrawal(
		SERVER_ID,
		USER_ID,
		ACCT_ID,
		AMOUNT
		);
}

long OTAPI_Basic::notarizeDeposit(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & ACCT_ID,
	const string & THE_PURSE
	)
{
	return OTAPI_Wrap::notarizeDeposit(
		SERVER_ID,
		USER_ID,
		ACCT_ID,
		THE_PURSE
		);
}

long OTAPI_Basic::notarizeTransfer(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & ACCT_FROM,
	const string & ACCT_TO,
	const string & AMOUNT,
	const string & NOTE
	)
{
	//const int64_t lAMOUNT = OTAPI_Wrap::StringToLong(AMOUNT);

	return OTAPI_Wrap::notarizeTransfer(
		SERVER_ID,
		USER_ID,
		ACCT_FROM,
		ACCT_TO,
		AMOUNT,
		NOTE
		);
}

long OTAPI_Basic::getInbox(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & ACCT_ID
	)
{
	return OTAPI_Wrap::getInbox(
		SERVER_ID,
		USER_ID,
		ACCT_ID
		);
}

long OTAPI_Basic::getOutbox(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & ACCT_ID
	)
{
	return OTAPI_Wrap::getOutbox(
		SERVER_ID,
		USER_ID,
		ACCT_ID
		);
}

long OTAPI_Basic::getNymbox(
	const string & SERVER_ID,
	const string & USER_ID
	)
{
	return OTAPI_Wrap::getNymbox(
		SERVER_ID,
		USER_ID
		);
}

string OTAPI_Basic::LoadNymbox(
	const string & SERVER_ID,
	const string & USER_ID
	)
{
	return OTAPI_Wrap::LoadNymbox(
		SERVER_ID,
		USER_ID
		);				
}

string OTAPI_Basic::LoadNymboxNoVerify(
	const string & SERVER_ID,
	const string & USER_ID
	)
{
	return OTAPI_Wrap::LoadNymboxNoVerify(
		SERVER_ID,
		USER_ID
		);	
}

string OTAPI_Basic::Nymbox_GetReplyNotice(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & REQUEST_NUMBER
	)
{
	//const int64_t lREQUEST_NUMBER = OTAPI_Wrap::StringToLong(REQUEST_NUMBER);

	return OTAPI_Wrap::Nymbox_GetReplyNotice(
		SERVER_ID,
		USER_ID,
		REQUEST_NUMBER
		);	
}

bool OTAPI_Basic::HaveAlreadySeenReply(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & REQUEST_NUMBER
	)
{
	//const int64_t lREQUEST_NUMBER = OTAPI_Wrap::StringToLong(REQUEST_NUMBER);

	return OTAPI_Wrap::HaveAlreadySeenReply(
		SERVER_ID,
		USER_ID,
		REQUEST_NUMBER
		);
}

long OTAPI_Basic::getBoxReceipt(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & ACCOUNT_ID,
	const long & nBoxType,
	const string & TRANSACTION_NUMBER
	)
{
	//const int64_t lTRANSACTION_NUMBER = OTAPI_Wrap::StringToLong(TRANSACTION_NUMBER);

	return OTAPI_Wrap::getBoxReceipt(
		SERVER_ID,
		USER_ID,
		ACCOUNT_ID,
		nBoxType,
		TRANSACTION_NUMBER
		);
}

bool OTAPI_Basic::DoesBoxReceiptExist(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & ACCOUNT_ID,
	const long & nBoxType,
	const string & TRANSACTION_NUMBER
	)
{
	//const int64_t lTRANSACTION_NUMBER = OTAPI_Wrap::StringToLong(TRANSACTION_NUMBER);

	return OTAPI_Wrap::DoesBoxReceiptExist(
		SERVER_ID,
		USER_ID,
		ACCOUNT_ID,
		nBoxType,
		TRANSACTION_NUMBER
		);
}
long OTAPI_Basic::processInbox(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & ACCT_ID,
	const string & ACCT_LEDGER
	)
{
	return OTAPI_Wrap::processInbox(
		SERVER_ID,
		USER_ID,
		ACCT_ID,
		ACCT_LEDGER
		);
}

long OTAPI_Basic::processNymbox(
	const string & SERVER_ID,
	const string & USER_ID
	)
{
	return OTAPI_Wrap::processNymbox(
		SERVER_ID,
		USER_ID
		);
}

long OTAPI_Basic::withdrawVoucher(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & ACCT_ID,
	const string & RECIPIENT_USER_ID,
	const string & CHEQUE_MEMO,
	const string & AMOUNT
	)
{
	//const int64_t lAMOUNT = OTAPI_Wrap::StringToLong(AMOUNT);

	return OTAPI_Wrap::withdrawVoucher(
		SERVER_ID,
		USER_ID,
		ACCT_ID,
		RECIPIENT_USER_ID,
		CHEQUE_MEMO,
		AMOUNT
		);
}

long OTAPI_Basic::payDividend(
	const string & SERVER_ID,
	const string & ISSUER_USER_ID,
	const string & DIVIDEND_FROM_ACCT_ID,
	const string & SHARES_ASSET_TYPE_ID,
	const string & DIVIDEND_MEMO,
	const string & AMOUNT_PER_SHARE
	)
{
	//const int64_t lAMOUNT_PER_SHARE = OTAPI_Wrap::StringToLong(AMOUNT_PER_SHARE);

	return OTAPI_Wrap::payDividend(
		SERVER_ID,
		ISSUER_USER_ID,
		DIVIDEND_FROM_ACCT_ID,
		SHARES_ASSET_TYPE_ID,
		DIVIDEND_MEMO,
		AMOUNT_PER_SHARE
		);
}

long OTAPI_Basic::depositCheque(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & ACCT_ID,
	const string & THE_CHEQUE
	)
{
	return OTAPI_Wrap::depositCheque(
		SERVER_ID,
		USER_ID,
		ACCT_ID,
		THE_CHEQUE
		);
}

long OTAPI_Basic::depositPaymentPlan(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & THE_PAYMENT_PLAN
	)
{
	return OTAPI_Wrap::depositPaymentPlan(
		SERVER_ID,
		USER_ID,
		THE_PAYMENT_PLAN
		);
}

long OTAPI_Basic::issueMarketOffer(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & ASSET_TYPE_ID,
	const string & ASSET_ACCT_ID,
	const string & CURRENCY_TYPE_ID,
	const string & CURRENCY_ACCT_ID,
	const string & MARKET_SCALE,
	const string & MINIMUM_INCREMENT,
	const string & TOTAL_ASSETS_ON_OFFER,
	const string & PRICE_LIMIT,
	const bool & bBuyingOrSelling
	)
{

	return OTAPI_Wrap::issueMarketOffer(
		SERVER_ID,
		USER_ID,
		ASSET_TYPE_ID,
		ASSET_ACCT_ID,
		CURRENCY_TYPE_ID,
		CURRENCY_ACCT_ID,
		MARKET_SCALE,
		MINIMUM_INCREMENT,
		TOTAL_ASSETS_ON_OFFER,
		PRICE_LIMIT,
		bBuyingOrSelling
		);
}

long OTAPI_Basic::getMarketList(
	const string & SERVER_ID,
	const string & USER_ID
	)
{
	return OTAPI_Wrap::getMarketList(
		SERVER_ID,
		USER_ID
		);
}

long OTAPI_Basic::getMarketOffers(
	const string & SERVER_ID,
	const string & USER_ID, 
	const string & MARKET_ID,
	const string & MAX_DEPTH
	)
{
	//const int64_t lMAX_DEPTH = OTAPI_Wrap::StringToLong(MAX_DEPTH);

	return OTAPI_Wrap::getMarketOffers(
		SERVER_ID,
		USER_ID,
		MARKET_ID,
		MAX_DEPTH
		);
}

long OTAPI_Basic::getMarketRecentTrades(
	const string & SERVER_ID,
	const string & USER_ID, 
	const string & MARKET_ID
	)
{
	return OTAPI_Wrap::getMarketRecentTrades(
		SERVER_ID,
		USER_ID,
		MARKET_ID
		);
}

long OTAPI_Basic::getNym_MarketOffers(
	const string & SERVER_ID,
	const string & USER_ID
	)
{
	return OTAPI_Wrap::getNym_MarketOffers(
		SERVER_ID,
		USER_ID
		);
}

long OTAPI_Basic::cancelMarketOffer(
	const string & SERVER_ID, 
	const string & USER_ID, 
	const string & ASSET_ACCT_ID, 
	const string & TRANSACTION_NUMBER
	)
{
	//const int64_t lTRANSACTION_NUMBER = OTAPI_Wrap::StringToLong(TRANSACTION_NUMBER);

	return OTAPI_Wrap::cancelMarketOffer(
		SERVER_ID,
		USER_ID,
		ASSET_ACCT_ID,
		TRANSACTION_NUMBER
		);
}

long OTAPI_Basic::cancelPaymentPlan(
	const string & SERVER_ID, 
	const string & USER_ID, 
	const string & FROM_ACCT_ID, 
	const string & TRANSACTION_NUMBER
	)
{
	//const int64_t lTRANSACTION_NUMBER = OTAPI_Wrap::StringToLong(TRANSACTION_NUMBER);

	return OTAPI_Wrap::cancelPaymentPlan(
		SERVER_ID,
		USER_ID,
		FROM_ACCT_ID,
		TRANSACTION_NUMBER
		);	
}

string OTAPI_Basic::PopMessageBuffer(
	const string & REQUEST_NUMBER,
	const string & SERVER_ID, 
	const string & USER_ID
	)
{
	//const int64_t lREQUEST_NUMBER = OTAPI_Wrap::StringToLong(REQUEST_NUMBER);

	return OTAPI_Wrap::PopMessageBuffer(
		REQUEST_NUMBER,
		SERVER_ID,
		USER_ID
		);
}

void OTAPI_Basic::FlushMessageBuffer()
{
	return OTAPI_Wrap::FlushMessageBuffer();
}

string OTAPI_Basic::GetSentMessage(
	const string & REQUEST_NUMBER,
	const string & SERVER_ID, 
	const string & USER_ID
	)
{	
	//const int64_t lREQUEST_NUMBER = OTAPI_Wrap::StringToLong(REQUEST_NUMBER);

	return OTAPI_Wrap::GetSentMessage(
		REQUEST_NUMBER,
		SERVER_ID,
		USER_ID
		);	
}

bool OTAPI_Basic::RemoveSentMessage(
	const string & REQUEST_NUMBER,
	const string & SERVER_ID, 
	const string & USER_ID
	)
{	
	//const int64_t lREQUEST_NUMBER = OTAPI_Wrap::StringToLong(REQUEST_NUMBER);

	return OTAPI_Wrap::RemoveSentMessage(
		REQUEST_NUMBER,
		SERVER_ID,
		USER_ID
		);
}

void OTAPI_Basic::FlushSentMessages(
	const bool & bHarvestingForRetry,
	const string & SERVER_ID, 
	const string & USER_ID,
	const string & THE_NYMBOX
	)
{
	return OTAPI_Wrap::FlushSentMessages(
		bHarvestingForRetry,
		SERVER_ID,
		USER_ID,
		THE_NYMBOX
		);
}

void OTAPI_Basic::Sleep(const string & MILLISECONDS)
{
	//const int64_t lMILLISECONDS = OTAPI_Wrap::StringToLong(MILLISECONDS);

	return OTAPI_Wrap::Sleep(
		MILLISECONDS
		//MILLISECONDS
		);
}

bool OTAPI_Basic::ResyncNymWithServer(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & THE_MESSAGE
	)
{
	return OTAPI_Wrap::ResyncNymWithServer(
		SERVER_ID,
		USER_ID,
		THE_MESSAGE
		);
}

string OTAPI_Basic::Message_GetCommand(const string & THE_MESSAGE)
{
	return OTAPI_Wrap::Message_GetCommand(
		THE_MESSAGE
		);		
}

long OTAPI_Basic::Message_GetSuccess(const string & THE_MESSAGE)
{
	return OTAPI_Wrap::Message_GetSuccess(
		THE_MESSAGE
		);	
}

long OTAPI_Basic::queryAssetTypes(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & ENCODED_MAP
	)
{
	return OTAPI_Wrap::queryAssetTypes(
		SERVER_ID,
		USER_ID,
		ENCODED_MAP
		);	
}

string OTAPI_Basic::Message_GetPayload(const string & THE_MESSAGE)
{
	return OTAPI_Wrap::Message_GetPayload(
		THE_MESSAGE
		);		
}

string OTAPI_Basic::Message_GetDepth(const string & THE_MESSAGE)
{
	return OTAPI_Wrap::LongToString(OTAPI_Wrap::Message_GetDepth(
		THE_MESSAGE
		));
}

long OTAPI_Basic::Message_GetTransactionSuccess(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & ACCOUNT_ID,
	const string & THE_MESSAGE
	)
{
	return OTAPI_Wrap::Message_GetTransactionSuccess(
		SERVER_ID,
		USER_ID,
		ACCOUNT_ID,
		THE_MESSAGE
		);
}

long OTAPI_Basic::Message_GetBalanceAgreementSuccess(
	const string & SERVER_ID,
	const string & USER_ID,
	const string & ACCOUNT_ID,
	const string & THE_MESSAGE
	)
{
	return OTAPI_Wrap::Message_GetBalanceAgreementSuccess(
		SERVER_ID,
		USER_ID,
		ACCOUNT_ID,
		THE_MESSAGE
		);
}

string OTAPI_Basic::Message_GetLedger(const string & THE_MESSAGE)
{
	return OTAPI_Wrap::Message_GetLedger(
		THE_MESSAGE
		);			
}

string OTAPI_Basic::Message_GetNewAssetTypeID(const string & THE_MESSAGE)
{
	return OTAPI_Wrap::Message_GetNewAssetTypeID(
		THE_MESSAGE
		);	
}

string OTAPI_Basic::Message_GetNewIssuerAcctID(const string & THE_MESSAGE)
{
	return OTAPI_Wrap::Message_GetNewIssuerAcctID(
		THE_MESSAGE
		);
}

string OTAPI_Basic::Message_GetNewAcctID(const string & THE_MESSAGE)
{
	return OTAPI_Wrap::Message_GetNewAcctID(
		THE_MESSAGE
		);
}

string OTAPI_Basic::Message_GetNymboxHash(const string & THE_MESSAGE)
{
	return OTAPI_Wrap::Message_GetNymboxHash(
		THE_MESSAGE
		);
}

bool OTAPI_Basic::ConnectServer(
	const string & SERVER_ID,
	const string & USER_ID, 
	const string & strCA_FILE,
	const string & strKEY_FILE, 
	const string & strKEY_PASSWORD
	)
{
	return OTAPI_Wrap::ConnectServer(
		SERVER_ID,
		USER_ID,
		strCA_FILE,
		strKEY_FILE,
		strKEY_PASSWORD
		);
}

bool OTAPI_Basic::ProcessSockets()
{
	return OTAPI_Wrap::ProcessSockets();
}
