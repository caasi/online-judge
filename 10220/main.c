#include<stdio.h>
#include<stdlib.h>
#define MAX_DIGITS 10000
typedef struct number
{
	int digits[MAX_DIGITS];
} number;
number nums[1000];

number *number_create(int num)
{
	int i, count;
	number *ret = (number *)malloc(sizeof(number));
	for(i = 0; i < MAX_DIGITS; i++)
		ret->digits[i] = 0;
	count = 0;
	while(num)
	{
		ret->digits[count++] = num % 10;
		num /= 10;
	}
	return ret;
}

void number_multiply(number *a, int num)
{	
	int i, len_a;
	for(i = 0; i < MAX_DIGITS; i++)
		a->digits[i] *= num;
	for(i = 0; i < MAX_DIGITS - 1; i++)
	{
		a->digits[i + 1] += a->digits[i] / 10;
		a->digits[i] %= 10;
	}
	i = 0;
	return;
}

int main(int argc, char *argv[])
{
	int i, num, result;
	nums[0].digits[0] = 1;
	for(i = 1; i < 1000; i++)
	{
		nums[i] = nums[i - 1];
		number_multiply(&nums[i], i + 1);
	}
	while(scanf("%d", &num) != EOF)
	{
		/*
		a = number_create(1);
		for(i = 1; i < num; i++)
			number_multiply(a, i + 1);
		*/
		result = 0;
		for(i = 0; i < MAX_DIGITS; i++)
			result += nums[num - 1].digits[i];
		printf("%d\n", result);
	}
	return 0;
}

