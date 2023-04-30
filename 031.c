#include <stdio.h>
#include <stdlib.h>
#define size 13

int front = -1, rear = -1;
char cirqueue[size];

void enqueue(char x)
{
    if (front == -1 && rear == -1)
    {
        rear = 0;
        front = 0;
        cirqueue[rear] = x;
    }
    else if ((rear + 1) % size == front)
    {
        printf("Cirqueue is full\n");
    }
    else
    {
        rear = (rear + 1) % size;
        cirqueue[rear] = x;
    }
}
char dequeue()
{
    char data;
    if (front == -1 && rear == -1)
    {
        printf("The cirqueue is empty\n");
    }
    else if (front == rear)
    {
        data = cirqueue[rear];
        front = rear = -1;
        return data;
    }
    else
    {
        data = cirqueue[rear];
        front = (front + 1) % size;
        return data;
    }
}
void display()
{
    int i = front;
    if (front == -1 && rear == -1)
    {
        printf("The cirqueue is empty\n");
    }
    else
    {
        printf("Components of the cirqueue are: ");
        while (i != rear)
        {
            printf("%c", cirqueue[i]);
            i = (i + 1) % size;
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
        printf("\nEnter 1 to enqueue , 2 to dequeue and 3 to exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter character to be enqueued\n");
            scanf(" %c", &value);
            enqueue(value);
            display();
            break;

        case 2:
            value = dequeue();
            if (front != -1 && rear != -1)
            {
                printf("The dequeued value is %d\n", value);
            }
            display();
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid option\n");
            break;
        }
    }
}