#include <bits/stdc++.h>
int N,ret,s[10],w[10];

void dfs(int pos, int cnt){
    if(pos==N){
        ret=std::max(ret, cnt);
        return;
    }
    if(s[pos]<=0 || cnt==N-1) dfs(pos+1,cnt);
    else{
    for(int i =0; i<N;i++){
        if(s[i]<=0 || i==pos) continue;
        s[pos] -= w[i]; s[i] -= w[pos];
        dfs(pos+1,cnt+(s[pos]<=0)+(s[i]<=0));
        s[pos] += w[i]; s[i] += w[pos];
        }
    }
}
int main(){
    scanf("%d",&N);
    for(int i =0; i <N ;i++) scanf("%d %d",&s[i],&w[i]);
    dfs(0,0);
    printf("%d",ret);
}