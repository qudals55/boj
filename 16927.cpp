#include <bits/stdc++.h>
int arr[301][301],n,m,k,dx[4]={0,1,0,-1}, dy[4]={1,0,-1,0}, l;

void solve(int s, int t){
        while(t--){
        int d= 0,t = arr[s][s],c=s,r=s;
        while(d<4){
            int nc = dx[d]+c, nr = dy[d]+r;
            if(nc<s || nc>=n-s || nr<s || nr>=m-s) d++;
            else arr[c][r] = arr[nc][nr], c=nc,r=nr;
        }
        arr[c+1][r]=t;
        }
}
int main(){
    scanf("%d %d %d",&n,&m,&k);
    for(int i =0; i <n ; i++) for(int j =0; j <m ;j++) scanf("%d",&arr[i][j]);
    l = std::min(n,m)/2;
    for(int p = 0; p<l; p++){
        int x = 2*((n-2*p)+(m-2*p))-4;
        solve(p,k%x);
    }
    for(int i =0; i <n ; i++){
        for(int j =0; j <m ;j++) printf("%d ",arr[i][j]);
        puts("");
    }
}