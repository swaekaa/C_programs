#include <stdio.h>

int main() 
{
	// your code goes here
	int n;
	scanf("%d",&n);
	int arr[n];
	int num;
	scanf("%d",&num);
	int mdif=1000,dif,pos;
	for(int i=0;i<n;i++)
	{
	    scanf("%d",&arr[i]);
	    dif=num-arr[i];
	    if(dif<0)
	    dif*=-1;
	    if(dif<mdif )
	    {mdif=dif;
	    pos=i;}
	}
	
	printf("%d",arr[pos]);

}

