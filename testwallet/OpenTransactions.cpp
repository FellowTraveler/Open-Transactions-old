/*
 *  OpenTransactions.cpp
 *
 *  A C++ high-level interface.
 *
 *  Created by Fellow Traveler on 8/6/10.
 *  Copyright 2010. All rights reserved.
 *
 */

#include "OTString.h"


#include "OTPseudonym.h"

#include "OTClient.h"
#include "OTServerConnection.h"
#include "OTMessage.h"
#include "OTWallet.h"
#include "OTEnvelope.h"

#include "OTTransaction.h"
#include "OTMint.h"
#include "OTToken.h"
#include "OTPurse.h"
#include "OTLedger.h"
#include "OTCheque.h"

#include "OpenTransactions.h"

// Todo: convert these from globals to OpenTransactions member variables
// (So you can instantiate it multiple times, though I don't see that being
// needed... most real world apps will only use this interface once...)

OTWallet		g_Wallet;
OTClient		g_Client;

OTPseudonym *g_pTemporaryNym = NULL;




int OT_API_getNymCount()
{
	return g_Wallet.GetNymCount();
}

int OT_API_getServerCount()
{
	return g_Wallet.GetServerCount();
}

int OT_API_getAssetTypeCount()
{
	return g_Wallet.GetAssetTypeCount();
}

int OT_API_getAccountCount()
{
	return g_Wallet.GetAccountCount();
}

bool OT_API_getNym(int iIndex, OTIdentifier & NYM_ID, OTString & NYM_NAME)
{
	return g_Wallet.GetNym(iIndex, NYM_ID, NYM_NAME);
}

bool OT_API_getServer(int iIndex, OTIdentifier & THE_ID, OTString & THE_NAME)
{
	return g_Wallet.GetServer(iIndex, THE_ID, THE_NAME);
}

bool OT_API_getAssetType(int iIndex, OTIdentifier & THE_ID, OTString & THE_NAME)
{
	return g_Wallet.GetAssetType(iIndex, THE_ID, THE_NAME);
}

bool OT_API_getAccount(int iIndex, OTIdentifier & THE_ID, OTString & THE_NAME)
{
	return g_Wallet.GetAccount(iIndex, THE_ID, THE_NAME);
}


// Need to call this before using OT.
bool OT_API_Init(OTString & strClientPath)
{
	OTPseudonym::OTPath.Set(strClientPath.Get());
	
	return g_Client.InitClient(g_Wallet);
}



// "wallet.xml" (path set above.)
bool OT_API_loadWallet(OTString & strPath)
{
	return g_Wallet.LoadWallet(strPath.Get());
}


// Eventually this connects to the server denoted by SERVER_ID
// But for right now, it just connects to the first server in the list.
// TODO: make it connect to the server ID instead of the first one in the list.
bool OT_API_connectServer(OTIdentifier & SERVER_ID, OTIdentifier	& USER_ID,
									 OTString & strCA_FILE, OTString & strKEY_FILE, OTString & strKEY_PASSWORD)
{
	// Wallet, after loading, should contain a list of server
	// contracts. Let's pull the hostname and port out of
	// the first contract, and connect to that server.
	
	OTPseudonym * pNym = g_Wallet.GetNymByID(USER_ID);
	
	if (!pNym)
	{
		fprintf(stdout, "No Nym loaded but tried to connect to server.\n");
		return false;
	}
		
	bool bConnected = g_Client.ConnectToTheFirstServerOnList(*pNym, strCA_FILE, strKEY_FILE, strKEY_PASSWORD); 
	
	if (bConnected)
	{
		fprintf(stdout, "Success. (Connected to the first notary server on your wallet's list.)\n");
		return true;
	}
	else {
		fprintf(stdout, "Either the wallet is not loaded, or there was an error connecting to server.\n");
		return false;
	}
}




// Open Transactions maintains a connection to the server(s)
// Messages could arrive from the server at any time, though
// usually this only happens right after a request was sent.
// The client should call THIS function periodically, to listen
// on the connections for any server replies and process them.
//
// Perhaps once per second, and more often immediately following
// a request.  (Usually only one response comes for each request.)
bool OT_API_processSockets()
{
	bool bFoundMessage = false, bSuccess = false;
	
	// 4) While there are messages to be read in response from the server,
	//	  then process and handle them all.
	do 
	{
		OTMessage theMsg;
		
		// If this returns true, that means a Message was
		// received and processed into an OTMessage object (theMsg)
		bFoundMessage = g_Client.ProcessInBuffer(theMsg);
		
		if (true == bFoundMessage)
		{
			bSuccess = true;
			
			//				OTString strReply;
			//				theMsg.SaveContract(strReply);
			//				fprintf(stderr, "\n\n**********************************************\n"
			//						"Successfully in-processed server response.\n\n%s\n", strReply.Get());
			g_Client.ProcessServerReply(theMsg);
		}
		
	} while (true == bFoundMessage);
	
	return bSuccess;
}




void OT_API_exchangeBasket(OTIdentifier	& SERVER_ID,
									  OTIdentifier	& USER_ID,
									  OTIdentifier	& BASKET_ASSET_ID,
									  OTString		& BASKET_INFO)
{
	// -----------------------------------------------------------------
	
	OTServerContract * pServer = g_Wallet.GetServerContract(SERVER_ID);
	
	if (!pServer)
	{
		// todo error message
		
		return;
	}
	
	
	// -----------------------------------------------------------------
	
	OTPseudonym * pNym = g_Wallet.GetNymByID(USER_ID);
	
	if (!pNym)
	{
		// todo error message
		
		return;
	}
	
	// -----------------------------------------------------------------
	
	OTAssetContract * pAssetContract = g_Wallet.GetAssetContract(BASKET_ASSET_ID);
	
	if (!pAssetContract)
	{
		// todo error message
		
		return;
	}
	
	// -----------------------------------------------------------------
	
	OTMessage theMessage;
	long lRequestNumber = 0;
	
	OTString strServerID(SERVER_ID), strNymID(USER_ID), strAssetTypeID(BASKET_ASSET_ID);
	
	// (0) Set up the REQUEST NUMBER and then INCREMENT IT
	pNym->GetCurrentRequestNum(strServerID, lRequestNumber);
	theMessage.m_strRequestNum.Format("%ld", lRequestNumber); // Always have to send this.
	pNym->IncrementRequestNum(*pNym, strServerID); // since I used it for a server request, I have to increment it
	
	// (1) set up member variables 
	theMessage.m_strCommand			= "exchangeBasket";
	theMessage.m_strNymID			= strNymID;
	theMessage.m_strServerID		= strServerID;
	theMessage.m_strAssetID			= strAssetTypeID;
	
	theMessage.m_ascPayload.SetString(BASKET_INFO);
	
	// (2) Sign the Message 
	theMessage.SignContract(*pNym);		
	
	// (3) Save the Message (with signatures and all, back to its internal member m_strRawFile.)
	theMessage.SaveContract();
	
	// (Send it)
	g_Client.ProcessMessageOut(theMessage);		
}





