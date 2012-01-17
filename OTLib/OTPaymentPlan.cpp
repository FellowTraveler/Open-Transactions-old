/************************************************************************************
 *    
 *  OTPaymentPlan.cpp
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



#include <cstring>

#include "irrxml/irrXML.h"

using namespace irr;
using namespace io;

#include "OTStorage.h"

#include "OTIdentifier.h"
#include "OTPseudonym.h"
#include "OTAccount.h"
#include "OTLedger.h"
#include "OTTransaction.h"
#include "OTItem.h"

#include "OTCron.h"
#include "OTPaymentPlan.h"
#include "OTLog.h"



// return -1 if error, 0 if nothing, and 1 if the node was processed.
int OTPaymentPlan::ProcessXMLNode(irr::io::IrrXMLReader*& xml)
{
	int nReturnVal = 0;
	
	// Here we call the parent class first.
	// If the node is found there, or there is some error,
	// then we just return either way.  But if it comes back
	// as '0', then nothing happened, and we'll continue executing.
	//
	// -- Note you can choose not to call the parent if
	// you don't want to use any of those xml tags.
	// As I do below, in the case of OTAccount.
	if (0 != (nReturnVal = OTAgreement::ProcessXMLNode(xml)))
		return nReturnVal;
    
	// Note: the closing transaction numbers are read in OTCronItem::ProcessXMLNode,
    // and similarly, the closing Recipient transaction numbers are read in OTAgreement::ProcessXMLNode.
	
    
// ----------------------------------------------------
    
	if (!strcmp("initialPayment", xml->getNodeName())) 
	{
		// Yes, there IS apparently an initial payment. We can set the bool to true.
		m_bInitialPayment	= true; 
		
		SetInitialPaymentDate(			atoi(xml->getAttributeValue("date")));
		SetInitialPaymentCompletedDate(	atoi(xml->getAttributeValue("dateCompleted")));
		SetLastFailedInitialPaymentDate(atoi(xml->getAttributeValue("dateOfLastAttempt")));
		SetNoInitialFailures(			atoi(xml->getAttributeValue("numberOfAttempts")));
		SetInitialPaymentAmount(		atol(xml->getAttributeValue("amount")));
		
		OTString strCompleted(xml->getAttributeValue("completed"));
		
		if (strCompleted.Compare("true"))
			m_bInitialPaymentDone = true;
		else
			m_bInitialPaymentDone = false;
		
		// ---------------------
		
		OTLog::vOutput(1,
					   "\n\nInitial Payment. Amount: %ld.   Date: %d.   Completed Date: %d\n"
					   " Number of failed attempts: %d.   Date of last failed attempt: %d\n"
					   " Payment %s.\n",
					   m_lInitialPaymentAmount, m_tInitialPaymentDate, m_tInitialPaymentCompletedDate,
					   m_nNumberInitialFailures, m_tFailedInitialPaymentDate,
					   (m_bInitialPaymentDone ? "COMPLETED" : "NOT completed"));
		
		nReturnVal = 1;
	}
	
	else if (!strcmp("paymentPlan", xml->getNodeName())) 
	{
		// Yes, there IS apparently a payment plan. We can set the bool to true.
		m_bPaymentPlan	= true; 
		
		SetPaymentPlanAmount(		atol(xml->getAttributeValue("amountPerPayment")));
		SetTimeBetweenPayments(		atoi(xml->getAttributeValue("timeBetweenPayments")));
		SetPaymentPlanStartDate(	atoi(xml->getAttributeValue("planStartDate")));
		SetPaymentPlanLength(		atoi(xml->getAttributeValue("planLength")));
		SetMaximumNoPayments(		atoi(xml->getAttributeValue("maxNoPayments")));
		
		SetDateOfLastPayment(		atoi(xml->getAttributeValue("dateOfLastPayment")));
		SetDateOfLastFailedPayment(	atoi(xml->getAttributeValue("dateOfLastFailedPayment")));
		
		SetNoPaymentsDone(			atoi(xml->getAttributeValue("completedNoPayments")));
		SetNoFailedPayments(		atoi(xml->getAttributeValue("failedNoPayments")));
		
		// ---------------------
		
		OTLog::vOutput(1,
					   "\n\nPayment Plan. Amount per payment: %ld.  Time between payments: %d.\n"
					   " Payment plan Start Date: %d.  Length: %d.   Maximum No. of Payments: %d.\n"
					   " Completed No. of Payments: %d.  Failed No. of Payments: %d\n"
					   " Date of last payment: %d        Date of last failed payment: %d\n",
					   m_lPaymentPlanAmount,	m_tTimeBetweenPayments,
					   m_tPaymentPlanStartDate,	m_tPaymentPlanLength, m_nMaximumNoPayments,
					   m_nNoPaymentsDone,		m_nNoFailedPayments,
					   m_tDateOfLastPayment,	m_tDateOfLastFailedPayment);
		
		nReturnVal = 1;
	}
        
	return nReturnVal;
}






void OTPaymentPlan::UpdateContents()
{
	// I release this because I'm about to repopulate it.
	m_xmlUnsigned.Release();
	
	m_xmlUnsigned.Concatenate("<?xml version=\"%s\"?>\n\n", "1.0");		
	
	// -------------------------------------------------------------

	const OTString	SERVER_ID(GetServerID()),					ASSET_TYPE_ID(GetAssetID()), 
					SENDER_ACCT_ID(GetSenderAcctID()),			SENDER_USER_ID(GetSenderUserID()),
					RECIPIENT_ACCT_ID(GetRecipientAcctID()),	RECIPIENT_USER_ID(GetRecipientUserID());
	
    // OTAgreement
	m_xmlUnsigned.Concatenate("<agreement\n version=\"%s\"\n"
							  " serverID=\"%s\"\n"
							  " assetTypeID=\"%s\"\n"
							  " senderAcctID=\"%s\"\n"
							  " senderUserID=\"%s\"\n"
							  " recipientAcctID=\"%s\"\n"
							  " recipientUserID=\"%s\"\n"
							  " transactionNum=\"%ld\"\n"
							  " creationDate=\"%d\"\n"
							  " validFrom=\"%d\"\n"
							  " validTo=\"%d\""							  
							  " >\n\n", 
							  m_strVersion.Get(),
							  SERVER_ID.Get(),
							  ASSET_TYPE_ID.Get(), 
							  SENDER_ACCT_ID.Get(),
							  SENDER_USER_ID.Get(),
							  RECIPIENT_ACCT_ID.Get(),
							  RECIPIENT_USER_ID.Get(),
							  m_lTransactionNum,
							  GetCreationDate(), GetValidFrom(), GetValidTo() );	
    
	// -------------------------------------------------------------
    
    // There are "closing" transaction numbers, used to CLOSE a transaction.
    // Often where Cron items are involved such as this payment plan, or in baskets,
    // where many asset accounts are involved and require receipts to be closed out.
    
    // OTCronItem
    for (int i = 0; i < GetCountClosingNumbers(); i++)
    {
        long lClosingNumber = GetClosingTransactionNoAt(i);
        OT_ASSERT(lClosingNumber > 0);
        
        m_xmlUnsigned.Concatenate("<closingTransactionNumber value=\"%ld\"/>\n\n",
                                  lClosingNumber);
        
    }
    
    // OTAgreement
    // For the recipient, his OPENING *and* CLOSING transaction numbers go on
    // this list. (For sender, the "opening" number is the GetTransactionNum()
    // on this object, and the "closing" number is in the above list.)
    for (int i = 0; i < GetRecipientCountClosingNumbers(); i++)
    {
        long lClosingNumber = GetRecipientClosingTransactionNoAt(i);
        OT_ASSERT(lClosingNumber > 0);
        
        m_xmlUnsigned.Concatenate("<closingRecipientNumber value=\"%ld\"/>\n\n",
                                  lClosingNumber);
        
    }
    
	// -------------------------------------------------------------
    // OTPaymentPlan
    
	if (HasInitialPayment())
	{
		const time_t	tInitialPaymentDate			= GetInitialPaymentDate();
		const long		lAmount						= GetInitialPaymentAmount();
		const int		nNumberOfFailedAttempts		= GetNoInitialFailures();
		const time_t	tFailedInitialPaymentDate	= GetLastFailedInitialPaymentDate();
		const time_t	tCompletedInitialPaymentDate= GetInitialPaymentCompletedDate();
		
		m_xmlUnsigned.Concatenate("<initialPayment\n"
								  " date=\"%d\"\n"
								  " amount=\"%ld\"\n"
								  " numberOfAttempts=\"%d\"\n"
								  " dateOfLastAttempt=\"%d\"\n"
								  " dateCompleted=\"%d\"\n"
								  " completed=\"%s\""
								  " />\n\n", 
								  tInitialPaymentDate, 
								  lAmount,
								  nNumberOfFailedAttempts,
								  tFailedInitialPaymentDate,
								  tCompletedInitialPaymentDate,
								  (IsInitialPaymentDone() ? "true" : "false"));								  		
	}
	
	
	// -------------------------------------------------------------
    // OTPaymentPlan
		
	if (HasPaymentPlan())
	{
		const long	lAmountPerPayment		= GetPaymentPlanAmount(),
					lTimeBetween			= GetTimeBetweenPayments(),
					lPlanStartDate			= GetPaymentPlanStartDate(),
					lPlanLength				= GetPaymentPlanLength(),
					lDateOfLastPayment		= GetDateOfLastPayment(),
					lDateOfLastFailedPayment= GetDateOfLastPayment();
		
		const int	nMaxNoPayments		= GetMaximumNoPayments(),
					nNoPaymentsComplete	= GetNoPaymentsDone(),
					nNoFailedPayments	= GetNoFailedPayments();
		
		m_xmlUnsigned.Concatenate("<paymentPlan\n"
								  " amountPerPayment=\"%ld\"\n"
								  " timeBetweenPayments=\"%ld\"\n"
								  " planStartDate=\"%ld\"\n"
								  " planLength=\"%ld\"\n"
								  " maxNoPayments=\"%d\"\n"
								  " completedNoPayments=\"%d\"\n"
								  " failedNoPayments=\"%d\"\n"
								  " dateOfLastPayment=\"%ld\"\n"							  
								  " dateOfLastFailedPayment=\"%ld\""							  
								  " />\n\n", 
								  lAmountPerPayment,
								  lTimeBetween,
								  lPlanStartDate,
								  lPlanLength,
								  nMaxNoPayments,
								  nNoPaymentsComplete,
								  nNoFailedPayments,
								  lDateOfLastPayment,
								  lDateOfLastFailedPayment
								  );
	}
		
	// -------------------------------------------------------------
    // OTAgreement
	
    if (m_strConsideration.Exists())
	{
		OTASCIIArmor ascTemp(m_strConsideration);		
		m_xmlUnsigned.Concatenate("<consideration>\n%s</consideration>\n\n", ascTemp.Get());
	}
	
	// -------------------------------------------------------------
	// OTAgreement
    
    if (m_strMerchantSignedCopy.Exists())
	{
		OTASCIIArmor ascTemp(m_strMerchantSignedCopy);		
		m_xmlUnsigned.Concatenate("<merchantSignedCopy>\n%s</merchantSignedCopy>\n\n", ascTemp.Get());
	}
	
	// -------------------------------------------------------------

	m_xmlUnsigned.Concatenate("</agreement>\n");					
}








// --------------------------------------------------------------------------
// *** Set Initial Payment ***  / Make sure to call SetAgreement() first.


bool OTPaymentPlan::SetInitialPayment(const long & lAmount, time_t tTimeUntilInitialPayment/*=0*/)
{
	m_bInitialPayment		= true; // There is now an initial payment.
	m_bInitialPaymentDone	= false;// It has not yet been paid.
	
	// The initial date passed it is measured relative to the creation date.
	// (Assumes SetAgreement() was already called...)
	const time_t INITIAL_PAYMENT_DATE = GetCreationDate() + tTimeUntilInitialPayment;
	
	SetInitialPaymentDate(INITIAL_PAYMENT_DATE);
	
	SetInitialPaymentAmount(lAmount);
	
	return true;
}



