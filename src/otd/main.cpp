/*************************************************************
 *    
 *  main.cpp  (Uses ZMQ for transport.)
 *  
 */

/************************************************************
 -----BEGIN PGP SIGNED MESSAGE-----
 Hash: SHA1
 
 *                 OPEN TRANSACTIONS
 *
 *       Financial Cryptography and Digital Cash
 *       Library, Protocol, API, Server, CLI, GUI
 *
 *       -- Anonymous Numbered Accounts.
 *       -- Untraceable Digital Cash.
 *       -- Triple-Signed Receipts.
 *       -- Cheques, Vouchers, Transfers, Inboxes.
 *       -- Basket Currencies, Markets, Payment Plans.
 *       -- Signed, XML, Ricardian-style Contracts.
 *       -- Scripted smart contracts.
 *
 *  Copyright (C) 2010-2013 by "Fellow Traveler" (A pseudonym)
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
 *   -- otlib.........A class library.......LICENSE:...LAGPLv3
 *   -- otapi.........A client API..........LICENSE:...LAGPLv3
 *   -- opentxs/ot....Command-line client...LICENSE:...LAGPLv3
 *   -- otserver......Server Application....LICENSE:....AGPLv3
 *  Github.com/FellowTraveler/Open-Transactions/wiki/Components
 *
 *  All of the above OT components were designed and written by
 *  Fellow Traveler, with the exception of Moneychanger, which
 *  was contracted out to Vicky C (bitcointrader4@gmail.com).
 *  The open-source community has since actively contributed.
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
 *   (==> This means if you are only using the OT API, then you
 *   don't have to open-source your code--only your changes to
 *   Open-Transactions itself must be open source. Similar to
 *   LGPLv3, except it applies to software-as-a-service, not
 *   just to distributing binaries.)
 *
 *   Extra WAIVER for OpenSSL, Lucre, and all other libraries
 *   used by Open Transactions: This program is released under
 *   the AGPL with the additional exemption that compiling,
 *   linking, and/or using OpenSSL is allowed. The same is true
 *   for any other open source libraries included in this
 *   project: complete waiver from the AGPL is hereby granted to
 *   compile, link, and/or use them with Open-Transactions,
 *   according to their own terms, as long as the rest of the
 *   Open-Transactions terms remain respected, with regard to
 *   the Open-Transactions code itself.
 *
 *   Lucre License:
 *   This code is also "dual-license", meaning that Ben Lau-
 *   rie's license must also be included and respected, since
 *   the code for Lucre is also included with Open Transactions.
 *   See Open-Transactions/src/otlib/lucre/LUCRE_LICENSE.txt
 *   The Laurie requirements are light, but if there is any
 *   problem with his license, simply remove the Lucre code.
 *   Although there are no other blind token algorithms in Open
 *   Transactions (yet. credlib is coming), the other functions
 *   will continue to operate.
 *   See Lucre on Github:  https://github.com/benlaurie/lucre
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
 Version: GnuPG v1.4.9 (Darwin)
 
 iQIcBAEBAgAGBQJRSsfJAAoJEAMIAO35UbuOQT8P/RJbka8etf7wbxdHQNAY+2cC
 vDf8J3X8VI+pwMqv6wgTVy17venMZJa4I4ikXD/MRyWV1XbTG0mBXk/7AZk7Rexk
 KTvL/U1kWiez6+8XXLye+k2JNM6v7eej8xMrqEcO0ZArh/DsLoIn1y8p8qjBI7+m
 aE7lhstDiD0z8mwRRLKFLN2IH5rAFaZZUvj5ERJaoYUKdn4c+RcQVei2YOl4T0FU
 LWND3YLoH8naqJXkaOKEN4UfJINCwxhe5Ke9wyfLWLUO7NamRkWD2T7CJ0xocnD1
 sjAzlVGNgaFDRflfIF4QhBx1Ddl6wwhJfw+d08bjqblSq8aXDkmFA7HeunSFKkdn
 oIEOEgyj+veuOMRJC5pnBJ9vV+7qRdDKQWaCKotynt4sWJDGQ9kWGWm74SsNaduN
 TPMyr9kNmGsfR69Q2Zq/FLcLX/j8ESxU+HYUB4vaARw2xEOu2xwDDv6jt0j3Vqsg
 x7rWv4S/Eh18FDNDkVRChiNoOIilLYLL6c38uMf1pnItBuxP3uhgY6COm59kVaRh
 nyGTYCDYD2TK+fI9o89F1297uDCwEJ62U0Q7iTDp5QuXCoxkPfv8/kX6lS6T3y9G
 M9mqIoLbIQ1EDntFv7/t6fUTS2+46uCrdZWbQ5RjYXdrzjij02nDmJAm2BngnZvd
 kamH0Y/n11lCvo1oQxM+
 =uSzz
 -----END PGP SIGNATURE-----
 **************************************************************/

#include <stdafx.h>

#define OT_OPTIONS_FILE_DEFAULT	"command-line-ot.opt"
#define CLIENT_PATH_DEFAULT	"client_data" //should get programmatically



#define CA_FILE             "certs/special/ca.crt"
#define KEY_FILE            "certs/special/client.pem"

#include <cstring>
#include <cstdio>
#include <cstdlib>


#include <string>

#include <iostream>

#include <istream>
#include <ostream>
#include <iterator>

#ifdef _WIN32
#include <WinsockWrapper.h> 
#endif

#ifdef _WIN32
#include <Shlobj.h>
#endif


extern "C" 
{
#ifdef _WIN32
#else
#include <netinet/in.h>
#endif
}

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include "simpleini/SimpleIni.h"



// ---------------------------------------------------------------------------

#if defined(OT_ZMQ_MODE)

#include <zmq.hpp>


#endif
// ---------------------------------------------------------------------------

#ifdef _WIN32
void OT_Sleep(int nMS);
#endif

// ---------------------------------------------------------------------------

#include "OTStorage.h"

#include "OTString.h"
#include "OTASCIIArmor.h"
#include "OTClient.h"
#include "OTServerConnection.h"
#include "OTMessage.h"
#include "OTString.h"
#include "OTWallet.h"
#include "OTPseudonym.h"
#include "OTEnvelope.h"
#include "OTPurse.h"
#include "OTCheque.h"
#include "OpenTransactions.h"
#include "OTPaymentPlan.h"
#include "OTLog.h"

#include "OTScript.h"


//  Just Include OTAPI_Wrapper, as it is now our pure C++ api.
//

#include "OTAPI.h"
#include "OT_ME.h"

// ---------------------------------------------------------------------------

// This global variable contains an OTWallet, an OTClient, etc. 
// It's the C++ high-level interace to OT. 
// Any client software will have an instance of this.
//
// Use OTAPI_Wrap::OTAPI()->
//
// Note: In the main function, before using OT, must call OT_API::InitOTAPI--(which
// calls OTLog::OT_Init())--then after calling that, must call OTAPI_Wrap::OTAPI()->Init() in
// the main function.

// ---------------------------------------------------------------------------

/*
OT by default will look here: "~/.ot/ot_init.cfg"

Inside that file are these contents:
[paths]
client_path=~/.ot/client_data
server_path=~/.ot/server_data

If none of the snazzy ini files or config files, or client_data/server_data folders
are found, then the default locations are ./client_data and ./server_data
MEANING: If it can't find it in your $HOME/.ot/ot_init.cfg file, then it looks
in the current directory instead.

(I'm REMOVING the option to pass the location in on the command line, at least without a switch.)
*/


#include "anyoption.h"


void HandleCommandLineArguments( int argc, char* argv[], AnyOption * opt );


/*

--server     (SERVER_ID)

USAGE:  ot -COMMAND [AMOUNT] [--from ACCT/NYM/ASSET] [--to ACCT or NYM]

ot -w 100    (WITHDRAW 100 FROM DEFAULT ACCOUNT.)
ot -d 100    (DEPOSIT FROM DEFAULT PURSE TO DEFAULT ACCOUNT.)
ot -t 100 --to j43k  (TRANSFER 100 FROM DEFAULT ACCT TO ACCT STARTING WITH j43k)
ot -t 100 --from qwer --to j43k  (TRANSFER 100 from ACCT STARTING WITH qwer TO ACCT starting j43k)

*/





// -------------------------------------------------------------------------------
// If false, error happened, usually based on what user just attemped.
//
bool SetupPointersForWalletMyNymAndServerContract(std::string & str_ServerID,
	std::string & str_MyNym,
	OTPseudonym *& pMyNym, 
	OTWallet *& pWallet, 
	OTServerContract *& pServerContract)
{
    // If we got down here, that means there were no commands on the command line 
    // (That's why we dropped into the OT prompt.)
    // However, there still may have been OPTIONS -- and if so, we'll go ahead and
    // load the wallet. (If there were NOT ANY OPTIONS, then we do NOT load the wallet,
    // although there is a COMMAND for doing that.)
    //

	OTAPI_Wrap::OTAPI()->LoadWallet();

    // -----------------------------------------------------        
    //
	pWallet = OTAPI_Wrap::OTAPI()->GetWallet();
    
    if (NULL == pWallet)
    {
        OTLog::Output(0, "The wallet object is still NULL, somehow. Please load it.\n");
        return false;
    }
    
    // Below this point, pWallet is available :-)
    // -----------------------------------------------------
    
    if (str_ServerID.size() > 0 )
    {        
        const OTIdentifier SERVER_ID(str_ServerID.c_str());
        
        pServerContract = pWallet->GetServerContract(SERVER_ID);
        // If failure, then we try PARTIAL match.
        if (NULL == pServerContract)
            pServerContract = pWallet->GetServerContractPartialMatch(str_ServerID);
        
        if (NULL != pServerContract)
        {
            OTString strTemp;
            pServerContract->GetIdentifier(strTemp);
            
            str_ServerID = strTemp.Get();
            OTLog::vOutput(0, "Using as server: %s\n", str_ServerID.c_str());
        }
        else
        {
            OTLog::Output(0, "Unable to find a server contract. Please use the option:  --server SERVER_ID\n"
                          "(Where SERVER_ID is the server ID. Partial matches are accepted if the contract is already in the wallet.)\n"
                          "Also, see default values located in ~/.ot/comand-line-ot.opt \n");
//          return false;
        }
    }
    // Below this point, pServerContract MAY be available, but also may be NULL.
    //
    // ------------------------------------------------------------------------------			
    
    if ( str_MyNym.size() > 0 )
    {
        const OTIdentifier MY_NYM_ID(str_MyNym.c_str());
        
        pMyNym = pWallet->GetNymByID(MY_NYM_ID);
        
        // If failure, then we try PARTIAL match.
        if (NULL == pMyNym)
            pMyNym = pWallet->GetNymByIDPartialMatch( str_MyNym );
        
        if (NULL != pMyNym)
        {
            OTString strTemp;
            pMyNym->GetIdentifier(strTemp);
            
            str_MyNym = strTemp.Get();
            OTLog::vOutput(0, "Using as mynym: %s\n", str_MyNym.c_str());
        }
        else
        {
            OTLog::Output(0, "==> Unable to find My Nym. Please use the option:   --mynym USER_ID\n"
                          "(Where USER_ID is the Nym's ID. Partial matches are accepted if the nym is already in the wallet.)\n"
                          "Also, see default values located in ~/.ot/comand-line-ot.opt \n");
//          return false;
        }
    } // Below this point, pMyNym MIGHT be a valid pointer, or MIGHT be NULL.
        
    // Below THIS point, there's no guarantee of pWallet, though it MIGHT be there.
    // Same with pServerContract. (MIGHT be there.)
    
    return true;
}





