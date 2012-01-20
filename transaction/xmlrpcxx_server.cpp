/************************************************************************************
 *    
 *  xmlrpcxx_server.cpp  (The web-services implementation of the Open Transactions server.)
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



// NOTE:  The PATH and the PASSWORD are configurable on the command line!!!
//        Path is also now configurable in the ini file.
//        They are only here as DEFAULTS for convenience, so I don't have to
//        type them over and over again.  You can blank them out if you want, 
//        or set them to whatever is convenient for you on your system.
//

#define KEY_PASSWORD        "test"

// password is deprecated. 

// ------------------------------------------------

// TODO: what about android for all the defaults here? Are there ini files in android? Revisit.
// so far, treating it like unix since it is.

#ifdef _WIN32

#define OT_INI_FILE_DEFAULT	"C:\\ot.ini"
#define SERVER_PATH_DEFAULT	"C:\\~\\Open-Transactions\\transaction\\server_data"
#define CA_FILE             "certs\\special\\ca.crt"
#define DH_FILE             "certs\\special\\dh_param_1024.pem"
#define KEY_FILE            "certs\\special\\server.pem"

#else // UNIX

#define OT_INI_FILE_DEFAULT	"~/.ot/ot_init.cfg"
#define SERVER_PATH_DEFAULT	"./server_data"
#define CA_FILE             "certs/special/ca.crt"
#define DH_FILE             "certs/special/dh_param_1024.pem"
#define KEY_FILE            "certs/special/server.pem"

#endif

// NOTE: the CA file, DH file, and Key file are most likely not necessary in this XML-RPC version.
// I left them here for now but so far I don't see that I need them for anything.

// ----------------------------------------------------------------

#ifdef _WIN32
#include "OTLib/stdafx.h"
#endif

#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <iostream>
#include <list>
#include <string>
#include <unistd.h>


#include <zmq.hpp>

//#include "zhelpers.hpp"


extern "C" 
{
#ifdef _WIN32
#include <WinSock.h>
#else
#include <netinet/in.h>
#endif
	
#include <openssl/err.h>
#include <openssl/ssl.h>
}

// ------------------------------------


#include "SimpleIni.h"
#include "Timer.h"


// ------------------------------------

//#include "XmlRpc.h"

#include "OTStorage.h"

#include "main.h"

#include "OTMessage.h"
#include "OTEnvelope.h"

#include "OTServer.h"

#include "OTLog.h"


void ProcessMessage_ZMQ(const std::string & str_Message, std::string & str_Reply);

// -------------------------------------------------------------

//using namespace XmlRpc;


// The HTTP server
//XmlRpcServer theXmlRpcServer; // This object handles the network transport. (Over HHTP, in this case.)


// The Open Transactions server
OTServer * g_pServer = NULL;  // This object handles all the actual OT notarization processing.


// -------------------------------------------------------------

// This function is called for every OT Message that is sent for processing.
// One argument is passed, and a result string is passed back.
//
/*
class OT_XML_RPC : public XmlRpcServerMethod
{
public:
	OT_XML_RPC(XmlRpcServer* s) : XmlRpcServerMethod("OT_XML_RPC", s) 
	{
		// Do I need to do anything here? Doubt it.
	}
	
	void execute(XmlRpcValue& params, XmlRpcValue& result)
	{
		OT_ASSERT(NULL != g_pServer);
		
		// return value.
		std::string resultString = ""; // Whatever we put in this string is what will get returned.
		
		// First we grab the client's message (it's the first parameter.)
		std::string str_Message = std::string(params[0]); // Here I read the string containing the message.
		OTASCIIArmor ascMessage = str_Message.c_str();
		
		// ----------------------------------------------------------------------
		
		OTMessage theMsg, theReply; // we'll need these in a sec...

		OTEnvelope theEnvelope(ascMessage); // Now the base64 is decoded and the envelope is in binary form again.
		if (ascMessage.Exists())
		{
			OTLog::Output(2, "Successfully retrieved envelope from XmlRpc argument string...\n");
			
			OTString strEnvelopeContents;
			
			// Decrypt the Envelope.    
			if (theEnvelope.Open(g_pServer->GetServerNym(), strEnvelopeContents)) // now strEnvelopeContents contains the decoded message.
			{
				// All decrypted--now let's load the results into an OTMessage.
				// No need to call theMsg.ParseRawFile() after, since
				// LoadContractFromString handles it.
				//
				if (strEnvelopeContents.Exists() && theMsg.LoadContractFromString(strEnvelopeContents))
				{
					
					// In case you want to see all the incoming messages...
//					OTLog::vOutput(0, "%s\n\n", strEnvelopeContents.Get());
					
					// By constructing this without a socket, I put it in XmlRpc/http mode, instead of tcp/ssl.
					OTClientConnection theClient(*g_pServer); 

					// By optionally passing in &theClient, the client Nym's public key will be
					// set on it whenever verification is complete. (So for the reply, I'll 
					// have the key and thus I'll be able to encrypt reply to the recipient.)
					if (g_pServer->ProcessUserCommand(theMsg, theReply, &theClient))	
					{	
						// At this point the reply is ready to go, and theClient has the public key of the recipient...
						
						OTLog::vOutput(0, "Successfully processed user command: %s.\n", theMsg.m_strCommand.Get());
						
						// The transaction is now processed, and the server's reply message is in theReply.
						// Let's seal it up to the recipient's nym (in an envelope) and send back to the user...
						OTEnvelope theRecipientEnvelope;
						
						bool bSealed = theClient.SealMessageForRecipient(theReply, theRecipientEnvelope);

						if (bSealed)
						{
							OTASCIIArmor ascReply(theRecipientEnvelope);
							resultString = ascReply.Get();
						}
						else
							OTLog::Output(0, "Unable to seal envelope in OT_XML_RPC.\n");
					}
					else
						OTLog::Output(0, "Unable to process user command in OT_XML_RPC.\n");
				}
				else 
					OTLog::Error("Error loading message from envelope contents.\n");
			}
			else 
				OTLog::Error("Unable to open envelope.\n");
		}
		else 
			OTLog::Error("Error retrieving envelope from rpc.\n");


	// ----------------------------------------------------------------------
			
		result = resultString;
		
	}
} theOTXmlRpc(&theXmlRpcServer);
*/

	