void OT_API_getTransactionNumber(OTIdentifier & SERVER_ID,
											OTIdentifier & USER_ID)
{
	// -----------------------------------------------------------------
	
	OTServerContract * pServer = g_Wallet.GetServerContract(SERVER_ID);
	
	if (!pServer)
	{
		// todo error message
		
		return;
	}
	
	
	// -----------------------------------------------------------------
	
	OTPseudonym * pNym = g_Wallet.GetNymByID(USER_ID);
	
	if (!pNym)
	{
		// todo error message
		
		return;
	}
	
	// -----------------------------------------------------------------
	
	OTMessage theMessage;
	
	if (g_Client.ProcessUserCommand(OTClient::getTransactionNum, theMessage, 
									*pNym, *pServer,
									NULL)) // NULL pAccount on this command.
	{				
		g_Client.ProcessMessageOut(theMessage);
	}
	else
		fprintf(stderr, "Error processing getTransactionNumber command in OT_API_getTransactionNumber\n");
}





void OT_API_notarizeWithdrawal(OTIdentifier	& SERVER_ID,
										  OTIdentifier	& USER_ID,
										  OTIdentifier	& ACCT_ID,
										  OTString		& AMOUNT)
{
	// -----------------------------------------------------------------
	
	OTServerContract * pServer = g_Wallet.GetServerContract(SERVER_ID);
	
	if (!pServer)
	{
		// todo error message
		
		return;
	}
	
	
	// -----------------------------------------------------------------
	
	OTPseudonym * pNym = g_Wallet.GetNymByID(USER_ID);
	
	if (!pNym)
	{
		// todo error message
		
		return;
	}
	
	// -----------------------------------------------------------------
	
	OTIdentifier	CONTRACT_ID;
	OTString		strContractID;
	
	OTAccount * pAccount = g_Wallet.GetAccount(ACCT_ID);
	
	if (!pAccount)
	{
		// todo error message
		
		return;
	}
	else {
		CONTRACT_ID = pAccount->GetAssetTypeID();
		CONTRACT_ID.GetString(strContractID);
	}
	
	
	// -----------------------------------------------------------------
	
	
	OTMessage theMessage;
	
	long lRequestNumber = 0;
	long lAmount = atol(AMOUNT.Get());
	
	OTString strServerID(SERVER_ID), strNymID(USER_ID), strFromAcct(ACCT_ID);
	
	long lStoredTransactionNumber=0;
	bool bGotTransNum = pNym->GetNextTransactionNum(*pNym, strServerID, lStoredTransactionNumber);
	
	if (bGotTransNum)
	{
		// Create a transaction
		OTTransaction * pTransaction = OTTransaction::GenerateTransaction (USER_ID, ACCT_ID, SERVER_ID, 
																		   OTTransaction::withdrawal, lStoredTransactionNumber); 
		
		// set up the transaction item (each transaction may have multiple items...)
		OTItem * pItem		= OTItem::CreateItemFromTransaction(*pTransaction, OTItem::withdrawal);
		pItem->m_lAmount	= lAmount;
		
		const OTPseudonym * pServerNym = pServer->GetContractPublicNym();
		
		OTString strMintPath;
		strMintPath.Format("%s%smints%s%s", OTPseudonym::OTPath.Get(), OTPseudonym::OTPathSeparator.Get(), 
						   OTPseudonym::OTPathSeparator.Get(), strContractID.Get()); 
		OTMint theMint(strContractID, strMintPath, strContractID);
		
		if (pServerNym && theMint.LoadContract() && theMint.VerifyMint((OTPseudonym&)*pServerNym))
		{
			OTPurse * pPurse		= new OTPurse(SERVER_ID, CONTRACT_ID);
			OTPurse * pPurseMyCopy	= new OTPurse(SERVER_ID, CONTRACT_ID);
			
			// Create all the necessary tokens for the withdrawal amount.
			// Push copies of each token into a purse to be sent to the server,
			// as well as a purse to be kept for unblinding when we receive the
			// server response.  (Coin private unblinding keys are not sent to
			// the server, obviously.)
			long lTokenAmount = 0;
			while (lTokenAmount = theMint.GetLargestDenomination(lAmount))
			{
				lAmount -= lTokenAmount;
				
				// Create the relevant token request with same server/asset ID as the purse.
				// the purse does NOT own the token at this point. the token's constructor
				// just uses it to copy some IDs, since they must match.
				OTToken theToken(*pPurse);
				
				// GENERATE new token, sign it and save it. 
				theToken.GenerateTokenRequest(*pNym, theMint, lTokenAmount);
				theToken.SignContract(*pNym);
				theToken.SaveContract();
				
				// Now the proto-token is generated, let's add it to a purse
				// By pushing theToken into pPurse with *pServerNym, I encrypt it to pServerNym.
				// So now only the server Nym can decrypt that token and pop it out of that purse.
				pPurse->Push(*pServerNym, theToken);	
				
				// I'm saving my own copy of all this, encrypted to my nym
				// instead of the server's, so I can get to my private coin data.
				// The server's copy of theToken is already Pushed, so I can re-use
				// the variable now for my own purse.
				theToken.ReleaseSignatures();
				theToken.SetSavePrivateKeys(); // This time it will save the private keys when I sign it
				theToken.SignContract(*pNym);
				theToken.SaveContract();
				
				pPurseMyCopy->Push(*pNym, theToken);// Now my copy of the purse has a version of the token,
			}
			
			pPurse->SignContract(*pNym);
			pPurse->SaveContract(); // I think this one is unnecessary.
			
			// Save the purse into a string...
			OTString strPurse;
			pPurse->SaveContract(strPurse);
			
			// Add the purse string as the attachment on the transaction item.
			pItem->SetAttachment(strPurse); // The purse is contained in the reference string.
			
			
			pPurseMyCopy->SignContract(*pNym);		// encrypted to me instead of the server, and including 
			pPurseMyCopy->SaveContract();			// the private keys for unblinding the server response.
			// This thing is neat and tidy. The wallet can just save it as an ascii-armored string as a
			// purse field inside the wallet file.  It doesn't do that for now (TODO) but it easily could.
			
			
			// Add the purse to the wallet
			// (We will need it to look up the private coin info for unblinding the token,
			//  when the response comes from the server.)
			g_Wallet.AddPendingWithdrawal(*pPurseMyCopy);
			
			delete pPurse;
			pPurse			= NULL; // We're done with this one.
			pPurseMyCopy	= NULL; // The wallet owns my copy now and will handle cleaning it up.
			
			
			// sign the item
			pItem->SignContract(*pNym);
			pItem->SaveContract();
			
			pTransaction->AddItem(*pItem); // the Transaction's destructor will cleanup the item. It "owns" it now.
			
			// sign the transaction
			pTransaction->SignContract(*pNym);
			pTransaction->SaveContract();
			
			
			// set up the ledger
			OTLedger theLedger(USER_ID, ACCT_ID, SERVER_ID);
			theLedger.GenerateLedger(ACCT_ID, SERVER_ID, OTLedger::message); // bGenerateLedger defaults to false, which is correct.
			theLedger.AddTransaction(*pTransaction);
			
			// sign the ledger
			theLedger.SignContract(*pNym);
			theLedger.SaveContract();
			
			// extract the ledger in ascii-armored form
			OTString		strLedger(theLedger);
			OTASCIIArmor	ascLedger; // I can't pass strLedger into this constructor because I want to encode it
			
			// Encoding...
			ascLedger.SetString(strLedger);
			
			
			// (0) Set up the REQUEST NUMBER and then INCREMENT IT
			pNym->GetCurrentRequestNum(strServerID, lRequestNumber);
			theMessage.m_strRequestNum.Format("%ld", lRequestNumber); // Always have to send this.
			pNym->IncrementRequestNum(*pNym, strServerID); // since I used it for a server request, I have to increment it
			
			// (1) Set up member variables 
			theMessage.m_strCommand			= "notarizeTransactions";
			theMessage.m_strNymID			= strNymID;
			theMessage.m_strServerID		= strServerID;
			theMessage.m_strAcctID			= strFromAcct;
			theMessage.m_ascPayload			= ascLedger;
			
			// (2) Sign the Message 
			theMessage.SignContract(*pNym);		
			
			// (3) Save the Message (with signatures and all, back to its internal member m_strRawFile.)
			theMessage.SaveContract();
			
			// (Send it)
			g_Client.ProcessMessageOut(theMessage);	
		}
	}
	else {
		fprintf(stderr, "No Transaction Numbers were available. Suggest requesting the server for a new one.\n");
	}
}





