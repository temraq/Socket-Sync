#ifndef SERVER_H
#define SERVER_H

#include <string>

class Server {
public:
    void run();
private:
    void process_data(const std::string& data);
    void start_server();
};

#endif // SERVER_H