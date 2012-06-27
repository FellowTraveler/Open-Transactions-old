//-*-C++-*-

#ifndef __LUCRE_WRAPPER__
#define __LUCRE_WRAPPER__

extern "C"
{
#include <openssl/bio.h>
#include <openssl/dh.h>
#include <openssl/sha.h>
#include <memory.h>
#include <assert.h>

#ifdef _WIN32
#include <malloc.h>
#endif
}

//#define SAMY_DIGEST_LENGTH		64	// 64 bytes aka 512 bits output for the SAMY hash.
//#define DIGEST_LENGTH		SAMY_DIGEST_LENGTH
//#define MIN_COIN_LENGTH		64
//#define BLINDING_LENGTH		32
#define MIN_COIN_LENGTH		16
#define BLINDING_LENGTH		8
#define DIGEST_LENGTH		SHA_DIGEST_LENGTH

typedef int LAURIE_BOOLEAN;

class Bank;
class PublicCoinRequest;
class CoinRequest;
class Coin;

extern const char _NL[];
void SetDumper(BIO *out);
void SetDumper(FILE *f);
void SetDumper(const char *filepathexact);       // Open-Transactions
void CleanupDumpFile(const char *filepathexact); // Open-Transactions
void SetMonitor(BIO *out);
void SetMonitor(FILE *f);
void SetMonitor(const char *filepathexact);      // Open-Transactions
void DumpNumber(BIO *out,const char *szTitle,const BIGNUM *bn,
		const char *szTrailer=_NL);
void DumpNumber(const char *szTitle,const BIGNUM *bn,
		const char *szTrailer=_NL);
void HexDump(BIO *out,const char *szTitle,const unsigned char *acBuf,
	     int nLength);
void HexDump(const char *szTitle,const unsigned char *acBuf,int nLength);
BIGNUM *ReadNumber(BIO *in,const char *szTitle);

class PublicBank
    {
protected:
    DH *m_pDH;
public:
    PublicBank(Bank &bank);
    PublicBank(BIO *bio)
	{
	m_pDH=NULL;
	ReadBIO(bio);
	}
    PublicBank()
	{ m_pDH=NULL; }
    ~PublicBank()
	{ DH_free(m_pDH); }
    const BIGNUM *p() const
	{ return m_pDH->p; }
    /*const*/ BIGNUM *g() // regrettably not const, coz C doesn't support mutable
	{ return m_pDH->g; }
    /*const*/ BIGNUM *pub_key() // see above
	{ return m_pDH->pub_key; }
    void WriteBIO(BIO *bio);
    void ReadBIO(BIO *bio);
    void Dump()
	{
	DumpNumber("p=        ",m_pDH->p);
	DumpNumber("g=        ",m_pDH->g);
	DumpNumber("g^k=      ",m_pDH->pub_key);
	}
    int CoinLength() const
	{
	return MIN_COIN_LENGTH+(PrimeLength()-MIN_COIN_LENGTH)%DIGEST_LENGTH;
	}
    int PrimeLength() const
	{ return BN_num_bytes(p()); }
    };

class Bank : public PublicBank
    {
    BN_CTX *m_ctx;

    static void cb(int p, int, void *arg);
public:
    Bank(int nPrimeLength)
	{
	assert(nPrimeLength >= MIN_COIN_LENGTH+DIGEST_LENGTH);
	m_pDH=DH_generate_parameters(nPrimeLength*8,DH_GENERATOR_5,cb,NULL);
	assert(m_pDH);
	assert(BN_num_bytes(m_pDH->p) == nPrimeLength);  // can this fail? i.e. does OpenSSL check for length when generating?
	int nRet=DH_generate_key(m_pDH);
	assert(nRet);
	m_ctx=NULL;
	}
    Bank(BIO *bio)
	{
	m_ctx=NULL;
	ReadBIO(bio);
	}
    ~Bank()
	{ BN_CTX_free(m_ctx); }
    void InitCTX()
	{
	if(!m_ctx)
	    m_ctx=BN_CTX_new();
	}
    void Dump()
	{
	PublicBank::Dump();
	DumpNumber("k=        ",m_pDH->priv_key);
	}
    const BIGNUM *priv_key()
	{ return m_pDH->priv_key; }
    /*const*/ BIGNUM *SignRequest(PublicCoinRequest &req);
    LAURIE_BOOLEAN Verify(Coin &coin);
    void WriteBIO(BIO *bio);
    void ReadBIO(BIO *bio);
    };

