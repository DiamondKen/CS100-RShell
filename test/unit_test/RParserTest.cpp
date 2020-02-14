
#include <gtest/gtest.h>

#include "../../src/RParser.cpp"

TEST(parserTest, parsetTestRandom)
{
    // char test_val;
    RParser *test = new RParser("echo \"hello\" && ls #&&dsaw");
    EXPECT_TRUE(test->execCommand(test->warpCommand(test->readInput(test->readHash(test->readQuote())))));
}