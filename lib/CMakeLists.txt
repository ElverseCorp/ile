cmake_minimum_required(VERSION 3.10)
project(Ile)

set(CMAKE_C_STANDARD 11)

# For SO we have not to do anything

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_C_FLAGS "-Wall -Wextra -pedantic")
set(CMAKE_C_FLAGS_DEBUG "-D DEBUG")
set(CMAKE_C_FLAGS_RELEASE "-O3")


add_library(ile_solver SHARED)

target_include_directories(ile_solver PUBLIC "include/")
file(GLOB_RECURSE ILE_LIB_SRC "src/*.c")
target_sources(ile_solver PRIVATE ${ILE_LIB_SRC})
