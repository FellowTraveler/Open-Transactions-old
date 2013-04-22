/*****************************************************************
 *    
 *  OpenTransactions.cpp  ( low-level api for OTLIB )
 *
 *		This file contains 2 classes:
 *
 *	OTSocket: This class helps with connecting to a ot server.
 *
 *	OT_API: This class provides functions for many core tasks
 *		using the otlib.
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


#include <ctime>
#include <cstdlib>

#include <string>
#include <iostream>
#include <fstream>

 // credit:stlplus library.
#include "containers/simple_ptr.hpp"

#ifdef _WIN32
#include <WinsockWrapper.h>
#endif

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
	
//#include "SSL-Example/SFSocket.h"
}

// ----------------------------------------------
#ifdef _WIN32
/*
 Minimum supported client    -- Windows XP
 Minimum supported server    -- Windows Server 2003
 Header                      -- WinBase.h (include Windows.h)
 Library                     -- Kernel32.lib
 DLL                         -- Kernel32.dll
 */
//#include <windows.h>  // I'm assuming the above WinsockWrapper inclusion already covers this.
// DWORD GetCurrentProcessId(void);
#else
// getpid
#include <sys/types.h>
#include <unistd.h>
//pid_t getpid(void);
//pid_t getppid(void);
#endif
// ----------------------------------------------

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include "simpleini/SimpleIni.h"

// ----------------------------

// TinyThread++
//
#include "tinythread.h"   // These are in the header already.
//#include "fast_mutex.h"

using namespace tthread;

// ----------------------------

#include <OTAPI.h>

#include "OTStorage.h"

#include "OTString.h"
#include "OTASCIIArmor.h"
#include "OTBasket.h"


#include "OpenTransactions.h"


#include "OTPseudonym.h"


#include "OTPassword.h"
#include "OTCrypto.h"
#include "OTClient.h"
#include "OTServerConnection.h"


#include "OTServerContract.h"
#include "OTMessage.h"
#include "OTWallet.h"
#include "OTSymmetricKey.h"
#include "OTCachedKey.h"
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
#include "OTOffer.h"
#include "OTTrade.h"
#include "OTMarket.h"
#include "OTKeyring.h"

#include "OTSmartContract.h"

#include "OTPayment.h"

#include "OTSettings.h"

#define CLIENT_CONFIG_KEY "client"
#define CLIENT_DATA_DIR "client_data"
#define CLIENT_LOGFILE_FILENAME "log-client.log"
#define CLIENT_MASTER_KEY_TIMEOUT_DEFAULT 300
#define CLIENT_WALLET_FILENAME "wallet.xml"
#define CLIENT_USE_SYSTEM_KEYRING false
#define CLIENT_PASSWORD_FOLDER ""
#define CLIENT_PID_FILENAME "ot.pid"


#define	DEFAULT_LATENCY_SEND_MS				200
#define	DEFAULT_LATENCY_SEND_NO_TRIES		7
#define	DEFAULT_LATENCY_RECEIVE_MS			200
#define	DEFAULT_LATENCY_RECEIVE_NO_TRIES	7
#define	DEFAULT_LATENCY_DELAY_AFTER			50
#define	DEFAULT_IS_BLOCKING					false

#define	KEY_LATENCY_SEND_MS					"latency_send_ms"
#define	KEY_LATENCY_SEND_NO_TRIES			"latency_send_no_tries"
#define	KEY_LATENCY_RECEIVE_MS				"latency_receive_ms"
#define	KEY_LATENCY_RECEIVE_NO_TRIES		"latency_receive_no_tries"
#define	KEY_LATENCY_DELAY_AFTER				"latency_delay_after"
#define	KEY_IS_BLOCKING						"is_blocking"



OTSocket::OTSocket()
  : m_pMutex(new tthread::mutex),
	m_pContext(NULL),
	m_pSocket(NULL),

	m_lLatencySendMs(DEFAULT_LATENCY_SEND_MS),
	m_nLatencySendNoTries(DEFAULT_LATENCY_SEND_NO_TRIES),
	m_lLatencyReceiveMs(DEFAULT_LATENCY_RECEIVE_MS),
	m_nLatencyReceiveNoTries(DEFAULT_LATENCY_RECEIVE_NO_TRIES),
	m_lLatencyDelayAfter(DEFAULT_LATENCY_DELAY_AFTER),
	m_bIsBlocking(DEFAULT_IS_BLOCKING),

	m_bInitialized(false),
	m_HasContext(false),
	m_bConnected(false),
	m_strConnectPath("")
{
}

OTSocket::~OTSocket()
{
	if (NULL != m_pSocket)  zmq_close(m_pSocket);
	if (NULL != m_pContext) zmq_term(m_pContext);

	if (NULL != m_pSocket)	delete m_pSocket;	m_pSocket	= NULL;
	if (NULL != m_pContext)	delete m_pContext;	m_pContext	= NULL;
	if (NULL != m_pMutex)	delete m_pMutex;	m_pMutex	= NULL;
}

const bool OTSocket::Init()
{
	if (m_bInitialized) return false;
	if (m_HasContext) return false;
	if (m_bConnected) return false;

	m_bInitialized =  true;
	return true;
}

const bool OTSocket::Init(
		const long	   & lLatencySendMs,
		const int	   & nLatencySendNoTries,
		const long	   & lLatencyReceiveMs,
		const int	   & nLatencyReceiveNoTries,
		const long	   & lLatencyDelayAfter,
		const bool	   & bIsBlocking
		)
{
	if (m_bInitialized) return false;
	if (m_HasContext) return false;
	if (m_bConnected) return false;

	m_lLatencySendMs		 = lLatencySendMs;
	m_nLatencySendNoTries	 = nLatencySendNoTries;
	m_lLatencyReceiveMs		 = lLatencyReceiveMs;
	m_nLatencyReceiveNoTries = nLatencyReceiveNoTries;
	m_lLatencyDelayAfter	 = lLatencyDelayAfter;
	m_bIsBlocking			 = bIsBlocking;

	m_bInitialized =  true;
	return true;
}

const bool OTSocket::Init(OTSettings * pSettings)
{
	if (m_bInitialized) return false;
	if (m_HasContext) return false;
	if (m_bConnected) return false;

	if (NULL == pSettings) { OT_ASSERT(false); return false; }

	bool bIsNew;
	{
		if(!pSettings->CheckSet_long("latency", KEY_LATENCY_SEND_MS,		m_lLatencySendMs,		m_lLatencySendMs,		bIsNew)) { OT_ASSERT(false); return false; }
	}
	{
		long lResult = 0;
		if(!pSettings->CheckSet_long("latency", KEY_LATENCY_SEND_NO_TRIES,	m_nLatencySendNoTries,	lResult,				bIsNew)) { OT_ASSERT(false); return false;  }
		m_nLatencySendNoTries = static_cast<int>(lResult);
	}
	{
		if(!pSettings->CheckSet_long("latency", KEY_LATENCY_RECEIVE_MS,		m_lLatencyReceiveMs,	m_lLatencyReceiveMs,	bIsNew)) { OT_ASSERT(false); return false;  }
	}
	{
		long lResult = 0;
		if(!pSettings->CheckSet_long("latency", KEY_LATENCY_RECEIVE_NO_TRIES, m_nLatencyReceiveNoTries, lResult,			bIsNew)) { OT_ASSERT(false); return false;  }
		m_nLatencyReceiveNoTries = static_cast<int>(lResult);
	}
	{
		if(!pSettings->CheckSet_long("latency", KEY_LATENCY_DELAY_AFTER,	m_lLatencyDelayAfter,	m_lLatencyDelayAfter,	bIsNew)) { OT_ASSERT(false); return false;  }
	}
	{
		if(!pSettings->CheckSet_bool("latency", KEY_IS_BLOCKING,			m_bIsBlocking,			m_bIsBlocking,			bIsNew)) { OT_ASSERT(false); return false;  }
	}

	m_bInitialized = true;

	return true;
}



const bool OTSocket::NewContext()
{
	if (!m_bInitialized) return false;

	m_HasContext = false;

	if (NULL != m_pSocket)  zmq_close(m_pSocket);
	if (NULL != m_pContext) zmq_term(m_pContext);

	if (NULL != m_pSocket)	delete m_pSocket;	m_pSocket	= NULL;
	if (NULL != m_pContext)	delete m_pContext;	m_pContext	= NULL;
	
	m_pContext = new zmq::context_t(1);

	m_HasContext = true;
	return true;
}

const bool OTSocket::Connect(const OTString & strConnectPath)
{
	OT_ASSERT(NULL != m_pContext);

	if (NULL != m_pSocket)  zmq_close(m_pSocket);
	if (NULL != m_pSocket)	delete m_pSocket;	m_pSocket	= NULL; // cleanup old socket (if we have one);

	if (!strConnectPath.Exists())		{ OTLog::vError("%s: Error: %s dosn't exist!\n", __FUNCTION__, "strConnectPath");	OT_ASSERT(false); return false;}
	if (5 > strConnectPath.GetLength()) { OTLog::vError("%s: Error: %s is too short!\n", __FUNCTION__, "strConnectPath");	OT_ASSERT(false); return false;}

	if (!m_bInitialized) return false;
	if (!m_HasContext) return false;

	m_bConnected = false;

	m_strConnectPath = strConnectPath;  // set the connection path.

	m_pSocket = new zmq::socket_t(*m_pContext, ZMQ_REQ);  // make a new socket

	OT_ASSERT_MSG(NULL != m_pSocket, "OTSocket::ConnectSocket: new zmq::socket(context, ZMQ_REQ)");

	const int linger = 0; // close immediately
	m_pSocket->setsockopt (ZMQ_LINGER, &linger, sizeof (linger));
    /*
     int zmq_setsockopt (void *socket, int option_name, const void *option_value, size_t option_len);
     
     Caution: All options, with the exception of ZMQ_SUBSCRIBE, ZMQ_UNSUBSCRIBE and ZMQ_LINGER, only take effect for subsequent socket bind/connects.     
     */

	if (!m_strConnectPath.Exists()) { OT_ASSERT(false); }
	m_pSocket->connect(m_strConnectPath.Get());
	m_bConnected = true;
	return true;
}



// The bool means true == try again soon, false == don't try again.
const bool OTSocket::HandlePollingError()
{
	bool bRetVal = false;
	
	switch (errno) {
			// At least one of the members of the items array refers to a socket whose associated ØMQ context was terminated.
		case ETERM:
			OTLog::Error("OTSocket::HandlePollingError: Failure: At least one of the members of the items array refers to a socket whose associated ØMQ context was terminated. (Deleting and re-creating the context.)\n");
			//this->NewContext();
			this->NewContext();
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
const bool OTSocket::HandleSendingError()
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
			OTLog::vOutput(0, "OTSocket::HandleSendingError: The zmq_send() operation cannot be performed on this socket at the moment due to the socket not being in the appropriate state. Deleting socket and re-trying...\n");
			this->Connect(m_strConnectPath);
			bRetVal = true;
			break;
			// The ØMQ context associated with the specified socket was terminated.
		case ETERM:
			OTLog::Error("OTSocket::HandleSendingError: The ØMQ context associated with the specified socket was terminated. (Deleting and re-creating the context and the socket, and trying again.)\n");
			this->NewContext();
			this->Connect(m_strConnectPath);
			bRetVal = true;			
			break;
			// The provided socket was invalid.
		case ENOTSOCK:
			OTLog::Error("OTSocket::HandleSendingError: The provided socket was invalid. (Deleting socket and re-trying...)\n");
			this->Connect(m_strConnectPath);
			bRetVal = true;			
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


const bool OTSocket::HandleReceivingError()
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
			OTLog::vOutput(0, "OTSocket::HandleReceivingError: The zmq_recv() operation cannot be performed on this socket at the moment due to the socket not being in the appropriate state. (Deleting socket and re-trying...)\n");
		{ OTASCIIArmor ascTemp(m_ascLastMsgSent); bRetVal = this->Send(ascTemp, m_strConnectPath); }
			break;
			// The ØMQ context associated with the specified socket was terminated.
		case ETERM:
			OTLog::Error("OTSocket::HandleReceivingError: The ØMQ context associated with the specified socket was terminated. (Re-creating the context, and trying again...)\n");
			this->NewContext();
		{ OTASCIIArmor ascTemp(m_ascLastMsgSent); bRetVal = this->Send(ascTemp, m_strConnectPath); }
			break;
			// The provided socket was invalid.
		case ENOTSOCK:
			OTLog::Error("OTSocket::HandleReceivingError: The provided socket was invalid. (Deleting socket and re-trying.)\n");
		{ OTASCIIArmor ascTemp(m_ascLastMsgSent); bRetVal = this->Send(ascTemp, m_strConnectPath); }
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


const bool OTSocket::Send(OTASCIIArmor & ascEnvelope, const OTString & strConnectPath)
{
	OT_ASSERT_MSG(ascEnvelope.GetLength() > 0, "ascEnvelope.GetLength() > 0");
	OT_ASSERT_MSG(NULL != m_pContext, "m_pContext == NULL in OTSocket::Send()");
	m_ascLastMsgSent.Set(ascEnvelope); // In case we need to re-send.

	// -----------------------------------
	if (m_strConnectPath.Compare(strConnectPath) && this->IsConnected())
	{
		// no need to reconnect.
	}
	else
	{
		this->Connect(strConnectPath); // connect
	}
	
	if (NULL == m_pSocket) // This should have been set in the Connect() call just above.
	{
		OTLog::Error("OTSocket::Send: Failed connecting socket.\n");
		return false;
	}

	if (!m_bInitialized) return false;
	if (!m_HasContext) return false;
	if (!m_bConnected) return false;

	// -----------------------------------	
	const long lLatencySendMilliSec	= m_lLatencySendMs;
	const long lLatencySendMicroSec	= lLatencySendMilliSec*1000; // Microsecond is 1000 times smaller than millisecond.
	
	zmq::message_t request(ascEnvelope.GetLength());
	memcpy((void*)request.data(), ascEnvelope.Get(), ascEnvelope.GetLength());
	
	bool bSuccessSending	= false;
	
	if (m_bIsBlocking)
	{
		bSuccessSending = m_pSocket->send(request); // Blocking.
	}
	else // not blocking
	{
		int		nSendTries	= m_nLatencySendNoTries;
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
				bSuccessSending = m_pSocket->send(request, ZMQ_NOBLOCK); // <=========== SEND ===============
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
	/*
	 Normally, we try to send...
	 If the send fails, we wait X ms and then try again (Y times).
	 
	 BUT -- what if the failure was an errno==EAGAIN ?
	 In that case, it's not a REAL failure, but rather, a "failure right now, try again in a sec."
	 */
	// ***********************************
	
	if (bSuccessSending)
		OTLog::SleepMilliseconds( m_lLatencyDelayAfter > 0 ? m_lLatencyDelayAfter : 1 );
	
	return bSuccessSending;
}
// -----------------------------------

const bool OTSocket::Receive(OTString & strServerReply)
{
	OT_ASSERT_MSG(NULL != m_pContext, "m_pContext == NULL in OTSocket::Receive()");
	OT_ASSERT_MSG(NULL != m_pSocket, "m_pSocket == NULL in OTSocket::Receive()");

	OT_ASSERT_MSG(true == m_bConnected, "true != m_bConnected in OTSocket::Receive()");

	// -----------------------------------	
	const long lLatencyRecvMilliSec	= m_lLatencyReceiveMs;
	const long lLatencyRecvMicroSec	= lLatencyRecvMilliSec*1000;
	
	if (!m_bInitialized) return false;
	if (!m_HasContext) return false;
	if (!m_bConnected) return false;

	// ***********************************
	//  Get the reply.
	zmq::message_t reply;
	
	bool bSuccessReceiving = false;
	
	// If failure receiving, re-tries 2 times, with 4000 ms max delay between each (Doubling every time.)
	//
	if (m_bIsBlocking)
	{
		bSuccessReceiving = m_pSocket->recv(&reply); // Blocking.
	}
	else	// not blocking
	{
		long	lDoubling = lLatencyRecvMicroSec;
		int		nReceiveTries = m_nLatencyReceiveNoTries;
		bool	expect_reply = true;
		while (expect_reply) 
		{
			//  Poll socket for a reply, with timeout
			zmq::pollitem_t items[] = { { *m_pSocket, 0, ZMQ_POLLIN, 0 } };
			
			const int nPoll = zmq::poll (&items[0], 1, lDoubling);
			lDoubling *= 2;
			
			//  If we got a reply, process it
			if (items[0].revents & ZMQ_POLLIN) 
			{
				bSuccessReceiving = m_pSocket->recv(&reply, ZMQ_NOBLOCK); // <=========== RECEIVE ===============
				OTLog::SleepMilliseconds( 1 );
				
				if (!bSuccessReceiving)
				{
					if (false == HandleReceivingError())
						expect_reply = false;
				}
				else
					break; // (Success -- we're done in this loop.)				
			}
			else if (nReceiveTries == 0) 
			{
				OTLog::Error("OTSocket::Receive: server seems to be offline, abandoning.\n");
				expect_reply = false;
				break;
			}
			else if ((-1) == nPoll) // error.
			{
				if (false == HandlePollingError())
					expect_reply = false;
			}
			
			--nReceiveTries;
		}
	}
	// ***********************************
	
	if (bSuccessReceiving && (reply.size() > 0))
		strServerReply.MemSet(static_cast<const char*>(reply.data()), static_cast<uint32_t> (reply.size()));

	return (bSuccessReceiving && (reply.size() > 0));
}



TransportCallback::TransportCallback(OT_API & refOT_API)
	: m_refOT_API(refOT_API)
	{
	}

TransportCallback::~TransportCallback()
	{
	}


// Transport Callback Main Operator
bool TransportCallback::operator() (OTServerContract& theserverContract,OTEnvelope& theEnvelope)
{
	if (this->m_refOT_API.IsInitialized())
		return this->m_refOT_API.TransportFunction(theserverContract,theEnvelope);
	else return false;
}



// static
bool OT_API::bInitOTApp = false;

// static
bool OT_API::bCleanupOTApp = false;

// ------------------------------------

// Call this once per run of the software. (enforced by a static value)
//
//static
bool OT_API::InitOTApp()
{
	OT_ASSERT(!OT_API::bCleanupOTApp);

	if (!OT_API::bInitOTApp)
	{
		if (!OTLog::Init("client")) { assert(false); }

		// ------------------------------------
		OTLog::vOutput(0, "\n\nWelcome to Open Transactions -- version %s\n", 
			OTLog::Version());

		OTLog::vOutput(1, "(transport build: OTMessage -> OTEnvelope -> ZMQ )\n");
		// ------------------------------------
#ifdef _WIN32
		WSADATA wsaData;
		WORD wVersionRequested = MAKEWORD( 2, 2 );
		int err = WSAStartup( wVersionRequested, &wsaData );

		/* Tell the user that we could not find a usable		*/
		/* Winsock DLL.											*/		

		OT_ASSERT_MSG((err == 0), "WSAStartup failed!\n");


		/*	Confirm that the WinSock DLL supports 2.2.			*/
		/*	Note that if the DLL supports versions greater		*/
		/*	than 2.2 in addition to 2.2, it will still return	*/
		/*	2.2 in wVersion since that is the version we		*/
		/*	requested.											*/

		bool bWinsock = (LOBYTE(wsaData.wVersion) != 2 || HIBYTE(wsaData.wVersion) != 2);

		/* Tell the user that we could not find a usable */
		/* WinSock DLL.                                  */

		if (!bWinsock) WSACleanup();  // do cleanup.
		OT_ASSERT_MSG((!bWinsock), "Could not find a usable version of Winsock.dll\n");

		/* The Winsock DLL is acceptable. Proceed to use it. */
		/* Add network programming using Winsock here */
		/* then call WSACleanup when done using the Winsock dll */
		OTLog::vOutput(1,"The Winsock 2.2 dll was found okay\n");
#endif
		// ------------------------------------
		// SIGNALS
		//
#if defined(OT_SIGNAL_HANDLING)
		//
		OTLog::SetupSignalHandler();  // <===== SIGNALS
		//
		// This is optional! You can always remove it using the OT_NO_SIGNAL_HANDLING
		//  option, and plus, the internals only execute once anyway. (It keeps count.)
#endif

		// ------------------------------------    
		OTCrypto::It()->Init(); // (OpenSSL gets initialized here.)
		// ------------------------------------
		// TODO in the case of Windows, figure err into this return val somehow.
		// (Or log it or something.)
		//

		OT_API::bInitOTApp = true;
		return true;
	}
	else
	{
		OTLog::vError("%s: ERROR: This function can only be called once.\n", __FUNCTION__);
		return false;
	}
}

// ------------------------------------


//static
bool OT_API::CleanupOTApp()
{
	if (!OT_API::bInitOTApp)
	{
		OTLog::vError("%s: WARNING: Never Successfully called:  %s\n", __FUNCTION__, "OT_API::InitCTX()");
		OT_API::bInitOTApp = true;
		return false;
	}

	if (!OT_API::bCleanupOTApp)
	{
		// ------------------------------------
		OTCachedKey::Cleanup(); // it has a static list of dynamically allocated master keys that need to be cleaned up, if the application is shutting down.
		// ------------------------------------

		// We clean these up in reverse order from the Init function, which just seems
		// like the best default, in absence of any brighter ideas.
		//
		OTCrypto::It()->Cleanup();  // (OpenSSL gets cleaned up here.)

		// ------------------------------------
#ifdef _WIN32
		WSACleanup(); // Corresponds to WSAStartup() in InitOTAPI().
#endif
		// ------------------------------------

		// NOTE: TODO: This shouldn't be here.
		// Why not? Because InitOTAPI corresponds to CleanupOTAPI.
		// But the PID init code is in OT_API::Init, NOT InitOTAPI. Therefore
		// the PID cleanup code should likewise be in OT_API::Cleanup, NOT CleanupOTAPI.
		// So then why is it here? Because OT_API::Cleanup doesn't exist yet...

		// Data Path
		OTString strDataPath;
		const bool bGetDataFolderSuccess = OTDataFolder::Get(strDataPath);
		if (bGetDataFolderSuccess)
		{

		}
		else 
		{
			OTLog::vError("%s: Unable to get data folder, will not remove pid (we likely didn't create one)", __FUNCTION__);
		}

		return true;
	}
	else
	{
		OTLog::vError("%s: ERROR: This function can only be called once.\n", __FUNCTION__);
		return false;
	}
}



// The API begins here...
OT_API::OT_API() :
	m_refPid(*new Pid()),
	m_pTransportCallback(NULL),
	m_pSocket(new OTSocket()),
	m_pWallet(NULL),
	m_pClient(NULL),
	m_bInitialized(false)
{

	m_strDataPath = "";
	m_strWalletFilename = "";
	m_strWalletFilePath = "";
	m_strConfigFilename = "";
	m_strConfigFilePath = "";

	if (!this->Init())
	{
		this->Cleanup();
	}
}



OT_API::~OT_API()
{
    // DELETE AND SET NULL
    //
	if (NULL != m_pSocket) delete m_pSocket; m_pSocket = NULL;

	if (NULL != m_pTransportCallback) delete m_pTransportCallback; m_pTransportCallback = NULL;
	if (NULL != m_pWallet) delete m_pWallet; m_pWallet = NULL;
	if (NULL != m_pClient) delete m_pClient; m_pClient = NULL;

	if (m_bInitialized) OT_ASSERT(this->Cleanup()); // we only cleanup if we need to

	// this must be last!
	if (NULL != &m_refPid) delete &m_refPid;
}


OT_API::Pid::Pid()
	: m_bIsPidOpen(false)
{
	m_strPidFilePath = "";
}

OT_API::Pid::~Pid()
{
	// nothing for now
}

void OT_API::Pid::OpenPid(const OTString strPidFilePath)
{
	if (this->IsPidOpen()) { OTLog::sError("%s: Pid is OPEN, MUST CLOSE BEFORE OPENING A NEW ONE!\n",__FUNCTION__,"strPidFilePath"); OT_ASSERT(false); }

	if (!strPidFilePath.Exists()) { OTLog::sError("%s: %s is Empty!\n",__FUNCTION__,"strPidFilePath"); OT_ASSERT(false); }
	if (3 > strPidFilePath.GetLength()) { OTLog::sError("%s: %s is Too Short! (%s)\n",__FUNCTION__,"strPidFilePath",strPidFilePath.Get()); OT_ASSERT(false); }

	OTLog::vOutput(1, "%s: Using Pid File: %s\n",__FUNCTION__,strPidFilePath.Get());
	this->m_strPidFilePath = strPidFilePath;

	{
		// 1. READ A FILE STORING THE PID. (It will already exist, if OT is already running.)
		//
		// We open it for reading first, to see if it already exists. If it does,
		// we read the number. 0 is fine, since we overwrite with 0 on shutdown. But
		// any OTHER number means OT is still running. Or it means it was killed while
		// running and didn't shut down properly, and that you need to delete the pid file
		// by hand before running OT again. (This is all for the purpose of preventing two
		// copies of OT running at the same time and corrupting the data folder.)
		//
		std::ifstream pid_infile(this->m_strPidFilePath.Get());

		// 2. (IF FILE EXISTS WITH ANY PID INSIDE, THEN DIE.)
		//
		if (pid_infile.is_open()) // it existed already
		{
			uint32_t old_pid = 0;
			pid_infile >> old_pid;
			pid_infile.close();

			// There was a real PID in there.
			if (old_pid != 0)
			{
				const unsigned long lPID = static_cast<unsigned long>(old_pid);
				OTLog::vError("\n\n\nIS OPEN-TRANSACTIONS ALREADY RUNNING?\n\n"
					"I found a PID (%lu) in the data lock file, located at: %s\n\n"
					"If the OT process with PID %lu is truly not running anymore, "
					"then just erase that file and restart.\n", lPID, this->m_strPidFilePath.Get(), lPID);
				this->m_bIsPidOpen = false;
				return;
			}
			// Otherwise, though the file existed, the PID within was 0.
			// (Meaning the previous instance of OT already set it to 0 as it was shutting down.)
		}
		// Next let's record our PID to the same file, so other copies of OT can't trample on US.

		// 3. GET THE CURRENT (ACTUAL) PROCESS ID.
		//
		uint32_t the_pid = 0;

#ifdef _WIN32        
		the_pid = static_cast<uint32_t>(GetCurrentProcessId());
#else
		the_pid = static_cast<uint32_t>(getpid());
#endif

		// 4. OPEN THE FILE IN WRITE MODE, AND SAVE THE PID TO IT.
		//
		std::ofstream pid_outfile(this->m_strPidFilePath.Get());

		if (pid_outfile.is_open())
		{
			pid_outfile << the_pid;
			pid_outfile.close();
			this->m_bIsPidOpen = true;
		}
		else
		{
			OTLog::vError("Failed trying to open data locking file (to store PID %lu): %s\n", the_pid, this->m_strPidFilePath.Get());
			this->m_bIsPidOpen = false;
		}
	}
}

void OT_API::Pid::ClosePid()
{
	if (!this->IsPidOpen()) { OTLog::sError("%s: Pid is CLOSED, WHY CLOSE A PID IF NONE IS OPEN!\n",__FUNCTION__,"strPidFilePath"); OT_ASSERT(false); }
	if (!this->m_strPidFilePath.Exists()) { OTLog::sError("%s: %s is Empty!\n",__FUNCTION__,"m_strPidFilePath"); OT_ASSERT(false); }

	// -------------------------------------------------------
	// PID -- Set it to 0 in the lock file so the next time we run OT, it knows there isn't
	// another copy already running (otherwise we might wind up with two copies trying to write
	// to the same data folder simultaneously, which could corrupt the data...)
	//

	uint32_t the_pid = 0;

	std::ofstream pid_outfile(this->m_strPidFilePath.Get());

	if (pid_outfile.is_open())
	{
		pid_outfile << the_pid;
		pid_outfile.close();
		m_bIsPidOpen = false;
	}
	else {
		OTLog::vError("Failed trying to open data locking file (to wipe PID back to 0): %s\n",this->m_strPidFilePath.Get());
		this->m_bIsPidOpen = true;
	}
}

const bool OT_API::Pid::IsPidOpen() const
{
	return this->m_bIsPidOpen;
}

// Call this once per INSTANCE of OT_API.
//
// Theoretically, someday OTAPI can be the "OT_CTX" and we will be able to instantiate
// multiple instances of it within a single application.
//
// So you use OT_API::InitOTAPI to initialize the entire application, and then you use
// OT_API::Init() to initialize THIS "OT_CTX" (the OT_API object.)
//
// If not initialized yet, but then this function is successful, it will return true.
// If ALREADY initialized, this function still returns true.
// If initialization fails, it will return false, but you can just call it again.
//
bool OT_API::Init()
{
    const char * szFunc = "OT_API::Init";
    // --------------------------------------
	if (true == this->m_bInitialized)
	{
		OTString strDataPath;
		bool bGetDataFolderSuccess = OTDataFolder::Get(strDataPath);
		OT_ASSERT_MSG(bGetDataFolderSuccess,"OT_API::Init(): Error! Data path not set!");

		OTLog::vError("%s: OTAPI was already initialized. (Skipping) and using path: %s\n", 
					  szFunc, strDataPath.Get());
		return true;
	}

	if (!OTDataFolder::Init(CLIENT_CONFIG_KEY)) { OTLog::vError("%s: Unable to Init data folders", __FUNCTION__); OT_ASSERT(false); }

    // --------------------------------------
	static bool bConstruct = false;
	
	if (false == bConstruct)
	{
		bConstruct = true;
		// ----------------------------
		m_pWallet = new OTWallet;
		m_pClient = new OTClient;
		// ----------------------------		
	}
    // --------------------------------------
	
	if (!this->LoadConfigFile()) { OTLog::vError("%s: Unable to Load Config File!", __FUNCTION__); OT_ASSERT(false); }

	// --------------------------------------
    // PID -- Make sure we're not running two copies of OT on the same data simultaneously here.
    //
	// we need to get the loacation of where the pid file should be.
	// then we pass it to the OpenPid function.
	OTString strDataPath = "";
    const bool bGetDataFolderSuccess = OTDataFolder::Get(strDataPath);

	OTString strPIDPath = "";
	OTPaths::AppendFile(strPIDPath,strDataPath,CLIENT_PID_FILENAME);

	if (bGetDataFolderSuccess) this->m_refPid.OpenPid(strPIDPath);
	if (!this->m_refPid.IsPidOpen()) { this->m_bInitialized = false; return false; }  // failed loading


    // --------------------------------------
	// This way, everywhere else I can use the default storage context (for now) and it will work
	// everywhere I put it. (Because it's now set up...)
	//
	this->m_bDefaultStore = OTDB::InitDefaultStorage(OTDB_DEFAULT_STORAGE, OTDB_DEFAULT_PACKER); // We only need to do this once now.
	
	if (this->m_bDefaultStore) // success initializing default storage on OTDB.
	{
		OTLog::vOutput(1, "%s: Success invoking OTDB::InitDefaultStorage", szFunc);
		
		if (this->m_bInitialized)
            OTLog::vOutput(1, "%s: m_pClient->InitClient() was already initialized. (Skipping.)\n", szFunc);
		else
        {
			this->m_bInitialized = this->m_pClient->InitClient(*this->m_pWallet);
			// -----------------------------
			if (this->m_bInitialized) OTLog::vOutput(1, "%s: Success invoking m_pClient->InitClient() \n", szFunc);
			else OTLog::vError("%s: Failed invoking m_pClient->InitClient()\n", szFunc);
		}
		return this->m_bInitialized;
	}
	else
        OTLog::vError("%s: Failed invoking OTDB::InitDefaultStorage\n", szFunc);
	// -------------------------------------
	return false;
}



bool OT_API::Cleanup()
{
	if (!this->m_refPid.IsPidOpen()) { return false; } // pid isn't open, just return false.

	this->m_refPid.ClosePid();
	if (this->m_refPid.IsPidOpen()) { OT_ASSERT(false); }  // failed loading
	return true;
}




	// Get
bool OT_API::GetWalletFilename(OTString & strPath) { if (m_strWalletFilename.Exists()) { strPath = m_strWalletFilename; return true; } else { strPath.Set(""); return false; } }

	// Set
bool OT_API::SetWalletFilename(const OTString & strPath) { if (strPath.Exists()) { m_strWalletFilename = strPath; return true; } else return false; }

bool OT_API::SetTransportCallback(TransportCallback * pTransportCallback)
{
	if (NULL != pTransportCallback) { this->m_pTransportCallback = pTransportCallback; return true; }
	else return false;
}

TransportCallback * OT_API::GetTransportCallback()
{
	if (NULL != this->m_pTransportCallback) { return this->m_pTransportCallback; }
	else { OT_ASSERT(false); return NULL; }
}

// Load the configuration file.
// 
bool OT_API::LoadConfigFile()
{
	const char * szFunc = "OT_API::LoadConfigFile()";

	// Setup Config File
	OTString strConfigPath, strConfigFilename;


	if(!OTDataFolder::IsInitialized()) { return false; }

	// Create Config Object (OTSettings)
	OTString strConfigFilePath="";
	if (!OTDataFolder::GetConfigFilePath(strConfigFilePath)) { OT_ASSERT(false); }
	OTSettings * p_Config = NULL;
	p_Config = new OTSettings(strConfigFilePath);

	// First Load, Create new fresh config file if failed loading.
	if (!p_Config -> Load())
	{
		OTLog::vOutput(0,"%s: Note: Unable to Load Config. Creating a new file: %s\n", szFunc, strConfigFilename.Get());
		if (!p_Config -> Reset()) return false;
		if (!p_Config -> Save()	) return false;
	}


	if (!p_Config -> Reset()) return false;

	// Second Load, Throw Assert if Failed loading.
	if (!p_Config -> Load())
	{
		OTLog::vError(0,"%s: Error: Unable to load config file: %s It should exist, as we just saved it!\n", szFunc, strConfigFilename.Get());
		OT_ASSERT(false);
	}


	// ---------------------------------------------
	// LOG LEVEL
	{
		bool bIsNewKey;
		long lValue;
		p_Config -> CheckSet_long("logging","log_level",0,lValue,bIsNewKey);
		OTLog::SetLogLevel(static_cast<int> (lValue));
	}

	// ---------------------------------------------
	// WALLET

	// WALLET FILENAME
	//
	// Clean and Set
	{
		bool bIsNewKey;
		OTString strValue;
		p_Config -> CheckSet_str("wallet","wallet_filename",CLIENT_WALLET_FILENAME,strValue,bIsNewKey);
		OT_API::SetWalletFilename(strValue);
		OTLog::vOutput(1,"Using Wallet: %s\n",strValue.Get());
	}

	// -----------------------------------
	// LATENCY
	{
		const char * szComment =
			";; LATENCY:\n\n"
			";; For sending and receiving:\n"
			";; blocking=true (usually not recommended) means OT will hang on the send/receive\n"
			";; call, and wait indefinitely until the send or receive has actually occurred.\n"
			";; IF BLOCKING IS FALSE (normal, default):\n"
			";; - no_tries is the number of times OT will try to send or receive a message.\n"
			";; - ms is the number of milliseconds it will wait between each attempt.\n"
			";; UPDATE: send_ms and receive_ms now DOUBLE after each failed attempt! (up to 3 tries)\n"
			";; Meaning that after 3 tries, it's already waited over 21 seconds trying to get\n"
			";; the message. \n"
			";; send_delay_after happens after EVERY SINGLE server request/reply, which can be\n"
			";; multiple times per use case. (They can add up quick...)\n";

		bool b_SectionExist;
		p_Config -> CheckSetSection("latency",szComment,b_SectionExist);
	}


	{
		if (NULL == m_pSocket) { OT_ASSERT(false); return false; }

		m_pSocket->Init(p_Config);  // setup the socket.
	}


	// ---------------------------------------------
	// SECURITY (beginnings of..)

	// Master Key Timeout
	{
	const char * szComment =
		"; master_key_timeout is how long the master key will be in memory until a thread wipes it out.\n"
		"; 0   : means you have to type your password EVERY time OT uses a private key. (Even multiple times in a single function.)\n"
		"; 300 : means you only have to type it once per 5 minutes.\n"
		"; -1  : means you only type it once PER RUN (popular for servers.)\n";

		bool bIsNewKey;
		long lValue;
	p_Config -> CheckSet_long("security","master_key_timeout",CLIENT_MASTER_KEY_TIMEOUT_DEFAULT,lValue,bIsNewKey,szComment);
	OTCachedKey::It()->SetTimeoutSeconds(static_cast<int>(lValue));
	}

	// Use System Keyring
	{
	bool bValue, bIsNewKey;
	p_Config -> CheckSet_bool("security","use_system_keyring",CLIENT_USE_SYSTEM_KEYRING,bValue,bIsNewKey);
	OTCachedKey::It()->UseSystemKeyring(bValue);
	}

	// Use System Keyring
	{
	bool bValue, bIsNewKey;
	p_Config -> CheckSet_bool("security","use_system_keyring",CLIENT_USE_SYSTEM_KEYRING,bValue,bIsNewKey);
	OTCachedKey::It()->UseSystemKeyring(bValue);
        
#if defined(OT_KEYRING_FLATFILE)
        // Is there a password folder? (There shouldn't be, but we allow it...)
        //
        if (bValue)
        {
            bool bIsNewKey2;
            OTString strValue;
            p_Config -> CheckSet_str("security","password_folder",CLIENT_PASSWORD_FOLDER,strValue,bIsNewKey2);
            if (strValue.Exists())
            {
                OTKeyring::FlatFile_SetPasswordFolder(strValue.Get());
                OTLog::vOutput(0," **DANGEROUS!**  Using password folder: %s\n",strValue.Get());
            }
        }
#endif
	}


	// Done Loading... Lets save any changes...
	if (!p_Config -> Save())
	{
		OTLog::vError("%s: Error! Unable to save updated Config!!!\n",szFunc);
		OT_ASSERT(false);
	}

	// Finsihed Saving... now lets cleanup!
	if (!p_Config -> Reset()) return false;

	if (NULL != p_Config) delete p_Config;
	p_Config = NULL;

	return true;
}

// ------------------------------------




bool OT_API::SetWallet(const OTString & strFilename) {

	if (!m_bInitialized) { OTLog::vError("%s: Not initialized; call OT_API::Init first.\n", __FUNCTION__); OT_ASSERT(false); return false; }

	{
		bool bExists = strFilename.Exists();
		if (bExists) { OTLog::vError("%s: strFilename dose not exist!\n", __FUNCTION__); OT_ASSERT(false); return false; }
	}

	OT_ASSERT_MSG(strFilename.Exists(),"OT_API::SetWalletFilename: strFilename does not exist.\n");
	OT_ASSERT_MSG((3 < strFilename.GetLength()),"OT_API::SetWalletFilename: strFilename is too short.\n");

	// Set New Wallet Filename
	OTLog::vOutput(0,"%s: Setting Wallet Filename... \n", __FUNCTION__);
	OTString strWalletFilename; OT_API::GetWalletFilename(strWalletFilename);

	if (strFilename.Compare(strWalletFilename)) 
	{
		OTLog::vOutput(1, "%s: Wallet Filename: %s  is same as in configuration. (skipping)\n",__FUNCTION__,strFilename.Get());
		return true;
	}
	else 
		strWalletFilename.Set(strWalletFilename);

	// Will save updated config filename.

	// Create Config Object (OTSettings)
	OTString strConfigFilePath;
	OTDataFolder::GetConfigFilePath(strConfigFilePath);
	OTSettings * p_Config(new OTSettings(strConfigFilePath));

	// First Load, Create new fresh config file if failed loading.
	if (!p_Config -> Load())
	{
		OTLog::vOutput(0,"%s: Note: Unable to Load Config. Creating a new file: %s\n", __FUNCTION__, strConfigFilePath.Get());
		if (!p_Config -> Reset()) return false;
		if (!p_Config -> Save()	) return false;
	}

	if (!p_Config -> Reset()) return false;

	// Second Load, Throw Assert if Failed loading.
	if (!p_Config -> Load())
	{
		OTLog::vError(0,"%s: Error: Unable to load config file: %s It should exist, as we just saved it!\n", __FUNCTION__, strConfigFilePath.Get());
		OT_ASSERT(false);
	}


	// ----------------------------------------------
	// Set New Wallet Filename
	{
		bool bNewOrUpdated; 
		p_Config -> Set_str("wallet","wallet_filename",strWalletFilename,bNewOrUpdated,"; Wallet updated\n");

		OT_API::SetWalletFilename(strWalletFilename);
	}


	// Done Loading... Lets save any changes...
	if (!p_Config -> Save())
	{
		OTLog::vError("%s: Error! Unable to save updated Config!!!\n",__FUNCTION__);
		OT_ASSERT(false);
	}

	// Finsihed Saving... now lets cleanup!
	if (!p_Config -> Reset()) return false;

	OTLog::vOutput(0,"%s: Updated Wallet filename: %s \n",__FUNCTION__,strWalletFilename.Get());

	return true;
}

bool OT_API::WalletExists()
{
	return (NULL != m_pWallet) ? true : false;
}

bool OT_API::LoadWallet()
{
	const char * szFunc = "OT_API::LoadWallet";
	
	OT_ASSERT_MSG(m_bInitialized, "Not initialized; call OT_API::Init first.\n");
	OT_ASSERT_MSG(m_bDefaultStore, "Default Storage not Initialized; call OT_API::Init first.\n");
    
	OTString strWalletFilename;
	bool bGetWalletFilenameSuccess = OT_API::GetWalletFilename(strWalletFilename);

	OT_ASSERT_MSG(bGetWalletFilenameSuccess, "OT_API::GetWalletFilename failed, wallet filename isn't set!");

	// Atempt Load
	OTLog::vOutput(2,"m_pWallet->LoadWallet() with: %s\n", strWalletFilename.Get());
	bool bSuccess = m_pWallet->LoadWallet(strWalletFilename.Get());

	if (bSuccess) OTLog::vOutput(2, "%s: Success invoking m_pWallet->LoadWallet() with filename: %s\n", 
							   szFunc, strWalletFilename.Get());
	else OTLog::vError("%s: Failed invoking m_pWallet->LoadWallet() with filename: %s\n", 
							  szFunc, strWalletFilename.Get());
	return bSuccess;
}




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


bool OT_API::TransportFunction(OTServerContract & theServerContract, OTEnvelope & theEnvelope)
{
	if (!this->IsInitialized())					{ OTLog::vError("%s: Error: %s is not Initialized!\n", __FUNCTION__, "OT_API");		OT_ASSERT(false); return false;}
	if (NULL == this->m_pClient)				{ OTLog::vError("%s: Error: %s is a NULL!\n", __FUNCTION__, "m_pClient");		OT_ASSERT(false); return false;}
	if (NULL == this->m_pClient->m_pConnection){ OTLog::vError("%s: Error: %s is a NULL!\n", __FUNCTION__, "m_pConnection");	OT_ASSERT(false); return false;}

	OTPseudonym * pNym(m_pClient -> m_pConnection -> GetNym());
	if (NULL == pNym)							{ OTLog::vError("%s: Error: %s is a NULL!\n", __FUNCTION__, "pNym");				OT_ASSERT(false); return false;}
	if (NULL == this->m_pSocket)				{ OTLog::vError("%s: Error: %s is a NULL!\n", __FUNCTION__, "m_Socket");			OT_ASSERT(false); return false;}
	if (NULL == this->m_pSocket->m_pMutex)		{ OTLog::vError("%s: Error: %s is a NULL!\n", __FUNCTION__, "m_Socket");			OT_ASSERT(false); return false;}
	if (!m_pSocket->IsInitialized())			{ OTLog::vError("%s: Error: %s is not Initialized!\n", __FUNCTION__, "m_Socket");	OT_ASSERT(false); return false;}



	tthread::lock_guard<tthread::mutex>  lock(*m_pSocket->m_pMutex);

	// ----------------------------------------------
	const char * szFunc = "OT_API::TransportCallback";
	// ----------------------------------------------
	int			nServerPort = 0;
	OTString	strServerHostname;



	if (false == theServerContract.GetConnectInfo(strServerHostname, nServerPort))
	{
		OTLog::vError("%s: Failed retrieving connection info from server contract.\n", szFunc);
		return false;
	}
	// ----------------------------------------------
	OTString strConnectPath;         
	strConnectPath.Format("tcp://%s:%d", strServerHostname.Get(), nServerPort);
	// --------------------------------------------

	OTASCIIArmor ascEnvelope(theEnvelope);

	if (ascEnvelope.Exists())
	{
		if (!m_pSocket->HasContext()) if(!m_pSocket->NewContext())
			return false;  // unable to make context. btw. should have been already made.

		// --------------------------------------------

		bool bSuccessSending = m_pSocket->Send(ascEnvelope, strConnectPath);  // <========

		if (!bSuccessSending)
		{
			OTLog::vError("%s: Failed, even with error correction and retries, "
				"while trying to send message to server.", szFunc);
		}
		else
		{
			OTString  strRawServerReply;
			bool	  bSuccessReceiving = m_pSocket->Receive(strRawServerReply); // <========

			if (!bSuccessReceiving || !strRawServerReply.Exists())
			{
				OTLog::vError("%s: Failed trying to receive expected reply from server.\n", szFunc);
			}					
			// ----------------------------------------------------------
			else
			{                
				OTASCIIArmor ascServerReply;
				const bool   bLoaded = strRawServerReply.Exists() && ascServerReply.LoadFromString(strRawServerReply);
				// -----------------------------
				OTString strServerReply;
				bool     bRetrievedReply = false;
				// -----------------------------
				if (!bLoaded)
					OTLog::vError("%s: Failed trying to load OTASCIIArmor object from string:\n\n%s\n\n",
					szFunc, strRawServerReply.Get());
				// ----------------------------------------------------------

				else if (strRawServerReply.Contains("ENVELOPE")) // Server sent this encrypted to my public key, in an armored envelope.
				{
					OTEnvelope  
						theServerEnvelope;
					if (theServerEnvelope.SetAsciiArmoredData(ascServerReply))
					{

						bRetrievedReply = theServerEnvelope.Open(*pNym, strServerReply);
					}
					else
					{
						OTLog::vError("%s: Failed: while setting OTASCIIArmor'd string into an OTEnvelope.\n", szFunc);
					}                    
				}
				// ----------------------------------------------------------
				// NOW ABLE TO HANDLE MESSAGES HERE IN ADDITION TO ENVELOPES!!!!
				// (Sometimes the server HAS to reply with an unencrypted reply,
				// and this is what makes it possible for the client to RECEIVE
				// that reply.)
				//
				// The Server doesn't have to accept both types, but the client does,
				// since technically all clients cannot talk to it without knowing its key first.
				//
				// ===> A CLIENT could POTENTIALLY have sent a message to server when unregistered, 
				// leaving server NO WAY to reply! Therefore server HAS to have the OPTION to send
				// an unencrypted message, in that case, and the client HAS to be able to receive it 
				// properly!!
				//
				// ----------------------------------------------------------

				else if (strRawServerReply.Contains("MESSAGE")) // Server sent this NOT encrypted, in an armored message.
				{
					bRetrievedReply = ascServerReply.GetString(strServerReply);
				}
				// ----------------------------------------------------------
				else
				{
					OTLog::vError("%s: Error: Unknown reply type received from server. (Expected envelope or message.)\n"
						"\n\n PERHAPS YOU ARE RUNNING AN OLD VERSION OF THE SERVER ????? \n\n", szFunc);
				}                    
				// **********************************************************************
				OTMessage * pServerReply(new OTMessage());
				OT_ASSERT(NULL != pServerReply);

				if (bRetrievedReply && strServerReply.Exists() && pServerReply->LoadContractFromString(strServerReply))
				{
					// Now the fully-loaded message object (from the server, this time) can be processed by the OT library...
					m_pClient -> ProcessServerReply(*pServerReply); // Client takes ownership and will handle cleanup.
				}
				else
				{
					if (NULL != pServerReply) delete pServerReply; pServerReply = NULL;  // cleanup

					OTLog::vError("%s: Error loading server reply from string:\n\n%s\n\n", 
						szFunc, strRawServerReply.Get());
				}
				// ----------------------------------------------------------
			} // !success receiving.
			// ----------------------------------------------------------
		} // else (bSuccessSending)
	} // if envelope exists.
	return true;

}

#endif  // (OT_ZMQ_MODE)
// -------------------------------------------------------------------------


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
	if (NYM_ID.IsEmpty()) { OTLog::vError("%s: NYM_ID is empty!", __FUNCTION__); OT_ASSERT(false); return NULL; }
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
			OTLog::vOutput(1, "OT_API::GetNym %s: No Nym found in wallet with ID: %s\n", 
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
			OTLog::vOutput(1, "OT_API::GetServer %s: No server contract found in wallet with ID: %s\n", 
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
			OTLog::vOutput(1, "OT_API::GetAssetType %s: No asset contract found in wallet with ID: %s\n", 
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
			OTLog::vOutput(1, "OT_API::GetAccount %s: No account found in wallet with ID: %s\n", 
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
// Adds to wallet. (No need to delete.)
//
OTPseudonym * OT_API::CreateNym(int nKeySize/*=1024*/,
                                const std::string str_id_source   /*=""*/,
                                const std::string str_alt_location/*=""*/)
{
    OT_ASSERT_MSG(m_bInitialized, "Not initialized; call OT_API::Init first.");
    const char * szFuncName = __FUNCTION__;
	// -----------------------------------------------------
    switch (nKeySize) 
    {
        case 1024:
        case 2048:
        case 4096:
        case 8192:
            break;            
        default:
            OTLog::vError("%s: Failure: nKeySize must be one of: "
                          "1024, 2048, 4096, 8192. (%d was passed...)\n",
                          szFuncName, nKeySize);
            return NULL;
    }
    // ---------------------------    
	OTWallet * pWallet = this->GetWallet(szFuncName); // This logs and ASSERTs already.
	if (NULL == pWallet) return NULL;
	// By this point, pWallet is a good pointer.  (No need to cleanup.)
	// -----------------------------------------------------
	OTPseudonym * pNym = new OTPseudonym;
	OT_ASSERT(NULL != pNym);	
    // ---------------------------    
	if (false == pNym->GenerateNym(nKeySize, true, str_id_source, str_alt_location))
	{
        OTLog::vError("%s: Failed trying to generate Nym.\n", szFuncName);
		delete pNym; pNym = NULL;
		return NULL;
	}
    // ---------------------------
    pWallet->AddNym(*pNym); // Add our new nym to the wallet, who "owns" it hereafter.

    // Note: It's already on the master key. To prevent that, we would have had
    // to PAUSE the master key before calling GenerateNym above. So the below call
    // is less about the Nym's encryption, and more about the wallet KNOWING. Because
    // OTWallet::ConvertNymToCachedKey is what adds this nym to the wallet's list of
    // "master key nyms". Until that happens, the wallet has no idea.
    //
    if (false == pWallet->ConvertNymToCachedKey(*pNym))
        OTLog::vError("%s: Error: Failed in pWallet->ConvertNymToCachedKey \n",
                      szFuncName);
	pWallet->SaveWallet(); // Since it just changed.
	// By this point, pNym is a good pointer, and is on the wallet.
	//  (No need to cleanup.)
    // ---------------------------
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
	const char * szFuncName = __FUNCTION__; //"OT_API::SetAssetType_Name";
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
	if (NYM_ID.IsEmpty()) { OTLog::vError("%s: NYM_ID is empty!", __FUNCTION__); OT_ASSERT(false); return false; }

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
/*
 CHANGE MASTER KEY and PASSWORD.
 
 Normally your passphrase is used to derive a key, which is used to unlock 
 a random number (a symmetric key), which is used as the passphrase to open the
 master key, which is used as the passphrase to any given Nym.
 
 Since all the Nyms are encrypted to the master key, and since we can change the
 passphrase on the master key without changing the master key itself, then we don't
 have to do anything to update all the Nyms, since that part hasn't changed.
 
 But we might want a separate "Change Master Key" function that replaces that key
 itself, in which case we'd HAVE to load up all the Nyms and re-save them.
 
*** UPDATE: Seems the easiest thing to do is to just change both the key and passphase
 at the same time here, by loading up all the private nyms, destroying the master key,
 and then saving all the private Nyms. (With master key never actually being "paused.")
 This will automatically cause it to generate a new master key during the saving process.
 (Make sure to save the wallet also.)
 */



/*
 
 // Done:
 
 Load up separate copies of all the Nyms.
 (Set them to destruct automatically on exit, no matter what.)
 
 Change them to temp PW.
 
 Re-generate master.
 
 Change them to new master.
 
 Save nyms, save wallet.
 
 Reload wallet.
 
 IF anything fails along the way, we just return. What happens? The temp
 Nyms we converted are destroyed, not saved, and were not the actual wallet
 copies anyway (which are still old.) The master key itself is reverted to
 its former form (I stored a copy of that) and the wallet file itself is
 never overwritten.
 Once we successfully convert everything, we save the Nyms and then re-load
 the wallet (and thus the nyms...) Now the updated Nyms are loaded up in the 
 wallet, and the temp ones just destruct when we exit the function. Perfect.
 
 */

// WARNING: This function, if successful, saves and re-loads the wallet.
// Therefore if you have any pointers to things inside the wallet, such as
// a pointer to a Nym, that pointer will be bad after you call this function.
// So make sure you grab a fresh pointer in such situations, after calling this.
// (Because the one you had before will crash you.)
//
const bool OT_API::Wallet_ChangePassphrase()
{
    // -----------------------------------------------------
	bool bInitialized = OTAPI_Wrap::OTAPI()->IsInitialized();
	if (!bInitialized) { OTLog::vError("%s: Not initialized; call OT_API::Init first.\n",__FUNCTION__);	OT_ASSERT(false); }
    // -----------------------------------------------------
	OTWallet * pWallet = OTAPI_Wrap::OTAPI()->GetWallet(__FUNCTION__); // This logs and ASSERTs already.
	if (NULL == pWallet) return false;
	// By this point, pWallet is a good pointer.  (No need to cleanup.)
	// -----------------------------------------------------
    class ot_change_pw
    {
        std::list<OTPseudonym *> * m_plist_nyms; // We'll be responsible in this class for cleaning these up.
        
    public:
        ot_change_pw(std::list<OTPseudonym *> & list_nyms) : m_plist_nyms(&list_nyms) { }
        ~ot_change_pw()
        {
            if (NULL != m_plist_nyms)
            {
                while (m_plist_nyms->size() > 0) // Here's the cleanup.
                {
                    std::list<OTPseudonym *>::iterator it = m_plist_nyms->begin();
                    OTPseudonym * pNym = *it;
                    OT_ASSERT(NULL != pNym);
                    
                    delete pNym; pNym = NULL;
                    m_plist_nyms->erase(it);
                }
            }
        }
    };
	// -----------------------------------------------------
    std::list<OTPseudonym *> list_nyms;  // Any Nyms on this list will be cleaned up automatically in the ot_change_pw destructor. Thus
    ot_change_pw the_cleanup(list_nyms); // we cannot add Nyms here that are also on the Wallet. We load our own copies just for this list.
    // -----------------------------------------------------
    bool bAtLeastOneNymHasCredentials = false;
    bool bSuccessLoading              = true; // defaults to true in case there aren't any Nyms.
    
    // Loop through all the private Nyms and get them all loaded up into a list.
    //
    const int nNymCount = pWallet->GetNymCount();
	// -----------------------------------------------------
    for (int iii = 0; iii < nNymCount; ++iii)
    {
        OTIdentifier NYM_ID;
        OTString     NYM_NAME;
        
        const bool bGotNym = pWallet->GetNym(iii, NYM_ID, NYM_NAME);
        OT_ASSERT(bGotNym);
        // ----------------------
        const OTString strNymID(NYM_ID);
        
        // otherwise it's a public Nym, so we just skip it.
        if (OTPseudonym::DoesCertfileExist(strNymID)) // is there a private key or credential available for this Nym?
        {   // In here, we know there's a private key...

            // CALLER responsible to delete!
            OTPseudonym * pNym = this->LoadPrivateNym(NYM_ID, false /*bChecking*/,  __FUNCTION__); // This also loads credentials, if there are any.
            
            // We use LoadPrivateNym here instead. (meaning: need to clean them up.)
            // Therefore use a nested class here to handle the cleanup.
            // This way we aren't changing the actual Nyms in the wallet until it's re-loaded.
            // Any failure between now and then, and it's not re-loaded, and none of the Nyms
            // were ever changed!
            
            if (NULL == pNym) // Since we KNOW there's a private key, yet it failed, therefore the user must have entered the wrong password...
            {
                bSuccessLoading = false;
                break;
            }
            // else... (add to list for cleanup, on exit from this function.)
            list_nyms.push_back(pNym); // ONLY private Nyms, and they ALL must successfully load and verify.
            
            if (pNym->GetMasterCredentialCount() > 0)
                bAtLeastOneNymHasCredentials = true;
        }
    }
    // ----------------------
    if (!bSuccessLoading)
    {
        OTLog::vError("%s: Error: Failed to load all the private Nyms. Wrong passphrase? (Aborting operation.)\n",
                      __FUNCTION__);
        return false;
    }
    // By this point we KNOW we have successfully loaded up ALL the private Nyms
    // for this wallet, and that list_nyms contains a pointer to each one...
    // ---------------------------------------------------------------------------
    // ENCRYPT ALL CREDENTIALS FROM MASTER KEY INTO A TEMP KEY
    //
    OTPassword     theTempPassword; // Used to store a temp password only. Only for credentialed nyms.
    OTPasswordData thePWData("Enter existing wallet master passphrase.");

    // At this point, for Nyms with credentials, we need to ReEncrypt the Nym's credentials,
    // similar to importing or exporting the Nym from the wallet. Except this time, we have
    // to ReEncrypt FROM a wallet-based Nym to a temporary passphrase, then destroy and re-
    // create the wallet's cached master key, then ReEncrypt AGAIN from the temporary passphrase
    // and back to the new master passphrase that was just generated.
    // Makes sense? It's the easiest way to do it based on the existing code we have.
    //    
    if (bAtLeastOneNymHasCredentials) // All the Nyms on our list are private, by this point. And within this block, they have credentials, too.
    {
        theTempPassword.randomizePassword(12); // the new random PW will be 12 bytes long. (We discard it after this function is done.)
        bool bSuccessReEncrypting = true;
        // ------------------------
        FOR_EACH(std::list<OTPseudonym *>, list_nyms)
        {
            OTPseudonym * pNym = *it;
            OT_ASSERT(NULL != pNym);
            // ------------------------
            // We know at least one Nym has credentials. Does this one?
            //
            if (pNym->GetMasterCredentialCount() > 0) // If this specific Nym has credentials...
            {
                // It won't ask for a passphrase when using the temp password, since it already
                // has the password. So it will only ask for a passphrase when it is NOT using
                // the temp password, e.g. when using the wallet's cached master key. ABOVE (here)
                // that will be the OLD master key, and BELOW (after the master key is re-created)
                // that will be the NEW master key.
                // That's why here, it says: "Enter your EXISTING wallet master passphrase."
                //
                const bool bExported = pNym->ReEncryptPrivateCredentials(false/* (EXPORTING) bImporting=FALSE */,
                                                                         &thePWData, &theTempPassword);
                if (!bExported)
                {
                    bSuccessReEncrypting = false; // At least this way if there's a failure, it's equally to all the Nyms, and not halfway through.
                }
            }
        } //FOR_EACH
        // ------------------------
        if (!bSuccessReEncrypting) // FAILURE
        {
            OTLog::vError("%s: Failed trying to re-encrypt Nym's private credentials.\n", __FUNCTION__);
            return false; // Nyms are cleaned up automatically when we return.
        }
        // ------------------------
    }
    // By this point, if there were credentials on any of the Nyms, they are all now converted
    // (in RAM, not in local storage) to the temp password, and OUT of the wallet's master key
    // (which we're about to destroy and re-create.)
	// ****************************************************************************
    // Destroy the wallet's cached master key (in Ram, not on disk--yet.)
    //
    OTASCIIArmor ascBackup;
    OTCachedKey::It()->SerializeTo(ascBackup);  // Just in case!
    OTCachedKey::It()->ResetMasterPassword();   // Which will force it to be re-created next time someone tries to use it...
    
    // NOTE: Below this point we cannot return without setting the master passphrase BACK.
	// -----------------------------------------------------
    // GENERATE the wallet's NEW MASTER KEY.
    //
    OTString  strReason("Choose a new passphrase: ");
    
    // This step would be unnecessary if we knew for a fact that at least
    // one Nym exists. But in the off-chance that there ARE NO NYMS in the 
    // wallet, we need to have this here, in order to MAKE SURE that the new
    // master key is generated. Otherwise it would never end up actually having
    // to generate the thing. (Since, if there are no Nyms to re-save, it would
    // never need to actually retrieve the master key, which is what triggers it
    // to generate if it's not already there.) So we just force that step here,
    // to make sure it happens, even if there are no Nyms to save below this point.
    //
    OTPassword temp_password;
    const bool bRegenerate = OTCachedKey::It()->GetMasterPassword(temp_password, strReason.Get(), true); //bVerifyTwice=false by default.
    // ----------------------------------------------------
    if (!bRegenerate) // Failure generating new master key.
    {
        OTLog::vError("%s: Error: Failed while trying to regenerate master key, in call: "
                      "OTCachedKey::It()->GetMasterPassword. (Setting it back to the old one.)\n", __FUNCTION__);
        // ------------------------
        if (false == OTCachedKey::It()->SerializeFrom(ascBackup))
            OTLog::vError("%s: Error: Failed while trying to restore master key, in call: "
                          "OTCachedKey::It()->GetMasterPassword. (While setting it back to the old one.)\n"
                          "Original value: \n%s\n", __FUNCTION__, ascBackup.Get()); // todo security: is it risky to have the key displayed in this log?
        // ------------------------
        return false;
        //
        // NOTE: Since we loaded our own copies of the Nyms, we haven't changed the copies in the wallet,
        // nor the wallet itself. So we can just return, since our copies of the Nyms will already be cleaned
        // up automatically.
    }
    // ----------------------------------------------------
    else// SUCCESS creating new master key, so let's CONVERT AND RE-SAVE ALL
    {   // THE NYMS, so they'll be using it from now on...

        // (Master key would normally be generated here, if we hadn't already forced it above,
        // but we did that to make sure it got re-created in the event there are zero nyms.)
        
        // Todo: save them to temp files and only copy over if everything
        // else is successful. Same with wallet. Also make backups.
        //
        bool bSuccessResaving = true; // in case the list is empty, we assume success here.
        
        FOR_EACH(std::list<OTPseudonym *>, list_nyms) // Let's save all these Nyms under the new master key.
        {
            OTPseudonym * pNym = *it;
            OT_ASSERT(NULL != pNym);
            // ------------------------
            bool bSaved = false;
            
            // CREDENTIALS
            if (pNym->GetMasterCredentialCount() > 0) // Nym has credentials.
            {
                // We had converted the Nyms to a temp key above, so now we need to convert
                // from the temp key to the new wallet key. Then we can save them and re-load
                // the wallet.
                //
                // We're supplying the temp password (from above), and importing the Nyms back
                // from that, back into to the wallet's new master key. So it will only ask
                // for a passphrase for the wallet, since the other passphrase is already provided.
                // Therefore thePWData is relevant to the wallet only.
                //
                bool  bSavedCredentials = false;
                const
                bool  bImported = pNym->ReEncryptPrivateCredentials(true/*bImporting*/,  // <==== CONVERT FROM TEMP PW TO NEW MASTER KEY.
                                                                    &thePWData, &theTempPassword);
                // --------------------------------------
                if (bImported) // Success? Okay, let's Save those credentials we just imported, to local storage.
                {
                    bSavedCredentials = true;
                    // --------------------------------------
                    OTString     strNymID, strCredList, strOutput;
                    mapOfStrings mapCredFiles;
                    
                    pNym->GetIdentifier(strNymID);
                    pNym->GetPrivateCredentials(strCredList, &mapCredFiles);
                    // --------------------------------------
                    OTString strFilename;
                    strFilename.Format("%s.cred", strNymID.Get());
                    // --------------------------------------                    
                    OTASCIIArmor ascArmor(strCredList);
                    if (ascArmor.Exists() &&
                        ascArmor.WriteArmoredString(strOutput, "CREDENTIAL LIST") && // bEscaped=false by default.
                        strOutput.Exists())
                    {
                        if (false == OTDB::StorePlainString(strOutput.Get(), OTFolders::Credential().Get(), strFilename.Get()))
                        {
                            OTLog::vError("%s: After converting credentials to new master key, failure trying to store private "
                                          "credential list for Nym: %s\n", __FUNCTION__, strNymID.Get());
                            bSavedCredentials = false;
                        }
                    }
                    // ----------------------------------------------------
                    // Here we do the actual credentials.
                    FOR_EACH(mapOfStrings, mapCredFiles)
                    {
                        std::string str_cred_id  = (*it).first;
                        OTString    strCredential((*it).second);
                        // ------------------------
                        strOutput.Release();
                        OTASCIIArmor ascLoopArmor(strCredential);
                        if (ascLoopArmor.Exists() &&
                            ascLoopArmor.WriteArmoredString(strOutput, "CREDENTIAL") && // bEscaped=false by default.
                            strOutput.Exists())
                        {
                            if (false == OTDB::StorePlainString(strOutput.Get(), OTFolders::Credential().Get(), strNymID.Get(), str_cred_id))
                            {
                                OTLog::vError("%s: After converting credentials to new master key, failure trying to store private "
                                              "credential for Nym: %s\n", __FUNCTION__, strNymID.Get());
                                bSavedCredentials = false;
                            }
                        }
                        // -------------------------
                    } // FOR_EACH
                    // ----------------------------------------------------
                }
                // ------------------------------------------
                bSaved = bImported && bSavedCredentials;
            } // If Nym has credentials. (Convert and save them, in the above block.)
            // ------------------------------------------
            else // Old-school: the old nyms (from before credentials code) merely need to have their cert saved (here), which process will automatically use the current (new) master key to encrypt the private portion of that cert when saving. So it gets converted and saved all in this one call. For new-style Nyms (with credentials) see the above block instead.
                //
                bSaved = pNym->Savex509CertAndPrivateKey(true, &strReason);
            // ------------------------------------------
            if (!bSaved) bSuccessResaving = false;
        } // FOR_EACH (list_nyms)
        // -----------------------------------------------------
        if (!bSuccessResaving) // Failed saving all the Nyms after switching their credentials over.
        {
            OTASCIIArmor ascBackup2;
            OTCachedKey::It()->SerializeTo(ascBackup2);  // Just in case!
            // ------------------------
            OTLog::vError("%s: ERROR: Failed re-saving Nym (into new Master Key.) It's possible "
                          "some Nyms are already saved on the new key, while others are still stuck "
                          "on the old key!! Therefore, asserting now. OLD KEY was:\n%s\n\n NEW KEY is: %s\n",
                          __FUNCTION__, ascBackup.Get(), ascBackup2.Get()); // Todo: security: keys are exposed here. Is this log safe?
            // ------------------------
            OT_ASSERT_MSG(false, "ASSERT while trying to change wallet's master key and passphrase.\n");
        }
        // -----------------------------------------------------
        else// SAVE THE WALLET.
        {
            // By this point, we have successfully converted all the Nyms (our local copies of the wallet's private nyms)
            // to the new master key, AND we have successfully saved those Nyms to local storage. Now, if we just save and
            // re-load the wallet itself, it should load up using the new master key, and it should load up its own copies
            // of those same Nyms again, using that new master key to decrypt them. (Those new copies of those Nyms being
            // the ones that we saved to local storage just above, using our local copies.)
            //
            // With the wallet updated thus, we can simply discard the local copies, which will have outlived their usefulness.
            // They will already be destroyed on exit, automatically.
            //
            bool  bLoaded = false;
            const
            bool  bSaved  = pWallet->SaveWallet();
            // ------------------------
            if (bSaved) // Next, re-load it so the Nyms we've changed will be loaded up in their new forms. (The nyms local to this function will be destroyed on exit, but they are separate from the nyms in the wallet, which will appear in their new forms upon loading, presuming the Nyms were successfully saved above.)
                //
                bLoaded = pWallet->LoadWallet();
            else
                OTLog::vError("%s: Failed saving wallet \n", __FUNCTION__);
            // ------------------------
            if (!bLoaded)
            {
                OTASCIIArmor ascBackup2;
                OTCachedKey::It()->SerializeTo(ascBackup2);  // Just in case!
                // ------------------------
                // Note: if we even got this far, that means we already saved the Nyms under the new master Key,
                // to local storage. Therefore we NEED that new key, if it wasn't properly saved in the wallet file
                // just now! (And we need to have made a real backup of the wallet before attempting this...todo.)
                // In the meantime, the best thing we can do is just LOG that key here, and hope the server operator
                // still has the log! Log both keys (new and old.)
                // ------------------------
                OTLog::vError("%s: ERROR: Failed saving or re-loading Wallet (with new Master Key.) "
                              "Asserting now. OLD KEY was:\n%s\n\n NEW KEY is: %s\n",
                              __FUNCTION__, ascBackup.Get(), ascBackup2.Get()); // Todo: security: keys are exposed here. Is this log safe?
                // ------------------------
                OT_ASSERT_MSG(false, "ASSERT while trying to save and re-load wallet with new master key and passphrase.\n");
            }
            else
                OTLog::vOutput(0, "\nSuccess changing master passphrase for wallet!\n");
            // ------------------------
            return bLoaded;
        }
        // -----------------------------------------------------
    }
    
    return false;
}



const bool OT_API::Wallet_CanRemoveServer(const OTIdentifier & SERVER_ID)
{
    // -----------------------------------------------------
	bool bInitialized = OTAPI_Wrap::OTAPI()->IsInitialized();
	if (!bInitialized) { OTLog::vError("%s: Not initialized; call OT_API::Init first.\n",__FUNCTION__);	OT_ASSERT(false); }

	if (SERVER_ID.IsEmpty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "SERVER_ID"			); OT_ASSERT(false); }
    // -----------------------------------------------------
	OTString strName;
	// ------------------------------------------
	const int nCount = OTAPI_Wrap::OTAPI()->GetAccountCount();
	
	// Loop through all the accounts.
	for (int i = 0; i < nCount; i++)
	{
		OTIdentifier accountID;

		OTAPI_Wrap::OTAPI()->GetAccount(i,accountID,strName);
		OTAccount * pAccount = OTAPI_Wrap::OTAPI()->GetAccount(accountID,__FUNCTION__);

		OTIdentifier purportedServerID(pAccount->GetPurportedServerID());

		if (SERVER_ID == purportedServerID) {
			OTString strPurportedServerID(purportedServerID), strSERVER_ID(SERVER_ID);
			OTLog::vOutput(0, "%s: Unable to remove server contract %s from wallet, because Account %s uses it.\n",
				__FUNCTION__, strSERVER_ID.Get(), strPurportedServerID.Get());
			return false;
		}
	}

    // ------------------------------------------
	const int nNymCount = OTAPI_Wrap::OTAPI()->GetNymCount();
    
    // Loop through all the Nyms. (One might be registered on that server.)
    //
    for (int i = 0; i < nNymCount; i++)
    {
		OTIdentifier nymID;
		bool bGetNym = OTAPI_Wrap::OTAPI()->GetNym(i, nymID, strName);

		if (OTAPI_Wrap::OTAPI()->IsNym_RegisteredAtServer(nymID, SERVER_ID))
		{
			OTString strNymID(nymID), strSERVER_ID(SERVER_ID);
            OTLog::vOutput(0, "%s: Unable to remove server contract %s from wallet, because Nym %s is registered there. (Delete that first...)\n",
				__FUNCTION__, strSERVER_ID.Get(), strNymID.Get());
			return false;
		}
   }
	return true;
}

	// Can I remove this asset contract from my wallet?
	//
	// You cannot remove the asset contract from your wallet if there are accounts in there using it.
	// This function tells you whether you can remove the asset contract or not.(Whether there are accounts...)
	//
const bool OT_API::Wallet_CanRemoveAssetType(const OTIdentifier & ASSET_ID)
{
    // -----------------------------------------------------
	bool bInitialized = OTAPI_Wrap::OTAPI()->IsInitialized();
	if (!bInitialized) { OTLog::vError("%s: Not initialized; call OT_API::Init first.\n",__FUNCTION__);	OT_ASSERT(false); }

	if (ASSET_ID.IsEmpty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ASSET_ID"			); OT_ASSERT(false); }
    // -----------------------------------------------------
	
	OTString strName;
	// ------------------------------------------
	const int nCount = OTAPI_Wrap::OTAPI()->GetAccountCount();
	
	// Loop through all the accounts.
	for (int i = 0; i < nCount; i++)
	{
		OTIdentifier accountID;

		OTAPI_Wrap::OTAPI()->GetAccount(i,accountID,strName);
		OTAccount * pAccount = OTAPI_Wrap::OTAPI()->GetAccount(accountID,__FUNCTION__);
		OTIdentifier theTYPE_ID(pAccount->GetAssetTypeID());

		if (ASSET_ID == theTYPE_ID)
        {
			OTString strASSET_ID(ASSET_ID), strTYPE_ID(theTYPE_ID);

            OTLog::vOutput(0, "%s: Unable to remove asset contract %s from wallet: Account %s uses it.\n",
				__FUNCTION__,strASSET_ID.Get(), strTYPE_ID.Get());
			return false;            
        }
	}
	return true;	
}

// Can I remove this Nym from my wallet?
//
// You cannot remove the Nym from your wallet if there are accounts in there using it.
// This function tells you whether you can remove the Nym or not. (Whether there are accounts...)
// It also checks to see if the Nym in question is registered at any servers.
//
// returns OT_BOOL
//
const bool OT_API::Wallet_CanRemoveNym(const OTIdentifier & NYM_ID) 
{	
    // -----------------------------------------------------
	bool bInitialized = OTAPI_Wrap::OTAPI()->IsInitialized();
	if (!bInitialized) { OTLog::vError("%s: Not initialized; call OT_API::Init first.\n",__FUNCTION__);	OT_ASSERT(false); }

	if (NYM_ID.IsEmpty())				{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "NYM_ID"				); OT_ASSERT(false); }
    // -----------------------------------------------------
	
	
	// -----------------------------------------------------
    OTPseudonym * pNym = OTAPI_Wrap::OTAPI()->GetNym(NYM_ID,__FUNCTION__);
    if (NULL == pNym) return false;
	// ------------------------------------------
	// Make sure the Nym doesn't have any accounts in the wallet. 
    // (Client must close those before calling this.)
    //
	const int nCount = OTAPI_Wrap::OTAPI()->GetAccountCount();
	
	// Loop through all the accounts.
	for (int i = 0; i < nCount; i++)
	{
		OTIdentifier accountID;
		OTString strName;

		OTAPI_Wrap::OTAPI()->GetAccount(i,accountID,strName);
		OTAccount * pAccount = OTAPI_Wrap::OTAPI()->GetAccount(accountID,__FUNCTION__);
		OTIdentifier theNYM_ID(pAccount->GetUserID());

		
		if (theNYM_ID.IsEmpty())
		{
			OTLog::vError("%s: Bug in OT_API_Wallet_CanRemoveNym / OT_API_GetAccountWallet_NymID\n", __FUNCTION__);
			return false;
		}
		
		
        // Looks like the Nym still has some accounts in this wallet.
		if (NYM_ID == theNYM_ID)
        {
            OTLog::vOutput(0, "%s: Nym cannot be removed because there are still accounts in the wallet for that Nym.\n", __FUNCTION__);
			return false;
        }
	}
	
    // ------------------------------------------
    // Make sure the Nym isn't registered at any servers...
    // (Client must unregister at those servers before calling this function..)
    //
    const int nServerCount = OTAPI_Wrap::OTAPI()->GetServerCount();
    
    for (int i = 0; i < nServerCount; i++)
    {
	OTIdentifier	theID;
	OTString		strName;
	bool bGetServer = OTAPI_Wrap::OTAPI()->GetServer(i, theID, strName);
        
	if (!theID.IsEmpty())
        {
            const OTString strServerID(theID);
            
            if (pNym->IsRegisteredAtServer(strServerID))
            {
                OTLog::vOutput(0, "%s: Nym cannot be removed because there are still servers in the wallet that the Nym is registered at.\n", __FUNCTION__);
                return false;
            }
        }
    }
    
    // ------------------------------------------

    // TODO:  Make sure Nym doesn't have any cash in any purses...

	return true;	
}

// Can I remove this Account from my wallet?
//
// You cannot remove the Account from your wallet if there are transactions still open.
// This function tells you whether you can remove the Account or not. (Whether there are transactions...)
// Also, balance must be zero to do this.
//
// returns OT_BOOL
//
const bool OT_API::Wallet_CanRemoveAccount(const OTIdentifier & ACCOUNT_ID)
{
    // -----------------------------------------------------
	bool bInitialized = OTAPI_Wrap::OTAPI()->IsInitialized();
	if (!bInitialized) { OTLog::vError("%s: Not initialized; call OT_API::Init first.\n",__FUNCTION__);	OT_ASSERT(false); }

	if (ACCOUNT_ID.IsEmpty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCOUNT_ID"			); OT_ASSERT(false); }
    // -----------------------------------------------------

	// -----------------------------------------------------------------
	const OTString strAccountID(ACCOUNT_ID);

	// -----------------------------------------------------
	OTAccount * pAccount = OTAPI_Wrap::OTAPI()->GetAccount(ACCOUNT_ID, __FUNCTION__);
	if (NULL == pAccount) return false;
	// -----------------------------------------------------
	// Balance must be zero in order to close an account!
	else if (pAccount->GetBalance() != 0)
	{
		OTLog::vOutput(0, "%s: Account balance MUST be zero in order to close an asset account: %s.\n", __FUNCTION__, strAccountID.Get());
		return false;
	}
	// -----------------------------------------------------------------
	bool BOOL_RETURN_VALUE = false;

	const OTIdentifier & theServerID	= pAccount->GetPurportedServerID();
	const OTIdentifier & theUserID		= pAccount->GetUserID();

	// There is an OT_ASSERT in here for memory failure,
	// but it still might return NULL if various verification fails.
	OTLedger * pInbox   = OTAPI_Wrap::OTAPI()->LoadInbox(theServerID, theUserID, ACCOUNT_ID); 
	OTLedger * pOutbox  = OTAPI_Wrap::OTAPI()->LoadOutbox(theServerID, theUserID, ACCOUNT_ID); 

	// Make sure it gets cleaned up pInbox this goes out of scope.
	OTCleanup<OTLedger>	theInboxAngel(pInbox); // I pass the pointer, in case it's NULL.
	OTCleanup<OTLedger>	theOutboxAngel(pOutbox); // I pass the pointer, in case it's NULL.

	if (NULL == pInbox){
		OTLog::vOutput(0, "%s: Failure calling OT_API::LoadInbox.\n Account ID: %s\n", __FUNCTION__, strAccountID.Get());
	}
	else if (NULL == pOutbox) {
		OTLog::vOutput(0, "%s: Failure calling OT_API::LoadOutbox.\n Account ID: %s\n",__FUNCTION__ , strAccountID.Get());
	}
	else if ( (pInbox->GetTransactionCount() > 0) || (pOutbox->GetTransactionCount() > 0) ) {
		OTLog::vOutput(0, "%s: Failure: You cannot remove an asset account if there are inbox/outbox items still waiting to be processed.\n", __FUNCTION__);
	}
	else BOOL_RETURN_VALUE = true; // SUCCESS!

	return BOOL_RETURN_VALUE;
}



// Remove this server contract from my wallet!
//
// Try to remove the server contract from the wallet.
// This will not work if there are any accounts in the wallet for the same server ID.
//
const bool OT_API::Wallet_RemoveServer(const OTIdentifier & SERVER_ID)
{
	// -----------------------------------------------------
	bool bInitialized = IsInitialized();
	if (!bInitialized) { OTLog::vError("%s: Not initialized; call OT_API::Init first.\n",__FUNCTION__);	OT_ASSERT(false); }

	if (SERVER_ID.IsEmpty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ASSET_ID"			); OT_ASSERT(false); }
	// -----------------------------------------------------

	// Make sure there aren't any dependent accounts..
	if (!Wallet_CanRemoveServer(SERVER_ID)) return false;

	// TODO: the above call proves that there are no accounts laying around
	// for this server ID. (No need to worry about "orphaned accounts.")
	//
	// However, there may still be Nyms registered at the server! Therefore,
	// we need to loop through the Nyms, and make sure none of them has been
	// registered at this server ID. If it has, then we need to message the server
	// to "deregister" the Nym, which is much cleaner.  Otherwise server's only
	// other alternative is to expire Nyms that have gone unused for some specific
	// period of time, presumably those terms are described in the server contract.
	//
	// -----------------------------------------------------

	if (NULL == m_pWallet) {
		OTLog::sError("%s:  No wallet found...\n",__FUNCTION__);
		OT_ASSERT(false);
	}

	if (m_pWallet->RemoveServerContract(SERVER_ID))
	{
		m_pWallet->SaveWallet();
		OTLog::sOutput(0, "%s: Removed server contract from the wallet: %s\n", __FUNCTION__, SERVER_ID);
		return true;
	}
	return false;
}


// Remove this asset contract from my wallet!
//
// Try to remove the asset contract from the wallet.
// This will not work if there are any accounts in the wallet for the same asset type ID.
//
const bool OT_API::Wallet_RemoveAssetType(const OTIdentifier & ASSET_ID)
{
    // -----------------------------------------------------
	bool bInitialized = IsInitialized();
	if (!bInitialized) { OTLog::vError("%s: Not initialized; call OT_API::Init first.\n",__FUNCTION__);	OT_ASSERT(false); }

	if (ASSET_ID.IsEmpty())			{ OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ASSET_ID"			); OT_ASSERT(false); }
    // -----------------------------------------------------

	// Make sure there aren't any dependent accounts..
	if (!Wallet_CanRemoveAssetType(ASSET_ID)) return false;


	if (NULL == m_pWallet) {
		OTLog::sError("%s: No wallet found...!\n",__FUNCTION__);
		OT_ASSERT(false);
	}

	if (m_pWallet -> RemoveAssetContract(ASSET_ID))
	{
		m_pWallet -> SaveWallet();
		OTLog::sOutput(0, "%s: Removed asset contract from the wallet: %s\n",__FUNCTION__, ASSET_ID);
		return true;
	}
	return false;
}


// Remove this Nym from my wallet!
//
// Try to remove the Nym from the wallet.
// This will not work if there are any nyms in the wallet for the same server ID.
//
const bool OT_API::Wallet_RemoveNym(const OTIdentifier & NYM_ID)
{
    // -----------------------------------------------------
	bool bInitialized = IsInitialized();
	if (!bInitialized)    { OTLog::vError("%s: Not initialized; call OT_API::Init first.\n",__FUNCTION__);	OT_ASSERT(false); }

	if (NYM_ID.IsEmpty()) { OTLog::vError("%s: Null: %s passed in!\n", __FUNCTION__, "ACCOUNT_ID"); OT_ASSERT(false); }
    // -----------------------------------------------------


	// DONE: The below call proves already that there are no accounts laying around
	// for this Nym. (No need to worry about "orphaned accounts.")
	//
	// DONE (finally):
	// However, the Nym might still be registered at various servers, even without asset accounts.
	// Therefore, we need to iterate through the server contracts, and if the Nym is registered at 
	// any of the servers, then "deregister" (before deleting the Nym entirely.) This is much
	// cleaner for the server side, who otherwise has to expired unused nyms based on some rule
	// presumably to be found in the server contract.
	// ------------------------------------------
	if (! Wallet_CanRemoveNym(NYM_ID)) return false;


	if (NULL == m_pWallet)
    {
		OTLog::sError("%s: No wallet found...!\n",__FUNCTION__);
		OT_ASSERT(false);
	}

	if (m_pWallet->RemoveNym(NYM_ID))
	{
		OTLog::sOutput(0, "%s: Success erasing Nym from wallet: %s\n", __FUNCTION__, NYM_ID);
		m_pWallet -> SaveWallet();
		return true;
	}
	else
		OTLog::sOutput(0, "%s: Failure erasing Nym from wallet: %s\n", __FUNCTION__, NYM_ID);

	return false;
}

// --------------------------------------------

// OT has the capability to export a Nym (normally stored in several files) as an encoded
// object (in base64-encoded form) and then import it again.
//
// Returns bool on success, and strOutput will contain the exported data.
//
const bool OT_API::Wallet_ExportNym(const OTIdentifier & NYM_ID, OTString & strOutput)
{
	if (NYM_ID.IsEmpty()) { OTLog::vError("%s: NYM_ID is empty!", __FUNCTION__); OT_ASSERT(false); return false; }
	// -----------------------------------------------------
    OTPasswordData thePWDataLoad("Enter wallet master passphrase.");
    OTPasswordData thePWDataSave("Create new passphrase for exported Nym.");
    OTString strReasonToSave(thePWDataSave.GetDisplayString());
	// -----------------------------------------------------
    OTPseudonym * pNym = this->GetOrLoadPrivateNym(NYM_ID, false, __FUNCTION__, &thePWDataLoad); // This logs and ASSERTs already.
    if (NULL == pNym) return false;
	// -----------------------------------------------------
    std::string  str_nym_name(pNym->GetNymName().Get());
	// -----------------------------------------------------    
    OTString strID; pNym->GetIdentifier(strID);
    std::string  str_nym_id(strID.Get());
	// -----------------------------------------------------    
    // Below this point I can use:
    //
    // pNym, str_nym_name, and str_nym_id.
    //
    // I still need the certfile and the nymfile (both in string form.)
    // -----------------------------------------------------
    //
    const bool bHasCredentials = (pNym->GetMasterCredentialCount() > 0);
    
    OTASCIIArmor ascCredentials, ascCredList;
    OTString     strCertfile;
    bool         bSavedCert = false;
    // -----------------------------------------------------
    if (!bHasCredentials)
    {
        // *****************************************************************
        if (false == OTCachedKey::It()->isPaused())
        {
            OTCachedKey::It()->Pause();
        }
        // -----------------------------------
        bSavedCert = pNym->Savex509CertAndPrivateKeyToString(strCertfile, &strReasonToSave);
        // -----------------------------------        
        if (OTCachedKey::It()->isPaused())
        {
            OTCachedKey::It()->Unpause();
        }
        // *****************************************************************
    }
    // -----------------------------------------------------    
    else
    {
        // We don't have to pause OTCachedKey here like we did above, because
        // this already has built-in mechanisms to go around OTCachedKey.
        //
        const bool bReEncrypted = pNym->ReEncryptPrivateCredentials(false/*bImporting*/, &thePWDataSave); // Handles OTCachedKey already.
        // -----------------------------
        if (bReEncrypted)
        {
            // -----------------------------
            // Create a new OTDB::StringMap object.
            //
            OTDB::Storable * pStorable = NULL;
            OTCleanup<OTDB::Storable> theAngel;
            OTDB::StringMap * pMap = NULL;
            // --------------------------------------------------------------
            pStorable = OTDB::CreateObject(OTDB::STORED_OBJ_STRING_MAP); // this asserts already, on failure.
            theAngel.SetCleanupTargetPointer(pStorable); // It will definitely be cleaned up.
            pMap = (NULL == pStorable) ? NULL : dynamic_cast<OTDB::StringMap *>(pStorable);
            // --------------------------------------------------------------
            if (NULL == pMap)
                OTLog::vError("%s: Error: failed trying to load or create a STORED_OBJ_STRING_MAP.\n",
                              __FUNCTION__);
            else // It instantiated.
            {    // -----------------------------------------------
                OTString       strCredList;
                mapOfStrings & theMap = pMap->the_map;
                
                pNym->GetPrivateCredentials(strCredList, &theMap);
                // -----------------------------------------------
                // Serialize the StringMap to a string...
                //
                if (strCredList.Exists() && (theMap.size() > 0)) // Won't bother if there are zero credentials somehow.
                {
                    std::string str_Encoded     = OTDB::EncodeObject(*pMap);
                    const bool bSuccessEncoding = (str_Encoded.size() > 0);
                    if (bSuccessEncoding)
                    {
                        ascCredList.SetString(strCredList);   // <========== Success
                        ascCredentials.Set(str_Encoded.c_str());  // Payload contains credentials list, payload2 contains actual credentials.
                        bSavedCert = true;
                    }
                }
            }
        } // bReEncrypted.
        // -----------------------------
    } // bHasCredentials==true
    // -----------------------------------------------------
    if (!bSavedCert)
    {
        OTLog::vError("%s: Failed while saving Nym's private cert, or private credentials, to string.\n"
                      "Reason I was doing this: \"%s\"\n", __FUNCTION__, thePWDataSave.GetDisplayString());
        return false;
    }
    // -----------------------------    
    OTString strNymfile;
    const bool bSavedNym = pNym->SavePseudonym(strNymfile);
    
    if (!bSavedNym)
    {
        OTLog::vError("%s: Failed while calling pNym->SavePseudonym(strNymfile) (to string)\n",
                      __FUNCTION__);
        return false;
    }
    // -----------------------------
    // Create an OTDB::StringMap object.
    //
    // Set the name, id, [certfile|credlist credentials], and nymfile onto it.  (Our exported
    // Nym appears as an ASCII-armored text to the naked eye, but when loaded up in code it
    // appears as a map of strings: name, id, [certfile|credlist credentials], and nymfile.)
    // 
    OTDB::Storable * pStorable = NULL;
    OTCleanup<OTDB::Storable> theAngel;
    OTDB::StringMap * pMap = NULL;
    // --------------------------------------------------------------
    pStorable = OTDB::CreateObject(OTDB::STORED_OBJ_STRING_MAP); // this asserts already, on failure.
    theAngel.SetCleanupTargetPointer(pStorable); // It will definitely be cleaned up.
    pMap = (NULL == pStorable) ? NULL : dynamic_cast<OTDB::StringMap *>(pStorable);
    // --------------------------------------------------------------
    // It exists.
    //
    if (NULL == pMap) 
    {
        OTLog::vError("%s: Error: failed trying to load or create a STORED_OBJ_STRING_MAP.\n", __FUNCTION__);
        return false;
    }
    // -----------------------------------------------
    mapOfStrings & theMap = pMap->the_map;
    // -----------------------------------------------
    theMap["id"]       = str_nym_id;
    theMap["name"]     = str_nym_name;
    theMap["nymfile"]  = strNymfile.Get();
    
    if (strCertfile.Exists())
        theMap["certfile"] = strCertfile.Get();
    
    if (ascCredList.Exists())
        theMap["credlist"] = ascCredList.Get();
    
    if (ascCredentials.Exists())
        theMap["credentials"] = ascCredentials.Get();
        // -----------------------------------------------
    // Serialize the StringMap to a string...
    //
    std::string str_Encoded = OTDB::EncodeObject(*pMap);
    bool bReturnVal   = (str_Encoded.size() > 0);
        
    if (bReturnVal)
    {
        OTASCIIArmor ascTemp;
        ascTemp.Set(str_Encoded.c_str());
        strOutput.Release();        
        bReturnVal = ascTemp.WriteArmoredString(strOutput, 
                                                "EXPORTED NYM" // -----BEGIN OT EXPORTED NYM-----
                                                ); // (bool bEscaped=false by default.)
    }

    return bReturnVal;
}



// OT has the capability to export a Nym (normally stored in several files) as an encoded
// object (in base64-encoded form) and then import it again.
//
// Returns bool on success, and if pNymID is passed in, will set it to the new NymID.
// Also on failure, if the Nym was already there with that ID, and if pNymID is passed,
// then it will be set to the ID that was already there.
//
const bool OT_API::Wallet_ImportNym(const OTString & FILE_CONTENTS, OTIdentifier * pNymID/*=NULL*/)
{
	// -----------------------------------------------------
	OTWallet * pWallet = GetWallet(__FUNCTION__); // This logs and ASSERTs already.
	if (NULL == pWallet) return false;
	// By this point, pWallet is a good pointer.  (No need to cleanup.)
	// -----------------------------------------------------
    OTASCIIArmor ascArmor;
    const bool bLoadedArmor = OTASCIIArmor::LoadFromString(ascArmor, FILE_CONTENTS); // str_bookend="-----BEGIN" by default
	// -----------------------------------------------------
    if (!bLoadedArmor || !ascArmor.Exists())
    {
        OTLog::vError("%s: Failure loading string into OTASCIIArmor object:\n\n%s\n\n",
                      __FUNCTION__, FILE_CONTENTS.Get());
        return false;
    }
	// -------------------------------------------------
    OTDB::Storable  * pStorable = OTDB::DecodeObject(OTDB::STORED_OBJ_STRING_MAP, ascArmor.Get());
    OTCleanup<OTDB::Storable> theStorableAngel(pStorable); // It will definitely be cleaned up.
    OTDB::StringMap * pMap = (NULL == pStorable) ? NULL : dynamic_cast<OTDB::StringMap *>(pStorable);
    
    if (NULL == pMap)
    {
        OTLog::vOutput(0, "%s: Failed decoding StringMap object while trying to import Nym:\n%s\n",
                       __FUNCTION__, FILE_CONTENTS.Get());
        return false;
    }
    // ----------------------------------------
    std::map<std::string, std::string> & theMap = pMap->the_map;
    // ---------------------------------------------------
    // By this point, there was definitely a StringMap encoded in the FILE_CONTENTS...
    //
    // Decode the FILE_CONTENTS into a StringMap object,
    // and if success, make sure it contains these values:
    //
    // id:       The NymID.
    // name:     The display name from the wallet.
    // certfile: The public / private certfile in openssl format.
    // nymfile:  The contents of the nymfile.
    //
    if (theMap.end() == theMap.find("id")) // todo hardcoding
    {
        // not found.
        OTLog::vOutput(0, "%s: Unable to find 'id' field while trying to import Nym:\n%s\n",
                       __FUNCTION__, FILE_CONTENTS.Get());
        return false;
    }
    if (theMap.end() == theMap.find("name")) // todo hardcoding
    {
        // not found.
        OTLog::vOutput(0, "%s: Unable to find 'name' field while trying to import Nym:\n%s\n",
                       __FUNCTION__, FILE_CONTENTS.Get());
        return false;
    }
    if (theMap.end() == theMap.find("nymfile")) // todo hardcoding
    {
        // not found.
        OTLog::vOutput(0, "%s: Unable to find 'nymfile' field while trying to import Nym:\n%s\n",
                       __FUNCTION__, FILE_CONTENTS.Get());
        return false;
    }
    // ------------------------------------------
    if ((theMap.end() == theMap.find("certfile")) && // todo hardcoding
        (theMap.end() == theMap.find("credlist")))   // Logic: No certfile AND no credlist? Gotta have one or the other.
    {
        // not found.
        OTLog::vOutput(0, "%s: Unable to find a 'certfile' nor a 'credlist' field while trying to import Nym:\n%s\n",
                       __FUNCTION__, FILE_CONTENTS.Get());
        return false;
    }
    // ---------------------------------------------------
    // Do various verifications on the values to make sure there's no funny business.
    //
    // If Nym with this ID is ALREADY in the wallet, set pNymID and return false.
	// -----------------------------------------------------
    const OTIdentifier theNymID  (theMap["id"  ].c_str());
    const OTString     strNymName(theMap["name"].c_str());
    
    if (NULL != pNymID)
        pNymID->SetString(theMap["id"].c_str());
	// -----------------------------------------------------
	if (theNymID.IsEmpty()) { OTLog::vError("%s: Error: NYM_ID passed in is empty; returning false", __FUNCTION__); return false; }
	// -----------------------------------------------------
    // MAKE SURE IT'S NOT ALREADY IN THE WALLET.
    //
	OTPseudonym * pNym = this->GetOrLoadPrivateNym(theNymID, true, __FUNCTION__); // This logs and ASSERTs already.
    
	if (NULL != pNym) // already there.
    {
        OTLog::vOutput(0, "%s: Tried to import a Nym that's already in wallet: %s\n",
                       __FUNCTION__, theMap["id"].c_str());
        return false;
    }
	// -----------------------------------------------------
    // Create a new Nym object.
    //
    const OTString strNymID(theNymID);
    pNym = new OTPseudonym(theNymID);
    OT_ASSERT(NULL != pNym);
    OTCleanup<OTPseudonym> theAngel(*pNym); // will be cleaned up automatically.

    pNym->SetNymName(strNymName);
    
    // *****************************************************************
    
    // The Nym being imported has its own password. We ask for that here,
    // so we can preserve it in an OTPassword object and pass it around to
    // everyone who needs it.
    //
    // This way OT doesn't automatically ask for it a billion times as it
    // goes through the process of loading and copying these various keys
    // (None of which utilize the wallet's built-in cached master key, since
    // this Nym is being imported and thus is external to the wallet until
    // that process is complete.)
    //
    OTString strDisplay("Enter passphrase for the Nym being imported.");
    
    // Circumvents the cached key.
    OTPassword * pExportPassphrase = OTSymmetricKey::GetPassphraseFromUser(&strDisplay, false); //bAskTwice is true when exporting (since the export passphrase is being created at that time.) But here during importing, we just ask once, since the passphrase is being used, not created.
    OTCleanup<OTPassword> thePasswordAngel(pExportPassphrase);
    
    if (NULL == pExportPassphrase)
    {
        OTLog::vError("%s: Failed in GetPassphraseFromUser.\n", __FUNCTION__);
        return false;
    }

    // *****************************************************************
    // Pause the master key, since this Nym is coming from outside
    // the wallet. We'll let it load with its own key. (No point using
    // the internal wallet master key here, since the Nym is coming from
    // outside, and doesn't use it anyway.)
    // This is true regardless of whether we load via the old system or
    // the new credentials system.
    //
    if (!(OTCachedKey::It()->isPaused()))
    {
        OTCachedKey::It()->Pause();   // BELOW THIS POINT, CACHED MASTER KEY IS DISABLED.
    }
    // *****************************************************************
    // Set the credentials or keys on the new Nym object based on the
    // certfile from the StringMap.
    //
    // -------------------------------------------------
    bool      bIfNymLoadKeys = false;
    OTString  strReasonToLoad("(ImportNym) To import this Nym, what is its passphrase? ");
    OTString  strReasonToSave("(ImportNym) What is your wallet's master passphrase? ");
    
    OTPasswordData thePWDataLoad(strReasonToLoad.Get());
    OTPasswordData thePWDataSave(strReasonToSave.Get());
    // ------------------------------------------------------------
    mapOfStrings::iterator it_credlist    = theMap.find("credlist");
    mapOfStrings::iterator it_credentials = theMap.find("credentials");
    bool bHasCredentials = false;
    // ------------------------------------------------------------
    // found "credlist"
    //
    if (theMap.end() != it_credlist) 
    {
        OTASCIIArmor ascCredList;
        OTString     strCredList;
        if (it_credlist->second.size() > 0)
        {
            ascCredList.Set(it_credlist->second.c_str());
            ascCredList.GetString(strCredList);
        }
        // ----------------------------------------------
        // cred list exists, and found "credentials"...
        //
        if (strCredList.Exists() && (theMap.end() != it_credentials)) // and found "credentials"
        {
            OTASCIIArmor ascCredentials;
            if (it_credentials->second.size() > 0)
            {
                ascCredentials.Set(it_credentials->second.c_str());
                // -------------------------------------------------
                OTDB::Storable  * pPrivateStorable = OTDB::DecodeObject(OTDB::STORED_OBJ_STRING_MAP, ascCredentials.Get());
                OTCleanup<OTDB::Storable> thePrivStorableAngel(pPrivateStorable); // It will definitely be cleaned up.
                OTDB::StringMap * pPrivateMap = (NULL == pPrivateStorable) ? NULL : dynamic_cast<OTDB::StringMap *>(pPrivateStorable);
                // -------------------------------------------------
                if (NULL == pPrivateMap)
                {
                    OTLog::vOutput(0, "%s: Failed decoding StringMap object.\n", __FUNCTION__);
                    return false;
                }
                else // IF the list saved, then we save the credentials themselves...
                {
                    mapOfStrings & thePrivateMap = pPrivateMap->the_map;
                    // ----------------------------------------
                    if (false == pNym->LoadFromString(strCredList,
                                                      &thePrivateMap,
                                                      &strReasonToLoad,
                                                      pExportPassphrase)) // <===========
                    {
                        OTLog::vError("%s: Failure loading nym %s from credential string.\n",
                                      __FUNCTION__, strNymID.Get());
                        return false;
                    }
                    else // Success
                    {
                        bIfNymLoadKeys  = true;   // <============
                        bHasCredentials = true;
                    }
                } // success decoding StringMap
            } // it_credentials.second().size() > 0
        } // strCredList.Exists() and it_credentials found.
    } // found "credlist"
    // ------------------------------------------------------------
    // found "certfile"
    else if (theMap.end() != theMap.find("certfile"))
    {
        const OTString strCert(theMap["certfile"]);
        bIfNymLoadKeys = pNym->Loadx509CertAndPrivateKeyFromString(strCert, &thePWDataLoad, pExportPassphrase); // <============
    }
    // *****************************************************************
    // Unpause the OTCachedKey (wallet master key.)
    // Now that we've loaded up the "outsider" using its own key,
    // we now resume normal wallet master key operations so that when
    // we save the Nym, it will be saved using the wallet master key.
    // (Henceforth, it has been "imported.")
    //
    if (OTCachedKey::It()->isPaused())
    {
        OTCachedKey::It()->Unpause();   // BELOW THIS POINT, CACHED MASTER KEY IS BACK IN EFFECT. (Disabled above.)
    }
    // *****************************************************************
    //
    if (bIfNymLoadKeys && pNym->VerifyPseudonym())
    {
        // Before we go on switching the credentials around, let's make sure this Nym we're
        // importing isn't already in the wallet.
        
        // -----------------------------
        if ( bHasCredentials &&
            !pNym->ReEncryptPrivateCredentials(true/*bImporting*/, &thePWDataLoad, pExportPassphrase)) // Handles OTCachedKey internally, no need for pausing for this call.
        {
            OTLog::vError("%s: Failed trying to re-encrypt Nym's private credentials.\n", __FUNCTION__);
            return false;
        }
        // -----------------------------
        // load Nymfile from string
        //
        const OTString strNymfile(theMap["nymfile"]);
        
              bool bConverted = false;
        const bool bLoaded    = (strNymfile.Exists() && pNym->LoadFromString(strNymfile));
//      const bool bLoaded    = (strNymfile.Exists() && pNym->LoadFromString(strNymfile, &thePrivateMap)); // Unnecessary, since pNym has already loaded with this private info, and it will stay loaded even through loading up the nymfile portion, which does not overwrite it. Furthermore, we have since transformed that data, re-encrypting it to a new key, and that's the important change that we're trying to save here! Therefore I don't want to re-introduce this (now old) version of the private info, therefore this is commented out.
        // -----------------------------
        // If success: Add to Wallet including name.
        //
        if (bLoaded)
        {
            pWallet->AddNym(*pNym); // Insert to wallet's list of Nyms.
            theAngel.SetCleanupTargetPointer(NULL); // Since adding to wallet, no need to cleanup, so we set this back to NULL.
            
            if (false == pWallet->ConvertNymToCachedKey(*pNym)) // This also calls SaveX509CertAndPrivateKey, FYI. (Or saves credentials, too, whichever is applicable.)
            {
                OTLog::vError("%s: Failed while calling pWallet->ConvertNymToCachedKey(*pNym)\n", __FUNCTION__);
                return false;
            }
            else
                bConverted = true;
        }
        else
        {
            OTLog::vError("%s: Failed loading nymfile from string.\n", __FUNCTION__);
            return false;
        }
        // ***********************************************************
        //
        if (bLoaded && bConverted) // bLoaded is probably superfluous here.
        {
            // ----------------------------
            // save the nymfile.
            //
            if (!pNym->SaveSignedNymfile(*pNym))
            {
                OTLog::vError("%s: Error: Failed calling SaveSignedNymfile.\n", __FUNCTION__);
                return false;
            }
            // ----------------------------
            // the conversion process adds values to the wallet, so we must save it after.
            if (!pWallet->SaveWallet())
            {
                OTLog::vError("%s: Error: Failed to save (updated) wallet.\n", __FUNCTION__);
                return false;
            }
            
            return true;   // <========= Success!
        }
        // ***********************************************************
    }
    else
        OTLog::vError("%s: Failed loading or verifying keys|credentials|pseudonym.\n", __FUNCTION__);
    // ----------------------
    return false;
}


// In this case, instead of importing a special "OT Nym all-in-one exported" file format,
// we are importing the public/private keys only, from their Cert file contents, and then
// creating a blank Nymfile to go along with it. This is for when people wish to import
// pre-existing keys to create a new Nym.
//
// Returns bool on success, and if pNymID is passed in, will set it to the new NymID.
// Also on failure, if the Nym was already there with that ID, and if pNymID is passed,
// then it will be set to the ID that was already there.
//

const bool OT_API::Wallet_ImportCert(const OTString & DISPLAY_NAME, const OTString & FILE_CONTENTS, OTIdentifier * pNymID/*=NULL*/)
{
	// -----------------------------------------------------
	OTWallet * pWallet = GetWallet(__FUNCTION__); // This logs and ASSERTs already.
	if (NULL == pWallet) return false;
	// By this point, pWallet is a good pointer.  (No need to cleanup.)
	// -----------------------------------------------------

    // Do various verifications on the values to make sure there's no funny business.
    //
    // If Nym with this ID is ALREADY in the wallet, set pNymID and return false.
	// -----------------------------------------------------
    // Create a new Nym object.
    //
    OTPseudonym * pNym = new OTPseudonym;
    OT_ASSERT(NULL != pNym);
    OTCleanup<OTPseudonym> theAngel(*pNym); // will be cleaned up automatically.
    
    if (DISPLAY_NAME.Exists())
       pNym->SetNymName(DISPLAY_NAME);
	// -----------------------------------------------------
    // Pause the master key, since this Nym is coming from outside
    // the wallet.
    //
    if (!(OTCachedKey::It()->isPaused()))
    {
        OTCachedKey::It()->Pause();
    }
    // ----------------------
    // Set the public and private keys on the new Nym object based on the
    // certfile from the StringMap.
    //
    OTPasswordData  thePWData("To import this Cert, what is its passphrase? ");
    const bool bIfNymLoadKeys = pNym->Loadx509CertAndPrivateKeyFromString(FILE_CONTENTS, &thePWData);
    // ----------------------
    // Unpause the master key. (This may go above the add to wallet, or it may stay here, with the "convert to master key" below.)
    //
    if (OTCachedKey::It()->isPaused())
    {
        OTCachedKey::It()->Unpause();
    }
    // ----------------------
    if (bIfNymLoadKeys && pNym->SetIdentifierByPubkey())
    {
        if (NULL != pNymID)
            *pNymID = pNym->GetConstID();
        // -----------------------------------------------------
        OTPseudonym * pTempNym = this->GetOrLoadPrivateNym(pNym->GetConstID(), false, __FUNCTION__); // This logs and ASSERTs already.
        
        if (NULL != pTempNym) // already there.
        {
            const OTString strNymID(pNym->GetConstID());
            OTLog::vOutput(0, "%s: Tried to import the Cert for a Nym that's already in wallet: %s\n",
                           __FUNCTION__, strNymID.Get());
            return false;
        }
        // -----------------------------------------------------        
        // If success: Add to Wallet including name.
        //
        pWallet->AddNym(*pNym); // Insert to wallet's list of Nyms.
        theAngel.SetCleanupTargetPointer(NULL); // In this case, no need to cleanup, so we set this back to NULL.
        
        const bool bConverted = pWallet->ConvertNymToCachedKey(*pNym);
        
        if (!bConverted)
        {
            OTLog::vError("%s: Failed while calling pWallet->ConvertNymToCachedKey(*pNym)\n", __FUNCTION__);
        }
        else
        {
            pNym->SaveSignedNymfile(*pNym);
            pWallet->SaveWallet();  // the conversion process adds values to the wallet, so we must save it after.
            return true;
        }
    }
    else
        OTLog::vError("%s: Failed loading or verifying key from cert string.\n", __FUNCTION__);
    // ----------------------
    return false;
}



// ----------------------------------------------------



const bool OT_API::Wallet_ExportCert(const OTIdentifier & NYM_ID, OTString & strOutput)
{
	if (NYM_ID.IsEmpty()) { OTLog::vError("%s: NYM_ID is empty!", __FUNCTION__); OT_ASSERT(false); return false; }
	// -----------------------------------------------------
    OTPasswordData thePWDataLoad("Need Wallet Master passphrase to export any Cert.");
    OTPasswordData thePWDataSave("Create new passphrase for exported Cert.");
    OTString strReasonToSave(thePWDataSave.GetDisplayString());
	// -----------------------------------------------------
    OTPseudonym * pNym = this->GetOrLoadPrivateNym(NYM_ID, false, __FUNCTION__, &thePWDataLoad); // This logs and ASSERTs already.
    if (NULL == pNym) return false;
	// -----------------------------------------------------    
    // Pause the master key before exporting, since we want to save this Nym
    // WITHOUT the master key, which it will no longer have, outside of this
    // wallet.
    //
    if (!(OTCachedKey::It()->isPaused()))
    {
        OTCachedKey::It()->Pause();
    }
    // ----------------------
    OTString strCertfile;
    const bool bSavedCert  = pNym->Savex509CertAndPrivateKeyToString(strCertfile, &strReasonToSave);
    // ----------------------
    // Unpause the master key.
    //
    if (OTCachedKey::It()->isPaused())
    {
        OTCachedKey::It()->Unpause();
    }
    // ----------------------
    if (!bSavedCert)
    {
        OTLog::vError("%s: Failed while calling pNym->Savex509CertAndPrivateKeyToString(strCertfile, \"%s\")\n",
                      __FUNCTION__, thePWDataSave.GetDisplayString());
        return false;
    }
    // -----------------------------
    if (strCertfile.Exists())
    {
        strOutput.Concatenate("%s", strCertfile.Get());
        return true;
    }
    // -----------------------------
    
    return false;
}


//bool  NumList::Peek(long & lPeek) const;
//bool  NumList::Pop();


bool OT_API::NumList_Add(OTNumList & theList, const OTNumList & theNewNumbers)
{
    OTNumList tempNewList(theList);
    
    const bool bSuccess = tempNewList.Add(theNewNumbers);
    
    if (bSuccess)
    {
        theList.Release();
        theList.Add(tempNewList);
        return true;
    }
    return false;
}

bool OT_API::NumList_Remove(OTNumList & theList, const OTNumList & theOldNumbers)
{
    OTNumList   tempNewList(theList), 
                tempOldList(theOldNumbers);
    
    while (tempOldList.Count() > 0)
    {
        long lPeek=0;
        
        if (!tempOldList.Peek(lPeek) || !tempOldList.Pop())
            OT_ASSERT(false);
        
        if (!tempNewList.Remove(lPeek))
            return false;
    }
    
    theList.Release();
    theList.Add(tempNewList);
    return true;
}


// Verifies the presence of theQueryNumbers on theList (as a subset)
//
bool OT_API::NumList_VerifyQuery(OTNumList & theList, const OTNumList & theQueryNumbers)
{
    OTNumList theTempQuery(theQueryNumbers);

    while (theTempQuery.Count() > 0)
    {
        long lPeek=0;
        
        if (!theTempQuery.Peek(lPeek) || !theTempQuery.Pop())
            OT_ASSERT(false);
        
        if (!theList.Verify(lPeek))
            return false;
    }
    
    return true;
}

// Verifies the COUNT and CONTENT (but not the order) matches EXACTLY.
//
bool OT_API::NumList_VerifyAll(OTNumList & theList, const OTNumList & theQueryNumbers)
{
    return theList.Verify(theQueryNumbers);
}

int OT_API::NumList_Count(OTNumList & theList)
{
    return theList.Count();
}

// --------------------------------------------------------------------
/** TIME (in seconds, as long)
 
 This will return the current time in seconds, as a long int.
 
 Todo:  consider making this available on the server side as well,
 so the smart contracts can see what time it is. 
 */
long OT_API::GetTime()
{
	const	
    time_t  CURRENT_TIME =	time(NULL);
    long	lTime = static_cast<long> (CURRENT_TIME);
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
	OTASCIIArmor    ascArmor;
	bool bSuccess = ascArmor.SetString(strPlaintext, bLineBreaks); // encodes.
	
	if (bSuccess)
	{
		strOutput.Release();        
        bSuccess = ascArmor.WriteArmoredString(strOutput, 
                                               "ENCODED TEXT" // -----BEGIN OT ENCODED TEXT-----
                                               ); // (bool bEscaped=false by default.)
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
    // -----------------------------------------------------
    OTASCIIArmor ascArmor;
    const bool bLoadedArmor = OTASCIIArmor::LoadFromString(ascArmor, strEncoded); // str_bookend="-----BEGIN" by default
	// -----------------------------------------------------
    if (!bLoadedArmor || !ascArmor.Exists())
    {
        OTLog::vError("%s: Failure loading string into OTASCIIArmor object:\n\n%s\n\n",
                      __FUNCTION__, strEncoded.Get());
        return false;
    }
	// -------------------------------------------------
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
    OTPasswordData thePWData(OT_PW_DISPLAY);
	OTPseudonym * pRecipientNym = this->GetOrLoadNym(theRecipientNymID, false, szFuncName, &thePWData); // This logs and ASSERTs already.
	if (NULL == pRecipientNym) return false;
	// -----------------------------------------------------
	OTEnvelope	    theEnvelope;
	bool bSuccess = theEnvelope.Seal(*pRecipientNym, strPlaintext);
    
	if (bSuccess) 
	{
		OTASCIIArmor ascCiphertext(theEnvelope);
		strOutput.Release();
        
        bSuccess = ascCiphertext.WriteArmoredString(strOutput, 
                                                    "ENCRYPTED TEXT" // -----BEGIN OT ENCRYPTED TEXT-----
                                                    ); // (bool bEscaped=false by default.)
	}
	return bSuccess;
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
	OTPseudonym * pRecipientNym = this->GetOrLoadPrivateNym(theRecipientNymID, false, __FUNCTION__); // This logs and ASSERTs already.
	if (NULL == pRecipientNym) return false;
	// -----------------------------------------------------	
	OTEnvelope		theEnvelope;
	OTASCIIArmor	ascCiphertext;
    // -----------------------------------------------------
    const bool bLoadedArmor = OTASCIIArmor::LoadFromString(ascCiphertext, strCiphertext); // str_bookend="-----BEGIN" by default
	// -----------------------------------------------------
    if (!bLoadedArmor || !ascCiphertext.Exists())
    {
        OTLog::vError("%s: Failure loading string into OTASCIIArmor object:\n\n%s\n\n",
                      __FUNCTION__, strCiphertext.Get());
        return false;
    }
	// -------------------------------------------------
	if (theEnvelope.SetAsciiArmoredData(ascCiphertext)) 
	{
		strOutput.Release();		
		return theEnvelope.Open(*pRecipientNym, strOutput);
	}
	return false;
}




// --------------------------------------------------------------------
/** OT-Sign a piece of flat text. (With no discernible bookends around it.)
 strContractType contains, for example, if you are trying to sign a ledger
 (which does not have any existing signatures on it) then you would pass
 LEDGER for strContractType, resulting in -----BEGIN OT SIGNED LEDGER-----
 */
bool OT_API::FlatSign(const OTIdentifier	&	theSignerNymID, 
                      const OTString		&	strInput,
                      const OTString		&	strContractType,
                      // ---------------------
                            OTString        &	strOutput)
{
	// -----------------------------------------------------
	OTPseudonym * pNym = this->GetOrLoadPrivateNym(theSignerNymID, false, __FUNCTION__); // This logs and ASSERTs already.
	if (NULL == pNym) return false;
	// By this point, pNym is a good pointer, and is on the wallet. (No need to cleanup.)
	// -----------------------------------------------------
	if (!strInput.Exists())
	{
		OTLog::vOutput(0, "%s: Empty contract passed in. (Returning false.)\n", __FUNCTION__);
		return false;
	}
	// ------------------------------------------------------------
	if (!strContractType.Exists())
	{
		OTLog::vOutput(0, "%s: Empty contract type passed in. (Returning false.)\n", __FUNCTION__);
		return false;
	}
	// ------------------------------------------------------------
    OTString strTemp(strInput);
    return OTContract::SignFlatText(strTemp, strContractType, *pNym, strOutput);
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
	// -----------------------------------------------------
	OTPseudonym * pNym = this->GetOrLoadPrivateNym(theSignerNymID, false, __FUNCTION__); // This logs and ASSERTs already.
	if (NULL == pNym) return false;
	// By this point, pNym is a good pointer, and is on the wallet. (No need to cleanup.)
	// -----------------------------------------------------
	if (!strContract.Exists())
	{
		OTLog::vOutput(0, "%s: Empty contract passed in. (Returning false.)\n", __FUNCTION__);
		return false;
	}
	// ------------------------------------------------------------
	//
	OTContract * pContract = NULL;
	
	if (NULL == pContract)
		pContract = OTTransactionType::TransactionFactory(strContract);
	
	if (NULL == pContract)
		pContract = OTScriptable::InstantiateScriptable(strContract);
	
	if (NULL == pContract)
		pContract = OTContract::InstantiateContract(strContract);
	
	if (NULL == pContract)
	{
		OTLog::vOutput(0, "%s: I tried my best. "
                       "Unable to instantiate contract passed in:\n\n%s\n\n",
					   __FUNCTION__, strContract.Get());
		return false;
	}
	
	OTCleanup<OTContract> theAngel(*pContract);

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
	// -----------------------------------------------------
	OTPseudonym * pNym = this->GetOrLoadPrivateNym(theSignerNymID, false, __FUNCTION__); // This logs and ASSERTs already.
	if (NULL == pNym) return false;
	// By this point, pNym is a good pointer, and is on the wallet. (No need to cleanup.)
	// -----------------------------------------------------
	if (!strContract.Exists())
	{
		OTLog::vOutput(0, "%s: Empty contract passed in. (Returning false.)\n", __FUNCTION__);
		return false;
	}
	// ------------------------------------------------------------
	//
	OTContract * pContract = NULL;
	
	if (NULL == pContract)
		pContract = OTTransactionType::TransactionFactory(strContract);
	
	if (NULL == pContract)
		pContract = OTScriptable::InstantiateScriptable(strContract);
	
	if (NULL == pContract)
		pContract = OTContract::InstantiateContract(strContract);
	
	if (NULL == pContract)
	{
		OTLog::vOutput(0, "%s: I tried my best. Unable to instantiate contract passed in:\n\n%s\n\n",
					   __FUNCTION__, strContract.Get());
		return false;
	}
	
	OTCleanup<OTContract> theAngel(*pContract);

	// -----------------------------------------------------
//	pContract->ReleaseSignatures();		// Other than this line, this function is identical to 
										// OT_API::SignContract(). (This one adds signatures without removing existing ones.)
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
	// -----------------------------------------------------
    OTPasswordData thePWData(OT_PW_DISPLAY);
	OTPseudonym * pNym = this->GetOrLoadNym(theSignerNymID, false, __FUNCTION__, &thePWData); // This logs and ASSERTs already.
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
//	if (false == pContract->VerifyContractID())
////	if (false == pContract->VerifyContract())	// This calls VerifyContractID(), then GetContractPublicNym(), then VerifySignature() (with that Nym)
//	{											// Therefore it's only useful for server contracts and asset contracts. Here we can VerifyID and Signature,
//												// and that's good enough for here and most other places, generically speaking.
//		OTLog::vOutput(0, "OT_API::VerifySignature: Unable to verify contract ID for contract passed in. NOTE: If you are experiencing "
//					   "a problem here, CONTACT FELLOW TRAVELER and let him know WHAT KIND OF CONTRACT, and what symptoms you are seeing, "
//					   "versus what you were expecting to see. Contract contents:\n\n%s\n\n",
//					   strContract.Get());
//		return false;
//	}

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
	// -----------------------------------------------------
	OTPseudonym * pNym = this->GetOrLoadPrivateNym(USER_ID, false, __FUNCTION__); // These copiously log, and ASSERT.
	if (NULL == pNym) return false;
	// By this point, pNym is a good pointer, and is on the wallet. (No need to cleanup.)
	// -----------------------------------------------------
	OTServerContract *	pServer = this->GetServer(SERVER_ID, __FUNCTION__); // This ASSERTs and logs already.
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






bool OT_API::Create_SmartContract(const OTIdentifier & SIGNER_NYM_ID,// Use any Nym you wish here. (The signing at this point is only to cause a save.)
								  // ----------------------------------------
								  time_t		VALID_FROM,	// Default (0 or NULL) == NOW
								  time_t		VALID_TO,	// Default (0 or NULL) == no expiry / cancel anytime
								  OTString & strOutput)
{
	// -----------------------------------------------------
	OTPseudonym * pNym = this->GetOrLoadPrivateNym(SIGNER_NYM_ID, false, __FUNCTION__); // These copiously log, and ASSERT.
	if (NULL == pNym) return false;
	// By this point, pNym is a good pointer, and is on the wallet. (No need to cleanup.)
	// -----------------------------------------------------
	OTSmartContract * pContract = new OTSmartContract();
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
	// -----------------------------------------------------
	OTPseudonym * pNym = this->GetOrLoadPrivateNym(SIGNER_NYM_ID, false, __FUNCTION__); // These copiously log, and ASSERT.
	if (NULL == pNym) return false;
	// By this point, pNym is a good pointer, and is on the wallet. (No need to cleanup.)
	// -----------------------------------------------------	
	OTScriptable * pContract = OTScriptable::InstantiateScriptable(THE_CONTRACT);
	OTCleanup<OTScriptable> theContractAngel;
	if (NULL == pContract)
	{
		OTLog::vOutput(0, "%s: Error loading smart contract:\n\n%s\n\n",
					   __FUNCTION__, THE_CONTRACT.Get());
		return false;
	}
	else
		theContractAngel.SetCleanupTarget(*pContract);  // Auto-cleanup.
	// -----------------------------------------------------
	const std::string str_party_name(PARTY_NAME.Get()), str_agent_name(AGENT_NAME.Get());
	
	OTParty * pParty = pContract->GetParty(str_party_name);
	
	if (NULL != pParty)
	{
		OTLog::vOutput(0, "%s: Failure: Party already exists. \n", __FUNCTION__);
		return false;
	}
	// -------------------------------

	pParty = new OTParty(str_party_name.c_str(), true /*bIsOwnerNym*/, 
						 NULL/*OwnerID not set until confirm*/, str_agent_name.c_str(),
						 true); //bCreateAgent=false by default.
	OT_ASSERT(NULL != pParty);
	
	if (false == pContract->AddParty(*pParty)) // takes ownership.
	{
		OTLog::vOutput(0, "%s: Failed while trying to add party: %s \n",
					   __FUNCTION__, PARTY_NAME.Get());
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
	// -----------------------------------------------------
	OTPseudonym * pNym = this->GetOrLoadPrivateNym(SIGNER_NYM_ID, false, __FUNCTION__); // These copiously log, and ASSERT.
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
	// -----------------------------------------------------
	OTPseudonym * pNym = this->GetOrLoadPrivateNym(SIGNER_NYM_ID, false, __FUNCTION__); // These copiously log, and ASSERT.
	if (NULL == pNym) return false;
	// By this point, pNym is a good pointer, and is on the wallet. (No need to cleanup.)
	// -----------------------------------------------------
	const OTIdentifier theAcctID(ACCT_ID);
	OTAccount * pAccount = this->GetAccount(theAcctID, __FUNCTION__);
	if (NULL == pAccount) return false;
	// By this point, pAccount is a good pointer, and is on the wallet. (No need to cleanup.)
	// -----------------------------------------------------			
	OTScriptable * pScriptable = OTScriptable::InstantiateScriptable(THE_CONTRACT);
	OTCleanup<OTScriptable> theContractAngel;
	if (NULL == pScriptable)
	{
		OTLog::vOutput(0, "%s: Error loading smart contract:\n\n%s\n\n",
                       __FUNCTION__, THE_CONTRACT.Get());
		return false;
	}
	else
		theContractAngel.SetCleanupTarget(*pScriptable);  // Auto-cleanup.
	// -----------------------------------------------------
    OTSmartContract * pContract = dynamic_cast<OTSmartContract *>(pScriptable);
    if (NULL == pContract)
	{
		OTLog::vOutput(0, "%s: Failure casting to Smart Contract. "
                       "Are you SURE it's a smart contract? Contents:\n"
                       "%s\n", __FUNCTION__, THE_CONTRACT.Get());
		return false;
	}
	// -----------------------------------------------------
	const std::string str_party_name(PARTY_NAME.Get());
	OTParty * pParty = pContract->GetParty(str_party_name);
	if (NULL == pParty)
	{
		OTLog::vOutput(0, "%s: Failure: Party doesn't exist: %s \n",
                       __FUNCTION__, PARTY_NAME.Get());
		return false;
	}
	// ---------------------------------------------
	// Make sure there's not already an account here with the same ID (Server disallows.)
	//
	OTPartyAccount * pDupeAcct = pParty->GetAccountByID(theAcctID);
	if (NULL != pDupeAcct) // It's already there.
	{
		OTLog::vOutput(0, "%s: Failed, since a duplicate account ID (%s) "
					   "was already found on this contract. (Server disallows, sorry.)\n",
                        __FUNCTION__, ACCT_ID.Get());
		return false;
	}
	// ---------------------------------------------
	// Find the account template based on its name, to affix the acct ID to.
	//
	const std::string str_name(ACCT_NAME.Get());

	OTPartyAccount * pPartyAcct = pParty->GetAccount(str_name);
	if (NULL == pPartyAcct) // It's not already there. (Though it should be...)
	{
		OTLog::vOutput(0, "%s: Failed: No account found on contract with name: %s \n",
					    __FUNCTION__, str_name.c_str());
		return false;
	}
	// ---------------------------------------------
	// the actual asset type ID
	
	const OTIdentifier	theExpectedAssetTypeID(pPartyAcct->GetAssetTypeID()); // The expected asset type ID, converting from a string.
	const OTIdentifier&	theActualAssetTypeID = pAccount->GetAssetTypeID();    // the actual asset type ID, already an identifier, from the actual account.
	
	if (theExpectedAssetTypeID != theActualAssetTypeID)
	{
		const OTString strAssetTypeID(theActualAssetTypeID);
		OTLog::vOutput(0, "%s: Failed, since the asset type ID of the account (%s) "
					   "does not match what was expected (%s) according to this contract.\n",
                        __FUNCTION__, strAssetTypeID.Get(), pPartyAcct->GetAssetTypeID().Get());
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
		OTLog::vOutput(0, "%s: Failed, since this nym (%s) isn't the owner of this account (%s).\n",
                        __FUNCTION__, strNymID.Get(), str_name.c_str());
		return false;
	}
	// ---------------------------------------------
    // When the first ACCOUNT is confirmed, then at that moment, we know which server
    // this smart contract is intended to execute on.
    //
    // If this is the first account being confirmed, then we will set the server ID
    // for the smart contract based on the server ID of this account. Otherwise if this
    // is not the first account being confirmed, then we will compare the server ID
    // that's already on the smart contract, to the server ID for this account, and make
    // sure they match. (Otherwise we will reject the confirmation.)
    //
    // Once the contract is activated, the server will verify all the parties and accounts
    // anyway. So might as well save ourselves the hassle, if this doesn't match up now.
    //
    if (pContract->SetServerIDIfEmpty(pAccount->GetPurportedServerID()))
    {        
        // todo security: possibly want to verify here that this really is the FIRST
        // account being confirmed in this smart contract, or at least the first party.
        // Right now we're just using the server ID being empty as an easy way to find
        // out, but technically a party could slip in a "signed version" without setting
        // the server ID, and it might slip by here (though it would eventually fail some
        // verification.) In the long term we'll do a more thorough check here, though.
    }
    else if (pContract->GetServerID() != pAccount->GetPurportedServerID())
    {
        const OTString strServer1(pContract->GetServerID()),
                       strServer2(pAccount->GetPurportedServerID());
        OTLog::vOutput(0, "%s: Failure: The smart contract has a different server ID on it already (%s) "
                       "than the one that goes with this account (server %s, for account %s)\n",
                       __FUNCTION__, strServer1.Get(), strServer2.Get(), ACCT_ID.Get());
        return false;
    }
	// ---------------------------------------------
	// BY THIS POINT, we know that the account is actually owned by the Nym,
	// and we know that it's got the proper asset type ID that was expected 
	// according to the smart contract. We also know that the smart contract
    // has the same server ID as the account being confirmed.
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
	// -----------------------------------------------------
	OTPseudonym * pNym = this->GetOrLoadPrivateNym(NYM_ID, false, __FUNCTION__); // These copiously log, and ASSERT.
	if (NULL == pNym) return false;
	// By this point, pNym is a good pointer, and is on the wallet. (No need to cleanup.)
	// -----------------------------------------------------			
	OTScriptable * pContract = OTScriptable::InstantiateScriptable(THE_CONTRACT);
	OTCleanup<OTScriptable> theContractAngel;
	
	if (NULL == pContract)
	{
		OTLog::vOutput(0, "%s: Error loading smart contract:\n\n%s\n\n",
					    __FUNCTION__, THE_CONTRACT.Get());
		return false;
	}
	else
		theContractAngel.SetCleanupTarget(*pContract);  // Auto-cleanup.
	// -----------------------------------------------------
	const std::string str_party_name(PARTY_NAME.Get());
	
	OTParty * pParty = pContract->GetParty(str_party_name);
	
	if (NULL == pParty)
	{
		OTLog::vOutput(0, "%s: Failure: Party (%s) doesn't exist, so how can you confirm it?\n",
					    __FUNCTION__, str_party_name.c_str());
		return false;
	}
	// -------------------------------
	OTParty * pNewParty = new OTParty(pParty->GetPartyName(), *pNym, // party keeps an internal pointer to pNym from here on.
									  pParty->GetAuthorizingAgentName()); // Party name and agent name must match, in order to replace / activate this party.
	OT_ASSERT(NULL != pNewParty);
	if (false == pParty->CopyAcctsToConfirmingParty(*pNewParty)) 
	{
		OTLog::vOutput(0, "%s: Failed while trying to copy accounts, while confirming party: %s \n",
					    __FUNCTION__, PARTY_NAME.Get());
		delete pNewParty; pNewParty=NULL;
		return false;
	}
	// ------------------
	if (false == pContract->ConfirmParty(*pNewParty)) // takes ownership. (Deletes the theoretical version of the party, replaced by our actual version pNewParty.)
	{
		OTLog::vOutput(0, "%s: Failed while trying to confirm party: %s \n",
					    __FUNCTION__, PARTY_NAME.Get());
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
    // ------------------------------
    //
    // DROP A COPY into the Outpayments box...
    //
    // (Since we used a transaction number to confirm the party, we
    // have to track it until it's activated or until we cancel it.)
    //
    const OTString strInstrument(*pContract);
    // ------------------------------
    OTMessage * pMessage = new OTMessage;
    OT_ASSERT(NULL != pMessage);
    
    const OTString strNymID(NYM_ID);
    
    pMessage->m_strCommand		= "outpaymentsMessage";
    pMessage->m_strNymID		= strNymID;
//  pMessage->m_strServerID		= strServerID;
    pMessage->m_ascPayload.SetString(strInstrument);
    
    pMessage->SignContract(*pNym);
    pMessage->SaveContract();
    
    pNym->AddOutpayments(*pMessage); // Now the Nym is responsible to delete it. It's in his "outpayments".
    OTPseudonym * pSignerNym = pNym;
    pNym->SaveSignedNymfile(*pSignerNym);
	// ------------------------------
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
	OTPseudonym * pNym = this->GetOrLoadPrivateNym(SIGNER_NYM_ID, false, __FUNCTION__); // These copiously log, and ASSERT.
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
	OTPseudonym * pNym = this->GetOrLoadPrivateNym(SIGNER_NYM_ID, false, szFuncName); // These copiously log, and ASSERT.
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
	OTPseudonym * pNym = this->GetOrLoadPrivateNym(SIGNER_NYM_ID, false, szFuncName); // These copiously log, and ASSERT.
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
	OTPseudonym * pNym = this->GetOrLoadPrivateNym(SIGNER_NYM_ID, false, szFuncName); // These copiously log, and ASSERT.
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
		OTLog::vOutput(0, "OT_API::SmartContract_AddClause: Failure: Bylaw doesn't exist: %s \n Input contract: \n\n%s\n\n",
					   str_bylaw_name.c_str(), THE_CONTRACT.Get());
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
	OTPseudonym * pNym = this->GetOrLoadPrivateNym(SIGNER_NYM_ID, false, szFuncName); // These copiously log, and ASSERT.
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
	OTPseudonym *	pSignerNym = this->GetOrLoadPrivateNym(SIGNER_NYM_ID, false, szFuncName);	// This logs and ASSERTs already.
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
	if (NYM_ID.IsEmpty()) { OTLog::vError("%s: NYM_ID is empty!", __FUNCTION__); OT_ASSERT(false); return NULL; }

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
OTPseudonym * OT_API::LoadPrivateNym(const OTIdentifier & NYM_ID, const bool bChecking/*=false*/,  const char * szFuncName/*=NULL*/,
                                     OTPasswordData * pPWData/*=NULL*/,
                                     OTPassword   * pImportPassword/*=NULL*/)
{
	if (NYM_ID.IsEmpty()) { OTLog::vError("%s: NYM_ID is empty!", __FUNCTION__); OT_ASSERT(false); return NULL; }
	// ---------------------------------
	// Grab the name, if there is one.
	// That way if we have to reload it, we'll be able to preserve the name.
	OTString		strName;
	const OTString	strNymID(NYM_ID);
	// ---------------------------------
    // If the Nym is already in the wallet, we grab the name from the wallet, so we can
    // set the same name onto that Nym again when he's re-loaded.
    //
	OTPseudonym *	pNym = this->GetNym(NYM_ID, szFuncName);	// This already logs and ASSERTs
	strName = (NULL != pNym) ? pNym->GetNymName().Get() : strNymID.Get();
	// now strName contains either "" or the Nym's name from wallet.
	// ---------------------------------
    OTPasswordData thePWData(OT_PW_DISPLAY);
    if (NULL == pPWData)
        pPWData = &thePWData;
	return OTPseudonym::LoadPrivateNym(NYM_ID, bChecking, &strName, szFuncName, pPWData, pImportPassword); // CALLER must delete!
}




// -----------------------------------------------------


/*
 OT_API_Msg_HarvestTransactionNumbers
 
 This function will load up the cron item (which is either a market offer, a payment plan,
 or a SMART CONTRACT.)  UPDATE: this function operates on messages, not cron items.
 
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
 
 // -----------------
 
 UPDATE: The above logic is now handled automatically in OT_API_HarvestTransactionNumbers.
 Therefore OT_API_HarvestClosingNumbers and OT_API_HarvestAllNumbers have been removed.
 
 */

// true == no errors. false == errors.
//
bool OT_API::Msg_HarvestTransactionNumbers(      OTMessage      & theMsg,
                                           const OTIdentifier	& USER_ID,
                                           const bool             bHarvestingForRetry,     // false until positively asserted.
                                           const bool             bReplyWasSuccess,        // false until positively asserted.
                                           const bool             bReplyWasFailure,        // false until positively asserted.
                                           const bool             bTransactionWasSuccess,  // false until positively asserted.
                                           const bool             bTransactionWasFailure)  // false until positively asserted.
{
	const char * szFuncName		= "OT_API::Msg_HarvestTransactionNumbers";
	// -----------------------------------------------------
	OTPseudonym * pNym = this->GetOrLoadPrivateNym(USER_ID, false, szFuncName); // These copiously log, and ASSERT.
	if (NULL == pNym) return false;
	// By this point, pNym is a good pointer, and is on the wallet. (No need to cleanup.)
	// -----------------------------------------------------
    
    return theMsg.HarvestTransactionNumbers(*pNym,
                                            bHarvestingForRetry,     
                                            bReplyWasSuccess,        
                                            bReplyWasFailure,        
                                            bTransactionWasSuccess,  
                                            bTransactionWasFailure);  
}









/*
 
 ------ TODO: Smart Contracts -----------
 
 TODO:  Whenever a party confirms a smart contract (sending it on to the next party) then a copy of
 the smart contract should go into that party's paymentOutbox. Same thing if the party is the last
 one in the chain, and has activated it on to the server. A copy sits in the paymentOutbox until
 that smart contract is either successfully activated, or FAILS to activate.
 
 If a smart contract activates, OTScriptable::DropServerNoticeToNymbox already sends an
 'acknowledgment' notice to all parties.
 
 TODO: If a smart contract fails to activate, it should ALSO send a notice ('rejection') to
 all parties.
 
 TODO: When a party receives a rejection notice in his Nymbox for a certain smart contract,
 he looks up that same smart contract in his paymentOutbox, HARVESTS THE CLOSING NUMBERS, and
 then moves the notice from his paymentOutbox to his recordBox.
 
 Until this is added, then clients will go out of sync on rejected smart contracts. (Not the kind
 of out-of-sync where they can't do any transactions, but rather, the kind where they have certain
 numbers signed out forever but then never use them on anything because their client thinks those
 numbers were already used on a smart contract somewhere, and without the above code they would
 never have clawed back those numbers.)
 */








bool OT_API::HarvestClosingNumbers(const OTIdentifier	& SERVER_ID,
								   const OTIdentifier	& NYM_ID,
								   const OTString		& THE_CRON_ITEM)
{
	const char * szFuncName		= "OT_API::HarvestClosingNumbers";
	// -----------------------------------------------------
	OTPseudonym * pNym = this->GetOrLoadPrivateNym(NYM_ID, false, szFuncName); // These copiously log, and ASSERT.
	if (NULL == pNym) return false;
	// By this point, pNym is a good pointer, and is on the wallet. (No need to cleanup.)
	// -----------------------------------------------------			
	OTCronItem * pCronItem = OTCronItem::NewCronItem(THE_CRON_ITEM);
	OTCleanup<OTCronItem> theContractAngel;
	if (NULL == pCronItem)
	{
		OTLog::vOutput(0, "%s: Error loading the cron item (a cron item is a smart contract, or "
					   "some other recurring transaction such as a market offer, or a payment plan.) Contents:\n\n%s\n\n",
					   szFuncName, THE_CRON_ITEM.Get());
		return false;
	}
	else
		theContractAngel.SetCleanupTarget(*pCronItem);  // Auto-cleanup.
	// -----------------------------------------------------
	pCronItem->HarvestClosingNumbers(*pNym); // <==== the Nym is actually harvesting the numbers from the Cron Item, and not the other way around.
	// -------------------------------	
	return true;
}


// NOTE: usually you will want to call OT_API_HarvestClosingNumbers (above), since the Opening number is usually
// burned up from some failed transaction or whatever. You don't want to harvest the opening number usually,
// just the closing numbers. (If the opening number is burned up, yet you still harvest it, then your OT wallet
// could end up using that number again on some other transaction, which will obviously then fail since the number
// isn't good anymore. In fact much of OT's design is based on minimizing/eliminating any such sync issues.)
// This function is only for those cases where you are sure that the opening transaction # hasn't been burned yet,
// such as when the message failed and the transaction wasn't attempted (because it never got that far) or such as
// when the contract simply never got signed or activated by one of the other parties, and so you want to claw ALL your
// #'s back, and since in that case your opening number is still good, you would use the below function to get it back.
//
bool OT_API::HarvestAllNumbers(const OTIdentifier	& SERVER_ID,
							   const OTIdentifier	& NYM_ID,
							   const OTString		& THE_CRON_ITEM)
{
	const char * szFuncName		= "OT_API::HarvestAllNumbers";
	// -----------------------------------------------------
	OTPseudonym * pNym = this->GetOrLoadPrivateNym(NYM_ID, false, szFuncName); // These copiously log, and ASSERT.
	if (NULL == pNym) return false;
	// By this point, pNym is a good pointer, and is on the wallet. (No need to cleanup.)
	// -----------------------------------------------------			
	OTCronItem * pCronItem = OTCronItem::NewCronItem(THE_CRON_ITEM);
	OTCleanup<OTCronItem> theContractAngel;
	if (NULL == pCronItem)
	{
		OTLog::vOutput(0, "%s: Error loading the cron item (a cron item is a smart contract, or "
					   "some other recurring transaction such as a market offer, or a payment plan.) Contents:\n\n%s\n\n",
					   szFuncName, THE_CRON_ITEM.Get());
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
	if (NYM_ID.IsEmpty()) { OTLog::vError("%s: NYM_ID is empty!", __FUNCTION__); OT_ASSERT(false); return NULL; }

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
OTPseudonym * OT_API::GetOrLoadPrivateNym(const OTIdentifier & NYM_ID,
										  const bool bChecking/*=false*/,
                                          const char * szFuncName/*=NULL*/,
                                          OTPasswordData * pPWData/*=NULL*/,
                                          OTPassword * pImportPassword/*=NULL*/)
{
	if (NYM_ID.IsEmpty()) { OTLog::vError("%s: NYM_ID is empty!", __FUNCTION__); OT_ASSERT(false); return NULL; }

	OTWallet * pWallet = GetWallet(szFuncName); // This logs and ASSERTs already.
	if (NULL == pWallet) return NULL;
	if (NYM_ID.IsEmpty()) return NULL;
	// By this point, pWallet is a good pointer.  (No need to cleanup.)
	// -----------------------------------------------------
	//
	// This already logs copiously, including szFuncName...
	//
    OTPasswordData thePWData(OT_PW_DISPLAY);
	return pWallet->GetOrLoadPrivateNym(NYM_ID, bChecking, szFuncName,
                                        NULL == pPWData ? &thePWData : pPWData,
                                        pImportPassword);
}


/// This function tries to load as public Nym first, then if it fails,
/// it tries the private one next. (So as to avoid unnecessarily asking
/// users for their passphrase.) Be sure to use GetOrLoadPublicNym() or
/// GetOrLoadPrivateNym() if you want to force it one way or the other.
///
/// No need to cleanup the Nym returned here, since it's added to the wallet and
/// the wallet takes ownership.
///
OTPseudonym * OT_API::GetOrLoadNym(const OTIdentifier & NYM_ID,
								   const bool bChecking/*=false*/,
                                   const char * szFuncName/*=NULL*/,
                                   OTPasswordData * pPWData/*=NULL*/)
{
	if (NYM_ID.IsEmpty()) { OTLog::vError("%s: NYM_ID is empty!", __FUNCTION__); OT_ASSERT(false); return NULL; }

	OTWallet * pWallet = GetWallet(szFuncName); // This logs and ASSERTs already.
	if (NULL == pWallet) return NULL;
	// By this point, pWallet is a good pointer.  (No need to cleanup.)
	// -----------------------------------------------------
	//
	// This already logs copiously, including szFuncName...
	//
    
    OTPasswordData thePWData(OT_PW_DISPLAY);

	return pWallet->GetOrLoadNym(NYM_ID, bChecking, szFuncName, NULL == pPWData ? &thePWData : pPWData);
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
	OTPseudonym * pNym = this->GetOrLoadPrivateNym(NYM_ID, false, szFunc);
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
							   const long         & CHEQUE_AMOUNT, 
							   const time_t       & VALID_FROM, 
							   const time_t       & VALID_TO,
							   const OTIdentifier & SENDER_ACCT_ID,
							   const OTIdentifier & SENDER_USER_ID,
							   const OTString     & CHEQUE_MEMO, 
							   const OTIdentifier * pRECIPIENT_USER_ID/*=NULL*/)
{
	// -----------------------------------------------------
	OTPseudonym * pNym = this->GetOrLoadPrivateNym(SENDER_USER_ID, false, __FUNCTION__);
	if (NULL == pNym) return NULL;
	// By this point, pNym is a good pointer, and is on the wallet. (No need to cleanup.)
	// -----------------------------------------------------
	OTAccount * pAccount = this->GetOrLoadAccount(*pNym, SENDER_ACCT_ID, SERVER_ID, __FUNCTION__);
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
		OTLog::vOutput(0, "%s: User attempted to write a cheque, but had no transaction numbers.\n",
                       __FUNCTION__);
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
		OTLog::vError("%s: Failure calling OTCheque::IssueCheque().\n", __FUNCTION__);
		delete pCheque; pCheque = NULL;
		// IF FAILED, ADD TRANSACTION NUMBER BACK TO LIST OF AVAILABLE NUMBERS.
		pNym->AddTransactionNum(*pNym, strServerID, lTransactionNumber, true); // bSave=true								
		return NULL;			
	}
	// ------------------------------
	pCheque->SignContract(*pNym);
	pCheque->SaveContract();
	// ------------------------------
    //
    // DROP A COPY into the Outpayments box...
    //
    // (Since we used a transaction number to write the cheque,
    // we have to track it until it's deposited or until we cancel
    // it.)
    //
    const OTString strInstrument(*pCheque);
    // ------------------------------
    OTMessage * pMessage = new OTMessage;
    OT_ASSERT(NULL != pMessage);
    
    const OTString strNymID(SENDER_USER_ID);

    pMessage->m_strCommand		= "outpaymentsMessage";
    pMessage->m_strNymID		= strNymID;
    
    if (NULL != pRECIPIENT_USER_ID)
    {
        const OTString strNymID2(*pRECIPIENT_USER_ID);
        pMessage->m_strNymID2	= strNymID2;
    }
    pMessage->m_strServerID		= strServerID;    
    pMessage->m_ascPayload.SetString(strInstrument);
    
    pMessage->SignContract(*pNym);
    pMessage->SaveContract();
    
    pNym->AddOutpayments(*pMessage); // Now the Nym is responsible to delete it. It's in his "outpayments".
    OTPseudonym * pSignerNym = pNym;
    pNym->SaveSignedNymfile(*pSignerNym);
	// ------------------------------
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
	OTPseudonym * pNym = this->GetOrLoadPrivateNym(RECIPIENT_USER_ID, false, szFuncName); // This logs, ASSERTs, etc.
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
    // ------------------------------
    //
    // DROP A COPY into the Outpayments box...
    //
    // (Since we used a transaction number to propose the plan, we
    // have to track it until it's deposited or until we cancel it.)
    //
    const OTString strInstrument(*pPlan);
    // ------------------------------
    OTMessage * pMessage = new OTMessage;
    OT_ASSERT(NULL != pMessage);
    
    const OTString strNymID(RECIPIENT_USER_ID), strNymID2(SENDER_USER_ID);
    
    pMessage->m_strCommand		= "outpaymentsMessage";
    pMessage->m_strNymID		= strNymID;
    pMessage->m_strNymID2		= strNymID2;    
    pMessage->m_strServerID		= strServerID;
    pMessage->m_ascPayload.SetString(strInstrument);
    
    pMessage->SignContract(*pNym);
    pMessage->SaveContract();
    
    pNym->AddOutpayments(*pMessage); // Now the Nym is responsible to delete it. It's in his "outpayments".
    OTPseudonym * pSignerNym = pNym;
    pNym->SaveSignedNymfile(*pSignerNym);
	// ------------------------------
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
	OTPseudonym * pNym = this->GetOrLoadPrivateNym(SENDER_USER_ID, false, szFuncName); // This logs, ASSERTs, etc.
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
    const OTString strServerID(SERVER_ID);

	if (!bConfirmed)
	{
		OTLog::Output(0, "OT_API::ConfirmPaymentPlan: Failed trying to confirm the agreement.\n");
        
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
    // ------------------------------
    //
    // DROP A COPY into the Outpayments box...
    //
    // (Since we used a transaction number to confirm the plan, we
    // have to track it until it's deposited or until we cancel it.)
    //
    const OTString strInstrument(thePlan);
    // ------------------------------
    OTMessage * pMessage = new OTMessage;
    OT_ASSERT(NULL != pMessage);
    
    const OTString strNymID(SENDER_USER_ID), strNymID2(RECIPIENT_USER_ID);
    
    pMessage->m_strCommand		= "outpaymentsMessage";
    pMessage->m_strNymID		= strNymID;
    pMessage->m_strNymID2		= strNymID2;
    pMessage->m_strServerID		= strServerID;
    pMessage->m_ascPayload.SetString(strInstrument);
    
    pMessage->SignContract(*pNym);
    pMessage->SaveContract();
    
    pNym->AddOutpayments(*pMessage); // Now the Nym is responsible to delete it. It's in his "outpayments".
    OTPseudonym * pSignerNym = pNym;
    pNym->SaveSignedNymfile(*pSignerNym);
	// ------------------------------
	return true;
}



// -----------------------------------------------------




// LOAD PURSE
//
// Returns an OTPurse pointer, or NULL.
//
// (Caller responsible to delete.)
//
OTPurse * OT_API::LoadPurse(const OTIdentifier & SERVER_ID,
							const OTIdentifier & ASSET_ID,
							const OTIdentifier & USER_ID,
                            const OTString     * pstrDisplay/*=NULL*/)
{	
	OT_ASSERT_MSG(m_bInitialized, "Not initialized; call OT_API::Init first.");
	// -----------------------------------------------------------------
    const char * szFunc = "OT_API::LoadPurse";
	// -----------------------------------------------------------------
    const OTString strReason((NULL == pstrDisplay) ? "Loading purse from local storage." : pstrDisplay->Get());
    OTPasswordData thePWData(strReason);
    // -----------------------------------
	const OTString strServerID(SERVER_ID);
	const OTString strUserID(USER_ID);
	const OTString strAssetTypeID(ASSET_ID);
	// -----------------------------------------------------------------
    OTPseudonym * pNym = this->GetOrLoadPrivateNym(USER_ID, false, szFunc, &thePWData); // These copiously log, and ASSERT.
    if (NULL == pNym) return NULL;
	// -----------------------------------------------------------------
	OTPurse * pPurse = new OTPurse(SERVER_ID, ASSET_ID, USER_ID);
	OT_ASSERT_MSG(NULL != pPurse, "Error allocating memory in the OT API."); // responsible to delete or return pPurse below this point.
	
	if (pPurse->LoadPurse(strServerID.Get(), strUserID.Get(), strAssetTypeID.Get()) &&
        pPurse->VerifySignature(*pNym)       &&
        (SERVER_ID == pPurse->GetServerID()) &&
        (ASSET_ID  == pPurse->GetAssetID ()))
		return pPurse;
    else
        OTLog::vOutput(0, "%s: Failed loading or verifying purse.\n");
	// --------------------------------
	delete pPurse; 
	pPurse = NULL;
	
	return NULL;
}


// -----------------------------------------------------



bool OT_API::SavePurse(const OTIdentifier & SERVER_ID,
					   const OTIdentifier & ASSET_ID,
					   const OTIdentifier & USER_ID,
                             OTPurse      & THE_PURSE)
{	
	OT_ASSERT_MSG(m_bInitialized, "Not initialized; call OT_API::Init first.");
    // ---------------------------------------------------------
	const char *szFunc = "OT_API::SavePurse";
    // ---------------------------------------------------------   
    if (THE_PURSE.IsPasswordProtected())
    {
        OTLog::vOutput(0, "%s: Failure: This purse is password-protected (exported) "
                       "and cannot be saved inside the wallet without first re-importing it.\n", szFunc);
    }
    else if ((THE_PURSE.GetServerID() != SERVER_ID) ||
             (THE_PURSE.GetAssetID()  != ASSET_ID))
	{
		OTLog::vOutput(0, "%s: Error: Wrong server or asset ID passed in, "
                       "considering the purse that was passed.\n", szFunc);
    }
    else
	{
        // -------------------------------------------------
        const OTString strServerID(SERVER_ID);
        const OTString strAssetTypeID(ASSET_ID);
        const OTString strUserID(USER_ID);
        // -----------------------------------------------------------------
        if (THE_PURSE.SavePurse(strServerID.Get(), strUserID.Get(), strAssetTypeID.Get()))
            return true;
	}
    // -----------------------------------------------------------------
	const OTString strPurse(THE_PURSE);
	OTLog::vOutput(0, "%s: Failed saving purse:\n\n%s\n\n",
                   szFunc, strPurse.Get());
	return false;
}



// -----------------------------------------------------

// Creates a purse owned by a specific Nym. (OWNER_ID.)
//
// Caller is responsible to delete!
//
OTPurse * OT_API::CreatePurse(const OTIdentifier & SERVER_ID,
                              const OTIdentifier & ASSET_ID,
                              const OTIdentifier & OWNER_ID)
{
	OT_ASSERT_MSG(m_bInitialized, "Not initialized; call OT_API::Init first.");
	// -----------------------------------------------------------------
	OTPurse * pPurse = new OTPurse(SERVER_ID, ASSET_ID, OWNER_ID);
	OT_ASSERT_MSG(NULL != pPurse, "Error allocating memory in the OT API."); // responsible to delete or return pPurse below this point.
	
	return pPurse;
}



// -----------------------------------------------------



// This is the same as CreatePurse, except it creates a password-protected purse,
// instead of a Nym-encrypted purse. 
//
// Caller is responsible to delete!
//
OTPurse * OT_API::CreatePurse_Passphrase(const OTIdentifier & SERVER_ID,
                                         const OTIdentifier & ASSET_ID)
{
	OT_ASSERT_MSG(m_bInitialized, "Not initialized; call OT_API::Init first.");
	// -----------------------------------------------------------------
	OTPurse * pPurse = new OTPurse(SERVER_ID, ASSET_ID);
	OT_ASSERT_MSG(NULL != pPurse, "Error allocating memory in the OT API."); // responsible to delete or return pPurse below this point.
	// -----------------------------------------------------------------
    if (pPurse->GenerateInternalKey())
        return pPurse;
    else
        OTLog::Error("OT_API::CreatePurse_Passphrase: "
                     "pPurse->GenerateInternalKey() returned false. (Failure.)\n");
    delete pPurse; pPurse = NULL;
    return NULL;
}

// -----------------------------------------------------




// Caller responsible to delete!
//
// This method was added because otherwise its code would be
// duplicated across many of the Purse functions.
//
OTNym_or_SymmetricKey * OT_API::LoadPurseAndOwnerFromString(const OTIdentifier & theServerID,
                                                            const OTIdentifier & theAssetTypeID,
                                                            const OTString     & strPurse,
                                                                  OTPurse      & thePurse, // output
                                                                  OTPassword   & thePassword, // Only used in the case of password-protected purses. Passed in so it won't go out of scope when pOwner is set to point to it.
                                                            const bool           bForEncrypting/*=true*/, // true==encrypting,false==decrypting. Only relevant if there's an owner.
                                                            const OTIdentifier * pOWNER_ID/*=NULL*/, // This can be NULL, **IF** purse is password-protected. (It's just ignored in that case.) Otherwise MUST contain the NymID for the Purse owner.
                                                            const OTString     * pstrDisplay1/*=NULL*/, // for purses owned by the wallet already
                                                            const OTString     * pstrDisplay2/*=NULL*/) // for password-protected purses
{
	OT_ASSERT_MSG(m_bInitialized, "Not initialized; call OT_API::Init first.");
	// -----------------------------------------------------------------
   	const char * szFunc             = __FUNCTION__; //"LoadPurseAndOwnerFromString";
	// -----------------------------------------------------
    const bool   bDoesOwnerIDExist  = (NULL != pOWNER_ID); // If not true, purse MUST be password-protected.
	// -----------------------------------------------------
    OTPasswordData thePWData1((NULL == pstrDisplay1) ?
                              "Enter the master passphrase for your wallet. (LoadPurseAndOwnerFromString)" :
                              pstrDisplay1->Get()); // for purses already owned by the wallet
    OTPasswordData thePWData2((NULL == pstrDisplay2) ?
                              "Enter the passphrase for this purse. (LoadPurseAndOwnerFromString)" :
                              pstrDisplay2->Get()); // for password-protected purses.
	// -----------------------------------------------------
    OTPseudonym * pOwnerNym         =  NULL; // In the case where there is an owner, this will point to it.
	// -----------------------------------------------------
    if (bDoesOwnerIDExist)
    {
        pOwnerNym = bForEncrypting ? this->GetOrLoadNym(*pOWNER_ID, false, szFunc, &thePWData1) :
                                     this->GetOrLoadPrivateNym(*pOWNER_ID, false, szFunc, &thePWData1); // These copiously log, and ASSERT.
        if (NULL == pOwnerNym) return NULL;
    }
	// By this point, pOwnerNym may be a good pointer, and on the wallet. (No need to cleanup.)
    // Or, it may also be NULL, in the case that the purse is password-protected.
    // bDoesOwnerIDExist is an easy way to tell, either way.
	// -----------------------------------------------------
    OTNym_or_SymmetricKey * pOwner = NULL;
	// -----------------------------------------------------    
	if (strPurse.Exists() && thePurse.LoadContractFromString(strPurse))
	{
        const bool bNymIDIncludedInPurse = thePurse.IsNymIDIncluded();
        // --------------------------------------
        OTIdentifier idPurseNym;
        
        if (thePurse.GetServerID() != theServerID)
            OTLog::vError("%s: Failed: ServerID doesn't match.\n", szFunc);
        // --------------------------------------
        else if (thePurse.GetAssetID() != theAssetTypeID)
            OTLog::vError("%s: Failed: AssetTypeID doesn't match.\n", szFunc);
        // --------------------------------------
        else if (bNymIDIncludedInPurse && !thePurse.GetNymID(idPurseNym))
            OTLog::vError("%s: Failed trying to get the NymID from the "
                          "purse (though one WAS apparently present.)\n", szFunc);
        // --------------------------------------
        else if (bNymIDIncludedInPurse && !bDoesOwnerIDExist)
        {
            const OTString strPurseNymID(idPurseNym);
            OTLog::vError("%s: Error: The purse is owned by a NymID, but no NymID was passed into "
                          "this function.\nNym who owns the purse: %s\n\n", szFunc, strPurseNymID.Get());
        }
        // --------------------------------------
        else if (bNymIDIncludedInPurse && !(pOwnerNym->GetConstID() == idPurseNym))
        {
            const OTString strPurseNymID(idPurseNym), strNymActuallyPassed(pOwnerNym->GetConstID());
            OTLog::vError("%s: Error: the API call mentions Nym A, but the purse is actually "
                          "owned by Nym B.\nNym A: %s\nNym B: %s\n\n", szFunc, strNymActuallyPassed.Get(),
                          strPurseNymID.Get());
        }
        // --------------------------------------
        else if (!bDoesOwnerIDExist && !thePurse.IsPasswordProtected())
            OTLog::vError("%s: Failed: The USER_ID was NULL, which is only allowed "
                          "for a password-protected purse. (And this purse is NOT "
                          "password-protected.) Please provide a USER_ID.\n", szFunc);
        // --------------------------------------
        // By this point, we know the purse loaded up properly, and the server and asset IDs match
        // what we expected. We also know that if the purse included a NymID, it matches the USER_ID
        // that was passed in. We also know that if a User ID was NOT passed in, that the purse WAS
        // definitely a password-protected purse.
        //
        else if (thePurse.IsPasswordProtected())  // Purse is encrypted based on its own built-in symmetric key.
        {
            OTSymmetricKey * pSymmetricKey = thePurse.GetInternalKey();
            OT_ASSERT(NULL != pSymmetricKey);
            // -------------------------
            const bool bGotPassphrase = thePurse.GetPassphrase(thePassword, thePWData2.GetDisplayString());
            
            if (!bGotPassphrase)
                OTLog::vOutput(0, "%s: Authentication failed, or otherwise failed "
                               "retrieving secret from user.\n", szFunc);
            // -------------------------
            // Below this point, we know thePassword is good, and we know pSymmetricKey is good.
            // Therefore...
            //
            else
            {
                pOwner = new OTNym_or_SymmetricKey(*pSymmetricKey, thePassword,
                                                   pstrDisplay2); // Can't put &strReason here. (It goes out of scope.)
                OT_ASSERT(NULL != pOwner);
            }
        }
        // --------------------------------------
        else if (bDoesOwnerIDExist)                // Purse is encrypted based on Nym.
        {
            pOwner = new OTNym_or_SymmetricKey(*pOwnerNym, pstrDisplay1); // Can't put &strReason here. (It goes out of scope.)
            OT_ASSERT(NULL != pOwner);
        }
        // --------------------------------------
        else
            OTLog::vError("%s: Failed: The purse is not password-protected, but rather, is locked by a Nym. "
                          "However, no USER_ID was passed in! Please supply a USER_ID in order "
                          "to open this purse.\n", szFunc);
        // ************************************************************************************
        // (By this point, pOwner is all set up and ready to go.)
	}
	else
		OTLog::vOutput(0, "%s: Failure loading purse from string:\n%s\n",
                       szFunc, strPurse.Get());
    // ----------------
    return pOwner;
}


// NOTE: This function is identical to the one above it, except
// that one has to verify that the Nym IDs match, whereas this one
// takes the NymID from the purse, if one is there, and makes it
// authoritative. If no NymID is listed on the purse (but it's NOT
// password protected, i.e. there IS a Nym, it's just not listed)
// then pOWNER_ID is the one it will try.
//
// Caller must delete.
//
OTNym_or_SymmetricKey * OT_API::LoadPurseAndOwnerForMerge(const OTString     & strPurse,
                                                                OTPurse      & thePurse, // output
                                                                OTPassword   & thePassword, // Only used in the case of password-protected purses. Passed in so it won't go out of scope when pOwner is set to point to it.
                                                          const bool           bCanBePublic/*=false*/, // true==private nym isn't mandatory. false==private nym IS mandatory. (Only relevant if there's an owner.)
                                                          const OTIdentifier * pOWNER_ID/*=NULL*/, // This can be NULL, **IF** purse is password-protected. (It's just ignored in that case.) Otherwise if it's Nym-protected, the purse will have a NymID on it already. If not (it's optional), then pOWNER_ID is the ID it will try next, before failing.
                                                          const OTString     * pstrDisplay/*=NULL*/)
{
	OT_ASSERT_MSG(m_bInitialized, "Not initialized; call OT_API::Init first.");
	// -----------------------------------------------------------------
   	const char * szFunc = __FUNCTION__; //"LoadPurseAndOwnerForMerge";
	// -----------------------------------------------------
    OTPasswordData thePWData((NULL == pstrDisplay) ? OT_PW_DISPLAY : pstrDisplay->Get());
    // -----------------------------------
    OTNym_or_SymmetricKey * pOwner = NULL;
	// -----------------------------------------------------    
	if (strPurse.Exists() && thePurse.LoadContractFromString(strPurse))
	{
        // --------------------------------------
        OTIdentifier idPurseNym;
        
        if (thePurse.IsNymIDIncluded() && !thePurse.GetNymID(idPurseNym))
            OTLog::vError("%s: Failed trying to get the NymID from the "
                          "purse (though one WAS apparently present.)\n", szFunc);
        // --------------------------------------
        // Purse is encrypted based on Nym.
        //
        // If the purse includes a NymID, then we'll use it. (If we can't use that specific one, then we have failed.)
        else if (thePurse.IsNymIDIncluded() ||
                 // Else if the purse does NOT include a NymID (but also is NOT password protected, meaning a Nym still exists, but just isn't named) then we'll use pOWNER_ID passed in. If that's NULL, or we fail to find the Nym with it, then we have failed.
                 ( !thePurse.IsNymIDIncluded() && !thePurse.IsPasswordProtected() ) // && (NULL != pOWNER_ID)) // checked inside the block.
                 )
        {
            const OTIdentifier * pActualOwnerID = thePurse.IsNymIDIncluded() ? &idPurseNym : pOWNER_ID;
            
            if (NULL == pActualOwnerID)
            {
                OTLog::vError("%s: Failed: The purse is encrypted to a specific Nym (not a passphrase) "
                              "but that Nym is not specified in the purse, nor was it passed into this "
                              "function. (Failure. Unable to access purse.)\n", szFunc);
                return NULL;
            }
            // ---------------------------------------------------
            OTPseudonym * pOwnerNym = bCanBePublic ? this->GetOrLoadNym       (*pActualOwnerID, false, szFunc, &thePWData) :
                                                     this->GetOrLoadPrivateNym(*pActualOwnerID, false, szFunc, &thePWData); // These copiously log, and ASSERT.
            if (NULL == pOwnerNym)
            {
                const OTString strAttemptedID(*pActualOwnerID);
                OTLog::vError("%s: Failed: The purse is encrypted to a specific NymID (not a passphrase) which was "
                              "either specified inside the purse, or wasn't specified so we guessed the user ID. "
                              "Either way, we then failed loading that Nym: %s\n"
                              "(Failure. Unable to access purse.)\n", szFunc, strAttemptedID.Get());
                return NULL;
            }
            // ---------------------------------------------------
            // We found the Nym. If it was the Nym listed in the purse, then it's almost certainly the right one.
            // Else if it was the Nym we guessed, it could be right and it could be wrong. We won't find out in that
            // case, until we actually try to use it for decrypting tokens on the purse (and then we'll fail at that
            // time, if it's the wrong Nym.)
            //
            pOwner = new OTNym_or_SymmetricKey(*pOwnerNym, pstrDisplay); // Can't put &strReason here. (It goes out of scope.)
            OT_ASSERT(NULL != pOwner);
        }
        // --------------------------------------
        // Else if purse IS password protected, then use its internal key.
        else if (thePurse.IsPasswordProtected())  // Purse is encrypted based on its own built-in symmetric key.
        {
            OTSymmetricKey * pSymmetricKey = thePurse.GetInternalKey();
            OT_ASSERT(NULL != pSymmetricKey);
            // -------------------------
            const bool bGotPassphrase = thePurse.GetPassphrase(thePassword, thePWData.GetDisplayString());
            
            if (!bGotPassphrase)
                OTLog::vOutput(0, "%s: Authentication failed, or otherwise failed "
                               "retrieving secret from user.\n", szFunc);
            // -------------------------
            // Below this point, we know thePassword is good, and we know pSymmetricKey is good.
            // Therefore...
            //
            else
            {
                pOwner = new OTNym_or_SymmetricKey(*pSymmetricKey, thePassword,
                                                   pstrDisplay); // Can't put &strReason here. (It goes out of scope.)
                OT_ASSERT(NULL != pOwner);
            }
        }
        // --------------------------------------
        else
            OTLog::vError("%s: Failed: Somehow this purse is not password-protected, nor is it "
                          "Nym-protected. (This error should never actually happen.)\n", szFunc);
        // ************************************************************************************
        // (By this point, pOwner is all set up and ready to go.)
	}
	else
		OTLog::vOutput(0, "%s: Failure loading purse from string:\n%s\n",
                       szFunc, strPurse.Get());
    // ----------------
    return pOwner;
}





/// Returns the TOKEN on top of the stock (LEAVING it on top of the stack,
/// but giving you a decrypted copy of it.)
///
/// USER_ID can be NULL, **if** the purse is password-protected.
/// (It's just ignored in that case.) Otherwise MUST contain the NymID for
/// the Purse owner (necessary to decrypt the token.)
///
/// CALLER must delete!!
///
/// returns NULL if failure.
///
OTToken * OT_API::Purse_Peek(const OTIdentifier & SERVER_ID,
                             const OTIdentifier & ASSET_TYPE_ID,
                             const OTString     & THE_PURSE,
                             const OTIdentifier * pOWNER_ID/*=NULL*/, // This can be NULL, **IF** purse is password-protected. (It's just ignored in that case.) Otherwise MUST contain the NymID for the Purse owner (necessary to decrypt the token.)
                             const OTString     * pstrDisplay/*=NULL*/)
{
	OT_ASSERT_MSG(m_bInitialized, "Not initialized; call OT_API::Init first.");
	// -----------------------------------------------------------------
    const char * szFunc = "OT_API::Purse_Peek";
    // -----------------------------------
    const OTString strReason1((NULL == pstrDisplay) ? "Enter your master passphrase for your wallet. (Purse_Peek)" : pstrDisplay->Get());
    const OTString strReason2((NULL == pstrDisplay) ? "Enter the passphrase for this purse. (Purse_Peek)"          : pstrDisplay->Get());
//  OTPasswordData thePWData(strReason);
    // -----------------------------------
    OTPurse    thePurse(SERVER_ID, ASSET_TYPE_ID);
    OTPassword thePassword; // Only used in the case of password-protected purses.
	// -----------------------------------------------------
    // What's going on here?
    // A purse can be encrypted by a private key (controlled by a Nym) or by a symmetric
    // key (embedded inside the purse along with a corresponding master key.) The below
    // function is what actually loads up thePurse from string (THE_PURSE) and this call
    // also returns pOwner, which is a pointer to a special wrapper class (which you must
    // delete, when you're done with it) which contains a pointer EITHER to the owner Nym
    // for that purse, OR to the "owner" symmetric key for that purse.
    //
    // This way, any subsequent purse operations can use pOwner, regardless of whether there
    // is actually a Nym inside, or a symmetric key. (None of the purse operations will care,
    // since they can use pOwner either way.)
    //
    OTNym_or_SymmetricKey * pOwner = this->LoadPurseAndOwnerFromString(SERVER_ID, ASSET_TYPE_ID,
                                                                       THE_PURSE, thePurse, thePassword,
                                                                       false, // bForEncrypting=true by default. (Peek needs to decrypt.)
                                                                       pOWNER_ID,
                                                                       &strReason1, &strReason2);
    OTCleanup<OTNym_or_SymmetricKey> theOwnerAngel(pOwner);
    // -----------------------------------------------------------------
    if (NULL == pOwner) return NULL; // This already logs, no need for more logs.
    // -----------------------------------------------------------------
    OTToken * pToken = NULL;

    if (thePurse.IsEmpty())
        OTLog::vOutput(0, "%s: Failed attempt to peek; purse is empty.\n", szFunc);
    else
    {
        pToken = thePurse.Peek(*pOwner);
        
        if (NULL == pToken)
            OTLog::vOutput(0, "%s: Failed peeking a token from a "
                           "purse that supposedly had tokens on it...\n", szFunc);
    }
    // -----------------------------------------------------------------
    return pToken;
}





// -----------------------------------------------------


/// Returns the PURSE after popping a single token off of it.
///
/// NOTE: Caller must delete!
/// NOTE: Caller must sign/save in order to effect the change.
///
/// OWNER_ID can be NULL, **if** the purse is password-protected.
/// (It's just ignored in that case.) Otherwise MUST contain the NymID for
/// the Purse owner (necessary to decrypt the token.)
///
/// The reason you don't see a signer being passed here (to save the purse
/// again, after popping) is because OTAPI.cpp Purse_Pop does the saving.
/// (That's the function that calls this one.) So IT has a signer ID passed
/// in, in addition to the owner ID--but we don't need that here.)
///
/// returns NULL if failure.
///
OTPurse * OT_API::Purse_Pop(const OTIdentifier & SERVER_ID,
                            const OTIdentifier & ASSET_TYPE_ID,
                            const OTString     & THE_PURSE,
                            const OTIdentifier * pOWNER_ID/*=NULL*/, // This can be NULL, **IF** purse is password-protected. (It's just ignored in that case.) Otherwise MUST contain the NymID for the Purse owner (necessary to decrypt the token.)
                            const OTString     * pstrDisplay/*=NULL*/)
{
	OT_ASSERT_MSG(m_bInitialized, "Not initialized; call OT_API::Init first.");
	// -----------------------------------------------------------------
    const char * szFunc = "OT_API::Purse_Pop";
    // -----------------------------------
    const OTString strReason1((NULL == pstrDisplay) ? "Enter your master passphrase for your wallet. (Purse_Pop)" : pstrDisplay->Get());
    const OTString strReason2((NULL == pstrDisplay) ? "Enter the passphrase for this purse. (Purse_Pop)"          : pstrDisplay->Get());
//  OTPasswordData thePWData(strReason);
    // -----------------------------------
    OTPurse    * pPurse = new OTPurse(SERVER_ID, ASSET_TYPE_ID);
    OT_ASSERT(NULL != pPurse);
    OTCleanup<OTPurse> thePurseAngel(pPurse); // We'll unset this in success case, so it doesn't delete the purse we're returning.
	// -----------------------------------------------------
    OTPassword thePassword; // Only used in the case of password-protected purses.
	// -----------------------------------------------------
    // What's going on here?
    // A purse can be encrypted by a private key (controlled by a Nym) or by a symmetric
    // key (embedded inside the purse along with a corresponding master key.) The below
    // function is what actually loads up pPurse from string (THE_PURSE) and this call
    // also returns pOwner, which is a pointer to a special wrapper class (which you must
    // delete, when you're done with it) which contains a pointer EITHER to the owner Nym
    // for that purse, OR to the "owner" symmetric key for that purse.
    //
    // This way, any subsequent purse operations can use pOwner, regardless of whether there
    // is actually a Nym inside, or a symmetric key. (None of the purse operations will care,
    // since they can use pOwner either way.)
    //
    OTNym_or_SymmetricKey * pOwner = this->LoadPurseAndOwnerFromString(SERVER_ID, ASSET_TYPE_ID,
                                                                       THE_PURSE, *pPurse, thePassword,
                                                                       false, //bForEncrypting=true by default, but Pop needs to decrypt.
                                                                       pOWNER_ID,
                                                                       &strReason1, &strReason2);
    OTCleanup<OTNym_or_SymmetricKey> theOwnerAngel(pOwner);
    // -----------------------------------------------------------------
    if (NULL == pOwner) return NULL; // This already logs, no need for more logs.
    // -----------------------------------------------------------------
    OTPurse * pReturnPurse = NULL;

    if (pPurse->IsEmpty())
        OTLog::vOutput(0, "%s: Failed attempt to pop; purse is empty.\n", szFunc);
    else
    {
        OTToken * pToken = pPurse->Pop(*pOwner);
        OTCleanup<OTToken> theTokenAngel(pToken);

        if (NULL == pToken)
            OTLog::vOutput(0, "%s: Failed popping a token from a "
                           "purse that supposedly had tokens on it...\n", szFunc);
        else
        {
            pReturnPurse = pPurse;
            thePurseAngel.SetCleanupTargetPointer(NULL); // We don't clean up the purse in the case where we're returning it.
        }
    }
    // -----------------------------------------------------------------
    return pReturnPurse;
    
    // NOTE: Caller must release/sign/save pReturnPurse, once this returns, in order to effect the change.
}


// -----------------------------------------------------


// Caller must delete.
OTPurse * OT_API::Purse_Empty(const OTIdentifier & SERVER_ID,
                              const OTIdentifier & ASSET_TYPE_ID,
                              const OTString     & THE_PURSE,
                              const OTString     * pstrDisplay/*=NULL*/)
{
	OT_ASSERT_MSG(m_bInitialized, "Not initialized; call OT_API::Init first.");
	// -----------------------------------------------------------------
    const char * szFunc = "OT_API::Purse_Empty";
    // -----------------------------------
    const OTString strReason((NULL == pstrDisplay) ? "Making an empty copy of a cash purse." : pstrDisplay->Get());
//  OTPasswordData thePWData(strReason);
    // -----------------------------------
    OTPurse * pPurse = OTPurse::PurseFactory(THE_PURSE, SERVER_ID, ASSET_TYPE_ID);
    
    if (NULL == pPurse)
    {
        OTLog::vOutput(0, "%s: Error: THE_PURSE is an empty string. Please pass a "
                       "real purse when calling this function.\n", szFunc);
        return NULL;
    }
	// -----------------------------------------------------
    pPurse->ReleaseTokens();
    // NOTE: Caller must release/sign/save pReturnPurse, once this returns, in order to effect the change.
    return pPurse;
}



// -----------------------------------------------------

/// Returns the PURSE after pushing a single token onto it.
///
/// NOTE: Caller must delete!
/// NOTE: Caller must sign/save in order to effect the change.
///
/// USER_ID can be NULL, **if** the purse is password-protected.
/// (It's just ignored in that case.) Otherwise MUST contain the NymID for
/// the Purse owner (necessary to encrypt the token.)
///
/// returns NULL if failure.
///
OTPurse * OT_API::Purse_Push(const OTIdentifier & SERVER_ID,
                             const OTIdentifier & ASSET_TYPE_ID,
                             const OTString     & THE_PURSE,
                             const OTString     & THE_TOKEN,
                             const OTIdentifier * pOWNER_ID/*=NULL*/, // This can be NULL, **IF** purse is password-protected. (It's just ignored in that case.) Otherwise MUST contain the NymID for the Purse owner (necessary to encrypt the token.)
                             const OTString     * pstrDisplay/*=NULL*/)
{
	OT_ASSERT_MSG(m_bInitialized, "Not initialized; call OT_API::Init first.");
	// -----------------------------------------------------------------
    const char * szFunc = "OT_API::Purse_Push";
    // -----------------------------------
    const OTString strReason1((NULL == pstrDisplay) ? "Enter your master passphrase for your wallet. (Purse_Push)" : pstrDisplay->Get());
    const OTString strReason2((NULL == pstrDisplay) ? "Enter the passphrase for this purse. (Purse_Push)"          : pstrDisplay->Get());
//  OTPasswordData thePWData(strReason);
    // -----------------------------------
	if (!THE_PURSE.Exists())
	{
		OTLog::vOutput(0, "%s: Purse does not exist.\n", szFunc);
		return NULL;
	}
	else if (!THE_TOKEN.Exists())
	{
		OTLog::vOutput(0, "%s: Token does not exist.\n", szFunc);
		return NULL;
	}
    // -----------------------------------
    OTString strToken(THE_TOKEN);
    OTToken * pToken = OTToken::TokenFactory(strToken, SERVER_ID, ASSET_TYPE_ID);
    OTCleanup<OTToken> theTokenAngel(pToken);
    
    if (NULL == pToken) // TokenFactory instantiates AND loads from string.
    {
		OTLog::vOutput(0, "%s: Unable to instantiate or load token from string:\n\n%s\n\n",
                       szFunc, THE_TOKEN.Get());
		return NULL;
    }
    // -----------------------------------
    OTPurse    * pPurse = new OTPurse(SERVER_ID, ASSET_TYPE_ID);
    OT_ASSERT(NULL != pPurse);
    OTCleanup<OTPurse> thePurseAngel(pPurse); // We'll unset this in success case, so it doesn't delete the purse we're returning.
	// -----------------------------------------------------
    OTPassword thePassword; // Only used in the case of password-protected purses.
	// -----------------------------------------------------
    // What's going on here?
    // A purse can be encrypted by a private key (controlled by a Nym) or by a symmetric
    // key (embedded inside the purse along with a corresponding master key.) The below
    // function is what actually loads up pPurse from string (THE_PURSE) and this call
    // also returns pOwner, which is a pointer to a special wrapper class (which you must
    // delete, when you're done with it) which contains a pointer EITHER to the owner Nym
    // for that purse, OR to the "owner" symmetric key for that purse.
    //
    // This way, any subsequent purse operations can use pOwner, regardless of whether there
    // is actually a Nym inside, or a symmetric key. (None of the purse operations will care,
    // since they can use pOwner either way.)
    //
    OTNym_or_SymmetricKey * pOwner = this->LoadPurseAndOwnerFromString(SERVER_ID, ASSET_TYPE_ID,
                                                                       THE_PURSE, *pPurse, thePassword,
                                                                       true, //bForEncrypting=true by default.
                                                                       pOWNER_ID,
                                                                       &strReason1, &strReason2);
    OTCleanup<OTNym_or_SymmetricKey> theOwnerAngel(pOwner);
    // -----------------------------------------------------------------
    if (NULL == pOwner) return NULL; // This already logs, no need for more logs.
    // -----------------------------------------------------------------
    OTPurse * pReturnPurse = NULL;

    const bool bPushed = pPurse->Push(*pOwner, *pToken);

    if (!bPushed)
        OTLog::vOutput(0, "%s: Failed pushing a token onto a purse.\n", szFunc);
    else
    {
        pReturnPurse = pPurse;
        thePurseAngel.SetCleanupTargetPointer(NULL); // We don't clean up the purse in the case where we're returning it.
    }
    // -----------------------------------------------------------------
    return pReturnPurse;
    
    // NOTE: Caller must release/sign/save pReturnPurse, once this returns, in order to effect the change.
}


// -----------------------------------------------------



bool OT_API::Wallet_ImportPurse(const OTIdentifier & SERVER_ID,
                                const OTIdentifier & ASSET_TYPE_ID,
                                const OTIdentifier & SIGNER_ID, // We must know the SIGNER_ID in order to know which "old purse" to load and merge into. The New Purse may have a different one, but its ownership will be re-assigned in that case, as part of the merging process, to SIGNER_ID. Otherwise the New Purse might be symmetrically encrypted (instead of using a Nym) in which case again, its ownership will be re-assigned from that key, to SIGNER_ID, as part of the merging process.
                                const OTString     & THE_PURSE,
                                const OTString     * pstrDisplay/*=NULL*/)
{
	OT_ASSERT_MSG(m_bInitialized, "Not initialized; call OT_API::Init first.");
	// -----------------------------------------------------------------
    const char * szFunc = "OT_API::Wallet_ImportPurse";
    // -----------------------------------
    OTString strPurseReason ((NULL == pstrDisplay) ? "Enter passphrase for purse being imported." : pstrDisplay->Get());
    OTPasswordData thePWDataWallet((NULL == pstrDisplay) ? OT_PW_DISPLAY : pstrDisplay->Get());
    // -----------------------------------
    OTPassword thePassword; // Only used in the case of password-protected purses.
	// -----------------------------------------------------
	OTPseudonym * pNym = this->GetOrLoadPrivateNym(SIGNER_ID, false, szFunc, &thePWDataWallet); // These copiously log, and ASSERT.
	if (NULL == pNym) return false;
	// By this point, pNym is a good pointer, and is on the wallet. (No need to cleanup.)
	// -----------------------------------------------------
    OTPurse    * pNewPurse = new OTPurse(SERVER_ID, ASSET_TYPE_ID);
    OT_ASSERT(NULL != pNewPurse);
    OTCleanup<OTPurse> theNewPurseAngel(pNewPurse);
	// -----------------------------------------------------
    // What's going on here?
    // A purse can be encrypted by a private key (controlled by a Nym) or by a symmetric
    // key (embedded inside the purse along with a corresponding master key.) The below
    // function is what actually loads up pPurse from string (THE_PURSE) and this call
    // also returns pOwner, which is a pointer to a special wrapper class (which you must
    // delete, when you're done with it) which contains a pointer EITHER to the owner Nym
    // for that purse, OR to the "owner" symmetric key for that purse.
    //
    // This way, any subsequent purse operations can use pOwner, regardless of whether there
    // is actually a Nym inside, or a symmetric key. (None of the purse operations will care,
    // since they can use pOwner either way.)
    //
    OTNym_or_SymmetricKey * pNewOwner = this->LoadPurseAndOwnerForMerge(THE_PURSE, *pNewPurse, thePassword,
                                                                        false, //bCanBePublic=false by default. (Private Nym must be loaded, if a nym is the owner.)
                                                                        &SIGNER_ID, // This can be NULL, **IF** purse is password-protected. (It's just ignored in that case.) Otherwise if it's Nym-protected, the purse will have a NymID on it already, which is what LoadPurseAndOwnerForMerge will try first. If not (it's optional), then SIGNER_ID is the ID it will try next, before failing altogether.
                                                                        &strPurseReason);
    OTCleanup<OTNym_or_SymmetricKey> theOwnerAngel(pNewOwner);
    // -----------------------------------------------------------------
    if (NULL == pNewOwner) return false; // This already logs, no need for more logs.
    // -----------------------------------------------------------------
    OTPurse * pOldPurse = this->LoadPurse(SERVER_ID, ASSET_TYPE_ID, SIGNER_ID);
	OTCleanup<OTPurse> theOldPurseAngel(pOldPurse);
    
	if (NULL == pOldPurse) // apparently there's not already a purse of this type, let's create it.
	{
		pOldPurse = new OTPurse(SERVER_ID, ASSET_TYPE_ID, SIGNER_ID);
		OT_ASSERT(NULL != pOldPurse);
		// ---------------------------------------
		theOldPurseAngel.SetCleanupTarget(*pOldPurse);
	}
    else if (!pOldPurse->VerifySignature(*pNym))
    {
        OTLog::vError("%s: Failed to verify signature on old purse. (Very strange...)\n", szFunc);
        return false;
    }
    // -----------------------------------------------------
	// By this point, the old purse has either been loaded, or created.
    // Let's make sure the server and asset ID match between the purses,
    // since they are now actually loaded up.
    //
    if (pOldPurse->GetServerID() != pNewPurse->GetServerID())
    {
        OTLog::vOutput(0, "%s: Failure: ServerIDs don't match between these two purses.\n", szFunc);
        return false;
    }
    // -----------------------------------------------------------
    else if (pOldPurse->GetAssetID() != pNewPurse->GetAssetID())
    {
        OTLog::vOutput(0, "%s: Failure: AssetIDs don't match between these two purses.\n", szFunc);
        return false;
    }
	// -----------------------------------------------------
    //
    // By this point, I have two owners, and two purses.
    //
    // NOTE: if I want to pass in a custom display string here, pNym could be replaced with
    // pOldOwner (an OTNym_or_SymmetricKey instance) which can contain that string.
    // (I'm referring to the string that contains the "reason" why the passphrase needs to
    // be entered, so it can be shown to the user on the passphrase dialog.)
    //
    if (pOldPurse->Merge(*pNym, // signer
                         *pNym, // old owner (must be private, if a nym.)
                         *pNewOwner, // new owner (must be private, if a nym.)
                         *pNewPurse)) // new purse (being merged into old.)
    {
        pOldPurse->ReleaseSignatures();
        pOldPurse->SignContract(*pNym);
        pOldPurse->SaveContract();
        // -------------------------------------------------
        return this->SavePurse(SERVER_ID, ASSET_TYPE_ID, SIGNER_ID, *pOldPurse);
    }
    else // Failed merge.
    {
        OTString   strNymID1, strNymID2;
        pNym->     GetIdentifier(strNymID1);
        pNewOwner->GetIdentifier(strNymID2);
        OTLog::vOutput(0, "%s: (OldNymID: %s.) (New Owner ID: %s.) Failure merging new "
                       "purse:\n\n%s\n\n", szFunc, strNymID1.Get(), strNymID2.Get(),
                       THE_PURSE.Get());
    }
	// -----------------------------------------------------
    return false;
}



// -----------------------------------------------------



// ALLOW the caller to pass a symmetric key here, instead of either Nym ID.
// We'll load it up and use it instead of a Nym. Update: make that a purse.
// These tokens already belong to specific purses, so just pass the purse here
//
// Done: Also, add a key cache with a timeout (similar to Master Key) where we can stash
// any already-loaded symmetric keys, and a thread wipes them out later. That way
// even if we have to load the key each time this func is called, we still avoid the
// user having to enter the passphrase more than once per timeout period.
//
// Done also: allow a "Signer ID" to be passed in here, since either owner could potentially
// now be a symmetric key.
//
// Caller must delete!
//
OTToken * OT_API::Token_ChangeOwner(const OTIdentifier & SERVER_ID,
                                    const OTIdentifier & ASSET_TYPE_ID,
                                    const OTString     & THE_TOKEN,
                                    const OTIdentifier & SIGNER_NYM_ID,
                                    const OTString     & OLD_OWNER, // Pass a NymID here, or a purse.
                                    const OTString     & NEW_OWNER, // Pass a NymID here, or a purse.
                                    const OTString     * pstrDisplay/*=NULL*/)
{
	OT_ASSERT_MSG(m_bInitialized, "Not initialized; call OT_API::Init first.");
	// -----------------------------------------------------------------
    const char * szFunc = "OT_API::Token_ChangeOwner";
	// -----------------------------------------------------
    OTString strWalletReason((NULL == pstrDisplay) ? "Enter your wallet's master passphrase. (Token_ChangeOwner.)" : pstrDisplay->Get());
    OTString strPurseReason ((NULL == pstrDisplay) ? "Enter the passphrase for this purse. (Token_ChangeOwner.)" : pstrDisplay->Get());
    OTPasswordData thePWDataWallet(strWalletReason);
	// -----------------------------------------------------
	OTPseudonym * pSignerNym = this->GetOrLoadPrivateNym(SIGNER_NYM_ID, false, szFunc, &thePWDataWallet); // These copiously log, and ASSERT.
	if (NULL == pSignerNym) return NULL;
	// By this point, pNym is a good pointer, and is on the wallet. (No need to cleanup.)
	// -----------------------------------------------------
    // ALL THE COMPLEXITY YOU SEE BELOW is mainly just about handling OLD_OWNER
    // and NEW_OWNER each as either a NymID or as a Purse (containing a symmetric key and
    // a corresponding master key.)
	// -----------------------------------------------------
    OTIdentifier oldOwnerNymID, newOwnerNymID; // if either owner is a Nym, the ID goes here.
    // ------------------------------
    OTPurse * pOldPurse = NULL;                // if the old owner is a Purse (symmetric+master key), the entire purse is loaded.
    OTCleanup<OTPurse> theOldPurseAngel;
    OTPassword theOldPassword;      // Only used in the case of password-protected purses.
    OTPseudonym *			pOldNym   = NULL;
    OTNym_or_SymmetricKey * pOldOwner = NULL;
    OTCleanup<OTNym_or_SymmetricKey> theOldOwnerAngel;
    // ------------------------------
    OTPurse * pNewPurse = NULL;                // if the new owner is a Purse (symmetric+master key), the entire purse is loaded.
    OTCleanup<OTPurse> theNewPurseAngel;
    OTPassword theNewPassword;      // Only used in the case of password-protected purses.
    OTPseudonym *			pNewNym   = NULL;
    OTNym_or_SymmetricKey * pNewOwner = NULL;
    OTCleanup<OTNym_or_SymmetricKey> theNewOwnerAngel;
    // ------------------------------
    const bool bOldOwnerIsPurse = OLD_OWNER.Contains("PURSE");
    const bool bNewOwnerIsPurse = NEW_OWNER.Contains("PURSE");
    // ********************************************************************************
    if (!bOldOwnerIsPurse) // The old owner is a NYM (public/private keys.)
    {
        oldOwnerNymID.SetString(OLD_OWNER);
        // -----------------------------------------------------
                                pOldNym = this->GetOrLoadPrivateNym(oldOwnerNymID, false, szFunc, &thePWDataWallet); // These copiously log, and ASSERT.
//      if (NULL == pOldNym)	pOldNym = this->GetOrLoadPublicNym(oldOwnerNymID, szFunc); // must be private, in order to decrypt the old token.
        if (NULL == pOldNym)	return NULL;
        // -----------------------------------------------------
        pOldOwner = new OTNym_or_SymmetricKey(*pOldNym, &strWalletReason);
        OT_ASSERT(NULL != pOldOwner);
        theOldOwnerAngel.SetCleanupTargetPointer(pOldOwner);
    }
    // -----------------------------------------------------
    else                  // The old owner is a PURSE (Symmetric/master keys, internal to that purse.)
    {
        pOldPurse = new OTPurse(SERVER_ID, ASSET_TYPE_ID);
        OT_ASSERT(NULL != pOldPurse);
        theOldPurseAngel.SetCleanupTargetPointer(pOldPurse);
        // -----------------------------------------------------
        pOldOwner = this->LoadPurseAndOwnerForMerge(OLD_OWNER, *pOldPurse, theOldPassword,
                                                    false, //bCanBePublic=false by default. In this case, it definitely must be private.
                                                    &SIGNER_NYM_ID, // This can be NULL, **IF** purse is password-protected. (It's just ignored in that case.) Otherwise if it's Nym-protected, the purse will have a NymID on it already, which is what LoadPurseAndOwnerForMerge will try first. If not (it's optional), then SIGNER_NYM_ID is the ID it will try next, before failing altogether. ADDITIONAL NOTE: We don't expect the purse to ever be Nym-based since in this function, we pass a purse in order to pass the symmetric and master keys. Otherwise if this token's owner was already a Nym, then we would have passed a NymID in here, instead of a purse, in the first place.
                                                    &strPurseReason);
        theOldOwnerAngel.SetCleanupTargetPointer(pOldOwner);
        // -----------------------------------------------------------------
        if (NULL == pOldOwner) return NULL; // This already logs, no need for more logs.
        // -----------------------------------------------------------------
    }
    // ********************************************************************************
    if (!bNewOwnerIsPurse) // The new owner is a NYM
    {
        newOwnerNymID.SetString(NEW_OWNER);
        // -----------------------------------------------------
        pNewNym = this->GetOrLoadNym(newOwnerNymID, false, szFunc, &thePWDataWallet); // These copiously log, and ASSERT.
        if (NULL == pNewNym)	return NULL;
        // -----------------------------------------------------
        pNewOwner = new OTNym_or_SymmetricKey(*pNewNym, &strWalletReason);
        OT_ASSERT(NULL != pNewOwner);
        theNewOwnerAngel.SetCleanupTargetPointer(pNewOwner);
    }
    // -----------------------------------------------------
    else                   // The new owner is a PURSE
    {
        pNewPurse = new OTPurse(SERVER_ID, ASSET_TYPE_ID);
        OT_ASSERT(NULL != pNewPurse);
        theNewPurseAngel.SetCleanupTargetPointer(pNewPurse);
        // -----------------------------------------------------
        pNewOwner = this->LoadPurseAndOwnerForMerge(NEW_OWNER, *pNewPurse, theNewPassword,
                                                    true, //bCanBePublic=false by default, but set TRUE here, since you SHOULD be able to re-assign ownership of a token to someone else, without having to load their PRIVATE key (which you don't have.) Sort of irrelevant here actually, since this block is for purses only...
                                                    &SIGNER_NYM_ID, // This can be NULL, **IF** purse is password-protected. (It's just ignored in that case.) Otherwise if it's Nym-protected, the purse will have a NymID on it already, which is what LoadPurseAndOwnerForMerge will try first. If not (it's optional), then SIGNER_NYM_ID is the ID it will try next, before failing altogether. ADDITIONAL NOTE: We don't expect the purse to ever be Nym-based since in this function, we pass a purse in order to pass the symmetric and master keys. Otherwise if this token's owner was already a Nym, then we would have passed a NymID in here, instead of a purse, in the first place.
                                                    &strPurseReason);
        theNewOwnerAngel.SetCleanupTargetPointer(pNewOwner);
        // -----------------------------------------------------------------
        if (NULL == pNewOwner) return NULL; // This already logs, no need for more logs.
        // -----------------------------------------------------------------
    }
    // ********************************************************************************
    //
    // (By this point, pOldOwner and pNewOwner should both be good to go.)
    //
    // -----------------------------------------------------------------
    OTToken * pToken = OTToken::TokenFactory(THE_TOKEN, SERVER_ID, ASSET_TYPE_ID);
    OTCleanup<OTToken> theTokenAngel(pToken);
    OT_ASSERT(NULL != pToken);
    // -----------------------------------------------------
    if (false == pToken->ReassignOwnership(*pOldOwner,  // must be private, if a Nym.
                                           *pNewOwner)) // can be public, if a Nym.
    {
        OTLog::vError("%s: Error re-assigning ownership of token.\n",
                      szFunc);
    }
    else 
    {
        OTLog::vOutput(3, "%s: Success re-assigning ownership of token.\n",
                       szFunc);
        
        pToken->ReleaseSignatures();
        pToken->SignContract(*pSignerNym);
        pToken->SaveContract();
        
        theTokenAngel.SetCleanupTargetPointer(NULL); // so pToken doesn't get deleted, since we're returning it here.
        return pToken;
    }
	
	return NULL;
}





// -----------------------------------------------------


// LOAD Mint
//
// Returns an OTMint pointer, or NULL. 
// (Caller responsible to delete.)
//
OTMint * OT_API::LoadMint(const OTIdentifier & SERVER_ID,
						  const OTIdentifier & ASSET_ID)
{	
	const char * szFunc = "OT_API::LoadMint";
	// -----------------------------------------------------
	const OTString strServerID(SERVER_ID);
	const OTString strAssetTypeID(ASSET_ID);
	// -------------------------------------------------------------
	OTServerContract	* pServerContract	= this->GetServer(SERVER_ID, szFunc);
	if (NULL == pServerContract) return NULL;
	// -------------------------------------------------------------		
	const OTPseudonym	* pServerNym		= pServerContract->GetContractPublicNym();
	if (NULL == pServerNym)
	{
		OTLog::vError("%s: Failed trying to get contract public Nym for ServerID: %s \n",
					  szFunc, strServerID.Get());
		return NULL;
	}
	// -------------------------------------------------------------
	OTMint * pMint = OTMint::MintFactory(strServerID, strAssetTypeID);
	OT_ASSERT_MSG(NULL != pMint, "OT_API::LoadMint: Error allocating memory in the OT API"); 
	// responsible to delete or return pMint below this point.
	// -------------------------------------------------------------
	if (!pMint->LoadMint() || !pMint->VerifyMint(*pServerNym))
	{
		OTLog::vOutput(0, "%s: Unable to load or verify Mintfile : %s%s%s%s%s\n", szFunc,
					   OTFolders::Mint().Get(), OTLog::PathSeparator(), strServerID.Get(),
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

	OTString strFoldername	= OTFolders::Contract().Get();
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
	
	OTString strFoldername	= OTFolders::Contract().Get();
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
	const char * szFuncName = __FUNCTION__;
	// -----------------------------------------------------
	OTWallet * pWallet = this->GetWallet(szFuncName); // This logs and ASSERTs already.
	if (NULL == pWallet) return NULL;
	// By this point, pWallet is a good pointer.  (No need to cleanup.)
	// -----------------------------------------------------
	OTPseudonym * pNym = this->GetOrLoadPrivateNym(USER_ID, false, szFuncName);
	if (NULL == pNym) return NULL;
	// By this point, pNym is a good pointer, and is on the wallet. (No need to cleanup.)
	// -----------------------------------------------------
	return pWallet->LoadAccount(*pNym, ACCOUNT_ID, SERVER_ID, szFuncName);	
}


// ---------------------------------------------------

// LOAD NYMBOX
//
// Caller IS responsible to delete
//
OTLedger * OT_API::LoadNymbox(const OTIdentifier & SERVER_ID,
							  const OTIdentifier & USER_ID)
{
	const char * szFuncName = __FUNCTION__;
	// -----------------------------------------------------
	OTPseudonym * pNym = this->GetOrLoadPrivateNym(USER_ID, false, szFuncName);
	if (NULL == pNym) return NULL;
	// By this point, pNym is a good pointer, and is on the wallet. (No need to cleanup.)
	// -----------------------------------------------------
	OTLedger * pLedger = OTLedger::GenerateLedger(USER_ID, USER_ID, SERVER_ID, OTLedger::nymbox);
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
	OTPseudonym * pNym = this->GetOrLoadPrivateNym(USER_ID, false, szFuncName);
	if (NULL == pNym) return NULL;
	// By this point, pNym is a good pointer, and is on the wallet. (No need to cleanup.)
	// -----------------------------------------------------
	OTLedger * pLedger = OTLedger::GenerateLedger(USER_ID, USER_ID, SERVER_ID, OTLedger::nymbox);
	OT_ASSERT_MSG(NULL != pLedger, "OT_API::LoadNymboxNoVerify: Error allocating memory in the OT API.");
	// Beyond this point, I know that pLedger will need to be deleted or returned.
	// ------------------------------------------------------
	if (pLedger->LoadNymbox()) // The Verify would go here.
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
	OTPseudonym * pNym = this->GetOrLoadPrivateNym(USER_ID, false, szFuncName);
	if (NULL == pNym) return NULL;
	// By this point, pNym is a good pointer, and is on the wallet. (No need to cleanup.)
	// -----------------------------------------------------
    OTLedger * pLedger = OTLedger::GenerateLedger(USER_ID, ACCOUNT_ID, SERVER_ID, OTLedger::inbox);
	OT_ASSERT_MSG(NULL != pLedger, "OT_API::LoadInbox: Error allocating memory in the OT API.");
	
	// Beyond this point, I know that pLedger will need to be deleted or returned.
	// ------------------------------------------------------
	if (pLedger->LoadInbox() && pLedger->VerifyAccount(*pNym))
		return pLedger;
	else
	{
		OTString strUserID(USER_ID), strAcctID(ACCOUNT_ID);
		OTLog::vOutput(1, "OT_API::LoadInbox: Unable to load or verify inbox: %s\n For user: %s\n",
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
	OTPseudonym * pNym = this->GetOrLoadPrivateNym(USER_ID, false, szFuncName);
	if (NULL == pNym) return NULL;
	// By this point, pNym is a good pointer, and is on the wallet. (No need to cleanup.)
	// -----------------------------------------------------
    OTLedger * pLedger = OTLedger::GenerateLedger(USER_ID, ACCOUNT_ID, SERVER_ID, OTLedger::inbox);
	OT_ASSERT_MSG(NULL != pLedger, "OT_API::LoadInboxNoVerify: Error allocating memory in the OT API.");
	
	// Beyond this point, I know that pLedger will need to be deleted or returned.
	// ------------------------------------------------------
	if (pLedger->LoadInbox()) // The Verify would go here.
		return pLedger;
	else
	{
		OTString strUserID(USER_ID), strAcctID(ACCOUNT_ID);
		OTLog::vOutput(1, "OT_API::LoadInboxNoVerify: Unable to load inbox: %s\n For user: %s\n",
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
	OTPseudonym * pNym = this->GetOrLoadPrivateNym(USER_ID, false, szFuncName);
	if (NULL == pNym) return NULL;
	// By this point, pNym is a good pointer, and is on the wallet. (No need to cleanup.)
	// -----------------------------------------------------
    OTLedger * pLedger = OTLedger::GenerateLedger(USER_ID, ACCOUNT_ID, SERVER_ID, OTLedger::outbox);
	OT_ASSERT_MSG(NULL != pLedger, "OT_API::LoadOutbox: Error allocating memory in the OT API.");
	
	// Beyond this point, I know that pLedger is loaded and will need to be deleted or returned.
	// ------------------------------------------------------
	
	if (pLedger->LoadOutbox() && pLedger->VerifyAccount(*pNym))
		return pLedger;
	else
	{
		OTString strUserID(USER_ID), strAcctID(ACCOUNT_ID);
		
		OTLog::vOutput(1, "OT_API::LoadOutbox: Unable to load or verify outbox: %s\n For user: %s\n",
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
	OTPseudonym * pNym = this->GetOrLoadPrivateNym(USER_ID, false, szFuncName);
	if (NULL == pNym) return NULL;
	// By this point, pNym is a good pointer, and is on the wallet. (No need to cleanup.)
	// -----------------------------------------------------
    OTLedger * pLedger = OTLedger::GenerateLedger(USER_ID, ACCOUNT_ID, SERVER_ID, OTLedger::outbox);
	OT_ASSERT_MSG(NULL != pLedger, "OT_API::LoadOutboxNoVerify: Error allocating memory in the OT API.");
	
	// Beyond this point, I know that pLedger is loaded and will need to be deleted or returned.
	// ------------------------------------------------------
	
	if (pLedger->LoadOutbox()) // The Verify would go here.
		return pLedger;
	else
	{
		OTString strUserID(USER_ID), strAcctID(ACCOUNT_ID);
		OTLog::vOutput(1, "OT_API::LoadOutboxNoVerify: Unable to load outbox: %s\n For user: %s\n",
					   strAcctID.Get(), strUserID.Get());
		
		delete pLedger;
		pLedger = NULL;		
	}
	return  NULL;
}



// ***************************************************************************



OTLedger * OT_API::LoadPaymentInbox(const OTIdentifier & SERVER_ID,
									const OTIdentifier & USER_ID)
{
	const char * szFuncName = "OT_API::LoadPaymentInbox";
	// -----------------------------------------------------
	OTPseudonym * pNym = this->GetOrLoadPrivateNym(USER_ID, false, szFuncName);
	if (NULL == pNym) return NULL;
	// By this point, pNym is a good pointer, and is on the wallet. (No need to cleanup.)
	// -----------------------------------------------------
    OTLedger * pLedger = OTLedger::GenerateLedger(USER_ID, USER_ID, SERVER_ID, OTLedger::paymentInbox);
	OT_ASSERT_MSG(NULL != pLedger, "OT_API::LoadPaymentInbox: Error allocating memory in the OT API.");
	// Beyond this point, I know that pLedger will need to be deleted or returned.
	// ------------------------------------------------------
	if (pLedger->LoadPaymentInbox() && pLedger->VerifyAccount(*pNym))
		return pLedger;
	else
	{
		OTString strUserID(USER_ID), strAcctID(USER_ID);
		OTLog::vOutput(1, "%s: Unable to load or verify: %s / %s\n",
					   szFuncName, strUserID.Get(), strAcctID.Get());
		delete pLedger;
		pLedger = NULL;		
	}
	return  NULL;
}


OTLedger * OT_API::LoadPaymentInboxNoVerify(const OTIdentifier & SERVER_ID,
											const OTIdentifier & USER_ID)
{
	const char * szFuncName = "OT_API::LoadPaymentInboxNoVerify";
	// -----------------------------------------------------
	OTPseudonym * pNym = this->GetOrLoadPrivateNym(USER_ID, false, szFuncName);
	if (NULL == pNym) return NULL;
	// By this point, pNym is a good pointer, and is on the wallet. (No need to cleanup.)
	// -----------------------------------------------------
    OTLedger * pLedger = OTLedger::GenerateLedger(USER_ID, USER_ID, SERVER_ID, OTLedger::paymentInbox);
	OT_ASSERT_MSG(NULL != pLedger, "OT_API::LoadPaymentInboxNoVerify: Error allocating memory in the OT API.");
	// Beyond this point, I know that pLedger will need to be deleted or returned.
	// ------------------------------------------------------
	if (pLedger->LoadPaymentInbox()) // The Verify would have gone here.
		return pLedger;
	else
	{
		OTString strUserID(USER_ID), strAcctID(USER_ID);
		OTLog::vOutput(1, "%s: Unable to load or verify: %s / %s\n",
					   szFuncName, strUserID.Get(), strAcctID.Get());
		delete pLedger;
		pLedger = NULL;
	}
	return  NULL;			
}



// Caller IS responsible to delete
//
OTLedger * OT_API::LoadRecordBox(const OTIdentifier & SERVER_ID,
								 const OTIdentifier & USER_ID,
								 const OTIdentifier & ACCOUNT_ID)
{
	const char * szFuncName = "OT_API::LoadRecordBox";
	// -----------------------------------------------------
	OTPseudonym * pNym = this->GetOrLoadPrivateNym(USER_ID, false, szFuncName);
	if (NULL == pNym) return NULL;

	// By this point, pNym is a good pointer, and is on the wallet. (No need to cleanup.)
	// -----------------------------------------------------
    OTLedger * pLedger = OTLedger::GenerateLedger(USER_ID, ACCOUNT_ID, SERVER_ID, OTLedger::recordBox);
	OT_ASSERT_MSG(NULL != pLedger, "OT_API::LoadRecordBox: Error allocating memory in the OT API.");
	// Beyond this point, I know that pLedger will need to be deleted or returned.
	// ------------------------------------------------------
    const bool bLoaded = pLedger->LoadRecordBox();
    
    bool bVerified = false;
    
    if (bLoaded)
        bVerified = pLedger->VerifyAccount(*pNym);
    
	if (bLoaded && bVerified)
		return pLedger;
	else
	{
		OTString strUserID(USER_ID), strAcctID(ACCOUNT_ID);
		OTLog::vOutput(1, "%s: Unable to load or verify: %s / %s\n",
					   szFuncName, strUserID.Get(), strAcctID.Get());
		delete pLedger;
		pLedger = NULL;
	}
	return  NULL;	
}


OTLedger * OT_API::LoadRecordBoxNoVerify(const OTIdentifier & SERVER_ID,
										 const OTIdentifier & USER_ID,
										 const OTIdentifier & ACCOUNT_ID)
{
	const char * szFuncName = "OT_API::LoadRecordBoxNoVerify";
	// -----------------------------------------------------
	OTPseudonym * pNym = this->GetOrLoadPrivateNym(USER_ID, false, szFuncName);
	if (NULL == pNym) return NULL;
	// By this point, pNym is a good pointer, and is on the wallet. (No need to cleanup.)
	// -----------------------------------------------------
    OTLedger * pLedger = OTLedger::GenerateLedger(USER_ID, ACCOUNT_ID, SERVER_ID, OTLedger::recordBox);
	OT_ASSERT_MSG(NULL != pLedger, "OT_API::LoadRecordBoxNoVerify: Error allocating memory in the OT API.");
	// Beyond this point, I know that pLedger will need to be deleted or returned.
	// ------------------------------------------------------
	if (pLedger->LoadRecordBox()) // The Verify would have gone here.
		return pLedger;
	else
	{
		OTString strUserID(USER_ID), strAcctID(ACCOUNT_ID);
		OTLog::vOutput(1, "%s: Unable to load or verify: %s / %s\n",
					   szFuncName, strUserID.Get(), strAcctID.Get());
		delete pLedger;
		pLedger = NULL;
	}
	return  NULL;	
}


// From OTAPI.cpp:
//
//int				OT_API_GetNym_OutpaymentsCount(const char * NYM_ID);
//
//const char *	OT_API_GetNym_OutpaymentsContentsByIndex(const char * NYM_ID, int nIndex); /// returns the message itself
//
//const char *	OT_API_GetNym_OutpaymentsRecipientIDByIndex(const char * NYM_ID, int nIndex); /// returns the NymID of the recipient.
//const char *	OT_API_GetNym_OutpaymentsServerIDByIndex(const char * NYM_ID, int nIndex); /// returns the ServerID where the message came from.
//
//int				OT_API_Nym_RemoveOutpaymentsByIndex(const char * NYM_ID, int nIndex); /// actually returns OT_BOOL, (1 or 0.)
//int				OT_API_Nym_VerifyOutpaymentsByIndex(const char * NYM_ID, int nIndex); /// actually returns OT_BOOL. OT_TRUE if signature verifies. (Sender Nym MUST be in my wallet for this to work.)



// If you write a cheque, a copy should go in outpayments box.
// If you SEND a cheque, a copy should go in your outpayments box. (Perhaps just replacing the first one.)
// Once that cheque is CASHED, the copy should be removed from the outpayments. (Copied to record box.)
//
// If the cheque is discarded by sender, it can be moved in the same fashion. But the critical difference
// is, the recipient MIGHT still have a copy of it, and thus MIGHT still run it through, unless you take
// that discarded number and use it on another server transaction or cancel it somehow. Normally you'd just
// harvest the number for some other transaction (which the "discard cheque" function actually does) but if
// I think about it, that cheque can still come through, meanwhile I'm thinking the transaction # is available
// still to be attached to some other cheque (at least as far as my wallet can tell, if I've harvested the number
// by this point.) My wallet will think the server is trying to screw me somehow, since it apparently hasn't
// even USED that number yet on a subsequent transaction, yet here's the server claiming it's already used and
// funds were deducted!
// Therefore we MUST (todo) add the functionality to cancel a transaction number!
// TODO: Need a server message for canceling a transaction.
// IF there are no receipts in your inbox or outbox regarding a transaction #,
// then you can cancel it. (Hmm re-think: Is that possible? What if I have a
// transaction # out there on a smart contract somewhere -- that someone ELSE
// activated? Then how would I find it? Perhaps server-side Nym needs to track
// that...)
//
// Really, if a cheque receipt comes through, and we accept it out of the inbox, then the "SUCCESS"
// reply for that processInbox is where we need to remove the corresponding outpayments entry and move
// it to the record box.
//
// Similarly, if a cheque is canceled (transaction # is canceled) then we should receive a "SUCCESS" reply
// (to that cancel transaction) and again, remove the corresponding outpayments entry and move it to the
// record box.
//
//
/*
 - In my Payments Inbox, there could be a cheque or invoice. Either way, when I deposit the cheque or
 pay the invoice, the chequeReceipt goes back to the signer's asset account's inbox.
 - When he accepts the chequeReceipt (during a processInbox) and WHEN HE GETS THE "SUCCESS" REPLY to that
 processInbox, is when the chequeReceipt should be moved from his inbox to his record box. It MUST be
 done then, inside OT, because the next time he downloads the inbox from the server, that chequeReceipt
 won't be in there anymore! It'll be too late to pass it on to the records.
 - Whereas I, being the recipient of his cheque, had it in my **payments inbox,** and thus upon receipt
 of a successful server-reply to my deposit transaction, need to move it from my payments inbox to my
 record box. (The record box will eventually be a callback so that client software can take over that
 functionality, which is outside the scope of OT. The actual CALL to store in the record box, however
 should occur inside OT.)
 - For now, I'm using the below API call, so it's available inside the scripts. This is "good enough"
 for now, just to get the payments inbox/outbox working for the scripts. But in the long term, I'll need
 to add the hooks directly into OT as described just above. (It'll be necessary in order to get the record
 box working.)
 - Since I'm only worried about Payments Inbox for now, and since I'll be calling the below function
 directly from inside the scripts, how will this work? Incoming cheque or invoice will be in the payments
 inbox, and will need to be moved to recordBox (below call) when the script receives a success reply to
 the depositing/paying of that cheque/invoice.
 - Whereas outoing cheque/invoice is in the Outpayments box, (fundamentally more similar to the outmail
 box than to the payments inbox.) If the cheque/invoice is cashed/paid by the endorsee, **I** will receive
 the chequeReceipt, in MY asset account inbox, and when I accept it during a processInbox transaction,
 the SUCCESS REPLY from the server for that processInbox is where I should actually process that chequeReceipt
 and, if it appears in the outpayments box, move it at that time to the record box. The problem is, I can NOT
 do this much inside the script. To do this part, I thus HAVE to go into OT itself as I just described.
 - Fuck!
 - Therefore I might as well comment this out, since this simply isn't going to work.
 
 
 
 - Updated plan:
   1. DONE: Inside OT, when processing successful server reply to processInbox request, if a chequeReceipt
      was processed out successfully, and if that cheque is found inside the outpayments, then
      move it at that time to the record box.
   2. DONE: Inside OT, when processing successful server reply to depositCheque request, if that cheque is
      found inside the Payments Inbox, move it to the record box.
   3. As for cash:
        If I SENT cash, it will be in my outpayments box. But that's wrong. Because I can
      never see if the guy cashed it or not. Therefore it should go straight to the record box, when
      sent. AND it needs to be encrypted to MY key, not his -- so need to generate BOTH versions, when
      exporting the purse to him in the FIRST PLACE. Then my version goes straight into my record box and
      I can delete it at my leisure. (If he comes running the next day saying "I lost it!!" I can still 
      recover it. But once he deposits it, then the cash will be no good and I might as well archive it
      or destroy it, or whatever I choose to do with my personal records.)
        If I RECEIVED cash, it will be in my payments inbox, and then when I deposit it, and when I process
      the SUCCESSFUL server REPLY to my depositCash request, it should be moved to my record Box.
   4. How about vouchers? If I deposit a voucher, then the "original sender" should get some sort of
      notice. This means attaching his ID to the voucher--which should be optional--and then dropping an
      "FYI" notice to him when it gets deposited. It can't be a normal chequeReceipt because that's used
      to verify the balance agreement against a balance change, whereas a "voucher receipt" wouldn't represent
      a balance change at all, since the balance was already changed when you originally bought the voucher.
      Instead it would probably be sent to your Nymbox but it COULD NOT BE PROVEN that it was, since OT currently
      can't prove NOTICE!! Nevertheless, in the meantime, OT Server should still drop a notice in the Nymbox
      of the original sender which is basically a "voucher receipt" (containing the voucher but interpreted
      as a receipt and not as a payment instrument.) 
        How about this===> when such a receipt is received, instead of moving it to the payments inbox like
      we would with invoices/cheques/purses we'll just move it straight to the record box instead.
 
 All of the above needs to happen inside OT, since there are many places where it's the only appropriate
 place to take the necessary action. (Script cannot.)
 
 */


// So far I haven't needed this yet, since sent and received payments already handle moving
// payments-inbox receipts to the record box, and moving outpayments instruments to the
// record box (built into OT.) But finally a case occured: the instrument is expired, so OT
// will never move it, since OT can never deposit it, in the case of incoming payments, and
// in the case of outgoing payments, clearly the recipient never deposited it, or I would have
// gotten a receipt by now and it would have already been cleared out of my outpayments box.
// Since neither of those cases will ever happen, for an expired instrument, then how in the heck
// do I get that damned instrument out of my outpayments / payments inbox, and moved over to
// the record box so the client software can deal with it? Answer: this API call: OT_API::RecordPayment
//
// ONE MORE THING: Let's say I sent a cheque and it expired. The recipient never cashed it.
// At this point, I am SAFE to harvest the transaction number(s) back off of the cheque. After
// all, it was never cashed, right? And since it's now expired, it never WILL be cashed, right?
// Therefore I NEED to harvest the transaction number back from the expired instrument, so I can
// use it again in the future and eventually get it closed out.
//
//
bool OT_API::RecordPayment(const OTIdentifier & SERVER_ID,
                           const OTIdentifier & USER_ID,
                           bool    bIsInbox, // true == payments inbox. false == payments outbox.
                           int32_t nIndex)   // removes payment instrument (from payments in or out box) and moves to record box.
{
	OTPseudonym * pNym = this->GetOrLoadPrivateNym(USER_ID, false, __FUNCTION__);
	if (NULL == pNym) return false;
	// By this point, pNym is a good pointer, and is on the wallet. (No need to cleanup.)
	// -----------------------------------------------------    
    OTLedger  * pRecordBox = this->LoadRecordBox (SERVER_ID, USER_ID, USER_ID);
	// -----------------------------------------------------
    if (NULL == pRecordBox)
    {
        pRecordBox = OTLedger::GenerateLedger(USER_ID, USER_ID, SERVER_ID, OTLedger::recordBox, true);
        
        if (NULL == pRecordBox)
        {
            OTLog::vError("%s: Unable to load or create record box (and thus unable to do anything with it.)\n",
                          __FUNCTION__);
            return false;
        }
    }
	// -----------------------------------------------------
    OTCleanup<OTLedger> theRecordBoxAngel (pRecordBox);
	// -----------------------------------------------------
    OTLedger * pPaymentInbox  = NULL;
    OTCleanup<OTLedger> thePaymentBoxAngel;

    //first block:
    OTTransaction * pTransaction = NULL;
    OTCleanup<OTTransaction> theTransactionAngel;
    
    //second block:
    OTMessage *	pMessage = NULL;
    OTCleanup<OTMessage> theMessageAngel;

    bool bRemoved = false, bNeedToSaveTheNym = false;
    
    if (bIsInbox)
    {
        pPaymentInbox  = this->LoadPaymentInbox (SERVER_ID, USER_ID);
        // -----------------------------------------------------
        thePaymentBoxAngel.SetCleanupTargetPointer(pPaymentInbox);
        // -----------------------------------------------------
        if (NULL == pPaymentInbox)
        {
            OTLog::vError("%s: Unable to load payment inbox (and thus unable to do anything with it.)\n",
                          __FUNCTION__);
            return false;
        }
        // -----------------------------------------------------
        //
        if ((nIndex < 0) || (nIndex >= pPaymentInbox->GetTransactionCount()))
        {
            OTLog::vError("%s: Unable to find transaction in payment inbox based on index %d. (Out of bounds.)\n",
                          __FUNCTION__, nIndex);
            return false;
        }
        // ---------------------
        pTransaction = pPaymentInbox->GetTransactionByIndex(nIndex);
        
        if (NULL == pTransaction)
        {
            OTLog::vError("%s: Unable to find transaction in payment inbox based on index %d.\n",
                          __FUNCTION__, nIndex);
            return false;
        }
        // -----------------------------------------------------
        // Move it from one box to the other...
        //
        
        
        // todo resume
        //
        // Do I need to delete the box receipt here when I remove the transaction?
        // I understand I'm moving the transaction to the record box, but I am calling
        // SaveBoxReceipt already for that version of it, so shouldn't I delete the one
        // we had before? Or does it overwrite it already? Make sure.
        
        
        bRemoved = pPaymentInbox->RemoveTransaction(pTransaction->GetTransactionNum(), false); // bDeleteIt=true by default. We pass false since we are moving it to another box. Note that we still need to save pPaymentInbox somewhere below, assuming it's all successful.
        theTransactionAngel.SetCleanupTargetPointer(pTransaction); // If below we put pTransaction onto the Record Box, then we have to set this to NULL.
        
        
        // anything else?
        // Note: no need to harvest transaction number for incoming payments.
        // But for outgoing (see below) then harvesting becomes an issue.
        
    }
    else // Outpayments box (which is not stored in an OTLedger like payments inbox, but rather, is stored similarly to outmail.)
    {
        // -----------------------------------------------------
        //
        if ((nIndex < 0) || (nIndex >= pNym->GetOutpaymentsCount()))
        {
            OTLog::vError("%s: Unable to find payment in outpayment box based on index %d. (Out of bounds.)\n",
                          __FUNCTION__, nIndex);
            return false;
        }
        // ---------------------
        pMessage = pNym->GetOutpaymentsByIndex(nIndex);
        
        if (NULL == pMessage)
        {
            OTLog::vError("%s: Unable to find payment message in outpayment box based on index %d.\n",
                          __FUNCTION__, nIndex);
            return false;
        }
        // ---------------------
        OTString strInstrument;
        if (!pMessage->m_ascPayload.GetString(strInstrument))
        {
            OTLog::vError("%s: Unable to find payment instrument in outpayment message at index %d.\n",
                          __FUNCTION__, nIndex);
            return false;
        }
        // ---------------------
        OTPayment  thePayment(strInstrument);
        long       lPaymentTransNum = 0;
        
        if (thePayment.IsValid() && thePayment.SetTempValues() && thePayment.GetTransactionNum(lPaymentTransNum))
        {
            // See what account the payment instrument is drawn from.
            // Is it mine?
            // If so, load up the inbox and see if there are any related receipts inside.
            // If so, do NOT harvest the transaction numbers from the instrument.
            // Otherwise, harvest them. (The instrument hasn't been redeemed yet.)
            // Also, use the transaction number on the instrument to see if it's signed out to me.
            //
            // Hmm: If the instrument is definitely expired, and there's definitely nothing in the inbox,
            // then I can DEFINITELY harvest it back.
            //
            // But if the instrument is definitely NOT expired, and the transaction # IS signed out to ME,
            // then I can't just harvest the numbers, since the original recipient could still come through
            // and deposit that cheque.  So in this case, I would HAVE to cancel the transaction, and then
            // such cancellation would automatically harvest while processing the successful server reply.
            //
            // Therefore make sure not to move the instrument here, unless it's definitely expired.
            // Whereas if it's not expired, then the API must cancel it with the server, and can't simply
            // come in here and move/harvest it. So this function can only be for expired transactions or
            // those where the transaction number is no longer issued. (And in cases where it's expired but
            // STILL issued, then it definitely DOES need to harvest.)
            //
            
            bool bShouldHarvestPayment     = false;
            bool bNeedToLoadAssetAcctInbox = false;
            bool bIsIssued                 = false;
            // ----------------------
            time_t tValidFrom = 0, tValidTo = 0, tCurrentTime = static_cast<time_t>(this->GetTime());
            thePayment.GetValidFrom(tValidFrom);
            thePayment.GetValidTo  (tValidTo  );
            
            const bool bIsExpired = (tCurrentTime > tValidTo);
            // ----------------------------------------------------------------
            OTIdentifier theSenderUserID, theSenderAcctID;

            const bool bPaymentSenderIsNym  = (thePayment.GetSenderUserID(theSenderUserID) && pNym->CompareID(theSenderUserID));
            const bool bFromAcctIsAvailable =  thePayment.GetSenderAcctID(theSenderAcctID);
            // ----------------------------------------------------------------
            if (bPaymentSenderIsNym)
            {
                const OTString strServerID(SERVER_ID);
                
                // If the transaction # isn't signed out to me, then there's no need to check the inbox
                // for any receipts, since those would have to have been already closed out, in order for
                // the number not to be signed out to me anymore.
                //
                // Therefore let's check that first, before bothering to load the inbox.
                //
                if (pNym->VerifyTentativeNum(strServerID, lPaymentTransNum))   // If I'm in the middle of trying to sign it out...
                {
                    OTLog::vError("%s: Error: Why on earth is this transaction number (%ld) on an outgoing payment instrument, if it's still on my 'Tentative' list? If I haven't even signed out that number, how did I send an instrument to someone else with that number on it?\n", __FUNCTION__, lPaymentTransNum);
                    return false;
                }
                // ---------------------------                
                bIsIssued = pNym->VerifyIssuedNum(strServerID, lPaymentTransNum);

                // If pNym is the sender AND the payment instrument IS expired.
                //
                if (bIsExpired)
                {
                    if (bIsIssued)  // ...and if this number is still signed out to pNym...
                    {
                        // If the instrument is definitely expired, and its number is still issued to pNym, and
                        // there's definitely no related chequeReceipts in the asset acocunt inbox, then I
                        // can DEFINITELY harvest it back. After all, it hasn't been used, and since it's
                        // expired, now it CAN'T be used. So might as well harvest the number back, since we've
                        // established that it's still signed out.
                        //
                        // You might ask, but what if there IS a chequeReceipt in the asset account inbox? How
                        // does that change things? The answer is, because the transaction # might still be signed
                        // out to me, even in a case where the payment instrument is expired, but a chequeReceipt
                        // still IS present! How so? Simple: I sent him the cheque, he cashed it. It's in my outpayments
                        // still, because his chequeReceipt is in my inbox still, and hasn't been processed out.
                        // Meanwhile I wait a few weeks, and then the instrument, meanwhile, expires. It's already
                        // been processed, so it doesn't matter that it's expired. But nonetheless, according to the
                        // dates affixed to it, it IS expired, and the receipt IS present. So this is clearly a
                        // realistic and legitimate case for our logic to take into account. When this happens, we
                        // should NOT harvest the transaction # back when recording the payment, because that number
                        // has been used already!
                        //
                        // That, in a nutshell, is why we have to load the inbox and see if that receipt's there,
                        // to MAKE SURE whether the instrument was negotiated already, before it expired, even though
                        // I haven't accepted the receipt and closed out the transaction # yet, because it impacts
                        // our decision of whether or not to harvest back the number.
                        //
                        // The below two statements are interpreted based on this logic (see comment for each.)
                        //
                        bShouldHarvestPayment     = true;  // If no chequeReceipt in inbox, definitely should harvest back the trans # (since the cheque's expired and could never otherwise be closed out)...
                        bNeedToLoadAssetAcctInbox = true;  // ...unless chequeReceipt IS in inbox, definitely should NOT harvest back the # (since it's already been used.)
                        //
                        // =====> Therefore bNeedToLoadAssetAcctInbox is a caveat, which OVERRIDES bShouldHarvestPayment. <=====
                    }
                    else // pNym is sender, payment instrument IS expired, and most importantly: the transaction # is no longer signed out
                    {    // to pNym. Normally the closing of the # (by accepting whatever its related receipt was) should have already
                         // removed the outpayment, so we are cleared here to go ahead and remove it. 
                         //
                        bShouldHarvestPayment     = false; // The # isn't signed out anymore, so we don't want to harvest it (which would cause the wallet to try and use it again -- but we don't want that, since we can't be using numnbers that aren't even signed out to us!)
                        bNeedToLoadAssetAcctInbox = false; // No need to check the inbox since the # isn't even signed out anymore. Even if some related receipt was in the inbox (for some non-cheque instrument, say) we'd still never need to harvest it back for re-use, since it's not even signed out to us anymore, and we can only use numbers that are signed out to us.
                    }
                } // if bIsExpired.
                // ------------------------------------------------------------------------------------------------
                else // Not expired. pNym is the sender but the payment instrument is NOT expired.
                {
                    // Remember that the transaction number is still signed out to me until I accept that
                    // chequeReceipt. So whether the receipt is there or not, the # will still be signed 
                    // out to me. But if there's no receipt yet in my inbox, that means the cheque hasn't
                    // been cashed yet. And THAT means I still have time to cancel it. I can't just discard
                    // the payment instrument, since its trans# would still need to be harvested if it's not
                    // being cancelled (so as to get it closed out on some other instrument, presumably), but
                    // I can't just harvest a number when there's some instrument still floating around out
                    // there, with that same number already on it! I HAVE to cancel it.
                    //
                    // If I discard it without harvesting, and if the recipient never cashes it, then that
                    // transaction # will end up signed out to me FOREVER (bad thing.) So I would have to
                    // cancel it first, in order to discard it. The server's success reply to my cancel
                    // would be the proper time to discard the old outpayment. Until I see that, how do I know
                    // if I won't need it in the future, for harvesting back?
                    //
                    if (bIsIssued)  // If this number is still signed out to pNym...
                    {
                        // If the instrument is definitely NOT expired, and the transaction # definitely IS issued to ME,
                        // then I can't just harvest the numbers, since the original recipient could still come through
                        // and deposit that cheque.  So in this case, I would HAVE to cancel the transaction first, and then
                        // such cancellation could sign a new transaction statement with that # removed from my list of
                        // "signed out" numbers. Only then am I safe from the cheque being cashed by the recipient,
                        // and only then could I even think about harvesting the number back--that itself being unnecessary,
                        // since the transaction # would then be cancelled/closed and thus would eliminate any need of
                        // harvesting it (since now I will never use it.)
                        //
                        // Also, if I DON'T cancel it, then I don't want to remove it from the outpayments box, because
                        // it will be removed automatically whenever the cheque is eventually cashed, and until/unless that
                        // happens, I need to keep it around for potential harvesting or cancellation. Therefore I can't
                        // discard the instrument either--I need to keep it in the outpayments box for now, in case it's
                        // needed later.
                        //
                        OTLog::vOutput(0, "%s: This outpayment isn't expired yet, and the transaction number (%ld) is still signed out. "
                                       "(Skipping moving it to record box -- it will be moved automatically once you cancel the transaction "
                                       "or the recipient deposits it.)\n", __FUNCTION__, lPaymentTransNum);
                        return false;
                    }
                    else // The payment is NOT expired yet, but most importantly, its transaction # is NOT signed out to pNym anymore.
                    {    // Normally the closing of the # (by accepting whatever its related receipt was) should have already
                         // removed the outpayment by now, so we are cleared here to go ahead and remove it.
                         //
                        bShouldHarvestPayment     = false; // The # isn't signed out anymore, so we don't want to harvest it (which would cause the wallet to try and use it again.)
                        bNeedToLoadAssetAcctInbox = false; // No need to check the inbox since the # isn't even signed out anymore and we're certainly not interested in harvesting it if it's not even signed out to us.
                    }
                } // !bIsExpired
            } // sender is pNym
            // -----------------------------------------------------------
            
            // TODO: Add OPTIONAL field to OTPurse: "Remitter".
            // This way the sender has the OPTION to attach his ID "for the record" even though
            // a cash transaction HAS NO "SENDER."
            //
            // This would make it convenient for a purse to, for example, create a second copy
            // of the cash, encrypted to the remitter's public key. This is important, since the
            // if the remitter has the cash in his outpayment's box, he will want a way to recover
            // it if his friend returns and says, "I lost that USB key! Do you still have that cash?!?"
            //
            // In fact we may want to use the field for that purpose, WHETHER OR NOT the final sent
            // instrument actually includes the remitter's ID.
            
            // -----------------------------------------------------------
            // If the SenderUserID on this instrument isn't Nym's ID (as in the case of vouchers),
            // or isn't even there (as in the case of cash) then why is it in Nym's payment outbox?
            // Well, maybe the recipient of your voucher, lost it. You still need to be able to
            // get another copy for him, or get it refunded (if you are listed as the remitter...)
            // Therefore you keep it in your outpayments box "just in case." In the case of cash,
            // the same could be true.
            //
            // In a way it doesn't matter, since eventually those instruments will expire and then
            // they will be swept into the record box with everything else (probably by this function.)
            //
            // But what if the instruments never expire? Say a voucher with a very very long expiration
            // date? It's still going to sit there, stuck in your outpayments box, even though the
            // recipient have have cashed it long, long ago! The only way to get rid of it is to have
            // the server send you a notice when it's cashed, which is only possible if your ID is
            // listed as the remitter. (Otherwise the server wouldn't know who to send the notice to.)
            //
            // Further, there's no PROVING whether the server sent you notice for anything -- whether
            // you are listed as the remitter or not, the server could choose to LIE and just NOT TELL
            // YOU that the voucher was cashed. How would you know the difference? Thus "Notice" is
            // an important problem, peripheral to OT. Balances are safe from any change without a
            // proper signed and authorized receipt--that is a powerful strength of OT--but notice
            // cannot be proven.
            //
            // If the remitter has no way to prove that the recipient actually deposited the cheque,
            // (even though most servers will of course provide this, they cannot PROVE that they
            // provided it) then what good is the instrument to the remitter? What good is such a
            // cashier's cheque? Well, the voucher is still in my outpayments, so I can see the transaction
            // number on it, and then I should be able to query the server and see which transaction
            // numbers are signed out to it. In which case a simple server message (available to all
            // users) will return the numbers signed out to the server and thus I can see whether or
            // not the number on the voucher is still valid. If it's not, the server reply to that
            // message would be the appropriate place to move the outpayment to the record box.
            //
            // What if we don't want to have these transaction numbers signed out to the server at all?
            // Maybe we use numbers signed out to the users instead. Then when the voucher is cashed,
            // instead of checking the server's list of issued transaction numbers to see if the voucher
            // is valid, we would be checking the remitter's list instead. And thus whenever the voucher
            // is cashed, we would have to drop a voucherReceipt in the REMITTER's inbox (and nymbox)
            // so he would know to discard the transaction number.
            //
            // This would require adding the voucherReceipt, and would restrict the use of vouchers to
            // those people who have an asset account (though that's currently the only people who can
            // use them now anyway, since vouchers are withdrawn from accounts) but it would eliminate
            // the need for the server nym to store all the transaction numbers for all the open vouchers,
            // and it would also eliminate the problem of "no notice" for the remitters of vouchers.
            // They'd be guaranteed, in fact, to get notice, since the voucherReceipt is what removes
            // the transaction number from the user's list of signed-out transaction numbers (and thus
            // prevents anyone from spending the voucher twice, which the server wants to avoid at all
            // costs.) Thus if the server wants to avoid having a voucher spent twice, then it needs to
            // get that transaction number off of my list of numbers, and it can't do that without putting
            // a receipt in my inbox to justify the removal of the number. Otherwise my receipt verifications
            // will start failing and I'll be unable to do any new transactions, and then the server will
            // have to explain why it removed a transaction number from my list, even though it still was
            // on my list during the last transaction statement, and even though there's no new receipt in
            // my inbox to justify removing it.
            //
            // Conclusion, todo: vouchers WITH a remitter acct, should store the remitter's user AND acct IDs,
            // and should use a transaction # that's signed out to the remitter (instead of the server) and
            // should drop a voucherReceipt in the remitter's asset account inbox when they are cashed.
            // These vouchers are guaranteed to provide notice to the remitter.
            //
            // Whereas vouchers WITHOUT a remitter acct should store the remitter's user ID (or not), but should
            // NOT store the remitter's acct ID, and should use a transaction # that's signed out to the server,
            // and should drop a notice in the Nymbox of the remitter IF his user ID is available, but it should
            // be understood that such notice is a favor the server is doing, and not something that's PROVABLE
            // as in the case of the vouchers in the above paragraph.
            //
            // This is similar to smart contracts, which can only be activated by a party who has an
            // asset account, so he has somewhere to receive the finalReceipt for that contract. (And thus
            // close out the transcation number he used to open it...)
            //
            // Perhaps we'll just offer both types of vouchers, and just let users choose which they are willing
            // to pay for, and which trade-off is most palatable to them (having to have an asset account to
            // get notice, or instead verifying the voucher's spent status based on some publicly-available
            // listing of the transaction #'s currently signed out to the server.)
            //
            // In the case of having transaction #'s signed out to the server, perhaps the server's internal storage
            // of these should be paired each with the NymID of the owner nym for that number, just so no one
            // would ever have any incentive to try and use one of those numbers on some instrument somehow, and
            // also so that the server wouldn't necessarily have to post the entire list of numbers, but just
            // rather give you the ones that are relevant to you (although the entire list may have to be posted
            // in some public way in any case, for notice reasons.)
            //
            // By this point, you may be wondering, but what does all this have to do with the function
            // we're in now? Well... in the below block, with a voucher, pNym would NOT be the sender.
            // The voucher would still be drawn off a server account. But nevertheless, pNym might still be
            // the owner of the transaction # for that voucher (assuming I change OT around to use the above
            // system, which I will have to do if I want provable notice for vouchers.) And if pNym is the
            // owner of that number, then he will want the option later of refunding it or re-issuing it,
            // and he will have to possibly load up his inbox to make sure there's no voucherReceipt in it,
            // etc. So for now, the vouchers will be handled by the below code, but in the future, they might
            // be moved to the above code.
            //
            //
            else // pNym is not the sender.
            {
                // pNym isn't even the "sender" (although he is) but since it's cash or voucher,
                // he's not waiting on any transaction number to close out or be harvested.
                // (In the case of cash, in fact, we might as well just put it straight in the records
                // and bypass the outpayments box entirely.) But this function can sweep it into there
                // all in due time anyway, once it expires, so it seems harmless to leave it there before
                // then. Plus, that way we always know which tokens are still potentially exchangeable,
                // for cases where the recipient never cashed them.
                //
                if (bIsExpired)
                {
                    // pNym is NOT the sender AND the payment instrument IS expired.
                    // Therefore, say in the case of sent vouchers and sent cash, there
                    // may have been some legitimate reason for keeping them in outpayments
                    // up until this point, but now that the instrument is expired, might as
                    // well get it out of the outpayments box and move it to the record box.
                    // Let the client software do its own historical archiving.
                    //
                    bShouldHarvestPayment     = false; // The # isn't signed out to pNym, so we don't want to harvest it (which would cause the wallet to try and use it even though it's signed out to someone else -- bad.)
                    bNeedToLoadAssetAcctInbox = false; // No need to check the inbox since the # isn't even signed out to pNym and we're certainly not interested in harvesting it if it's not even signed out to us. (Thus no reason to check the inbox.)
                }
                else // pNym is NOT the sender and the payment instrument is NOT expired.
                {
                    // For example, for a sent voucher that has not expired yet.
                    // Those we'll keep here for now, until some server notice is
                    // received, or the instrument expires. What if we need to re-issue
                    // the cheque to the recipient who lost it? Or what if we want to
                    // cancel it before he tries to cash it? Since it's not expired yet,
                    // it's wise to keep a copy in the outpayments box for now.
                    //
                    OTLog::vOutput(0, "%s: This outpayment isn't expired yet. (Skipping moving it to record box -- it "
                                   "will be moved automatically once it expires--and maybe sooner, if I code voucherReceipts. "
                                   "See giant comment just above this log.)\n", __FUNCTION__, lPaymentTransNum);
                    return false;
                }
            }
            // ----------------------------------------------------------------
            //
            bool bFoundReceiptInInbox = false;
            //
            // In certain cases (logic above) it is determined that we have to load the
            // asset account inbox and make sure there aren't any chequeReceipts there,
            // before we go ahead and harvest any transaction numbers.
            //
            if (bNeedToLoadAssetAcctInbox && bFromAcctIsAvailable)
            {
                OTLedger theSenderInbox(USER_ID, theSenderAcctID, SERVER_ID);
                
                const bool bSuccessLoadingSenderInbox = (theSenderInbox.LoadInbox() && theSenderInbox.VerifyAccount(*pNym));
                // --------------------------------------------------------------------
                if (bSuccessLoadingSenderInbox)
                {
                    // Loop through the inbox and see if there are any receipts for lPaymentTransNum inside.
                    // Technically this would have to be a chequeReceipt, or possibly a voucherReceipt if I add
                    // that (see giant comment above.)
                    //
                    // There are other instrument types but only a cheque, at this point, would be in my outpayments
                    // box AND could have a receipt in my asset account inbox. So let's see if there's a chequeReceipt
                    // in there that corresponds to lPaymentTransNum...
                    //
                    OTTransaction * pChequeReceipt = theSenderInbox.GetChequeReceipt(lPaymentTransNum);
                    
                    if (NULL != pChequeReceipt)
                    {
                        bFoundReceiptInInbox = true;
                    }
                }
                //else unable to load inbox. Maybe it's empty, never been used before. i.e. it doesn't even exist.                
            }
            // ----------------------------------------------------------------
            // If we should harvest the transaction numbers,
            // AND if we don't need to double-check that against the asset inbox to make sure the receipt's not there,
            // (or if we do, that it was a successful double-check and the receipt indeed is not there.)
            //
            if (  bShouldHarvestPayment &&
                ((!bNeedToLoadAssetAcctInbox) || (bNeedToLoadAssetAcctInbox && !bFoundReceiptInInbox)))
            {
                // Harvest the transaction number from the cheque.
                //
                pNym->ClawbackTransactionNumber(SERVER_ID, lPaymentTransNum, false); //bSave=false
                bNeedToSaveTheNym = true;
                
                // Note, food for thought: IF the receipt had popped into your asset inbox on the server
                // side, since the last time you downloaded your inbox, then you could be making the wrong
                // decision here, and harvesting a number that's already spent. (You just didn't know it yet.)
                //
                // What happens in that case, when I download the inbox again? A new receipt is there, and a
                // transaction # is used, which I thought was still available for use? (Since I harvested it?)
                // The appearance of the receipt in the inbox, as long as properly formed and signed by me,
                // should be enough information for the client side to adjust its records, because if it
                // doesn't anticipate this possibility, then it will be forced to resync entirely, which I want
                // to avoid in all cases period.
                //
                // In this block, we clawed back the number because if there's no chequeReceipt in the inbox,
                // then that means the cheque has never been used, since if I had closed the chequeReceipt out
                // already, then the transaction number on that cheque would already have been closed out at
                // that time.
                // We only clawback for expired instruments, where the transaction # is still outstanding
                // and where no receipt is present in the asset acct inbox. If the instrument is not expired,
                // then you must cancel it properly. And if the cheque receipt is in the inbox, then you must
                // close it properly.
            }
            // ----------------------------------------------------------------
            // Create the notice to put in the Record Box.
            //
            OTTransaction * pNewTransaction = OTTransaction::GenerateTransaction(*pRecordBox, OTTransaction::notice, lPaymentTransNum);
            
            if (NULL != pNewTransaction) // The above has an OT_ASSERT within, but I just like to check my pointers.
            {
                pNewTransaction->	SetReferenceToNum(lPaymentTransNum); // referencing myself here. We'll see how it works out.
                pNewTransaction->	SetReferenceString(strInstrument); // the cheque, invoice, etc that used to be in the outpayments box.
                
                pNewTransaction->	SignContract(*pNym);
                pNewTransaction->	SaveContract();
                // -----------------------------------------
                pTransaction = pNewTransaction;
            
                theTransactionAngel.SetCleanupTargetPointer(pTransaction);
            }
            else // should never happen
            {
                const OTString strUserID(USER_ID);
                OTLog::vError("%s: Failed while trying to generate transaction in order to "
                              "add a new transaction (for a payment instrument from the outpayments box) "
                              "to Record Box: %s\n", __FUNCTION__, strUserID.Get());
            }
        } //if (thePayment.IsValid() && thePayment.SetTempValues() && thePayment.GetTransactionNum(lPaymentTransNum))
        // -------------------------------------------------------------------
        
        // 
        // Now we actually remove the message from the outpayments...
        //
        bRemoved = pNym->RemoveOutpaymentsByIndex(nIndex, false); // bDeleteIt=true by default
        theMessageAngel.SetCleanupTargetPointer(pMessage); // Since we chose to keep pMessage alive after removing it from the outpayments, we set the angel here to make sure it gets cleaned up later whenever we return out of this godforsaken function.
        
        // Anything else?
    } // outpayments box.
    // ***********************************************************
    // 
    // Okay by this point, whether the payment was in the payments inbox, or
    // whether it was in the outpayments box, either way, it has now been removed
    // from that box. (Otherwise we would have returned already by this point.)
    //
    // It's still safer to explicitly check bRemoved, just in case.
    //
    if (bRemoved)
    {
        // -----------------------------------------------------
        const bool bAdded = pRecordBox->AddTransaction(*pTransaction);

        if (!bAdded)
        {
            OTLog::vError("%s: Unable to add transaction %ld to record box (after tentatively removing "
                          "from payment %s, an action that is now canceled.)\n", __FUNCTION__,
                          pTransaction->GetTransactionNum(), bIsInbox ? "inbox" : "outbox");
            return false;
        }
        else
            theTransactionAngel.SetCleanupTargetPointer(NULL); // If successfully added to the record box, then no need anymore to clean it up ourselves.
        
        pRecordBox->ReleaseSignatures();
        pRecordBox->SignContract(*pNym);
        pRecordBox->SaveContract();
        // -------------------------------
        pRecordBox->SaveRecordBox(); // todo log failure.
        
        // Any inbox/nymbox/outbox ledger will only itself contain
        // abbreviated versions of the receipts, including their hashes.
        //
        // The rest is stored separately, in the box receipt, which is created
        // whenever a receipt is added to a box, and deleted after a receipt
        // is removed from a box.
        //
        pTransaction->SaveBoxReceipt(*pRecordBox); // todo: log failure
        // -----------------------------------------------------
        if (bIsInbox)
        {
            pPaymentInbox->ReleaseSignatures();
            pPaymentInbox->SignContract(*pNym);
            pPaymentInbox->SaveContract();
            // -----------------------------------------------------
            const bool bSavedInbox = pPaymentInbox->SavePaymentInbox(); // todo: log failure
        }
        else // outbox
        {
            // Outpayments are currently stored in the Nymfile.
            //
            bNeedToSaveTheNym = true;
        }
        // -----------------------------------------------------
        if (bNeedToSaveTheNym)
        {
            pNym->SaveSignedNymfile(*pNym);
        }
        // -----------------------------------------------------
    }
    else
    {
        OTLog::vError("%s: Unable to remove from payment %s based on index %d.\n",
                      __FUNCTION__, bIsInbox ? "inbox" : "outbox", nIndex);
        return false;
    }
    // -----------------------------------------------------
    //

    return true;
}



// ----------------------------------------------------------------



bool OT_API::ClearRecord(const OTIdentifier & SERVER_ID,
                         const OTIdentifier & USER_ID,
                         const OTIdentifier & ACCOUNT_ID, // USER_ID can be passed here as well.
                         const int32_t        nIndex,
                         const bool           bClearAll/*=false*/) // if true, nIndex is ignored.
{
	OTPseudonym * pNym = this->GetOrLoadPrivateNym(USER_ID, false, __FUNCTION__);
	if (NULL == pNym) return false;
	// By this point, pNym is a good pointer, and is on the wallet. (No need to cleanup.)
	// -----------------------------------------------------
    OTLedger  * pRecordBox = this->LoadRecordBox (SERVER_ID, USER_ID, ACCOUNT_ID);
	// -----------------------------------------------------
    if (NULL == pRecordBox)
    {
        pRecordBox = OTLedger::GenerateLedger(USER_ID, ACCOUNT_ID, SERVER_ID, OTLedger::recordBox, true);
        
        if (NULL == pRecordBox)
        {
            OTLog::vError("%s: Unable to load or create record box (and thus unable to do anything with it.)\n",
                          __FUNCTION__);
            return false;
        }
    }
	// -----------------------------------------------------
    OTCleanup<OTLedger> theRecordBoxAngel (pRecordBox);
	// -----------------------------------------------------
    if (bClearAll)
    {
        pRecordBox->ReleaseTransactions();
        pRecordBox->ReleaseSignatures();
        pRecordBox->SignContract(*pNym);
        pRecordBox->SaveContract();
        pRecordBox->SaveRecordBox();
        return true;
    }
    // -----------------------------------------
    // Okay, it's not "clear all" but "clear at index" ...
    //
    const int nTransCount  = pRecordBox->GetTransactionCount();
    
    if ((nIndex < 0) || (nIndex >= nTransCount))
    {
        OTLog::vOutput(0, "%s: Index out of bounds (highest allowed index for this record box is %d.)\n",
                       __FUNCTION__, nTransCount-1);
        return false;
    }
    // -----------------------------------------
    OTTransaction * pTransaction = pRecordBox->GetTransactionByIndex(nIndex);
    bool bRemoved = false;
    
    if (NULL != pTransaction)
    {
        
        // todo resume:  shouldn't we be deleting the box receipt here as well?
        
        
        bRemoved = pRecordBox->RemoveTransaction(pTransaction->GetTransactionNum());
    }
    // -----------------------------------------
    if (bRemoved)
    {
        pRecordBox->ReleaseSignatures();
        pRecordBox->SignContract(*pNym);
        pRecordBox->SaveContract();
        pRecordBox->SaveRecordBox();
        return true;
    }
    else
    {
        const int nTemp = static_cast<int>(nIndex);
        OTLog::vOutput(0, "%s: Failed trying to clear a record from the record box at index: %d\n",
                       __FUNCTION__, nTemp);        
    }
    // -----------------------------------------
    return false;
}

// ----------------------------------------------------------------
    


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




// ----------------------------------------------------------------


// INCOMING SERVER REPLIES


// YOU are responsible to delete the OTMessage object, once
// you receive the pointer that comes back from this function.
// (It also might return NULL, if there are none there.)
//
OTMessage * OT_API::PopMessageBuffer(const long         &   lRequestNumber,
                                     const OTIdentifier &	SERVER_ID,
                                     const OTIdentifier &	USER_ID)
{
	OT_ASSERT_MSG( (m_bInitialized && (m_pClient != NULL)) , "Not initialized; call OT_API::Init first.");
	OT_ASSERT_MSG( lRequestNumber > 0, "OT_API::PopMessageBuffer: lRequestNumber is less than 1.");
    
    const OTString strServerID(SERVER_ID), strNymID(USER_ID);

	return m_pClient->GetMessageBuffer().Pop(lRequestNumber, strServerID, strNymID); // deletes
}



void OT_API::FlushMessageBuffer()
{
	OT_ASSERT_MSG(m_bInitialized && (m_pClient != NULL), "Not initialized; call OT_API::Init first.");
	
    m_pClient->GetMessageBuffer().Clear();
}




// --------------------------------------------------------------------


// OUTOING MESSSAGES

// NOTE: Currently it just stores ALL sent messages, if they were sent (as far as it
// can tell.) But the idea for the future is to have messages marked as "important"
// and for "only those" to actually be saved here. (Those important msgs are the ones
// that we need to track for purposes of harvesting transaction numbers.)

// Do NOT delete the message that is returned here.
// Use the "Remove" call if you want to remove it.
//

OTMessage * OT_API::GetSentMessage(const long         & lRequestNumber,
                                   const OTIdentifier &	SERVER_ID,
                                   const OTIdentifier &	USER_ID)
{
	OT_ASSERT_MSG( (m_bInitialized && (m_pClient != NULL)) , "Not initialized; call OT_API::Init first.");
	OT_ASSERT_MSG( lRequestNumber > 0, "OT_API::GetSentMessage: lRequestNumber is less than 1.");
    
    const OTString strServerID(SERVER_ID), strNymID(USER_ID);
    
	return m_pClient->GetMessageOutbuffer().GetSentMessage(lRequestNumber, strServerID, strNymID); // doesn't delete.
}


bool OT_API::RemoveSentMessage(const long         & lRequestNumber,
                               const OTIdentifier &	SERVER_ID,
                               const OTIdentifier &	USER_ID)
{
	OT_ASSERT_MSG(m_bInitialized && (m_pClient != NULL), "Not initialized; call OT_API::Init first.");
	OT_ASSERT_MSG(lRequestNumber > 0, "OT_API::RemoveSentMessage: lRequestNumber is less than 1.");
    
    const OTString strServerID(SERVER_ID), strNymID(USER_ID);
    
	return m_pClient->GetMessageOutbuffer().RemoveSentMessage(lRequestNumber, strServerID, strNymID); // deletes.
}



//  Basically, the sent messages queue must store
// messages (by request number) until we know for SURE whether we have a success, a failure,
// or a lost/rejected message. That is, until we DOWNLOAD the Nymbox, and thus know for SURE
// that a response to a given message is there...or not. Why do we care? For making this 
// choice:
//
// Messages that DO have a reply are therefore already "in the system" and will be handled
// normally--they can be ignored and flushed from the "sent messages" queue. Whereas messages
// that do NOT have a reply in the Nymbox (yet are still in the "sent messages" queue) can be
// assumed safely to have been rejected at "message level" (before any transaction could
// have processed) and the reply must have been dropped on the network, OR the server never
// even received the message in the first place. EITHER WAY the trans #s can be harvested
// accordingly and then removed from the sent buffer. In a perfect world (read: iteration 2)
// these sent messages will be serialized somehow along with the Nym, and not just stored in 
// RAM like this version does.
//
// Therefore this function will be called only after @getNymbox (in OTClient), where each
// replyNotice in the Nymbox will be removed from the sent messages individually, and then
// the rest of the sent messages can be flushed
//
//
// -----------------------------------------------------------
// OT_API::FlushSentMessages
//
// Make sure to call this directly after a successful @getNymbox.
// (And ONLY at that time.)
//
// This empties the buffer of sent messages.
// (Harvesting any transaction numbers that are still there.)
//
// NOTE: You normally ONLY call this immediately after receiving
// a successful @getNymbox. It's only then that you can see which
// messages a server actually received or not -- which transactions
// it processed (success or fail) vs which transactions did NOT
// process (and thus did NOT leave any success/fail receipt in the
// nymbox.)
//
// I COULD have just flushed myself IN the @getNymbox code (where
// the reply is processed.) But then the developer using the OT API
// would never have the opportunity to see whether a message was
// replied to, and harvest it for himself (say, just before attempting
// a re-try, which I plan to do in the high-level Java API, which is
// why I'm coding it this way.)
//
// This way, he can do that if he wishes, THEN call this function,
// and harvesting will still occur properly, and he will also thus have
// his chance to check for his own replies to harvest before then.
// This all depends on the developer using the API being smart enough
// to call this function after a successful @getNymbox!
//
void OT_API::FlushSentMessages(const bool bHarvestingForRetry,
                               const OTIdentifier &	SERVER_ID,
                               const OTIdentifier &	USER_ID,
                                     OTLedger     & THE_NYMBOX)
{
	OT_ASSERT_MSG(m_bInitialized && (m_pClient != NULL), "Not initialized; call OT_API::Init first.");
    // --------------------------------------------------------------------
	const char * szFuncName = "OT_API::FlushSentMessages";
	// -----------------------------------------------------
	OTPseudonym * pNym = this->GetNym(USER_ID, szFuncName); // This logs and ASSERTs already.
	if (NULL == pNym) return;
	// Below this point, pNym is a good ptr, and will be cleaned up automatically.
	// -----------------------------------------------------
    const OTString strServerID(SERVER_ID), strNymID(USER_ID);
	// -----------------------------------------------------
    if ((THE_NYMBOX.GetUserID()            != USER_ID) ||
        (THE_NYMBOX.GetPurportedServerID() != SERVER_ID))
    {
        const OTString strLedger(THE_NYMBOX);
        OTLog::vError("%s: Failure, Bad input data: UserID (%s) or ServerID (%s) failed to match Nymbox:\n\n%s\n\n", 
                      szFuncName, strNymID.Get(), strServerID.Get(), strLedger.Get());
        return;
    }
    // -----------------------------------------------------------------
    // Iterate through the nymbox receipts.
    // If ANY of them is a REPLY NOTICE, then see if the SENT MESSAGE for that SAME
    // request number is in the sent queue.
    // If it IS, REMOVE IT from the sent queue. (Since Nymbox clearly already contains
    // a reply to it, no need to queue it anymore.)
    // At the end of this loop, then FLUSH the sent queue. We KNOW only important
    // (nymbox related) messages should be queued there, and once we see the latest Nymbox,
    // then we KNOW which ones to remove before flushing.
    // 
    FOR_EACH(mapOfTransactions, THE_NYMBOX.GetTransactionMap())
    {
        const OTTransaction * pTransaction = (*it).second;
        OT_ASSERT(NULL != pTransaction);
        // --------------------------------
        
        if (OTTransaction::replyNotice == pTransaction->GetType())
        {
            OTMessage * pMessage = m_pClient->GetMessageOutbuffer().GetSentMessage(*pTransaction);
            
            if (NULL != pMessage) // It WAS there in my sent buffer!
            {
                // Since it IS in my Nymbox already as a replyNotice,
                // therefore I'm safe to erase it from my sent queue.
                //
                m_pClient->GetMessageOutbuffer().RemoveSentMessage(*pTransaction);
            }
            // else do nothing, must have already removed it.
        }
    }
    // -----------------------------------------------------------------
    // Now that we've REMOVED the sent messages that already have a reply
    // in the Nymbox (and thus CLEARLY do not need harvesting...)
    //
    // Clear all "sent message" cached messages for this server and NymID.
    // (And harvest their transaction numbers back, since we know for a fact
    // the server hasn't replied to them (the reply would be in the Nymbox, which
    // we just got.)
    //
    // UPDATE: We will have to rely on the Developer using the OT API to call
    // OT_API_FlushSentMessages IMMEDIATELY after calling getNymbox and receiving
    // a successful reply. Why? Because that's the only way to give him the chance
    // to see if certain replies are there or not (before they get removed.) That way
    // he can do his own harvesting, do a re-try, etc and then finally when he is done
    // with that, do the flush.
    //
    m_pClient->GetMessageOutbuffer().Clear(&strServerID, &strNymID, pNym, &bHarvestingForRetry); // FYI: This HARVESTS any sent messages that need harvesting, before flushing them all.
}

// -----------------------------------------------------------------



bool OT_API::HaveAlreadySeenReply(OTIdentifier & SERVER_ID, OTIdentifier & USER_ID, const long & lRequestNumber)
{
    const char * szFuncName = "OT_API::HaveAlreadySeenReply";
	// -----------------------------------------------------
	OTPseudonym * pNym = this->GetOrLoadPrivateNym(USER_ID, false, szFuncName);
	if (NULL == pNym) return false;
	// By this point, pNym is a good pointer, and is on the wallet. (No need to cleanup.)
	// -----------------------------------------------------

    // "Client verifies it has already seen a server reply."
//  bool OTPseudonym:::VerifyAcknowledgedNum(const OTString & strServerID, const long & lRequestNum); 
    //
    const OTString strServerID(SERVER_ID);    
    return pNym->VerifyAcknowledgedNum(strServerID, lRequestNumber);
}




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
	OTPseudonym * pNym = this->GetOrLoadPrivateNym(USER_ID, false, szFuncName);
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
	OTPseudonym * pNym = this->GetOrLoadPrivateNym(USER_ID, false, szFuncName);
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
int OT_API::issueBasket(OTIdentifier	& SERVER_ID,
						 OTIdentifier	& USER_ID,
						 OTString		& BASKET_INFO)
{
	const char * szFuncName = "OT_API::issueBasket";
	// -----------------------------------------------------
	OTPseudonym * pNym = this->GetOrLoadPrivateNym(USER_ID, false, szFuncName);
	if (NULL == pNym) return (-1);
	// By this point, pNym is a good pointer, and is on the wallet. (No need to cleanup.)
	// -----------------------------------------------------
	OTServerContract	* pServer = this->GetServer(SERVER_ID, szFuncName);
	if (NULL == pServer) return (-1);
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
    theMessage.SetAcknowledgments(*pNym); // Must be called AFTER theMessage.m_strServerID is already set. (It uses it.)

	theMessage.m_ascPayload.SetString(BASKET_INFO);
	
	// (2) Sign the Message 
	theMessage.SignContract(*pNym);		
	
	// (3) Save the Message (with signatures and all, back to its internal member m_strRawFile.)
	theMessage.SaveContract();
	
	// (Send it)
#if defined(OT_ZMQ_MODE)
	m_pClient->SetFocusToServerAndNym(*pServer, *pNym, this->m_pTransportCallback);
#endif	
	m_pClient->ProcessMessageOut(theMessage);
    
    return m_pClient->CalcReturnVal(lRequestNumber);
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
	OTPseudonym * pNym = this->GetOrLoadPrivateNym(USER_ID, false, szFuncName); // These copiously log, and ASSERT.
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
	OTPseudonym * pNym = this->GetOrLoadPrivateNym(USER_ID, false, szFuncName); // These copiously log, and ASSERT.
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

// TODO: It was a mistake to only drop Nymbox notices for successful messages.
// If the client misses a failure message, the client will then fail to claw back
// his transaction numbers from that failure. For transactions, at least, failure
// notices should also be dropped.

// BUT perhaps we can avoid many failure notices, by nipping things in the bud. For
// example, if the NymboxHash is wrong, we can reject transactions before even the 
// opening number is burned (similar to rejecting messages based on bad request #.)
// This "message level" rejection allows the client to claw-back or re-try, without
// the pain of having burned SOME numbers while others are still good (and then 
// having to reconcile that mess to get back into sync.)


// Some notes on TRANSACTION NUMBERS:
/*
 1. You must BURN a number even to ATTEMPT a transaction.
 
 2. However, remember that OT has messages, and those messages contain transactions.
    A message might fail due to out-of-sync request number, meaning it was cut off
    before even having a chance to call the NotarizeTransactions code.
 
 3. If the message failed, that means the transaction has not yet even been tried, so
    the number on it is still good. (You can re-send the message.)
 
 4. But if the message succeeded, then the transaction itself requires 2 steps:
    the balance agreement, and the transaction itself.
 
 5. If the balance agreement or transaction fails, then the primary transaction # has been burned.
    BUT there may be OTHER transaction numbers that are STILL good. The closing numbers, etc.
 
 6. The OTHER numbers are only burned if the transaction is a SUCCESS.
 
 
 Therefore:
 -- If the message fails, we can re-sync and re-try. All trans #s are still good.
 -- If the message succeeds, but balance agreement fails, or the transaction fails,
    then the primary transaction # is burned, but any additional numbers are still good.
 -- If the transaction itself succeeds, then ALL numbers are burned.
 
 OT Client, if the MESSAGE was a failure, MUST re-send it, or claw back the numbers, since
 they are all still good, even the primary #. (This is only if an EXPLICIT message failure
 is received. A null reply could mean it was SUCCESSFUL but we just didn't SEE that success
 because we never got the reply! In that case, we do NOT want to re-try, nor do we want to
 claw the numbers back.)
 
 Thus OT client, as long as the MESSAGE was a success, can operate based on the assumption 
 that the primary transaction number IS burned, whether the transaction itself was successful
 or not.
 
 OT client also assumes the other numbers are burned as well, UNLESS IT RECEIVES A FAILURE REPLY.
 If an explicit transaction failure is received, then OT client can CLAW BACK all of the transaction
 numbers EXCEPT the primary one.
 
 OT MUST SEE THE FAILURE MESSAGES -- AT LEAST FOR TRANSACTIONS!
 What if:
 
 What if I try a TRANSACTION, and fail to receive the server reply?
 Potentialities:
 
 1. Message was a failure. (No numbers are burned.)
 2. Message was success but balance agreement was a failure.
    (The opening # was burned, but the others are still good.)
 3. Message and balance agreement were both success, but transaction itself failed.
    (The opening # was burned, but the others are still good.)
 4. Message, balance agreement, and transaction were all a success.
    (ALL transaction #s on the message are burned.)
 
 
 Currently:
 1. If I don't receive this failure message, then I resend, which would basically work since the numbers are all still good.
    BUT IN THE CASE OF EXCHANGE BASKET, IT FUCKING GRABS A NEW NUMBER EACH CALL!  So when OTAPI_Func retries, it grabs a new one each time. 
    (Instead of just using the ones that are still good.)
 
 2. If I miss this success reply, or treat the null as a failure, then I will end up re-trying a transaction
    that has no prayer of working, since its opening # is already burned. I'll also fail to claw back my numbers, which are mostly still good.
 
 3. If I miss this success reply, or treat the null as a failure, then I will end up re-trying a transaction
    that has no prayer of working, since its opening # is already burned. I'll also fail to claw back my numbers, which are mostly still good.
 
 4. If I miss this success reply, the numbers are all burned on both sides, but I don't KNOW that, and though I correctly believe the numbers
    are all burned, I also end up CONTINUING to re-try the message, which fails every time, since it was already a success and the numbers are
    all burned already.
 ----------------------------------
 
 Therefore, the new solutions...
 
 
 
 --------------------------------------------------
 
 
 
 
 */



// -----------------------------------------------------
// EXCHANGE (into or out of) BASKET (request to server.)
//
int OT_API::exchangeBasket(OTIdentifier	& SERVER_ID,
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
	OTPseudonym * pNym = this->GetOrLoadPrivateNym(USER_ID, false, szFuncName); // These copiously log, and ASSERT.
	if (NULL == pNym) return (-1);
	// By this point, pNym is a good pointer, and is on the wallet. (No need to cleanup.)
	// -----------------------------------------------------
	OTServerContract *	pServer = this->GetServer(SERVER_ID, szFuncName); // This ASSERTs and logs already.
	if (NULL == pServer) return (-1);
	// By this point, pServer is a good pointer.  (No need to cleanup.)
	// -----------------------------------------------------
	OTAssetContract * pContract = this->GetAssetType(BASKET_ASSET_ID, szFuncName);
	if (NULL == pContract) return (-1);
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
		if (NULL == pAccount) return (-1);

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
                            *pTransaction, *pNym, *pAccount, *pOutbox);         // but basketReceipts will be used to account for it.) 
                    
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
                    theMessage.SetAcknowledgments(*pNym); // Must be called AFTER theMessage.m_strServerID is already set. (It uses it.)

                    BASKET_ASSET_ACCT_ID.GetString(theMessage.m_strAcctID);
                    theMessage.m_ascPayload			= ascLedger;
                    
                    OTIdentifier NYMBOX_HASH;
                    const std::string str_server(strServerID.Get());
                    const bool bNymboxHash = pNym->GetNymboxHash(str_server, NYMBOX_HASH);
                    NYMBOX_HASH.GetString(theMessage.m_strNymboxHash);
                    
                    if (!bNymboxHash)
                        OTLog::vError("Failed getting NymboxHash from Nym for server: %s\n",
                                      str_server.c_str());

                    // (2) Sign the Message 
                    theMessage.SignContract(*pNym);		
                    
                    // (3) Save the Message (with signatures and all, back to its internal member m_strRawFile.)
                    theMessage.SaveContract();
                    
                    // (Send it)
#if defined(OT_ZMQ_MODE)
                    m_pClient->SetFocusToServerAndNym(*pServer, *pNym, this->m_pTransportCallback);
#endif	
                    m_pClient->ProcessMessageOut(theMessage);
                    
                    return m_pClient->CalcReturnVal(lRequestNumber);
                } // Inbox loaded.
            } // successfully got first transaction number.
        }
    }
    
    return (-1);
}





int OT_API::getTransactionNumber(OTIdentifier & SERVER_ID,
								  OTIdentifier & USER_ID)
{
	const char * szFuncName = "OT_API::getTransactionNumber";
	// -----------------------------------------------------
	OTPseudonym * pNym = this->GetOrLoadPrivateNym(USER_ID, false, szFuncName); // These copiously log, and ASSERT.
	if (NULL == pNym) return (-1);
	// By this point, pNym is a good pointer, and is on the wallet. (No need to cleanup.)
	// -----------------------------------------------------
	OTServerContract *	pServer = this->GetServer(SERVER_ID, szFuncName); // This ASSERTs and logs already.
	if (NULL == pServer) return (-1);
	// By this point, pServer is a good pointer.  (No need to cleanup.)
	// -----------------------------------------------------
	
    const int nCount	= pNym->GetTransactionNumCount(SERVER_ID);
	const int nMaxCount	= 50; // todo no hardcoding. (max transaction nums allowed out at a single time.)
    
	if (nCount > nMaxCount) 
	{
		OTLog::vOutput(0, "OT_API::getTransactionNumber: Failure: That Nym already has "
					  "more than %d transaction numbers signed out. (Use those first.)\n", nMaxCount);
        return 0; // Java code needs to know that no msg went out, BUT it's because we already have TOO
        // MANY numbers (i.e. "a good reason.") This means "process your Nymbox and grab your intermediary
        // files, and try again!" So, we return 0 to indicate this.
        //
//      return (-1);
	}
	// -----------------------------------------------------
	OTMessage theMessage;

	int nReturnValue = m_pClient->ProcessUserCommand(OTClient::getTransactionNum, theMessage, 
                                                     *pNym, *pServer,
                                                     NULL); // NULL pAccount on this command.
	if (0 < nReturnValue) 
	{				
#if defined(OT_ZMQ_MODE)
		m_pClient->SetFocusToServerAndNym(*pServer, *pNym, this->m_pTransportCallback);
#endif	
		m_pClient->ProcessMessageOut(theMessage);
        
        return nReturnValue;
	}
	else
		OTLog::vError("OT_API::getTransactionNumber: Error processing getTransactionNumber command. Return value: %d\n",
                      nReturnValue);
    
    return (-1);
}





int OT_API::notarizeWithdrawal(OTIdentifier	& SERVER_ID,
								OTIdentifier	& USER_ID,
								OTIdentifier	& ACCT_ID,
								const long		& AMOUNT)
{
	const char * szFuncName = "OT_API::notarizeWithdrawal";
	// -----------------------------------------------------
	OTWallet * pWallet = this->GetWallet(szFuncName); // This logs and ASSERTs already.
	if (NULL == pWallet) return (-1);
	// -----------------------------------------------------
	OTPseudonym * pNym = this->GetOrLoadPrivateNym(USER_ID, false, szFuncName); // These copiously log, and ASSERT.
	if (NULL == pNym) return (-1);
	// By this point, pNym is a good pointer, and is on the wallet. (No need to cleanup.)
	// -----------------------------------------------------
	OTServerContract *	pServer = this->GetServer(SERVER_ID, szFuncName); // This ASSERTs and logs already.
	if (NULL == pServer) return (-1);
	// By this point, pServer is a good pointer.  (No need to cleanup.)
	// -----------------------------------------------------
	OTAccount * pAccount = this->GetOrLoadAccount(*pNym, ACCT_ID, SERVER_ID, szFuncName);
	if (NULL == pAccount) return (-1);
	// By this point, pAccount is a good pointer, and is on the wallet. (No need to cleanup.)
	// -----------------------------------------------------			
	OTIdentifier	CONTRACT_ID;
	OTString		strContractID, strServerID(SERVER_ID);
	// -----------------------------------------------------
	CONTRACT_ID = pAccount->GetAssetTypeID();
	CONTRACT_ID.GetString(strContractID);	
	// --------------------------------------------------------------------
	if (false == OTDB::Exists(OTFolders::Mint().Get(), strServerID.Get(), strContractID.Get()))
	{
		OTLog::vError("OT_API::notarizeWithdrawal: File does not exist: %s%s%s%s%s\n", 
					  OTFolders::Mint().Get(), OTLog::PathSeparator(), strServerID.Get(),
					  OTLog::PathSeparator(), strContractID.Get());
        return -1;
	}
	// --------------------------------------------------------------------
	OTMint * pMint = OTMint::MintFactory(strServerID, strContractID); // <=================
	OTCleanup<OTMint> theMintAngel(pMint);
    OT_ASSERT(NULL != pMint);
	// -----------------------------------------------------------------	
	OTMessage theMessage;
	
	long lRequestNumber = 0;
	
	const	long lTotalAmount	= AMOUNT;
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
	else if ((bGotTransNum = pNym->GetNextTransactionNum(*pNym, strServerID, lStoredTransactionNumber)))
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
			pMint->LoadMint() &&
			pMint->VerifyMint((OTPseudonym&)*pServerNym))
		{
			OTPurse * pPurse		= new OTPurse(SERVER_ID, CONTRACT_ID, SERVER_USER_ID);
			OTPurse * pPurseMyCopy	= new OTPurse(SERVER_ID, CONTRACT_ID, USER_ID);
			
			// Create all the necessary tokens for the withdrawal amount.
			// Push copies of each token into a purse to be sent to the server,
			// as well as a purse to be kept for unblinding when we receive the
			// server response.  (Coin private unblinding keys are not sent to
			// the server, obviously.)
			long lTokenAmount = 0;
			while ((lTokenAmount = pMint->GetLargestDenomination(lAmount)) > 0 )
			{
				lAmount -= lTokenAmount;
				
				// Create the relevant token request with same server/asset ID as the purse.
				// the purse does NOT own the token at this point. The token's constructor
				// just uses it to copy some IDs, since they must match.
                //
                OTToken * pToken = OTToken::InstantiateAndGenerateTokenRequest(*pPurse, *pNym, *pMint, lTokenAmount);
                OTCleanup<OTToken> theTokenAngel(pToken);
                OT_ASSERT(NULL != pToken);

				// Sign it and save it. 
				pToken->SignContract(*pNym);
				pToken->SaveContract();
				
				// Now the proto-token is generated, let's add it to a purse
				// By pushing *pToken into pPurse with *pServerNym, I encrypt it to pServerNym.
				// So now only the server Nym can decrypt that token and pop it out of that purse.
				pPurse->Push(*pServerNym, *pToken);
				
				// I'm saving my own copy of all this, encrypted to my nym
				// instead of the server's, so I can get to my private coin data.
				// The server's copy of pToken is already Pushed, so I can re-use
				// the variable now for my own purse.
				pToken->ReleaseSignatures();
				pToken->SetSavePrivateKeys(); // This time it will save the private keys when I sign it
				pToken->SignContract(*pNym);
				pToken->SaveContract();
				
				pPurseMyCopy->Push(*pNym, *pToken);// Now my copy of the purse has a version of the token,
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
            theMessage.SetAcknowledgments(*pNym); // Must be called AFTER theMessage.m_strServerID is already set. (It uses it.)

			theMessage.m_strAcctID			= strFromAcct;
			theMessage.m_ascPayload			= ascLedger;
			
            OTIdentifier NYMBOX_HASH;
            const std::string str_server(strServerID.Get());
            const bool bNymboxHash = pNym->GetNymboxHash(str_server, NYMBOX_HASH);
            NYMBOX_HASH.GetString(theMessage.m_strNymboxHash);
            
            if (!bNymboxHash)
                OTLog::vError("Failed getting NymboxHash from Nym for server: %s\n",
                              str_server.c_str());

			// (2) Sign the Message 
			theMessage.SignContract(*pNym);		
			
			// (3) Save the Message (with signatures and all, back to its internal member m_strRawFile.)
			theMessage.SaveContract();
			
			// (Send it)
#if defined(OT_ZMQ_MODE)
			m_pClient->SetFocusToServerAndNym(*pServer, *pNym, m_pTransportCallback);
#endif	
			m_pClient->ProcessMessageOut(theMessage);
            
            return m_pClient->CalcReturnVal(lRequestNumber);
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
    
    return (-1);
}




int OT_API::notarizeDeposit(OTIdentifier	& SERVER_ID,
							 OTIdentifier	& USER_ID,
							 OTIdentifier	& ACCT_ID,
							 OTString		& THE_PURSE)
{
	const char * szFuncName = "OT_API::notarizeDeposit";
	// -----------------------------------------------------
    OTString strPurseReason        ("Depositing a cash purse. Enter passphrase for the purse.");
    OTPasswordData thePWDataWallet ("Depositing a cash purse. Enter master passphrase for wallet.");
    // -----------------------------------------------------
	OTPseudonym * pNym = this->GetOrLoadPrivateNym(USER_ID, false, szFuncName, &thePWDataWallet); // These copiously log, and ASSERT.
	if (NULL == pNym) return (-1);
	// By this point, pNym is a good pointer, and is on the wallet. (No need to cleanup.)
	// -----------------------------------------------------
	OTServerContract *	pServer = this->GetServer(SERVER_ID, szFuncName); // This ASSERTs and logs already.
	if (NULL == pServer) return (-1);
	// By this point, pServer is a good pointer.  (No need to cleanup.)
	// -----------------------------------------------------
	OTAccount * pAccount = this->GetOrLoadAccount(*pNym, ACCT_ID, SERVER_ID, szFuncName);
	if (NULL == pAccount) return (-1);
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
        
        // -----------------------------------------------------
        // What's going on here?
        // A purse can be encrypted by a private key (controlled by a Nym) or by a symmetric
        // key (embedded inside the purse along with a corresponding master key.) The below
        // function is what actually loads up pPurse from string (THE_PURSE) and this call
        // also returns pOwner, which is a pointer to a special wrapper class (which you must
        // delete, when you're done with it) which contains a pointer EITHER to the owner Nym
        // for that purse, OR to the "owner" symmetric key for that purse.
        //
        // This way, any subsequent purse operations can use pOwner, regardless of whether there
        // is actually a Nym inside, or a symmetric key. (None of the purse operations will care,
        // since they can use pOwner either way.)
        //
        OTPassword  thePassword;
        OTPurse     theSourcePurse(thePurse);

        OTNym_or_SymmetricKey * pPurseOwner = this->LoadPurseAndOwnerForMerge(THE_PURSE, theSourcePurse, thePassword,
                                                                              false, //bCanBePublic=false by default. MUST be private, if a nym.
                                                                              &USER_ID, // This can be NULL, **IF** purse is password-protected. (It's just ignored in that case.) Otherwise if it's Nym-protected, the purse will have a NymID on it already, which is what LoadPurseAndOwnerForMerge will try first. If not (it's optional), then USER_ID is the ID it will try next, before failing altogether.
                                                                            &strPurseReason);
        OTCleanup<OTNym_or_SymmetricKey> theOwnerAngel(pPurseOwner);
        // -----------------------------------------------------------------
		if (NULL != pPurseOwner)
        {
            OTNym_or_SymmetricKey theServerNymAsOwner(*pServerNym);

			while (!theSourcePurse.IsEmpty())
			{
				OTToken * pToken = theSourcePurse.Pop(*pPurseOwner);
				
				if (NULL != pToken)
				{
					// TODO need 2-recipient envelopes. My request to the server is encrypted to the server's nym,
					// but it should be encrypted to my Nym also, so both have access to decrypt it.
					
					// Now the token is ready, let's add it to a purse
					// By pushing theToken into thePurse with *pServerNym, I encrypt it to pServerNym.
					// So now only the server Nym can decrypt that token and pop it out of that purse.
					if (false == pToken->ReassignOwnership(*pPurseOwner,         // must be private, if a nym.
                                                           theServerNymAsOwner)) // can be public, if a nym.
					{
						OTLog::Error("OT_API::notarizeDeposit: Error re-assigning ownership of token (to server.)\n");
						delete pToken; pToken = NULL;
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
						
						thePurse.Push(theServerNymAsOwner, *pToken);
						
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
        }
		// ---------------------------------------------
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
            theMessage.SetAcknowledgments(*pNym); // Must be called AFTER theMessage.m_strServerID is already set. (It uses it.)

			theMessage.m_strAcctID			= strFromAcct;
			theMessage.m_ascPayload			= ascLedger;
			
            OTIdentifier NYMBOX_HASH;
            const std::string str_server(strServerID.Get());
            const bool bNymboxHash = pNym->GetNymboxHash(str_server, NYMBOX_HASH);
            NYMBOX_HASH.GetString(theMessage.m_strNymboxHash);
            
            if (!bNymboxHash)
                OTLog::vError("Failed getting NymboxHash from Nym for server: %s\n",
                              str_server.c_str());

			// (2) Sign the Message 
			theMessage.SignContract(*pNym);		
			
			// (3) Save the Message (with signatures and all, back to its internal member m_strRawFile.)
			theMessage.SaveContract();
			
			// (Send it)
#if defined(OT_ZMQ_MODE)
			m_pClient->SetFocusToServerAndNym(*pServer, *pNym, this->m_pTransportCallback);
#endif	
			m_pClient->ProcessMessageOut(theMessage);	
			
            return m_pClient->CalcReturnVal(lRequestNumber);
            
		} // bSuccess
		else 
		{
			delete pItem;		pItem = NULL;
			delete pTransaction;pTransaction = NULL;
			
			// IF FAILED, ADD TRANSACTION NUMBER BACK TO LIST OF AVAILABLE NUMBERS.
			pNym->AddTransactionNum(*pNym, strServerID, lStoredTransactionNumber, true); // bSave=true								
		}
	} // if (pServerNym)
    
    return (-1);
}



// Let's pretend you are paying a dollar dividend for Pepsi shares...
// Therefore ACCT_ID needs to be a dollar account, and SHARES_ASSET_ID needs
// to be the Pepsi asset type ID. (NOT the dollar asset type ID...)
//
int OT_API::payDividend(OTIdentifier	& SERVER_ID,
                        OTIdentifier	& ISSUER_USER_ID,           // must be issuer of SHARES_ASSET_TYPE_ID
                        OTIdentifier	& DIVIDEND_FROM_ACCT_ID,    // if dollars paid for pepsi shares, then this is the issuer's dollars account.
                        OTIdentifier	& SHARES_ASSET_TYPE_ID,     // if dollars paid for pepsi shares, then this is the pepsi shares asset type id.
                        OTString        & DIVIDEND_MEMO,            // a message attached to the payout request.
                        const long		& AMOUNT_PER_SHARE) // number of dollars to be paid out PER SHARE (multiplied by total number of shares issued.)
{
	const char * szFuncName = "OT_API::payDividend";
	// -----------------------------------------------------
	OTPseudonym * pNym = this->GetOrLoadPrivateNym(ISSUER_USER_ID, false, szFuncName); // These copiously log, and ASSERT.
	if (NULL == pNym) return (-1);
	// By this point, pNym is a good pointer, and is on the wallet. (No need to cleanup.)
	// -----------------------------------------------------
	OTServerContract *	pServer = this->GetServer(SERVER_ID, szFuncName); // This ASSERTs and logs already.
	if (NULL == pServer) return (-1);
	// By this point, pServer is a good pointer.  (No need to cleanup.)
	// -----------------------------------------------------
	OTAccount * pDividendSourceAccount = this->GetOrLoadAccount(*pNym, DIVIDEND_FROM_ACCT_ID, SERVER_ID, szFuncName);
	if (NULL == pDividendSourceAccount) return (-1);
	// By this point, pDividendSourceAccount is a good pointer, and is on the wallet. (No need to cleanup.)
	// -----------------------------------------------------
	OTAssetContract * pSharesContract = this->GetAssetType(SHARES_ASSET_TYPE_ID, szFuncName); // This ASSERTs and logs already.
	if (NULL == pSharesContract) return (-1);
	// By this point, pSharesContract is a good pointer.  (No need to cleanup.)
	// -----------------------------------------------------
	OTWallet * pWallet = GetWallet(szFuncName); // This logs and ASSERTs already.
	if (NULL == pWallet) return (-1);
	// -----------------------------------------------------
    OTAccount * pSharesIssuerAcct = pWallet->GetIssuerAccount(SHARES_ASSET_TYPE_ID);

	if (NULL == pSharesIssuerAcct)
    {
        OTLog::vError("%s: Failure: Unable to find issuer account for the shares asset type. "
                      "Are you sure you're the issuer?\n", szFuncName);
        return (-1);
    }
    const OTIdentifier SHARES_ISSUER_ACCT_ID(*pSharesIssuerAcct);
    // -----------------------------------------------------
	if (!pDividendSourceAccount->VerifyOwner(*pNym))
    {
        OTLog::vError("%s: Failure: Nym doesn't verify as owner of the source account for the dividend payout.\n", 
                      szFuncName);
        return (-1);
    }
    // -----------------------------------------------------
	if (!pSharesIssuerAcct->VerifyOwner(*pNym))
    {
        OTLog::vError("%s: Failure: Nym doesn't verify as owner of issuer account for the shares "
                      "(the shares we're paying the dividend on...)\n", 
                      szFuncName);
        return (-1);
    }
    // -----------------------------------------------------
    OT_ASSERT_MSG(pSharesIssuerAcct->GetBalance() <= 0, "Assert (strange): issuer account should never have a higher-than-zero balance.\n");
    
	if (0 == pSharesIssuerAcct->GetBalance())
    {
        OTLog::vError("%s: Failure: There are no shares issued for that asset type. "
                      "(Therefore you cannot pay any dividend...)\n", szFuncName);
        return (-1);
    }
	// -----------------------------------------------------
    const long lAmountPerShare      = AMOUNT_PER_SHARE;
    
    if (lAmountPerShare <= 0)
    {
        OTLog::vError("%s: Failure: The amount per share must be larger than zero.\n", szFuncName);
        return (-1);
    }
    // -----------------------------------------------------
    // If there are 100,000 Pepsi shares, then the Pepsi issuer acct will have -100,000 balance.
    // Therefore we multiply by -1, resulting in 100,000. Then we multiple that by the amount to be
    // paid per share, let's say $5, resulting in a lTotalCostOfDividend of $500,000 that must be
    // available in the dollar account (in order to successfully pay this dividend.)
    //
    const long lTotalCostOfDividend = ((-1) * pSharesIssuerAcct->GetBalance()) * lAmountPerShare;
	// -----------------------------------------------------    
    // Let's make sure we have enough money in the dividend source account, to pay the total cost..
    //
    if (pDividendSourceAccount->GetBalance() < lTotalCostOfDividend)
    {
        OTLog::vError("%s: Failure: There's not enough (%ld) in the source account, to cover "
                      "the total cost of the dividend (%ld.)\n", szFuncName, pDividendSourceAccount->GetBalance(),
                      lTotalCostOfDividend);
        return (-1);        
    }
	// -----------------------------------------------------    
    OTMessage theMessage;
		
	OTString strServerID(SERVER_ID), strNymID(ISSUER_USER_ID), strFromAcct(DIVIDEND_FROM_ACCT_ID);
	
	long lStoredTransactionNumber=0;
	bool bGotTransNum = pNym->GetNextTransactionNum(*pNym, strServerID, lStoredTransactionNumber);
	
	if (bGotTransNum)
	{
		// -----------------------------------------------------------------------
		// Expiration (ignored by server -- it sets its own for its vouchers.)
		const	time_t	VALID_FROM	= time(NULL); // This time is set to TODAY NOW
		const	time_t	VALID_TO	= VALID_FROM + 15552000; // 6 months.
		// -----------------------------------------------------------------------
		// The server only uses the amount and asset type from this cheque when it
		// constructs the actual voucher (to the dividend payee.) And remember there
        // might be a hundred shareholders, so the server would create a hundred
        // vouchers in that case.
        //
		OTCheque theRequestVoucher(SERVER_ID, SHARES_ASSET_TYPE_ID); // <====== Server needs this (SHARES_ASSET_TYPE_ID)

		bool bIssueCheque = theRequestVoucher.IssueCheque(lAmountPerShare, // <====== Server needs this (lAmountPerShare.)
                                                          lStoredTransactionNumber, // server actually ignores this and supplies its own transaction number for any vouchers.
														  VALID_FROM, VALID_TO, SHARES_ISSUER_ACCT_ID, ISSUER_USER_ID, DIVIDEND_MEMO);
        
        /*
         NOTE: The above cheque isn't actually USED for anything, except as a vehicle to send additional
         data to the server. For example, the server will need to know the asset type ID for the shares.
         It gets that information from this voucher's asset type ID. It will also need to know the amount-
         per-share, which is also on this voucher, as its amount. The voucher code already does a similar
         thing, and this code already copied the voucher code since they were so similar, so we're just
         using the same mechanism here. It's consistent.
         On the server side, we'll also need to know the issuer account ID for the shares asset type, so
         we set that as the "from" account on the request voucher (again, just as a way of transmitting it.)
         */
		// --------------------------------------------------
		OTLedger * pInbox	= pDividendSourceAccount->LoadInbox(*pNym);
		OTLedger * pOutbox	= pDividendSourceAccount->LoadOutbox(*pNym);
		
		OTCleanup<OTLedger> theInboxAngel (pInbox );
		OTCleanup<OTLedger> theOutboxAngel(pOutbox);
		
		if (NULL == pInbox)
		{
			OTLog::vOutput(0, "%s: Failed loading inbox for acct %s\n", szFuncName, strFromAcct.Get());
			
			// IF FAILED, ADD TRANSACTION NUMBER BACK TO LIST OF AVAILABLE NUMBERS.
			pNym->AddTransactionNum(*pNym, strServerID, lStoredTransactionNumber, true); // bSave=true								
		}
		else if (NULL == pOutbox)
		{
			OTLog::vOutput(0, "%s: Failed loading outbox for acct %s\n", szFuncName, strFromAcct.Get());
			
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
			OTTransaction * pTransaction = OTTransaction::GenerateTransaction (ISSUER_USER_ID, DIVIDEND_FROM_ACCT_ID, SERVER_ID, 
																			   OTTransaction::payDividend, lStoredTransactionNumber); 
			// set up the transaction item (each transaction may have multiple items...)
			OTItem * pItem		= OTItem::CreateItemFromTransaction(*pTransaction, OTItem::payDividend);
			pItem->SetAmount(lTotalCostOfDividend); // <=== Notice, while the CHEQUE is for lAmountPerShare, the item's AMOUNT is set to lTotalCostOfDividend.
			OTString strNote("Pay Dividend: ");     // The server just needs both of those, so that's how we send them (Similar to the voucher code.)
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
			OTItem * pBalanceItem = pInbox->GenerateBalanceStatement(lTotalCostOfDividend*(-1), *pTransaction, *pNym, *pDividendSourceAccount, *pOutbox);
			
            // Notice the balance agreement is made for the "total cost of the dividend", which we calculated as the issuer's
            // account balance, times -1, times the amount per share. So for 100,000 shares of Pepsi, at a dividend payout of
            // $2 per share, then $200,000 must be removed from my dollar account, in order to cover it. Therefore I sign a
            // balance agreement for $200,000. The server removes it all at once, and then iterates through a loop, sending
            // vouchers to people. If any fail, or there is any left over, then vouchers are sent back to pNym again, containing
            // the difference.
            // todo failsafe: We can't just loop, long-term, and send a voucher at the end. What if it crashes halfway through
            // the loop? It seems that the dividend payout still needs to be "REGISTERED" somewhere until successfully completed.
            // (And therefore, that this concept must be repeated throughout OT for other transactions, not just this example.)
            // This is already done with Cron, but just thinking about how to best do it for "single action" transactions.
            
			if (NULL != pBalanceItem)
				pTransaction->AddItem(*pBalanceItem); // Better not be NULL... message will fail... But better check anyway.
			// ---------------------------------------------
			// sign the transaction
			pTransaction->SignContract(*pNym);
			pTransaction->SaveContract();
			
			// set up the ledger
			OTLedger theLedger(ISSUER_USER_ID, DIVIDEND_FROM_ACCT_ID, SERVER_ID);
			theLedger.GenerateLedger(DIVIDEND_FROM_ACCT_ID, SERVER_ID, OTLedger::message); // bGenerateLedger defaults to false, which is correct.
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
            theMessage.SetAcknowledgments(*pNym); // Must be called AFTER theMessage.m_strServerID is already set. (It uses it.)

			theMessage.m_strAcctID			= strFromAcct;
			theMessage.m_ascPayload			= ascLedger;
			
            OTIdentifier NYMBOX_HASH;
            const std::string str_server(strServerID.Get());
            const bool bNymboxHash = pNym->GetNymboxHash(str_server, NYMBOX_HASH);
            NYMBOX_HASH.GetString(theMessage.m_strNymboxHash);
            
            if (!bNymboxHash)
                OTLog::vError("%s: Failed getting NymboxHash from Nym for server: %s\n",
                              szFuncName, str_server.c_str());

			// (2) Sign the Message 
			theMessage.SignContract(*pNym);		
			
			// (3) Save the Message (with signatures and all, back to its internal member m_strRawFile.)
			theMessage.SaveContract();
			
			// (Send it)
#if defined(OT_ZMQ_MODE)
			m_pClient->SetFocusToServerAndNym(*pServer, *pNym, this->m_pTransportCallback);
#endif	
			m_pClient->ProcessMessageOut(theMessage);
            
            return m_pClient->CalcReturnVal(lRequestNumber);
		}
	}
	else 
		OTLog::vOutput(0, "%s: No Transaction Numbers were available. "
                       "Suggest requesting the server for a new one.\n", szFuncName);
    
    return (-1);
}







int OT_API::withdrawVoucher(OTIdentifier	& SERVER_ID,
							 OTIdentifier	& USER_ID,
							 OTIdentifier	& ACCT_ID,
							 OTIdentifier	& RECIPIENT_USER_ID,
							 OTString		& CHEQUE_MEMO,
							 const long		& AMOUNT)
{
	const char * szFuncName = "OT_API::withdrawVoucher";
	// -----------------------------------------------------
	OTPseudonym * pNym = this->GetOrLoadPrivateNym(USER_ID, false, szFuncName); // These copiously log, and ASSERT.
	if (NULL == pNym) return (-1);
	// By this point, pNym is a good pointer, and is on the wallet. (No need to cleanup.)
	// -----------------------------------------------------
	OTServerContract *	pServer = this->GetServer(SERVER_ID, szFuncName); // This ASSERTs and logs already.
	if (NULL == pServer) return (-1);
	// By this point, pServer is a good pointer.  (No need to cleanup.)
	// -----------------------------------------------------
	OTAccount * pAccount = this->GetOrLoadAccount(*pNym, ACCT_ID, SERVER_ID, szFuncName);
	if (NULL == pAccount) return (-1);
	// By this point, pAccount is a good pointer, and is on the wallet. (No need to cleanup.)
	// -----------------------------------------------------				
	OTIdentifier	CONTRACT_ID;
	OTString		strContractID;

	CONTRACT_ID = pAccount->GetAssetTypeID();
	CONTRACT_ID.GetString(strContractID);
	// -----------------------------------------------------------------
	OTMessage theMessage;
	
	const long lAmount = AMOUNT;
	
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
            theMessage.SetAcknowledgments(*pNym); // Must be called AFTER theMessage.m_strServerID is already set. (It uses it.)

			theMessage.m_strAcctID			= strFromAcct;
			theMessage.m_ascPayload			= ascLedger;
			
            OTIdentifier NYMBOX_HASH;
            const std::string str_server(strServerID.Get());
            const bool bNymboxHash = pNym->GetNymboxHash(str_server, NYMBOX_HASH);
            NYMBOX_HASH.GetString(theMessage.m_strNymboxHash);
            
            if (!bNymboxHash)
                OTLog::vError("Failed getting NymboxHash from Nym for server: %s\n",
                              str_server.c_str());

			// (2) Sign the Message 
			theMessage.SignContract(*pNym);		
			
			// (3) Save the Message (with signatures and all, back to its internal member m_strRawFile.)
			theMessage.SaveContract();
			
			// (Send it)
#if defined(OT_ZMQ_MODE)
			m_pClient->SetFocusToServerAndNym(*pServer, *pNym, this->m_pTransportCallback);
#endif	
			m_pClient->ProcessMessageOut(theMessage);
            
            return m_pClient->CalcReturnVal(lRequestNumber);
		}
	}
	else 
		OTLog::Output(0, "No Transaction Numbers were available. Suggest requesting the server for a new one.\n");
    
    return (-1);
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
	OTPseudonym * pNym = this->GetOrLoadPrivateNym(USER_ID, false, szFuncName); // These copiously log, and ASSERT.
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

int OT_API::depositCheque(OTIdentifier	& SERVER_ID,
						   OTIdentifier	& USER_ID,
						   OTIdentifier	& ACCT_ID,
						   OTString		& THE_CHEQUE)
{
	const char * szFuncName = "OT_API::depositCheque";
	// -----------------------------------------------------
	OTPseudonym * pNym = this->GetOrLoadPrivateNym(USER_ID, false, szFuncName); // These copiously log, and ASSERT.
	if (NULL == pNym) return (-1);
	// By this point, pNym is a good pointer, and is on the wallet. (No need to cleanup.)
	// -----------------------------------------------------
	OTServerContract *	pServer = this->GetServer(SERVER_ID, szFuncName); // This ASSERTs and logs already.
	if (NULL == pServer) return (-1);
	// By this point, pServer is a good pointer.  (No need to cleanup.)
	// -----------------------------------------------------
	OTAccount * pAccount = this->GetOrLoadAccount(*pNym, ACCT_ID, SERVER_ID, szFuncName);
	if (NULL == pAccount) return (-1);
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
            theMessage.SetAcknowledgments(*pNym); // Must be called AFTER theMessage.m_strServerID is already set. (It uses it.)

			theMessage.m_strAcctID			= strFromAcct;
			theMessage.m_ascPayload			= ascLedger;
			
            OTIdentifier NYMBOX_HASH;
            const std::string str_server(strServerID.Get());
            const bool bNymboxHash = pNym->GetNymboxHash(str_server, NYMBOX_HASH);
            NYMBOX_HASH.GetString(theMessage.m_strNymboxHash);
            
            if (!bNymboxHash)
                OTLog::vError("Failed getting NymboxHash from Nym for server: %s\n",
                              str_server.c_str());

			// (2) Sign the Message 
			theMessage.SignContract(*pNym);		
			
			// (3) Save the Message (with signatures and all, back to its internal member m_strRawFile.)
			theMessage.SaveContract();
			
			// (Send it)
#if defined(OT_ZMQ_MODE)
			m_pClient->SetFocusToServerAndNym(*pServer, *pNym, this->m_pTransportCallback);
#endif	
			m_pClient->ProcessMessageOut(theMessage);
            
            return m_pClient->CalcReturnVal(lRequestNumber);
		}
	} // bSuccess
    
    return -1;
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
int OT_API::depositPaymentPlan(const OTIdentifier	& SERVER_ID,
								const OTIdentifier	& USER_ID,
								const OTString		& THE_PAYMENT_PLAN)
{
	const char * szFuncName = "OT_API::depositPaymentPlan";
	// -----------------------------------------------------
	OTServerContract *	pServer = this->GetServer(SERVER_ID, szFuncName); // This ASSERTs and logs already.
	if (NULL == pServer) return (-1);
	// By this point, pServer is a good pointer.  (No need to cleanup.)
	// -----------------------------------------------------------------
	OTPseudonym * pNym = this->GetOrLoadPrivateNym(USER_ID, false, szFuncName); // This ASSERTs and logs already.
	if (NULL == pNym) return (-1);
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
		if (NULL == pAccount) return (-1);
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
        theMessage.SetAcknowledgments(*pNym); // Must be called AFTER theMessage.m_strServerID is already set. (It uses it.)

		theMessage.m_strAcctID			= strFromAcct;
		theMessage.m_ascPayload			= ascLedger;
		
        OTIdentifier NYMBOX_HASH;
        const std::string str_server(strServerID.Get());
        const bool bNymboxHash = pNym->GetNymboxHash(str_server, NYMBOX_HASH);
        NYMBOX_HASH.GetString(theMessage.m_strNymboxHash);
        
        if (!bNymboxHash)
            OTLog::vError("Failed getting NymboxHash from Nym for server: %s\n",
                          str_server.c_str());

		// (2) Sign the Message 
		theMessage.SignContract(*pNym);		
		
		// (3) Save the Message (with signatures and all, back to its internal member m_strRawFile.)
		theMessage.SaveContract();
		
		// (Send it)
#if defined(OT_ZMQ_MODE)
		m_pClient->SetFocusToServerAndNym(*pServer, *pNym, this->m_pTransportCallback);
#endif	
		m_pClient->ProcessMessageOut(theMessage);	
        
        return m_pClient->CalcReturnVal(lRequestNumber);
	} // thePlan.LoadContractFromString()
	else 
	{
		OTLog::Output(0, "Unable to load payment plan from string, or verify it. Sorry.\n");
	}
    
    return (-1);
}



// If a smart contract is already running on a specific server, and the Nym in question (USER_ID)
// is an authorized agent for that smart contract, then he can trigger clauses. All he needs is
// the transaction ID for the smart contract, and the name of the clause.
//
int OT_API::triggerClause(const OTIdentifier	& SERVER_ID,
						   const OTIdentifier	& USER_ID,
						   const long			& lTransactionNum,
						   const OTString		& strClauseName,
						   const OTString		* pStrParam/*=NULL*/)
{
	const char * szFuncName = "OT_API::triggerClause";
	// -----------------------------------------------------
	OTPseudonym * pNym = this->GetOrLoadPrivateNym(USER_ID, false, szFuncName); // This ASSERTs and logs already.
	if (NULL == pNym) return (-1);
	// By this point, pNym is a good pointer, and is on the wallet.
	//  (No need to cleanup.)
	// -----------------------------------------------------
	OTServerContract *	pServer = this->GetServer(SERVER_ID, szFuncName); // This ASSERTs and logs already.
	if (NULL == pServer) return (-1);
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
    theMessage.SetAcknowledgments(*pNym); // Must be called AFTER theMessage.m_strServerID is already set. (It uses it.)

	theMessage.m_lTransactionNum	= lTransactionNum;
	theMessage.m_strNymID2			= strClauseName;
	
	// Optional string parameter. Available as "param_string" 
	// inside the script.
	//
	if ((NULL != pStrParam) && (pStrParam->Exists()))
		theMessage.m_ascPayload.SetString(*pStrParam); // <===

    OTIdentifier NYMBOX_HASH;
    const std::string str_server(strServerID.Get());
    const bool bNymboxHash = pNym->GetNymboxHash(str_server, NYMBOX_HASH);
    NYMBOX_HASH.GetString(theMessage.m_strNymboxHash);
    
    if (!bNymboxHash)
        OTLog::vError("Failed getting NymboxHash from Nym for server: %s\n",
                      str_server.c_str());

	// (2) Sign the Message 
	theMessage.SignContract(*pNym);		
	
	// (3) Save the Message (with signatures and all, back to its internal member m_strRawFile.)
	theMessage.SaveContract();
	
	// (Send it)
#if defined(OT_ZMQ_MODE)
	m_pClient->SetFocusToServerAndNym(*pServer, *pNym, this->m_pTransportCallback);
#endif	
	m_pClient->ProcessMessageOut(theMessage);
	
    return m_pClient->CalcReturnVal(lRequestNumber);
}



int OT_API::activateSmartContract(const OTIdentifier	& SERVER_ID,
								   const OTIdentifier	& USER_ID,
								   const OTString		& THE_SMART_CONTRACT)
{
	const char * szFuncName = "OT_API::activateSmartContract";
	// -----------------------------------------------------
	OTPseudonym * pNym = this->GetOrLoadPrivateNym(USER_ID, false, szFuncName); // This ASSERTs and logs already.
	if (NULL == pNym) return (-1);
	// By this point, pNym is a good pointer, and is on the wallet.
	//  (No need to cleanup.)
	// -----------------------------------------------------
	OTServerContract *	pServer = this->GetServer(SERVER_ID, szFuncName); // This ASSERTs and logs already.
	if (NULL == pServer) return (-1);
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
			return (-1);
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
			return -1;
		}
		if (SERVER_ID != theContract.GetServerID())
		{
			OTLog::Output(0, "OT_API::activateSmartContract: Failed. The server ID passed in doesn't match the one on the contract itself.\n");
			return -1;
		}
		// ----------------------------------------------------------
		if (!(pParty->GetAccountCount() > 0))
		{
			OTLog::Output(0, "OT_API::activateSmartContract: Failed. The activating Nym must not only be the authorizing agent for one of the parties, "
						   "but must also be the authorized agent for one of that party's asset accounts. That party must have at least one asset account "
						   "for this reason. (See code comment below this message, in the code.)\n");
			return -1;
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
			return -1;
		}
		// ----------------------------------------------------------
		const OTString &	strAcctID = pAcct->GetAcctID();
		
		if (!strAcctID.Exists())
		{
			OTLog::vOutput(0, "OT_API::activateSmartContract: Failed. The Account ID is blank for asset acct (%s) for party (%s). Did you confirm "
						   "this account, before trying to activate this contract?\n", pAcct->GetName().Get(), pParty->GetPartyName().c_str());
			return -1;
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
			return -1;
		}
		if (!pNym->VerifyIssuedNum(strServerID, lOpeningTransNo))
		{
			OTLog::vOutput(0, "OT_API::activateSmartContract: Failed. Opening Transaction # (%ld) wasn't valid/issued to this Nym, "
						   "for asset acct (%s) for party (%s). Did you confirm this account and party, before trying to activate this contract?\n", 
						   lOpeningTransNo, pAcct->GetName().Get(), pParty->GetPartyName().c_str());
			return -1;
		}
		if (!pNym->VerifyIssuedNum(strServerID, lClosingTransNo))
		{
			OTLog::vOutput(0, "OT_API::activateSmartContract: Failed. Closing Transaction # (%ld) wasn't issued to this Nym, "
						   "for asset acct (%s) for party (%s). Did you confirm this account and party, before trying to activate this contract?\n", 
						   lClosingTransNo, pAcct->GetName().Get(), pParty->GetPartyName().c_str());
			return -1;
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
			return -1;
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
        theMessage.SetAcknowledgments(*pNym); // Must be called AFTER theMessage.m_strServerID is already set. (It uses it.)

		theAcctID.GetString(theMessage.m_strAcctID);
		theMessage.m_ascPayload			= ascLedger;
		
        OTIdentifier NYMBOX_HASH;
        const std::string str_server(strServerID.Get());
        const bool bNymboxHash = pNym->GetNymboxHash(str_server, NYMBOX_HASH);
        NYMBOX_HASH.GetString(theMessage.m_strNymboxHash);
        
        if (!bNymboxHash)
            OTLog::vError("Failed getting NymboxHash from Nym for server: %s\n",
                          str_server.c_str());

		// (2) Sign the Message 
		theMessage.SignContract(*pNym);		
		
		// (3) Save the Message (with signatures and all, back to its internal member m_strRawFile.)
		theMessage.SaveContract();
		
		// (Send it)
#if defined(OT_ZMQ_MODE)
		m_pClient->SetFocusToServerAndNym(*pServer, *pNym, this->m_pTransportCallback);
#endif	
		m_pClient->ProcessMessageOut(theMessage);
        
        return m_pClient->CalcReturnVal(lRequestNumber);
        
	} // theContract.LoadContractFromString()
	else
		OTLog::vOutput(0, "OT_API::activateSmartContract: Unable to load smart contract from string:\n\n%s\n\n", 
					   THE_SMART_CONTRACT.Get());
    
    return (-1);
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



// DONE: Change this into a TRANSACTION!
// (So there can be a transaction statement, since canceling a cron
// item removes a transaction number from your issued list.)
///-------------------------------------------------------
/// CANCEL A SPECIFIC OFFER (THAT SAME NYM PLACED PREVIOUSLY ON SAME SERVER.)
/// By transaction number as key.
///
int OT_API::cancelCronItem(const OTIdentifier & SERVER_ID, 
							const OTIdentifier & USER_ID, 
							const OTIdentifier & ASSET_ACCT_ID, 
							const long & lTransactionNum) // so the server can lookup the offer in Cron.
{
	const char * szFuncName = "OT_API::cancelCronItem";
	// -----------------------------------------------------
	OTPseudonym * pNym = this->GetOrLoadPrivateNym(USER_ID, false, szFuncName); // This ASSERTs and logs already.
	if (NULL == pNym) return (-1);
	// By this point, pNym is a good pointer, and is on the wallet.
	//  (No need to cleanup.)
	// -----------------------------------------------------
	OTServerContract *	pServer = this->GetServer(SERVER_ID, szFuncName); // This ASSERTs and logs already.
	if (NULL == pServer) return (-1);
	// By this point, pServer is a good pointer.  (No need to cleanup.)
	// -----------------------------------------------------
	OTMessage	theMessage;
	
	long lRequestNumber = 0;
	
	const OTString strServerID(SERVER_ID), strNymID(USER_ID);
    
	if (pNym->GetTransactionNumCount(strServerID) < 1)
    {
        OTLog::Output(0, "OT_API::cancelCronItem: At least 1 Transaction Number is necessary to cancel any cron item. "
                      "Try requesting the server for more numbers (you are low.)\n"); 
        return (-1);
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
        theMessage.SetAcknowledgments(*pNym); // Must be called AFTER theMessage.m_strServerID is already set. (It uses it.)

        theMessage.m_strAcctID			= str_ASSET_ACCT_ID;
        theMessage.m_ascPayload			= ascLedger;
        
        OTIdentifier NYMBOX_HASH;
        const std::string str_server(strServerID.Get());
        const bool bNymboxHash = pNym->GetNymboxHash(str_server, NYMBOX_HASH);
        NYMBOX_HASH.GetString(theMessage.m_strNymboxHash);
        
        if (!bNymboxHash)
            OTLog::vError("Failed getting NymboxHash from Nym for server: %s\n",
                          str_server.c_str());

        // (2) Sign the Message 
        theMessage.SignContract(*pNym);		
        
        // (3) Save the Message (with signatures and all, back to its internal member m_strRawFile.)
        theMessage.SaveContract();
			
        // (Send it)
#if defined(OT_ZMQ_MODE)
        m_pClient->SetFocusToServerAndNym(*pServer, *pNym, this->m_pTransportCallback);
#endif	
        m_pClient->ProcessMessageOut(theMessage);
        
        return m_pClient->CalcReturnVal(lRequestNumber);
	} // got transaction number.
    
    return (-1);
}





// ----------------------------------------------------------------
// ISSUE MARKET OFFER
//
//
int OT_API::issueMarketOffer( const OTIdentifier	& SERVER_ID,
							  const OTIdentifier	& USER_ID,
							  // -------------------------------------------
							  const OTIdentifier	& ASSET_ACCT_ID,
							  const OTIdentifier	& CURRENCY_ACCT_ID,
							  // -------------------------------------------
							  const long			& MARKET_SCALE,	// Defaults to minimum of 1. Market granularity.
							  const long			& MINIMUM_INCREMENT, // This will be multiplied by the Scale. Min 1.
							  const long			& TOTAL_ASSETS_ON_OFFER, // Total assets available for sale or purchase. Will be multiplied by minimum increment.
							  const long			& PRICE_LIMIT,    // Per Minimum Increment...
							  const bool			  bBuyingOrSelling, //  BUYING == false, SELLING == true.
                             // -------------------------------------------
                              const time_t            tLifespanInSeconds/*=86400*/) // 86400 == 1 day.
{
	// -----------------------------------------------------
	OTPseudonym * pNym = this->GetOrLoadPrivateNym(USER_ID, false, __FUNCTION__); // This ASSERTs and logs already.
	if (NULL == pNym) return (-1);
	// By this point, pNym is a good pointer, and is on the wallet. (No need to cleanup.)
	// -----------------------------------------------------
	OTServerContract *	pServer = this->GetServer(SERVER_ID, __FUNCTION__); // This ASSERTs and logs already.
	if (NULL == pServer) return (-1);
	// By this point, pServer is a good pointer.  (No need to cleanup.)
	// -----------------------------------------------------
	OTAccount * pAssetAccount = this->GetOrLoadAccount(*pNym, ASSET_ACCT_ID, SERVER_ID, __FUNCTION__);
	if (NULL == pAssetAccount) return (-1);
	// By this point, pAssetAccount is a good pointer.  (No need to cleanup.)
	// -----------------------------------------------------
	OTAccount * pCurrencyAccount = this->GetOrLoadAccount(*pNym, CURRENCY_ACCT_ID, SERVER_ID, __FUNCTION__);
	if (NULL == pCurrencyAccount) return (-1);
	// By this point, pCurrencyAccount is a good pointer.  (No need to cleanup.)
	// -----------------------------------------------------
    const OTIdentifier & ASSET_TYPE_ID     = pAssetAccount   ->GetAssetTypeID();
    const OTIdentifier & CURRENCY_TYPE_ID  = pCurrencyAccount->GetAssetTypeID();
    // ------------------------------------
	if (ASSET_TYPE_ID == CURRENCY_TYPE_ID)
    {
        OTLog::vOutput(0, "%s: The asset account and currency account cannot have the same asset type ID. (You can't, for "
                       "example, trade dollars against other dollars. Why bother trading them in the first place?)\n",
                       __FUNCTION__);
        return (-1);
    }
    // -----------------------------------------------------
	OTMessage       theMessage;
	long            lRequestNumber = 0;
	const OTString  strServerID(SERVER_ID),
                    strNymID   (USER_ID);
	// -----------------------------------------------------
	if (pNym->GetTransactionNumCount(strServerID) < 3)
    {
        OTLog::vOutput(0, "%s: At least 3 Transaction Numbers are necessary to issue a market offer. "
                       "Try requesting the server for more (you are low.)\n", __FUNCTION__);
        return (-1);
    }
    // ------------------------------------
	long lStoredTransactionNumber=0, lAssetAcctClosingNo=0, lCurrencyAcctClosingNo=0;
	bool bGotTransNum = pNym->GetNextTransactionNum(*pNym, strServerID, lStoredTransactionNumber, false);   // bSave=false
	bool bGotAssetClosingNum = pNym->GetNextTransactionNum(*pNym, strServerID, lAssetAcctClosingNo, false); // bSave=false -- (true by default, FYI.)
	bool bGotCurrencyClosingNum = pNym->GetNextTransactionNum(*pNym, strServerID, lCurrencyAcctClosingNo, true); // bSave=true 
    // -------------------------------------------------------------------
	if (!bGotTransNum || !bGotAssetClosingNum || !bGotCurrencyClosingNum)
	{
		OTLog::vError("%s: Supposedly there were 3 transaction numbers available, but the call(s)\n"
                      "still failed. (Re-adding back to Nym, and failing out of this function.)\n",
                      __FUNCTION__);
        // ------------------------------------
        if (bGotTransNum)           pNym->AddTransactionNum(*pNym, strServerID, lStoredTransactionNumber, false); // bSave=true
        if (bGotAssetClosingNum)    pNym->AddTransactionNum(*pNym, strServerID, lAssetAcctClosingNo,      false); // bSave=true
        if (bGotCurrencyClosingNum) pNym->AddTransactionNum(*pNym, strServerID, lCurrencyAcctClosingNo,   false); // bSave=true
        // ------------------------------------
        if (bGotTransNum || bGotAssetClosingNum || bGotCurrencyClosingNum)
            pNym->SaveSignedNymfile(*pNym);
	}
    // -------------------------------------------------------------------
	else
	{
        const time_t VALID_FROM = this->GetTime();      // defaults to RIGHT NOW aka OT_API_GetTime() if set to 0 anyway.
        const time_t VALID_TO   = VALID_FROM +          // defaults to 24 hours (a "Day Order") aka OT_API_GetTime() + 86,400
                                  (0 == tLifespanInSeconds ? LENGTH_OF_DAY_IN_SECONDS : tLifespanInSeconds);
        // ------------------------------------
		long	lTotalAssetsOnOffer = 1,
				lMinimumIncrement   = 1, 
				lPriceLimit         = 1,  // your price limit, per scale of assets.
				lMarketScale        = 1;
		// -------------------------------------------------------------------
		if (TOTAL_ASSETS_ON_OFFER > 0) lTotalAssetsOnOffer = TOTAL_ASSETS_ON_OFFER; // otherwise, defaults to 1.
		if (MARKET_SCALE          > 0) lMarketScale        = MARKET_SCALE;          // otherwise, defaults to 1.
		if (MINIMUM_INCREMENT     > 0) lMinimumIncrement   = MINIMUM_INCREMENT;     // otherwise, defaults to 1.
		if (PRICE_LIMIT           > 0) lPriceLimit         = PRICE_LIMIT;           // otherwise, defaults to 1.
		// -------------------------------------------------------------------
		lMinimumIncrement   *= lMarketScale;       // minimum increment is PER SCALE.
//		lTotalAssetsOnOffer *= lMinimumIncrement;  // This was a bug. (Left as a warning.)
		// -------------------------------------------------------------------
		OTOffer theOffer(SERVER_ID, ASSET_TYPE_ID, CURRENCY_TYPE_ID, lMarketScale);
		// -------------------------------------------------------------------		
		OTTrade theTrade(SERVER_ID, 
						 ASSET_TYPE_ID, ASSET_ACCT_ID, 
						 USER_ID, 
						 CURRENCY_TYPE_ID, CURRENCY_ACCT_ID);
        // -------------------------------------------------------------------
		// MAKE OFFER...
		//
		bool bCreateOffer = theOffer.MakeOffer(bBuyingOrSelling,	// True == SELLING, False == BUYING
											   lPriceLimit,			// Per Minimum Increment...
											   lTotalAssetsOnOffer,	// Total assets available for sale or purchase.
											   lMinimumIncrement,	// The minimum increment that must be bought or sold for each transaction
											   lStoredTransactionNumber, // Transaction number matches on transaction, item, offer, and trade.
                                               VALID_FROM,  // defaults to RIGHT NOW aka OT_API_GetTime()
                                               VALID_TO);   // defaults to 24 hours (a "Day Order") aka OT_API_GetTime() + 86,400
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
			OTItem * pItem = OTItem::CreateItemFromTransaction(*pTransaction, OTItem::marketOffer, 
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
            theMessage.SetAcknowledgments(*pNym); // Must be called AFTER theMessage.m_strServerID is already set. (It uses it.)

			theMessage.m_strAcctID			= str_ASSET_ACCT_ID;
			theMessage.m_ascPayload			= ascLedger;
			
            OTIdentifier NYMBOX_HASH;
            const std::string str_server(strServerID.Get());
            const bool bNymboxHash = pNym->GetNymboxHash(str_server, NYMBOX_HASH);
            NYMBOX_HASH.GetString(theMessage.m_strNymboxHash);
            
            if (!bNymboxHash)
                OTLog::vError("%s: Failed getting NymboxHash from Nym for server: %s\n",
                              __FUNCTION__, str_server.c_str());

			// (2) Sign the Message 
			theMessage.SignContract(*pNym);		
			
			// (3) Save the Message (with signatures and all, back to its internal member m_strRawFile.)
			theMessage.SaveContract();
			
			// (Send it)
#if defined(OT_ZMQ_MODE)
			m_pClient->SetFocusToServerAndNym(*pServer, *pNym, this->m_pTransportCallback);
#endif	
			m_pClient->ProcessMessageOut(theMessage);
            
            return m_pClient->CalcReturnVal(lRequestNumber);
            
		} // if (bCreateOffer && bIssueTrade)
		else 
		{
			OTLog::vOutput(0, "%s: Unable to create offer or issue trade. Sorry.\n",
                           __FUNCTION__);
			
			// IF FAILED, add the transaction number (and closing number)
            // BACK to the list of available numbers.
            //
			pNym->AddTransactionNum(*pNym, strServerID, lStoredTransactionNumber,   false); // bSave defaults to true
            pNym->AddTransactionNum(*pNym, strServerID, lAssetAcctClosingNo,        false); 
            pNym->AddTransactionNum(*pNym, strServerID, lCurrencyAcctClosingNo,     true ); // bSave=true (No sense saving thrice in a row.)	
		}							
	} // got transaction number.
    
    return (-1);
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
int OT_API::getMarketList(const OTIdentifier & SERVER_ID, const OTIdentifier & USER_ID)
{
	const char * szFuncName = "OT_API::getMarketList";
	// -----------------------------------------------------
	OTPseudonym * pNym = this->GetOrLoadPrivateNym(USER_ID, false, szFuncName); // This ASSERTs and logs already.
	if (NULL == pNym) return (-1);
	// By this point, pNym is a good pointer, and is on the wallet.
	//  (No need to cleanup.)
	// -----------------------------------------------------
	OTServerContract *	pServer = this->GetServer(SERVER_ID, szFuncName); // This ASSERTs and logs already.
	if (NULL == pServer) return (-1);
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
    theMessage.SetAcknowledgments(*pNym); // Must be called AFTER theMessage.m_strServerID is already set. (It uses it.)

	// (2) Sign the Message 
	theMessage.SignContract(*pNym);		
	
	// (3) Save the Message (with signatures and all, back to its internal member m_strRawFile.)
	theMessage.SaveContract();
	
	// (Send it)
#if defined(OT_ZMQ_MODE)
	m_pClient->SetFocusToServerAndNym(*pServer, *pNym, this->m_pTransportCallback);
#endif	
	m_pClient->ProcessMessageOut(theMessage);
	
    return m_pClient->CalcReturnVal(lRequestNumber);
}




// -----------------------------------------------------
/// GET ALL THE OFFERS ON A SPECIFIC MARKET
///
/// A specific Nym is requesting the Server to send a list of the offers on a specific
/// Market ID-- the bid/ask, and prices/amounts, basically--(up to lDepth or server Max) 
/// 
int OT_API::getMarketOffers(const OTIdentifier & SERVER_ID, const OTIdentifier & USER_ID, 
							 const OTIdentifier & MARKET_ID, const long & lDepth)
{
	const char * szFuncName = "OT_API::getMarketOffers";
	// -----------------------------------------------------
	OTPseudonym * pNym = this->GetOrLoadPrivateNym(USER_ID, false, szFuncName); // This ASSERTs and logs already.
	if (NULL == pNym) return (-1);
	// By this point, pNym is a good pointer, and is on the wallet.
	//  (No need to cleanup.)
	// -----------------------------------------------------
	OTServerContract *	pServer = this->GetServer(SERVER_ID, szFuncName); // This ASSERTs and logs already.
	if (NULL == pServer) return (-1);
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
    theMessage.SetAcknowledgments(*pNym); // Must be called AFTER theMessage.m_strServerID is already set. (It uses it.)

	theMessage.m_strNymID2			= strMarketID;
	theMessage.m_lDepth				= lDepth;
	
	// (2) Sign the Message 
	theMessage.SignContract(*pNym);		
	
	// (3) Save the Message (with signatures and all, back to its internal member m_strRawFile.)
	theMessage.SaveContract();
	
	// (Send it)
#if defined(OT_ZMQ_MODE)
	m_pClient->SetFocusToServerAndNym(*pServer, *pNym, this->m_pTransportCallback);
#endif	
	m_pClient->ProcessMessageOut(theMessage);
    
    return m_pClient->CalcReturnVal(lRequestNumber);
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
int OT_API::getMarketRecentTrades(const OTIdentifier & SERVER_ID,
                                  const OTIdentifier & USER_ID, 
                                  const OTIdentifier & MARKET_ID)
{
	const char * szFuncName = "OT_API::getMarketRecentTrades";
	// -----------------------------------------------------
	OTPseudonym * pNym = this->GetOrLoadPrivateNym(USER_ID, false, szFuncName); // This ASSERTs and logs already.
	if (NULL == pNym) return (-1);
	// By this point, pNym is a good pointer, and is on the wallet.
	//  (No need to cleanup.)
	// -----------------------------------------------------
	OTServerContract *	pServer = this->GetServer(SERVER_ID, szFuncName); // This ASSERTs and logs already.
	if (NULL == pServer) return (-1);
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
    theMessage.SetAcknowledgments(*pNym); // Must be called AFTER theMessage.m_strServerID is already set. (It uses it.)

	theMessage.m_strNymID2			= strMarketID;
	
	// (2) Sign the Message 
	theMessage.SignContract(*pNym);		
	
	// (3) Save the Message (with signatures and all, back to its internal member m_strRawFile.)
	theMessage.SaveContract();
	
	// (Send it)
#if defined(OT_ZMQ_MODE)
	m_pClient->SetFocusToServerAndNym(*pServer, *pNym, this->m_pTransportCallback);
#endif	
	m_pClient->ProcessMessageOut(theMessage);
    
    return m_pClient->CalcReturnVal(lRequestNumber);
}



///-------------------------------------------------------
/// GET ALL THE ACTIVE (in Cron) MARKET OFFERS FOR A SPECIFIC NYM. 
/// (ON A SPECIFIC SERVER, OBVIOUSLY.) Remember to use Flush/Call/Wait/Pop
/// to check the server reply for success or fail.
/// Hmm for size reasons, this really will have to return a list of transaction #s,
/// and then I request them one-by-one after that...
///
int OT_API::getNym_MarketOffers(const OTIdentifier & SERVER_ID, const OTIdentifier & USER_ID)
{
	const char * szFuncName = "OT_API::getNym_MarketOffers";
	// -----------------------------------------------------
	OTPseudonym * pNym = this->GetOrLoadPrivateNym(USER_ID, false, szFuncName); // This ASSERTs and logs already.
	if (NULL == pNym) return (-1);
	// By this point, pNym is a good pointer, and is on the wallet.
	//  (No need to cleanup.)
	// -----------------------------------------------------
	OTServerContract *	pServer = this->GetServer(SERVER_ID, szFuncName); // This ASSERTs and logs already.
	if (NULL == pServer) return (-1);
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
    theMessage.SetAcknowledgments(*pNym); // Must be called AFTER theMessage.m_strServerID is already set. (It uses it.)
	
	// (2) Sign the Message 
	theMessage.SignContract(*pNym);		
	
	// (3) Save the Message (with signatures and all, back to its internal member m_strRawFile.)
	theMessage.SaveContract();
	
	// (Send it)
#if defined(OT_ZMQ_MODE)
	m_pClient->SetFocusToServerAndNym(*pServer, *pNym, this->m_pTransportCallback);
#endif	
	m_pClient->ProcessMessageOut(theMessage);
    
    return m_pClient->CalcReturnVal(lRequestNumber);
}


// ===============================================================




int OT_API::notarizeTransfer(OTIdentifier	& SERVER_ID,
							  OTIdentifier	& USER_ID,
							  OTIdentifier	& ACCT_FROM,
							  OTIdentifier	& ACCT_TO,
							  const long	& AMOUNT,
							  OTString		& NOTE)
{
	const char * szFuncName = "OT_API::notarizeTransfer";
	// -----------------------------------------------------
	OTPseudonym * pNym = this->GetOrLoadPrivateNym(USER_ID, false, szFuncName);
	if (NULL == pNym) return (-1);	
	// By this point, pNym is a good pointer, and is on the wallet.
	//  (No need to cleanup.)
	// -----------------------------------------------------
	OTServerContract *	pServer = this->GetServer(SERVER_ID, szFuncName); // This ASSERTs and logs already.
	if (NULL == pServer) return (-1);
	// By this point, pServer is a good pointer.  (No need to cleanup.)
	// -----------------------------------------------------
	OTAccount * pAccount = this->GetOrLoadAccount(*pNym, ACCT_FROM, SERVER_ID, szFuncName);
	if (NULL == pAccount) return (-1);
	// By this point, pAccount is a good pointer.  (No need to cleanup.)
	// -----------------------------------------------------
	OTMessage theMessage;
	
	long lRequestNumber = 0;
	const long lAmount = AMOUNT;
	
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
		pItem->SetAmount(lAmount);
		
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
			OTItem * pBalanceItem = pInbox->GenerateBalanceStatement(lAmount*(-1), *pTransaction, *pNym, *pAccount, *pOutbox);				
			
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
            theMessage.SetAcknowledgments(*pNym); // Must be called AFTER theMessage.m_strServerID is already set. (It uses it.)

			theMessage.m_strAcctID			= strFromAcct;
			theMessage.m_ascPayload			= ascLedger;
			
            OTIdentifier NYMBOX_HASH;
            const std::string str_server(strServerID.Get());
            const bool bNymboxHash = pNym->GetNymboxHash(str_server, NYMBOX_HASH);
            NYMBOX_HASH.GetString(theMessage.m_strNymboxHash);
            
            if (!bNymboxHash)
                OTLog::vError("Failed getting NymboxHash from Nym for server: %s\n",
                              str_server.c_str());

			// (2) Sign the Message 
			theMessage.SignContract(*pNym);		
			
			// (3) Save the Message (with signatures and all, back to its internal member m_strRawFile.)
			theMessage.SaveContract();

			// (Send it)
	#if defined(OT_ZMQ_MODE)
			m_pClient->SetFocusToServerAndNym(*pServer, *pNym, this->m_pTransportCallback);
	#endif	
			m_pClient->ProcessMessageOut(theMessage);
            
            return m_pClient->CalcReturnVal(lRequestNumber);
		}
	}
	else 
		OTLog::Output(0, "No transaction numbers were available. Suggest requesting the server for one.\n");
		
		// IF FAILED, ADD TRANSACTION NUMBER BACK TO LIST OF AVAILABLE NUMBERS.
//		pNym->AddTransactionNum(*pNym, strServerID, lStoredTransactionNumber, true); // bSave=true	
		// Duh! No need to re-add a transaction num when the error is that there weren't any transaction numbers...
    
    return -1;
}





int OT_API::getNymbox(OTIdentifier & SERVER_ID,
					   OTIdentifier & USER_ID)
{
	const char * szFuncName = "OT_API::getNymbox";
	// -----------------------------------------------------
	OTPseudonym * pNym = this->GetOrLoadPrivateNym(USER_ID, false, szFuncName);
	if (NULL == pNym) return (-1);	
	// By this point, pNym is a good pointer, and is on the wallet.
	//  (No need to cleanup.)
	// -----------------------------------------------------
	OTServerContract *	pServer = this->GetServer(SERVER_ID, szFuncName); // This ASSERTs and logs already.
	if (NULL == pServer) return (-1);
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
    theMessage.SetAcknowledgments(*pNym); // Must be called AFTER theMessage.m_strServerID is already set. (It uses it.)
	
	// (2) Sign the Message 
	theMessage.SignContract(*pNym);		
	
	// (3) Save the Message (with signatures and all, back to its internal member m_strRawFile.)
	theMessage.SaveContract();
	
	// (Send it)
#if defined(OT_ZMQ_MODE)
	m_pClient->SetFocusToServerAndNym(*pServer, *pNym, this->m_pTransportCallback);
#endif	
	m_pClient->ProcessMessageOut(theMessage);
    
    return m_pClient->CalcReturnVal(lRequestNumber);
}



int OT_API::getInbox(OTIdentifier & SERVER_ID,
					  OTIdentifier & USER_ID,
					  OTIdentifier & ACCT_ID)
{
	const char * szFuncName = "OT_API::getInbox";
	// -----------------------------------------------------
	OTPseudonym * pNym = this->GetOrLoadPrivateNym(USER_ID, false, szFuncName);
	if (NULL == pNym) return (-1);	
	// By this point, pNym is a good pointer, and is on the wallet.
	//  (No need to cleanup.)
	// -----------------------------------------------------
	OTServerContract *	pServer = this->GetServer(SERVER_ID, szFuncName); // This ASSERTs and logs already.
	if (NULL == pServer) return (-1);
	// By this point, pServer is a good pointer.  (No need to cleanup.)
	// -----------------------------------------------------
	OTAccount * pAccount = this->GetOrLoadAccount(*pNym, ACCT_ID, SERVER_ID, szFuncName);
	if (NULL == pAccount) return (-1);
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
    theMessage.SetAcknowledgments(*pNym); // Must be called AFTER theMessage.m_strServerID is already set. (It uses it.)

	theMessage.m_strAcctID			= strAcctID;
	
	// (2) Sign the Message 
	theMessage.SignContract(*pNym);		
	
	// (3) Save the Message (with signatures and all, back to its internal member m_strRawFile.)
	theMessage.SaveContract();
	
	// (Send it)
#if defined(OT_ZMQ_MODE)
	m_pClient->SetFocusToServerAndNym(*pServer, *pNym, this->m_pTransportCallback);
#endif	
	m_pClient->ProcessMessageOut(theMessage);
	
    return m_pClient->CalcReturnVal(lRequestNumber);
}




int OT_API::getOutbox(OTIdentifier & SERVER_ID,
					  OTIdentifier & USER_ID,
					  OTIdentifier & ACCT_ID)
{
	const char * szFuncName = "OT_API::getOutbox";
	// -----------------------------------------------------
	OTPseudonym * pNym = this->GetOrLoadPrivateNym(USER_ID, false, szFuncName);
	if (NULL == pNym) return (-1);	
	// By this point, pNym is a good pointer, and is on the wallet.
	//  (No need to cleanup.)
	// -----------------------------------------------------
	OTServerContract *	pServer = this->GetServer(SERVER_ID, szFuncName); // This ASSERTs and logs already.
	if (NULL == pServer) return (-1);
	// By this point, pServer is a good pointer.  (No need to cleanup.)
	// -----------------------------------------------------
	OTAccount * pAccount = this->GetOrLoadAccount(*pNym, ACCT_ID, SERVER_ID, szFuncName);
	if (NULL == pAccount) return (-1);
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
    theMessage.SetAcknowledgments(*pNym); // Must be called AFTER theMessage.m_strServerID is already set. (It uses it.)

	theMessage.m_strAcctID			= strAcctID;
	
	// (2) Sign the Message 
	theMessage.SignContract(*pNym);		
	
	// (3) Save the Message (with signatures and all, back to its internal member m_strRawFile.)
	theMessage.SaveContract();
	
	// (Send it)
#if defined(OT_ZMQ_MODE)
	m_pClient->SetFocusToServerAndNym(*pServer, *pNym, this->m_pTransportCallback);
#endif	
	m_pClient->ProcessMessageOut(theMessage);
    
    return m_pClient->CalcReturnVal(lRequestNumber);
}




// Returns:
// -1 if error.
//  0 if Nymbox is empty.
//  1 or more: Count of items in Nymbox before processing.
//  UPDATE: This now returns the request number of the message sent, if success.
//
int OT_API::processNymbox(OTIdentifier	& SERVER_ID,
						  OTIdentifier	& USER_ID)
{
	const char * szFuncName = "OT_API::processNymbox";
	// -----------------------------------------------------
	OTPseudonym * pNym = this->GetOrLoadPrivateNym(USER_ID, false, szFuncName);
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
	int			nRequestNum 	= (-1);
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
                {
					OTLog::vOutput(1, "OT_API::processNymbox: Nymbox (%s) is empty (so, skipping processNymbox.)\n",
								   strNymID.Get());
                    nRequestNum   = 0;
                    nReceiptCount = 0; //redundant.
                }
				else
				{
					OTLog::vOutput(0, "OT_API::processNymbox: Failed trying to accept the entire Nymbox. (And no, it's not empty.)\n");
					nReceiptCount = (-1);
				}
			}
			else	// Success!
			{
                OTIdentifier NYMBOX_HASH;
                const OTString strServerID(SERVER_ID);
                const std::string str_server(strServerID.Get());
                const bool bNymboxHash = theNym.GetNymboxHash(str_server, NYMBOX_HASH);
                NYMBOX_HASH.GetString(theMessage.m_strNymboxHash);
                
                if (!bNymboxHash)
                    OTLog::vError("Failed getting NymboxHash from Nym for server: %s\n",
                                  str_server.c_str());
                
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
        // Instead of the receipt count, in the case of success sending, we return the
        // actual request number for the message that was sent.
        // (Otherwise 0 means Nymbox was empty, and -1 means there was an error.)
        //
        nRequestNum = atoi(theMessage.m_strRequestNum.Get());
        
        
#if defined(OT_ZMQ_MODE)
		m_pClient->SetFocusToServerAndNym(*pServer, *pNym, this->m_pTransportCallback);
#endif	
		m_pClient->ProcessMessageOut(theMessage);
        
        return nRequestNum;
	}
	// if successful, ..., else if not successful--and wasn't empty--then error.
	else if (!bIsEmpty)  
		OTLog::Error("Error performing processNymbox command in OT_API::processNymbox\n");
	
	return nReceiptCount;
}




int OT_API::processInbox(OTIdentifier	& SERVER_ID,
						  OTIdentifier	& USER_ID,
						  OTIdentifier	& ACCT_ID,
						  OTString		& ACCT_LEDGER)
{
	const char * szFuncName = "OT_API::processInbox";
	// -----------------------------------------------------
	OTPseudonym * pNym = this->GetOrLoadPrivateNym(USER_ID, false, szFuncName);
	if (NULL == pNym) return (-1);	
	// By this point, pNym is a good pointer, and is on the wallet.
	//  (No need to cleanup.)
	// -----------------------------------------------------
	OTServerContract *	pServer = this->GetServer(SERVER_ID, szFuncName); // This ASSERTs and logs already.
	if (NULL == pServer) return (-1);
	// By this point, pServer is a good pointer.  (No need to cleanup.)
	// -----------------------------------------------------
	OTAccount * pAccount = this->GetOrLoadAccount(*pNym, ACCT_ID, SERVER_ID, szFuncName);
	if (NULL == pAccount) return (-1);
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
    theMessage.SetAcknowledgments(*pNym); // Must be called AFTER theMessage.m_strServerID is already set. (It uses it.)

	theMessage.m_strAcctID			= strAcctID;
	
	// Presumably ACCT_LEDGER was already set up before this function was called...
	// See test client for example of it being done.
	theMessage.m_ascPayload.SetString(ACCT_LEDGER);
	
    OTIdentifier NYMBOX_HASH;
    const std::string str_server(strServerID.Get());
    const bool bNymboxHash = pNym->GetNymboxHash(str_server, NYMBOX_HASH);
    NYMBOX_HASH.GetString(theMessage.m_strNymboxHash);
    
    if (!bNymboxHash)
        OTLog::vError("Failed getting NymboxHash from Nym for server: %s\n",
                      str_server.c_str());

	// (2) Sign the Message 
	theMessage.SignContract(*pNym);		
	
	// (3) Save the Message (with signatures and all, back to its internal member m_strRawFile.)
	theMessage.SaveContract();
	
	// (Send it)
#if defined(OT_ZMQ_MODE)
	m_pClient->SetFocusToServerAndNym(*pServer, *pNym, this->m_pTransportCallback);
#endif	
	m_pClient->ProcessMessageOut(theMessage);
    
    return m_pClient->CalcReturnVal(lRequestNumber);
}



int OT_API::issueAssetType(OTIdentifier	&	SERVER_ID,
                           OTIdentifier &	USER_ID,
                           OTString	    &	THE_CONTRACT)
{
	const char * szFuncName = "OT_API::issueAssetType";
	// -----------------------------------------------------
	OTWallet * pWallet = this->GetWallet(szFuncName);
	if (NULL == pWallet) return (-1);
	// -----------------------------------------------------
	OTPseudonym * pNym = this->GetOrLoadPrivateNym(USER_ID, false, szFuncName);
	if (NULL == pNym) return (-1);	
	// By this point, pNym is a good pointer, and is on the wallet.
	//  (No need to cleanup.)
	// -----------------------------------------------------
	OTServerContract *	pServer = this->GetServer(SERVER_ID, szFuncName); // This ASSERTs and logs already.
	if (NULL == pServer) return (-1);
	// By this point, pServer is a good pointer.  (No need to cleanup.)
	// -----------------------------------------------------
//	OTLog::vError("OT_API::issueAssetType: About to trim this contract:  **BEGIN:%s***END\n\n",
//				 THE_CONTRACT.Get());
	
	std::string str_Trim(THE_CONTRACT.Get());
	std::string str_Trim2 = OTString::trim(str_Trim);
	OTString strTrimContract(str_Trim2.c_str());
	// -----------------------------------------------------
	OTAssetContract theAssetContract;
	
	if (!theAssetContract.LoadContractFromString(strTrimContract))
	{
        OTLog::vOutput(0, "%s: Failed trying to load asset contract from string:\n\n%s\n\n",
                       szFuncName, strTrimContract.Get());
    }
    else
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
        theMessage.SetAcknowledgments(*pNym); // Must be called AFTER theMessage.m_strServerID is already set. (It uses it.)

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
		
		OTString strFoldername(OTFolders::Contract().Get());
		
		OTAssetContract * pContract = new OTAssetContract(theMessage.m_strAssetID, strFoldername,
														  strFilename, theMessage.m_strAssetID);
		OT_ASSERT(NULL != pContract);
		
		// Check the server signature on the contract here. (Perhaps the message is good enough?
		// After all, the message IS signed by the server and contains the Account.
//		if (pContract->LoadContract() && pContract->VerifyContract())
		if (!pContract->LoadContractFromString(strTrimContract))
        {
            OTLog::vOutput(0, "%s: Failed(2) trying to load asset contract from string:\n\n%s\n\n",
                           szFuncName, strTrimContract.Get());
        }
		else if (!pContract->VerifyContract())
        {
            OTLog::vOutput(0, "%s: Failed verifying asset contract:\n\n%s\n\n",
                           szFuncName, strTrimContract.Get());
        }
        else
		{
			// Next make sure the wallet has this contract on its list...			
			pWallet->AddAssetContract(*pContract); // this saves both the contract and the wallet.
			pContract = NULL; // Success. The wallet "owns" it now, no need to clean it up.
		}
        // ------------------------------------------------
		// cleanup
		if (pContract)
		{
			delete pContract;
			pContract = NULL;
		}
		// ----------------------------
		
		// (Send it)
#if defined(OT_ZMQ_MODE)
		m_pClient->SetFocusToServerAndNym(*pServer, *pNym, this->m_pTransportCallback);
#endif	
		m_pClient->ProcessMessageOut(theMessage);
        
        return m_pClient->CalcReturnVal(lRequestNumber);
	}
    
    return -1;
}



int OT_API::getContract(OTIdentifier & SERVER_ID,
						 OTIdentifier & USER_ID,
						 OTIdentifier & ASSET_ID)
{
	const char * szFuncName = "OT_API::getContract";
	// -----------------------------------------------------
	OTPseudonym * pNym = this->GetOrLoadPrivateNym(USER_ID, false, szFuncName);
	if (NULL == pNym) return (-1);	
	// By this point, pNym is a good pointer, and is on the wallet.
	//  (No need to cleanup.)
	// -----------------------------------------------------
	OTServerContract *	pServer = this->GetServer(SERVER_ID, szFuncName); // This ASSERTs and logs already.
	if (NULL == pServer) return (-1);
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
    theMessage.SetAcknowledgments(*pNym); // Must be called AFTER theMessage.m_strServerID is already set. (It uses it.)

	theMessage.m_strAssetID			= strAssetTypeID;
	
	// (2) Sign the Message 
	theMessage.SignContract(*pNym);		
	
	// (3) Save the Message (with signatures and all, back to its internal member m_strRawFile.)
	theMessage.SaveContract();
	
	// (Send it)
#if defined(OT_ZMQ_MODE)
	m_pClient->SetFocusToServerAndNym(*pServer, *pNym, this->m_pTransportCallback);
#endif	
	m_pClient->ProcessMessageOut(theMessage);
    
    return m_pClient->CalcReturnVal(lRequestNumber);
}






int OT_API::getMint(OTIdentifier & SERVER_ID,
					 OTIdentifier & USER_ID,
					 OTIdentifier & ASSET_ID)
{
	const char * szFuncName = "OT_API::getMint";
	// -----------------------------------------------------
	OTPseudonym * pNym = this->GetOrLoadPrivateNym(USER_ID, false, szFuncName);
	if (NULL == pNym) return (-1);	
	// By this point, pNym is a good pointer, and is on the wallet.
	//  (No need to cleanup.)
	// -----------------------------------------------------
	OTServerContract *	pServer = this->GetServer(SERVER_ID, szFuncName); // This ASSERTs and logs already.
	if (NULL == pServer) return (-1);
	// By this point, pServer is a good pointer.  (No need to cleanup.)
	// -----------------------------------------------------
	OTAssetContract *	pAssetContract = this->GetAssetType(ASSET_ID, szFuncName); // This ASSERTs and logs already.
	if (NULL == pAssetContract) return (-1);
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
    theMessage.SetAcknowledgments(*pNym); // Must be called AFTER theMessage.m_strServerID is already set. (It uses it.)

	theMessage.m_strAssetID			= strAssetTypeID;
	
	// (2) Sign the Message 
	theMessage.SignContract(*pNym);		
	
	// (3) Save the Message (with signatures and all, back to its internal member m_strRawFile.)
	theMessage.SaveContract();
	
	// (Send it)
#if defined(OT_ZMQ_MODE)
	m_pClient->SetFocusToServerAndNym(*pServer, *pNym, this->m_pTransportCallback);
#endif	
	m_pClient->ProcessMessageOut(theMessage);
    
    return m_pClient->CalcReturnVal(lRequestNumber);
}



// Sends a list of asset IDs to the server, which replies with a list of the actual receipts
// with the issuer's signature on them, from when the currency was issued.
//
// So you can tell for sure whether or not they are actually issued on that server.
//
// Map input: key is asset type ID, and value is blank (server reply puts issuer's receipts
// in that spot.)
//
int OT_API::queryAssetTypes(OTIdentifier & SERVER_ID,
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
	OTPseudonym * pNym = this->GetOrLoadPrivateNym(USER_ID, false, szFuncName);
	if (NULL == pNym) return (-1);	
	// By this point, pNym is a good pointer, and is on the wallet.
	//  (No need to cleanup.)
	// -----------------------------------------------------
	OTServerContract *	pServer = this->GetServer(SERVER_ID, szFuncName); // This ASSERTs and logs already.
	if (NULL == pServer) return (-1);
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
    theMessage.SetAcknowledgments(*pNym); // Must be called AFTER theMessage.m_strServerID is already set. (It uses it.)

	theMessage.m_ascPayload			= ENCODED_MAP;
	
	// (2) Sign the Message 
	theMessage.SignContract(*pNym);		
	
	// (3) Save the Message (with signatures and all, back to its internal member m_strRawFile.)
	theMessage.SaveContract();
	
	// (Send it)
#if defined(OT_ZMQ_MODE)
	m_pClient->SetFocusToServerAndNym(*pServer, *pNym, this->m_pTransportCallback);
#endif	
	m_pClient->ProcessMessageOut(theMessage);
    
    return m_pClient->CalcReturnVal(lRequestNumber);
}



int OT_API::createAssetAccount(OTIdentifier & SERVER_ID,
								OTIdentifier & USER_ID,
								OTIdentifier & ASSET_ID)
{	
	const char * szFuncName = "OT_API::createAssetAccount";
	// -----------------------------------------------------
	OTPseudonym * pNym = this->GetOrLoadPrivateNym(USER_ID, false, szFuncName);
	if (NULL == pNym) return (-1);	
	// By this point, pNym is a good pointer, and is on the wallet.
	//  (No need to cleanup.)
	// -----------------------------------------------------
	OTServerContract *	pServer = this->GetServer(SERVER_ID, szFuncName); // This ASSERTs and logs already.
	if (NULL == pServer) return (-1);
	// By this point, pServer is a good pointer.  (No need to cleanup.)
	// -----------------------------------------------------
	OTAssetContract *	pAssetContract = this->GetAssetType(ASSET_ID, szFuncName); // This ASSERTs and logs already.
	if (NULL == pAssetContract) return (-1);
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
    theMessage.SetAcknowledgments(*pNym); // Must be called AFTER theMessage.m_strServerID is already set. (It uses it.)

	theMessage.m_strAssetID			= strAssetTypeID;
	
	// (2) Sign the Message 
	theMessage.SignContract(*pNym);		
	
	// (3) Save the Message (with signatures and all, back to its internal member m_strRawFile.)
	theMessage.SaveContract();
	
	// (Send it)
#if defined(OT_ZMQ_MODE)
	m_pClient->SetFocusToServerAndNym(*pServer, *pNym, this->m_pTransportCallback);
#endif	
	m_pClient->ProcessMessageOut(theMessage);
    
    return m_pClient->CalcReturnVal(lRequestNumber);
}



int OT_API::deleteAssetAccount(OTIdentifier & SERVER_ID,
								OTIdentifier & USER_ID,
								OTIdentifier & ACCOUNT_ID)
{	
	const char * szFuncName = "OT_API::deleteAssetAccount";
	// -----------------------------------------------------
	OTPseudonym * pNym = this->GetOrLoadPrivateNym(USER_ID, false, szFuncName);
	if (NULL == pNym) return (-1);	
	// By this point, pNym is a good pointer, and is on the wallet.
	//  (No need to cleanup.)
	// -----------------------------------------------------
	OTServerContract *	pServer = this->GetServer(SERVER_ID, szFuncName); // This ASSERTs and logs already.
	if (NULL == pServer) return (-1);
	// By this point, pServer is a good pointer.  (No need to cleanup.)
	// -----------------------------------------------------
	OTAccount * pAccount = this->GetOrLoadAccount(*pNym, ACCOUNT_ID, SERVER_ID, szFuncName);
	if (NULL == pAccount) return (-1);
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
    theMessage.SetAcknowledgments(*pNym); // Must be called AFTER theMessage.m_strServerID is already set. (It uses it.)

	theMessage.m_strAcctID			= strAcctID;
	
	// (2) Sign the Message 
	theMessage.SignContract(*pNym);		
	
	// (3) Save the Message (with signatures and all, back to its internal member m_strRawFile.)
	theMessage.SaveContract();
	
	// (Send it)
#if defined(OT_ZMQ_MODE)
	m_pClient->SetFocusToServerAndNym(*pServer, *pNym, this->m_pTransportCallback);
#endif	
	m_pClient->ProcessMessageOut(theMessage);
    
    return m_pClient->CalcReturnVal(lRequestNumber);
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




int OT_API::getBoxReceipt(const OTIdentifier & SERVER_ID,
						   const OTIdentifier & USER_ID,
						   const OTIdentifier & ACCOUNT_ID,		// If for Nymbox (vs inbox/outbox) then pass USER_ID in this field also.
						   const int			nBoxType,		// 0/nymbox, 1/inbox, 2/outbox
						   const long		  &	lTransactionNum)
{	
	const char * szFuncName = "OT_API::getBoxReceipt";
	// -----------------------------------------------------
	OTPseudonym * pNym = this->GetOrLoadPrivateNym(USER_ID, false, szFuncName);
	if (NULL == pNym) return (-1);	
	// By this point, pNym is a good pointer, and is on the wallet.
	//  (No need to cleanup.)
	// -----------------------------------------------------
	OTServerContract *	pServer = this->GetServer(SERVER_ID, szFuncName); // This ASSERTs and logs already.
	if (NULL == pServer) return (-1);
	// By this point, pServer is a good pointer.  (No need to cleanup.)
	// -----------------------------------------------------
	OTAccount * pAccount = NULL;
	if (USER_ID != ACCOUNT_ID) // inbox/outbox (if it were nymbox, the USER_ID and ACCOUNT_ID would match)
	{
		pAccount =	this->GetOrLoadAccount(*pNym, ACCOUNT_ID, SERVER_ID, szFuncName);
		if (NULL == pAccount) return (-1);
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
    theMessage.SetAcknowledgments(*pNym); // Must be called AFTER theMessage.m_strServerID is already set. (It uses it.)

	theMessage.m_strAcctID			= strAcctID;
	theMessage.m_lDepth				= static_cast<long>(nBoxType);
	theMessage.m_lTransactionNum	= lTransactionNum;
	
	// (2) Sign the Message 
	theMessage.SignContract(*pNym);		
	
	// (3) Save the Message (with signatures and all, back to its internal member m_strRawFile.)
	theMessage.SaveContract();
	
	// (Send it)
#if defined(OT_ZMQ_MODE)
	m_pClient->SetFocusToServerAndNym(*pServer, *pNym, this->m_pTransportCallback);
#endif	
	m_pClient->ProcessMessageOut(theMessage);
    
    return m_pClient->CalcReturnVal(lRequestNumber);
}





int OT_API::getAccount(OTIdentifier	& SERVER_ID,
						OTIdentifier	& USER_ID,
						OTIdentifier	& ACCT_ID)
{	
	const char * szFuncName = "OT_API::getAccount";
	// -----------------------------------------------------
	OTPseudonym * pNym = this->GetOrLoadPrivateNym(USER_ID, false, szFuncName); // This ASSERTs and logs already.
	if (NULL == pNym) return (-1);	
	// By this point, pNym is a good pointer, and is on the wallet.
	//  (No need to cleanup.)
	// -----------------------------------------------------
	OTServerContract *	pServer = this->GetServer(SERVER_ID, szFuncName); // This ASSERTs and logs already.
	if (NULL == pServer) return (-1);
	// By this point, pServer is a good pointer.  (No need to cleanup.)
	// -----------------------------------------------------
	OTAccount * pAccount = this->GetOrLoadAccount(*pNym, ACCT_ID, SERVER_ID, szFuncName);
	if (NULL == pAccount) return (-1);
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
    theMessage.SetAcknowledgments(*pNym); // Must be called AFTER theMessage.m_strServerID is already set. (It uses it.)

	theMessage.m_strAcctID			= strAcctID;
	
	// (2) Sign the Message 
	theMessage.SignContract(*pNym);		
	
	// (3) Save the Message (with signatures and all, back to its internal member m_strRawFile.)
	theMessage.SaveContract();
	
	// (Send it)
#if defined(OT_ZMQ_MODE)
	m_pClient->SetFocusToServerAndNym(*pServer, *pNym, this->m_pTransportCallback);
#endif	
	m_pClient->ProcessMessageOut(theMessage);
    
    return m_pClient->CalcReturnVal(lRequestNumber);
}




int OT_API::getRequest(OTIdentifier	& SERVER_ID,
                       OTIdentifier	& USER_ID)
{	
	const char * szFuncName = "OT_API::getRequest";
	// -----------------------------------------------------
	OTPseudonym * pNym = this->GetOrLoadPrivateNym(USER_ID, false, szFuncName); // This ASSERTs and logs already.
	if (NULL == pNym) return (-1);	
	// By this point, pNym is a good pointer, and is on the wallet.
	//  (No need to cleanup.)
	// -----------------------------------------------------
	OTServerContract *	pServer = this->GetServer(SERVER_ID, szFuncName); // This ASSERTs and logs already.
	if (NULL == pServer) return (-1);
	// By this point, pServer is a good pointer.  (No need to cleanup.)
	// -----------------------------------------------------
	OTMessage theMessage;
	
    int nReturnValue = m_pClient->ProcessUserCommand(OTClient::getRequest, theMessage, 
                                                     *pNym, *pServer,
                                                     NULL); // NULL pAccount on this command.
	if (0 < nReturnValue) 
	{				
#if defined(OT_ZMQ_MODE)
		m_pClient->SetFocusToServerAndNym(*pServer, *pNym, this->m_pTransportCallback);
#endif	
		m_pClient->ProcessMessageOut(theMessage);
        
        return nReturnValue;
	}
	else
		OTLog::Error("Error processing getRequest command in OT_API::getRequest\n");
    
    return (-1);
}






int OT_API::usageCredits(const OTIdentifier &	SERVER_ID,
						  const OTIdentifier &	USER_ID,
						  const OTIdentifier &	USER_ID_CHECK,
						  const long			lAdjustment/*=0*/)
{	
	const char * szFuncName = "OT_API::usageCredits";
	// -----------------------------------------------------
	OTPseudonym * pNym = this->GetOrLoadPrivateNym(USER_ID, false, szFuncName); // This ASSERTs and logs already.
	if (NULL == pNym) return (-1);	
	// By this point, pNym is a good pointer, and is on the wallet.
	//  (No need to cleanup.)
	// -----------------------------------------------------
	OTServerContract *	pServer = this->GetServer(SERVER_ID, szFuncName); // This ASSERTs and logs already.
	if (NULL == pServer) return (-1);
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
    theMessage.SetAcknowledgments(*pNym); // Must be called AFTER theMessage.m_strServerID is already set. (It uses it.)
	
	theMessage.m_lDepth				= lAdjustment; // Default is "no adjustment" (@usageCredits returns current balance regardless.)
	
	// (2) Sign the Message 
	theMessage.SignContract(*pNym);		
	
	// (3) Save the Message (with signatures and all, back to its internal member m_strRawFile.)
	theMessage.SaveContract();
	
	// (Send it)
#if defined(OT_ZMQ_MODE)
	m_pClient->SetFocusToServerAndNym(*pServer, *pNym, this->m_pTransportCallback);
#endif	
	m_pClient->ProcessMessageOut(theMessage);
    
    return m_pClient->CalcReturnVal(lRequestNumber);
}



int OT_API::checkUser(OTIdentifier & SERVER_ID,
					   OTIdentifier & USER_ID,
					   OTIdentifier & USER_ID_CHECK)
{	
	const char * szFuncName = "OT_API::checkUser";
	// -----------------------------------------------------
	OTPseudonym * pNym = this->GetOrLoadPrivateNym(USER_ID, false, szFuncName); // This ASSERTs and logs already.
	if (NULL == pNym) return (-1);	
	// By this point, pNym is a good pointer, and is on the wallet.
	//  (No need to cleanup.)
	// -----------------------------------------------------
	OTServerContract *	pServer = this->GetServer(SERVER_ID, szFuncName); // This ASSERTs and logs already.
	if (NULL == pServer) return (-1);
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
    theMessage.SetAcknowledgments(*pNym); // Must be called AFTER theMessage.m_strServerID is already set. (It uses it.)
	
	// (2) Sign the Message 
	theMessage.SignContract(*pNym);		
	
	// (3) Save the Message (with signatures and all, back to its internal member m_strRawFile.)
	theMessage.SaveContract();
	
	// (Send it)
#if defined(OT_ZMQ_MODE)
	m_pClient->SetFocusToServerAndNym(*pServer, *pNym, this->m_pTransportCallback);
#endif	
	m_pClient->ProcessMessageOut(theMessage);
    
    return m_pClient->CalcReturnVal(lRequestNumber);
}



int OT_API::sendUserMessage(OTIdentifier	& SERVER_ID,
							 OTIdentifier	& USER_ID,
							 OTIdentifier	& USER_ID_RECIPIENT,
							 OTString       & RECIPIENT_PUBKEY, // unescaped and bookended.
							 OTString		& THE_MESSAGE)
{	
	const char * szFuncName = "OT_API::sendUserMessage";
	// -----------------------------------------------------
	OTPseudonym * pNym = this->GetOrLoadPrivateNym(USER_ID, false, szFuncName); // This ASSERTs and logs already.
	if (NULL == pNym) return (-1);	
	// By this point, pNym is a good pointer, and is on the wallet.
	//  (No need to cleanup.)
	// -----------------------------------------------------
	OTServerContract *	pServer = this->GetServer(SERVER_ID, szFuncName); // This ASSERTs and logs already.
	if (NULL == pServer) return (-1);
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
    theMessage.SetAcknowledgments(*pNym); // Must be called AFTER theMessage.m_strServerID is already set. (It uses it.)
	
	OTEnvelope theEnvelope;
	OTAsymmetricKey * pPubkey = OTAsymmetricKey::KeyFactory();
    OT_ASSERT(NULL != pPubkey);
	OTCleanup<OTAsymmetricKey> theKeyAngel(pPubkey);
    
    int nReturnValue = -1;
    
	if (!pPubkey->SetPublicKey(RECIPIENT_PUBKEY))
	{
		OTLog::Output(0, "OT_API::sendUserMessage: Failed setting public key.\n");
	}
	else if (THE_MESSAGE.Exists() && 
			 theEnvelope.Seal(*pPubkey, THE_MESSAGE) &&
			 theEnvelope.GetAsciiArmoredData(theMessage.m_ascPayload))
	{
		// (2) Sign the Message 
		theMessage.SignContract(*pNym);		
		
		// (3) Save the Message (with signatures and all, back to its internal member m_strRawFile.)
		theMessage.SaveContract();
		
		// (Send it)
#if defined(OT_ZMQ_MODE)
		// -----------------------------------------------------------------
		
		m_pClient->SetFocusToServerAndNym(*pServer, *pNym, this->m_pTransportCallback);
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
        
        nReturnValue = m_pClient->CalcReturnVal(lRequestNumber);
	}
	else
		OTLog::Output(0, "OT_API::sendUserMessage: Failed sealing envelope.\n");
    
    return nReturnValue;
}





int OT_API::sendUserInstrument(OTIdentifier	& SERVER_ID,
                               OTIdentifier	& USER_ID,
                               OTIdentifier	& USER_ID_RECIPIENT,
                               OTString     & RECIPIENT_PUBKEY,
                               OTPayment	& THE_INSTRUMENT,
                               OTPayment	* pINSTRUMENT_FOR_SENDER/*=NULL*/) // This is only used for cash purses. It's a copy of the purse in THE_INSTRUMENT, except all the tokens are already encrypted to the sender's public key, instead of the recipient's public key (as THE_INSTRUMENT is.) This is what we put in the sender's outpayments, so he can retrieve those tokens if he needs to.
{	
	// -----------------------------------------------------
	OTPseudonym * pNym = this->GetOrLoadPrivateNym(USER_ID, false, __FUNCTION__); // This ASSERTs and logs already.
	if (NULL == pNym) return (-1);	
	// By this point, pNym is a good pointer, and is on the wallet.
	//  (No need to cleanup.)
	// -----------------------------------------------------
	OTServerContract *	pServer = this->GetServer(SERVER_ID, __FUNCTION__); // This ASSERTs and logs already.
	if (NULL == pServer) return (-1);
	// By this point, pServer is a good pointer.  (No need to cleanup.)
	// -----------------------------------------------------
	OTMessage theMessage;
	long lRequestNumber = 0;
	
    int nReturnValue = -1;
    
	OTString strServerID(SERVER_ID), strNymID(USER_ID), strNymID2(USER_ID_RECIPIENT);
	
	// (0) Set up the REQUEST NUMBER and then INCREMENT IT
	pNym->GetCurrentRequestNum(strServerID, lRequestNumber);
	theMessage.m_strRequestNum.Format("%ld", lRequestNumber); // Always have to send this.
	pNym->IncrementRequestNum(*pNym, strServerID); // since I used it for a server request, I have to increment it
	
	// (1) set up member variables 
	theMessage.m_strCommand			= "sendUserInstrument";
	theMessage.m_strNymID			= strNymID;
	theMessage.m_strNymID2			= strNymID2;
	theMessage.m_strServerID		= strServerID;
    theMessage.SetAcknowledgments(*pNym); // Must be called AFTER theMessage.m_strServerID is already set. (It uses it.)
	
	OTEnvelope theEnvelope;
	OTAsymmetricKey * pPubkey = OTAsymmetricKey::KeyFactory();
    OT_ASSERT(NULL != pPubkey);
	OTCleanup<OTAsymmetricKey> theKeyAngel(pPubkey);
    // -----------------------------------	
	OTString strInstrument,
             strInstrumentForSender;
    // -----------------------------------
    const bool bGotPaymentContents = THE_INSTRUMENT.GetPaymentContents(strInstrument);
    const bool bGotSenderPmntCnts  = (NULL == pINSTRUMENT_FOR_SENDER) ? false :
                                     pINSTRUMENT_FOR_SENDER->GetPaymentContents(strInstrumentForSender);
    // -----------------------------------
	if (!pPubkey->SetPublicKey(RECIPIENT_PUBKEY))
	{
		OTLog::vOutput(0, "%s: Failed setting public key from string ===>%s<===\n",
                       __FUNCTION__, RECIPIENT_PUBKEY.Get());
	}
	else if (bGotPaymentContents &&
             theEnvelope.Seal(*pPubkey, strInstrument) &&
			 theEnvelope.GetAsciiArmoredData(theMessage.m_ascPayload))
	{
		// (2) Sign the Message 
		theMessage.SignContract(*pNym);		
		
		// (3) Save the Message (with signatures and all, back to its internal member m_strRawFile.)
		theMessage.SaveContract();
		
		// (Send it)
#if defined(OT_ZMQ_MODE)
		// -----------------------------------------------------------------
		m_pClient->SetFocusToServerAndNym(*pServer, *pNym, this->m_pTransportCallback);
#endif	
		m_pClient->ProcessMessageOut(theMessage);	
		// ----------------------------------------------
		// store a copy in the outpayments.
		// (not encrypted, since the Nymfile will be encrypted anyway.)
		//
        // UPDATE: We are now storing a copy in outpayments when the
        // cheque is WRITTEN. But for other instruments (like cash, or
        // vouchers) we cannot store them in outpayments until they are
        // SENT. ...Meaning we must record at this point regardless.
        // Should we have an exception here for cheques?
        //
        // Solution: Let's just make sure there's not already one there...
        //
        // -------------------------------------------------------
        long lTempTransNum = 0;
        bool bGotTransNum  = THE_INSTRUMENT.GetTransactionNum(lTempTransNum);
        
        int lOutpaymentsIndex = bGotTransNum ? pNym->GetOutpaymentsIndexByTransNum(lTempTransNum) : (-1);
        
        if (lOutpaymentsIndex > (-1)) // found something that matches...
        {
            // Remove it from Outpayments box. We're adding an updated version
            // of this same instrument here anyway. We can erase the old one.
            //
            if (!pNym->RemoveOutpaymentsByIndex(lOutpaymentsIndex)) // <==== REMOVED! (So the one added below isn't a duplicate.)
            {
                OTLog::vError("%s: Error calling RemoveOutpaymentsByIndex for Nym: %s\n",
                              __FUNCTION__, strNymID.Get());
                
            }
            // Save Nym to local storage, since an outpayment was erased.
            // Note: we're saving below anyway. Might as well not save twice.
            //
//          else if (!pNym->SaveSignedNymfile(*pNym))
//                    OTLog::vError("%s: Error saving Nym: %s\n", __FUNCTION__, strNymID.Get());                
        }
        // --------------------------------------------------------
		OTMessage * pMessage = new OTMessage;
		OT_ASSERT(NULL != pMessage);
		
		pMessage->m_strCommand		= "outpaymentsMessage";
		pMessage->m_strNymID		= strNymID;
		pMessage->m_strNymID2		= strNymID2;
		pMessage->m_strServerID		= strServerID;
		pMessage->m_strRequestNum.Format("%ld", lRequestNumber);
		
		pMessage->m_ascPayload.SetString(bGotSenderPmntCnts ? strInstrumentForSender : strInstrument);
		
		pMessage->SignContract(*pNym);
		pMessage->SaveContract();
		
		pNym->AddOutpayments(*pMessage); // Now the Nym is responsible to delete it. It's in his "outpayments".
		OTPseudonym * pSignerNym = pNym;
		pNym->SaveSignedNymfile(*pSignerNym);
        
        nReturnValue = m_pClient->CalcReturnVal(lRequestNumber);
	}
	else
		OTLog::vOutput(0, "%s: Failed sealing envelope.\n", __FUNCTION__);
    
    return nReturnValue;
}



// PROBLEM: How can I put anything in an "out" box (ledger) when I can't generate a
// transaction number on the client side?  Normally I download the outbox and
// it contains transactions that the SERVER put there--not me!

// THEREFORE!!! The paymentOutbox NEEDS to be like OUTMAIL! It's just a message on a Nym. (No transaction numbers.)
// The instrument I sent will be a payload on a message, and that message will be copied into the paymentOutbox...

// The messages definitely go OUT as messages, as do instruments, and those same messages end up
// "in reference to" on transactions stuffed in my nymbox and then those transactions have their
// message copied OUT, and added as a message to my OUTMAIL.
// Therefore Payment Outbox needs to be similar. It will contain the message originally sent -- no more.

// whereas payment inbox comes from Nymbox (just copy it over.)
// Similarly, recordbox comes from either payment inbox or asset account inbox.

// So tomorrow:  REMOVE the payment Outbox since it is BULLSHIT and replace with "outmail" like functionality for that box.
//
// Update: DONE.



int OT_API::createUserAccount(OTIdentifier	& SERVER_ID,
							   OTIdentifier	& USER_ID)
{	
	const char * szFuncName = "OT_API::createUserAccount";
	// -----------------------------------------------------
	OTPseudonym * pNym = this->GetOrLoadPrivateNym(USER_ID, false, szFuncName); // This ASSERTs and logs already.
	if (NULL == pNym) return (-1);	
	// By this point, pNym is a good pointer, and is on the wallet.
	//  (No need to cleanup.)
	// -----------------------------------------------------
	OTServerContract *	pServer = this->GetServer(SERVER_ID, szFuncName); // This ASSERTs and logs already.
	if (NULL == pServer) return (-1);
	// By this point, pServer is a good pointer.  (No need to cleanup.)
	// -----------------------------------------------------
	OTMessage theMessage;
    
	int nReturnValue = m_pClient->ProcessUserCommand(OTClient::createUserAccount, theMessage, 
                                                     *pNym, *pServer,
                                                     NULL); // NULL pAccount on this command.
	if (0 < nReturnValue)
	{				
#if defined(OT_ZMQ_MODE)
		m_pClient->SetFocusToServerAndNym(*pServer, *pNym, this->m_pTransportCallback);
#endif	
		m_pClient->ProcessMessageOut(theMessage);
        
        return nReturnValue;
	}
	else
		OTLog::Error("OT_API::createUserAccount: Error in m_pClient->ProcessUserCommand() \n");
    
    return -1;
}



int OT_API::deleteUserAccount(OTIdentifier	& SERVER_ID,
							   OTIdentifier	& USER_ID)
{	
	const char * szFuncName = "OT_API::deleteUserAccount";
	// -----------------------------------------------------
	OTPseudonym * pNym = this->GetOrLoadPrivateNym(USER_ID, false, szFuncName); // This ASSERTs and logs already.
	if (NULL == pNym) return (-1);	
	// By this point, pNym is a good pointer, and is on the wallet.
	//  (No need to cleanup.)
	// -----------------------------------------------------
	OTServerContract *	pServer = this->GetServer(SERVER_ID, szFuncName); // This ASSERTs and logs already.
	if (NULL == pServer) return (-1);
	// By this point, pServer is a good pointer.  (No need to cleanup.)
	// -----------------------------------------------------
	OTMessage theMessage;
	
    int nReturnValue = m_pClient->ProcessUserCommand(OTClient::deleteUserAccount, theMessage, 
                                                     *pNym, *pServer,
                                                     NULL); // NULL pAccount on this command.
	if (0 < nReturnValue) 
	{				
#if defined(OT_ZMQ_MODE)
		m_pClient->SetFocusToServerAndNym(*pServer, *pNym, this->m_pTransportCallback);
#endif	
		m_pClient->ProcessMessageOut(theMessage);
        
        return nReturnValue;
	}
	else
		OTLog::Error("Error processing deleteUserAccount command in OT_API::deleteUserAccount\n");
    
    return -1;
	
}


int OT_API::checkServerID(OTIdentifier	& SERVER_ID,
						   OTIdentifier	& USER_ID)
{	
	const char * szFuncName = "OT_API::checkServerID";
	// -----------------------------------------------------
	OTPseudonym * pNym = this->GetOrLoadPrivateNym(USER_ID, false, szFuncName); // This ASSERTs and logs already.
	if (NULL == pNym) return (-1);	
	// By this point, pNym is a good pointer, and is on the wallet.
	//  (No need to cleanup.)
	// -----------------------------------------------------
	OTServerContract *	pServer = this->GetServer(SERVER_ID, szFuncName); // This ASSERTs and logs already.
	if (NULL == pServer) return (-1);
	// By this point, pServer is a good pointer.  (No need to cleanup.)
	// -----------------------------------------------------
	OTMessage theMessage;
	
    int nReturnValue = m_pClient->ProcessUserCommand(OTClient::checkServerID, theMessage, 
                                                     *pNym, *pServer,
                                                     NULL); // NULL pAccount on this command.
	if (0 < nReturnValue) 
	{				
#if defined(OT_ZMQ_MODE)
		m_pClient->SetFocusToServerAndNym(*pServer, *pNym, this->m_pTransportCallback);
#endif	
		m_pClient->ProcessMessageOut(theMessage);
        
        return nReturnValue;
	}
	else
		OTLog::Error("Error processing checkServerID command in OT_API::checkServerID\n");
    
    return -1;
}


void OT_API::AddServerContract(const OTServerContract & pContract)
{
	this->m_pWallet->AddServerContract(pContract);
}

void OT_API::AddAssetContract(const OTAssetContract & theContract)
{
	this->m_pWallet->AddAssetContract(theContract);
}































