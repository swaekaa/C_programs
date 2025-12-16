#include <stdio.h>

int main() 
{
	// your code goes here
	int n;
	scanf("%d",&n);
	int arr[n];
	int max=-1000;
	int min=1000;
	
	for(int i=0;i<n;i++)
	{
	    scanf("%d",&arr[i]);
	    
	    if(arr[i]>max)
	    max=arr[i];
	    
	    if(arr[i]<min)
	    min=arr[i];
	}
	
	printf("%d %d",min,max);

}

