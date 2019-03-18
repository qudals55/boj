#include <bits/stdc++.h>
struct Rec{
    int c,r;
};
int arr[10][10], tmp[10][10], dc[4]={1,0,-1,0}, dr[4]={0,1,0,-1},n,m,ret=1e9,idx[10];
std::vector<Rec> adj;

bool safe(int x, int y){
    return (x>=0 && x<n && y>=0 && y<m && tmp[x][y]!=6);
}
void solve(int x, int y, int k, int d){
    if(!safe(x,y)) return;
    if(!tmp[x][y]) tmp[x][y] = 7;
    solve(x+k,y+d,k,d);
}
int go(){
    int sum=0,pos=0;
    for(auto cur:adj){
        int t = tmp[cur.c][cur.r];
        if(t==1) solve(cur.c, cur.r, dc[idx[pos]],dr[idx[pos]]);
        if(t==2) {
            if(idx[pos]%2) solve(cur.c, cur.r, dc[0],dr[0]),solve(cur.c,cur.r,dc[2],dr[2]);
            else solve(cur.c,cur.r,dc[1],dr[1]), solve(cur.c,cur.r,dc[3],dr[3]);
        }
        if(t==3) solve(cur.c,cur.r, dc[idx[pos]],dr[idx[pos]]),solve(cur.c,cur.r,dc[(idx[pos]+1)%4],dr[(idx[pos]+1)%4]);
        if(t==4) for(int i =0; i <4; i++) if(i!= idx[pos]) solve(cur.c,cur.r,dc[i],dr[i]);
        pos++;
    }
    for(int i =0; i <n;i++) for(int j =0; j <m ; j++) sum+=(tmp[i][j]==0);
    return sum;
}
void dfs(int p){
    if(p==adj.size()){
        memcpy(tmp, arr,sizeof(arr));
        int cnt = go();
        ret = std::min(ret,cnt);
        return;
    }
    for(int i =0; i <4; i++) idx[p] = i, dfs(p+1);
}
int main(){
    scanf("%d %d",&n,&m);
    for(int i =0; i <n ;i++){
        for(int j=0;j<m ;j++) {
            scanf("%d",&arr[i][j]);
            tmp[i][j] =arr[i][j];
            if(arr[i][j] && arr[i][j]<5) adj.push_back({i,j});
        }
    }
    for(int i =0; i<n ;i++)
        for(int j =0;j <m;j++)
            if(tmp[i][j]==5) solve(i,j,1,0),solve(i,j,0,1),solve(i,j,-1,0),solve(i,j,0,-1);
    memcpy(arr,tmp,sizeof(arr));
    dfs(0);
    printf("%d",ret);
}
