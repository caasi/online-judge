/* @JUDGE_ID: 37889YH 107 C */
#include<stdio.h>
#include<stdlib.h>

int main(){
	int i,j;
	int N;
	int twoDarray[100][100];

	int sum;
	int max_sum;
	int left,right,right_I;
	
	while(scanf("%d",&N)!=EOF){
		for(i=0;i<N;i++){
			for(j=0;j<N;j++)
				scanf("%d",&twoDarray[i][j]);
		}
	
		max_sum = 0;
		for(right_I=0;right_I < N;right_I++){
			left = 0;
			for(right=right_I;right < N;right++,left++){
				sum = 0;
				for(i=0;i<N;i++){
					for(j=left;j<=right;j++)
						sum += twoDarray[i][j];
					if(sum > max_sum){
						max_sum = sum;
					}else if(sum <= 0){
						sum = 0;
					}
				}
			}
		}
		printf("%d\n",max_sum);
	}
	return 0;
}
