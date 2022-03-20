#include<stdio.h>
#include<math.h>

int gcd(int a, int b)
{
	int tmp;
	while(1)
	{
		a %= b;
		if(!a)
			break;
		tmp = a;
		a = b;
		b = tmp;
	}
	return b;
}

int main(int argc, char *argv[])
{
	int i, j, num, count;
	int nums[50];
	while(scanf("%d", &num) != EOF)
	{
		if(!num)
			break;
		for(i = 0; i < num; i++)
			scanf("%d", &nums[i]);
		count = 0;
		for(i = 0; i < num; i++)
			for(j = i + 1; j < num; j++)
				if(gcd(nums[i], nums[j]) == 1)
					count++;
		if(count)
			printf("%.6lf\n", sqrt(3.0 * num * (num - 1) / count));
		else
			printf("No estimate for this data set.\n");
	}
	return 0;
}

