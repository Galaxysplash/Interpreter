#include "CInterpreter.h"
#include "BufferSize.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <ranges>

#include "SString.h"


void CInterpreter::runFile(const char path[]) {
    std::ifstream file(path);
    char* bytes;

    if (!file.is_open()) {
        std::cerr << "Error opening file " << path << std::endl;
        exit(1);
    }

    try {
        file.read(bytes, SBufferSize::MB);
    }
    catch (const std::out_of_range &e) {
        std::cerr << "File is to large " << path << std::endl;
        exit(1);
    }
    catch (const std::exception& e) {
        std::cerr << "Error reading file " << path << std::endl;
        exit(1);
    }


    run(bytes);

    if (hadError) {
        exit(64);
    }
}

void CInterpreter::runPrompt() {
    while (true) {
        char line[SBufferSize::KB];
        std::cout << "> ";
        std::cin.getline(line, SBufferSize::KB);

        if (std::cin.fail()) {
            std::cout << "Line to large\n";
            continue;
        }

        run(line);
        hadError = false;
    }
}

void CInterpreter::run(const char bytes[]) {
    std::vector<std::string> tokens;

    SString::split(bytes, tokens);

    for (const auto& token: tokens) {
        std::cout << token << std::endl;
    }
}

void CInterpreter::report(
    const size_t &line,
    const std::string_view &where,
    const std::string_view &message
) {
    std::cerr << "[Line " << line << "] Error" << where << ": " << message << std::endl;
    hadError = true;
}

void CInterpreter::error(const size_t &line, const std::string_view &message) {
    report(line, "", message);
}
