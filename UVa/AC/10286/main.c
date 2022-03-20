#include<stdio.h>
#include<math.h>
#define PI 3.14159265

int main(int argc, char *argv[])
{
	double f, factor;
	factor = sin(9.0 * PI / 180) * (1.0 / tan(63 * PI / 180)) +cos(9.0 * PI / 180);
	while(scanf("%lf", &f) == 1)
		printf("%.10lf\n", f * factor);
	return 0;
}

