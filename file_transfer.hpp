// file_transfer.hpp
#ifndef FILE_TRANSFER_HPP
#define FILE_TRANSFER_HPP

#include <iostream>
#include <fstream>
#include <thread>
#include <vector>
#include <cstring>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080
#define BUFFER_SIZE 1024

void handle_client(int client_socket);
void start_server();
void send_file(const char* filename, const char* server_ip);

#endif // FILE_TRANSFER_HPP
