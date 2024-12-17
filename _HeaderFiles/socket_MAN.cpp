#include "socket_MAN.hh"

bool init_wsa(WSADATA* wsa)
{
    if (WSAStartup(MAKEWORD(2, 2), wsa) != 0)
    {
        printf("[-] ERRORE: WSAStartup fallito\n");
        return false;
    }

    return true;
}

SOCKET init_sock()
{
    SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock == INVALID_SOCKET) {
        WSACleanup();
        printf("[-] ERRORE NELLA CREAZIONE\n");
        return -1;
    }

    return sock;
}

void write_sockaddr(struct sockaddr_in* dest_sockaddr, short int port)
{
    dest_sockaddr->sin_addr.s_addr = INADDR_ANY;
    dest_sockaddr->sin_family = AF_INET;
    dest_sockaddr->sin_port = htons(port);
}