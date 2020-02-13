#include "../header/RParser.hpp"
#include <queue>
#include <iostream>
#include <cstring>

using namespace std;

string RParser::readInput()
{

    char delimiterQuote[] = "\"";
    char s[] = "echo lol && ls && echo 123";
    char delimiter[] = " &|;";

    size_t pos = 0;
    queue<char *> container;
    string ret = "";
    char *token = strtok(s, delimiter);
    while (token)
    {
        container.push(token);
        ret += container.front();
        container.pop();
        token = strtok(NULL, delimiter);
    }

    return ret;
}

