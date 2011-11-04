/************************************************************
 *    
 *  OTCronItem.cpp
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


#include "OTPseudonym.h"
#include "OTLedger.h"
#include "OTCronItem.h"
#include "OTAgreement.h"
#include "OTPaymentPlan.h"
#include "OTTrade.h"
#include "OTCron.h"
#include "OTLog.h"


// Base class for OTTrade and OTAgreement and OTPaymentPlan.
// OTCron contains lists of these for regular processing.


// static -- class factory.
//
// I just realized, I don't have to use this only for CronItems.
// If I wanted to, I could put ANY Open-Transactions class in here,
// if there was some need for it, and it would work just fine right here.
// Like if I wanted to have different Token types for different cash
// algorithms. All I have to do is change the return type.
OTCronItem * OTCronItem::NewCronItem(const OTString & strCronItem)
{
	static char		buf[45] = "";
	OTCronItem *	pItem = NULL;
	
	if (!strCronItem.Exists())
		return NULL;
	
	OTString strContract(strCronItem);
	
	strContract.reset(); // for sgets
	buf[0] = 0; // probably unnecessary.
	bool bGotLine = strContract.sgets(buf, 40);

	if (!bGotLine)
		return NULL;
	
	OTString strFirstLine(buf);
	strContract.reset(); // set the "file" pointer within this string back to index 0.
	
	// Now I feel pretty safe -- the string I'm examining is within
	// the first 45 characters of the beginning of the contract, and
	// it will NOT contain the escape "- " sequence. From there, if
	// it contains the proper sequence, I will instantiate that type.
	if (!strFirstLine.Exists() || strFirstLine.Contains("- -"))
		return NULL;
		
//	if (strFirstLine.Contains("-----BEGIN SIGNED AGREEMENT-----"))  // this string is 32 chars long.
//	{	pItem = new OTAgreement();		OT_ASSERT(NULL != pItem); }
	
	else if (strFirstLine.Contains("-----BEGIN SIGNED PAYMENT PLAN-----"))  // this string is 35 chars long.
	{	pItem = new OTPaymentPlan();	OT_ASSERT(NULL != pItem); }
	
	else if (strFirstLine.Contains("-----BEGIN SIGNED TRADE-----"))  // this string is 28 chars long.
	{	pItem = new OTTrade();			OT_ASSERT(NULL != pItem); }
	
	
	// The string didn't match any of the options in the factory.
	if (NULL == pItem)
		return NULL;
	
	// Does the contract successfully load from the string passed in?
	if (pItem->LoadContractFromString(strContract))
		return pItem;
	else
		delete pItem;
	
	
	return NULL;
}




// ------------------------------------------------------------
// These are for finalReceipt
// The Cron Item stores a list of these closing transaction numbers,
// used for closing a transaction.
//
int OTCronItem::GetCountClosingNumbers() const
{
	return m_dequeClosingNumbers.size();
}

long OTCronItem::GetClosingTransactionNoAt(unsigned int nIndex) const 
{
    OT_ASSERT_MSG((nIndex < m_dequeClosingNumbers.size()) && (nIndex >= 0), 
                  "OTCronItem::GetClosingTransactionNoAt: index out of bounds.");
    
    return m_dequeClosingNumbers.at(nIndex);
}

void OTCronItem::AddClosingTransactionNo(const long & lClosingTransactionNo)
{
    m_dequeClosingNumbers.push_back(lClosingTransactionNo);
}
// ------------------------------------------------------------

/// See if theNym has rights to remove this item from Cron.
///
bool OTCronItem::CanRemoveItemFromCron(OTPseudonym & theNym)
{
    // You don't just go willy-nilly and remove a cron item from a market unless you check first
    // and make sure the Nym who requested it actually has said number (or a related closing number)
    // signed out to him on his last receipt...
    //    
    if (false == theNym.CompareID(GetSenderUserID()))
    {
        OTLog::Output(5, "OTCronItem::CanRemoveItem: theNym is not the originator of this CronItem. "
                      "(He could be a recipient though, so this is normal.)\n");
        return false;
    }
    
    // By this point, that means theNym is DEFINITELY the originator (sender)...
    else if (this->GetCountClosingNumbers() < 1)
    {
        OTLog::vOutput(0, "Weird: Sender tried to remove a cron item; expected at least 1 closing number to be available"
                      "--that wasn't. (Found %d).\n", this->GetCountClosingNumbers());
        return false;
    }
    // ------------------------------------------
    //
    const OTString strServerID(GetServerID());
    
    if (false == theNym.VerifyIssuedNum(strServerID, this->GetClosingNum()))
    {
        OTLog::Output(0, "OTCronItem::CanRemoveItemFromCron: Closing number didn't verify (for removal from cron).\n");
        return false;
    }
 
    // By this point, we KNOW theNym is the sender, and we KNOW there are the proper number of transaction
    // numbers available to close. We also know that this cron item really was on the cron object, since
    // that is where it was looked up from, when this function got called! So I'm pretty sure, at this point,
    // to authorize removal, as long as the transaction num is still issued to theNym (this check here.)
    //
    return theNym.VerifyIssuedNum(strServerID, this->GetOpeningNum());

    // Normally this will be all we need to check. The originator will have the transaction
    // number signed-out to him still, if he is trying to close it. BUT--in some cases, someone
    // who is NOT the originator can cancel. Like in a payment plan, the sender is also the depositor,
    // who would normally be the person cancelling the plan. But technically, the RECIPIENT should
    // also have the ability to cancel that payment plan.  BUT: the transaction number isn't signed
    // out to the RECIPIENT... In THAT case, the below VerifyIssuedNum() won't work! In those cases,
    // expect that the special code will be in the subclasses override of this function. (OTPaymentPlan::CanRemoveItem() etc)

    // P.S. If you override this function, MAKE SURE to call the parent (OTCronItem::CanRemoveItem) first, 
    // for the VerifyIssuedNum call above. Only if that fails, do you need to dig deeper...
}




// OTCron calls this regularly, which is my chance to expire, etc.
// Child classes will override this, AND call it (to verify valid date range.)
//
// Return False:	REMOVE this Cron Item from Cron.
// Return True:		KEEP this Cron Item on Cron (for now.)
//
bool OTCronItem::ProcessCron()
{
	OT_ASSERT(m_pCron);
	
    if (IsFlaggedForRemoval())
    {
		OTLog::vOutput(3, "Cron: Flagged for removal: %s.\n", m_strContractType.Get());        
        return false;
    }
    
	// I call IsExpired() here instead of VerifyCurrentDate(). The Cron Item will stay on
	// Cron even if it is NOT YET valid. But once it actually expires, this will remove it.
	if (IsExpired())
	{
		OTLog::vOutput(3, "Cron: Expired %s.\n", m_strContractType.Get());
		return false;
	}
	
	// As far as this code is concerned, the item can stay on cron for now. Return true.
	return true;
}



OTCronItem * OTCronItem::LoadCronReceipt(const long & lTransactionNum)
{
	OTString strFilename;
	strFilename.Format("%ld.crn", lTransactionNum);
	
	const char * szFoldername	= OTLog::CronFolder();
	const char * szFilename		= strFilename.Get();
		
	// --------------------------------------------------------------------
	
	if (false == OTDB::Exists(szFoldername, szFilename))
	{
		OTLog::vError("OTCronItem::LoadCronReceipt: File does not exist: %s%s%s\n", 
					  szFoldername, OTLog::PathSeparator(), szFilename);
		return NULL;
	}
	
	// --------------------------------------------------------------------
	//
	OTString strFileContents(OTDB::QueryPlainString(szFoldername, szFilename)); // <=== LOADING FROM DATA STORE.
	
	if (strFileContents.GetLength() < 2)
	{
		OTLog::vError("OTCronItem::LoadCronReceipt: Error reading file: %s%s%s\n", 
					  szFoldername, OTLog::PathSeparator(), szFilename);
		return NULL;
	}
	else
		return OTCronItem::NewCronItem(strFileContents);
}


// When first adding anything to Cron, a copy needs to be saved in a folder somewhere.
// (Just for our records.) For example, before I start updating the status on any Trade,
// I have already saved the user's original Trade object (from his request) to a folder.
// Now I have the freedom to ReleaseSignatures on the Trade and re-sign it with the
// server's Nym as it updates over time.  The user cannot challenge the Trade because
// the server has the original copy on file and sends it with all receipts.

bool OTCronItem::SaveCronReceipt()
{
	OTString strFilename;
	strFilename.Format("%ld.crn", GetTransactionNum());
	
	const char * szFoldername	= OTLog::CronFolder();  // cron
	const char * szFilename		= strFilename.Get();    // cron/TRANSACTION_NUM.crn
	
	// --------------------------------------------------------------------
	
	if (OTDB::Exists(szFoldername, szFilename))
	{
		OTLog::vError("Cron Record exists for transaction %ld %s%s%s,\nyet attempted to record it again.\n",
					  GetTransactionNum(), szFoldername, OTLog::PathSeparator(), szFilename);
		return false;
	}
	
	// --------------------------------------------------------------------
	
	OTString strFinal;
	SaveContract(strFinal);
	
	bool bSaved = OTDB::StorePlainString(strFinal.Get(), szFoldername, szFilename);
	
	if (!bSaved)
	{
		OTLog::vError("OTCronItem::SaveCronReceipt: Error saving file: %s%s%s\n", 
					  szFoldername, OTLog::PathSeparator(), szFilename);
		return false;
	}
	// --------------------------------------------------------------------
		
	return bSaved;
}







// OTCron calls this when a cron item is removed
// This gives each item a chance to drop a final receipt,
// and clean up any memory, before being destroyed.
//
void OTCronItem::HookRemovalFromCron(OTPseudonym * pRemover)
{
    OTCron * pCron  = GetCron();
    OT_ASSERT(NULL != pCron);
    
    OTPseudonym * pServerNym = pCron->GetServerNym();
    OT_ASSERT(NULL != pServerNym);
    
    // -----------------------------------------------------
    
    // Generate new transaction number for these new inbox receipts.
    //
    const long lNewTransactionNumber = pCron->GetNextTransactionNumber();
    
    //	OT_ASSERT(lNewTransactionNumber > 0); // this can be my reminder.			
    if (0 == lNewTransactionNumber)
    {
        OTLog::Error("OTCronItem::HookRemovalFromCron: ** ERROR Final receipt not added to inbox, since no "
                     "transaction numbers were available!\n");
    }
    else
    {
        // Everytime a payment processes, or a trade, then a receipt is put in the user's inbox.
        // This contains a copy of the current payment or trade (which took money from the user's acct.)
        //
        // ==> So I increment the payment count each time before dropping the receipt. (I also use a fresh
        // transaction number when I put it into the inbox.) That way, the user will never get the same
        // receipt for the same plan twice. It cannot take funds from his account, without a new payment
        // count and a new transaction number on a new receipt. Until the user accepts the receipt out
        // of his inbox with a new balance agreement, the existing receipts can be added up and compared
        // to the last balance agreement, to verify the current balance. Every receipt from a processing
        // payment will have the user's authorization, signature, and terms, as well as the update in balances
        // due to the payment, signed by the server.
        
        // In the case of the FINAL RECEIPT, I do NOT increment the count, so you can see it will have the same
        // payment count as the last paymentReceipt. (if there were 5 paymentReceipts, from 1 to 5, then the
        // finalReceipt will also be 5. This is evidence of what the last paymentReceipt WAS.)
        
        // -------------------------------------------------------------
        
        // The TRANSACTION will be dropped into the INBOX with "In Reference To" information,
        // containing the ORIGINAL SIGNED REQUEST.
        //
        OTCronItem * pOrigCronItem	= OTCronItem::LoadCronReceipt(GetTransactionNum());
        // OTCronItem::LoadCronReceipt loads the original version with the user's signature.
        // (Updated versions, as processing occurs, are signed by the server.)
        OT_ASSERT(NULL != pOrigCronItem);
        OTCleanup<OTCronItem> theCronItemAngel(*pOrigCronItem);
        
        // Note: elsewhere, we verify the Nym's signature. But in this place, we verify the SERVER's
        // signature. (The server signed the cron receipt just before it was first saved, so it has two signatures on it.)
        //
        OT_ASSERT_MSG(pOrigCronItem->VerifySignature(*pServerNym), 
                      "Failure verifying signature of server on Cron Item in OTCronItem::HookRemovalFromCron.\n");
        
        // I now have a String copy of the original CronItem...
        const OTString strOrigCronItem(*pOrigCronItem);
        // -------------------------------------------------------
        
        OTPseudonym theOriginatorNym; // Don't use this... use the pointer just below.

        // The Nym who is actively requesting to remove a cron item will be passed in as pRemover.
        // However, sometimes there is no Nym... perhaps it just expired and pRemover is NULL.
        // The originating Nym (if different than remover) is loaded up. Otherwise the originator
        // pointer just pointers to *pRemover.
        //
        OTPseudonym * pOriginator = NULL;
        
        if (pServerNym->CompareID(pOrigCronItem->GetSenderUserID()))
        {
            pOriginator = pServerNym; // Just in case the originator Nym is also the server Nym.
        }                               // This MIGHT be unnecessary, since pRemover is(I think) already transmogrified 
        // ******************************************************* to pServer earlier, if they share the same ID.
        //
        // If pRemover is NOT NULL, and he has the Originator's ID...
        // then set the pointer accordingly.
        //
        else if ((NULL != pRemover) && (true == pRemover->CompareID(pOrigCronItem->GetSenderUserID())))
        {
            pOriginator = pRemover; // <======== now both pointers are set (to same Nym). DONE!
        }
        // --------------------------------------------------------------------------------------------------
        // At this point, pRemover MIGHT be set, or NULL. (And that's that -- pRemover may always be NULL.)
        //
        // if pRemover IS set, then pOriginator MIGHT point to it as well. (If the IDs match. Done above.)
        // pOriginator might also still be NULL. (If pRemover is NULL, then pOriginator DEFINITELY is.)
        // pRemover is loaded (or not). Next let's make SURE pOriginator is loaded, if it wasn't already...
        //
        if (NULL == pOriginator)
        {
            // GetSenderUserID() should be the same on THIS (updated version of the same cron item) 
            // but for whatever reason, I'm checking the userID on the original version. Sue me.
            //
            const OTIdentifier NYM_ID(pOrigCronItem->GetSenderUserID());
            
            theOriginatorNym.SetIdentifier(NYM_ID);  
            
            if (false == theOriginatorNym.LoadPublicKey())
            {
                OTString strNymID(NYM_ID);
                OTLog::vError("OTCronItem::HookRemovalFromCron: Failure loading Sender's public key:\n%s\n", strNymID.Get());
            }		
            else if (theOriginatorNym.VerifyPseudonym() && 
                     theOriginatorNym.LoadSignedNymfile(*pServerNym)) // ServerNym here is merely the signer on this file.
            {
                pOriginator = &theOriginatorNym; //  <=====
            }
            else 
            {
                OTString strNymID(NYM_ID);
                OTLog::vError("OTCronItem::HookRemovalFromCron: Failure verifying Sender's public key or loading signed nymfile: %s\n",
                              strNymID.Get());
            }
        }
        
        // -------------------------------
        
        // pOriginator should NEVER be NULL by this point, unless there was an ERROR in the above block.
        // We even loaded the guy from storage, if we had to.
        //
        if (NULL != pOriginator)
        {
            // Drop the FINAL RECEIPT(s) into the user's inbox(es)!!
            // Pass in strOrigCronItem and lNewTransactionNumber which were obtained above.
            //
            onFinalReceipt(*pOrigCronItem, lNewTransactionNumber, *pOriginator, pRemover);
        }
        else
        {
            OTLog::Error("MAJOR ERROR in OTCronItem::HookRemovalFromCron!! Failed loading Originator Nym for Cron Item.\n");
        }
    }
    
    // -------------------------------------------------------
    // Remove corresponding offer from market, if applicable.
    // 
    onRemovalFromCron();
}


long OTCronItem::GetOpeningNum() const
{
    return GetTransactionNum();
}

long OTCronItem::GetClosingNum() const
{
    return (GetCountClosingNumbers() > 0) ? GetClosingTransactionNoAt(0) : 0; // todo stop hardcoding.
}



// This function is overridden in both OTTrade and OTAgreement.
// I'm put a default implementation here "Just Because".
//
// This is called by HookRemovalFromCron().
//
void OTCronItem::onFinalReceipt(OTCronItem & theOrigCronItem, const long & lNewTransactionNumber,
                                OTPseudonym & theOriginator,
                                OTPseudonym * pRemover) // may already point to theOriginator... or someone else...
{
    OTCron * pCron  = GetCron();
    OT_ASSERT(NULL != pCron);
    
    OTPseudonym * pServerNym = pCron->GetServerNym();
    OT_ASSERT(NULL != pServerNym);

    // -------------------------------------------------
    
    // The finalReceipt Item's ATTACHMENT contains the UPDATED Cron Item.
    // (With the SERVER's signature on it!)
    //
    OTString strUpdatedCronItem(*this);
    OTString * pstrAttachment=&strUpdatedCronItem;
    
    const OTString strOrigCronItem(theOrigCronItem);
    // -----------------------------------------------------------------

    // First, we are closing the transaction number ITSELF, of this cron item,
    // as an active issued number on the originating nym. (Changing it to CLOSED.)
    //
    // Second, we're verifying the CLOSING number, and using it as the closing number
    // on the FINAL RECEIPT (with that receipt being "InReferenceTo" this->GetTransactionNum())
    //
    const long lOpeningNumber = theOrigCronItem.GetTransactionNum();
    const long lClosingNumber = (theOrigCronItem.GetCountClosingNumbers() > 0) ? theOrigCronItem.GetClosingTransactionNoAt(0) : 0;

    const OTString strServerID(GetServerID());

    // -----------------------------------------------------------------
    // I'm ASSUMING here that pRemover is also theOriginator.
    //
    // REMEMBER: Most subclasses will override this method, and THEY
    // are the cases where pRemover is someone other than theOriginator.
    // That's why they have a different version of onFinalReceipt.
    //
    if ((lOpeningNumber > 0) && 
        theOriginator.VerifyIssuedNum(strServerID, lOpeningNumber)) 
    {
        // The Nym (server side) stores a list of all opening and closing cron #s.
        // So when the number is released from the Nym, we also take it off that list.
        //
        std::set<long> & theIDSet = theOriginator.GetSetOpenCronItems();
        theIDSet.erase(lOpeningNumber);
        
        theOriginator.RemoveIssuedNum(*pServerNym, strServerID, lOpeningNumber, false); //bSave=false
        theOriginator.SaveSignedNymfile(*pServerNym);
        
        // the RemoveIssued call means the original transaction# (to find this cron item on cron) is now CLOSED.
        // But the Transaction itself is still OPEN. How? Because the CLOSING number is still signed out.
        // The closing number is also USED, since the NotarizePaymentPlan or NotarizeMarketOffer call, but it
        // remains ISSUED, until the final receipt itself is accepted during a process inbox.
        //
        
        if (false == this->DropFinalReceiptToNymbox(GetSenderUserID(),
                                                    lNewTransactionNumber,
                                                    strOrigCronItem,
                                                    NULL, // note
                                                    pstrAttachment))
        {
            OTLog::Error("OTCronItem::onFinalReceipt:Failure dropping finalReceipt to Nymbox.\n");
        }        
    }
    else
    {
        OTLog::Error("OTCronItem::onFinalReceipt: Failed doing VerifyIssuedNum(theOrigCronItem.GetTransactionNum())\n");
    }
    
    // ------------------------------------------------------------------------
    
    if ((lClosingNumber > 0) && 
        theOriginator.VerifyIssuedNum(strServerID, lClosingNumber)
        ) 
    {        
        // SENDER only. (CronItem has no recipient. That's in the subclass.)
        if (false == this->DropFinalReceiptToInbox(GetSenderUserID(), GetSenderAcctID(),
                                                        lNewTransactionNumber,
                                                        lClosingNumber, // The closing transaction number to put on the receipt.
                                                        strOrigCronItem,
                                                        NULL, // note
                                                        pstrAttachment))
            OTLog::Error("OTCronItem::onFinalReceipt: Failure dropping receipt into inbox.\n");

        // In this case, I'm passing NULL for pstrNote, since there is no note.
        // (Additional information would normally be stored in the note.) 

        // This part below doesn't happen until you ACCEPT the final receipt (when processing your inbox.)
        //
//      theOriginator.RemoveIssuedNum(strServerID, lClosingNumber, true); //bSave=false
    }
    else
    {
        OTLog::Error("OTCronItem::onFinalReceipt: Failed verifying lClosingNumber=theOrigCronItem.GetClosingTransactionNoAt(0)>0 &&  "
                     "theOriginator.VerifyTransactionNum(lClosingNumber)\n");
    }
    // -------------------------------
   
    // QUESTION: Won't there be Cron Items that have no asset account at all?
    // In which case, there'd be no need to drop a final receipt, but I don't think
    // that's the case, since you have to use a transaction number to get onto cron
    // in the first place.
    // -----------------------------------------------------------------
} 


// DONE:  ABOVE, do the other subclasses.




// DONE:  Below, use lClosingNumber
// 


// This is the "DROPS FINAL RECEIPT" function.
// "Final Receipts" are used by Cron Items, as the last receipt for a given transaction number.
//
/*
 bool DropFinalReceiptToInbox(const OTIdentifier & USER_ID,
            const OTIdentifier & ACCOUNT_ID,
            const long & lNewTransactionNumber,
            const long & lClosingNumber,
            OTString & strOrigCronItem,
            OTString * pstrNote=NULL, 
            OTString * pstrAttachment=NULL);
 */
