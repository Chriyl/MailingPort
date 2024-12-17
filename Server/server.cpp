#include "../_HeaderFiles/socket_MAN.hh"
#include <stdio.h>
#include <winsock2.h>
#include <vector>
#include <string>         // Add this header for std::string
#include <filesystem>   
#pragma comment(lib, "ws2_32.lib")

#define PORT 22222

int main()
{
    WSADATA wsa;

    if (!init_wsa(&wsa)) {
        printf("[-] Errore con WSA");
        return -1;
    }

    SOCKET sock = init_sock();
    sockaddr_in server_addr;
    write_sockaddr(&server_addr, (short int) PORT);

    printf("ciao");
    return 0;
}