void OT_API_notarizeDeposit(OTIdentifier	& SERVER_ID,
									   OTIdentifier	& USER_ID,
									   OTIdentifier	& ACCT_ID,
									   OTString		& THE_PURSE)
{
	// -----------------------------------------------------------------
	
	OTServerContract * pServer = g_Wallet.GetServerContract(SERVER_ID);
	
	if (!pServer)
	{
		// todo error message
		
		return;
	}
	
	
	// -----------------------------------------------------------------
	
	OTPseudonym * pNym = g_Wallet.GetNymByID(USER_ID);
	
	if (!pNym)
	{
		// todo error message
		
		return;
	}
	
	// -----------------------------------------------------------------
	
	OTIdentifier	CONTRACT_ID;
	OTString		strContractID;
	
	OTAccount * pAccount = g_Wallet.GetAccount(ACCT_ID);
	
	if (!pAccount)
	{
		// todo error message
		
		return;
	}
	else {
		CONTRACT_ID = pAccount->GetAssetTypeID();
		CONTRACT_ID.GetString(strContractID);
	}
	
	
	// -----------------------------------------------------------------
	
	OTMessage theMessage;
	long lRequestNumber = 0;
	
	OTString strServerID(SERVER_ID), strNymID(USER_ID), strFromAcct(ACCT_ID);
	
	
	OTPurse thePurse(SERVER_ID, CONTRACT_ID);
	
	const OTPseudonym * pServerNym = pServer->GetContractPublicNym();
	
	long lStoredTransactionNumber=0;
	bool bGotTransNum = pNym->GetNextTransactionNum(*pNym, strServerID, lStoredTransactionNumber);
	
	if (!bGotTransNum)
	{
		fprintf(stderr, "No Transaction Numbers were available. Try requesting the server for a new one.\n");
	}
	else if (pServerNym)
	{
		bool bSuccess = false;
		
		// Create a transaction
		OTTransaction * pTransaction = OTTransaction::GenerateTransaction (USER_ID, ACCT_ID, SERVER_ID, 
																		   OTTransaction::deposit, lStoredTransactionNumber); 
		
		// set up the transaction item (each transaction may have multiple items...)
		OTItem * pItem		= OTItem::CreateItemFromTransaction(*pTransaction, OTItem::deposit);
		
		OTPurse theSourcePurse(thePurse);
		
		if (theSourcePurse.LoadContractFromString(THE_PURSE))
			while (!theSourcePurse.IsEmpty()) 
			{
				OTToken * pToken = theSourcePurse.Pop(*pNym);
				
				if (pToken)
				{
					// TODO need 2-recipient envelopes. My request to the server is encrypted to the server's nym,
					// but it should be encrypted to my Nym also, so both have access to decrypt it.
					
					// Now the token is ready, let's add it to a purse
					// By pushing theToken into thePurse with *pServerNym, I encrypt it to pServerNym.
					// So now only the server Nym can decrypt that token and pop it out of that purse.
					if (false == pToken->ReassignOwnership(*pNym, *pServerNym))
					{
						fprintf(stderr, "Error re-assigning ownership of token (to server.)\n");
						delete pToken;
						pToken = NULL;
						bSuccess = false;
						break;
					}
					else 
					{
						fprintf(stderr, "Success re-assigning ownership of token (to server.)\n");
						
						bSuccess = true;
						
						pToken->ReleaseSignatures();
						pToken->SignContract(*pNym);
						pToken->SaveContract();
						
						thePurse.Push(*pServerNym, *pToken);
						
						pItem->m_lAmount += pToken->GetDenomination();
					}
					
					delete pToken;
					pToken = NULL;
				}
				else {
					fprintf(stderr, "Error loading token from purse.\n");
					break;
				}
				
			}
		
		if (bSuccess)
		{
			thePurse.SignContract(*pNym);
			thePurse.SaveContract(); // I think this one is unnecessary.
			
			// Save the purse into a string...
			OTString strPurse;
			thePurse.SaveContract(strPurse);
			
			// Add the purse string as the attachment on the transaction item.
			pItem->SetAttachment(strPurse); // The purse is contained in the reference string.
			
			// sign the item
			pItem->SignContract(*pNym);
			pItem->SaveContract();
			
			// the Transaction "owns" the item now and will handle cleaning it up.
			pTransaction->AddItem(*pItem); // the Transaction's destructor will cleanup the item. It "owns" it now.
			
			// sign the transaction
			pTransaction->SignContract(*pNym);
			pTransaction->SaveContract();
			
			
			// set up the ledger
			OTLedger theLedger(USER_ID, ACCT_ID, SERVER_ID);
			theLedger.GenerateLedger(ACCT_ID, SERVER_ID, OTLedger::message); // bGenerateLedger defaults to false, which is correct.
			theLedger.AddTransaction(*pTransaction); // now the ledger "owns" and will handle cleaning up the transaction.
			
			// sign the ledger
			theLedger.SignContract(*pNym);
			theLedger.SaveContract();
			
			// extract the ledger in ascii-armored form... encoding...
			OTString		strLedger(theLedger);
			OTASCIIArmor	ascLedger(strLedger);
			
			// (0) Set up the REQUEST NUMBER and then INCREMENT IT
			pNym->GetCurrentRequestNum(strServerID, lRequestNumber);
			theMessage.m_strRequestNum.Format("%ld", lRequestNumber); // Always have to send this.
			pNym->IncrementRequestNum(*pNym, strServerID); // since I used it for a server request, I have to increment it
			
			// (1) Set up member variables 
			theMessage.m_strCommand			= "notarizeTransactions";
			theMessage.m_strNymID			= strNymID;
			theMessage.m_strServerID		= strServerID;
			theMessage.m_strAcctID			= strFromAcct;
			theMessage.m_ascPayload			= ascLedger;
			
			// (2) Sign the Message 
			theMessage.SignContract(*pNym);		
			
			// (3) Save the Message (with signatures and all, back to its internal member m_strRawFile.)
			theMessage.SaveContract();
			
			// (Send it)
			g_Client.ProcessMessageOut(theMessage);	
			
		} // bSuccess
		else {
			delete pItem;		pItem = NULL;
			delete pTransaction;pTransaction = NULL;
		}
	} // if (pServerNym)
}



