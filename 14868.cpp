#include <bits/stdc++.h>
int N,K, arr[2001][2001], par[2001*2001],dx[4]={1,0,-1,0}, dy[4]={0,1,0,-1},c,r,ret;
int get(int x, int y){
    return x*N+y;
}
bool safe(int x, int y){
    return (x>=0 && y>=0 && x<N && y<N);
}
int find(int x){
    return x==par[x]? x: par[x]=find(par[x]);
}
int merge(int x, int y){
    x=find(x);
    y=find(y);
    if(x==y) return 0;
    par[y] =x;
    return 1;
}

int main(){
    scanf("%d %d",&N,&K);
    for(int i =0; i <N*N;i++) par[i]=i;
    std::queue<int> Q;

    int chk = K;
    for(int i =1; i<=K;i++){
        scanf("%d %d",&r,&c);
        c--;r--;
        arr[c][r] =i;
        Q.push(get(c,r));
        for(int k =0; k <4 ; k++){
            int nx = c+dx[k], ny = r+dy[k];
            if(!safe(nx,ny) || !arr[nx][ny]) continue;
            chk-= merge(arr[c][r], arr[nx][ny]);
        }
    }
    while(chk>1){
        int sz = Q.size();
        while(sz--){
            int x = Q.front()/N, y = Q.front()%N; Q.pop();
            for(int i =0; i <4; i++){
                int nx = x+dx[i], ny = y+dy[i];
                if(!safe(nx, ny)) continue;
                if(arr[nx][ny]) chk-= merge(arr[x][y], arr[nx][ny]);
                else{
                    arr[nx][ny] = arr[x][y];
                    Q.push(get(nx, ny));
                    for(int k =0; k <4 ;k++){
                        int nnx = nx+dx[k], nny = ny+dy[k];
                        if(!safe(nnx, nny)) continue;
                        if(arr[nnx][nny]) chk-=merge(arr[nx][ny], arr[nnx][nny]);
                    }
                }
            }
        }
        ret++;
}
printf("%d",ret);
}