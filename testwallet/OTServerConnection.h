/************************************************************************************
 *    
 *  OTServerConnection.h
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
 *  Copyright (C) 2010-2011 by "Fellow Traveler" (A pseudonym)
 *
 *  EMAIL:
 *  FellowTraveler@rayservers.net --- SEE PGP KEY BELOW.
 *  F3llowTraveler@gmail.com --- (not preferred.)
 *  
 *  BITCOIN:  1NtTPVVjDsUfDWybS4BwvHpG2pdS9RnYyQ
 *
 *  KEY FINGERPRINT:
 *  9DD5 90EB 9292 4B48 0484  7910 0308 00ED F951 BB8E
 *
 *  OFFICIAL PROJECT WIKI(s):
 *  http://wiki.github.com/FellowTraveler/Open-Transactions/wiki 
 *  http://wiki.github.com/FellowTraveler/Moneychanger/wiki 
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
 Version: GnuPG v1.4.10 (Darwin)
 
 iQIcBAEBCAAGBQJNsV9NAAoJEAMIAO35UbuOB3IP/12THBedTYrR2F2hkhYKK+0H
 YlVwRJyFnX3uKjDkYx2fpB2yNaMPPyiQRFpQBpiUxB2wSMHelM+m4YxVegx7h15s
 nD+jMLeVnlhgfKYsVZZiCKT58HXVsuGDc/iycXBBIQYBjCzbeCCG0vyEapR+sCwF
 eGR5l7yGbcMWaVqjPawqSMe/5Ie0wstWMrNAkLlWHRn/ISXb8vMusaxCe9kSeUX8
 7ZSZ0ojy3gLTZnUHFFZ2RaMepVB9jVoMSdVG89mEHX383foTuaxedjI2Wsw6J8YR
 D7PFp6PLGhm1eqArmotCj5NeV9lleULdnvR7T4QwzOZjI65kMwi/e1W6GyvzT3RZ
 RrLaZwiagcyKTXyEX5qSBQfSVNwC761rgNTG0fCBrBmDbQxet4A6Y+ZMxZmE0QXb
 Xch/g4g9Lki0TrSOx0zSAAcpLCIrqdvGX2jcmmJ/Ex4ZhzVhMvtkGfui9bUaY2bU
 bdu1GY0CfmElZ7+wXh2AutkMscRtnu62VSdGjrqry3KJMBWbtxNA9Q+U+NipWnYN
 yisBlQBADkXNtkL3EXEqX6OnjGfHNZ3G1bwuELcZjoOL+K0aQKCojRf8Ii5DW0A3
 niqzq/dwpt45VaQ+uYSG7Sg19FNvADg+WILdFcyszfS8Wks6BsKYzHUc5zbf3SFc
 JaOXLV9Ss58mj57JpNp8
 =VjLJ
 -----END PGP SIGNATURE-----
 **************************************************************/



#ifndef __OT_SERVERCONNECTION_H__
#define __OT_SERVERCONNECTION_H__

extern "C"
{
#include <stdint.h>	

#include "SSL-Example/SFSocket.h"	
}

extern "C" 
{	
#define TYPE_1_CMD_1	1
#define TYPE_1_CMD_2	2
#define TYPE_1_CMD_3	3
#define TYPE_1_CMD_4	4
	
#define CMD_TYPE_1		1
	
#define OT_CMD_HEADER_SIZE  9

typedef unsigned char	BYTE;
typedef unsigned short	USHORT;

union u_header
{
	BYTE buf[OT_CMD_HEADER_SIZE];
	struct {
		BYTE		type_id;	// 1 byte
		BYTE		command_id;	// 1 byte
		BYTE		filler[2];	// 2 extra bytes here so the size begins on a 4-byte boundary
		uint32_t	size;		// 4 bytes to describe size of payload
		BYTE		checksum;	// 1 byte
	} fields;	// total of 9 bytes
};
	
}


class OTMessage;
class OTEnvelope;

#include "OTMessageBuffer.h"
#include "OTPseudonym.h"
#include "OTServerContract.h"



//-----------------------------------------------------------------
// CALLBACK
//
// Here's the callback, for processing out messages via different 
// transport schemes (like RPC). Ultimate I suppose any transport could work....
// All it needs is the server contract and the envelope containing the message.
typedef void (*OT_CALLBACK_MSG)(OTServerContract & theServerContract, OTEnvelope & theEnvelope);

//-----------------------------------------------------------------

// Update: The actual connection information is now read out of the server contract!!
//#define HOSTNAME        "localhost"
//#define PORT            7085

class OTPseudonym;
class OTAccount;
class OTWallet;
class OTString;
class OTClient;

class OTServerConnection 
{
	static void Initialize();
	static bool s_bInitialized;
	
	OTMessageBuffer m_listIn;
	OTMessageBuffer m_listOut;

	SFSocket *				m_pSocket;	 // For TCP / SSL mode.
	
	bool					m_bFocused;	 // For RPC / HTTP mode.
	OT_CALLBACK_MSG			m_pCallback; // --------------------
	
	OTPseudonym			*	m_pNym;
	OTServerContract	*	m_pServerContract;
	OTWallet			*	m_pWallet;
	OTClient			*	m_pClient;
	
public:
	OTServerConnection(OTWallet & theWallet, OTClient & theClient);
	OTServerConnection(OTWallet & theWallet, OTClient & theClient, SFSocket * pSock);
	~OTServerConnection();
	
	bool GetServerID(OTIdentifier & theID);
	
	inline OTPseudonym		*	GetNym()			{ return m_pNym; }
	inline OTServerContract	*	GetServerContract()	{ return m_pServerContract; }
	inline OTWallet			*	GetWallet()			{ return m_pWallet; }
	
	inline bool IsConnected()	{ return ((NULL == m_pSocket)?false:true); }	// for socket mode				-- TCP / SSL
	inline bool IsFocused()		{ return m_bFocused; }							// for request/response mode	-- RPC / HTTP
	
	// SetFocus() is for RPC / HTTP mode.
	bool SetFocus(OTPseudonym & theNym, OTServerContract & theServerContract, OT_CALLBACK_MSG pCallback);

	// Connect() is for TCP / SSL mode.
	bool Connect(OTPseudonym & theNym, OTServerContract & theServerContract,
				 OTString & strCA_FILE, OTString & strKEY_FILE, OTString & strKEY_PASSWORD);
	
	void OnServerResponseToGetRequestNumber(long lNewRequestNumber);
	
	void ProcessMessageOut(char *buf, int * pnExpectReply);
	void ProcessMessageOut(OTMessage & theMessage);
	
	bool ProcessInBuffer(OTMessage & theServerReply);
	bool ProcessReply(u_header & theCMD, OTMessage & theServerReply);
	bool ProcessType1Cmd(u_header & theCMD, OTMessage & theServerReply);
	
	// Assuming we are connected, then we have the nym for signing and we
	// have the connection for sending.
	bool SignAndSend(OTMessage & theMessage);
	
};

#endif // __OT_SERVERCONNECTION_H__