bool OTCronItem::DropFinalReceiptToInbox(const OTIdentifier & USER_ID,
                                         const OTIdentifier & ACCOUNT_ID,
                                         const long & lNewTransactionNumber,
                                         const long & lClosingNumber,
                                         const OTString & strOrigCronItem,
                                         OTString * pstrNote/*=NULL*/,
                                         OTString * pstrAttachment/*=NULL*/)
{
    OTCron * pCron  = GetCron();
    OT_ASSERT(NULL != pCron);
    
    OTPseudonym * pServerNym = pCron->GetServerNym();
    OT_ASSERT(NULL != pServerNym);
    
    // -----------------------------------------------------
	// Load the inbox in case it already exists.
    OTLedger theInbox (USER_ID, ACCOUNT_ID, GetServerID());
    
    // Inbox will receive notification of something ALREADY DONE.
    bool bSuccessLoading = theInbox.LoadInbox();
    
    // -------------------------------------------------------------------
    // ...or generate it otherwise...
    
    if (true == bSuccessLoading)
        bSuccessLoading		= theInbox.VerifyAccount(*pServerNym);
    else
		bSuccessLoading		= theInbox.GenerateLedger(ACCOUNT_ID, GetServerID(), OTLedger::inbox, true); // bGenerateFile=true
    
    // --------------------------------------------------------------------
    
    if (false == bSuccessLoading)
    {
        OTLog::Error("ERROR loading or generating an inbox in OTCronItem::DropFinalReceiptToInbox. (FAILED WRITING RECEIPT!!) \n");
        return false;
    }
    else 
    {        
        // Start generating the receipts
        
        OTTransaction * pTrans1	= OTTransaction::GenerateTransaction(theInbox, OTTransaction::finalReceipt, lNewTransactionNumber);        
        // (No need to OT_ASSERT on the above transaction since it occurs in GenerateTransaction().)
        
        // The inbox will get a receipt with the new transaction ID.
        // That receipt has an "in reference to" field containing the original cron item.
        
        // set up the transaction items (each transaction may have multiple items... but not in this case.)
        OTItem * pItem1	= OTItem::CreateItemFromTransaction(*pTrans1, OTItem::finalReceipt);
        
        // This may be unnecessary, I'll have to check CreateItemFromTransaction. I'll leave it for now.
        OT_ASSERT(NULL != pItem1);
        
        pItem1->SetStatus(OTItem::acknowledgement);
                
        // -------------------------------------------------------------
        //
        // Here I make sure that the receipt (the inbox notice) references the
        // transaction number that the trader originally used to issue the cron item...
        // This number is used to match up offers to trades, and used to track all cron items.
        // (All Cron items require a transaction from the user to add them to Cron in the
        // first place.)
        // 
        pTrans1->SetReferenceToNum(GetTransactionNum());
        // -------------------------------------------------
        // The reference on the transaction contains an OTCronItem, in this case.
        // The original cron item, versus the updated cron item (which is stored
        // on the finalReceipt item just below here.)
        //
        pTrans1->SetReferenceString(strOrigCronItem);
        // --------------------------------------------
        pTrans1->SetClosingNum(lClosingNumber); // This transaction is the finalReceipt for GetTransactionNum(), as lClosingNumber.
        // -----------------------------------------------------------------
        // The finalReceipt ITEM's NOTE contains the UPDATED CRON ITEM.
        //
        if (NULL != pstrNote)
        {
            pItem1->SetNote(*pstrNote);    // in markets, this is updated trade.        
        }
        
        // Also set the ** UPDATED OFFER ** as the ATTACHMENT on the ** item.** 
        // (With the SERVER's signature on it!) // in markets, this is updated offer.
        //
        if (NULL != pstrAttachment)
        {
            pItem1->SetAttachment(*pstrAttachment); 
        }
        
        // -----------------------------------------------------------------
        // sign the item
        
        pItem1->SignContract(*pServerNym);
        pItem1->SaveContract();
        
        // the Transaction "owns" the item now and will handle cleaning it up.
        pTrans1->AddItem(*pItem1);
        
        pTrans1->SignContract(*pServerNym);
        pTrans1->SaveContract();
        
        // Here the transaction we just created is actually added to the ledger.
        theInbox.AddTransaction(*pTrans1);
        
        // Release any signatures that were there before (They won't
        // verify anymore anyway, since the content has changed.)
        theInbox.ReleaseSignatures();
        
        // Sign and save.
        theInbox.   SignContract(*pServerNym);
        theInbox.	SaveContract();
        
        // TODO: Better rollback capabilities in case of failures here:
        
        // Save both inboxes to storage. (File, DB, wherever it goes.)
        theInbox.	SaveInbox();
        
        return true;    // Really this true should be predicated on ALL the above functions returning true. Right?
    }                   // ...Right?
    
    return false; // unreachable.
}




