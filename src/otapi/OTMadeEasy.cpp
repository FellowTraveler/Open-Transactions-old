/************************************************************************************

OTMadeEasy.cpp   --	A C++ wrapper class (named OTMadeEasy)

This is a wrapper for OT_ME
 
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

#ifndef EXPORT
#define EXPORT
#endif
#ifndef NOEXPORT
#include <ExportWrapper.h>
#endif

#include <string>

#include <memory>



#include "OTMadeEasy.h"
#include "OTAPI.h"
#include "OT_ME.h"

#include "OTLog.h"


using namespace std;


OTMadeEasy::OTMadeEasy() : m_pME(new OT_ME)
{

}

OTMadeEasy::~OTMadeEasy()
{
    if (NULL != m_pME)
        delete m_pME;
    m_pME = NULL;
}


// **********************************************************************


std::string OTMadeEasy::register_nym(const std::string  & SERVER_ID,
                                     const std::string  & NYM_ID)
{
	return m_pME->register_nym(SERVER_ID, NYM_ID);
}


std::string OTMadeEasy::check_user(const std::string  & SERVER_ID,
                                   const std::string  & NYM_ID,
                                   const std::string  & TARGET_NYM_ID)
{
	return m_pME->check_user(SERVER_ID, NYM_ID, TARGET_NYM_ID);
}


std::string OTMadeEasy::create_pseudonym(const long & nKeybits)
{
	return m_pME->create_pseudonym(static_cast<int32_t>(nKeybits));
}


std::string OTMadeEasy::issue_asset_type(const std::string  & SERVER_ID,
                                         const std::string  & NYM_ID,
                                         const std::string  & THE_CONTRACT)
{
	return m_pME->issue_asset_type(SERVER_ID, NYM_ID, THE_CONTRACT);    
}


std::string OTMadeEasy::retrieve_contract(const std::string  & SERVER_ID,
                                          const std::string  & NYM_ID,
                                          const std::string  & CONTRACT_ID)
{
	return m_pME->retrieve_contract(SERVER_ID, NYM_ID, CONTRACT_ID);    
}


std::string OTMadeEasy::load_or_retrieve_contract(const std::string  & SERVER_ID,
                                                  const std::string  & NYM_ID,
                                                  const std::string  & CONTRACT_ID)
{
	return m_pME->load_or_retrieve_contract(SERVER_ID, NYM_ID, CONTRACT_ID);    
}


std::string OTMadeEasy::create_asset_acct(const std::string  & SERVER_ID,
                                          const std::string  & NYM_ID,
                                          const std::string  & ASSET_TYPE_ID)
{
	return m_pME->create_asset_acct(SERVER_ID, NYM_ID, ASSET_TYPE_ID);    
}


std::string OTMadeEasy::stat_asset_account(const std::string & ACCOUNT_ID)
{
	return m_pME->stat_asset_account(ACCOUNT_ID);
}


bool OTMadeEasy::retrieve_account(const std::string  & SERVER_ID,
                                  const std::string  & NYM_ID,
                                  const std::string  & ACCOUNT_ID)
{
	return m_pME->retrieve_account(SERVER_ID, NYM_ID, ACCOUNT_ID);
}


bool OTMadeEasy::retrieve_account(const std::string  & SERVER_ID,
                                  const std::string  & NYM_ID,
                                  const std::string  & ACCOUNT_ID,
                                  const bool           bForceDownload)
{
	return m_pME->retrieve_account(SERVER_ID, NYM_ID, ACCOUNT_ID, bForceDownload);
}


std::string OTMadeEasy::send_transfer(const std::string  & SERVER_ID,
                                      const std::string  & NYM_ID,
                                      const std::string  & ACCT_FROM,
                                      const std::string  & ACCT_TO,
                                      const std::string  & AMOUNT,
                                      const std::string  & NOTE)
{
	return m_pME->send_transfer(SERVER_ID, NYM_ID, ACCT_FROM, ACCT_TO, OTAPI_Wrap::StringToLong(AMOUNT), NOTE);
}


std::string OTMadeEasy::process_inbox(const std::string  & SERVER_ID,
                                      const std::string  & NYM_ID,
                                      const std::string  & ACCOUNT_ID,
                                      const std::string  & RESPONSE_LEDGER)
{
 	return m_pME->process_inbox(SERVER_ID, NYM_ID, ACCOUNT_ID, RESPONSE_LEDGER);
}


std::string OTMadeEasy::load_public_encryption_key(const std::string & NYM_ID) // from local storage.
{
	return m_pME->load_public_encryption_key(NYM_ID);
}


std::string OTMadeEasy::load_or_retrieve_encrypt_key(const std::string  & SERVER_ID,
                                                     const std::string  & NYM_ID,
                                                     const std::string  & TARGET_NYM_ID)
{
    return m_pME->load_or_retrieve_encrypt_key(SERVER_ID, NYM_ID, TARGET_NYM_ID);
}


std::string OTMadeEasy::load_public_signing_key(const std::string & NYM_ID) // from local storage.
{
	return m_pME->load_public_signing_key(NYM_ID);
}


std::string OTMadeEasy::load_or_retrieve_signing_key(const std::string  & SERVER_ID,
                                                     const std::string  & NYM_ID,
                                                     const std::string  & TARGET_NYM_ID)
{
    return m_pME->load_or_retrieve_signing_key(SERVER_ID, NYM_ID, TARGET_NYM_ID);
}


std::string OTMadeEasy::send_user_msg_pubkey(const std::string  & SERVER_ID,
                                             const std::string  & NYM_ID,
                                             const std::string  & RECIPIENT_NYM_ID,
                                             const std::string  & RECIPIENT_PUBKEY,
                                             const std::string  & THE_MESSAGE)
{
    return m_pME->send_user_msg_pubkey(SERVER_ID, NYM_ID, RECIPIENT_NYM_ID, RECIPIENT_PUBKEY, THE_MESSAGE);
}


std::string OTMadeEasy::send_user_pmnt_pubkey(const std::string  & SERVER_ID,
                                              const std::string  & NYM_ID,
                                              const std::string  & RECIPIENT_NYM_ID,
                                              const std::string  & RECIPIENT_PUBKEY,
                                              const std::string  & THE_INSTRUMENT)
{
    return m_pME->send_user_pmnt_pubkey(SERVER_ID, NYM_ID, RECIPIENT_NYM_ID, RECIPIENT_PUBKEY, THE_INSTRUMENT);
}


std::string OTMadeEasy::send_user_msg(const std::string  & SERVER_ID,
                                      const std::string  & NYM_ID,
                                      const std::string  & RECIPIENT_NYM_ID,
                                      const std::string  & THE_MESSAGE)
{
    return m_pME->send_user_msg(SERVER_ID, NYM_ID, RECIPIENT_NYM_ID, THE_MESSAGE);    
}


std::string OTMadeEasy::send_user_payment(const std::string  & SERVER_ID,
                                          const std::string  & NYM_ID,
                                          const std::string  & RECIPIENT_NYM_ID,
                                          const std::string  & THE_PAYMENT)
{
    return m_pME->send_user_payment(SERVER_ID, NYM_ID, RECIPIENT_NYM_ID, THE_PAYMENT);
}


std::string OTMadeEasy::get_payment_instrument(const std::string  & SERVER_ID,
                                               const std::string  & NYM_ID,
                                               const long         & nIndex)
{
    return m_pME->get_payment_instrument(SERVER_ID, NYM_ID, static_cast<int32_t>(nIndex));
}


std::string OTMadeEasy::get_payment_instrument(const std::string  & SERVER_ID,
                                               const std::string  & NYM_ID,
                                               const long         & nIndex,
                                               const std::string  & PRELOADED_INBOX) // PRELOADED_INBOX is optional.
{
    return m_pME->get_payment_instrument(SERVER_ID, NYM_ID, static_cast<int32_t>(nIndex), PRELOADED_INBOX); 
}


std::string OTMadeEasy::get_box_receipt(const std::string  & SERVER_ID,
                                        const std::string  & NYM_ID,
                                        const std::string  & ACCT_ID,
                                        const long         & nBoxType,
                                        const std::string  & TRANS_NUM)
{
    return m_pME->get_box_receipt(SERVER_ID, NYM_ID, ACCT_ID, static_cast<int32_t>(nBoxType), OTAPI_Wrap::StringToLong(TRANS_NUM));
}


std::string OTMadeEasy::retrieve_mint(const std::string  & SERVER_ID,
                                      const std::string  & NYM_ID,
                                      const std::string  & ASSET_ID)
{
    return m_pME->retrieve_mint(SERVER_ID, NYM_ID, ASSET_ID);
}


std::string OTMadeEasy::load_or_retrieve_mint(const std::string  & SERVER_ID,
                                              const std::string  & NYM_ID,
                                              const std::string  & ASSET_ID)
{
    return m_pME->load_or_retrieve_mint(SERVER_ID, NYM_ID, ASSET_ID);
}

std::string OTMadeEasy::query_asset_types(const std::string  & SERVER_ID,
                                          const std::string  & NYM_ID,
                                          const std::string  & ENCODED_MAP)
{
    return m_pME->load_or_retrieve_mint(SERVER_ID, NYM_ID, ENCODED_MAP);
}


std::string OTMadeEasy::create_market_offer(const std::string  & SERVER_ID,
                                            const std::string  & NYM_ID,
                                            const std::string  & ASSET_ACCT_ID,
                                            const std::string  & CURRENCY_ACCT_ID,
                                            const std::string  & scale,
                                            const std::string  & minIncrement,
                                            const std::string  & quantity,
                                            const std::string  & price,
                                            const bool           bSelling)
{
    return m_pME->create_market_offer(SERVER_ID,
                                      NYM_ID,
                                      ASSET_ACCT_ID,
                                      CURRENCY_ACCT_ID,
                                      OTAPI_Wrap::StringToLong(scale),
                                      OTAPI_Wrap::StringToLong(minIncrement),
                                      OTAPI_Wrap::StringToLong(quantity),
                                      OTAPI_Wrap::StringToLong(price),
                                      bSelling);
}


std::string OTMadeEasy::cancel_market_offer(const std::string  & SERVER_ID,
                                            const std::string  & NYM_ID,
                                            const std::string  & ASSET_ACCT_ID,
                                            const std::string  & TRANS_NUM)
{
    return m_pME->cancel_market_offer(SERVER_ID,
                                      NYM_ID,
                                      ASSET_ACCT_ID,
                                      OTAPI_Wrap::StringToLong(TRANS_NUM));
}


std::string OTMadeEasy::cancel_payment_plan(const std::string  & SERVER_ID,
                                            const std::string  & NYM_ID,
                                            const std::string  & ACCT_ID,
                                            const std::string  & TRANS_NUM)
{
    return m_pME->cancel_payment_plan(SERVER_ID,
                                      NYM_ID,
                                      ACCT_ID,
                                      OTAPI_Wrap::StringToLong(TRANS_NUM));    
}


std::string OTMadeEasy::activate_smart_contract(const std::string  & SERVER_ID,
                                                const std::string  & NYM_ID,
                                                const std::string  & ACCT_ID,
                                                const std::string  & AGENT_NAME,
                                                const std::string  & THE_SMART_CONTRACT)
{
    return m_pME->activate_smart_contract(SERVER_ID,
                                          NYM_ID,
                                          ACCT_ID,
                                          AGENT_NAME,
                                          THE_SMART_CONTRACT);
}


std::string OTMadeEasy::trigger_clause(const std::string  & SERVER_ID,
                                       const std::string  & NYM_ID,
                                       const std::string  & TRANS_NUM,
                                       const std::string  & CLAUSE_NAME,
                                       const std::string  & STR_PARAM)
{
    return m_pME->trigger_clause(SERVER_ID,
                                 NYM_ID,
                                 OTAPI_Wrap::StringToLong(TRANS_NUM),
                                 CLAUSE_NAME,
                                 STR_PARAM);
}


std::string OTMadeEasy::withdraw_cash(const std::string  & SERVER_ID,
                                      const std::string  & NYM_ID,
                                      const std::string  & ACCT_ID,
                                      const std::string  & AMOUNT)
{
    return m_pME->withdraw_cash(SERVER_ID,
                                NYM_ID,
                                ACCT_ID,
                                OTAPI_Wrap::StringToLong(AMOUNT));
}


std::string OTMadeEasy::withdraw_voucher(const std::string  & SERVER_ID,
                                         const std::string  & NYM_ID,
                                         const std::string  & ACCT_ID,
                                         const std::string  & RECIP_NYM_ID,
                                         const std::string  & STR_MEMO,
                                         const std::string  & AMOUNT)
{
    return m_pME->withdraw_voucher(SERVER_ID,
                                   NYM_ID,
                                   ACCT_ID,
                                   RECIP_NYM_ID,
                                   STR_MEMO,
                                   OTAPI_Wrap::StringToLong(AMOUNT));
}


std::string OTMadeEasy::pay_dividend(const std::string  & SERVER_ID,
                                     const std::string  & NYM_ID,
                                     const std::string  & SOURCE_ACCT_ID,
                                     const std::string  & SHARES_ASSET_ID,
                                     const std::string  & STR_MEMO,
                                     const std::string  & AMOUNT_PER_SHARE)
{
    return m_pME->pay_dividend(SERVER_ID,
                               NYM_ID,
                               SOURCE_ACCT_ID,
                               SHARES_ASSET_ID,
                               STR_MEMO,
                               OTAPI_Wrap::StringToLong(AMOUNT_PER_SHARE));
}


std::string OTMadeEasy::deposit_cheque(const std::string  & SERVER_ID,
                                       const std::string  & NYM_ID,
                                       const std::string  & ACCT_ID,
                                       const std::string  & STR_CHEQUE)
{
    return m_pME->deposit_cheque(SERVER_ID,
                                 NYM_ID,
                                 ACCT_ID,
                                 STR_CHEQUE);
}


std::string OTMadeEasy::get_market_list(const std::string  & SERVER_ID,
                                        const std::string  & NYM_ID)
{
    return m_pME->get_market_list(SERVER_ID, NYM_ID);
}


std::string OTMadeEasy::get_market_offers(const std::string  & SERVER_ID,
                                          const std::string  & NYM_ID,
                                          const std::string  & MARKET_ID,
                                          const std::string  & MAX_DEPTH)
{
    return m_pME->get_market_offers(SERVER_ID,
                                    NYM_ID,
                                    MARKET_ID,
                                    OTAPI_Wrap::StringToLong(MAX_DEPTH));
}


std::string OTMadeEasy::get_nym_market_offers(const std::string  & SERVER_ID,
                                              const std::string  & NYM_ID)
{
    return m_pME->get_nym_market_offers(SERVER_ID, NYM_ID);
}


std::string OTMadeEasy::get_market_recent_trades(const std::string  & SERVER_ID,
                                                 const std::string  & NYM_ID,
                                                 const std::string  & MARKET_ID)
{
    return m_pME->get_market_recent_trades(SERVER_ID, NYM_ID, MARKET_ID);
}


std::string OTMadeEasy::adjust_usage_credits(const std::string  & SERVER_ID,
                                             const std::string  & USER_NYM_ID,
                                             const std::string  & TARGET_NYM_ID,
                                             const std::string  & ADJUSTMENT)
{
    return m_pME->adjust_usage_credits(SERVER_ID, USER_NYM_ID, TARGET_NYM_ID, ADJUSTMENT);
}


long OTMadeEasy::VerifyMessageSuccess(const std::string & str_Message)
{
    const long lReturn = static_cast<long>(m_pME->VerifyMessageSuccess(str_Message));
    return lReturn;
}


long OTMadeEasy::VerifyMsgBalanceAgrmntSuccess(const std::string & SERVER_ID,
                                               const std::string & USER_ID,
                                               const std::string & ACCOUNT_ID,
                                               const std::string & str_Message)
{
    const long lReturn = static_cast<long>(m_pME->VerifyMsgBalanceAgrmntSuccess(SERVER_ID, USER_ID, ACCOUNT_ID, str_Message));
    return lReturn;    
}


long OTMadeEasy::VerifyMsgTrnxSuccess(const std::string & SERVER_ID,
                                      const std::string & USER_ID,
                                      const std::string & ACCOUNT_ID,
                                      const std::string & str_Message)
{
    const long lReturn = static_cast<long>(m_pME->VerifyMsgTrnxSuccess(SERVER_ID, USER_ID, ACCOUNT_ID, str_Message));
    return lReturn;    
}


long OTMadeEasy::InterpretTransactionMsgReply(const std::string & SERVER_ID,
                                              const std::string & USER_ID,
                                              const std::string & ACCOUNT_ID,
                                              const std::string & str_Attempt,
                                              const std::string & str_Response)
{
    const long lReturn = static_cast<long>(m_pME->InterpretTransactionMsgReply(SERVER_ID, USER_ID, ACCOUNT_ID, str_Attempt, str_Response));
    return lReturn;    
}








