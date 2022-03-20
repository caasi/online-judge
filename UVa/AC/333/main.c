#include<stdio.h>
#include<string.h>

char *trim(char *line)
{
	char *crt;
	while(*line && (*line == ' ' || *line == '\t'))
		line++;
	crt = line;
	while(*++line);
	while(--line != crt && (*line == ' ' || *line == '\t'));
	*(line + 1) = '\0';
	return crt;
}

int main(int argc, char *argv[])
{
	int c, count, tail, failed, sum;
	char line[81];
	int ISBN[10];
	count = 0;
	sum = 0;
	tail = 0;
	failed = 0;
	while(c = getchar())
	{
		switch(c)
		{
			case '\n':
				if(tail)
					{
					line[tail] = '\0';
					if(failed || count != 10)
						printf("%s is incorrect.\n", trim(line));
					else
					{
						if(sum % 11 == 0)
							printf("%s is correct.\n", trim(line));
						else
							printf("%s is incorrect.\n", trim(line));
						/* printf("sum: %d\n", sum); */
					}
				}
				else
					printf(" is incorrect.\n");
				count = 0;
				sum = 0;
				tail = 0;
				failed = 0;
				break;
			case EOF:
				return 0;
				break;
			case '\t':
			case ' ':
				if(count > 0 && count < 10)
					failed = 1;
				line[tail++] = c;
				break;
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
			case 'X':
				if(count < 10)
				{
					if(c == 'X')
					{
						if(count == 9)
						{
							sum += 10;
							count++;
						}
					}
					else
					{
						sum += (10 - count) * (c - '0');
						count++;
					}
				}
				else
					failed = 1;
			case '-':
				line[tail++] = c;
				break;
			default:
				line[tail++] = c;
				if(count > 0)
					failed = 1;
		}
	}
	return 0;
}

