#include <bits/stdc++.h>
int c[10001][10001],n,a,b,t,total,S,E;
std::vector<int> adj[802];
int main(){
	scanf("%d %d",&n,&t);
	for(int i =1; i<=n;i++) c[i][i+n]=1,adj[i].push_back(i+n),adj[i+n].push_back(i);
	c[1][n+1]=c[2][n+2]=1e9;
	while(t--)scanf("%d %d",&a,&b),c[a+n][b]=c[b+n][a]=1,adj[a+n].push_back(b),adj[b+n].push_back(a),adj[b].push_back(a+n),adj[a].push_back(b+n);
	S=1; E=n+2;
	while(1){
		std::vector<int> prev(n+n+1,-1);
		std::queue<int> q;
		q.push(S);
		while(!q.empty() && prev[E]==-1){
			int cur =q.front();q.pop();
			for(int next:adj[cur])if(prev[next]==-1 && c[cur][next]) q.push(next),prev[next]=cur;
		}
		if(prev[E]==-1) break;
		for(int i =E; i!=S; i=prev[i]) c[prev[i]][i]--,c[i][prev[i]]++;
		total++;
	}
	printf("%d",total);
}