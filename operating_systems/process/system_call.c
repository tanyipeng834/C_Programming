#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main (int argc, char* argv[])
{
    int rc = fork();
    int x = 100;
    if(rc<0){
        fprintf(stderr,"fork failed \n");
        

    }
    else if (rc==0)
    {
        printf("In Child Process: %d",x);
        x = 10;
        printf("In Child Process after modification: %d",x)


    }
    else
    {
        printf("In Parent Process")
        x =200;


    }
    
    printf("the new number is %d",x);

}