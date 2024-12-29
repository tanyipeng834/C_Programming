#include <stdio.h>




int main(){

int arr[2][3] ={{2,3,4}
,{6,7,8}};
// This is an pointer to an array of 3 elements;
int (*parr)[3]; 

parr = arr;

for(int i =0; i<2;i++){
    for (int j=0;j<3;j++)
    {
        printf("element is %d \n",*(*(parr+i)+j));


    }

}


}