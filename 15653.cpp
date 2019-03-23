#include <bits/stdc++.h>
struct Ball{
    int x, y,cnt, xx, yy;
};
char arr[11][11];
int n,m,dx[4]={1,0,-1,0}, dy[4]={0,1,0,-1}, rx,ry,bx,by;
bool visit[11][11][11][11];

int main(){
    std::queue<Ball> Q;
    scanf("%d %d",&n,&m);
    for(int i =0; i <n ;i++){
        scanf("%s",arr[i]);
        for(int j =0; j <m ;j++){
            if(arr[i][j] =='R') rx=i,ry=j;
            if(arr[i][j]== 'B') bx=i,by=j;
        }
    }
    Q.push({rx,ry,0,bx,by});
    visit[rx][ry][bx][by] = true;

    while(!Q.empty()){
        auto cur = Q.front(); Q.pop();
    
        if(arr[cur.x][cur.y]=='O') {
            printf("%d",cur.cnt);
            return 0;
        }
        for(int i =0; i <4; i++){
            int nrx = cur.x, nry =cur.y,nbx = cur.xx, nby = cur.yy,flr=0,flb=0,fl=1;

            while(arr[nrx+dx[i]][nry+dy[i]]!='#') {
                nrx+=dx[i], nry +=dy[i];
                if(arr[nrx][nry]=='O') break;
                if(nrx==cur.xx && nry==cur.yy) flr=1;
            }
            while(arr[nbx+dx[i]][nby+dy[i]]!='#') {
                nbx+=dx[i], nby+=dy[i];
                if(arr[nbx][nby]=='O') {
                    fl=0;
                    break;
                }
                if(nbx==cur.x && nby==cur.y) flb=1;
            }
            if(nbx==nrx && nby==nry){
                if(flr) nrx-=dx[i], nry-=dy[i];
                if(flb) nbx-=dx[i], nby-=dy[i];
            }
            if(fl && !visit[nrx][nry][nbx][nby])Q.push({nrx,nry,cur.cnt+1,nbx,nby}), visit[nrx][nry][nbx][nby]=true;
        }
    }
    puts("-1");
}