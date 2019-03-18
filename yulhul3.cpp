#include <bits/stdc++.h>
int b[2002],v[2002],n,m,k,x,t,y,s;
std::vector<int> adj[2002];
int dfs(int i){
	v[i]=1;
	for(int to: adj[i]) if(!b[to] || !v[b[to]] && dfs(b[to])){b[to]=i;return 1;}
	return 0;
}
int main(){
	scanf("%d %d %d",&n,&m,&t);
	for(int i =1; i<=n;i++){
		scanf("%d",&k);
		while(k--) scanf("%d",&x), adj[i].push_back(x),adj[i+1000].push_back(x);
	}
	for(int i =1; i <=n+1000 && t;i++){
		std::fill(v,v+2000,0);
		if(dfs(i)){
			s++;
			if(i>1000) t--;
		}
	}
	printf("%d",s);
}