bool OTPaymentPlan::Compare(const OTAgreement & rhs) const
{
    if (false == OTAgreement::Compare(rhs))
        return false;
    
    // Compare OTPaymentPlan specific info here.
    const OTPaymentPlan * pPlan = dynamic_cast<const OTPaymentPlan *>(&rhs);
  
    if (
        (NULL != pPlan) &&
        // --------------------------------------------------------------------
        (HasInitialPayment()        == pPlan->HasInitialPayment())          &&
        (GetInitialPaymentDate()    == pPlan->GetInitialPaymentDate())      &&
        (GetInitialPaymentAmount()  == pPlan->GetInitialPaymentAmount())    &&
        // --------------------------------------------------------------------
        (HasPaymentPlan()           == pPlan->HasPaymentPlan())             &&
        (GetPaymentPlanAmount()     == pPlan->GetPaymentPlanAmount())       &&
        (GetTimeBetweenPayments()   == pPlan->GetTimeBetweenPayments())     &&
        (GetPaymentPlanStartDate()  == pPlan->GetPaymentPlanStartDate())    &&
        (GetPaymentPlanLength()     == pPlan->GetPaymentPlanLength())       &&
        (GetMaximumNoPayments()     == pPlan->GetMaximumNoPayments())
       )
        return true;
    
    return false;
}


// This function assumes that it is the customer's copy, with the customer's transaction numbers,
// and that the merchant's copy is attached within. The function tries to verify they are the same,
// and properly signed.
bool OTPaymentPlan::VerifyAgreement(OTPseudonym & RECIPIENT_NYM, OTPseudonym & SENDER_NYM)
{    
    // Load up the merchant's copy.
    OTPaymentPlan theMerchantCopy;
    if (!m_strMerchantSignedCopy.Exists() || !theMerchantCopy.LoadContractFromString(m_strMerchantSignedCopy))
    {
        OTLog::Error("OTPaymentPlan::VerifyAgreement: Expected Merchant's signed copy to be inside the "
                     "payment plan, but unable to load.\n");
        return false;
    }
    
    // Compare this against the merchant's copy using Compare function.
    if (!this->Compare(theMerchantCopy))
    {
        OTLog::Output(0, "OTPaymentPlan::VerifyAgreement: Merchant's copy of payment plan isn't equal to Customer's copy.\n");
        return false;
    }

    const OTString strServerID(GetServerID());
    
    // Verify Transaction Num and Closing Nums against SENDER's issued list
    if ((GetCountClosingNumbers() < 1) || !SENDER_NYM.VerifyIssuedNum(strServerID, GetTransactionNum()))
    {
        OTLog::Error("OTPaymentPlan::VerifyAgreement: Transaction number isn't on sender's issued list, "
                     "or there weren't enough closing numbers.\n");
        return false;
    }
    for (int i = 0; i < GetCountClosingNumbers(); i++)
        if (!SENDER_NYM.VerifyIssuedNum(strServerID, GetClosingTransactionNoAt(i)))
        {
            OTLog::Error("OTPaymentPlan::VerifyAgreement: Closing transaction number isn't on sender's issued list.\n");
            return false;
        }
    // --------------------------------------------------------------------------
    // Verify Recipient closing numbers against RECIPIENT's issued list.
    if (GetRecipientCountClosingNumbers() < 2)
    {
        OTLog::Error("OTPaymentPlan::VerifyAgreement: Expected 2 closing transaction numbers for recipient.\n");
        return false;
    }
    for (int i = 0; i < GetRecipientCountClosingNumbers(); i++)
        if (!SENDER_NYM.VerifyIssuedNum(strServerID, GetRecipientClosingTransactionNoAt(i)))
        {
            OTLog::Error("OTPaymentPlan::VerifyAgreement: Recipient's Closing transaction number isn't on recipient's issued list.\n");
            return false;
        }

    // Verify sender's signature on this.
    if (!this->VerifySignature(SENDER_NYM))
    {
        OTLog::Output(0, "OTPaymentPlan::VerifyAgreement: Sender's signature failed to verify.\n");
        return false;
    }

    // Verify recipient's signature on merchant's copy.
    // Verify sender's signature on this.
    if (!theMerchantCopy.VerifySignature(RECIPIENT_NYM))
    {
        OTLog::Output(0, "OTPaymentPlan::VerifyAgreement: Recipient's signature failed to verify on internal merchant copy of agreement.\n");
        return false;
    }
    
    return true; // Success!
}







