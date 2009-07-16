#include<stdio.h>

long long int gcd(long int a, long int b)
{
	int tmp;
	while(1)
	{
		tmp = a % b;
		if(!tmp)
			break;
		a = b;
		b = tmp;
	}
	return b;
}

int main(int argc, char *argv[])
{
	long long int fnum, num, tmp, tmp2;
	while(scanf("%lld%lld", &fnum, &num) != EOF)
	{
		for(tmp = fnum, tmp2 = num; tmp >= 1; tmp--)
			tmp2 /= gcd(tmp2, tmp);
		if(tmp2 == 1)
			printf("%lld divides %lld!\n", num, fnum);
		else
			printf("%lld does not divide %lld!\n", num, fnum);
	}
	return 0;
}

