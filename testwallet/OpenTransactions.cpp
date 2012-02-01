/*****************************************************************
 *    
 *  OpenTransactions.cpp  (a high-level API)
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

#include <ctime>

#include <string>
#include <iostream>

#if defined (OT_ZMQ_MODE)
#include <zmq.hpp>
#endif

extern "C" 
{
#ifdef _WIN32
//#include <WinSock.h>
#else
#include <netinet/in.h>
#endif
	
#include "SSL-Example/SFSocket.h"
}


#include "SimpleIni.h"


// -----------------------

#include "OTString.h"

#include "OTStorage.h"

#include "OTPseudonym.h"

#include "OTClient.h"
#include "OTServerConnection.h"
#include "OTServerContract.h"
#include "OTMessage.h"
#include "OTWallet.h"
#include "OTEnvelope.h"
#include "OTCheque.h"
#include "OTPaymentPlan.h"
#include "OTAccount.h"
#include "OTTransaction.h"
#include "OTMint.h"
#include "OTToken.h"
#include "OTPurse.h"
#include "OTLedger.h"
#include "OTLog.h"
#include "OTMessage.h"
#include "OTMessageBuffer.h"
#include "OTBasket.h"
#include "OTOffer.h"
#include "OTTrade.h"
#include "OTMarket.h"

#include "OTSmartContract.h"

#include "OpenTransactions.h"


// used for testing.
OTPseudonym *g_pTemporaryNym=NULL;


extern OT_API g_OT_API; 




// -------------------------------------------------------------------------
// When the server and client (this API being a client) are built in XmlRpc/HTTP
// mode, then a callback must be provided for passing the messages back and forth
// with the server. (Provided below.)
//
// IMPORTANT: If you ever wanted to use a different transport mechanism, it would
// be as easy as adding your own version of this callback function, but having it
// use your own transport mechanism instead of the xmlrpc in this example.
// Of course, the server would also have to support this transport layer...

#if defined(OT_ZMQ_MODE)

// If you build in tcp/ssl mode, this file will build even if you don't have this library.
// But if you build in xml/rpc/http mode, 
//#ifdef _WIN32
//#include "timxmlrpc.h" // XmlRpcC4Win
//#else
//#include "XmlRpc.h"  // xmlrpcpp
//using namespace XmlRpc;
//#endif

// The Callback so OT can give us messages to send using our xmlrpc transport.
// Whenever OT needs to pop a message on over to the server, it calls this so we
// can do the work here.
//
//typedef bool (*OT_CALLBACK_MSG)(OTPayload & thePayload);
//

zmq::context_t	OT_API::s_ZMQ_Context(1);


void OT_API::TransportCallback(OTServerContract & theServerContract, OTEnvelope & theEnvelope)
{	
	int			nServerPort = 0;
	OTString	strServerHostname;
	
	OT_ASSERT_MSG((NULL != g_OT_API.GetClient()) && 
			  (NULL != g_OT_API.GetClient()->m_pConnection) && 
			  (NULL != g_OT_API.GetClient()->m_pConnection->GetNym()), 
				  "OT_API::TransportCallback: Important things are NULL that shouldn't be.");
	
	if (false == theServerContract.GetConnectInfo(strServerHostname, nServerPort))
	{
		OTLog::Error("Failed retrieving connection info from server contract.\n");
		return;
	}
	
	OTASCIIArmor ascEnvelope(theEnvelope);
	
	if (ascEnvelope.Exists())
	{
		//  Prepare our context and socket
		zmq::context_t & context = s_ZMQ_Context;
		zmq::socket_t socket(context, ZMQ_REQ);

		OTString strConnectPath; strConnectPath.Format("tcp://%s:%d", strServerHostname.Get(), nServerPort);
		socket.connect(strConnectPath.Get());

//		OTPayload thePayload;
//		thePayload.SetEnvelope(theEnvelope);
		
		zmq::message_t request(ascEnvelope.GetLength());
		memcpy((void*)request.data(), ascEnvelope.Get(), ascEnvelope.GetLength());
		
		int		nSendTries = 0;
		bool	bSuccessSending = false;
		
		// If failure sending, re-tries 5 times, with 200 ms delay between each. (Maximum of 1 second.)
		//
		while ((nSendTries++ < 5) && (false == (bSuccessSending = socket.send(request, ZMQ_NOBLOCK))))
			OTLog::SleepMilliseconds(200); // todo stop hardcoding. (For now I needed non-blocking so this is much better than before.)
		
		
		// Here's our connection...
		/*
#if defined (linux)
		XmlRpcClient theXmlRpcClient(strServerHostname.Get(), nServerPort, 0); // serverhost, port.
#elif defined (_WIN32) 
		XmlRpcClient theXmlRpcClient(strServerHostname.Get(), nServerPort, "fellowtraveler"); // serverhost, port, value that crashes if NULL.
#else
		XmlRpcClient theXmlRpcClient(strServerHostname.Get(), nServerPort); // serverhost, port.
#endif
		 */
		// -----------------------------------------------------------
		//
		// Call the OT_XML_RPC method (thus passing the message to the server.)
		//
//		XmlRpcValue oneArg, result;		// oneArg contains the outgoing message; result will contain the server reply.
//		oneArg[0] = ascEnvelope.Get();	// Here's where I set the envelope string, as the only argument for the rpc call.
		
//		if (theXmlRpcClient.execute("OT_XML_RPC", oneArg, result)) // The actual call to the server. (Hope my envelope string isn't too long for this...)
		
		if (bSuccessSending)
		{	
			//  Get the reply.
			zmq::message_t reply;
			
			int		nReceiveTries = 0;
			bool	bSuccessReceiving = false;
			
			// If failure receiving, re-tries 25 times, with 200 ms delay between each. (Maximum of 5 seconds.)
			//
			while ((nReceiveTries++ < 25) && (false == (bSuccessReceiving = socket.recv(&reply, ZMQ_NOBLOCK))))
				OTLog::SleepMilliseconds(200); // todo stop hardcoding. (And probably change how I send/receive, but for now I needed non-blocking...)
			
//			std::string str_Result;
//			str_Result.reserve(reply.size());
//			str_Result.append(static_cast<const char *>(reply.data()), reply.size());
			
			if (bSuccessReceiving)
			{
				OTASCIIArmor ascServerReply;
				ascServerReply.MemSet(static_cast<const char*>(reply.data()), reply.size());
			
//				OTPayload theRecvPayload;
//				theRecvPayload.SetPayloadSize(reply.size());			
//				memcpy((void*)theRecvPayload.GetPayloadPointer(), reply.data(), reply.size());
				
				// --------------------------
				
				OTString	strServerReply;
				OTEnvelope theServerEnvelope;
				
				if (theServerEnvelope.SetAsciiArmoredData(ascServerReply))
				{	
					bool bOpened = theServerEnvelope.Open(*(g_OT_API.GetClient()->m_pConnection->GetNym()), strServerReply);
					
					OTMessage * pServerReply = new OTMessage;
					OT_ASSERT_MSG(NULL != pServerReply, "Error allocating memory in the OT API.");

					if (bOpened && strServerReply.Exists() && pServerReply->LoadContractFromString(strServerReply))
					{
						// Now the fully-loaded message object (from the server, this time) can be processed by the OT library...
						g_OT_API.GetClient()->ProcessServerReply(*pServerReply); // the Client takes ownership and will handle cleanup.
					}
					else
					{
						delete pServerReply;
						pServerReply = NULL;
						OTLog::Error("Error loading server reply from string after call to 'OT_API::TransportCallback'\n");
					}
				}
			}
			else
			{
				OTLog::Error("Failed trying to receive message from server.\n");
			}					
		}
		else
		{
			OTLog::Error("Failed trying to send message to server.\n");
		}
	}
}

#endif  // (OT_ZMQ_MODE)
// -------------------------------------------------------------------------




// The API begins here...


OT_API::OT_API() : m_pWallet(NULL), m_pClient(NULL), m_bInitialized(false), 
	m_pstrStoragePath(NULL), m_pstrWalletFilename(NULL)
{

}

OT_API::~OT_API()
{
	if (NULL != m_pWallet)
		delete m_pWallet;
	if (NULL != m_pClient)
		delete m_pClient;
	if (NULL != m_pstrStoragePath)
		delete m_pstrStoragePath;
	if (NULL != m_pstrWalletFilename)
		delete m_pstrWalletFilename;
	
	m_pWallet = NULL;
	m_pClient = NULL;
	
	m_pstrStoragePath		= NULL;
	m_pstrWalletFilename	= NULL;
}


// Load the configuration file.
// 
bool OT_API::LoadConfigFile(const OTString & strMainPath)
{	
	OTString strFilepath;
	strFilepath.Format("%s%s%s%s%s", OTLog::Path(), OTLog::PathSeparator(), "..", 
                       OTLog::PathSeparator(), "client.cfg"); // todo: stop hardcoding.
	
	{        
		CSimpleIniA ini; // We're assuming this file is on the path.
		SI_Error rc = ini.LoadFile(strFilepath.Get());  
		
		if (rc >=0)
		{	
            // ---------------------------------------------
            // LOGFILE
            {
                // Read a value from file: (category,	key )
                const char * pVal1 = ini.GetValue("logging", "logfile_path"); // todo stop hardcoding.
                
                if (NULL != pVal1)
                {
                    OTString strOutput;
                    
                    OTLog::TransformFilePath(pVal1, strOutput);
                    
                    if (strOutput.Exists())
                    {
                        OTLog::vOutput(1, "Setting logfile: %s\n", strOutput.Get());
                        OTLog::SetLogfile(strOutput.Get());
                    }
                }
                else
                    OTLog::vOutput(1, "Current logfile is: %s\n", OTLog::Logfile());
                // ---------------------------------------------
                // LOG LEVEL
                //
                const char * pVal2 = ini.GetValue("logging", "log_level"); // todo stop hardcoding.
                
                if (NULL != pVal2)
                {
                    OTLog::vOutput(1, "Setting log level: %d\n", atoi(pVal2));
                    OTLog::SetLogLevel(atoi(pVal2));
                }
                else
                    OTLog::vOutput(1, "Current log level is: %d\n", OTLog::GetLogLevel());
            }
            // ---------------------------------------------
            // LATENCY 
			{
                const char * pVal = ini.GetValue("latency", "blocking");
                
                if (NULL != pVal)
                {
					const OTString strBlocking(pVal);
					const bool bBlocking = strBlocking.Compare("true") ? true : false;
					
                    OTLog::vOutput(0, "Setting latency blocking: %s\n",
								   bBlocking ? "true" : "false");
                    OTLog::SetBlocking(bBlocking);
                }
            }
            // ------------------------------------------------
            // LATENCY (SENDING)
            {
                const char * pVal = ini.GetValue("latency", "send_delay_after");
                
                if ((NULL != pVal) && (atoi(pVal)))
                {
                    OTLog::vOutput(1, "Setting latency send_delay_after: %d\n", atoi(pVal));
                    OTLog::SetLatencyDelayAfter(atoi(pVal));
                }
            }
            {
                const char * pVal = ini.GetValue("latency", "send_fail_no_tries");
                
                if ((NULL != pVal) && (atoi(pVal)))
                {
                    OTLog::vOutput(1, "Setting latency send_fail_no_tries: %d\n", atoi(pVal));
                    OTLog::SetLatencySendNoTries(atoi(pVal));
                }
            }
            {
                const char * pVal = ini.GetValue("latency", "send_fail_max_ms");
                
                if ((NULL != pVal) && (atoi(pVal)))
                {
                    OTLog::vOutput(1, "Setting latency send_fail_max_ms: %d\n", atoi(pVal));
                    OTLog::SetLatencySendMs(atoi(pVal));
                }
            }
            // ------------------------------------------------
            // LATENCY (RECEIVING)
            {
                const char * pVal = ini.GetValue("latency", "recv_fail_no_tries");
                
                if ((NULL != pVal) && (atoi(pVal)))
                {
                    OTLog::vOutput(1, "Setting latency recv_fail_no_tries: %d\n", atoi(pVal));                    
                    OTLog::SetLatencyReceiveNoTries(atoi(pVal));
                }
            }
            {
                const char * pVal = ini.GetValue("latency", "recv_fail_max_ms");
                
                if ((NULL != pVal) && (atoi(pVal)))
                {
                    OTLog::vOutput(1, "Setting latency recv_fail_max_ms: %d\n", atoi(pVal));
                    OTLog::SetLatencyReceiveMs(atoi(pVal));
                }
            }
            // ----------------------------------------------------------------
		}
        else
            OTLog::vError("Failed loading the ini file: %s\n", strFilepath.Get());
	}
	
	return true;
}




// Call this once per run of the software. Static.
// TODO: add a boolean variable to enforce this, and then
// just call it from the above function.  Currently this only
// even works because the below function is empty, and there
// may be Windows problems in the TCP version for the API builds.
// (No big deal -- none of them will use TCP anyway...)
//
bool OT_API::InitOTAPI()
{
#ifdef _WIN32
	WSADATA wsaData;
	WORD wVersionRequested = MAKEWORD( 2, 2 );
	int err = WSAStartup( wVersionRequested, &wsaData );
#endif
	
	// TODO: probably put all the OpenSSL init stuff here now. We'll see.
	
	// TODO in the case of Windows, figure err into this return val somehow.
	return true;
}



// Call this once per instance of OT_API.
bool OT_API::Init(OTString & strClientPath)
{
	// TODO: Main path needs to be stored in OT_API global, not OTLog static.
	//		 This way, you can have multiple instances of OT_API,
	//		 Each with their own main path. This is necessary.
	//		 Now that the OT_API class exists might be time to take
	//       folders away from OTLog and move it all over. Ugh.
	// OR!! Maybe just code a mechanism so OTLog tracks the instances of OT_API.
	
	OT_ASSERT_MSG(strClientPath.Exists(), "OT_API::Init: Empty path passed in.");
	
	if (true == m_bInitialized)
	{
		OTLog::vError("OT_API::Init: OTAPI was already initialized. (Skipping.) Ignoring path %s because already using path: %s\n", 
					  strClientPath.Get(), GetStoragePath());
		return true;
	}
//	OT_ASSERT_MSG(false == m_bInitialized, "OTAPI was already initialized, please do not call it twice.");
    // ---------------------------------------
	
    OTString strPATH_OUTPUT;
    
    OTLog::TransformFilePath(strClientPath.Get(), strPATH_OUTPUT);
    
//	OTLog::vError("**** OT_API::Init: strClientPath: %s   strPATH_OUTPUT: %s \n",
//				  strClientPath.Get(), strPATH_OUTPUT.Get());
	/*
	 ****	OT_API::Init:	
	 strClientPath:		/Users/au/Library/Application Support/.ot/client_data
	 strPATH_OUTPUT:	/Users/au/Library/Application 
	 */
	
	
	// At some point, remove this, since each instance of OT API should eventually store its OWN path.
	OTLog::SetMainPath(strPATH_OUTPUT.Get()); // This currently does NOT support multiple instances of OT_API.  :-(
	// -------------------------------------
	
	static bool bConstruct = false;
	
	if (false == bConstruct)
	{
		bConstruct = true;
		// ----------------------------
		m_pWallet = new OTWallet;
		m_pClient = new OTClient;
		
		m_pstrStoragePath		= new OTString;
		m_pstrWalletFilename	= new OTString;

		OT_ASSERT_MSG(NULL != m_pWallet, "Error allocating memory for m_pWallet in OT_API::Init");
		OT_ASSERT_MSG(NULL != m_pClient, "Error allocating memory for m_pClient in OT_API::Init");
		OT_ASSERT_MSG(NULL != m_pstrStoragePath, "Error allocating memory for m_pstrStoragePath in OT_API::Init");
		OT_ASSERT_MSG(NULL != m_pstrWalletFilename, "Error allocating memory for m_pstrWalletFilename in OT_API::Init");
		// ----------------------------		
		LoadConfigFile(strPATH_OUTPUT);
	}
	
	// Keep this though.
	SetStoragePath(strPATH_OUTPUT); // sets m_pstrStoragePath

	// -------------------------------------
	std::string strPath = strPATH_OUTPUT.Get();

	// This way, everywhere else I can use the default storage context (for now) and it will work
	// everywhere I put it. (Because it's now set up...)
	//
	const bool bDefaultStore = OTDB::InitDefaultStorage(OTDB_DEFAULT_STORAGE, OTDB_DEFAULT_PACKER, strPath); // notice no wallet filename is passed here... InitDefaultStorage() will thus get called again...
	
	if (bDefaultStore) // success initializing default storage on OTDB.
	{
		OTLog::vOutput(1, "OT_API::Init: Success invoking OTDB::InitDefaultStorage with path: %s\n",
					   strPath.c_str());
		
		if (m_bInitialized)
			OTLog::Output(1, "OT_API::Init: m_pClient->InitClient() was already initialized. (Skipping.)\n");
		else
		{
			m_bInitialized = m_pClient->InitClient(*m_pWallet);
			// -----------------------------
			if (m_bInitialized)
				OTLog::Output(1, "OT_API::Init: Success invoking m_pClient->InitClient()\n");
			else
				OTLog::vError("OT_API::Init: Failed invoking m_pClient->InitClient() with path: %s \n", 
							  strPATH_OUTPUT.Get());
		}
		return m_bInitialized;
	}
	else
		OTLog::vError("OT_API::Init: Failed invoking OTDB::InitDefaultStorage with path: %s\n", strPath.c_str());

	// -------------------------------------
	
	return false;
}



// "wallet.xml" (path set above.)
bool OT_API::LoadWallet(const OTString & strFilename)
{
	OT_ASSERT_MSG(m_bInitialized, "Not initialized; call OT_API::Init first.");
	OT_ASSERT(strFilename.Exists());
	OT_ASSERT(NULL != m_pWallet);
	
	// ----------------------------
	// Grab the old name for safe keeping..
	//
	const char * szOldFilename = GetWalletFilename();
	
	const OTString strOldName((NULL == szOldFilename) 
							  ? 
							  "wallet.xml" // todo stop hardcoding this DEFAULT VALUE.
							  : szOldFilename);
	// ----------------------------
	// set to new name.
	//
	SetWalletFilename(strFilename); 
	// ------------------------------------------
	bool bSuccess = false;

	const char * pstrStoragePath	= GetStoragePath();
	const char * pstrWalletFilename	= GetWalletFilename();
	
	if (NULL == pstrStoragePath)
		OTLog::Error("OT_API::LoadWallet: StoragePath is NULL. Have you called OT_API_Init() yet?\n");
	else if (NULL == pstrWalletFilename || !strFilename.Exists())
		OTLog::Error("OT_API::LoadWallet: WalletFilename is NULL or otherwise nonexistent.\n");
	// ------------------------------------------
	else // NAMES ARE IN ORDER, so let's INIT DEFAULT STORAGE...
	{
		std::string strDataFolderPath(pstrStoragePath);
		std::string strWalletFilename(pstrWalletFilename);
		
		// This way, everywhere else I can use the default storage context (for now) and it will work
		// everywhere I put it. (Because it's now set up...)
		bool bSuccessInitDefault = OTDB::InitDefaultStorage(OTDB_DEFAULT_STORAGE, OTDB_DEFAULT_PACKER, strDataFolderPath, strWalletFilename);

		if (!bSuccessInitDefault)
			OTLog::vError("OT_API::Init: Failed invoking OTDB::InitDefaultStorage with path: %s and wallet filename: %s\n",
						  strDataFolderPath.c_str(), strWalletFilename.c_str());
		// ------------------------------------------
		else // Success initializing default storage.
		{
			bSuccess = m_pWallet->LoadWallet(GetWalletFilename());
			
			if (false == bSuccess)
				OTLog::vError("OT_API::LoadWallet: Failed invoking m_pWallet->LoadWallet() with filename: %s\n", 
							  GetWalletFilename());
			else // success
				OTLog::vOutput(1, "OT_API::LoadWallet: Success invoking m_pWallet->LoadWallet() with filename: %s\n", 
							   GetWalletFilename());
		}
	}
	// ------------------------------------------
	// SET THE OLD NAME BACK, IF FAILURE.
	//
	if (false == bSuccess)
	{
		OTLog::vError("OT_API::LoadWallet: Failed with filename: %s\n", 
					  GetWalletFilename());
		SetWalletFilename(strOldName);  // However we failed, set back to old filename.
	}
	// ------------------------------------------
	
	return bSuccess;
}


// *************************************************************************


int OT_API::GetNymCount()
{
	const char * szFunc = "OT_API::GetNymCount";
	// -------------------------
	OTWallet * pWallet = GetWallet(szFunc); // This logs and ASSERTs already.
	// -------------------------
	if (NULL != pWallet)
		return pWallet->GetNymCount();
	
	return 0;
}

int OT_API::GetServerCount()
{
	const char * szFunc = "OT_API::GetServerCount";
	// -------------------------
	OTWallet * pWallet = GetWallet(szFunc); // This logs and ASSERTs already.
	// -------------------------
	if (NULL != pWallet)
		return pWallet->GetServerCount();
	
	return 0;
}

int OT_API::GetAssetTypeCount()
{
	const char * szFunc = "OT_API::GetAssetTypeCount";
	// -------------------------
	OTWallet * pWallet = GetWallet(szFunc); // This logs and ASSERTs already.
	// -------------------------
	if (NULL != pWallet)
		return pWallet->GetAssetTypeCount();
	
	return 0;
}

int OT_API::GetAccountCount()
{
	const char * szFunc = "OT_API::GetAccountCount";
	// -------------------------
	OTWallet * pWallet = GetWallet(szFunc); // This logs and ASSERTs already.
	// -------------------------
	if (NULL != pWallet)
		return pWallet->GetAccountCount();
	
	return 0;
}

// *************************************************************************

bool OT_API::GetNym(int iIndex, OTIdentifier & NYM_ID, OTString & NYM_NAME)
{
	const char * szFunc = "OT_API::GetNym";
	// -------------------------
	OTWallet * pWallet = GetWallet(szFunc); // This logs and ASSERTs already.
	// -------------------------
	if (NULL != pWallet)
		return pWallet->GetNym(iIndex, NYM_ID, NYM_NAME);
	
	return false;
}

bool OT_API::GetServer(int iIndex, OTIdentifier & THE_ID, OTString & THE_NAME)
{
	const char * szFunc = "OT_API::GetServer";
	// -------------------------
	OTWallet * pWallet = GetWallet(szFunc); // This logs and ASSERTs already.
	// -------------------------
	if (NULL != pWallet)
		return pWallet->GetServer(iIndex, THE_ID, THE_NAME);

	return false;
}

bool OT_API::GetAssetType(int iIndex, OTIdentifier & THE_ID, OTString & THE_NAME)
{
	const char * szFunc = "OT_API::GetAssetType";
	// -------------------------
	OTWallet * pWallet = GetWallet(szFunc); // This logs and ASSERTs already.
	// -------------------------
	if (NULL != pWallet)
		return pWallet->GetAssetType(iIndex, THE_ID, THE_NAME);

	return false;
}

bool OT_API::GetAccount(int iIndex, OTIdentifier & THE_ID, OTString & THE_NAME)
{
	const char * szFunc = "OT_API::GetAccount";
	// -------------------------
	OTWallet * pWallet = GetWallet(szFunc); // This logs and ASSERTs already.
	// -------------------------
	if (NULL != pWallet)
		return pWallet->GetAccount(iIndex, THE_ID, THE_NAME);

	return false;
}

// *************************************************************************


OTWallet * OT_API::GetWallet(const char * szFuncName/*=NULL*/)
{	
	// Any function that calls GetWallet() thus asserts here.
	OT_ASSERT_MSG(m_bInitialized, "Not initialized; call OT_API::Init first."); 
	// --------------------------------------------------------------------
	const char * szFunc = (NULL != szFuncName) ? szFuncName : "OT_API::GetWallet";
	// --------------------------------------------------------------------
	OTWallet * pWallet = m_pWallet; // This is where we "get" the wallet.  :P
	// --------------------------------------------------------------------
	if (NULL == pWallet)
		OTLog::vOutput(0, "OT_API::GetWallet %s: -- The Wallet is not loaded.\n",
					   szFunc);
	return pWallet;
}

// *************************************************************************


OTPseudonym * OT_API::GetNym(const OTIdentifier & NYM_ID, const char * szFuncName/*=NULL*/)
{
	// --------------------------------------------------------------------
	const char * szFunc = (NULL != szFuncName) ? szFuncName : "OT_API::GetNym";
	// --------------------------------------------------------------------
	OTWallet * pWallet = GetWallet(szFunc); // This logs and ASSERTs already.
	// --------------------------------------------------------------------
	if (NULL != pWallet)
	{
		OTPseudonym * pNym = pWallet->GetNymByID(NYM_ID);
		if ((NULL == pNym) && (NULL != szFuncName)) // We only log if the caller asked us to.
		{
			const OTString strID(NYM_ID);
			OTLog::vOutput(0, "OT_API::GetNym %s: No Nym found in wallet with ID: %s\n", 
						   szFunc, strID.Get());
		}
		return pNym;
	}
	return NULL;
}

OTServerContract * OT_API::GetServer(const OTIdentifier & THE_ID, const char * szFuncName/*=NULL*/)
{
	// --------------------------------------------------------------------
	const char * szFunc = (NULL != szFuncName) ? szFuncName : "OT_API::GetServer";
	// --------------------------------------------------------------------
	OTWallet * pWallet = GetWallet(szFunc); // This logs and ASSERTs already.
	// --------------------------------------------------------------------
	if (NULL != pWallet)
	{
		OTServerContract * pContract = pWallet->GetServerContract(THE_ID);
		if ((NULL == pContract) && (NULL != szFuncName)) // We only log if the caller asked us to.
		{
			const OTString strID(THE_ID);
			OTLog::vOutput(0, "OT_API::GetServer %s: No server contract found in wallet with ID: %s\n", 
						   szFunc, strID.Get());
		}
		return pContract;
	}
	return NULL;
}

OTAssetContract * OT_API::GetAssetType(const OTIdentifier & THE_ID, const char * szFuncName/*=NULL*/)
{
	// --------------------------------------------------------------------
	const char * szFunc = (NULL != szFuncName) ? szFuncName : "OT_API::GetAssetType";
	// --------------------------------------------------------------------
	OTWallet * pWallet = GetWallet(szFunc); // This logs and ASSERTs already.
	// --------------------------------------------------------------------
	if (NULL != pWallet)
	{
		OTAssetContract * pContract = pWallet->GetAssetContract(THE_ID);
		if ((NULL == pContract) && (NULL != szFuncName)) // We only log if the caller asked us to.
		{
			const OTString strID(THE_ID);
			OTLog::vOutput(0, "OT_API::GetAssetType %s: No asset contract found in wallet with ID: %s\n", 
						   szFunc, strID.Get());
		}
		return pContract;
	}
	return NULL;
}

OTAccount * OT_API::GetAccount(const OTIdentifier & THE_ID, const char * szFuncName/*=NULL*/)	
{
	// --------------------------------------------------------------------
	const char * szFunc = (NULL != szFuncName) ? szFuncName : "OT_API::GetAccount";
	// --------------------------------------------------------------------
	OTWallet * pWallet = GetWallet(szFunc); // This logs and ASSERTs already.
	// --------------------------------------------------------------------
	if (NULL != pWallet)
	{
		OTAccount * pAcct = pWallet->GetAccount(THE_ID);
		if ((NULL == pAcct) && (NULL != szFuncName)) // We only log if the caller asked us to.
		{
			const OTString strID(THE_ID);
			OTLog::vOutput(0, "OT_API::GetAccount %s: No account found in wallet with ID: %s\n", 
						   szFunc, strID.Get());
		}
		return pAcct;
	}
	return NULL;
}

// *************************************************************************



OTPseudonym * OT_API::GetNymByIDPartialMatch(const std::string PARTIAL_ID, const char * szFuncName/*=NULL*/)
{
	// --------------------------------------------------------------------
	const char * szFunc = (NULL != szFuncName) ? szFuncName : "OT_API::GetNymByIDPartialMatch";
	// --------------------------------------------------------------------
	OTWallet * pWallet = GetWallet(szFunc); // This logs and ASSERTs already.
	// --------------------------------------------------------------------
	if (NULL != pWallet)
		return pWallet->GetNymByIDPartialMatch(PARTIAL_ID);
    
	return NULL;
}

OTServerContract * OT_API::GetServerContractPartialMatch(const std::string PARTIAL_ID, const char * szFuncName/*=NULL*/)
{
	// --------------------------------------------------------------------
	const char * szFunc = (NULL != szFuncName) ? szFuncName : "OT_API::GetServerContractPartialMatch";
	// --------------------------------------------------------------------
	OTWallet * pWallet = GetWallet(szFunc); // This logs and ASSERTs already.
	// --------------------------------------------------------------------
	if (NULL != pWallet)
		return pWallet->GetServerContractPartialMatch(PARTIAL_ID);
    
	return NULL;   
}

OTAssetContract * OT_API::GetAssetContractPartialMatch(const std::string PARTIAL_ID, const char * szFuncName/*=NULL*/)
{
	// --------------------------------------------------------------------
	const char * szFunc = (NULL != szFuncName) ? szFuncName : "OT_API::GetAssetContractPartialMatch";
	// --------------------------------------------------------------------
	OTWallet * pWallet = GetWallet(szFunc); // This logs and ASSERTs already.
	// --------------------------------------------------------------------
	if (NULL != pWallet)
		return pWallet->GetAssetContractPartialMatch(PARTIAL_ID);
    
	return NULL; 
}

OTAccount * OT_API::GetAccountPartialMatch(const std::string PARTIAL_ID, const char * szFuncName/*=NULL*/)
{
	// --------------------------------------------------------------------
	const char * szFunc = (NULL != szFuncName) ? szFuncName : "OT_API::GetAccountPartialMatch";
	// --------------------------------------------------------------------
	OTWallet * pWallet = GetWallet(szFunc); // This logs and ASSERTs already.
	// --------------------------------------------------------------------
	if (NULL != pWallet)	
		return pWallet->GetAccountPartialMatch(PARTIAL_ID);
	
	return NULL;
}

// *************************************************************************



// returns a new nym (with key pair) and files created. (Or NULL.)
//
// CALLER is responsible to delete!
//
OTPseudonym * OT_API::CreateNym()
{
	OTPseudonym * pNym = new OTPseudonym;
	OT_ASSERT(NULL != pNym);
	
	if (false == pNym->GenerateNym()) 
	{
		delete pNym;
		return NULL;
	}
	return pNym;
}



// ------------------------------------------------------------------



// The Asset Type's Name is basically just a client-side label.
// This function lets you change it.
//
// Returns success, true or false.
//
bool OT_API::SetAssetType_Name(const OTIdentifier	&	ASSET_ID, 
							   const OTString		&	STR_NEW_NAME) 
{
	const char * szFuncName = "OT_API::SetAssetType_Name";
	// -----------------------------------------------------
	OTWallet * pWallet = this->GetWallet(szFuncName); // This logs and ASSERTs already.
	if (NULL == pWallet) return false;
	// By this point, pWallet is a good pointer.  (No need to cleanup.)
	// -----------------------------------------------------
	OTAssetContract * pContract = this->GetAssetType(ASSET_ID, szFuncName); // This ASSERTs and logs already.
	if (NULL == pContract) return false;
	// By this point, pContract is a good pointer.  (No need to cleanup.)
	// -----------------------------------------------------
	// Might want to put some more data validation on the name?
	if (!STR_NEW_NAME.Exists())
		OTLog::Output(0, "OT_API::SetAssetType_Name: Bad: name is empty.\n");
	else
	{
		pContract->SetName(STR_NEW_NAME);		
		return pWallet->SaveWallet(); // Only 'cause the name is actually stored here.
	}
	return false;
}



// The Server's Name is basically just a client-side label.
// This function lets you change it.
//
// Returns success, true or false.
//
bool OT_API::SetServer_Name(const OTIdentifier	&	SERVER_ID, 
							const OTString		&	STR_NEW_NAME)
{
	const char * szFuncName = "OT_API::SetServer_Name";
	// -----------------------------------------------------
	OTWallet * pWallet = this->GetWallet(szFuncName); // This logs and ASSERTs already.
	if (NULL == pWallet) return false;
	// By this point, pWallet is a good pointer.  (No need to cleanup.)
	// -----------------------------------------------------
	OTServerContract *	pContract = this->GetServer(SERVER_ID, szFuncName); // This ASSERTs and logs already.
	if (NULL == pContract) return false;
	// By this point, pContract is a good pointer.  (No need to cleanup.)
	// -----------------------------------------------------
	// Might want to put some more data validation on the name?
	if (!STR_NEW_NAME.Exists())
		OTLog::Output(0, "OT_API::SetServer_Name: Bad: name is empty.\n");
	else
	{
		pContract->SetName(STR_NEW_NAME);
		return pWallet->SaveWallet(); // Only 'cause the name is actually stored here.
	}
	return false;
}



bool OT_API::IsNym_RegisteredAtServer(const OTIdentifier & NYM_ID, const OTIdentifier & SERVER_ID)
{
	const char * szFuncName = "OT_API::IsNym_RegisteredAtServer";
	// -----------------------------------------------------
	OTPseudonym * pNym = this->GetNym(NYM_ID, szFuncName); // This logs and ASSERTs already.
	if (NULL == pNym) return false;
	// Below this point, pNym is a good ptr, and will be cleaned up automatically.
	// ------------------------------------------------------
	const OTString strServerID(SERVER_ID);
	return pNym->IsRegisteredAtServer(strServerID);
}



// --------------------------------------------------------------------
/** TIME (in seconds, as long)
 
 This will return the current time in seconds, as a long int.
 
 Todo:  consider making this available on the server side as well,
 so the smart contracts can see what time it is. 
 */
long OT_API::GetTime()
{
	const	time_t CURRENT_TIME =	time(NULL);
	long	lTime = CURRENT_TIME;
	return	lTime;
}




// --------------------------------------------------------------------
/** OT-encode a plaintext string.
 
 const char * OT_API_Encode(const char * szPlaintext);
 
 This will pack, compress, and base64-encode a plain string.
 Returns the base64-encoded string, or NULL.
 
 Internally: 
 OTString		strPlain(szPlaintext);
 OTASCIIArmor	ascEncoded(thePlaintext);	// ascEncoded now contains the OT-encoded string.
 return			ascEncoded.Get();			// We return it.
 */
bool OT_API::Encode(const OTString & strPlaintext, OTString & strOutput, bool bLineBreaks/*=true*/)
{
	OTASCIIArmor ascArmor;
	const bool bSuccess = ascArmor.SetString(strPlaintext, bLineBreaks);
	
	if (bSuccess)
	{
		strOutput.Release();
		strOutput = ascArmor.Get();
	}
	return bSuccess;
}





// --------------------------------------------------------------------
/** Decode an OT-encoded string (back to plaintext.)
 
 const char * OT_API_Decode(const char * szEncoded);
 
 This will base64-decode, uncompress, and unpack an OT-encoded string.
 Returns the plaintext string, or NULL.
 
 Internally: 
 OTASCIIArmor	ascEncoded(szEncoded);
 OTString		strPlain(ascEncoded);	// strPlain now contains the decoded plaintext string.
 return			strPlain.Get();			// We return it.
 */
bool OT_API::Decode(const OTString & strEncoded, OTString & strOutput, bool bLineBreaks/*=true*/)
{
	OTASCIIArmor ascArmor;
	ascArmor.Set(strEncoded.Get());
	// -------------------------------
	strOutput.Release();
	const bool bSuccess = ascArmor.GetString(strOutput, bLineBreaks);
	return bSuccess;
}





// --------------------------------------------------------------------
/** OT-ENCRYPT a plaintext string.
 
 const char * OT_API_Encrypt(const char * RECIPIENT_NYM_ID, const char * szPlaintext);
 
 This will encode, ENCRYPT, and encode a plain string.
 Returns the base64-encoded ciphertext, or NULL.
 
 Internally the C++ code is: 
 OTString		strPlain(szPlaintext);
 OTEnvelope		theEnvelope;				
 if (theEnvelope.Seal(RECIPIENT_NYM, strPlain)) {	// Now it's encrypted (in binary form, inside the envelope), to the recipient's nym.
 OTASCIIArmor	ascCiphertext(theEnvelope);		// ascCiphertext now contains the base64-encoded ciphertext (as a string.)
 return ascCiphertext.Get();
 }
 */
bool OT_API::Encrypt(const OTIdentifier & theRecipientNymID, const OTString & strPlaintext, OTString & strOutput)
{
	const char * szFuncName = "OT_API::Encrypt";
	// -----------------------------------------------------
	OTPseudonym * pRecipientNym = this->GetOrLoadNym(theRecipientNymID, szFuncName); // This logs and ASSERTs already.
	if (NULL == pRecipientNym) return false;
	// -----------------------------------------------------
	OTEnvelope	theEnvelope;
	
	if (theEnvelope.Seal(*pRecipientNym, strPlaintext)) 
	{
		OTASCIIArmor	ascCiphertext(theEnvelope);
		strOutput.Release();
		strOutput = ascCiphertext.Get();
		return true;
	}
	return false;
}






// --------------------------------------------------------------------
/** OT-DECRYPT an OT-encrypted string back to plaintext.
 
 const char * OT_API_Decrypt(const char * RECIPIENT_NYM_ID, const char * szCiphertext);
 
 Decrypts the base64-encoded ciphertext back into a normal string plaintext.
 Returns the plaintext string, or NULL.
 
 Internally the C++ code is: 
 OTEnvelope		theEnvelope;					// Here is the envelope object. (The ciphertext IS the data for an OTEnvelope.)
 OTASCIIArmor	ascCiphertext(szCiphertext);	// The base64-encoded ciphertext passed in. Next we'll try to attach it to envelope object...
 if (theEnvelope.SetAsciiArmoredData(ascCiphertext)) {	// ...so that we can open it using the appropriate Nym, into a plain string object:
 OTString	strServerReply;					// This will contain the output when we're done.
 const bool	bOpened =						// Now we try to decrypt:
 theEnvelope.Open(RECIPIENT_NYM, strServerReply);
 if (bOpened) {
 return strServerReply.Get();
 }
 }
 */
bool OT_API::Decrypt(const OTIdentifier & theRecipientNymID, const OTString & strCiphertext, OTString & strOutput)
{
	const char * szFuncName = "OT_API::Decrypt";
	// -----------------------------------------------------
	OTPseudonym * pRecipientNym = this->GetOrLoadPrivateNym(theRecipientNymID, szFuncName); // This logs and ASSERTs already.
	if (NULL == pRecipientNym) return false;
	// -----------------------------------------------------	
	OTEnvelope		theEnvelope;
	OTASCIIArmor	ascCiphertext;
	ascCiphertext.Set(strCiphertext);
	
	if (theEnvelope.SetAsciiArmoredData(ascCiphertext)) 
	{
		strOutput.Release();		
		return theEnvelope.Open(*pRecipientNym, strOutput);
	}
	return false;
}