// --------------------------------------------------------------------------
// *** Set Payment Plan *** / Make sure to call SetAgreement() first.
																// default: 1st payment in 30 days
bool OTPaymentPlan::SetPaymentPlan(const long & lPaymentAmount, time_t tTimeUntilPlanStart/*=2592000*/, 
								   time_t tBetweenPayments/*=2592000*/, // Default: 30 days.
								   time_t tPlanLength/*=0*/, int nMaxPayments/*=0*/)
{		
	// -----------------------------------------
	
	if (lPaymentAmount <= 0 )
	{
		OTLog::Error("Payment Amount less than zero in OTPaymentPlan::SetPaymentPlan\n");
		return false;
	}
	
	SetPaymentPlanAmount(lPaymentAmount);
	
	// -----------------------------------------
	
	// Note: this is just a safety mechanism. And while it should be turned back ON at some point,
	//       I need it off for testing at the moment. So if you're reading this now, go ahead and
	//       uncomment the below code so it is functional again.
	
//	if (tBetweenPayments < LENGTH_OF_DAY_IN_SECONDS) // If the time between payments is set to LESS than a 24-hour day,
//		tBetweenPayments = LENGTH_OF_DAY_IN_SECONDS; // then set the minimum time to 24 hours. This is a safety mechanism.
	if (tBetweenPayments < 10) // Every 10 seconds (still need some kind of standard, even while testing.)
		tBetweenPayments = 10; // TODO: Remove this and uncomment the above code.
	// TODO possible make it possible to configure this in the currency contract itself.
	
	SetTimeBetweenPayments(tBetweenPayments);
	
	// -----------------------------------------
	
	// Assuming no need to check a time_t for <0 since it's probably unsigned...
	const time_t PAYMENT_PLAN_START = GetCreationDate() + tTimeUntilPlanStart;
	
	SetPaymentPlanStartDate(PAYMENT_PLAN_START);
	
	// -----------------------------------------
	
	// Is this even a problem? todo: verify that time_t is unisigned.
	if (0 > tPlanLength) // if it's a negative number...
	{
		OTLog::Error("Attempt to use negative number for plan length.\n");
		return false;
	}
	
	SetPaymentPlanLength(tPlanLength); // any zero (no expiry) or above-zero value will do.
	
	// -----------------------------------------
	
	if (0 > nMaxPayments) // if it's a negative number...
	{
		OTLog::Error("Attempt to use negative number for plan max payments.\n");
		return false;
	}
	
	SetMaximumNoPayments(nMaxPayments); // any zero (no expiry) or above-zero value will do.

	// -----------------------------------------
	
	// Set these to zero, they will be incremented later at the right times.
	m_tDateOfLastPayment	= 0;
	m_nNoPaymentsDone		= 0;

	// Okay, we're a payment plan! (Still need to add the object to OTCron... But it's ready...)
	m_bPaymentPlan			= true;

	return true;
}




OTPaymentPlan::OTPaymentPlan() : OTAgreement(), m_bProcessingInitialPayment(false), m_bProcessingPaymentPlan(false)
{
	InitPaymentPlan();
}


OTPaymentPlan::OTPaymentPlan(const OTIdentifier & SERVER_ID, const OTIdentifier & ASSET_ID) :
				OTAgreement(SERVER_ID, ASSET_ID), m_bProcessingInitialPayment(false), m_bProcessingPaymentPlan(false)
{
	InitPaymentPlan();
}


OTPaymentPlan::OTPaymentPlan(const OTIdentifier & SERVER_ID,			const OTIdentifier & ASSET_ID,
							 const OTIdentifier & SENDER_ACCT_ID,		const OTIdentifier & SENDER_USER_ID,
							 const OTIdentifier & RECIPIENT_ACCT_ID,	const OTIdentifier & RECIPIENT_USER_ID) :
					OTAgreement(SERVER_ID, ASSET_ID, 
                                SENDER_ACCT_ID, SENDER_USER_ID, RECIPIENT_ACCT_ID, RECIPIENT_USER_ID), m_bProcessingInitialPayment(false), m_bProcessingPaymentPlan(false)
{
	InitPaymentPlan();
}


bool OTPaymentPlan::SetInitialPaymentDone()
{
	if (m_bInitialPaymentDone) // if done already.
		return false;
	
	m_bInitialPaymentDone = true;
	// We store the bool that it's done (above), and we also store the date when it was done:
	SetInitialPaymentCompletedDate(GetCurrentTime());
	
	return true;
}



// TODO: Run a scanner on the code for memory leaks and buffer overflows.





