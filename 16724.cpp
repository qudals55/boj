#include <bits/stdc++.h>
int N,M,dx[4]={1,0,-1,0}, dy[4]={0,1,0,-1},ret,visit[1001][1001],f,k;
char ch[1001][1001], d[4]={'D','R','U','L'};
void dfs(int x, int y, int r){
    int i;
    if(visit[x][y]){
        if(visit[x][y]==r) f=1;
        return; 
    }
    visit[x][y]=r;
    for(i =0; i <4; i++) if(ch[x][y]==d[i]) break;
    dfs(x+dx[i], y+dy[i],r);
}
int main(){
    scanf("%d %d",&N,&M);
    for(int i =0; i <N ;i++)
        scanf("%s",ch[i]);
    for(int i =0; i <N ;i++) {
        for(int j =0; j<M;j++){
            if(!visit[i][j]) dfs(i,j,++k);
            ret+=f;
            f=0;
        } 
    }
    printf("%d",ret);
}
