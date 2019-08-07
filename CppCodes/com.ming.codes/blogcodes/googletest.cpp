//
// Created by android on 19-8-7.
//

#include <iostream>
#include <gtest/gtest.h>

int add(int a, int b) {
    return a + b;
}

TEST(test, c1) {
    EXPECT_EQ(3, add(1, 2));
}


