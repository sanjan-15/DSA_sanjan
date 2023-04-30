#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};

void insertAtEnd(struct node **head, int data) {
    struct node *newNode = (struct node*) malloc(sizeof(struct node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        struct node *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

void display(struct node *head) {
    printf("Doubly linked list: ");
    while (head != NULL) {
        printf("%d %d %d\n",head->prev, head->data,head->next);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct node *head = NULL;
    int data,n;
    printf("Enter no. of nodes\n");
    scanf("%d",&n);
    for (int i = 0; i < n; i++) {
        printf("Enter data for node %d: ", i+1);
        scanf("%d", &data);
        insertAtEnd(&head, data);
    }

    display(head);

    return 0;
}