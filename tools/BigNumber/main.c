/* Big Number
 * The biggest problem is that I can't divide the number by 10, so I can't
 * print the number.
 */

#include<stdio.h>
#include<stdlib.h>
#define MIN_DIGITS 1

typedef struct number
{
	unsigned int *digits;
	unsigned int length;
} number;

/* private */
void init_number(number *num)
{
	num->digits = (unsigned int *)malloc(MIN_DIGITS * sizeof(unsigned int));
	num->length = MIN_DIGITS;
	return;
}

void double_number_length(number *num)
{
	int i;
	unsigned int *new_digits =
		(unsigned int *)malloc(2 * num->length * sizeof(unsigned int));
	for(i = 0; i < num->length; i++)
		new_digits[i] = num->digits[i];
	free(num->digits);
	num->digits = new_digits;
	num->length *= 2;
	return;
}

/* public */
number *create_number()
{
	number *new_num;
	new_num = (number *)malloc(sizeof(number));
	init_number(new_num);
	return new_num;
}

void delete_number(number **num)
{
	free((*num)->digits);
	free(*num);
	*num = NULL;
	return;
}

void multiply_number_by_two(number *num)
{
	int i, len;
	len = num->length;
	for(i = len - 1; i >= 0; i--)
	{
		if(num->digits[i] & (0x01 << 31))
		{
			if(i == len - 1)
				double_number_length(num);
			num->digits[i + 1] += 1;
		}
		num->digits[i] <<= 1;
	}
	return;
}

int main(int argc, char *argv[])
{
	int i;
	number *num = create_number();
	printf("number created\n");
	double_number_length(num);
	printf("number length doubled\n");
	double_number_length(num);
	printf("number length doubled\n");
	for(i = 0; i < 32; i++)
	{
		multiply_number_by_two(num);
		printf("number doubled\n");
	}
	delete_number(&num);
	printf("number deleted\n");
	return 0;
}
