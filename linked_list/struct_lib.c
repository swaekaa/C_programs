#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;

NODE * create(NODE *start)
{
    NODE *nn, *pr;
    int c=1;

    while(c!=0)
    {
        nn=(NODE *)malloc(sizeof(NODE));

        printf("enter the data to put in the node\n");
        scanf("%d ",&nn->data);

        if(start==NULL)
        {
            start=nn;
        }
        else
        {
            pr->next=start;
        }

        printf("enter 0 to exit else type any number\n");
        scanf("%d",&c);
    }
}

void display(NODE *start)
{
    while(start!=NULL);
    {
        printf("%d\n",start->data);
        start=start->next;
    }
}



