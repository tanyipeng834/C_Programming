#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    printf("location of code:%p\n",main);
    printf("location of heap:%p\n" ,malloc(5));
    int x =3;
    printf("location of stack:%p\n",&x);


}
