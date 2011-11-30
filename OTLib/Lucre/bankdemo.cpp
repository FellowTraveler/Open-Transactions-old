#include <openssl/bio.h>
#include <openssl/dh.h>
#include <openssl/sha.h>
#include <memory.h>
#include <assert.h>

#define COIN_LENGTH		8
#define BLINDING_LENGTH		8

#define PRIME_LENGTH		(COIN_LENGTH+SHA_DIGEST_LENGTH)

static void cb(int p, int, void *arg)
    {
    char c='*';

    if (p == 0) c='.';
    if (p == 1) c='+';
    if (p == 2) c='*';
    if (p == 3) c='\n';
    BIO_write((BIO *)arg,&c,1);
    BIO_flush((BIO *)arg);
    }

static void Hex(const unsigned char *acBuf,int nLength)
    {
    for(int n=0 ; n < nLength ; ++n)
	printf("%02X",acBuf[n]);
    printf("\n");
    }

int LucreBankDemo(int /*argc*/,char **/*argv*/)
    {
    DH *a;
    BIO *out;

    out=BIO_new(BIO_s_file());
    if(out == NULL)
	exit(1);
    BIO_set_fp(out,stdout,BIO_NOCLOSE);

    a=DH_generate_parameters(PRIME_LENGTH*8,DH_GENERATOR_5,cb,out);
    assert(a);
    assert(BN_num_bytes(a->p) == PRIME_LENGTH);  // can this fail? i.e. does OpenSSL check for length when generating?

    BIO_puts(out,"\np=        ");
    BN_print(out,a->p);
    BIO_puts(out,"\ng=        ");
    BN_print(out,a->g);
    BIO_puts(out,"\n");

    int nRet=DH_generate_key(a);
    assert(nRet);
    BIO_puts(out,"k=        ");
    BN_print(out,a->priv_key);
    BIO_puts(out,"\ng^k=      ");
    BN_print(out,a->pub_key);
    BIO_puts(out,"\n");

    // now generate the coin request
    BIGNUM *x=BN_new();
    unsigned char xplusd[COIN_LENGTH+SHA_DIGEST_LENGTH];
    BIGNUM *y=BN_new();
    for( ; ; )
	{
	// choose x
	BN_rand(x,COIN_LENGTH*8,0,1);	// make sure we use the whole length
	BIO_puts(out,"x=        ");
	BN_print(out,x);
	BIO_puts(out,"\n");

	assert(BN_num_bytes(x) == COIN_LENGTH);

	// generate y=x|hash(x)
	memset(xplusd,'\0',COIN_LENGTH);
	assert(BN_num_bytes(x) <= COIN_LENGTH);
	BN_bn2bin(x,xplusd);

	SHA_CTX c;
	SHA_Init(&c);
	SHA_Update(&c,xplusd,COIN_LENGTH);
	SHA_Final(&xplusd[COIN_LENGTH],&c);
	
	BIO_puts(out,"x|hash(x)=");
	Hex(xplusd,COIN_LENGTH+SHA_DIGEST_LENGTH);

	BN_bin2bn(xplusd,COIN_LENGTH+SHA_DIGEST_LENGTH,y);
	BIO_puts(out,"y=        ");
	BN_print(out,y);
	BIO_puts(out,"\n");

	if(BN_cmp(y,a->p) < 0)
	    break;
	}

    // choose b
    BIGNUM *b=BN_new();
    BN_rand(b,BLINDING_LENGTH*8,0,0);
    BIO_puts(out,"b=        ");
    BN_print(out,b);
    BIO_puts(out,"\n");

    // calculate A->B: y g^b
    BIGNUM *AtoB=BN_new();
    BN_CTX *ctx=BN_CTX_new();

    BN_mod_exp(AtoB,a->g,b,a->p,ctx);
    BN_mod_mul(AtoB,AtoB,y,a->p,ctx);
    BIO_puts(out,"A->B=     ");
    BN_print(out,AtoB);
    BIO_puts(out,"\n");

    // calculate B->A: (A->B)^k=(y g^b)^k
    BIGNUM *BtoA=BN_new();
    BN_mod_exp(BtoA,AtoB,a->priv_key,a->p,ctx);
    BIO_puts(out,"B->A=     ");
    BN_print(out,BtoA);
    BIO_puts(out,"\n");

    // calculate z=(y g^b)^k (g^k)^-b=(BtoA) (g^k)^-b
    BIGNUM *z=BN_new();
    BN_mod_exp(z,a->pub_key,b,a->p,ctx);
    BN_mod_inverse(z,z,a->p,ctx);
    BN_mod_mul(z,BtoA,z,a->p,ctx);
    BIO_puts(out,"z=        ");
    BN_print(out,z);
    BIO_puts(out,"\n");

    // confirm z == y^k (not possible in a real system, because that's the whole dang point!)
    BIGNUM *t=BN_new();
    BN_mod_exp(t,y,a->priv_key,a->p,ctx);
    BIO_puts(out,"y^k=      ");
    BN_print(out,t);
    BIO_puts(out,"\n");

    BN_sub(t,t,z);
    assert(BN_is_zero(t));

    // for clarity, show the coin:
    BIO_puts(out,"coin=    (");
    BN_print(out,x);
    BIO_puts(out,",");
    BN_print(out,z);
    BIO_puts(out,")\n");

    // and convert it to hex...
    unsigned char coin[COIN_LENGTH+PRIME_LENGTH];
    BN_bn2bin(x,coin);
    BN_bn2bin(z,&coin[COIN_LENGTH]);

    BIO_puts(out,"hexcoin=  ");
    Hex(coin,sizeof coin);

    // and finally, check the coin (pointless here, but included for completeness)
    //    unsigned char check_xplusd[COIN_LENGTH+SHA_DIGEST_LENGTH];
    

		return 1;
    }

