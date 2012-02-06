
/*     (SSL Sockets)
 *
 *       SFSocket       --- Copyright (C) 2009 Matteo Bertozzi
 *                          Used with permission in OpenTransactions
 *                          http://th30z.netsons.org/
 *
 *                          Useful as a tool for learning SSL sockets. Good work.
 *
 *                          (Also new software, but fine for this test release.)
 */

#ifdef _WIN32
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <io.h>
#include <winsock2.h>

typedef int socklen_t;

#define strcasecmp _stricmp

#else
#include <sys/types.h>
#include <netinet/tcp.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
#include <netdb.h>
#endif

#include <openssl/err.h>
#include <openssl/ssl.h>

#include "SFSocket.h"

#define SFSocketSSL(socket)                     ((socket)->sslSock)
#define SFSocketSetSSL(socket, ssl)             (socket)->sslSock = (ssl)

#define SFSocketBIO(socket)                     ((socket)->bio)
#define SFSocketSetBIO(socket, sslBio)          (socket)->bio = (sslBio);

#define SFSocketContext(socket)                 ((socket)->ctx)
#define SFSocketSetContext(socket, context)     (socket)->ctx = (context)

#define SFSocketDescriptor(socket)              ((socket)->sock)
#define SFSocketSetDescriptor(socket, fd)       (socket)->sock = (fd)

#ifdef _WIN32
#define SFSocketClearDescriptor(socket)         (socket)->sock = (INVALID_SOCKET)
#else
#define SFSocketClearDescriptor(socket)         (socket)->sock = (-1)
#endif

#define SFSocketAddress(socket)                 (&(socket)->address)

struct _SFSocket {
    struct sockaddr_in address;
    SSL_CTX *ctx;
    SSL *sslSock;
    BIO *bio;
    int sock;
};

static int __SFSocketSetPasswordCallback (char *buf, int size, 
                                          int rwflag, void *password)
{
	fprintf(stderr, "\n\n\n\n\n\n\n __SFSocketSetPasswordCallback: THIS SHOULD NEVER HAPPEN!!!!!!!!!\n\n\n\n\n");

#ifdef _WIN32
    strncpy_s(buf, size, (char *)password, size);
#else
    strncpy(buf, (char *)password, size);
#endif

    buf[size - 1] = '\0';
    return(strlen(buf));
}

static int __SFSocketLoadDHParams (SFSocket *socket, const char *dhFile) {
    BIO *bio = NULL;
    DH *dh = NULL;

#ifdef _WIN32
//    if ((bio = BIO_new_file(dhFile, "r")) == NULL)
    if (NULL == (bio = BIO_new_file(dhFile, "rb"))) // _WIN32
#else
	if (NULL == (bio = BIO_new_file(dhFile, "r")))
#endif
		return(-1);

    if ((dh = PEM_read_bio_DHparams(bio, NULL, NULL, NULL)) == NULL) {
        BIO_free(bio);
		bio = NULL;
        return(-2);
    }

    BIO_free(bio);
	bio = NULL;
    if (SSL_CTX_set_tmp_dh(SFSocketContext(socket), dh) < 0)
        return(-3);

    DH_free(dh);
	dh = NULL;
	
    return(0);
}

static int __SFSocketCheckCert (SFSocket *socket, const char *host) {
    char peerCN[384] = ""; // really 256 but I made it bigger for safety.
    X509 *peer = NULL;

    if (SSL_get_verify_result(SFSocketSSL(socket)) != X509_V_OK)
        return(-1);

    if ((peer = SSL_get_peer_certificate(SFSocketSSL(socket))) == NULL)
        return(-2);

    X509_NAME_get_text_by_NID(X509_get_subject_name(peer), 
                              NID_commonName, peerCN, 256);
    X509_free(peer);
	peer = NULL;

    return(strcasecmp(peerCN, host) ? - 3 : 0);
}

static char __globalInit = 0;

