cmake_minimum_required(VERSION 3.11)
project(Calculator VERSION 0.1.0)
include(FetchContent)

set(CMAKE_CXX_STANDARD 17)

FetchContent_Declare(
    flatbuffers
    GIT_REPOSITORY https://github.com/google/flatbuffers.git
    GIT_TAG v22.9.29
)

FetchContent_Declare(
    pistache
    GIT_REPOSITORY https://github.com/pistacheio/pistache.git
    GIT_TAG 769e4f458b85035f51c997e8a58d0dfeb8e5492e
)

FetchContent_MakeAvailable(flatbuffers pistache)

set(FLATBUFFERS_LIBRARY ${FETCHCONTENT_BASE_DIR}/flatbuffers-build/libflatbuffers.a)
set(PISTACHE_LIBRARY ${FETCHCONTENT_BASE_DIR}/pistache-build/src/libpistache.so)

add_custom_target(
    fbsh
    ALL
    ${FETCHCONTENT_BASE_DIR}/flatbuffers-build/flatc --cpp -o ./inc/flatbuffers/ ./flatbuffers/CalcHistory.fbs)

include_directories(src inc inc/MathOperations inc/flatbuffers inc/Controllers inc/Services)

add_subdirectory(src)
add_subdirectory(test)