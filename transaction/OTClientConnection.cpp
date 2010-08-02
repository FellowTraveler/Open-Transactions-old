/************************************************************************************
 *    
 *  OTCLientConnection.cpp
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


extern "C" 
{
#include <netinet/in.h>
#include <string.h>
#include <stdio.h>
	
#include "SFSocket.h"
}


#include "main.h"
#include "OTDataCheck.h"
#include "OTEnvelope.h"
#include "OTPayload.h"
#include "OTClientConnection.h"
#include "OTServer.h"
#include "OTAsymmetricKey.h"




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



void SetupHeader( union u_header * pCMD, int nTypeID, int nCmdID, OTPayload & thePayload)
{
	pCMD->fields.type_id	= nTypeID;
	pCMD->fields.command_id	= nCmdID;
//	pCMD->fields.size		= thePayload.GetSize();
	pCMD->fields.size		= htonl(thePayload.GetSize()); // think this is causing problems
	pCMD->fields.checksum	= CalcChecksum(pCMD->buf, OT_CMD_HEADER_SIZE-1);
	
	BYTE byChecksum	= (BYTE)pCMD->fields.checksum;
	int nChecksum	= byChecksum;
	
	uint32_t nTemp	= thePayload.GetSize();
	fprintf(stderr, "(Payload size %d, TYPE %d command, checksum: %d...)\n", nTemp, nTypeID, nChecksum);
}



/*
void OTClientConnection::ProcessBuffer()
{
	int  err, nread;
	union u_header theCMD;
	
	// clear the header object.	
	memset((void *)theCMD.buf, 0, OT_CMD_HEADER_SIZE);
	
	// Read the header
	for (nread = 0;  nread < OT_CMD_HEADER_SIZE;  nread += err)
	{
		err = SFSocketRead(m_pSocket, 
						   theCMD.buf + nread, OT_CMD_HEADER_SIZE - nread);
		if (err <= 0)
		{
			break;
		}
		else {
			fprintf(stderr, "Reading input from socket...\n");
		}
		
	}
	
	if (nread)
	{
		fprintf(stderr, "\n===> Processing header from client message. First 5 bytes are: %d %d %d %d %d...\n",
				theCMD.buf[0],theCMD.buf[1],theCMD.buf[2],theCMD.buf[3],theCMD.buf[4]);
		
		// When the server knows for SURE it is receiving a message,
		// then wait for 1 second to make sure we have the entire payload
		// at once.
		// TODO: rewrite socket code so that if a complete command has not yet
		// come in, to buffer the data and wait until next time around the loop.
		// Because right now, if you have a partial command, it reads it as an error
		// and returns, discarding what had already been read. Obviously that will
		// not work for a real server.
		// In the meantime, this sleep allows me to do testing by insuring that,
		// with a second's wait, the server will have time to read the entire message.
		sleep(1);
		
		ProcessMessage(theCMD);
	}
}
*/

/*
 
 union u_header
 {
	 BYTE buf[OT_CMD_HEADER_SIZE];
 
	 struct 
	 {
		 unsigned char type_id;    // 1 byte
		 unsigned char command_id; // 1 byte
		 BYTE filler[2];
		 uint32_t size;     // 4 bytes to describe size of payload
		 unsigned char  checksum;  // 1 byte
 
	 } fields;  // total of 9 bytes
 }
 */



