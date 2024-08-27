#ifndef BUFFER_H
#define BUFFER_H

#include <string>
#include <mutex>
#include <condition_variable>
#include <vector>
#include "IBufferObserver.h"

class Buffer {
public:
    void set_data(const std::string& data);
    std::string get_data();
    void add_observer(IBufferObserver* observer);
private:
    std::string data_;
    std::mutex mutex_;
    std::condition_variable cv_;
    bool ready_ = false;
    std::vector<IBufferObserver*> observers_;

    void notify_observers();
};

#endif // BUFFER_H