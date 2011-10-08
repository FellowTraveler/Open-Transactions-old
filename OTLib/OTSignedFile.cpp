/************************************************************************************
 *    
 *  OTSignedFile.cpp
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


#include <cstring>


#include "irrxml/irrXML.h"

using namespace irr;
using namespace io;


#include "OTStorage.h"


#include "OTSignedFile.h"
#include "OTPseudonym.h"
#include "OTLog.h"



void OTSignedFile::UpdateContents()
{
	// I release this because I'm about to repopulate it.
	m_xmlUnsigned.Release();
	
	m_xmlUnsigned.Concatenate("<?xml version=\"%s\"?>\n\n", "1.0");		
	
	m_xmlUnsigned.Concatenate("<signedFile\n version=\"%s\"\n"
							  " localDir=\"%s\"\n"
							  " filename=\"%s\""
							  " >\n\n", 
							  m_strVersion.Get(),
							  m_strLocalDir.Get(),
							  m_strSignedFilename.Get());		
	
	if (m_strSignedFilePayload.Exists())
	{
		OTASCIIArmor ascPayload(m_strSignedFilePayload);		
		m_xmlUnsigned.Concatenate("<filePayload>\n%s</filePayload>\n\n", ascPayload.Get());
	}
	
	m_xmlUnsigned.Concatenate("</signedFile>\n");
}


int OTSignedFile::ProcessXMLNode(irr::io::IrrXMLReader*& xml)
{
	int nReturnVal = 0;
	
	// Here we call the parent class first.
	// If the node is found there, or there is some error,
	// then we just return either way.  But if it comes back
	// as '0', then nothing happened, and we'll continue executing.
	//
	// -- Note you can choose not to call the parent if
	// you don't want to use any of those xml tags.
	// As I do below, in the case of OTAccount.
	//if (nReturnVal = OTContract::ProcessXMLNode(xml))
	//	return nReturnVal;
	
	if (!strcmp("signedFile", xml->getNodeName())) 
	{		
		m_strVersion			= xml->getAttributeValue("version");	
		
		m_strPurportedLocalDir	= xml->getAttributeValue("localDir");					
		m_strPurportedFilename	= xml->getAttributeValue("filename");					
		
		// ---------------------
				
		nReturnVal = 1;
	}
	
	else if (!strcmp("filePayload", xml->getNodeName())) 
	{		
		if (false == LoadEncodedTextField(xml, m_strSignedFilePayload))
		{
			OTLog::Error("Error in OTSignedFile::ProcessXMLNode: filePayload field without value.\n");
			return (-1); // error condition
		}
		
		return 1;
	}
	
	return nReturnVal;	
}


	


// We just loaded a certain subdirectory/filename
// This file also contains that information within it.
// This function allows me to compare the two and make sure
// the file that I loaded is what it claims to be.
//
// Make sure you also VerifySignature() whenever doing something
// like this  :-)
//
// Assumes SetFilename() has been set, and that LoadFile() has just been called.
bool OTSignedFile::VerifyFile()
{
	if (m_strLocalDir.Compare(m_strPurportedLocalDir) &&
		m_strSignedFilename.Compare(m_strPurportedFilename))
		return true;
	
	return false;
}




OTSignedFile::OTSignedFile(const OTString & LOCAL_SUBDIR, const OTString & FILE_NAME) : OTContract()
{
	m_strContractType.Set("FILE");
	
	SetFilename(LOCAL_SUBDIR, FILE_NAME);
}

OTSignedFile::OTSignedFile(const char * LOCAL_SUBDIR, const OTString & FILE_NAME) : OTContract()
{
	m_strContractType.Set("FILE");
	
	OTString strLocalSubdir(LOCAL_SUBDIR);
	
	SetFilename(strLocalSubdir, FILE_NAME);
}

OTSignedFile::OTSignedFile(const char * LOCAL_SUBDIR, const char * FILE_NAME) : OTContract()
{
	m_strContractType.Set("FILE");
	
	OTString strLocalSubdir(LOCAL_SUBDIR), strFile_Name(FILE_NAME);
	
	SetFilename(strLocalSubdir, strFile_Name);
}


// This is entirely separate from the OTContract saving methods.  This is specifically
// for saving the internal file payload based on the internal file information, which
// this method assumes has already been set (using SetFilename())
bool OTSignedFile::SaveFile()
{
	const OTString strTheFileName(m_strFilename);
	const OTString strTheFolderName(m_strFoldername);
	
	// OTContract doesn't natively make it easy to save a contract to its own filename.
	// Funny, I know, but OTContract is designed to save either to a specific filename,
	// or to a string parameter, or to the internal rawfile member. It doesn't normally
	// save to its own filename that was used to load it. But OTSignedFile is different...
	
	// This saves to a file, the name passed in as a char *.
	return SaveContract(strTheFolderName.Get(), strTheFileName.Get());
}

// Assumes SetFilename() has already been set.
bool OTSignedFile::LoadFile()
{
//	OTLog::vOutput(0, "DEBUG LoadFile (Signed) folder: %s file: %s \n", m_strFoldername.Get(), m_strFilename.Get());
	
	if (OTDB::Exists(m_strFoldername.Get(), m_strFilename.Get()))
		return LoadContract();

	return false;
}

void OTSignedFile::SetFilename(const OTString & LOCAL_SUBDIR, const OTString & FILE_NAME)
{
	// OTSignedFile specific variables.
	m_strLocalDir		= LOCAL_SUBDIR;
	m_strSignedFilename	= FILE_NAME;
	
	// OTContract variables.
	m_strFoldername	= m_strLocalDir;
	m_strFilename	= m_strSignedFilename;

	/*
	m_strFilename.Format("%s%s" // data_folder/
						 "%s%s" // nyms/
						 "%s",  // 5bf9a88c.nym
						 OTLog::Path(), OTLog::PathSeparator(),
						 m_strLocalDir.Get(), OTLog::PathSeparator(),
						 m_strSignedFilename.Get());
	*/
	// Software Path + Local Sub-directory + Filename
	//
	// Finished Product:    "transaction/nyms/5bf9a88c.nym"
}

OTSignedFile::OTSignedFile() : OTContract()
{
	m_strContractType.Set("FILE");
}


OTSignedFile::~OTSignedFile()
{
	// No need to call release here -- it's called by the parent.
}

	
void OTSignedFile::Release()
{
	m_strSignedFilePayload.Release();	// This is the file contents we were wrapping. 
										// We can release this now.
	
//	m_strLocalDir.Release();			// We KEEP these, *not* release, because LoadContract()
//	m_strSignedFilename.Release();		// calls Release(), and these are our core values. We don't
										// want to lose them when the file is loaded.
	
	// Note: Additionally, neither does OTContract release m_strFilename here, for the SAME reason.
	
	m_strPurportedLocalDir.Release();	
	m_strPurportedFilename.Release();
	
	OTContract::Release();

	m_strContractType.Set("FILE");
}
	
	

bool OTSignedFile::SaveContractWallet(std::ofstream & ofs)
{
	return true;
}


















