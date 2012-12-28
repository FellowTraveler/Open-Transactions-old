/************************************************************************************
*    
*  main.cpp (OT Create Mint)
*  
*              Open Transactions:  Library, Protocol, Server, and Test Client
*    
*                      -- Anonymous Numbered Accounts
*                      -- Untraceable Digital Cash
*                      -- Triple-Signed Receipts
*                      -- Basket Currencies
*                      -- Signed XML Contracts
*    
*    Copyright (C) 2010-2012 by "Fellow Traveler" (A pseudonym)
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

#ifdef _WIN32
#include <WinsockWrapper.h>
#include <ShlObj.h>
#endif

extern "C"
{
#include <cstdio>
#include <sys/stat.h>	
#include <openssl/ssl.h>
}

#include <ctime>

#include "simpleini/SimpleIni.h"


#include "OTStorage.h"

#include "OTString.h"
#include "OTIdentifier.h"
#include "OTPseudonym.h"
#include "OTAssetContract.h"
#include "OTMint.h"

#include "OTEnvelope.h"
#include "OTServer.h"

#include "OTLog.h"

// ------------------------------------------------

// TODO: what about android for all the defaults here? Are there ini files in android? Revisit.
// so far, treating it like unix since it is.
//
// Paths
//

#define SERVER_PATH_DEFAULT	"server_data" //should get programmatically
#define SERVER_CONFIG_KEY "server"
#define SERVER_CONFIG_FILENAME "server.cfg"
#define SERVER_LOGFILE_FILENAME "log-server.log"
#define SERVER_MASTER_KEY_TIMEOUT_DEFAULT -1
#define SERVER_MAIN_FILENAME "notaryServer.xml"

// ----------------------------------------------------------------

#define KEY_PASSWORD        "test"
//#define KEY_PASSWORD        ""





int main (int argc, char * const argv[])
{
	if (argc < 4)
	{
		printf("\n\nUsage:  createmint  server_id  server_user_id  asset_type_id \n\n"
			"For now, expiration dates are automatically set:\n"
			"-- FROM: Today, Now.\n"
			"-- TO: 6 months from now.\n\n"
			"It is recommended that you issue a new series (create a new mint) every 3 months for each\n"
			"asset type, so that there is a 3-month overlap. In the future, this will be configured inside\n"
			"the contracts themselves.\n\n"
			"Server ID needs to match the Server ID from notaryServer.xml\n"
			"Server user ID needs to match the Server User ID from notaryServer.xml\n"
			"Asset Type ID needs to match the Asset ID (aka Hashed Contract ID) of the currency contract.\n\n"
			//			   "The path to the data folder is necessary for initialization of the OT library.\n\n"
			//             "(You probably want to use ~/.ot/server_data as your data folder.)\n\n"
			);
		return 0;
	}
	// **************************************************************************

	class __OTcreatemint_RAII
	{
	public:
		__OTcreatemint_RAII()
		{
			if(!OTLog::Init(SERVER_CONFIG_KEY,0)) { assert(false); };  // setup the logger.

			OTLog::vOutput(0, "\n\nWelcome to Open Transactions -- 'createmint', version %s\n", 
				OTLog::Version());
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
			OTLog::vOutput(0,"The Winsock 2.2 dll was found okay\n");
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

			//
			// OT Server Path:
			//
			{
				bool bSetupPathsSuccess = false;
				if(!OTDataFolder::Init(SERVER_CONFIG_KEY)) { OT_ASSERT(false); }
				else
					bSetupPathsSuccess = true;

				OT_ASSERT_MSG(bSetupPathsSuccess, "main(): Assert failed: Failed to set OT Path");
			}

			// -----------------------------------------------------------------------    

			OTCrypto::It()->Init(); // (OpenSSL gets initialized here.)

			// ------------------------------------
		}
		~__OTcreatemint_RAII()
		{
			// We clean these up in reverse order from the Init function, which just seems
			// like the best default, in absence of any brighter ideas.
			//
			OTCrypto::It()->Cleanup();  // (OpenSSL gets cleaned up here.)

			// ------------------------------------
#ifdef _WIN32
			WSACleanup(); // Corresponds to WSAStartup() in InitOTAPI().
#endif
			// ------------------------------------
		}
	};
	// --------------------------------------------

	__OTcreatemint_RAII   the_createmint_cleanup;

	// **************************************************************************

	OTServer theServer;

	// -----------------------------------------

	int nReturnVal = 0;

	OTString		strServerID(argv[1]),
		strServerNymID(argv[2]),
		strAssetTypeID(argv[3]);

	OTIdentifier	ASSET_TYPE_ID(strAssetTypeID),
		SERVER_ID(strServerID);

	//	std::string strDataFolderPath(argv[4]), strNotaryFile("notaryServer.xml");

	OTLog::vOutput(0, 
		"\nNow loading the server nym, which will also ask you for a password, to unlock\n"
		"its private key. (Default password is \"%s\".)\n", KEY_PASSWORD);

	// Keys, etc are loaded here. ===> Assumes main path is set! <===
	//
	theServer.Init(true); //bool bReadOnly=false by default (We don't want to overwrite anything if the ACTUAL server is running...)


	//  NOTE: I copied some code in here from xmlrpcxx_server.cpp, including the above
	//  call to theServer.Init(), which has the InitDefaultStorage inside of it, and
	//  which uses OTLog::Path(), which the above new code should be setting properly
	//  before theServer.Init() actually gets called. (So this should work....)
	//  
	//	bool bSuccessInitDefault = OTDB::InitDefaultStorage(OTDB_DEFAULT_STORAGE, 
	//														OTDB_DEFAULT_PACKER, strDataFolderPath, strNotaryFile);
	//    if (!bSuccessInitDefault)
	//    {
	//        OTLog::vError("\n\n%s: Failed invoking OTDB::InitDefaultStorage with path: %s and main filename: %s\n\n",
	//                      __FUNCTION__, strDataFolderPath.c_str(), strNotaryFile.c_str());
	//        return 0;
	//    }
	// -----------------------------------------

	OTString strMintPath;
	bool bFileIsPresent = false;		
	int nSeries = 0;

	for (nSeries = 0; nSeries < 10000; ++nSeries)
	{
//		struct stat st;

		OTString strFilename;
		strFilename.Format("%s%s%d", strAssetTypeID.Get(), ".", nSeries);

		bFileIsPresent = OTDB::Exists(OTFolders::Mint().Get(),
                                      strServerID.Get(),
                                      strFilename.Get());

		// Old Code
		//strMintPath.Format("%s%s%s%s%s%s%s%s%d", 
		//	OTLog::Path(), 
		//	OTLog::PathSeparator(),
		//	OTFolders::Mint().Get(),
		//	OTLog::PathSeparator(),
		//	strServerID.Get(),
		//	OTLog::PathSeparator(),
		//	strAssetTypeID.Get(), ".", nSeries);
		//bFileIsPresent = (stat(strMintPath.Get(), &st) == 0);

		if (!bFileIsPresent)
			break;
	}

	// if bFileIsPresent is STILL true, that means we got all the way up to 1000 and the 
	// file was present every time.
	// Geez, there must be 10000 mints on this computer.  At one new Mint per 3 months,
	// that's 4 per year, that's 2500 years already!!
	//
	if (bFileIsPresent)
	{
		OTLog::Output(0, "\n\nThis program automatically finds the next series, up to 10000. You\n"
			"have reached 10000. You will have to change the source code of this\n"
			"program in order to continue. Sorry.\n\n");
		return 0;
	}
	// ---------------------------------------------------------------------

	// nSeries now contains the number we need to use for the next series.
	// and strMintPath now contains the correct file path.

	OTMint * pMint = new OTMint(strServerID, strServerNymID, strAssetTypeID);
	OT_ASSERT(NULL != pMint);

	OTString strSeries; strSeries.Format("%s%d", ".", nSeries);

	if (pMint->LoadMint(strSeries.Get()))
	{
		OTLog::Output(0, "\n\nSorry, that mint already exists. Delete it first if you wish to re-create it.\n\n");
	}
	else 
	{
		OTLog::vOutput(0, "\n\nMint file does not (yet) exist for series %d and asset type:\n%s\n Creating......\n\n", 
			nSeries, strAssetTypeID.Get());

		// TODO: read the denominations out of the asset contract itself, instead of hardcoding them here.


		// Calculate FROM as Today, Now, 
		// then calculate TO as 6 months from now, 
		// and EXPIRATION as 3 months from now.
		//
		// TODO: Let these numbers be configured either in server operator contract, or issuer contract.
		// In the meantime, 3 and 6 months are good enough.

		OTPseudonym theNym;
		theNym.SetIdentifier(strServerNymID);

		// 1 hour	==     3600 Seconds
		// 1 day	==    86400 Seconds
		// 30 days	==  2592000 Seconds
		// 3 months ==  7776000 Seconds
		// 6 months == 15552000 Seconds


		// This part requires the server operator to enter his passphrase.
		// Which is why the server can't just fire it off automatically and
		// make a mint available to the client.  The client has to wait a day or
		// until the operator is able to run this script and type the passphrase.
		if (theNym.Loadx509CertAndPrivateKey())
		{								
			const time_t	CURRENT_TIME	= time(NULL), 
				VALID_TO		= CURRENT_TIME + 15552000,	// Tokens generated by this mint are valid from today until 6 months from today
				MINT_EXPIRATION	= CURRENT_TIME + 7776000;	// The mint itself will expire in 3 months from today, and be replaced with a new one.

			pMint->GenerateNewMint(nSeries, CURRENT_TIME, VALID_TO, MINT_EXPIRATION, ASSET_TYPE_ID, SERVER_ID,
				// penny, nickel, dime, quarter, $1, $5, $10, $20, $100, $1000
				theNym, 1, 5, 10, 25, 100, 500, 1000, 2000, 10000, 100000);
			// should be: 1, 2, 4,   8,  16,  32,   64,  128,   256,    512, 1024, 2048, 4096, 8192, 16384, 32768, 65536

			// ---------------------------------------

			//			OTString strFilename;// strPUBLICFilename;		
			//			strFilename.		Format("%s%s%s",		strServerID.Get(), OTLog::PathSeparator(), strAssetTypeID.Get());
			//			strPUBLICFilename.	Format("%s%s%s%sPUBLIC",strServerID.Get(), OTLog::PathSeparator(), strAssetTypeID.Get(), ".");

			if (!OTDataFolder::IsInitialized()) { OT_ASSERT(false); };

			OTString strServerFolder(""), strMintFolder("");

			if (!OTPaths::AppendFolder(strMintFolder,	OTDataFolder::Get(),OTFolders::Mint())) { OT_ASSERT(false); }; // mint/
			if (!OTPaths::AppendFolder(strServerFolder,	strMintFolder,		strServerID.Get())) { OT_ASSERT(false); }; // mint/serverID

			bool bFolderCreated;
			if (OTPaths::BuildFolderPath(strServerFolder,bFolderCreated))
			{
				// -------------------------------------------------------------------
				// This causes the next serialization to save the private, not just public, keys.
				pMint->SetSavePrivateKeys(); // <== PRIVATE MINT VERSION.

				pMint->SignContract(theNym);
				pMint->SaveContract();

				pMint->SaveMint();		// save the private mint file as: path/mints/server_id/Asset_TypeID (overwriting the last "current mint"...)
				pMint->SaveMint(strSeries.Get()); // save the private mint file as: path/mints/server_id/Asset_TypeID.nSeries (These accumulate.)

				// When the server needs to reference the "current" private keys, then it just loads the
				// mint without specifying the series number. Since this file is overwritten with each new 
				// mint, it is thus always the latest one.  (Similarly, the latest public is always asset_id.PUBLIC)
				// On the other hand, if I need to load the keys for a specific series, (since more than one may be
				// redeemable, even if only the latest one is being issued) then they are all also saved by series
				// number, which is not overwritten with each new mint, but accumulates.
				// That is why above, you see me save the mint twice in two different files, and below you see
				// it being saved with the .PUBLIC appending to the filename.

				//				pMint->SaveContract(OTFolders::Mint().Get(), strFilename.Get());  // save the mint file.

				// -------------------------------------------------------------------
				// Now I sign it again, to get the private keys out of there.
				pMint->ReleaseSignatures();
				pMint->SignContract(theNym);
				pMint->SaveContract();

				pMint->SaveMint(".PUBLIC");  // save the public mint file.
				//				pMint->SaveContract(OTFolders::Mint().Get(), strPUBLICFilename.Get());  // save the public mint file.

				nReturnVal = 1;

				OTLog::Output(0, "\nDone.\n\n");
			}
			else
				OTLog::Output(0, "\n\nError calling OTLog::ConfirmOrCreateFolder() for path/mints/server_id\n\n");
		}
		else
			OTLog::Output(0, "\n\nError calling theNym.Loadx509CertAndPrivateKey()\n\n");
	} // Mint file doesn't exist yet (therefore the above block creates it...)

	return nReturnVal;
}




// ------------
