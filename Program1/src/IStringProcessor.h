// IStringProcessor.h
#ifndef ISTRINGPROCESSOR_H
#define ISTRINGPROCESSOR_H

#include <string>

class IStringProcessor {
public:
    virtual std::string process(const std::string& input) = 0;
    virtual ~IStringProcessor() = default;
};

#endif // ISTRINGPROCESSOR_H