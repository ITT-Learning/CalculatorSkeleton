cmake_path(GET CMAKE_CURRENT_BINARY_DIR FILENAME lib_path)

set(LIBRARY_NAME ${PROJECT_NAME}${lib_path})

set(LIBRARY_SOURCES "src/ConsoleIo.cpp" "inc/ConsoleIo.h")


# Set the output folder where your program will be created
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${LIBRARY_NAME}/build)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${LIBRARY_NAME}/build)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${LIBRARY_NAME}/bin)

add_custom_target(genexdebug3 COMMAND ${CMAKE_COMMAND} -E echo "CalculatorExpression include directories: $<TARGET_PROPERTY:CalculatorExpression,INCLUDE_DIRECTORES>")
add_custom_target(genexdebug4 COMMAND ${CMAKE_COMMAND} -E echo "CalculatorExpressionParser include directories: $<TARGET_PROPERTY:CalculatorExpressionParser,INCLUDE_DIRECTORES>")
include_directories(inc
    $<TARGET_PROPERTY:CalculatorExpression,INCLUDE_DIRECTORIES>
    $<TARGET_PROPERTY:CalculatorExpressionParser,INCLUDE_DIRECTORIES>
)
link_libraries(
    CalculatorExpression
    CalculatorExpressionParser
)
add_library(${LIBRARY_NAME} STATIC ${LIBRARY_SOURCES})
add_executable(${PROJECT_NAME}Console ${LIBRARY_SOURCES} "src/main.cpp")


target_include_directories(
    ${LIBRARY_NAME}
    PUBLIC
    ${CMAKE_CURRENT_BINARY_DIR}/inc
    $<TARGET_PROPERTY:CalculatorExpression,INCLUDE_DIRECTORIES>
    $<TARGET_PROPERTY:CalculatorExpressionParser,INCLUDE_DIRECTORIES>
)
target_include_directories(
    ${PROJECT_NAME}Console
    PUBLIC
    ${CMAKE_CURRENT_BINARY_DIR}/inc
    $<TARGET_PROPERTY:CalculatorExpression,INCLUDE_DIRECTORIES>
    $<TARGET_PROPERTY:CalculatorExpressionParser,INCLUDE_DIRECTORIES>
)
