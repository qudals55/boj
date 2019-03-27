#include <bits/stdc++.h>
int N,M,cnt,arr[101][101],visit[101][101];
int dfs(int x, int y){
    int t =0;
    if(x<0 || y<0 || x>=N || y>=M) return 0;
    if(arr[x][y]){
         visit[x][y]++;
        if(visit[x][y]>=2){
            printf("!");
            arr[x][y] = 0;
            return 1;
        }
        return 0;
    }
    else{
        if(visit[x][y]) return 0;
        visit[x][y]++;
    }
    t+=dfs(x+1,y);t+=dfs(x-1,y);t+=dfs(x,y+1);t+=dfs(x,y-1);
    return t;
}
int main(){
    scanf("%d %d",&N,&M);
    for(int i =0; i<N; i++)
        for(int j =0; j <M ;j++) scanf("%d",&arr[i][j]);
    while(1){
        memset(visit,0, sizeof(visit));
        int k =dfs(0,0);
        if(k==0) break;
        cnt++;
    }
    printf("%d",cnt);
}