void SFSocketGlobalInit (void) {
    if (!__globalInit) {
        __globalInit = 1;

#ifdef _WIN32
		CRYPTO_malloc_init();
#endif
        SSL_library_init();
        SSL_load_error_strings();
    }
}

SFSocket *SFSocketAlloc (void) {
    SFSocket *socket = NULL;

	fprintf(stderr, "\n\n\n\n\n\n\n SFSocketAlloc: THIS SHOULD NEVER HAPPEN!!!!!!!!!\n\n\n\n\n");

    if (NULL == (socket = (SFSocket *) malloc (sizeof(SFSocket))))
        return(NULL);

    socket->ctx = NULL;
    socket->sslSock = NULL;
    socket->sock = -1;
    memset(&(socket->address), 0, sizeof(struct sockaddr_in));

    return(socket);
}

void SFSocketRelease (SFSocket *socket) {
    if (socket->ctx != NULL) {
        SSL_CTX_free(socket->ctx);
        socket->ctx = NULL;
    }

    if (socket->sslSock != NULL) {
        SSL_shutdown(socket->sslSock);
        SSL_free(socket->sslSock);
        socket->sslSock = NULL;
    }

#ifdef _WIN32
    if (socket->sock != INVALID_SOCKET) {
        closesocket(socket->sock);
        socket->sock = INVALID_SOCKET;
    }
#else
    if (socket->sock != -1) {
        close(socket->sock);
        socket->sock = -1;
    }
#endif

    free(socket);
	socket = NULL;
}

int SFSocketInit (SFSocket *socket,
                  const char *caFile,
                  const char *dhFile,
                  const char *keyFile, 
                  const char *password,
                  const char *chipers)
{
    SSL_CTX *ctx = NULL;

	fprintf(stderr, "\n\n\n\n\n\n\n SFSocketInit: THIS SHOULD NEVER HAPPEN!!!!!!!!!\n\n\n\n\n");

    /* Create Context */
    if (NULL == (ctx = SSL_CTX_new(SSLv3_method()))) {
        ERR_print_errors_fp(stderr);
        return(-1);
    }

    /* Load Key and Certificate */
    if (!SSL_CTX_use_certificate_chain_file(ctx, keyFile)) {
        ERR_print_errors_fp(stderr);
        return(-2);
    }

    SSL_CTX_set_default_passwd_cb(ctx, __SFSocketSetPasswordCallback);
    SSL_CTX_set_default_passwd_cb_userdata(ctx, (void *)password);
    if (!SSL_CTX_use_PrivateKey_file(ctx, keyFile, SSL_FILETYPE_PEM)) {
        ERR_print_errors_fp(stderr);
        SSL_CTX_free(ctx);
        return(-3);
    }

    /* Load the CAs we Trust */
    if (!SSL_CTX_load_verify_locations(ctx, caFile, NULL)) {
        SSL_CTX_free(ctx);
        return(-4);
    }

#if (OPENSSL_VERSION_NUMBER < 0x00905100L)
    SSL_CTX_set_verify_depth(ctx, 1);
#endif

    /* Set Context on Socket */
    SFSocketSetContext(socket, ctx);

    /* Load DH Params */
    if (dhFile != NULL)
        __SFSocketLoadDHParams(socket, dhFile);

    /* Set Chipers */
    if (chipers != NULL)
        SSL_CTX_set_cipher_list(ctx, chipers);

    return(0);
}

