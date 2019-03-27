#include <bits/stdc++.h>
int n,k,ret=1e9,dp[500001][2],t;
std::queue<int> Q;
int main(){
	scanf("%d %d",&n,&k);
	Q.push(n);
	memset(dp, -1,sizeof(dp));
	dp[n][0]=0;
	while(!Q.empty()){
		int sz =Q.size();
		while(sz--){
			int cur = Q.front(); Q.pop();
			for(int next: {cur-1, cur+1, cur*2}){
				if(next <0 || next>500000 ) continue;
				if(dp[next][!t]==-1 || dp[next][!t] > dp[cur][t]+1) dp[next][!t] = dp[cur][t]+1, Q.push(next);
			}
		}
		t^=1;
	}
	t=0;
	while(k<=500000){
		if(dp[k][t%2] <=t) ret=std::min(ret,t);
		t++;
		k+=t;
	}
	ret==1e9?puts("-1"):printf("%d",ret);
}