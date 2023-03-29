#include <stdio.h>
int main()
{
    typedef struct myshop{
        char name[20];
        int quantity;
        float price;
    }myshop;
    myshop bakery;
    printf("Enter name of the item\n");
    scanf("%s",&bakery.name);
    printf("Enter no. of items\n");
    scanf("%d",&bakery.quantity);
    printf("Enter price of item\n");
    scanf("%f",&bakery.price);
    printf("The details entered are:\nName: %s\nQuantity:%d\nPrice: %f\n",bakery.name,bakery.quantity,bakery.price);
    printf("Total price is %f",bakery.price*bakery.quantity);

}