#include<stdio.h>

int main()
{
    char a[20];
    printf("Enter character array\n");
    scanf("%[^\n]s",a);
    printf("Your character array is:\n");
    printf("%s",a);
}