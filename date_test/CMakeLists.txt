cmake_minimum_required(VERSION 3.10.0)
project(date_test VERSION 0.1.0 LANGUAGES C CXX)

add_executable(date_test main.cpp)

# GoogleTest library
# See: https://github.com/google/googletest/blob/master/googletest/README.md

# Download library source code
include(FetchContent)
FetchContent_Declare(
  googletest
  # Specify the commit you depend on and update it regularly.
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

target_link_libraries(date_test PRIVATE date gtest_main)
