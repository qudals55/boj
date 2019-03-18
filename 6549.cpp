#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
typedef long long ll;
using namespace std;
int n,h,s;
void init(vector<ll> &v, vector<ll> &tree,int node, int s, int e){
	if(s==e) tree[node] =s;
	else{
	int m =(s+e)/2;
	init(v,tree,node*2,s,m);
	init(v,tree,node*2+1,m+1,e);
	tree[node] = v[tree[node*2]] <v[tree[node*2+1]]? tree[node*2]:tree[node*2+1];
}
}
int get_m(vector<ll> &v, vector<ll> &tree, int node, int s,int e, int l, int r){
	if(s>r || e<l) return -1;
	if(l<=s && e<=r) return tree[node];
	int m=(s+e)/2;
	int l2 = get_m(v,tree,node*2, s,m,l,r), r2=get_m(v,tree,node*2+1,m+1,e,l,r);
	if(l2==-1) return r2;
	if(r2==-1) return l2;
	return v[l2]<v[r2]?l2:r2;
}
ll f(vector<ll> &v, vector<ll> &tree, int l, int r){
	int index = get_m(v,tree,1,0,n-1,l,r);
	ll ans = (ll)(r-l+1)*v[index];
	if(l<=index-1) ans=max(ans,f(v,tree,l,index-1));
	if(r>=index+1) ans=max(ans,f(v,tree,index+1,r));
	return ans;
}
int main(){
	while(scanf("%d",&n),n!=0){
		vector<ll> v(n);
		for(int i =0; i <n; i++) scanf("%lld",&v[i]);
		h=ceil(log2(n)); s=(1<<(h+1));
		vector<ll> tree(s);
		init(v,tree,1,0,n-1);
		printf("%lld\n",f(v,tree,0,n-1));
	}
}