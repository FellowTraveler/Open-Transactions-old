/************************************************************************************
 *    
 *  OTMint.cpp
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
 *    
 *     ----------------------------------------------------------------
 *
 *    Open Transactions links to these libraries:
 *    
 *       OpenSSL        --- (Version 0.9.8l at time of writing.) 
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


#include "irlxml/irrXML.h"

using namespace irr;
using namespace io;


#include "bank.h"  // Lucre

#include "OTToken.h"
#include "OTMint.h"
#include "OTPseudonym.h"
#include "OTASCIIArmor.h"



void OTMint::InitMint()
{
	m_nDenominationCount = 0;
	
	m_bSavePrivateKeys = false; // Determines whether it serializes private keys (no if false)

}

void OTMint::ReleaseDenominations()
{
	while (!m_mapPublic.empty())
	{		
		OTASCIIArmor * pArmor = m_mapPublic.begin()->second;
		m_mapPublic.erase(m_mapPublic.begin());
		delete pArmor;
		pArmor = NULL;
	}
	while (!m_mapPrivate.empty())
	{		
		OTASCIIArmor * pArmor = m_mapPrivate.begin()->second;
		m_mapPrivate.erase(m_mapPrivate.begin());
		delete pArmor;
		pArmor = NULL;
	}
}

void OTMint::Release()
{
	ReleaseDenominations();
	
	InitMint();
}

OTMint::OTMint(const OTString & name, const OTString & filename, const OTString & strID)
 : OTContract(name, filename, strID)
{
	InitMint();
}

OTMint::OTMint() : OTContract()
{
	InitMint();
}


OTMint::~OTMint()
{
	Release();
}


// Make sure this contract checks out. Very high level. 
// Verifies ID and signature.
bool OTMint::VerifyMint(OTPseudonym & theOperator)
{
	// Make sure that the supposed Contract ID that was set is actually
	// a hash of the contract file, signatures and all.
	if (false == VerifyContractID())
	{
		fprintf(stderr, "Error comparing Mint ID to Asset Contract ID in OTMint::VerifyMint\n");
		return false;
	}
	else if (false == VerifySignature(theOperator))
	{
		fprintf(stderr, "Error verifying signature on mint in OTMint::VerifyMint.\n");
		return false;
	}
	
	fprintf(stderr, "\nWe now know that...\n"
			"1) The Asset Contract ID matches the Mint ID loaded from the Mint file.\n"
			"2) The SIGNATURE VERIFIED.\n\n");
	return true;
}



// Unlike other contracts, which calculate their ID from a hash of the file itself, a mint has
// the same ID as its Asset Contract.  When we open the Mint file, we read the Asset Type ID
// from it and then verify that it matches what we were expecting from the asset type.
bool OTMint::VerifyContractID()
{
	// I use the == operator here because there is no != operator at this time.
	// That's why you see the ! outside the parenthesis.
	if (!(m_ID == m_AssetID))
	{
		OTString str1(m_ID), str2(m_AssetID);
		
		fprintf(stderr, "\nMint ID does NOT match Asset Type ID in OTMint::VerifyContractID.\n%s\n%s\n"
				//				"\nRAW FILE:\n--->%s<---"
				"\n",
				str1.Get(), str2.Get()
				//				m_strRawFile.Get()
				);
		return false;
	}
	else {
		OTString str1(m_ID);
		fprintf(stderr, "\nMint ID *SUCCESSFUL* match to Asset Contract ID:\n%s\n\n", str1.Get());
		return true;
	}
}



// The mint has a different key pair for each denomination.
// Pass in the actual denomination such as 5, 10, 20, 50, 100...
bool OTMint::GetPrivate(OTASCIIArmor & theArmor, long lDenomination)
{
	OTASCIIArmor * pArmor = NULL;
	
	for (mapOfArmor::iterator ii = m_mapPrivate.begin(); ii != m_mapPrivate.end(); ++ii)
	{		
		if (pArmor = (*ii).second) // if pArmor not null
		{
			if ((*ii).first == lDenomination) // if this denomination (say, 50) matches the one passed in...
			{							   
				theArmor.Set(*pArmor);
				return true;
			}
		}
		else {
			fprintf(stderr, "NULL mint pointer in OTMint::GetPrivate.\n");
		}		
	}
	
	return false;	
}

// The mint has a different key pair for each denomination.
// Pass in the actual denomination such as 5, 10, 20, 50, 100...
bool OTMint::GetPublic(OTASCIIArmor & theArmor, long lDenomination)
{
	OTASCIIArmor * pArmor = NULL;
	
	for (mapOfArmor::iterator ii = m_mapPublic.begin(); ii != m_mapPublic.end(); ++ii)
	{		
		if (pArmor = (*ii).second) // if pArmor not null
		{
			if ((*ii).first == lDenomination) // if this denomination (say, 50) matches the one passed in...
			{							   
				theArmor.Set(*pArmor);
				return true;
			}
		}
		else {
			fprintf(stderr, "NULL mint pointer in OTMint::GetPublic.\n");
		}		
	}
	
	return false;
}


// If you need to withdraw a specific amount, pass it in here and the
// mint will return the largest denomination that is equal to or smaller
// than the amount.
// Then you can subtract the denomination from the amount and call this method
// again, and again, until it reaches 0, in order to create all the necessary
// tokens to reach the full withdrawal amount.
long OTMint::GetLargestDenomination(long lAmount)
{
	for (int nIndex = GetDenominationCount()-1; nIndex >= 0; nIndex--)
	{
		long lDenom = GetDenomination(nIndex);
		
		if (lDenom <= lAmount)
			return lDenom;
	}
	
	return 0;
}


// If you call GetDenominationCount, you can then use this method
// to look up a denomination by index.
// You could also iterate through them by index.
long OTMint::GetDenomination(int nIndex)
{
	// index out of bounds.
	if (nIndex > (m_nDenominationCount-1))
	{
		return 0;
	}
	
	int				nIterateIndex	= 0;
	OTASCIIArmor *	pArmor			= NULL;
	
	for (mapOfArmor::iterator ii = m_mapPublic.begin(); ii != m_mapPublic.end(); ++ii, nIterateIndex++)
	{		
		if (pArmor = (*ii).second) // if pArmor not null
		{
			if (nIndex == nIterateIndex)
				return (*ii).first;
		}
		else {
			fprintf(stderr, "NULL mint pointer in OTMint::GetDenomination.\n");
		}		
	}
	
	return 0;
}



// The mint has a different key pair for each denomination.
// Pass the actual denomination such as 5, 10, 20, 50, 100...
bool OTMint::AddDenomination(OTPseudonym & theNotary, long lDenomination, int nPrimeLength/*=1024*/)
{
	bool bReturnValue = false;
	
	// Let's make sure it doesn't already exist
	OTASCIIArmor theArmor;
	if (GetPublic(theArmor, lDenomination))
	{
		// it already exists.
		fprintf(stderr, "Error: Denomination public already exists in OTMint::AddDenomination\n");
		return false;
	}
	if (GetPrivate(theArmor, lDenomination))
	{
		// it already exists.
		fprintf(stderr, "Error: Denomination private already exists in OTMint::AddDenomination\n");
		return false;
	}
	
	//		fprintf(stderr,"%s <size of bank prime in bits> <bank data file> <bank public data file>\n",
	
    if ((nPrimeLength/8) < (MIN_COIN_LENGTH+DIGEST_LENGTH))
	{
		fprintf(stderr,"Prime must be at least %d bits\n",
				(MIN_COIN_LENGTH+DIGEST_LENGTH)*8);
		return false;
	}
	
    if (nPrimeLength%8)
	{
		fprintf(stderr,"Prime length must be a multiple of 8\n");
		return false;
	}
	
    SetMonitor(stderr);
	
    BIO *bio		=	BIO_new(BIO_s_mem());
    BIO *bioPublic	=	BIO_new(BIO_s_mem());
	
	// Generate the mint private key information
    Bank bank(nPrimeLength/8);
    bank.WriteBIO(bio);
	
	// Generate the mint public key information
    PublicBank pbank(bank);
    pbank.WriteBIO(bioPublic);	
	
	// Copy from BIO back to a normal OTString or Ascii-Armor  
	char privateBankBuffer[4096], publicBankBuffer[4096];   // todo stop hardcoding these string lengths
	int privatebankLen	= BIO_read(bio, privateBankBuffer, 4000); // cutting it a little short on purpose, with the buffer. Just makes me feel more comfortable for some reason.
	int publicbankLen	= BIO_read(bioPublic, publicBankBuffer, 4000); 
	
	if (privatebankLen && publicbankLen)
	{
		// With this, we have the Lucre public and private bank info converted to OTStrings
		OTString strPublicBank;		strPublicBank.Set(publicBankBuffer, publicbankLen);
		OTString strPrivateBank;	strPrivateBank.Set(privateBankBuffer, privatebankLen);
		
		OTASCIIArmor * pPublic	= new OTASCIIArmor();
		OTASCIIArmor * pPrivate	= new OTASCIIArmor();
		
		// Set the public bank info onto pPublic
		pPublic->SetString(strPublicBank, true); // linebreaks = true
		
		// Seal the private bank info up into an encrypted Envelope 
		// and set it onto pPrivate
		OTEnvelope theEnvelope;
		theEnvelope.Seal(theNotary, strPrivateBank);	// Todo check the return values on these two functions
		theEnvelope.GetAsciiArmoredData(*pPrivate);
		
		// Add the new key pair to the maps, using denomination as the key
		m_mapPublic[lDenomination]	= pPublic;
		m_mapPrivate[lDenomination]	= pPrivate;
		
		// Grab the Server ID and save it with this Mint
		theNotary.GetIdentifier(m_ServerID);
		
		// Grab the Server's public key and save it with this Mint
		// OTAsymmetricKey op= only copies the public key, FYI.
		m_keyPublic = theNotary.GetPublicKey();
		
		m_nDenominationCount++;
		
		// Success!
		bReturnValue = true;
	}
	
	// Release OpenSSL resources.
    BIO_free_all(bio);		// note: this WAS bio_free. I changed it to free_all. In case there is trouble later...
    BIO_free_all(bioPublic);
	
	return bReturnValue;
}


