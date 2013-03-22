// This is the main DLL file.

/************************************************************
 -----BEGIN PGP SIGNED MESSAGE-----
 Hash: SHA1
 
 *                 OPEN TRANSACTIONS
 *
 *       Financial Cryptography and Digital Cash
 *       Library, Protocol, API, Server, CLI, GUI
 *
 *       -- Anonymous Numbered Accounts.
 *       -- Untraceable Digital Cash.
 *       -- Triple-Signed Receipts.
 *       -- Cheques, Vouchers, Transfers, Inboxes.
 *       -- Basket Currencies, Markets, Payment Plans.
 *       -- Signed, XML, Ricardian-style Contracts.
 *       -- Scripted smart contracts.
 *
 *  Copyright (C) 2010-2013 by "Fellow Traveler" (A pseudonym)
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
 *   -- otlib.........A class library.......LICENSE:...LAGPLv3
 *   -- otapi.........A client API..........LICENSE:...LAGPLv3
 *   -- opentxs/ot....Command-line client...LICENSE:...LAGPLv3
 *   -- otserver......Server Application....LICENSE:....AGPLv3
 *  Github.com/FellowTraveler/Open-Transactions/wiki/Components
 *
 *  All of the above OT components were designed and written by
 *  Fellow Traveler, with the exception of Moneychanger, which
 *  was contracted out to Vicky C (bitcointrader4@gmail.com).
 *  The open-source community has since actively contributed.
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
 *   (==> This means if you are only using the OT API, then you
 *   don't have to open-source your code--only your changes to
 *   Open-Transactions itself must be open source. Similar to
 *   LGPLv3, except it applies to software-as-a-service, not
 *   just to distributing binaries.)
 *
 *   Extra WAIVER for OpenSSL, Lucre, and all other libraries
 *   used by Open Transactions: This program is released under
 *   the AGPL with the additional exemption that compiling,
 *   linking, and/or using OpenSSL is allowed. The same is true
 *   for any other open source libraries included in this
 *   project: complete waiver from the AGPL is hereby granted to
 *   compile, link, and/or use them with Open-Transactions,
 *   according to their own terms, as long as the rest of the
 *   Open-Transactions terms remain respected, with regard to
 *   the Open-Transactions code itself.
 *
 *   Lucre License:
 *   This code is also "dual-license", meaning that Ben Lau-
 *   rie's license must also be included and respected, since
 *   the code for Lucre is also included with Open Transactions.
 *   See Open-Transactions/src/otlib/lucre/LUCRE_LICENSE.txt
 *   The Laurie requirements are light, but if there is any
 *   problem with his license, simply remove the Lucre code.
 *   Although there are no other blind token algorithms in Open
 *   Transactions (yet. credlib is coming), the other functions
 *   will continue to operate.
 *   See Lucre on Github:  https://github.com/benlaurie/lucre
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
 Version: GnuPG v1.4.9 (Darwin)
 
 iQIcBAEBAgAGBQJRSsfJAAoJEAMIAO35UbuOQT8P/RJbka8etf7wbxdHQNAY+2cC
 vDf8J3X8VI+pwMqv6wgTVy17venMZJa4I4ikXD/MRyWV1XbTG0mBXk/7AZk7Rexk
 KTvL/U1kWiez6+8XXLye+k2JNM6v7eej8xMrqEcO0ZArh/DsLoIn1y8p8qjBI7+m
 aE7lhstDiD0z8mwRRLKFLN2IH5rAFaZZUvj5ERJaoYUKdn4c+RcQVei2YOl4T0FU
 LWND3YLoH8naqJXkaOKEN4UfJINCwxhe5Ke9wyfLWLUO7NamRkWD2T7CJ0xocnD1
 sjAzlVGNgaFDRflfIF4QhBx1Ddl6wwhJfw+d08bjqblSq8aXDkmFA7HeunSFKkdn
 oIEOEgyj+veuOMRJC5pnBJ9vV+7qRdDKQWaCKotynt4sWJDGQ9kWGWm74SsNaduN
 TPMyr9kNmGsfR69Q2Zq/FLcLX/j8ESxU+HYUB4vaARw2xEOu2xwDDv6jt0j3Vqsg
 x7rWv4S/Eh18FDNDkVRChiNoOIilLYLL6c38uMf1pnItBuxP3uhgY6COm59kVaRh
 nyGTYCDYD2TK+fI9o89F1297uDCwEJ62U0Q7iTDp5QuXCoxkPfv8/kX6lS6T3y9G
 M9mqIoLbIQ1EDntFv7/t6fUTS2+46uCrdZWbQ5RjYXdrzjij02nDmJAm2BngnZvd
 kamH0Y/n11lCvo1oQxM+
 =uSzz
 -----END PGP SIGNATURE-----
 **************************************************************/

#include <stdafx.h>

#include <otapi\otapicli.h>

#define IMPORT
#include <otapi\OTAPI.h>

#include <String>
#include <iostream>

#include <vector>

//#include <vcclr.h>

using namespace otapicli;
using namespace std;

otapi_wrap::otapi_wrap() {

};

otapi_wrap::~otapi_wrap() {

};

static string Native (String ^% s) {
	using namespace Runtime::InteropServices;

	IntPtr p_sz(Marshal::StringToHGlobalAnsi(const_cast<String ^>(s)).ToPointer());
	Int32 n_p_sz = safe_cast<Int32>(p_sz);
	long l_p_sz = safe_cast<long>(n_p_sz);

	const char * chars(reinterpret_cast<const char *>(l_p_sz));

	string str(chars);

	Marshal::FreeHGlobal(IntPtr((void*)chars));
	return str;
};

static String ^ Managed (const string& os) { return gcnew String(os.c_str()); };

//static wstring NativeW (String ^% s) {
//	using namespace Runtime::InteropServices;
//
//	IntPtr p_sz(Marshal::StringToHGlobalUni(const_cast<String ^>(s)).ToPointer());
//	Int32 n_p_sz = safe_cast<Int32>(p_sz);
//	long l_p_sz = safe_cast<long>(n_p_sz);
//
//	const wchar_t * chars(reinterpret_cast<const wchar_t *>(l_p_sz));
//
//	wstring str(chars);
//	Marshal::FreeHGlobal(IntPtr((void*)chars));
//	return str;
//};

//static String ^ Managed (const wstring& os) { return gcnew String(os.c_str()); };

static int32_t Native (Int32 % m_int) {
	int32_t ^ n_int = m_int;
	return *n_int;
};

static Int32 Managed (int32_t & n_int) {
	Int32 ^ m_int = n_int;
	return *m_int;
};

static int64_t Native (Int64 % m_int) {
	int64_t ^ n_int = m_int;
	return *n_int;
};

static Int64 Managed (int64_t & n_int) {
	Int64 ^ m_int = n_int;
	return *m_int;
};

static time_t Native (DateTime % dt) {
	DateTime ^ startTime = gcnew DateTime (1970, 1, 1);
	return static_cast<time_t>((dt - *startTime).TotalSeconds);
};

static DateTime Managed (const time_t& time)
{
	const int64_t win32FileTime = 10000000*static_cast<int64_t>(time) + 116444736000000000;
	return DateTime::FromFileTimeUtc(static_cast<long>(win32FileTime));
};

static time_t Native (TimeSpan % ts) {
	return static_cast<time_t>((ts).TotalSeconds);
};

static TimeSpan ManagedTimeSpan (const time_t& time)
{
	const int64_t win32FileTime = 10000000*static_cast<int64_t>(time);
	return TimeSpan::FromTicks(static_cast<long>(win32FileTime));
};




Int64 otapi_wrap::StringToLong(String ^% strNumber)
{
	return OTAPI_Wrap::StringToLong(Native(strNumber));
}

String ^ otapi_wrap::LongToString(Int64 % lNumber)
{
	Int64 n_Int64 = lNumber;
	return Managed(OTAPI_Wrap::LongToString(n_Int64));
}

Boolean otapi_wrap::Init()
{
	return (NULL != OTAPI_Wrap::It());
}

Boolean otapi_wrap::SetWallet(String ^% strWalletFilename)
{
	return OTAPI_Wrap::SetWallet(Native(strWalletFilename));
}

Boolean otapi_wrap::WalletExists()
{
	return OTAPI_Wrap::WalletExists();
}

Boolean otapi_wrap::LoadWallet()
{
	return OTAPI_Wrap::LoadWallet();
}

Boolean otapi_wrap::SwitchWallet()
{
	return OTAPI_Wrap::SwitchWallet();
}

void otapi_wrap::Output(
	Int32 % nLogLevel,
	String ^% strOutput
	)
{
	Int32 n_Int32 = nLogLevel;
	return OTAPI_Wrap::Output(
		n_Int32,
		Native(strOutput)
		);
}

Int64 otapi_wrap::GetTime()
{
	return OTAPI_Wrap::GetTime();
}


String ^ otapi_wrap::NumList_Add(
	String ^% strNumList,
	String ^% strNumbers
	)
{
	return Managed(OTAPI_Wrap::NumList_Add(Native(strNumList),Native(strNumbers)));
}

String ^ otapi_wrap::NumList_Remove(
	String ^% strNumList,
	String ^% strNumbers
	)
{
	return Managed(OTAPI_Wrap::NumList_Remove(Native(strNumList),Native(strNumbers)));
}

Boolean otapi_wrap::NumList_VerifyQuery(
	String ^% strNumList,
	String ^% strNumbers
	)
{
	return OTAPI_Wrap::NumList_VerifyQuery(Native(strNumList),Native(strNumbers));
}

Boolean otapi_wrap::NumList_VerifyAll(
	String ^% strNumList,
	String ^% strNumbers
	)
{
	return OTAPI_Wrap::NumList_VerifyAll(Native(strNumList),Native(strNumbers));
}

Int32 otapi_wrap::NumList_Count(
	String ^% strNumList
	)
{
	return OTAPI_Wrap::NumList_Count(Native(strNumList));
}

String ^ otapi_wrap::Encode(
	String ^% strPlaInt32ext,
	Boolean % bLineBreaks
	)
{
	Boolean n_bLineBreaks = bLineBreaks;
	return Managed(OTAPI_Wrap::Encode(Native(strPlaInt32ext),n_bLineBreaks));
}

String ^ otapi_wrap::Decode(
	String ^% strEncoded,
	Boolean % bLineBreaks
	)
{
	Boolean n_bLineBreaks = bLineBreaks;
	return Managed(OTAPI_Wrap::Decode(Native(strEncoded),n_bLineBreaks));
}

String ^ otapi_wrap::Encrypt(
	String ^% RECIPIENT_NYM_ID,
	String ^% strPlaInt32ext
	)
{
	return Managed(OTAPI_Wrap::Encrypt(Native(RECIPIENT_NYM_ID),Native(strPlaInt32ext)));
}

String ^ otapi_wrap::Decrypt(
	String ^% RECIPIENT_NYM_ID,
	String ^% strCiphertext
	)
{
	return Managed(OTAPI_Wrap::Decrypt(Native(RECIPIENT_NYM_ID),Native(strCiphertext)));
}

String ^ otapi_wrap::CreateSymmetricKey()
{
	return Managed(OTAPI_Wrap::CreateSymmetricKey());
}

String ^ otapi_wrap::SymmetricEncrypt(
	String ^% SYMMETRIC_KEY,
	String ^% PLAINTEXT
	)
{
	return Managed(OTAPI_Wrap::SymmetricEncrypt(Native(SYMMETRIC_KEY),Native(PLAINTEXT)));
}

String ^ otapi_wrap::SymmetricDecrypt(
	String ^% SYMMETRIC_KEY,
	String ^% CIPHERTEXT_ENVELOPE
	)
{
	return Managed(OTAPI_Wrap::SymmetricDecrypt(Native(SYMMETRIC_KEY),Native(CIPHERTEXT_ENVELOPE)));
}

