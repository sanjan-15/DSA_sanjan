#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

void displayList(struct Node *head)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    printf("The list is: ");
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int deleteFromBeginning(struct Node **head)
{
    int deletedElement;
    struct Node *temp = *head;

    if (*head == NULL)
    {
        printf("List is empty.\n");
        return -1;
    }

    *head = temp->next;
    if (*head != NULL)
    {
        (*head)->prev = NULL;
    }

    deletedElement = temp->data;
    free(temp);

    return deletedElement;
}

int deleteFromEnd(struct Node **head)
{
    int deletedElement;
    struct Node *last = *head;

    if (*head == NULL)
    {
        printf("List is empty.\n");
        return -1;
    }

    while (last->next != NULL)
    {
        last = last->next;
    }

    if (last->prev != NULL)
    {
        last->prev->next = NULL;
    }
    else
    {
        *head = NULL;
    }

    deletedElement = last->data;
    free(last);

    return deletedElement;
}

int deleteFromPosition(struct Node **head, int position)
{
    int deletedElement;
    struct Node *temp = *head;

    if (*head == NULL)
    {
        printf("List is empty.\n");
        return -1;
    }

    if (position == 1)
    {
        *head = temp->next;
        if (*head != NULL)
        {
            (*head)->prev = NULL;
        }

        deletedElement = temp->data;
        free(temp);

        return deletedElement;
    }

    for (int i = 0; i < position - 2; i++)
    {
        temp = temp->next;
        if (temp == NULL)
        {
            printf("Position not found.\n");
            return -1;
        }
    }

    struct Node *nodeToDelete = temp->next;
    if (nodeToDelete == NULL)
    {
        printf("Position not found.\n");
        return -1;
    }

    temp->next = nodeToDelete->next;
    if (nodeToDelete->next != NULL)
    {
        nodeToDelete->next->prev = temp;
    }

    deletedElement = nodeToDelete->data;
    free(nodeToDelete);

    return deletedElement;
}
int main()
{
    struct Node *head = NULL;
    int choice, value, position, deletedElement;
    while (1)
    {
        printf("1. Delete from the beginning\n");
        printf("2. Delete from end\n");
        printf("3. Delete from a specified position\n");
        printf("4. Display the list\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            deletedElement = deleteFromBeginning(&head);
            if (deletedElement != -1)
            {
                printf("%d deleted from the beginning.\n", deletedElement);
            }
            displayList(head);
            break;
        case 2:
            deletedElement = deleteFromEnd(&head);
            if (deletedElement != -1)
            {
                printf("%d deleted from the end.\n", deletedElement);
            }
            displayList(head);
            break;
        case 3:
            printf("Enter the position of the node to be deleted: ");
            scanf("%d", &position);
            deletedElement = deleteFromPosition(&head, position);
            if (deletedElement != -1)
            {
                printf("%d deleted from position %d.\n", deletedElement, position);
            }
            displayList(head);
            break;
        case 4:
            displayList(head);
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}
