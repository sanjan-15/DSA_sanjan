#include <stdio.h>
#include <stdlib.h>

void addNode(int data);
int countNodes();

void display();

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;
struct node *tail = NULL;

void addNode(int data)
{

    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {

        tail->next = newNode;

        tail = newNode;
    }
}
int countNodes()
{
    int count = 0;

    struct node *current = head;

    while (current != NULL)
    {

        count++;
        current = current->next;
    }
    return count;
}

void display()
{

    struct node *current = head;

    if (head == NULL)
    {

        return;
    }
    printf("Nodes of singly linked list: \n");
    while (current != NULL)
    {

        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main()
{
    int no_nodes, i = 0, ll_data;
    printf("Enter the number of nodes you want in the linked list: ");
    scanf("%d", &no_nodes);

    // while loop to ask for data.
    //  The while loop will be true as long as the loop counter is not equal to the no of nodes entered by the user

    while (i < no_nodes)
    {
        printf("Enter the data for Node %d: ", i + 1);
        scanf("%d", &ll_data);
        addNode(ll_data);
        i++;
    }

    display();

    printf("Count of nodes present in the list: %d", countNodes());

    return 0;
}