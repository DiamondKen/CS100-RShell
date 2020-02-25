#include <gtest/gtest.h>

#include "../src/RAnd.cpp"

TEST(RAndTest, RAndExecute)
{
  
    char *test_val1 = strdup("echo");
    char *test_val2 = strdup("ls");
    RAnd *test1 = new RAnd(test_val1);
    RAnd *test2 = new RAnd(test_val2);
    
    RAnd *test = new RAnd(test2,test1);
    EXPECT_TRUE(test->execute());

}
