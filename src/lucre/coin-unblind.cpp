#include "bank.h"

int LucreCoinUnblind(int argc,char **argv)
{
    if(argc != 5)
	{
	fprintf(stderr,"%s <bank public info> <private coin request> <signed coin request> <coin>\n",
		argv[0]);
	exit(1);
	}
    const char *szBankFile=argv[1];
    const char *szPrivateRequestFile=argv[2];
    const char *szSignatureFile=argv[3];
    const char *szCoinFile=argv[4];

    SetDumper(stderr);

    BIO *bioBank=BIO_new_file(szBankFile,"r");
    BIO *bioPrivateRequest=BIO_new_file(szPrivateRequestFile,"r");
    BIO *bioSignature=BIO_new_file(szSignatureFile,"r");
    BIO *bioCoin=BIO_new_file(szCoinFile,"w");

    PublicBank bank(bioBank);
    CoinRequest req(bioPrivateRequest);
    ReadNumber(bioSignature,"request=");
    BIGNUM *bnSignature=ReadNumber(bioSignature,"signature=");
    DumpNumber("signature=",bnSignature);
    Coin coin;
    req.ProcessResponse(&coin,bank,bnSignature);
    coin.WriteBIO(bioCoin);
	return 1;
}
