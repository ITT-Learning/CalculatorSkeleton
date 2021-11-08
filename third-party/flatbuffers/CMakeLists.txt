cmake_minimum_required(VERSION 3.11)

include(FetchContent)

set(FETCHCONTENT_BASE_DIR ${CMAKE_CURRENT_SOURCE_DIR})

FetchContent_Declare(
        flatbuffers
        GIT_REPOSITORY https://github.com/google/flatbuffers.git
        GIT_TAG        v2.0.0
)

FetchContent_GetProperties(flatbuffers)
if(NOT flatbuffers_POPULATED)
    FetchContent_Populate(flatbuffers)
    add_subdirectory(${flatbuffers_SOURCE_DIR} EXCLUDE_FROM_ALL ${flatbuffers_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()