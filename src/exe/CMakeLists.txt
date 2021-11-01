  
# Set the output folder where your program will be created
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Hmm, is there a better way?
include_directories(
    $<TARGET_PROPERTY:CalculatorApplication,INCLUDE_DIRECTORIES>
    $<TARGET_PROPERTY:CalculatorStrings,INCLUDE_DIRECTORIES>
)

set(EXECUTABLE_NAME ${PROJECT_NAME}_exe)

add_executable(${EXECUTABLE_NAME} main.cpp)

SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -pthread")

target_link_libraries(${EXECUTABLE_NAME}
    CalculatorApplication
    CalculatorStrings
)