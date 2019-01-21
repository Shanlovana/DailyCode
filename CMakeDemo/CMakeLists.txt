cmake_minimum_required(VERSION 3.13)

project(CMakeDemo C)

set(CMAKE_C_STANDARD 99)


set(CMAKE_INCLUDE_CURRENT_DIR ON)

# 加入一个配置头文件，用于处理 CMake 对源码的设置
configure_file (
        "${PROJECT_SOURCE_DIR}/config.h.in"
        "${PROJECT_BINARY_DIR}/config.h"
)

# 是否使用自己的 MathUtils 库
option (USE_MATH_LIB
        "Use provided math implementation" ON)#ON 与 OFF 切换

# 是否加入 MathUtils 库
if (USE_MATH_LIB)
    include_directories ("${PROJECT_SOURCE_DIR}/math")
    add_subdirectory (math)
    set (EXTRA_LIBS ${EXTRA_LIBS} MathUtils)
endif (USE_MATH_LIB)


# 查找当前目录下的所有源文件
# 并将名称保存到 DIR_SRCS 变量
aux_source_directory(. DIR_SRCS)
# 指定生成目标
add_executable(CMakeDemo ${DIR_SRCS})

target_link_libraries (CMakeDemo  ${EXTRA_LIBS})


# 指定安装路径
install (TARGETS CMakeDemo DESTINATION bin)
install (FILES "${PROJECT_BINARY_DIR}/config.h"
        DESTINATION include)

# 启用测试
enable_testing()

# 测试程序是否成功运行
add_test (test_run CMakeDemo 5 2)

# 测试帮助信息是否可以正常提示
add_test (test_usage CMakeDemo)
set_tests_properties (test_usage
        PROPERTIES PASS_REGULAR_EXPRESSION "Usage: .* base exponent")

# 测试 5 的平方
 add_test (test_5_2 Demo 5 2)

 set_tests_properties (test_5_2
  PROPERTIES PASS_REGULAR_EXPRESSION "is 25")

