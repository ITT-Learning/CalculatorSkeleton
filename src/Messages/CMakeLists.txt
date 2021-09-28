get_filename_component(lib_dir ${CMAKE_CURRENT_BINARY_DIR} NAME)

set(LIBRARY_NAME ${PROJECT_NAME}${lib_dir})


include_directories(inc)

add_library(${LIBRARY_NAME} INTERFACE)

target_include_directories(${LIBRARY_NAME} INTERFACE inc/)
