#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct stack
{
	int *stuff;
	int length;
	int max;
} stack;
stack *primes;

stack *create_stack()
{
	stack *ret = (stack *)malloc(sizeof(stack));
	ret->stuff = (int *)malloc(2 * sizeof(int));
	ret->length = 0;
	ret->max = 2;
}

void delete_stack(stack **s)
{
	if(!s)
		return;
	free((*s)->stuff);
	free(*s);
	*s = NULL;
	return;
}

void double_stack(stack *s)
{
	s->max <<= 1;
	s->stuff = (int *)realloc(s->stuff, s->max * sizeof(int));
	return;
}

void push(stack *s, int num)
{
	if(!s)
		return;
	if(s->length == s->max)
		double_stack(s);
	s->stuff[s->length++] = num;
	return;
}

int pop(stack *s)
{
	if(!s->length)
		return 0;
	return s->stuff[--s->length];
}

void build_prime_table(int limit)
{
	unsigned int i, j, prime;

	primes = create_stack();
	push(primes, 2);
	push(primes, 3);
	push(primes, 5);

	for(i = 1; ; i++)
	{
		if(6 * i + 1 > limit)
			break;
		for(j = 0; j < primes->length; j++)
		{
			prime = primes->stuff[j];
			if(prime * prime > 6 * i + 1)
			{
				push(primes, 6 * i + 1);
				break;
			}
			if((6 * i + 1) % prime == 0)
				break;
		}
		if(6 * i + 5 > limit)
			break;
		for(j = 0; j < primes->length; j++)
		{
			prime = primes->stuff[j];
			if(prime * prime > 6 * i + 5)
			{
				push(primes, 6 * i + 5);
				break;
			}
			if((6 * i + 5) % prime == 0)
				break;
		}
	}
	return;
}

int main(int argc, char *argv[])
{
	int i;
	build_prime_table(1000000);
	for(i = 0; i < primes->length; i++)
		printf("%d\n", primes->stuff[i]);
	delete_stack(&primes);
	return 0;
}
