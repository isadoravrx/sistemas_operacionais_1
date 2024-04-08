#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

int i;
sem_t semaforo;

void thread_P0(void* argthread){
    sem_wait(&semaforo); 
    for(i=0; i<10;i++){
        printf("%d\n", i);
    }
    sem_post(&semaforo);
    pthread_exit(0);
}

void thread_P1(void* argthread){
    sem_wait(&semaforo); 
    for(i=10; i<=20;i++){
        printf("%d\n", i);
    }
    sem_post(&semaforo);
    pthread_exit(0);
}

int main(){
    sem_init(&semaforo, 0, 1); 
    pthread_t t1, t2;

    pthread_create(&t1, NULL, (void*)thread_P0, NULL);
    pthread_create(&t2, NULL, (void*)thread_P1, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    
    sem_destroy(&semaforo); 
    return 0;
}