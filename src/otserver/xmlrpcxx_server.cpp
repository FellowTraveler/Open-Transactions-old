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


#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <iostream>
#include <list>
#include <string>
//#include <unistd.h>


#include <zmq.hpp>

//#include "zhelpers.hpp"

#ifdef _WIN32
#include <WinsockWrapper.h>
#endif

#ifdef _WIN32
#include <Shlobj.h>
#endif

extern "C" 
{
#ifdef _WIN32
#else
#include <netinet/in.h>
#endif
	
#include <openssl/err.h>
#include <openssl/ssl.h>
}

// ------------------------------------


#include "simpleini/SimpleIni.h"
#include "Timer.h"

// ---------------------------------------------------------------------------

#include "ot_default_paths.h"

// ---------------------------------------------------------------------------

//#include "XmlRpc.h"

#include "OTStorage.h"

#include "main.h"

#include "OTMessage.h"
#include "OTEnvelope.h"

#include "OTServer.h"

#include "OTLog.h"


// true  == YES, DISCONNECT m_pSocket, something must have gone wrong.
// false ==  NO, do NOT disconnect m_pSocket, everything went wonderfully!
//
bool ProcessMessage_ZMQ(OTServer & theServer, const std::string & str_Message, std::string & str_Reply);

// -------------------------------------------------------------

//using namespace XmlRpc;


// The HTTP server
//XmlRpcServer theXmlRpcServer; // This object handles the network transport. (Over HHTP, in this case.)


// The Open Transactions server
//OTServer * g_pServer = NULL;  // This object handles all the actual OT notarization processing.


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
	
	void Listen(); // assumes m_strBindPath is already set.
	void Listen(const OTString & strBind); // sets m_strBindPath

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
//	m_pContext = NULL;
	m_pContext = new zmq::context_t(1);
	OT_ASSERT_MSG(NULL != m_pContext, "OTSocket::NewContext():  Failed creating network context: zmq::context_t * pContext = new zmq::context_t(1);");	
}



void OTSocket::Listen() // assumes m_strBindPath is already set.
{
    const OTString strBind(m_strBindPath);
    
    this->NewContext();
    this->Listen(strBind);
}


void OTSocket::Listen(const OTString &strBind)
{
	if (NULL != m_pSocket)
		delete m_pSocket;
//	m_pSocket = NULL;
	m_pSocket = new zmq::socket_t(*m_pContext, ZMQ_REP);  // RESPONSE socket (Request / Response.)
	OT_ASSERT_MSG(NULL != m_pSocket, "OTSocket::Listen: new zmq::socket(context, ZMQ_REP)");
	
	OTString strTemp(strBind); // In case m_strBindPath is what was passed in. (It happens.)
	m_strBindPath.Set(strTemp); // In case we have to close/reopen the socket to finish a send/receive.
	
	// ------------------------
	//  Configure socket to not wait at close time
    //
	const int linger = 0; // close immediately
	m_pSocket->setsockopt (ZMQ_LINGER, &linger, sizeof (linger));
    /*
     int zmq_setsockopt (void *socket, int option_name, const void *option_value, size_t option_len);
     
     Caution: All options, with the exception of ZMQ_SUBSCRIBE, ZMQ_UNSUBSCRIBE and ZMQ_LINGER, only take effect for subsequent socket bind/connects.     
     */
    
	// ------------------------
    
	m_pSocket->bind(strBind.Get());
}
// -----------------------------------
/*
 typedef struct
 {
 void *socket;
 int fd;
 short events;
 short revents;
 } zmq_pollitem_t; 
 */

// The bool means true == try again soon, false == don't try again.
//
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