// This can be called by either the initial payment code, or by the payment plan code.
// true == success, false == failure.
//
bool OTPaymentPlan::ProcessPayment(const long & lAmount)
{	
	const OTCron * pCron = GetCron();
	OT_ASSERT(NULL != pCron);
	
	OTPseudonym * pServerNym = pCron->GetServerNym();
	OT_ASSERT(NULL != pServerNym);

	
	bool bSuccess = false;	// The return value.

	
	const OTIdentifier		SERVER_ID(pCron->GetServerID());
	const OTIdentifier		SERVER_USER_ID(*pServerNym);
	
	const OTIdentifier &	SOURCE_ACCT_ID		= GetSenderAcctID();
	const OTIdentifier &	SENDER_USER_ID		= GetSenderUserID();
	
	const OTIdentifier &	RECIPIENT_ACCT_ID	= GetRecipientAcctID();
	const OTIdentifier &	RECIPIENT_USER_ID	= GetRecipientUserID();
	
	
	OTString	strSenderUserID(SENDER_USER_ID), strRecipientUserID(RECIPIENT_USER_ID),
				strSourceAcctID(SOURCE_ACCT_ID), strRecipientAcctID(RECIPIENT_ACCT_ID);
	
	
	// Make sure they're not the same Account IDs ...
	// Otherwise we would have to take care not to load them twice, like with the Nyms below.
	// (Instead I just disallow it entirely.)
	if (SOURCE_ACCT_ID == RECIPIENT_ACCT_ID)
	{
		OTLog::Output(0, "Failed to process payment: both account IDs were identical.\n");
		FlagForRemoval(); // Remove from Cron
		return false; // TODO: should have a "Verify Payment Plan" function that weeds this crap out before we even get here.
	}
	// When the accounts are actually loaded up, then we should also compare
	// the asset types to make sure they were what we expected them to be.
	
	
	// -----------------------------------------------------------------
	
	// Need to load up the ORIGINAL PAYMENT PLAN (with BOTH users' original SIGNATURES on it!)
	// Will need to verify those signatures as well as attach a copy of it to the receipt.
	
	OTCronItem * pOrigCronItem	= NULL;
	
	// OTCronItem::LoadCronReceipt loads the original version with the user's signature.
	// (Updated versions, as processing occurs, are signed by the server.)
	pOrigCronItem		= OTCronItem::LoadCronReceipt(GetTransactionNum());
	
	OT_ASSERT(NULL != pOrigCronItem);	// How am I processing it now if the receipt wasn't saved in the first place??
									// TODO: Decide global policy for handling situations where the hard drive stops working, etc.
	
	// When theOrigPlanGuardian goes out of scope, pOrigCronItem gets deleted automatically.
	OTCleanup<OTCronItem>	theOrigPlanGuardian(*pOrigCronItem);
		
	// strOrigPlan is a String copy (a PGP-signed XML file, in string form) of the original Payment Plan request...
	OTString strOrigPlan(*pOrigCronItem); // <====== Farther down in the code, I attach this string to the receipts.
	
	
	// Make sure to clean these up.
//	delete pOrigCronItem;		// theOrigPlanGuardian will handle this now, whenever it goes out of scope.
//	pOrigCronItem = NULL;		// So I don't need to worry about deleting this anymore. I can keep it around and
							// use it all I want, and return anytime, and it won't leak.
	

	
	// -------------- Make sure have both nyms loaded and checked out. --------------------------------------------------
	// WARNING: 1 or both of the Nyms could be also the Server Nym. They could also be the same Nym, but NOT the Server.
	// In all of those different cases, I don't want to load the same file twice and overwrite it with itself, losing
	// half of all my changes. I have to check all three IDs carefully and set the pointers accordingly, and then operate
	// using the pointers from there.
	
	
	OTPseudonym theSenderNym, theRecipientNym; // We MIGHT use ONE, OR BOTH, of these, or none. (But probably both.)
	
	// Find out if either Nym is actually also the server.
	bool bSenderNymIsServerNym		= ((SENDER_USER_ID		== SERVER_USER_ID) ? true : false);
	bool bRecipientNymIsServerNym	= ((RECIPIENT_USER_ID	== SERVER_USER_ID) ? true : false);
	
	// We also see, after all that is done, whether both pointers go to the same entity. 
	// (We'll want to know that later.)
	bool bUsersAreSameNym			= ((SENDER_USER_ID == RECIPIENT_USER_ID) ? true : false);
	
	OTPseudonym * pSenderNym		= NULL;
	OTPseudonym * pRecipientNym		= NULL;

	// Figure out if Sender Nym is also Server Nym.
	if (bSenderNymIsServerNym)		
	{
		// If the First Nym is the server, then just point to that.
		pSenderNym = pServerNym;
	}
	else	// Else load the First Nym from storage.
	{
		theSenderNym.SetIdentifier(SENDER_USER_ID);  // theSenderNym is pSenderNym
		
		if (false == theSenderNym.LoadPublicKey())
		{
			OTString strNymID(SENDER_USER_ID);
			OTLog::vError("Failure loading Sender Nym public key in OTPaymentPlan::ProcessPayment: %s\n", 
						  strNymID.Get());
			FlagForRemoval(); // Remove it from future Cron processing, please.
			return false;
		}
		
		if (theSenderNym.VerifyPseudonym()	&&		
			theSenderNym.LoadSignedNymfile(*pServerNym)) // ServerNym here is not theSenderNym's identity, but merely the signer on this file.
		{
			pSenderNym = &theSenderNym; //  <=====
		}
		else 
		{
			OTString strNymID(SENDER_USER_ID);
			OTLog::vError("Failure loading or verifying Sender Nym public key in OTPaymentPlan::ProcessPayment: %s\n", 
						  strNymID.Get());
			FlagForRemoval(); // Remove it from future Cron processing, please.
			return false;			
		}
	}
	
	
	// Next, we also find out if Recipient Nym is Server Nym...
	if (bRecipientNymIsServerNym)		
	{
		// If the Recipient Nym is the server, then just point to that.
		pRecipientNym = pServerNym;
	}
	else if (bUsersAreSameNym)	// Else if the participants are the same Nym, point to the one we already loaded. 
	{
		pRecipientNym = pSenderNym; // theSenderNym is pSenderNym
	}
	else	// Otherwise load the Other Nym from Disk and point to that.
	{
		theRecipientNym.SetIdentifier(RECIPIENT_USER_ID);
		
		if (false == theRecipientNym.LoadPublicKey())
		{
			OTString strNymID(RECIPIENT_USER_ID);
			OTLog::vError("Failure loading Recipient Nym public key in OTPaymentPlan::ProcessPayment: %s\n", 
						  strNymID.Get());
			FlagForRemoval(); // Remove it from future Cron processing, please.
			return false;
		}
		
		if (theRecipientNym.VerifyPseudonym()	&& 
			theRecipientNym.LoadSignedNymfile(*pServerNym))
		{
			pRecipientNym = &theRecipientNym; //  <=====
		}
		else 
		{
			OTString strNymID(RECIPIENT_USER_ID);
			OTLog::vError("Failure loading or verifying Recipient Nym public key in OTPaymentPlan::ProcessPayment: %s\n", 
						  strNymID.Get());
			FlagForRemoval(); // Remove it from future Cron processing, please.
			return false;			
		}
	}
	
	
	// -----------------------------------------------------------------

	
	// Now that I have the original Payment Plan loaded, and all the Nyms ready to go,
	// let's make sure that BOTH the nyms in question have SIGNED the original request.
	// (Their signatures wouldn't be on the updated version in Cron--the server signs
	// that one.)
	
	if (!pOrigCronItem->VerifySignature(*pSenderNym) || !pOrigCronItem->VerifySignature(*pRecipientNym))
	{
		OTLog::Error("Failed authorization: Payment plan (while attempting to process...)\n");
		FlagForRemoval(); // Remove it from Cron.
		return false;			
	}
	
	
	// AT THIS POINT, I have pServerNym, pSenderNym, and pRecipientNym. 
	// ALL are loaded from disk (where necessary.) AND...
	// ALL are valid pointers, (even if they sometimes point to the same object,)
	// AND none are capable of overwriting the storage of the other (by accidentally
	// loading the same storage twice.)
	// We also have boolean variables at this point to tell us exactly which are which,
	// (in case some of those pointers do go to the same object.) 
	// They are:
	// bSenderNymIsServerNym, bRecipientNymIsServerNym, and bUsersAreSameNym.
	//
	// I also have pOrigCronItem, which is a dynamically-allocated copy of the original
	// Cron Receipt for this Payment Plan. (And I don't need to worry about deleting it, either.)
	// I know for a fact they have both signed pOrigCronItem...

	// -----------------------------------------------------------------
	
	OTAccount * pSourceAcct		= OTAccount::LoadExistingAccount(SOURCE_ACCT_ID, SERVER_ID);
	
	if (NULL == pSourceAcct)
	{
		OTLog::Output(0, "ERROR verifying existence of source account during attempted payment plan processing.\n");
		FlagForRemoval(); // Remove it from future Cron processing, please.
		return false;
	}
	// Past this point we know pSourceAcct is good and will clean itself up.
	OTCleanup<OTAccount>	theSourceAcctSmrtPtr(*pSourceAcct);
	// -----------------------------------------------------------------

	OTAccount * pRecipientAcct	= OTAccount::LoadExistingAccount(RECIPIENT_ACCT_ID,	SERVER_ID);

	if (NULL == pRecipientAcct)
	{
		OTLog::Output(0, "ERROR verifying existence of recipient account during attempted payment plan processing.\n");
		FlagForRemoval(); // Remove it from future Cron processing, please.
		return false;
	}
	// Past this point we know pRecipientAcct is good and will clean itself up.
	OTCleanup<OTAccount>	theRecipAcctSmrtPtr(*pRecipientAcct);
	// -----------------------------------------------------------------
	
	
	// BY THIS POINT, both accounts are successfully loaded, and I don't have to worry about
	// cleaning either one of them up, either. But I can now use pSourceAcct and pRecipientAcct...
	//
	//
	// -----------------------------------------------------------------------------------
	
	// A few verification if/elses...
	
	// Are both accounts of the same Asset Type?
	if (pSourceAcct->GetAssetTypeID() != pRecipientAcct->GetAssetTypeID())
	{	// We already know the SUPPOSED Asset IDs of these accounts... But only once
		// the accounts THEMSELVES have been loaded can we VERIFY this to be true.
		OTLog::Output(0, "ERROR - attempted payment between accounts of different "
					  "asset types in OTPaymentPlan::ProcessPayment\n");
		FlagForRemoval(); // Remove it from future Cron processing, please.
		return false;
	}
	
	// Make sure all accounts are signed by the server and have the owner they are expected to have.
	
	// I call VerifySignature here since VerifyContractID was already called in LoadExistingAccount().
	else if (!pSourceAcct->VerifyOwner(*pSenderNym) || !pSourceAcct->VerifySignature(*pServerNym) )
	{
		OTLog::Output(0, "ERROR verifying ownership or signature on source account in OTPaymentPlan::ProcessPayment\n");
		FlagForRemoval(); // Remove it from future Cron processing, please.
		return false;
	}
	
	else if (!pRecipientAcct->VerifyOwner(*pRecipientNym) || !pRecipientAcct->VerifySignature(*pServerNym) )
	{
		OTLog::Output(0, "ERROR verifying ownership or signature on recipient account in OTPaymentPlan::ProcessPayment\n");
		FlagForRemoval(); // Remove it from future Cron processing, please.
		return false;
	}
	
	// By this point, I know I have both accounts loaded, and I know that they have the right asset types,
	// and I know they have the right owners and they were all signed by the server.
	// I also know that their account IDs in their internal records matched the account filename for each acct.
	// I also have pointers to the Nyms who own these accounts.
	
	else 
	{			
		// Okay then, everything checks out. Let's add a receipt to the sender's outbox and the recipient's inbox. 
		// IF they can be loaded up from file, or generated, that is. 
		
		// Load the inbox/outbox in case they already exist
		OTLedger	theSenderInbox		(SENDER_USER_ID,	SOURCE_ACCT_ID,		SERVER_ID),
					theRecipientInbox	(RECIPIENT_USER_ID, RECIPIENT_ACCT_ID,	SERVER_ID);
		
		// ALL inboxes -- no outboxes. All will receive notification of something ALREADY DONE.
		bool bSuccessLoadingSenderInbox		= theSenderInbox.LoadInbox();
		bool bSuccessLoadingRecipientInbox	= theRecipientInbox.LoadInbox();
		
		// --------------------------------------------------------------------
		
		// ...or generate them otherwise...
		
		if (true == bSuccessLoadingSenderInbox)
			bSuccessLoadingSenderInbox		= theSenderInbox.VerifyAccount(*pServerNym);
		else
			bSuccessLoadingSenderInbox		= theSenderInbox.GenerateLedger(SOURCE_ACCT_ID, SERVER_ID, OTLedger::inbox, true); // bGenerateFile=true
		
		if (true == bSuccessLoadingRecipientInbox)
			bSuccessLoadingRecipientInbox		= theRecipientInbox.VerifyAccount(*pServerNym);
		else
			bSuccessLoadingRecipientInbox		= theRecipientInbox.GenerateLedger(RECIPIENT_ACCT_ID, SERVER_ID, OTLedger::inbox, true); // bGenerateFile=true
				
		// --------------------------------------------------------------------
		
		if ((false == bSuccessLoadingSenderInbox)	|| 
			(false == bSuccessLoadingRecipientInbox))
		{
			OTLog::Error("ERROR loading or generating inbox ledger in OTPaymentPlan::ProcessPayment.\n");
		}
		else 
		{
			// Generate new transaction numbers for these new transactions
			long lNewTransactionNumber = GetCron()->GetNextTransactionNumber();
			
//			OT_ASSERT(lNewTransactionNumber > 0); // this can be my reminder.			
			if (0 == lNewTransactionNumber)
			{
				OTLog::Output(0, "WARNING: Payment plan is unable to process because there are no more transaction numbers available.\n");
				// (Here I do NOT flag for removal.)
				return false; 			
			}
			
			OTTransaction * pTransSend		= OTTransaction::GenerateTransaction(theSenderInbox, 
																			 OTTransaction::paymentReceipt, lNewTransactionNumber);
			
			OTTransaction * pTransRecip		= OTTransaction::GenerateTransaction(theRecipientInbox, 
																			 OTTransaction::paymentReceipt, lNewTransactionNumber);
			
			// (No need to OT_ASSERT on the above transactions since it occurs in GenerateTransaction().)
			
			
			// Both inboxes will get receipts with the same (new) transaction ID on them.
			// They will have a "In reference to" field containing the original payment plan
			// (with user's signature).
			
			// set up the transaction items (each transaction may have multiple items... but not in this case.)
			OTItem * pItemSend		= OTItem::CreateItemFromTransaction(*pTransSend, OTItem::paymentReceipt);
			OTItem * pItemRecip		= OTItem::CreateItemFromTransaction(*pTransRecip, OTItem::paymentReceipt);
			
			// these may be unnecessary, I'll have to check CreateItemFromTransaction. I'll leave em.
			OT_ASSERT(NULL != pItemSend);	
			OT_ASSERT(NULL != pItemRecip);
			
			pItemSend->SetStatus(OTItem::rejection); // the default.
			pItemRecip->SetStatus(OTItem::rejection); // the default.
			
			
			// Here I make sure that each receipt (each inbox notice) references the original
			// transaction number that was used to set the payment plan into place...
			// This number is used to track all cron items. (All Cron items require a transaction 
			// number from the user in order to add them to Cron in the first place.)
			// 
			// The number is also used to uniquely identify all other transactions, as you
			// might guess from its name.
			pTransSend->SetReferenceToNum(GetTransactionNum());
			pTransRecip->SetReferenceToNum(GetTransactionNum());
			
			
			// The TRANSACTION (a receipt in my inbox) will be sent with "In Reference To" information
            // containing the ORIGINAL SIGNED PLAN. (With both parties' original signatures on it.)
			//
			// Whereas the TRANSACTION ITEM will include an "attachment" containing the UPDATED
			// PLAN (this time with the SERVER's signature on it.)
			//
			// Here's the original one going onto the transaction:
			//
			pTransSend->SetReferenceString(strOrigPlan);
			pTransRecip->SetReferenceString(strOrigPlan);

			
			
			
			
			// --------------------------------------------------------------------------
			
			// MOVE THE DIGITAL ASSETS FROM ONE ACCOUNT TO ANOTHER...
			
			// Calculate the amount and debit/ credit the accounts
			// Make sure each Account can afford it, and roll back in case of failure.
			
			bool bMoveSender	= false;
			bool bMoveRecipient = false;
			
			// Make sure he can actually afford it...
			if (pSourceAcct->GetBalance() >= lAmount)
			{
				// Debit the source account. 
				bMoveSender	= pSourceAcct->Debit(lAmount); // <====== DEBIT FUNDS
				
				// IF success, credit the recipient.
				if (bMoveSender)
				{
					bMoveRecipient	= pRecipientAcct->Credit(lAmount); // <=== CREDIT FUNDS
					
					// Okay, we already took it from the source account.
					// But if we FAIL to credit the recipient, then we need to PUT IT BACK in the source acct.
					// (EVEN THOUGH we'll just "NOT SAVE" after any failure, so it's really superfluous.)
					//
					if (!bMoveRecipient)
						pSourceAcct->Credit(lAmount); // put the money back
					else
						bSuccess = true;
				}
				
				// If ANY of these failed, then roll them all back and break.
				if (!bMoveSender || !bMoveRecipient)
				{
					OTLog::Error("Very strange! Funds were available but debit or credit failed while performing payment.\n");
					// We won't save the files anyway, if this failed. 					
					bSuccess = false;
				}				
			}
			
			
			
			// --------------------------------------------------------------------------

			
			
			
			
			// DO NOT SAVE ACCOUNTS if bSuccess is false.
			// We only save these accounts if bSuccess == true.
			// (But we do save the inboxes either way, since payment failures always merit an inbox notice.)
			
			if (true == bSuccess) // The payment succeeded.
			{
				// Both accounts involved need to get a receipt of this trade in their inboxes...
				pItemSend->SetStatus(OTItem::acknowledgement); // pSourceAcct		
				pItemRecip->SetStatus(OTItem::acknowledgement); // pRecipientAcct
								
				pItemSend->SetAmount(lAmount*(-1));	// "paymentReceipt" is otherwise ambigious about whether you are paying or being paid.
				pItemRecip->SetAmount(lAmount);		// So, I decided for payment and market receipts, to use negative and positive amounts.
													// I will probably do the same for cheques, since they can be negative as well (invoices).
				
				if (m_bProcessingInitialPayment) // if this is a success for an initial payment
				{
					SetInitialPaymentDone();	
					OTLog::Output(3, "Initial payment performed in OTPaymentPlan::ProcessPayment\n");
				}
				else if (m_bProcessingPaymentPlan) // if this is a success for payment plan payment.
				{
					IncrementNoPaymentsDone();	
					SetDateOfLastPayment(GetCurrentTime());
					OTLog::Output(3, "Payment plan payment performed in OTPaymentPlan::ProcessPayment\n");
				}
				
				// (I do NOT save m_pCron here, since that already occurs after this function is called.)
			}
			else // bSuccess = false.  The payment failed.
			{
				pItemSend->SetStatus(OTItem::rejection);// pSourceAcct		// These are already initialized to false.
				pItemRecip->SetStatus(OTItem::rejection);// pRecipientAcct	// (But just making sure...)

				pItemSend->SetAmount(0);		// No money changed hands. Just being explicit.
				pItemRecip->SetAmount(0);		// No money changed hands. Just being explicit.		

				if (m_bProcessingInitialPayment)
				{
					IncrementNoInitialFailures();
					SetLastFailedInitialPaymentDate(GetCurrentTime());
					OTLog::Output(3, "Initial payment failed in OTPaymentPlan::ProcessPayment\n");
				}
				else if (m_bProcessingPaymentPlan)
				{
					IncrementNoFailedPayments();
					SetDateOfLastFailedPayment(GetCurrentTime());
					OTLog::Output(3, "Payment plan payment failed in OTPaymentPlan::ProcessPayment\n");
				}
			}
			
			// Everytime a payment processes, a receipt is put in the user's inbox, containing a
			// CURRENT copy of the payment plan (which took just money from the user's acct, or not,
			// and either way thus updated its status -- so its internal data has changed.)
			//
			// It will also contain a copy of the user's ORIGINAL signed payment plan, where the data
			// has NOT changed, (so the user's original signature is still good.)
			//
			// In order for it to export the RIGHT VERSION of the CURRENT plan, which has just changed
			// (above), then I need to re-sign it and save it first. (The original version I'll load from
			// a separate file using OTCronItem::LoadCronReceipt(lTransactionNum). It has both original
			// signatures on it. Nice, eh?)
			
			
			this->ReleaseSignatures();
			this->SignContract(*pServerNym);
			this->SaveContract();
			
			
			// No need to save Cron here, since both caller functions call SaveCron() EVERY time anyway,
			// success or failure, rain or shine.
			//m_pCron->SaveCron(); // Cron is where I am serialized, so if Cron's not saved, I'm not saved.
			
			// -----------------------------------------------------------------
			//
			// EVERYTHING BELOW is just about notifying the users, by dropping the receipt in their
			// inboxes. The rest is done.  The accounts and inboxes will all be saved at the same time.
			//
			// The Payment Plan is entirely updated and saved by this point, and Cron will
			// also be saved in the calling function once we return (no matter what.)
			//
			// -----------------------------------------------------------------
			
			
			// Basically I load up both INBOXES, which are actually LEDGERS, and then I create
			// a new transaction, with a new transaction item, for each of the ledgers.
			// (That's where the receipt information goes.)
			// 
			
			
			
			// -----------------------------------------------------------------
			
			// The TRANSACTION will be sent with "In Reference To" information containing the
			// ORIGINAL SIGNED PLAN. (With both of the users' original signatures on it.)
			//
			// Whereas the TRANSACTION ITEM will include an "attachment" containing the UPDATED
			// PLAN (this time with the SERVER's signature on it.)
			
			// (Lucky I just signed and saved the updated plan (above), or it would still have 
			// have the old data in it.)
			
			// I also already loaded the original plan. Remember this from above,
			// near the top of the function:
			//  OTCronItem * pOrigCronItem	= NULL;
			// 	OTString strOrigPlan(*pOrigCronItem); // <====== Farther down in the code, I attach this string to the receipts.
			//  ... then lower down...
			// pTransSend->SetReferenceString(strOrigPlan);
			// pTransRecip->SetReferenceString(strOrigPlan);
			//
			// So the original plan is already loaded and copied to the Transaction as the "In Reference To" 
			// Field. Now let's add the UPDATED plan as an ATTACHMENT on the Transaction ITEM:
			//
			OTString	strUpdatedPlan(*this);
			
			// Set the updated plan as the attachment on the transaction item.
			// (With the SERVER's signature on it!)
			// (As a receipt for each trader, so they can see their offer updating.)
			pItemSend->SetAttachment(strUpdatedPlan);
			pItemRecip->SetAttachment(strUpdatedPlan);
			
			// -----------------------------------------------------------------
			
			
			// Success OR failure, either way I want a receipt in both inboxes.
			// But if FAILURE, I do NOT want to save the Accounts, JUST the inboxes.
			// So the inboxes happen either way, but the accounts are saved only on success.
			
			// sign the item
			pItemSend->SignContract(*pServerNym);
			pItemRecip->SignContract(*pServerNym);
			
			pItemSend->SaveContract();
			pItemRecip->SaveContract();
			
			// the Transaction "owns" the item now and will handle cleaning it up.
			pTransSend->AddItem(*pItemSend);
			pTransRecip->AddItem(*pItemRecip);
			
			pTransSend->SignContract(*pServerNym);
			pTransRecip->SignContract(*pServerNym);
			
			pTransSend->SaveContract();
			pTransRecip->SaveContract();

			// -------------------------------------------
			// Here, the transactions we just created are actually added to the ledgers.
			// This happens either way, success or fail.
			
			theSenderInbox.		AddTransaction(*pTransSend);
			theRecipientInbox.	AddTransaction(*pTransRecip);
			
			// -------------------------------------------

			// Release any signatures that were there before (They won't
			// verify anymore anyway, since the content has changed.)
			theSenderInbox.		ReleaseSignatures();
			theRecipientInbox.	ReleaseSignatures();
			
			// Sign both of them.				
			theSenderInbox.		SignContract(*pServerNym);
			theRecipientInbox.	SignContract(*pServerNym);
			
			// Save both of them internally
			theSenderInbox.		SaveContract();
			theRecipientInbox.	SaveContract();
						
			// Save both inboxes to storage. (File, DB, wherever it goes.)
			theSenderInbox.		SaveInbox();
			theRecipientInbox.	SaveInbox();
			
			// These correspond to the AddTransaction() calls just above. These are stored
			// in separate files now.
			//
			pTransSend->SaveBoxReceipt(theSenderInbox);
			pTransRecip->SaveBoxReceipt(theRecipientInbox);
			
			// If success, save the accounts with new balance. (Save inboxes with receipts either way,
			// and the receipts will contain a rejection or acknowledgment stamped by the Server Nym.)
			if (true == bSuccess)
			{					
				// -------------------------------------------
				// Release any signatures that were there before (They won't
				// verify anymore anyway, since the content has changed.)
				pSourceAcct->	ReleaseSignatures();	
				pRecipientAcct->ReleaseSignatures();	

				// Sign both of them.				
				pSourceAcct->	SignContract(*pServerNym);	
				pRecipientAcct->SignContract(*pServerNym);	

				// Save both of them internally
				pSourceAcct->	SaveContract();	
				pRecipientAcct->SaveContract();	

				// TODO: Better rollback capabilities in case of failures here:
				
				// Save both accounts to storage.
				pSourceAcct->	SaveAccount();	
				pRecipientAcct->SaveAccount();	
				
				// NO NEED TO LOG HERE, since success / failure is already logged above.
			}
		} // both inboxes were successfully loaded or generated.
	} // By the time we enter this block, accounts and nyms are already loaded. As we begin, inboxes are instantiated.
	
	return bSuccess;
}





