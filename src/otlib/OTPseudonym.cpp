/************************************************************************************
 *    
 *  OTPseudonym.cpp
 *  
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


#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>
#include <algorithm>

#ifdef _WIN32
#include <WinsockWrapper.h>
#endif

#ifdef _WIN32 // Including this so it'll be above the openssl/ssl.h
//#include <winsock.h> // So there won't be a conflict with WinCrypt.h due to Windows sucking
#endif


extern "C"
{
#include <openssl/crypto.h>
#include <openssl/ssl.h>
	
#include <openssl/sha.h>
	
#include <openssl/pem.h>
#include <openssl/evp.h>
#include <openssl/conf.h>
#include <openssl/x509v3.h>
	
#ifndef OPENSSL_NO_ENGINE
#include <openssl/engine.h>
#endif
	
	int mkcert(X509 **x509p, EVP_PKEY **pkeyp, int bits, int serial, int days);
	int add_ext(X509 *cert, int nid, char *value);
	
}




#include "irrxml/irrXML.h"

using namespace irr;
using namespace io;

#include "OTStorage.h"

#include "OTString.h"
#include "OTStringXML.h"
#include "OTIdentifier.h"

#include "OTPassword.h"

#include "OTAsymmetricKey.h"

#include "OTASCIIArmor.h"
#include "OTPseudonym.h"
#include "OTEnvelope.h"
#include "OTSignedFile.h"
#include "OTItem.h"
#include "OTTransaction.h"
#include "OTLedger.h"
#include "OTMessage.h"

#include "OTLog.h"











//static
OTPseudonym * OTPseudonym::LoadPublicNym(const OTIdentifier & NYM_ID, 
										 OTString * pstrName/*=NULL*/, 
										 const char * szFuncName/*=NULL*/)
{
	const char * szFunc = (NULL != szFuncName) ? szFuncName : "OTPseudonym::LoadPublicNym";
	// ------------------------------------------
	const OTString	strNymID(NYM_ID);
	// ------------------------------------------
	// If name is empty, construct one way, 
	// else construct a different way.
	//
	OTPseudonym * pNym = ((NULL == pstrName) || !pstrName->Exists()) ? 
		(new OTPseudonym(NYM_ID)): 
		(new OTPseudonym(*pstrName, strNymID, strNymID));
	OT_ASSERT_MSG(NULL != pNym, "OTPseudonym::LoadPublicNym: Error allocating memory.\n");
	// ---------------------------
	// First load the public key
	if (false == pNym->LoadPublicKey())
		OTLog::vOutput(1, "OTPseudonym::LoadPublicNym %s: Tried (and failed) to load Nym (%s). (Maybe it's simply not here. "
					   "Often normal, maybe it's a friend's key and I need to download it.)\n", szFunc, strNymID.Get());
	else if (false == pNym->VerifyPseudonym())
		OTLog::vError("OTPseudonym::LoadPublicNym %s: Security: Failure verifying Nym public key after loading it: %s\n", 
					  szFunc, strNymID.Get());
	else if (false == pNym->LoadSignedNymfile(*pNym))
	{
		OTLog::vOutput(1, "OTPseudonym::LoadPublicNym %s: Usually normal: There's no Nymfile (%s), though there IS a public "
					   "key, which checks out. It's probably just someone else's Nym. (So I'm still returning this Nym to "
					   "the caller so he can still use the public key.)\n", szFunc, strNymID.Get());
		return pNym;
	}
	else // success 
		return pNym;
	// -------------------
	delete pNym; pNym = NULL;
	// -------------------
	return NULL;	
}


//static
OTPseudonym * OTPseudonym::LoadPrivateNym(const OTIdentifier & NYM_ID,
										        OTString     * pstrName/*=NULL*/,
										  const char         * szFuncName/*=NULL*/,
                                                OTString     * pstrReason/*=NULL*/)
{	
	const char * szFunc = (NULL != szFuncName) ? szFuncName : "OTPseudonym::LoadPrivateNym";
	// ------------------------------------------
	const OTString	strNymID(NYM_ID);
	// ------------------------------------------
	// If name is empty, construct one way, 
	// else construct a different way.
	//
	OTPseudonym * pNym = ((NULL == pstrName) || !pstrName->Exists()) ? 
		(new OTPseudonym(NYM_ID)): 
		(new OTPseudonym(*pstrName, strNymID, strNymID));
	OT_ASSERT_MSG(NULL != pNym, "OTPseudonym::LoadPrivateNym: Error allocating memory.\n");
	// ---------------------------------
	// Error loading x509CertAndPrivateKey.
	if (false == pNym->Loadx509CertAndPrivateKey(pstrReason))
		OTLog::vError("OTPseudonym::LoadPrivateNym %s: Failure calling Loadx509CertAndPrivateKey: %s\n", 
					  szFunc, strNymID.Get());
	// success loading x509CertAndPrivateKey,
	// failure verifying pseudonym public key.
	else if (false == pNym->VerifyPseudonym())
		OTLog::vError("OTPseudonym::LoadPrivateNym %s: Failure verifying Nym public key: %s\n", 
					  szFunc, strNymID.Get());
	// success verifying pseudonym public key.
	// failure loading signed nymfile.
	else if (false == pNym->LoadSignedNymfile(*pNym)) // Unlike with public key, with private key we DO expect nymfile to be here.
		OTLog::vError("OTPseudonym::LoadPrivateNym %s: Failure calling LoadSignedNymfile: %s\n", 
					  szFunc, strNymID.Get());
	else // ultimate success.
		return pNym;
	// ---------------------------------
	delete pNym; 
	pNym = NULL;
	// ----------
	return NULL;	
}

/*
 The following code is old code from OTWallet, that was previously used for re-signing private Nyms:
 
 //							pNym->LoadSignedNymfile(*pNym); // Uncomment this line to generate a new Nym by hand.
 //							if (true)						// This one too.
 if (pNym->LoadSignedNymfile(*pNym))  // Comment OUT this line to generate a new nym by hand..
 {
 //								pNym->SaveSignedNymfile(*pNym); // Uncomment this if you want to generate a new nym by hand. NORMALLY LEAVE IT COMMENTED OUT!!!! IT'S DANGEROUS!!!
 // Also see OTPseudonym.cpp where it says:  //		&& theNymfile.VerifyFile()

 
 The code where this was has since been moved into the above function (OTPseudonym::LoadPrivateNym),
 so I put this comment here to help me find it, in case I ever need to do a similar thing inside
 OTPseudonym::LoadPrivateNym (above.)
 
 */





/// Though the parameter is a reference (forcing you to pass a real object),
/// the Nym DOES take ownership of the object. Therefore it MUST be allocated
/// on the heap, NOT the stack, or you will corrupt memory with this call.
///
void OTPseudonym::AddMail(OTMessage & theMessage) // a mail message is a form of transaction, transported via Nymbox
{
	m_dequeMail.push_front(&theMessage);
}

/// return the number of mail items available for this Nym.
//
int OTPseudonym::GetMailCount()
{
	return static_cast<int> (m_dequeMail.size());
}

// Look up a piece of mail by index.
// If it is, return a pointer to it, otherwise return NULL.
OTMessage * OTPseudonym::GetMailByIndex(const int nIndex)
{
	const unsigned int uIndex = nIndex;
	
	// Out of bounds.
	if (m_dequeMail.empty()	||
		(nIndex < 0)		|| (uIndex >= m_dequeMail.size()))
		return NULL;
	
	return m_dequeMail.at(nIndex);	
}


bool OTPseudonym::RemoveMailByIndex(const int nIndex) // if false, mail index was bad.
{
	const unsigned int uIndex = nIndex;
	
	// Out of bounds.
	if (m_dequeMail.empty()	||
		(nIndex < 0)		|| (uIndex >= m_dequeMail.size()))
		return false;
	
	// -----------------------
	
	OTMessage * pMessage = m_dequeMail.at(nIndex);
	
	OT_ASSERT(NULL != pMessage);
	
	m_dequeMail.erase(m_dequeMail.begin() + nIndex);
	
	delete pMessage;
	
	return true;		
}


void OTPseudonym::ClearMail()
{
	while (GetMailCount() > 0)
		RemoveMailByIndex(0);
}



// --------------------



/// Though the parameter is a reference (forcing you to pass a real object),
/// the Nym DOES take ownership of the object. Therefore it MUST be allocated
/// on the heap, NOT the stack, or you will corrupt memory with this call.
///
void OTPseudonym::AddOutmail(OTMessage & theMessage) // a mail message is a form of transaction, transported via Nymbox
{
	m_dequeOutmail.push_front(&theMessage);
}

/// return the number of mail items available for this Nym.
//
int OTPseudonym::GetOutmailCount()
{
	return static_cast<int> (m_dequeOutmail.size());
}

// Look up a transaction by transaction number and see if it is in the ledger.
// If it is, return a pointer to it, otherwise return NULL.
OTMessage * OTPseudonym::GetOutmailByIndex(const int nIndex)
{
	const unsigned int uIndex = nIndex;
	
	// Out of bounds.
	if (m_dequeOutmail.empty()	||
		(nIndex < 0)		|| (uIndex >= m_dequeOutmail.size()))
		return NULL;
	
	return m_dequeOutmail.at(nIndex);	
}


bool OTPseudonym::RemoveOutmailByIndex(const int nIndex) // if false, outmail index was bad.
{
	const unsigned int uIndex = nIndex;
	
	// Out of bounds.
	if (m_dequeOutmail.empty()	||
		(nIndex < 0)		|| (uIndex >= m_dequeOutmail.size()))
		return false;
	
	// -----------------------
	
	OTMessage * pMessage = m_dequeOutmail.at(nIndex);
	
	OT_ASSERT(NULL != pMessage);
	
	m_dequeOutmail.erase(m_dequeOutmail.begin() + nIndex);
	
	delete pMessage;
	
	return true;		
}


void OTPseudonym::ClearOutmail()
{
	while (GetOutmailCount() > 0)
		RemoveOutmailByIndex(0);
}



// --------------------



/// Though the parameter is a reference (forcing you to pass a real object),
/// the Nym DOES take ownership of the object. Therefore it MUST be allocated
/// on the heap, NOT the stack, or you will corrupt memory with this call.
///
void OTPseudonym::AddOutpayments(OTMessage & theMessage) // a payments message is a form of transaction, transported via Nymbox
{
	m_dequeOutpayments.push_front(&theMessage);
}

/// return the number of payments items available for this Nym.
//
int OTPseudonym::GetOutpaymentsCount()
{
	return static_cast<int> (m_dequeOutpayments.size());
}

// Look up a transaction by transaction number and see if it is in the ledger.
// If it is, return a pointer to it, otherwise return NULL.
OTMessage * OTPseudonym::GetOutpaymentsByIndex(const int nIndex)
{
	const unsigned int uIndex = nIndex;
	
	// Out of bounds.
	if (m_dequeOutpayments.empty()	||
		(nIndex < 0)		|| (uIndex >= m_dequeOutpayments.size()))
		return NULL;
	
	return m_dequeOutpayments.at(nIndex);	
}


bool OTPseudonym::RemoveOutpaymentsByIndex(const int nIndex) // if false, outpayments index was bad.
{
	const unsigned int uIndex = nIndex;
	
	// Out of bounds.
	if (m_dequeOutpayments.empty()	||
		(nIndex < 0)		|| (uIndex >= m_dequeOutpayments.size()))
		return false;
	
	// -----------------------
	
	OTMessage * pMessage = m_dequeOutpayments.at(nIndex);
	
	OT_ASSERT(NULL != pMessage);
	
	m_dequeOutpayments.erase(m_dequeOutpayments.begin() + nIndex);
	
	delete pMessage;
	
	return true;		
}


void OTPseudonym::ClearOutpayments()
{
	while (GetOutpaymentsCount() > 0)
		RemoveOutpaymentsByIndex(0);
}



// --------------------

// Instead of a "balance statement", some messages require a "transaction statement".
// Whenever the number of transactions changes, you must sign the new list so you
// aren't responsible for cleared transactions, for example. Or so you server will
// allow you to take responsibility for a new transaction number (only if you've 
// signed off on it!)
//
// There will have to be another version of this function for when you don't have
// a transaction (like a processNymbox!) Otherwise you would need a transaction number
// in order to do a processNymbox. This function therefore is available in that incarnation
// even when you don't have a transaction number. It'll just attach the balance item to
// the message directly.
//
OTItem * OTPseudonym::GenerateTransactionStatement(const OTTransaction & theOwner)
{
	if ( (theOwner.GetUserID() != m_nymID) )
	{
		OTLog::Error("Transaction has wrong owner in OTPseudonym::GenerateTransactionStatement (expected to match nym).\n");
		return NULL;
	}
	
	// ---------------------------------------------------------
	
	// theOwner is the depositPaymentPlan, activateSmartContract, or marketOffer that triggered the need for this transaction statement.
	// since it uses up a transaction number, I will be sure to remove that one from my list before signing the list.
	OTItem * pBalanceItem = OTItem::CreateItemFromTransaction(theOwner, OTItem::transactionStatement); // <=== transactionStatement type, with user ID, server ID, transaction ID.
	
	// The above has an ASSERT, so this this will never actually happen.
	if (NULL == pBalanceItem)
		return NULL;
	
	// ---------------------------------------------------------
	
	// COPY THE ISSUED TRANSACTION NUMBERS FROM THE NYM
	
	OTPseudonym theMessageNym;
	
	theMessageNym.HarvestIssuedNumbers(theOwner.GetPurportedServerID(),
                                       *this /*unused in this case, not saving to disk*/, *this, false); // bSave = false;
	
	// ---------------------------------------------------------
    switch (theOwner.GetType()) 
    {
        case OTTransaction::cancelCronItem:
            if (theOwner.GetTransactionNum() > 0)
            {
                theMessageNym.RemoveIssuedNum(theOwner.GetRealServerID(), theOwner.GetTransactionNum());  // a transaction number is being used, and REMOVED from my list of responsibility,
                theMessageNym.RemoveTransactionNum(theOwner.GetRealServerID(), theOwner.GetTransactionNum()); // so I want the new signed list to reflect that number has been REMOVED.
            }
            break;
            
            // Transaction Statements usually only have a transaction number in the case of market offers and
            // payment plans, in which case the number should NOT be removed, and remains in play until
            // final closure from Cron.
        case OTTransaction::marketOffer:
        case OTTransaction::paymentPlan:
        case OTTransaction::smartContract:
        default:
            break;
    }
	// ---------------------------------------------------------
	
	// What about cases where no number is being used? (Such as processNymbox)
	// Perhaps then if this function is even called, it's with a 0-number transaction, in which 
	// case the above Removes probably won't hurt anything.  Todo.
	
	
	OTString	strMessageNym(theMessageNym); // Okay now we have the transaction numbers in this MessageNym string.
	
	pBalanceItem->SetAttachment(strMessageNym);	// <======== This is where the server will read the transaction numbers from (A nym in item.m_ascAttachment)
	
	// ---------------------------------------------------------
	
	pBalanceItem->SignContract(*this); // <=== Sign, save, and return. OTTransactionType needs to weasel in a "date signed" variable.
	pBalanceItem->SaveContract();
	
	return pBalanceItem;	
}

// ---------------------------------

bool OTPseudonym::Savex509CertAndPrivateKeyToString(OTString & strOutput, OTString * pstrReason/*=NULL*/)
{
    const char * szFunc = "OTPseudonym::Savex509CertAndPrivateKeyToString";
    // ---------------------------------------
    X509         * x509        = m_pkeyPublic->GetX509();
	EVP_PKEY     * pPrivateKey = m_pkeyPrivate->GetKeyLowLevel();
    
    if (NULL == x509)
    {
        OTLog::vError("%s: Error: Unexpected NULL x509. (Returning false.)\n", szFunc);
        return false;
    }
    
    if (NULL == pPrivateKey)
    {
        OTLog::vError("%s: Error: Unexpected NULL pPrivateKey. (Returning false.)\n", szFunc);
        return false;
    }
    // ---------------------------------------    
    class _Nym__saveCert_
    {
        BIO	**	m_bio_out_pri;
        BIO	**	m_bio_out_x509;
    public:
        _Nym__saveCert_(BIO	** param_bio_out_pri, 
                        BIO ** param_bio_out_x509) 
        : m_bio_out_pri(param_bio_out_pri), 
        m_bio_out_x509(param_bio_out_x509)
        {
            OT_ASSERT(NULL != m_bio_out_pri);
            OT_ASSERT(NULL != m_bio_out_x509);
            
            *m_bio_out_pri  = BIO_new(BIO_s_mem());
            *m_bio_out_x509 = BIO_new(BIO_s_mem());
        }
        ~_Nym__saveCert_()
        {            
            if (NULL != *m_bio_out_pri)
                BIO_free(*m_bio_out_pri);
            *m_bio_out_pri = NULL;
            m_bio_out_pri  = NULL;
            if (NULL != *m_bio_out_x509)
                BIO_free(*m_bio_out_x509);
            *m_bio_out_x509 = NULL;
            m_bio_out_x509  = NULL;
        }
    };
    // ---------------------------------------
    BIO	*	bio_out_pri  = NULL;
	BIO	*	bio_out_x509 = NULL;
    // ---------------------------------------
    _Nym__saveCert_ theInstance(&bio_out_pri, &bio_out_x509);
    // ---------------------------------------
    OTPasswordData thePWData((NULL != pstrReason) ? pstrReason->Get() : 
                             "OTPseudonym::Savex509CertAndPrivateKeyToString is calling PEM_write_bio_PrivateKey...");
    
	PEM_write_bio_PrivateKey(bio_out_pri, pPrivateKey,  EVP_des_ede3_cbc(), NULL, 0, OTAsymmetricKey::GetPasswordCallback(), &thePWData);
	PEM_write_bio_X509(bio_out_x509, x509);
    // ---------------------------------------
    bool bSuccess = false;
    
	unsigned char buffer_pri [4096] = ""; // todo hardcoded
	unsigned char buffer_x509[8192] = ""; // todo hardcoded
	
	OTString strx509;
	OTString strPrivateKey;
    
	int len = 0;
	
    // todo hardcoded 4080 (see array above.)
    //
	if (0 < (len = BIO_read(bio_out_x509, buffer_x509, 8100))) // returns number of bytes successfully read.
	{
		buffer_x509[len] = '\0';
		
		strx509.Set((const char*)buffer_x509); // todo cast
        
		EVP_PKEY * pPublicKey = X509_get_pubkey(x509); 
		
		if (NULL != pPublicKey)
        {
			m_pkeyPublic->SetKeyAsCopyOf(*pPublicKey, false); // bool bIsPrivateKey=false;
            EVP_PKEY_free(pPublicKey);
            pPublicKey = NULL;
        }
		// else?
        
		// todo hardcoded 4080 (see array above.)
		if (0 < (len = BIO_read(bio_out_pri, buffer_pri, 4080))) // returns number of bytes successfully read.
		{
			buffer_pri[len] = '\0';
			
			strPrivateKey.Set((const char *)buffer_pri); // so I can write this string to file in a sec... todo cast
            
			bSuccess = true;
		}
	}
	// ---------------------------------------
	//
	if (bSuccess)
		strOutput.Format((char*)"%s%s", strPrivateKey.Get(), strx509.Get()); // todo cast.
	
	return bSuccess;
}

// ---------------------------------

bool OTPseudonym::Savex509CertAndPrivateKey(bool       bCreateFile/*=true*/, 
                                            OTString * pstrReason/*=NULL*/)
{
    const char * szFunc = "OTPseudonym::Savex509CertAndPrivateKey";
    // ---------------------------------------
    OTString    strOutput;
    const bool  bSuccess   = this->Savex509CertAndPrivateKeyToString(strOutput, pstrReason);
	// ---------------------------------------
    //	
	// At this point, the Nym's private key is set, and its public key is also set.
	// So the object in memory is good to go.
	// Now we just need to create some files, especially where the keys are stored,
	// since the Nym normally never writes to those files (just reads.)
	//
	if (bSuccess)
	{
        // todo security. Revisit this part during security audit.
        //
		const OTString strFilename("temp.nym"); // todo stop hardcoding. Plus this should select a random number too.
        		
		if (false == OTDB::StorePlainString(strOutput.Get(), OTLog::CertFolder(), strFilename.Get())) // temp.nym
		{
			OTLog::vError("%s: Failure storing new cert for nym: %s\n", szFunc, strFilename.Get());
			return false;
		}
		// ------------------------------------------
		bool bPublic  = false;
		bool bPrivate = false;
		
		bPublic  = m_pkeyPublic-> LoadPublicKeyFromCertFile (OTLog::CertFolder(), strFilename.Get());
		bPrivate = m_pkeyPrivate->LoadPrivateKey            (OTLog::CertFolder(), strFilename.Get(), 
                                                             pstrReason);		
		if (!bPublic)
		{
			OTLog::vError("%s: Although the ascii-armored file (%s) was read, LoadPublicKeyFromCert "
						  "returned false.\n", szFunc, strFilename.Get());
			return false;
		}
		else
		{
			OTLog::vOutput(2, "%s: Successfully loaded public key from Certfile: %s\n", szFunc, strFilename.Get());
		}
		// -----------------
		if (!bPrivate)
		{
			OTLog::vError("%s: Although the ascii-armored file (%s) was read, LoadPrivateKey returned false.\n",
						  szFunc, strFilename.Get());
			return false;
		}
		else
		{
			OTLog::vOutput(2, "%s: Successfully loaded private key from certfile: %s\n", szFunc, strFilename.Get());
		}
		// -----------------------------------------
        
        if (false == this->SetIdentifierByPubkey())
        {
			OTLog::vError("%s: Error calculating Nym ID (as a digest of nym's public key.)\n", szFunc);
			return false;	
        }
        // ---------------------------------------
		const OTString strID(m_nymID);
		// ---------------------------------------
		
        if (bCreateFile &&
            (false == OTDB::StorePlainString(strOutput.Get(), OTLog::CertFolder(), strID.Get()))) // Store as actual Nym ID this time instead of temp.nym
		{
			OTLog::vError("%s: Failure storing cert for new nym: %s\n", szFunc, strID.Get());
			return false;
		}
	}
	
	return bSuccess;
}



