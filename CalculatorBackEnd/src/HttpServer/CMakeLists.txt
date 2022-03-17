cmake_path(GET CMAKE_CURRENT_SOURCE_DIR FILENAME lib_path)

set(LIBRARY_NAME ${PROJECT_NAME}${lib_path})

set(LIBRARY_SOURCES "src/HttpRequestHandler.cpp")
set(LIBRARY_INCLUDES "inc/HttpRequestHandler.h")

add_executable(${PROJECT_NAME}Server ${LIBRARY_SOURCES} ${LIBRARY_INCLUDES} "src/main.cpp")
target_include_directories(
    ${PROJECT_NAME}Server
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/inc
)
target_link_libraries(${PROJECT_NAME}Server CalculatorExpression CalculatorExpressionParser pistache_static)

add_library(${LIBRARY_NAME} STATIC ${LIBRARY_SOURCES} ${LIBRARY_INCLUDES})
target_include_directories(
    ${LIBRARY_NAME}
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/inc
)
target_link_libraries(${LIBRARY_NAME} CalculatorExpression CalculatorExpressionParser pistache_static)
get_property(DEBUG_INCL_DIRS TARGET ${LIBRARY_NAME} PROPERTY INCLUDE_DIRECTORIES)
message("${DEBUG_INCL_DIRS}")
get_property(DEBUG_IF_INCL_DIRS TARGET ${LIBRARY_NAME} PROPERTY INTERFACE_INCLUDE_DIRECTORIES)
message("${DEBUG_IF_INCL_DIRS}")
get_property(asdf TARGET CalculatorExpression PROPERTY INCLUDE_DIRECTORIES)
message("${asdf}")
get_property(asasdfdf TARGET CalculatorExpressionParser PROPERTY INCLUDE_DIRECTORIES)
message("${asasdfdf}")