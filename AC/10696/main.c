#include<stdio.h>

int main(int argc, char *argv[])
{
	int num;
	while(scanf("%d", &num))
	{
		if(!num)
			break;
		printf("f91(%d) = %d\n", num, num <= 101 ? 91 : num - 10);
	}
	return 0;
}