// The default behavior of this function does NOT save the private keys. It only
// serializes the public keys, and it is safe to send the object to the client.
// If the server needs to save the private keys, then call SetSavePrivateKeys() first.
void OTMint::UpdateContents()
{
	OTString SERVER_ID(m_ServerID), ASSET_ID(m_AssetID);
		
	// I release this because I'm about to repopulate it.
	m_xmlUnsigned.Release();
	
	m_xmlUnsigned.Concatenate("<?xml version=\"%s\"?>\n\n", "1.0");		
	
	m_xmlUnsigned.Concatenate("<mint version=\"%s\"\n serverID=\"%s\"\n assetTypeID=\"%s\" >\n\n", 
							  m_strVersion.Get(), SERVER_ID.Get(), ASSET_ID.Get());		
	
	OTASCIIArmor	armorPublicKey;
	m_keyPublic.GetPublicKey(armorPublicKey);
	m_xmlUnsigned.Concatenate("<mintPublicKey>\n%s</mintPublicKey>\n\n", armorPublicKey.Get());
	
	if (m_nDenominationCount)
	{
		OTASCIIArmor * pArmor = NULL;
		if (m_bSavePrivateKeys)
		{
			m_bSavePrivateKeys = false;  // reset this back to false again. Use SetSavePrivateKeys() to set it true.
			for (mapOfArmor::iterator ii = m_mapPrivate.begin(); ii != m_mapPrivate.end(); ++ii)
			{		
				if (pArmor = (*ii).second) // if pArmor not null
				{
					m_xmlUnsigned.Concatenate("<mintPrivateInfo denomination=\"%ld\">\n"
											  "%s</mintPrivateInfo>\n\n", 
											  (*ii).first, pArmor->Get());
				}
				else {
					fprintf(stderr, "NULL private mint pointer in OTMint::UpdateContents.\n");
				}		
			}
		}
		for (mapOfArmor::iterator ii = m_mapPublic.begin(); ii != m_mapPublic.end(); ++ii)
		{		
			if (pArmor = (*ii).second) // if pArmor not null
			{
				m_xmlUnsigned.Concatenate("<mintPublicInfo denomination=\"%ld\">\n"
										  "%s</mintPublicInfo>\n\n", 
										  (*ii).first, pArmor->Get());
			}
			else {
				fprintf(stderr, "NULL public mint pointer in OTMint::UpdateContents.\n");
			}		
		}
	}
	
	m_xmlUnsigned.Concatenate("</mint>\n");			
}



