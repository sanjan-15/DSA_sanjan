#include<stdio.h>
 
int main()
{
    //int array
    int n,i;
    printf("Enter no. of elements of an array\n");
    scanf("%d",&n);
    int arr[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Your elements are:\n");
    for(i=0;i<n;i++)
    {
        printf("%d\n",arr[i]);
    }

    //character array(string)
    char a[20];
    printf("Enter character array\n");
    scanf("%s",&a);
    printf("Your character array is:\n");
    printf("%s",a);
}