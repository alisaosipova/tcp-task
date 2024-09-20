cmake_minimum_required(VERSION 3.10)

project(tcptask VERSION 1.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SOURCES
    tcp-server/TCPServer.cpp
    tcp-client/TCPClient.cpp
    main.cpp
)

# client 
add_executable(client ${SOURCES})

target_link_libraries(client pthread)

# server
add_executable(server ${SOURCES})

target_link_libraries(server pthread)
