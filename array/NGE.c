#include <stdio.h>

void nextGreaterElement(int arr[], int n) {
    // Iterate over each element
    for (int i = 0; i < n; i++) {
        int next = -1;  // Initialize the next greater element as -1

        // Check elements to the right of arr[i]
        for (int j = i + 1; j < n; j++) {
            if (arr[j] > arr[i]) {
                next = arr[j];  // First greater element found
                break;
            }
        }

        // Print the next greater element for arr[i]
        printf("%d ", next);
    }
    printf("\n");
}

int main() {
    int n;
    // Input the number of elements
    scanf("%d", &n);
    
    int arr[n];
    // Input the array elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Find and print the next greater elements
    nextGreaterElement(arr, n);
    
    return 0;
}
