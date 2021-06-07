list(APPEND _sources ../inc/Calculator.h Calculator.cpp)

file(GLOB APP_SOURCES
    "*.cpp"
    "../inc/*.h"
)


# we irresponsibily added main.cpp to all the APP_SOURCES
# this is going to add main.cpp to the Calculator_lib, which we don't want
# this removes main.cpp from the APP_SOURCES list
file(GLOB to_remove main.cpp)
list(REMOVE_ITEM APP_SOURCES ${to_remove})


# Set the output folder where your program will be created
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_library(${PROJECT_NAME}_lib ${APP_SOURCES})

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME}
    Calculator_lib
)