#include<stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;

}NODE;

NODE* create(NODE* start)
{
    NODE* nn, *pr;
    int c=1;

    while(c!=0)
    {
        nn=(NODE*)malloc(sizeof(NODE));
        printf("enter value of the node\n");
        scanf("%d",&nn->data);

        nn->next=start;

        if(start==NULL)
        {
            start=nn;
        }
        else
        {
            pr->next=nn;
        }
        pr=nn;

        printf("enter 0 to exit creating linked list\n");
        scanf("%d",&c);
    }

    nn ->next=NULL;
    return start;
}

void display(NODE* start)
{
    while(start != NULL)
    {
        printf("%d ",start->data);
        start=start->next;
    }
    printf("\n");
}

NODE* addnode(NODE* start)
{
    NODE* nn= (NODE*)malloc(sizeof(NODE));
    printf("enter the value for the first node ");
    scanf("%d",&nn->data);

    nn->next=start;
    return nn;
}

void addlast(NODE* start)
{
    NODE* nn=(NODE*)malloc(sizeof(NODE));

    printf("enter the value to add in the last node ");
    scanf("%d",&nn->data);

    nn->next=NULL;
    while(start->next != NULL)
    {
        start=start->next;
    }

    start->next=nn;
    return start;
}

void addpos(NODE* start)
{
    printf("enter a position to add a node\n");
    int n;
    scanf("%d",&n);

    NODE* nn=(NODE*)malloc(sizeof(NODE));
    printf("enter the value of node\n");
    scanf("%d",&nn->data);

    for(int i=0;i<n;i++)
    {
        start=start->next;
    }

    nn->next=start->next;
    start->next=nn;
}

NODE* deletefirst(NODE* start)
{
    NODE* temp=start;
    start=start->next;
    free(start);

    return start;
}

int main(void)
{
    NODE* start=NULL;
    start=create(start);

    printf("the linked list is :\n");
    display(start);

    start=addnode(start);
    display(start);

    addlast(start);
    display(start);

    addpos(start);
    display(start);

    printf("deleting first node");
    start=deletefirst(start);
    display(start);
    



    return 0;
}