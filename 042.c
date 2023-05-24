#include <stdio.h>
#include <stdlib.h>

// Structure for a tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Build a perfect binary tree
struct Node* buildPerfectBinaryTree(int depth, int* nodeCount) {
    if (depth <= 0 || *nodeCount <= 0)
        return NULL;

    struct Node* root = createNode(*nodeCount);
    (*nodeCount)--;

    root->left = buildPerfectBinaryTree(depth - 1, nodeCount);
    root->right = buildPerfectBinaryTree(depth - 1, nodeCount);

    return root;
}

// Pre-order traversal of the tree
void preOrder(struct Node* root) {
    if (root == NULL)
        return;

    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}

// Main function
int main() {
    int depth, nodeCount;
    
    printf("Enter the number of nodes in the perfect binary tree: ");
    scanf("%d", &nodeCount);
    
    // Calculate the depth of the tree based on the number of nodes
    depth = 0;
    int temp = nodeCount;
    while (temp > 0) {
        depth++;
        temp /= 2;
    }

    struct Node* root = buildPerfectBinaryTree(depth, &nodeCount);

    printf("Pre-order traversal of the perfect binary tree: ");
    preOrder(root);
    printf("\n");

    return 0;
}
