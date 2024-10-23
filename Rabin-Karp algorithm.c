#include <stdio.h>
#include <string.h>

#define d 256
#define q 101

void rabinKarp(char *pattern, char *text) {
    int M = strlen(pattern);
    int N = strlen(text);
    int i, j;
    int p = 0;
    int t = 0;
    int h = 1;

    for (i = 0; i < M - 1; i++) {
        h = (h * d) % q;
    }

    for (i = 0; i < M; i++) {
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }

    for (i = 0; i <= N - M; i++) {
        if (p == t) {
            for (j = 0; j < M; j++) {
                if (text[i + j] != pattern[j]) {
                    break;
                }
            }
            if (j == M) {
                printf("Pattern found at index %d\n", i);
            }
        }

        if (i < N - M) {
            t = (d * (t - text[i] * h) + text[i + M]) % q;
            if (t < 0) {
                t = t + q;
            }
        }
    }
}

int main() {
    char text[] = "coding in c is fun";
    char pattern[] = "fun";
    rabinKarp(pattern, text);
    return 0;
}
