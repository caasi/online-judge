#include<stdio.h>
#include<math.h>

int main(int argc, char *argv[])
{
	int times;
	int players, which_one;
	double chance, tmp1, tmp2;
	scanf("%d", &times);
	while(times)
	{
		scanf("%d%lf%d", &players, &chance, &which_one);
		if(chance == 0.0)
		{
			printf("0.0000\n");
			times--;
			continue;
		}
		tmp1 = pow(1.0 - chance, which_one - 1.0);
		tmp2 = pow(1.0 - chance, (double)players);
		printf("%.4lf\n", chance * tmp1 / (1 - tmp2));
		times--;
	}
	return 0;
}

