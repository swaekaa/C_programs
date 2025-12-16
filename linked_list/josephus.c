#include <stdio.h>
#include <stdlib.h>

struct node{
    int value;
    struct node* next;
};

struct node* head;
struct node* tail;

// Function to create a new node
struct node* node_new(int val){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->value = val;
    newnode->next = NULL;
    return newnode;
}

// Function to insert a new node at the end of the circular linked list
void insertAtEnd(int val){
    struct node* newnode = node_new(val);

    if (head == NULL) {
        head = newnode;
        tail = newnode;
    } else {
        tail->next = newnode;
        tail = newnode;
    }
    tail->next = head;  // Make the list circular
}

// Function to solve the Josephus problem using circular linked list
void solveJosephus() {
    struct node *current = head;
    struct node *prev = NULL;

    // Continue until only one person is left in the circle
    while (current->next != current) {
        prev = current;               // Person with the knife
        current = current->next;      // Person to be eliminated

        // Eliminate the current node
        prev->next = current->next;   // Remove the current node from the circle
        free(current);                // Free the memory of the eliminated person
        current = prev->next;         // Move to the next person with the knife
    }

    // The last remaining person (node) is the winner
    head = current;  // Set the head to the survivor
}

// Function to invoke the Josephus problem solution and print the winner
void solution() {
    solveJosephus();  // Call solveJosephus to solve the problem
    printf("%d\n", head->value);  // Print the winner
}

int main() {
    int t;
    scanf("%d", &t);  // Read the number of test cases
    
    while (t--) {
        head = NULL;
        tail = NULL;

        int n;
        scanf("%d", &n);  // Read the number of people in the circle

        // Insert the people into the circular linked list (1 to n)
        for (int i = 1; i <= n; i++) {
            insertAtEnd(i);
        }

        // Solve the Josephus problem and print the winner
        solution();
    }
    
    return 0;
}
