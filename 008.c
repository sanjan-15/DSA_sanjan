#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 5
typedef struct myshop
{
   char name[20];
   int quantity;
   float price;
} myshop;
myshop myshopArray[SIZE], temp;
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

myshop peek()
{
   return myshopArray[top];
}

myshop pop()
{
   myshop data;

   if (!isempty())
   {
      strcpy(data.name, myshopArray[top].name);
      data.quantity = myshopArray[top].quantity;
      data.price = myshopArray[top].price;
      top = top - 1;
      return data;
   }
   else
   {
      printf("Could not retrieve data, Stack is empty.\n");
   }
}

myshop push(myshop data)
{

   if (!isfull())
   {
      top = top + 1;
      strcpy(myshopArray[top].name, data.name);
      myshopArray[top].quantity = data.quantity;
      myshopArray[top].price = data.price;
   }
   else
   {
      printf("Could not insert data, myshopArray is full.\n");
   }
}
void display()
{
   for (int i = top; i >= 0; i--)
   {
      printf("Stack index %d\nName : %s\nQuantity : %d\nPrice : %f\n\n", i, myshopArray[i].name, myshopArray[i].quantity, myshopArray[i].price);
   }
}

int main()
{
   int choice1, choice = 1;

   while (choice == 1)
   {
      printf("Enter 1 to push and 2 to pop and 3 to exit the struct array:\n");
      scanf("%d", &choice1);
      if (choice1 == 1)
      {
         printf("Enter name of the item \n");
         scanf("%s", &temp.name);
         printf("Enter no. of items\n");
         scanf("%d", &temp.quantity);
         printf("Enter price of item\n");
         scanf("%f", &temp.price);
         push(temp);
         printf("\nDisplaying stack elements\n\n");
         display();
      }
      else if (choice1 == 2)
      {
         temp = pop();
         if (!isempty())
         {
            printf("The popped out data is :\nName : %s\nQuantity : %d\nPrice : %f\n", temp.name, temp.quantity, temp.price);
            printf("\nDisplaying stack elements\n\n");
            display();
         }
      }
      else if (choice1 == 3)
      {
         exit;
      }
      printf("Enter 1 to continue and 2 to exit:\n");
      scanf("%d", &choice);
   }
}