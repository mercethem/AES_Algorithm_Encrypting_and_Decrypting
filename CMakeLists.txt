cmake_minimum_required(VERSION 3.27)
project(src C)

set(CMAKE_C_STANDARD 11)

add_executable(src main.c aes.c aes.h utility.c utility.h)
