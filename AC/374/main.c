#include<stdio.h>

typedef struct number
{
	int base;
	int power;
	int extra;
} number;

int main(int argc, char *argv[])
{
	number num;
	int m, tmp;
	while(scanf("%d %d %d", &num.base, &num.power, &m) != EOF)
	{
		num.extra = 1;
		num.base %= m;
		if(num.power == 0)
		{
			printf("%d\n", num.extra);
			continue;
		}
		while(num.power != 1)
		{
			tmp = num.power & 0x01;
			if (tmp)
				num.extra *= num.base;
			num.extra %= m;
			num.power >>= 1;
			num.base *= num.base;
			num.base %= m;
		}
		printf("%d\n", (num.base * num.extra) % m);
	}
	return 0;
}
