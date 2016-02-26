cmake_minimum_required(VERSION 3.3)
project(List_1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(List_1 ${SOURCE_FILES})