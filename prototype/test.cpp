#include <iostream>
#include "ExecTest.h"
#include "gtest/gtest.h"

using namespace std;

TEST(ExecText, PRINTHELLO) {
    EXPECT_EQ('Hello World executed by execvp()!', ExecTest());
}

TEST(ExecText, PRINTtwo) {
    EXPECT_EQ('Hello World executed by execvp()!', ExecTest());
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}