// Assumes we're due for this payment. Execution oriented.
// NOTE: there used to be more to this function, but it ended up like this. Que sera sera.
void OTPaymentPlan::ProcessInitialPayment()
{
	OT_ASSERT(NULL != GetCron());

	m_bProcessingInitialPayment	= true;
	ProcessPayment(GetInitialPaymentAmount());
	m_bProcessingInitialPayment	= false;
	
	// No need to save the Payment Plan itself since it's already
	// saved inside the ProcessPayment() call as part of constructing the receipt.
	
		
	// Since this' data file is actually a blob as part of Cron, 
	// then we need to save Cron as well. Only then are these changes truly saved.
	// I'm actually lucky to even be able to save cron here, since I know for a fact
	// that I have to save no matter what. In cases where I don't know for sure, the
	// save call has to go a level deeper, since only there would the code know whether
	// or not something has actually changed.
	// HMM Todo: Look into adding a "DIRTY" field to OT objects.
	// Double-hmm, todo: I could make a series of macros for serializable member variables,
	// that would deal with all the xml read/write very compactly, and automatically track
	// whether the variable was dirty. Then anywhere in the code I can just ask an object
	// if it is dirty, or instruct it to update itself if it is.  Anyway, let's save Cron...
	
	GetCron()->SaveCron();
	
	// Todo: put the actual Cron items in separate files, so I don't have to update
	// the entire cron file every time an item changes. That way the main cron file
	// can just keep a record of the active items, and will change only when an item
	// is added or removed.
	//
	// Until then, the entire Cron file will have to save EVERY time this call happens.
	//
	// (I'll add something to Cron so it can't save more than once per second or something.) 
	// (DONE: Payment Plans process hourly and Trades process every 10 seconds.)
}



