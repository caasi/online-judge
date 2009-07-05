#include<stdio.h>
#include<stdlib.h>
#define LINE_LEN 255
#define MAX_LEN 9000

void getline(char *line)
{
	int c;
	int count = 0;
	while(count < LINE_LEN)
	{
		c = getchar();
		if(c == '\n' || c == EOF)
			break;
		line[count++] = c;
	}
	line[count] = '\0';
	return;
}

typedef struct fpnumber
{
	double head;
	int power;
} fpnumber;

int main(int argc, char *argv[])
{
	int times, exp, tmp, power, tail;
	double head;
	char round[7];
	char line[LINE_LEN + 1];
	fpnumber *table[MAX_LEN + 1], *newnum;
	for(tmp = 0; tmp < MAX_LEN + 1; tmp++)
		table[tmp] = NULL;
	table[0] = (fpnumber *)malloc(sizeof(fpnumber)); 
	table[0]->head = 1.0;
	table[0]->power = 0;
	tail = 1;

	getline(line);
	times = atoi(line);
	getline(line);
	while(times)
	{
		getline(line);
		if(line[0] == '\0')
		{
			times--;
			if(times)
				printf("\n");
		}
		else
		{
			exp = atoi(line);
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
			sprintf(round, "%.4lf", table[exp]->head);
			if(round[5] == '5')
				head = table[exp]->head + 0.0001;
			else
				head = table[exp]->head;
			printf("2^-%d = %.3lfE-%d\n", exp, head, table[exp]->power);
		}
	}

	for(tmp = 0; tmp < tail; tmp++)
		free(table[tmp]);
	return 0;
}
