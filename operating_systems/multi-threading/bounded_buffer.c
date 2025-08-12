#include<stdlib.h>
#include<stdio.h>
#include <pthread.h>
#include<assert.h>

#define MAX 10
#define loops 10

int buffer[MAX];
int fill_ptr =0;
int use_ptr =0;
int count =0;


void put(int value)
{
    buffer[fill_ptr] = value;
    
    fill_ptr = (fill_ptr +1) % MAX;
    count+=1;


}

int get(){
    int tmp = buffer[use_ptr];
    use_ptr = (use_ptr +1 ) % MAX;
    count -=1;
    return tmp;
}

pthread_cond_t empty,fill;
pthread_mutex_t mutex;

void * producer (void * arg)
{
    for (int i =0;i<loops;i++){

        pthread_mutex_lock(&mutex);

        while(count==MAX)
            pthread_cond_wait(&empty,&mutex);
        
        put(i);
        pthread_cond_signal(&fill);
        pthread_mutex_unlock(&mutex);

        

    }

}

void * consumer(void * args){
    for (int i =0;i<loops;i++){
        pthread_mutex_lock(&mutex);
        while(count==0)
            pthread_cond_wait(&fill,&mutex);
        int tmp = get();
        pthread_cond_signal(&empty);
        pthread_mutex_unlock(&mutex);
        printf("%d\n", tmp);
    }
    

}

int main(int agrc , char* argv []){
   pthread_t tp, tc;

    int rc = pthread_create(&tp, NULL, producer, NULL);
    assert(rc == 0);
    rc = pthread_create(&tc, NULL, consumer, NULL);
    assert(rc == 0);

    pthread_join(tp, NULL);
    pthread_join(tc, NULL);
    return 0;
}






