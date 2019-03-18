#include <bits/stdc++.h>
int d[100001],n,s,e,ret=1e9,sum,m;
int main(){
	scanf("%d %d",&n,&m);
	for(int i =0; i <n ; i++) scanf("%d",d+i);
	while(1){
		if(sum >= m) sum-=d[s++];
		else if(e==n) {
			ret == 1e9? puts("0"):printf("%d",ret);
			return 0;
		}
		else sum+=d[e++];
		if(sum>=m) ret= std::min(ret, e-s);
	}
}