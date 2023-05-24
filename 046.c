#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the binary search tree
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node with the given data
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a node in the binary search tree
struct Node* insertNode(struct Node* root, int data) {
    if (root == NULL) {
        root = createNode(data);
        return root;
    }
    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }
    return root;
}

// Function to find the minimum element in the binary search tree
int findMin(struct Node* root) {
    if (root == NULL) {
        printf("The binary search tree is empty.\n");
        return -1;
    }
    while (root->left != NULL) {
        root = root->left;
    }
    return root->data;
}

// Function to find the maximum element in the binary search tree
int findMax(struct Node* root) {
    if (root == NULL) {
        printf("The binary search tree is empty.\n");
        return -1;
    }
    while (root->right != NULL) {
        root = root->right;
    }
    return root->data;
}

int main() {
    struct Node* root = NULL;
    int data, n, i;

    printf("Enter the number of elements in the binary search tree: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &data);
        root = insertNode(root, data);
    }

    int minValue = findMin(root);
    int maxValue = findMax(root);

    printf("Minimum element: %d\n", minValue);
    printf("Maximum element: %d\n", maxValue);

    return 0;
}
