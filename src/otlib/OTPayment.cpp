/************************************************************************************
 *    
 *  OTPayment.cpp
 *  
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


#include <cstring>

#include <string>

#include "irrxml/irrXML.h"

using namespace irr;
using namespace io;


#include "OTStorage.h"

#include "OTPayment.h"

#include "OTData.h"
#include "OTIdentifier.h"

#include "OTString.h"
#include "OTASCIIArmor.h"

#include "OTPseudonym.h"

#include "OTEnvelope.h"

#include "OTTrackable.h"
#include "OTCheque.h"

#include "OTPurse.h"

#include "OTCronItem.h"
#include "OTPaymentPlan.h"
#include "OTSmartContract.h"

#include "OTLog.h"




char const * const __TypeStrings[] = 
{
    // ------------------
    // OTCheque is derived from OTTrackable, which is derived from OTInstrument, which is
    // derived from OTScriptable, which is derived from OTContract.
    // ------------------
    "CHEQUE",         // A cheque drawn on a user's account.
    "VOUCHER",        // A cheque drawn on a server account (cashier's cheque aka banker's cheque)
    "INVOICE",        // A cheque with a negative amount. (Depositing this causes a payment out, instead of a deposit in.)
    // ------------------
    "PAYMENT PLAN",   // An OTCronItem-derived OTPaymentPlan, related to a recurring payment plan.
    "SMARTCONTRACT",  // An OTCronItem-derived OTSmartContract, related to a smart contract.
    // ------------------
    "PURSE",          // An OTContract-derived OTPurse containing a list of cash OTTokens.
    // ------------------
    "ERROR_STATE"
};

//static
const char * const OTPayment::_GetTypeString(paymentType theType) {
	int nType = static_cast<int> (theType);
	return __TypeStrings[nType];
}


OTPayment::paymentType OTPayment::GetTypeFromString(const OTString & strType)
{
#define OT_NUM_ELEM(blah) (sizeof (blah) / sizeof (*(blah)))    
    for (unsigned int i = 0; i < ( OT_NUM_ELEM(__TypeStrings) - 1 ); i++ )
    {
        if (strType.Compare(__TypeStrings[i]))
            return static_cast<OTPayment::paymentType>(i);
    }
#undef OT_NUM_ELEM
    return OTPayment::ERROR_STATE;
}
// ***********************************************************

// Since the temp values are not available until at least ONE instantiating has occured,
// this function forces that very scenario (cleanly) so you don't have to instantiate-and-
// then-delete a payment instrument. Instead, just call this, and then the temp values will
// be available thereafter.
//
bool OTPayment::SetTempValues() // this version for OTTrackable (all types EXCEPT purses.)
{
    if (OTPayment::PURSE == m_Type)
    {
        // Perform instantiation of a purse, then use it to set the temp values,
        // then cleans it up again before returning success/fail.
        //
        OTPurse * pPurse = this->InstantiatePurse();
        
        if (NULL == pPurse)
        {
            OTLog::vError("OTPayment::SetTempValues: Error: Failed instantiating OTPayment (purported purse) contents:\n\n%s\n\n",
                          m_strPayment.Get());
            return false;
        }
        OTCleanup<OTPurse> thePurseAngel(*pPurse); // (This automates the deletion.)
        // ----------------------------
        
        return this->SetTempValuesFromPurse(*pPurse);
    }
    // ----------------------------
    else
    {
        OTTrackable * pTrackable = this->Instantiate();
        
        if (NULL == pTrackable)
        {
            OTLog::vError("OTPayment::SetTempValues: Error: Failed instantiating OTPayment contents:\n\n%s\n\n",
                          m_strPayment.Get());
            return false;
        }
        // BELOW THIS POINT, MUST DELETE pTrackable!
        OTCleanup<OTTrackable> theTrackableAngel(*pTrackable); // (This automates the deletion.)
        // ----------------------------
        OTCheque        *   pCheque         = NULL;
        OTPaymentPlan   *   pPaymentPlan    = NULL;
        OTSmartContract *   pSmartContract  = NULL;    
        
        switch (m_Type) 
        {
            case CHEQUE:
            case VOUCHER:
            case INVOICE:
                pCheque = dynamic_cast<OTCheque *>(pTrackable);
                if (NULL == pCheque)
                    OTLog::vError("OTPayment::SetTempValues: Failure: dynamic_cast<OTCheque *>(pTrackable). Contents:\n\n%s\n\n",
                                  m_strPayment.Get());
                // Let's grab all the temp values from the cheque!!
                //
                else // success
                    return this->SetTempValuesFromCheque(*pCheque);
                break;

            case PAYMENT_PLAN:
                pPaymentPlan = dynamic_cast<OTPaymentPlan *>(pTrackable);
                if (NULL == pPaymentPlan)
                    OTLog::vError("OTPayment::SetTempValues: Failure: dynamic_cast<OTPaymentPlan *>(pTrackable). Contents:\n\n%s\n\n",
                                  m_strPayment.Get());
                // Let's grab all the temp values from the payment plan!!
                //
                else // success
                    return this->SetTempValuesFromPaymentPlan(*pPaymentPlan);
                break;
                
            case SMART_CONTRACT:
                pSmartContract = dynamic_cast<OTSmartContract *>(pTrackable);
                if (NULL == pSmartContract)
                    OTLog::vError("OTPayment::SetTempValues: Failure: dynamic_cast<OTSmartContract *>(pTrackable). Contents:\n\n%s\n\n",
                                  m_strPayment.Get());
                // Let's grab all the temp values from the smart contract!!
                //
                else // success
                    return this->SetTempValuesFromSmartContract(*pSmartContract);
                break;
                
            default:
                OTLog::vError("OTPayment::SetTempValues: Failure: Wrong m_Type. Contents:\n\n%s\n\n",
                              m_strPayment.Get());            
                return false;
        }
    }
    
    return false; // Should never actually reach this point.
}

// -----------------------------------------


bool OTPayment::SetTempValuesFromCheque(const OTCheque & theInput)
{
    switch (m_Type) 
    {
        case OTPayment::CHEQUE:
        case OTPayment::VOUCHER:
        case OTPayment::INVOICE:
            // -------------------------
            m_bAreTempValuesSet = true;
            // -------------------------
            m_lAmount           = theInput.GetAmount();         
            m_lTransactionNum   = theInput.GetTransactionNum();                
            // -------------------------
            if (theInput.GetMemo().Exists())
                m_strMemo.Set(theInput.GetMemo());
            else
                m_strMemo.Release();
            // -------------------------
            m_AssetTypeID   = theInput.GetAssetID();     
            m_ServerID      = theInput.GetServerID();     
            // ----------------------------
            m_SenderUserID  = theInput.GetSenderUserID();
            m_SenderAcctID  = theInput.GetSenderAcctID();    
            // ----------------------------        
            if (theInput.HasRecipient())
            {
                m_bHasRecipient   = true;
                m_RecipientUserID = theInput.GetRecipientUserID();
            }
            else
            {
                m_bHasRecipient   = false;
                m_RecipientUserID.Release();
            }
            // ----------------------------
            if (theInput.HasRemitter())
            {
                m_bHasRemitter   = true;
                m_RemitterUserID = theInput.GetRemitterID();
            }
            else
            {
                m_bHasRemitter   = false;
                m_RemitterUserID.Release();
            }
            // ----------------------------
            // NOTE: the "Recipient Acct" is NOT KNOWN when cheque is written, but only
            // once the cheque gets deposited. Therefore if type is CHEQUE, then Recipient
            // Acct ID is not set, and attempts to read it will result in failure.
            //
            m_RecipientAcctID.Release(); 
            // --------------------------------
            m_VALID_FROM    = theInput.GetValidFrom();      
            m_VALID_TO      = theInput.GetValidTo();
            // --------------------------------
            return true;
            
        default:
            OTLog::Error("OTPayment::SetTempValuesFromCheque: Error: Wrong type. (Returning false.)\n");
            break;
    }

    return false;
}



bool OTPayment::SetTempValuesFromPaymentPlan(const OTPaymentPlan & theInput)
{
    if (OTPayment::PAYMENT_PLAN == m_Type)
    {
        m_bAreTempValuesSet = true;
        m_bHasRecipient     = true;
        m_bHasRemitter      = false;
        // -------------------------
        m_lAmount           = theInput.GetInitialPaymentAmount();  // There're also regular payments of GetPaymentPlanAmount(). Can't fit 'em all.        
        m_lTransactionNum   = theInput.GetTransactionNum();                
        // -------------------------
        // const OTString &  OTPaymentPlan::GetConsideration() const 
        //                  { return m_strConsideration; }
        if (theInput.GetConsideration().Exists())
            m_strMemo.Set(theInput.GetConsideration());
        else
            m_strMemo.Release();
        // -------------------------
        m_AssetTypeID      = theInput.GetAssetID();     
        m_ServerID         = theInput.GetServerID();     
        // ----------------------------
        m_SenderUserID     = theInput.GetSenderUserID();    
        m_SenderAcctID     = theInput.GetSenderAcctID();    
        // ----------------------------        
        m_RecipientUserID  = theInput.GetRecipientUserID();
        m_RecipientAcctID  = theInput.GetRecipientAcctID();
        // ----------------------------
        m_RemitterUserID.Release();
        // ----------------------------
        m_VALID_FROM    = theInput.GetValidFrom();
        m_VALID_TO      = theInput.GetValidTo();
        // --------------------------------
        return true;
    }
    else
        OTLog::Error("OTPayment::SetTempValuesFromPaymentPlan: Error: Wrong type. (Returning false.)\n");

    return false;    
}

bool OTPayment::SetTempValuesFromSmartContract(const OTSmartContract & theInput)
{
    if (OTPayment::SMART_CONTRACT == m_Type)
    {
        m_bAreTempValuesSet = true;
        m_bHasRecipient     = false;
        m_bHasRemitter      = false;
        // -------------------------
        m_lAmount           = 0; // not used here.
        m_lTransactionNum   = theInput.GetTransactionNum();                
        // -------------------------
        // Note: Maybe later, store the Smart Contract's temporary name, or ID, in the memo field. 
        // Or something.
        //
        m_strMemo.Release(); // not used here.
        // -------------------------
        m_ServerID      = theInput.GetServerID();     
        m_AssetTypeID.Release(); // not used here.
        // ----------------------------
        m_SenderUserID  = theInput.GetSenderUserID();    
        m_SenderAcctID.Release();    
        // ----------------------------        
        m_RecipientUserID.Release(); // not used here.
        m_RecipientAcctID.Release(); // not used here.
        // ----------------------------
        m_RemitterUserID.Release();
        // ----------------------------
        m_VALID_FROM    = theInput.GetValidFrom();
        m_VALID_TO      = theInput.GetValidTo();
        // --------------------------------
        return true;
    }
    else
        OTLog::vError("%s: Error: Wrong type. (Returning false.)\n", __FUNCTION__);

    return false;    
}


bool OTPayment::SetTempValuesFromPurse(const OTPurse & theInput)
{
    if (OTPayment::PURSE == m_Type)
    {
        m_bAreTempValuesSet = true;
        m_bHasRecipient     = theInput.IsNymIDIncluded();
        m_bHasRemitter      = false;
        // -------------------------
        m_lAmount           = theInput.GetTotalValue();         
        m_lTransactionNum   = 0; // (A purse has no transaction number.)
        // -------------------------
        m_strMemo.Release(); // So far there's no purse memo (could add it, though.)
        // -------------------------
        m_AssetTypeID   = theInput.GetAssetID();     
        m_ServerID      = theInput.GetServerID();     
        // ----------------------------
        m_SenderUserID.Release();    
        m_SenderAcctID.Release();    
        // ----------------------------        
        if (!m_bHasRecipient || !theInput.GetNymID(m_RecipientUserID))
        {
            m_bHasRecipient = false;
            m_RecipientUserID.Release();
        }
        // ----------------------------
        m_RecipientAcctID.Release();
        // --------------------------------
        m_RemitterUserID.Release();
        // ----------------------------
        // NOTE: Have to iterate the tokens and choose which date we want from each,
        // and then decide how to best express that here.
//      m_VALID_FROM    = theInput.GetValidFrom();
//      m_VALID_TO      = theInput.GetValidTo();
        //
        m_VALID_FROM    = 0; // todo
        m_VALID_TO      = 0; // todo
        // --------------------------------
        return true;
    }
    else
        OTLog::Error("OTPayment::SetTempValuesFromPurse: Error: Wrong type. (Returning false.)\n");
    
    return false;    
}
// -------------------------------------------------------------------




bool OTPayment::GetMemo(OTString & strOutput) const
{
    strOutput.Release();
    // ----------------------
    if (!m_bAreTempValuesSet)
        return false;
    
    bool bSuccess = false;
    
    switch (m_Type) 
    {
        case OTPayment::CHEQUE:
        case OTPayment::VOUCHER:
        case OTPayment::INVOICE:
        case OTPayment::PAYMENT_PLAN:
            if (m_strMemo.Exists())
            {
                strOutput = m_strMemo;
                bSuccess = true;
            }
            else
                bSuccess = false;
            break;
            
        case OTPayment::SMART_CONTRACT:
        case OTPayment::PURSE:
            bSuccess = false;
            break;
            
        default:
            OTLog::Error("OTPayment::GetMemo: Bad payment type!\n");
            break;
    }
    
    return bSuccess;
}




bool OTPayment::GetAmount(long & lOutput) const
{
    lOutput = 0;
    // ----------------------
    if (!m_bAreTempValuesSet)
        return false;
    
    bool bSuccess = false;
    
    switch (m_Type) 
    {
        case OTPayment::CHEQUE:
        case OTPayment::VOUCHER:
        case OTPayment::INVOICE:
        case OTPayment::PAYMENT_PLAN:
        case OTPayment::PURSE:
            lOutput  = m_lAmount;
            bSuccess = true;
            break;
            
        case OTPayment::SMART_CONTRACT:
            lOutput  = 0;
            bSuccess = false;
            break;
            
        default:
            OTLog::Error("OTPayment::GetAmount: Bad payment type!\n");
            break;
    }
    
    return bSuccess;
}

// This works with a cheque who has a transaction number.
// It also works with a payment plan or smart contract, for opening AND closing numbers.
bool OTPayment::HasTransactionNum(const long & lInput) const
{
    // SMART CONTRACTS and PAYMENT PLANS get a little special
    // treatment here at the top.
    //
    if ((false == m_bAreTempValuesSet)        || // Why is this here? Because if temp values haven't
        (OTPayment::SMART_CONTRACT == m_Type) || // been set yet, then m_Type isn't set either.
        (OTPayment::PAYMENT_PLAN   == m_Type) )
    {
        OTTrackable * pTrackable = this->Instantiate();
        if ( NULL  == pTrackable )
        {
            OTLog::vError("%s: Failed instantiating OTPayment containing:\n%s\n",
                          __FUNCTION__, m_strPayment.Get());
            return false;
        } // BELOW THIS POINT, MUST DELETE pTrackable!
        OTCleanup<OTTrackable> theTrackableAngel(*pTrackable); // (This automates the DELETION.)
        // ----------------------------
        OTSmartContract * pSmartContract = NULL;
        pSmartContract = dynamic_cast<OTSmartContract *>(pTrackable);
        // ----------------------------
        OTPaymentPlan * pPlan = NULL;
        pPlan = dynamic_cast<OTPaymentPlan *>(pTrackable);
        // ----------------------------        
        if (NULL != pSmartContract)
        {
            if (pSmartContract->HasTransactionNum(lInput))
                return true;
            return false;
        }
        else if (NULL != pPlan)
        {
            if (pPlan->HasTransactionNum(lInput))
                return true;
            return false;
        }
    }
    // -------------------------------------------
    if (!m_bAreTempValuesSet)  // This normally fails, for all payment types except the ones above.
        return false;
    // -------------------------------------------
    //
    // Next: ALL OTHER payment types...
    //
    bool bSuccess = false;
    
    switch (m_Type)
    {
        case OTPayment::CHEQUE:
        case OTPayment::VOUCHER:
        case OTPayment::INVOICE:            
            if (lInput == m_lTransactionNum)
                bSuccess = true;
            break;

        case OTPayment::PURSE:
            bSuccess = false;
            break;
            
        default:
        case OTPayment::PAYMENT_PLAN:   // Should never happen.
        case OTPayment::SMART_CONTRACT: // Should never happen.
            OTLog::Error("OTPayment::HasTransactionNum: Bad payment type!\n");
            break;
    }
    
    return bSuccess;
}



bool OTPayment::GetClosingNum(      long         & lOutput,
                              const OTIdentifier & theAcctID)   const
{
    lOutput = 0;
    // ----------------------
    // SMART CONTRACTS and PAYMENT PLANS get a little special
    // treatment here at the top.
    //
    if ((false == m_bAreTempValuesSet)        || // m_Type isn't even set if this is false.
        (OTPayment::SMART_CONTRACT == m_Type) ||
        (OTPayment::PAYMENT_PLAN   == m_Type) )
    {
        OTTrackable * pTrackable = this->Instantiate();
        if ( NULL  == pTrackable )
        {
            OTLog::vError("%s: Failed instantiating OTPayment containing:\n%s\n",
                          __FUNCTION__, m_strPayment.Get());
            return false;
        } // BELOW THIS POINT, MUST DELETE pTrackable!
        OTCleanup<OTTrackable> theTrackableAngel(*pTrackable); // (This automates the DELETION.)
        // ----------------------------
        OTSmartContract * pSmartContract = NULL;
        pSmartContract = dynamic_cast<OTSmartContract *>(pTrackable);
        // ----------------------------
        OTPaymentPlan * pPlan = NULL;
        pPlan = dynamic_cast<OTPaymentPlan *>(pTrackable);
        // ----------------------------
        if (NULL != pSmartContract)
        {
            lOutput = pSmartContract->GetClosingNumber(theAcctID);
            if (lOutput > 0)
                return true;
            return false;
        }
        else if (NULL != pPlan)
        {
            lOutput = pPlan->GetClosingNumber(theAcctID);
            if (lOutput > 0)
                return true;
            return false;
        }
    }
    // -------------------------------------------
    if (!m_bAreTempValuesSet)
        return false;
    // -------------------------------------------
    //
    // Next: ALL OTHER payment types...
    //
    bool bSuccess = false;
    
    switch (m_Type)
    {
        // ------------------------
        case OTPayment::CHEQUE:
        case OTPayment::VOUCHER:
        case OTPayment::INVOICE:
        case OTPayment::PURSE:
            lOutput  = 0; // Redundant, but just making sure.
            bSuccess = false;
            break;
        // ------------------------
        default:
        case OTPayment::PAYMENT_PLAN:
        case OTPayment::SMART_CONTRACT:
            OTLog::vError("%s: Bad payment type!\n", __FUNCTION__);
            break;
        // ------------------------
    }
    
    return bSuccess;
}


bool OTPayment::GetOpeningNum(      long         & lOutput,
                              const OTIdentifier & theNymID)   const
{
    lOutput = 0;
    // ----------------------
    // SMART CONTRACTS and PAYMENT PLANS get a little special
    // treatment here at the top.
    //
    if ((false == m_bAreTempValuesSet)        || // m_Type isn't even set if this is false.
        (OTPayment::SMART_CONTRACT == m_Type) ||
        (OTPayment::PAYMENT_PLAN   == m_Type) )
    {
        OTTrackable * pTrackable = this->Instantiate();
        if ( NULL  == pTrackable )
        {
            OTLog::vError("%s: Failed instantiating OTPayment containing:\n%s\n",
                          __FUNCTION__, m_strPayment.Get());
            return false;
        } // BELOW THIS POINT, MUST DELETE pTrackable!
        OTCleanup<OTTrackable> theTrackableAngel(*pTrackable); // (This automates the DELETION.)
        // ----------------------------
        OTSmartContract * pSmartContract = NULL;
        pSmartContract = dynamic_cast<OTSmartContract *>(pTrackable);
        // ----------------------------
        OTPaymentPlan * pPlan = NULL;
        pPlan = dynamic_cast<OTPaymentPlan *>(pTrackable);
        // ----------------------------
        if (NULL != pSmartContract)
        {
            lOutput = pSmartContract->GetOpeningNumber(theNymID);
            if (lOutput > 0)
                return true;
            return false;
        }
        else if (NULL != pPlan)
        {
            lOutput = pPlan->GetOpeningNumber(theNymID);
            if (lOutput > 0)
                return true;
            return false;
        }
    }
    // -------------------------------------------
    if (!m_bAreTempValuesSet)
        return false;
    // -------------------------------------------
    //
    // Next: ALL OTHER payment types...
    //
    bool bSuccess = false;
    
    switch (m_Type)
    {
        // ------------------------
        case OTPayment::CHEQUE:
        case OTPayment::VOUCHER:
        case OTPayment::INVOICE:
            if (theNymID == m_SenderUserID)
            {
                lOutput = m_lTransactionNum;  // The "opening" number for a cheque is the ONLY number it has.
                bSuccess = true;
            }
            else
            {
                lOutput  = 0;
                bSuccess = false;
            }
            break;
        // ------------------------            
        case OTPayment::PURSE:
            lOutput  = 0; // Redundant, but just making sure.
            bSuccess = false;
            break;
        // ------------------------
        default:
        case OTPayment::PAYMENT_PLAN:
        case OTPayment::SMART_CONTRACT:
            OTLog::vError("%s: Bad payment type!\n", __FUNCTION__);
            break;
        // ------------------------
    }
    
    return bSuccess;
}


bool OTPayment::GetTransactionNum(long & lOutput) const
{
    lOutput = 0;
    // ----------------------
    if (!m_bAreTempValuesSet)
        return false;
    
    bool bSuccess = false;
    
    switch (m_Type) 
    {
        case OTPayment::CHEQUE:
        case OTPayment::VOUCHER:
        case OTPayment::INVOICE:
        case OTPayment::PAYMENT_PLAN: // For payment plans, this is the opening transaction FOR THE NYM who activated the contract (probably the customer.)
        case OTPayment::SMART_CONTRACT: // For smart contracts, this is the opening transaction number FOR THE NYM who activated the contract.
            lOutput  = m_lTransactionNum;
            bSuccess = true;
            break;
            
        case OTPayment::PURSE:
            lOutput  = 0;
            bSuccess = false;
            break;
            
        default:
            OTLog::Error("OTPayment::GetTransactionNum: Bad payment type!\n");
            break;
    }
    
    return bSuccess;
}

bool OTPayment::GetValidFrom(time_t & tOutput) const
{
    tOutput = 0;
    // ----------------------
    if (!m_bAreTempValuesSet)
        return false;
    
    bool bSuccess = false;
    
    switch (m_Type) 
    {
        case OTPayment::CHEQUE:
        case OTPayment::VOUCHER:
        case OTPayment::INVOICE:
        case OTPayment::PAYMENT_PLAN:
        case OTPayment::SMART_CONTRACT:
            tOutput  = m_VALID_FROM;
            bSuccess = true;
            break;
            
        case OTPayment::PURSE:
            tOutput  = 0;
            bSuccess = false;
            break;
            
        default:
            OTLog::Error("OTPayment::GetValidFrom: Bad payment type!\n");
            break;
    }
    
    return bSuccess;
}

bool OTPayment::GetValidTo(time_t & tOutput) const
{
    tOutput = 0;
    // ----------------------
    if (!m_bAreTempValuesSet)
        return false;
    
    bool bSuccess = false;
    
    switch (m_Type) 
    {
        case OTPayment::CHEQUE:
        case OTPayment::VOUCHER:
        case OTPayment::INVOICE:
        case OTPayment::PAYMENT_PLAN:
        case OTPayment::SMART_CONTRACT:
            tOutput  = m_VALID_TO;
            bSuccess = true;
            break;
            
        case OTPayment::PURSE:
            tOutput  = 0;
            bSuccess = false;
            break;
            
        default:
            OTLog::Error("OTPayment::GetValidTo: Bad payment type!\n");
            break;
    }
    
    return bSuccess;
}

bool OTPayment::GetAssetTypeID(OTIdentifier & theOutput) const
{
    theOutput.Release();
    // ----------------------
    if (!m_bAreTempValuesSet)
        return false;
    
    bool bSuccess = false;
    
    switch (m_Type) 
    {
        case OTPayment::CHEQUE:
        case OTPayment::VOUCHER:
        case OTPayment::INVOICE:
        case OTPayment::PAYMENT_PLAN:
        case OTPayment::PURSE:
            theOutput = m_AssetTypeID;
            bSuccess  = true;
            break;
            
        case OTPayment::SMART_CONTRACT:
            bSuccess  = false;
            break;
            
        default:
            OTLog::Error("OTPayment::GetAssetTypeID: Bad payment type!\n");
            break;
    }
    
    return bSuccess;
}

bool OTPayment::GetServerID(OTIdentifier & theOutput) const
{
    theOutput.Release();
    // ----------------------
    if (!m_bAreTempValuesSet)
        return false;
    
    bool bSuccess = false;
    
    switch (m_Type) 
    {
        case OTPayment::CHEQUE:
        case OTPayment::VOUCHER:
        case OTPayment::INVOICE:
        case OTPayment::PAYMENT_PLAN:
        case OTPayment::SMART_CONTRACT:
        case OTPayment::PURSE:
            theOutput = m_ServerID;
            bSuccess  = true;
            break;
            
        default:
            OTLog::Error("OTPayment::GetServerID: Bad payment type!\n");
            break;
    }
    
    return bSuccess;
}


// With a voucher (cashier's cheque) the "bank" is the "sender",
// whereas the actual Nym who purchased it is the "remitter."
//
bool OTPayment::GetRemitterUserID(OTIdentifier & theOutput) const
{
    theOutput.Release();
    // ----------------------
    if (!m_bAreTempValuesSet)
        return false;
    
    bool bSuccess = false;
    
    switch (m_Type)
    {
        case OTPayment::VOUCHER:
            theOutput = m_RemitterUserID;
            bSuccess  = true;
            break;
            
        default:
            OTLog::Error("OTPayment::GetRemitterUserID: Bad payment type! Expected a voucher cheque.\n");
            break;
    }
    
    return bSuccess;
}


bool OTPayment::GetSenderUserID(OTIdentifier & theOutput) const
{
    theOutput.Release();
    // ----------------------
    if (!m_bAreTempValuesSet)
        return false;
    
    bool bSuccess = false;
    
    switch (m_Type) 
    {
        case OTPayment::CHEQUE:
        case OTPayment::VOUCHER:
        case OTPayment::INVOICE:
        case OTPayment::PAYMENT_PLAN:
        case OTPayment::SMART_CONTRACT:
            theOutput = m_SenderUserID;
            bSuccess  = true;
            break;
            
        case OTPayment::PURSE:
            bSuccess  = false;
            break;
            
        default:
            OTLog::Error("OTPayment::GetSenderUserID: Bad payment type!\n");
            break;
    }
    
    return bSuccess;
}

bool OTPayment::GetSenderAcctID(OTIdentifier & theOutput) const
{
    theOutput.Release();
    // ----------------------
    if (!m_bAreTempValuesSet)
        return false;
    
    bool bSuccess = false;
    
    switch (m_Type) 
    {
        case OTPayment::CHEQUE:
        case OTPayment::VOUCHER:
        case OTPayment::INVOICE:
        case OTPayment::PAYMENT_PLAN:
            theOutput = m_SenderAcctID;
            bSuccess  = true;
            break;
            
        case OTPayment::SMART_CONTRACT:
        case OTPayment::PURSE:
            bSuccess  = false;
            break;
            
        default:
            OTLog::Error("OTPayment::GetSenderAcctID: Bad payment type!\n");
            break;
    }
    
    return bSuccess;
}




bool OTPayment::GetRecipientUserID(OTIdentifier & theOutput) const
{
    theOutput.Release();
    // ----------------------
    if (!m_bAreTempValuesSet)
        return false;
    
    bool bSuccess = false;
    
    switch (m_Type) 
    {
        case OTPayment::CHEQUE:
        case OTPayment::VOUCHER:
        case OTPayment::INVOICE:
        case OTPayment::PAYMENT_PLAN:
        case OTPayment::PURSE:
            if (m_bHasRecipient)
            {
                theOutput = m_RecipientUserID;
                bSuccess  = true;
            }
            else
                bSuccess  = false;

            break;
            
        case OTPayment::SMART_CONTRACT:
            bSuccess  = false;
            break;
            
        default:
            OTLog::Error("OTPayment::GetRecipientUserID: Bad payment type!\n");
            break;
    }
    
    return bSuccess;
}


bool OTPayment::GetRecipientAcctID(OTIdentifier & theOutput) const
{
    // NOTE:
    // A cheque HAS NO "Recipient Asset Acct ID", since the recipient's account (where he deposits
    // the cheque) is not known UNTIL the time of the deposit. It's certain not known at the time 
    // that the cheque is written...

    theOutput.Release();
    // ----------------------
    if (!m_bAreTempValuesSet)
        return false;
    
    bool bSuccess = false;
    
    switch (m_Type) 
    {
        case OTPayment::PAYMENT_PLAN:
            if (m_bHasRecipient)
            {
                theOutput = m_RecipientAcctID;
                bSuccess  = true;
            }
            else
                bSuccess  = false;
            
            break;
            
        case OTPayment::CHEQUE:
        case OTPayment::VOUCHER:
        case OTPayment::INVOICE:
        case OTPayment::SMART_CONTRACT:
        case OTPayment::PURSE:  // A purse might have a recipient USER, but never a recipient ACCOUNT.
            bSuccess  = false;
            break;
            
        default:
            OTLog::Error("OTPayment::GetRecipientAcctID: Bad payment type!\n");
            break;
    }
    
    return bSuccess;
}

// -----------------------------------------





OTPayment::OTPayment()
:   ot_super(),
    m_Type(OTPayment::ERROR_STATE),
    m_bAreTempValuesSet(false),
    m_bHasRecipient(false),
    m_bHasRemitter(false),
    m_lAmount(0),
    m_lTransactionNum(0),
    m_VALID_FROM(0),
    m_VALID_TO(0)
{
	InitPayment();
}


OTPayment::OTPayment(const OTString & strPayment)
:   ot_super(),
    m_Type(OTPayment::ERROR_STATE),
    m_bAreTempValuesSet(false),
    m_bHasRecipient(false),
    m_bHasRemitter(false),
    m_lAmount(0),
    m_lTransactionNum(0),
    m_VALID_FROM(0),
    m_VALID_TO(0)
{
	InitPayment();
    
    SetPayment(strPayment);
}
// -----------------------------------------------------

// CALLER is responsible to delete.
//
OTTrackable * OTPayment::Instantiate() const
{
    OTContract *        pContract       = NULL;
    OTTrackable *       pTrackable      = NULL;
    OTCheque *          pCheque         = NULL;
    OTPaymentPlan *     pPaymentPlan    = NULL;
    OTSmartContract *   pSmartContract  = NULL;
    
    switch (m_Type)
    {
        case CHEQUE:
        case VOUCHER:
        case INVOICE:
            pContract = OTContract::InstantiateContract(m_strPayment);
            
            if (NULL != pContract)
            {
                pCheque  = dynamic_cast<OTCheque *>(pContract);
            
                if (NULL == pCheque)
                {
                    OTLog::vError("OTPayment::Instantiate: Tried to instantiate cheque, but factory returned non-cheque:\n\n%s\n\n",
                                  m_strPayment.Get());
                    delete pContract; pContract = NULL;
                }
                else
                    pTrackable = pCheque;
            }
            else
                OTLog::vError("OTPayment::Instantiate: Tried to instantiate cheque, but factory returned NULL:\n\n%s\n\n",
                              m_strPayment.Get());
            break;
            
        case PAYMENT_PLAN:
            pContract = OTContract::InstantiateContract(m_strPayment);
            
            if (NULL != pContract)
            {
                pPaymentPlan = dynamic_cast<OTPaymentPlan *>(pContract);
                
                if (NULL == pPaymentPlan)
                {
                    OTLog::vError("OTPayment::Instantiate: Tried to instantiate payment plan, but factory returned non-payment-plan:\n\n%s\n\n",
                                  m_strPayment.Get());
                    delete pContract; pContract = NULL;
                }
                else
                    pTrackable = pPaymentPlan;
            }
            else
                OTLog::vError("OTPayment::Instantiate: Tried to instantiate payment plan, but factory returned NULL:\n\n%s\n\n",
                              m_strPayment.Get());
            break;
            
        case SMART_CONTRACT:
            pContract = OTContract::InstantiateContract(m_strPayment);
            
            if (NULL != pContract)
            {
                pSmartContract  = dynamic_cast<OTSmartContract *>(pContract);
                
                if (NULL == pSmartContract)
                {
                    OTLog::vError("%s: Tried to instantiate smart contract, but factory "
                                  "returned non-smart-contract:\n\n%s\n\n", __FUNCTION__,
                                  m_strPayment.Get());
                    delete pContract; pContract = NULL;
                }
                else
                    pTrackable = pSmartContract;
            }
            else
                OTLog::vError("OTPayment::Instantiate: Tried to instantiate smart contract, but factory returned NULL:\n\n%s\n\n",
                              m_strPayment.Get());
            break;
        case PURSE:
            OTLog::Error("OTPayment::Instantiate: ERROR: Tried to instantiate purse, but should have called OTPayment::InstantiatePurse.\n");
            return NULL;
        default:
            OTLog::vError("OTPayment::Instantiate: ERROR: Tried to instantiate payment object, but had a bad type. Contents:\n\n%s\n\n",
                          m_strPayment.Get());
            return NULL;
    }
    
    return pTrackable;  
}


OTTrackable * OTPayment::Instantiate(const OTString & strPayment)
{
    if (this->SetPayment(strPayment))
        return this->Instantiate();
    
    return NULL;
}

// -------------------------------------------

// You need the server ID to instantiate a purse, unlike all the
// other payment types. UPDATE: Not anymore.
//
// CALLER is responsible to delete!
//
OTPurse * OTPayment::InstantiatePurse() const
{
    if (OTPayment::PURSE == this->GetType())
	{
        return OTPurse::PurseFactory(m_strPayment);
   	}
    else
        OTLog::vError("OTPayment::InstantiatePurse: Failure: This payment object does NOT contain a purse. "
                      "Contents:\n\n%s\n\n", m_strPayment.Get());
    
    return NULL;
}

/*
OTPurse * OTPayment::InstantiatePurse(const OTIdentifier & SERVER_ID) const
{
    if (OTPayment::PURSE == this->GetType())
	{
        return OTPurse::PurseFactory(m_strPayment, SERVER_ID);
   	}
    else
        OTLog::vError("OTPayment::InstantiatePurse: Failure: This payment object does NOT contain a purse. "
                      "Contents:\n\n%s\n\n", m_strPayment.Get());
    
    return NULL;
}

OTPurse * OTPayment::InstantiatePurse(const OTIdentifier & SERVER_ID, const OTIdentifier & ASSET_ID) const
{
    if (OTPayment::PURSE == this->GetType())
	{
        return OTPurse::PurseFactory(m_strPayment, SERVER_ID, ASSET_ID);
   	}
    else
        OTLog::vError("OTPayment::InstantiatePurse: Failure: This payment object does NOT contain a purse. "
                      "Contents:\n\n%s\n\n", m_strPayment.Get());
    
    return NULL;
}
*/

