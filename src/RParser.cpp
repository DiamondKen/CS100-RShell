#include "../header/RParser.hpp"
#include <queue>
#include <iostream>
#include <cstring>

using namespace std;

queue<RShellBase*> RParser::warpCommand(queue<char *> container)
{
    queue<RShellBase *> warpExec;
    string command = "";
    while (container.size() != 0)
    {
        if (container.front() == "&")
        {
            container.pop();
            string ret = "";
            while (container.front() != "&" || container.front() != "|" || container.front() != ";" || container.size() != 0)
            {
                ret += container.front();
                container.pop();
            }
            RShellExec *retExe = new RShellExec(ret.c_str());
            RAnd *andExe = new RAnd(warpExec.front(), retExe);
            warpExec.pop();
            warpExec.push(andExe);
        }
        else if (container.front() == "|")
        {
            container.pop();
            string ret = "";
            while (container.front() != "&" || container.front() != "|" || container.front() != ";" || container.size() != 0)
            {
                ret += container.front();
                container.pop();
            }
            RShellExec *retExe = new RShellExec(ret.c_str());
            RAnd *andExe = new RAnd(warpExec.front(), retExe);
            warpExec.pop();
            warpExec.push(andExe);
        }
        else if (container.front() == ";")
        {
            container.pop();
            string ret = "";
            while (container.front() != "&" || container.front() != "|" || container.front() != ";" || container.size() != 0)
            {
                ret += container.front();
                container.pop();
            }
            RShellExec *retExe = new RShellExec(ret.c_str());
            RAnd *andExe = new RAnd(warpExec.front(), retExe);
            warpExec.pop();
            warpExec.push(andExe);
        }
        else
        {
            command += container.front();
            RShellExec *exe = new RShellExec(command.c_str());
            warpExec.push(exe);
        }
    }
    
    return warpExec;
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
        if (hashContainer.front()[0] = '"')
        {
            secondContainer.push(hashContainer.front());
            hashContainer.pop();
        }
        else
        {
            char *command = strdup(hashContainer.front());
            char *copy = strdup(hashContainer.front());
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
        }
    }

    while (secondContainer.size() != 0)
    {
        if (secondContainer.front()[0] = '"')
        {
            finalContainer.push(secondContainer.front());
            secondContainer.pop();
        }
        else
        {
            char *command = strdup(hashContainer.front());
            char *token = strtok(command, space);
            while (token)
            {
                secondContainer.push(token);
                token = strtok(NULL, delimiter);
            }
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
            ret += quoteContainer.front();
            quoteContainer.pop();
            while (quoteContainer.front() != "\"")
            {
                ret += quoteContainer.front();
                quoteContainer.pop();
            }
            char *charArray = strcpy(new char[ret.length() + 1], ret.c_str());
            tempContainer.push(charArray);
        }
    }

    // check hash symbol
    while (tempContainer.size() != 0)
    {
        if (tempContainer.front()[0] = '"')
        {
            hashContainer.push(tempContainer.front());
            tempContainer.pop();
            // continue;
        }
        else if (strchr(tempContainer.front(), '#'))
        {
            string ret = tempContainer.front();
            char *pos = strchr(tempContainer.front(), '#');
            ret = ret.substr(0, pos - tempContainer.front() + 1);
            char *cutToken = strcpy(new char[ret.length() + 1], ret.c_str());
            hashContainer.push(cutToken);
            break;
        }

        hashContainer.push(tempContainer.front());
        tempContainer.pop();
    }
    return hashContainer;
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