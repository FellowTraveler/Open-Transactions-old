/************************************************************************************
 *    
 *  OTServerConnection.h
 *  
 *              Open Transactions:  Library, Protocol, Server, and Test Client
 *    
 *                      -- Anonymous Numbered Accounts
 *                      -- Untraceable Digital Cash
 *                      -- Triple-Signed Receipts
 *                      -- Basket Currencies
 *                      -- Signed XML Contracts
 *    
 *    Copyright (C) 2010 by "Fellow Traveler" (A pseudonym)
 *    
 *    EMAIL:
 *    F3llowTraveler@gmail.com --- SEE PGP PUBLIC KEY IN CREDITS FILE.
 *    
 *    KEY FINGERPRINT:
 *    9DD5 90EB 9292 4B48 0484  7910 0308 00ED F951 BB8E
 *    
 *    WEBSITE:
 *    http://www.OpenTransactions.org
 *    
 *    OFFICIAL PROJECT WIKI:
 *    http://wiki.github.com/FellowTraveler/Open-Transactions/
 *    
 *     ----------------------------------------------------------------
 *    
 *    Open Transactions was written including these libraries:
 *    
 *       Lucre          --- Copyright (C) 1999-2009 Ben Laurie.
 *                          http://anoncvs.aldigital.co.uk/lucre/
 *       irrXML         --- Copyright (C) 2002-2005 Nikolaus Gebhardt
 *                          http://irrlicht.sourceforge.net/author.html	
 *       easyzlib       --- Copyright (C) 2008 First Objective Software, Inc.
 *                          Used with permission. http://www.firstobject.com/
 *       PGP to OpenSSL --- Copyright (c) 2010 Mounir IDRASSI 
 *                          Used with permission. http://www.idrix.fr
 *       SFSocket       --- Copyright (C) 2009 Matteo Bertozzi
 *                          Used with permission. http://th30z.netsons.org/
 *    
 *     ----------------------------------------------------------------
 *
 *    Open Transactions links to these libraries:
 *    
 *       OpenSSL        --- (Version 1.0.0a at time of writing.) 
 *                          http://openssl.org/about/
 *       zlib           --- Copyright (C) 1995-2004 Jean-loup Gailly and Mark Adler
 *    
 *     ----------------------------------------------------------------
 *
 *    LICENSE:
 *        This program is free software: you can redistribute it and/or modify
 *        it under the terms of the GNU Affero General Public License as
 *        published by the Free Software Foundation, either version 3 of the
 *        License, or (at your option) any later version.
 *    
 *        You should have received a copy of the GNU Affero General Public License
 *        along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *      
 *        If you would like to use this software outside of the free software
 *        license, please contact FellowTraveler. (Unfortunately many will run
 *        anonymously and untraceably, so who could really stop them?)
 *   
 *        This library is also "dual-license", meaning that Ben Laurie's license
 *        must also be included and respected, since the code for Lucre is also
 *        included with Open Transactions.
 *        The Laurie requirements are light, but if there is any problem with his
 *        license, simply remove the deposit/withdraw commands. Although there are 
 *        no other blind token algorithms in Open Transactions (yet), the other 
 *        functionality will continue to operate.
 *    
 *    OpenSSL WAIVER:
 *        This program is released under the AGPL with the additional exemption 
 *        that compiling, linking, and/or using OpenSSL is allowed.
 *    
 *    DISCLAIMER:
 *        This program is distributed in the hope that it will be useful,
 *        but WITHOUT ANY WARRANTY; without even the implied warranty of
 *        MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *        GNU Affero General Public License for more details.
 *      
 ************************************************************************************/

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

#include "OTMessageBuffer.h"
#include "OTPseudonym.h"
#include "OTServerContract.h"


// Update: The actual connection information is now read out of the server contract!!
//#define HOSTNAME        "localhost"
//#define PORT            7085

class OTPseudonym;
class OTAccount;
class OTWallet;
class OTString;

class OTServerConnection 
{
	static void Initialize();
	static bool s_bInitialized;
	
	OTMessageBuffer m_listIn;
	OTMessageBuffer m_listOut;

	SFSocket * m_pSocket;
	
	OTPseudonym			*	m_pNym;
	OTServerContract	*	m_pServerContract;
	OTWallet			*	m_pWallet;
	
public:
	OTServerConnection(OTWallet & theWallet);
	OTServerConnection(OTWallet & theWallet, SFSocket * pSock);
	~OTServerConnection();
	
	bool GetServerID(OTIdentifier & theID);
	
	inline OTPseudonym		*	GetNym()			{ return m_pNym; }
	inline OTServerContract	*	GetServerContract()	{ return m_pServerContract; }
	inline OTWallet			*	GetWallet()			{ return m_pWallet; }
	
	inline bool IsConnected() { return ((NULL == m_pSocket)?false:true); }
	
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
