/*************************************************************
 *    
 *  OTMessageBuffer.h
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


#ifndef __OTMESSAGEBUFFER_H__
#define __OTMESSAGEBUFFER_H__

#ifndef EXPORT
#define EXPORT
#endif
#include <ExportWrapper.h>

#include <list>
#include <map>


class OTString;
class OTPseudonym;
class OTMessage;
class OTTransaction;


typedef std::list<OTMessage *>       listOfMessages; // Incoming server replies to your messages.
typedef std::multimap <long, OTMessage *> mapOfMessages;  // Your outgoing messages, mapped by request number.


// ------------------------------------


// INCOMING SERVER REPLIES.

// The purpose of this class is to cache server replies (internally to OT)
// so that the developer using the OT API has access to them.
// 
// This class is pretty generic and so may be used as an output buffer
// as well. (If "stack" form is preferable.)
//

class OTMessageBuffer
{
	listOfMessages m_listMessages;
    // --------------------------------
    // Just to keep you out of trouble.
    OTMessageBuffer  (const OTMessageBuffer & rhs) {}
    OTMessageBuffer & operator=(const OTMessageBuffer & rhs) { return *this; }
public:
	OTMessageBuffer() {}
EXPORT	~OTMessageBuffer();
	// -------------------------------
    
EXPORT    void        Clear   ();
EXPORT	void        Push    (OTMessage & theMessage);     // Push: theMessage must be heap-allocated. Takes ownership.
EXPORT	OTMessage * Pop     (const long & lRequestNum,    // Pop:  Caller IS responsible to delete.
                         const OTString & strServerID,
                         const OTString & strNymID);
};


// ------------------------------------



// OUTOING MESSAGES (from me--client--sent to server.)


// The purpose of this class is to cache client requests (being sent to the server)
// so that they can later be queried (using the request number) by the developer
// using the OTAPI, so that if transaction numbers need to be clawed back from failed
// messages, etc, they are available.
//
// The OT client side also can use this as a mechanism to help separate old-and-dealt-with
// messages, by explicitly removing messages from this queue once they are dealt with.
// This way the developer can automatically assume that any reply is old if it carries
// a request number that cannot be found in this queue.
//
// This class is pretty generic and so may be used in other ways, where "map"
// functionality is required.
//

class OTMessageOutbuffer
{
	mapOfMessages m_mapMessages;
    // --------------------------------
    // Just to keep you out of trouble.
    OTMessageOutbuffer  (const OTMessageOutbuffer & rhs) {}
    OTMessageOutbuffer & operator=(const OTMessageOutbuffer & rhs) { return *this; }

	OTString m_strDataFolder;

public:
EXPORT	OTMessageOutbuffer();
EXPORT	~OTMessageOutbuffer();
    // Note: AddSentMessage, if it finds a message already on the map with the same request number,
    // deletes the old one before adding the new one. In the future may contemplate using multimap
    // here instead (if completeness becomes desired over uniqueness.)

EXPORT    void        Clear(const OTString * pstrServerID=NULL, const OTString * pstrNymID=NULL, OTPseudonym * pNym=NULL,
                      const bool     * pbHarvestingForRetry=NULL);
EXPORT	void        AddSentMessage      (OTMessage & theMessage);   // Allocate theMsg on the heap (takes ownership.) Mapped by request num.
	
EXPORT    OTMessage * GetSentMessage      (const long & lRequestNum, const OTString & strServerID, const OTString & strNymID); // null == not found. caller NOT responsible to delete.
EXPORT	bool        RemoveSentMessage   (const long & lRequestNum, const OTString & strServerID, const OTString & strNymID); // true == it was removed. false == it wasn't found.

EXPORT	OTMessage * GetSentMessage      (const OTTransaction & theTransaction); // null == not found. caller NOT responsible to delete.
EXPORT	bool        RemoveSentMessage   (const OTTransaction & theTransaction); // true == it was removed. false == it wasn't found.
};



// ------------------------------------












#endif // __OTMESSAGEBUFFER_H__

























