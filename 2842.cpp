#include <bits/stdc++.h>
int map[51][51], N, dx[8]={0,0,1,-1,1,-1,1,-1}, dy[8]={1,-1,0,0,1,1,-1,-1}, startx, starty, s,e, ans=1e9, sum;
std::vector<int> v;
bool visit[51][51],check[51][51];
char ch;

int dfs(int x, int y){
	if(x <0 || x>=N || y<0 || y>=N || visit[x][y] || !(map[x][y]>=v[s] && map[x][y] <=v[e]) ) return 0;
	visit[x][y]= true;
	int cnt = 0;
	if(check[x][y]) cnt++;

	for(int i =0; i <8; i++)
		cnt+= dfs(dx[i]+x, dy[i]+y);
	return cnt;
}
int main(){
	scanf("%d",&N);
	for(int i =0; i <N ;i++){
		getchar();
		for(int j =0;j  <N;j++){
			ch= getchar();
			if(ch=='K')  check[i][j] = true, sum++;
			if(ch=='P') startx =i, starty =j;
		}
	}

	for(int i =0; i <N ;i++) for(int j =0; j< N ;j++) scanf("%d",&map[i][j]),v.push_back(map[i][j]);

	std::sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());

	while(1){

		memset(visit, false , sizeof(visit));
		int ret= dfs(startx ,starty);
		if(ret==sum) ans = std::min(ans, v[e]-v[s++]);
		else if(e==v.size()){
			printf("%d",ans);
			return 0;
		}
		else e++;
	}
}