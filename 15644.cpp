#include <bits/stdc++.h>
struct Ball{
    int nrx, nry, nbx,nby,cnt;
};
struct Ball_2{
    int crx, cry, cbx,cby;
    char d;
};
Ball_2 p[11][11][11][11];
char arr[11][11],dd[4]={'D', 'R', 'U', 'L'};
int n, m, dx[4]={1,0,-1,0}, dy[4]={0,1,0,-1},rx,ry,bx,by;
bool visit[11][11][11][11];

int main(){
    scanf("%d %d",&n,&m);
    for(int i =0; i <n ;i++){
        scanf("%s",arr[i]);
        for(int j =0; j <m; j++) {
            if(arr[i][j]=='R') rx =i, ry = j;
            if(arr[i][j]=='B') bx =i, by = j;
        }
    }

    visit[rx][ry][bx][by] = true;
    std::queue<Ball> Q;
    Q.push({rx,ry,bx,by,0});
    while(!Q.empty()){
        auto cur = Q.front(); Q.pop();
        if(cur.cnt > 10) break;
        if(arr[cur.nrx][cur.nry]=='O'){
            printf("%d\n",cur.cnt);
            char pos[10]={};
            int r=0;
            Ball_2 q = p[cur.nrx][cur.nry][cur.nbx][cur.nby];
            while(q.d){
                pos[r++]=q.d;
                int cx=q.crx, cy = q.cry, cxx =q.cbx, cyy= q.cby;
                q =p[cx][cy][cxx][cyy];
            }
            
            for(int i =r-1;i>=0;i--) printf("%c",pos[i]);
            return 0;
        }
        for(int i =0; i <4; i++){
            int nnrx = cur.nrx, nnry = cur.nry, nnbx = cur.nbx, nnby = cur.nby,flr=0, flb = 0,fl=0;
            while(arr[nnrx+dx[i]][nnry+dy[i]]!='#'){
                nnrx+=dx[i]; nnry+=dy[i];
                if(arr[nnrx][nnry] == 'O') break;
                if(nnrx==cur.nbx && nnry==cur.nby) flr =1;
            }

            while(arr[nnbx+dx[i]][nnby+dy[i]]!= '#'){
                nnbx+=dx[i]; nnby +=dy[i];
                 if(arr[nnbx][nnby] == 'O'){
                    fl = 1;
                    break;
                }
                if(nnbx==cur.nrx && nnby ==cur.nry) flb = 1;
            }

            if(nnbx==nnrx && nnby == nnry){
                if(flr) nnrx -=dx[i], nnry -= dy[i];
                if(flb) nnbx -=dx[i], nnby -= dy[i];
            }
            if(!fl){
                if(!visit[nnrx][nnry][nnbx][nnby]){
                    Q.push({nnrx,nnry,nnbx,nnby,cur.cnt+1}), visit[nnrx][nnry][nnbx][nnby] = true;
                    p[nnrx][nnry][nnbx][nnby] = {cur.nrx, cur.nry, cur.nbx, cur.nby, dd[i]};
                }
            }
        }
    }
    puts("-1");
}