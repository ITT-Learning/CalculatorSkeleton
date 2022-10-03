cmake_minimum_required(VERSION 3.11)
project(Calculator VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)

add_custom_target(fbsh ALL flatc --cpp -o ./inc/flatbuffers/ ./flatbuffers/CalcHistory.fbs)

include_directories(src inc inc/MathOperations inc/flatbuffers)

add_subdirectory(src)
add_subdirectory(test)