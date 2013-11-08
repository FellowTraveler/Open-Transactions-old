#!/usr/bin/env php
<?php
   
function getInput($msg){
    fwrite(STDOUT, "$msg");
    $varin = trim(fgets(STDIN));
    return $varin;
}
    
    $path = 'C:\\Users\\JSpit-PC\\AppData\\Roaming\\OpenTransactions';
    
    // NOTE: This unlink is unnecessary as long as we are properly calling
    // OTAPI_Basic_AppShutdown() at the bottom of this file (and we are...)
    //
//  $a = unlink($path . '\\client_data\ot.pid');

    $nb = getInput("\n\nBefore running this script, I had to copy\n /Users/au/.local/lib/libotapi-php.dylib to:\n /usr/local/lib/php/extensions/no-debug-non-zts-20090626 \n I figured out the folders based on PHP complaining when it could find otapi.so.\nYou might have to do something similar so your PHP can find the otapi.\nOh and also, I had to rename libotapi-php.dylib to otapi.so.\nI also had to copy otapi.php (from SWIG) into this folder.\n\nAlso, make sure the server is running (otserver)\n\nOkay, ready to test?\nPress enter TWICE to try out the OT API... ");

    include("otapi.php");

    OTAPI_Basic_AppStartup();

    # These functions are perfect examples of the 'Low-level API',
    # which is useful for simple functions that don't require messaging
    # any OT servers. See OTAPI_Basic.h and OTAPI.h for the complete
    # low-level API.

    OTAPI_Basic_Init();
    
    date_default_timezone_set('UTC');
    $tm = OTAPI_Basic_GetTime();
    $date = date("d/m/Y H:i:s", $tm);
    echo(  $tm . " = " . $date . "<br>");

    OTAPI_Basic_SetWallet('wallet.xml');

    if (!OTAPI_Basic_WalletExists()):
       die(' wallet not found<br>');
    else:
       echo(' wallet exists.<br>');
    endif;

   //myClass("test");
   //$caller   = new OTCaller();
   //$callback = new PHPCallback();
   //$p1 = OTCaller_setCallback($callback);
   //OT_API_Set_PasswordCallback($p1);   


    $s_theCaller   = new OTCaller();
    //$s_theCaller   = getInstanceOf( "OTCaller"); 
    $s_theCallback = new PHPCallback();

    if ((null == $s_theCaller) || (null == $s_theCallback)) {
       $s_theCaller   = null;
       $s_theCallback = null;
       echo("OneTimeOnly.GiveItAShot(): ERROR: Failure instantiating caller or callback objects.");
     }

     $s_theCaller->setCallback($s_theCallback);
     $bSuccess = OT_API_Set_PasswordCallback($s_theCaller);

     if (!$bSuccess) {
        $s_theCaller   = null;
        $s_theCallback = null;
        //LoadState.setStageFailed();
        echo("OneTimeOnly.GiveItAShot(): ERROR: Failure instantiating caller or callback objects.");
     }
     echo("SUCCESS setting the password callback.<br>");
   
    OTAPI_Basic_LoadWallet();
    // -----------------------------------------
    # Use the low-level API to see how many server contracts
    # are in the user's wallet.
    
    $count = OTAPI_Basic_GetServerCount();
    echo "Server count: ".$count."<br>";

    for ($i=0;$i<$count;$i++) {
    //$srvID = OTAPI_Basic_GetServer_ID($i);
    $srvID = OTAPI_Basic_GetServer_ID($i);
    echo("Server Id : " . $srvID . '&nbsp;&nbsp;&nbsp;');
    $server_name = OTAPI_Basic_GetServer_Name($srvID);
    echo($server_name . '<br>');
    }

    $nym_cnt = OTAPI_Basic_GetNymCount();
    echo('nym count = ' . $nym_cnt . '<br>');

    for ($i=0;$i<$nym_cnt;$i++) {
    $nymID = OTAPI_Basic_GetNym_ID($i);
    echo("Nym Id : " . $nymID . '&nbsp;&nbsp;&nbsp;&nbsp;');
    $nym_name = OTAPI_Basic_GetNym_Name($nymID);
    echo($nym_name . '<br>');
    }

    // -----------------------------------------
    # OT MADE EASY  (high-level API)
    #
    # This object handles all the request/response going on with
    # any servers, plus all the retries and synchronization. It's
    # the 'High-level API'. See OTMadeEasy.h and OT_ME.h for the
    # complete set of high-level API functions.

    $objEasy = new OTMadeEasy();
    // -----------------------------------------
    #
    # Use the High-level API to download a user's public key from
    # the server. (Obviously this will fail if the server is not
    # running, or if the test data is not installed.)

    $strCheck = $objEasy->check_user('r1fUoHwJOWCuK3WBAAySjmKYqsG6G2TYIxdqY6YNuuG', 'DYEB6U7dcpbwdGrftPnslNKz76BDuBTFAjiAgKaiY2n', 'HpDoVBTix9GRLvZZoKBi2zv2f4IFVLmRrW2Q0nAA0OH');

    // -----------------------------------------
    # objEasy.check_user corresponds to the command-line:
    #   'opentxs checknym'
    #
    # It's a useful test because it shows whether a server message
    # is successful, before going the extra step of trying a real
    # financial transaction.
    #
    # Therefore we only need to verify the Message Success, and not
    # any transaction success. (Remember, a successful message can
    # still contain a failed transaction.)

    $nResult = $objEasy->VerifyMessageSuccess($strCheck);
    
    if ($nResult < 0)
    {
        echo "Error in check nym. Is the server running? Is the test data in ~/.ot ?<br>";
    }
    else if ($nResult == 0)
    {
        echo "Failure in check nym. Is the test data in ~/.ot ?<br>";
    }
    else if ($nResult == 1)
    {
        echo "\n Success in check nym.<br>";
    }
    else
    {
        echo "Unexpected return value in check nym.<br>";
    }


