#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX 2550
map<string, int> m;
stack<int> S;
string s,k;
int finish[MAX],dfsn[MAX],scc[MAX],sn,cnt,mn,T,n;
ll ans=1,dp[MAX];
vector<int> adj[MAX],radj[MAX];
int dfs(int cur){
	dfsn[cur]=++cnt;
	S.push(cur);
	int ret = dfsn[cur];
	for(int next: adj[cur]){
		if(!dfsn[next]) ret = min(ret, dfs(next));
		else if(!finish[next]) ret = min(ret, dfsn[next]);
	}

	if(ret ==dfsn[cur]){
		sn++;
		while(1){
			int t= S.top();
			S.pop();
			finish[t]=true;
			scc[t] =sn;
			if(t==cur) break;
		}
	}
	return ret;
}

ll solve(int cur){
	ll &ret = dp[cur];
	if(ret) return ret;
	ret =1;
	for(int next: radj[cur]) {
		if(scc[cur] !=scc[next]) ret += solve(next);
	}
	return ret;
}
int main(){
	cin>>T;
	while(T--){
		cin>>k>>n;
		if(!m[k])m[k]=++mn;
		while(n--) {
			cin>>s;
			if(!m[s]) m[s]=++mn;
			adj[m[s]].push_back(m[k]);
			radj[m[k]].push_back(m[s]);
		}
	}
		for(int i =1; i <=mn;i++) if(!dfsn[i]) dfs(i);
		cin>>k;
		if(!m[k]) m[k]=++mn;
		cout<<solve(m[k]);
}