// use this to actually generate a new key pair and assorted nym files.
//
bool OTPseudonym::GenerateNym(int nBits/*=1024*/, bool bCreateFile/*=true*/) // By default, it creates the various nym files and certs in local storage. (Pass false when creating a temp Nym, like for OTPurse.)
{
    const char * szFunc = "OTPseudonym::GenerateNym";
    
//	BIO			*	bio_err	=	NULL;
	X509		*	x509	=	NULL;
	EVP_PKEY	*	pNewKey	=	NULL;
	
//	CRYPTO_mem_ctrl(CRYPTO_MEM_CHECK_ON); // memory leak detection. Leaving this for now.
//	bio_err	=	BIO_new_fp(stderr, BIO_NOCLOSE);
	
	// actually generate the things. // TODO THESE PARAMETERS...(mkcert)
	mkcert(&x509, &pNewKey, nBits, 0, 3650); // 3650=10 years. Todo hardcoded.
	// Note: 512 bit key CRASHES
	// 1024 is apparently a minimum requirement, if not an only requirement.
	// Will need to go over just what sorts of keys are involved here... todo.
	
	// ------------------------------------------------------------
	if (NULL == x509)
	{
		OTLog::vError("%s: Failed attempting to generate new x509 cert.\n", szFunc);
        
		if (NULL != pNewKey)
			EVP_PKEY_free(pNewKey);
        
		return false;
	}
	// ---------------------------------------------------------------
	if (NULL == pNewKey)
	{
		OTLog::vError("%s: Failed attempting to generate new private key.\n", szFunc);
		
		if (NULL != x509)
			X509_free(x509);

		return false;
	}
	// ---------------------------------------------------------------
	// Below this point, x509 and pNewKey will need to be cleaned up properly.
    
    
	// --------COMMENT THIS OUT FOR PRODUCTION --------  TODO security
	//                  (Debug only.)
//	RSA_print_fp(stdout, pNewKey->pkey.rsa, 0); // human readable
//	X509_print_fp(stdout, x509); // human readable
	
	// --------COMMENT THIS OUT FOR PRODUCTION --------  TODO security
	//                  (Debug only.)
	// write the private key, then the x509, to stdout.
    
//    OTPasswordData thePWData2("OTPseudonym::GenerateNym is calling PEM_write_PrivateKey...");
//
//	PEM_write_PrivateKey(stdout, pNewKey, EVP_des_ede3_cbc(), NULL, 0, OTAsymmetricKey::GetPasswordCallback(), &thePWData2);
//	PEM_write_X509(stdout, x509);
	
    // ---------------------------------------------------------------    
    // private key itself... might as well keep it loaded for now.
    // (Therefore it's now owned by m_pkeyPrivate, no need to cleanup after this.)
    //
    m_pkeyPrivate->SetKeyAsCopyOf(*pNewKey, true); // bool bIsPrivateKey=true; (Default is false)
    EVP_PKEY_free(pNewKey);
    pNewKey = NULL;
    
    m_pkeyPublic->SetX509(x509); // x509 is now owned by m_pkeyPublic. (No need to free it here.)
    // ---------------------------------------------------------------
    OTString strReason("Creating new Nym.");
    bool bSaved = this->Savex509CertAndPrivateKey(bCreateFile, &strReason);
                    // NOTE: cannot reference x509 and pNewKey below this point, since they
                    // were probably destroyed and re-loaded during Savex509CertAndPrivateKey...
    // ---------------------------------------------------------------
	if (bSaved && bCreateFile)
	{		
        bSaved = this->SaveSignedNymfile(*this); // Now we'll generate the NymFile as well! (bCreateFile will be false for temp Nyms..)
	}
    
    if (bCreateFile && !bSaved)
        OTLog::Error("OTPseudonym::GenerateNym: Failed trying to save new Nym's cert or nymfile.\n");
	
	return bSaved;
}


bool OTPseudonym::SetIdentifierByPubkey()
{
    const char * szFunc = "OTPseudonym::SetIdentifierByPubkey";
    // --------------------------------------------------------------
    const bool bCalculated = GetPublicKey().CalculateID(m_nymID); // OTAsymmetricKey::CalculateID only works with public keys.
    
	if (!bCalculated)
	{
		OTLog::vError("%s: Error calculating Nym ID in OTAsymmetricKey::CalculateID().\n", szFunc);
		return false;	
	}
	
	return true;
}



// If an ID is passed in, that means remove all numbers FOR THAT SERVER ID.
// If passed in, and current map doesn't match, then skip it (continue).

#ifndef CLEAR_MAP_AND_DEQUE
#define CLEAR_MAP_AND_DEQUE(the_map) \
    \
FOR_EACH(mapOfTransNums, the_map) \
{ \
if ((NULL != pstrServerID) && (str_ServerID != it->first)) \
        continue; \
    dequeOfTransNums * pDeque = (it->second); \
    OT_ASSERT(NULL != pDeque); \
    if (!(pDeque->empty())) \
        pDeque->clear(); \
}
#endif // CLEAR_MAP_AND_DEQUE





// Sometimes for testing I need to clear out all the transaction numbers from a nym.
// So I added this method to make such a thing easy to do.
//
void OTPseudonym::RemoveAllNumbers(const OTString * pstrServerID/*=NULL*/, const bool bRemoveHighestNum/*=true*/) // Some callers don't want to wipe the highest num. Some do.
{
	const std::string str_ServerID((NULL != pstrServerID) ? pstrServerID->Get() : "");		

    // --------------------------
    // These use str_ServerID (above)
    //
    CLEAR_MAP_AND_DEQUE(m_mapIssuedNum)
    CLEAR_MAP_AND_DEQUE(m_mapTransNum)
    CLEAR_MAP_AND_DEQUE(m_mapTentativeNum)
    CLEAR_MAP_AND_DEQUE(m_mapAcknowledgedNum)
    
    // ----------------------------
	
    std::list<mapOfHighestNums::iterator> listOfHighestNums;
    std::list<mapOfIdentifiers::iterator> listOfNymboxHash;
    std::list<mapOfIdentifiers::iterator> listOfInboxHash;
    std::list<mapOfIdentifiers::iterator> listOfOutboxHash;
    std::list<mapOfIdentifiers::iterator> listOfRecentHash;
    
	if (bRemoveHighestNum)
	{
		FOR_EACH(mapOfHighestNums, m_mapHighTransNo)
		{
			if ((NULL != pstrServerID) && (str_ServerID != it->first)) // If passed in, and current it doesn't match, then skip it (continue).
				continue;
			
            listOfHighestNums.push_back(it);
//			m_mapHighTransNo.erase(it);		
		}	
	}	
    // ----------------------------
    
    FOR_EACH(mapOfIdentifiers, m_mapNymboxHash)
    {
        if ((NULL != pstrServerID) && (str_ServerID != it->first)) // If passed in, and current it doesn't match, then skip it (continue).
            continue;
        
        listOfNymboxHash.push_back(it);
//      m_mapNymboxHash.erase(it);
    }	
    // ----------------------------
    // This is mapped to acct_id, not server_id.
    // (So we just wipe them all.)
    //
    FOR_EACH(mapOfIdentifiers, m_mapInboxHash)
    {
        listOfInboxHash.push_back(it);
//      m_mapInboxHash.erase(it);
    }	
    // ----------------------------
    // This is mapped to acct_id, not server_id.
    // (So we just wipe them all.)
    //    
    FOR_EACH(mapOfIdentifiers, m_mapOutboxHash)
    {
        listOfOutboxHash.push_back(it);
//      m_mapOutboxHash.erase(it);
    }	
    // ----------------------------
    
    FOR_EACH(mapOfIdentifiers, m_mapRecentHash)
    {
        if ((NULL != pstrServerID) && (str_ServerID != it->first)) // If passed in, and current it doesn't match, then skip it (continue).
            continue;
        
        listOfRecentHash.push_back(it);
//      m_mapRecentHash.erase(it);		
    }
    
    // ----------------------------------------------------------------

    while (listOfHighestNums.size() > 0)
    {
        m_mapHighTransNo.erase(listOfHighestNums.back());
        listOfHighestNums.pop_back();
    }
    while (listOfNymboxHash.size() > 0)
    {
        m_mapNymboxHash.erase(listOfNymboxHash.back());
        listOfNymboxHash.pop_back();
    }
    while (listOfInboxHash.size() > 0)
    {
        m_mapInboxHash.erase(listOfInboxHash.back());
        listOfInboxHash.pop_back();
    }
    while (listOfOutboxHash.size() > 0)
    {
        m_mapOutboxHash.erase(listOfOutboxHash.back());
        listOfOutboxHash.pop_back();
    }
    while (listOfRecentHash.size() > 0)
    {
        m_mapRecentHash.erase(listOfRecentHash.back());
        listOfRecentHash.pop_back();
    }
}




//	OTIdentifier        m_NymboxHash;       // (Server-side) Hash of the Nymbox
//  mapOfIdentifiers    m_mapNymboxHash;    // (Client-side) Hash of Nymbox (OTIdentifier) mapped by ServerID (std::string)


bool OTPseudonym::GetNymboxHashServerSide(const OTIdentifier & theServerID, OTIdentifier & theOutput)    // server-side
{
    if (m_NymboxHash.IsEmpty())
    {
        OTLedger theNymbox(m_nymID, m_nymID, theServerID);
        
        if (theNymbox.LoadNymbox() && theNymbox.CalculateNymboxHash(theOutput))
            return true;
    }
    
    return false;
}


void OTPseudonym::SetNymboxHashServerSide(const OTIdentifier & theInput)    // server-side
{
    m_NymboxHash = theInput;
}



// ---------------------------------------------------------

bool OTPseudonym::GetNymboxHash(const std::string & server_id, OTIdentifier & theOutput) const // client-side
{
    return this->GetHash(m_mapNymboxHash, server_id, theOutput);
}


bool OTPseudonym::SetNymboxHash(const std::string & server_id, const OTIdentifier & theInput) // client-side
{
    return this->SetHash(m_mapNymboxHash, server_id, theInput);
}

// ---------------------------------------------------------

bool OTPseudonym::GetRecentHash(const std::string & server_id, OTIdentifier & theOutput) const // client-side
{
    return this->GetHash(m_mapRecentHash, server_id, theOutput);
}


bool OTPseudonym::SetRecentHash(const std::string & server_id, const OTIdentifier & theInput) // client-side
{
    return this->SetHash(m_mapRecentHash, server_id, theInput);
}


// ---------------------------------------------------------

bool OTPseudonym::GetInboxHash(const std::string & acct_id, OTIdentifier & theOutput) const // client-side
{
    return this->GetHash(m_mapInboxHash, acct_id, theOutput);
}


bool OTPseudonym::SetInboxHash(const std::string & acct_id, const OTIdentifier & theInput) // client-side
{
    return this->SetHash(m_mapInboxHash, acct_id, theInput);
}


// ---------------------------------------------------------

bool OTPseudonym::GetOutboxHash(const std::string & acct_id, OTIdentifier & theOutput) const // client-side
{
    return this->GetHash(m_mapOutboxHash, acct_id, theOutput);
}


bool OTPseudonym::SetOutboxHash(const std::string & acct_id, const OTIdentifier & theInput) // client-side
{
    return this->SetHash(m_mapOutboxHash, acct_id, theInput);
}

// ---------------------------------------------------------

bool OTPseudonym::GetHash(const mapOfIdentifiers & the_map, const std::string & str_id, OTIdentifier & theOutput) const // client-side
{
	bool bRetVal = false; // default is false: "No, I didn't find a hash for that id."
	theOutput.Release();
    
	// The Pseudonym has a map of its recent hashes, one for each server (nymbox) or account (inbox/outbox).
	// For Server Bob, with this Pseudonym, I might have hash lkjsd987345lkj.
	// For but Server Alice, I might have hash 98345jkherkjghdf98gy.
    // (Same Nym, but different hash for each server, as well as inbox/outbox hashes for each asset acct.)
	// 
	// So let's loop through all the hashes I have, and if the ID on the map passed in
	// matches the [server|acct] ID that was passed in, then return TRUE.
    //
	FOR_EACH_CONST(mapOfIdentifiers, the_map)
	{
		if ( str_id == it->first )
		{			
			// The call has succeeded
			bRetVal     = true;
            theOutput   = it->second;
			break;
		}
	}
	
	return bRetVal;    
}

bool OTPseudonym::SetHash(mapOfIdentifiers & the_map, const std::string & str_id, const OTIdentifier & theInput) // client-side
{
    bool bSuccess = false;
    
    mapOfIdentifiers::iterator find_it = the_map.find(str_id);
    
    if (the_map.end() != find_it) // found something for that str_id
	{
        // The call has succeeded
        the_map.erase(find_it);
        the_map[str_id] = theInput;
        bSuccess = true;
	}
	
	// If I didn't find it in the list above (whether the list is empty or not....)
	// that means it does not exist. (So create it.)
    //
	if (!bSuccess)
	{
		the_map[str_id] = theInput;
		bSuccess = true;
	}
//	if (bSuccess)
//	{
//		SaveSignedNymfile(SIGNER_NYM);
//	}
    
    return bSuccess;
}





// ---------------------------------------------------------






void OTPseudonym::RemoveReqNumbers(const OTString * pstrServerID/*=NULL*/)
{
	const std::string str_ServerID((NULL != pstrServerID) ? pstrServerID->Get() : "");		
	
	FOR_EACH(mapOfRequestNums, m_mapRequestNum)
	{
		if ((NULL != pstrServerID) && (str_ServerID != it->first)) // If passed in, and current it doesn't match, then skip it (continue).
			continue;

		m_mapRequestNum.erase(it);		
	}	
}



// You can't go using a Nym at a certain server, if it's not registered there...
// BTW -- if you have never called GetRequest(), then this will wrongly return false!
// But as long as you call getRequest() upon successsful registration (or whenever) this
// function will return an accurate answer after that point, and forever.
//
bool OTPseudonym::IsRegisteredAtServer(const OTString & strServerID)
{
	bool bRetVal		= false; // default is return false: "No, I'm NOT registered at that Server."
	std::string strID	= strServerID.Get();
	
	// The Pseudonym has a map of the request numbers for different servers.
	// For Server Bob, with this Pseudonym, I might be on number 34.
	// For but Server Alice, I might be on number 59.
	// 
	// So let's loop through all the numbers I have, and if the server ID on the map
	// matches the Server ID that was passed in, then return TRUE.
	FOR_EACH(mapOfRequestNums, m_mapRequestNum)
	{
		if ( strID == it->first )
		{			
			// The call has succeeded
			bRetVal = true;
			
			break;
		}
	}
	
	return bRetVal;	
}


// Removes Request Num for specific server
// (Like if Nym has deleted his account on that server...)
// Caller is responsible to save Nym after this.
//
bool OTPseudonym::UnRegisterAtServer(const OTString & strServerID)
{
	bool bRetVal		= false; // default is return false: "No, I'm NOT registered at that Server."
	std::string strID	= strServerID.Get();
	
	// The Pseudonym has a map of the request numbers for different servers.
	// For Server Bob, with this Pseudonym, I might be on number 34.
	// For but Server Alice, I might be on number 59.
	// 
	// So let's loop through all the numbers I have, and if the server ID on the map
	// matches the Server ID that was passed in, then delete that one.
    //
	FOR_EACH(mapOfRequestNums, m_mapRequestNum)
	{
		if ( strID == it->first )
		{			
			// The call has succeeded
			bRetVal = true;
            m_mapRequestNum.erase(it);
			break;
		}
	}
	
	return bRetVal;	
}


// -----------------------------------------------------

#ifndef WIPE_MAP_AND_DEQUE
#define WIPE_MAP_AND_DEQUE(the_map) \
while (!the_map.empty()) \
{ \
    dequeOfTransNums * pDeque = the_map.begin()->second; \
    OT_ASSERT(NULL != pDeque); \
    the_map.erase(the_map.begin()); \
    delete pDeque; pDeque = NULL; \
}
#endif // WIPE_MAP_AND_DEQUE


void OTPseudonym::ReleaseTransactionNumbers()
{
    WIPE_MAP_AND_DEQUE(m_mapTransNum)
    WIPE_MAP_AND_DEQUE(m_mapIssuedNum)
    WIPE_MAP_AND_DEQUE(m_mapTentativeNum)
    WIPE_MAP_AND_DEQUE(m_mapAcknowledgedNum)
}
// -----------------------------------------------------





/*
 ResyncWithServer:
    // ----------------------------------------------------
--	OTIdentifier        m_NymboxHash;       // (Server-side) Hash of the Nymbox
    // ----------------------------------------------------    
--    mapOfIdentifiers    m_mapNymboxHash;    // (Client-side) Hash of latest DOWNLOADED Nymbox (OTIdentifier) mapped by ServerID (std::string)
--    mapOfIdentifiers    m_mapRecentHash;    // (Client-side) Hash of Nymbox according to Server, based on some recent reply. (May be newer...)
    // ----------------------------------------------------
--    mapOfIdentifiers    m_mapInboxHash;  
--    mapOfIdentifiers    m_mapOutboxHash; 
    // ----------------------------------------------------    
--	dequeOfMail		m_dequeMail;	// Any mail messages received by this Nym. (And not yet deleted.)
--	dequeOfMail		m_dequeOutmail;	// Any mail messages sent by this Nym. (And not yet deleted.)
--	dequeOfMail		m_dequeOutpayments;	// Any outoing payments sent by this Nym. (And not yet deleted.) (payments screen.)
    // -----------------------------------------------
--	mapOfRequestNums m_mapRequestNum;	// Whenever this user makes a request to a transaction server
 
**	mapOfTransNums	 m_mapTransNum;	// Each Transaction Request must be accompanied by a fresh transaction #,
**	mapOfTransNums	 m_mapIssuedNum;	// If the server has issued me (1,2,3,4,5) and I have already used 1-3,
**	mapOfTransNums	 m_mapTentativeNum; 
 
**  mapOfHighestNums m_mapHighTransNo;  // Mapped, a single long to each server (just like request numbers are.)
	// -----------------------------
--    mapOfTransNums	m_mapAcknowledgedNum; // request numbers are stored here.
	// -----------------------------
    // (SERVER side)
--    std::set<long> m_setOpenCronItems; // Until these Cron Items are closed out, the server-side Nym keeps a list of them handy.
    // -----------------------------
    // (SERVER side)
    // Using strings here to avoid juggling memory crap.
--    std::set<std::string> m_setAccounts; // A list of asset account IDs. Server side only (client side uses wallet; has multiple servers.)
    // ------------------------------------------
    // (SERVER side.)
--	long	m_lUsageCredits;	// Server-side. The usage credits available for this Nym. Infinite if negative.
 // -----------------------------
 */


