cmake_minimum_required(VERSION 3.11)

include(FetchContent)

set(FETCHCONTENT_BASE_DIR ${CMAKE_CURRENT_SOURCE_DIR})

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.10.0
)

FetchContent_GetProperties(googletest)
if(NOT googletest_POPULATED)
  FetchContent_Populate(googletest)
  add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR})
endif()

set(This calculator_test)
project(${This} C CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

set(GCC_COVERAGE_COMPILE_FLAGS "-g -O0 -coverage -fprofile-arcs -ftest-coverage")
set(GCC_COVERAGE_LINK_FLAGS "-coverage -lgcov")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${GCC_COVERAGE_LINK_FLAGS}")

enable_testing()

include_directories(
    $<TARGET_PROPERTY:SimpleExpressionCalculator,INCLUDE_DIRECTORIES>
    $<TARGET_PROPERTY:CompoundExpressionCalculator,INCLUDE_DIRECTORIES>
    $<TARGET_PROPERTY:CustomCalculator,INCLUDE_DIRECTORIES>
    $<TARGET_PROPERTY:CalculatorHistory,INCLUDE_DIRECTORIES>
    $<TARGET_PROPERTY:CalculatorStrings,INCLUDE_DIRECTORIES>
    )

# Some recommendations on NOT using file globbing to grab all cpp files.  So far, it seems
# ok, so rolling with it until we get more experience.

#"mocks/*.cpp",
file(GLOB UNIT_TEST_SOURCES
    ${CMAKE_SOURCE_DIR}/test/*.cpp
    ${CMAKE_SOURCE_DIR}/src/*/test/*.cpp
)


add_executable(${This} ${UNIT_TEST_SOURCES})

target_link_libraries(${This} PUBLIC	
    gtest_main
    gmock_main
    gtest
    gmock
    pthread
    SimpleExpressionCalculator
    CompoundExpressionCalculator
    CustomCalculator
    CalculatorHistory
    CalculatorStrings
)