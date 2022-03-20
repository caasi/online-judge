#include<stdio.h>

int main(int argc, char *argv[])
{
	int v, t;
	while(scanf("%d%d", &v, &t) != EOF)
		printf("%d\n", (v * t) << 1);
	return 0;
}

