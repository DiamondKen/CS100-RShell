#ifndef _REXIT_TEST_CPP__
#define _REXIT_TEST_CPP__

#include "gtest/gtest.h"


TEST(RExitTest, RExitExecute)
{
    Exit *test = new Exit();
    EXPECT_TRUE(test->execute());
}

#endif // _REXIT_TEST_CPP__
