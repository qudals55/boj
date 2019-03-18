#include <bits/stdc++.h>
struct Rec{
    int z,c,r;
};
int arr[101][101][101], n,m,h,dc[6]={1,-1,0,0,0}, dr[6]={0,0,0,0,1,-1}, dh[6]={0,0,1,-1,0,0}, ret,dist;
std::queue<Rec> Q;
bool visit[101][101][101];
int main(){
    scanf("%d %d %d",&m,&n,&h);
    for(int i =0; i <h ;i++) {
        for(int j =0; j <n; j++) {
            for(int k=0;k<m;k++) {
                scanf("%d",&arr[i][j][k]);
                if(!arr[i][j][k]) ret++;
                if(arr[i][j][k]==1) Q.push({i,j,k}), visit[i][j][k]= true;
            }
        }
    }
    if(ret==0){
        puts("0");
        return 0;
    }
    while(!Q.empty()){
        int sz = Q.size();
        while(sz--){
            auto cur = Q.front();
            Q.pop();
            for(int i =0; i <6; i++){
                int nh = cur.z+dh[i], nc = cur.c+dc[i], nr =cur.r+dr[i];
                if(nc<0 || nr<0 || nh<0 || nc>=n || nr>=m || nh>=h || visit[nh][nc][nr] || arr[nh][nc][nr]==-1) continue;
                Q.push({nh,nc,nr}); visit[nh][nc][nr]=true; ret--;
            }
        }
        dist++;
    }
    ret==0 ? printf("%d",dist-1):puts("-1");
}