void OT_API_withdrawVoucher(OTIdentifier	& SERVER_ID,
									OTIdentifier	& USER_ID,
									OTIdentifier	& ACCT_ID,
									OTIdentifier	& RECIPIENT_USER_ID,
									OTString		& CHEQUE_MEMO,
									OTString		& AMOUNT)
{
	// -----------------------------------------------------------------
	
	OTServerContract * pServer = g_Wallet.GetServerContract(SERVER_ID);
	
	if (!pServer)
	{
		// todo error message
		
		return;
	}
	
	
	// -----------------------------------------------------------------
	
	OTPseudonym * pNym = g_Wallet.GetNymByID(USER_ID);
	
	if (!pNym)
	{
		// todo error message
		
		return;
	}
	
	// -----------------------------------------------------------------
	
	OTIdentifier	CONTRACT_ID;
	OTString		strContractID;
	
	OTAccount * pAccount = g_Wallet.GetAccount(ACCT_ID);
	
	if (!pAccount)
	{
		// todo error message
		
		return;
	}
	else {
		CONTRACT_ID = pAccount->GetAssetTypeID();
		CONTRACT_ID.GetString(strContractID);
	}
	
	
	// -----------------------------------------------------------------
	
	OTMessage theMessage;
	
	long lAmount = atol(AMOUNT.Get());
	
	OTString strServerID(SERVER_ID), strNymID(USER_ID), strFromAcct(ACCT_ID);
	
	long lStoredTransactionNumber=0;
	bool bGotTransNum = pNym->GetNextTransactionNum(*pNym, strServerID, lStoredTransactionNumber);
	
	if (bGotTransNum)
	{
		const OTString strChequeMemo(CHEQUE_MEMO);
		const OTString strRecipientUserID(RECIPIENT_USER_ID);
		
		const long lAmount = atol(AMOUNT.Get());

		// -----------------------------------------------------------------------
		
		// Expiration (ignored by server -- it sets its own for its vouchers.)
		const	time_t	VALID_FROM	= time(NULL); // This time is set to TODAY NOW
		const	time_t	VALID_TO	= VALID_FROM + 15552000; // 6 months.
		
		// -----------------------------------------------------------------------
		// The server only uses the memo, amount, and recipient from this cheque when it
		// constructs the actual voucher.
		OTCheque theRequestVoucher(SERVER_ID, CONTRACT_ID);
		bool bIssueCheque = theRequestVoucher.IssueCheque(lAmount, lStoredTransactionNumber,// server actually ignores this and supplies its own transaction number for any voucher.
														  VALID_FROM, VALID_TO, ACCT_ID, USER_ID, strChequeMemo,
														  (strRecipientUserID.GetLength() > 2) ? &(RECIPIENT_USER_ID) : NULL);
		
		if (bIssueCheque)
		{
			// Create a transaction
			OTTransaction * pTransaction = OTTransaction::GenerateTransaction (USER_ID, ACCT_ID, SERVER_ID, 
																			   OTTransaction::withdrawal, lStoredTransactionNumber); 
			
			// set up the transaction item (each transaction may have multiple items...)
			OTItem * pItem		= OTItem::CreateItemFromTransaction(*pTransaction, OTItem::withdrawVoucher);
			pItem->m_lAmount	= lAmount;
			OTString strNote("Withdraw Voucher: ");
			pItem->SetNote(strNote);
			
			// Add the voucher request string as the attachment on the transaction item.
			OTString strVoucher;
			theRequestVoucher.SignContract(*pNym);
			theRequestVoucher.SaveContract();
			theRequestVoucher.SaveContract(strVoucher);			
			pItem->SetAttachment(strVoucher); // The voucher request is contained in the reference string.
			
			// sign the item
			pItem->SignContract(*pNym);
			pItem->SaveContract();
			
			pTransaction->AddItem(*pItem); // the Transaction's destructor will cleanup the item. It "owns" it now.
			
			// sign the transaction
			pTransaction->SignContract(*pNym);
			pTransaction->SaveContract();
			
			
			// set up the ledger
			OTLedger theLedger(USER_ID, ACCT_ID, SERVER_ID);
			theLedger.GenerateLedger(ACCT_ID, SERVER_ID, OTLedger::message); // bGenerateLedger defaults to false, which is correct.
			theLedger.AddTransaction(*pTransaction);
			
			// sign the ledger
			theLedger.SignContract(*pNym);
			theLedger.SaveContract();
			
			// extract the ledger in ascii-armored form
			OTString		strLedger(theLedger);
			OTASCIIArmor	ascLedger(strLedger);
			
			long lRequestNumber = 0;
			
			// (0) Set up the REQUEST NUMBER and then INCREMENT IT
			pNym->GetCurrentRequestNum(strServerID, lRequestNumber);
			theMessage.m_strRequestNum.Format("%ld", lRequestNumber); // Always have to send this.
			pNym->IncrementRequestNum(*pNym, strServerID); // since I used it for a server request, I have to increment it
			
			// (1) Set up member variables 
			theMessage.m_strCommand			= "notarizeTransactions";
			theMessage.m_strNymID			= strNymID;
			theMessage.m_strServerID		= strServerID;
			theMessage.m_strAcctID			= strFromAcct;
			theMessage.m_ascPayload			= ascLedger;
			
			// (2) Sign the Message 
			theMessage.SignContract(*pNym);		
			
			// (3) Save the Message (with signatures and all, back to its internal member m_strRawFile.)
			theMessage.SaveContract();
			
			// (Send it)
			g_Client.ProcessMessageOut(theMessage);	
		}
	}
	else {
		fprintf(stderr, "No Transaction Numbers were available. Suggest requesting the server for a new one.\n");
	}
}