/*
 OTPseudonym::RemoveAllNumbers affects (**):  (-- means doesn't affect)
 // ----------------------------------------------------
--	OTIdentifier        m_NymboxHash;       // (Server-side) Hash of the Nymbox
 // ----------------------------------------------------
**    mapOfIdentifiers    m_mapNymboxHash;    // (Client-side) Hash of latest DOWNLOADED Nymbox (OTIdentifier) mapped by ServerID (std::string)
**    mapOfIdentifiers    m_mapRecentHash;    // (Client-side) Hash of Nymbox according to Server, based on some recent reply. (May be newer...)
 // ----------------------------------------------------
**    mapOfIdentifiers    m_mapInboxHash; 
**    mapOfIdentifiers    m_mapOutboxHash;   
 // ----------------------------------------------------
--	dequeOfMail		m_dequeMail;	// Any mail messages received by this Nym. (And not yet deleted.)
--	dequeOfMail		m_dequeOutmail;	// Any mail messages sent by this Nym. (And not yet deleted.)
--	dequeOfMail		m_dequeOutpayments;	// Any outoing payments sent by this Nym. (And not yet deleted.) (payments screen.)
    // -----------------------------------------------
--    mapOfRequestNums m_mapRequestNum;
 
**	mapOfTransNums   m_mapTransNum;
**	mapOfTransNums   m_mapIssuedNum;
**	mapOfTransNums	 m_mapTentativeNum; 

**    mapOfHighestNums m_mapHighTransNo;  // Mapped, a single long to each server (just like request numbers are.)
 // ----------------------------- 
**  mapOfTransNums	 m_mapAcknowledgedNum;  // request nums are stored.
	// -----------------------------
    // (SERVER side)
--    std::set<long> m_setOpenCronItems; // Until these Cron Items are closed out, the server-side Nym keeps a list of them handy.
 // ----------------------------------------------------
    // (SERVER side)
--    std::set<std::string> m_setAccounts; // A list of asset account IDs. Server side only (client side uses wallet; has multiple servers.)
    // ------------------------------------------
    // (SERVER side.)
--	long	m_lUsageCredits;	// Server-side. The usage credits available for this Nym. Infinite if negative.
 // ----------------------------------------------------
 
 
 CLEAR_MAP_AND_DEQUE(m_mapIssuedNum)
 CLEAR_MAP_AND_DEQUE(m_mapTransNum)
 CLEAR_MAP_AND_DEQUE(m_mapTentativeNum)
 CLEAR_MAP_AND_DEQUE(m_mapAcknowledgedNum)
 
 m_mapHighTransNo.erase(listOfHighestNums.back());
 m_mapNymboxHash.erase(listOfNymboxHash.back());
 m_mapRecentHash.erase(listOfRecentHash.back());

*/

// -----------------------------------------------------
//
// ** ResyncWithServer **
//
// Not for normal use! (Since you should never get out of sync with the server in the first place.)
// However, in testing, or if some bug messes up some data, or whatever, and you absolutely need to
// re-sync with a server, and you trust that server not to lie to you, then this function will do the trick.
// NOTE: Before calling this, you need to do a getNymbox() to download the latest Nymbox, and you need to do
// a createUserAccount() to download the server's copy of your Nym. You then need to load that Nymbox from
// local storage, and you need to load the server's message Nym out of the @createUserAccount reply, so that
// you can pass both of those objects into this function, which must assume that those pieces were already done
// just prior to this call.
//
bool OTPseudonym::ResyncWithServer(OTLedger & theNymbox, OTPseudonym & theMessageNym)
{
	bool bSuccess = true;
	
	// --------------------------------------
	const OTIdentifier &	theServerID = theNymbox.GetRealServerID();
	const OTString			strServerID(theServerID);
	const OTString			strNymID(m_nymID);

	const int nIssuedNumCount	= theMessageNym.GetIssuedNumCount(theServerID);
	const int nTransNumCount	= theMessageNym.GetTransactionNumCount(theServerID);

	// --------------------------------------
	// Remove all issued, transaction, and tentative numbers for a specific server ID,
    // as well as all acknowledgedNums, and the highest transaction number for that serverID,
	// from *this nym. Leave our record of the highest trans num received from that server,
	// since we will want to just keep it when re-syncing. (Server doesn't store that anyway.)
	//
	this->RemoveAllNumbers(&strServerID, false); // bRemoveHighestNum=true by default. But in this case, I keep it.
	
	// --------------------------------------
	// Any issued or trans numbers we add to *this from theMessageNym, are also added here so 
	// they can be used to update the "highest number" record (at the bottom of this function.)
	//
	std::set<long> setTransNumbers;  

	// ***************************************************************************
	// Now that *this has no issued or transaction numbers for theServerID, we add
	// them back again from theMessageNym. (So they will match, and be 'N SYNC!!!)
	//
	// Copy the issued and transaction numbers from theMessageNym onto *this.
	// 
	for(int n1 = 0; n1 < nIssuedNumCount; ++n1)
	{
		const long lNum = theMessageNym.GetIssuedNum(theServerID, n1);

		if (false == this->AddIssuedNum(strServerID, lNum))		// Add to list of numbers that haven't been closed yet.
		{
			OTLog::vError("OTPseudonym::ResyncWithServer: Failed trying to add IssuedNum (%ld) onto *this nym: %s, for server: %s\n",
						  lNum, strNymID.Get(), strServerID.Get());
			bSuccess = false;
		}
		else
		{
			setTransNumbers.insert(lNum);
			// ---------------------------
			OTLog::vOutput(1, "OTPseudonym::ResyncWithServer: Added IssuedNum (%ld) onto *this nym: %s, for server: %s \n",
						   lNum, strNymID.Get(), strServerID.Get());
		}		
	}
	// --------------------------------------
	for(int n2 = 0; n2 < nTransNumCount; ++n2)
	{
		const long lNum = theMessageNym.GetTransactionNum(theServerID, n2);
		
		if (false == this->AddTransactionNum(strServerID, lNum))		// Add to list of available-to-use numbers.
		{
			OTLog::vError("OTPseudonym::ResyncWithServer: Failed trying to add TransactionNum (%ld) onto *this nym: %s, for server: %s\n",
						  lNum, strNymID.Get(), strServerID.Get());
			bSuccess = false;
		}
		else
		{
			setTransNumbers.insert(lNum);
			// ---------------------------
			OTLog::vOutput(1, "OTPseudonym::ResyncWithServer: Added TransactionNum (%ld) onto *this nym: %s, for server: %s \n",
						   lNum, strNymID.Get(), strServerID.Get());
		}
	}
	// ***************************************************************************
	// We already cleared all tentative numbers from *this (above in 
	// RemoveAllNumbers). Next, loop through theNymbox and add Tentative numbers 
	// to *this based on each successNotice in the Nymbox. This way, when the notices
    // are processed, they will succeed because the Nym will believe he was expecting them.
	//
	FOR_EACH(mapOfTransactions, theNymbox.GetTransactionMap())
	{
		OTTransaction * pTransaction = (*it).second;
		OT_ASSERT(NULL != pTransaction);		
//		OTString strTransaction(*pTransaction);
//		OTLog::vError("TRANSACTION CONTENTS:\n%s\n", strTransaction.Get());
		
		// (a new; ALREADY just added transaction number.)
		if ((OTTransaction::successNotice != pTransaction->GetType())) // if !successNotice 
			continue;
		// -------------
		const long lNum = pTransaction->GetReferenceToNum(); // successNotice is inRefTo the new transaction # that should be on my tentative list.
		
		if (false == this->AddTentativeNum(strServerID, lNum))		// Add to list of tentatively-being-added numbers.
		{
			OTLog::vError("OTPseudonym::ResyncWithServer: Failed trying to add TentativeNum (%ld) onto *this nym: %s, for server: %s\n",
						  lNum, strNymID.Get(), strServerID.Get());
			bSuccess = false;
		}
		else
			OTLog::vOutput(1, "OTPseudonym::ResyncWithServer: Added TentativeNum (%ld) onto *this nym: %s, for server: %s \n",
						   lNum, strNymID.Get(), strServerID.Get());
		// There's no "else insert to setTransNumbers" here, like the other two blocks above.
		// Why not? Because setTransNumbers is for updating the Highest Trans Num record on this Nym,
		// and the Tentative Numbers aren't figured into that record until AFTER they are accepted
		// from the Nymbox. So I leave them out, since this function is basically setting us up to
		// successfully process the Nymbox, which will then naturally update the highest num record
		// based on the tentatives, as it's removing them from the tentative list and adding them to
		// the "available" transaction list (and issued.)
		
	} // FOR_EACH (Nymbox)
	// ***************************************************************************
	
	const std::string strID	= strServerID.Get();
	
	FOR_EACH_IT(mapOfHighestNums, this->m_mapHighTransNo, it_high_num)
	{
		if ( strID == it_high_num->first )	// We found it!
		{
            // -------------------------
			// See if any numbers on the set are higher, and if so, update the record to match.
			//
			FOR_EACH(std::set<long>, setTransNumbers)
			{
				const long lTransNum = (*it);
				// --------------------------------
				// Grab a copy of the old highest trans number
				const long lOldHighestNumber = m_mapHighTransNo[it_high_num->first];
				// --------------------------------
				if (lTransNum > lOldHighestNumber) // Did we find a bigger one?
				{
					// Then update the Nym's record!
					this->m_mapHighTransNo[it_high_num->first] = lTransNum; 
					OTLog::vOutput(1, "OTPseudonym::ResyncWithServer: Updated HighestNum (%ld) record on *this nym: %s, for server: %s \n",
								   lTransNum, strNymID.Get(), strServerID.Get());	
				}
			}
            // -------------------------
			// We only needed to do this for the one server, so we can break now.
			break;
		}
	}
	// ***************************************************************************
	
	return (this->SaveSignedNymfile(*this) && bSuccess);
}




/*
typedef std::deque<long>							dequeOfTransNums;
typedef std::map<std::string, dequeOfTransNums *>	mapOfTransNums;	
*/


// Verify whether a certain transaction number appears on a certain list.
//
bool OTPseudonym::VerifyGenericNum(mapOfTransNums & THE_MAP, const OTString & strServerID, const long & lTransNum)
{
	std::string strID	= strServerID.Get();
	
	// The Pseudonym has a deque of transaction numbers for each servers.
	// These deques are mapped by Server ID.
	// 
	// So let's loop through all the deques I have, and if the server ID on the map
	// matches the Server ID that was passed in, then find the transaction number on
	// that list, and then return true. Else return false.
	//
	FOR_EACH(mapOfTransNums, THE_MAP)
	{
		// if the ServerID passed in matches the serverID for the current deque
		if ( strID == it->first )
		{
			dequeOfTransNums * pDeque = (it->second);
			OT_ASSERT(NULL != pDeque);
			
			if (!(pDeque->empty())) // there are some numbers for that server ID
			{
				// Let's loop through them and see if the culprit is there
				for (unsigned i = 0; i < pDeque->size(); i++)
				{
					// Found it!
					if (lTransNum == pDeque->at(i))
					{
						return true;
					}
				}
			}
			break;			
		}
	}
	
	return false;	
}

// On the server side: A user has submitted a specific transaction number. 
// Remove it from his file so he can't use it again.
bool OTPseudonym::RemoveGenericNum(mapOfTransNums & THE_MAP, OTPseudonym & SIGNER_NYM, const OTString & strServerID, const long & lTransNum)
{
	bool bRetVal = RemoveGenericNum(THE_MAP, strServerID, lTransNum);
	
	if (bRetVal)
	{
		SaveSignedNymfile(SIGNER_NYM);
	}
	
	return bRetVal;
}

// This function is a little lower level, and doesn't worry about saving. Used internally.
// Returns true IF it successfully finds and removes the number. Otherwise returns false.
//
bool OTPseudonym::RemoveGenericNum(mapOfTransNums & THE_MAP, const OTString & strServerID, const long & lTransNum)
{
	bool bRetVal = false;
	std::string strID	= strServerID.Get();
	
	// The Pseudonym has a deque of transaction numbers for each servers.
	// These deques are mapped by Server ID.
	// 
	// So let's loop through all the deques I have, and if the server ID on the map
	// matches the Server ID that was passed in, then find the transaction number on
	// that list, and then remove it, and return true. Else return false.
	//
	FOR_EACH(mapOfTransNums, THE_MAP)
	{
		// if the ServerID passed in matches the serverID for the current deque
		if ( strID == it->first )
		{
			dequeOfTransNums * pDeque = (it->second);
			
			OT_ASSERT(NULL != pDeque);
			
			if (!(pDeque->empty())) // there are some numbers for that server ID
			{
				// Let's loop through them and see if the culprit is there
				for (unsigned i = 0; i < pDeque->size(); i++)
				{
					// Found it!
					if (lTransNum == pDeque->at(i))
					{
						pDeque->erase(pDeque->begin() + i);
						bRetVal = true;
						break;
					}
				}
			}
			break;			
		}
	}
		
	return bRetVal;
}


// No signer needed for this one, and save is false.
// This version is ONLY for cases where we're not saving inside this function.
bool OTPseudonym::AddGenericNum(mapOfTransNums & THE_MAP, const OTString & strServerID, const long lTransNum) 
{
	bool bSuccessFindingServerID = false, bSuccess = false;
	std::string strID	= strServerID.Get();
	
	// The Pseudonym has a deque of transaction numbers for each server.
	// These deques are mapped by Server ID.
	// 
	// So let's loop through all the deques I have, and if the server ID on the map
	// matches the Server ID that was passed in, then add the transaction number.
	//
	FOR_EACH(mapOfTransNums, THE_MAP)
	{
		// if the ServerID passed in matches the serverID for the current deque
		if ( strID == it->first )
		{
			dequeOfTransNums * pDeque = (it->second);
			OT_ASSERT(NULL != pDeque);
			
			dequeOfTransNums::iterator iiii = std::find(pDeque->begin(), pDeque->end(), lTransNum);
			
			if (iiii == pDeque->end()) // Only add it if it's not already there. No duplicates!
				pDeque->push_front(lTransNum);
			
			bSuccess				= true;
			bSuccessFindingServerID	= true;
			
			break;			
		}
	}
	
	// Apparently there is not yet a deque stored for this specific serverID.
	// Fine. Let's create it then, and then add the transaction num to that new deque.
	if (!bSuccessFindingServerID)
	{
		dequeOfTransNums * pDeque = new dequeOfTransNums;
		
		OT_ASSERT(NULL != pDeque);
		
		THE_MAP[strID] = pDeque;
		pDeque->push_front(lTransNum);
		bSuccess = true;
	}
	
	return bSuccess;	
}


// Returns count of transaction numbers available for a given server.
//
int OTPseudonym::GetGenericNumCount(mapOfTransNums & THE_MAP, const OTIdentifier & theServerID) 
{
	int nReturnValue = 0;
	
	const OTString strServerID(theServerID);
	std::string strID	= strServerID.Get();
	
	dequeOfTransNums * pDeque = NULL;
	
	// The Pseudonym has a deque of transaction numbers for each server.
	// These deques are mapped by Server ID.
	// 
	// So let's loop through all the deques I have, and if the server ID on the map
	// matches the Server ID that was passed in, then we found the right server.
	FOR_EACH(mapOfTransNums, THE_MAP)
	{
		// if the ServerID passed in matches the serverID for the current deque
		if ( strID == it->first )
		{
			pDeque = (it->second);
			OT_ASSERT(NULL != pDeque);

			break;			
		}
	}
	
	// We found the right server, so let's count the transaction numbers
	// that this nym has already stored for it.
	if (NULL != pDeque)
	{		
		nReturnValue = static_cast<int> (pDeque->size());
	}
	
	return nReturnValue;	
}


// by index.
long OTPseudonym::GetGenericNum(mapOfTransNums & THE_MAP, const OTIdentifier & theServerID, int nIndex)
{
	long lRetVal = 0;
	
	const OTString strServerID(theServerID);
	std::string strID	= strServerID.Get();
	
	// The Pseudonym has a deque of numbers for each server.
	// These deques are mapped by Server ID.
	// 
	// So let's loop through all the deques I have, and if the server ID on the
	// maps matches the Server ID that was passed in, then find the number on
	// that list, and then return it.
	//
	FOR_EACH(mapOfTransNums, THE_MAP)
	{
		// if the ServerID passed in matches the serverID for the current deque
		if ( strID == it->first )
		{
			dequeOfTransNums * pDeque = (it->second);
			OT_ASSERT(NULL != pDeque);
			
			if (!(pDeque->empty())) // there are some numbers for that server ID
			{
				// Let's loop through them and see if the culprit is there
				for (unsigned i = 0; i < pDeque->size(); i++)
				{					
					// Found it!
					if ((unsigned)nIndex == i)
					{
						lRetVal = pDeque->at(i); // <==== Got the number here.
						break;
					}
				}
			}
			break;			
		}
	}
	
	return lRetVal;
}

// *************************************************************************************



// by index.
long OTPseudonym::GetTentativeNum(const OTIdentifier & theServerID, int nIndex)
{
	return GetGenericNum(m_mapTentativeNum, theServerID, nIndex);
}

// by index.
long OTPseudonym::GetIssuedNum(const OTIdentifier & theServerID, int nIndex)
{
	return GetGenericNum(m_mapIssuedNum, theServerID, nIndex);
}

// by index.
long OTPseudonym::GetTransactionNum(const OTIdentifier & theServerID, int nIndex)
{
	return GetGenericNum(m_mapTransNum, theServerID, nIndex);
}

// by index.
long OTPseudonym::GetAcknowledgedNum(const OTIdentifier & theServerID, int nIndex)
{
	return GetGenericNum(m_mapAcknowledgedNum, theServerID, nIndex);
}


// ------------------------------------

// TRANSACTION NUM

// On the server side: A user has submitted a specific transaction number. 
// Verify whether he actually has a right to use it.
bool OTPseudonym::VerifyTransactionNum(const OTString & strServerID, const long & lTransNum) // doesn't save
{
	return VerifyGenericNum(m_mapTransNum, strServerID, lTransNum);
}

// On the server side: A user has submitted a specific transaction number. 
// Remove it from his file so he can't use it again.
bool OTPseudonym::RemoveTransactionNum(OTPseudonym & SIGNER_NYM, const OTString & strServerID, const long & lTransNum)  // saves
{
	return RemoveGenericNum(m_mapTransNum, SIGNER_NYM, strServerID, lTransNum);
}

bool OTPseudonym::RemoveTransactionNum(const OTString & strServerID, const long & lTransNum) // doesn't save.
{
	return RemoveGenericNum(m_mapTransNum, strServerID, lTransNum);
}

// Returns count of transaction numbers available for a given server.
//
int OTPseudonym::GetTransactionNumCount(const OTIdentifier & theServerID)  
{
	return GetGenericNumCount(m_mapTransNum, theServerID);
}


// No signer needed for this one, and save is false.
// This version is ONLY for cases where we're not saving inside this function.
bool OTPseudonym::AddTransactionNum(const OTString & strServerID, const long lTransNum)  // doesn't save
{
	return AddGenericNum(m_mapTransNum, strServerID, lTransNum);
}


// ----------------------------------------------------------------------

// ISSUED NUM

// On the server side: A user has submitted a specific transaction number. 
// Verify whether it was issued to him and still awaiting final closing.
bool OTPseudonym::VerifyIssuedNum(const OTString & strServerID, const long & lTransNum)
{
	return VerifyGenericNum(m_mapIssuedNum, strServerID, lTransNum);
}

// On the server side: A user has accepted a specific receipt. 
// Remove it from his file so he's not liable for it anymore.
bool OTPseudonym::RemoveIssuedNum(OTPseudonym & SIGNER_NYM, const OTString & strServerID, const long & lTransNum) // saves
{
	return RemoveGenericNum(m_mapIssuedNum, SIGNER_NYM, strServerID, lTransNum);
}

bool OTPseudonym::RemoveIssuedNum(const OTString & strServerID, const long & lTransNum) // doesn't save
{
	return RemoveGenericNum(m_mapIssuedNum, strServerID, lTransNum);
}


// Returns count of transaction numbers not yet cleared for a given server.
//
int OTPseudonym::GetIssuedNumCount(const OTIdentifier & theServerID) 
{
	return GetGenericNumCount(m_mapIssuedNum, theServerID);
}


// No signer needed for this one, and save is false.
// This version is ONLY for cases where we're not saving inside this function.
bool OTPseudonym::AddIssuedNum(const OTString & strServerID, const long & lTransNum)  // doesn't save.
{
	return AddGenericNum(m_mapIssuedNum, strServerID, lTransNum);
}



// ----------------------------------------------------------------------

// TENTATIVE NUM

// On the server side: A user has submitted a specific transaction number. 
// Verify whether it was issued to him and still awaiting final closing.
bool OTPseudonym::VerifyTentativeNum(const OTString & strServerID, const long & lTransNum)
{
	return VerifyGenericNum(m_mapTentativeNum, strServerID, lTransNum);
}

// On the server side: A user has accepted a specific receipt. 
// Remove it from his file so he's not liable for it anymore.
bool OTPseudonym::RemoveTentativeNum(OTPseudonym & SIGNER_NYM, const OTString & strServerID, const long & lTransNum) // saves
{
	return RemoveGenericNum(m_mapTentativeNum, SIGNER_NYM, strServerID, lTransNum);
}

bool OTPseudonym::RemoveTentativeNum(const OTString & strServerID, const long & lTransNum) // doesn't save
{
	return RemoveGenericNum(m_mapTentativeNum, strServerID, lTransNum);
}


