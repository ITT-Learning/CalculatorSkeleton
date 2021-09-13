cmake_minimum_required(VERSION 3.11)

include(FetchContent)

set(FETCHCONTENT_BASE_DIR ${CMAKE_CURRENT_SOURCE_DIR})

FetchContent_Declare(
        fmt
        GIT_REPOSITORY https://github.com/fmtlib/fmt.git
        GIT_TAG        7.1.3
)

FetchContent_GetProperties(fmt)
if(NOT fmt_POPULATED)
    FetchContent_Populate(fmt)
    add_subdirectory(${fmt_SOURCE_DIR} EXCLUDE_FROM_ALL ${fmt_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()