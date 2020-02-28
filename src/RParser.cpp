#include "../header/RParser.hpp"
#include <queue>
#include <stack>
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

RShellBase *RParser::warpCommand(stack<char *> opStack, stack<char *> statment)
{
    
}
// RShellBase *RParser::warpCommand(queue<char *> container)
// {
//     queue<RShellBase *> warpExec;
//     queue<char *> statment;
//     stack<char *> ope;

//     while (container.size() != 0)
//     {
//         char *tempPtr = strdup(container.front());
//         if (strchr(tempPtr, '&'))
//         {
//             container.pop();
//             string ret = "";
//             while (container.size() != 0 && !(container.front()[0] == '&' || container.front()[0] == '|' || container.front()[0] == ';'))
//             {
//                 tempPtr = strdup(container.front());
//                 ret += tempPtr;
//                 container.pop();
//                 if (container.size() != 0 && !(container.front()[0] == '&' || container.front()[0] == '|' || container.front()[0] == ';'))
//                 {
//                     ret += " ";
//                 }
//             }
//             RShellExec *retExe = new RShellExec(ret.c_str());
//             RAnd *andExe = new RAnd(warpExec.front(), retExe);
//             warpExec.pop();
//             warpExec.push(andExe);
//         }
//         else if (strchr(tempPtr, '|'))
//         {
//             container.pop();
//             string ret = "";
//             while (container.size() != 0 && !(container.front()[0] == '&' || container.front()[0] == '|' || container.front()[0] == ';'))
//             {
//                 tempPtr = strdup(container.front());
//                 ret += tempPtr;
//                 container.pop();
//                 if (container.size() != 0 && !(container.front()[0] == '&' || container.front()[0] == '|' || container.front()[0] == ';'))
//                 {
//                     ret += " ";
//                 }
//             }
//             RShellExec *retExe = new RShellExec(ret.c_str());
//             ROr *orExe = new ROr(warpExec.front(), retExe);
//             warpExec.pop();
//             warpExec.push(orExe);
//         }
//         else if (strchr(tempPtr, ';'))
//         {
//             container.pop();

//             string ret = "";
//             while (container.size() != 0 && !(container.front()[0] == '&' || container.front()[0] == '|' || container.front()[0] == ';'))
//             {
//                 tempPtr = strdup(container.front());
//                 ret += tempPtr;
//                 container.pop();
//                 if (container.size() != 0 && !(container.front()[0] == '&' || container.front()[0] == '|' || container.front()[0] == ';'))
//                 {
//                     ret += " ";
//                 }
//             }
//             RShellExec *retExe = new RShellExec(ret.c_str());
//             RSeparator *sepExe = new RSeparator(warpExec.front(), retExe);
//             warpExec.pop();
//             warpExec.push(sepExe);
//         }
//         else
//         {
//             string ret = "";
//             while (container.size() != 0 && !(container.front()[0] == '&' || container.front()[0] == '|' || container.front()[0] == ';'))
//             {
//                 tempPtr = strdup(container.front());
//                 ret += tempPtr;
//                 container.pop();
//                 if (container.size() != 0 && !(container.front()[0] == '&' || container.front()[0] == '|' || container.front()[0] == ';'))
//                 {
//                     ret += " ";
//                 }
//             }
//             RShellExec *exe = new RShellExec(ret.c_str());
//             warpExec.push(exe);
//         }
//     }

//     return warpExec.front();
// }