// Returns count of transaction numbers not yet cleared for a given server.
//
int OTPseudonym::GetTentativeNumCount(const OTIdentifier & theServerID) 
{
	return GetGenericNumCount(m_mapTentativeNum, theServerID);
}


// No signer needed for this one, and save is false.
// This version is ONLY for cases where we're not saving inside this function.
bool OTPseudonym::AddTentativeNum(const OTString & strServerID, const long & lTransNum)  // doesn't save.
{
	return AddGenericNum(m_mapTentativeNum, strServerID, lTransNum);
}


// ----------------------------------------------------------------------

// ACKNOWLEDGED NUM

// These are actually used for request numbers, so both sides can determine which
// replies are already acknowledged. Used purely for optimization, to avoid downloading
// a large number of box receipts (specifically the replyNotices.)


// Client side: See if I've already seen the server's reply to a certain request num.
// Server side: See if I've already seen the client's acknowledgment of a reply I sent.
//
bool OTPseudonym::VerifyAcknowledgedNum(const OTString & strServerID, const long & lRequestNum)
{
	return VerifyGenericNum(m_mapAcknowledgedNum, strServerID, lRequestNum);
}

// On client side: server acknowledgment has been spotted in a reply message, so I can remove it from my ack list.
// On server side: client has removed acknowledgment from his list (as evident since its sent with client messages), so server can remove it as well.
//
bool OTPseudonym::RemoveAcknowledgedNum(OTPseudonym & SIGNER_NYM, const OTString & strServerID, const long & lRequestNum) // saves
{
	return RemoveGenericNum(m_mapAcknowledgedNum, SIGNER_NYM, strServerID, lRequestNum);
}

bool OTPseudonym::RemoveAcknowledgedNum(const OTString & strServerID, const long & lRequestNum) // doesn't save
{
	return RemoveGenericNum(m_mapAcknowledgedNum, strServerID, lRequestNum);
}


// Returns count of request numbers that the client has already seen the reply to
// (Or in the case of server-side, the list of request numbers that the client has
// told me he has already seen the reply to.)
//
int OTPseudonym::GetAcknowledgedNumCount(const OTIdentifier & theServerID) 
{
	return GetGenericNumCount(m_mapAcknowledgedNum, theServerID);
}


// No signer needed for this one, and save is false.
// This version is ONLY for cases where we're not saving inside this function.
bool OTPseudonym::AddAcknowledgedNum(const OTString & strServerID, const long & lRequestNum)  // doesn't save.
{
	return AddGenericNum(m_mapAcknowledgedNum, strServerID, lRequestNum);
}



// ----------------------------------------------------------------------


// HIGHER LEVEL...


// Client side: We have received a new trans num from server. Store it.
// Now the server uses this too, for storing these numbers so it can verify them later.
//
bool OTPseudonym::AddTransactionNum(OTPseudonym & SIGNER_NYM, const OTString & strServerID, long lTransNum, bool bSave) // SAVE OR NOT (your choice) High-Level.
{
	bool bSuccess1 = AddTransactionNum(strServerID, lTransNum);	// Add to list of available-to-use, outstanding numbers.
	bool bSuccess2 = AddIssuedNum(strServerID, lTransNum);		// Add to list of numbers that haven't been closed yet.
	// -----------------------------------
	if (bSuccess1 && !bSuccess2)
		RemoveGenericNum(m_mapTransNum, strServerID, lTransNum);
	else if (bSuccess2 && !bSuccess1)
		RemoveGenericNum(m_mapIssuedNum, strServerID, lTransNum);
	// -----------------------------------
	if (bSuccess1 && bSuccess2 && bSave)
		bSave = SaveSignedNymfile(SIGNER_NYM);
	else
		bSave = true; // so the return at the bottom calculates correctly.
	
	return (bSuccess1 && bSuccess2 && bSave);
}

// Client side: We have received a server's successful reply to a processNymbox accepting a specific new transaction number(s).
// Or, if the reply was lost, then we still found out later that the acceptance was successful, since a notice is still dropped
// into the Nymbox. Either way, this function removes the Tentative number, right before calling the above AddTransactionNum()
// in order to make it available for the Nym's use on actual transactions.
//
bool OTPseudonym::RemoveTentativeNum(OTPseudonym & SIGNER_NYM, const OTString & strServerID, const long & lTransNum, bool bSave) // SAVE OR NOT (your choice) High-Level.
{
	bool bSuccess = RemoveTentativeNum(strServerID, lTransNum);		// Remove from list of numbers that haven't been made available for use yet, though they're "tentative"...
	// -----------------------------------
	if (bSuccess && bSave)
		bSave = SaveSignedNymfile(SIGNER_NYM);
	else 
		bSave = true; // so the return at the bottom calculates correctly.
	// -----------------------------------
	return (bSuccess && bSave);
}

// Client side: We have accepted a certain receipt. Remove the transaction number from my list of issued numbers.
// The server uses this too, also for keeping track of issued numbers, and removes them around same time as client.
// (When receipt is accepted.) Also, There is no "RemoveTransactionNum" at this level since GetNextTransactionNum handles that.
//
bool OTPseudonym::RemoveIssuedNum(OTPseudonym & SIGNER_NYM, const OTString & strServerID, const long & lTransNum, bool bSave) // SAVE OR NOT (your choice) High-Level.
{
	bool bSuccess = RemoveIssuedNum(strServerID, lTransNum);		// Remove from list of numbers that haven't been closed yet.
	// -----------------------------------
	if (bSuccess && bSave)
		bSave = SaveSignedNymfile(SIGNER_NYM);
	else 
		bSave = true; // so the return at the bottom calculates correctly.
	// -----------------------------------
	return (bSuccess && bSave);
}


// Client keeps track of server replies it's already seen.
// Server keeps track of these client acknowledgments.
// (Server also removes from Nymbox, any acknowledged message
// that wasn't already on his list based on request num.)
// Server already removes from his list, any number the client
// has removed from his.
// This is all purely for optimization, since it allows us to avoid
// downloading all the box receipts that contain replyNotices.
//
bool OTPseudonym::RemoveAcknowledgedNum(OTPseudonym & SIGNER_NYM, const OTString & strServerID, const long & lRequestNum, bool bSave) // SAVE OR NOT (your choice) High-Level.
{
	bool bSuccess = RemoveAcknowledgedNum(strServerID, lRequestNum);		// Remove from list of acknowledged request numbers.
	// -----------------------------------
	if (bSuccess && bSave)
		bSave = SaveSignedNymfile(SIGNER_NYM);
	else 
		bSave = true; // so the return at the bottom calculates correctly.
	// -----------------------------------
	return (bSuccess && bSave);
}



/// OtherNym is used as container for server to send us new transaction numbers
/// Currently unused. (old) NEW USE:
/// Okay then, new use: This will be the function that does what the below function
/// does (OTPseudonym::HarvestIssuedNumbers), EXCEPT it only adds numbers that
/// aren't on the TENTATIVE list. Also, it will set the new "highest" trans num
/// for the appropriate server, based on the new numbers being harvested.
//
void OTPseudonym::HarvestTransactionNumbers(const OTIdentifier & theServerID, 
                                            OTPseudonym & SIGNER_NYM, 
                                            OTPseudonym & theOtherNym, bool bSave/*=true*/)
{
    const char * szFunc = "OTPseudonym::HarvestTransactionNumbers";
    // --------------------
	long lTransactionNumber = 0;
	
	std::set<long> setInput, setOutputGood, setOutputBad;

	FOR_EACH(mapOfTransNums, theOtherNym.GetMapIssuedNum())
	{	
        std::string	strServerID		= (*it).first;
		dequeOfTransNums * pDeque	= (it->second);
		
        OT_ASSERT(NULL != pDeque);
		
        OTString OTstrServerID = strServerID.c_str();
        const OTIdentifier theTempID(OTstrServerID);
		
		if (!(pDeque->empty()) && (theServerID == theTempID) ) // only for the matching serverID.
		{
			for (unsigned i = 0; i < pDeque->size(); i++)
			{
				lTransactionNumber = pDeque->at(i);
				
				// If number wasn't already on issued list, then add to BOTH lists.
				// Otherwise do nothing (it's already on the issued list, and no longer 
				// valid on the available list--thus shouldn't be re-added there anyway.)
				// 
				if ((true   == VerifyTentativeNum(OTstrServerID, lTransactionNumber)) &&	// If I've actually requested this number and waiting on it...
					(false  == VerifyIssuedNum(OTstrServerID, lTransactionNumber))          // and if it's not already on my issued list...
					)
					setInput.insert(lTransactionNumber);
			}
            break;  // We found it! Might as well break out.
		}
	} // for
	// ----------------------------------
    // Looks like we found some numbers to harvest (tentative numbers we had already been waiting
    // for, yet hadn't processed onto our issued list yet.)
    //
	if (setInput.size() > 0)
	{
		const OTString strServerID(theServerID), strNymID(m_nymID);
        
		long lViolator = this->UpdateHighestNum(SIGNER_NYM, strServerID, setInput, 
                                                setOutputGood, setOutputBad); // bSave=false (saved below already, if necessary)

		// NOTE: Due to the possibility that a server reply could be process twice (due to redundancy
        // for the purposes of preventing syncing issues) then we expect we might get numbers in here
        // that are below our "last highest num" (due to processing the same numbers twice.) Therefore
        // we don't need to assume an error in this case. UpdateHighestNum() is already smart enough to
        // only update based on the good numbers, while ignoring the bad (i.e. already-processed) ones.
        // Thus we really only have a problem if we receive a (-1), which would mean an error occurred.
        // Also, the above call will log an FYI that it is skipping any numbers below the line, so no need
        // to log more in the case of lViolater being >0 but less than the 'last highest number.'
        //
		if ((-1) == lViolator)
			OTLog::vError("%s: ERROR: UpdateHighestNum() returned (-1), which is an error condition. "
                          "(Should never happen.)\nNym ID: %s \n", szFunc, strNymID.Get());
		else
		{
            // We only remove-tentative-num/add-transaction-num for the numbers that were above our 'last highest number'.
            // The contents of setOutputBad are thus ignored for these purposes.
            //
			FOR_EACH(std::set<long>, setOutputGood) 
			{
				const long lNoticeNum = (*it);
                // --------------------------------------
                // We already know it's on the TentativeNum list, since we checked that in the above for loop.
                // We also already know that it's not on the issued list, since we checked that as well.
                // That's why the below calls just ASSUME those things already.
                //
				RemoveTentativeNum(strServerID, lNoticeNum); // doesn't save (but saved below)
				AddTransactionNum(SIGNER_NYM, strServerID, lNoticeNum, false); // bSave = false (but saved below...)
			}
			
            // We save regardless of whether any removals or additions are made, because data was 
            // updated in UpdateHighestNum regardless.
            //
			if (bSave) 
				SaveSignedNymfile(SIGNER_NYM);
		}
	}
}




/// OtherNym is used as container for us to send server list of issued transaction numbers.
//
// The above function is good for accepting new numbers onto my list, numbers that I already
// tried to sign for and are thus waiting in my tentative list. When calling that function,
// I am trying to accept those new numbers (the ones I was expecting already), and NO other
// numbers.
//
// Whereas with the below function, I am adding as "available" all the numbers that I didn't
// already have issued to me, REGARDLESS of tentative status. Why would I do this? Well,
// perhaps a temp nym is being used during some calculations, and I want to copy all the numbers
// over to the temp nym, period, regardless of his tentative list, because he has no tentative
// list, because he's not a nym in the first place.
//
void OTPseudonym::HarvestIssuedNumbers(const OTIdentifier & theServerID,
                                       OTPseudonym & SIGNER_NYM,
                                       OTPseudonym & theOtherNym,
                                       bool bSave/*=false*/)
{
	bool bChangedTheNym = false;
	long lTransactionNumber = 0;
	
	FOR_EACH(mapOfTransNums, theOtherNym.GetMapIssuedNum())
	{	
        std::string	strServerID		= (*it).first;
		dequeOfTransNums * pDeque	= (it->second);
		
        OT_ASSERT(NULL != pDeque);

        OTString OTstrServerID = ((strServerID.size()) > 0 ? strServerID.c_str() : "");
        const OTIdentifier theTempID(OTstrServerID);
		
		if (!(pDeque->empty()) && (theServerID == theTempID) )
		{
			for (unsigned i = 0; i < pDeque->size(); i++)
			{
				lTransactionNumber = pDeque->at(i);
				
				// If number wasn't already on issued list, then add to BOTH lists.
				// Otherwise do nothing (it's already on the issued list, and no longer 
				// valid on the available list--thus shouldn't be re-added there anyway.)
				// 
				if (false == VerifyIssuedNum(OTstrServerID, lTransactionNumber))
                {
					AddTransactionNum(SIGNER_NYM, OTstrServerID, lTransactionNumber, false); // bSave = false (but saved below...)
                    bChangedTheNym = true;
                }
			}
            break;  // We found it! Might as well break out.
		}
	} // for
	
	if (bChangedTheNym && bSave)
	{
		SaveSignedNymfile(SIGNER_NYM);
	}
}



// ---------------------------------------------------------------------------------


/// When a number IS already on my issued list, but NOT on my available list
/// (because I already used it on some transaction) then this function will
/// verify that and then add it BACK to my available list. (Like if the
/// transaction failed and I just want to get my numbers back so I can use
/// them on a different transaction.)
///
bool OTPseudonym::ClawbackTransactionNumber(const OTIdentifier & theServerID,
                                            const long & lTransClawback, // the number being clawed back.
                                            bool bSave/*=false*/, // false because you might call this function 10 times in a loop, and not want to save EVERY iteration.
                                            OTPseudonym * pSIGNER_NYM/*=NULL*/)
{
    if (NULL == pSIGNER_NYM)
        pSIGNER_NYM = this;
    // Below this point, pSIGNER_NYM is definitely a good pointer.
    // -------------------------------
    const OTString strServerID(theServerID);

    // Only re-add the transaction number if it's already on my issued list.
    // (Otherwise, why am I "adding it back again" if I never had it in the
    // first place? Doesn't sound like a real clawback situation in that case.)
    // 
    if (true == VerifyIssuedNum(strServerID, lTransClawback))
    {
        AddTransactionNum(*pSIGNER_NYM, strServerID, lTransClawback, bSave);
        return true;
    }
    // -------------------------------
    return false;
}



// ---------------------------------------------------------------------------------


/// Client side.
/// Get the next available transaction number for the serverID
/// The lTransNum parameter is for the return value.
/// SAVES if successful.
bool OTPseudonym::GetNextTransactionNum(OTPseudonym & SIGNER_NYM, const OTString & strServerID, long &lTransNum,
                                        bool bSave/*=true*/)
{
	bool bRetVal		= false;
	std::string strID	= strServerID.Get();
	
	// The Pseudonym has a deque of transaction numbers for each server.
	// These deques are mapped by Server ID.
	// 
	// So let's loop through all the deques I have, and if the server ID on the map
	// matches the Server ID that was passed in, then send out the transaction  number.
	//
	FOR_EACH(mapOfTransNums, m_mapTransNum)
	{
		// if the ServerID passed in matches the serverID for the current deque
		if ( strID == it->first )
		{
			dequeOfTransNums * pDeque = (it->second);
			OT_ASSERT(NULL != pDeque);
			
			if (!(pDeque->empty()))
			{
				lTransNum = pDeque->front();
				
				pDeque->pop_front();
				
				// The call has succeeded
				bRetVal = true;
			}
			break;			
		}
	}
	
	if (bRetVal && bSave)
	{
		if (false == SaveSignedNymfile(SIGNER_NYM))
            OTLog::Error("Error saving signed NymFile in OTPseudonym::GetNextTransactionNum\n");
	}
    
	return bRetVal;
}








// returns true on success, value goes into lReqNum
// Make sure the Nym is LOADED before you call this,
// otherwise it won't be there to get.
//
bool OTPseudonym::GetHighestNum(const OTString & strServerID, long &lHighestNum)
{		
	bool bRetVal		= false;
	std::string strID	= strServerID.Get();
	
	// The Pseudonym has a map of the highest transaction # it's received from different servers.
	// For Server Bob, with this Pseudonym, I might be on number 34.
	// For but Server Alice, I might be on number 59.
	// 
	// So let's loop through all the numbers I have, and if the server ID on the map
	// matches the Server ID that was passed in, then send out the highest number.
	//
	// Since the transaction number only ever gets bigger, this is a way of preventing
	// the server from EVER tricking us by trying to give us a number that we've
	// already seen before.
	//
	FOR_EACH(mapOfHighestNums, m_mapHighTransNo)
	{
		if ( strID == it->first )
		{
			// Setup return value.
			lHighestNum = (it->second);
			
			// The call has succeeded
			bRetVal = true;
			
			break;
		}
	}
	
	return bRetVal;
}



// Go through setNumbers and make sure none of them is lower than the highest number I already have for this
// server. At the same time, keep a record of the largest one in the set. If successful, that becomes the new
// "highest" number I've ever received that server. Otherwise fail.
// If success, returns 0. If failure, returns the number that caused us to fail (by being lower than the last 
// highest number.) I should NEVER receive a new transaction number that is lower than any I've gotten before.
// They should always only get bigger. UPDATE: Unless I happen to be processing an old receipt twice... (which
// can happen, due to redundancy used for preventing syncing issues, such as Nymbox notices.)
//
long OTPseudonym::UpdateHighestNum(OTPseudonym & SIGNER_NYM,
                                   const OTString & strServerID,
                                   std::set<long> & setNumbers,
                                   std::set<long> & setOutputGood,
                                   std::set<long> & setOutputBad, bool bSave/*=false*/)
{
	bool bSuccess   = false;
	long lReturnVal = 0; // 0 is success.
    
	// First find the highest and lowest numbers out of the new set.
	//
	long lHighestInSet  = 0;
	long lLowestInSet   = 0;
    
	FOR_EACH(std::set<long>, setNumbers)
	{
		const long lSetNum = *it;

		if (lSetNum > lHighestInSet)		lHighestInSet = lSetNum;    // Set lHighestInSet to contain the highest number out of setNumbers (input)
		// ---------------------
		if (0 == lLowestInSet)				lLowestInSet = lSetNum;     // If lLowestInSet is still 0, then set it to the current number (happens first iteration.)
		else if (lSetNum < lLowestInSet)	lLowestInSet = lSetNum;     // If current number is less than lLowestInSet, then set lLowestInSet to current Number.
	}
    
    // By this point, lLowestInSet contains the lowest number in setNumbers,
    // and lHighestInSet contains the highest number in setNumbers.
    // -------------------------------------------------------------------
    //
	// The Pseudonym has a map of the "highest transaction numbers" for different servers.
	// For Server Bob, with this Pseudonym, I might be on number 34.
	// For but Server Alice, I might be on number 59.
	// 
	// So let's loop through all the numbers I have, and if the server ID on the map
	// matches the Server ID that was passed in, then update it there (then break.)
	//
	// Make sure to save the Pseudonym afterwards, so the new numbers are saved.

	std::string strID	= strServerID.Get();
	
	FOR_EACH(mapOfHighestNums, m_mapHighTransNo)
	{
		if ( strID == it->first )
		{
			// We found it!
			// Presumably we ONLY found it because this Nym has been properly loaded first.
			// Good job! Otherwise, the list would have been empty even though the highest number
			// was sitting in the file.
			
			// Grab a copy of the old highest trans number
			const long lOldHighestNumber = m_mapHighTransNo[it->first]; // <=========== The previous "highest number".

			// ----------------------------------------------
            
            FOR_EACH_IT(std::set<long>, setNumbers, it_numbers)
            {
                const long lSetNum = *it_numbers;
                // ------------------------
                // If the current number (this iteration) is less than or equal to the "old highest number" then it's not going to be added twice.
                //
                if (lSetNum <= lOldHighestNumber)
                {
                    OTLog::vOutput(1, "OTPseudonym::UpdateHighestNum: New transaction number is less-than-or-equal-to "
                                   "last known 'highest trans number' record. (Must be seeing the same server reply for a second time, due to a receipt in my Nymbox.) "
                                   "FYI, last known 'highest' number received: %ld (Current 'violator': %ld) Skipping...\n",
                                   lOldHighestNumber, lSetNum);
                    setOutputBad.insert(lSetNum);
                }
                // The number this iteration, as it should be, is higher than any transaction number 
                else // I've ever received before. (Although sometimes old messages will 'echo'.)
                {
                    setOutputGood.insert(lSetNum);
                    
                    const long lCurrentHighestNumber = m_mapHighTransNo[it->first]; // <=========== The current "highest number".

                    if (lCurrentHighestNumber < lSetNum)
                    {
                        OTLog::vOutput(4, "OTPseudonym::UpdateHighestNum: Raising Highest Trans Number from %ld to %ld.\n", 
                                       lOldHighestNumber, lSetNum);
                        m_mapHighTransNo[it->first] = lSetNum;
                    }
                }
            }
			// ----------------------------------------------

			// Here we're making sure that all the numbers in the set are larger than any others
			// that we've had before for the same server (They should only ever get larger.)
			//
//			if (lLowestInSet <= lOldHighestNumber) // ERROR!!! The new numbers should ALWAYS be larger than the previous ones!
			if ((lLowestInSet > 0) && (lLowestInSet <= lOldHighestNumber))  // WARNING! The new numbers should ALWAYS be larger than the previous ones!
                                                                            // UPDATE: Unless we happen to be processing the same receipt for a second time, due to redundancy in the system (for preventing syncing errors.)
				lReturnVal = lLowestInSet;  // We return the violator (otherwise 0 if success).
			// ---------------------------------------------------------------
			// The loop has succeeded in finding the server.
            //
			bSuccess = true;
			break;  // This main FOR_EACH only ever has one active iteration: the one with
                    //  the right server ID. Once we find it, we break (no matter what.)
		}
	} // FOR_EACH
	// -----------------------------------------
    
	// If I didn't find the server in the list above (whether the list is empty or not....)
	// that means it does not exist. So create it.
	
	if (!bSuccess)
	{
		OTLog::vOutput(0, "OTPseudonym::UpdateHighestNum: Creating Highest Transaction Number entry for this server as '%ld'.\n", 
                       lHighestInSet);
		m_mapHighTransNo[strServerID.Get()] = lHighestInSet;
		bSuccess = true;
	}
	// ----------------------------------------
    
	if (bSuccess)
	{
		if (bSave)
			SaveSignedNymfile(SIGNER_NYM);
		// ---------------------------------
        
        
		return lReturnVal; // Defaults to 0 (success) but above, might have been set to "lLowestInSet" (if one was below the mark.)
	}
	
	return -1;  // should never reach this point.
}










