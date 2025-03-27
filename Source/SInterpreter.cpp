#include "Interpreter.h"
#include "BufferSize.h"

#include <fstream>
#include <iostream>

void Interpreter::runFile(const char path[]) {
    std::ifstream file(path);
    char* bytes;

    if (!file.is_open()) {
        std::cerr << "Error opening file " << path << std::endl;
        exit(1);
    }

    try {
        file.read(bytes, 3 * SBufferSize::Byte);
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
}

void Interpreter::run(const char bytes[]) {

}
