#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* buildCompleteBinaryTree(int index, int nodeCount) {
    if (index >= nodeCount)
        return NULL;

    struct Node* root = createNode(index + 1);

    root->left = buildCompleteBinaryTree(2 * index + 1, nodeCount);
    root->right = buildCompleteBinaryTree(2 * index + 2, nodeCount);

    return root;
}

void preOrder(struct Node* root) {
    if (root == NULL)
        return;

    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}

int main() {
    int nodeCount;
    
    printf("Enter the number of nodes in the complete binary tree: ");
    scanf("%d", &nodeCount);

    struct Node* root = buildCompleteBinaryTree(0, nodeCount);

    printf("Pre-order traversal of the complete binary tree: ");
    preOrder(root);
    printf("\n");

    return 0;
}
