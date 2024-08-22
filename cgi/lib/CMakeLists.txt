# This makefile build everything except main.c file

cmake_minimum_required(VERSION 3.10)
project(cgi)

set(CMAKE_C_STANDARD 11)

add_library(cgi STATIC)

# target_compile_options(llibs PRIVATE ${WINDOWS_COMPILE_FLAGS})
include_directories(include/)

file(GLOB_RECURSE LLIBS_SRC "src/*.c")
target_sources(cgi PRIVATE ${LLIBS_SRC})