void OT_API_depositCheque(OTIdentifier	& SERVER_ID,
									   OTIdentifier	& USER_ID,
									   OTIdentifier	& ACCT_ID,
									   OTString		& THE_CHEQUE)
{
	// -----------------------------------------------------------------
	
	OTServerContract * pServer = g_Wallet.GetServerContract(SERVER_ID);
	
	if (!pServer)
	{
		// todo error message
		
		return;
	}
	
	
	// -----------------------------------------------------------------
	
	OTPseudonym * pNym = g_Wallet.GetNymByID(USER_ID);
	
	if (!pNym)
	{
		// todo error message
		
		return;
	}
	
	// -----------------------------------------------------------------
	
	OTIdentifier	CONTRACT_ID;
	OTString		strContractID;
	
	OTAccount * pAccount = g_Wallet.GetAccount(ACCT_ID);
	
	if (!pAccount)
	{
		// todo error message
		
		return;
	}
	else {
		CONTRACT_ID = pAccount->GetAssetTypeID();
		CONTRACT_ID.GetString(strContractID);
	}
	
	
	// -----------------------------------------------------------------
	
	OTMessage theMessage;
	long lRequestNumber = 0;
	
	OTString strServerID(SERVER_ID), strNymID(USER_ID), strFromAcct(ACCT_ID);
	
	OTCheque theCheque(SERVER_ID, CONTRACT_ID);
	
	long lStoredTransactionNumber=0;
	bool bGotTransNum = pNym->GetNextTransactionNum(*pNym, strServerID, lStoredTransactionNumber);
	
	if (!bGotTransNum)
	{
		fprintf(stderr, "No Transaction Numbers were available. Try requesting the server for a new one.\n");
	}
	else if (theCheque.LoadContractFromString(THE_CHEQUE))
	{
		// Create a transaction
		OTTransaction * pTransaction = OTTransaction::GenerateTransaction (USER_ID, ACCT_ID, SERVER_ID, 
																		   OTTransaction::deposit, lStoredTransactionNumber); 
		
		// set up the transaction item (each transaction may have multiple items...)
		OTItem * pItem		= OTItem::CreateItemFromTransaction(*pTransaction, OTItem::depositCheque);
		
		OTString strNote("Deposit this cheque, please!");
		pItem->SetNote(strNote);
		
		OTString strCheque;
		theCheque.SaveContract(strCheque);
		
		// Add the cheque string as the attachment on the transaction item.
		pItem->SetAttachment(strCheque); // The cheque is contained in the reference string.
		
		// sign the item
		pItem->SignContract(*pNym);
		pItem->SaveContract();
		
		// the Transaction "owns" the item now and will handle cleaning it up.
		pTransaction->AddItem(*pItem); // the Transaction's destructor will cleanup the item. It "owns" it now.
		
		// sign the transaction
		pTransaction->SignContract(*pNym);
		pTransaction->SaveContract();
		
		// set up the ledger
		OTLedger theLedger(USER_ID, ACCT_ID, SERVER_ID);
		theLedger.GenerateLedger(ACCT_ID, SERVER_ID, OTLedger::message); // bGenerateLedger defaults to false, which is correct.
		theLedger.AddTransaction(*pTransaction); // now the ledger "owns" and will handle cleaning up the transaction.
		
		// sign the ledger
		theLedger.SignContract(*pNym);
		theLedger.SaveContract();
		
		// extract the ledger in ascii-armored form... encoding...
		OTString		strLedger(theLedger);
		OTASCIIArmor	ascLedger(strLedger);
		
		// (0) Set up the REQUEST NUMBER and then INCREMENT IT
		pNym->GetCurrentRequestNum(strServerID, lRequestNumber);
		theMessage.m_strRequestNum.Format("%ld", lRequestNumber); // Always have to send this.
		pNym->IncrementRequestNum(*pNym, strServerID); // since I used it for a server request, I have to increment it
		
		// (1) Set up member variables 
		theMessage.m_strCommand			= "notarizeTransactions";
		theMessage.m_strNymID			= strNymID;
		theMessage.m_strServerID		= strServerID;
		theMessage.m_strAcctID			= strFromAcct;
		theMessage.m_ascPayload			= ascLedger;
		
		// (2) Sign the Message 
		theMessage.SignContract(*pNym);		
		
		// (3) Save the Message (with signatures and all, back to its internal member m_strRawFile.)
		theMessage.SaveContract();
			
		// (Send it)
		g_Client.ProcessMessageOut(theMessage);	
		
	} // bSuccess
}







void OT_API_notarizeTransfer(OTIdentifier	& SERVER_ID,
										OTIdentifier	& USER_ID,
										OTIdentifier	& ACCT_FROM,
										OTIdentifier	& ACCT_TO,
										OTString		& AMOUNT,
										OTString		& NOTE)
{
	// -----------------------------------------------------------------
	
	OTServerContract * pServer = g_Wallet.GetServerContract(SERVER_ID);
	
	if (!pServer)
	{
		// todo error message
		
		return;
	}
	
	
	// -----------------------------------------------------------------
	
	OTPseudonym * pNym = g_Wallet.GetNymByID(USER_ID);
	
	if (!pNym)
	{
		// todo error message
		
		return;
	}
	
	// -----------------------------------------------------------------
	
	OTAccount * pAccount = g_Wallet.GetAccount(ACCT_FROM);
	
	if (!pAccount)
	{
		// todo error message
		
		return;
	}
	
	
	// -----------------------------------------------------------------
	
	
	OTMessage theMessage;
	
	long lRequestNumber = 0;
	long lAmount = atol(AMOUNT.Get());
	
	OTString	strServerID(SERVER_ID), strNymID(USER_ID), 
				strFromAcct(ACCT_FROM), strToAcct(ACCT_TO);

	long lStoredTransactionNumber=0;
	bool bGotTransNum = pNym->GetNextTransactionNum(*pNym, strServerID, lStoredTransactionNumber);
	
	if (bGotTransNum)
	{
		// Create a transaction
		OTTransaction * pTransaction = OTTransaction::GenerateTransaction (USER_ID, ACCT_FROM, 
																		   SERVER_ID, 
																		   OTTransaction::transfer, 
																		   lStoredTransactionNumber); 
		
		// set up the transaction item (each transaction may have multiple items...)
		OTItem * pItem		= OTItem::CreateItemFromTransaction(*pTransaction, OTItem::transfer, &ACCT_TO);
		pItem->m_lAmount	= atol(AMOUNT.Get());
		
		// The user can include a note here for the recipient.
		pItem->SetNote(NOTE);
		
		// sign the item
		pItem->SignContract(*pNym);
		pItem->SaveContract();
		
		
		pTransaction->AddItem(*pItem); // the Transaction's destructor will cleanup the item. It "owns" it now.
		
		// sign the transaction
		pTransaction->SignContract(*pNym);
		pTransaction->SaveContract();
		
		
		// set up the ledger
		OTLedger theLedger(USER_ID, ACCT_FROM, SERVER_ID);
		theLedger.GenerateLedger(ACCT_FROM, SERVER_ID, OTLedger::message); // bGenerateLedger defaults to false, which is correct.
		theLedger.AddTransaction(*pTransaction);
		
		// sign the ledger
		theLedger.SignContract(*pNym);
		theLedger.SaveContract();
		
		// extract the ledger in ascii-armored form
		OTString		strLedger(theLedger);
		OTASCIIArmor	ascLedger;
		
		// Encoding...
		ascLedger.SetString(strLedger);
		
		
		// (0) Set up the REQUEST NUMBER and then INCREMENT IT
		pNym->GetCurrentRequestNum(strServerID, lRequestNumber);
		theMessage.m_strRequestNum.Format("%ld", lRequestNumber); // Always have to send this.
		pNym->IncrementRequestNum(*pNym, strServerID); // since I used it for a server request, I have to increment it
		
		// (1) Set up member variables 
		theMessage.m_strCommand			= "notarizeTransactions";
		theMessage.m_strNymID			= strNymID;
		theMessage.m_strServerID		= strServerID;
		theMessage.m_strAcctID			= strFromAcct;
		theMessage.m_ascPayload			= ascLedger;
		
		// (2) Sign the Message 
		theMessage.SignContract(*pNym);		
		
		// (3) Save the Message (with signatures and all, back to its internal member m_strRawFile.)
		theMessage.SaveContract();

		// (Send it)
		g_Client.ProcessMessageOut(theMessage);	
	}
	else {
		fprintf(stderr, "No transaction numbers were available. Suggest requesting the server for one.\n");
	}	
}





