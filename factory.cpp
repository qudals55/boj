#include <bits/stdc++.h>
#define MAX 1000001
#define ll long long
ll k;
int n,x,a[MAX/2],b[MAX],tree[MAX];
void update(int i, int val){
	while(i<=MAX-1) tree[i]+=val,i+=i&-i;
}
ll query(int i){
	ll ans=0;
	while(i>0) ans+=tree[i],i-=i&-i;
	return ans;
}
int main(){
	scanf("%d",&n);
	for(int i =1;i<=n;i++) scanf("%d",a+i);
	for(int i =1;i<=n;i++) scanf("%d",&x),b[x]=i;
	for(int i =1; i<=n;i++) k+=(query(MAX-1)-query(b[a[i]])),update(b[a[i]],1);
	printf("%lld",k);
}