// returns true on success, value goes into lReqNum
// Make sure the Nym is LOADED before you call this,
// otherwise it won't be there to get.
// and if the request number needs to be incremented,
// then make sure you call IncrementRequestNum (below)
bool OTPseudonym::GetCurrentRequestNum(const OTString & strServerID, long &lReqNum)
{		
	bool bRetVal		= false;
	std::string strID	= strServerID.Get();
	
	// The Pseudonym has a map of the request numbers for different servers.
	// For Server Bob, with this Pseudonym, I might be on number 34.
	// For but Server Alice, I might be on number 59.
	// 
	// So let's loop through all the numbers I have, and if the server ID on the map
	// matches the Server ID that was passed in, then send out the request number.
	FOR_EACH(mapOfRequestNums, m_mapRequestNum)
	{
		if ( strID == it->first )
		{
			// Setup return value.
			lReqNum = (it->second);
			
			// The call has succeeded
			bRetVal = true;
			
			break;
		}
	}
	
	return bRetVal;
}



// Make SURE you call SavePseudonym after you call this.
// Otherwise it will increment in memory but not in the file.
// In fact, I cannot allow that. I will call SavePseudonym myself.
// Therefore, make SURE you fully LOAD this Pseudonym before you save it.
// You don't want to overwrite what's in that file.
// THEREFORE we need a better database than the filesystem.
// I will research a good, free, secure database (or encrypt everything
// before storing it there) and soon these "load/save" commands will use that
// instead of the filesystem.
void OTPseudonym::IncrementRequestNum(OTPseudonym & SIGNER_NYM, const OTString & strServerID)
{
	bool bSuccess = false;

	// The Pseudonym has a map of the request numbers for different servers.
	// For Server Bob, with this Pseudonym, I might be on number 34.
	// For but Server Alice, I might be on number 59.
	// 
	// So let's loop through all the numbers I have, and if the server ID on the map
	// matches the Server ID that was passed in, then send out the request number and
	// increment it so it will be ready for the next request.
	//
	// Make sure to save the Pseudonym so the new request number is saved.
	std::string strID	= strServerID.Get();
	
	FOR_EACH(mapOfRequestNums, m_mapRequestNum)
	{
		if ( strID == it->first )
		{
			// We found it!
			// Presumably we ONLY found it because this Nym has been properly loaded first.
			// Good job! Otherwise, the list would have been empty even though the request number
			// was sitting in the file.
			
			
			// Grab a copy of the old request number
			long lOldRequestNumber = m_mapRequestNum[it->first];
			
			// Set the new request number to the old one plus one.
			m_mapRequestNum[it->first] = lOldRequestNumber + 1;
			
			// Now we can log BOTH, before and after... // debug here
			OTLog::vOutput(4, "Incremented Request Number from %ld to %ld. Saving...\n", 
					lOldRequestNumber, m_mapRequestNum[it->first]);
//			OTLog::Output(2, "DEBUG REQUESTNUM: first: %s   Second: %ld\n", it->first.c_str(), it->second);
//			OTLog::Output(2, "SAVING PSEUDONYM TO FILE: %s\n", m_strNymfile.Get());

			// The call has succeeded
			bSuccess = true;
			break;
		}
	}
	
	// If I didn't find it in the list above (whether the list is empty or not....)
	// that means it does not exist. So create it.
	
	if (!bSuccess)
	{
		OTLog::Output(0, "Creating Request Number entry as '100'. Saving...\n");
		m_mapRequestNum[strServerID.Get()] = 100;
		bSuccess = true;
	}
	
	
	if (bSuccess)
	{
		SaveSignedNymfile(SIGNER_NYM);
	}
}






// if the server sends us a @getRequest
void OTPseudonym::OnUpdateRequestNum(OTPseudonym & SIGNER_NYM, const OTString & strServerID, long lNewRequestNumber)
{
	bool bSuccess = false;
	
	// The Pseudonym has a map of the request numbers for different servers.
	// For Server Bob, with this Pseudonym, I might be on number 34.
	// For but Server Alice, I might be on number 59.
	// 
	// So let's loop through all the numbers I have, and if the server ID on the map
	// matches the Server ID that was passed in, then send out the request number and
	// increment it so it will be ready for the next request.
	//
	// Make sure to save the Pseudonym so the new request number is saved.
	std::string strID	= strServerID.Get();
	
	FOR_EACH(mapOfRequestNums, m_mapRequestNum)
	{
		if ( strID == it->first )
		{
			// We found it!
			// Presumably we ONLY found it because this Nym has been properly loaded first.
			// Good job! Otherwise, the list would have been empty even though the request number
			// was sitting in the file.
			
			// The call has succeeded
			bSuccess = true;
			
			// Grab a copy of the old request number
			long lOldRequestNumber = m_mapRequestNum[it->first];
			
			// Set the new request number to the old one plus one.
			m_mapRequestNum[it->first] = lNewRequestNumber;
			
			// Now we can log BOTH, before and after...
			OTLog::vOutput(4, "Updated Request Number from %ld to %ld. Saving...\n", 
					lOldRequestNumber, m_mapRequestNum[it->first]);
//			OTLog::Output(2, "DEBUG REQUESTNUM: first: %s   Second: %ld\n", it->first.c_str(), it->second);
//			OTLog::Output(2, "SAVING PSEUDONYM TO FILE: %s\n", m_strNymfile.Get());
			break;
		}
	}
	
	// If I didn't find it in the list above (whether the list is empty or not....)
	// that means it does not exist. So create it.
	
	if (!bSuccess)
	{
		OTLog::vOutput(0, "Creating Request Number entry as '%ld'. Saving...\n", lNewRequestNumber);
		m_mapRequestNum[strServerID.Get()] = lNewRequestNumber;
		bSuccess = true;
	}
	
	
	if (bSuccess)
	{
		SaveSignedNymfile(SIGNER_NYM);
	}
	
}



/*
bool OTPseudonym::VerifyPseudonym()
{
	OTData binCert; // Here's where we'll put the decoded binary content.
	
	// m_ascCert should already contain the ascii-armored text from the 
	// Nym's x509 certificate file. (this happened in LoadPseudonym())
	
	// This function decodes the base64 text into binary OTData...
	bool bSuccessfulDecode = m_ascCert.GetData(binCert); 
	
	if (!bSuccessfulDecode)
	{
		OTLog::Error("Error decoding Certificate!\n");
		return false;
	}
	
	// Next we get a Message Digest of that binary Cert...
	OTIdentifier newID;
	
	bool bSuccessCalculateDigest = newID.CalculateDigest(binCert);
	
	if (!bSuccessCalculateDigest)
	{
		OTLog::Error("Error calculating Certificate digest.\n");
		return false;	
	}
	
	// newID now contains the Hash aka Message Digest aka Fingerprint aka "IDENTIFIER" 
	// of the x.509 certificate (in its binary form). 
	// (Maybe later we'll choose to hash the text form instead.)
	// 
	// Now let's compare that identifier to the one already loaded by the wallet
	// and make sure they MATCH.
	
	if (!(m_nymID == newID))
	{
		OTString str1, str2;
		m_nymID.GetString(str1);
		newID.GetString(str2);
		OTLog::Output(0, "Hashes do NOT match in OTPseudonym::VerifyPseudonym!\n%s\n%s\n",
				str1.Get(), str2.Get());
		return false;
	}
	else {
		OTLog::Output(1, "\nNymID from wallet *SUCCESSFUL* match to "
				"sha256 hash of the Cert.\n"
				"---------------------------------------------------------------\n");
		return true;
	}
}
*/
/*
bool OTPseudonym::GetPublicKey(OTData & thePublicKey)
{
	
}
*/

/*
 // Save this code. It may be possible to send the entire file
 // to the library and just have it processed there. This code
 // reads the file and then we can pass it to such a library.
bool OTPseudonym::LoadPseudonym()
{	
	OTString & filename = m_strFilename;
	
	std::ifstream in(filename.Get(), std::ios::binary);
	
	if (in.fail())
	{
		OTLog::vError("Error opening file in OTPseudonym::LoadPseudonym: %s\n",
			m_strFilename.Get());
		return false;
	}
 
	std::stringstream buffer;
	buffer << in.rdbuf();
	
	std::string contents(buffer.str());

	m_strCertFileContents = contents.c_str();
	
	OTLog::Output(1, "Loaded x.509 Certificate:\n%s\n", m_strCertFileContents.Get());
	
	return true;
}
*/



/*
 <pseudonym name="REDACTED" 
 nymID="0094e344f6f437c55458873218b14651c4f0ecc88fc7b714fa3b98a83fdf8767"
 file="client.pem" />  <!-- ascii-armored x509 certificate -->
 
 <assetType name="Chuck-E-Cheese Tokens" 
 assetTypeID="65e6ecf1a72300dcb41a908246be1b53465e7edc9b14d90656ba845d71ef94b5" 
 contract="test.xml" />
 
 <transactionServer 
 name="transactions.com" 
 serverID="0535d64305fd10ee104bb79a994c5c58e833a1af664a939a49b1fa4a0445d590" 
 contract="transactionscom.xml" />
 
 <assetAccount name="LD Chuck-E-Cheese token side acct" 
 file="LD-side.xml" 
 AccountID="df9834lkjs5jf8" />
 
 <assetAccount name="LD Main Acct" 
 file="LD-main.xml" 
 AccountID="af9834lkjs5jf6" />
 
 <assetAccount name="Kacey Shopping Acct" 
 file="Kacey-main.xml" 
 AccountID="bw9834lkjs5jf6" />
 */


bool OTPseudonym::VerifyPseudonym() const
{
	OTString strPublicKey;
	bool bGotPublicKey = GetPublicKey().GetPublicKey(strPublicKey);
	
	if (!bGotPublicKey)
	{
		OTLog::Error("Error getting public key in OTPseudonym::VerifyPseudonym.\n");
		return false;	
	}
	
	OTIdentifier newID;
	bool bSuccessCalculateDigest = newID.CalculateDigest(strPublicKey);
	
	if (!bSuccessCalculateDigest)
	{
		OTLog::Error("Error calculating pubkey digest.\n");
		return false;	
	}
	
	// newID now contains the Hash aka Message Digest aka Fingerprint aka "IDENTIFIER" 
	// of the public key (in its text form, with escaped bookends.)
	// 
	// Now let's compare that identifier to the one already loaded by the wallet
	// and make sure they MATCH.
	
	if (m_nymID != newID)
	{
		OTString str1(m_nymID), str2(newID);
		OTLog::vError("\nHashes do NOT match in OTPseudonym::VerifyPseudonym!\n%s\n%s\n",
				str1.Get(), str2.Get());
		
		OT_ASSERT(false);// temp remove. debugging.
		
		return false;
	}
	else 
    {
//		OTString str2(newID);
//		OTLog::Output(1, "\nNymID from wallet *SUCCESSFUL* match to hash of Nym\'s public key:\n%s\n"
//				"---------------------------------------------------------------\n", str2.Get());
		return true;
	}
}


bool OTPseudonym::CompareID(const OTPseudonym & RHS) const
{ 
	return RHS.CompareID(m_nymID); 
}



// --------------------------------------------------------------


bool OTPseudonym::SavePseudonymWallet(OTString & strOutput) const
{
	OTString nymID;
	GetIdentifier(nymID);
	
	OTASCIIArmor ascName;
	
	if (m_strName.Exists()) // name is in the clear in memory, and base64 in storage.
	{
		ascName.SetString(m_strName, false); // linebreaks == false
	}

	strOutput.Concatenate("<pseudonym name=\"%s\"\n"
			" nymID=\"%s\" />\n\n",
			ascName.Get(),
			nymID.Get());
	
	return true;
}


bool OTPseudonym::SavePseudonymWallet(std::ofstream & ofs) const
{
	OTString strOutput;
	
	if (SavePseudonymWallet(strOutput))
		ofs << strOutput.Get();
	else
		return false;
	
	return true;
}



/*
bool OTPseudonym::SavePseudonymWallet(FILE * fl) const
{
	if (NULL != fl)
	{
		OTString nymID;
		GetIdentifier(nymID);
		
		fprintf(fl, "<pseudonym name=\"%s\"\n"
				" nymID=\"%s\"\n"
				" file=\"%s\""
				">\n\n",
				m_strName.Get(), nymID.Get(), m_strNymfile.Get());
	}
	else {
		return false;
	}
	
	return true;
}
*/

// -----------------------------------------------------


//
// This function saves the public key to a file.
//
bool OTPseudonym::SavePublicKey(const OTString & strPath) const
{
	const char * szFoldername	= OTLog::PubkeyFolder();
	const char * szFilename	= strPath.Get();
	
	OT_ASSERT(NULL != szFoldername);
	OT_ASSERT(NULL != szFilename);
	
	// By passing in an OTString instead of OTASCIIArmor, it knows to add the bookends
	// ----- BEGIN PUBLIC KEY  etc.  These bookends are necessary for OTASCIIArmor to later
	// read the thing back up into memory again.
	OTString strKey;
	
	if (GetPublicKey().GetPublicKey(strKey, false)) // false means "do not ESCAPE the bookends"
		// Ie we'll get ----------- instead of - ---------
	{
		bool bStored = OTDB::StorePlainString(strKey.Get(), szFoldername, szFilename);

		if (!bStored)
		{
			OTLog::vError("Failure in OTPseudonym::SavePublicKey while saving to storage: %s%s%s\n",
						  szFoldername, OTLog::PathSeparator(), szFilename);
			return false;
		}
	}
	else 
	{
		OTLog::Error("Error in OTPseudonym::SavePublicKey: unable to GetPublicKey from Nym\n");
		return false;
	}
	
	return true;
}


bool OTPseudonym::SavePublicKey(std::ofstream & ofs) const
{
	// By passing in an OTString instead of OTASCIIArmor, it knows to add the bookends
	// ----- BEGIN PUBLIC KEY  etc.  These bookends are necessary for OTASCIIArmor to later
	// read the thing back up into memory again.
	OTString strKey;
	
	if (GetPublicKey().GetPublicKey(strKey, false)) // false means "do not ESCAPE the bookends"
		// Ie we'll get ----------- instead of - ---------
	{
		strKey.WriteToFile(ofs);
	}
	else 
	{
		OTLog::Error("Error in OTPseudonym::SavePublicKey: unable to GetPublicKey from Nym\n");
		return false;
	}
	
	return true;
}

/*
bool OTPseudonym::SavePublicKey(FILE * fl) const
{
	if (NULL != fl)
	{
		// By passing in an OTString instead of OTASCIIArmor, it knows to add the bookends
		// ----- BEGIN PUBLIC KEY  etc.  These bookends are necessary for OTASCIIArmor to later
		// read the thing back up into memory again.
		OTString strKey;
		
		if (GetPublicKey().GetPublicKey(strKey, false)) // false means "do not ESCAPE the bookends"
			// Ie we'll get ----------- instead of - ---------
		{
			strKey.WriteToFile(fl);
		}
		else {
			OTLog::Error("Error in OTPseudonym::SavePublicKey: unable to GetPublicKey from Nym\n");
			return false;
		}
	}
	else {
		return false;
	}
	
	return true;
}
*/

// pstrID is an output parameter.
bool OTPseudonym::Server_PubKeyExists(OTString * pstrID/*=NULL*/) // Only used on server side.
{
	// ------------------------------------
	OTString strID;
    if (NULL == pstrID)
    {
        pstrID = &strID;
    }
    this->GetIdentifier(*pstrID);
	// ------------------------------------
    // Below this point, pstrID is a GOOD pointer, no matter what. (And no need to delete it.)

	return OTDB::Exists(OTLog::PubkeyFolder(), pstrID->Get());
}

// ------------------------------------

// This version is run on the server side, and assumes only a Public Key.
// This code reads up the file, discards the bookends, and saves only the gibberish itself.
bool OTPseudonym::LoadPublicKey()
{	
    const char * szFunc = "OTPseudonym::LoadPublicKey";
    
	OTString strID;
	
	if (false == this->Server_PubKeyExists(&strID)) // strID will contain *this nymID after this call.
	{
		// Code will call this in order to see if there is a PublicKey to be loaded.
		// Therefore I don't want to log a big error here since we expect that sometimes
		// the key won't be there.
		// Therefore I log at level 4, the same level as I log the successful outcome.
        //
		OTLog::vOutput(4, "%s: Failed load: "
                      "Apparently this Nym doesn't exist. (Returning.)\n", szFunc);
		return false;
	}
	// --------------------------------------------------------------------
    const char * szFoldername	= OTLog::PubkeyFolder();
	const char * szFilename		= strID.Get();
	// --------------------------------------------------------------------
	const OTString strFoldername(szFoldername), strFilename(szFilename);
	
	// This loads up the ascii-armored Public Key.
	// On the client side, the entire x509 is stored in the cert folder.
    // (With other Nym's pubkeys stored in pubkey folder.)
	// On the server side, it's just the public key and stored here in pubkey folder.
    //
	const bool bCanLoadKeyFile = OTDB::Exists(szFoldername, szFilename);
	
	// If successful, I load the same file again, but this time using OpenSSL
	if (bCanLoadKeyFile)
	{
		// Unlike above, where I'm merely reading a text file into a memory buffer,
		// this time we are actually trying to use OpenSSL to really extract the
		// public key from that same file.
		OTAsymmetricKey & pubKey = (OTAsymmetricKey &)GetPublicKey(); // todo cast.
		
		bool bLoadPublicKey = pubKey.LoadPublicKey(strFoldername, strFilename);
		
		if (!bLoadPublicKey)
		{
			OTLog::vError("%s: Although the ascii-armored file (%s%s%s) was read, LoadPublicKey "
						  "returned false.\n", szFunc, szFoldername, OTLog::PathSeparator(), szFilename);
			return false;
		}
		else
		{
			OTLog::vOutput(4, "%s: Successfully loaded public key from file: %s%s%s\n", 
						   szFunc, szFoldername, OTLog::PathSeparator(), szFilename);
		}		
		return true;	
	}

	OTLog::vOutput(2, "%s: Failure.\n", szFunc);
	return false;
}





// DISPLAY STATISTICS

