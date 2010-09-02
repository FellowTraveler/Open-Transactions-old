/************************************************************************************
 *    
 *  OTPseudonym.cpp
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



extern "C"
{
#include <openssl/sha.h>
}

#include "cstdio"	
#include "cstring"	

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>
#include <algorithm>
#include <cassert>

#include "irlxml/irrXML.h"

using namespace irr;
using namespace io;

#include "OTString.h"
#include "OTStringXML.h"
#include "OTIdentifier.h"
#include "OTAsymmetricKey.h"

#include "OTASCIIArmor.h"
#include "OTPseudonym.h"
#include "OTSignedFile.h"

/*
typedef std::deque<long>							dequeOfTransNums;
typedef std::map<std::string, dequeOfTransNums *>	mapOfTransNums;	
*/


// ---------------------------------------------------------------------------------
// This is the "global" path to the subdirectories. The wallet file is probably also there.
OTString OTPseudonym::OTPath("."); // it defaults to '.' but then it is set by the client and server.

// All my paths now use the global path above, and are constructed using
// the path separator below. So the filesystem aspect of Open Transactions
// should be a LOT more portable to Windows, though I haven't actually tried
// it on Windows.
#ifdef _WIN32
OTString OTPseudonym::OTPathSeparator("\\");
#else
OTString OTPseudonym::OTPathSeparator("/");
#endif

// ---------------------------------------------------------------------------------


// On the server side: A user has submitted a specific transaction number. 
// Verify whether he actually has a right to use it.
bool OTPseudonym::VerifyTransactionNum(const OTString & strServerID, const long & lTransNum)
{
	std::string strID	= strServerID.Get();
	
	// The Pseudonym has a deque of transaction numbers for each servers.
	// These deques are mapped by Server ID.
	// 
	// So let's loop through all the deques I have, and if the server ID on the map
	// matches the Server ID that was passed in, then find the transaction number on
	// that list, and then return true. Else return false.
	for (mapOfTransNums::iterator ii = m_mapTransNum.begin();  ii != m_mapTransNum.end(); ++ii)
	{
		// if the ServerID passed in matches the serverID for the current deque
		if ( strID == ii->first )
		{
			dequeOfTransNums * pDeque = (ii->second);
			
			if (pDeque && !(pDeque->empty())) // there are some numbers for that server ID
			{
				// Let's loop through them and see if the culprit is there
				for (int i = 0; i < pDeque->size(); i++)
				{
					// Found it!
					if (lTransNum == pDeque->at(i))
					{
						return true;
					}
				}
			}
			break;			
		}
	}
	
	return false;	
}

// On the server side: A user has submitted a specific transaction number. 
// Remove it from his file so he can't use it again.
bool OTPseudonym::RemoveTransactionNum(OTPseudonym & SIGNER_NYM, const OTString & strServerID, const long & lTransNum)
{
	bool bRetVal = false;
	std::string strID	= strServerID.Get();
	
	// The Pseudonym has a deque of transaction numbers for each servers.
	// These deques are mapped by Server ID.
	// 
	// So let's loop through all the deques I have, and if the server ID on the map
	// matches the Server ID that was passed in, then find the transaction number on
	// that list, and then remove it, and return true. Else return false.
	for (mapOfTransNums::iterator ii = m_mapTransNum.begin();  ii != m_mapTransNum.end(); ++ii)
	{
		// if the ServerID passed in matches the serverID for the current deque
		if ( strID == ii->first )
		{
			dequeOfTransNums * pDeque = (ii->second);
			
			if (pDeque && !(pDeque->empty())) // there are some numbers for that server ID
			{
				// Let's loop through them and see if the culprit is there
				for (int i = 0; i < pDeque->size(); i++)
				{
					// Found it!
					if (lTransNum == pDeque->at(i))
					{
						pDeque->erase(pDeque->begin() + i);
						bRetVal = true;
						break;
					}
				}
			}
			break;			
		}
	}
	
	if (bRetVal)
	{
		SaveSignedNymfile(SIGNER_NYM);
	}
	
	return bRetVal;
}


// No signer needed for this one, and save is false.
// This version is ONLY for cases where we're not saving inside this function.
bool OTPseudonym::AddTransactionNum(const OTString & strServerID, long lTransNum) 
{
	bool bSuccessFindingServerID = false, bSuccess = false;
	std::string strID	= strServerID.Get();
	
	// The Pseudonym has a deque of transaction numbers for each server.
	// These deques are mapped by Server ID.
	// 
	// So let's loop through all the deques I have, and if the server ID on the map
	// matches the Server ID that was passed in, then send out the transaction  number.
	for (mapOfTransNums::iterator ii = m_mapTransNum.begin();  ii != m_mapTransNum.end(); ++ii)
	{
		// if the ServerID passed in matches the serverID for the current deque
		if ( strID == ii->first )
		{
			dequeOfTransNums * pDeque = (ii->second);
			
			if (pDeque)
			{
				pDeque->push_front(lTransNum);
				bSuccess = true;
			}
			bSuccessFindingServerID = true;
			break;			
		}
	}
	
	// Apparently there is not yet a deque stored for this specific serverID.
	// Fine. Let's create it then, and then add the transaction num to that new deque.
	if (!bSuccessFindingServerID)
	{
		dequeOfTransNums * pDeque = new dequeOfTransNums;
		
		if (pDeque)
		{
			m_mapTransNum[strID] = pDeque;
			pDeque->push_front(lTransNum);
			bSuccess = true;
		}
	}

	return bSuccess;	
}