// --------------------------------------------------------------------
/** OT-Sign a CONTRACT.  (First signature)
 
 const char * OT_API_SignContract(const char * SIGNER_NYM_ID, const char * THE_CONTRACT);
 
 Tries to instantiate the contract object, based on the string passed in.
 Releases all signatures, and then signs the contract.
 Returns the signed contract, or NULL if failure.
 
 NOTE: The actual OT functionality (Use Cases) NEVER requires you to sign via
 this function. Why not? because, anytime a signature is needed on something,
 the relevant OT API call will require you to pass in the Nym, and the API already
 signs internally wherever it deems appropriate. Thus, this function is only for
 advanced uses, for OT-Scripts, server operators, etc.
 */

bool OT_API::SignContract(const OTIdentifier & theSignerNymID, const OTString & strContract, OTString & strOutput)
{
	const char * szFuncName = "OT_API::SignContract";
	// -----------------------------------------------------
	OTPseudonym * pNym = this->GetOrLoadPrivateNym(theSignerNymID, szFuncName); // This logs and ASSERTs already.
	if (NULL == pNym) return false;
	// By this point, pNym is a good pointer, and is on the wallet. (No need to cleanup.)
	// -----------------------------------------------------
	if (!strContract.Exists())
	{
		OTLog::Output(0, "OT_API::SignContract: Empty contract passed in. (Returning false.)\n");
		return false;
	}
	// ------------------------------------------------------------
	//
	OTContract * pContract = NULL;
	OTCleanup<OTContract> theAngel;
	
	if (NULL == pContract)
		pContract = OTTransactionType::TransactionFactory(strContract);
	
	if (NULL == pContract)
		pContract = OTScriptable::InstantiateScriptable(strContract);
	
	if (NULL == pContract)
		pContract = OTContract::InstantiateContract(strContract);
	
	if (NULL == pContract)
	{
		OTLog::vOutput(0, "OT_API::SignContract: I tried my best. Unable to instantiate contract passed in:\n\n%s\n\n",
					   strContract.Get());
		return false;
	}
	// -----------------------------------------------------
	pContract->ReleaseSignatures();
	pContract->SignContract(*pNym);
	pContract->SaveContract();
	// -----------------------------------------------------
	strOutput.Release();
	pContract->SaveContractRaw(strOutput);	
	// -----------------------------------------------------
	return true;		
}





// --------------------------------------------------------------------
/** OT-Sign a CONTRACT.  (Add a signature)
 
 const char * OT_API_AddSignature(const char * SIGNER_NYM_ID, const char * THE_CONTRACT);
 
 Tries to instantiate the contract object, based on the string passed in.
 Signs the contract, without releasing any signatures that are already there.
 Returns the signed contract, or NULL if failure.
 
 NOTE: The actual OT functionality (Use Cases) NEVER requires you to sign via
 this function. Why not? because, anytime a signature is needed on something,
 the relevant OT API call will require you to pass in the Nym, and the API already
 signs internally wherever it deems appropriate. Thus, this function is only for
 advanced uses, for OT-Scripts, server operators, etc.
 */
bool OT_API::AddSignature(const OTIdentifier & theSignerNymID, const OTString & strContract, OTString & strOutput)
{
	const char * szFuncName = "OT_API::AddSignature";
	// -----------------------------------------------------
	OTPseudonym * pNym = this->GetOrLoadPrivateNym(theSignerNymID, szFuncName); // This logs and ASSERTs already.
	if (NULL == pNym) return false;
	// By this point, pNym is a good pointer, and is on the wallet. (No need to cleanup.)
	// -----------------------------------------------------
	if (!strContract.Exists())
	{
		OTLog::Output(0, "OT_API::AddSignature: Empty contract passed in. (Returning false.)\n");
		return false;
	}
	// ------------------------------------------------------------
	//
	OTContract * pContract = NULL;
	OTCleanup<OTContract> theAngel;
	
	if (NULL == pContract)
		pContract = OTTransactionType::TransactionFactory(strContract);
	
	if (NULL == pContract)
		pContract = OTScriptable::InstantiateScriptable(strContract);
	
	if (NULL == pContract)
		pContract = OTContract::InstantiateContract(strContract);
	
	if (NULL == pContract)
	{
		OTLog::vOutput(0, "OT_API::AddSignature: I tried my best. Unable to instantiate contract passed in:\n\n%s\n\n",
					   strContract.Get());
		return false;
	}
	// -----------------------------------------------------
	//	pContract->ReleaseSignatures();		// Other than this line, this function is identical to 
										// OT_API::SignContract(). (It adds signatures without removing existing ones.)
	pContract->SignContract(*pNym);
	pContract->SaveContract();
	// -----------------------------------------------------
	strOutput.Release();
	pContract->SaveContractRaw(strOutput);	
	// -----------------------------------------------------
	return true;
}





// --------------------------------------------------------------------
/** OT-Verify the signature on a CONTRACT.
 Returns true/false (success/fail)
 
 NOTICE that ppContract can be set, EVEN WHEN THIS RETURNS FALSE!
 Therefore, if you are low-level enough to actually be passing ppContract
 in here, then you had better check it, after the call, whether it returns
 success or fail! Either way, that pointer could be set, in which case YOU
 are responsible to clean it up! Check that pointer for NULL!
 */
bool OT_API::VerifySignature(const OTString		& strContract,
							 const OTIdentifier	& theSignerNymID,
							 OTContract			**ppContract/*=NULL*/) // If you use this optional parameter, then YOU are responsible to clean it up.
{
	const char * szFuncName = "OT_API::VerifySignature";
	// -----------------------------------------------------
	OTPseudonym * pNym = this->GetOrLoadNym(theSignerNymID, szFuncName); // This logs and ASSERTs already.
	if (NULL == pNym) return false;
	// By this point, pNym is a good pointer, and is on the wallet. (No need to cleanup.)
	// -----------------------------------------------------
	if (!strContract.Exists())
	{
		OTLog::Output(0, "OT_API::VerifySignature: Empty contract passed in. (Returning false.)\n");
		return false;
	}
	// ------------------------------------------------------------
	//
	OTContract * pContract = NULL;
	OTCleanup<OTContract> theAngel;
	
	if (NULL == pContract)
		pContract = OTTransactionType::TransactionFactory(strContract);

	if (NULL == pContract)
		pContract = OTScriptable::InstantiateScriptable(strContract);

	if (NULL == pContract)
		pContract = OTContract::InstantiateContract(strContract);
	
	if (NULL == pContract)
	{
		OTLog::vOutput(0, "OT_API::VerifySignature: I tried my best. Unable to instantiate contract passed in:\n\n%s\n\n",
					   strContract.Get());
		return false;
	}
	// -----------------------------------------------------
	// Since we created it ourselves using a factory, we can do this:
	
	// -----------------------------------------------------
	// The caller wants to take the contract for himself, without us cleaning 
	// it up in here.
	//
	if (NULL != ppContract)
		*ppContract = pContract;
	// Else, we will clean it up ourselves...
	else
		theAngel.SetCleanupTargetPointer(pContract);
	// -----------------------------------------------------
	if (false == pContract->VerifyContractID())
//	if (false == pContract->VerifyContract())	// This calls VerifyContractID(), then GetContractPublicNym(), then VerifySignature() (with that Nym)
	{											// Therefore it's only useful for server contracts and asset contracts. Here we can VerifyID and Signature,
												// and that's good enough for here and most other places, generically speaking.
		OTLog::vOutput(0, "OT_API::VerifySignature: Unable to verify contract ID for contract passed in. NOTE: If you are experiencing "
					   "a problem here, CONTACT FELLOW TRAVELER and let him know WHAT KIND OF CONTRACT, and what symptoms you are seeing, "
					   "versus what you were expecting to see. Contract contents:\n\n%s\n\n",
					   strContract.Get());
		return false;
	}

	// -----------------------------------------------------
	if (false == pContract->VerifySignature(*pNym))
	{
		OTString strSignerNymID(theSignerNymID);
		OTLog::vOutput(0, "OT_API::VerifySignature: For Nym (%s), unable to verify signature on contract passed in:\n\n%s\n\n",
					   strSignerNymID.Get(), strContract.Get());
		return false;
	}
	// -----------------------------------------------------
	
	return true;	
}


// --------------------------------------------------
// Verify and Retrieve XML Contents.
//
// Pass in a contract and a user ID, and this function will:
// -- Load the contract up and verify it.
// -- Verify the user's signature on it.
// -- Remove the PGP-style bookends (the signatures, etc)
// -- Output: the XML contents of the contract in string form. 
// -- Returns: bool. (success/fail)
//
bool OT_API::VerifyAndRetrieveXMLContents(const OTString		&	strContract,
										  const OTIdentifier	&	theSignerNymID,
										  // ---------------------
										  OTString				&	strOutput)
{
	OTContract * pContract = NULL;
	const bool bSuccess = this->VerifySignature(strContract, theSignerNymID, &pContract);
	//
	// If pContract is not NULL after the above call, then this Cleanup object
	// will clean it up after we leave the scope of this block.
	//
	OTCleanup<OTContract> theAngel(pContract); 
	// -----------------------------------------------------
	strOutput.Release();
	
	if (NULL != pContract) // pContract will always exist, if we were successful.
		return (bSuccess && pContract->SaveContractRaw(strOutput));
	
	return bSuccess; // In practice this will only happen on failure. (Could have put "return false".)
}



/// === Verify Account Receipt ===
/// Returns bool. Verifies any asset account (intermediary files) against its own last signed receipt.
/// Obviously this will fail for any new account that hasn't done any transactions yet (and thus has no receipts.)
///
///
bool OT_API::VerifyAccountReceipt(const OTIdentifier & SERVER_ID,
								  const OTIdentifier & USER_ID,
								  const OTIdentifier & ACCOUNT_ID)
{
	const char * szFuncName = "OT_API::VerifyAccountReceipt";
	// -----------------------------------------------------
	OTPseudonym * pNym = this->GetOrLoadPrivateNym(USER_ID, szFuncName); // These copiously log, and ASSERT.
	if (NULL == pNym) return false;
	// By this point, pNym is a good pointer, and is on the wallet. (No need to cleanup.)
	// -----------------------------------------------------
	OTServerContract *	pServer = this->GetServer(SERVER_ID, szFuncName); // This ASSERTs and logs already.
	if (NULL == pServer) return false;
	// By this point, pServer is a good pointer.  (No need to cleanup.)
	// -----------------------------------------------------
	OTPseudonym * pServerNym = const_cast<OTPseudonym *>(pServer->GetContractPublicNym());
	if (NULL == pServerNym) { OTLog::Error("OT_API::VerifyAccountReceipt: should never happen. pServerNym is NULL.\n"); return false; }
	// -----------------------------------------------------
	return OTTransaction::VerifyBalanceReceipt(*pServerNym,
											   *pNym,
											   SERVER_ID,
											   ACCOUNT_ID);
}






bool OT_API::Create_SmartContract(const OTIdentifier & SERVER_ID,
								  const OTIdentifier & SIGNER_NYM_ID,// Use any Nym you wish here. (The signing at this point is only to cause a save.)
								  // ----------------------------------------
								  time_t		VALID_FROM,	// Default (0 or NULL) == NOW
								  time_t		VALID_TO,	// Default (0 or NULL) == no expiry / cancel anytime
								  OTString & strOutput)
{
	const char * szFuncName = "OT_API::Create_SmartContract";
	// -----------------------------------------------------
	OTPseudonym * pNym = this->GetOrLoadPrivateNym(SIGNER_NYM_ID, szFuncName); // These copiously log, and ASSERT.
	if (NULL == pNym) return false;
	// By this point, pNym is a good pointer, and is on the wallet. (No need to cleanup.)
	// -----------------------------------------------------
	OTSmartContract * pContract = new OTSmartContract(SERVER_ID);
	OT_ASSERT_MSG(NULL != pContract, "OT_API::Create_SmartContract: ASSERT while trying to instantiate blank smart contract.\n");
	// --------------------------------	
	if (false == pContract->SetDateRange(VALID_FROM,  VALID_TO))
	{
		OTLog::vOutput(0, "OT_API::Create_SmartContract: Failed trying to set date range.\n");
		return false;
	}
	// -----------------------------------------------------
	pContract->SignContract(*pNym);
	pContract->SaveContract();
	// -----------------------------------------------------
	strOutput.Release();
	// -----------------------------------------------------
	pContract->SaveContractRaw(strOutput);
	// -----------------------------------------------------
	return true;
}




bool OT_API::SmartContract_AddParty(const	OTString		& THE_CONTRACT,		// The contract, about to have the bylaw added to it.
									const	OTIdentifier	& SIGNER_NYM_ID,	// Use any Nym you wish here. (The signing at this point is only to cause a save.)
									// ----------------------------------------
									const	OTString		& PARTY_NAME,		// The Party's NAME as referenced in the smart contract. (And the scripts...)
									const	OTString		& AGENT_NAME,		// An AGENT will be added by default for this party. Need Agent NAME.
											OTString		& strOutput)
{
	const char * szFuncName		= "OT_API::SmartContract_AddParty";
	// -----------------------------------------------------
	OTPseudonym * pNym = this->GetOrLoadPrivateNym(SIGNER_NYM_ID, szFuncName); // These copiously log, and ASSERT.
	if (NULL == pNym) return false;
	// By this point, pNym is a good pointer, and is on the wallet. (No need to cleanup.)
	// -----------------------------------------------------	
	OTScriptable * pContract = OTScriptable::InstantiateScriptable(THE_CONTRACT);
	OTCleanup<OTScriptable> theContractAngel;
	if (NULL == pContract)
	{
		OTLog::vOutput(0, "OT_API::SmartContract_AddParty: Error loading smart contract:\n\n%s\n\n",
					   THE_CONTRACT.Get());
		return false;
	}
	else
		theContractAngel.SetCleanupTarget(*pContract);  // Auto-cleanup.
	// -----------------------------------------------------
	const std::string str_party_name(PARTY_NAME.Get()), str_agent_name(AGENT_NAME.Get());
	
	OTParty * pParty = pContract->GetParty(str_party_name);
	
	if (NULL != pParty)
	{
		OTLog::Output(0, "OT_API::SmartContract_AddParty: Failure: Party already exists. \n");
		return false;
	}
	// -------------------------------

	pParty = new OTParty(str_party_name.c_str(), true /*bIsOwnerNym*/, 
						 NULL/*OwnerID not set until confirm*/, str_agent_name.c_str(),
						 true); //bCreateAgent=false by default.
	OT_ASSERT(NULL != pParty);
	
	if (false == pContract->AddParty(*pParty)) // takes ownership.
	{
		OTLog::vOutput(0, "OT_API_SmartContract_AddParty: Failed while trying to add party: %s \n",
					   PARTY_NAME.Get());
		delete pParty; pParty=NULL;
		return false;
	}
	// ------------------
	// Success!
	//
	pContract->ReleaseSignatures();
	pContract->SignContract(*pNym);
	pContract->SaveContract();
	// ------------------
	strOutput.Release();
	pContract->SaveContractRaw(strOutput);
	// ------------------
	return true;	
}



bool OT_API::SmartContract_AddAccount(const	OTString		& THE_CONTRACT,		// The contract, about to have the clause added to it.
									  const	OTIdentifier	& SIGNER_NYM_ID,	// Use any Nym you wish here. (The signing at this point is only to cause a save.)
									  // ----------------------------------------
									  const	OTString		& PARTY_NAME,		// The Party's NAME as referenced in the smart contract. (And the scripts...)
									  // ----------------------------------------
									  const	OTString		& ACCT_NAME,		// The Account's name as referenced in the smart contract
									  const	OTString		& ASSET_TYPE_ID,	// Asset Type ID for the Account.
											OTString		& strOutput)
{
	const char * szFuncName		= "OT_API::SmartContract_AddAccount";
	// -----------------------------------------------------
	OTPseudonym * pNym = this->GetOrLoadPrivateNym(SIGNER_NYM_ID, szFuncName); // These copiously log, and ASSERT.
	if (NULL == pNym) return false;
	// By this point, pNym is a good pointer, and is on the wallet. (No need to cleanup.)
	// -----------------------------------------------------	
	OTScriptable * pContract = OTScriptable::InstantiateScriptable(THE_CONTRACT);
	OTCleanup<OTScriptable> theContractAngel;
	if (NULL == pContract)
	{
		OTLog::vOutput(0, "OT_API::SmartContract_AddAccount: Error loading smart contract:\n\n%s\n\n",
					   THE_CONTRACT.Get());
		return false;
	}
	else
		theContractAngel.SetCleanupTarget(*pContract);  // Auto-cleanup.
	// -----------------------------------------------------
	const std::string str_party_name(PARTY_NAME.Get());
	
	OTParty * pParty = pContract->GetParty(str_party_name);
	
	if (NULL == pParty)
	{
		OTLog::Output(0, "OT_API::SmartContract_AddAccount: Failure: Party doesn't exist. \n");
		return false;
	}
	// -------------------------------
	const std::string str_name(ACCT_NAME.Get()), str_asset_id(ASSET_TYPE_ID.Get());

	if (NULL != pParty->GetAccount(str_name))
	{
		OTLog::vOutput(0, "OT_API::SmartContract_AddAccount: Failed adding: account is already there with that name (%s) on party: %s \n",
					   str_name.c_str(), str_party_name.c_str());
		return false;
	}
	// ---------------------------------------------
	const OTString strAgentName, strAcctName(str_name.c_str()), strAcctID, strAssetTypeID(str_asset_id.c_str());
	
	if (false == pParty->AddAccount(strAgentName, strAcctName, strAcctID, strAssetTypeID, 0))
	{
		OTLog::vOutput(0, "OT_API::SmartContract_AddAccount: Failed trying to add account (%s) to party: %s \n",
					   str_name.c_str(), str_party_name.c_str());
		return false;
	}
	// -------------------------------
	// Success!
	//
	pContract->ReleaseSignatures();
	pContract->SignContract(*pNym);
	pContract->SaveContract();
	// ------------------
	strOutput.Release();
	pContract->SaveContractRaw(strOutput);
	// ------------------
	return true;	
}




int OT_API::SmartContract_CountNumsNeeded(const	OTString	& THE_CONTRACT,		// The contract, about to have the bylaw added to it.
										  const	OTString	& AGENT_NAME)		// An AGENT will be added by default for this party. Need Agent NAME.
{
	int nReturnValue = 0;
	const std::string	str_agent_name(AGENT_NAME.Get());
	// ----------------------------------------------------
	OTScriptable * pContract = OTScriptable::InstantiateScriptable(THE_CONTRACT);
	OTCleanup<OTScriptable> theContractAngel;
	
	if (NULL == pContract)
	{
		OTLog::Output(0, "OT_API::SmartContract_CountNumsNeeded: Error loading smart contract. \n");
		return nReturnValue;
	}
	else
		theContractAngel.SetCleanupTarget(*pContract);  // Auto-cleanup.
	// -----------------------------------------------------
	// -- nReturnValue starts as 0.
	// -- If agent is authorizing agent for a party, nReturnValue++. (Opening number.)
	// -- If agent is authorized agent for any of party's accts, nReturnValue++ for each. (Closing numbers.)
	//
	// (Then return the count.)
	
	nReturnValue = pContract->GetCountTransNumsNeededForAgent(str_agent_name);
	// ----------------------------------------------------
	return nReturnValue;
}





bool OT_API::SmartContract_ConfirmAccount(const	OTString	& THE_CONTRACT,	
										  const	OTIdentifier& SIGNER_NYM_ID,
												// -----------------------------
										  const	OTString	& PARTY_NAME,	
										  const	OTString	& ACCT_NAME,	
												// -----------------------------
										  const	OTString	& AGENT_NAME,
										  const	OTString	& ACCT_ID,
												OTString	& strOutput)
{
	const char * szFuncName		= "OT_API::SmartContract_ConfirmAccount";
	// -----------------------------------------------------
	OTPseudonym * pNym = this->GetOrLoadPrivateNym(SIGNER_NYM_ID, szFuncName); // These copiously log, and ASSERT.
	if (NULL == pNym) return false;
	// By this point, pNym is a good pointer, and is on the wallet. (No need to cleanup.)
	// -----------------------------------------------------
	const OTIdentifier theAcctID(ACCT_ID);
	OTAccount * pAccount = this->GetAccount(theAcctID, szFuncName);
	if (NULL == pAccount) return false;
	// By this point, pAccount is a good pointer, and is on the wallet. (No need to cleanup.)
	// -----------------------------------------------------			
	OTScriptable * pContract = OTScriptable::InstantiateScriptable(THE_CONTRACT);
	OTCleanup<OTScriptable> theContractAngel;
	
	if (NULL == pContract)
	{
		OTLog::vOutput(0, "OT_API::SmartContract_ConfirmAccount: Error loading smart contract:\n\n%s\n\n",
					   THE_CONTRACT.Get());
		return false;
	}
	else
		theContractAngel.SetCleanupTarget(*pContract);  // Auto-cleanup.
	// -----------------------------------------------------
	const std::string str_party_name(PARTY_NAME.Get());
	OTParty * pParty = pContract->GetParty(str_party_name);
	if (NULL == pParty)
	{
		OTLog::vOutput(0, "OT_API::SmartContract_ConfirmAccount: Failure: Party doesn't exist: %s \n",
					   PARTY_NAME.Get());
		return false;
	}
	// ---------------------------------------------
	// Make sure there's not already an account here with the same ID (Server disallows.)
	//
	OTPartyAccount * pDupeAcct = pParty->GetAccountByID(theAcctID);
	if (NULL != pDupeAcct) // It's already there.
	{
		OTLog::vOutput(0, "OT_API::SmartContract_ConfirmAccount: Failed, since a duplicate account ID (%s) "
					   "was already found on this contract. (Server disallows, sorry.)\n", ACCT_ID.Get());
		return false;
	}
	// ---------------------------------------------
	// Make sure there's not already an account here with the same ID (Server disallows.)
	//
	const std::string str_name(ACCT_NAME.Get());

	OTPartyAccount * pPartyAcct = pParty->GetAccount(str_name);
	if (NULL == pPartyAcct) // It's not already there. (Though it should be...)
	{
		OTLog::vOutput(0, "OT_API::SmartContract_ConfirmAccount: Failed: No Account found on contract with name: %s \n",
					   str_name.c_str());
		return false;
	}
	// ---------------------------------------------
	// the actual asset type ID
	
	const OTIdentifier	theExpectedAssetTypeID(pPartyAcct->GetAssetTypeID());	// The expected asset type ID, converting from a string.
	const OTIdentifier&	theActualAssetTypeID = pAccount->GetAssetTypeID();		// the actual asset type ID, already an identifier, from the actual account.
	
	if (theExpectedAssetTypeID != theActualAssetTypeID)
	{
		const OTString strAssetTypeID(theActualAssetTypeID);
		OTLog::vOutput(0, "OT_API::SmartContract_ConfirmAccount: Failed, since the asset type ID of the account (%s) "
					   "does not match what was expected (%s) according to this contract.\n",
					   strAssetTypeID.Get(), pPartyAcct->GetAssetTypeID().Get());
		return false;
	}
	// ---------------------------------------------
	// I'm leaving this here for now, since a party can only be a Nym for now anyway (until I code entities.)
	// Therefore this account COULD ONLY be owned by that Nym anyway, and thus will pass this test.
	// All the above functions aren't that stringent because they are about designing the smart contract, not
	// executing it. But in THIS case, we are actually confirming the thing, and adding our actual account #s
	// to it, signing it, etc, so I might as well save the person the hassle of being rejected later because
	// he accidentally set it up with the wrong Nym.
	//
	if (false == pAccount->VerifyOwner(*pNym))
	{
		const OTString strNymID(SIGNER_NYM_ID);
		OTLog::vOutput(0, "OT_API::SmartContract_ConfirmAccount: Failed, since this nym (%s) isn't the owner of this account (%s).\n",
					   strNymID.Get(), str_name.c_str());
		return false;
	}
	// ---------------------------------------------
	// BY THIS POINT, we know that the account is actually owned by the Nym,
	// and we know that it's got the proper asset type ID that was expected 
	// according to the smart contract.
	//
	pPartyAcct->SetAcctID(ACCT_ID.Get());
	pPartyAcct->SetAgentName(AGENT_NAME.Get());	
	// -------------------------------
	pContract->ReleaseSignatures();
	pContract->SignContract(*pNym);
	pContract->SaveContract();
	// -------------------------------
	strOutput.Release();
	pContract->SaveContractRaw(strOutput);
	// -------------------------------
	return true;
}




bool OT_API::SmartContract_ConfirmParty(const	OTString	& THE_CONTRACT,	// The smart contract, about to be changed by this function.
										const	OTString	& PARTY_NAME,	// Should already be on the contract. This way we can find it.
										// ----------------------------------------
										const	OTIdentifier& NYM_ID,		// Nym ID for the party, the actual owner, 
												OTString	& strOutput)	// ===> AS WELL AS for the default AGENT of that party. (For now, until I code entities)
{
	const char * szFuncName		= "OT_API::SmartContract_ConfirmParty";
	// -----------------------------------------------------
	OTPseudonym * pNym = this->GetOrLoadPrivateNym(NYM_ID, szFuncName); // These copiously log, and ASSERT.
	if (NULL == pNym) return false;
	// By this point, pNym is a good pointer, and is on the wallet. (No need to cleanup.)
	// -----------------------------------------------------			
	OTScriptable * pContract = OTScriptable::InstantiateScriptable(THE_CONTRACT);
	OTCleanup<OTScriptable> theContractAngel;
	
	if (NULL == pContract)
	{
		OTLog::vOutput(0, "OT_API::SmartContract_ConfirmParty: Error loading smart contract:\n\n%s\n\n",
					   THE_CONTRACT.Get());
		return false;
	}
	else
		theContractAngel.SetCleanupTarget(*pContract);  // Auto-cleanup.
	// -----------------------------------------------------
	const std::string str_party_name(PARTY_NAME.Get());
	
	OTParty * pParty = pContract->GetParty(str_party_name);
	
	if (NULL == pParty)
	{
		OTLog::vOutput(0, "OT_API::SmartContract_ConfirmParty: Failure: Party (%s) doesn't exist, so how can you confirm it?\n",
					   str_party_name.c_str());
		return false;
	}
	// -------------------------------
	OTParty * pNewParty = new OTParty(pParty->GetPartyName(), *pNym, // party keeps an internal pointer to pNym from here on.
									  pParty->GetAuthorizingAgentName()); // Party name and agent name must match, in order to replace / activate this party.
	OT_ASSERT(NULL != pNewParty);
	if (false == pParty->CopyAcctsToConfirmingParty(*pNewParty)) 
	{
		OTLog::vOutput(0, "OT_API::SmartContract_ConfirmParty: Failed while trying to copy accounts, while confirming party: %s \n",
					   PARTY_NAME.Get());
		delete pNewParty; pNewParty=NULL;
		return false;
	}
	// ------------------
	if (false == pContract->ConfirmParty(*pNewParty)) // takes ownership. (Deletes the theoretical version of the party, replaced by our actual version pNewParty.)
	{
		OTLog::vOutput(0, "OT_API::SmartContract_ConfirmParty: Failed while trying to confirm party: %s \n", 
					   PARTY_NAME.Get());
		delete pNewParty; pNewParty=NULL;
		return false;
	}
	// ------------------
	// ConfirmParty(), unlike most others, actually signs and saves the contract already.
	// Therefore, all that's needed here is to grab it in string form...
	// (No need to sign again, it's just a waste of resource..)
//	pContract->ReleaseSignatures();
//	pContract->SignContract(*pNym);
//	pContract->SaveContract();

	strOutput.Release();
	pContract->SaveContractRaw(strOutput);
	
	return true;
}




bool OT_API::SmartContract_AddBylaw(const	OTString		& THE_CONTRACT,	// The contract, about to have the bylaw added to it.
									const	OTIdentifier	& SIGNER_NYM_ID,// Use any Nym you wish here. (The signing at this point is only to cause a save.)
									// ----------------------------------------
									const	OTString		& BYLAW_NAME,	// The Bylaw's NAME as referenced in the smart contract. (And the scripts...)
											OTString		& strOutput)
{
	const char * BYLAW_LANGUAGE	= "chai"; // todo hardcoding.
	// -----------------------------------------------------
	
	const char * szFuncName		= "OT_API::SmartContract_AddBylaw";
	// -----------------------------------------------------
	OTPseudonym * pNym = this->GetOrLoadPrivateNym(SIGNER_NYM_ID, szFuncName); // These copiously log, and ASSERT.
	if (NULL == pNym) return false;
	// By this point, pNym is a good pointer, and is on the wallet. (No need to cleanup.)
	// -----------------------------------------------------	
	OTScriptable * pContract = OTScriptable::InstantiateScriptable(THE_CONTRACT);
	OTCleanup<OTScriptable> theContractAngel;
	if (NULL == pContract)
	{
		OTLog::vOutput(0, "OT_API::SmartContract_AddBylaw: Error loading smart contract:\n\n%s\n\n",
					   THE_CONTRACT.Get());
		return false;
	}
	else
		theContractAngel.SetCleanupTarget(*pContract);  // Auto-cleanup.
	// -----------------------------------------------------
	const std::string str_bylaw_name(BYLAW_NAME.Get()), str_language(BYLAW_LANGUAGE);
	
	OTBylaw * pBylaw = pContract->GetBylaw(str_bylaw_name);

	if (NULL != pBylaw)
	{
		OTLog::vOutput(0, "OT_API::SmartContract_AddBylaw: Failure: Bylaw already exists: %s \n", 
					   BYLAW_NAME.Get());
		return false;
	}
	// -------------------------------
	pBylaw = new OTBylaw(str_bylaw_name.c_str(), str_language.c_str());
	OT_ASSERT(NULL != pBylaw);
	
	if (false == pContract->AddBylaw(*pBylaw)) // takes ownership.
	{
		OTLog::vOutput(0, "OT_API::SmartContract_AddBylaw: Failed while trying to add bylaw: %s \n", 
					   BYLAW_NAME.Get());
		delete pBylaw; pBylaw = NULL;
		return false;
	}
	// ------------------
	// Success!
	//
	pContract->ReleaseSignatures();
	pContract->SignContract(*pNym);
	pContract->SaveContract();
	// ------------------
	strOutput.Release();
	pContract->SaveContractRaw(strOutput);
	// ------------------
	return true;
}






bool OT_API::SmartContract_AddHook(const	OTString		& THE_CONTRACT,	// The contract, about to have the clause added to it.
								   const	OTIdentifier	& SIGNER_NYM_ID,	// Use any Nym you wish here. (The signing at this point is only to cause a save.)
								   // ----------------------------------------
								   const	OTString		& BYLAW_NAME,	// Should already be on the contract. (This way we can find it.)
								   // ----------------------------------------
								   const	OTString		& HOOK_NAME,	// The Hook's name as referenced in the smart contract. (And the scripts...)
								   const	OTString		& CLAUSE_NAME,	// The actual clause that will be triggered by the hook. (You can call this multiple times, and have multiple clauses trigger on the same hook.)
											OTString		& strOutput)
{
	const char * szFuncName		= "OT_API::SmartContract_AddHook";
	// -----------------------------------------------------
	OTPseudonym * pNym = this->GetOrLoadPrivateNym(SIGNER_NYM_ID, szFuncName); // These copiously log, and ASSERT.
	if (NULL == pNym) return false;
	// By this point, pNym is a good pointer, and is on the wallet. (No need to cleanup.)
	// -----------------------------------------------------	
	OTScriptable * pContract = OTScriptable::InstantiateScriptable(THE_CONTRACT);
	OTCleanup<OTScriptable> theContractAngel;
	if (NULL == pContract)
	{
		OTLog::vOutput(0, "OT_API::SmartContract_AddHook: Error loading smart contract:\n\n%s\n\n",
					   THE_CONTRACT.Get());
		return false;
	}
	else
		theContractAngel.SetCleanupTarget(*pContract);  // Auto-cleanup.
	// -----------------------------------------------------
	const std::string str_bylaw_name(BYLAW_NAME.Get());
		
	OTBylaw * pBylaw = pContract->GetBylaw(str_bylaw_name);
	
	if (NULL == pBylaw)
	{
		OTLog::vOutput(0, "OT_API::SmartContract_AddHook: Failure: Bylaw doesn't exist: %s \n",
					   str_bylaw_name.c_str());
		return false;
	}
	// -------------------------------
	const std::string	str_name(HOOK_NAME.Get()), str_clause(CLAUSE_NAME.Get());
	
	if (false == pBylaw->AddHook(str_name, str_clause))
	{
		OTLog::vOutput(0, "OT_API::SmartContract_AddHook: Failed trying to add hook (%s, clause %s) to bylaw: %s \n",
					   str_name.c_str(), str_clause.c_str(), str_bylaw_name.c_str());
		return false;
	}
	// -------------------------------
	// Success!
	//
	pContract->ReleaseSignatures();
	pContract->SignContract(*pNym);
	pContract->SaveContract();
	// ------------------
	strOutput.Release();
	pContract->SaveContractRaw(strOutput);
	// ------------------
	return true;	
}




bool OT_API::SmartContract_AddCallback(const	OTString		& THE_CONTRACT,	// The contract, about to have the clause added to it.
									   const	OTIdentifier	& SIGNER_NYM_ID,	// Use any Nym you wish here. (The signing at this point is only to cause a save.)
									   // ----------------------------------------
									   const	OTString		& BYLAW_NAME,	// Should already be on the contract. (This way we can find it.)
									   // ----------------------------------------
									   const	OTString		& CALLBACK_NAME,// The Callback's name as referenced in the smart contract. (And the scripts...)
									   const	OTString		& CLAUSE_NAME,	// The actual clause that will be triggered by the callback. (Must exist.)
												OTString		& strOutput)
{
	const char * szFuncName		= "OT_API::SmartContract_AddCallback";
	// -----------------------------------------------------
	OTPseudonym * pNym = this->GetOrLoadPrivateNym(SIGNER_NYM_ID, szFuncName); // These copiously log, and ASSERT.
	if (NULL == pNym) return false;
	// By this point, pNym is a good pointer, and is on the wallet. (No need to cleanup.)
	// -----------------------------------------------------	
	OTScriptable * pContract = OTScriptable::InstantiateScriptable(THE_CONTRACT);
	OTCleanup<OTScriptable> theContractAngel;
	if (NULL == pContract)
	{
		OTLog::vOutput(0, "OT_API::SmartContract_AddCallback: Error loading smart contract:\n\n%s\n\n",
					   THE_CONTRACT.Get());
		return false;
	}
	else
		theContractAngel.SetCleanupTarget(*pContract);  // Auto-cleanup.
	// -----------------------------------------------------
	const std::string str_bylaw_name(BYLAW_NAME.Get());
	
	OTBylaw * pBylaw = pContract->GetBylaw(str_bylaw_name);
	
	if (NULL == pBylaw)
	{
		OTLog::vOutput(0, "OT_API::SmartContract_AddCallback: Failure: Bylaw doesn't exist: %s \n",
					   str_bylaw_name.c_str());
		return false;
	}
	// -------------------------------
	const std::string	str_name(CALLBACK_NAME.Get()), str_clause(CLAUSE_NAME.Get());
	
	if (NULL != pBylaw->GetCallback(str_name))
	{
		OTLog::vOutput(0, "OT_API::SmartContract_AddCallback: Failure: Callback (%s) already exists on bylaw: %s \n",
					   str_name.c_str(), str_bylaw_name.c_str());
		return false;
	}
	// -----------------------------------------------------	
	if (false == pBylaw->AddCallback(str_name.c_str(), str_clause.c_str()))
	{
		OTLog::vOutput(0, "OT_API::SmartContract_AddCallback: Failed trying to add callback (%s, clause %s) to bylaw: %s \n",
					   str_name.c_str(), str_clause.c_str(), str_bylaw_name.c_str());
		return false;
	}
	// -------------------------------
	// Success!
	//
	pContract->ReleaseSignatures();
	pContract->SignContract(*pNym);
	pContract->SaveContract();
	// ------------------
	strOutput.Release();
	pContract->SaveContractRaw(strOutput);
	// ------------------
	return true;	
}






bool OT_API::SmartContract_AddClause(const	OTString		& THE_CONTRACT,	// The contract, about to have the clause added to it.
									 const	OTIdentifier	& SIGNER_NYM_ID,	// Use any Nym you wish here. (The signing at this point is only to cause a save.)
									 // ----------------------------------------
									 const	OTString		& BYLAW_NAME,	// Should already be on the contract. (This way we can find it.)
									 // ----------------------------------------
									 const	OTString		& CLAUSE_NAME,	// The Clause's name as referenced in the smart contract. (And the scripts...)
									 const	OTString		& SOURCE_CODE,	// The actual source code for the clause.
											OTString		& strOutput)
{
	const char * szFuncName		= "OT_API::SmartContract_AddClause";
	// -----------------------------------------------------
	OTPseudonym * pNym = this->GetOrLoadPrivateNym(SIGNER_NYM_ID, szFuncName); // These copiously log, and ASSERT.
	if (NULL == pNym) return false;
	// By this point, pNym is a good pointer, and is on the wallet. (No need to cleanup.)
	// -----------------------------------------------------	
	OTScriptable * pContract = OTScriptable::InstantiateScriptable(THE_CONTRACT);
	OTCleanup<OTScriptable> theContractAngel;
	if (NULL == pContract)
	{
		OTLog::vOutput(0, "OT_API::SmartContract_AddClause: Error loading smart contract:\n\n%s\n\n",
					   THE_CONTRACT.Get());
		return false;
	}
	else
		theContractAngel.SetCleanupTarget(*pContract);  // Auto-cleanup.
	// -----------------------------------------------------
	const std::string str_bylaw_name(BYLAW_NAME.Get());
	
	OTBylaw * pBylaw = pContract->GetBylaw(str_bylaw_name);
	
	if (NULL == pBylaw)
	{
		OTLog::vOutput(0, "OT_API::SmartContract_AddClause: Failure: Bylaw doesn't exist: %s \n",
					   str_bylaw_name.c_str());
		return false;
	}
	// -------------------------------
	const std::string str_name(CLAUSE_NAME.Get()), str_code(SOURCE_CODE.Get());
	
	if (NULL != pBylaw->GetClause(str_name))
	{
		OTLog::vOutput(0, "OT_API::SmartContract_AddClause: Failed adding: clause is already there with that name (%s) on bylaw: %s \n",
					   str_name.c_str(), str_bylaw_name.c_str());
		return false;
	}
	// ---------------------------------------------
	if (false == pBylaw->AddClause(str_name.c_str(), str_code.c_str()))
	{
		OTLog::vOutput(0, "OT_API::SmartContract_AddClause: Failed trying to add clause (%s) to bylaw: %s \n",
					   str_name.c_str(), str_bylaw_name.c_str());
		return false;
	}
	// ------------------
	// Success!
	//
	pContract->ReleaseSignatures();
	pContract->SignContract(*pNym);
	pContract->SaveContract();
	// ------------------
	strOutput.Release();
	pContract->SaveContractRaw(strOutput);
	// ------------------
	return true;	
}





