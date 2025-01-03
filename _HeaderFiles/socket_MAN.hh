#ifndef SOCKETMAN_HH
#define SOCKETMAN_HH

#include <iostream>
#include <WinSock2.h>
using namespace std;



static class SOCKETMAN {
    
    public:
    static SOCKET init_sock();
    static bool init_wsa(WSADATA*);
    static void write_sockaddr(struct sockaddr_in*, short int );
    static void write_sockaddr_client(short int, const char*, sockaddr_in*);
    static bool bind_server(SOCKET, struct sockaddr_in*, int);
    static bool connect_client(SOCKET, struct sockaddr_in*, int);
    static bool server_listen(SOCKET, int);
    static bool server_accept(SOCKET, sockaddr_in* );
};


#endif // SOCKETMAN_HH