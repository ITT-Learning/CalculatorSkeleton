cmake_minimum_required(VERSION 3.11)

include(FetchContent)

set(FETCHCONTENT_BASE_DIR ${CMAKE_CURRENT_SOURCE_DIR})

FetchContent_Declare(
        pistache
        GIT_REPOSITORY https://github.com/pistacheio/pistache.git
)

FetchContent_GetProperties(pistache)
if(NOT pistache_POPULATED)
    FetchContent_Populate(pistache)
    add_subdirectory(${pistache_SOURCE_DIR} EXCLUDE_FROM_ALL ${pistache_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()