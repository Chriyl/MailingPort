# Specifica versione e progetto
cmake_minimum_required(VERSION 3.15)
project(mailingProtocol)

# Imposta standard C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Percorso per gli header
include_directories(${CMAKE_SOURCE_DIR}/_HeaderFiles)

# Aggiungi eseguibile per il Client
add_executable(client
    Client/client.cpp
    _HeaderFiles/socket_MAN.cpp
)
# Linka la libreria ws2_32 per il client
target_link_libraries(client ws2_32)

# Aggiungi eseguibile per il Server
add_executable(server
    Server/server.cpp
    _HeaderFiles/socket_MAN.cpp
)
# Linka la libreria ws2_32 per il server
target_link_libraries(server ws2_32)
target_link_libraries(client Ws2_32 )
target_link_libraries(client Mswsock )
target_link_libraries(client AdvApi32 )

