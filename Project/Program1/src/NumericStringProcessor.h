// NumericStringProcessor.h
#ifndef NUMERICSTRINGPROCESSOR_H
#define NUMERICSTRINGPROCESSOR_H

#include "IStringProcessor.h"

class NumericStringProcessor : public IStringProcessor {
public:
    std::string process(const std::string& input) override;
private:
    bool is_numeric(const std::string& str);
};

#endif // NUMERICSTRINGPROCESSOR_H