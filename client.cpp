// client.cpp
#include "file_transfer.hpp"
#include "chat.hpp"

int main(int argc, char* argv[]) {
    if (argc == 3) {
        send_file(argv[1], argv[2]);
    } else if (argc == 2) {
        send_chat_message(argv[1]);
    } else {
        std::cerr << "Usage: " << argv[0] << " [filename server_ip] or [server_ip for chat]" << std::endl;
        return 1;
    }
    return 0;
}