get_filename_component(lib_dir ${CMAKE_CURRENT_BINARY_DIR} NAME)

set(LIBRARY_NAME ${PROJECT_NAME}${lib_dir})

file(GLOB LIBRARY_SOURCES
    "src/*.cpp"
)

include_directories(
    inc
    $<TARGET_PROPERTY:CalculatorMessages,INCLUDE_DIRECTORIES>
    $<TARGET_PROPERTY:CalculatorParser,INCLUDE_DIRECTORIES>
    $<TARGET_PROPERTY:CalculatorResult,INCLUDE_DIRECTORIES>
    $<TARGET_PROPERTY:CalculatorHistory,INCLUDE_DIRECTORIES>
    ${CMAKE_SOURCE_DIR}/schema
)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${LIBRARY_NAME}/build)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${LIBRARY_NAME}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${LIBRARY_NAME}/bin)

SET(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -pthread")

add_library(${LIBRARY_NAME} ${LIBRARY_SOURCES})

target_include_directories(${LIBRARY_NAME} PUBLIC
    ${CMAKE_CURRENT_BINARY_DIR}/inc
) 

target_link_libraries(${LIBRARY_NAME}
    INTERFACE CalculatorMessages
    CalculatorParser
    CalculatorResult
    CalculatorHistory
    flatbuffers
)