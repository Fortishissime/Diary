cmake_minimum_required(VERSION 3.24)
project(Diary C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(Diary
        main.c list.c list.h cell.c cell.h utils.c utils.h
        app.c
        rdv.c
        diary_e.c
)