stack<char *> RParser::readStatement(string input)
{
    stack<char *> statement;
    int strLen = input.size();
    int prePos = 0;
    bool isQuote = false;
    string ret = "";
    for (int i = 0; i < strLen; i++)
    {
        if (input[i] == '"')
        {
            isQuote = !isQuote;
            // for (int j = i; j < strLen; j++)
            // {
            //     if (input[j] == '"')
            //     {
            //         // temp string for storage
            //         string temp = input.substr(i, j);
            //         // conversion between string and char* to store in statement container
            //         statement.push(&temp[0]);
            //         i = j;
            //         break;
            //     }
            // }
        }
        else if (isQuote == false)
        {
            if (input[i] == '&' && input[i + 1] == '&')
            {
                // temp string for storage
                string temp = input.substr(prePos, i - 1);
                // conversion between string and char* to store in statement container
                statement.push(&temp[0]);
                i++;
                prePos = i + 1;
            }
            else if (input[i] == '|' && input[i + 1] == '|')
            {
                // temp string for storage
                string temp = input.substr(prePos, i - 1);
                // conversion between string and char* to store in statement container
                statement.push(&temp[0]);
                i++;
                prePos = i + 1;
            }
            else if (input[i] == ';')
            {
                // temp string for storage
                string temp = input.substr(prePos, i - 1);
                // conversion between string and char* to store in statement container
                statement.push(&temp[0]);
                prePos = i + 1;
            }
            else if (input[i] == '(' || input[i] == ')')
            {
                if (input[i + 1] == '(' || input[i + 1] == ')')
                {
                    prePos = i + 2;
                    continue;
                }
                else
                {
                    string temp = input.substr(prePos, i - 1);
                    // conversion between string and char* to store in statement container
                    statement.push(&temp[0]);
                    prePos = i + 1;
                }
            }
        }
    }
    return statement;
}

stack<char *> RParser::readOp(string input)
{
    int strLen = input.size();
    bool inQuote = false;
    stack<char *> opStack;
    for (int i = 0; i < strLen; i++)
    {
        if (input[i] == '"')
        {
            inQuote = !inQuote;
        }

        if (inQuote == false)
        {

            if (input[i] == '&' && input[i + 1] == '&')
            {
                opStack.push("&&");
                i++;
            }
            else if (input[i] == '|' && input[i + 1] == '|')
            {
                opStack.push("||");
                i++;
            }
            else if (input[i] == ';')
            {
                opStack.push(";");
            }
            else if (input[i] == '(')
            {
                // reverse reading, so push )
                opStack.push(")");
            }
            else if (input[i] == ')')
            {
                // reverse reading, so push (
                opStack.push("(");
            }
        }
    }
    return opStack;
}

// stack<char *> RParser::readOp(queue<char *> hashContainer)
// {
//     stack<char *> opStack;
//     char delimiter[] = "&|;()";

//     // Add &,|,;
//     while (hashContainer.size() != 0)
//     {
//         char *tempPtr = strdup(hashContainer.front());
//         if (tempPtr[0] == '"')
//         {
//             hashContainer.pop();
//         }
//         else
//         {
//             char *command = strdup(tempPtr);
//             char *copy = strdup(tempPtr);
//             char *token = strtok(command, delimiter);
//             while (token)
//             {
//                 if (copy[token - command + strlen(token)] == '&')
//                 {
//                     opStack.push("&&");
//                 }
//                 else if (copy[token - command + strlen(token)] == '|')
//                 {
//                     opStack.push("||");
//                 }
//                 else if (copy[token - command + strlen(token)] == ';')
//                 {
//                     opStack.push(";");
//                 }
//                 else if (copy[token - command + strlen(token)] == '(')
//                 {
//                     // reverse reading, so push )
//                     opStack.push(")");
//                 }
//                 else if (copy[token - command + strlen(token)] == ')')
//                 {
//                     // reverse reading, so push (
//                     opStack.push("(");
//                 }
//                 token = strtok(NULL, delimiter);
//             }
//             hashContainer.pop();
//         }
//     }

//     return opStack;
// }

stack<char *> RParser::readInput(queue<char *> hashContainer)
{
    stack<char *> statementStack;
    char delimiter[] = "&|;()";

    // Add &,|,;
    while (hashContainer.size() != 0)
    {
        char *tempPtr = strdup(hashContainer.front());
        string ret = "";
        if (tempPtr[0] == '"')
        {
            ret += tempPtr;
            hashContainer.pop();
        }
        else
        {
            char *command = strdup(tempPtr);
            char *copy = strdup(tempPtr);
            char *token = strtok(command, delimiter);

            while (token)
            {
                ret += token;
            }
            hashContainer.pop();
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