String ^ otapi_wrap::SignContract(
	String ^% SIGNER_NYM_ID,
	String ^% THE_CONTRACT
	)
{
	return Managed(OTAPI_Wrap::SignContract(Native(SIGNER_NYM_ID),Native(THE_CONTRACT)));
}

String ^ otapi_wrap::FlatSign(String ^% SIGNER_NYM_ID, String ^% THE_INPUT, String ^% CONTRACT_TYPE)
{
	return Managed(OTAPI_Wrap::FlatSign(Native(SIGNER_NYM_ID),Native(THE_INPUT),Native(CONTRACT_TYPE)));
}

String ^ otapi_wrap::AddSignature(
	String ^% SIGNER_NYM_ID,
	String ^% THE_CONTRACT
	)
{
	return Managed(OTAPI_Wrap::AddSignature(Native(SIGNER_NYM_ID),Native(THE_CONTRACT)));
}

Boolean otapi_wrap::VerifySignature(
	String ^% SIGNER_NYM_ID,
	String ^% THE_CONTRACT
	)
{
	return OTAPI_Wrap::VerifySignature(Native(SIGNER_NYM_ID),Native(THE_CONTRACT));
}

String ^ otapi_wrap::VerifyAndRetrieveXMLContents(
	String ^% THE_CONTRACT,
	String ^% SIGNER_ID
	)
{
	return Managed(OTAPI_Wrap::VerifyAndRetrieveXMLContents(Native(THE_CONTRACT),Native(SIGNER_ID)));
}

Int32 otapi_wrap::GetMemlogSize()
{
	return OTAPI_Wrap::GetMemlogSize();
}

String ^ otapi_wrap::GetMemlogAtIndex(Int32 % nIndex)
{
	Int32 n_nIndex = nIndex;
	return Managed(OTAPI_Wrap::GetMemlogAtIndex(n_nIndex));
}

String ^ otapi_wrap::PeekMemlogFront()
{
	return Managed(OTAPI_Wrap::PeekMemlogFront());
}
String ^ otapi_wrap::PeekMemlogBack()
{
	return Managed(OTAPI_Wrap::PeekMemlogBack());
}
Boolean otapi_wrap::PopMemlogFront()
{
		return OTAPI_Wrap::PopMemlogFront();
}
Boolean otapi_wrap::PopMemlogBack()
{
		return OTAPI_Wrap::PopMemlogBack();
}

String ^ otapi_wrap::CreateNym(Int32 % nKeySize, String ^% NYM_ID_SOURCE, String ^% ALT_LOCATION)
{
	Int32 n_nKeySize = nKeySize;
	return Managed(OTAPI_Wrap::CreateNym(n_nKeySize,Native(NYM_ID_SOURCE),Native(ALT_LOCATION)));
}

String ^ otapi_wrap::CreateServerContract(
	String ^% NYM_ID,
	String ^% strXMLcontents
	)
{
	return Managed(OTAPI_Wrap::CreateServerContract(Native(NYM_ID),Native(strXMLcontents)));
}

String ^ otapi_wrap::CreateAssetContract(
	String ^% NYM_ID,
	String ^% strXMLcontents
	)
{
	return Managed(OTAPI_Wrap::CreateAssetContract(Native(NYM_ID),Native(strXMLcontents)));
}

Int32 otapi_wrap::AddServerContract(String ^% strContract)
{
	return OTAPI_Wrap::AddServerContract(Native(strContract));
}

Int32 otapi_wrap::AddAssetContract(String ^% strContract)
{
	return OTAPI_Wrap::AddAssetContract(Native(strContract));
}

Int32 otapi_wrap::GetServerCount(void) { return OTAPI_Wrap::GetServerCount(); }
Int32 otapi_wrap::GetAssetTypeCount(void) { return OTAPI_Wrap::GetAssetTypeCount(); }
Int32 otapi_wrap::GetAccountCount(void) { return OTAPI_Wrap::GetAccountCount(); }
Int32 otapi_wrap::GetNymCount(void) { return OTAPI_Wrap::GetNymCount(); }

String ^ otapi_wrap::GetServer_ID(Int32 % nIndex)
{
	Int32 n_nIndex = nIndex;
	return Managed(OTAPI_Wrap::GetServer_ID(n_nIndex));
}
String ^ otapi_wrap::GetServer_Name(String ^% SERVER_ID) { return Managed(OTAPI_Wrap::GetServer_Name(Native(SERVER_ID))); }
String ^ otapi_wrap::GetServer_Contract(String ^% SERVER_ID)  { return Managed(OTAPI_Wrap::GetServer_Contract(Native(SERVER_ID))); }
String ^ otapi_wrap::GetAssetType_ID(Int32 % nIndex)
{
	Int32 n_nIndex = nIndex;
	return Managed(OTAPI_Wrap::GetAssetType_ID(n_nIndex));
}
String ^ otapi_wrap::GetAssetType_Name(String ^% ASSET_TYPE_ID)  { return Managed(OTAPI_Wrap::GetAssetType_Name(Native(ASSET_TYPE_ID))); }
String ^ otapi_wrap::GetAssetType_Contract(String ^% ASSET_TYPE_ID)  { return Managed(OTAPI_Wrap::GetAssetType_Contract(Native(ASSET_TYPE_ID))); }

String ^ otapi_wrap::GetAccountWallet_ID(Int32 % nIndex)
{
	Int32 n_nIndex = nIndex;
	return Managed(OTAPI_Wrap::GetAccountWallet_ID(n_nIndex));
}
String ^ otapi_wrap::GetAccountWallet_Name(String ^% ACCOUNT_ID)  { return Managed(OTAPI_Wrap::GetAccountWallet_Name(Native(ACCOUNT_ID))); }

Int64 otapi_wrap::GetAccountWallet_Balance(String ^% ACCOUNT_ID)
{
	int64_t ret = OTAPI_Wrap::GetAccountWallet_Balance(Native(ACCOUNT_ID));
	return Managed(ret);
}
String ^ otapi_wrap::GetAccountWallet_Type(String ^% ACCOUNT_ID)  { return Managed(OTAPI_Wrap::GetAccountWallet_Type(Native(ACCOUNT_ID))); }
String ^ otapi_wrap::GetAccountWallet_AssetTypeID(String ^% ACCOUNT_ID)  { return Managed(OTAPI_Wrap::GetAccountWallet_AssetTypeID(Native(ACCOUNT_ID))); }
String ^ otapi_wrap::GetAccountWallet_ServerID(String ^% ACCOUNT_ID)  { return Managed(OTAPI_Wrap::GetAccountWallet_ServerID(Native(ACCOUNT_ID))); }
String ^ otapi_wrap::GetAccountWallet_NymID(String ^% ACCOUNT_ID)  { return Managed(OTAPI_Wrap::GetAccountWallet_NymID(Native(ACCOUNT_ID))); }

String ^ otapi_wrap::GetAccountWallet_InboxHash(String ^% ACCOUNT_ID)  { return Managed(OTAPI_Wrap::GetAccountWallet_InboxHash(Native(ACCOUNT_ID))); }
String ^ otapi_wrap::GetAccountWallet_OutboxHash(String ^% ACCOUNT_ID) { return Managed(OTAPI_Wrap::GetAccountWallet_OutboxHash(Native(ACCOUNT_ID))); }

Boolean otapi_wrap::VerifyAccountReceipt(
	String ^% SERVER_ID,
	String ^% NYM_ID,
	String ^% ACCT_ID
	)
{
	return OTAPI_Wrap::VerifyAccountReceipt(Native(SERVER_ID),Native(NYM_ID),Native(ACCT_ID));
}

Int32 otapi_wrap::GetNym_TransactionNumCount(
	String ^% SERVER_ID,
	String ^% NYM_ID
	)
{
	return OTAPI_Wrap::GetNym_TransactionNumCount(Native(SERVER_ID),Native(NYM_ID));
}

String ^ otapi_wrap::GetNym_ID(Int32 % nIndex)
{
	Int32 n_nIndex = nIndex;
	return Managed(OTAPI_Wrap::GetNym_ID(n_nIndex));
}

String ^ otapi_wrap::GetNym_Name(String ^% NYM_ID)  { return Managed(OTAPI_Wrap::GetNym_Name(Native(NYM_ID))); }
String ^ otapi_wrap::GetNym_Stats(String ^% NYM_ID)  { return Managed(OTAPI_Wrap::GetNym_Stats(Native(NYM_ID))); }

String ^ otapi_wrap::GetNym_NymboxHash(
	String ^% SERVER_ID,
	String ^% NYM_ID 
	)
{
	return Managed(OTAPI_Wrap::GetNym_NymboxHash(Native(SERVER_ID),Native(NYM_ID)));
}

String ^ otapi_wrap::GetNym_RecentHash(
	String ^% SERVER_ID,
	String ^% NYM_ID
	)
{
	return Managed(OTAPI_Wrap::GetNym_RecentHash(Native(SERVER_ID),Native(NYM_ID)));
}

String ^ otapi_wrap::GetNym_InboxHash(
	String ^% ACCOUNT_ID,
	String ^% NYM_ID
	)
{
	return Managed(OTAPI_Wrap::GetNym_InboxHash(Native(ACCOUNT_ID),Native(NYM_ID)));
}

String ^ otapi_wrap::GetNym_OutboxHash(
	String ^% ACCOUNT_ID,
	String ^% NYM_ID
	)
{
	return Managed(OTAPI_Wrap::GetNym_OutboxHash(Native(ACCOUNT_ID),Native(NYM_ID)));
}

Boolean otapi_wrap::IsNym_RegisteredAtServer(String ^% NYM_ID, String ^% SERVER_ID) { return OTAPI_Wrap::IsNym_RegisteredAtServer(Native(NYM_ID),Native(SERVER_ID)); }

Int32 otapi_wrap::GetNym_MailCount(String ^% NYM_ID) { return OTAPI_Wrap::GetNym_MailCount(Native(NYM_ID)); }

String ^ otapi_wrap::GetNym_MailContentsByIndex(
	String ^% NYM_ID,
	Int32 % nIndex
	)
{
	Int32 n_nIndex = nIndex;
	return Managed(OTAPI_Wrap::GetNym_MailContentsByIndex(Native(NYM_ID),n_nIndex));
}

String ^ otapi_wrap::GetNym_MailSenderIDByIndex(
	String ^% NYM_ID,
	Int32 % nIndex
	)
{
	Int32 n_nIndex = nIndex;
	return Managed(OTAPI_Wrap::GetNym_MailSenderIDByIndex(Native(NYM_ID),n_nIndex));
}

String ^ otapi_wrap::GetNym_MailServerIDByIndex(
	String ^% NYM_ID,
	Int32 % nIndex
	)
{
	Int32 n_nIndex = nIndex;
	return Managed(OTAPI_Wrap::GetNym_MailServerIDByIndex(Native(NYM_ID),n_nIndex));
}


Boolean otapi_wrap::Nym_RemoveMailByIndex(
	String ^% NYM_ID,
	Int32 % nIndex
	)
{
	Int32 n_nIndex = nIndex;
	return OTAPI_Wrap::Nym_RemoveMailByIndex(Native(NYM_ID),n_nIndex);
}

Boolean otapi_wrap::Nym_VerifyMailByIndex(
	String ^% NYM_ID,
	Int32 % nIndex
	)
{
	Int32 n_nIndex = nIndex;
	return OTAPI_Wrap::Nym_VerifyMailByIndex(Native(NYM_ID),n_nIndex);
}

Int32 otapi_wrap::GetNym_OutmailCount(String ^% NYM_ID) { return OTAPI_Wrap::GetNym_OutmailCount(Native(NYM_ID)); }

