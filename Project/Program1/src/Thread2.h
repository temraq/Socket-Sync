#ifndef THREAD2_H
#define THREAD2_H

#include "Buffer.h"
#include "IBufferObserver.h"

class Thread2 : public IBufferObserver {
public:
    Thread2(Buffer& buffer);
    void operator()();
    void on_data_ready(const std::string& data) override;
private:
    Buffer& buffer_;
    void send_to_program2(const std::string& data);
};

#endif // THREAD2_H