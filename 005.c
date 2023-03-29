#include <stdio.h>

int MAXSIZE = 10;
int MyDivBy5Stack[10];
int top = -1;

int isempty()
{

    if (top == -1)
        return 1;
    else
        return 0;
}

int isfull()
{

    if (top == MAXSIZE)
        return 1;
    else
        return 0;
}

int peek()
{
    return MyDivBy5Stack[top];
}

int pop()
{
    int data;

    if (!isempty())
    {
        data = MyDivBy5Stack[top];
        top = top - 1;
        return data;
    }
    else
    {
        printf("Could not retrieve data, Stack is empty.\n");
    }
}

int push(int data)
{

    if (!isfull())
    {
        top = top + 1;
        MyDivBy5Stack[top] = data;
    }
    else
    {
        printf("Could not insert data, Stack is full.\n");
    }
}
int main()
{
    int i, MyNumbers[10];
    printf("Enter 10 elements into the array\n");
    for (i = 0; i < 10; i++)
    {
        scanf("%d", &MyNumbers[i]);
    }
    for (i = 0; i < 10; i++)
    {
        if (MyNumbers[i] % 5 == 0)
        {
            push(MyNumbers[i]);
        }
    }
    printf("Element on top of the stack is: %d\n", peek());
    int temp = top;
    printf("The 5 and 25 preaent are:\n");
    for (i = 0; i <= top; i++)
    {
        if (MyDivBy5Stack[i] == 5 || MyDivBy5Stack[i] == 25)
        {
            top = i;
            printf("%d\n", pop());
        }
        top = temp;
    }
    printf("The final elements of  the stack are:\n");
    while (!isempty())
    {
        int data = pop();
        printf("%d\n", data);
    }
}