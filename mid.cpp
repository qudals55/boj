#include <bits/stdc++.h>
using namespace std;
#define MAX 66000
int n,k,h=ceil(log2(MAX)),s=(1<<(h+1)),x;
long long ans;
int update(vector<int> &tree,int node, int s, int e, int pos,int val){
	if(pos<s || pos>e) return tree[node];
	if(s==e) return tree[node]+=val;
	int mid=(s+e)>>1;
	return tree[node]=update(tree,node*2,s,mid,pos,val)+update(tree,node*2+1,mid+1,e,pos,val);
}
long long query(vector<int> &tree,int node, int s, int e, int pivot){
	if(s==e) return s;
	int mid=(s+e)>>1;
	if(pivot<=tree[node*2]) return query(tree,node*2,s,mid,pivot);
	else return query(tree,node*2+1,mid+1,e,pivot-tree[node*2]);
}
int main(){
	scanf("%d%d",&n,&k);
	vector<int> v(n+1),tree(s);
	x=(k+1)/2;
	for(int i =1; i<= n;i++){
		scanf("%d",&v[i]);update(tree,1,0,MAX,v[i],1);
		if(i>k)update(tree,1,0,MAX,v[i-k],-1);
		if(i>=k)ans+=query(tree,1,0,MAX,x); 
	}
	printf("%lld",ans);
}