// Client side: We have received a new trans num from server. Store it.
// Now the server uses this too, for storing these numbers so it can verify them later.
bool OTPseudonym::AddTransactionNum(OTPseudonym & SIGNER_NYM, const OTString & strServerID, long lTransNum, bool bSave) 
{
	bool bSuccess = AddTransactionNum(strServerID, lTransNum);
	
	if (bSuccess && bSave)
	{
		SaveSignedNymfile(SIGNER_NYM);
	}	
	
	return bSuccess;
}


// Client side.
// Get the next available transaction number for the serverID
// The lTransNum parameter is for the return value.
bool OTPseudonym::GetNextTransactionNum(OTPseudonym & SIGNER_NYM, const OTString & strServerID, long &lTransNum)
{
	bool bRetVal		= false;
	std::string strID	= strServerID.Get();
	
	// The Pseudonym has a deque of transaction numbers for each servers.
	// These deques are mapped by Server ID.
	// 
	// So let's loop through all the deques I have, and if the server ID on the map
	// matches the Server ID that was passed in, then send out the transaction  number.
	for (mapOfTransNums::iterator ii = m_mapTransNum.begin();  ii != m_mapTransNum.end(); ++ii)
	{
		// if the ServerID passed in matches the serverID for the current deque
		if ( strID == ii->first )
		{
			dequeOfTransNums * pDeque = (ii->second);
			
			if (pDeque && !(pDeque->empty()))
			{
				lTransNum = pDeque->front();
				
				pDeque->pop_front();
				
				// The call has succeeded
				bRetVal = true;
			}
			break;			
		}
	}
	
	if (bRetVal)
	{
		SaveSignedNymfile(SIGNER_NYM);
	}
	
	return bRetVal;
}




void OTPseudonym::ReleaseTransactionNumbers()
{
	while (!m_mapTransNum.empty())
	{		
		dequeOfTransNums * pDeque = m_mapTransNum.begin()->second;
		m_mapTransNum.erase(m_mapTransNum.begin());
		delete pDeque;
		pDeque = NULL;
	}	
}


// returns true on success, value goes into lReqNum
// Make sure the Nym is LOADED before you call this,
// otherwise it won't be there to get.
// and if the request number needs to be incremented,
// then make sure you call IncrementRequestNum (below)
bool OTPseudonym::GetCurrentRequestNum(const OTString & strServerID, long &lReqNum)
{		
	bool bRetVal		= false;
	std::string strID	= strServerID.Get();
	
	// The Pseudonym has a map of the request numbers for different servers.
	// For Server Bob, with this Pseudonym, I might be on number 34.
	// For but Server Alice, I might be on number 59.
	// 
	// So let's loop through all the numbers I have, and if the server ID on the map
	// matches the Server ID that was passed in, then send out the request number.
	for (mapOfRequestNums::iterator ii = m_mapRequestNum.begin();  ii != m_mapRequestNum.end(); ++ii)
	{
		if ( strID == ii->first )
		{
			// Setup return value.
			lReqNum = (ii->second);
			
			// The call has succeeded
			bRetVal = true;
			
			break;
		}
	}
	
	return bRetVal;
}
	