String ^ otapi_wrap::GetNym_OutmailContentsByIndex(
	String ^% NYM_ID,
	Int32 % nIndex
	)
{
	Int32 n_nIndex = nIndex;
	return Managed(OTAPI_Wrap::GetNym_OutmailContentsByIndex(Native(NYM_ID),n_nIndex));
}

String ^ otapi_wrap::GetNym_OutmailRecipientIDByIndex(
	String ^% NYM_ID,
	Int32 % nIndex
	)
{
	Int32 n_nIndex = nIndex;
	return Managed(OTAPI_Wrap::GetNym_OutmailRecipientIDByIndex(Native(NYM_ID),n_nIndex));
}

String ^ otapi_wrap::GetNym_OutmailServerIDByIndex(
	String ^% NYM_ID,
	Int32 % nIndex
	)
{
	Int32 n_nIndex = nIndex;
	return Managed(OTAPI_Wrap::GetNym_OutmailServerIDByIndex(Native(NYM_ID),n_nIndex));
}

Boolean otapi_wrap::Nym_RemoveOutmailByIndex(
	String ^% NYM_ID,
	Int32 % nIndex
	)
{
	Int32 n_nIndex = nIndex;
	return OTAPI_Wrap::Nym_RemoveOutmailByIndex(Native(NYM_ID),n_nIndex);
}

Boolean otapi_wrap::Nym_VerifyOutmailByIndex(
	String ^% NYM_ID,
	Int32 % nIndex
	)
{
	Int32 n_nIndex = nIndex;
	return OTAPI_Wrap::Nym_VerifyOutmailByIndex(Native(NYM_ID),n_nIndex);
}

Int32 otapi_wrap::GetNym_OutpaymentsCount(String ^% NYM_ID) { return OTAPI_Wrap::GetNym_OutpaymentsCount(Native(NYM_ID)); }

String ^ otapi_wrap::GetNym_OutpaymentsContentsByIndex(
	String ^% NYM_ID,
	Int32 % nIndex
	)
{
	Int32 n_nIndex = nIndex;
	return Managed(OTAPI_Wrap::GetNym_OutpaymentsContentsByIndex(Native(NYM_ID),n_nIndex));
}

String ^ otapi_wrap::GetNym_OutpaymentsRecipientIDByIndex(
	String ^% NYM_ID,
	Int32 % nIndex
	)
{
	Int32 n_nIndex = nIndex;
	return Managed(OTAPI_Wrap::GetNym_OutpaymentsRecipientIDByIndex(Native(NYM_ID),n_nIndex));
}

String ^ otapi_wrap::GetNym_OutpaymentsServerIDByIndex(
	String ^% NYM_ID,
	Int32 % nIndex
	)
{
	Int32 n_nIndex = nIndex;
	return Managed(OTAPI_Wrap::GetNym_OutpaymentsServerIDByIndex(Native(NYM_ID),n_nIndex));
}

Boolean otapi_wrap::Nym_RemoveOutpaymentsByIndex(
	String ^% NYM_ID,
	Int32 % nIndex
	)
{
	Int32 n_nIndex = nIndex;
	return OTAPI_Wrap::Nym_RemoveOutpaymentsByIndex(Native(NYM_ID),n_nIndex);
}

Boolean otapi_wrap::Nym_VerifyOutpaymentsByIndex(
	String ^% NYM_ID,
	Int32 % nIndex
	)
{
	Int32 n_nIndex = nIndex;
	return OTAPI_Wrap::Nym_VerifyOutpaymentsByIndex(Native(NYM_ID),n_nIndex);
}

Boolean otapi_wrap::Wallet_CanRemoveServer(String ^% SERVER_ID) { return OTAPI_Wrap::Wallet_CanRemoveServer(Native(SERVER_ID)); }

Boolean otapi_wrap::Wallet_RemoveServer(String ^% SERVER_ID) { return OTAPI_Wrap::Wallet_RemoveServer(Native(SERVER_ID)); }

Boolean otapi_wrap::Wallet_CanRemoveAssetType(String ^% ASSET_ID) { return OTAPI_Wrap::Wallet_CanRemoveAssetType(Native(ASSET_ID)); }

Boolean otapi_wrap::Wallet_RemoveAssetType(String ^% ASSET_ID) { return OTAPI_Wrap::Wallet_RemoveAssetType(Native(ASSET_ID)); }

Boolean otapi_wrap::Wallet_CanRemoveNym(String ^% NYM_ID) { return OTAPI_Wrap::Wallet_CanRemoveNym(Native(NYM_ID)); }

Boolean otapi_wrap::Wallet_RemoveNym(String ^% NYM_ID) { return OTAPI_Wrap::Wallet_RemoveNym(Native(NYM_ID)); }

Boolean otapi_wrap::Wallet_CanRemoveAccount(String ^% ACCOUNT_ID) { return OTAPI_Wrap::Wallet_CanRemoveAccount(Native(ACCOUNT_ID)); }

Boolean otapi_wrap::Wallet_ChangePassphrase() { return OTAPI_Wrap::Wallet_ChangePassphrase(); }

String ^ otapi_wrap::Wallet_ExportNym(String ^% NYM_ID) { return Managed(OTAPI_Wrap::Wallet_ExportNym(Native(NYM_ID))); }

String ^ otapi_wrap::Wallet_ImportCert(String ^% DISPLAY_NAME, String ^% FILE_CONTENTS) { return Managed(OTAPI_Wrap::Wallet_ImportCert(Native(DISPLAY_NAME),Native(FILE_CONTENTS))); }

String ^ otapi_wrap::Wallet_ExportCert(String ^% NYM_ID) { return Managed(OTAPI_Wrap::Wallet_ExportCert(Native(NYM_ID))); }

String ^ otapi_wrap::Wallet_ImportNym(String ^% FILE_CONTENTS) { return Managed(OTAPI_Wrap::Wallet_ImportNym(Native(FILE_CONTENTS))); }

String ^ otapi_wrap::Wallet_GetNymIDFromPartial(String ^% PARTIAL_ID) { return Managed(OTAPI_Wrap::Wallet_GetNymIDFromPartial(Native(PARTIAL_ID))); }
String ^ otapi_wrap::Wallet_GetServerIDFromPartial(String ^% PARTIAL_ID) { return Managed(OTAPI_Wrap::Wallet_GetServerIDFromPartial(Native(PARTIAL_ID))); }
String ^ otapi_wrap::Wallet_GetAssetIDFromPartial(String ^% PARTIAL_ID) { return Managed(OTAPI_Wrap::Wallet_GetAssetIDFromPartial(Native(PARTIAL_ID))); }
String ^ otapi_wrap::Wallet_GetAccountIDFromPartial(String ^% PARTIAL_ID) { return Managed(OTAPI_Wrap::Wallet_GetAccountIDFromPartial(Native(PARTIAL_ID))); }

Boolean otapi_wrap::SetNym_Name(
	String ^% NYM_ID, 
	String ^% SIGNER_NYM_ID, 
	String ^% NYM_NEW_NAME
	)
{
	return OTAPI_Wrap::SetNym_Name(Native(NYM_ID),Native(SIGNER_NYM_ID),Native(NYM_NEW_NAME));
}

Boolean otapi_wrap::SetAccountWallet_Name(
	String ^% ACCT_ID, 
	String ^% SIGNER_NYM_ID, 
	String ^% ACCT_NEW_NAME
	)
{
	return OTAPI_Wrap::SetAccountWallet_Name(Native(ACCT_ID),Native(SIGNER_NYM_ID),Native(ACCT_NEW_NAME));
}

Boolean otapi_wrap::SetAssetType_Name(
	String ^% ASSET_ID, 
	String ^% STR_NEW_NAME
	)
{
	return OTAPI_Wrap::SetAssetType_Name(Native(ASSET_ID),Native(STR_NEW_NAME));
}

Boolean otapi_wrap::SetServer_Name(
	String ^% SERVER_ID, 
	String ^% STR_NEW_NAME
	)
{
	return OTAPI_Wrap::SetServer_Name(Native(SERVER_ID),Native(STR_NEW_NAME));
}

String ^ otapi_wrap::WriteCheque(
			String ^% SERVER_ID,
			Int64 % CHEQUE_AMOUNT, 
			DateTime % VALID_FROM, 
			DateTime % VALID_TO,
			String ^% SENDER_ACCT_ID,
			String ^% SENDER_USER_ID,
			String ^% CHEQUE_MEMO, 
			String ^% RECIPIENT_USER_ID
			)
{
	//String n_CHEQUE_AMOUNT = CHEQUE_AMOUNT;

	return Managed(OTAPI_Wrap::WriteCheque(
		Native(SERVER_ID),
		Native(CHEQUE_AMOUNT),
		Native(VALID_FROM),
		Native(VALID_TO),
		Native(SENDER_ACCT_ID),
		Native(SENDER_USER_ID),
		Native(CHEQUE_MEMO),
		Native(RECIPIENT_USER_ID)
		));
}

Boolean otapi_wrap::DiscardCheque(
	String ^% SERVER_ID,
	String ^% USER_ID,
	String ^% ACCT_ID,
	String ^% THE_CHEQUE
	)
{
	return OTAPI_Wrap::DiscardCheque(
		Native(SERVER_ID),
		Native(USER_ID),
		Native(ACCT_ID),
		Native(THE_CHEQUE)
		);
}

String ^ otapi_wrap::ProposePaymentPlan(
	String ^% SERVER_ID,
	DateTime % VALID_FROM,
	DateTime % VALID_TO,
	String ^% SENDER_ACCT_ID,
	String ^% SENDER_USER_ID,
	String ^% PLAN_CONSIDERATION,
	String ^% RECIPIENT_ACCT_ID,
	String ^% RECIPIENT_USER_ID,
	Int64 % INITIAL_PAYMENT_AMOUNT,
	TimeSpan % INITIAL_PAYMENT_DELAY,
	Int64 % PAYMENT_PLAN_AMOUNT,
	TimeSpan % PAYMENT_PLAN_DELAY,
	TimeSpan % PAYMENT_PLAN_PERIOD,
	Int64 % PAYMENT_PLAN_LENGTH,
	Int32 % PAYMENT_PLAN_MAX_PAYMENTS
	)
{
	return Managed(OTAPI_Wrap::ProposePaymentPlan(
		Native(SERVER_ID),
		Native(VALID_FROM),
		Native(VALID_TO),
		Native(SENDER_ACCT_ID),
		Native(SENDER_USER_ID),
		Native(PLAN_CONSIDERATION),
		Native(RECIPIENT_ACCT_ID),
		Native(RECIPIENT_USER_ID),
		Native(INITIAL_PAYMENT_AMOUNT),
		Native(INITIAL_PAYMENT_DELAY),
		Native(PAYMENT_PLAN_AMOUNT),
		Native(PAYMENT_PLAN_DELAY),
		Native(PAYMENT_PLAN_PERIOD),
		Native(PAYMENT_PLAN_LENGTH),
		Native(PAYMENT_PLAN_MAX_PAYMENTS)
		));
}

String ^ otapi_wrap::ConfirmPaymentPlan(
	String ^% SERVER_ID,
	String ^% SENDER_USER_ID,
	String ^% SENDER_ACCT_ID,
	String ^% RECIPIENT_USER_ID,
	String ^% PAYMENT_PLAN
	)
{
	return Managed(OTAPI_Wrap::ConfirmPaymentPlan(
		Native(SERVER_ID),
		Native(SENDER_USER_ID),
		Native(SENDER_ACCT_ID),
		Native(RECIPIENT_USER_ID),
		Native(PAYMENT_PLAN)
		));
}

String ^ otapi_wrap::Create_SmartContract(
	String ^% SIGNER_NYM_ID,
	DateTime % VALID_FROM,
	DateTime % VALID_TO
	)
{
	return Managed(OTAPI_Wrap::Create_SmartContract(
		Native(SIGNER_NYM_ID),
		Native(VALID_FROM),
		Native(VALID_TO)
		));
}

