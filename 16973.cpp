#include <bits/stdc++.h>

int N,M, arr[1001][1001], dc[4]={1,-1,0,0}, dr[4]={0,0,1,-1},ret,H,W,sr,sc, fr,fc;

bool visit[1001*1001];
int get(int x,int y){
	return x*M+y;
}
bool safe(int x, int y){

	if(x<1 || x+H>N+1 || y<1 || y+W>M+1) return false;
	if(arr[x+H-1][y+W-1] - arr[x+H-2][y+W-1] - arr[x+H-1][y+W-2] + arr[x+H-2][y+W-2]) return false;
	return true;
}

int main(){
	scanf("%d %d",&N,&M);
	for(int i =1; i <=N;i++)
		for(int j =1; j <=M;j++)
			scanf("%d",&arr[i][j]), arr[i][j] += arr[i-1][j] + arr[i][j-1] -arr[i-1][j-1];
	scanf("%d %d %d %d %d %d",&H,&W,&sr,&sc,&fr,&fc);
	
	std::queue<int> Q;
	Q.push(get(sr, sc));
	visit[get(sr, sc)]=true;

	while(!Q.empty()){
		int sz= Q.size();
		while(sz--){
			int cur =Q.front();
			Q.pop();
			if(cur/M == fr && cur%M ==fc){
				printf("%d",ret);
				return 0;
			}
			for(int i =0; i <4; i++) {
				int nc = cur/M +dc[i], nr = cur%M +dr[i];
					if(safe(nc,nr) && !visit[get(nc,nr)]) Q.push(get(nc, nr)),visit[get(nc,nr)] = true;
				}
			}
		ret++;
	}
	puts("-1");
}