void OTPseudonym::DisplayStatistics(OTString & strOutput)
{	
	strOutput.Concatenate("==>      Name: %s   %s\n", m_strName.Get(),
                          m_bMarkForDeletion ? "(MARKED FOR DELETION)" : "");
	strOutput.Concatenate("      Version: %s\n", m_strVersion.Get());
	strOutput.Concatenate("Usage Credits: %ld\n", m_lUsageCredits);
    
    strOutput.Concatenate("       Mail count: %d\n", m_dequeMail.size());
	strOutput.Concatenate("    Outmail count: %d\n", m_dequeOutmail.size());
	strOutput.Concatenate("Outpayments count: %d\n", m_dequeOutpayments.size());
    
	OTString theStringID;
	GetIdentifier(theStringID);
	strOutput.Concatenate("Nym (aka User) ID: %s\n", theStringID.Get());
	
	FOR_EACH(mapOfRequestNums, m_mapRequestNum)
	{
		std::string strServerID	= it->first;
		long lRequestNumber		= it->second;
		
		// Now we can log BOTH, before and after...
		strOutput.Concatenate("Request Number is %ld for server ID: %s\n", 
                              lRequestNumber, strServerID.c_str());
	}    
    // -------------------------------------
    
    FOR_EACH(mapOfHighestNums, m_mapHighTransNo)
    {	
        std::string	strServerID = (*it).first;
        const long lHighestNum  = (*it).second;
        
        strOutput.Concatenate("Highest trans# ever received was %ld for server: %s\n",
                              lHighestNum, strServerID.c_str());
    }
    
	FOR_EACH(mapOfTransNums, m_mapIssuedNum)
	{	
		std::string strServerID		= (*it).first;
		dequeOfTransNums * pDeque	= (it->second);
		
		OT_ASSERT(NULL != pDeque);
		
		if (!(pDeque->empty()))
		{
			for (unsigned i = 0; i < pDeque->size(); i++)
			{
				long lTransactionNumber = pDeque->at(i);
				
				strOutput.Concatenate("Signed for Transaction# %ld for server ID: %s\n", 
									  lTransactionNumber, strServerID.c_str());
			}
		}
	} // for
	
	FOR_EACH(mapOfTransNums, m_mapTransNum)
	{	
		std::string strServerID		= (*it).first;
		dequeOfTransNums * pDeque	= (it->second);
		
		OT_ASSERT(NULL != pDeque);
		
		if (!(pDeque->empty()))
		{
			for (unsigned i = 0; i < pDeque->size(); i++)
			{
				long lTransactionNumber = pDeque->at(i);
				
				strOutput.Concatenate("Transaction# %ld still usable for server ID: %s\n", 
									  lTransactionNumber, strServerID.c_str());
			}
		}
	} // for
	
	FOR_EACH(mapOfTransNums, m_mapAcknowledgedNum)
	{	
		std::string strServerID		= (*it).first;
		dequeOfTransNums * pDeque	= (it->second);
		
		OT_ASSERT(NULL != pDeque);
		
		if (!(pDeque->empty()))
		{
			for (unsigned i = 0; i < pDeque->size(); i++)
			{
				long lRequestNumber = pDeque->at(i);
				
				strOutput.Concatenate("Server reply to Request# %ld has already been received: %s\n", 
									  lRequestNumber, strServerID.c_str());
			}
		}
	} // for
}





bool OTPseudonym::SavePseudonym() 
{
	if (!m_strNymfile.GetLength())
	{
		OTString nymID;
		GetIdentifier(nymID);
		m_strNymfile.Format("%s", nymID.Get());
	}
	
	OTLog::vOutput(2, "Saving nym to: %s%s%s\n", 
				   OTLog::NymFolder(), OTLog::PathSeparator(), m_strNymfile.Get());
	
	return SavePseudonym(OTLog::NymFolder(), m_strNymfile.Get());
}



bool OTPseudonym::SavePseudonym(const char * szFoldername, const char * szFilename)
{	
	OT_ASSERT(NULL != szFoldername);
	OT_ASSERT(NULL != szFilename);
	
	OTString strNym;
	SavePseudonym(strNym);

	// -------------------------------------
	
	bool bSaved = OTDB::StorePlainString(strNym.Get(), szFoldername, szFilename);
	
	if (!bSaved)
		OTLog::vError("OTPseudonym::SavePseudonym: Error saving file: %s%s%s\n", 
					  szFoldername, OTLog::PathSeparator(), szFilename);

		// --------------------------------------------------------------------

	return bSaved;	
}



bool OTPseudonym::SavePseudonym(std::ofstream & ofs)
{
	OTString strNym;
	SavePseudonym(strNym);
		
	ofs << strNym.Get();
	
	return true;
}


// Save the Pseudonym to a string...
bool OTPseudonym::SavePseudonym(OTString & strNym)
{
	OTString nymID;
	GetIdentifier(nymID);
	
	strNym.Concatenate("<?xml version=\"%s\"?>\n\n", "1.0");	
	
	if (m_lUsageCredits == 0)
		strNym.Concatenate("<OTuser version=\"%s\"\n"
						   " nymID=\"%s\""
						   ">\n\n", 
						   m_strVersion.Get(), 
						   nymID.Get()
						   );
	else
		strNym.Concatenate("<OTuser version=\"%s\"\n"
						   " nymID=\"%s\"\n"
						   " usageCredits=\"%ld\""
						   ">\n\n", 
						   m_strVersion.Get(), 
						   nymID.Get(),
						   m_lUsageCredits
						   );
	
	// -------------------------------------

	long	lRequestNum;
	
	FOR_EACH(mapOfRequestNums, m_mapRequestNum)
	{	
		std::string	strServerID = (*it).first;
		lRequestNum = (*it).second;
		
		strNym.Concatenate("<requestNum\n"
						   " serverID=\"%s\"\n"
						   " currentRequestNum=\"%ld\""
						   "/>\n\n", 
						   strServerID.c_str(),
						   lRequestNum
						   );
	}
	
	// -------------------------------------
	long	lHighestNum;
	
	FOR_EACH(mapOfHighestNums, m_mapHighTransNo)
	{	
		std::string	strServerID = (*it).first;
		lHighestNum = (*it).second;
		
		strNym.Concatenate("<highestTransNum\n"
						   " serverID=\"%s\"\n"
						   " mostRecent=\"%ld\""
						   "/>\n\n", 
						   strServerID.c_str(),
						   lHighestNum
						   );
	}
	
	// -------------------------------------
    // When you delete a Nym, it just marks it.
    // Actual deletion occurs during maintenance sweep (targeting marked nyms...)
    //
    if (m_bMarkForDeletion)
        strNym.Concatenate("<MARKED_FOR_DELETION>\n"
                           "%s</MARKED_FOR_DELETION>\n\n", 
                           "THIS NYM HAS BEEN MARKED FOR DELETION AT ITS OWN REQUEST");

	// -------------------------------------
	
	long lTransactionNumber = 0;
	
	FOR_EACH(mapOfTransNums, m_mapTransNum)
	{	
		std::string	strServerID		= (*it).first;
		dequeOfTransNums * pDeque	= (it->second);
		
		OT_ASSERT(NULL != pDeque);
		
//		if (!(pDeque->empty()) && (strServerID.size() > 0) )
//		{
//			for (unsigned i = 0; i < pDeque->size(); i++)
//			{
//				lTransactionNumber = pDeque->at(i);
//				
//				strNym.Concatenate("<transactionNum\n"
//								   " serverID=\"%s\"\n"
//								   " transactionNum=\"%ld\""
//								   "/>\n\n", 
//								   strServerID.c_str(),
//								   lTransactionNumber
//								   );
//			}
//		}
        
		if (!(pDeque->empty()) && (strServerID.size() > 0) )
		{
            OTNumList theList;
            
			for (unsigned i = 0; i < pDeque->size(); i++)
			{
				lTransactionNumber = pDeque->at(i);
                theList.Add(lTransactionNumber);
			}
            OTString strTemp;
            if ((theList.Count() > 0) && theList.Output(strTemp) && strTemp.Exists())
            {
                const OTASCIIArmor ascTemp(strTemp);
                
                if (ascTemp.Exists())
                    strNym.Concatenate("<transactionNums serverID=\"%s\">\n%s</transactionNums>\n\n",
                                       strServerID.c_str(), ascTemp.Get());
            }
		}
	} // for
	
	// -------------------------------------
	
	lTransactionNumber = 0;
	
	FOR_EACH(mapOfTransNums, m_mapIssuedNum)
	{	
		std::string	strServerID		= (*it).first;
		dequeOfTransNums * pDeque	= (it->second);
		
		OT_ASSERT(NULL != pDeque);
		
//		if (!(pDeque->empty()) && (strServerID.size() > 0) )
//		{
//			for (unsigned i = 0; i < pDeque->size(); i++)
//			{
//				lTransactionNumber = pDeque->at(i);
//				
//				strNym.Concatenate("<issuedNum\n"
//								   " serverID=\"%s\"\n"
//								   " transactionNum=\"%ld\""
//								   "/>\n\n", 
//								   strServerID.c_str(),
//								   lTransactionNumber
//								   );
//			}
//		}
        
        if (!(pDeque->empty()) && (strServerID.size() > 0) )
		{
            OTNumList theList;
            
			for (unsigned i = 0; i < pDeque->size(); i++)
			{
				lTransactionNumber = pDeque->at(i);
                theList.Add(lTransactionNumber);
			}
            OTString strTemp;
            if ((theList.Count() > 0) && theList.Output(strTemp) && strTemp.Exists())
            {
                const OTASCIIArmor ascTemp(strTemp);
                
                if (ascTemp.Exists())
                    strNym.Concatenate("<issuedNums serverID=\"%s\">\n%s</issuedNums>\n\n",
                                       strServerID.c_str(), ascTemp.Get());
            }
		}
	} // for
	
	// -------------------------------------
	
	lTransactionNumber = 0;
	
	FOR_EACH(mapOfTransNums, m_mapTentativeNum)
	{	
		std::string	strServerID		= (*it).first;
		dequeOfTransNums * pDeque	= (it->second);
		
		OT_ASSERT(NULL != pDeque);
		
//		if (!(pDeque->empty()) && (strServerID.size() > 0) )
//		{
//			for (unsigned i = 0; i < pDeque->size(); i++)
//			{
//				lTransactionNumber = pDeque->at(i);
//				
//				strNym.Concatenate("<tentativeNum\n"
//								   " serverID=\"%s\"\n"
//								   " transactionNum=\"%ld\""
//								   "/>\n\n", 
//								   strServerID.c_str(),
//								   lTransactionNumber
//								   );
//			}
//		}
        
        if (!(pDeque->empty()) && (strServerID.size() > 0) )
		{
            OTNumList theList;
            
			for (unsigned i = 0; i < pDeque->size(); i++)
			{
				lTransactionNumber = pDeque->at(i);
                theList.Add(lTransactionNumber);
			}
            OTString strTemp;
            if ((theList.Count() > 0) && theList.Output(strTemp) && strTemp.Exists())
            {
                const OTASCIIArmor ascTemp(strTemp);
                
                if (ascTemp.Exists())
                    strNym.Concatenate("<tentativeNums serverID=\"%s\">\n%s</tentativeNums>\n\n",
                                       strServerID.c_str(), ascTemp.Get());
            }
		}

	} // for
	
	// -------------------------------------
	
    // although mapOfTransNums is used, in this case,
    // request numbers are what is actually being stored.
    // The data structure just happened to be appropriate 
    // in this case, with generic manipulation functions
    // already written, so I used that pre-existing system.
    //
	FOR_EACH(mapOfTransNums, m_mapAcknowledgedNum)
	{	
		std::string	strServerID		= (*it).first;
		dequeOfTransNums * pDeque	= (it->second);
		
		OT_ASSERT(NULL != pDeque);
		
//		if (!(pDeque->empty()) && (strServerID.size() > 0) )
//		{
//			for (unsigned i = 0; i < pDeque->size(); i++)
//			{
//				const long lRequestNumber = pDeque->at(i);
//				
//				strNym.Concatenate("<acknowledgedNum\n"
//								   " serverID=\"%s\"\n"
//								   " requestNum=\"%ld\""
//								   "/>\n\n", 
//								   strServerID.c_str(),
//								   lRequestNumber
//								   );
//			}
//		}
        
        if (!(pDeque->empty()) && (strServerID.size() > 0) )
		{
            OTNumList theList;
            
			for (unsigned i = 0; i < pDeque->size(); i++)
			{
                const long lRequestNumber = pDeque->at(i);
                theList.Add(lRequestNumber);
			}
            OTString strTemp;
            if ((theList.Count() > 0) && theList.Output(strTemp) && strTemp.Exists())
            {
                const OTASCIIArmor ascTemp(strTemp);
                
                if (ascTemp.Exists())
                    strNym.Concatenate("<ackNums serverID=\"%s\">\n%s</ackNums>\n\n",
                                       strServerID.c_str(), ascTemp.Get());
            }
		}

	} // for
	
	// -------------------------------------
	
	if (!(m_dequeMail.empty()))
	{
		for (unsigned i = 0; i < m_dequeMail.size(); i++)
		{
			OTMessage * pMessage = m_dequeMail.at(i);
			OT_ASSERT(NULL != pMessage);
			
			OTString strMail(*pMessage);
			
			OTASCIIArmor ascMail;
			
			if (strMail.Exists())
				ascMail.SetString(strMail);
			
			if (ascMail.Exists())
				strNym.Concatenate("<mailMessage>\n"
								   "%s</mailMessage>\n\n", 
								   ascMail.Get());
		} 
	}
	
	// -------------------------------------
	
	
	if (!(m_dequeOutmail.empty()))
	{
		for (unsigned i = 0; i < m_dequeOutmail.size(); i++)
		{
			OTMessage * pMessage = m_dequeOutmail.at(i);
			OT_ASSERT(NULL != pMessage);
			
			OTString strOutmail(*pMessage);
			
			OTASCIIArmor ascOutmail;
			
			if (strOutmail.Exists())
				ascOutmail.SetString(strOutmail);
			
			if (ascOutmail.Exists())
				strNym.Concatenate("<outmailMessage>\n"
								   "%s</outmailMessage>\n\n", 
								   ascOutmail.Get());
		} 
	}
	
	// -------------------------------------
	
	if (!(m_dequeOutpayments.empty()))
	{
		for (unsigned i = 0; i < m_dequeOutpayments.size(); i++)
		{
			OTMessage * pMessage = m_dequeOutpayments.at(i);
			OT_ASSERT(NULL != pMessage);
			
			OTString strOutpayments(*pMessage);
			
			OTASCIIArmor ascOutpayments;
			
			if (strOutpayments.Exists())
				ascOutpayments.SetString(strOutpayments);
			
			if (ascOutpayments.Exists())
				strNym.Concatenate("<outpaymentsMessage>\n"
								   "%s</outpaymentsMessage>\n\n", 
								   ascOutpayments.Get());
		} 
	}
	
	// -------------------------------------
    // These are used on the server side.
    // (That's why you don't see the server ID saved here.)
    //
	if (!(m_setOpenCronItems.empty()))
	{
		FOR_EACH(std::set<long>, m_setOpenCronItems)
		{
            long lCronItemTransNum = *it;
            
            strNym.Concatenate("<hasOpenCronItem ID=\"%ld\" />\n\n",
                               lCronItemTransNum);
		} 
	}
	
	// -------------------------------------
    // These are used on the server side.
    // (That's why you don't see the server ID saved here.)
    //
	if (!(m_setAccounts.empty()))
	{
		FOR_EACH(std::set<std::string>, m_setAccounts)
		{
            std::string strAcctID = *it;
                        
            strNym.Concatenate("<ownsAssetAcct ID=\"%s\" />\n\n",
                               strAcctID.c_str());
		} 
	}
	
	// -------------------------------------
    // client-side
	FOR_EACH(mapOfIdentifiers, m_mapNymboxHash)
	{	
		std::string	strServerID		= (*it).first;
        OTIdentifier & theID        = (*it).second;
        
		if ( (strServerID.size() > 0) && !theID.IsEmpty())
		{
            const OTString strNymboxHash(theID);
            strNym.Concatenate("<nymboxHashItem\n"
                               " serverID=\"%s\"\n"
                               " nymboxHash=\"%s\""
                               "/>\n\n", 
                               strServerID.c_str(),
                               strNymboxHash.Get());
		}
	} // for
    
	// -------------------------------------
    // client-side
	FOR_EACH(mapOfIdentifiers, m_mapRecentHash)
	{	
		std::string	strServerID		= (*it).first;
        OTIdentifier & theID        = (*it).second;
        
		if ( (strServerID.size() > 0) && !theID.IsEmpty())
		{
            const OTString strRecentHash(theID);
            strNym.Concatenate("<recentHashItem\n"
                               " serverID=\"%s\"\n"
                               " recentHash=\"%s\""
                               "/>\n\n", 
                               strServerID.c_str(),
                               strRecentHash.Get());
		}
	} // for
    
	// -------------------------------------
    // server-side
    if (!m_NymboxHash.IsEmpty())
    {
        const OTString strNymboxHash(m_NymboxHash);
        strNym.Concatenate("<nymboxHash\n"
                           " value=\"%s\""
                           "/>\n\n", 
                           strNymboxHash.Get());
    }
	
	// -------------------------------------
	
    // -------------------------------------
    // client-side
	FOR_EACH(mapOfIdentifiers, m_mapInboxHash)
	{	
		std::string	strAcctID		= (*it).first;
        OTIdentifier & theID        = (*it).second;
        
		if ( (strAcctID.size() > 0) && !theID.IsEmpty())
		{
            const OTString strHash(theID);
            strNym.Concatenate("<inboxHashItem\n"
                               " accountID=\"%s\"\n"
                               " hashValue=\"%s\""
                               "/>\n\n", 
                               strAcctID.c_str(),
                               strHash.Get());
		}
	} // for
    
	// -------------------------------------
    // client-side
	FOR_EACH(mapOfIdentifiers, m_mapOutboxHash)
	{	
		std::string	strAcctID		= (*it).first;
        OTIdentifier & theID        = (*it).second;
        
		if ( (strAcctID.size() > 0) && !theID.IsEmpty())
		{
            const OTString strHash(theID);
            strNym.Concatenate("<outboxHashItem\n"
                               " accountID=\"%s\"\n"
                               " hashValue=\"%s\""
                               "/>\n\n", 
                               strAcctID.c_str(),
                               strHash.Get());
		}
	} // for
    
	// -------------------------------------
	
	strNym.Concatenate("</OTuser>\n");	
	
	return true;
	
}



// --------------------------------------------------------------



//std::set<long> m_setOpenCronItems; // Until these Cron Items are closed out, the server-side Nym keeps a list of them handy.

//std::set<std::string> m_setAccounts; // A list of asset account IDs. Server side only (client side uses wallet; has multiple servers.)


/*
 
 Enumeration for all xml nodes which are parsed by IrrXMLReader.
 
 Enumeration values:
 
 EXN_NONE			No xml node. This is usually the node if you did not read anything yet.
 EXN_ELEMENT		A xml element, like <foo>.
 EXN_ELEMENT_END	End of an xml element, like </foo>.
 EXN_TEXT			Text within a xml element: <foo> this is the text. </foo>.
 EXN_COMMENT		An xml comment like <!-- I am a comment --> or a DTD definition.
 EXN_CDATA			An xml cdata section like <![CDATA[ this is some CDATA ]]>.
 EXN_UNKNOWN		Unknown element.
 
 Definition at line 180 of file irrXML.h.
 
 */
