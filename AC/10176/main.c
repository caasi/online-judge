#include<stdio.h>
#include<string.h>

int main(int argc, char *argv[])
{
	int c, num;
	const int prime = (0x01 << 17) - 1;
	num = 0;
	while((c = getchar()) != EOF)
	{
		if(c == '#')
		{
			if(num == 0)
				printf("YES\n");
			else
				printf("NO\n");
			num = 0;
		}
		else
		{
			if(c == '1' || c == '0')
			{
				num <<= 1;
				if(c == '1')
					num |= 0x01;
				num %= prime;
			}
		}
	}
	return 0;
}

