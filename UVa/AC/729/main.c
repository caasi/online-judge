#include<stdio.h>
#include<string.h>
#define LINE_LEN 255

/* get a number before \n */
int get_a_number(int *num)
{
	int count = 0, c;
	char line[LINE_LEN + 1];
	while(count < LINE_LEN)
	{
		c = getchar();
		if(c == '\n' || c == EOF)
			break;
		/* got a number */
		if(count && !isdigit(c))
			break;
		if(isdigit(c))
			line[count++] = c;
	}
	line[count] = '\0';
	if(num)
		*num = atoi(line);
	return line[0];
}

short int hamming_distance(int num)
{
	int ret = 0;
	while(num)
	{
		if(num & 0x01)
			ret++;
		num >>= 1;
	}	
	return ret;
}

void print_binary(int num, int digits)
{
	int tmp = 1;
	tmp <<= digits - 1;
	while(digits)
	{
		printf("%d", num & tmp ? 1 : 0);
		num <<= 1;
		digits--;
	}
	return;
}

int main(int argc, char *argv[])
{
	char line[LINE_LEN + 1];
	int times, n, m, result;
	int i, tmp;

	get_a_number(&times);
	get_a_number(NULL);	
	while(times)
	{
		result = get_a_number(&m);
		if(!result)
		{
			if(times != 1)
				printf("\n");
			times--;
		}
		else
		{
			get_a_number(&n);
			tmp = 1;
			tmp <<= m;
			for(i = 0; i < tmp; i++)
			{
				if(hamming_distance(i) == n)
				{
					print_binary(i, m);
					printf("\n");
				}
			}
		}
	}
	return 0;
}
