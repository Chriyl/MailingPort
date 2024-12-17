#ifndef SOCKETMAN_HH
#define SOCKETMAN_HH

#include <iostream>
#include <WinSock2.h>
using namespace std;

SOCKET init_sock();
bool init_wsa(WSADATA*);
void write_sockaddr(struct sockaddr_in*, short int );

#endif SOCKETMAN_HH