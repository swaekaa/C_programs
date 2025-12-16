#include <stdio.h>
#include <stdlib.h>

void bucketSort(float arr[], int n) {
    // Create n empty buckets
    float *buckets[n];
    int bucketSizes[n];

    for (int i = 0; i < n; i++) {
        buckets[i] = (float *)malloc(n * sizeof(float));
        bucketSizes[i] = 0;
    }

    // Place array elements into their respective buckets
    for (int i = 0; i < n; i++) {
        int bucketIndex = n * arr[i];
        buckets[bucketIndex][bucketSizes[bucketIndex]++] = arr[i];
    }

    // Sort individual buckets
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < bucketSizes[i] - 1; j++) {
            for (int k = 0; k < bucketSizes[i] - j - 1; k++) {
                if (buckets[i][k] > buckets[i][k + 1]) {
                    float temp = buckets[i][k];
                    buckets[i][k] = buckets[i][k + 1];
                    buckets[i][k + 1] = temp;
                }
            }
        }
    }

    // Concatenate all buckets into the original array
    int index = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < bucketSizes[i]; j++) {
            arr[index++] = buckets[i][j];
        }
    }

    // Free allocated memory
    for (int i = 0; i < n; i++) {
        free(buckets[i]);
    }
}

int main() {
    float arr[] = {0.897, 0.565, 0.656, 0.123, 0.665, 0.343};
    int n = sizeof(arr) / sizeof(arr[0]);

    bucketSort(arr, n);

    for (int i = 0; i < n; i++) {
        printf("%f ", arr[i]);
    }
    printf("\n");

    return 0;
}
