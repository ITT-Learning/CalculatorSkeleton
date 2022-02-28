cmake_minimum_required(VERSION 3.11)
project(Calculator VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 14)

find_package(Boost 1.66)

include_directories(src inc)

add_subdirectory(src)
add_subdirectory(test)