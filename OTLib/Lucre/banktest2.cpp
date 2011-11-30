#include "bank.h"
#include <stdlib.h>

static const char acBankPrivate[]=
"g=5\n"
"p=FE1D6186F8993ACAA8BA41C605B784B31A313314122580F20C7304CC19183D16CDC673D3\n"
"public=3BCF8D4AB8E48373B0B221671DFE769825FF4C88807B94DCEE977FB04AB0A06EDABC512E\n"
"private=77560C6F9E99AB2E3B8FE32DCF5BF75E477CF0D2977EBCC60AF32911F6D62DD4626A2E3C\n";

static const char acCoinPrivate[]=
"request=8AA33FFA7D3096CE4D2E933923D31A4769ACF8BB8421E32EC6D9190E63690E58E44D012C\n"
"id=C8A941A01D0B316094C4455117A2B947\n"
"blinding=C6FE1F070531D18B\n";


int LucreBankTest2(int /*argc*/,char **/*argv*/)
    {
    BIO *dout;
    int nCoins=1;

    dout=BIO_new(BIO_s_file());
    if(dout == NULL)
	exit(1);
    BIO_set_fp(dout,stdout,BIO_NOCLOSE);
    SetDumper(dout);

    BIO *mem=BIO_new(BIO_s_mem());
    BIO_write(mem,acBankPrivate,strlen(acBankPrivate));
    Bank _bank(mem);
    _bank.Dump();

    PublicBank bank(_bank);

    for(int n=0 ; n < nCoins ; ++n)
	{
	printf("\nCoin %d\n\n",n);
	// now generate the coin request
	//	CoinRequest request(bank);
	BIO_write(mem,acCoinPrivate,strlen(acCoinPrivate));
	CoinRequest request(mem);

	// calculate B->A: (A->B)^k=(y g^b)^k
	BIGNUM *bnSignedCoin=_bank.SignRequest(request);
	DumpNumber("signature=",bnSignedCoin);

	// calculate z=(y g^b)^k (g^k)^-b=(BtoA) (g^k)^-b
	Coin coin;
	request.ProcessResponse(&coin,bank,bnSignedCoin);
	coin.Dump();

	boolean bRet=_bank.Verify(coin);
	assert(bRet);
	}

	return 1;
}