// ***********************************************************************
//
// EVR PATH
//
OTString GetRoamingAppDataLocation()
	{
#ifdef _WIN32

		
		TCHAR szPath[MAX_PATH];

		if(SUCCEEDED(SHGetFolderPath(NULL, 
                             CSIDL_APPDATA|CSIDL_FLAG_CREATE, 
                             NULL, 
                             0, 
                             szPath))) ;

		#ifdef UNICODE
		std::string stdpath = utf8util::UTF8FromUTF16(szPath);
		#else
		std::string string(szPath);
		std::string stdpath = szPath;
		#endif

		return stdpath;

		// Old Code... Good, except worked for Windows Vista or greater only.
		// We should use this code when we decide to disscontinue Win XP support.

		//wchar_t* roamingAppData = 0;
		//SHGetKnownFolderPath(FOLDERID_RoamingAppData, 0, NULL, &roamingAppData);

		//std::wstring basicstring(roamingAppData);

		//std::string stdstring = utf8util::UTF8FromUTF16(basicstring);

		//return stdstring;
#else
		return getenv("HOME");
#endif
	};


// ***********************************************************************
//
// INI FILE
//
bool GetOTAppDataFolderLocation(const OTString & strIniFileDefault, OTString & strOTServerDataLocation)
{
    CSimpleIniA ini;
    SI_Error rc = ini.LoadFile(strIniFileDefault.Get());
    if (rc >=0)
    {
        {
            const char * pVal = ini.GetValue("paths", "prefix_path", OT_PREFIX_DEFAULT); // todo stop hardcoding.
            
            if (NULL != pVal)
            {
                OTLog::SetPrefixPath(pVal);
                OTLog::vOutput(0, "server main: Reading ini file (%s). \n Found prefix_path: %s \n", 
                               strIniFileDefault.Get(), OTLog::PrefixPath());
            }
            else
                OTLog::vOutput(0, "server main:Ini file: %s: Failed to find prefix_path. \n", strIniFileDefault.Get());
        }            
        {
            const char * pVal = ini.GetValue("paths", "init_path", OT_FOLDER_DEFAULT); // todo stop hardcoding.
            
            if (NULL != pVal)
            {
                OTLog::SetConfigPath(pVal);
                OTLog::vOutput(0, "server main: Reading ini file (%s). \n Found Server init_path: %s \n", 
                               strIniFileDefault.Get(), OTLog::ConfigPath());
            }
            else
                OTLog::vOutput(0, "server main:Ini file: %s: Failed to find init_path. \n", strIniFileDefault.Get());
        }            
        {
            const char * pVal = ini.GetValue("paths", "server_path", SERVER_PATH_DEFAULT); // todo stop hardcoding.
            
            if (NULL != pVal)
            {
                strOTServerDataLocation.Set(pVal);
                OTLog::vOutput(0, "server main: Reading ini file (%s). \n Found Server data_folder path: %s \n", 
                               strIniFileDefault.Get(), strOTServerDataLocation.Get());
                return true;
            }
            
            OTLog::vOutput(0, "server main: Reading ini file (%s) \n", strIniFileDefault.Get());
            return false;
        }            
    }
    else 
    {
        OTLog::vOutput(0, "server main: Unable to load ini file (%s) to find data_folder path \n", 
                       strIniFileDefault.Get());
        return false;
    }
}






