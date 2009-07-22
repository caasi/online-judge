#include<stdio.h>
#include<stdlib.h>

typedef struct vector
{
	int max;
	int length;
	int *a;
} vector;

vector *vector_create()
{
	vector *ret = (vector *)malloc(sizeof(vector));
	ret->a = (int *)malloc(sizeof(int));
	ret->length = 0;
	ret->max = 1;
	return ret;
}

void vector_delete(vector *v)
{
	if(!v)
		return;
	free(v->a);
	free(v);
	return;
}

void vector_double(vector *v)
{
	if(!v)
		return;
	v->max <<= 1;
	v->a = (int *)realloc(v->a, v->max * sizeof(int));
	return;
}

void vector_push(vector *v, int num)
{
	if(!v)
		return;
	if(v->length == v->max)
		vector_double(v);
	v->a[v->length++] = num;
	return;
}

int vector_pop(vector *v)
{
	if(!v)
		return;
	if(v->length == 0)
		return -1;
	return v->a[v->length--];
}

int main(int argc, char *argv[])
{
	int i;
	vector *v;
	v = vector_create();
	for(i = 0; i < 10000; i++)
		vector_push(v, i + 1);
	vector_delete(v);
	v =  NULL;
	return 0;
}

