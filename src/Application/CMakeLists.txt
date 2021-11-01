# Get name of stem of path to help set library names
get_filename_component(lib_dir ${CMAKE_CURRENT_BINARY_DIR} NAME)

set(LIBRARY_NAME ${PROJECT_NAME}${lib_dir})

file(GLOB LIBRARY_SOURCES
    "src/*.cpp"
) 

include_directories(
    inc
    $<TARGET_PROPERTY:CalculatorStrings,INCLUDE_DIRECTORIES>
    $<TARGET_PROPERTY:CalculatorParser,INCLUDE_DIRECTORIES>
    $<TARGET_PROPERTY:CalculatorInterface,INCLUDE_DIRECTORIES>
)

add_library(${LIBRARY_NAME} SHARED ${LIBRARY_SOURCES})

target_include_directories(${LIBRARY_NAME} PUBLIC
    ${CMAKE_CURRENT_BINARY_DIR}/inc
) 

target_link_libraries(${LIBRARY_NAME}
    CalculatorStrings
    CalculatorInterface
    CalculatorParser
)