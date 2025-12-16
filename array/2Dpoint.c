// to input a 2d array with pointers
#include <stdio.h>
#include <stdlib.h>

void getdata(int m,int n,int **a)
{
    printf("enter the data\n");
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        scanf("%d \n",&a[i][j]);
    }

}

void putdata(int m, int n ,int **a)
{
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        printf("%d \n",*(*(a+i)+j));
    }
}
int  main()
{
    int **pv;
    int m,n;
    printf("enter the dimensions of the array\n");
    scanf("%d %d \n",&m,&n);
    pv=(int **)malloc(m*sizeof(int*));
    for(int i=0;i<m;i++)
    *(pv+i)=(int *)malloc(n*sizeof(int));
    getdata(m,n,pv);
    putdata(m,n,pv);
    return 1;
    
}
