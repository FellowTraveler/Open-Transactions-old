#include "bank.h"

int LucreBankSign(int argc,char **argv)
{
    if(argc != 4 && argc != 5)
	{
	fprintf(stderr,"%s <bank file> <coin request> <coin signature> [<signature repeats>]\n",
		argv[0]);
	exit(1);
	}
    const char *szBankFile=argv[1];
    const char *szRequest=argv[2];
    const char *szSignature=argv[3];
    int nRepeats=1;
    if(argc >= 5)
	nRepeats=atoi(argv[4]);
    else
	SetDumper(stderr);

    BIO *bioBank=BIO_new_file(szBankFile,"r");
    BIO *bioRequest=BIO_new_file(szRequest,"r");
    BIO *bioSignature=BIO_new_file(szSignature,"w");

    Bank bank(bioBank);
    PublicCoinRequest req(bioRequest);
    for(int n=0 ; n < nRepeats-1 ; ++n)
	{
	BIGNUM *bnSignature=bank.SignRequest(req);
	BN_free(bnSignature);
	}
    BIGNUM *bnSignature=bank.SignRequest(req);
    req.WriteBIO(bioSignature);
    DumpNumber(bioSignature,"signature=",bnSignature);
	
	return 1;
}
	
