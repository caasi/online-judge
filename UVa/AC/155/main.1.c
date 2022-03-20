#include<stdio.h>
#define SQUARE_WIDTH 2049
#define SQUARE_HEIGHT 2049
int plane[SQUARE_WIDTH][SQUARE_HEIGHT];

void init_plane()
{
	int i, j;
	for(i = 0; i < SQUARE_WIDTH; i++)
		for(j = 0; j < SQUARE_HEIGHT; j++)
			plane[i][j] = 0;
	return;
}

void increase_point(int x, int y)
{
	if((unsigned int)x >= SQUARE_WIDTH)
		return;
	if((unsigned int)y >= SQUARE_HEIGHT)
		return;
	plane[y][x]++;
}

void draw_square(int x, int y, int k)
{
	int i, j;
	if(k > 512)
		return;
	for(i = y - k; i <= y + k; i++)
		for(j = x - k; j <= x + k; j++)
			increase_point(j, i);
	if(k > 1)
	{
		draw_square(x - k, y - k, k / 2);
		draw_square(x + k, y - k, k / 2);
		draw_square(x - k, y + k, k / 2);
		draw_square(x + k, y + k, k / 2);
	}
	return;
}

int main(int argc, char *argv[])
{
	int k, x, y, i, j;
	while(scanf("%d%d%d", &k, &x, &y) == 3)
	{
		if(k == 0 && x == 0 && y == 0)
			break;
		init_plane();
		draw_square(1024, 1024, k);
		printf("%3d\n", plane[y][x]);
	}
	return 0;
}

