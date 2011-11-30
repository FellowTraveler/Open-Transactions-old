#include "bank.h"

int LucreBankVerify(int argc,char **argv)
    {
    if(argc != 3)
	{
	fprintf(stderr,"%s <bank info> <coin>\n",argv[0]);
	exit(1);
	}
    const char *szBankFile=argv[1];
    const char *szCoinFile=argv[2];

    SetDumper(stderr);

    BIO *bioBank=BIO_new_file(szBankFile,"r");
    BIO *bioCoin=BIO_new_file(szCoinFile,"r");

    Bank bank(bioBank);
    Coin coin(bioCoin);

    if(!bank.Verify(coin))
	{
	fprintf(stderr,"Bad coin!\n");
	exit(1);
	}
    exit(0);
    }