bool OT_API::SmartContract_AddVariable(const	OTString		& THE_CONTRACT,		// The contract, about to have the clause added to it.
									   const	OTIdentifier	& SIGNER_NYM_ID,	// Use any Nym you wish here. (The signing at this point is only to cause a save.)
									   // ----------------------------------------
									   const	OTString		& BYLAW_NAME,		// Should already be on the contract. (This way we can find it.)
									   // ----------------------------------------
									   const	OTString		& VAR_NAME,		// The Variable's name as referenced in the smart contract. (And the scripts...)
									   const	OTString		& VAR_ACCESS,	// "constant", "persistent", or "important".
									   const	OTString		& VAR_TYPE,		// "string", "long", or "bool"
									   const	OTString		& VAR_VALUE,	// Contains a string. If type is long, atol() will be used to convert value to a long. If type is bool, the strings "true" or "false" are expected here in order to convert to a bool.
									   // ----------------------------------------
												OTString		& strOutput)
{
	const char * szFuncName		= "OT_API::SmartContract_AddVariable";
	// -----------------------------------------------------
	OTPseudonym * pNym = this->GetOrLoadPrivateNym(SIGNER_NYM_ID, szFuncName); // These copiously log, and ASSERT.
	if (NULL == pNym) return false;
	// By this point, pNym is a good pointer, and is on the wallet. (No need to cleanup.)
	// -----------------------------------------------------	
	OTScriptable * pContract = OTScriptable::InstantiateScriptable(THE_CONTRACT);
	OTCleanup<OTScriptable> theContractAngel;
	if (NULL == pContract)
	{
		OTLog::vOutput(0, "OT_API::SmartContract_AddVariable: Error loading smart contract:\n\n%s\n\n",
					   THE_CONTRACT.Get());
		return false;
	}
	else
		theContractAngel.SetCleanupTarget(*pContract);  // Auto-cleanup.
	// -----------------------------------------------------
	const std::string str_bylaw_name(BYLAW_NAME.Get());
	
	OTBylaw * pBylaw = pContract->GetBylaw(str_bylaw_name);
	
	if (NULL == pBylaw)
	{
		OTLog::vOutput(0, "OT_API::SmartContract_AddVariable: Failure: Bylaw doesn't exist: %s \n",
					   str_bylaw_name.c_str());
		return false;
	}
	// -------------------------------
	const std::string	str_name(VAR_NAME.Get()), str_access(VAR_ACCESS.Get()), 
						str_type(VAR_TYPE.Get()), str_value(VAR_VALUE.Get());
	
	if (NULL != pBylaw->GetVariable(str_name))
	{
		OTLog::vOutput(0, "OT_API::SmartContract_AddVariable: Failure: Variable (%s) already exists on bylaw: %s \n",
					   str_name.c_str(), str_bylaw_name.c_str());
		return false;
	}
	// -------------------------------
	OTVariable::OTVariable_Access theAccess = OTVariable::Var_Error_Access;
	
	if (str_access.compare("constant") == 0)
		theAccess = OTVariable::Var_Constant;
	else if (str_access.compare("persistent") == 0)
		theAccess = OTVariable::Var_Persistent;
	else if (str_access.compare("important") == 0)
		theAccess = OTVariable::Var_Important;
	// ---------------------
	OTVariable::OTVariable_Type theType = OTVariable::Var_Error_Type;
	
	if (str_type.compare("bool") == 0)
		theType = OTVariable::Var_Bool;
	else if (str_type.compare("integer") == 0)
		theType = OTVariable::Var_Integer;
	else if (str_type.compare("string") == 0)
		theType = OTVariable::Var_String;
	// ---------------------
	if ((OTVariable::Var_Error_Type == theType) || (OTVariable::Var_Error_Access == theAccess))
	{
		OTLog::Output(0, "OT_API::SmartContract_AddVariable: Failed due to bad variable type or bad access type. \n");
		return false;
	}
	// ---------------------
	bool bAdded = false;
	
	switch (theType) 
	{
		case OTVariable::Var_Bool:
		{
			const bool bValue = (str_value.compare("true") == 0);
			bAdded = pBylaw->AddVariable(str_name, bValue, theAccess);
		}
			break;
		case OTVariable::Var_Integer:
		{
			const int nValue = atoi(str_value.c_str());
			bAdded = pBylaw->AddVariable(str_name, nValue, theAccess);
		}
			break;
		case OTVariable::Var_String:
			bAdded = pBylaw->AddVariable(str_name, str_value, theAccess);
			break;
		default:
			// SHOULD NEVER HAPPEN (We already return above, if the variable type isn't correct.)
			OT_ASSERT_MSG(false, "Should never happen. You aren't seeing this.");
			break;
	}
	
	if (false == bAdded)
	{
		OTLog::vOutput(0, "OT_API::SmartContract_AddVariable: Failed trying to add variable (%s) to bylaw: %s \n",
					   str_name.c_str(), str_bylaw_name.c_str());
		return false;
	}
	// -------------------------------
	// Success!
	//
	pContract->ReleaseSignatures();
	pContract->SignContract(*pNym);
	pContract->SaveContract();
	// ------------------
	strOutput.Release();
	pContract->SaveContractRaw(strOutput);
	// ------------------
	return true;	
}



// -----------------------------------------------------







// The Nym's Name is basically just a client-side label.
// This function lets you change it.
//
// Returns success, true or false.
//
bool OT_API::SetNym_Name(const OTIdentifier	&	NYM_ID, 
						 const OTIdentifier	&	SIGNER_NYM_ID,
						 const OTString		&	NYM_NEW_NAME)
{
	const char * szFuncName = "OT_API::SetNym_Name";
	// -----------------------------------------------------
	OTWallet * pWallet = GetWallet(szFuncName); // This logs and ASSERTs already.
	if (NULL == pWallet) return false;
	// By this point, pWallet is a good pointer.  (No need to cleanup.)
	// -----------------------------------------------------}
	OTPseudonym *	pNym		= GetNym(NYM_ID,		szFuncName);
	OTPseudonym *	pSignerNym	= GetNym(SIGNER_NYM_ID,	szFuncName);
	if ((NULL == pNym) || (NULL == pSignerNym))  return false;
	// By this point, pNym and pSignerNym are good pointers.  (No need to cleanup.)
	// -----------------------------------------------------}
	// Might want to put some more data validation on the name?
	if (!NYM_NEW_NAME.Exists())
		OTLog::Output(0, "OT_API::SetNym_Name: Empty name (bad).\n");
	else
	{
		OTString strOldName(pNym->GetNymName()); // just in case.
		pNym->SetNymName(NYM_NEW_NAME);
		if (pNym->SaveSignedNymfile(*pSignerNym))
			return pWallet->SaveWallet(); // Only cause the nym's name is stored here, too.
		else
			pNym->SetNymName(strOldName); // Set it back to the old name if failure.
	}
	return false;
}




// The Asset Account's Name is basically just a client-side label.
// This function lets you change it.
//
// Returns success, true or false.
//
bool OT_API::SetAccount_Name(const OTIdentifier &	ACCT_ID, 
							 const OTIdentifier &	SIGNER_NYM_ID,
							 const OTString &		ACCT_NEW_NAME)
{
	const char * szFuncName = "OT_API::SetAccount_Name";
	// -----------------------------------------------------
	OTWallet * pWallet = this->GetWallet(szFuncName);		// This logs and ASSERTs already.
	if (NULL == pWallet) return false;
	// By this point, pWallet is a good pointer.  (No need to cleanup.)
	// -----------------------------------------------------
	OTPseudonym *	pSignerNym = this->GetOrLoadPrivateNym(SIGNER_NYM_ID, szFuncName);	// This logs and ASSERTs already.
	if (NULL == pSignerNym)	return false;
	// -----------------------------------------------------
	OTAccount *		pAccount = this->GetAccount(ACCT_ID, szFuncName);		// This logs and ASSERTs already.
	if (NULL == pAccount)	return false;
	// -------------------------------------
	if (!ACCT_NEW_NAME.Exists()) // Any other validation to do on the name?
	{
		OTLog::Output(0, "OT_API::SetAccount_Name: New name is empty (bad).\n");
	}
	else
	{
		OTLog::Output(0, "Saving updated account file to disk...\n");
		pAccount->SetName(ACCT_NEW_NAME);
		pAccount->ReleaseSignatures();
		if (pAccount->SignContract(*pSignerNym) && pAccount->SaveContract() && pAccount->SaveAccount())
			return pWallet->SaveWallet(); // Only cause the account's name is stored here, too.
		else
			OTLog::Error("OT_API::SetAccount_Name: Failed doing this:  if (pAccount->SignContract(*pSignerNym) "
						 "&& pAccount->SaveContract() && pAccount->SaveAccount())\n");
	}
	return false;	
}


// -----------------------------------------------------


/// CALLER is responsible to delete this Nym!
/// (Low level.)
OTPseudonym * OT_API::LoadPublicNym(const OTIdentifier & NYM_ID, const char * szFuncName/*=NULL*/)
{
//	const char * szFunc = (NULL != szFuncName) ? szFuncName : "OT_API::LoadPublicNym";
	// ---------------------------------
	// Grab the name, if there is one.
	// That way if we have to reload it, we'll be able to preserve the name.
	OTString		strName;
	const OTString	strNymID(NYM_ID);
	// ---------------------------------
	OTPseudonym *	pNym = this->GetNym(NYM_ID, szFuncName);	// This already logs and ASSERTs
	strName = (NULL != pNym) ? pNym->GetNymName().Get() : strNymID.Get();
	// now strName contains either "" or the Nym's name from wallet.
	// ---------------------------------
	return OTPseudonym::LoadPublicNym(NYM_ID, &strName, szFuncName);
}


/// CALLER is responsible to delete the Nym that's returned here!
/// (Low level.)
OTPseudonym * OT_API::LoadPrivateNym(const OTIdentifier & NYM_ID, const char * szFuncName/*=NULL*/)
{	
//	const char * szFunc = (NULL != szFuncName) ? szFuncName : "OT_API::LoadPrivateNym";
	// ---------------------------------
	// Grab the name, if there is one.
	// That way if we have to reload it, we'll be able to preserve the name.
	OTString		strName;
	const OTString	strNymID(NYM_ID);
	// ---------------------------------
	OTPseudonym *	pNym = this->GetNym(NYM_ID, szFuncName);	// This already logs and ASSERTs
	strName = (NULL != pNym) ? pNym->GetNymName().Get() : strNymID.Get();
	// now strName contains either "" or the Nym's name from wallet.
	// ---------------------------------
	return OTPseudonym::LoadPrivateNym(NYM_ID, &strName, szFuncName);
}




// -----------------------------------------------------


/*
 This function will load up the cron item (which is either a market offer, a payment plan,
 or a SMART CONTRACT.)
 
 Then it will try to harvest all of the closing transaction numbers for NYM_ID that are
 available to be harvested from THE_CRON_ITEM. (There might be zero #s available for that
 Nym, which is still a success and will return true. False means error.)
 
 YOU MIGHT ASK:
 
 WHY WOULD I WANT to harvest ONLY the closing numbers for the Nym, and not the OPENING
 numbers as well? The answer is because for this Nym, the opening number might already
 be burned. For example, if Nym just tried to activate a smart contract, and the activation
 FAILED, then maybe the opening number is already gone, even though his closing numbers, on the
 other hand, are still valid for retrieval. (I have to double check this.)
 
 HOWEVER, what if the MESSAGE failed, before it even TRIED the transaction? In which case,
 the opening number is still good also, and should be retrieved.  
 
 Remember, I have to keep signing for my transaction numbers until they are finally closed out.
 They will appear on EVERY balance agreement and transaction statement from here until the end
 of time, whenever I finally close out those numbers. If some of them are still good on a failed
 transaction, then I want to retrieve them so I can use them, and eventually close them out.
 
 ==> Whereas, what if I am the PARTY to a smart contract, but I am not the actual ACTIVATOR / ORIGINATOR
 (who activated the smart contract on the server).  Therefore I never sent any transaction to the
 server, and I never burned my opening number. It's probably still a good #. If my wallet is not a piece
 of shit, then I should have a stored copy of any contract that I signed. If it turns out in the future
 that that contract wasn't activated, then I can retrieve not only my closing numbers, but my OPENING
 number as well! IN THAT CASE, I would call OT_API_HarvestAllNumbers() instead of OT_API_HarvestClosingNumbers().
 */
bool OT_API::HarvestClosingNumbers(const OTIdentifier	& SERVER_ID,
								   const OTIdentifier	& NYM_ID,
								   const OTString		& THE_CRON_ITEM)
{
	const char * szFuncName		= "OT_API::HarvestClosingNumbers";
	// -----------------------------------------------------
	OTPseudonym * pNym = this->GetOrLoadPrivateNym(NYM_ID, szFuncName); // These copiously log, and ASSERT.
	if (NULL == pNym) return false;
	// By this point, pNym is a good pointer, and is on the wallet. (No need to cleanup.)
	// -----------------------------------------------------			
	OTCronItem * pCronItem = OTCronItem::NewCronItem(THE_CRON_ITEM);
	OTCleanup<OTCronItem> theContractAngel;
	if (NULL == pCronItem)
	{
		OTLog::vOutput(0, " OT_API::HarvestClosingNumbers: Error loading the cron item (a cron item is a smart contract, or "
					   "some other recurring transaction such as a market offer, or a payment plan.) Contents:\n\n%s\n\n",
					   THE_CRON_ITEM.Get());
		return false;
	}
	else
		theContractAngel.SetCleanupTarget(*pCronItem);  // Auto-cleanup.
	// -----------------------------------------------------
	pCronItem->HarvestClosingNumbers(*pNym); // <==== the Nym is actually harvesting the numbers from the Cron Item, and not the other way around.
	// -------------------------------	
	return true;
}


// NOTE: usually you will want to call OT_API_HarvestClosingNumbers, since the Opening number is usually
// burned up from some failed transaction or whatever. You don't want to harvest the opening number usually,
// just the closing numbers. (If the opening number is burned up, yet you still harvest it, then your OT wallet
// will end up using that number again on some other transaction, which will obviously then fail since the number
// isn't good anymore.)
// This function is only for those cases where you are sure that the opening transaction # hasn't been burned yet,
// such as when the message failed and the transaction wasn't attempted (because it never got that far) or such as
// when the contract simply never got signed or activated by one of the other parties, and so you want to claw your
// #'s back, and since in that case your opening number is still good, you would use the below function to get it back.
//
bool OT_API::HarvestAllNumbers(const OTIdentifier	& SERVER_ID,
							   const OTIdentifier	& NYM_ID,
							   const OTString		& THE_CRON_ITEM)
{
	const char * szFuncName		= "OT_API::HarvestAllNumbers";
	// -----------------------------------------------------
	OTPseudonym * pNym = this->GetOrLoadPrivateNym(NYM_ID, szFuncName); // These copiously log, and ASSERT.
	if (NULL == pNym) return false;
	// By this point, pNym is a good pointer, and is on the wallet. (No need to cleanup.)
	// -----------------------------------------------------			
	OTCronItem * pCronItem = OTCronItem::NewCronItem(THE_CRON_ITEM);
	OTCleanup<OTCronItem> theContractAngel;
	if (NULL == pCronItem)
	{
		OTLog::vOutput(0, " OT_API::HarvestAllNumbers: Error loading the cron item (a cron item is a smart contract, or "
					   "some other recurring transaction such as a market offer, or a payment plan.) Contents:\n\n%s\n\n",
					   THE_CRON_ITEM.Get());
		return false;
	}
	else
		theContractAngel.SetCleanupTarget(*pCronItem);  // Auto-cleanup.
	// -----------------------------------------------------
	pCronItem->HarvestOpeningNumber (*pNym); // <==== the Nym is actually harvesting the numbers from the Cron Item, and not the other way around.
	pCronItem->HarvestClosingNumbers(*pNym); // <==== the Nym is actually harvesting the numbers from the Cron Item, and not the other way around.
	// -------------------------------	
	return true;
}





/// This function only tries to load as a public Nym.
/// No need to cleanup, since it adds the Nym to the wallet.
///
OTPseudonym * OT_API::GetOrLoadPublicNym(const OTIdentifier & NYM_ID, const char * szFuncName/*=NULL*/)
{
	OTWallet * pWallet = GetWallet(szFuncName); // This logs and ASSERTs already.
	if (NULL == pWallet) return NULL;
	// By this point, pWallet is a good pointer.  (No need to cleanup.)
	// -----------------------------------------------------	
	//
	// This already logs copiously, including szFuncName...
	//
	return pWallet->GetOrLoadPublicNym(NYM_ID, szFuncName); 
}


/// This function only tries to load as a private Nym.
/// No need to cleanup, since it adds the Nym to the wallet.
///
/// It is smart enough to Get the Nym from the wallet, and if it
/// sees that it's only a public nym (no private key) then it
/// reloads it as a private nym at that time.
///
OTPseudonym * OT_API::GetOrLoadPrivateNym(const OTIdentifier & NYM_ID, const char * szFuncName/*=NULL*/)
{
	OTWallet * pWallet = GetWallet(szFuncName); // This logs and ASSERTs already.
	if (NULL == pWallet) return NULL;
	// By this point, pWallet is a good pointer.  (No need to cleanup.)
	// -----------------------------------------------------
	//
	// This already logs copiously, including szFuncName...
	//
	return pWallet->GetOrLoadPrivateNym(NYM_ID, szFuncName); 
}


/// This function tries to load as public Nym first, then if it fails,
/// it tries the private one next. (So as to avoid unnecessarily asking
/// users for their passphrase.) Be sure to use GetOrLoadPublicNym() or
/// GetOrLoadPrivateNym() if you want to force it one way or the other.
///
/// No need to cleanup the Nym returned here, since it's added to the wallet and
/// the wallet takes ownership.
///
OTPseudonym * OT_API::GetOrLoadNym(const OTIdentifier & NYM_ID, const char * szFuncName/*=NULL*/)
{
	OTWallet * pWallet = GetWallet(szFuncName); // This logs and ASSERTs already.
	if (NULL == pWallet) return NULL;
	// By this point, pWallet is a good pointer.  (No need to cleanup.)
	// -----------------------------------------------------
	//
	// This already logs copiously, including szFuncName...
	//
	return pWallet->GetOrLoadNym(NYM_ID, szFuncName); 
}



/** Tries to get the account from the wallet.
 Otherwise loads it from local storage.
 */
OTAccount * OT_API::GetOrLoadAccount(		OTPseudonym		& theNym,
									 const	OTIdentifier	& ACCT_ID,
									 const	OTIdentifier	& SERVER_ID,
									 const char *	szFuncName	/*=NULL*/)
{	
	const char * szFunc = (NULL != szFuncName) ? szFuncName : "OT_API::GetOrLoadAccount (theNym)";
	// -----------------------------------------------------
	OTWallet * pWallet = GetWallet(szFunc); // This logs and ASSERTs already.
	if (NULL == pWallet) return NULL;
	// By this point, pWallet is a good pointer.  (No need to cleanup.)
	// -----------------------------------------------------
	return pWallet->GetOrLoadAccount(theNym, ACCT_ID, SERVER_ID, szFunc); // This logs plenty.
}	

// -----------------------------------------------------

/** Tries to get the account from the wallet.
 Otherwise loads it from local storage.
 */
OTAccount * OT_API::GetOrLoadAccount(const	OTIdentifier	& NYM_ID,
									 const	OTIdentifier	& ACCT_ID,
									 const	OTIdentifier	& SERVER_ID,
									 const char *	szFuncName	/*=NULL*/)
{	
	const char * szFunc = (NULL != szFuncName) ? szFuncName : "OT_API::GetOrLoadAccount (NYM_ID)";
	// -----------------------------------------------------
	OTPseudonym * pNym = this->GetOrLoadPrivateNym(NYM_ID, szFunc);
	if (NULL == pNym) return NULL;
	// By this point, pNym is a good pointer, and is on the wallet. (No need to cleanup.)
	// -----------------------------------------------------
	return this->GetOrLoadAccount(*pNym, ACCT_ID, SERVER_ID, szFunc); // This logs plenty.
}	

// -----------------------------------------------------


// WRITE CHEQUE
//
// Returns an OTCheque pointer, or NULL. 
// (Caller responsible to delete.)
//
OTCheque * OT_API::WriteCheque(const OTIdentifier & SERVER_ID,
							   const long &			CHEQUE_AMOUNT, 
							   const time_t &		VALID_FROM, 
							   const time_t &		VALID_TO,
							   const OTIdentifier & SENDER_ACCT_ID,
							   const OTIdentifier & SENDER_USER_ID,
							   const OTString &		CHEQUE_MEMO, 
							   const OTIdentifier * pRECIPIENT_USER_ID/*=NULL*/)
{
	const char * szFuncName = "OT_API::WriteCheque";
	// -----------------------------------------------------
	OTPseudonym * pNym = this->GetOrLoadPrivateNym(SENDER_USER_ID, szFuncName);
	if (NULL == pNym) return NULL;
	// By this point, pNym is a good pointer, and is on the wallet. (No need to cleanup.)
	// -----------------------------------------------------
	OTAccount * pAccount = this->GetOrLoadAccount(*pNym, SENDER_ACCT_ID, SERVER_ID, szFuncName);
	if (NULL == pAccount) return NULL;
	// By this point, pAccount is a good pointer, and is on the wallet. (No need to cleanup.)
	// -----------------------------------------------------		
	// To write a cheque, we need to burn one of our transaction numbers. (Presumably the wallet
	// is also storing a couple of these, since they are needed to perform any transaction.)
	//
	// I don't have to contact the server to write a cheque -- as long as I already have a transaction
	// number I can use to write it with. (Otherwise I'd have to ask the server to send me one first.)
	//
	OTString strServerID(SERVER_ID);
	long lTransactionNumber=0; // Notice I use the server ID on the ACCOUNT.
	
	if (false == pNym->GetNextTransactionNum(*pNym, strServerID, lTransactionNumber))
	{
		OTLog::Output(0, "OT_API::WriteCheque: User attempted to write a cheque, but had no transaction numbers.\n");
		return NULL;
	}	
	// At this point, I know that lTransactionNumber contains one I can use.
	// ------------------------------
	OTCheque * pCheque = new OTCheque(pAccount->GetRealServerID(), 
									  pAccount->GetAssetTypeID());
	OT_ASSERT_MSG(NULL != pCheque, "OT_API::WriteCheque: Error allocating memory in the OT API.");
	// At this point, I know that pCheque is a good pointer that I either
	// have to delete, or return to the caller.
	// -----------------------------------------------------
	bool bIssueCheque = pCheque->IssueCheque(CHEQUE_AMOUNT, 
											 lTransactionNumber, 
											 VALID_FROM, VALID_TO, 
											 SENDER_ACCT_ID, 
											 SENDER_USER_ID, 
											 CHEQUE_MEMO,
											 pRECIPIENT_USER_ID);
	if (false == bIssueCheque) 
	{
		OTLog::Error("OT_API::WriteCheque: Failure calling OTCheque::IssueCheque().\n");
		delete pCheque; pCheque = NULL;
		// IF FAILED, ADD TRANSACTION NUMBER BACK TO LIST OF AVAILABLE NUMBERS.
		pNym->AddTransactionNum(*pNym, strServerID, lTransactionNumber, true); // bSave=true								
		return NULL;			
	}
	// ------------------------------
	pCheque->SignContract(*pNym);
	pCheque->SaveContract();
	
	return pCheque;
}









// PROPOSE PAYMENT PLAN  (MERCHANT calls this function)
//
// Returns an OTPaymentPlan pointer, or NULL. 
// (Caller responsible to delete.)
//
// The process (finally) is:
// 
// 1) Payment plan is written, and signed, by the recipient. (Merchant.)
// 2) He sends it to the sender, who signs it and submits it. (Payer / Customer.)
// 3) The server loads the recipient nym to verify the transaction
//    number. The sender also had to burn a transaction number (to
//    submit it) so now, both have verified trns#s in this way.
//
//----------------------
//
// Payment Plan Delay, and Payment Plan Period, both default to 30 days (if you pass 0.)
// Payment Plan Length, and Payment Plan Max Payments, both default to 0, which means
// no maximum length and no maximum number of payments.
//
// WARNING: the OTPaymentPlan object being returned, contains 2 transaction numbers of the Recipient.
// If you delete that object without actually activating it, make sure you retrieve those transaction
// numbers first, and add them BACK to the Recipient's Nym!!
//
// Furthermore, recipient should keep a COPY of this proposal after making it,
// so that he can retrieve the transaction numbers from it, for the same reason.
//
OTPaymentPlan * OT_API::ProposePaymentPlan(const OTIdentifier & SERVER_ID,
										 // ----------------------------------------
										 const time_t		& VALID_FROM,	// Default (0) == NOW
										 const time_t		& VALID_TO,		// Default (0) == no expiry / cancel anytime
										 // ----------------------------------------
										 const OTIdentifier & SENDER_ACCT_ID,
										 const OTIdentifier & SENDER_USER_ID,
										 // ----------------------------------------
										 const OTString		& PLAN_CONSIDERATION, // Like a memo.
										 // ----------------------------------------
										 const OTIdentifier & RECIPIENT_ACCT_ID,
										 const OTIdentifier & RECIPIENT_USER_ID,
										 // ----------------------------------------  // If it's above zero, the initial
										 const long			& INITIAL_PAYMENT_AMOUNT, // amount will be processed after
										 const time_t		& INITIAL_PAYMENT_DELAY,  // delay (seconds from now.) 
										 // ----------------------------------------  // AND SEPARATELY FROM THIS...
										 const long			& PAYMENT_PLAN_AMOUNT,	// The regular amount charged,
										 const time_t		& PAYMENT_PLAN_DELAY,	// which begins occuring after delay
										 const time_t		& PAYMENT_PLAN_PERIOD,	// (seconds from now) and happens
										 // ----------------------------------------// every period, ad infinitum, until
										 time_t	  PAYMENT_PLAN_LENGTH /*=0*/,		// after the length (in seconds)
										 int	  PAYMENT_PLAN_MAX_PAYMENTS /*=0*/	// expires, or after the maximum
										 )											// number of payments. These last 
{																					// two arguments are optional.
	const char * szFuncName = "OT_API::ProposePaymentPlan";
	// -----------------------------------------------------
	OTPseudonym * pNym = this->GetOrLoadPrivateNym(RECIPIENT_USER_ID, szFuncName); // This logs, ASSERTs, etc.
	if (NULL == pNym) return NULL;
	// By this point, pNym is a good pointer, and is on the wallet. (No need to cleanup.)
	// -----------------------------------------------------
	OTAccount * pAccount = this->GetOrLoadAccount(*pNym, RECIPIENT_ACCT_ID, SERVER_ID, szFuncName);
	if (NULL == pAccount) return NULL;
	// By this point, pAccount is a good pointer, and is on the wallet. (No need to cleanup.)
	// -----------------------------------------------------			
	OTPaymentPlan * pPlan = new OTPaymentPlan(SERVER_ID, 
											  pAccount->GetAssetTypeID(),
											  SENDER_ACCT_ID,
                                              SENDER_USER_ID,
											  RECIPIENT_ACCT_ID, 
                                              RECIPIENT_USER_ID);
	OT_ASSERT_MSG(NULL != pPlan, "OT_API::ProposePaymentPlan: Error allocating memory in the OT API for new OTPaymentPlan.\n");
	// -----------------------------------------------------
	// At this point, I know that pPlan is a good pointer that I either
	// have to delete, or return to the caller. CLEANUP WARNING!
	// -----------------------------------------------------
    bool bSuccessSetProposal =
            pPlan->SetProposal(*pNym, PLAN_CONSIDERATION, VALID_FROM, VALID_TO);
    // ************************************************
    // WARNING!!!! SetProposal() burns TWO transaction numbers for RECIPIENT. (*pNym)
    // BELOW THIS POINT, if you have an error, then you must retrieve those numbers from
    // the plan, and set them BACK on pNym before you return!!!
    // ------------------------------------------------
	const OTString strServerID(SERVER_ID);

	if (!bSuccessSetProposal)
	{   
		OTLog::Output(0, "OT_API::ProposePaymentPlan: Failed trying to set the proposal.\n");
        // IF FAILED, ADD TRANSACTION NUMBER(s) BACK TO LIST OF AVAILABLE NUMBERS.
        for (int i = 0; i < pPlan->GetRecipientCountClosingNumbers(); i++)
        {
            long lNumber = pPlan->GetRecipientClosingTransactionNoAt(i);
            pNym->AddTransactionNum(*pNym, 
                                    strServerID, 
                                    lNumber, 
                                    // The below line of code means "Only SAVE TO STORAGE on the LAST ITERATION."
                                    (i == ( pPlan->GetRecipientCountClosingNumbers()-1)) ? true : false); // bSave
        }
		delete pPlan; pPlan = NULL;
        return NULL;
	}
	
	// -----------------------------------------------------------------------
	bool bSuccessSetInitialPayment	= true; // the default, in case user chooses not to even have this payment.
	bool bSuccessSetPaymentPlan		= true; // the default, in case user chooses not to have a payment plan
	// -----------------------------------------------------------------------
	
	if ((INITIAL_PAYMENT_AMOUNT > 0) && (INITIAL_PAYMENT_DELAY >= 0))
	{		
		// The Initial payment delay is measured in seconds, starting from the "Creation Date". 
		bSuccessSetInitialPayment = pPlan->SetInitialPayment(INITIAL_PAYMENT_AMOUNT, INITIAL_PAYMENT_DELAY);
	}	
	if (!bSuccessSetInitialPayment)
	{
		OTLog::Output(0, "OT_API::ProposePaymentPlan: Failed trying to set the initial payment.\n");
        // IF FAILED, ADD TRANSACTION NUMBER(s) BACK TO LIST OF AVAILABLE NUMBERS.
        for (int i = 0; i < pPlan->GetRecipientCountClosingNumbers(); i++)
        {
            long lNumber = pPlan->GetRecipientClosingTransactionNoAt(i);
            pNym->AddTransactionNum(*pNym, 
                                    strServerID, 
                                    lNumber, 
                                    // The below line of code means "Only SAVE TO STORAGE on the LAST ITERATION."
                                    (i == ( pPlan->GetRecipientCountClosingNumbers()-1)) ? true : false); // bSave
        }
 		delete pPlan; pPlan = NULL;
		return NULL;
	}
	// -----------------------------------------------------------------------
    //	
    //				  " 6 minutes	==      360 Seconds\n"
    //				  "10 minutes	==      600 Seconds\n"
    //				  "1 hour		==     3600 Seconds\n"
    //				  "1 day		==    86400 Seconds\n"
    //				  "30 days		==  2592000 Seconds\n"
    //				  "3 months		==  7776000 Seconds\n"
    //				  "6 months		== 15552000 Seconds\n\n"
    //	
	
	if (PAYMENT_PLAN_AMOUNT > 0) // If there are regular payments.
	{
		// -----------------------------------------------------------------------
		// The payment plan delay is measured in seconds, starting from the "Creation Date".
		time_t	PAYMENT_DELAY = LENGTH_OF_MONTH_IN_SECONDS; // Defaults to 30 days, measured in seconds (if you pass 0.)
        
		if (PAYMENT_PLAN_DELAY > 0)
			PAYMENT_DELAY = PAYMENT_PLAN_DELAY;
		// -----------------------------------------------------------------------
		time_t	PAYMENT_PERIOD = LENGTH_OF_MONTH_IN_SECONDS; // Defaults to 30 days, measured in seconds (if you pass 0.)
        
		if (PAYMENT_PLAN_PERIOD > 0)
			PAYMENT_PERIOD = PAYMENT_PLAN_PERIOD;
		// -----------------------------------------------------------------------
		time_t	PLAN_LENGTH = 0; // Defaults to 0 seconds (for no max length).
        
		if (PAYMENT_PLAN_LENGTH > 0)
			PLAN_LENGTH = PAYMENT_PLAN_LENGTH;
		// -----------------------------------------------------------------------
		int nMaxPayments = 0; // Defaults to 0 maximum payments (for no maximum).
		
		if (PAYMENT_PLAN_MAX_PAYMENTS > 0)
			nMaxPayments = PAYMENT_PLAN_MAX_PAYMENTS;
		// -----------------------------------------------------------------------
		bSuccessSetPaymentPlan = pPlan->SetPaymentPlan(PAYMENT_PLAN_AMOUNT, 
													   PAYMENT_DELAY, PAYMENT_PERIOD, 
													   PLAN_LENGTH, nMaxPayments);
	}
	// -----------------------------------------------
	if (!bSuccessSetPaymentPlan)
	{
		OTLog::Output(0, "OT_API::ProposePaymentPlan: Failed trying to set the payment plan.\n");
        // IF FAILED, ADD TRANSACTION NUMBER(s) BACK TO LIST OF AVAILABLE NUMBERS.
        for (int i = 0; i < pPlan->GetRecipientCountClosingNumbers(); i++)
        {
            long lNumber = pPlan->GetRecipientClosingTransactionNoAt(i);
            pNym->AddTransactionNum(*pNym, 
                                    strServerID, 
                                    lNumber, 
                                    // The below line of code means "Only SAVE TO STORAGE on the LAST ITERATION."
                                    (i == ( pPlan->GetRecipientCountClosingNumbers()-1)) ? true : false); // bSave
        }
        delete pPlan; pPlan = NULL;
		return NULL;
	}
    // ------------------------------------------------
    
	pPlan->SignContract(*pNym); // Here we have saved the MERCHANT's VERSION.
	pPlan->SaveContract();      // A copy of this will be attached to the CUSTOMER's version as well.
	
	return pPlan;
}








// CONFIRM PAYMENT PLAN  (CUSTOMER)
//
// Returns an OTPaymentPlan pointer, or NULL. 
// (Caller responsible to delete.)
//
// The process (currently) is:
// 
// 1) Payment plan is written, and signed, by the recipient. (Merchant.)
// 2) He sends it to the sender, who signs it and submits it. (Payer / Customer.)
// 3) The server loads the recipient nym to verify the transaction
//    number. The sender also had to burn a transaction number (to
//    submit it) so now, both have verified trns#s in this way.
//
//----------------------
//
bool OT_API::ConfirmPaymentPlan(const OTIdentifier & SERVER_ID,
                                // ----------------------------------------
                                const OTIdentifier & SENDER_USER_ID,
                                const OTIdentifier & SENDER_ACCT_ID,
                                // ----------------------------------------
                                const OTIdentifier & RECIPIENT_USER_ID,
                                // ----------------------------------------
                                OTPaymentPlan & thePlan)										
{
	const char * szFuncName = "OT_API::ConfirmPaymentPlan";
	// -----------------------------------------------------
	OTPseudonym * pNym = this->GetOrLoadPrivateNym(SENDER_USER_ID, szFuncName); // This logs, ASSERTs, etc.
	if (NULL == pNym) return false;
	// By this point, pNym is a good pointer, and is on the wallet. (No need to cleanup.)
	// -----------------------------------------------------
	OTAccount * pAccount = this->GetOrLoadAccount(*pNym, SENDER_ACCT_ID, SERVER_ID, szFuncName);
	if (NULL == pAccount) return false;
	// By this point, pAccount is a good pointer, and is on the wallet. (No need to cleanup.)
	// -----------------------------------------------------			
    OTPseudonym * pMerchantNym = this->LoadPublicNym(RECIPIENT_USER_ID, szFuncName);
    OTCleanup<OTPseudonym> theNymAngel(pMerchantNym);
    
    if (NULL == pMerchantNym) // We don't have this Nym in our storage already.
	{
		const OTString strRecipNymID(RECIPIENT_USER_ID);
		OTLog::vOutput(0, "OT_API::ConfirmPaymentPlan: There's no (Merchant) Nym with the recipient's NymID in local storage: %s\n",
					   strRecipNymID.Get());
        return false;
	}
	// pMerchantNym is also good, and has an angel. (No need to cleanup.)
	//
    // *******************************************************    
	// The "Creation Date" of the agreement is re-set here.
	//
    bool bConfirmed = thePlan.Confirm(*pMerchantNym, *pNym);
	//
    // WARNING:  The call to "Confirm()" uses TWO transaction numbers from pNym!
    // If you don't end up actually USING this payment plan, then you need to retrieve
    // those numbers and Add them back to pNym again.
    // A nice client will store a copy of any payment plans until they are closed out, or canceled,
    // or whatever.
    // ANY FAILURES BELOW THIS POINT need to be smart enough to retrieve those numbers before returning.
    //
	if (!bConfirmed)
	{
		OTLog::Output(0, "OT_API::ConfirmPaymentPlan: Failed trying to confirm the agreement.\n");
		const OTString strServerID(SERVER_ID);
        
        // The main thePlan.GetTransactionNum() contains the main transaction number
        // for the whole plan, which belongs to pNym, so we'll grab that here as well.
		long lTransactionNumber = thePlan.GetTransactionNum();
        if (lTransactionNumber > 0)
            pNym->AddTransactionNum(*pNym, strServerID, lTransactionNumber, false); // bSave=false, assuming the loop below runs at least once.

        // IF FAILED, ADD TRANSACTION NUMBER(s) BACK TO LIST OF AVAILABLE NUMBERS.
        for (int i = 0; i < thePlan.GetCountClosingNumbers(); i++)
        {
            long lNumber = thePlan.GetClosingTransactionNoAt(i);
            pNym->AddTransactionNum(*pNym, 
                                    strServerID, 
                                    lNumber, 
                                    (i == (thePlan.GetCountClosingNumbers()-1)) ? true : false); // bSave
            // There's only supposed to be one number here (the closing number)
            // But I copied the loop from above and it seems more capable for the future.
        }
		return false;
	}
	// -----------------------------------------------------------------------
	thePlan.SignContract(*pNym); // Here we have saved the CUSTOMER's version, 
	thePlan.SaveContract();      // which contains a copy of the merchant's version.
	
	return true;
}



// LOAD PURSE
//
// Returns an OTPurse pointer, or NULL. 
// (Caller responsible to delete.)
//
OTPurse * OT_API::LoadPurse(const OTIdentifier & SERVER_ID,
							const OTIdentifier & ASSET_ID,
							const OTIdentifier & USER_ID)
{	
	OT_ASSERT_MSG(m_bInitialized, "Not initialized; call OT_API::Init first.");
	
	const OTString strServerID(SERVER_ID);
	const OTString strUserID(USER_ID);
	const OTString strAssetTypeID(ASSET_ID);
	// -----------------------------------------------------------------
	
	OTPurse * pPurse = new OTPurse(SERVER_ID, ASSET_ID, USER_ID);
	OT_ASSERT_MSG(NULL != pPurse, "Error allocating memory in the OT API."); // responsible to delete or return pPurse below this point.
	
	if (pPurse->LoadPurse(strServerID.Get(), strUserID.Get(), strAssetTypeID.Get()))
		return pPurse;
	
	delete pPurse; 
	pPurse = NULL;
	
	return NULL;
}