void HandleCommandLineArguments( int argc, char* argv[], AnyOption * opt)
{
	if (NULL == opt)
		return;

	OTString strConfigPath(OTPaths::AppDataFolder());
	{ bool GetConfigPathSuccess = strConfigPath.Exists() && 3 < strConfigPath.GetLength();
	OT_ASSERT_MSG(GetConfigPathSuccess,"HandleCommandLineArguments:  Must Set Conifg Path First!"); }



	/* 1. CREATE AN OBJECT */
	//    AnyOption *opt = new AnyOption();
	//    OT_ASSERT(NULL != opt);
	//    OTCleanup<AnyOption> theOptionAngel(opt);

	// -----------------------------------------------------
	/* 2. SET PREFERENCES  */
	//opt->noPOSIX(); /* do not check for POSIX style character options */
	//opt->setVerbose(); /* print warnings about unknown options */
	//opt->autoUsagePrint(true); /* print usage for bad options */

	// -----------------------------------------------------
    /* 3. SET THE USAGE/HELP   */
    opt->addUsage( "" );
    opt->addUsage( " **** NOTE: DO NOT USE 'ot' !! Use 'opentxs help' instead! *** OT CLI Usage:  " );
    opt->addUsage( "" );
    opt->addUsage( "ot  --stat (Prints the wallet contents)    ot --prompt (Enter the OT prompt)" );
    opt->addUsage( "ot  [-h|-?|--help]    (Prints this help)   ot --script <filename> [--args \"key value ...\"]" );
    opt->addUsage( "The '|' symbol means use --balance or -b, use --withdraw or -w, etc." );
    opt->addUsage( "The brackets '[]' show required arguments, where default values are" );
    opt->addUsage( "normally expected to be found in:   ~/.ot/command-line-ot.opt" );
    opt->addUsage( "ot  --balance  | -b          [--myacct <acct_id>]   (Display account balance)" );
    opt->addUsage( "ot  --withdraw | -w <amount> [--myacct <acct_id>]   (Withdraw as CASH)" );
    opt->addUsage( "ot  --transfer | -t <amount> [--myacct <acct_id>] [--hisacct <acct_id>]" );
    opt->addUsage( "ot  --cheque   | -c <amount> [--myacct <acct_id>] [--hisnym  <nym_id> ]" );
    opt->addUsage( "ot  --voucher  | -v <amount> [--myacct <acct_id>] [--hisnym  <nym_id> ]" );
    opt->addUsage( "ot  --depositcheque  [--myacct <acct_id>]   (Deposit a cheque.)" );
    opt->addUsage( "ot  --depositpurse   [--myacct <acct_id>]   (Deposit a cash purse.)" );
    opt->addUsage( "ot  --deposittokens  [--myacct <acct_id>]   (Deposit individual cash tokens.)" );
    opt->addUsage( "ot  --inbox    | -i  [--myacct <acct_id>]   (Display the inbox.)" );
    opt->addUsage( "ot  --sign     | -s  [--mynym  <nym_id> ]   (Sign a contract.)" );
    opt->addUsage( "ot  --verify         [--mynym  <nym_id> ]   (Verify a signature.)" );
    opt->addUsage( "ot  --purse    | -p   <arguments>           (Display a purse.)");
    opt->addUsage( "  Arguments:     [--mynym  <nym_id> ] [--mypurse <asset_type_id>]" );
    opt->addUsage( "ot  --refresh  | -r  [--myacct <acct_id>]    (Download account files from server.)");
    opt->addUsage( "ot  --refreshnym     [--mynym  <nym_id> ]    (Download nym files from server.)");
    opt->addUsage( "ot  --marketoffer    [--mynym  <nym_id> ]    (Place an offer on a market.)" );
    opt->addUsage( "Also, [--server <server_id>] will work with all of the above." );
    opt->addUsage( "" );
    opt->addUsage( "Recurring payments:" );
    opt->addUsage( "ot --proposeplan  <arguments>   (Merchant)" );
    opt->addUsage( "  Arguments: [--mynym  <nym_id> ] [--myacct  <acct_id>]  (continued.)" );
    opt->addUsage( "  Continued: [--hisnym <nym_id> ] [--hisacct <acct_id> ]");
    opt->addUsage( "ot --confirmplan  <arguments>   (Customer)" );
    opt->addUsage( "ot --activateplan <arguments>   (Customer again)" );
    opt->addUsage( "  Arguments: [--mynym  <nym_id> ] [--myacct  <acct_id>]" );
    opt->addUsage( " **** NOTE: DO NOT USE 'ot' !! Use 'opentxs help' instead! ***" );
    
    // -----------------------------------------------------
    /* 4. SET THE OPTION STRINGS/CHARACTERS */
    //
    // COMMAND LINE *AND* RESOURCE FILE
        
//  opt->setOption(  "server" );      /* an option (takes an argument), supporting only long form */
    
	// -----------------------------------------------------
	/* 4. SET THE OPTION STRINGS/CHARACTERS */
	//
	// COMMAND LINE *AND* RESOURCE FILE

	//  opt->setOption(  "server" );      /* an option (takes an argument), supporting only long form */

	// -----------------------------------------------------

	// COMMAND LINE ONLY
	/* for options that will be checked only on the command and line not in option/resource file */
	//    opt->setCommandFlag(  "zip" , 'z'); /* a flag (takes no argument), supporting long and short form */
	opt->setCommandOption("withdraw" , 'w');   // withdraw from acct to purse, myacct, topurse
	opt->setCommandOption("transfer" , 't');   // transfer acct-to-acct, myacct, toacct
	opt->setCommandOption("cheque" ,   'c');   // write a cheque   myacct, tonym
	opt->setCommandOption("voucher" ,  'v');   // withdraw voucher myacct, tonym
	opt->setCommandFlag(  "marketoffer"   );   // add an offer to the market.
	opt->setCommandFlag(  "balance" ,  'b');   // Display account balance
	opt->setCommandFlag(  "depositcheque" );   // deposit a cheque to myacct
	opt->setCommandFlag(  "depositpurse"  );   // deposit cash purse to myacct
	opt->setCommandFlag(  "deposittokens" );   // deposit individual cash tokens to myacct
	opt->setCommandFlag(  "proposeplan"   );   // Merchant proposes a payment plan.
	opt->setCommandFlag(  "confirmplan"   );   // Customer confirms a payment plan.
	opt->setCommandFlag(  "activateplan"  );   // Customer activates a payment plan.
	opt->setCommandFlag(  "inbox" ,    'i');   // displays inbox (for ACCT_ID...)
	opt->setCommandFlag(  "sign" ,     's');   // sign a contract  mynym
	opt->setCommandFlag(  "verify"        );   // verify a signature
	opt->setCommandFlag(  "purse" ,    'p');   // display purse contents.
	opt->setCommandFlag(  "refresh" ,  'r');   // refresh intermediary files from server + verify against last receipt.
	opt->setCommandFlag(  "refreshnym"    );   // refresh intermediary files from server + verify against last receipt.
	opt->setCommandFlag(  "stat" );            // print out the wallet contents.
	opt->setCommandFlag(  "prompt" );          // Enter the OT prompt.
	opt->setCommandOption("script" );          // Process a script from out of a scriptfile
	opt->setCommandOption("args");             // Pass custom arguments from command line: --args "key1 value1 key2 \"here is value2\" key3 value3"

	opt->setCommandFlag("help", 'h');   // the Help screen.
	opt->setCommandFlag('?');           // the Help screen.

	/*
	--myacct   (ACCT ID)
	--mynym    (NYM ID)
	--mypurse  (ASSET TYPE ID)

	--toacct   (ACCT ID)
	--tonym    (NYM ID)
	--topurse  (ASSET TYPE ID)
	*/  
	opt->setCommandOption("server");

	opt->setCommandOption("myacct");
	opt->setCommandOption("mynym");
	opt->setCommandOption("mypurse");
	opt->setCommandOption("hisacct");
	opt->setCommandOption("hisnym");
	opt->setCommandOption("hispurse");

	// NOTE: Above and Below me are IDs. This interface should allow PARTIAL IDs.
	// -----------------------------------------------------

	// RESOURCE FILE ONLY
	/* for options that will be checked only from the option/resource file */
	opt->setFileOption(  "defaultserver" ); /* an option (takes an argument), supporting only long form */

	opt->setFileOption(  "defaultmyacct" ); /* an option (takes an argument), supporting only long form */
	opt->setFileOption(  "defaultmynym" ); /* an option (takes an argument), supporting only long form */
	opt->setFileOption(  "defaultmypurse" ); /* an option (takes an argument), supporting only long form */
	opt->setFileOption(  "defaulthisacct" ); /* an option (takes an argument), supporting only long form */
	opt->setFileOption(  "defaulthisnym" ); /* an option (takes an argument), supporting only long form */
	opt->setFileOption(  "defaulthispurse" ); /* an option (takes an argument), supporting only long form */
	/*    
	--defaultmyacct   (ACCT ID)
	--defaultmynym    (NYM ID)
	--defaultmypurse  (ASSET TYPE ID)

	--defaulttoacct   (ACCT ID)
	--defaulttonym    (NYM ID)
	--defaulttopurse  (ASSET TYPE ID)
	*/

	// -----------------------------------------------------
	/* 5. PROCESS THE COMMANDLINE AND RESOURCE FILE */

	/* read options from a option/resource file with ':' separated options or flags, one per line */

	OTString strOptionsFile(OT_OPTIONS_FILE_DEFAULT), strIniFileExact;
	{ bool bBuildFullPathSuccess = OTPaths::RelativeToCanonical(strIniFileExact,strConfigPath,strOptionsFile);
	OT_ASSERT_MSG(bBuildFullPathSuccess,"Unalbe to set Full Path"); }

	// -----------------------------------------------------
	opt->processFile( strIniFileExact.Get() );  
	// -----------------------------------------------------    
	opt->processCommandArgs( argc, argv );
}



/*
I'm starting to need this in possibly multiple places below, so I 
made a function to avoid duplicating code. These are values such
as "my account ID" and "his NymID" that are provided on the command
line, and which also can be defaulted in a config file in ~/.ot
*/
void CollectDefaultedCLValues(AnyOption *opt,
	std::string & str_ServerID,
	std::string & str_MyAcct,
	std::string & str_MyNym,
	std::string & str_MyPurse,
	std::string & str_HisAcct,
	std::string & str_HisNym,
	std::string & str_HisPurse)
{
	OT_ASSERT(NULL != opt);

	OTAPI_Wrap::Output(1, "\n");

	// First we pre-set all the values based on the defaults from the options file.
	//
	if( opt->getValue( "defaultserver" ) != NULL )
	{
//      cerr << "Server default: " << (str_ServerID = opt->getValue( "defaultserver" )) << endl;        
		str_ServerID = opt->getValue( "defaultserver" );
		OTLog::vOutput(1, "Server default: %s \n", str_ServerID.c_str());
	}

	if( opt->getValue( "defaultmyacct" ) != NULL )
	{
//      cerr << "MyAcct default: " << (str_MyAcct = opt->getValue( "defaultmyacct" )) << endl;
		str_MyAcct = opt->getValue( "defaultmyacct" );
		OTLog::vOutput(1, "MyAcct default: %s \n", str_MyAcct.c_str());
	}
	if( opt->getValue( "defaultmynym" ) != NULL )
	{
//      cerr << "MyNym default: " << (str_MyNym = opt->getValue( "defaultmynym" )) << endl;
		str_MyNym = opt->getValue( "defaultmynym" );
		OTLog::vOutput(1, "MyNym default: %s \n", str_MyNym.c_str());
	}
	if( opt->getValue( "defaultmypurse" ) != NULL )
	{
//      cerr << "MyPurse default: " << (str_MyPurse = opt->getValue( "defaultmypurse" )) << endl;
		str_MyPurse = opt->getValue( "defaultmypurse" );
		OTLog::vOutput(1, "MyPurse default: %s \n", str_MyPurse.c_str());
	}

	if( opt->getValue( "defaulthisacct" ) != NULL )
	{
//      cerr << "HisAcct default: " << (str_HisAcct = opt->getValue( "defaulthisacct" )) << endl;
		str_HisAcct = opt->getValue( "defaulthisacct" );
		OTLog::vOutput(1, "HisAcct default: %s \n", str_HisAcct.c_str());
	}
	if( opt->getValue( "defaulthisnym" ) != NULL )
	{
//      cerr << "HisNym default: " << (str_HisNym = opt->getValue( "defaulthisnym" )) << endl;
		str_HisNym = opt->getValue( "defaulthisnym" );
		OTLog::vOutput(1, "HisNym default: %s \n", str_HisNym.c_str());
	}
	if( opt->getValue( "defaulthispurse" ) != NULL )
	{
//      cerr << "HisPurse default: " << (str_HisPurse = opt->getValue( "defaulthispurse" )) << endl;
		str_HisPurse = opt->getValue( "defaulthispurse" );
		OTLog::vOutput(1, "HisPurse default: %s \n", str_HisPurse.c_str());
	}

	// --------------
	// Next, we overwrite those with any that were passed in on the command line.

	if( opt->getValue( "server" ) != NULL )
	{
//      cerr << "Server from command-line: " << (str_ServerID = opt->getValue( "server" )) << endl;
		str_ServerID = opt->getValue( "server" );
		OTLog::vOutput(1, "Server from command-line: %s \n", str_ServerID.c_str());
	}

	if( opt->getValue( "myacct" ) != NULL )
	{        
//      cerr << "MyAcct from command-line: " << (str_MyAcct = opt->getValue( "myacct" )) << endl;
		str_MyAcct = opt->getValue( "myacct" );
		OTLog::vOutput(1, "MyAcct from command-line: %s \n", str_MyAcct.c_str());
	}
	if( opt->getValue( "mynym" ) != NULL )
	{
//      cerr << "MyNym from command-line: " << (str_MyNym = opt->getValue( "mynym" )) << endl;
		str_MyNym = opt->getValue( "mynym" );
		OTLog::vOutput(1, "MyNym from command-line: %s \n", str_MyNym.c_str());
	}
	if( opt->getValue( "mypurse" ) != NULL )
	{
//      cerr << "MyPurse from command-line: " << (str_MyPurse = opt->getValue( "mypurse" )) << endl;
		str_MyPurse = opt->getValue( "mypurse" );
		OTLog::vOutput(1, "MyPurse from command-line: %s \n", str_MyPurse.c_str());
	}

	if( opt->getValue( "hisacct" ) != NULL )
	{
//      cerr << "HisAcct from command-line: " << (str_HisAcct = opt->getValue( "hisacct" )) << endl;
		str_HisAcct = opt->getValue( "hisacct" );
		OTLog::vOutput(1, "HisAcct from command-line: %s \n", str_HisAcct.c_str());
	}
	if( opt->getValue( "hisnym" ) != NULL )
	{
//      cerr << "HisNym from command-line: " << (str_HisNym = opt->getValue( "hisnym" )) << endl;
		str_HisNym = opt->getValue( "hisnym" );
		OTLog::vOutput(1, "HisNym from command-line: %s \n", str_HisNym.c_str());
	}
	if( opt->getValue( "hispurse" ) != NULL )
	{
//      cerr << "HisPurse from command-line: " << (str_HisPurse = opt->getValue( "hispurse" )) << endl;
		str_HisPurse = opt->getValue( "hispurse" );
		OTLog::vOutput(1, "HisPurse from command-line: %s \n", str_HisPurse.c_str());
	}
}

// *************************************   MAIN FUNCTION   *************************************



