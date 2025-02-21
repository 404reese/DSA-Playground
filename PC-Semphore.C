#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define BUFFER_SIZE 5
int buffer[BUFFER_SIZE];
int in = 0;
int out = 0;

sem_t empty;
sem_t full;
pthread_mutex_t mutex;

void* producer(void *param) {
    int item;
    while (1) {
        sleep(1); // chill, then make something
        item = rand() % 100;
        sem_wait(&empty); // wait for free spot
        pthread_mutex_lock(&mutex); // lock it up
        buffer[in] = item;
        printf("Producer dropped %d at %d\n", item, in);
        in = (in + 1) % BUFFER_SIZE;
        pthread_mutex_unlock(&mutex); // free up
        sem_post(&full); // signal there's something
    }
    pthread_exit(0);
}

void* consumer(void *param) {
    int item;
    while (1) {
        sem_wait(&full); // wait for something to munch on
        pthread_mutex_lock(&mutex); // lock the stash
        item = buffer[out];
        printf("Consumer grabbed %d from %d\n", item, out);
        out = (out + 1) % BUFFER_SIZE;
        pthread_mutex_unlock(&mutex); // done, unlock it
        sem_post(&empty); // one free spot now
        sleep(2); // take a breather
    }
    pthread_exit(0);
}

int main() {
    pthread_t prod_tid, cons_tid;
    sem_init(&empty, 0, BUFFER_SIZE); // all spots free
    sem_init(&full, 0, 0); // nothing there initially
    pthread_mutex_init(&mutex, NULL);

    pthread_create(&prod_tid, NULL, producer, NULL);
    pthread_create(&cons_tid, NULL, consumer, NULL);

    pthread_join(prod_tid, NULL);
    pthread_join(cons_tid, NULL);

    sem_destroy(&empty);
    sem_destroy(&full);
    pthread_mutex_destroy(&mutex);
    return 0;
}
