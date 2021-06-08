cmake_minimum_required(VERSION 3.20)
project(Calculator VERSION 0.3.1)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(src/Calculator)
add_subdirectory(src/exe)
add_subdirectory(src/Interface)
add_subdirectory(src/Strings)
add_subdirectory(test)