#include "Thread1.h"
#include <iostream>

Thread1::Thread1(Buffer& buffer, IStringProcessor* processor)
    : buffer_(buffer), processor_(processor) {}

void Thread1::operator()() {
    std::string input;
    while (true) {
        std::cin >> input;
        std::string processed = processor_->process(input);
        if (!processed.empty()) {
            buffer_.set_data(processed);
        }
    }
}