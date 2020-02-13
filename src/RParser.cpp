#include "../header/RParser.hpp"
#include <queue>
#include <iostream>
#include <cstring>

using namespace std;

string RParser::readInput()
{

    char delimiterQuote[] = "\"";
    char s[] = "echo \"lol && ls && echo 123\"";
    char *copy = strdup(s);
    char delimiter[] = " &|;";

    size_t pos = 0;
    queue<char *> container;
    string ret = "";
    char *token = strtok(s, delimiter);
    while (token)
    {
        container.push(token);
        if (copy[token - s + strlen(token)] == '&')
        {
            container.push("&");
        }
        else if (copy[token - s + strlen(token)] == '|')
        {
            container.push("|");
        }
        else if (copy[token - s + strlen(token)] == ';')
        {
            container.push(";");
        }

        token = strtok(NULL, delimiter);
    }

    return ret;
}

string RParser::readHash(queue<char *> quoteContainer)
{
    // new queue for hashContainer
    queue<char *> hashContainer;
    while (quoteContainer.size() != 0)
    {
        if (quoteContainer.front() == "\"")
        {
            string ret = "";
            ret += quoteContainer.front();
            quoteContainer.pop();
            while (quoteContainer.front() != "\"")
            {
                ret += quoteContainer.front();
                quoteContainer.pop();
            }
            char *charArray = strcpy(new char[ret.length() + 1], ret.c_str());
            hashContainer.push(charArray);
        }
    }

    char hashDemli[] = "#";

    return ret;
}

queue<char *> RParser::readQuote()
{
    char delimiter[] = "\"";

    size_t pos = 0;
    queue<char *> quoteContainer;
    char *copy = strdup(input);
    string ret = "";
    char *token = strtok(input, delimiter);
    while (token)
    {
        quoteContainer.push(token);
        if (copy[token - input + strlen(token)] == '"')
        {
            quoteContainer.push("\"");
        }
        token = strtok(NULL, delimiter);
    }
    int containerSize = quoteContainer.size();
    for (int i = 0; i <= containerSize; i++)
    {
        cout << quoteContainer.front() << endl;
        quoteContainer.pop();
    }
    return quoteContainer;
}