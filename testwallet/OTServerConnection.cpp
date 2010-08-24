/************************************************************************************
 *    
 *  OTServerConnection.cpp
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

#include <cstring>
#include <cstdio>

extern "C" 
{
#ifdef _WIN32
#include <WinSock.h>
#define strcasecmp _stricmp
#else
#include <netinet/in.h>
#endif

#include "SSL-Example/SFSocket.h"
}


#include "OTServerConnection.h"

#include "OTIdentifier.h"
#include "OTDataCheck.h"
#include "OTPayload.h"
#include "OTWallet.h"
#include "OTPseudonym.h"
#include "OTMessage.h"
#include "OTWallet.h"
#include "OTClient.h"
#include "OTEnvelope.h"



int allow_debug = 1;

extern OTPseudonym			* g_pTemporaryNym; 
extern OTAssetContract		* g_pTemporaryContract;
extern OTServerContract		* g_pServerContract;

OTClient g_Client;
OTWallet g_Wallet;

/*
 union u_header
 {
 BYTE buf[OT_CMD_HEADER_SIZE];
 struct {
 BYTE type_id;    // 1 byte
 BYTE command_id; // 1 byte
 BYTE filler[2];
 uint32_t size;     // 4 bytes to describe size of payload
 BYTE  checksum;  // 1 byte
 } fields;  // total of 9 bytes
 };
 */

void SetupHeader( u_header & theCMD, int nTypeID, int nCmdID, OTPayload & thePayload)
{
	uint32_t lSize = thePayload.GetSize(); // outputting in normal byte order, but sent to network in network byte order.

	theCMD.fields.type_id	= nTypeID;
	theCMD.fields.command_id= nCmdID;
//	theCMD.fields.size		= thePayload.GetSize();
	theCMD.fields.size		= htonl(lSize); // think this is causing problems.. maybe not...
	theCMD.fields.checksum	= CalcChecksum(theCMD.buf, OT_CMD_HEADER_SIZE-1);	
	
	
	BYTE byChecksum	= (BYTE)theCMD.fields.checksum;
	int nChecksum	= byChecksum;
	
	fprintf(stderr, "OT_CMD_HEADER_SIZE: %d -- CMD TYPE: %d -- CMD NUM: %d -- (followed by 2 bytes of filler)\n"
			"PAYLOAD SIZE: %d -- CHECKSUM: %d\n", OT_CMD_HEADER_SIZE,
			nTypeID, nCmdID, lSize, nChecksum);
	
	fprintf(stderr, "First 9 bytes are: %d %d %d %d %d %d %d %d %d\n",
//			"sizeof(int) is %d, sizeof(long) is %d, sizeof(short) is %d, sizeof(uint32_t) is %d.\n", 
			theCMD.buf[0],theCMD.buf[1],theCMD.buf[2],theCMD.buf[3],theCMD.buf[4], theCMD.buf[5], theCMD.buf[6], theCMD.buf[7], theCMD.buf[8]
//			sizeof(int), sizeof(long), sizeof(short), sizeof(uint32_t)
			);
}


bool OTServerConnection::s_bInitialized = false;

void OTServerConnection::Initialize()
{
	// We've already been initialized. We can just return
	if (s_bInitialized)
	{
		return;
	}
	
	// This is the first time this function has run.
	s_bInitialized = true; // set this to true so the function can't run again. It only runs the first time.
	
	// Initialize SSL
    SFSocketGlobalInit();
}


// the hostname is not a reference, because I want people to be able
// to pass in a C-style string and have it still work.
bool OTServerConnection::Connect(OTPseudonym & theNym, OTServerContract & theServerContract,
								 OTString & strCA_FILE, OTString & strKEY_FILE, OTString & strKEY_PASSWORD)
{
	// We're already connected!
	if (IsConnected())
		return false;
	
	// Make sure all the socket stuff is initialized and set up.
	Initialize();
	
	// You can't just pass in a hostname and port.
	// Instead, you pass in the Nym and Contract, and *I'll* look up all that stuff.
	OTString strHostname;
	int nPort;
	
	if (false == theServerContract.GetConnectInfo(strHostname, nPort))
	{
		fprintf(stderr, "Error retrieving connection info from server contract.\n");
		return false;
	}
	
    SFSocket * socket;

    // Alloc Socket
    if ((socket = SFSocketAlloc()) == NULL) {
        fprintf(stderr, "Alloc Failed\n");
        return false;
    }
		
    // Initialize SSL client Socket
    if (SFSocketInit(socket, strCA_FILE.Get(), NULL, strKEY_FILE.Get(), strKEY_PASSWORD.Get(), NULL) < 0) {
	    fprintf(stderr, "Init Failed\n");
        return false;
    }
	
	// TODO: Note, I had to go intside this function and comment out the Cert-checking portion
	// in order to get this program running.
	// So I need to go back and revisit that later, but at least now we have client/server.
	
    // Connect to Host
    if (SFSocketConnectToHost(socket, strHostname.Get(), nPort) < 0) {
        fprintf(stderr, "Connect to Host Failed\n");
        return false;
    }	
	
	m_pSocket			= socket;
	m_pNym				= &theNym;
	m_pServerContract	= &theServerContract;
	
	return true;
}



