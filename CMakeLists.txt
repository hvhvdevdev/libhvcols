cmake_minimum_required(VERSION 3.19)
project(libhvcols C)

set(CMAKE_C_STANDARD 99)

add_library(libhvcols hvLinkedList.c hvLinkedList.h)

add_executable(tests tests.c vendor/bdd-for-c.h)

target_link_libraries(tests libhvcols)