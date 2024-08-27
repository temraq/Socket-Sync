#include "Thread2.h"
#include <iostream>
#include <numeric>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
#include <thread>
#include <chrono>

Thread2::Thread2(Buffer& buffer) : buffer_(buffer) {
    buffer_.add_observer(this);
}

void Thread2::send_to_program2(const std::string& data) {
    while (true) {
        int sock = socket(AF_INET, SOCK_STREAM, 0);
        struct sockaddr_in server;
        server.sin_addr.s_addr = inet_addr("127.0.0.1");
        server.sin_family = AF_INET;
        server.sin_port = htons(8888);
        if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == -1) {
            std::cerr << "Failed to connect to server. Retrying in 5 seconds..." << std::endl;
            close(sock);
            std::this_thread::sleep_for(std::chrono::seconds(5));
            continue; 
        }
        if (send(sock, data.c_str(), data.size(), 0) == -1) {
            std::cerr << "Failed to send data. Retrying in 5 seconds..." << std::endl;
            close(sock);
            std::this_thread::sleep_for(std::chrono::seconds(5));
            continue; 
        }
        close(sock);
        break; 
    }
}

void Thread2::on_data_ready(const std::string& data) {
    std::cout << "Received: " << data << std::endl;
    int sum = 0;
    for (char ch : data) {
        if (isdigit(ch)) {
            sum += ch - '0';
        }
    }
    std::cout << "Total: " << sum << std::endl;
    send_to_program2(std::to_string(sum));
}

void Thread2::operator()() {}