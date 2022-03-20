#include<stdio.h>
char people[101];
int num;

void init_people()
{
	int i;
	for(i = 1; i <= 100; i++)
		people[i] = i;
	num = 0;
}

int survivor(int n, int k)
{
	int tmp;
	if(n <= 1)
		return 1;
	if(k > n)
		k %= n;
	tmp = survivor(n - 1, k);
	tmp = (tmp + k) % (n + 1);
	return tmp < k ? tmp : tmp + 1;
}

int main(int argc, char *argv[])
{
	int n, k, count, die, bury, i;
	while(scanf("%d%d", &n, &k) == 2 && n && k)
	{
		/*
		if(n == 1)
		{
			printf("1\n");
			continue;
		}
		*/
		init_people();
		for(die = 0, count = 0; count < n - 1; count++)
		{
			i = 0;
			while(i < k)
			{
				die++;
				if(die > n)
					die  = 1;
				if(people[die])
					i++;
			}
			people[die] = 0;
			bury = die;
			i = 0;
			while(i < k)
			{
				bury++;
				if(bury > n)
					bury = 1;
				if(people[bury])
					i++;
			}
			people[die] = people[bury];
			people[bury] = 0;
		}
		die = n - people[die] + 1;
		die %= n;
		die++;
		printf("%d\n", die);
	}
	return 0;
}

