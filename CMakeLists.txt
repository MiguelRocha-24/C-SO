cmake_minimum_required(VERSION 4.0)
project(SO C)

set(CMAKE_C_STANDARD 17)

add_executable(SO1 hello.c
        hello.c)

add_executable(SO2 trig.c)
add_executable(SO3 pointers.c)

