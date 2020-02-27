#include "../header/RParser.hpp"
#include <queue>
#include <iostream>
#include <cstring>

using namespace std;

bool RParser::execCommand(RShellBase *container)
{
    if (container == NULL)
    {
        return false;
    }
    return container->execute();
}

RShellBase *RParser::warpCommand(queue<char *> container)
{
    queue<RShellBase *> warpExec;

    while (container.size() != 0)
    {
        char *tempPtr = strdup(container.front());

        if (strchr(tempPtr, '&'))
        {
            container.pop();
            string ret = "";
            while (container.size() != 0 && !(container.front()[0] == '&' || container.front()[0] == '|' || container.front()[0] == ';'))
            {
                tempPtr = strdup(container.front());
                ret += tempPtr;
                container.pop();
                if (container.size() != 0 && !(container.front()[0] == '&' || container.front()[0] == '|' || container.front()[0] == ';'))
                {
                    ret += " ";
                }
            }
            RShellExec *retExe = new RShellExec(ret.c_str());
            RAnd *andExe = new RAnd(warpExec.front(), retExe);
            warpExec.pop();
            warpExec.push(andExe);
        }
        else if (strchr(tempPtr, '|'))
        {
            container.pop();
            string ret = "";
            while (container.size() != 0 && !(container.front()[0] == '&' || container.front()[0] == '|' || container.front()[0] == ';'))
            {
                tempPtr = strdup(container.front());
                ret += tempPtr;
                container.pop();
                if (container.size() != 0 && !(container.front()[0] == '&' || container.front()[0] == '|' || container.front()[0] == ';'))
                {
                    ret += " ";
                }
            }
            RShellExec *retExe = new RShellExec(ret.c_str());
            ROr *orExe = new ROr(warpExec.front(), retExe);
            warpExec.pop();
            warpExec.push(orExe);
        }
        else if (strchr(tempPtr, ';'))
        {
            container.pop();
            // tempPtr = strdup(container.front());
            string ret = "";
            while (container.size() != 0 && !(container.front()[0] == '&' || container.front()[0] == '|' || container.front()[0] == ';'))
            {
                tempPtr = strdup(container.front());
                ret += tempPtr;
                container.pop();
                if (container.size() != 0 && !(container.front()[0] == '&' || container.front()[0] == '|' || container.front()[0] == ';'))
                {
                    ret += " ";
                }
            }
            RShellExec *retExe = new RShellExec(ret.c_str());
            RSeparator *sepExe = new RSeparator(warpExec.front(), retExe);
            warpExec.pop();
            warpExec.push(sepExe);
        }
        else
        {
            string ret = "";
            while (container.size() != 0 && !(container.front()[0] == '&' || container.front()[0] == '|' || container.front()[0] == ';'))
            {
                tempPtr = strdup(container.front());
                ret += tempPtr;
                container.pop();
                if (container.size() != 0 && !(container.front()[0] == '&' || container.front()[0] == '|' || container.front()[0] == ';'))
                {
                    ret += " ";
                }
            }
            RShellExec *exe = new RShellExec(ret.c_str());
            warpExec.push(exe);
        }
    }

    return warpExec.front();
}

queue<char *> RParser::readInput(queue<char *> hashContainer)
{
    queue<char *> secondContainer;
    queue<char *> finalContainer;
    queue<char *> execContinaer;
    char delimiter[] = "&|;";
    char space[] = " ";

    // Add &,|,;
    while (hashContainer.size() != 0)
    {
        char *tempPtr = strdup(hashContainer.front());
        if (tempPtr[0] == '"')
        {
            secondContainer.push(tempPtr);
            hashContainer.pop();
        }
        else
        {
            char *command = strdup(tempPtr);
            char *copy = strdup(tempPtr);
            char *token = strtok(command, delimiter);
            while (token)
            {
                secondContainer.push(token);
                if (copy[token - command + strlen(token)] == '&')
                {
                    secondContainer.push("&");
                }
                else if (copy[token - command + strlen(token)] == '|')
                {
                    secondContainer.push("|");
                }
                else if (copy[token - command + strlen(token)] == ';')
                {
                    secondContainer.push(";");
                }
                token = strtok(NULL, delimiter);
            }
            hashContainer.pop();
        }
    }

    while (secondContainer.size() != 0)
    {
        char *tempPtr = strdup(secondContainer.front());
        if (tempPtr[0] == '"')
        {
            finalContainer.push(tempPtr);
            secondContainer.pop();
        }
        else
        {
            char *command = strdup(tempPtr);
            char *token = strtok(command, space);
            while (token)
            {
                finalContainer.push(token);
                token = strtok(NULL, delimiter);
            }
            secondContainer.pop();
        }
    }

    return finalContainer;
}

queue<char *> RParser::readHash(queue<char *> quoteContainer)
{
    // new queue for hashContainer
    char hashDemli[] = "#";
    queue<char *> tempContainer;
    queue<char *> hashContainer;
    while (quoteContainer.size() != 0)
    {
        // combine quotation with the sentence
        if (quoteContainer.front() == "\"")
        {
            string ret = "";
            quoteContainer.pop();
            ret += quoteContainer.front();
            quoteContainer.pop();
            quoteContainer.pop();
            char *charArray = strcpy(new char[ret.length() + 1], ret.c_str());
            tempContainer.push(charArray);
        }
        else
        {
            tempContainer.push(quoteContainer.front());
            quoteContainer.pop();
        }
    }

    // check hash symbol
    while (tempContainer.size() != 0)
    {
        char *tempPtr = strdup(tempContainer.front());
        if (tempPtr[0] == '"')
        {
            hashContainer.push(tempPtr);
            tempContainer.pop();
            // continue;
        }
        else if (strchr(tempPtr, '#') != NULL)
        {
            string ret = tempPtr;
            char *pos = strchr(tempPtr, '#');
            ret = ret.substr(0, pos - tempPtr);
            char *cutToken = strcpy(new char[ret.length() + 1], ret.c_str());
            hashContainer.push(cutToken);
            break;
        }
        else
        {
            hashContainer.push(tempPtr);
            tempContainer.pop();
        }
    }
    return hashContainer;
}

queue<char *> RParser::readQuote(char *input)
{
    char delimiter[] = "\"";

    queue<char *> quoteContainer;
    char *copy = strdup(input);
    string ret = "";
    char *copy2 = strdup(input);
    char *token = strtok(copy2, delimiter);
    while (token)
    {
        quoteContainer.push(token);
        if (copy[token - copy2 + strlen(token)] == '"')
        {
            quoteContainer.push("\"");
        }
        token = strtok(NULL, delimiter);
    }

    // debug code
    // int containerSize = quoteContainer.size();
    // for (int i = 0; i <= containerSize; i++)
    // {
    //     cout << quoteContainer.front() << endl;
    //     quoteContainer.pop();
    // }
    return quoteContainer;
}

// RShellBase *RParser::readPrecedence(queue<char *> container)
// {

// }
