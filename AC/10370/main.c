#include<stdio.h>

int main(int argc, char *argv[])
{
	int times, student_num, i, count;
	double ave;
	int students[1000];
	scanf("%d", &times);
	while(times)
	{
		scanf("%d", &student_num);
		ave = 0.0;
		for(i = 0; i < student_num; i++)
		{
			scanf("%d", &students[i]);
			ave += students[i];
		}
		ave /= student_num;
		count = 0;
		for(i = 0; i< student_num; i++)
			if(students[i] > ave)
				count++;
		printf("%.3lf%%\n", 100.0 * count / student_num);

		times--;
	}
	return 0;
}