String ^ otapi_wrap::SmartContract_AddBylaw(
	String ^% THE_CONTRACT,
	String ^% SIGNER_NYM_ID,
	String ^% BYLAW_NAME
	)
{
	return Managed(OTAPI_Wrap::SmartContract_AddBylaw(Native(THE_CONTRACT), Native(SIGNER_NYM_ID), Native(BYLAW_NAME)));
}

String ^ otapi_wrap::SmartContract_AddClause(
	String ^% THE_CONTRACT,
	String ^% SIGNER_NYM_ID,
	String ^% BYLAW_NAME, 
	String ^% CLAUSE_NAME,
	String ^% SOURCE_CODE
	)
{
	return Managed(OTAPI_Wrap::SmartContract_AddClause(
		Native(THE_CONTRACT),
		Native(SIGNER_NYM_ID),
		Native(BYLAW_NAME),
		Native(CLAUSE_NAME),
		Native(SOURCE_CODE)
		));
}

String ^ otapi_wrap::SmartContract_AddVariable(
	String ^% THE_CONTRACT,
	String ^% SIGNER_NYM_ID,
	String ^% BYLAW_NAME,
	String ^% VAR_NAME,
	String ^% VAR_ACCESS,
	String ^% VAR_TYPE,
	String ^% VAR_VALUE
	)
{
	return Managed(OTAPI_Wrap::SmartContract_AddVariable(
		Native(THE_CONTRACT),
		Native(SIGNER_NYM_ID),
		Native(BYLAW_NAME),
		Native(VAR_NAME),
		Native(VAR_ACCESS),
		Native(VAR_TYPE),
		Native(VAR_VALUE)
		));
}

String ^ otapi_wrap::SmartContract_AddCallback(
	String ^% THE_CONTRACT,
	String ^% SIGNER_NYM_ID,
	String ^% BYLAW_NAME,
	String ^% CALLBACK_NAME,
	String ^% CLAUSE_NAME
	)
{
	return Managed(OTAPI_Wrap::SmartContract_AddCallback(
		Native(THE_CONTRACT),
		Native(SIGNER_NYM_ID),
		Native(BYLAW_NAME),
		Native(CALLBACK_NAME),
		Native(CLAUSE_NAME)
		));
}

String ^ otapi_wrap::SmartContract_AddHook(
	String ^% THE_CONTRACT,
	String ^% SIGNER_NYM_ID,
	String ^% BYLAW_NAME,
	String ^% HOOK_NAME,
	String ^% CLAUSE_NAME
	)
{
	return Managed(OTAPI_Wrap::SmartContract_AddHook(
		Native(THE_CONTRACT),
		Native(SIGNER_NYM_ID),
		Native(BYLAW_NAME),
		Native(HOOK_NAME),
		Native(CLAUSE_NAME)
		));
}

String ^ otapi_wrap::SmartContract_AddParty(
	String ^% THE_CONTRACT,
	String ^% SIGNER_NYM_ID,
	String ^% PARTY_NAME,
	String ^% AGENT_NAME
	)
{
	return Managed(OTAPI_Wrap::SmartContract_AddParty(
		Native(THE_CONTRACT),
		Native(SIGNER_NYM_ID),
		Native(PARTY_NAME),
		Native(AGENT_NAME)
		));
}

String ^ otapi_wrap::SmartContract_AddAccount(
	String ^% THE_CONTRACT,
	String ^% SIGNER_NYM_ID,
	String ^% PARTY_NAME,
	String ^% ACCT_NAME,
	String ^% ASSET_TYPE_ID
	)
{
	return Managed(OTAPI_Wrap::SmartContract_AddAccount(
		Native(THE_CONTRACT),
		Native(SIGNER_NYM_ID),
		Native(PARTY_NAME),
		Native(ACCT_NAME),
		Native(ASSET_TYPE_ID)
		));
}

Int32 otapi_wrap::SmartContract_CountNumsNeeded(
	String ^% THE_CONTRACT,
	String ^% AGENT_NAME
	)
{
	return OTAPI_Wrap::SmartContract_CountNumsNeeded(
		Native(THE_CONTRACT),
		Native(AGENT_NAME)
		);
}

String ^ otapi_wrap::SmartContract_ConfirmAccount(
	String ^% THE_CONTRACT,
	String ^% SIGNER_NYM_ID,
	String ^% PARTY_NAME,
	String ^% ACCT_NAME,
	String ^% AGENT_NAME,
	String ^% ACCT_ID
	)
{
	return Managed(OTAPI_Wrap::SmartContract_ConfirmAccount(
		Native(THE_CONTRACT),
		Native(SIGNER_NYM_ID),
		Native(PARTY_NAME),
		Native(ACCT_NAME),
		Native(AGENT_NAME),
		Native(ACCT_ID)
		));
}

String ^ otapi_wrap::SmartContract_ConfirmParty(
	String ^% THE_CONTRACT,
	String ^% PARTY_NAME,
	String ^% NYM_ID
	)
{
	return Managed(OTAPI_Wrap::SmartContract_ConfirmParty(
		Native(THE_CONTRACT),
		Native(PARTY_NAME),
		Native(NYM_ID)
		));
}

Int32 otapi_wrap::activateSmartContract(
	String ^% SERVER_ID,
	String ^% USER_ID,
	String ^% THE_SMART_CONTRACT
	)
{
	return OTAPI_Wrap::activateSmartContract(
		Native(SERVER_ID),
		Native(USER_ID),
		Native(THE_SMART_CONTRACT)
		);
}

Int32 otapi_wrap::triggerClause(
	String ^% SERVER_ID,
	String ^% USER_ID,
	Int64 % TRANSACTION_NUMBER,
	String ^% CLAUSE_NAME,
	String ^% STR_PARAM
	)
{
	//String n_TRANSACTION_NUMBER = TRANSACTION_NUMBER;

	return OTAPI_Wrap::triggerClause(
		Native(SERVER_ID),
		Native(USER_ID),
		Native(TRANSACTION_NUMBER),
		Native(CLAUSE_NAME),
		Native(STR_PARAM)
		);
}

Boolean otapi_wrap::Msg_HarvestTransactionNumbers(
	String ^% THE_MESSAGE,
	String ^% USER_ID,
	Boolean % bHarvestingForRetry,
	Boolean % bReplyWasSuccess,
	Boolean % bReplyWasFailure,
	Boolean % bTransactionWasSuccess,
	Boolean % bTransactionWasFailure
	)
{
	Boolean n_bHarvestingForRetry = bHarvestingForRetry;
	Boolean n_bReplyWasSuccess = bReplyWasSuccess;
	Boolean n_bReplyWasFailure = bReplyWasFailure;
	Boolean n_bTransactionWasSuccess = bTransactionWasSuccess;
	Boolean n_bTransactionWasFailure = bTransactionWasFailure;

	return OTAPI_Wrap::Msg_HarvestTransactionNumbers(
		Native(THE_MESSAGE),
		Native(USER_ID),
		n_bHarvestingForRetry,
		n_bReplyWasSuccess,
		n_bReplyWasFailure,
		n_bTransactionWasSuccess,
		n_bTransactionWasFailure
		);
}

String ^ otapi_wrap::LoadUserPubkey_Encryption(String ^% USER_ID) { return Managed(OTAPI_Wrap::LoadUserPubkey_Encryption(Native(USER_ID))); }
String ^ otapi_wrap::LoadPubkey_Encryption(String ^% USER_ID) { return Managed(OTAPI_Wrap::LoadPubkey_Encryption(Native(USER_ID))); }
String ^ otapi_wrap::LoadUserPubkey_Signing(String ^% USER_ID) { return Managed(OTAPI_Wrap::LoadUserPubkey_Signing(Native(USER_ID))); }
String ^ otapi_wrap::LoadPubkey_Signing(String ^% USER_ID) { return Managed(OTAPI_Wrap::LoadPubkey_Signing(Native(USER_ID))); }

Boolean otapi_wrap::VerifyUserPrivateKey(String ^% USER_ID) { return OTAPI_Wrap::VerifyUserPrivateKey(Native(USER_ID)); }

String ^ otapi_wrap::LoadPurse(
	String ^% SERVER_ID,
	String ^% ASSET_TYPE_ID,
	String ^% USER_ID
	)
{
	return Managed(OTAPI_Wrap::LoadPurse(Native(SERVER_ID), Native(ASSET_TYPE_ID), Native(USER_ID)));
}

String ^ otapi_wrap::LoadMint(
	String ^% SERVER_ID,
	String ^% ASSET_TYPE_ID)
{
	return Managed(OTAPI_Wrap::LoadMint(Native(SERVER_ID), Native(ASSET_TYPE_ID)));
}

String ^ otapi_wrap::LoadAssetContract(String ^% ASSET_TYPE_ID) { return Managed(OTAPI_Wrap::LoadAssetContract(Native(ASSET_TYPE_ID))); }

String ^ otapi_wrap::LoadServerContract(String ^% SERVER_ID) { return Managed(OTAPI_Wrap::LoadServerContract(Native(SERVER_ID))); }

Boolean otapi_wrap::Mint_IsStillGood(
	String ^% SERVER_ID,
	String ^% ASSET_TYPE_ID
	)
{
	return OTAPI_Wrap::Mint_IsStillGood(Native(SERVER_ID), Native(ASSET_TYPE_ID));
}

Boolean otapi_wrap::IsBasketCurrency(String ^% ASSET_TYPE_ID) { return OTAPI_Wrap::IsBasketCurrency(Native(ASSET_TYPE_ID)); }

Int32 otapi_wrap::Basket_GetMemberCount(String ^% BASKET_ASSET_TYPE_ID) { return OTAPI_Wrap::Basket_GetMemberCount(Native(BASKET_ASSET_TYPE_ID)); }

String ^ otapi_wrap::Basket_GetMemberType(
	String ^% BASKET_ASSET_TYPE_ID,
	Int32 % nIndex
	)
{
	Int32 n_nIndex = nIndex;
	return Managed(OTAPI_Wrap::Basket_GetMemberType(Native(BASKET_ASSET_TYPE_ID),n_nIndex));
}

Int64	otapi_wrap::Basket_GetMinimumTransferAmount(String ^% BASKET_ASSET_TYPE_ID) { return OTAPI_Wrap::Basket_GetMinimumTransferAmount(Native(BASKET_ASSET_TYPE_ID)); }

Int64	otapi_wrap::Basket_GetMemberMinimumTransferAmount(
	String ^% BASKET_ASSET_TYPE_ID,
	Int32 % nIndex
	)
{
	int64_t ret = OTAPI_Wrap::Basket_GetMemberMinimumTransferAmount(Native(BASKET_ASSET_TYPE_ID),Native(nIndex));
	return Managed(ret);
}

String ^ otapi_wrap::LoadAssetAccount(
	String ^% SERVER_ID,
	String ^% USER_ID,
	String ^% ACCOUNT_ID
	)
{
	return Managed(OTAPI_Wrap::LoadAssetAccount(Native(SERVER_ID), Native(USER_ID), Native(ACCOUNT_ID)));
}

String ^ otapi_wrap::LoadInbox(
	String ^% SERVER_ID,
	String ^% USER_ID,
	String ^% ACCOUNT_ID
	)
{
	return Managed(OTAPI_Wrap::LoadInbox(Native(SERVER_ID), Native(USER_ID), Native(ACCOUNT_ID)));
}

String ^ otapi_wrap::LoadOutbox(
	String ^% SERVER_ID,
	String ^% USER_ID,
	String ^% ACCOUNT_ID
	)
{
	return Managed(OTAPI_Wrap::LoadOutbox(Native(SERVER_ID), Native(USER_ID), Native(ACCOUNT_ID)));
}

