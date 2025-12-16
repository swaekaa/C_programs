#include <stdio.h>

#include <stdbool.h>

#include<string.h>


int main()
{
    // your code goes here

    char name[50];

    fgets(name, sizeof(name), stdin);
    
    size_t len =strlen(name);
    
    if(name[len-1]=='\n')
    name[len-1]='\0';

    char search;
    int n, count = 0;
    bool nfound = true;

    scanf(" %c", & search);
    scanf("%d", & n);

    for (int i = 0; name[i] != '\0'; i++)
    {
        if (name[i] == search)
        {
            count++;

            if (count == n)
            {
                printf("%d\n", i);
                nfound = false;
                break;
            }
        }
    }

    if (nfound)
        printf("-1");
        
        return 0;

}