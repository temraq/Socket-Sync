#ifndef THREAD1_H
#define THREAD1_H

#include "Buffer.h"
#include "IStringProcessor.h"

class Thread1 {
public:
    Thread1(Buffer& buffer, IStringProcessor* processor);
    void operator()();
private:
    Buffer& buffer_;
    IStringProcessor* processor_;
};

#endif // THREAD1_H