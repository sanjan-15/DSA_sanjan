#include <stdio.h>
#include<stdlib.h>
#define SIZE 5
int front = -1;
int rear = -1;
int cirqueue[SIZE];
int main()
{
  int value;
  int choice1, choice = 1;

  while (choice == 1)
  {
    printf("Enter 1 to enqueue and 2 to dequeue and 3 to exit the struct array:\n");
    scanf("%d", &choice1);
    if (choice1 == 1)
    {
      printf("Enter value to be in queue \n");
      scanf("%d", &value);
      enqueue(value);
      display();
    }
    else if (choice1 == 2)
    {
      value = dequeue();
      if (rear != -1)
      {
        printf("The dequeued value is :\n%d", value);
        display();
      }
    }
    else if (choice1 == 3)
    {
      exit;
    }
    printf("Enter 1 to continue and 2 to exit:\n");
    scanf("%d", &choice);
  }
}
void enqueue(int x)
{
  if (front == -1 && rear == -1)
  {
    rear = 0;
    front = 0;
    cirqueue[rear] = x;
  }
  else if ((rear + 1) % SIZE == front)
  {
    printf("Cirqueue is full");
  }
  else
  {
    rear = (rear + 1) % SIZE;
    cirqueue[rear] = x;
  }
}
int dequeue()
{
  int data;
  if (rear == -1 && front == -1)
  {
    printf("CIRQUEUE IS EMPTY");
  }
  else if (front > rear)
  {
    front = rear = -1;
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
    printf("Cirque is empty");
  }
  else
  {
    printf("Queue circular is");
    while (i != rear)
    {
      printf("%d", cirqueue[i]);
      i = (i + 1) % SIZE;
    }
    printf("%d", cirqueue[i]);
  }
}