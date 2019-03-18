#include <bits/stdc++.h>
int c[305][305],f[305][305],total,N,D,K,S=302,E=301,k,t;
std::vector<int> adj[305];
int main(){
	scanf("%d %d %d",&N,&K,&D);
	for(int i =201;i<=200+D; i++) scanf("%d",&c[i][E]),adj[i].push_back(E), adj[E].push_back(i);
	for(int i =1; i<=N;i++) adj[i].push_back(S),adj[S].push_back(i),c[S][i] =K;
	for(int i =1; i <=N; i++){
		scanf("%d",&t);
		while(t--)scanf("%d",&k), k+=200,c[i][k]=1, adj[i].push_back(k),adj[k].push_back(i);
	}
	while(1){
		int prev[305];
		std::fill(prev, prev+305,-1);
		std::queue<int> q;
		q.push(S);
		while(!q.empty() && prev[E]==-1){
			int cur =q.front();q.pop();
			for(int next :adj[cur]) if(c[cur][next] - f[cur][next] > 0 && prev[next]==-1) prev[next] = cur, q.push(next);
		}
	if(prev[E]==-1) break;
	int flow =1e9;
	for(int i =E ; i!=S; i=prev[i]) flow = std::min(flow, c[prev[i]][i]-f[prev[i]][i]);
	for(int i =E; i !=S; i=prev[i]) f[prev[i]][i] += flow,f[i][prev[i]]-=flow;
	total+=flow;
	} 
	printf("%d",total);
}