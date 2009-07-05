#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct char_list
{
	char c;
	struct char_list *next;
} char_list;

int count_list(char_list *list)
{
	int count = 0;
	char_list *current;
	for(current = list; current; current = current->next, count++);
	return count;
}

void print_list(char_list *list)
{
	char_list *current;
	for(current = list; current; current = current->next)
		printf("%c", current->c);
	return;
}

char_list *new_list(char c)
{
	char_list *ret;
	ret = (char_list*)malloc(sizeof(char_list));
	ret->c = c;
	ret->next = NULL;
	return ret;
}

char_list *copy_list(char_list *old)
{
	char_list *ret, *new, *current;
	ret = new_list(old->c);
	new = ret;
	for(current = old->next; current; current = current->next)
	{
		new->next = new_list(current->c);
		new = new->next;
	}
	return ret;
}

void delete_list(char_list *list)
{
	if(!list)
		return;
	if(list->next)
		delete_list(list->next);
	free(list);
	return;
}

void insert_list(char_list *new, char_list *target, int pos)
{
	int i;
	char_list *current, *tmp;
	for(current = target, i = 0; current && i < pos; current = current->next, i++);
	if(current)
	{
		tmp = current->next;
		current->next = new;
		new->next = tmp;
	}
	return;
}

char_list **create_dek(char c, char_list **array, int size, int *new_size)
{
	int i, j, list_size;
	char_list *tmp;
	char_list **ret;

	if(!array)
	{
		*new_size = 1;
		ret = (char_list **)malloc(sizeof(char_list*));
		ret[0] = new_list(c);
		return ret;
	}

	list_size = count_list(array[0]);
	*new_size = size * (list_size + 1);
	ret = (char_list **)malloc((*new_size) * sizeof(char_list*));
	for(i = 0; i < size; i++)
	{
		tmp = new_list(c);
		ret[(list_size + 1) * i] = tmp;
		tmp->next = copy_list(array[i]);
		for(j = 1; j <= list_size; j++)
		{
			ret[(list_size + 1) * i + j] = copy_list(array[i]);
			tmp = new_list(c);
			insert_list(tmp, ret[(list_size + 1) * i + j], j - 1);
		}
	}

	return ret;
}

int main(int argc, char *argv[])
{
	int c, i, size, new_size, count, is_start;
	char_list **array, **old;

	is_start = 0;
	count = 0;
	size = 1;
	array = old = NULL;
	while(c = getchar())
	{
		if(c == '\n' || c == EOF)
		{
			if(is_start && array)
				putchar('\n');
			else
				is_start = 1;
			for(i = 0; array && i < size; i++)
			{
				print_list(array[i]);
				delete_list(array[i]);
				putchar('\n');
			}
			free(array);
			old = array = NULL;
			if(c == EOF)
				break;
			continue;
		}
		if(isalpha(c))
		{
			old = array;
			array = create_dek(c, old, size, &new_size);
			for(i = 0; old && i < size; i++)
				delete_list(old[i]);
			free(old);
			size = new_size;
		}
	}
	return 0;
}

