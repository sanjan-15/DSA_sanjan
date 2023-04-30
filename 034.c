#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};
struct Node* createNode(int data) {
    struct Node *new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = NULL;
    return new_node;
}
void insertAtBeginning(struct Node **head_ref, int data) {
    struct Node *new_node = createNode(data);
    if (*head_ref == NULL) {
        *head_ref = new_node;
    } else {
        new_node->next = *head_ref;
        (*head_ref)->prev = new_node;
        *head_ref = new_node;
    }
}
void insertAtEnd(struct Node **head_ref, int data) {
    struct Node *new_node = createNode(data);
    if (*head_ref == NULL) {
        *head_ref = new_node;
    } else {
        struct Node *temp = *head_ref;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
        new_node->prev = temp;
    }
}
void insertInMiddle(struct Node **head_ref, int data, int position) {
    struct Node *new_node = createNode(data);
    if (*head_ref == NULL) {
        *head_ref = new_node;
    } else {
        int i = 1;
        struct Node *temp = *head_ref;
        while (i < position && temp != NULL) {
            temp = temp->next;
            i++;
        }
        if (i != position) {
            printf("Desired position not found\n");
        } else {
            new_node->prev = temp->prev;
            new_node->next = temp;
            temp->prev->next = new_node;
            temp->prev = new_node;
        }
    }
}
void display(struct Node *head) {
    if (head == NULL) {
        printf("Doubly Linked List is empty\n");
    } else {
        struct Node *temp = head;
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }
    printf("\n");
}
int main() {
    struct Node *head = NULL;
    int choice, data, position;
    while (1) {
        printf("\nWhat do you want to do?\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert somewhere in the middle\n");
        printf("4. Display Doubly Linked List\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
 
        switch(choice) {
            case 1:
                printf("Enter the element to be inserted: ");
                scanf("%d", &data);
                insertAtBeginning(&head, data);
                break;
 
            case 2:
                printf("Enter the element to be inserted: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                break;
         case 3:
            printf("Enter the element to be inserted: ");
            scanf("%d", &data);
            printf("Enter the position where the element is to be inserted: ");
            scanf("%d", &position);
            insertInMiddle(&head, data, position);
            break;

        case 4:
            display(head);
            break;

        case 5:
            exit(0);
            break;

        default:
            printf("Invalid choice\n");
    }
}
return 0;
}
