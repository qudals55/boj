#include <bits/stdc++.h>
int T,N,par[3001],x[3001],y[3001],r[3001];
int find(int x){
    return x==par[x] ? x:par[x]=find(par[x]);
}
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d",&N);
        int ret =0;
        for(int i =1; i <=N ;i++) par[i]=i,scanf("%d %d %d",x+i,y+i,r+i);
        for(int i =1; i <=N;i++){
            for(int j =i+1; j<=N;j++)
            if((x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]) <= (r[i]+r[j])*(r[i]+r[j]))
                if(find(i) != find(j)) par[find(j)] =par[find(i)],ret++;
        }
        printf("%d\n",N-ret);
    }
}