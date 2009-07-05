#include<stdio.h>

int int_abs(int num)
{
	return num < 0 ? -num : num;
}

int main(int argc, char *argv[])
{
	int num, i, prev, current;
	int numbers[3000];
	while(scanf("%d", &num) == 1)
	{
		for(i = 0; i < 3000; i++)
			numbers[i] = 0;
		scanf("%d", &prev);
		for(i = 1; i < num; i++)
		{
			scanf("%d", &current);
			numbers[int_abs(current - prev)] = 1;
			prev = current;
		}
		for(i = 1; i < num; i++)
			if(!numbers[i])
				break;
		if(i == num)
			printf("Jolly\n");
		else
			printf("Not jolly\n");
	}
	return 0;
}

