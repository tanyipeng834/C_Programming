#include <stdio.h>
#include <stdlib.h>

int main (void)
{
    int *array = (int*)malloc(3 *sizeof(int));
    if(array ==NULL){
        // Malloc has failed
        return 1;
    }
    for(int i=0; i<3;i++){
        array[i] =i;
    }

    for(int i =0;i<3;i++){
        printf("%d\n",array[i]);
    }
    int *biggerArray = (int*)malloc(4* sizeof(int));
    if(biggerArray ==NULL){
        // Free the array ontop since memory allocation has failed
        free(array);
        return 1;
    }
    for(int i =0;i<3;i++){
        *(biggerArray+i) = array[i];
    }
    *(biggerArray+3) = 3;

    for(int i =0;i<4;i++){
        printf("%d\n",biggerArray[i]);
    }




}