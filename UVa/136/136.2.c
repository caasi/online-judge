#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
	int i,j,k;
	long long int trash;
		
	for(i=0;i<10;i++){
		for(j=0;j<10;j++){
			for(k=0;k<10;k++){
				trash = (int)(pow(2,i)*pow(3,j)*pow(5,k));
				printf("%d\n",trash);
			}
		}
	}
	return 0;
}
