#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(){
    int ends[2];
    pid_t child[3];

    if(pipe(ends) == -1)
    {
        printf("deu ruim no pipe fi");
        return (1);
    }
    for (int i = 0; i < 3; i++)
    {
        child[i] = fork();

        if(child[i] == 0)
        {
            close(ends[0]);
            write(ends[1], "oi pai eu sou o filho" , 21);
            write(ends[1], )
        }

    }
}