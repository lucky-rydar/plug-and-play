project(plug-and-play)

cmake_minimum_required(VERSION 3.8)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fpermissive")

include_directories(
    lib/googletest/googletest/include
)

add_subdirectory(lib/googletest)

# example

add_subdirectory(example)

# tests

add_executable(test
    test/happy_test.cpp
)

target_link_libraries(test
    gtest_main
)
