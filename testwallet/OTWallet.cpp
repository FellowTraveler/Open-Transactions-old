/************************************************************************************
 *    
 *  OTWallet.cpp
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
#include "stdio.h"	
#include "string.h"	
}

#include "OTWallet.h"

#include "OTString.h"
#include "OTAssetContract.h"
#include "OTServerContract.h"
#include "OTContract.h"
#include "OTAccount.h"
#include "OTPseudonym.h"
#include "OTEnvelope.h"
#include "OTPurse.h"

#include "irlxml/irrXML.h"

using namespace irr;
using namespace io;


// TODO remove this pTemporaryNym variable, used for testing only.
OTPseudonym			* g_pTemporaryNym = NULL; 
OTAssetContract		* g_pTemporaryContract = NULL;
OTServerContract	* g_pServerContract = NULL;


OTWallet::OTWallet() : m_Connection(*this)
{
	m_pWithdrawalPurse = NULL;
}

OTWallet::~OTWallet()
{
	//TODO:
	//1) Go through the map of Nyms and delete them. (They were dynamically allocated.)
	//2) Go through the map of Contracts and delete them. (They were dynamically allocated.)
	//3) Go through the map of Servers and delete them. (They were dynamically allocated.)
	//4) Go through the map of Accounts and delete them. (They were dynamically allocated.)
}



// While waiting on server response to a withdrawal, we keep the private coin
// data here so we can unblind the response.
// This information is so important (as important as the digital cash token
// itself, until the unblinding is done) that we need to save the file right away.
void OTWallet::AddPendingWithdrawal(const OTPurse & thePurse)
{
	// TODO maintain a list here (I don't know why, the server response is nearly
	// instant and then it's done.)
	
	// TODO notice I don't check the pointer here to see if it's already set, I 
	// just start using it.. Fix that.
	m_pWithdrawalPurse = (OTPurse *)&thePurse;
}

void OTWallet::RemovePendingWithdrawal()
{
	if (m_pWithdrawalPurse)
		delete m_pWithdrawalPurse;
	
	m_pWithdrawalPurse = NULL;
}





bool OTWallet::SignContractWithFirstNymOnList(OTContract & theContract)
{
	if (g_pTemporaryNym)
	{
		theContract.SignContract(*g_pTemporaryNym);
		return true;
	}

	return false;
}


// used for testing.
// Once the wallet is loaded, we are assuming there is at least one server
// contract in the wallet, and we are asking the wallet to look it up,
// find the hostname and port inside that contract, and establish a connection
// to the server.
//
// Whereas in a nice user interface, you would loop through all the servers in 
// the wallet and display them in a nice list on the screen, and the user could
// just click on one, and you would just call Wallet.Connect(ServerID) and do your thing.
bool OTWallet::ConnectToTheFirstServerOnList()
{
	if (g_pTemporaryNym && g_pServerContract)
	{
		return m_Connection.Connect(*g_pTemporaryNym, *g_pServerContract);
	}
	
	return false;
}


void OTWallet::DisplayStatistics(OTString & strOutput)
{
	strOutput.Concatenate("WALLET STATISTICS:\n");
	
	OTPseudonym * pNym = NULL;
	
	for (mapOfNyms::iterator ii = m_mapNyms.begin(); ii != m_mapNyms.end(); ++ii)
	{		
		if (pNym = (*ii).second)
		{
			pNym->DisplayStatistics(strOutput);
		}
		else {
			fprintf(stderr, "NULL pseudonym pointer in OTWallet::m_mapNyms, OTWallet::DisplayStatistics.");
		}		
	}
	
	// ---------------------------------------------------------------
	
	/*
	OTContract * pContract = NULL;
	
	for (mapOfContracts::iterator ii = m_mapContracts.begin(); ii != m_mapContracts.end(); ++ii)
	{
		if (pContract = (*ii).second)
		{
			pContract->SaveContractWallet(fl);
			
			// ----------------------------------------
		}
		else 
		{
			fprintf(stderr, "NULL contract pointer in OTWallet::m_mapContracts, OTWallet::SaveWallet: %s",
					szFilename);
		}
	}
	
	// ---------------------------------------------------------------
	
	OTContract * pServer = NULL;
	
	for (mapOfServers::iterator ii = m_mapServers.begin(); ii != m_mapServers.end(); ++ii)
	{
		if (pServer = (*ii).second)
		{
			pServer->SaveContractWallet(fl);
			
			// ----------------------------------------
		}
		else {
			fprintf(stderr, "NULL server pointer in OTWallet::m_mapServers, OTWallet::SaveWallet: %s",
					szFilename);
		}
	}
	
	// ---------------------------------------------------------------
	 */

	strOutput.Concatenate("\n-------------------------------------------------\n");
	strOutput.Concatenate("ACCOUNTS:\n\n");
	
	OTContract * pAccount = NULL;
	
	for (mapOfAccounts::iterator ii = m_mapAccounts.begin(); ii != m_mapAccounts.end(); ++ii)
	{
		if (pAccount = (*ii).second)
		{
			OTString strContents;
			pAccount->SaveContents(strContents);
			
			strOutput.Concatenate(strContents);
			strOutput.Concatenate("-------------------------------------------------\n");
			// ----------------------------------------
		}
		else {
			fprintf(stderr, "NULL account pointer in OTWallet::m_mapAccounts, OTWallet::DisplayStatistics");
		}
	}
	
	// ---------------------------------------------------------------
	
	
}


