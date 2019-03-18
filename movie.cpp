#include <bits/stdc++.h>
#define MAX 200002
int tree[MAX],v[MAX],n,m,k,t,p;
void update(int i,int val){
	while(i<=n+m) tree[i]+=val,i+=i&-i;
}
int query(int i){
	int ans=0;
	while(i>0) ans+=tree[i],i-=i&-i;
	return ans;
}
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d %d",&n,&m);
		for(int i=1;i<=n+m;i++) v[i]=tree[i]=0;
			for(int i =1;i<=n;i++) v[i]=i+m, update(v[i],1);
			p=m;
			while(p--){
				scanf("%d",&k);
				printf("%d ",query(v[k]-1));
				update(v[k],-1);
				v[k]=p+1;
				update(v[k],1);
			}
			printf("\n");
		}
	}