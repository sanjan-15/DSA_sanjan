#include <stdio.h>
#include <stdlib.h>

typedef struct linkedlist
{
  int data;
  struct linkedlist *next;
  struct linkedlist *prev;
} doublyy;
doublyy *head;
doublyy *tail;
int count = 0;

void beginning(int wow);
void specific(int wow);
void end(int wow);
void del_beginning();
void del_specific();
void del_end();
void display();
void search();

int main()
{
  int choose, d;
  while (1)
  {
    printf("\n\n\n\n\nChoose For Insertion:\n\t\t  1 - at the beginning\t  2 - at a specific node\t  3 - at the end\n\nChoose For deletion:\n\t\t  4 - at the beginning\t  5 - at a specific node\t  6 - at the end\n\nChoose special:\n\t\t  7 - display list\t  8 - Search for an Item in the list\t  9 - EXIT THE PROGRAM  :  ");
    scanf("%d", &choose);

    if (choose == 1 || choose == 2 || choose == 3)
    {
      printf("\n\nEnter data to be inserted: ");
      scanf("%d", &d);
    }
    if (choose == 1)
    {
      beginning(d);
    }
    else if (choose == 2)
    {
      specific(d);
    }
    else if (choose == 3)
    {
      end(d);
    }
    else if (choose == 4)
    {
      del_beginning();
    }
    else if (choose == 5)
    {
      del_specific();
    }
    else if (choose == 6)
    {
      del_end();
    }
    else if (choose == 7)
    {
      display();
    }
    else if (choose == 8)
    {
      search();
    }
    else if (choose == 9)
    {
      exit(0);
    }
    else
    {
      printf("Invalid Input, Try Again");
    }
  }
}

void beginning(int wow)
{
  count++;
  doublyy *newNode = (doublyy *)malloc(sizeof(doublyy));
  newNode->data = wow;

  if (head == NULL)
  {
    head = newNode;
    head->prev = head;
    head->next = head;
    tail = newNode;
  }
  else
  {
    head->prev = newNode;
    newNode->next = head;
    head = newNode;
    head->prev = tail;
  }

  doublyy *current = head;
  printf("\nUpdated LinkedList: ");
  while (current != NULL)
  {
    printf("%d ", current->data);
    current = current->next;
    if (current == head)
    {
      break;
    }
  }
  free(current);
}

void specific(int wow)
{
  doublyy *newNode = (doublyy *)malloc(sizeof(doublyy));
  newNode->data = wow;
  if (head == NULL)
  {
    head = newNode;
    head->prev = head;
    head->next = head;
    tail = newNode;
    printf("\nThe linkedlist is empty so specific position is 1");
  }

  else
  {
    int num, i = 1;

    printf("Choose a specific position from 1 to %d: ", count + 1);
    scanf("%d", &num);

    if (num == 1)
    {
      head->prev = newNode;
      newNode->next = head;
      head = newNode;
      head->prev = tail;
    }

    else if (num == count + 1)
    {
      tail->next = newNode;
      newNode->prev = tail;
      tail = newNode;
      tail->next = head;
    }

    else
    {
      doublyy *temp = head;
      while (i < num)
      {
        temp = temp->next;
        i++;
      }
      newNode->prev = temp->prev;
      temp->prev->next = newNode;
      temp->prev = newNode;
      newNode->next = temp;
    }
  }

  doublyy *current = head;
  printf("\nUpdated LinkedList: ");
  while (current != NULL)
  {
    printf("%d ", current->data);
    current = current->next;
    if (current == head)
    {
      break;
    }
  }
  free(current);
  count++;
}

void end(int wow)
{
  count++;
  doublyy *newNode = (doublyy *)malloc(sizeof(doublyy));
  newNode->data = wow;
  if (tail == NULL)
  {
    tail = newNode;
    tail->prev = tail;
    tail->next = tail;
    head = newNode;
    printf("\nThe linkedlist is empty so end location is at position 1");
  }

  else
  {
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
    tail->next = head;
  }

  doublyy *current = head;
  printf("\nUpdated LinkedList: ");
  while (current != NULL)
  {
    printf("%d ", current->data);
    current = current->next;
    if (current == head)
    {
      break;
    }
  }
  free(current);
}

void del_beginning()
{
  if (head == NULL)
  {
    printf("\nThe linked list is empty");
  }
  else
  {
    printf("Deleted Node: %d", head->data);
    count--;
    if (count == 0)
    {
      printf("\nThe linked list had become empty now");
    }
    else
    {
      head = head->next;
      head->prev = tail;
    }
  }
}

void del_specific()
{
  if (head == NULL)
  {
    printf("\nThe linked list is empty");
  }
  else if (count == 1)
  {
    printf("The linked list has only one node\tDeleted Node: %d", head->data);
    head = NULL;
    tail = NULL;
    count--;
    printf("\nThe linked list has become empty now");
  }
  else
  {
    int num;
    printf("\nChoose a specific position from 1 to %d to delete from: ", count);
    scanf("%d", &num);

    if (num == 1)
    {
      printf("Deleted Node: %d", head->data);
      head = head->next;
      head->prev = tail;
    }
    else if (num == count)
    {
      printf("Deleted Node: %d", tail->data);
      tail = tail->prev;
      tail->next = head;
    }
    else
    {
      int i = 2;
      doublyy *temp = head;
      while (i <= num)
      {
        temp = temp->next;
        i++;
      }
      printf("Deleted Node: %d", temp->data);
      temp->prev->next = temp->next;
      temp->next->prev = temp->prev;
    }
    count--;
  }
}

void del_end()
{
  if (tail == NULL)
  {
    printf("\nThe linked list is empty");
  }
  else
  {
    printf("Deleted Node: %d", tail->data);
    count--;
    if (count == 0)
    {
      printf("\nThe linked list had become empty now");
    }
    else
    {
      tail = tail->prev;
      tail->next = head;
    }
  }
}

void display()
{
  if (head == NULL)
  {
    printf("\nThe linked list is empty");
  }
  else
  {
    printf("\nLinked List: ");
    doublyy *current = head;
    while (current != NULL)
    {
      printf("%d ", current->data);
      current = current->next;
      if (current == head)
      {
        break;
      }
    }
    free(current);
  }
}

void search()
{
  if (head == NULL)
  {
    printf("The linked list is empty");
  }

  else
  {
    int num, posi[count], address[count], index = 0, i = 1, count = 0;
    printf("Enter the number to search: ");
    scanf("%d", &num);
    doublyy *wow = head;
    while (wow != NULL)
    {
      if (wow->data == num)
      {
        posi[index] = i;
        address[index] = (int)wow;
        index++;
      }
      i++;
      wow = wow->next;
      if (wow == head)
      {
        break;
      }
    }
    if (index > 0)
    {
      printf("\nNumber of times %d appears in the linked list: %d", num, index);
      for (int i = 0; i < index; i++)
      {
        printf("\nAt Position: %d and Address: %d", posi[i], address[i]);
      }
    }
    else
    {
      printf("The number %d does not appear in the linked list", num);
    }
  }
}