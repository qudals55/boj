#include <bits/stdc++.h>
#define MAX 100001
int tree[MAX*4],d[MAX],n,q[MAX];
int init(int node, int s, int e){
	if(s==e) return tree[node]=1;
	int mid=(s+e)>>1;
	return tree[node]=init(node*2,s,mid)+init(node*2+1,mid+1,e);
}
int query(int node, int s,int e, int val, int pivot){
	if(s==e){q[s]=val;return tree[node]=0;}
	int mid=(s+e)>>1;
	if(pivot<tree[node*2]) return tree[node]=tree[node*2+1]+query(node*2,s,mid,val,pivot);
	return tree[node]=tree[node*2]+query(node*2+1,mid+1,e,val,pivot-tree[node*2]); 
}
int main(){
	scanf("%d",&n);
	init(1,0,n-1);
	for(int i =0; i <n ; i++) scanf("%d",d+i);
	for(int i =n-1;i>=0;i--) query(1,0,n-1,i+1,d[i]);
	for(int i =n-1;i>=0;i--) printf("%d ",q[i]);
}