class OTSocket
{
	zmq::context_t	* m_pContext;
	zmq::socket_t	* m_pSocket;
	
	OTString		m_strBindPath;
	
	void NewContext();
	
	bool HandlePollingError();
	bool HandleSendingError();
	bool HandleReceivingError();
	
public:
	OTSocket();
	~OTSocket();
	
	void Listen(const OTString & strBind);

	bool Receive(std::string & str_Message);
	bool Send(const std::string & str_Reply);
};


OTSocket::OTSocket() : m_pContext(NULL), m_pSocket(NULL)
{
	NewContext();
}

OTSocket::~OTSocket()
{
	// -----------------------------------
	// Clean up the socket and context.
	if (NULL != m_pSocket)
		delete m_pSocket;
	m_pSocket = NULL;
	// -----------------------------------
	if (NULL != m_pContext)
		delete m_pContext;
	m_pContext = NULL;
	// -----------------------------------
}


void OTSocket::NewContext()
{
	if (NULL != m_pSocket)
		delete m_pSocket;
	m_pSocket = NULL;
	
	if (NULL != m_pContext)
		delete m_pContext;
	
	m_pContext = new zmq::context_t(1);
	OT_ASSERT_MSG(NULL != m_pContext, "OTSocket::NewContext():  Failed creating network context: zmq::context_t * pContext = new zmq::context_t(1);");	
}

void OTSocket::Listen(const OTString &strBind)
{
	if (NULL != m_pSocket)
		delete m_pSocket;
	
	m_pSocket = new zmq::socket_t(*m_pContext, ZMQ_REP);  // RESPONSE socket (Request / Response.)
	OT_ASSERT_MSG(NULL != m_pSocket, "OTSocket::Listen: new zmq::socket(context, ZMQ_REP)");
	
	OTString strTemp(strBind); // In case m_strBindPath is what was passed in. (It happens.)
	m_strBindPath.Set(strTemp); // In case we have to close/reopen the socket to finish a send/receive.
	
	m_pSocket->bind(strBind.Get());
}
// -----------------------------------
/*
 typedef struct
 {
 void //*socket//;
 int //fd//;
 short //events//;
 short //revents//;
 } zmq_pollitem_t; 
 */

