#include<stdio.h>

void f(int a, int b)
{
	int tmp = a%b;
	if(tmp)
	{
		printf("%d,", a/b);
		f(b, tmp);
	}
	else
		printf("%d", a/b);
	return;
}

int main(int argc, char *argv[])
{
	int a, b, tmp;
	while(scanf("%d%d", &a, &b) == 2)
	{
		tmp = a%b;
		if(tmp)
		{
			printf("[%d;", a/b);
			f(b, tmp);
		}
		else
			printf("[%d", a/b);
		printf("]\n");
	}
	return 0;
}
