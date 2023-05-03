#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void displayList(struct Node *node)
{
    struct Node *temp = node;

    if (node == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    printf("List elements: ");

    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != node);
}

void insertFront(struct Node **head, int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    struct Node *temp = *head;

    newNode->data = value;
    newNode->next = *head;

    if (*head == NULL)
    {
        *head = newNode;
        newNode->next = newNode;
        return;
    }

    while (temp->next != *head)
    {
        temp = temp->next;
    }

    temp->next = newNode;
    *head = newNode;
}

void insertEnd(struct Node **head, int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    struct Node *temp = *head;

    newNode->data = value;
    newNode->next = *head;

    if (*head == NULL)
    {
        *head = newNode;
        newNode->next = newNode;
        return;
    }

    while (temp->next != *head)
    {
        temp = temp->next;
    }

    temp->next = newNode;
}

void insertBetween(struct Node **head, int value, int position)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    struct Node *temp = *head;

    newNode->data = value;

    if (*head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    for (int i = 0; i < position - 2; i++)
    {
        temp = temp->next;
        if (temp == *head)
        {
            printf("Position not found.\n");
            return;
        }
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void searchNode(struct Node **head, int value)
{
    int position = 1;
    struct Node *temp = *head;

    if (*head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    do
    {
        if (temp->data == value)
        {
            printf("%d found at position %d.\n", value, position);
            return;
        }
        temp = temp->next;
        position++;
    } while (temp != *head);

    printf("%d not found in the list.\n", value);
}

int deleteFront(struct Node **head)
{
    int deletedElement;
    struct Node *last = *head;
    struct Node *temp;

    if (*head == NULL)

    {
        printf("List is empty.\n");
        return -1;
    }
    while (last->next != *head)
    {
        last = last->next;
    }

    temp = *head;
    *head = temp->next;
    last->next = *head;
    deletedElement = temp->data;
    free(temp);

    return deletedElement;
}

int deleteEnd(struct Node **head)
{
    int deletedElement;
    struct Node *last = *head;
    struct Node *temp;
    if (*head == NULL)
    {
        printf("List is empty.\n");
        return -1;
    }

    while (last->next != *head)
    {
        temp = last;
        last = last->next;
    }

    temp->next = *head;
    deletedElement = last->data;
    free(last);

    return deletedElement;
}

int deleteBetween(struct Node **head, int position)
{
    int deletedElement;
    struct Node *temp = *head;
    if (*head == NULL)
    {
        printf("List is empty.\n");
        return -1;
    }

    for (int i = 0; i < position - 2; i++)
    {
        temp = temp->next;
        if (temp->next == *head)
        {
            printf("Position not found.\n");
            return -1;
        }
    }

    struct Node *deleteNode = temp->next;
    temp->next = deleteNode->next;
    deletedElement = deleteNode->data;
    free(deleteNode);

    return deletedElement;
}
int main()
{
    struct Node *head = NULL;
    int choice, value, position, searchValue, deletedElement;
    while (1)
    {
        printf("\n--Menu--\n");
        printf("1. Insertion at the front.\n");
        printf("2. Insertion at the end.\n");
        printf("3. Insertion in between.\n");
        printf("4. Searching for a data in the LL and displaying its position.\n");
        printf("5. Deletion at the front.\n");
        printf("6. Deletion at the end.\n");
        printf("7. Deletion in between.\n");
        printf("8. Exit.\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the element to be inserted at the front: ");
            scanf("%d", &value);
            insertFront(&head, value);
            displayList(head);
            break;
        case 2:
            printf("Enter the element to be inserted at the end: ");
            scanf("%d", &value);
            insertEnd(&head, value);
            displayList(head);
            break;
        case 3:
            printf("Enter the position to insert the element: ");
            scanf("%d", &position);
            printf("Enter the element to be inserted: ");
            scanf("%d", &value);
            insertBetween(&head, value, position);
            displayList(head);
            break;
        case 4:
            printf("Enter the element to be searched: ");
            scanf("%d", &searchValue);
            searchNode(&head, searchValue);
            break;
        case 5:
            deletedElement = deleteFront(&head);
            if (deletedElement != -1)
            {
                printf("%d deleted from the front.\n", deletedElement);
            }
            displayList(head);
            break;
        case 6:
            deletedElement = deleteEnd(&head);
            if (deletedElement != -1)
            {
                printf("%d deleted from the end.\n", deletedElement);
            }
            displayList(head);
            break;
        case 7:
            printf("Enter the position of the node to be deleted: ");
            scanf("%d", &position);
            deletedElement = deleteBetween(&head, position);
            if (deletedElement != -1)
            {
                printf("%d deleted from position %d.\n", deletedElement, position);
            }
            displayList(head);
            break;
        case 8:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }
    return 0;
}
