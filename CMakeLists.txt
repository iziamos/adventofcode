cmake_minimum_required(VERSION 3.20)
project(adventofcode)

set(CMAKE_CXX_STANDARD 23)

add_executable(adventofcode main.cpp utils.h utils.cpp problems/Problem1.cpp problems/Problem1.h problems/Problem2.cpp problems/Problem2.h)
