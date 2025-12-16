#include <stdio.h>
#include <ctype.h>  // For isdigit function
#include <stdlib.h> // For malloc, free

// Stack node structure
struct Node {
    int data;
    struct Node* next;
};

// Push function
void push(struct Node** start, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = *start;
    *start = newNode;
}

// Pop function
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

// Function to evaluate a postfix expression
int evaluatePostfix(char* exp) {
    struct Node* stack = NULL;
    int i;

    // Scan all characters in the expression
    for (i = 0; exp[i] != '\0'; i++) {
        // If the character is an operand (number), push it to the stack
        if (isdigit(exp[i])) {
            push(&stack, exp[i] - '0');  // Convert char to int
        }
        // If the character is an operator, pop two operands from the stack
        else {
            int val1 = pop(&stack);
            int val2 = pop(&stack);

            switch (exp[i]) {
                case '+': push(&stack, val2 + val1); break;
                case '-': push(&stack, val2 - val1); break;
                case '*': push(&stack, val2 * val1); break;
                case '/': push(&stack, val2 / val1); break;
            }
        }
    }

    // The final result will be the only value in the stack
    return pop(&stack);
}

int main() {
    char exp[] = "53+82-*";  // Example postfix expression
    printf("Postfix Evaluation: %d\n", evaluatePostfix(exp));
    return 0;
}

