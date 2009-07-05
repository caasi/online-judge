#include<stdio.h>
#include<math.h>

int main(int argc, char *argv[])
{
	long long int num, res, sum;
	while(scanf("%lld", &num) == 1)
	{
		res = ceil((sqrt(1 + 8 * num) - 1) / (double)2.0);
		sum = ((res * res) + res) / (double)2.0;
		printf("%lld/%lld\n", sum - num + 1, num - sum + res);
	}
	return 0;
}
