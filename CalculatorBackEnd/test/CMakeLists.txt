cmake_minimum_required(VERSION 3.11)

set(This calculator_test)
project(${This} C CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

set(GCC_COVERAGE_COMPILE_FLAGS "-g -O0 -coverage -fprofile-arcs -ftest-coverage")
set(GCC_COVERAGE_LINK_FLAGS "-coverage -lgcov")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${GCC_COVERAGE_LINK_FLAGS}")

# Some recommendations on NOT using file globbing to grab all cpp files.  So far, it seems
# ok, so rolling with it until we get more experience.
file(GLOB UNIT_TEST_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/../src/*/test/*.cpp
)

add_executable(${This} ${UNIT_TEST_SOURCES})
target_link_libraries(
    ${This}
    PUBLIC	
    gtest_main
    gmock_main
    gtest
    gmock
    pthread
    CalculatorExpression
    CalculatorExpressionParser
    CalculatorApplication
)
include(GoogleTest)
gtest_discover_tests(${This})