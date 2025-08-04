#include<stdlib.h>
#include<stdio.h>
#include<pthread.h>


void * print_thread(void* arg){
    printf("%s\n",(char *)arg);
    return NULL;

}

int main(int argc, char*argv[]){

    pthread_t p1 ,p2;
    printf("Starting Main Thread here\n");
    pthread_create(&p1,NULL,print_thread,"Thread 1");
    pthread_create(&p2,NULL,print_thread,"Thread 2");
    pthread_join(p1,NULL);
    pthread_join(p2,NULL);
    return 0;




}