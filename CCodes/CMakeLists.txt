# cmake_minimum_required(VERSION <specify CMake version here>)

CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

project(CCodes C)

set(CMAKE_C_STANDARD 99)

add_executable(CCodes com.ming.code/main.c com.ming.code/blogcode/support.c com.ming.code/blogcode/operatorhead.h com.ming.code/blogcode/blogcodes.c
        com.ming.code/tinyhttp/smarthttp.c com.ming.code/tinyhttp/simpleclient.c com.ming.code/libcurl/request/cluster_curl.c com.ming.code/libcurl/request/cluster_curl.h
        com.ming.code/libcurl/request/libcurlclient.c com.ming.code/easylogger/port/elog_port.c
        com.ming.code/easylogger/src/elog.c com.ming.code/easylogger/src/elog_async.c com.ming.code/easylogger/src/elog_buf.c com.ming.code/easylogger/src/elog_utils.c
        com.ming.code/blogcode/method.h com.ming.code/libcurl/socket/externalsocket.c  com.ming.code/libcurl/socket/sendrecvheart.c com.ming.code/blogcode/ycodes.c com.ming.code/blogcode/ycodes.h)




set(CURL_LIBRARY "-lcurl")
find_package(CURL REQUIRED)
include_directories(${CURL_INCLUDE_DIR})
target_link_libraries(CCodes ${CURL_LIBRARIES})

include_directories(com.ming.code/easylogger/inc)

find_package(Threads)

target_link_libraries(CCodes ${CMAKE_THREAD_LIBS_INIT})

set(CJSON_LIBRARY "-cJSON")
find_package(cJSON REQUIRED)
include_directories(${cJSON_INCLUDE_DIR})
target_link_libraries(CCodes ${CJSON_LIBRARIES})