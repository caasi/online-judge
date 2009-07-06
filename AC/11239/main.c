#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/* getline */
#define LINE_LEN 255
char line[LINE_LEN+1];

int getline()
{
	int c, count;
	count = 0;
	while(count < LINE_LEN)
	{
		c = getchar();
		if(c == '\n' || c == EOF)
			break;
		line[count++] = c;
	}
	line[count] = '\0';
	return count;
}

/* simple(?) hash table */
#define NAME_LIMIT 10000
#define PROJECT_LIMIT 100

typedef struct hash
{
	char *string;
	int len;
	int count;
	struct hash *cls;
	struct hash *link;
} hash;

hash *name_table[NAME_LIMIT];
hash *project_table[PROJECT_LIMIT];
hash *sorted_project[PROJECT_LIMIT];
int project_tail;

hash *new_hash(char *string, int len)
{
	hash *n = (hash *)malloc(sizeof(hash));
	n->string = (char *)malloc((len + 1) * sizeof(char));
	strncpy(n->string, string, len);
	n->string[len] = '\0';
	n->len = len;
	n->count = 0;
	n->cls = NULL;
	n->link = NULL;
	return n;
}

void delete_hash(hash **h)
{
	free((*h)->string);
	free(*h);
	*h = NULL;
	return;
}

void trace_hash(hash* h)
{
	if(!h)
	{
		printf("null\n");
		return;
	}
	printf("string: %s\n", h->string);
	printf("length: %d\n", h->len);
	printf("happens %d time(s)\n", h->count);
	printf("collision: %s\n", h->cls ? "yes" : "no");
	return;
}

int get_hash_num(int len, char *string, int string_len)
{
	int i, ret;
	ret = 0;
	for(i = 0; i < string_len; i++)
		ret += string[i];
	return ret % len;
}

void set_hash(hash **table, int len, char *index)
{
	int index_len, hashed;
	hash *prev, *tail;
	index_len = strlen(index);
	hashed = get_hash_num(len, index, index_len);
	tail = table[hashed];
	if(!tail)
	{
		table[hashed] = new_hash(index, index_len);
		return;
	}
	while(tail)
	{
		/* exist */
		if(strncmp(tail->string, index, index_len) == 0)
			return;
		else
		{
			prev = tail;
			tail = tail->cls;
		}
			
	}
	prev->cls = new_hash(index, index_len);
	return;
}

hash *get_hash(hash **table, int len, char *index)
{
	int hashed, index_len;
	hash *h = NULL;
	index_len = strlen(index);
	hashed = get_hash_num(len, index, index_len);
	h = table[hashed];
	while(h)
	{
		if(strncmp(h->string, index, index_len) == 0)
			break;
		h = h->cls;
	}
	return h;
}

void sort_project()
{
	int i, j;
	hash *current;
	project_tail = 0;
	for(i = 0; i < PROJECT_LIMIT; i++)
		if(project_table[i])
			for(current = project_table[i]; current; current = current->cls)
				sorted_project[project_tail++] = current;
	for(i = 0; i < project_tail; i++)
	{
		for(j = 0; j < project_tail - i - 1; j++)
			if(
				sorted_project[j]->count <=
				sorted_project[j+1]->count
			)
			{
				if(
					sorted_project[j]->count ==
					sorted_project[j+1]->count
					&&
					strcmp
					(
						sorted_project[j]->string,
						sorted_project[j+1]->string
					) < 0
				)
					continue;
				current = sorted_project[j];
				sorted_project[j] = sorted_project[j+1];
				sorted_project[j+1] = current;
			}
	}
	return;
}

void clear_all()
{
	int i;
	for(i = 0; i < NAME_LIMIT; i++)
		if(name_table[i])
			delete_hash(&name_table[i]);
	for(i = 0; i < PROJECT_LIMIT; i++)
		if(project_table[i])
			delete_hash(&project_table[i]);
	return;
}

int main(int argc, char *argv[])
{
	hash *h, *p, *blacklist;
	int line_len, num, i;

	set_hash(project_table, PROJECT_LIMIT, "_BLACKLIST_");
	blacklist = get_hash(project_table, PROJECT_LIMIT, "_BLACKLIST_");
	while(1)
	{
		line_len = getline();
		if(line_len)
		{
			if(isupper(line[0]))
			{
				p = get_hash(project_table, PROJECT_LIMIT, line);
				if(!p)
				{
					set_hash(project_table, PROJECT_LIMIT, line);
					p = get_hash(project_table, PROJECT_LIMIT, line);
				}
			}
			if(islower(line[0]))
			{
				h = get_hash(name_table, NAME_LIMIT, line);
				if(!h)
				{
					set_hash(name_table, NAME_LIMIT, line);
					h = get_hash(name_table, NAME_LIMIT, line);
					h->link = p;
					p->count++;
				}
				else
				{
					if(h->link != blacklist && h->link != p)
					{
						h->link->count--;
						h->link = blacklist;
					}
				}
			}
			if(isdigit(line[0]))
			{
				if(line[0] == '1')
				{
					sort_project();
					for(i = 0; i < project_tail; i++)
						if(
							sorted_project[i] &&
							sorted_project[i] != blacklist
						)
							printf
							(
								"%s %d\n",
								sorted_project[i]->string,
								sorted_project[i]->count
							);
					clear_all();
					set_hash(project_table, PROJECT_LIMIT, "_BLACKLIST_");
					blacklist = get_hash(project_table, PROJECT_LIMIT, "_BLACKLIST_");
				}
				else if(line[0] == '0')
					break;
			}
		}
	}

	clear_all();
	return 0;
}

