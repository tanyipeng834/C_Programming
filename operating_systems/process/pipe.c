#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char* argv[])
{
    int fd[2];
    if (pipe(fd) ==-1){
        printf("Pipe Creation has failed");

    }
    pid_t pid1 = fork();
    if (pid1<0){
        printf("Fork of process 1 has failed");
    }
    else if(pid1==0){
        // Close the read end
        close(fd[0]);

        char* message = "hello, i am yi peng";
        // Write to the write end of the pipe
        write(fd[1],message,strlen(message)+1);
        close(fd[1]);


    }

    pid_t pid2 = fork();
    if (pid2<0)
    {
        printf("Fork of process 2 has failed");

    }
    else if(pid2==0)
    {
        close(fd[1]);
        char buffer[100];
        read(fd[0],buffer,sizeof(buffer));
        close(fd[0]);
        printf("%s",buffer);







    }

    
    

}