// The final receipt doesn't have a closing number in the Nymbox, only in the Inbox.
// That's because in the Nymbox, it's just a notice, and it's not there to enforce anything.
// If you get one in your Nymbox, it's just so that you know to removed its "in ref to" number
// from your issued list (so your balance agreements will work :P)
//
bool OTCronItem::DropFinalReceiptToNymbox(const OTIdentifier & USER_ID,
                                         const long & lNewTransactionNumber,
                                         const OTString & strOrigCronItem,
                                         OTString * pstrNote/*=NULL*/,
                                         OTString * pstrAttachment/*=NULL*/)
{
    OTCron * pCron  = GetCron();
    OT_ASSERT(NULL != pCron);
    
    OTPseudonym * pServerNym = pCron->GetServerNym();
    OT_ASSERT(NULL != pServerNym);
    
    // -----------------------------------------------------
    
    OTLedger theLedger(USER_ID, USER_ID, GetServerID());
    
    // Inbox will receive notification of something ALREADY DONE.
    bool bSuccessLoading = theLedger.LoadNymbox();
    
    // -------------------------------------------------------------------
    // ...or generate it otherwise...
    
    if (true == bSuccessLoading)
        bSuccessLoading		= theLedger.VerifyAccount(*pServerNym);
    else
		bSuccessLoading		= theLedger.GenerateLedger(USER_ID, GetServerID(), OTLedger::nymbox, true); // bGenerateFile=true
    
    // --------------------------------------------------------------------
    
    if (false == bSuccessLoading)
    {
        OTLog::Error("ERROR loading or generating a nymbox in OTCronItem::DropFinalReceiptToNymbox. (FAILED WRITING RECEIPT!!) \n");
        return false;
    }

    // --------------------------------------------------------------------
    
    OTTransaction * pTransaction = OTTransaction::GenerateTransaction(theLedger,
                                                                      OTTransaction::finalReceipt,
                                                                      lNewTransactionNumber);
    
    if (NULL != pTransaction) // The above has an OT_ASSERT within, but I just like to check my pointers.
    {			
        // The nymbox will get a receipt with the new transaction ID.
        // That receipt has an "in reference to" field containing the original cron item.

        
        // set up the transaction items (each transaction may have multiple items... but not in this case.)
        OTItem * pItem1	= OTItem::CreateItemFromTransaction(*pTransaction, OTItem::finalReceipt);
        
        // This may be unnecessary, I'll have to check CreateItemFromTransaction. I'll leave it for now.
        OT_ASSERT(NULL != pItem1);
        
        pItem1->SetStatus(OTItem::acknowledgement);
        
        // -------------------------------------------------------------
        //
        // Here I make sure that the receipt (the nymbox notice) references the
        // transaction number that the trader originally used to issue the cron item...
        // This number is used to match up offers to trades, and used to track all cron items.
        // (All Cron items require a transaction from the user to add them to Cron in the
        // first place.)
        // 
        pTransaction->SetReferenceToNum(GetTransactionNum());
        // -------------------------------------------------
        // The reference on the transaction contains an OTCronItem, in this case.
        // The original cron item, versus the updated cron item (which is stored
        // on the finalReceipt item just below here.)
        //
        pTransaction->SetReferenceString(strOrigCronItem);
        // --------------------------------------------
        pTransaction->SetClosingNum(GetTransactionNum()); // This transaction is the finalReceipt for GetTransactionNum(). (Which is also the original transaction number.)
        
        // -----------------------------------------------------------------
        // The finalReceipt ITEM's NOTE contains the UPDATED CRON ITEM.
        //
        if (NULL != pstrNote)
        {
            pItem1->SetNote(*pstrNote);    // in markets, this is updated trade.        
        }
        
        // Also set the ** UPDATED OFFER ** as the ATTACHMENT on the ** item.** 
        // (With the SERVER's signature on it!) // in markets, this is updated offer.
        //
        if (NULL != pstrAttachment)
        {
            pItem1->SetAttachment(*pstrAttachment); 
        }
        
        // -----------------------------------------------------------------
        // sign the item
        
        pItem1->SignContract(*pServerNym);
        pItem1->SaveContract();
        
        // the Transaction "owns" the item now and will handle cleaning it up.
        pTransaction->AddItem(*pItem1);
        
        pTransaction->SignContract(*pServerNym);
        pTransaction->SaveContract();
        
        // Here the transaction we just created is actually added to the ledger.
        theLedger.AddTransaction(*pTransaction);
        
        // Release any signatures that were there before (They won't
        // verify anymore anyway, since the content has changed.)
        theLedger.ReleaseSignatures();
        
        // Sign and save.
        theLedger.SignContract(*pServerNym);
        theLedger.SaveContract();
        
        // TODO: Better rollback capabilities in case of failures here:
        
        // Save both inboxes to storage. (File, DB, wherever it goes.)
        theLedger.	SaveNymbox();
        
        return true;    // Really this true should be predicated on ALL the above functions returning true. Right?
    }
    else
        OTLog::Error("Failed trying to create Nymbox in OTCronItem::DropFinalReceiptToNymbox()\n");

    return false; // unreachable.
}








