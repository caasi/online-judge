#include<stdio.h>
#define SQUARE_WIDTH 2049
#define SQUARE_HEIGHT 2049

int test_square(int x, int y, int k, int tx, int ty)
{
	int result = 0;
	if(k > 512)
		return;
	if(k > 1)
		result +=
			test_square(x - k, y - k, k / 2, tx, ty) +
			test_square(x + k, y - k, k / 2, tx, ty) +
			test_square(x - k, y + k, k / 2, tx, ty) +
			test_square(x + k, y + k, k / 2, tx, ty);
	if(tx >= x - k && tx <= x + k && ty >= y - k && ty <= y + k)
		result++;
	return result;
}

int main(int argc, char *argv[])
{
	int k, x, y, i, j;
	while(scanf("%d%d%d", &k, &x, &y) == 3)
	{
		if(k == 0 && x == 0 && y == 0)
			break;
		printf("%3d\n", test_square(1024, 1024, k, x, y));
	}
	return 0;
}

