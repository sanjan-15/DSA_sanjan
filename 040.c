#include <stdio.h>
#include <stdlib.h>

struct Node {
    char data;
    struct Node* next;
};

void insertAtEnd(struct Node** headRef, char data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
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
}

void printListReverse(struct Node* head) {
    if(head == NULL) {
        return;
    }

    printListReverse(head->next);
    printf("%c", head->data);
}

int main() {
    struct Node* head = NULL;
    char ch;

    printf("Enter a word character by character (press Enter to exit): ");
    while((ch = getchar()) != '\n') {
        insertAtEnd(&head, ch);
    }

    printf("The word in reverse order is: ");
    printListReverse(head);

    return 0;
}