void OTCronItem::HarvestClosingNumbers(OTPseudonym & theNym)
{
    // The Nym is the original sender. (If Compares true).
    // GetTransactionNum() is burned, but we can harvest the closing
    // numbers from the "Closing" list, which is only for the sender's numbers.
    // Subclasses will have to override this function for recipients, etc.
    //
    if (theNym.CompareID(GetSenderUserID()))
    {
        const OTString strServerID(GetServerID());

        for (int i = 0; i < GetCountClosingNumbers(); i++)
        {
            theNym.AddTransactionNum(theNym, strServerID, GetClosingTransactionNoAt(i), 
                                     (i == (GetCountClosingNumbers()-1) ? true : false)); // bSave=true only on the last iteration.
        }
    }
}



OTCronItem::OTCronItem() : OTTrackable(), m_pCron(NULL), m_CREATION_DATE(0), m_LAST_PROCESS_DATE(0),
    m_PROCESS_INTERVAL(1),  // Default for any cron item is to execute once per second.
    m_bRemovalFlag(false)
{
	InitCronItem();
}


OTCronItem::OTCronItem(const OTIdentifier & SERVER_ID, const OTIdentifier & ASSET_ID) : 
    OTTrackable(SERVER_ID, ASSET_ID),
        m_pCron(NULL), m_CREATION_DATE(0), 
        m_LAST_PROCESS_DATE(0), m_PROCESS_INTERVAL(1), // Default for any cron item is to execute once per second.
        m_bRemovalFlag(false)
{
	InitCronItem();
}

