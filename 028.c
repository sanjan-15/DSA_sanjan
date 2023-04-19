#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void insertNode(int data, int position) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (position == 1) {
        newNode->next = head;
        head = newNode;
        return;
    }
    struct Node* prev = head;
    for (int i = 1; i < position - 1; i++) {
        prev = prev->next;
    }
    newNode->next = prev->next;
    prev->next = newNode;
}

void display() {
    struct Node* temp = head;
    printf("Linked list: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int n, data, position;
    printf("Enter the number of nodes in the linked list: ");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        printf("Enter the data for node %d: ", i);
        scanf("%d", &data);
        insertNode(data, i);
    }
    display();
    printf("Enter the position at which you want to insert a node: ");
    scanf("%d", &position);
    printf("Enter the data for the new node: ");
    scanf("%d", &data);
    insertNode(data, position);
    display();
    return 0;
}
