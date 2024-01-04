cmake_minimum_required(VERSION 3.26)
project(PROG2100_Student_Information_System)

set(CMAKE_CXX_STANDARD 17)

add_executable(PROG2100_Student_Information_System StudentInfoSystem/main.cpp
        StudentInfoSystem/Menu.h
        StudentInfoSystem/Start.h
        StudentInfoSystem/Student.cpp
        StudentInfoSystem/StudentRegistry.cpp)
