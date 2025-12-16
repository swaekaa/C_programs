#include <stdio.h>
#include <stdlib.h>

// Structure for an item with weight, value, and fraction
struct Item {
    int weight;
    int value;
    float ratio;
};

// Structure for Huffman Node
struct HuffmanNode {
    int weight;
    struct HuffmanNode *left, *right;
};

// Comparison function for sorting items in decreasing order of value/weight ratio
int compare(const void *a, const void *b) {
    struct Item *item1 = (struct Item *)a;
    struct Item *item2 = (struct Item *)b;
    return (item2->ratio - item1->ratio) > 0 ? 1 : -1;
}

// Function to implement fractional knapsack
float fractionalKnapsack(int capacity, struct Item items[], int n) {
    qsort(items, n, sizeof(struct Item), compare);
    
    float totalValue = 0.0;
    for (int i = 0; i < n; i++) {
        if (capacity >= items[i].weight) {
            capacity -= items[i].weight;
            totalValue += items[i].value;
        } else {
            totalValue += items[i].ratio * capacity;
            break;
        }
    }
    return totalValue;
}

// Function to create a new Huffman node
struct HuffmanNode* createNode(int weight) {
    struct HuffmanNode* node = (struct HuffmanNode*)malloc(sizeof(struct HuffmanNode));
    node->weight = weight;
    node->left = node->right = NULL;
    return node;
}

// Main function
int main() {
    int n, capacity;
    printf("Enter number of items: ");
    scanf("%d", &n);
    
    struct Item items[n];
    printf("Enter weight and value of each item:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &items[i].weight, &items[i].value);
        items[i].ratio = (float)items[i].value / items[i].weight;
    }
    
    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);
    
    float maxValue = fractionalKnapsack(capacity, items, n);
    printf("Maximum value in Knapsack: %.2f\n", maxValue);
    
    // Creating Huffman nodes for item weights
    printf("Huffman Nodes for Item Weights:\n");
    for (int i = 0; i < n; i++) {
        struct HuffmanNode* node = createNode(items[i].weight);
        printf("Node with weight %d created.\n", node->weight);
    }
    
    return 0;
}