# ---------------------------------------------------------
#
# Use the high-level API to withdraw some cash (1 silver gram)
# from FT's Silver account. (Obviously this will not work if the
# localhost server is not running, or if the test data is not
# installed to ~/.ot )

# This is a "real" financial transaction:
#
    $strWithdraw = $objEasy->withdraw_cash('r1fUoHwJOWCuK3WBAAySjmKYqsG6G2TYIxdqY6YNuuG', 'DYEB6U7dcpbwdGrftPnslNKz76BDuBTFAjiAgKaiY2n', 'yQGh0vgm9YiqYOh6bfLDxyAA7Nnh2NmturCQmOt4LTo', '1');
# ---------------------------------------------------------
# InterpretTransactionMsgReply
#
# This function first verifies whether the message itself was a success.
# (For example, what if the server was down, and never received it?)
#
# Once it verifies that the reply was successful as a message, then it
# peers deeper, to see whether the balance agreement was successful as well.
# (After all, any transaction is automatically rejected if the balance
# agreement is poorly-formed.)
#
# Then if the balance agreement was successful, then finally, this same
# function (InterpretTransactionMsgReply) checks to see whether the
# transaction ITSELF was successful. After all, maybe there was an error
# saving it back to disk on the server side and this caused the transaction
# to fail. Or maybe there wasn't enough money in the account. Etc. All of
# the above work is done in the below call:
    
    $nResult = $objEasy->InterpretTransactionMsgReply('r1fUoHwJOWCuK3WBAAySjmKYqsG6G2TYIxdqY6YNuuG', 'DYEB6U7dcpbwdGrftPnslNKz76BDuBTFAjiAgKaiY2n', 'yQGh0vgm9YiqYOh6bfLDxyAA7Nnh2NmturCQmOt4LTo', 'withdraw_cash', $strWithdraw);
        
    if ($nResult < 0)
    {
        echo "Error in withdraw cash. Is the server running? Is the test data in ~/.ot ?\n<br>";
    }
    else if ($nResult == 0)
    {
        echo "Failure in withdraw cash. Is the test data in ~/.ot ?\n<br>";
    }
    else if ($nResult == 1)
    {
        echo "\n Success in withdraw cash! (Using high-level API in PHP.)\n<br>";
    }
    else
    {
        echo "Unexpected return value in withdraw cash.'\n<br>";
    }


# ---------------------------------------------------------
# At this point we're done. We've downloaded a public key from
# the OT server, and we've also withdrawn a little cash from the
# server. We've demonstrated that both the high-level and low-level
# OT APIs are operational through PHP.

# So... we're done. Let's shutdown OT and finish execution.
# (Using the low-level API...)
    
    OTAPI_Basic_Output(0, "\nOne more thing: Successfully used OT_API_Output.\n<br>");
  
    OTAPI_Basic_AppShutdown();
    
# P.S. to see the complete OT high-level API:  OTMadeEasy.h
#  and to see the complete OT low-level  API:  OTAPI_Basic.h
#
# See the Open-Transactions/include/otapi folder for all
# relevant headers. OTMadeEasy is a wrapper for OT_ME, and
# OTAPI_Basic is a wrapper for OTAPI.
#
# One more thing: If you want to see a lot of free sample code
# similar to the above code, which shows you how to use all the
# different OT API function calls, check out this file:
#
#        Open-Transactions/scripts/ot/ot_commands.ot
#
# (It contains the complete implementation for a command-line
#  Open-Transactions client.)
# --------------------------------------

   
?>