#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(){
    pid_t pid;
    int ends[2];

    if(pipe(ends) == -1)
    {
        printf("pipe error!\n");
        return (0);
    }
    pid = fork();
    if(pid == -1)
    {
        printf("fork error!\n");
        return (0);
    }
    else if (pid == 0)
    {
        write(ends[1], "oii paii!!!!!, serio muito bom ser seu filho!\n", 47);
        close(ends[1]);
        close(ends[0]);
    }
    else if (pid > 0)
    {
        char text[200];
        int status;

        waitpid(-1, &status, 0);
        read(ends[0], &text, 100);
        printf("recebi esse bela mensagem de meu filho: %s\n", text);
        close(ends[1]);
        close(ends[0]);
    }
}