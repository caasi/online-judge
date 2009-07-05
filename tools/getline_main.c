#include<stdio.h>
#include<string.h>
#define LINE_LEN 255
char line[LINE_LEN+1];

int getline()
{
	int c, count;
	count = 0;
	while(count < LINE_LEN)
	{
		c = getchar();
		if(c == '\n' || c == EOF)
			break;
		line[count++] = c;
	}
	line[count] = '\0';
	return count;
}

int main(int argc, char *argv[])
{
	return 0;
}