// return -1 if error, 0 if nothing, and 1 if the node was processed.
int OTMint::ProcessXMLNode(IrrXMLReader*& xml)
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
	
	if (!strcmp("mint", xml->getNodeName())) 
	{
		OTString strServerID, strAssetID;
		
		m_strVersion	= xml->getAttributeValue("version");					
		strServerID		= xml->getAttributeValue("serverID");
		strAssetID		= xml->getAttributeValue("assetTypeID");
		
		m_ServerID.SetString(strServerID);
		m_AssetID.SetString(strAssetID);
				
		fprintf(stderr, 
				//	"\n===> Loading XML for mint into memory structures..."
				"\n\nMint version: %s\n Server ID: %s\n Asset Type ID: %s\n", 
				m_strVersion.Get(), strServerID.Get(), strAssetID.Get());
		
		nReturnVal = 1;
	}
	
	
	else if (!strcmp("mintPublicKey", xml->getNodeName())) 
	{
		// go to the next node and read the text.
		xml->read();
		
		if (EXN_TEXT == xml->getNodeType())
		{
			OTASCIIArmor armorPublicKey;
			OTString strNodeData = xml->getNodeData();
			
			// Sometimes the XML reads up the data with a prepended newline.
			// This screws up my own objects which expect a consistent in/out
			// So I'm checking here for that prepended newline, and removing it.
			char cNewline;
			if (strNodeData.At(0, cNewline))
			{
				if ('\n' == cNewline)
					armorPublicKey.Set(strNodeData.Get() + 1); // the +1 puts us past the damned prepended newline 
				else
					armorPublicKey.Set(strNodeData);  // else the data was fine so grab it as-is
			}
						
			m_keyPublic.SetPublicKey(armorPublicKey); // todo check this for failure.
		}
		else {
			fprintf(stderr, "Error in OTToken::ProcessXMLNode: mintPublicKey without value.\n");
			return (-1); // error condition
		}
		
		return 1;
	}

	else if (!strcmp("mintPrivateInfo", xml->getNodeName())) 
	{
		long lDenomination = atol(xml->getAttributeValue("denomination"));					

		// go to the next node and read the text.
		xml->read();
		
		if (EXN_TEXT == xml->getNodeType())
		{
			OTASCIIArmor * pArmor = new OTASCIIArmor();
			OTString strNodeData = xml->getNodeData();

			// Sometimes the XML reads up the data with a prepended newline.
			// This screws up my own objects which expect a consistent in/out
			// So I'm checking here for that prepended newline, and removing it.
			char cNewline;
			if (strNodeData.At(0, cNewline))
			{
				if ('\n' == cNewline)
					pArmor->Set(strNodeData.Get() + 1); // the +1 puts us past the damned prepended newline 
				else
					pArmor->Set(strNodeData);  // else the data was fine so grab it as-is
			}
			
			m_mapPrivate[lDenomination] = pArmor;
		}
		else {
			fprintf(stderr, "Error in OTToken::ProcessXMLNode: mintPrivateInfo without value.\n");
			return (-1); // error condition
		}
		
		return 1;
	}
	
	else if (!strcmp("mintPublicInfo", xml->getNodeName())) 
	{
		long lDenomination = atol(xml->getAttributeValue("denomination"));					

		// go to the next node and read the text.
		xml->read();
		
		if (EXN_TEXT == xml->getNodeType())
		{
			OTASCIIArmor * pArmor = new OTASCIIArmor();
			OTString strNodeData = xml->getNodeData();
			
			// Sometimes the XML reads up the data with a prepended newline.
			// This screws up my own objects which expect a consistent in/out
			// So I'm checking here for that prepended newline, and removing it.
			char cNewline;
			if (strNodeData.At(0, cNewline))
			{
				if ('\n' == cNewline)
					pArmor->Set(strNodeData.Get() + 1); // the +1 puts us past the damned prepended newline 
				else
					pArmor->Set(strNodeData);  // else the data was fine so grab it as-is
			}
			
			m_mapPublic[lDenomination] = pArmor;
			m_nDenominationCount++; // Whether client or server, both sides have public. Each public denomination should increment this count.
		}
		else {
			fprintf(stderr, "Error in OTToken::ProcessXMLNode: mintPublicInfo without value.\n");
			return (-1); // error condition
		}
		
		return 1;
	}
	
	
	return nReturnVal;
}





