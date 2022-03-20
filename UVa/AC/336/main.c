#include<stdio.h>
#include<stdlib.h>
#if 0
#define DEBUG
#endif

typedef struct node
{
	int data;
	int visited;
	struct node *links[45];
	int tail;
	struct node *left;
	struct node *right;
}node;

node *node_create(int d)
{
	node *ret = (node *)malloc(sizeof(node));
	if(ret)
	{
		ret->data = d;
		ret->visited = -1;
		ret->tail = 0;
		ret->left = ret->right = NULL;
	}
	return ret;
}

void node_delete(node *crt)
{
	if(crt)
	{
		node_delete(crt->left);
		node_delete(crt->right);
		free(crt);
	}
	return;
}

void node_reset(node *crt)
{
	if(crt)
	{
		crt->visited = -1;
		node_reset(crt->left);
		node_reset(crt->right);
	}
	return;
}

node *node_add(node **root, int d)
{
	node *crt = *root;
	if(crt)
	{
		if(crt->data > d)
			return node_add(&crt->left, d);
		else if(crt->data < d)
			return node_add(&crt->right, d);
		else
			return crt;
	}
	else
	{
		*root = node_create(d);
		return *root;
	}
}

node *node_search(node *root, int d)
{
	node *crt = root;
	if(crt)
	{
		if(crt->data > d)
			return node_search(crt->left, d);
		else if(crt->data < d)
		{
			return node_search(crt->right, d);
		}
		else
			return crt;
	}
	return NULL;
}

void node_travel(node *crt, int TTL)
{
	int i, j;
	--TTL;
	if(TTL < 0)
		return;
	if(crt)
	{
#ifdef DEBUG
		printf("%d gets the message.\n", crt->data);
#endif
		if(crt->visited < TTL)
			crt->visited = TTL;
		else
			return;
		for(i = crt->tail - 1; i >= 0; i--)
			node_travel(crt->links[i], TTL);
	}
	return;
}

int node_dead_count(node *crt)
{
	int count;
	if(crt)
	{
		count = node_dead_count(crt->left) + node_dead_count(crt->right);
		if(crt->visited == -1)
		{
#ifdef DEBUG
			printf("%d got nothing.\n", crt->data);
#endif
			return count + 1;
		}
		else
			return count;
	}
	return 0;
}

int main(int argc, char *argv[])
{
	int i, times, from, to, count;
	node *root, *nodeFrom, *nodeTo;
	count = 0;
	while(scanf("%d", &times) != EOF)
	{
		if(!times)
			break;
		root = NULL;
		for(i = 0; i < times; i++)
		{
			scanf("%d%d", &from, &to);
			nodeFrom = node_add(&root, from);
			nodeTo = node_add(&root, to);
			nodeFrom->links[nodeFrom->tail++] = nodeTo;
			nodeTo->links[nodeTo->tail++] = nodeFrom;
		}
		/* now "from" is node id and "to" is TTL */
		while(scanf("%d%d", &from, &to))
		{
			if(!from && !to)
				break;
			node_reset(root);
			nodeFrom = node_search(root, from);
			node_travel(nodeFrom, to + 1);
			printf
			(
				"Case %d: %d nodes not reachable from node %d with TTL = %d.\n",
				++count,
				node_dead_count(root),
				from,
				to
			);
			/* do BFS */
		}
		node_delete(root);
		root = NULL;
	}
	return 0;
}

