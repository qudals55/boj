#include <bits/stdc++.h>
int c[405][405],n,t,total,S,E,k,x,y;
int main(){
	scanf("%d %d",&n,&t);
	y=std::max(n,t)+200;
	S=y+1;E=y+2;
	for(int i =1; i <=n;i++){
		scanf("%d",&k);
		while(k--) scanf("%d",&x),x+=200,c[i][x]=1,c[x][E]=1;
		c[S][i]=1;
	}
	while(1){
		std::vector<int> p(E+1,-1);
		std::queue<int> q;
		q.push(S);
		while(!q.empty() && p[E]==-1){
			int cur= q.front();q.pop();
			for(int i =0; i<=E;i++) if(p[i]==-1 && c[cur][i]) q.push(i),p[i]=cur;
		}
	if(p[E]==-1) break;
	for(int i=E; i!=S;i=p[i]) c[p[i]][i]--,c[i][p[i]]++;
	total++;
	}
	printf("%d",total);
}


#include <cstdio>
int d[21],n,m;
int df(int a,int b){
	if(a==n) return b==0?1:0;
	return df(a+1,b-d[a])+df(a+1,b); 
}
int main(){
	scanf("%d %d",&n,&m);
	for(int i =0; i <n ; i++) scanf("%d",d+i);
	printf("%d", m==0? df(0,m)-1:df(0,m));
}