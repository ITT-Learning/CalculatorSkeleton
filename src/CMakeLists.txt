list(APPEND _sources
        ../inc/IExpression.h IExpression.cpp
        ../inc/ValueExpression.h ValueExpression.cpp
        ../inc/SymbolExpression.h SymbolExpression.cpp
        ../inc/ExpressionFactory.h ExpressionFactory.cpp
        ../inc/OperatorExpression.h OperatorExpression.cpp)

# Set the output folder where your program will be created
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_executable(${PROJECT_NAME} main.cpp ${_sources})
add_library(lib${PROJECT_NAME} ${_sources})
