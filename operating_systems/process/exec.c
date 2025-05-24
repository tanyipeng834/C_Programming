#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>

int main (int argc, char* argv[])
{
    int rc = fork();
    printf("%d",rc);
    if(rc<0)
    {
        printf("The fork has failed");

    }
    else if (rc==0){
        // child process // it would
        char* args[] ={"ls", NULL};
        printf("called the ls executable");
        execv("/bin/ls",args);
        



    }
    else{
        
        int status;
        printf("parent process\n");
        int rc_wait = waitpid(rc,&status,0);
        printf("Status: %d\n", status);
        printf("rc_wait is %d\n",rc_wait);
        
        

    }
    

}