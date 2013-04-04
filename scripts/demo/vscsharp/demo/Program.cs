using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace demo
{
    using otapi = org.opentransactions.otapi;

    class Program
    {
        static void Main(string[] args)
        {
            var instance = otvs.Load.Instance;

            // These functions are perfect examples of the 'Low-level API',
            // which is useful for simple functions that don't require messaging
            // any OT servers. See OTAPI_Basic.h and OTAPI.h for the complete
            // low-level API.

            if (!otapi.OTAPI_Basic.Init())
            {
                Console.Out.WriteLine();
                Console.Out.WriteLine("Press any key to close window...");
                Console.ReadKey();
                return;
            }

            otapi.OTAPI_Basic.LoadWallet();

            System.Console.Out.WriteLine("Loaded Wallet!");


            // ---------------------------------------------------------
            // Use the low-level API to see how many server contracts
            // are in the user's wallet.


            int count = otapi.OTAPI_Basic.GetServerCount();

            Console.Out.WriteLine("Server count {0}", count.ToString());

            // ---------------------------------------------------------

            // OT MADE EASY  (high-level API)

            // This object handles all the request/response going on with
            // any servers, plus all the retries and synchronization. It's
            // the 'High-level API'. See OTMadeEasy.h and OT_ME.h for the
            // complete set of high-level API functions.

            otapi.OTMadeEasy otme = new otapi.OTMadeEasy();

            // ---------------------------------------------------------
            //
            // Use the High-level API to download a user's public key from
            // the server. (Obviously this will fail if the server is not
            // running, or if the test data is not installed.)

            string strCheck = otme.check_user("tBy5mL14qSQXCJK7Uz3WlTOKRP9M0JZksA3Eg7EnnQ1",
                            "T1Q3wZWgeTUoaUvn9m1lzIK5tn5wITlzxzrGNI8qtaV",
                            "T1Q3wZWgeTUoaUvn9m1lzIK5tn5wITlzxzrGNI8qtaV");

            // ---------------------------------------------------------
            // objEasy.check_user corresponds to the command-line:
            //   'opentxs checknym'
            //
            // It's a useful test because it shows whether a server message
            // is successful, before going the extra step of trying a real
            // financial transaction.
            //
            // Therefore we only need to verify the Message Success, and not
            // any transaction success. (Remember, a successful message can
            // still contain a failed transaction.)

            int nResult = otme.VerifyMessageSuccess(strCheck);


            if (nResult < 0)
                Console.Out.WriteLine("Error in check nym. Is the server running? Is the test data in ~/.ot ?");
            if (nResult == 0)
                Console.Out.WriteLine("Failure in check nym. Is the test data in ~/.ot ?");
            if (nResult == 1)
                Console.Out.WriteLine("Success in check nym.");
            else
                Console.Out.WriteLine("Unexpected return value in check nym.");

            // ---------------------------------------------------------
            //
            // Use the high-level API to withdraw some cash (1 silver gram)
            // from FT's Silver account. (Obviously this will not work if the
            // localhost server is not running, or if the test data is not
            // installed to ~/.ot )

            // This is a "real" financial transaction:
            //
            string strWithdraw = otme.withdraw_cash("tBy5mL14qSQXCJK7Uz3WlTOKRP9M0JZksA3Eg7EnnQ1",
                               "T1Q3wZWgeTUoaUvn9m1lzIK5tn5wITlzxzrGNI8qtaV",
                               "eMldMMiKfJRO8B8yJjzcezs9xvSt7dkdlWt50e8CDxn", "1");

            // ---------------------------------------------------------
            // InterpretTransactionMsgReply
            //
            // This function first verifies whether the message itself was a 
            // success. (For example, what if the server was down, and never
            // received it?)
            //
            // Once it verifies that the reply was successful as a message, 
            // then it peers deeper, to see whether the balance agreement was
            // successful as well. (After all, any transaction is automatically
            // rejected if the balance agreement is poorly-formed.)
            //
            // Then if the balance agreement was successful, then finally,
            // this same function (InterpretTransactionMsgReply) checks to see
            // whether the transaction ITSELF was successful. After all, maybe
            // there was an error saving it back to disk on the server side 
            // and this caused the transaction to fail. Or maybe there wasn't
            // enough money in the account. Etc. All of the above work is done
            // in the below call:

            nResult = otme.InterpretTransactionMsgReply("tBy5mL14qSQXCJK7Uz3WlTOKRP9M0JZksA3Eg7EnnQ1",
                                                        "T1Q3wZWgeTUoaUvn9m1lzIK5tn5wITlzxzrGNI8qtaV",
                                                        "eMldMMiKfJRO8B8yJjzcezs9xvSt7dkdlWt50e8CDxn",
                                                        "withdraw_cash", strWithdraw);

            if (nResult < 0)
                Console.WriteLine("Error in withdraw cash. Is the server running? Is the test data in ~/.ot ?");
            if (nResult == 0)
                Console.WriteLine("Failure in withdraw cash. Is the test data installed in ~/.ot ?");
            if (nResult == 1)
                Console.WriteLine("Success in withdraw cash! (Using high-level API in Python.");
            else
                Console.Out.WriteLine("Unexpected return value in withdraw cash.");

            // ---------------------------------------------------------

            // At this point we're done. We've downloaded a public key from
            // the OT server, and we've also withdrawn a little cash from the
            // server. We've demonstrated that both the high-level and
            // low-level OT APIs are operational through Python.

            // So... we're done. Let's shutdown OT and finish execution.
            // (Using the low-level API...)
            otapi.OTAPI_Basic.Output(0, "One more thing: Successfully used OT_API_Output.");

            Console.Out.WriteLine();
            Console.Out.WriteLine("All tests finished...");
            Console.ReadKey();
            return;
        }
    }
}
