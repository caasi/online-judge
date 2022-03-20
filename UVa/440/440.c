#include<stdio.h>
#include<stdlib.h>
int cutoff(int);
int ninput;
int m=2;
int sum=1;

int main(){
	int n;
	scanf("%d",&n);
	while(1){
		scanf("%d",&n);
		if(n==0)
			break;
		ninput=n--;
		if(cutoff(ninput)==1)printf("%d\n",m);
	}
	return 0;
}

int cutoff(int n){
	if(n==1)return 1;
	sum+=n%m;
	n-=n/m;
	if(sum==m){
		m++;
		return cutoff(ninput); 
	}
	return cutoff(n);
}
