cmake_minimum_required(VERSION 3.11)
project(Calculator VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 14)

include_directories(src inc inc/MathOperations)

add_subdirectory(src)
add_subdirectory(test)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lncurses")