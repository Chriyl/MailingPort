#include <iostream>
#include <winsock2.h>
#include <ws2tcpip.h>
#include "../_HeaderFiles/socket_MAN.hh"
#pragma comment (lib, "Ws2_32.lib")
#pragma comment (lib, "Mswsock.lib")
#pragma comment (lib, "AdvApi32.lib")

#define PORT 8080



int main(int argv, char** args)
{
    int server_port = atoi(args[2]);
    server_port = htons(server_port);


    WSADATA wsa;
    struct sockaddr_in server_addr;

    if (!SOCKETMAN::init_wsa(&wsa)) {
        printf("[-] Errore con WSA\n");
        return -1;
    }

    SOCKET sock = SOCKETMAN::init_sock();
    if (sock == INVALID_SOCKET) {
        printf("[-] Errore con init sock\n");
        return -1;
    }

   SOCKETMAN::write_sockaddr_client(server_port, args[1], &server_addr);

    
    if(SOCKETMAN::connect_client(sock, &server_addr, sizeof(server_addr))){
        printf("[+] Connessione riuscita al server %s:%s\n", args[1], args[2]);
    }else{
        printf("[-] Failed to connect");
        return -1;
    }
    

  
    const char* msg = "Ciao, server!";
    send(sock, msg, strlen(msg), 0);

   
    closesocket(sock);
    //freeaddrinfo(result);
    WSACleanup();

    

    return 0;
}