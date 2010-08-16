/************************************************************************************
 *    
 *  OTClient.cpp
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
#include <openssl/evp.h>
#include <openssl/pem.h>
#include <openssl/rsa.h>
#include <openssl/err.h>
#include <openssl/rand.h>
	
}

#include "OTClient.h"

#include "OTString.h"
#include "OTIdentifier.h"
#include "OTPseudonym.h"
#include "OTContract.h"
#include "OTAssetContract.h"
#include "OTServerContract.h"
#include "OTAccount.h"
#include "OTMessage.h"
#include "OTPayload.h"
#include "OTWallet.h"
#include "OTEnvelope.h"
#include "OTItem.h"
#include "OTLedger.h"
#include "OTMint.h"
#include "OTPurse.h"
#include "OTBasket.h"

#include "OTTransaction.h"
#include "OTCheque.h"


extern OTWallet g_Wallet;
extern OTPseudonym * g_pTemporaryNym;

// Without regard to WHAT those transactions ARE that are in my inbox,
// just process and accept them all!!!  (This is AUTO-ACCEPT functionality
// built into the test client and not the library itself.)
void OTClient::AcceptEntireInbox(OTLedger & theInbox, OTServerConnection & theConnection)
{
	OTPseudonym * pNym = theConnection.GetNym();

	OTIdentifier theAccountID(theInbox), theServerID;
	theConnection.GetServerID(theServerID);

	OTString strServerID(theServerID);
	long lStoredTransactionNumber=0;
	bool bGotTransNum = pNym->GetNextTransactionNum(*pNym, strServerID, lStoredTransactionNumber);
	
	if (!bGotTransNum)
	{
		fprintf(stderr, "Error: No transaction numbers are available. Suggest requesting the server for a new one.\n");
		return;
	}
	
	// the message to the server will contain a ledger to be processed for a specific acct.
	OTLedger processLedger(theInbox.GetUserID(), theAccountID, theServerID);	
	
	// bGenerateFile defaults to false on GenerateLedger call, so I left out the false.
	processLedger.GenerateLedger(theAccountID, theServerID, OTLedger::message);	// Can't just use one of these. It either has to be read out of a file or
																				// a string, or it has to be generated. So you construct it, then you either
																				// call GenerateLedger or LoadInbox, then you call VerifyContractID to make sure
																				// it loaded securely. (No need to verify if you just generated it.)
	
	OTTransaction *	pAcceptTransaction = OTTransaction::GenerateTransaction(theInbox.GetUserID(), 
																			theAccountID, theServerID, OTTransaction::processInbox, lStoredTransactionNumber);

	
	// This insures that the ledger will handle cleaning up the transaction, so I don't have to delete it later.
	processLedger.AddTransaction(*pAcceptTransaction);

	// loop through the transactions in theInbox, and create corresponding "accept" items
	// for each one of the transfer requests. Each of those items will go into a single
	// "process inbox" transaction that I will add to the processledger and thus to the 
	// outgoing message.
	OTTransaction * pTransaction = NULL;
	
	// For each transaction in the inbox, if it's in reference to a transfer request,
	// then create an "accept" item for that transfer request, and add it to my own, new,
	// "process inbox" transaction that I'm sending out.
	for (mapOfTransactions::iterator ii = theInbox.GetTransactionMap().begin(); 
		 ii != theInbox.GetTransactionMap().end(); ++ii)
	{
		// If this transaction references the item that I'm trying to accept...
		if ((pTransaction = (*ii).second) && (pTransaction->GetReferenceToNum()>0)) // if pointer not null AND it refers to some other transaction
		{
//			OTString strTransaction(*pTransaction);
//			fprintf(stderr, "TRANSACTION CONTENTS:\n%s\n", strTransaction.Get());
			
			OTString strRespTo;
			pTransaction->GetReferenceString(strRespTo);
//			fprintf(stderr, "TRANSACTION \"IN REFERENCE TO\" CONTENTS:\n%s\n", strRespTo.Get());	
			
			OTItem * pOriginalItem = OTItem::CreateItemFromString(strRespTo, theServerID, pTransaction->GetReferenceToNum());
			
			// This item was attached as the "in reference to" item. Perhaps Bob sent it to me.
			// Since that item was initiated by him, HIS would be the account ID on it, not mine.
			// So I DON'T want to create it with my account ID on it.
			if (pOriginalItem)
			{
				if ((OTItem::request == pOriginalItem->m_Status) &&
					
					// In a real client, the user would pick and choose which items he wanted
					// to accept or reject. We, on the other hand, are blindly accepting all of
					// these types:
					(OTItem::transfer		== pOriginalItem->m_Type  || // I'm accepting a transfer that was sent to me.
					 OTItem::accept			== pOriginalItem->m_Type  || // I'm accepting a notice that someone accepted my transfer.
					 OTItem::reject			== pOriginalItem->m_Type  || // I'm accepting a notice that someone rejected my transfer.
					 OTItem::depositCheque	== pOriginalItem->m_Type)	 // I'm accepting a notice that someone cashed a cheque I wrote.
					)
				{
					OTItem * pAcceptItem = OTItem::CreateItemFromTransaction(*pAcceptTransaction, OTItem::accept);
					// the transaction will handle cleaning up the transaction item.
					pAcceptTransaction->AddItem(*pAcceptItem);

					// Set up the "accept" transaction item to be sent to the server 
					// (this item references and accepts another item by its transaction number--
					//  one that is already there in my inbox)
					OTString strNote("Thanks for that money!"); // this message is from when only transfer worked.
					pAcceptItem->SetNote(strNote);
					pAcceptItem->SetReferenceToNum(pOriginalItem->GetTransactionNum()); // This is critical. Server needs this to look up the original.
					// Don't need to set transaction num on item since the constructor already got it off the owner transaction.
					 
					// I don't attach the original item here because I already reference it by transaction num,
					// and because the server already has it and sent it to me. SO I just need to give the server
					// enough info to look it up again.
					
					// sign the item
					pAcceptItem->SignContract(*(theConnection.GetNym()));
					pAcceptItem->SaveContract();
				}
				else {
					fprintf(stderr, "Unrecognized item type while processing inbox.\n"
							"(Only transfers, cheques, and accepts are operational inbox items at this time.)\n");
				}
				delete pOriginalItem; // make sure we clean this up...
				pOriginalItem = NULL;
			}
			else 
			{
				fprintf(stderr, "Error loading transaction item from string in OTClient::AcceptEntireInbox\n");
			}
		} // if pTransaction
		if (pTransaction)
		{
			HarvestTransactionNumbers(*pTransaction, *pNym);	
		}
	}
	
	if (pAcceptTransaction->GetItemCount())
	{
		OTMessage theMessage;
		OTAccount * pAccount				= theConnection.GetWallet()->GetAccount(theAccountID);
		OTAssetContract * pAssetContract	= theConnection.GetWallet()->GetAssetContract(pAccount->GetAssetTypeID());
		
		if (pAccount && ProcessUserCommand(OTClient::processInbox, theMessage, 
										   *(theConnection.GetNym()), 
//										   *(pAssetContract),
										   *(theConnection.GetServerContract()), 
										     pAccount)) 
		{
			// the message is all set up and ready to go out... it's even signed.
			// Except the ledger we're sending, still needs to be added, and then the
			// message needs to be re-signed as a result of that.
			
			// Sign the accept transaction, as well as the message ledger 
			// that we've just constructed containing it.
			pAcceptTransaction->SignContract(*(theConnection.GetNym()));
			processLedger.SignContract(*(theConnection.GetNym()));
			pAcceptTransaction->SaveContract();
			processLedger.SaveContract();
			
			// Extract the ledger into string form and add it as the payload on the message.
			OTString strLedger(processLedger);
			theMessage.m_ascPayload.SetString(strLedger);
			
			// Release any other signatures from the message, since I know it
			// was signed already in the above call to ProcessUserCommand.
			theMessage.ReleaseSignatures();
			
			// Sign it and send it out.
			theConnection.SignAndSend(theMessage);
			// I could have called SignContract() and then theConnection.ProcessMessageOut(message) 
			// but I used the above function instead.
		}
		else
			fprintf(stderr, "Error processing processInbox command in OTClient::AcceptEntireInbox\n");
	}
}

// We have received the server reply (ProcessServerReply) which has vetted it and determined that it
// is legitimate and safe, and that it is a reply to a transaction request.
//
// At that point, this function is called to open the reply, go through the transaction responses,
// and potentially grab any bearer certificates that are inside and save them in a purse somewhere.
void OTClient::ProcessIncomingTransactions(OTServerConnection & theConnection, OTMessage & theReply)
{
	const OTIdentifier ACCOUNT_ID(theReply.m_strAcctID);
	OTIdentifier SERVER_ID;
	theConnection.GetServerID(SERVER_ID);
	OTPseudonym * pNym = theConnection.GetNym();
	OTIdentifier USER_ID;
	pNym->GetIdentifier(USER_ID);
	OTPseudonym * pServerNym = (OTPseudonym *)(theConnection.GetServerContract()->GetContractPublicNym());

	// The only incoming transactions that we actually care about are responses to cash
	// WITHDRAWALS.  (Cause we want to get that money off of the response, not lose it.)
	// So let's just check to see if it's a withdrawal...
	OTLedger theLedger(USER_ID, ACCOUNT_ID, SERVER_ID);	
	OTString strLedger(theReply.m_ascPayload);
	
	// The ledger we received from the server was generated there, so we don't
	// have to call GenerateLedger. We just load it.
	bool bSuccess = theLedger.LoadContractFromString(strLedger);
	
	if (bSuccess)
		bSuccess = theLedger.VerifyAccount((OTPseudonym &)*pServerNym);
	
	if (!bSuccess)
	{
		fprintf(stderr, "ERROR loading ledger from message payload in OTClient::ProcessIncomingTransactions.\n");
		return;
	}
	
//	fprintf(stderr, "Loaded ledger out of message payload.\n");
	
	// TODO: Loop through ledger transactions, 		
	OTTransaction * pTransaction	= NULL;
	
	for (mapOfTransactions::iterator ii = theLedger.GetTransactionMap().begin(); 
		 ii != theLedger.GetTransactionMap().end(); ++ii)
	{	
		// for each transaction in the ledger, we create a transaction response and add
		// that to the response ledger.
		if ((pTransaction = (*ii).second) && pTransaction->VerifyAccount(*pServerNym)) // if not null && valid transaction reply from server
		{
			// It's a withdrawal...
			if (OTTransaction::atWithdrawal == pTransaction->GetType())
			{
				ProcessWithdrawalResponse(*pTransaction, theConnection, theReply);
			}			
			// It's a deposit...
			else if (OTTransaction::atDeposit == pTransaction->GetType())
			{
				ProcessDepositResponse(*pTransaction, theConnection, theReply);
			}
			
			// No matter what kind of transaction it is,
			// let's see if the server gave us some new transaction numbers with it...
			HarvestTransactionNumbers(*pTransaction, *pNym);
		}
		else {
			fprintf(stderr, "NULL transaction pointer in OTServer::UserCmdNotarizeTransactions\n");
		}		
	}
}


// Usually a transaction from the server includes some new transaction numbers.
// Use this function to harvest them.
void OTClient::HarvestTransactionNumbers(OTTransaction & theTransaction, OTPseudonym & theNym)
{
	// loop through the ALL items that make up this transaction and check to see if a response to deposit.
	OTItem * pItem = NULL;
	
	// if pointer not null, and it's a withdrawal, and it's an acknowledgement (not a rejection or error)
	for (listOfItems::iterator ii = theTransaction.GetItemList().begin(); ii != theTransaction.GetItemList().end(); ++ii)
	{
		if ((pItem = *ii) && (OTItem::atTransaction == pItem->GetType()))
		{ 
			if (OTItem::acknowledgement == pItem->GetStatus())
			{
				fprintf(stderr, "SUCCESS -- Received new transaction number(s) from Server for storage.\n");
				
				OTString strAttachment;
				pItem->GetAttachment(strAttachment);
				if (strAttachment.GetLength())
				{
					OTPseudonym thePseudonym;
					
					if (thePseudonym.LoadFromString(strAttachment))
					{
						theNym.HarvestTransactionNumbers(theNym, thePseudonym);
					}
				}
			}
			else {
				fprintf(stderr, "FAILURE -- Server refuses to send transaction num.\n"); // in practice will never occur.
			}
		}
	}	
}


void OTClient::ProcessDepositResponse(OTTransaction & theTransaction, OTServerConnection & theConnection, OTMessage & theReply)
{
	const OTIdentifier ACCOUNT_ID(theReply.m_strAcctID);
	OTIdentifier SERVER_ID;
	theConnection.GetServerID(SERVER_ID);
	const OTPseudonym * pNym = theConnection.GetNym();
	OTIdentifier USER_ID;
	pNym->GetIdentifier(USER_ID);
//	OTWallet * pWallet = theConnection.GetWallet();
	
	// loop through the ALL items that make up this transaction and check to see if a response to deposit.
	OTItem * pItem = NULL;
	
	// if pointer not null, and it's a withdrawal, and it's an acknowledgement (not a rejection or error)
	for (listOfItems::iterator ii = theTransaction.GetItemList().begin(); ii != theTransaction.GetItemList().end(); ++ii)
	{
		if ((pItem = *ii) && (OTItem::atDeposit == pItem->GetType()))
		{ 
			if (OTItem::acknowledgement == pItem->GetStatus())
			{
				fprintf(stderr, "SUCCESS -- Server acknowledges deposit.\n");
			}
			else {
				fprintf(stderr, "FAILURE -- Server rejects deposit.\n");
			}

		}
	}
}


// It's definitely a withdrawal, we just need to iterate through the items in the transaction and
// grab any cash tokens that are inside, to save inside a purse.  Also want to display any vouchers.
void OTClient::ProcessWithdrawalResponse(OTTransaction & theTransaction, OTServerConnection & theConnection, OTMessage & theReply)
{
	const OTIdentifier ACCOUNT_ID(theReply.m_strAcctID);
	OTIdentifier SERVER_ID;
	theConnection.GetServerID(SERVER_ID);
	const OTPseudonym * pNym = theConnection.GetNym();
	OTIdentifier USER_ID;
	pNym->GetIdentifier(USER_ID);
	OTWallet * pWallet = theConnection.GetWallet();
	OTPseudonym * pServerNym = (OTPseudonym *)(theConnection.GetServerContract()->GetContractPublicNym());

	// loop through the ALL items that make up this transaction and check to see if a response to withdrawal.
	OTItem * pItem = NULL;
	
	// if pointer not null, and it's a withdrawal, and it's an acknowledgement (not a rejection or error)
	for (listOfItems::iterator ii = theTransaction.GetItemList().begin(); ii != theTransaction.GetItemList().end(); ++ii)
	{
		pItem = *ii;
		
		// If we got a reply to a voucher withdrawal, we'll just display the the voucher
		// on the screen (if the server sent us one...)
		if ((pItem) && 
			(OTItem::atWithdrawVoucher	== pItem->GetType()) &&
			(OTItem::acknowledgement	== pItem->GetStatus()))
		{ 
			OTString	strVoucher;
			pItem->GetAttachment(strVoucher);
			
			OTCheque	theVoucher;
			if (theVoucher.LoadContractFromString(strVoucher))
			{
				fprintf(stdout, "\nReceived voucher from server:\n\n%s\n\n", strVoucher.Get());				
			}
		}
		
		// ----------------------------------------------------------------------------------------
		
		// If the item is a response to a cash withdrawal, we want to save the coins into a purse
		// somewhere on the computer. That's cash! Gotta keep it safe.
		
		else if ((pItem) && 
				 (OTItem::atWithdrawal		== pItem->GetType()) &&
				 (OTItem::acknowledgement	== pItem->GetStatus()))
		{ 
			OTString	strPurse;
			pItem->GetAttachment(strPurse);
			
			OTPurse		thePurse(SERVER_ID);
			if (thePurse.LoadContractFromString(strPurse))
			{
				// When we made the withdrawal request, we saved that purse pointer in the
				// wallet so that we could get to the private coin unblinding data when we 
				// needed it (now).
				OTPurse * pRequestPurse		= pWallet->GetPendingWithdrawal();
				OTToken * pToken			= NULL;
				OTToken * pOriginalToken	= NULL;
				
				OTString strMintPath, ASSET_ID(thePurse.GetAssetID());
				
				strMintPath.Format("%s%smints%s%s", OTPseudonym::OTPath.Get(), OTPseudonym::OTPathSeparator.Get(),
								   OTPseudonym::OTPathSeparator.Get(), ASSET_ID.Get());
				OTMint theMint(ASSET_ID, strMintPath, ASSET_ID);

				OTString strPursePath;
				strPursePath.Format("%s%spurse%s%s", OTPseudonym::OTPath.Get(), OTPseudonym::OTPathSeparator.Get(), 
									OTPseudonym::OTPathSeparator.Get(), ASSET_ID.Get());
				
				// Unlike the purse which we read out of a message,
				// now we try to open a purse as a file on the client side,
				// keyed by Asset ID.  (The client should already have one
				// purse file for each asset type, if he already has cash.)
				// 
				// We don't want to just overwrite that file. So instead, we
				// try to load that purse first, then add the token, then save it
				// again.
				OTPurse theWalletPurse(thePurse);
				// TODO verify the wallet purse when loaded. My signature should be the last thing on it.
				
				// TODO: I don't check this for failure. If the file doesn't exist,
				// we are still going to save the purse there regardless.
				// HOWEVER need to make sure the wallet software has good backup
				// strategy.  In the event that tokens are overwritten here, it
				// shouldn't be a problem since they would be in the archive somewhere.
				theWalletPurse.LoadContract(strPursePath.Get());
//					if Load, theWalletPurse.VerifySignature();

				bool bSuccess = false;
				
				if ((NULL != pRequestPurse) && pServerNym && theMint.LoadContract() && theMint.VerifyMint(*pServerNym))
				while (pToken = thePurse.Pop(*pNym))
				{
					pOriginalToken = pRequestPurse->Pop(*pNym);
					
					if (NULL == pOriginalToken)
					{
						fprintf(stderr, "ERROR, processing withdrawal response, but couldn't find original token:%s\n", strPurse.Get());
					}
					else if (OTToken::signedToken == pToken->GetState())
					{
						fprintf(stderr, "Retrieved signed token from purse, and have corresponding withdrawal request in wallet. Unblinding...\n\n");
						
						if (pToken->ProcessToken(*pNym, theMint, *pOriginalToken))
						{
							// Now that it's processed, let's save it again.
							pToken->ReleaseSignatures();
							pToken->SignContract(*pNym);
							pToken->SaveContract();
							
							bSuccess = true;
							
							// add it to the existing client-side purse for storing tokens of that asset type
							theWalletPurse.Push(*pNym, *pToken);
						}
						else 
						{
							bSuccess = false;
							if (pToken)
							{
								delete pToken;
								pToken = NULL;
							}
							// The while loop starts by allocating a pOriginalToken, so I want to 
							// delete it for each iteration and keep things clean.
							if (pOriginalToken)
							{
								delete pOriginalToken;
								pOriginalToken = NULL;
							}							
							break;
						}
					}
					
					// The while loop starts by allocating a pToken, so I want to 
					// delete it for each iteration and keep things clean.
					if (pToken)
					{
						delete pToken;
						pToken = NULL;
					}
					// The while loop starts by allocating a pOriginalToken, so I want to 
					// delete it for each iteration and keep things clean.
					if (pOriginalToken)
					{
						delete pOriginalToken;
						pOriginalToken = NULL;
					}
				} // while (pToken = thePurse.Pop(*pNym))
				
				if (bSuccess)
				{
					// Sign it, save it.
					theWalletPurse.ReleaseSignatures(); // Might as well, they're no good anyway once the data has changed.
					theWalletPurse.SignContract(*pNym);
					theWalletPurse.SaveContract(strPursePath.Get());
					
					fprintf(stderr, "SUCCESSFULLY UNBLINDED token, and added the cash to the local purse, and saved.\n");					
				}
			} // if (thePurse.LoadContractFromString(strPurse))
		}
	} // for
}

// We have just received a message from the server.
// Find out what it is and do the appropriate processing.
// Perhaps we just tried to create an account -- this could be
// our new account! Let's make sure we receive it and save it
// to disk somewhere.
bool OTClient::ProcessServerReply(OTServerConnection & theConnection, OTMessage & theReply)
{
	const OTIdentifier ACCOUNT_ID(theReply.m_strAcctID);
	OTIdentifier SERVER_ID;
	theConnection.GetServerID(SERVER_ID);
	OTPseudonym * pNym = theConnection.GetNym();
	OTIdentifier USER_ID;
	pNym->GetIdentifier(USER_ID);
	OTPseudonym * pServerNym = (OTPseudonym *)(theConnection.GetServerContract()->GetContractPublicNym());


	// Just like the server verifies all messages before processing them,
	// so does the client need to verify the signatures against each message
	// and verify the various contract IDs and signatures.
	if (!theReply.VerifySignature(*pServerNym)) 
	{
		fprintf(stderr, "Error: Server reply signature failed to verify in OTClient::ProcessServerReply\n");
		return false;
	}
	
	// Once that process is done, everything below that line, in this function,
	// will be able to assume there is a verified Nym available, and a Server Contract,
	// and an asset contract where applicable, and an account where applicable.
	//
	// Until that code is written, I do not have those things available to me.
	//
	// Furthermore also need to verify the payloads...
	// If "Command Responding To" was not actually signed by me, and I wasn't
	// expecting the new account request, then I do NOT want to sign it.
	//
	// Also if the new account is not signed by the server, I don't want to sign
	// it either. Need to check for all these things. Right now just proof of concept.
	
	// Also, assuming all the verification shit is done here, I will have the Nym
	// Wait a second, I think I have the Nym already cause there's a pointer on
	// the server connection that was passed in here...

	if (theReply.m_bSuccess && theReply.m_strCommand.Compare("@getRequest"))
	{
		long lNewRequestNumber = atol(theReply.m_strRequestNum.Get());
		
		// so the proper request number is sent next time, we take the one that
		// the server just sent us, and we ask the wallet to save it somewhere safe 
		// (like in the nymfile)
		
		// In the future, I will have to write a function on the wallet that actually
		// takes the reply, looks up the associated nym in the wallet, verifies
		// that it was EXPECTING a response to GetRequest, (cause otherwise it won't
		// know which one to update) and then updates the request number there.
		// In the meantime there is only one connection, and it already has a pointer to
		// the Nym,  so I'll just tell it to update the request number that way for now.
		
		theConnection.OnServerResponseToGetRequestNumber(lNewRequestNumber);
		
		return true;
	}
	else if (theReply.m_bSuccess && theReply.m_strCommand.Compare("@getTransactionNum"))
	{
		OTString strMessageNym(theReply.m_ascPayload);
		
		OTPseudonym theMessageNym;
		
		if (theMessageNym.LoadFromString(strMessageNym))
			pNym->HarvestTransactionNumbers(*pNym, theMessageNym);
		
		return true;
	}
	else if (theReply.m_bSuccess && theReply.m_strCommand.Compare("@notarizeTransactions"))
	{
		ProcessIncomingTransactions(theConnection, theReply);
		
		return true;
	}
	else if (theReply.m_bSuccess && theReply.m_strCommand.Compare("@getInbox"))
	{
		OTString strReply(theReply), strAck;
		strAck.Format("Received server acknowledgment of Get Inbox command:\n%s\n", strReply.Get());
		
		fprintf(stderr, "%s", strAck.Get());
		
		// base64-Decode the server reply's payload into strInbox
		OTString strInbox(theReply.m_ascPayload);
		
//		fprintf(stderr, "INBOX CONTENTS:\n%s\n", strInbox.Get());
		
		// Load the ledger object from that string.				
		OTLedger theInbox(USER_ID, ACCOUNT_ID, SERVER_ID);	
		
		// Obviously a real client will never do something as foolish as this below...
		// (Accepting the entire inbox automatically--literally sending a signed message right
		// back to the server accepting whatever was inside this ledger, without giving the user
		// the opportunity to examine and reject those inbox items.)
		// This could empty your account!  But of course for testing, I want to get the inbox
		// and process it at the same time, since I already know what all the transactions are
		// supposed to be.
		if (theInbox.LoadContractFromString(strInbox) && theInbox.VerifyAccount(*pServerNym))
			AcceptEntireInbox(theInbox, theConnection);// Perhaps just Verify Contract so it verifies signature too, and ServerID too if I override it and add that...
				
		return true;
	}
	else if (theReply.m_bSuccess && theReply.m_strCommand.Compare("@getContract"))
	{
		// base64-Decode the server reply's payload into strContract
		OTString strContract(theReply.m_ascPayload);
		
		OTString strFilename;
		strFilename.Format("%s%scontracts%s%s", OTPseudonym::OTPath.Get(), OTPseudonym::OTPathSeparator.Get(), 
						   OTPseudonym::OTPathSeparator.Get(), theReply.m_strAssetID.Get());
		
		// Load the contract object from that string.	
		OTAssetContract * pContract = new OTAssetContract(theReply.m_strAssetID, strFilename, theReply.m_strAssetID);
		
		// Check the server signature on the contract here. (Perhaps the message is good enough?
		// After all, the message IS signed by the server and contains the Account.
		if (pContract && pContract->LoadContractFromString(strContract) && pContract->VerifyContract())
		{
			fprintf(stdout, "Saving asset contract to disk...\n");
			pContract->SaveContract(strFilename.Get());
			
			// Next let's make sure the wallet's copy of this account is replaced with the new one...
			OTWallet * pWallet;
			
			if (pWallet = theConnection.GetWallet())
			{
				pWallet->AddAssetContract(*pContract);
				pContract = NULL; // Success. The wallet "owns" it now, no need to clean it up.

				g_Wallet.SaveWallet(g_Wallet.m_strFilename.Get());
			}
		}
		// cleanup
		if (pContract)
		{
			delete pContract;
			pContract = NULL;
		}
		return true;
	}
	else if (theReply.m_bSuccess && theReply.m_strCommand.Compare("@getMint"))
	{
		// base64-Decode the server reply's payload into strMint
		OTString strMint(theReply.m_ascPayload);
		
		OTString strFilename;
		strFilename.Format("%s%smints%s%s", OTPseudonym::OTPath.Get(), OTPseudonym::OTPathSeparator.Get(), 
						   OTPseudonym::OTPathSeparator.Get(), theReply.m_strAssetID.Get());
		
		// Load the account object from that string.				
		OTMint theMint(theReply.m_strAssetID, strFilename, theReply.m_strAssetID);
		
		// TODO check the server signature on the account here. (Perhaps the message is good enough?
		// After all, the message IS signed by the server and contains the Account.
		if (theMint.LoadContractFromString(strMint))
		{
			fprintf(stdout, "Saving mint file to disk...\n");
			theMint.SaveContract(strFilename.Get());
		}
		return true;
	}
	else if (theReply.m_bSuccess && theReply.m_strCommand.Compare("@issueAssetType"))
	{
		if (theReply.m_ascPayload.GetLength())
		{
			OTAccount	* pAccount = NULL;
			
			// this decodes the ascii-armor payload where the new account file
			// is stored, and returns a normal string in strAcctContents.
			OTString	strAcctContents(theReply.m_ascPayload);
			
			// TODO check return value
			pAccount = new OTAccount(USER_ID, ACCOUNT_ID, SERVER_ID);
			
			if (pAccount->LoadContractFromString(strAcctContents) && pAccount->VerifyAccount(*pServerNym))
			{
				// (2) Sign the Account 
				pAccount->SignContract(*g_pTemporaryNym);		
				pAccount->SaveContract();
				
				// (3) Save the Account to file
				OTString strPath, strID;
				pAccount->GetIdentifier(strID);
				strPath.Format((char*)"%s%saccounts%s%s", OTPseudonym::OTPath.Get(), OTPseudonym::OTPathSeparator.Get(), 
							   OTPseudonym::OTPathSeparator.Get(), strID.Get());
				pAccount->SaveContract(strPath.Get()); // Saving to strPath would save the account into the 
				// strPath variable. (Which we don't want to do...)
				// Instead of passing an OTString, I pass a char*.
				// That's cause saving to strPath.Get() saves into the filename
				// that's stored in the strPath variable. (Opens that file.)
				
				// Need to consider other security considerations.
				// What if I wasn't EXPECTING a @createAccount message?
				// Well actually, in that case, the server wouldn't have a
				// copy of my request to send back to me, would he? So I should
				// check that request to make sure it's good.
				// Also maybe should check to see if I was expecting this message
				// in the first place.
				
				g_Wallet.AddAccount(*pAccount);
				
				g_Wallet.SaveWallet(g_Wallet.m_strFilename.Get());
				
				return true;
			}
			else {
				delete pAccount;
				pAccount = NULL;
			}
			
		}
	}
	
	else if (theReply.m_bSuccess && theReply.m_strCommand.Compare("@getAccount"))
	{
		// base64-Decode the server reply's payload into strAccount
		OTString strAccount(theReply.m_ascPayload);
		
		//		fprintf(stderr, "ACCOUNT CONTENTS:\n%s\n", strAccount.Get());
		
		// Load the account object from that string.				
		OTAccount * pAccount = new OTAccount(USER_ID, ACCOUNT_ID, SERVER_ID);
		
		// TODO check the server signature on the account here. (Perhaps the message is good enough?
		// After all, the message IS signed by the server and contains the Account.
		if (pAccount && pAccount->LoadContractFromString(strAccount) && pAccount->VerifyAccount(*pServerNym))
		{
			fprintf(stderr, "Saving updated account file to disk...\n");
			pAccount->ReleaseSignatures();	// So I don't get the annoying failure to verify message from the server's signature.
											// Will eventually end up keeping the signature, however, just for reasons of proof. todo.
			pAccount->SignContract(*pNym);
			pAccount->SaveAccount();
			
			// Next let's make sure the wallet's copy of this account is replaced with the new one...
			OTWallet * pWallet;
			
			if (pWallet = theConnection.GetWallet())
			{
				pWallet->AddAccount(*pAccount);
				pAccount = NULL; // Success. The wallet "owns" it now, no need to clean it up.
			}
		}
		// cleanup
		if (pAccount)
		{
			delete pAccount;
			pAccount = NULL;
		}
		return true;
	}
	else if (theReply.m_bSuccess && theReply.m_strCommand.Compare("@createAccount"))
	{
		if (theReply.m_ascPayload.GetLength())
		{
			OTAccount	* pAccount = NULL;
			
			// this decodes the ascii-armor payload where the new account file
			// is stored, and returns a normal string in strAcctContents.
			OTString	strAcctContents(theReply.m_ascPayload);
			
			pAccount = new OTAccount(USER_ID, ACCOUNT_ID, SERVER_ID);
			
			if (pAccount && pAccount->LoadContractFromString(strAcctContents) && pAccount->VerifyAccount(*pServerNym))
			{
				// (2) Sign the Account
				pAccount->ReleaseSignatures();	// So I don't get the annoying failure to verify message from the server's signature.
												// Will eventually end up keeping the signature, however, just for reasons of proof. todo.
				pAccount->SignContract(*g_pTemporaryNym);		
				pAccount->SaveContract();
				
				// (3) Save the Account to file
				OTString strPath, strID;
				pAccount->GetIdentifier(strID);
				strPath.Format((char*)"%s%saccounts%s%s", OTPseudonym::OTPath.Get(), OTPseudonym::OTPathSeparator.Get(), 
							   OTPseudonym::OTPathSeparator.Get(), strID.Get());
				pAccount->SaveContract(strPath.Get()); // Saving to strPath would save the account into the 
				// strPath variable. (Which we don't want to do...)
				// Instead of passing an OTString, I pass a char*.
				// That's cause saving to strPath.Get() saves into the filename
				// that's stored in the strPath variable. (Opens that file.)
				
				// Need to consider other security considerations.
				// What if I wasn't EXPECTING a @createAccount message?
				// Well actually, in that case, the server wouldn't have a
				// copy of my request to send back to me, would he? So I should
				// check that request to make sure it's good.
				// Also maybe should check to see if I was expecting this message
				// in the first place.
				
				g_Wallet.AddAccount(*pAccount);
				
				g_Wallet.SaveWallet(g_Wallet.m_strFilename.Get());
				
				return true;
			}
			else {
				delete pAccount;
				pAccount = NULL;
			}
			
		}
	}
	else {

	}
	return false;
}



// This function sets up "theMessage" so that it is ready to be sent out to the server.
// If you want to set up a checkServerID command and send it to the server, then
// you just call this to get the OTMessage object all set up and ready to be sent.
bool OTClient::ProcessUserCommand(OTClient::OT_CLIENT_CMD_TYPE requestedCommand,
								  OTMessage & theMessage,
								  OTPseudonym & theNym,
//								  OTAssetContract & theContract,
								  OTServerContract & theServer,
								  OTAccount * pAccount/*=NULL*/)
{
	// This is all preparatory work to get the various pieces of data together -- only
	// then can we put those pieces into a message.
	OTIdentifier CONTRACT_ID;
	OTString strNymID, strContractID, strServerID, strNymPublicKey, strAccountID;
	long lRequestNumber = 0;
	
	theNym.GetIdentifier(strNymID);
	theServer.GetIdentifier(strServerID);
	
	if (NULL != pAccount)
	{
		pAccount->GetIdentifier(strAccountID);
	}

	theNym.GetPublicKey().GetPublicKey(strNymPublicKey);
	
	bool bSendCommand = false;
	
	if (OTClient::checkServerID == requestedCommand)
	{
//		fprintf(stderr, "(User has instructed to send a checkServerID command to the server...)\n");
		
		// (1) set up member variables 
		theMessage.m_strCommand			= "checkServerID";
		theMessage.m_strNymID			= strNymID;
		theMessage.m_strServerID		= strServerID;
		theMessage.m_strNymPublicKey	= strNymPublicKey;
		
		// (2) Sign the Message 
		// When a message is signed, it updates its m_xmlUnsigned contents to
		// the values in the member variables
		theMessage.SignContract(theNym);		
		
		// (3) Save the Message (with signatures and all, back to its internal member m_strRawFile.)
		//
		// FYI, SaveContract takes m_xmlUnsigned and wraps it with the signatures and ------- BEGIN  bookends
		// If you don't pass a string in, then SaveContract saves the new version to its member, m_strRawFile
		theMessage.SaveContract();
		
		bSendCommand = true;
	}

	// ------------------------------------------------------------------------
	
	else if (OTClient::createUserAccount == requestedCommand)
	{
//		fprintf(stderr, "(User has instructed to send a createUserAccount command to the server...)\n");
		
		// (1) set up member variables 
		theMessage.m_strCommand			= "createUserAccount";
		theMessage.m_strNymID			= strNymID;
		theMessage.m_strServerID		= strServerID;
		theMessage.m_strNymPublicKey	= strNymPublicKey;
		
		// (2) Sign the Message 
		theMessage.SignContract(theNym);		
		
		// (3) Save the Message (with signatures and all, back to its internal member m_strRawFile.)
		theMessage.SaveContract();
		
		bSendCommand = true;
	}
	
	// ------------------------------------------------------------------------
	
	else if (OTClient::getRequest == requestedCommand)
	{
		//		fprintf(stderr, "(User has instructed to send a getRequest command to the server...)\n");
		
		// (1) set up member variables 
		theMessage.m_strCommand			= "getRequest";
		theMessage.m_strNymID			= strNymID;
		theMessage.m_strServerID		= strServerID;
		
		// (2) Sign the Message 
		theMessage.SignContract(theNym);		
		
		// (3) Save the Message (with signatures and all, back to its internal member m_strRawFile.)
		theMessage.SaveContract();
		
		bSendCommand = true;
	}
	
	// ------------------------------------------------------------------------
	
	// **************************************************************************************
	// EVERY COMMAND BELOW THIS POINT (THEY ARE ALL OUTGOING TO THE SERVER) MUST INCLUDE THE
	// CORRECT REQUEST NUMBER, OR BE REJECTED BY THE SERVER.
	//
	// The same commands must also increment the local counter of the request number by calling theNym.IncrementRequestNum
	// Otherwise it will get out of sync, and future commands will start failing (until it is resynchronized with
	// a getRequest message to the server, which replies with the latest number. The code on this side that processes
	// that server reply is already smart enough to update the local nym's copy of the request number when it is received.
	// In this way, the client becomes resynchronized and the next command will work again. But it's better to increment the
	// counter properly.
	// PROPERLY == every time you actually get the request number from a nym and use it to make a server request,
	// then you should therefore also increment that counter. If you call GetCurrentRequestNum AND USE IT WITH THE SERVER,
	// then make sure you call IncrementRequestNum immediately after. Otherwise future commands will start failing.
	//
	// This is all because the server requres a new request number (last one +1) with each request. This is in
	// order to thwart would-be attackers who cannot break the crypto, but try to capture encrypted messages and
	// send them to the server twice. Better that new requests requre new request numbers :-)
	
	else if (OTClient::checkUser == requestedCommand) // CHECK USER
	{
		fprintf(stdout, "Please enter a NymID: ");
		
		// User input.
		// I need a second NymID, so I allow the user to enter it here.
		OTString strNymID2;
		strNymID2.OTfgets(stdin);
		
		// (0) Set up the REQUEST NUMBER and then INCREMENT IT
		theNym.GetCurrentRequestNum(strServerID, lRequestNumber);
		theMessage.m_strRequestNum.Format("%ld", lRequestNumber); // Always have to send this.
		theNym.IncrementRequestNum(theNym, strServerID); // since I used it for a server request, I have to increment it

//		fprintf(stderr, "DEBUG: Sending request number: %ld\n", lRequestNumber);
		
		// (1) set up member variables 
		theMessage.m_strCommand			= "checkUser";
		theMessage.m_strNymID			= strNymID;
		theMessage.m_strNymID2			= strNymID2;
		theMessage.m_strServerID		= strServerID;
		
		// (2) Sign the Message 
		theMessage.SignContract(theNym);		
		
		// (3) Save the Message (with signatures and all, back to its internal member m_strRawFile.)
		theMessage.SaveContract();
		
		bSendCommand = true;
	}
	
	// ------------------------------------------------------------------------
	
	// The standard "contract" key inside the new currency contract must be the same key
	// used by the Nym who is signing the requests to issue the currency.
	else if (OTClient::issueAssetType == requestedCommand) // ISSUE ASSET TYPE
	{				
		fprintf(stdout, "Please enter currency contract, terminate with ~ on a new line:\n> ");
		OTString strSourceContract;
		char decode_buffer[200];
		
		do {
			fgets(decode_buffer, sizeof(decode_buffer), stdin);
			
			if (decode_buffer[0] != '~')
			{
				strSourceContract.Concatenate("%s", decode_buffer);
				fprintf(stdout, "> ");
			}
		} while (decode_buffer[0] != '~');
		
		OTAssetContract theAssetContract;
		
		if (theAssetContract.LoadContractFromString(strSourceContract))
		{
			OTIdentifier	newID;
			theAssetContract.CalculateContractID(newID);
			
			// (0) Set up the REQUEST NUMBER and then INCREMENT IT
			theNym.GetCurrentRequestNum(strServerID, lRequestNumber);
			theMessage.m_strRequestNum.Format("%ld", lRequestNumber); // Always have to send this.
			theNym.IncrementRequestNum(theNym, strServerID); // since I used it for a server request, I have to increment it
			
			// (1) Set up member variables 
			theMessage.m_strCommand			= "issueAssetType";
			theMessage.m_strNymID			= strNymID;
			theMessage.m_strServerID		= strServerID;
			newID.GetString(theMessage.m_strAssetID);
			OTString strAssetContract(theAssetContract);
			theMessage.m_ascPayload.SetString(strAssetContract);
			
			// (2) Sign the Message 
			theMessage.SignContract(theNym);		
			
			// (3) Save the Message (with signatures and all, back to its internal member m_strRawFile.)
			theMessage.SaveContract();
			
			bSendCommand = true;			
		}		
	}
	
	// ------------------------------------------------------------------------
	
	else if (OTClient::exchangeBasket == requestedCommand) // EXCHANGE BASKET
	{				
		OTString strBasketInfo;
		OTString str_BASKET_CONTRACT_ID, str_MAIN_ACCOUNT_ID, strTemp;
		
		// FIRST get the Asset Type ID for the basket
		fprintf(stdout, "Enter the basket's Asset Type ID (aka Contract ID): ");
		str_BASKET_CONTRACT_ID.OTfgets(stdin);
		
		// FIRST get the Asset Type ID for the basket
		fprintf(stdout, "Enter an ACCOUNT ID of yours for an account that has the same asset type: ");
		str_MAIN_ACCOUNT_ID.OTfgets(stdin);
		OTIdentifier MAIN_ACCOUNT_ID(str_MAIN_ACCOUNT_ID);
		
		// which direction is the exchange?
		OTString strDirection;
		fprintf(stdout, "Are you exchanging in or out? [in]: ");
		strDirection.OTfgets(stdin);
		
		if (strDirection.Compare("out") || strDirection.Compare("Out"))
			theMessage.m_bBool	= false;
		else
			theMessage.m_bBool	= true;
		
		// load up the asset contract
		OTString strContractPath;
		strContractPath.Format("%s%scontracts%s%s", OTPseudonym::OTPath.Get(), OTPseudonym::OTPathSeparator.Get(), 
							   OTPseudonym::OTPathSeparator.Get(), str_BASKET_CONTRACT_ID.Get());
		OTAssetContract * pContract = new OTAssetContract(str_BASKET_CONTRACT_ID, strContractPath, str_BASKET_CONTRACT_ID);
		
		if (pContract && pContract->LoadContract() && pContract->VerifyContract()) 
		{
			// Next load the OTBasket object out of that contract.
			OTBasket theBasket;
			
			// todo perhaps verify the basket here, even though I just verified the asset contract itself...
			// Can't never be too sure.
			if (pContract->GetBasketInfo().GetLength() && theBasket.LoadContractFromString(pContract->GetBasketInfo()))
			{
				int nTransferMultiple = 0;
				
				OTBasket theRequestBasket(theBasket.Count(), theBasket.GetMinimumTransfer());

				// Show the minimum transfer amount to the customer and ask him to choose a multiple for the transfer
				fprintf(stdout, "The minimum transfer amount for this basket is %ld. You may only exchange in multiples of it.\n"
						"Choose any multiple [1]: ", theBasket.GetMinimumTransfer());
				strTemp.OTfgets(stdin);
				nTransferMultiple = atoi(strTemp.Get()); 
				strTemp.Release();
				if (nTransferMultiple <= 0)
					nTransferMultiple = 1;

				theRequestBasket.SetTransferMultiple(nTransferMultiple);
				
				// Then loop through the BasketItems... 
				for (int i = 0; i < theBasket.Count(); i++)
				{
					BasketItem * pItem = theBasket.At(i);
					
					// pItem-> contains SUB_CONTRACT_ID, SUB_ACCOUNT_ID, and lMinimumTransferAmount.
					
					// ...and for each one, ask the user to enter his corresponding account ID.
					// IT MUST BE THE SAME ASSET TYPE AS THE BASKET ITEM, SO SHOW USER THE ASSET ID!
					OTString str_SUB_CONTRACT_ID(pItem->SUB_CONTRACT_ID);
					fprintf(stdout, "\nBasket currency type (Asset Type) #%d is:\n%s\n\nPlease enter your own "
							"existing Account ID of the same asset type: ", 
							i+1, str_SUB_CONTRACT_ID.Get());
					OTString str_TEMP_ACCOUNT_ID;
					str_TEMP_ACCOUNT_ID.OTfgets(stdin);
					OTIdentifier TEMP_ACCOUNT_ID(str_TEMP_ACCOUNT_ID);
					
					
					// TODO (later) Load up the user's account at this point to make sure it even exists.
					// Then check the asset type on that account against pItem->SUB_CONTRACT_ID and make sure they match.
					// The server will definitely have to do this anyway. The client can skip it, but the command
					// won't work unless the user enters this data properly. UI will have to do a popup here if something is wrong.
					
					
					// As this is happening, we're creating ANOTHER basket object (theRequestBasket), with items that 
					// contain MY account IDs. 
					// The minimum transfer amounts on the new basket are set based on a multiple of the original.
					// (I already set the multiple just above this loop.)
					
					theRequestBasket.AddRequestSubContract(pItem->SUB_CONTRACT_ID, TEMP_ACCOUNT_ID);
				}
				
				// Make sure the server knows where to put my new basket currency once the exchange is done.
				theRequestBasket.SetRequestAccountID(MAIN_ACCOUNT_ID);
				
				// Export the OTBasket object into a string, add it as
				// a payload on my request, and send to server.
				theRequestBasket.SignContract(theNym);
				theRequestBasket.SaveContract(strBasketInfo);
			}
			else {
				fprintf(stdout, "Error loading basket info from asset contract. Are you SURE this is a basket currency?\n");
			}
		}
		else {
			fprintf(stdout, "Failure loading or verifying %s\n", strContractPath.Get());
		}
		
		// The result is the same as any other currency contract, but with the server's signature
		// on it (and thus it must store the server's public key).  The server handles all
		// transactions in and out of the basket currency based upon the rules set up by the user.
		//
		// The user who created the currency has no more control over it. The server reserves the
		// right to exchange out to the various users and close the basket.
		
		// AT SOME POINT, strBasketInfo has been populated with the relevant data.
		theMessage.m_ascPayload.SetString(strBasketInfo);

		// (0) Set up the REQUEST NUMBER and then INCREMENT IT
		theNym.GetCurrentRequestNum(strServerID, lRequestNumber);
		theMessage.m_strRequestNum.Format("%ld", lRequestNumber); // Always have to send this.
		theNym.IncrementRequestNum(theNym, strServerID); // since I used it for a server request, I have to increment it
		
		// (1) Set up member variables
		theMessage.m_strCommand		= "exchangeBasket";
		theMessage.m_strNymID		= strNymID;
		theMessage.m_strServerID	= strServerID;
		theMessage.m_strAssetID		= str_BASKET_CONTRACT_ID;
		
		
		// (2) Sign the Message 
		theMessage.SignContract(theNym);		
		
		// (3) Save the Message (with signatures and all, back to its internal member m_strRawFile.)
		theMessage.SaveContract();
		
		bSendCommand = true;			
	}
	
	// ------------------------------------------------------------------------
	
	else if (OTClient::issueBasket == requestedCommand) // ISSUE BASKET
	{				
		OTString strTemp, strBasketInfo;
		
		// Collect NUMBER OF CONTRACTS for the basket.
		fprintf(stdout, "How many different asset types will compose this new basket? [2]: ");
		strTemp.OTfgets(stdin);
		int nBasketCount = atoi(strTemp.Get());
		if (0 == nBasketCount)
			nBasketCount = 2;
		
		// Collect the MINIMUM TRANSFER AMOUNT for the basket. Default 100.
		fprintf(stdout, "If your basket has a minimum transfer amount of 100, you might have 2 or 3 sub-currencies,\n"
				"with the first being a minimum of 2 gold, the second being a minimum of 50 dollars, and the\n"
				"third being a minimum of 30 silver. In this example, 100 units of the basket currency is\n"
				"transferrable in or out of the basket currency, in return for 2 gold, 50 dollars, and 30 silver.\n"
				"As those are only the *minimum* amounts, you could also transfer (in or out) in *any* multiple of\n"
				"those numbers.\n\n");
		fprintf(stdout, "What is the minimum transfer amount for the basket currency itself? [100]: ");
		strTemp.Release(); strTemp.OTfgets(stdin);
		long lMinimumTransferAmount = atoi(strTemp.Get());
		if (0 == lMinimumTransferAmount)
			lMinimumTransferAmount = 100;
		
		// ADD THESE VALUES TO A BASKET OBJECT HERE SO I CAN RE-USE lMinimumTransferAmount for the loop below.
		OTBasket theBasket(nBasketCount, lMinimumTransferAmount);
		
		// Collect all the contract IDs for the above contracts
		for (int i = 0; i < nBasketCount; i++)
		{
			fprintf(stdout, "Enter contract ID # %d: ", i+1);
			strTemp.Release(); strTemp.OTfgets(stdin);
			
			OTIdentifier SUB_CONTRACT_ID(strTemp.Get());
			
			// After each ID, collect the minimum transfer amount for EACH contract.
			fprintf(stdout, "Enter minimum transfer amount for that asset type: ");
			strTemp.Release(); strTemp.OTfgets(stdin);
			
			lMinimumTransferAmount = atol(strTemp.Get());
			
			// ADD THE CONTRACT ID TO A LIST TO BE SENT TO THE SERVER.
			// ADD THE MINIMUM TRANSFER AMOUNT TO THE SAME OBJECT
			theBasket.AddSubContract(SUB_CONTRACT_ID, lMinimumTransferAmount);
			
			// The object storing these should also have a space for storing
			// the account ID that will go with each one. The server will add
			// the Account ID when the reserve accounts are generated.
			//
			// (The basket issuer account will contain sub-accounts for the
			// reserves, which are stored there and 100% redeemable at all times.)
		}
		
		// Export the OTBasket object into a string, add it as
		// a payload on message, and send to server.
		theBasket.SignContract(theNym);
		theBasket.SaveContract(strBasketInfo);
		
		// The user signs and saves the contract, but once the server gets it,
		// the server releases signatures and signs it, calculating the hash from the result,
		// in order to form the ID.
		//
		// The result is the same as any other currency contract, but with the server's signature
		// on it (and thus it must store the server's public key).  The server handles all
		// transactions in and out of the basket currency based upon the rules set up by the user.
		//
		// The user who created the currency has no more control over it. The server reserves the
		// right to exchange out to the various users and close the basket.
		
		// AT SOME POINT, strBasketInfo has been populated with the relevant data.
		
		// (0) Set up the REQUEST NUMBER and then INCREMENT IT
		theNym.GetCurrentRequestNum(strServerID, lRequestNumber);
		theMessage.m_strRequestNum.Format("%ld", lRequestNumber); // Always have to send this.
		theNym.IncrementRequestNum(theNym, strServerID); // since I used it for a server request, I have to increment it
		
		// (1) Set up member variables 
		theMessage.m_strCommand			= "issueBasket";
		theMessage.m_strNymID			= strNymID;
		theMessage.m_strServerID		= strServerID;
		
		theMessage.m_ascPayload.SetString(strBasketInfo);
		
		// (2) Sign the Message 
		theMessage.SignContract(theNym);		
		
		// (3) Save the Message (with signatures and all, back to its internal member m_strRawFile.)
		theMessage.SaveContract();
		
		bSendCommand = true;			
		
	}
	
	// ------------------------------------------------------------------------
	
	else if (OTClient::createAccount == requestedCommand) // CREATE ACCOUNT
	{	
		fprintf(stdout, "Please enter an asset type (contract ID): ");
		// User input.
		// I need a from account
		OTString strAssetID;
		strAssetID.OTfgets(stdin);
		
		// (0) Set up the REQUEST NUMBER and then INCREMENT IT
		theNym.GetCurrentRequestNum(strServerID, lRequestNumber);
		theMessage.m_strRequestNum.Format("%ld", lRequestNumber); // Always have to send this.
		theNym.IncrementRequestNum(theNym, strServerID); // since I used it for a server request, I have to increment it
		
		// (1) Set up member variables 
		theMessage.m_strCommand			= "createAccount";
		theMessage.m_strNymID			= strNymID;
		theMessage.m_strServerID		= strServerID;
		theMessage.m_strAssetID			= strAssetID;// the hash of the contract is the AssetID
		
		// (2) Sign the Message 
		theMessage.SignContract(theNym);		
		
		// (3) Save the Message (with signatures and all, back to its internal member m_strRawFile.)
		theMessage.SaveContract();
		
		bSendCommand = true;
	}
	
	// ------------------------------------------------------------------------
	
	else if (OTClient::notarizeTransfer == requestedCommand) // NOTARIZE TRANSFER
	{	
		// Eventually these sorts of things will be handled with callback functions
		// I'll just use a callback here.
		// That way, whatever user interface people want to implement for obtaining
		// the account numbers for the message, is up to the programmer.
		fprintf(stdout, "Please enter a From account: ");
		// User input.
		// I need a from account
		OTString strFromAcct;
		strFromAcct.OTfgets(stdin);
		
		
		fprintf(stdout, "Please enter a To account: ");
		// User input.
		// I need a to account
		OTString strToAcct;
		strToAcct.OTfgets(stdin);
		
		
		fprintf(stdout, "Please enter an amount: ");
		// User input.
		// I need a to account
		OTString strAmount;
		strAmount.OTfgets(stdin);
		
		
		OTIdentifier	ACCT_FROM_ID(strFromAcct),	ACCT_TO_ID(strToAcct), 
						SERVER_ID(strServerID),		USER_ID(theNym);
	
		long lStoredTransactionNumber=0;
		bool bGotTransNum = theNym.GetNextTransactionNum(theNym, strServerID, lStoredTransactionNumber);
		
		if (bGotTransNum)
		{
			// Create a transaction
			OTTransaction * pTransaction = OTTransaction::GenerateTransaction (USER_ID, ACCT_FROM_ID, SERVER_ID, OTTransaction::transfer, lStoredTransactionNumber); 
			
			// set up the transaction item (each transaction may have multiple items...)
			OTItem * pItem		= OTItem::CreateItemFromTransaction(*pTransaction, OTItem::transfer, &ACCT_TO_ID);
			pItem->m_lAmount	= atol(strAmount.Get());
			OTString strNote("Just testing the notes...blah blah blah blah blah blah");
			pItem->SetNote(strNote);
			
			// sign the item
			pItem->SignContract(theNym);
			pItem->SaveContract();
			
			
			pTransaction->AddItem(*pItem); // the Transaction's destructor will cleanup the item. It "owns" it now.
			
			// sign the transaction
			pTransaction->SignContract(theNym);
			pTransaction->SaveContract();
			
			
			// set up the ledger
			OTLedger theLedger(USER_ID, ACCT_FROM_ID, SERVER_ID);
			theLedger.GenerateLedger(ACCT_FROM_ID, SERVER_ID, OTLedger::message); // bGenerateLedger defaults to false, which is correct.
			theLedger.AddTransaction(*pTransaction);
			
			// sign the ledger
			theLedger.SignContract(theNym);
			theLedger.SaveContract();
			
			// extract the ledger in ascii-armored form
			OTString		strLedger(theLedger);
			OTASCIIArmor	ascLedger; // I can't pass strLedger into this constructor because I want to encode it
			
			// Encoding...
			ascLedger.SetString(strLedger);
		
			
			// (0) Set up the REQUEST NUMBER and then INCREMENT IT
			theNym.GetCurrentRequestNum(strServerID, lRequestNumber);
			theMessage.m_strRequestNum.Format("%ld", lRequestNumber); // Always have to send this.
			theNym.IncrementRequestNum(theNym, strServerID); // since I used it for a server request, I have to increment it
			
			// (1) Set up member variables 
			theMessage.m_strCommand			= "notarizeTransactions";
			theMessage.m_strNymID			= strNymID;
			theMessage.m_strServerID		= strServerID;
			theMessage.m_strAcctID			= strFromAcct;
			theMessage.m_ascPayload			= ascLedger;
			
			// (2) Sign the Message 
			theMessage.SignContract(theNym);		
			
			// (3) Save the Message (with signatures and all, back to its internal member m_strRawFile.)
			theMessage.SaveContract();
			
//			OTString DEBUGSTR;
//			theMessage.SaveContract(DEBUGSTR);
//			
//			fprintf(stderr, "DEBUG  Transaction message:\n%s\n", DEBUGSTR.Get());
			
			bSendCommand = true;
		}
		else {
			fprintf(stderr, "No transaction numbers were available. Suggest requesting the server for one.\n");
		}
	}
	
	// ------------------------------------------------------------------------
	
	else if (OTClient::getInbox == requestedCommand) // GET INBOX
	{	
		fprintf(stdout, "Please enter an account number: ");
		// User input.
		// I need an account
		OTString strAcctID;
		strAcctID.OTfgets(stdin);
		
		
		// (0) Set up the REQUEST NUMBER and then INCREMENT IT
		theNym.GetCurrentRequestNum(strServerID, lRequestNumber);
		theMessage.m_strRequestNum.Format("%ld", lRequestNumber); // Always have to send this.
		theNym.IncrementRequestNum(theNym, strServerID); // since I used it for a server request, I have to increment it
		
		// (1) Set up member variables 
		theMessage.m_strCommand			= "getInbox";
		theMessage.m_strNymID			= strNymID;
		theMessage.m_strServerID		= strServerID;
		theMessage.m_strAcctID			= strAcctID;
		
		// (2) Sign the Message 
		theMessage.SignContract(theNym);		
		
		// (3) Save the Message (with signatures and all, back to its internal member m_strRawFile.)
		theMessage.SaveContract();
		
		bSendCommand = true;
	}
	
	// ------------------------------------------------------------------------
	
	else if (OTClient::processInbox == requestedCommand) // PROCESS INBOX
	{	
		OTString strAcctID;

		// Normally processInbox command is sent with a transaction ledger
		// in the payload, accepting or rejecting various transactions in
		// my inbox.
		// If pAccount was passed in, that means somewhere else in the code
		// a ledger is being added to this message after this point, and it
		// is being re-signed and sent out.
		// That's why you don't see a ledger being constructed and added to
		// the payload here. Because it's being done somewhere else, and that
		// same place is what passed the account pointer in here.
		// I only put this block here for now because I'd rather have it with
		// all the others.

		if (pAccount)
		{	// set up strAcctID based on pAccount
			OTIdentifier theAccountID;
			pAccount->GetIdentifier(theAccountID);
			theAccountID.GetString(strAcctID);
		}
		else {
			fprintf(stdout, "Please enter an account number: ");
			// User input.
			// I need an account
			strAcctID.OTfgets(stdin);
		}
		
		// (0) Set up the REQUEST NUMBER and then INCREMENT IT
		theNym.GetCurrentRequestNum(strServerID, lRequestNumber);
		theMessage.m_strRequestNum.Format("%ld", lRequestNumber); // Always have to send this.
		theNym.IncrementRequestNum(theNym, strServerID); // since I used it for a server request, I have to increment it
		
		// (1) Set up member variables 
		theMessage.m_strCommand			= "processInbox";
		theMessage.m_strNymID			= strNymID;
		theMessage.m_strServerID		= strServerID;
		theMessage.m_strAcctID			= strAcctID;
		
		// (2) Sign the Message 
		theMessage.SignContract(theNym);		
		
		// (3) Save the Message (with signatures and all, back to its internal member m_strRawFile.)
		theMessage.SaveContract();
		
		bSendCommand = true;
	}
	
	// ------------------------------------------------------------------------
	
	
	else if (OTClient::getAccount == requestedCommand) // GET ACCOUNT
	{	
		fprintf(stdout, "Please enter an account number: ");
		// User input.
		// I need an account
		OTString strAcctID;
		strAcctID.OTfgets(stdin);
		
		
		// (0) Set up the REQUEST NUMBER and then INCREMENT IT
		theNym.GetCurrentRequestNum(strServerID, lRequestNumber);
		theMessage.m_strRequestNum.Format("%ld", lRequestNumber); // Always have to send this.
		theNym.IncrementRequestNum(theNym, strServerID); // since I used it for a server request, I have to increment it
		
		// (1) Set up member variables 
		theMessage.m_strCommand			= "getAccount";
		theMessage.m_strNymID			= strNymID;
		theMessage.m_strServerID		= strServerID;
		theMessage.m_strAcctID			= strAcctID;
		
		// (2) Sign the Message 
		theMessage.SignContract(theNym);		
		
		// (3) Save the Message (with signatures and all, back to its internal member m_strRawFile.)
		theMessage.SaveContract();
		
		bSendCommand = true;
	}
	
	// ------------------------------------------------------------------------
	
	
	else if (OTClient::getContract == requestedCommand) // GET CONTRACT
	{	
		fprintf(stdout, "Please enter an asset type ID: ");
		// User input.
		// I need an account
		OTString strAssetID;
		strAssetID.OTfgets(stdin);
		
		
		// (0) Set up the REQUEST NUMBER and then INCREMENT IT
		theNym.GetCurrentRequestNum(strServerID, lRequestNumber);
		theMessage.m_strRequestNum.Format("%ld", lRequestNumber); // Always have to send this.
		theNym.IncrementRequestNum(theNym, strServerID); // since I used it for a server request, I have to increment it
		
		// (1) Set up member variables 
		theMessage.m_strCommand			= "getContract";
		theMessage.m_strNymID			= strNymID;
		theMessage.m_strServerID		= strServerID;
		theMessage.m_strAssetID			= strAssetID;
		
		// (2) Sign the Message 
		theMessage.SignContract(theNym);		
		
		// (3) Save the Message (with signatures and all, back to its internal member m_strRawFile.)
		theMessage.SaveContract();
		
		bSendCommand = true;
	}
	
	// ------------------------------------------------------------------------
	
	
	else if (OTClient::getMint == requestedCommand) // GET MINT
	{	
		fprintf(stdout, "Please enter an asset type ID: ");
		// User input.
		// I need an account
		OTString strAssetID;
		strAssetID.OTfgets(stdin);
		
		
		// (0) Set up the REQUEST NUMBER and then INCREMENT IT
		theNym.GetCurrentRequestNum(strServerID, lRequestNumber);
		theMessage.m_strRequestNum.Format("%ld", lRequestNumber); // Always have to send this.
		theNym.IncrementRequestNum(theNym, strServerID); // since I used it for a server request, I have to increment it
		
		// (1) Set up member variables 
		theMessage.m_strCommand			= "getMint";
		theMessage.m_strNymID			= strNymID;
		theMessage.m_strServerID		= strServerID;
		theMessage.m_strAssetID			= strAssetID;
		
		// (2) Sign the Message 
		theMessage.SignContract(theNym);		
		
		// (3) Save the Message (with signatures and all, back to its internal member m_strRawFile.)
		theMessage.SaveContract();
		
		bSendCommand = true;
	}
	
	// ------------------------------------------------------------------------
	

	else if (OTClient::notarizeCheque == requestedCommand) // DEPOSIT CHEQUE
	{	
		OTString strFromAcct;
		
		if (!pAccount)
		{
			// Eventually these sorts of things will be handled with callback functions
			// I'll just use a callback here.
			// That way, whatever user interface people want to implement for obtaining
			// the account numbers for the message, is up to the programmer.
			fprintf(stdout, "Please enter an account to deposit to: ");
			// User input.
			// I need a from account, Yes even in a deposit, it's still the "From" account.
			// The "To" account is only used for a transfer. (And perhaps for a 2-way trade.)
			
			// User input.
			// I need a from account
			strFromAcct.OTfgets(stdin);
			
			const OTIdentifier ACCOUNT_ID(strFromAcct);
			
			if (pAccount = g_Wallet.GetAccount(ACCOUNT_ID))
			{
				CONTRACT_ID = pAccount->GetAssetTypeID();
				CONTRACT_ID.GetString(strContractID);
			}
		}
		
		OTIdentifier ACCT_FROM_ID(strFromAcct), SERVER_ID(strServerID), USER_ID(theNym);
		
		OTCheque theCheque(SERVER_ID, CONTRACT_ID);
		
		fprintf(stdout, "Please enter plaintext cheque, terminate with ~ on a new line:\n> ");
		OTString strCheque;
		char decode_buffer[200];
		
		do {
			fgets(decode_buffer, sizeof(decode_buffer), stdin);
			
			if (decode_buffer[0] != '~')
			{
				strCheque.Concatenate("%s", decode_buffer);
				fprintf(stdout, "> ");
			}
		} while (decode_buffer[0] != '~');
		
		
		long lStoredTransactionNumber=0;
		bool bGotTransNum = theNym.GetNextTransactionNum(theNym, strServerID, lStoredTransactionNumber);
		
		if (!bGotTransNum)
		{
			fprintf(stderr, "No Transaction Numbers were available. Try requesting the server for a new one.\n");
		}
		else if (theCheque.LoadContractFromString(strCheque))
		{
			// Create a transaction
			OTTransaction * pTransaction = OTTransaction::GenerateTransaction (USER_ID, ACCT_FROM_ID, SERVER_ID, 
																			   OTTransaction::deposit, lStoredTransactionNumber); 
			
			// set up the transaction item (each transaction may have multiple items...)
			OTItem * pItem		= OTItem::CreateItemFromTransaction(*pTransaction, OTItem::depositCheque);
			
			OTString strNote("Deposit this cheque, please!");
			pItem->SetNote(strNote);
			
			strCheque.Release();
			theCheque.SaveContract(strCheque);
									
			// Add the cheque string as the attachment on the transaction item.
			pItem->SetAttachment(strCheque); // The cheque is contained in the reference string.
			
			// sign the item
			pItem->SignContract(theNym);
			pItem->SaveContract();
			
			// the Transaction "owns" the item now and will handle cleaning it up.
			pTransaction->AddItem(*pItem); // the Transaction's destructor will cleanup the item. It "owns" it now.
			
			// sign the transaction
			pTransaction->SignContract(theNym);
			pTransaction->SaveContract();
			
			// set up the ledger
			OTLedger theLedger(USER_ID, ACCT_FROM_ID, SERVER_ID);
			theLedger.GenerateLedger(ACCT_FROM_ID, SERVER_ID, OTLedger::message); // bGenerateLedger defaults to false, which is correct.
			theLedger.AddTransaction(*pTransaction); // now the ledger "owns" and will handle cleaning up the transaction.
			
			// sign the ledger
			theLedger.SignContract(theNym);
			theLedger.SaveContract();
			
			// extract the ledger in ascii-armored form... encoding...
			OTString		strLedger(theLedger);
			OTASCIIArmor	ascLedger(strLedger);
			
			// (0) Set up the REQUEST NUMBER and then INCREMENT IT
			theNym.GetCurrentRequestNum(strServerID, lRequestNumber);
			theMessage.m_strRequestNum.Format("%ld", lRequestNumber); // Always have to send this.
			theNym.IncrementRequestNum(theNym, strServerID); // since I used it for a server request, I have to increment it
			
			// (1) Set up member variables 
			theMessage.m_strCommand			= "notarizeTransactions";
			theMessage.m_strNymID			= strNymID;
			theMessage.m_strServerID		= strServerID;
			theMessage.m_strAcctID			= strFromAcct;
			theMessage.m_ascPayload			= ascLedger;
			
			// (2) Sign the Message 
			theMessage.SignContract(theNym);		
			
			// (3) Save the Message (with signatures and all, back to its internal member m_strRawFile.)
			theMessage.SaveContract();
			
			bSendCommand = true;
		} 
	} // else if (OTClient::notarizeCheque == requestedCommand) // DEPOSIT CHEQUE
	
	
	// ------------------------------------------------------------------------
		
	else if (OTClient::withdrawVoucher == requestedCommand) // WITHDRAW VOUCHER
	{		
		OTString		strFromAcct;
		OTIdentifier	ACCOUNT_ID;
		
		if (!pAccount)
		{
			fprintf(stdout, "Please enter a From account: ");
			// User input.
			// I need a from account
			strFromAcct.OTfgets(stdin);
			
			ACCOUNT_ID.SetString(strFromAcct);
			
			if (pAccount = g_Wallet.GetAccount(ACCOUNT_ID))
			{
				CONTRACT_ID = pAccount->GetAssetTypeID();
				CONTRACT_ID.GetString(strContractID);
			}
		}
		else {
			pAccount->GetIdentifier(strFromAcct);
			pAccount->GetIdentifier(ACCOUNT_ID);
			CONTRACT_ID = pAccount->GetAssetTypeID();
			CONTRACT_ID.GetString(strContractID);			
		}
	
		const OTIdentifier SERVER_ID(strServerID), USER_ID(strNymID);
		
		long lStoredTransactionNumber=0;
		bool bGotTransNum = theNym.GetNextTransactionNum(theNym, strServerID, lStoredTransactionNumber);

		if ((NULL != pAccount) && bGotTransNum)
		{
			// Recipient
			fprintf(stdout, "Enter a User ID for the recipient of this cheque (defaults to blank): ");
			OTString strRecipientUserID;
			strRecipientUserID.OTfgets(stdin);
			const OTIdentifier RECIPIENT_USER_ID(strRecipientUserID.Get());
			
			// -----------------------------------------------------------------------

			// Amount
			fprintf(stdout, "Enter an amount: ");
			OTString strAmount;
			strAmount.OTfgets(stdin);
			const long lAmount = atol(strAmount.Get());
			
			// -----------------------------------------------------------------------
			
			// Memo
			fprintf(stdout, "Enter a memo for your check: ");
			OTString strChequeMemo;
			strChequeMemo.OTfgets(stdin);
			
			// -----------------------------------------------------------------------

			// Expiration (ignored by server -- it sets its own for its vouchers.)
			const	time_t	VALID_FROM	= time(NULL); // This time is set to TODAY NOW
			const	time_t	VALID_TO	= VALID_FROM + 15552000; // 6 months.
						
			// -----------------------------------------------------------------------
			// The server only uses the memo, amount, and recipient from this cheque when it
			// constructs the actual voucher.
			OTCheque theRequestVoucher(SERVER_ID, CONTRACT_ID);
			bool bIssueCheque = theRequestVoucher.IssueCheque(lAmount, lStoredTransactionNumber,// server actually ignores this and supplies its own transaction number for any voucher.
															  VALID_FROM, VALID_TO, ACCOUNT_ID, USER_ID, strChequeMemo,
															  (strRecipientUserID.GetLength() > 2) ? &(RECIPIENT_USER_ID) : NULL);
			
			if (bIssueCheque)
			{
				// Create a transaction
				OTTransaction * pTransaction = OTTransaction::GenerateTransaction (USER_ID, ACCOUNT_ID, SERVER_ID, 
																				   OTTransaction::withdrawal, lStoredTransactionNumber); 
				
				// set up the transaction item (each transaction may have multiple items...)
				OTItem * pItem		= OTItem::CreateItemFromTransaction(*pTransaction, OTItem::withdrawVoucher);
				pItem->m_lAmount	= lAmount;
				OTString strNote("Withdraw Voucher: ");
				pItem->SetNote(strNote);
				
				// Add the voucher request string as the attachment on the transaction item.
				OTString strVoucher;
				theRequestVoucher.SignContract(theNym);
				theRequestVoucher.SaveContract();
				theRequestVoucher.SaveContract(strVoucher);			
				pItem->SetAttachment(strVoucher); // The voucher request is contained in the reference string.
				
				// sign the item
				pItem->SignContract(theNym);
				pItem->SaveContract();
				
				pTransaction->AddItem(*pItem); // the Transaction's destructor will cleanup the item. It "owns" it now.
				
				// sign the transaction
				pTransaction->SignContract(theNym);
				pTransaction->SaveContract();
				
				
				// set up the ledger
				OTLedger theLedger(USER_ID, ACCOUNT_ID, SERVER_ID);
				theLedger.GenerateLedger(ACCOUNT_ID, SERVER_ID, OTLedger::message); // bGenerateLedger defaults to false, which is correct.
				theLedger.AddTransaction(*pTransaction);
				
				// sign the ledger
				theLedger.SignContract(theNym);
				theLedger.SaveContract();
				
				// extract the ledger in ascii-armored form
				OTString		strLedger(theLedger);
				OTASCIIArmor	ascLedger; // I can't pass strLedger into this constructor because I want to encode it
				
				// Encoding...
				ascLedger.SetString(strLedger);
				
				
				// (0) Set up the REQUEST NUMBER and then INCREMENT IT
				theNym.GetCurrentRequestNum(strServerID, lRequestNumber);
				theMessage.m_strRequestNum.Format("%ld", lRequestNumber); // Always have to send this.
				theNym.IncrementRequestNum(theNym, strServerID); // since I used it for a server request, I have to increment it
				
				// (1) Set up member variables 
				theMessage.m_strCommand			= "notarizeTransactions";
				theMessage.m_strNymID			= strNymID;
				theMessage.m_strServerID		= strServerID;
				theMessage.m_strAcctID			= strFromAcct;
				theMessage.m_ascPayload			= ascLedger;
				
				// (2) Sign the Message 
				theMessage.SignContract(theNym);		
				
				// (3) Save the Message (with signatures and all, back to its internal member m_strRawFile.)
				theMessage.SaveContract();
				
				bSendCommand = true;
			}
		}
		else {
			fprintf(stderr, "No Transaction Numbers were available. Suggest requesting the server for a new one.\n");
		}
		
	}
	
	// ------------------------------------------------------------------------
	
	
	
	else if (OTClient::notarizeWithdrawal == requestedCommand) // NOTARIZE WITHDRAWAL
	{	
		// Eventually these sorts of things will be handled with callback functions
		// I'll just use a callback here.
		// That way, whatever user interface people want to implement for obtaining
		// the account numbers for the message, is up to the programmer.
		
		OTString strFromAcct;
		
		if (!pAccount)
		{
			fprintf(stdout, "Please enter a From account: ");
			// User input.
			// I need a from account
			strFromAcct.OTfgets(stdin);
			
			const OTIdentifier ACCOUNT_ID(strFromAcct);
			
			if (pAccount = g_Wallet.GetAccount(ACCOUNT_ID))
			{
				CONTRACT_ID = pAccount->GetAssetTypeID();
				CONTRACT_ID.GetString(strContractID);
			}
		}
		
		fprintf(stdout, "Please enter an amount: ");
		// User input.
		// I need an amount
		OTString strAmount;
		strAmount.OTfgets(stdin);
		
		long lAmount = atol(strAmount.Get());
		
		OTIdentifier ACCT_FROM_ID(strFromAcct), SERVER_ID(strServerID), USER_ID(theNym);
		
		long lStoredTransactionNumber=0;
		bool bGotTransNum = theNym.GetNextTransactionNum(theNym, strServerID, lStoredTransactionNumber);
		
		if (bGotTransNum)
		{
			// Create a transaction
			OTTransaction * pTransaction = OTTransaction::GenerateTransaction (USER_ID, ACCT_FROM_ID, SERVER_ID, 
																			   OTTransaction::withdrawal, lStoredTransactionNumber); 
			
			// set up the transaction item (each transaction may have multiple items...)
			OTItem * pItem		= OTItem::CreateItemFromTransaction(*pTransaction, OTItem::withdrawal);
			pItem->m_lAmount	= lAmount;
			//		pItem->m_lAmount	= atol(strAmount.Get());
			OTString strNote("Gimme cash!");
			pItem->SetNote(strNote);
			
			// Testing encrypted envelopes...
			const OTPseudonym * pServerNym = theServer.GetContractPublicNym();
			
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
					theToken.GenerateTokenRequest(theNym, theMint, lTokenAmount);
					theToken.SignContract(theNym);
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
					theToken.SignContract(theNym);
					theToken.SaveContract();
					
					pPurseMyCopy->Push(theNym, theToken);	// Now my copy of the purse has a version of the token,
				}
				
				pPurse->SignContract(theNym);
				pPurse->SaveContract(); // I think this one is unnecessary.
				
				// Save the purse into a string...
				OTString strPurse;
				pPurse->SaveContract(strPurse);
				
				// Add the purse string as the attachment on the transaction item.
				pItem->SetAttachment(strPurse); // The purse is contained in the reference string.
				
				
				pPurseMyCopy->SignContract(theNym);		// encrypted to me instead of the server, and including 
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
				pItem->SignContract(theNym);
				pItem->SaveContract();
				
				pTransaction->AddItem(*pItem); // the Transaction's destructor will cleanup the item. It "owns" it now.
				
				// sign the transaction
				pTransaction->SignContract(theNym);
				pTransaction->SaveContract();
				
				
				// set up the ledger
				OTLedger theLedger(USER_ID, ACCT_FROM_ID, SERVER_ID);
				theLedger.GenerateLedger(ACCT_FROM_ID, SERVER_ID, OTLedger::message); // bGenerateLedger defaults to false, which is correct.
				theLedger.AddTransaction(*pTransaction);
				
				// sign the ledger
				theLedger.SignContract(theNym);
				theLedger.SaveContract();
				
				// extract the ledger in ascii-armored form
				OTString		strLedger(theLedger);
				OTASCIIArmor	ascLedger; // I can't pass strLedger into this constructor because I want to encode it
				
				// Encoding...
				ascLedger.SetString(strLedger);
				
				
				// (0) Set up the REQUEST NUMBER and then INCREMENT IT
				theNym.GetCurrentRequestNum(strServerID, lRequestNumber);
				theMessage.m_strRequestNum.Format("%ld", lRequestNumber); // Always have to send this.
				theNym.IncrementRequestNum(theNym, strServerID); // since I used it for a server request, I have to increment it
				
				// (1) Set up member variables 
				theMessage.m_strCommand			= "notarizeTransactions";
				theMessage.m_strNymID			= strNymID;
				theMessage.m_strServerID		= strServerID;
				theMessage.m_strAcctID			= strFromAcct;
				theMessage.m_ascPayload			= ascLedger;
				
				// (2) Sign the Message 
				theMessage.SignContract(theNym);		
				
				// (3) Save the Message (with signatures and all, back to its internal member m_strRawFile.)
				theMessage.SaveContract();
				
				bSendCommand = true;
			}
		}
		else {
			fprintf(stderr, "No Transaction Numbers were available. Suggest requesting the server for a new one.\n");
		}
		
	}
	
	// ------------------------------------------------------------------------
	
	
	
	else if (OTClient::notarizeDeposit == requestedCommand) // NOTARIZE DEPOSIT
	{	
		OTString strFromAcct;
		
		if (!pAccount)
		{
			// Eventually these sorts of things will be handled with callback functions
			// I'll just use a callback here.
			// That way, whatever user interface people want to implement for obtaining
			// the account numbers for the message, is up to the programmer.
			fprintf(stdout, "Please enter an account to deposit to: ");
			// User input.
			// I need a from account, Yes even in a deposit, it's still the "From" account.
			// The "To" account is only used for a transfer. (And perhaps for a 2-way trade.)

			// User input.
			// I need a from account
			strFromAcct.OTfgets(stdin);
			
			const OTIdentifier ACCOUNT_ID(strFromAcct);
			
			if (pAccount = g_Wallet.GetAccount(ACCOUNT_ID))
			{
				CONTRACT_ID = pAccount->GetAssetTypeID();
				CONTRACT_ID.GetString(strContractID);
			}
		}
		
		OTIdentifier ACCT_FROM_ID(strFromAcct), SERVER_ID(strServerID), USER_ID(theNym);
		
		OTPurse thePurse(SERVER_ID, CONTRACT_ID);
		
		const OTPseudonym * pServerNym = theServer.GetContractPublicNym();
		
		long lStoredTransactionNumber=0;
		bool bGotTransNum = theNym.GetNextTransactionNum(theNym, strServerID, lStoredTransactionNumber);
		
		if (!bGotTransNum)
		{
			fprintf(stderr, "No Transaction Numbers were available. Try requesting the server for a new one.\n");
		}

		else if (pServerNym)
		{
			bool bSuccess = false;
			
			// Create a transaction
			OTTransaction * pTransaction = OTTransaction::GenerateTransaction (USER_ID, ACCT_FROM_ID, SERVER_ID, 
																			   OTTransaction::deposit, lStoredTransactionNumber); 
			
			// set up the transaction item (each transaction may have multiple items...)
			OTItem * pItem		= OTItem::CreateItemFromTransaction(*pTransaction, OTItem::deposit);
			
			OTString strNote("Deposit this cash, please!");
			pItem->SetNote(strNote);
			
			fprintf(stdout, "How many tokens would you like to deposit? ");
			OTString strTokenCount;
			strTokenCount.OTfgets(stdin);
			const int nTokenCount = atoi(strTokenCount.Get());
			
			for (int nTokenIndex = 1; nTokenIndex <= nTokenCount; nTokenIndex++)
			{
				fprintf(stdout, "Please enter plaintext token # %d; terminate with ~ on a new line:\n> ", nTokenIndex);
				OTString strToken;
				char decode_buffer[200];
				
				do {
					fgets(decode_buffer, sizeof(decode_buffer), stdin);
					
					if (decode_buffer[0] != '~')
					{
						strToken.Concatenate("%s", decode_buffer);
						fprintf(stdout, "> ");
					}
				} while (decode_buffer[0] != '~');
				
				// Create the relevant token request with same server/asset ID as the purse.
				// the purse does NOT own the token at this point. the token's constructor
				// just uses it to copy some IDs, since they must match.
				OTToken theToken(thePurse);
				
				if (theToken.LoadContractFromString(strToken)) // TODO verify the token contract
				{
					// TODO need 2-recipient envelopes. My request to the server is encrypted to the server's nym,
					// but it should be encrypted to my Nym also, so both have access to decrypt it.
					
					// Now the token is ready, let's add it to a purse
					// By pushing theToken into thePurse with *pServerNym, I encrypt it to pServerNym.
					// So now only the server Nym can decrypt that token and pop it out of that purse.
					if (false == theToken.ReassignOwnership(theNym, *pServerNym))
					{
						fprintf(stderr, "Error re-assigning ownership of token (to server.)\n");
						bSuccess = false;
						break;
					}
					else 
					{
						fprintf(stderr, "Success re-assigning ownership of token (to server.)\n");
						
						bSuccess = true;
						
						theToken.ReleaseSignatures();
						theToken.SignContract(theNym);
						theToken.SaveContract();
						
						thePurse.Push(*pServerNym, theToken);
						
						pItem->m_lAmount += theToken.GetDenomination();
					}
				}
				else {
					fprintf(stderr, "Error loading token from string.\n");
				}
			} // for
			
			if (bSuccess)
			{
				thePurse.SignContract(theNym);
				thePurse.SaveContract(); // I think this one is unnecessary.
				
				// Save the purse into a string...
				OTString strPurse;
				thePurse.SaveContract(strPurse);
				
				// Add the purse string as the attachment on the transaction item.
				pItem->SetAttachment(strPurse); // The purse is contained in the reference string.
				
				// sign the item
				pItem->SignContract(theNym);
				pItem->SaveContract();
				
				// the Transaction "owns" the item now and will handle cleaning it up.
				pTransaction->AddItem(*pItem); // the Transaction's destructor will cleanup the item. It "owns" it now.
				
				// sign the transaction
				pTransaction->SignContract(theNym);
				pTransaction->SaveContract();
				
				
				// set up the ledger
				OTLedger theLedger(USER_ID, ACCT_FROM_ID, SERVER_ID);
				theLedger.GenerateLedger(ACCT_FROM_ID, SERVER_ID, OTLedger::message); // bGenerateLedger defaults to false, which is correct.
				theLedger.AddTransaction(*pTransaction); // now the ledger "owns" and will handle cleaning up the transaction.
				
				// sign the ledger
				theLedger.SignContract(theNym);
				theLedger.SaveContract();
				
				// extract the ledger in ascii-armored form... encoding...
				OTString		strLedger(theLedger);
				OTASCIIArmor	ascLedger(strLedger); // I can't pass strLedger into this constructor because I want to encode it
				
				// (0) Set up the REQUEST NUMBER and then INCREMENT IT
				theNym.GetCurrentRequestNum(strServerID, lRequestNumber);
				theMessage.m_strRequestNum.Format("%ld", lRequestNumber); // Always have to send this.
				theNym.IncrementRequestNum(theNym, strServerID); // since I used it for a server request, I have to increment it
				
				// (1) Set up member variables 
				theMessage.m_strCommand			= "notarizeTransactions";
				theMessage.m_strNymID			= strNymID;
				theMessage.m_strServerID		= strServerID;
				theMessage.m_strAcctID			= strFromAcct;
				theMessage.m_ascPayload			= ascLedger;
				
				// (2) Sign the Message 
				theMessage.SignContract(theNym);		
				
				// (3) Save the Message (with signatures and all, back to its internal member m_strRawFile.)
				theMessage.SaveContract();
				
				bSendCommand = true;
			} // bSuccess
			else {
				delete pItem;		pItem = NULL;
				delete pTransaction;pTransaction = NULL;
			}
		} // if (pServerNym)
	} // else if (OTClient::notarizeDeposit == requestedCommand) // NOTARIZE DEPOSIT
	
	// ------------------------------------------------------------------------
	
	
	
	
	else if (OTClient::notarizePurse == requestedCommand) // NOTARIZE PURSE (deposit)
	{	
		OTString strFromAcct;
		
		if (!pAccount)
		{
			// Eventually these sorts of things will be handled with callback functions
			// I'll just use a callback here.
			// That way, whatever user interface people want to implement for obtaining
			// the account numbers for the message, is up to the programmer.
			fprintf(stdout, "Please enter an account to deposit to: ");
			// User input.
			// I need a from account, Yes even in a deposit, it's still the "From" account.
			// The "To" account is only used for a transfer. (And perhaps for a 2-way trade.)
			
			// User input.
			// I need a from account
			strFromAcct.OTfgets(stdin);
			
			const OTIdentifier ACCOUNT_ID(strFromAcct);
			
			if (pAccount = g_Wallet.GetAccount(ACCOUNT_ID))
			{
				CONTRACT_ID = pAccount->GetAssetTypeID();
				CONTRACT_ID.GetString(strContractID);
			}
		}
		
		OTIdentifier ACCT_FROM_ID(strFromAcct), SERVER_ID(strServerID), USER_ID(theNym);
		
		OTPurse thePurse(SERVER_ID, CONTRACT_ID);
		
		const OTPseudonym * pServerNym = theServer.GetContractPublicNym();
		
		long lStoredTransactionNumber=0;
		bool bGotTransNum = theNym.GetNextTransactionNum(theNym, strServerID, lStoredTransactionNumber);
		
		if (!bGotTransNum)
		{
			fprintf(stderr, "No Transaction Numbers were available. Try requesting the server for a new one.\n");
		}
		else if (pServerNym)
		{
			bool bSuccess = false;
			
			// Create a transaction
			OTTransaction * pTransaction = OTTransaction::GenerateTransaction (USER_ID, ACCT_FROM_ID, SERVER_ID, 
																			   OTTransaction::deposit, lStoredTransactionNumber); 
			
			// set up the transaction item (each transaction may have multiple items...)
			OTItem * pItem		= OTItem::CreateItemFromTransaction(*pTransaction, OTItem::deposit);
			
			OTString strNote("Deposit this cash, please!");
			pItem->SetNote(strNote);
			
			fprintf(stdout, "Please enter plaintext purse, terminate with ~ on a new line:\n> ");
			OTString strSourcePurse;
			char decode_buffer[200];
			
			do {
				fgets(decode_buffer, sizeof(decode_buffer), stdin);
				
				if (decode_buffer[0] != '~')
				{
					strSourcePurse.Concatenate("%s", decode_buffer);
					fprintf(stdout, "> ");
				}
			} while (decode_buffer[0] != '~');

			OTPurse theSourcePurse(thePurse);
			
			if (theSourcePurse.LoadContractFromString(strSourcePurse))
			while (!theSourcePurse.IsEmpty()) 
			{
				OTToken * pToken = theSourcePurse.Pop(theNym);
				
				if (pToken)
				{
					// TODO need 2-recipient envelopes. My request to the server is encrypted to the server's nym,
					// but it should be encrypted to my Nym also, so both have access to decrypt it.
					
					// Now the token is ready, let's add it to a purse
					// By pushing theToken into thePurse with *pServerNym, I encrypt it to pServerNym.
					// So now only the server Nym can decrypt that token and pop it out of that purse.
					if (false == pToken->ReassignOwnership(theNym, *pServerNym))
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
						pToken->SignContract(theNym);
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
				thePurse.SignContract(theNym);
				thePurse.SaveContract(); // I think this one is unnecessary.
				
				// Save the purse into a string...
				OTString strPurse;
				thePurse.SaveContract(strPurse);
				
				// Add the purse string as the attachment on the transaction item.
				pItem->SetAttachment(strPurse); // The purse is contained in the reference string.
				
				// sign the item
				pItem->SignContract(theNym);
				pItem->SaveContract();
				
				// the Transaction "owns" the item now and will handle cleaning it up.
				pTransaction->AddItem(*pItem); // the Transaction's destructor will cleanup the item. It "owns" it now.
				
				// sign the transaction
				pTransaction->SignContract(theNym);
				pTransaction->SaveContract();
				
				
				// set up the ledger
				OTLedger theLedger(USER_ID, ACCT_FROM_ID, SERVER_ID);
				theLedger.GenerateLedger(ACCT_FROM_ID, SERVER_ID, OTLedger::message); // bGenerateLedger defaults to false, which is correct.
				theLedger.AddTransaction(*pTransaction); // now the ledger "owns" and will handle cleaning up the transaction.
				
				// sign the ledger
				theLedger.SignContract(theNym);
				theLedger.SaveContract();
				
				// extract the ledger in ascii-armored form... encoding...
				OTString		strLedger(theLedger);
				OTASCIIArmor	ascLedger(strLedger); // I can't pass strLedger into this constructor because I want to encode it
				
				// (0) Set up the REQUEST NUMBER and then INCREMENT IT
				theNym.GetCurrentRequestNum(strServerID, lRequestNumber);
				theMessage.m_strRequestNum.Format("%ld", lRequestNumber); // Always have to send this.
				theNym.IncrementRequestNum(theNym, strServerID); // since I used it for a server request, I have to increment it
				
				// (1) Set up member variables 
				theMessage.m_strCommand			= "notarizeTransactions";
				theMessage.m_strNymID			= strNymID;
				theMessage.m_strServerID		= strServerID;
				theMessage.m_strAcctID			= strFromAcct;
				theMessage.m_ascPayload			= ascLedger;
				
				// (2) Sign the Message 
				theMessage.SignContract(theNym);		
				
				// (3) Save the Message (with signatures and all, back to its internal member m_strRawFile.)
				theMessage.SaveContract();
				
				bSendCommand = true;
			} // bSuccess
			else {
				delete pItem;		pItem = NULL;
				delete pTransaction;pTransaction = NULL;
			}
		} // if (pServerNym)
	} // else if (OTClient::notarizeDeposit == requestedCommand) // NOTARIZE DEPOSIT
	
	// ------------------------------------------------------------------------
	
	else if (OTClient::getTransactionNum == requestedCommand) // GET TRANSACTION NUM
	{	
		// (0) Set up the REQUEST NUMBER and then INCREMENT IT
		theNym.GetCurrentRequestNum(strServerID, lRequestNumber);
		theMessage.m_strRequestNum.Format("%ld", lRequestNumber); // Always have to send this.
		theNym.IncrementRequestNum(theNym, strServerID); // since I used it for a server request, I have to increment it
		
		// (1) Set up member variables 
		theMessage.m_strCommand			= "getTransactionNum";
		theMessage.m_strNymID			= strNymID;
		theMessage.m_strServerID		= strServerID;
		
		// (2) Sign the Message 
		theMessage.SignContract(theNym);		
		
		// (3) Save the Message (with signatures and all, back to its internal member m_strRawFile.)
		theMessage.SaveContract();
		
		bSendCommand = true;
	}
	
	
	
	
	// ------------------------------------------------------------------------
	

	/*
	else if (OTClient::withdrawTest == requestedCommand) // TEST OF TOKEN BLINDING. NOT PART OF THE REAL PROTOCOL.
	{	
		// (0) Set up the REQUEST NUMBER and then INCREMENT IT
		theNym.GetCurrentRequestNum(strServerID, lRequestNumber);
		theMessage.m_strRequestNum.Format("%ld", lRequestNumber); // Always have to send this.
		theNym.IncrementRequestNum(strServerID); // since I used it for a server request, I have to increment it
		
		// (1) Set up member variables 
		theMessage.m_strCommand			= "debitAccount";
		theMessage.m_strNymID			= strNymID;
		theMessage.m_strServerID		= strServerID;
		theMessage.m_strAssetID			= strContractID;// the hash of the contract is the AssetID
		
		// (2) Sign the Message 
		OTContract & aSigningDoc = theMessage;
		aSigningDoc.SignContract(theNym);		
		
		// (3) Save the Message (with signatures and all, back to its internal member m_strRawFile.)
		theMessage.SaveContract();
		
		bSendCommand = true;
	}
	*/
	// ------------------------------------------------------------------------
	
	else 
	{
		//gDebugLog.Write("unknown user command in ProcessMessage in main.cpp");
		//		fprintf(stderr, "Unknown user command in OTClient::ProcessUserCommand.\n");
				fprintf(stderr, "\n");
	}
	
	return bSendCommand;
}


OTClient::OTClient()
{
	// openssl initialization
	ERR_load_crypto_strings();  // Todo deal with error logging mechanism later.
	OpenSSL_add_all_algorithms();  // Is this really necessary to make these function calls? I'll leave it.
}

OTClient::~OTClient()
{
	// openssl cleanup
	CRYPTO_cleanup_all_ex_data();
	RAND_cleanup();
	EVP_cleanup();
	ERR_free_strings();
	ERR_remove_state(0);	
}



























