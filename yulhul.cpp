
#include <cstdio>
#include <queue>
int c[2005][2005],n,t,k,x,y,total,S,E,m;
std::vector<int> adj[2005];
int main(){
	scanf("%d %d",&n,&m);
	y=std::max(n,m)+1000;
	S=y+1;E=y+2;
	for(int i =1; i <=n ; i++){
		scanf("%d",&k);
		while(k--) scanf("%d",&x),x+=1000,c[i][x]=1,c[x][E]=1,adj[i].push_back(x),adj[x].push_back(i),adj[x].push_back(E),adj[E].push_back(x);
		c[S][i]=2;
		adj[S].push_back(i);
		adj[i].push_back(S);
	}
	while(1){
		std::vector<int> p(E+1,-1);
		std::queue<int> q;
		q.push(S);
		while(!q.empty() && p[E]==-1){
			int cur=q.front();q.pop();
			for(int next:adj[cur]) if(c[cur][next] && p[next]==-1) q.push(next),p[next]=cur;
		}
	if(p[E]==-1) break;
	for(int i=E;i!=S;i=p[i]) c[p[i]][i]--,c[i][p[i]]++;
	total++;
	}
	printf("%d",total);
}