#include<stdio.h>
#include<string.h>
#define STACK_LEN 100
#define ERR_STACK_FULL 1
#define ERR_STACK_EMPTY 2

typedef struct stack
{
	char s[STACK_LEN];
	int len;
} stack;

void init_stack(stack *s)
{
	s.len = 0;
	return;
}

int push(stack *s, char c);
{
	if(s->len == STACK_LEN)
		return ERR_STACK_FULL;
	s->s[s->len++] = c;
	return 0;
}

int pop(stack *s)
{
	int ret;
	if(s->len == 0)
		return ERR_STACK_EMPTY;
	return s->s[--s->len];
}

int main(int argc, char *argv[])
{
	int c, count;
	stack s1, s2;
	init_stack(s1);
	init_stack(s2);
	while((c = getchar()) != EOF)
	{
		if(c != '\n')
			push(s1, c);
		while((c = pop(s1)) != ERR_STACK_EMPTY)
		{
			switch(c)
			{
				case '+':
				case '-':
				case '*':
				case '/':
					break;
				default:
					push(s2, c);
					break;
			}
		}
	}
	return 0;
}

