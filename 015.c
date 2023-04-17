#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 5

int front = -1, rear = -1;
typedef struct test{
    char sub[20];
    int marks;
}test;
test myarr[SIZE];

test peek()
{
    return myarr[front];
}
void enqueue(test data)
{
    if (rear == SIZE - 1)
        printf("Queue is full\n");
    else
    {
        if (front == -1)
            front = 0;
        rear++;
        strcpy(myarr[rear].sub,data.sub);
        myarr[rear].marks = data.marks;
    }
}
test dequeue()
{
    test data;
    if (rear == -1)
        printf("Queue is empty\n");
    else
    {
        data.marks = myarr[front].marks;
        strcpy(data.sub,myarr[front].sub);
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
        printf("\nElements of the queue are:\n");
        for (i = front; i <= rear; i++)
            printf("%d)Subject: %s\nMarks: %d\n",i+1,myarr[i].sub,myarr[i].marks);
        printf("\n");
    }
}

int main()
{
    test temp;
    int choice1, choice = 1;

    while (1)
    {
        printf("Enter 1 to enqueue and 2 to dequeue, 3 to peek and 4 to exit the struct array:\n");
        scanf("%d", &choice1);
        if (choice1 == 1)
        {
            printf("Enter value to be in queue \n");
            printf("Enter subject and marks:\n");
            scanf("%s%d",&temp.sub,&temp.marks);
            enqueue(temp);
            display();
        }
        else if (choice1 == 2)
        {
            temp = dequeue();
            if (rear!=-1)
            {
                printf("The dequeued value is :\n%s\n%d",temp.sub,temp.sub);
                display();
            }
        }
        else if (choice1==3)
        {
            temp = peek();
            printf("The front most value in the queue is:\nSubject: %s\nMarks: %d\n",temp.sub,temp.marks);
        }
        
        else if (choice1 == 4)
        {
            exit(0);
        }
    }
}