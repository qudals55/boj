#include <bits/stdc++.h>
int player[4][21],n,k,rule[10][10],win[4],idx[4];
bool chk[10];
void dfs(int from, int to){
	if(win[1]>=k) {
		puts("1");
		exit(0);
	}
	if(win[2]>=k || win[3]>=k ) return;

	if(from > to) std::swap(from, to);

	if(from==1){
	for(int i =1; i <=n ;i++){
		if(!chk[i]){
			int w = rule[i][player[to][idx[to]]];
			if(w== 2)
				chk[i] = true, win[from]++,idx[to]++,dfs(from, 6-from-to),chk[i]=false, win[from]--,idx[to]--;
			else
				chk[i] = true,win[to]++, idx[to]++,dfs(6-from-to, to), chk[i] =false, win[to]--,idx[to]--;
		}
	}
	}
	else{
		int w = rule[player[from][idx[from]]][player[to][idx[to]]];
		if(w==2) win[from]++, idx[from]++, idx[to]++, dfs(from, 6-from-to), win[from]--,idx[from]--, idx[to]--;
		else win[to]++,idx[to]++, idx[from]++, dfs(6-from-to, to), win[to]--,idx[from]--, idx[to]--;
	}

}
int main(){
	scanf("%d %d",&n,&k);
	for(int i =1; i <=n ;i++)
		for(int j =1; j<=n ;j++) scanf("%d",&rule[i][j]);
	for(int i =2; i<=3;i++) for(int j =1; j <=20; j++) scanf("%d",&player[i][j]);

	idx[2]=idx[3]=1;
	dfs(1,2);
	puts("0");
}