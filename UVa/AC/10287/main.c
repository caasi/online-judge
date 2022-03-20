#include<stdio.h>
#include<math.h>

int main(int argc, char *argv[])
{
	double f, f1, f2, f3, f4, sqrt_3, sqrt_7;
	sqrt_3 = sqrt(3);
	sqrt_7 = sqrt(7);
	f1 = sqrt_3 / 2.0;
	f2 = 2.0 * sqrt_3 - 3.0;
	f3 = sqrt_3 / 4.0;
	f4 = (6.0 * sqrt_7 - 7.0 * sqrt_3) / 10.0;
	while(scanf("%lf", &f) == 1)
	{
		printf("%.10lf ", f * f1);
		printf("%.10lf ", f * f2);
		printf("%.10lf ", f * f3);
		printf("%.10lf\n", f * f4);
	}
	return 0;
}

