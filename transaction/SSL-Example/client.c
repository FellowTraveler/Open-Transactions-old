#include <netinet/in.h>
#include <string.h>
#include <stdio.h>

#include "SFSocket.h"

#define CA_FILE             "SSL-Example/ca.crt"
#define KEY_FILE            "SSL-Example/client.crt"
#define KEY_PASSWORD        "test"

#define HOSTNAME        "localhost"
#define PORT            7085

int main (int argc, char **argv) {
    char buffer[1024];
    SFSocket *socket;
    int rdSize;

    /* Initialize SSL */
    SFSocketGlobalInit();

    /* Alloc Socket */
    if ((socket = SFSocketAlloc()) == NULL) {
        printf("Alloc Failed\n");
        return(1);
    }

    /* Initialize SSL Socket */
    if (SFSocketInit(socket, CA_FILE, NULL, KEY_FILE, KEY_PASSWORD, NULL) < 0) {
        printf("Init Failed\n");
        return(2);
    }

    /* Connect to Host */
    if (SFSocketConnectToHost(socket, HOSTNAME, PORT) < 0) {
        printf("Connect to Host Failed\n");
        return(3);
    }

    /* Send Message to Server */
    strcpy(buffer, "Hello from Client!");
    SFSocketWrite(socket, buffer, strlen(buffer));

    /* Read Message from Server */
    if ((rdSize = SFSocketRead(socket, buffer, 1024 - 1)) > 0) {
        buffer[rdSize] = '\0';
        printf("Server: %s\n", buffer);
    }

    /* Close and Release Socket Resources */
    SFSocketRelease(socket);

    return(0);
}