bool OT_API::SavePurse(const OTIdentifier & SERVER_ID,
					   const OTIdentifier & ASSET_ID,
					   const OTIdentifier & USER_ID,
					   OTPurse & THE_PURSE)
{	
	OT_ASSERT_MSG(m_bInitialized, "Not initialized; call OT_API::Init first.");
	
	const OTString strServerID(SERVER_ID);
	const OTString strAssetTypeID(ASSET_ID);
	const OTString strUserID(USER_ID);
	// -----------------------------------------------------------------
	
	if (THE_PURSE.SavePurse(strServerID.Get(), strUserID.Get(), strAssetTypeID.Get()))
		return true;
	
	const OTString strPurse(THE_PURSE);
	OTLog::vOutput(0, "OT_API::SavePurse: Failed saving purse:\n\n%s\n\n", strPurse.Get());
	return false;
}




// LOAD Mint
//
// Returns an OTMint pointer, or NULL. 
// (Caller responsible to delete.)
//
OTMint * OT_API::LoadMint(const OTIdentifier & SERVER_ID,
						  const OTIdentifier & ASSET_ID)
{	
	const char * szFuncName = "OT_API::LoadMint";
	// -----------------------------------------------------
	const OTString strServerID(SERVER_ID);
	const OTString strAssetTypeID(ASSET_ID);
	// -------------------------------------------------------------
	OTServerContract	* pServerContract	= this->GetServer(SERVER_ID, szFuncName);
	if (NULL == pServerContract) return NULL;
	// -------------------------------------------------------------		
	const OTPseudonym	* pServerNym		= pServerContract->GetContractPublicNym();
	if (NULL == pServerNym)
	{
		OTLog::vError("OT_API::LoadMint: Failed trying to get contract public Nym for ServerID: %s \n",
					  strServerID.Get());
		return NULL;
	}
	// -------------------------------------------------------------
	OTMint * pMint = new OTMint(strServerID, strAssetTypeID);
	OT_ASSERT_MSG(NULL != pMint, "OT_API::LoadMint: Error allocating memory in the OT API"); 
	// responsible to delete or return pMint below this point.
	// -------------------------------------------------------------
	if (!pMint->LoadMint() || !pMint->VerifyMint(*pServerNym))
	{
		OTLog::vOutput(0, "OT_API::LoadMint: Unable to load or verify Mintfile : %s%s%s%s%s\n", 
					   OTLog::MintFolder(), OTLog::PathSeparator(), strServerID.Get(),
					   OTLog::PathSeparator(), strAssetTypeID.Get());
		delete pMint; pMint = NULL;
		return NULL;		
	}
	// -------------------------------------------------------------
	return pMint;
}



// LOAD SERVER CONTRACT (from local storage)
//
// Caller is responsible to delete.
//
OTServerContract * OT_API::LoadServerContract(const OTIdentifier & SERVER_ID)
{
	OT_ASSERT_MSG(m_bInitialized, "Not initialized; call OT_API::Init first.");
	// -----------------------------------------------------------------
	OTString strServerID(SERVER_ID);

	OTString strFoldername	= OTLog::ContractFolder();
	OTString strFilename	= strServerID.Get();
	// ------------------------------------------------------------------
	if (false == OTDB::Exists(strFoldername.Get(), strFilename.Get()))
	{
		OTLog::vError("OT_API::LoadServerContract: File does not exist: %s%s%s\n", 
					  strFoldername.Get(), OTLog::PathSeparator(), strFilename.Get());
		return NULL;
	}
	// --------------------------------------------------------------------
	OTServerContract * pContract = new OTServerContract(strServerID, strFoldername,
														strFilename, strServerID);
	OT_ASSERT_MSG(NULL != pContract, "Error allocating memory for Server "
				  "Contract in OT_API::LoadServerContract\n");
	
	if (pContract->LoadContract() && pContract->VerifyContract())
		return pContract;
	else
		OTLog::vOutput(0, "OT_API::LoadServerContract: Unable to load or verify server contract. (Maybe it's just not there, and needs to "
					   "be downloaded.) Server ID: %s\n", strServerID.Get());
	// --------------------------------------------------------------------
	delete pContract; 
	pContract = NULL;
	
	return NULL;
}


// LOAD ASSET CONTRACT (from local storage)
//
// Caller is responsible to delete.
//
OTAssetContract * OT_API::LoadAssetContract(const OTIdentifier & ASSET_ID)
{
	OT_ASSERT_MSG(m_bInitialized, "Not initialized; call OT_API::Init first.");
	// -----------------------------------------------------------------
	OTString strAssetTypeID(ASSET_ID);
	
	OTString strFoldername	= OTLog::ContractFolder();
	OTString strFilename	= strAssetTypeID.Get();
	// -----------------------------------------------------------------
	if (false == OTDB::Exists(strFoldername.Get(), strFilename.Get()))
	{
		OTLog::vError("OT_API::LoadAssetContract: File does not exist: %s%s%s\n", 
					  strFoldername.Get(), OTLog::PathSeparator(), strFilename.Get());
		return NULL;
	}
	// -----------------------------------------------------------------
	OTAssetContract * pContract = new OTAssetContract(strAssetTypeID, strFoldername,
													  strFilename, strAssetTypeID);
	OT_ASSERT_MSG(NULL != pContract, "Error allocating memory for Asset "
				  "Contract in OT_API::LoadAssetContract\n");
	
	if (pContract->LoadContract() && pContract->VerifyContract())
		return pContract;
	else
		OTLog::vOutput(0, "OT_API::LoadAssetContract: Unable to load or verify asset contract (Maybe it's just not there, and needs to "
					   "be downloaded.) Asset ID: %s\n", strAssetTypeID.Get());
	// --------------------------------------------------------------------	
	delete pContract; 
	pContract = NULL;
	
	return NULL;
}



// LOAD ASSET ACCOUNT
//
// Caller is NOT responsible to delete -- I add it to the wallet!
//
// We don't care if this asset account is already loaded in the wallet.
// Presumably, the user has just downloaded the latest copy of the account
// from the server, and the one in the wallet is old, so now this function
// is being called to load the new one from storage and update the wallet.
//
// See also: OT_API::GetOrLoadAccount()
//
OTAccount * OT_API::LoadAssetAccount(const OTIdentifier & SERVER_ID,
									 const OTIdentifier & USER_ID,
									 const OTIdentifier & ACCOUNT_ID)
{
	const char * szFuncName = "OT_API::LoadAssetAccount";
	// -----------------------------------------------------
	OTWallet * pWallet = this->GetWallet(szFuncName); // This logs and ASSERTs already.
	if (NULL == pWallet) return NULL;
	// By this point, pWallet is a good pointer.  (No need to cleanup.)
	// -----------------------------------------------------
	OTPseudonym * pNym = this->GetOrLoadPrivateNym(USER_ID, szFuncName);
	if (NULL == pNym) return NULL;
	// By this point, pNym is a good pointer, and is on the wallet. (No need to cleanup.)
	// -----------------------------------------------------
	return pWallet->LoadAccount(*pNym, ACCOUNT_ID, SERVER_ID, szFuncName);	
}



// LOAD NYMBOX
//
// Caller IS responsible to delete
//
OTLedger * OT_API::LoadNymbox(const OTIdentifier & SERVER_ID,
							  const OTIdentifier & USER_ID)
{
	const char * szFuncName = "OT_API::LoadNymbox";
	// -----------------------------------------------------
	OTPseudonym * pNym = this->GetOrLoadPrivateNym(USER_ID, szFuncName);
	if (NULL == pNym) return NULL;
	// By this point, pNym is a good pointer, and is on the wallet. (No need to cleanup.)
	// -----------------------------------------------------
	OTLedger * pLedger = new OTLedger(USER_ID, USER_ID, SERVER_ID);
	OT_ASSERT_MSG(NULL != pLedger, "OT_API::LoadNymbox: Error allocating memory in the OT API.");
	// Beyond this point, I know that pLedger will need to be deleted or returned.
	// ------------------------------------------------------
	if (pLedger->LoadNymbox() && pLedger->VerifyAccount(*pNym))
		return pLedger;
	else
	{
		OTString strUserID(USER_ID);
		OTLog::vOutput(0, "OT_API::LoadNymbox: Unable to load or verify nymbox: %s\n",
					   strUserID.Get());
		delete pLedger;
		pLedger = NULL;		
	}
	return  NULL;
}

// LOAD NYMBOX NO VERIFY 
// (VerifyAccount, for ledgers, loads all the Box Receipts. You may not want this.
// For example, you may be loading this ledger precisely so you can iterate through
// its receipts and download them from the server, so they will all load up on a
// subsequent verify.)
//
// Caller IS responsible to delete
//
OTLedger * OT_API::LoadNymboxNoVerify(const OTIdentifier & SERVER_ID,
									  const OTIdentifier & USER_ID)
{
	const char * szFuncName = "OT_API::LoadNymboxNoVerify";
	// -----------------------------------------------------
	OTPseudonym * pNym = this->GetOrLoadPrivateNym(USER_ID, szFuncName);
	if (NULL == pNym) return NULL;
	// By this point, pNym is a good pointer, and is on the wallet. (No need to cleanup.)
	// -----------------------------------------------------
	OTLedger * pLedger = new OTLedger(USER_ID, USER_ID, SERVER_ID);
	OT_ASSERT_MSG(NULL != pLedger, "OT_API::LoadNymboxNoVerify: Error allocating memory in the OT API.");
	// Beyond this point, I know that pLedger will need to be deleted or returned.
	// ------------------------------------------------------
	if (pLedger->LoadNymbox())
		return pLedger;
	else
	{
		OTString strUserID(USER_ID);
		OTLog::vOutput(0, "OT_API::LoadNymboxNoVerify: Unable to load nymbox: %s\n",
					   strUserID.Get());
		delete pLedger;
		pLedger = NULL;		
	}
	return  NULL;
}



// LOAD INBOX
//
// Caller IS responsible to delete
//
OTLedger * OT_API::LoadInbox(const OTIdentifier & SERVER_ID,
							 const OTIdentifier & USER_ID,
							 const OTIdentifier & ACCOUNT_ID)
{
	const char * szFuncName = "OT_API::LoadInbox";
	// -----------------------------------------------------
	OTPseudonym * pNym = this->GetOrLoadPrivateNym(USER_ID, szFuncName);
	if (NULL == pNym) return NULL;
	// By this point, pNym is a good pointer, and is on the wallet. (No need to cleanup.)
	// -----------------------------------------------------
	OTLedger * pLedger = new OTLedger(USER_ID, ACCOUNT_ID, SERVER_ID);
	OT_ASSERT_MSG(NULL != pLedger, "OT_API::LoadInbox: Error allocating memory in the OT API.");
	
	// Beyond this point, I know that pLedger will need to be deleted or returned.
	// ------------------------------------------------------
	if (pLedger->LoadInbox() && pLedger->VerifyAccount(*pNym))
		return pLedger;
	else
	{
		OTString strUserID(USER_ID), strAcctID(ACCOUNT_ID);
		OTLog::vOutput(0, "OT_API::LoadInbox: Unable to load or verify inbox: %s\n For user: %s\n",
					   strAcctID.Get(), strUserID.Get());
		delete pLedger;
		pLedger = NULL;		
	}
	return  NULL;
}


// LOAD INBOX NO VERIFY
//
// (VerifyAccount, for ledgers, loads all the Box Receipts. You may not want this.
// For example, you may be loading this ledger precisely so you can iterate through
// its receipts and download them from the server, so they will all load up on a
// subsequent verify.)
//
// Caller IS responsible to delete
//
OTLedger * OT_API::LoadInboxNoVerify(const OTIdentifier & SERVER_ID,
									 const OTIdentifier & USER_ID,
									 const OTIdentifier & ACCOUNT_ID)
{
	const char * szFuncName = "OT_API::LoadInboxNoVerify";
	// -----------------------------------------------------
	OTPseudonym * pNym = this->GetOrLoadPrivateNym(USER_ID, szFuncName);
	if (NULL == pNym) return NULL;
	// By this point, pNym is a good pointer, and is on the wallet. (No need to cleanup.)
	// -----------------------------------------------------
	OTLedger * pLedger = new OTLedger(USER_ID, ACCOUNT_ID, SERVER_ID);
	OT_ASSERT_MSG(NULL != pLedger, "OT_API::LoadInboxNoVerify: Error allocating memory in the OT API.");
	
	// Beyond this point, I know that pLedger will need to be deleted or returned.
	// ------------------------------------------------------
	if (pLedger->LoadInbox())
		return pLedger;
	else
	{
		OTString strUserID(USER_ID), strAcctID(ACCOUNT_ID);
		OTLog::vOutput(0, "OT_API::LoadInboxNoVerify: Unable to load inbox: %s\n For user: %s\n",
					   strAcctID.Get(), strUserID.Get());
		delete pLedger;
		pLedger = NULL;		
	}
	return  NULL;
}


// LOAD OUTBOX
//
// Caller IS responsible to delete
//
OTLedger * OT_API::LoadOutbox(const OTIdentifier & SERVER_ID,
							  const OTIdentifier & USER_ID,
							  const OTIdentifier & ACCOUNT_ID)
{	
	const char * szFuncName = "OT_API::LoadOutbox";
	// -----------------------------------------------------
	OTPseudonym * pNym = this->GetOrLoadPrivateNym(USER_ID, szFuncName);
	if (NULL == pNym) return NULL;
	// By this point, pNym is a good pointer, and is on the wallet. (No need to cleanup.)
	// -----------------------------------------------------
	OTLedger * pLedger = new OTLedger(USER_ID, ACCOUNT_ID, SERVER_ID);
	OT_ASSERT_MSG(NULL != pLedger, "OT_API::LoadOutbox: Error allocating memory in the OT API.");
	
	// Beyond this point, I know that pLedger is loaded and will need to be deleted or returned.
	// ------------------------------------------------------
	
	if (pLedger->LoadOutbox() && pLedger->VerifyAccount(*pNym))
		return pLedger;
	else
	{
		OTString strUserID(USER_ID), strAcctID(ACCOUNT_ID);
		
		OTLog::vOutput(0, "OT_API::LoadOutbox: Unable to load or verify outbox: %s\n For user: %s\n",
					   strAcctID.Get(), strUserID.Get());
		
		delete pLedger;
		pLedger = NULL;		
	}
	return  NULL;
}



// LOAD OUTBOX NO VERIFY
//
// (VerifyAccount, for ledgers, loads all the Box Receipts. You may not want this.
// For example, you may be loading this ledger precisely so you can iterate through
// its receipts and download them from the server, so they will all load up on a
// subsequent verify.)
//
// Caller IS responsible to delete
//
OTLedger * OT_API::LoadOutboxNoVerify(const OTIdentifier & SERVER_ID,
									  const OTIdentifier & USER_ID,
									  const OTIdentifier & ACCOUNT_ID)
{	
	const char * szFuncName = "OT_API::LoadOutboxNoVerify";
	// -----------------------------------------------------
	OTPseudonym * pNym = this->GetOrLoadPrivateNym(USER_ID, szFuncName);
	if (NULL == pNym) return NULL;
	// By this point, pNym is a good pointer, and is on the wallet. (No need to cleanup.)
	// -----------------------------------------------------
	OTLedger * pLedger = new OTLedger(USER_ID, ACCOUNT_ID, SERVER_ID);
	OT_ASSERT_MSG(NULL != pLedger, "OT_API::LoadOutboxNoVerify: Error allocating memory in the OT API.");
	
	// Beyond this point, I know that pLedger is loaded and will need to be deleted or returned.
	// ------------------------------------------------------
	
	if (pLedger->LoadOutbox())
		return pLedger;
	else
	{
		OTString strUserID(USER_ID), strAcctID(ACCOUNT_ID);
		
		OTLog::vOutput(0, "OT_API::LoadOutboxNoVerify: Unable to load outbox: %s\n For user: %s\n",
					   strAcctID.Get(), strUserID.Get());
		
		delete pLedger;
		pLedger = NULL;		
	}
	return  NULL;
}



// This function assumes you have already downloaded the latest copy of your Nymbox,
// and that you have already retrieved theMessageNym from the @createUserAccount
// message, with both objects being loaded and passed as arguments here, ready to go.
//
bool OT_API::ResyncNymWithServer(OTPseudonym & theNym, OTLedger & theNymbox, OTPseudonym & theMessageNym)
{
	OT_ASSERT_MSG(m_bInitialized, "Not initialized; call OT_API::Init first.");
	// -----------------------------------------------------
	if (OTLedger::nymbox != theNymbox.GetType())
	{
		OTLog::vError("OT_API::ResyncNymWithServer: Error: Expected a Nymbox, but you passed in a %s.\n",
					  theNymbox.GetTypeString());
		return false;
	}
	// -----------------------------------------------------
	if (false == theNym.CompareID(theNymbox.GetUserID()))
	{
		const OTString id1(theNym.GetConstID()), id2(theNymbox.GetUserID());
		OTLog::vError("OT_API::ResyncNymWithServer: Error: NymID of Nym (%s) doesn't match NymID on (supposedly) his own Nymbox (%s).\n",
					  id1.Get(), id2.Get());
		return false;
	}	
	// -----------------------------------------------------
//	if (false == theNym.CompareID(theMessageNym))
//	{
//		const OTString id1(theNym.GetConstID()), id2(theMessageNym.GetConstID());
//		OTLog::vError("OT_API::ResyncNymWithServer: Error: NymID of Nym (%s) doesn't match NymID on (supposedly) his server-side doppelganger (%s).\n",
//					  id1.Get(), id2.Get());
//		return false;
//	}
	// *****************************************************

	return theNym.ResyncWithServer(theNymbox, theMessageNym);
}









// YOU are responsible to delete the OTMessage object, once
// you receive the pointer that comes back from this function.
// (It also might return NULL, if there are none there.)
//
OTMessage * OT_API::PopMessageBuffer()
{
	OT_ASSERT_MSG(m_bInitialized && (m_pClient != NULL), "Not initialized; call OT_API::Init first.");
		
	return m_pClient->GetMessageBuffer().GetNextMessage();
}

void OT_API::FlushMessageBuffer()
{
	OT_ASSERT_MSG(m_bInitialized, "Not initialized; call OT_API::Init first.");
	
	OTMessage * pMsg = m_pClient->GetMessageBuffer().GetNextMessage();
	
	while (NULL != pMsg)
	{
		delete pMsg;
		pMsg = m_pClient->GetMessageBuffer().GetNextMessage();
	}
}




// --------------------------------------------------------------------





// ABOVE ARE COMMANDS TO MANIPULATE LOCAL DATA (*NOT* MESSAGE THE SERVER.)


// ---------------------------------------------------------------------




// NOTE: This is only for Message->TCP->SSL mode, NOT for Message->XmlRpc->HTTP mode...
//
// Eventually this connects to the server denoted by SERVER_ID
// But for right now, it just connects to the first server in the list.
// TODO: make it connect to the server ID instead of the first one in the list.
//
bool OT_API::ConnectServer(OTIdentifier & SERVER_ID, OTIdentifier	& USER_ID,
						   OTString & strCA_FILE, OTString & strKEY_FILE, OTString & strKEY_PASSWORD)
{
	OT_ASSERT_MSG(m_bInitialized, "Not initialized; call OT_API::Init first.");
	
#if defined(OT_ZMQ_MODE)
	OT_ASSERT_MSG(m_bInitialized, "OT_API::ConnectServer not necessary in ZMQ mode.");
#endif
	
	// Wallet, after loading, should contain a list of server
	// contracts. Let's pull the hostname and port out of
	// the first contract, and connect to that server.
	
	OTPseudonym * pNym = m_pWallet->GetNymByID(USER_ID);
	
	if (!pNym)
	{
		OTLog::Error("No Nym loaded but tried to connect to server.\n");
		return false;
	}
		
	bool bConnected = m_pClient->ConnectToTheFirstServerOnList(*pNym, strCA_FILE, strKEY_FILE, strKEY_PASSWORD); 
	
	if (bConnected)
	{
		OTLog::Output(0, "Success. (Connected to the first notary server on your wallet's list.)\n");
		return true;
	}
	
	OTLog::Output(0, "Either the wallet is not loaded, or there was an error connecting to server.\n");
	return false;
}




// NOTE: this function NOT needed in XmlRpc / HTTP (web services) mode.
//
// Open Transactions maintains a connection to the server(s)
// The client should call THIS function after a message, and/or periodicallyt,
// to listen on the connections for any server replies and process them.
//
// Perhaps once per second, and more often immediately following
// a request.  (Usually only one response comes for each request.)
//
bool OT_API::ProcessSockets()
{
	OT_ASSERT_MSG(m_bInitialized, "Not initialized; call OT_API::Init first.");

#if defined(OT_ZMQ_MODE)
	OT_ASSERT_MSG(m_bInitialized, "OT_API::ProcessSockets not necessary in XmlRpc mode.");
#endif
	
	bool bFoundMessage = false, bSuccess = false;
	
	do 
	{
		OTMessage * pMsg = new OTMessage;
		
		OT_ASSERT_MSG(NULL != pMsg, "Error allocating memory in the OT API");
		
		// If this returns true, that means a Message was
		// received and processed into an OTMessage object (theMsg)
		bFoundMessage = m_pClient->ProcessInBuffer(*pMsg);
		
		if (true == bFoundMessage)
		{
			bSuccess = true;
			
			//				OTString strReply;
			//				theMsg.SaveContract(strReply);
			//				OTLog::vError("\n\n**********************************************\n"
			//						"Successfully in-processed server response.\n\n%s\n", strReply.Get());
			m_pClient->ProcessServerReply(*pMsg); // the Client takes ownership and will handle cleanup.
		}
		else 
		{
			delete pMsg;
			pMsg = NULL;
		}

		
	} while (true == bFoundMessage);
	
	return bSuccess;
}
// NOTE: The above function only applies in Message / TCP / SSL mode, since server replies are instantly
// received in XmlRpc / HTTP mode. (Both are request / response, it's the same protocol no matter what transport.)








// --------------------------------------------------------------
// IS BASKET CURRENCY ?
//
// Tells you whether or not a given asset type is actually a basket currency.
//
bool OT_API::IsBasketCurrency(const OTIdentifier & BASKET_ASSET_TYPE_ID) // returns true or false.
{
	const char * szFuncName = "OT_API::IsBasketCurrency";
	// -----------------------------------------------------
	// There is an OT_ASSERT_MSG in here for memory failure,
	// but it still might return NULL if various verification fails.
	OTAssetContract * pContract = this->GetAssetType(BASKET_ASSET_TYPE_ID, szFuncName); 
	if (NULL == pContract) return false;
	// No need to cleanup pContract.
	// -----------------------------------------------------
	// Next load the OTBasket object out of that contract.
	OTBasket theBasket;
	
	// todo perhaps verify the basket here, even though I already verified the asset contract itself...
	// Can't never be too sure...
	//
	if (pContract->GetBasketInfo().Exists() && theBasket.LoadContractFromString(pContract->GetBasketInfo()))
	{
		if (theBasket.Count() > 0)
			return true;
	}

	return false;	
}



// --------------------------------------------------------------------
// Get Basket Count (of member currency types.)
//
// Returns the number of asset types that make up this basket.
// (Or zero.)
//
int OT_API::GetBasketMemberCount(const OTIdentifier & BASKET_ASSET_TYPE_ID)
{
	const char * szFuncName = "OT_API::GetBasketMemberCount";
	// -----------------------------------------------------
	// There is an OT_ASSERT_MSG in here for memory failure,
	// but it still might return NULL if various verification fails.
	OTAssetContract * pContract = this->GetAssetType(BASKET_ASSET_TYPE_ID, szFuncName); 
	if (NULL == pContract) return 0;
	// No need to cleanup pContract.
	// -----------------------------------------------------
	// Next load the OTBasket object out of that contract.
	OTBasket theBasket;
	
	// todo perhaps verify the basket here, even though I already verified the asset contract itself...
	// Can't never be too sure...
	//
	if (pContract->GetBasketInfo().Exists() && theBasket.LoadContractFromString(pContract->GetBasketInfo()))
		return theBasket.Count();
	
	return 0;
}



// --------------------------------------------------------------------
// Get Basket Member Asset Type
//
// Returns one of the asset types that make up this basket,
// by index, and true.
// (Or false.)
//
bool OT_API::GetBasketMemberType(const OTIdentifier & BASKET_ASSET_TYPE_ID,
								 const int nIndex,
								 OTIdentifier & theOutputMemberType)
{
	const char * szFuncName = "OT_API::GetBasketMemberType";
	// -----------------------------------------------------
	// There is an OT_ASSERT_MSG in here for memory failure,
	// but it still might return NULL if various verification fails.
	OTAssetContract * pContract = this->GetAssetType(BASKET_ASSET_TYPE_ID, szFuncName); 
	if (NULL == pContract) return false;
	// No need to cleanup pContract.
	// -----------------------------------------------------
	// Next load the OTBasket object out of that contract.
	OTBasket theBasket;
	
	// todo perhaps verify the basket here, even though I already verified the asset contract itself...
	// Can't never be too sure.
	if (pContract->GetBasketInfo().GetLength() && theBasket.LoadContractFromString(pContract->GetBasketInfo()))
	{
		if ((nIndex >= theBasket.Count()) || (nIndex < 0))
		{
			OTLog::vError("OT_API::GetBasketMemberType: Index out of bounds: %d\n", nIndex);
			return false;
		}
		
		BasketItem * pItem = theBasket.At(nIndex);
		OT_ASSERT_MSG(NULL != pItem, "Bad index in OT_API::GetBasketMemberType");
		
		theOutputMemberType = pItem->SUB_CONTRACT_ID;
		
		return true;
	}
	return false;
}




// --------------------------------------------------------------------
// Get Basket Member Minimum Transfer Amount
//
// Returns the minimum transfer amount for one of the asset types that
// makes up this basket, by index.
// (Or 0.)
//
long OT_API::GetBasketMemberMinimumTransferAmount(const OTIdentifier & BASKET_ASSET_TYPE_ID,
												  const int nIndex)
{
	const char * szFuncName = "OT_API::GetBasketMemberMinimumTransferAmount";
	// -----------------------------------------------------
	// There is an OT_ASSERT_MSG in here for memory failure,
	// but it still might return NULL if various verification fails.
	OTAssetContract * pContract = this->GetAssetType(BASKET_ASSET_TYPE_ID, szFuncName); 
	if (NULL == pContract) return 0;
	// No need to cleanup pContract.
	// -----------------------------------------------------
	// Next load the OTBasket object out of that contract.
	OTBasket theBasket;
	
	// todo perhaps verify the basket here, even though I already verified the asset contract itself...
	// Can't never be too sure.
	if (pContract->GetBasketInfo().GetLength() && theBasket.LoadContractFromString(pContract->GetBasketInfo()))
	{
		if ((nIndex >= theBasket.Count()) || (nIndex < 0))
		{
			OTLog::vError("OT_API::GetBasketMemberMinimumTransferAmount: Index out of bounds: %d\n", nIndex);
			return 0;
		}
		
		BasketItem * pItem = theBasket.At(nIndex);
		
		OT_ASSERT_MSG(NULL != pItem, "Bad index in OT_API::GetBasketMemberMinimumTransferAmount.");
		
		return pItem->lMinimumTransferAmount;;
	}
    else
        OTLog::Error("OT_API::GetBasketMemberMinimumTransferAmount: Failed loading basket info from basket asset contract.\n");
	
	return 0;
}



// --------------------------------------------------------------------
// Get Basket Minimum Transfer Amount
//
// Returns the minimum transfer amount for the basket.
// (Or 0.)
//
long OT_API::GetBasketMinimumTransferAmount(const OTIdentifier & BASKET_ASSET_TYPE_ID)
{
	const char * szFuncName = "OT_API::GetBasketMinimumTransferAmount";
	// -----------------------------------------------------
	// There is an OT_ASSERT_MSG in here for memory failure,
	// but it still might return NULL if various verification fails.
	OTAssetContract * pContract = this->GetAssetType(BASKET_ASSET_TYPE_ID, szFuncName); 
	if (NULL == pContract) return 0;
	// No need to cleanup pContract.
	// -----------------------------------------------------
	// Next load the OTBasket object out of that contract.
	OTBasket theBasket;
	
	// todo perhaps verify the basket here, even though I already verified the asset contract itself...
	// Can't never be too sure.
	if (pContract->GetBasketInfo().GetLength() && theBasket.LoadContractFromString(pContract->GetBasketInfo()))
		return theBasket.GetMinimumTransfer();
	
	return 0;
}





// --------------------------------------------------------
// GENERATE BASKET CREATION REQUEST
//
// Creates a new request (for generating a new Basket type).
// (Each currency in this request will be added with
// subsequent calls to OT_API::GenerateBasketItem()).
//
// (Caller is responsible to delete.)
//
OTBasket * OT_API::GenerateBasketCreation(const OTIdentifier & USER_ID,
										  const long MINIMUM_TRANSFER) // Must be above zero. If <= 0, defaults to 10.
{
	const char * szFuncName = "OT_API::GenerateBasketCreation";
	// -----------------------------------------------------
	OTPseudonym * pNym = this->GetOrLoadPrivateNym(USER_ID, szFuncName);
	if (NULL == pNym) return NULL;
	// By this point, pNym is a good pointer, and is on the wallet. (No need to cleanup.)
	// -----------------------------------------------------
	long lMinimumTransferAmount = 10;
	
	if (MINIMUM_TRANSFER > 0)
		lMinimumTransferAmount = MINIMUM_TRANSFER;
	// -----------------------------------------------------
	OTBasket * pBasket = new OTBasket(0, lMinimumTransferAmount);
	OT_ASSERT_MSG(NULL != pBasket, "OT_API::GenerateBasketCreation: Error allocating memory in the OT API");
	
	pBasket->SignContract(*pNym);
	pBasket->SaveContract();
	
	return pBasket;
}


// --------------------------------------------------------
// ADD BASKET CREATION ITEM
//
// Used for creating a request to generate a new basket currency.
bool OT_API::AddBasketCreationItem(const OTIdentifier & USER_ID, // for signature.
								   OTBasket & theBasket, 
								   const OTIdentifier & ASSET_TYPE_ID, 
								   const long MINIMUM_TRANSFER)
{
	const char * szFuncName = "OT_API::AddBasketCreationItem";
	// -----------------------------------------------------
	OTPseudonym * pNym = this->GetOrLoadPrivateNym(USER_ID, szFuncName);
	if (NULL == pNym) return false;
	// By this point, pNym is a good pointer, and is on the wallet. (No need to cleanup.)
	// -----------------------------------------------------
	// There is an OT_ASSERT_MSG in here for memory failure,
	// but it still might return NULL if various verification fails.
	OTAssetContract * pContract = this->GetAssetType(ASSET_TYPE_ID, szFuncName); 
	if (NULL == pContract) return false;
	// No need to cleanup pContract.
	// -----------------------------------------------------
	
	theBasket.AddSubContract(ASSET_TYPE_ID, MINIMUM_TRANSFER);

	theBasket.IncrementSubCount();

	theBasket.ReleaseSignatures();
	theBasket.SignContract(*pNym);
	theBasket.SaveContract();
	
	return true;
}





// -----------------------------------------------------
// ISSUE BASKET CREATION REQUEST (to server.)
//
void OT_API::issueBasket(OTIdentifier	& SERVER_ID,
						 OTIdentifier	& USER_ID,
						 OTString		& BASKET_INFO)
{
	const char * szFuncName = "OT_API::issueBasket";
	// -----------------------------------------------------
	OTPseudonym * pNym = this->GetOrLoadPrivateNym(USER_ID, szFuncName);
	if (NULL == pNym) return;
	// By this point, pNym is a good pointer, and is on the wallet. (No need to cleanup.)
	// -----------------------------------------------------
	OTServerContract	* pServer = this->GetServer(SERVER_ID, szFuncName);
	if (NULL == pServer) return;
	// -------------------------------------------------------------		
	// AT SOME POINT, BASKET_INFO has been populated with the relevant data. (see test client for example.)
	OTString strServerID(SERVER_ID), strNymID(USER_ID);
	
	OTMessage theMessage;
	long lRequestNumber = 0;
	
	// (0) Set up the REQUEST NUMBER and then INCREMENT IT
	pNym->GetCurrentRequestNum(strServerID, lRequestNumber);
	theMessage.m_strRequestNum.Format("%ld", lRequestNumber); // Always have to send this.
	pNym->IncrementRequestNum(*pNym, strServerID); // since I used it for a server request, I have to increment it
	
	// (1) Set up member variables 
	theMessage.m_strCommand			= "issueBasket";
	theMessage.m_strNymID			= strNymID;
	theMessage.m_strServerID		= strServerID;
	
	theMessage.m_ascPayload.SetString(BASKET_INFO);
	
	// (2) Sign the Message 
	theMessage.SignContract(*pNym);		
	
	// (3) Save the Message (with signatures and all, back to its internal member m_strRawFile.)
	theMessage.SaveContract();
	
	// (Send it)
#if defined(OT_ZMQ_MODE)
	m_pClient->SetFocusToServerAndNym(*pServer, *pNym, &OT_API::TransportCallback);
#endif	
	m_pClient->ProcessMessageOut(theMessage);
}




// ---------------------------------------------------------------
// GENERATE BASKET EXCHANGE REQUEST
//
// Creates a new request (for exchanging funds in/out of a Basket).
// (Each currency in this request will be added with
// subsequent calls to OT_API::GenerateBasketItem()).
//
// (Caller is responsible to delete.)
//
OTBasket * OT_API::GenerateBasketExchange(const OTIdentifier & SERVER_ID,
										  const OTIdentifier & USER_ID,
										  const OTIdentifier & BASKET_ASSET_TYPE_ID,
										  const OTIdentifier & BASKET_ASSET_ACCT_ID,
										  const int TRANSFER_MULTIPLE)	// 1			2			 3
{																		// 5=2,3,4  OR  10=4,6,8  OR 15=6,9,12
	const char * szFuncName = "OT_API::GenerateBasketExchange";
	// -----------------------------------------------------
	OTPseudonym * pNym = this->GetOrLoadPrivateNym(USER_ID, szFuncName); // These copiously log, and ASSERT.
	if (NULL == pNym) return NULL;
	// By this point, pNym is a good pointer, and is on the wallet. (No need to cleanup.)
	// -----------------------------------------------------
	OTAssetContract * pContract = this->GetAssetType(BASKET_ASSET_TYPE_ID, szFuncName);
	if (NULL == pContract) return NULL;
	// By this point, pContract is a good pointer, and is on the wallet. (No need to cleanup.)
	// -----------------------------------------------------
	OTAccount * pAccount = this->GetOrLoadAccount(*pNym, BASKET_ASSET_ACCT_ID, SERVER_ID, szFuncName);
	if (NULL == pAccount) return NULL;
	// By this point, pAccount is a good pointer, and is on the wallet. (No need to cleanup.)
	// -----------------------------------------------------		
	if (BASKET_ASSET_TYPE_ID != pAccount->GetAssetTypeID())
	{
		const OTString strAcctID(BASKET_ASSET_ACCT_ID), strAcctTypeID(BASKET_ASSET_TYPE_ID);
		OTLog::vOutput(0, "OT_API::GenerateBasketExchange: Wrong asset type ID on account %s (expected type to be %s)\n",
					   strAcctID.Get(), strAcctTypeID.Get());
		return NULL;			
	}
	// By this point, I know that everything checks out. Signature and Account ID.
	// pAccount is good, and no need to clean it up.
	// -----------------------------------------------------
	OTString strServerID(SERVER_ID);
	
	int nTransferMultiple = 1;
	
	if (TRANSFER_MULTIPLE > 0)
		nTransferMultiple = TRANSFER_MULTIPLE;
	// -----------------------------------------------------------------
	
	// Next load the OTBasket object out of that contract.
	OTBasket theBasket;
	OTBasket * pRequestBasket = NULL;
    
	// todo perhaps verify the basket here, even though I already verified the asset contract itself...
	// Can't never be too sure.
	if (pContract->GetBasketInfo().Exists() && theBasket.LoadContractFromString(pContract->GetBasketInfo()))
	{
        // We need a transaction number just to send this thing. Plus, we need a number for
        // each sub-account to the basket, as well as the basket's main account.
        // That is: 1 + theBasket.Count() + 1
        //
        if (pNym->GetTransactionNumCount(SERVER_ID) < (2 + theBasket.Count()))
        {
            OTLog::Output(0, "OT_API::GenerateBasketExchange: you don't have enough transaction numbers to perform the exchange.\n");
        }
        else
        {
            pRequestBasket = new OTBasket(theBasket.Count(), theBasket.GetMinimumTransfer());
            OT_ASSERT_MSG(NULL != pRequestBasket, "OT_API::GenerateBasketExchange: Error allocating memory in the OT API");
            
            pRequestBasket->SetTransferMultiple(nTransferMultiple); // This stays in this function.
            
            // Make sure the server knows where to put my new basket currency funds, 
            // once the exchange is done.
            pRequestBasket->SetRequestAccountID(BASKET_ASSET_ACCT_ID); // This stays too

            // Export the OTBasket object into a string, add it as
            // a payload on my request, and send to server.
            pRequestBasket->SignContract(*pNym);
            pRequestBasket->SaveContract();            
        } // *pNym apparently has enough transaction numbers to exchange the basket.
        // ----------------------------------------------------------------
	}
	else 
	{
		OTLog::Output(0, "OT_API::GenerateBasketExchange: Error loading "
					  "basket info from asset contract. "
					  "Are you SURE this is a basket currency?\n");
		return NULL;
	}    
	return pRequestBasket;
}







