#include <stdio.h>

int main()
{
    // your code goes here
    int n;
    scanf("%d", & n);

    int arr[n][2];
    int temp = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2; j++)
            scanf("%d", & arr[i][j]);

    }

    int x, y;
    scanf("%d %d", & x, & y);

    for (int i = 0; i < n; i++)
    {

        if ((x == arr[i][0] || x == arr[i][1]) && (y == arr[i][0] || y == arr[i][1]))
            temp = 1;

    }

    if (temp == 1)
        printf("YES");
    else
        printf("NO");




}