// *********************************************************************************************************
//
//
//             *** SERVER MAIN ***
//
//
// The MAIN function for the server software, which starts up the ZMQ listener, as well
// as well as the Open Transactions library and the OT Server object.
//
// After initialization, this function becomes the "main loop" of OT server.
//
int main(int argc, char* argv[])
{
	OTLog::vOutput(0, "\n\nWelcome to Open Transactions... Test Server -- version %s\n"
				   "(transport build: OTMessage -> OTEnvelope -> ZMQ )\n\n", OTLog::Version());

	// WINSOCK WINDOWS
	// -----------------------------------------------------------------------
#ifdef _WIN32

	WORD wVersionRequested;
	WSADATA wsaData;
	int err;

	/* Use the MAKEWORD(lowbyte, highbyte) macro declared in Windef.h */
	wVersionRequested = MAKEWORD(2, 2);

	err = WSAStartup(wVersionRequested, &wsaData);
	if (err != 0) {
	/* Tell the user that we could not find a usable		*/
	/* Winsock DLL.											*/
		printf("WSAStartup failed with error: %d\n", err);
		return 1;
	}

	/*	Confirm that the WinSock DLL supports 2.2.			*/
	/*	Note that if the DLL supports versions greater		*/
	/*	than 2.2 in addition to 2.2, it will still return	*/
	/*	2.2 in wVersion since that is the version we		*/
	/*	requested.											*/

	if (LOBYTE(wsaData.wVersion) != 2 || HIBYTE(wsaData.wVersion) != 2) {
		/* Tell the user that we could not find a usable */
		/* WinSock DLL.                                  */
		printf("Could not find a usable version of Winsock.dll\n");
		WSACleanup();
		return 1;
	}
	else
		printf("The Winsock 2.2 dll was found okay\n");

	/* The Winsock DLL is acceptable. Proceed to use it. */
	/* Add network programming using Winsock here */
	/* then call WSACleanup when done using the Winsock dll */
#endif





	// ***********************************************************************
    // INITIALIZATION and CLEANUP (for the OT library, and for this server application.)
    //
    class __ot_server_
    {
        OTServer * m_pServer;
    public:
        OTServer * GetServer() { return m_pServer; }
        // -----------------------------------
        __ot_server_() : m_pServer(NULL) // INIT 
        {
            // -----------------------------------------------------------------------   
	
            // -----------------------------------------------------------------------
            // OTLog class exists on both client and server sides.
            // #define OT_NO_SIGNAL_HANDLING if you want to turn off OT's signal handling.
            //
#if defined(OT_SIGNAL_HANDLING)
            OTLog::SetupSignalHandler(); // This is optional! (I, of course, am using it in this test app...)
#endif
            // -----------------------------------------------------------------------    
            // I instantiate this here (instead of globally) so that I am assured that any globals and other
            // setup is already done before we instantiate the server object itself.
            //
            OT_ASSERT_MSG(NULL == m_pServer, "server main(): ASSERT: NULL == m_pServer.");
            m_pServer = new OTServer;
            //
            // (This .cpp file you are currently reading is a wrapper for OTServer,
            // which adds the transport layer.)
            //
            OT_ASSERT_MSG(NULL != m_pServer, "server main(): ASSERT: Unable to instantiate OT server.\n");

			OTString pathUserAppDataPath, pathIniFileLocation;

			pathUserAppDataPath = GetRoamingAppDataLocation();
			pathIniFileLocation.Format("%s%s%s", pathUserAppDataPath.Get(), OTLog::PathSeparator(), SERVER_INI_FILE_DEFAULT);


			OTString pathOTServerDataLocation;

			OTLog::vOutput(0, "\nFound ot_init.cfg in: \n     %s \nNow checking to see if it contains the OT Server path...", pathIniFileLocation.Get());
			// Read the File, If successful use result

			if (false == GetOTAppDataFolderLocation(pathIniFileLocation, pathOTServerDataLocation))
			{
				OTLog::vOutput(0, "Path not found... Will attempt default!... \n");
				// Not successfull will will assume it is in default location:
				pathOTServerDataLocation.Format("%s%s%s", pathUserAppDataPath.Get(), OTLog::PathSeparator(), SERVER_PATH_DEFAULT);
			};

			OTLog::vOutput(0, "     %s \n", pathOTServerDataLocation.Get());


			OTLog::SetMainPath(pathOTServerDataLocation.Get());              // <============ SET MAIN PATH
            OTLog::vOutput(0, "Using server_data path:  %s\n", OTLog::Path());


            // -----------------------------------------------------------------------    
            
            OTCrypto::It()->Init();  // <========== (OpenSSL gets initialized here.)
            
        }
        // ****************************************
        //
        ~__ot_server_()  // CLEANUP
        {
            OTLog::vOutput(0, "\n\n OT version %s, shutting down and cleaning up.\n",
                           OTLog::Version());

            // ------------------------------
            if (NULL != m_pServer)
                delete m_pServer;
            m_pServer = NULL;
            // ------------------------------
            // We clean these up in reverse order from the Init function, which just seems
            // like the best default, in absence of any brighter ideas.
            //
            OTCrypto::It()->Cleanup();  // <======= (OpenSSL gets cleaned up here.)

            // -------------------------
            // (This is at the bottom, since we do the cleanup in the 
            // reverse order from initialization.)
#ifdef _WIN32
            WSACleanup();
#endif
        }
    };	
	// ***********************************************************************
    //
    // INSTANTIATE and INITIALIZE...
    //
    // (Cleanup happens automatically when this object goes out of scope.)
    //
    __ot_server_  the_server_obj;
    OTServer * pServer = the_server_obj.GetServer();
    OT_ASSERT(NULL != pServer);
    // -----------------------------------------------------------------------
//	OTString strCAFile, strDHFile, strKeyFile;  //, strSSLPassword;
//	strCAFile. Format("%s%s%s", OTLog::Path(), OTLog::PathSeparator(), CA_FILE);
//	strDHFile. Format("%s%s%s", OTLog::Path(), OTLog::PathSeparator(), DH_FILE);
//	strKeyFile.Format("%s%s%s", OTLog::Path(), OTLog::PathSeparator(), KEY_FILE);
	// -----------------------------------------------------------------------
    //
    // UPDATE: This was moved to OTLog::OT_Init(), which is called above, by the
    // nested cleanup class.
    //
	// Initialize SSL -- This MUST occur before any Private Keys are loaded!
//	SSL_library_init();
//	SSL_load_error_strings();
	
	// -----------------------------------------------------------------------
	// OTServer::Init loads up server's nym so it can decrypt messages sent in
    // envelopes. It also does various other initialization work.
	//
	// (Envelopes prove that ONLY someone who actually had the server contract,
	//  and had loaded it into his wallet, could ever connect to the server or 
	//  communicate with it. And if that person is following the contract, there
	//  is only one server he can connect to, and one key he can use to talk to it.)
	//
	OTLog::vOutput(0, 
				   "\nNow loading the server nym, which will also ask you for a password, to unlock\n"
				   "its private key. (Default password is \"%s\".)\n", KEY_PASSWORD);
	
	pServer->Init(); // Keys, etc are loaded here. ===> Assumes main path is set! <===
	
	// -----------------------------------------------------------------------
	// We're going to listen on the same port that is listed in our server contract.
	//
	//
	OTString	strHostname;	// The hostname of this server, according to its own contract.
	int			nPort=0;		// The port of this server, according to its own contract.
	
    const bool bConnectInfo = pServer->GetConnectInfo(strHostname, nPort);
    
	OT_ASSERT_MSG(bConnectInfo, "server main: Unable to find my own connect info (which SHOULD be in my server contract, BTW.) Perhaps you failed trying to open that contract? Have you tried the test password? (\"test\")\n");
	
	const int   nServerPort = nPort;
	
	// -----------------------------------------------------------------------
    // OT CRON
    //
    // A heartbeat for recurring transactions, such as markets, payment plans,
    // and smart contracts.

	pServer->ActivateCron();

    // NOTE: Currently we trigger OT Cron's processing internally, but there's no reason why, in the
    // future, we can't make an actual cron job that triggers a script, that fires a message
    // to OT, causing OT to process its Cron (even if we were single-threaded we could do this...)
    //
    // Have to put some thought into it...
    //
    // Wouldn't require much security, since OT can still be smart enough not to process cron any
    // more often than X minutes, no matter HOW many times the ProcessCron script fires.
    // Thing is, though, that with this setup, we can't really guarantee that cron will EVER be
    // triggered -- whereas the way OT is now, at least we know it WILL fire every X seconds.
    //
    
	// --------------------------------------
    //
    // NETWORK
    //
	// Prepare our context and listening socket...

	OTSocket theSocket;
	OTString strBindPath; strBindPath.Format("%s%d", "tcp://*:", nServerPort);
	theSocket.Listen(strBindPath);
    
    // ******************************************************************************************
    //
    //      *** MAIN LOOP ***
    //
	do // ---------------------------
	{
        // =-=-=- HEARTBEAT -=-=-=
		//
		// The Server now processes certain things on a regular basis.
		// ProcessCron is what gives it the opportunity to do that.
		// All of the Cron Items (including market trades, payment plans, smart contracts...) 
		// they all have their hooks here...
		//
		pServer->ProcessCron();  // Internally this is smart enough to know how often to actually activate itself.
                                   // Most often it just returns doing nothing (waiting for its timer.)		
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
		//
        // PROCESS X NUMBER OF REQUESTS (THIS PULSE.)
        //
        // Theoretically the "number of requests" that we process EACH PULSE.
        // (The timing code here is still pretty new, need to do some load testing.)
        //
		for (int i = 0; i < /*10*/OTServer::GetHeartbeatNoRequests(); i++) 
		{
			std::string	str_Message;
			
			// With 100ms heartbeat, receive will try 100 ms, then 200 ms, then 400 ms, total of 700.
			// That's about 15 Receive() calls every 10 seconds. Therefore if I want the ProcessCron()
			// to trigger every 10 seconds, I need to set the cron interval to roll over every 15 heartbeats.
			// Therefore I will be using a real Timer for Cron, instead of the damn intervals.
			//
			bool bReceived = theSocket.Receive(str_Message);  
			
			if  (bReceived)
			{
				std::string str_Reply; // Output.
				
				if (str_Message.length() <= 0)
				{
					OTLog::Error("server main: Received a message, but of 0 length or less. Weird. (Skipping it.)\n");
				}
				else // ------------------------------------
				{
                    // true  == YES, DISCONNECT m_pSocket, something must have gone wrong.
                    // false ==  NO, do NOT disconnect m_pSocket, everything went wonderfully!
                    //
					const bool bShouldDisconnect = ProcessMessage_ZMQ(*pServer, str_Message, str_Reply); // <================== PROCESS the message!
					// --------------------------------------------------

					if ((str_Reply.length() <= 0) || bShouldDisconnect)
					{
						OTLog::vOutput(0, "server main: ERROR: Unfortunately, not every client request is "
                                       "legible or worthy of a server response. :-)  "
									   "Msg:\n\n%s\n\n", str_Message.c_str());
                        
                        theSocket.Listen();
					}
					else
					{
						bool bSuccessSending = theSocket.Send(str_Reply); // <===== SEND THE REPLY
						
						if (false == bSuccessSending)
							OTLog::vError("server main: Socket ERROR: failed while trying to send reply "
                                          "back to client! \n\n MESSAGE:\n%s\n\nREPLY:\n%s\n\n", 
										  str_Message.c_str(), str_Reply.c_str());
						// --------------------------------------------------
					}
				}
			}
		} //  for
		
		// -----------------------------------------------------------------------
		//
        // IF the time we had available wasn't all used up -- if some of it is still
        // available, then SLEEP until we reach the NEXT PULSE. (In practice, we will 
        // probably use TOO MUCH time, not too little--but then again OT isn't ALWAYS
        // processing a message. There could be plenty of dead time in between...)
        //
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
		// Speeding it up is just a matter of adjusting the above numbers, and LOAD TESTING,
        // to see if OT can handle it. (Not counting optimization of course.)
		//
		// -----------------------------------------------------------------------

		if (pServer->IsFlaggedForShutdown())
		{
			OTLog::Output(0, "main: OT Server is shutting down gracefully....\n");
			break;
		}
        
    } while (1);  // (MAIN LOOP)
    
	// ------------------------------------
    
	return 0;
}


