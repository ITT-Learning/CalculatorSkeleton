cmake_minimum_required(VERSION 3.11)
project(Calculator VERSION 0.1.0)
include(FetchContent)

set(CMAKE_CXX_STANDARD 17)

FetchContent_Declare(
    pistache
    GIT_REPOSITORY https://github.com/pistacheio/pistache.git
    GIT_TAG 769e4f458b85035f51c997e8a58d0dfeb8e5492e
)

FetchContent_Populate(pistache)

add_custom_target(fbsh ALL flatc --cpp -o ./inc/flatbuffers/ ./flatbuffers/CalcHistory.fbs)

include_directories(src inc inc/MathOperations inc/flatbuffers inc/Controllers inc/Services)

add_subdirectory(src)
add_subdirectory(test)