// --------------------------------------------------------
// ADD BASKET EXCHANGE ITEM
//
bool OT_API::AddBasketExchangeItem(const OTIdentifier & SERVER_ID,
								   const OTIdentifier & USER_ID,
								   OTBasket & theBasket, 
								   const OTIdentifier & ASSET_TYPE_ID,
								   const OTIdentifier & ASSET_ACCT_ID)
{
	const char * szFuncName = "OT_API::AddBasketExchangeItem";
	// -----------------------------------------------------
	OTPseudonym * pNym = this->GetOrLoadPrivateNym(USER_ID, szFuncName); // These copiously log, and ASSERT.
	if (NULL == pNym) return false;
	// By this point, pNym is a good pointer, and is on the wallet. (No need to cleanup.)
	// -----------------------------------------------------
	OTAssetContract * pContract = this->GetAssetType(ASSET_TYPE_ID, szFuncName);
	if (NULL == pContract) return false;
	// By this point, pContract is a good pointer, and is on the wallet. (No need to cleanup.)
	// -----------------------------------------------------
	OTAccount * pAccount = this->GetOrLoadAccount(*pNym, ASSET_ACCT_ID, SERVER_ID, szFuncName);
	if (NULL == pAccount) return false;
	// By this point, pAccount is a good pointer, and is on the wallet. (No need to cleanup.)
	// -----------------------------------------------------		
    if (pNym->GetTransactionNumCount(SERVER_ID) < 1)
    {
        OTLog::Output(0, "OT_API::AddBasketExchangeItem: you need at least one transaction number to add this exchange item.\n");
        return false;
    }
	// -----------------------------------------------------
	if (ASSET_TYPE_ID != pAccount->GetAssetTypeID())
	{
		const OTString strAssetTypeID(ASSET_TYPE_ID), strAcctID(ASSET_ACCT_ID);
		OTLog::vOutput(0, "OT_API::AddBasketExchangeItem: Wrong asset type ID on account %s (expected to find asset type %s)\n",
					   strAcctID.Get(), strAssetTypeID.Get());
		return false;			
	}
	// By this point, I know that everything checks out. Signature and Account ID.
	// pAccount is good, and no need to clean it up.
	// ----------------------------------------------------
	const OTString strServerID(SERVER_ID);

    long lSubClosingTransactionNo = 0; // For the basketReceipt (closing transaction num) for the sub account.
    
    if (pNym->GetNextTransactionNum(*pNym, strServerID, lSubClosingTransactionNo)) // this saves
    // ---------------------------------------------------
    {
        theBasket.AddRequestSubContract(ASSET_TYPE_ID, ASSET_ACCT_ID, lSubClosingTransactionNo);

        theBasket.ReleaseSignatures();
        theBasket.SignContract(*pNym);
        theBasket.SaveContract();
        
        return true;
	}
    else
        OTLog::Error("OT_API::AddBasketExchangeItem: Failed getting next transaction number. \n");

	return false;
}

// ------------------------------------------------------





// TODO!  Either stop getting the next transaction numbers above, and do it all in a big
// loop in the next function below, OR, provide a way to harvest those numbers back again
// in the event of error (ugh.)
//





// -----------------------------------------------------
// EXCHANGE (into or out of) BASKET (request to server.)
//
void OT_API::exchangeBasket(OTIdentifier	& SERVER_ID,
							OTIdentifier	& USER_ID,
							OTIdentifier	& BASKET_ASSET_ID,
							OTString		& BASKET_INFO,
							// ----------------------------------------
							const bool bExchangeInOrOut	// exchanging in == true, out == false.
							// ----------------------------------------
							)
{
	const char * szFuncName = "OT_API::exchangeBasket";
	// -----------------------------------------------------
	OTPseudonym * pNym = this->GetOrLoadPrivateNym(USER_ID, szFuncName); // These copiously log, and ASSERT.
	if (NULL == pNym) return;
	// By this point, pNym is a good pointer, and is on the wallet. (No need to cleanup.)
	// -----------------------------------------------------
	OTServerContract *	pServer = this->GetServer(SERVER_ID, szFuncName); // This ASSERTs and logs already.
	if (NULL == pServer) return;
	// By this point, pServer is a good pointer.  (No need to cleanup.)
	// -----------------------------------------------------
	OTAssetContract * pContract = this->GetAssetType(BASKET_ASSET_ID, szFuncName);
	if (NULL == pContract) return;
	// By this point, pContract is a good pointer, and is on the wallet. (No need to cleanup.)   
	// -----------------------------------------------------------------
	const OTString strServerID(SERVER_ID), strUserID(USER_ID);

	// Next load the OTBasket object out of that contract, and load the RequestBasket object that was passed in.
	OTBasket theBasket, theRequestBasket;
        
	if (pContract->GetBasketInfo().GetLength()  && theBasket.LoadContractFromString(pContract->GetBasketInfo()) &&
        BASKET_INFO.GetLength()                 && theRequestBasket.LoadContractFromString(BASKET_INFO))
	{
        const OTIdentifier & BASKET_ASSET_ACCT_ID(theRequestBasket.GetRequestAccountID());
        // -------------------------------------------------------------------------
		OTAccount * pAccount = this->GetOrLoadAccount(*pNym, BASKET_ASSET_ACCT_ID, SERVER_ID, szFuncName);
		if (NULL == pAccount) return;
		// By this point, pAccount is a good pointer, and is on the wallet. (No need to cleanup.)
		// -----------------------------------------------------		
        // We need a transaction number just to send this thing. Plus, we need a number for
        // each sub-account to the basket, as well as the basket's main account.
        // That is: 1 + theBasket.Count() + 1
        // Total of 2, since theBasket.Count() worth of numbers were already added in the
        // calls to OT_API::AddBasketExchangeItem.
        
        if (pNym->GetTransactionNumCount(SERVER_ID) < 2)
        {
            OTLog::Output(0, "OT_API::exchangeBasket: you don't have enough transaction numbers to perform the exchange.\n");
        }
        else
        {
            long lStoredTransactionNumber=0;
            bool bGotTransNum = pNym->GetNextTransactionNum(*pNym, strServerID, lStoredTransactionNumber); // this saves
            
            if (bGotTransNum)
            {                
                // ----------------------------------------------------
                // LOAD the INBOX for the MAIN ACCOUNT
                //
                OTLedger * pInbox	= pAccount->LoadInbox(*pNym);
                OTLedger * pOutbox	= pAccount->LoadOutbox(*pNym);
                
                OTCleanup<OTLedger> theInboxAngel(pInbox);
                OTCleanup<OTLedger> theOutboxAngel(pOutbox);
                
                if (NULL == pInbox)
                {
                    OTLog::Output(0, "OT_API::exchangeBasket: Failed loading inbox!\n");
                
                    // IF FAILED, ADD TRANSACTION NUMBER BACK TO LIST OF AVAILABLE NUMBERS.
                    pNym->AddTransactionNum(*pNym, strServerID, lStoredTransactionNumber, true); // bSave=true
                }
                else if (NULL == pOutbox)
                {
                    OTLog::Output(0, "OT_API::exchangeBasket: Failed loading outbox!\n");
                    
                    // IF FAILED, ADD TRANSACTION NUMBER BACK TO LIST OF AVAILABLE NUMBERS.
                    pNym->AddTransactionNum(*pNym, strServerID, lStoredTransactionNumber, true); // bSave=true
                }
                // Set up the Request Basket! ------------------------------
                else
                {   
                    // Create a transaction
                    OTTransaction * pTransaction = 
                        OTTransaction::GenerateTransaction (USER_ID, BASKET_ASSET_ACCT_ID, SERVER_ID, 
															OTTransaction::exchangeBasket, lStoredTransactionNumber); 
                    
                    // set up the transaction item (each transaction may have multiple items...)
                    OTItem * pItem		= OTItem::CreateItemFromTransaction(*pTransaction, OTItem::exchangeBasket);
                    
                    // This pItem is where the Basket Info will be stored. (So it ends up on receipts...)                        
                    pTransaction->AddItem(*pItem); // the Transaction's destructor will cleanup the item. It "owns" it now.
					
                    // --------------------------------------------------
                    // NOTE: I'm not checking this call for success...
                    // But, I DID check the count beforehand, and I know there are enough numbers.
                    //
                    long lClosingTransactionNo = 0; // for Main Basket Acct on the Request Basket.
                    OT_ASSERT(pNym->GetNextTransactionNum(*pNym, strServerID, lClosingTransactionNo)); // this saves
                    
                    // This goes in the final API call.
                    theRequestBasket.SetClosingNum(lClosingTransactionNo); // For the basketReceipt (Closing Transaction Num) for main account.
                    // -----------------------------------------------------------
                    
                    // This goes in the final API call.
                    theRequestBasket.SetExchangingIn(bExchangeInOrOut);

                    // -----------------------------------------------------------
                    theRequestBasket.ReleaseSignatures();
                    theRequestBasket.SignContract(*pNym);
                    theRequestBasket.SaveContract();
                    
                    // Export the OTBasket object into a string, add it as
                    // a payload on my request, and send to server.
                    OTString strBasketInfo;
                    theRequestBasket.SaveContractRaw(strBasketInfo);
                    
                    //***********************************************************************
                    
                    pItem->SetAttachment(strBasketInfo);
                    
                    // sign the item. save it.
                    //
                    pItem->SignContract(*pNym);
                    pItem->SaveContract();
                    
                    //***********************************************************************
                    
                    // ---------------------------------------------
                    // BALANCE AGREEMENT!
                    //
                    // pBalanceItem is signed and saved within this call. No need to do that again.
                    OTItem * pBalanceItem = pInbox->GenerateBalanceStatement(0, // Change in balance is 0. (The accounts will all be changed, 
                            *pTransaction, *pNym, *pAccount, *pOutbox); // but basketReceipts will be used to account for it.) 
                    
                    if (NULL != pBalanceItem) // will never be NULL. Will assert above before it gets here.
                        pTransaction->AddItem(*pBalanceItem); // Better not be NULL... message will fail... But better check anyway.
                    // ---------------------------------------------
                    
                    // sign the transaction
                    pTransaction->SignContract(*pNym);
                    pTransaction->SaveContract();
                    
                    // set up the ledger
                    OTLedger theLedger(USER_ID, BASKET_ASSET_ACCT_ID, SERVER_ID);
                    theLedger.GenerateLedger(BASKET_ASSET_ACCT_ID, SERVER_ID, OTLedger::message); // bGenerateLedger defaults to false, which is correct.
                    theLedger.AddTransaction(*pTransaction);
                    
                    // sign the ledger
                    theLedger.SignContract(*pNym);
                    theLedger.SaveContract();
                    
                    // extract the ledger in ascii-armored form
                    OTString		strLedger(theLedger);
                    OTASCIIArmor	ascLedger; // I can't pass strLedger into this constructor because I want to encode it
                    
                    // Encoding...
                    ascLedger.SetString(strLedger);
                    
                    OTMessage theMessage;

                    // (0) Set up the REQUEST NUMBER and then INCREMENT IT
                    long lRequestNumber=0;
                    pNym->GetCurrentRequestNum(strServerID, lRequestNumber);
                    theMessage.m_strRequestNum.Format("%ld", lRequestNumber); // Always have to send this.
                    pNym->IncrementRequestNum(*pNym, strServerID); // since I used it for a server request, I have to increment it
                    
                    // (1) Set up member variables 
                    theMessage.m_strCommand			= "notarizeTransactions";
                    theMessage.m_strNymID			= strUserID;
                    theMessage.m_strServerID		= strServerID;
                    BASKET_ASSET_ACCT_ID.GetString(theMessage.m_strAcctID);
                    theMessage.m_ascPayload			= ascLedger;
                    
                    // (2) Sign the Message 
                    theMessage.SignContract(*pNym);		
                    
                    // (3) Save the Message (with signatures and all, back to its internal member m_strRawFile.)
                    theMessage.SaveContract();
                    
                    // (Send it)
#if defined(OT_ZMQ_MODE)
                    m_pClient->SetFocusToServerAndNym(*pServer, *pNym, &OT_API::TransportCallback);
#endif	
                    m_pClient->ProcessMessageOut(theMessage);		
                } // Inbox loaded.
            } // successfully got first transaction number.
        }
    }
}





void OT_API::getTransactionNumber(OTIdentifier & SERVER_ID,
								  OTIdentifier & USER_ID)
{
	const char * szFuncName = "OT_API::getTransactionNumber";
	// -----------------------------------------------------
	OTPseudonym * pNym = this->GetOrLoadPrivateNym(USER_ID, szFuncName); // These copiously log, and ASSERT.
	if (NULL == pNym) return;
	// By this point, pNym is a good pointer, and is on the wallet. (No need to cleanup.)
	// -----------------------------------------------------
	OTServerContract *	pServer = this->GetServer(SERVER_ID, szFuncName); // This ASSERTs and logs already.
	if (NULL == pServer) return;
	// By this point, pServer is a good pointer.  (No need to cleanup.)
	// -----------------------------------------------------
	const int nCount	= pNym->GetTransactionNumCount(SERVER_ID);
	const int nMaxCount	= 50; // todo no hardcoding. (max transaction nums allowed out at a single time.)
	if (nCount > nMaxCount) 
	{
		OTLog::vOutput(0, "OT_API::getTransactionNumber: Failure: That Nym already has "
					  "more than %d transaction numbers signed out. (Use those first.)\n", nMaxCount);
		return;
	}
	// -----------------------------------------------------
	OTMessage theMessage;
	
	if (m_pClient->ProcessUserCommand(OTClient::getTransactionNum, theMessage, 
									*pNym, *pServer,
									NULL)) // NULL pAccount on this command.
	{				
#if defined(OT_ZMQ_MODE)
		m_pClient->SetFocusToServerAndNym(*pServer, *pNym, &OT_API::TransportCallback);
#endif	
		m_pClient->ProcessMessageOut(theMessage);
	}
	else
		OTLog::Error("OT_API::getTransactionNumber: Error processing getTransactionNumber command\n");
}





void OT_API::notarizeWithdrawal(OTIdentifier	& SERVER_ID,
								OTIdentifier	& USER_ID,
								OTIdentifier	& ACCT_ID,
								OTString		& AMOUNT)
{
	const char * szFuncName = "OT_API::notarizeWithdrawal";
	// -----------------------------------------------------
	OTWallet * pWallet = this->GetWallet(szFuncName); // This logs and ASSERTs already.
	if (NULL == pWallet) return;
	// -----------------------------------------------------
	OTPseudonym * pNym = this->GetOrLoadPrivateNym(USER_ID, szFuncName); // These copiously log, and ASSERT.
	if (NULL == pNym) return;
	// By this point, pNym is a good pointer, and is on the wallet. (No need to cleanup.)
	// -----------------------------------------------------
	OTServerContract *	pServer = this->GetServer(SERVER_ID, szFuncName); // This ASSERTs and logs already.
	if (NULL == pServer) return;
	// By this point, pServer is a good pointer.  (No need to cleanup.)
	// -----------------------------------------------------
	OTAccount * pAccount = this->GetOrLoadAccount(*pNym, ACCT_ID, SERVER_ID, szFuncName);
	if (NULL == pAccount) return;
	// By this point, pAccount is a good pointer, and is on the wallet. (No need to cleanup.)
	// -----------------------------------------------------			
	OTIdentifier	CONTRACT_ID;
	OTString		strContractID, strServerID(SERVER_ID);
	// -----------------------------------------------------
	CONTRACT_ID = pAccount->GetAssetTypeID();
	CONTRACT_ID.GetString(strContractID);	
	// --------------------------------------------------------------------
	if (false == OTDB::Exists(OTLog::MintFolder(), strServerID.Get(), strContractID.Get()))
	{
		OTLog::vError("OT_API::notarizeWithdrawal: File does not exist: %s%s%s%s%s\n", 
					  OTLog::MintFolder(), OTLog::PathSeparator(), strServerID.Get(),
					  OTLog::PathSeparator(), strContractID.Get());
		return;
	}
	// --------------------------------------------------------------------
	
	OTMint theMint(strServerID, strContractID); // <=================
	
	// -----------------------------------------------------------------	
	OTMessage theMessage;
	
	long lRequestNumber = 0;
	
	const	long lTotalAmount	= atol(AMOUNT.Get());
			long lAmount		= lTotalAmount;
	
	OTString strNymID(USER_ID), strFromAcct(ACCT_ID);
	
	long lStoredTransactionNumber=0;
	bool bGotTransNum = false;
	// ---------------------------------------------
	OTLedger * pInbox	= pAccount->LoadInbox(*pNym);
	OTLedger * pOutbox	= pAccount->LoadOutbox(*pNym);
	
	OTCleanup<OTLedger> theInboxAngel(pInbox);
	OTCleanup<OTLedger> theOutboxAngel(pOutbox);
	
	if (NULL == pInbox)
	{
		OTLog::Output(0, "OT_API::notarizeWithdrawal: Failed loading inbox!\n");
	}
	else if (NULL == pOutbox)
	{
		OTLog::Output(0, "OT_API::notarizeWithdrawal: Failed loading outbox!\n");
	}
	else if (bGotTransNum = pNym->GetNextTransactionNum(*pNym, strServerID, lStoredTransactionNumber))
	{
		// Create a transaction
		OTTransaction * pTransaction = OTTransaction::GenerateTransaction (USER_ID, ACCT_ID, SERVER_ID, 
																		   OTTransaction::withdrawal, lStoredTransactionNumber); 
		// set up the transaction item (each transaction may have multiple items...)
		OTItem * pItem		= OTItem::CreateItemFromTransaction(*pTransaction, OTItem::withdrawal);
		pItem->SetAmount(lTotalAmount);
//		pItem->m_lAmount	= atol(strAmount.Get());
		OTString strNote("Gimme cash!");  // TODO: Note is unnecessary for cash withdrawal. Research uses / risks.
		pItem->SetNote(strNote);
		// -------------------------------------
		const OTPseudonym * pServerNym = pServer->GetContractPublicNym();
		
		const OTIdentifier SERVER_USER_ID(*pServerNym);
		// -----------------------------------------------------------------
		if ((NULL != pServerNym) && 
			theMint.LoadMint() && 
			theMint.VerifyMint((OTPseudonym&)*pServerNym))
		{
			OTPurse * pPurse		= new OTPurse(SERVER_ID, CONTRACT_ID, SERVER_USER_ID);
			OTPurse * pPurseMyCopy	= new OTPurse(SERVER_ID, CONTRACT_ID, USER_ID);
			
			// Create all the necessary tokens for the withdrawal amount.
			// Push copies of each token into a purse to be sent to the server,
			// as well as a purse to be kept for unblinding when we receive the
			// server response.  (Coin private unblinding keys are not sent to
			// the server, obviously.)
			long lTokenAmount = 0;
			while (lTokenAmount = theMint.GetLargestDenomination(lAmount))
			{
				lAmount -= lTokenAmount;
				
				// Create the relevant token request with same server/asset ID as the purse.
				// the purse does NOT own the token at this point. the token's constructor
				// just uses it to copy some IDs, since they must match.
				OTToken theToken(*pPurse);
				
				// GENERATE new token, sign it and save it. 
				theToken.GenerateTokenRequest(*pNym, theMint, lTokenAmount);
				theToken.SignContract(*pNym);
				theToken.SaveContract();
				
				// Now the proto-token is generated, let's add it to a purse
				// By pushing theToken into pPurse with *pServerNym, I encrypt it to pServerNym.
				// So now only the server Nym can decrypt that token and pop it out of that purse.
				pPurse->Push(*pServerNym, theToken);	
				
				// I'm saving my own copy of all this, encrypted to my nym
				// instead of the server's, so I can get to my private coin data.
				// The server's copy of theToken is already Pushed, so I can re-use
				// the variable now for my own purse.
				theToken.ReleaseSignatures();
				theToken.SetSavePrivateKeys(); // This time it will save the private keys when I sign it
				theToken.SignContract(*pNym);
				theToken.SaveContract();
				
				pPurseMyCopy->Push(*pNym, theToken);// Now my copy of the purse has a version of the token,
			}
			// --------------------------------
			// Save the purse into a string...
			OTString strPurse;
			pPurse->SignContract(*pNym);
			pPurse->SaveContract();			
			pPurse->SaveContractRaw(strPurse);
			
			// Add the purse string as the attachment on the transaction item.
			pItem->SetAttachment(strPurse); // The purse is contained in the reference string.
			// --------------------------------------
			pPurseMyCopy->SignContract(*pNym);		// encrypted to me instead of the server, and including 
			pPurseMyCopy->SaveContract();			// the private keys for unblinding the server response.
			// This thing is neat and tidy. The wallet can just save it as an ascii-armored string as a
			// purse field inside the wallet file.  It doesn't do that for now (TODO) but it easily could.			
			// --------------------------------------
			// Add the purse to the wallet
			// (We will need it to look up the private coin info for unblinding the token,
			//  when the response comes from the server.)
			pWallet->AddPendingWithdrawal(*pPurseMyCopy);
			
			delete pPurse;
			pPurse			= NULL; // We're done with this one.
			pPurseMyCopy	= NULL; // The wallet owns my copy now and will handle cleaning it up.
			
			// --------------------------------------
			// sign the item
			pItem->SignContract(*pNym);
			pItem->SaveContract();
			
			pTransaction->AddItem(*pItem); // the Transaction's destructor will cleanup the item. It "owns" it now.
			// ---------------------------------------------
			// BALANCE AGREEMENT
			
			// pBalanceItem is signed and saved within this call. No need to do that again.
			OTItem * pBalanceItem = pInbox->GenerateBalanceStatement(lTotalAmount*(-1), *pTransaction, *pNym, *pAccount, *pOutbox);
			
			if (NULL != pBalanceItem) // will never be NULL. Will assert above before it gets here.
				pTransaction->AddItem(*pBalanceItem); // Better not be NULL... message will fail... But better check anyway.
			// ---------------------------------------------
			
			// sign the transaction
			pTransaction->SignContract(*pNym);
			pTransaction->SaveContract();
			
			// set up the ledger
			OTLedger theLedger(USER_ID, ACCT_ID, SERVER_ID);
			theLedger.GenerateLedger(ACCT_ID, SERVER_ID, OTLedger::message); // bGenerateLedger defaults to false, which is correct.
			theLedger.AddTransaction(*pTransaction);
			
			// sign the ledger
			theLedger.SignContract(*pNym);
			theLedger.SaveContract();
			
			// extract the ledger in ascii-armored form
			OTString		strLedger(theLedger);
			OTASCIIArmor	ascLedger; // I can't pass strLedger into this constructor because I want to encode it
			
			// Encoding...
			ascLedger.SetString(strLedger);
			// -----------------------------------------------------
			// (0) Set up the REQUEST NUMBER and then INCREMENT IT
			pNym->GetCurrentRequestNum(strServerID, lRequestNumber);
			theMessage.m_strRequestNum.Format("%ld", lRequestNumber); // Always have to send this.
			pNym->IncrementRequestNum(*pNym, strServerID); // since I used it for a server request, I have to increment it
			
			// (1) Set up member variables 
			theMessage.m_strCommand			= "notarizeTransactions";
			theMessage.m_strNymID			= strNymID;
			theMessage.m_strServerID		= strServerID;
			theMessage.m_strAcctID			= strFromAcct;
			theMessage.m_ascPayload			= ascLedger;
			
			// (2) Sign the Message 
			theMessage.SignContract(*pNym);		
			
			// (3) Save the Message (with signatures and all, back to its internal member m_strRawFile.)
			theMessage.SaveContract();
			
			// (Send it)
#if defined(OT_ZMQ_MODE)
			m_pClient->SetFocusToServerAndNym(*pServer, *pNym, &OT_API::TransportCallback);
#endif	
			m_pClient->ProcessMessageOut(theMessage);	
		}
		else 
		{
			// IF FAILED, ADD TRANSACTION NUMBER BACK TO LIST OF AVAILABLE NUMBERS.
			pNym->AddTransactionNum(*pNym, strServerID, lStoredTransactionNumber, true); // bSave=true								
		}
	}
	else 
	{
		OTLog::Output(0, "No Transaction Numbers were available. Suggest requesting the server for a new one.\n");
	}
}





void OT_API::notarizeDeposit(OTIdentifier	& SERVER_ID,
							 OTIdentifier	& USER_ID,
							 OTIdentifier	& ACCT_ID,
							 OTString		& THE_PURSE)
{
	const char * szFuncName = "OT_API::notarizeDeposit";
	// -----------------------------------------------------
	OTPseudonym * pNym = this->GetOrLoadPrivateNym(USER_ID, szFuncName); // These copiously log, and ASSERT.
	if (NULL == pNym) return;
	// By this point, pNym is a good pointer, and is on the wallet. (No need to cleanup.)
	// -----------------------------------------------------
	OTServerContract *	pServer = this->GetServer(SERVER_ID, szFuncName); // This ASSERTs and logs already.
	if (NULL == pServer) return;
	// By this point, pServer is a good pointer.  (No need to cleanup.)
	// -----------------------------------------------------
	OTAccount * pAccount = this->GetOrLoadAccount(*pNym, ACCT_ID, SERVER_ID, szFuncName);
	if (NULL == pAccount) return;
	// By this point, pAccount is a good pointer, and is on the wallet. (No need to cleanup.)
	// -----------------------------------------------------			
	OTIdentifier	CONTRACT_ID;
	OTString		strContractID;
	
	CONTRACT_ID = pAccount->GetAssetTypeID();
	CONTRACT_ID.GetString(strContractID);
	// -----------------------------------------------------------------
	OTMessage theMessage;
	long lRequestNumber = 0;
	
	OTString strServerID(SERVER_ID), strNymID(USER_ID), strFromAcct(ACCT_ID);
		
	const OTPseudonym * pServerNym = pServer->GetContractPublicNym();
	const OTIdentifier SERVER_USER_ID(*pServerNym);
	// ------------------------------------------------
	OTPurse thePurse(SERVER_ID, CONTRACT_ID, SERVER_USER_ID);
	
	long lStoredTransactionNumber=0;
	bool bGotTransNum = false;
	// ---------------------------------------------
	OTLedger * pInbox	= pAccount->LoadInbox(*pNym);
	OTLedger * pOutbox	= pAccount->LoadOutbox(*pNym);
	
	OTCleanup<OTLedger> theInboxAngel(pInbox);
	OTCleanup<OTLedger> theOutboxAngel(pOutbox);
	
	if (NULL == pInbox)
		OTLog::vOutput(0, "OT_API::notarizeDeposit: Failed loading inbox for acct %s\n",
					   strFromAcct.Get());
	else if (NULL == pOutbox)
		OTLog::vOutput(0, "OT_API::notarizeDeposit: Failed loading outbox for acct %s\n",
					   strFromAcct.Get());	
	else if (!(bGotTransNum = pNym->GetNextTransactionNum(*pNym, strServerID, lStoredTransactionNumber)))
		OTLog::Output(0, "OT_API::notarizeDeposit: No Transaction Numbers were available. Try requesting the server for a new one.\n");
	// -----------------------------------------
	else if (NULL != pServerNym)
	{
		bool bSuccess = false;
		
		// Create a transaction
		OTTransaction * pTransaction = OTTransaction::GenerateTransaction (USER_ID, ACCT_ID, SERVER_ID, 
																		   OTTransaction::deposit, lStoredTransactionNumber); 
		// set up the transaction item (each transaction may have multiple items...)
		OTItem * pItem	= OTItem::CreateItemFromTransaction(*pTransaction, OTItem::deposit);
		
		OTPurse theSourcePurse(thePurse);
		
		if (theSourcePurse.LoadContractFromString(THE_PURSE))
			while (!theSourcePurse.IsEmpty()) 
			{
				OTToken * pToken = theSourcePurse.Pop(*pNym);
				
				if (pToken)
				{
					// TODO need 2-recipient envelopes. My request to the server is encrypted to the server's nym,
					// but it should be encrypted to my Nym also, so both have access to decrypt it.
					
					// Now the token is ready, let's add it to a purse
					// By pushing theToken into thePurse with *pServerNym, I encrypt it to pServerNym.
					// So now only the server Nym can decrypt that token and pop it out of that purse.
					if (false == pToken->ReassignOwnership(*pNym, *pServerNym))
					{
						OTLog::Error("OT_API::notarizeDeposit: Error re-assigning ownership of token (to server.)\n");
						delete pToken;
						pToken = NULL;
						bSuccess = false;
						break;
					}
					else 
					{
						OTLog::vOutput(3, "OT_API::notarizeDeposit: Success re-assigning ownership of token (to server.)\n");
						
						bSuccess = true;
						
						pToken->ReleaseSignatures();
						pToken->SignContract(*pNym);
						pToken->SaveContract();
						
						thePurse.Push(*pServerNym, *pToken);
						
						long lTemp = pItem->GetAmount();
						pItem->SetAmount(lTemp += pToken->GetDenomination());
					}
					delete pToken;
					pToken = NULL;
				}
				else 
				{
					OTLog::Error("Error loading token from purse.\n");
					break;
				}
			} // while
		
		if (bSuccess)
		{
			// Save the purse into a string...
			OTString strPurse;
			thePurse.SignContract(*pNym);
			thePurse.SaveContract();
			thePurse.SaveContractRaw(strPurse);
			
			// Add the purse string as the attachment on the transaction item.
			pItem->SetAttachment(strPurse); // The purse is contained in the reference string.
			
			// sign the item
			pItem->SignContract(*pNym);
			pItem->SaveContract();
			
			// the Transaction "owns" the item now and will handle cleaning it up.
			pTransaction->AddItem(*pItem); // the Transaction's destructor will cleanup the item. It "owns" it now.
			
			// ---------------------------------------------
			// BALANCE AGREEMENT
			//
			// pBalanceItem is signed and saved within this call. No need to do that again.
			OTItem * pBalanceItem = pInbox->GenerateBalanceStatement(pItem->GetAmount(), *pTransaction, *pNym, *pAccount, *pOutbox);
			
			if (NULL != pBalanceItem) // will never be NULL. Will assert above before it gets here.
				pTransaction->AddItem(*pBalanceItem); // Better not be NULL... message will fail... But better check anyway.
			// ---------------------------------------------
			
			// sign the transaction
			pTransaction->SignContract(*pNym);
			pTransaction->SaveContract();
			
			// set up the ledger
			OTLedger theLedger(USER_ID, ACCT_ID, SERVER_ID);
			theLedger.GenerateLedger(ACCT_ID, SERVER_ID, OTLedger::message); // bGenerateLedger defaults to false, which is correct.
			theLedger.AddTransaction(*pTransaction); // now the ledger "owns" and will handle cleaning up the transaction.
			
			// sign the ledger
			theLedger.SignContract(*pNym);
			theLedger.SaveContract();
			
			// extract the ledger in ascii-armored form... encoding...
			OTString		strLedger(theLedger);
			OTASCIIArmor	ascLedger(strLedger);
			
			// (0) Set up the REQUEST NUMBER and then INCREMENT IT
			pNym->GetCurrentRequestNum(strServerID, lRequestNumber);
			theMessage.m_strRequestNum.Format("%ld", lRequestNumber); // Always have to send this.
			pNym->IncrementRequestNum(*pNym, strServerID); // since I used it for a server request, I have to increment it
			
			// (1) Set up member variables 
			theMessage.m_strCommand			= "notarizeTransactions";
			theMessage.m_strNymID			= strNymID;
			theMessage.m_strServerID		= strServerID;
			theMessage.m_strAcctID			= strFromAcct;
			theMessage.m_ascPayload			= ascLedger;
			
			// (2) Sign the Message 
			theMessage.SignContract(*pNym);		
			
			// (3) Save the Message (with signatures and all, back to its internal member m_strRawFile.)
			theMessage.SaveContract();
			
			// (Send it)
#if defined(OT_ZMQ_MODE)
			m_pClient->SetFocusToServerAndNym(*pServer, *pNym, &OT_API::TransportCallback);
#endif	
			m_pClient->ProcessMessageOut(theMessage);	
			
		} // bSuccess
		else 
		{
			delete pItem;		pItem = NULL;
			delete pTransaction;pTransaction = NULL;
			
			// IF FAILED, ADD TRANSACTION NUMBER BACK TO LIST OF AVAILABLE NUMBERS.
			pNym->AddTransactionNum(*pNym, strServerID, lStoredTransactionNumber, true); // bSave=true								
		}
	} // if (pServerNym)
}



void OT_API::withdrawVoucher(OTIdentifier	& SERVER_ID,
							 OTIdentifier	& USER_ID,
							 OTIdentifier	& ACCT_ID,
							 OTIdentifier	& RECIPIENT_USER_ID,
							 OTString		& CHEQUE_MEMO,
							 OTString		& AMOUNT)
{
	const char * szFuncName = "OT_API::withdrawVoucher";
	// -----------------------------------------------------
	OTPseudonym * pNym = this->GetOrLoadPrivateNym(USER_ID, szFuncName); // These copiously log, and ASSERT.
	if (NULL == pNym) return;
	// By this point, pNym is a good pointer, and is on the wallet. (No need to cleanup.)
	// -----------------------------------------------------
	OTServerContract *	pServer = this->GetServer(SERVER_ID, szFuncName); // This ASSERTs and logs already.
	if (NULL == pServer) return;
	// By this point, pServer is a good pointer.  (No need to cleanup.)
	// -----------------------------------------------------
	OTAccount * pAccount = this->GetOrLoadAccount(*pNym, ACCT_ID, SERVER_ID, szFuncName);
	if (NULL == pAccount) return;
	// By this point, pAccount is a good pointer, and is on the wallet. (No need to cleanup.)
	// -----------------------------------------------------				
	OTIdentifier	CONTRACT_ID;
	OTString		strContractID;

	CONTRACT_ID = pAccount->GetAssetTypeID();
	CONTRACT_ID.GetString(strContractID);
	// -----------------------------------------------------------------
	OTMessage theMessage;
	
	const long lAmount = atol(AMOUNT.Get());
	
	OTString strServerID(SERVER_ID), strNymID(USER_ID), strFromAcct(ACCT_ID);
	
	long lStoredTransactionNumber=0;
	bool bGotTransNum = pNym->GetNextTransactionNum(*pNym, strServerID, lStoredTransactionNumber);
	
	if (bGotTransNum)
	{
		const OTString strChequeMemo(CHEQUE_MEMO);
		const OTString strRecipientUserID(RECIPIENT_USER_ID);
		// -----------------------------------------------------------------------
		
		// Expiration (ignored by server -- it sets its own for its vouchers.)
		const	time_t	VALID_FROM	= time(NULL); // This time is set to TODAY NOW
		const	time_t	VALID_TO	= VALID_FROM + 15552000; // 6 months.
		// -----------------------------------------------------------------------
		// The server only uses the memo, amount, and recipient from this cheque when it
		// constructs the actual voucher.
		OTCheque theRequestVoucher(SERVER_ID, CONTRACT_ID);
		bool bIssueCheque = theRequestVoucher.IssueCheque(lAmount, lStoredTransactionNumber,// server actually ignores this and supplies its own transaction number for any voucher.
														  VALID_FROM, VALID_TO, ACCT_ID, USER_ID, strChequeMemo,
														  (strRecipientUserID.GetLength() > 2) ? &(RECIPIENT_USER_ID) : NULL);
		// --------------------------------------------------
		OTLedger * pInbox	= pAccount->LoadInbox(*pNym);
		OTLedger * pOutbox	= pAccount->LoadOutbox(*pNym);
		
		OTCleanup<OTLedger> theInboxAngel(pInbox);
		OTCleanup<OTLedger> theOutboxAngel(pOutbox);
		
		if (NULL == pInbox)
		{
			OTLog::vOutput(0, "OT_API::withdrawVoucher: Failed loading inbox for acct %s\n", strFromAcct.Get());
			
			// IF FAILED, ADD TRANSACTION NUMBER BACK TO LIST OF AVAILABLE NUMBERS.
			pNym->AddTransactionNum(*pNym, strServerID, lStoredTransactionNumber, true); // bSave=true								
		}
		
		else if (NULL == pOutbox)
		{
			OTLog::vOutput(0, "OT_API::withdrawVoucher: Failed loading outbox for acct %s\n", strFromAcct.Get());
			
			// IF FAILED, ADD TRANSACTION NUMBER BACK TO LIST OF AVAILABLE NUMBERS.
			pNym->AddTransactionNum(*pNym, strServerID, lStoredTransactionNumber, true); // bSave=true								
		}
		else if (!bIssueCheque)
		{
			// IF FAILED, ADD TRANSACTION NUMBER BACK TO LIST OF AVAILABLE NUMBERS.
			pNym->AddTransactionNum(*pNym, strServerID, lStoredTransactionNumber, true); // bSave=true								
		}
		else 
		{
			// Create a transaction
			OTTransaction * pTransaction = OTTransaction::GenerateTransaction (USER_ID, ACCT_ID, SERVER_ID, 
																			   OTTransaction::withdrawal, lStoredTransactionNumber); 
			// set up the transaction item (each transaction may have multiple items...)
			OTItem * pItem		= OTItem::CreateItemFromTransaction(*pTransaction, OTItem::withdrawVoucher);
			pItem->SetAmount(lAmount);
			OTString strNote("Withdraw Voucher: ");
			pItem->SetNote(strNote);
			
			// Add the voucher request string as the attachment on the transaction item.
			theRequestVoucher.SignContract(*pNym);
			theRequestVoucher.SaveContract();
			OTString strVoucher(theRequestVoucher);
			pItem->SetAttachment(strVoucher); // The voucher request is contained in the reference string.
			
			// sign the item
			pItem->SignContract(*pNym);
			pItem->SaveContract();
			
			pTransaction->AddItem(*pItem); // the Transaction's destructor will cleanup the item. It "owns" it now.
			// ---------------------------------------------
			// BALANCE AGREEMENT 
			//
			// The item is signed and saved within this call as well. No need to do that again.
			OTItem * pBalanceItem = pInbox->GenerateBalanceStatement(lAmount*(-1), *pTransaction, *pNym, *pAccount, *pOutbox);
			
			if (NULL != pBalanceItem)
				pTransaction->AddItem(*pBalanceItem); // Better not be NULL... message will fail... But better check anyway.
			// ---------------------------------------------
			// sign the transaction
			pTransaction->SignContract(*pNym);
			pTransaction->SaveContract();
			
			// set up the ledger
			OTLedger theLedger(USER_ID, ACCT_ID, SERVER_ID);
			theLedger.GenerateLedger(ACCT_ID, SERVER_ID, OTLedger::message); // bGenerateLedger defaults to false, which is correct.
			theLedger.AddTransaction(*pTransaction);
			
			// sign the ledger
			theLedger.SignContract(*pNym);
			theLedger.SaveContract();
			
			// extract the ledger in ascii-armored form
			OTString		strLedger(theLedger);
			OTASCIIArmor	ascLedger(strLedger);
			
			long lRequestNumber = 0;
			
			// (0) Set up the REQUEST NUMBER and then INCREMENT IT
			pNym->GetCurrentRequestNum(strServerID, lRequestNumber);
			theMessage.m_strRequestNum.Format("%ld", lRequestNumber); // Always have to send this.
			pNym->IncrementRequestNum(*pNym, strServerID); // since I used it for a server request, I have to increment it
			
			// (1) Set up member variables 
			theMessage.m_strCommand			= "notarizeTransactions";
			theMessage.m_strNymID			= strNymID;
			theMessage.m_strServerID		= strServerID;
			theMessage.m_strAcctID			= strFromAcct;
			theMessage.m_ascPayload			= ascLedger;
			
			// (2) Sign the Message 
			theMessage.SignContract(*pNym);		
			
			// (3) Save the Message (with signatures and all, back to its internal member m_strRawFile.)
			theMessage.SaveContract();
			
			// (Send it)
#if defined(OT_ZMQ_MODE)
			m_pClient->SetFocusToServerAndNym(*pServer, *pNym, &OT_API::TransportCallback);
#endif	
			m_pClient->ProcessMessageOut(theMessage);	
		}
	}
	else 
		OTLog::Output(0, "No Transaction Numbers were available. Suggest requesting the server for a new one.\n");
}












