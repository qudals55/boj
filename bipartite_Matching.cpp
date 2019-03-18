#include <cstdio>
#include <vector>
#include <algorithm>
int n,m,t,x,s,v[2002],b[2002];
std::vector<int> adj[2002];
int dfs(int i){
    v[i]=1;
    for(int there: adj[i]) if(!b[there]||!v[b[there]] && dfs(b[there])) {b[there]=i;return 1;}
    return 0;
}
int main(){
    scanf("%d %d",&n,&m);
    for(int i =1; i<=n;i++){
        scanf("%d",&t);
        while(t--) scanf("%d",&x), adj[i].push_back(x);
    }
    for(int i =1; i<=n+1000;i++) std::fill(v,v+2002,0),s+=dfs(i),s+=dfs(i);
    printf("%d",s);
}