#include <gtest/gtest.h>

TEST(RSepTest, RSeparatorTrueExecute)
{

    char *test_val1 = strdup("echo");
    char *test_val2 = strdup("ls");
    RShellExec *test1 = new RShellExec(test_val1);
    RShellExec *test2 = new RShellExec(test_val2);
    RSeparator *test = new RSeparator(test1, test2);
    EXPECT_TRUE(test->execute());
}

TEST(RSepTest, RSeparatorFirstHalfTrueExecute)
{

    char *test_val1 = strdup("echo 321");
    char *test_val2 = strdup("dywudhjwajd");
    RShellExec *test1 = new RShellExec(test_val1);
    RShellExec *test2 = new RShellExec(test_val2);
    RSeparator *test = new RSeparator(test1, test2);
    EXPECT_FALSE(test->execute());
}

TEST(RSepTest, RSeparatorSecondHalfTrueExecute)
{

    char *test_val1 = strdup("wjhdbjasjkdwak");
    char *test_val2 = strdup("echo lol");
    RShellExec *test1 = new RShellExec(test_val1);
    RShellExec *test2 = new RShellExec(test_val2);
    RSeparator *test = new RSeparator(test1, test2);
    EXPECT_TRUE(test->execute());
}

TEST(RSepTest, RSeparatorFalseExecute)
{

    char *test_val1 = strdup("wjhdbjasjkdwak");
    char *test_val2 = strdup("sadwadw");
    RShellExec *test1 = new RShellExec(test_val1);
    RShellExec *test2 = new RShellExec(test_val2);
    RSeparator *test = new RSeparator(test1, test2);
    EXPECT_FALSE(test->execute());
}