// -------------------------------------------


OTPurse * OTPayment::InstantiatePurse(const OTString & strPayment)
{
    if (false == this->SetPayment(strPayment))
        OTLog::vError("OTPayment::InstantiatePurse: WARNING: Failed setting the payment string based on "
                      "what was passed in:\n\n%s\n\n", strPayment.Get());
    else if (OTPayment::PURSE != m_Type)
        OTLog::vError("OTPayment::InstantiatePurse: WARNING: No purse was found in the "
                      "payment string:\n\n%s\n\n", strPayment.Get());
    else
        return this->InstantiatePurse();
    
    return NULL;
}

// -------------------------------------------

/*
OTPurse * OTPayment::InstantiatePurse(const OTIdentifier & SERVER_ID, const OTString & strPayment)
{
    if (false == this->SetPayment(strPayment))
        OTLog::vError("OTPayment::InstantiatePurse: WARNING: Failed setting the payment string based on "
                      "what was passed in:\n\n%s\n\n", strPayment.Get());
    else if (OTPayment::PURSE != m_Type)
        OTLog::vError("OTPayment::InstantiatePurse: WARNING: No purse was found in the "
                      "payment string:\n\n%s\n\n", strPayment.Get());
    else
        return this->InstantiatePurse(SERVER_ID);
    
    return NULL;
}

// -------------------------------------------

OTPurse * OTPayment::InstantiatePurse(const OTIdentifier & SERVER_ID, const OTIdentifier & ASSET_ID, const OTString & strPayment)
{
    if (false == this->SetPayment(strPayment))
        OTLog::vError("OTPayment::InstantiatePurse: WARNING: Failed setting the payment string based on "
                      "what was passed in:\n\n%s\n\n", strPayment.Get());
    else if (OTPayment::PURSE != m_Type)
        OTLog::vError("OTPayment::InstantiatePurse: WARNING: No purse was found in the "
                      "payment string:\n\n%s\n\n", strPayment.Get());
    else
        return this->InstantiatePurse(SERVER_ID, ASSET_ID);
    
    return NULL;
}
*/
// -------------------------------------------


