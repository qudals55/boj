#include <bits/stdc++.h>
struct Rec{
    int x,y,t;
};
char arr[1001][1001];
bool visit[1001][1001];
int N,M, dx[4]={1,0,-1,0}, dy[4]={0,1,0,-1},ret;
int main(){
    scanf("%d %d",&N,&M);
    std::queue<Rec> Q;
    for(int i =0; i <N ;i++) {
        scanf("%s",arr[i]);
        for(int j =0; j <M ;j++) if(arr[i][j]=='F') Q.push({i,j,1}),visit[i][j] = true;
    }
    for(int i =0; i <N ;i++)
        for(int j =0;j<M;j++)
            if(arr[i][j]=='J') Q.push({i,j,0}), visit[i][j] =true;

    while(!Q.empty()){
        int sz = Q.size();
        while(sz--){
            auto cur = Q.front(); Q.pop();
            for(int i =0; i <4; i++){
                int nx = cur.x+dx[i], ny = cur.y+dy[i];
                if((nx<0 || ny< 0 || nx>=N || ny>=M) && !cur.t){
                    printf("%d",ret+1);
                    return 0;
                }
                if(nx<0 || ny< 0 || nx>=N || ny>=M || arr[nx][ny]=='#' || visit[nx][ny]) continue;
                Q.push({nx,ny,cur.t});
                visit[nx][ny]=true;
            }
        }
        ret++;
    }
    puts("IMPOSSIBLE");
}