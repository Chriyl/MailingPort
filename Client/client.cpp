#include <iostream>
#include "../_HeaderFiles/socket_MAN.hh"

#define PORT 8080

int main()
{

    WSADATA wsa;

    if (!SOCKETMAN::init_wsa(&wsa)) {
        printf("[-] Errore con WSA\n");
        return -1;
    }

    SOCKET sock = SOCKETMAN::init_sock();
    if (sock == INVALID_SOCKET) {
        return -1;
    }

    sockaddr_in server_addr;
    SOCKETMAN::write_sockaddr(&server_addr, (short int)PORT);
}