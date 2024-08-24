cmake_minimum_required(VERSION 3.10)
project(Ile)

set(CMAKE_C_STANDARD 11)

# For DLL
if(WIN32)
  add_compile_options("-D ILE_API=__declspec(dllexport)")
endif()

# For SO we have not to do anything

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_C_FLAGS "-Wall -Wextra -pedantic")
# set(CMAKE_C_FLAGS_DEBUG "-g" "-D DEBUG")
set(CMAKE_C_FLAGS_RELEASE "-O3")

add_library(ile SHARED)

target_include_directories(ile PUBLIC "include/")
file(GLOB_RECURSE ILE_LIB_SRC "src/*.c")
target_sources(ile PRIVATE ${ILE_LIB_SRC})