/*
// This is called by OTCronItem::HookRemovalFromCron
// (After calling this method, HookRemovalFromCron then calls onRemovalFromCron.)
//
void OTPaymentPlan::onFinalReceipt()
{
    
    OTAgreement::onFinalReceipt();
    
    // -----------------------------------------------------------
    
    // Not much done in this one.
    
    // -----------------------------------------------------------
    

    
}


// This is called by OTCronItem::HookRemovalFromCron
// (Before calling this method, HookRemovalFromCron first calls onFinalReceipt.)
//
void OTPaymentPlan::onRemovalFromCron()
{
    
    OTAgreement::onRemovalFromCron();
    
    // -----------------------------------------------------------

    // Not much done in this one.
    
    // -----------------------------------------------------------

}
*/






// Assumes we're due for a payment. Execution oriented.
// NOTE: There used to be more to this function, but it ended up like this. Que sera sera.
void OTPaymentPlan::ProcessPaymentPlan()
{	
	OT_ASSERT(NULL != GetCron());
	
	// This way the ProcessPayment() function knows what kind of payment we're processing.
	// Basically there's just one little spot in there where it needs to know.  :-(
	// But the member could be useful in the future anyway.
	m_bProcessingPaymentPlan	= true;
	ProcessPayment(GetPaymentPlanAmount());
	m_bProcessingPaymentPlan	= false;
    
	// No need to save the Payment Plan itself since it's already
	// saved inside the ProcessPayment() call as part of constructing the receipt.
    
	
	// Either way, Cron should save, since it just updated.
	// (The above function call WILL change this payment plan
	// and re-sign it and save it, no matter what. So I just 
	// call this here to keep it simple:
	
	GetCron()->SaveCron();
	
	// -----------------------------------------------------
}



