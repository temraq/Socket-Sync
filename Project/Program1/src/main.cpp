#include "Buffer.h"
#include "Thread1.h"
#include "Thread2.h"
#include "NumericStringProcessor.h"
#include <thread>

int main() {
    Buffer buffer;
    NumericStringProcessor processor;
    Thread1 t1(buffer, &processor);
    Thread2 t2(buffer);

    std::thread thread1(t1);
    std::thread thread2(t2);

    thread1.join();
    thread2.join();

    return 0;
}