void OT_API_getInbox(OTIdentifier & SERVER_ID,
								OTIdentifier & USER_ID,
								OTIdentifier & ACCT_ID)
{
	// -----------------------------------------------------------------
	
	OTServerContract * pServer = g_Wallet.GetServerContract(SERVER_ID);
	
	if (!pServer)
	{
		// todo error message
		
		return;
	}
	
	
	// -----------------------------------------------------------------
	
	OTPseudonym * pNym = g_Wallet.GetNymByID(USER_ID);
	
	if (!pNym)
	{
		// todo error message
		
		return;
	}
	
	// -----------------------------------------------------------------
	
	OTAccount * pAccount = g_Wallet.GetAccount(ACCT_ID);
	
	if (!pAccount)
	{
		// todo error message
		
		return;
	}
	
	// -----------------------------------------------------------------
	
	OTMessage theMessage;
	long lRequestNumber = 0;
	
	OTString strServerID(SERVER_ID), strNymID(USER_ID), strAcctID(ACCT_ID);
	
	// (0) Set up the REQUEST NUMBER and then INCREMENT IT
	pNym->GetCurrentRequestNum(strServerID, lRequestNumber);
	theMessage.m_strRequestNum.Format("%ld", lRequestNumber); // Always have to send this.
	pNym->IncrementRequestNum(*pNym, strServerID); // since I used it for a server request, I have to increment it
	
	// (1) set up member variables 
	theMessage.m_strCommand			= "getInbox";
	theMessage.m_strNymID			= strNymID;
	theMessage.m_strServerID		= strServerID;
	theMessage.m_strAcctID			= strAcctID;
	
	// (2) Sign the Message 
	theMessage.SignContract(*pNym);		
	
	// (3) Save the Message (with signatures and all, back to its internal member m_strRawFile.)
	theMessage.SaveContract();
	
	// (Send it)
	g_Client.ProcessMessageOut(theMessage);	
}





void OT_API_processInbox(OTIdentifier	& SERVER_ID,
									OTIdentifier	& USER_ID,
									OTIdentifier	& ACCT_ID,
									OTString		& ACCT_LEDGER)
{
	// -----------------------------------------------------------------
	
	OTServerContract * pServer = g_Wallet.GetServerContract(SERVER_ID);
	
	if (!pServer)
	{
		// todo error message
		
		return;
	}
	
	
	// -----------------------------------------------------------------
	
	OTPseudonym * pNym = g_Wallet.GetNymByID(USER_ID);
	
	if (!pNym)
	{
		// todo error message
		
		return;
	}
	
	// -----------------------------------------------------------------
	
	OTAccount * pAccount = g_Wallet.GetAccount(ACCT_ID);
	
	if (!pAccount)
	{
		// todo error message
		
		return;
	}
	
	// -----------------------------------------------------------------
	
	OTMessage theMessage;
	long lRequestNumber = 0;
	
	OTString strServerID(SERVER_ID), strNymID(USER_ID), strAcctID(ACCT_ID);
	
	// (0) Set up the REQUEST NUMBER and then INCREMENT IT
	pNym->GetCurrentRequestNum(strServerID, lRequestNumber);
	theMessage.m_strRequestNum.Format("%ld", lRequestNumber); // Always have to send this.
	pNym->IncrementRequestNum(*pNym, strServerID); // since I used it for a server request, I have to increment it
	
	// (1) set up member variables 
	theMessage.m_strCommand			= "processInbox";
	theMessage.m_strNymID			= strNymID;
	theMessage.m_strServerID		= strServerID;
	theMessage.m_strAcctID			= strAcctID;
	
	// Presumably ACCT_LEDGER was already set up before this function was called...
	// See test client for example of it being done.
	theMessage.m_ascPayload.SetString(ACCT_LEDGER);

	// (2) Sign the Message 
	theMessage.SignContract(*pNym);		
	
	// (3) Save the Message (with signatures and all, back to its internal member m_strRawFile.)
	theMessage.SaveContract();
	
	// (Send it)
	g_Client.ProcessMessageOut(theMessage);	
}




void OT_API_issueBasket(OTIdentifier	& SERVER_ID,
								   OTIdentifier	& USER_ID,
								   OTString		& BASKET_INFO)
{
	// -----------------------------------------------------------------
	
	OTServerContract * pServer = g_Wallet.GetServerContract(SERVER_ID);
	
	if (!pServer)
	{
		// todo error message
		
		return;
	}
	
	
	// -----------------------------------------------------------------
	
	OTPseudonym * pNym = g_Wallet.GetNymByID(USER_ID);
	
	if (!pNym)
	{
		// todo error message
		
		return;
	}
	
	// -----------------------------------------------------------------
	
	// AT SOME POINT, BASKET_INFO has been populated with the relevant data. (see test client for example.)
	
	OTString strServerID(SERVER_ID), strNymID(USER_ID);

	OTMessage theMessage;
	long lRequestNumber = 0;
	
	// (0) Set up the REQUEST NUMBER and then INCREMENT IT
	pNym->GetCurrentRequestNum(strServerID, lRequestNumber);
	theMessage.m_strRequestNum.Format("%ld", lRequestNumber); // Always have to send this.
	pNym->IncrementRequestNum(*pNym, strServerID); // since I used it for a server request, I have to increment it
	
	// (1) Set up member variables 
	theMessage.m_strCommand			= "issueBasket";
	theMessage.m_strNymID			= strNymID;
	theMessage.m_strServerID		= strServerID;
	
	theMessage.m_ascPayload.SetString(BASKET_INFO);
	
	// (2) Sign the Message 
	theMessage.SignContract(*pNym);		
	
	// (3) Save the Message (with signatures and all, back to its internal member m_strRawFile.)
	theMessage.SaveContract();
	
	// (Send it)
	g_Client.ProcessMessageOut(theMessage);
}