String ^ otapi_wrap::LoadInboxNoVerify(
	String ^% SERVER_ID,
	String ^% USER_ID,
	String ^% ACCOUNT_ID
	)
{
	return Managed(OTAPI_Wrap::LoadInboxNoVerify(Native(SERVER_ID), Native(USER_ID), Native(ACCOUNT_ID)));
}

String ^ otapi_wrap::LoadOutboxNoVerify(
	String ^% SERVER_ID,
	String ^% USER_ID,
	String ^% ACCOUNT_ID
	)
{
	return Managed(OTAPI_Wrap::LoadOutboxNoVerify(Native(SERVER_ID), Native(USER_ID), Native(ACCOUNT_ID)));
}

String ^ otapi_wrap::LoadPaymentInbox(
	String ^% SERVER_ID,
	String ^% USER_ID
	)
{
	return Managed(OTAPI_Wrap::LoadPaymentInbox(Native(SERVER_ID), Native(USER_ID)));
}

String ^ otapi_wrap::LoadPaymentInboxNoVerify(
	String ^% SERVER_ID,
	String ^% USER_ID
	)
{
	return Managed(OTAPI_Wrap::LoadPaymentInboxNoVerify(Native(SERVER_ID), Native(USER_ID)));
}

String ^ otapi_wrap::LoadRecordBox(
	String ^% SERVER_ID,
	String ^% USER_ID,
	String ^% ACCOUNT_ID
	)
{
	return Managed(OTAPI_Wrap::LoadRecordBox(Native(SERVER_ID), Native(USER_ID), Native(ACCOUNT_ID)));
}

String ^ otapi_wrap::LoadRecordBoxNoVerify(
	String ^% SERVER_ID,
	String ^% USER_ID,
	String ^% ACCOUNT_ID
	)
{
	return Managed(OTAPI_Wrap::LoadRecordBoxNoVerify(Native(SERVER_ID), Native(USER_ID), Native(ACCOUNT_ID)));
}

Boolean otapi_wrap::ClearRecord(
	String ^% SERVER_ID,
	String ^% USER_ID,
	String ^% ACCOUNT_ID,
	Int32 % nIndex,
    Boolean % bClearAll
	)
{
	Boolean bool_bClearAll = bClearAll;
	return OTAPI_Wrap::ClearRecord(Native(SERVER_ID), Native(USER_ID), Native(ACCOUNT_ID),Native(nIndex),bool_bClearAll);
}

Boolean otapi_wrap::RecordPayment(
	String ^% SERVER_ID,
	String ^% USER_ID,
    Boolean % bIsInbox,
	Int32 % nIndex
	)
{
	Boolean bool_bIsInbox = bIsInbox;
	return OTAPI_Wrap::RecordPayment(Native(SERVER_ID), Native(USER_ID), bool_bIsInbox ,Native(nIndex));
}

Int32 otapi_wrap::Ledger_GetCount(
	String ^% SERVER_ID,
	String ^% USER_ID,
	String ^% ACCOUNT_ID,
	String ^% THE_LEDGER
	)
{
	return OTAPI_Wrap::Ledger_GetCount(Native(SERVER_ID), Native(USER_ID), Native(ACCOUNT_ID), Native(THE_LEDGER));
}

String ^ otapi_wrap::Ledger_CreateResponse(
	String ^% SERVER_ID,
	String ^% USER_ID,
	String ^% ACCOUNT_ID,
	String ^% ORIGINAL_LEDGER
	)
{
	return Managed(OTAPI_Wrap::Ledger_CreateResponse(Native(SERVER_ID), Native(USER_ID), Native(ACCOUNT_ID), Native(ORIGINAL_LEDGER)));
}

String ^ otapi_wrap::Ledger_GetTransactionByIndex(
	String ^% SERVER_ID,
	String ^% USER_ID,
	String ^% ACCOUNT_ID,
	String ^% THE_LEDGER,
	Int32 % nIndex
	)
{
	Int32 n_nIndex = nIndex;
	return Managed(OTAPI_Wrap::Ledger_GetTransactionByIndex(Native(SERVER_ID), Native(USER_ID), Native(ACCOUNT_ID), Native(THE_LEDGER),n_nIndex));
}

String ^ otapi_wrap::Ledger_GetTransactionByID(
	String ^% SERVER_ID,
	String ^% USER_ID,
	String ^% ACCOUNT_ID,
	String ^% THE_LEDGER,
	Int64 % TRANSACTION_NUMBER
	)
{
	//String n_TRANSACTION_NUMBER = TRANSACTION_NUMBER;

	return Managed(OTAPI_Wrap::Ledger_GetTransactionByID(Native(SERVER_ID), Native(USER_ID), Native(ACCOUNT_ID), Native(THE_LEDGER), Native(TRANSACTION_NUMBER)));
}

Int64 otapi_wrap::Ledger_GetTransactionIDByIndex(
	String ^% SERVER_ID,
	String ^% USER_ID,
	String ^% ACCOUNT_ID,
	String ^% THE_LEDGER,
	Int32 % nIndex
	)
{
	Int32 n_nIndex = nIndex;
	return OTAPI_Wrap::Ledger_GetTransactionIDByIndex(Native(SERVER_ID), Native(USER_ID), Native(ACCOUNT_ID), Native(THE_LEDGER),n_nIndex);
}


String ^ otapi_wrap::Ledger_AddTransaction(
	String ^% SERVER_ID,
	String ^% USER_ID,
	String ^% ACCOUNT_ID,
	String ^% THE_LEDGER,
	String ^% THE_TRANSACTION
	)
{
	return Managed(OTAPI_Wrap::Ledger_AddTransaction(Native(SERVER_ID), Native(USER_ID), Native(ACCOUNT_ID), Native(THE_LEDGER), Native(THE_TRANSACTION)));
}


String ^ otapi_wrap::Transaction_CreateResponse(
	String ^% SERVER_ID,
	String ^% USER_ID,
	String ^% ACCOUNT_ID,
	String ^% RESPONSE_LEDGER,
	String ^% ORIGINAL_TRANSACTION, 
	Boolean % BOOL_DO_I_ACCEPT
	)
{
	Boolean n_bBOOL_DO_I_ACCEPT = BOOL_DO_I_ACCEPT;
	return Managed(OTAPI_Wrap::Transaction_CreateResponse(Native(SERVER_ID), Native(USER_ID), Native(ACCOUNT_ID), Native(RESPONSE_LEDGER), Native(ORIGINAL_TRANSACTION), n_bBOOL_DO_I_ACCEPT));
}

String ^ otapi_wrap::Ledger_FinalizeResponse(
	String ^% SERVER_ID,
	String ^% USER_ID,
	String ^% ACCOUNT_ID,
	String ^% THE_LEDGER
	)
{
	return Managed(OTAPI_Wrap::Ledger_FinalizeResponse(Native(SERVER_ID), Native(USER_ID), Native(ACCOUNT_ID), Native(THE_LEDGER)));
}

String ^ otapi_wrap::Ledger_GetInstrument(
	String ^% SERVER_ID,
	String ^% USER_ID,
	String ^% ACCOUNT_ID,
	String ^% THE_LEDGER,
	Int32 % nIndex
	)
{
	Int32 n_nIndex = nIndex;
	return Managed(OTAPI_Wrap::Ledger_GetInstrument(Native(SERVER_ID), Native(USER_ID), Native(ACCOUNT_ID), Native(THE_LEDGER),n_nIndex));
}

String ^ otapi_wrap::Transaction_GetType(
	String ^% SERVER_ID,
	String ^% USER_ID,
	String ^% ACCOUNT_ID,
	String ^% THE_TRANSACTION
	)
{
	return Managed(OTAPI_Wrap::Transaction_GetType(Native(SERVER_ID), Native(USER_ID), Native(ACCOUNT_ID), Native(THE_TRANSACTION)));
}

Int64 otapi_wrap::ReplyNotice_GetRequestNum(
	String ^% SERVER_ID,
	String ^% USER_ID,
	String ^% THE_TRANSACTION
	)
{
	return OTAPI_Wrap::ReplyNotice_GetRequestNum(Native(SERVER_ID), Native(USER_ID), Native(THE_TRANSACTION));
}

String ^ otapi_wrap::Transaction_GetVoucher(
	String ^% SERVER_ID,
	String ^% USER_ID,
	String ^% ACCOUNT_ID,
	String ^% THE_TRANSACTION
	)
{
	return Managed(OTAPI_Wrap::Transaction_GetVoucher(Native(SERVER_ID), Native(USER_ID), Native(ACCOUNT_ID), Native(THE_TRANSACTION)));
}


Boolean otapi_wrap::Transaction_GetSuccess(
	String ^% SERVER_ID,
	String ^% USER_ID,
	String ^% ACCOUNT_ID,
	String ^% THE_TRANSACTION
	)
{
	return OTAPI_Wrap::Transaction_GetSuccess(Native(SERVER_ID), Native(USER_ID), Native(ACCOUNT_ID), Native(THE_TRANSACTION));
}

Boolean otapi_wrap::Transaction_GetBalanceAgreementSuccess(
	String ^% SERVER_ID,
	String ^% USER_ID,
	String ^% ACCOUNT_ID,
	String ^% THE_TRANSACTION
	)
{
	return OTAPI_Wrap::Transaction_GetBalanceAgreementSuccess(Native(SERVER_ID), Native(USER_ID), Native(ACCOUNT_ID), Native(THE_TRANSACTION));
}

DateTime otapi_wrap::Transaction_GetDateSigned(
	String ^% SERVER_ID,
	String ^% USER_ID,
	String ^% ACCOUNT_ID,
	String ^% THE_TRANSACTION
	)
{
	return Managed(OTAPI_Wrap::Transaction_GetDateSigned(Native(SERVER_ID), Native(USER_ID), Native(ACCOUNT_ID), Native(THE_TRANSACTION)));
}

Int64 otapi_wrap::Transaction_GetAmount(
	String ^% SERVER_ID,
	String ^% USER_ID,
	String ^% ACCOUNT_ID,
	String ^% THE_TRANSACTION
	)
{
	int64_t ret = OTAPI_Wrap::Transaction_GetAmount(Native(SERVER_ID), Native(USER_ID), Native(ACCOUNT_ID), Native(THE_TRANSACTION));
	return Managed(ret);
}

String ^ otapi_wrap::Pending_GetNote(
	String ^% SERVER_ID,
	String ^% USER_ID,
	String ^% ACCOUNT_ID,
	String ^% THE_TRANSACTION
	)
{
	return Managed(OTAPI_Wrap::Pending_GetNote(Native(SERVER_ID), Native(USER_ID), Native(ACCOUNT_ID), Native(THE_TRANSACTION)));
}

String ^ otapi_wrap::Transaction_GetSenderUserID(
	String ^% SERVER_ID,
	String ^% USER_ID,
	String ^% ACCOUNT_ID,
	String ^% THE_TRANSACTION
	)
{
	return Managed(OTAPI_Wrap::Transaction_GetSenderUserID(Native(SERVER_ID), Native(USER_ID), Native(ACCOUNT_ID), Native(THE_TRANSACTION)));
}

String ^ otapi_wrap::Transaction_GetSenderAcctID(
	String ^% SERVER_ID,
	String ^% USER_ID,
	String ^% ACCOUNT_ID,
	String ^% THE_TRANSACTION
	)
{
	return Managed(OTAPI_Wrap::Transaction_GetSenderAcctID(Native(SERVER_ID), Native(USER_ID), Native(ACCOUNT_ID), Native(THE_TRANSACTION)));
}

String ^ otapi_wrap::Transaction_GetRecipientUserID(
	String ^% SERVER_ID,
	String ^% USER_ID,
	String ^% ACCOUNT_ID,
	String ^% THE_TRANSACTION
	)
{
	return Managed(OTAPI_Wrap::Transaction_GetRecipientUserID(Native(SERVER_ID), Native(USER_ID), Native(ACCOUNT_ID), Native(THE_TRANSACTION)));
}

