#include <stdio.h>

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to heapify the array
void heapify(int array[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // Find the largest element among the root and its children
    if (left < n && array[left] > array[largest])
        largest = left;

    if (right < n && array[right] > array[largest])
        largest = right;

    // If the root is not the largest element, swap it with the largest element
    if (largest != i) {
        swap(&array[i], &array[largest]);
        heapify(array, n, largest);
    }
}

// Function to build a max heap
void buildMaxHeap(int array[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(array, n, i);
}

// Function to extract the maximum element from the heap
int extractMax(int array[], int *n) {
    int max = array[0];
    array[0] = array[*n - 1];
    *n = *n - 1;
    heapify(array, *n, 0);
    return max;
}

// Function to insert an element into the heap
void insert(int array[], int *n, int capacity, int key) {
    if (*n == capacity) {
        printf("Heap is full\n");
        return;
    }

    array[*n] = key;
    *n = *n + 1;

    int i = *n - 1;
    while (i != 0 && array[(i - 1) / 2] < array[i]) {
        swap(&array[i], &array[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Function to print the heap
void printHeap(int array[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", array[i]);
    printf("\n");
}

int main() {
    int array[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(array) / sizeof(array[0]);
    int capacity = 10;

    buildMaxHeap(array, n);
    printf("Max heap: ");
    printHeap(array, n);

    insert(array, &n, capacity, 15);
    printf("After inserting 15: ");
    printHeap(array, n);

    printf("Extracted max element: %d\n", extractMax(array, &n));
    printf("After extracting max element: ");
    printHeap(array, n);

    return 0;
}