// When the server sends a reply back with our new request number, we
// need to update our records accordingly.
//
// This function is meant to be called when that happens, so that we
// can do just that.
//
void OTServerConnection::OnServerResponseToGetRequestNumber(long lNewRequestNumber)
{
	if (m_pNym && m_pServerContract)
	{
//		fprintf(stderr, "Received new request number from the server: %ld. Updating Nym records...\n", 
//				lNewRequestNumber);
		
		OTString strServerID;
		m_pServerContract->GetIdentifier(strServerID);
		m_pNym->OnUpdateRequestNum(*m_pNym, strServerID, lNewRequestNumber);
	}
	else {
		fprintf(stderr, "Expected m_pNym or m_pServerContract to be not null in "
				"OTServerConnection::OnServerResponseToGetRequestNumber.\n");
	}
}


bool OTServerConnection::GetServerID(OTIdentifier & theID)
{
	if (m_pServerContract)
	{
		m_pServerContract->GetIdentifier(theID);
		return true;
	}
	return false;
}

// When a certain Nym opens a certain account on a certain server,
// that account is put onto a list of accounts inside the wallet.
// Therefore, a certain Nym's connection to a certain server will
// occasionally require access to those accounts. Therefore the
// server connection object needs to have a pointer to the wallet.
// There might be MORE THAN ONE connection per wallet, or only one,
// but either way the connections need a pointer to the wallet
// they are associated with, so they can access those accounts.
OTServerConnection::OTServerConnection(OTWallet & theWallet, SFSocket * pSock)
{
	m_pSocket			= pSock;
	m_pNym				= NULL;
	m_pServerContract	= NULL;
	m_pWallet			= &theWallet;
}

OTServerConnection::OTServerConnection(OTWallet & theWallet)
{
	m_pSocket			= NULL;
	m_pNym				= NULL;
	m_pServerContract	= NULL;
	m_pWallet			= &theWallet;
}

OTServerConnection::~OTServerConnection()
{
	if (m_pSocket)
	{
	    // Close and Release Socket Resources
		SFSocketRelease(m_pSocket);	
	}
}


// This function returns true if we received a full and proper reply from the server.
// theServerReply will contain that message after a successful call to this function.
bool OTServerConnection::ProcessInBuffer(OTMessage & theServerReply)
{
	int  err;
	uint32_t nread;
	u_header theCMD;
	
	// clear the header
	memset((void *)theCMD.buf, 0, OT_CMD_HEADER_SIZE);
	
	for (nread = 0;  nread < OT_CMD_HEADER_SIZE;  nread += err)
	{
		err = SFSocketRead(m_pSocket, theCMD.buf + nread, OT_CMD_HEADER_SIZE - nread);

#ifdef _WIN32
		if (0 == err || SOCKET_ERROR == err) // 0 is a disconnect. error is error. otherwise err contains bytes read.
#else
		if (err <= 0)
#endif
		{
			break;
		}
	}
	
	if (OT_CMD_HEADER_SIZE == nread)
	{
//		fprintf(stderr, "\n**************************************************************\n"
//				"===> Processing header from server reply. First 5 bytes are: %d %d %d %d %d...\n",
//				theCMD.buf[0],theCMD.buf[1],theCMD.buf[2],theCMD.buf[3],theCMD.buf[4]);	
		
		
		return ProcessReply(theCMD, theServerReply);
	}
	
	return false;
}

// ProcessInBuffer calls this function, once it has verified the header,
// this function gets the payload.  If successful, returns true and theServerReply
// will contain the OTMessage that was received.
// It also flushes the pipe in the event of any errors.
bool OTServerConnection::ProcessReply(u_header & theCMD, OTMessage & theServerReply)
{
	bool bSuccess = false;

	
	fprintf(stderr, "\n****************************************************************\n"
			"===> Processing header from server response.\nFirst 9 bytes are: %d %d %d %d %d %d %d %d %d...\n",
			theCMD.buf[0],theCMD.buf[1],theCMD.buf[2],theCMD.buf[3],theCMD.buf[4],theCMD.buf[5], theCMD.buf[6], theCMD.buf[7], theCMD.buf[8]);

	
	if( theCMD.fields.type_id == CMD_TYPE_1 )
	{
	//	fprintf(stderr, "Received a Type 1 Command...\n");
		
		if( IsChecksumValid( theCMD.buf, OT_CMD_HEADER_SIZE ) ){								
//			fprintf(stderr, "Checksum is valid! Processing payload.\n");
			if (true == ProcessType1Cmd(theCMD, theServerReply ))
				bSuccess = true;
		}
		else {
			fprintf(stderr, "Invalid checksum - Type 1 Command\n");
		}
	}
	else
	{
		//gDebugLog.Write("Unknown command type");
		int nCMDType = theCMD.fields.type_id;
		fprintf(stderr, "Unknown command type: %d\n", nCMDType);
	}
	
	
	// I added this for error correction. In the event that there are errors, 
	// just clean out whatever is in the pipe and throw it away.
	// Should probably send an Error message back, as well.
	if (bSuccess == false)
	{
		int  err = 0, nread = 0;
		
		char buffer[1024];
		int sizeJunkData = 1024;
		
		while (1)
		{
			err = SFSocketRead(m_pSocket, buffer, sizeJunkData);
			
			if (err > 0) // _WIN32
				nread += err;
			
#ifdef _WIN32
			if (0 == err || SOCKET_ERROR == err) // 0 means disconnect. error means error. >0 means bytes read.
#else
			if (err <= 0)
#endif
				break;
		}
		
		fprintf(stderr, "Transmission error--therefore have flushed the pipe, discarding %d bytes.\n", 
				nread, sizeJunkData);
	}
	
	return bSuccess;
}



