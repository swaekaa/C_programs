#include <stdio.h>

int main(void) 
{
	// your code goes here
	int t;
	scanf("%d",&t);
	int n;
	int min=0;
	int sum=0;
	while(t--)
	{
	    scanf("%d",&n);
	    int arr[n];
	    for(int i=0;i<n;i++)
	    {
	        scanf("%d\n",&arr[i]);
	        if (arr[i]<min)
	        {
	            min==arr[i];
	        }
	    }
	    
	    for(int i=0;i<n;i++)
	    {
	        if(arr[i]!=0)
	        sum=sum+arr[i];
	    }
	    
	    printf("%d\n",sum);
	}

}