// ------------------------------------------------------------------------
//
// DISCARD CHEQUE (recover the transaction number for re-use, so the cheque 
// can be discarded.)
//

bool OT_API::DiscardCheque(OTIdentifier	& SERVER_ID,
						   OTIdentifier	& USER_ID,
						   OTIdentifier	& ACCT_ID,
						   OTString		& THE_CHEQUE)
{
	const char * szFuncName = "OT_API::DiscardCheque";
	// -----------------------------------------------------
	OTPseudonym * pNym = this->GetOrLoadPrivateNym(USER_ID, szFuncName); // These copiously log, and ASSERT.
	if (NULL == pNym) return false;
	// By this point, pNym is a good pointer, and is on the wallet. (No need to cleanup.)
	// -----------------------------------------------------
	OTServerContract *	pServer = this->GetServer(SERVER_ID, szFuncName); // This ASSERTs and logs already.
	if (NULL == pServer) return false;
	// By this point, pServer is a good pointer.  (No need to cleanup.)
	// -----------------------------------------------------
	OTAccount * pAccount = this->GetOrLoadAccount(*pNym, ACCT_ID, SERVER_ID, szFuncName);
	if (NULL == pAccount) return false;
	// By this point, pAccount is a good pointer, and is on the wallet. (No need to cleanup.)
	// -----------------------------------------------------				
	OTIdentifier	CONTRACT_ID;
	OTString		strContractID;

	CONTRACT_ID = pAccount->GetAssetTypeID();
	CONTRACT_ID.GetString(strContractID);
	// -----------------------------------------------------------------
	// By this point, pNym is a good pointer, and is on the wallet.
	//  (No need to cleanup.)  pServer and pAccount are also good.
	// 
	// -----------------------------------------------------------------
	const OTString strServerID(SERVER_ID), strNymID(USER_ID);
	
	OTCheque theCheque(SERVER_ID, CONTRACT_ID);
	
	if (!theCheque.LoadContractFromString(THE_CHEQUE))
	{
		OTLog::vOutput(0, "OT_API::DiscardCheque: Unable to load cheque from string. Sorry. Cheque contents:\n\n%s\n\n",
					   THE_CHEQUE.Get());
		return false;								
	}
	else if ((theCheque.GetServerID()		== SERVER_ID) && 
			 (theCheque.GetAssetID()		== CONTRACT_ID) && 
			 (theCheque.GetSenderUserID()	== USER_ID) && 
			 (theCheque.GetSenderAcctID()	== ACCT_ID))
	{
		if (pNym->VerifyIssuedNum(strServerID, theCheque.GetTransactionNum())) // we only "add it back" if it was really there in the first place.
		{
			pNym->AddTransactionNum(*pNym, strServerID, theCheque.GetTransactionNum(), true); // bSave=true
			return true;
		}
		else // No point adding it back as available to use, if pNym doesn't even have it signed out! 
		{
			OTLog::vOutput(0, "OT_API::discardCheque: Failed attempt to claw back a transaction number that wasn't signed "
						   "out to pNym in the first place. Cheque contents:\n\n%s\n\n", THE_CHEQUE.Get());
			return false;
		}
	} // bSuccess
	else
		OTLog::vOutput(0, "OT_API::discardCheque: Unable to verify cheque's server ID, asset type ID, user ID, or acct ID. "
					   "Sorry. Cheque contents:\n\n%s\n\n", THE_CHEQUE.Get());
	return false;
}




// ----------------------------------------------------------------
// DEPOSIT CHEQUE
//

void OT_API::depositCheque(OTIdentifier	& SERVER_ID,
						   OTIdentifier	& USER_ID,
						   OTIdentifier	& ACCT_ID,
						   OTString		& THE_CHEQUE)
{
	const char * szFuncName = "OT_API::depositCheque";
	// -----------------------------------------------------
	OTPseudonym * pNym = this->GetOrLoadPrivateNym(USER_ID, szFuncName); // These copiously log, and ASSERT.
	if (NULL == pNym) return;
	// By this point, pNym is a good pointer, and is on the wallet. (No need to cleanup.)
	// -----------------------------------------------------
	OTServerContract *	pServer = this->GetServer(SERVER_ID, szFuncName); // This ASSERTs and logs already.
	if (NULL == pServer) return;
	// By this point, pServer is a good pointer.  (No need to cleanup.)
	// -----------------------------------------------------
	OTAccount * pAccount = this->GetOrLoadAccount(*pNym, ACCT_ID, SERVER_ID, szFuncName);
	if (NULL == pAccount) return;
	// By this point, pAccount is a good pointer, and is on the wallet. (No need to cleanup.)
	// -----------------------------------------------------				
	OTIdentifier	CONTRACT_ID;
	OTString		strContractID;
	CONTRACT_ID = pAccount->GetAssetTypeID();
	CONTRACT_ID.GetString(strContractID);
	// -----------------------------------------------------------------
	OTMessage theMessage;
	long lRequestNumber = 0;
	
	OTString strServerID(SERVER_ID), strNymID(USER_ID), strFromAcct(ACCT_ID);
	
	OTCheque theCheque(SERVER_ID, CONTRACT_ID);
	
	long lStoredTransactionNumber=0;
	bool bGotTransNum = pNym->GetNextTransactionNum(*pNym, strServerID, lStoredTransactionNumber);
	
	if (!bGotTransNum)
		OTLog::Output(0, "OT_API::depositCheque: No Transaction Numbers were available. Try requesting the server for a new one.\n");
	else if (!theCheque.LoadContractFromString(THE_CHEQUE))
	{
		OTLog::vOutput(0, "OT_API::depositCheque: Unable to load cheque from string. Sorry. Contents:\n\n%s\n\n",
					   THE_CHEQUE.Get());
		// IF FAILED, ADD TRANSACTION NUMBER BACK TO LIST OF AVAILABLE NUMBERS.
		pNym->AddTransactionNum(*pNym, strServerID, lStoredTransactionNumber, true); // bSave=true								
	}
	else 
	{
		// Create a transaction
		OTTransaction * pTransaction = OTTransaction::GenerateTransaction (USER_ID, ACCT_ID, SERVER_ID, 
																		   OTTransaction::deposit, lStoredTransactionNumber);
		// set up the transaction item (each transaction may have multiple items...)
		OTItem * pItem		= OTItem::CreateItemFromTransaction(*pTransaction, OTItem::depositCheque);
		
		OTString strNote("Deposit this cheque, please!"); // todo
		pItem->SetNote(strNote);
		
		OTString strCheque(theCheque);
		
		// Add the cheque string as the attachment on the transaction item.
		pItem->SetAttachment(strCheque); // The cheque is contained in the reference string.
		
		// sign the item
		pItem->SignContract(*pNym);
		pItem->SaveContract();
		
		// the Transaction "owns" the item now and will handle cleaning it up.
		pTransaction->AddItem(*pItem); // the Transaction's destructor will cleanup the item. It "owns" it now.
		// ---------------------------------------------
		OTLedger * pInbox	= pAccount->LoadInbox(*pNym);
		OTLedger * pOutbox	= pAccount->LoadOutbox(*pNym);
		
		OTCleanup<OTLedger> theInboxAngel(pInbox);
		OTCleanup<OTLedger> theOutboxAngel(pOutbox);
		
		if (NULL == pInbox)
		{
			OTLog::vOutput(0, "OT_API::depositCheque: Failed loading inbox for acct %s\n", strFromAcct.Get());
			// IF FAILED, ADD TRANSACTION NUMBER BACK TO LIST OF AVAILABLE NUMBERS.
			pNym->AddTransactionNum(*pNym, strServerID, lStoredTransactionNumber, true); // bSave=true								
		}
		else if (NULL == pOutbox)
		{
			OTLog::vOutput(0, "OT_API::depositCheque: Failed loading outbox for acct %s\n", strFromAcct.Get());
			// IF FAILED, ADD TRANSACTION NUMBER BACK TO LIST OF AVAILABLE NUMBERS.
			pNym->AddTransactionNum(*pNym, strServerID, lStoredTransactionNumber, true); // bSave=true				
		}
		else 
		{
			// BALANCE AGREEMENT 
			// ---------------------------------------------
			// pBalanceItem is signed and saved within this call. No need to do that twice.
			OTItem * pBalanceItem = pInbox->GenerateBalanceStatement(theCheque.GetAmount(), *pTransaction, *pNym, *pAccount, *pOutbox);
			
			if (NULL != pBalanceItem) // will never be NULL. Will assert above before it gets here.
				pTransaction->AddItem(*pBalanceItem); // Better not be NULL... message will fail... But better check anyway.
			// ---------------------------------------------
			// sign the transaction
			pTransaction->SignContract(*pNym);
			pTransaction->SaveContract();
			
			// set up the ledger
			OTLedger theLedger(USER_ID, ACCT_ID, SERVER_ID);
			theLedger.GenerateLedger(ACCT_ID, SERVER_ID, OTLedger::message); // bGenerateLedger defaults to false, which is correct.
			theLedger.AddTransaction(*pTransaction); // now the ledger "owns" and will handle cleaning up the transaction.
			
			// sign the ledger
			theLedger.SignContract(*pNym);
			theLedger.SaveContract();
			
			// extract the ledger in ascii-armored form... encoding...
			OTString		strLedger(theLedger);
			OTASCIIArmor	ascLedger(strLedger);
			
			// (0) Set up the REQUEST NUMBER and then INCREMENT IT
			pNym->GetCurrentRequestNum(strServerID, lRequestNumber);
			theMessage.m_strRequestNum.Format("%ld", lRequestNumber); // Always have to send this.
			pNym->IncrementRequestNum(*pNym, strServerID); // since I used it for a server request, I have to increment it
			
			// (1) Set up member variables 
			theMessage.m_strCommand			= "notarizeTransactions";
			theMessage.m_strNymID			= strNymID;
			theMessage.m_strServerID		= strServerID;
			theMessage.m_strAcctID			= strFromAcct;
			theMessage.m_ascPayload			= ascLedger;
			
			// (2) Sign the Message 
			theMessage.SignContract(*pNym);		
			
			// (3) Save the Message (with signatures and all, back to its internal member m_strRawFile.)
			theMessage.SaveContract();
			
			// (Send it)
#if defined(OT_ZMQ_MODE)
			m_pClient->SetFocusToServerAndNym(*pServer, *pNym, &OT_API::TransportCallback);
#endif	
			m_pClient->ProcessMessageOut(theMessage);
		}
	} // bSuccess
}





// ----------------------------------------------------------------
// DEPOSIT PAYMENT PLAN
//
// The Recipient Creates the Payment Plan using ProposePaymentPlan.
// Then the sender Confirms it using ConfirmPaymentPlan.
// Both of the above steps involve attaching transaction numbers to
// the payment plan and signing copies of it.
// This function here is the final step, where the payment plan
// contract is now being deposited by the customer (who is also
// the sender), in a message to the server.
//
void OT_API::depositPaymentPlan(const OTIdentifier	& SERVER_ID,
								const OTIdentifier	& USER_ID,
								const OTString		& THE_PAYMENT_PLAN)
{
	const char * szFuncName = "OT_API::depositPaymentPlan";
	// -----------------------------------------------------
	OTServerContract *	pServer = this->GetServer(SERVER_ID, szFuncName); // This ASSERTs and logs already.
	if (NULL == pServer) return;
	// By this point, pServer is a good pointer.  (No need to cleanup.)
	// -----------------------------------------------------------------
	OTPseudonym * pNym = this->GetOrLoadPrivateNym(USER_ID, szFuncName); // This ASSERTs and logs already.
	if (NULL == pNym) return;
	// By this point, pNym is a good pointer.  (No need to cleanup.)
	// -----------------------------------------------------------------
	OTPaymentPlan	thePlan;
	OTMessage		theMessage;
	long			lRequestNumber = 0;
	
	const OTString strServerID(SERVER_ID), strNymID(USER_ID);
	
	if (thePlan.LoadContractFromString(THE_PAYMENT_PLAN) &&
		thePlan.VerifySignature(*pNym))
	{
		const OTIdentifier	SENDER_ACCT_ID(thePlan.GetSenderAcctID());
//		const OTIdentifier	SENDER_USER_ID(thePlan.GetSenderUserID());
		const OTString		strFromAcct(SENDER_ACCT_ID);
		// -----------------------------------------------------
		OTAccount * pAccount = this->GetOrLoadAccount(*pNym,			SENDER_ACCT_ID, SERVER_ID, szFuncName);
//		OTAccount * pAccount = this->GetOrLoadAccount(SENDER_USER_ID,	SENDER_ACCT_ID, SERVER_ID, szFuncName);
		if (NULL == pAccount) return;
		// By this point, pAccount is a good pointer and in the wallet. 
		// (No need to cleanup.) I also know it has the right Server ID
		// and that the Nym owns it, and has signed it, etc.
		// -----------------------------------------------------
		
		// Create a transaction
		OTTransaction * pTransaction = OTTransaction::GenerateTransaction (USER_ID, SENDER_ACCT_ID, SERVER_ID, 
																		   OTTransaction::paymentPlan, thePlan.GetTransactionNum()); 
		// set up the transaction item (each transaction may have multiple items...)
		OTItem * pItem		= OTItem::CreateItemFromTransaction(*pTransaction, OTItem::paymentPlan);
		
		OTString strPlan(thePlan);
		
		// Add the payment plan string as the attachment on the transaction item.
		pItem->SetAttachment(strPlan); // The payment plan is contained in the reference string.
		
		// sign the item
		pItem->SignContract(*pNym);
		pItem->SaveContract();
		
		// the Transaction "owns" the item now and will handle cleaning it up.
		pTransaction->AddItem(*pItem); // the Transaction's destructor will cleanup the item. It "owns" it now.
		
		// ---------------------------------------------
		// TRANSACTION AGREEMENT
		
		// pBalanceItem is signed and saved within this call. No need to do that again.
		OTItem * pStatementItem = pNym->GenerateTransactionStatement(*pTransaction);
		
		if (NULL != pStatementItem) // will never be NULL. Will assert above before it gets here.
			pTransaction->AddItem(*pStatementItem); // Better not be NULL... message will fail... But better check anyway.
		// ---------------------------------------------		
		// sign the transaction
		pTransaction->SignContract(*pNym);
		pTransaction->SaveContract();
		
		// set up the ledger
		OTLedger theLedger(USER_ID, SENDER_ACCT_ID, SERVER_ID);
		theLedger.GenerateLedger(SENDER_ACCT_ID, SERVER_ID, OTLedger::message); // bGenerateLedger defaults to false, which is correct.
		theLedger.AddTransaction(*pTransaction); // now the ledger "owns" and will handle cleaning up the transaction.
		
		// sign the ledger
		theLedger.SignContract(*pNym);
		theLedger.SaveContract();
		
		// extract the ledger in ascii-armored form... encoding...
		OTString		strLedger(theLedger);
		OTASCIIArmor	ascLedger(strLedger);
		
		// (0) Set up the REQUEST NUMBER and then INCREMENT IT
		pNym->GetCurrentRequestNum(strServerID, lRequestNumber);
		theMessage.m_strRequestNum.Format("%ld", lRequestNumber); // Always have to send this.
		pNym->IncrementRequestNum(*pNym, strServerID); // since I used it for a server request, I have to increment it
		
		// (1) Set up member variables 
		theMessage.m_strCommand			= "notarizeTransactions";
		theMessage.m_strNymID			= strNymID;
		theMessage.m_strServerID		= strServerID;
		theMessage.m_strAcctID			= strFromAcct;
		theMessage.m_ascPayload			= ascLedger;
		
		// (2) Sign the Message 
		theMessage.SignContract(*pNym);		
		
		// (3) Save the Message (with signatures and all, back to its internal member m_strRawFile.)
		theMessage.SaveContract();
		
		// (Send it)
#if defined(OT_ZMQ_MODE)
		m_pClient->SetFocusToServerAndNym(*pServer, *pNym, &OT_API::TransportCallback);
#endif	
		m_pClient->ProcessMessageOut(theMessage);	
	} // thePlan.LoadContractFromString()
	else 
	{
		OTLog::Output(0, "Unable to load payment plan from string, or verify it. Sorry.\n");
	}
}



// If a smart contract is already running on a specific server, and the Nym in question (USER_ID)
// is an authorized agent for that smart contract, then he can trigger clauses. All he needs is
// the transaction ID for the smart contract, and the name of the clause.
//
void OT_API::triggerClause(const OTIdentifier	& SERVER_ID,
						   const OTIdentifier	& USER_ID,
						   const long			& lTransactionNum,
						   const OTString		& strClauseName,
						   const OTString		* pStrParam/*=NULL*/)
{
	const char * szFuncName = "OT_API::triggerClause";
	// -----------------------------------------------------
	OTPseudonym * pNym = this->GetOrLoadPrivateNym(USER_ID, szFuncName); // This ASSERTs and logs already.
	if (NULL == pNym) return;
	// By this point, pNym is a good pointer, and is on the wallet.
	//  (No need to cleanup.)
	// -----------------------------------------------------
	OTServerContract *	pServer = this->GetServer(SERVER_ID, szFuncName); // This ASSERTs and logs already.
	if (NULL == pServer) return;
	// By this point, pServer is a good pointer.  (No need to cleanup.)
	// -----------------------------------------------------
	OTMessage theMessage;
	long lRequestNumber = 0;
	
	OTString strServerID(SERVER_ID), strNymID(USER_ID);
	
	// (0) Set up the REQUEST NUMBER and then INCREMENT IT
	pNym->GetCurrentRequestNum(strServerID, lRequestNumber);
	theMessage.m_strRequestNum.Format("%ld", lRequestNumber); // Always have to send this.
	pNym->IncrementRequestNum(*pNym, strServerID); // since I used it for a server request, I have to increment it
	
	// (1) set up member variables 
	theMessage.m_strCommand			= "triggerClause";
	theMessage.m_strNymID			= strNymID;
	theMessage.m_strServerID		= strServerID;
	theMessage.m_lTransactionNum	= lTransactionNum;
	theMessage.m_strNymID2			= strClauseName;
	
	// Optional string parameter. Available as "param_string" 
	// inside the script.
	//
	if ((NULL != pStrParam) && (pStrParam->Exists()))
		theMessage.m_ascPayload.SetString(*pStrParam); // <===

	// (2) Sign the Message 
	theMessage.SignContract(*pNym);		
	
	// (3) Save the Message (with signatures and all, back to its internal member m_strRawFile.)
	theMessage.SaveContract();
	
	// (Send it)
#if defined(OT_ZMQ_MODE)
	m_pClient->SetFocusToServerAndNym(*pServer, *pNym, &OT_API::TransportCallback);
#endif	
	m_pClient->ProcessMessageOut(theMessage);		
}



void OT_API::activateSmartContract(const OTIdentifier	& SERVER_ID,
								   const OTIdentifier	& USER_ID,
								   const OTString		& THE_SMART_CONTRACT)
{
	const char * szFuncName = "OT_API::activateSmartContract";
	// -----------------------------------------------------
	OTPseudonym * pNym = this->GetOrLoadPrivateNym(USER_ID, szFuncName); // This ASSERTs and logs already.
	if (NULL == pNym) return;
	// By this point, pNym is a good pointer, and is on the wallet.
	//  (No need to cleanup.)
	// -----------------------------------------------------
	OTServerContract *	pServer = this->GetServer(SERVER_ID, szFuncName); // This ASSERTs and logs already.
	if (NULL == pServer) return;
	// By this point, pServer is a good pointer.  (No need to cleanup.)
	// -----------------------------------------------------
	OTSmartContract theContract(SERVER_ID);
	OTMessage		theMessage;
	
	long lRequestNumber = 0;
	
	const OTString strServerID(SERVER_ID), strNymID(USER_ID);
	
	if (theContract.LoadContractFromString(THE_SMART_CONTRACT))
	{
		OTAgent * pAgent = NULL;
		OTParty * pParty = theContract.FindPartyBasedOnNymAsAuthAgent(*pNym, &pAgent);
		if (NULL == pParty)
		{
			OTLog::Output(0, "OT_API::activateSmartContract: Failure: USER_ID *IS* a valid Nym, but that Nym is not the authorizing agent for any "
						  "of the parties on this contract. Try calling ConfirmParty() first.\n");
			return;
		}
		OT_ASSERT(NULL != pAgent);
		//
		// BELOW THIS POINT, pAgent and pParty are both valid, and no need to clean them up.
		// ----------------------------------
		
		// Note: Usually, payment plan or market offer will load up the Nym and accounts,
		// and verify ownership, etc.
		// But in this case, the Nym who actually activates the smart contract is merely
		// the authorizing agent for a single party, where there may be a dozen parties listed
		// on the actual contract.
		//
		// It would be unreasonable to expect a party to have EVERY nym and EVERY account
		// to the entire contract. As long as the Nym is legitimately the authorizing agent
		// for one of the parties, then we allow him to send the activation message to the server.
		//
		// (Let the server sort out the trouble of loading all the nyms, loading all the accounts,
		// verifying all the asset type IDs, verifying all the agent names, making sure there
		// are no stashes already created, ETC ETC.)
		//
		// ONE THING I should verify, is that all of the parties are confirmed. I mean, it's not
		// even worth the bother to send the damn thing until then, right? And the Server ID.
		//
		if (false == theContract.AllPartiesHaveSupposedlyConfirmed())
		{
			OTLog::Output(0, "OT_API::activateSmartContract: Failed. EACH PARTY to this smart contract needs to CONFIRM IT FIRST, before one of them "
						   "then activates it at the server. (But THIS smart contract has NOT yet been confirmed, at least, not by all of its parties.)\n");
			return;
		}
		if (SERVER_ID != theContract.GetServerID())
		{
			OTLog::Output(0, "OT_API::activateSmartContract: Failed. The server ID passed in doesn't match the one on the contract itself.\n");
			return;
		}
		// ----------------------------------------------------------
		if (!(pParty->GetAccountCount() > 0))
		{
			OTLog::Output(0, "OT_API::activateSmartContract: Failed. The activating Nym must not only be the authorizing agent for one of the parties, "
						   "but must also be the authorized agent for one of that party's asset accounts. That party must have at least one asset account "
						   "for this reason. (See code comment below this message, in the code.)\n");
			return;
		}
		// *************************************************************************************
		//
		// REQUIREMENT:  The ACTIVATOR aka the Originator Nym (the party who activates the smart 
		// contract on the server) must have at least one asset account as part of the smart contract,
		// for which the authorizing agent for that party is also the authorized agent for that account.
		// This is in order to make sure that the smart contracts will work with the existing infrastructure,
		// so that functions like "GetOpeningNumber()" and "GetClosingNumber()" will continue to work the way
		// they are expected to, and so that there is always at least ONE closing transaction number supplied
		// for the smart contract (at least ONE finalReceipt will actually have to be signed for once it is
		// deactivated) and so we can know who the owner of that account, and what acct # it will be.
		//
		// This is also a requirement because the existing infrastructure uses the transaction system for
		// activating cron items. It was simply not anticipated in the past that cron items, based on valid
		// transactions, wouldn't also therefore be associated with at least one asset account. In fact, 
		// the original difference between transactions (vs normal messages) was that transactions dealt
		// with asset accounts, whereas normal messages did not. (Such as, "checkUser" or "getRequest".)
		//
		// A big piece of this is the BALANCE AGREEMENT. Obviously it wasn't anticipated that "balance
		// agreements" would ever be needed for transactions, yet asset accounts wouldn't be. So the below
		// TRANSACTION STATEMENT, for example, expects an asset account, as does the verification code
		// associated with it. Even transaction statements were originally made for situations where the balance
		// wasn't actually changing, (and so a balance agreement wasn't needed), but where a signature on
		// the transaction numbers was still necessary, since one had to be burned in order to prove that
		// the instrument was valid.
		//
		// Unfortunately, transaction statements still expected an asset account to at least EXIST, since
		// they involved market offers (which do not immediately change the balance) or payment plans
		// (which also do not immediately change the balance.) Yet the account's ID was still at least
		// present in the receipt, and a transaction # was still used.
		//
		// In the case of smart contracts, I will probably someday lift this restriction (that the activating
		// nym must also be the authorized agent on one of the asset accounts on the smart contract). But I
		// will have to go over all the plumbing first and deal with that. In the meantime:
		//
		// --- THE ACTIVATING NYM *MUST* ALSO BE THE AUTHORIZED AGENT 
		//     FOR AT LEAST ONE ASSET ACCOUNT, FOR THAT PARTY. ---
		//
		// *************************************************************************************

		const std::string str_agent_name(pAgent->GetName().Get());
		
		OTPartyAccount * pAcct = pParty->GetAccountByAgent(str_agent_name);

		if (NULL == pAcct)
		{
			OTLog::Output(0, "OT_API::activateSmartContract: Failed. The activating Nym must not only be the authorizing agent for one of the parties, "
						   "but must also be the authorized agent for one of that party's asset accounts. That party must have at least one asset account "
						   "for this reason. (See code comment above this message, in the code.)\n");
			return;
		}
		// ----------------------------------------------------------
		const OTString &	strAcctID = pAcct->GetAcctID();
		
		if (!strAcctID.Exists())
		{
			OTLog::vOutput(0, "OT_API::activateSmartContract: Failed. The Account ID is blank for asset acct (%s) for party (%s). Did you confirm "
						   "this account, before trying to activate this contract?\n", pAcct->GetName().Get(), pParty->GetPartyName().c_str());
			return;
		}
		// ----------------------------------------------------------
		OTIdentifier	theAcctID(strAcctID);
		
		const long lOpeningTransNo = pParty->GetOpeningTransNo();
		const long lClosingTransNo = pAcct-> GetClosingTransNo();
		
		if ((lOpeningTransNo <= 0) || (lClosingTransNo <= 0))
		{
			OTLog::vOutput(0, "OT_API::activateSmartContract: Failed. Opening Transaction # (%ld) or Closing # (%ld) were invalid "
						   "for asset acct (%s) for party (%s). Did you confirm this account and party, before trying to activate this contract?\n", 
						   lOpeningTransNo, lClosingTransNo, pAcct->GetName().Get(), pParty->GetPartyName().c_str());
			return;
		}
		if (!pNym->VerifyIssuedNum(strServerID, lOpeningTransNo))
		{
			OTLog::vOutput(0, "OT_API::activateSmartContract: Failed. Opening Transaction # (%ld) wasn't valid/issued to this Nym, "
						   "for asset acct (%s) for party (%s). Did you confirm this account and party, before trying to activate this contract?\n", 
						   lOpeningTransNo, pAcct->GetName().Get(), pParty->GetPartyName().c_str());
			return;
		}
		if (!pNym->VerifyIssuedNum(strServerID, lClosingTransNo))
		{
			OTLog::vOutput(0, "OT_API::activateSmartContract: Failed. Closing Transaction # (%ld) wasn't issued to this Nym, "
						   "for asset acct (%s) for party (%s). Did you confirm this account and party, before trying to activate this contract?\n", 
						   lClosingTransNo, pAcct->GetName().Get(), pParty->GetPartyName().c_str());
			return;
		}
		// ----------------------------------------------------------
		// These numbers (the opening and closing transaction #s) were already available on
		// the smart contract -- specifically an opening number is stored for each party,
		// taken from the authorizing agent for that party, and a closing number is stored for
		// each asset account, taken from the authorized agent for that asset account.
		// 
		// Now we set the appropriate opening/closing number onto the smart contract, in the way
		// of the existing CronItem system, so that it will work properly within that infrastructure.
		// (This is what makes the activating Nym slightly different / more than the other authorizing
		// agent nyms for each party to the contract. Not only does it have opening/closing numbers
		// on its party like all the others, but its numbers are also those used for the cron item itself.)
		//		
		theContract.PrepareToActivate(lOpeningTransNo, lClosingTransNo, USER_ID, theAcctID);
		// This call changes the contract slightly, so it must be re-signed (in order to save changes.)
		// ----------------------------------------------------------
		theContract.ReleaseSignatures();
		
		if (false == pAgent->SignContract(theContract)) // RE-SIGN HERE.
		{
			OTLog::Error("OT_API::activateSmartContract: Failed re-signing contract, after calling PrepareToActivate().\n");
			return;
		}
		
		theContract.SaveContract();
		const OTString strContract(theContract); // Grab a string version of the latest signed contract.
		
		// ----------------------------------------------------------
		// Create a transaction
		//
		OTTransaction * pTransaction = OTTransaction::GenerateTransaction (USER_ID,
																		   theAcctID,
																		   SERVER_ID, 
																		   OTTransaction::smartContract,
																		   theContract.GetTransactionNum());
		
		// set up the transaction item (each transaction may have multiple items...)
		OTItem * pItem		= OTItem::CreateItemFromTransaction(*pTransaction, OTItem::smartContract);

		// Add the smart contract string as the attachment on the transaction item.
		pItem->SetAttachment(strContract);
		
		// sign the item
		pItem->SignContract(*pNym);
		pItem->SaveContract();
		
		// the Transaction "owns" the item now and will handle cleaning it up.
		pTransaction->AddItem(*pItem); // the Transaction's destructor will cleanup the item. It "owns" it now.
		
		// ---------------------------------------------
		// TRANSACTION AGREEMENT
		
		// pStatementItem is signed and saved within this call. No need to do that again.
		OTItem * pStatementItem = pNym->GenerateTransactionStatement(*pTransaction);
		
		if (NULL != pStatementItem) // will never be NULL. Will assert above before it gets here.
			pTransaction->AddItem(*pStatementItem); // Better not be NULL... message will fail... But better check anyway.
		// ---------------------------------------------		
		// sign the transaction
		pTransaction->SignContract(*pNym);
		pTransaction->SaveContract();
		
		// set up the ledger
		OTLedger theLedger(USER_ID, theAcctID, SERVER_ID);
		
		theLedger.GenerateLedger(theAcctID, SERVER_ID, OTLedger::message); // bGenerateLedger defaults to false, which is correct.
		theLedger.AddTransaction(*pTransaction); // now the ledger "owns" and will handle cleaning up the transaction.
		
		// sign the ledger
		theLedger.SignContract(*pNym);
		theLedger.SaveContract();

		// extract the ledger in ascii-armored form... encoding...
		OTString		strLedger(theLedger);
		OTASCIIArmor	ascLedger(strLedger);
		
		// (0) Set up the REQUEST NUMBER and then INCREMENT IT
		pNym->GetCurrentRequestNum(strServerID, lRequestNumber);
		theMessage.m_strRequestNum.Format("%ld", lRequestNumber); // Always have to send this.
		pNym->IncrementRequestNum(*pNym, strServerID); // since I used it for a server request, I have to increment it
		
		// (1) Set up member variables 
		theMessage.m_strCommand			= "notarizeTransactions";
		theMessage.m_strNymID			= strNymID;
		theMessage.m_strServerID		= strServerID;
		theAcctID.GetString(theMessage.m_strAcctID);
		theMessage.m_ascPayload			= ascLedger;
		
		// (2) Sign the Message 
		theMessage.SignContract(*pNym);		
		
		// (3) Save the Message (with signatures and all, back to its internal member m_strRawFile.)
		theMessage.SaveContract();
		
		// (Send it)
#if defined(OT_ZMQ_MODE)
		m_pClient->SetFocusToServerAndNym(*pServer, *pNym, &OT_API::TransportCallback);
#endif	
		m_pClient->ProcessMessageOut(theMessage);	
	} // theContract.LoadContractFromString()
	else
		OTLog::vOutput(0, "OT_API::activateSmartContract: Unable to load smart contract from string:\n\n%s\n\n", 
					   THE_SMART_CONTRACT.Get());
}


// Done: make a new transaction (and item) type for smart contract. (for a cron item.)


// Done: Add an API call that allows the coder to harvest transaction numbers from Cron Items.
// This will be used on the client side, I believe, and not server side (not in smart contracts.)
//


// Done: Make a copy of CancelCronItem(), and use it to make an EXECUTE CLAUSE message 
// for Nyms to trigger existing smart contracts!!!!!!!!!
// WAIT: Except it DOESN'T have to be a transaction! Because as long as the Nym is a valid
// party, and the action occurs, it will ALREADY drop receipts into the appropriate boxes!
// But wait... How do we know that the Nym REALLY triggered that clause, if there's not
// a transaction # burned? It doesn't matter: the purpose of transaction #s is to make sure
// that CHANGES in BALANCE are signed off on, by leaving the # open, and putting a receipt
// in the inbox. But if Nym really is a party to this smart contract (which will be verified 
// in any case), then he DOES have transaction #s open already, and if any balances change,
// receipts will be dropped into the appropriate inboxes already containing those transaction
// #s. (As well as containing his original signed copy of the cron item, AND as well as 
// containing the latest message, with his signature and request number on it, which triggered
// the clause to be called.)  Furthermore, if the clause is triggered multiple times, then
// there must be multiple receipts, and each one should feature a NEW instance of the triggering,
// WITH a valid signature on it, and WITH a NEW REQUEST NUMBER ON IT. Without this, none of
// the balances could change anyway.
// Therefore I conclude that the "trigger a clause" message does NOT have to be a transaction,
// but only needs to be a message  :-)
//
// Done: the "trigger clause" message!



// DONE: CHange this into a TRANSACTION!
// (So there can be a transaction statement, since canceling a cron
// item removes a transaction number from your issued list.)
///-------------------------------------------------------
/// CANCEL A SPECIFIC OFFER (THAT SAME NYM PLACED PREVIOUSLY ON SAME SERVER.)
/// By transaction number as key.
///
void OT_API::cancelCronItem(const OTIdentifier & SERVER_ID, 
							const OTIdentifier & USER_ID, 
							const OTIdentifier & ASSET_ACCT_ID, 
							const long & lTransactionNum) // so the server can lookup the offer in Cron.
{
	const char * szFuncName = "OT_API::cancelCronItem";
	// -----------------------------------------------------
	OTPseudonym * pNym = this->GetOrLoadPrivateNym(USER_ID, szFuncName); // This ASSERTs and logs already.
	if (NULL == pNym) return;
	// By this point, pNym is a good pointer, and is on the wallet.
	//  (No need to cleanup.)
	// -----------------------------------------------------
	OTServerContract *	pServer = this->GetServer(SERVER_ID, szFuncName); // This ASSERTs and logs already.
	if (NULL == pServer) return;
	// By this point, pServer is a good pointer.  (No need to cleanup.)
	// -----------------------------------------------------
	OTMessage	theMessage;
	
	long lRequestNumber = 0;
	
	const OTString strServerID(SERVER_ID), strNymID(USER_ID);
    
	if (pNym->GetTransactionNumCount(strServerID) < 1)
    {
        OTLog::Output(0, "OT_API::cancelCronItem: At least 1 Transaction Number is necessary to cancel any cron item. "
                      "Try requesting the server for more numbers (you are low.)\n"); 
        return;
    }
    // ------------------------------------
	long lStoredTransactionNumber=0;
	bool bGotTransNum   = pNym->GetNextTransactionNum(*pNym, strServerID, lStoredTransactionNumber, true); // bSave=false
    
	if (!bGotTransNum)
		OTLog::Error("OT_API::cancelCronItem: Supposedly there was a transaction number available, but the call\n"
                     "still failed.\n");
	else
	{
		// -------------------------------------------------------------------
        OTString str_ASSET_ACCT_ID(ASSET_ACCT_ID);
        
        // Create a transaction
        OTTransaction * pTransaction = OTTransaction::GenerateTransaction (USER_ID, ASSET_ACCT_ID, SERVER_ID, 
                                                                           OTTransaction::cancelCronItem, lStoredTransactionNumber); 
        // set up the transaction item (each transaction may have multiple items...)
        OTItem * pItem		= OTItem::CreateItemFromTransaction(*pTransaction, OTItem::cancelCronItem); 
        OT_ASSERT_MSG(NULL != pItem, "Error allocating memory in the OT API");

        pItem->SetReferenceToNum(lTransactionNum);          // This transaction is being sent in order to cancel another transaction.
        pTransaction->SetReferenceToNum(lTransactionNum);   // This is where we clearly show which one is actually being cancelled.
        
        // sign the item
        pItem->SignContract(*pNym);
        pItem->SaveContract();
        
        // the Transaction "owns" the item now and will handle cleaning it up.
        pTransaction->AddItem(*pItem); // the Transaction's destructor will cleanup the item. It "owns" it now.
        // ---------------------------------------------
        // TRANSACTION AGREEMENT
        
        // pBalanceItem is signed and saved within this call. No need to do that again.
        OTItem * pStatementItem = pNym->GenerateTransactionStatement(*pTransaction);
        
        if (NULL != pStatementItem) // will never be NULL. Will assert above before it gets here.
            pTransaction->AddItem(*pStatementItem); // Better not be NULL... message will fail... But better check anyway.
        // ---------------------------------------------
        // sign the transaction
        pTransaction->SignContract(*pNym);
        pTransaction->SaveContract();
        
        // set up the ledger
        OTLedger theLedger(USER_ID, ASSET_ACCT_ID, SERVER_ID);
        theLedger.GenerateLedger(ASSET_ACCT_ID, SERVER_ID, OTLedger::message); // bGenerateLedger defaults to false, which is correct.
        theLedger.AddTransaction(*pTransaction); // now the ledger "owns" and will handle cleaning up the transaction.
        
        // sign the ledger
        theLedger.SignContract(*pNym);
        theLedger.SaveContract();
        
        // extract the ledger in ascii-armored form... encoding...
        OTString		strLedger(theLedger);
        OTASCIIArmor	ascLedger(strLedger);
        
        // (0) Set up the REQUEST NUMBER and then INCREMENT IT
        pNym->GetCurrentRequestNum(strServerID, lRequestNumber);
        theMessage.m_strRequestNum.Format("%ld", lRequestNumber); // Always have to send this.
        pNym->IncrementRequestNum(*pNym, strServerID); // since I used it for a server request, I have to increment it
        
        // (1) Set up member variables 
        theMessage.m_strCommand			= "notarizeTransactions";
        theMessage.m_strNymID			= strNymID;
        theMessage.m_strServerID		= strServerID;
        theMessage.m_strAcctID			= str_ASSET_ACCT_ID;
        theMessage.m_ascPayload			= ascLedger;
        
        // (2) Sign the Message 
        theMessage.SignContract(*pNym);		
        
        // (3) Save the Message (with signatures and all, back to its internal member m_strRawFile.)
        theMessage.SaveContract();
			
        // (Send it)
#if defined(OT_ZMQ_MODE)
        m_pClient->SetFocusToServerAndNym(*pServer, *pNym, &OT_API::TransportCallback);
#endif	
        m_pClient->ProcessMessageOut(theMessage);	
	} // got transaction number.
}




