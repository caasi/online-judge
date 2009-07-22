#include<stdio.h>
#include<stdlib.h>

typedef struct utm
{
	unsigned long long int *m;
	int w;
}utm;

utm *utm_create(int w)
{
	int i;
	utm *ret = (utm *)malloc(sizeof(utm));
	ret->m = (unsigned long long int *)malloc((w * w + w) / 2 * sizeof(unsigned long long int));
	ret->w = w;
	for(i = (w * w + w) / 2 - 1; i >= 0; i--)
		ret->m[i] = 0;
	return ret;
}

void utm_delete(utm *u)
{
	if(u)
		free(u->m);
	free(u);
	return;
}

unsigned long long int utm_get(utm *u, int x, int y)
{
	unsigned long long int tmp;
	if(!u)
		return 0;
	if(x >= u->w || y >= u->w)
		return 0;
	if(x < y)
	{
		tmp = x;
		x = y;
		y = tmp;
	}
	return u->m[x + u->w * y - (y * y + y) / 2];
}

void utm_set(utm *u, unsigned long long int num, int x, int y)
{
	unsigned long long int tmp;
	if(!u)
		return;
	if(x >= u->w || y >= u->w)
		return;
	if(x < y)
	{
		tmp = x;
		x = y;
		y = tmp;
	}
	u->m[x + u->w * y - (y * y + y) / 2] = num;
	return;
}

unsigned long long int combination(utm *u, int k, int m)
{
	unsigned long long int tmp;
	if(!u)
		return 0;
	if(!m || k == m)
		return 1;
	tmp = utm_get(u, k - m, m);
	if(!tmp)
	{
		tmp = combination(u, k - 1, m) + combination(u, k - 1, m - 1);
		utm_set(u, tmp, k - m, m);
	}
	return tmp;
}

unsigned long long int factorial(utm *u, int n)
{
	unsigned long long int tmp;
	if(!u)
		return 0;
	if(!n)
		return 1;
	if(n % 2 == 0)
	{
		tmp = factorial(u, n / 2);
		return combination(u, n, n / 2) * tmp * tmp;
	}
	else
		return n * factorial(u, n - 1);
}

int main(int argc, char *argv[])
{
	int i, j;
	utm *cmb;
	cmb = utm_create(11);
	for(j = 0; j < 11; j++)
		for(i = 0; i < 11; i++)
			printf("%6llu%c", combination(cmb, i + j, j), i == 10 ? '\n' : ',');
	for(i = 0; i <= 20; i++)
		printf("%2d!: %llu\n", i, factorial(cmb, i));
	utm_delete(cmb);
	return 0;
}
