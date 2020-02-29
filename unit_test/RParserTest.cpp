#ifndef __PARSER_TEST_HPP__
#define __PARSER_TEST_HPP__

#include "gtest/gtest.h"


#include "../src/RParser.hpp"
#include <cstring>

TEST(hashTest, hashTesttwo)
{
   
	string test_val1 = "echo abc#def";
	RParser *myRp = new RParser();
    EXPECT_EQ("echo abc",myRp->readHash(test_val1));
     
}
//TEST(quoteTest, quoteTesttwo)
//{
//    string test_val2 = "echo "hello world"";
//    RParse *myRP = new RParser();
//    EXPECT_EQ("echo "hello world"", myRP->readQupte(test_val2))
//}



#endif
