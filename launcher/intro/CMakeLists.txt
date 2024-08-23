cmake_minimum_required(VERSION 3.10)
project(intro)

set(CMAKE_C_STANDARD 11)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_C_FLAGS "-Wall -Wextra -pedantic")
set(CMAKE_C_FLAGS_DEBUG "-g" "-DDEBUG")
set(CMAKE_C_FLAGS_RELEASE "-O3")

add_library(intro)

file(GLOB_RECURSE INTRO_SRC_FILES "src/*.c")
target_sources(intro PRIVATE ${INTRO_SRC_FILES})