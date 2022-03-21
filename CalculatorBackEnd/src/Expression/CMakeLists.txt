cmake_path(GET CMAKE_CURRENT_SOURCE_DIR FILENAME lib_path)

set(LIBRARY_NAME ${PROJECT_NAME}${lib_path})

set(LIBRARY_SOURCES
    "src/ExpressionSerializer.cpp"
    "src/IExpression.cpp"
    "src/OperatorExpression.cpp"
    "src/SymbolExpression.cpp"
    "src/ValueExpression.cpp"
)
set(LIBRARY_INCLUDES
    "inc/ExpressionSerializer.h"
    "inc/IExpression.h"
    "inc/OperatorExpression.h"
    "inc/SymbolExpression.h"
    "inc/ValueExpression.h"
)

add_library(${LIBRARY_NAME} STATIC)

set(FLATBUFFER_OUTPUT_SCHEMA_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/flatbuffers")
file(MAKE_DIRECTORY "${FLATBUFFER_OUTPUT_SCHEMA_DIRECTORY}")
file(GLOB FLATBUFFER_SCHEMAS "flatbuffers/*.fbs")
foreach(FLATBUFFER_SCHEMA ${FLATBUFFER_SCHEMAS})
    cmake_path(GET FLATBUFFER_SCHEMA FILENAME FLATBUFFER_SCHEMA_FILENAME)
    set(FLATBUFFER_NAME ${FLATBUFFER_SCHEMA_FILENAME})
    cmake_path(REMOVE_EXTENSION FLATBUFFER_NAME)
    set(FLATBUFFER_HEADER "${CMAKE_CURRENT_SOURCE_DIR}/inc/${FLATBUFFER_NAME}_generated.h")
    set(FLATBUFFER_OUTPUT_SCHEMA "${FLATBUFFER_OUTPUT_SCHEMA_DIRECTORY}/${FLATBUFFER_SCHEMA_FILENAME}")
    # even though we're just generating a header file, in order for CMake to know that it should generate these files,
    # the files need to be used as a dependency for a target, so they're added to LIBRARY_FLATBUFFERS here.
    list(APPEND LIBRARY_FLATBUFFER_HEADERS ${FLATBUFFER_HEADER})
    add_custom_command(OUTPUT ${FLATBUFFER_HEADER}
        COMMAND ${FlatBuffers_BINARY_DIR}/flatc
        ARGS --cpp --gen-object-api -o "${CMAKE_CURRENT_SOURCE_DIR}/inc/" "${FLATBUFFER_SCHEMA}"
        DEPENDS "${FLATBUFFER_SCHEMA}" flatc
        COMMENT "Compiling flatbuffer schema: ${FLATBUFFER_SCHEMA}"
    )
    add_custom_command(OUTPUT ${FLATBUFFER_OUTPUT_SCHEMA}
        COMMAND /usr/bin/cp
        ARGS "${FLATBUFFER_SCHEMA}" "${FLATBUFFER_OUTPUT_SCHEMA}"
        DEPENDS ${FLATBUFFER_SCHEMA}
        COMMENT "Copying flatbuffer schema: ${FLATBUFFER_SCHEMA}"
    )
    add_custom_target(${FLATBUFFER_SCHEMA_FILENAME} DEPENDS ${FLATBUFFER_OUTPUT_SCHEMA})
    add_dependencies(${LIBRARY_NAME} ${FLATBUFFER_SCHEMA_FILENAME})
endforeach()

target_sources(${LIBRARY_NAME}
    PRIVATE
    ${LIBRARY_SOURCES}
    ${LIBRARY_INCLUDES}
    ${LIBRARY_FLATBUFFERS}
)
target_include_directories(
    ${LIBRARY_NAME}
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/inc
)
target_link_libraries(${LIBRARY_NAME} flatbuffers)