// OTCron calls this regularly, which is my chance to expire, etc.
// Return True if I should stay on the Cron list for more processing.
// Return False if I should be removed and deleted.
bool OTPaymentPlan::ProcessCron()
{
	OT_ASSERT(NULL != GetCron());
	
	// -----------------------------------------------------------------
	// Right now Cron is called 10 times per second.
	// I'm going to slow down all trades so they are once every GetProcessInterval()
	if (GetLastProcessDate() > 0)
	{
//		OTLog::vOutput(3, "DEBUG: time: %d  Last process date: %d   Time since last: %d    Interval: %d\n",
//					   GetCurrentTime(), GetLastProcessDate(), (GetCurrentTime() - GetLastProcessDate()),
//					   GetProcessInterval());
		
		// (Default ProcessInternal is 1 second, but Trades will use 10 seconds,
		// and Payment Plans will use an hour or day.)
		if ((GetCurrentTime() - GetLastProcessDate()) <= GetProcessInterval())
			return true;
	}
	// Keep a record of the last time this was processed.
	// (NOT saved to storage, only used while the software is running.)
	// (Thus no need to release signatures, sign contract, save contract, etc.)
	SetLastProcessDate(GetCurrentTime());
	// -----------------------------------------------------------------
			
	// END DATE --------------------------------
	// First call the parent's version (which this overrides) so it has
	// a chance to check its stuff. 
    // Currently it calls OTCronItem::ProcessCron, which checks IsExpired().
    //
	if (false == OTAgreement::ProcessCron())
	{
		OTLog::Output(3, "Cron job has expired.\n");
		return false;	// It's expired or flagged for removal--remove it from Cron.
	}

	// START DATE --------------------------------
	// Okay, so it's not expired. But might not have reached START DATE yet...
	if (!VerifyCurrentDate())
		return true;	// The Payment Plan is not yet valid, so we return. BUT, we also 
						// return TRUE, so it will STAY on Cron until it BECOMES valid.
	
	
	// -----------------------------------------------------------------------------

	if (GetCron()->GetTransactionCount() < 1)
	{
		OTLog::Output(0, "Failed to process payment: Out of transaction numbers!\n");
		return true;	// If there aren't enough transaction numbers, this won't log
						// 10 times per second, but instead every hour or every day, 
	}					// since plans don't process any more often than that anyway.
	
	// -----------------------------------------------------------------------------

	// First process the initial payment...
	
	if (HasInitialPayment()								&&	// If I have an initial payment...
		!IsInitialPaymentDone()							&&	// and I have not yet processed it...
		(GetCurrentTime() > GetInitialPaymentDate())	&&	// and we're past the initial payment due date...
		((GetCurrentTime() - GetLastFailedInitialPaymentDate()) > LENGTH_OF_DAY_IN_SECONDS)) // and it's been more than a day since I last failed attmpting this...
	{	// THEN we're due for the initial payment! Process it!

		OTLog::Output(3, "Cron: Processing initial payment...\n");

		ProcessInitialPayment();
	}
	
	// -----------------------------------------------------------------------------

	
	// Next, process the payment plan...
	OTLog::vOutput(3, "(payment plan): Flagged/Removal: %s Has Plan: %s Current time: %d Start Date: %d\n",
				   (IsFlaggedForRemoval() ? "TRUE" : "FALSE"), (HasPaymentPlan() ? "TRUE" : "FALSE"), 
				   GetCurrentTime(), GetPaymentPlanStartDate());
	if (!IsFlaggedForRemoval() && HasPaymentPlan() &&		// This object COULD have gotten flagged for removal during the ProcessInitialPayment()
		(GetCurrentTime() > GetPaymentPlanStartDate()))		// call. Therefore, I am sure to check that it's NOT IsFlaggedForRemoval() before calling
	{														// this block of code.
//		OTLog::Error("DEBUG: Payment Plan -------------\n");
		
		// First I'll calculate whether the next payment would be due, based on start date,
		// time between payments, and date of last payment.
		
		const time_t DURATION_SINCE_START = (GetCurrentTime() - GetPaymentPlanStartDate());
		
		// Let's say the plan charges every week, and it's been 16 DAYS DURATION since starting.
		// The first charge would have been on the 1st day, 16 days ago.
		// Then the second charge would have been on the 8th day, (7 days later)
		// Then the third charge would have been on the 15th day, (7 days later again)
		// That means the next charge isn't due until the 22nd.
		
		// Right now in this example, DURATION_SINCE_START is: (16 * LENGTH_OF_DAY_IN_SECONDS).
		// I must calculate from that, that three charges have already happened, and that the
		// next one is not yet due.
		// 
		// I also know that GetTimeBetweenPayments() is set to (LENGTH_OF_DAY_IN_SECONDS * 7)
		// 
		// Duration / timebetween == 16/7 == 2 with 2 remainder.	(+1 to get 3: THREE should have already happened.)
		// if it was the 14th, 14/7 == 2 with 0 remainder.			(+1 to get 3: THREE should have happened by the 14th)
		// If it was the 22nd, 22/7 == 3 with 1 remainder.			(+1 to get 4: FOUR payments should have already happened.)
		//
		// Can also just add the TimeBetweenPayments to the DateOfLastPayment...
		//
		const int nNoPaymentsThatShouldHaveHappenedByNow = ((DURATION_SINCE_START/GetTimeBetweenPayments()) + 1);
		// The +1 is because it charges on the 1st day of the plan. So 14 days, which is 7 times 2, equals *3* payments, not 2.

//		OTLog::vOutput(3, "Payments that should have happened by now: %d\n"
//					   "Number payments done: %d      date of last payment: %d\n"
//					   "Date of last failed payment: %d   Time Between: %d", 
//					   nNoPaymentsThatShouldHaveHappenedByNow, GetNoPaymentsDone(), GetDateOfLastPayment(),
//					   GetDateOfLastFailedPayment(), GetTimeBetweenPayments());
		// -------------------------------------------------------
		
		// It's expired, remove it. (I check >0 because this one is an optional field.)
		if ((GetMaximumNoPayments() > 0) && (GetNoPaymentsDone() >= GetMaximumNoPayments()))
		{
			OTLog::Output(1, "Payment plan has expired by reaching max number of payments allowed.\n");
			return false; // This payment plan will be removed from Cron by returning false.
		}
		// Again, I check >0 because the plan length is optional and might just be 0.
		else if ((GetPaymentPlanLength() > 0) && (GetCurrentTime() >= (GetPaymentPlanStartDate() + GetPaymentPlanLength())))
		{
			OTLog::Output(1, "Payment plan has expired by reaching its maximum length of time.\n");
			return false; // This payment plan will be removed from Cron by returning false.
		}
		else if (nNoPaymentsThatShouldHaveHappenedByNow	<=	GetNoPaymentsDone())	// if not enough payments have happened...
		{
//			OTLog::Output(3, "DEBUG: Enough payments have already been made.\n");
		}
		else if ((GetCurrentTime() - GetDateOfLastPayment())	<	GetTimeBetweenPayments()) // and the time since last payment is more than the payment period...
		{
//			OTLog::Output(3, "DEBUG: Not enough time has elapsed.\n");	
		}
		else if ((GetCurrentTime() - GetDateOfLastFailedPayment())	<	LENGTH_OF_DAY_IN_SECONDS) // and it's been at least 24 hrs since the last failed payment...
		{
			OTLog::Output(3, "Cron (processing payment plan): Not enough time since last failed payment.\n");
		}
		// Okay -- PROCESS IT!
		else					// The above 3 end-comments have opposite logic from their if(), since they used to be here.
		{						// I reversed the operators so they could be failures, resulting in this else block for success.
			
			OTLog::Output(3, "Cron: Processing payment...\n");
			
			// This function assumes the payment is due, and it only fails in the case of 
			// the payer's account having insufficient funds.
			ProcessPaymentPlan();
		}
	}
	

	// Notice something: Markets are very concerned whether a trade failed, or if the account
	// was short of funds. They track that, and remove any trades when they have this problem.
	// So in OTTrade right now, you would be checking if it was flagged for removal, and 
	// returning false in that case.
	// 
	// But with a PAYMENT PLAN, if a payment fails, you don't want to cancel the plan!!!
	// You want it to keep trying until it gets in more payments, and ONLY cancel in the
	// case where the user REQUESTS it, or when one of the legitimate terms above expires naturally.
	// Insufficient funds? NO PROBLEM: you can stay on your payment plan as long as you want! :-)
	//
	// There ARE however funny cases where you WOULD want the plan removed.
	// For example:
	//
	if (IsFlaggedForRemoval() ||
		(HasInitialPayment() && IsInitialPaymentDone() && !HasPaymentPlan()))
	{
		OTLog::Output(3, "OTPaymentPlan::ProcessCron: Removing payment plan from cron processing...\n");
		return false; // if there's no plan, and initial payment is done, nothing left to do. Remove!
	}	

	return true;
}



