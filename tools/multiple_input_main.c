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

int main(int argc, char *argv[])
{
	int num;
	while(get_a_number(&num))
		printf("%d\n", num);
	return 0;
}

