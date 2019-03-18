#include <bits/stdc++.h>
#define MAX 100001
int d[MAX],tree[MAX*4],n,m,k,q[MAX];
int init(int node, int s, int e){
	if(s==e) return tree[node]=1;
	int mid=(s+e)>>1;
	return tree[node]=init(node*2,s,mid)+init(node*2+1,mid+1,e);
}
int query(int node, int s, int e,int p,int pivot){
	if(s==e) {q[p]=s+1;return tree[node]=0;}
	int mid=(s+e)>>1;
	if(pivot<tree[node*2]) return tree[node]= tree[node*2+1]+query(node*2,s,mid,p,pivot);
	return tree[node]=tree[node*2]+query(node*2+1,mid+1,e,p,pivot-tree[node*2]);
}
int main(){
	scanf("%d %d",&n,&m);
	init(1,0,n-1);
	for(int i =0;i<n;i++){
		k+=m-1;
		k%=(n-i);
		query(1,0,n-1,i,k);
	}
	printf("<");
	for(int i =0;i<n-1;i++) printf("%d, ",q[i]);
	printf("%d>",q[n-1]);
}