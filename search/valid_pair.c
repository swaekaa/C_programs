#include <stdio.h>

int main() 
{
	// your code goes here
	int n;
	scanf("%d",&n);
	int arr[n][2];
	
	for(int i=0;i<n;i++)
	{
	    for(int j=0;j<2;j++)
	    {
	        scanf("%d",&arr[i][j]);
	    }
	}
	
	int x,y;
	scanf("%d %d",&x,&y);
	
	int sum=0;
	int pro=1;
	
	for(int i=0;i<n;i++)
	{
	    sum=arr[i][0]+arr[i][1];
	    pro=arr[i][0]*arr[i][1];
	    
	    if((sum>=x && sum<=y) && (pro>=x && pro<=y))
	    printf("%d %d\n",arr[i][0],arr[i][1]);
	}

    return 0;


}