// The bool means true == try again soon, false == don't try again.
bool OTSocket::HandlePollingError()
{
	bool bRetVal = false;
	
	switch (errno) {
			// At least one of the members of the items array refers to a socket whose associated ØMQ context was terminated.
		case ETERM:
			OTLog::Error("OTSocket::HandlePollingError: Failure: At least one of the members of the items array refers to a socket whose associated ØMQ context was terminated. (Deleting and re-creating the context.)\n");
			this->NewContext();
			this->Listen(m_strBindPath);
			break;		
			// The provided items was not valid (NULL).
		case EFAULT:
			OTLog::Error("OTSocket::HandlePollingError: Failed: The provided polling items were not valid (NULL).\n");
			break;
			// The operation was interrupted by delivery of a signal before any events were available.
		case EINTR:
			OTLog::Error("OTSocket::HandlePollingError: The operation was interrupted by delivery of a signal before any events were available. Re-trying...\n");
			bRetVal = true;
			break;
		default:
			OTLog::Error("OTSocket::HandlePollingError: Default case. Re-trying...\n");
			bRetVal = true;
			break;
	}
	return bRetVal;
}

// return value bool, true == try again, false == error, failed.
//
bool OTSocket::HandleSendingError()
{
	bool bRetVal = false;
	
	switch (errno) {
			// Non-blocking mode was requested and the message cannot be sent at the moment.
		case EAGAIN:
			OTLog::vOutput(0, "OTSocket::HandleSendingError: Non-blocking mode was requested and the message cannot be sent at the moment. Re-trying...\n");
			bRetVal = true;
			break;
			// The zmq_send() operation is not supported by this socket type.
		case ENOTSUP:
			OTLog::Error("OTSocket::HandleSendingError: failure: The zmq_send() operation is not supported by this socket type.\n");
			break;
			// The zmq_send() operation cannot be performed on this socket at the moment due to the socket not being in the appropriate state. This error may occur with socket types that switch between several states, such as ZMQ_REP. See the messaging patterns section of zmq_socket(3) for more information.
		case EFSM:
			OTLog::vOutput(0, "OTSocket::HandleSendingError: The zmq_send() operation cannot be performed on this socket at the moment due to the socket not being in the appropriate state. Deleting socket and listening again...\n");
		{ OTString strTemp(m_strBindPath); this->Listen(strTemp); }
			break;
			// The ØMQ context associated with the specified socket was terminated.
		case ETERM:
			OTLog::Error("OTSocket::HandleSendingError: The ØMQ context associated with the specified socket was terminated. (Deleting and re-creating the context and the socket, and listening again.)\n");
			this->NewContext();
		{ OTString strTemp(m_strBindPath); this->Listen(strTemp); }
			break;
			// The provided socket was invalid.
		case ENOTSOCK:
			OTLog::Error("OTSocket::HandleSendingError: The provided socket was invalid. (Deleting socket and listening again...)\n");
		{ OTString strTemp(m_strBindPath); this->Listen(strTemp); }
			break;
			// The operation was interrupted by delivery of a signal before the message was sent. Re-trying...
		case EINTR:
			OTLog::Error("OTSocket::HandleSendingError: The operation was interrupted by delivery of a signal before the message was sent. (Re-trying...)\n");
			bRetVal = true;
			break;
			// Invalid message.
		case EFAULT:
			OTLog::Error("OTSocket::HandleSendingError: Failure: The provided pollitems were not valid (NULL).\n");
			break;
		default:
			OTLog::Error("OTSocket::HandleSendingError: Default case. Re-trying...\n");
			bRetVal = true;
			break;
	}
	return bRetVal;
}