// Make SURE you call SavePseudonym after you call this.
// Otherwise it will increment in memory but not in the file.
// In fact, I cannot allow that. I will call SavePseudonym myself.
// Therefore, make SURE you fully LOAD this Pseudonym before you save it.
// You don't want to overwrite what's in that file.
// THEREFORE we need a better database than the filesystem.
// I will research a good, free, secure database (or encrypt everything
// before storing it there) and soon these "load/save" commands will use that
// instead of the filesystem.
void OTPseudonym::IncrementRequestNum(OTPseudonym & SIGNER_NYM, const OTString & strServerID)
{
	bool bSuccess = false;

	// The Pseudonym has a map of the request numbers for different servers.
	// For Server Bob, with this Pseudonym, I might be on number 34.
	// For but Server Alice, I might be on number 59.
	// 
	// So let's loop through all the numbers I have, and if the server ID on the map
	// matches the Server ID that was passed in, then send out the request number and
	// increment it so it will be ready for the next request.
	//
	// Make sure to save the Pseudonym so the new request number is saved.
	std::string strID	= strServerID.Get();
	for (mapOfRequestNums::iterator ii = m_mapRequestNum.begin();  ii != m_mapRequestNum.end(); ++ii)
	{
		if ( strID == ii->first )
		{
			// We found it!
			// Presumably we ONLY found it because this Nym has been properly loaded first.
			// Good job! Otherwise, the list would have been empty even though the request number
			// was sitting in the file.
			
			
			// Grab a copy of the old request number
			long lOldRequestNumber = m_mapRequestNum[ii->first];
			
			// Set the new request number to the old one plus one.
			m_mapRequestNum[ii->first] = lOldRequestNumber + 1;
			
			// Now we can log BOTH, before and after... // debug here
			fprintf(stderr, "Incremented Request Number from %ld to %ld. Saving...\n", 
					lOldRequestNumber, m_mapRequestNum[ii->first]);
			//			fprintf(stderr, "DEBUG REQUESTNUM: first: %s   Second: %ld\n", ii->first.c_str(), ii->second);
			//			fprintf(stderr, "SAVING PSEUDONYM TO FILE: %s\n", m_strNymfile.Get());

			// The call has succeeded
			bSuccess = true;
			break;
		}
	}
	
	// If I didn't find it in the list above (whether the list is empty or not....)
	// that means it does not exist. So create it.
	
	if (!bSuccess)
	{
		fprintf(stderr, "Creating Request Number entry as '1'. Saving...\n");
		m_mapRequestNum[strServerID.Get()] = 1;
		bSuccess = true;
	}
	
	
	if (bSuccess)
	{
		SaveSignedNymfile(SIGNER_NYM);
	}
}

void OTPseudonym::DisplayStatistics(OTString & strOutput)
{
	OTString strTemp;
	
	strOutput.Concatenate("\nPSEUDONYM(s):\n\n");
	
	strTemp.Format("Name: %s\n", m_strName.Get());			strOutput.Concatenate(strTemp);
	strTemp.Format("Version: %s\n\n", m_strVersion.Get());	strOutput.Concatenate(strTemp);
	
	OTString theStringID;
	GetIdentifier(theStringID);
	strTemp.Format("ID: %s\n", theStringID.Get());			strOutput.Concatenate(strTemp);
	strTemp.Format("Nymfile: %s\n", m_strNymfile.Get());	strOutput.Concatenate(strTemp);	
	strTemp.Format("Certfile: %s\n\n", m_strCertfile.Get());	strOutput.Concatenate(strTemp);
	
	for (mapOfRequestNums::iterator ii = m_mapRequestNum.begin();  ii != m_mapRequestNum.end(); ++ii)
	{
		std::string strServerID	= ii->first;
		long lRequestNumber		= ii->second;
		
		// Now we can log BOTH, before and after...
		strTemp.Format("Request Number is %ld for server ID: %s\n", 
				lRequestNumber, strServerID.c_str());
		strOutput.Concatenate(strTemp);
	}
	
	for (mapOfTransNums::iterator iii = m_mapTransNum.begin(); iii != m_mapTransNum.end(); ++iii)
	{	
		std::string strServerID		= (*iii).first;
		dequeOfTransNums * pDeque	= (iii->second);
		
		if (pDeque && !(pDeque->empty()))
		{
			for (int i = 0; i < pDeque->size(); i++)
			{
				long lTransactionNumber = pDeque->at(i);
				
				strTemp.Format("Transaction Number available (%ld) for server ID: %s\n", 
							   lTransactionNumber, strServerID.c_str());
				strOutput.Concatenate(strTemp);
			}
		}
	} // for
	
}

// if the server sends us a @getRequest
void OTPseudonym::OnUpdateRequestNum(OTPseudonym & SIGNER_NYM, const OTString & strServerID, long lNewRequestNumber)
{
	bool bSuccess = false;
	
	// The Pseudonym has a map of the request numbers for different servers.
	// For Server Bob, with this Pseudonym, I might be on number 34.
	// For but Server Alice, I might be on number 59.
	// 
	// So let's loop through all the numbers I have, and if the server ID on the map
	// matches the Server ID that was passed in, then send out the request number and
	// increment it so it will be ready for the next request.
	//
	// Make sure to save the Pseudonym so the new request number is saved.
	std::string strID	= strServerID.Get();
	for (mapOfRequestNums::iterator ii = m_mapRequestNum.begin();  ii != m_mapRequestNum.end(); ++ii)
	{
		if ( strID == ii->first )
		{
			// We found it!
			// Presumably we ONLY found it because this Nym has been properly loaded first.
			// Good job! Otherwise, the list would have been empty even though the request number
			// was sitting in the file.
			
			// The call has succeeded
			bSuccess = true;
			
			// Grab a copy of the old request number
			long lOldRequestNumber = m_mapRequestNum[ii->first];
			
			// Set the new request number to the old one plus one.
			m_mapRequestNum[ii->first] = lNewRequestNumber;
			
			// Now we can log BOTH, before and after...
			fprintf(stderr, "Updated Request Number from %ld to %ld. Saving...\n", 
					lOldRequestNumber, m_mapRequestNum[ii->first]);
			//			fprintf(stderr, "DEBUG REQUESTNUM: first: %s   Second: %ld\n", ii->first.c_str(), ii->second);
			//			fprintf(stderr, "SAVING PSEUDONYM TO FILE: %s\n", m_strNymfile.Get());
			break;
		}
	}
	
	// If I didn't find it in the list above (whether the list is empty or not....)
	// that means it does not exist. So create it.
	
	if (!bSuccess)
	{
		fprintf(stderr, "Creating Request Number entry as '%ld'. Saving...\n", lNewRequestNumber);
		m_mapRequestNum[strServerID.Get()] = lNewRequestNumber;
		bSuccess = true;
	}
	
	
	if (bSuccess)
	{
		SaveSignedNymfile(SIGNER_NYM);
	}
	
}



