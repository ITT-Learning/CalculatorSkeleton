set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include_directories(
    $<TARGET_PROPERTY:CalculatorApplication,INCLUDE_DIRECTORIES>
    $<TARGET_PROPERTY:CalculatorRest,INCLUDE_DIRECTORIES>
)

set(EXECUTABLE_NAME ${PROJECT_NAME}_rest_exe)

SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -pthread")

add_executable(${EXECUTABLE_NAME} main.cpp)

target_link_libraries(${EXECUTABLE_NAME}
    CalculatorApplication
    CalculatorRest
    pistache
)