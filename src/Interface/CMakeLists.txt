# Get name of stem of path to help set library names
get_filename_component(lib_dir ${CMAKE_CURRENT_BINARY_DIR} NAME)

set(LIBRARY_NAME ${PROJECT_NAME}${lib_dir})

# Set the output folder where your program will be created
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${LIBRARY_NAME}/build)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${LIBRARY_NAME}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${LIBRARY_NAME}/bin)

include_directories(.)

add_library(${LIBRARY_NAME} INTERFACE ${LIBRARY_SOURCES})

target_include_directories(${LIBRARY_NAME} INTERFACE
    ${CMAKE_CURRENT_BINARY_DIR}/inc
)