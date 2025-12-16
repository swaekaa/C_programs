#include <stdio.h>
#include "linkedlib.c"

/// @brief 
struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;

int main()
{
    NODE *start=NULL;
    start=create(start);
    display(start);


}