bool OTPseudonym::LoadFromString(const OTString & strNym) // todo optimize
{
	bool bSuccess = false;

    m_setOpenCronItems.clear();
    m_setAccounts.clear(); 

    // ------------------------------------
    
	OTStringXML strNymXML(strNym); // todo optimize
	IrrXMLReader* xml = createIrrXMLReader(&strNymXML);
	OT_ASSERT(NULL != xml);
	OTCleanup<IrrXMLReader> theCleanup(*xml);
    
	// parse the file until end reached
	while(xml && xml->read())
	{
        
//        switch(xml->getNodeType())
//        {
//            case(EXN_NONE):
//                OTLog::Error("ACK NUMS: EXN_NONE --  No xml node. This is usually the node if you did not read anything yet.\n");
//                break;
//            case(EXN_ELEMENT):
//                OTLog::Error("ACK NUMS: EXN_ELEMENT -- An xml element such as <foo>.\n");
//                break;
//            case(EXN_ELEMENT_END):
//                OTLog::Error("ACK NUMS: EXN_ELEMENT_END -- End of an xml element such as </foo>.\n");
//                break;
//            case(EXN_TEXT):
//                OTLog::Error("ACK NUMS: EXN_TEXT -- Text within an xml element: <foo> this is the text. <foo>.\n");
//                break;
//            case(EXN_COMMENT):
//                OTLog::Error("ACK NUMS: EXN_COMMENT -- An xml comment like <!-- I am a comment --> or a DTD definition.\n");
//                break;
//            case(EXN_CDATA):
//                OTLog::Error("ACK NUMS: EXN_CDATA -- An xml cdata section like <![CDATA[ this is some CDATA ]]>.\n");
//                break;
//            case(EXN_UNKNOWN):
//                OTLog::Error("ACK NUMS: EXN_UNKNOWN -- Unknown element.\n");
//                break;
//            default:
//                OTLog::Error("ACK NUMS: default!! -- SHOULD NEVER HAPPEN...\n");
//                break;
//        }
//        OTLog::vError("OTPseudonym::LoadFromString: NODE DATA: %s\n", xml->getNodeData());

        
        
		// strings for storing the data that we want to read out of the file		
        //
		switch(xml->getNodeType())
		{
			case EXN_NONE:
			case EXN_TEXT:
			case EXN_COMMENT:
			case EXN_ELEMENT_END:
			case EXN_CDATA:
				// in this xml file, the only text which occurs is the messageText
				//messageText = xml->getNodeData();
                
//            switch(xml->getNodeType())
//            {
//                case(EXN_NONE):
//                    OTLog::Error("SKIPPING: EXN_NONE --  No xml node. This is usually the node if you did not read anything yet.\n");
//                    break;
//                case(EXN_TEXT):
//                    OTLog::Error("SKIPPING: EXN_TEXT -- Text within an xml element: <foo> this is the text. <foo>.\n");
//                    break;
//                case(EXN_COMMENT):
//                    OTLog::Error("SKIPPING: EXN_COMMENT -- An xml comment like <!-- I am a comment --> or a DTD definition.\n");
//                    break;
//                case(EXN_ELEMENT_END):
//                    OTLog::Error("SKIPPING: EXN_ELEMENT_END -- End of an xml element such as </foo>.\n");
//                    break;
//                case(EXN_CDATA):
//                    OTLog::Error("SKIPPING: EXN_CDATA -- An xml cdata section like <![CDATA[ this is some CDATA ]]>.\n");
//                    break;
//                default:
//                    OTLog::Error("SKIPPING: default!! -- SHOULD NEVER HAPPEN...\n");
//                    break;
//            }
                
				break;
			case EXN_ELEMENT:
			{
                const OTString strNodeName = xml->getNodeName();

                
                
//                OTLog::vError("PROCESSING EXN_ELEMENT: NODE NAME: %s\n", strNodeName.Get());
                
                
                
                
                
				if (strNodeName.Compare("OTuser"))
				{
					m_strVersion                = xml->getAttributeValue("version");					
					const OTString UserNymID    = xml->getAttributeValue("nymID");
					
					
					// Server-side only...
					OTString strCredits = xml->getAttributeValue("usageCredits");
					
					if (strCredits.GetLength() > 0)
						m_lUsageCredits = atol(strCredits.Get());
					else
						m_lUsageCredits = 0; // This is the default anyway, but just being safe...

					//TODO: no need to set the ID again here. We already know the ID
					// at this point. Better to check and compare they are the same here.
					//m_nymID.SetString(UserNymID);
					//
					
					if (UserNymID.GetLength())
						OTLog::vOutput(3, "\nLoading user, version: %s NymID:\n%s\n", m_strVersion.Get(), UserNymID.Get());
					bSuccess = true;
				}
				else if (strNodeName.Compare("requestNum"))
				{
					const OTString ReqNumServerID = xml->getAttributeValue("serverID");				
					const OTString ReqNumCurrent = xml->getAttributeValue("currentRequestNum");
					
					OTLog::vOutput(3, "\nCurrent Request Number is %s for ServerID: %s\n",
								   ReqNumCurrent.Get(), ReqNumServerID.Get());
					
					// Make sure now that I've loaded this request number, to add it to my
					// internal map so that it is available for future lookups.
					m_mapRequestNum[ReqNumServerID.Get()] = atol(ReqNumCurrent.Get());
				}                
				else if (strNodeName.Compare("nymboxHash"))
				{
					const OTString strValue = xml->getAttributeValue("value");				
					
					OTLog::vOutput(3, "\nNymboxHash is: %s\n", strValue.Get());
					
                    if (strValue.Exists())
                        m_NymboxHash.SetString(strValue);
				}
                else if (strNodeName.Compare("nymboxHashItem"))
				{
					const OTString strServerID      = xml->getAttributeValue("serverID");				
					const OTString strNymboxHash    = xml->getAttributeValue("nymboxHash");
					
					OTLog::vOutput(3, "\nNymboxHash is %s for ServerID: %s\n",
								   strNymboxHash.Get(), strServerID.Get());
					
					// Make sure now that I've loaded this nymboxHash, to add it to my
					// internal map so that it is available for future lookups.
                    if (strServerID.Exists() && strNymboxHash.Exists())
                    {
                        const OTIdentifier theID(strNymboxHash);
                        m_mapNymboxHash[strServerID.Get()] = theID;
                    }
				}
                else if (strNodeName.Compare("recentHashItem"))
				{
					const OTString strServerID      = xml->getAttributeValue("serverID");				
					const OTString strRecentHash    = xml->getAttributeValue("recentHash");
					
					OTLog::vOutput(3, "\nRecentHash is %s for ServerID: %s\n",
								   strRecentHash.Get(), strServerID.Get());
					
					// Make sure now that I've loaded this RecentHash, to add it to my
					// internal map so that it is available for future lookups.
                    if (strServerID.Exists() && strRecentHash.Exists())
                    {
                        const OTIdentifier theID(strRecentHash);
                        m_mapRecentHash[strServerID.Get()] = theID;
                    }
				}
                else if (strNodeName.Compare("inboxHashItem"))
				{
					const OTString strAccountID    = xml->getAttributeValue("accountID");				
					const OTString strHashValue    = xml->getAttributeValue("hashValue");
					
					OTLog::vOutput(3, "\nInboxHash is %s for Account ID: %s\n",
								   strHashValue.Get(), strAccountID.Get());
					
					// Make sure now that I've loaded this InboxHash, to add it to my
					// internal map so that it is available for future lookups.
                    //
                    if (strAccountID.Exists() && strHashValue.Exists())
                    {
                        const OTIdentifier theID(strHashValue);
                        m_mapInboxHash[strAccountID.Get()] = theID;
                    }
				}
                else if (strNodeName.Compare("outboxHashItem"))
				{
					const OTString strAccountID    = xml->getAttributeValue("accountID");				
					const OTString strHashValue    = xml->getAttributeValue("hashValue");
					
					OTLog::vOutput(3, "\nOutboxHash is %s for Account ID: %s\n",
								   strHashValue.Get(), strAccountID.Get());
					
					// Make sure now that I've loaded this OutboxHash, to add it to my
					// internal map so that it is available for future lookups.
                    //
                    if (strAccountID.Exists() && strHashValue.Exists())
                    {
                        const OTIdentifier theID(strHashValue);
                        m_mapOutboxHash[strAccountID.Get()] = theID;
                    }
				}
				else if (strNodeName.Compare("highestTransNum"))
				{
					const OTString HighNumServerID = xml->getAttributeValue("serverID");				
					const OTString HighNumRecent = xml->getAttributeValue("mostRecent");
					
					OTLog::vOutput(3, "\nHighest Transaction Number ever received is %s for ServerID: %s\n",
								   HighNumRecent.Get(), HighNumServerID.Get());
					
					// Make sure now that I've loaded this highest number, to add it to my
					// internal map so that it is available for future lookups.
					m_mapHighTransNo[HighNumServerID.Get()] = atol(HighNumRecent.Get());
				}
                // ----------------------------------------------
                
                else if (strNodeName.Compare("transactionNums"))
                {	
                    const OTString tempServerID	= xml->getAttributeValue("serverID");				
                    OTString strTemp;
                    if (!tempServerID.Exists() || !OTContract::LoadEncodedTextField(xml, strTemp))
                    {
                        OTLog::Error("OTPseudonym::LoadFromString: Error: transactionNums field without value.\n");
                        return false; // error condition
                    }
                    OTNumList theNumList;
                    
                    if (strTemp.Exists())
                        theNumList.Add(strTemp);
                    
                    long lTemp=0;
                    while(theNumList.Peek(lTemp))
                    {
                        theNumList.Pop();
                        // ------------
                        OTLog::vOutput(3, "Transaction Number %ld ready-to-use for ServerID: %s\n",
                                       lTemp, tempServerID.Get());
                        AddTransactionNum(tempServerID, lTemp); // This version doesn't save to disk. (Why save to disk AS WE'RE LOADING?)
                    }
                }
                
                // ----------------------------------------------
                
                else if (strNodeName.Compare("issuedNums"))
                {	
                    const OTString tempServerID	= xml->getAttributeValue("serverID");				
                    OTString strTemp;
                    if (!tempServerID.Exists() || !OTContract::LoadEncodedTextField(xml, strTemp))
                    {
                        OTLog::Error("OTPseudonym::LoadFromString: Error: issuedNums field without value.\n");
                        return false; // error condition
                    }
                    OTNumList theNumList;
                    
                    if (strTemp.Exists())
                        theNumList.Add(strTemp);
                    
                    long lTemp=0;
                    while(theNumList.Peek(lTemp))
                    {
                        theNumList.Pop();
                        // ------------
                        OTLog::vOutput(3, "Currently liable for issued trans# %ld at ServerID: %s\n",
                                       lTemp, tempServerID.Get());
                        AddIssuedNum(tempServerID, lTemp); // This version doesn't save to disk. (Why save to disk AS WE'RE LOADING?)
                    }
                }
                
                // ----------------------------------------------
                
                else if (strNodeName.Compare("tentativeNums"))
                {	
                    const OTString tempServerID	= xml->getAttributeValue("serverID");				
                    OTString strTemp;
                    if (!tempServerID.Exists() || !OTContract::LoadEncodedTextField(xml, strTemp))
                    {
                        OTLog::Error("OTPseudonym::LoadFromString: Error: tentativeNums field without value.\n");
                        return false; // error condition
                    }
                    OTNumList theNumList;
                    
                    if (strTemp.Exists())
                        theNumList.Add(strTemp);
                    
                    long lTemp=0;
                    while(theNumList.Peek(lTemp))
                    {
                        theNumList.Pop();
                        // ------------
                        OTLog::vOutput(3, "Tentative: Currently awaiting success notice, "
                                       "for accepting trans# %ld for ServerID: %s\n",
                                       lTemp, tempServerID.Get());
                        AddTentativeNum(tempServerID, lTemp); // This version doesn't save to disk. (Why save to disk AS WE'RE LOADING?)
                    }
                }
                
                // ----------------------------------------------
                
                else if (strNodeName.Compare("ackNums"))
                {	
                    const OTString tempServerID	= xml->getAttributeValue("serverID");				
                    OTString strTemp;
                    if (!tempServerID.Exists())
                    {
                        OTLog::vError("OTPseudonym::LoadFromString: Error: While loading ackNums "
                                      "field: Missing serverID. Nym contents:\n\n%s\n\n", strNym.Get());
                        return false; // error condition
                    }
                    // ----------------------
                    
//                  xml->read(); // there should be a text field next, with the data for the list of acknowledged numbers.
                    // Note: I think I was forced to add this when the numlist was empty, one time, so this may come back
                    // to haunt me, but I want to fix it right, not kludge it.
                    //
                    // ----------------------
                    if (!OTContract::LoadEncodedTextField(xml, strTemp))
                    {
                        OTLog::Error("OTPseudonym::LoadFromString: Error: ackNums field without value "
                                     "(at least, unable to LoadEncodedTextField on that value.)\n");
                        return false; // error condition
                    }
                    OTNumList theNumList;
                    
                    if (strTemp.Exists())
                        theNumList.Add(strTemp);
                    
                    long lTemp=0;
                    while(theNumList.Peek(lTemp))
                    {
                        theNumList.Pop();
                        // ------------
                        OTLog::vOutput(2, "Acknowledgment record exists for server reply, for Request Number %ld for ServerID: %s\n",
                                       lTemp, tempServerID.Get());
                        AddAcknowledgedNum(tempServerID, lTemp); // This version doesn't save to disk. (Why save to disk AS WE'RE LOADING?)
                    }
                }
                
                // ----------------------------------------------
                
                // THE BELOW FOUR ARE DEPRECATED, AND ARE REPLACED BY THE ABOVE FOUR.
                
				else if (!!strNodeName.Compare("transactionNum"))
				{
					const OTString TransNumServerID	= xml->getAttributeValue("serverID");				
					const OTString TransNumAvailable	= xml->getAttributeValue("transactionNum");
					
					OTLog::vOutput(3, "Transaction Number %s available for ServerID: %s\n",
								   TransNumAvailable.Get(), TransNumServerID.Get());
					
					AddTransactionNum(TransNumServerID, atol(TransNumAvailable.Get())); // This version doesn't save to disk. (Why save to disk AS WE'RE LOADING?)
				}
				else if (strNodeName.Compare("issuedNum"))
				{
					const OTString TransNumServerID	= xml->getAttributeValue("serverID");				
					const OTString TransNumAvailable	= xml->getAttributeValue("transactionNum");
					
					OTLog::vOutput(3, "Currently liable for Transaction Number %s, for ServerID: %s\n",
								   TransNumAvailable.Get(), TransNumServerID.Get());
					
					AddIssuedNum(TransNumServerID, atol(TransNumAvailable.Get())); // This version doesn't save to disk. (Why save to disk AS WE'RE LOADING?)
				}
				else if (strNodeName.Compare("tentativeNum"))
				{
					const OTString TransNumServerID	= xml->getAttributeValue("serverID");				
					const OTString TransNumAvailable	= xml->getAttributeValue("transactionNum");
					
					OTLog::vOutput(3, "Currently waiting on server success notice, accepting Transaction Number %s, for ServerID: %s\n",
								   TransNumAvailable.Get(), TransNumServerID.Get());
					
					AddTentativeNum(TransNumServerID, atol(TransNumAvailable.Get())); // This version doesn't save to disk. (Why save to disk AS WE'RE LOADING?)
				}                
				else if (strNodeName.Compare("acknowledgedNum"))
				{
					const OTString AckNumServerID = xml->getAttributeValue("serverID");				
					const OTString AckNumValue    = xml->getAttributeValue("requestNum");
					
					OTLog::vOutput(3, "Acknowledgment record exists for server reply, for Request Number %s, for ServerID: %s\n",
								   AckNumValue.Get(), AckNumServerID.Get());
					
					AddAcknowledgedNum(AckNumServerID, atol(AckNumValue.Get())); // This version doesn't save to disk. (Why save to disk AS WE'RE LOADING?)
				}                
                // -------------------------------------
                else if (strNodeName.Compare("MARKED_FOR_DELETION"))
				{
					m_bMarkForDeletion = true;  
                    OTLog::vOutput(3, "This nym has been MARKED_FOR_DELETION (at some point prior.)\n");
				}
                // -------------------------------------
                
				else if (!!strNodeName.Compare("hasOpenCronItem"))
				{
                    OTString strID = xml->getAttributeValue("ID");
					
                    if (strID.Exists())
                    {
                        const long lNewID = atol(strID.Get()); 
                        m_setOpenCronItems.insert(lNewID);
                        OTLog::vOutput(3, "This nym has an open cron item with ID: %s\n",
                                       strID.Get());
                    }
                    else
                        OTLog::vOutput(3, "This nym MISSING ID when loading open cron item record.\n");
				}
				else if (strNodeName.Compare("ownsAssetAcct"))
				{
                    OTString strID = xml->getAttributeValue("ID");
					
                    if (strID.Exists())
                    {
                        m_setAccounts.insert(strID.Get());
                        OTLog::vOutput(3, "This nym has an asset account with the ID: %s\n",
                                       strID.Get());
                    }
                    else
                        OTLog::vOutput(3, "This nym MISSING asset account ID when loading nym record.\n");
				}
				else if (strNodeName.Compare("mailMessage"))
				{					
					OTASCIIArmor armorMail;
					
					OTString strMessage;
					
					xml->read();
					
					if (EXN_TEXT == xml->getNodeType())
					{
						OTString strNodeData = xml->getNodeData();
						
						// Sometimes the XML reads up the data with a prepended newline.
						// This screws up my own objects which expect a consistent in/out
						// So I'm checking here for that prepended newline, and removing it.
						char cNewline;
						if (strNodeData.Exists() && strNodeData.GetLength() > 2 && strNodeData.At(0, cNewline))
						{
							if ('\n' == cNewline)
							{
								armorMail.Set(strNodeData.Get() + 1); // I know all this shit is ugly. I refactored this in OTContract.
							}
							else										// unfortunately OTNym is like a "basic type" and isn't derived from OTContract.
							{
								armorMail.Set(strNodeData.Get());       // TODO: OTContract now has STATIC methods for this. (Start using them here...)
							}
							
							if (armorMail.GetLength() > 2)
							{
								armorMail.GetString(strMessage, true); // linebreaks == true.
								
								if (strMessage.GetLength() > 2)
								{
									OTMessage * pMessage = new OTMessage;
									
									OT_ASSERT(NULL != pMessage);
									
									if (pMessage->LoadContractFromString(strMessage))
										m_dequeMail.push_back(pMessage); // takes ownership
									else
										delete pMessage;
								}
							}
						}
					}
				}
				else if (strNodeName.Compare("outmailMessage"))
				{					
					OTASCIIArmor armorMail;
					
					OTString strMessage;
					
					xml->read();
					
					if (EXN_TEXT == xml->getNodeType())
					{
						OTString strNodeData = xml->getNodeData();
						
						// Sometimes the XML reads up the data with a prepended newline.
						// This screws up my own objects which expect a consistent in/out
						// So I'm checking here for that prepended newline, and removing it.
						char cNewline;
						if (strNodeData.Exists() && strNodeData.GetLength() > 2 && strNodeData.At(0, cNewline))
						{
							if ('\n' == cNewline)
							{
								armorMail.Set(strNodeData.Get() + 1);
							}
							else
							{
								armorMail.Set(strNodeData.Get());
							}
							
							if (armorMail.GetLength() > 2)
							{
								armorMail.GetString(strMessage, true); // linebreaks == true.
								
								if (strMessage.GetLength() > 2)
								{
									OTMessage * pMessage = new OTMessage;
									
									OT_ASSERT(NULL != pMessage);
									
									if (pMessage->LoadContractFromString(strMessage))
										m_dequeOutmail.push_back(pMessage); // takes ownership
									else
										delete pMessage;
								}
							}
						}
					}
				} // outpayments message
				else if (strNodeName.Compare("outpaymentsMessage"))
				{					
					OTASCIIArmor armorMail;
					
					OTString strMessage;
					
					xml->read();
					
					if (EXN_TEXT == xml->getNodeType())
					{
						OTString strNodeData = xml->getNodeData();
						
						// Sometimes the XML reads up the data with a prepended newline.
						// This screws up my own objects which expect a consistent in/out
						// So I'm checking here for that prepended newline, and removing it.
						char cNewline;
						if (strNodeData.Exists() && strNodeData.GetLength() > 2 && strNodeData.At(0, cNewline))
						{
							if ('\n' == cNewline)
							{
								armorMail.Set(strNodeData.Get() + 1);
							}
							else
							{
								armorMail.Set(strNodeData.Get());
							}
							
							if (armorMail.GetLength() > 2)
							{
								armorMail.GetString(strMessage, true); // linebreaks == true.
								
								if (strMessage.GetLength() > 2)
								{
									OTMessage * pMessage = new OTMessage;
									
									OT_ASSERT(NULL != pMessage);
									
									if (pMessage->LoadContractFromString(strMessage))
										m_dequeOutpayments.push_back(pMessage); // takes ownership
									else
										delete pMessage;
								}
							}
						}
					}
				} // outpayments message
				else
				{
					// unknown element type
					OTLog::vError("Unknown element type in OTPseudonym::LoadFromString: %s\n", xml->getNodeName());
					bSuccess = false;
				}
				break;
			}
			default:
			{
				OTLog::vOutput(5, "Unknown XML type in OTPseudonym::LoadFromString: %s\n", xml->getNodeName());
				break;	
			}
		} // switch
	} // while

	return bSuccess;
}




bool OTPseudonym::LoadSignedNymfile(OTPseudonym & SIGNER_NYM)
{
	// Get the Nym's ID in string form
	OTString nymID;
	GetIdentifier(nymID);
	
	// Create an OTSignedFile object, giving it the filename (the ID) and the local directory ("nyms")
	OTSignedFile	theNymfile("nyms", nymID);
	
	if (false == theNymfile.LoadFile())
	{
		OTLog::vOutput(0, "Failed Loading a signed nymfile:\n%s\n\n", nymID.Get());
		return false;
	}
	
	// We verify:
	//
	// 1. That the file even exists and loads.
	// 2. That the local subdir and filename match the versions inside the file.
	// 3. That the signature matches for the signer nym who was passed in.
	//
	if (	true					// Also see OTWallet.cpp where it says:   //pNym->SaveSignedNymfile(*pNym); // Uncomment this if you want to generate a new nym by hand. NORMALLY LEAVE IT COMMENTED OUT!!!! IT'S DANGEROUS!!!
		&&	theNymfile.VerifyFile()			// TODO TEMP TEMPORARY RESUME  (These two lines can be commented out to allow you to load a nymfile with no sig.)
		&&	theNymfile.VerifySignature(SIGNER_NYM)	// These are ONLY commented-out so I can reload a bad nymfile. (UNCOMMENT THESE IF YOU SEE THIS COMMENTED OUT.)
		)
	{
		OTLog::Output(2, "Loaded and verified signed nymfile. Reading from string...\n");
		
		if (theNymfile.GetFilePayload().GetLength() > 0)
			return LoadFromString(theNymfile.GetFilePayload());
		else 
		{
			const long lLength = static_cast<long> (theNymfile.GetFilePayload().GetLength());
			
			OTLog::vError("Bad length (%ld) while loading nymfile:\n%s\n", lLength, nymID.Get());
		}
	}
	else 
	{
		OTLog::vError("Error Verifying signed nymfile:\n%s\n\n", nymID.Get());
	}

	return false;
}

