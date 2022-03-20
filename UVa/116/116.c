/*
 * Find the min sum of a matrix from left to right
 *
 * i.e.
 * 
 * 3 4 1 2 8 6
 * 6 1 8 2 7 4
 * 5 9 3 9 9 5
 * 8 4 1 3 2 6
 * 3 7 2 8 6 4
 */

#include<stdio.h>

int Compute(int matrix[][100],int row,int col);
void show(int matrix[][100],int,int);

int main(){
	int i,j,row,col;
	int matrix[10][100];

	row=-1;
	col=-1;
	
	//while(row!=0&&col!=0){
		scanf("%d%d",&row,&col);
		for(i=0;i<row;i++)
			for(j=0;j<col;j++)
				scanf("%d",&matrix[i][j]);
	Compute(matrix,row,col);
	//}
	
	return 0;
}

int Compute(int matrix[][100],int row,int col){
	int i,j,min;
	int path[10][100];
	if(col!=1){
		for(i=0;i<col-1;i++)
			for(i=0;j<row;j++){
				min=matrix[j-1<0?row-1:j-1][i+1>col?0:i+1];
				if(min>matrix[j][i+1>col?0:i+1])
					min=matrix[j][i+1>col?0:i+1];
				if(min>matrix[j+1>row?0:j+1][i+1>col?0:i+1])
					min=matrix[j+1>row?0:j+1][i+1>col?0:i+1];
				matrix[j][i]+=min;
		}
		show(matrix,row,col-1);
		Compute(matrix,row,col-1);
	}else{
		j=0;
		min=matrix[0][0];
		for(i=1;i<row-1;i++)
			if(min>matrix[i][0]){
				min=matrix[i][0];
				j=i;
			}
		printf("%d\n",j);
		return min;
	}
}
	
void show(int matrix[][100],int row,int col){
	int i,j;
	for(i=0;i<row;i++){
		for(j=0;j<col;j++)
			printf("%d ",matrix[i][j]);
		printf("\n");
	}
}