bool OTPayment::SetPayment(const OTString & strPayment)
{
    if (!strPayment.Exists())
		return false;
    // --------------------------------------------------------------------
    OTString strContract(strPayment);
    
    if (false == strContract.DecodeIfArmored(false)) // bEscapedIsAllowed=true by default.
    {
        OTLog::vError("%s: Input string apparently was encoded and then failed decoding. Contents: \n%s\n",
                      __FUNCTION__, strPayment.Get());
        return false;
    }
    // ------------------------------------------
    m_strPayment.Release();
    // ----------------------
    // todo: should be "starts with" and perhaps with a trim first
    //
    if (strContract.Contains("-----BEGIN SIGNED CHEQUE-----"))
        m_Type  = OTPayment::CHEQUE;
    else if (strContract.Contains("-----BEGIN SIGNED VOUCHER-----"))
        m_Type  = OTPayment::VOUCHER;
    else if (strContract.Contains("-----BEGIN SIGNED INVOICE-----"))
        m_Type  = OTPayment::INVOICE;
    // -------------------
    else if (strContract.Contains("-----BEGIN SIGNED PAYMENT PLAN-----"))
        m_Type  = OTPayment::PAYMENT_PLAN;
    else if (strContract.Contains("-----BEGIN SIGNED SMARTCONTRACT-----"))
        m_Type  = OTPayment::SMART_CONTRACT;
    // -------------------
    else if (strContract.Contains("-----BEGIN SIGNED PURSE-----"))
        m_Type  = OTPayment::PURSE;
    else
    {
        m_Type  = OTPayment::ERROR_STATE;
        
        OTLog::vError("%s: Failure: Unable to determine payment type, from input:\n\n%s\n\n",
                      __FUNCTION__, strContract.Get());
    }
    // ----------------------
    if (OTPayment::ERROR_STATE == m_Type)
        return false;

    // *********************************
    
    m_strPayment.Set(strContract);
    
    // *********************************
    
    return true;
}
// -------------------------------------------


