cmake_path(GET CMAKE_CURRENT_SOURCE_DIR FILENAME lib_path)

set(LIBRARY_NAME ${PROJECT_NAME}${lib_path})

file(GLOB LIBRARY_SOURCES "src/*.cpp" "inc/*.h")

add_library(${LIBRARY_NAME} STATIC ${LIBRARY_SOURCES})
target_include_directories(
    ${LIBRARY_NAME}
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/inc
    $<TARGET_PROPERTY:CalculatorExpression,INTERFACE_INCLUDE_DIRECTORIES>
)
target_link_libraries(${LIBRARY_NAME} CalculatorExpression)