#include<stdio.h>

int main(int argc, char *argv[])
{
	long long int num;
	while(scanf("%lld", &num) == 1)
	{
		if(num < 0)
			break;
		printf("%lld\n", 1 + (num * num + num) / 2);
	}
	return 0;
}

