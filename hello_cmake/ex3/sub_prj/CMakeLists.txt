cmake_minimum_required(VERSION 3.16.3)

project(sub_prj)

set(SOURCE_LIB lib.cpp)

add_library(lib STATIC ${SOURCE_LIB})