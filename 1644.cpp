#include <bits/stdc++.h>
#define MAX 4000001
int d[MAX],n,s,e,ret,sum,p[MAX],q;
int main(){
	for(int i =2; i <MAX;i++){
		if(d[i]==0){
			p[q++] = i;
			for(int j =i+i; j<MAX;j+=i)
				d[j]=1;
		}
	}
	scanf("%d",&n);
	while(1){
		if(sum >= n) sum-=p[s++];
		else if(e == q) break;
		else sum+=p[e++];
		if(sum==n) ret++;
	}
	printf("%d",ret);
}