void OTPayment::InitPayment()
{
    m_Type              = OTPayment::ERROR_STATE;
    m_lAmount           = 0;
    m_lTransactionNum   = 0;
    m_VALID_FROM        = 0;
    m_VALID_TO          = 0;
    m_bAreTempValuesSet = false;
    m_bHasRecipient     = false;
    m_bHasRemitter      = false;
	m_strContractType.Set("PAYMENT");
}



OTPayment::~OTPayment()
{
    Release_Payment();
}

void OTPayment::Release_Payment()
{
    m_Type              = OTPayment::ERROR_STATE;
	m_lAmount           = 0;
    m_lTransactionNum   = 0;
    m_VALID_FROM        = 0;
    m_VALID_TO          = 0;
    // --------------------------------
    m_strPayment.Release();
    // --------------------------------
    m_bAreTempValuesSet = false;
    m_bHasRecipient     = false;
    m_bHasRemitter      = false;
    // --------------------------------
    m_strMemo.Release();
    // --------------------------------
    m_AssetTypeID.Release();
    m_ServerID.Release();
    // --------------------------------    
    m_SenderUserID.Release();
    m_SenderAcctID.Release();
    m_RecipientUserID.Release();
    m_RecipientAcctID.Release();
    // --------------------------------
    m_RemitterUserID.Release();
    // ----------------------------
}


