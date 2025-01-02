#include "socket_MAN.hh"


bool SOCKETMAN::init_wsa(WSADATA* wsa)
{
    if (WSAStartup(MAKEWORD(2, 2), wsa) != 0)
    {
        printf("[-] ERRORE: WSAStartup fallito\n");
        return false;
    }

    return true;
}

SOCKET SOCKETMAN::init_sock()
{
    SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock == INVALID_SOCKET) {
        WSACleanup();
        printf("[-] ERRORE NELLA CREAZIONE DEL SOCKET\n");
        return INVALID_SOCKET;
    }

    return sock;
}

void SOCKETMAN::write_sockaddr(struct sockaddr_in* dest_sockaddr, short int port)
{
    dest_sockaddr->sin_addr.s_addr = INADDR_ANY;
    dest_sockaddr->sin_family = AF_INET;
    dest_sockaddr->sin_port = htons(port);
}

bool SOCKETMAN::bind_server(SOCKET sock, struct sockaddr_in* addr, int size)
{
    int bindValue = bind(sock, (struct sockaddr*) addr, size);

    if (bindValue == SOCKET_ERROR) {
        printf("[-] Bind non riuscito. Errore: %d\n", WSAGetLastError());
        return false;
    }

    printf("[+] Bind riuscito\n");
    return true;
}

