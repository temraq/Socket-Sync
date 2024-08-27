#include "Buffer.h"

void Buffer::set_data(const std::string& data) {
    std::unique_lock<std::mutex> lock(mutex_);
    data_ = data;
    ready_ = true;
    notify_observers();
    cv_.notify_one();
}

std::string Buffer::get_data() {
    std::unique_lock<std::mutex> lock(mutex_);
    cv_.wait(lock, [this]{ return ready_; });
    ready_ = false;
    return data_;
}

void Buffer::add_observer(IBufferObserver* observer) {
    std::unique_lock<std::mutex> lock(mutex_);
    observers_.push_back(observer);
}

void Buffer::notify_observers() {
    for (auto observer : observers_) {
        observer->on_data_ready(data_);
    }
}