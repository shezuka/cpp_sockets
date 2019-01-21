cmake_minimum_required(VERSION 3.13)
project(sockets)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_library(sockets SHARED include/Socket.h src/Socket.cpp include/TcpServer.h src/TcpServer.cpp include/TcpClient.h src/TcpClient.cpp)