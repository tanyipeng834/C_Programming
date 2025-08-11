#include<stdlib.h>
#include<stdio.h>
#include <unistd.h>
#include <pthread.h>
#include<sys/time.h>
#include <assert.h>


typedef struct __counter_t{
    int counter;
    pthread_mutex_t lock;


}counter_t;

void* counter(void * args)
{   
    counter_t * counter = (counter_t *) args;
    while(1){
        pthread_mutex_lock(&counter->lock);
        if (counter->counter>=1e6){
        pthread_mutex_unlock(&counter->lock);
        break;
        }
        counter->counter++;

        pthread_mutex_unlock(&counter->lock);
    }
    printf("Thread Done \n");
    return NULL;


}
 
void init(counter_t* c)
{
    int rc = pthread_mutex_init(&c->lock,NULL);
    assert(rc ==0);
    c->counter =0;





}





int main(int argc, char*argv[])
{

    struct timeval start_time,end_time;
    
    int rc = gettimeofday(&start_time,NULL);  
    assert(rc==0);

    long nprocs = sysconf(_SC_NPROCESSORS_ONLN);   // number of online CPUs
    long nprocs_conf = sysconf(_SC_NPROCESSORS_CONF); // total co
    printf("Configured CPUs: %ld\n", nprocs_conf);
    printf("Online CPUs:     %ld\n", nprocs);
    size_t num_threads = 10000;
    pthread_t threads[num_threads];
    counter_t c;
    init(&c);
    for (int i=0;i<num_threads;i++)
    {   
         int rc =pthread_create(&threads[i],NULL,counter,&c);
         assert(rc ==0);

    }


    for (int i =0;i<num_threads;i++){
        pthread_join(threads[i],NULL);
    }

rc = gettimeofday(&end_time,NULL);
assert(rc ==0);

long seconds  = end_time.tv_sec  - start_time.tv_sec;
    long useconds = end_time.tv_usec - start_time.tv_usec;
    if (useconds < 0) {
        seconds--;
        useconds += 1000000;
    }
    long total_microseconds = seconds * 1000000 + useconds;

    printf("Final counter value: %d\n", c.counter);
    printf("Total time taken: %ld microseconds (%.6f seconds)\n",
           total_microseconds, total_microseconds / 1e6);


    
    


}