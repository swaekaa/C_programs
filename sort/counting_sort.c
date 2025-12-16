
#include <stdio.h>
#include <stdlib.h>

void countingSort(int arr[], int n, int maxElement) {
    int count[maxElement + 1];
    for (int i = 0; i <= maxElement; i++) {
        count[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    for (int i = 1; i <= maxElement; i++) {
        count[i] += count[i - 1];
    }

    int output[n];
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

int main() {
    int arr[] = {1,2,3,4,3,2,3,4,3,3,3,2,1,2,3,4,4,2,1,2,3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int maxElement = 8;

    countingSort(arr, n, maxElement);

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
