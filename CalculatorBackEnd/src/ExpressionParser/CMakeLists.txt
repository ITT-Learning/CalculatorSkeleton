cmake_path(GET CMAKE_CURRENT_SOURCE_DIR FILENAME lib_path)

set(LIBRARY_NAME ${PROJECT_NAME}${lib_path})

set(LIBRARY_SOURCES "src/ExpressionFactory.cpp")
set(LIBRARY_INCLUDES "inc/ExpressionFactory.h")

add_library(${LIBRARY_NAME} STATIC ${LIBRARY_SOURCES} ${LIBRARY_INCLUDES})
target_include_directories(
    ${LIBRARY_NAME}
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/inc
)
target_link_libraries(${LIBRARY_NAME} CalculatorExpression)
