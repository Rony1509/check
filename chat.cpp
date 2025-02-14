#include "chat.hpp"
#include <cstring>  // Include this for strlen()

void send_chat_message(const char* server_ip) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        std::cerr << "Chat socket creation failed!" << std::endl;
        return;
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(CHAT_PORT);
    inet_pton(AF_INET, server_ip, &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        std::cerr << "Chat connection failed!" << std::endl;
        return;
    }

    char buffer[BUFFER_SIZE];
    while (true) {
        std::cin.getline(buffer, BUFFER_SIZE);
        send(sock, buffer, strlen(buffer), 0);  // strlen is now recognized
    }

    close(sock);
}
