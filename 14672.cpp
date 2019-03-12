#include <bits/stdc++.h>
#define MAX 10001
std::vector<int> prime, adj[1001];
std::map<int, int> ma;
int n,m,pos,k,b[MAX],ret;
bool chk[MAX],c[1001];

int dfs(int i){
    c[i] =true;
    for(int next: adj[i]) if(!b[next] || !c[b[next]] && dfs(b[next])){
        b[next] = i;
        return 1;
    }
    return 0;
}
int main(){
    for(int i =2; i <MAX;i++){
        if(!chk[i]){
            prime.push_back(i);
            for(int j = i+i; j<MAX;j+=i)
                chk[j]=true;
        }
    }
    scanf("%d %d",&n,&m);
    for(int i =1; i <=m ;i++){
        scanf("%d",&k);
        for(int p: prime){
            if(k==1) break;
            if(k%p==0){
                adj[i].push_back(p);
                while(k%p==0) k/=p;
            }
        }
        if(k>1){
            adj[i].push_back(k);
        } 
    }
    for(int i =1; i <=m ;i++) std::fill(c,c+m+1,false), ret+=dfs(i);
    printf("%d",ret);
}