int SFSocketListen (SFSocket *serverSocket, unsigned int address, int port) {
    struct sockaddr_in *saddr = NULL;
    SSL_CTX *ctx = NULL;
    int sock = 0;

    /* Require Authentication */
    if (NULL != (ctx = SFSocketContext(serverSocket))) {
        SSL_CTX_set_verify(ctx, SSL_VERIFY_PEER | 
                                SSL_VERIFY_FAIL_IF_NO_PEER_CERT, 0);
    }

    if (0 > (sock = socket(AF_INET, SOCK_STREAM, 0)))
        return(-1);

    /* Setup Socket Address */
    saddr = SFSocketAddress(serverSocket);
    memset(saddr, 0, sizeof(struct sockaddr_in));
    saddr->sin_addr.s_addr = address;
    saddr->sin_family = AF_INET;
    saddr->sin_port = htons(port);

    /* Bind */
    if (bind(sock, (struct sockaddr *)saddr, sizeof(struct sockaddr_in)) < 0) {
        close(sock);
        return(-2);
    }

    /* Listen */
    listen(sock, 15);

    /* Set Socket Descriptor */
    SFSocketSetDescriptor(serverSocket, sock);

    return(0);
}

SFSocket *SFSocketAccept (SFSocket *socket) {
    struct sockaddr_in *addr = NULL;
    SFSocket *clientSocket = NULL;
    socklen_t addrlen = 0;
    SSL_CTX *ctx = NULL;
    int sock = 0;

    /* Alloc new Client Socket */
    if (NULL == (clientSocket = SFSocketAlloc()))
        return(clientSocket);

    /* Accept Connection */
    addr = SFSocketAddress(clientSocket);
    if ((sock = accept(SFSocketDescriptor(socket), 
                       (struct sockaddr *)addr, &addrlen)) <= 0)
    {
        SFSocketRelease(clientSocket);
        return(NULL);
    }

    /* Set Client Socket Descriptor */
    SFSocketSetDescriptor(clientSocket, sock);

    /* Setup Client SSL */
    if (NULL != (ctx = SFSocketContext(socket))) {
        BIO *bio = NULL;
        SSL *ssl = NULL;

        if ((bio = BIO_new_socket(sock, BIO_NOCLOSE)) == NULL) {
            ERR_print_errors_fp(stderr);
            SFSocketRelease(clientSocket);
            return(NULL);
        }

        if (NULL == (ssl = SSL_new(ctx))) {
            ERR_print_errors_fp(stderr);
            BIO_free(bio); bio  = NULL;
            SFSocketRelease(clientSocket); clientSocket = NULL;
            return(NULL);
        }

        /* SSL Accept */
        SSL_set_bio(ssl, bio, bio);
        if (SSL_accept(ssl) <= 0) {
            ERR_print_errors_fp(stderr);
            SSL_free(ssl); ssl = NULL;
            SFSocketRelease(clientSocket); clientSocket = NULL;
            return(NULL);
        }

        /* Set SSL Socket */
        SFSocketSetSSL(clientSocket, ssl);
        SFSocketSetBIO(clientSocket, bio);
    }

    return(clientSocket);
}

int SFSocketConnectToHost (SFSocket *clientSocket, const char *host, int port) {
    struct sockaddr_in *addr = NULL;
    struct hostent *hp = NULL;
    SSL_CTX *ctx = NULL;
    int sock = 0;

    if ((hp = gethostbyname(host)) == NULL)
        return(-1);

    /* Setup Address */
    addr = SFSocketAddress(clientSocket);
    memset(addr, 0, sizeof(struct sockaddr_in));
    addr->sin_addr = *((struct in_addr *)hp->h_addr_list[0]);
    addr->sin_family = AF_INET;
    addr->sin_port = htons(port);

#ifdef _WIN32
    if ( INVALID_SOCKET == (sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) )
#else
	if (0 > (sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)))
#endif
		return(-2);

    /* Connect to Host */
#ifdef _WIN32
	if (SOCKET_ERROR == connect(sock, (struct sockaddr *)addr, sizeof(struct sockaddr_in)) )
#else
	if (0 > connect(sock, (struct sockaddr *)addr, sizeof(struct sockaddr_in)))
