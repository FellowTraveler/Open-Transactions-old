extern "C"
{
#include <stdio.h>
	
#include <openssl/ssl.h>
}

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>


#include "OTString.h"
#include "OTIdentifier.h"
#include "OTPseudonym.h"
#include "OTAssetContract.h"


// Run this program from inside the testwallet directory.

int main (int argc, char * const argv[])
{
	
	if (argc < 3)
	{
		printf("Usage:  signcontract  nym_id  contract_file\n");
		exit(1);
	}
	
	SSL_library_init();
	SSL_load_error_strings();
	
	
	OTString strNymID(argv[1]), strContractFile(argv[2]);
	OTString NymName(strNymID), NymFile;
	
	NymFile.Format("nyms/%s", strNymID.Get());
	
	OTPseudonym theNym(NymName, NymFile, strNymID);
	
	if (theNym.LoadNymfile((char*)(NymFile.Get())))
	{
		if (theNym.Loadx509CertAndPrivateKey()) 
		{							
			if (theNym.VerifyPseudonym()) 
			{
				std::ifstream in(strContractFile.Get());
				
				std::stringstream buffer;
				buffer << in.rdbuf();
				
				std::string contents(buffer.str());
				
				OTString strContract(contents.c_str());				
				
				if (strContract.GetLength())
				{
					OTAssetContract theContract;
					theContract.CreateContract(strContract, theNym);

					OTString strOutput, strDigest;
					
					theContract.GetIdentifier(strDigest);
					theContract.SaveContract(strOutput);
					
					fprintf(stdout, "\n\n Contract ID:\n%s\n\nContract:\n%s\n", 
							strDigest.Get(), strOutput.Get());
				}
			}
		}
	}
	
	return 0;
}
