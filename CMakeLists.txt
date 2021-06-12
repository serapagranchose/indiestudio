cmake_minimum_required(VERSION 3.17)
project(bomberman)

set(CMAKE_BUILD_TYPE Release)
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

find_package(raylib)

include_directories(include)

add_executable(bomberman
                include/Block.hpp
                include/Button.hpp
                include/Game.hpp
                include/Player.hpp
                include/Music.hpp
                src/Block.cpp
                src/Button.cpp
                src/Game.cpp
                src/main.cpp
                src/Player.cpp
                src/str_to_word_array.cpp
                src/Music.cpp
)

target_link_libraries(bomberman raylib)
