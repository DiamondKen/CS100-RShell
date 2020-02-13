#ifndef  _REXIT_TEST_CPP__
#define  _REXIT_TEST_CPP__

#include "../src/RExit.h"
#include "gtest/gtest.h"

TEST(RExitTest, RExitExecute)
{
    Exit* test =new Exit();
    EXPECT_EQ(test->RExecute(0,1),0);

}

#endif // _REXIT_TEST_CPP__
