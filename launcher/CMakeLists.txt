cmake_minimum_required(VERSION 3.10)
project(Ile)

set(CMAKE_C_STANDARD 11)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_C_FLAGS "-Wall -Wextra -pedantic")
# set(CMAKE_C_FLAGS_DEBUG "-g" "-DDEBUG")
set(CMAKE_C_FLAGS_RELEASE "-O3")

add_subdirectory(../lib/ ../lib/build/)

# Build 
include_directories(include/)
file(GLOB_RECURSE ILE_SRC_FILES "src/*.c")

add_executable(ile ${ILE_SRC_FILES})
target_link_libraries(ile ile_solver)