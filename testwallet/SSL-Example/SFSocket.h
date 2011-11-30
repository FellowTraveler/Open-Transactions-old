
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


#ifndef _SFSOCKET_H_
#define _SFSOCKET_H_

typedef struct _SFSocket SFSocket;

void        SFSocketGlobalInit  (void);

SFSocket *  SFSocketAlloc       (void);
void        SFSocketRelease     (SFSocket *socket);

int         SFSocketInit         (SFSocket *socket,
                                  const char *caFile,
                                  const char *dhFile,
                                  const char *keyFile, 
                                  const char *password,
                                  const char *chipers);

int         SFSocketListen          (SFSocket *serverSocket, 
                                     unsigned int address, 
                                     int port);
SFSocket *  SFSocketAccept          (SFSocket *socket);

int         SFSocketConnectToHost   (SFSocket *socket, 
                                     const char *host, 
                                     int port);

int     SFSocketRead    (SFSocket *socket, void *buf, int len);
int     SFSocketWrite   (SFSocket *socket, const void *buf, int len);

#endif /* !_SFSOCKET_H_ */

