#include <stdio.h>
#include <stdlib.h>

void swap(int* x, int*y );
int main (){
    int x = 1 ;
    int y = 2;
    printf("value of x is %d\n",x);
    printf("value of y is %d\n",y);
    swap(&x,&y);
    printf("After Swap \n");
    printf("value of x is %d\n",x);
    printf("value of y is %d\n",y);





}

void swap(int *x,int*y){
    int tmp = *x;
    *x=*y;
    *y=tmp;

}