void OTClientConnection::ProcessBuffer()
{	
	if (!m_bHaveHeader)
	{
		int  err, nread;
		union u_header theCMD;

		// clear the header object.	
		memset((void *)theCMD.buf, 0, OT_CMD_HEADER_SIZE);
		
		// Read the header
		for (nread = 0;  nread < OT_CMD_HEADER_SIZE;  nread += err)
		{
			err = SFSocketRead(m_pSocket, 
							   theCMD.buf + nread, OT_CMD_HEADER_SIZE - nread);
			if (err <= 0)
			{
				break;
			}
			else {
				fprintf(stderr, "Reading input from socket...\n");
			}
		}
		
		if (nread == OT_CMD_HEADER_SIZE)
		{
			uint32_t lOldSize	= theCMD.fields.size;
			uint32_t lSize		= ntohl(lOldSize); // think this might be causing some problems... maybe not.
			theCMD.fields.size	= lSize; // fix the byte order.
			
			m_CMD			= theCMD;	// grab a copy of the header
			m_bHaveHeader	= true;		// We need to remember that we are now in "header mode"

			int nChecksum	= theCMD.fields.checksum;
			
			fprintf(stderr, "\n************************************************************\n===> Reading header from client message.\n"
					"First 9 bytes are: %d %d %d %d %d %d %d %d %d.\nSize is: %d...\n",
					theCMD.buf[0],theCMD.buf[1],theCMD.buf[2],theCMD.buf[3],theCMD.buf[4], 
					theCMD.buf[5], theCMD.buf[6], theCMD.buf[7], theCMD.buf[8], lSize);
			
			fprintf(stderr, "\nCMD HEADER:   CMD TYPE: %d -- CMD NUM: %d\n"
					"PAYLOAD SIZE: %d -- CHECKSUM: %d\n", theCMD.fields.type_id, 
					theCMD.fields.command_id, lSize, nChecksum);

			ReadBytesIntoBuffer();
			
			// When the server knows for SURE it is receiving a message,
			// then wait for 1 second to make sure we have the entire payload
			// at once.
			// TODO: rewrite socket code so that if a complete command has not yet
			// come in, to buffer the data and wait until next time around the loop.
			// Because right now, if you have a partial command, it reads it as an error
			// and returns, discarding what had already been read. Obviously that will
			// not work for a real server.
			// In the meantime, this sleep allows me to do testing by insuring that,
			// with a second's wait, the server will have time to read the entire message.
	//		sleep(1);
			
	//		ProcessMessage(theCMD);
		}
	}
	else {
		// If we've finally read enough into our buffer to process the entire mesage, then process it.
		if (m_Buffer.GetSize() >= m_CMD.fields.size)
		{
			ProcessMessage(m_CMD);
			m_bHaveHeader = false;
		} // otherwise if we haven't read enough, just read a bit more and wait until next time.
		else
			ReadBytesIntoBuffer();
	}

}

// We'll buffer 8K at a time for each user.
// It's smart enough not to read more data than required for the message payload.
// After that it would just start eating into the next header - so it stops.
void OTClientConnection::ReadBytesIntoBuffer()
{
	// At this point, the checksum has already validated. 
	// Might as well get the PAYLOAD next.
	int			err;
	uint32_t	nread;
	
	const int		nBufferSize = 8192; // todo no hardcoding.
	unsigned char	szBuffer[8192];
	
	//ultimately we want to read until m_Buffer.GetSize equals m_CMD.fields.size
	// In this function we'll read up to that or 8192, whichever is smaller.
	uint32_t	lNumberOfBytesRemaining	= m_CMD.fields.size - m_Buffer.GetSize();
	uint32_t	nNumberOfBytesToRead	= ((lNumberOfBytesRemaining > nBufferSize) ? nBufferSize : lNumberOfBytesRemaining);
	
	// actually read the payload from the socket into the buffer.
	for (nread = 0;  nread < nNumberOfBytesToRead;  nread += err)
	{
		err = SFSocketRead(m_pSocket, 
						   szBuffer + nread,
						   nNumberOfBytesToRead - nread);
		
		// if we don't read anything more, stop reading and move on
		if (err <= 0)
			break;
	}
	
	// If we read anything, up to 4K, we add it to the m_Buffer.
	// This continues happening until m_Buffer.GetSize() == m_CMD.fields.size 
	// and then other code reads the message from the buffer and processes it.
	if (nread)
	{
		OTData toAddData(szBuffer, nread);
		m_Buffer += toAddData;
	}
}