void OTPayment::Release()
{
    Release_Payment();
    // --------------------------------
    // Finally, we call the method we overrode:
    //
	ot_super::Release();
}




void OTPayment::UpdateContents() // Before transmission or serialization, this is where the Purse saves its contents 
{	
	// I release this because I'm about to repopulate it.
	m_xmlUnsigned.Release();
	
	m_xmlUnsigned.Concatenate("<?xml version=\"%s\"?>\n\n", "1.0");		
	
	m_xmlUnsigned.Concatenate("<payment version=\"%s\"\n"
                              " type=\"%s\">\n\n",
							  m_strVersion.Get(),
                              this->GetTypeString());		
    
    if (m_strPayment.Exists())
    {
        const OTASCIIArmor ascContents(m_strPayment);
        
        if (ascContents.Exists())
            m_xmlUnsigned.Concatenate("<contents>\n%s</contents>\n\n", ascContents.Get());
    }
    
	m_xmlUnsigned.Concatenate("</payment>\n");			
}



int OTPayment::ProcessXMLNode(irr::io::IrrXMLReader*& xml)
{
    const OTString strNodeName(xml->getNodeName());
    
	if (strNodeName.Compare("payment"))
	{	
		m_strVersion = xml->getAttributeValue("version"); 

        const OTString strPaymentType = xml->getAttributeValue("type");
        
		if (strPaymentType.Exists())
			m_Type = OTPayment::GetTypeFromString(strPaymentType);
        else
            m_Type = OTPayment::ERROR_STATE;
        
		OTLog::vOutput(4, "Loaded payment... Type: %s\n----------\n",
                       this->GetTypeString());
		
		return (OTPayment::ERROR_STATE == m_Type) ? (-1) : 1;
	}
	
	else if (strNodeName.Compare("contents")) 
	{
        OTString strContents;
		
		if (!OTContract::LoadEncodedTextField(xml, strContents) || 
            !strContents.Exists() ||
            // -------------------------------
            !this->SetPayment(strContents))
		{
			OTLog::vError("OTPayment::ProcessXMLNode: ERROR: \"contents\" field without a value, OR error setting that "
                          "value onto this object. Raw:\n\n%s\n\n", strContents.Get());
			
			return (-1); // error condition
		}
		// else success -- the value is now set on this object.
        // todo security: Make sure the type of the payment that's ACTUALLY there
        // matches the type expected (based on the m_Type that we already read, above.)
        
		return 1;
	}

	return 0;
}



bool OTPayment::SaveContractWallet(std::ofstream & ofs)	
{
	return true;
}


