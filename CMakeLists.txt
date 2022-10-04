cmake_minimum_required(VERSION 3.16)
project(prototypical C)

set(CMAKE_C_STANDARD 11)

add_executable(prototypical main.c)

enable_testing()

add_subdirectory(libs)
add_subdirectory(extern)
