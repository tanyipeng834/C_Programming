#include <stdio.h>
#include <stdlib.h>

int* addEntry(int x, int*arr);

int main(int argc ,char* argv[])
{

    int * arr = malloc(2*sizeof(int));
    if(arr ==NULL){
        perror("Memory allocation has failed for array");
        return 1;

    }
    arr[0] =1;
    arr[1]=1;
int * newArr = addEntry(2,arr);
if(newArr==NULL){
    perror("Memory allocation has failed");
    return 1;
}
for(int i=0;i<3;i++){
    printf("%d",newArr[i]);
}
free(newArr);

   
    


}

int* addEntry(int x, int* arr){
    arr= realloc(arr,3*sizeof(int));
    if(arr==NULL){
        perror("Memory allocation has failed");
        exit(1);
    }
    return arr;


}