#endif
	{
#ifdef _WIN32
		errno_t theError = WSAGetLastError();
        closesocket(sock);
#else
		close(sock);
#endif
		sock = 0;
		return(-3);
    }

    /* Set Socket Descriptor */
    SFSocketSetDescriptor(clientSocket, sock);
    
    if (NULL != (ctx = SFSocketContext(clientSocket))) {
        BIO *bio = NULL;
        SSL *ssl = NULL;

        /* Setup SSL */
        if (NULL == (ssl = SSL_new(ctx))) {
            ERR_print_errors_fp(stderr);
            SFSocketClearDescriptor(clientSocket);
#ifdef _WIN32
            closesocket(sock);
#else
			close(sock);
#endif
			sock = 0;
            return(-4);
        }

        /* Setup BIO */
        if ((bio = BIO_new_socket(sock, BIO_NOCLOSE)) == NULL) {
            SFSocketClearDescriptor(clientSocket);
            SSL_free(ssl);
#ifdef _WIN32
            closesocket(sock);
#else
			close(sock);
#endif
			sock = 0;
			return(-5);
        }

        /* SSL Connect */
        SSL_set_bio(ssl, bio, bio);
        if (0 >= SSL_connect(ssl)) {
            ERR_print_errors_fp(stderr);
            return(-6);
        }

        /* Setup SSL/BIO on Socket */
        SFSocketSetSSL(clientSocket, ssl);
        SFSocketSetBIO(clientSocket, bio);

		//TODO Figure out why Certs weren't working.
		// TODO get certs working.
		// TODO otherwise at least figure out how to call this without a cert
        /* Check Certificate */
//        if (__SFSocketCheckCert(clientSocket, host) < 0)
//            return(-7);
    }

    return(0);
}

int SFSocketRead (SFSocket *socket, void *buf, int len) 
{
	SSL *ssl = NULL;
	
	fd_set read_flags, write_flags;	// the flag sets to be used
	struct timeval waitd;			// the max wait time for an event
	int stat = 0;					// holds return value for select();
	
	waitd.tv_sec = 0;		// Make select wait up to 1 second for data
	waitd.tv_usec = 100;	// and 0 milliseconds.
	
	// (FellowTraveler) I'm trying to make this work asynchronously.
	
	
	FD_ZERO(&read_flags); // Zero the flags ready for using
	FD_ZERO(&write_flags); // Zero the flags ready for using
	
	// Set the sockets read flag, so when select is called it examines
	// the read status of available data.
	FD_SET(SFSocketDescriptor(socket), &read_flags);
	
	// Now call select
	stat=select(SFSocketDescriptor(socket)+1, &read_flags,&write_flags,(fd_set*)0,&waitd);
	
#ifdef _WIN32
	if (SOCKET_ERROR == stat)
	{
		fprintf(stderr, "Error during select()\n");
	}
	else if (0 == stat)
	{
		// This means the timeout occurred and there were no new connections
		// (Which is normal, don't want to log every single time that happens.)
	}
	else
#endif
	if (FD_ISSET(SFSocketDescriptor(socket), &read_flags)) 
	{
		FD_CLR(SFSocketDescriptor(socket), &read_flags);
		
		// here is where you use the read().
		// If read returns an error then the socket
		// must be dead so you must close it.
		
		// (FellowTraveler) trying to make asynchronous sockets work...
		if (NULL != (ssl = SFSocketSSL(socket)))
		{
			//		if (SSL_pending(ssl))	
			return(SSL_read(ssl, buf, len));
			//		else {
			//			return 0;
			//		}
		}
		
#ifdef _WIN32
		return(recv(SFSocketDescriptor(socket), buf, len, 0));
#else
		return(read(SFSocketDescriptor(socket), buf, len));
#endif
	}
	
	
	return 0;
}

int SFSocketWrite (SFSocket *socket, const void *buf, int len) {
    SSL *ssl = NULL;
    if (NULL != (ssl = SFSocketSSL(socket)))
        return(SSL_write(ssl, buf, len));

#ifdef _WIN32
    return(send(SFSocketDescriptor(socket), buf, len, 0));
#else
	return(write(SFSocketDescriptor(socket), buf, len));
#endif
}

