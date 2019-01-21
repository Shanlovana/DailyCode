cmake_minimum_required(VERSION 3.13)

project(CMakeDemo C)

set(CMAKE_C_STANDARD 99)

set(VERSIONCODEMAJOR  1)
set(VERSIONCODEMINOR  0)



set(CMAKE_INCLUDE_CURRENT_DIR ON)


# 检查系统是否支持 pow 函数
include(${CMAKE_ROOT}/Modules/CheckFunctionExists.cmake)
check_function_exists(pow HAVE_POW)


# 加入一个配置头文件，用于处理 CMake 对源码的设置
configure_file(
        "${PROJECT_SOURCE_DIR}/config.h.in"
        "${PROJECT_BINARY_DIR}/config.h"
)

# 是否使用自己的 MathUtils 库
option(USE_MATH_LIB
        "Use provided math implementation" ON)#ON 与 OFF 切换

# 是否加入 MathUtils 库
if (USE_MATH_LIB)
    include_directories("${PROJECT_SOURCE_DIR}/math")
    add_subdirectory(math)
    set(EXTRA_LIBS ${EXTRA_LIBS} MathUtils)
endif (USE_MATH_LIB)


# 查找当前目录下的所有源文件
# 并将名称保存到 DIR_SRCS 变量
aux_source_directory(. DIR_SRCS)
# 指定生成目标
add_executable(CMakeDemo ${DIR_SRCS})

target_link_libraries(CMakeDemo ${EXTRA_LIBS})

#导入cJSON
set(CJSON_LIBRARY "-cJSON")
find_package(cJSON REQUIRED)
include_directories(${cJSON_INCLUDE_DIR})
target_link_libraries(CMakeDemo ${CJSON_LIBRARIES})


# 指定安装路径
install(TARGETS CMakeDemo DESTINATION bin)
install(FILES "${PROJECT_BINARY_DIR}/config.h"
        DESTINATION include)



# 构建一个 CPack 安装包
include (InstallRequiredSystemLibraries)
SET(CPACK_CMAKE_GENERATOR "Unix Makefiles")
SET(CPACK_GENERATOR "STGZ;TGZ;TZ")

set (CPACK_RESOURCE_FILE_LICENSE
        "${CMAKE_CURRENT_SOURCE_DIR}/License.txt")

SET(CPACK_PACKAGE_NAME "CMakeDemo")
SET(CPACK_PACKAGE_VENDOR "Kitware")
SET(CPACK_PACKAGE_VERSION "2.5.0")
SET(CPACK_PACKAGE_VERSION_MAJOR "2")
SET(CPACK_PACKAGE_VERSION_MINOR "5")
SET(CPACK_PACKAGE_VERSION_PATCH "0")

SET(CPACK_SYSTEM_NAME "Linux-i686")
SET(CPACK_TOPLEVEL_TAG "Linux-i686")

include (CPack)