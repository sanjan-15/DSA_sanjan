#include <stdio.h>
int main()
{
    typedef struct myshop
    {
        char name[20];
        int quantity;
        float price;
    } myshop;
    myshop myshopArray[5];
    for (int i = 0; i < 5; i++)
    {
        printf("Enter name of the item %d\n",i+1);
        scanf("%s", &myshopArray[i].name);
        printf("Enter no. of items\n");
        scanf("%d", &myshopArray[i].quantity);
        printf("Enter price of item\n");
        scanf("%f", &myshopArray[i].price);
    }
    for (int i = 0; i < 5; i++)
    {
        printf("The details entered are:\nName: %s\nQuantity:%d\nPrice: %f\n", myshopArray[i].name, myshopArray[i].quantity, myshopArray[i].price);
    }
}