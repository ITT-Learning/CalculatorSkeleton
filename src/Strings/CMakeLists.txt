# Get name of stem of path to help set library names
get_filename_component(lib_dir ${CMAKE_CURRENT_BINARY_DIR} NAME)


set(LIBRARY_NAME ${PROJECT_NAME}${lib_dir})

file(GLOB LIBRARY_SOURCES
    "src/*.cpp"
)

# Set the output folder where your program will be created
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${LIBRARY_NAME}/build)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${LIBRARY_NAME}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${LIBRARY_NAME}/bin)

include_directories(inc
)

add_library(${LIBRARY_NAME} ${LIBRARY_SOURCES})

target_sources(${LIBRARY_NAME} PUBLIC
    ${LIBRARY_SOURCES})

target_include_directories(${LIBRARY_NAME} PUBLIC
    ${CMAKE_CURRENT_BINARY_DIR}/inc
) 