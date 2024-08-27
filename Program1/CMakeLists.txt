cmake_minimum_required(VERSION 3.10)
project(Program1)

set(CMAKE_CXX_STANDARD 17)

add_executable(Program1
    src/main.cpp
    src/Buffer.cpp
    src/Thread1.cpp
    src/Thread2.cpp
    src/NumericStringProcessor.cpp
)