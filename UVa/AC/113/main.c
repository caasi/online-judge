#include<stdio.h>
#include<string.h>
#include<math.h>

int main(int argc, char *argv[])
{
	double k, p, n;

	while(scanf("%lf%lf", &n, &p) == 2)
		printf("%.0lf\n", exp(log(p)/n));
	return 0;
}

