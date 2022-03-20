/* Q10018 Reverse and Add
 * Note:
 * Numbers like 9339 are palindrome.
 * Numbers which can't be palindrome by adding it's base 10 digits reverse
 * are Lychrel number, like 196
 */

#include<stdio.h>

long long int reverse_number(long long int num)
{
	long long int ret = 0;
	while(num)
	{
		ret *= 10;
		ret += num % 10;
		num /= 10;
	}
	return ret;
}

int main(int argc, char *argv[])
{
	int times, count;
	long long int num, rev;
	scanf("%d", &times);
	while(times)
	{
		scanf("%lld", &num);
		count = 0;
		rev = reverse_number(num);
		do
		{
			num += rev;
			count++;
		}
		while((rev = reverse_number(num)) != num);
		printf("%d %lld\n", count, num);
		times--;
	}
	return 0;
}

