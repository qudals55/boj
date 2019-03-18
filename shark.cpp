#include <bits/stdc++.h>
int b[101],c[101],n,k,d[101][101];
struct K{int a,b,c;};
K v[51];
int dfs(int i){
	c[i]=1;
	for(int j =1; j<=2*n;j++) if(d[i][j]) if(!b[j] || !c[b[j]] && dfs(b[j])) {b[j]=i;return 1;}
	return 0;
}
int main(){
	scanf("%d",&n);
	for(int i =1; i <=n;i++) scanf("%d %d %d",&v[i].a,&v[i].b,&v[i].c);
	for(int i =1; i <=n ;i++) for(int j=1;j<=n;j++) if(i!=j && !d[j][i] && v[i].a>=v[j].a && v[i].b>=v[j].b && v[i].c>=v[j].c) d[i][j]=d[i+n][j]=1;
	for(int i =1;i<=n*2;i++) std::fill(c,c+2*n+1,0),k+=dfs(i);
	printf("%d",n-k);
}