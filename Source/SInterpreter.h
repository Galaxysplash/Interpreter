#pragma once


struct Interpreter {
    static void runFile(const char path[]);
    static void run(const char bytes[]);
};
