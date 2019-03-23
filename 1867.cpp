#include <bits/stdc++.h>
int u,v,t,b[501],c[501],ret,n;
std::vector<int> adj[501];
bool dfs(int i){
	c[i] =1;
	for(int next: adj[i]) if(!b[next] || !c[b[next]] && dfs(b[next])){
		b[next] =i;
		return true;
	}
	return false;
}
int main(){
	scanf("%d %d",&n,&t);
	while(t--) scanf("%d %d",&u,&v), adj[u].push_back(v);
	for(int i =1; i <=n ; i++) memset(c,0,sizeof(c)),ret+=dfs(i);
	printf("%d",ret);
}