String ^ otapi_wrap::Transaction_GetRecipientAcctID(
	String ^% SERVER_ID,
	String ^% USER_ID,
	String ^% ACCOUNT_ID,
	String ^% THE_TRANSACTION
	)
{
	return Managed(OTAPI_Wrap::Transaction_GetRecipientAcctID(Native(SERVER_ID), Native(USER_ID), Native(ACCOUNT_ID), Native(THE_TRANSACTION)));
}

Int64 otapi_wrap::Transaction_GetDisplayReferenceToNum(
	String ^% SERVER_ID,
	String ^% USER_ID,
	String ^% ACCOUNT_ID,
	String ^% THE_TRANSACTION
	)
{
	return OTAPI_Wrap::Transaction_GetDisplayReferenceToNum(Native(SERVER_ID), Native(USER_ID), Native(ACCOUNT_ID), Native(THE_TRANSACTION));
}

String ^ otapi_wrap::CreatePurse(
		String ^% SERVER_ID,
		String ^% ASSET_TYPE_ID,
		String ^% OWNER_ID,
		String ^% SIGNER_ID
	)
{
	return Managed(OTAPI_Wrap::CreatePurse(Native(SERVER_ID), Native(ASSET_TYPE_ID), Native(OWNER_ID), Native(SIGNER_ID)));
}

String ^ otapi_wrap::CreatePurse_Passphrase(
		String ^% SERVER_ID,
		String ^% ASSET_TYPE_ID,
		String ^% SIGNER_ID
	)
{
	return Managed(OTAPI_Wrap::CreatePurse_Passphrase(Native(SERVER_ID), Native(ASSET_TYPE_ID), Native(SIGNER_ID)));
}

Int64 otapi_wrap::Purse_GetTotalValue(
		String ^% SERVER_ID,
		String ^% ASSET_TYPE_ID,
		String ^% THE_PURSE
	)
{
	return OTAPI_Wrap::Purse_GetTotalValue(Native(SERVER_ID), Native(ASSET_TYPE_ID), Native(THE_PURSE));
}

Boolean otapi_wrap::SavePurse(
	String ^% SERVER_ID,
	String ^% ASSET_TYPE_ID,
	String ^% USER_ID,
	String ^% THE_PURSE
	)
{
	return OTAPI_Wrap::SavePurse(Native(SERVER_ID), Native(ASSET_TYPE_ID), Native(USER_ID), Native(THE_PURSE));
}

Int32 otapi_wrap::Purse_Count(
	String ^% SERVER_ID,
	String ^% ASSET_TYPE_ID,
	String ^% THE_PURSE
	)
{
	return OTAPI_Wrap::Purse_Count(Native(SERVER_ID), Native(ASSET_TYPE_ID), Native(THE_PURSE));
}

Boolean otapi_wrap::Purse_HasPassword(
	String ^% SERVER_ID,
	String ^% THE_PURSE
	)
{
	return OTAPI_Wrap::Purse_HasPassword(Native(SERVER_ID), Native(THE_PURSE));
}

String ^ otapi_wrap::Purse_Peek(
	String ^% SERVER_ID,
	String ^% ASSET_TYPE_ID,
	String ^% USER_ID,
	String ^% THE_PURSE
	)
{
	return Managed(OTAPI_Wrap::Purse_Peek(Native(SERVER_ID), Native(ASSET_TYPE_ID), Native(USER_ID), Native(THE_PURSE)));
}

String ^ otapi_wrap::Purse_Pop(
	String ^% SERVER_ID,
	String ^% ASSET_TYPE_ID,
	String ^% USER_ID,
	String ^% THE_PURSE
	)
{
	return Managed(OTAPI_Wrap::Purse_Pop(Native(SERVER_ID), Native(ASSET_TYPE_ID), Native(USER_ID), Native(THE_PURSE)));
}

String ^ otapi_wrap::Purse_Push(
			String ^% SERVER_ID,
			String ^% ASSET_TYPE_ID,
			String ^% SIGNER_ID,
			String ^% OWNER_ID,
			String ^% THE_PURSE,
			String ^% THE_TOKEN
			)
{
	return Managed(OTAPI_Wrap::Purse_Push(Native(SERVER_ID), Native(ASSET_TYPE_ID), Native(SIGNER_ID), Native(OWNER_ID), Native(THE_PURSE), Native(THE_TOKEN)));
}

String ^ otapi_wrap::Purse_Empty(
	String ^% SERVER_ID,
	String ^% ASSET_TYPE_ID,
	String ^% SIGNER_ID,
	String ^% THE_PURSE
	)
{
	return Managed(OTAPI_Wrap::Purse_Empty(Native(SERVER_ID), Native(ASSET_TYPE_ID), Native(SIGNER_ID), Native(THE_PURSE)));
}

Boolean otapi_wrap::Wallet_ImportPurse(
	String ^% SERVER_ID,
	String ^% ASSET_TYPE_ID,
	String ^% USER_ID,
	String ^% THE_PURSE
	)
{
	return OTAPI_Wrap::Wallet_ImportPurse(Native(SERVER_ID), Native(ASSET_TYPE_ID), Native(USER_ID), Native(THE_PURSE));
}

Int32 otapi_wrap::exchangePurse(
	String ^% SERVER_ID,
	String ^% ASSET_TYPE_ID,
	String ^% USER_ID,
	String ^% THE_PURSE
	)
{
	return OTAPI_Wrap::exchangePurse(Native(SERVER_ID), Native(ASSET_TYPE_ID), Native(USER_ID), Native(THE_PURSE));
}

String ^ otapi_wrap::Token_ChangeOwner(
			String ^% SERVER_ID,
			String ^% ASSET_TYPE_ID,
			String ^% THE_TOKEN,
			String ^% SIGNER_NYM_ID,
			String ^% OLD_OWNER,
			String ^% NEW_OWNER
	)
{
	return Managed(OTAPI_Wrap::Token_ChangeOwner(Native(SERVER_ID), Native(ASSET_TYPE_ID), Native(THE_TOKEN), Native(SIGNER_NYM_ID), Native(OLD_OWNER), Native(NEW_OWNER)));
}

String ^ otapi_wrap::Token_GetID(
	String ^% SERVER_ID,
	String ^% ASSET_TYPE_ID,
	String ^% THE_TOKEN
	)
{
	return Managed(OTAPI_Wrap::Token_GetID(Native(SERVER_ID), Native(ASSET_TYPE_ID), Native(THE_TOKEN)));
}

Int64 otapi_wrap::Token_GetDenomination(
			String ^% SERVER_ID,
			String ^% ASSET_TYPE_ID,
			String ^% THE_TOKEN
	)
{
	return OTAPI_Wrap::Token_GetDenomination(Native(SERVER_ID), Native(ASSET_TYPE_ID), Native(THE_TOKEN));
}

Int32 otapi_wrap::Token_GetSeries(
	String ^% SERVER_ID,
	String ^% ASSET_TYPE_ID,
	String ^% THE_TOKEN
	)
{
	return OTAPI_Wrap::Token_GetSeries(Native(SERVER_ID), Native(ASSET_TYPE_ID), Native(THE_TOKEN));
}

DateTime otapi_wrap::Token_GetValidFrom(
	String ^% SERVER_ID,
	String ^% ASSET_TYPE_ID,
	String ^% THE_TOKEN
	)
{
	return Managed(OTAPI_Wrap::Token_GetValidFrom(Native(SERVER_ID), Native(ASSET_TYPE_ID), Native(THE_TOKEN)));
}

DateTime otapi_wrap::Token_GetValidTo(
	String ^% SERVER_ID,
	String ^% ASSET_TYPE_ID,
	String ^% THE_TOKEN
	)
{
	return Managed(OTAPI_Wrap::Token_GetValidTo(Native(SERVER_ID), Native(ASSET_TYPE_ID), Native(THE_TOKEN)));
}

String ^ otapi_wrap::Token_GetAssetID(String ^% THE_TOKEN) { return Managed(OTAPI_Wrap::Token_GetAssetID(Native(THE_TOKEN))); }

String ^ otapi_wrap::Token_GetServerID(String ^% THE_TOKEN) { return Managed(OTAPI_Wrap::Token_GetServerID(Native(THE_TOKEN))); }

Int64 otapi_wrap::Instrmnt_GetAmount(
	String ^% THE_INSTRUMENT
	)
{
	return OTAPI_Wrap::Instrmnt_GetAmount(Native(THE_INSTRUMENT));
}

Int64 otapi_wrap::Instrmnt_GetTransNum(
	String ^% THE_INSTRUMENT
	)
{
	return OTAPI_Wrap::Instrmnt_GetTransNum(Native(THE_INSTRUMENT));
}

DateTime otapi_wrap::Instrmnt_GetValidFrom(
	String ^% THE_INSTRUMENT
	)
{
	return Managed(OTAPI_Wrap::Instrmnt_GetValidFrom(Native(THE_INSTRUMENT)));
}

DateTime otapi_wrap::Instrmnt_GetValidTo(
	String ^% THE_INSTRUMENT
	)
{
	return Managed(OTAPI_Wrap::Instrmnt_GetValidTo(Native(THE_INSTRUMENT)));
}

String ^ otapi_wrap::Instrmnt_GetMemo(
	String ^% THE_INSTRUMENT
	)
{
	return Managed(OTAPI_Wrap::Instrmnt_GetMemo(Native(THE_INSTRUMENT)));
}

String ^ otapi_wrap::Instrmnt_GetType(
	String ^% THE_INSTRUMENT
	)
{
	return Managed(OTAPI_Wrap::Instrmnt_GetType(Native(THE_INSTRUMENT)));
}

String ^ otapi_wrap::Instrmnt_GetServerID(
	String ^% THE_INSTRUMENT
	)
{
	return Managed(OTAPI_Wrap::Instrmnt_GetServerID(Native(THE_INSTRUMENT)));
}

String ^ otapi_wrap::Instrmnt_GetAssetID(
	String ^% THE_INSTRUMENT
	)
{
	return Managed(OTAPI_Wrap::Instrmnt_GetAssetID(Native(THE_INSTRUMENT)));
}

String ^ otapi_wrap::Instrmnt_GetSenderUserID(
	String ^% THE_INSTRUMENT
	)
{
	return Managed(OTAPI_Wrap::Instrmnt_GetSenderUserID(Native(THE_INSTRUMENT)));
}

String ^ otapi_wrap::Instrmnt_GetSenderAcctID(
	String ^% THE_INSTRUMENT
	)
{
	return Managed(OTAPI_Wrap::Instrmnt_GetSenderAcctID(Native(THE_INSTRUMENT)));
}

String ^ otapi_wrap::Instrmnt_GetRecipientUserID(
	String ^% THE_INSTRUMENT
	)
{
	return Managed(OTAPI_Wrap::Instrmnt_GetRecipientUserID(Native(THE_INSTRUMENT)));
}

String ^ otapi_wrap::Instrmnt_GetRecipientAcctID(
	String ^% THE_INSTRUMENT
	)
{
	return Managed(OTAPI_Wrap::Instrmnt_GetRecipientAcctID(Native(THE_INSTRUMENT)));
}

Int32 otapi_wrap::checkServerID(
	String ^% SERVER_ID,
	String ^% USER_ID
	)
{
	return OTAPI_Wrap::checkServerID(Native(SERVER_ID), Native(USER_ID));
}

Int32 otapi_wrap::createUserAccount(
	String ^% SERVER_ID,
	String ^% USER_ID
	)
{
	return OTAPI_Wrap::createUserAccount(Native(SERVER_ID), Native(USER_ID));
}

Int32 otapi_wrap::deleteUserAccount(
	String ^% SERVER_ID,
	String ^% USER_ID
	)
{
	return OTAPI_Wrap::deleteUserAccount(Native(SERVER_ID), Native(USER_ID));
}