/*
bool OTPseudonym::VerifyPseudonym()
{
	OTData binCert; // Here's where we'll put the decoded binary content.
	
	// m_ascCert should already contain the ascii-armored text from the 
	// Nym's x509 certificate file. (this happened in LoadPseudonym())
	
	// This function decodes the base64 text into binary OTData...
	bool bSuccessfulDecode = m_ascCert.GetData(binCert); 
	
	if (!bSuccessfulDecode)
	{
		fprintf(stderr, "Error decoding Certificate!\n");
		return false;
	}
	
	// Next we get a Message Digest of that binary Cert...
	OTIdentifier newID;
	
	bool bSuccessCalculateDigest = newID.CalculateDigest(binCert);
	
	if (!bSuccessCalculateDigest)
	{
		fprintf(stderr, "Error calculating Certificate digest.\n");
		return false;	
	}
	
	// newID now contains the Hash aka Message Digest aka Fingerprint aka "IDENTIFIER" 
	// of the x.509 certificate (in its binary form). 
	// (Maybe later we'll choose to hash the text form instead.)
	// 
	// Now let's compare that identifier to the one already loaded by the wallet
	// and make sure they MATCH.
	
	if (!(m_nymID == newID))
	{
		OTString str1, str2;
		m_nymID.GetString(str1);
		newID.GetString(str2);
		fprintf(stderr, "Hashes do NOT match in OTPseudonym::VerifyPseudonym!\n%s\n%s\n",
				str1.Get(), str2.Get());
		return false;
	}
	else {
		fprintf(stderr, "\nNymID from wallet *SUCCESSFUL* match to "
				"sha256 hash of the Cert.\n"
				"---------------------------------------------------------------\n");
		return true;
	}
}
*/
/*
bool OTPseudonym::GetPublicKey(OTData & thePublicKey)
{
	
}
*/

/*
 // Save this code. It may be possible to send the entire file
 // to the library and just have it processed there. This code
 // reads the file and then we can pass it to such a library.
bool OTPseudonym::LoadPseudonym()
{	
	OTString & filename = m_strFilename;
	
	std::ifstream in(filename.Get());
	
	std::stringstream buffer;
	buffer << in.rdbuf();
	
	std::string contents(buffer.str());

	m_strCertFileContents = contents.c_str();
	
	fprintf(stderr, "Loaded x.509 Certificate:\n%s\n", m_strCertFileContents.Get());
	
	return true;
}
*/



/*
 <pseudonym name="REDACTED" 
 nymID="0094e344f6f437c55458873218b14651c4f0ecc88fc7b714fa3b98a83fdf8767"
 file="client.pem" />  <!-- ascii-armored x509 certificate -->
 
 <assetType name="Chuck-E-Cheese Tokens" 
 assetTypeID="65e6ecf1a72300dcb41a908246be1b53465e7edc9b14d90656ba845d71ef94b5" 
 contract="test.xml" />
 
 <transactionServer 
 name="transactions.com" 
 serverID="0535d64305fd10ee104bb79a994c5c58e833a1af664a939a49b1fa4a0445d590" 
 contract="transactionscom.xml" />
 
 <assetAccount name="LD Chuck-E-Cheese token side acct" 
 file="LD-side.xml" 
 AccountID="df9834lkjs5jf8" />
 
 <assetAccount name="LD Main Acct" 
 file="LD-main.xml" 
 AccountID="af9834lkjs5jf6" />
 
 <assetAccount name="Kacey Shopping Acct" 
 file="Kacey-main.xml" 
 AccountID="bw9834lkjs5jf6" />
 */



bool OTPseudonym::VerifyPseudonym() const
{
	OTString strPublicKey;
	bool bGotPublicKey = GetPublicKey().GetPublicKey(strPublicKey);
	
	if (!bGotPublicKey)
	{
		fprintf(stderr, "Error getting public key in OTPseudonym::VerifyPseudonym.\n");
		return false;	
	}
	
	
	OTIdentifier newID;
	bool bSuccessCalculateDigest = newID.CalculateDigest(strPublicKey);
	
	if (!bSuccessCalculateDigest)
	{
		fprintf(stderr, "Error calculating Certificate digest.\n");
		return false;	
	}
	
	
	// newID now contains the Hash aka Message Digest aka Fingerprint aka "IDENTIFIER" 
	// of the public key (in its text form, with escaped bookends.)
	// 
	// Now let's compare that identifier to the one already loaded by the wallet
	// and make sure they MATCH.
	
	if (!(m_nymID == newID))
	{
		OTString str1(m_nymID), str2(newID);
		fprintf(stderr, "\nHashes do NOT match in OTPseudonym::VerifyPseudonym!\n%s\n%s\n",
				str1.Get(), str2.Get());
		return false;
	}
	else {
//		OTString str2(newID);
//		fprintf(stderr, "\nNymID from wallet *SUCCESSFUL* match to hash of Nym\'s public key:\n%s\n"
//				"---------------------------------------------------------------\n", str2.Get());
		return true;
	}
}


