#include<stdio.h>

int factor_table[1001][40]; 

int main(int argc, char *argv[])
{
	int times, num, i, j, min, tmp, result, a, b, c;

	/* build factor table */
	factor_table[1][0] = 1;
	factor_table[1][1] = 1;
	for(j = 1000; j >= 2; j--)
	{
		factor_table[j][0] = 1;
		factor_table[j][1] = 1;
		for(i = 2; i <= 1000; i++)
			if(j % i == 0)
			{
				factor_table[j][0]++;
				factor_table[j][factor_table[j][0]] = i;
			}
	}

	scanf("%d", &times);
	while(times)
	{
		scanf("%d", &num);
		min = 2 * num + 1;
		for(i = 1; i <= factor_table[num][0]; i++)
		{
			a = factor_table[num][i];
			tmp = num / a;
			for(j = 1; j <= factor_table[tmp][0]; j++)
			{
				b = factor_table[tmp][j];
				c = tmp / b;
				result = a * b + b * c + a * c;
				if(result < min)
					min = result;
			}
		}
		printf("%d\n", 2 * min);
		times--;
	}
	return 0;
}

