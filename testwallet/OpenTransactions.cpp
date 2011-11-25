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
                        OTLog::vOutput(1, "Setting logfile to: %s\n", strOutput.Get());
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
                    OTLog::vOutput(1, "Setting log level to: %d\n", atoi(pVal2));
                    OTLog::SetLogLevel(atoi(pVal2));
                }
                else
                    OTLog::vOutput(1, "Current log level is: %d\n", OTLog::GetLogLevel());
            }
            // ---------------------------------------------
            // LATENCY (SENDING)
            {
                const char * pVal = ini.GetValue("latency", "send_no_tries");
                
                if ((NULL != pVal) && (atoi(pVal)))
                {
                    OTLog::vOutput(1, "Setting latency send_no_tries to: %d\n", atoi(pVal));
                    OTLog::SetLatencySendNoTries(atoi(pVal));
                }
            }
            {
                const char * pVal = ini.GetValue("latency", "send_ms");
                
                if ((NULL != pVal) && (atoi(pVal)))
                {
                    OTLog::vOutput(1, "Setting latency send_ms to: %d\n", atoi(pVal));
                    OTLog::SetLatencySendMs(atoi(pVal));
                }
            }
            // ------------------------------------------------
            // LATENCY (RECEIVING)
            {
                const char * pVal = ini.GetValue("latency", "receive_no_tries");
                
                if ((NULL != pVal) && (atoi(pVal)))
                {
                    OTLog::vOutput(1, "Setting latency receive_no_tries to: %d\n", atoi(pVal));                    
                    OTLog::SetLatencyReceiveNoTries(atoi(pVal));
                }
            }
            {
                const char * pVal = ini.GetValue("latency", "receive_ms");
                
                if ((NULL != pVal) && (atoi(pVal)))
                {
                    OTLog::vOutput(1, "Setting latency receive_ms to: %d\n", atoi(pVal));
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



// Call this once per instance of OT_API.
bool OT_API::Init(OTString & strClientPath)
{
	// TODO: Main path needs to be stored in OT_API global, not OTLog static.
	//		 This way, you can have multiple instances of OT_API,
	//		 Each with their own main path. This is necessary.
	//		 Now that the OT_API class exists might be time to take
	//       folders away from OTLog and move it all over. Ugh.
	// OR!! Maybe just code a mechanism so OTLog tracks the instances of OT_API.
	
	OT_ASSERT_MSG(strClientPath.Exists(), "Empty path passed to OT_API::Init");
	
	OT_ASSERT_MSG(false == m_bInitialized, "OTAPI was already initialized, please do not call it twice.");
    // ---------------------------------------
    
    OTString strPATH_OUTPUT;
    
    OTLog::TransformFilePath(strClientPath.Get(), strPATH_OUTPUT);
    

	// At some point, remove this, since each instance of OT API should eventually store its OWN path.
	OTLog::SetMainPath(strPATH_OUTPUT.Get()); // This currently does NOT support multiple instances of OT_API.  :-(
	// -------------------------------------
	
	LoadConfigFile(strPATH_OUTPUT);
	
	// -------------------------------------
	
	m_pWallet = new OTWallet;
	m_pClient = new OTClient;
	
	m_pstrStoragePath		= new OTString;
	m_pstrWalletFilename	= new OTString;

	OT_ASSERT_MSG(NULL != m_pWallet, "Error allocating memory for m_pWallet in OT_API::Init");
	OT_ASSERT_MSG(NULL != m_pClient, "Error allocating memory for m_pClient in OT_API::Init");
	OT_ASSERT_MSG(NULL != m_pstrStoragePath, "Error allocating memory for m_pstrStoragePath in OT_API::Init");
	OT_ASSERT_MSG(NULL != m_pstrWalletFilename, "Error allocating memory for m_pstrWalletFilename in OT_API::Init");
	
	// Keep this though.
	SetStoragePath(strPATH_OUTPUT); // sets m_pstrStoragePath

	m_bInitialized = m_pClient->InitClient(*m_pWallet);
	
	if (m_bInitialized)
	{
		std::string strPath = strPATH_OUTPUT.Get();
		
		// This way, everywhere else I can use the default storage context (for now) and it will work
		// everywhere I put it. (Because it's now set up...)
		bool bDefaultStore = OTDB::InitDefaultStorage(OTDB_DEFAULT_STORAGE, OTDB_DEFAULT_PACKER, strPath); // notice no wallet filename is passed here... InitDefaultStorage() will thus get called again...
		
		if (bDefaultStore)
			return true;
	}
	
	return false;
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


// "wallet.xml" (path set above.)
bool OT_API::LoadWallet(const OTString & strFilename)
{
	OT_ASSERT_MSG(m_bInitialized, "Not initialized; call OT_API::Init first.");
	OT_ASSERT(strFilename.Exists());
	OT_ASSERT(NULL != m_pWallet);
	
	// ----------------------------
	// Grab the old name for safe keeping..
	
	OTString strOldName;
	const char * szOldFilename = GetWalletFilename();
	
	if (NULL != szOldFilename)
		strOldName.Set(szOldFilename);
	else 
	{
		strOldName.Set("wallet.xml"); // todo stop hardcoding this DEFAULT VALUE.
	}

	// ----------------------------
	// set to new name.
	
	SetWalletFilename(strFilename); 
	
	// ------------------------------------------
	
	std::string strDataFolderPath = GetStoragePath();
	std::string strWalletFilename = GetWalletFilename();
	
	// This way, everywhere else I can use the default storage context (for now) and it will work
	// everywhere I put it. (Because it's now set up...)
	bool bSuccessInitDefault = OTDB::InitDefaultStorage(OTDB_DEFAULT_STORAGE, OTDB_DEFAULT_PACKER, strDataFolderPath, strWalletFilename);
	
	
	bool bSuccess = m_pWallet->LoadWallet(GetWalletFilename());
	
	if (false == bSuccess)
		SetWalletFilename(strOldName);
	
	return bSuccess;
}


int OT_API::GetNymCount()
{
	OT_ASSERT_MSG(m_bInitialized, "Not initialized; call OT_API::Init first.");
	
	return m_pWallet->GetNymCount();
}

int OT_API::GetServerCount()
{
	OT_ASSERT_MSG(m_bInitialized, "Not initialized; call OT_API::Init first.");
	
	return m_pWallet->GetServerCount();
}

int OT_API::GetAssetTypeCount()
{
	OT_ASSERT_MSG(m_bInitialized, "Not initialized; call OT_API::Init first.");
	
	return m_pWallet->GetAssetTypeCount();
}

int OT_API::GetAccountCount()
{
	OT_ASSERT_MSG(m_bInitialized, "Not initialized; call OT_API::Init first.");
	
	return m_pWallet->GetAccountCount();
}

bool OT_API::GetNym(int iIndex, OTIdentifier & NYM_ID, OTString & NYM_NAME)
{
	OT_ASSERT_MSG(m_bInitialized, "Not initialized; call OT_API::Init first.");
	
	return m_pWallet->GetNym(iIndex, NYM_ID, NYM_NAME);
}

bool OT_API::GetServer(int iIndex, OTIdentifier & THE_ID, OTString & THE_NAME)
{
	OT_ASSERT_MSG(m_bInitialized, "Not initialized; call OT_API::Init first.");
	
	return m_pWallet->GetServer(iIndex, THE_ID, THE_NAME);
}

bool OT_API::GetAssetType(int iIndex, OTIdentifier & THE_ID, OTString & THE_NAME)
{
	OT_ASSERT_MSG(m_bInitialized, "Not initialized; call OT_API::Init first.");
	
	return m_pWallet->GetAssetType(iIndex, THE_ID, THE_NAME);
}

bool OT_API::GetAccount(int iIndex, OTIdentifier & THE_ID, OTString & THE_NAME)
{
	OT_ASSERT_MSG(m_bInitialized, "Not initialized; call OT_API::Init first.");
	
	return m_pWallet->GetAccount(iIndex, THE_ID, THE_NAME);
}

// ----------------------------------------------------------


OTPseudonym * OT_API::GetNym(const OTIdentifier & NYM_ID)
{
	OT_ASSERT_MSG(m_bInitialized, "Not initialized; call OT_API::Init first.");
	
	OTWallet * pWallet = GetWallet();
	
	if (NULL != pWallet)
		return pWallet->GetNymByID(NYM_ID);

	return NULL;
}

OTServerContract * OT_API::GetServer(const OTIdentifier & THE_ID)
{
	OT_ASSERT_MSG(m_bInitialized, "Not initialized; call OT_API::Init first.");
	
	OTWallet * pWallet = GetWallet();
	
	if (NULL != pWallet)
		return pWallet->GetServerContract(THE_ID);

	return NULL;
}

OTAssetContract * OT_API::GetAssetType(const OTIdentifier & THE_ID)
{
	OT_ASSERT_MSG(m_bInitialized, "Not initialized; call OT_API::Init first.");
	
	OTWallet * pWallet = GetWallet();
	
	if (NULL != pWallet)
		return pWallet->GetAssetContract(THE_ID);

	return NULL;
}

OTAccount * OT_API::GetAccount(const OTIdentifier & THE_ID)	
{
	OT_ASSERT_MSG(m_bInitialized, "Not initialized; call OT_API::Init first.");
	
	OTWallet * pWallet = GetWallet();
	
	if (NULL != pWallet)	
		return pWallet->GetAccount(THE_ID);
	
	return NULL;
}

// ---------------------------------------------------------------------------

OTPseudonym * OT_API::GetNymByIDPartialMatch(const std::string PARTIAL_ID)
{
    OT_ASSERT_MSG(m_bInitialized, "Not initialized; call OT_API::Init first.");
	
	OTWallet * pWallet = GetWallet();
	
	if (NULL != pWallet)
		return pWallet->GetNymByIDPartialMatch(PARTIAL_ID);
    
	return NULL;
}

OTServerContract * OT_API::GetServerContractPartialMatch(const std::string PARTIAL_ID)
{
 	OT_ASSERT_MSG(m_bInitialized, "Not initialized; call OT_API::Init first.");
	
	OTWallet * pWallet = GetWallet();
	
	if (NULL != pWallet)
		return pWallet->GetServerContractPartialMatch(PARTIAL_ID);
    
	return NULL;   
}

OTAssetContract * OT_API::GetAssetContractPartialMatch(const std::string PARTIAL_ID)
{
   	OT_ASSERT_MSG(m_bInitialized, "Not initialized; call OT_API::Init first.");
	
	OTWallet * pWallet = GetWallet();
	
	if (NULL != pWallet)
		return pWallet->GetAssetContractPartialMatch(PARTIAL_ID);
    
	return NULL; 
}

OTAccount * OT_API::GetAccountPartialMatch(const std::string PARTIAL_ID)
{
    OT_ASSERT_MSG(m_bInitialized, "Not initialized; call OT_API::Init first.");
	
	OTWallet * pWallet = GetWallet();
	
	if (NULL != pWallet)	
		return pWallet->GetAccountPartialMatch(PARTIAL_ID);
	
	return NULL;
}


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





// The Asset Type's Name is basically just a client-side label.
// This function lets you change it.
//
// Returns success, true or false.
//
bool OT_API::SetAssetType_Name(const OTIdentifier	&	ASSET_ID, 
							   const OTString		&	STR_NEW_NAME) 
{
	OT_ASSERT_MSG(m_bInitialized, "Not initialized; call OT_API::Init first.");
	
	OTAssetContract *	pContract	= GetAssetType(ASSET_ID);
	OTWallet *			pWallet		= GetWallet();
	
	if (NULL == pWallet)
	{
		OTLog::Output(0, "No wallet loaded.\n");
	}
	else if (NULL == pContract)
	{
		OTString strOutput(ASSET_ID);
		OTLog::vOutput(0, "No asset contract found with the ID: %s\n", strOutput.Get());
	}
	// Might want to put some more data validation on the name?
	else if (!STR_NEW_NAME.Exists())
	{
		OTLog::vOutput(0, "Bad name: %s\n", STR_NEW_NAME.Get());
	}
	else
	{
		pContract->SetName(STR_NEW_NAME);
		
		return pWallet->SaveWallet(); // Only cause the name is actually stored here.
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
	OT_ASSERT_MSG(m_bInitialized, "Not initialized; call OT_API::Init first.");
	
	OTServerContract *	pContract	= GetServer(SERVER_ID);
	OTWallet *			pWallet		= GetWallet();
	
	if (NULL == pWallet)
	{
		OTLog::Output(0, "No wallet loaded.\n");
	}
	else if (NULL == pContract)
	{
		OTString strOutput(SERVER_ID);
		OTLog::vOutput(0, "No server contract found with the ID: %s\n", strOutput.Get());
	}
	// Might want to put some more data validation on the name?
	else if (!STR_NEW_NAME.Exists())
	{
		OTLog::vOutput(0, "Bad name: %s\n", STR_NEW_NAME.Get());
	}
	else
	{
		pContract->SetName(STR_NEW_NAME);
		
		return pWallet->SaveWallet(); // Only cause the name is actually stored here.
	}
	
	return false;
}



bool OT_API::IsNym_RegisteredAtServer(const OTIdentifier & NYM_ID, const OTIdentifier & SERVER_ID)
{
	OT_ASSERT_MSG(m_bInitialized, "Not initialized; call OT_API::Init first.");
	
	OTPseudonym *	pNym	= GetNym(NYM_ID);
	
	if (NULL == pNym)
	{
		OTString strOutput(NYM_ID);
		OTLog::vOutput(0, "No user found with Nym ID: %s\n", strOutput.Get());
	}
	else
	{
		const OTString strServerID(SERVER_ID);
		
		return pNym->IsRegisteredAtServer(strServerID);
	}
	
	return false;	
}



// The Nym's Name is basically just a client-side label.
// This function lets you change it.
//
// Returns success, true or false.
//
bool OT_API::SetNym_Name(const OTIdentifier	&	NYM_ID, 
						 const OTIdentifier	&	SIGNER_NYM_ID,
						 const OTString		&	NYM_NEW_NAME)
{
	OT_ASSERT_MSG(m_bInitialized, "Not initialized; call OT_API::Init first.");
	
	OTPseudonym *	pNym		= GetNym(NYM_ID);
	OTPseudonym *	pSignerNym	= GetNym(SIGNER_NYM_ID);
	OTWallet *		pWallet		= GetWallet();
	
	if (NULL == pWallet)
	{
		OTLog::Output(0, "No wallet loaded.\n");
	}
	else if (NULL == pNym)
	{
		OTString strOutput(NYM_ID);
		OTLog::vOutput(0, "No user found with Nym ID: %s\n", strOutput.Get());
	}
	else if (NULL == pSignerNym)
	{
		OTString strOutput(SIGNER_NYM_ID);
		OTLog::vOutput(0, "No user found with Signer Nym ID: %s\n", 
					   strOutput.Get());
	}
	// Might want to put some more data validation on the name?
	else if (!NYM_NEW_NAME.Exists())
	{
		OTLog::vOutput(0, "Bad name: %s\n", NYM_NEW_NAME.Get());
	}
	else
	{
		OTString strOldName(pNym->GetNymName()); // just in case.
		
		pNym->SetNymName(NYM_NEW_NAME);
		
		if (pNym->SaveSignedNymfile(*pSignerNym))
		{
			return pWallet->SaveWallet(); // Only cause the nym's name is stored here, too.
		}
		else
			pNym->SetNymName(strOldName);
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
	OT_ASSERT_MSG(m_bInitialized, "Not initialized; call OT_API::Init first.");
	
	OTAccount *		pAccount	= GetAccount(ACCT_ID);
	OTPseudonym *	pSignerNym	= GetNym(SIGNER_NYM_ID);
	OTWallet *		pWallet		= GetWallet();
	
	if (NULL == pWallet)
	{
		OTLog::Output(0, "No wallet loaded.\n");
	}	
	else if (NULL == pAccount)
	{
		OTString strOutput(ACCT_ID);
		OTLog::vOutput(0, "No asset account found with ID: %s\n", strOutput.Get());
	}
	else if (NULL == pSignerNym)
	{
		OTString strOutput(SIGNER_NYM_ID);
		OTLog::vOutput(0, "No user found with Signer Nym ID: %s\n", strOutput.Get());
	}
	else if (!pAccount->VerifyAccount(*pSignerNym))
	{
		OTString strOutput1(SIGNER_NYM_ID);
		OTString strOutput2(ACCT_ID);
		OTLog::vOutput(0, "The signing nym fails to verify on the account.\n"
					   " Nym: %s\n Account: %s\n", strOutput1.Get(), strOutput2.Get());
	}
	else if (!ACCT_NEW_NAME.Exists()) // Any other validation to do on the name?
	{
		OTLog::vOutput(0, "Bad name attempted change.(asset account): %s\n", ACCT_NEW_NAME.Get());
	}
	else
	{
		OTLog::Output(0, "Saving updated account file to disk...\n");
		
		pAccount->SetName(ACCT_NEW_NAME);
		pAccount->ReleaseSignatures();
		
		if (pAccount->SignContract(*pSignerNym))
		{
			if (pAccount->SaveAccount())
				return pWallet->SaveWallet(); // Only cause the account's name is stored here, too.
		}
	}
	
	return false;	
}




// CALLER is responsible to delete this Nym!
//
OTPseudonym * OT_API::LoadPublicNym(const OTIdentifier & NYM_ID)
{
	OT_ASSERT_MSG(m_bInitialized, "Not initialized; call OT_API::Init first.");
	
	OTPseudonym * pNym = new OTPseudonym(NYM_ID);
	
	OT_ASSERT_MSG(NULL != pNym, "Error allocating memory in the OT API.");
	
	// First load the public key
	if (false == pNym->LoadPublicKey())
	{
		OTString strNymID(NYM_ID);
		OTLog::vError("Failure loading Nym public key in OT_API::LoadPublicNym: %s\n", 
					  strNymID.Get());
	}
	else if (false == pNym->VerifyPseudonym())
	{
		OTString strNymID(NYM_ID);
		OTLog::vError("Failure verifying Nym public key in OT_API::LoadPublicNym: %s\n", 
					  strNymID.Get());
	}
	else if (false == pNym->LoadSignedNymfile(*pNym))
	{
		OTString strNymID(NYM_ID);
		OTLog::vError("Failure loading signed NymFile in OT_API::LoadPublicNym: %s\n", 
					  strNymID.Get());
	}
	else // success 
	{
		return pNym;
	}
	
	delete pNym; 
	pNym = NULL;

	return NULL;
}


// CALLER is responsible to delete the Nym that's returned here!
//
OTPseudonym * OT_API::LoadPrivateNym(const OTIdentifier & NYM_ID)
{	
	OT_ASSERT_MSG(m_bInitialized, "Not initialized; call OT_API::Init first.");
	
	OTPseudonym * pNym = new OTPseudonym(NYM_ID);
	
	OT_ASSERT_MSG(NULL != pNym, "Error allocating memory in the OT API.");
	
	if (pNym->Loadx509CertAndPrivateKey())
	{
		if (pNym->VerifyPseudonym()) 
		{
			if (pNym->LoadSignedNymfile(*pNym)) 
			{
				return pNym;
			}
			else 
			{
				OTString strNymID(NYM_ID);
				OTLog::vError("Failure calling LoadSignedNymfile in OT_API::LoadPrivateNym: %s\n", 
							  strNymID.Get());
			}
		}
		else 
		{
			OTString strNymID(NYM_ID);
			OTLog::vError("Failure verifying Nym public key in OT_API::LoadPrivateNym: %s\n", 
						  strNymID.Get());
		}
	}
	else 
	{
		// Error loading x509CertAndPrivateKey.
		OTString strNymID(NYM_ID);
		OTLog::vError("Failure calling Loadx509CertAndPrivateKey in OT_API::LoadPrivateNym: %s\n", 
					  strNymID.Get());
	}
	
	delete pNym; 
	pNym = NULL;
	
	return NULL;
}



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
	OT_ASSERT_MSG(m_bInitialized, "Not initialized; call OT_API::Init first.");
	
	OTWallet * pWallet = GetWallet();
	
	if (NULL == pWallet)
	{
		OTLog::Output(0, "The Wallet is not loaded.\n");
		return NULL;
	}
	
	// By this point, pWallet is a good pointer.  (No need to cleanup.)

	// -----------------------------------------------------
	
	OTPseudonym * pNym = pWallet->GetNymByID(SENDER_USER_ID);
	
	if (NULL == pNym) // Wasn't already in the wallet.
	{
		OTLog::Output(0, "There's no User already loaded with that ID. Loading...\n");
		
		pNym = this->LoadPrivateNym(SENDER_USER_ID);
		
		if (NULL == pNym) // LoadPrivateNym has plenty of error logging already.	
			return NULL;
		
		pWallet->AddNym(*pNym);
	}
	
	// By this point, pNym is a good pointer, and is on the wallet.
	//  (No need to cleanup.)
	// -----------------------------------------------------

	OTAccount * pAccount = pWallet->GetAccount(SENDER_ACCT_ID);
	
	if (NULL == pAccount)
	{
		OTLog::Output(0, "There's no asset account in the wallet with that ID. Trying to load from storage...\n");
		
		pAccount =  OTAccount::LoadExistingAccount(SENDER_ACCT_ID, SERVER_ID);
		
		if (NULL != pAccount) // It loaded...
		{
			if (SERVER_ID != pAccount->GetRealServerID())
			{
				OTLog::Output(0, "Writing a cheque, server ID passed in didn't match the one on the account.\n");
				delete pAccount; pAccount = NULL;
				return NULL;			
			}
			
			if (false == pAccount->VerifyOwner(*pNym)) // Verifies Ownership.
			{
				OTLog::Output(0, "User is not the owner of the account / tried to write a cheque.\n");
				delete pAccount; pAccount = NULL;
				return NULL;			
			}
			
			// By this point, I know the user is listed on the account as the owner.
			
			// -----------------------------------------------------
			
			if (false == pAccount->VerifyAccount(*pNym)) // Verifies ContractID and Signature.
			{
				OTLog::Output(0, "Bad signature or Account ID / tried to write a cheque.\n");
				delete pAccount; pAccount = NULL;
				return NULL;			
			}
			
			// By this point, I know that everything checks out. Signature and Account ID.
			
			// -----------------------------------------------------
			
			pWallet->AddAccount(*pAccount);
			
			// -----------------------------------------------------
		}
		else 
		{
			OTLog::Error("Error loading Asset Account in OT_API::WriteCheque\n");
			return NULL;
		}
	}
	
	// By this point, pAccount is a good pointer and in the wallet. 
	// (No need to cleanup.) I also know it has the right Server ID.
		
	// -----------------------------------------------------
	
	if (false == pAccount->VerifyOwner(*pNym)) // Verifies Ownership.
	{
		OTLog::Output(0, "User is not the owner of the account / tried to write a cheque.\n");
		return NULL;			
	}
	
	// By this point, I know the user is listed on the account as the owner.
	
	// -----------------------------------------------------
	
	if (false == pAccount->VerifyAccount(*pNym)) // Verifies ContractID and Signature.
	{
		OTLog::Output(0, "Bad signature or Account ID / tried to write a cheque.\n");
		return NULL;			
	}
	
	// By this point, I know that everything checks out. Signature and Account ID.
	// pAccount is good, and no need to clean it up.
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
		OTLog::Output(0, "User attempted to write a cheque, but had no transaction numbers.\n");
		return NULL;
	}
	
	// At this point, I know that lTransactionNumber contains one I can use.
	
	// -----------------------------------------------------
	
	OTCheque * pCheque = new OTCheque(pAccount->GetRealServerID(), 
									  pAccount->GetAssetTypeID());
	
	OT_ASSERT_MSG(NULL != pCheque, "Error allocating memory in the OT API.");
	
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
		OTLog::Error("OTCheque::IssueCheque failed in OT_API::WriteCheque.\n");
		
		delete pCheque; pCheque = NULL;
		
		// IF FAILED, ADD TRANSACTION NUMBER BACK TO LIST OF AVAILABLE NUMBERS.
		pNym->AddTransactionNum(*pNym, strServerID, lTransactionNumber, true); // bSave=true								
		
		return NULL;			
	}
	
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
	// -----------------------------------------------------
	
	OT_ASSERT_MSG(m_bInitialized, "Not initialized; call OT_API::Init first.");
	
	OTWallet * pWallet = GetWallet();
	
	if (NULL == pWallet)
	{
		OTLog::Output(0, "The Wallet is not loaded.\n");
		return NULL;
	}
	
	// By this point, pWallet is a good pointer.  (No need to cleanup.)
	
	// -----------------------------------------------------
	
	OTPseudonym * pNym = pWallet->GetNymByID(RECIPIENT_USER_ID);
	
	if (NULL == pNym) // Wasn't already in the wallet.
	{
		OTLog::Output(0, "There's no User already loaded with that ID. Loading...\n");
		
		pNym = this->LoadPrivateNym(RECIPIENT_USER_ID);
		
		if (NULL == pNym) // LoadPrivateNym has plenty of error logging already.	
			return NULL;
		
		pWallet->AddNym(*pNym);
	}
	
	// By this point, pNym is a good pointer, and is on the wallet.
	//  (No need to cleanup.)
	// -----------------------------------------------------
	
	OTAccount * pAccount = pWallet->GetAccount(RECIPIENT_ACCT_ID);
	
	if (NULL == pAccount)
	{
		OTLog::Output(0, "There's no asset account in the wallet with that ID. Trying to load from storage...\n");
		
		pAccount =  OTAccount::LoadExistingAccount(RECIPIENT_ACCT_ID, SERVER_ID);
		
		if (NULL != pAccount) // It loaded...
		{
			if (SERVER_ID != pAccount->GetRealServerID())
			{
				OTLog::Output(0, "OT_API::ProposePaymentPlan: server ID passed in didn't "
                              "match the one on the account.\n");
				delete pAccount; pAccount = NULL;
				return NULL;			
			}
			
			pWallet->AddAccount(*pAccount);
			// -----------------------------------------------------
		}
		else 
		{
			OTLog::Error("OT_API::ProposePaymentPlan: Error loading Asset Account.\n");
			return NULL;
		}
	}
	
	// By this point, pAccount is a good pointer and in the wallet. 
	// (No need to cleanup.) I also know it has the right Server ID.
	
	// -----------------------------------------------------
	
	if (false == pAccount->VerifyOwner(*pNym)) // Verifies Ownership.
	{
		OTLog::Output(0, "OT_API::ProposePaymentPlan: Merchant is not the owner of the recipient account in.\n");
		return NULL;			
	}
	
	// By this point, I know the user is listed on the account as the owner.
	
	// -----------------------------------------------------
	
	if (false == pAccount->VerifyAccount(*pNym)) // Verifies ContractID and Signature.
	{
		OTLog::Output(0, "OT_API::ProposePaymentPlan: Bad signature or Account ID when calling VerifyAccount().\n");
		return NULL;			
	}
	
	// By this point, I know that everything checks out. Signature and Account ID.
	
	// -----------------------------------------------------
		
	OTPaymentPlan * pPlan = new OTPaymentPlan(SERVER_ID, 
											  pAccount->GetAssetTypeID(),
											  SENDER_ACCT_ID,
                                              SENDER_USER_ID,
											  RECIPIENT_ACCT_ID, 
                                              RECIPIENT_USER_ID);
	
	OT_ASSERT_MSG(NULL != pPlan, "Error allocating memory in the OT API.");
	
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
    
	if (!bSuccessSetProposal)
	{   
        const OTString strServerID(SERVER_ID);
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
        const OTString strServerID(SERVER_ID);
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
	
	if (!bSuccessSetPaymentPlan)
	{
        const OTString strServerID(SERVER_ID);
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
	// -----------------------------------------------------
    
	OT_ASSERT_MSG(m_bInitialized, "Not initialized; call OT_API::Init first.");
	
	OTWallet * pWallet = GetWallet();
	
	if (NULL == pWallet)
	{
		OTLog::Output(0, "The Wallet is not loaded.\n");
		return false;
	}
	
	// By this point, pWallet is a good pointer.  (No need to cleanup.)
	
	// -----------------------------------------------------
	
	OTPseudonym * pNym = pWallet->GetNymByID(SENDER_USER_ID);
	
	if (NULL == pNym) // Wasn't already in the wallet.
	{
		OTLog::Output(0, "There's no User already loaded with that ID. Loading...\n");
		
		pNym = this->LoadPrivateNym(SENDER_USER_ID);
		
		if (NULL == pNym) // LoadPrivateNym has plenty of error logging already.	
			return false;
		
		pWallet->AddNym(*pNym);
	}
	// ----------------------------------------

    OTPseudonym * pMerchantNym = this->LoadPublicNym(RECIPIENT_USER_ID);
    OTCleanup<OTPseudonym> theNymAngel(pMerchantNym);
    
    if (NULL == pMerchantNym) // Wasn't already in the wallet.
	{
		OTLog::Output(0, "There's no Merchant with the recipient's NymID (in local storage.)\n");
        return false;
	}

	// By this point, pNym is a good pointer, and is on the wallet.
	// pMerchantNym is also good, and has an angel. (No need to cleanup either of them.)
	// -----------------------------------------------------
	
	OTAccount * pAccount = pWallet->GetAccount(SENDER_ACCT_ID);
	
	if (NULL == pAccount)
	{
		OTLog::Output(0, "There's no asset account in the wallet with that ID. Trying to load from storage...\n");
		
		pAccount =  OTAccount::LoadExistingAccount(SENDER_ACCT_ID, SERVER_ID);
		
		if (NULL != pAccount) // It loaded...
		{
			if (SERVER_ID != pAccount->GetRealServerID())
			{
				OTLog::Output(0, "OT_API::ConfirmPaymentPlan: server ID passed in didn't "
                              "match the one on the account.\n");
				delete pAccount; pAccount = NULL;
				return false;			
			}
			
			pWallet->AddAccount(*pAccount);
			// -----------------------------------------------------
		}
		else 
		{
			OTLog::Error("OT_API::ConfirmPaymentPlan: Error loading Asset Account.\n");
			return false;
		}
	}
	
	// By this point, pAccount is a good pointer and in the wallet. 
	// (No need to cleanup.) I also know it has the right Server ID.
	
	// -----------------------------------------------------
	
	if (false == pAccount->VerifyOwner(*pNym)) // Verifies Ownership.
	{
		OTLog::Output(0, "OT_API::ConfirmPaymentPlan: User is not the owner of the account.\n");
		return false;			
	}
	
	// By this point, I know the user is listed on the account as the owner.
	
	// -----------------------------------------------------
	
	if (false == pAccount->VerifyAccount(*pNym)) // Verifies ContractID and Signature.
	{
		OTLog::Output(0, "OT_API::ConfirmPaymentPlan: Bad signature or Account ID.\n");
		return false;			
	}
	
	// By this point, I know that everything checks out. Signature and Account ID.
	
	// -----------------------------------------------------
	// From Cron Item:
    //
    //    int     GetCountClosingNumbers() const;
    //    long    GetClosingTransactionNoAt(int nIndex) const;    
    //    void    AddClosingTransactionNo(const long & lClosingTransactionNo);
    
    // *******************************************************
    
	// The "Creation Date" of the agreement is re-set here.
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






// Note: replaced by ProposePaymentPlan and ConfirmPaymentPlan.
//
// WRITE PAYMENT PLAN
//
// Returns an OTPaymentPlan pointer, or NULL. 
// (Caller responsible to delete.)
//
// The process (currently) is:
// 1) Payment Plan is written by the sender (this function.)
// 2) This is necessary because the transaction number must be on
//    the sender's nym when he submits it to the server.
// 3) Also, the sender must be the one to submit it.
// 4) Recipient must sign it beforehand, so it must be sent to
//    recipient and then sent BACK to sender for submittal.
// 
// THAT SUCKS!   Here's what it should do:
// 
// 1) Payment plan is written, and signed, by the recipient. 
// 2) He sends it to the sender, who signs it and submits it.
// 3) The server loads the recipient nym to verify the transaction
//    number. The sender also had to burn a transaction number (to
//    submit it) so now, both have verified trns#s in this way.
//
// ==> Unfortunately, the current code is described by the first
// process above, not the second one. However, I think the API is
// the same either way -- just need to fix the server to support
// EITHER sender OR recipient being able to submit (it should simply
// check BOTH of them for the transaction number... 
// We'll get there...
//
//----------------------
//
// Payment Plan Delay, and Payment Plan Period, both default to 30 days (if you pass 0.)
// Payment Plan Length, and Payment Plan Max Payments, both default to 0, which means
// no maximum length and no maximum number of payments.
/*
OTPaymentPlan * OT_API::WritePaymentPlan(const OTIdentifier & SERVER_ID,
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
										 time_t	  PAYMENT_PLAN_LENGTH =0,		// after the length (in seconds)
										 int	  PAYMENT_PLAN_MAX_PAYMENTS =0	// expires, or after the maximum
										 )											// number of payments. These last 
{																					// two arguments are optional.
	// -----------------------------------------------------
	
	OT_ASSERT_MSG(m_bInitialized, "Not initialized; call OT_API::Init first.");
	
	OTWallet * pWallet = GetWallet();
	
	if (NULL == pWallet)
	{
		OTLog::Output(0, "The Wallet is not loaded.\n");
		return NULL;
	}
	
	// By this point, pWallet is a good pointer.  (No need to cleanup.)
	
	// -----------------------------------------------------
	
	OTPseudonym * pNym = pWallet->GetNymByID(SENDER_USER_ID);
	
	if (NULL == pNym) // Wasn't already in the wallet.
	{
		OTLog::Output(0, "There's no User already loaded with that ID. Loading...\n");
		
		pNym = this->LoadPrivateNym(SENDER_USER_ID);
		
		if (NULL == pNym) // LoadPrivateNym has plenty of error logging already.	
			return NULL;
		
		pWallet->AddNym(*pNym);
	}
	
	// By this point, pNym is a good pointer, and is on the wallet.
	//  (No need to cleanup.)
	// -----------------------------------------------------
	
	OTAccount * pAccount = pWallet->GetAccount(SENDER_ACCT_ID);
	
	if (NULL == pAccount)
	{
		OTLog::Output(0, "There's no asset account in the wallet with that ID. Trying to load from storage...\n");
		
		pAccount =  OTAccount::LoadExistingAccount(SENDER_ACCT_ID, SERVER_ID);
		
		if (NULL != pAccount) // It loaded...
		{
			if (SERVER_ID != pAccount->GetRealServerID())
			{
				OTLog::Output(0, "OT_API::WritePaymentPlan: server ID passed in didn't match the one on the account.\n");
				delete pAccount; pAccount = NULL;
				return NULL;			
			}
			
			pWallet->AddAccount(*pAccount);
			// -----------------------------------------------------
		}
		else 
		{
			OTLog::Error("Error loading Asset Account in OT_API::WritePaymentPlan\n");
			return NULL;
		}
	}
	
	// By this point, pAccount is a good pointer and in the wallet. 
	// (No need to cleanup.) I also know it has the right Server ID.
	
	// -----------------------------------------------------
	
	if (false == pAccount->VerifyOwner(*pNym)) // Verifies Ownership.
	{
		OTLog::Output(0, "User is not the owner of the account in OT_API::WritePaymentPlan.\n");
		return NULL;			
	}
	
	// By this point, I know the user is listed on the account as the owner.
	
	// -----------------------------------------------------
	
	if (false == pAccount->VerifyAccount(*pNym)) // Verifies ContractID and Signature.
	{
		OTLog::Output(0, "Bad signature or Account ID in OT_API::WritePaymentPlan.\n");
		return NULL;			
	}
	
	// By this point, I know that everything checks out. Signature and Account ID.
	
	// -----------------------------------------------------
	
	// To write a payment plan, we need to burn one of our transaction numbers. 
	// (Presumably the wallet is also storing a couple of these, since they are
	// needed to perform any transaction.)
	//
	// I don't have to contact the server to write a payment plan,
	// as long as I already have a transaction number I can use to 
	// write it with. (Otherwise I'd have to ask the server to send
	// me one first.)
	//
	OTString strServerID(SERVER_ID);
	long lTransactionNumber=0; // Notice I use the server ID on the ACCOUNT.
	
	if (false == pNym->GetNextTransactionNum(*pNym, strServerID, lTransactionNumber))
	{
		OTLog::Output(0, "OT_API::WritePaymentPlan: Failure, out of transaction numbers.\n");
		return NULL;
	}
	
	// At this point, I know that lTransactionNumber contains one I can use.
	
	// -----------------------------------------------------
	
	OTPaymentPlan * pPlan = new OTPaymentPlan(pAccount->GetRealServerID(), 
											  pAccount->GetAssetTypeID(),
											  pAccount->GetRealAccountID(),	pAccount->GetUserID(),
											  RECIPIENT_ACCT_ID, RECIPIENT_USER_ID);
	
	OT_ASSERT_MSG(NULL != pPlan, "Error allocating memory in the OT API.");
	
	// At this point, I know that pPlan is a good pointer that I either
	// have to delete, or return to the caller. CLEANUP WARNING!
	
	// -----------------------------------------------------
	// From Cron Item:
    //
    //    int     GetCountClosingNumbers() const;
    //    long    GetClosingTransactionNoAt(int nIndex) const;    
    //    void    AddClosingTransactionNo(const long & lClosingTransactionNo);

    // ----------------------------------------
    
	// The "Creation Date" of the agreement is set here.
	bool bSuccessSetAgreement = pPlan->SetAgreement(lTransactionNumber, PLAN_CONSIDERATION, VALID_FROM, VALID_TO);
	
	if (!bSuccessSetAgreement)
	{
		OTLog::Output(0, "Failed trying to set the agreement in OT_API::WritePaymentPlan.\n");
		
		delete pPlan; pPlan = NULL;
		
		// IF FAILED, ADD TRANSACTION NUMBER BACK TO LIST OF AVAILABLE NUMBERS.
		pNym->AddTransactionNum(*pNym, strServerID, lTransactionNumber, true); // bSave=true								

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
		OTLog::Output(0, "Failed trying to set the initial payment in OT_API::WritePaymentPlan.\n");
		
		delete pPlan; pPlan = NULL;
		
		// IF FAILED, ADD TRANSACTION NUMBER BACK TO LIST OF AVAILABLE NUMBERS.
		pNym->AddTransactionNum(*pNym, strServerID, lTransactionNumber, true); // bSave=true								

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
	
	if (!bSuccessSetPaymentPlan)
	{
		OTLog::Output(0, "Failed trying to set the payment plan in OT_API::WritePaymentPlan\n");
		
		delete pPlan; pPlan = NULL;
		
		// IF FAILED, ADD TRANSACTION NUMBER BACK TO LIST OF AVAILABLE NUMBERS.
		pNym->AddTransactionNum(*pNym, strServerID, lTransactionNumber, true); // bSave=true								

		return NULL;
	}
	
	pPlan->SignContract(*pNym);
	pPlan->SaveContract();
	
	return pPlan;
}
*/




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
	
	OTPurse * pPurse = new OTPurse(SERVER_ID, ASSET_ID);
	
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
	const OTString strUserID(USER_ID);
	const OTString strAssetTypeID(ASSET_ID);
	
	// -----------------------------------------------------------------
	
	if (THE_PURSE.SavePurse(strServerID.Get(), strUserID.Get(), strAssetTypeID.Get()))
		return true;
	
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
	OT_ASSERT_MSG(m_bInitialized, "Not initialized; call OT_API::Init first.");
	
	const OTString strServerID(SERVER_ID);
	const OTString strAssetTypeID(ASSET_ID);

	// -----------------------------------------------------------------
	
	OTMint * pMint = new OTMint(strServerID, strAssetTypeID);
	
	OT_ASSERT_MSG(NULL != pMint, "Error allocating memory in the OT API"); // responsible to delete or return pMint below this point.
	
	if (false == pMint->LoadMint())
	{
		OTLog::vOutput(0, "OT_API::LoadMint: Unable to load Mintfile : %s%s%s%s%s\n", 
					   OTLog::MintFolder(), OTLog::PathSeparator(), strServerID.Get(),
					   OTLog::PathSeparator(), strAssetTypeID.Get());
		delete pMint; pMint = NULL;
		return NULL;		
	}
	
	// TODO:  some kind of Mint Verification here ... ?
	
	// I know by this point that pMint is a good pointer AND
	// that I have successfully loaded the Mint file...
	
	return pMint;
}



// LOAD SERVER CONTRACT (from local storage)
//
// Caller is responsible to delete.
//
OTServerContract * OT_API::LoadServerContract(const OTIdentifier & SERVER_ID)
{
	OT_ASSERT_MSG(m_bInitialized, "Not initialized; call OT_API::Init first.");
	
	OTString strServerID(SERVER_ID);
	
	// -----------------------------------------------------------------
	
	OTString strFoldername	= OTLog::ContractFolder();
	OTString strFilename		= strServerID.Get();
	
	// --------------------------------------------------------------------
	
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
	{
		return pContract;
	}
	
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
	
	OTString strAssetTypeID(ASSET_ID);
	
	// -----------------------------------------------------------------
	
	OTString strFoldername	= OTLog::ContractFolder();
	OTString strFilename		= strAssetTypeID.Get();
	
	// --------------------------------------------------------------------
	
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
	{
		return pContract;
	}
	
	delete pContract; 
	pContract = NULL;
	
	return NULL;
}



// LOAD ASSET ACCOUNT
//
// Caller is NOT responsible to delete -- I add it to the wallet!
//
OTAccount * OT_API::LoadAssetAccount(const OTIdentifier & SERVER_ID,
									 const OTIdentifier & USER_ID,
									 const OTIdentifier & ACCOUNT_ID)
{
	OT_ASSERT_MSG(m_bInitialized, "Not initialized; call OT_API::Init first.");
	
	OTWallet * pWallet = GetWallet();
	
	if (NULL == pWallet)
	{
		OTLog::Output(0, "The Wallet is not loaded.\n");
		return NULL;
	}
	
	// By this point, pWallet is a good pointer.  (No need to cleanup.)
	
	// -----------------------------------------------------
	
	OTPseudonym * pNym = pWallet->GetNymByID(USER_ID);
	
	if (NULL == pNym) // Wasn't already in the wallet.
	{
		OTLog::Output(0, "There's no User already loaded with that ID. Loading...\n");
		
		pNym = this->LoadPrivateNym(USER_ID);
		
		if (NULL == pNym) // LoadPrivateNym has plenty of error logging already.	
		{
			return NULL;
		}
		
		pWallet->AddNym(*pNym);
	}
	
	// By this point, pNym is a good pointer, and is on the wallet.
	//  (No need to cleanup.)
	// -----------------------------------------------------
	
	// We don't care if this asset account is already loaded in the wallet.
	// Presumably, the user has just download the latest copy of the account
	// from the server, and the one in the wallet is old, so now this function
	// is being called to load the new one from storage and update the wallet.
	//
	OTAccount * pAcct = OTAccount::LoadExistingAccount(ACCOUNT_ID, SERVER_ID);
	
	if (NULL == pAcct)
	{
		OTString strServerID(SERVER_ID), strAcctID(ACCOUNT_ID);
		OTLog::vOutput(0, "Failed calling OTAccount::LoadExistingAccount in OT_API::LoadAssetAccount.\n"
					   " Server ID: %s\n Account ID: %s\n", strServerID.Get(), strAcctID.Get());
		return NULL;
	}
	
	// Beyond this point, I know that pAcct is loaded and will need to be deleted or returned.
	// ------------------------------------------------------
	
	// I call VerifySignature here since VerifyContractID was already called in LoadExistingAccount().
	if (!pAcct->VerifyOwner(*pNym) || !pAcct->VerifySignature(*pNym))
	{
		OTString strUserID(USER_ID), strAcctID(ACCOUNT_ID);
		
		OTLog::vOutput(0, "Unable to verify ownership or signature on account:\n%s\n For user:\n%s\n",
					   strAcctID.Get(), strUserID.Get());
		
		delete pAcct;
		pAcct = NULL;
		
		return  NULL;
	}
	
	// Beyond this point, I know the account is verified for the Nym...
	// Therefore, add it to the wallet (caller is NOT responsible to delete.)
	//
	pWallet->AddAccount(*pAcct);
	
	return pAcct;
}



// LOAD NYMBOX
//
// Caller IS responsible to delete
//
OTLedger * OT_API::LoadNymbox(const OTIdentifier & SERVER_ID,
							  const OTIdentifier & USER_ID)
{
	OT_ASSERT_MSG(m_bInitialized, "Not initialized; call OT_API::Init first.");
	
	// -----------------------------------------------------
	
	OTWallet * pWallet = GetWallet();
	
	if (NULL == pWallet)
	{
		OTLog::Output(0, "The Wallet is not loaded.\n");
		return NULL;
	}
	
	// By this point, pWallet is a good pointer.  (No need to cleanup.)
	
	// -----------------------------------------------------
	
	OTPseudonym * pNym = pWallet->GetNymByID(USER_ID);
	
	if (NULL == pNym) // Wasn't already in the wallet.
	{
		OTLog::Output(0, "There's no User already loaded with that ID. Loading...\n");
		
		pNym = this->LoadPrivateNym(USER_ID);
		
		if (NULL == pNym) // LoadPrivateNym has plenty of error logging already.	
		{
			return NULL;
		}
		
		pWallet->AddNym(*pNym);
	}
	
	// By this point, pNym is a good pointer, and is on the wallet.
	//  (No need to cleanup.)
	// -----------------------------------------------------
	
	OTLedger * pLedger = new OTLedger(USER_ID, USER_ID, SERVER_ID);
	
	OT_ASSERT_MSG(NULL != pLedger, "Error allocating memory in the OT API.");
	
	// Beyond this point, I know that pLedger will need to be deleted or returned.
	// ------------------------------------------------------
	
	if (pLedger->LoadNymbox() && pLedger->VerifyAccount(*pNym))
		return pLedger;
	else
	{
		OTString strUserID(USER_ID);
		
		OTLog::vOutput(0, "Unable to load or verify nymbox:\n%s\n",
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
	OT_ASSERT_MSG(m_bInitialized, "Not initialized; call OT_API::Init first.");
	
	// -----------------------------------------------------

	OTWallet * pWallet = GetWallet();
	
	if (NULL == pWallet)
	{
		OTLog::Output(0, "The Wallet is not loaded.\n");
		return NULL;
	}
	
	// By this point, pWallet is a good pointer.  (No need to cleanup.)
	
	// -----------------------------------------------------
	
	OTPseudonym * pNym = pWallet->GetNymByID(USER_ID);
	
	if (NULL == pNym) // Wasn't already in the wallet.
	{
		OTLog::Output(0, "There's no User already loaded with that ID. Loading...\n");
		
		pNym = this->LoadPrivateNym(USER_ID);
		
		if (NULL == pNym) // LoadPrivateNym has plenty of error logging already.	
		{
			return NULL;
		}
		
		pWallet->AddNym(*pNym);
	}
	
	// By this point, pNym is a good pointer, and is on the wallet.
	//  (No need to cleanup.)
	// -----------------------------------------------------
	
	OTLedger * pLedger = new OTLedger(USER_ID, ACCOUNT_ID, SERVER_ID);
	
	OT_ASSERT_MSG(NULL != pLedger, "Error allocating memory in the OT API.");
	
	// Beyond this point, I know that pLedger will need to be deleted or returned.
	// ------------------------------------------------------
	
	if (pLedger->LoadInbox() && pLedger->VerifyAccount(*pNym))
		return pLedger;
	else
	{
		OTString strUserID(USER_ID), strAcctID(ACCOUNT_ID);
		
		OTLog::vOutput(0, "Unable to load or verify inbox:\n%s\n For user:\n%s\n",
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
	OT_ASSERT_MSG(m_bInitialized, "Not initialized; call OT_API::Init first.");
	
	// -----------------------------------------------------------------

	OTWallet * pWallet = GetWallet();
	
	if (NULL == pWallet)
	{
		OTLog::Output(0, "The Wallet is not loaded.\n");
		return NULL;
	}
	
	// By this point, pWallet is a good pointer.  (No need to cleanup.)
	
	// -----------------------------------------------------
	
	OTPseudonym * pNym = pWallet->GetNymByID(USER_ID);
	
	if (NULL == pNym) // Wasn't already in the wallet.
	{
		OTLog::Output(0, "There's no User already loaded with that ID. Loading...\n");
		
		pNym = this->LoadPrivateNym(USER_ID);
		
		if (NULL == pNym) // LoadPrivateNym has plenty of error logging already.	
		{
			return NULL;
		}
		
		pWallet->AddNym(*pNym);
	}
	
	// By this point, pNym is a good pointer, and is on the wallet.
	//  (No need to cleanup.)
	// -----------------------------------------------------
	
	OTLedger * pLedger = new OTLedger(USER_ID, ACCOUNT_ID, SERVER_ID);
	
	OT_ASSERT_MSG(NULL != pLedger, "Error allocating memory in the OT API.");
	
	// Beyond this point, I know that pLedger is loaded and will need to be deleted or returned.
	// ------------------------------------------------------
	
	if (pLedger->LoadOutbox() && pLedger->VerifyAccount(*pNym))
		return pLedger;
	else
	{
		OTString strUserID(USER_ID), strAcctID(ACCOUNT_ID);
		
		OTLog::vOutput(0, "Unable to load or verify outbox:\n%s\n For user:\n%s\n",
					   strAcctID.Get(), strUserID.Get());
		
		delete pLedger;
		pLedger = NULL;		
	}
	
	return  NULL;
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





// ABOVE ARE COMMANDS TO MANIPULATE LOCAL DATA (**NOT** MESSAGE THE SERVER.)


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
	else {
		OTLog::Output(0, "Either the wallet is not loaded, or there was an error connecting to server.\n");
		return false;
	}
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
	OT_ASSERT_MSG(m_bInitialized, "Not initialized; call OT_API::Init first.");

	// -----------------------------------------------------
	
	// There is an OT_ASSERT_MSG in here for memory failure,
	// but it still might return NULL if various verification fails.
	OTAssetContract * pContract = this->GetAssetType(BASKET_ASSET_TYPE_ID); 
	
	if (!pContract)
	{
		OTLog::Output(0, "OT_API::IsBasketCurrency: No such asset contract.\n");
		
		return false;
	}
	// No need to cleanup pContract.
	// -----------------------------------------------------
	
	
	// Next load the OTBasket object out of that contract.
	OTBasket theBasket;
	
	// todo perhaps verify the basket here, even though I already verified the asset contract itself...
	// Can't never be too sure.
	if (pContract->GetBasketInfo().GetLength() && theBasket.LoadContractFromString(pContract->GetBasketInfo()))
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
	OT_ASSERT_MSG(m_bInitialized, "Not initialized; call OT_API::Init first.");

	// -----------------------------------------------------
	
	// There is an OT_ASSERT_MSG in here for memory failure,
	// but it still might return NULL if various verification fails.
	OTAssetContract * pContract = this->GetAssetType(BASKET_ASSET_TYPE_ID); 
	
	if (!pContract)
	{
		OTLog::Output(0, "OT_API::GetBasketMemberCount: No such asset contract.\n");
		
		return 0;
	}
	// No need to cleanup pContract.
	// -----------------------------------------------------
	
	
	// Next load the OTBasket object out of that contract.
	OTBasket theBasket;
	
	// todo perhaps verify the basket here, even though I already verified the asset contract itself...
	// Can't never be too sure.
	if (pContract->GetBasketInfo().GetLength() && theBasket.LoadContractFromString(pContract->GetBasketInfo()))
	{
		return theBasket.Count();
	}
	
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
	OT_ASSERT_MSG(m_bInitialized, "Not initialized; call OT_API::Init first.");
	
	// -----------------------------------------------------
	
	// There is an OT_ASSERT_MSG in here for memory failure,
	// but it still might return NULL if various verification fails.
	OTAssetContract * pContract = this->GetAssetType(BASKET_ASSET_TYPE_ID); 
	
	if (!pContract)
	{
		OTLog::Output(0, "OT_API::GetBasketMemberType: No such asset contract.\n");
		
		return false;
	}
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
	OT_ASSERT_MSG(m_bInitialized, "Not initialized; call OT_API::Init first.");
	
	// -----------------------------------------------------
	
	// There is an OT_ASSERT_MSG in here for memory failure,
	// but it still might return NULL if various verification fails.
	OTAssetContract * pContract = this->GetAssetType(BASKET_ASSET_TYPE_ID); 
	
	if (!pContract)
	{
		OTLog::Output(0, "OT_API::GetBasketMemberMinimumTransferAmount: No such asset contract.\n");
		
		return 0;
	}
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
	OT_ASSERT_MSG(m_bInitialized, "Not initialized; call OT_API::Init first.");
	
	// -----------------------------------------------------
	
	// There is an OT_ASSERT_MSG in here for memory failure,
	// but it still might return NULL if various verification fails.
	OTAssetContract * pContract = this->GetAssetType(BASKET_ASSET_TYPE_ID); 
	
	if (!pContract)
	{
		OTLog::Output(0, "OT_API::GetBasketMinimumTransferAmount: No such asset contract.\n");
		
		return 0;
	}
	// No need to cleanup pContract.
	// -----------------------------------------------------
	
	
	// Next load the OTBasket object out of that contract.
	OTBasket theBasket;
	
	// todo perhaps verify the basket here, even though I already verified the asset contract itself...
	// Can't never be too sure.
	if (pContract->GetBasketInfo().GetLength() && theBasket.LoadContractFromString(pContract->GetBasketInfo()))
	{
		return theBasket.GetMinimumTransfer();
	}
	
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
	OT_ASSERT_MSG(m_bInitialized, "Not initialized; call OT_API::Init first.");
	
	long lMinimumTransferAmount = 10;
	
	if (MINIMUM_TRANSFER > 0)
		lMinimumTransferAmount = MINIMUM_TRANSFER;
	
	// -----------------------------------------------------
	
	OTWallet * pWallet = GetWallet();
	
	if (NULL == pWallet)
	{
		OTLog::Output(0, "The Wallet is not loaded.\n");
		return false;
	}
	
	// By this point, pWallet is a good pointer.  (No need to cleanup.)
	
	// -----------------------------------------------------
	
	OTPseudonym * pNym = pWallet->GetNymByID(USER_ID);
	
	if (NULL == pNym) // Wasn't already in the wallet.
	{
		OTLog::Output(0, "There's no User already loaded with that ID. Loading...\n");
		
		pNym = this->LoadPrivateNym(USER_ID);
		
		if (NULL == pNym) // LoadPrivateNym has plenty of error logging already.	
			return false;
		
		pWallet->AddNym(*pNym);
	}
	
	// By this point, pNym is a good pointer, and is on the wallet.
	//  (No need to cleanup.)
	// -----------------------------------------------------

	OTBasket * pBasket = new OTBasket(0, lMinimumTransferAmount);
	
	OT_ASSERT_MSG(NULL != pBasket, "Error allocating memory in the OT API");
	
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
	OT_ASSERT_MSG(m_bInitialized, "Not initialized; call OT_API::Init first.");
	
	// -----------------------------------------------------
	
	OTWallet * pWallet = GetWallet();
	
	if (NULL == pWallet)
	{
		OTLog::Output(0, "The Wallet is not loaded.\n");
		return false;
	}
	
	// By this point, pWallet is a good pointer.  (No need to cleanup.)
	
	// -----------------------------------------------------
	
	OTPseudonym * pNym = pWallet->GetNymByID(USER_ID);
	
	if (NULL == pNym) // Wasn't already in the wallet.
	{
		OTLog::Output(0, "There's no User already loaded with that ID. Loading...\n");
		
		pNym = this->LoadPrivateNym(USER_ID);
		
		if (NULL == pNym) // LoadPrivateNym has plenty of error logging already.	
			return false;
		
		pWallet->AddNym(*pNym);
	}
	
	// By this point, pNym is a good pointer, and is on the wallet.
	//  (No need to cleanup.)
	// -----------------------------------------------------

	// There is an OT_ASSERT_MSG in here for memory failure,
	// but it still might return NULL if various verification fails.
	OTAssetContract * pContract = this->GetAssetType(ASSET_TYPE_ID); 
	
	if (!pContract)
	{
		OTLog::Output(0, "No such asset contract.\n");
		
		return false;
	}
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
	OT_ASSERT_MSG(m_bInitialized, "Not initialized; call OT_API::Init first.");
	
	// -----------------------------------------------------------------
	
	OTServerContract * pServer = m_pWallet->GetServerContract(SERVER_ID);
	
	if (!pServer)
	{
		OTLog::Output(0, "That server contract is not available in the wallet.\n");
		
		return;
	}
	
	
	// -----------------------------------------------------
	
	OTPseudonym * pNym = m_pWallet->GetNymByID(USER_ID);
	
	if (NULL == pNym) // Wasn't already in the wallet.
	{
		OTLog::Output(0, "There's no User already loaded with that ID. Loading...\n");
		
		pNym = this->LoadPrivateNym(USER_ID);
		
		if (NULL == pNym) // LoadPrivateNym has plenty of error logging already.	
			return;
		
		m_pWallet->AddNym(*pNym);
	}
	
	// By this point, pNym is a good pointer, and is on the wallet.
	//  (No need to cleanup.)
	// -----------------------------------------------------
	
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
	OT_ASSERT_MSG(m_bInitialized, "Not initialized; call OT_API::Init first.");
	
    OTString strServerID(SERVER_ID);
    
	// -----------------------------------------------------
	
	OTWallet * pWallet = GetWallet();
	
	if (NULL == pWallet)
	{
		OTLog::Output(0, "The Wallet is not loaded.\n");
		return NULL;
	}
	
	// By this point, pWallet is a good pointer.  (No need to cleanup.)
	
	// -----------------------------------------------------
	
	OTPseudonym * pNym = pWallet->GetNymByID(USER_ID);
	
	if (NULL == pNym) // Wasn't already in the wallet.
	{
		OTLog::Output(0, "There's no User already loaded with that ID. Loading...\n");
		
		pNym = this->LoadPrivateNym(USER_ID);
		
		if (NULL == pNym) // LoadPrivateNym has plenty of error logging already.	
			return NULL;
		
		pWallet->AddNym(*pNym);
	}
	
	// By this point, pNym is a good pointer, and is on the wallet.
	//  (No need to cleanup.)
	// -----------------------------------------------------
	
	int nTransferMultiple = 1;
	
	if (TRANSFER_MULTIPLE > 0)
		nTransferMultiple = TRANSFER_MULTIPLE;
	
	// -----------------------------------------------------------------
	
	// There is an OT_ASSERT_MSG in here for memory failure,
	// but it still might return NULL if various verification fails.
	OTAssetContract * pContract = this->GetAssetType(BASKET_ASSET_TYPE_ID); 

	if (!pContract)
	{
		OTLog::Output(0, "No such asset contract.\n");
		
		return NULL;
	}
	// No need to cleanup pContract.
	// -----------------------------------------------------
	
	OTAccount * pAccount = pWallet->GetAccount(BASKET_ASSET_ACCT_ID);
	
	if (NULL == pAccount)
	{
		OTLog::Output(0, "There's no asset account in the wallet with that ID. Trying to load from storage...\n");
		
		pAccount =  OTAccount::LoadExistingAccount(BASKET_ASSET_ACCT_ID, SERVER_ID);
		
		if (NULL != pAccount) // It loaded...
		{
			if (SERVER_ID != pAccount->GetRealServerID())
			{
				OTLog::Output(0, "OT_API::GenerateBasketExchange: server ID passed in didn't match "
							  "the one on the account.\n");
				delete pAccount; pAccount = NULL;
				return NULL;			
			}
			
			if (false == pAccount->VerifyOwner(*pNym)) // Verifies Ownership.
			{
				OTLog::Output(0, "OT_API::GenerateBasketExchange: User is not the owner of the account..\n");
				delete pAccount; pAccount = NULL;
				return NULL;			
			}
			
			// By this point, I know the user is listed on the account as the owner.
			
			// -----------------------------------------------------
			
			if (false == pAccount->VerifyAccount(*pNym)) // Verifies ContractID and Signature.
			{
				OTLog::Output(0, "OT_API::GenerateBasketExchange: Bad signature or Account ID.\n");
				delete pAccount; pAccount = NULL;
				return NULL;			
			}
			
			// By this point, I know that everything checks out. Signature and Account ID.
			
			// -----------------------------------------------------
			
			pWallet->AddAccount(*pAccount);
			
			// -----------------------------------------------------
		}
		else 
		{
			OTLog::Error("Error loading Asset Account in OT_API::GenerateBasketExchange\n");
			return NULL;
		}
	}
	
	// By this point, pAccount is a good pointer and in the wallet. 
	// (No need to cleanup.) I also know it has the right Server ID.
	
	// -----------------------------------------------------
	// I checked these things above. But since I only check them when ADDING,
	// I also want to check here, in cases where I get successfully and didn't
	// need to add.
	//
	if (false == pAccount->VerifyOwner(*pNym)) // Verifies Ownership.
	{
		OTLog::Output(0, "OT_API::GenerateBasketExchange: User is not the owner of the account.\n");
		return NULL;			
	}
	
	// By this point, I know the user is listed on the account as the owner.
	
	// -----------------------------------------------------
	
	if (false == pAccount->VerifyAccount(*pNym)) // Verifies ContractID and Signature.
	{
		OTLog::Output(0, "OT_API::GenerateBasketExchange: Bad signature or Account ID.\n");
		return NULL;			
	}
	
	if (BASKET_ASSET_TYPE_ID != pAccount->GetAssetTypeID())
	{
		OTLog::Output(0, "Wrong asset type ID on account in OT_API::GenerateBasketExchange.\n");
		return NULL;			
	}
	
	// By this point, I know that everything checks out. Signature and Account ID.
	// pAccount is good, and no need to clean it up.
	// -----------------------------------------------------
	
	// Next load the OTBasket object out of that contract.
	OTBasket theBasket;
	OTBasket * pRequestBasket = NULL;
    
	// todo perhaps verify the basket here, even though I already verified the asset contract itself...
	// Can't never be too sure.
	if (pContract->GetBasketInfo().GetLength() && theBasket.LoadContractFromString(pContract->GetBasketInfo()))
	{
        // We need a transaction number just to send this thing. Plus, we need a number for
        // each sub-account to the basket, as well as the basket's main account.
        // That is: 1 + theBasket.Count() + 1
        
        if (pNym->GetTransactionNumCount(SERVER_ID) < (2 + theBasket.Count()))
        {
            OTLog::Output(0, "Trying to exchange basket: you don't have enough transaction numbers to perform the exchange.\n");
        }
        else
        {
            pRequestBasket = new OTBasket(theBasket.Count(), theBasket.GetMinimumTransfer());
            OT_ASSERT_MSG(NULL != pRequestBasket, "Error allocating memory in the OT API");
            
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
	OT_ASSERT_MSG(m_bInitialized, "Not initialized; call OT_API::Init first.");
	
    const OTString strServerID(SERVER_ID);
    
	// -----------------------------------------------------
	
	OTWallet * pWallet = GetWallet();
	
	if (NULL == pWallet)
	{
		OTLog::Output(0, "The Wallet is not loaded.\n");
		return false;
	}
	
	// By this point, pWallet is a good pointer.  (No need to cleanup.)
	
	// -----------------------------------------------------
	
	OTPseudonym * pNym = pWallet->GetNymByID(USER_ID);
	
	if (NULL == pNym) // Wasn't already in the wallet.
	{
		OTLog::Output(0, "There's no User already loaded with that ID. Loading...\n");
		
		pNym = this->LoadPrivateNym(USER_ID);
		
		if (NULL == pNym) // LoadPrivateNym has plenty of error logging already.	
			return false;
		
		pWallet->AddNym(*pNym);
	}
	
	// By this point, pNym is a good pointer, and is on the wallet.
	//  (No need to cleanup.)
	// -----------------------------------------------------------------
	
    if (pNym->GetTransactionNumCount(SERVER_ID) < 1)
    {
        OTLog::Output(0, "OT_API::AddBasketExchangeItem: you need at least one transaction number to add this exchange item.\n");
        return false;
    }
    
    // -----------------------------------------------------
    
	// There is an OT_ASSERT_MSG in here for memory failure,
	// but it still might return NULL if various verification fails.
	OTAssetContract * pContract = this->GetAssetType(ASSET_TYPE_ID); 
	
	if (!pContract)
	{
		OTLog::Output(0, "No such asset contract.\n");
		
		return false;
	}
	// No need to cleanup pContract.
	// -----------------------------------------------------
	
	OTAccount * pAccount = pWallet->GetAccount(ASSET_ACCT_ID);
	
	if (NULL == pAccount)
	{
		OTLog::Output(0, "There's no asset account in the wallet with that ID. Trying to load from storage...\n");
		
		pAccount =  OTAccount::LoadExistingAccount(ASSET_ACCT_ID, SERVER_ID);
		
		if (NULL != pAccount) // It loaded...
		{
			if (SERVER_ID != pAccount->GetRealServerID())
			{
				OTLog::Output(0, "OT_API::AddBasketExchangeItem: server ID passed in didn't match "
							  "the one on the account.\n");
				delete pAccount; pAccount = NULL;
				return false;			
			}
			
			if (false == pAccount->VerifyOwner(*pNym)) // Verifies Ownership.
			{
				OTLog::Output(0, "OT_API::AddBasketExchangeItem: User is not the owner of the account..\n");
				delete pAccount; pAccount = NULL;
				return false;			
			}
			
			// By this point, I know the user is listed on the account as the owner.
			
			// -----------------------------------------------------
			
			if (false == pAccount->VerifyAccount(*pNym)) // Verifies ContractID and Signature.
			{
				OTLog::Output(0, "OT_API::AddBasketExchangeItem: Bad signature or Account ID.\n");
				delete pAccount; pAccount = NULL;
				return false;			
			}
			
			// By this point, I know that everything checks out. Signature and Account ID.
			
			// -----------------------------------------------------
			
            if (ASSET_TYPE_ID != pAccount->GetAssetTypeID())
            {
                OTLog::Output(0, "Wrong asset type ID on account in OT_API::AddBasketExchangeItem.\n");
                return false;			
            }

			// -----------------------------------------------------

			pWallet->AddAccount(*pAccount);
			
			// -----------------------------------------------------
		}
		else 
		{
			OTLog::Error("Error loading Asset Account in OT_API::AddBasketExchangeItem\n");
			return false;
		}
	}
	
	// By this point, pAccount is a good pointer and in the wallet. 
	// (No need to cleanup.) I also know it has the right Server ID.
	
	// -----------------------------------------------------
	// I checked these things above. But since I only check them when ADDING,
	// I also want to check here, in cases where I get successfully and didn't
	// need to add.
	//
	if (false == pAccount->VerifyOwner(*pNym)) // Verifies Ownership.
	{
		OTLog::Output(0, "OT_API::AddBasketExchangeItem: User is not the owner of the account.\n");
		return false;			
	}
	
	// By this point, I know the user is listed on the account as the owner.
	
	// -----------------------------------------------------
	
	if (false == pAccount->VerifyAccount(*pNym)) // Verifies ContractID and Signature.
	{
		OTLog::Output(0, "OT_API::AddBasketExchangeItem: Bad signature or Account ID.\n");
		return false;			
	}
	
	if (ASSET_TYPE_ID != pAccount->GetAssetTypeID())
	{
		OTLog::Output(0, "Wrong asset type ID on account in OT_API::AddBasketExchangeItem.\n");
		return false;			
	}
	
	// By this point, I know that everything checks out. Signature and Account ID.
	// pAccount is good, and no need to clean it up.
	// ----------------------------------------------------
    
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
    {
        OTLog::Error("OT_API::AddBasketExchangeItem: Failed getting next transaction number. \n");
    }

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
	OT_ASSERT_MSG(m_bInitialized, "Not initialized; call OT_API::Init first.");
	
    const OTString strServerID(SERVER_ID), strUserID(USER_ID);
    
	// -----------------------------------------------------------------
	
	OTServerContract * pServer = m_pWallet->GetServerContract(SERVER_ID);
	
	if (!pServer)
	{
		OTLog::Output(0, "That server contract is not available in the wallet.\n");
		
		return;
	}
	
	// -----------------------------------------------------
	
	OTPseudonym * pNym = m_pWallet->GetNymByID(USER_ID);
	
	if (NULL == pNym) // Wasn't already in the wallet.
	{
		OTLog::Output(0, "There's no User already loaded with that ID. Loading...\n");
		
		pNym = this->LoadPrivateNym(USER_ID);
		
		if (NULL == pNym) // LoadPrivateNym has plenty of error logging already.	
			return;
		
		m_pWallet->AddNym(*pNym);
	}
	
	// By this point, pNym is a good pointer, and is on the wallet.
	//  (No need to cleanup.)
	// -----------------------------------------------------------------
	
	// There is an OT_ASSERT_MSG in here for memory failure,
	// but it still might return NULL if various verification fails.
	OTAssetContract * pContract = this->GetAssetType(BASKET_ASSET_ID); 
	
	if (!pContract)
	{
		OTLog::Output(0, "No such asset contract.\n");
		
		return;
	}
	// No need to cleanup pContract.
	// -----------------------------------------------------
    
	// Next load the OTBasket object out of that contract, and load the RequestBasket object that was passed in.
	OTBasket theBasket, theRequestBasket;
        
	if (pContract->GetBasketInfo().GetLength()  && theBasket.LoadContractFromString(pContract->GetBasketInfo()) &&
        BASKET_INFO.GetLength()                 && theRequestBasket.LoadContractFromString(BASKET_INFO))
	{
        const OTIdentifier & BASKET_ASSET_ACCT_ID(theRequestBasket.GetRequestAccountID());

        // -------------------------------------------------------------------------
        OTAccount * pAccount = m_pWallet->GetAccount(BASKET_ASSET_ACCT_ID);
        // no cleanup object here because the wallet owns the account.
        
        if (NULL == pAccount)
        {
            OTLog::Output(0, "OT_API::exchangeBasket: There's no asset account in the wallet with that ID. Trying to load from storage...\n");
            
            pAccount =  OTAccount::LoadExistingAccount(BASKET_ASSET_ACCT_ID, SERVER_ID);
            
            if (NULL != pAccount) // It loaded...
            {
                if (SERVER_ID != pAccount->GetRealServerID())
                {
                    OTLog::Output(0, "OT_API::exchangeBasket: server ID passed in didn't match "
                                  "the one on the account.\n");
                    delete pAccount; pAccount = NULL;
                    return;			
                }
                
                if (false == pAccount->VerifyOwner(*pNym)) // Verifies Ownership.
                {
                    OTLog::Output(0, "OT_API::exchangeBasket: User is not the owner of the account..\n");
                    delete pAccount; pAccount = NULL;
                    return;			
                }
                
                // By this point, I know the user is listed on the account as the owner.
                
                // -----------------------------------------------------
                
                if (false == pAccount->VerifyAccount(*pNym)) // Verifies ContractID and Signature.
                {
                    OTLog::Output(0, "OT_API::exchangeBasket: Bad signature or Account ID.\n");
                    delete pAccount; pAccount = NULL;
                    return;			
                }
                
                // By this point, I know that everything checks out. Signature and Account ID.
                
                // -----------------------------------------------------
                
                m_pWallet->AddAccount(*pAccount);
                
                // -----------------------------------------------------
            }
            else 
            {
                OTLog::Error("Error loading Asset Account in OT_API::exchangeBasket\n");
                return;
            }
        }
        // ------------------------------------------------------------------------

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
                
                OTLedger * pInbox	= pAccount->LoadInbox(*pNym);
                OTLedger * pOutbox	= pAccount->LoadOutbox(*pNym);
                
                OTCleanup<OTLedger> theInboxAngel(pInbox);
                OTCleanup<OTLedger> theOutboxAngel(pOutbox);
                
                if (NULL == pInbox)
                {
                    OTLog::Output(0, "Failed loading inbox!\n");
                
                    // IF FAILED, ADD TRANSACTION NUMBER BACK TO LIST OF AVAILABLE NUMBERS.
                    pNym->AddTransactionNum(*pNym, strServerID, lStoredTransactionNumber, true); // bSave=true
                }
                else if (NULL == pOutbox)
                {
                    OTLog::Output(0, "Failed loading outbox!\n");
                    
                    // IF FAILED, ADD TRANSACTION NUMBER BACK TO LIST OF AVAILABLE NUMBERS.
                    pNym->AddTransactionNum(*pNym, strServerID, lStoredTransactionNumber, true); // bSave=true
                }
                // Set up the Request Basket! ------------------------------
                else
                {   
                    // Create a transaction
                    OTTransaction * pTransaction = 
                        OTTransaction::GenerateTransaction (USER_ID, BASKET_ASSET_ACCT_ID, SERVER_ID, OTTransaction::exchangeBasket, lStoredTransactionNumber); 
                    
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
                    theRequestBasket.SaveContract(strBasketInfo);
                    
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
	OT_ASSERT_MSG(m_bInitialized, "Not initialized; call OT_API::Init first.");
	
	// -----------------------------------------------------------------
	
	OTServerContract * pServer = m_pWallet->GetServerContract(SERVER_ID);
	
	if (!pServer)
	{
		OTLog::Output(0, "That server contract is not available in the wallet.\n");
		
		return;
	}
	
	
	// -----------------------------------------------------
	
	OTPseudonym * pNym = m_pWallet->GetNymByID(USER_ID);
	
	if (NULL == pNym) // Wasn't already in the wallet.
	{
		OTLog::Output(0, "There's no User already loaded with that ID. Loading...\n");
		
		pNym = this->LoadPrivateNym(USER_ID);
		
		if (NULL == pNym) // LoadPrivateNym has plenty of error logging already.	
			return;
		
		m_pWallet->AddNym(*pNym);
	}
	
	// By this point, pNym is a good pointer, and is on the wallet.
	//  (No need to cleanup.)
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
		OTLog::Error("Error processing getTransactionNumber command in OT_API::getTransactionNumber\n");
}





void OT_API::notarizeWithdrawal(OTIdentifier	& SERVER_ID,
								OTIdentifier	& USER_ID,
								OTIdentifier	& ACCT_ID,
								OTString		& AMOUNT)
{
	OT_ASSERT_MSG(m_bInitialized, "Not initialized; call OT_API::Init first.");
	
	// -----------------------------------------------------------------
	
	OTServerContract * pServer = m_pWallet->GetServerContract(SERVER_ID);
	
	if (!pServer)
	{
		OTLog::Output(0, "That server contract is not available in the wallet.\n");
		
		return;
	}
	
	// -----------------------------------------------------
	
	OTPseudonym * pNym = m_pWallet->GetNymByID(USER_ID);
	
	if (NULL == pNym) // Wasn't already in the wallet.
	{
		OTLog::Output(0, "There's no User already loaded with that ID. Loading...\n");
		
		pNym = this->LoadPrivateNym(USER_ID);
		
		if (NULL == pNym) // LoadPrivateNym has plenty of error logging already.	
			return;
		
		m_pWallet->AddNym(*pNym);
	}
	
	// By this point, pNym is a good pointer, and is on the wallet.
	//  (No need to cleanup.)
	// -----------------------------------------------------
	
	OTIdentifier	CONTRACT_ID;
	OTString		strContractID, strServerID(SERVER_ID);
	
	OTAccount * pAccount = m_pWallet->GetAccount(ACCT_ID);
	
	if (NULL == pAccount)
	{
		OTLog::Output(0, "There is no account in the wallet with that ID.\n");
		
		return;
	}
	else 
	{
		CONTRACT_ID = pAccount->GetAssetTypeID();
		CONTRACT_ID.GetString(strContractID);
	}
	
	// --------------------------------------------------------------------
	
	if (false == OTDB::Exists(OTLog::MintFolder(), strServerID.Get(), strContractID.Get()))
	{
		OTLog::vError("OTContract::SignContract: File does not exist: %s%s%s%s%s\n", 
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
		OTLog::Output(0, "Failed loading inbox!\n");
	}
	
	else if (NULL == pOutbox)
	{
		OTLog::Output(0, "Failed loading outbox!\n");
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
		OTString strNote("Gimme cash!");
		pItem->SetNote(strNote);
		
		const OTPseudonym * pServerNym = pServer->GetContractPublicNym();
		
		// -----------------------------------------------------------------

		if ((NULL != pServerNym) && 
			theMint.LoadMint() && 
			theMint.VerifyMint((OTPseudonym&)*pServerNym))
		{
			OTPurse * pPurse		= new OTPurse(SERVER_ID, CONTRACT_ID);
			OTPurse * pPurseMyCopy	= new OTPurse(SERVER_ID, CONTRACT_ID);
			
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
			
			pPurse->SignContract(*pNym);
			pPurse->SaveContract(); // I think this one is unnecessary.
			
			// Save the purse into a string...
			OTString strPurse;
			pPurse->SaveContract(strPurse);
			
			// Add the purse string as the attachment on the transaction item.
			pItem->SetAttachment(strPurse); // The purse is contained in the reference string.
			
			
			pPurseMyCopy->SignContract(*pNym);		// encrypted to me instead of the server, and including 
			pPurseMyCopy->SaveContract();			// the private keys for unblinding the server response.
			// This thing is neat and tidy. The wallet can just save it as an ascii-armored string as a
			// purse field inside the wallet file.  It doesn't do that for now (TODO) but it easily could.
			
			
			// Add the purse to the wallet
			// (We will need it to look up the private coin info for unblinding the token,
			//  when the response comes from the server.)
			m_pWallet->AddPendingWithdrawal(*pPurseMyCopy);
			
			delete pPurse;
			pPurse			= NULL; // We're done with this one.
			pPurseMyCopy	= NULL; // The wallet owns my copy now and will handle cleaning it up.
			
			
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
	OT_ASSERT_MSG(m_bInitialized, "Not initialized; call OT_API::Init first.");
	
	// -----------------------------------------------------------------
	
	OTServerContract * pServer = m_pWallet->GetServerContract(SERVER_ID);
	
	if (!pServer)
	{
		OTLog::Output(0, "That server contract is not available in the wallet.\n");
		
		return;
	}
	
	
	// -----------------------------------------------------
	
	OTPseudonym * pNym = m_pWallet->GetNymByID(USER_ID);
	
	if (NULL == pNym) // Wasn't already in the wallet.
	{
		OTLog::Output(0, "There's no User already loaded with that ID. Loading...\n");
		
		pNym = this->LoadPrivateNym(USER_ID);
		
		if (NULL == pNym) // LoadPrivateNym has plenty of error logging already.	
			return;
		
		m_pWallet->AddNym(*pNym);
	}
	
	// By this point, pNym is a good pointer, and is on the wallet.
	//  (No need to cleanup.)
	// -----------------------------------------------------
	
	OTIdentifier	CONTRACT_ID;
	OTString		strContractID;
	
	OTAccount * pAccount = m_pWallet->GetAccount(ACCT_ID);
	
	if (NULL == pAccount)
	{
		OTLog::Output(0, "There is no account in the wallet with that ID.\n");
		
		return;
	}
	else 
	{
		CONTRACT_ID = pAccount->GetAssetTypeID();
		CONTRACT_ID.GetString(strContractID);
	}
	
	
	// -----------------------------------------------------------------
	
	OTMessage theMessage;
	long lRequestNumber = 0;
	
	OTString strServerID(SERVER_ID), strNymID(USER_ID), strFromAcct(ACCT_ID);
	
	
	OTPurse thePurse(SERVER_ID, CONTRACT_ID);
	
	const OTPseudonym * pServerNym = pServer->GetContractPublicNym();
	
	long lStoredTransactionNumber=0;
	bool bGotTransNum = false;
	
	// ---------------------------------------------
	
	OTLedger * pInbox	= pAccount->LoadInbox(*pNym);
	OTLedger * pOutbox	= pAccount->LoadOutbox(*pNym);
	
	OTCleanup<OTLedger> theInboxAngel(pInbox);
	OTCleanup<OTLedger> theOutboxAngel(pOutbox);
	
	if (NULL == pInbox)
	{
		OTLog::Output(0, "Failed loading inbox!\n");
	}
	
	else if (NULL == pOutbox)
	{
		OTLog::Output(0, "Failed loading outbox!\n");
	}
	
	else if (!(bGotTransNum = pNym->GetNextTransactionNum(*pNym, strServerID, lStoredTransactionNumber)))
	{
		OTLog::Output(0, "No Transaction Numbers were available. Try requesting the server for a new one.\n");
	}
	
	else if (pServerNym)
	{
		bool bSuccess = false;
		
		// Create a transaction
		OTTransaction * pTransaction = OTTransaction::GenerateTransaction (USER_ID, ACCT_ID, SERVER_ID, 
																		   OTTransaction::deposit, lStoredTransactionNumber); 
		
		// set up the transaction item (each transaction may have multiple items...)
		OTItem * pItem		= OTItem::CreateItemFromTransaction(*pTransaction, OTItem::deposit);
		
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
						OTLog::Error("Error re-assigning ownership of token (to server.)\n");
						delete pToken;
						pToken = NULL;
						bSuccess = false;
						break;
					}
					else 
					{
						OTLog::vOutput(3, "Success re-assigning ownership of token (to server.)\n");
						
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
				else {
					OTLog::Error("Error loading token from purse.\n");
					break;
				}
				
			}
		
		if (bSuccess)
		{
			thePurse.SignContract(*pNym);
			thePurse.SaveContract(); // I think this one is unnecessary.
			
			// Save the purse into a string...
			OTString strPurse;
			thePurse.SaveContract(strPurse);
			
			// Add the purse string as the attachment on the transaction item.
			pItem->SetAttachment(strPurse); // The purse is contained in the reference string.
			
			// sign the item
			pItem->SignContract(*pNym);
			pItem->SaveContract();
			
			// the Transaction "owns" the item now and will handle cleaning it up.
			pTransaction->AddItem(*pItem); // the Transaction's destructor will cleanup the item. It "owns" it now.
			
			// ---------------------------------------------
			// BALANCE AGREEMENT
			
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
	OT_ASSERT_MSG(m_bInitialized, "Not initialized; call OT_API::Init first.");

	// -----------------------------------------------------------------
	
	OTServerContract * pServer = m_pWallet->GetServerContract(SERVER_ID);
	
	if (!pServer)
	{
		OTLog::Output(0, "That server contract is not available in the wallet.\n");
		
		return;
	}
	
	
	// -----------------------------------------------------
	
	OTPseudonym * pNym = m_pWallet->GetNymByID(USER_ID);
	
	if (NULL == pNym) // Wasn't already in the wallet.
	{
		OTLog::Output(0, "There's no User already loaded with that ID. Loading...\n");
		
		pNym = this->LoadPrivateNym(USER_ID);
		
		if (NULL == pNym) // LoadPrivateNym has plenty of error logging already.	
			return;
		
		m_pWallet->AddNym(*pNym);
	}
	
	// By this point, pNym is a good pointer, and is on the wallet.
	//  (No need to cleanup.)
	// -----------------------------------------------------
	
	OTIdentifier	CONTRACT_ID;
	OTString		strContractID;
	
	OTAccount * pAccount = m_pWallet->GetAccount(ACCT_ID);
	
	if (NULL == pAccount)
	{
		OTLog::Output(0, "There is no account in the wallet with that ID.\n");
		
		return;
	}
	else 
	{
		CONTRACT_ID = pAccount->GetAssetTypeID();
		CONTRACT_ID.GetString(strContractID);
	}
	
	
	// -----------------------------------------------------------------
	
	OTMessage theMessage;
	
	long lAmount = atol(AMOUNT.Get());
	
	OTString strServerID(SERVER_ID), strNymID(USER_ID), strFromAcct(ACCT_ID);
	
	long lStoredTransactionNumber=0;
	bool bGotTransNum = pNym->GetNextTransactionNum(*pNym, strServerID, lStoredTransactionNumber);
	
	if (bGotTransNum)
	{
		const OTString strChequeMemo(CHEQUE_MEMO);
		const OTString strRecipientUserID(RECIPIENT_USER_ID);
		
		const long lAmount = atol(AMOUNT.Get());

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
			OTLog::Output(0, "Failed loading inbox!\n");
			
			// IF FAILED, ADD TRANSACTION NUMBER BACK TO LIST OF AVAILABLE NUMBERS.
			pNym->AddTransactionNum(*pNym, strServerID, lStoredTransactionNumber, true); // bSave=true								
		}
		
		else if (NULL == pOutbox)
		{
			OTLog::Output(0, "Failed loading outbox!\n");
			
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
	{
		OTLog::Output(0, "No Transaction Numbers were available. Suggest requesting the server for a new one.\n");
	}
}



















// ------------------------------------------------------------------------







// ----------------------------------------------------------------
// DEPOSIT CHEQUE
//

void OT_API::depositCheque(OTIdentifier	& SERVER_ID,
						   OTIdentifier	& USER_ID,
						   OTIdentifier	& ACCT_ID,
						   OTString		& THE_CHEQUE)
{
	OT_ASSERT_MSG(m_bInitialized, "Not initialized; call OT_API::Init first.");
	
	// -----------------------------------------------------------------
	
	OTServerContract * pServer = m_pWallet->GetServerContract(SERVER_ID);
	
	if (!pServer)
	{
		OTLog::Output(0, "That server contract is not available in the wallet.\n");
		
		return;
	}
	
	
	// -----------------------------------------------------
	
	OTPseudonym * pNym = m_pWallet->GetNymByID(USER_ID);
	
	if (NULL == pNym) // Wasn't already in the wallet.
	{
		OTLog::Output(0, "There's no User already loaded with that ID. Loading...\n");
		
		pNym = this->LoadPrivateNym(USER_ID);
		
		if (NULL == pNym) // LoadPrivateNym has plenty of error logging already.	
			return;
		
		m_pWallet->AddNym(*pNym);
	}
	
	// By this point, pNym is a good pointer, and is on the wallet.
	//  (No need to cleanup.)
	// -----------------------------------------------------
	
	OTIdentifier	CONTRACT_ID;
	OTString		strContractID;
	
	OTAccount * pAccount = m_pWallet->GetAccount(ACCT_ID);
	
	if (NULL == pAccount)
	{
		OTLog::Output(0, "There is no account in the wallet with that ID.\n");
		
		return;
	}
	else 
	{
		CONTRACT_ID = pAccount->GetAssetTypeID();
		CONTRACT_ID.GetString(strContractID);
	}
	
	// -----------------------------------------------------------------
	
	OTMessage theMessage;
	long lRequestNumber = 0;
	
	OTString strServerID(SERVER_ID), strNymID(USER_ID), strFromAcct(ACCT_ID);
	
	OTCheque theCheque(SERVER_ID, CONTRACT_ID);
	
	long lStoredTransactionNumber=0;
	bool bGotTransNum = pNym->GetNextTransactionNum(*pNym, strServerID, lStoredTransactionNumber);
	
	if (!bGotTransNum)
	{
		OTLog::Output(0, "No Transaction Numbers were available. Try requesting the server for a new one.\n");
	}
	else if (!theCheque.LoadContractFromString(THE_CHEQUE))
	{
		OTLog::Output(0, "Unable to load cheque from string. Sorry.\n");
		
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
		
		OTString strNote("Deposit this cheque, please!");
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
			OTLog::Output(0, "Failed loading inbox!\n");
			
			// IF FAILED, ADD TRANSACTION NUMBER BACK TO LIST OF AVAILABLE NUMBERS.
			pNym->AddTransactionNum(*pNym, strServerID, lStoredTransactionNumber, true); // bSave=true								
		}
		
		else if (NULL == pOutbox)
		{
			OTLog::Output(0, "Failed loading outbox!\n");
			
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
	OT_ASSERT_MSG(m_bInitialized, "Not initialized; call OT_API::Init first.");
	
	// -----------------------------------------------------
	
	OTWallet * pWallet = GetWallet();
	
	if (NULL == pWallet)
	{
		OTLog::Output(0, "The Wallet is not loaded.\n");
		return;
	}
	
	// By this point, pWallet is a good pointer.  (No need to cleanup.)
	
	// -----------------------------------------------------
	
		
	OTServerContract * pServer = pWallet->GetServerContract(SERVER_ID);
	
	if (!pServer)
	{
		OTLog::Output(0, "That server contract is not available in the wallet.\n");
		
		return;
	}
	
	// By this point, pServer is a good pointer.  (No need to cleanup.)
	
	// -----------------------------------------------------------------

	OTPseudonym * pNym = pWallet->GetNymByID(USER_ID);
	
	if (NULL == pNym) // Wasn't already in the wallet.
	{
		OTLog::Output(0, "There's no User already loaded with that ID. Loading...\n");
		
		pNym = this->LoadPrivateNym(USER_ID);
		
		if (NULL == pNym) // LoadPrivateNym has plenty of error logging already.	
		{
			return;
		}
		
		pWallet->AddNym(*pNym);
	}
	
	// By this point, pNym is a good pointer, and is on the wallet.
	//  (No need to cleanup.)
	// -----------------------------------------------------
	
	OTPaymentPlan	thePlan;
	OTMessage		theMessage;
	
	long lRequestNumber = 0;
	
	const OTString strServerID(SERVER_ID), strNymID(USER_ID);
	
	
	if (thePlan.LoadContractFromString(THE_PAYMENT_PLAN) &&
		thePlan.VerifySignature(*pNym))
	{
		const OTIdentifier	SENDER_ACCT_ID(thePlan.GetSenderAcctID());
		const OTString		strFromAcct(SENDER_ACCT_ID);
	
		OTAccount * pAccount = pWallet->GetAccount(SENDER_ACCT_ID);
		
		if (NULL == pAccount)
		{
			OTLog::Output(0, "There's no asset account in the wallet with that ID. Trying to load from storage...\n");
			
			pAccount =  OTAccount::LoadExistingAccount(SENDER_ACCT_ID, SERVER_ID);
			
			if (NULL != pAccount) // It loaded...
			{
				if (SERVER_ID != pAccount->GetRealServerID())
				{
					OTLog::Output(0, "Depositing a payment plan, server ID passed in didn't match the one on the account.\n");
					delete pAccount; pAccount = NULL;
					return;			
				}
						
				if (false == pAccount->VerifyOwner(*pNym)) // Verifies Ownership.
				{
					OTLog::Output(0, "depositPaymentPlan: User is not the owner of the account.\n");
					delete pAccount; pAccount = NULL;
					return;			
				}
				
				// By this point, I know the user is listed on the account as the owner.
				
				// -----------------------------------------------------
				
				if (false == pAccount->VerifyAccount(*pNym)) // Verifies ContractID and Signature.
				{
					OTLog::Output(0, "depositPaymentPlan: Bad signature or Account ID.\n");
					delete pAccount; pAccount = NULL;
					return;			
				}
				
				// By this point, I know that everything checks out. Signature and Account ID.
				
				// -----------------------------------------------------
				
				pWallet->AddAccount(*pAccount);

				// -----------------------------------------------------
			}
			else 
			{
				OTLog::Error("Error loading Asset Account in OT_API::depositPaymentPlan\n");
				return;
			}
		} // if NULL == pAccount == pWallet->getAccount()
		
		if (false == pAccount->VerifyOwner(*pNym)) // Verifies Ownership.
		{
			OTLog::Output(0, "depositPaymentPlan: User is not the owner of the account.\n");
			return;			
		}
		
		// By this point, I know the user is listed on the account as the owner.
		
		// -----------------------------------------------------
		
		if (false == pAccount->VerifyAccount(*pNym)) // Verifies ContractID and Signature.
		{
			OTLog::Output(0, "depositPaymentPlan: Bad signature or Account ID.\n");
			return;			
		}
		
		// By this point, I know that everything checks out. Signature and Account ID.
		
		// -----------------------------------------------------
		
		// By this point, pAccount is a good pointer and in the wallet. 
		// (No need to cleanup.) I also know it has the right Server ID
		// and that the Nym owns it, and has signed it.
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
						   const OTString		& strClauseName)
{
	OT_ASSERT_MSG(m_bInitialized, "Not initialized; call OT_API::Init first.");
	// -----------------------------------------------------------------
	OTServerContract * pServer = m_pWallet->GetServerContract(SERVER_ID);
	
	if (!pServer)
	{
		OTLog::Output(0, "That server contract is not available in the wallet.\n");
		
		return;
	}
	// -----------------------------------------------------
	OTPseudonym * pNym = m_pWallet->GetNymByID(USER_ID);
	
	if (NULL == pNym) // Wasn't already in the wallet.
	{
		OTLog::Output(0, "There's no User already loaded with that ID. Loading...\n");
		
		pNym = this->LoadPrivateNym(USER_ID);
		
		if (NULL == pNym) // LoadPrivateNym has plenty of error logging already.	
			return;
		
		m_pWallet->AddNym(*pNym);
	}
	// By this point, pNym is a good pointer, and is on the wallet.
	//  (No need to cleanup.)
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
	OT_ASSERT_MSG(m_bInitialized, "Not initialized; call OT_API::Init first.");
	// -----------------------------------------------------
	OTWallet * pWallet = GetWallet();
	
	if (NULL == pWallet)
	{
		OTLog::Output(0, "The Wallet is not loaded.\n");
		return;
	}
	// By this point, pWallet is a good pointer.  (No need to cleanup.)
	// -----------------------------------------------------
	OTServerContract * pServer = pWallet->GetServerContract(SERVER_ID);
	
	if (!pServer)
	{
		OTLog::Output(0, "That server contract is not available in the wallet.\n");
		
		return;
	}
	// By this point, pServer is a good pointer.  (No need to cleanup.)
	// -----------------------------------------------------------------
	OTPseudonym * pNym = pWallet->GetNymByID(USER_ID);
	
	if (NULL == pNym) // Wasn't already in the wallet.
	{
		OTLog::Output(0, "There's no User already loaded with that ID. Loading...\n");
		
		pNym = this->LoadPrivateNym(USER_ID);
		
		if (NULL == pNym) // LoadPrivateNym has plenty of error logging already.	
		{
			return;
		}
		
		pWallet->AddNym(*pNym);
	}
	// By this point, pNym is a good pointer, and is on the wallet.
	//  (No need to cleanup.)
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
	{
		OTLog::Output(0, "Unable to load smart contract from string, sorry.\n");
	}
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
    OT_ASSERT_MSG(m_bInitialized, "Not initialized; call OT_API::Init first.");
	
	// -----------------------------------------------------
	// WALLET
	OTWallet * pWallet = GetWallet();
	
	if (NULL == pWallet)
	{
		OTLog::Output(0, "The Wallet is not loaded.\n");
		return;
	}
	
	// By this point, pWallet is a good pointer.  (No need to cleanup.)
	
	// -----------------------------------------------------
	// SERVER CONTRACT
	OTServerContract * pServer = pWallet->GetServerContract(SERVER_ID);
	
	if (!pServer)
	{
		OTLog::Output(0, "That server contract is not available in the wallet.\n");
		
		return;
	}
	
	// By this point, pServer is a good pointer.  (No need to cleanup.)
	
	// -----------------------------------------------------------------
	// NYM
	OTPseudonym * pNym = pWallet->GetNymByID(USER_ID);
	
	if (NULL == pNym) // Wasn't already in the wallet.
	{
		OTLog::Output(0, "There's no User already loaded with that ID. Loading...\n");
		
		pNym = this->LoadPrivateNym(USER_ID);
		
		if (NULL == pNym) // LoadPrivateNym has plenty of error logging already.	
		{
			return;
		}
		
		pWallet->AddNym(*pNym);
	}
	
	// By this point, pNym is a good pointer, and is on the wallet.
	//  (No need to cleanup.)
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
	{
		OTLog::Error("OT_API::cancelCronItem: Supposedly there was a transaction number available, but the call\n"
                     "still failed.\n");
    }
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



// DONE:  Make sure this includes a CLOSING transaction num!
// Copy the payment plan code....

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
	OT_ASSERT_MSG(m_bInitialized, "Not initialized; call OT_API::Init first.");
	
	// -----------------------------------------------------
	
	OTWallet * pWallet = GetWallet();
	
	if (NULL == pWallet)
	{
		OTLog::Output(0, "The Wallet is not loaded.\n");
		return;
	}
	
	// By this point, pWallet is a good pointer.  (No need to cleanup.)
	
	// -----------------------------------------------------
	
	
	OTServerContract * pServer = pWallet->GetServerContract(SERVER_ID);
	
	if (!pServer)
	{
		OTLog::Output(0, "That server contract is not available in the wallet.\n");
		
		return;
	}
	
	// By this point, pServer is a good pointer.  (No need to cleanup.)
	
	// -----------------------------------------------------------------
	
	OTPseudonym * pNym = pWallet->GetNymByID(USER_ID);
	
	if (NULL == pNym) // Wasn't already in the wallet.
	{
		OTLog::Output(0, "There's no User already loaded with that ID. Loading...\n");
		
		pNym = this->LoadPrivateNym(USER_ID);
		
		if (NULL == pNym) // LoadPrivateNym has plenty of error logging already.	
		{
			return;
		}
		
		pWallet->AddNym(*pNym);
	}
	
	// By this point, pNym is a good pointer, and is on the wallet.
	//  (No need to cleanup.)
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
		
		lTotalAssetsOnOffer *= lMinimumIncrement;
		
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
			
			OT_ASSERT_MSG(NULL != pItem, "Error allocating memory in the OT API");
			
			OTString strTrade;
			theTrade.SaveContract(strTrade);
			
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
			OTLog::Output(0, "Unable to create offer or issue trade. Sorry.\n");
			
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
	OT_ASSERT_MSG(m_bInitialized, "Not initialized; call OT_API::Init first.");
	
	// -----------------------------------------------------
	
	OTWallet * pWallet = GetWallet();
	
	if (NULL == pWallet)
	{
		OTLog::Output(0, "The Wallet is not loaded.\n");
		return;
	}
	
	// By this point, pWallet is a good pointer.  (No need to cleanup.)
	
	// -----------------------------------------------------
	
	OTPseudonym * pNym = pWallet->GetNymByID(USER_ID);
	
	if (NULL == pNym) // Wasn't already in the wallet.
	{
		OTLog::Output(0, "There's no User already loaded with that ID. Loading...\n");
		
		pNym = this->LoadPrivateNym(USER_ID);
		
		if (NULL == pNym) // LoadPrivateNym has plenty of error logging already.	
			return;
		
		pWallet->AddNym(*pNym);
	}
	
	// By this point, pNym is a good pointer, and is on the wallet.
	//  (No need to cleanup.)
	// -----------------------------------------------------------------

	OTServerContract * pServer = pWallet->GetServerContract(SERVER_ID);
	
	if (!pServer)
	{
		OTLog::Output(0, "That server contract is not available in the wallet.\n");
		
		return;
	}
	
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
	OT_ASSERT_MSG(m_bInitialized, "Not initialized; call OT_API::Init first.");
	
	// -----------------------------------------------------
	
	OTWallet * pWallet = GetWallet();
	
	if (NULL == pWallet)
	{
		OTLog::Output(0, "The Wallet is not loaded.\n");
		return;
	}
	
	// By this point, pWallet is a good pointer.  (No need to cleanup.)
	
	// -----------------------------------------------------
	
	OTPseudonym * pNym = pWallet->GetNymByID(USER_ID);
	
	if (NULL == pNym) // Wasn't already in the wallet.
	{
		OTLog::Output(0, "There's no User already loaded with that ID. Loading...\n");
		
		pNym = this->LoadPrivateNym(USER_ID);
		
		if (NULL == pNym) // LoadPrivateNym has plenty of error logging already.	
			return;
		
		pWallet->AddNym(*pNym);
	}
	
	// By this point, pNym is a good pointer, and is on the wallet.
	//  (No need to cleanup.)
	// -----------------------------------------------------------------
	
	OTServerContract * pServer = pWallet->GetServerContract(SERVER_ID);
	
	if (!pServer)
	{
		OTLog::Output(0, "That server contract is not available in the wallet.\n");
		
		return;
	}
	
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
	OT_ASSERT_MSG(m_bInitialized, "Not initialized; call OT_API::Init first.");
	
	// -----------------------------------------------------
	
	OTWallet * pWallet = GetWallet();
	
	if (NULL == pWallet)
	{
		OTLog::Output(0, "The Wallet is not loaded.\n");
		return;
	}
	
	// By this point, pWallet is a good pointer.  (No need to cleanup.)
	
	// -----------------------------------------------------
	
	OTPseudonym * pNym = pWallet->GetNymByID(USER_ID);
	
	if (NULL == pNym) // Wasn't already in the wallet.
	{
		OTLog::Output(0, "There's no User already loaded with that ID. Loading...\n");
		
		pNym = this->LoadPrivateNym(USER_ID);
		
		if (NULL == pNym) // LoadPrivateNym has plenty of error logging already.	
			return;
		
		pWallet->AddNym(*pNym);
	}
	
	// By this point, pNym is a good pointer, and is on the wallet.
	//  (No need to cleanup.)
	// -----------------------------------------------------------------
	
	OTServerContract * pServer = pWallet->GetServerContract(SERVER_ID);
	
	if (!pServer)
	{
		OTLog::Output(0, "That server contract is not available in the wallet.\n");
		
		return;
	}
	
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
	OT_ASSERT_MSG(m_bInitialized, "Not initialized; call OT_API::Init first.");
	
	// -----------------------------------------------------
	
	OTWallet * pWallet = GetWallet();
	
	if (NULL == pWallet)
	{
		OTLog::Output(0, "The Wallet is not loaded.\n");
		return;
	}
	
	// By this point, pWallet is a good pointer.  (No need to cleanup.)
	
	// -----------------------------------------------------
	
	OTPseudonym * pNym = pWallet->GetNymByID(USER_ID);
	
	if (NULL == pNym) // Wasn't already in the wallet.
	{
		OTLog::Output(0, "There's no User already loaded with that ID. Loading...\n");
		
		pNym = this->LoadPrivateNym(USER_ID);
		
		if (NULL == pNym) // LoadPrivateNym has plenty of error logging already.	
			return;
		
		pWallet->AddNym(*pNym);
	}
	
	// By this point, pNym is a good pointer, and is on the wallet.
	//  (No need to cleanup.)
	// -----------------------------------------------------------------
	
	OTServerContract * pServer = pWallet->GetServerContract(SERVER_ID);
	
	if (!pServer)
	{
		OTLog::Output(0, "That server contract is not available in the wallet.\n");
		
		return;
	}
	
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
	OT_ASSERT_MSG(m_bInitialized, "Not initialized; call OT_API::Init first.");
	
	// -----------------------------------------------------------------
	
	OTServerContract * pServer = m_pWallet->GetServerContract(SERVER_ID);
	
	if (!pServer)
	{
		OTLog::Output(0, "That server contract is not available in the wallet.\n");
		
		return;
	}
	
	
	// -----------------------------------------------------
	
	OTPseudonym * pNym = m_pWallet->GetNymByID(USER_ID);
	
	if (NULL == pNym) // Wasn't already in the wallet.
	{
		OTLog::Output(0, "There's no User already loaded with that ID. Loading...\n");
		
		pNym = this->LoadPrivateNym(USER_ID);
		
		if (NULL == pNym) // LoadPrivateNym has plenty of error logging already.	
			return;
		
		m_pWallet->AddNym(*pNym);
	}
	
	// By this point, pNym is a good pointer, and is on the wallet.
	//  (No need to cleanup.)
	// -----------------------------------------------------
	
	OTAccount * pAccount = m_pWallet->GetAccount(ACCT_FROM);
	
	if (NULL == pAccount)
	{
		OTLog::Output(0, "There is no account in the wallet with that ID.\n");
		
		return;
	}

	// -----------------------------------------------------------------	
	
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
			OTLog::Output(0, "Failed loading inbox!\n");
			
			// IF FAILED, ADD TRANSACTION NUMBER BACK TO LIST OF AVAILABLE NUMBERS.
			pNym->AddTransactionNum(*pNym, strServerID, lStoredTransactionNumber, true); // bSave=true				
		}
		
		else if (NULL == pOutbox)
		{
			OTLog::Output(0, "Failed loading outbox!\n");
			
			// IF FAILED, ADD TRANSACTION NUMBER BACK TO LIST OF AVAILABLE NUMBERS.
			pNym->AddTransactionNum(*pNym, strServerID, lStoredTransactionNumber, true); // bSave=true				
		}
		
		else 
		{
			// Need to setup a dummy outbox transaction (to mimic the one that will be on the server side when this pending transaction is actually put into the real outbox.)
			// When the server adds its own, and then compares the two, they should both show the same pending transaction, in order for this balance agreement to be valid..
			// Otherwise the server would have to refuse it for being inaccurate (server can't sign something inaccurate!) So I throw a dummy on there before generating balance statement.
			
			OTTransaction * pOutboxTransaction	= OTTransaction::GenerateTransaction(*pOutbox, OTTransaction::pending,
																					 1/*todo pick some number that everyone agrees doesn't matter, like 1. The referring-to is the important 
																					   number in this case, and perhaps server should update this value too before signing and returning.*/); // todo use a constant instead of '1'
			
			OT_ASSERT(NULL != pOutboxTransaction); // for now.
			
			OTString strItem(*pItem);
			pOutboxTransaction->SetReferenceString(strItem); // So the GenerateBalanceStatement function below can get the other info off this item (like amount, etc)
			pOutboxTransaction->SetReferenceToNum(pItem->GetTransactionNum());
			
//			pOutboxTransaction->SignContract(*pNym);	// Unnecessary to sign/save, since this is just a dummy data for verification
//			pOutboxTransaction->SaveContract();			// purposes, and isn't being serialized anywhere.
			
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
	{
		OTLog::Output(0, "No transaction numbers were available. Suggest requesting the server for one.\n");
		
		// IF FAILED, ADD TRANSACTION NUMBER BACK TO LIST OF AVAILABLE NUMBERS.
//		pNym->AddTransactionNum(*pNym, strServerID, lStoredTransactionNumber, true); // bSave=true	
		// Duh! No need to re-add a transaction num when the error is that there weren't any transaction numbers...
	}	
}





void OT_API::getNymbox(OTIdentifier & SERVER_ID,
					   OTIdentifier & USER_ID)
{
	OT_ASSERT_MSG(m_bInitialized, "Not initialized; call OT_API::Init first.");
	
	// -----------------------------------------------------------------
	
	OTServerContract * pServer = m_pWallet->GetServerContract(SERVER_ID);
	
	if (!pServer)
	{
		OTLog::Output(0, "That server contract is not available in the wallet.\n");
		
		return;
	}
	
	// -----------------------------------------------------
	
	OTPseudonym * pNym = m_pWallet->GetNymByID(USER_ID);
	
	if (NULL == pNym) // Wasn't already in the wallet.
	{
		OTLog::Output(0, "There's no User already loaded with that ID. Loading...\n");
		
		pNym = this->LoadPrivateNym(USER_ID);
		
		if (NULL == pNym) // LoadPrivateNym has plenty of error logging already.	
			return;
		
		m_pWallet->AddNym(*pNym);
	}
	
	// By this point, pNym is a good pointer, and is on the wallet.
	//  (No need to cleanup.)
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
	OT_ASSERT_MSG(m_bInitialized, "Not initialized; call OT_API::Init first.");
	
	// -----------------------------------------------------------------
	
	OTServerContract * pServer = m_pWallet->GetServerContract(SERVER_ID);
	
	if (!pServer)
	{
		OTLog::Output(0, "That server contract is not available in the wallet.\n");
		
		return;
	}
	
	
	// -----------------------------------------------------
	
	OTPseudonym * pNym = m_pWallet->GetNymByID(USER_ID);
	
	if (NULL == pNym) // Wasn't already in the wallet.
	{
		OTLog::Output(0, "There's no User already loaded with that ID. Loading...\n");
		
		pNym = this->LoadPrivateNym(USER_ID);
		
		if (NULL == pNym) // LoadPrivateNym has plenty of error logging already.	
			return;
		
		m_pWallet->AddNym(*pNym);
	}
	
	// By this point, pNym is a good pointer, and is on the wallet.
	//  (No need to cleanup.)
	// -----------------------------------------------------
	
	OTAccount * pAccount = m_pWallet->GetAccount(ACCT_ID);
	
	if (NULL == pAccount)
	{
		OTLog::Output(0, "There is no account in the wallet with that ID.\n");
		
		return;
	}
	
	// -----------------------------------------------------------------
	
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
	OT_ASSERT_MSG(m_bInitialized, "Not initialized; call OT_API::Init first.");
	
	// -----------------------------------------------------------------
	
	OTServerContract * pServer = m_pWallet->GetServerContract(SERVER_ID);
	
	if (!pServer)
	{
		OTLog::Output(0, "That server contract is not available in the wallet.\n");
		
		return;
	}
	
	
	// -----------------------------------------------------
	
	OTPseudonym * pNym = m_pWallet->GetNymByID(USER_ID);
	
	if (NULL == pNym) // Wasn't already in the wallet.
	{
		OTLog::Output(0, "There's no User already loaded with that ID. Loading...\n");
		
		pNym = this->LoadPrivateNym(USER_ID);
		
		if (NULL == pNym) // LoadPrivateNym has plenty of error logging already.	
			return;
		
		m_pWallet->AddNym(*pNym);
	}
	
	// By this point, pNym is a good pointer, and is on the wallet.
	//  (No need to cleanup.)
	// -----------------------------------------------------
	
	OTAccount * pAccount = m_pWallet->GetAccount(ACCT_ID);
	
	if (NULL == pAccount)
	{
		OTLog::Output(0, "There is no account in the wallet with that ID.\n");
		
		return;
	}
	
	// -----------------------------------------------------------------
	
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





void OT_API::processNymbox(OTIdentifier	& SERVER_ID,
						   OTIdentifier	& USER_ID,
						   OTString		& NYMBOX_LEDGER)
{
	OT_ASSERT_MSG(m_bInitialized, "Not initialized; call OT_API::Init first.");
	
	// -----------------------------------------------------------------
	
	OTServerContract * pServer = m_pWallet->GetServerContract(SERVER_ID);
	
	if (!pServer)
	{
		OTLog::Output(0, "That server contract is not available in the wallet.\n");
		
		return;
	}
	
	// -----------------------------------------------------
	
	OTPseudonym * pNym = m_pWallet->GetNymByID(USER_ID);
	
	if (NULL == pNym) // Wasn't already in the wallet.
	{
		OTLog::Output(0, "There's no User already loaded with that ID. Loading...\n");
		
		pNym = this->LoadPrivateNym(USER_ID);
		
		if (NULL == pNym) // LoadPrivateNym has plenty of error logging already.	
			return;
		
		m_pWallet->AddNym(*pNym);
	}
	
	// By this point, pNym is a good pointer, and is on the wallet.
	//  (No need to cleanup.)
	// -----------------------------------------------------
		
	OTMessage theMessage;
	long lRequestNumber = 0;
	
	OTString strServerID(SERVER_ID), strNymID(USER_ID);
	
	// (0) Set up the REQUEST NUMBER and then INCREMENT IT
	pNym->GetCurrentRequestNum(strServerID, lRequestNumber);
	theMessage.m_strRequestNum.Format("%ld", lRequestNumber); // Always have to send this.
	pNym->IncrementRequestNum(*pNym, strServerID); // since I used it for a server request, I have to increment it
	
	// (1) set up member variables 
	theMessage.m_strCommand			= "processNymbox";
	theMessage.m_strNymID			= strNymID;
	theMessage.m_strServerID		= strServerID;
	
	// Presumably NYMBOX_LEDGER was already set up before this function was called...
	// See test client for example of it being done.
	theMessage.m_ascPayload.SetString(NYMBOX_LEDGER);
	
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




void OT_API::processInbox(OTIdentifier	& SERVER_ID,
						  OTIdentifier	& USER_ID,
						  OTIdentifier	& ACCT_ID,
						  OTString		& ACCT_LEDGER)
{
	OT_ASSERT_MSG(m_bInitialized, "Not initialized; call OT_API::Init first.");
	
	// -----------------------------------------------------------------
	
	OTServerContract * pServer = m_pWallet->GetServerContract(SERVER_ID);
	
	if (!pServer)
	{
		OTLog::Output(0, "That server contract is not available in the wallet.\n");
		
		return;
	}
	
	
	// -----------------------------------------------------
	
	OTPseudonym * pNym = m_pWallet->GetNymByID(USER_ID);
	
	if (NULL == pNym) // Wasn't already in the wallet.
	{
		OTLog::Output(0, "There's no User already loaded with that ID. Loading...\n");
		
		pNym = this->LoadPrivateNym(USER_ID);
		
		if (NULL == pNym) // LoadPrivateNym has plenty of error logging already.	
			return;
		
		m_pWallet->AddNym(*pNym);
	}
	
	// By this point, pNym is a good pointer, and is on the wallet.
	//  (No need to cleanup.)
	// -----------------------------------------------------
	
	OTAccount * pAccount = m_pWallet->GetAccount(ACCT_ID);
	
	if (NULL == pAccount)
	{
		OTLog::Output(0, "There is no account in the wallet with that ID.\n");
		
		return;
	}
	
	// -----------------------------------------------------------------
	
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
	OT_ASSERT_MSG(m_bInitialized, "Not initialized; call OT_API::Init first.");

	// -----------------------------------------------------------------
	
	OTServerContract * pServer = m_pWallet->GetServerContract(SERVER_ID);
	
	if (!pServer)
	{
		OTLog::Output(0, "That server contract is not available in the wallet.\n");
		
		return;
	}
	
	
	// -----------------------------------------------------
	
	OTPseudonym * pNym = m_pWallet->GetNymByID(USER_ID);
	
	if (NULL == pNym) // Wasn't already in the wallet.
	{
		OTLog::Output(0, "There's no User already loaded with that ID. Loading...\n");
		
		pNym = this->LoadPrivateNym(USER_ID);
		
		if (NULL == pNym) // LoadPrivateNym has plenty of error logging already.	
			return;
		
		m_pWallet->AddNym(*pNym);
	}
	
	// By this point, pNym is a good pointer, and is on the wallet.
	//  (No need to cleanup.)
	// -----------------------------------------------------
	
	OTAssetContract theAssetContract;
	
	if (theAssetContract.LoadContractFromString(THE_CONTRACT))
	{
		OTIdentifier	newID;
		theAssetContract.CalculateContractID(newID);
		
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
		if (pContract->LoadContractFromString(THE_CONTRACT) && pContract->VerifyContract())
		{
			// Next make sure the wallet has this contract on its list...
			OTWallet * pWallet = NULL;
			
			if (NULL != (pWallet = m_pWallet))
			{
				pWallet->AddAssetContract(*pContract); // this saves both the contract and the wallet.
				pContract = NULL; // Success. The wallet "owns" it now, no need to clean it up.
			}
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
	OT_ASSERT_MSG(m_bInitialized, "Not initialized; call OT_API::Init first.");
	
	// -----------------------------------------------------------------
	
	OTServerContract * pServer = m_pWallet->GetServerContract(SERVER_ID);
	
	if (!pServer)
	{
		OTLog::Output(0, "That server contract is not available in the wallet.\n");
		
		return;
	}
	
	
	// -----------------------------------------------------
	
	OTPseudonym * pNym = m_pWallet->GetNymByID(USER_ID);
	
	if (NULL == pNym) // Wasn't already in the wallet.
	{
		OTLog::Output(0, "There's no User already loaded with that ID. Loading...\n");
		
		pNym = this->LoadPrivateNym(USER_ID);
		
		if (NULL == pNym) // LoadPrivateNym has plenty of error logging already.	
			return;
		
		m_pWallet->AddNym(*pNym);
	}
	
	// By this point, pNym is a good pointer, and is on the wallet.
	//  (No need to cleanup.)
	// -----------------------------------------------------
	
	OTAssetContract * pAssetContract = m_pWallet->GetAssetContract(ASSET_ID);
	
	if (!pAssetContract)
	{
		OTLog::Output(0, "Couldn't find any asset contract with that ID.\n");
		
		return;
	}
	
	// -----------------------------------------------------------------
	
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
	OT_ASSERT_MSG(m_bInitialized, "Not initialized; call OT_API::Init first.");
	
	// -----------------------------------------------------------------
	
	OTServerContract * pServer = m_pWallet->GetServerContract(SERVER_ID);
	
	if (!pServer)
	{
		OTLog::Output(0, "That server contract is not available in the wallet.\n");
		
		return;
	}
	
	
	// -----------------------------------------------------
	
	OTPseudonym * pNym = m_pWallet->GetNymByID(USER_ID);
	
	if (NULL == pNym) // Wasn't already in the wallet.
	{
		OTLog::Output(0, "There's no User already loaded with that ID. Loading...\n");
		
		pNym = this->LoadPrivateNym(USER_ID);
		
		if (NULL == pNym) // LoadPrivateNym has plenty of error logging already.	
			return;
		
		m_pWallet->AddNym(*pNym);
	}
	
	// By this point, pNym is a good pointer, and is on the wallet.
	//  (No need to cleanup.)
	// -----------------------------------------------------
	
	OTAssetContract * pAssetContract = m_pWallet->GetAssetContract(ASSET_ID);
	
	if (!pAssetContract)
	{
		OTLog::Output(0, "There's no Asset Contract already loaded with that ID.\n");
		
		return;
	}
	
	// -----------------------------------------------------------------
	
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





void OT_API::createAssetAccount(OTIdentifier & SERVER_ID,
								OTIdentifier & USER_ID,
								OTIdentifier & ASSET_ID)
{	
	OT_ASSERT_MSG(m_bInitialized, "Not initialized; call OT_API::Init first.");
	
	// -----------------------------------------------------
	
	OTWallet * pWallet = GetWallet();
	
	if (NULL == pWallet)
	{
		OTLog::Output(0, "The Wallet is not loaded.\n");
		return;
	}
	
	// By this point, pWallet is a good pointer.  (No need to cleanup.)
	
	// -----------------------------------------------------
	
	
	OTServerContract * pServer = pWallet->GetServerContract(SERVER_ID);
	
	if (!pServer)
	{
		OTLog::Output(0, "That server contract is not available in the wallet.\n");
		
		return;
	}
	
	// By this point, pServer is a good pointer.  (No need to cleanup.)
	
	// -----------------------------------------------------------------
	
	OTPseudonym * pNym = pWallet->GetNymByID(USER_ID);
	
	if (NULL == pNym) // Wasn't already in the wallet.
	{
		OTLog::Output(0, "There's no User already loaded with that ID. Loading...\n");
		
		pNym = this->LoadPrivateNym(USER_ID);
		
		if (NULL == pNym) // LoadPrivateNym has plenty of error logging already.	
		{
			return;
		}
		
		pWallet->AddNym(*pNym);
	}
	
	// By this point, pNym is a good pointer, and is on the wallet.
	//  (No need to cleanup.)
	// -----------------------------------------------------
	
	OTAssetContract * pAssetContract = pWallet->GetAssetContract(ASSET_ID);
	
	if (!pAssetContract)
	{
		OTLog::Output(0, "There's no Asset Contract already loaded with that ID.\n");
		
		return;
	}
	
	// -----------------------------------------------------------------
	
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
	OT_ASSERT_MSG(m_bInitialized, "Not initialized; call OT_API::Init first.");
	
	// -----------------------------------------------------
	
	OTWallet * pWallet = GetWallet();
	
	if (NULL == pWallet)
	{
		OTLog::Output(0, "The Wallet is not loaded.\n");
		return;
	}
	
	// By this point, pWallet is a good pointer.  (No need to cleanup.)
	
	// -----------------------------------------------------
	
	
	OTServerContract * pServer = pWallet->GetServerContract(SERVER_ID);
	
	if (!pServer)
	{
		OTLog::Output(0, "That server contract is not available in the wallet.\n");
		
		return;
	}
	
	// By this point, pServer is a good pointer.  (No need to cleanup.)
	
	// -----------------------------------------------------------------
	
	OTPseudonym * pNym = pWallet->GetNymByID(USER_ID);
	
	if (NULL == pNym) // Wasn't already in the wallet.
	{
		OTLog::Output(0, "There's no User already loaded with that ID. Loading...\n");
		
		pNym = this->LoadPrivateNym(USER_ID);
		
		if (NULL == pNym) // LoadPrivateNym has plenty of error logging already.	
		{
			return;
		}
		
		pWallet->AddNym(*pNym);
	}
	
	// By this point, pNym is a good pointer, and is on the wallet.
	//  (No need to cleanup.)
	// -----------------------------------------------------
    
	OTAccount * pAccount = pWallet->GetAccount(ACCOUNT_ID);
	
	if (NULL == pAccount)
	{
		OTLog::Output(0, "There is no account in the wallet with that ID.\n");
		
		return;
	}
	
	// -----------------------------------------------------------------
	
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





void OT_API::getAccount(OTIdentifier	& SERVER_ID,
						OTIdentifier	& USER_ID,
						OTIdentifier	& ACCT_ID)
{	
	OT_ASSERT_MSG(m_bInitialized, "Not initialized; call OT_API::Init first.");
	
	// -----------------------------------------------------------------
	
	OTServerContract * pServer = m_pWallet->GetServerContract(SERVER_ID);
	
	if (!pServer)
	{
		OTLog::Output(0, "That server contract is not available in the wallet.\n");
		
		return;
	}
	
	// -----------------------------------------------------
	
	OTPseudonym * pNym = m_pWallet->GetNymByID(USER_ID);
	
	if (NULL == pNym) // Wasn't already in the wallet.
	{
		OTLog::Output(0, "There's no User already loaded with that ID. Loading...\n");
		
		pNym = this->LoadPrivateNym(USER_ID);
		
		if (NULL == pNym) // LoadPrivateNym has plenty of error logging already.	
			return;
		
		m_pWallet->AddNym(*pNym);
	}
	
	// By this point, pNym is a good pointer, and is on the wallet.
	//  (No need to cleanup.)
	// -----------------------------------------------------
	
	OTAccount * pAccount = m_pWallet->GetAccount(ACCT_ID);
	
	if (NULL == pAccount)
	{
		OTLog::Output(0, "There is no account in the wallet with that ID.\n");
		
		return;
	}
	
	// -----------------------------------------------------------------
	
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
	OT_ASSERT_MSG(m_bInitialized, "Not initialized; call OT_API::Init first.");
	
	// -----------------------------------------------------------------
	
	OTServerContract * pServer = m_pWallet->GetServerContract(SERVER_ID);
	
	if (!pServer)
	{
		OTLog::Output(0, "That server contract is not available in the wallet.\n");
		
		return;
	}
	
	// -----------------------------------------------------
	
	OTPseudonym * pNym = m_pWallet->GetNymByID(USER_ID);
	
	if (NULL == pNym) // Wasn't already in the wallet.
	{
		OTLog::Output(0, "There's no User already loaded with that ID. Loading...\n");
		
		pNym = this->LoadPrivateNym(USER_ID);
		
		if (NULL == pNym) // LoadPrivateNym has plenty of error logging already.	
			return;
		
		m_pWallet->AddNym(*pNym);
	}
	
	// By this point, pNym is a good pointer, and is on the wallet.
	//  (No need to cleanup.)
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



void OT_API::checkUser(OTIdentifier & SERVER_ID,
					   OTIdentifier & USER_ID,
					   OTIdentifier & USER_ID_CHECK)
{	
	OT_ASSERT_MSG(m_bInitialized, "Not initialized; call OT_API::Init first.");
	
	// -----------------------------------------------------
	
	OTPseudonym * pNym = m_pWallet->GetNymByID(USER_ID);
	
	if (NULL == pNym) // Wasn't already in the wallet.
	{
		OTLog::Output(0, "There's no User already loaded with that ID. Loading...\n");
		
		pNym = this->LoadPrivateNym(USER_ID);
		
		if (NULL == pNym) // LoadPrivateNym has plenty of error logging already.	
			return;
		
		m_pWallet->AddNym(*pNym);
	}
	
	// By this point, pNym is a good pointer, and is on the wallet.
	//  (No need to cleanup.)
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
	// -----------------------------------------------------------------
	
	OTServerContract * pServer = m_pWallet->GetServerContract(SERVER_ID);
	
	if (!pServer)
	{
		OTLog::Output(0, "That server contract is not available in the wallet.\n");
		
		return;
	}
	
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
	OT_ASSERT_MSG(m_bInitialized, "Not initialized; call OT_API::Init first.");
	
	// -----------------------------------------------------
	
	OTPseudonym * pNym = m_pWallet->GetNymByID(USER_ID);
	
	if (NULL == pNym) // Wasn't already in the wallet.
	{
		OTLog::Output(0, "There's no User already loaded with that ID. Loading...\n");
		
		pNym = this->LoadPrivateNym(USER_ID);
		
		if (NULL == pNym) // LoadPrivateNym has plenty of error logging already.	
			return;
		
		m_pWallet->AddNym(*pNym);
	}
	
	// By this point, pNym is a good pointer, and is on the wallet.
	//  (No need to cleanup.)
	
	OTServerContract * pServer = m_pWallet->GetServerContract(SERVER_ID);
	
	if (!pServer)
	{
		OTLog::Output(0, "That server contract is not available in the wallet.\n");
		
		return;
	}
	
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
		OTLog::Output(0, "Failed setting public key.\n");
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
	{
		OTLog::Output(0, "Failed sealing envelope.\n");
	}	
}




void OT_API::createUserAccount(OTIdentifier	& SERVER_ID,
							   OTIdentifier	& USER_ID)
{	
	OT_ASSERT_MSG(m_bInitialized, "Not initialized; call OT_API::Init first.");
	
	// -----------------------------------------------------------------
	
	OTServerContract * pServer = m_pWallet->GetServerContract(SERVER_ID);
	
	if (!pServer)
	{
		OTLog::Output(0, "That server contract is not available in the wallet.\n");
		
		return;
	}
	
	
	// -----------------------------------------------------
	
	OTPseudonym * pNym = m_pWallet->GetNymByID(USER_ID);
	
	if (NULL == pNym) // Wasn't already in the wallet.
	{
		OTLog::Output(0, "There's no User already loaded with that ID. Loading...\n");
		
		pNym = this->LoadPrivateNym(USER_ID);
		
		if (NULL == pNym) // LoadPrivateNym has plenty of error logging already.	
			return;
		
		m_pWallet->AddNym(*pNym);
	}
	
	// By this point, pNym is a good pointer, and is on the wallet.
	//  (No need to cleanup.)
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
		OTLog::Error("Error processing createUserAccount command in OT_API::createUserAccount\n");
	
}

void OT_API::deleteUserAccount(OTIdentifier	& SERVER_ID,
							   OTIdentifier	& USER_ID)
{	
	OT_ASSERT_MSG(m_bInitialized, "Not initialized; call OT_API::Init first.");
	
	// -----------------------------------------------------------------
	
	OTServerContract * pServer = m_pWallet->GetServerContract(SERVER_ID);
	
	if (!pServer)
	{
		OTLog::Output(0, "That server contract is not available in the wallet.\n");
		
		return;
	}
	
	// -----------------------------------------------------
	
	OTPseudonym * pNym = m_pWallet->GetNymByID(USER_ID);
	
	if (NULL == pNym) // Wasn't already in the wallet.
	{
		OTLog::Output(0, "There's no User already loaded with that ID. Loading...\n");
		
		pNym = this->LoadPrivateNym(USER_ID);
		
		if (NULL == pNym) // LoadPrivateNym has plenty of error logging already.	
			return;
		
		m_pWallet->AddNym(*pNym);
	}
	
	// By this point, pNym is a good pointer, and is on the wallet.
	//  (No need to cleanup.)
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
	OT_ASSERT_MSG(m_bInitialized, "Not initialized; call OT_API::Init first.");
	
	// -----------------------------------------------------------------
	
	OTServerContract * pServer = m_pWallet->GetServerContract(SERVER_ID);
	
	if (!pServer)
	{
		OTLog::Output(0, "That server contract is not available in the wallet.\n");
		
		return;
	}
	
	
	// -----------------------------------------------------
	
	OTPseudonym * pNym = m_pWallet->GetNymByID(USER_ID);
	
	if (NULL == pNym) // Wasn't already in the wallet.
	{
		OTLog::Output(0, "There's no User already loaded with that ID. Loading...\n");
		
		pNym = this->LoadPrivateNym(USER_ID);
		
		if (NULL == pNym) // LoadPrivateNym has plenty of error logging already.	
			return;
		
		m_pWallet->AddNym(*pNym);
	}
	
	// By this point, pNym is a good pointer, and is on the wallet.
	//  (No need to cleanup.)
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



































