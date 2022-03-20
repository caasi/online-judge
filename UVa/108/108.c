#include<stdio.h>
#include<stdlib.h>

/*int sum_of_matrix(int,int,int,int);*/

int main(){
	int i,j;
	int N;
	int twoDarray[100][100];

	int sum;
	int max_sum;
	int left,right,up,down,right_I;
	
	scanf("%d",&N);
	for(i=0;i<N;i++){
		for(j=0;j<N;j++)
			scanf("%d",&twoDarray[i][j]);
	}
	
	/*for(m=0;m<N;m++){
		max_sum = -12700;
		for(j=0;j<N;j++){
			sum += twoDarray[m][j];
			if(sum > max_sum){
				max_sum = sum;
				right = j;
				printf("1.%d\n",j);
			}
		}
		sum = 0;
		for(j=right;j>=0;j--){
			sum += twoDarray[m][j];
			if(sum > max_sum){
				max_sum = sum;
				left = i;
				printf("2.%d\n",j);
			}
		}*/
	max_sum = 0;
	for(right_I=0;right_I < N;right_I++){
		left = 0;
		for(right=right_I;right < N;right++,left++){
			printf("left=%2d\tright=%2d\n",left,right);
			sum = 0;
			for(i=0;i<N;i++){
				for(j=left;j<=right;j++){
					sum += twoDarray[i][j];
				}
				if(sum > max_sum){
					max_sum = sum;
				}else if(sum <= 0){
					sum = 0;
				}
			}
		}
	}
	/*Sample Input
	 * 4
	 * 0 -2 -7  0 9  2 -6  2 -4  1 -4  1 -1 8  0 -2
	 */

	/*sum = 0;
	max_sum = -12700;
	for(i=0;i<N;i++){
		for(j=0;j<N;j++)
			sum += twoDarray[i][j];
		if(sum > max_sum){
			printf(">%d\n",sum);
			max_sum = sum;
			down = i;
		}
	}
	sum = 0;
	max_sum = -12700;
	for(i=down;i>=0;i--){
		for(j=0;j<N;j++)
			sum += twoDarray[i][j];
		if(sum > max_sum){
			printf(">>%d\n",sum);
			max_sum = sum;
			up = i;
		}
	}
	sum = 0;
	max_sum = -12700;
	for(j=0;j<N;j++){
		for(i=up;i<=down;i++)
			sum += twoDarray[i][j];
		if(sum > max_sum){
			printf(">>>%d\n",sum);
			max_sum = sum;
			right = j;
		}
	}
	sum = 0;
	max_sum = -12700;
	for(j=right;j>=0;j--){
		for(i=up;i<=down;i++)
			sum += twoDarray[i][j];
		if(sum > max_sum){
			printf(">>>>%d\n",sum);
			max_sum = sum;
			left = j;
		}
	}*/
	printf("%d,%d\n%d,%d\n=%d=\n",up,left,down,right,max_sum);
	/*for(i=0;i<N;i++){
		for(j=0;j<N;j++)
			printf("%d ",twoDarray[i][j]);
		printf("\n");
	}*/
	return 0;
}

/*int sum_of_matrix(int i,int j, int Fi, int Fj){
	int sum = 1;
	for(;i<Fi;i++){
		for(;j<Fj;j++)
			sum += matrix[i][j];
	}
	return sum;
}*/
/*This is N^3..
 * Is there 4N^2.....?
 * */
