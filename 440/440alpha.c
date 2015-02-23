void function(int,int);

int main(){
    int i,j;
    int x=6;
    int m=3;
    function(x,m);
    while(1);
}
void function(int x,int m){
    int sum=1;
    while(x/m!=0){
        if((sum+=x%m)==m){
            printf("SUM");
            return 0;
        }
        x+=(x-x/m);
        printf("%d ",x);
    }
}
