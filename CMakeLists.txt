cmake_minimum_required(VERSION 3.20)
project(Calculator VERSION 0.3.1)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-g -O0 -Wall -fprofile-arcs -ftest-coverage")
set(CMAKE_CXX_OUTPUT_EXTENSION_REPLACE ON)

add_subdirectory(src/Application)
add_subdirectory(src/Strings)
add_subdirectory(src/exe)
add_subdirectory(src/Interface)
add_subdirectory(src/Parser)

# Create OBJECT_DIR variable
set(OBJECT_DIR ${CMAKE_BINARY_DIR}/CMakeFiles/CalculatorApplication.dir)
message("-- Object files will be output to: ${OBJECT_DIR}")
message( "--cmake binary dir " ${CMAKE_BINARY_DIR})
message( "--cmake make prog " ${CMAKE_MAKE_PROGRAM})
message("--cmake_current_binary_dir" ${CMAKE_CURRENT_BINARY_DIR})

# Set the sources
set(SOURCES
    main.cpp
    CalculatorApplication.cpp
    CalculatorStrings.cpp
    )

# Create the gcov target. Run coverage tests with 'make gcov'
add_custom_target(gcov
    COMMAND mkdir -p coverage
    COMMAND ${CMAKE_MAKE_PROGRAM} src/Application/test
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    )
add_custom_command(TARGET gcov
    COMMAND echo "=================== GCOV ===================="
    COMMAND gcov -b ${CMAKE_SOURCE_DIR}/src/*.cpp -o ${OBJECT_DIR}
    #      | grep -A 5 "CalculatorApplication.cpp" > CoverageSummary.tmp
    # COMMAND cat CoverageSummary.tmp
     COMMAND echo "-- Coverage files have been output to ${CMAKE_BINARY_DIR}/coverage"
     COMMAND echo "-- ${CMAKE_SOURCE_DIR}"
     WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/coverage  # Need separate command for this line
    )
add_dependencies(gcov Calculator_exe)
# Make sure to clean up the coverage folder
set_property(DIRECTORY APPEND PROPERTY ADDITIONAL_MAKE_CLEAN_FILES coverage)

# Create the gcov-clean target. This cleans the build as well as generated 
# .gcda and .gcno files.
add_custom_target(scrub
    COMMAND ${CMAKE_MAKE_PROGRAM} clean
    COMMAND rm -f ${OBJECT_DIR}/*.gcno
    COMMAND rm -f ${OBJECT_DIR}/*.gcda
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    )

# Testing
enable_testing()

include(GoogleTest)

add_test(output_test ${CMAKE_CURRENT_BINARY_DIR}/bin/Calculator_exe)
