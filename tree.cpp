#include <cstdio>
#define ll long long
#define mod 1000000007
#define MAX 200001
ll tree[MAX],n,k,cnt[MAX],v[MAX],ans=1;
void update(ll p,ll val,int f){
	if(f){
		while(p<=MAX) tree[p]+=val,p+=p&-p;
	}
	else {
		while(p<=MAX) cnt[p]+=val,p+=p&-p;
}
}
ll query(ll p, int f){
	ll q=0;
	if(f){
		while(p>0) q+=tree[p],p-=p&-p;
	}
	else{
		while(p>0) q+=cnt[p],p-=p&-p;
	}
	return q;
}
int main(){
	scanf("%lld",&n);
	for(int i =0;i<n;i++) {
		scanf("%lld",&k); k++;
		update(k,1,0); update(k,k,1);
		v[i]=query(k-1,0)*k-query(k-1,1)+query(MAX-1,1)-query(k,1)-((query(MAX-1,0)-query(k,0))*k);
		v[i]%=mod;
	}
	for(int i=1; i<n;i++)ans*=v[i],ans%=mod;
	printf("%lld",ans);
}