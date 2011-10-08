/************************************************************************************
 *    
 *  server.cpp  (as opposed to OTServer, this is the project's encapsulation.)
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


#ifdef _WIN32
#include "OTLib/stdafx.h"
#endif

#include <cstring>
#include <cstdio>

extern "C" 
{
#ifdef _WIN32
#include <WinSock.h>
#else
#include <netinet/in.h>
#include <wordexp.h>
#endif

#include "SSL-Example/SFSocket.h"
}



#include "SimpleIni.h"



#include "OTLog.h"
#include "OTStorage.h"


// NOTE:  The PATH and the PASSWORD are configurable on the command line!!!
//
//        They are only here for convenience, so I don't have to type them
//        over and over again.  You can blank them out if you want, or set
//        them to whatever is convenient for you on your system.
//

#define KEY_PASSWORD        "test"

#ifdef _WIN32
#define SERVER_PATH_DEFAULT	"C:\\~\\Open-Transactions\\transaction\\data_folder"
#define CA_FILE             "certs\\special\\ca.crt"
#define DH_FILE             "certs\\special\\dh_param_1024.pem"
#define KEY_FILE            "certs\\special\\server.pem"

#else

#define SERVER_PATH_DEFAULT	"./data_folder"
#define CA_FILE             "certs/special/ca.crt"
#define DH_FILE             "certs/special/dh_param_1024.pem"
#define KEY_FILE            "certs/special/server.pem"

#endif

// NOTE: this SSL connection is entirely different from the user's cert/pubkey that he uses for his UserID while 
// talking to the server. I may be using the same key for that, but this code here is not about my wallet talking
// to its mint. Rather, it's about an SSL client app talking to an SSL server, at a lower layer, before my app's
// intelligence takes over.  Just like when you use SSH to connect somewhere on a terminal. There is some immediate
// key negotiation going on. Once connected, you might run software that asks you for a public key, which could be
// AN ENTIRELY DIFFERENT PUBLIC KEY. THAT is where, metaphorically, your Public Key / User ID comes into play.


#include <list>

#include "main.h"

#include "OTMessage.h"
#include "OTServer.h"
#include "OTClientConnection.h"

#include "OTLog.h"





/*
 if (bSuccess = theServer.ProcessUserCommand(theMessage, theReply))
 {
	 OTLog::vOutput(1, "Successfully processed user command: %s\n", theMessage.m_strCommand.Get());
	 ProcessReply(ssl, theReply);
 }
 else
 {
	 OTLog::Output(1, "Unable to process user command in XML, or missing payload, in ProcessMessage.\n");
 } 
 
 */



