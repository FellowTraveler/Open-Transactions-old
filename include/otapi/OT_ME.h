/************************************************************************************

OT_ME.h  aka "OT Made Easy" -- used for sending requests to the server.

In this class only following types are accepted:
bool, int32_t, int64_t, std::string
 
 This file is used like OTAPI.h
 
*/

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


#ifndef __OT_ME_H__
#define __OT_ME_H__

#ifndef EXPORT
#define EXPORT
#endif
#ifndef NOEXPORT
#include <ExportWrapper.h>
#endif


#include <string>

#include <OTScript.h>

// -------------------------------------------------------

EXPORT int         OT_CLI_GetArgsCount    (const std::string str_Args);
EXPORT std::string OT_CLI_GetValueByKey   (const std::string str_Args, const std::string str_key);
EXPORT std::string OT_CLI_GetValueByIndex (const std::string str_Args, const int nIndex);
EXPORT std::string OT_CLI_GetKeyByIndex   (const std::string str_Args, const int nIndex);
EXPORT std::string OT_CLI_ReadLine();
EXPORT std::string OT_CLI_ReadUntilEOF();

// -------------------------------------------------------

class OTVariable;

// -------------------------------------------------------

class OT_ME
{
private:
    
    OTScript_SharedPtr     m_pScript;
    // --------------------------------------
    bool SetupScriptObject();
    bool HaveWorkingScript();
    // --------------------------------------
    bool Register_OTDB_With_Script();
    bool Register_CLI_With_Script();
    bool Register_API_With_Script();
    bool Register_Headers_With_Script();
    // --------------------------------------
    // For ChaiScript:
    //
    bool Register_OTDB_With_Script_Chai    (OTScriptChai & theScript);
    bool Register_CLI_With_Script_Chai     (OTScriptChai & theScript);
    bool Register_API_With_Script_Chai     (OTScriptChai & theScript);
    bool Register_Headers_With_Script_Chai (OTScriptChai & theScript);
    
    // For Lua (etc.)
//  bool Register_OTDB_With_Script_Lua     (OTScriptLua & theScript);
//  bool Register_CLI_With_Script_Lua      (OTScriptLua & theScript);
//  bool Register_API_With_Script_Lua      (OTScriptLua & theScript);
//  bool Register_Headers_With_Script_Lua  (OTScriptLua & theScript);
    // --------------------------------------

    // Note: in the long run, we will have C++ implementations
    // for all the functions in OT_ME. But in the meantime, since
    // we already have script implementations, we'll make a C++
    // wrapper for those, and that way the other languages such as
    // Python, Ruby, D, etc will be able to access the high-level API
    // via their swig wrappers of these functions.
    
public:
    
    EXPORT OT_ME();
    EXPORT ~OT_ME();
    
