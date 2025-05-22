#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>

int main (int argc ,char* argv[])

{
    printf("hello (pid:%d)\n",(int)getpid());
    int rc = fork();
    if (rc <0){
        fprintf(stderr,"fork failed\n");
        // Exit code 1 if fork have failed
        exit(1);
    }
    else if (rc ==0){
        printf("child (pid:%d)\n", (int)getpid());

    }
    else{
        printf("parent of %d  (pid:%d)\n",rc,getpid());
    }


}