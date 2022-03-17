cmake_path(GET CMAKE_CURRENT_SOURCE_DIR FILENAME lib_path)

set(LIBRARY_NAME ${PROJECT_NAME}${lib_path})

file(GLOB LIBRARY_SOURCES "src/*.cpp" "inc/*.h")

file(GLOB FLATBUFFER_SCHEMAS "flatbuffers/*.fbs")
foreach(FLATBUFFER_SCHEMA ${FLATBUFFER_SCHEMAS})
    set(FLATBUFFER_NAME ${FLATBUFFER_SCHEMA})
    cmake_path(REMOVE_EXTENSION FLATBUFFER_NAME)
    set(FLATBUFFER_HEADER "${CMAKE_CURRENT_SOURCE_DIR}/inc/${FLATBUFFER_NAME}_generated.h")
    # even though we're just generating a header file, in order for CMake to know that it should generate these files,
    # the files need to be used as a dependency for a target, so they're added to LIBRARY_SOURCES here.
    list(APPEND LIBRARY_SOURCES ${FLATBUFFER_HEADER})
    add_custom_command(OUTPUT ${FLATBUFFER_HEADER}
        COMMAND ${FlatBuffers_BINARY_DIR}/flatc
        ARGS --cpp --gen-object-api -o "${CMAKE_CURRENT_SOURCE_DIR}/inc/" "${FLATBUFFER_SCHEMA}"
        DEPENDS ${FLATBUFFER_SCHEMA} flatc
        COMMENT "Compiling flatbuffer schema: ${FLATBUFFER_SCHEMA}"
    )
endforeach()

add_library(${LIBRARY_NAME} STATIC ${LIBRARY_SOURCES})
target_include_directories(
    ${LIBRARY_NAME}
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/inc
    $<TARGET_PROPERTY:flatbuffers,INTERFACE_INCLUDE_DIRECTORIES>
)
target_link_libraries(${LIBRARY_NAME} flatbuffers)
