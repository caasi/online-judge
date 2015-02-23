#include<stdio.h>

void func(int);

int main(){
	int n;
	scanf("%d",&n);
	func(n);
}

void func(int n){
	int m;
	int a,b,c;
	int i=0;
	int j=0;
	int sum[10000];
	while(i<n){
		scanf("%d",&m);
		while(j<m){
			scanf("%d %d %d",&a,&b,&c);
			sum[i]+=a*c;
			a=c=0;
			j++;
		}
	j=0;
	i++;
	}
	i=0;
	while(i<n){
		printf("%d\n",sum[i]);
		i++;
	}
}