bool OTPseudonym::SavePseudonymWallet(FILE * fl) const
{
	if (NULL != fl)
	{
		OTString nymID;
		GetIdentifier(nymID);
		
		fprintf(fl, "<pseudonym name=\"%s\"\n"
				" nymID=\"%s\"\n"
				" file=\"%s\""
				">\n\n",
				m_strName.Get(), nymID.Get(), m_strNymfile.Get());
	}
	else {
		return false;
	}
	
	return true;
}


// -----------------------------------------------------


//
// This function saves the public key to a file.
//
bool OTPseudonym::SavePublicKey(const OTString & strPath) const
{
#ifdef _WIN32
	FILE * fl = NULL;
	errno_t err = fopen_s(&fl, strPath.Get(), "wb");
#else
	FILE * fl  = fopen(strPath.Get(), "w");
#endif
	bool bSave = false;
	
	if (NULL != fl)
	{
		bSave = SavePublicKey(fl);
		fclose(fl);
	}
	else {
		return false;
	}
	
	return bSave;
}


bool OTPseudonym::SavePublicKey(FILE * fl) const
{
	if (NULL != fl)
	{
		// By passing in an OTString instead of OTASCIIArmor, it knows to add the bookends
		// ----- BEGIN PUBLIC KEY  etc.  These bookends are necessary for OTASCIIArmor to later
		// read the thing back up into memory again.
		OTString strKey;
		
		if (GetPublicKey().GetPublicKey(strKey, false)) // false means "do not ESCAPE the bookends"
			// Ie we'll get ----------- instead of - ---------
		{
			strKey.WriteToFile(fl);
		}
		else {
			fprintf(stderr, "Error in OTPseudonym::SavePublicKey: unable to GetPublicKey from Nym\n");
			return false;
		}
	}
	else {
		return false;
	}
	
	return true;
}






// This version is run on the server side, and assumes only a Public Key.
// This code reads up the file, discards the bookends, and saves only the gibberish itself.
bool OTPseudonym::LoadPublicKey()
{
	OTString strID, strPubKeyFile;
	
	GetIdentifier(strID);
	
	strPubKeyFile.Format("%s%spubkeys%s%s", OTPseudonym::OTPath.Get(), OTPseudonym::OTPathSeparator.Get(),
						 OTPseudonym::OTPathSeparator.Get(), strID.Get());
	
	// This loads up the ascii-armored Public Key.
	// On the client side, the entire x509 is stored.
	// On the server side, it's just the public key. 
	bool bLoadKeyFile = m_ascCert.LoadFromFile(strPubKeyFile);

	// If successful, I load the same file again, but this time using OpenSSL
	if (bLoadKeyFile)
	{
		// Unlike above, where I'm merely reading a text file into a memory buffer,
		// this time we are actually trying to use OpenSSL to really extract the
		// public key from that same file.
		OTAsymmetricKey & pubKey = (OTAsymmetricKey &)GetPublicKey();
		
		bool bLoadPublicKey = pubKey.LoadPublicKey(strPubKeyFile);
		
		if (!bLoadPublicKey)
		{
			fprintf(stderr, "Although the ascii-armored file (%s) was read, LoadPublicKey "
					"returned false.\n", strPubKeyFile.Get());
			return false;
		}
		else
		{
//			fprintf(stderr, "Successfully loaded public key from file: %s\n", strPubKeyFile.Get());
		}		
		return true;	
	}
	else
	{
		fprintf(stderr, "Failure in OTPseudonym::LoadPublicKey.\n");
		return false;
	}
}




bool OTPseudonym::SavePseudonym() 
{
	if (!m_strNymfile.GetLength())
	{
		OTString nymID;
		GetIdentifier(nymID);
		m_strNymfile.Format("%s%snyms%s%s", OTPseudonym::OTPath.Get(), OTPseudonym::OTPathSeparator.Get(),
							OTPseudonym::OTPathSeparator.Get(), nymID.Get());
	}
	
	fprintf(stderr, "Saving nym to: %s\n", m_strNymfile.Get());
	
	return SavePseudonym(m_strNymfile.Get());
}

