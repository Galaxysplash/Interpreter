#pragma once
#include <string>
#include <vector>


struct SString {
    static void split(const std::string_view &str, std::vector<std::string> &result);
};
