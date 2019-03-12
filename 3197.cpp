#include <bits/stdc++.h>
#define MAX 1501
int arr[MAX][MAX],N, M, dx[4]={1,-1,0,0}, dy[4]={0,0,1,-1},s1=-1,e1,s2,e2,cnt=1;
bool chk[MAX][MAX];
char ch;

bool safe(int x, int y){
	return (x>=0 && x<N && y>=0 && y<M);
}

bool bfs(int x, int y, int k){
	std::queue<int> Q;
	Q.push(x*M+y);
	chk[x][y]=true;

	while(!Q.empty()){
		int cur = Q.front();
		Q.pop();
	if(cur/M==s2 && cur%M== e2) return true;
	for(int i =0; i <4 ;i++){
		int nx = cur/M+dx[i], ny = cur%M +dy[i];
		if(!safe(nx,ny) || arr[nx][ny]> k || chk[nx][ny])continue;
		chk[nx][ny] =true;
		Q.push(nx*M+ny);
	}
}
	return false;
}

int main(){
	std::queue<int> Q;
	scanf("%d %d",&N,&M);
	for(int i =0; i <N ;i++){
		getchar();
		for(int j =0; j <M;j++){
			ch= getchar();
			if(ch=='X') chk[i][j] =true;
			else{ 
				if(ch=='L'){
				if(s1==-1) s1=i, e1=j;
				else s2=i,e2=j;
			}
			Q.push(i*M+j);
		}
		}
	}

	while(!Q.empty()){
		int sz= Q.size();
		while(sz--){
			int cur =Q.front();
			Q.pop();
			for(int i =0;  i<4 ; i++){
				int nx = cur/M +dx[i], ny = cur%M +dy[i];
				if(safe(nx, ny) && chk[nx][ny]) chk[nx][ny] =false, arr[nx][ny] = cnt,Q.push(nx*M+ny);
			}
		}
		cnt++;
	}

	int lo = 1, hi =cnt;
	while(lo <hi){
		memset(chk,false,sizeof(chk));
		int mid = (lo+hi)>>1;
		if(!bfs(s1, e1,mid)) lo =mid+1;
		else hi = mid;
	}
	printf("%d", hi);
}