#include <iostream>
#include <googletest/include/gtest/internal/gtest-port.h>
#include <googletest/include/gtest/gtest.h>
#include "com.ming.codes/blogcodes/Cppblogcode.h"

//全部单元测试一起运行
GTEST_API_ int main(int argc, char ** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

