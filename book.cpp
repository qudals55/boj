#include <cstdio>
#include <algorithm>
#include <vector>
int b[1001],v[1001],n,t,x,y,m,k;
std::vector<int> adj[1001];
int dfs(int i){
	v[i]=1;
	for(int to: adj[i]) if(!b[to] || !v[b[to]] && dfs(b[to])) {b[to]=i;return 1;}
	return 0;
}
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d %d",&n,&m);
		for(int i =1; i<=m;i++) adj[i].clear();
		std::fill(b,b+n+1,0);
		for(int i =1; i<=m;i++){
			scanf("%d %d",&x,&y);
			for(int j =x;j<=y;j++) adj[i].push_back(j);
	}
	for(int i =1; i <=m;i++) std::fill(v,v+n+1,0), k+=dfs(i);
	printf("%d\n",k);k=0;
}
}