bool OTPseudonym::SavePseudonym(const char * strPath)
{	
	if (NULL == strPath)
		return false;
	
#ifdef _WIN32
	FILE * fl = NULL;
	errno_t err = fopen_s(&fl, strPath, "wb");
#else
	FILE * fl  = fopen(strPath, "w");
#endif
	bool bSave = false;
	
	if (NULL != fl)
	{
		bSave = SavePseudonym(fl);
		fclose(fl);
	}
	else {
		fprintf(stderr, "Error saving nym to: %s\n", strPath);
		bSave = false;
	}
	
	return bSave;	
}


bool OTPseudonym::SavePseudonym(FILE * fl)
{
	if (NULL != fl)
	{
		OTString strNym;
		SavePseudonym(strNym);
		
		fprintf(fl, "%s", strNym.Get());	
	}
	else {
		fprintf(stderr, "Null file pointer sent to OTPseudonym::SavePseudonym. (Why?)\n");
		return false;
	}
	
	return true;
}


// Save the Pseudonym to a string...
bool OTPseudonym::SavePseudonym(OTString & strNym)
{
	OTString nymID;
	GetIdentifier(nymID);
	
	strNym.Concatenate("<?xml version=\"%s\"?>\n\n", "1.0");	
	
	strNym.Concatenate("<OTuser version=\"%s\"\n"
			" nymID=\"%s\""
			">\n\n", 
			m_strVersion.Get(), 
			nymID.Get()
			);
	
	std::string	strServerID;
	long		lRequestNum;
	
	for (mapOfRequestNums::iterator ii = m_mapRequestNum.begin(); ii != m_mapRequestNum.end(); ++ii)
	{	
		strServerID = (*ii).first;
		lRequestNum = (*ii).second;
		
		strNym.Concatenate("<requestNum\n"
				" serverID=\"%s\"\n"
				" currentRequestNum=\"%ld\""
				"/>\n\n", 
				strServerID.c_str(),
				lRequestNum
				);
	}
	
	long lTransactionNumber;
	
	for (mapOfTransNums::iterator iii = m_mapTransNum.begin(); iii != m_mapTransNum.end(); ++iii)
	{	
		strServerID					= (*iii).first;
		dequeOfTransNums * pDeque	= (iii->second);
		
		if (pDeque && !(pDeque->empty()))
		{
			for (int i = 0; i < pDeque->size(); i++)
			{
				lTransactionNumber = pDeque->at(i);
				
				strNym.Concatenate("<transactionNum\n"
						" serverID=\"%s\"\n"
						" transactionNum=\"%ld\""
						"/>\n\n", 
						strServerID.c_str(),
						lTransactionNumber
						);
			}
		}
	} // for
	
	strNym.Concatenate("</OTuser>\n");	
	
	return true;
	
}

// OtherNym is used as container for server to send us new transaction numbers
void OTPseudonym::HarvestTransactionNumbers(OTPseudonym & SIGNER_NYM, OTPseudonym & theOtherNym)
{
	bool bSuccess = false;
	std::string	strServerID;
	long lTransactionNumber = 0;

	for (mapOfTransNums::iterator	iii	 =	theOtherNym.GetMapTransNum().begin(); 
									iii !=	theOtherNym.GetMapTransNum().end(); ++iii)
	{	
		strServerID					= (*iii).first;
		dequeOfTransNums * pDeque	= (iii->second);
		
		OTString OTstrServerID = strServerID.c_str();

		if (pDeque && !(pDeque->empty()))
		{
			for (int i = 0; i < pDeque->size(); i++)
			{
				lTransactionNumber = pDeque->at(i);
				
				AddTransactionNum(SIGNER_NYM, OTstrServerID, lTransactionNumber, false); // bSave = false (but saved below...)
				
				bSuccess = true;
			}
		}
	} // for

	if (bSuccess)
	{
		SaveSignedNymfile(SIGNER_NYM);
	}
}