bool OTSocket::HandleReceivingError()
{
	bool bRetVal = false;
	
	switch (errno) {
			// Non-blocking mode was requested and no messages are available at the moment.
		case EAGAIN:
			OTLog::vOutput(0, "OTSocket::HandleReceivingError: Non-blocking mode was requested and no messages are available at the moment. Re-trying...\n");
			bRetVal = true;
			break;
			// The zmq_recv() operation is not supported by this socket type.
		case ENOTSUP:
			OTLog::Error("OTSocket::HandleReceivingError: Failure: The zmq_recv() operation is not supported by this socket type.\n");
			break;
			// The zmq_recv() operation cannot be performed on this socket at the moment due to the socket not being in the appropriate state. This error may occur with socket types that switch between several states, such as ZMQ_REP. See the messaging patterns section of zmq_socket(3) for more information.
		case EFSM:
			OTLog::vOutput(0, "OTSocket::HandleReceivingError: The zmq_recv() operation cannot be performed on this socket at the moment due to the socket not being in the appropriate state. (Deleting socket and listening again...)\n");
		{ OTString strTemp(m_strBindPath); this->Listen(strTemp); }
			break;
			// The ØMQ context associated with the specified socket was terminated.
		case ETERM:
			OTLog::Error("OTSocket::HandleReceivingError: The ØMQ context associated with the specified socket was terminated. (Re-creating the context, and listening again with a new socket...)\n");
			this->NewContext();
		{ OTString strTemp(m_strBindPath); this->Listen(strTemp); }
			break;
			// The provided socket was invalid.
		case ENOTSOCK:
			OTLog::Error("OTSocket::HandleReceivingError: The provided socket was invalid. (Deleting socket and listening again.)\n");
		{ OTString strTemp(m_strBindPath); this->Listen(strTemp); }
			break;
			// The operation was interrupted by delivery of a signal before a message was available.
		case EINTR:
			OTLog::Error("OTSocket::HandleSendingError: The operation was interrupted by delivery of a signal before the message was sent. (Re-trying...)\n");
			bRetVal = true;
			break;
			// The message passed to the function was invalid.
		case EFAULT:
			OTLog::Error("OTSocket::HandleReceivingError: Failure: The message passed to the function was invalid.\n");
			break;
		default:
			OTLog::Error("OTSocket::HandleReceivingError: Default case. Re-trying...\n");
			bRetVal = true;
			break;
	}
	return bRetVal;
}


bool OTSocket::Send(const std::string & str_Reply)
{
	OT_ASSERT_MSG(NULL != m_pSocket, "m_pSocket == NULL in OTSocket::Send()");
	OT_ASSERT_MSG(NULL != m_pContext, "m_pContext == NULL in OTSocket::Send()");
	OT_ASSERT_MSG(str_Reply.size() > 0, "str_Reply.size() > 0");
	// -----------------------------------
	const long lLatencySendMilliSec	= OTLog::GetLatencySendMs();
	const long lLatencySendMicroSec	= lLatencySendMilliSec*1000; // Microsecond is 1000 times smaller than millisecond.
	
	// Convert the std::string (reply) into a ZMQ message
	zmq::message_t reply (str_Reply.length());
	memcpy((void *) reply.data(), str_Reply.c_str(), str_Reply.length());
	// -----------------------------------
	
	bool bSuccessSending	= false;
	
	if (OTLog::IsBlocking())
	{
		bSuccessSending = m_pSocket->send(reply); // Blocking.
	}
	else // not blocking
	{
		int		nSendTries	= OTLog::GetLatencySendNoTries();
		long	lDoubling	= lLatencySendMicroSec;		
		bool	bKeepTrying = true;
		
		while (bKeepTrying && (nSendTries > 0))
		{
			zmq::pollitem_t items [] = {
				{ (*m_pSocket), 0, ZMQ_POLLOUT,	0 }
			};
			
			const int nPoll = zmq::poll(&items[0], 1, lDoubling);	// ZMQ_POLLOUT, 1 item, timeout (microseconds in ZMQ 2.1; changes to milliseconds in 3.0)					
			lDoubling *= 2;
			
			if (items[0].revents & ZMQ_POLLOUT)
			{
				bSuccessSending = m_pSocket->send(reply, ZMQ_NOBLOCK); // <=========== SEND ===============
				OTLog::SleepMilliseconds( 1 );
				
				if (!bSuccessSending)
				{
					if (false == HandleSendingError())
						bKeepTrying = false;
				}
				else
					break; // (Success -- we're done in this loop.)
			}
			else if ((-1) == nPoll) // error.
			{
				if (false == HandlePollingError())
					bKeepTrying = false;
			}
			
			--nSendTries;
		}
	}
	
	return bSuccessSending;
}
// -----------------------------------

