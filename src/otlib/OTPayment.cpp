/************************************************************************************
 *    
 *  OTPayment.cpp
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
    "PAYMENT_PLAN",   // An OTCronItem-derived OTPaymentPlan, related to a recurring payment plan.
    "SMART_CONTRACT", // An OTCronItem-derived OTSmartContract, related to a smart contract.
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
        // -------------------------
        m_lAmount           = 0; // not used here.
        m_lTransactionNum   = theInput.GetTransactionNum();                
        // -------------------------
        // Note: Maybe later, store the Smart Contract's temporary name, or ID, in the memo field. 
        // Or something.
        //
        m_strMemo.Release(); // not used here.
        // -------------------------
        m_ServerID         = theInput.GetServerID();     
        m_AssetTypeID.Release(); // not used here.
        // ----------------------------
        m_SenderUserID     = theInput.GetSenderUserID();    
        m_SenderAcctID.Release();    
        // ----------------------------        
        m_RecipientUserID.Release(); // not used here.
        m_RecipientAcctID.Release(); // not used here.
        // ----------------------------
        m_VALID_FROM    = theInput.GetValidFrom();      
        m_VALID_TO      = theInput.GetValidTo();
        // --------------------------------
        return true;
    }
    else
        OTLog::Error("OTPayment::SetTempValuesFromSmartContract: Error: Wrong type. (Returning false.)\n");

    return false;    
}


bool OTPayment::SetTempValuesFromPurse(const OTPurse & theInput)
{
    if (OTPayment::PURSE == m_Type)
    {
        m_bAreTempValuesSet = true;
        m_bHasRecipient     = theInput.IsNymIDIncluded();
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
        case OTPayment::PAYMENT_PLAN:
        case OTPayment::SMART_CONTRACT:
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
                    OTLog::vError("OTPayment::Instantiate: Tried to instantiate smart contract, but factory "
                                  "returned non-smart-contract:\n\n%s\n\n", m_strPayment.Get());
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
    
    const char * szFunc = "OTPayment::SetPayment";
    // --------------------------------------------------------------------
	//
    // To support legacy data, we check here to see if it's armored or not.
    // If it's not, we support it. But if it IS, we ALSO support it (we de-armor it here.)
    //
    bool bArmoredAndALSOescaped = false;    // "- -----BEGIN OT ARMORED"
    bool bArmoredButNOTescaped  = false;    // "-----BEGIN OT ARMORED"
    
    if (strPayment.Contains(OT_BEGIN_ARMORED_escaped)) // check this one first...
    {
        bArmoredAndALSOescaped = true;
        
        OTLog::vError("%s: Armored and escaped value passed in, but "
                     "escaped are forbidden here. (Returning false.)\n", szFunc);
		return false;
    }
    else if (strPayment.Contains(OT_BEGIN_ARMORED))
    {
        bArmoredButNOTescaped = true;
    }
    // ----------------------------------------
    const bool bArmored = (bArmoredAndALSOescaped || bArmoredButNOTescaped);
    // ----------------------------------------
    
    // Whether the string is armored or not, (-----BEGIN OT ARMORED)
    // either way, we'll end up with the decoded version in this variable:
    //
    std::string str_Trim;
    
    // ------------------------------------------------
    if (bArmored) // it's armored, we have to decode it first.
    {
        OTASCIIArmor ascTemp;
        OTString strPaymentTemp(strPayment);
        
        if (false == (ascTemp.LoadFromString(strPaymentTemp, 
                                             bArmoredAndALSOescaped, // if it IS escaped or not, this variable will be true or false to show it.
                                             // The below szOverride sub-string determines where the content starts, when loading.
                                             OT_BEGIN_ARMORED)))     // Default is:       "-----BEGIN" 
                                                                     // We're doing this: "-----BEGIN OT ARMORED" (Should worked for escaped as well, here.)
        {
            OTLog::vError("%s: Error loading string contents from ascii-armored encoding. Contents: \n%s\n",
                          szFunc, strPayment.Get());
            return false;
        }
        else // success loading the actual contents out of the ascii-armored version.
        {
            OTString strTemp(ascTemp); // <=== ascii-decoded here.
            
            std::string str_temp(strTemp.Get(), strTemp.GetLength());
            
            str_Trim = OTString::trim(str_temp); // This is the std::string for the trim process.
        } 
    }
    else
    {
        std::string str_temp(strPayment.Get(), strPayment.GetLength());
        str_Trim = OTString::trim(str_temp); // This is the std::string for the trim process. (Wasn't armored, so here we use it as passed in.)
    }
    // ------------------------------------------------
    
    // At this point, str_Trim contains the actual contents, whether they
    // were originally ascii-armored OR NOT. (And they are also now trimmed, either way.)
    // ------------------------------------------
    
    OTString strContract(str_Trim.c_str());
    
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
    else if (strContract.Contains("-----BEGIN SIGNED SMART CONTRACT-----"))
        m_Type  = OTPayment::SMART_CONTRACT;
    // -------------------
    else if (strContract.Contains("-----BEGIN SIGNED PURSE-----"))
        m_Type  = OTPayment::PURSE;
    else
    {
        m_Type  = OTPayment::ERROR_STATE;
        
        OTLog::vError("%s: Failure: Unable to determine payment type, from input:\n\n%s\n\n",
                      szFunc, strContract.Get());
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


