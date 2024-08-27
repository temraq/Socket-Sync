#include "NumericStringProcessor.h"
#include <algorithm>

bool NumericStringProcessor::is_numeric(const std::string& str) {
    return std::all_of(str.begin(), str.end(), ::isdigit);
}

std::string NumericStringProcessor::process(const std::string& input) {
    if (!is_numeric(input) || input.size() > 64) {
        return "Invalid data";
    }
    std::string result;
    result.reserve(input.size() * 2); 
    std::string sorted_input = input;
    std::sort(sorted_input.rbegin(), sorted_input.rend());
    for (char ch : sorted_input) {
        if ((ch - '0') % 2 == 0) {
            result += "KB";  
        } else {
            result += ch;
        }
    }
    return result;
}