#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define WALL 0
#define SPACE 1
#define START 2
typedef struct number3d
{
	int x;
	int y;
	int z;
}number3d;

number3d *queue[27000];
int qhead = 0;
int qtail = 0;

void queue_push(number3d *num)
{
	queue[qtail++] = num;
	return;
}

number3d *queue_shift()
{
	if(qhead == qtail)
		return NULL;
	return queue[qhead++];
}

number3d *number3d_create(int x, int y, int z)
{
	number3d *ret = (number3d *)malloc(sizeof(number3d));
	if(ret)
	{
		ret->x = x;
		ret->y = y;
		ret->z = z;
	}
	return ret;
}

int number3d_equal(number3d *a, number3d *b)
{
	if(a->x == b->x && a->y == b->y && a->z == b->z)
		return 1;
	return 0;
}

void dungeon_set
(
	int *d,
	number3d *size,
	int v,
	number3d *point
)
{
	if(!d || !size || !point)
		return;
	if((unsigned int)point->x >= size->x)
		return;
	if((unsigned int)point->y >= size->y)
		return;
	if((unsigned int)point->z >= size->z)
		return;
	d[size->x * size->y * point->z + size->x * point->y + point->x] = v;
	return;
}

int dungeon_get
(
	int *d,
	number3d *size,
	number3d *point
)
{
	if(!d || !size || !point)
		return 0;
	if((unsigned int)point->x >= size->x)
		return 0;
	if((unsigned int)point->y >= size->y)
		return 0;
	if((unsigned int)point->z >= size->z)
		return 0;
	return d[size->x * size->y * point->z + size->x * point->y + point->x];
}

void escape_from
(
	int *d,
	number3d *size,
	number3d *start,
	number3d *exit
)
{
	int status, crt_status;
	number3d *crt, *new;

	dungeon_set(d, size, START, start);
	queue_push(start);
	while(1)
	{
		crt = queue_shift();
		if(crt)
		{
			crt_status = dungeon_get(d, size, crt);
			if(number3d_equal(crt, exit))
			{
				printf("Escaped in %d minute(s).\n", crt_status - START);
				break;
			}
			else
			{
				if(crt_status)
				{
					new = number3d_create(crt->x + 1, crt->y, crt->z);
					status = dungeon_get(d, size, new);
					if(status == SPACE)
					{
						dungeon_set(d, size, crt_status + 1, new);
						queue_push(new);
					}
					else
						free(new);
					new = number3d_create(crt->x - 1, crt->y, crt->z);
					status = dungeon_get(d, size, new);
					if(status == SPACE)
					{
						dungeon_set(d, size, crt_status + 1, new);
						queue_push(new);
					}
					else
						free(new);
					new = number3d_create(crt->x, crt->y + 1, crt->z);
					status = dungeon_get(d, size, new);
					if(status == SPACE)
					{
						dungeon_set(d, size, crt_status + 1, new);
						queue_push(new);
					}
					else
						free(new);
					new = number3d_create(crt->x, crt->y - 1, crt->z);
					status = dungeon_get(d, size, new);
					if(status == SPACE)
					{
						dungeon_set(d, size, crt_status + 1, new);
						queue_push(new);
					}
					else
						free(new);
					new = number3d_create(crt->x, crt->y, crt->z + 1);
					status = dungeon_get(d, size, new);
					if(status == SPACE)
					{
						dungeon_set(d, size, crt_status + 1, new);
						queue_push(new);
					}
					else
						free(new);
					new = number3d_create(crt->x, crt->y, crt->z - 1);
					status = dungeon_get(d, size, new);
					if(status == SPACE)
					{
						dungeon_set(d, size, crt_status + 1, new);
						queue_push(new);
					}
					else
						free(new);
				}
			}
		}
		else
		{
			printf("Trapped!\n");
			break;
		}
		free(crt);
	}
	free(crt);
	return;
}

int main(int argc, char *argv[])
{
	int c, i, j, k;
	int *dungeon;
	number3d *size, *point, *start, *exit;

	size = number3d_create(0, 0, 0);
	while(scanf("%d%d%d", &size->z, &size->y, &size->x) != EOF)
	{
		if(!size->x && !size->y && !size->z)
			break;

		/* build dungeon */
		dungeon = (int *)malloc(size->x * size->y * size->z * sizeof(int));
		for(i = size->x * size->y * size->z - 1; i >= 0; i--)
			dungeon[i] = 0;
		point = number3d_create(0, 0, 0);
		for(k = 0; k < size->z; k++)
			for(j = 0; j < size->y; j++)
				for(i = 0; i < size->x; 1)
				{
					c = getchar();
					if(c == '#')
					{
						point->x = i;
						point->y = j;
						point->z = k;
						dungeon_set(dungeon, size, WALL, point);
						++i;
					}
					else if(c == 'S' || c == 'E' || c == '.')
					{
						if(c == 'S')
							start = number3d_create(i, j, k);
						if(c == 'E')
							exit = number3d_create(i, j, k);
						point->x = i;
						point->y = j;
						point->z = k;
						dungeon_set(dungeon, size, SPACE, point);
						++i;
					}
				}

		/* try to escape */
		escape_from(dungeon, size, start, exit);

		/* destroy dungeon XD */
		free(point);
		while(point = queue_shift())
			free(point);
		qhead = qtail = 0;
		free(dungeon);
	}
	
	return 0;
}

