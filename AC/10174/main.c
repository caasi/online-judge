#include<stdio.h>
#include<string.h>
#define MAX_LINE 255
char buffer[MAX_LINE + 1];

int get_numbers(int *num1, int *num2, int *quit)
{
	int c, count, got;
	got = 0;
	count = 0;
	while(c = getchar())
	{
		if(isdigit(c) || c == '-')
			buffer[count++] = c;
		else if(count)
		{
			buffer[count] = '\0';
			if(got == 0)
				*num1 = atoi(buffer);
			else if(got == 1)
				*num2 = atoi(buffer);
			got++;
			count = 0;
		}
		if(c == '\n')
			break;
		if(count == MAX_LINE)
			break;
		if(c == EOF)
		{
			*quit = 1;
			break;
		}
	}
	return got;
}

int main(int argc, char *argv[])
{
	int num1, num2, a, b, result, quit;
	quit = 0;
	while(result = get_numbers(&num1, &num2, &quit))
	{
		if(result == 1)
		{
			if(num1 % 2 == 0)
			{
				if(num1 % 4 != 0)
					printf("Bachelor Number.\n");
				else
				{
					if(num1 >= 0)
						printf("%d %d\n", num1 / 4 + 1, num1 / 4 - 1);
					else
						printf("%d %d\n", -1 - num1 / 4, 1 - num1 / 4);
				}
			}
			else
				if(num1 >= 0)
					printf("%d %d\n", num1 / 2 + 1, num1 / 2);
				else
					printf("%d %d\n", -num1 / 2, 1 - num1 / 2);
				
		}
		else if(result == 2)
		{
			if(num2 >= 0 && num1 >= 0)
			{
				num2 = (num2 + 2) / 4;
				num1 = (num1 + 1) / 4;
				printf("%d\n", num2 - num1);
			}
			else if(num2 > 0 && num1 < 0)
			{
				num2 = (num2 + 2) / 4;
				num1 = (2 - num1) / 4;
				printf("%d\n", num1 + num2);
			}
			else if(num2 <= 0 && num1 <= 0)
			{
				num2 = (1 - num2) / 4;
				num1 = (2 - num1) / 4;
				printf("%d\n", num1 - num2);
			}
		}
		if(quit)
			break;
	}
	return 0;
}

