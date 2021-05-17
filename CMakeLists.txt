cmake_minimum_required(VERSION 3.17)
set(CMAKE_BUILD_TYPE Release)
project(bomberman)

find_package(raylib QUIET)

if (NOT raylib_FOUND)
    include(FetchContent)
    FetchContent_Declare(raylib URL https://github.com/raysan5/raylib/archive/master.tar.gz)
    FetchContent_GetProperties(raylib)

    if (NOT raylib_POPULATED)
        set(FETCHCONTENT_QUIET NO)
        FetchContent_Populate(raylib)

        set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

        add_subdirectory(${raylib_SOURCE_DIR} ${raylib_BINARY_DIR})
    endif()
endif()

add_executable(bomberman src/main.cpp)
target_link_libraries(bomberman raylib)
