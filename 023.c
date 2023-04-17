#include <stdio.h>
#include <stdlib.h>

int main()
{
	int* ptr;
	int n, i;
	printf("Enter number of elements:");
	scanf("%d",&n);
	printf("Entered number of elements: %d\n", n);
	ptr = (int*)malloc(n * sizeof(int));
	if (ptr == NULL) {
		printf("Memory not allocated.\n");
		exit(0);
	}
	else {
		printf("Memory successfully allocated using malloc.\n");
		printf("The elements of the array are: ");
		for (i = 0; i < n; ++i) {
			printf("%d,%d\n ", ptr[i],&ptr[i]);
		}
	}
    free(ptr);
    int *ptr2;
    printf("Enter number of elements:");
	scanf("%d",&n);
    ptr2 = (int*)malloc(n*sizeof(int));
    if (ptr2 == NULL) {
		printf("Memory not allocated.\n");
		exit(0);
	}
	else {
		printf("Memory successfully allocated using malloc.\n");
		printf("The elements of the array are: ");
		for (i = 0; i < n; ++i) {
			printf("%d,%d\n ", ptr2[i],&ptr2[i]);
		}
	}

	return 0;
}
/*4.a)The malloc function takes one argument that specifies the size of the memory block to be allocated, in bytes.
    b)The calloc function is similar to malloc but it takes two arguments - the number of elements to be allocated and the size of each element. 
    Unlike malloc, calloc initializes the memory block to zero.
    c) The (int *) type-casting is required because malloc returns a void pointer, which needs to be cast to the appropriate pointer type.
*/
