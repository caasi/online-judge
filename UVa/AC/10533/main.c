#include<stdio.h>
#define LINE_LEN 255
char buffer[LINE_LEN + 1];
int buffer_tail;
int primes[168]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,199,211,223,227,229,233,239,241,251,257,263,269,271,277,281,283,293,307,311,313,317,331,337,347,349,353,359,367,373,379,383,389,397,401,409,419,421,431,433,439,443,449,457,461,463,467,479,487,491,499,503,509,521,523,541,547,557,563,569,571,577,587,593,599,601,607,613,617,619,631,641,643,647,653,659,661,673,677,683,691,701,709,719,727,733,739,743,751,757,761,769,773,787,797,809,811,821,823,827,829,839,853,857,859,863,877,881,883,887,907,911,919,929,937,941,947,953,967,971,977,983,991,997};
int is_digit_prime[1000000];

int get_a_char()
{
	if(buffer_tail)
		return buffer[--buffer_tail];
	else
		return getchar();
}

void put_a_char(char c)
{
	buffer[buffer_tail++] = c;
	return;
}

/* get a number before \n */
int get_a_number(int *num)
{
	int count = 0, c, negtive = 0;
	char line[LINE_LEN + 1];
	while(count < LINE_LEN)
	{
		c = get_a_char();
		if(c == '\n' || c == EOF)
			break;
		/* got a number */
		if(count && !isdigit(c))
		{
			put_a_char(c);
			break;
		}
		if(isdigit(c))
			line[count++] = c;
		if(c == '-' && !negtive)
		{
			line[count++] = c;
			negtive = 1;
		}
	}
	line[count] = '\0';
	if(num)
		*num = atoi(line);
	return c;
}

int is_prime(int num)
{
	int i, p;
	if(num == 1)
		return 0;
	if(num != 2 && num % 2 == 0)
		return 0;
	for(i = 0; i < 168; i++)
	{
		p = primes[i];
		if(p * p > num)
			return 1;
		if(num % p == 0)
			return 0;
	}
	return 1;
}

int digit_sum(int num)
{
	int ret = 0;
	while(num)
	{
		ret += num;
		num /= 10;
		ret -= 10 * num;
	}
	return ret;
}

int main(int argc, char *argv[])
{
	int c, times, a, b, count;

	is_digit_prime[2] = 1;
	is_digit_prime[3] = 1;
	is_digit_prime[5] = 1;
	for(a = 1; a < 1000000 / 6; a++)
	{
		b = 6 * a + 1;
		if(is_prime(b) && is_prime(digit_sum(b)))
			is_digit_prime[b] = 1;
		b = 6 * a + 5;
		if(is_prime(b) && is_prime(digit_sum(b)))
			is_digit_prime[b] = 1;
	}
	for(a = 1; a < 1000000; a++)
		is_digit_prime[a] += is_digit_prime[a - 1];

	scanf("%d", &times);
	while(times)
	{
		scanf("%d%d", &a, &b);

		if(a == 0)
			a = 1;
		count = is_digit_prime[b] - is_digit_prime[a - 1];
		printf("%d\n", count);

		times--;
	}
	return 0;
}

