#include<stdio.h>
#include<stdlib.h>

int main(int argc , char* argv[]){
    if (argc!=2){
        printf("Usage: %s <number of bytes> \n",argv[0]);
        exit(1);
        
    }
    int size =atoi(argv[1]);
    // Take into account megabyte which is 2^20
    char* charArray = (char *)malloc(size*1024*1024);
    if(charArray==NULL){
        perror("Malloc has failed");
        exit(1);
    }
    while(1){
        for(int i =0;i<size;i++){
            charArray[i]++;
        }


    }
    free(charArray);
    return 0;

}