int OTWallet::SaveWallet(const char * szFilename)
{	
	if (NULL == szFilename)
	{
		fprintf(stderr, "Null filename sent to OTWallet::SaveWallet\n");
		return 0;
	}
	
	FILE * fl = fopen(szFilename, "w");
	
	if (NULL == fl)
	{
		fprintf(stderr, "Error opening file in OTWallet::SaveWallet: %s\n", szFilename);
		return 0;
	}
	
	// ---------------------------------------------------------------
	
	fprintf(fl, "<?xml version=\"1.0\"?>\n<wallet name=\"%s\" version=\"%s\">\n\n",
			m_strName.Get(), m_strVersion.Get());
	
	//mapOfNyms			m_mapNyms;		// So far no file writing for these (and none needed...)
	//mapOfContracts	m_mapContracts; // This is what I'm testing now, which includes the other 3.
	//mapOfServers		m_mapServers;
	//mapOfAccounts		m_mapAccounts; 

	OTPseudonym * pNym = NULL;
	
	for (mapOfNyms::iterator ii = m_mapNyms.begin(); ii != m_mapNyms.end(); ++ii)
	{		
		if (pNym = (*ii).second)
		{
			pNym->SavePseudonymWallet(fl);
		}
		else {
			fprintf(stderr, "NULL pseudonym pointer in OTWallet::m_mapNyms, OTWallet::SaveWallet: %s",
					szFilename);
		}		
	}

	// ---------------------------------------------------------------

	OTContract * pContract = NULL;
	
	for (mapOfContracts::iterator ii = m_mapContracts.begin(); ii != m_mapContracts.end(); ++ii)
	{
		if (pContract = (*ii).second)
		{
			pContract->SaveContractWallet(fl);

			//TODO remove this test code---------------
			// Used for putting new signatures on contracts
/*
			{
				// Right now it's configured to sign with USER public key, not server.
//				OTString strNewFile, strIdentifier("1"); // This is where I've got the server Nym
				OTString strNewFile;
				pContract->GetFilename(strNewFile);
				strNewFile.Concatenate("NEW");
			
//				OTPseudonym theSigningNym;
//				theSigningNym.SetIdentifier(strIdentifier);
				
//				if (theSigningNym.Loadx509CertAndPrivateKey()) // with ID 1 in the certs folder.
				if (g_pTemporaryNym)
					pContract->SignContract(*g_pTemporaryNym);						

				//TODO remove this test code.
				pContract->SaveContract(strNewFile.Get());
			}
*/
			// ----------------------------------------
		}
		else 
		{
			fprintf(stderr, "NULL contract pointer in OTWallet::m_mapContracts, OTWallet::SaveWallet: %s",
					szFilename);
		}
	}
	
	// ---------------------------------------------------------------
	
	OTContract * pServer = NULL;
	
	for (mapOfServers::iterator ii = m_mapServers.begin(); ii != m_mapServers.end(); ++ii)
	{
		if (pServer = (*ii).second)
		{
			pServer->SaveContractWallet(fl);
			/*
			//TODO remove this test code---------------
			// Used for putting new signatures on contracts
		
			{
				OTString strNewFile, strIdentifier("1");
				pServer->GetFilename(strNewFile);
				strNewFile.Concatenate("NEW");
				
				OTPseudonym theSigningNym;
				theSigningNym.SetIdentifier(strIdentifier);
				
				if (theSigningNym.Loadx509CertAndPrivateKey()) // with ID 1 in the certs folder
					pServer->SignContract(theSigningNym);						
				
				//TODO remove this test code.
				pServer->SaveContract(strNewFile.Get());
			}
			*/
			// ----------------------------------------
		}
		else {
			fprintf(stderr, "NULL server pointer in OTWallet::m_mapServers, OTWallet::SaveWallet: %s",
					szFilename);
		}
	}
	
	// ---------------------------------------------------------------
	
	OTContract * pAccount = NULL;
	
	for (mapOfAccounts::iterator ii = m_mapAccounts.begin(); ii != m_mapAccounts.end(); ++ii)
	{
		if (pAccount = (*ii).second)
		{
			pAccount->SaveContractWallet(fl);

			//TODO remove this test code
			/*
			OTString strNewFile;
			pAccount->GetFilename(strNewFile);
			strNewFile.Concatenate("NEW");
			
			// The others, I merely save them.
			// But the accounts, I must sign them first.
			// Only when the account is signed, is the signed portion
			// updated to match the new account balance and date.
			if (g_pTemporaryNym)
			{
				if (!pAccount->SignContract(*g_pTemporaryNym))
				{
					fprintf(stderr, "Error signing account in OTWallet::SaveWallet\n");
				}
			}
			
			pAccount->SaveContract(strNewFile.Get());
			*/
			// ----------------------------------------
		}
		else {
			fprintf(stderr, "NULL account pointer in OTWallet::m_mapAccounts, OTWallet::SaveWallet: %s",
					szFilename);
		}
	}
	
	// ---------------------------------------------------------------
	
	fprintf(fl, "</wallet>\n");
		
	fclose(fl);
	
	return 1;
}



