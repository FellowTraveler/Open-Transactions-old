#include "bank.h"
#include <stdlib.h>

int LucreBankTest(int argc,char **argv)
{
    BIO *dout;

    if (argc != 3)
	{
		fprintf(stderr,"%s <prime length> <number of coins>\n",argv[0]);
		exit(1);
	}
	
    int nPrimeLength	=	atoi(argv[1]);
    int nCoins			=	atoi(argv[2]);

    if ( (nPrimeLength/8) < (MIN_COIN_LENGTH+DIGEST_LENGTH) )
	{
		fprintf(stderr,"Prime must be at least %d bits\n",
			(MIN_COIN_LENGTH+DIGEST_LENGTH)*8);
		exit(2);
	}
	
    if (nPrimeLength%8)
	{
		fprintf(stderr,"Prime length must be a multiple of 8\n");
		exit(3);
	}

    dout=BIO_new(BIO_s_file());
    if(dout == NULL)
	exit(1);
    BIO_set_fp(dout,stdout,BIO_NOCLOSE);
    SetDumper(dout);

    Bank _bank(nPrimeLength/8);
    _bank.Dump();

    PublicBank bank(_bank);

    for(int n=0 ; n < nCoins ; ++n)
	{
		printf("\nCoin %d\n\n",n);
			
			
		// *** now GENERATE the coin request
		CoinRequest request(bank);
			
		// *** THE BANK SIGNS THE REQUEST
		// calculate B->A: (A->B)^k=(y g^b)^k
		BIGNUM *bnSignedCoin = _bank.SignRequest(request);

		// THE CLIENT UNBLINDS THE COIN HE RECEIVES FROM SERVER
		// calculate z=(y g^b)^k (g^k)^-b=(BtoA) (g^k)^-b
		Coin coin;
		request.ProcessResponse(&coin,bank,bnSignedCoin);
		
		coin.Dump();

		// **** VERIFY THE TOKEN WHEN REDEEMED AT THE SERVER
		boolean bRet=_bank.Verify(coin);
			
		assert(bRet);
	}

	return 1;
}

