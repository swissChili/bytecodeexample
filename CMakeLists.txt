cmake_minimum_required(VERSION 3.7)
project(bytecode-parser C)

add_subdirectory(lib/bytecode)
include_directories(lib/bytecode)

add_executable(parser parser.c)
target_link_libraries(parser bytecodelib)