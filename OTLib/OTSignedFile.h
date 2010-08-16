/************************************************************************************
 *    
 *  OTSignedFile.h
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

#ifndef __OT_SIGNED_FILE_H__
#define __OT_SIGNED_FILE_H__

#include "OTString.h"
#include "OTContract.h"


class OTSignedFile : public OTContract 
{	
protected:
	OTString		m_strSignedFilePayload;	// This class exists to wrap another and save it in signed form.
											// The "payload" (the wrapped contents) are stored in this member.
	
	OTString		m_strLocalDir;			// The local subdirectory where the file is, such as "nyms" or "certs"
	OTString		m_strSignedFilename;	// The file stores its own name. Later, when loading it back up, you can
											// see that the name matches internally, and that the signature matches,
											// therefore, no one has switched the file or meddled with its contents.

	OTString		m_strPurportedLocalDir;	// This is the subdirectory according to the file.
	OTString		m_strPurportedFilename;	// This is the filename according to the file.
	
	// THOUGHT: What if someone switched the file for an older version of itself? Seems to me that he could
	// make the server accept the file, in that case. Like maybe an account file with a higher balance?
	// Similarly, what if someone erased a spent token file? Then the software would accept it as a new
	// token once again. Also, the cash account would be deducted twice for the same token, which means it
	// would no longer contain enough to cover all the tokens...
	// Therefore it seems to me that, even with the files signed, there are still attacks possible when
	// the attacker has write/erase access to the filesystem. I'd like to make it impervious even to that.
	
	virtual int ProcessXMLNode(irr::io::IrrXMLReader*& xml);
	
public:
	
	// These assume SetFilename() was already called, or at least one of the constructors that uses it. 
	bool LoadFile();
	bool SaveFile();
	
	OTSignedFile();
	OTSignedFile(const OTString & LOCAL_SUBDIR, const OTString & FILE_NAME);
	OTSignedFile(const char * LOCAL_SUBDIR, const OTString & FILE_NAME);
	OTSignedFile(const char * LOCAL_SUBDIR, const char * FILE_NAME);
	virtual ~OTSignedFile();
	
	bool VerifyFile();	// Returns true or false, whether actual subdir/file matches purported subdir/file.
						// (You should still verify the signature on it as well, if you are doing this.)
	
	virtual void Release();
	virtual void UpdateContents(); 
	
	void SetFilename(const OTString & LOCAL_SUBDIR, const OTString & FILE_NAME);
	
	inline OTString & GetFilePayload() { return m_strSignedFilePayload; } 
	inline void SetFilePayload(const OTString &strArg) { m_strSignedFilePayload = strArg; }

	virtual bool SaveContractWallet(FILE * fl);
};

#endif // __OT_SIGNED_FILE_H__




