void OT_API_issueAssetType(OTIdentifier	&	SERVER_ID,
									  OTIdentifier	&	USER_ID,
									  OTString		&	THE_CONTRACT)
{
	// -----------------------------------------------------------------
	
	OTServerContract * pServer = g_Wallet.GetServerContract(SERVER_ID);
	
	if (!pServer)
	{
		// todo error message
		
		return;
	}
	
	
	// -----------------------------------------------------------------
	
	OTPseudonym * pNym = g_Wallet.GetNymByID(USER_ID);
	
	if (!pNym)
	{
		// todo error message
		
		return;
	}
	
	// -----------------------------------------------------------------
		
	OTAssetContract theAssetContract;
	
	if (theAssetContract.LoadContractFromString(THE_CONTRACT))
	{
		OTIdentifier	newID;
		theAssetContract.CalculateContractID(newID);
		
		// -----------------------
		OTMessage theMessage;
		long lRequestNumber = 0;
		
		OTString strServerID(SERVER_ID), strNymID(USER_ID);
		
		// (0) Set up the REQUEST NUMBER and then INCREMENT IT
		pNym->GetCurrentRequestNum(strServerID, lRequestNumber);
		theMessage.m_strRequestNum.Format("%ld", lRequestNumber); // Always have to send this.
		pNym->IncrementRequestNum(*pNym, strServerID); // since I used it for a server request, I have to increment it
		
		// (1) set up member variables 
		theMessage.m_strCommand			= "issueAssetType";
		theMessage.m_strNymID			= strNymID;
		theMessage.m_strServerID		= strServerID;
		
		newID.GetString(theMessage.m_strAssetID);
		OTString strAssetContract(theAssetContract);
		theMessage.m_ascPayload.SetString(strAssetContract);
		
		// (2) Sign the Message 
		theMessage.SignContract(*pNym);		
		
		// (3) Save the Message (with signatures and all, back to its internal member m_strRawFile.)
		theMessage.SaveContract();
		
		// (Send it)
		g_Client.ProcessMessageOut(theMessage);
	}
}



void OT_API_getContract(OTIdentifier & SERVER_ID,
								   OTIdentifier & USER_ID,
								   OTIdentifier & ASSET_ID)
{
	// -----------------------------------------------------------------
	
	OTServerContract * pServer = g_Wallet.GetServerContract(SERVER_ID);
	
	if (!pServer)
	{
		// todo error message
		
		return;
	}
	
	
	// -----------------------------------------------------------------
	
	OTPseudonym * pNym = g_Wallet.GetNymByID(USER_ID);
	
	if (!pNym)
	{
		// todo error message
		
		return;
	}
	
	// -----------------------------------------------------------------
	
	OTAssetContract * pAssetContract = g_Wallet.GetAssetContract(ASSET_ID);
	
	if (!pAssetContract)
	{
		// todo error message
		
		return;
	}
	
	// -----------------------------------------------------------------
	
	OTMessage theMessage;
	long lRequestNumber = 0;
	
	OTString strServerID(SERVER_ID), strNymID(USER_ID), strAssetTypeID(ASSET_ID);
	
	// (0) Set up the REQUEST NUMBER and then INCREMENT IT
	pNym->GetCurrentRequestNum(strServerID, lRequestNumber);
	theMessage.m_strRequestNum.Format("%ld", lRequestNumber); // Always have to send this.
	pNym->IncrementRequestNum(*pNym, strServerID); // since I used it for a server request, I have to increment it
	
	// (1) set up member variables 
	theMessage.m_strCommand			= "getContract";
	theMessage.m_strNymID			= strNymID;
	theMessage.m_strServerID		= strServerID;
	theMessage.m_strAssetID			= strAssetTypeID;
	
	// (2) Sign the Message 
	theMessage.SignContract(*pNym);		
	
	// (3) Save the Message (with signatures and all, back to its internal member m_strRawFile.)
	theMessage.SaveContract();
	
	// (Send it)
	g_Client.ProcessMessageOut(theMessage);	
}






void OT_API_getMint(OTIdentifier & SERVER_ID,
							   OTIdentifier & USER_ID,
							   OTIdentifier & ASSET_ID)
{
	// -----------------------------------------------------------------
	
	OTServerContract * pServer = g_Wallet.GetServerContract(SERVER_ID);
	
	if (!pServer)
	{
		// todo error message
		
		return;
	}
	
	
	// -----------------------------------------------------------------
	
	OTPseudonym * pNym = g_Wallet.GetNymByID(USER_ID);
	
	if (!pNym)
	{
		// todo error message
		
		return;
	}
	
	// -----------------------------------------------------------------
	
	OTAssetContract * pAssetContract = g_Wallet.GetAssetContract(ASSET_ID);
	
	if (!pAssetContract)
	{
		// todo error message
		
		return;
	}
	
	// -----------------------------------------------------------------
	
	OTMessage theMessage;
	long lRequestNumber = 0;
	
	OTString strServerID(SERVER_ID), strNymID(USER_ID), strAssetTypeID(ASSET_ID);
	
	// (0) Set up the REQUEST NUMBER and then INCREMENT IT
	pNym->GetCurrentRequestNum(strServerID, lRequestNumber);
	theMessage.m_strRequestNum.Format("%ld", lRequestNumber); // Always have to send this.
	pNym->IncrementRequestNum(*pNym, strServerID); // since I used it for a server request, I have to increment it
	
	// (1) set up member variables 
	theMessage.m_strCommand			= "getMint";
	theMessage.m_strNymID			= strNymID;
	theMessage.m_strServerID		= strServerID;
	theMessage.m_strAssetID			= strAssetTypeID;
	
	// (2) Sign the Message 
	theMessage.SignContract(*pNym);		
	
	// (3) Save the Message (with signatures and all, back to its internal member m_strRawFile.)
	theMessage.SaveContract();
	
	// (Send it)
	g_Client.ProcessMessageOut(theMessage);	
}





void OT_API_createAssetAccount(OTIdentifier & SERVER_ID,
										  OTIdentifier & USER_ID,
										  OTIdentifier & ASSET_ID)
{	
	// -----------------------------------------------------------------
	
	OTServerContract * pServer = g_Wallet.GetServerContract(SERVER_ID);
	
	if (!pServer)
	{
		// todo error message
		
		return;
	}
	
	
	// -----------------------------------------------------------------
	
	OTPseudonym * pNym = g_Wallet.GetNymByID(USER_ID);
	
	if (!pNym)
	{
		// todo error message
		
		return;
	}
	
	// -----------------------------------------------------------------
	
	OTAssetContract * pAssetContract = g_Wallet.GetAssetContract(ASSET_ID);
	
	if (!pAssetContract)
	{
		// todo error message
		
		return;
	}
	
	// -----------------------------------------------------------------
	
	OTMessage theMessage;
	long lRequestNumber = 0;
	
	OTString strServerID(SERVER_ID), strNymID(USER_ID), strAssetTypeID(ASSET_ID);
	
	// (0) Set up the REQUEST NUMBER and then INCREMENT IT
	pNym->GetCurrentRequestNum(strServerID, lRequestNumber);
	theMessage.m_strRequestNum.Format("%ld", lRequestNumber); // Always have to send this.
	pNym->IncrementRequestNum(*pNym, strServerID); // since I used it for a server request, I have to increment it
	
	// (1) set up member variables 
	theMessage.m_strCommand			= "createAccount";
	theMessage.m_strNymID			= strNymID;
	theMessage.m_strServerID		= strServerID;
	theMessage.m_strAssetID			= strAssetTypeID;
	
	// (2) Sign the Message 
	theMessage.SignContract(*pNym);		
	
	// (3) Save the Message (with signatures and all, back to its internal member m_strRawFile.)
	theMessage.SaveContract();
	
	// (Send it)
	g_Client.ProcessMessageOut(theMessage);
}





