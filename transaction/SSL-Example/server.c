#include <netinet/in.h>
#include <string.h>
#include <stdio.h>

#include "SFSocket.h"

#define CA_FILE             "SSL-Example/ca.crt"
#define DH_FILE             "SSL-Example/dh_param_1024.pem"
#define KEY_FILE            "SSL-Example/server.crt"
#define KEY_PASSWORD        "test"

#define PORT                7085

int main (int argc, char **argv) {
    SFSocket *socket;

    /* Initialize SSL */
    SFSocketGlobalInit();

    /* Alloc Socket */
    if ((socket = SFSocketAlloc()) == NULL) {
        printf("Alloc Failed\n");
        return(1);
    }

    /* Initialize SSL Socket */
    if (SFSocketInit(socket, CA_FILE, DH_FILE, KEY_FILE, KEY_PASSWORD, NULL) < 0)
    {
        printf("Init Context Failed\n");
        return(2);
    }

    /* Listen on Address/Port */
    if (SFSocketListen(socket, INADDR_ANY, PORT) < 0) {
        printf("Listen Failed\n");
        return(3);
    }

    do {
        SFSocket *clientSocket;
        char buffer[1024];
        int rdSize;

        /* Accept Client Connection */
        if ((clientSocket = SFSocketAccept(socket)) == NULL)
            break;        

        /* Read Data from Client */
        if ((rdSize = SFSocketRead(clientSocket, buffer, 1024 - 1)) > 0) {
            buffer[rdSize] = '\0';
            printf("Client: %s\n", buffer);
        }

        /* Write to Client */
        strcpy(buffer, "Hello Client!");
        SFSocketWrite(clientSocket, buffer, strlen(buffer));

        /* Disconnect Client */
        SFSocketRelease(clientSocket);        
    } while (1);

    /* Close and Release Socket Resources */
    SFSocketRelease(socket);

    return(0);
}

