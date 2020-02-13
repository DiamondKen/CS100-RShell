#include <gtest/gtest.h>

#include "../src/RAnd.cpp"
#include "../src/RShellExec.cpp"

TEST(RAndTest, RAndExecute)
{
  
    char *test_val1 = "echo";
    char *test_val2 = "ls";
    RShellExec *test1 = new RShellExec(test_val1);
    RShellExec *test2 = new RShellExec(test_val2);
    
    RAnd *test = new RAnd(test2,test1);
    EXPECT_TRUE(test->execute());

}
