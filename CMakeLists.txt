cmake_minimum_required(VERSION 3.11)
project(Calculator)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(src/Messages)
add_subdirectory(src/History)
add_subdirectory(src/Result)
add_subdirectory(src/Parser)
add_subdirectory(src/Application)
add_subdirectory(src/exe)
add_subdirectory(test)
add_subdirectory(third-party)

enable_testing()
include(GoogleTest)