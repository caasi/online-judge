#include<stdio.h>
#include<stdlib.h>
#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3
int op[4][2] =
{
	{0, 1},
	{1, 0},
	{0, -1},
	{-1, 0}
};
char plane[51][51];

typedef struct robot
{
	int x;
	int y;
	int dir;
	struct robot *memory;
} robot;

robot *robot_create(int x, int y, char dir)
{
	robot *ret = (robot *)malloc(sizeof(robot));
	ret->x = x;
	ret->y = y;
	switch(dir)
	{
		case 'N':
			ret->dir = NORTH;
			break;
		case 'E':
			ret->dir = EAST;
			break;
		case 'S':
			ret->dir = SOUTH;
			break;
		case 'W':
			ret->dir = WEST;
			break;
		default:
			break;
	}
	ret->memory = NULL;
	return ret;
}

int main(int argc, char *argv[])
{
	int width, height;
	int x, y, newx, newy, lost;
	char dir;
	robot *robbie, *remember;
	robbie = NULL;
	scanf("%d %d ", &width, &height);
	while(scanf("%d %d %c ", &x, &y, &dir) == 3)
	{
		lost = 0;
		remember = robbie;
		robbie = robot_create(x, y, dir);
		robbie->memory = remember;
		/* use x for other propurse */
		while((x = getchar()) != EOF && x != '\n')
		{
			if(lost)
				continue;
			switch(x)
			{
				case 'F':
					newx = robbie->x + op[robbie->dir][0];
					newy = robbie->y + op[robbie->dir][1];
					if(
						(unsigned int)newx > width ||
						(unsigned int)newy > height
					)
					{
						remember = robbie->memory;
						while(remember)
						{
							if
							(
								remember->x == robbie->x &&
								remember->y == robbie->y
							)
								break;
							remember = remember->memory;
						}
						if(!remember)
							lost = 1;
					}
					else
					{
						robbie->x = newx;
						robbie->y = newy;
					}
					break;
				case 'L':
					robbie->dir--;
					if(robbie->dir < 0)
						robbie->dir += 4;
					break;
				case 'R':
					robbie->dir++;
					if(robbie->dir >= 4)
						robbie->dir -= 4;
					break;
			}
		}
		switch(robbie->dir)
		{
			case NORTH:
				dir = 'N';
				break;
			case EAST:
				dir = 'E';
				break;
			case SOUTH:
				dir = 'S';
				break;
			case WEST:
				dir = 'W';
				break;
		}
		printf("%d %d %c%s\n", robbie->x, robbie->y, dir, lost ? " LOST" : "");
	}
	while(robbie)
	{
		remember = robbie;
		robbie = robbie->memory;
		free(remember);
	}
	remember = NULL;
	return 0;
}