bool OTPseudonym::LoadFromString(const OTString & strNym)
{
	bool bSuccess = false;

	OTStringXML strNymXML(strNym);
	IrrXMLReader* xml = createIrrXMLReader(&strNymXML);

	// parse the file until end reached
	while(xml && xml->read())
	{
		// strings for storing the data that we want to read out of the file
		OTString UserNymID;
		
		OTString ReqNumServerID;
		OTString ReqNumCurrent;
		
		OTString TransNumServerID;
		OTString TransNumAvailable;
		
		switch(xml->getNodeType())
		{
			case EXN_TEXT:
				// in this xml file, the only text which occurs is the messageText
				//messageText = xml->getNodeData();
				break;
			case EXN_ELEMENT:
			{
				if (!strcmp("OTuser", xml->getNodeName()))
				{
					m_strVersion	= xml->getAttributeValue("version");					
					UserNymID		= xml->getAttributeValue("nymID");	
					
					//TODO: no need to set the ID again here. We already know the ID
					// at this point. Better to check and compare they are the same here.
					//m_nymID.SetString(UserNymID);
					//
					
					if (UserNymID.GetLength())
						fprintf(stderr, "\nLoading user, version: %s NymID:\n%s\n", m_strVersion.Get(), UserNymID.Get());
					bSuccess = true;
				}
				else if (!strcmp("requestNum", xml->getNodeName()))
				{
					ReqNumServerID = xml->getAttributeValue("serverID");				
					ReqNumCurrent = xml->getAttributeValue("currentRequestNum");
					
					fprintf(stderr, "\nCurrent Request Number is %s for ServerID: %s\n",
							ReqNumCurrent.Get(), ReqNumServerID.Get());
					
					// Make sure now that I've loaded this request number, to add it to my
					// internal map so that it is available for future lookups.
					m_mapRequestNum[ReqNumServerID.Get()] = atol(ReqNumCurrent.Get());
				}
				else if (!strcmp("transactionNum", xml->getNodeName()))
				{
					TransNumServerID	= xml->getAttributeValue("serverID");				
					TransNumAvailable	= xml->getAttributeValue("transactionNum");
					
					fprintf(stderr, "\nTransaction Number %s available for ServerID: %s\n",
							TransNumAvailable.Get(), TransNumServerID.Get());
					
					AddTransactionNum(TransNumServerID, atol(TransNumAvailable.Get())); // This version doesn't save to disk. Why save to disk AS WE'RE LOADING? 
				}
				else
				{
					// unknown element type
					fprintf(stderr, "unknown element type in OTPseudonym::LoadNymfile: %s\n", xml->getNodeName());
					bSuccess = false;
				}
			}
				break;
		} // switch
	} // while
	
	// delete the xml parser after usage
	if (xml)
		delete xml;
	
	
	return bSuccess;
}




bool OTPseudonym::LoadSignedNymfile(OTPseudonym & SIGNER_NYM)
{
	// Get the Nym's ID in string form
	OTString nymID;
	GetIdentifier(nymID);
	
	// Create an OTSignedFile object, giving it the filename (the ID) and the local directory ("nyms")
	OTSignedFile	theNymfile("nyms", nymID);
	
	// We verify:
	//
	// 1. That the file even exists and loads.
	// 2. That the local subdir and filename match the versions inside the file.
	// 3. That the signature matches for the signer nym who was passed in.
	//
	if (theNymfile.LoadFile()  
		&& theNymfile.VerifyFile() 
		&& theNymfile.VerifySignature(SIGNER_NYM) 
		)
	{
		if (theNymfile.GetFilePayload().GetLength())
			return LoadFromString(theNymfile.GetFilePayload());
	}
	
	return false;
}

bool OTPseudonym::SaveSignedNymfile(OTPseudonym & SIGNER_NYM)
{
	// Get the Nym's ID in string form
	OTString nymID;
	GetIdentifier(nymID);

	// Create an OTSignedFile object, giving it the filename (the ID) and the local directory ("nyms")
	OTSignedFile	theNymfile("nyms", nymID);
	theNymfile.GetFilename(m_strNymfile);
	
	fprintf(stderr, "Saving nym to: %s\n", m_strNymfile.Get());
	
	// First we save this nym to a string...
	// Specifically, the file payload string on the OTSignedFile object.
	SavePseudonym(theNymfile.GetFilePayload());

	// Now the OTSignedFile contains the path, the filename, AND the
	// contents of the Nym itself, saved to a string inside the OTSignedFile object.
	
	if (theNymfile.SignContract(SIGNER_NYM) && 
		theNymfile.SaveContract())
	{
		return theNymfile.SaveFile();
	}
	
	return false;
}





// Each Nym has a public key file, as well as a nym file. Why two separate files?
// Because they are often used for different purposes and are being loaded/saved 
// for their own reasons. The Nymfile contains the user ID, which is a hash of the
// public key, so the it knows how to find the right pubkey file (filename is the
// hash) and it knows how to validate the contents (by hashing them.) The Nymfile
// also contains the transaction numbers that have been issued to that nym, so 
// the server might later load it up in order to verify that a specific transaction
// number is indeed on that list (and then remove it from the list.)
bool OTPseudonym::LoadNymfile(const char * szFilename/*=NULL*/)
{
	// If no filename was passed in (user might have designated one) then we create
	// the filename by appending the Nym's ID to the path.
	if (NULL == szFilename)
	{
		OTString strID;
		GetIdentifier(strID);
		m_strNymfile.Format((char *)"%s%snyms%s%s", OTPseudonym::OTPath.Get(), OTPseudonym::OTPathSeparator.Get(),
							OTPseudonym::OTPathSeparator.Get(), strID.Get());
	}
	else {
		m_strNymfile = szFilename;
	}

	
	std::ifstream in(m_strNymfile.Get());
	
	std::stringstream buffer;
	buffer << in.rdbuf();
	
	std::string contents(buffer.str());
	
	OTString strRawFile = contents.c_str();
	
	if (strRawFile.GetLength())
		return LoadFromString(strRawFile);
		
	return false;
}


