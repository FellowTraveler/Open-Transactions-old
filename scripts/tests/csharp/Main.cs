using System;
using OtAPI;

namespace otest
{
    class MainClass
    {
        public static void Main (string[] args)
        {
            OTAPI_Basic.AppStartup();
            OTAPI_Basic.Init();
            OTAPI_Basic.LoadWallet();

            int count = OTAPI_Basic.GetServerCount();

            Console.Out.WriteLine("Server count {0}", count.ToString());

            OTMadeEasy otme = new OTMadeEasy();

            string strCheck = otme.check_user("tBy5mL14qSQXCJK7Uz3WlTOKRP9M0JZksA3Eg7EnnQ1", 
                            "T1Q3wZWgeTUoaUvn9m1lzIK5tn5wITlzxzrGNI8qtaV", 
                            "T1Q3wZWgeTUoaUvn9m1lzIK5tn5wITlzxzrGNI8qtaV");


            int nResult = otme.VerifyMessageSuccess(strCheck);


            if(nResult < 0)
                Console.Out.WriteLine("Error in check nym. Is the server running? Is the test data in ~/.ot ?");
            if(nResult == 0)
                Console.Out.WriteLine("Failure in check nym. Is the test data in ~/.ot ?");
            if(nResult == 1)
                Console.Out.WriteLine("Success in check nym.");
            else
                Console.Out.WriteLine("Unexpected return value in check nym.");


            string strWithdraw = otme.withdraw_cash("tBy5mL14qSQXCJK7Uz3WlTOKRP9M0JZksA3Eg7EnnQ1", 
                               "T1Q3wZWgeTUoaUvn9m1lzIK5tn5wITlzxzrGNI8qtaV", 
                               "eMldMMiKfJRO8B8yJjzcezs9xvSt7dkdlWt50e8CDxn", "1");


            nResult = otme.InterpretTransactionMsgReply("tBy5mL14qSQXCJK7Uz3WlTOKRP9M0JZksA3Eg7EnnQ1", 
                                                        "T1Q3wZWgeTUoaUvn9m1lzIK5tn5wITlzxzrGNI8qtaV", 
                                                        "eMldMMiKfJRO8B8yJjzcezs9xvSt7dkdlWt50e8CDxn", 
                                                        "withdraw_cash", strWithdraw);

            if(nResult < 0)
                Console.WriteLine("Error in withdraw cash. Is the server running? Is the test data in ~/.ot ?");
            if(nResult == 0)
                Console.WriteLine("Failure in withdraw cash. Is the test data installed in ~/.ot ?");
            if(nResult == 1)
                Console.WriteLine("Success in withdraw cash! (Using high-level API in Python.");
            else
                Console.Out.WriteLine("Unexpected return value in withdraw cash.");

            OTAPI_Basic.Output(0, "One more thing: Successfully used OT_API_Output.");


            OTAPI_Basic.AppShutdown();
        }
    }
}
