#include <gtest/gtest.h>

#include "../../src/RSeparator.cpp"
#include "../../src/RShellExec.cpp"

TEST(smclTest, smclTestwithtwo)
{
    // char test_val; 
    char test_val1 = "ls";
    char test_val2 = "echo UwU";
    RShellExec *test1 = new RShellExec(test_val[0]);
    RShellExec *test2 = new RShellExec(test_val[1]);
    // testContainer[0] = new RShellBase(test_val[0]);
    RSeparator::RShellConn *test = new RSeparator::RShellConn(test1,test2);
    EXPECT_TRUE(test->execute());
     
}

