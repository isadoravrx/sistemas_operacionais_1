#include <stdio.h>
#include <pthread.h>

int i;
pthread_mutex_t mutex;

void thread_P0(void* argcthread){
    pthread_mutex_lock(&mutex);
        for(i=0; i<10; i++){
            printf("%d\n", i);
        }
    pthread_mutex_unlock(&mutex);
    pthread_exit(0);
}

void thread_P1(void* argcthread){
    pthread_mutex_lock(&mutex);
        for(i=10; i<20; i++){
            printf("%d\n", i);
        }
    pthread_mutex_unlock(&mutex);
    pthread_exit(0);
}

int main(){
    pthread_mutex_init(&mutex, NULL);
    pthread_t t0, t1;

    pthread_create(&t0, NULL, (void*)thread_P0, NULL);
    pthread_create(&t1, NULL, (void*)thread_P1, NULL);
    
    pthread_join(t0, NULL);
    pthread_join(t1, NULL);

    pthread_mutex_destroy(&mutex);

    return 0;
}