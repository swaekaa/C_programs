#include <stdio.h>
#include <stdlib.h>

// implementation of stacks using linked list
// here double pointer is used rather than one
// to change in the address directly
// using 1 pointer the main function remains un updated, stacks start is not updated
// double pointer updates the actual pointer

struct Node {
    int data;
    struct Node* next;
};

void push(struct Node** start, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = *start;
    *start = newNode;
}

int pop(struct Node** start) {
    if (*start == NULL) {
        printf("Stack Underflow\n");
        return -1;
    }
    int value = (*start)->data;
    struct Node* temp = *start;
    *start = (*start)->next;
    free(temp);
    return value;
}

// just to check the top element of the stack
int peek(struct Node* start) {
    if (start == NULL) {
        printf("Stack is empty\n");
        return -1;
    }
    return start->data;
}

int main() {
    struct Node* stack = NULL;

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    printf("%d popped from stack\n", pop(&stack));
    printf("Top element is %d\n", peek(stack));

    return 0;
}
