#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NSTRS 3
int main(void) {
  const char * strs[NSTRS] = {"apple", "bannana", "carrot"};
  
  for (int i = 0; i < NSTRS; i++) {
    // Search in the String for the first occurence of 'a'


    const char * a = strchr(strs[i], 'a');
    a++;
    // Print p value, n value , then the r value
    printf("%c\n", *a);
    //Print the value l , then a value , then the o value
    printf("%c\n", a[2]);

    

    
    a = strstr(strs[i], "nana");
    if (a != NULL) {
      // Bannanoto has nana  3 characters into it !
      printf("%s has %s %ld characters into it!\n", strs[i], a, a - strs[i]);
    }
  }


  const char * ptr = strs[2];
  while (*ptr != '\0') {

    char x = *ptr + 3;
    //print f ,d,u,u,r ,w
    printf("%c", x);
    ptr++;
  }
  printf("\n");
  return EXIT_SUCCESS;
}
