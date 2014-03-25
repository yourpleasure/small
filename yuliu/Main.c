#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define SOURCE_FILE "source.txt"
#define RESULT_FILE "result.txt"
#define ONCE 2000

typedef struct result_item{
	float sa;
	float sm;
	int count;
}result_list;
struct struct result{
	result_list *list;
	int count;
}result;
int main()
{
	FILE *source;
//	FILE *result;
	float *E;
	float *F;
	int total;
	int i;
	int j;
	result *final_result;

	source = fopen(SOURCE_FILE, "r");	
	E = (int *)malloc(ONCE * sizeof(float));
	F = (int *)malloc(ONCE * sizeof(float));
	final_result = (result *)malloc(sizeof(struct result));
	final_result->count = 0;
	final_result->list = (result_list *)malloc(ONCE * sizeof(struct result_item));
	memset(final_result->list, '\0', ONCE * sizeof(struct result_item));
	total = 0;
	if(EOF != fscanf(source, "%*d\t%f", &E[total])) total++;
	while(EOF != fscanf(source, "%*d\t%f", &E[total])){
		if(fabs(E[total]- E[total-1]) < 1E-6) continue;
		else total++;
	}

	F[0] = E[0];
	j = 1;
	for(i = 1; i < total - 1; i++){
		if((E[i] - E[i-1]) * (E[i] - E[i+1]) > 0){
			F[j] = E[i];
			j++;
		}
	}
	F[j] = E[total-1];

	memcpy(E, F, (j+1) * sizeof(float));

	free(E);
	free(F);
	exit(0);
}

int yuliu()
{
	float a, b, c;
	float m;
	int j;
	int k;

	c = fabs(E[1] - E[0]);
	F[0] = E[0];
	F[1] = E[1];
	k = 2;
	i = 2;
	while(i < total){
		a = fabs(E[i+1] - E[i]);
		b = fabs(E[i-1] - E[i]);
		if((a >= b) && (b < c)){
			b = (int)(b * 10000) / 10000.0;
			m = 0.5 * (E[i-1] + E[i]);
			m = (int)(m * 10000) / 10000.0;
			for(j = 0; j < final_result->count; j++){
				if((fabs(final_result->list[j].sa-b) < 1E-6) && (fabs(final_result->list[j].sm - m) < 1E-6)){
					final_result->list[j].count ++;
					break;
				}
			}
			if(j == final_result->count){
				final_result->list[j].sa = b;
				final_result->list[j].sm = m;
				final_result->list[j].count ++;
				final_result->count ++;
			}

		}
		else {
			F[k++] = E[i++];
		}