bool OTSocket::Receive(std::string & str_Message)
{
	OT_ASSERT_MSG(NULL != m_pContext, "m_pContext == NULL in OTSocket::Receive()");
	OT_ASSERT_MSG(NULL != m_pSocket, "m_pSocket == NULL in OTSocket::Receive()");
	// -----------------------------------	
	const long lLatencyRecvMilliSec	= OTLog::GetLatencyReceiveMs();
	const long lLatencyRecvMicroSec	= lLatencyRecvMilliSec*1000;
	
	// ***********************************
	//  Get the request.
	zmq::message_t request;
	
	bool bSuccessReceiving = false;
	
	// If failure receiving, re-tries 2 times, with 4000 ms max delay between each (Doubling every time.)
	//
	if (OTLog::IsBlocking())
	{
		bSuccessReceiving = m_pSocket->recv(&request); // Blocking.
	}
	else	// not blocking
	{
		long	lDoubling = lLatencyRecvMicroSec;
		int		nReceiveTries = OTLog::GetLatencyReceiveNoTries();
		bool	expect_request = true;
		while (expect_request) 
		{
			//  Poll socket for a request, with timeout
			zmq::pollitem_t items[] = { { *m_pSocket, 0, ZMQ_POLLIN, 0 } };
			
			const int nPoll = zmq::poll (&items[0], 1, lDoubling);
			lDoubling *= 2; // 100 ms, then 200 ms, then 400 ms == total of 700 ms per receive. (About 15 per 10 seconds.)
			
			//  If we got a request, process it
			if (items[0].revents & ZMQ_POLLIN) 
			{
				bSuccessReceiving = m_pSocket->recv(&request, ZMQ_NOBLOCK); // <=========== RECEIVE ===============
				OTLog::SleepMilliseconds( 1 );
				
				if (!bSuccessReceiving)
				{
					if (false == HandleReceivingError())
						expect_request = false;
				}
				else
					break; // (Success -- we're done in this loop.)				
			}
			else if (nReceiveTries == 0) 
			{
//				OTLog::Error("OTSocket::Receive: Tried to receive, based on polling data, but failed even after retries.\n");
				expect_request = false;
				break;
			}
			else if ((-1) == nPoll) // error.
			{
				if (false == HandlePollingError())
					expect_request = false;
			}
			
			--nReceiveTries;
		}
	}
	// ***********************************
	
	if (bSuccessReceiving && (request.size() > 0))
	{
		str_Message.reserve(request.size());
		str_Message.append(static_cast<const char *>(request.data()), request.size());	
	}
	
	return (bSuccessReceiving && (request.size() > 0));
}





// ----------------------------------------------------------------------


