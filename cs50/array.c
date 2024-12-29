#include <stdio.h>

int sumOfElements(int* array,int size);

int main()
{
    int array[] ={1,2,3,4,5};

    int size = sizeof(array)/sizeof(array[0]);
    int result = sumOfElements(array,size);
    printf("%d", result);





    
}



int sumOfElements(int * array, int size)

{
    int sum =0;
    for(int i=0;i<size;i++){
        sum+= *(array+i);

    }
    return sum;


}

