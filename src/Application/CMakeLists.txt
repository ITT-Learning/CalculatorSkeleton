# Get name of stem of path to help set library names
get_filename_component(lib_dir ${CMAKE_CURRENT_BINARY_DIR} NAME)

set(LIBRARY_NAME ${PROJECT_NAME}${lib_dir})

file(GLOB LIBRARY_SOURCES
    "src/*.cpp"
) 

add_subdirectory(test/)

include_directories(
    inc
    $<TARGET_PROPERTY:CalculatorStrings,INCLUDE_DIRECTORIES>
    )

# Set the output folder where your program will be created
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${LIBRARY_NAME}/build)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${LIBRARY_NAME}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${LIBRARY_NAME}/bin)

add_library(${LIBRARY_NAME} SHARED ${LIBRARY_SOURCES})

target_include_directories(${LIBRARY_NAME} PUBLIC
    ${CMAKE_CURRENT_BINARY_DIR}/inc
) 

target_link_libraries(${LIBRARY_NAME}
    CalculatorStrings
    CalculatorINTERFACE
)