#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

void displayList(struct Node* head) {
    struct Node* temp = head;

    printf("Doubly linked list: ");

    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

void insertAtEnd(struct Node** headRef, int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;

    if(*headRef == NULL) {
        *headRef = newNode;
        return;
    }

    struct Node* temp = *headRef;
    while(temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}

void searchElement(struct Node* head, int element) {
    struct Node* temp = head;
    int position = 0;

    while(temp != NULL) {
        position++;

        if(temp->data == element) {
            printf("%d found at position %d with address %p.\n", element, position, temp);
            return;
        }

        temp = temp->next;
    }

    printf("%d not found in the list.\n", element);
}

int main() {
    struct Node* head = NULL;
    int element, data, n;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    for(int i = 1; i <= n; i++) {
        printf("Enter the data of node %d: ", i);
        scanf("%d", &data);
        insertAtEnd(&head, data);
    }

    displayList(head);

    printf("Enter the element to be searched: ");
    scanf("%d", &element);

    searchElement(head, element);

    return 0;
}
