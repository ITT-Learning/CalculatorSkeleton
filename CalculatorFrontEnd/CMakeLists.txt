cmake_path(GET CMAKE_CURRENT_BINARY_DIR FILENAME LIBRARY_NAME)

add_custom_target(${LIBRARY_NAME} ALL
    COMMAND npm update
    COMMAND /usr/bin/ng build --output-path "${CMAKE_BINARY_DIR}/${LIBRARY_NAME}"
    WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
    COMMENT "Building front end using /usr/bin/ng"
)