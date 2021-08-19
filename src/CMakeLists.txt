list(APPEND _sources ../inc/Calculator.h Calculator.cpp)
list(APPEND _sources ../inc/OpSymbol.h OpSymbol.cpp)
list(APPEND _sources ../inc/IOperator.h IOperator.cpp)
list(APPEND _sources ../inc/IBinaryOperator.h IBinaryOperator.cpp)
list(APPEND _sources ../inc/IUnaryOperator.h IUnaryOperator.cpp)
list(APPEND _sources ../inc/AdditionOperator.h AdditionOperator.cpp)
list(APPEND _sources ../inc/SubtractionOperator.h SubtractionOperator.cpp)
list(APPEND _sources ../inc/MultiplicationOperator.h MultiplicationOperator.cpp)
list(APPEND _sources ../inc/DivisionOperator.h DivisionOperator.cpp)
list(APPEND _sources ../inc/ExponentOperator.h ExponentOperator.cpp)
list(APPEND _sources ../inc/SquareRootOperator.h SquareRootOperator.cpp)

# Set the output folder where your program will be created
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_executable(${PROJECT_NAME} main.cpp ${_sources})