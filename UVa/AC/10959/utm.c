typedef struct utm
{
	unsigned int *m;
	int w;
}utm;

utm *utm_create(int w)
{
	int i;
	utm *ret = (utm *)malloc(sizeof(utm));
	if(ret)
	{
		ret->m = (unsigned int *)malloc((w * w + w) / 2 * sizeof(unsigned int));
		ret->w = w;
		for(i = (w * w + w) / 2 - 1; i >= 0; i--)
			ret->m[i] = 0;
	}
	return ret;
}

void utm_delete(utm *u)
{
	if(u)
		free(u->m);
	free(u);
	return;
}

unsigned int utm_get(utm *u, int x, int y)
{
	unsigned int tmp;
	if(!u)
		return 0;
	if((unsigned int)x >= u->w || (unsigned int)y >= u->w)
		return 0;
	if(x < y)
	{
		tmp = x;
		x = y;
		y = tmp;
	}
	return u->m[x + u->w * y - (y * y + y) / 2];
}

void utm_set(utm *u, unsigned int num, int x, int y)
{
	unsigned int tmp;
	if(!u)
		return;
	if((unsigned int)x >= u->w || (unsigned int)y >= u->w)
		return;
	if(x < y)
	{
		tmp = x;
		x = y;
		y = tmp;
	}
	u->m[x + u->w * y - (y * y + y) / 2] = num;
	return;
}
