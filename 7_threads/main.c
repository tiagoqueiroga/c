#include <stdio.h>
#include <pthread.h>
#include <stdlib.h> 
#include <pthread.h> 
#include <time.h>

#define MAX 10000000 // 10 millions

void *do_sum(void *value)
{
    long sum = 0;
    long *add = (long *) (value);

    for(long i =0; i < MAX; i++)
        sum += *add;

    return NULL;
}


int main(){

    clock_t t;

    t = clock();
    
    long value1 = 1;
    
    pthread_t thread1;

    pthread_create(&thread1,NULL,do_sum,(void*) &value1);
    
    pthread_join(thread1,NULL);

    t = clock() - t;

    double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds 

    printf("program took %f seconds to execute \n", time_taken); 
    
    return 0;
}
