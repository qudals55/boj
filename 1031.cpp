#include <bits/stdc++.h>
#define MAX 105
int f[MAX][MAX], c[MAX][MAX],S = MAX-2, E = MAX-1, n,m,k,sum_n,sum_m;
std::vector<int> adj[MAX];

void makeEdge(int from, int to, int cc){
    adj[from].push_back(to);
    adj[to].push_back(from);
    c[from][to] = cc;
}

int max_flow(){
    int ret =0;
    while(1){
        int prev[MAX];
        std::fill(prev, prev+MAX,-1);
        std::queue<int> Q;
        Q.push(S);
        while(!Q.empty() && prev[E]==-1){
            int cur =Q.front(); Q.pop();
            for(int next: adj[cur]) if(c[cur][next] - f[cur][next]>0 && prev[next]==-1)
                Q.push(next), prev[next]= cur;
        }

        if(prev[E]==-1) break;
        for(int i =E; i!=S;i=prev[i]) f[prev[i]][i]++, f[i][prev[i]]--;
        ret++;
    }
    return ret;
}

bool solve(int x, int y){
    f[x][y]--; f[y][x]++;
    f[S][x]--; f[x][S]++;
    f[y][E]--; f[E][y]++;
    std::queue<int> Q;
    int prev[MAX];
    Q.push(S);
    std::fill(prev, prev+MAX, -1);

    while(!Q.empty()){
        int cur =Q.front(); Q.pop();
        for(int next: adj[cur]){
            if(cur<=x && next <=y) continue;
             if(c[cur][next] - f[cur][next]>0 && prev[next]==-1)
                Q.push(next), prev[next]= cur;
        }
    }
    if(prev[E]==-1) return false;
    for(int i =E; i!=S;i=prev[i]) f[prev[i]][i]++, f[i][prev[i]]--;
    return true;
}
int main(){
    scanf("%d %d",&n,&m);
    for(int i =1; i <=n ;i++){
        scanf("%d",&k);
        sum_n+=k;
        makeEdge(S,i,k);
    }
    for(int i =n+1;i<=n+m;i++){
        scanf("%d",&k);
        sum_m+=k;
        makeEdge(i,E,k);
    }
    if(sum_n!=sum_m){
        puts("-1");
        return 0;
    }
    for(int i =1; i <=n ;i++)
        for(int j =n+1;j<=n+m;j++) makeEdge(i,j,1);
    if(sum_n!=max_flow()){
        puts("-1");
        return 0;
    }

    for(int i =1; i <=n ;i++)
        for(int j =n+1 ;j<=n+m;j++)
            if(f[i][j] && !solve(i,j))
                f[i][j] =1, f[j][i] =0, f[S][i]++, f[j][E]++, f[i][S]--, f[E][j]--;
    
    for(int i =1; i <=n ; i++){
        for(int j =n+1 ; j<=n+m;j++)
            printf("%d",f[i][j]);
        puts("");
    }
}