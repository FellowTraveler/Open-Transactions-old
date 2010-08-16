/************************************************************************************
 *    
 *  OTSignedFile.cpp
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

#include "irlxml/irrXML.h"

using namespace irr;
using namespace io;

#include "OTSignedFile.h"
#include "OTPseudonym.h"



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
		// go to the next node and read the text.
		xml->read();
		
		if (EXN_TEXT == xml->getNodeType())
		{
			OTString strNodeData = xml->getNodeData();
			
			// Sometimes the XML reads up the data with a prepended newline.
			// This screws up my own objects which expect a consistent in/out
			// So I'm checking here for that prepended newline, and removing it.
			char cNewline;
			if (strNodeData.At(0, cNewline))
			{
				OTASCIIArmor ascNodeData;
				
				if ('\n' == cNewline)
				{
					ascNodeData.Set(strNodeData.Get() + 1);
					ascNodeData.GetString(m_strSignedFilePayload, true); // linebreaks = true
				}
				else
				{
					ascNodeData.Set(strNodeData.Get());
					ascNodeData.GetString(m_strSignedFilePayload, true); // linebreaks = true
				}
			}
		}
		else {
			fprintf(stderr, "Error in OTSignedFile::ProcessXMLNode: filePayload field without value.\n");
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
	OTString strTheFileName(m_strFilename);
	
	// OTContract doesn't natively make it easy to save a contract to its own filename.
	// Funny, I know, but OTContract is designed to save either to a specific filename,
	// or to a string parameter, or to the internal rawfile member. It doesn't normally
	// save to its own filename that was used to load it. But OTSignedFile is different...
	
	// This saves to a file, the name passed in as a char *.
	return SaveContract(strTheFileName.Get());
}

// Assumes SetFilename() has already been set.
bool OTSignedFile::LoadFile()
{
	return LoadContract();
}

void OTSignedFile::SetFilename(const OTString & LOCAL_SUBDIR, const OTString & FILE_NAME)
{
	m_strLocalDir		= LOCAL_SUBDIR;
	m_strSignedFilename	= FILE_NAME;
	
	m_strFilename.Format("%s%s" // transaction/
						 "%s%s" // nyms/
						 "%s",  // 5bf9a88c.nym
						 OTPseudonym::OTPath.Get(), OTPseudonym::OTPathSeparator.Get(),
						 m_strLocalDir.Get(), OTPseudonym::OTPathSeparator.Get(),
						 m_strSignedFilename.Get());
	
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
	
	
bool OTSignedFile::SaveContractWallet(FILE * fl)
{
	return true;
}


















