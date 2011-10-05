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
#include <stdio.h>
#include <sys/stat.h>	
#include <openssl/ssl.h>
}

#include <ctime>

#include "OTStorage.h"

#include "OTString.h"
#include "OTIdentifier.h"
#include "OTPseudonym.h"
#include "OTAssetContract.h"
#include "OTMint.h"

#include "OTLog.h"


// run this program from inside the transaction directory (it's a tool for creating mints for the server.)

int main (int argc, char * const argv[])
{
	if (argc < 5)
	{
		printf("\n\nUsage:  createmint  server_id  server_user_id  asset_type_id  full_path_to_data_folder\n\n"
			   "For now, expiration dates are automatically set:\n"
			   "-- FROM: Today, Now.\n"
			   "-- TO: 6 months from now.\n\n"
			   "It is recommended that you issue a new series (create a new mint) every 3 months for each\n"
			   "asset type, so that there is a 3-month overlap. In the future, this will be configured inside\n"
			   "the contracts themselves.\n\n"
			   "Server ID needs to match the Server ID from notaryServer.xml\n"
			   "Server user ID needs to match the Server User ID from notaryServer.xml\n"
			   "Asset Type ID needs to match the Asset ID (aka Hashed Contract ID) of the currency contract.\n"
			   "The path to the data folder is necessary for initialization of the OT library.\n\n");
		exit(1);
	}
	
	SSL_library_init();
	SSL_load_error_strings();

	// -----------------------------------------
	
	OTString		strServerID(argv[1]), strServerNymID(argv[2]), strAssetTypeID(argv[3]);
	OTIdentifier	ASSET_TYPE_ID(strAssetTypeID), SERVER_ID(strServerID);
	
	std::string strDataFolderPath(argv[4]), strWalletFile("wallet.xml");
	
	bool bSuccessInitDefault = OTDB::InitDefaultStorage(OTDB_DEFAULT_STORAGE, 
														OTDB_DEFAULT_PACKER, strDataFolderPath, strWalletFile);
		
	// -----------------------------------------
	
	OTString strMintPath;
	bool bFileIsPresent = false;		
	int nSeries = 0;
	
	for (nSeries = 0; nSeries < 1000; nSeries++)
	{
		struct stat st;

		strMintPath.Format("%s%s%s%s%s%s%s%s%d", 
						   OTLog::Path(), 
						   OTLog::PathSeparator(),
						   OTLog::MintFolder(),
						   OTLog::PathSeparator(),
						   strServerID.Get(),
						   OTLog::PathSeparator(),
						   strAssetTypeID.Get(), ".", nSeries);
		
		bFileIsPresent = (stat(strMintPath.Get(), &st) == 0);
		
		if (!bFileIsPresent)
			break;
	}
	
	// if bFileIsPresent is STILL true, that means we got all the way up to 1000 and the 
	// file was present every time.
	// Geez, there must be 1000 mints on this computer.  At one new Mint per 3 months,
	// that's 4 per year, that's 250 years already!!
	if (bFileIsPresent)
	{
		OTLog::Output(0, "This program automatically finds the next series, up to 1000. You\n"
				"have reached 1000. You will have to change the source code of this\n"
				"program in order to continue. Sorry.\n");
		exit(1);
	}
	
	
	// nSeries now contains the number we need to use for the next series.
	// and strMintPath now contains the correct file path.
	
	OTMint * pMint = new OTMint(strServerID, strServerNymID, strAssetTypeID);
	
	OTString strSeries; strSeries.Format("%s%d", ".", nSeries);
	//
	if ((NULL != pMint) && pMint->LoadMint(strSeries.Get()))
	{
		OTLog::Output(0, "The mint already exists. Delete it first if you wish to re-create it.\n");
	}
	else 
	{
		OTLog::vOutput(0, "Mint file does not (yet) exist for series %d and asset type:\n%s\n Creating......\n", 
				nSeries, strAssetTypeID.Get());
		
		if (pMint)
		{	
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
				
//				OTString strFilename;// strPUBLICFilename;		
//				strFilename.		Format("%s%s%s",		strServerID.Get(), OTLog::PathSeparator(), strAssetTypeID.Get());
//				strPUBLICFilename.	Format("%s%s%s%sPUBLIC",strServerID.Get(), OTLog::PathSeparator(), strAssetTypeID.Get(), ".");
				
				OTString strServerFolder;
				strServerFolder.Format("%s%s%s", OTLog::MintFolder(), OTLog::PathSeparator(), strServerID.Get());
				
				if (OTLog::ConfirmOrCreateFolder(OTLog::MintFolder()) &&
					OTLog::ConfirmOrCreateFolder(strServerFolder.Get()))
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
					
//					pMint->SaveContract(OTLog::MintFolder(), strFilename.Get());  // save the mint file.
					
					// -------------------------------------------------------------------
					// Now I sign it again, to get the private keys out of there.
					pMint->ReleaseSignatures();
					pMint->SignContract(theNym);
					pMint->SaveContract();
					
					pMint->SaveMint(".PUBLIC");  // save the public mint file.
//					pMint->SaveContract(OTLog::MintFolder(), strPUBLICFilename.Get());  // save the public mint file.
					
					OTLog::Output(0, "Done.\n");
				}
				else
					OTLog::Output(0, "Error calling OTLog::ConfirmOrCreateFolder() for path/mints/server_id\n");
			}
			else
				OTLog::Output(0, "Error calling theNym.Loadx509CertAndPrivateKey()\n");
		}
		else 
		{
			OTLog::Output(0, "Error allocating memory for new OTMint.\n");
		}
	}
	
	return 0;
}
