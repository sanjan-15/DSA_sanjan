#include <stdio.h>
#include <stdlib.h>
#define SIZE 13

int front = -1;
int rear = -1;
char cirqueue[SIZE];

void enqueue(char x)
{
  if ((rear + 1) % SIZE == front)
  {
    printf("Circular queue is full\n");
  }
  else if (front == -1 && rear == -1)
  {
    rear = front = 0;
    cirqueue[rear] = x;
  }
  else
  {
    rear = (rear + 1) % SIZE;
    cirqueue[rear] = x;
  }
}

char dequeue()
{
  char data;

  if (front == -1 && rear == -1)
  {
    printf("Circular queue is empty\n");
  }
  else if (front == rear)
  {
    data = cirqueue[front];
    front = rear = -1;
    return data;
  }
  else
  {
    data = cirqueue[front];
    front = (front + 1) % SIZE;
    return data;
  }
}

void display()
{
  int i = front;

  if (front == -1 && rear == -1)
  {
    printf("Circular queue is empty\n");
  }
  else
  {
    printf("Componenets of circular queue are: ");
    while (i != rear)
    {
      printf("%c", cirqueue[i]);
      i = (i + 1) % SIZE;
    }
    printf("%c", cirqueue[i]);
  }
}

int main()
{
  char value;
  int choice;

  while (1)
  {
    printf("\nEnter 1 to enqueue, 2 to dequeue, and 3 to exit the program:\n");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
      printf("Enter a value to enqueue: ");
      scanf(" %c", &value);
      enqueue(value);
      display();
      break;

    case 2:
      value = dequeue();
      if (front != -1 && rear != -1)
      {
        printf("The dequeued value is: %c\n", value);
        display();
      }
      break;

    case 3:
      exit(0);

    default:
      printf("Invalid choice\n");
      break;
    }
  }
  return 0;
}
