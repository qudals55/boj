#include <cstdio>
#include <vector>
#define ll long long
#define MAX 1000001
std::vector<ll> tree(MAX),v(MAX);
ll n,m;
int a,b,c,d;
void update(int pos,int val){
	while(pos<n+1) tree[pos]+=val, pos+=pos&-pos;
}
ll sum(int pos){
	ll ans =0;
	while(pos>0) ans+=tree[pos], pos-=pos&-pos;
	return ans;
}
int main(){
	scanf("%lld%lld",&n,&m);
	while(m--){
		scanf("%d %d %d",&a,&b,&c);
		if(a) d=c-v[b],v[b]=c,update(b,d);
		else {
			if(b>c) a=b,b=c,c=a;
			printf("%lld\n",sum(c)-sum(b-1));
		}
	}
}