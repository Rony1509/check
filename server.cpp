// server.cpp
#include "file_transfer.hpp"
#include "chat.hpp"

int main() {
    std::thread file_server(start_server);
    std::thread chat_server(start_chat_server);
    file_server.join();
    chat_server.join();
    return 0;
}

