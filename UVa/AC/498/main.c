#include<stdio.h>
#define LINE_LEN 255
char buffer[LINE_LEN + 1];
int buffer_tail;

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

int int_pow(int num, int power)
{
	int tmp;
	if(power == 0)
		return 1;
	else
	{
		if(power % 2 == 0)
			return int_pow(num, power - 1) * num;
		else
		{
			tmp = int_pow(num, power / 2);
			return tmp * tmp;
		}
	}
}

int main(int argc, char *argv[])
{
	int i, j, sum, result, num, linenum, ctail, xtail;
	int c[1000], x[1000], xpow[1000];
	linenum = 0;
	ctail = 0;
	xtail = 0;
	xpow[0] = 1;
	while(1)
	{
		result = get_a_number(&num);
		if(ctail < 1000 && xtail < 1000)
		{
			if(linenum % 2 == 0)
				c[ctail++] = num;
			else
				x[xtail++] = num;
		}
		if(result == '\n')
		{
			linenum++;
			if(linenum % 2 == 0)
			{
				for(i = 0; i < xtail; i++)
				{
					for(j = 1; j < ctail; j++)
						xpow[j] = x[i] * xpow[j - 1];
					for(sum = 0, j = 0; j < ctail; j++)
						sum += c[j] * xpow[ctail - j - 1];
					printf("%d%c", sum, i == xtail - 1 ? '\n' : ' ');
				}
				ctail = 0;
			}
			else
				xtail = 0;
		}
		else if(result == EOF)
			break;
	}
	return 0;
}

