# Specifica versione e progetto
cmake_minimum_required(VERSION 3.15)
project(mailingProtocol)

# Imposta standard C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../bin) # per buttare i file.exe in una cartella fuori dal build

# Percorso per gli header
include_directories(${CMAKE_SOURCE_DIR}/include)

# Aggiungi eseguibile per il Client
add_executable(client
    Client/client.cpp
    include/socket_MAN.cpp
)
# Linka la libreria ws2_32 per il client
target_link_libraries(client ws2_32)

# Aggiungi eseguibile per il Server
add_executable(server
    Server/server.cpp
    include/socket_MAN.cpp
    include/profile_MAN.cpp
)
# Linka le lib per il server
target_link_libraries(server ws2_32)

# Linka le lib per il client
target_link_libraries(client Ws2_32 )
target_link_libraries(client Mswsock )
target_link_libraries(client AdvApi32 )

