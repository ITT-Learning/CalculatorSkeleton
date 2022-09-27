list(APPEND _sources
    Calculator.cpp

    ./CalcHistory.cpp
    ./CalcHistoryPair.cpp
    ./CalcHistoryTraverser.cpp
    ./FourOperationFactory.cpp
    ./MathExpression.cpp

    ./MathOperations/Addition.cpp
    ./MathOperations/Constant.cpp
    ./MathOperations/Division.cpp
    ./MathOperations/Multiplication.cpp
    ./MathOperations/Subtraction.cpp
)

# Set the output folder where your program will be created
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)


find_package(Curses REQUIRED)
include_directories(/usr/include)
add_executable(${PROJECT_NAME} main.cpp ${_sources})
add_dependencies(${PROJECT_NAME} fbsh)
target_link_libraries(${PROJECT_NAME} ${CURSES_LIBRARIES})
add_library(lib${PROJECT_NAME} ${_sources})