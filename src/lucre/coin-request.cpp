


#include "bank.h"

int LucreCoinRequest(int argc,char **argv)
{
    if(argc != 4)
	{
	fprintf(stderr,"%s <bank public info> <coin request> <public coin request>\n", argv[0]);
	exit(1);
	}
    const char *szBankFile=argv[1];
    const char *szCoinFile=argv[2];
    const char *szPublicCoinFile=argv[3];

    SetDumper(stderr);

    BIO *bioBank=BIO_new_file(szBankFile,"r");
    BIO *bioCoin=BIO_new_file(szCoinFile,"w");
    BIO *bioPublicCoin=BIO_new_file(szPublicCoinFile,"w");

    PublicBank bank;
    bank.ReadBIO(bioBank);

    CoinRequest req(bank);
    req.WriteBIO(bioCoin);
    ((PublicCoinRequest *)&req)->WriteBIO(bioPublicCoin);
		
	return 1;
}
