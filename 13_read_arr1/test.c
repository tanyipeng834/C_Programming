#include <stdio.h>
#include <stdlib.h>


int main(void) {
  int anArray[] = {5,16,33,99};
  int * p = anArray;
  // will prin the first element , hence 5
  printf("*p = %d\n", *p);
  // Incerement the pointer to the enxt element
  p++;
  // Will print 16 which is the second element
  printf("Now *p = %d\n", *p);

// Pointer to the 3rd element
  int * q = &anArray[3];
  // pointer to the pointer of the 3rd element
  int ** x = &q;
  // fourth element of the array change to 12
  **x = 12;

  *x = p;
  // 2nd elemnt of the array will change to the number 42
  **x = 42;
  // No Change as this is out of bounds
  q[1] = 9;
  for (int i =0; i < 4; i++){
    // This will print 5,42,9,12
    printf("anArray[%d] = %d\n",i, anArray[i]);
  }
  return EXIT_SUCCESS;
}
