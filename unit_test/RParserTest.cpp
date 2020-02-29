#ifndef __PARSER_TEST_HPP__
#define __PARSER_TEST_HPP__

#include "gtest/gtest.h"

TEST(RParserTest, hashTest)
{

	string test_val1 = "echo abc#def";
	string test_val2 = "ech#dbskahjdwadjksjakdhwajdk";
	RParser *myRp = new RParser();
	EXPECT_EQ("echo abc", myRp->readHash(test_val1));
	EXPECT_EQ("ech", myRp->readHash(test_val2));
}

TEST(RParserTest, readExpresssionTest)
{
	string test_val = "echo abc||echo 123&&ls";
	RParser *myRp = new RParser();
	queue<string> tempQ = myRp->readExpression(test_val);
	EXPECT_EQ("echo abc", tempQ.front());
	tempQ.pop();
	EXPECT_EQ("||",tempQ.front());
	tempQ.pop();
	EXPECT_EQ("echo 123", tempQ.front());
	tempQ.pop();
	EXPECT_EQ("&&", tempQ.front());
	tempQ.pop();
	EXPECT_EQ("ls", tempQ.front());
}

TEST(RParserTest, commandTreeTest)
{
	string test_val = "(a||b)&&c";
	RParser *myRp = new RParser();
	queue<string> tempQ1 = myRp->readExpression(test_val);
	queue<string> postfix = myRp->commandTree(tempQ1);
	EXPECT_EQ("a", postfix.front());
	postfix.pop();
	EXPECT_EQ("b", postfix.front());
	postfix.pop();
	EXPECT_EQ("||", postfix.front());
	postfix.pop();
	EXPECT_EQ("c", postfix.front());
	postfix.pop();
	EXPECT_EQ("&&", postfix.front());
}
#endif