bool OTPseudonym::SaveSignedNymfile(OTPseudonym & SIGNER_NYM)
{
	// Get the Nym's ID in string form
	OTString nymID;
	GetIdentifier(nymID);

	// Create an OTSignedFile object, giving it the filename (the ID) and the local directory ("nyms")
	OTSignedFile	theNymfile(OTLog::NymFolder(), nymID);
	theNymfile.GetFilename(m_strNymfile);
	
	OTLog::vOutput(2, "Saving nym to: %s\n", m_strNymfile.Get());
	
	// First we save this nym to a string...
	// Specifically, the file payload string on the OTSignedFile object.
	SavePseudonym(theNymfile.GetFilePayload());

	// Now the OTSignedFile contains the path, the filename, AND the
	// contents of the Nym itself, saved to a string inside the OTSignedFile object.
	
	if (theNymfile.SignContract(SIGNER_NYM) && 
		theNymfile.SaveContract())
	{
		return theNymfile.SaveFile();
	}
	
	return false;
}


/// See if two nyms have identical lists of issued transaction numbers (#s currently signed for.)
//
bool OTPseudonym::VerifyIssuedNumbersOnNym(OTPseudonym & THE_NYM)
{
	long lTransactionNumber	= 0; // Used in the loop below.
	
	int nNumberOfTransactionNumbers1 = 0; // *this
	int nNumberOfTransactionNumbers2 = 0; // THE_NYM.
	
	std::string	strServerID;
	
	// First, loop through the Nym on my side (*this), and count how many numbers total he has...
	//
	FOR_EACH(mapOfTransNums, GetMapIssuedNum())
	{	
//		strServerID					= (*it).first;
		dequeOfTransNums * pDeque	= (it->second);		
		OT_ASSERT(NULL != pDeque);
		
		if (!(pDeque->empty()))
		{
			nNumberOfTransactionNumbers1 += static_cast<int> (pDeque->size());
		}
	} // for
	
	// Next, loop through THE_NYM, and count his numbers as well...
	// But ALSO verify that each one exists on *this, so that each individual
	// number is checked.
	//
	FOR_EACH(mapOfTransNums, THE_NYM.GetMapIssuedNum())
	{	
		strServerID					= (*it).first;
		dequeOfTransNums * pDeque	= (it->second);
		OT_ASSERT(NULL != pDeque);
		
		OTString OTstrServerID = strServerID.c_str();
				
		if (!(pDeque->empty()))
		{
			for (unsigned i = 0; i < pDeque->size(); i++)
			{
				lTransactionNumber = pDeque->at(i);
				
//				if ()
				{
					nNumberOfTransactionNumbers2 ++ ; 
					
					if (false == VerifyIssuedNum(OTstrServerID, lTransactionNumber))
					{
						OTLog::vOutput(0, "OTPseudonym::VerifyIssuedNumbersOnNym: Issued transaction # %ld from THE_NYM not found on *this.\n", 
									   lTransactionNumber);
						
						return false;
					}
				}
			}
		}
	} // for
	
	// Finally, verify that the counts match...
	if (nNumberOfTransactionNumbers1 != nNumberOfTransactionNumbers2)
	{
		OTLog::vOutput(0, "OTPseudonym::VerifyIssuedNumbersOnNym: Issued transaction # Count mismatch: %d and %d\n", 
					   nNumberOfTransactionNumbers1, nNumberOfTransactionNumbers2);
		
		return false;
	}	
	
	return true;
}


// This is client-side. It's called by VerifyTransactionReceipt and VerifyBalanceReceipt.
//
// It's okay if some issued transaction #s in THE_NYM (the receipt's Nym) aren't found on *this, (client-side Nym)
// since the last balance agreement may have cleaned them out after they were recorded in THE_NYM 
// (from the transaction statement receipt).
//
// But I should never see transaction #s APPEAR in *this that aren't in THE_NYM on receipt, since a balance agreement
// can ONLY remove numbers, not add them. So any numbers left over should still be accounted for on the
// last signed receipt (which supplied THE_NYM as that list of numbers.)
//
// Conclusion: Loop through *this, which is newer, and make sure ALL numbers appear on THE_NYM.
// No need to check the reverse, and no need to match the count.
//
bool OTPseudonym::VerifyTransactionStatementNumbersOnNym(OTPseudonym & THE_NYM) // THE_NYM is from the receipt.
{
	long lTransactionNumber	= 0; // Used in the loop below.
	
	std::string	strServerID;
	
	// First, loop through the Nym on my side (*this), and verify that all those #s appear on the last receipt (THE_NYM)
	//
	FOR_EACH(mapOfTransNums, GetMapIssuedNum())
	{	
		strServerID					= (*it).first;
		dequeOfTransNums * pDeque	= (it->second);
		
		OTString OTstrServerID = strServerID.c_str();
		
		OT_ASSERT(NULL != pDeque);
		
		if (!(pDeque->empty()))
		{
			for (unsigned i = 0; i < pDeque->size(); i++)
			{
				lTransactionNumber = pDeque->at(i);

				if (false == THE_NYM.VerifyIssuedNum(OTstrServerID, lTransactionNumber))
				{
					OTLog::vOutput(0, "OTPseudonym::VerifyTransactionStatementNumbersOnNym: Issued transaction # %ld from *this not found on THE_NYM.\n", 
								   lTransactionNumber);
					return false;
				}
			}
		}
	} // for
	
	// Getting here means that, though issued numbers may have been removed from my responsibility
	// in a subsequent balance agreement (since the transaction agreement was signed), I know
	// for a fact that no numbers have been ADDED to my list of responsibility.
	// That's the most we can verify here, since we don't know the account number that was
	// used for the last balance agreement.
	
	
	return true;
}





// Each Nym has a public key file, as well as a nym file. Why two separate files?
// Because they are often used for different purposes and are being loaded/saved 
// for their own reasons. The Nymfile contains the user ID, which is a hash of the
// public key, so the it knows how to find the right pubkey file (filename is the
// hash) and it knows how to validate the contents (by hashing them.) The Nymfile
// also contains the transaction numbers that have been issued to that nym, so 
// the server might later load it up in order to verify that a specific transaction
// number is indeed on that list (and then remove it from the list.)
bool OTPseudonym::LoadNymfile(const char * szFilename/*=NULL*/)
{
	OTString strID;
	GetIdentifier(strID);

	const char * szFoldername = OTLog::NymFolder();
	const char * szTheFilename = strID.Get();
	
	// If no filename was passed in (user might have designated one) then we create
	// the filename by appending the Nym's ID to the path.
	if (NULL == szFilename)
	{
		m_strNymfile = szTheFilename;
	}
	else 
	{
		m_strNymfile = szFilename;
	}
	// --------------------------------------------------------------------
	if (false == OTDB::Exists(szFoldername, m_strNymfile.Get()))
	{
		OTLog::vError("OTPseudonym::LoadNymfile: File does not exist: %s%s%s\n", 
					  szFoldername, OTLog::PathSeparator(), m_strNymfile.Get());
		return false;
	}
	// --------------------------------------------------------------------
	//
	std::string strFileContents(OTDB::QueryPlainString(szFoldername, m_strNymfile.Get())); // <=== LOADING FROM DATA STORE.
	
	if (strFileContents.length() < 2)
	{
		OTLog::vError("OTPseudonym::LoadNymfile: Error reading file: %s%s%s\n", 
					  szFoldername, OTLog::PathSeparator(), m_strNymfile.Get());
		return false;
	}
	// --------------------------------------------------------------------
	OTString strRawFile = strFileContents.c_str();
	
	if (strRawFile.GetLength())
		return LoadFromString(strRawFile);
		
	return false;
}



bool OTPseudonym::Loadx509CertAndPrivateKeyFromString(const OTString & strInput, OTString * pstrReason/*=NULL*/)
{
    const char *szFunc = "OTPseudonym::Loadx509CertAndPrivateKeyFromString";
	// --------------------------------------------------------------------
    const bool bExists = strInput.Exists();
	if (!bExists)
	{
        const OTString strID(m_nymID);
		OTLog::vError("%s: strInput does not exist. (Returning false.) ID currently set to: %s\n",
                      szFunc, strID.Get());
		return false;
	}	
	// --------------------------------------------------------------------
    const bool bPublic  = m_pkeyPublic-> LoadPublicKeyFromCertString (strInput, false); //bool bEscaped=true by default
    const bool bPrivate = m_pkeyPrivate->LoadPrivateKeyFromCertString(strInput,
                                                                      false, //bool bEscaped=true by default, // "escaped" means pre-pended with "- " as in:   - -----BEGIN CER....
                                                                      pstrReason);
    if (!bPublic)
    {
        OTLog::vError("%s: Although the input string apparently exists, "
                      "LoadPublicKeyFromCertString returned false.\n", szFunc);
        return false;
    }
    else
    {
        OTLog::vOutput(2, "%s: Successfully loaded public key from string.\n", 
                       szFunc);
    }
    // ----------------
    if (!bPrivate)
    {
        OTLog::vError("%s: Although the input string apparently exists, "
                      "LoadPrivateKeyFromCertString returned false.\n", szFunc);
        return false;
    }
    else
    {
        OTLog::vOutput(2, "%s: Successfully loaded private key from string.\n", szFunc);
    }
    // ----------------
    return true;	
}

                      
// Todo: if the above function works fine, then call it in the below function (to reduce code bloat.)

bool OTPseudonym::Loadx509CertAndPrivateKey(OTString * pstrReason/*=NULL*/)
{
    const char * szFunc = "OTPseudonym::Loadx509CertAndPrivateKey";
    
	OTString strID(m_nymID);

	const char * szFoldername	= OTLog::CertFolder();
	const char * szFilename		= strID.Get();
	
//	OT_ASSERT(NULL != szFoldername);
//	OT_ASSERT(NULL != szFilename);
	
//	m_strCertfile.Format((char *)"%s%s%s%s%s", OTLog::Path(), OTLog::PathSeparator(),
//						 OTLog::CertFolder(),
//						 OTLog::PathSeparator(), strID.Get());
	// --------------------------------------------------------------------
    bool bExists = false;
    
	if ((NULL == szFoldername) ||
        (NULL == szFilename)   ||
        (false == (bExists = OTDB::Exists(szFoldername, szFilename))))
	{
		OTLog::vError("%s: File does not exist: %s%s%s\n", szFunc,
					  NULL == szFoldername ? "" : szFoldername, OTLog::PathSeparator(), 
                      NULL == szFilename   ? "" : szFilename);
		return false;
	}
	// --------------------------------------------------------------------
/*
 Error reading private key from file in OTAsymmetricKey::LoadPrivateKey: certs/T1Q3wZWgeTUoaUvn9m1lzIK5tn5wITlzxzrGNI8qtaV
 
 Although the ascii-armored file (certs/T1Q3wZWgeTUoaUvn9m1lzIK5tn5wITlzxzrGNI8qtaV) was read, LoadPrivateKey returned false.
 
 OTPseudonym::LoadPrivateNym OTPseudonym::LoadPrivateNym: Failure calling Loadx509CertAndPrivateKey: T1Q3wZWgeTUoaUvn9m1lzIK5tn5wITlzxzrGNI8qtaV
 */
	
	const OTString strFoldername(szFoldername);
	const OTString strFilename(szFilename);
	
	OT_ASSERT(strFoldername.Exists());
	OT_ASSERT(strFilename.Exists());
		
	// I load the same file again, but this time using OpenSSL functions to read the public
	// key and private key (if necessary) from the same file.
	if (bExists)
	{
		const bool bPublic  = m_pkeyPublic-> LoadPublicKeyFromCertFile(strFoldername, strFilename);
		const bool bPrivate = m_pkeyPrivate->LoadPrivateKey(strFoldername, strFilename, pstrReason);
		
		if (!bPublic)
		{
			OTLog::vError("%s: Although the ascii-armored file (%s%s%s) was read, "
                          "LoadPublicKeyFromCert returned false.\n", szFunc, szFoldername,
                          OTLog::PathSeparator(), szFilename);
			return false;
		}
		else
		{
			OTLog::vOutput(2, "%s: Successfully loaded public key from Certfile: %s%s%s\n", 
						   szFunc, szFoldername, OTLog::PathSeparator(), szFilename);
		}
		// ----------------
		if (!bPrivate)
		{
			OTLog::vError("%s: Although the ascii-armored file (%s%s%s) was read, "
                          "LoadPrivateKey returned false.\n", szFunc, szFoldername,
                          OTLog::PathSeparator(), szFilename);
			return false;
		}
		else
		{
			OTLog::vOutput(2, "%s: Successfully loaded private key from: %s%s%s\n", 
						   szFunc, szFoldername, OTLog::PathSeparator(), szFilename);
		}
		
		return true;	
	}
    // ---------------------------------
    OTLog::vError("%s: Failure, filename: %s%s%s\n", szFunc,
                  szFoldername, OTLog::PathSeparator(), szFilename);
    return false;
}



//static
bool OTPseudonym::DoesCertfileExist(const OTString & strNymID)
{
	const char * szFoldername	= OTLog::CertFolder();
	const char * szFilename		= strNymID.Get();
	// --------------------------------------------------------------------
	if ((NULL == szFoldername) || (NULL == szFilename))
        return false;
    // -----------------------------------------
    return OTDB::Exists(szFoldername, szFilename);
}


// on the client side, this means it's a private Nym.
bool OTPseudonym::CertfileExists()
{
	const OTString strID(m_nymID);
    return OTPseudonym::DoesCertfileExist(strID);
}


bool OTPseudonym::HasPublicKey()
{
	return m_pkeyPublic->IsPublic(); // This means it actually has a public key in it, or tried to.
}

bool OTPseudonym::HasPrivateKey()
{
	return m_pkeyPrivate->IsPrivate(); // This means it actually has a private key in it, or tried to.
}

// ----------------------------------------------------------------------------------------

// This version WILL handle the bookends: -----BEGIN CERTIFICATE------ 
// It will also handle the escaped version: - -----BEGIN CERTIFICATE-----
bool OTPseudonym::SetCertificate(const OTString & strCert, bool bEscaped/*=true*/)
{
	return m_pkeyPublic->LoadPublicKeyFromCertString(strCert, bEscaped);
}


// This version WILL handle the bookends -----BEGIN PUBLIC KEY------ 
// It will also handle the escaped version: - -----BEGIN PUBLIC KEY------
bool OTPseudonym::SetPublicKey(const OTString & strKey, bool bEscaped/*=true*/)
{	
	if (strKey.Contains("PGP PUBLIC KEY"))
	{
		OTASCIIArmor theArmor;
		
		if (theArmor.LoadFromString(const_cast<OTString &>(strKey), bEscaped))
		{
			// This function expects that the bookends are already removed.
			// The ascii-armor loading code removes them and handles the escapes also.
			return m_pkeyPublic->LoadPublicKeyFromPGPKey(theArmor);
		}
		else 
        {
			OTLog::Output(2, "OTPseudonym::SetPublicKey: Failed extracting PGP public key from ascii-armored text.\n");
			return false;
		}
	}
	else // the below function SetPublicKey (in the return call) expects the
		 // bookends to still be there, and it will handle removing them. (Unlike PGP code above.)
		return m_pkeyPublic->SetPublicKey(strKey, bEscaped);
}


// This version handles the ascii-armored text WITHOUT the bookends
bool OTPseudonym::SetPublicKey(const OTASCIIArmor & strKey)
{
	return m_pkeyPublic->SetPublicKey(strKey);
}

// ----------------------------------------------------------------------------------------


// This version WILL handle the bookends -----BEGIN ENCRYPTED PRIVATE KEY------ 
// It will also handle the escaped version: - -----BEGIN ENCRYPTED PRIVATE KEY------
//
bool OTPseudonym::SetPrivateKey(const OTString & strKey, bool bEscaped/*=true*/)
{	
    const char * szOverride = "PGP PRIVATE KEY";

	if (strKey.Contains(szOverride))
	{
		OTASCIIArmor theArmor;
        
		if (theArmor.LoadFromString(const_cast<OTString &>(strKey), bEscaped,
                                    szOverride)) // szOverride == "PGP PRIVATE KEY"
		{
			// This function expects that the bookends are already removed.
			// The ascii-armor loading code removes them and handles the escapes also.
//			return m_pkeyPrivate->LoadPrivateKeyFromPGPKey(theArmor);
            //
			OTLog::vOutput(0, "OTPseudonym::SetPrivateKey 1: Failure: PGP private keys are NOT YET SUPPORTED:\n\n%s\n\n",
                           strKey.Get());
			return false;
		}
		else 
        {
			OTLog::vOutput(0, "OTPseudonym::SetPrivateKey 2: Failure: PGP private keys are NOT YET SUPPORTED:\n\n%s\n\n",
                           strKey.Get());
			return false;
		}
	}
	else // the below function SetPrivateKey (in the return call) expects the
         // bookends to still be there, and it will handle removing them. (Unlike PGP code above.)
        //
		return m_pkeyPrivate->SetPrivateKey(strKey, bEscaped);
}


// This version handles the ascii-armored text WITHOUT the bookends
//
bool OTPseudonym::SetPrivateKey(const OTASCIIArmor & strKey)
{
	return m_pkeyPrivate->SetPrivateKey(strKey);
}

// ----------------------------------------------------------------------------------------

const OTAsymmetricKey & OTPseudonym::GetPublicKey() const
{
	return (*m_pkeyPublic);
}

const OTAsymmetricKey & OTPseudonym::GetPrivateKey() const
{
	return (*m_pkeyPrivate);
}

// ----------------------------------------------------------------------------------------
// sets internal member based in ID passed in
void OTPseudonym::SetIdentifier(const OTIdentifier & theIdentifier)
{
	m_nymID = theIdentifier;
}

// sets argument based on internal member
void OTPseudonym::GetIdentifier(OTIdentifier & theIdentifier) const
{
	theIdentifier = m_nymID;
}

// sets internal member based in ID passed in
void OTPseudonym::SetIdentifier(const OTString & theIdentifier)
{
	m_nymID.SetString(theIdentifier);
}

// sets argument based on internal member
void OTPseudonym::GetIdentifier(OTString & theIdentifier) const
{	
	m_nymID.GetString(theIdentifier);
}

// ----------------------------------------------------------------------------------------


OTPseudonym::OTPseudonym() : m_bMarkForDeletion(false), m_lUsageCredits(0)
{
	m_pkeyPublic = new OTAsymmetricKey;
	m_pkeyPrivate = new OTAsymmetricKey;
	Initialize();
}

void OTPseudonym::Initialize()
{
	m_strVersion = "1.0";
}

OTPseudonym::OTPseudonym(const OTString & name, const OTString & filename, const OTString & nymID)
 : m_bMarkForDeletion(false), m_lUsageCredits(0)
{
	m_pkeyPublic = new OTAsymmetricKey;
	m_pkeyPrivate = new OTAsymmetricKey;

	Initialize();
	
	m_strName		= name;
	m_strNymfile	= filename;
	
	m_nymID.SetString(nymID);
}

OTPseudonym::OTPseudonym(const OTIdentifier & nymID) : m_bMarkForDeletion(false), m_lUsageCredits(0)
{
	m_pkeyPublic = new OTAsymmetricKey;
	m_pkeyPrivate = new OTAsymmetricKey;

	Initialize();
	
	m_nymID = nymID;
}

OTPseudonym::OTPseudonym(const OTString & strNymID) : m_bMarkForDeletion(false), m_lUsageCredits(0)
{
	m_pkeyPublic = new OTAsymmetricKey;
	m_pkeyPrivate = new OTAsymmetricKey;

	Initialize();
	
	m_nymID.SetString(strNymID);
}

OTPseudonym::~OTPseudonym()
{
    if (NULL != m_pkeyPublic)
        delete m_pkeyPublic; // todo: else error
    if (NULL != m_pkeyPrivate)
        delete m_pkeyPrivate; // todo: else error
    // -----------------------------
	m_pkeyPublic	= NULL;
	m_pkeyPrivate	= NULL;
    // -----------------------------
	ReleaseTransactionNumbers();
    // -----------------------------
	ClearMail();
	ClearOutmail();
	ClearOutpayments();
    // -----------------------------

    // Note: unnecessary, superfluous.
    // Might as well release the strings and identifiers too...
    // (Since they are ALSO cleaned up automatically.)
    //
//    m_mapRequestNum.clear();
//    // -----------------------------
//    m_mapHighTransNo.clear();
//    // -----------------------------
//    m_setOpenCronItems.clear(); 
//    // -----------------------------
//    m_setAccounts.clear(); 
    // -----------------------------
}




















