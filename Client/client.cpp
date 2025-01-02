#include <iostream>
#include "../_HeaderFiles/socket_MAN.hh"
#pragma comment (lib, "Ws2_32.lib")
#pragma comment (lib, "Mswsock.lib")
#pragma comment (lib, "AdvApi32.lib")

#define PORT 8080


int main()
{

    WSADATA wsa;
    struct addrinfo *result = NULL, *ptr = NULL, hints;

    if (!SOCKETMAN::init_wsa(&wsa)) {
        printf("[-] Errore con WSA\n");
        return -1;
    }

    SOCKET sock = SOCKETMAN::init_sock();
    if (sock == INVALID_SOCKET) {
        return -1;
    }

    sockaddr_in server_addr;
    SOCKETMAN::write_addrinfo(&hints, (short int)PORT);

    return 0;
}