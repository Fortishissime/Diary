cmake_minimum_required(VERSION 3.24)
project(Diary C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(Diary
        struc.c
        struc.h timer.h timer.c main.c)