// If a valid header is received, this function gets called.
// The job of this function is to creae the message, read it, and add it to m_listIn.
// ...and also, if there are unexpected bytes, to flush them in anticipation of the
// next valid message.
void OTClientConnection::ProcessMessage(u_header & theCMD)
{
	bool bSuccess = false;
		
	OTMessage * pMsg = NULL;
	
	if ( theCMD.fields.type_id == CMD_TYPE_1 )
	{
		fprintf(stderr, "Received a Type 1 Command...\n");
		
		if( IsChecksumValid( theCMD.buf, OT_CMD_HEADER_SIZE ) )
		{								
			fprintf(stderr, "Checksum is valid! Processing payload.\n");
			
			pMsg = new OTMessage;
			
			if (ProcessType1Cmd(theCMD, *pMsg ))
			{
				AddToInputList(*pMsg);
				bSuccess = true;
			}
			else {
				delete pMsg;
				pMsg = NULL;
			}

		}
		else
		{
			//gDebugLog.Write("Invalid checksum - Type 1 Command");
			fprintf(stderr, "Invalid checksum - Type 1 Command, header size: %d\n", OT_CMD_HEADER_SIZE);
		}
	}
	else
	{
		//gDebugLog.Write("Unknown command type");
		fprintf(stderr, "Unknown command type\n");
		
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
			
			if (err >= 0)
				nread += err;

			if (err <= 0)
				break;
		}
		
		fprintf(stderr, "Transmission error--%d bytes flushed.\n", nread);
		
		// we are buffering data from the pipe now, so if we flush the pipe, we
		// should flush the buffer too.
		m_Buffer.Release();
	}
	else 
	{
		// TODO still need to process the commands and send the replies somewhere...
		//if (bSuccess = theServer.ProcessUserCommand(theMessage, theReply))
		//{
	//		fprintf(stderr, "Successfully processed user command: %s\n", theMessage.m_strCommand.Get());
//			ProcessReply(ssl, theReply);
//		}
//		else
//		{
//			fprintf(stderr, "Unable to process user command in XML, or missing payload, in ProcessMessage.\n");
//		}
	}
}



