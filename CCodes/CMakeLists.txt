# cmake_minimum_required(VERSION <specify CMake version here>)
project(CCodes C)

set(CMAKE_C_STANDARD 99)

add_executable(CCodes com.ming.code/main.c com.ming.code/support.c com.ming.code/operatorhead.h com.ming.code/blogcodes.c)