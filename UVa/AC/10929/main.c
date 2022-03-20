#include<stdio.h>
#include<string.h>

int main(int argc, char *argv[])
{
	int c, count, a, b;
	char line[1001];
	count = 0;
	a = b = 0;
	while((c = getchar()) != EOF)
	{
		if(c == '\n')
		{
			if(count == 1 && line[0] == '0')
				break;
			line[count] = '\0';
			if((a - b) % 11 == 0)
				printf("%s is a multiple of 11.\n", line);
			else
				printf("%s is not a multiple of 11.\n", line);
			count = 0;
			a = b = 0;
		}
		if(isdigit(c))
		{
			line[count++] = c;
			c -= '0';
			if(count & 0x01 == 1)
				a += c;
			else
				b += c;
		}
	}
	return 0;
}

