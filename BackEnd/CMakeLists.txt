set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")
find_package(Boost 1.66)

add_subdirectory(fetched-libraries/flatbuffers)
add_subdirectory(src/Expression)
add_subdirectory(src/ExpressionParser)
add_subdirectory(src/Application)
add_subdirectory(test)

enable_testing()