class UnsignedCoin
    {
protected:
    BIGNUM *m_bnCoinID;
public:
    UnsignedCoin()
	{ m_bnCoinID=NULL; }
    UnsignedCoin(BIGNUM *bnCoinID)
	{ m_bnCoinID=BN_dup(bnCoinID); }
    ~UnsignedCoin()
	{ BN_free(m_bnCoinID); }
    void Clear()
	{
	BN_free(m_bnCoinID);
	m_bnCoinID=NULL;
	}
    void Set(const BIGNUM *bnCoinID)
	{
	Clear();
	m_bnCoinID=BN_dup(bnCoinID);
	}
    void Random(int nCoinLength)
	{
	if(!m_bnCoinID)
	    m_bnCoinID=BN_new();
	// choose x
	BN_rand(m_bnCoinID,nCoinLength*8,0,1);
	DumpNumber("x=        ",m_bnCoinID);

	assert(BN_num_bytes(m_bnCoinID) == nCoinLength);
	}
	
    BIGNUM *ID()
	{ return m_bnCoinID; }
    LAURIE_BOOLEAN GenerateCoinNumber(BIGNUM *bnNumber,const PublicBank &bank)
	{
	int nCoinLength=BN_num_bytes(m_bnCoinID);
	int nDigestIterations=(bank.PrimeLength()-nCoinLength)/DIGEST_LENGTH;

	if(nCoinLength != bank.CoinLength())
	    return false;

	unsigned char *xplusd=
	  static_cast<unsigned char *>(alloca(bank.PrimeLength()));

	// generate y=x|hash(x)
	memset(xplusd,'\0',nCoinLength);
	BN_bn2bin(m_bnCoinID,xplusd);

		// Made some changes here... to use SAMY hash instead of SHA1...
		// spoke too soon... Changed back until I can have experts on this.
	for(int n = 0 ; n < nDigestIterations ; ++n)
	{
		/*
		OTData theContents(xplusd, nCoinLength+DIGEST_LENGTH*n);

		OTIdentifier theHash;
		theHash.CalculateDigest(theContents);
		theHash.CopyTo(&xplusd[nCoinLength+DIGEST_LENGTH*n]);
		*/
		
	    SHA1(xplusd,
			 nCoinLength+DIGEST_LENGTH*n, 
			 &xplusd[nCoinLength+DIGEST_LENGTH*n]
			 );
	}
		
	HexDump("x|hash(x)=",xplusd,
		nCoinLength+nDigestIterations*DIGEST_LENGTH);

	BN_bin2bn(xplusd,nCoinLength+nDigestIterations*DIGEST_LENGTH,bnNumber);
	DumpNumber("y=        ",bnNumber);

	return true;
	}
    void Dump()
	{
	DumpNumber("coin=     ",m_bnCoinID);
	}
    void WriteBIO(BIO *bio);
    void ReadBIO(BIO *bio);
    };

class Coin : public UnsignedCoin
    {
    BIGNUM *m_bnCoinSignature;
public:
    Coin()
	{ m_bnCoinSignature=NULL; }
    Coin(BIO *bio)
	{
	m_bnCoinSignature=NULL;
	ReadBIO(bio);
	}
    Coin(BIGNUM *bnCoinID,BIGNUM *bnCoinSignature)
      : UnsignedCoin(bnCoinID)
	{ m_bnCoinSignature=BN_dup(bnCoinSignature); }
    ~Coin()
	{ BN_free(m_bnCoinSignature); }
    void Clear()
	{
	BN_free(m_bnCoinSignature);
	m_bnCoinSignature=NULL;
	UnsignedCoin::Clear();
	}
    void Set(BIGNUM *bnCoinID,BIGNUM *bnCoinSignature)
	{
	Clear();
	m_bnCoinSignature=BN_dup(bnCoinSignature);
	UnsignedCoin::Set(bnCoinID);
	}
    void Set(UnsignedCoin &ucoin,BIGNUM *bnCoinSignature)
	{ Set(ucoin.ID(),bnCoinSignature); }
    void Dump()
	{
	DumpNumber("coin=    (",m_bnCoinID,"");
	DumpNumber(",",m_bnCoinSignature,")\n");
	}
    BIGNUM *Signature()
	{ return m_bnCoinSignature; }
    void WriteBIO(BIO *bio);
    void ReadBIO(BIO *bio);
    };

