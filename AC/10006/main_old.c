#include<stdio.h>

int is_prime[65001];
int is_carmichael[65001];

void build_prime_table()
{
	unsigned int i, j;
	is_prime[0] = 0;
	is_prime[1] = 0;
	is_prime[2] = 1;
	for(i = 1; i < 32500; i++)
		is_prime[2 * i + 1] = 1;
	for(i = 1; i < 32500; i++)
		for(j = 2; j <= 65000 / (2 * i + 1); j++)
			is_prime[2 * i * j + j] = 0;
	return;
}

void build_carmichael_table()
{
	unsigned int i, j;
	for(i = 2; i <= 65000; i++)
		if(!is_prime[i])
		{
			for(j = i - 1; j >= 2; j--)
				if(a_power_n_mod_m(j, i, i) != j)
					break;
			if(j == 1)
				printf("\tis_carmichael[%d] = 1;\n", i);
			/*
				is_carmichael[i] = 1;
			*/
		}
	return;
}

int a_power_n_mod_m(unsigned int a, unsigned int n, unsigned int m)
{
	int tmp;
	if(!n)
		return 1;
	if(n%2)
		return a_power_n_mod_m(a, n - 1, m) * a % m;
	else
	{
		tmp = a_power_n_mod_m(a, n / 2, m);
		return tmp * tmp % m;
	}
}

int main(int argc, char *argv[])
{
	int num, i;
	build_prime_table();
	build_carmichael_table();
	/*
	while(scanf("%d", &num) == 1)
	{
		if(!num)
			break;
		if(is_carmichael[num])
			printf("The number %d is a Carmichael number.\n", num);
		else
			printf("%d is normal.\n", num);
	}
	*/
	return 0;
}

