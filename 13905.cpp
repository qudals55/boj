#include <bits/stdc++.h>
struct Edge{
    int u,v,d;
    bool operator < (const Edge &b) const{
        return d > b.d;
    }
};
int par[100001],n,m,x,y,z,s,e;
std::vector<Edge> adj;

int find(int p){
    return p ==par[p]? p: par[p] = find(par[p]);
}
int main(){
    scanf("%d %d %d %d",&n,&m,&s,&e);
    while(m--) scanf("%d %d %d",&x,&y,&z), adj.push_back({x,y,z});
    for(int i =1; i <=n;i++) par[i] =i;
    std::sort(adj.begin(), adj.end());
    for(int i=0 ; i<adj.size(); i++){
        int a = find(adj[i].u), b = find(adj[i].v);
        par[b] = a;
        if(par[find(s)]== par[find(e)]) {
            printf("%d",adj[i].d);
            return 0;
        }
    }
    puts("0");
}