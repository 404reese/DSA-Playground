#include <stdio.h>
#include <stdbool.h>
#include <pthread.h>

#define N 2

int turn;
bool flag[N];

void critical_section(int id) {
    printf("Process %d is in critical section\n", id);
}

void *process(void *arg) {
    int id = *((int *)arg);
    int other = 1 - id;

    while (1) {
        flag[id] = true;
        turn = other;
        while (flag[other] && turn == other) {
        }

        critical_section(id);

        flag[id] = false;
    }
}

int main() {
    pthread_t threads[N];
    int ids[N] = {0, 1};

    flag[0] = flag[1] = false;
    turn = 0;

    for (int i = 0; i < N; i++) {
        pthread_create(&threads[i], NULL, process, &ids[i]);
    }

    for (int i = 0; i < N; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}

