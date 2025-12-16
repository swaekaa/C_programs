#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct node 
{
    char data;
    struct node* next;
} node;

void push(node** start, char value) 
{
    node* nn = (node*)malloc(sizeof(node));
    nn->data = value;
    nn->next = *start;
    *start = nn;
}

char pop(node** start) 
{
    if (*start == NULL) 
    {
        printf("stack underflow\n");
        return '\0';
    }

    char value = (*start)->data;
    node* temp = *start;
    *start = (*start)->next;
    free(temp);
    return value;
}

int precedence(char op) 
{
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

void postfix(char arr[], char post[]) 
{
    node* start = NULL;
    int k = 0;

    for (int i = 0; arr[i] != '\0'; i++) 
    {
        if (isdigit(arr[i])) 
        {
            post[k++] = arr[i];
        } 
        else 
        {
            while (start != NULL && precedence(start->data) >= precedence(arr[i])) 
            {
                post[k++] = pop(&start);
            }
            push(&start, arr[i]);
        }
    }

    while (start != NULL) 
    {
        post[k++] = pop(&start);
    }
    post[k] = '\0';
}

int main(void) 
{
    char exp[] = "3*3+4/4";
    char post[strlen(exp) + 1];

    postfix(exp, post);
    printf("Postfix expression: %s\n", post);

    return 0;
}
