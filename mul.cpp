#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
#define mod 1000000007
int n,m,k,a,b,c,h,_s;
ll update(vector<ll> &tree, int node, int s, int e,int pos, ll val){
	if(!(s<=pos&&pos<=e)) return tree[node];
	if(s==e) return tree[node]=val;
	int mid=(s+e)/2;
	return tree[node]=(update(tree,node*2,s,mid,pos,val)*update(tree,node*2+1,mid+1,e,pos,val))%mod;
}
ll query(vector<ll> &tree, int node, int s, int e, int l, int r){
	if(s>r || e<l) return 1;
	if(l<=s && e<=r) return tree[node];
	int mid=(s+e)/2;
	return (query(tree,node*2,s,mid,l,r)*query(tree,node*2+1,mid+1,e,l,r))%mod;
}
int main(){
	scanf("%d %d %d",&n,&m,&k);
	k+=m;
	ll t;
	h=ceil(log2(n));
	_s=(1<<(h+1));
	vector<ll> tree(_s);
	for(int i =0; i <n ;i++) scanf("%lld",&t), update(tree, 1,0,n-1,i,t);
	while(k--){
		scanf("%d %d %d",&a,&b,&c);
		if(a==1) update(tree,1,0,n-1,b-1,c);
		else printf("%lld\n",query(tree,1,0,n-1,b-1,c-1));
	}	
}