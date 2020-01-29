#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/wait.h>
#include <iostream>

using namespace std;
int ExecTest()
{
   pid_t pid = fork();
   int status;

   if (pid == -1)
   {
      exit(EXIT_FAILURE);
   }
   else if (pid == 0)
   {
      char *argv_list[] = {"./helloworld", NULL};
      execvp(argv_list[0], argv_list);
      exit(0);
   }

   waitpid(pid, &status, 0);
   cout << "Hello I'm parent!" << endl;
   
   return 0;
}

int main()
{
   ExecTest();
   return 0;
}