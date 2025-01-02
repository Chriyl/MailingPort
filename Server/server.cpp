#include "../_HeaderFiles/socket_MAN.hh"
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

    if (!init_wsa(&wsa)) {
        printf("[-] Errore con WSA\n");
        return -1;
    }

    SOCKET sock = init_sock();
    if (sock == INVALID_SOCKET) {
        return -1;
    }

    sockaddr_in server_addr;
    write_sockaddr(&server_addr, (short int)PORT);

    if (!bind_server(sock, &server_addr, sizeof(server_addr))) {
        closesocket(sock);
        WSACleanup();
        return -1;
    }

    printf("[+] Server in ascolto sulla porta %d\n", PORT);
    
    // Continuare con la logica del server, come l'ascolto e l'accettazione delle connessioni

    // Chiusura del socket quando finito
    closesocket(sock);
    WSACleanup();
    
    return 0;
}