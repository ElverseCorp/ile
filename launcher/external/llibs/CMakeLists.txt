cmake_minimum_required(VERSION 3.10)
project(Llibs)

set(CMAKE_C_STANDARD 11)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_C_FLAGS "-Wall -Wextra -pedantic")
set(CMAKE_C_FLAGS_DEBUG "-g" "-DDEBUG")
set(CMAKE_C_FLAGS_RELEASE "-O3")

add_library(llibs STATIC)

target_compile_options(llibs PRIVATE ${WINDOWS_COMPILE_FLAGS})
target_include_directories(llibs PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/cross/include
)

file(GLOB_RECURSE LLIBS_SRC "src/*.c" "cross/src/*.c" "native/${CMAKE_SYSTEM_NAME}/src/*.c")
target_sources(llibs PRIVATE ${LLIBS_SRC})

add_subdirectory(external/lingua)
target_link_libraries(llibs PUBLIC lingua)