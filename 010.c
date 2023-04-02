#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 5
typedef struct mystructure
{
    char name[20];
    int marks;
} mystructure;
mystructure MyDivBy5Stack[SIZE], temp;
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

    if (top == SIZE)
        return 1;
    else
        return 0;
}

mystructure peek()
{
    return MyDivBy5Stack[top];
}

mystructure pop()
{
    mystructure data;

    if (!isempty())
    {
        strcpy(data.name, MyDivBy5Stack[top].name);
        data.marks = MyDivBy5Stack[top].marks;
        top = top - 1;
        return data;
    }
    else
    {
        printf("Could not retrieve data, Stack is empty.\n");
    }
}

mystructure push(mystructure data)
{

    if (!isfull())
    {
        top = top + 1;
        strcpy(MyDivBy5Stack[top].name, data.name);
        MyDivBy5Stack[top].marks = data.marks;
    }
    else
    {
        printf("Could not insert data, MyDivBy5Stack is full.\n");
    }
}
void display()
{
    for (int i = top; i >= 0; i--)
    {
        printf("Stack index %d\nName : %s\nQuantity : %d\n\n", i, MyDivBy5Stack[i].name, MyDivBy5Stack[i].marks);
    }
}

int main()
{
    mystructure s[10];
    for (int i = 0; i < 10; i++)
    {
        printf("Enter name of student %d\n", i + 1);
        scanf("%s", &s[i].name);
        printf("Enter marks:\n");
        scanf("%d", &s[i].marks);
    }
    for (int i = 0; i < 10; i++)
    {
        if (s[i].marks % 5 == 0)
            push(s[i]);
    }
    temp = peek();
    printf("Top most element of the stack is :\n%s\n%d\n", temp.name, temp.marks);
    int temp1 = top;
    for (int i = 0; i <= top; i++)
    {
        if (MyDivBy5Stack[i].marks == 5 || MyDivBy5Stack[i].marks == 25)
        {
            top = i;
            temp = pop();
            printf("Students with marks 5 or 25 are:\nName: %s\nMarks: %d\n", temp.name, temp.marks);
        }
        top = temp1;
    }
    printf("Final result of all the operations are:\n");
    display();
}