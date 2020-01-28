#include <iostream>
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>

using namespace std;

int ExecTest()
{
    char *args[] = {"./helloworld", NULL};
    execvp(args[0], args);
    return 0;
}