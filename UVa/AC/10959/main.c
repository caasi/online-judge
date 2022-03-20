#include<stdio.h>
#include<stdlib.h>
#define START 1
typedef struct node
{
	unsigned int data;
	struct node *next;
}node;

node *node_create(int d)
{
	node *ret = (node *)malloc(sizeof(node));
	if(ret)
	{
		ret->data = d;
		ret->next = NULL;
	}
	return ret;
}

void node_delete(node *head)
{
	if(head)
		node_delete(head->next);
	free(head);
	return;
}

void node_push(node **head, node *n)
{
	node *tmp;
	if(!head)
		return;
	if(!*head)
	{
		*head = n;
		return;
	}
	tmp = *head;
	while(tmp->next)
		tmp = tmp->next;
	tmp->next = n;
	return;
}

node *node_shift(node **head)
{
	node *tmp;
	if(!head)
		return NULL;
	if(!*head)
		return NULL;
	tmp = *head;
	*head = (*head)->next;
	return tmp;
}

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

void bfs(utm *graph, node *queue)
{
	int i, dgnum, crtnum;
	node *tmp, *people  = node_create(0);
	utm_set(graph, START, 0, 0);
	node_push(&queue, people);
	while(people = node_shift(&queue))
	{
		crtnum = utm_get(graph, people->data, people->data);
		for(i = 0; i < graph->w; i++)
		{
			if(i == people->data)
				continue;
			if(utm_get(graph, people->data, i))
			{
				dgnum = utm_get(graph, i, i);
				if(!dgnum)
				{
					utm_set(graph, crtnum + 1, i, i);
					tmp = node_create(i);
					node_push(&queue, tmp);
				}
			}
		}
	}
	return;
}

int main(int argc, char *argv[])
{
	int times, i, j, p, d, id1, id2;
	node *queue = NULL;
	utm *graph;
	scanf("%d", &times);
	while(times)
	{
		scanf("%d%d", &p, &d);
		graph = utm_create(p);
		for(i = 0; i < d; ++i)
		{
			scanf("%d%d", &id1, &id2);
			utm_set(graph, 1, id1, id2);
		}
		/*
		for(i = 0; i < graph->w; i++)
			for(j = 0; j < graph->w; j++)
				printf("%u%c", utm_get(graph, j, i), j == graph->w - 1 ? '\n' : ' ');
		*/
		bfs(graph, queue);
		for(i = 1; i < p; i++)
			printf("%u\n", utm_get(graph, i, i) - START);
		if(times > 1)
			printf("\n");

		free(graph);
		node_delete(queue);
		queue = NULL;
		--times;
	}
	return 0;
}

