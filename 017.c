#include <stdio.h> 
#include <stdlib.h> 
#define MAX 10

int front = -1,rear=-1;
typedef struct queue{
    int pq[MAX];
    int priority[MAX],value,pri;
}queue;
int main()
{
  queue a1;
  int choice;
  while (1)
  {
    printf("Enter 1 to enqueue and 2 to dequeue and 3 to exit the struct array:\n");
    scanf("%d", &choice);
    if (choice == 1)
    {
      printf("Enter value to be in queue and its priority\n");
      scanf("%d%d", &a1.value,&a1.pri);
      enqueue(a1);
      display();
    }
    else if (choice == 2)
    {
      a1.value = dequeue();
      if (rear != -1)
      {
        printf("The dequeued value is :\n%d", a1.value);
        display();
      }
    }
    else if (choice == 3)
    {
      exit;
    }
  }
}
void enqueue(queue a1)
{
    queue q1;
    if(rear>=MAX-1)
    printf("Queue is FULL!!!");
    if(front==-1&&rear==-1)
    {
        front++;
        rear++;
        q1.pq[rear]=a1.value;
        q1.priority[rear]=a1.pri;
    }
}
