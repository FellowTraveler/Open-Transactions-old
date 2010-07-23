extern "C"
{
#include <stdio.h>

#include <openssl/ssl.h>
}

#include "OTString.h"
#include "OTIdentifier.h"
#include "OTPseudonym.h"
#include "OTAssetContract.h"
#include "OTMint.h"


// run this program from inside the transaction directory (it's a tool for creating mints for the server.)

int main (int argc, char * const argv[])
{
	
	if (argc < 3)
	{
		printf("Usage:  otcreatemint server_id asset_type_id\n");
		exit(1);
	}
	
	SSL_library_init();
	SSL_load_error_strings();

	
	OTString strServerID(argv[1]), strAssetTypeID(argv[2]);
	
	OTIdentifier ASSET_TYPE_ID(strAssetTypeID);
	
	OTString strMintPath;
	strMintPath.Format("mints/%s", strAssetTypeID.Get()); // todo stop hardcoding paths
	OTMint * pMint = new OTMint(strAssetTypeID, strMintPath, strAssetTypeID);
	
	if (pMint && pMint->LoadContract())
	{
		printf("The mint already exists. Delete it first if you wish to re-create it.\n");
	}
	else 
	{
		fprintf(stderr, "Error loading mint for asset type: %s. Creating...\n", strAssetTypeID.Get());
		
		if (pMint)
		{	
			// TODO: read the denominations out of the asset contract itself, instead of hardcoding them here.
			
			OTPseudonym theNym;
			theNym.SetIdentifier(strServerID);
			
			// This part requires the server operator to enter his passphrase.
			// Which is why the server can't just fire it off automatically and
			// make a mint available to the client.  The client has to wait a day or
			// until the operator is able to run this script and type the passphrase.
			if (theNym.Loadx509CertAndPrivateKey())
			{										// penny, nickel, dime, quarter, $1, $5, $10, $20, $100, $1000
				pMint->GenerateNewMint(ASSET_TYPE_ID, theNym, 1, 5, 10, 25, 100, 500, 1000, 2000, 10000, 100000);
				
				pMint->SetSavePrivateKeys(); // This causes the next serialization to save the private, not just public, keys.
				pMint->SignContract(theNym);
				pMint->SaveContract(strMintPath.Get());  // save the mint file.
				
				// Now I sign it again, to get the private keys out of there.
				pMint->ReleaseSignatures();
				pMint->SignContract(theNym);
				strMintPath.Format("mints/%s.PUBLIC", strAssetTypeID.Get());
				pMint->SaveContract(strMintPath.Get());
				printf("Done.\n");
			}
			else {
				printf("Error calling theNym.Loadx509CertAndPrivateKey()\n");
			}
		}
		else 
		{
			fprintf(stdout, "Error allocating memory for new OTMint.\n");
		}
	}
	
	return 0;
}
