#include<stdio.h>
#include<stdlib.h>
/* quadtree for a 32 * 32 pixels image, counter-clockwise */
typedef struct quadtree
{
	char tree[1365];
	int length;
}quadtree;

void quadtree_read(quadtree *q)
{
	int c;
	if(!q)
		return;
	q->length = 0;
	while((c = getchar()) != '\n')
		q->tree[(q->length)++] = c;
	return;
}

/* private */
/* counts black pixels inside a tree, and store next node pointer in *tree */
int tree_count(char **tree, int size)
{
	int i, count;
	switch(*(*tree)++)
	{
		case 'f':
			return size;
		case 'e':
			return 0;
		case 'p':
			count = 0;
			for(i = 0; i < 4; ++i)
				count += tree_count(tree, size / 4);
			return count;
		default:
			return -1;
	}
}

/* public */
int quadtree_count(quadtree *q)
{
	char *ptr;
	if(!q)
		return 0;
	ptr = q->tree;
	return tree_count(&ptr, 1024);
}

/* private */
int tree_count_intersect(char **t1, char **t2, int size)
{
	int i, count;
	if((**t1) == 'f')
	{	
		tree_count(t2, size);
		return tree_count(t1, size);
	}
	if((**t2) == 'f')
	{
		tree_count(t1, size);
		return tree_count(t2, size);
	}
	if((**t1) == 'e' && (**t2) == 'e')
	{
		tree_count(t2, size);
		return tree_count(t1, size);
	}
	if((**t1) == 'p' && (**t2) == 'p')
	{
		++(*t1);
		++(*t2);
		count = 0;
		for(i = 0; i < 4; ++i)
			count += tree_count_intersect(t1, t2, size / 4);
		return count;
	}
	if((**t1) == 'p')
	{
		tree_count(t2, size);
		return tree_count(t1, size);
	}
	if((**t2) == 'p')
	{
		tree_count(t1, size);
		return tree_count(t2, size);
	}
}

/* public */
/* combine q1, q2 to q3 */
int quadtree_count_intersect(quadtree *q1, quadtree *q2)
{
	char *t1, *t2;
	if(!q1 || !q2)
		return 0;
	t1 = q1->tree;
	t2 = q2->tree;
	return tree_count_intersect(&t1, &t2, 1024);
}

int main(int argc, char *argv[])
{
	int times;
	quadtree qtree1, qtree2;
	/* remember to chomp the \n */
	scanf("%d ", &times);
	while(times--)
	{
		quadtree_read(&qtree1);
		quadtree_read(&qtree2);
		printf
		(
			"There are %d black pixels.\n",
			quadtree_count_intersect(&qtree1, &qtree2)
		);
	}
	return 0;
}

