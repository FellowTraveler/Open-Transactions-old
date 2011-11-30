#include "bank.h"

#ifdef _WIN32
#include <cstring>
#endif

extern "C"
{
#include <openssl/asn1.h>
}

static BIO *dout;
static BIO *mout;

const char _NL[]="\n";

void SetDumper(BIO *out)
    {
    dout=out;
    if(!mout)
	mout=out;
    }

void SetDumper(FILE *f)
    {
    BIO *out=BIO_new(BIO_s_file());
    assert(out);
    BIO_set_fp(out,f,BIO_NOCLOSE);
    SetDumper(out);
    }

void SetMonitor(BIO *out)
    { mout=out; }

void SetMonitor(FILE *f)
    {
    BIO *out=BIO_new(BIO_s_file());
    assert(out);
    BIO_set_fp(out,f,BIO_NOCLOSE);
    SetMonitor(out);
    }

BIGNUM *ReadNumber(BIO *in,const char *szTitle)
    {
    char szLine[10240];
    unsigned char aucBN[1024];
    int nTLen=strlen(szTitle);

    BIO_gets(in,szLine,sizeof szLine-1);
    if(strncmp(szLine,szTitle,nTLen))
	{
#ifndef ANDROID
	fprintf(stderr,"Got %s, expected %s\n",szLine,szTitle);
#endif
	assert(!"Unexpected input");  // TODO Find out what this exclamation point is for...
	return NULL;
	}
    BIGNUM *bn=BN_new();

    int n=strcspn(szLine+nTLen,"\r\n");
    szLine[nTLen+n]='\0';
    if(n&1)
	{
	memmove(szLine+nTLen+1,szLine+nTLen,n+1);
	szLine[nTLen]='0';
	}

    for(n=0 ; szLine[nTLen+n*2] ; ++n)
	{
	int h;

	sscanf(&szLine[nTLen+n*2],"%02x",&h);
	aucBN[n]=(unsigned char)h;
	}
	
    BN_bin2bn(aucBN,n,bn);

    return bn;
    }

void DumpNumber(BIO *out,const char *szTitle,const BIGNUM *bn,
		const char *szTrailer)
    {
    if(!out)
	return;
    BIO_puts(out,szTitle);
    if(!bn)
	BIO_puts(out,"(null)");
    else
	BN_print(out,bn);
    BIO_puts(out,szTrailer);
    }

void DumpNumber(const char *szTitle,const BIGNUM *bn,const char *szTrailer)
    { DumpNumber(dout,szTitle,bn,szTrailer); }

void HexDump(BIO *out,const char *szTitle,const unsigned char *acBuf,
	     int nLength)
    {
    if(!out)
	return;
    BIO_puts(out,szTitle);
    for(int n=0 ; n < nLength ; ++n)
	{
	char buf[3];
	sprintf(buf,"%02X",acBuf[n]);
	BIO_puts(out,buf);
	}
    BIO_puts(out,"\n");
    }

void HexDump(const char *szTitle,const unsigned char *acBuf,int nLength)
    { HexDump(dout,szTitle,acBuf,nLength); }

PublicBank::PublicBank(Bank &bank)
    {
    m_pDH=DH_new();
    m_pDH->g=BN_dup(bank.g());
    m_pDH->p=BN_dup(bank.p());
    m_pDH->pub_key=BN_dup(bank.pub_key());
    }

void Bank::cb(int n, int, void * /*arg*/)
    {
    if(!mout)
	return;

    char c='*';

    if (n == 0) c='.';
    if (n == 1) c='+';
    if (n == 2) c='*';
    if (n == 3) c='\n';
    BIO_write(mout,&c,1);
    BIO_flush(mout);
    }

/*const*/ BIGNUM *Bank::SignRequest(PublicCoinRequest &req)
    {
    InitCTX();

    BIGNUM *BtoA=BN_new();
    BN_mod_exp(BtoA,req.Request(),priv_key(),p(),m_ctx);
    DumpNumber("B->A=     ",BtoA);

    return BtoA;
    }

LAURIE_BOOLEAN Bank::Verify(Coin &coin)
    {
    InitCTX();

    BIGNUM *t=BN_new();
    if(!coin.GenerateCoinNumber(t,*this))
	return false;
    BN_mod_exp(t,t,priv_key(),p(),m_ctx);
    DumpNumber("y^k=      ",t);

    BN_sub(t,t,coin.Signature());
    LAURIE_BOOLEAN bRet=BN_is_zero(t);

    BN_free(t);

    return bRet;
    }

void Bank::WriteBIO(BIO *bio)
    {
    PublicBank::WriteBIO(bio);
    DumpNumber(bio,"private=",priv_key());
    }

void Bank::ReadBIO(BIO *bio)
    {
    PublicBank::ReadBIO(bio);
    m_pDH->priv_key=ReadNumber(bio,"private=");
    }

void PublicBank::WriteBIO(BIO *bio)
    {
    DumpNumber(bio,"g=",g());
    DumpNumber(bio,"p=",p());
    DumpNumber(bio,"public=",pub_key());
    }

void PublicBank::ReadBIO(BIO *bio)
    {
    m_pDH=DH_new();

    m_pDH->g=ReadNumber(bio,"g=");
    m_pDH->p=ReadNumber(bio,"p=");
    m_pDH->pub_key=ReadNumber(bio,"public=");

    Dump();
    }

void UnsignedCoin::WriteBIO(BIO *bio)
    {
    DumpNumber(bio,"id=",m_bnCoinID);
    }

void UnsignedCoin::ReadBIO(BIO *bio)
    {
    m_bnCoinID=ReadNumber(bio,"id=");
    }

void Coin::WriteBIO(BIO *bio)
    {
    UnsignedCoin::WriteBIO(bio);
    DumpNumber(bio,"signature=",m_bnCoinSignature);
    }

void Coin::ReadBIO(BIO *bio)
    {
    UnsignedCoin::ReadBIO(bio);
    m_bnCoinSignature=ReadNumber(bio,"signature=");
    Dump();
    }

void PublicCoinRequest::WriteBIO(BIO *bio)
    {
    DumpNumber(bio,"request=",m_bnCoinRequest);
    }

void PublicCoinRequest::ReadBIO(BIO *bio)
    {
    m_bnCoinRequest=ReadNumber(bio,"request=");
    }

void CoinRequest::WriteBIO(BIO *bio)
    {
    PublicCoinRequest::WriteBIO(bio);
    m_coin.WriteBIO(bio);
    DumpNumber(bio,"blinding=",m_bnBlindingFactor);
    }

void CoinRequest::ReadBIO(BIO *bio)
    {
    PublicCoinRequest::ReadBIO(bio);
    m_coin.ReadBIO(bio);
    m_bnBlindingFactor=ReadNumber(bio,"blinding=");

    Dump();
    }