class PublicCoinRequest
    {
protected:
    BIGNUM *m_bnCoinRequest;
public:
    PublicCoinRequest()
	{ m_bnCoinRequest=NULL; }
    PublicCoinRequest(BIO *bio)
	{
	m_bnCoinRequest=NULL;
	ReadBIO(bio);
	}
    ~PublicCoinRequest()
	{ BN_free(m_bnCoinRequest); }
    /*const*/ BIGNUM *Request()
	{ return m_bnCoinRequest; }
    void WriteBIO(BIO *bio);
    void ReadBIO(BIO *bio);

    void Dump()
	{ DumpNumber("request=  ",m_bnCoinRequest); }
    };

class CoinRequest : public PublicCoinRequest
    {
    BIGNUM *m_bnBlindingFactor;
    UnsignedCoin m_coin;
    BN_CTX *m_ctx;

    void CheckCTX()
	{
	if(m_ctx)
	    return;
	m_ctx=BN_CTX_new();
	}
public:
    CoinRequest(BIO *bio)
	{
	m_ctx=NULL;
	ReadBIO(bio);
	}
    CoinRequest(PublicBank &bank)
	{
	m_ctx=NULL;

	BIGNUM *y=BN_new();
	for( ; ; )
	    {
	    m_coin.Random(bank.CoinLength());

	    m_coin.GenerateCoinNumber(y,bank);

	    if(BN_cmp(y,bank.p()) < 0)
		break;
	    }

	// choose b
	m_bnBlindingFactor=BN_new();
	BN_rand(m_bnBlindingFactor,BLINDING_LENGTH*8,0,0);
	DumpNumber("b=        ",m_bnBlindingFactor);

	// calculate A->B: y g^b
	m_bnCoinRequest=BN_new();
	CheckCTX();

	BN_mod_exp(m_bnCoinRequest,bank.g(),m_bnBlindingFactor,bank.p(),m_ctx);
	BN_mod_mul(m_bnCoinRequest,m_bnCoinRequest,y,bank.p(),m_ctx);
	DumpNumber("A->B=     ",m_bnCoinRequest);

	BN_free(y);
	}
    ~CoinRequest()
	{
	BN_free(m_bnBlindingFactor);
	BN_CTX_free(m_ctx);
	}
    BIGNUM *Unblind(BIGNUM *bnSignedCoin,PublicBank &bank)
	{
	CheckCTX();
	BIGNUM *z=BN_new();
	BN_mod_exp(z,bank.pub_key(),m_bnBlindingFactor,bank.p(),m_ctx);
	BN_mod_inverse(z,z,bank.p(),m_ctx);
	BN_mod_mul(z,bnSignedCoin,z,bank.p(),m_ctx);
	return z;
	}
    void ProcessResponse(Coin *pCoin,PublicBank &bank,
			 BIGNUM *bnSignedCoinRequest)
	{
	BIGNUM *bnCoinSignature=Unblind(bnSignedCoinRequest,bank);
	DumpNumber("z=        ",bnCoinSignature);
	pCoin->Set(m_coin,bnCoinSignature);
	}
    void WriteBIO(BIO *bio);
    void ReadBIO(BIO *bio);

    void Dump()
	{
	PublicCoinRequest::Dump();
	m_coin.Dump();
	DumpNumber("blinding= ",m_bnBlindingFactor);
	}
    };

#endif // __LUCRE_WRAPPER__