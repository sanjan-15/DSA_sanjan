#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 20
int stk[MAX];
int top = -1;

int isEmpty()
{
    return top == -1;
}
int isFull()
{
    return top == MAX - 1;
}
char peek()
{
    return stk[top];
}
char pop()
{
    if (isEmpty())
        return -1;
    char ch = stk[top];
    top--;
    return (ch);
}
void push(char oper)
{
    if (isFull())
        printf("Stack Full!!!!");

    else
    {
        top++;
        stk[top] = oper;
    }
}
void convertPostfixToInfix(char exp[])
{
    int i, l, j = 0;
    char a, b, op, tmp[20];
    strrev(exp);
    l = strlen(exp);
    for (i = 0; i < l; i++)
    {
        if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/' || exp[i] == '^')
            push(exp[i]);
        else
        {
            tmp[j++] = exp[i];
            tmp[j++] = pop();
        }
    }
    tmp[j] = exp[top--];
    strrev(tmp);
    puts(tmp);
}
int main()
{
    char exp[20];
    printf("Enter the expression:\n");
    gets(exp);
    convertPostfixToInfix(exp);
    return 0;
}