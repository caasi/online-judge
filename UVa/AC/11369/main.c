#include<stdio.h>

int main(int argc, char *argv[])
{
	int times, num, n, i, j, discount;
	int items[20000];
	
	scanf("%d", &times);
	while(times)
	{
		scanf("%d", &num);
		for(i = 0; i < num; i++)
		{
			scanf("%d", &n);
			for(j = i - 1; j >= 0; j--)
				if(items[j] < n)
					items[j + 1] = items[j];
				else
				{
					items[j + 1] = n;
					break;
				}
			if(j == -1)
				items[0] = n;
		}
		/*
		for(i = 0; i < num; i++)
			printf("%d, ", items[i]);
		printf("\n");
		*/
		discount = 0;
		for(i = 1; i <= num / 3; i++)
			discount += items[3 * i - 1];
		printf("%d\n", discount);
		times--;
	}
	return 0;
}

