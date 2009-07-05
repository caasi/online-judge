#include<stdio.h>
#include<string.h>
#define LIMIT 65000

int is_prime[LIMIT + 1];

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

int main(int argc, char *argv[])
{
	int limit, i;
	if(argc == 2 && isdigit(argv[1][0]))
	{
		limit = atoi(argv[1]);
		if(limit > LIMIT) limit = LIMIT;
		build_prime_table();
		printf("int is_prime[%d];\nvoid build_prime_table()\n{\n", limit + 1);
		for(i = 0; i <=  limit; i++)
			if(is_prime[i])
				printf("\tis_prime[%d] = 1;\n", i);
		printf("\treturn;\n}\n");
	}
	return 0;
}
