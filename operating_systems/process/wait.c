#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main(int argc, char* argv[]){
    pid_t rc = fork();

    if (rc<0){
        fprintf(stderr,"Forking the process has failed \n");
    }
    else if (rc==0){
        printf("Children process \n");


    }
    else
    {
       
        int rc_wait = wait(NULL);
        printf("Parent process");



    }
}