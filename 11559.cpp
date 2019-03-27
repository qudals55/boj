#include <bits/stdc++.h>
int n=12,m=6, dx[4]={1,0,-1,0}, dy[4]={0,1,0,-1},ret;
bool visit[13][7],fl=true;
char ch[13][7];
bool safe(int x, int y){
    return(x>=0 && y>=0 && x<n && y<m);
}
void go(int x, int y){
    int p =x;
    while(safe(p,y) && ch[p+1][y]=='.')
        p++;
    if(x!=p) std::swap(ch[x][y], ch[p][y]);
}
bool bfs(int x, int y){
    int cnt=1;
    std::queue<int> Q,v;
    memset(visit, false,sizeof(visit));
    Q.push(n*x+y);
    v.push(n*x+y);
    visit[x][y] =true;
    while(!Q.empty()){
        int cx = Q.front()/n, cy = Q.front()%n; Q.pop();
        for(int i =0; i<4 ; i++){
            int nx = cx+dx[i], ny = cy+dy[i];
            if(!safe(nx,ny) || visit[nx][ny] || ch[nx][ny] != ch[cx][cy]) continue;
            cnt++;
            visit[nx][ny] =true;
            v.push(nx*n+ny);
            Q.push(nx*n+ny);
        }
    }
    if(cnt>=4){
        while(!v.empty()){
            int cx = v.front()/n, cy = v.front()%n; v.pop();
            ch[cx][cy] = '.';
        }
        return true;
    }
    return false;
}
int main(){
    for(int i =0; i<n ;i++) scanf("%s",ch[i]);
    while(fl){
        fl =false;
        for(int i =0; i <n ;i++)
            for(int j = 0;j <m; j++) if(ch[i][j]!='.' && !visit[i][j] && bfs(i,j)) fl=true;   

        for(int i =n-1; i>=0 ;i--)
            for(int j =0; j<m;j++) if(ch[i][j]!='.') go(i,j);
    ret+=fl;
    }
    printf("%d",ret);
}