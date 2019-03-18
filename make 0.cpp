#include <bits/stdc++.h>
using namespace std;
#define MAX 50
#define MAX_V 2550
#define INF 1e9	
int n,t,m,d[MAX][MAX],c[MAX_V][MAX_V],f[MAX_V][MAX_V],S=2501,E=2502,total,dx[4]={1,-1,0,0},dy[4]={0,0,-1,1};
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d %d",&n,&m);
		int total=0,sum=0;
		memset(c,0, sizeof(c));
		memset(f,0,sizeof(f));
		vector<int> adj[MAX_V];
		for(int i =0; i <n; i++) for(int j =0; j <m;j++) scanf("%d",&d[i][j]),sum+=d[i][j];
		for(int i =0; i <n ;i++){
			for(int j =0;j<m;j++){
				int cur= i*MAX+j;
				if((i+j)%2==0){
					c[S][cur] = d[i][j];
					adj[S].push_back(cur);
					adj[cur].push_back(S);
					for(int k =0; k <4 ;k++){
						int nx= i+dx[k], ny=j+dy[k];
						if(nx>=0 && ny>=0 && nx<n && ny<m){
							int to= MAX*nx + ny;
							adj[cur].push_back(to);
							adj[to].push_back(cur);
							c[cur][to]=1e9;
						}
					}
				}
				else adj[E].push_back(cur), adj[cur].push_back(E), c[cur][E] = d[i][j];
			}
		}
		while(1){
			queue<int> q;
			vector<int> prev(MAX_V,-1);
			q.push(S);
			while(!q.empty() && prev[E]==-1){
				int cur = q.front(); q.pop();
				for(int next:adj[cur]) if(c[cur][next]- f[cur][next]>0 && prev[next]==-1) q.push(next), prev[next]=cur;
			}
		if(prev[E]==-1) break;
		int flow = 1e9;
		for(int i=E; i!=S;i=prev[i]) flow=min(flow, c[prev[i]][i]-f[prev[i]][i]);
		for(int i=E; i!=S;i=prev[i]) f[prev[i]][i]+=flow,f[i][prev[i]]-=flow;
		total+=flow;
		}
		printf("%d\n",sum-total);
	}
}