Int32 otapi_wrap::deleteAssetAccount(
	String ^% SERVER_ID,
	String ^% USER_ID,
	String ^% ACCOUNT_ID
	)
{
	return OTAPI_Wrap::deleteAssetAccount(Native(SERVER_ID), Native(USER_ID), Native(ACCOUNT_ID));
}

Int32 otapi_wrap::usageCredits(
	String ^% SERVER_ID,
	String ^% USER_ID,
	String ^% USER_ID_CHECK,
	Int64 % ADJUSTMENT
	)
{
	//String n_ADJUSTMENT = ADJUSTMENT;

	return OTAPI_Wrap::usageCredits(Native(SERVER_ID), Native(USER_ID), Native(USER_ID_CHECK), Native(ADJUSTMENT));
}

Int64 otapi_wrap::Message_GetUsageCredits(String ^% THE_MESSAGE) { return OTAPI_Wrap::Message_GetUsageCredits(Native(THE_MESSAGE)); }

Int32 otapi_wrap::checkUser(
	String ^% SERVER_ID,
	String ^% USER_ID,
	String ^% USER_ID_CHECK
	)
{
	return OTAPI_Wrap::checkUser(Native(SERVER_ID), Native(USER_ID), Native(USER_ID_CHECK));
}

Int32 otapi_wrap::sendUserMessage(
	String ^% SERVER_ID,
	String ^% USER_ID,
	String ^% USER_ID_RECIPIENT,
	String ^% RECIPIENT_PUBKEY,
	String ^% THE_MESSAGE
	)
{
	return OTAPI_Wrap::sendUserMessage(Native(SERVER_ID), Native(USER_ID), Native(USER_ID_RECIPIENT), Native(RECIPIENT_PUBKEY), Native(THE_MESSAGE));
}

Int32 otapi_wrap::sendUserInstrument(
	String ^% SERVER_ID,
	String ^% USER_ID,
	String ^% USER_ID_RECIPIENT,
	String ^% RECIPIENT_PUBKEY,
    String ^% THE_INSTRUMENT,
    String ^% INSTRUMENT_FOR_SENDER
	)
{
	return OTAPI_Wrap::sendUserInstrument(Native(SERVER_ID), Native(USER_ID), Native(USER_ID_RECIPIENT), Native(RECIPIENT_PUBKEY), Native(THE_INSTRUMENT), Native(INSTRUMENT_FOR_SENDER));
}

Int32 otapi_wrap::getRequest(
	String ^% SERVER_ID,
	String ^% USER_ID
	)
{
	return OTAPI_Wrap::getRequest(Native(SERVER_ID), Native(USER_ID));
}

Int32 otapi_wrap::getTransactionNumber(
	String ^% SERVER_ID,
	String ^% USER_ID
	)
{
	return OTAPI_Wrap::getTransactionNumber(Native(SERVER_ID), Native(USER_ID));
}

Int32 otapi_wrap::issueAssetType(
	String ^% SERVER_ID,
	String ^% USER_ID,
	String ^% THE_CONTRACT
	)
{
	return OTAPI_Wrap::issueAssetType(Native(SERVER_ID), Native(USER_ID), Native(THE_CONTRACT));
}

Int32 otapi_wrap::getContract(
	String ^% SERVER_ID,
	String ^% USER_ID,
	String ^% ASSET_ID
	)
{
	return OTAPI_Wrap::getContract(Native(SERVER_ID), Native(USER_ID), Native(ASSET_ID));
}

Int32 otapi_wrap::getMint(
	String ^% SERVER_ID,
	String ^% USER_ID,
	String ^% ASSET_ID
	)
{
	return OTAPI_Wrap::getMint(Native(SERVER_ID), Native(USER_ID), Native(ASSET_ID));
}

Int32 otapi_wrap::createAssetAccount(
	String ^% SERVER_ID,
	String ^% USER_ID,
	String ^% ASSET_ID
	)
{
	return OTAPI_Wrap::createAssetAccount(Native(SERVER_ID), Native(USER_ID), Native(ASSET_ID));
}

Int32 otapi_wrap::getAccount(
	String ^% SERVER_ID,
	String ^% USER_ID,
	String ^% ACCT_ID
	)
{
	return OTAPI_Wrap::getAccount(Native(SERVER_ID), Native(USER_ID), Native(ACCT_ID));
}

String ^ otapi_wrap::GenerateBasketCreation(
	String ^% USER_ID,
	Int64 % MINIMUM_TRANSFER
	)
{
	//String n_MINIMUM_TRANSFER = MINIMUM_TRANSFER;

	return Managed(OTAPI_Wrap::GenerateBasketCreation(Native(USER_ID), Native(MINIMUM_TRANSFER)));
}

String ^ otapi_wrap::AddBasketCreationItem(
	String ^% USER_ID,
	String ^% THE_BASKET,
	String ^% ASSET_TYPE_ID,
	Int64 % MINIMUM_TRANSFER
	)
{
	//String n_MINIMUM_TRANSFER = MINIMUM_TRANSFER;

	return Managed(OTAPI_Wrap::AddBasketCreationItem(Native(USER_ID), Native(THE_BASKET), Native(ASSET_TYPE_ID), Native(MINIMUM_TRANSFER)));
}

Int32 otapi_wrap::issueBasket(
	String ^% SERVER_ID,
	String ^% USER_ID,
	String ^% THE_BASKET
	)
{
	return OTAPI_Wrap::issueBasket(Native(SERVER_ID), Native(USER_ID), Native(THE_BASKET));
}

String ^ otapi_wrap::GenerateBasketExchange(
	String ^% SERVER_ID,
	String ^% USER_ID,
	String ^% BASKET_ASSET_TYPE_ID,
	String ^% BASKET_ASSET_ACCT_ID,
	Int32 % TRANSFER_MULTIPLE
	)
{
	Int32 n_TRANSFER_MULTIPLE = TRANSFER_MULTIPLE;
	return Managed(OTAPI_Wrap::GenerateBasketExchange(Native(SERVER_ID), Native(USER_ID), Native(BASKET_ASSET_TYPE_ID), Native(BASKET_ASSET_ACCT_ID), n_TRANSFER_MULTIPLE));
}

String ^ otapi_wrap::AddBasketExchangeItem(
	String ^% SERVER_ID,
	String ^% USER_ID,
	String ^% THE_BASKET, 
	String ^% ASSET_TYPE_ID,
	String ^% ASSET_ACCT_ID
	)
{
	return Managed(OTAPI_Wrap::AddBasketExchangeItem(Native(SERVER_ID), Native(USER_ID), Native(THE_BASKET), Native(ASSET_TYPE_ID), Native(ASSET_ACCT_ID)));
}

Int32 otapi_wrap::exchangeBasket(
	String ^% SERVER_ID,
	String ^% USER_ID,
	String ^% BASKET_ASSET_ID,
	String ^% THE_BASKET,
	Boolean % BOOL_EXCHANGE_IN_OR_OUT
	)
{
	Boolean n_BOOL_EXCHANGE_IN_OR_OUT = BOOL_EXCHANGE_IN_OR_OUT;
	return OTAPI_Wrap::exchangeBasket(Native(SERVER_ID), Native(USER_ID), Native(BASKET_ASSET_ID), Native(THE_BASKET), n_BOOL_EXCHANGE_IN_OR_OUT);
}

Int32 otapi_wrap::notarizeWithdrawal(
	String ^% SERVER_ID,
	String ^% USER_ID,
	String ^% ACCT_ID,
	Int64 % AMOUNT
	)
{
	return OTAPI_Wrap::notarizeWithdrawal(Native(SERVER_ID), Native(USER_ID), Native(ACCT_ID), Native(AMOUNT));
}

Int32 otapi_wrap::notarizeDeposit(
	String ^% SERVER_ID,
	String ^% USER_ID,
	String ^% ACCT_ID,
	String ^% THE_PURSE
	)
{
	return OTAPI_Wrap::notarizeDeposit(Native(SERVER_ID), Native(USER_ID), Native(ACCT_ID), Native(THE_PURSE));
}

Int32 otapi_wrap::notarizeTransfer(
	String ^% SERVER_ID,
	String ^% USER_ID,
	String ^% ACCT_FROM,
	String ^% ACCT_TO,
	Int64 % AMOUNT,
	String ^% NOTE
	)
{
	//String n_AMOUNT = AMOUNT;
	
	return OTAPI_Wrap::notarizeTransfer(Native(SERVER_ID), Native(USER_ID), Native(ACCT_FROM), Native(ACCT_TO), Native(AMOUNT), Native(NOTE));
}

Int32 otapi_wrap::getInbox(
	String ^% SERVER_ID,
	String ^% USER_ID,
	String ^% ACCT_ID
	)
{
	return OTAPI_Wrap::getInbox(Native(SERVER_ID), Native(USER_ID), Native(ACCT_ID));
}

Int32 otapi_wrap::getOutbox(
	String ^% SERVER_ID,
	String ^% USER_ID,
	String ^% ACCT_ID
	)
{
	return OTAPI_Wrap::getOutbox(Native(SERVER_ID), Native(USER_ID), Native(ACCT_ID));
}

Int32 otapi_wrap::getNymbox(
	String ^% SERVER_ID,
	String ^% USER_ID
	)
{
	return OTAPI_Wrap::getNymbox(Native(SERVER_ID), Native(USER_ID));
}

String ^ otapi_wrap::LoadNymbox(
	String ^% SERVER_ID,
	String ^% USER_ID
	)
{
	return Managed(OTAPI_Wrap::LoadNymbox(Native(SERVER_ID), Native(USER_ID)));
}

String ^ otapi_wrap::LoadNymboxNoVerify(
	String ^% SERVER_ID,
	String ^% USER_ID
	)
{
	return Managed(OTAPI_Wrap::LoadNymboxNoVerify(Native(SERVER_ID), Native(USER_ID)));
}

String ^ otapi_wrap::Nymbox_GetReplyNotice(
	String ^% SERVER_ID,
	String ^% USER_ID,
	Int64 % REQUEST_NUMBER
	)
{
	//String n_REQUEST_NUMBER = REQUEST_NUMBER;

	return Managed(OTAPI_Wrap::Nymbox_GetReplyNotice(Native(SERVER_ID), Native(USER_ID), Native(REQUEST_NUMBER)));
}

Boolean otapi_wrap::HaveAlreadySeenReply(
	String ^% SERVER_ID,
	String ^% USER_ID,
	Int64 % REQUEST_NUMBER
	)
{
	//String n_REQUEST_NUMBER = REQUEST_NUMBER;

	return OTAPI_Wrap::HaveAlreadySeenReply(Native(SERVER_ID), Native(USER_ID), Native(REQUEST_NUMBER));
}

Int32 otapi_wrap::getBoxReceipt(
	String ^% SERVER_ID,
	String ^% USER_ID,
	String ^% ACCOUNT_ID,
	Int32 % nBoxType,
	Int64 % TRANSACTION_NUMBER
	)
{
	Int32 n_nBoxType = nBoxType;
	//String n_TRANSACTION_NUMBER = TRANSACTION_NUMBER;

	return OTAPI_Wrap::getBoxReceipt(Native(SERVER_ID), Native(USER_ID), Native(ACCOUNT_ID), n_nBoxType, Native(TRANSACTION_NUMBER));
}

Boolean otapi_wrap::DoesBoxReceiptExist(
	String ^% SERVER_ID,
	String ^% USER_ID,
	String ^% ACCOUNT_ID,
	Int32 % nBoxType,
	Int64 % TRANSACTION_NUMBER
	)
{
	Int32 n_nBoxType = nBoxType;
	//String n_TRANSACTION_NUMBER = TRANSACTION_NUMBER;

	return OTAPI_Wrap::DoesBoxReceiptExist(Native(SERVER_ID), Native(USER_ID), Native(ACCOUNT_ID), n_nBoxType, Native(TRANSACTION_NUMBER));
}

