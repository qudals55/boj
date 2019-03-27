#include <bits/stdc++.h>
int N,M,ret,cnt,arr[101][101];
bool visit[101][101];
int dfs(int x, int y){
    int t=0;
    if(x<0 || y<0|| x>=N || y>=M || visit[x][y]) return 0;
    visit[x][y]=true;
    if(arr[x][y]) {
        arr[x][y]=0;
        return 1;
    }
    t+=dfs(x+1,y);t+=dfs(x,y-1);t+=dfs(x,y+1);t+=dfs(x-1,y);
    return t;
}
int main(){
    scanf("%d %d",&N,&M);
    for(int i =0; i <N; i++) for(int j =0; j <M ;j++) scanf("%d",&arr[i][j]);
    while(1){
        memset(visit,false,sizeof(visit));
        int k=dfs(0,0);
        if(k==0) break;
        ret=k;
        cnt++;
    }
    printf("%d\n%d",cnt,ret);
}