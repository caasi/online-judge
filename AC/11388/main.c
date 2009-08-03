#include<stdio.h>

int main(int argc, char *argv[])
{
	int times, gcd, lcm;
	scanf("%d ", &times);
	while(times--)
	{
		scanf("%d%d", &gcd, &lcm);
		if(lcm % gcd == 0)
			printf("%d %d\n", gcd, lcm);
		else
			printf("-1\n");
	}
	return 0;
}

