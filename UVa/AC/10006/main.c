#include<stdio.h>

int is_carmichael[65001];

void build_carmichael_table()
{
	is_carmichael[561] = 1;
	is_carmichael[1105] = 1;
	is_carmichael[1729] = 1;
	is_carmichael[2465] = 1;
	is_carmichael[2821] = 1;
	is_carmichael[6601] = 1;
	is_carmichael[8911] = 1;
	is_carmichael[10585] = 1;
	is_carmichael[15841] = 1;
	is_carmichael[29341] = 1;
	is_carmichael[41041] = 1;
	is_carmichael[46657] = 1;
	is_carmichael[52633] = 1;
	is_carmichael[62745] = 1;
	is_carmichael[63973] = 1;
	return;
}

int main(int argc, char *argv[])
{
	int num, i;
	build_carmichael_table();
	while(scanf("%d", &num) == 1)
	{
		if(!num)
			break;
		if(is_carmichael[num])
			printf("The number %d is a Carmichael number.\n", num);
		else
			printf("%d is normal.\n", num);
	}
	return 0;
}

