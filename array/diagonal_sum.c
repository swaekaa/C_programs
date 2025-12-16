#include <stdio.h>

int main() 
{
	// your code goes here
	int n;
	scanf("%d",&n);
	int arr[n][n];
	int pd=0;
	int mid;
	
	for(int i=0;i<n;i++)
	{
	    for(int j=0;j<n;j++)
	    scanf("%d",&arr[i][j]);
	}
	
	for(int i=0;i<n;i++)
	{
	    pd+=arr[i][i];
	}
	
	int sd=0;

	for(int i=0;i<n;i++)
	{
	    sd+=arr[i][n-1-i];
	}
	
	if(n%2!=0)
	mid=arr[n/2][n/2];

	
	int sum=pd+sd-mid;
	printf("%d\n",sum);
	
	return 0;

}

