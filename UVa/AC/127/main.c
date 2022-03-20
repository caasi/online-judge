#include<stdio.h>
#include<stdlib.h>

typedef struct card
{
	char rank;
	char suit;
} card;
card *deck[52][52];
int deck_tail[52];

void deck_push(int index, card *crd)
{
	if((unsigned int)index >= 52)
		return;
	deck[index][deck_tail[index]++] = crd;
	return;
}

card *deck_look(int index)
{
	if((unsigned int)index >= 52)
		return NULL;
	if(!deck_tail[index])
		return NULL;
	return deck[index][deck_tail[index] - 1];
}

card *deck_pop(int index)
{
	if((unsigned int)index >= 52)
		return NULL;
	if(deck_tail[index] == 0)
		return NULL;
	return deck[index][--deck_tail[index]];
}

void clear_all()
{
	int i, j;
	for(i = 0; i < 52; i++)
	{
		for(j = 0; j < deck_tail[i]; j++)
			if(deck[i][j])
			{
				free(deck[i][j]);
				deck[i][j] = NULL;
			}
		deck_tail[i] = 0;
	}
	return;
}

card *card_create(char rank, char suit)
{
	card *new = (card *)malloc(sizeof(card));
	new->rank = rank;
	new->suit = suit;
	return new;
}

int card_match(card *a, card *b)
{
	return a && b && ((a->rank == b->rank) || (a->suit == b->suit));
}

int main(int argc, char *argv[])
{
	char suit, rank, count, i, j, k;
	int index1, index2;
	count = 0;
	while(scanf("%c%c ", &rank, &suit) == 2)
	{
		if(rank == '#')
			break;
		deck_push(count++, card_create(rank, suit));
		if(count == 52)
		{
			for(i = 0; i < 52;)
			{
				if(!deck_tail[i])
				{
					i++;
					continue;
				}
				index1 = -1;
				index2 = -1;
				for(j = 0, k = i - 1; j != 3 && k >= 0; k--)
				{
					if(deck_tail[k])
					{
						j++;
						if(j == 1)
							index1 = k;
						if(j == 3)
							index2 = k;
					}
				}
				if(card_match(deck_look(index2), deck_look(i)))
				{
					deck_push(index2, deck_pop(i));
					i = index2;
					continue;
				}
				if(card_match(deck_look(index1), deck_look(i)))
				{
					deck_push(index1, deck_pop(i));
					i = index1;
					continue;
				}
				i++;
			}
			/* use count for other purpose */
			for(count = 0, i = 0; i < 52; i++)
				if(deck_look(i))
					count++;
			printf("%d pile%sremaining:", count, count == 1 ? " " : "s ");
			for(i = 0; i < 52; i++)
				if(deck_look(i))
					printf(" %d", deck_tail[i]);
			printf("\n");
			count = 0;
			clear_all();
		}
	}
	return 0;
}

