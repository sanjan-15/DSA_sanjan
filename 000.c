#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
   char data;
   struct node *prev;
   struct node *next;
};

struct node *head = NULL;

void push(char value) {
   struct node *newnode = (struct node *)malloc(sizeof(struct node));
   newnode->data = value;
   newnode->prev = NULL;
   newnode->next = head;

   if (head != NULL) {
      head->prev = newnode;
   }

   head = newnode;
}

void reverseString() {
   struct node *current = head;
   struct node *temp = NULL;

   while (current != NULL) {
      temp = current->prev;
      current->prev = current->next;
      current->next = temp;
      current = current->prev;
   }

   if (temp != NULL) {
      head = temp->prev;
   }
}

void display() {
   struct node *current = head;

   // Traverse to the last node
   while (current != NULL && current->next != NULL) {
      current = current->next;
   }

   // Print characters in reverse order
   while (current != NULL) {
      printf("%c", current->data);
      current = current->prev;
   }
   printf("\n");
}

int main() {
   char input[100];
   printf("Enter the string: ");
   scanf("%s", input);

   int i = 0;
   while (input[i] != '\0') {
      push(input[i]);
      i++;
   }

   printf("The original string: %s\n", input);

   reverseString();

   printf("The reversed string: ");
   display();

   return 0;
}
