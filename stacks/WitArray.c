#include <stdio.h>
#include <stdlib.h>
#define max 25
// implementing stacks through 
typedef struct stack
{
    int a[max];
    int top; 
} stack;

void push(stack* s, int n)
{
    if (s->top == max - 1)
    {
        printf("error\n");
        return;
    }

    s->top++;
    s->a[s->top] = n;
}

int pop(stack* s)
{
    if (s->top == -1)
    {
        printf("stack is empty\n");
        return -1;
    }

    int temp = s->a[s->top];
    s->top--;
    return temp;
}

void display(stack* s)
{
    printf("the value popped out is: %d\n", pop(s)); // Corrected the function call
}

void input(stack* s)
{
    printf("enter a value to pushed into the stack: "); // Improved prompt
    int n;
    scanf("%d", &n);
    push(s, n); // Corrected the function call
}

int main(void)
{
    stack s;
    s.top = -1;
    int c = 1;

    while (c != 0)
    {
        input(&s);
        printf("if you want to exit press 0 else enter any other number: ");
        scanf("%d", &c);
    }

    int p = 1;
    while (p != 0)
    {
        display(&s);
        printf("if you want to exit press 0 else enter any other number: ");
        scanf("%d", &p);
    }
    return 0;
}