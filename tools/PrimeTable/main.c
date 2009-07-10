#include<stdio.h>
#include<string.h>
#define LIMIT 65000

int is_prime[LIMIT + 1];

void build_prime_table()
{
	unsigned int i, j, p;
	is_prime[0] = 0;
	is_prime[1] = 0;
	is_prime[2] = 1;
	is_prime[3] = 1;
	is_prime[5] = 1;
	for(i = 1; 6 * i < LIMIT; i++)
	{
		is_prime[6 * i + 1] = 1;
		is_prime[6 * i + 5] = 1;
	}
	
	for(i = 5; i < 65000; i++)
		if(is_prime[i])
			for(j = i << 1; j  < 65000; j += i)
				is_prime[j] = 0;
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
