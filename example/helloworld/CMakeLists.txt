project(pap-helloworld)

cmake_minimum_required(VERSION 3.8)

include_directories(
    common/
    ../../include
)

SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -fPIC")

add_executable(app
    app/main.cpp
    common/app.cpp
)

target_link_libraries(app
    ${CMAKE_DL_LIBS}
)

add_library(plugin SHARED
    plugin/plugin.cpp
)
