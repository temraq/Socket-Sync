#ifndef IBUFFEROBSERVER_H
#define IBUFFEROBSERVER_H

#include <string>

class IBufferObserver {
public:
    virtual void on_data_ready(const std::string& data) = 0;
    virtual ~IBufferObserver() = default;
};

#endif // IBUFFEROBSERVER_H