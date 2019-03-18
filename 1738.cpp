#include <bits/stdc++.h>
using namespace std;
vector< pair<int, int> > adj[101];
int n,m,from, to, c,S=1,dist[101],par[101], arr[101],q;
int main(){
    scanf("%d %d",&n,&m);
    while(m--) scanf("%d %d %d",&from,&to, &c), adj[from].push_back({to, -c});
    for(int i =1; i <=n ; i++) dist[i] =1e9;
    dist[1] = 0;
    int E=n;
    std::queue<int> Q;
    bool visit[101]={};

    for(int i =0; i <n ; i++){
        for(int j=1; j <=n; j++){
            for(auto next: adj[j]){
                if(dist[j] != 1e9 && dist[next.first] > dist[j]+next.second){
                    if( i== n-1) Q.push(j),visit[j] = true;
                    dist[next.first] = dist[j]+ next.second;
                    par[next.first] = j;
                }
            }
        }
    }

    while(!Q.empty()){
        int cur = Q.front(); Q.pop();
        for(auto next: adj[cur]) if(!visit[next.first]) 
            visit[next.first]=true, Q.push(next.first);
    }
    if(visit[E] || dist[E]==1e9){
        puts("-1");
        return 0;
    }
    printf("%d ",1);
    for(int i =E; i!=S; i=par[i]) arr[q++]=i;
    for(int i=q-1; i>=0;i--) printf("%d ",arr[i]);
}