// If this function returns a true, that means theServerReply now contains a valid message
// from the server.  (So something should be done with it.)
bool OTServerConnection::ProcessType1Cmd(u_header & theCMD, OTMessage & theServerReply)
{
	// At this point, the checksum has already validated. 
	// Might as well get the PAYLOAD next.
	int  err;
	uint32_t nread;
	
	// Make sure our byte-order is correct here.
	theCMD.fields.size = ntohl(theCMD.fields.size); // think this is causing problems... maybe not...

	OTPayload thePayload;
	thePayload.SetPayloadSize(theCMD.fields.size);
	
	for (nread = 0;  nread < theCMD.fields.size;  nread += err)
	{
		err = SFSocketRead(m_pSocket, (unsigned char *)thePayload.GetPayloadPointer() + nread, theCMD.fields.size - nread);

#ifdef _WIN32
		if (0 == err || SOCKET_ERROR == 0) // 0 means disconnect. error means error. otherwise, err contains bytes read.
#else
		if (err <= 0)
#endif
			break;
	}
	
	// ------------------------------------------------------------
	
	switch (theCMD.fields.command_id) {
		case TYPE_1_CMD_1:
//			fprintf(stderr, "Received TYPE 1 CMD 1, an OTMessage.\n");
			break;
		case TYPE_1_CMD_2:
//			fprintf(stderr, "Received TYPE 1 CMD 2, an OTEnvelope containing an OTMessage.\n");
			break;
		default:
			break;
	}
	
	// ------------------------------------------------------------
	
	if (theCMD.fields.size == 0)
	{
		fprintf(stderr, "(The payload was a 0 size.)\n");
		return true;
	}
	else if (nread < theCMD.fields.size)
	{
		fprintf(stderr, "Number of bytes read (%d) did NOT match size in header (%d).\n",
				nread, theCMD.fields.size);
		return false;
	}
	else
	{
//		fprintf(stderr, "Loaded a payload, size: %d\n", theCMD.fields.size);
	}
	// ------------------------------------------------------------
	

	// a signed OTMessage
	if (TYPE_1_CMD_1 == theCMD.fields.command_id) 
	{
#ifdef _WIN32
		if (OTPAYLOAD_GetMessage(thePayload, theServerReply))
#else
		if (thePayload.GetMessage(theServerReply))
#endif
		{
			fprintf(stderr, "Successfully retrieved payload message...\n");
			
			if (theServerReply.ParseRawFile())
			{
				fprintf(stderr, "Successfully parsed payload message.\n");
				
				OTPseudonym * pServerNym = NULL;
				
				if (m_pServerContract && (pServerNym = (OTPseudonym *)m_pServerContract->GetContractPublicNym()))
				{
					if (theServerReply.VerifySignature((const OTPseudonym &)*pServerNym))
					{
						fprintf(stderr, "VERIFIED -- this message was signed by the Server.\n");
					}
					else {
						fprintf(stderr, "Signature verification failed on this message, proportedly from the Server.\n");
						return false;
					}
				}
				else {
					fprintf(stderr, "No server contract loaded, or could not load public key from server contract.\n");
					return false;
				}
				
				return true;
			}
			else {
				fprintf(stderr, "Error parsing message.\n");
				return false;
			}
			
		}
		else {
			fprintf(stderr, "Error retrieving message from payload.\n");
			return false;
		}
		
	}
	
	// A base64-encoded envelope, encrypted, and containing a signed message.
	else if (TYPE_1_CMD_2 == theCMD.fields.command_id) 
	{
		OTEnvelope theEnvelope;
		if (thePayload.GetEnvelope(theEnvelope))
		{
			fprintf(stderr, "===> Received encrypted envelope. (Server reply.) Decrypting...\n");
			
			OTString strEnvelopeContents;
						
			// Decrypt the Envelope.
			if (m_pNym && theEnvelope.Open(*m_pNym, strEnvelopeContents))
			{
				// All decrypted, now let's load the results into an OTMessage.
				// No need to call theMessage.ParseRawFile() after, since
				// LoadContractFromString handles it.
				//
				if (theServerReply.LoadContractFromString(strEnvelopeContents))
				{
		//			fprintf(stderr, "Success decrypting the message out of the envelope and parsing it.\n");
					
					OTPseudonym * pServerNym = NULL;
					
					if (m_pServerContract && (pServerNym = (OTPseudonym *)m_pServerContract->GetContractPublicNym()))
					{
						if (theServerReply.VerifySignature((const OTPseudonym &)*pServerNym))
						{
							fprintf(stderr, "VERIFIED -- this message was signed by the Server.\n");
//							fprintf(stderr, "VERIFIED -- this message was signed by the Server:\n%s\n", strEnvelopeContents.Get());
						}
						else {
							fprintf(stderr, "Signature verification failed on this message, proportedly from the Server.\n");
							return false;
						}
					}
					else {
						fprintf(stderr, "No server contract loaded, or could not load public key from server contract.\n");
						return false;
					}
					
					return true;
				}
				else 
				{
					fprintf(stderr, "Error loading message from envelope contents.\n");
					return false;		
				}
			}
			else {
				fprintf(stderr, "Unable to open envelope.\n");
				return false;
			}			
		}
		else {
			fprintf(stderr, "Error retrieving message from payload.\n");
			return false;
		}
		
	}
		
	else {
		fprintf(stderr, "Error retrieving message from payload. Unknown type.\n");
		return false;
	}
	
	return true;
	
}




