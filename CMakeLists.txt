cmake_minimum_required(VERSION 3.6)
project(test_kontur)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(generator)

set(SOURCE_FILES main.cpp Reader.cpp Reader.h Graph.cpp Graph.h)
add_executable(test_kontur ${SOURCE_FILES})