/*
 
 enum tokenState {
 blankToken,
 protoToken,
 signedToken,
 spendableToken,
 verifiedToken,
 errorToken
 };
 
 
 Create a memory BIO and write some data to it:
 
 BIO *mem = BIO_new(BIO_s_mem());
 BIO_puts(mem, "Hello World\n");
 
 
 Create a read only memory BIO:
 
 char data[] = "Hello World";
 BIO *mem;
 mem = BIO_new_mem_buf(data, -1);
 
 
 Extract the BUF_MEM structure from a memory BIO and then free up the BIO:
 
 BUF_MEM *bptr;
 BIO_get_mem_ptr(mem, &bptr);
 BIO_set_close(mem, BIO_NOCLOSE); // So BIO_free() leaves BUF_MEM alone
 BIO_free(mem);

 */




// Lucre step 3: the mint signs the token
// 
bool OTMint::SignToken(OTPseudonym & theNotary, OTToken & theToken, OTString & theOutput, int nTokenIndex)
{
	bool bReturnValue = false;
	
	//fprintf(stderr,"%s <bank file> <coin request> <coin signature> [<signature repeats>]\n",
	SetDumper(stderr);
	
//	fprintf(stderr, "OTMint::SignToken!!\nnTokenIndex: %d\n Denomination: %ld\n", nTokenIndex, theToken.GetDenomination());
	
    BIO *bioBank		= BIO_new(BIO_s_mem()); // input
    BIO *bioRequest		= BIO_new(BIO_s_mem()); // input
    BIO *bioSignature	= BIO_new(BIO_s_mem()); // output
	
	OTASCIIArmor thePrivate;
	GetPrivate(thePrivate, theToken.GetDenomination());
	
	// The Mint private info is encrypted in m_mapPrivates[theToken.GetDenomination()]. 
	// So I need to extract that first before I can use it.
	OTEnvelope theEnvelope(thePrivate);

	OTString strContents; // output from opening the envelope.
	// Decrypt the Envelope into strContents    
	if (!theEnvelope.Open(theNotary, strContents))
		return false;

	// copy strContents to a BIO
	BIO_puts(bioBank, strContents.Get());
	
//	fprintf(stderr, "BANK CONTENTS:\n%s--------------------------------------\n", strContents.Get());
	
	// Instantiate the Bank with its private key
    Bank bank(bioBank);
//	fprintf(stderr, "BANK INSTANTIATED.--------------------------------------\n");

	// I need the request. the prototoken.
	OTASCIIArmor ascPrototoken;
	bool bFoundToken = theToken.GetPrototoken(ascPrototoken, nTokenIndex);
	
	if (bFoundToken)
	{
		// base64-Decode the prototoken
		OTString strPrototoken(ascPrototoken);
		
//		fprintf(stderr, "\n--------------------------------------\nDEBUG:  PROTOTOKEN CONTENTS:\n"
//				"-----------------%s---------------------\n", strPrototoken.Get() );
		
		// copy strPrototoken to a BIO
		BIO_puts(bioRequest, strPrototoken.Get());

		// Load up the coin request from the bio (the prototoken)
		PublicCoinRequest req(bioRequest);
//		fprintf(stderr, "PROTOTOKEN INSTANTIATED.--------------------------------------\n");

		// Sign it with the bank we previously instantiated.
		// results will be in bnSignature (BIGNUM)
		BIGNUM * bnSignature = bank.SignRequest(req);

		if (NULL == bnSignature)
		{
			fprintf(stderr, "MAJOR ERROR!: Bank.SignRequest failed in OTMint::SignToken\n");
		}
		
		else 
		{
//			fprintf(stderr, "BANK.SIGNREQUEST SUCCESSFUL.--------------------------------------\n");

			// Write the request contents, followed by the signature contents,
			// to the Signature bio. Then free the BIGNUM.
			req.WriteBIO(bioSignature); // the original request contents
			DumpNumber(bioSignature,"signature=", bnSignature); // the new signature contents
			BN_free(bnSignature);

			// Read the signature bio into a C-style buffer...
			char sig_buf[1024];   // todo stop hardcoding these string lengths
//			memset(sig_buf, 0, 2048); // zero it out.
			
			int sig_len	= BIO_read(bioSignature, sig_buf, 1000); // cutting it a little short on purpose, with the buffer. Just makes me feel more comfortable for some reason.
			
			
			// Add the null terminator by hand (just in case.)
			sig_buf[sig_len]	= '\0';
			
			int sig_str_len = strlen(sig_buf);

			if (sig_len)
			{ // ***********************************************
//				fprintf(stderr, "\n--------------------------------------\n"
//						"*** Siglen is %d. sig_str_len is %d.\nsig buf:\n------------%s------------\nLAST "
//						"CHARACTER IS '%c'  SECOND TO LAST CHARACTER IS '%c'\n", 
//						sig_len, sig_str_len, sig_buf, sig_buf[sig_str_len-1], sig_buf[sig_str_len-2]);
				
				// Copy the original coin request into the spendable field of the token object.
				// (It won't actually be spendable until the client processes it, though.)
				theToken.SetSpendable(ascPrototoken);
				
//				fprintf(stderr, "*** SPENDABLE:\n-----------%s---------------------\n", ascPrototoken.Get());
						
						
				// Base64-encode the signature contents into theToken.m_Signature.
				OTString	strSignature(sig_buf);
	//			strSignature.Set(sig_buf, sig_len-1); // sig_len includes null terminator, whereas Set() adds 1 for it.
				
//				fprintf(stderr, "SIGNATURE:\n--------------------%s"
//						"------------------\n", strSignature.Get());

				// Here we pass the signature back to the caller.
				// He will probably set it onto the token.
				theOutput.Set(sig_buf, sig_len);
				bReturnValue = true;
			}
		}
	}

	BIO_free_all(bioBank);		
    BIO_free_all(bioRequest);	
    BIO_free_all(bioSignature);	
	
	return bReturnValue;
}