bool OTServerConnection::SignAndSend(OTMessage & theMessage)
{
	if (m_pNym && m_pSocket && m_pWallet && theMessage.SignContract(*m_pNym) && theMessage.SaveContract())
	{
		ProcessMessageOut(theMessage);
		return true;
	}
	
	return false;
}




void OTServerConnection::ProcessMessageOut(OTMessage & theMessage)
{
    int  err;
	uint32_t nwritten;
	
	u_header theCMD; 
	OTPayload thePayload;
	
	// clear the header
	memset((void *)theCMD.buf, 0, OT_CMD_HEADER_SIZE);

	// Here is where we set up the Payload (so we have the size ready before the header goes out)
	// This is also where we have turned on the encrypted envelopes  }:-)

	// Testing encrypted envelopes...
	const OTPseudonym * pRecipient = NULL;
	
	if (m_pServerContract && (pRecipient = m_pServerContract->GetContractPublicNym()))
	{
		OTString strEnvelopeContents;
		// Save the ready-to-go message into a string.
		theMessage.SaveContract(strEnvelopeContents);
		
		OTEnvelope theEnvelope;
		// Seal the string up into an encrypted Envelope
		theEnvelope.Seal(*pRecipient, strEnvelopeContents);
		
		// From here on out, theMessage is disposable. OTPayload takes over. 
		// OTMessage doesn't care about checksums and headers.
		thePayload.SetEnvelope(theEnvelope);
		
		// Now that the payload is ready, we'll set up the header.
		SetupHeader(theCMD, CMD_TYPE_1, TYPE_1_CMD_2, thePayload);
	}
	// else, for whatever reason, we just send an UNencrypted message...
	else {
		thePayload.SetMessage(theMessage);
		
		// Now that the payload is ready, we'll set up the header.
		SetupHeader(theCMD, CMD_TYPE_1, TYPE_1_CMD_1, thePayload);
	}
	
	int nHeaderSize = OT_CMD_HEADER_SIZE;
	
	for (nwritten = 0;  nwritten < nHeaderSize;  nwritten += err)
	{
		err = SFSocketWrite(m_pSocket, theCMD.buf + nwritten, nHeaderSize - nwritten);

#ifdef _WIN32
		if (0 == err || SOCKET_ERROR == err) //  0 is disonnect. error is error. >0 is bytes written.
#else
		if (err <= 0)
#endif
			break;
	}

	// At this point, we have sent the header across the pipe.
	uint32_t nPayloadSize = thePayload.GetSize();
	
	for (nwritten = 0;  nwritten < nPayloadSize;  nwritten += err)
	{
		err = SFSocketWrite(m_pSocket, (unsigned char *)thePayload.GetPayloadPointer() + nwritten, nPayloadSize - nwritten);

#ifdef _WIN32
		if (0 == err || SOCKET_ERROR == err) //  0 is disonnect. error is error. >0 is bytes written.
#else
		if (err <= 0)
#endif
			break;
	}		
	fprintf(stderr, "Message sent...\n\n");
	// At this point, we have sent the payload across the pipe.		
}



