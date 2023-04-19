#include <stdio.h>
#include <stdlib.h>

struct node {
   int data;
   struct node *next;
};

struct node *head = NULL;

void create(int n);
void display();
void deleteNode(int key);

int main() {
   int n, key;

   printf("Enter the number of nodes: ");
   scanf("%d", &n);

   create(n);

   printf("The linked list is: ");
   display();

   printf("\nEnter the node data to be deleted: ");
   scanf("%d", &key);

   deleteNode(key);

   printf("After deleting %d, the linked list is: ", key);
   display();

   return 0;
}

void create(int n) {
   int i, data;
   struct node *newNode, *temp;

   for (i = 1; i <= n; i++) {
      newNode = (struct node *)malloc(sizeof(struct node));

      printf("Enter data for node %d: ", i);
      scanf("%d", &data);

      newNode->data = data;
      newNode->next = NULL;

      if (head == NULL) {
         head = newNode;
      } else {
         temp = head;
         while (temp->next != NULL) {
            temp = temp->next;
         }
         temp->next = newNode;
      }
   }
}

void display() {
   struct node *temp;
   if (head == NULL) {
      printf("The linked list is empty.\n");
   } else {
      temp = head;
      while (temp != NULL) {
         printf("%d ", temp->data);
         temp = temp->next;
      }
      printf("\n");
   }
}

void deleteNode(int key) {
   struct node *prev, *curr;
   prev = NULL;
   curr = head;

   while (curr != NULL && curr->data != key) {
      prev = curr;
      curr = curr->next;
   }

   if (curr == NULL) {
      printf("The given node is not present in the linked list.\n");
      return;
   }

   if (prev == NULL) {
      head = curr->next;
   } else {
      prev->next = curr->next;
   }

   free(curr);
}