    // --------------------------------------
    EXPORT  bool make_sure_enough_trans_nums(const int32_t      & nNumberNeeded,
                                             const std::string  & SERVER_ID,
                                             const std::string  & NYM_ID);
    // --------------------------------------
    EXPORT  std::string register_nym(const std::string  & SERVER_ID,
                                     const std::string  & NYM_ID);
    EXPORT  std::string check_user(const std::string  & SERVER_ID,
                                   const std::string  & NYM_ID,
                                   const std::string  & TARGET_NYM_ID);
    EXPORT  std::string create_pseudonym(const int32_t & nKeybits,
                                         const std::string & NYM_ID_SOURCE,
                                         const std::string & ALT_LOCATION);
    EXPORT  std::string issue_asset_type(const std::string  & SERVER_ID,
                                         const std::string  & NYM_ID,
                                         const std::string  & THE_CONTRACT);
    EXPORT  std::string retrieve_contract(const std::string  & SERVER_ID,
                                          const std::string  & NYM_ID,
                                          const std::string  & CONTRACT_ID);
    EXPORT  std::string load_or_retrieve_contract(const std::string  & SERVER_ID,
                                                  const std::string  & NYM_ID,
                                                  const std::string  & CONTRACT_ID);
    EXPORT  std::string create_asset_acct(const std::string  & SERVER_ID,
                                          const std::string  & NYM_ID,
                                          const std::string  & ASSET_TYPE_ID);
    EXPORT  std::string stat_asset_account(const std::string  & ACCOUNT_ID);
    EXPORT  bool retrieve_account(const std::string  & SERVER_ID,
                                  const std::string  & NYM_ID,
                                  const std::string  & ACCOUNT_ID);
    EXPORT  bool retrieve_account(const std::string  & SERVER_ID,
                                  const std::string  & NYM_ID,
                                  const std::string  & ACCOUNT_ID,
                                  const bool      bForceDownload);
    EXPORT  bool retrieve_nym(const std::string  & SERVER_ID,
                              const std::string  & NYM_ID);
    EXPORT  bool retrieve_nym(const std::string  & SERVER_ID,
                              const std::string  & NYM_ID,
                              const bool      bForceDownload);
    EXPORT  std::string send_transfer(const std::string  & SERVER_ID,
                                      const std::string  & NYM_ID,
                                      const std::string  & ACCT_FROM,
                                      const std::string  & ACCT_TO,
                                      const int64_t      & AMOUNT,
                                      const std::string  & NOTE);
    EXPORT  std::string process_inbox(const std::string  & SERVER_ID,
                                      const std::string  & NYM_ID,
                                      const std::string  & ACCOUNT_ID,
                                      const std::string  & RESPONSE_LEDGER);
    EXPORT  std::string load_public_encryption_key(const std::string  & NYM_ID);	// from local storage.
    EXPORT  std::string load_public_signing_key(const std::string  & NYM_ID);	// from local storage.
    EXPORT  std::string load_or_retrieve_encrypt_key(const std::string  & SERVER_ID,
                                                     const std::string  & NYM_ID,
                                                     const std::string  & TARGET_NYM_ID);
    EXPORT  std::string load_or_retrieve_signing_key(const std::string  & SERVER_ID,
                                                     const std::string  & NYM_ID,
                                                     const std::string  & TARGET_NYM_ID);
    EXPORT  std::string send_user_msg_pubkey(const std::string  & SERVER_ID,
                                             const std::string  & NYM_ID,
                                             const std::string  & RECIPIENT_NYM_ID,
                                             const std::string  & RECIPIENT_PUBKEY,
                                             const std::string  & THE_MESSAGE);
    EXPORT  std::string send_user_pmnt_pubkey(const std::string  & SERVER_ID,
                                              const std::string  & NYM_ID,
                                              const std::string  & RECIPIENT_NYM_ID,
                                              const std::string  & RECIPIENT_PUBKEY,
                                              const std::string  & THE_INSTRUMENT);
    EXPORT  std::string send_user_cash_pubkey(const std::string  & SERVER_ID,
                                              const std::string  & NYM_ID,
                                              const std::string  & RECIPIENT_NYM_ID,
                                              const std::string  & RECIPIENT_PUBKEY,
                                              const std::string  & THE_INSTRUMENT,
                                              const std::string  & INSTRUMENT_FOR_SENDER);
    EXPORT  std::string send_user_msg(const std::string  & SERVER_ID,
                                      const std::string  & NYM_ID,
                                      const std::string  & RECIPIENT_NYM_ID,
                                      const std::string  & THE_MESSAGE);
    EXPORT  std::string send_user_payment(const std::string  & SERVER_ID,
                                          const std::string  & NYM_ID,
                                          const std::string  & RECIPIENT_NYM_ID,
                                          const std::string  & THE_PAYMENT);
    EXPORT  std::string send_user_cash(const std::string  & SERVER_ID,
                                       const std::string  & NYM_ID,
                                       const std::string  & RECIPIENT_NYM_ID,
                                       const std::string  & THE_PAYMENT,
                                       const std::string  & SENDERS_COPY);
    EXPORT  std::string get_payment_instrument(const std::string  & SERVER_ID,
                                               const std::string  & NYM_ID,
                                               const int32_t & nIndex);
    EXPORT  std::string get_payment_instrument(const std::string  & SERVER_ID,
                                               const std::string  & NYM_ID,
                                               const int32_t & nIndex,
                                               const std::string  & PRELOADED_INBOX); // PRELOADED_INBOX is optional.
    EXPORT  std::string get_box_receipt(const std::string  & SERVER_ID,
                                        const std::string  & NYM_ID,
                                        const std::string  & ACCT_ID,
                                        const int32_t & nBoxType,
                                        const int64_t & TRANS_NUM);
    EXPORT  std::string retrieve_mint(const std::string  & SERVER_ID,
                                      const std::string  & NYM_ID,
                                      const std::string  & ASSET_ID);
    EXPORT  std::string load_or_retrieve_mint(const std::string  & SERVER_ID,
                                              const std::string  & NYM_ID,
                                              const std::string  & ASSET_ID);
    EXPORT  std::string query_asset_types(const std::string  & SERVER_ID,
                                          const std::string  & NYM_ID,
                                          const std::string  & ENCODED_MAP);
    EXPORT  std::string create_market_offer(const std::string  & SERVER_ID,
                                            const std::string  & NYM_ID,
                                            const std::string  & ASSET_ACCT_ID,
                                            const std::string  & CURRENCY_ACCT_ID,
                                            const int64_t & scale,
                                            const int64_t & minIncrement,
                                            const int64_t & quantity,
                                            const int64_t & price,
                                            const bool      bSelling,
                                            const int64_t & lLifespanInSeconds); // 0 does default of 86400 == 1 day.
    EXPORT  std::string cancel_market_offer(const std::string  & SERVER_ID,
                                            const std::string  & NYM_ID,
                                            const std::string  & ASSET_ACCT_ID,
                                            const int64_t & TRANS_NUM);
    EXPORT  std::string cancel_payment_plan(const std::string  & SERVER_ID,
                                            const std::string  & NYM_ID,
                                            const std::string  & ACCT_ID,
                                            const int64_t & TRANS_NUM);
    EXPORT  std::string activate_smart_contract(const std::string  & SERVER_ID,
                                                const std::string  & NYM_ID,
                                                const std::string  & ACCT_ID,
                                                const std::string  & AGENT_NAME,
                                                const std::string  & THE_SMART_CONTRACT);
    EXPORT  std::string trigger_clause(const std::string  & SERVER_ID,
                                       const std::string  & NYM_ID,
                                       const int64_t & TRANS_NUM,
                                       const std::string  & CLAUSE_NAME,
                                       const std::string  & STR_PARAM);
    EXPORT  std::string withdraw_cash(const std::string  & SERVER_ID,
                                      const std::string  & NYM_ID,
                                      const std::string  & ACCT_ID,
                                      const int64_t & AMOUNT);
    EXPORT  std::string withdraw_voucher(const std::string  & SERVER_ID,
                                         const std::string  & NYM_ID,
                                         const std::string  & ACCT_ID,
                                         const std::string  & RECIP_NYM_ID,
                                         const std::string  & STR_MEMO,
                                         const int64_t & AMOUNT);
    EXPORT  std::string pay_dividend(const std::string  & SERVER_ID,
                                     const std::string  & NYM_ID,
                                     const std::string  & SOURCE_ACCT_ID,
                                     const std::string  & SHARES_ASSET_ID,
                                     const std::string  & STR_MEMO,
                                     const int64_t & AMOUNT_PER_SHARE);
    EXPORT  std::string deposit_cheque(const std::string  & SERVER_ID,
                                       const std::string  & NYM_ID,
                                       const std::string  & ACCT_ID,
                                       const std::string  & STR_CHEQUE);
    EXPORT  std::string get_market_list(const std::string  & SERVER_ID,
                                        const std::string  & NYM_ID);
    EXPORT  std::string get_market_offers(const std::string  & SERVER_ID,
                                          const std::string  & NYM_ID,
                                          const std::string  & MARKET_ID,
                                          const int64_t & MAX_DEPTH);
    EXPORT  std::string get_nym_market_offers(const std::string  & SERVER_ID,
                                              const std::string  & NYM_ID);
    EXPORT  std::string get_market_recent_trades(const std::string  & SERVER_ID,
                                                 const std::string  & NYM_ID,
                                                 const std::string  & MARKET_ID);
    EXPORT  std::string adjust_usage_credits(const std::string  & SERVER_ID,
                                             const std::string  & USER_NYM_ID,
                                             const std::string  & TARGET_NYM_ID,
                                             const std::string  & ADJUSTMENT);
    EXPORT  int32_t VerifyMessageSuccess(const std::string & str_Message);
    EXPORT  int32_t VerifyMsgBalanceAgrmntSuccess(const std::string & SERVER_ID,
                                                  const std::string & USER_ID,
                                                  const std::string & ACCOUNT_ID,
                                                  const std::string & str_Message);
    EXPORT  int32_t VerifyMsgTrnxSuccess(const std::string & SERVER_ID,
                                         const std::string & USER_ID,
                                         const std::string & ACCOUNT_ID,
                                         const std::string & str_Message);
    EXPORT  int32_t InterpretTransactionMsgReply(const std::string & SERVER_ID,
                                                 const std::string & USER_ID,
                                                 const std::string & ACCOUNT_ID,
                                                 const std::string & str_Attempt,
                                                 const std::string & str_Response);
    // ------------------------------------------------------
    EXPORT  std::string   ExecuteScript_ReturnString(const std::string & str_Code, std::string str_DisplayName="<BLANK>");
    EXPORT  bool          ExecuteScript_ReturnBool  (const std::string & str_Code, std::string str_DisplayName="<BLANK>");
    EXPORT  int           ExecuteScript_ReturnInt   (const std::string & str_Code, std::string str_DisplayName="<BLANK>");
    EXPORT  void          ExecuteScript_ReturnVoid  (const std::string & str_Code, std::string str_DisplayName="<BLANK>");
    // --------------------------------------
    EXPORT  void          AddVariable               (const std::string & str_var_name, OTVariable & theVar);
    // ------------------------------------------------------
};
















#endif   // __OT_ME_H__















