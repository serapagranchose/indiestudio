cmake_minimum_required(VERSION 3.17)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})

project(bonberman
    VERSION 0.1
    DESCRIPTION "A Bomberman game in c++, powered by RayLib !"
    LANGUAGES CXX)

file(GLOB SRCS "src/*.cpp")

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
find_package(raylib 2.5.0 REQUIRED)
add_executable(bomberman ${SRCS})
include_directories(bomberman include)
target_link_libraries(bomberman raylib)