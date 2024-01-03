cmake_minimum_required(VERSION 3.26)
project(apresentacao C)

set(CMAKE_C_STANDARD 17)

add_executable(apresentacao main.c
        ufp6.h
        ufp6.c
        funcoes.c)
