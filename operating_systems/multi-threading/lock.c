#include<stdlib.h>
#include<stdio.h>
#include<pthread.h>

typedef struct __counter_t{
int counter;
pthread_mutex_t lock;
} counter_t;

void* increment_counter(void * arg){

    counter_t * c = (counter_t*) arg;


    for(int i =0;i<1e7;i++){
        pthread_mutex_lock(&c->lock);
        c->counter+=1;
        pthread_mutex_unlock(&c->lock);
    }
    printf("Thread Done\n");
    return NULL;


}

void init(counter_t* c ){
    int rc = pthread_mutex_init(&c->lock,NULL);
    assert(rc ==0);
    
    c->counter =0;

}

int main(int argc, char*argv[])

{

    pthread_t p1,p2;
    pthread_mutex_t lock;
    counter_t c;
    init(&c);
    pthread_create(&p1,NULL,increment_counter,&c);
    pthread_create(&p2,NULL,increment_counter,&c);
    pthread_join(p1,NULL);
    pthread_join(p2,NULL);
    printf("Value is %d",c.counter);


   













}