#include <stdio.h>
#include <stdlib.h>

int size_of_array(int *iteration)
{
	*iteration = 2 << (*iteration - 1); 
}



int main()
{
	int iteration;
	scanf("%d",&iteration);
	size_of_array(&iteration);
	printf("%d\n", iteration);
	return 0;
}