Int32 otapi_wrap::processInbox(
	String ^% SERVER_ID,
	String ^% USER_ID,
	String ^% ACCT_ID,
	String ^% ACCT_LEDGER
	)
{
	return OTAPI_Wrap::processInbox(Native(SERVER_ID), Native(USER_ID), Native(ACCT_ID), Native(ACCT_LEDGER));
}

Int32 otapi_wrap::processNymbox(
	String ^% SERVER_ID,
	String ^% USER_ID
	)
{
	return OTAPI_Wrap::processNymbox(Native(SERVER_ID), Native(USER_ID));
}

Int32 otapi_wrap::withdrawVoucher(
	String ^% SERVER_ID,
	String ^% USER_ID,
	String ^% ACCT_ID,
	String ^% RECIPIENT_USER_ID,
	String ^% CHEQUE_MEMO,
	Int64 % AMOUNT
	)
{
	//String n_AMOUNT = AMOUNT;

	return OTAPI_Wrap::withdrawVoucher(Native(SERVER_ID), Native(USER_ID), Native(ACCT_ID), Native(RECIPIENT_USER_ID), Native(CHEQUE_MEMO), Native(AMOUNT));
}

Int32 otapi_wrap::payDividend(
	String ^% SERVER_ID,
	String ^% ISSUER_USER_ID,
	String ^% DIVIDEND_FROM_ACCT_ID,
	String ^% SHARES_ASSET_TYPE_ID,
	String ^% DIVIDEND_MEMO,
	Int64 % AMOUNT_PER_SHARE
	)
{
	//String n_AMOUNT_PER_SHARE = AMOUNT_PER_SHARE;

	return OTAPI_Wrap::payDividend(Native(SERVER_ID), Native(ISSUER_USER_ID), Native(DIVIDEND_FROM_ACCT_ID), Native(SHARES_ASSET_TYPE_ID), Native(DIVIDEND_MEMO), Native(AMOUNT_PER_SHARE));
}

Int32 otapi_wrap::depositCheque(
	String ^% SERVER_ID,
	String ^% USER_ID,
	String ^% ACCT_ID,
	String ^% THE_CHEQUE
	)
{
	return OTAPI_Wrap::depositCheque(Native(SERVER_ID), Native(USER_ID), Native(ACCT_ID), Native(THE_CHEQUE));
}

Int32 otapi_wrap::depositPaymentPlan(
	String ^% SERVER_ID,
	String ^% USER_ID,
	String ^% THE_PAYMENT_PLAN
	)
{
	return OTAPI_Wrap::depositPaymentPlan(Native(SERVER_ID), Native(USER_ID), Native(THE_PAYMENT_PLAN));
}

Int32 otapi_wrap::issueMarketOffer(
		String ^% SERVER_ID,
		String ^% USER_ID,
		String ^% ASSET_ACCT_ID,
		String ^% CURRENCY_ACCT_ID,
		Int64 % MARKET_SCALE,
		Int64 % MINIMUM_INCREMENT,
		Int64 % TOTAL_ASSETS_ON_OFFER,
		Int64 % PRICE_LIMIT,
		Boolean % bBuyingOrSelling,
		TimeSpan % LIFESPAN_IN_SECONDS
	)
{
	Boolean n_BuyingOrSelling = bBuyingOrSelling;

	return OTAPI_Wrap::issueMarketOffer(
		Native(SERVER_ID),
		Native(USER_ID),
		Native(ASSET_ACCT_ID),
		Native(CURRENCY_ACCT_ID),
		Native(MARKET_SCALE),
		Native(MINIMUM_INCREMENT),
		Native(TOTAL_ASSETS_ON_OFFER),
		Native(PRICE_LIMIT),
		n_BuyingOrSelling,
		Native(LIFESPAN_IN_SECONDS)
		);
}

Int32 otapi_wrap::getMarketList(
	String ^% SERVER_ID,
	String ^% USER_ID
	)
{
	return OTAPI_Wrap::getMarketList(Native(SERVER_ID), Native(USER_ID));
}

Int32 otapi_wrap::getMarketOffers(
	String ^% SERVER_ID,
	String ^% USER_ID, 
	String ^% MARKET_ID,
	Int64 % MAX_DEPTH
	)
{
	//String n_MAX_DEPTH = MAX_DEPTH;

	return OTAPI_Wrap::getMarketOffers(Native(SERVER_ID), Native(USER_ID), Native(MARKET_ID), Native(MAX_DEPTH));
}


Int32 otapi_wrap::getMarketRecentTrades(
	String ^% SERVER_ID,
	String ^% USER_ID, 
	String ^% MARKET_ID
	)
{
	return OTAPI_Wrap::getMarketRecentTrades(Native(SERVER_ID), Native(USER_ID), Native(MARKET_ID));
}

Int32 otapi_wrap::getNym_MarketOffers(
	String ^% SERVER_ID,
	String ^% USER_ID
	)
{
	return OTAPI_Wrap::getNym_MarketOffers(Native(SERVER_ID), Native(USER_ID));
}

Int32 otapi_wrap::cancelMarketOffer(
	String ^% SERVER_ID, 
	String ^% USER_ID, 
	String ^% ASSET_ACCT_ID, 
	Int64 % TRANSACTION_NUMBER
	)
{
	//String n_TRANSACTION_NUMBER = TRANSACTION_NUMBER;

	return OTAPI_Wrap::cancelMarketOffer(Native(SERVER_ID), Native(USER_ID), Native(ASSET_ACCT_ID), Native(TRANSACTION_NUMBER));
}

Int32 otapi_wrap::cancelPaymentPlan(
	String ^% SERVER_ID, 
	String ^% USER_ID, 
	String ^% FROM_ACCT_ID, 
	Int64 % TRANSACTION_NUMBER
	)
{
	//String n_TRANSACTION_NUMBER = TRANSACTION_NUMBER;

	return OTAPI_Wrap::cancelPaymentPlan(Native(SERVER_ID), Native(USER_ID), Native(FROM_ACCT_ID), Native(TRANSACTION_NUMBER));
}

String ^ otapi_wrap::PopMessageBuffer(
	Int64 % REQUEST_NUMBER,
	String ^% SERVER_ID, 
	String ^% USER_ID
	)
{
	//String n_REQUEST_NUMBER = REQUEST_NUMBER;

	return Managed(OTAPI_Wrap::PopMessageBuffer(Native(REQUEST_NUMBER), Native(SERVER_ID), Native(USER_ID)));
}

void otapi_wrap::FlushMessageBuffer(void) { return OTAPI_Wrap::FlushMessageBuffer(); }

String ^ otapi_wrap::GetSentMessage(
	Int64 % REQUEST_NUMBER,
	String ^% SERVER_ID, 
	String ^% USER_ID
	)
{
	//String n_REQUEST_NUMBER = REQUEST_NUMBER;

	return Managed(OTAPI_Wrap::GetSentMessage(Native(REQUEST_NUMBER), Native(SERVER_ID), Native(USER_ID)));
}

Boolean otapi_wrap::RemoveSentMessage(
	Int64 % REQUEST_NUMBER,
	String ^% SERVER_ID, 
	String ^% USER_ID
	)
{
	//String n_REQUEST_NUMBER = REQUEST_NUMBER;

	return OTAPI_Wrap::RemoveSentMessage(Native(REQUEST_NUMBER), Native(SERVER_ID), Native(USER_ID));
}

void otapi_wrap::FlushSentMessages(
	Boolean % bHarvestingForRetry,
	String ^% SERVER_ID, 
	String ^% USER_ID,
	String ^% THE_NYMBOX
	)
{
	Boolean n_bHarvestingForRetry = bHarvestingForRetry;

	OTAPI_Wrap::FlushSentMessages(n_bHarvestingForRetry, Native(SERVER_ID), Native(USER_ID), Native(THE_NYMBOX));
}

void otapi_wrap::Sleep(Int64 % MILLISECONDS)
{
	//String n_MILLISECONDS = MILLISECONDS;

	OTAPI_Wrap::Sleep(Native(MILLISECONDS));
}

Boolean otapi_wrap::ResyncNymWithServer(
	String ^% SERVER_ID,
	String ^% USER_ID,
	String ^% THE_MESSAGE
	)
{
	return OTAPI_Wrap::ResyncNymWithServer(Native(SERVER_ID), Native(USER_ID), Native(THE_MESSAGE));
}

String ^ otapi_wrap::Message_GetCommand(String ^% THE_MESSAGE) { return Managed(OTAPI_Wrap::Message_GetCommand(Native(THE_MESSAGE))); }

Int32 otapi_wrap::Message_GetSuccess(String ^% THE_MESSAGE) { return OTAPI_Wrap::Message_GetSuccess(Native(THE_MESSAGE)); }

Int32 otapi_wrap::queryAssetTypes(
	String ^% SERVER_ID,
	String ^% USER_ID,
	String ^% ENCODED_MAP
	)
{
	return OTAPI_Wrap::queryAssetTypes(Native(SERVER_ID), Native(USER_ID), Native(ENCODED_MAP));
}

String ^ otapi_wrap::Message_GetPayload(String ^% THE_MESSAGE) { return Managed(OTAPI_Wrap::Message_GetPayload(Native(THE_MESSAGE))); }

Int32 otapi_wrap::Message_GetDepth(String ^% THE_MESSAGE) { return OTAPI_Wrap::Message_GetDepth(Native(THE_MESSAGE)); }

Int32 otapi_wrap::Message_GetTransactionSuccess(
	String ^% SERVER_ID,
	String ^% USER_ID,
	String ^% ACCOUNT_ID,
	String ^% THE_MESSAGE
	)
{
	return OTAPI_Wrap::Message_GetTransactionSuccess(Native(SERVER_ID), Native(USER_ID), Native(ACCOUNT_ID), Native(THE_MESSAGE));
}


Int32 otapi_wrap::Message_GetBalanceAgreementSuccess(
	String ^% SERVER_ID,
	String ^% USER_ID,
	String ^% ACCOUNT_ID,
	String ^% THE_MESSAGE
	)
{
	return OTAPI_Wrap::Message_GetBalanceAgreementSuccess(Native(SERVER_ID), Native(USER_ID), Native(ACCOUNT_ID), Native(THE_MESSAGE));
}

String ^ otapi_wrap::Message_GetLedger(String ^% THE_MESSAGE) { return Managed(OTAPI_Wrap::Message_GetLedger(Native(THE_MESSAGE))); }

String ^ otapi_wrap::Message_GetNewAssetTypeID(String ^% THE_MESSAGE) { return Managed(OTAPI_Wrap::Message_GetNewAssetTypeID(Native(THE_MESSAGE))); }

String ^ otapi_wrap::Message_GetNewIssuerAcctID(String ^% THE_MESSAGE) { return Managed(OTAPI_Wrap::Message_GetNewIssuerAcctID(Native(THE_MESSAGE))); }

String ^ otapi_wrap::Message_GetNewAcctID(String ^% THE_MESSAGE) { return Managed(OTAPI_Wrap::Message_GetNewAcctID(Native(THE_MESSAGE))); }

String ^ otapi_wrap::Message_GetNymboxHash(String ^% THE_MESSAGE) { return Managed(OTAPI_Wrap::Message_GetNymboxHash(Native(THE_MESSAGE))); }

Boolean otapi_wrap::ConnectServer(
	String ^% SERVER_ID,
	String ^% USER_ID, 
	String ^% strCA_FILE,
	String ^% strKEY_FILE, 
	String ^% strKEY_PASSWORD
	)
{
	return OTAPI_Wrap::ConnectServer(Native(SERVER_ID), Native(USER_ID), Native(strCA_FILE), Native(strKEY_FILE), Native(strKEY_PASSWORD));
}

Boolean otapi_wrap::ProcessSockets() { return OTAPI_Wrap::ProcessSockets(); }


