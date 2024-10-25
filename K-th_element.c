#include <stdio.h>

int findKth(int arr1[], int size1, int arr2[], int size2, int k) {
    if (size1 > size2) {
        return findKth(arr2, size2, arr1, size1, k);
    }
    if (size1 == 0) {
        return arr2[k - 1];
    }
    if (k == 1) {
        return arr1[0] < arr2[0] ? arr1[0] : arr2[0];
    }

    int index1 = (size1 < k / 2) ? size1 : k / 2;
    int index2 = k - index1;

    if (arr1[index1 - 1] < arr2[index2 - 1]) {
        return findKth(arr1 + index1, size1 - index1, arr2, size2, k - index1);
    } else {
        return findKth(arr1, size1, arr2 + index2, size2 - index2, k - index2);
    }
}

int main() {
    int arr1[] = {2, 3, 6, 7, 9};
    int arr2[] = {1, 4, 8, 10};
    int k = 5;

    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    int result = findKth(arr1, size1, arr2, size2, k);
    printf("The %d-th smallest element is %d\n", k, result);

    return 0;
}
