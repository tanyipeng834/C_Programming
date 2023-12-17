#include <stdio.h>
#include <string.h>


 void swap(int *x , int *y);
int main() {
    // Print the message to the console

    /*
    I have to do something in the code
    */

   int a = 3;
   int b =4;
   swap(&a,&b);
   printf("a = %d, b = %d",a,b);



}

void swap(int *x , int *y){
    int temp =*x;
    *x = *y;
    *y = temp;
}