int main(int argc, char* argv[])
{    
	// --------------------------------------------
	class __OTclient_RAII
	{
	public:
		__OTclient_RAII()
		{
			// OT_API class exists only on the client side.

			OTAPI_Wrap::AppInit();     // SSL gets initialized in here, before any keys are loaded.       
		}
		~__OTclient_RAII()
		{
			OTAPI_Wrap::AppCleanup();
		}
	};
	// --------------------------------------------
	//
	// This makes SURE that AppCleanup() gets called before main() exits (without any
	// twisted logic being necessary below, for that to happen.)
	//
	__OTclient_RAII   the_client_cleanup;
	// -------------------------------------------------------------------
    //

	if (NULL == OTAPI_Wrap::It()) return -1;  // error out if we don't have the API.

	OTString strConfigPath(OTPaths::AppDataFolder());
	bool bConfigPathFound = strConfigPath.Exists() && 3 < strConfigPath.GetLength();

	OT_ASSERT_MSG(bConfigPathFound,"RegisterAPIWithScript: Must set Config Path first!\n");

	OTLog::vOutput(1, "Using configuration path:  %s\n", strConfigPath.Get());
	// -------------------------------------------------------------------

	// COMMAND-LINE OPTIONS (and default values from files.)
	//
	AnyOption *opt = new AnyOption();
	OT_ASSERT(NULL != opt);
	OTCleanup<AnyOption> theOptionAngel(opt);

	// Process the command line args
	//
	HandleCommandLineArguments( argc, argv, opt);


	// command line values such as account ID, Nym ID, etc. 
	// Also available as defaults in a config file in the ~/.ot folder
	//
	std::string str_ServerID;

	std::string str_MyAcct;
	std::string str_MyNym;
	std::string str_MyPurse;

	std::string str_HisAcct;
	std::string str_HisNym;
	std::string str_HisPurse;

	CollectDefaultedCLValues(opt,
		str_ServerID,
		str_MyAcct,
		str_MyNym,
		str_MyPurse,
		str_HisAcct,
		str_HisNym,
		str_HisPurse);
	// -----------------------------------------------------
	// Users can put --args "key value key value key value etc"
	// Then they can access those values from within their scripts.

	std::string str_Args;

	if( opt->getValue( "args" ) != NULL )
		cerr << "User-defined arguments aka:  --args " << (str_Args = opt->getValue( "args" )) << endl;

	// -----------------------------------------------------
	/*  USAGE SCREEN (HELP) */
	//
	if( opt->getFlag( "help" ) || opt->getFlag( 'h' )  || opt->getFlag( '?' ) )
	{
		opt->printUsage();

		return 0;
	}
	// -----------------------------------------------------

	bool bIsCommandProvided = false;

	// See if there's a COMMAND chosen at command line.
	//
	if ( opt ->hasOptions())
	{
		// Below are COMMANDS (only one of them can be true...)
		//

		if( opt->getValue( 'w' ) != NULL  || opt->getValue( "withdraw" ) != NULL  )
		{ bIsCommandProvided = true; cerr << "withdraw amount = " << opt->getValue( 'w' ) << endl ; }
		else if( opt->getValue( 't' ) != NULL  || opt->getValue( "transfer" ) != NULL  )
		{ bIsCommandProvided = true; cerr << "transfer amount = " << opt->getValue( 't' ) << endl ; }
		else if( opt->getValue( 'c' ) != NULL  || opt->getValue( "cheque" ) != NULL  )
		{ bIsCommandProvided = true; cerr << "cheque amount = " << opt->getValue( 'c' ) << endl ; }
		else if(  opt->getFlag( "marketoffer" ) == true  )
		{ bIsCommandProvided = true; cerr << "marketoffer flag set " << endl ; }
		else if( opt->getValue( 'v' ) != NULL  || opt->getValue( "voucher" ) != NULL  )
		{ bIsCommandProvided = true; cerr << "voucher amount = " << opt->getValue( 'v' ) << endl ; }
		else if( opt->getFlag( "depositcheque" ) )
		{ bIsCommandProvided = true; cerr << "deposit cheque flag set " << endl ; }
		else if( opt->getFlag( "depositpurse" ) ) 
		{ bIsCommandProvided = true; cerr << "deposit purse flag set " << endl ; }
		else if( opt->getFlag( "deposittokens" ) ) 
		{ bIsCommandProvided = true; cerr << "deposit tokens flag set " << endl ; }
		else if( opt->getFlag( "proposepaymentplan" ) ) 
		{ bIsCommandProvided = true; cerr << "proposepaymentplan flag set " << endl ; }
		else if( opt->getFlag( "confirmpaymentplan" ) ) 
		{ bIsCommandProvided = true; cerr << "confirm payment plan flag set " << endl ; }
		else if( opt->getFlag( "activatepaymentplan" ) ) 
		{ bIsCommandProvided = true; cerr << "activate payment plan flag set " << endl ; }
		else if( opt->getFlag( 'b' )  || opt->getFlag( "balance" )  )
		{ bIsCommandProvided = true; cerr << "balance flag set " << endl ; }
		else if( opt->getFlag( 'i' )  || opt->getFlag( "inbox" )  )
		{ bIsCommandProvided = true; cerr << "inbox flag set " << endl ; }
		else if( opt->getFlag( 'p' ) || opt->getFlag( "purse" )  )
		{ bIsCommandProvided = true; cerr << "purse flag set " << endl ; }
		else if( opt->getFlag( 's' ) || opt->getFlag( "sign" ))
		{ bIsCommandProvided = true; cerr << "sign flag set " << endl ; }
		else if( opt->getFlag( "verify" )  )
		{ bIsCommandProvided = true; cerr << "verify flag set " << endl; }
		else if( opt->getFlag( "stat" )   )
		{ bIsCommandProvided = true; cerr << "stat flag set "  << endl ; }
		else if( opt->getFlag( "prompt" )   )
		{ bIsCommandProvided = true; cerr << "prompt flag set "  << endl ; }
		else if( opt->getValue( "script" )  != NULL )
		{ bIsCommandProvided = true; cerr << "script filename: " << opt->getValue( "script" ) << endl ; }
		else if( opt->getFlag( 'r' ) || opt->getFlag( "refresh" )   )
		{ bIsCommandProvided = true; cerr << "refresh flag set "  << endl ; }
		else if( opt->getFlag( "refreshnym" )   )
		{ bIsCommandProvided = true; cerr << "refreshnym flag set "  << endl ; }

		cerr << endl ;
	}
	else
		bIsCommandProvided = false;

	// ---------------------------------------------------------------------------------------
	//
	if(!(opt->getArgc() > 0) &&
		(false == bIsCommandProvided) )   // If no command was provided (though other command-line options may have been...) 
	{                           // then we expect a script to come in through stdin, and we run it through the script interpreter!
		OTLog::Output(0, "\n\nYou probably don't want to do this... Use CTRL-C, and try \"ot --help\" for instructions.\n\n "
			"==> Expecting ot script from standard input. (Terminate with CTRL-D):\n\n");

		// ----------------------------------------
		// don't skip the whitespace while reading
		std::cin >> std::noskipws;

		// use stream iterators to copy the stream to a string
		std::istream_iterator<char> it(std::cin);
		std::istream_iterator<char> end;
		std::string results(it, end);

		// -----------------------------------------------
        OT_ME madeEasy;
        madeEasy.ExecuteScript_ReturnVoid(results, ("stdin"));
		// --------------------------------------------------------------------					

		return 0;
	}
	else // Else a command WAS provided at the command line, so we execute a single time, once just for that command.
	{
		OTWallet * pWallet = NULL;
		OTServerContract * pServerContract = NULL;
		OTPseudonym * pMyNym = NULL;

		// This does LoadWallet, andif Nym or Server IDs were provided, loads those up as well.
		// (They may still be NULL after this call, however.)
		//
		bool bMainPointersSetupSuccessful =
			SetupPointersForWalletMyNymAndServerContract(str_ServerID, str_MyNym, pMyNym, pWallet, pServerContract);

		OT_ASSERT_MSG(bMainPointersSetupSuccessful,"main: SetupPointersForWalletMyNymAndServerContract failed to return true");
        
        // Below this point, pWallet is available :-)
        // -----------------------------------------------------
        // Later I can split the below commands into "those that need a server contract"
        // and "those that don't need a server contract", and put this code between them.
        // That's what the OT Prompt loop does. For now I'm making things easy here by just
        // making it a blanket requirement.
        //
        if (NULL == pServerContract) 
        {
            OTLog::Output(0, "Unable to find a server contract to use. Please use the option: --server SERVER_ID\n"
                          "(Where SERVER_ID is the Server's ID. Partial matches ARE accepted.)\n");
//          return 0;
        }

        OTIdentifier theServerID;
        OTString     strServerID;

        if (NULL != pServerContract)
        {
            pServerContract->GetIdentifier(theServerID);
            theServerID.GetString(strServerID);
        }
        // -----------------------------------------------------
//      int       nServerPort = 0;
//      OTString  strServerHostname;
        // ------------------------------------------------------------------------------			            
        // You can't just connect to any hostname and port.
        // Instead, you give me the Server Contract, and *I'll* look up all that stuff FOR you...
        // (We verify this up here, but use it at the bottom of the function once the message is set up.)
        //
        
//      if (false == pServerContract->GetConnectInfo(strServerHostname, nServerPort))
//      {
//          OTLog::vError("Failed retrieving connection info from server contract: %s\n",
//                        strServerID.Get());
//          return 0;
//      }

        // Below this point, pWallet and pServerContract are both available.
        // UPDATE: Not necessarily... (pServerContract may be NULL...)
        //
        // ***********************************************************
        
        OTAccount * pMyAccount  = NULL;
        OTAccount * pHisAccount = NULL;
        
        if( str_MyAcct.size() > 0 )
        {
         	const OTIdentifier MY_ACCOUNT_ID(str_MyAcct.c_str());
			
			pMyAccount = pWallet->GetAccount(MY_ACCOUNT_ID);

            // If failure, then we try PARTIAL match.
            if (NULL == pMyAccount)
                pMyAccount = pWallet->GetAccountPartialMatch( str_MyAcct );
            
            if (NULL != pMyAccount)
            {
                OTString strTemp;
                pMyAccount->GetPurportedAccountID().GetString(strTemp);
                
                str_MyAcct = strTemp.Get();
                OTLog::vOutput(0, "Using as myacct: %s\n", str_MyAcct.c_str());
            }
            else // Execution aborts if we cannot find MyAcct when one was provided.
            {
                OTLog::vOutput(0, "Aborting: Unable to find specified myacct: %s\n", str_MyAcct.c_str());
                return 0;
            }
        }
        // -------------------------------------------------------------------------
        // TODO: I wouldn't have HIS account in MY wallet -- I'd only have his account ID.
        // Therefore need to be able to retrieve this info from the ADDRESS BOOK (in order
        // to be able to do PARTIAL MATCHES...)
        //
        if ( str_HisAcct.size() > 0 )
        {
         	const OTIdentifier HIS_ACCOUNT_ID(str_HisAcct.c_str());
            
            pHisAccount = pWallet->GetAccount(HIS_ACCOUNT_ID);
            
            // If failure, then we try PARTIAL match.
            if (NULL == pHisAccount)
                pHisAccount = pWallet->GetAccountPartialMatch( str_HisAcct );
            // ------------------------------------------
            if (NULL != pHisAccount)
            {
                OTString strTemp;
                pHisAccount->GetPurportedAccountID().GetString(strTemp);
                
                str_HisAcct = strTemp.Get();
                OTLog::vOutput(0, "Using as hisacct: %s\n", str_HisAcct.c_str());
            }
            
            // Execution continues, even if we fail to find his account.
            // (Only my accounts will be in my wallet. Anyone else's account
            // will exist on the server, even if it's not in my wallet. Therefore
            // we still allow users to use HisAcctID since their server messages
            // will usually actually work.)
            //
            // Again: Just because account lkjsf09234lkjafkljasd098q345lkjasdf doesn't
            // appear in my wallet, doesn't mean the account doesn't exist on the server
            // and in reality. Therefore I must assume, if I didn't find it by abbreviation,
            // that it exists exactly as entered. The server message will just fail, if it
            // doesn't exist. (But then that's the user's fault...)
            //
            // We can still keep account IDs in the address book, even if they aren't
            // in the wallet (since they're owned by someone else...)
            //
        }
        
        // ***********************************************************

        // I put this here too since I think it's required in all cases.
        // Update: commented out the return in order to allow for empty wallets.
        //
        if (NULL == pMyNym) // Todo maybe move this check to the commands below (ONLY the ones that use a nym.)
        {
            OTLog::Output(0, "Unable to find My Nym. Please use the option:   --mynym USER_ID\n"
                          "(Where USER_ID is the Nym's ID. Partial matches and names are accepted.)\n");
//          return 0;
        }
        
        OTIdentifier MY_NYM_ID;
        
        if (NULL != pMyNym)
            pMyNym->GetIdentifier(MY_NYM_ID);
        // -----------------------------------------------
        OTPseudonym * pHisNym = NULL;

        if ( str_HisNym.size() > 0 )
        {
         	const OTIdentifier HIS_NYM_ID(str_HisNym.c_str());
            
            pHisNym = pWallet->GetNymByID(HIS_NYM_ID);
            // If failure, then we try PARTIAL match.
            if (NULL == pHisNym)
                pHisNym = pWallet->GetNymByIDPartialMatch( str_HisNym );
            // ----------------------------
            if (NULL != pHisNym)
            {
                OTString strTemp;
                pHisNym->GetIdentifier(strTemp);
                
                str_HisNym = strTemp.Get();
                OTLog::vOutput(0, "Using as 'his' nym: %s\n", str_HisNym.c_str());
            }
        }

        // Below this point, if Nyms or Accounts were specified, they are now available.
        // (Pointers might be null, though currently My Nym is required to be there.)
        //
        // Execution continues, even if we fail to find his nym.
        // This is so the script has the opportunity to "check nym" (Download it)
        // based on the ID that the user has entered here.

        // ***********************************************************
        
        OTIdentifier thePurseAssetTypeID;
        OTAssetContract * pMyAssetContract = NULL;

        if ( str_MyPurse.size() > 0 )
        {
			const OTIdentifier MY_ASSET_TYPE_ID(str_MyPurse.c_str());
			pMyAssetContract = pWallet->GetAssetContract(MY_ASSET_TYPE_ID);
            
            // If failure, then we try PARTIAL match.
            if (NULL == pMyAssetContract)
                pMyAssetContract = pWallet->GetAssetContractPartialMatch( str_MyPurse );
            
            // ------------------------------------------
            if (NULL != pMyAssetContract)
            {
                OTString strTemp;
                pMyAssetContract->GetIdentifier(strTemp);
                
                str_MyPurse = strTemp.Get();
                OTLog::vOutput(0, "Using as mypurse: %s\n", str_MyPurse.c_str());
                // ------------------------------------------
                pMyAssetContract->GetIdentifier(thePurseAssetTypeID);
            }
            // Execution continues here, so the script has the option to download
            // any asset contract, if it can't find it in the wallet.
        }
        // if no purse (asset type) ID was provided, but MyAccount WAS provided, then
        // use the asset type for the account instead.
        else if (NULL != pMyAccount)
            thePurseAssetTypeID = pMyAccount->GetAssetTypeID();
        // ------------------
        if (!thePurseAssetTypeID.IsEmpty())

		{
			OTString strTempAssetType(thePurseAssetTypeID);
			str_MyPurse = strTempAssetType.Get();
		}		
		// BELOW THIS POINT, pMyAssetContract MIGHT be NULL, or MIGHT be an asset type specified by the user.
		// There's no guarantee that it's available, but if it IS, then it WILL be available below this point.
		// ---------------------------------------------------------------------------
		OTIdentifier hisPurseAssetTypeID;

        OTAssetContract * pHisAssetContract = NULL;
		
        if ( str_HisPurse.size() > 0 )
        {
			const OTIdentifier HIS_ASSET_TYPE_ID(str_HisPurse.c_str());
			pHisAssetContract = pWallet->GetAssetContract(HIS_ASSET_TYPE_ID);
            
            // If failure, then we try PARTIAL match.
            if (NULL == pHisAssetContract)
                pHisAssetContract = pWallet->GetAssetContractPartialMatch( str_HisPurse );
            
            // ------------------------------------------
            if (NULL != pHisAssetContract)
            {
                OTString strTemp;
                pHisAssetContract->GetIdentifier(strTemp);
                
                str_HisPurse = strTemp.Get();
                OTLog::vOutput(0, "Using as hispurse: %s\n", str_HisPurse.c_str());
                // ------------------------------------------
                pHisAssetContract->GetIdentifier(hisPurseAssetTypeID);
            }
        }
        // If no "HisPurse" was provided, but HisAcct WAS, then we use the
        // asset type of HisAcct as HisPurse.
        else if (NULL != pHisAccount)
            hisPurseAssetTypeID = pHisAccount->GetAssetTypeID();
        // ------------------
        if (!hisPurseAssetTypeID.IsEmpty())

		{
			OTString strTempAssetType(hisPurseAssetTypeID);
			str_HisPurse = strTempAssetType.Get();
		}				
        // --------------------------------------------------------------------------
        
        OTLog::Output(0, "\n");
        
        // Also, pAccount and pMyAssetContract have not be validated AGAINST EACH OTHER (yet)...
        // Also, pHisAccount and pHisAssetContract have not be validated AGAINST EACH OTHER (yet)...
         
        // -----------------------------------------------------
        /*  GET THE ACTUAL ARGUMENTS AFTER THE OPTIONS */
//
//      for( int i = 0 ; i < opt->getArgc() ; i++ )
//      {
//         cerr << "arg = " <<  opt->getArgv( i ) << endl ;
//      }        
    
        bool bSendCommand	= false; // Determines whether to actually send a message to the server.

		OTMessage theMessage;

		// If we can match the user's request to a client command,
		// AND theClient object is able to process that request into
		// theMessage, then we send it down the pipe.


        // In lieu of maintaining a constant connection to the server, in ZMQ mode, the
        // client updates its internal "connection" object to make sure the right pointers
        // are in place (since in ZMQ mode, each message could be from a different nym 
        // and to a different server.)
        //
		if ((NULL != pServerContract) && (NULL != pMyNym))
			OTAPI_Wrap::OTAPI()->GetClient()->SetFocusToServerAndNym(*pServerContract, *pMyNym, OTAPI_Wrap::It()->OTAPI()->GetTransportCallback());
		// NOTE -- This MAY be unnecessary for ProcessUserCommand (since these args are passed
		// in there already) but it's definitely necessary soon after for ProcessServerReply()
		// (which comes next.)


		//        (OTClient::OT_CLIENT_CMD_TYPE requestedCommand,
		//         OTMessage & theMessage,
		//         OTPseudonym & theNym,
		//         OTServerContract & theServer,
		//         OTAccount * pAccount/*=NULL*/,
		//         lAmount
		//         OTAssetContract * pMyAssetType/*=NULL*/,
		//         OTAccount * pHisAcct/*=NULL*/,
		//         OTPseudonym * pHisNym/*=NULL*/)


		// COMMANDS


		if( ( opt->getValue( "script" ) != NULL ) ||
			( opt->getArgc() > 0) )
		{
			int nReturnValue = 0; // This is what gets returned back to the caller. The Script has a chance to change this.

			// ----------------------------------------

			OTAPI_Wrap::OTAPI()->GetClient()->SetRunningAsScript(); // This way it won't go firing off messages automatically based on receiving certain server replies to previous requests.
			// Todo: Research whether the above call is still necessary. (OTAPI no longer fires off ANY auto messages based on server replies. API CLIENT MUST do those things itself now.)

			std::string strFilename;

			// If a filename is provided as a normal argument (like this: ot <filename>)
			// then it will work...
			//
			if (opt->getArgc() > 0)
			{
				strFilename = opt->getArgv( 0 );
			}

			// the --script option will ALSO work for the filename, and will override the above.
			// so:   ot --script <filename>
			// also: ot --script <actual_filename> <ignored_filename>
			//
			// In this above example, ignored_filename WOULD have been used, but then it got
			// overridden by the --script actual_filename.

			if (NULL != opt->getValue( "script" ))
			{
				strFilename = opt->getValue( "script" );
			}

			std::ifstream t(strFilename.c_str(), ios::in | ios::binary);
			std::stringstream buffer;
			buffer << t.rdbuf();
			std::string results = buffer.str();
			// ----------------------------------------
            OT_ME madeEasy;

			OTCleanup<OTVariable>	angelArgs; // For user-defined arguments that may have been passed in.

//			OTParty		* pPartyMyNym	= NULL;
//			OTParty		* pPartyHisNym	= NULL;
//
//			OTCleanup<OTParty> angelMyNym;
//			OTCleanup<OTParty> angelHisNym;
			OTCleanup<OTVariable> angelMyNymVar;
			OTCleanup<OTVariable> angelHisNymVar;
			OTCleanup<OTVariable> angelServer;
			OTCleanup<OTVariable> angelMyAcct;
			OTCleanup<OTVariable> angelHisAcct;
			OTCleanup<OTVariable> angelMyPurse;
			OTCleanup<OTVariable> angelHisPurse;
			// -------------------------

            if ((str_Args.size() > 0) || (opt->getArgc() > 1))
            {
                const std::string str_var_name("Args");
                std::string str_var_value, str_command;

                if (str_Args.size() > 0)
                    str_var_value += str_Args;

                if (opt->getArgc() > 1)
                {
                    if (str_Args.size() > 0)
                        str_var_value += " ";

                    str_command = opt->getArgv( 1 );
                    str_var_value += "ot_cli_command ";
                    str_var_value += str_command;
                }

                OTLog::vOutput(1, "Adding user-defined command line arguments as '%s' containing value: %s\n",
                    str_var_name.c_str(), str_var_value.c_str());

                OTVariable * pVar = new OTVariable(str_var_name,		// "Args"
                    str_var_value,		// "key1 value1 key2 value2 key3 value3 key4 value4"
                    OTVariable::Var_Constant);	// constant, persistent, or important.
                angelArgs.SetCleanupTargetPointer(pVar);
                OT_ASSERT(NULL != pVar);
                // ------------------------------------------
                madeEasy.AddVariable(str_var_name, *pVar);
            }
            else 
            {
                OTLog::Output(2, "Args variable (optional user-defined arguments) isn't set...\n");
            }

            // -------------------------
            if (str_ServerID.size() > 0)
            {
                const std::string str_var_name("Server");
                const std::string str_var_value(str_ServerID);

                OTLog::vOutput(1, "Adding constant with name %s and value: %s ...\n", str_var_name.c_str(), str_var_value.c_str());

                OTVariable * pVar = new OTVariable(str_var_name,		// "Server"
                    str_var_value,		// "lkjsdf09834lk5j34lidf09" (Whatever)
                    OTVariable::Var_Constant);	// constant, persistent, or important.
                angelServer.SetCleanupTargetPointer(pVar);
                OT_ASSERT(NULL != pVar);
                // ------------------------------------------
                madeEasy.AddVariable(str_var_name, *pVar);
            }
            else
            {
                OTLog::Output(2, "Server variable isn't set...\n");
            }
            // -------------------------

            if (NULL != pMyNym)
            {
                const std::string str_party_name("MyNym");

                OTLog::vOutput(1, "Adding constant with name %s and value: %s ...\n", str_party_name.c_str(), str_MyNym.c_str());

                OTVariable * pVar = new OTVariable(str_party_name,	// "MyNym"
                    str_MyNym,		// "lkjsdf09834lk5j34lidf09" (Whatever)
                    OTVariable::Var_Constant);	// constant, persistent, or important.
                angelMyNymVar.SetCleanupTargetPointer(pVar);
                OT_ASSERT(NULL != pVar);
                // ------------------------------------------
                madeEasy.AddVariable(str_party_name, *pVar);
            }
            else
            {
                OTLog::Output(2, "MyNym variable isn't set...\n");
            }
            // -------------------------

            if ((NULL != pHisNym) || (str_HisNym.size() > 0)) // Even if we didn't find him, we still let the ID through, if there is one.
            {
                const std::string str_party_name("HisNym");

                OTLog::vOutput(1, "Adding constant with name %s and value: %s ...\n", str_party_name.c_str(), str_HisNym.c_str());

                OTVariable * pVar = new OTVariable(str_party_name,	// "HisNym"
                    str_HisNym,		// "lkjsdf09834lk5j34lidf09" (Whatever)
                    OTVariable::Var_Constant);	// constant, persistent, or important.
                angelHisNymVar.SetCleanupTargetPointer(pVar);
                OT_ASSERT(NULL != pVar);
                // ------------------------------------------
                madeEasy.AddVariable(str_party_name, *pVar);
            }
            else
            {
                OTLog::Output(2, "HisNym variable isn't set...\n");
            }				
            // -------------------------
            // WE NO LONGER PASS THE PARTY DIRECTLY TO THE SCRIPT,
            // BUT INSTEAD, ONLY THE PARTY'S NAME.
            //
            // (Because often, "HisNym" isn't in my wallet and wouldn't be found anyway,
            //  even though it ends up to contain a perfectly legitimate Nym ID.)
            /*
            if (NULL != pMyNym)
            {
                const std::string str_party_name("MyNym"), str_agent_name("mynym"), str_acct_name("myacct");

                pPartyMyNym = new OTParty (str_party_name, *pMyNym, str_agent_name, pMyAccount, &str_acct_name);
                angelMyNym.SetCleanupTargetPointer(pPartyMyNym);
                OT_ASSERT(NULL != pPartyMyNym);
                // ------------------------------------------
                pScript-> AddParty("MyNym", *pPartyMyNym);
            }
            else 
            {
                OTLog::Error("MyNym variable isn't set...\n");
            }
            // -------------------------
            if (NULL != pHisNym)
            {
                const std::string str_party_name("HisNym"), str_agent_name("hisnym"), str_acct_name("hisacct");

                pPartyHisNym = new OTParty (str_party_name, *pHisNym, str_agent_name, pHisAccount, &str_acct_name);
                angelHisNym.SetCleanupTargetPointer(pPartyHisNym);
                OT_ASSERT(NULL != pPartyHisNym);
                // ------------------------------------------
                pScript-> AddParty("HisNym", *pPartyHisNym);
            }
            else 
            {
                OTLog::Error("HisNym variable isn't set...\n");
            }
            */
            // -------------------------

            if (str_MyAcct.size() > 0)
            {
                const std::string str_var_name("MyAcct");
                const std::string str_var_value(str_MyAcct);

                OTLog::vOutput(1, "Adding variable with name %s and value: %s ...\n", str_var_name.c_str(), str_var_value.c_str());

                OTVariable * pVar = new OTVariable(str_var_name,		// "MyAcct"
                    str_var_value,		// "lkjsdf09834lk5j34lidf09" (Whatever)
                    OTVariable::Var_Constant);	// constant, persistent, or important.
                angelMyAcct.SetCleanupTargetPointer(pVar);
                OT_ASSERT(NULL != pVar);
                // ------------------------------------------
                madeEasy.AddVariable(str_var_name, *pVar);
            }
            else
            {
                OTLog::Output(2, "MyAcct variable isn't set...\n");
            }
            // -------------------------

            if (str_MyPurse.size() > 0)
            {
                const std::string str_var_name("MyPurse");
                const std::string str_var_value(str_MyPurse);

                OTLog::vOutput(1, "Adding variable with name %s and value: %s ...\n", str_var_name.c_str(), str_var_value.c_str());

                OTVariable * pVar = new OTVariable(str_var_name,		// "MyPurse"
                    str_var_value,		// "lkjsdf09834lk5j34lidf09" (Whatever)
                    OTVariable::Var_Constant);	// constant, persistent, or important.
                angelMyPurse.SetCleanupTargetPointer(pVar);
                OT_ASSERT(NULL != pVar);
                // ------------------------------------------
                madeEasy.AddVariable(str_var_name, *pVar);
            }
            else
            {
                OTLog::Output(2, "MyPurse variable isn't set...\n");
            }
            // -------------------------

            if (str_HisAcct.size() > 0)
            {
                const std::string str_var_name("HisAcct");
                const std::string str_var_value(str_HisAcct);

                OTLog::vOutput(1, "Adding variable with name %s and value: %s ...\n", str_var_name.c_str(), str_var_value.c_str());

                OTVariable * pVar = new OTVariable(str_var_name,		// "HisAcct"
                    str_var_value,		// "lkjsdf09834lk5j34lidf09" (Whatever)
                    OTVariable::Var_Constant);	// constant, persistent, or important.
                angelHisAcct.SetCleanupTargetPointer(pVar);
                OT_ASSERT(NULL != pVar);
                // ------------------------------------------
                madeEasy.AddVariable(str_var_name, *pVar);
            }
            else 
            {
                OTLog::Output(2, "HisAcct variable isn't set...\n");
            }
            // -------------------------

            if (str_HisPurse.size() > 0)
            {
                const std::string str_var_name("HisPurse");
                const std::string str_var_value(str_HisPurse);

                OTLog::vOutput(1, "Adding variable with name %s and value: %s ...\n", str_var_name.c_str(), str_var_value.c_str());

                OTVariable * pVar = new OTVariable(str_var_name,		// "HisPurse"
                    str_var_value,		// "lkjsdf09834lk5j34lidf09" (Whatever)
                    OTVariable::Var_Constant);	// constant, persistent, or important.
                angelHisPurse.SetCleanupTargetPointer(pVar);
                OT_ASSERT(NULL != pVar);
                // ------------------------------------------
                madeEasy.AddVariable(str_var_name, *pVar);
            }
            else
            {
                OTLog::Output(2, "MyPurse variable isn't set...\n");
            }
            // ************************************************

            OTLog::Output(1, "Script output:\n\n");


			// OT SCRIPT PROMPT --------------------------------------------
            nReturnValue = madeEasy.ExecuteScript_ReturnInt(results, strFilename);
			// OT SCRIPT PROMPT --------------------------------------------


			return nReturnValue;
			
		}
        // ------------------------------------------------------------------------
		// OT SCRIPT ABOVE.
        // ------------------------------------------------------------------------
        
        
		// *******************************************************************

		if ((NULL == pServerContract) || (NULL == pMyNym))
		{
			OTLog::vError("Unexpected NULL: %s %s\n", 
				(NULL == pServerContract) ? "pServerContract" : "", 
				(NULL == pMyNym)          ? "pMyNym"          : "");
		}
		else if ( opt->getValue( 'w' ) != NULL  || opt->getValue( "withdraw" ) != NULL  )
		{
			const long lAmount = atol(opt->getValue( 'w' ));

			OTLog::Output(0, "(User has instructed to withdraw cash...)\n");

			// ------------------------------------------------------------------------------			
			// if successful setting up the command payload...

			if (0 < OTAPI_Wrap::OTAPI()->GetClient()->ProcessUserCommand(OTClient::notarizeWithdrawal, theMessage, 
				*pMyNym, *pServerContract,
				pMyAccount, lAmount))
			{
				bSendCommand = true;
			}
			else
				OTLog::Error("Error processing withdraw command in ProcessMessage.\n");
			// ------------------------------------------------------------------------
		}
		else if ( opt->getValue( 't' ) != NULL  || opt->getValue( "transfer" ) != NULL  )
		{
			const long lAmount = atol(opt->getValue( 't' ));

			OTIdentifier HIS_ACCT_ID((str_HisAcct.size() > 0) ? str_HisAcct.c_str():"aaaaaaaa");

			OTLog::Output(0, "User has instructed to send a Transfer command (Notarize Transactions)...\n");

			// ------------------------------------------------------------------------------			
			// if successful setting up the command payload...

			if (0 < OTAPI_Wrap::OTAPI()->GetClient()->ProcessUserCommand(OTClient::notarizeTransfer, theMessage, 
				*pMyNym,  *pServerContract,
				pMyAccount, lAmount, NULL, // asset contract
				NULL, // his Nym
				(str_HisAcct.size() > 0) ? &HIS_ACCT_ID : NULL)) // his acct
			{
				bSendCommand = true;
			}
			else
				OTLog::Error("Error processing notarizeTransactions (transfer) command in ProcessMessage.\n");
		}
		else if( opt->getValue( 'c' ) != NULL  || opt->getValue( "cheque" ) != NULL  )
		{
			OTLog::Output(0, "(User has instructed to write a cheque...)\n");

			const long lAmount = atol(opt->getValue( 'c' ));

			OTIdentifier HIS_NYM_ID ((str_HisNym.size() > 0)  ? str_HisNym.c_str():"aaaaaaaa"); // todo hardcoding

			OTAPI_Wrap::OTAPI()->GetClient()->ProcessUserCommand(OTClient::writeCheque, theMessage,
				*pMyNym, *pServerContract,
				pMyAccount, lAmount, NULL, // asset contract
				(str_HisNym.size() > 0)  ? &HIS_NYM_ID : NULL);
		}
		else if( opt->getValue( 'v' ) != NULL  || opt->getValue( "voucher" ) != NULL  )
		{
			OTLog::Output(0, "(User has instructed to withdraw a voucher...)\n");

			const long lAmount = atol(opt->getValue( 'v' ));

			OTIdentifier HIS_NYM_ID ((str_HisNym.size() > 0)  ? str_HisNym.c_str():"aaaaaaaa");

			if (0 < OTAPI_Wrap::OTAPI()->GetClient()->ProcessUserCommand(OTClient::withdrawVoucher, theMessage,
				*pMyNym, *pServerContract,
				pMyAccount, lAmount, NULL, // asset contract
				(str_HisNym.size() > 0)  ? &HIS_NYM_ID : NULL))
			{
				bSendCommand = true;
			}
			else
				OTLog::Error("Error processing withdraw voucher command in ProcessMessage.\n");

		}

		// make an offer and put it onto a market. 
		else if (opt->getValue( "marketoffer" ) != NULL)
		{
			OTLog::Output(0, "(User has instructed to send a marketOffer command to the server...)\n");

			// ------------------------------------------------------------------------------			
			// if successful setting up the command payload...

			if (0 < OTAPI_Wrap::OTAPI()->GetClient()->ProcessUserCommand(OTClient::marketOffer, theMessage, 
				*pMyNym, *pServerContract,
				NULL)) // for now, keeping it simple. Can add options later.
			{
				bSendCommand = true;
			}
			else
				OTLog::Error("Error processing marketOffer command in ProcessMessage.\n");
			// ------------------------------------------------------------------------
		}

		// ********************************************************
		/*
		bool ProcessUserCommand(OT_CLIENT_CMD_TYPE requestedCommand,
            OTMessage & theMessage,
            OTPseudonym & theNym,
//          OTAssetContract & theContract,
            OTServerContract & theServer,
            OTAccount * pAccount=NULL,
            long lTransactionAmount = 0,
            OTAssetContract * pMyAssetType=NULL,
            OTIdentifier * pHisAcctID=NULL,
            OTIdentifier * pHisNymID=NULL);
		*/
		else if(opt->getFlag( "proposepaymentplan" ) )
		{            
			OTLog::Output(0, "(User has instructed to propose a payment plan...)\n");

			OTIdentifier HIS_NYM_ID ((str_HisNym.size()  > 0) ? str_HisNym.c_str() :"aaaaaaaa");
			OTIdentifier HIS_ACCT_ID((str_HisAcct.size() > 0) ? str_HisAcct.c_str():"aaaaaaaa");

			OTAPI_Wrap::OTAPI()->GetClient()->ProcessUserCommand(OTClient::proposePaymentPlan, theMessage,
				*pMyNym, *pServerContract,
				pMyAccount, 0, pMyAssetContract,
				(str_HisNym.size() > 0)  ? &HIS_NYM_ID : NULL,
				(str_HisAcct.size() > 0) ? &HIS_ACCT_ID : NULL
				);
		}
		// ------------------------------------------------------------------------
		else if(opt->getFlag( "confirmpaymentplan" ) )
		{            
			OTLog::Output(0, "(User has instructed to confirm a payment plan...)\n");

			OTAPI_Wrap::OTAPI()->GetClient()->ProcessUserCommand(OTClient::confirmPaymentPlan, theMessage,
				*pMyNym, *pServerContract,
				NULL); // the account info is already on the plan, right?
		}
		// ------------------------------------------------------------------------
		else if(opt->getFlag( "activatepaymentplan" ) )
		{            
			OTLog::Output(0, "(User has instructed to activate a payment plan...)\n");

			if (0 < OTAPI_Wrap::OTAPI()->GetClient()->ProcessUserCommand(OTClient::paymentPlan, theMessage,
				*pMyNym, *pServerContract,
				pMyAccount)) // if user DOES specify an account (unnecessary)
			{                                   // then OT will verify that they match, and error otherwise.
				bSendCommand = true;
			}
			else
				OTLog::Error("Error processing activate payment plan command in ProcessMessage.\n");
		}
		// *******************************************************

		else if(opt->getFlag( "depositcheque" ) )
		{            
			OTLog::Output(0, "(User has instructed to deposit a cheque...)\n");

			// ------------------------------------------------------------------------------			
			// if successful setting up the command payload...

			if (0 < OTAPI_Wrap::OTAPI()->GetClient()->ProcessUserCommand(OTClient::notarizeCheque, theMessage, 
				*pMyNym, *pServerContract,
				pMyAccount))
			{
				bSendCommand = true;
			}
			else
				OTLog::Error("Error processing deposit cheque command in ProcessMessage.\n");
			// ------------------------------------------------------------------------
		}
		else if (opt->getFlag( "depositpurse" ) )
		{            
			OTLog::Output(0, "(User has instructed to deposit a cash purse...)\n");

			// ------------------------------------------------------------------------------			
			// if successful setting up the command payload...

			if (0 < OTAPI_Wrap::OTAPI()->GetClient()->ProcessUserCommand(OTClient::notarizePurse, theMessage, 
				*pMyNym, *pServerContract,
				pMyAccount,
				0, // amount (unused here)
				pMyAssetContract))
			{
				bSendCommand = true;
			}
			else
				OTLog::Error("Error processing deposit purse command in ProcessMessage.\n");
			// ------------------------------------------------------------------------
		}
		else if(opt->getFlag( "deposittokens" ) )
		{            
			OTLog::Output(0, "(User has instructed to deposit individual cash tokens...)\n");

			// ------------------------------------------------------------------------------			
			// if successful setting up the command payload...

			if (0 < OTAPI_Wrap::OTAPI()->GetClient()->ProcessUserCommand(OTClient::notarizeDeposit, theMessage, 
				*pMyNym, *pServerContract,
				pMyAccount))
			{
				bSendCommand = true;
			}
			else
				OTLog::Error("Error processing deposit cash tokens command in ProcessMessage.\n");
			// ------------------------------------------------------------------------
		}
		else if( opt->getFlag( 'i' )  || opt->getFlag( "inbox" )  )
		{
			cerr << "DISPLAY INBOX CONTENTS HERE... (When I code this. What can I say? Use the GUI.)" << endl ;
		}
		else if( opt->getFlag( 's' ) || opt->getFlag( "sign" ))
		{
			OTLog::Output(0, "(User has instructed to sign a contract...)\n");

			OTAPI_Wrap::OTAPI()->GetClient()->ProcessUserCommand(OTClient::signContract, theMessage,
				*pMyNym, *pServerContract,
				NULL);
		}
		else if( opt->getFlag( 'p' ) || opt->getFlag( "purse" )  )
		{
			cerr << "User wants to display purse contents (not coded yet here.)" << endl ;
		}
		else if( opt->getFlag( "verify" )  )
		{
			cerr << "User wants to verify a signature on a contract (not coded yet here) " << endl ;
		}
		else if( opt->getFlag( "stat" )   )
		{
			OTLog::Output(0, "User has instructed to display wallet contents...\n");

			OTString strStat;
			pWallet->DisplayStatistics(strStat);
			OTLog::vOutput(0, "%s\n", strStat.Get());
		}
		else if( opt->getFlag( "prompt" )   )
		{
			OTLog::Output(0, "User has instructed to enter the OT prompt...\n");
		}
		else if(opt->getFlag( 'b' ) || opt->getFlag( "balance" )   )
		{            
			OTLog::vOutput(0, "\n ACCT BALANCE (server-side): %ld\n\n", pMyAccount->GetBalance());

			OTPurse * pPurse = OTAPI_Wrap::OTAPI()->LoadPurse(theServerID, thePurseAssetTypeID, MY_NYM_ID);
			OTCleanup<OTPurse> thePurseAngel(pPurse);
			if (NULL != pPurse)
				OTLog::vOutput(0, " CASH PURSE (client-side): %ld\n", pPurse->GetTotalValue());
		}
		else if( opt->getFlag( 'r' ) || opt->getFlag( "refresh" )   )
		{
			OTLog::Output(0, "(User has instructed to download intermediary files for an asset account...)\n");

			// ------------------------------------------------------------------------------			
			// if successful setting up the command payload...

			if (0 < OTAPI_Wrap::OTAPI()->GetClient()->ProcessUserCommand(OTClient::getAccount, theMessage, 
				*pMyNym,  *pServerContract,
				pMyAccount))
			{
				bSendCommand = true;
			}
			else
				OTLog::Error("Error processing getAccount command in ProcessMessage.\n");
			// ------------------------------------------------------------------------
		}
		else if( opt->getFlag( "refreshnym" )   )
		{
			OTLog::Output(0, "(User has instructed to download intermediary files for a Nym...)\n");

			// ------------------------------------------------------------------------------			
			// if successful setting up the command payload...

			if (0 < OTAPI_Wrap::OTAPI()->GetClient()->ProcessUserCommand(OTClient::getNymbox, theMessage, 
				*pMyNym,  *pServerContract,
				NULL))
			{
				bSendCommand = true;
			}
			else
				OTLog::Error("Error processing getNymbox command in ProcessMessage.\n");
		}

		// ----------------------------------------------------------------------
		//
		const OTPseudonym * pServerNym = pServerContract->GetContractPublicNym();

		if ((NULL == pServerNym) || (false == pServerNym->VerifyPseudonym()))
		{
			OTLog::vOutput(0, "The server Nym was NULL or failed to verify on server contract: %s\n", 
				strServerID.Get());
			return 0;
		}
		//
		// ***********************************************************

		if (bSendCommand && pServerNym->VerifyPseudonym())
		{
			OTString strEnvelopeContents(theMessage);
			OTEnvelope theEnvelope;	// Seal the string up into an encrypted Envelope
			theEnvelope.Seal(*pServerNym, strEnvelopeContents);
			// -----------------------------------

			OTAPI_Wrap::It()->OTAPI()->GetTransportCallback()->operator()(*pServerContract, theEnvelope);

		} // if bSendCommand		


		if ( !opt->getFlag( "prompt" ) ) // If the user selected to enter the OT prompt, then we drop down below... (otherwise return.)
		{
			return 0;
		}
	} // Command line interface (versus below, which is the PROMPT interface.)

	// ****************************************************************************












	OTLog::Output(0, "\nLOOKING FOR INSTRUCTIONS for the OT COMMAND LINE?\n"
		"Try:   quit\n"
		"Followed by:  ot -?\n"
		"or:    ot -h\n"
		"or:    ot --help\n"
		"\n"
		"(NOW ENTERING OT PROMPT) \n"
		"See docs/CLIENT-COMMANDS.txt\n\n");


	// -----------------------------------------------------------------------
	//
	//  THE OPEN-TRANSACTIONS PROMPT
	//
	// OT> 
	//
	// Basically, loop:
	//
	//	1) Present a prompt, and get a user string of input. Wait for that.
	//
	//	2) Process it out as an OTMessage to the server. It goes down the pipe.
	//
	//	3) Sleep for 1 second.
	//
	//	4) Awake and check for messages to be read in response from the server.
	//	   Loop. As long as there are any responses there, then process and handle
	//	   them all.
	//	   Then continue back up to the prompt at step (1).



	OTPseudonym * pMyNym = NULL;
	OTWallet * pWallet = NULL;
	OTServerContract * pServerContract = NULL;

	// If we got down here, that means there were no commands on the command line 
	// (That's why we dropped into the OT prompt.)
	// However, there still may have been OPTIONS -- and if so, we'll go ahead and
	// load the wallet. (If there were NOT ANY OPTIONS, then we do NOT load the wallet,
	// although there is a COMMAND for doing that.)
	//
	if ( (str_ServerID.size() > 0) || (str_MyNym.size() > 0) )
	{
		if (false == SetupPointersForWalletMyNymAndServerContract(str_ServerID, str_MyNym, 
			pMyNym, pWallet, pServerContract))
		{
			return 0;
		}
	}
	else
		OTLog::Output(0, "\nYou may wish to 'load' then 'stat'.\n"
		"(FYI, --server SERVER_ID  and  --mynym NYM_ID  were both valid options.)\n"
		"Also, see:  ~/.ot/command-line-ot.opt for defaults.\n");

	// Below this point, pWallet is available and loaded, IF opt->HasOptions().
	// Otherwise, pWallet is NOT loaded, and we're waiting for the Load command.

	// Below this point, pMyNym MIGHT be a valid pointer (if it was specified),
	// or MIGHT be NULL. Same with pServerContract. (MIGHT be there.)
	//
	// ***********************************************************

	char buf[200] = "";

	int nExpectResponse = 0;

	OTLog::vOutput(4, "Starting client loop.\n", OT_CMD_HEADER_SIZE);


	// Set the logging level for the network transport code.
#ifndef _WIN32
	//	XmlRpc::setVerbosity(1);
#endif


	// -----------------------------------------------------------------------

	for(;;)
	{
		buf[0] = 0; // Making it fresh again.

		nExpectResponse = 0;

		// 1) Present a prompt, and get a user string of input. Wait for that.
		OTLog::Output(0, "\nOT -- WARNING: This prompt is too low-level for you.\nType 'quit', and then try 'opentxs help' and 'opentxs list'.\n\nOT> ");

		if (NULL == fgets(buf, 190, stdin)) // Leaving myself 10 extra bytes at the end for safety's sake.
			break;

		OTLog::Output(0, ".\n..\n...\n....\n.....\n......\n.......\n........\n.........\n..........\n"
			"...........\n............\n.............\n");

		// so we can process the user input
		std::string strLine = buf;

		// Load wallet.xml
		if (strLine.compare(0,4,"load") == 0)
		{
			OTLog::Output(0, "User has instructed to load wallet.xml...\n");

			if (false == SetupPointersForWalletMyNymAndServerContract(str_ServerID, str_MyNym, 
				pMyNym, pWallet, pServerContract))
			{            
				return 0;
			}

			continue;
		}

		else if ('\0' == buf[0])
		{
			continue;
		}

		// --------------------------------------------------------------------

		else if (strLine.compare(0,4,"test") == 0)
		{			
			std::string strScript ="print(\"Hello, world\")";
            OT_ME madeEasy;
            madeEasy.ExecuteScript_ReturnVoid(strScript, "hardcoded");
            
			// --------------------------------------------------------------------
			/*
			// TODO: Make sure there's no issues with a known plaintext attack.
			// (Not here, but I am doing a similar thing in OTASCIIArmor to maintain a minimum size,
			// due to a bug in some other library that I can't recall at this time.)
			//
			const char * szBlah = "Transaction processor featuring Untraceable Digital Cash, "
			"Anonymous Numbered Accounts, Triple-Signed Receipts, Basket Currencies, and Signed "
			"XML Contracts. Also supports cheques, invoices, payment plans, markets with trades, "
			"and other instruments... it's like PGP for Money.... Uses OpenSSL and Lucre blinded tokens.\n";

			OTASCIIArmor theArmoredText(szBlah);
			OTLog::vOutput(0, "Armored text:\n%s\n", theArmoredText.Get());

			OTString theFixedText(theArmoredText);
			OTLog::vOutput(0, "Uncompressed, etc text:\n%s\n", theFixedText.Get());
			*/

			continue;
		}
		// --------------------------------

		else if (strLine.compare(0,8,"clearreq") == 0) // clear request numbers
		{
			if (NULL == pMyNym)
			{
				OTLog::Output(0, "No Nym yet available. Try 'load'.\n");
				continue;
			}

			OTString strServerID;
			pServerContract->GetIdentifier(strServerID);

			OTLog::vOutput(0, "You are trying to mess around with your (clear your) request numbers.\n"
				"Enter the relevant server ID [%s]: ", strServerID.Get());

			std::string str_ServerID = OT_CLI_ReadLine();

			const OTString strReqNumServerID((str_ServerID.size() > 0) ? str_ServerID.c_str() : strServerID.Get());

			// --------------------------------

			pMyNym->RemoveReqNumbers(&strReqNumServerID);

			pMyNym->SaveSignedNymfile(*pMyNym);

			OTLog::vOutput(0, "Successfully removed request number for server %s. Saving nym...\n",
				strReqNumServerID.Get());
			continue;
		}
		// --------------------------------
		else if (strLine.compare(0,5,"clear") == 0)
		{
			if (NULL == pMyNym)
			{
				OTLog::Output(0, "No Nym yet available. Try 'load'.\n");
				continue;
			}

			OTString strServerID;
			pServerContract->GetIdentifier(strServerID);

			OTLog::vOutput(0, "You are trying to mess around with your (clear your) transaction numbers.\n"
				"Enter the relevant server ID [%s]: ", strServerID.Get());

			std::string str_ServerID = OT_CLI_ReadLine();

			const OTString strTransNumServerID((str_ServerID.size() > 0) ? str_ServerID.c_str() : strServerID.Get());

			// --------------------------------

			pMyNym->RemoveAllNumbers(&strTransNumServerID, true); // bRemoveHighestNum = true.			
			pMyNym->SaveSignedNymfile(*pMyNym);

			OTLog::vOutput(0, "Successfully removed all issued and transaction numbers for server %s. Saving nym...\n",
				strTransNumServerID.Get());
			continue;
		}			
		// --------------------------------
		else if (strLine.compare(0,7,"decrypt") == 0)
		{
			if (NULL == pMyNym)
			{
				OTLog::Output(0, "No Nym yet available to decrypt with.\n");
				continue;
			}

			OTLog::Output(0, "Enter text to be decrypted:\n> ");

			OTASCIIArmor theArmoredText;
			char decode_buffer[200]; // Safe since we only read sizeof - 1

			do {
				decode_buffer[0] = 0;
				if (NULL != fgets(decode_buffer, sizeof(decode_buffer)-1, stdin))
				{
					theArmoredText.Concatenate("%s\n", decode_buffer);
					OTLog::Output(0, "> ");
				}
				else 
				{
					break;
				}
			} while (strlen(decode_buffer)>1);


			OTEnvelope	theEnvelope(theArmoredText);
			OTString	strDecodedText;

			theEnvelope.Open(*pMyNym, strDecodedText);

			OTLog::vOutput(0, "\n\nDECRYPTED TEXT:\n\n%s\n\n", strDecodedText.Get());

			continue;
		}
		// --------------------------------

		else if (strLine.compare(0,6,"decode") == 0)
		{
			OTLog::Output(0, "Enter text to be decoded:\n> ");

			OTASCIIArmor theArmoredText;
			char decode_buffer[200]; // Safe since we only read sizeof - 1.

			do {
				decode_buffer[0] = 0;
				if (NULL != fgets(decode_buffer, sizeof(decode_buffer)-1, stdin))
				{
					theArmoredText.Concatenate("%s\n", decode_buffer);
					OTLog::Output(0, "> ");
				}
				else 
				{
					break;
				}

			} while (strlen(decode_buffer)>1);

			OTString strDecodedText(theArmoredText);

			OTLog::vOutput(0, "\n\nDECODED TEXT:\n\n%s\n\n", strDecodedText.Get());

			continue;
		}

		else if (strLine.compare(0,6,"encode") == 0)
		{
			OTLog::Output(0, "Enter text to be ascii-encoded (terminate with ~ on a new line):\n> ");

			OTString strDecodedText;
			char decode_buffer[200]; // Safe since we only read sizeof - 1.

			do {
				decode_buffer[0] = 0;

				if ((NULL != fgets(decode_buffer, sizeof(decode_buffer)-1, stdin)) &&
					(decode_buffer[0] != '~'))
				{
					strDecodedText.Concatenate("%s", decode_buffer);
					OTLog::Output(0, "> ");
				}
				else 
				{
					break;
				}

			} while (decode_buffer[0] != '~');

			OTASCIIArmor theArmoredText(strDecodedText);

			OTLog::vOutput(0, "\n\nENCODED TEXT:\n\n%s\n\n", theArmoredText.Get());

			continue;
		}

		else if (strLine.compare(0,4,"hash") == 0)
		{
			OTLog::Output(0, "Enter text to be hashed (terminate with ~ on a new line):\n> ");

			OTString strDecodedText;
			char decode_buffer[200]; // Safe since we only read sizeof - 1.

			do {
				decode_buffer[0] = 0;

				if ((NULL != fgets(decode_buffer, sizeof(decode_buffer)-1, stdin)) &&
					(decode_buffer[0] != '~'))
				{
					strDecodedText.Concatenate("%s\n", decode_buffer);
					OTLog::Output(0, "> ");
				}
				else 
				{
					break;
				}

			} while (decode_buffer[0] != '~');


			std::string str_Trim(strDecodedText.Get());
			std::string str_Trim2 = OTString::trim(str_Trim);
			strDecodedText.Set(str_Trim2.c_str());

			OTIdentifier theIdentifier;
			theIdentifier.CalculateDigest(strDecodedText);

			OTString strHash(theIdentifier);

			OTLog::vOutput(0, "\n\nMESSAGE DIGEST:\n\n%s\n\n", strHash.Get());

			continue;
		}

		else if (strLine.compare(0,4,"stat") == 0)
		{
			OTLog::Output(0, "User has instructed to display wallet contents...\n");

			if (pWallet)
			{
				OTString strStat;
				pWallet->DisplayStatistics(strStat);
				OTLog::vOutput(0, "%s\n", strStat.Get());
			}
			else
				OTLog::Output(0, "No wallet is loaded...\n");

			continue;
		}

		else if (strLine.compare(0,4,"help") == 0)
		{
			OTLog::Output(0, "User has instructed to display the help file...\nPlease see this file: docs/CLIENT_COMMANDS.txt\n");

			continue;
		}

		else if (strLine.compare(0,4,"quit") == 0)
		{
			OTLog::Output(0, "User has instructed to exit the wallet...\n");

			break;
		}


		// ------------------------------------------------------------------------------			

		/*
		--myacct   (ACCT ID)
		--mynym    (NYM ID)
		--mypurse  (ASSET TYPE ID)

		--toacct   (ACCT ID)
		--tonym    (NYM ID)
		--topurse  (ASSET TYPE ID)

		OTPseudonym *		GetNymByIDPartialMatch(const std::string PARTIAL_ID);
		OTServerContract *	GetServerContractPartialMatch(const std::string PARTIAL_ID);
		OTAssetContract *	GetAssetContractPartialMatch(const std::string PARTIAL_ID);
		OTAccount *         GetAccountPartialMatch(const std::string PARTIAL_ID);
		*/  


		if (NULL == pServerContract)
		{
			OTLog::Output(0, "Unable to find a server contract. Please restart using the option:  --server SERVER_ID\n"
				"(Where SERVER_ID is the server ID. Partial matches ARE accepted.)\n");
			continue;
		}


		// You can't just connect to any hostname and port.
		// Instead, you give me the Server Contract, and *I'll* look up all that stuff FOR you...
		// (We verify this up here, but use it at the bottom of the function once the message is set up.)
		//
//		int			nServerPort = 0;
//		OTString	strServerHostname;
//		
//		if (false == pServerContract->GetConnectInfo(strServerHostname, nServerPort))
//		{
//			OTLog::Error("Failed retrieving connection info from server contract.\n");
//			continue;
//		}

		// ------------------------------------------------------------------------------			

		// I put this here too since I think it's required in all cases below.
		//
		if (NULL == pMyNym) // Todo maybe move this check to the commands below (ONLY the ones that use a nym.)
		{
			OTLog::Output(0, "Unable to find My Nym. Please restart and use the option:\n"
				"   --mynym USER_ID\n"
				"(Where USER_ID is the Nym's ID. Partial matches ARE accepted.)\n");
			continue;
		}

		// ------------------------------------------------------------------------------			

		bool bSendCommand	= false; // Determines whether to actually send a message to the server.

		OTMessage theMessage;

		// If we can match the user's request to a client command,
		// AND theClient object is able to process that request into
		// theMessage, then we send it down the pipe.

		// *******************************************************************************


		// In lieu of maintaining a constant connection to the server, in RPC mode, the
		// client updates its internal "connection" object to make sure the right pointers
		// are in place (since in RPC mode, each message could be from a different nym 
		// and to a different server.)
		//
		OTAPI_Wrap::OTAPI()->GetClient()->SetFocusToServerAndNym(*pServerContract, *pMyNym, OTAPI_Wrap::It()->OTAPI()->GetTransportCallback());
		// NOTE -- This MAY be unnecessary for ProcessUserCommand (since these args are passed
		// in there already) but it's definitely necessary soon after for ProcessServerReply()
		// (which comes next.)

		// -------------------------------------------------------------------------

		// 'check server ID' command
		if (buf[0] == 'c')
		{
			OTLog::vOutput(0, "(User has instructed to send a checkServerID command to the server...)\n");

			// ------------------------------------------------------------------------------			
			// if successful setting up the command payload...

			if (0 < OTAPI_Wrap::OTAPI()->GetClient()->ProcessUserCommand(OTClient::checkServerID, theMessage, 
				*pMyNym, *pServerContract,
				NULL)) // NULL pAccount on this command (so far).
			{				
				bSendCommand = true;
			}
			else
				OTLog::vError("Error processing checkServerID command in ProcessMessage: %c\n", buf[0]);
			// ------------------------------------------------------------------------
		}

		// register new user account 
		else if (buf[0] == 'r')
		{
			OTLog::Output(0, "(User has instructed to send a createUserAccount command to the server...)\n");

			// ------------------------------------------------------------------------------			
			// if successful setting up the command payload...

			if (0 < OTAPI_Wrap::OTAPI()->GetClient()->ProcessUserCommand(OTClient::createUserAccount, theMessage, 
				*pMyNym, *pServerContract,
				NULL)) // NULL pAccount on this command.
			{
				bSendCommand = true;
			}
			else
				OTLog::vError("Error processing createUserAccount command in ProcessMessage: %c\n", buf[0]);
			// ------------------------------------------------------------------------
		}

		// ALL MESSAGES BELOW THIS POINT SHOULD ATTACH A REQUEST NUMBER IF THEY EXPECT THE SERVER TO PROCESS THEM.
		// (Handled inside ProcessUserCommand)

		// checkUser
		else if (buf[0] == 'u')
		{
			OTLog::Output(0, "(User has instructed to send a checkUser command to the server...)\n");

			// ------------------------------------------------------------------------------			
			// if successful setting up the command payload...

			if (0 < OTAPI_Wrap::OTAPI()->GetClient()->ProcessUserCommand(OTClient::checkUser, theMessage, 
				*pMyNym, *pServerContract,
				NULL)) // NULL pAccount on this command.
			{
				bSendCommand = true;
			}
			else
				OTLog::vError("Error processing checkUser command in ProcessMessage: %c\n", buf[0]);
			// ------------------------------------------------------------------------
		}

		// register new asset account 
		else if (buf[0] == 'a')
		{
			OTLog::Output(0, "(User has instructed to send a createAccount command to the server...)\n");

			// ------------------------------------------------------------------------------			
			// if successful setting up the command payload...

			if (0 < OTAPI_Wrap::OTAPI()->GetClient()->ProcessUserCommand(OTClient::createAccount, theMessage, 
				*pMyNym, *pServerContract,
				NULL)) // NULL pAccount on this command.
			{
				bSendCommand = true;
			}
			else
				OTLog::vError("Error processing createAccount command in ProcessMessage: %c\n", buf[0]);
			// ------------------------------------------------------------------------
		}

		// issue a new asset type 
		else if (!strcmp(buf, "issue\n"))
		{
			OTLog::Output(0, "(User has instructed to send an issueAssetType command to the server...)\n");

			// ------------------------------------------------------------------------------			
			// if successful setting up the command payload...

			if (0 < OTAPI_Wrap::OTAPI()->GetClient()->ProcessUserCommand(OTClient::issueAssetType, theMessage, 
				*pMyNym, *pServerContract,
				NULL)) // NULL pAccount on this command.
			{
				bSendCommand = true;
			}
			else
				OTLog::vError("Error processing issueAssetType command in ProcessMessage: %s\n", buf);
			// ------------------------------------------------------------------------
		}

		// issue a new basket asset type 
		else if (!strcmp(buf, "basket\n"))
		{
			OTLog::Output(0, "(User has instructed to send an issueBasket command to the server...)\n");

			// ------------------------------------------------------------------------------			
			// if successful setting up the command payload...

			if (0 < OTAPI_Wrap::OTAPI()->GetClient()->ProcessUserCommand(OTClient::issueBasket, theMessage, 
				*pMyNym, *pServerContract,
				NULL)) // NULL pAccount on this command.
			{
				bSendCommand = true;
			}
			else
				OTLog::vError("Error processing issueBasket command in ProcessMessage: %s\n", buf);
			// ------------------------------------------------------------------------
		}

		// exchange in/out of a basket currency 
		else if (!strcmp(buf, "exchange\n"))
		{
			OTLog::Output(0, "(User has instructed to send an exchangeBasket command to the server...)\n");

			// ------------------------------------------------------------------------------			
			// if successful setting up the command payload...

			if (0 < OTAPI_Wrap::OTAPI()->GetClient()->ProcessUserCommand(OTClient::exchangeBasket, theMessage, 
				*pMyNym, *pServerContract,
				NULL)) // NULL pAccount on this command.
			{
				bSendCommand = true;
			}
			else
				OTLog::vError("Error processing exchangeBasket command in ProcessMessage: %s\n", buf);
			// ------------------------------------------------------------------------
		}

		// make an offer and put it onto a market. 
		else if (!strcmp(buf, "offer\n"))
		{
			OTLog::Output(0, "(User has instructed to send a marketOffer command to the server...)\n");

			// ------------------------------------------------------------------------------			
			// if successful setting up the command payload...

			if (0 < OTAPI_Wrap::OTAPI()->GetClient()->ProcessUserCommand(OTClient::marketOffer, theMessage, 
				*pMyNym, *pServerContract,
				NULL)) // NULL pAccount on this command.
			{
				bSendCommand = true;
			}
			else
				OTLog::vError("Error processing marketOffer command in ProcessMessage: %s\n", buf);
			// ------------------------------------------------------------------------
		}

		// Set a Server Contract's client-side name (merely a label.) 
		else if (!strcmp(buf, "setservername\n"))
		{
			OTLog::Output(0, "(User wants to set a Server Contract's client-side name...)\n");

			// ------------------------------------------------------------------------------			
			// if successful setting up the command payload...

			if (0 < OTAPI_Wrap::OTAPI()->GetClient()->ProcessUserCommand(OTClient::setServerName, theMessage, 
				*pMyNym, *pServerContract,
				NULL)) // NULL pAccount on this command.
			{
				//					bSendCommand = true; // No message needed. Local data only.
			}
			// ------------------------------------------------------------------------
		}

		// Set an Asset Contract's client-side name (merely a label.) 
		else if (!strcmp(buf, "setassetname\n"))
		{
			OTLog::Output(0, "(User wants to set an Asset Contract's client-side name...)\n");

			// ------------------------------------------------------------------------------			
			// if successful setting up the command payload...

			if (0 < OTAPI_Wrap::OTAPI()->GetClient()->ProcessUserCommand(OTClient::setAssetName, theMessage, 
				*pMyNym, *pServerContract,
				NULL)) // NULL pAccount on this command.
			{
				//					bSendCommand = true; // No message needed. Local data only.
			}
			// ------------------------------------------------------------------------
		}

		// Set a Nym's client-side name (merely a label.) 
		else if (!strcmp(buf, "setnymname\n"))
		{
			OTLog::Output(0, "(User wants to set a Nym's client-side name...)\n");

			// ------------------------------------------------------------------------------			
			// if successful setting up the command payload...

			if (0 < OTAPI_Wrap::OTAPI()->GetClient()->ProcessUserCommand(OTClient::setNymName, theMessage, 
				*pMyNym, *pServerContract,
				NULL)) // NULL pAccount on this command.
			{
				//					bSendCommand = true; // No message needed. Local data only.
			}
			// ------------------------------------------------------------------------
		}

		// Set an Asset Account's client-side name (merely a label.) 
		else if (!strcmp(buf, "setaccountname\n"))
		{
			OTLog::Output(0, "(User wants to set an Asset Account's client-side name...)\n");

			// ------------------------------------------------------------------------------			
			// if successful setting up the command payload...

			if (0 < OTAPI_Wrap::OTAPI()->GetClient()->ProcessUserCommand(OTClient::setAccountName, theMessage, 
				*pMyNym, *pServerContract,
				NULL)) // NULL pAccount on this command.
			{
				//					bSendCommand = true; // No message needed. Local data only.
			}

			// ------------------------------------------------------------------------
		}

		// sign contract 
		// This doesn't message the server, but it DOES require the user's Nym to be loaded.
		else if (!strcmp(buf, "signcontract\n"))
		{
			OTLog::Output(0, "(User has instructed to sign a contract...)\n");

			OTAPI_Wrap::OTAPI()->GetClient()->ProcessUserCommand(OTClient::signContract, theMessage,
				*pMyNym, *pServerContract,
				NULL);
			continue;            
		}

		// sendUserMessage
		else if (buf[0] == 's')
		{
			OTLog::Output(0, "(User has instructed to send a sendUserMessage command to the server...)\n");

			// ------------------------------------------------------------------------------			
			// if successful setting up the command payload...

			if (0 < OTAPI_Wrap::OTAPI()->GetClient()->ProcessUserCommand(OTClient::sendUserMessage, theMessage, 
				*pMyNym, *pServerContract,
				NULL)) // NULL pAccount on this command.
			{
				bSendCommand = true;
			}
			else
				OTLog::vError("Error processing sendUserMessage command in ProcessMessage: %c\n", buf[0]);
			// ------------------------------------------------------------------------
		}

		// process nymbox 
		else if (strLine.compare(0,2,"py") == 0)
		{
			OTLog::Output(0, "(User has instructed to send a processNymbox command to the server...)\n");

			// ------------------------------------------------------------------------------			
			// if successful setting up the command payload...

			if (0 < OTAPI_Wrap::OTAPI()->GetClient()->ProcessUserCommand(OTClient::processEntireNymbox, theMessage, 
				*pMyNym, *pServerContract,
				NULL)) // NULL pAccount on this command.
			{
				bSendCommand = true;
			}
			else
				OTLog::vError("Error in processNymbox command in ProcessMessage: %s\n", strLine.c_str());
			// ------------------------------------------------------------------------
		}

		// get nymbox 
		else if (buf[0] == 'y')
		{
			OTLog::Output(0, "(User has instructed to send a getNymbox command to the server...)\n");

			// ------------------------------------------------------------------------------			
			// if successful setting up the command payload...

			if (0 < OTAPI_Wrap::OTAPI()->GetClient()->ProcessUserCommand(OTClient::getNymbox, theMessage, 
				*pMyNym, *pServerContract,
				NULL)) // NULL pAccount on this command.
			{
				bSendCommand = true;
			}
			else
				OTLog::vError("Error processing getNymbox command in ProcessMessage: %c\n", buf[0]);
			// ------------------------------------------------------------------------
		}

		// Nym, Account, Server ID, Server Contract

		// process inbox 
		else if (strLine.compare(0,2,"pi") == 0)
		{
			OTLog::Output(0, "(User has instructed to send a processInbox command to the server...)\n");

			// ------------------------------------------------------------------------------			
			// if successful setting up the command payload...

			if (0 < OTAPI_Wrap::OTAPI()->GetClient()->ProcessUserCommand(OTClient::processEntireInbox, theMessage, 
				*pMyNym, *pServerContract,
				NULL)) // have to allow this to be defaulted at some point...
			{
				bSendCommand = true;
			}
			else
				OTLog::vError("Error in processInbox command in ProcessMessage: %s\n", strLine.c_str());
			// ------------------------------------------------------------------------
		}

		// get inbox 
		else if (buf[0] == 'i')
		{
			OTLog::Output(0, "(User has instructed to send a getInbox command to the server...)\n");

			// ------------------------------------------------------------------------------			
			// if successful setting up the command payload...

			if (0 < OTAPI_Wrap::OTAPI()->GetClient()->ProcessUserCommand(OTClient::getInbox, theMessage, 
				*pMyNym, *pServerContract,
				NULL))
			{
				bSendCommand = true;
			}
			else
				OTLog::vError("Error processing getInbox command in ProcessMessage: %c\n", buf[0]);
			// ------------------------------------------------------------------------
		}

		// get outbox 
		else if (buf[0] == 'o')
		{
			OTLog::Output(0, "(User has instructed to send a getOutbox command to the server...)\n");

			// ------------------------------------------------------------------------------			
			// if successful setting up the command payload...

			if (0 < OTAPI_Wrap::OTAPI()->GetClient()->ProcessUserCommand(OTClient::getOutbox, theMessage, 
				*pMyNym, *pServerContract,
				NULL))
			{
				bSendCommand = true;
			}
			else
				OTLog::vError("Error processing getOutbox command in ProcessMessage: %c\n", buf[0]);
			// ------------------------------------------------------------------------
		}

		// deposit cheque
		else if (buf[0] == 'q')
		{
			OTLog::Output(0, "User has instructed to deposit a cheque...\n");

			// ------------------------------------------------------------------------------			
			// if successful setting up the command payload...

			if (0 < OTAPI_Wrap::OTAPI()->GetClient()->ProcessUserCommand(OTClient::notarizeCheque, theMessage, 
				*pMyNym, *pServerContract,
				NULL))
			{
				bSendCommand = true;
			}
			else
				OTLog::vError("Error processing deposit cheque command in ProcessMessage: %c\n", buf[0]);
			// ------------------------------------------------------------------------
		}

		// deposit purse
		else if (buf[0] == 'p')
		{
			OTLog::Output(0, "(User has instructed to deposit a purse containing cash...)\n");

			// ------------------------------------------------------------------------------			
			// if successful setting up the command payload...

			if (0 < OTAPI_Wrap::OTAPI()->GetClient()->ProcessUserCommand(OTClient::notarizePurse, theMessage, 
				*pMyNym, *pServerContract,
				NULL))
			{
				bSendCommand = true;
			}
			else
				OTLog::vError("Error processing deposit command in ProcessMessage: %c\n", buf[0]);
			// ------------------------------------------------------------------------
		}

		// deposit tokens
		else if (buf[0] == 'd')
		{
			OTLog::Output(0, "(User has instructed to deposit cash tokens...)\n");

			// ------------------------------------------------------------------------------			
			// if successful setting up the command payload...

			if (0 < OTAPI_Wrap::OTAPI()->GetClient()->ProcessUserCommand(OTClient::notarizeDeposit, theMessage, 
				*pMyNym, *pServerContract,
				NULL))
			{
				bSendCommand = true;
			}
			else
				OTLog::vError("Error processing deposit command in ProcessMessage: %c\n", buf[0]);
			// ------------------------------------------------------------------------
		}

		// withdraw voucher
		else if (buf[0] == 'v')
		{
			OTLog::Output(0, "User has instructed to withdraw a voucher (like a cashier's cheque)...\n");

			// ------------------------------------------------------------------------------			
			// if successful setting up the command payload...

			if (0 < OTAPI_Wrap::OTAPI()->GetClient()->ProcessUserCommand(OTClient::withdrawVoucher, theMessage, 
				*pMyNym, *pServerContract,
				NULL)) // NULL pAccount on this command.
			{
				bSendCommand = true;
			}
			else
				OTLog::vError("Error processing withdraw voucher command in ProcessMessage: %c\n", buf[0]);
			// ------------------------------------------------------------------------
		}

		// withdraw cash
		else if (buf[0] == 'w')
		{
			OTLog::Output(0, "(User has instructed to withdraw cash...)\n");

			// ------------------------------------------------------------------------------			
			// if successful setting up the command payload...

			if (0 < OTAPI_Wrap::OTAPI()->GetClient()->ProcessUserCommand(OTClient::notarizeWithdrawal, theMessage, 
				*pMyNym, *pServerContract,
				NULL)) // NULL pAccount on this command.
			{
				bSendCommand = true;
			}
			else
				OTLog::vError("Error processing withdraw command in ProcessMessage: %c\n", buf[0]);
			// ------------------------------------------------------------------------
		}

		// activate payment plan
		else if (!strcmp(buf, "activate\n"))
		{
			OTLog::Output(0, "User has instructed to activate a payment plan...\n");

			// ------------------------------------------------------------------------------			
			// if successful setting up the command payload...

			if (0 < OTAPI_Wrap::OTAPI()->GetClient()->ProcessUserCommand(OTClient::paymentPlan, theMessage, 
				*pMyNym, *pServerContract,
				NULL)) // NULL pAccount on this command.
			{
				bSendCommand = true;
			}
			else
				OTLog::vError("Error processing payment plan command in ProcessMessage: %c\n", buf[0]);
			// ------------------------------------------------------------------------
		}

		// get account 
		else if (!strcmp(buf, "get\n"))
		{
			OTLog::Output(0, "(User has instructed to send a getAccount command to the server...)\n");

			// ------------------------------------------------------------------------------			
			// if successful setting up the command payload...

			if (0 < OTAPI_Wrap::OTAPI()->GetClient()->ProcessUserCommand(OTClient::getAccount, theMessage, 
				*pMyNym,  *pServerContract,
				NULL)) // NULL pAccount on this command.
			{
				bSendCommand = true;
			}
			else
				OTLog::vError("Error processing getAccount command in ProcessMessage: %c\n", buf[0]);
			// ------------------------------------------------------------------------
		}

		// get contract 
		else if (!strcmp(buf, "getcontract\n"))
		{
			OTLog::Output(0, "(User has instructed to send a getContract command to the server...)\n");

			// ------------------------------------------------------------------------------			
			// if successful setting up the command payload...

			if (0 < OTAPI_Wrap::OTAPI()->GetClient()->ProcessUserCommand(OTClient::getContract, theMessage, 
				*pMyNym, *pServerContract,
				NULL)) // NULL pAccount on this command.
			{
				bSendCommand = true;
			}
			else
				OTLog::vError("Error processing getContract command in ProcessMessage: %c\n", buf[0]);
			// ------------------------------------------------------------------------
		}

		// ------------------------------------------------------------------------

		else if (!strcmp(buf, "propose\n"))
		{
			OTLog::Output(0, "(User has instructed to propose a payment plan...)\n");

			OTAPI_Wrap::OTAPI()->GetClient()->ProcessUserCommand(OTClient::proposePaymentPlan, theMessage,
				*pMyNym, *pServerContract,
				NULL); // User owns Merchant (recipient) account
			continue;
		}

		else if (!strcmp(buf, "confirm\n"))
		{
			OTLog::Output(0, "(User has instructed to confirm a payment plan...)\n");

			OTAPI_Wrap::OTAPI()->GetClient()->ProcessUserCommand(OTClient::confirmPaymentPlan, theMessage,
				*pMyNym, *pServerContract,
				NULL); // the account info is already on the plan, right?
			continue;
		}

		// ------------------------------------------------------------------------

		else if (!strcmp(buf, "cheque\n"))
		{
			OTLog::Output(0, "(User has instructed to write a cheque...)\n");

			OTAPI_Wrap::OTAPI()->GetClient()->ProcessUserCommand(OTClient::writeCheque, theMessage,
				*pMyNym, *pServerContract,
				NULL); // It will ascertain the account inside the call.			
			continue;
		}

		// get mint 
		else if (!strcmp(buf, "getmint\n"))
		{
			OTLog::Output(0, "(User has instructed to send a getMint command to the server...)\n");

			// ------------------------------------------------------------------------------			
			// if successful setting up the command payload...

			if (0 < OTAPI_Wrap::OTAPI()->GetClient()->ProcessUserCommand(OTClient::getMint, theMessage, 
				*pMyNym,  *pServerContract,
				NULL)) // NULL pAccount on this command.
			{
				bSendCommand = true;
			}
			else
				OTLog::vError("Error processing getMint command in ProcessMessage: %c\n", buf[0]);
			// ------------------------------------------------------------------------
		}

		// notarize transfer 
		else if (buf[0] == 't')
		{
			OTLog::Output(0, "(User has instructed to send a Transfer command (Notarize Transactions) to the server...)\n");

			// ------------------------------------------------------------------------------			
			// if successful setting up the command payload...

			if (0 < OTAPI_Wrap::OTAPI()->GetClient()->ProcessUserCommand(OTClient::notarizeTransfer, theMessage, 
				*pMyNym,  *pServerContract,
				NULL)) // NULL pAccount on this command.
			{
				bSendCommand = true;
			}
			else
				OTLog::vError("Error processing notarizeTransactions command in ProcessMessage: %c\n", buf[0]);
			// ------------------------------------------------------------------------
		}

		// getRequest
		else if (buf[0] == 'g')
		{
			OTLog::Output(0, "(User has instructed to send a getRequest command to the server...)\n");

			// ------------------------------------------------------------------------------			
			// if successful setting up the command payload...

			if (0 < OTAPI_Wrap::OTAPI()->GetClient()->ProcessUserCommand(OTClient::getRequest, theMessage, 
				*pMyNym, *pServerContract,
				NULL)) // NULL pAccount on this command.
			{
				bSendCommand = true;
			}
			else
				OTLog::vError("Error processing getRequest command in ProcessMessage: %c\n", buf[0]);
			// ------------------------------------------------------------------------
		}

		// getTransactionNum
		else if (buf[0] == 'n')
		{
			// I just coded (here) for myself a secret option (for testing)...
			// Optionally instead of JUST 'n', I can put n <number>, (without brackets) and
			// this code will add that number to my list of issued and transaction numbers.
			// I already have the ability to clear the list, so now I can add numbers to it as well.
			// (Which adds to both lists.)
			// I can also remove a number from the transaction list but LEAVE it on the issued list,
			// for example by writing a cheque and throwing it away.
			//
			// This code is for testing and allows me to find and patch any problems without
			// having to re-create my data each time -- speeds up debugging.
			//
			long lTransactionNumber = ((strlen(buf) > 2) ? atol(&(buf[2])) : 0);

			if (lTransactionNumber > 0)
			{
				OTString strServerID;
				pServerContract->GetIdentifier(strServerID);

				OTLog::vOutput(0, "You are trying to mess around with your (add to your) transaction numbers.\n"
					"Enter the relevant server ID [%s]: ", strServerID.Get());

				std::string str_ServerID = OT_CLI_ReadLine();

				const OTString strTransNumServerID((str_ServerID.size() > 0) ? str_ServerID.c_str() : strServerID.Get());

				// --------------------------

				pMyNym->AddTransactionNum(*pMyNym, strTransNumServerID, lTransactionNumber, true); // bool bSave=true

				OTLog::vOutput(0, "Transaction number %ld added to both lists (on client side.)\n", 
					lTransactionNumber);
			}

			else 
			{
				OTLog::Output(0, "(User has instructed to send a getTransactionNum command to the server...)\n");

				// ------------------------------------------------------------------------------			
				// if successful setting up the command payload...

				if (0 < OTAPI_Wrap::OTAPI()->GetClient()->ProcessUserCommand(OTClient::getTransactionNum, theMessage, 
					*pMyNym,  *pServerContract,
					NULL)) // NULL pAccount on this command.
				{
					bSendCommand = true;
				}
				else
					OTLog::vError("Error processing getTransactionNum command in ProcessMessage: %c\n", buf[0]);
			}

			// ------------------------------------------------------------------------
		}

		else 
		{
			{
				//gDebugLog.Write("unknown user command in ProcessMessage in main.cpp");
				OTLog::Output(0, "\n");
				//				OTLog::vError( "unknown user command in ProcessMessage in main.cpp: %d\n", buf[0]);
			}		
			continue;
		}


		// ************************************************************************


		const OTPseudonym * pServerNym = pServerContract->GetContractPublicNym();

		if (bSendCommand && (NULL != pServerNym) && pServerNym->VerifyPseudonym())
		{
			OTString strEnvelopeContents(theMessage);
			OTEnvelope theEnvelope;
			theEnvelope.Seal(*pServerNym, strEnvelopeContents);							  
			// -----------------------------------

			OTAPI_Wrap::It()->OTAPI()->GetTransportCallback()->operator()(*pServerContract, theEnvelope);
            
		} // if bSendCommand
	} // for

	// -----------------------------------------------------------


	OTLog::Output(0, "Exiting OT prompt.\n");

	// NOTE: Cleanup is handled via a nested class at the top of this main function.

	return 0;
}

