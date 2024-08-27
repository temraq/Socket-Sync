#include "Server.h"
#include <iostream>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
#include <cstring> // для memset

void Server::run() {
    while (true) {
        start_server();
    }
}

//.........................


void Server::start_server() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        std::cerr << "Failed to create socket" << std::endl;
        return;
    }

    struct sockaddr_in server;
    memset(&server, 0, sizeof(server)); 
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(8888);

    if (bind(sock, (struct sockaddr *)&server, sizeof(server)) == -1) {
        std::cerr << "Failed to bind socket" << std::endl;
        close(sock);
        return;
    }

    if (listen(sock, 3) == -1) {
        std::cerr << "Failed to listen on socket" << std::endl;
        close(sock);
        return;
    }

    std::cout << "Waiting for connections..." << std::endl;
    int client_sock;
    struct sockaddr_in client;
    socklen_t c = sizeof(client);

    while (true) {
        client_sock = accept(sock, (struct sockaddr *)&client, &c);
        if (client_sock == -1) {
            std::cerr << "Failed to accept connection" << std::endl;
            continue; 
        }
       // std::cout << "Client connected" << std::endl;
        char buffer[1024];
        while (true) {
            ssize_t read_size = recv(client_sock, buffer, sizeof(buffer) - 1, 0);
            if (read_size > 0) {
                buffer[read_size] = '\0'; 
                std::string data(buffer);
                process_data(data);
            } else if (read_size == 0) {
              //  std::cout << "Client disconnected" << std::endl;
                break; 
            } else {
                std::cerr << "Error receiving data" << std::endl;
                break; 
            }
        }
        close(client_sock); 
    }
    close(sock); 
}

//................................

void Server::process_data(const std::string& data) {
    if (data.length() > 2 && data.length() % 32 == 0) {
        std::cout << "Received valid data: " << data << std::endl;
    } else {
        std::cout << "Error: Data does not meet the criteria. " << std::endl;
    }
}