cmake_minimum_required(VERSION 3.11)

include(FetchContent)

FetchContent_Declare(
  pistache
  GIT_REPOSITORY https://github.com/pistacheio/pistache.git
  GIT_TAG        3ec9d7c4f8b828fdd391550fff81b01e72dd6269
)
FetchContent_MakeAvailable(pistache)
