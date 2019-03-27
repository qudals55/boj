#include <bits/stdc++.h>
int arr[21][21],x,y,k,t,dice[6],n,m,dx[4]={0,0,-1,1},dy[4]={1,-1,0,0},tmp[6];
int solve(int p){
	memcpy(tmp,dice,sizeof(dice));
	if(p==1){
		dice[0] = tmp[2];
		dice[2] = tmp[5];
		dice[5] = tmp[3];
		dice[3] = tmp[0];
	}
	else if(p==2){
		dice[0] = tmp[3];
		dice[2] = tmp[0];
		dice[3] = tmp[5];
		dice[5] = tmp[2];
	}
	else if(p==3){
		dice[0] = tmp[1];
		dice[1] = tmp[5];
		dice[4] = tmp[0];
		dice[5] = tmp[4];
	}
	else{
		dice[0] = tmp[4];
		dice[4] = tmp[5];
		dice[1] = tmp[0];
		dice[5] = tmp[1];
	}
	if(arr[x][y]) dice[5] =arr[x][y], arr[x][y]=0;
	else arr[x][y] = dice[5];
	return dice[0];
}
int main(){
	scanf("%d %d %d %d %d",&n,&m,&x,&y,&k);
	for(int i =0;i<n;i++) for(int j =0; j <m ;j++) scanf("%d",&arr[i][j]);
	while(k--){
		scanf("%d",&t);
		if(x+dx[t-1]<0 || y+dy[t-1]<0 || x+dx[t-1]>=n|| y+dy[t-1]>=m) continue;
		x+=dx[t-1],y+=dy[t-1];
		printf("%d\n",solve(t));
	}
}