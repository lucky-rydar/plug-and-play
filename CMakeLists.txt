project(plug-and-play)

cmake_minimum_required(VERSION 3.8)

include_directories(
    lib/googletest/googletest/include
)

add_subdirectory(lib/googletest)


# tests

add_executable(test
    test/happy_test.cpp
)

target_link_libraries(test
    gtest_main
)
