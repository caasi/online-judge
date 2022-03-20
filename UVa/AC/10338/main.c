#include<stdio.h>
#include<string.h>

int main(int argc, char *argv[])
{
	int i, j, c, count, times, tmp;
	unsigned long long int result;
	char alphabets[26];

	for(i = 0; i < 26; i++)
		alphabets[i] = 0;
	count = 0;
	result = 1;

	scanf("%d ", &times);
	tmp = 1;
	while(tmp <= times)
	{
		c = getchar();
		if(c == '\n')
		{
			if(count == 0)
			{
				printf("\n");
				continue;
			}
			for(i = count; i >= 2; i--)
			{
				result *= i;
				for(j = 0; j < 26; j++)
					while(alphabets[j] && result % alphabets[j] == 0)
						result /= alphabets[j]--;
			}
			printf("Data set %d: %llu\n", tmp, result);
			for(i = 0; i < 26; i++)
				alphabets[i] = 0;
			count = 0;
			result = 1;
			tmp++;
		}
		else
		{
			count++;
			alphabets[c - 'A']++;
		}
	}
	return 0;
}

