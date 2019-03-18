#include <bits/stdc++.h>
char s[101];
int d[101][101][3],n,x=1e9;
char f(int a){
	if(!a) return 'R';
	if(a==1) return 'G';
	return 'B';
}
int go(int l, int r, int c){
	if(l>r) return 0;
	if(l==r) return f(c)!=s[l];
	if(d[l][r][c]!=1e9) return d[l][r][c];
	for(int i =l;i<r;i++) for(int j =0; j <3; j++) d[l][r][c] = std::min(d[l][r][c],go(l,i,j)+go(i+1,r,c)+(j!=c));
	return d[l][r][c];
}
int main(){
	scanf("%d %s",&n,s);
	for(int i =0; i<n ;i++) for(int j =0; j <n ; j++) for(int k=0; k<3;k++) d[i][j][k]=1e9;
	for(int i =0; i <3;i++) x=std::min(x,go(0,n-1,i)+1);
	printf("%d",x);
}
