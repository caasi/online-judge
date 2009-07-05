#include<stdio.h>

int factor_table[101][25];

int is_prime[101];
void build_prime_table()
{
	is_prime[2] = 1;
	is_prime[3] = 2;
	is_prime[5] = 3;
	is_prime[7] = 4;
	is_prime[11] = 5;
	is_prime[13] = 6;
	is_prime[17] = 7;
	is_prime[19] = 8;
	is_prime[23] = 9;
	is_prime[29] = 10;
	is_prime[31] = 11;
	is_prime[37] = 12;
	is_prime[41] = 13;
	is_prime[43] = 14;
	is_prime[47] = 15;
	is_prime[53] = 16;
	is_prime[59] = 17;
	is_prime[61] = 18;
	is_prime[67] = 19;
	is_prime[71] = 20;
	is_prime[73] = 21;
	is_prime[79] = 22;
	is_prime[83] = 23;
	is_prime[89] = 24;
	is_prime[97] = 25;
	return;
}

int main(int argc, char *argv[])
{
	int i, j, tmp;
	build_prime_table();
	for(i = 0; i < 25; i++)
		factor_table[2][i] = 0;
	for(i = 2; i <= 100; i++)
	{
		for(j = 0; j < 25; j++)
			factor_table[i][j] = factor_table[i - 1][j];
		tmp = i;
		while(tmp != 1)
			for(j = 2; j <= 97;)
				if(is_prime[j] && tmp % j == 0)
				{
					tmp /= j;
					factor_table[i][is_prime[j] - 1]++;
				}
				else
					j++;
	}
	printf("int factor_table[][] =\n{\n");
	for(i = 2; i <= 100; i++)
	{
		printf("\t{");
		for(j = 0; j < 25; j++)
			printf("%2d%c", factor_table[i][j], j == 24 ? '}' : ',');
		printf("%c\n", i == 100 ? ' ' : ',');
	}
	printf("};\n");
	return 0;
}

