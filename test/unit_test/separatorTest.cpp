#include <gtest/gtest.h>

#include "../../src/RSeparator.cpp"
#include "../../src/RShellExec.cpp"

TEST(smclTest, smclTestwithtwo)
{
    // char test_val; 
    char *test_val1 = "echo";
    char *test_val2 = "ls";
    RShellExec *test1 = new RShellExec(test_val1);
    RShellExec *test2 = new RShellExec(test_val2);
    // testContainer[0] = new RShellBase(test_val[0]);
    RSeparator *test = new RSeparator(test2,test1);
    EXPECT_TRUE(test->execute());
     
}

