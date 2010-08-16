/************************************************************************************
 *    
 *  client.cpp  (the actual command line test client that encapsulates OTClient)
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
	
#include "SSL-Example/SFSocket.h"
};


#include "OTString.h"
#include "OTClient.h"
#include "OTServerConnection.h"
#include "OTMessage.h"
#include "OTString.h"
#include "OTWallet.h"
#include "OTPseudonym.h"
#include "OTEnvelope.h"
#include "OTCheque.h"

extern OTClient		g_Client;
extern OTWallet		g_Wallet;
extern OTPseudonym *g_pTemporaryNym;





// TODO REALLY NEED to move this crap to a config file...
// ALso, FYI, the below paths may not work unless you put a fully-qualified path (which I haven't.)
#define KEY_PASSWORD        "test"  // RIGHT NOW THE PASSWORD FOR CONNECTING TO THE SERVER IS HARDCODED HERE.  TODO: config file, password prompt.

#ifdef WINDOWS

#define SERVER_PATH_DEFAULT	"C:\\Users\\REDACTED\\Projects\\Open-Transactions\\testwallet"
#define CA_FILE             "SSL-Example\\ca.crt"
#define KEY_FILE            "SSL-Example\\client.pem"

#else

#define SERVER_PATH_DEFAULT	"/Users/REDACTED/Projects/Open-Transactions/testwallet"
#define CA_FILE             "SSL-Example/ca.crt"
#define KEY_FILE            "SSL-Example/client.pem"

#endif

// NOTE: this SSL connection is entirely different from the user's cert/pubkey that he uses for his UserID while 
// talking to the server. I may be using the same key for that, but this code here is not about my wallet talking
// to its mint. Rather, it's about an SSL client app talking to an SSL server, at a lower layer, before my app's
// intelligence takes over.  Just like when you use SSH to connect somewhere on a terminal. There is some immediate
// key negotiation going on. Once connected, you might run software that asks you for a public key, which could be
// AN ENTIRELY DIFFERENT PUBLIC KEY. THAT is where, metaphorically, your Public Key / User ID comes into play.






int main (int argc, char **argv) 
{
	
	// -----------------------------------------------------------------------
	
	OTString strCAFile, strKeyFile, strSSLPassword;
	
	if (argc < 2)
	{
		fprintf(stdout, "\n\nUsage:  testwallet <SSL-password> <full path to testwallet folder>\n\n"
				"(Password defaults to '%s' if left blank.)\n"
				"(Folder defaults to '%s' if left blank.)\n", KEY_PASSWORD, SERVER_PATH_DEFAULT);
		
		strSSLPassword.Set(KEY_PASSWORD);
		OTPseudonym::OTPath.Set(SERVER_PATH_DEFAULT);
	}
	else if (argc < 3)
	{
		fprintf(stdout, "\n\nUsage:  transaction <SSL-password> <full path to transaction folder>\n\n"
				"(Folder defaults to '%s' if left blank.)\n", SERVER_PATH_DEFAULT);
		
		strSSLPassword.Set(argv[1]);
		OTPseudonym::OTPath.Set(SERVER_PATH_DEFAULT);
	}
	else 
	{
		strSSLPassword.Set(argv[1]);
		OTPseudonym::OTPath.Set(argv[2]);
	}	
	
	strCAFile. Format("%s%s%s", OTPseudonym::OTPath.Get(), OTPseudonym::OTPathSeparator.Get(), CA_FILE);
	strKeyFile.Format("%s%s%s", OTPseudonym::OTPath.Get(), OTPseudonym::OTPathSeparator.Get(), KEY_FILE);
	
	
	// -----------------------------------------------------------------------

	
	
	// ------------------------------------------------------------------------------
	
	//
	// Basically, loop:
	//
	//	1) Present a prompt, and get a user string of input. Wait for that.
	//
	//	2) Process it out as an OTMessage to the server. It goes down the pipe.
	//
	//	3) Sleep for 1 second.
	//
	//	4) Awake and check for messages to be read in response from the server.
	//	   Loop. As long as there are any responses there, then process and handle
	//	   them all.
	//	   Then continue back up to the prompt at step (1).
	
    char buf[80];
 	int retVal = 0;
	
	int nExpectResponse = 0;
	
	fprintf(stderr,"\n\nWelcome to Open Transactions, version %s.\n"
			"You may wish to 'load' then 'connect' then 'stat'.\n", "0.2");
//	fprintf(stderr,"Starting client loop. u_header size in C code is %d.\n", OT_CMD_HEADER_SIZE);
	
	for(;;)
	{
		nExpectResponse = 0;
		
		// 1) Present a prompt, and get a user string of input. Wait for that.
		fprintf(stdout, "\nWallet> ");
		
		if (!fgets(buf, sizeof(buf), stdin))
            break;
				
		fprintf(stderr,".\n..\n...\n....\n.....\n......\n.......\n........\n.........\n..........\n"
				"...........\n............\n.............\n");
		
		// so we can process the user input
		std::string strLine = buf;
			
		// 1.5 The one command that doesn't involve a message to the server (so far)
		//     is the command to load the wallet from disk (which we do before we can
		//     do anything else.)  That and maybe the message to CONNECT to the server.
		// Load wallet.xml
		if (strLine.compare(0,4,"load") == 0)
		{
			fprintf(stderr, "User has instructed to load wallet.xml...\n");
			
			g_Wallet.LoadWallet("wallet.xml");
//			g_Wallet.SaveWallet("NEWwallet.xml"); // todo remove this test code.
			
			continue;
		}
		
		else if (strLine.compare(0,6,"cheque") == 0)
		{
			if (NULL == g_pTemporaryNym)
			{
				fprintf(stdout, "No Nym yet available to sign the cheque with. Try 'load'.\n");
				continue;
			}

			fprintf(stdout, "Enter the ID for your Asset Account that the cheque will be drawn on: ");
			OTString strTemp;
			strTemp.OTfgets(stdin);

			const OTIdentifier ACCOUNT_ID(strTemp), USER_ID(*g_pTemporaryNym);
			OTAccount * pAccount = g_Wallet.GetAccount(ACCOUNT_ID);
			
			if (NULL == pAccount)
			{
				fprintf(stderr, "That account isn't loaded right now. Try 'load'.\n");
				continue;
			}
			
			// To write a cheque, we need to burn one of our transaction numbers. (Presumably the wallet
			// is also storing a couple of these, since they are needed to perform any transaction.)
			//
			// I don't have to contact the server to write a cheque -- as long as I already have a transaction
			// number I can use to write it. Otherwise I'd have to ask the server to send me one first.
			OTString strServerID(pAccount->GetRealServerID());
			long lTransactionNumber=0;
			
			if (false == g_pTemporaryNym->GetNextTransactionNum(*g_pTemporaryNym, strServerID, lTransactionNumber))
			{
				fprintf(stdout, "Cheques are written offline, but you still need a transaction number\n"
						"(and you have none, currently.) Try using 'n' to request another transaction number.\n");
				continue;
			}

			
			OTCheque theCheque(pAccount->GetRealServerID(), pAccount->GetAssetTypeID());
			
			// Recipient
			fprintf(stdout, "Enter a User ID for the recipient of this cheque (defaults to blank): ");
			OTString strRecipientUserID;
			strRecipientUserID.OTfgets(stdin);
			const OTIdentifier RECIPIENT_USER_ID(strRecipientUserID.Get());
			
			// Amount
			fprintf(stdout, "Enter an amount: ");
			strTemp.Release();
			strTemp.OTfgets(stdin);
			const long lAmount = atol(strTemp.Get());
			
			// -----------------------------------------------------------------------
			
			// Memo
			fprintf(stdout, "Enter a memo for your check: ");
			OTString strChequeMemo;
			strChequeMemo.OTfgets(stdin);

			// -----------------------------------------------------------------------
			
			// Valid date range (in seconds)
			fprintf(stdout, 
					" 6 minutes	==      360 Seconds\n"
					"10 minutes	==      600 Seconds\n"
					"1 hour		==     3600 Seconds\n"
					"1 day		==    86400 Seconds\n"
					"30 days		==  2592000 Seconds\n"
					"3 months	==  7776000 Seconds\n"
					"6 months	== 15552000 Seconds\n\n"
					);

			long lExpirationInSeconds = 3600;
			fprintf(stdout, "How many seconds before cheque expires? (defaults to 1 hour: %ld): ", lExpirationInSeconds);
			strTemp.Release();
			strTemp.OTfgets(stdin);
			
			if (strTemp.GetLength() > 1)
				lExpirationInSeconds = atol(strTemp.Get());
			
			
			// -----------------------------------------------------------------------
			
			time_t	VALID_FROM	= time(NULL); // This time is set to TODAY NOW

			fprintf(stdout, "Cheque may be cashed STARTING date (defaults to now, in seconds) [%ld]: ", VALID_FROM);
			strTemp.Release();
			strTemp.OTfgets(stdin);
			
			if (strTemp.GetLength() > 2)
				VALID_FROM = atol(strTemp.Get());
			
			
			const time_t VALID_TO = VALID_FROM + lExpirationInSeconds; // now + 3600

			// -----------------------------------------------------------------------

			bool bIssueCheque = theCheque.IssueCheque(lAmount, lTransactionNumber, VALID_FROM, VALID_TO, 
													  ACCOUNT_ID, USER_ID, strChequeMemo,
													  (strRecipientUserID.GetLength() > 2) ? &(RECIPIENT_USER_ID) : NULL);
			
			if (bIssueCheque)
			{
				theCheque.SignContract(*g_pTemporaryNym);
				theCheque.SaveContract();
				
				OTString strCheque;
				theCheque.SaveContract(strCheque);
				
				fprintf(stdout, "\n\nOUTPUT:\n\n\n%s\n", strCheque.Get());
			}
			else {
				fprintf(stdout, "Failed trying to issue the cheque!\n");
			}

			continue;
		}
		
		else if (strLine.compare(0,7,"decrypt") == 0)
		{
			if (NULL == g_pTemporaryNym)
			{
				fprintf(stdout, "No Nym yet available to decrypt with.\n");
				continue;
			}
		
			fprintf(stdout, "Enter text to be decrypted:\n> ");
			
			OTASCIIArmor theArmoredText;
			char decode_buffer[200];
			
			do {
				fgets(decode_buffer, sizeof(decode_buffer), stdin);				
				theArmoredText.Concatenate("%s\n", decode_buffer);
				fprintf(stdout, "> ");
			} while (strlen(decode_buffer)>1);
			
			
			OTEnvelope	theEnvelope(theArmoredText);
			OTString	strDecodedText;
			
			theEnvelope.Open(*g_pTemporaryNym, strDecodedText);
				
			fprintf(stdout, "\n\nDECRYPTED TEXT:\n\n%s\n\n", strDecodedText.Get());
			
			continue;
		}
		
		else if (strLine.compare(0,6,"decode") == 0)
		{
			fprintf(stdout, "Enter text to be decoded:\n> ");
			
			OTASCIIArmor theArmoredText;
			char decode_buffer[200];
			
			do {
				fgets(decode_buffer, sizeof(decode_buffer), stdin);				
				theArmoredText.Concatenate("%s\n", decode_buffer);
				fprintf(stdout, "> ");
			} while (strlen(decode_buffer)>1);
			
			OTString strDecodedText(theArmoredText);
			
			fprintf(stdout, "\n\nDECODED TEXT:\n\n%s\n\n", strDecodedText.Get());
			
			continue;
		}
		
		else if (strLine.compare(0,6,"encode") == 0)
		{
			fprintf(stdout, "Enter text to be ascii-encoded (terminate with ~ on a new line):\n> ");
			
			OTString strDecodedText;
			char decode_buffer[200];
			
			do {
				fgets(decode_buffer, sizeof(decode_buffer), stdin);
				
				if (decode_buffer[0] != '~')
				{
					strDecodedText.Concatenate("%s", decode_buffer);
					fprintf(stdout, "> ");
				}
			} while (decode_buffer[0] != '~');
			
			OTASCIIArmor theArmoredText(strDecodedText);
			
			fprintf(stdout, "\n\nENCODED TEXT:\n\n%s\n\n", theArmoredText.Get());
			
			continue;
		}
		
		else if (strLine.compare(0,4,"hash") == 0)
		{
			fprintf(stdout, "Enter text to be hashed (terminate with ~ on a new line):\n> ");
			
			OTString strDecodedText;
			char decode_buffer[200];
			
			do {
				fgets(decode_buffer, sizeof(decode_buffer), stdin);
				
				if (decode_buffer[0] != '~')
				{
					strDecodedText.Concatenate("%s\n", decode_buffer);
					fprintf(stdout, "> ");
				}
			} while (decode_buffer[0] != '~');
			
			OTIdentifier theIdentifier;
			theIdentifier.CalculateDigest(strDecodedText);

			OTString strHash(theIdentifier);
			
			fprintf(stdout, "\n\nMESSAGE DIGEST:\n\n%s\n\n", strHash.Get());
			
			continue;
		}
		
		else if (strLine.compare(0,4,"stat") == 0)
		{
			fprintf(stderr, "User has instructed to display wallet contents...\n");
			
			OTString strStat;
			g_Wallet.DisplayStatistics(strStat);
			fprintf(stderr, "%s\n", strStat.Get());
			
			continue;
		}
		
		else if (strLine.compare(0,4,"quit") == 0)
		{
			fprintf(stderr, "User has instructed to exit the wallet...\n");
						
			break;
		}
		
		// 1.6 Connect to the first server in the wallet. (assuming it loaded a server contract.)
		else if (strLine.compare(0,7,"connect") == 0)
		{
			fprintf(stderr, "User has instructed to connect to the first server available in the wallet.\n");
						
			// Wallet, after loading, should contain a list of server
			// contracts. Let's pull the hostname and port out of
			// the first contract, and connect to that server.
			bool bConnected = g_Wallet.ConnectToTheFirstServerOnList(strCAFile, strKeyFile, strSSLPassword); 
			
			if (bConnected)
				fprintf(stderr, "Success. (Connected to the first notary server on your wallet's list.)\n");
			else {
				fprintf(stderr, "Either the wallet is not loaded, or there was an error connecting to server.\n");
			}

			continue;
		}
		
		if (!g_Wallet.m_Connection.IsConnected())
		{
			fprintf(stdout, "(You are not connected to a notary server--you cannot send commands.)\n");
			continue;
		}
			
		// 2) Process it out as an OTMessage to the server. It goes down the pipe.
		g_Wallet.m_Connection.ProcessMessageOut(buf, &nExpectResponse);
		
		// 3) Sleep for 1 second.
		sleep (1);
		
		bool bFoundMessage = false;

		// 4) While there are messages to be read in response from the server,
		//	  then process and handle them all.
		do 
		{
			OTMessage theMsg;
			
			// If this returns true, that means a Message was
			// received and processed into an OTMessage object (theMsg)
			bFoundMessage = g_Wallet.m_Connection.ProcessInBuffer(theMsg);
			
			if (true == bFoundMessage)
			{
//				OTString strReply;
//				theMsg.SaveContract(strReply);
//				fprintf(stderr, "\n\n**********************************************\n"
//						"Successfully in-processed server response.\n\n%s\n", strReply.Get());
				g_Client.ProcessServerReply(g_Wallet.m_Connection, theMsg);
			}
		
		} while (true == bFoundMessage);
	} // for
	
	fprintf(stderr,"Finished running client.\n");

	return retVal;
}











































