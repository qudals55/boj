#include <bits/stdc++.h>
int n,m,x,y,b[101],c[101],k;
std::vector<int> v[101];
int dfs(int i){
	c[i]=1;
	for(int to: v[i]) if(!b[to] || !c[b[to]] && dfs(b[to])){b[to]=i;return 1;}
	return 0;
}
int main(){
	scanf("%d %d",&n,&m);
	while(m--) scanf("%d %d",&x,&y), v[x].push_back(y);
	for(int i=1;i<=n;i++) std::fill(c,c+n+1,0),k+=dfs(i);printf("%d",k);
}