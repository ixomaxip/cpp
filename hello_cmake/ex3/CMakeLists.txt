cmake_minimum_required(VERSION 3.16.3)

project(hello_cmake)

set(SOURCE_EXE main.cpp)

include_directories(sub_prj)

add_executable(main ${SOURCE_EXE})

add_subdirectory(sub_prj)

target_link_libraries(main lib)