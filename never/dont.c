#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Merge function for Merge Sort
void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    // Copy data to temp arrays
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    i = 0; 
    j = 0; 
    k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    free(L);
    free(R);
}

// Merge Sort function
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    printf("Starting...\n");

    clock_t start_time, allocation_time, pre_sort_time, post_sort_time;
    size_t size = 1024;  
    int *ptr = NULL;
    int *last_successful = NULL;

    start_time = clock();  // Start timing

    // Find the maximum memory allocation
    while (1) {
        ptr = (int*) malloc(size * sizeof(int));
        if (ptr == NULL) {
            break;
        }
        last_successful = ptr;
        free(ptr);
        size *= 2;
    }

    // Reduce step size using binary search approach
    size /= 2;
    while (size > 0) {
        ptr = (int*) malloc(size * sizeof(int));
        if (ptr == NULL) {
            size /= 2;
        } else {
            last_successful = ptr;
            break;
        }
    }

    allocation_time = clock();  // Time after memory allocation

    printf("The Size of the Array: %d ",size);

    // Fill array with random values
    srand(time(NULL));
    for (size_t i = 0; i < size; i++) {
        last_successful[i] = rand();
    }

    pre_sort_time = clock();  // Time before sorting

    // Perform Merge Sort
    mergeSort(last_successful, 0, size - 1);

    post_sort_time = clock();  // Time after sorting

    // Print execution times
    printf("Largest successfully allocated memory: %lu bytes\n", size * sizeof(int));
    printf("Time taken for allocation: %.6f seconds\n", (double)(allocation_time - start_time) / CLOCKS_PER_SEC);
    printf("Time taken for sorting: %.6f seconds\n", (double)(post_sort_time - pre_sort_time) / CLOCKS_PER_SEC);
    printf("Total execution time: %.6f seconds\n", (double)(post_sort_time - start_time) / CLOCKS_PER_SEC);

    free(last_successful);  // Free allocated memory

    return 0;
}