// ----------------------------------------------------------------
// ISSUE MARKET OFFER
//
//
void OT_API::issueMarketOffer(const OTIdentifier	& SERVER_ID,
							  const OTIdentifier	& USER_ID,
							  // -------------------------------------------
							  const OTIdentifier	& ASSET_TYPE_ID,
							  const OTIdentifier	& ASSET_ACCT_ID,
							  // -------------------------------------------
							  const OTIdentifier	& CURRENCY_TYPE_ID,
							  const OTIdentifier	& CURRENCY_ACCT_ID,
							  // -------------------------------------------
							  const long			& MARKET_SCALE,	// Defaults to minimum of 1. Market granularity.
							  const long			& MINIMUM_INCREMENT, // This will be multiplied by the Scale. Min 1.
							  const long			& TOTAL_ASSETS_ON_OFFER, // Total assets available for sale or purchase. Will be multiplied by minimum increment.
							  const long			& PRICE_LIMIT, // Per Minimum Increment...
							  const bool			bBuyingOrSelling) //  BUYING == false, SELLING == true.
{
	const char * szFuncName = "OT_API::issueMarketOffer";
	// -----------------------------------------------------
	OTPseudonym * pNym = this->GetOrLoadPrivateNym(USER_ID, szFuncName); // This ASSERTs and logs already.
	if (NULL == pNym) return;
	// By this point, pNym is a good pointer, and is on the wallet.
	//  (No need to cleanup.)
	// -----------------------------------------------------
	OTServerContract *	pServer = this->GetServer(SERVER_ID, szFuncName); // This ASSERTs and logs already.
	if (NULL == pServer) return;
	// By this point, pServer is a good pointer.  (No need to cleanup.)
	// -----------------------------------------------------
	OTMessage	theMessage;
	
	long lRequestNumber = 0;
	
	const OTString strServerID(SERVER_ID), strNymID(USER_ID);

	if (pNym->GetTransactionNumCount(strServerID) < 3)
    {
        OTLog::Output(0, "OT_API::issueMarketOffer: At least 3 Transaction Numbers are necessary to issue a market offer. "
                      "Try requesting the server for more (you are low.)\n"); 
        return;
    }
    // ------------------------------------
	long lStoredTransactionNumber=0, lAssetAcctClosingNo=0, lCurrencyAcctClosingNo=0;
	bool bGotTransNum   = pNym->GetNextTransactionNum(*pNym, strServerID, lStoredTransactionNumber, false); // bSave=false
	bool bGotAssetClosingNum = pNym->GetNextTransactionNum(*pNym, strServerID, lAssetAcctClosingNo, false); // bSave=true  (true is default in this case, FYI.)
	bool bGotCurrencyClosingNum = pNym->GetNextTransactionNum(*pNym, strServerID, lCurrencyAcctClosingNo, true); // bSave=true 

	if (!bGotTransNum || !bGotAssetClosingNum || !bGotCurrencyClosingNum)
	{
		OTLog::Error("OT_API::issueMarketOffer: Supposedly there were 3 transaction numbers available, but the call(s)\n"
                     "still failed. (Re-adding back to Nym, and failing out of this function.)\n");
        
        if (bGotTransNum)
			pNym->AddTransactionNum(*pNym, strServerID, lStoredTransactionNumber, false); // bSave=true								
        
        if (bGotAssetClosingNum)
			pNym->AddTransactionNum(*pNym, strServerID, lAssetAcctClosingNo, false); // bSave=true								
        
        if (bGotCurrencyClosingNum)
			pNym->AddTransactionNum(*pNym, strServerID, lCurrencyAcctClosingNo, false); // bSave=true								
        
        if (bGotTransNum || bGotAssetClosingNum || bGotCurrencyClosingNum)
            pNym->SaveSignedNymfile(*pNym);
	}
	else
	{
		// -------------------------------------------------------------------
		long	lTotalAssetsOnOffer = 1, 
				lMinimumIncrement = 1, 
				lPriceLimit = 1,
				lMarketScale = 1;
		// -------------------------------------------------------------------
		if (MARKET_SCALE > 0)
			lMarketScale = MARKET_SCALE; // otherwise, defaults to 1.
		
		if (MINIMUM_INCREMENT > 0)
			lMinimumIncrement = MINIMUM_INCREMENT; // otherwise, defaults to 1.
		
		lMinimumIncrement *= lMarketScale; // minimum increment is PER SCALE.
		// -------------------------------------------------------------------
		if (TOTAL_ASSETS_ON_OFFER > 0)
			lTotalAssetsOnOffer = TOTAL_ASSETS_ON_OFFER; // otherwise, defaults to 1.
		
//		lTotalAssetsOnOffer *= lMinimumIncrement;  This was a bug.
		// -------------------------------------------------------------------
		if (PRICE_LIMIT > 0) // your price limit, per scale of assets.
			lPriceLimit = PRICE_LIMIT; // otherwise, defaults to 1.
		// -------------------------------------------------------------------
		OTOffer theOffer(SERVER_ID, ASSET_TYPE_ID, CURRENCY_TYPE_ID, lMarketScale);
		
		OTTrade theTrade(SERVER_ID, 
						 ASSET_TYPE_ID, ASSET_ACCT_ID, 
						 USER_ID, 
						 CURRENCY_TYPE_ID, CURRENCY_ACCT_ID);
		
		// MAKE OFFER...
		//
		bool bCreateOffer = theOffer.MakeOffer(bBuyingOrSelling,	// True == SELLING, False == BUYING
											   lPriceLimit,			// Per Minimum Increment...
											   lTotalAssetsOnOffer,	// Total assets available for sale or purchase.
											   lMinimumIncrement,	// The minimum increment that must be bought or sold for each transaction
											   lStoredTransactionNumber); // Transaction number matches on transaction, item, offer, and trade.
		
		// -------------------------------------------------------------------
		// ISSUE TRADE.
		bool bIssueTrade = false;
		
		if (bCreateOffer)
		{
			bCreateOffer = 	theOffer.SignContract(*pNym);
			
			if (bCreateOffer)
			{
				bCreateOffer = theOffer.SaveContract();
			
				if (bCreateOffer)
				{
					bIssueTrade = theTrade.IssueTrade(theOffer); // <==== ISSUE TRADE <=====
					
                    // ******************************************************************************
                    // This is new: the closing transaction number is now used for CLOSING recurring
                    // cron items, like market offers and payment plans. It's also useful for baskets.
                    // Since this is a market offer, it needs a closing number (for later cancellation
                    // or expiration.)
                    // lAssetAcctClosingNo=0, lCurrencyAcctClosingNo=0;
                    //
                    theTrade.AddClosingTransactionNo(lAssetAcctClosingNo);
                    theTrade.AddClosingTransactionNo(lCurrencyAcctClosingNo);

					if (bIssueTrade)
					{
						bIssueTrade = 	theTrade.SignContract(*pNym);
						
						if (bIssueTrade)
							bIssueTrade = theTrade.SaveContract();
					} // if ( bIssueTrade )
				}
			}
		} // if ( bCreateOffer )
		// -------------------------------------------------------------------

		if (bCreateOffer && bIssueTrade)
		{
			OTString str_ASSET_ACCT_ID(ASSET_ACCT_ID);
			
			// Create a transaction
			OTTransaction * pTransaction = OTTransaction::GenerateTransaction (USER_ID, ASSET_ACCT_ID, SERVER_ID, 
																			   OTTransaction::marketOffer, lStoredTransactionNumber); 
			
			// set up the transaction item (each transaction may have multiple items...)
			OTItem * pItem		= OTItem::CreateItemFromTransaction(*pTransaction, OTItem::marketOffer, 
																	(OTIdentifier *)(&CURRENCY_ACCT_ID)); 
			// the "To" account (normally used for a TRANSFER transaction) is used here 
			// storing the Currency Acct ID. The Server will expect the Trade object bundled 
			// within this item to have an Asset Acct ID and "Currency" Acct ID that match
			// those on this Item. Otherwise it will reject the offer.
			//
			OT_ASSERT_MSG(NULL != pItem, "OT_API::issueMarketOffer: Error allocating memory in the OT API");
			
			OTString strTrade;
			theTrade.SaveContractRaw(strTrade);
			
			// Add the trade string as the attachment on the transaction item.
			pItem->SetAttachment(strTrade); // The trade is contained in the attachment string. (The offer is within the trade.)
			
			// sign the item
			pItem->SignContract(*pNym);
			pItem->SaveContract();
			
			// the Transaction "owns" the item now and will handle cleaning it up.
			pTransaction->AddItem(*pItem); // the Transaction's destructor will cleanup the item. It "owns" it now.
			
			// ---------------------------------------------
			// TRANSACTION AGREEMENT
			
			// pBalanceItem is signed and saved within this call. No need to do that again.
			OTItem * pStatementItem = pNym->GenerateTransactionStatement(*pTransaction);
			
			if (NULL != pStatementItem) // will never be NULL. Will assert above before it gets here.
				pTransaction->AddItem(*pStatementItem); // Better not be NULL... message will fail... But better check anyway.
			
			// ---------------------------------------------
			
			// sign the transaction
			pTransaction->SignContract(*pNym);
			pTransaction->SaveContract();
			
			// set up the ledger
			OTLedger theLedger(USER_ID, ASSET_ACCT_ID, SERVER_ID);
			theLedger.GenerateLedger(ASSET_ACCT_ID, SERVER_ID, OTLedger::message); // bGenerateLedger defaults to false, which is correct.
			theLedger.AddTransaction(*pTransaction); // now the ledger "owns" and will handle cleaning up the transaction.
			
			// sign the ledger
			theLedger.SignContract(*pNym);
			theLedger.SaveContract();
			
			// extract the ledger in ascii-armored form... encoding...
			OTString		strLedger(theLedger);
			OTASCIIArmor	ascLedger(strLedger);
			
			// (0) Set up the REQUEST NUMBER and then INCREMENT IT
			pNym->GetCurrentRequestNum(strServerID, lRequestNumber);
			theMessage.m_strRequestNum.Format("%ld", lRequestNumber); // Always have to send this.
			pNym->IncrementRequestNum(*pNym, strServerID); // since I used it for a server request, I have to increment it
			
			// (1) Set up member variables 
			theMessage.m_strCommand			= "notarizeTransactions";
			theMessage.m_strNymID			= strNymID;
			theMessage.m_strServerID		= strServerID;
			theMessage.m_strAcctID			= str_ASSET_ACCT_ID;
			theMessage.m_ascPayload			= ascLedger;
			
			// (2) Sign the Message 
			theMessage.SignContract(*pNym);		
			
			// (3) Save the Message (with signatures and all, back to its internal member m_strRawFile.)
			theMessage.SaveContract();
			
			// (Send it)
#if defined(OT_ZMQ_MODE)
			m_pClient->SetFocusToServerAndNym(*pServer, *pNym, &OT_API::TransportCallback);
#endif	
			m_pClient->ProcessMessageOut(theMessage);	
		} // if (bCreateOffer && bIssueTrade)
		else 
		{
			OTLog::Output(0, "OT_API::issueMarketOffer: Unable to create offer or issue trade. Sorry.\n");
			
			// IF FAILED, ADD TRANSACTION NUMBER (and closing number) BACK TO LIST OF AVAILABLE NUMBERS.
			pNym->AddTransactionNum(*pNym, strServerID, lStoredTransactionNumber, false); // bSave defaults to true								
            pNym->AddTransactionNum(*pNym, strServerID, lAssetAcctClosingNo, false); 
            pNym->AddTransactionNum(*pNym, strServerID, lCurrencyAcctClosingNo, true); // bSave=true (No sense saving thrice in a row.)	
		}							
	} // got transaction number.
}



// -----------------------------------
/// GET MARKET LIST
///
/// Connect to a specific server, as a specific Nym, and request the list of markets.
/// (Flush the buffer before calling this. Then after you make this call, wait 50 ms
/// and then pop the buffer and check the server reply for success. From there you can 
/// either read the reply data directly out of the reply message, or you can load it from
/// storage (OT will probably auto-store the reply to storage, for your convenience.)
///
void OT_API::getMarketList(const OTIdentifier & SERVER_ID, const OTIdentifier & USER_ID)
{
	const char * szFuncName = "OT_API::getMarketList";
	// -----------------------------------------------------
	OTPseudonym * pNym = this->GetOrLoadPrivateNym(USER_ID, szFuncName); // This ASSERTs and logs already.
	if (NULL == pNym) return;
	// By this point, pNym is a good pointer, and is on the wallet.
	//  (No need to cleanup.)
	// -----------------------------------------------------
	OTServerContract *	pServer = this->GetServer(SERVER_ID, szFuncName); // This ASSERTs and logs already.
	if (NULL == pServer) return;
	// By this point, pServer is a good pointer.  (No need to cleanup.)
	// -----------------------------------------------------
	OTMessage theMessage;
	
	OTString strServerID(SERVER_ID);
	// -----------------------------------------------------
	// (0) Set up the REQUEST NUMBER and then INCREMENT IT
	long lRequestNumber = 0;
	pNym->GetCurrentRequestNum(strServerID, lRequestNumber);
	theMessage.m_strRequestNum.Format("%ld", lRequestNumber); // Always have to send this.
	pNym->IncrementRequestNum(*pNym, strServerID); // since I used it for a server request, I have to increment it
	
	OTString strNymID(USER_ID);

	// (1) Set up member variables 
	theMessage.m_strCommand			= "getMarketList";
	theMessage.m_strNymID			= strNymID;
	theMessage.m_strServerID		= strServerID;
	
	// (2) Sign the Message 
	theMessage.SignContract(*pNym);		
	
	// (3) Save the Message (with signatures and all, back to its internal member m_strRawFile.)
	theMessage.SaveContract();
	
	// (Send it)
#if defined(OT_ZMQ_MODE)
	m_pClient->SetFocusToServerAndNym(*pServer, *pNym, &OT_API::TransportCallback);
#endif	
	m_pClient->ProcessMessageOut(theMessage);		
}




// -----------------------------------------------------
/// GET ALL THE OFFERS ON A SPECIFIC MARKET
///
/// A specific Nym is requesting the Server to send a list of the offers on a specific
/// Market ID-- the bid/ask, and prices/amounts, basically--(up to lDepth or server Max) 
/// 
void OT_API::getMarketOffers(const OTIdentifier & SERVER_ID, const OTIdentifier & USER_ID, 
							 const OTIdentifier & MARKET_ID, const long & lDepth)
{
	const char * szFuncName = "OT_API::getMarketOffers";
	// -----------------------------------------------------
	OTPseudonym * pNym = this->GetOrLoadPrivateNym(USER_ID, szFuncName); // This ASSERTs and logs already.
	if (NULL == pNym) return;
	// By this point, pNym is a good pointer, and is on the wallet.
	//  (No need to cleanup.)
	// -----------------------------------------------------
	OTServerContract *	pServer = this->GetServer(SERVER_ID, szFuncName); // This ASSERTs and logs already.
	if (NULL == pServer) return;
	// By this point, pServer is a good pointer.  (No need to cleanup.)
	// -----------------------------------------------------
	OTMessage theMessage;
	
	OTString strServerID(SERVER_ID), strMarketID(MARKET_ID);
	
	// -----------------------------------------------------
	// (0) Set up the REQUEST NUMBER and then INCREMENT IT
	long lRequestNumber = 0;
	pNym->GetCurrentRequestNum(strServerID, lRequestNumber);
	theMessage.m_strRequestNum.Format("%ld", lRequestNumber); // Always have to send this.
	pNym->IncrementRequestNum(*pNym, strServerID); // since I used it for a server request, I have to increment it
	
	OTString strNymID(USER_ID);
	// (1) Set up member variables 
	theMessage.m_strCommand			= "getMarketOffers";
	theMessage.m_strNymID			= strNymID;
	theMessage.m_strServerID		= strServerID;
	theMessage.m_strNymID2			= strMarketID;
	theMessage.m_lDepth				= lDepth;
	
	// (2) Sign the Message 
	theMessage.SignContract(*pNym);		
	
	// (3) Save the Message (with signatures and all, back to its internal member m_strRawFile.)
	theMessage.SaveContract();
	
	// (Send it)
#if defined(OT_ZMQ_MODE)
	m_pClient->SetFocusToServerAndNym(*pServer, *pNym, &OT_API::TransportCallback);
#endif	
	m_pClient->ProcessMessageOut(theMessage);					
}

///-------------------------------------------------------
/// GET RECENT TRADES FOR A SPECIFIC MARKET ID
/// 
/// Most likely, ticker data will be made available through a separate ZMQ instance,
/// which will use the publisher/subscriber model to distribute ticker data. From there,
/// those privileged subscribers can distribute it via RSS, store it for future analysis,
/// display charts, etc.
///
/// (So this function is not here to usurp that purpose.)
///
void OT_API::getMarketRecentTrades(const OTIdentifier & SERVER_ID, const OTIdentifier & USER_ID, 
								   const OTIdentifier & MARKET_ID)
{
	const char * szFuncName = "OT_API::getMarketRecentTrades";
	// -----------------------------------------------------
	OTPseudonym * pNym = this->GetOrLoadPrivateNym(USER_ID, szFuncName); // This ASSERTs and logs already.
	if (NULL == pNym) return;
	// By this point, pNym is a good pointer, and is on the wallet.
	//  (No need to cleanup.)
	// -----------------------------------------------------
	OTServerContract *	pServer = this->GetServer(SERVER_ID, szFuncName); // This ASSERTs and logs already.
	if (NULL == pServer) return;
	// By this point, pServer is a good pointer.  (No need to cleanup.)
	// -----------------------------------------------------
	OTMessage theMessage;
	
	OTString strServerID(SERVER_ID), strMarketID(MARKET_ID);
	// -----------------------------------------------------
	// (0) Set up the REQUEST NUMBER and then INCREMENT IT
	long lRequestNumber = 0;
	pNym->GetCurrentRequestNum(strServerID, lRequestNumber);
	theMessage.m_strRequestNum.Format("%ld", lRequestNumber); // Always have to send this.
	pNym->IncrementRequestNum(*pNym, strServerID); // since I used it for a server request, I have to increment it
	
	OTString strNymID(USER_ID);
	// (1) Set up member variables 
	theMessage.m_strCommand			= "getMarketRecentTrades";
	theMessage.m_strNymID			= strNymID;
	theMessage.m_strServerID		= strServerID;
	theMessage.m_strNymID2			= strMarketID;
	
	// (2) Sign the Message 
	theMessage.SignContract(*pNym);		
	
	// (3) Save the Message (with signatures and all, back to its internal member m_strRawFile.)
	theMessage.SaveContract();
	
	// (Send it)
#if defined(OT_ZMQ_MODE)
	m_pClient->SetFocusToServerAndNym(*pServer, *pNym, &OT_API::TransportCallback);
#endif	
	m_pClient->ProcessMessageOut(theMessage);					
}



///-------------------------------------------------------
/// GET ALL THE ACTIVE (in Cron) MARKET OFFERS FOR A SPECIFIC NYM. 
/// (ON A SPECIFIC SERVER, OBVIOUSLY.) Remember to use Flush/Call/Wait/Pop
/// to check the server reply for success or fail.
/// Hmm for size reasons, this really will have to return a list of transaction #s,
/// and then I request them one-by-one after that...
///
void OT_API::getNym_MarketOffers(const OTIdentifier & SERVER_ID, const OTIdentifier & USER_ID)
{
	const char * szFuncName = "OT_API::getNym_MarketOffers";
	// -----------------------------------------------------
	OTPseudonym * pNym = this->GetOrLoadPrivateNym(USER_ID, szFuncName); // This ASSERTs and logs already.
	if (NULL == pNym) return;
	// By this point, pNym is a good pointer, and is on the wallet.
	//  (No need to cleanup.)
	// -----------------------------------------------------
	OTServerContract *	pServer = this->GetServer(SERVER_ID, szFuncName); // This ASSERTs and logs already.
	if (NULL == pServer) return;
	// By this point, pServer is a good pointer.  (No need to cleanup.)
	// -----------------------------------------------------
	OTMessage theMessage;
	
	OTString strServerID(SERVER_ID);
	
	// -----------------------------------------------------
	// (0) Set up the REQUEST NUMBER and then INCREMENT IT
	long lRequestNumber = 0;
	pNym->GetCurrentRequestNum(strServerID, lRequestNumber);
	theMessage.m_strRequestNum.Format("%ld", lRequestNumber); // Always have to send this.
	pNym->IncrementRequestNum(*pNym, strServerID); // since I used it for a server request, I have to increment it

	OTString strNymID(USER_ID);

	// (1) Set up member variables 
	theMessage.m_strCommand			= "getNym_MarketOffers";
	theMessage.m_strNymID			= strNymID;
	theMessage.m_strServerID		= strServerID;
	
	// (2) Sign the Message 
	theMessage.SignContract(*pNym);		
	
	// (3) Save the Message (with signatures and all, back to its internal member m_strRawFile.)
	theMessage.SaveContract();
	
	// (Send it)
#if defined(OT_ZMQ_MODE)
	m_pClient->SetFocusToServerAndNym(*pServer, *pNym, &OT_API::TransportCallback);
#endif	
	m_pClient->ProcessMessageOut(theMessage);			
}


// ===============================================================




void OT_API::notarizeTransfer(OTIdentifier	& SERVER_ID,
							  OTIdentifier	& USER_ID,
							  OTIdentifier	& ACCT_FROM,
							  OTIdentifier	& ACCT_TO,
							  OTString		& AMOUNT,
							  OTString		& NOTE)
{
	const char * szFuncName = "OT_API::notarizeTransfer";
	// -----------------------------------------------------
	OTPseudonym * pNym = this->GetOrLoadPrivateNym(USER_ID, szFuncName);
	if (NULL == pNym) return;	
	// By this point, pNym is a good pointer, and is on the wallet.
	//  (No need to cleanup.)
	// -----------------------------------------------------
	OTServerContract *	pServer = this->GetServer(SERVER_ID, szFuncName); // This ASSERTs and logs already.
	if (NULL == pServer) return;
	// By this point, pServer is a good pointer.  (No need to cleanup.)
	// -----------------------------------------------------
	OTAccount * pAccount = this->GetOrLoadAccount(*pNym, ACCT_FROM, SERVER_ID, szFuncName);
	if (NULL == pAccount) return;
	// By this point, pAccount is a good pointer.  (No need to cleanup.)
	// -----------------------------------------------------
	OTMessage theMessage;
	
	long lRequestNumber = 0;
	long lAmount = atol(AMOUNT.Get());
	
	OTString	strServerID(SERVER_ID), strNymID(USER_ID), 
				strFromAcct(ACCT_FROM), strToAcct(ACCT_TO);

	long lStoredTransactionNumber=0;
	bool bGotTransNum = pNym->GetNextTransactionNum(*pNym, strServerID, lStoredTransactionNumber);
	
	if (bGotTransNum)
	{
		// Create a transaction
		OTTransaction * pTransaction = OTTransaction::GenerateTransaction (USER_ID, ACCT_FROM, 
																		   SERVER_ID, 
																		   OTTransaction::transfer, 
																		   lStoredTransactionNumber); 
		
		// set up the transaction item (each transaction may have multiple items...)
		OTItem * pItem		= OTItem::CreateItemFromTransaction(*pTransaction, OTItem::transfer, &ACCT_TO);
		pItem->SetAmount(atol(AMOUNT.Get()));
		
		// The user can include a note here for the recipient.
		if (NOTE.Exists() && NOTE.GetLength() > 2) 
		{
			pItem->SetNote(NOTE);
		}
		
		// sign the item
		pItem->SignContract(*pNym);
		pItem->SaveContract();
		
		pTransaction->AddItem(*pItem); // the Transaction's destructor will cleanup the item. It "owns" it now.
		// --------------------------------------------------
		OTLedger * pInbox	= pAccount->LoadInbox(*pNym);
		OTLedger * pOutbox	= pAccount->LoadOutbox(*pNym);
		
		OTCleanup<OTLedger> theInboxAngel(pInbox);
		OTCleanup<OTLedger> theOutboxAngel(pOutbox);
		
		if (NULL == pInbox)
		{
			OTLog::vOutput(0, "OT_API::notarizeTransfer: Failed loading inbox for acct: %s\n", strFromAcct.Get());
			// IF FAILED, ADD TRANSACTION NUMBER BACK TO LIST OF AVAILABLE NUMBERS.
			pNym->AddTransactionNum(*pNym, strServerID, lStoredTransactionNumber, true); // bSave=true				
		}		
		else if (NULL == pOutbox)
		{
			OTLog::vOutput(0, "OT_API::notarizeTransfer: Failed loading outbox for acct: %s\n", strFromAcct.Get());
			// IF FAILED, ADD TRANSACTION NUMBER BACK TO LIST OF AVAILABLE NUMBERS.
			pNym->AddTransactionNum(*pNym, strServerID, lStoredTransactionNumber, true); // bSave=true				
		}		
		else 
		{
			// Need to setup a dummy outbox transaction (to mimic the one that will be on the server side when this pending transaction is actually put into the real outbox.)
			// When the server adds its own, and then compares the two, they should both show the same pending transaction, in order for this balance agreement to be valid..
			// Otherwise the server would have to refuse it for being inaccurate (server can't sign something inaccurate!) So I throw a dummy on there before generating balance statement.
			//
			OTTransaction * pOutboxTransaction	= OTTransaction::GenerateTransaction(*pOutbox, OTTransaction::pending,
																					 1/*todo pick some number that everyone agrees doesn't matter, like 1. The referring-to is the important 
																					   number in this case, and perhaps server should update this value too before signing and returning.*/); // todo use a constant instead of '1'
			OT_ASSERT(NULL != pOutboxTransaction); // for now.
			
			OTString strItem(*pItem);
			pOutboxTransaction->SetReferenceString(strItem); // So the GenerateBalanceStatement function below can get the other info off this item (like amount, etc)
			pOutboxTransaction->SetReferenceToNum(pItem->GetTransactionNum());
			
//			pOutboxTransaction->SignContract(*pNym);	// Unnecessary to sign/save, since this is just a dummy data for verification purposes, and isn't being
//			pOutboxTransaction->SaveContract();			// serialized anywhere. (I download the actual outbox from server, and verify against last signed receipt.)
			
			pOutbox->AddTransaction(*pOutboxTransaction);  // no need to cleanup pOutboxTransaction since pOutbox will handle it now.
			// ---------------------------------------------
			// BALANCE AGREEMENT 

			// pBalanceItem is signed and saved within this call. No need to do that twice.
			//
			OTItem * pBalanceItem = pInbox->GenerateBalanceStatement(atol(AMOUNT.Get())*(-1), *pTransaction, *pNym, *pAccount, *pOutbox);				
			
			if (NULL != pBalanceItem) // will never be NULL. Will assert above before it gets here.
				pTransaction->AddItem(*pBalanceItem); // Better not be NULL... message will fail... But better check anyway.
			// ---------------------------------------------
			// sign the transaction
			pTransaction->SignContract(*pNym);
			pTransaction->SaveContract();
			
			// set up the ledger
			OTLedger theLedger(USER_ID, ACCT_FROM, SERVER_ID);
			theLedger.GenerateLedger(ACCT_FROM, SERVER_ID, OTLedger::message); // bGenerateLedger defaults to false, which is correct.
			theLedger.AddTransaction(*pTransaction);
			
			// sign the ledger
			theLedger.SignContract(*pNym);
			theLedger.SaveContract();
			
			// extract the ledger in ascii-armored form
			OTString		strLedger(theLedger);
			OTASCIIArmor	ascLedger;
			
			// Encoding...
			ascLedger.SetString(strLedger);
			// ---------------------------------------------
			// (0) Set up the REQUEST NUMBER and then INCREMENT IT
			pNym->GetCurrentRequestNum(strServerID, lRequestNumber);
			theMessage.m_strRequestNum.Format("%ld", lRequestNumber); // Always have to send this.
			pNym->IncrementRequestNum(*pNym, strServerID); // since I used it for a server request, I have to increment it
			
			// (1) Set up member variables 
			theMessage.m_strCommand			= "notarizeTransactions";
			theMessage.m_strNymID			= strNymID;
			theMessage.m_strServerID		= strServerID;
			theMessage.m_strAcctID			= strFromAcct;
			theMessage.m_ascPayload			= ascLedger;
			
			// (2) Sign the Message 
			theMessage.SignContract(*pNym);		
			
			// (3) Save the Message (with signatures and all, back to its internal member m_strRawFile.)
			theMessage.SaveContract();

			// (Send it)
	#if defined(OT_ZMQ_MODE)
			m_pClient->SetFocusToServerAndNym(*pServer, *pNym, &OT_API::TransportCallback);
	#endif	
			m_pClient->ProcessMessageOut(theMessage);	
		}
	}
	else 
		OTLog::Output(0, "No transaction numbers were available. Suggest requesting the server for one.\n");
		
		// IF FAILED, ADD TRANSACTION NUMBER BACK TO LIST OF AVAILABLE NUMBERS.
//		pNym->AddTransactionNum(*pNym, strServerID, lStoredTransactionNumber, true); // bSave=true	
		// Duh! No need to re-add a transaction num when the error is that there weren't any transaction numbers...
}





void OT_API::getNymbox(OTIdentifier & SERVER_ID,
					   OTIdentifier & USER_ID)
{
	const char * szFuncName = "OT_API::getNymbox";
	// -----------------------------------------------------
	OTPseudonym * pNym = this->GetOrLoadPrivateNym(USER_ID, szFuncName);
	if (NULL == pNym) return;	
	// By this point, pNym is a good pointer, and is on the wallet.
	//  (No need to cleanup.)
	// -----------------------------------------------------
	OTServerContract *	pServer = this->GetServer(SERVER_ID, szFuncName); // This ASSERTs and logs already.
	if (NULL == pServer) return;
	// By this point, pServer is a good pointer.  (No need to cleanup.)
	// -----------------------------------------------------
	OTMessage theMessage;
	long lRequestNumber = 0;
	
	OTString strServerID(SERVER_ID), strNymID(USER_ID);
	
	// (0) Set up the REQUEST NUMBER and then INCREMENT IT
	pNym->GetCurrentRequestNum(strServerID, lRequestNumber);
	theMessage.m_strRequestNum.Format("%ld", lRequestNumber); // Always have to send this.
	pNym->IncrementRequestNum(*pNym, strServerID); // since I used it for a server request, I have to increment it
	
	// (1) set up member variables 
	theMessage.m_strCommand			= "getNymbox";
	theMessage.m_strNymID			= strNymID;
	theMessage.m_strServerID		= strServerID;
	
	// (2) Sign the Message 
	theMessage.SignContract(*pNym);		
	
	// (3) Save the Message (with signatures and all, back to its internal member m_strRawFile.)
	theMessage.SaveContract();
	
	// (Send it)
#if defined(OT_ZMQ_MODE)
	m_pClient->SetFocusToServerAndNym(*pServer, *pNym, &OT_API::TransportCallback);
#endif	
	m_pClient->ProcessMessageOut(theMessage);	
}



void OT_API::getInbox(OTIdentifier & SERVER_ID,
					  OTIdentifier & USER_ID,
					  OTIdentifier & ACCT_ID)
{
	const char * szFuncName = "OT_API::getInbox";
	// -----------------------------------------------------
	OTPseudonym * pNym = this->GetOrLoadPrivateNym(USER_ID, szFuncName);
	if (NULL == pNym) return;	
	// By this point, pNym is a good pointer, and is on the wallet.
	//  (No need to cleanup.)
	// -----------------------------------------------------
	OTServerContract *	pServer = this->GetServer(SERVER_ID, szFuncName); // This ASSERTs and logs already.
	if (NULL == pServer) return;
	// By this point, pServer is a good pointer.  (No need to cleanup.)
	// -----------------------------------------------------
	OTAccount * pAccount = this->GetOrLoadAccount(*pNym, ACCT_ID, SERVER_ID, szFuncName);
	if (NULL == pAccount) return;
	// By this point, pAccount is a good pointer.  (No need to cleanup.)
	// -----------------------------------------------------
	OTMessage theMessage;
	long lRequestNumber = 0;
	
	OTString strServerID(SERVER_ID), strNymID(USER_ID), strAcctID(ACCT_ID);
	
	// (0) Set up the REQUEST NUMBER and then INCREMENT IT
	pNym->GetCurrentRequestNum(strServerID, lRequestNumber);
	theMessage.m_strRequestNum.Format("%ld", lRequestNumber); // Always have to send this.
	pNym->IncrementRequestNum(*pNym, strServerID); // since I used it for a server request, I have to increment it
	
	// (1) set up member variables 
	theMessage.m_strCommand			= "getInbox";
	theMessage.m_strNymID			= strNymID;
	theMessage.m_strServerID		= strServerID;
	theMessage.m_strAcctID			= strAcctID;
	
	// (2) Sign the Message 
	theMessage.SignContract(*pNym);		
	
	// (3) Save the Message (with signatures and all, back to its internal member m_strRawFile.)
	theMessage.SaveContract();
	
	// (Send it)
#if defined(OT_ZMQ_MODE)
	m_pClient->SetFocusToServerAndNym(*pServer, *pNym, &OT_API::TransportCallback);
#endif	
	m_pClient->ProcessMessageOut(theMessage);	
}




void OT_API::getOutbox(OTIdentifier & SERVER_ID,
					  OTIdentifier & USER_ID,
					  OTIdentifier & ACCT_ID)
{
	const char * szFuncName = "OT_API::getOutbox";
	// -----------------------------------------------------
	OTPseudonym * pNym = this->GetOrLoadPrivateNym(USER_ID, szFuncName);
	if (NULL == pNym) return;	
	// By this point, pNym is a good pointer, and is on the wallet.
	//  (No need to cleanup.)
	// -----------------------------------------------------
	OTServerContract *	pServer = this->GetServer(SERVER_ID, szFuncName); // This ASSERTs and logs already.
	if (NULL == pServer) return;
	// By this point, pServer is a good pointer.  (No need to cleanup.)
	// -----------------------------------------------------
	OTAccount * pAccount = this->GetOrLoadAccount(*pNym, ACCT_ID, SERVER_ID, szFuncName);
	if (NULL == pAccount) return;
	// By this point, pAccount is a good pointer.  (No need to cleanup.)
	// -----------------------------------------------------
	OTMessage theMessage;
	long lRequestNumber = 0;
	
	OTString strServerID(SERVER_ID), strNymID(USER_ID), strAcctID(ACCT_ID);
	
	// (0) Set up the REQUEST NUMBER and then INCREMENT IT
	pNym->GetCurrentRequestNum(strServerID, lRequestNumber);
	theMessage.m_strRequestNum.Format("%ld", lRequestNumber); // Always have to send this.
	pNym->IncrementRequestNum(*pNym, strServerID); // since I used it for a server request, I have to increment it
	
	// (1) set up member variables 
	theMessage.m_strCommand			= "getOutbox";
	theMessage.m_strNymID			= strNymID;
	theMessage.m_strServerID		= strServerID;
	theMessage.m_strAcctID			= strAcctID;
	
	// (2) Sign the Message 
	theMessage.SignContract(*pNym);		
	
	// (3) Save the Message (with signatures and all, back to its internal member m_strRawFile.)
	theMessage.SaveContract();
	
	// (Send it)
#if defined(OT_ZMQ_MODE)
	m_pClient->SetFocusToServerAndNym(*pServer, *pNym, &OT_API::TransportCallback);
#endif	
	m_pClient->ProcessMessageOut(theMessage);	
}




// Returns:
// -1 if error.
//  0 if Nymbox is empty.
//  1 or more: Count of items in Nymbox before processing.
//
int OT_API::processNymbox(OTIdentifier	& SERVER_ID,
						  OTIdentifier	& USER_ID)
{
	const char * szFuncName = "OT_API::processNymbox";
	// -----------------------------------------------------
	OTPseudonym * pNym = this->GetOrLoadPrivateNym(USER_ID, szFuncName);
	if (NULL == pNym) return (-1);	
	// By this point, pNym is a good pointer, and is on the wallet.
	//  (No need to cleanup.)
	const OTString strNymID(USER_ID);
	// -----------------------------------------------------
	OTServerContract *	pServer = this->GetServer(SERVER_ID, szFuncName); // This ASSERTs and logs already.
	if (NULL == pServer) return (-1);
	// By this point, pServer is a good pointer.  (No need to cleanup.)
	// -----------------------------------------------------
	OTMessage	theMessage;
	bool		bSuccess		= false;
	int			nReceiptCount	= (-1);
	bool		bIsEmpty		= true;

	{
		OTPseudonym			& theNym	= *pNym;
		OTServerContract	& theServer	= *pServer;
		
		// Load up the appropriate Nymbox... 
		OTLedger theNymbox (USER_ID, USER_ID, SERVER_ID);
		
		bool	bLoadedNymbox	= theNymbox.LoadNymbox();
		bool	bVerifiedNymbox	= bLoadedNymbox ? theNymbox.VerifyAccount(theNym) : false;
		
		if (false == bLoadedNymbox)
			OTLog::vOutput(0, "OT_API::processNymbox: Failed loading Nymbox: %s \n",
						   strNymID.Get());
		else if (false == bVerifiedNymbox)
			OTLog::vOutput(0, "OT_API::processNymbox: Failed verifying Nymbox: %s \n",
						   strNymID.Get());
		// --------------------------------------
		else
		{
			nReceiptCount	= theNymbox.GetTransactionCount();
			bIsEmpty		= (nReceiptCount < 1);
			
			// -----------------
			if (!bIsEmpty)
				bSuccess = m_pClient->AcceptEntireNymbox(theNymbox, SERVER_ID, theServer, theNym, theMessage);
			// -----------------
			
			if (!bSuccess)
			{
				if (bIsEmpty)
					OTLog::vOutput(0, "OT_API::processNymbox: Nymbox (%s) is empty (so, skipping processNymbox.)\n",
								   strNymID.Get());
				else
				{
					OTLog::vOutput(0, "OT_API::processNymbox: Failed trying to accept the entire Nymbox. (And no, it's not empty.)\n");
					nReceiptCount = (-1);
				}
			}
			else	// Success!
			{
				// (2) Sign the Message 
				theMessage.SignContract(theNym);		
				
				// (3) Save the Message (with signatures and all, back to its internal member m_strRawFile.)
				theMessage.SaveContract();
			}			
		}
		// --------------------------------------
	}
	
	if (bSuccess)
	{				
#if defined(OT_ZMQ_MODE)
		m_pClient->SetFocusToServerAndNym(*pServer, *pNym, &OT_API::TransportCallback);
#endif	
		m_pClient->ProcessMessageOut(theMessage);
	}
	// if successful, ..., else if not successful--and wasn't empty--then error.
	else if (!bIsEmpty)  
		OTLog::Error("Error performing processNymbox command in OT_API::processNymbox\n");
	
	return nReceiptCount;
}




