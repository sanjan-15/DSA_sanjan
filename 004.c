#include <stdio.h>
#include <string.h>

int MAXSIZE = 5;
int stack[5];
int top = -1;

int isfull()
{
    if (top == MAXSIZE)
        return 1;
    else
        return 0;
}

int isempty()
{
    if (top == -1)
        return 1;
    else
        return 0;
}
int push(int data)
{
    if (!isfull())
    {
        top = top + 1;
        stack[top] = data;
    }
    else
    {
        printf("Sorry,stack is full\n");
    }
}
int pop()
{
    if (!isempty())
    {
        int data = stack[top];
        top = top - 1;
        return data;
    }
    else
    {
        printf("Sorry,stack is empty\n");
    }
}
int main()
{
    char ch[20], ch1[] = "continue";
    while (strcmp(ch1, "continue") == 0)
    {
        printf("Do you want to 'push' or 'pop' or 'show' elements of stack?\n");
        scanf("%s", ch);
        while (strcmp(ch, "push") == 0 || strcmp(ch, "pop") == 0)
        {
            if (strcmp(ch, "push") == 0)
            {
                int a;
                printf("Enter push value\n");
                scanf("%d", &a);
                push(a);
            }
            else if (strcmp(ch, "pop") == 0)
            {
                int b = pop();
                printf("%d\n", b);
            }
            printf("Do you want to 'push', 'pop' or 'continue'?\n");
            scanf("%s",&ch);
        }
        printf("Elements of of the stack are: \n");

        while (!isempty())
        {
            int data = pop();
            printf("%d\n", data);
        }
        printf("Do you want to 'continue' or 'exit'\n");
        scanf("%s", ch1);
    }
}