// The MAIN function for the server software, which starts up the XmlRpc (http server), 
// as well as Open Transactions.
//
int main(int argc, char* argv[])
{
	OTLog::vOutput(0, "\n\nWelcome to Open Transactions... Test Server -- version %s\n"
				   "(transport build: OTMessage -> OTEnvelope -> ZMQ )\n\n", OTLog::Version());
	// -----------------------------------------------------------------------

#ifdef _WIN32
	WSADATA wsaData;
	WORD wVersionRequested = MAKEWORD( 2, 2 );
	int nWSA = WSAStartup( wVersionRequested, &wsaData );
	OT_ASSERT_MSG(0 != nWSA, "Error calling WSAStartup.\n");	
#endif
	
	// -----------------------------------------------------------------------
	// I instantiate this here (instead of globally) so that I am assured all the globals
	// are ready to go before the server is created.  I still have it as a global pointer, though,
	// so I can get to it wherever I need to.
	g_pServer = new OTServer;
	// (This file you are reading is a wrapper for OTServer, which adds the transport layer.)

	OT_ASSERT_MSG(NULL != g_pServer, "Unable to instantiate OT server...\n");
	
	// -----------------------------------------------------------------------
	// The beginnings of an INI file!!
	
    OTString strIniFileDefault;
    OTLog::TransformFilePath(OT_INI_FILE_DEFAULT, strIniFileDefault);
	
	OTString strPath, strRawPath(SERVER_PATH_DEFAULT);
	
	{
		CSimpleIniA ini;
		
		SI_Error rc = ini.LoadFile(strIniFileDefault.Get());
		
		if (rc >=0)
		{
            {
                const char * pVal = ini.GetValue("paths", "server_path", SERVER_PATH_DEFAULT); // todo stop hardcoding.
                
                if (NULL != pVal)
                {
                    strRawPath.Set(pVal);
                    OTLog::vOutput(0, "Reading ini file (%s). \n Found Server data_folder path: %s \n", 
                                   strIniFileDefault.Get(), strRawPath.Get());
                }
                else
                {
                    strRawPath.Set(SERVER_PATH_DEFAULT);
                    OTLog::vOutput(0, "Reading ini file (%s): \n Failed reading Server data_folder path. Using: %s \n", 
                                   strIniFileDefault.Get(), strRawPath.Get());
                }
            }            
		}
		else 
		{
			strRawPath.Set(SERVER_PATH_DEFAULT);
			OTLog::vOutput(0, "Unable to load ini file (%s) to find data_folder path\n Will assume that server data_folder is at path: %s \n", 
						   strIniFileDefault.Get(), strRawPath.Get());
		}
	}
        
	// -----------------------------------------------------------------------

	OTString strCAFile, strDHFile, strKeyFile;  //, strSSLPassword;
	
    OTLog::TransformFilePath(strRawPath.Get(), strPath);
    
    OTLog::SetMainPath(strPath.Get());
    	
	OTLog::vOutput(0, "Using data_folder path:  %s\n", OTLog::Path());
	
	strCAFile. Format("%s%s%s", OTLog::Path(), OTLog::PathSeparator(), CA_FILE);
	strDHFile. Format("%s%s%s", OTLog::Path(), OTLog::PathSeparator(), DH_FILE);
	strKeyFile.Format("%s%s%s", OTLog::Path(), OTLog::PathSeparator(), KEY_FILE);
	
	
	
	// -----------------------------------------------------------------------
	
	// Initialize SSL -- This MUST occur before any Private Keys are loaded!
	SSL_library_init();
	SSL_load_error_strings();
	
	// Init loads up server's nym so it can decrypt messages sent in envelopes.
	// It also does various other initialization work.
	//
	// (Envelopes prove that ONLY someone who actually had the server contract,
	// and had loaded it into his wallet, could ever connect to the server or 
	// communicate with it. And if that person is following the contract, there
	// is only one server he can connect to, and one key he can use to talk to it.)
	
	OTLog::vOutput(0, 
				   "\nNow loading the server nym, which will also ask you for a password, to unlock\n"
				   "its private key. (Default password is \"%s\".)\n", KEY_PASSWORD);
	
	g_pServer->Init(); // Keys, etc are loaded here.
	
	// -----------------------------------------------------------------------
	// We're going to listen on the same port that is listed in our server contract.
	//
	//
	OTString	strHostname;	// The hostname of this server, according to its own contract.
	int			nPort=0;		// The port of this server, according to its own contract.
	
	OT_ASSERT_MSG(g_pServer->GetConnectInfo(strHostname, nPort),
				  "Unable to find my own connect info (which is in my server contract BTW.)\n");
	
	const int	nServerPort = nPort;
	
	// -----------------------------------------------------------------------
	// For re-occuring actions (like markets and payment plans.)
	//
	g_pServer->ActivateCron();

	// --------------------------------------
	//  Prepare our context and socket
	OTSocket theSocket;
	OTString strBindPath; strBindPath.Format("%s%d", "tcp://*:", nServerPort);
	theSocket.Listen(strBindPath);
	// -----------------------------------------------------------------------



	// ******************************************************************************************
	do  // THE HEARTBEAT LOOP FOR THE OPEN-TRANSACTIONS SERVER! 
	{
		//
		// The Server now processes certain things on a regular basis.
		// ProcessCron is what gives it the opportunity to do that.
		// All of the Cron Items (including market trades, and payment plans...) 
		// they all have their hooks here...
		//

		g_pServer->ProcessCron();  // Internally this is smart enough to know how often to actually activate itself. Most often it just returns doing nothing (waiting for its timer.)

		
		// -----------------------------------------------------------------------
		// Wait for client http requests (and process replies out to them.)
		// ----------------------------------------------------------------------
		// Number of requests to process per heartbeat: OTServer::GetHeartbeatNoRequests()
		//
		// Loop: process up to 10 client requests, then sleep for 1/10th second.
		// That's a total of 100 requests per second. Can the computers handle it? 
		// Is it too much or too little? Todo: load testing.
		//
		// Then: check for shutdown flag.
		//
		// Then: go back to the top ("do") and repeat the loop.... process cron, 
		// process 10 client requests, sleep, check for shutdown, etc.
		//
		//
                
		Timer t;	// start timer
		t.start();
		const double tick1 = t.getElapsedTimeInMilliSec();
		// -----------------------------------------------------
		
		for (int i = 0; i < /*10*/OTServer::GetHeartbeatNoRequests(); i++) 
		{
			std::string	str_Message;
			
			// With 100ms heartbeat, receive will try 100 ms, then 200 ms, then 400 ms, total of 700.
			// That's about 15 Receive() calls every 10 seconds. Therefore if I want the ProcessCron()
			// to trigger every 10 seconds, I need to set the cron interval to roll over every 15 heartbeats.
			// Therefore I will be using a real Timer for Cron, instead of the damn intervals.
			//
			bool		bReceived = theSocket.Receive(str_Message);  
			
			if (bReceived)
			{
				std::string str_Reply; // Output.
				
				if (str_Message.length() <= 0)
				{
					OTLog::Error("main function: Received a message, but of 0 length or less. Weird. (Skipping it.)\n");
				}
				else // ------------------------------------
				{
					ProcessMessage_ZMQ(str_Message, str_Reply); // <================== PROCESS the message!
					// --------------------------------------------------

					if (str_Reply.length() <= 0)
					{
						OTLog::vOutput(0, "Main function: Unfortunately, not every client request is legible or worthy of a server response. :-)  "
									   "Msg:\n\n%s\n\n", str_Message.c_str());
					}
					else
					{
						bool bSuccessSending = theSocket.Send(str_Reply); // <===== SEND THE REPLY
						
						if (false == bSuccessSending)
							OTLog::vError("Socket error: failed while trying to send reply back to client! \n\n MESSAGE:\n%s\n\nREPLY:\n%s\n\n", 
										  str_Message.c_str(), str_Reply.c_str());
						// --------------------------------------------------
					}
				}
			}
		} //  for
		
		// -----------------------------------------------------------------------
		
		const	double tick2	= t.getElapsedTimeInMilliSec();
		const	long elapsed	= static_cast<long>(tick2 - tick1);
		long	lSleepMS		= 0;
			
		if (elapsed < /*100*/OTServer::GetHeartbeatMsBetweenBeats()) 
		{
			lSleepMS = OTServer::GetHeartbeatMsBetweenBeats() - elapsed;

			// Now go to sleep.
			// (The main loop processes ten times per second, currently.)		
			OTLog::SleepMilliseconds(lSleepMS); // 100 ms == (1 second / 10)
		}
		
		// -----------------------------------------------------------------------
		// ARTIFICIAL LIMIT:
		// 10 requests per heartbeat, 10 rounds per second == 100 requests per second.
		//
		// *** ONE HUNDRED CLIENT MESSAGES PER SECOND is the same as:
		// 
		//     6000 PER MINUTE == 360,000 PER HOUR == 8,640,000 PER DAY***
		//
		// Speeding it up is just a matter of adjusting the above numbers, and TESTING to see if OT can handle it.
		// (Not counting optimization of course.)
		//
		// -----------------------------------------------------------------------

		if (g_pServer->IsFlaggedForShutdown())
		{
			OTLog::Output(0, "Server is shutting down gracefully....\n");
			break;
		}
    } while (1);
	
	
	// TODO: cleanup OpenSSL here.
	
#ifdef _WIN32
	WSACleanup();
#endif
	
	return 0;
}



