#include <bits/stdc++.h>
using namespace std;
int n,t,m,k,S,E,a,b,f1;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&m);
        int c[301][301]={},f[301][301]={};
        vector<int> adj[301];
        vector<pair<int, int> > chk;
        k=0;
        while(m--) scanf("%d %d %d",&a,&b,&f1), c[a][b]+=f1,adj[a].push_back(b),adj[b].push_back(a),chk.push_back({a,b});
        S=1; E=n;
        while(1){
            queue<int> q;
            q.push(S);
            vector<int> prev(n+1,-1);
            while(!q.empty() && prev[E]==-1){
                int cur =q.front(); q.pop();
                for(int next: adj[cur]) if(prev[next]==-1 && c[cur][next]-f[cur][next]>0) q.push(next),prev[next]=cur;
            }
        if(prev[E]==-1) break;
        int flow=1e9;
        for(int i=E; i!=S;i=prev[i]) flow=std::min(flow,c[prev[i]][i]-f[prev[i]][i]);
        for(int i =E;i!=S;i=prev[i]) f[prev[i]][i]+=flow,f[i][prev[i]]-=flow;    
        }
    for(int i =0; i<chk.size();i++){
        S=chk[i].first; E=chk[i].second;
        queue<int> q;
        q.push(S);
        vector<int> prev(n+1,-1);
        while(!q.empty() && prev[E]==-1){
            int cur =q.front(); q.pop();
            for(int next: adj[cur])  if(prev[next]==-1 && c[cur][next]-f[cur][next]>0) q.push(next),prev[next]=cur;
        }
    if(prev[E]==-1) k++;
    }
    printf("%d\n",k);
    }
}