cmake_minimum_required(VERSION 3.16)

project(libhvcols C)

set(CMAKE_C_STANDARD 99)

add_executable(tests tests.c vendor/bdd-for-c.h hvLinkedList.h)