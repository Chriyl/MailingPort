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
    static bool bind_server(SOCKET, struct sockaddr_in*, int);
};


#endif // SOCKETMAN_HH