bool OTPseudonym::Loadx509CertAndPrivateKey()
{
	OTString strID;
	GetIdentifier(strID);
	m_strCertfile.Format((char *)"%s%scerts%s%s", OTPseudonym::OTPath.Get(), OTPseudonym::OTPathSeparator.Get(),
						 OTPseudonym::OTPathSeparator.Get(), strID.Get());
	
	// This loads up the ascii-armored Cert from the certfile, minus the ------ bookends.
	// Later we will use this to create a hash and verify against the NymID that was in the wallet.
	bool bRetVal = m_ascCert.LoadFromFile(m_strCertfile);
	
	// I load the same file again, but this time using OpenSSL functions to read the public
	// key and private key (if necessary) from the same file.
	if (bRetVal)
	{
		bool bPublic  = false;
		bool bPrivate = false;
		
		bPublic  = m_keyPublic.LoadPublicKeyFromCertFile(m_strCertfile);
		bPrivate = m_keyPrivate.LoadPrivateKey(m_strCertfile);
		//		bPrivate = true;
		
		if (!bPublic)
		{
			fprintf(stderr, "Although the ascii-armored file (%s) was read, LoadPublicKeyFromCert "
					"returned false.\n", m_strCertfile.Get());
			return false;
		}
		else
		{
			fprintf(stderr, "Successfully loaded public key from Certfile: %s\n", m_strCertfile.Get());
		}
		
		
		if (!bPrivate)
		{
			fprintf(stderr, "Although the ascii-armored file (%s) was read, LoadPrivateKey returned false.\n",
					m_strCertfile.Get());
			return false;
		}
		else
		{
			fprintf(stderr, "Successfully loaded private key from: %s\n", m_strCertfile.Get());
		}
		
		return true;	
	}
	else
	{
		fprintf(stderr, "Failure in OTPseudonym::Loadx509CertAndPrivateKey, filename:\n%s\n", m_strCertfile.Get());
		return false;
	}
}





// This version WILL handle the bookends: -----BEGIN CERTIFICATE------ 
// It will also handle the escaped version: - -----BEGIN CERTIFICATE-----
bool OTPseudonym::SetCertificate(const OTString & strCert, bool bEscaped/*=true*/)
{
	return m_keyPublic.LoadPublicKeyFromCertString(strCert, bEscaped);
}


// This version WILL handle the bookends -----BEGIN PUBLIC KEY------ 
// It will also handle the escaped version: - -----BEGIN PUBLIC KEY------
bool OTPseudonym::SetPublicKey(const OTString & strKey, bool bEscaped/*=true*/)
{	
	if (strKey.Contains("PGP PUBLIC KEY"))
	{
		OTASCIIArmor theArmor;
		
		if (theArmor.LoadFromString((OTString &)strKey, bEscaped))
		{
			// This function expects that the bookends are already removed.
			// The ascii-armor loading code removes them and handles the escapes also.
			return m_keyPublic.LoadPublicKeyFromPGPKey(theArmor);
		}
		else {
			fprintf(stderr, "Error extracting PGP public key from ascii-armored text.\n");
			return false;
		}
	}
	else // the below function SetPublicKey (in the return call) expects the
		 // bookends to still be there, and it will handle removing them. (Unlike PGP code above.)
		return m_keyPublic.SetPublicKey(strKey, bEscaped);
}




// This version handles the ascii-armored text WITHOUT the bookends
bool OTPseudonym::SetPublicKey(const OTASCIIArmor & strKey)
{
	return m_keyPublic.SetPublicKey(strKey);
}


// sets internal member based in ID passed in
void OTPseudonym::SetIdentifier(const OTIdentifier & theIdentifier)
{
	m_nymID = theIdentifier;
}

// sets argument based on internal member
void OTPseudonym::GetIdentifier(OTIdentifier & theIdentifier) const
{
	theIdentifier = m_nymID;
}

// sets internal member based in ID passed in
void OTPseudonym::SetIdentifier(const OTString & theIdentifier)
{
	m_nymID.SetString(theIdentifier);
}

// sets argument based on internal member
void OTPseudonym::GetIdentifier(OTString & theIdentifier) const
{	
	m_nymID.GetString(theIdentifier);
}


const OTAsymmetricKey & OTPseudonym::GetPublicKey() const
{
	return m_keyPublic;
}

const OTAsymmetricKey & OTPseudonym::GetPrivateKey() const
{
	return m_keyPrivate;
}



OTPseudonym::OTPseudonym()
{
	Initialize();
}

void OTPseudonym::Initialize()
{
	m_strVersion = "1.0";
}

OTPseudonym::OTPseudonym(OTString & name, OTString & filename, OTString & nymID)
{
	Initialize();
	
	m_strName		= name;
	m_strNymfile	= filename;
	
	m_nymID.SetString(nymID);
}

OTPseudonym::OTPseudonym(OTIdentifier & nymID)
{
	Initialize();
	
	m_nymID = nymID;
}

OTPseudonym::OTPseudonym(OTString & strNymID)
{
	Initialize();
	
	m_nymID.SetString(strNymID);
}

OTPseudonym::~OTPseudonym()
{
	ReleaseTransactionNumbers();
}




















