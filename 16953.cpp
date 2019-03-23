#include <cstdio>
int n,k,t=1;
int main(){
    scanf("%d %d",&k,&n);
    while(n>k){
        if(n%10==1) n/=10;
        else if(n%2==0) n/=2;
        else {
            puts("-1"); return 0;
        }
        t++;
    }
   n!=k? puts("-1"):printf("%d",t);
}