int main (int argc, char **argv) 
{
	OTLog::vOutput(0, "\n\nWelcome to Open Transactions... Test Server -- version %s\n"
				   "(transport build: OTMessage -> TCP -> SSL)\n"
				   "IF YOU PREFER TO USE XmlRpc with HTTP, then rebuild from main folder like this:\n\n"
				   "cd ..; make clean; make rpc\n\n", 
				   OTLog::Version());
	
	// -----------------------------------------------------------------------
	
	// This object handles all the actual transaction notarization details.
	// (This file you are reading is a wrapper for OTServer, which adds the transport layer.)
	OTServer theServer;

	// -----------------------------------------------------------------------
	
#ifdef _WIN32
	WSADATA wsaData;
	WORD wVersionRequested = MAKEWORD( 2, 2 );
	int nWSA = WSAStartup( wVersionRequested, &wsaData );
	OT_ASSERT_MSG(0 != nWSA, "Error calling WSAStartup.\n");	
#endif

	OTLog::vOutput(0, "\n\nWelcome to Open Transactions, version %s.\n\n", OTLog::Version());
	
	// -----------------------------------------------------------------------
	// The beginnings of an INI file!!
	
#ifndef _WIN32 // if UNIX (NOT windows)
	wordexp_t exp_result;
	wordexp(OT_INI_FILE_DEFAULT, &exp_result, 0);
	
	const OTString strIniFileDefault(exp_result.we_wordv[0]);
	
	wordfree(&exp_result); 
#else
	const OTString strIniFileDefault(OT_INI_FILE_DEFAULT);
#endif
	
	OTString strPath(SERVER_PATH_DEFAULT);
	
	{
		CSimpleIniA ini;
		
		SI_Error rc = ini.LoadFile(strIniFileDefault.Get());
		
		if (rc >=0)
		{
			const char * pVal = ini.GetValue("paths", "server_path", SERVER_PATH_DEFAULT); // todo stop hardcoding.
			
			if (NULL != pVal)
			{
				strPath.Set(pVal);
				OTLog::vOutput(0, "Reading ini file (%s). \n Found Server data_folder path: %s \n", 
							   strIniFileDefault.Get(), strPath.Get());
			}
			else
			{
				strPath.Set(SERVER_PATH_DEFAULT);
				OTLog::vOutput(0, "Reading ini file (%s): \n Failed reading Server data_folder path. Using: %s \n", 
							   strIniFileDefault.Get(), strPath.Get());
			}
		}
		else 
		{
			strPath.Set(SERVER_PATH_DEFAULT);
			OTLog::vOutput(0, "Unable to load ini file (%s) to find data_folder path\n Will assume that server data_folder is at path: %s \n", 
						   strIniFileDefault.Get(), strPath.Get());
		}
	}
	// -----------------------------------------------------------------------
	
	OTString strCAFile, strDHFile, strKeyFile;
	//, strSSLPassword;
	
	if (argc < 1)
	{
		OTLog::vOutput(0, "\n==> USAGE:    %s  [absolute_path_to_data_folder]\n\n"
					   
					   //		OTLog::vOutput(0, "\n==> USAGE:    %s  <SSL-password>  [absolute_path_to_data_folder]\n\n"
#if defined (FELLOW_TRAVELER)					   
					   //					   "(Password defaults to '%s' if left blank.)\n"
					   "(Folder defaults to '%s' if left blank.)\n"
#else
					   "The test password is always 'test'.\n"
					   "OT will try to read the data_folder path from your ini file. If you prefer\n"
					   "to specify it at the command line, and you want to see the exact path, type:\n"
					   "     cd data_folder && pwd && cd ..\n"
#endif
					   "\n\n", argv[0]
#if defined (FELLOW_TRAVELER)					   
					   //					   , KEY_PASSWORD, 
					   , strPath.Get()
#endif					   
					   );
		
#if defined (FELLOW_TRAVELER)
		//		strSSLPassword.Set(KEY_PASSWORD);
		OTLog::SetMainPath(strPath.Get());
#else
		exit(1);
#endif
	}
	else if (argc < 2)
	{		
		//		strSSLPassword.Set(argv[1]);
		OTLog::SetMainPath(strPath.Get());
	}
	else 
	{
		//		strSSLPassword.Set(argv[1]);
		OTLog::SetMainPath(argv[1]); // formerly [2]
	}
	
	OTLog::vOutput(0, "Using as path to data folder:  %s\n", OTLog::Path());

	strCAFile. Format("%s%s%s", OTLog::Path(), OTLog::PathSeparator(), CA_FILE);
	strDHFile. Format("%s%s%s", OTLog::Path(), OTLog::PathSeparator(), DH_FILE);
	strKeyFile.Format("%s%s%s", OTLog::Path(), OTLog::PathSeparator(), KEY_FILE);
	
	
	// -----------------------------------------------------------------------

	// Init loads up server's nym so it can decrypt messages sent in envelopes.
	// It also does various other initialization work.
	//
	// (Envelopes prove that ONLY someone who actually had the server contract,
	// and had loaded it into his wallet, could ever connect to the server or 
	// communicate with it. And if that person is following the contract, there
	// is only one server he can connect to, and one key he can use to talk to it.)
	
	OTLog::Output(0, 
				  "\n\nNow loading the server nym, which will also ask you for a password, to unlock\n"
				  "its private key. (Default password is \"test\".)\n");

	// Initialize SSL -- This MUST occur before any Private Keys are loaded!
    SFSocketGlobalInit(); // Any app that uses OT has to initialize SSL first.

	theServer.Init(); // Keys, etc are loaded here.

	// -----------------------------------------------------------------------

	// We're going to listen on the same port that is listed in our server contract.
	//
	//
	OTString	strHostname;	// The hostname of this server, according to its own contract.
	int			nPort=0;		// The port of this server, according to its own contract.

	OT_ASSERT_MSG(theServer.GetConnectInfo(strHostname, nPort),
				  "Unable to find my own connect info (which is in my server contract BTW.)\n");
	
	const int	nServerPort = nPort;
	
	// -----------------------------------------------------------------------
	
	
	SFSocket *socket = NULL;
	listOfConnections theConnections;
	
    // Alloc Socket
	socket = SFSocketAlloc();
	OT_ASSERT_MSG(NULL != socket, "SFSocketAlloc Failed\n");
	
    // Initialize SSL Socket
	int nSFSocketInit = SFSocketInit(socket,
					 strCAFile.Get(), 
					 strDHFile.Get(), 
					 strKeyFile.Get(),
					 strSSLPassword.Get(), 
									 NULL);
	
	OT_ASSERT_MSG(nSFSocketInit >= 0, "SFSocketInit Context Failed\n");
	
    // Listen on Address/Port
	int nSFSocketListen = SFSocketListen(socket, INADDR_ANY, nServerPort);
	
	OT_ASSERT_MSG(nSFSocketListen >= 0, "nSFSocketListen Failed\n");
	
	
	theServer.ActivateCron();
	
    do 
	{
        SFSocket * clientSocket = NULL;

        // Accept Client Connection
        if (NULL != (clientSocket = SFSocketAccept(socket)))
		{
			OTClientConnection * pClient = new OTClientConnection(*clientSocket, theServer);
			theConnections.push_back(pClient);
			OTLog::Output(0, "Accepting new connection.\n");
		}
		
		// READ THROUGH ALL CLIENTS HERE, LOOP A LIST
		// AND process in-buffer onto our list of messages.
		
		OTClientConnection * pConnection = NULL;
		
		for (listOfConnections::iterator ii = theConnections.begin(); 
			 ii != theConnections.end(); ++ii)
		{
			if (pConnection = *ii)
			{
				// Here we read the bytes from the pipe into the client's buffer
				// As necessary this function also processes those bytes into OTMessages
				// and adds them to the Input List for that client.
				pConnection->ProcessBuffer();
			}
		}
		
		
		
		// Now loop through them all again, and process their messages onto the reply list.
		
		pConnection = NULL;
		
		for (listOfConnections::iterator ii = theConnections.begin(); 
			 ii != theConnections.end(); ++ii)
		{
			if (pConnection = *ii)
			{
				OTMessage * pMsg = NULL;
				
				while (pMsg = pConnection->GetNextInputMessage())
				{
					OTMessage * pReply = new OTMessage;
					
					OT_ASSERT(NULL != pReply);
					
					if (theServer.ProcessUserCommand(*pMsg, *pReply, pConnection))
					{
						OTLog::vOutput(0, "Successfully processed user command: %s.\n", 
								pMsg->m_strCommand.Get());
						
						pConnection->AddToOutputList(*pReply);
					}
					else
					{
						OTLog::Output(0, "Unable to process user command in XML, or missing payload, in main.\n");
						delete pReply;
						pReply = NULL;
					}
					
					// I am responsible to delete this here.
					delete pMsg;
					pMsg = NULL;
				}
			}
		}
		
		
		// Now loop through them all again, and process their replies down the pipe
		
		pConnection = NULL;
		
		for (listOfConnections::iterator ii = theConnections.begin(); 
			 ii != theConnections.end(); ++ii)
		{
			if (pConnection = *ii)
			{
				OTMessage * pMsg = NULL;
				
				while (pMsg = pConnection->GetNextOutputMessage())
				{
					pConnection->ProcessReply(*pMsg);
						
					// I am responsible to delete this here.
					delete pMsg;
					pMsg = NULL;
				}
			}
		}
		
		
		
		
		
		// The Server now processes certain things on a regular basis.
		// This method call is what gives it the opportunity to do that.
	
		theServer.ProcessCron();
		
		
		
		
		// Now go to sleep for a tenth of a second.
		// (Main loop processes ten times per second, currently.)
		
		OTLog::SleepMilliseconds(100); // 100 ms == (1 second / 10)
		
		
		
		
    } while (1);

    // Close and Release Socket Resources
    SFSocketRelease(socket);

#ifdef _WIN32
	WSACleanup();
#endif

    return(0);
}

/*
 int do_server_loop(SSL *ssl)
 {
 int  err, nread;
 union u_header theCMD;
 int retVal = 0;
 int bClosed = 0;
 
 do
 {
 // clear the buffer.	
 memset((void *)theCMD.buf, 0, OT_CMD_HEADER_SIZE);
 
 for (nread = 0;  nread < OT_CMD_HEADER_SIZE;  nread += err)
 {
 err = SSL_read(ssl, theCMD.buf + nread, OT_CMD_HEADER_SIZE - nread);
 if (err <= 0)
 {
 bClosed = 1;
 break;
 }
 }
 
 if (bClosed)
 break;
 
 OTLog::vOutput(0, "\n===> Processing header from client message. First 5 bytes are: %d %d %d %d %d...\n",
 theCMD.buf[0],theCMD.buf[1],theCMD.buf[2],theCMD.buf[3],theCMD.buf[4]);
 
 ProcessMessage(ssl, &theCMD);
 }
 while (!(retVal = ((SSL_get_shutdown(ssl) & SSL_RECEIVED_SHUTDOWN) ? 1 : 0)));
 return retVal;
 }
 
 

*/


























