#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{
    int pid;
    pid_t child[3];
    int ends[2];

    if(pipe(ends) == -1)
    {
        printf("pipe errors");
        return 1;
    }
    for (int i = 0; i < 3; i++)
    {
        child[i] = fork();

        if(child[i] == 0)
        {
            printf("eu sou uma criança numro %d e meu pid é %d\n", i, getpid()); 
            return(1);
        }
    }

    for(int i = 0; i < 3; i++)
    {
        waitpid(child[i], NULL, 0);
        printf("esperando criança de pid %d\n", child[i]);
    }
    printf("eu sou el pai!\n");
}