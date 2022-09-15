list(APPEND _sources ../inc/Calculator.h Calculator.cpp ./CalcHistory.cpp ../inc/CalcHistory.h ./CalcHistoryPair.cpp ../inc/CalcHistoryPair.h ./CalcHistoryTraverser.cpp ../inc/CalcHistoryTraverser.h ./MathOperations/Addition.cpp ../inc/MathOperations/Addition.h ./MathOperations/Constant.cpp ../inc/MathOperations/Constant.h ./MathOperations/Division.cpp ../inc/MathOperations/Division.h ../inc/MathOperations/IMathOperation.h ./MathOperations/Multiplication.cpp ../inc/MathOperations/Multiplication.h ./MathOperations/Subtraction.cpp ../inc/MathOperations/Subtraction.h ./FourOperationFactory.cpp ../inc/IOperationFactory.h ../inc/FourOperationFactory.h)

# Set the output folder where your program will be created
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)


find_package(Curses REQUIRED)
include_directories(/usr/include)
add_executable(${PROJECT_NAME} main.cpp ${_sources})
target_link_libraries(${PROJECT_NAME} ${CURSES_LIBRARIES})
add_library(lib${PROJECT_NAME} ${_sources})