// Lucre step 5: mint verifies token when it is redeemed by merchant.
// This function is called by OTToken::VerifyToken.
// That's the one you should be calling, most likely, not this one.
bool OTMint::VerifyToken(OTPseudonym & theNotary, OTString & theCleartextToken, long lDenomination)
{
	bool bReturnValue = false;
	//fprintf(stderr,"%s <bank info> <coin>\n",argv[0]);
    SetDumper(stderr);
	
	BIO *bioBank	= BIO_new(BIO_s_mem()); // input
	BIO *bioCoin	= BIO_new(BIO_s_mem()); // input
	
	// --- copy theCleartextToken to bioCoin so lucre can load it
	BIO_puts(bioCoin, theCleartextToken.Get());
		
	// --- The Mint private info is encrypted in m_mapPrivate[lDenomination]. 
	// So I need to extract that first before I can use it.
	OTASCIIArmor theArmor;
	GetPrivate(theArmor, lDenomination);
	OTEnvelope theEnvelope(theArmor);
	
	OTString strContents; // will contain output from opening the envelope.
	// Decrypt the Envelope into strContents    
	if (theEnvelope.Open(theNotary, strContents))
	{
		// copy strContents to a BIO
		BIO_puts(bioBank, strContents.Get());
		
		// ---- Now the bank and coin bios are both ready to go... 
		
		Bank bank(bioBank);
		Coin coin(bioCoin);
		
		if (bank.Verify(coin))  // Here's the boolean output: coin is verified!
		{
			bReturnValue = true;
			
			// BIG TODO: When a token is redeemed, need to store it in the spent token database.
			// Right now I can verify the token, but unless I check it against a database, then 
			// even though the signature verifies, it doesn't stop people from redeeming the same
			// token again and again and again.
			//
			// note to self: also need to make sure issuer has double-entries for total amount outstanding.
		}
	}
	
	// Cleanup openssl resources.
	BIO_free_all(bioBank);	
	BIO_free_all(bioCoin);	
	
	return bReturnValue;
}

