//selection sort
#include<stdio.h>
void main(void)
{
    int n;
    printf("enter the length of the array\n");
    scanf("%d",&n);
    int arr[n];
    getdata(n,arr);
    sortdata(n,arr);
    display(n,arr);
}

void getdata(int n,int arr[n])
{
    printf("enter the elements of the array\n");
    int i;
    for(i=0;i<n;i++)
    scanf("%d",arr[i]);

}

void sortdata(int n,int a[n])
{
    int max=a[0];
    int i, pos, temp[n];

    for( i=0;i<n;i++)
    {
        if(a[i]>max)
        {
            max=a[i];
            pos=i;
        }

        temp[i]=a[n];
        a[n]=a[pos];
        a[pos]=temp[i];
        n--;

    }
}