#include <stdio.h>
void subarray(int n ,int a[])
{
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            for(int k=i;k<=j;k++)
            {
                printf("%d ",a[k]);
            }
            printf("\n");
        }
    }


}

void getdata(int n,int a[])
{
    printf("enter the elements of the array\n");
    for(int i=0;i<n;i++)
    scanf("%d",&a[i]);
}

int main(void)
{
    int n;

    printf("enter the number of elements in the array \n");
    scanf("%d",&n);
    int arr[n];

    getdata(n,arr);
    printf("All subarrays are:\n");
    subarray(n,arr);

    return 0;
}

