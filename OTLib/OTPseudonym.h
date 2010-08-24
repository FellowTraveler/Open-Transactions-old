/************************************************************************************
 *    
 *  OTPseudonym.h
 *  
 *		Open Transactions:  Library, Protocol, Server, and Test Client
 *    
 *    			-- Anonymous Numbered Accounts
 *    			-- Untraceable Digital Cash
 *    			-- Triple-Signed Receipts
 *    			-- Basket Currencies
 *    			-- Signed XML Contracts
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
 *    	  If you would like to use this software outside of the free software
 *    	  license, please contact FellowTraveler.
 *   
 *        This library is also "dual-license", meaning that Ben Laurie's license
 *        must also be included and respected, since the code for Lucre is also
 *        included with Open Transactions.
 *        The Laurie requirements are light, but if there is any problem with his
 *        license, simply remove the Lucre code. Although there are no other blind
 *        token algorithms in Open Transactions (yet), the other functionality will
 *        continue to operate .
 *    
 *    OpenSSL WAIVER:
 *        This program is released under the AGPL with the additional exemption 
 *    	  that compiling, linking, and/or using OpenSSL is allowed.
 *    
 *    DISCLAIMER:
 *        This program is distributed in the hope that it will be useful,
 *        but WITHOUT ANY WARRANTY; without even the implied warranty of
 *        MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *        GNU Affero General Public License for more details.
 *    	
 ************************************************************************************/


#ifndef __OTPSEUDONYM_H__
#define __OTPSEUDONYM_H__

#include <cstdio>


#include <map>
#include <deque>
#include <string>

#include "OTString.h"
#include "OTData.h"
#include "OTIdentifier.h"

#include "OTASCIIArmor.h"
#include "OTAsymmetricKey.h"

/*
 
 I need to map transaction server ID, each for a pointer to deque of long.
 

 */

typedef std::map<std::string, long>	mapOfRequestNums;

typedef std::deque<long>							dequeOfTransNums;
typedef std::map<std::string, dequeOfTransNums *>	mapOfTransNums;

class OTPseudonym
{
private:
	OTString		m_strName;      // Used by the wallet so the nym is easily identified by the user
									// The internals, and server, prefer nymID to name.
	OTString		m_strNymfile;   // This contains the request numbers and other user acct info. XML.
									// Client-side only, since the server uses nymID for filenames
	OTString		m_strCertfile;  // Filename for pem file that contains the x509 Certificate. ----BEGIN etc...
									// Client-side only for now.

	OTString		m_strVersion;   // This goes with the Nymfile
	
	OTASCIIArmor	m_ascCert;		// Just the ascii-armor portion without BEGIN and END
	
	OTIdentifier	m_nymID;		// hashed public key
	
	OTAsymmetricKey m_keyPublic;	// This nym's public key
	OTAsymmetricKey m_keyPrivate;	// This nym's private key

	mapOfRequestNums m_mapRequestNum;	// Whenever this user makes a request to a transaction server
										// he must use the latest request number. Each user has a request
										// number for EACH transaction server he accesses.
	mapOfTransNums	m_mapTransNum;	// Each Transaction Request must be accompanied by a fresh transaction #,
									// one that has previously been issued to the Nym by the Server.
	
public:
	
	// OTPath is where all the subdirectories can be found.
	// On the client side, this is loaded in the wallet file.
	// But I don't have it in the wallet class because I need
	// it accessible all over the library, server, and client.
	// So I put it here instead.
	static OTString	OTPath;
	static OTString	OTPathSeparator;
	
	// ------------------------------------------------
	OTPseudonym();
	OTPseudonym(OTIdentifier & nymID);
	OTPseudonym(OTString & strNymID);
	OTPseudonym(OTString & name, OTString & filename, OTString & nymID);
	virtual ~OTPseudonym();
	
	void Initialize();
	void ReleaseTransactionNumbers();
	
	bool VerifyPseudonym() const;

	
	// This version WILL handle the bookends -----BEGIN PUBLIC KEY------ 
	bool SetPublicKey(const OTString & strKey, bool bEscaped=true);
	
	// This version WILL handle the bookends: -----BEGIN CERTIFICATE------ 
	// It also handles the escaped version:   - -----BEGIN CERTIFICATE-----
	bool SetCertificate(const OTString & strCert, bool bEscaped=true);
	
	// This will set the public key on this Nym 
	// based on the public key as it appears in an
	// ascii-armored string.
	bool SetPublicKey(const OTASCIIArmor & strKey);
	
	
	// The signer is whoever wanted to make sure these nym files haven't changed.
	// Usually that means the server nym.  Most of the time, m_nymServer will be used as signer.
	bool LoadSignedNymfile(OTPseudonym & SIGNER_NYM);
	bool SaveSignedNymfile(OTPseudonym & SIGNER_NYM);
	
	bool LoadNymfile(const char * szFilename=NULL);
	bool LoadFromString(const OTString & strNym);

	bool LoadPublicKey();
	bool Loadx509CertAndPrivateKey();
	
	bool SavePseudonymWallet(FILE * fl) const;

	bool SavePublicKey(const OTString & strPath) const;
	bool SavePublicKey(FILE * fl) const;

	bool SavePseudonym(); // saves to filename m_strNymfile
	bool SavePseudonym(const char * strPath);
	bool SavePseudonym(OTString & strNym);
	bool SavePseudonym(FILE * fl);

	void GetIdentifier(OTIdentifier & theIdentifier) const;
	void SetIdentifier(const OTIdentifier & theIdentifier);
	
	void GetIdentifier(OTString & theIdentifier) const;
	void SetIdentifier(const OTString & theIdentifier);
	
	void HarvestTransactionNumbers(OTPseudonym & SIGNER_NYM, OTPseudonym & theOtherNym); // OtherNym is used as container for server to send us new transaction numbers

	void IncrementRequestNum(OTPseudonym & SIGNER_NYM, const OTString & strServerID); // Increment the counter or create a new one for this serverID starting at 1
	void OnUpdateRequestNum(OTPseudonym & SIGNER_NYM, const OTString & strServerID, long lNewRequestNumber); // if the server sends us a @getRequest
	bool GetCurrentRequestNum(const OTString & strServerID, long &lReqNum); // get the current request number for the serverID

	inline mapOfTransNums & GetMapTransNum() { return m_mapTransNum; }
	bool AddTransactionNum(const OTString & strServerID, long lTransNum);
	bool AddTransactionNum(OTPseudonym & SIGNER_NYM, const OTString & strServerID, long lTransNum, bool bSave); // We have received a new trans num from server. Store it.
	bool GetNextTransactionNum(OTPseudonym & SIGNER_NYM, const OTString & strServerID, long &lTransNum); // Get the next available transaction number for the serverID

	bool VerifyTransactionNum(const OTString & strServerID, const long & lTransNum); // server verifies that nym was issued this TransNum
	bool RemoveTransactionNum(OTPseudonym & SIGNER_NYM, const OTString & strServerID, const long & lTransNum); // server removes spent number from nym file.

	const OTAsymmetricKey & GetPublicKey() const;
	const OTAsymmetricKey & GetPrivateKey() const;
	
	void DisplayStatistics(OTString & strOutput);
};

#endif // __OTPSEUDONYM_H__









































