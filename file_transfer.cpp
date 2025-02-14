#include "file_transfer.hpp"

void send_file(const char* filename, const char* server_ip) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        std::cerr << "Socket creation failed!" << std::endl;
        return;
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, server_ip, &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        std::cerr << "Connection failed!" << std::endl;
        return;
    }

    send(sock, filename, strlen(filename), 0);
    std::ifstream infile(filename, std::ios::binary);
    char buffer[BUFFER_SIZE];
    
    while (infile.read(buffer, BUFFER_SIZE) || infile.gcount() > 0) {
        send(sock, buffer, infile.gcount(), 0);
    }

    infile.close();
    close(sock);
}