// Lucre step 1: generate new mint
// Make sure the issuer here has a private key
// theMint.GenerateNewMint(ASSET_ID, m_nymServer, 1, 5, 10, 20, 50, 100, 500, 1000, 10000, 100000);
void OTMint::GenerateNewMint(const OTIdentifier & theAssetID, OTPseudonym & theNotary, 
							 long nDenom1, long nDenom2, long nDenom3, long nDenom4, long nDenom5,
							 long nDenom6, long nDenom7, long nDenom8, long nDenom9, long nDenom10)
{
	Release();
	
	m_AssetID = theAssetID;
	
	if (nDenom1)
	{
		AddDenomination(theNotary, nDenom1); // int nPrimeLength default = 1024
	}
	if (nDenom2)
	{
		AddDenomination(theNotary, nDenom2); // int nPrimeLength default = 1024
	}
	if (nDenom3)
	{
		AddDenomination(theNotary, nDenom3); // int nPrimeLength default = 1024
	}
	if (nDenom4)
	{
		AddDenomination(theNotary, nDenom4); // int nPrimeLength default = 1024
	}
	if (nDenom5)
	{
		AddDenomination(theNotary, nDenom5); // int nPrimeLength default = 1024
	}
	if (nDenom6)
	{
		AddDenomination(theNotary, nDenom6); // int nPrimeLength default = 1024
	}
	if (nDenom7)
	{
		AddDenomination(theNotary, nDenom7); // int nPrimeLength default = 1024
	}
	if (nDenom8)
	{
		AddDenomination(theNotary, nDenom8); // int nPrimeLength default = 1024
	}
	if (nDenom9)
	{
		AddDenomination(theNotary, nDenom9); // int nPrimeLength default = 1024
	}
	if (nDenom10)
	{
		AddDenomination(theNotary, nDenom10); // int nPrimeLength default = 1024
	}
}



bool OTMint::SaveContractWallet(FILE * fl)
{
	return true;
}

