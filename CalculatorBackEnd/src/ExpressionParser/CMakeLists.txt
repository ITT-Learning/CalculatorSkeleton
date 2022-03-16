cmake_path(GET CMAKE_CURRENT_BINARY_DIR FILENAME lib_path)

message("${PROJECT_NAME}")
set(LIBRARY_NAME ${PROJECT_NAME}${lib_path})

file(GLOB LIBRARY_SOURCES "src/*.cpp" "inc/*.h")

# Set the output folder where your program will be created
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${LIBRARY_NAME}/build)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${LIBRARY_NAME}/build)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${LIBRARY_NAME}/bin)

include_directories(inc
    $<TARGET_PROPERTY:CalculatorExpression,INCLUDE_DIRECTORIES>
)

add_library(${LIBRARY_NAME} ${LIBRARY_SOURCES})

target_include_directories(
    ${LIBRARY_NAME}
    PUBLIC
    ${CMAKE_CURRENT_BINARY_DIR}/inc
    $<TARGET_PROPERTY:CalculatorExpression,INCLUDE_DIRECTORIES>
)
target_link_libraries(${LIBRARY_NAME} CalculatorExpression)