// A certain number of bytes are expected in the payload, according to the header.
// This function tries to read that many bytes, and inserts them into an OTPayload object.
// From there, a simple method call extracts the message, we return true, and the message
// gets added to our internal list for processing.
bool OTClientConnection::ProcessType1Cmd(u_header & theCMD, OTMessage & theMessage)
{
	// At this point, the checksum has already validated. 
	// Might as well get the PAYLOAD next.
//	int  err;
	uint32_t nread, lSize = theCMD.fields.size;
	
	// Make sure our byte-order is correct here.
//	theCMD.fields.size = ntohl(theCMD.fields.size); // I was doing this twice!! This is already done when the header is first read.

	// setup the buffer we are reading into
	OTPayload thePayload;
	nread = thePayload.ReadBytesFrom(m_Buffer, lSize);
	
	/*
	// actually read the payload from the socket into the buffer.
	for (nread = 0;  nread < theCMD.fields.size;  nread += err)
	{
		err = SFSocketRead(m_pSocket, 
						   (unsigned char *)thePayload.GetPayloadPointer() + nread,
						   theCMD.fields.size - nread);
		
		// if we don't read anything more, stop reading and move on
		if (err <= 0)
			break;
	}
	*/
	// TODO fix the buffering so that if a complete command has not yet been received, it saves the other
	// bytes instead of discarding them.  For now I'll just sleep for a second to make sure the entire command
	// was received.
//	sleep(1);
	
	// ------------------------------------------------------------
	
	// Try to interpret the command number.
	// Right now we support signed messages and encrypted envelopes containing
	// signed messages.
	switch (theCMD.fields.command_id) {
		case TYPE_1_CMD_1:
			fprintf(stderr, "Received Type 1 CMD 1:\nThere is a signed OTMessage in the payload.\n");
			break;
		case TYPE_1_CMD_2:
			fprintf(stderr, "Received Type 1 CMD 2:\n"
					"There is an encrypted OTEnvelope (containing signed OTMessage) in the payload.\n");
			break;
		default:
			fprintf(stderr, "Received unexpected command number %d in OTClientConnection::ProcessType1Cmd\n", 
					theCMD.fields.command_id);
			break;
	}
	
	// ------------------------------------------------------------
	// Hm, that's weird. It was a 0 size payload message. DoS?
	if (theCMD.fields.size == 0)
	{
		fprintf(stderr, "(The payload was a 0 size.)\n");
		return true;
	}
	// Uh-oh, somehow the number of bytes read was less than what we expected...
	else if (nread < theCMD.fields.size)
	{
		// TODO: Verify that the amount read matched the amount expected
		// if not, we have a problem that needs to be handled.
		
		// Long term solution is to buffer the data as a comes in and just
		// add it to the buffer.
		
		// Then if we don't have the complete message yet, we just come around next
		// time some data is read, and we add that to the buffer, THEN we check to see
		// if there are enough bytes yet read to match the amount expected according to
		// the header.
		//
		// Until I can do that, I'm not yet TRULY asynchronous. TODO: lookup a good buffer class.

		fprintf(stderr, "Number of bytes read did NOT match size in header.\n");
		return false;
	}
	else
		fprintf(stderr, "Loaded a payload, size: %d\n", theCMD.fields.size);
	
	// ------------------------------------------------------------
	
	// Okay so now we've received the expected size from the socket. Let's transfer it
	// into an object type that we can manipulate here in code. (Message or Envelope.)
	
	// a signed OTMessage
	if (TYPE_1_CMD_1 == theCMD.fields.command_id) 
	{
		if (thePayload.GetMessage(theMessage))
		{
			fprintf(stderr, "Successfully retrieved payload message...\n");
			
			if (theMessage.ParseRawFile())
			{
				fprintf(stderr, "Successfully parsed payload message.\n");
				
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
			fprintf(stderr, "Successfully retrieved envelope from payload...\n");
			
			OTString strEnvelopeContents;
			
			// Decrypt the Envelope.    
			if (m_pServer && theEnvelope.Open(m_pServer->GetServerNym(), strEnvelopeContents))
			{
				// All decrypted, now let's load the results into an OTMessage.
				// No need to call theMessage.ParseRawFile() after, since
				// LoadContractFromString handles it.
				//
				if (theMessage.LoadContractFromString(strEnvelopeContents))
				{
//					fprintf(stderr, "Success loading message out of the envelope contents and parsing it.\n");
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
	
	
	return true;
	
}


// At certain times, when the server has verified that a Nym REALLY is who
// he says he is, he sets the public key onto the connection object for
// that nym.  That way, if the connection object ever needs to encrypt something
// being sent to the client, he has access to the public key.
void OTClientConnection::SetPublicKey(const OTString & strPublicKey)
{	
	// SetPublicKey takes the ascii-encoded text, including bookends, and processes
	// it into the OTAssymeticKey object. If successful, the OTAssymetricKey is now
	// fully functional for encrypting and verifying.
	m_PublicKey.SetPublicKey(strPublicKey, true/*bEscaped*/);
}

void OTClientConnection::SetPublicKey(const OTAsymmetricKey & thePublicKey)
{
	OTString strNymsPublicKey;
	
	thePublicKey.GetPublicKey(strNymsPublicKey, true);
	m_PublicKey.SetPublicKey(strNymsPublicKey, true/*bEscaped*/);
}

// Process my reply back out to the client.  @something.
void OTClientConnection::ProcessReply(OTMessage &theReply)
{
    int  err;
	uint32_t nwritten;
	bool bSendCommand = false;
	bool bSendPayload = false;
	
	u_header  theCMD;
	OTPayload thePayload;

	// For now let's send ALL replies in Envelopes (encrypted to public key of client)
	// IF we have a public key, that is. Otherwise we send as a normal message.
	//
	// All messages already require either a public key, or a nymID used to look up a
	// public key. So given that I have that information when I reply, I might as well
	// ENCRYPT my reply to that same public key. More secure that way.
	//
	// The wallet (and server) are both ready to open and process these encrypted envelopes.
	
		
	// If GetKey() returns something, that means the key was set in there, it's
	// not just a null pointer. This means we can use it!  So let's encrypt to it.
	if (m_PublicKey.GetKey())
	{
		OTString strEnvelopeContents;
		// Save the ready-to-go message into a string.
		theReply.SaveContract(strEnvelopeContents);
		
		OTEnvelope theEnvelope;
		// Seal the string up into an encrypted Envelope
		theEnvelope.Seal(m_PublicKey, strEnvelopeContents);
		
		// From here on out, theMessage is disposable. OTPayload takes over. 
		// OTMessage doesn't care about checksums and headers.
		thePayload.SetEnvelope(theEnvelope);
		
		// Now that the payload is ready, we'll set up the header.
		SetupHeader(&theCMD, CMD_TYPE_1, TYPE_1_CMD_2, thePayload);
	}
	else {
		thePayload.SetMessage(theReply);
		
		// Now that the payload is ready, we'll set up the header.
		SetupHeader(&theCMD, CMD_TYPE_1, TYPE_1_CMD_1, thePayload);
	}
	
	bSendCommand = true;
	bSendPayload = true;				
	
	
	fprintf(stderr, "\n****************************************************************\n"
			"===> Finished setting up header for response.\nFirst 9 bytes are: %d %d %d %d %d %d %d %d %d...\n",
			theCMD.buf[0], theCMD.buf[1], theCMD.buf[2], theCMD.buf[3], theCMD.buf[4], 
			theCMD.buf[5], theCMD.buf[6], theCMD.buf[7], theCMD.buf[8]);
	
	
	// ------------------------------------------------------------------------------			
	/*
	 // Write to Client
	 strcpy(buffer, "Hello Client!");
	 SFSocketWrite(clientSocket, buffer, strlen(buffer));
	 
	 */
	
	if (bSendCommand)
	{
		
		int nHeaderSize = OT_CMD_HEADER_SIZE;
		
		for (nwritten = 0;  nwritten < nHeaderSize;  nwritten += err)
		{
			err = SFSocketWrite(m_pSocket, theCMD.buf + nwritten, nHeaderSize - nwritten);
			if (err <= 0)
				break;
		}
	}
	// At this point, we have sent the header across the pipe.
	
	if (bSendPayload)
	{
		
		uint32_t nPayloadSize = thePayload.GetSize();
		
		for (nwritten = 0;  nwritten < nPayloadSize;  nwritten += err)
		{
			err = SFSocketWrite(m_pSocket, (unsigned char *)thePayload.GetPayloadPointer() + nwritten, nPayloadSize - nwritten);
			if (err <= 0)
				break;
		}		
	}
	// At this point, we have sent the payload across the pipe.		
	
	fprintf(stderr, "...Done.\n");
}



void OTClientConnection::AddToInputList(OTMessage & theMessage)
{
	m_listIn.AddToList(theMessage);
}

OTMessage * OTClientConnection::GetNextInputMessage()
{
	return m_listIn.GetNextMessage();
}


void OTClientConnection::AddToOutputList(OTMessage & theMessage)
{
	m_listOut.AddToList(theMessage);

}


OTMessage * OTClientConnection::GetNextOutputMessage()
{
	return m_listOut.GetNextMessage();
}


OTClientConnection::OTClientConnection(SFSocket & theSocket, OTServer & theServer)
{
	m_pSocket		= &theSocket;
	m_pServer		= &theServer;
	
	m_bHaveHeader	= false;
}

OTClientConnection::~OTClientConnection()
{
	// Disconnect Client
	SFSocketRelease(m_pSocket);     
}

