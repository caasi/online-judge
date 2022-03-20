#include<stdio.h>
#define UGLY_NUM 30

void insert_sort(int[],int),print_list(int[]),the_same(int[],int);

int main(){
	int i,ugly[UGLY_NUM];
	ugly[0] = 1;
	for(i=1;i<UGLY_NUM;i++)
		ugly[i]=0;

	printf("**");
	for(i=0;i<UGLY_NUM;i++)
		printf("%3d ",i);
	printf("\n");
	
	for(i=0;ugly[UGLY_NUM-1]==0;i++){
		insert_sort(ugly,ugly[i]*2);
		printf("%d=",i);
		print_list(ugly);
		insert_sort(ugly,ugly[i]*3);
		printf("%d=",i);
		print_list(ugly);
		insert_sort(ugly,ugly[i]*5);
		printf("%d=",i);
		print_list(ugly);
		printf("\n");
	}
	
	//print_list(ugly);
	return 0;
}

void insert_sort(int ugly[],int value){
	int i,j,s_i;
	for(s_i=0;ugly[s_i]!=0;s_i++);
	for(i=s_i;ugly[i-1]>value;i--)
		ugly[i] = ugly[i-1];
	ugly[i] = value;
	the_same(ugly,s_i);
}

void print_list(int ugly[]){
	int i;
	for(i=0;i<UGLY_NUM;i++)
		printf("%3d ",ugly[i]);
	printf("\n");
}

void the_same(int ugly[],int s_i){
	int i;
	for(i=0;i<UGLY_NUM;i++)
		if(ugly[i]==ugly[i+1])
			break;
	for(ugly[i]=0;i<s_i;i++)
		ugly[i]^=ugly[i+1]^=ugly[i]^=ugly[i+1];
}
