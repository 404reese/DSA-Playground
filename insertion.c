#include <stdio.h>

void insert(int arr[], int *n, int key) {
    int i;
    for (i = *n - 1; (i >= 0 && arr[i] > key); i--) {
        arr[i + 1] = arr[i];
    }
    arr[i + 1] = key;
    (*n)++;
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[100] = {1, 3, 5, 7, 9};
    int n = 5;
    int key;

    printf("Current array: ");
    printArray(arr, n);
    
    printf("Enter a number to insert: ");
    scanf("%d", &key);

    insert(arr, &n, key);

    printf("Array after insertion: ");
    printArray(arr, n);

    return 0;
}
