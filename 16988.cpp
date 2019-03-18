#include <bits/stdc++.h>
int arr[21][21],n,m,ret, pos[2],flag;
bool visit[410],check[21][21];
int get(int x, int y){
    return (x*m +y);
}
int dfs1(int x, int y){
   int cnt =1;
   if(x<0 || x>=n || y>=m || y<0 || check[x][y] || arr[x][y]==1) return 0;
   if(arr[x][y]==0) {
       flag =0;
       return 0;
   }
   check[x][y]=true;
   cnt+=dfs1(x+1,y);cnt+=dfs1(x-1,y); cnt+=dfs1(x,y+1); cnt+=dfs1(x,y-1); 
   return cnt;
}
void dfs(int p, int idx){
    if(idx==2){
        int cnt= 0;
        memset(check,false,sizeof(check));
        arr[pos[0]/m][pos[0]%m] = arr[pos[1]/m][pos[1]%m] =1;
        for(int i =0; i <n; i++)
            for(int j =0; j <m ;j++) if(!check[i][j] && arr[i][j]==2) flag=1, cnt+=dfs1(i,j)*flag;

        ret= std::max(ret, cnt);
        arr[pos[0]/m][pos[0]%m] = arr[pos[1]/m][pos[1]%m] =0;
        return;
    }
    for(int i =p; i<n*m; i++) if(!visit[i]) visit[i] = true, pos[idx] = i, dfs(i+1,idx+1), visit[i]= false;
}
int main(){
    scanf("%d %d",&n,&m);
    for(int i =0; i <n; i++)
        for(int j =0; j <m; j++) 
            scanf("%d",&arr[i][j]), visit[(get(i,j))] = arr[i][j] ? true:false;
    dfs(0,0);
    printf("%d",ret);
}
