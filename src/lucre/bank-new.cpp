#include "bank.h"
#include <stdio.h>
#include <stdlib.h>

int LucreBankNew(int argc,char **argv)
{
    if(argc != 4)
	{
		fprintf(stderr,"%s <size of bank prime in bits> <bank data file> <bank public data file>\n",
			argv[0]);
		exit(1);
	}
	
    int nPrimeLength=atoi(argv[1]);
    const char *szFile=argv[2];
    const char *szPublicFile=argv[3];

    if(nPrimeLength/8 < MIN_COIN_LENGTH+DIGEST_LENGTH)
	{
		fprintf(stderr,"Prime must be at least %d bits\n",
			(MIN_COIN_LENGTH+DIGEST_LENGTH)*8);
		exit(2);
	}

    if(nPrimeLength%8)
	{
		fprintf(stderr,"Prime length must be a multiple of 8\n");
		exit(3);
	}

    SetMonitor(stdout);

    BIO *bio=BIO_new_file(szFile,"w");
    BIO *bioPublic=BIO_new_file(szPublicFile,"w");
    
    Bank bank(nPrimeLength/8);
    bank.WriteBIO(bio);
    PublicBank pbank(bank);
    pbank.WriteBIO(bioPublic);
	
	return 1;
}
