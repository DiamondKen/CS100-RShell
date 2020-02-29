#include <gtest/gtest.h>

TEST(ROrTest, ROrTrueExecute)
{

    char *test_val1 = strdup("echo");
    char *test_val2 = strdup("ls");
    RShellExec *test1 = new RShellExec(test_val1);
    RShellExec *test2 = new RShellExec(test_val2);
    ROr *test = new ROr(test1, test2);
    EXPECT_TRUE(test->execute());
}

TEST(ROrTest, ROrFirstHalfTrueExecute)
{

    char *test_val1 = strdup("echo 321");
    char *test_val2 = strdup("dywudhjwajd");
    RShellExec *test1 = new RShellExec(test_val1);
    RShellExec *test2 = new RShellExec(test_val2);
    ROr *test = new ROr(test1, test2);
    EXPECT_TRUE(test->execute());
}

TEST(ROrTest, ROrSecondHalfTrueExecute)
{

    char *test_val1 = strdup("wjhdbjasjkdwak");
    char *test_val2 = strdup("echo lol");
    RShellExec *test1 = new RShellExec(test_val1);
    RShellExec *test2 = new RShellExec(test_val2);
    ROr *test = new ROr(test1, test2);
    EXPECT_TRUE(test->execute());
}

TEST(ROrTest, ROrFalseExecute)
{

    char *test_val1 = strdup("wjhdbjasjkdwak");
    char *test_val2 = strdup("sadwadw");
    RShellExec *test1 = new RShellExec(test_val1);
    RShellExec *test2 = new RShellExec(test_val2);
    ROr *test = new ROr(test1, test2);
    EXPECT_FALSE(test->execute());
}
