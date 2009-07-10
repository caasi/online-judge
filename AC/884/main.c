#include<stdio.h>
#include<stdlib.h>
int primes[78498];
int len;
int factorial[1000001];
int answer[1000001];

void build_prime_table(int limit)
{
	int i, j, prime;

	primes[len++] = 2;
	primes[len++] = 3;
	primes[len++] = 5;

	for(i = 1; ; i++)
	{
		if(6 * i + 1 > limit)
			break;
		for(j = 0; j < len; j++)
		{
			prime = primes[j];
			if(prime * prime > 6 * i + 1)
			{
				primes[len++] = 6 * i + 1;
				break;
			}
			if((6 * i + 1) % prime == 0)
				break;
		}
		if(6 * i + 5 > limit)
			break;
		for(j = 0; j < len; j++)
		{
			prime = primes[j];
			if(prime * prime > 6 * i + 5)
			{
				primes[len++] = 6 * i + 5;
				break;
			}
			if((6 * i + 5) % prime == 0)
				break;
		}
	}
	return;
}

int get_f(int num)
{
	int i, p, tmp;
	if(num == 1)
		return 0;
	if(!factorial[num])
	{
		for(i = 0, tmp = num; i < len; i++)
		{
			p = primes[i];
			if(p * p > tmp)
				break;
			if(tmp % p == 0)
			{
				tmp /= p;
				factorial[num]++;
				while(tmp % p == 0)
				{
					tmp /= p;
					factorial[num]++;
				}
				break;
			}
		}
		factorial[num] += get_f(tmp);
	}
	return factorial[num];
}

int main(int argc, char *argv[])
{
	int i, num;

	build_prime_table(1000000);
	for(i = len - 1; i >= 0 ; i--)
		factorial[primes[i]] = 1;
	answer[2] = 1;
	for(i = 3; i <= 1000000; i++)
		answer[i] = answer[i - 1] + get_f(i);
	while(scanf("%d", &num) == 1)
	{
		printf("%d\n", answer[num]);
	}
	return 0;
}

