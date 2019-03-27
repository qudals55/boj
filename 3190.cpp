#include <bits/stdc++.h>
int arr[105][105]={1},N,dx[4]={0,1,0,-1}, dy[4]={1,0,-1,0},cnt,a,b,t,d,pos,nx,ny;
std::pair<int, char> p[105];
int main(){
	scanf("%d %d",&N,&t);
	while(t--) scanf("%d %d",&a,&b), arr[a-1][b-1] =2;
	scanf("%d",&t);
	for(int i =0; i <t; i++) scanf("%d %c",&p[i].first,&p[i].second);
	std::queue<int> Q;
	Q.push(0);
	while(1){
		nx+=dx[d],ny+=dy[d]; cnt++;
		Q.push(nx*N+ny);
		if(nx<0 || ny<0 || nx>=N || ny>=N ||arr[nx][ny]==1){
			printf("%d",cnt);
			return 0;
		}
		if(arr[nx][ny]!=2) arr[Q.front()/N][Q.front()%N]=0, Q.pop();
		arr[nx][ny] =1;
		if(cnt == p[pos].first){
			if(p[pos].second=='D') d=(d+1)%4;
			else d=(d+3)%4;
			pos++;
		}	
	}
}