#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char* argv[])
{
    int rc = fork();
    int fd = open("./p4.output", O_CREAT|O_WRONLY|O_TRUNC,S_IRWXU);

    if (rc<0){
        fprintf(stderr,"The fork has failed");
    }
    else if (rc==0){
        // Child process
        printf("Child process writing");
        dprintf(fd,"Child here");

    }
    else{
        printf("Parent process wriring");
        dprintf(fd,"parent here");

    }


}