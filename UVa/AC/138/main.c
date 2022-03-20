#include<stdio.h>
#define MAX_LEN 10000000000

int main(int argc, char *argv[])
{
	long long int i, j, count;
	long long int sum, sqrt;

	i = 2;
	j = 0;
	sum = 1;
	count = 0;
	while (count < 10)
	{
		sum += i++;
		while (j < MAX_LEN && (sqrt = j * j) < sum)
			j++;
		if (j == MAX_LEN)
			break;
		if (sqrt == sum)
		{
			count++;
			printf("%lld, %lld\n", j, i - 1);
		}
	}
	return 0;
}

