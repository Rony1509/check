#ifndef CHAT_HPP
#define CHAT_HPP

#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define CHAT_PORT 9090
#define BUFFER_SIZE 1024  // <-- Add this line

void chat_handle_client(int client_socket);
void start_chat_server();
void send_chat_message(const char* server_ip);

#endif // CHAT_HPP
