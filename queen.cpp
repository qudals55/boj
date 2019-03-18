#include <bits/stdc++.h>
using namespace std;
#define MAX 100000
#define ll long long
int n,s;
ll k;
void update(vector<ll> &tree,int node, int s, int e,int pos){
	if(pos<s || pos>e) return;
	tree[node]+=1;
	if(s!=e) {
	int mid=(s+e)>>1;
	update(tree,node*2,s,mid,pos);update(tree,node*2+1,mid+1,e,pos);
}
}
ll query(vector<ll> &tree, int node, int s, int e, int l, int r){
	if(r<s || l>e) return 0;
	if(l<=s && e<=r ) return tree[node];
	int mid=(s+e)>>1;
	return query(tree, node*2, s,mid,l,r)+query(tree,node*2+1,mid+1,e,l,r);
}
int main(){
	scanf("%d",&n);
	vector<ll> v(n),L(n),R(n),tree(n*4);
	for(int i =0; i<n ;i++) scanf("%lld",&v[i]), L[i]=query(tree,1,0,n-1,v[i],n-1),update(tree,1,0,n-1,v[i]-1);
	tree=vector<ll>(n*4);
	for(int i =n-1;i>=0;i--) R[i]=query(tree,1,0,n-1,0,v[i]-2),update(tree,1,0,n-1,v[i]-1);
	for(int i =0; i <n;i++) k+=L[i]*R[i];
	printf("%lld",k);
}