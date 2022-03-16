cmake_path(GET CMAKE_CURRENT_BINARY_DIR FILENAME lib_path)

set(LIBRARY_NAME ${PROJECT_NAME}${lib_path})

file(GLOB LIBRARY_SOURCES "src/*.cpp" "inc/*.h")

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${LIBRARY_NAME}/build)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${LIBRARY_NAME}/build)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${LIBRARY_NAME}/bin)

include_directories(inc
)

add_library(${LIBRARY_NAME} ${LIBRARY_SOURCES})
add_executable(${PROJECT_NAME}Server ${LIBRARY_SOURCES})

target_include_directories(
    ${LIBRARY_NAME}
    PUBLIC
    ${CMAKE_CURRENT_BINARY_DIR}/inc
)
target_include_directories(
    ${PROJECT_NAME}Server
    PUBLIC
    ${CMAKE_CURRENT_BINARY_DIR}/inc
)

target_link_libraries(${LIBRARY_NAME} pistache)
target_link_libraries(${PROJECT_NAME}Server pistache)