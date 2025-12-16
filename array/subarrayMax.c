// using Kadane's Algorithm, to slove this program

#include <stdio.h>
#include <limits.h>

int printmaxsub(int arr[], int n)
{
    int currentSum;
    int maxSum=currentSum=arr[0];
    
    
    for(int i=1;i<n;i++)
    {
        if(arr[i]>currentSum+arr[i])
        {
            currentSum=arr[i];
            
        }
        else
        {
            currentSum+=arr[i];
        }
        if(currentSum>maxSum)
        {
            maxSum=currentSum;
            
        }
    }
    
   return maxSum;
    
    
}

int main(void) 
{
	// your code goes here
	int t;
	scanf("%d",&t);
	

	while(t--)
	{
	    int n;
	    scanf("%d",&n);
	    int arr[n];
	    
	    for(int i=0;i<n;i++)
	    scanf("%d",&arr[i]);
	    
	    printf("%d\n",printmaxsub(arr,n));
	    
	    
	}
	

}


/*
the same program can be done without kadane's algorithm

#include <stdio.h>

void subarray(int n, int a[]) {
    int max = a[0];  // Initialize max to the first element of the array
    int sum = 0;     // Initialize sum to 0

    // Outer loop defines the starting point of the subarray
    for (int i = 0; i < n; i++) {
        sum = 0;  // Reset sum for the new subarray starting at index i
        // Inner loop defines the ending point of the subarray
        for (int j = i; j < n; j++) {
            sum += a[j];  // Accumulate sum for the subarray from i to j
            if (sum > max) {
                max = sum;  // Update max if the current subarray sum is greater
            }
        }
    }

    printf("Maximum sum of subarray: %d\n", max);
}

void getdata(int n, int a[]) {
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
}

int main(void) {
    int n;

    printf("Enter the number of elements in the array:\n");
    scanf("%d", &n);
    int arr[n];

    getdata(n, arr);
    subarray(n, arr);

    return 0;
}
*/