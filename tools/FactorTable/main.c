#include<stdio.h>
#include<string.h>
#define LIMIT 1000

int factors[LIMIT + 1][LIMIT + 1];

int main(int argc, char *argv[])
{
	int num, i, j, count;
	if(argc == 2 && isdigit(argv[1][0]))
	{
		num = atoi(argv[1]);
		if(num > LIMIT) num = LIMIT;

		factors[1][0] = 1;
		factors[1][1] = 1;
		for(j = num; j >= 2; j--)
		{
			factors[j][0] = 1;
			factors[j][1] = 1;
			for(i = 2; i <= num; i++)
				if(j % i == 0)
				{
					factors[j][0]++;
					factors[j][factors[j][0]] = i;
				}
		}
		printf("int factor_table[%d][40] = \n{\n", num + 1);
		for(j = 1; j <= num; j++)
		{
			printf("\t{");
			for(i = 0; i < 40; i++)
				printf("%d%c", factors[j][i], i == 39 ? '}' : ',');
			printf("%s", j == num ? "\n" : ",\n");
		}
		printf("};\n");
	}
	return 0;
}

