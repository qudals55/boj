#include <bits/stdc++.h>
char arr[11][11];
int n,m,ret=11,dx[4]={1,0,-1,0}, dy[4]={0,1,0,-1};
void dfs(int p, int rx, int ry, int bx,int by){
    if(p>10) return;

    for(int i =0; i <4; i++){
        int nrx = rx, nry = ry, nbx= bx, nby= by,rok=0,bok=0,flr=0,flb=0;
        while(arr[nrx+dx[i]][nry+dy[i]]!='#'){
            nrx+=dx[i]; nry+=dy[i];
            if(arr[nrx][nry]=='O') {
                rok = 1;
                break;
            }
            if(nrx==bx && nry==by) flr=1;
        }
         while(arr[nbx+dx[i]][nby+dy[i]]!='#'){
            nbx+=dx[i]; nby+=dy[i];
            if(arr[nbx][nby]=='O') {
                bok = 1;
                break;
            }
            if(nbx==rx && nby==ry) flb=1;
        }
         if(nrx==nbx && nry==nby){
            if(flr) nrx-=dx[i], nry-=dy[i];
            if(flb) nbx-=dx[i], nby-=dy[i];
        }
        if(bok) continue;
        if(rok) {
            ret=std::min(ret,p);
            return;
        }
        dfs(p+1,nrx,nry,nbx,nby);
    }
}
int main(){
    scanf("%d %d",&n,&m);
    int rx,ry,bx,by;
    for(int i =0; i <n ;i++){
        scanf("%s",arr[i]);
        for(int j=0; j <m ; j++){
            if(arr[i][j]=='R') rx=i,ry=j;
            if(arr[i][j]=='B') bx=i,by=j;
        }
    }
    dfs(1,rx,ry,bx,by);
    ret==11?puts("-1"):printf("%d",ret);
}
