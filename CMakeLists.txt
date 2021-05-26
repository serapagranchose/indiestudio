cmake_minimum_required(VERSION 3.17)
project(bomberman)

set(CMAKE_BUILD_TYPE Release)
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

find_package(raylib)

include_directories(include)

add_executable(bomberman
                include/indiestudio.hpp
                src/draw.cpp
                src/game.cpp
                src/input.cpp
                src/main.cpp
)

target_link_libraries(bomberman raylib)
