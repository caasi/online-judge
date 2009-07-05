#include<stdio.h>
#include<string.h>

int print_post()
{
	int c;
	if((c = getchar()) != EOF)
	{
		switch(c)
		{
			case '+':
			case '-':
			case '*':
			case '/':
				print_post();
				print_post();
			default:
				putchar(c);
				break;
		}
	}
	return c;
}

int main(int argc, char *argv[])
{
	while(print_post() != EOF);
	return 0;
}

