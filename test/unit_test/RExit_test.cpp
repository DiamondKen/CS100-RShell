#ifndef _REXIT_TEST_CPP__
#define _REXIT_TEST_CPP__

#include "../src/RExit.cpp"
#include "../src/RShellExec.cpp"
#include "gtest/gtest.h"

TEST(RExitTest, RExitExecute)
{
    Exit *test = new Exit();
    EXPECT_EQ(test->exxcute());
}

#endif // _REXIT_TEST_CPP__