void OT_API::processInbox(OTIdentifier	& SERVER_ID,
						  OTIdentifier	& USER_ID,
						  OTIdentifier	& ACCT_ID,
						  OTString		& ACCT_LEDGER)
{
	const char * szFuncName = "OT_API::processInbox";
	// -----------------------------------------------------
	OTPseudonym * pNym = this->GetOrLoadPrivateNym(USER_ID, szFuncName);
	if (NULL == pNym) return;	
	// By this point, pNym is a good pointer, and is on the wallet.
	//  (No need to cleanup.)
	// -----------------------------------------------------
	OTServerContract *	pServer = this->GetServer(SERVER_ID, szFuncName); // This ASSERTs and logs already.
	if (NULL == pServer) return;
	// By this point, pServer is a good pointer.  (No need to cleanup.)
	// -----------------------------------------------------
	OTAccount * pAccount = this->GetOrLoadAccount(*pNym, ACCT_ID, SERVER_ID, szFuncName);
	if (NULL == pAccount) return;
	// By this point, pAccount is a good pointer.  (No need to cleanup.)
	// -----------------------------------------------------
	OTMessage theMessage;
	long lRequestNumber = 0;
	
	OTString strServerID(SERVER_ID), strNymID(USER_ID), strAcctID(ACCT_ID);
	
	// (0) Set up the REQUEST NUMBER and then INCREMENT IT
	pNym->GetCurrentRequestNum(strServerID, lRequestNumber);
	theMessage.m_strRequestNum.Format("%ld", lRequestNumber); // Always have to send this.
	pNym->IncrementRequestNum(*pNym, strServerID); // since I used it for a server request, I have to increment it
	
	// (1) set up member variables 
	theMessage.m_strCommand			= "processInbox";
	theMessage.m_strNymID			= strNymID;
	theMessage.m_strServerID		= strServerID;
	theMessage.m_strAcctID			= strAcctID;
	
	// Presumably ACCT_LEDGER was already set up before this function was called...
	// See test client for example of it being done.
	theMessage.m_ascPayload.SetString(ACCT_LEDGER);
	
	// (2) Sign the Message 
	theMessage.SignContract(*pNym);		
	
	// (3) Save the Message (with signatures and all, back to its internal member m_strRawFile.)
	theMessage.SaveContract();
	
	// (Send it)
#if defined(OT_ZMQ_MODE)
	m_pClient->SetFocusToServerAndNym(*pServer, *pNym, &OT_API::TransportCallback);
#endif	
	m_pClient->ProcessMessageOut(theMessage);	
}



void OT_API::issueAssetType(OTIdentifier	&	SERVER_ID,
							OTIdentifier	&	USER_ID,
							OTString		&	THE_CONTRACT)
{
	const char * szFuncName = "OT_API::issueAssetType";
	// -----------------------------------------------------
	OTWallet * pWallet = this->GetWallet(szFuncName);
	if (NULL == pWallet) return;
	// -----------------------------------------------------
	OTPseudonym * pNym = this->GetOrLoadPrivateNym(USER_ID, szFuncName);
	if (NULL == pNym) return;	
	// By this point, pNym is a good pointer, and is on the wallet.
	//  (No need to cleanup.)
	// -----------------------------------------------------
	OTServerContract *	pServer = this->GetServer(SERVER_ID, szFuncName); // This ASSERTs and logs already.
	if (NULL == pServer) return;
	// By this point, pServer is a good pointer.  (No need to cleanup.)
	// -----------------------------------------------------
	//	OTLog::vError("OT_API::issueAssetType: About to trim this contract:  **BEGIN:%s***END\n\n",
//				 THE_CONTRACT.Get());
	
	std::string str_Trim(THE_CONTRACT.Get());
	std::string str_Trim2 = OTString::trim(str_Trim);
	OTString strTrimContract(str_Trim2.c_str());
	// -----------------------------------------------------
	
	OTAssetContract theAssetContract;
	
	if (theAssetContract.LoadContractFromString(strTrimContract))
	{
		OTIdentifier	newID;
		theAssetContract.CalculateContractID(newID);
		theAssetContract.SetIdentifier(newID); // probably unnecessary
		// -----------------------
		OTMessage theMessage;
		long lRequestNumber = 0;
		
		OTString strServerID(SERVER_ID), strNymID(USER_ID);
		
		// (0) Set up the REQUEST NUMBER and then INCREMENT IT
		pNym->GetCurrentRequestNum(strServerID, lRequestNumber);
		theMessage.m_strRequestNum.Format("%ld", lRequestNumber); // Always have to send this.
		pNym->IncrementRequestNum(*pNym, strServerID); // since I used it for a server request, I have to increment it
		
		// (1) set up member variables 
		theMessage.m_strCommand			= "issueAssetType";
		theMessage.m_strNymID			= strNymID;
		theMessage.m_strServerID		= strServerID;
		
		newID.GetString(theMessage.m_strAssetID);
		OTString strAssetContract(theAssetContract);
		theMessage.m_ascPayload.SetString(strAssetContract);
		
		// (2) Sign the Message 
		theMessage.SignContract(*pNym);
		
		// (3) Save the Message (with signatures and all, back to its internal member m_strRawFile.)
		theMessage.SaveContract();
		
		// ------------------------------------ 
		// Save the contract to local storage and add to wallet.
		//
		OTString strFilename;	// In this case the filename isn't actually used, since SaveToContractFolder will
		// handle setting up the filename and overwrite it anyway. But I still prefer to set it
		// up correctly, rather than pass a blank. I'm just funny like that.
		strFilename = theMessage.m_strAssetID.Get();
		
		OTString strFoldername(OTLog::ContractFolder());
		
		OTAssetContract * pContract = new OTAssetContract(theMessage.m_strAssetID, strFoldername,
														  strFilename, theMessage.m_strAssetID);
		OT_ASSERT(NULL != pContract);
		
		// Check the server signature on the contract here. (Perhaps the message is good enough?
		// After all, the message IS signed by the server and contains the Account.
//		if (pContract->LoadContract() && pContract->VerifyContract())
		if (pContract->LoadContractFromString(strTrimContract) && pContract->VerifyContract())
		{
			// Next make sure the wallet has this contract on its list...			
			pWallet->AddAssetContract(*pContract); // this saves both the contract and the wallet.
			pContract = NULL; // Success. The wallet "owns" it now, no need to clean it up.
		}
		// cleanup
		if (pContract)
		{
			delete pContract;
			pContract = NULL;
		}
		// ----------------------------
		
		// (Send it)
#if defined(OT_ZMQ_MODE)
		m_pClient->SetFocusToServerAndNym(*pServer, *pNym, &OT_API::TransportCallback);
#endif	
		m_pClient->ProcessMessageOut(theMessage);
	}
}



void OT_API::getContract(OTIdentifier & SERVER_ID,
						 OTIdentifier & USER_ID,
						 OTIdentifier & ASSET_ID)
{
	const char * szFuncName = "OT_API::getContract";
	// -----------------------------------------------------
	OTPseudonym * pNym = this->GetOrLoadPrivateNym(USER_ID, szFuncName);
	if (NULL == pNym) return;	
	// By this point, pNym is a good pointer, and is on the wallet.
	//  (No need to cleanup.)
	// -----------------------------------------------------
	OTServerContract *	pServer = this->GetServer(SERVER_ID, szFuncName); // This ASSERTs and logs already.
	if (NULL == pServer) return;
	// By this point, pServer is a good pointer.  (No need to cleanup.)
	// -----------------------------------------------------
	OTMessage theMessage;
	long lRequestNumber = 0;
	
	OTString strServerID(SERVER_ID), strNymID(USER_ID), strAssetTypeID(ASSET_ID);
	
	// (0) Set up the REQUEST NUMBER and then INCREMENT IT
	pNym->GetCurrentRequestNum(strServerID, lRequestNumber);
	theMessage.m_strRequestNum.Format("%ld", lRequestNumber); // Always have to send this.
	pNym->IncrementRequestNum(*pNym, strServerID); // since I used it for a server request, I have to increment it
	
	// (1) set up member variables 
	theMessage.m_strCommand			= "getContract";
	theMessage.m_strNymID			= strNymID;
	theMessage.m_strServerID		= strServerID;
	theMessage.m_strAssetID			= strAssetTypeID;
	
	// (2) Sign the Message 
	theMessage.SignContract(*pNym);		
	
	// (3) Save the Message (with signatures and all, back to its internal member m_strRawFile.)
	theMessage.SaveContract();
	
	// (Send it)
#if defined(OT_ZMQ_MODE)
	m_pClient->SetFocusToServerAndNym(*pServer, *pNym, &OT_API::TransportCallback);
#endif	
	m_pClient->ProcessMessageOut(theMessage);	
}






void OT_API::getMint(OTIdentifier & SERVER_ID,
					 OTIdentifier & USER_ID,
					 OTIdentifier & ASSET_ID)
{
	const char * szFuncName = "OT_API::getMint";
	// -----------------------------------------------------
	OTPseudonym * pNym = this->GetOrLoadPrivateNym(USER_ID, szFuncName);
	if (NULL == pNym) return;	
	// By this point, pNym is a good pointer, and is on the wallet.
	//  (No need to cleanup.)
	// -----------------------------------------------------
	OTServerContract *	pServer = this->GetServer(SERVER_ID, szFuncName); // This ASSERTs and logs already.
	if (NULL == pServer) return;
	// By this point, pServer is a good pointer.  (No need to cleanup.)
	// -----------------------------------------------------
	OTAssetContract *	pAssetContract = this->GetAssetType(ASSET_ID, szFuncName); // This ASSERTs and logs already.
	if (NULL == pAssetContract) return;
	// By this point, pAssetContract is a good pointer.  (No need to cleanup.)
	// -----------------------------------------------------
	OTMessage theMessage;
	long lRequestNumber = 0;
	
	OTString strServerID(SERVER_ID), strNymID(USER_ID), strAssetTypeID(ASSET_ID);
	
	// (0) Set up the REQUEST NUMBER and then INCREMENT IT
	pNym->GetCurrentRequestNum(strServerID, lRequestNumber);
	theMessage.m_strRequestNum.Format("%ld", lRequestNumber); // Always have to send this.
	pNym->IncrementRequestNum(*pNym, strServerID); // since I used it for a server request, I have to increment it
	
	// (1) set up member variables 
	theMessage.m_strCommand			= "getMint";
	theMessage.m_strNymID			= strNymID;
	theMessage.m_strServerID		= strServerID;
	theMessage.m_strAssetID			= strAssetTypeID;
	
	// (2) Sign the Message 
	theMessage.SignContract(*pNym);		
	
	// (3) Save the Message (with signatures and all, back to its internal member m_strRawFile.)
	theMessage.SaveContract();
	
	// (Send it)
#if defined(OT_ZMQ_MODE)
	m_pClient->SetFocusToServerAndNym(*pServer, *pNym, &OT_API::TransportCallback);
#endif	
	m_pClient->ProcessMessageOut(theMessage);	
}



// Sends a list of asset IDs to the server, which replies with a list of the actual receipts
// with the issuer's signature on them, from when the currency was issued.
//
// So you can tell for sure whether or not they are actually issued on that server.
//
// Map input: key is asset type ID, and value is blank (server reply puts issuer's receipts
// in that spot.)
//
void OT_API::queryAssetTypes(OTIdentifier & SERVER_ID,
							 OTIdentifier & USER_ID,
							 OTASCIIArmor & ENCODED_MAP)
{
	/*
	 // Java code will create a StringMap object:
	 
		String strEncodedObj(""); // output will go here.
		StringMap stringMap = null;	// we are about to create this object

		Storable storable = otapi.CreateObject(StoredObjectType.STORED_OBJ_STRING_MAP);
		
		if (storable != null) 
		{
            stringMap = StringMap.ot_dynamic_cast(storable);
            if (stringMap != null) 
			{
				// ADD ALL THE ASSET IDs HERE (To the string map, so you
				// can ask the server about them...)
				//
				for_each(the asset IDs you want to query the server about)
				{
					stringMap.SetValue(ASSET_TYPE_ID, "exists"); 
				}

				strEncodedObj = otapi.EncodeObject(stringMap);
            }
        }
		
		if (null == strEncodedObj)
			Error;
	 ----------------------------------------------------------------------
	 
		Then send the server message:
	 
	 var theRequest := OTAPI_Func(ot_Msg.QUERY_ASSET_TYPES, SERVER_ID, NYM_ID, strEncodedObj);
	 var	strResponse = theRequest.SendRequest(theRequest, "QUERY_ASSET_TYPES");

	 String strReplyMap = null;
	 
	 // When the server reply comes back, get the payload from it:
	 //
	 if (strResponse != null)
		strReplyMap = OT_API_Message_GetPayload(strReply);
	 ----------------------------------------------------------------------
	 
		//	Pass the payload (the StringMap from the server's reply) to otapi.DecodeObject:
		//
		if (strReplyMap != null)
		{
			StringMap stringMap = null;
			Storable storable = otapi.DecodeObject(StoredObjectType.STORED_OBJ_STRING_MAP, strReplyMap);
			if (storable != null) 
			{
				stringMap = StringMap.ot_dynamic_cast(storable);
				if (stringMap != null) 
				{
					// Loop through string map. For each asset ID key, the value will 
					// say either "true" or "false".
					//
					for_each(stringMap)
					{
						strValue = stringMap.GetValue(ASSET_TYPE_ID);
	 
						if (strValue.compare("true") == 0)
						{
							// ... do something here ...
						}
					}
				}
			}
		}

	 */
	const char * szFuncName = "OT_API::queryAssetTypes";
	// -----------------------------------------------------
	OTPseudonym * pNym = this->GetOrLoadPrivateNym(USER_ID, szFuncName);
	if (NULL == pNym) return;	
	// By this point, pNym is a good pointer, and is on the wallet.
	//  (No need to cleanup.)
	// -----------------------------------------------------
	OTServerContract *	pServer = this->GetServer(SERVER_ID, szFuncName); // This ASSERTs and logs already.
	if (NULL == pServer) return;
	// By this point, pServer is a good pointer.  (No need to cleanup.)
	// -----------------------------------------------------
	OTMessage theMessage;
	long lRequestNumber = 0;
	
	OTString strServerID(SERVER_ID), strNymID(USER_ID);
	
	// (0) Set up the REQUEST NUMBER and then INCREMENT IT
	pNym->GetCurrentRequestNum(strServerID, lRequestNumber);
	theMessage.m_strRequestNum.Format("%ld", lRequestNumber); // Always have to send this.
	pNym->IncrementRequestNum(*pNym, strServerID); // since I used it for a server request, I have to increment it
	
	// (1) set up member variables 
	theMessage.m_strCommand			= "queryAssetTypes";
	theMessage.m_strNymID			= strNymID;
	theMessage.m_strServerID		= strServerID;
	theMessage.m_ascPayload			= ENCODED_MAP;
	
	// (2) Sign the Message 
	theMessage.SignContract(*pNym);		
	
	// (3) Save the Message (with signatures and all, back to its internal member m_strRawFile.)
	theMessage.SaveContract();
	
	// (Send it)
#if defined(OT_ZMQ_MODE)
	m_pClient->SetFocusToServerAndNym(*pServer, *pNym, &OT_API::TransportCallback);
#endif	
	m_pClient->ProcessMessageOut(theMessage);
}



void OT_API::createAssetAccount(OTIdentifier & SERVER_ID,
								OTIdentifier & USER_ID,
								OTIdentifier & ASSET_ID)
{	
	const char * szFuncName = "OT_API::createAssetAccount";
	// -----------------------------------------------------
	OTPseudonym * pNym = this->GetOrLoadPrivateNym(USER_ID, szFuncName);
	if (NULL == pNym) return;	
	// By this point, pNym is a good pointer, and is on the wallet.
	//  (No need to cleanup.)
	// -----------------------------------------------------
	OTServerContract *	pServer = this->GetServer(SERVER_ID, szFuncName); // This ASSERTs and logs already.
	if (NULL == pServer) return;
	// By this point, pServer is a good pointer.  (No need to cleanup.)
	// -----------------------------------------------------
	OTAssetContract *	pAssetContract = this->GetAssetType(ASSET_ID, szFuncName); // This ASSERTs and logs already.
	if (NULL == pAssetContract) return;
	// By this point, pAssetContract is a good pointer.  (No need to cleanup.)
	// -----------------------------------------------------
	OTMessage theMessage;
	long lRequestNumber = 0;
	
	OTString strServerID(SERVER_ID), strNymID(USER_ID), strAssetTypeID(ASSET_ID);
	
	// (0) Set up the REQUEST NUMBER and then INCREMENT IT
	pNym->GetCurrentRequestNum(strServerID, lRequestNumber);
	theMessage.m_strRequestNum.Format("%ld", lRequestNumber); // Always have to send this.
	pNym->IncrementRequestNum(*pNym, strServerID); // since I used it for a server request, I have to increment it
	
	// (1) set up member variables 
	theMessage.m_strCommand			= "createAccount";
	theMessage.m_strNymID			= strNymID;
	theMessage.m_strServerID		= strServerID;
	theMessage.m_strAssetID			= strAssetTypeID;
	
	// (2) Sign the Message 
	theMessage.SignContract(*pNym);		
	
	// (3) Save the Message (with signatures and all, back to its internal member m_strRawFile.)
	theMessage.SaveContract();
	
	// (Send it)
#if defined(OT_ZMQ_MODE)
	m_pClient->SetFocusToServerAndNym(*pServer, *pNym, &OT_API::TransportCallback);
#endif	
	m_pClient->ProcessMessageOut(theMessage);
}



void OT_API::deleteAssetAccount(OTIdentifier & SERVER_ID,
								OTIdentifier & USER_ID,
								OTIdentifier & ACCOUNT_ID)
{	
	const char * szFuncName = "OT_API::deleteAssetAccount";
	// -----------------------------------------------------
	OTPseudonym * pNym = this->GetOrLoadPrivateNym(USER_ID, szFuncName);
	if (NULL == pNym) return;	
	// By this point, pNym is a good pointer, and is on the wallet.
	//  (No need to cleanup.)
	// -----------------------------------------------------
	OTServerContract *	pServer = this->GetServer(SERVER_ID, szFuncName); // This ASSERTs and logs already.
	if (NULL == pServer) return;
	// By this point, pServer is a good pointer.  (No need to cleanup.)
	// -----------------------------------------------------
	OTAccount * pAccount = this->GetOrLoadAccount(*pNym, ACCOUNT_ID, SERVER_ID, szFuncName);
	if (NULL == pAccount) return;
	// By this point, pAccount is a good pointer, and is on the wallet. (No need to cleanup.)
	// -----------------------------------------------------
	OTMessage theMessage;
	long lRequestNumber = 0;
	
	OTString strServerID(SERVER_ID), strNymID(USER_ID), strAcctID(ACCOUNT_ID);
	
	// (0) Set up the REQUEST NUMBER and then INCREMENT IT
	pNym->GetCurrentRequestNum(strServerID, lRequestNumber);
	theMessage.m_strRequestNum.Format("%ld", lRequestNumber); // Always have to send this.
	pNym->IncrementRequestNum(*pNym, strServerID); // since I used it for a server request, I have to increment it
	
	// (1) set up member variables 
	theMessage.m_strCommand			= "deleteAssetAccount";
	theMessage.m_strNymID			= strNymID;
	theMessage.m_strServerID		= strServerID;
	theMessage.m_strAcctID			= strAcctID;
	
	// (2) Sign the Message 
	theMessage.SignContract(*pNym);		
	
	// (3) Save the Message (with signatures and all, back to its internal member m_strRawFile.)
	theMessage.SaveContract();
	
	// (Send it)
#if defined(OT_ZMQ_MODE)
	m_pClient->SetFocusToServerAndNym(*pServer, *pNym, &OT_API::TransportCallback);
#endif	
	m_pClient->ProcessMessageOut(theMessage);
}






bool OT_API::DoesBoxReceiptExist(const OTIdentifier & SERVER_ID,
								 const OTIdentifier & USER_ID,	// Unused here for now, but still convention.
								 const OTIdentifier & ACCOUNT_ID,	// If for Nymbox (vs inbox/outbox) then pass USER_ID in this field also.
								 const int			nBoxType,	// 0/nymbox, 1/inbox, 2/outbox
								 const long		  &	lTransactionNum)
{
			//static
	return	OTTransaction::VerifyBoxReceiptExists(SERVER_ID,
												  USER_ID,		// Unused here for now, but still convention.
												  ACCOUNT_ID,	// If for Nymbox (vs inbox/outbox) then pass USER_ID in this field also.
												  nBoxType,		// 0/nymbox, 1/inbox, 2/outbox
												  lTransactionNum);
}




void OT_API::getBoxReceipt(const OTIdentifier & SERVER_ID,
						   const OTIdentifier & USER_ID,
						   const OTIdentifier & ACCOUNT_ID,		// If for Nymbox (vs inbox/outbox) then pass USER_ID in this field also.
						   const int			nBoxType,		// 0/nymbox, 1/inbox, 2/outbox
						   const long		  &	lTransactionNum)
{	
	const char * szFuncName = "OT_API::getBoxReceipt";
	// -----------------------------------------------------
	OTPseudonym * pNym = this->GetOrLoadPrivateNym(USER_ID, szFuncName);
	if (NULL == pNym) return;	
	// By this point, pNym is a good pointer, and is on the wallet.
	//  (No need to cleanup.)
	// -----------------------------------------------------
	OTServerContract *	pServer = this->GetServer(SERVER_ID, szFuncName); // This ASSERTs and logs already.
	if (NULL == pServer) return;
	// By this point, pServer is a good pointer.  (No need to cleanup.)
	// -----------------------------------------------------
	OTAccount * pAccount = NULL;
	if (USER_ID != ACCOUNT_ID) // inbox/outbox (if it were nymbox, the USER_ID and ACCOUNT_ID would match)
	{
		pAccount =	this->GetOrLoadAccount(*pNym, ACCOUNT_ID, SERVER_ID, szFuncName);
		if (NULL == pAccount) return;
	}
	// By this point, pAccount is a good pointer, and is on the wallet. (No need to cleanup.)
	// Note: pAccount could be NULL also, but this function doesn't actually use it anyway.
	// I just force it to load in order to keep things clean, since this is an API call. (I'm
	// real strict on the API user, making him keep his nose clean.)
	// -----------------------------------------------------
	OTMessage theMessage;
	long lRequestNumber = 0;
	
	const OTString strServerID(SERVER_ID), strNymID(USER_ID), strAcctID(ACCOUNT_ID);
	
	// (0) Set up the REQUEST NUMBER and then INCREMENT IT
	pNym->GetCurrentRequestNum(strServerID, lRequestNumber);
	theMessage.m_strRequestNum.Format("%ld", lRequestNumber); // Always have to send this.
	pNym->IncrementRequestNum(*pNym, strServerID); // since I used it for a server request, I have to increment it
	
	// (1) set up member variables 
	theMessage.m_strCommand			= "getBoxReceipt";
	theMessage.m_strNymID			= strNymID;
	theMessage.m_strServerID		= strServerID;
	theMessage.m_strAcctID			= strAcctID;
	theMessage.m_lDepth				= static_cast<long>(nBoxType);
	theMessage.m_lTransactionNum	= lTransactionNum;
	
	// (2) Sign the Message 
	theMessage.SignContract(*pNym);		
	
	// (3) Save the Message (with signatures and all, back to its internal member m_strRawFile.)
	theMessage.SaveContract();
	
	// (Send it)
#if defined(OT_ZMQ_MODE)
	m_pClient->SetFocusToServerAndNym(*pServer, *pNym, &OT_API::TransportCallback);
#endif	
	m_pClient->ProcessMessageOut(theMessage);
}





void OT_API::getAccount(OTIdentifier	& SERVER_ID,
						OTIdentifier	& USER_ID,
						OTIdentifier	& ACCT_ID)
{	
	const char * szFuncName = "OT_API::getAccount";
	// -----------------------------------------------------
	OTPseudonym * pNym = this->GetOrLoadPrivateNym(USER_ID, szFuncName); // This ASSERTs and logs already.
	if (NULL == pNym) return;	
	// By this point, pNym is a good pointer, and is on the wallet.
	//  (No need to cleanup.)
	// -----------------------------------------------------
	OTServerContract *	pServer = this->GetServer(SERVER_ID, szFuncName); // This ASSERTs and logs already.
	if (NULL == pServer) return;
	// By this point, pServer is a good pointer.  (No need to cleanup.)
	// -----------------------------------------------------
	OTAccount * pAccount = this->GetOrLoadAccount(*pNym, ACCT_ID, SERVER_ID, szFuncName);
	if (NULL == pAccount) return;
	// By this point, pAccount is a good pointer, and is on the wallet. (No need to cleanup.)
	// -----------------------------------------------------
	OTMessage theMessage;
	long lRequestNumber = 0;
	
	OTString strServerID(SERVER_ID), strNymID(USER_ID), strAcctID(ACCT_ID);
	
	// (0) Set up the REQUEST NUMBER and then INCREMENT IT
	pNym->GetCurrentRequestNum(strServerID, lRequestNumber);
	theMessage.m_strRequestNum.Format("%ld", lRequestNumber); // Always have to send this.
	pNym->IncrementRequestNum(*pNym, strServerID); // since I used it for a server request, I have to increment it
	
	// (1) set up member variables 
	theMessage.m_strCommand			= "getAccount";
	theMessage.m_strNymID			= strNymID;
	theMessage.m_strServerID		= strServerID;
	theMessage.m_strAcctID			= strAcctID;
	
	// (2) Sign the Message 
	theMessage.SignContract(*pNym);		
	
	// (3) Save the Message (with signatures and all, back to its internal member m_strRawFile.)
	theMessage.SaveContract();
	
	// (Send it)
#if defined(OT_ZMQ_MODE)
	m_pClient->SetFocusToServerAndNym(*pServer, *pNym, &OT_API::TransportCallback);
#endif	
	m_pClient->ProcessMessageOut(theMessage);
}




void OT_API::getRequest(OTIdentifier	& SERVER_ID,
						OTIdentifier	& USER_ID)
{	
	const char * szFuncName = "OT_API::getRequest";
	// -----------------------------------------------------
	OTPseudonym * pNym = this->GetOrLoadPrivateNym(USER_ID, szFuncName); // This ASSERTs and logs already.
	if (NULL == pNym) return;	
	// By this point, pNym is a good pointer, and is on the wallet.
	//  (No need to cleanup.)
	// -----------------------------------------------------
	OTServerContract *	pServer = this->GetServer(SERVER_ID, szFuncName); // This ASSERTs and logs already.
	if (NULL == pServer) return;
	// By this point, pServer is a good pointer.  (No need to cleanup.)
	// -----------------------------------------------------
	OTMessage theMessage;
	
	if (m_pClient->ProcessUserCommand(OTClient::getRequest, theMessage, 
									*pNym, *pServer,
									NULL)) // NULL pAccount on this command.
	{				
#if defined(OT_ZMQ_MODE)
		m_pClient->SetFocusToServerAndNym(*pServer, *pNym, &OT_API::TransportCallback);
#endif	
		m_pClient->ProcessMessageOut(theMessage);
	}
	else
		OTLog::Error("Error processing getRequest command in OT_API::getRequest\n");
}






void OT_API::usageCredits(const OTIdentifier &	SERVER_ID,
						  const OTIdentifier &	USER_ID,
						  const OTIdentifier &	USER_ID_CHECK,
						  const long			lAdjustment/*=0*/)
{	
	const char * szFuncName = "OT_API::usageCredits";
	// -----------------------------------------------------
	OTPseudonym * pNym = this->GetOrLoadPrivateNym(USER_ID, szFuncName); // This ASSERTs and logs already.
	if (NULL == pNym) return;	
	// By this point, pNym is a good pointer, and is on the wallet.
	//  (No need to cleanup.)
	// -----------------------------------------------------
	OTServerContract *	pServer = this->GetServer(SERVER_ID, szFuncName); // This ASSERTs and logs already.
	if (NULL == pServer) return;
	// By this point, pServer is a good pointer.  (No need to cleanup.)
	// -----------------------------------------------------
	OTMessage theMessage;
	long lRequestNumber = 0;
	
	OTString strServerID(SERVER_ID), strNymID(USER_ID), strNymID2(USER_ID_CHECK);
	
	// (0) Set up the REQUEST NUMBER and then INCREMENT IT
	pNym->GetCurrentRequestNum(strServerID, lRequestNumber);
	theMessage.m_strRequestNum.Format("%ld", lRequestNumber); // Always have to send this.
	pNym->IncrementRequestNum(*pNym, strServerID); // since I used it for a server request, I have to increment it
	
	// (1) set up member variables 
	theMessage.m_strCommand			= "usageCredits";
	theMessage.m_strNymID			= strNymID;
	theMessage.m_strNymID2			= strNymID2;
	theMessage.m_strServerID		= strServerID;
	
	theMessage.m_lDepth				= lAdjustment; // Default is "no adjustment" (@usageCredits returns current balance regardless.)
	
	// (2) Sign the Message 
	theMessage.SignContract(*pNym);		
	
	// (3) Save the Message (with signatures and all, back to its internal member m_strRawFile.)
	theMessage.SaveContract();
	
	// (Send it)
#if defined(OT_ZMQ_MODE)
	m_pClient->SetFocusToServerAndNym(*pServer, *pNym, &OT_API::TransportCallback);
#endif	
	m_pClient->ProcessMessageOut(theMessage);
}



void OT_API::checkUser(OTIdentifier & SERVER_ID,
					   OTIdentifier & USER_ID,
					   OTIdentifier & USER_ID_CHECK)
{	
	const char * szFuncName = "OT_API::checkUser";
	// -----------------------------------------------------
	OTPseudonym * pNym = this->GetOrLoadPrivateNym(USER_ID, szFuncName); // This ASSERTs and logs already.
	if (NULL == pNym) return;	
	// By this point, pNym is a good pointer, and is on the wallet.
	//  (No need to cleanup.)
	// -----------------------------------------------------
	OTServerContract *	pServer = this->GetServer(SERVER_ID, szFuncName); // This ASSERTs and logs already.
	if (NULL == pServer) return;
	// By this point, pServer is a good pointer.  (No need to cleanup.)
	// -----------------------------------------------------
	OTMessage theMessage;
	long lRequestNumber = 0;
	
	OTString strServerID(SERVER_ID), strNymID(USER_ID), strNymID2(USER_ID_CHECK);
	
	// (0) Set up the REQUEST NUMBER and then INCREMENT IT
	pNym->GetCurrentRequestNum(strServerID, lRequestNumber);
	theMessage.m_strRequestNum.Format("%ld", lRequestNumber); // Always have to send this.
	pNym->IncrementRequestNum(*pNym, strServerID); // since I used it for a server request, I have to increment it
	
	// (1) set up member variables 
	theMessage.m_strCommand			= "checkUser";
	theMessage.m_strNymID			= strNymID;
	theMessage.m_strNymID2			= strNymID2;
	theMessage.m_strServerID		= strServerID;
	
	// (2) Sign the Message 
	theMessage.SignContract(*pNym);		
	
	// (3) Save the Message (with signatures and all, back to its internal member m_strRawFile.)
	theMessage.SaveContract();
	
	// (Send it)
#if defined(OT_ZMQ_MODE)
	m_pClient->SetFocusToServerAndNym(*pServer, *pNym, &OT_API::TransportCallback);
#endif	
	m_pClient->ProcessMessageOut(theMessage);
}



void OT_API::sendUserMessage(OTIdentifier	& SERVER_ID,
							 OTIdentifier	& USER_ID,
							 OTIdentifier	& USER_ID_RECIPIENT,
							 OTASCIIArmor	& RECIPIENT_PUBKEY,
							 OTString		& THE_MESSAGE)
{	
	const char * szFuncName = "OT_API::sendUserMessage";
	// -----------------------------------------------------
	OTPseudonym * pNym = this->GetOrLoadPrivateNym(USER_ID, szFuncName); // This ASSERTs and logs already.
	if (NULL == pNym) return;	
	// By this point, pNym is a good pointer, and is on the wallet.
	//  (No need to cleanup.)
	// -----------------------------------------------------
	OTServerContract *	pServer = this->GetServer(SERVER_ID, szFuncName); // This ASSERTs and logs already.
	if (NULL == pServer) return;
	// By this point, pServer is a good pointer.  (No need to cleanup.)
	// -----------------------------------------------------
	OTMessage theMessage;
	long lRequestNumber = 0;
	
	OTString strServerID(SERVER_ID), strNymID(USER_ID), strNymID2(USER_ID_RECIPIENT);
	
	// (0) Set up the REQUEST NUMBER and then INCREMENT IT
	pNym->GetCurrentRequestNum(strServerID, lRequestNumber);
	theMessage.m_strRequestNum.Format("%ld", lRequestNumber); // Always have to send this.
	pNym->IncrementRequestNum(*pNym, strServerID); // since I used it for a server request, I have to increment it
	
	// (1) set up member variables 
	theMessage.m_strCommand			= "sendUserMessage";
	theMessage.m_strNymID			= strNymID;
	theMessage.m_strNymID2			= strNymID2;
	theMessage.m_strServerID		= strServerID;
	
	OTEnvelope theEnvelope;
	OTAsymmetricKey thePubkey;
	
	if (!thePubkey.SetPublicKey(RECIPIENT_PUBKEY))
	{
		OTLog::Output(0, "OT_API::sendUserMessage: Failed setting public key.\n");
	}
	else if (THE_MESSAGE.Exists() && 
			 theEnvelope.Seal(thePubkey, THE_MESSAGE) &&
			 theEnvelope.GetAsciiArmoredData(theMessage.m_ascPayload))
	{
		// (2) Sign the Message 
		theMessage.SignContract(*pNym);		
		
		// (3) Save the Message (with signatures and all, back to its internal member m_strRawFile.)
		theMessage.SaveContract();
		
		// (Send it)
#if defined(OT_ZMQ_MODE)
		// -----------------------------------------------------------------
		
		m_pClient->SetFocusToServerAndNym(*pServer, *pNym, &OT_API::TransportCallback);
#endif	
		m_pClient->ProcessMessageOut(theMessage);
		
		
		// ----------------------------------------------
		// store a copy in the outmail.
		// (not encrypted, since the Nymfile will be encrypted anyway.
		//
		OTMessage * pMessage = new OTMessage;
		
		OT_ASSERT(NULL != pMessage);
		
		pMessage->m_strCommand		= "outmailMessage";
		pMessage->m_strNymID		= strNymID;
		pMessage->m_strNymID2		= strNymID2;
		pMessage->m_strServerID		= strServerID;			
		pMessage->m_strRequestNum.Format("%ld", lRequestNumber);
		
		pMessage->m_ascPayload.SetString(THE_MESSAGE);
		
		pMessage->SignContract(*pNym);		
		pMessage->SaveContract();
		
		pNym->AddOutmail(*pMessage); // Now the Nym is responsible to delete it. It's in his "outmail".
		OTPseudonym * pSignerNym = pNym;
		pNym->SaveSignedNymfile(*pSignerNym); // commented out temp for testing. 
	}
	else
		OTLog::Output(0, "OT_API::sendUserMessage: Failed sealing envelope.\n");
}




void OT_API::createUserAccount(OTIdentifier	& SERVER_ID,
							   OTIdentifier	& USER_ID)
{	
	const char * szFuncName = "OT_API::createUserAccount";
	// -----------------------------------------------------
	OTPseudonym * pNym = this->GetOrLoadPrivateNym(USER_ID, szFuncName); // This ASSERTs and logs already.
	if (NULL == pNym) return;	
	// By this point, pNym is a good pointer, and is on the wallet.
	//  (No need to cleanup.)
	// -----------------------------------------------------
	OTServerContract *	pServer = this->GetServer(SERVER_ID, szFuncName); // This ASSERTs and logs already.
	if (NULL == pServer) return;
	// By this point, pServer is a good pointer.  (No need to cleanup.)
	// -----------------------------------------------------
	OTMessage theMessage;
	
	if (m_pClient->ProcessUserCommand(OTClient::createUserAccount, theMessage, 
									*pNym, *pServer,
									NULL)) // NULL pAccount on this command.
	{				
#if defined(OT_ZMQ_MODE)
		m_pClient->SetFocusToServerAndNym(*pServer, *pNym, &OT_API::TransportCallback);
#endif	
		m_pClient->ProcessMessageOut(theMessage);
	}
	else
		OTLog::Error("OT_API::createUserAccount: Error in m_pClient->ProcessUserCommand() \n");
}



void OT_API::deleteUserAccount(OTIdentifier	& SERVER_ID,
							   OTIdentifier	& USER_ID)
{	
	const char * szFuncName = "OT_API::deleteUserAccount";
	// -----------------------------------------------------
	OTPseudonym * pNym = this->GetOrLoadPrivateNym(USER_ID, szFuncName); // This ASSERTs and logs already.
	if (NULL == pNym) return;	
	// By this point, pNym is a good pointer, and is on the wallet.
	//  (No need to cleanup.)
	// -----------------------------------------------------
	OTServerContract *	pServer = this->GetServer(SERVER_ID, szFuncName); // This ASSERTs and logs already.
	if (NULL == pServer) return;
	// By this point, pServer is a good pointer.  (No need to cleanup.)
	// -----------------------------------------------------
	OTMessage theMessage;
	
	if (m_pClient->ProcessUserCommand(OTClient::deleteUserAccount, theMessage, 
                                      *pNym, *pServer,
                                      NULL)) // NULL pAccount on this command.
	{				
#if defined(OT_ZMQ_MODE)
		m_pClient->SetFocusToServerAndNym(*pServer, *pNym, &OT_API::TransportCallback);
#endif	
		m_pClient->ProcessMessageOut(theMessage);
	}
	else
		OTLog::Error("Error processing deleteUserAccount command in OT_API::deleteUserAccount\n");
	
}


void OT_API::checkServerID(OTIdentifier	& SERVER_ID,
						   OTIdentifier	& USER_ID)
{	
	const char * szFuncName = "OT_API::checkServerID";
	// -----------------------------------------------------
	OTPseudonym * pNym = this->GetOrLoadPrivateNym(USER_ID, szFuncName); // This ASSERTs and logs already.
	if (NULL == pNym) return;	
	// By this point, pNym is a good pointer, and is on the wallet.
	//  (No need to cleanup.)
	// -----------------------------------------------------
	OTServerContract *	pServer = this->GetServer(SERVER_ID, szFuncName); // This ASSERTs and logs already.
	if (NULL == pServer) return;
	// By this point, pServer is a good pointer.  (No need to cleanup.)
	// -----------------------------------------------------
	OTMessage theMessage;
	
	if (m_pClient->ProcessUserCommand(OTClient::checkServerID, theMessage, 
									*pNym, *pServer,
									NULL)) // NULL pAccount on this command.
	{				
#if defined(OT_ZMQ_MODE)
		m_pClient->SetFocusToServerAndNym(*pServer, *pNym, &OT_API::TransportCallback);
#endif	
		m_pClient->ProcessMessageOut(theMessage);
	}
	else
		OTLog::Error("Error processing checkServerID command in OT_API::checkServerID\n");
	
}



































