#include <iostream>

#include "CInterpreter.h"


int main(const int argc, const char* argv[]) {
    if (argc > 2) {
        std::cout << "Too many args\n";
        exit(64);
    } if (argc == 2) {
        CInterpreter::runFile(argv[1]);
    } else {
        CInterpreter::runPrompt();
    }
}
