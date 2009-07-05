#include<stdio.h>
#include<math.h>

int main(int argc, char *argv[])
{
	int times;
	long long int x, y, d, i, sq, mod, count;
	scanf("%d", &times);
	while(times)
	{
		scanf("%lld%lld", &x, &y);
		d = y - x;
		if(!d)
		{
			printf("0\n");
			times--;
			continue;
		}
		sq = floor(sqrt(d));
		count = 2 * sq - 1;
		mod = d - (sq * sq);
		for(i = sq; i >= 1; i--)
		{
			count += mod / i;
			mod %= i;
		}
		printf("%lld\n", count);
		times--;
	}
	return 0;
}

