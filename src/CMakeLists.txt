cmake_minimum_required(VERSION 2.8.4)
project(src)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES ImplementTriePrefixTree.cpp)
add_executable(src ${SOURCE_FILES})