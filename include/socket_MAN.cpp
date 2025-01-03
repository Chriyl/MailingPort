#include "socket_MAN.hh"
#include <string>
using namespace std;

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

void SOCKETMAN::write_sockaddr_client(short int port, const char* ip, sockaddr_in* dest_addr)
{
    /*
    
    dest_addrinfo->ai_family = AF_UNSPEC;
    dest_addrinfo->ai_socktype = SOCK_STREAM;
    dest_addrinfo->ai_protocol = IPPROTO_TCP;
    */
   
   dest_addr->sin_family = AF_INET;
   dest_addr->sin_port = port;
   dest_addr->sin_addr.s_addr = inet_addr(ip);
    
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

bool SOCKETMAN::connect_client(SOCKET sock, struct sockaddr_in* src_sockaddr, int size) {
    int result = connect(sock, (struct sockaddr*)src_sockaddr, size); // Passa il puntatore diretto
    if (result == SOCKET_ERROR) {
        printf("[-] Errore in connect: %d\n", WSAGetLastError());
        return false;
    }

    printf("[+] Connessione riuscita\n");
    return true;
}


bool SOCKETMAN::server_listen(SOCKET sock, int connections){
    int result = listen(sock, connections);
    if(result == SOCKET_ERROR) {return false;} else {return true;}
}

bool SOCKETMAN::server_accept(SOCKET sock, sockaddr_in* addr) {
    int size = sizeof(sockaddr_in); // Dimensione corretta della struttura
    SOCKET client_sock = accept(sock, (struct sockaddr*)addr, &size); // Passa il puntatore corretto e la dimensione
    if (client_sock == INVALID_SOCKET) {
        printf("[-] Errore in accept: %d\n", WSAGetLastError());
        return false;
    }

    // Se necessario, puoi salvare o gestire il socket del client connesso
    printf("[+] Connessione accettata\n");
    return true;
}


