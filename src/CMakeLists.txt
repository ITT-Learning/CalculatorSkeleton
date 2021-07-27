list(APPEND _sources ../inc/Calculator.h Calculator.cpp)
list(APPEND _sources ../inc/CalculatorW2.h CalculatorW2.cpp)
list(APPEND _sources ../inc/TokenizerW2.h TokenizerW2.cpp)
list(APPEND _sources ../inc/IoStreamCalculatorW2.h IoStreamCalculatorW2.cpp)

# Set the output folder where your program will be created
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_executable(${PROJECT_NAME} main.cpp ${_sources})