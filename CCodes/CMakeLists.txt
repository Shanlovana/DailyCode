# cmake_minimum_required(VERSION <specify CMake version here>)

CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

project(CCodes C)

set(CMAKE_C_STANDARD 99)

add_executable(CCodes com.ming.code/main.c com.ming.code/support.c com.ming.code/operatorhead.h com.ming.code/blogcodes.c
        com.ming.code/tinyhttp/smarthttp.c com.ming.code/tinyhttp/simpleclient.c com.ming.code/libcurl/cluster_curl.c com.ming.code/libcurl/cluster_curl.h
        com.ming.code/libcurl/libcurlclient.c)

set(CURL_LIBRARY "-lcurl")
find_package(CURL REQUIRED)
include_directories(${CURL_INCLUDE_DIR})
target_link_libraries(CCodes ${CURL_LIBRARIES})