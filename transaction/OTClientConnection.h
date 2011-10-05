/*******************************************************************
 *    
 *  OTCLientConnection.h
 *  
 */

/************************************************************
 -----BEGIN PGP SIGNED MESSAGE-----
 Hash: SHA1
 
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
 
 iQIcBAEBAgAGBQJOiDLNAAoJEAMIAO35UbuOHZ8P/2FButaqcu7+z2wYmYKwm2Ki
 hECaUkzqOiT/FJZGBmNTiXxsBc8G1c2mPjB+MUT0cuow8+THBwzhifXRP2mmz03K
 7QqPc8I01q2wtG9C/BnfTLJ/rmkWHcrUsSMQe4nLW4F7fVB9A74J0Jivzq3ItC9F
 R/dBqj84zRM0jObW04ndXuJsvGtN3Arp8hujanLfuepOj8Bayu04awuGvmVOBW+U
 GqAxKnhW984QlEttydwMgmpDdDtNoBNWeGJKlkYV+T7z2M1ajAaLRje5+FyZZ5cU
 BCIp+RKUCLx4jUKCTBh2D9gXog/H5fXNGkpA8IrY9zFp0QABvNfNQLmwTeAT8mEp
 Dji07lfPqXu4AezHoWv8n56ew8W2gpTypCX9tL1HnPhCYOAzV+/EVLZqzpJliJV3
 0dwmO3W0aOsmTjXV2w5Ll4sx2UBi+d4eoVUGE1xYEpDpNoD1NLtysTJILRwFsQAX
 5X+LLzyoIRV+Sx/2N1S3l2fTZNK9EGVbjzJruASphiIrjk3NBQaThIIOLHqsPaTH
 RhRoCDpmm80uzWZJr0Mi7JAQmgSmralZAT8tCrD2VYq9mL9RHhwQ/fyXttFEEN+s
 DN/7M35z/u3wy3GikVknlzPcm+q4NaZMZJiynh5GeU++A0APh15clYqOsB5Zxe8O
 qg/U8uXzgLQuLbFxBjyr
 =utx2
 -----END PGP SIGNATURE-----
 **************************************************************/




#ifndef __OT_CLIENT_CONNECTION_H__
#define __OT_CLIENT_CONNECTION_H__

extern "C"
{
#include "SSL-Example/SFSocket.h"	
}


#ifdef __cplusplus
extern "C" {
#endif
	
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
	
#ifdef __cplusplus
}
#endif





class OTMessage;
class OTServer;


#include "OTMessageBuffer.h"
#include "OTAsymmetricKey.h"
#include "OTData.h"

class OTString;
class OTEnvelope;

class OTClientConnection
{
	u_header		m_CMD;			// We'll load a header and put it here, then wait until the bytes received matches the count
									// before processing.
	OTData			m_Buffer;		// As we read data, we buffer it here and chunk it out into messages.
	
	bool			m_bHaveHeader;	// If we've loaded a header already, and we're waiting for the byte count, this is true.
	OTMessageBuffer m_listIn;
	OTMessageBuffer m_listOut;
	OTServer	*	m_pServer;
	
	OTAsymmetricKey m_PublicKey;
	
	bool			m_bFocused;		// Defaults to false. If true, it means we're in XmlRpc mode, or some such, instead of TCP over SSL streaming.
	
public:
	SFSocket * m_pSocket;	// For TCP / SSL mode. 
	
	void ProcessBuffer();
	void ReadBytesIntoBuffer();

	void ProcessMessage(u_header & theCMD);
	bool ProcessType1Cmd(u_header & theCMD, OTMessage & theMessage);

	void ProcessReply(OTMessage &theReply);

	OTClientConnection(SFSocket & theSocket, OTServer & theServer); // TCP		/ over SSL mode.
	OTClientConnection(OTServer & theServer);						// XmlRpc	/ over HTTP mode.
	~OTClientConnection();
	
	void AddToInputList(OTMessage & theMessage);
	OTMessage * GetNextInputMessage();

	void AddToOutputList(OTMessage & theMessage);
	OTMessage * GetNextOutputMessage();

	void SetPublicKey(const OTString & strPublicKey);
	void SetPublicKey(const OTAsymmetricKey & thePublicKey);
	
	// This is for XmlRpc mode (i.e. there is not actually an open connection being maintained.)
	bool SealMessageForRecipient(OTMessage & theMsg, OTEnvelope & theEnvelope);
};


#endif // __OT_CLIENT_CONNECTION_H__
