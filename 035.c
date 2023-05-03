#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
struct Node *createLinkedList(int n)
{
    struct Node *head = NULL;
    struct Node *tail = NULL;
    int data;
    printf("Enter data for node 1: ");
    scanf("%d", &data);
    head = createNode(data);
    tail = head;
    int i;
    for (i = 2; i <= n; i++)
    {
        printf("Enter data for node %d: ", i);
        scanf("%d", &data);
        struct Node *newNode = createNode(data);
        tail->next = newNode;
        tail = newNode;
    }
    tail->next = head;
    return head;
}
void displayLinkedList(struct Node *head)
{
    if (head == NULL)
    {
        printf("List is empty");
        return;
    }

    struct Node *current = head;
    do
    {
        printf("Curr add - %u ,Data - %d ,Next add - %d \n",&current->data,current->data,current->next);
        current = current->next;
    } while (current != head);

    printf("\n");
}
struct Node *insertAtBeginning(struct Node *head, int data)
{
    struct Node *newNode = createNode(data);
    if (head == NULL)
    {
        head = newNode;
        newNode->next = head;
    }
    else
    {
        newNode->next = head;
        struct Node *current = head;
        while (current->next != head)
        {
            current = current->next;
        }
        current->next = newNode;
        head = newNode;
    }
    return head;
}
struct Node *insertAtEnd(struct Node *head, int data)
{
    struct Node *newNode = createNode(data);
    if (head == NULL)
    {
        head = newNode;
        newNode->next = head;
    }
    else
    {
        struct Node *current = head;
        while (current->next != head)
        {
            current = current->next;
        }
        current->next = newNode;
        newNode->next = head;
    }
    return head;
}
struct Node *insertInBetween(struct Node *head, int data, int position)
{
    struct Node *newNode = createNode(data);
    if (head == NULL)
    {
        printf("List is empty\n");
        return head;
    }
    else
    {
        int i;
        struct Node *current = head;
        for (i = 1; i < position - 1; i++)
        {
            current = current->next;
            if (current == head)
            {
                printf("Invalid position\n");
                return head;
            }
        }
        newNode->next = current->next;
        current->next = newNode;
        return head;
    }
}
int main()
{
    int n = 4; 
    struct Node *head = createLinkedList(n);
    printf("Original linked list: \n");
    displayLinkedList(head);
    int data;
    printf("Enter data to insert at the beginning: ");
    scanf("%d", &data);
    head = insertAtBeginning(head, data);
    printf("Linked list after inserting at the beginning: ");
    displayLinkedList(head);
    printf("Enter data to insert at the end: ");
    scanf("%d", &data);
    head = insertAtEnd(head, data);
    printf("Linked list after inserting at the end: ");
    displayLinkedList(head);
    int position;
    printf("Enter position to insert in between (1-%d): ", n + 1);
    scanf("%d", &position);
    printf("Enter data to insert in between: ");
    scanf("%d", &data);
    head = insertInBetween(head, data, position);
    printf("Linked list after inserting in between: ");
    displayLinkedList(head);
    return 0;
}
