cmake_path(GET CMAKE_CURRENT_BINARY_DIR FILENAME lib_path)

set(LIBRARY_NAME ${PROJECT_NAME}${lib_path})

file(GLOB FLATBUFFER_SCHEMAS "flatbuffers/*.fbs")
file(GLOB LIBRARY_SOURCES "src/*.cpp" "inc/*.h")
foreach(FLATBUFFER_SCHEMA ${FLATBUFFER_SCHEMAS})
    set(FLATBUFFER_NAME ${FLATBUFFER_SCHEMA})
    cmake_path(REMOVE_EXTENSION FLATBUFFER_NAME)
    set(FLATBUFFER_HEADER "${CMAKE_CURRENT_BINARY_DIR}/inc/${FLATBUFFER_NAME}_generated.h")
    # even though we're just generating a header file, in order for CMake to know that it should generate these files,
    # the files need to be used as a dependency for a target, so they're added to LIBRARY_SOURCES here.
    list(APPEND LIBRARY_SOURCES ${FLATBUFFER_HEADER})
    add_custom_command(OUTPUT ${FLATBUFFER_HEADER}
        COMMAND ${FlatBuffers_BINARY_DIR}/flatc
        ARGS --cpp --gen-object-api -o "${CMAKE_CURRENT_BINARY_DIR}/inc/" "${FLATBUFFER_SCHEMA}"
        DEPENDS ${FLATBUFFER_SCHEMA} flatc
        COMMENT "Compiling flatbuffer schema: ${FLATBUFFER_SCHEMA}"
    )
endforeach()




# Set the output folder where your program will be created
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${LIBRARY_NAME}/build)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${LIBRARY_NAME}/build)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${LIBRARY_NAME}/bin)

include_directories(inc "${FlatBuffers_SOURCE_DIR}/include")

add_library(${LIBRARY_NAME} STATIC ${LIBRARY_SOURCES})

target_include_directories(${LIBRARY_NAME} PUBLIC ${CMAKE_CURRENT_BINARY_DIR}/inc)
target_link_libraries(${LIBRARY_NAME} flatbuffers)
