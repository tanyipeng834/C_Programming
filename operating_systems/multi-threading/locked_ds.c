#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>
#include<assert.h>




int main(int agrc, char*argv[]){
struct timeval current_time,end_time;
int rc = gettimeofday(&current_time,NULL);
assert(rc==0);

printf("Seconds: %ld\n", (long)current_time.tv_sec);
 printf("Microseconds: %ld\n", (long)current_time.tv_usec);
int counter =0;
for (int i =0;i<1e7;i++){
counter +=1;

}
rc = gettimeofday(&end_time,NULL);
assert(rc ==0);
printf("Seconds: %ld\n", (long)end_time.tv_sec);
printf("Microseconds: %ld\n", (long)end_time.tv_usec);

}





