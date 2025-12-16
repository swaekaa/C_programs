#include <stdio.h>

int main() 
{
	// your code goes here
	int n,d;
	scanf("%d %d",&n,&d);
	
	int arr[n][2];
	
	for(int i=0;i<n;i++)
	{
	    for(int j=0;j<2;j++)
	    {
	        scanf("%d",&arr[i][j]);
	       
	    }
	}

	for(int i=0;i<n;i++)
	{
	   if((arr[i][0]+arr[i][1])%d==0)
	   {
	       printf("(%d, %d)\n",arr[i][0],arr[i][1]);
	   }
	    
	}

}

