#include <bits/stdc++.h>
#define MAX 51*51
int d[51][51], L,R,N, ret,par[MAX],level[MAX],sum[MAX],dx[4]={1,-1,0,0}, dy[4]={0,0,1,-1};

int find(int x){
	return x==par[x] ? x: par[x]=find(par[x]);
}
void merge(int x, int y){
	x=find(x);
	y=find(y);
	if(x==y) return;
	if(level[x] < level[y]) std::swap(x,y);
	level[x]+=level[y];
	par[y] =x;
}

bool f(){
	bool ok = false;
	for(int i =0; i <N*N; i++) par[i] = i, sum[i] = 0, level[i] = 1;
	for(int i =0; i <N; i++){
		for(int j =0;j <N; j++){
			int cur = i*N +j;
			for(int k =0; k <4; k++){
				int ni = dx[k]+i, nj= dy[k]+j;
				if(ni < 0 || nj <0 || ni>=N || nj>=N) continue;
				int next = ni*N+nj;
				int dist = abs(d[i][j] - d[ni][nj]);
				if(dist>=L && dist<=R) merge(cur, next), ok=true;
			}
		}
	}

	for(int i =0; i <N; i++) for(int j =0; j <N ;j++) {
		int cur = i*N+j;
		sum[find(cur)] += d[i][j];
	}
	for(int i =0;i <N ;i++) for(int j =0; j <N ;j++){
		int cur = find(i*N+j);
		d[i][j] = sum[cur]/level[cur];
	}
	return ok;
}

int main(){
	scanf("%d %d %d",&N,&L,&R);
	for(int i = 0; i <N; i++) for(int j = 0; j <N ;j++) scanf("%d",&d[i][j]);
	while(f()) ret++;
	printf("%d",ret);
}