cmake_minimum_required(VERSION 3.13)
project(CppCodes)

message("------------ Options -------------")

set(CMAKE_CXX_STANDARD 14)
add_subdirectory(./googletest)
include_directories(./googletest/include ./googletest)
link_directories(./googletest)
set(LIBRARIES
        gtest
        pthread)

add_executable(CppCodes main.cpp com.ming.codes/blogcodes/Cppblogcode.cpp com.ming.codes/blogcodes/Cppblogcode.h
        com.ming.codes/leetcode/FindDuplicate.cpp com.ming.codes/blogcodes/googletest.cpp com.ming.codes/leetcode/ReplaceSpace.cpp com.ming.codes/leetcode/PrintListInReOrder.cpp com.ming.codes/leetcode/ConstructBinaryTree.cpp com.ming.codes/leetcode/NextNodeInBinaryTree.cpp)
target_link_libraries(CppCodes ${LIBRARIES})