void OTWallet::AddAccount(OTAccount & theAcct)
{
	const OTIdentifier	ACCOUNT_ID(theAcct);
	
	// See if there is already an account object on this wallet with the same ID
	// (Otherwise if we don't delete it, this would be a memory leak.)
	// Should use a smart pointer.
	OTAccount * pAccount = NULL;
	OTIdentifier anAccountID;
	
	for (mapOfAccounts::iterator ii = m_mapAccounts.begin(); ii != m_mapAccounts.end(); ++ii)
	{
		if (pAccount = (*ii).second) // if pointer not null
		{
			pAccount->GetIdentifier(anAccountID);
			
			if (anAccountID == ACCOUNT_ID)
			{
				m_mapAccounts.erase(ii);
				delete pAccount;
				pAccount = NULL;
				break;
			}
		}
	}
	
	const OTString	strAcctID(ACCOUNT_ID);
	m_mapAccounts[strAcctID.Get()] = &theAcct;
}


// Look up an account by ID and see if it is in the wallet.
// If it is, return a pointer to it, otherwise return NULL.
OTAccount * OTWallet::GetAccount(const OTIdentifier & theAccountID)
{
	// loop through the items that make up this transaction and print them out here, base64-encoded, of course.
	OTAccount * pAccount = NULL;
	OTIdentifier anAccountID;
	
	for (mapOfAccounts::iterator ii = m_mapAccounts.begin(); ii != m_mapAccounts.end(); ++ii)
	{
		if (pAccount = (*ii).second) // if pointer not null
		{
			pAccount->GetIdentifier(anAccountID);
			
			if (anAccountID == theAccountID)
				return pAccount;
		}
	}
	
	return NULL;
}


// The wallet "owns" theContract and will handle cleaning it up.
// So make SURE you allocate it on the heap.
void OTWallet::AddAssetContract(const OTAssetContract & theContract)
{
	OTIdentifier	CONTRACT_ID(theContract);
	OTString		STR_CONTRACT_ID(CONTRACT_ID);
	
	OTAssetContract * pContract = GetAssetContract(CONTRACT_ID);
	
	if (pContract)
	{
		fprintf(stderr, "Error: Attempt to add Asset Contract but it is already in the wallet.\n");
	}
	else {
		m_mapContracts[STR_CONTRACT_ID.Get()] = &((OTAssetContract &)theContract);
	}
}

OTAssetContract * OTWallet::GetAssetContract(const OTIdentifier & theContractID)
{
	// loop through the items that make up this transaction and print them out here, base64-encoded, of course.
	OTAssetContract * pContract = NULL;
	OTIdentifier aContractID;
	
	for (mapOfContracts::iterator ii = m_mapContracts.begin(); ii != m_mapContracts.end(); ++ii)
	{
		if (pContract = (*ii).second) // if pointer not null
		{
			pContract->GetIdentifier(aContractID);
			
			if (aContractID == theContractID)
				return pContract;
		}
	}
	
	return NULL;	
}

