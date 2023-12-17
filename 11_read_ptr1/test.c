#include <stdio.h>
#include <stdlib.h>

void g(int x, int * y,FILE *file) {
  fprintf(file, "In g, x = %d, *y = %d\n", x, *y);
  printf("In g, x = %d, *y = %d\n", x, *y);
  x++;
  *y = *y - x;
  y = &x;
}

void f(int * a, int b,FILE *file) {
  fprintf(file, "In f, *a = %d, b = %d\n", *a, b);
  printf("In f, *a = %d, b = %d\n", *a, b);
  *a += b;
  b *= 2;
  g(*a, &b,file);
  printf("Back in f, *a = %d, b = %d\n", *a, b);
  fprintf(file, "Back in f, *a = %d, b = %d\n", *a, b);
  
}


int main(void) {
  FILE *file = fopen("answer.txt", "w");


  int x = 3;
  int y = 4;
  f(&x, y,file);
  fprintf(file, "In main: x = %d, y = %d\n", x, y);
  printf("In main: x = %d, y = %d\n", x, y);
  return EXIT_SUCCESS;
}
