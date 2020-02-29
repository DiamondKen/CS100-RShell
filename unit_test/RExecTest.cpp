#include <gtest/gtest.h>

TEST(RExecTest, quotationTest)
{
    const char *test_val = "     echo         \"sadwhag       hjsdjjwhahj           dhjkwhadjsa\"         ";
    RShellExec *test = new RShellExec(test_val);
    test->execute();
    EXPECT_EQ("echo", string(test->getRealCommand()));
    EXPECT_EQ("sadwhag       hjsdjjwhahj           dhjkwhadjsa", string(test->getFlags().front()));
}

TEST(RExecTest, testWithECommandTest)
{
    const char *test_val = "test -e names.txt";
    RShellExec *test = new RShellExec(test_val);
    EXPECT_TRUE(test->execute());
}

TEST(RExecTest, testWithFCommandTest1)
{
    const char *test_val = "test -f names.txt";
    RShellExec *test = new RShellExec(test_val);
    EXPECT_TRUE(test->execute());
}

TEST(RExecTest, testWithDCommandTest1)
{
    const char *test_val = "test -d names.txt";
    RShellExec *test = new RShellExec(test_val);
    EXPECT_FALSE(test->execute());
}

TEST(RExecTest, testWithoutFlagCommandTest1)
{
    const char *test_val = "test names.txt";
    RShellExec *test = new RShellExec(test_val);
    EXPECT_TRUE(test->execute());
}

