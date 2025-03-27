cmake_minimum_required(VERSION 3.30)
project(Interpreter)

set(CMAKE_CXX_STANDARD 20)

add_executable(Interpreter Source/main.cpp
        Source/Interpreter/CInterpreter.cpp
        Source/Interpreter/CInterpreter.h
        Source/Memory/BufferSize.h
        Source/String/SString.cpp
        Source/String/SString.h
)