OTCronItem::OTCronItem(const OTIdentifier & SERVER_ID, const OTIdentifier & ASSET_ID,
					   const OTIdentifier & ACCT_ID, const OTIdentifier & USER_ID) : 
    OTTrackable(SERVER_ID, ASSET_ID, ACCT_ID, USER_ID),
        m_pCron(NULL), m_CREATION_DATE(0), 
        m_LAST_PROCESS_DATE(0), m_PROCESS_INTERVAL(1), // Default for any cron item is to execute once per second.
        m_bRemovalFlag(false)

{
	InitCronItem();
}




OTCronItem::~OTCronItem()
{
    // No need to call Release() here, it's handled by the framework.	
}

void OTCronItem::InitCronItem()
{
	m_strContractType.Set("CRONITEM"); // in practice should never appear. Child classes will overwrite.
}


void OTCronItem::Release()
{
	// If there were any dynamically allocated objects, clean them up here.
	
    m_CREATION_DATE = 0;
    m_LAST_PROCESS_DATE = 0;
	m_PROCESS_INTERVAL = 1;
	
    m_dequeClosingNumbers.clear();
    
    m_bRemovalFlag = false;

    // ----------------------------------
    
	OTTrackable::Release(); // since I've overridden the base class, I call it now...
}



// return -1 if error, 0 if nothing, and 1 if the node was processed.
int OTCronItem::ProcessXMLNode(irr::io::IrrXMLReader*& xml)
{
	int nReturnVal = 0;
    
	// Here we call the parent class first.
	// If the node is found there, or there is some error,
	// then we just return either way.  But if it comes back
	// as '0', then nothing happened, and we'll continue executing.
	//
	// -- Note you can choose not to call the parent if
	// you don't want to use any of those xml tags.
	//
	
	// In this case, I don't need to call the parent. But I'm going to 
	// call the grand-grand-parent (scriptable.)
	//
	nReturnVal = OTScriptable::ProcessXMLNode(xml);
	
	if (nReturnVal != 0) // -1 is error, and 1 is "found it". Either way, return.
		return nReturnVal;	// 0 means "nothing happened, keep going."
    
	// ---------
	
    if (!strcmp("closingTransactionNumber", xml->getNodeName())) 
	{		
        OTString strClosingNumber = xml->getAttributeValue("value");
        
        if (strClosingNumber.Exists())
        {
            const long lClosingNumber = atol(strClosingNumber.Get());					
            
            this->AddClosingTransactionNo(lClosingNumber);
        }
        else
		{
			OTLog::Error("Error in OTCronItem::ProcessXMLNode: closingTransactionNumber field without value.\n");
			return (-1); // error condition
		}
        
		nReturnVal = 1;
	}
     
	return nReturnVal;
}



/*

void OTCronItem::UpdateContents()
{
	
}


bool OTCronItem::SaveContractWallet(std::ofstream & ofs)
{
	return true;
}
*/
