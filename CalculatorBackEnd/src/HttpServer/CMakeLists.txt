cmake_path(GET CMAKE_CURRENT_BINARY_DIR FILENAME lib_path)

set(LIBRARY_NAME ${PROJECT_NAME}${lib_path})

set(LIBRARY_SOURCES "src/HttpRequestHandler.cpp" "inc/HttpRequestHandler.h")

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${LIBRARY_NAME}/build)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${LIBRARY_NAME}/build)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${LIBRARY_NAME}/bin)

add_custom_target(genexdebug COMMAND ${CMAKE_COMMAND} -E echo "pistache include directories: $<TARGET_PROPERTY:pistache_static,INCLUDE_DIRECTORES>")
add_custom_target(genexdebug2 COMMAND ${CMAKE_COMMAND} -E echo "CalculatorExpression include directories: $<TARGET_PROPERTY:CalculatorExpression,INCLUDE_DIRECTORES>")
include_directories(inc
    $<TARGET_PROPERTY:pistache_static,INCLUDE_DIRECTORES>
    $<TARGET_PROPERTY:CalculatorExpression,INCLUDE_DIRECTORES>
)
link_libraries(
    pistache_static
    CalculatorExpression
)

add_library(${LIBRARY_NAME} STATIC ${LIBRARY_SOURCES})
add_executable(${PROJECT_NAME}Server ${LIBRARY_SOURCES} "src/main.cpp")

target_include_directories(
    ${LIBRARY_NAME}
    PUBLIC
    ${CMAKE_CURRENT_BINARY_DIR}/inc
    $<TARGET_PROPERTY:pistache_static,INCLUDE_DIRECTORES>
    $<TARGET_PROPERTY:CalculatorExpression,INCLUDE_DIRECTORES>
)
target_include_directories(
    ${PROJECT_NAME}Server
    PUBLIC
    ${CMAKE_CURRENT_BINARY_DIR}/inc
    $<TARGET_PROPERTY:pistache_static,INCLUDE_DIRECTORES>
    $<TARGET_PROPERTY:CalculatorExpression,INCLUDE_DIRECTORES>
)

target_link_libraries(${LIBRARY_NAME} CalculatorExpression pistache_static)
target_link_libraries(${PROJECT_NAME}Server CalculatorExpression pistache_static)