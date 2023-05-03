#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void displayList(struct Node* node) {
    struct Node* temp = node;

    if(node == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("List elements: ");

    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while(temp != node);
}

void insertEnd(struct Node** head, int value) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    struct Node* temp = *head;

    newNode->data = value;
    newNode->next = *head;

    if(*head == NULL) {
        *head = newNode;
        return;
    }

    while(temp->next != *head) {
        temp = temp->next;
    }

    temp->next = newNode;
    *head = newNode;
}

int deleteBeg(struct Node** head) {
    int deletedElement;
    struct Node* last = *head;
    struct Node* temp;

    if(*head == NULL) {
        printf("List is empty.\n");
        return -1;
    }

    while(last->next != *head) {
        last = last->next;
    }

    temp = *head;
    deletedElement = temp->data;
    last->next = temp->next;
    *head = temp->next;

    free(temp);

    return deletedElement;
}

int deleteEnd(struct Node** head) {
    int deletedElement;
    struct Node* last = *head;
    struct Node* prev;

    if(*head == NULL) {
        printf("List is empty.\n");
        return -1;
    }

    while(last->next != *head) {
        prev = last;
        last = last->next;
    }

    deletedElement = last->data;
    prev->next = *head;
    free(last);

    return deletedElement;
}

int deletePos(struct Node** head, int pos) {
    int deletedElement;
    struct Node* last = *head;
    struct Node* prev;

    if(*head == NULL) {
        printf("List is empty.\n");
        return -1;
    }

    if(pos == 0) {
        return deleteBeg(head);
    }

    for(int i = 0; i < pos - 1; i++) {
        prev = last;
        last = last->next;

        if(last == *head) {
            printf("Position not found.\n");
            return -1;
        }
    }

    deletedElement = last->data;
    prev->next = last->next;
    free(last);

    return deletedElement;
}

int main() {
    struct Node* head = NULL;

    insertEnd(&head, 10);
    insertEnd(&head, 20);
    insertEnd(&head, 30);

    displayList(head);

    printf("\nDeleted element at beginning: %d\n", deleteBeg(&head));
    displayList(head);

    printf("\nDeleted element at end: %d\n", deleteEnd(&head));
    displayList(head);

    printf("\nDeleted element at position 1: %d\n", deletePos(&head, 1));
    displayList(head);

    return 0;
}