void ProcessMessage_ZMQ(const std::string & str_Message, std::string & str_Reply)
{
	OT_ASSERT(NULL != g_pServer);
	
	if (str_Message.size() < 1)
		return;
	
	// --------------------
	
	// return value.
	std::string resultString = ""; // Whatever we put in this string is what will get returned.
	
	// First we grab the client's message
	OTASCIIArmor ascMessage;
	ascMessage.MemSet(str_Message.data(), str_Message.size());
	
	// ------------------
//	
//	OTPayload thePayload;
//	thePayload.SetPayloadSize(str_Message.size());	
//	memcpy((void*)thePayload.GetPayloadPointer(), str_Message.data(), str_Message.size());
	
	// ----------------------------------------------------------------------
	
//	OTLog::vError("Envelope: \n%s\n Size: %ld\n", ascMessage.Get(), ascMessage.GetLength());
	
	OTMessage theMsg, theReply; // we'll need these in a sec...
	
//	OTEnvelope theEnvelope(ascMessage);
	OTEnvelope theEnvelope; 
	
	if (false == theEnvelope.SetAsciiArmoredData(ascMessage))
		OTLog::Error("Error retrieving envelope from ProcessMessage_ZMQ.\n");
	else
	{	// Now the base64 is decoded and the envelope is in binary form again.
		OTLog::Output(2, "Successfully retrieved envelope from ZMQ message...\n");
		
		OTString strEnvelopeContents;
		
//		OTString strPubkeyPath("TESTPUBKEY.txt");
//		g_pServer->GetServerNym().SavePublicKey(strPubkeyPath);
		
		// Decrypt the Envelope.    
		if (false == theEnvelope.Open(g_pServer->GetServerNym(), strEnvelopeContents)) // now strEnvelopeContents contains the decoded message.
			OTLog::Error("Unable to open envelope. ProcessMessage_ZMQ.\n");
		else
		{
			// All decrypted--now let's load the results into an OTMessage.
			// No need to call theMsg.ParseRawFile() after, since
			// LoadContractFromString handles it.
			//
			if (strEnvelopeContents.Exists() && theMsg.LoadContractFromString(strEnvelopeContents))
			{
				theReply.m_strCommand.Format("@%s", theMsg.m_strCommand.Get());
				theReply.m_strNymID		= theMsg.m_strNymID;	// UserID
				theReply.m_strServerID	= theMsg.m_strServerID;	// ServerID, a hash of the server contract.
				theReply.m_bSuccess		= false;				// The default reply. In fact this is probably superfluous.
				
				// In case you want to see all the incoming messages...
//				OTLog::vOutput(0, "%s\n\n", strEnvelopeContents.Get());
				
				// By constructing this without a socket, I put it in ZMQ mode, instead of tcp/ssl.
				OTClientConnection theClient(*g_pServer); 
								
				// By optionally passing in &theClient, the client Nym's public key will be
				// set on it whenever verification is complete. (So for the reply, I'll 
				// have the key and thus I'll be able to encrypt reply to the recipient.)
				if (false == g_pServer->ProcessUserCommand(theMsg, theReply, &theClient))
				{
					OTLog::Output(0, "Unable to process user command in ProcessMessage_ZMQ.\n");
					
					// NOTE: normally you would even HAVE a true or false if we're in this block. ProcessUserCommand()
					// is what tries to process a command and then sets false if/when it fails. Until that point, you
					// wouldn't get any server reply.  I'm now changing this slightly, so you still get a reply (defaulted
					// to success==false.) That way if a client needs to re-sync his request number, he will get the false
					// and therefore know to resync the # as his next move, vs being stuck with no server reply (and thus
					// stuck with a bad socket.)
					// We sign the reply here, but not in the else block, since it's already signed in cases where 
					// ProcessUserCommand() is a success, by the time that call returns.
					
					theReply.m_bSuccess = false; // Since the process call definitely failed, I'm making sure this here is definitely set to false (even though it probably was already.)
					theReply.SignContract(g_pServer->GetServerNym());
					theReply.SaveContract();
				}
				else	// At this point the reply is ready to go, and theClient has the public key of the recipient...
					OTLog::vOutput(1, "Successfully processed user command: %s.\n", theMsg.m_strCommand.Get());
				
				// -------------------------------------------------
				// The transaction is now processed (or not), and the server's reply message is in theReply.
				// Let's seal it up to the recipient's nym (in an envelope) and send back to the user...
				OTEnvelope theRecipientEnvelope;
				
				bool bSealed = theClient.SealMessageForRecipient(theReply, theRecipientEnvelope);
				
				if (false == bSealed)
					OTLog::Output(0, "Unable to seal envelope in ProcessMessage_ZMQ. (No reply will be sent.)\n");
				else
				{
//					OTPayload theReplyPayload;
//					theReplyPayload.SetEnvelope(theRecipientEnvelope);
//					resultString = ascReply.Get();
//					resultString.assign(theReplyPayload.GetPayloadPointer(), theReplyPayload.GetPayloadSize());
					
					OTASCIIArmor ascReply;
					if (theRecipientEnvelope.GetAsciiArmoredData(ascReply))
						resultString.assign(ascReply.Get(), ascReply.GetLength());
				}
			}
			else 
				OTLog::vError("ProcessMessage_ZMQ: Error loading message from envelope contents:\n\n%s\n\n",
							  strEnvelopeContents.Get());
		}
	}

	// ----------------------------------------------------------------------
	
	str_Reply = resultString;	
}















































