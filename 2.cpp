#include <bits/stdc++.h>
using namespace std;
typedef long long lld;
int n;
map<string, int> m;
int cnt;
int scnt;
vector<int> adj[2501];
vector<int> radj[2501];
int visited[2501];
int scc[2501];
lld memo[2501],ans;
stack<int> stk;
int dfs1(int cur)
{
    visited[cur]=1;
    for(int i=0;i<adj[cur].size();++i){
        int nxt=adj[cur][i];
        if(!visited[nxt]){
            dfs1(nxt);
        }
    }
    stk.push(cur);
}
 
int dfs2(int cur)
{
    scc[cur]=scnt;
    for(int i=0;i<radj[cur].size();++i){
        int nxt=radj[cur][i];
        if(!scc[nxt]){
            dfs2(nxt);
        }
    }
}
void solve(int cur){
    for(int next: radj[cur]) if(scc[cur] !=scc[next])ans++,solve(next);
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        string t;
        cin>>t;
        if(!m[t])m[t]=++cnt;
        int x;
        scanf("%d",&x);
        for(int j=0;j<x;++j){
            string s;
            cin>>s;
            if(!m[s])m[s]=++cnt;
            adj[m[s]].push_back(m[t]);
            radj[m[t]].push_back(m[s]);
        }
    }
    string x;
    cin>>x;
    if(!m[x])m[x]=++cnt;
    for(int i=1;i<=cnt;++i){
        if(!visited[i])dfs1(i);
    }
    while(!stk.empty()){
        if(!scc[stk.top()]){
            ++scnt;
            dfs2(stk.top());
        }
        stk.pop();
    }
    
    solve(m[x]);
    cout<<ans+1;
}