void OT_API_getAccount(OTIdentifier	& SERVER_ID,
								  OTIdentifier	& USER_ID,
								  OTIdentifier	& ACCT_ID)
{	
	// -----------------------------------------------------------------
	
	OTServerContract * pServer = g_Wallet.GetServerContract(SERVER_ID);
	
	if (!pServer)
	{
		// todo error message
		
		return;
	}
	
	
	// -----------------------------------------------------------------
	
	OTPseudonym * pNym = g_Wallet.GetNymByID(USER_ID);
	
	if (!pNym)
	{
		// todo error message
		
		return;
	}
	
	// -----------------------------------------------------------------
	
	OTAccount * pAccount = g_Wallet.GetAccount(ACCT_ID);
	
	if (!pAccount)
	{
		// todo error message
		
		return;
	}
	
	// -----------------------------------------------------------------
	
	OTMessage theMessage;
	long lRequestNumber = 0;
	
	OTString strServerID(SERVER_ID), strNymID(USER_ID), strAcctID(ACCT_ID);
	
	// (0) Set up the REQUEST NUMBER and then INCREMENT IT
	pNym->GetCurrentRequestNum(strServerID, lRequestNumber);
	theMessage.m_strRequestNum.Format("%ld", lRequestNumber); // Always have to send this.
	pNym->IncrementRequestNum(*pNym, strServerID); // since I used it for a server request, I have to increment it
	
	// (1) set up member variables 
	theMessage.m_strCommand			= "getAccount";
	theMessage.m_strNymID			= strNymID;
	theMessage.m_strServerID		= strServerID;
	theMessage.m_strAcctID			= strAcctID;
	
	// (2) Sign the Message 
	theMessage.SignContract(*pNym);		
	
	// (3) Save the Message (with signatures and all, back to its internal member m_strRawFile.)
	theMessage.SaveContract();
	
	// (Send it)
	g_Client.ProcessMessageOut(theMessage);
}


void OT_API_getRequest(OTIdentifier	& SERVER_ID,
								  OTIdentifier	& USER_ID)
{	
	// -----------------------------------------------------------------
	
	OTServerContract * pServer = g_Wallet.GetServerContract(SERVER_ID);
	
	if (!pServer)
	{
		// todo error message
		
		return;
	}
	
	
	// -----------------------------------------------------------------
	
	OTPseudonym * pNym = g_Wallet.GetNymByID(USER_ID);
	
	if (!pNym)
	{
		// todo error message
		
		return;
	}
	
	// -----------------------------------------------------------------
	
	OTMessage theMessage;
	
	if (g_Client.ProcessUserCommand(OTClient::getRequest, theMessage, 
									*pNym, *pServer,
									NULL)) // NULL pAccount on this command.
	{				
		g_Client.ProcessMessageOut(theMessage);
	}
	else
		fprintf(stderr, "Error processing getRequest command in OT_API_getRequest\n");
	
}



void OT_API_checkUser(OTIdentifier & SERVER_ID,
								 OTIdentifier & USER_ID,
								 OTIdentifier & USER_ID_CHECK)
{	
	// -----------------------------------------------------------------
	
	OTPseudonym * pNym = g_Wallet.GetNymByID(USER_ID);
	
	if (!pNym)
	{
		// todo error message
		
		return;
	}
	
	// -----------------------------------------------------------------
	
	OTMessage theMessage;
	long lRequestNumber = 0;

	OTString strServerID(SERVER_ID), strNymID(USER_ID), strNymID2(USER_ID_CHECK);
	
	// (0) Set up the REQUEST NUMBER and then INCREMENT IT
	pNym->GetCurrentRequestNum(strServerID, lRequestNumber);
	theMessage.m_strRequestNum.Format("%ld", lRequestNumber); // Always have to send this.
	pNym->IncrementRequestNum(*pNym, strServerID); // since I used it for a server request, I have to increment it
	
	// (1) set up member variables 
	theMessage.m_strCommand			= "checkUser";
	theMessage.m_strNymID			= strNymID;
	theMessage.m_strNymID2			= strNymID2;
	theMessage.m_strServerID		= strServerID;
	
	// (2) Sign the Message 
	theMessage.SignContract(*pNym);		
	
	// (3) Save the Message (with signatures and all, back to its internal member m_strRawFile.)
	theMessage.SaveContract();
		
	// (Send it)
	g_Client.ProcessMessageOut(theMessage);
}


void OT_API_createUserAccount(OTIdentifier	& SERVER_ID,
										 OTIdentifier	& USER_ID)
{	
	// -----------------------------------------------------------------
	
	OTServerContract * pServer = g_Wallet.GetServerContract(SERVER_ID);
	
	if (!pServer)
	{
		// todo error message
		
		return;
	}
	
	
	// -----------------------------------------------------------------
	
	OTPseudonym * pNym = g_Wallet.GetNymByID(USER_ID);
	
	if (!pNym)
	{
		// todo error message
		
		return;
	}
	
	// -----------------------------------------------------------------
	
	OTMessage theMessage;
	
	if (g_Client.ProcessUserCommand(OTClient::createUserAccount, theMessage, 
									*pNym, *pServer,
									NULL)) // NULL pAccount on this command.
	{				
		g_Client.ProcessMessageOut(theMessage);
	}
	else
		fprintf(stderr, "Error processing createUserAccount command in OT_API_createUserAccount\n");
	
}


void OT_API_checkServerID(OTIdentifier	& SERVER_ID,
									 OTIdentifier	& USER_ID)
{	
	// -----------------------------------------------------------------
	
	OTServerContract * pServer = g_Wallet.GetServerContract(SERVER_ID);
	
	if (!pServer)
	{
		// todo error message
		
		return;
	}
	
	
	// -----------------------------------------------------------------
	
	OTPseudonym * pNym = g_Wallet.GetNymByID(USER_ID);
	
	if (!pNym)
	{
		// todo error message
		
		return;
	}
	
	// -----------------------------------------------------------------
	
	OTMessage theMessage;
	
	if (g_Client.ProcessUserCommand(OTClient::checkServerID, theMessage, 
									*pNym, *pServer,
									NULL)) // NULL pAccount on this command.
	{				
		g_Client.ProcessMessageOut(theMessage);
	}
	else
		fprintf(stderr, "Error processing checkServerID command in OT_API_checkServerID\n");
	
}

