#include <stdio.h>
#include <stdlib.h>

void size_of_array(int *iteration)
{
	*iteration = 2 << (*iteration - 1); 
}


 void make_2d_array(int *arr[], int *iteration)
{
	for(int i = 0; i < *iteration; i++)
		arr[i] = (int *) malloc((i+1) * sizeof(int));
}


int is_even(int number)
{
	if(number%2 == 0)
		return 1;
	return 0;
}


void fill_2d_array(int *arr[], int *iteration)
{
	int number;
	for(int i = 0; i < *iteration; i++)
		for(int j = 0; j < i+1; j++)
			if(j == 0 || j == i)
				*(*(arr + i) + j) = 1;
			else
				{
					number = (*(*(arr + i-1) + j)) + (*(*(arr + i-1) + (j-1)));
					*(*(arr + i) + j) = number;
				}
}


void show_sierpinsky_triangle(int *arr[], int *iteration)
{
	int number;
	for(int i = 0; i < *iteration; i++)
	{
		for(int j = 0; j < i+1; j++)
		{
			number = *(*(arr + i) + j);
			if(is_even(number))
				printf("%c ", ' ');
			else{printf("%c ", '*');}
		}
		putchar('\n');
	}
}


int main()
{
	int iteration;
	scanf("%d",&iteration);
	size_of_array(&iteration);

	int *arr[iteration];
	make_2d_array(&*arr, &iteration);
	fill_2d_array(&*arr, &iteration);
	show_sierpinsky_triangle(&*arr, &iteration);
	return 0;
}