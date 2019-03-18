#include <bits/stdc++.h>
int k;
int f(int n,int a,int b,int c){
	if(n>0)f(n-1,a,c,b),printf("%d -> %d    %d\n",a,c,++k),f(n-1,b,a,c);
}
int main(){
	int n;
	scanf("%d",&n);
	f(n,1,2,3);
}
