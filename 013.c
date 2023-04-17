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
    int i,l=strlen(exp);
    char op,ch1,ch2,ping,tmp[20];
    for (i = 0; i < l; i++)
    {
        if((exp[i] >= 'a' && exp[i] <= 'z') || (exp[i] >= 'A' && exp[i] <= 'Z'))
        {
            push(exp[i]);
        }
        else
        {
            if(exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/' || exp[i] == '^')
            {
                op=exp[i];
                ch2=pop();
                ch1=pop();
                sprintf(ping,"(%s%s%s)",ch1,op,ch2);
                push(ping);
            }
        }
    }
    for(i=0;i<top;i++)
    {
        tmp[i]=pop();
    }
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