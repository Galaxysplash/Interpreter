#include "SString.h"

void SString::split(const std::string_view&str, std::vector<std::string> &result) {
    std::string temp{};
    result.clear();

    for (const char& c: str) {
        temp += c;

        if (c == ' ') {
            result.emplace_back(temp);
            temp.clear();
        }
    }

    result.emplace_back(temp);
}