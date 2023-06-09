#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define max 20
char stk[max];
int top = -1;

int isEmpty()
{
    return top == -1;
}
int isFull()
{
    return top == max - 1;
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
int checkIfOperand(char ch)
{
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}
int precedence(char ch)
{
    switch (ch)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    }
    return -1;
}
int convertInfixToPostfix(char *exp)
{
    int i, j;
    for (i = 0, j = -1; exp[i]; ++i)
    {
        if (checkIfOperand(exp[i]))//here we use the function to check whether the element in the loop is an alphabet
            exp[++j] = exp[i];
        else if (exp[i] == '(')//this is for opening bracket
            push(exp[i]);
        else if (exp[i] == ')')//this is for closing bracket where we pop off the previous operators till the previously opened bracket
        {
            while (!isEmpty() && peek() != '(')//this is for popping operators between brackets
                exp[++j] = pop();
            if (!isEmpty() && peek() != '(')//this return error
                return -1;
            else
                pop();//this pops off the brackets
        }
        else
        {
            while (!isEmpty() && precedence(exp[i]) <= precedence(peek()))//this checks precedence of operators outside brackets and pops them when somethg with equal or less precedence cpmes off
                exp[++j] = pop();
            push(exp[i]);
        }
    }
    while (!isEmpty())
        exp[++j] = pop();
    exp[++j] = '\0';
    printf("%s", exp);
}
int main()
{
    char exp[19];
    printf("Enter expression:\n");
    scanf("%s", &exp);
    convertInfixToPostfix(exp);
    return 0;
}