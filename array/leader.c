// to find the leaders in an array
#include <stdio.h>
void printleader(int n,int arr[n]);
int main(void)
{
	// your code goes here
	int n;
    printf("enter the lenght of the array\n");
	scanf("%d",&n);
	int arr[n];
	printf("enter the elements iof the array\n");
	for(int i=0;i<n;i++)
	scanf("%d",&arr[i]);
	printf("the leaders of the array are\n");
	printleader(n,arr);
	return 0;

}
void printleader(int n,int arr[n])
{
    int max=arr[n-1];
    int lead[n];
    int index=0;
    lead[index++]=max;
    
    for(int i=n-2;i>=0;i--)
    {
        if(arr[i]>max)
        {
            max=arr[i];
            lead[index++]=max;
        }
    }
    
    for(int i=index-1;i>=0;i--)
    {
        printf("%d ",lead[i]);
    }
}



