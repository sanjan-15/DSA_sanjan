#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr1, *arr2, n, i;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    arr1 = (int*) malloc(n * sizeof(int));
    arr2 = (int*) malloc(n * sizeof(int));

    printf("Enter the elements of array 1: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr1[i]);
    }
    printf("Enter the elements of array 2: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr2[i]);
    }

    for (i = 0; i < n; i++) {
        arr1[i] += arr2[i];
    }

    printf("Resultant array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr1[i]);
    }
    printf("\nAddress of array 1: %u\nAddress of array 2: %u\n", arr1, arr2);

    free(arr1);
    free(arr2);

    int newSize=n*2;
    arr1 = realloc(arr1, newSize * sizeof(int));
    printf("\nAddress of array 1 after realloc(): %p\n",arr1);
    return 0;
}
