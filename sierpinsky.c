#include <stdio.h>
#include <stdlib.h>

int size_of_array(int *iteration)
{
	*iteration = 2 << (*iteration - 1); 
}


int make_2d_array(int *arr[], int *iteration)
{
	for(int i = 0; i < *iteration; i++)
		arr[i] = (int *) malloc((i+1) * sizeof(int));
	(*iteration)++;
}


int main()
{
	int iteration;
	scanf("%d",&iteration);
	size_of_array(&iteration);

	int *arr[iteration];
	make_2d_array(&*arr, &iteration);
	
	return 0;
}