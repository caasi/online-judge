#include<stdio.h>
#include<stdlib.h>
#define LINE_LEN 255
char line[LINE_LEN + 1];

typedef struct stack
{
	char array[LINE_LEN];
	int tail;
} stack;

stack *new_stack()
{
	stack *ret = (stack *)malloc(sizeof(stack));
	ret->tail = 0;
	return ret;
}

void delete_stack(stack **s)
{
	free(*s);
	*s = NULL;
	return;
}

int pop(stack *s)
{
	if(s->tail)
		return s->array[--s->tail];
	else
		return 0;
}

void push(stack *s, char c)
{
	if(s->tail < LINE_LEN)
		s->array[s->tail++] = c;
	return;
}

int getline()
{
	int c, count = 0;
	while((c = getchar()) != EOF)
	{
		if(c == '\n')
			break;
		line[count++] = c;
	}
	line[count] = '\0';
	return count;
}

void add_parentheses(stack *s)
{
	int i, j, k, parentheses, expect_operator;
	for(i = 0; i < s->tail; i++)
	{
		if(s->array[i] == '*' || s->array[i] == '/')
		{
			parentheses = 0;
			expect_operator = 0;
			for(j = i - 1; j >= 0; j--)
			{
				if(s->array[j] == ')')
				{
					if(expect_operator)
						break;
					else
						parentheses++;
				}
				else if(parentheses && s->array[j] == '(')
					parentheses--;
				else if(
					!parentheses && 
					(
						s->array[j] == '+' ||
						s->array[j] == '-' ||
						s->array[j] == '('
					)
				)
					break;
				if(isdigit(s->array[j]))
					expect_operator = 1;
				else
					expect_operator = 0;
			}
			for(k = s->tail; k > j + 1; k--)
				s->array[k] = s->array[k-1];
			s->array[j+1] = '(';
			s->tail++;
			i++;
			parentheses = 0;
			expect_operator = 0;
			for(j = i + 1; j < s->tail; j++)
			{
				if(s->array[j] == '(')
				{
					if(expect_operator)
						break;
					else
						parentheses++;
				}
				else if(parentheses && s->array[j] == ')')
					parentheses--;
				else if
				(
					!parentheses &&
					(
						s->array[j] == '+' ||
						s->array[j] == '-' ||
						s->array[j] == ')'
					)
				)
					break;
				if(isdigit(s->array[j]))
					expect_operator = 1;
				else
					expect_operator = 0;
			}
			for(k = s->tail; k > j; k--)
				s->array[k] = s->array[k-1];
			s->array[j] = ')';
			s->tail++;
		}
	}
	return;
}

int main(int argc, char *argv[])
{
	int times, result, c, tmp, p, i;
	stack *stack1, *stack2;

	stack1 = new_stack();
	stack2 = new_stack();

	scanf("%d ", &times);
	while(times)
	{
		result = getline();
		if(result)
			push(stack1, line[0]);
		else
		{
			add_parentheses(stack1);
			/*
			printf("stack1: ");
			for(i = 0; i < stack1->tail; i++)
				printf("%c", stack1->array[i]);
			putchar('\n');
			*/
			p = 0;
			while(c = pop(stack1))
			{
				switch(c)
				{
					case '+':
					case '-':
					case '*':
					case '/':
						if(p)
						{
							push(stack1, '(');
							while((tmp = pop(stack2)) && tmp != ')')
								push(stack1, tmp);
							push(stack1, c);
							while((tmp = pop(stack1)) && tmp != '(')
								push(stack2, tmp);
							p = 0;
						}
						else
						{
							tmp = pop(stack2);
							push(stack2, c);
							push(stack2, tmp);
						}
						break;
					case ')':
						push(stack2, ')');
						break;
					case '(':
						if(p)
						{
							push(stack1, '(');
							while((tmp = pop(stack2)) && tmp != ')')
								push(stack1, tmp);
							while((tmp = pop(stack1)) && tmp != '(')
								push(stack2, tmp);
						}
						p = 1;
						break;
					default:
						push(stack2, c);
				}
			}
			while(c = pop(stack2))
				if(c != ')')
					putchar(c);
			putchar('\n');
			times--;
			if(times)
				putchar('\n');
		}
	}
	return 0;
}

