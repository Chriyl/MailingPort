#include "../include/socket_MAN.hh"
#include <stdio.h>
#include <winsock2.h>
#include <vector>
#include <string>
#include <filesystem>
#pragma comment(lib, "ws2_32.lib")

#define PORT 22222

int main()
{
    WSADATA wsa;
    sockaddr_in server_addr, client_addr;
    SOCKETMAN::write_sockaddr(&server_addr, (short int)PORT);

    if (!SOCKETMAN::init_wsa(&wsa)) {
        printf("[-] Errore con WSA\n");
        return -1;
    }

    SOCKET sock = SOCKETMAN::init_sock();
    if (sock == INVALID_SOCKET) {
        return -1;
    }

    

    if (!SOCKETMAN::bind_server(sock, &server_addr, sizeof(server_addr))) {
        closesocket(sock);
        WSACleanup();
        return -1;
    }

    if(!SOCKETMAN::server_listen(sock, 10)){
        printf("[+] failed to listen on : %d\n", PORT);
    }
    printf("[+] Server in ascolto sulla porta %d\n", PORT);

    if(!SOCKETMAN::server_accept(sock, &client_addr)){
        printf("Connessione non accettata");
        return -1;
    }
        
  
   // CHIUSURA SOCK
    
    closesocket(sock);
    WSACleanup();
    
    return 0;
}