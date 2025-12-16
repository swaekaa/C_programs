#include <stdio.h>

int main() 
{
	// your code goes here
	int n,m;
	scanf("%d %d",&n,&m);
	int arr[n][m];
	int row[n];
	int col[m];
	
	
	
	
	for(int i=0;i<n;i++)
	{
	    for(int j=0;j<m;j++)
	    {
	        scanf("%d",&arr[i][j]);
	        
	        if (arr[i][j]==0)
	        {
	            row[i]=1;
	            col[j]=1;
	            
	        }
	    }
	}
	
	for(int i=0;i<n;i++)
	{
	    if(row[i]==1)
	    {
	    for(int j=0;j<m;j++)
	    {
	        arr[i][j]=0;
	    }
	    }
	}
	
	
	for(int j=0;j<m;j++)
	{
	    if(col[j]==1)
	    {
	        for(int i=0;i< n;i++)
	        {
	            arr[i][j]=0;
	        }
	    }
	}
	
	for(int i =0;i<n;i++)
	{
	    for(int j=0;j<m;j++)
	    {
	        printf("%d ",arr[i][j]);
	    }
	    printf("\n");
	}

}