// This function interprets test input (so should have been in test client?)
// then it uses that to send a message to server.
// The buf passed in is simply data collected by fgets from stdin.
void OTServerConnection::ProcessMessageOut(char *buf, int * pnExpectReply)
{
 	bool bSendCommand = false;
	bool bSendPayload = false;
	
	OTMessage theMessage;
	
	bool bHandledIt = false;
	
    int  err;
	uint32_t nwritten;
	u_header theCMD; 
	
	// clear the header
	memset((void *)theCMD.buf, 0, OT_CMD_HEADER_SIZE);
	
	
	// Simple rule here: In each of the below if statements,
	// YOU MUST set up the header bytes HERE!
	// OR you must set the boolean bSendCommand TO TRUE!!
	// It must be one or the other in each block.
	// If you set to true, code at the bottom will calculate header
	// for you. If you fail to do this, the header is now uncalculated either way.
	// Don't send uncalculated headers to the server unless doing it on purpose for TESTING.
	
	if (buf[0] == '1')
	{
		bHandledIt = true;
		
		theCMD.fields.type_id = CMD_TYPE_1;
		theCMD.fields.command_id = TYPE_1_CMD_1;
		theCMD.fields.size = 0;
		theCMD.fields.checksum = CalcChecksum(theCMD.buf, OT_CMD_HEADER_SIZE-1);
		
		int nChecksum = theCMD.fields.checksum;
		
		fprintf(stderr, "(User has instructed to send a size %d, TYPE 1 COMMAND to the server...)\n CHECKSUM: %d\n", 
				OT_CMD_HEADER_SIZE, nChecksum);
		bSendCommand = true;
	}
	else if (buf[0] == '2')
	{
		bHandledIt = true;
		
		theCMD.fields.type_id = 12;
		theCMD.fields.command_id = 3;
		theCMD.fields.size = 98;
		theCMD.fields.checksum = CalcChecksum(theCMD.buf, OT_CMD_HEADER_SIZE-1);
		
		fprintf(stderr, "(User has instructed to send a size %d, **malformed command** to the server...)\n", OT_CMD_HEADER_SIZE+3);
		bSendCommand = true;
	}
	// Empty OTMessage including signed XML, but no other commands
	else if (buf[0] == '3')
	{
		fprintf(stderr, "(User has instructed to create a signed XML message and send it to the server...)\n");
		bHandledIt = true;
		
		// Normally you'd update the member variables here, before signing it.
		// But this is just an empty OTMessage.
		
		// When a message is signed, it updates its m_xmlUnsigned contents to the values in the members variables
		g_Wallet.SignContractWithFirstNymOnList(theMessage);
		
		// SaveContract takes m_xmlUnsigned and wraps it with the signatures and ------- BEGIN  bookends
		// If you don't pass a string in, then SaveContract saves the new version to its member, m_strRawFile
		theMessage.SaveContract();
		
		bSendCommand = true;
		bSendPayload = true;
	}
	
	
	// Above are various test messages.
	
	// ------------------------------------------------------------------------------			
	
	// ------------------------------------------------------------------------------			
	
	// This section for commands that involve building full XML messages, 
	// that is, most of the real implementation of the transaction protocol.
	
	// If we can match the user's request to a client command,
	// AND theClient object is able to process that request into
	// a payload, THEN we create the header and send it all down the pipe.
	
	if (false == bHandledIt && g_pTemporaryNym && g_pServerContract)
	{
		// check server ID command
		if (buf[0] == 'c')
		{
			fprintf(stderr, "(User has instructed to send a checkServerID command to the server...)\n");
			
			// ------------------------------------------------------------------------------			
			// if successful setting up the command payload...
			
			if (g_Client.ProcessUserCommand(OTClient::checkServerID, theMessage, 
											*g_pTemporaryNym, *g_pServerContract,
											NULL)) // NULL pAccount on this command.
			{				
				bSendCommand = true;
				bSendPayload = true;				
			}
			else
				fprintf(stderr, "Error processing checkServerID command in ProcessMessage: %c\n", buf[0]);
			// ------------------------------------------------------------------------
		}
		
		// register new user account 
		else if (buf[0] == 'r')
		{
			fprintf(stderr, "(User has instructed to send a createUserAccount command to the server...)\n");
			
			// ------------------------------------------------------------------------------			
			// if successful setting up the command payload...
			
			if (g_Client.ProcessUserCommand(OTClient::createUserAccount, theMessage, 
											*g_pTemporaryNym, *g_pServerContract,
											NULL)) // NULL pAccount on this command.
			{
				bSendCommand = true;
				bSendPayload = true;				
			}
			else
				fprintf(stderr, "Error processing createUserAccount command in ProcessMessage: %c\n", buf[0]);
			// ------------------------------------------------------------------------
		}
		
		// ALL MESSAGES BELOW THIS POINT SHOULD ATTACH A REQUEST NUMBER IF THEY EXPECT THE SERVER TO PROCESS THEM.
		// (Handled inside ProcessUserCommand)
		
		// checkUser
		else if (buf[0] == 'u')
		{
			fprintf(stderr, "(User has instructed to send a checkUser command to the server...)\n");
			
			// ------------------------------------------------------------------------------			
			// if successful setting up the command payload...
			
			if (g_Client.ProcessUserCommand(OTClient::checkUser, theMessage, 
											*g_pTemporaryNym, *g_pServerContract,
											NULL)) // NULL pAccount on this command.
			{
				bSendCommand = true;
				bSendPayload = true;				
			}
			else
				fprintf(stderr, "Error processing checkUser command in ProcessMessage: %c\n", buf[0]);
			// ------------------------------------------------------------------------
		}
		
		// register new asset account 
		else if (buf[0] == 'a')
		{
			fprintf(stderr, "(User has instructed to send a createAccount command to the server...)\n");
			
			// ------------------------------------------------------------------------------			
			// if successful setting up the command payload...
			
			if (g_Client.ProcessUserCommand(OTClient::createAccount, theMessage, 
											*g_pTemporaryNym, *g_pServerContract,
											NULL)) // NULL pAccount on this command.
			{
				bSendCommand = true;
				bSendPayload = true;				
			}
			else
				fprintf(stderr, "Error processing createAccount command in ProcessMessage: %c\n", buf[0]);
			// ------------------------------------------------------------------------
		}
		
		// issue a new asset type 
		else if (!strcmp(buf, "issue\n"))
		{
			fprintf(stderr, "(User has instructed to send an issueAssetType command to the server...)\n");
			
			// ------------------------------------------------------------------------------			
			// if successful setting up the command payload...
			
			if (g_Client.ProcessUserCommand(OTClient::issueAssetType, theMessage, 
											*g_pTemporaryNym, *g_pServerContract,
											NULL)) // NULL pAccount on this command.
			{
				bSendCommand = true;
				bSendPayload = true;				
			}
			else
				fprintf(stderr, "Error processing issueAssetType command in ProcessMessage: %c\n", buf[0]);
			// ------------------------------------------------------------------------
		}
		
		// issue a new basket asset type 
		else if (!strcmp(buf, "basket\n"))
		{
			fprintf(stderr, "(User has instructed to send an issueBasket command to the server...)\n");
			
			// ------------------------------------------------------------------------------			
			// if successful setting up the command payload...
			
			if (g_Client.ProcessUserCommand(OTClient::issueBasket, theMessage, 
											*g_pTemporaryNym, *g_pServerContract,
											NULL)) // NULL pAccount on this command.
			{
				bSendCommand = true;
				bSendPayload = true;				
			}
			else
				fprintf(stderr, "Error processing issueBasket command in ProcessMessage: %c\n", buf[0]);
			// ------------------------------------------------------------------------
		}
		
		// exchange in/out of a basket currency 
		else if (!strcmp(buf, "exchange\n"))
		{
			fprintf(stderr, "(User has instructed to send an exchangeBasket command to the server...)\n");
			
			// ------------------------------------------------------------------------------			
			// if successful setting up the command payload...
			
			if (g_Client.ProcessUserCommand(OTClient::exchangeBasket, theMessage, 
											*g_pTemporaryNym, *g_pServerContract,
											NULL)) // NULL pAccount on this command.
			{
				bSendCommand = true;
				bSendPayload = true;				
			}
			else
				fprintf(stderr, "Error processing exchangeBasket command in ProcessMessage: %c\n", buf[0]);
			// ------------------------------------------------------------------------
		}
		
		// get inbox 
		else if (buf[0] == 'i')
		{
			fprintf(stderr, "(User has instructed to send a getInbox command to the server...)\n");
			
			// ------------------------------------------------------------------------------			
			// if successful setting up the command payload...
			
			if (g_Client.ProcessUserCommand(OTClient::getInbox, theMessage, 
											*g_pTemporaryNym, *g_pServerContract,
											NULL)) // NULL pAccount on this command.
			{
				bSendCommand = true;
				bSendPayload = true;				
			}
			else
				fprintf(stderr, "Error processing getInbox command in ProcessMessage: %c\n", buf[0]);
			// ------------------------------------------------------------------------
		}
		
		// deposit cheque
		else if (buf[0] == 'q')
		{
			fprintf(stderr, "User has instructed to deposit a cheque...\n");
			
			// ------------------------------------------------------------------------------			
			// if successful setting up the command payload...
			
			if (g_Client.ProcessUserCommand(OTClient::notarizeCheque, theMessage, 
											*g_pTemporaryNym, *g_pServerContract,
											NULL)) // NULL pAccount on this command.
			{
				bSendCommand = true;
				bSendPayload = true;				
			}
			else
				fprintf(stderr, "Error processing deposit cheque command in ProcessMessage: %c\n", buf[0]);
			// ------------------------------------------------------------------------
		}
		
		// withdraw voucher
		else if (buf[0] == 'v')
		{
			fprintf(stderr, "User has instructed to withdraw a voucher (like a cashier's cheque)...\n");
			
			// ------------------------------------------------------------------------------			
			// if successful setting up the command payload...
			
			if (g_Client.ProcessUserCommand(OTClient::withdrawVoucher, theMessage, 
											*g_pTemporaryNym, *g_pServerContract,
											NULL)) // NULL pAccount on this command.
			{
				bSendCommand = true;
				bSendPayload = true;				
			}
			else
				fprintf(stderr, "Error processing withdraw voucher command in ProcessMessage: %c\n", buf[0]);
			// ------------------------------------------------------------------------
		}
		
		// withdraw cash
		else if (buf[0] == 'w')
		{
			fprintf(stderr, "(User has instructed to withdraw cash...)\n");
			
			// ------------------------------------------------------------------------------			
			// if successful setting up the command payload...
			
			if (g_Client.ProcessUserCommand(OTClient::notarizeWithdrawal, theMessage, 
											*g_pTemporaryNym, *g_pServerContract,
											NULL)) // NULL pAccount on this command.
			{
				bSendCommand = true;
				bSendPayload = true;				
			}
			else
				fprintf(stderr, "Error processing withdraw command in ProcessMessage: %c\n", buf[0]);
			// ------------------------------------------------------------------------
		}
		
		// deposit tokens
		else if (buf[0] == 'd')
		{
			fprintf(stderr, "(User has instructed to deposit cash tokens...)\n");
			
			// ------------------------------------------------------------------------------			
			// if successful setting up the command payload...
			
			if (g_Client.ProcessUserCommand(OTClient::notarizeDeposit, theMessage, 
											*g_pTemporaryNym, *g_pServerContract,
											NULL)) // NULL pAccount on this command.
			{
				bSendCommand = true;
				bSendPayload = true;				
			}
			else
				fprintf(stderr, "Error processing deposit command in ProcessMessage: %c\n", buf[0]);
			// ------------------------------------------------------------------------
		}
		
		// deposit purse
		else if (buf[0] == 'p')
		{
			fprintf(stderr, "(User has instructed to deposit a purse containing cash...)\n");
			
			// ------------------------------------------------------------------------------			
			// if successful setting up the command payload...
			
			if (g_Client.ProcessUserCommand(OTClient::notarizePurse, theMessage, 
											*g_pTemporaryNym, *g_pServerContract,
											NULL)) // NULL pAccount on this command.
			{
				bSendCommand = true;
				bSendPayload = true;				
			}
			else
				fprintf(stderr, "Error processing deposit command in ProcessMessage: %c\n", buf[0]);
			// ------------------------------------------------------------------------
		}
		
		// get account 
		else if (!strcmp(buf, "test\n"))
		{
			fprintf(stderr, "(User has instructed to perform a test...)\n");
			
			// ------------------------------------------------------------------------------			
			// if successful setting up the command payload...
			
			if (g_pTemporaryNym)
			{
				OTString strMessage("Well well well, this is just a little bit of plaintext.\nNotice there are NO NEWLINES at the start.\n"
									"I'm just trying to make it as long as i can, so that\nI can test the envelope and armor functionality.\n");
				
				fprintf(stdout, "MESSAGE:\n------>%s<--------\n", strMessage.Get());
				
				OTASCIIArmor ascMessage(strMessage);
				
				fprintf(stdout, "ASCII ARMOR:\n------>%s<--------\n", ascMessage.Get());

				OTEnvelope theEnvelope;
				theEnvelope.Seal(*g_pTemporaryNym, strMessage);
				
				ascMessage.Release();
				
				theEnvelope.GetAsciiArmoredData(ascMessage);
				
				fprintf(stdout, "ENCRYPTED PLAIN TEXT AND THEN ASCII ARMOR:\n------>%s<--------\n", ascMessage.Get());
				
				strMessage.Release();
				
				OTEnvelope the2Envelope(ascMessage);
				the2Envelope.Open(*g_pTemporaryNym, strMessage);
				
				fprintf(stdout, "DECRYPTED PLAIN TEXT:\n------>%s<--------\n", strMessage.Get());
				
				OTEnvelope the3Envelope;
				the3Envelope.Seal(*g_pTemporaryNym, strMessage.Get());
				
				ascMessage.Release();
				
				the3Envelope.GetAsciiArmoredData(ascMessage);
				
				fprintf(stdout, "RE-ENCRYPTED PLAIN TEXT AND THEN ASCII ARMOR:\n------>%s<--------\n", ascMessage.Get());

				strMessage.Release();
				
				OTEnvelope the4Envelope(ascMessage);
				the4Envelope.Open(*g_pTemporaryNym, strMessage);
				
				fprintf(stdout, "RE-DECRYPTED PLAIN TEXT:\n------>%s<--------\n", strMessage.Get());
				
				OTEnvelope the5Envelope;
				the5Envelope.Seal(*g_pTemporaryNym, strMessage.Get());
				
				ascMessage.Release();
				
				the3Envelope.GetAsciiArmoredData(ascMessage);
				
				fprintf(stdout, "RE-RE-ENCRYPTED PLAIN TEXT AND THEN ASCII ARMOR:\n------>%s<--------\n", ascMessage.Get());
				
				strMessage.Release();
				
				OTEnvelope the6Envelope(ascMessage);
				the6Envelope.Open(*g_pTemporaryNym, strMessage);
				
				fprintf(stdout, "RE-RE-DECRYPTED PLAIN TEXT:\n------>%s<--------\n", strMessage.Get());
				
			}
			
			// ------------------------------------------------------------------------
		}
		
		// get account 
		else if (!strcmp(buf, "get\n"))
		{
			fprintf(stderr, "(User has instructed to send a getAccount command to the server...)\n");
			
			// ------------------------------------------------------------------------------			
			// if successful setting up the command payload...
			
			if (g_Client.ProcessUserCommand(OTClient::getAccount, theMessage, 
											*g_pTemporaryNym,  *g_pServerContract,
											NULL)) // NULL pAccount on this command.
			{
				bSendCommand = true;
				bSendPayload = true;				
			}
			else
				fprintf(stderr, "Error processing getAccount command in ProcessMessage: %c\n", buf[0]);
			// ------------------------------------------------------------------------
		}
		
		// get contract 
		else if (!strcmp(buf, "getcontract\n"))
		{
			fprintf(stderr, "(User has instructed to send a getContract command to the server...)\n");
			
			// ------------------------------------------------------------------------------			
			// if successful setting up the command payload...
			
			if (g_Client.ProcessUserCommand(OTClient::getContract, theMessage, 
											*g_pTemporaryNym, *g_pServerContract,
											NULL)) // NULL pAccount on this command.
			{
				bSendCommand = true;
				bSendPayload = true;				
			}
			else
				fprintf(stderr, "Error processing getContract command in ProcessMessage: %c\n", buf[0]);
			// ------------------------------------------------------------------------
		}
		
		
		// sign contract 
		else if (!strcmp(buf, "signcontract\n"))
		{
			fprintf(stdout, "Is the contract properly escaped already? [y/n]: ");
			// User input.
			// I need a from account, Yes even in a deposit, it's still the "From" account.
			// The "To" account is only used for a transfer. (And perhaps for a 2-way trade.)
			OTString strEscape;
			strEscape.OTfgets(stdin);
			                    
			char cEscape='n';
			bool bEscaped = strEscape.At(0, cEscape);

			if (bEscaped)
			{
				if ('N' == cEscape || 'n' == cEscape)
					bEscaped = false;
			}
				
			fprintf(stdout, "Please enter an unsigned asset contract; terminate with ~ on a new line:\n> ");
			OTString strContract;
			char decode_buffer[200];
			
			do {
				fgets(decode_buffer, sizeof(decode_buffer), stdin);
				
				if (decode_buffer[0] != '~')
				{
					if (!bEscaped && decode_buffer[0] == '-')
					{
						strContract.Concatenate("- ");
					}
					strContract.Concatenate("%s", decode_buffer);
					fprintf(stdout, "> ");
				}
			} while (decode_buffer[0] != '~');
			
			OTAssetContract theContract;
			theContract.CreateContract(strContract, *g_pTemporaryNym);
			
			// re-using strContract here for output this time.
			strContract.Release();
			theContract.SaveContract(strContract);
			
			fprintf(stdout, ".\n..\n...\n....\n.....\n......\n.......\n........\n.........\n\n"
					"NEW CONTRACT:\n\n%s\n", strContract.Get());
			// ------------------------------------------------------------------------
		}
		
		// get mint 
		else if (!strcmp(buf, "getmint\n"))
		{
			fprintf(stderr, "(User has instructed to send a getMint command to the server...)\n");
			
			// ------------------------------------------------------------------------------			
			// if successful setting up the command payload...
			
			if (g_Client.ProcessUserCommand(OTClient::getMint, theMessage, 
											*g_pTemporaryNym,  *g_pServerContract,
											NULL)) // NULL pAccount on this command.
			{
				bSendCommand = true;
				bSendPayload = true;				
			}
			else
				fprintf(stderr, "Error processing getMint command in ProcessMessage: %c\n", buf[0]);
			// ------------------------------------------------------------------------
		}
		
		// notarize transfer 
		else if (buf[0] == 't')
		{
			fprintf(stderr, "(User has instructed to send a Transfer command (Notarize Transactions) to the server...)\n");
			
			// ------------------------------------------------------------------------------			
			// if successful setting up the command payload...
			
			if (g_Client.ProcessUserCommand(OTClient::notarizeTransfer, theMessage, 
											*g_pTemporaryNym,  *g_pServerContract,
											NULL)) // NULL pAccount on this command.
			{
				bSendCommand = true;
				bSendPayload = true;				
			}
			else
				fprintf(stderr, "Error processing notarizeTransactions command in ProcessMessage: %c\n", buf[0]);
			// ------------------------------------------------------------------------
		}
		
		// getRequest
		else if (buf[0] == 'g')
		{
			fprintf(stderr, "(User has instructed to send a getRequest command to the server...)\n");
			
			// ------------------------------------------------------------------------------			
			// if successful setting up the command payload...
			
			if (g_Client.ProcessUserCommand(OTClient::getRequest, theMessage, 
											*g_pTemporaryNym, *g_pServerContract,
											NULL)) // NULL pAccount on this command.
			{
				bSendCommand = true;
				bSendPayload = true;				
			}
			else
				fprintf(stderr, "Error processing getRequest command in ProcessMessage: %c\n", buf[0]);
			// ------------------------------------------------------------------------
		}
		
		// getTransactionNum
		else if (buf[0] == 'n')
		{
			fprintf(stderr, "(User has instructed to send a getTransactionNum command to the server...)\n");
			
			// ------------------------------------------------------------------------------			
			// if successful setting up the command payload...
			
			if (g_Client.ProcessUserCommand(OTClient::getTransactionNum, theMessage, 
											*g_pTemporaryNym,  *g_pServerContract,
											NULL)) // NULL pAccount on this command.
			{
				bSendCommand = true;
				bSendPayload = true;				
			}
			else
				fprintf(stderr, "Error processing getTransactionNum command in ProcessMessage: %c\n", buf[0]);
			// ------------------------------------------------------------------------
		}
		
		else 
		{
			if( allow_debug )
			{
				//gDebugLog.Write("unknown user command in ProcessMessage in main.cpp");
				fprintf(stderr, "\n");
				//				fprintf(stderr, "unknown user command in ProcessMessage in main.cpp: %d\n", buf[0]);
			}		
			return;
		}
	} //if (false == bHandledIt && g_pTemporaryNym && g_pTemporaryContract && g_pServerContract)
	
	else if (false == bHandledIt)
	{
		//		fprintf(stderr, "Your command was unrecognized or required resources that were not loaded.\n");
		fprintf(stderr, "\n");
	}
	
	if (bSendCommand && bSendPayload)
	{
		// Voila -- it's sent. (If there was a payload involved.)
		ProcessMessageOut(theMessage);
	} // Otherwise...
	else if (bSendCommand)
	{
		int nHeaderSize = OT_CMD_HEADER_SIZE;
		
		// TODO: REMOVE THIS. FOR TESTING ONLY
		if (buf[0] == '2') {
			nHeaderSize += 3;
		}
		
		for (nwritten = 0;  nwritten < nHeaderSize;  nwritten += err)
		{
			err = SFSocketWrite(m_pSocket, theCMD.buf + nwritten, nHeaderSize - nwritten);

#ifdef _WIN32
		if (0 == err || SOCKET_ERROR == err) //  0 is disonnect. error is error. >0 is bytes written.
#else
		if (err <= 0)
#endif				
			break;
		}
		
		int n0 = theCMD.buf[0], n1 = theCMD.buf[1], n2 = theCMD.buf[2], n3 = theCMD.buf[3], n4 = theCMD.buf[4], n5 = theCMD.buf[5], n6 = theCMD.buf[6];
		
		fprintf(stderr, "Sent: %d %d %d %d %d %d %d\n", n0, n1, n2, n3, n4, n5, n6);
	}
	// At this point, we have sent the header across the pipe.
}



