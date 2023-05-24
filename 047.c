#include <stdio.h>
#include <stdlib.h>

struct Node
{
    char data;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(char data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node *insertNode(struct Node *root, char data)
{
    if (root == NULL)
    {
        return createNode(data);
    }
    else if (data < root->data)
    {
        root->left = insertNode(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = insertNode(root->right, data);
    }
    return root;
}

char findMinimum(struct Node *root)
{
    if (root == NULL)
    {
        return '\0';
    }
    else if (root->left == NULL)
    {
        return root->data;
    }
    else
    {
        return findMinimum(root->left);
    }
}

char findMaximum(struct Node *root)
{
    if (root == NULL)
    {
        return '\0';
    }
    else if (root->right == NULL)
    {
        return root->data;
    }
    else
    {
        return findMaximum(root->right);
    }
}

int main()
{
    struct Node *root = NULL;

    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements: ");
    char data;
    for (int i = 0; i < n; i++)
    {
        scanf(" %c", &data);
        root = insertNode(root, data);
    }

    char minimum = findMinimum(root);
    char maximum = findMaximum(root);

    printf("Minimum element: %c\n", minimum);
    printf("Maximum element: %c\n", maximum);

    return 0;
}