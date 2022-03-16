cmake_minimum_required(VERSION 3.11)

include(FetchContent)

FetchContent_Declare(
  flatbuffers
  GIT_REPOSITORY https://github.com/google/flatbuffers.git
  GIT_TAG        v2.0.0
)
FetchContent_MakeAvailable(flatbuffers)
