#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>


int main(int argc, char*argv[])
{
    int rc = fork();
    if(rc<0){
        printf("The fork has failed");


    }
    else if (rc==0){
        // Child process
        printf("Child process\n");
        close(STDOUT_FILENO);
        printf("Hello, I am here after closing Standard output");


    }

    else
    {
        printf("I am the parent process");

    }


}