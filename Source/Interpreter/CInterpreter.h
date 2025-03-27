#pragma once
#include <functional>
#include <string>


static bool hadError = false;

class CInterpreter {
public:
    static void runFile(const char path[]);
    static void runPrompt();
    static void run(const char bytes[]);
    static void error(const size_t& line, const std::string_view& message);
    static void report(
        const size_t& line,
        const std::string_view& where,
        const std::string_view& message
    );
};