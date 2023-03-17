cmake_minimum_required(VERSION 3.23)
project(Lab_6)

set(CMAKE_CXX_STANDARD 17)

add_executable(Lab_6 main.cpp
        CustomLogger/Logger.cpp
        CustomLogger/Logger.hpp)
