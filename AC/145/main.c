#include<stdio.h>
#define DAY 0
#define EVENING 1
#define NIGHT 2
double cost[5][3] = 
{
	{0.10, 0.06, 0.02},
	{0.25, 0.15, 0.05},
	{0.53, 0.33, 0.13},
	{0.87, 0.47, 0.17},
	{1.44, 0.80, 0.30}
};

int main(int argc, char *argv[])
{
	int sh, sm, eh, em, tmp, daycount, eveningcount, nightcount;
	char step, number[9];
	while(scanf("%c %s %02d %02d %02d %02d ", &step, number, &sh, &sm, &eh, &em))
	{
		if(step == '#')
			break;
		number[8] = '\0';

		daycount = 0;
		eveningcount = 0;
		nightcount = 0;
		sm += 60 * sh;
		em += 60 * eh;
		if(em <= sm)
			em += 1440;
		while(sm < em)
		{
			tmp = sm % 1440;
			if(tmp < 480)
				nightcount++;
			else if(tmp < 1080)
				daycount++;
			else if(tmp < 1320)
				eveningcount++;
			else
				nightcount++;
			sm++;
		}
		printf(
			"  %s%6d%6d%6d  %c%8.2lf\n",
			number,
			daycount,
			eveningcount,
			nightcount,
			step,
			daycount * cost[step - 'A'][DAY] +
			eveningcount * cost[step - 'A'][EVENING] +
			nightcount * cost[step - 'A'][NIGHT]
		);
	}
	return 0;
}

