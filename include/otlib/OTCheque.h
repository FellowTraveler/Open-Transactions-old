/*************************************************************
 *    
 *  OTCheque.h
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


#ifndef __OT_CHEQUE_H__
#define __OT_CHEQUE_H__

#ifndef EXPORT
#define EXPORT
#endif
#include <ExportWrapper.h>

#include <ctime>
#include <fstream>


#include "OTTrackable.h"
#include "OTIdentifier.h"
#include "OTString.h"



class OTCheque : public OTTrackable
{
private:  // Private prevents erroneous use by other classes.
    typedef OTTrackable ot_super;

protected:
	virtual int ProcessXMLNode(irr::io::IrrXMLReader*& xml);

	long			m_lAmount;
	OTString		m_strMemo;
	OTIdentifier	m_RECIPIENT_USER_ID;// Optional. If present, must match depositor's user ID.
	bool			m_bHasRecipient;
	OTIdentifier	m_REMITTER_ID; // In the case of vouchers (cashier's cheques) we store the Remitter's ID.
	bool			m_bHasRemitter;
	
public:
	inline void  SetAsVoucher(const OTIdentifier & theRemitter)
    { m_REMITTER_ID = theRemitter; m_bHasRemitter = true; m_strContractType = "VOUCHER"; }
    // ---------------------------------------------------------------------------
	inline const OTString     &	GetMemo()             const { return m_strMemo; }
	inline const long         & GetAmount()           const { return m_lAmount; }
	inline const OTIdentifier &	GetRecipientUserID()  const { return m_RECIPIENT_USER_ID; }
	inline bool                 HasRecipient()        const { return m_bHasRecipient; }
	inline const OTIdentifier &	GetRemitterID()       const { return m_REMITTER_ID; }
	inline bool                 HasRemitter()         const { return m_bHasRemitter; }

    // A cheque HAS NO "Recipient Asset Acct ID", since the recipient's account (where he deposits
    // the cheque) is not known UNTIL the time of the deposit. It's certain not known at the time 
    // that the cheque is written...
    // --------------------------------------------------
	
	// Calling this function is like writing a check...
EXPORT	bool IssueCheque(const long	& lAmount,      const long & lTransactionNum,
                         const time_t & VALID_FROM, const time_t & VALID_TO, // The expiration date (valid from/to dates) of the cheque
                         const OTIdentifier & SENDER_ACCT_ID,                // The asset account the cheque is drawn on.
                         const OTIdentifier & SENDER_USER_ID,                // This ID must match the user ID on the asset account, 
                                                                             // AND must verify the cheque signature with that user's key.
                         const OTString & strMemo,	// Optional memo field.
                         const OTIdentifier * pRECIPIENT_USER_ID=NULL);	// Recipient optional. (Might be a blank cheque.)

EXPORT  void CancelCheque(); // You still need to re-sign the cheque after doing this.
    
	// From OTTrackable (parent class of this)
	/*
	 // A cheque can be written offline, provided you have a transaction
	 // number handy to write it with. (Necessary to prevent double-spending.)
	 inline       long              GetTransactionNum() const  { return m_lTransactionNum; }
	 inline const OTIdentifier &	GetSenderAcctID()		   { return m_SENDER_ACCT_ID; }
	 inline const OTIdentifier &	GetSenderUserID()		   { return m_SENDER_USER_ID; }
	 */
	
	// From OTInstrument (parent class of OTTrackable, parent class of this)
	/*
	 OTInstrument(const OTIdentifier & SERVER_ID, const OTIdentifier & ASSET_ID) : OTContract()
	 
	 inline const OTIdentifier & GetAssetID()  const { return m_AssetTypeID; }
	 inline const OTIdentifier & GetServerID() const { return m_ServerID;    }
	 
	 inline time_t GetValidFrom()	const { return m_VALID_FROM; }
	 inline time_t GetValidTo()		const { return m_VALID_TO;   }
	 
	 bool VerifyCurrentDate(); // Verify the current date against the VALID FROM / TO dates.
	 */
EXPORT	OTCheque();
EXPORT	OTCheque(const OTIdentifier & SERVER_ID, const OTIdentifier & ASSET_ID);
EXPORT	virtual ~OTCheque();
	
			void InitCheque();
	virtual void Release();
	void Release_Cheque();
	virtual void UpdateContents(); // Before transmission or serialization, this is where the token saves its contents 	

//	virtual bool SaveContractWallet(FILE * fl);
	virtual bool SaveContractWallet(std::ofstream & ofs);
};


#endif // __OT_CHEQUE_H__






















