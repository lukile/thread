cmake_minimum_required(VERSION 3.14)
project(thread C)

set(CMAKE_C_STANDARD 99)

add_executable(thread main.c)

target_link_libraries(${thread} pthread)

SET( CMAKE_CXX_FLAGS -pthread)

