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
        com.ming.codes/codinginterview/FindDuplicate.cpp com.ming.codes/blogcodes/googletest.cpp com.ming.codes/codinginterview/ReplaceSpace.cpp com.ming.codes/codinginterview/PrintListInReOrder.cpp com.ming.codes/codinginterview/ConstructBinaryTree.cpp com.ming.codes/codinginterview/NextNodeInBinaryTree.cpp com.ming.codes/codinginterview/QueueInTwoStack.cpp com.ming.codes/codinginterview/MinNumberInRotatedArray.cpp com.ming.codes/codinginterview/ReverseLinkedList.cpp com.ming.codes/codinginterview/CopyComplexList.cpp)
target_link_libraries(CppCodes ${LIBRARIES})