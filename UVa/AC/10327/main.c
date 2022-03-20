#include<stdio.h>

int main(int argc, char *argv[])
{
	int i, j, max, count;
	int nums[1000], array_len;
	while(scanf("%d", &array_len) != EOF)
	{
		for(i = 0; i < array_len; i++)
			scanf("%d", &nums[i]);
		count = 0;
		while(array_len > 1)
		{
			/* find max */
			for(max = 0, i = 0; i < array_len; i++)
				if(nums[max] <= nums[i])
					max = i;
			count += array_len - max - 1;
			for(i = max; i < array_len - 1; i++)
				nums[i] = nums[i + 1];
			array_len--;
		}
		printf("Minimum exchange operations : %d\n", count);
	}
	return 0;
}

