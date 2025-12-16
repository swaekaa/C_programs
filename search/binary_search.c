#include <stdio.h>

int sort(int n,int arr[n],int k)
{
    int left=0;
    int right=n-1;
    int mid;
    int index=-1;
    for(int i=0;i<n;i++)
    {
        mid=(left+right)/2;
        
        if(arr[i]==k)
        index=i;
        
        if(arr[i]<k)
        left=mid+1;
        
        if(arr[i]>k)
        right=mid-1;
    }
    return index;
}

int main() 
{
	// your code goes here
	int n,k;
	scanf("%d %d",&n,&k);
	int arr[n];
	
	for(int i=0;i<n;i++)
	{
	    scanf("%d",&arr[i]);
	}
	
	printf("%d",sort(n,arr,k));
	return 0;

}

