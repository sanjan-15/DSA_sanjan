#include <stdio.h>
#include<stdlib.h>
#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

void enqueue(int data)
{
    if (rear == SIZE - 1)
        printf("Queue is full\n");
    else
    {
        if (front == -1)
            front = 0;
        rear++;
        queue[rear] = data;
    }
}
int dequeue()
{
    int data;
    if (rear == -1)
        printf("Queue is empty\n");
    else
    {
        data = queue[front];
        front++;
        if (front > rear)
            front = rear = -1;
    }
    return data;
}
void display()
{
    int i;
    if (rear == -1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Elements of the queue are:\n");
        for (i = front; i <= rear; i++)
            printf("%d\n",queue[i]);
        printf("\n");
    }
}

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
            scanf("%d",&value);
            enqueue(value);
            display();
        }
        else if (choice1 == 2)
        {
            value = dequeue();
            if (rear!=-1)
            {
                printf("The dequeued value is :\n%d",value);
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