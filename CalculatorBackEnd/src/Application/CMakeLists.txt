cmake_path(GET CMAKE_CURRENT_SOURCE_DIR FILENAME lib_path)

set(LIBRARY_NAME ${PROJECT_NAME}${lib_path})

set(LIBRARY_SOURCES "src/ConsoleIo.cpp" "inc/ConsoleIo.h")


add_library(${LIBRARY_NAME} STATIC ${LIBRARY_SOURCES})
target_include_directories(
    ${LIBRARY_NAME}
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/inc
    $<TARGET_PROPERTY:CalculatorExpression,INTERFACE_INCLUDE_DIRECTORIES>
    $<TARGET_PROPERTY:CalculatorExpressionParser,INTERFACE_INCLUDE_DIRECTORIES>
)
target_link_libraries(${LIBRARY_NAME} CalculatorExpression CalculatorExpressionParser)

add_executable(${PROJECT_NAME}Console ${LIBRARY_SOURCES} "src/main.cpp")
target_include_directories(
    ${PROJECT_NAME}Console
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/inc
    $<TARGET_PROPERTY:CalculatorExpression,INTERFACE_INCLUDE_DIRECTORIES>
    $<TARGET_PROPERTY:CalculatorExpressionParser,INTERFACE_INCLUDE_DIRECTORIES>
)
target_link_libraries(${PROJECT_NAME}Console CalculatorExpression CalculatorExpressionParser)
