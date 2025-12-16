#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

// the operation of operands are in correct order
// the exp should be reversed first

struct node
{
    int data;
    struct node* next;
};

typedef struct node node;

void push(node** start, int value)
{
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = value;
    newnode->next = *start;
    *start = newnode;
}

int pop(node** start)
{
    if (*start == NULL)
    {
        printf("stack underflow\n");
        return -1;
    }

    int value = (*start)->data;

    node* temp = *start;
    *start = (*start)->next;
    free(temp);

    return value;
}

void reverse(char exp[], int size)
{
    int start = 0;
    int end = size - 1;
    while (start < end)
    {
        char temp = exp[start];
        exp[start] = exp[end];
        exp[end] = temp;

        start++;
        end--;
    }
}

int execute(char* exp)
{
    node* start = NULL;

    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (isdigit(exp[i]))
        {
            push(&start, exp[i] - '0');
        }
        else
        {
            int val1 = pop(&start);
            int val2 = pop(&start);

            switch (exp[i]) {
                case '+': push(&start, val1 + val2); break;
                case '-': push(&start, val1 - val2); break; 
                case '*': push(&start, val1 * val2); break;
                case '/': push(&start, val1 / val2); break; 
            }
        }
    }
    return pop(&start);
}

int main(void)
{
    char exp[] = "+/*7-+38293";
    int size = strlen(exp);
    reverse(exp, size);
    printf("The value of the prefix expression is %d\n", execute(exp));

    return 0;
}
// 3+4+5*7