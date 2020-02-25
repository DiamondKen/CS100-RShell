#include <gtest/gtest.h>

#include "../src/ROr.cpp"

TEST(ROrTest, ROrExecute)
{
  
    char *test_val1 = strdup("echo");
    char *test_val2 = strdup("ls");
    RShellExec *test1 = new RShellExec(test_val1);
    RShellExec *test2 = new RShellExec(test_val2); 
    ROr *test = new ROr(test2,test1);
    EXPECT_TRUE(test->execute());

}