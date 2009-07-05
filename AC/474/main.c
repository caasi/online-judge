#include<stdio.h>
#include<stdlib.h>
#define MAX_LEN 1000000

typedef struct fpnumber
{
	double head;
	int power;
} fpnumber;

int main(int argc, char *argv[])
{
	int exp, tmp, power, tail;
	double head;
	fpnumber *table[MAX_LEN + 1], *newnum;
	for(tmp = 0; tmp < MAX_LEN + 1; tmp++)
		table[tmp] = NULL;
	table[0] = (fpnumber *)malloc(sizeof(fpnumber)); 
	table[0]->head = 1.0;
	table[0]->power = 0;
	tail = 1;

	while(scanf("%d", &exp) == 1)
	{
		if(!table[exp])
		{
			for(tmp = tail; tmp <= exp; tmp++)
			{
				newnum = (fpnumber *)malloc(sizeof(fpnumber));
				newnum->head = table[tmp - 1]->head / 2;
				newnum->power = table[tmp - 1]->power;
				if(newnum->head < 1.0)
				{
					newnum->head *= 10.0;
					newnum->power += 1;
				}
				table[tmp] = newnum;
			}
			tail = exp + 1;
		}
		printf("2^-%d = %.3lfe-%d\n", exp, table[exp]->head, table[exp]->power);
	}

	for(tmp = 0; tmp < tail; tmp++)
		free(table[tmp]);
	return 0;
}
