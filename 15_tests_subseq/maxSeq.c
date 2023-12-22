#include <stdio.h>
#include <stdlib.h>

size_t maxSeq(int *array, size_t n){
    if (n==0){
        return 0;
    }
    if (n==1){
        return 1;
    }

    size_t maxSeq = 0;
    size_t curentSeq = 1;
    for (int i =0; i <n-1; i++){
        if(array[i]>array[i+1]){
            curentSeq++;
        
        }
        else{
            if(curentSeq>maxSeq){
                maxSeq = curentSeq;
            }

            curentSeq =1;
        }
    }

return maxSeq;

}