// true  == YES, DISCONNECT m_pSocket, something must have gone wrong.
// false ==  NO, do NOT disconnect m_pSocket, everything went wonderfully!
//
bool ProcessMessage_ZMQ(OTServer & theServer, const std::string & str_Message, std::string & str_Reply)
{
	if (str_Message.size() < 1)
		return false;
	
    const char * szFunc = "ProcessMessage_ZMQ";
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
	
    
    bool bReturnVal = false; // "false" == no, do NOT disconnect. No errors. ("True" means YES, DISCONNECT!)
    
	OTMessage theMsg, theReply; // we'll need these in a sec...
	
//	OTEnvelope theEnvelope(ascMessage);
	OTEnvelope theEnvelope; 
	
	if (false == theEnvelope.SetAsciiArmoredData(ascMessage))
    {
		OTLog::vError("%s: Error retrieving envelope.\n", szFunc);
        bReturnVal = true; // disconnect the socket!
    }
	else
	{	// Now the base64 is decoded and the envelope is in binary form again.
		OTLog::vOutput(2, "%s: Successfully retrieved envelope from ZMQ message...\n", szFunc);
		
		OTString strEnvelopeContents;
		
//		OTString strPubkeyPath("TESTPUBKEY.txt");
//		theServer.GetServerNym().SavePublicKey(strPubkeyPath);
		
		// Decrypt the Envelope.    
		if (false == theEnvelope.Open(theServer.GetServerNym(), strEnvelopeContents)) // now strEnvelopeContents contains the decoded message.
        {
			OTLog::vError("%s: Unable to open envelope.\n", szFunc);
            bReturnVal = true; // disconnect the socket!
        }
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
				OTClientConnection theClient(theServer); 
								
				// By optionally passing in &theClient, the client Nym's public key will be
				// set on it whenever verification is complete. (So for the reply, I'll 
				// have the key and thus I'll be able to encrypt reply to the recipient.)
				if (false == theServer.ProcessUserCommand(theMsg, theReply, &theClient))
				{
                    const OTString s1(theMsg), s2(theReply);
                    
					OTLog::vOutput(0, "%s: Unable to process user command.\n\n ********** "
                                   "REQUEST:\n\n%s\n\n ********** RESPONSE:\n\n%s\n\n", szFunc, s1.Get(), s2.Get());
					
					// NOTE: normally you would even HAVE a true or false if we're in this block. ProcessUserCommand()
					// is what tries to process a command and then sets false if/when it fails. Until that point, you
					// wouldn't get any server reply.  I'm now changing this slightly, so you still get a reply (defaulted
					// to success==false.) That way if a client needs to re-sync his request number, he will get the false
					// and therefore know to resync the # as his next move, vs being stuck with no server reply (and thus
					// stuck with a bad socket.)
					// We sign the reply here, but not in the else block, since it's already signed in cases where 
					// ProcessUserCommand() is a success, by the time that call returns.
					
					theReply.m_bSuccess = false; // Since the process call definitely failed, I'm making sure this here is definitely set to false (even though it probably was already.)
					theReply.SignContract(theServer.GetServerNym());
					theReply.SaveContract();
				}
				else	// At this point the reply is ready to go, and theClient has the public key of the recipient...
					OTLog::vOutput(1, "%s: Successfully processed user command: %s.\n", szFunc, theMsg.m_strCommand.Get());
				
				// -------------------------------------------------
				// The transaction is now processed (or not), and the server's reply message is in theReply.
				// Let's seal it up to the recipient's nym (in an envelope) and send back to the user...
                //
				OTEnvelope theRecipientEnvelope;
				
				bool bSealed = theClient.SealMessageForRecipient(theReply, theRecipientEnvelope);
				
				if (false == bSealed)
                {
					OTLog::vOutput(0, "%s: Unable to seal envelope. (No reply will be sent.)\n", szFunc);
                    bReturnVal = true; // disconnect the socket!
                }
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
            {
				OTLog::vError("%s: Error loading message from envelope contents:\n\n%s\n\n",
							  szFunc, strEnvelopeContents.Get());
                bReturnVal = true; // disconnect the socket!
            }
		}
	}
	// ----------------------------------------------------------------------
	
	str_Reply = resultString;
    
    return bReturnVal;
    
} // ProcessMessage_ZMQ















