bool OTWallet::LoadWallet(const char * szFilename)
{

	if (NULL == szFilename)
		return false;
		
	IrrXMLReader* xml = createIrrXMLReader(szFilename);
		
	// parse the file until end reached
	while(xml && xml->read())
	{
		// strings for storing the data that we want to read out of the file
		OTString NymName;
		OTString NymFile;
		OTString NymID;
		
		OTString AssetName;
		OTString AssetContract;
		OTString AssetID;
		
		OTString ServerName;
		OTString ServerContract;
		OTString ServerID;
		
		OTString AcctName;
		OTString AcctFile;
		OTString AcctID;
		
		switch(xml->getNodeType())
		{
			case EXN_TEXT:
				// in this xml file, the only text which occurs is the messageText
				//messageText = xml->getNodeData();
				break;
			case EXN_ELEMENT:
			{
				if (!strcmp("wallet", xml->getNodeName()))
				{
					m_strName = xml->getAttributeValue("name");					
					m_strVersion = xml->getAttributeValue("version");					
					
					fprintf(stderr, "\nLoading wallet: %s, version: %s\n", m_strName.Get(), m_strVersion.Get());
				}
				else if (!strcmp("pseudonym", xml->getNodeName()))
				{
					NymName = xml->getAttributeValue("name");// user-assigned name for GUI usage				
					NymFile = xml->getAttributeValue("file");// another XML file. Need to store stuff for nyms.
					NymID = xml->getAttributeValue("nymID"); // message digest from hash of x.509 cert
					
					fprintf(stderr, "\n\n** Pseudonym ** (wallet listing): %s\nID: %s\nfile: %s\n",
							NymName.Get(), NymID.Get(), NymFile.Get());

					OTPseudonym * pNym = new OTPseudonym(NymName, NymFile, NymID);
										
					if (pNym && pNym->LoadNymfile((char*)(NymFile.Get())))
					{
						if (pNym->Loadx509CertAndPrivateKey()) 
						{							
							if (pNym->VerifyPseudonym()) 
							{
								m_mapNyms[NymID.Get()] = pNym;
								g_pTemporaryNym = pNym; // TODO remove this temporary line used for testing only.
							}
							else {
								fprintf(stderr, "Error verifying public key from x509 against Nym ID in OTWallet::LoadWallet\n");
							}
						}
						else {
							fprintf(stderr, "Error loading x509 file for Pseudonym in OTWallet::LoadWallet\n");
						}
					}
					else {
						fprintf(stderr, "Error creating or loading Nym in OTWallet::LoadWallet\n");
					}
				}
				else if (!strcmp("assetType", xml->getNodeName()))
				{
					AssetName = xml->getAttributeValue("name");			
					AssetContract = xml->getAttributeValue("contract"); // digital asset contract file
					AssetID = xml->getAttributeValue("assetTypeID"); // hash of contract itself
					
					fprintf(stderr, "\n\n****Asset Contract**** (wallet listing) Name: %s\nContract ID:\n%s"
							"\nLocation of contract file: %s\n",
							AssetName.Get(), AssetID.Get(), AssetContract.Get());

					OTAssetContract * pContract = new OTAssetContract(AssetName, AssetContract, AssetID);

					if (pContract)
					{
						if (pContract->LoadContract()) 
						{
							if (pContract->VerifyContract())
							{
								fprintf(stderr, "** Asset Contract Verified **\n-----------------------------------------------------------------------------\n\n");
								
								m_mapContracts[AssetID.Get()] = pContract;
								g_pTemporaryContract = pContract; // TODO remove this temporary line used for testing only
							}
							else
							{
								fprintf(stderr, "Contract FAILED to verify.\n");
							}							
						}
						else {
							fprintf(stderr, "Error reading file for Asset Contract in OTWallet::LoadWallet\n");
						}
					}
					else {
						fprintf(stderr, "Error allocating memory for Asset Contract in OTWallet::LoadWallet\n");
					}
				}
				else if (!strcmp("notaryProvider", xml->getNodeName())) 
				{
					ServerName = xml->getAttributeValue("name");					
					ServerContract = xml->getAttributeValue("contract"); // transaction server contract
					ServerID = xml->getAttributeValue("serverID"); // hash of contract
					
					fprintf(stderr, "\n\n\n****Notary Server (contract)**** (wallet listing): %s\n ServerID:\n%s\n"
							"contract file: %s\n", ServerName.Get(), ServerID.Get(), ServerContract.Get());
				
					OTServerContract * pContract = new OTServerContract(ServerName, ServerContract, ServerID);
					
					if (pContract)
					{
						if (pContract->LoadContract()) 
						{
							// TODO: move these lines back into the 'if' block below.
							// Moved them temporarily so I could regenerate some newly-signed contracts
							// for testing only.
							m_mapServers[ServerID.Get()] = pContract;
							g_pServerContract = pContract; // TODO remove this temporary line used for testing only

							if (pContract->VerifyContract())
							{
								fprintf(stderr, "** Server Contract Verified **\n-----------------------------------------------------------------------------\n\n");
								
							}
							else
							{
								fprintf(stderr, "Server contract failed to verify.\n");
							}
						}
						else {
							fprintf(stderr, "Error reading file for Transaction Server in OTWallet::LoadWallet\n");
						}
					}
					else {
						fprintf(stderr, "Error allocating memory for Server Contract in OTWallet::LoadWallet\n");
					}
				}
				else if (!strcmp("assetAccount", xml->getNodeName())) 
				{
					AcctName = xml->getAttributeValue("name");					
					AcctFile = xml->getAttributeValue("file");
					AcctID	 = xml->getAttributeValue("accountID");
					ServerID = xml->getAttributeValue("serverID");
										
					fprintf(stderr, "\n--------------------------------------------------------------------------\n"
							"****Account**** (wallet listing) "
							"name: %s\n AccountID: %s\n ServerID: %s\n file: %s\n", 
							AcctName.Get(), AcctID.Get(), ServerID.Get(), AcctFile.Get());
					
					OTIdentifier ACCOUNT_ID(AcctID), SERVER_ID(ServerID);
					
					OTAccount * pAccount =  OTAccount::LoadExistingAccount(ACCOUNT_ID, SERVER_ID);
					
					if (pAccount)
					{
						m_mapAccounts[AcctID.Get()] = pAccount;
						
						// TODO remove this test code that makes sure the first pseudonym loaded is the signer on these accounts
						if (g_pTemporaryNym)
						{
							bool bVerified = pAccount->VerifySignature(*g_pTemporaryNym);
							
							if (bVerified) {
								fprintf(stderr, "Verified that this Pseudonym HAS signed this account.\n");
							}
							else
							{
								fprintf(stderr, "Verified that this Pseudonym has *NOT* signed this account: %s\n",
										AcctID.Get());
							}
						}
						// --------------------------------------------------------------
						
					}
					else {
						fprintf(stderr, "Error allocating memory or reading file for Asset Account in OTWallet::LoadWallet\n");
					}
				}
				else
				{
					// unknown element type
					fprintf(stderr, "unknown element type: %s\n", xml->getNodeName());
				}
			}
				break;
		}
	}
	
	
	
	
	
	
	// TODO remove this test code
	//bool GetAsciiArmoredData(OTASCIIArmor & theArmoredText) const;
	//bool SetAsciiArmoredData(const OTASCIIArmor & theArmoredText)
	
	/*
	OTString strPlaintext("Testing testing testing testing blah blah blah");
	fprintf(stderr, "\n\nTesting new RSA ENVELOPES (public key crypto).\n\nPlaintext: %s\n", strPlaintext.Get());
	
	OTEnvelope theEVP;
	theEVP.Seal(*g_pTemporaryNym, strPlaintext);
	
	
	OTASCIIArmor ascCiphertext;
	theEVP.GetAsciiArmoredData(ascCiphertext); // Now the contents of encrypted envelope are ascii-encoded
	
	fprintf(stderr, "\nASCII-ARMORED Ciphertext:\n%s\n", ascCiphertext.Get());

	
	// Now decrypt it
	OTEnvelope evpReceived;
	evpReceived.SetAsciiArmoredData(ascCiphertext);
	
	OTString strDecrypted;
	evpReceived.Open(*g_pTemporaryNym, strDecrypted);
	
	fprintf(stderr, "Decrypted text: %s\n\n\n", strDecrypted.Get());
	*/
		

	// delete the xml parser after usage
	if (xml)
		delete xml;
	
	return true;
}












































