/*
*
* hcportscan.h - contains the port_scan() function
* The Hconsole Project is made by Copy05
*
* (c) Copy05 2020-2023
* ~~~~~~~~~~~~~[ Author ]~~~~~~~~~~~~~~~~~~~~~~
*   Copy05 [https://github.com/Copy05/]
*/

#include "hcportscan.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#if __unix
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#endif

#if __unix
void port_scan(const char* url, int port){
    int socket_desc, connection_status;
    struct sockaddr_in server;

    // Create socket
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_desc == -1) {
        printf("Could not create socket.\n");
        return;
    }

    server.sin_addr.s_addr = inet_addr(ip_address);
    server.sin_family = AF_INET;
    server.sin_port = htons(port);

    connection_status = connect(socket_desc, (struct sockaddr *)&server, sizeof(server));
    if (connection_status == -1) {
        if (errno == ETIMEDOUT) {
            printf("Error: Connection timed out.\n");
        } else {
            printf("Port %d is closed.\n", port);
        }
    } else {
        printf("Port %d is open.\n", port);
        close(socket_desc);
    }
}
#else
void port_scan(const char* url, int port){
    printf("This is a UNIX only feature.")
}
#endif