OTPaymentPlan::~OTPaymentPlan()
{
	// no need to call Release(), the framework will call it.
}


void OTPaymentPlan::InitPaymentPlan()
{
	m_strContractType = "PAYMENT PLAN";

	SetProcessInterval(PLAN_PROCESS_INTERVAL); // Payment plans currently process every hour. (Could be reduced even more, to every day.)

	// Initial Payment...
	m_bInitialPayment			= false;	// Will there be an initial payment?
	m_tInitialPaymentDate		= 0;		// Date of the initial payment, measured seconds after creation date.
	m_tInitialPaymentCompletedDate	= 0;	// Date the initial payment was finally completed.
	m_lInitialPaymentAmount		= 0;		// Amount of the initial payment.
	m_bInitialPaymentDone		= false;	// Has the initial payment been made?
	m_nNumberInitialFailures	= 0;		// Number of times we failed to process this.
	m_tFailedInitialPaymentDate	= 0;		// Date of the last failed initial payment.
	
	
	// Payment Plan...
	m_bPaymentPlan				= false;	// Will there be a payment plan?
	m_lPaymentPlanAmount		= 0;		// Amount of each payment.
	m_tTimeBetweenPayments		= 2592000;	// How long between each payment? (Default: 30 days) // TODO don't hardcode.
	m_tPaymentPlanStartDate		= 0;		// Date for the first payment plan payment. Measured seconds after creation.
	
	m_tPaymentPlanLength		= 0;		// Optional. Plan length measured in seconds since plan start.
	m_nMaximumNoPayments		= 0;		// Optional. The most number of payments that are authorized.
	
	m_tDateOfLastPayment		= 0;		// Recording of date of the last payment.
	m_nNoPaymentsDone			= 0;		// Recording of the number of payments already processed.
	
	m_tDateOfLastFailedPayment	= 0;	// Recording of date of the last failed payment.
	m_nNoFailedPayments			= 0;	// Every time a payment fails, we record that here.
}




// the framework will call this at the right time.
void OTPaymentPlan::Release()
{
	// If there were any dynamically allocated objects, clean them up here.
	
	OTAgreement::Release(); // since I've overridden the base class, I call it now...
	
	// Then I call this to re-initialize everything
	InitPaymentPlan();
}




bool OTPaymentPlan::SaveContractWallet(std::ofstream & ofs)
{
	return true;
}

