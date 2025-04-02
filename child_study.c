#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>

#ifndef CHILD_EXIT_CODE
# define CHILD_EXIT_CODE 42
#endif

// Define a macro for the expected exit status
#define EXPECTED_CODE 42

void    child_routine(pid_t pid)
{
    printf(" sou a criança e meu pid : %d\n" , pid);
	printf("\e[36mChild: Exiting with exit code %d.\e[0m\n",
        CHILD_EXIT_CODE);
    exit(CHILD_EXIT_CODE);
}
void    father_routine(pid_t pid)
{
    int status;

    printf(" sou o adulto e o pid que recebi foi esse: %d\n" , pid);
    printf("esperando a criança! %d\n" , pid);
    waitpid(pid, &status, 0);
    if(WIFEXITED(status))
    {
        printf("o programa foi finalizado!%d\n" , WIFEXITED(status));
        if(WEXITSTATUS(status) == EXPECTED_CODE)
            printf("isso era o que eu esperava!\n");
        else
            printf("isso não era oq eu esperava\n");
    }
}
int main()
{
    pid_t pid;

    pid = fork();
    if(pid > 0)
    {
        father_routine(pid);
    }
    else if (pid == 0)
    {
        child_routine(pid);
    }
    return (0);
}