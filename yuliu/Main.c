#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define SOURCE_FILE "source.txt"
#define RESULT_FILE "result.txt"
#define ONCE 1000

int main()
{
	FILE *source;
//	FILE *result;
	int *A;
	int total;
	int i;

	source = fopen(SOURCE_FILE, "r");	
	A = (int *)malloc(ONCE * sizeof(int));
	total = 0;
	while(fscanf(source, "%*d\t%d", &A[total++]));
	for(i = 0; i < total; i++){
		printf("%d\n", A[i]);
	}
	free(A);
	exit(0);
}
