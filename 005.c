#include <stdio.h>
#include<string.h>

int main()
{
    char favoriteDairyProduct[30];

    scanf("%s",favoriteDairyProduct);

    if(strcmp(favoriteDairyProduct, "cheese")==0)
    {
        printf("You like cheese too!");
    }
    else
    {
        printf("I like cheese more.");
    }

    return 0;
}