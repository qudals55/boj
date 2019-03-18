#include <cstdio>
#define ll long long
#define MAX 100001
ll tree[MAX*4];
ll update(int node, int s, int e,int pos, ll val){
	if(pos<s || pos>e) return tree[node];
	if(s==e) return tree[node] = val;
	int mid=(s+e)>>1;
	return tree[node]=update(node*2,s,mid,pos,val)+update(node*2+1,mid+1,e,pos,val);
}
ll sum(int node,int s, int e, int l, int r){
	if(s>r || e<l) return 0;
	if(l<=s&&e<=r) return tree[node];
	int mid=(s+e)>>1;
	return sum(node*2,s,mid,l,r)+sum(node*2+1,mid+1,e,l,r);
}
int main(){
	ll n,m,a,b,c,d,t;
	scanf("%lld %lld",&n,&m);
	for(int i =0; i <n ;i++) scanf("%lld",&a),update(1,0,n-1,i,a);
	while(m--){
		scanf("%lld %lld %lld %lld",&a,&b,&c,&d);
		if(a>b) t=a,a=b,b=t;
		printf("%lld\n",sum(1,0,n-1,a-1,b-1)); update(1,0,n-1,c-1,d);
	}
}