#include <bits/stdc++.h>
using namespace std;
int n,k,c[52][52],f[52][52],s,e,total;
char a,b;
vector<int> adj[52];
int Ctoi(char ch){
	if(ch<= 'Z') return ch-'A';
	return ch-'a'+26;
}
int main(){
	cin>>n;
	while(n--){
		cin>>a>>b>>k;
		a=Ctoi(a); b=Ctoi(b);
		c[a][b]+=k;
		adj[a].push_back(b); adj[b].push_back(a);
	}
	s=Ctoi('A'); e= Ctoi('Z');
	while(1){
		int prev[52];
		fill(prev, prev+52, -1);
		queue<int> q;
		q.push(s);
		while(!q.empty() && prev[e] ==-1){
			int cur = q.front(); q.pop();
			for(int next : adj[cur])if(c[cur][next]- f[cur][next] > 0 && prev[next]==-1) q.push(next), prev[next] = cur;
		}
	if(prev[e]==-1) break;
	int flow =1e9;
	for(int i =e ; i!=s; i=prev[i]) flow = min(c[prev[i]][i]-f[prev[i]][i],flow);
	for(int i =e; i!=s;i=prev[i]) f[prev[i]][i] += flow,f[i][prev[i]]-=flow;
	total +=flow;
	}
	cout<<total;
}